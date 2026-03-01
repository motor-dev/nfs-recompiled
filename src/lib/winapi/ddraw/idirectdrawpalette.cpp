#include <winapi/ddraw/idirectdrawpalette.h>
#include <winapi/wrapper.h>
#include <lib/palette.h>

namespace win32 { namespace ddraw
{

x86::reg32 IDirectDrawPalette::s_iDirectDrawPaletteVtable = 0;

DEFINE_GUID( IID_IDirectDrawPalette,	0x6C14DB84,0xA733,0x11CE,0xA5,0x21,0x00,0x20,0xAF,0x0B,0xE5,0x60 );

IDirectDrawPalette::IDirectDrawPalette(WinApplication* app, Renderer* renderer, x86::reg32 flags, const PALETTEENTRY* entries)
    :   IUnknown(IID_IDirectDrawPalette)
{
    m_vtable = s_iDirectDrawPaletteVtable;
    x86::reg32 entryCount = 1;
    NFS2_ASSERT(!(flags & DDPCAPS_8BITENTRIES));
    NFS2_ASSERT(!(flags & DDPCAPS_ALPHA));
    NFS2_ASSERT(!(flags & DDPCAPS_PRIMARYSURFACE));
    NFS2_ASSERT(!(flags & DDPCAPS_PRIMARYSURFACELEFT));
    NFS2_ASSERT(!(flags & DDPCAPS_VSYNC));
    if (flags & DDPCAPS_1BIT)
        entryCount = 2;
    else if (flags & DDPCAPS_2BIT)
        entryCount = 4;
    else if (flags & DDPCAPS_4BIT)
        entryCount = 16;
    else if (flags & DDPCAPS_8BIT || flags & DDPCAPS_ALLOW256)
        entryCount = 256;
    m_resource = new Palette(renderer, entries, entryCount);
    app->allocateResource(m_resource);
}

void IDirectDrawPalette::GetCaps(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDrawPalette::GetEntries(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

void IDirectDrawPalette::Initialize(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_ASSERT(false);
}

HRESULT IDirectDrawPalette::SetEntries(WinApplication* app, x86::CPU& cpu,
                                       DWORD dwFlags, DWORD dwStartingEntry, DWORD dwCount, LPPALETTEENTRY lpEntries)
{
    NFS2_USE(cpu);
    NFS2_USE(app);
    NFS2_ASSERT(dwFlags == 0);
    Palette* palette = dynamic_cast<Palette*>(m_resource);
    palette->setEntries(lpEntries, dwStartingEntry, dwCount);
    return 0;
}

x86::reg32 IDirectDrawPalette::init(WinApplication *app, x86::reg32 memblockIndex, x86::reg8* memBlock)
{
    x86::reg32* vtable = reinterpret_cast<x86::reg32*>(memBlock);
    app->registerMethod(0x400019, {"IDirectDrawPalette::GetCaps", &Wrapper<decltype(&IDirectDrawPalette::GetCaps), &IDirectDrawPalette::GetCaps>::stdcall});
    app->registerMethod(0x40001a, {"IDirectDrawPalette::GetEntries", &Wrapper<decltype(&IDirectDrawPalette::GetEntries), &IDirectDrawPalette::GetEntries>::stdcall});
    app->registerMethod(0x40001b, {"IDirectDrawPalette::Initialize", &Wrapper<decltype(&IDirectDrawPalette::Initialize), &IDirectDrawPalette::Initialize>::stdcall});
    app->registerMethod(0x40001c, {"IDirectDrawPalette::SetEntries", &Wrapper<decltype(&IDirectDrawPalette::SetEntries), &IDirectDrawPalette::SetEntries>::stdcall});

    s_iDirectDrawPaletteVtable = memblockIndex;
    vtable[0] = 0x400000;    // IUnknown_QueryInterface
    vtable[1] = 0x400001;    // IUnknown_AddRef
    vtable[2] = 0x400002;    // IUnknwon_Release
    vtable[3] = 0x400019;    // IDirectDrawPalette_GetCaps
    vtable[4] = 0x40001a;    // IDirectDrawPalette_GetEntries
    vtable[5] = 0x40001b;    // IDirectDrawPalette_Initialize
    vtable[6] = 0x40001c;    // IDirectDrawPalette_SetEntries
    return 7 * sizeof(x86::reg32);
}

}}
