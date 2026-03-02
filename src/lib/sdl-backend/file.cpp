#include <lib/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#ifdef _WIN32
# include <windows.h>
# include <io.h>
#else
# include <unistd.h>
# include <dirent.h>
# include <fnmatch.h>
# define _open   open
# define _close  close
# define _dup    dup
# define _lseek  lseek
# define _read   read
# define _write  write
# define _unlink unlink
# define _chsize ftruncate
# define O_BINARY 0
#endif
#include <algorithm>
#include <SDL_log.h>


namespace win32
{

static std::string s_currentDirectory = "c:\\nfs2se\\";
static std::string s_dataDirectory = "./";
static std::string s_cdDirectory = "./";

static std::string moveToRoot(const std::string& path)
{
    if (path.size() >= 2 && path[1] == ':')
    {
        /* Absolute Win32 path (e.g. D:\DATA\...) - map to CD directory */
        if (path.size() >= 3 && path[2] == '\\')
            return s_cdDirectory + std::string(path.begin() + 3, path.end());
        else
            return s_cdDirectory + std::string(path.begin() + 2, path.end());
    }
    else if (path == "nul")
    {
        return "/dev/null";
    }
    else
    {
        /* Relative path - map to local install directory */
        return s_dataDirectory + path;
    }
}

static std::string resolvePathCaseInsensitive(const std::string& path)
{
    if (path.empty())
        return path;

    std::string resolved;
    std::string::size_type start = 0;

    if (path[0] == '/')
    {
        resolved = "/";
        start = 1;
    }
    else if (path.size() >= 2 && path[0] == '.' && path[1] == '/')
    {
        resolved = "./";
        start = 2;
    }

    while (start < path.size())
    {
        std::string::size_type end = path.find('/', start);
        if (end == std::string::npos)
            end = path.size();

        std::string component(path, start, end - start);
        if (component.empty() || component == ".")
        {
            start = end + 1;
            continue;
        }

        /* Try exact match first */
        std::string candidate = resolved + component;
        struct stat st;
        if (stat(candidate.c_str(), &st) == 0)
        {
            resolved = candidate;
        }
        else
        {
#ifdef _WIN32
            /* Windows filesystems are case-insensitive; just append the
             * component as-is and let the OS handle it. */
            resolved += component;
#else
            /* Scan directory for a case-insensitive match */
            const char* dirToOpen = resolved.empty() ? "." : resolved.c_str();
            DIR* dir = opendir(dirToOpen);
            bool found = false;
            if (dir)
            {
                struct dirent* entry;
                while ((entry = readdir(dir)) != nullptr)
                {
                    if (strcasecmp(entry->d_name, component.c_str()) == 0)
                    {
                        resolved += entry->d_name;
                        found = true;
                        break;
                    }
                }
                closedir(dir);
            }
            if (!found)
            {
                /* No match found, keep original (e.g. file to be created) */
                resolved += component;
            }
#endif
        }

        if (end < path.size())
            resolved += '/';

        start = end + 1;
    }

    return resolved;
}

FileEnumerator::FileEnumerator(const char* filename)
    :   m_pattern(moveToRoot(filename))
    ,   m_index(-1)
{
    std::transform(m_pattern.begin(), m_pattern.end(), m_pattern.begin(), ::tolower);
    SDL_Log("Enumerate %s", m_pattern.c_str());
#ifdef _WIN32
    NFS2_ASSERT(sizeof(::WIN32_FIND_DATAA) == sizeof(WIN32_FIND_DATAA));
    ::WIN32_FIND_DATAA findData;
    WIN32_FIND_DATAA result;
    ::HANDLE h = ::FindFirstFileA(m_pattern.c_str(), &findData);
    if (h != ::HANDLE(-1))
    {
        memcpy(&result, &findData, sizeof(result));
        SDL_Log("  ->  %s", result.cFileName);
        m_files.push_back(result);
    }
    while (::FindNextFileA(h, &findData))
    {
        memcpy(&result, &findData, sizeof(result));
        SDL_Log("  ->  %s", result.cFileName);
        m_files.push_back(result);
    }
    ::FindClose(h);
#else
    for (std::string::iterator it = m_pattern.begin(); it != m_pattern.end(); ++it)
        if (*it == '\\') *it = '/';
    /* hack - replace *.* with *
     * I hate windows
     */
    size_t pos = m_pattern.find("*.*");
    if (pos != std::string::npos)
        m_pattern.replace(pos, 3, "*");
    /* Case-insensitive file enumeration for Win32 compatibility */
    std::string dirPath, filePattern;
    size_t lastSlash = m_pattern.rfind('/');
    if (lastSlash != std::string::npos)
    {
        dirPath = m_pattern.substr(0, lastSlash);
        filePattern = m_pattern.substr(lastSlash + 1);
    }
    else
    {
        dirPath = ".";
        filePattern = m_pattern;
    }
    dirPath = resolvePathCaseInsensitive(dirPath);
    DIR* d = opendir(dirPath.c_str());
    if (d)
    {
        struct dirent* entry;
        while ((entry = readdir(d)) != nullptr)
        {
            if (fnmatch(filePattern.c_str(), entry->d_name, FNM_CASEFOLD) == 0)
            {
                std::string fullPath = dirPath + "/" + entry->d_name;
                struct stat buffer;
                stat(fullPath.c_str(), &buffer);
                WIN32_FIND_DATAA data;
                memset(&data, 0, sizeof(data));
                data.dwFileAttributes = (buffer.st_mode & S_IFDIR) ? 16 : 0;
                data.nFileSizeHigh = 0;
                data.nFileSizeLow = buffer.st_size;
                strncpy(data.cFileName, entry->d_name, sizeof(data.cFileName)-1);
                m_files.push_back(data);
            }
        }
        closedir(d);
    }
#endif
}

FileEnumerator::~FileEnumerator()
{
}

bool FileEnumerator::findNext(WIN32_FIND_DATAA *data)
{
    m_index++;
    if (size_t(m_index) >= m_files.size())
    {
        return false;
    }
    else
    {
        memcpy(data, &m_files[m_index], sizeof(*data));
        return true;
    }
}

File::File(int file, const char* name)
    :   m_file(_dup(file))
    ,   m_filename(name)
{
}

File::File(const File& other)
    :   m_file(_open(other.m_filename.c_str(), O_RDONLY|O_BINARY, 0664))
    ,   m_filename(other.m_filename)
{
    SDL_Log("opening file %s for Map", m_filename.c_str());
}

File::File(const char* path, x86::reg32 mode, x86::reg32 flags, x86::reg32 creationFlags)
    :   m_file()
    ,   m_filename(moveToRoot(path))
{
    NFS2_USE(flags);
    std::transform(m_filename.begin(), m_filename.end(), m_filename.begin(), ::tolower);
    if (m_filename == "nul")
    {
        m_filename = "/dev/null";
    }
    //NFS2_ASSERT((flags & FILE_FLAG_OVERLAPPED) == 0);
    for (std::string::iterator it = m_filename.begin(); it != m_filename.end(); ++it)
        if (*it == '\\') *it = '/';
    m_filename = resolvePathCaseInsensitive(m_filename);
    int openFlags = O_BINARY;
    switch(mode)
    {
    case GENERIC_READ:
        openFlags |= O_RDONLY;
        break;
    case GENERIC_WRITE:
        openFlags |= O_WRONLY;
        break;
    case GENERIC_READ|GENERIC_WRITE:
        openFlags |= O_RDWR;
        break;
    default:
        NFS2_ASSERT(false);
    }
    switch(creationFlags)
    {
    case CREATE_NEW:
        openFlags |= O_CREAT;
        break;
    case CREATE_ALWAYS:
        openFlags |= O_CREAT | O_TRUNC;
        break;
    case OPEN_ALWAYS:
        openFlags |= O_CREAT;
        break;
    case OPEN_EXISTING:
        break;
    case TRUNCATE_EXISTING:
        openFlags |= O_TRUNC;
        break;
    default:
        NFS2_ASSERT(false);
    }

    m_file = _open(m_filename.c_str(), openFlags, 0664);
    if (m_file == -1)
    {
        SDL_Log("unable to open file %s", m_filename.c_str());
    }
    else
    {
        SDL_Log("opening file %s", m_filename.c_str());
    }
}

File::~File()
{
    if (m_file != -1)
    {
        _close(m_file);
        SDL_Log("closing file %s", m_filename.c_str());
    }
}

x86::reg32 File::seek(x86::reg32 mode, x86::sreg32 offset)
{
    int seekMode = 0;
    switch(mode)
    {
    case 0:
        seekMode = SEEK_SET;
        break;
    case 1:
        seekMode = SEEK_CUR;
        break;
    case 2:
        seekMode = SEEK_END;
        break;
    default:
        NFS2_ASSERT(false);
        break;
    }
    x86::reg32 result = _lseek(m_file, offset, seekMode);
    return result;
}

x86::reg32 File::read(void* buffer, x86::reg32 max, x86::reg32* totalRead)
{
    *totalRead = ::_read(m_file, buffer, max);
    return *totalRead != x86::reg32(-1); //*totalRead == max;
}

x86::reg32 File::write(const void* buffer, x86::reg32 max, x86::reg32* totalWritten)
{
    *totalWritten = ::_write(m_file, buffer, max);
    return *totalWritten == max;
}

x86::reg32 File::truncate()
{
    SDL_Log("Truncating file %s", m_filename.c_str());
    return _chsize(m_file, _lseek(m_file, 0, 1)) == 0;
}

x86::reg32 File::size() const
{
    struct stat buffer;
    fstat(m_file, &buffer);
    return buffer.st_size;
}

const std::string& File::getCurrentDirectory()
{
    return s_currentDirectory;
}

void File::setCurrentDirectory(const char* path)
{
    s_currentDirectory = path;
    if (s_currentDirectory.back() != '\\')
        s_currentDirectory.append("\\");
}

void File::setDataDirectory(const char* path)
{
    s_dataDirectory = path;
    if (s_dataDirectory.back() != '/')
        s_dataDirectory.append("/");
}

void File::setCdDirectory(const char* path)
{
    s_cdDirectory = path;
    if (s_cdDirectory.back() != '/')
        s_cdDirectory.append("/");
}

x86::reg32 File::remove(const char *filename)
{
    std::string f = moveToRoot(filename);
    std::transform(f.begin(), f.end(), f.begin(), ::tolower);
    for (std::string::iterator it = f.begin(); it != f.end(); ++it)
        if (*it == '\\') *it = '/';
    f = resolvePathCaseInsensitive(f);
    if (_unlink(f.c_str()) != 0)
    {
        SDL_Log("unable to delete file %s", filename);
        return 0;
    }
    else
    {
        SDL_Log("Deleting file %s", filename);
        return 1;
    }
}

}

