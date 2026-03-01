#ifndef DDRAW_IDIRECTDRAWSURFACE_H_
#define DDRAW_IDIRECTDRAWSURFACE_H_

#include <winapi/com.h>
#include <lib/renderer.h>

namespace win32 { namespace ddraw
{

struct DDSCAPS
{
    DWORD  dwCaps;
};
typedef DDSCAPS* LPDDSCAPS;

struct DDCOLORKEY
{
    DWORD dwColorSpaceLowValue;
    DWORD dwColorSpaceHighValue;
};
typedef DDCOLORKEY* LPDDCOLORKEY;

struct DDPIXELFORMAT
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwFourCC;
    union
    {
        DWORD  dwRGBBitCount;
        DWORD  dwYUVBitCount;
        DWORD  dwZBufferBitDepth;
        DWORD  dwAlphaBitDepth;
    };
    union
    {
        DWORD  dwRBitMask;
        DWORD  dwYBitMask;
    };
    union
    {
        DWORD  dwGBitMask;
        DWORD  dwUBitMask;
    };
    union
    {
        DWORD  dwBBitMask;
        DWORD  dwVBitMask;
    };
    union
    {
        DWORD  dwRGBAlphaBitMask;
        DWORD  dwYUVAlphaBitMask;
    };
};
typedef DDPIXELFORMAT* LPDDPIXELFORMAT;

struct DDSURFACEDESC
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwHeight;
    DWORD           dwWidth;
    union
    {
        LONG        lPitch;
        DWORD       dwLinearSize;
    };
    DWORD           dwBackBufferCount;
    union
    {
        DWORD       dwMipMapCount;
        DWORD       dwZBufferBitDepth;
        DWORD       dwRefreshRate;
    };
    DWORD           dwAlphaBitDepth;
    DWORD           dwReserved;
    Packed<void>    lpSurface;
    DDCOLORKEY      ddckCKDestOverlay;
    DDCOLORKEY      ddckCKDestBlt;
    DDCOLORKEY      ddckCKSrcOverlay;
    DDCOLORKEY      ddckCKSrcBlt;
    DDPIXELFORMAT   ddpfPixelFormat;
    DDSCAPS         ddsCaps;
};
typedef DDSURFACEDESC* LPDDSURFACEDESC;

class IDirectDrawClipper;
class IDirectDrawPalette;
class IDirectDraw2;

class IDirectDrawSurface : public com::IUnknown
{
public:
    IDirectDrawSurface();
    IDirectDrawSurface(WinApplication* app, DDSURFACEDESC* desc, Renderer* renderer, x86::reg32 surfaceIndex);

    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);

