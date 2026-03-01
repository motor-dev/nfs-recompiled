#include <winapi/dinput/idirectinputdevice.h>
#include <winapi/wrapper.h>
#include <lib/gamepad.h>


namespace win32 { namespace dinput
{


x86::reg32 IDirectInputDevice::s_iDirectInputDeviceVtable = 0;
const GUID IDirectInputDevice::s_diPropRange =  { 0x6F1D2B61, 0xD5A0, 0x11CF, { 0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00 } };

enum DirectInutDeviceForceFeedBackCommand
{
    DISFFC_RESET            = 0x00000001,
    DISFFC_STOPALL          = 0x00000002,
    DISFFC_PAUSE            = 0x00000004,
    DISFFC_CONTINUE         = 0x00000008,
    DISFFC_SETACTUATORSON   = 0x00000010,
    DISFFC_SETACTUATORSOFF  = 0x00000020
};

enum DirectInutDeviceFlags
{
    DIDC_ATTACHED           = 0x00000001,
    DIDC_POLLEDDEVICE       = 0x00000002,
    DIDC_EMULATED           = 0x00000004,
    DIDC_POLLEDDATAFORMAT   = 0x00000008,
    DIDC_FORCEFEEDBACK      = 0x00000100,
    DIDC_FFATTACK           = 0x00000200,
    DIDC_FFFADE             = 0x00000400,
    DIDC_SATURATION         = 0x00000800,
    DIDC_POSNEGCOEFFICIENTS = 0x00001000,
    DIDC_POSNEGSATURATION   = 0x00002000,
    DIDC_DEADBAND           = 0x00004000,
    DIDC_STARTDELAY         = 0x00008000,
    DIDC_ALIAS              = 0x00010000,
    DIDC_PHANTOM            = 0x00020000,
    DIDC_HIDDEN             = 0x00040000
};

enum DirectInputDeviceHow
{
    DIPH_DEVICE     = 0,
    DIPH_BYOFFSET   = 1,
    DIPH_BYID       = 2,
    DIPH_BYUSAGE    = 3
};

enum DirectInputDeviceForceFeedbackState
{
    DIGFFS_EMPTY           = 0x00000001,
    DIGFFS_STOPPED         = 0x00000002,
    DIGFFS_PAUSED          = 0x00000004,
    DIGFFS_ACTUATORSON     = 0x00000010,
    DIGFFS_ACTUATORSOFF    = 0x00000020,
    DIGFFS_POWERON         = 0x00000040,
    DIGFFS_POWEROFF        = 0x00000080,
    DIGFFS_SAFETYSWITCHON  = 0x00000100,
    DIGFFS_SAFETYSWITCHOFF = 0x00000200,
    DIGFFS_USERFFSWITCHON  = 0x00000400,
    DIGFFS_USERFFSWITCHOFF = 0x00000800,
    DIGFFS_DEVICELOST      = 0x80000000
};

struct DIJOYSTATE
{
    LONG lX;
    LONG lY;
    LONG lZ;
    LONG lRx;
    LONG lRy;
    LONG lRz;
    LONG rglSlider[2];
    DWORD rgdwPOV[4];
    BYTE rgbButtons[32];
};

struct IDirectInputDevice::DIPROPHEADER
{
    DWORD dwSize;
    DWORD dwHeaderSize;
    DWORD dwObj;
    DWORD dwHow;
};

struct IDirectInputDevice::DIPROPRANGE
{
    IDirectInputDevice::DIPROPHEADER diph;
    LONG lMin;
    LONG lMax;
};

struct IDirectInputDevice::DIPROPPOINTER
{
    IDirectInputDevice::DIPROPHEADER    diph;
    Packed<UINT>    uData;
};

//DEFINE_GUID(IID_IDirectInputDeviceA,	0x5944E680,0xC92E,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);
DEFINE_GUID(IID_IDirectInputDevice2A,	0x5944E682,0xC92E,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

IDirectInputDevice::IDirectInputDevice(Input* input)
    :   IUnknown(IID_IDirectInputDevice2A)
{
    m_vtable = s_iDirectInputDeviceVtable;
    m_resource = input;
}

HRESULT IDirectInputDevice::GetCapabilities(WinApplication* app, x86::CPU& cpu,
                                            LPDIDEVCAPS lpDIDevCaps)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(lpDIDevCaps->dwSize == sizeof(DIDEVCAPS));
    memset(lpDIDevCaps, 0, sizeof(DIDEVCAPS));
    lpDIDevCaps->dwSize = sizeof(DIDEVCAPS);
    lpDIDevCaps->dwFlags = DIDC_ATTACHED | DIDC_POLLEDDATAFORMAT /* | DIDC_FORCEFEEDBACK */;
    lpDIDevCaps->dwDevType = 4;
    lpDIDevCaps->dwButtons = dynamic_cast<Input*>(m_resource)->getButtonCount();
    lpDIDevCaps->dwAxes = dynamic_cast<Input*>(m_resource)->getAxesCount();
    return 0;
}

HRESULT IDirectInputDevice::EnumObjects(WinApplication* app, x86::CPU& cpu,
                                        LPDIENUMDEVICEOBJECTSCALLBACK lpCallback, x86::reg32 pvRef, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpCallback);
    NFS2_USE(pvRef);
    NFS2_USE(dwFlags);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::GetProperty(WinApplication* app, x86::CPU& cpu,
                                        Packed<const GUID> rguidProp, LPDIPROPHEADER pdiph)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(rguidProp);
    NFS2_USE(pdiph);
    //NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::SetProperty(WinApplication* app, x86::CPU& cpu,
                                        Packed<const GUID> rguidProp, LPCDIPROPHEADER pdiph)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(rguidProp);
    NFS2_USE(pdiph);
    return 0;
}

