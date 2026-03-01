#ifndef LIB_FILE_H_
#define LIB_FILE_H_

#include <lib/winapp.h>
#include <winapi/types.h>
#include <string>
#include <vector>


namespace win32
{

enum
{
    FILE_SHARE_READ                 = 0x00000001,
    FILE_SHARE_WRITE                = 0x00000002,
    FILE_SHARE_DELETE               = 0x00000004,

    CREATE_NEW                      = 1,
    CREATE_ALWAYS                   = 2,
    OPEN_EXISTING                   = 3,
    OPEN_ALWAYS                     = 4,
    TRUNCATE_EXISTING               = 5,

    GENERIC_WRITE                   = 0x40000000,
    GENERIC_READ                    = 0x80000000,


    FILE_ATTRIBUTE_READONLY         = 0x0001,
    FILE_ATTRIBUTE_HIDDEN           = 0x0002,
    FILE_ATTRIBUTE_SYSTEM           = 0x0004,
    FILE_ATTRIBUTE_ARCHIVE          = 0x0020,
    FILE_ATTRIBUTE_NORMAL           = 0x0080,
    FILE_ATTRIBUTE_TEMPORARY        = 0x0100,
    FILE_ATTRIBUTE_OFFLINE          = 0x1000,
    FILE_ATTRIBUTE_ENCRYPTED        = 0x4000,

    FILE_FLAG_OPEN_NO_RECALL        = 0x00100000,
    FILE_FLAG_OPEN_REPARSE_POINT    = 0x00200000,
    FILE_FLAG_SESSION_AWARE         = 0x00800000,
    FILE_FLAG_POSIX_SEMANTICS       = 0x01000000,
    FILE_FLAG_BACKUP_SEMANTICS      = 0x02000000,
    FILE_FLAG_DELETE_ON_CLOSE       = 0x04000000,
    FILE_FLAG_SEQUENTIAL_SCAN       = 0x08000000,
    FILE_FLAG_RANDOM_ACCESS         = 0x10000000,
    FILE_FLAG_NO_BUFFERING          = 0x20000000,
    FILE_FLAG_OVERLAPPED            = 0x40000000,
    FILE_FLAG_WRITE_THROUGH         = 0x80000000
};

class FileEnumerator : public GenericResource
{
public:
    FileEnumerator(const char* filename);
    ~FileEnumerator();

    bool findNext(WIN32_FIND_DATAA* data);

private:
    std::string                     m_pattern;
    std::vector<WIN32_FIND_DATAA>   m_files;
    int                             m_index;
};

class File : public GenericResource
{
public:
    File(int file, const char* name);
    File(const File& other);
    File(const char* path, x86::reg32 mode, x86::reg32 flags, x86::reg32 creationFlags);
    ~File();

    x86::reg32 seek(x86::reg32 mode, x86::sreg32 offset);
    x86::reg32 read(void* buffer, x86::reg32 max, x86::reg32* totalRead);
    x86::reg32 write(const void *buffer, x86::reg32 max, x86::reg32* totalWritten);
    x86::reg32 truncate();
    x86::reg32 size() const;

    static const std::string& getCurrentDirectory();
    static void setCurrentDirectory(const char* path);
    static void setDataDirectory(const char* path);
    static void setCdDirectory(const char* path);
    static x86::reg32 remove(const char* filename);

    operator void*() { return reinterpret_cast<void*>(static_cast<intptr_t>(m_file)+1); }
private:
    int m_file;
    std::string m_filename;
};

}

#endif
