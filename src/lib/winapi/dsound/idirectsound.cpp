#include <winapi/dsound/idirectsound.h>
#include <winapi/dsound/idirectsoundbuffer.h>
#include <winapi/wrapper.h>
#include <lib/audio.h>


namespace win32 { namespace dsound
{

x86::reg32 IDirectSound::s_iDirectSoundVtable = 0;

struct DSCAPS
{
    DWORD  dwSize;
    DWORD  dwFlags;
    DWORD  dwMinSecondarySampleRate;
    DWORD  dwMaxSecondarySampleRate;
    DWORD  dwPrimaryBuffers;
    DWORD  dwMaxHwMixingAllBuffers;
    DWORD  dwMaxHwMixingStaticBuffers;
    DWORD  dwMaxHwMixingStreamingBuffers;
    DWORD  dwFreeHwMixingAllBuffers;
    DWORD  dwFreeHwMixingStaticBuffers;
    DWORD  dwFreeHwMixingStreamingBuffers;
    DWORD  dwMaxHw3DAllBuffers;
    DWORD  dwMaxHw3DStaticBuffers;
    DWORD  dwMaxHw3DStreamingBuffers;
    DWORD  dwFreeHw3DAllBuffers;
    DWORD  dwFreeHw3DStaticBuffers;
    DWORD  dwFreeHw3DStreamingBuffers;
    DWORD  dwTotalHwMemBytes;
    DWORD  dwFreeHwMemBytes;
    DWORD  dwMaxContigFreeHwMemBytes;
    DWORD  dwUnlockTransferRateHwBuffers;
    DWORD  dwPlayCpuOverheadSwBuffers;
    DWORD  dwReserved1;
    DWORD  dwReserved2;
};

enum DirectSoundCaps
{
    DSCAPS_PRIMARYMONO        = 0x00000001,
    DSCAPS_PRIMARYSTEREO      = 0x00000002,
    DSCAPS_PRIMARY8BIT        = 0x00000004,
    DSCAPS_PRIMARY16BIT       = 0x00000008,
    DSCAPS_CONTINUOUSRATE     = 0x00000010,
    DSCAPS_EMULDRIVER         = 0x00000020,
    DSCAPS_CERTIFIED          = 0x00000040,
    DSCAPS_SECONDARYMONO      = 0x00000100,
    DSCAPS_SECONDARYSTEREO    = 0x00000200,
    DSCAPS_SECONDARY8BIT      = 0x00000400,
    DSCAPS_SECONDARY16BIT     = 0x00000800
};

static x86::reg32 s_primaryBuffer = 0;

DEFINE_GUID(IID_IDirectSound,           0x279AFA83,0x4981,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60);

IDirectSound::IDirectSound()
    :   IUnknown(IID_IDirectSound)
{
    m_vtable = s_iDirectSoundVtable;
}

HRESULT IDirectSound::CreateSoundBuffer(WinApplication* app, x86::CPU& cpu,
                                       LPCDSBUFFERDESC lpcDSBufferDesc, LPLPDIRECTSOUNDBUFFER lplpDirectSoundBuffer, IUnknown *pUnkOuter)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(pUnkOuter == nullptr);
    if (lpcDSBufferDesc->dwFlags & 1)
    {
        if (!s_primaryBuffer)
        {
            s_primaryBuffer = Packed<IDirectSoundBuffer>(com::ComAlloc(app));
            IDirectSoundBuffer* buffer = &app->getMemory<IDirectSoundBuffer>(s_primaryBuffer);
            new (buffer) IDirectSoundBuffer(app, cpu, this, lpcDSBufferDesc);
        }
        else
        {
            (&app->getMemory<IDirectSoundBuffer>(s_primaryBuffer))->AddRef(app, cpu);
        }
        *lplpDirectSoundBuffer = Packed<IDirectSoundBuffer>(s_primaryBuffer);
    }
    else
    {
        *lplpDirectSoundBuffer = Packed<IDirectSoundBuffer>(com::ComAlloc(app));
        IDirectSoundBuffer* buffer = &app->getMemory<IDirectSoundBuffer>(*lplpDirectSoundBuffer);
        new (buffer) IDirectSoundBuffer(app, cpu, this, lpcDSBufferDesc);
    }
    return 0;
}

HRESULT IDirectSound::GetCaps(WinApplication* app, x86::CPU& cpu,
                              LPDSCAPS lpDSCaps)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(lpDSCaps->dwSize == sizeof(DSCAPS));
    lpDSCaps->dwFlags = DSCAPS_PRIMARYSTEREO | DSCAPS_SECONDARYSTEREO | DSCAPS_PRIMARY16BIT | DSCAPS_SECONDARY16BIT | DSCAPS_CERTIFIED;
    lpDSCaps->dwMinSecondarySampleRate = 22050;
    lpDSCaps->dwMaxSecondarySampleRate = 44100;
    lpDSCaps->dwPrimaryBuffers = 1;
    lpDSCaps->dwMaxHwMixingAllBuffers = 65535;
    lpDSCaps->dwMaxHwMixingStaticBuffers = 65535;
    lpDSCaps->dwMaxHwMixingStreamingBuffers = 65535;
    lpDSCaps->dwFreeHwMixingAllBuffers = 65535;
    lpDSCaps->dwFreeHwMixingStaticBuffers = 65535;
    lpDSCaps->dwFreeHwMixingStreamingBuffers = 65535;
    lpDSCaps->dwMaxHw3DAllBuffers = 0;
    lpDSCaps->dwMaxHw3DStaticBuffers = 0;
    lpDSCaps->dwMaxHw3DStreamingBuffers = 0;
    lpDSCaps->dwFreeHw3DAllBuffers = 0;
    lpDSCaps->dwFreeHw3DStaticBuffers = 0;
    lpDSCaps->dwFreeHw3DStreamingBuffers = 0;
    lpDSCaps->dwTotalHwMemBytes = 1024*1024;
    lpDSCaps->dwFreeHwMemBytes = 1024*1024;
    lpDSCaps->dwMaxContigFreeHwMemBytes = 0;
    lpDSCaps->dwUnlockTransferRateHwBuffers = 0;
    lpDSCaps->dwPlayCpuOverheadSwBuffers = 0;
    lpDSCaps->dwReserved1 = 0;
    lpDSCaps->dwReserved2 = 0;
    return 0;
}

