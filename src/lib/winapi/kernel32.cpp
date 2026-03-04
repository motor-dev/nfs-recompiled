#include <winapi/kernel32.h>
#include <x86.h>
#include <lib/memmap.h>
#include <lib/mutex.h>
#include <lib/event.h>
#include <lib/file.h>
#include <lib/library.h>
#include <lib/process.h>
#include <lib/timer.h>
#include <lib/window.h>
#include <lib/thread.h>
#include <cstring>
#include <vector>
#include <SDL_log.h>

namespace win32 { namespace kernel32
{

struct OSVERSIONINFOA
{
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR  szCSDVersion[128];
};

struct OSVERSIONINFOEXA
{
    OSVERSIONINFOA versionInfoA;
    WORD  wServicePackMajor;
    WORD  wServicePackMinor;
    WORD  wSuiteMask;
    BYTE  wProductType;
    BYTE  wReserved;
};

BOOL CloseHandle(WinApplication* app, x86::CPU& cpu,
                 HANDLE hObject)
{
    NFS2_USE(cpu);
    if (hObject)
        app->freeResource(hObject);
    return 1;
}

LONG CompareFileTime(WinApplication* app, x86::CPU& cpu,
                     const FILETIME *lpFileTime1, const FILETIME *lpFileTime2)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (lpFileTime1->dwHighDateTime < lpFileTime2->dwHighDateTime)
    {
        return -1;
    }
    else if (lpFileTime1->dwHighDateTime == lpFileTime2->dwHighDateTime)
    {
        if (lpFileTime1->dwLowDateTime < lpFileTime2->dwLowDateTime)
        {
            return -1;
        }
        else if (lpFileTime1->dwLowDateTime == lpFileTime2->dwLowDateTime)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

BOOL CreateDirectoryA(WinApplication* app, x86::CPU& cpu,
                      LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpPathName);
    NFS2_USE(lpSecurityAttributes);
    NFS2_ASSERT(false);
    return 0;
}

HANDLE CreateEventA(WinApplication* app, x86::CPU& cpu,
                    LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCSTR lpName)
{
    NFS2_USE(cpu);
    NFS2_USE(lpEventAttributes);
    win32::Event* event = new win32::Event(lpName, bManualReset != 0, bInitialState != 0);
    return app->allocateResource(event);
}

HANDLE CreateFileA(WinApplication* app, x86::CPU& cpu,
                   LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
                   LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
                   DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
    NFS2_USE(cpu);
    NFS2_USE(dwShareMode);
    NFS2_USE(lpSecurityAttributes);
    NFS2_USE(hTemplateFile);
    win32::File* file = new win32::File(lpFileName, dwDesiredAccess, dwFlagsAndAttributes, dwCreationDisposition);
    if (*file)
    {
        return app->allocateResource(file);
    }
    else
    {
        delete file;
        return HANDLE(-1);
    }
}

HANDLE CreateFileMappingA(WinApplication* app, x86::CPU& cpu,
                          HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                          DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow,
                          LPCSTR lpName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpFileMappingAttributes);
    NFS2_USE(dwMaximumSizeHigh);
    NFS2_USE(dwMaximumSizeLow);
    NFS2_USE(lpName);
    NFS2_ASSERT(flProtect & 0x2);
    File* file = new File(*dynamic_cast<File*>(app->getResource(hFile)));
    return app->allocateResource(file);
}

HANDLE CreateMutexA(WinApplication* app, x86::CPU& cpu,
                    LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
    NFS2_USE(cpu);
    NFS2_USE(lpMutexAttributes);
    win32::Mutex* mutex = new win32::Mutex(lpName);
    if (bInitialOwner)
    {
        app->unlockContext(cpu);
        mutex->lock();
        app->lockContext(cpu);
    }
    return app->allocateResource(mutex);
}

HANDLE CreateThread(WinApplication* app, x86::CPU& cpu,
                    LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize,
                    LPTHREAD_START_ROUTINE lpStartAddress, x86::reg32 lpParameter, DWORD dwCreationFlags,
                    LPDWORD lpThreadId)
{
    NFS2_USE(cpu);
    NFS2_USE(lpThreadAttributes);
    NFS2_ASSERT(dwStackSize <= 1024*1024);
    win32::Thread* thread = new win32::Thread(app, lpStartAddress, lpParameter, dwCreationFlags);
    if ((dwCreationFlags & 0x4) == 0) // CREATE_SUSPENDED
    {
        thread->resume();
    }
    if (lpThreadId) *lpThreadId = thread->threadId();
    return app->allocateResource(thread);
}

void DebugBreak(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void DeleteCriticalSection(WinApplication* app, x86::CPU& cpu,
                           LPCRITICAL_SECTION lpCriticalSection)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    app->freeResource((*lpCriticalSection)->getResourceIndex());
}

BOOL DeleteFileA(WinApplication* app, x86::CPU& cpu,
                 LPCSTR lpFileName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return File::remove(lpFileName);
}

BOOL DuplicateHandle(WinApplication* app, x86::CPU& cpu,
                     HANDLE hSourceProcessHandle, HANDLE hSourceHandle, HANDLE hTargetProcessHandle,
                     LPHANDLE lpTargetHandle, DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions)
{
    NFS2_USE(cpu);
    NFS2_USE(hSourceProcessHandle);
    NFS2_USE(hTargetProcessHandle);
    NFS2_USE(dwDesiredAccess);
    NFS2_USE(bInheritHandle);
    NFS2_USE(dwOptions);
    win32::GenericResource* sourceHandle = dynamic_cast<win32::GenericResource*>(app->getResource(hSourceHandle));
    NFS2_ASSERT(dynamic_cast<win32::Thread*>(sourceHandle));
    *lpTargetHandle = app->allocateResource(dynamic_cast<win32::Thread*>(sourceHandle)->duplicate());
    return 1;
}

void EnterCriticalSection(WinApplication* app, x86::CPU& cpu,
                          LPCRITICAL_SECTION lpCriticalSection)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    app->unlockContext(cpu);
    (*lpCriticalSection)->lock();
    app->lockContext(cpu);
}

