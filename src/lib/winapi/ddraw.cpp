#include <winapi/ddraw.h>
#include <winapi/com.h>
#include <winapi/ddraw/idirectdraw2.h>
#include <x86.h>
#include <lib/memmap.h>
#include <lib/library.h>
#include <winapi/wrapper.h>


namespace win32 { namespace ddraw
{


HRESULT DirectDrawCreate(WinApplication* app, x86::CPU& cpu,
                         GUID* lpGUID, x86::reg32* lplpDD, void* pUnkOuter)
{
    NFS2_USE(cpu);
    NFS2_USE(lpGUID);
    static bool s_init = com::InitialiseComMemory(app);
    NFS2_USE(s_init);
    NFS2_ASSERT(pUnkOuter == nullptr);
    *lplpDD = com::ComAlloc(app);
    new (&app->getMemory<IDirectDraw2>(*lplpDD)) IDirectDraw2();
    return 0;
}

HRESULT DirectDrawEnumerateA(WinApplication* app, x86::CPU& cpu,
                             x86::reg32 lpCallback, x86::reg32 lpCallbackParam)
{
    cpu.esp -= 20;
    app->getMemory<x86::reg32>(cpu.esp + 0) = lpCallback;
    app->getMemory<x86::reg32>(cpu.esp + 4) = 0;
    app->getMemory<x86::reg32>(cpu.esp + 8) = 0;
    app->getMemory<x86::reg32>(cpu.esp + 12) = 0;
    app->getMemory<x86::reg32>(cpu.esp + 16) = lpCallbackParam;
    app->dynamic_call(lpCallback, cpu);
    return 0;
}

Library s_dDrawLibrary = win32::Library("ddraw.dll");
Library* s_dDrawRegistry = &(s_dDrawLibrary
    .registerSymbol("DirectDrawCreate", &Wrapper<decltype(&DirectDrawCreate), &DirectDrawCreate>::stdcall));

}}
