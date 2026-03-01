#ifndef DDRAW_IDIRECTDRAWPALETTE_H_
#define DDRAW_IDIRECTDRAWPALETTE_H_

#include <winapi/com.h>
#include <lib/palette.h>


namespace win32 { namespace ddraw
{

enum
{
    DDPCAPS_4BIT                = 0x0001,
    DDPCAPS_8BITENTRIES         = 0x0002,
    DDPCAPS_8BIT                = 0x0004,
    DDPCAPS_INITIALIZE          = 0x0008,
    DDPCAPS_PRIMARYSURFACE      = 0x0010,
    DDPCAPS_PRIMARYSURFACELEFT  = 0x0020,
    DDPCAPS_ALLOW256            = 0x0040,
    DDPCAPS_VSYNC               = 0x0080,
    DDPCAPS_1BIT                = 0x0100,
    DDPCAPS_2BIT                = 0x0200,
    DDPCAPS_ALPHA               = 0x0400
};

class IDirectDrawPalette : public com::IUnknown
{
public:
    IDirectDrawPalette(WinApplication* app, Renderer *renderer, x86::reg32 flags, const PALETTEENTRY* entries);

    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);

private:
    static void GetCaps(WinApplication* app, x86::CPU& cpu);
    static void GetEntries(WinApplication* app, x86::CPU& cpu);
    static void Initialize(WinApplication* app, x86::CPU& cpu);
    HRESULT SetEntries(WinApplication* app, x86::CPU& cpu,
                       DWORD dwFlags, DWORD dwStartingEntry, DWORD dwCount, LPPALETTEENTRY lpEntries);

private:
    static x86::reg32 s_iDirectDrawPaletteVtable;
};

}}

#endif /*!DDRAW_IDIRECTDRAWPALETTE_H_*/