BOOL EscapeCommFunction(WinApplication* app, x86::CPU& cpu,
                        HANDLE hFile, DWORD dwFunc)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_USE(dwFunc);
    NFS2_ASSERT(false);
    return 0;
}

void ExitProcess(WinApplication* app, x86::CPU& cpu,
                 UINT uExitCode)
{
    NFS2_USE(app);
    NFS2_USE(uExitCode);
    win32::Window::postMessage(0, 0x0012, 0, 0);
    cpu.terminate = true;
}

void ExitThread(WinApplication* app, x86::CPU& cpu,
                DWORD dwExitCode)
{
    NFS2_USE(app);
    NFS2_USE(dwExitCode);
    cpu.terminate = true;
}

BOOL FindClose(WinApplication* app, x86::CPU& cpu,
               HANDLE hFindFile)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    app->freeResource(hFindFile);
    return 1;
}

HANDLE FindFirstFileA(WinApplication* app, x86::CPU& cpu,
                      LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
{
    NFS2_USE(cpu);
    win32::FileEnumerator* enumerator = new win32::FileEnumerator(lpFileName);
    if (enumerator->findNext(lpFindFileData))
    {
        return app->allocateResource(enumerator);
    }
    else
    {
        delete enumerator;
        return -1;
    }
}

BOOL FindNextFileA(WinApplication* app, x86::CPU& cpu,
                   HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
{
    NFS2_USE(cpu);
    FileEnumerator* enumerator = dynamic_cast<FileEnumerator*>(app->getResource(hFindFile));
    return enumerator->findNext(lpFindFileData);
}

BOOL FlushFileBuffers(WinApplication* app, x86::CPU& cpu,
                      HANDLE hFile)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_ASSERT(false);
    return 0;
}

BOOL FreeEnvironmentStringsA(WinApplication* app, x86::CPU& cpu,
                             LPSTR lpszEnvironmentBlock)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpszEnvironmentBlock
    );
    return 1;
}

BOOL FreeLibrary(WinApplication* app, x86::CPU& cpu,
                 HMODULE hLibModule)
{
    NFS2_USE(cpu);
    app->freeResource(hLibModule);
    return 1;
}

UINT GetACP(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
    return 0;
}

BOOL GetCPInfo(WinApplication* app, x86::CPU& cpu,
               UINT CodePage, LPCPINFO lpCPInfo)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(CodePage);
    lpCPInfo->MaxCharSize = 1;
    lpCPInfo->DefaultChar[0] = '?';
    lpCPInfo->DefaultChar[1] = 0;
    lpCPInfo->LeadByte[0] = 0;
    lpCPInfo->LeadByte[1] = 0;
    lpCPInfo->LeadByte[2] = 0;
    lpCPInfo->LeadByte[3] = 0;
    lpCPInfo->LeadByte[4] = 0;
    lpCPInfo->LeadByte[5] = 0;
    lpCPInfo->LeadByte[6] = 0;
    lpCPInfo->LeadByte[7] = 0;
    lpCPInfo->LeadByte[8] = 0;
    lpCPInfo->LeadByte[9] = 0;
    lpCPInfo->LeadByte[10] = 0;
    lpCPInfo->LeadByte[11] = 0;
    return 1;
}

BOOL GetCommModemStatus(WinApplication* app, x86::CPU& cpu,
                        HANDLE hFile, LPDWORD lpModemStat)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_USE(lpModemStat);
    NFS2_ASSERT(false);
    return 0;
}

BOOL GetCommProperties(WinApplication* app, x86::CPU& cpu,
                       HANDLE hFile, LPCOMMPROP lpCommProp)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_USE(lpCommProp);
    NFS2_ASSERT(false);
    return 0;
}

