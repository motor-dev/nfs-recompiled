#include <winapi/com.h>
#include <winapi/wrapper.h>
#include <winapi/ddraw/idirectdraw2.h>
#include <winapi/ddraw/idirectdrawpalette.h>
#include <winapi/ddraw/idirectdrawsurface.h>
#include <winapi/dinput/idirectinput2.h>
#include <winapi/dinput/idirectinputdevice.h>
#include <winapi/dsound/idirectsound.h>
#include <winapi/dsound/idirectsoundbuffer.h>
#include <winapi/dsound/idirectsound3dlistener.h>

namespace win32 { namespace com
{


static win32::MemMap* s_memory = nullptr;
static x86::reg32 s_firstFreeBlock = 0;

x86::reg32 ComAlloc(WinApplication* app)
{
    x86::reg32 result = s_firstFreeBlock;
    x86::reg32* memory = app->getMemory<x86::reg32>(result);
    s_firstFreeBlock = *memory;
    return result;
}

x86::reg32 ComGetIndex(WinApplication* app, const IUnknown* pointer)
{
    x86::reg32 offset = x86::reg32(reinterpret_cast<const x86::reg8*>(pointer) - app->getMemory<x86::reg8>(s_memory->getBlockStart()));
    return offset + s_memory->getBlockStart();
}

void ComFree(WinApplication* app, IUnknown* pointer)
{
    x86::reg32* memory = reinterpret_cast<x86::reg32*>(pointer);
    *memory = s_firstFreeBlock;
    x86::reg32 block = x86::reg32(reinterpret_cast<x86::reg8*>(memory) - app->getMemory<x86::reg8>(s_memory->getBlockStart()));
    s_firstFreeBlock = s_memory->getBlockStart() + block;
}

bool InitialiseComMemory(WinApplication* app)
{
    s_memory = new win32::MemMap(1024*1024*1);
    x86::reg32  blockOffset = 0;
    x86::reg8* blockStart = app->getMemory<x86::reg8>(s_memory->getBlockStart());
    x86::reg8* blockEnd = app->getMemory<x86::reg8>(s_memory->getBlockStart() + s_memory->getBlockSize()-1);
    blockOffset += IUnknown::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    blockOffset += ddraw::IDirectDraw2::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    blockOffset += ddraw::IDirectDrawPalette::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    blockOffset += ddraw::IDirectDrawSurface::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    blockOffset += dinput::IDirectInput2::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    blockOffset += dinput::IDirectInputDevice::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    blockOffset += dsound::IDirectSound::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    blockOffset += dsound::IDirectSoundBuffer::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    blockOffset += dsound::IDirectSound3DListener::init(app, s_memory->getBlockStart() + blockOffset, blockStart + blockOffset);
    s_firstFreeBlock = s_memory->getBlockStart() + blockOffset;
    const x86::reg32 blockSize = sizeof(IUnknown);
    for (x86::reg8* block = blockStart + blockOffset;
         block < blockEnd;
         block += blockSize, blockOffset += blockSize)
    {
        *reinterpret_cast<x86::reg32*>(block) = s_memory->getBlockStart() + blockOffset + blockSize;
    }

    return true;
}

x86::reg32 IUnknown::s_iUknownVtable = 0;

IUnknown::IUnknown(const GUID& interface)
    :   m_vtable(s_iUknownVtable)
    ,   m_interface(interface)
    ,   m_refCount(1)
{
}

BOOL IUnknown::QueryInterface(WinApplication* app, x86::CPU& cpu,
                              REFGUID refiid, x86::reg32* pvvObject)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    NFS2_USE(refiid);
    if (*refiid == m_interface)
    {
        *pvvObject = ComGetIndex(app, this);
        m_refCount ++;
        return 0;
    }
    else
    {
        *pvvObject = 0;
        //m_refCount ++;
        return 0x80004002;
    }
}

ULONG IUnknown::AddRef(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    return ++m_refCount;
}

ULONG IUnknown::Release(WinApplication* app, x86::CPU& cpu)
{
    NFS2_USE(app);
    NFS2_USE(cpu);
    ULONG result = --m_refCount;
    if (!result)
    {
        this->~IUnknown();
        com::ComFree(app, this);
    }
    return result;
}

x86::reg32 IUnknown::init(WinApplication* app, x86::reg32 memblockIndex, x86::reg8* memBlock)
{
    x86::reg32* vtable = reinterpret_cast<x86::reg32*>(memBlock);
    app->registerMethod(0x400000, {"IUnknown::QueryInterface", &Wrapper<decltype(&IUnknown::QueryInterface), &IUnknown::QueryInterface>::stdcall});
    app->registerMethod(0x400001, {"IUnknown::AddRef", &Wrapper<decltype(&IUnknown::AddRef), &IUnknown::AddRef>::stdcall});
    app->registerMethod(0x400002, {"IUnknown::Release", &Wrapper<decltype(&IUnknown::Release), &IUnknown::Release>::stdcall});

    s_iUknownVtable = memblockIndex;
    vtable[0] = 0x400000;    // IUnknown_QueryInterface
    vtable[1] = 0x400001;    // IUnknown_AddRef
    vtable[2] = 0x400002;    // IUnknwon_Release
    return 3 * sizeof(x86::reg32);
}

}}
