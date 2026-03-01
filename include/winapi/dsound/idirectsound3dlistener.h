#ifndef DSOUND_IDIRECTSOUND3DLISTENER_H_
#define DSOUND_IDIRECTSOUND3DLISTENER_H_

#include <winapi/com.h>
#include <winapi/dsound/idirectsound3dlistener.h>

namespace win32 { namespace dsound
{

class IDirectSoundBuffer;

class IDirectSound3DListener : public com::IUnknown
{
public:
    IDirectSound3DListener(IDirectSoundBuffer* owner);

    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);

private:
    struct DS3DLISTENER;
    typedef DS3DLISTENER* LPDS3DLISTENER;
    typedef const DS3DLISTENER* LPCDS3DLISTENER;
    typedef float D3DVALUE;
    typedef D3DVALUE* LPD3DVALUE;
    struct D3DVECTOR;
    typedef D3DVECTOR* LPD3DVECTOR;

    HRESULT GetAllParameters(WinApplication* app, x86::CPU& cpu, LPDS3DLISTENER lpListener);
    HRESULT GetDistanceFactor(WinApplication* app, x86::CPU& cpu, LPD3DVALUE lpflDistanceFactor);
    HRESULT GetDopplerFactor(WinApplication* app, x86::CPU& cpu, LPD3DVALUE lpflDopplerFactor);
    HRESULT GetOrientation(WinApplication* app, x86::CPU& cpu, LPD3DVECTOR lpvOrientFront, LPD3DVECTOR lpvOrientTop);
    HRESULT GetPosition(WinApplication* app, x86::CPU& cpu, LPD3DVECTOR lpvPosition);
    HRESULT GetRolloffFactor(WinApplication* app, x86::CPU& cpu, LPD3DVALUE lpflRolloffFactor);
    HRESULT GetVelocity(WinApplication* app, x86::CPU& cpu, LPD3DVECTOR lpvVelocity);
    HRESULT SetAllParameters(WinApplication* app, x86::CPU& cpu, LPCDS3DLISTENER lpcListener, DWORD dwApply);
    HRESULT SetDistanceFactor(WinApplication* app, x86::CPU& cpu, D3DVALUE flDistanceFactor, DWORD dwApply);
    HRESULT SetDopplerFactor(WinApplication* app, x86::CPU& cpu, D3DVALUE flDopplerFactor, DWORD dwApply);
    HRESULT SetOrientation(WinApplication* app, x86::CPU& cpu, D3DVALUE xFront, D3DVALUE yFront, D3DVALUE zFront, D3DVALUE xTop, D3DVALUE yTop, D3DVALUE zTop, DWORD dwApply);
    HRESULT SetPosition(WinApplication* app, x86::CPU& cpu, D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
    HRESULT SetRolloffFactor(WinApplication* app, x86::CPU& cpu, D3DVALUE flRolloffFactor, DWORD dwApply);
    HRESULT SetVelocity(WinApplication* app, x86::CPU& cpu, D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
    HRESULT CommitDeferredSettings(WinApplication* app, x86::CPU& cpu);

private:
    static x86::reg32 s_iDirectSound3DListenerVtable;
};

}}

#endif /*!DSOUND_IDIRECTSOUNDBUFFER_H_*/