BOOL GetCommState(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile, LPDCB lpDCB)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_USE(lpDCB);
    NFS2_ASSERT(false);
    return 0;
}

x86::reg32 GetCommandLineA(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(cpu);
    SDL_Log("%s", app->getAppNameRaw());
    return app->getAppName();
}

x86::reg32 GetCommandLineW(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0;
}

BOOL GetConsoleMode(WinApplication* app, x86::CPU& cpu,
                    HANDLE hConsoleHandle, LPDWORD lpMode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hConsoleHandle);
    *lpMode = 0;
    return 1;
}

DWORD GetCurrentDirectoryA(WinApplication* app, x86::CPU& cpu,
                           DWORD nBufferLength, LPSTR lpBuffer)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(nBufferLength);
    NFS2_ASSERT(lpBuffer);
    strcpy(lpBuffer, File::getCurrentDirectory().c_str());
    return static_cast<DWORD>(File::getCurrentDirectory().length());
}

HANDLE GetCurrentProcess(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(cpu);
    return app->allocateResource(new win32::Process());
}

DWORD GetCurrentProcessId(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
    return 0;
}

DWORD GetCurrentThreadId(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(cpu);
    return app->getMemory<x86::reg32>(cpu.efs + 0x4);
}

HANDLE GetCurrentThread(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(cpu);
    return app->allocateResource(new win32::Thread());
}

BOOL GetDiskFreeSpaceA(WinApplication* app, x86::CPU& cpu,
                       LPCSTR lpRootPathName, LPDWORD lpSectorsPerCluster, LPDWORD lpBytesPerSector,
                       LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpRootPathName);
    if (lpSectorsPerCluster) *lpSectorsPerCluster = 1;
    if (lpBytesPerSector) *lpBytesPerSector = 512;
    if (lpNumberOfFreeClusters) *lpNumberOfFreeClusters = 512*1024;
    if (lpTotalNumberOfClusters) *lpTotalNumberOfClusters = 1024*1024;
    return 1;
}

UINT GetDriveTypeA(WinApplication* app, x86::CPU& cpu,
                   LPCSTR lpRootPathName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    switch(*lpRootPathName)
    {
    case 'C':
        return 3; //DISK
    case 'D':
        return 5; //CDROM
    default:
        return 1; //INVALID
    }
}

x86::reg32 GetEnvironmentStrings(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return app->getEnv();
}

DWORD GetFileAttributesA(WinApplication* app, x86::CPU& cpu,
                         LPCSTR lpFileName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    File f(lpFileName, GENERIC_READ, 0, OPEN_EXISTING);
    if (f)
    {
        return 0x1;
    }
    else
    {
        return 0xffffffff;
    }
}

BOOL GetFileTime(WinApplication* app, x86::CPU& cpu,
                 HANDLE hFile, LPFILETIME lpCreationTime, LPFILETIME lpLastAccessTime, LPFILETIME lpLastWriteTime)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    if (lpCreationTime)
    {
        lpCreationTime->dwLowDateTime = 0;
        lpCreationTime->dwHighDateTime = 0;
    }
    if (lpLastAccessTime)
    {
        lpLastAccessTime->dwLowDateTime = 0;
        lpLastAccessTime->dwHighDateTime = 0;
    }
    if (lpLastWriteTime)
    {
        lpLastWriteTime->dwLowDateTime = 0;
        lpLastWriteTime->dwHighDateTime = 0;
    }
    return 0;
}

DWORD GetFileSize(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile, LPDWORD lpFileSizeHigh)
{
    NFS2_USE(cpu);
    win32::File* file = dynamic_cast<win32::File*>(app->getResource(hFile));
    if (lpFileSizeHigh)
        *lpFileSizeHigh = 0;
    return file->size();
}

DWORD GetFileType(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile)
{
    NFS2_USE(cpu);
    win32::File* f = dynamic_cast<win32::File*>(app->getResource(hFile));
    return f ? 1 : 0;
}

DWORD GetFullPathNameA(WinApplication* app, x86::CPU& cpu,
                       LPCSTR lpFileName, DWORD nBufferLength, LPSTR lpBuffer, x86::reg32* lpFilePart)
{
    NFS2_USE(nBufferLength);
    x86::reg32 lpBufferAddress = app->getMemory<x86::reg32>(cpu.esp + 12);
    NFS2_ASSERT(&app->getMemory<char>(lpBufferAddress) == lpBuffer);
    strcpy(lpBuffer, "C:\\nfs2se\\");
    *lpFilePart = lpBufferAddress + static_cast<x86::reg32>(strlen(lpBuffer));
    strcat(lpBuffer, lpFileName);
    return static_cast<DWORD>(strlen(lpBuffer));
}

DWORD GetLastError(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    //NFS2_ASSERT(false);
    return 0;
}

void GetLocalTime(WinApplication* app, x86::CPU& cpu,
                  LPSYSTEMTIME lpSystemTime)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    win32::getSystemTime(lpSystemTime);
}

