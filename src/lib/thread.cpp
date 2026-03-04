#include <lib/thread.h>
#include <lib/event.h>
#include <lib/window.h>
#include <SDL3/SDL.h>

namespace win32
{

SDL_AtomicU32 s_threadCount = {1};
thread_local x86::reg32 s_threadId = 1;

Thread::Data::Data(WinApplication* app, x86::reg32 entryPoint, x86::reg32 parameter, x86::reg32 flags)
    :   m_app(app)
    ,   m_entryPoint(entryPoint)
    ,   m_parameter(parameter)
    ,   m_flags(flags)
    ,   m_threadId(1 + SDL_AddAtomicU32(&s_threadCount, 1))
{
}

Thread::Thread()
    :   m_refCount(new SDL_AtomicInt())
    ,   m_semaphore(0)
    ,   m_data(0, 0, 0, 0)
    ,   m_thread(0)
{
    m_refCount->value = 1;
}

Thread::Thread(const Thread& other)
    :   m_refCount(other.m_refCount)
    ,   m_semaphore(other.m_semaphore)
    ,   m_data(0, 0, 0, 0)
    ,   m_thread(other.m_thread)
{
    SDL_AtomicIncRef(m_refCount);
}

Thread::Thread(WinApplication *app, x86::reg32 method, x86::reg32 parameter, x86::reg32 flags)
    :   m_refCount(new SDL_AtomicInt())
    ,   m_semaphore(SDL_CreateSemaphore((flags & 0x4) ? 0 : 1))
    ,   m_data(app, method, parameter, flags)
    ,   m_thread(SDL_CreateThread(&run, "thread", this))
{
    m_refCount->value = 1;
}

Thread::~Thread()
{
    if (SDL_AtomicDecRef(m_refCount))
    {
        delete m_refCount;
        if (m_thread)
        {
            terminate();
        }
    }
}

void Thread::resume()
{
      SDL_SignalSemaphore(m_semaphore);
}

x86::reg32 Thread::currentThreadId()
{
    return s_threadId;
}
 
void Thread::terminate()
{
    m_cpu.terminate = true;
    Event::broadcastTerminate();
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Waiting for thread 0x%x", m_data.m_threadId);
    SDL_Event event;
    event.type = g_userEvent2;
    event.user.code = 0;
    event.user.data1 = reinterpret_cast<void*>(static_cast<uintptr_t>(m_data.m_threadId));
    event.user.data2 = 0;
    event.user.windowID = 0;
    SDL_PushEvent(&event);
    SDL_WaitThread(m_thread, nullptr);
    m_thread = nullptr;
}

x86::reg32 Thread::threadId() const
{
    return m_data.m_threadId;
}

void Thread::sleep(x86::reg32 milliseconds)
{
    SDL_Delay(milliseconds);
}

int Thread::run(void* data)
{
    Thread* thread = (Thread*)data;
    s_threadId = thread->m_data.m_threadId;
    if (thread->m_semaphore)
    {
        SDL_WaitSemaphore(thread->m_semaphore);
        SDL_DestroySemaphore(thread->m_semaphore);
        thread->m_semaphore = nullptr;
    }
    return thread->m_data.m_app->runThread(thread->m_cpu, thread->m_data.m_entryPoint, thread->m_data.m_parameter);
}

}

