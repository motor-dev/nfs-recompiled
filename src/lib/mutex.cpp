#include <lib/mutex.h>
#include <lib/thread.h>
#include <SDL2/SDL_mutex.h>

namespace win32
{

Mutex::Mutex(const char* name)
    :   m_mutex(SDL_CreateMutex())
    ,   m_name(name)
    ,   m_owner(0)
    ,   m_count(0)
{
}

Mutex::~Mutex()
{
    SDL_DestroyMutex(m_mutex);
}

void Mutex::lock()
{
    SDL_LockMutex(m_mutex);
    NFS2_ASSERT(m_owner == 0 || m_owner == Thread::currentThreadId());
    if (m_owner == 0)
    {
        NFS2_ASSERT(m_count == 0);
        m_count = 1;
        m_owner = Thread::currentThreadId();
    }
    else
    {
        m_count++;
    }
}

void Mutex::unlock()
{
    NFS2_ASSERT(m_owner == Thread::currentThreadId());
    if (--m_count == 0)
    {
        m_owner = 0;
    }
    SDL_UnlockMutex(m_mutex);
}

}
