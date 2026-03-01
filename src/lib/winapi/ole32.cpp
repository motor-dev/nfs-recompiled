#include <winapi/ole32.h>
#include <x86.h>

namespace win32 { namespace ole32
{

HRESULT CoCreateGuid(WinApplication* app, x86::CPU& cpu, GUID *pguid)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(pguid);
    NFS2_ASSERT(false);
    return -1;
}

}}
