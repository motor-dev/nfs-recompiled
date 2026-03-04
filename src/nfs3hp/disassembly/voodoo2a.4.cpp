#include "voodoo2a.h"
#include <lib/thread.h>

namespace voodoo2a
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8fb50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb50  ff253804a900           -jmp dword ptr [0xa90438]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076664), cpu);
}

/* align: skip  */
void sub_a8fb56(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb56  ff255803a900           -jmp dword ptr [0xa90358]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076440), cpu);
}

/* align: skip  */
void sub_a8fb5c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb5c  ff255c03a900           -jmp dword ptr [0xa9035c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076444), cpu);
}

/* align: skip  */
void sub_a8fb62(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb62  ff250404a900           -jmp dword ptr [0xa90404]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076612), cpu);
}

/* align: skip  */
void sub_a8fb68(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb68  ff256403a900           -jmp dword ptr [0xa90364]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076452), cpu);
}

/* align: skip  */
void sub_a8fb6e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb6e  ff256803a900           -jmp dword ptr [0xa90368]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076456), cpu);
}

/* align: skip  */
void sub_a8fb74(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb74  ff259003a900           -jmp dword ptr [0xa90390]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076496), cpu);
}

/* align: skip  */
void sub_a8fb7a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb7a  ff25d803a900           -jmp dword ptr [0xa903d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076568), cpu);
}

/* align: skip  */
void sub_a8fb80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb80  ff25ec03a900           -jmp dword ptr [0xa903ec]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076588), cpu);
}

/* align: skip  */
void sub_a8fb86(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb86  ff250004a900           -jmp dword ptr [0xa90400]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076608), cpu);
}

/* align: skip  */
void sub_a8fb8c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb8c  ff258403a900           -jmp dword ptr [0xa90384]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076484), cpu);
}

/* align: skip  */
void sub_a8fb92(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb92  ff257003a900           -jmp dword ptr [0xa90370]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076464), cpu);
}

/* align: skip  */
void sub_a8fb98(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb98  ff25b003a900           -jmp dword ptr [0xa903b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076528), cpu);
}

/* align: skip  */
void sub_a8fb9e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb9e  ff255003a900           -jmp dword ptr [0xa90350]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076432), cpu);
}

/* align: skip  */
void sub_a8fba4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fba4  ff25fc03a900           -jmp dword ptr [0xa903fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076604), cpu);
}

/* align: skip  */
void sub_a8fbaa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbaa  ff257803a900           -jmp dword ptr [0xa90378]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076472), cpu);
}

/* align: skip  */
void sub_a8fbb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbb0  ff25a403a900           -jmp dword ptr [0xa903a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076516), cpu);
}

/* align: skip  */
void sub_a8fbb6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbb6  ff25c003a900           -jmp dword ptr [0xa903c0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076544), cpu);
}

/* align: skip  */
void sub_a8fbbc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbbc  ff25f003a900           -jmp dword ptr [0xa903f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076592), cpu);
}

/* align: skip  */
void sub_a8fbc2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbc2  ff25b803a900           -jmp dword ptr [0xa903b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076536), cpu);
}

/* align: skip  */
void sub_a8fbc8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbc8  ff259803a900           -jmp dword ptr [0xa90398]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076504), cpu);
}

/* align: skip  */
void sub_a8fbce(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbce  ff25d403a900           -jmp dword ptr [0xa903d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076564), cpu);
}

/* align: skip  */
void sub_a8fbd4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbd4  ff259403a900           -jmp dword ptr [0xa90394]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076500), cpu);
}

/* align: skip  */
void sub_a8fbda(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbda  ff25bc03a900           -jmp dword ptr [0xa903bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076540), cpu);
}

/* align: skip  */
void sub_a8fbe0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbe0  ff25f803a900           -jmp dword ptr [0xa903f8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076600), cpu);
}

/* align: skip  */
void sub_a8fbe6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbe6  ff256c03a900           -jmp dword ptr [0xa9036c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076460), cpu);
}

/* align: skip  */
void sub_a8fbec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbec  ff25a803a900           -jmp dword ptr [0xa903a8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076520), cpu);
}

/* align: skip  */
void sub_a8fbf2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbf2  ff253c04a900           -jmp dword ptr [0xa9043c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076668), cpu);
}

/* align: skip  */
void sub_a8fbf8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbf8  ff253004a900           -jmp dword ptr [0xa90430]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076656), cpu);
}

/* align: skip  */
void sub_a8fbfe(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fbfe  ff258c03a900           -jmp dword ptr [0xa9038c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076492), cpu);
}

/* align: skip  */
void sub_a8fc04(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc04  ff251404a900           -jmp dword ptr [0xa90414]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076628), cpu);
}

/* align: skip  */
void sub_a8fc0a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc0a  ff252804a900           -jmp dword ptr [0xa90428]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076648), cpu);
}

/* align: skip  */
void sub_a8fc10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc10  ff253404a900           -jmp dword ptr [0xa90434]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076660), cpu);
}

/* align: skip  */
void sub_a8fc16(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc16  ff25f403a900           -jmp dword ptr [0xa903f4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076596), cpu);
}

/* align: skip  */
void sub_a8fc1c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc1c  ff25cc03a900           -jmp dword ptr [0xa903cc]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076556), cpu);
}

