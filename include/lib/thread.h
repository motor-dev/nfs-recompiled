#ifndef LIB_THREAD_H_
#define LIB_THREAD_H_

#include <lib/winapp.h>
#include <SDL2/SDL_mutex.h>
#include <SDL2/SDL_atomic.h>

struct SDL_Thread;

namespace win32
{

class Thread : public GenericResource
{
public:
    Thread();
    Thread(WinApplication* app, x86::reg32 method, x86::reg32 parameter, x86::reg32 flags);
    ~Thread();

    Thread* duplicate()
    {
        return new Thread(*this);
    }

    void resume();
    void terminate();
    x86::reg32 threadId() const;
    static void sleep(x86::reg32 milliseconds);
    static x86::reg32 currentThreadId();

private:
    Thread(const Thread& other);
    static int run(void* parameter);

private:
    struct Data
    {
        Data(WinApplication* app, x86::reg32 entryPoint, x86::reg32 parameter, x86::reg32 flags);
        WinApplication* m_app;
        x86::reg32      m_entryPoint;
        x86::reg32      m_parameter;
        x86::reg32      m_flags;
    };

    SDL_atomic_t*   m_refCount;
    SDL_sem*        m_semaphore;
    Data            m_data;
    SDL_Thread*     m_thread;
    x86::CPU        m_cpu;
};

}

#endif

