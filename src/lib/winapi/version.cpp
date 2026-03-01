#include <winapi/version.h>
#include <x86.h>

namespace win32 { namespace version
{

BOOL GetFileVersionInfoA(WinApplication* app, x86::CPU& cpu, LPCSTR lptstrFilename,
                         DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lptstrFilename);
    NFS2_USE(dwHandle);
    NFS2_USE(dwLen);
    *reinterpret_cast<x86::reg32*>(lpData) = 0x02000000;
    return 1;
}

DWORD GetFileVersionInfoSizeA(WinApplication* app, x86::CPU& cpu,
                              LPCSTR lptstrFilename, LPDWORD lpdwHandle)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lptstrFilename);
    *lpdwHandle = 0;
    return 4;
}

BOOL VerQueryValueA(WinApplication* app, x86::CPU& cpu,
                    Packed<void> pBlock, LPCSTR lpSubBlock, Packed<void>* lplpBuffer, UINT* puLen)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpSubBlock);
    NFS2_USE(puLen);
    *lplpBuffer = pBlock;
    return 1;
}
}}
