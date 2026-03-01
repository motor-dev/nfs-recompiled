#ifndef ddraw_H_
#define ddraw_H_

#include <x86.h>
#include <winapi/types.h>

namespace win32
{

class WinApplication;
class Library;

}

namespace win32 { namespace ddraw
{

HRESULT DirectDrawCreate(WinApplication* app, x86::CPU& cpu,
                         GUID* lpGUID, x86::reg32* lplpDD, void* pUnkOuter);
HRESULT DirectDrawEnumerateA(WinApplication* app, x86::CPU& cpu,
                             x86::reg32 lpCallback, x86::reg32 lpCallbackParam);

extern Library* s_dDrawRegistry;

}}

#endif
