#ifndef shell32_H_
#define shell32_H_

#include <x86.h>
#include <winapi/types.h>

namespace win32 { class WinApplication; }

namespace win32 { namespace shell32
{

HINSTANCE ShellExecuteA(WinApplication* app, x86::CPU& cpu, HWND hwnd, LPCSTR lpOperation,
                        LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, int nShowCmd);

}}

#endif
