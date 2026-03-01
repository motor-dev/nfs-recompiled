#ifndef ole32_H_
#define ole32_H_

#include <x86.h>
#include <winapi/types.h>

namespace win32 { class WinApplication; }

namespace win32 { namespace ole32
{

HRESULT CoCreateGuid(WinApplication* app, x86::CPU& cpu, GUID *pguid);

}}

#endif
