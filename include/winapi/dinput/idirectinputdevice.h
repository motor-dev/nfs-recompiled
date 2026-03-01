#ifndef DINPUT_IDIRECTINPUTDEVICE_H_
#define DINPUT_IDIRECTINPUTDEVICE_H_

#include <winapi/com.h>
#include <lib/gamepad.h>

namespace win32 { namespace dinput
{

class IDirectInputDevice : public com::IUnknown
{
public:
    IDirectInputDevice(Input* input);

    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);

private:
    struct DIPROPHEADER;
    typedef DIPROPHEADER*       LPDIPROPHEADER;
    typedef const DIPROPHEADER* LPCDIPROPHEADER;
    struct DIPROPRANGE;

    struct DIPROPPOINTER;
    typedef DIPROPPOINTER*          LPDIPROPPOINTER;
    typedef const DIPROPPOINTER*    LPCDIPROPPOINTER;

    struct DIDEVCAPS
    {
        DWORD dwSize;
        DWORD dwFlags;
        DWORD dwDevType;
        DWORD dwAxes;
        DWORD dwButtons;
        DWORD dwPOVs;
        DWORD dwFFSamplePeriod;
        DWORD dwFFMinTimeResolution;
        DWORD dwFirmwareRevision;
        DWORD dwHardwareRevision;
        DWORD dwFFDriverVersion;
    };
    typedef DIDEVCAPS* LPDIDEVCAPS;

    struct DIDEVICEOBJECTINSTANCE
    {
        DWORD   dwSize;
        GUID    guidType;
        DWORD   dwOfs;
        DWORD   dwType;
        DWORD   dwFlags;
        CHAR    tszName[MAX_PATH];
        DWORD   dwFFMaxForce;
        DWORD   dwFFForceResolution;
        WORD    wCollectionNumber;
        WORD    wDesignatorIndex;
        WORD    wUsagePage;
        WORD    wUsage;
        WORD    dwDimension;
        WORD    wExponent;
        WORD    wReportId;
    };
    typedef DIDEVICEOBJECTINSTANCE* LPDIDEVICEOBJECTINSTANCE;

    struct DIOBJECTDATAFORMAT
    {
        Packed<GUID>    pguid;
        DWORD           dwOfs;
        DWORD           dwType;
        DWORD           dwFlags;
    };
    typedef DIOBJECTDATAFORMAT* LPDIOBJECTDATAFORMAT;

    struct DIDEVICEOBJECTDATA
    {
        DWORD           dwOfs;
        DWORD           dwData;
        DWORD           dwTimeStamp;
        DWORD           dwSequence;
        Packed<UINT>    uAppData;
    };
    typedef DIDEVICEOBJECTDATA* LPDIDEVICEOBJECTDATA;
    typedef const DIDEVICEOBJECTDATA* LPCDIDEVICEOBJECTDATA;

    struct DIDATAFORMAT
    {
        DWORD                       dwSize;
        DWORD                       dwObjSize;
        DWORD                       dwFlags;
        DWORD                       dwDataSize;
        DWORD                       dwNumObjs;
        Packed<DIOBJECTDATAFORMAT>  rgodf;
    };
    typedef DIDATAFORMAT*       LPDIDATAFORMAT;
    typedef const DIDATAFORMAT* LPCDIDATAFORMAT;

    typedef x86::reg32 LPDIENUMDEVICEOBJECTSCALLBACK;
    struct DIDEVICEINSTANCE
    {
        DWORD dwSize;
        GUID guidInstance;
        GUID guidProduct;
        DWORD dwDevType;
        CHAR tszInstanceName[MAX_PATH];
        CHAR tszProductName[MAX_PATH];
        GUID guidFFDriver;
        WORD wUsagePage;
        WORD wUsage;
    };
    typedef DIDEVICEINSTANCE* LPDIDEVICEINSTANCE;

    struct DIENVELOPE
    {
        DWORD dwSize;
        DWORD dwAttackLevel;
        DWORD dwAttackTime;
        DWORD dwFadeLevel;
        DWORD dwFadeTime;
    };

    struct DIEFFECT
    {
        DWORD               dwSize;
        DWORD               dwFlags;
        DWORD               dwDuration;
        DWORD               dwSamplePeriod;
        DWORD               dwGain;
        DWORD               dwTriggerButton;
        DWORD               dwTriggerRepeatInterval;
        DWORD               cAxes;
        Packed<DWORD>       rgdwAxes;
        Packed<LONG>        rglDirection;
        Packed<DIENVELOPE>  lpEnvelope;
        DWORD               cbTypeSpecificParams;
        Packed<void>        lpvTypeSpecificParams;
        DWORD               dwStartDelay;
    };
    typedef DIEFFECT*       LPDIEFFECT;
    typedef const DIEFFECT* LPCDIEFFECT;

