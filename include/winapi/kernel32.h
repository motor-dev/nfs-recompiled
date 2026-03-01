#ifndef kernel32_H_
#define kernel32_H_

#include <x86.h>
#include <lib/winapp.h>
#include <winapi/types.h>

namespace win32 { namespace kernel32
{

struct EXCEPTION_RECORD;
typedef EXCEPTION_RECORD* PEXCEPTION_RECORD;
struct OSVERSIONINFOA;
typedef OSVERSIONINFOA* LPOSVERSIONINFOA;
typedef int HFILE;

BOOL CloseHandle(WinApplication* app, x86::CPU& cpu,
                 HANDLE hObject);
LONG CompareFileTime(WinApplication* app, x86::CPU& cpu,
                     const FILETIME *lpFileTime1, const FILETIME *lpFileTime2);
BOOL CreateDirectoryA(WinApplication* app, x86::CPU& cpu,
                      LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
HANDLE CreateEventA(WinApplication* app, x86::CPU& cpu,
                    LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCSTR lpName);
HANDLE CreateFileA(WinApplication* app, x86::CPU& cpu,
                   LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
                   LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
                   DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
HANDLE CreateFileMappingA(WinApplication* app, x86::CPU& cpu,
                          HANDLE hFile, LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                          DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow,
                          LPCSTR lpName);
HANDLE CreateMutexA(WinApplication* app, x86::CPU& cpu,
                    LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName);
HANDLE CreateThread(WinApplication* app, x86::CPU& cpu,
                    LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize,
                    LPTHREAD_START_ROUTINE lpStartAddress, x86::reg32 lpParameter, DWORD dwCreationFlags,
                    LPDWORD lpThreadId);
void DebugBreak(WinApplication* app, x86::CPU& cpu);
void DeleteCriticalSection(WinApplication* app, x86::CPU& cpu,
                           LPCRITICAL_SECTION lpCriticalSection);
BOOL DeleteFileA(WinApplication* app, x86::CPU& cpu,
                 LPCSTR lpFileName);
BOOL DuplicateHandle(WinApplication* app, x86::CPU& cpu,
                     HANDLE hSourceProcessHandle, HANDLE hSourceHandle, HANDLE hTargetProcessHandle,
                     LPHANDLE lpTargetHandle, DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions);
void EnterCriticalSection(WinApplication* app, x86::CPU& cpu,
                          LPCRITICAL_SECTION lpCriticalSection);
BOOL EscapeCommFunction(WinApplication* app, x86::CPU& cpu,
                        HANDLE hFile, DWORD dwFunc);
void ExitProcess(WinApplication* app, x86::CPU& cpu,
                 UINT uExitCode);
void ExitThread(WinApplication* app, x86::CPU& cpu,
                DWORD dwExitCode);
BOOL FindClose(WinApplication* app, x86::CPU& cpu,
               HANDLE hFindFile);
HANDLE FindFirstFileA(WinApplication* app, x86::CPU& cpu,
                      LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
BOOL FindNextFileA(WinApplication* app, x86::CPU& cpu,
                   HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
BOOL FlushFileBuffers(WinApplication* app, x86::CPU& cpu,
                      HANDLE hFile);
BOOL FreeEnvironmentStringsA(WinApplication* app, x86::CPU& cpu,
                             LPSTR lpszEnvironmentBlock);
BOOL FreeLibrary(WinApplication* app, x86::CPU& cpu,
                 HMODULE hLibModule);
UINT GetACP(WinApplication* app, x86::CPU& cpu);
BOOL GetCPInfo(WinApplication* app, x86::CPU& cpu,
               UINT CodePage, LPCPINFO lpCPInfo);
BOOL GetCommModemStatus(WinApplication* app, x86::CPU& cpu,
                        HANDLE hFile, LPDWORD lpModemStat);
BOOL GetCommProperties(WinApplication* app, x86::CPU& cpu,
                       HANDLE hFile, LPCOMMPROP lpCommProp);
BOOL GetCommState(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile, LPDCB lpDCB);
x86::reg32 GetCommandLineA(WinApplication* app, x86::CPU& cpu);
x86::reg32 GetCommandLineW(WinApplication* app, x86::CPU& cpu);
BOOL GetConsoleMode(WinApplication* app, x86::CPU& cpu,
                    HANDLE hConsoleHandle, LPDWORD lpMode);
DWORD GetCurrentDirectoryA(WinApplication* app, x86::CPU& cpu,
                           DWORD nBufferLength, LPSTR lpBuffer);
HANDLE GetCurrentProcess(WinApplication* app, x86::CPU& cpu);
DWORD GetCurrentProcessId(WinApplication* app, x86::CPU& cpu);
DWORD GetCurrentThreadId(WinApplication* app, x86::CPU& cpu);
HANDLE GetCurrentThread(WinApplication* app, x86::CPU& cpu);
BOOL GetDiskFreeSpaceA(WinApplication* app, x86::CPU& cpu,
                       LPCSTR lpRootPathName, LPDWORD lpSectorsPerCluster, LPDWORD lpBytesPerSector,
                       LPDWORD lpNumberOfFreeClusters, LPDWORD lpTotalNumberOfClusters);
UINT GetDriveTypeA(WinApplication* app, x86::CPU& cpu,
                   LPCSTR lpRootPathName);
x86::reg32 GetEnvironmentStrings(WinApplication* app, x86::CPU& cpu);
DWORD GetFileAttributesA(WinApplication* app, x86::CPU& cpu,
                         LPCSTR lpFileName);
DWORD GetFileSize(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile, LPDWORD lpFileSizeHigh);
BOOL GetFileTime(WinApplication* app, x86::CPU& cpu,
                 HANDLE hFile, LPFILETIME lpCreationTime, LPFILETIME lpLastAccessTime, LPFILETIME lpLastWriteTime);
DWORD GetFileType(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile);
DWORD GetFullPathNameA(WinApplication* app, x86::CPU& cpu,
                       LPCSTR lpFileName, DWORD nBufferLength, LPSTR lpBuffer, x86::reg32* lpFilePart);
DWORD GetLastError(WinApplication* app, x86::CPU& cpu);
void GetLocalTime(WinApplication* app, x86::CPU& cpu,
                  LPSYSTEMTIME lpSystemTime);
DWORD GetLogicalDriveStringsA(WinApplication* app, x86::CPU& cpu,
                              DWORD nBufferLength, LPSTR lpBuffer);
DWORD GetLogicalDrives(WinApplication* app, x86::CPU& cpu);
DWORD GetModuleFileNameA(WinApplication* app, x86::CPU& cpu,
                         HMODULE hModule, LPSTR lpFilename, DWORD nSize);
DWORD GetModuleFileNameW(WinApplication* app, x86::CPU& cpu,
                         HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
HMODULE GetModuleHandleA(WinApplication* app, x86::CPU& cpu,
                         LPCSTR lpModuleName);
UINT GetOEMCP(WinApplication* app, x86::CPU& cpu);
BOOL GetOverlappedResult(WinApplication* app, x86::CPU& cpu,
                         HANDLE hFile, LPOVERLAPPED lpOverlapped,
                         LPDWORD lpNumberOfBytesTransferred, BOOL bWait);
FARPROC GetProcAddress(WinApplication* app, x86::CPU& cpu,
                       HMODULE hModule, LPCSTR lpProcName);
HANDLE GetStdHandle(WinApplication* app, x86::CPU& cpu,
                    DWORD nStdHandle);
void GetSystemInfo(WinApplication* app, x86::CPU& cpu,
                   LPSYSTEM_INFO lpSystemInfo);
int GetThreadPriority(WinApplication* app, x86::CPU& cpu,
                      HANDLE hThread);
DWORD GetTickCount(WinApplication* app, x86::CPU& cpu);
DWORD GetTimeZoneInformation(WinApplication* app, x86::CPU& cpu,
                             LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
DWORD GetVersion(WinApplication* app, x86::CPU& cpu);
BOOL GetVersionExA(WinApplication* app, x86::CPU& cpu,
                   LPOSVERSIONINFOA lpVersionInformation);
BOOL GetVolumeInformationA(WinApplication* app, x86::CPU& cpu,
                           LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer, DWORD nVolumeNameSize,
                           LPDWORD lpVolumeSerialNumber, LPDWORD lpMaximumComponentLength,
                           LPDWORD lpFileSystemFlags, LPSTR lpFileSystemNameBuffer,
                           DWORD nFileSystemNameSize);
UINT GetWindowsDirectoryA(WinApplication* app, x86::CPU& cpu,
                          LPSTR lpBuffer, UINT uSize);
void GlobalMemoryStatus(WinApplication* app, x86::CPU& cpu,
                        LPMEMORYSTATUS lpBuffer);
void InitializeCriticalSection(WinApplication* app, x86::CPU& cpu,
                               LPCRITICAL_SECTION lpCriticalSection);
void LeaveCriticalSection(WinApplication* app, x86::CPU& cpu,
                          LPCRITICAL_SECTION lpCriticalSection);
HMODULE LoadLibraryA(WinApplication* app, x86::CPU& cpu,
                     LPCSTR lpLibFileName);
x86::reg32 MapViewOfFile(WinApplication* app, x86::CPU& cpu,
                         HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh,
                         DWORD dwFileOffsetLow, SIZE_T dwNumberOfBytesToMap);
BOOL MoveFileA(WinApplication* app, x86::CPU& cpu,
               LPCSTR lpExistingFileName, LPCSTR lpNewFileName);
int MultiByteToWideChar(WinApplication* app, x86::CPU& cpu,
                        UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr,
                        int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
void OutputDebugStringA(WinApplication* app, x86::CPU& cpu,
                        LPCSTR lpOutputString);
BOOL PeekConsoleInputA(WinApplication* app, x86::CPU& cpu,
                       HANDLE hConsoleInput, PINPUT_RECORD lpBuffer,
                       DWORD nLength, LPDWORD lpNumberOfEventsRead);
BOOL PulseEvent(WinApplication* app, x86::CPU& cpu, HANDLE hEvent);
BOOL PurgeComm(WinApplication* app, x86::CPU& cpu,
               HANDLE hFile, DWORD dwFlags);
BOOL ReadConsoleInputA(WinApplication* app, x86::CPU& cpu,
                       HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, DWORD nLength,
                       LPDWORD lpNumberOfEventsRead);
BOOL ReadFile(WinApplication* app, x86::CPU& cpu,
              HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead,
              LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
BOOL RemoveDirectoryA(WinApplication* app, x86::CPU& cpu, LPCSTR lpPathName);
BOOL ResetEvent(WinApplication* app, x86::CPU& cpu, HANDLE hEvent);
DWORD ResumeThread(WinApplication* app, x86::CPU& cpu,
                   HANDLE hThread);
void RtlUnwind(WinApplication* app, x86::CPU& cpu,
               PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue);
BOOL SetCommState(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile, LPDCB lpDCB);
BOOL SetCommTimeouts(WinApplication* app, x86::CPU& cpu,
                     HANDLE hFile, LPCOMMTIMEOUTS lpCommTimeouts);
BOOL SetConsoleCtrlHandler(WinApplication* app, x86::CPU& cpu,
                           PHANDLER_ROUTINE HandlerRoutine, BOOL Add);
BOOL SetConsoleMode(WinApplication* app, x86::CPU& cpu,
                    HANDLE hConsoleHandle, DWORD  dwMode);
BOOL SetCurrentDirectoryA(WinApplication* app, x86::CPU& cpu,
                          LPCSTR lpPathName);
BOOL SetEndOfFile(WinApplication* app, x86::CPU& cpu,
                  HANDLE hFile);
BOOL SetEnvironmentVariableA(WinApplication* app, x86::CPU& cpu,
                             LPCSTR lpName, LPCSTR lpValue);
BOOL SetEnvironmentVariableW(WinApplication* app, x86::CPU& cpu,
                             LPCWSTR lpName, LPCWSTR lpValue);
BOOL SetEvent(WinApplication* app, x86::CPU& cpu,
              HANDLE hEvent);
UINT SetErrorMode(WinApplication* app, x86::CPU& cpu, UINT uMode);
BOOL SetFileAttributesA(WinApplication* app, x86::CPU& cpu,
                        LPCSTR lpFileName, DWORD  dwFileAttributes);
DWORD SetFilePointer(WinApplication* app, x86::CPU& cpu,
                     HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
void SetLastError(WinApplication* app, x86::CPU& cpu,
                  DWORD dwErrCode);
BOOL SetStdHandle(WinApplication* app, x86::CPU& cpu,
                  DWORD nStdHandle, HANDLE hHandle);
BOOL SetThreadPriority(WinApplication* app, x86::CPU& cpu,
                       HANDLE hThread, int nPriority);
LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(WinApplication* app, x86::CPU& cpu,
                                                         LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
DWORD SleepEx(WinApplication* app, x86::CPU& cpu,
              DWORD dwMilliseconds, BOOL bAlertable);
BOOL TerminateThread(WinApplication* app, x86::CPU& cpu,
                     HANDLE hThread, DWORD dwExitCode);
DWORD TlsAlloc(WinApplication* app, x86::CPU& cpu);
BOOL TlsFree(WinApplication* app, x86::CPU& cpu,
             DWORD dwTlsIndex);
x86::reg32 TlsGetValue(WinApplication* app, x86::CPU& cpu,
                       DWORD dwTlsIndex);
BOOL TlsSetValue(WinApplication* app, x86::CPU& cpu,
                 DWORD dwTlsIndex, LPVOID lpTlsValue);
LONG UnhandledExceptionFilter(WinApplication* app, x86::CPU& cpu,
                              struct _EXCEPTION_POINTERS *ExceptionInfo);
BOOL UnmapViewOfFile(WinApplication* app, x86::CPU& cpu,
                     Packed<const void> lpBaseAddress);
x86::reg32 VirtualAlloc(WinApplication* app, x86::CPU& cpu,
                        LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
BOOL VirtualFree(WinApplication* app, x86::CPU& cpu,
                 Packed<void> lpAddress, SIZE_T dwSize, DWORD dwFreeType);
BOOL VirtualProtect(WinApplication* app, x86::CPU& cpu,
                    Packed<void> lpAddress, SIZE_T dwSize, DWORD flNewProtect, DWORD* lpflOldProtect);
SIZE_T VirtualQuery(WinApplication* app, x86::CPU& cpu,
                    Packed<const void> lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength);
DWORD WaitForMultipleObjectsEx(WinApplication* app, x86::CPU& cpu,
                               DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll,
                               DWORD dwMilliseconds, BOOL bAlertable);
DWORD WaitForSingleObject(WinApplication* app, x86::CPU& cpu,
                          HANDLE hHandle, DWORD dwMilliseconds);
int WideCharToMultiByte(WinApplication* app, x86::CPU& cpu,
                        UINT CodePage, DWORD dwFlags, LPCWCH lpWideCharStr, int cchWideChar,
                        LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar);
BOOL WriteConsoleA(WinApplication* app, x86::CPU& cpu,
                   HANDLE hConsoleOutput, const void* lpBuffer, DWORD nNumberOfCharsToWrite,
                   LPDWORD lpNumberOfCharsWritten, LPVOID  lpReserved);
BOOL WriteFile(WinApplication* app, x86::CPU& cpu,
               HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite,
               LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
HFILE _lclose(WinApplication* app, x86::CPU& cpu, HFILE hFile);
HFILE _lopen(WinApplication* app, x86::CPU& cpu, LPCSTR lpPathName, int iReadWrite);

}}

#endif