DWORD GetLogicalDriveStringsA(WinApplication* app, x86::CPU& cpu,
                              DWORD nBufferLength, LPSTR lpBuffer)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (nBufferLength)
    {
        lpBuffer[0] = 'C';
        lpBuffer[1] = 'D';
        lpBuffer[2] = 0;
    }
    return 2;
}

DWORD GetLogicalDrives(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0x2 | 0x4;
}

DWORD GetModuleFileNameA(WinApplication* app, x86::CPU& cpu,
                         HMODULE hModule, LPSTR lpFilename, DWORD nSize)
{
    NFS2_USE(cpu);
    NFS2_USE(nSize);
    *(lpFilename++) = 'C';
    *(lpFilename++) = ':';
    *(lpFilename++) = '\\';
    if (!hModule)
    {
        const char* exeFilename = app->getAppNameRaw();
        DWORD result = 0;
        while (*exeFilename)
        {
            *(lpFilename++) = *(exeFilename++);
            result++;
        }
        *lpFilename = 0;
        return result;
    }
    else
    {
        NFS2_ASSERT(false);
        return 0;
    }
}

DWORD GetModuleFileNameW(WinApplication* app, x86::CPU& cpu,
                         HMODULE hModule, LPWSTR lpFilename, DWORD nSize)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hModule);
    NFS2_USE(lpFilename);
    NFS2_USE(nSize);
    NFS2_ASSERT(false);
    return 0;
}

HMODULE GetModuleHandleA(WinApplication* app, x86::CPU& cpu,
                         LPCSTR lpModuleName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (lpModuleName)
    {
        NFS2_ASSERT(false);
        return 0xffffffff;
    }
    else
    {
        return 1;
    }
}

UINT GetOEMCP(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 850;
}

BOOL GetOverlappedResult(WinApplication* app, x86::CPU& cpu,
                         HANDLE hFile, LPOVERLAPPED lpOverlapped,
                         LPDWORD lpNumberOfBytesTransferred, BOOL bWait)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_USE(lpOverlapped);
    NFS2_USE(lpNumberOfBytesTransferred);
    NFS2_USE(bWait);
    NFS2_ASSERT(false);
    return 0;
}

FARPROC GetProcAddress(WinApplication* app, x86::CPU& cpu,
                       HMODULE hModule, LPCSTR lpProcName)
{
    NFS2_USE(cpu);
    win32::LibraryHandle* libraryHandle = dynamic_cast<win32::LibraryHandle*>(app->getResource(hModule));
    win32::Library* l = libraryHandle->getLibrary();
    win32::Library::Symbol s = (*l)[lpProcName];
    NFS2_ASSERT(s.first);
    return s.first;
}

HANDLE GetStdHandle(WinApplication* app, x86::CPU& cpu,
                    DWORD nStdHandle)
{
    NFS2_USE(cpu);
    switch(nStdHandle)
    {
    case x86::reg32(-10):
        {
            // stdin
            win32::File* h = new win32::File(0, "stdin");
            return app->allocateResource(h);
        }
    case x86::reg32(-11):
        {
            // stdout
            win32::File* h = new win32::File(1, "stdout");
            return app->allocateResource(h);
        }
    case x86::reg32(-12):
        {
            // stderr
            win32::File* h = new win32::File(2, "stderr");
            return app->allocateResource(h);
        }
    default:
        NFS2_ASSERT(false);
        return HANDLE(-1);
    }
}

void GetSystemInfo(WinApplication* app, x86::CPU& cpu,
                   LPSYSTEM_INFO lpSystemInfo)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    lpSystemInfo->wProcessorArchitecture = 0;
    lpSystemInfo->wReserved = 0;
    lpSystemInfo->dwPageSize = 4096;
    lpSystemInfo->lpMinimumApplicationAddress = 0x2000;
    lpSystemInfo->lpMinimumApplicationAddress = 0xffffffff;
    lpSystemInfo->dwActiveProcessorMask = 1;
    lpSystemInfo->dwNumberOfProcessors = 1;
    lpSystemInfo->dwProcessorType = 2;
    lpSystemInfo->dwAllocationGranularity = 4096;
    lpSystemInfo->wProcessorLevel = 5;
    lpSystemInfo->wProcessorRevision = 0xff50;
}

int GetThreadPriority(WinApplication* app, x86::CPU& cpu,
                      HANDLE hThread)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hThread);
    NFS2_ASSERT(false);
    return 0;
}

DWORD GetTickCount(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    DWORD result = timeGetTickCount();
    return result;
}

DWORD GetTimeZoneInformation(WinApplication* app, x86::CPU& cpu,
                             LPTIME_ZONE_INFORMATION lpTimeZoneInformation)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpTimeZoneInformation);
    NFS2_ASSERT(false);
    return 0;
}

DWORD GetVersion(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0x80000304;
}

