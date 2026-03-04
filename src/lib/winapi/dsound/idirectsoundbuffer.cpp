#include <winapi/dsound/idirectsoundbuffer.h>
#include <winapi/dsound/idirectsound3dlistener.h>
#include <winapi/dsound/idirectsound.h>
#include <winapi/wrapper.h>
#include <lib/audio.h>
#include <lib/thread.h>


namespace win32 { namespace dsound
{

x86::reg32 IDirectSoundBuffer::s_iDirectSoundBufferVtable = 0;

struct WAVEFORMATEX
{
    WORD  wFormatTag;
    WORD  nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD  nBlockAlign;
    WORD  wBitsPerSample;
    WORD  cbSize;
};

struct IDirectSoundBuffer::DSBCAPS
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwBufferBytes;
    DWORD dwUnlockTransferRate;
    DWORD dwPlayCpuOverhead;
};

enum DirectSoundBufferFlags
{
    DSBCAPS_PRIMARYBUFFER         = 0x00000001,
    DSBCAPS_STATIC                = 0x00000002,
    DSBCAPS_LOCHARDWARE           = 0x00000004,
    DSBCAPS_LOCSOFTWARE           = 0x00000008,
    DSBCAPS_CTRL3D                = 0x00000010,
    DSBCAPS_CTRLFREQUENCY         = 0x00000020,
    DSBCAPS_CTRLPAN               = 0x00000040,
    DSBCAPS_CTRLVOLUME            = 0x00000080,
    DSBCAPS_CTRLDEFAULT           = 0x000000E0,  /* Pan + volume + frequency. */
    DSBCAPS_CTRLPOSITIONNOTIFY    = 0x00000100,
    DSBCAPS_CTRLFX                = 0x00000200,
    DSBCAPS_CTRLALL               = 0x000001F0,  /* All control capabilities */
    DSBCAPS_STICKYFOCUS           = 0x00004000,
    DSBCAPS_GLOBALFOCUS           = 0x00008000,
    DSBCAPS_GETCURRENTPOSITION2   = 0x00010000,  /* More accurate play cursor under emulation*/
    DSBCAPS_MUTE3DATMAXDISTANCE   = 0x00020000,
    DSBCAPS_LOCDEFER              = 0x00040000
};

enum DirectSoundBufferStatus
{
    DSBSTATUS_PLAYING         = 0x00000001,
    DSBSTATUS_BUFFERLOST      = 0x00000002,
    DSBSTATUS_LOOPING         = 0x00000004
};

DEFINE_GUID(IID_IDirectSoundBuffer,	0x279AFA85,0x4981,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60);
DEFINE_GUID(IID_IDirectSound3DListener, 0x279AFA84,0x4981,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60);


IDirectSoundBuffer::IDirectSoundBuffer(WinApplication* app, x86::CPU& cpu, LPDIRECTSOUND lpDirectSound, LPCDSBUFFERDESC lpcDSBufferDesc)
    :   IUnknown(IID_IDirectSoundBuffer)
{
    NFS2_ASSERT(lpcDSBufferDesc->dwSize == sizeof(DSBUFFERDESC));
    m_vtable = s_iDirectSoundBufferVtable;
    Initialize(app, cpu, lpDirectSound, lpcDSBufferDesc);
}

BOOL IDirectSoundBuffer::QueryInterface(WinApplication* app, x86::CPU& cpu,
                                        REFGUID refiid, x86::reg32* pvvObject)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(refiid);
    if (*refiid == IID_IDirectSoundBuffer)
    {
        *pvvObject = ComGetIndex(app, this);
        m_refCount ++;
        return 0;
    }
    else if (*refiid == IID_IDirectSound3DListener)
    {
        *pvvObject = com::ComAlloc(app);
        new (&app->getMemory<void>(*pvvObject)) IDirectSound3DListener(this);
        return 0;
    }
    else
    {
        *pvvObject = 0;
        //m_refCount ++;
        return 0x80004002;
    }
}

