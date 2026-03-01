#ifndef EACSND_H_
#define EACSND_H_
#include <x86.h>
#include <lib/winapp.h>
#include <lib/library.h>

namespace eacsnd
{

extern const x86::reg8 s_AUTOSegment[];
extern const x86::reg8 s__idataSegment[];
extern const x86::reg8 s_DGROUPSegment[];
extern const x86::reg8 s__edataSegment[];
void sub_548600(win32::WinApplication* app, x86::CPU& cpu);
void sub_548614(win32::WinApplication* app, x86::CPU& cpu);
void sub_54863c(win32::WinApplication* app, x86::CPU& cpu);
void sub_548b6c(win32::WinApplication* app, x86::CPU& cpu);
void sub_5491dc(win32::WinApplication* app, x86::CPU& cpu);
void sub_549224(win32::WinApplication* app, x86::CPU& cpu);
void sub_5492d0(win32::WinApplication* app, x86::CPU& cpu);
void sub_549394(win32::WinApplication* app, x86::CPU& cpu);
void sub_5494d4(win32::WinApplication* app, x86::CPU& cpu);
void sub_549777(win32::WinApplication* app, x86::CPU& cpu);
void sub_549790(win32::WinApplication* app, x86::CPU& cpu);
void sub_5497c2(win32::WinApplication* app, x86::CPU& cpu);
void sub_5497c7(win32::WinApplication* app, x86::CPU& cpu);
void sub_549834(win32::WinApplication* app, x86::CPU& cpu);
void sub_549840(win32::WinApplication* app, x86::CPU& cpu);

extern win32::Library* s_registry;

}

#endif /* !EACSND_H_ */