HRESULT IDirectInputDevice::Acquire(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0;
}

HRESULT IDirectInputDevice::Unacquire(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0;
}

HRESULT IDirectInputDevice::GetDeviceState(WinApplication* app, x86::CPU& cpu,
                                           DWORD cbData, LPVOID lpvData)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(cbData);
    NFS2_USE(lpvData);
    app->unlockContext(cpu);
    Gamepad* gamepad = dynamic_cast<Gamepad*>(m_resource);
    memset(lpvData, 0, cbData);
    if (gamepad)
    {
        NFS2_ASSERT(cbData == sizeof(DIJOYSTATE));
        DIJOYSTATE* state = reinterpret_cast<DIJOYSTATE*>(lpvData);
        GamepadState gpState = gamepad->getState();
        state->lX = 0x7fff + gpState.axes[0];
        state->lY = 0x7fff + gpState.axes[1];
        state->lZ = 0x7fff + gpState.axes[4];
        state->lRx = 0x7fff + gpState.axes[2];
        state->lRy = 0x7fff + gpState.axes[3];
        state->lRz = 0x7fff + gpState.axes[5];
        state->rgdwPOV[0] = -1;
        state->rgdwPOV[1] = -1;
        state->rgdwPOV[2] = -1;
        state->rgdwPOV[3] = -1;
        for (int button = 0; button < 16; ++button)
        {
            state->rgbButtons[button] = (gpState.buttons & (1ll<<button)) ? 0x80 : 0x00;
        }
    }
    app->lockContext(cpu);
    return 0;
}

HRESULT IDirectInputDevice::GetDeviceData(WinApplication* app, x86::CPU& cpu,
                                          DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(cbObjectData);
    NFS2_USE(rgdod);
    NFS2_USE(pdwInOut);
    NFS2_USE(dwFlags);
    NFS2_ASSERT(dynamic_cast<Mouse*>(m_resource));
    *pdwInOut = 0;
    return 0;
}

HRESULT IDirectInputDevice::SetDataFormat(WinApplication* app, x86::CPU& cpu,
                                          LPCDIDATAFORMAT lpdf)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpdf);
    return 0;
}

HRESULT IDirectInputDevice::SetEventNotification(WinApplication* app, x86::CPU& cpu,
                                                 HANDLE hEvent)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hEvent);
    return 0;
}

HRESULT IDirectInputDevice::SetCooperativeLevel(WinApplication* app, x86::CPU& cpu,
                                                HWND hwnd, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hwnd);
    NFS2_USE(dwFlags);
    return 0;
}

HRESULT IDirectInputDevice::GetObjectInfo(WinApplication* app, x86::CPU& cpu,
                                          LPDIDEVICEOBJECTINSTANCE pdidoi, DWORD dwObj, DWORD dwHow)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwObj);
    NFS2_USE(dwHow);
    NFS2_ASSERT(pdidoi->dwSize == sizeof(DIDEVICEOBJECTINSTANCE));
    memset(pdidoi, 0, pdidoi->dwSize);
    pdidoi->dwSize = sizeof(DIDEVICEOBJECTINSTANCE);
    /*switch (dwHow)
    {
    case DIPH_BYOFFSET:
        NFS2_ASSERT(false);
        break;
    case DIPH_DEVICE:
    case DIPH_BYID:
    case DIPH_BYUSAGE:
        NFS2_ASSERT(false);
        break;
    }
    NFS2_ASSERT(false);*/
    return 0;
}