/* align: skip  */
void sub_a8fc22(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc22  ff25dc03a900           -jmp dword ptr [0xa903dc]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076572), cpu);
}

/* align: skip  */
void sub_a8fc28(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc28  ff251004a900           -jmp dword ptr [0xa90410]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076624), cpu);
}

/* align: skip  */
void sub_a8fc2e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc2e  ff258803a900           -jmp dword ptr [0xa90388]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076488), cpu);
}

/* align: skip  */
void sub_a8fc34(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc34  ff250804a900           -jmp dword ptr [0xa90408]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076616), cpu);
}

/* align: skip  */
void sub_a8fc3a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc3a  ff254004a900           -jmp dword ptr [0xa90440]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076672), cpu);
}

/* align: skip  */
void sub_a8fc40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc40  ff255403a900           -jmp dword ptr [0xa90354]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076436), cpu);
}

/* align: skip  */
void sub_a8fc46(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc46  ff251c04a900           -jmp dword ptr [0xa9041c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076636), cpu);
}

/* align: skip  */
void sub_a8fc4c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc4c  ff252404a900           -jmp dword ptr [0xa90424]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076644), cpu);
}

/* align: skip  */
void sub_a8fc52(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc52  ff251804a900           -jmp dword ptr [0xa90418]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076632), cpu);
}

/* align: skip  */
void sub_a8fc58(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc58  ff250c04a900           -jmp dword ptr [0xa9040c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076620), cpu);
}

/* align: skip  */
void sub_a8fc5e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc5e  ff252004a900           -jmp dword ptr [0xa90420]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076640), cpu);
}

/* align: skip  */
void sub_a8fc64(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc64  ff25c403a900           -jmp dword ptr [0xa903c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076548), cpu);
}

/* align: skip  */
void sub_a8fc6a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc6a  ff25e803a900           -jmp dword ptr [0xa903e8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076584), cpu);
}

/* align: skip  */
void sub_a8fc70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc70  ff257c03a900           -jmp dword ptr [0xa9037c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076476), cpu);
}

/* align: skip  */
void sub_a8fc76(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc76  ff25ac03a900           -jmp dword ptr [0xa903ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076524), cpu);
}

/* align: skip  */
void sub_a8fc7c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc7c  ff257403a900           -jmp dword ptr [0xa90374]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076468), cpu);
}

/* align: skip  */
void sub_a8fc82(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc82  ff25e403a900           -jmp dword ptr [0xa903e4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076580), cpu);
}

/* align: skip  */
void sub_a8fc88(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc88  ff252c04a900           -jmp dword ptr [0xa9042c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076652), cpu);
}

/* align: skip  */
void sub_a8fc8e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc8e  ff25d003a900           -jmp dword ptr [0xa903d0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076560), cpu);
}

/* align: skip  */
void sub_a8fc94(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc94  ff25a003a900           -jmp dword ptr [0xa903a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076512), cpu);
}

/* align: skip  */
void sub_a8fc9a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fc9a  ff259c03a900           -jmp dword ptr [0xa9039c]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076508), cpu);
}

/* align: skip  */
void sub_a8fca0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fca0  ff25c803a900           -jmp dword ptr [0xa903c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076552), cpu);
}

/* align: skip  */
void sub_a8fca6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fca6  ff25e003a900           -jmp dword ptr [0xa903e0]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076576), cpu);
}

/* align: skip  */
void sub_a8fcac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fcac  ff25b403a900           -jmp dword ptr [0xa903b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076532), cpu);
}

/* align: skip  */
void sub_a8fcb2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fcb2  ff258003a900           -jmp dword ptr [0xa90380]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076480), cpu);
}

/* align: skip  */
void sub_a8fcb8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fcb8  ff254804a900           -jmp dword ptr [0xa90448]
    return app->dynamic_call(app->getMemory<x86::reg32>(11076680), cpu);
}

/* align: skip 0x00 0x00 */
void sub_a8fcc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fcc0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcc2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcc4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcc6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcc8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fccc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcdc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fce0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fce2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fce4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fce6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fce8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcf0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcf2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcf4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcf6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcf8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fcfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd00  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd02  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd04  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd06  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd08  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd0a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd0c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd0e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd10  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd12  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd14  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd16  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd18  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd1a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd1c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd1e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd20  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd22  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd24  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd26  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd28  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd2a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd2c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd2e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd30  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd32  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd34  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd36  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd38  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd3a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd3c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd3e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd40  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd42  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd44  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd46  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd48  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd4a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd4c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd4e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd50  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd52  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd54  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd56  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd58  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd5a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd5c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd5e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd60  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd62  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd64  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd66  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd68  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd6a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd6c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd6e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd70  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd72  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd74  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd76  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd78  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd7a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd7c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd7e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd80  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd82  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd84  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd86  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd88  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd8a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd8c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd8e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd90  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd92  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd94  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd96  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd98  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd9a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd9c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fd9e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fda0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fda2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fda4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fda6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fda8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdaa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdac  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdae  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdb0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdb2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdb4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdb6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdb8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdba  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdbc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdbe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdc0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdc2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdc4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdc6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdc8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdca  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdcc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdce  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdd0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdd2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdd4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdd6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdd8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdda  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fddc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdde  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fde0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fde2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fde4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fde6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fde8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdf0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdf2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdf4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdf6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdf8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a8fdfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
}

}
