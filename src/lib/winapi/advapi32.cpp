#include <winapi/advapi32.h>
#include <lib/registry.h>
#include <x86.h>
#include <string>


namespace win32 { namespace advapi32
{

LSTATUS RegCloseKey(WinApplication* app, x86::CPU& cpu,
                    HKEY hKey)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hKey);
    return 0;
}

LSTATUS RegFlushKey(WinApplication* app, x86::CPU& cpu,
                    HKEY hKey)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(hKey);
    return 1;
}

LSTATUS RegOpenKeyExA(WinApplication* app, x86::CPU& cpu,
                      HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
    NFS2_USE(cpu);
    NFS2_USE(ulOptions);
    NFS2_USE(samDesired);
    RegistryKey* key = dynamic_cast<RegistryKey*>(app->getResource(hKey));
    if (key)
    {
        const char* subk = lpSubKey;
        while (*subk)
        {
            const char* subkEnd;
            for (subkEnd = subk; *subkEnd && *subkEnd != '\\'; ++subkEnd)
                /* nothing */;
            std::string subkey = std::string(subk, subkEnd);
            key = key->getChild(subkey);
            if (!key)
                return 1;
            subk = subkEnd;
            if (*subk) subk++;
        }
        *phkResult = key->getResourceIndex();
        return 0;
    }
    else
    {
        return 1;
    }
}

LSTATUS RegQueryValueExA(WinApplication* app, x86::CPU& cpu,
                         HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
    NFS2_USE(cpu);
    NFS2_USE(lpReserved);
    RegistryKey* key = dynamic_cast<RegistryKey*>(app->getResource(hKey));
    if (key)
    {
        RegistryValue* value = key->getValue(lpValueName);
        if (!value)
        {
            return 1;
        }
        else
        {
            return value->query(lpType, lpData, lpcbData);
        }
    }
    else
    {
        return 1;
    }
}


}}
