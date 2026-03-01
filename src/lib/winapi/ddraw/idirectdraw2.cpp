#include <winapi/ddraw/idirectdraw2.h>
#include <winapi/ddraw/idirectdrawpalette.h>
#include <winapi/ddraw/idirectdrawsurface.h>
#include <winapi/com.h>
#include <winapi/wrapper.h>
#include <lib/window.h>
#include <lib/renderer.h>


namespace win32 { namespace ddraw
{

static x86::reg32 g_dm8bpp640;
static x86::reg32 g_dm8bpp800;
static x86::reg32 g_dm16bpp640;
static x86::reg32 g_dm16bpp800;

x86::reg32 IDirectDraw2::s_iDirectDraw2Vtable = 0;
x86::reg32 IDirectDraw2::g_currentDisplayMode;


static const int DD_ROP_SPACE = (256/32);
struct IDirectDraw2::DDCAPS
{
    DWORD   dwSize;
    DWORD   dwCaps;
    DWORD   dwCaps2;
    DWORD   dwCKeyCaps;
    DWORD   dwFXCaps;
    DWORD   dwFXAlphaCaps;
    DWORD   dwPalCaps;
    DWORD   dwSVCaps;
    DWORD   dwAlphaBltConstBitDepths;
    DWORD   dwAlphaBltPixelBitDepths;
    DWORD   dwAlphaBltSurfaceBitDepths;
    DWORD   dwAlphaOverlayConstBitDepths;
    DWORD   dwAlphaOverlayPixelBitDepths;
    DWORD   dwAlphaOverlaySurfaceBitDepths;
    DWORD   dwZBufferBitDepths;
    DWORD   dwVidMemTotal;
    DWORD   dwVidMemFree;
    DWORD   dwMaxVisibleOverlays;
    DWORD   dwCurrVisibleOverlays;
    DWORD   dwNumFourCCCodes;
    DWORD   dwAlignBoundarySrc;
    DWORD   dwAlignSizeSrc;
    DWORD   dwAlignBoundaryDest;
    DWORD   dwAlignSizeDest;
    DWORD   dwAlignStrideAlign;
    DWORD   dwRops[DD_ROP_SPACE];
    DDSCAPS ddsCaps;
    DWORD   dwMinOverlayStretch;
    DWORD   dwMaxOverlayStretch;
    DWORD   dwMinLiveVideoStretch;
    DWORD   dwMaxLiveVideoStretch;
    DWORD   dwMinHwCodecStretch;
    DWORD   dwMaxHwCodecStretch;
    DWORD   dwReserved1;
    DWORD   dwReserved2;
    DWORD   dwReserved3;
    DWORD   dwSVBCaps;
    DWORD   dwSVBCKeyCaps;
    DWORD   dwSVBFXCaps;
    DWORD   dwSVBRops[DD_ROP_SPACE];
    DWORD   dwVSBCaps;
    DWORD   dwVSBCKeyCaps;
    DWORD   dwVSBFXCaps;
    DWORD   dwVSBRops[DD_ROP_SPACE];
    DWORD   dwSSBCaps;
    DWORD   dwSSBCKeyCaps;
    DWORD   dwSSBFXCaps;
    DWORD   dwSSBRops[DD_ROP_SPACE];
    DWORD   dwMaxVideoPorts;
    DWORD   dwCurrVideoPorts;
    DWORD   dwSVBCaps2;
    DWORD   dwNLVBCaps;
    DWORD   dwNLVBCaps2;
    DWORD   dwNLVBCKeyCaps;
    DWORD   dwNLVBFXCaps;
    DWORD   dwNLVBRops[DD_ROP_SPACE];
};

enum DDSCL
{
    DDSCL_NORMAL = 0x8
};

DEFINE_GUID(IID_IDirectDraw2, 0xB3A6F3E0,0x2B43,0x11CF,0xA2,0xDE,0x00,0xAA,0x00,0xB9,0x33,0x56);
DEFINE_GUID(IID_IDirectDraw3, 0x618f8ad4,0x8b7a,0x11d0,0x8f,0xcc,0x00,0xc0,0x4f,0xd9,0x18,0x9d);

IDirectDraw2::IDirectDraw2()
    :   IUnknown(IID_IDirectDraw3)
{
    m_vtable = s_iDirectDraw2Vtable;
}

BOOL IDirectDraw2::QueryInterface(WinApplication* app, x86::CPU& cpu,
                                  REFGUID refiid, x86::reg32* pvvObject)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(refiid);
    if (*refiid == IID_IDirectDraw2 || *refiid == IID_IDirectDraw3)
    {
        *pvvObject = ComGetIndex(app, this);
        m_refCount ++;
        return 0;
    }
    else
    {
        *pvvObject = 0;
        //m_refCount ++;
        return 0x80004002;
    }
}

void IDirectDraw2::Compact(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDraw2::CreateClipper(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

HRESULT IDirectDraw2::CreatePalette(WinApplication* app, x86::CPU& cpu,
                                    DWORD dwFlags, PALETTEENTRY* lpColorTable,
                                    x86::reg32* lpDirectDrawPalette, LPUNKNOWN pUnkOuter)
{
    NFS2_USE(cpu);
    NFS2_ASSERT(pUnkOuter == nullptr);
    *lpDirectDrawPalette = com::ComAlloc(app);
    new (app->getMemory<IDirectDrawPalette>(*lpDirectDrawPalette)) IDirectDrawPalette(app, dynamic_cast<Renderer*>(m_resource), dwFlags, lpColorTable);
    return 0;
}

HRESULT IDirectDraw2::CreateSurface(WinApplication* app, x86::CPU& cpu,
                                    DDSURFACEDESC* lpSurfaceDesc, x86::reg32* lpDirectDrawSurface, LPUNKNOWN pUnkOuter)
{
    NFS2_USE(cpu);
    NFS2_USE(lpSurfaceDesc);
    NFS2_ASSERT(pUnkOuter == nullptr);
    *lpDirectDrawSurface = com::ComAlloc(app);
    IDirectDrawSurface* mem = app->getMemory<IDirectDrawSurface>(*lpDirectDrawSurface);
    new (mem) IDirectDrawSurface(app, app->getMemory<DDSURFACEDESC>(g_currentDisplayMode),
                                 dynamic_cast<Renderer*>(m_resource),
                                 0);
    return 0;
}

void IDirectDraw2::DuplicateSurface(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

HRESULT IDirectDraw2::EnumDisplayModes(WinApplication* app, x86::CPU& cpu,
                                       DWORD dwFlags, DDSURFACEDESC* lpDDSurfaceDesc,
                                       Packed<void> context, x86::reg32 lpEnumModesCallback)
{
    NFS2_USE(dwFlags);
    if (lpDDSurfaceDesc)
    {
        NFS2_ASSERT(lpDDSurfaceDesc->dwSize == sizeof(DDSURFACEDESC));
    }
    cpu.esp -= 12;
    *app->getMemory<x86::reg32>(cpu.esp + 0) = lpEnumModesCallback;
    *app->getMemory<x86::reg32>(cpu.esp + 4) = g_dm16bpp800;
    *app->getMemory<x86::reg32>(cpu.esp + 8) = context;
    app->dynamic_call(lpEnumModesCallback, cpu);
    cpu.esp -= 12;
    *app->getMemory<x86::reg32>(cpu.esp + 0) = lpEnumModesCallback;
    *app->getMemory<x86::reg32>(cpu.esp + 4) = g_dm8bpp800;
    *app->getMemory<x86::reg32>(cpu.esp + 8) = context;
    app->dynamic_call(lpEnumModesCallback, cpu);
    cpu.esp -= 12;
    *app->getMemory<x86::reg32>(cpu.esp + 0) = lpEnumModesCallback;
    *app->getMemory<x86::reg32>(cpu.esp + 4) = g_dm16bpp640;
    *app->getMemory<x86::reg32>(cpu.esp + 8) = context;
    app->dynamic_call(lpEnumModesCallback, cpu);
    cpu.esp -= 12;
    *app->getMemory<x86::reg32>(cpu.esp + 0) = lpEnumModesCallback;
    *app->getMemory<x86::reg32>(cpu.esp + 4) = g_dm8bpp640;
    *app->getMemory<x86::reg32>(cpu.esp + 8) = context;
    app->dynamic_call(lpEnumModesCallback, cpu);
    return 0;
}

void IDirectDraw2::EnumSurfaces(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

HRESULT IDirectDraw2::FlipToGDISurface(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return 0;
}

HRESULT IDirectDraw2::GetCaps(WinApplication* app, x86::CPU& cpu, LPDDCAPS lpDDCaps, LPDDCAPS lpDDHelCaps)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(lpDDCaps->dwSize == sizeof(DDCAPS));
    NFS2_ASSERT(lpDDHelCaps->dwSize == sizeof(DDCAPS));
    memset(lpDDCaps, 0, lpDDCaps->dwSize);
    memset(lpDDHelCaps, 0, lpDDHelCaps->dwSize);
    lpDDCaps->dwSize = sizeof(DDCAPS);
    //lpDDCaps->dwCaps = 0x40;
    return 0;
}

HRESULT IDirectDraw2::GetDisplayMode(WinApplication* app, x86::CPU& cpu,
                                     DDSURFACEDESC* desc)
{
    NFS2_USE(cpu);
    DDSURFACEDESC* currentDisplayMode = app->getMemory<DDSURFACEDESC>(g_currentDisplayMode);
    memcpy(desc, currentDisplayMode, currentDisplayMode->dwSize);
    return 0;
}

void IDirectDraw2::GetFourCCCodes(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDraw2::GetGDISurface(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDraw2::GetMonitorFrequency(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDraw2::GetScanLine(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDraw2::GetVerticalBlankStatus(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDraw2::Initialize(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDraw2::RestoreDisplayMode(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

HRESULT IDirectDraw2::SetCooperativeLevel(WinApplication* app, x86::CPU& cpu, HWND hWNd, DWORD dwFlags)
{
    NFS2_USE(cpu);
    NFS2_USE(dwFlags);
    Window* window = dynamic_cast<Window*>(app->getResource(hWNd));
    if (!window)
    {
        /*TODO: delete renderer?*/
    }
    else
    {
        m_resource = new Renderer(app, window);
        app->allocateResource(m_resource);
    }
    return 0;
}

HRESULT IDirectDraw2::SetDisplayMode(WinApplication* app, x86::CPU& cpu,
                                     DWORD dwWidth, DWORD dwHeight, DWORD dwBPP,
                                     DWORD dwRefreshRate, DWORD dwFlags)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(dwRefreshRate);
    NFS2_USE(dwFlags);
    g_currentDisplayMode = dwBPP == 8 ? (dwWidth == 640 ?  g_dm8bpp640 : g_dm8bpp800)
                                      : (dwWidth == 640 ?  g_dm16bpp640 : g_dm16bpp800);
    dynamic_cast<Renderer*>(m_resource)->setVideoMode(dwWidth, dwHeight, dwBPP);
    return 0;
}

void IDirectDraw2::WaitForVerticalBlank(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

HRESULT IDirectDraw2::GetAvailableVidMem(WinApplication* app, x86::CPU& cpu,
                                         LPDDSCAPS lpDDSCaps, LPDWORD lpdwTotal, LPDWORD lpdwFree)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(lpDDSCaps);
    *lpdwTotal = dynamic_cast<Renderer*>(m_resource)->getVideoMemorySize();
    *lpdwFree = dynamic_cast<Renderer*>(m_resource)->getVideoMemorySize();
    return 0;
}

x86::reg32 IDirectDraw2::init(WinApplication *app, x86::reg32 memblockIndex, x86::reg8* memBlock)
{
    x86::reg32* vtable = reinterpret_cast<x86::reg32*>(memBlock);
    app->registerMethod(0x400003, {"IDirectDraw2::QueryInterface", &Wrapper<decltype(&IDirectDraw2::QueryInterface), &IDirectDraw2::QueryInterface>::stdcall});
    app->registerMethod(0x400004, {"IDirectDraw2::Compact", &Wrapper<decltype(&IDirectDraw2::Compact), &IDirectDraw2::Compact>::stdcall});
    app->registerMethod(0x400005, {"IDirectDraw2::CreateClipper", &Wrapper<decltype(&IDirectDraw2::CreateClipper), &IDirectDraw2::CreateClipper>::stdcall});
    app->registerMethod(0x400006, {"IDirectDraw2::CreatePalette", &Wrapper<decltype(&IDirectDraw2::CreatePalette), &IDirectDraw2::CreatePalette>::stdcall});
    app->registerMethod(0x400007, {"IDirectDraw2::CreateSurface", &Wrapper<decltype(&IDirectDraw2::CreateSurface), &IDirectDraw2::CreateSurface>::stdcall});
    app->registerMethod(0x400008, {"IDirectDraw2::DuplicateSurface", &Wrapper<decltype(&IDirectDraw2::DuplicateSurface), &IDirectDraw2::DuplicateSurface>::stdcall});
    app->registerMethod(0x400009, {"IDirectDraw2::EnumDisplayModes", &Wrapper<decltype(&IDirectDraw2::EnumDisplayModes), &IDirectDraw2::EnumDisplayModes>::stdcall});
    app->registerMethod(0x40000a, {"IDirectDraw2::EnumSurfaces", &Wrapper<decltype(&IDirectDraw2::EnumSurfaces), &IDirectDraw2::EnumSurfaces>::stdcall});
    app->registerMethod(0x40000b, {"IDirectDraw2::FlipToGDISurface", &Wrapper<decltype(&IDirectDraw2::FlipToGDISurface), &IDirectDraw2::FlipToGDISurface>::stdcall});
    app->registerMethod(0x40000c, {"IDirectDraw2::GetCaps", &Wrapper<decltype(&IDirectDraw2::GetCaps), &IDirectDraw2::GetCaps>::stdcall});
    app->registerMethod(0x40000d, {"IDirectDraw2::GetDisplayMode", &Wrapper<decltype(&IDirectDraw2::GetDisplayMode), &IDirectDraw2::GetDisplayMode>::stdcall});
    app->registerMethod(0x40000e, {"IDirectDraw2::GetFourCCCodes", &Wrapper<decltype(&IDirectDraw2::GetFourCCCodes), &IDirectDraw2::GetFourCCCodes>::stdcall});
    app->registerMethod(0x40000f, {"IDirectDraw2::GetGDISurface", &Wrapper<decltype(&IDirectDraw2::GetGDISurface), &IDirectDraw2::GetGDISurface>::stdcall});
    app->registerMethod(0x400010, {"IDirectDraw2::GetMonitorFrequency", &Wrapper<decltype(&IDirectDraw2::GetMonitorFrequency), &IDirectDraw2::GetMonitorFrequency>::stdcall});
    app->registerMethod(0x400011, {"IDirectDraw2::GetScanLine", &Wrapper<decltype(&IDirectDraw2::GetScanLine), &IDirectDraw2::GetScanLine>::stdcall});
    app->registerMethod(0x400012, {"IDirectDraw2::GetVerticalBlankStatus", &Wrapper<decltype(&IDirectDraw2::GetVerticalBlankStatus), &IDirectDraw2::GetVerticalBlankStatus>::stdcall});
    app->registerMethod(0x400013, {"IDirectDraw2::Initialize", &Wrapper<decltype(&IDirectDraw2::Initialize), &IDirectDraw2::Initialize>::stdcall});
    app->registerMethod(0x400014, {"IDirectDraw2::RestoreDisplayMode", &Wrapper<decltype(&IDirectDraw2::RestoreDisplayMode), &IDirectDraw2::RestoreDisplayMode>::stdcall});
    app->registerMethod(0x400015, {"IDirectDraw2::SetCooperativeLevel", &Wrapper<decltype(&IDirectDraw2::SetCooperativeLevel), &IDirectDraw2::SetCooperativeLevel>::stdcall});
    app->registerMethod(0x400016, {"IDirectDraw2::SetDisplayMode", &Wrapper<decltype(&IDirectDraw2::SetDisplayMode), &IDirectDraw2::SetDisplayMode>::stdcall});
    app->registerMethod(0x400017, {"IDirectDraw2::WaitForVerticalBlank", &Wrapper<decltype(&IDirectDraw2::WaitForVerticalBlank), &IDirectDraw2::WaitForVerticalBlank>::stdcall});
    app->registerMethod(0x400018, {"IDirectDraw2::GetAvailableVidMem", &Wrapper<decltype(&IDirectDraw2::GetAvailableVidMem), &IDirectDraw2::GetAvailableVidMem>::stdcall});
    s_iDirectDraw2Vtable = memblockIndex;
    vtable[0] = 0x400003;    // IDirectDraw2_QueryInterface
    vtable[1] = 0x400001;    // IUnknown_AddRef
    vtable[2] = 0x400002;    // IUnknwon_Release
    vtable[3] = 0x400004;    // IDirectDraw2_Compact
    vtable[4] = 0x400005;    // IDirectDraw2_CreateClipper
    vtable[5] = 0x400006;    // IDirectDraw2_CreatePalette
    vtable[6] = 0x400007;    // IDirectDraw2_CreateSurface
    vtable[7] = 0x400008;    // IDirectDraw2_DuplicateSurface
    vtable[8] = 0x400009;    // IDirectDraw2_EnumDisplayModes
    vtable[9] = 0x40000a;    // IDirectDraw2_EnumSurfaces
    vtable[10] = 0x40000b;    // IDirectDraw2_FlipToGDISurface
    vtable[11] = 0x40000c;    // IDirectDraw2_GetCaps
    vtable[12] = 0x40000d;    // IDirectDraw2_GetDisplayMode
    vtable[13] = 0x40000e;    // IDirectDraw2_GetFourCCCodes
    vtable[14] = 0x40000f;    // IDirectDraw2_GetGDISurface
    vtable[15] = 0x400010;    // IDirectDraw2_GetMonitorFrequency
    vtable[16] = 0x400011;    // IDirectDraw2_GetScanLine
    vtable[17] = 0x400012;    // IDirectDraw2_GetVerticalBlankStatus
    vtable[18] = 0x400013;    // IDirectDraw2_Initialize
    vtable[19] = 0x400014;    // IDirectDraw2_RestoreDisplayMode
    vtable[20] = 0x400015;    // IDirectDraw2_SetCooperativeLevel
    vtable[21] = 0x400016;    // IDirectDraw2_SetDisplayMode
    vtable[22] = 0x400017;    // IDirectDraw2_WaitForVerticalBlank
    vtable[23] = 0x400018;    // IDirectDraw2_GetAvailableVidMem

    DDSURFACEDESC* dm8bpp = (DDSURFACEDESC*)(vtable + 24);
    dm8bpp->dwSize = sizeof(DDSURFACEDESC);
    dm8bpp->dwFlags = 0x04100e;
    dm8bpp->dwHeight = 480;
    dm8bpp->dwWidth = 640;
    dm8bpp->dwLinearSize = 640;
    dm8bpp->dwBackBufferCount = 0;
    dm8bpp->dwRefreshRate = 60;
    dm8bpp->dwAlphaBitDepth = 0;
    dm8bpp->dwReserved = 0;
    dm8bpp->lpSurface = Packed<void>(0);
    dm8bpp->ddckCKDestOverlay.dwColorSpaceLowValue = 0;
    dm8bpp->ddckCKDestOverlay.dwColorSpaceHighValue = 0;
    dm8bpp->ddckCKDestBlt.dwColorSpaceLowValue = 0;
    dm8bpp->ddckCKDestBlt.dwColorSpaceHighValue = 0;
    dm8bpp->ddckCKSrcOverlay.dwColorSpaceLowValue = 0;
    dm8bpp->ddckCKSrcOverlay.dwColorSpaceHighValue = 0;
    dm8bpp->ddckCKSrcBlt.dwColorSpaceLowValue = 0;
    dm8bpp->ddckCKSrcBlt.dwColorSpaceHighValue = 0;
    dm8bpp->ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
    dm8bpp->ddpfPixelFormat.dwFlags = 0x60;
    dm8bpp->ddpfPixelFormat.dwFourCC = 0;
    dm8bpp->ddpfPixelFormat.dwRGBBitCount = 8;
    dm8bpp->ddpfPixelFormat.dwRBitMask = 0;
    dm8bpp->ddpfPixelFormat.dwGBitMask = 0;
    dm8bpp->ddpfPixelFormat.dwBBitMask = 0;
    dm8bpp->ddpfPixelFormat.dwRGBAlphaBitMask = 0;
    dm8bpp->ddsCaps.dwCaps = 0;
    g_dm8bpp640 = memblockIndex + 24 * sizeof(x86::reg32);

    DDSURFACEDESC* dm16bpp = (DDSURFACEDESC*)(vtable + 24 + sizeof(DDSURFACEDESC)/4);
    dm16bpp->dwSize = sizeof(DDSURFACEDESC);
    dm16bpp->dwFlags = 0x04100e;
    dm16bpp->dwHeight = 480;
    dm16bpp->dwWidth = 640;
    dm16bpp->dwLinearSize = 640*2;
    dm16bpp->dwBackBufferCount = 0;
    dm16bpp->dwRefreshRate = 60;
    dm16bpp->dwAlphaBitDepth = 0;
    dm16bpp->dwReserved = 0;
    dm16bpp->lpSurface = Packed<void>(0);
    dm16bpp->ddckCKDestOverlay.dwColorSpaceLowValue = 0;
    dm16bpp->ddckCKDestOverlay.dwColorSpaceHighValue = 0;
    dm16bpp->ddckCKDestBlt.dwColorSpaceLowValue = 0;
    dm16bpp->ddckCKDestBlt.dwColorSpaceHighValue = 0;
    dm16bpp->ddckCKSrcOverlay.dwColorSpaceLowValue = 0;
    dm16bpp->ddckCKSrcOverlay.dwColorSpaceHighValue = 0;
    dm16bpp->ddckCKSrcBlt.dwColorSpaceLowValue = 0;
    dm16bpp->ddckCKSrcBlt.dwColorSpaceHighValue = 0;
    dm16bpp->ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
    dm16bpp->ddpfPixelFormat.dwFlags = 0x40;
    dm16bpp->ddpfPixelFormat.dwFourCC = 0;
    dm16bpp->ddpfPixelFormat.dwRGBBitCount = 16;
    dm16bpp->ddpfPixelFormat.dwRBitMask = 0xf800;
    dm16bpp->ddpfPixelFormat.dwGBitMask = 0x07e0;
    dm16bpp->ddpfPixelFormat.dwBBitMask = 0x001f;
    dm16bpp->ddpfPixelFormat.dwRGBAlphaBitMask = 0;
    dm16bpp->ddsCaps.dwCaps = 0;
    g_dm16bpp640 = memblockIndex + 24 * sizeof(x86::reg32) + sizeof(DDSURFACEDESC);


    dm8bpp = (DDSURFACEDESC*)(vtable + 24 + 2*sizeof(DDSURFACEDESC)/4);
    dm8bpp->dwSize = sizeof(DDSURFACEDESC);
    dm8bpp->dwFlags = 0x04100e;
    dm8bpp->dwHeight = 600;
    dm8bpp->dwWidth = 800;
    dm8bpp->dwLinearSize = 800;
    dm8bpp->dwBackBufferCount = 0;
    dm8bpp->dwRefreshRate = 60;
    dm8bpp->dwAlphaBitDepth = 0;
    dm8bpp->dwReserved = 0;
    dm8bpp->lpSurface = Packed<void>(0);
    dm8bpp->ddckCKDestOverlay.dwColorSpaceLowValue = 0;
    dm8bpp->ddckCKDestOverlay.dwColorSpaceHighValue = 0;
    dm8bpp->ddckCKDestBlt.dwColorSpaceLowValue = 0;
    dm8bpp->ddckCKDestBlt.dwColorSpaceHighValue = 0;
    dm8bpp->ddckCKSrcOverlay.dwColorSpaceLowValue = 0;
    dm8bpp->ddckCKSrcOverlay.dwColorSpaceHighValue = 0;
    dm8bpp->ddckCKSrcBlt.dwColorSpaceLowValue = 0;
    dm8bpp->ddckCKSrcBlt.dwColorSpaceHighValue = 0;
    dm8bpp->ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
    dm8bpp->ddpfPixelFormat.dwFlags = 0x60;
    dm8bpp->ddpfPixelFormat.dwFourCC = 0;
    dm8bpp->ddpfPixelFormat.dwRGBBitCount = 8;
    dm8bpp->ddpfPixelFormat.dwRBitMask = 0;
    dm8bpp->ddpfPixelFormat.dwGBitMask = 0;
    dm8bpp->ddpfPixelFormat.dwBBitMask = 0;
    dm8bpp->ddpfPixelFormat.dwRGBAlphaBitMask = 0;
    dm8bpp->ddsCaps.dwCaps = 0;
    g_dm8bpp800 = memblockIndex + 24 * sizeof(x86::reg32);

    dm16bpp = (DDSURFACEDESC*)(vtable + 24 + 3*sizeof(DDSURFACEDESC)/4);
    dm16bpp->dwSize = sizeof(DDSURFACEDESC);
    dm16bpp->dwFlags = 0x04100e;
    dm16bpp->dwHeight = 600;
    dm16bpp->dwWidth = 800;
    dm16bpp->dwLinearSize = 800*2;
    dm16bpp->dwBackBufferCount = 0;
    dm16bpp->dwRefreshRate = 60;
    dm16bpp->dwAlphaBitDepth = 0;
    dm16bpp->dwReserved = 0;
    dm16bpp->lpSurface = Packed<void>(0);
    dm16bpp->ddckCKDestOverlay.dwColorSpaceLowValue = 0;
    dm16bpp->ddckCKDestOverlay.dwColorSpaceHighValue = 0;
    dm16bpp->ddckCKDestBlt.dwColorSpaceLowValue = 0;
    dm16bpp->ddckCKDestBlt.dwColorSpaceHighValue = 0;
    dm16bpp->ddckCKSrcOverlay.dwColorSpaceLowValue = 0;
    dm16bpp->ddckCKSrcOverlay.dwColorSpaceHighValue = 0;
    dm16bpp->ddckCKSrcBlt.dwColorSpaceLowValue = 0;
    dm16bpp->ddckCKSrcBlt.dwColorSpaceHighValue = 0;
    dm16bpp->ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
    dm16bpp->ddpfPixelFormat.dwFlags = 0x40;
    dm16bpp->ddpfPixelFormat.dwFourCC = 0;
    dm16bpp->ddpfPixelFormat.dwRGBBitCount = 16;
    dm16bpp->ddpfPixelFormat.dwRBitMask = 0xf800;
    dm16bpp->ddpfPixelFormat.dwGBitMask = 0x07e0;
    dm16bpp->ddpfPixelFormat.dwBBitMask = 0x001f;
    dm16bpp->ddpfPixelFormat.dwRGBAlphaBitMask = 0;
    dm16bpp->ddsCaps.dwCaps = 0;
    g_dm16bpp800 = memblockIndex + 24 * sizeof(x86::reg32) + sizeof(DDSURFACEDESC);

    g_currentDisplayMode = g_dm16bpp800;
    return 24 * sizeof(x86::reg32) + 4*sizeof(DDSURFACEDESC);
}

}}
