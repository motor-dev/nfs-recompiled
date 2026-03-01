#include <winapi/dsetup.h>
#include <lib/library.h>
#include <winapi/types.h>
#include <winapi/wrapper.h>

namespace win32 { namespace dsetup
{

int DirectXSetupGetVersion(WinApplication* app, x86::CPU& cpu,
                           DWORD *pdwVersion, DWORD *pdwRevision)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (pdwVersion) *pdwVersion = 0x00040007;
    if (pdwRevision) *pdwRevision = 0x00000000;
    return 1;
}

Library s_dsetupLibrary = win32::Library("dsetup.dll");
Library* s_dSetupRegistry = &(s_dsetupLibrary
    .registerSymbol("DirectXSetupGetVersion", &Wrapper<decltype(&DirectXSetupGetVersion), &DirectXSetupGetVersion>::stdcall));


}}