HRESULT IDirectInputDevice::GetDeviceInfo(WinApplication* app, x86::CPU& cpu,
                                          LPDIDEVICEINSTANCE pdidi)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(pdidi);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::RunControlPanel(WinApplication* app, x86::CPU& cpu,
                                            HWND hwndOwner, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hwndOwner);
    NFS2_USE(dwFlags);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::Initialize(WinApplication* app, x86::CPU& cpu,
                                       HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hinst);
    NFS2_USE(dwVersion);
    NFS2_USE(rguid);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::CreateEffect(WinApplication* app, x86::CPU& cpu,
                                         REFGUID rguid, LPCDIEFFECT lpeff, Packed<IUnknown>* ppdeff, LPUNKNOWN punkOuter)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(rguid);
    NFS2_USE(lpeff);
    NFS2_USE(ppdeff);
    NFS2_USE(punkOuter);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::EnumEffects(WinApplication* app, x86::CPU& cpu,
                                        LPDIENUMEFFECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwEffType)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpCallback);
    NFS2_USE(pvRef);
    NFS2_USE(dwEffType);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::GetEffectInfo(WinApplication* app, x86::CPU& cpu,
                                          LPDIEffectInfo pdei, REFGUID rguid)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(pdei);
    NFS2_USE(rguid);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::GetForceFeedbackState(WinApplication* app, x86::CPU& cpu,
                                                  LPDWORD pdwOut)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(pdwOut);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::SendForceFeedbackCommand(WinApplication* app, x86::CPU& cpu,
                                                     DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwFlags);
    return 0;
}

HRESULT IDirectInputDevice::EnumCreatedEffectObjects(WinApplication* app, x86::CPU& cpu,
                                                     LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpCallback);
    NFS2_USE(pvRef);
    NFS2_USE(fl);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::Escape(WinApplication* app, x86::CPU& cpu,
                                   LPDIEFFESCAPE pesc)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(pesc);
    NFS2_ASSERT(false);
    return 1;
}

HRESULT IDirectInputDevice::Poll(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    app->unlockContext(cpu);
    Gamepad::poll();
    app->lockContext(cpu);
    return 0;
}

HRESULT IDirectInputDevice::SendDeviceData(WinApplication* app, x86::CPU& cpu,
                                           DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(cbObjectData);
    NFS2_USE(rgdod);
    NFS2_USE(pdwInOut);
    NFS2_USE(fl);
    NFS2_ASSERT(false);
    return 1;
}

