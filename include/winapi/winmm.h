#ifndef winmm_H_
#define winmm_H_

#include <x86.h>
#include <winapi/types.h>

namespace win32 { class WinApplication; }

namespace win32 { namespace winmm
{

typedef x86::reg32 MMRESULT;
struct TIMECAPS
{
    UINT wPeriodMin;
    UINT wPeriodMax;
};
typedef TIMECAPS*   LPTIMECAPS;
typedef x86::reg32  LPTIMECALLBACK;


UINT joyGetNumDevs(WinApplication* app, x86::CPU& cpu);
MMRESULT timeBeginPeriod(WinApplication* app, x86::CPU& cpu,
                         UINT uPeriod);
MMRESULT timeEndPeriod(WinApplication* app, x86::CPU& cpu,
                       UINT uPeriod);
MMRESULT timeGetDevCaps(WinApplication* app, x86::CPU& cpu,
                        LPTIMECAPS ptc, UINT cbtc);
MMRESULT timeKillEvent(WinApplication* app, x86::CPU& cpu,
                       UINT uTimerID);
MMRESULT timeSetEvent(WinApplication* app, x86::CPU& cpu,
                      UINT uDelay, UINT uResolution, LPTIMECALLBACK lpTimeProc,
                      x86::reg32 dwUser, UINT fuEvent);

}}

#endif
