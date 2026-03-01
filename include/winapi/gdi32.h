#ifndef gdi32_H_
#define gdi32_H_

#include <x86.h>
#include <winapi/types.h>

namespace win32 { class WinApplication; }

namespace win32 { namespace gdi32
{

int GetDeviceCaps(WinApplication* app, x86::CPU& cpu, HDC hdc, int index);
HGDIOBJ GetStockObject(WinApplication* app, x86::CPU& cpu, int i);

}}

#endif
