#include <lib/winapp.h>
#include <lib/mutex.h>
#include <lib/event.h>
#include <lib/library.h>
#include <lib/registry.h>
#include <winapi/types.h>
#include <SDL_timer.h>
#include <SDL_atomic.h>
#include <SDL_mutex.h>
#include <x86.h>

#include <winapi/dsetup.h>
#include <winapi/ddraw.h>
#include <winapi/glide2x.h>
#include <algorithm>

namespace win32
{

static x86::reg32 s_resourceIndex;
static SDL_atomic_t s_resourceCount;

GenericResource::GenericResource()
    :   m_resourceIndex(0)
{
    SDL_AtomicAdd(&s_resourceCount, 1);
}

GenericResource::~GenericResource()
{
    NFS2_ASSERT(m_resourceIndex == 0);
    SDL_AtomicAdd(&s_resourceCount, -1);
}

void GenericResource::setResourceIndex(x86::reg32 resourceIndex)
{
    NFS2_ASSERT(!resourceIndex || !m_resourceIndex);
    m_resourceIndex = resourceIndex;
}

x86::reg32 GenericResource::getResourceIndex() const
{
    return m_resourceIndex;
}


WinApplication::WinApplication(const char* appName, x86::reg32 baseAddress, const std::vector<Section>& sections)
    :   m_memory(MemMap::init(baseAddress, sections))
    ,   m_appName(new MemMap(4096))
    ,   m_appNameW(new MemMap(4096))
    ,   m_env(new MemMap(4096))
    ,   m_executionContext(new Mutex("ExecutionContext"))
    ,   m_resourceContext(new Mutex("Resource"))
{
    /*m_methods = new Method[sections[0].size+sections[0].baseAddress - 0x400000];
    memset(m_methods, 0, sizeof(Method)*(sections[0].size+sections[0].baseAddress - 0x400000));*/
    memset(&m_cpu, 0, sizeof(m_cpu));
    dsetup::s_dSetupRegistry->registerSymbols(this);
    ddraw::s_dDrawRegistry->registerSymbols(this);
    glide2x::s_glide2xRegistry->registerSymbols(this);
    Event::init();
    strcpy(&getMemory<char>(m_appName->getBlockStart()), appName);
    strcat(&getMemory<char>(m_appName->getBlockStart()), " -modes");
    getMemory<char>(m_env->getBlockStart()) = 0;
    WCHAR* wchar = &getMemory<WCHAR>(m_appNameW->getBlockStart());
    *wchar++ = 0xfffe;
    for (const char* appNameW = appName; *appNameW; ++wchar, ++appNameW)
    {
        *wchar = WCHAR(*appNameW);
    }
    *wchar = 0;
    allocateResourceFixed(new RegistryKey(), HKEY_CLASSES_ROOT);
    allocateResourceFixed(new RegistryKey(), HKEY_CURRENT_USER);
    allocateResourceFixed(new RegistryKey(), HKEY_LOCAL_MACHINE);
    allocateResourceFixed(new RegistryKey(), HKEY_USERS);
    allocateResourceFixed(new RegistryKey(), HKEY_PERFORMANCE_DATA);
    allocateResourceFixed(new RegistryKey(), HKEY_PERFORMANCE_TEXT);
    allocateResourceFixed(new RegistryKey(), HKEY_PERFORMANCE_NLSTEXT);
    allocateResourceFixed(new RegistryKey(), HKEY_CURRENT_CONFIG);
    allocateResourceFixed(new RegistryKey(), HKEY_DYN_DATA);
}

WinApplication::~WinApplication()
{
    delete m_appNameW;
    delete m_appName;
    m_resourceContext->lock();
    for (std::map<x86::reg32, GenericResource*>::const_iterator it = m_resources.begin();
        it != m_resources.end();
        it = m_resources.erase(it))
    {
        it->second->setResourceIndex(0);
        delete it->second;
    }
    m_resourceContext->unlock();
    Event::fini();
    MemMap::fini();
    delete m_resourceContext;
    delete m_executionContext;
    /*delete[] m_methods;*/
    NFS2_ASSERT(SDL_AtomicGet(&s_resourceCount) == 0);
}

void WinApplication::addRegistryKey(x86::reg32 root, const char* keyname, const char* valuename, RegistryValue* value)
{
    RegistryKey* key = dynamic_cast<RegistryKey*>(getResource(root));
    NFS2_ASSERT(key);
    const char* subk = keyname;
    while (*subk)
    {
        const char* subkEnd;
        for (subkEnd = subk; *subkEnd && *subkEnd != '\\'; ++subkEnd)
            /* nothing */;
        std::string subkey = std::string(subk, subkEnd);
        RegistryKey* newkey = key->getChild(subkey);
        if (!newkey)
        {
            newkey = new RegistryKey();
            allocateResource(newkey);
            key->addChild(subkey, newkey);
        }
        key = newkey;
        subk = subkEnd;
        if (*subk) subk++;
    }
    allocateResource(value);
    key->addValue(valuename, value);
}

x86::reg32 WinApplication::allocateResourceFixed(GenericResource *resource, x86::reg32 fixedHandle)
{
    NFS2_ASSERT((fixedHandle < 0x20000) || (fixedHandle > 0x20000 + 0x30000));
    m_resourceContext->lock();
    resource->setResourceIndex(fixedHandle);
    bool inserted = m_resources.insert(std::make_pair(fixedHandle, resource)).second;
    NFS2_ASSERT(inserted);
    m_resourceContext->unlock();
    return fixedHandle;
}

x86::reg32 WinApplication::allocateResource(GenericResource *resource)
{
    m_resourceContext->lock();
    x86::reg32 resourceIndex = ++s_resourceIndex + 0x20000;
    resource->setResourceIndex(resourceIndex);
    bool inserted = m_resources.insert(std::make_pair(resourceIndex, resource)).second;
    NFS2_ASSERT(inserted);
    m_resourceContext->unlock();
    return resourceIndex;
}

GenericResource* WinApplication::getResource(x86::reg32 resource)
{
    GenericResource* result = nullptr;
    m_resourceContext->lock();
    std::map<x86::reg32, GenericResource*>::iterator it = m_resources.find(resource);
    if (it != m_resources.end())
    {
        result = it->second;
    }
    else
    {
        result = nullptr;
    }
    m_resourceContext->unlock();
    return result;
}

void WinApplication::freeResource(x86::reg32 resource)
{
    if (resource != 0xffffffff)
    {
        m_resourceContext->lock();
        std::map<x86::reg32, GenericResource*>::iterator it = m_resources.find(resource);
        NFS2_ASSERT(it != m_resources.end());
        it->second->setResourceIndex(0);
        delete it->second;
        m_resources.erase(it);
        m_resourceContext->unlock();
    }
}

void WinApplication::registerMethod(x86::reg32 pointer, Method method)
{
    NFS2_ASSERT(m_methods.find(pointer-0x400000) == m_methods.end());
    m_methods[pointer-0x400000] = method;
}

int WinApplication::runThread(x86::CPU& cpu, x86::reg32 entryPoint, x86::reg32 parameter, bool threadLock)
{
    if (!m_cpu.terminate)
    {
        win32::MemMap threadStorage(4096);
        win32::MemMap threadStack(1024 * 1024);
        cpu.init(threadStorage.getBlockStart(), entryPoint);
        getMemory<Mutex*>(cpu.efs + 8) = threadLock ? m_executionContext : nullptr;
        LockContext ctx(*this, cpu);
        cpu.esp = threadStack.getBlockStart() + threadStack.getBlockSize() - 8;
        getMemory<x86::reg32>(cpu.esp + 4) = parameter;
        getMemory<x86::reg32>(cpu.esp) = cpu.ip;
        dynamic_call(entryPoint, cpu);
        return int(cpu.eax);
    }
    else
    {
        return 0;
    }
}

void WinApplication::lockContext(const x86::CPU& cpu)
{
    Mutex* executionContext = getMemory<Mutex*>(cpu.efs + 8);
    NFS2_ASSERT(executionContext);
    if (executionContext)
    {
        executionContext->lock();
    }
}

void WinApplication::unlockContext(const x86::CPU& cpu)
{
    Mutex* executionContext = getMemory<Mutex*>(cpu.efs + 8);
    NFS2_ASSERT(executionContext);
    if (executionContext)
    {
        executionContext->unlock();
    }
}

void WinApplication::unmarkContext(const x86::CPU& cpu)
{
    Mutex* executionContext = getMemory<Mutex*>(cpu.efs + 8);
    if (executionContext)
    {
        executionContext->unlock();
        getMemory<Mutex*>(cpu.efs + 8) = nullptr;
    }
    else
    {
        NFS2_ASSERT(false);
    }
}

void WinApplication::terminate()
{
    m_cpu.terminate = true;
}

}
