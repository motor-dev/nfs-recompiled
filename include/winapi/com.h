#ifndef WINAPI_COM_H_
#define WINAPI_COM_H_

#include <lib/winapp.h>
#include <winapi/types.h>

namespace win32 { namespace com
{

#define DEFINE_GUID(NAME, DW, W1, W2, B1, B2, B3, B4, B5, B6, B7, B8)   \
    static const GUID NAME = { DW, W1, W2, { B1, B2, B3, B4, B5, B6, B7, B8 }};

class IUnknown;

x86::reg32 ComAlloc(WinApplication* app);
x86::reg32 ComGetIndex(WinApplication* app, const IUnknown* pointer);

bool InitialiseComMemory(WinApplication* app);

class IUnknown
{
public:
    static x86::reg32 init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock);

    ULONG AddRef(WinApplication* app, x86::CPU& cpu);
    ULONG Release(WinApplication* app, x86::CPU& cpu);

protected:
    IUnknown(const GUID& guid);

protected:
    x86::reg32          m_vtable;
    GUID                m_interface;
    x86::reg32          m_refCount;
    GenericResource*    m_resource;

protected:
    typedef IUnknown*   LPUNKNOWN;
    typedef const GUID* REFGUID;
    typedef GUID*       LPGUID;

protected:
    BOOL  QueryInterface(WinApplication* app, x86::CPU& cpu, REFGUID riid, x86::reg32* pvvObject);

private:
    static x86::reg32 s_iUknownVtable;
};

}}

#endif /*!WINAPI_COM_H_*/