HRESULT IDirectSound::DuplicateSoundBuffer(WinApplication* app, x86::CPU& cpu,
                                           LPDIRECTSOUNDBUFFER lpDsbOriginal, LPLPDIRECTSOUNDBUFFER lplpDsbDuplicate)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpDsbOriginal);
    NFS2_USE(lplpDsbDuplicate);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound::SetCooperativeLevel(WinApplication* app, x86::CPU& cpu,
                                          HWND hwnd, DWORD dwLevel)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hwnd);
    NFS2_USE(dwLevel);
    m_resource = new AudioDevice();
    app->allocateResource(m_resource);
    return 0;
}

HRESULT IDirectSound::Compact(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound::GetSpeakerConfig(WinApplication* app, x86::CPU& cpu,
                                       LPDWORD lpdwSpeakerConfig)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpdwSpeakerConfig);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound::SetSpeakerConfig(WinApplication* app, x86::CPU& cpu,
                                       DWORD dwSpeakerConfig)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwSpeakerConfig);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound::Initialize(WinApplication* app, x86::CPU& cpu,
                                 const GUID* lpcGuid)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpcGuid);
    NFS2_ASSERT(false);
    return 1;
}

x86::reg32 IDirectSound::init(WinApplication *app, x86::reg32 memblockIndex, x86::reg8* memBlock)
{
    x86::reg32* vtable = reinterpret_cast<x86::reg32*>(memBlock);
    app->registerMethod(0x400060, {"CreateSoundBuffer", &Wrapper<decltype(&IDirectSound::CreateSoundBuffer), &IDirectSound::CreateSoundBuffer>::stdcall});
    app->registerMethod(0x400061, {"GetCaps", &Wrapper<decltype(&IDirectSound::GetCaps), &IDirectSound::GetCaps>::stdcall});
    app->registerMethod(0x400062, {"DuplicateSoundBuffer", &Wrapper<decltype(&IDirectSound::DuplicateSoundBuffer), &IDirectSound::DuplicateSoundBuffer>::stdcall});
    app->registerMethod(0x400063, {"SetCooperativeLevel", &Wrapper<decltype(&IDirectSound::SetCooperativeLevel), &IDirectSound::SetCooperativeLevel>::stdcall});
    app->registerMethod(0x400064, {"Compact", &Wrapper<decltype(&IDirectSound::Compact), &IDirectSound::Compact>::stdcall});
    app->registerMethod(0x400065, {"GetSpeakerConfig", &Wrapper<decltype(&IDirectSound::GetSpeakerConfig), &IDirectSound::GetSpeakerConfig>::stdcall});
    app->registerMethod(0x400066, {"SetSpeakerConfig", &Wrapper<decltype(&IDirectSound::SetSpeakerConfig), &IDirectSound::SetSpeakerConfig>::stdcall});
    app->registerMethod(0x400067, {"Initialize", &Wrapper<decltype(&IDirectSound::Initialize), &IDirectSound::Initialize>::stdcall});

    s_iDirectSoundVtable = memblockIndex;
    vtable[0] = 0x400000;    // IUnknown_QueryInterface
    vtable[1] = 0x400001;    // IUnknown_AddRef
    vtable[2] = 0x400002;    // IUnknwon_Release
    vtable[3] = 0x400060;    // IDirectSound_CreateSoundBuffer
    vtable[4] = 0x400061;    // IDirectSound_GetCaps
    vtable[5] = 0x400062;    // IDirectSound_DuplicateSoundBuffer
    vtable[6] = 0x400063;    // IDirectSound_SetCooperativeLevel
    vtable[7] = 0x400064;    // IDirectSound_Compact
    vtable[8] = 0x400065;    // IDirectSound_GetSpeakerConfig
    vtable[9] = 0x400066;    // IDirectSound_SetSpeakerConfig
    vtable[10] = 0x400067;   // IDirectSound_FindDevice
    return 11 * sizeof(x86::reg32);
}

}}
