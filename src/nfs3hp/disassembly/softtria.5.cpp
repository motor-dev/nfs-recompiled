#include "softtria.h"
#include <lib/thread.h>

namespace softtria
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7ba40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba40  ff25f0bda700           -jmp dword ptr [0xa7bdf0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993136), cpu);
}

/* align: skip  */
void sub_a7ba46(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba46  ff25c0bda700           -jmp dword ptr [0xa7bdc0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993088), cpu);
}

/* align: skip  */
void sub_a7ba4c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba4c  ff25bcbda700           -jmp dword ptr [0xa7bdbc]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993084), cpu);
}

/* align: skip  */
void sub_a7ba52(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba52  ff25e8bda700           -jmp dword ptr [0xa7bde8]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993128), cpu);
}

/* align: skip  */
void sub_a7ba58(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba58  ff2504bea700           -jmp dword ptr [0xa7be04]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993156), cpu);
}

/* align: skip  */
void sub_a7ba5e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba5e  ff25d4bda700           -jmp dword ptr [0xa7bdd4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993108), cpu);
}

/* align: skip  */
void sub_a7ba64(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba64  ff25a4bda700           -jmp dword ptr [0xa7bda4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993060), cpu);
}

/* align: skip  */
void sub_a7ba6a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba6a  ff251cbea700           -jmp dword ptr [0xa7be1c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993180), cpu);
}

/* align: skip  */
void sub_a7ba70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba70  ff2578bda700           -jmp dword ptr [0xa7bd78]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993016), cpu);
}

/* align: skip  */
void sub_a7ba76(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba76  ff256cbda700           -jmp dword ptr [0xa7bd6c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993004), cpu);
}

/* align: skip  */
void sub_a7ba7c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba7c  ff2570bda700           -jmp dword ptr [0xa7bd70]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993008), cpu);
}

/* align: skip  */
void sub_a7ba82(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba82  ff2588bda700           -jmp dword ptr [0xa7bd88]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993032), cpu);
}

/* align: skip  */
void sub_a7ba88(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba88  ff2564bea700           -jmp dword ptr [0xa7be64]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993252), cpu);
}

/* align: skip  */
void sub_a7ba8e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba8e  ff257cbda700           -jmp dword ptr [0xa7bd7c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993020), cpu);
}

/* align: skip  */
void sub_a7ba94(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba94  ff2580bda700           -jmp dword ptr [0xa7bd80]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993024), cpu);
}

/* align: skip  */
void sub_a7ba9a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7ba9a  ff258cbda700           -jmp dword ptr [0xa7bd8c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993036), cpu);
}

/* align: skip  */
void sub_a7baa0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7baa0  ff255cbea700           -jmp dword ptr [0xa7be5c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993244), cpu);
}

/* align: skip  */
void sub_a7baa6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7baa6  ff2554bea700           -jmp dword ptr [0xa7be54]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993236), cpu);
}

/* align: skip  */
void sub_a7baac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7baac  ff252cbea700           -jmp dword ptr [0xa7be2c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993196), cpu);
}

/* align: skip  */
void sub_a7bab2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bab2  ff2500bea700           -jmp dword ptr [0xa7be00]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993152), cpu);
}

/* align: skip  */
void sub_a7bab8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bab8  ff2528bea700           -jmp dword ptr [0xa7be28]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993192), cpu);
}

/* align: skip  */
void sub_a7babe(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7babe  ff25a8bda700           -jmp dword ptr [0xa7bda8]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993064), cpu);
}

/* align: skip  */
void sub_a7bac4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bac4  ff2594bda700           -jmp dword ptr [0xa7bd94]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993044), cpu);
}

/* align: skip  */
void sub_a7baca(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7baca  ff25d0bda700           -jmp dword ptr [0xa7bdd0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993104), cpu);
}

/* align: skip  */
void sub_a7bad0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bad0  ff259cbda700           -jmp dword ptr [0xa7bd9c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993052), cpu);
}

/* align: skip  */
void sub_a7bad6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bad6  ff25c4bda700           -jmp dword ptr [0xa7bdc4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993092), cpu);
}

/* align: skip  */
void sub_a7badc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7badc  ff25e0bda700           -jmp dword ptr [0xa7bde0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993120), cpu);
}

/* align: skip  */
void sub_a7bae2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bae2  ff2514bea700           -jmp dword ptr [0xa7be14]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993172), cpu);
}

/* align: skip  */
void sub_a7bae8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bae8  ff25d8bda700           -jmp dword ptr [0xa7bdd8]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993112), cpu);
}

/* align: skip  */
void sub_a7baee(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7baee  ff25dcbda700           -jmp dword ptr [0xa7bddc]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993116), cpu);
}

/* align: skip  */
void sub_a7baf4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7baf4  ff2568bda700           -jmp dword ptr [0xa7bd68]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993000), cpu);
}

/* align: skip  */
void sub_a7bafa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bafa  ff2524bea700           -jmp dword ptr [0xa7be24]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993188), cpu);
}

/* align: skip  */
void sub_a7bb00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb00  ff25b8bda700           -jmp dword ptr [0xa7bdb8]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993080), cpu);
}

/* align: skip  */
void sub_a7bb06(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb06  ff25f4bda700           -jmp dword ptr [0xa7bdf4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993140), cpu);
}