BOOL GetVersionExA(WinApplication* app, x86::CPU& cpu,
                   LPOSVERSIONINFOA lpVersionInformation)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    lpVersionInformation->dwMajorVersion = 5;
    lpVersionInformation->dwMinorVersion = 1;
    lpVersionInformation->dwBuildNumber = 2600;
    lpVersionInformation->dwPlatformId = 2;
    strcpy(lpVersionInformation->szCSDVersion, "Service Pack 3");
    if (lpVersionInformation->dwOSVersionInfoSize == sizeof(OSVERSIONINFOEXA))
    {
        OSVERSIONINFOEXA* info = reinterpret_cast<OSVERSIONINFOEXA*>(lpVersionInformation);
        info->wProductType = 1;
        info->wServicePackMajor = 3;
        info->wServicePackMinor = 0;
    }
    return 1;
}

BOOL GetVolumeInformationA(WinApplication* app, x86::CPU& cpu,
                           LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer, DWORD nVolumeNameSize,
                           LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength,
                           LPDWORD lpFileSystemFlags, LPSTR lpFileSystemNameBuffer,
                           DWORD nFileSystemNameSize)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpRootPathName);
    if (lpVolumeNameBuffer && nVolumeNameSize)
    {
        strcpy(lpVolumeNameBuffer, "DISK");
    }
    if (lpVolumeSerialNumber)
        *lpVolumeSerialNumber = 0x12345678;
    if (lpMaximumComponentLength)
        *lpMaximumComponentLength = 255;
    if (lpFileSystemFlags)
        *lpFileSystemFlags = 1|2|4;
    if (lpFileSystemNameBuffer && nFileSystemNameSize)
        strcpy(lpFileSystemNameBuffer, "FAT");
    return 1;
}

UINT GetWindowsDirectoryA(WinApplication* app, x86::CPU& cpu,
                          LPSTR lpBuffer, UINT uSize)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpBuffer);
    NFS2_USE(uSize);
    NFS2_ASSERT(false);
    return 0;
}

void GlobalMemoryStatus(WinApplication* app, x86::CPU& cpu,
                        LPMEMORYSTATUS lpBuffer)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    lpBuffer->dwLength = sizeof(MEMORYSTATUS);
    lpBuffer->dwMemoryLoad = 0;
    lpBuffer->dwTotalPhys = 268435456;
    lpBuffer->dwAvailPhys = 268435456;
    lpBuffer->dwTotalPageFile = 268435456;
    lpBuffer->dwAvailPageFile = 268435456;
    lpBuffer->dwTotalVirtual = 0x7fffffff;
    lpBuffer->dwAvailVirtual = 0x7fffffff;
}

void InitializeCriticalSection(WinApplication* app, x86::CPU& cpu,
                               LPCRITICAL_SECTION lpCriticalSection)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    *lpCriticalSection = new win32::Mutex("");
    app->allocateResource(*lpCriticalSection);
}

void LeaveCriticalSection(WinApplication* app, x86::CPU& cpu,
                          LPCRITICAL_SECTION lpCriticalSection)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    (*lpCriticalSection)->unlock();
    app->unlockContext(cpu);
    app->lockContext(cpu);
}

HMODULE LoadLibraryA(WinApplication* app, x86::CPU& cpu,
                     LPCSTR lpLibFileName)
{
    NFS2_USE(cpu);
    SDL_Log("Loading library %s", lpLibFileName);
    win32::LibraryHandle* lib = new win32::LibraryHandle(lpLibFileName);
    if (*lib)
    {
        //lib->getLibrary()->registerSymbols(app);
        return app->allocateResource(lib);
    }
    else
    {
        delete lib;
        //NFS2_ASSERT(false);
        return -1;
    }
}

x86::reg32 MapViewOfFile(WinApplication* app, x86::CPU& cpu,
                         HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh,
                         DWORD dwFileOffsetLow, SIZE_T dwNumberOfBytesToMap)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwDesiredAccess);
    NFS2_ASSERT(dwFileOffsetHigh == 0);
    app->unlockContext(cpu);
    File* file = dynamic_cast<File*>(app->getResource(hFileMappingObject));
    MemMap* result = new MemMap(dwNumberOfBytesToMap);
    void* data = &app->getMemory<void>(result->getBlockStart());
    file->seek(0, x86::sreg32(dwFileOffsetLow));
    x86::reg32 bytesRead = 0;
    file->read(data, dwNumberOfBytesToMap, &bytesRead);
    NFS2_ASSERT(bytesRead == dwNumberOfBytesToMap);
    app->lockContext(cpu);
    return result->getBlockStart();
}

BOOL MoveFileA(WinApplication* app, x86::CPU& cpu,
               LPCSTR lpExistingFileName, LPCSTR lpNewFileName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpExistingFileName);
    NFS2_USE(lpNewFileName);
    NFS2_ASSERT(false);
    return 0;
}