HRESULT IDirectSoundBuffer::GetCaps(WinApplication* app, x86::CPU& cpu, LPDSBCAPS lpDSBufferCaps)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(lpDSBufferCaps->dwSize == sizeof(DSBCAPS));
    lpDSBufferCaps->dwFlags = DSBCAPS_GETCURRENTPOSITION2|DSBCAPS_CTRLALL;
    if (dynamic_cast<AudioBuffer*>(m_resource)->primary())
        lpDSBufferCaps->dwFlags |= DSBCAPS_LOCHARDWARE;
    else
        lpDSBufferCaps->dwFlags |= DSBCAPS_LOCSOFTWARE;
    lpDSBufferCaps->dwBufferBytes = dynamic_cast<AudioBuffer*>(m_resource)->bufferSize();
    lpDSBufferCaps->dwUnlockTransferRate = 0;
    lpDSBufferCaps->dwPlayCpuOverhead = 0;
    return 0;
}

HRESULT IDirectSoundBuffer::GetCurrentPosition(WinApplication* app, x86::CPU& cpu, LPDWORD lpdwCurrentPlayCursor, LPDWORD lpdwCurrentWriteCursor)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (lpdwCurrentPlayCursor)
        *lpdwCurrentPlayCursor = dynamic_cast<AudioBuffer*>(m_resource)->playStart() % dynamic_cast<AudioBuffer*>(m_resource)->bufferSize();
    if (lpdwCurrentWriteCursor)
        *lpdwCurrentWriteCursor = dynamic_cast<AudioBuffer*>(m_resource)->playStart() % dynamic_cast<AudioBuffer*>(m_resource)->bufferSize();
    return 0;
}

HRESULT IDirectSoundBuffer::GetFormat(WinApplication* app, x86::CPU& cpu, LPWAVEFORMATEX lpwfxFormat, DWORD dwSizeAllocated, LPDWORD lpdwSizeWritten)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpdwSizeWritten);
    NFS2_USE(dwSizeAllocated);
    NFS2_USE(lpwfxFormat);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSoundBuffer::GetVolume(WinApplication* app, x86::CPU& cpu, LPLONG lplVolume)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lplVolume);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSoundBuffer::GetPan(WinApplication* app, x86::CPU& cpu, LPLONG lplpan)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lplpan);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSoundBuffer::GetFrequency(WinApplication* app, x86::CPU& cpu, LPDWORD lpdwFrequency)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpdwFrequency);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSoundBuffer::GetStatus(WinApplication* app, x86::CPU& cpu, LPDWORD lpdwStatus)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    if (dynamic_cast<AudioBuffer*>(m_resource)->playStart() < dynamic_cast<AudioBuffer*>(m_resource)->playStop())
        *lpdwStatus = DSBSTATUS_PLAYING;
    else
        *lpdwStatus = 0;
    return 0;
}

HRESULT IDirectSoundBuffer::Initialize(WinApplication* app, x86::CPU& cpu, LPDIRECTSOUND lpDirectSound, LPCDSBUFFERDESC lpcDSBufferDesc)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpDirectSound);
    NFS2_USE(lpcDSBufferDesc);
    m_resource = new AudioBuffer(dynamic_cast<AudioDevice*>(lpDirectSound->m_resource), app, lpcDSBufferDesc->dwBufferBytes);
    app->allocateResource(m_resource);
    return 0;
}

HRESULT IDirectSoundBuffer::Lock(WinApplication* app, x86::CPU& cpu, DWORD dwOffset, DWORD dwBytes,
                                 Packed<void>* ppvAudioPtr1, LPDWORD pdwAudioBytes1, Packed<void>* ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(dwFlags == 0);
    AudioBuffer* buffer = dynamic_cast<AudioBuffer*>(m_resource);
    x86::reg32 bufferSize = buffer->bufferSize();
    NFS2_ASSERT(dwBytes <= bufferSize);
    /**ppvAudioPtr1 = Packed<void>(buffer->getBackBuffer());
    *pdwAudioBytes1 = dwBytes;*/
    x86::reg32 start = dwOffset;
    x86::reg32 stop = dwOffset + dwBytes;
    if (dwBytes == bufferSize)
    {
        NFS2_ASSERT(dwOffset == 0);
    }
    x86::reg32 mem = buffer->lock();
    *ppvAudioPtr1 = Packed<void>(mem + start);
    if (stop <= bufferSize)
    {
        *pdwAudioBytes1 = stop - start;
        if (ppvAudioPtr2)
        {
            *ppvAudioPtr2 = Packed<void>();
            *pdwAudioBytes2 = 0;
        }
    }
    else
    {
        *pdwAudioBytes1 = bufferSize - start;
        if (ppvAudioPtr2)
        {
            *ppvAudioPtr2 = Packed<void>(mem);
            *pdwAudioBytes2 = stop - bufferSize;
        }
    }
    return 0;
}

