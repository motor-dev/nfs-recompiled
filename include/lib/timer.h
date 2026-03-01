#ifndef LIB_TIMER_H_
#define LIB_TIMER_H_

#include <lib/winapp.h>
#include <winapi/types.h>
#include <SDL2/SDL_timer.h>

namespace win32
{

void getSystemTime(SYSTEMTIME* systemTime);
x86::reg32 timeGetTickCount();

class Timer : public GenericResource
{
public:
    Timer(x86::reg32 delay, WinApplication* app, x86::reg32 proc, x86::reg32 param);
    ~Timer();

    void cancel();
private:
    static Uint32 timerCallback(Uint32 interval, void* data);

private:
    WinApplication* m_app;
    x86::reg32      m_callback;
    x86::reg32      m_parameter;
    SDL_TimerID     m_id;
};

}

#endif