int MultiByteToWideChar(WinApplication* app, x86::CPU& cpu,
                        UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr,
                        int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(CodePage);
    NFS2_USE(dwFlags);
    NFS2_USE(cchWideChar);
    int result = 0;
    if (lpWideCharStr)
        *lpWideCharStr++ = 0xfffe;
    for (int i = 0; i < cbMultiByte; ++i)
    {
        result++;
        if (lpWideCharStr)
            *lpWideCharStr++ = *lpMultiByteStr++;
        if (!*lpMultiByteStr)
            break;
    }
    return result;
}

void OutputDebugStringA(WinApplication* app, x86::CPU& cpu,
                        LPCSTR lpOutputString)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    SDL_Log("%s", lpOutputString);
    NFS2_ASSERT(false);
}

BOOL PeekConsoleInputA(WinApplication* app, x86::CPU& cpu,
                       HANDLE hConsoleInput, PINPUT_RECORD lpBuffer,
                       DWORD nLength, LPDWORD lpNumberOfEventsRead)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hConsoleInput);
    NFS2_USE(lpBuffer);
    NFS2_USE(nLength);
    NFS2_USE(lpNumberOfEventsRead);
    //NFS2_ASSERT(false);
    *lpNumberOfEventsRead = 0;
    return 1;
}

BOOL PulseEvent(WinApplication* app, x86::CPU& cpu, HANDLE hEvent)
{
    NFS2_USE(cpu);
    Event* event = dynamic_cast<Event*>(app->getResource(hEvent));
    return event->pulse();
}

BOOL PurgeComm(WinApplication* app, x86::CPU& cpu,
               HANDLE hFile, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_USE(dwFlags);
    NFS2_ASSERT(false);
    return 0;
}

BOOL ReadConsoleInputA(WinApplication* app, x86::CPU& cpu,
                       HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, DWORD nLength,
                       LPDWORD lpNumberOfEventsRead)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hConsoleInput);
    NFS2_USE(lpBuffer);
    NFS2_USE(nLength);
    //NFS2_ASSERT(false);
    *lpNumberOfEventsRead = 0;
    return 1;
}

BOOL ReadFile(WinApplication* app, x86::CPU& cpu,
              HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
              LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
    NFS2_USE(cpu);
    NFS2_USE(lpOverlapped);
    win32::File* f = dynamic_cast<win32::File*>(app->getResource(hFile));
    if (!f)
    {
        return 0;
    }
    else
    {
        app->unlockContext(cpu);
        BOOL result = f->read(lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead);
        app->lockContext(cpu);
        return result;
    }
}

BOOL RemoveDirectoryA(WinApplication* app, x86::CPU& cpu, LPCSTR lpPathName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpPathName);
    NFS2_ASSERT(false);
    return 0;
}

BOOL ResetEvent(WinApplication* app, x86::CPU& cpu, HANDLE hEvent)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hEvent);
    NFS2_ASSERT(false);
    return 0;
}

DWORD ResumeThread(WinApplication* app, x86::CPU& cpu,
                   HANDLE hThread)
{
    NFS2_USE(cpu);
    win32::Thread* thread = dynamic_cast<win32::Thread*>(app->getResource(hThread));
    thread->resume();
    return 1;
}

void RtlUnwind(WinApplication* app, x86::CPU& cpu,
               PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(TargetFrame);
    NFS2_USE(TargetIp);
    NFS2_USE(ExceptionRecord);
    NFS2_USE(ReturnValue);
    NFS2_ASSERT(false);
}

BOOL SetCommState(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile, LPDCB lpDCB)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_USE(lpDCB);
    NFS2_ASSERT(false);
    return 0;
}

BOOL SetCommTimeouts(WinApplication* app, x86::CPU& cpu,
                     HANDLE hFile, LPCOMMTIMEOUTS lpCommTimeouts)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hFile);
    NFS2_USE(lpCommTimeouts);
    NFS2_ASSERT(false);
    return 0;
}

BOOL SetConsoleCtrlHandler(WinApplication* app, x86::CPU& cpu,
                           PHANDLER_ROUTINE HandlerRoutine, BOOL Add)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(HandlerRoutine);
    NFS2_USE(Add);
    NFS2_ASSERT(false);
    return 0;
}

BOOL SetConsoleMode(WinApplication* app, x86::CPU& cpu,
                    HANDLE hConsoleHandle, DWORD  dwMode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hConsoleHandle);
    NFS2_USE(dwMode);
    //NFS2_ASSERT(false);
    return 1;
}

BOOL SetCurrentDirectoryA(WinApplication* app, x86::CPU& cpu,
                          LPCSTR lpPathName)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    File::setCurrentDirectory(lpPathName);
    return 1;
}

BOOL SetEndOfFile(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile)
{
    NFS2_USE(cpu);
    File* file = dynamic_cast<File*>(app->getResource(hFile));
    return file->truncate();
}

BOOL SetEnvironmentVariableA(WinApplication* app, x86::CPU& cpu,
                             LPCSTR lpName, LPCSTR lpValue)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpName);
    NFS2_USE(lpValue);
    // TODO?
    return 0;
}

