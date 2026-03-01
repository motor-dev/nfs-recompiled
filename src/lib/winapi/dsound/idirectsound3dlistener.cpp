#include <winapi/dsound/idirectsound3dlistener.h>
#include <winapi/dsound/idirectsoundbuffer.h>
#include <winapi/wrapper.h>
#include <lib/audio.h>


namespace win32 { namespace dsound
{

x86::reg32 IDirectSound3DListener::s_iDirectSound3DListenerVtable = 0;

DEFINE_GUID(IID_IDirectSound3DListener, 0x279AFA84,0x4981,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60);

IDirectSound3DListener::IDirectSound3DListener(IDirectSoundBuffer* owner)
    :   IUnknown(IID_IDirectSound3DListener)
{
    NFS2_USE(owner);
    m_vtable = s_iDirectSound3DListenerVtable;
}

HRESULT IDirectSound3DListener::GetAllParameters(WinApplication* app, x86::CPU& cpu, LPDS3DLISTENER lpListener)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpListener);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::GetDistanceFactor(WinApplication* app, x86::CPU& cpu, LPD3DVALUE lpflDistanceFactor)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpflDistanceFactor);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::GetDopplerFactor(WinApplication* app, x86::CPU& cpu, LPD3DVALUE lpflDopplerFactor)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpflDopplerFactor);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::GetOrientation(WinApplication* app, x86::CPU& cpu, LPD3DVECTOR lpvOrientFront, LPD3DVECTOR lpvOrientTop)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpvOrientFront);
    NFS2_USE(lpvOrientTop);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::GetPosition(WinApplication* app, x86::CPU& cpu, LPD3DVECTOR lpvPosition)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpvPosition);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::GetRolloffFactor(WinApplication* app, x86::CPU& cpu, LPD3DVALUE lpflRolloffFactor)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpflRolloffFactor);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::GetVelocity(WinApplication* app, x86::CPU& cpu, LPD3DVECTOR lpvVelocity)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpvVelocity);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::SetAllParameters(WinApplication* app, x86::CPU& cpu, LPCDS3DLISTENER lpcListener, DWORD dwApply)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpcListener);
    NFS2_USE(dwApply);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::SetDistanceFactor(WinApplication* app, x86::CPU& cpu, D3DVALUE flDistanceFactor, DWORD dwApply)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(flDistanceFactor);
    NFS2_USE(dwApply);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::SetDopplerFactor(WinApplication* app, x86::CPU& cpu, D3DVALUE flDopplerFactor, DWORD dwApply)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(flDopplerFactor);
    NFS2_USE(dwApply);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::SetOrientation(WinApplication* app, x86::CPU& cpu, D3DVALUE xFront, D3DVALUE yFront, D3DVALUE zFront, D3DVALUE xTop, D3DVALUE yTop, D3DVALUE zTop, DWORD dwApply)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(xFront);
    NFS2_USE(yFront);
    NFS2_USE(zFront);
    NFS2_USE(xTop);
    NFS2_USE(yTop);
    NFS2_USE(zTop);
    NFS2_USE(dwApply);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::SetPosition(WinApplication* app, x86::CPU& cpu, D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(x);
    NFS2_USE(y);
    NFS2_USE(z);
    NFS2_USE(dwApply);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::SetRolloffFactor(WinApplication* app, x86::CPU& cpu, D3DVALUE flRolloffFactor, DWORD dwApply)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(flRolloffFactor);
    NFS2_USE(dwApply);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::SetVelocity(WinApplication* app, x86::CPU& cpu, D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(x);
    NFS2_USE(y);
    NFS2_USE(z);
    NFS2_USE(dwApply);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectSound3DListener::CommitDeferredSettings(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
    return 1;
}


x86::reg32 IDirectSound3DListener::init(WinApplication *app, x86::reg32 memblockIndex, x86::reg8* memBlock)
{
    x86::reg32* vtable = reinterpret_cast<x86::reg32*>(memBlock);
    app->registerMethod(0x40007b, {"GetAllParameters", &Wrapper<decltype(&IDirectSound3DListener::GetAllParameters), &IDirectSound3DListener::GetAllParameters>::stdcall});
    app->registerMethod(0x40007c, {"GetDistanceFactor", &Wrapper<decltype(&IDirectSound3DListener::GetDistanceFactor), &IDirectSound3DListener::GetDistanceFactor>::stdcall});
    app->registerMethod(0x40007d, {"GetDopplerFactor", &Wrapper<decltype(&IDirectSound3DListener::GetDopplerFactor), &IDirectSound3DListener::GetDopplerFactor>::stdcall});
    app->registerMethod(0x40007e, {"GetOrientation", &Wrapper<decltype(&IDirectSound3DListener::GetOrientation), &IDirectSound3DListener::GetOrientation>::stdcall});
    app->registerMethod(0x40007f, {"GetPosition", &Wrapper<decltype(&IDirectSound3DListener::GetPosition), &IDirectSound3DListener::GetPosition>::stdcall});
    app->registerMethod(0x400080, {"GetRolloffFactor", &Wrapper<decltype(&IDirectSound3DListener::GetRolloffFactor), &IDirectSound3DListener::GetRolloffFactor>::stdcall});
    app->registerMethod(0x400081, {"GetVelocity", &Wrapper<decltype(&IDirectSound3DListener::GetVelocity), &IDirectSound3DListener::GetVelocity>::stdcall});
    app->registerMethod(0x400082, {"SetAllParameters", &Wrapper<decltype(&IDirectSound3DListener::SetAllParameters), &IDirectSound3DListener::SetAllParameters>::stdcall});
    app->registerMethod(0x400083, {"SetDistanceFactor", &Wrapper<decltype(&IDirectSound3DListener::SetDistanceFactor), &IDirectSound3DListener::SetDistanceFactor>::stdcall});
    app->registerMethod(0x400084, {"SetDopplerFactor", &Wrapper<decltype(&IDirectSound3DListener::SetDopplerFactor), &IDirectSound3DListener::SetDopplerFactor>::stdcall});
    app->registerMethod(0x400085, {"SetOrientation", &Wrapper<decltype(&IDirectSound3DListener::SetOrientation), &IDirectSound3DListener::SetOrientation>::stdcall});
    app->registerMethod(0x400086, {"SetPosition", &Wrapper<decltype(&IDirectSound3DListener::SetPosition), &IDirectSound3DListener::SetPosition>::stdcall});
    app->registerMethod(0x400087, {"SetRolloffFactor", &Wrapper<decltype(&IDirectSound3DListener::SetRolloffFactor), &IDirectSound3DListener::SetRolloffFactor>::stdcall});
    app->registerMethod(0x400088, {"SetVelocity", &Wrapper<decltype(&IDirectSound3DListener::SetVelocity), &IDirectSound3DListener::SetVelocity>::stdcall});
    app->registerMethod(0x400089, {"CommitDeferredSettings", &Wrapper<decltype(&IDirectSound3DListener::CommitDeferredSettings), &IDirectSound3DListener::CommitDeferredSettings>::stdcall});

    s_iDirectSound3DListenerVtable = memblockIndex;
    vtable[0] = 0x400000;    // IUnknown_QueryInterface
    vtable[1] = 0x400001;    // IUnknown_AddRef
    vtable[2] = 0x400002;    // IUnknwon_Release
    vtable[3] = 0x40007b;    // IDirectSound3DListener_GetAllParameters
    vtable[4] = 0x40007c;    // IDirectSound3DListener_GetDistanceFactor
    vtable[5] = 0x40007d;    // IDirectSound3DListener_GetDopplerFactor
    vtable[6] = 0x40007e;    // IDirectSound3DListener_GetOrientation
    vtable[7] = 0x40007f;    // IDirectSound3DListener_GetPosition
    vtable[8] = 0x400080;    // IDirectSound3DListener_GetRolloffFactor
    vtable[9] = 0x400081;    // IDirectSound3DListener_GetVelocity
    vtable[10] = 0x400082;   // IDirectSound3DListener_SetAllParameters
    vtable[11] = 0x400083;   // IDirectSound3DListener_SetDistanceFactor
    vtable[12] = 0x400084;   // IDirectSound3DListener_SetDopplerFactor
    vtable[13] = 0x400085;   // IDirectSound3DListener_SetOrientation
    vtable[14] = 0x400086;   // IDirectSound3DListener_SetPosition
    vtable[15] = 0x400087;   // IDirectSound3DListener_SetRolloffFactor
    vtable[17] = 0x400088;   // IDirectSound3DListener_SetVelocity
    vtable[18] = 0x400089;   // IDirectSound3DListener_CommitDeferredSettings
    return 19 * sizeof(x86::reg32);
}

}}
