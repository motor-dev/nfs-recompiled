#include <winapi/dsound.h>
#include <winapi/com.h>
#include <winapi/dsound/idirectsound.h>
#include <x86.h>

namespace win32 { namespace dsound
{

HRESULT DirectSoundCreate(WinApplication* app, x86::CPU& cpu,
                          GUID* lpGuid, Packed<IDirectSound>* ppDS, LPVOID punkOuter)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpGuid);
    NFS2_ASSERT(punkOuter == nullptr);
    *ppDS = Packed<IDirectSound>(com::ComAlloc(app));
    IDirectSound* dsound = app->getMemory<IDirectSound>(*ppDS);
    new (dsound) IDirectSound();
    return 0;
}

}}
