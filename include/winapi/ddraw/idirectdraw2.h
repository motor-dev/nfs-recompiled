#ifndef DDRAW_IDIRECTDRAW2_H_
#define DDRAW_IDIRECTDRAW2_H_

#include <winapi/com.h>
#include <lib/palette.h>
#include <winapi/ddraw/idirectdrawsurface.h>


namespace win32 { namespace ddraw
{

class IDirectDraw2 : public com::IUnknown
{
public:
    IDirectDraw2();

    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);
    static x86::reg32 g_currentDisplayMode;

private:
    struct DDCAPS;
    typedef DDCAPS* LPDDCAPS;

    BOOL QueryInterface(WinApplication* app, x86::CPU& cpu,
                        REFGUID refiid, x86::reg32* pvvObject);
    static void Compact(WinApplication* app, x86::CPU& cpu);
    static void CreateClipper(WinApplication* app, x86::CPU& cpu);
    HRESULT CreatePalette(WinApplication* app, x86::CPU& cpu,
                          DWORD dwFlags, PALETTEENTRY* lpColorTable,
                          x86::reg32* lpDirectDrawPalette, LPUNKNOWN pUnkOuter);
    HRESULT CreateSurface(WinApplication* app, x86::CPU& cpu,
                          DDSURFACEDESC* lpSurfaceDesc, x86::reg32* lpDirectDrawSurface, LPUNKNOWN pUnkOuter);
    static void DuplicateSurface(WinApplication* app, x86::CPU& cpu);
    HRESULT EnumDisplayModes(WinApplication* app, x86::CPU& cpu,
                             DWORD dwFlags, DDSURFACEDESC* lpDDSurfaceDesc,
                             Packed<void> context, x86::reg32 lpEnumModesCallback);
    static void EnumSurfaces(WinApplication* app, x86::CPU& cpu);
    HRESULT FlipToGDISurface(WinApplication* app, x86::CPU& cpu);
    HRESULT GetCaps(WinApplication* app, x86::CPU& cpu, LPDDCAPS lpDDCaps, LPDDCAPS lpDDHelCaps);
    HRESULT GetDisplayMode(WinApplication* app, x86::CPU& cpu,
                           DDSURFACEDESC* desc);
    static void GetFourCCCodes(WinApplication* app, x86::CPU& cpu);
    static void GetGDISurface(WinApplication* app, x86::CPU& cpu);
    static void GetMonitorFrequency(WinApplication* app, x86::CPU& cpu);
    static void GetScanLine(WinApplication* app, x86::CPU& cpu);
    static void GetVerticalBlankStatus(WinApplication* app, x86::CPU& cpu);
    static void Initialize(WinApplication* app, x86::CPU& cpu);
    static void RestoreDisplayMode(WinApplication* app, x86::CPU& cpu);
    HRESULT SetCooperativeLevel(WinApplication* app, x86::CPU& cpu, HWND hWNd, DWORD dwFlags);
    HRESULT SetDisplayMode(WinApplication* app, x86::CPU& cpu,
                           DWORD dwWidth, DWORD dwHeight, DWORD dwBPP,
                           DWORD dwRefreshRate, DWORD dwFlags);
    static void WaitForVerticalBlank(WinApplication* app, x86::CPU& cpu);
    HRESULT GetAvailableVidMem(WinApplication* app, x86::CPU& cpu,
                               LPDDSCAPS lpDDSCaps, LPDWORD lpdwTotal, LPDWORD lpdwFree);

private:
    static x86::reg32 s_iDirectDraw2Vtable;
};

}}

#endif /*!DDRAW_IDIRECTDRAW2_H_*/
