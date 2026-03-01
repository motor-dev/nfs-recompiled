#ifndef DINPUT_IDIRECTINPUT2_H_
#define DINPUT_IDIRECTINPUT2_H_

#include "winapi/com.h"

namespace win32 { namespace dinput
{

class IDirectInputDevice;

class IDirectInput2 : public com::IUnknown
{
public:
    IDirectInput2();

    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);

private:
    typedef x86::reg32  LPDIENUMDEVICESCALLBACK;

    HRESULT CreateDevice(WinApplication* app, x86::CPU& cpu,
                         REFGUID rguid, Packed<IDirectInputDevice>* lplpDirectInputDevice, LPUNKNOWN pUnkOuter);
    HRESULT EnumDevices(WinApplication* app, x86::CPU& cpu,
                        DWORD dwDevType, LPDIENUMDEVICESCALLBACK lpCallback, Packed<void> pvRef, DWORD dwFlags);
    HRESULT GetDeviceStatus(WinApplication* app, x86::CPU& cpu,
                            REFGUID rguidInstance);
    HRESULT RunControlPanel(WinApplication* app, x86::CPU& cpu,
                            HWND hwndOwner, DWORD dwFlags);
    HRESULT Initialize(WinApplication* app, x86::CPU& cpu,
                       HINSTANCE hinst, DWORD dwVersion);
    HRESULT FindDevice(WinApplication* app, x86::CPU& cpu,
                       REFGUID rguidClass, LPCSTR ptszName, LPGUID pguidInstance);

private:
    static x86::reg32 s_iDirectInput2Vtable;
    static const GUID  s_GUID_SysKeyboard;
    static const GUID  s_GUID_SysMouse;
};

}}

#endif /*!DINPUT_IDIRECTINPUT2_H_*/