    struct DIEffectInfo
    {
        DWORD dwSize;
        GUID guid;
        DWORD dwEffType;
        DWORD dwStaticParams;
        DWORD dwDynamicParams;
        CHAR  tszName[MAX_PATH];
    };
    typedef DIEffectInfo* LPDIEffectInfo;

    struct DIEFFESCAPE
    {
        DWORD           dwSize;
        DWORD           dwCommand;
        Packed<void>    lpvInBuffer;
        DWORD           cbInBuffer;
        Packed<void>    lpvOutBuffer;
        DWORD           cbOutBuffer;
    };
    typedef DIEFFESCAPE* LPDIEFFESCAPE;

    typedef x86::reg32 LPDIENUMEFFECTSCALLBACK;
    typedef x86::reg32 LPDIENUMCREATEDEFFECTOBJECTSCALLBACK;

    HRESULT GetCapabilities(WinApplication* app, x86::CPU& cpu,
                            LPDIDEVCAPS lpDIDevCaps);
    HRESULT EnumObjects(WinApplication* app, x86::CPU& cpu,
                        LPDIENUMDEVICEOBJECTSCALLBACK lpCallback, x86::reg32 pvRef, DWORD dwFlags);
    HRESULT GetProperty(WinApplication* app, x86::CPU& cpu,
                        Packed<const GUID> rguidProp, LPDIPROPHEADER pdiph);
    HRESULT SetProperty(WinApplication* app, x86::CPU& cpu,
                        Packed<const GUID> rguidProp, LPCDIPROPHEADER pdiph);
    HRESULT Acquire(WinApplication* app, x86::CPU& cpu);
    HRESULT Unacquire(WinApplication* app, x86::CPU& cpu);
    HRESULT GetDeviceState(WinApplication* app, x86::CPU& cpu,
                           DWORD cbData, LPVOID lpvData);
    HRESULT GetDeviceData(WinApplication* app, x86::CPU& cpu,
                          DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
    HRESULT SetDataFormat(WinApplication* app, x86::CPU& cpu,
                          LPCDIDATAFORMAT lpdf);
    HRESULT SetEventNotification(WinApplication* app, x86::CPU& cpu,
                                 HANDLE hEvent);
    HRESULT SetCooperativeLevel(WinApplication* app, x86::CPU& cpu,
                                HWND hwnd, DWORD dwFlags);
    HRESULT GetObjectInfo(WinApplication* app, x86::CPU& cpu,
                          LPDIDEVICEOBJECTINSTANCE pdidoi, DWORD dwObj, DWORD dwHow);
    HRESULT GetDeviceInfo(WinApplication* app, x86::CPU& cpu,
                          LPDIDEVICEINSTANCE pdidi);
    HRESULT RunControlPanel(WinApplication* app, x86::CPU& cpu,
                            HWND hwndOwner, DWORD dwFlags);
    HRESULT Initialize(WinApplication* app, x86::CPU& cpu,
                       HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);
    HRESULT CreateEffect(WinApplication* app, x86::CPU& cpu,
                         REFGUID rguid, LPCDIEFFECT lpeff, Packed<IUnknown>* ppdeff, LPUNKNOWN punkOuter);
    HRESULT EnumEffects(WinApplication* app, x86::CPU& cpu,
                        LPDIENUMEFFECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwEffType);
    HRESULT GetEffectInfo(WinApplication* app, x86::CPU& cpu,
                          LPDIEffectInfo pdei, REFGUID rguid);
    HRESULT GetForceFeedbackState(WinApplication* app, x86::CPU& cpu,
                                  LPDWORD pdwOut);
    HRESULT SendForceFeedbackCommand(WinApplication* app, x86::CPU& cpu,
                                     DWORD dwFlags);
    HRESULT EnumCreatedEffectObjects(WinApplication* app, x86::CPU& cpu,
                                     LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);
    HRESULT Escape(WinApplication* app, x86::CPU& cpu,
                   LPDIEFFESCAPE pesc);
    HRESULT Poll(WinApplication* app, x86::CPU& cpu);
    HRESULT SendDeviceData(WinApplication* app, x86::CPU& cpu,
                           DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);

private:
    static x86::reg32 s_iDirectInputDeviceVtable;
    static const GUID s_diPropRange;
};

}}

#endif /*!DINPUT_IDIRECTINPUTDEVICE_H_*/
