#ifndef dinput_H_
#define dinput_H_

#include <x86.h>
#include <lib/winapp.h>
#include <winapi/types.h>

namespace win32 { namespace dinput
{

class IDirectInput2;

HRESULT DirectInputCreateA(WinApplication* app, x86::CPU& cpu,
                           HINSTANCE hinst, DWORD dwVersion, Packed<IDirectInput2>* lplpDirectInput,
                           LPVOID punkOuter);

}}

#endif