BOOL SetEnvironmentVariableW(WinApplication* app, x86::CPU& cpu,
                             LPCWSTR lpName, LPCWSTR lpValue)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpName);
    NFS2_USE(lpValue);
    NFS2_ASSERT(false);
    return 0;
}

UINT SetErrorMode(WinApplication* app, x86::CPU& cpu, UINT uMode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(uMode);
    return 0;
}

BOOL SetEvent(WinApplication* app, x86::CPU& cpu,
              HANDLE hEvent)
{
    NFS2_USE(cpu);
    win32::Event* event = dynamic_cast<win32::Event*>(app->getResource(hEvent));
    if (event)
    {
        event->set();
        return 1;
    }
    else
    {
        NFS2_ASSERT(false);
        return 0;
    }
}

BOOL SetFileAttributesA(WinApplication* app, x86::CPU& cpu,
                        LPCSTR lpFileName, DWORD  dwFileAttributes)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpFileName);
    NFS2_USE(dwFileAttributes);
    //NFS2_ASSERT(false);
    return 0;
}

DWORD SetFilePointer(WinApplication* app, x86::CPU& cpu,
                     HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod)
{
    NFS2_USE(cpu);
    win32::File* file= dynamic_cast<win32::File*>(app->getResource(hFile));
    NFS2_ASSERT(lpDistanceToMoveHigh == 0);
    return file->seek(dwMoveMethod, lDistanceToMove);
}

void SetLastError(WinApplication* app, x86::CPU& cpu,
                  DWORD dwErrCode)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwErrCode);
}

BOOL SetStdHandle(WinApplication* app, x86::CPU& cpu,
                  DWORD nStdHandle, HANDLE hHandle)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(nStdHandle);
    NFS2_USE(hHandle);
    NFS2_ASSERT(false);
    return 0;
}

BOOL SetThreadPriority(WinApplication* app, x86::CPU& cpu,
                       HANDLE hThread, int nPriority)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hThread);
    NFS2_USE(nPriority);
    return 1;
}

LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(WinApplication* app, x86::CPU& cpu,
                                                         LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpTopLevelExceptionFilter);
    return 0;
}

DWORD SleepEx(WinApplication* app, x86::CPU& cpu,
              DWORD dwMilliseconds, BOOL bAlertable)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(bAlertable);
    app->unlockContext(cpu);
    win32::Thread::sleep(dwMilliseconds);
    app->lockContext(cpu);
    return 0;
}

BOOL TerminateThread(WinApplication* app, x86::CPU& cpu,
                     HANDLE hThread, DWORD dwExitCode)
{
    NFS2_USE(cpu);
    NFS2_USE(dwExitCode);
    Thread* thread = dynamic_cast<Thread*>(app->getResource(hThread));
    app->unlockContext(cpu);
    thread->terminate();
    app->lockContext(cpu);
    return 0;
}

DWORD TlsAlloc(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
    return 0;
}

BOOL TlsFree(WinApplication* app, x86::CPU& cpu,
             DWORD dwTlsIndex)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwTlsIndex);
    NFS2_ASSERT(false);
    return 0;
}

x86::reg32 TlsGetValue(WinApplication* app, x86::CPU& cpu,
                       DWORD dwTlsIndex)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwTlsIndex);
    NFS2_ASSERT(false);
    return 0;
}

BOOL TlsSetValue(WinApplication* app, x86::CPU& cpu,
                 DWORD dwTlsIndex, LPVOID lpTlsValue)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwTlsIndex);
    NFS2_USE(lpTlsValue);
    NFS2_ASSERT(false);
    return 0;
}

LONG UnhandledExceptionFilter(WinApplication* app, x86::CPU& cpu,
                              struct _EXCEPTION_POINTERS *ExceptionInfo)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(ExceptionInfo);
    NFS2_ASSERT(false);
    return 0;
}

BOOL UnmapViewOfFile(WinApplication* app, x86::CPU& cpu,
    Packed<const void> lpBaseAddress)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (lpBaseAddress)
    {
        MemMap* memBlock = MemMap::findBlock(lpBaseAddress);
        delete memBlock;
        return 1;
    }
    else
    {
        return 0;
    }
}

x86::reg32 VirtualAlloc(WinApplication* app, x86::CPU& cpu,
                        LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect)
{
    NFS2_USE(cpu);
    NFS2_USE(flAllocationType);
    NFS2_USE(flProtect);
    NFS2_ASSERT(lpAddress == nullptr);
    MemMap* map = new MemMap(dwSize);
    void* data = &app->getMemory<void>(map->getBlockStart());
    memset(data, 0, dwSize);
    return map->getBlockStart();
}

BOOL VirtualFree(WinApplication* app, x86::CPU& cpu,
                 Packed<void> lpAddress, SIZE_T dwSize, DWORD dwFreeType)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwSize);
    NFS2_ASSERT(dwFreeType = 0x8000);
    MemMap* memBlock = MemMap::findBlock(lpAddress);
    delete memBlock;
    return 1;
}