x86::reg32 IDirectInputDevice::init(WinApplication *app, x86::reg32 memblockIndex, x86::reg8* memBlock)
{
    x86::reg32* vtable = reinterpret_cast<x86::reg32*>(memBlock);
    app->registerMethod(0x400048, {"GetCapabilities", &Wrapper<decltype(&IDirectInputDevice::GetCapabilities), &IDirectInputDevice::GetCapabilities>::stdcall});
    app->registerMethod(0x400049, {"EnumObjects", &Wrapper<decltype(&IDirectInputDevice::EnumObjects), &IDirectInputDevice::EnumObjects>::stdcall});
    app->registerMethod(0x40004a, {"GetProperty", &Wrapper<decltype(&IDirectInputDevice::GetProperty), &IDirectInputDevice::GetProperty>::stdcall});
    app->registerMethod(0x40004b, {"SetProperty", &Wrapper<decltype(&IDirectInputDevice::SetProperty), &IDirectInputDevice::SetProperty>::stdcall});
    app->registerMethod(0x40004c, {"Acquire", &Wrapper<decltype(&IDirectInputDevice::Acquire), &IDirectInputDevice::Acquire>::stdcall});
    app->registerMethod(0x40004d, {"Unacquire", &Wrapper<decltype(&IDirectInputDevice::Unacquire), &IDirectInputDevice::Unacquire>::stdcall});
    app->registerMethod(0x40004e, {"GetDeviceState", &Wrapper<decltype(&IDirectInputDevice::GetDeviceState), &IDirectInputDevice::GetDeviceState>::stdcall});
    app->registerMethod(0x40004f, {"GetDeviceData", &Wrapper<decltype(&IDirectInputDevice::GetDeviceData), &IDirectInputDevice::GetDeviceData>::stdcall});
    app->registerMethod(0x400050, {"SetDataFormat", &Wrapper<decltype(&IDirectInputDevice::SetDataFormat), &IDirectInputDevice::SetDataFormat>::stdcall});
    app->registerMethod(0x400051, {"SetEventNotification", &Wrapper<decltype(&IDirectInputDevice::SetEventNotification), &IDirectInputDevice::SetEventNotification>::stdcall});
    app->registerMethod(0x400052, {"SetCooperativeLevel", &Wrapper<decltype(&IDirectInputDevice::SetCooperativeLevel), &IDirectInputDevice::SetCooperativeLevel>::stdcall});
    app->registerMethod(0x400053, {"GetObjectInfo", &Wrapper<decltype(&IDirectInputDevice::GetObjectInfo), &IDirectInputDevice::GetObjectInfo>::stdcall});
    app->registerMethod(0x400054, {"GetDeviceInfo", &Wrapper<decltype(&IDirectInputDevice::GetDeviceInfo), &IDirectInputDevice::GetDeviceInfo>::stdcall});
    app->registerMethod(0x400055, {"RunControlPanel", &Wrapper<decltype(&IDirectInputDevice::RunControlPanel), &IDirectInputDevice::RunControlPanel>::stdcall});
    app->registerMethod(0x400056, {"Initialize", &Wrapper<decltype(&IDirectInputDevice::Initialize), &IDirectInputDevice::Initialize>::stdcall});
    app->registerMethod(0x400057, {"CreateEffect", &Wrapper<decltype(&IDirectInputDevice::CreateEffect), &IDirectInputDevice::CreateEffect>::stdcall});
    app->registerMethod(0x400058, {"EnumEffects", &Wrapper<decltype(&IDirectInputDevice::EnumEffects), &IDirectInputDevice::EnumEffects>::stdcall});
    app->registerMethod(0x400059, {"GetEffectInfo", &Wrapper<decltype(&IDirectInputDevice::GetEffectInfo), &IDirectInputDevice::GetEffectInfo>::stdcall});
    app->registerMethod(0x40005a, {"GetForceFeedbackState", &Wrapper<decltype(&IDirectInputDevice::GetForceFeedbackState), &IDirectInputDevice::GetForceFeedbackState>::stdcall});
    app->registerMethod(0x40005b, {"SendForceFeedbackCommand", &Wrapper<decltype(&IDirectInputDevice::SendForceFeedbackCommand), &IDirectInputDevice::SendForceFeedbackCommand>::stdcall});
    app->registerMethod(0x40005c, {"EnumCreatedEffectObjects", &Wrapper<decltype(&IDirectInputDevice::EnumCreatedEffectObjects), &IDirectInputDevice::EnumCreatedEffectObjects>::stdcall});
    app->registerMethod(0x40005d, {"Escape", &Wrapper<decltype(&IDirectInputDevice::Escape), &IDirectInputDevice::Escape>::stdcall});
    app->registerMethod(0x40005e, {"Poll", &Wrapper<decltype(&IDirectInputDevice::Poll), &IDirectInputDevice::Poll>::stdcall});
    app->registerMethod(0x40005f, {"SendDeviceData", &Wrapper<decltype(&IDirectInputDevice::SendDeviceData), &IDirectInputDevice::SendDeviceData>::stdcall});

    s_iDirectInputDeviceVtable = memblockIndex;
    vtable[0] = 0x400000;    // IUnknown_QueryInterface
    vtable[1] = 0x400001;    // IUnknown_AddRef
    vtable[2] = 0x400002;    // IUnknwon_Release
    vtable[3] = 0x400048;    // IDirectInputDevice_GetCapabilities
    vtable[4] = 0x400049;    // IDirectInputDevice_EnumObjects
    vtable[5] = 0x40004a;    // IDirectInputDevice_GetProperty
    vtable[6] = 0x40004b;    // IDirectInputDevice_SetProperty
    vtable[7] = 0x40004c;    // IDirectInputDevice_Acquire
    vtable[8] = 0x40004d;    // IDirectInputDevice_Unacquire
    vtable[9] = 0x40004e;    // IDirectInputDevice_GetDeviceState
    vtable[10] = 0x40004f;    // IDirectInputDevice_GetDeviceData
    vtable[11] = 0x400050;    // IDirectInputDevice_SetDataFormat
    vtable[12] = 0x400051;    // IDirectInputDevice_SetEventNotification
    vtable[13] = 0x400052;    // IDirectInputDevice_SetCooperativeLevel
    vtable[14] = 0x400053;    // IDirectInputDevice_GetObjectInfo
    vtable[15] = 0x400054;    // IDirectInputDevice_GetDeviceInfo
    vtable[16] = 0x400055;    // IDirectInputDevice_RunControlPanel
    vtable[17] = 0x400056;    // IDirectInputDevice_Initialize
    vtable[18] = 0x400057;    // IDirectInputDevice_CreateEffect
    vtable[19] = 0x400058;    // IDirectInputDevice_EnumEffects
    vtable[20] = 0x400059;    // IDirectInputDevice_GetEffectInfo
    vtable[21] = 0x40005a;    // IDirectInputDevice_GetForceFeedbackState
    vtable[22] = 0x40005b;    // IDirectInputDevice_SendForceFeedbackCommand
    vtable[23] = 0x40005c;    // IDirectInputDevice_EnumCreatedEffectObjects
    vtable[24] = 0x40005d;    // IDirectInputDevice_Escape
    vtable[25] = 0x40005e;    // IDirectInputDevice_Poll
    vtable[26] = 0x40005f;    // IDirectInputDevice_SendDeviceData
    return 27 * sizeof(x86::reg32);
}

}}