private:
    typedef IDirectDrawSurface* LPDIRECTDRAWSURFACE;
    typedef IDirectDrawSurface* LPDIRECTDRAWSURFACE2;
    typedef IDirectDrawClipper* LPDIRECTDRAWCLIPPER;
    typedef IDirectDrawPalette* LPDIRECTDRAWPALETTE;
    typedef IDirectDraw2* LPDIRECTDRAW;

    struct DDBLTFX
    {
        DWORD dwSize;
        DWORD dwDDFX;
        DWORD dwROP;
        DWORD dwDDROP;
        DWORD dwRotationAngle;
        DWORD dwZBufferOpCode;
        DWORD dwZBufferLow;
        DWORD dwZBufferHigh;
        DWORD dwZBufferBaseDest;
        DWORD dwZDestConstBitDepth;
        union
        {
            DWORD                       dwZDestConst;
            Packed<IDirectDrawSurface>  lpDDSZBufferDest;
        };
        DWORD dwZSrcConstBitDepth;
        union
        {
            DWORD                       dwZSrcConst;
            Packed<IDirectDrawSurface>  lpDDSZBufferSrc;
        };
        DWORD dwAlphaEdgeBlendBitDepth;
        DWORD dwAlphaEdgeBlend;
        DWORD dwReserved;
        DWORD dwAlphaDestConstBitDepth;
        union
        {
            DWORD                       dwAlphaDestConst;
            Packed<IDirectDrawSurface>  lpDDSAlphaDest;
        };
        DWORD dwAlphaSrcConstBitDepth;
        union
        {
            DWORD                       dwAlphaSrcConst;
            Packed<IDirectDrawSurface>  lpDDSAlphaSrc;
        };
        union
        {
            DWORD                       dwFillColor;
            DWORD                       dwFillDepth;
            DWORD                       dwFillPixel;
            Packed<IDirectDrawSurface>  lpDDSPattern;
        };
        DDCOLORKEY ddckDestColorkey;
        DDCOLORKEY ddckSrcColorkey;
    };
    typedef DDBLTFX* LPDDBLTFX;

    struct DDBLTBATCH
    {
        Packed<RECT>                  lprDest;
        Packed<IDirectDrawSurface>    lpDDSSrc;
        Packed<RECT>                  lprSrc;
        DWORD                         dwFlags;
        Packed<DDBLTFX>               lpDDBltFx;
    };
    typedef DDBLTBATCH* LPDDBLTBATCH;

    struct DDOVERLAYFX
    {
        DWORD       dwSize;
        DWORD       dwAlphaEdgeBlendBitDepth;
        DWORD       dwAlphaEdgeBlend;
        DWORD       dwReserved;
        DWORD       dwAlphaDestConstBitDepth;
        union
        {
            DWORD                       dwAlphaDestConst;
            Packed<IDirectDrawSurface>  lpDDSAlphaDest;
        };
        DWORD       dwAlphaSrcConstBitDepth;
        union
        {
            DWORD                       dwAlphaSrcConst;
            Packed<IDirectDrawSurface>  lpDDSAlphaSrc;
        };
        DDCOLORKEY  dckDestColorkey;
        DDCOLORKEY  dckSrcColorkey;
        DWORD       dwDDFX;
        DWORD       dwFlags;
    };
    typedef DDOVERLAYFX* LPDDOVERLAYFX;

    typedef x86::reg32 LPDDENUMSURFACESCALLBACK;

    BOOL QueryInterface(WinApplication* app, x86::CPU& cpu,
                        REFGUID refiid, x86::reg32* pvvObject);
    HRESULT AddAttachedSurface(WinApplication* app, x86::CPU& cpu,
                               LPDIRECTDRAWSURFACE2 lpDDSAttachedSurface);
    HRESULT AddOverlayDirtyRect(WinApplication* app, x86::CPU& cpu,
                                LPRECT lpRect);
    HRESULT Blt(WinApplication* app, x86::CPU& cpu,
                LPRECT lpDestRect, LPDIRECTDRAWSURFACE2 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx);
    HRESULT BltBatch(WinApplication* app, x86::CPU& cpu,
                     LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags);
    HRESULT BltFast(WinApplication* app, x86::CPU& cpu,
                    DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE2 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans);
    HRESULT DeleteAttachedSurface(WinApplication* app, x86::CPU& cpu,
                                  DWORD dwFlags, LPDIRECTDRAWSURFACE2 lpDDSAttachedSurface);
    HRESULT EnumAttachedSurfaces(WinApplication* app, x86::CPU& cpu,
                                 LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback);
    HRESULT EnumOverlayZOrders(WinApplication* app, x86::CPU& cpu,
                               DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback);
    HRESULT Flip(WinApplication* app, x86::CPU& cpu,
                 LPDIRECTDRAWSURFACE2 lpDDSurfaceTargetOverride, DWORD dwFlags);
    HRESULT GetAttachedSurface(WinApplication* app, x86::CPU& cpu,
                               LPDDSCAPS lpDDSCaps, Packed<LPDIRECTDRAWSURFACE2> *lplpDDAttachedSurface);
    HRESULT GetBltStatus(WinApplication* app, x86::CPU& cpu,
                         DWORD dwFlags);
    HRESULT GetCaps(WinApplication* app, x86::CPU& cpu,
                    LPDDSCAPS lpDDSCaps);
    HRESULT GetClipper(WinApplication* app, x86::CPU& cpu,
                       Packed<LPDIRECTDRAWCLIPPER> lplpDDClipper);
    HRESULT GetColorKey(WinApplication* app, x86::CPU& cpu,
                        DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
    HRESULT GetDC(WinApplication* app, x86::CPU& cpu,
                  HDC *lphDC);
    HRESULT GetFlipStatus(WinApplication* app, x86::CPU& cpu,
                          DWORD dwFlags);
    HRESULT GetOverlayPosition(WinApplication* app, x86::CPU& cpu,
                               LPLONG lplX, LPLONG lplY);
    HRESULT GetPalette(WinApplication* app, x86::CPU& cpu,
                       Packed<LPDIRECTDRAWPALETTE> lplpDDPalette);
    HRESULT GetPixelFormat(WinApplication* app, x86::CPU& cpu,
                           LPDDPIXELFORMAT lpDDPixelFormat);
    HRESULT GetSurfaceDesc(WinApplication* app, x86::CPU& cpu,
                           LPDDSURFACEDESC lpDDSurfaceDesc);
    HRESULT Initialize(WinApplication* app, x86::CPU& cpu,
                       LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc);
    HRESULT IsLost(WinApplication* app, x86::CPU& cpu);
    HRESULT Lock(WinApplication* app, x86::CPU& cpu,
                 LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
    HRESULT ReleaseDC(WinApplication* app, x86::CPU& cpu,
                      HDC hDC);
    HRESULT Restore(WinApplication* app, x86::CPU& cpu);
    HRESULT SetClipper(WinApplication* app, x86::CPU& cpu,
                       LPDIRECTDRAWCLIPPER lpDDClipper);
    HRESULT SetColorKey(WinApplication* app, x86::CPU& cpu,
                        DWORD dwFlags, LPDDCOLORKEY lpDDColorKey);
    HRESULT SetOverlayPosition(WinApplication* app, x86::CPU& cpu,
                               LONG lX, LONG lY);
    HRESULT SetPalette(WinApplication* app, x86::CPU& cpu,
                       LPDIRECTDRAWPALETTE lpDDPalette);
    HRESULT Unlock(WinApplication* app, x86::CPU& cpu,
                   LPVOID lpSurfaceData);
    HRESULT UpdateOverlay(WinApplication* app, x86::CPU& cpu,
                          LPRECT lpSrcRect, LPDIRECTDRAWSURFACE2 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx);
    HRESULT UpdateOverlayDisplay(WinApplication* app, x86::CPU& cpu,
                                 DWORD dwFlags);
    HRESULT UpdateOverlayZOrder(WinApplication* app, x86::CPU& cpu,
                                DWORD dwFlags, LPDIRECTDRAWSURFACE2 lpDDSReference);
    HRESULT GetDDInterface(WinApplication* app, x86::CPU& cpu,
                           Packed<LPVOID> lplpDD);
    HRESULT PageLock(WinApplication* app, x86::CPU& cpu,
                     DWORD dwFlags);
    HRESULT PageUnlock(WinApplication* app, x86::CPU& cpu,
                       DWORD dwFlags);

private:
    const void* getPointer(WinApplication* app) const;

private:
    static x86::reg32 s_iDirectDrawSurfaceVtable;
};

}}

#endif /*!DDRAW_IDIRECTDRAWSURFACE_H_*/
