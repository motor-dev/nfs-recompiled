#ifndef dsound_H_
#define dsound_H_

#include <x86.h>
#include <lib/winapp.h>
#include <winapi/types.h>

namespace win32 { namespace dsound
{

class IDirectSound;

HRESULT DirectSoundCreate(WinApplication* app, x86::CPU& cpu,
                          GUID* lpGuid, Packed<IDirectSound>* ppDS, LPVOID punkOuter);

}}

#endif
