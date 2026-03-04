#include <lib/timer.h>
#include <time.h>
#ifdef _WIN32
# define localtime_r(a,b)  localtime_s(b,a)
#endif

namespace win32
{

void getSystemTime(SYSTEMTIME* systemTime)
{
    time_t now;
    struct tm localTime;
    time(&now);
    localtime_r(&now, &localTime);
    systemTime->wYear = localTime.tm_year;
    systemTime->wMonth = localTime.tm_mon+1;
    systemTime->wDayOfWeek = localTime.tm_wday;
    systemTime->wDay = localTime.tm_mday;
    systemTime->wHour = localTime.tm_hour;
    systemTime->wMinute = localTime.tm_min;
    systemTime->wSecond = localTime.tm_sec;
    systemTime->wMilliseconds = 0;
}

x86::reg32 timeGetTickCount()
{
    x86::reg32 result = (x86::reg32)SDL_GetTicks();
    return result;
}

Timer::Timer(x86::reg32 delay, WinApplication* app, x86::reg32 proc, x86::reg32 param)
    :   m_app(app)
    ,   m_callback(proc)
    ,   m_parameter(param)
    ,   m_id(SDL_AddTimer(delay, &timerCallback, this))
{
    //SDL_Log("Started timer %d (%d ms)", m_id, delay);
}

Timer::~Timer()
{
    cancel();
}

void Timer::cancel()
{
    SDL_RemoveTimer(m_id);
}

Uint32 Timer::timerCallback(void* data, SDL_TimerID /*timerID*/, Uint32 interval)
{
    NFS2_USE(interval);
    Timer* t = (Timer*)data;
    x86::CPU cpu;
    //SDL_Log("Timer callback: %d", t->m_id);
    t->m_app->runThread(cpu, t->m_callback, t->m_parameter);
    //SDL_Log("Timer callback done: %d", t->m_id);
    return 0;
}

}