HRESULT IDirectSoundBuffer::Play(WinApplication* app, x86::CPU& cpu, DWORD dwReserved1, DWORD dwReserved2, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwReserved1);
    NFS2_USE(dwReserved2);
    NFS2_USE(dwFlags);
    dynamic_cast<AudioBuffer*>(m_resource)->play();
    return 0;
}

HRESULT IDirectSoundBuffer::SetCurrentPosition(WinApplication* app, x86::CPU& cpu, DWORD dwNewPosition)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwNewPosition);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSoundBuffer::SetFormat(WinApplication* app, x86::CPU& cpu, LPCWAVEFORMATEX lpcfxFormat)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpcfxFormat);
    return 0;
}

HRESULT IDirectSoundBuffer::SetVolume(WinApplication* app, x86::CPU& cpu, LONG lVolume)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lVolume);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSoundBuffer::SetPan(WinApplication* app, x86::CPU& cpu, LONG lPan)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lPan);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSoundBuffer::SetFrequency(WinApplication* app, x86::CPU& cpu, DWORD dwFrequency)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwFrequency);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSoundBuffer::Stop(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    dynamic_cast<AudioBuffer*>(m_resource)->stop();
    return 0;
}

HRESULT IDirectSoundBuffer::Unlock(WinApplication* app, x86::CPU& cpu, Packed<void> pvAudioPtr1, DWORD dwAudioBytes1, Packed<void> pvAudioPtr2, DWORD dwAudioBytes2)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(pvAudioPtr1);
    NFS2_USE(pvAudioPtr2);
    AudioBuffer* buffer = dynamic_cast<AudioBuffer*>(m_resource);
    //NFS2_ASSERT(pvAudioPtr1 - buffer->lock() == buffer->playStop() % buffer->bufferSize());
    buffer->unlock(dwAudioBytes1 + dwAudioBytes2);
    return 0;
}

HRESULT IDirectSoundBuffer::Restore(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
    return 1;
}

