#include <winapi/gdi32.h>
#include <x86.h>

namespace win32 { namespace gdi32
{

int GetDeviceCaps(WinApplication* app, x86::CPU& cpu, HDC hdc, int index)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hdc);
    NFS2_USE(index);
    NFS2_ASSERT(false);
    return -1;
}

HGDIOBJ GetStockObject(WinApplication* app, x86::CPU& cpu, int i)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(i);
    return 0xffffffff;
}

}}
