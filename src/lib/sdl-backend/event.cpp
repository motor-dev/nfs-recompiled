#include <lib/event.h>
#include <lib/thread.h>
#include <SDL2/SDL_mutex.h>
#include <algorithm>

namespace win32
{

static SDL_mutex* s_mutex = nullptr;
static SDL_cond* s_condition = nullptr;

static const x86::sreg32 WAIT_TIMEOUT = 0x102;

static unsigned s_eventIndex = 0;

Event::Event(const char *name, bool manualReset, bool initialState)
    :   m_name(name ? name : "")
    ,   m_manualReset(manualReset)
    ,   m_isSet(initialState)
    ,   m_pulse(false)
    ,   m_id(s_eventIndex++)
{
}

Event::~Event()
{
}

void Event::init()
{
    s_mutex = SDL_CreateMutex();
    s_condition = SDL_CreateCond();
}

void Event::fini()
{
    SDL_DestroyCond(s_condition);
    SDL_DestroyMutex(s_mutex);
}

void Event::broadcastTerminate()
{
    SDL_LockMutex(s_mutex);
    SDL_CondBroadcast(s_condition);
    SDL_UnlockMutex(s_mutex);
}

void Event::set()
{
    SDL_LockMutex(s_mutex);
    //SDL_Log("Event set: %s<%u>", m_name.c_str(), m_id);
    m_pulse = false;
    m_isSet = true;
    SDL_CondBroadcast(s_condition);
    SDL_UnlockMutex(s_mutex);
}

x86::reg32 Event::pulse()
{
    SDL_LockMutex(s_mutex);
    //SDL_Log("Event pulse: %s<%u>", m_name.c_str(), m_id);
    if (!m_waitingThreads.empty())
    {
        m_pulse = true;
        m_isSet = true;
        SDL_CondBroadcast(s_condition);
    }
    SDL_UnlockMutex(s_mutex);
    return 1;
}

x86::reg32 Event::wait(x86::CPU& cpu, Event** begin, Event** end, bool waitAll, x86::sreg32 timeout)
{
    NFS2_ASSERT(!waitAll);
    SDL_LockMutex(s_mutex);
    x86::reg32 result = WAIT_TIMEOUT;
    for (Event** e = begin; e < end; ++e)
    {
        //SDL_Log("Event wait[%u]: %s<%u>", static_cast<unsigned>(e - begin), (*e)->m_name.c_str(), (*e)->m_id);
        (*e)->m_waitingThreads.push_back(Thread::currentThreadId());
    }
    for (;;)
    {
        for (Event** e = begin; e < end; ++e)
        {
            if ((*e)->m_isSet)
            {
                //SDL_Log("Event wait finished[%u]: %s<%u>", static_cast<unsigned>(e - begin), (*e)->m_name.c_str(), (*e)->m_id);
                if (result == WAIT_TIMEOUT)
                    result = static_cast<x86::reg32>(e - begin);
                if (!(*e)->m_manualReset)
                    (*e)->m_isSet = false;
            }
        }

        if (result != WAIT_TIMEOUT || timeout == 0)
        {
            break;
        }
        if (cpu.terminate)
        {
            result = x86::reg32(-1);
            break;
        }
        int event = SDL_CondWaitTimeout(s_condition, s_mutex, timeout);
        if (event == SDL_MUTEX_TIMEDOUT)
        {
            break;
        }
        else if (event < 0)
        {
            result = x86::reg32(-1);
            break;
        }
    }
    for (Event** e = begin; e < end; ++e)
    {
        (*e)->m_waitingThreads.erase(std::remove((*e)->m_waitingThreads.begin(),
                                                 (*e)->m_waitingThreads.end(),
                                                 Thread::currentThreadId()),
                                     (*e)->m_waitingThreads.end());
        if ((*e)->m_pulse && !(*e)->m_waitingThreads.empty())
            (*e)->m_isSet = false;
    }
    //SDL_Log("Event wait result: %d", result);
    SDL_UnlockMutex(s_mutex);
    return result;
}

}
