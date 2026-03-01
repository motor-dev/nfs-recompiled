#include <winapi/shell32.h>
#include <x86.h>

namespace win32 { namespace shell32
{



HINSTANCE ShellExecuteA(WinApplication* app, x86::CPU& cpu, HWND hwnd, LPCSTR lpOperation,
                        LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, int nShowCmd)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hwnd);
    NFS2_USE(lpOperation);
    NFS2_USE(lpFile);
    NFS2_USE(lpParameters);
    NFS2_USE(lpDirectory);
    NFS2_USE(nShowCmd);
    NFS2_ASSERT(false);
    return -1;
}

}}
