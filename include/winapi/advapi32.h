#ifndef advapi32_H_
#define advapi32_H_
#include <x86.h>
#include <winapi/types.h>

namespace win32 { class WinApplication; }

namespace win32 { namespace advapi32
{

typedef x86::reg32  HKEY;

LSTATUS RegCloseKey(WinApplication* app, x86::CPU& cpu,
                    HKEY hKey);
LSTATUS RegFlushKey(WinApplication* app, x86::CPU& cpu,
                    HKEY hKey);
LSTATUS RegOpenKeyExA(WinApplication* app, x86::CPU& cpu,
                      HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LSTATUS RegQueryValueExA(WinApplication* app, x86::CPU& cpu,
                         HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);

}}

#endif