BOOL VirtualProtect(WinApplication* app, x86::CPU& cpu,
                    Packed<void> lpAddress, SIZE_T dwSize, DWORD flNewProtect, DWORD* lpflOldProtect)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpAddress);
    NFS2_USE(dwSize);
    NFS2_USE(flNewProtect);
    NFS2_USE(lpflOldProtect);
    // TODO?
    return 1;
}

SIZE_T VirtualQuery(WinApplication* app, x86::CPU& cpu,
                    Packed<const void> lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    MemMap* memBlock = MemMap::findBlock(lpAddress);
    NFS2_ASSERT(dwLength == sizeof(MEMORY_BASIC_INFORMATION));
    lpBuffer->BaseAddress = memBlock->getBlockStart();
    lpBuffer->AllocationBase = memBlock->getBlockStart();
    lpBuffer->AllocationProtect = 0x04; //READWRITE
    lpBuffer->RegionSize = memBlock->getBlockSize();
    lpBuffer->State = 0x1000; //COMMIT
    lpBuffer->Protect = 0x04; //READWRITE
    lpBuffer->Type = 0x20000; //PRIVATE
    return sizeof(*lpBuffer);
}

DWORD WaitForMultipleObjectsEx(WinApplication* app, x86::CPU& cpu,
                               DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll,
                               DWORD dwMilliseconds, BOOL bAlertable)
{
    NFS2_USE(cpu);
    NFS2_USE(bAlertable);
    std::vector<win32::Event*> events(nCount);
    for (x86::reg32 i = 0; i < nCount; ++i)
    {
        events[i] = dynamic_cast<win32::Event*>(app->getResource(lpHandles[i]));
        if (!events[i])
        {
            NFS2_ASSERT(false);
            return 0xffffffff;
        }
    }
    app->unlockContext(cpu);
    DWORD result = DWORD(win32::Event::wait(cpu, &events.front(), &events.front() + nCount, bWaitAll, x86::sreg32(dwMilliseconds)));
    app->lockContext(cpu);
    return result;
}

DWORD WaitForSingleObject(WinApplication* app, x86::CPU& cpu,
                          HANDLE hHandle, DWORD dwMilliseconds)
{
    NFS2_USE(cpu);
    app->unlockContext(cpu);
    GenericResource* r = app->getResource(hHandle);
    Event* event = dynamic_cast<win32::Event*>(r);
    DWORD result = DWORD(win32::Event::wait(cpu, &event, &event + 1, 0, x86::sreg32(dwMilliseconds)));
    app->lockContext(cpu);
    return result;
}

int WideCharToMultiByte(WinApplication* app, x86::CPU& cpu,
                        UINT CodePage, DWORD dwFlags, LPCWCH lpWideCharStr, int cchWideChar,
                        LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(CodePage);
    NFS2_USE(dwFlags);
    NFS2_USE(lpWideCharStr);
    NFS2_USE(cchWideChar);
    NFS2_USE(lpMultiByteStr);
    NFS2_USE(cbMultiByte);
    NFS2_USE(lpDefaultChar);
    NFS2_USE(lpUsedDefaultChar);
    NFS2_ASSERT(false);
    return 0;
}

BOOL WriteConsoleA(WinApplication* app, x86::CPU& cpu,
                   HANDLE hConsoleOutput, const void* lpBuffer, DWORD nNumberOfCharsToWrite,
                   LPDWORD lpNumberOfCharsWritten, LPVOID  lpReserved)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hConsoleOutput);
    NFS2_USE(lpBuffer);
    NFS2_USE(nNumberOfCharsToWrite);
    NFS2_USE(lpNumberOfCharsWritten);
    NFS2_USE(lpReserved);
    NFS2_ASSERT(false);
    return 0;
}

BOOL WriteFile(WinApplication* app, x86::CPU& cpu,
               HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
               LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped)
{
    NFS2_USE(cpu);
    NFS2_ASSERT(lpOverlapped == nullptr);
    win32::File* f = dynamic_cast<win32::File*>(app->getResource(hFile));
    if (!f)
    {
        return 0;
    }
    else
    {
        app->unlockContext(cpu);
        x86::reg32 result = f->write(lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten);
        app->lockContext(cpu);
        return result;
    }
}

HFILE _lclose(WinApplication* app, x86::CPU& cpu, HFILE hFile)
{
    NFS2_USE(cpu);
    app->freeResource(hFile);
    return hFile;
}

HFILE _lopen(WinApplication* app, x86::CPU& cpu, LPCSTR lpPathName, int iReadWrite)
{
    NFS2_USE(cpu);
    NFS2_ASSERT(iReadWrite == 0);
    win32::File* file = new win32::File(lpPathName, 0x80000000, 0, 3);
    return app->allocateResource(file);
}


}}