/* align: skip  */
void sub_a7bb0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb0c  ff25b4bda700           -jmp dword ptr [0xa7bdb4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993076), cpu);
}

/* align: skip  */
void sub_a7bb12(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb12  ff2520bea700           -jmp dword ptr [0xa7be20]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993184), cpu);
}

/* align: skip  */
void sub_a7bb18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb18  ff2590bda700           -jmp dword ptr [0xa7bd90]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993040), cpu);
}

/* align: skip  */
void sub_a7bb1e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb1e  ff25c8bda700           -jmp dword ptr [0xa7bdc8]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993096), cpu);
}

/* align: skip  */
void sub_a7bb24(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb24  ff2574bda700           -jmp dword ptr [0xa7bd74]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993012), cpu);
}

/* align: skip  */
void sub_a7bb2a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb2a  ff2558bea700           -jmp dword ptr [0xa7be58]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993240), cpu);
}

/* align: skip  */
void sub_a7bb30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb30  ff2568bea700           -jmp dword ptr [0xa7be68]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993256), cpu);
}

/* align: skip  */
void sub_a7bb36(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb36  ff253cbea700           -jmp dword ptr [0xa7be3c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993212), cpu);
}

/* align: skip  */
void sub_a7bb3c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb3c  ff2550bea700           -jmp dword ptr [0xa7be50]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993232), cpu);
}

/* align: skip  */
void sub_a7bb42(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb42  ff25f8bda700           -jmp dword ptr [0xa7bdf8]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993144), cpu);
}

/* align: skip  */
void sub_a7bb48(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb48  ff2510bea700           -jmp dword ptr [0xa7be10]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993168), cpu);
}

/* align: skip  */
void sub_a7bb4e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb4e  ff2560bea700           -jmp dword ptr [0xa7be60]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993248), cpu);
}

/* align: skip  */
void sub_a7bb54(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb54  ff2518bea700           -jmp dword ptr [0xa7be18]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993176), cpu);
}

/* align: skip  */
void sub_a7bb5a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb5a  ff25ecbda700           -jmp dword ptr [0xa7bdec]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993132), cpu);
}

/* align: skip  */
void sub_a7bb60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb60  ff2544bea700           -jmp dword ptr [0xa7be44]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993220), cpu);
}

/* align: skip  */
void sub_a7bb66(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb66  ff254cbea700           -jmp dword ptr [0xa7be4c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993228), cpu);
}

/* align: skip  */
void sub_a7bb6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb6c  ff2540bea700           -jmp dword ptr [0xa7be40]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993216), cpu);
}

/* align: skip  */
void sub_a7bb72(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb72  ff2534bea700           -jmp dword ptr [0xa7be34]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993204), cpu);
}

/* align: skip  */
void sub_a7bb78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb78  ff2548bea700           -jmp dword ptr [0xa7be48]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993224), cpu);
}

/* align: skip  */
void sub_a7bb7e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb7e  ff25e4bda700           -jmp dword ptr [0xa7bde4]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993124), cpu);
}

/* align: skip  */
void sub_a7bb84(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb84  ff250cbea700           -jmp dword ptr [0xa7be0c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993164), cpu);
}

/* align: skip  */
void sub_a7bb8a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb8a  ff25a0bda700           -jmp dword ptr [0xa7bda0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993056), cpu);
}

/* align: skip  */
void sub_a7bb90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb90  ff25ccbda700           -jmp dword ptr [0xa7bdcc]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993100), cpu);
}

/* align: skip  */
void sub_a7bb96(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb96  ff2598bda700           -jmp dword ptr [0xa7bd98]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993048), cpu);
}

/* align: skip  */
void sub_a7bb9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bb9c  ff2508bea700           -jmp dword ptr [0xa7be08]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993160), cpu);
}

/* align: skip  */
void sub_a7bba2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bba2  ff25fcbda700           -jmp dword ptr [0xa7bdfc]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993148), cpu);
}

/* align: skip  */
void sub_a7bba8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bba8  ff2538bea700           -jmp dword ptr [0xa7be38]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993208), cpu);
}

/* align: skip  */
void sub_a7bbae(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bbae  ff25acbda700           -jmp dword ptr [0xa7bdac]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993068), cpu);
}

/* align: skip  */
void sub_a7bbb4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bbb4  ff2530bea700           -jmp dword ptr [0xa7be30]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993200), cpu);
}

/* align: skip  */
void sub_a7bbba(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bbba  ff256cbea700           -jmp dword ptr [0xa7be6c]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993260), cpu);
}

/* align: skip  */
void sub_a7bbc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bbc0  ff25b0bda700           -jmp dword ptr [0xa7bdb0]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993072), cpu);
}

/* align: skip  */
void sub_a7bbc6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bbc6  ff2578bea700           -jmp dword ptr [0xa7be78]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993272), cpu);
}

/* align: skip  */
void sub_a7bbcc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bbcc  ff2574bea700           -jmp dword ptr [0xa7be74]
    return app->dynamic_call(app->getMemory<x86::reg32>(10993268), cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a7bbe0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7bbe0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbe2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbe4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbe6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbe8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbea  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbec  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbee  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbf0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbf2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbf4  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbf6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbf8  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbfa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbfc  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00a7bbfe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
}

}