x86::reg32 IDirectSoundBuffer::init(WinApplication *app, x86::reg32 memblockIndex, x86::reg8* memBlock)
{
    x86::reg32* vtable = reinterpret_cast<x86::reg32*>(memBlock);
    app->registerMethod(0x400068, {"IDirectSoundBuffer::QueryInterface", &Wrapper<decltype(&IDirectSoundBuffer::QueryInterface), &IDirectSoundBuffer::QueryInterface>::stdcall});
    app->registerMethod(0x400069, {"IDirectSoundBuffer::GetCaps", &Wrapper<decltype(&IDirectSoundBuffer::GetCaps), &IDirectSoundBuffer::GetCaps>::stdcall});
    app->registerMethod(0x40006a, {"IDirectSoundBuffer::GetCurrentPosition", &Wrapper<decltype(&IDirectSoundBuffer::GetCurrentPosition), &IDirectSoundBuffer::GetCurrentPosition>::stdcall});
    app->registerMethod(0x40006b, {"IDirectSoundBuffer::GetFormat", &Wrapper<decltype(&IDirectSoundBuffer::GetFormat), &IDirectSoundBuffer::GetFormat>::stdcall});
    app->registerMethod(0x40006c, {"IDirectSoundBuffer::GetVolume", &Wrapper<decltype(&IDirectSoundBuffer::GetVolume), &IDirectSoundBuffer::GetVolume>::stdcall});
    app->registerMethod(0x40006d, {"IDirectSoundBuffer::GetPan", &Wrapper<decltype(&IDirectSoundBuffer::GetPan), &IDirectSoundBuffer::GetPan>::stdcall});
    app->registerMethod(0x40006e, {"IDirectSoundBuffer::GetFrequency", &Wrapper<decltype(&IDirectSoundBuffer::GetFrequency), &IDirectSoundBuffer::GetFrequency>::stdcall});
    app->registerMethod(0x40006f, {"IDirectSoundBuffer::GetStatus", &Wrapper<decltype(&IDirectSoundBuffer::GetStatus), &IDirectSoundBuffer::GetStatus>::stdcall});
    app->registerMethod(0x400070, {"IDirectSoundBuffer::Initialize", &Wrapper<decltype(&IDirectSoundBuffer::Initialize), &IDirectSoundBuffer::Initialize>::stdcall});
    app->registerMethod(0x400071, {"IDirectSoundBuffer::Lock", &Wrapper<decltype(&IDirectSoundBuffer::Lock), &IDirectSoundBuffer::Lock>::stdcall});
    app->registerMethod(0x400072, {"IDirectSoundBuffer::Play", &Wrapper<decltype(&IDirectSoundBuffer::Play), &IDirectSoundBuffer::Play>::stdcall});
    app->registerMethod(0x400073, {"IDirectSoundBuffer::SetCurrentPosition", &Wrapper<decltype(&IDirectSoundBuffer::SetCurrentPosition), &IDirectSoundBuffer::SetCurrentPosition>::stdcall});
    app->registerMethod(0x400074, {"IDirectSoundBuffer::SetFormat", &Wrapper<decltype(&IDirectSoundBuffer::SetFormat), &IDirectSoundBuffer::SetFormat>::stdcall});
    app->registerMethod(0x400075, {"IDirectSoundBuffer::SetVolume", &Wrapper<decltype(&IDirectSoundBuffer::SetVolume), &IDirectSoundBuffer::SetVolume>::stdcall});
    app->registerMethod(0x400076, {"IDirectSoundBuffer::SetPan", &Wrapper<decltype(&IDirectSoundBuffer::SetPan), &IDirectSoundBuffer::SetPan>::stdcall});
    app->registerMethod(0x400077, {"IDirectSoundBuffer::SetFrequency", &Wrapper<decltype(&IDirectSoundBuffer::SetFrequency), &IDirectSoundBuffer::SetFrequency>::stdcall});
    app->registerMethod(0x400078, {"IDirectSoundBuffer::Stop", &Wrapper<decltype(&IDirectSoundBuffer::Stop), &IDirectSoundBuffer::Stop>::stdcall});
    app->registerMethod(0x400079, {"IDirectSoundBuffer::Unlock", &Wrapper<decltype(&IDirectSoundBuffer::Unlock), &IDirectSoundBuffer::Unlock>::stdcall});
    app->registerMethod(0x40007a, {"IDirectSoundBuffer::Restore", &Wrapper<decltype(&IDirectSoundBuffer::Restore), &IDirectSoundBuffer::Restore>::stdcall});

    s_iDirectSoundBufferVtable = memblockIndex;
    vtable[0] = 0x400068;    // IDirectSoundBuffer_QueryInterface
    vtable[1] = 0x400001;    // IUnknown_AddRef
    vtable[2] = 0x400002;    // IUnknown_Release
    vtable[3] = 0x400069;    // IDirectSoundBuffer_GetCaps
    vtable[4] = 0x40006a;    // IDirectSoundBuffer_GetCurrentPosition
    vtable[5] = 0x40006b;    // IDirectSoundBuffer_GetFormat
    vtable[6] = 0x40006c;    // IDirectSoundBuffer_GetVolume
    vtable[7] = 0x40006d;    // IDirectSoundBuffer_GetPan
    vtable[8] = 0x40006e;    // IDirectSoundBuffer_GetFrequency
    vtable[9] = 0x40006f;    // IDirectSoundBuffer_GetStatus
    vtable[10] = 0x400070;   // IDirectSoundBuffer_Initialize
    vtable[11] = 0x400071;   // IDirectSoundBuffer_Lock
    vtable[12] = 0x400072;   // IDirectSoundBuffer_Play
    vtable[13] = 0x400073;   // IDirectSoundBuffer_SetCurrentPosition
    vtable[14] = 0x400074;   // IDirectSoundBuffer_SetFormat
    vtable[15] = 0x400075;   // IDirectSoundBuffer_SetVolume
    vtable[16] = 0x400076;   // IDirectSoundBuffer_SetPan
    vtable[17] = 0x400077;   // IDirectSoundBuffer_SetFrequency
    vtable[18] = 0x400078;   // IDirectSoundBuffer_Stop
    vtable[19] = 0x400079;   // IDirectSoundBuffer_Unlock
    vtable[20] = 0x40007a;   // IDirectSoundBuffer_Restore
    return 21 * sizeof(x86::reg32);
}

}}
