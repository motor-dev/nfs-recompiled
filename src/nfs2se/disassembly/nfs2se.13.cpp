#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ab90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ab90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ab91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ab92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ab93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ab94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ab95  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ab98  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046ab9a  a0ac9e4600             -mov al, byte ptr [0x469eac]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4628140) /* 0x469eac */);
    // 0046ab9f  bafeffffff             -mov edx, 0xfffffffe
    cpu.edx = 4294967294 /*0xfffffffe*/;
    // 0046aba4  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 0046aba7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046abac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046abae  e8bd50feff             -call 0x44fc70
    cpu.esp -= 4;
    sub_44fc70(app, cpu);
    if (cpu.terminate) return;
    // 0046abb3  66891530e54d00         -mov word ptr [0x4de530], dx
    app->getMemory<x86::reg16>(x86::reg32(5104944) /* 0x4de530 */) = cpu.dx;
    // 0046abba  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046abbc  b203                   -mov dl, 3
    cpu.dl = 3 /*0x3*/;
    // 0046abbe  8825e4e44d00           -mov byte ptr [0x4de4e4], ah
    app->getMemory<x86::reg8>(x86::reg32(5104868) /* 0x4de4e4 */) = cpu.ah;
    // 0046abc4  b800030000             -mov eax, 0x300
    cpu.eax = 768 /*0x300*/;
    // 0046abc9  8815dee44d00           -mov byte ptr [0x4de4de], dl
    app->getMemory<x86::reg8>(x86::reg32(5104862) /* 0x4de4de */) = cpu.dl;
    // 0046abcf  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0046abd4  66891dd8e44d00         -mov word ptr [0x4de4d8], bx
    app->getMemory<x86::reg16>(x86::reg32(5104856) /* 0x4de4d8 */) = cpu.bx;
    // 0046abdb  e8d077f9ff             -call 0x4023b0
    cpu.esp -= 4;
    sub_4023b0(app, cpu);
    if (cpu.terminate) return;
    // 0046abe0  8b15fc724c00           -mov edx, dword ptr [0x4c72fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5010172) /* 0x4c72fc */);
    // 0046abe6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046abe8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046abea  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046abf1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046abf3  8b1504734c00           -mov edx, dword ptr [0x4c7304]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
    // 0046abf9  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046abfe  7424                   -je 0x46ac24
    if (cpu.flags.zf)
    {
        goto L_0x0046ac24;
    }
    // 0046ac00  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046ac02  b848815100             -mov eax, 0x518148
    cpu.eax = 5341512 /*0x518148*/;
    // 0046ac07  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046ac09  e8c6210200             -call 0x48cdd4
    cpu.esp -= 4;
    sub_48cdd4(app, cpu);
    if (cpu.terminate) return;
    // 0046ac0e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ac10  0f8e7e000000           -jle 0x46ac94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046ac94;
    }
    // 0046ac16  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046ac18:
    // 0046ac18  3b15ec815100           +cmp edx, dword ptr [0x5181ec]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5341676) /* 0x5181ec */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ac1e  0f84a0000000           -je 0x46acc4
    if (cpu.flags.zf)
    {
        goto L_0x0046acc4;
    }
L_0x0046ac24:
    // 0046ac24  e8b74efeff             -call 0x44fae0
    cpu.esp -= 4;
    sub_44fae0(app, cpu);
    if (cpu.terminate) return;
    // 0046ac29  b864815100             -mov eax, 0x518164
    cpu.eax = 5341540 /*0x518164*/;
    // 0046ac2e  b948815100             -mov ecx, 0x518148
    cpu.ecx = 5341512 /*0x518148*/;
    // 0046ac33  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ac35  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0046ac3a  e8b1f8ffff             -call 0x46a4f0
    cpu.esp -= 4;
    sub_46a4f0(app, cpu);
    if (cpu.terminate) return;
    // 0046ac3f  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0046ac44  e813220200             -call 0x48ce5c
    cpu.esp -= 4;
    sub_48ce5c(app, cpu);
    if (cpu.terminate) return;
    // 0046ac49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ac4b  0f85e3000000           -jne 0x46ad34
    if (!cpu.flags.zf)
    {
        goto L_0x0046ad34;
    }
    // 0046ac51  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0046ac56  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046ac58  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046ac5d  e8de76f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046ac62  66890ddae44d00         -mov word ptr [0x4de4da], cx
    app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */) = cpu.cx;
    // 0046ac69  e832f9ffff             -call 0x46a5a0
    cpu.esp -= 4;
    sub_46a5a0(app, cpu);
    if (cpu.terminate) return;
    // 0046ac6e  e801470100             -call 0x47f374
    cpu.esp -= 4;
    sub_47f374(app, cpu);
    if (cpu.terminate) return;
    // 0046ac73  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046ac75  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ac77  668935dae44d00         -mov word ptr [0x4de4da], si
    app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */) = cpu.si;
L_0x0046ac7e:
    // 0046ac7e  e82dacf9ff             -call 0x4058b0
    cpu.esp -= 4;
    sub_4058b0(app, cpu);
    if (cpu.terminate) return;
    // 0046ac83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ac85  0f847b000000           -je 0x46ad06
    if (cpu.flags.zf)
    {
        goto L_0x0046ad06;
    }
    // 0046ac8b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046ac8d  e8eed30000             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 0046ac92  ebea                   -jmp 0x46ac7e
    goto L_0x0046ac7e;
L_0x0046ac94:
    // 0046ac94  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0046ac99  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ac9b  e8a076f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
L_0x0046aca0:
    // 0046aca0  e84cc60000             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0046aca5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046aca7  7509                   -jne 0x46acb2
    if (!cpu.flags.zf)
    {
        goto L_0x0046acb2;
    }
    // 0046aca9  e802acf9ff             -call 0x4058b0
    cpu.esp -= 4;
    sub_4058b0(app, cpu);
    if (cpu.terminate) return;
    // 0046acae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046acb0  74ee                   -je 0x46aca0
    if (cpu.flags.zf)
    {
        goto L_0x0046aca0;
    }
L_0x0046acb2:
    // 0046acb2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046acb4  e8b74ffeff             -call 0x44fc70
    cpu.esp -= 4;
    sub_44fc70(app, cpu);
    if (cpu.terminate) return;
L_0x0046acb9:
    // 0046acb9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046acbb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046acbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acc0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046acc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046acc4:
    // 0046acc4  e8e74dfeff             -call 0x44fab0
    cpu.esp -= 4;
    sub_44fab0(app, cpu);
    if (cpu.terminate) return;
    // 0046acc9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046accb  0f8447ffffff           -je 0x46ac18
    if (cpu.flags.zf)
    {
        goto L_0x0046ac18;
    }
    // 0046acd1  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0046acd6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046acd8  e86376f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046acdd  e8bef8ffff             -call 0x46a5a0
    cpu.esp -= 4;
    sub_46a5a0(app, cpu);
    if (cpu.terminate) return;
L_0x0046ace2:
    // 0046ace2  e80ac60000             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0046ace7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ace9  75c7                   -jne 0x46acb2
    if (!cpu.flags.zf)
    {
        goto L_0x0046acb2;
    }
    // 0046aceb  e8c0abf9ff             -call 0x4058b0
    cpu.esp -= 4;
    sub_4058b0(app, cpu);
    if (cpu.terminate) return;
    // 0046acf0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046acf2  74ee                   -je 0x46ace2
    if (cpu.flags.zf)
    {
        goto L_0x0046ace2;
    }
    // 0046acf4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046acf6  e8754ffeff             -call 0x44fc70
    cpu.esp -= 4;
    sub_44fc70(app, cpu);
    if (cpu.terminate) return;
    // 0046acfb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046acfd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ad00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ad06:
    // 0046ad06  e8e6c50000             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0046ad0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ad0d  7509                   -jne 0x46ad18
    if (!cpu.flags.zf)
    {
        goto L_0x0046ad18;
    }
    // 0046ad0f  e89cabf9ff             -call 0x4058b0
    cpu.esp -= 4;
    sub_4058b0(app, cpu);
    if (cpu.terminate) return;
    // 0046ad14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ad16  74ee                   -je 0x46ad06
    if (cpu.flags.zf)
    {
        goto L_0x0046ad06;
    }
L_0x0046ad18:
    // 0046ad18  e88351fbff             -call 0x41fea0
    cpu.esp -= 4;
    sub_41fea0(app, cpu);
    if (cpu.terminate) return;
    // 0046ad1d  e8ae3efaff             -call 0x40ebd0
    cpu.esp -= 4;
    sub_40ebd0(app, cpu);
    if (cpu.terminate) return;
    // 0046ad22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ad24  e8474ffeff             -call 0x44fc70
    cpu.esp -= 4;
    sub_44fc70(app, cpu);
    if (cpu.terminate) return;
    // 0046ad29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ad2b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ad2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ad34:
    // 0046ad34  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046ad36:
    // 0046ad36  663b15a4e44d00         +cmp dx, word ptr [0x4de4a4]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(5104804) /* 0x4de4a4 */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046ad3d  7554                   -jne 0x46ad93
    if (!cpu.flags.zf)
    {
        goto L_0x0046ad93;
    }
    // 0046ad3f  e86c4dfeff             -call 0x44fab0
    cpu.esp -= 4;
    sub_44fab0(app, cpu);
    if (cpu.terminate) return;
    // 0046ad44  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ad46  74ee                   -je 0x46ad36
    if (cpu.flags.zf)
    {
        goto L_0x0046ad36;
    }
    // 0046ad48  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0046ad4d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046ad4f  e8ec75f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046ad54  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046ad59  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ad5b  66a3dae44d00           -mov word ptr [0x4de4da], ax
    app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */) = cpu.ax;
    // 0046ad61  e80e460100             -call 0x47f374
    cpu.esp -= 4;
    sub_47f374(app, cpu);
    if (cpu.terminate) return;
    // 0046ad66  66891ddae44d00         -mov word ptr [0x4de4da], bx
    app->getMemory<x86::reg16>(x86::reg32(5104858) /* 0x4de4da */) = cpu.bx;
    // 0046ad6d  e80e4dfeff             -call 0x44fa80
    cpu.esp -= 4;
    sub_44fa80(app, cpu);
    if (cpu.terminate) return;
L_0x0046ad72:
    // 0046ad72  e87ac50000             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0046ad77  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ad79  0f853affffff           -jne 0x46acb9
    if (!cpu.flags.zf)
    {
        goto L_0x0046acb9;
    }
    // 0046ad7f  e82cabf9ff             -call 0x4058b0
    cpu.esp -= 4;
    sub_4058b0(app, cpu);
    if (cpu.terminate) return;
    // 0046ad84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ad86  74ea                   -je 0x46ad72
    if (cpu.flags.zf)
    {
        goto L_0x0046ad72;
    }
    // 0046ad88  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ad8a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ad8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ad92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ad93:
    // 0046ad93  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046ad95  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ad97  e8a475f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046ad9c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046ada1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ada4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ada5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ada6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ada7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ada8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ada9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46adb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046adb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046adb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046adb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046adb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046adb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046adb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046adb6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046adb9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046adbb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046adc0  bfe5e44d00             -mov edi, 0x4de4e5
    cpu.edi = 5104869 /*0x4de4e5*/;
    // 0046adc5  a0ab9e4600             -mov al, byte ptr [0x469eab]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4628139) /* 0x469eab */);
    // 0046adca  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0046adcc  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 0046add0  e80bf3ffff             -call 0x46a0e0
    cpu.esp -= 4;
    sub_46a0e0(app, cpu);
    if (cpu.terminate) return;
    // 0046add5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046adda  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046addc  e88f4efeff             -call 0x44fc70
    cpu.esp -= 4;
    sub_44fc70(app, cpu);
    if (cpu.terminate) return;
    // 0046ade1  b403                   -mov ah, 3
    cpu.ah = 3 /*0x3*/;
    // 0046ade3  8815e4e44d00           -mov byte ptr [0x4de4e4], dl
    app->getMemory<x86::reg8>(x86::reg32(5104868) /* 0x4de4e4 */) = cpu.dl;
    // 0046ade9  66891d2ee54d00         -mov word ptr [0x4de52e], bx
    app->getMemory<x86::reg16>(x86::reg32(5104942) /* 0x4de52e */) = cpu.bx;
    // 0046adf0  66893532e54d00         -mov word ptr [0x4de532], si
    app->getMemory<x86::reg16>(x86::reg32(5104946) /* 0x4de532 */) = cpu.si;
    // 0046adf7  8825dee44d00           -mov byte ptr [0x4de4de], ah
    app->getMemory<x86::reg8>(x86::reg32(5104862) /* 0x4de4de */) = cpu.ah;
    // 0046adfd  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0046adff  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046ae01  66891530e54d00         -mov word ptr [0x4de530], dx
    app->getMemory<x86::reg16>(x86::reg32(5104944) /* 0x4de530 */) = cpu.dx;
    // 0046ae08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046ae09:
    // 0046ae09  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046ae0b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046ae0d  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ae0f  7410                   -je 0x46ae21
    if (cpu.flags.zf)
    {
        goto L_0x0046ae21;
    }
    // 0046ae11  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046ae14  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046ae17  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046ae1a  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046ae1d  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ae1f  75e8                   -jne 0x46ae09
    if (!cpu.flags.zf)
    {
        goto L_0x0046ae09;
    }
L_0x0046ae21:
    // 0046ae21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ae22  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 0046ae27  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0046ae29:
    // 0046ae29  0fbfd0                 -movsx edx, ax
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0046ae2c  40                     -inc eax
    (cpu.eax)++;
    // 0046ae2d  66893c5532e54d00       -mov word ptr [edx*2 + 0x4de532], di
    app->getMemory<x86::reg16>(x86::reg32(5104946) /* 0x4de532 */ + cpu.edx * 2) = cpu.di;
    // 0046ae35  663d0800               +cmp ax, 8
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046ae39  7cee                   -jl 0x46ae29
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046ae29;
    }
    // 0046ae3b  e8c0f1ffff             -call 0x46a000
    cpu.esp -= 4;
    sub_46a000(app, cpu);
    if (cpu.terminate) return;
    // 0046ae40  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0046ae45  bff4815100             -mov edi, 0x5181f4
    cpu.edi = 5341684 /*0x5181f4*/;
    // 0046ae4a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046ae4c  891524825100           -mov dword ptr [0x518224], edx
    app->getMemory<x86::reg32>(x86::reg32(5341732) /* 0x518224 */) = cpu.edx;
    // 0046ae52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046ae53:
    // 0046ae53  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046ae55  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046ae57  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ae59  7410                   -je 0x46ae6b
    if (cpu.flags.zf)
    {
        goto L_0x0046ae6b;
    }
    // 0046ae5b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046ae5e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046ae61  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046ae64  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046ae67  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ae69  75e8                   -jne 0x46ae53
    if (!cpu.flags.zf)
    {
        goto L_0x0046ae53;
    }
L_0x0046ae6b:
    // 0046ae6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ae6c  833d00734c0000         +cmp dword ptr [0x4c7300], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5010176) /* 0x4c7300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ae73  0f85aa000000           -jne 0x46af23
    if (!cpu.flags.zf)
    {
        goto L_0x0046af23;
    }
    // 0046ae79  8b15fc724c00           -mov edx, dword ptr [0x4c72fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5010172) /* 0x4c72fc */);
    // 0046ae7f  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046ae86  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ae88  8b1504734c00           -mov edx, dword ptr [0x4c7304]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
    // 0046ae8e  807c820f00             +cmp byte ptr [edx + eax*4 + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ae93  0f8474000000           -je 0x46af0d
    if (cpu.flags.zf)
    {
        goto L_0x0046af0d;
    }
    // 0046ae99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ae9b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046ae9d:
    // 0046ae9d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ae9e  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046aea2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046aea3  8b0dfc724c00           -mov ecx, dword ptr [0x4c72fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5010172) /* 0x4c72fc */);
    // 0046aea9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046aeaa  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0046aeb1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046aeb3  8b0d04734c00           -mov ecx, dword ptr [0x4c7304]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
    // 0046aeb9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046aebc  bb1c734c00             -mov ebx, 0x4c731c
    cpu.ebx = 5010204 /*0x4c731c*/;
    // 0046aec1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046aec3  b848815100             -mov eax, 0x518148
    cpu.eax = 5341512 /*0x518148*/;
    // 0046aec8  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046aecb  e8741d0200             -call 0x48cc44
    cpu.esp -= 4;
    sub_48cc44(app, cpu);
    if (cpu.terminate) return;
    // 0046aed0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046aed2  7545                   -jne 0x46af19
    if (!cpu.flags.zf)
    {
        goto L_0x0046af19;
    }
    // 0046aed4  b8ff020000             -mov eax, 0x2ff
    cpu.eax = 767 /*0x2ff*/;
    // 0046aed9  e8c27df9ff             -call 0x402ca0
    cpu.esp -= 4;
    sub_402ca0(app, cpu);
    if (cpu.terminate) return;
    // 0046aede  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0046aee3  e8efc30000             -call 0x4772d7
    cpu.esp -= 4;
    sub_4772d7(app, cpu);
    if (cpu.terminate) return;
L_0x0046aee8:
    // 0046aee8  e804c40000             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0046aeed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046aeef  7509                   -jne 0x46aefa
    if (!cpu.flags.zf)
    {
        goto L_0x0046aefa;
    }
    // 0046aef1  e8baa9f9ff             -call 0x4058b0
    cpu.esp -= 4;
    sub_4058b0(app, cpu);
    if (cpu.terminate) return;
    // 0046aef6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046aef8  74ee                   -je 0x46aee8
    if (cpu.flags.zf)
    {
        goto L_0x0046aee8;
    }
L_0x0046aefa:
    // 0046aefa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046aefc  e86f4dfeff             -call 0x44fc70
    cpu.esp -= 4;
    sub_44fc70(app, cpu);
    if (cpu.terminate) return;
    // 0046af01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046af03  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046af06  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af07  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046af0d:
    // 0046af0d  b806040000             -mov eax, 0x406
    cpu.eax = 1030 /*0x406*/;
    // 0046af12  ba00a14600             -mov edx, 0x46a100
    cpu.edx = 4628736 /*0x46a100*/;
    // 0046af17  eb84                   -jmp 0x46ae9d
    goto L_0x0046ae9d;
L_0x0046af19:
    // 0046af19  c70500734c0001000000   -mov dword ptr [0x4c7300], 1
    app->getMemory<x86::reg32>(x86::reg32(5010176) /* 0x4c7300 */) = 1 /*0x1*/;
L_0x0046af23:
    // 0046af23  e8b84bfeff             -call 0x44fae0
    cpu.esp -= 4;
    sub_44fae0(app, cpu);
    if (cpu.terminate) return;
    // 0046af28  8b15fc724c00           -mov edx, dword ptr [0x4c72fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5010172) /* 0x4c72fc */);
    // 0046af2e  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046af35  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046af37  a104734c00             -mov eax, dword ptr [0x4c7304]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
    // 0046af3c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046af3f  807c020f00             +cmp byte ptr [edx + eax + 0xf], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046af44  7514                   -jne 0x46af5a
    if (!cpu.flags.zf)
    {
        goto L_0x0046af5a;
    }
    // 0046af46  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046af4b  a314734c00             -mov dword ptr [0x4c7314], eax
    app->getMemory<x86::reg32>(x86::reg32(5010196) /* 0x4c7314 */) = cpu.eax;
    // 0046af50  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046af53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046af59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046af5a:
    // 0046af5a  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 0046af5f  b970a14600             -mov ecx, 0x46a170
    cpu.ecx = 4628848 /*0x46a170*/;
    // 0046af64  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046af68  baf4815100             -mov edx, 0x5181f4
    cpu.edx = 5341684 /*0x5181f4*/;
    // 0046af6d  b848815100             -mov eax, 0x518148
    cpu.eax = 5341512 /*0x518148*/;
    // 0046af72  893d50824c00           -mov dword ptr [0x4c8250], edi
    app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */) = cpu.edi;
    // 0046af78  e86f1e0200             -call 0x48cdec
    cpu.esp -= 4;
    sub_48cdec(app, cpu);
    if (cpu.terminate) return;
    // 0046af7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046af7f  754f                   -jne 0x46afd0
    if (!cpu.flags.zf)
    {
        goto L_0x0046afd0;
    }
    // 0046af81  a350824c00             -mov dword ptr [0x4c8250], eax
    app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */) = cpu.eax;
    // 0046af86  b8ff020000             -mov eax, 0x2ff
    cpu.eax = 767 /*0x2ff*/;
    // 0046af8b  e8107df9ff             -call 0x402ca0
    cpu.esp -= 4;
    sub_402ca0(app, cpu);
    if (cpu.terminate) return;
    // 0046af90  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
    // 0046af95  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046af97  e83bc30000             -call 0x4772d7
    cpu.esp -= 4;
    sub_4772d7(app, cpu);
    if (cpu.terminate) return;
    // 0046af9c  e8d3430100             -call 0x47f374
    cpu.esp -= 4;
    sub_47f374(app, cpu);
    if (cpu.terminate) return;
L_0x0046afa1:
    // 0046afa1  e84bc30000             -call 0x4772f1
    cpu.esp -= 4;
    sub_4772f1(app, cpu);
    if (cpu.terminate) return;
    // 0046afa6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046afa8  7509                   -jne 0x46afb3
    if (!cpu.flags.zf)
    {
        goto L_0x0046afb3;
    }
    // 0046afaa  e801a9f9ff             -call 0x4058b0
    cpu.esp -= 4;
    sub_4058b0(app, cpu);
    if (cpu.terminate) return;
    // 0046afaf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046afb1  74ee                   -je 0x46afa1
    if (cpu.flags.zf)
    {
        goto L_0x0046afa1;
    }
L_0x0046afb3:
    // 0046afb3  e8e84efbff             -call 0x41fea0
    cpu.esp -= 4;
    sub_41fea0(app, cpu);
    if (cpu.terminate) return;
    // 0046afb8  e8133cfaff             -call 0x40ebd0
    cpu.esp -= 4;
    sub_40ebd0(app, cpu);
    if (cpu.terminate) return;
    // 0046afbd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046afbf  e8ac4cfeff             -call 0x44fc70
    cpu.esp -= 4;
    sub_44fc70(app, cpu);
    if (cpu.terminate) return;
    // 0046afc4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046afc6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046afc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afcc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046afd0:
    // 0046afd0  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046afd2  892d50824c00           -mov dword ptr [0x4c8250], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */) = cpu.ebp;
    // 0046afd8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046afdd  a314734c00             -mov dword ptr [0x4c7314], eax
    app->getMemory<x86::reg32>(x86::reg32(5010196) /* 0x4c7314 */) = cpu.eax;
    // 0046afe2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046afe5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afe6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afe7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afe8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afe9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046afeb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46aff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046aff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046aff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046aff2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046aff3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046aff4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046aff5  83ec68                 -sub esp, 0x68
    (cpu.esp) -= x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0046aff8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046affa  8d7c2440               -lea edi, [esp + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046affe  a0aa9e4600             -mov al, byte ptr [0x469eaa]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(4628138) /* 0x469eaa */);
    // 0046b003  bea09e4600             -mov esi, 0x469ea0
    cpu.esi = 4628128 /*0x469ea0*/;
    // 0046b008  8b0d00734c00           -mov ecx, dword ptr [0x4c7300]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5010176) /* 0x4c7300 */);
    // 0046b00e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b010  88442464               -mov byte ptr [esp + 0x64], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.al;
    // 0046b014  66891d0c734c00         -mov word ptr [0x4c730c], bx
    app->getMemory<x86::reg16>(x86::reg32(5010188) /* 0x4c730c */) = cpu.bx;
    // 0046b01b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046b01c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046b01d  66a5                   -movsw word ptr es:[edi], word ptr [esi]
    app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = app->getMemory<x86::reg16>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 2;
        cpu.esi -= 2;
    }
    else
    {
        cpu.edi += 2;
        cpu.esi += 2;
    }
    // 0046b01f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046b021  7547                   -jne 0x46b06a
    if (!cpu.flags.zf)
    {
        goto L_0x0046b06a;
    }
    // 0046b023  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b024  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0046b028  8b15fc724c00           -mov edx, dword ptr [0x4c72fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5010172) /* 0x4c72fc */);
    // 0046b02e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046b02f  bb1c734c00             -mov ebx, 0x4c731c
    cpu.ebx = 5010204 /*0x4c731c*/;
    // 0046b034  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046b03b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b03c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046b03e  8b0d04734c00           -mov ecx, dword ptr [0x4c7304]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
    // 0046b044  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046b047  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b049  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b04b  b848815100             -mov eax, 0x518148
    cpu.eax = 5341512 /*0x518148*/;
    // 0046b050  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046b053  e8ec1b0200             -call 0x48cc44
    cpu.esp -= 4;
    sub_48cc44(app, cpu);
    if (cpu.terminate) return;
    // 0046b058  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b05a  0f8472010000           -je 0x46b1d2
    if (cpu.flags.zf)
    {
        goto L_0x0046b1d2;
    }
    // 0046b060  c70500734c0001000000   -mov dword ptr [0x4c7300], 1
    app->getMemory<x86::reg32>(x86::reg32(5010176) /* 0x4c7300 */) = 1 /*0x1*/;
L_0x0046b06a:
    // 0046b06a  bea07b5100             -mov esi, 0x517ba0
    cpu.esi = 5340064 /*0x517ba0*/;
    // 0046b06f  8d4c2464               -lea ecx, [esp + 0x64]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0046b073  baa0a14600             -mov edx, 0x46a1a0
    cpu.edx = 4628896 /*0x46a1a0*/;
    // 0046b078  b848815100             -mov eax, 0x518148
    cpu.eax = 5341512 /*0x518148*/;
    // 0046b07d  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046b07f  893510734c00           -mov dword ptr [0x4c7310], esi
    app->getMemory<x86::reg32>(x86::reg32(5010192) /* 0x4c7310 */) = cpu.esi;
    // 0046b085  e83e1d0200             -call 0x48cdc8
    cpu.esp -= 4;
    sub_48cdc8(app, cpu);
    if (cpu.terminate) return;
    // 0046b08a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b08c  0f8440010000           -je 0x46b1d2
    if (cpu.flags.zf)
    {
        goto L_0x0046b1d2;
    }
    // 0046b092  66833d0c734c0001       +cmp word ptr [0x4c730c], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5010188) /* 0x4c730c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046b09a  0f8e32010000           -jle 0x46b1d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b1d2;
    }
    // 0046b0a0  a10a734c00             -mov eax, dword ptr [0x4c730a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5010186) /* 0x4c730a */);
    // 0046b0a5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046b0a7  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046b0aa  897c245c               -mov dword ptr [esp + 0x5c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edi;
    // 0046b0ae  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0046b0b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b0b4  0f8e18010000           -jle 0x46b1d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b1d2;
    }
    // 0046b0ba  897c2458               -mov dword ptr [esp + 0x58], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edi;
L_0x0046b0be:
    // 0046b0be  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0046b0c2  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046b0c6  8b3510734c00           -mov esi, dword ptr [0x4c7310]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5010192) /* 0x4c7310 */);
    // 0046b0cc  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046b0d0  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046b0d2  8d7c244c               -lea edi, [esp + 0x4c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0046b0d6  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046b0d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046b0d9:
    // 0046b0d9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046b0db  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046b0dd  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046b0df  7410                   -je 0x46b0f1
    if (cpu.flags.zf)
    {
        goto L_0x0046b0f1;
    }
    // 0046b0e1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046b0e4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046b0e7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046b0ea  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046b0ed  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046b0ef  75e8                   -jne 0x46b0d9
    if (!cpu.flags.zf)
    {
        goto L_0x0046b0d9;
    }
L_0x0046b0f1:
    // 0046b0f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b0f2  39d5                   +cmp ebp, edx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b0f4  7d4e                   -jge 0x46b144
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b144;
    }
    // 0046b0f6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046b0f8  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
L_0x0046b0fb:
    // 0046b0fb  8b1510734c00           -mov edx, dword ptr [0x4c7310]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5010192) /* 0x4c7310 */);
    // 0046b101  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0046b105  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b107  e8e4c70000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 0046b10c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b10e  7e28                   -jle 0x46b138
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b138;
    }
    // 0046b110  8b3510734c00           -mov esi, dword ptr [0x4c7310]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5010192) /* 0x4c7310 */);
    // 0046b116  8d7c244c               -lea edi, [esp + 0x4c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0046b11a  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b11c  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046b11e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046b11f:
    // 0046b11f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046b121  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046b123  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046b125  7410                   -je 0x46b137
    if (cpu.flags.zf)
    {
        goto L_0x0046b137;
    }
    // 0046b127  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046b12a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046b12d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046b130  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046b133  3c00                   +cmp al, 0
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046b135  75e8                   -jne 0x46b11f
    if (!cpu.flags.zf)
    {
        goto L_0x0046b11f;
    }
L_0x0046b137:
    // 0046b137  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046b138:
    // 0046b138  8b742460               -mov esi, dword ptr [esp + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046b13c  41                     -inc ecx
    (cpu.ecx)++;
    // 0046b13d  83c340                 -add ebx, 0x40
    (cpu.ebx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046b140  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b142  7cb7                   -jl 0x46b0fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b0fb;
    }
L_0x0046b144:
    // 0046b144  3b6c245c               +cmp ebp, dword ptr [esp + 0x5c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b148  7468                   -je 0x46b1b2
    if (cpu.flags.zf)
    {
        goto L_0x0046b1b2;
    }
    // 0046b14a  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046b14e  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0046b153  8b3510734c00           -mov esi, dword ptr [0x4c7310]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5010192) /* 0x4c7310 */);
    // 0046b159  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046b15b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b15d  c1e506                 -shl ebp, 6
    cpu.ebp <<= 6 /*0x6*/ % 32;
    // 0046b160  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b161  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b163  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046b166  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0046b168  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046b16a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046b16d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0046b16f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b170  a110734c00             -mov eax, dword ptr [0x4c7310]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5010192) /* 0x4c7310 */);
    // 0046b175  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046b179  8d3428                 -lea esi, [eax + ebp]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0046b17c  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0046b181  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b183  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b184  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b186  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046b189  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0046b18b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046b18d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046b190  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0046b192  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b193  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0046b198  8b3d10734c00           -mov edi, dword ptr [0x4c7310]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5010192) /* 0x4c7310 */);
    // 0046b19e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046b1a0  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046b1a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b1a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b1a5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046b1a8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0046b1aa  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046b1ac  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046b1af  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0046b1b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046b1b2:
    // 0046b1b2  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046b1b6  8b54245c               -mov edx, dword ptr [esp + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0046b1ba  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046b1be  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046b1c1  42                     -inc edx
    (cpu.edx)++;
    // 0046b1c2  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0046b1c6  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 0046b1ca  39ca                   +cmp edx, ecx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b1cc  0f8cecfeffff           -jl 0x46b0be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b0be;
    }
L_0x0046b1d2:
    // 0046b1d2  be0c734c00             -mov esi, 0x4c730c
    cpu.esi = 5010188 /*0x4c730c*/;
    // 0046b1d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046b1d9  83c468                 -add esp, 0x68
    (cpu.esp) += x86::reg32(x86::sreg32(104 /*0x68*/));
    // 0046b1dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b1e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b1f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b1f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b1f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b1f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b1f4  8b35fc724c00           -mov esi, dword ptr [0x4c72fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5010172) /* 0x4c72fc */);
    // 0046b1fa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046b1fc  833d18734c0000         +cmp dword ptr [0x4c7318], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5010200) /* 0x4c7318 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b203  0f849d000000           -je 0x46b2a6
    if (cpu.flags.zf)
    {
        goto L_0x0046b2a6;
    }
L_0x0046b209:
    // 0046b209  833d00734c0000         +cmp dword ptr [0x4c7300], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5010176) /* 0x4c7300 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b210  7412                   -je 0x46b224
    if (cpu.flags.zf)
    {
        goto L_0x0046b224;
    }
    // 0046b212  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046b214  b848815100             -mov eax, 0x518148
    cpu.eax = 5341512 /*0x518148*/;
    // 0046b219  893d00734c00           -mov dword ptr [0x4c7300], edi
    app->getMemory<x86::reg32>(x86::reg32(5010176) /* 0x4c7300 */) = cpu.edi;
    // 0046b21f  e8681b0200             -call 0x48cd8c
    cpu.esp -= 4;
    sub_48cd8c(app, cpu);
    if (cpu.terminate) return;
L_0x0046b224:
    // 0046b224  833d04734c0000         +cmp dword ptr [0x4c7304], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b22b  7520                   -jne 0x46b24d
    if (!cpu.flags.zf)
    {
        goto L_0x0046b24d;
    }
    // 0046b22d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b22e  b8c4bd4b00             -mov eax, 0x4bbdc4
    cpu.eax = 4963780 /*0x4bbdc4*/;
    // 0046b233  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0046b238  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0046b23d  e842240200             -call 0x48d684
    cpu.esp -= 4;
    sub_48d684(app, cpu);
    if (cpu.terminate) return;
    // 0046b242  b880250000             -mov eax, 0x2580
    cpu.eax = 9600 /*0x2580*/;
    // 0046b247  e884f1ffff             -call 0x46a3d0
    cpu.esp -= 4;
    sub_46a3d0(app, cpu);
    if (cpu.terminate) return;
    // 0046b24c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046b24d:
    // 0046b24d  a104734c00             -mov eax, dword ptr [0x4c7304]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
    // 0046b252  8b35fc724c00           -mov esi, dword ptr [0x4c72fc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5010172) /* 0x4c72fc */);
    // 0046b258  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b25a  743f                   -je 0x46b29b
    if (cpu.flags.zf)
    {
        goto L_0x0046b29b;
    }
    // 0046b25c  8b1520835100           -mov edx, dword ptr [0x518320]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5341984) /* 0x518320 */);
    // 0046b262  46                     -inc esi
    (cpu.esi)++;
    // 0046b263  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b265  7c02                   -jl 0x46b269
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b269;
    }
    // 0046b267  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046b269:
    // 0046b269  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046b26b  741a                   -je 0x46b287
    if (cpu.flags.zf)
    {
        goto L_0x0046b287;
    }
    // 0046b26d  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0046b274  8b1504734c00           -mov edx, dword ptr [0x4c7304]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
    // 0046b27a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046b27c  8a44820f               -mov al, byte ptr [edx + eax*4 + 0xf]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4);
    // 0046b280  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046b285  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x0046b287:
    // 0046b287  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 0046b28e  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0046b291  a104734c00             -mov eax, dword ptr [0x4c7304]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5010180) /* 0x4c7304 */);
    // 0046b296  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046b299  01d0                   +add eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0046b29b:
    // 0046b29b  8935fc724c00           -mov dword ptr [0x4c72fc], esi
    app->getMemory<x86::reg32>(x86::reg32(5010172) /* 0x4c72fc */) = cpu.esi;
    // 0046b2a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b2a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b2a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b2a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b2a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b2a6:
    // 0046b2a6  e80d3d0100             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0046b2ab  a318734c00             -mov dword ptr [0x4c7318], eax
    app->getMemory<x86::reg32>(x86::reg32(5010200) /* 0x4c7318 */) = cpu.eax;
    // 0046b2b0  e954ffffff             -jmp 0x46b209
    goto L_0x0046b209;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b2c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b2c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b2c2  b9e0b24600             -mov ecx, 0x46b2e0
    cpu.ecx = 4633312 /*0x46b2e0*/;
    // 0046b2c7  ba00b34600             -mov edx, 0x46b300
    cpu.edx = 4633344 /*0x46b300*/;
    // 0046b2cc  890dc8844c00           -mov dword ptr [0x4c84c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014728) /* 0x4c84c8 */) = cpu.ecx;
    // 0046b2d2  8915c4844c00           -mov dword ptr [0x4c84c4], edx
    app->getMemory<x86::reg32>(x86::reg32(5014724) /* 0x4c84c4 */) = cpu.edx;
    // 0046b2d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b2d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b2da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b2e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b2e1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046b2e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b2e5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046b2e7  7502                   -jne 0x46b2eb
    if (!cpu.flags.zf)
    {
        goto L_0x0046b2eb;
    }
    // 0046b2e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b2ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b2eb:
    // 0046b2eb  e888dc0000             -call 0x478f78
    cpu.esp -= 4;
    sub_478f78(app, cpu);
    if (cpu.terminate) return;
    // 0046b2f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b2f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b300  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b312  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b313  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b314  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b315  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046b317  a190895100             -mov eax, dword ptr [0x518990]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046b31c  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0046b31f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b321  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046b326  e8f50a0000             -call 0x46be20
    cpu.esp -= 4;
    sub_46be20(app, cpu);
    if (cpu.terminate) return;
    // 0046b32b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046b32d  8db300010000           -lea esi, [ebx + 0x100]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(256) /* 0x100 */);
L_0x0046b333:
    // 0046b333  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b335  8b1d90895100           -mov ebx, dword ptr [0x518990]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046b33b  e870e1ffff             -call 0x4694b0
    cpu.esp -= 4;
    sub_4694b0(app, cpu);
    if (cpu.terminate) return;
    // 0046b340  8b3d90895100           -mov edi, dword ptr [0x518990]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046b346  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046b348  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046b34a  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046b34c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046b34e  41                     -inc ecx
    (cpu.ecx)++;
    // 0046b34f  e8ec0a0000             -call 0x46be40
    cpu.esp -= 4;
    sub_46be40(app, cpu);
    if (cpu.terminate) return;
    // 0046b354  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046b35a  83f910                 +cmp ecx, 0x10
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b35d  7cd4                   -jl 0x46b333
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b333;
    }
    // 0046b35f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b360  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b361  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b362  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b363  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b364  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b370  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0046b373  01d0                   +add eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046b375  e94e0d0200             -jmp 0x48c0c8
    return sub_48c0c8(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b380  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b381  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046b383  a190895100             -mov eax, dword ptr [0x518990]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046b388  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0046b38b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046b38d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b38e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46b390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b390  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b391  8b158c895100           -mov edx, dword ptr [0x51898c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343628) /* 0x51898c */);
    // 0046b397  81fae0020000           +cmp edx, 0x2e0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(736 /*0x2e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b39d  7d0d                   -jge 0x46b3ac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b3ac;
    }
    // 0046b39f  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046b3a2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b3a4  89158c895100           -mov dword ptr [0x51898c], edx
    app->getMemory<x86::reg32>(x86::reg32(5343628) /* 0x51898c */) = cpu.edx;
    // 0046b3aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b3ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b3ac:
    // 0046b3ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b3ae  89158c895100           -mov dword ptr [0x51898c], edx
    app->getMemory<x86::reg32>(x86::reg32(5343628) /* 0x51898c */) = cpu.edx;
    // 0046b3b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b3b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b3c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b3c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b3c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b3c3  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0046b3c8  b970c34b00             -mov ecx, 0x4bc370
    cpu.ecx = 4965232 /*0x4bc370*/;
    // 0046b3cd  bb5a020000             -mov ebx, 0x25a
    cpu.ebx = 602 /*0x25a*/;
    // 0046b3d2  b8c4c44b00             -mov eax, 0x4bc4c4
    cpu.eax = 4965572 /*0x4bc4c4*/;
    // 0046b3d7  89158c895100           -mov dword ptr [0x51898c], edx
    app->getMemory<x86::reg32>(x86::reg32(5343628) /* 0x51898c */) = cpu.edx;
    // 0046b3dd  891d90844c00           -mov dword ptr [0x4c8490], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebx;
    // 0046b3e3  ba00e00200             -mov edx, 0x2e000
    cpu.edx = 188416 /*0x2e000*/;
    // 0046b3e8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b3ea  890d8c844c00           -mov dword ptr [0x4c848c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ecx;
    // 0046b3f0  e873d20000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046b3f5  a390895100             -mov dword ptr [0x518990], eax
    app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */) = cpu.eax;
    // 0046b3fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b3fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b3fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b3fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46b400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b400  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b401  ba84835100             -mov edx, 0x518384
    cpu.edx = 5342084 /*0x518384*/;
    // 0046b406  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b408  e803ffffff             -call 0x46b310
    cpu.esp -= 4;
    sub_46b310(app, cpu);
    if (cpu.terminate) return;
    // 0046b40d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046b40f:
    // 0046b40f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b411  42                     -inc edx
    (cpu.edx)++;
    // 0046b412  e809000000             -call 0x46b420
    cpu.esp -= 4;
    sub_46b420(app, cpu);
    if (cpu.terminate) return;
    // 0046b417  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b41a  7cf3                   -jl 0x46b40f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b40f;
    }
    // 0046b41c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b41d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46b420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b421  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b423  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046b425  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046b428  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b42a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046b42d  0524835100             -add eax, 0x518324
    (cpu.eax) += x86::reg32(x86::sreg32(5341988 /*0x518324*/));
    // 0046b432  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046b435  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046b437  7429                   -je 0x46b462
    if (cpu.flags.zf)
    {
        goto L_0x0046b462;
    }
L_0x0046b439:
    // 0046b439  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046b43b  8d5108                 -lea edx, [ecx + 8]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046b43e  83fb01                 +cmp ebx, 1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b441  7423                   -je 0x46b466
    if (cpu.flags.zf)
    {
        goto L_0x0046b466;
    }
    // 0046b443  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046b445  752c                   -jne 0x46b473
    if (!cpu.flags.zf)
    {
        goto L_0x0046b473;
    }
    // 0046b447  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046b44a  e861090000             -call 0x46bdb0
    cpu.esp -= 4;
    sub_46bdb0(app, cpu);
    if (cpu.terminate) return;
L_0x0046b44f:
    // 0046b44f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b451  8b9110070000           -mov edx, dword ptr [ecx + 0x710]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1808) /* 0x710 */);
    // 0046b457  e870d60000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046b45c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046b45e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046b460  75d7                   -jne 0x46b439
    if (!cpu.flags.zf)
    {
        goto L_0x0046b439;
    }
L_0x0046b462:
    // 0046b462  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b463  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b464  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b465  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b466:
    // 0046b466  8b810c070000           -mov eax, dword ptr [ecx + 0x70c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */);
    // 0046b46c  e89ffeffff             -call 0x46b310
    cpu.esp -= 4;
    sub_46b310(app, cpu);
    if (cpu.terminate) return;
    // 0046b471  ebdc                   -jmp 0x46b44f
    goto L_0x0046b44f;
L_0x0046b473:
    // 0046b473  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b476  75d7                   -jne 0x46b44f
    if (!cpu.flags.zf)
    {
        goto L_0x0046b44f;
    }
    // 0046b478  8b9908070000           -mov ebx, dword ptr [ecx + 0x708]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1800) /* 0x708 */);
    // 0046b47e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046b481  e8ea080000             -call 0x46bd70
    cpu.esp -= 4;
    sub_46bd70(app, cpu);
    if (cpu.terminate) return;
    // 0046b486  ebc7                   -jmp 0x46b44f
    goto L_0x0046b44f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b490  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b491  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b492  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b493  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b496  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046b49a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046b49c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046b49e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046b4a0  741d                   -je 0x46b4bf
    if (cpu.flags.zf)
    {
        goto L_0x0046b4bf;
    }
    // 0046b4a2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046b4a4  81c1fc030000           -add ecx, 0x3fc
    (cpu.ecx) += x86::reg32(x86::sreg32(1020 /*0x3fc*/));
    // 0046b4aa  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
L_0x0046b4ad:
    // 0046b4ad  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b4b0  7514                   -jne 0x46b4c6
    if (!cpu.flags.zf)
    {
        goto L_0x0046b4c6;
    }
L_0x0046b4b2:
    // 0046b4b2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b4b5  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046b4b8  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046b4bb  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b4bd  75ee                   -jne 0x46b4ad
    if (!cpu.flags.zf)
    {
        goto L_0x0046b4ad;
    }
L_0x0046b4bf:
    // 0046b4bf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b4c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b4c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b4c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b4c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b4c6:
    // 0046b4c6  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b4ca  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046b4cc  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b4d0  e8cb070000             -call 0x46bca0
    cpu.esp -= 4;
    sub_46bca0(app, cpu);
    if (cpu.terminate) return;
    // 0046b4d5  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046b4d7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b4db  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046b4e0  e82b0b0000             -call 0x46c010
    cpu.esp -= 4;
    sub_46c010(app, cpu);
    if (cpu.terminate) return;
    // 0046b4e5  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b4e8  74c8                   -je 0x46b4b2
    if (cpu.flags.zf)
    {
        goto L_0x0046b4b2;
    }
    // 0046b4ea  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0046b4f0  ebc0                   -jmp 0x46b4b2
    goto L_0x0046b4b2;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b500  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b501  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b502  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b503  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046b506  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046b50a  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046b50e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0046b510  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046b512  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046b514  7467                   -je 0x46b57d
    if (cpu.flags.zf)
    {
        goto L_0x0046b57d;
    }
    // 0046b516  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046b518  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046b51c  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0046b51f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046b521  7e32                   -jle 0x46b555
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b555;
    }
L_0x0046b523:
    // 0046b523  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b527  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046b52b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046b52d  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046b531  e86a070000             -call 0x46bca0
    cpu.esp -= 4;
    sub_46bca0(app, cpu);
    if (cpu.terminate) return;
    // 0046b536  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b53a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046b53f  e8cc0a0000             -call 0x46c010
    cpu.esp -= 4;
    sub_46c010(app, cpu);
    if (cpu.terminate) return;
    // 0046b544  83f8ff                 +cmp eax, -1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b547  7418                   -je 0x46b561
    if (cpu.flags.zf)
    {
        goto L_0x0046b561;
    }
L_0x0046b549:
    // 0046b549  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046b54d  45                     -inc ebp
    (cpu.ebp)++;
    // 0046b54e  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046b551  39c5                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b553  7cce                   -jl 0x46b523
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b523;
    }
L_0x0046b555:
    // 0046b555  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b558  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046b55b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b55c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b55d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b55e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0046b561:
    // 0046b561  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046b563  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046b565  83c703                 +add edi, 3
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046b568  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046b56b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b56e  8847fe                 -mov byte ptr [edi - 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */) = cpu.al;
    // 0046b571  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046b572  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0046b575  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046b578  8847ff                 -mov byte ptr [edi - 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0046b57b  ebcc                   -jmp 0x46b549
    goto L_0x0046b549;
L_0x0046b57d:
    // 0046b57d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046b581  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046b584  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0046b58b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b58d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b58e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b590  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046b593  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0046b595  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046b597  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046b59a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0046b59c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b59d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b5a0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046b5a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5a6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b5b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b5b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b5b2  833d8889510000         +cmp dword ptr [0x518988], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5343624) /* 0x518988 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b5b9  7425                   -je 0x46b5e0
    if (cpu.flags.zf)
    {
        goto L_0x0046b5e0;
    }
    // 0046b5bb  8b1584895100           -mov edx, dword ptr [0x518984]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343620) /* 0x518984 */);
    // 0046b5c1  0310                   -add edx, dword ptr [eax]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 0046b5c3  b9ff000000             -mov ecx, 0xff
    cpu.ecx = 255 /*0xff*/;
    // 0046b5c8  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b5ca  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046b5cc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046b5ce  7e10                   -jle 0x46b5e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b5e0;
    }
    // 0046b5d0  3b0d88895100           +cmp ecx, dword ptr [0x518988]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5343624) /* 0x518988 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b5d6  7d06                   -jge 0x46b5de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b5de;
    }
    // 0046b5d8  890d88895100           -mov dword ptr [0x518988], ecx
    app->getMemory<x86::reg32>(x86::reg32(5343624) /* 0x518988 */) = cpu.ecx;
L_0x0046b5de:
    // 0046b5de  0110                   -add dword ptr [eax], edx
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0046b5e0:
    // 0046b5e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b5e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b5f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b5f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b5f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b5f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b5f4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046b5f7  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0046b5fb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046b5fd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046b600  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b602  bd24835100             -mov ebp, 0x518324
    cpu.ebp = 5341988 /*0x518324*/;
    // 0046b607  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046b60a  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b60c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b60e  e8cd0d0000             -call 0x46c3e0
    cpu.esp -= 4;
    sub_46c3e0(app, cpu);
    if (cpu.terminate) return;
    // 0046b613  8b6d08                 -mov ebp, dword ptr [ebp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046b616  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046b618  7471                   -je 0x46b68b
    if (cpu.flags.zf)
    {
        goto L_0x0046b68b;
    }
L_0x0046b61a:
    // 0046b61a  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b61d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046b61f  7460                   -je 0x46b681
    if (cpu.flags.zf)
    {
        goto L_0x0046b681;
    }
    // 0046b621  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b623  e8b8e60100             -call 0x489ce0
    cpu.esp -= 4;
    sub_489ce0(app, cpu);
    if (cpu.terminate) return;
    // 0046b628  ba68c44b00             -mov edx, 0x4bc468
    cpu.edx = 4965480 /*0x4bc468*/;
    // 0046b62d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046b62f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b631  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b634  8dbd08030000           -lea edi, [ebp + 0x308]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(776) /* 0x308 */);
    // 0046b63a  e859b70000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046b63f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b641  745e                   -je 0x46b6a1
    if (cpu.flags.zf)
    {
        goto L_0x0046b6a1;
    }
    // 0046b643  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 0046b648  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046b64b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b64c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b64e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046b651  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 4;
            cpu.esi -= 4;
        }
        else
        {
            cpu.edi += 4;
            cpu.esi += 4;
        }
        --cpu.ecx;
    }
    // 0046b653  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046b655  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046b658  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = app->getMemory<x86::reg8>(cpu.esi);
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
            cpu.esi -= 1;
        }
        else
        {
            cpu.edi += 1;
            cpu.esi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0046b65a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046b65b:
    // 0046b65b  b884865100             -mov eax, 0x518684
    cpu.eax = 5342852 /*0x518684*/;
    // 0046b660  8dbd08030000           -lea edi, [ebp + 0x308]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(776) /* 0x308 */);
    // 0046b666  8b1584895100           -mov edx, dword ptr [0x518984]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343620) /* 0x518984 */);
    // 0046b66c  8d7508                 -lea esi, [ebp + 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046b66f  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046b671  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046b673  e818feffff             -call 0x46b490
    cpu.esp -= 4;
    sub_46b490(app, cpu);
    if (cpu.terminate) return;
    // 0046b678  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046b67a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046b67c  e82f0d0000             -call 0x46c3b0
    cpu.esp -= 4;
    sub_46c3b0(app, cpu);
    if (cpu.terminate) return;
L_0x0046b681:
    // 0046b681  8bad10070000           -mov ebp, dword ptr [ebp + 0x710]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1808) /* 0x710 */);
    // 0046b687  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046b689  758f                   -jne 0x46b61a
    if (!cpu.flags.zf)
    {
        goto L_0x0046b61a;
    }
L_0x0046b68b:
    // 0046b68b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b68f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046b691  e86a0a0000             -call 0x46c100
    cpu.esp -= 4;
    sub_46c100(app, cpu);
    if (cpu.terminate) return;
    // 0046b696  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b699  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046b69c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b69d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b69e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b69f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b6a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b6a1:
    // 0046b6a1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046b6a3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046b6a5  7eb4                   -jle 0x46b65b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b65b;
    }
    // 0046b6a7  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0046b6a9:
    // 0046b6a9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046b6ab  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b6ae  e831e60100             -call 0x489ce4
    cpu.esp -= 4;
    sub_489ce4(app, cpu);
    if (cpu.terminate) return;
    // 0046b6b3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046b6b5  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046b6bb  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b6be  7509                   -jne 0x46b6c9
    if (!cpu.flags.zf)
    {
        goto L_0x0046b6c9;
    }
    // 0046b6c0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046b6c2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046b6c4  e8c7070000             -call 0x46be90
    cpu.esp -= 4;
    sub_46be90(app, cpu);
    if (cpu.terminate) return;
L_0x0046b6c9:
    // 0046b6c9  41                     -inc ecx
    (cpu.ecx)++;
    // 0046b6ca  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b6cc  7d8d                   -jge 0x46b65b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b65b;
    }
    // 0046b6ce  ebd9                   -jmp 0x46b6a9
    goto L_0x0046b6a9;
}

/* align: skip  */
void Application::sub_46b6d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b6d0  b884835100             -mov eax, 0x518384
    cpu.eax = 5342084 /*0x518384*/;
    // 0046b6d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b6e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b6e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b6e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b6e2  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0046b6e8  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 0046b6ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b6ec  8825ca834c00           -mov byte ptr [0x4c83ca], ah
    app->getMemory<x86::reg8>(x86::reg32(5014474) /* 0x4c83ca */) = cpu.ah;
    // 0046b6f2  e851fb0100             -call 0x48b248
    cpu.esp -= 4;
    sub_48b248(app, cpu);
    if (cpu.terminate) return;
    // 0046b6f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046b6f9:
    // 0046b6f9  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046b6fc  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0046b6fe  885c04ff               -mov byte ptr [esp + eax - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = cpu.bl;
    // 0046b702  8a9a84835100           -mov bl, byte ptr [edx + 0x518384]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5342084) /* 0x518384 */);
    // 0046b708  885c04fe               -mov byte ptr [esp + eax - 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.bl;
    // 0046b70c  8a9a85835100           -mov bl, byte ptr [edx + 0x518385]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5342085) /* 0x518385 */);
    // 0046b712  885c04fd               -mov byte ptr [esp + eax - 3], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.eax * 1) = cpu.bl;
    // 0046b716  8a9a86835100           -mov bl, byte ptr [edx + 0x518386]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5342086) /* 0x518386 */);
    // 0046b71c  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046b71f  885c04fc               -mov byte ptr [esp + eax - 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.bl;
    // 0046b723  3d00040000             +cmp eax, 0x400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b728  75cf                   -jne 0x46b6f9
    if (!cpu.flags.zf)
    {
        goto L_0x0046b6f9;
    }
    // 0046b72a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046b72c  e837fb0100             -call 0x48b268
    cpu.esp -= 4;
    sub_48b268(app, cpu);
    if (cpu.terminate) return;
    // 0046b731  a3c8824c00             -mov dword ptr [0x4c82c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5014216) /* 0x4c82c8 */) = cpu.eax;
    // 0046b736  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0046b73c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b73d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b73e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46b740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b740  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b741  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b742  bb84835100             -mov ebx, 0x518384
    cpu.ebx = 5342084 /*0x518384*/;
    // 0046b747  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0046b74c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b74e  e845210200             -call 0x48d898
    cpu.esp -= 4;
    sub_48d898(app, cpu);
    if (cpu.terminate) return;
    // 0046b753  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b754  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b755  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b761  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b762  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b763  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b764  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b765  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046b767  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046b769  8b3584895100           -mov esi, dword ptr [0x518984]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5343620) /* 0x518984 */);
    // 0046b76f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046b771  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046b773  7e43                   -jle 0x46b7b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b7b8;
    }
    // 0046b775  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 0046b77c  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046b77e  81c384865100           -add ebx, 0x518684
    (cpu.ebx) += x86::reg32(x86::sreg32(5342852 /*0x518684*/));
L_0x0046b784:
    // 0046b784  8d0476                 -lea eax, [esi + esi*2]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 2);
    // 0046b787  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046b789  889084835100           -mov byte ptr [eax + 0x518384], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5342084) /* 0x518384 */) = cpu.dl;
    // 0046b78f  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046b792  889085835100           -mov byte ptr [eax + 0x518385], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5342085) /* 0x518385 */) = cpu.dl;
    // 0046b798  8a5102                 -mov dl, byte ptr [ecx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0046b79b  47                     -inc edi
    (cpu.edi)++;
    // 0046b79c  889086835100           -mov byte ptr [eax + 0x518386], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5342086) /* 0x518386 */) = cpu.dl;
    // 0046b7a2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046b7a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046b7a6  46                     -inc esi
    (cpu.esi)++;
    // 0046b7a7  e8f4040000             -call 0x46bca0
    cpu.esp -= 4;
    sub_46bca0(app, cpu);
    if (cpu.terminate) return;
    // 0046b7ac  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046b7af  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046b7b2  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b7b4  7cce                   -jl 0x46b784
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b784;
    }
    // 0046b7b6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0046b7b8:
    // 0046b7b8  012d84895100           -add dword ptr [0x518984], ebp
    (app->getMemory<x86::reg32>(x86::reg32(5343620) /* 0x518984 */)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046b7be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b7c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b7d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b7d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b7d2  bb7d010000             -mov ebx, 0x17d
    cpu.ebx = 381 /*0x17d*/;
    // 0046b7d7  ba04885100             -mov edx, 0x518804
    cpu.edx = 5343236 /*0x518804*/;
    // 0046b7dc  b801885100             -mov eax, 0x518801
    cpu.eax = 5343233 /*0x518801*/;
    // 0046b7e1  e86a4f0100             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0046b7e6  bb7d010000             -mov ebx, 0x17d
    cpu.ebx = 381 /*0x17d*/;
    // 0046b7eb  ba04885100             -mov edx, 0x518804
    cpu.edx = 5343236 /*0x518804*/;
    // 0046b7f0  b801855100             -mov eax, 0x518501
    cpu.eax = 5342465 /*0x518501*/;
    // 0046b7f5  e8564f0100             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0046b7fa  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 0046b7fc  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0046b7fe  882501855100           -mov byte ptr [0x518501], ah
    app->getMemory<x86::reg8>(x86::reg32(5342465) /* 0x518501 */) = cpu.ah;
    // 0046b804  881502855100           -mov byte ptr [0x518502], dl
    app->getMemory<x86::reg8>(x86::reg32(5342466) /* 0x518502 */) = cpu.dl;
    // 0046b80a  882503855100           -mov byte ptr [0x518503], ah
    app->getMemory<x86::reg8>(x86::reg32(5342467) /* 0x518503 */) = cpu.ah;
    // 0046b810  88154b834c00           -mov byte ptr [0x4c834b], dl
    app->getMemory<x86::reg8>(x86::reg32(5014347) /* 0x4c834b */) = cpu.dl;
    // 0046b816  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b817  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b818  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b820(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046b821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b822  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046b823  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b824  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b825  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b826  81ec08060000           -sub esp, 0x608
    (cpu.esp) -= x86::reg32(x86::sreg32(1544 /*0x608*/));
    // 0046b82c  b924835100             -mov ecx, 0x518324
    cpu.ecx = 5341988 /*0x518324*/;
    // 0046b831  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b833  898c2404060000         -mov dword ptr [esp + 0x604], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1540) /* 0x604 */) = cpu.ecx;
    // 0046b83a  89942400060000         -mov dword ptr [esp + 0x600], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1536) /* 0x600 */) = cpu.edx;
L_0x0046b841:
    // 0046b841  8bac2404060000         -mov ebp, dword ptr [esp + 0x604]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1540) /* 0x604 */);
    // 0046b848  837d0400               +cmp dword ptr [ebp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b84c  7464                   -je 0x46b8b2
    if (cpu.flags.zf)
    {
        goto L_0x0046b8b2;
    }
    // 0046b84e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046b851  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046b853  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b855  7412                   -je 0x46b869
    if (cpu.flags.zf)
    {
        goto L_0x0046b869;
    }
L_0x0046b857:
    // 0046b857  8bb008070000           -mov esi, dword ptr [eax + 0x708]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1800) /* 0x708 */);
    // 0046b85d  8b8010070000           -mov eax, dword ptr [eax + 0x710]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1808) /* 0x710 */);
    // 0046b863  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046b865  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046b867  75ee                   -jne 0x46b857
    if (!cpu.flags.zf)
    {
        goto L_0x0046b857;
    }
L_0x0046b869:
    // 0046b869  3b5504                 +cmp edx, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b86c  0f8e76000000           -jle 0x46b8e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b8e8;
    }
    // 0046b872  837d0001               +cmp dword ptr [ebp], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b876  7570                   -jne 0x46b8e8
    if (!cpu.flags.zf)
    {
        goto L_0x0046b8e8;
    }
    // 0046b878  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b87b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046b87d  e82efdffff             -call 0x46b5b0
    cpu.esp -= 4;
    sub_46b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0046b882  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b885  8b842400060000         -mov eax, dword ptr [esp + 0x600]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1536) /* 0x600 */);
    // 0046b88c  42                     -inc edx
    (cpu.edx)++;
    // 0046b88d  e85efdffff             -call 0x46b5f0
    cpu.esp -= 4;
    sub_46b5f0(app, cpu);
    if (cpu.terminate) return;
    // 0046b892  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b895  42                     -inc edx
    (cpu.edx)++;
    // 0046b896  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046b898  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046b89a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b89c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046b89e  7e06                   -jle 0x46b8a6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b8a6;
    }
    // 0046b8a0  891588895100           -mov dword ptr [0x518988], edx
    app->getMemory<x86::reg32>(x86::reg32(5343624) /* 0x518988 */) = cpu.edx;
L_0x0046b8a6:
    // 0046b8a6  8d442403               -lea eax, [esp + 3]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 0046b8aa  8d51ff                 -lea edx, [ecx - 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0046b8ad  e8aefeffff             -call 0x46b760
    cpu.esp -= 4;
    sub_46b760(app, cpu);
    if (cpu.terminate) return;
L_0x0046b8b2:
    // 0046b8b2  8b9c2400060000         -mov ebx, dword ptr [esp + 0x600]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1536) /* 0x600 */);
    // 0046b8b9  8b8c2404060000         -mov ecx, dword ptr [esp + 0x604]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1540) /* 0x604 */);
    // 0046b8c0  43                     -inc ebx
    (cpu.ebx)++;
    // 0046b8c1  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046b8c4  899c2400060000         -mov dword ptr [esp + 0x600], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1536) /* 0x600 */) = cpu.ebx;
    // 0046b8cb  898c2404060000         -mov dword ptr [esp + 0x604], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1540) /* 0x604 */) = cpu.ecx;
    // 0046b8d2  83fb08                 +cmp ebx, 8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b8d5  0f8c66ffffff           -jl 0x46b841
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046b841;
    }
    // 0046b8db  81c408060000           -add esp, 0x608
    (cpu.esp) += x86::reg32(x86::sreg32(1544 /*0x608*/));
    // 0046b8e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b8e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b8e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b8e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b8e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b8e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046b8e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046b8e8:
    // 0046b8e8  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b8eb  e8c0fcffff             -call 0x46b5b0
    cpu.esp -= 4;
    sub_46b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0046b8f0  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046b8f3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046b8f5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046b8f7  7448                   -je 0x46b941
    if (cpu.flags.zf)
    {
        goto L_0x0046b941;
    }
L_0x0046b8f9:
    // 0046b8f9  b884865100             -mov eax, 0x518684
    cpu.eax = 5342852 /*0x518684*/;
    // 0046b8fe  8b8f08070000           -mov ecx, dword ptr [edi + 0x708]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1800) /* 0x708 */);
    // 0046b904  8b1584895100           -mov edx, dword ptr [0x518984]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343620) /* 0x518984 */);
    // 0046b90a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046b90b  8d5f08                 -lea ebx, [edi + 8]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046b90e  8d8c2404030000         -lea ecx, [esp + 0x304]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0046b915  e8e6fbffff             -call 0x46b500
    cpu.esp -= 4;
    sub_46b500(app, cpu);
    if (cpu.terminate) return;
    // 0046b91a  8b5d04                 -mov ebx, dword ptr [ebp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b91d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046b91f  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b921  7e06                   -jle 0x46b929
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046b929;
    }
    // 0046b923  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046b925  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046b927  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0046b929:
    // 0046b929  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046b92b  8d842400030000         -lea eax, [esp + 0x300]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0046b932  e829feffff             -call 0x46b760
    cpu.esp -= 4;
    sub_46b760(app, cpu);
    if (cpu.terminate) return;
    // 0046b937  8bbf10070000           -mov edi, dword ptr [edi + 0x710]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1808) /* 0x710 */);
    // 0046b93d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046b93f  75b8                   -jne 0x46b8f9
    if (!cpu.flags.zf)
    {
        goto L_0x0046b8f9;
    }
L_0x0046b941:
    // 0046b941  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046b944  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046b946  0f8d66ffffff           -jge 0x46b8b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046b8b2;
    }
    // 0046b94c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046b94e  29f0                   +sub eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046b950  a388895100             -mov dword ptr [0x518988], eax
    app->getMemory<x86::reg32>(x86::reg32(5343624) /* 0x518988 */) = cpu.eax;
    // 0046b955  e958ffffff             -jmp 0x46b8b2
    goto L_0x0046b8b2;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46b960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046b960  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046b961  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046b962  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046b963  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046b966  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046b969  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046b96b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046b96d  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0046b971  ba70c34b00             -mov edx, 0x4bc370
    cpu.edx = 4965232 /*0x4bc370*/;
    // 0046b976  b9c6000000             -mov ecx, 0xc6
    cpu.ecx = 198 /*0xc6*/;
    // 0046b97b  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046b980  b88cc34b00             -mov eax, 0x4bc38c
    cpu.eax = 4965260 /*0x4bc38c*/;
    // 0046b985  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0046b98b  ba14070000             -mov edx, 0x714
    cpu.edx = 1812 /*0x714*/;
    // 0046b990  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0046b996  e8cdcc0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046b99b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046b99d  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046b9a0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046b9a2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046b9a4  e817050000             -call 0x46bec0
    cpu.esp -= 4;
    sub_46bec0(app, cpu);
    if (cpu.terminate) return;
    // 0046b9a9  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046b9ad  898608070000           -mov dword ptr [esi + 0x708], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1800) /* 0x708 */) = cpu.eax;
    // 0046b9b3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046b9b5  8b8e08070000           -mov ecx, dword ptr [esi + 0x708]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1800) /* 0x708 */);
    // 0046b9bb  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0046b9be  e8bd95fdff             -call 0x444f80
    cpu.esp -= 4;
    sub_444f80(app, cpu);
    if (cpu.terminate) return;
    // 0046b9c3  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0046b9c8  8d8608030000           -lea eax, [esi + 0x308]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(776) /* 0x308 */);
    // 0046b9ce  e809370100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046b9d3  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 0046b9d9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046b9dc  c7860c07000000000000   -mov dword ptr [esi + 0x70c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */) = 0 /*0x0*/;
    // 0046b9e6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046b9e8  c7861007000000000000   -mov dword ptr [esi + 0x710], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1808) /* 0x710 */) = 0 /*0x0*/;
    // 0046b9f2  e879010000             -call 0x46bb70
    cpu.esp -= 4;
    sub_46bb70(app, cpu);
    if (cpu.terminate) return;
    // 0046b9f7  8b860c070000           -mov eax, dword ptr [esi + 0x70c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */);
    // 0046b9fd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ba00  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ba03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ba10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ba10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ba11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ba12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ba13  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ba16  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046ba1a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046ba1c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0046ba1f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046ba21  ba70c34b00             -mov edx, 0x4bc370
    cpu.edx = 4965232 /*0x4bc370*/;
    // 0046ba26  b9a3000000             -mov ecx, 0xa3
    cpu.ecx = 163 /*0xa3*/;
    // 0046ba2b  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046ba30  b88cc34b00             -mov eax, 0x4bc38c
    cpu.eax = 4965260 /*0x4bc38c*/;
    // 0046ba35  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0046ba3b  ba14070000             -mov edx, 0x714
    cpu.edx = 1812 /*0x714*/;
    // 0046ba40  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0046ba46  e81dcc0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046ba4b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046ba4d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ba4f  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046ba52  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046ba54  e867040000             -call 0x46bec0
    cpu.esp -= 4;
    sub_46bec0(app, cpu);
    if (cpu.terminate) return;
    // 0046ba59  898108070000           -mov dword ptr [ecx + 0x708], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1800) /* 0x708 */) = cpu.eax;
    // 0046ba5f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046ba61  e88a97fdff             -call 0x4451f0
    cpu.esp -= 4;
    sub_4451f0(app, cpu);
    if (cpu.terminate) return;
    // 0046ba66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ba68  745d                   -je 0x46bac7
    if (cpu.flags.zf)
    {
        goto L_0x0046bac7;
    }
    // 0046ba6a  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x0046ba71:
    // 0046ba71  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046ba74  8d5e08                 -lea ebx, [esi + 8]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046ba77  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046ba79  8b8e08070000           -mov ecx, dword ptr [esi + 0x708]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1800) /* 0x708 */);
    // 0046ba7f  e8fc94fdff             -call 0x444f80
    cpu.esp -= 4;
    sub_444f80(app, cpu);
    if (cpu.terminate) return;
    // 0046ba84  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0046ba89  8d8608030000           -lea eax, [esi + 0x308]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(776) /* 0x308 */);
    // 0046ba8f  e848360100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046ba94  c70601000000           -mov dword ptr [esi], 1
    app->getMemory<x86::reg32>(cpu.esi) = 1 /*0x1*/;
    // 0046ba9a  e8f1f8ffff             -call 0x46b390
    cpu.esp -= 4;
    sub_46b390(app, cpu);
    if (cpu.terminate) return;
    // 0046ba9f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046baa1  89860c070000           -mov dword ptr [esi + 0x70c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */) = cpu.eax;
    // 0046baa7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046baab  c7861007000000000000   -mov dword ptr [esi + 0x710], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1808) /* 0x710 */) = 0 /*0x0*/;
    // 0046bab5  e8b6000000             -call 0x46bb70
    cpu.esp -= 4;
    sub_46bb70(app, cpu);
    if (cpu.terminate) return;
    // 0046baba  8b860c070000           -mov eax, dword ptr [esi + 0x70c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1804) /* 0x70c */);
    // 0046bac0  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046bac3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bac4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bac5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bac6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bac7:
    // 0046bac7  896904                 -mov dword ptr [ecx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0046baca  eba5                   -jmp 0x46ba71
    goto L_0x0046ba71;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46bad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bad0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bad1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bad2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bad3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046bad4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046bad6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046bad8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046bada  ba70c34b00             -mov edx, 0x4bc370
    cpu.edx = 4965232 /*0x4bc370*/;
    // 0046badf  b989000000             -mov ecx, 0x89
    cpu.ecx = 137 /*0x89*/;
    // 0046bae4  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046bae9  b88cc34b00             -mov eax, 0x4bc38c
    cpu.eax = 4965260 /*0x4bc38c*/;
    // 0046baee  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0046baf4  ba14070000             -mov edx, 0x714
    cpu.edx = 1812 /*0x714*/;
    // 0046baf9  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0046baff  e864cb0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046bb04  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bb06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046bb08  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046bb0b  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0046bb0e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046bb10  e8ab030000             -call 0x46bec0
    cpu.esp -= 4;
    sub_46bec0(app, cpu);
    if (cpu.terminate) return;
    // 0046bb15  898108070000           -mov dword ptr [ecx + 0x708], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1800) /* 0x708 */) = cpu.eax;
    // 0046bb1b  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 0046bb1d  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bb20  7438                   -je 0x46bb5a
    if (cpu.flags.zf)
    {
        goto L_0x0046bb5a;
    }
    // 0046bb22  c7810c07000000000000   -mov dword ptr [ecx + 0x70c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = 0 /*0x0*/;
L_0x0046bb2c:
    // 0046bb2c  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0046bb31  8d8308030000           -lea eax, [ebx + 0x308]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(776) /* 0x308 */);
    // 0046bb37  e8a0350100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046bb3c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046bb3e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046bb40  c7831007000000000000   -mov dword ptr [ebx + 0x710], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1808) /* 0x710 */) = 0 /*0x0*/;
    // 0046bb4a  e821000000             -call 0x46bb70
    cpu.esp -= 4;
    sub_46bb70(app, cpu);
    if (cpu.terminate) return;
    // 0046bb4f  8b830c070000           -mov eax, dword ptr [ebx + 0x70c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1804) /* 0x70c */);
    // 0046bb55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bb5a:
    // 0046bb5a  e831f8ffff             -call 0x46b390
    cpu.esp -= 4;
    sub_46b390(app, cpu);
    if (cpu.terminate) return;
    // 0046bb5f  89810c070000           -mov dword ptr [ecx + 0x70c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1804) /* 0x70c */) = cpu.eax;
    // 0046bb65  ebc5                   -jmp 0x46bb2c
    goto L_0x0046bb2c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bb70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bb71  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bb73  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bb76  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bb78  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bb7b  0524835100             -add eax, 0x518324
    (cpu.eax) += x86::reg32(x86::sreg32(5341988 /*0x518324*/));
    // 0046bb80  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046bb83  898a10070000           -mov dword ptr [edx + 0x710], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1808) /* 0x710 */) = cpu.ecx;
    // 0046bb89  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046bb8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bb8d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46bb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bb90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bb91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bb92  8b3594895100           -mov esi, dword ptr [0x518994]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5343636) /* 0x518994 */);
    // 0046bb98  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bb9a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bb9d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bb9f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046bba2  8d0c32                 -lea ecx, [edx + esi]
    cpu.ecx = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0046bba5  0524835100             -add eax, 0x518324
    (cpu.eax) += x86::reg32(x86::sreg32(5341988 /*0x518324*/));
    // 0046bbaa  81f9ff000000           +cmp ecx, 0xff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bbb0  7e07                   -jle 0x46bbb9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046bbb9;
    }
    // 0046bbb2  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0046bbb7  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046bbb9:
    // 0046bbb9  83e301                 -and ebx, 1
    cpu.ebx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0046bbbc  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0046bbc3  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046bbc5  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046bbc8  893594895100           -mov dword ptr [0x518994], esi
    app->getMemory<x86::reg32>(x86::reg32(5343636) /* 0x518994 */) = cpu.esi;
    // 0046bbce  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0046bbd0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bbd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bbd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bbe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bbe0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bbe1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046bbe3:
    // 0046bbe3  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046bbe6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bbe8  89901c835100           -mov dword ptr [eax + 0x51831c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5341980) /* 0x51831c */) = cpu.edx;
    // 0046bbee  83f860                 +cmp eax, 0x60
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bbf1  75f0                   -jne 0x46bbe3
    if (!cpu.flags.zf)
    {
        goto L_0x0046bbe3;
    }
    // 0046bbf3  891594895100           -mov dword ptr [0x518994], edx
    app->getMemory<x86::reg32>(x86::reg32(5343636) /* 0x518994 */) = cpu.edx;
    // 0046bbf9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bbfa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bc00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bc01  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0046bc06  b884835100             -mov eax, 0x518384
    cpu.eax = 5342084 /*0x518384*/;
    // 0046bc0b  e8cc340100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046bc10  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0046bc15  b884865100             -mov eax, 0x518684
    cpu.eax = 5342852 /*0x518684*/;
    // 0046bc1a  e8bd340100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046bc1f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bc21  891584895100           -mov dword ptr [0x518984], edx
    app->getMemory<x86::reg32>(x86::reg32(5343620) /* 0x518984 */) = cpu.edx;
    // 0046bc27  891588895100           -mov dword ptr [0x518988], edx
    app->getMemory<x86::reg32>(x86::reg32(5343624) /* 0x518988 */) = cpu.edx;
    // 0046bc2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46bc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bc30  a190895100             -mov eax, dword ptr [0x518990]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046bc35  e992ce0000             -jmp 0x478acc
    return sub_478acc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bc40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bc40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bc41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046bc42  e8b995fdff             -call 0x445200
    cpu.esp -= 4;
    sub_445200(app, cpu);
    if (cpu.terminate) return;
    // 0046bc47  e8b4ffffff             -call 0x46bc00
    cpu.esp -= 4;
    sub_46bc00(app, cpu);
    if (cpu.terminate) return;
    // 0046bc4c  e86ff7ffff             -call 0x46b3c0
    cpu.esp -= 4;
    sub_46b3c0(app, cpu);
    if (cpu.terminate) return;
    // 0046bc51  e88affffff             -call 0x46bbe0
    cpu.esp -= 4;
    sub_46bbe0(app, cpu);
    if (cpu.terminate) return;
    // 0046bc56  ba1a000000             -mov edx, 0x1a
    cpu.edx = 26 /*0x1a*/;
    // 0046bc5b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046bc5d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bc5f  e82cffffff             -call 0x46bb90
    cpu.esp -= 4;
    sub_46bb90(app, cpu);
    if (cpu.terminate) return;
    // 0046bc64  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 0046bc69  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046bc6e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046bc70  e81bffffff             -call 0x46bb90
    cpu.esp -= 4;
    sub_46bb90(app, cpu);
    if (cpu.terminate) return;
    // 0046bc75  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046bc7a  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0046bc7f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0046bc84  e807ffffff             -call 0x46bb90
    cpu.esp -= 4;
    sub_46bb90(app, cpu);
    if (cpu.terminate) return;
    // 0046bc89  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046bc8e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046bc90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bc92  e8f9feffff             -call 0x46bb90
    cpu.esp -= 4;
    sub_46bb90(app, cpu);
    if (cpu.terminate) return;
    // 0046bc97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bc99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bca0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bca1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bca2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bca3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bca4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046bca5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bca7  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046bcaa  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046bcad  8d348d00000000         -lea esi, [ecx*4]
    cpu.esi = x86::reg32(cpu.ecx * 4);
    // 0046bcb4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bcb6  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046bcb8  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046bcbb  8b1c8d40794c00         -mov ebx, dword ptr [ecx*4 + 0x4c7940]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5011776) /* 0x4c7940 */ + cpu.ecx * 4);
    // 0046bcc2  039e40764c00           -add ebx, dword ptr [esi + 0x4c7640]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5011008) /* 0x4c7640 */)));
    // 0046bcc8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bcca  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046bccd  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046bcd0  031c8d40734c00         -add ebx, dword ptr [ecx*4 + 0x4c7340]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5010240) /* 0x4c7340 */ + cpu.ecx * 4)));
    // 0046bcd7  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0046bcd9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bcdb  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0046bcdd  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046bce0  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046bce3  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0046bcea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bcec  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046bcee  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046bcf1  8bbb40774c00           -mov edi, dword ptr [ebx + 0x4c7740]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5011264) /* 0x4c7740 */);
    // 0046bcf7  8b0c8d407a4c00         -mov ecx, dword ptr [ecx*4 + 0x4c7a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5012032) /* 0x4c7a40 */ + cpu.ecx * 4);
    // 0046bcfe  8d1c39                 -lea ebx, [ecx + edi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 0046bd01  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bd03  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046bd06  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046bd09  8b0c8d40744c00         -mov ecx, dword ptr [ecx*4 + 0x4c7440]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5010496) /* 0x4c7440 */ + cpu.ecx * 4);
    // 0046bd10  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046bd12  81c100010000           -add ecx, 0x100
    (cpu.ecx) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046bd18  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0046bd1a  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0046bd1d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bd1f  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046bd22  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046bd25  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0046bd2c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046bd2e  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046bd30  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0046bd33  8bab40784c00           -mov ebp, dword ptr [ebx + 0x4c7840]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5011520) /* 0x4c7840 */);
    // 0046bd39  8b0c8d407b4c00         -mov ecx, dword ptr [ecx*4 + 0x4c7b40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5012288) /* 0x4c7b40 */ + cpu.ecx * 4);
    // 0046bd40  8a4002                 -mov al, byte ptr [eax + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046bd43  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046bd45  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046bd4a  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046bd4d  030c8540754c00         -add ecx, dword ptr [eax*4 + 0x4c7540]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5010752) /* 0x4c7540 */ + cpu.eax * 4)));
    // 0046bd54  81c100010000           -add ecx, 0x100
    (cpu.ecx) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046bd5a  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0046bd5c  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 0046bd5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bd64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bd70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bd70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bd71  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046bd77  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bd79  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046bd7b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046bd7d  e81e020000             -call 0x46bfa0
    cpu.esp -= 4;
    sub_46bfa0(app, cpu);
    if (cpu.terminate) return;
    // 0046bd82  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 0046bd84  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046bd86  88a424ff000000         -mov byte ptr [esp + 0xff], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(255) /* 0xff */) = cpu.ah;
    // 0046bd8d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046bd8f  e89cd5ffff             -call 0x469330
    cpu.esp -= 4;
    sub_469330(app, cpu);
    if (cpu.terminate) return;
    // 0046bd94  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046bd96  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046bd98  e843000000             -call 0x46bde0
    cpu.esp -= 4;
    sub_46bde0(app, cpu);
    if (cpu.terminate) return;
    // 0046bd9d  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046bda3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bda4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bdb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bdb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bdb1  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046bdb7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bdb9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046bdbb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046bdbd  e8de010000             -call 0x46bfa0
    cpu.esp -= 4;
    sub_46bfa0(app, cpu);
    if (cpu.terminate) return;
    // 0046bdc2  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 0046bdc4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046bdc6  88a424ff000000         -mov byte ptr [esp + 0xff], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(255) /* 0xff */) = cpu.ah;
    // 0046bdcd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046bdcf  e80c000000             -call 0x46bde0
    cpu.esp -= 4;
    sub_46bde0(app, cpu);
    if (cpu.terminate) return;
    // 0046bdd4  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046bdda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bddb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46bde0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bde0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bde1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bde2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bde3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046bde5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046bde7  e8f4de0100             -call 0x489ce0
    cpu.esp -= 4;
    sub_489ce0(app, cpu);
    if (cpu.terminate) return;
    // 0046bdec  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0046bdee:
    // 0046bdee  49                     -dec ecx
    (cpu.ecx)--;
    // 0046bdef  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bdf2  7504                   -jne 0x46bdf8
    if (!cpu.flags.zf)
    {
        goto L_0x0046bdf8;
    }
    // 0046bdf4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bdf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bdf6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bdf7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bdf8:
    // 0046bdf8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046bdfa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046bdfc  e8e3de0100             -call 0x489ce4
    cpu.esp -= 4;
    sub_489ce4(app, cpu);
    if (cpu.terminate) return;
    // 0046be01  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046be03  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046be09  83fa7b                 +cmp edx, 0x7b
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046be0c  75e0                   -jne 0x46bdee
    if (!cpu.flags.zf)
    {
        goto L_0x0046bdee;
    }
    // 0046be0e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046be10  e85b000000             -call 0x46be70
    cpu.esp -= 4;
    sub_46be70(app, cpu);
    if (cpu.terminate) return;
    // 0046be15  49                     -dec ecx
    (cpu.ecx)--;
    // 0046be16  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046be19  75dd                   -jne 0x46bdf8
    if (!cpu.flags.zf)
    {
        goto L_0x0046bdf8;
    }
    // 0046be1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46be20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046be20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046be21  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046be23  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046be25  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046be27  e874010000             -call 0x46bfa0
    cpu.esp -= 4;
    sub_46bfa0(app, cpu);
    if (cpu.terminate) return;
    // 0046be2c  c681ff000000ff         -mov byte ptr [ecx + 0xff], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(255) /* 0xff */) = 255 /*0xff*/;
    // 0046be33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46be40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046be40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046be41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046be42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046be43  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046be45  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046be47  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046be49  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046be4b  81c3ff000000           -add ebx, 0xff
    (cpu.ebx) += x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x0046be51:
    // 0046be51  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046be53  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046be55  42                     -inc edx
    (cpu.edx)++;
    // 0046be56  8a0c31                 -mov cl, byte ptr [ecx + esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1);
    // 0046be59  40                     -inc eax
    (cpu.eax)++;
    // 0046be5a  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 0046be5d  39d8                   +cmp eax, ebx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046be5f  75f0                   -jne 0x46be51
    if (!cpu.flags.zf)
    {
        goto L_0x0046be51;
    }
    // 0046be61  c687ff000000ff         -mov byte ptr [edi + 0xff], 0xff
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(255) /* 0xff */) = 255 /*0xff*/;
    // 0046be68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46be70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046be70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046be71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046be72  8b5802                 -mov ebx, dword ptr [eax + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046be75  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046be78  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046be7b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046be7e  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0046be81  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046be84  e8cb1b0200             -call 0x48da54
    cpu.esp -= 4;
    sub_48da54(app, cpu);
    if (cpu.terminate) return;
    // 0046be89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046be8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46be90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046be90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046be91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046be92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046be93  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046be95  8d4210                 -lea eax, [edx + 0x10]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0046be98  8b4a02                 -mov ecx, dword ptr [edx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046be9b  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046be9e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046bea1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046bea4  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
L_0x0046bea7:
    // 0046bea7  4a                     -dec edx
    (cpu.edx)--;
    // 0046bea8  83faff                 +cmp edx, -1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046beab  740e                   -je 0x46bebb
    if (cpu.flags.zf)
    {
        goto L_0x0046bebb;
    }
    // 0046bead  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046beaf  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046beb1  8b348b                 -mov esi, dword ptr [ebx + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 4);
    // 0046beb4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046beb5  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046beb6  89348b                 -mov dword ptr [ebx + ecx*4], esi
    app->getMemory<x86::reg32>(cpu.ebx + cpu.ecx * 4) = cpu.esi;
    // 0046beb9  ebec                   -jmp 0x46bea7
    goto L_0x0046bea7;
L_0x0046bebb:
    // 0046bebb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bebc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bebd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bebe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46bec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bec2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bec3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bec4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046bec5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046bec7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046bec9  e812de0100             -call 0x489ce0
    cpu.esp -= 4;
    sub_489ce0(app, cpu);
    if (cpu.terminate) return;
    // 0046bece  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0046bed0:
    // 0046bed0  49                     -dec ecx
    (cpu.ecx)--;
    // 0046bed1  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bed4  750a                   -jne 0x46bee0
    if (!cpu.flags.zf)
    {
        goto L_0x0046bee0;
    }
    // 0046bed6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046bed8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046beda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bedb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bedc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bedd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bede  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bedf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bee0:
    // 0046bee0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046bee2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046bee4  e8fbdd0100             -call 0x489ce4
    cpu.esp -= 4;
    sub_489ce4(app, cpu);
    if (cpu.terminate) return;
    // 0046bee9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046beeb  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046bef1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046bef3  83fa24                 +cmp edx, 0x24
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bef6  755a                   -jne 0x46bf52
    if (!cpu.flags.zf)
    {
        goto L_0x0046bf52;
    }
L_0x0046bef8:
    // 0046bef8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046befa  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046befd  8dbd00030000           -lea edi, [ebp + 0x300]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0046bf03:
    // 0046bf03  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046bf05  40                     -inc eax
    (cpu.eax)++;
    // 0046bf06  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0046bf08  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bf0a  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0046bf0c  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046bf0e  40                     -inc eax
    (cpu.eax)++;
    // 0046bf0f  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0046bf12  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046bf14  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046bf17  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0046bf19  40                     -inc eax
    (cpu.eax)++;
    // 0046bf1a  885aff                 -mov byte ptr [edx - 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0046bf1d  39fa                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bf1f  75e2                   -jne 0x46bf03
    if (!cpu.flags.zf)
    {
        goto L_0x0046bf03;
    }
    // 0046bf21  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046bf23  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046bf28  83f822                 +cmp eax, 0x22
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bf2b  7517                   -jne 0x46bf44
    if (!cpu.flags.zf)
    {
        goto L_0x0046bf44;
    }
    // 0046bf2d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046bf2f  8d9500030000           -lea edx, [ebp + 0x300]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0046bf35:
    // 0046bf35  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046bf37  40                     -inc eax
    (cpu.eax)++;
    // 0046bf38  c0e302                 -shl bl, 2
    cpu.bl <<= 2 /*0x2*/ % 32;
    // 0046bf3b  8858ff                 -mov byte ptr [eax - 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 0046bf3e  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bf40  75f3                   -jne 0x46bf35
    if (!cpu.flags.zf)
    {
        goto L_0x0046bf35;
    }
    // 0046bf42  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0046bf44:
    // 0046bf44  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0046bf47  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046bf4a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046bf4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf50  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046bf52:
    // 0046bf52  83fa22                 +cmp edx, 0x22
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(34 /*0x22*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bf55  74a1                   -je 0x46bef8
    if (cpu.flags.zf)
    {
        goto L_0x0046bef8;
    }
    // 0046bf57  83fa2a                 +cmp edx, 0x2a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bf5a  0f8570ffffff           -jne 0x46bed0
    if (!cpu.flags.zf)
    {
        goto L_0x0046bed0;
    }
    // 0046bf60  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046bf62  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046bf65  8dbd00030000           -lea edi, [ebp + 0x300]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(768) /* 0x300 */);
L_0x0046bf6b:
    // 0046bf6b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bf6d  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046bf6f  40                     -inc eax
    (cpu.eax)++;
    // 0046bf70  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 0046bf73  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046bf75  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0046bf77  40                     -inc eax
    (cpu.eax)++;
    // 0046bf78  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0046bf7b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046bf7d  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046bf80  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0046bf82  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046bf85  885afd                 -mov byte ptr [edx - 3], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 0046bf88  39fa                   +cmp edx, edi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bf8a  75df                   -jne 0x46bf6b
    if (!cpu.flags.zf)
    {
        goto L_0x0046bf6b;
    }
    // 0046bf8c  8b5e06                 -mov ebx, dword ptr [esi + 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0046bf8f  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046bf92  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046bf94  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bf99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bfa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bfa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046bfa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046bfa2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046bfa3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046bfa4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046bfa6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046bfa8  8dbaff000000           -lea edi, [edx + 0xff]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(255) /* 0xff */);
L_0x0046bfae:
    // 0046bfae  46                     -inc esi
    (cpu.esi)++;
    // 0046bfaf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046bfb1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bfb3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bfb5  8a5902                 -mov bl, byte ptr [ecx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0046bfb8  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046bfbb  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0046bfbd  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046bfc0  e81b000000             -call 0x46bfe0
    cpu.esp -= 4;
    sub_46bfe0(app, cpu);
    if (cpu.terminate) return;
    // 0046bfc5  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 0046bfc8  39fe                   +cmp esi, edi
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046bfca  75e2                   -jne 0x46bfae
    if (!cpu.flags.zf)
    {
        goto L_0x0046bfae;
    }
    // 0046bfcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bfcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bfce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bfcf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046bfd0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46bfe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046bfe0  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0046bfe3  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0046bfe6  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0046bfe9  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046bfec  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0046bfef  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0046bff1  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0046bff3  a1c8824c00             -mov eax, dword ptr [0x4c82c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014216) /* 0x4c82c8 */);
    // 0046bff8  8a0403                 -mov al, byte ptr [ebx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + cpu.eax * 1);
    // 0046bffb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046c000  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c010  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c011  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c012  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c013  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c016  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0046c01a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046c01c  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0046c023  a1a4895100             -mov eax, dword ptr [0x5189a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343652) /* 0x5189a4 */);
    // 0046c028  bf9f860100             -mov edi, 0x1869f
    cpu.edi = 99999 /*0x1869f*/;
    // 0046c02d  8b0c01                 -mov ecx, dword ptr [ecx + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1);
    // 0046c030  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0046c035  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0046c03c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c03e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c040  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c044  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046c047  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046c049  7e24                   -jle 0x46c06f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c06f;
    }
    // 0046c04b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x0046c04d:
    // 0046c04d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046c04f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c051  e82a000000             -call 0x46c080
    cpu.esp -= 4;
    sub_46c080(app, cpu);
    if (cpu.terminate) return;
    // 0046c056  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c059  7f08                   -jg 0x46c063
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046c063;
    }
    // 0046c05b  39f8                   +cmp eax, edi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c05d  7d04                   -jge 0x46c063
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046c063;
    }
    // 0046c05f  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046c061  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0046c063:
    // 0046c063  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c067  43                     -inc ebx
    (cpu.ebx)++;
    // 0046c068  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046c06b  39c3                   +cmp ebx, eax
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c06d  7cde                   -jl 0x46c04d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c04d;
    }
L_0x0046c06f:
    // 0046c06f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046c071  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c074  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c075  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c076  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c077  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c082  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c085  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c087  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c089  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046c08b  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0046c08d  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c08f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046c091  7e60                   -jle 0x46c0f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c0f3;
    }
L_0x0046c093:
    // 0046c093  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 0046c096  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c098  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c09a  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046c09d  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046c0a0  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c0a2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046c0a4  7e51                   -jle 0x46c0f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c0f7;
    }
L_0x0046c0a6:
    // 0046c0a6  8a4002                 -mov al, byte ptr [eax + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046c0a9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046c0ae  8a5202                 -mov dl, byte ptr [edx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046c0b1  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046c0b7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c0b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c0bb  7e3e                   -jle 0x46c0fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c0fb;
    }
L_0x0046c0bd:
    // 0046c0bd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c0bf  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0046c0c3  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 0046c0c6  a1a4895100             -mov eax, dword ptr [0x5189a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343652) /* 0x5189a4 */);
    // 0046c0cb  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046c0ce  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0046c0d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c0d3  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0046c0d5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046c0d8  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0046c0db  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046c0dd  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046c0df  8d0c1a                 -lea ecx, [edx + ebx]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0046c0e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c0e4  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c0e8  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 0046c0eb  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c0ed  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046c0f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c0f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c0f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c0f3:
    // 0046c0f3  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046c0f5  eb9c                   -jmp 0x46c093
    goto L_0x0046c093;
L_0x0046c0f7:
    // 0046c0f7  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046c0f9  ebab                   -jmp 0x46c0a6
    goto L_0x0046c0a6;
L_0x0046c0fb:
    // 0046c0fb  f7d8                   +neg eax
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.eax;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046c0fd  ebbe                   -jmp 0x46c0bd
    goto L_0x0046c0bd;
}

/* align: skip 0x00 */
void Application::sub_46c100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c100  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c101  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c102  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c103  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c104  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c105  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0046c107  81ec1c200000           -sub esp, 0x201c
    (cpu.esp) -= x86::reg32(x86::sreg32(8220 /*0x201c*/));
    // 0046c10d  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0046c110  89842408200000         -mov dword ptr [esp + 0x2008], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8200) /* 0x2008 */) = cpu.eax;
    // 0046c117  8994240c200000         -mov dword ptr [esp + 0x200c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8204) /* 0x200c */) = cpu.edx;
    // 0046c11e  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c123  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 0046c128  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046c12b  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046c12e  89942404200000         -mov dword ptr [esp + 0x2004], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8196) /* 0x2004 */) = cpu.edx;
    // 0046c135  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046c137  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046c13a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c13b  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046c13e  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046c141  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0046c146  e8b50c0000             -call 0x46ce00
    cpu.esp -= 4;
    sub_46ce00(app, cpu);
    if (cpu.terminate) return;
    // 0046c14b  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0046c14f  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0046c153  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c155  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0046c159  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0046c15d  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0046c161  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0046c165  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0046c167:
    // 0046c167  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c16c  3b701c                 +cmp esi, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c16f  7c72                   -jl 0x46c1e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c1e3;
    }
L_0x0046c171:
    // 0046c171  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c176  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046c178  e84fc90000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046c17d  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c182  8bb4240c200000         -mov esi, dword ptr [esp + 0x200c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8204) /* 0x200c */);
    // 0046c189  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0046c18f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046c191  0f84b5010000           -je 0x46c34c
    if (cpu.flags.zf)
    {
        goto L_0x0046c34c;
    }
    // 0046c197  8b942404200000         -mov edx, dword ptr [esp + 0x2004]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8196) /* 0x2004 */);
    // 0046c19e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046c1a5  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c1a9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c1ab  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046c1ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c1af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c1b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c1b3  e8242f0100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
L_0x0046c1b8:
    // 0046c1b8  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c1bd  3b581c                 +cmp ebx, dword ptr [eax + 0x1c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c1c0  0f8d86010000           -jge 0x46c34c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046c34c;
    }
    // 0046c1c6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046c1c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c1cb  e8600b0000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c1d0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c1d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c1d4  0f8519010000           -jne 0x46c2f3
    if (!cpu.flags.zf)
    {
        goto L_0x0046c2f3;
    }
    // 0046c1da  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046c1dd  43                     -inc ebx
    (cpu.ebx)++;
    // 0046c1de  83c11c                 +add ecx, 0x1c
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046c1e1  ebd5                   -jmp 0x46c1b8
    goto L_0x0046c1b8;
L_0x0046c1e3:
    // 0046c1e3  6bde1c                 -imul ebx, esi, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0046c1e6  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c1ea  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c1ec  6bd71c                 -imul edx, edi, 0x1c
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0046c1ef  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c1f3  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c1f5  89942414200000         -mov dword ptr [esp + 0x2014], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8212) /* 0x2014 */) = cpu.edx;
    // 0046c1fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046c1fe  e8fd020000             -call 0x46c500
    cpu.esp -= 4;
    sub_46c500(app, cpu);
    if (cpu.terminate) return;
    // 0046c203  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c205  0f84d0000000           -je 0x46c2db
    if (cpu.flags.zf)
    {
        goto L_0x0046c2db;
    }
    // 0046c20b  8b842414200000         -mov eax, dword ptr [esp + 0x2014]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8212) /* 0x2014 */);
    // 0046c212  837c041c01             +cmp dword ptr [esp + eax + 0x1c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */ + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c217  0f8ea5000000           -jle 0x46c2c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c2c2;
    }
    // 0046c21d  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c222  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046c224  e8c7060000             -call 0x46c8f0
    cpu.esp -= 4;
    sub_46c8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046c229  d99c2418200000         -fstp dword ptr [esp + 0x2018]
    app->getMemory<float>(cpu.esp + x86::reg32(8216) /* 0x2018 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046c230:
    // 0046c230  6bd61c                 -imul edx, esi, 0x1c
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
    // 0046c233  8b842418200000         -mov eax, dword ptr [esp + 0x2018]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8216) /* 0x2018 */);
    // 0046c23a  8b4c141c               -mov ecx, dword ptr [esp + edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */ + cpu.edx * 1);
    // 0046c23e  8984bc041c0000         -mov dword ptr [esp + edi*4 + 0x1c04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.edi * 4) = cpu.eax;
    // 0046c245  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c248  0f8e82000000           -jle 0x46c2d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c2d0;
    }
    // 0046c24e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c252  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c254  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c259  e892060000             -call 0x46c8f0
    cpu.esp -= 4;
    sub_46c8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046c25e  d99c2410200000         -fstp dword ptr [esp + 0x2010]
    app->getMemory<float>(cpu.esp + x86::reg32(8208) /* 0x2010 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0046c265:
    // 0046c265  8b942410200000         -mov edx, dword ptr [esp + 0x2010]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8208) /* 0x2010 */);
    // 0046c26c  8994b4041c0000         -mov dword ptr [esp + esi*4 + 0x1c04], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.esi * 4) = cpu.edx;
L_0x0046c273:
    // 0046c273  8b8424041c0000         -mov eax, dword ptr [esp + 0x1c04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */);
    // 0046c27a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046c27f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046c281  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046c284  39ce                   +cmp esi, ecx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c286  7c28                   -jl 0x46c2b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c2b0;
    }
    // 0046c288  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x0046c28d:
    // 0046c28d  d98414041c0000         +fld dword ptr [esp + edx + 0x1c04]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.edx * 1)));
    // 0046c294  d81c24                 +fcomp dword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp)));
    cpu.fpu.pop();
    // 0046c297  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c299  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046c29a  760c                   -jbe 0x46c2a8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046c2a8;
    }
    // 0046c29c  8b8414041c0000         -mov eax, dword ptr [esp + edx + 0x1c04]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.edx * 1);
    // 0046c2a3  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046c2a5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0046c2a8:
    // 0046c2a8  41                     -inc ecx
    (cpu.ecx)++;
    // 0046c2a9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046c2ac  39f1                   +cmp ecx, esi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c2ae  7edd                   -jle 0x46c28d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046c28d;
    }
L_0x0046c2b0:
    // 0046c2b0  d90424                 +fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046c2b3  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0046c2b5  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 0046c2b7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c2b9  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046c2ba  7329                   -jae 0x46c2e5
    if (!cpu.flags.cf)
    {
        goto L_0x0046c2e5;
    }
    // 0046c2bc  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046c2bd  e9a5feffff             -jmp 0x46c167
    goto L_0x0046c167;
L_0x0046c2c2:
    // 0046c2c2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046c2c4  89842418200000         -mov dword ptr [esp + 0x2018], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8216) /* 0x2018 */) = cpu.eax;
    // 0046c2cb  e960ffffff             -jmp 0x46c230
    goto L_0x0046c230;
L_0x0046c2d0:
    // 0046c2d0  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046c2d2  899c2410200000         -mov dword ptr [esp + 0x2010], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8208) /* 0x2010 */) = cpu.ebx;
    // 0046c2d9  eb8a                   -jmp 0x46c265
    goto L_0x0046c265;
L_0x0046c2db:
    // 0046c2db  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0046c2dc  8984bc041c0000         -mov dword ptr [esp + edi*4 + 0x1c04], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(7172) /* 0x1c04 */ + cpu.edi * 4) = cpu.eax;
    // 0046c2e3  eb8e                   -jmp 0x46c273
    goto L_0x0046c273;
L_0x0046c2e5:
    // 0046c2e5  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c2ea  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046c2eb  89701c                 -mov dword ptr [eax + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0046c2ee  e97efeffff             -jmp 0x46c171
    goto L_0x0046c171;
L_0x0046c2f3:
    // 0046c2f3  8b15a0895100           -mov edx, dword ptr [0x5189a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c2f9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c2fb  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046c2fe  e82d0a0000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c303  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c305  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046c308  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046c30a  8b15a0895100           -mov edx, dword ptr [0x5189a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c310  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046c312  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c314  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046c317  e8140a0000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c31c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c31e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046c321  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046c323  8b15a0895100           -mov edx, dword ptr [0x5189a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c329  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046c32c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c32e  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0046c331  e8fa090000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c336  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c338  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046c33b  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046c33d  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0046c340  83c703                 -add edi, 3
    (cpu.edi) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046c343  43                     -inc ebx
    (cpu.ebx)++;
    // 0046c344  83c11c                 +add ecx, 0x1c
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046c347  e96cfeffff             -jmp 0x46c1b8
    goto L_0x0046c1b8;
L_0x0046c34c:
    // 0046c34c  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c351  8b8c2408200000         -mov ecx, dword ptr [esp + 0x2008]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8200) /* 0x2008 */);
    // 0046c358  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046c35b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0046c35d  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046c360  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046c362  7407                   -je 0x46c36b
    if (cpu.flags.zf)
    {
        goto L_0x0046c36b;
    }
    // 0046c364  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c366  e861c70000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x0046c36b:
    // 0046c36b  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c370  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046c372  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046c374  7512                   -jne 0x46c388
    if (!cpu.flags.zf)
    {
        goto L_0x0046c388;
    }
    // 0046c376  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c37b  e84cc70000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046c380  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046c382  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c383  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c384  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c385  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c386  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c387  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c388:
    // 0046c388  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046c38a  e83dc70000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046c38f  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c394  e833c70000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046c399  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046c39b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c39c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c39d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c39e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c39f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c3b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c3b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c3b2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c3b4  a1a0895100             -mov eax, dword ptr [0x5189a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */);
    // 0046c3b9  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046c3bc  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046c3be  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0046c3c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c3c2  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046c3c5  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046c3c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c3c9  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046c3cc  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046c3cf  e86c0c0000             -call 0x46d040
    cpu.esp -= 4;
    sub_46d040(app, cpu);
    if (cpu.terminate) return;
    // 0046c3d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c3d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c3e0  e80b000000             -call 0x46c3f0
    cpu.esp -= 4;
    sub_46c3f0(app, cpu);
    if (cpu.terminate) return;
    // 0046c3e5  a3a0895100             -mov dword ptr [0x5189a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5343648) /* 0x5189a0 */) = cpu.eax;
    // 0046c3ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c3f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c3f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c3f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c3f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c3f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c3f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c3f6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046c3f8  ba00c54b00             -mov edx, 0x4bc500
    cpu.edx = 4965632 /*0x4bc500*/;
    // 0046c3fd  b964010000             -mov ecx, 0x164
    cpu.ecx = 356 /*0x164*/;
    // 0046c402  b828c54b00             -mov eax, 0x4bc528
    cpu.eax = 4965672 /*0x4bc528*/;
    // 0046c407  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c409  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0046c40f  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0046c414  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0046c41a  e849c20000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046c41f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046c421  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046c423  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c425  7507                   -jne 0x46c42e
    if (!cpu.flags.zf)
    {
        goto L_0x0046c42e;
    }
    // 0046c427  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c428  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c429  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c42a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c42b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c42c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c42d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c42e:
    // 0046c42e  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0046c433  bb00c54b00             -mov ebx, 0x4bc500
    cpu.ebx = 4965632 /*0x4bc500*/;
    // 0046c438  bd6f010000             -mov ebp, 0x16f
    cpu.ebp = 367 /*0x16f*/;
    // 0046c43d  e89a2c0100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046c442  ba10c60800             -mov edx, 0x8c610
    cpu.edx = 574992 /*0x8c610*/;
    // 0046c447  b82cc54b00             -mov eax, 0x4bc52c
    cpu.eax = 4965676 /*0x4bc52c*/;
    // 0046c44c  891d8c844c00           -mov dword ptr [0x4c848c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebx;
    // 0046c452  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c454  892d90844c00           -mov dword ptr [0x4c8490], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebp;
    // 0046c45a  e809c20000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046c45f  ba75010000             -mov edx, 0x175
    cpu.edx = 373 /*0x175*/;
    // 0046c464  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c466  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046c469  b800c54b00             -mov eax, 0x4bc500
    cpu.eax = 4965632 /*0x4bc500*/;
    // 0046c46e  891590844c00           -mov dword ptr [0x4c8490], edx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.edx;
    // 0046c474  ba84310200             -mov edx, 0x23184
    cpu.edx = 143748 /*0x23184*/;
    // 0046c479  a38c844c00             -mov dword ptr [0x4c848c], eax
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.eax;
    // 0046c47e  b838c54b00             -mov eax, 0x4bc538
    cpu.eax = 4965688 /*0x4bc538*/;
    // 0046c483  e8e0c10000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046c488  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046c48b  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0046c48d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046c48f  7529                   -jne 0x46c4ba
    if (!cpu.flags.zf)
    {
        goto L_0x0046c4ba;
    }
L_0x0046c491:
    // 0046c491  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0046c494  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c496  7405                   -je 0x46c49d
    if (cpu.flags.zf)
    {
        goto L_0x0046c49d;
    }
    // 0046c498  e82fc60000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x0046c49d:
    // 0046c49d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046c49f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046c4a1  7407                   -je 0x46c4aa
    if (cpu.flags.zf)
    {
        goto L_0x0046c4aa;
    }
    // 0046c4a3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046c4a5  e822c60000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x0046c4aa:
    // 0046c4aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c4ac  e81bc60000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046c4b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c4b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c4ba:
    // 0046c4ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046c4bc  74d3                   -je 0x46c491
    if (cpu.flags.zf)
    {
        goto L_0x0046c491;
    }
    // 0046c4be  ba10c60800             -mov edx, 0x8c610
    cpu.edx = 574992 /*0x8c610*/;
    // 0046c4c3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046c4c5  e8122c0100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046c4ca  ba84310200             -mov edx, 0x23184
    cpu.edx = 143748 /*0x23184*/;
    // 0046c4cf  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046c4d1  e8062c0100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046c4d6  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046c4d9  89791c                 -mov dword ptr [ecx + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 0046c4dc  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046c4df  0584310200             -add eax, 0x23184
    (cpu.eax) += x86::reg32(x86::sreg32(143748 /*0x23184*/));
    // 0046c4e4  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046c4e7  0584310200             -add eax, 0x23184
    (cpu.eax) += x86::reg32(x86::sreg32(143748 /*0x23184*/));
    // 0046c4ec  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046c4ef  0584310200             -add eax, 0x23184
    (cpu.eax) += x86::reg32(x86::sreg32(143748 /*0x23184*/));
    // 0046c4f4  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046c4f7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c4f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4fb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c4ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46c500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c500  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c501  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c502  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c503  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c504  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046c507  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046c509  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046c50b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046c50d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046c510  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c512  e819080000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c517  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046c51b  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046c51e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c520  e80b080000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c525  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046c529  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046c52c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c52e  e8fd070000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c533  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046c537  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046c53a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046c53c  e8ef070000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c541  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c542  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c546  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c547  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c54b  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046c54f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c550  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c554  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046c557  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c558  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c55c  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046c55e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c55f  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0046c564  41                     -inc ecx
    (cpu.ecx)++;
    // 0046c565  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c566  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046c568  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046c56a  e891010000             -call 0x46c700
    cpu.esp -= 4;
    sub_46c700(app, cpu);
    if (cpu.terminate) return;
    // 0046c56f  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c573  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c574  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c578  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c579  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c57d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c57e  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c582  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c583  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c587  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c58a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c58b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046c590  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046c592  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c593  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046c596  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046c598  41                     -inc ecx
    (cpu.ecx)++;
    // 0046c599  d95c243c               -fstp dword ptr [esp + 0x3c]
    app->getMemory<float>(cpu.esp + x86::reg32(60) /* 0x3c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c59d  e85e010000             -call 0x46c700
    cpu.esp -= 4;
    sub_46c700(app, cpu);
    if (cpu.terminate) return;
    // 0046c5a2  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c5a6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c5a7  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c5ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c5ac  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c5b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046c5b1  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c5b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c5b6  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c5ba  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c5bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046c5be  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046c5c0  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046c5c3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c5c4  41                     -inc ecx
    (cpu.ecx)++;
    // 0046c5c5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046c5c7  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046c5c9  d95c2438               +fstp dword ptr [esp + 0x38]
    app->getMemory<float>(cpu.esp + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c5cd  e82e010000             -call 0x46c700
    cpu.esp -= 4;
    sub_46c700(app, cpu);
    if (cpu.terminate) return;
    // 0046c5d2  d9442424               +fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0046c5d6  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046c5d8  d95c241c               +fstp dword ptr [esp + 0x1c]
    app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c5dc  d85c2420               +fcomp dword ptr [esp + 0x20]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    cpu.fpu.pop();
    // 0046c5e0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c5e2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046c5e3  0f82a9000000           -jb 0x46c692
    if (cpu.flags.cf)
    {
        goto L_0x0046c692;
    }
    // 0046c5e9  d9442424               +fld dword ptr [esp + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0046c5ed  d85c241c               +fcomp dword ptr [esp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0046c5f1  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c5f3  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046c5f4  0f8298000000           -jb 0x46c692
    if (cpu.flags.cf)
    {
        goto L_0x0046c692;
    }
    // 0046c5fa  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c5fd  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 0046c5ff  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046c601  0f8c81000000           -jl 0x46c688
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c688;
    }
L_0x0046c607:
    // 0046c607  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046c60a  895704                 -mov dword ptr [edi + 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046c60d  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c610  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046c613  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c616  895714                 -mov dword ptr [edi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046c619  3c01                   +cmp al, 1
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046c61b  0f8399000000           -jae 0x46c6ba
    if (!cpu.flags.cf)
    {
        goto L_0x0046c6ba;
    }
    // 0046c621  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046c623  7514                   -jne 0x46c639
    if (!cpu.flags.zf)
    {
        goto L_0x0046c639;
    }
    // 0046c625  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046c629  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046c62c  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046c62f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046c631  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046c633  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046c636  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0046c639:
    // 0046c639  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046c63c  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046c63f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c641  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046c643  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046c645  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046c648  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c64a  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046c64d  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046c650  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0046c653  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c655  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046c658  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046c65b  8b570c                 -mov edx, dword ptr [edi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0046c65e  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046c661  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0046c664  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0046c666  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046c668  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046c66a  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046c66d  8b4f10                 -mov ecx, dword ptr [edi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0046c670  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0046c673  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c675  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046c678  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046c67d  895718                 -mov dword ptr [edi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046c680  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046c683  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c684  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c685  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c686  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c687  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c688:
    // 0046c688  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046c68a  83c428                 +add esp, 0x28
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046c68d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c68e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c68f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c690  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c691  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046c692:
    // 0046c692  d9442420               +fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0046c696  d85c2424               +fcomp dword ptr [esp + 0x24]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    cpu.fpu.pop();
    // 0046c69a  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c69c  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046c69d  7214                   -jb 0x46c6b3
    if (cpu.flags.cf)
    {
        goto L_0x0046c6b3;
    }
    // 0046c69f  d9442420               +fld dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 0046c6a3  d85c241c               +fcomp dword ptr [esp + 0x1c]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(28) /* 0x1c */)));
    cpu.fpu.pop();
    // 0046c6a7  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c6a9  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046c6aa  7207                   -jb 0x46c6b3
    if (cpu.flags.cf)
    {
        goto L_0x0046c6b3;
    }
    // 0046c6ac  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0046c6ae  e954ffffff             -jmp 0x46c607
    goto L_0x0046c607;
L_0x0046c6b3:
    // 0046c6b3  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0046c6b5  e94dffffff             -jmp 0x46c607
    goto L_0x0046c607;
L_0x0046c6ba:
    // 0046c6ba  7719                   -ja 0x46c6d5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046c6d5;
    }
    // 0046c6bc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c6c0  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046c6c3  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046c6c6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046c6c8  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046c6ca  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046c6cd  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046c6d0  e964ffffff             -jmp 0x46c639
    goto L_0x0046c639;
L_0x0046c6d5:
    // 0046c6d5  3c02                   +cmp al, 2
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046c6d7  0f855cffffff           -jne 0x46c639
    if (!cpu.flags.zf)
    {
        goto L_0x0046c639;
    }
    // 0046c6dd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c6e0  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046c6e3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046c6e5  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046c6e8  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046c6eb  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046c6ee  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046c6f1  e943ffffff             -jmp 0x46c639
    goto L_0x0046c639;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46c700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c700  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c701  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c702  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c703  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0046c705  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0046c708  83e4f8                 -and esp, 0xfffffff8
    cpu.esp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 0046c70b  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046c70f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046c713  885c2430               -mov byte ptr [esp + 0x30], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.bl;
    // 0046c717  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046c719  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c71b  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046c71e  8a4c2430               -mov cl, byte ptr [esp + 0x30]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046c722  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c726  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046c728  e873040000             -call 0x46cba0
    cpu.esp -= 4;
    sub_46cba0(app, cpu);
    if (cpu.terminate) return;
    // 0046c72d  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c731  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046c735  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046c737  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c73b  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0046c73e  e85d040000             -call 0x46cba0
    cpu.esp -= 4;
    sub_46cba0(app, cpu);
    if (cpu.terminate) return;
    // 0046c743  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c747  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046c74b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046c74d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c751  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0046c754  e847040000             -call 0x46cba0
    cpu.esp -= 4;
    sub_46cba0(app, cpu);
    if (cpu.terminate) return;
    // 0046c759  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c75d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046c761  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046c763  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c767  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046c76a  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0046c76c  e82f040000             -call 0x46cba0
    cpu.esp -= 4;
    sub_46cba0(app, cpu);
    if (cpu.terminate) return;
    // 0046c771  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046c775  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c777  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0046c77a  8b4d10                 -mov ecx, dword ptr [ebp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046c77d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046c780  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 0046c786  39cf                   +cmp edi, ecx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c788  0f8d87000000           -jge 0x46c815
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046c815;
    }
L_0x0046c78e:
    // 0046c78e  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c792  0fb67c2430             -movzx edi, byte ptr [esp + 0x30]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */));
    // 0046c797  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c79b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046c79d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046c79f  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046c7a2  e879020000             -call 0x46ca20
    cpu.esp -= 4;
    sub_46ca20(app, cpu);
    if (cpu.terminate) return;
    // 0046c7a7  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046c7ab  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c7ad  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046c7af  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0046c7b3  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c7b7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046c7b9  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c7bd  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046c7c0  e85b020000             -call 0x46ca20
    cpu.esp -= 4;
    sub_46ca20(app, cpu);
    if (cpu.terminate) return;
    // 0046c7c5  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c7c9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c7cb  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046c7cd  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0046c7d1  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c7d5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046c7d7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c7db  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046c7de  e83d020000             -call 0x46ca20
    cpu.esp -= 4;
    sub_46ca20(app, cpu);
    if (cpu.terminate) return;
    // 0046c7e3  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046c7e7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c7e9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046c7eb  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0046c7ef  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046c7f3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046c7f5  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046c7f9  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046c7fc  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046c800  e81b020000             -call 0x46ca20
    cpu.esp -= 4;
    sub_46ca20(app, cpu);
    if (cpu.terminate) return;
    // 0046c805  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046c807  7517                   -jne 0x46c820
    if (!cpu.flags.zf)
    {
        goto L_0x0046c820;
    }
L_0x0046c809:
    // 0046c809  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046c80c  46                     -inc esi
    (cpu.esi)++;
    // 0046c80d  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046c80f  0f8c79ffffff           -jl 0x46c78e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046c78e;
    }
L_0x0046c815:
    // 0046c815  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 0046c818  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0046c81a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c81b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c81c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046c81d  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0046c820:
    // 0046c820  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046c824  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046c828  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046c82c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046c830  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046c832  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046c836  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046c83a  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046c83c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046c840  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046c842  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046c846  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046c84a  d8c8                   -fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046c84c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046c84e  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0046c852  db44242c               -fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046c856  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046c858  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046c85c  8b4518                 -mov eax, dword ptr [ebp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0046c85f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046c861  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046c865  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046c869  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0046c86c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046c86e  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046c872  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046c876  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0046c879  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046c87b  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0046c87f  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0046c882  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046c884  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046c886  d95c2428               +fstp dword ptr [esp + 0x28]
    app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c88a  0f8479ffffff           -je 0x46c809
    if (cpu.flags.zf)
    {
        goto L_0x0046c809;
    }
    // 0046c890  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046c894  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046c898  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046c89c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046c8a0  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046c8a2  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046c8a6  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046c8aa  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046c8ac  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046c8b0  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046c8b2  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046c8b6  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046c8ba  d8c8                   +fmul st(0)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(0));
    // 0046c8bc  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046c8be  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0046c8c2  db44242c               +fild dword ptr [esp + 0x2c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */))));
    // 0046c8c6  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046c8c8  d8442428               +fadd dword ptr [esp + 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */));
    // 0046c8cc  d9542428               +fst dword ptr [esp + 0x28]
    app->getMemory<float>(cpu.esp + x86::reg32(40) /* 0x28 */) = float(cpu.fpu.st(0));
    // 0046c8d0  d81c24                 +fcomp dword ptr [esp]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.esp)));
    cpu.fpu.pop();
    // 0046c8d3  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0046c8d5  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0046c8d6  0f862dffffff           -jbe 0x46c809
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046c809;
    }
    // 0046c8dc  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046c8e0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046c8e3  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0046c8e6  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0046c8e8  e91cffffff             -jmp 0x46c809
    goto L_0x0046c809;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46c8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046c8f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046c8f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046c8f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046c8f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046c8f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046c8f5  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046c8f8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046c8fa  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046c8fc  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046c8ff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c901  e82a040000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c906  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046c90a  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0046c90d  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046c911  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c913  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c917  e814040000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c91c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046c920  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0046c923  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046c927  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c929  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c92d  e8fe030000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046c932  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0046c936  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046c939  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0046c93d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046c93f  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0046c943  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0046c946  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0046c94a  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c94c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046c950  c1e706                 -shl edi, 6
    cpu.edi <<= 6 /*0x6*/ % 32;
    // 0046c953  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046c955  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c957  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046c95b  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046c95e  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046c961  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c963  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046c965  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0046c968  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046c96a  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0046c96d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046c970  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046c973  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046c976  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046c978  8d2c30                 -lea ebp, [eax + esi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046c97b  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046c97e  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 0046c981  d82490                 -fsub dword ptr [eax + edx*4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + cpu.edx * 4));
    // 0046c984  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046c987  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046c989  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046c98c  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c98e  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046c991  8d042f                 -lea eax, [edi + ebp]
    cpu.eax = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 0046c994  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046c997  d827                   -fsub dword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi));
    // 0046c999  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046c99b  d80490                 -fadd dword ptr [eax + edx*4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + cpu.edx * 4));
    // 0046c99e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046c9a0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046c9a3  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046c9a5  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046c9a8  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046c9aa  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c9ae  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046c9b1  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046c9b3  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046c9b7  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0046c9bb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046c9bd  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0046c9c0  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c9c4  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046c9c6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046c9c8  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046c9ca  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046c9cd  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046c9d1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046c9d3  d827                   -fsub dword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi));
    // 0046c9d5  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046c9d7  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0046c9db  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046c9dd  d80490                 -fadd dword ptr [eax + edx*4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + cpu.edx * 4));
    // 0046c9e0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046c9e4  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046c9e6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046c9e8  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046c9ea  d80406                 -fadd dword ptr [esi + eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 1));
    // 0046c9ed  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046c9ef  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c9f3  d82490                 -fsub dword ptr [eax + edx*4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + cpu.edx * 4));
    // 0046c9f6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046c9f8  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046c9fb  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046c9ff  e82c030000             -call 0x46cd30
    cpu.esp -= 4;
    sub_46cd30(app, cpu);
    if (cpu.terminate) return;
    // 0046ca04  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046ca08  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046ca0c  d87c2404               -fdivr dword ptr [esp + 4]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)) / cpu.fpu.st(0);
    // 0046ca10  d86c2408               -fsubr dword ptr [esp + 8]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) - cpu.fpu.st(0);
    // 0046ca14  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046ca17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ca1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46ca20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ca20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ca21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ca22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ca23  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ca26  80fa01                 +cmp dl, 1
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ca29  737d                   -jae 0x46caa8
    if (!cpu.flags.cf)
    {
        goto L_0x0046caa8;
    }
    // 0046ca2b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0046ca2d  0f8553010000           -jne 0x46cb86
    if (!cpu.flags.zf)
    {
        goto L_0x0046cb86;
    }
    // 0046ca33  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046ca36  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046ca38  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046ca3b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ca3d  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046ca40  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ca42  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046ca45  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0046ca47  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046ca4a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046ca4d  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ca4f  8d3c11                 -lea edi, [ecx + edx]
    cpu.edi = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0046ca52  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046ca55  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046ca58  8d142f                 -lea edx, [edi + ebp]
    cpu.edx = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 0046ca5b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ca5d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046ca60  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046ca64  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046ca66  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046ca69  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ca6b  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046ca6e  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ca72  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ca74  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046ca76  2b141f                 -sub edx, dword ptr [edi + ebx]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 1)));
    // 0046ca79  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046ca7b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046ca7d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046ca7f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046ca82  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ca84  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046ca87  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ca89  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046ca8c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ca8e  8d0429                 -lea eax, [ecx + ebp]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0046ca91  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ca93  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046ca95  8b2c03                 -mov ebp, dword ptr [ebx + eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 0046ca98  8b0419                 -mov eax, dword ptr [ecx + ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebx * 1);
    // 0046ca9b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046ca9d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ca9f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046caa1  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046caa4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046caa5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046caa6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046caa7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046caa8:
    // 0046caa8  7668                   -jbe 0x46cb12
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046cb12;
    }
    // 0046caaa  80fa02                 +cmp dl, 2
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046caad  0f85d3000000           -jne 0x46cb86
    if (!cpu.flags.zf)
    {
        goto L_0x0046cb86;
    }
    // 0046cab3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046cab5  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046cab8  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046caba  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046cabd  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cabf  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cac2  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0046cac5  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046cac8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046caca  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046cacd  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046cad0  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cad2  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046cad5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cad8  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046cadb  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cadd  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046cae0  8d2c0a                 -lea ebp, [edx + ecx]
    cpu.ebp = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0046cae3  8d3c32                 -lea edi, [edx + esi]
    cpu.edi = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0046cae6  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046cae9  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0046caeb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046caed  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046caf0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046caf2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0046caf5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046caf7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046cafa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cafc  29ef                   -sub edi, ebp
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cafe  8b1401                 -mov edx, dword ptr [ecx + eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1);
    // 0046cb01  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0046cb04  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046cb06  8d140f                 -lea edx, [edi + ecx]
    cpu.edx = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 0046cb09  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cb0b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cb0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cb12:
    // 0046cb12  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046cb15  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046cb17  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046cb1a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046cb1c  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046cb1e  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0046cb21  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046cb24  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cb26  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046cb28  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046cb2b  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cb2e  8b5814                 -mov ebx, dword ptr [eax + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046cb31  8d3411                 -lea esi, [ecx + edx]
    cpu.esi = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0046cb34  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046cb37  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0046cb3a  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0046cb3d  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0046cb40  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046cb43  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046cb46  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046cb48  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046cb4c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046cb4f  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cb53  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cb55  2b5500                 -sub edx, dword ptr [ebp]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp)));
    // 0046cb58  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046cb5a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046cb5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cb5e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046cb61  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cb63  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046cb66  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cb68  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046cb6b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cb6d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cb6f  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0046cb72  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cb74  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046cb76  8b3c06                 -mov edi, dword ptr [esi + eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0046cb79  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cb7b  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cb7d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cb7f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cb82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cb86:
    // 0046cb86  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046cb88  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cb8a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cb8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cb90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46cba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cba1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cba2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cba3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046cba4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cba7  80fa01                 +cmp dl, 1
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046cbaa  0f8383000000           -jae 0x46cc33
    if (!cpu.flags.cf)
    {
        goto L_0x0046cc33;
    }
    // 0046cbb0  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0046cbb2  0f855e010000           -jne 0x46cd16
    if (!cpu.flags.zf)
    {
        goto L_0x0046cd16;
    }
    // 0046cbb8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046cbbb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046cbbd  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046cbc0  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cbc2  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046cbc5  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cbc7  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046cbca  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046cbcc  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cbcf  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046cbd2  8d3413                 -lea esi, [ebx + edx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0046cbd5  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cbd7  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046cbda  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046cbdd  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046cbe0  8d142e                 -lea edx, [esi + ebp]
    cpu.edx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0046cbe3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cbe5  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046cbe8  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046cbec  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046cbee  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046cbf1  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cbf3  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046cbf6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cbfa  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cbfc  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cbfe  2b1431                 -sub edx, dword ptr [ecx + esi]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 1)));
    // 0046cc01  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046cc03  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046cc05  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cc07  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046cc0a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cc0c  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046cc0f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cc11  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046cc14  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cc16  8d043b                 -lea eax, [ebx + edi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 0046cc19  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cc1b  8b3c01                 -mov edi, dword ptr [ecx + eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1);
    // 0046cc1e  8d140b                 -lea edx, [ebx + ecx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 0046cc21  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cc23  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cc25  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046cc27  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cc29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cc2b  83c408                 +add esp, 8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046cc2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cc33:
    // 0046cc33  7669                   -jbe 0x46cc9e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046cc9e;
    }
    // 0046cc35  80fa02                 +cmp dl, 2
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046cc38  0f85d8000000           -jne 0x46cd16
    if (!cpu.flags.zf)
    {
        goto L_0x0046cd16;
    }
    // 0046cc3e  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046cc40  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046cc42  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046cc45  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cc47  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046cc4a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cc4c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cc4f  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046cc52  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cc54  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046cc56  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046cc59  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046cc5c  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cc5e  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046cc61  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cc64  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046cc67  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cc69  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046cc6c  8d2c32                 -lea ebp, [edx + esi]
    cpu.ebp = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0046cc6f  8d3c0a                 -lea edi, [edx + ecx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0046cc72  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046cc75  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0046cc77  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046cc79  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046cc7c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cc7e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0046cc81  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cc83  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046cc86  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cc88  29ef                   -sub edi, ebp
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cc8a  8b1401                 -mov edx, dword ptr [ecx + eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1);
    // 0046cc8d  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0046cc90  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cc92  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cc94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cc96  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cc99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cc9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cc9e:
    // 0046cc9e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046cca1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046cca3  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046cca6  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cca8  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046ccab  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ccad  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046ccb0  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046ccb3  8d3413                 -lea esi, [ebx + edx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0046ccb6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046ccb8  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046ccbb  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ccbd  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046ccc0  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046ccc3  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046ccc6  8d140e                 -lea edx, [esi + ecx]
    cpu.edx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0046ccc9  8d343a                 -lea esi, [edx + edi]
    cpu.esi = x86::reg32(cpu.edx + cpu.edi * 1);
    // 0046cccc  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0046cccf  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046ccd2  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046ccd5  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ccd7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046ccdb  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046ccde  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cce2  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cce4  2b5500                 -sub edx, dword ptr [ebp]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp)));
    // 0046cce7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046cce9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046cceb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cced  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046ccf0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ccf2  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046ccf5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ccf7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046ccfa  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ccfc  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ccfe  8b1c31                 -mov ebx, dword ptr [ecx + esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 1);
    // 0046cd01  8d1439                 -lea edx, [ecx + edi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 0046cd04  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cd06  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cd08  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046cd0a  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046cd0c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cd0e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cd11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd15  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046cd16:
    // 0046cd16  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046cd18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cd1a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046cd1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd20  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cd21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46cd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046cd30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046cd31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046cd32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046cd33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046cd34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046cd35  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046cd38  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046cd3a  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046cd3d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046cd3f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046cd42  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cd44  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046cd47  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cd49  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046cd4c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cd4f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046cd51  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046cd53  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0046cd56  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046cd59  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cd5b  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046cd5e  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046cd61  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046cd64  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cd66  8d1c0a                 -lea ebx, [edx + ecx]
    cpu.ebx = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0046cd69  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0046cd6d  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046cd70  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046cd73  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046cd75  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046cd79  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046cd7d  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cd7f  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046cd83  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cd87  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046cd8b  2b2a                   -sub ebp, dword ptr [edx]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0046cd8d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046cd90  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046cd94  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0046cd98  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046cd9c  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046cd9f  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cda1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cda4  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046cda8  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046cdab  03542408               -add edx, dword ptr [esp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046cdaf  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046cdb3  2b2c11                 -sub ebp, dword ptr [ecx + edx]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1)));
    // 0046cdb6  032c1a                 -add ebp, dword ptr [edx + ebx]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 1)));
    // 0046cdb9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046cdbb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cdbd  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046cdc0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cdc2  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046cdc5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046cdc7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046cdca  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046cdcc  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cdce  8d140f                 -lea edx, [edi + ecx]
    cpu.edx = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 0046cdd1  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0046cdd3  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0046cdd5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046cdd7  8b341f                 -mov esi, dword ptr [edi + ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 1);
    // 0046cdda  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046cdde  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cde0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cde2  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046cde4  031401                 -add edx, dword ptr [ecx + eax]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1)));
    // 0046cde7  8b0c03                 -mov ecx, dword ptr [ebx + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 0046cdea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046cdec  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cdee  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046cdf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cdf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cdf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cdf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cdf5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046cdf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ce00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ce00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ce01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ce02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ce03  81ecc4020000           -sub esp, 0x2c4
    (cpu.esp) -= x86::reg32(x86::sreg32(708 /*0x2c4*/));
    // 0046ce09  898424ac020000         -mov dword ptr [esp + 0x2ac], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(684) /* 0x2ac */) = cpu.eax;
    // 0046ce10  8994249c020000         -mov dword ptr [esp + 0x29c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(668) /* 0x29c */) = cpu.edx;
    // 0046ce17  899c2494020000         -mov dword ptr [esp + 0x294], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(660) /* 0x294 */) = cpu.ebx;
    // 0046ce1e  898c2498020000         -mov dword ptr [esp + 0x298], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(664) /* 0x298 */) = cpu.ecx;
    // 0046ce25  c68424c002000001       -mov byte ptr [esp + 0x2c0], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(704) /* 0x2c0 */) = 1 /*0x1*/;
L_0x0046ce2d:
    // 0046ce2d  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
L_0x0046ce2f:
    // 0046ce2f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ce31  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ce33  898c24bc020000         -mov dword ptr [esp + 0x2bc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */) = cpu.ecx;
    // 0046ce3a  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0046ce3c  db8424bc020000         -fild dword ptr [esp + 0x2bc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */))));
    // 0046ce43  fec2                   -inc dl
    (cpu.dl)++;
    // 0046ce45  898c8410020000         -mov dword ptr [esp + eax*4 + 0x210], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.eax * 4) = cpu.ecx;
    // 0046ce4c  898c8408010000         -mov dword ptr [esp + eax*4 + 0x108], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */ + cpu.eax * 4) = cpu.ecx;
    // 0046ce53  898c8484000000         -mov dword ptr [esp + eax*4 + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */ + cpu.eax * 4) = cpu.ecx;
    // 0046ce5a  898c848c010000         -mov dword ptr [esp + eax*4 + 0x18c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */ + cpu.eax * 4) = cpu.ecx;
    // 0046ce61  d91c84                 -fstp dword ptr [esp + eax*4]
    app->getMemory<float>(cpu.esp + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ce64  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ce67  76c6                   -jbe 0x46ce2f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046ce2f;
    }
    // 0046ce69  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
L_0x0046ce6b:
    // 0046ce6b  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0046ce6d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046ce6f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046ce71  89bc24b4020000         -mov dword ptr [esp + 0x2b4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(692) /* 0x2b4 */) = cpu.edi;
    // 0046ce78  89bc24b8020000         -mov dword ptr [esp + 0x2b8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(696) /* 0x2b8 */) = cpu.edi;
    // 0046ce7f  89bc24b0020000         -mov dword ptr [esp + 0x2b0], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(688) /* 0x2b0 */) = cpu.edi;
    // 0046ce86  d98424b0020000         -fld dword ptr [esp + 0x2b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(688) /* 0x2b0 */)));
L_0x0046ce8d:
    // 0046ce8d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ce8f  8a8424c0020000         -mov al, byte ptr [esp + 0x2c0]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0046ce96  69d041040000           -imul edx, eax, 0x441
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1089 /*0x441*/)));
    // 0046ce9c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ce9e  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 0046cea0  6bc021                 -imul eax, eax, 0x21
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(33 /*0x21*/)));
    // 0046cea3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cea5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046cea7  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0046cea9  8bac24ac020000         -mov ebp, dword ptr [esp + 0x2ac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(684) /* 0x2ac */);
    // 0046ceb0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ceb2  898424bc020000         -mov dword ptr [esp + 0x2bc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */) = cpu.eax;
    // 0046ceb9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046cec0  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cec2  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046cec5  018c24b8020000         -add dword ptr [esp + 0x2b8], ecx
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(696) /* 0x2b8 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cecc  8b8c249c020000         -mov ecx, dword ptr [esp + 0x29c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(668) /* 0x29c */);
    // 0046ced3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ced5  898c24a0020000         -mov dword ptr [esp + 0x2a0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(672) /* 0x2a0 */) = cpu.ecx;
    // 0046cedc  0331                   -add esi, dword ptr [ecx]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0046cede  8b8c2494020000         -mov ecx, dword ptr [esp + 0x294]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(660) /* 0x294 */);
    // 0046cee5  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cee7  898c24a4020000         -mov dword ptr [esp + 0x2a4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(676) /* 0x2a4 */) = cpu.ecx;
    // 0046ceee  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046cef0  018c24b4020000         -add dword ptr [esp + 0x2b4], ecx
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(692) /* 0x2b4 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cef7  8b8c2498020000         -mov ecx, dword ptr [esp + 0x298]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(664) /* 0x298 */);
    // 0046cefe  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cf00  898c24a8020000         -mov dword ptr [esp + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046cf07  0339                   -add edi, dword ptr [ecx]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0046cf09  8b8c24d4020000         -mov ecx, dword ptr [esp + 0x2d4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(724) /* 0x2d4 */);
    // 0046cf10  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0046cf12  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046cf14  8b8424bc020000         -mov eax, dword ptr [esp + 0x2bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */);
    // 0046cf1b  898c24bc020000         -mov dword ptr [esp + 0x2bc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */) = cpu.ecx;
    // 0046cf22  d801                   -fadd dword ptr [ecx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx));
    // 0046cf24  8b8c24b8020000         -mov ecx, dword ptr [esp + 0x2b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(696) /* 0x2b8 */);
    // 0046cf2b  018c848c010000         -add dword ptr [esp + eax*4 + 0x18c], ecx
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */ + cpu.eax * 4)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cf32  8b8c8484000000         -mov ecx, dword ptr [esp + eax*4 + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */ + cpu.eax * 4);
    // 0046cf39  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046cf3b  81ea41040000           -sub edx, 0x441
    (cpu.edx) -= x86::reg32(x86::sreg32(1089 /*0x441*/));
    // 0046cf41  898c8484000000         -mov dword ptr [esp + eax*4 + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */ + cpu.eax * 4) = cpu.ecx;
    // 0046cf48  8b8c24b4020000         -mov ecx, dword ptr [esp + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(692) /* 0x2b4 */);
    // 0046cf4f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046cf52  018c8408010000         -add dword ptr [esp + eax*4 + 0x108], ecx
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */ + cpu.eax * 4)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046cf59  8b8c8410020000         -mov ecx, dword ptr [esp + eax*4 + 0x210]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.eax * 4);
    // 0046cf60  d90484                 -fld dword ptr [esp + eax*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + cpu.eax * 4)));
    // 0046cf63  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046cf65  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046cf67  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cf69  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0046cf6b  898c8410020000         -mov dword ptr [esp + eax*4 + 0x210], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.eax * 4) = cpu.ecx;
    // 0046cf72  8b8c24ac020000         -mov ecx, dword ptr [esp + 0x2ac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(684) /* 0x2ac */);
    // 0046cf79  d91c84                 -fstp dword ptr [esp + eax*4]
    app->getMemory<float>(cpu.esp + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cf7c  8b0c11                 -mov ecx, dword ptr [ecx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
    // 0046cf7f  038c848c010000         -add ecx, dword ptr [esp + eax*4 + 0x18c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */ + cpu.eax * 4)));
    // 0046cf86  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0046cf89  8b8c249c020000         -mov ecx, dword ptr [esp + 0x29c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(668) /* 0x29c */);
    // 0046cf90  8bac8484000000         -mov ebp, dword ptr [esp + eax*4 + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */ + cpu.eax * 4);
    // 0046cf97  8b0c11                 -mov ecx, dword ptr [ecx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
    // 0046cf9a  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cf9c  8bac24a0020000         -mov ebp, dword ptr [esp + 0x2a0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(672) /* 0x2a0 */);
    // 0046cfa3  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0046cfa6  8b8c2494020000         -mov ecx, dword ptr [esp + 0x294]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(660) /* 0x294 */);
    // 0046cfad  8bac8408010000         -mov ebp, dword ptr [esp + eax*4 + 0x108]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */ + cpu.eax * 4);
    // 0046cfb4  8b0c11                 -mov ecx, dword ptr [ecx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
    // 0046cfb7  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cfb9  8bac24a4020000         -mov ebp, dword ptr [esp + 0x2a4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(676) /* 0x2a4 */);
    // 0046cfc0  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0046cfc3  8b8c2498020000         -mov ecx, dword ptr [esp + 0x298]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(664) /* 0x298 */);
    // 0046cfca  8bac8410020000         -mov ebp, dword ptr [esp + eax*4 + 0x210]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.eax * 4);
    // 0046cfd1  8b0c11                 -mov ecx, dword ptr [ecx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
    // 0046cfd4  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046cfd6  8bac24a8020000         -mov ebp, dword ptr [esp + 0x2a8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(680) /* 0x2a8 */);
    // 0046cfdd  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0046cfe0  039424d4020000         -add edx, dword ptr [esp + 0x2d4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(724) /* 0x2d4 */)));
    // 0046cfe7  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0046cfe9  d80484                 -fadd dword ptr [esp + eax*4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + cpu.eax * 4));
    // 0046cfec  8b8424bc020000         -mov eax, dword ptr [esp + 0x2bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */);
    // 0046cff3  fec3                   -inc bl
    (cpu.bl)++;
    // 0046cff5  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046cff7  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046cffa  0f868dfeffff           -jbe 0x46ce8d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046ce8d;
    }
    // 0046d000  fec7                   -inc bh
    (cpu.bh)++;
    // 0046d002  d99c24b0020000         -fstp dword ptr [esp + 0x2b0]
    app->getMemory<float>(cpu.esp + x86::reg32(688) /* 0x2b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d009  80ff20                 +cmp bh, 0x20
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046d00c  0f8659feffff           -jbe 0x46ce6b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046ce6b;
    }
    // 0046d012  8a9424c0020000         -mov dl, byte ptr [esp + 0x2c0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0046d019  fec2                   -inc dl
    (cpu.dl)++;
    // 0046d01b  889424c0020000         -mov byte ptr [esp + 0x2c0], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(704) /* 0x2c0 */) = cpu.dl;
    // 0046d022  80fa20                 +cmp dl, 0x20
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046d025  0f8602feffff           -jbe 0x46ce2d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046ce2d;
    }
    // 0046d02b  81c4c4020000           -add esp, 0x2c4
    (cpu.esp) += x86::reg32(x86::sreg32(708 /*0x2c4*/));
    // 0046d031  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d032  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d033  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d034  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d040  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d041  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d042  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d043  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046d046  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046d04a  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046d04e  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0046d052  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0046d056  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046d059  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0046d05b:
    // 0046d05b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d05d  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046d060  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046d063  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d065  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0046d068  0fb631                 -movzx esi, byte ptr [ecx]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 0046d06b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046d06f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046d071  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0046d074  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046d077  69d241040000           -imul edx, edx, 0x441
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1089 /*0x441*/)));
    // 0046d07d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d080  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0046d083  40                     -inc eax
    (cpu.eax)++;
    // 0046d084  6bc021                 -imul eax, eax, 0x21
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(33 /*0x21*/)));
    // 0046d087  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d08b  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 0046d08e  47                     -inc edi
    (cpu.edi)++;
    // 0046d08f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046d091  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046d095  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046d097  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046d09b  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046d09e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046d0a1  8b141a                 -mov edx, dword ptr [edx + ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 1);
    // 0046d0a4  011407                 -add dword ptr [edi + eax], edx
    (app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046d0a7  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0046d0a9  0fafea                 -imul ebp, edx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046d0ac  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046d0b0  012c07                 -add dword ptr [edi + eax], ebp
    (app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046d0b3  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d0b6  0fafea                 -imul ebp, edx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046d0b9  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d0bd  012c07                 -add dword ptr [edi + eax], ebp
    (app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046d0c0  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d0c4  0fafea                 -imul ebp, edx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046d0c7  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046d0cb  012c07                 -add dword ptr [edi + eax], ebp
    (app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046d0ce  8b7c2434               -mov edi, dword ptr [esp + 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046d0d2  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046d0d5  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046d0d7  a1a4895100             -mov eax, dword ptr [0x5189a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343652) /* 0x5189a4 */);
    // 0046d0dc  8d2c30                 -lea ebp, [eax + esi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046d0df  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d0e2  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046d0e5  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0046d0e9  8d2c30                 -lea ebp, [eax + esi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046d0ec  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046d0f0  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0046d0f2  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0046d0f6  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046d0f9  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046d0fd  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046d0ff  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d103  032cb0                 -add ebp, dword ptr [eax + esi*4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4)));
    // 0046d106  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0046d10a  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0046d10e  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046d112  db44241c               -fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 0046d116  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046d118  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046d11b  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 0046d11d  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046d120  d91f                   -fstp dword ptr [edi]
    app->getMemory<float>(cpu.edi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046d122  81fbfc030000           +cmp ebx, 0x3fc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1020 /*0x3fc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d128  0f852dffffff           -jne 0x46d05b
    if (!cpu.flags.zf)
    {
        goto L_0x0046d05b;
    }
    // 0046d12e  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046d131  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d132  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d133  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d134  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d140  a1a4895100             -mov eax, dword ptr [0x5189a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343652) /* 0x5189a4 */);
    // 0046d145  e982b90000             -jmp 0x478acc
    return sub_478acc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d151  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d152  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d153  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d154  8b35a4895100           -mov esi, dword ptr [0x5189a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5343652) /* 0x5189a4 */);
    // 0046d15a  ba00c54b00             -mov edx, 0x4bc500
    cpu.edx = 4965632 /*0x4bc500*/;
    // 0046d15f  b942000000             -mov ecx, 0x42
    cpu.ecx = 66 /*0x42*/;
    // 0046d164  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046d169  b81cc54b00             -mov eax, 0x4bc51c
    cpu.eax = 4965660 /*0x4bc51c*/;
    // 0046d16e  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0046d174  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0046d179  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0046d17f  e8e4b40000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046d184  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d186  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d188  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046d18a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046d18c:
    // 0046d18c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046d18e  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046d191  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046d194  40                     -inc eax
    (cpu.eax)++;
    // 0046d195  895c11fc               -mov dword ptr [ecx + edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edx * 1) = cpu.ebx;
    // 0046d199  3d00010000             +cmp eax, 0x100
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d19e  7cec                   -jl 0x46d18c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d18c;
    }
    // 0046d1a0  8935a4895100           -mov dword ptr [0x5189a4], esi
    app->getMemory<x86::reg32>(x86::reg32(5343652) /* 0x5189a4 */) = cpu.esi;
    // 0046d1a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d1a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d1a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d1a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d1aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d1b0  a1ac895100             -mov eax, dword ptr [0x5189ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343660) /* 0x5189ac */);
    // 0046d1b5  e912b90000             -jmp 0x478acc
    return sub_478acc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d1c0  a1ac895100             -mov eax, dword ptr [0x5189ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343660) /* 0x5189ac */);
    // 0046d1c5  e802b90000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046d1ca  e901000000             -jmp 0x46d1d0
    return sub_46d1d0(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46d1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d1d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d1d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d1d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d1d3  ba40c54b00             -mov edx, 0x4bc540
    cpu.edx = 4965696 /*0x4bc540*/;
    // 0046d1d8  b91b010000             -mov ecx, 0x11b
    cpu.ecx = 283 /*0x11b*/;
    // 0046d1dd  b860c54b00             -mov eax, 0x4bc560
    cpu.eax = 4965728 /*0x4bc560*/;
    // 0046d1e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d1e4  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0046d1ea  ba00340000             -mov edx, 0x3400
    cpu.edx = 13312 /*0x3400*/;
    // 0046d1ef  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0046d1f5  e86eb40000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046d1fa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d1fc  a3ac895100             -mov dword ptr [0x5189ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5343660) /* 0x5189ac */) = cpu.eax;
    // 0046d201  891db0895100           -mov dword ptr [0x5189b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5343664) /* 0x5189b0 */) = cpu.ebx;
    // 0046d207  891da8895100           -mov dword ptr [0x5189a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5343656) /* 0x5189a8 */) = cpu.ebx;
    // 0046d20d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0046d210  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d211  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d212  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d213  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d223  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d224  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d225  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d226  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046d229  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046d22b  a1b0895100             -mov eax, dword ptr [0x5189b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343664) /* 0x5189b0 */);
    // 0046d230  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d232  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046d236  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0046d23a  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0046d23e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046d240  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046d244  83c044                 -add eax, 0x44
    (cpu.eax) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0046d247  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0046d24e  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0046d252  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d254  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046d256  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046d259  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d25c  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046d25e  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046d262  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
L_0x0046d265:
    // 0046d265  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046d269  4b                     -dec ebx
    (cpu.ebx)--;
    // 0046d26a  81efa0010000           -sub edi, 0x1a0
    (cpu.edi) -= x86::reg32(x86::sreg32(416 /*0x1a0*/));
    // 0046d270  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0046d274  81ff60feffff           +cmp edi, 0xfffffe60
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966880 /*0xfffffe60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d27a  753a                   -jne 0x46d2b6
    if (!cpu.flags.zf)
    {
        goto L_0x0046d2b6;
    }
    // 0046d27c  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046d280  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046d284  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046d288  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046d28c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d28e  7406                   -je 0x46d296
    if (cpu.flags.zf)
    {
        goto L_0x0046d296;
    }
    // 0046d290  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
L_0x0046d296:
    // 0046d296  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046d298  6800000600             -push 0x60000
    app->getMemory<x86::reg32>(cpu.esp-4) = 393216 /*0x60000*/;
    cpu.esp -= 4;
    // 0046d29d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d2a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d2a2  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d2a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d2a7  e844f3feff             -call 0x45c5f0
    cpu.esp -= 4;
    sub_45c5f0(app, cpu);
    if (cpu.terminate) return;
    // 0046d2ac  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046d2af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d2b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d2b6:
    // 0046d2b6  8b35ac895100           -mov esi, dword ptr [0x5189ac]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5343660) /* 0x5189ac */);
    // 0046d2bc  bb00003200             -mov ebx, 0x320000
    cpu.ebx = 3276800 /*0x320000*/;
    // 0046d2c1  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046d2c3  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046d2c7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046d2c9  e812effeff             -call 0x45c1e0
    cpu.esp -= 4;
    sub_45c1e0(app, cpu);
    if (cpu.terminate) return;
    // 0046d2ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d2d0  7493                   -je 0x46d265
    if (cpu.flags.zf)
    {
        goto L_0x0046d265;
    }
    // 0046d2d2  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046d2d5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046d2d8  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d2db  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0046d2df  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046d2e1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d2e3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046d2e6  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046d2e9  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046d2ec  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d2ee  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046d2f2  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046d2f5  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046d2f8  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046d2fc  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d2fe  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046d302  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046d306  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046d308  e8730c0000             -call 0x46df80
    cpu.esp -= 4;
    sub_46df80(app, cpu);
    if (cpu.terminate) return;
    // 0046d30d  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046d311  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d315  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046d318  e823dbfeff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 0046d31d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d31f  0f8440ffffff           -je 0x46d265
    if (cpu.flags.zf)
    {
        goto L_0x0046d265;
    }
    // 0046d325  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d329  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046d32d  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046d331  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046d332  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046d335  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046d339  e8e2090000             -call 0x46dd20
    cpu.esp -= 4;
    sub_46dd20(app, cpu);
    if (cpu.terminate) return;
    // 0046d33e  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046d341  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0046d346  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d348  81c690010000           -add esi, 0x190
    (cpu.esi) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0046d34e  e82d3b0000             -call 0x470e80
    cpu.esp -= 4;
    sub_470e80(app, cpu);
    if (cpu.terminate) return;
L_0x0046d353:
    // 0046d353  49                     -dec ecx
    (cpu.ecx)--;
    // 0046d354  83f9ff                 +cmp ecx, -1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d357  0f8408ffffff           -je 0x46d265
    if (cpu.flags.zf)
    {
        goto L_0x0046d265;
    }
    // 0046d35d  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0046d362  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d366  e8d5dafeff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 0046d36b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d36d  7511                   -jne 0x46d380
    if (!cpu.flags.zf)
    {
        goto L_0x0046d380;
    }
    // 0046d36f  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d373  81c380000000           +add ebx, 0x80
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046d379  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046d37a  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0046d37e  ebd3                   -jmp 0x46d353
    goto L_0x0046d353;
L_0x0046d380:
    // 0046d380  837c243400             +cmp dword ptr [esp + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d385  0f8586000000           -jne 0x46d411
    if (!cpu.flags.zf)
    {
        goto L_0x0046d411;
    }
    // 0046d38b  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d38f  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
L_0x0046d393:
    // 0046d393  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d397  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0046d39b  c740040a000000         -mov dword ptr [eax + 4], 0xa
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10 /*0xa*/;
    // 0046d3a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d3a4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046d3a6  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d3aa  8b0485ec985100         -mov eax, dword ptr [eax*4 + 0x5198ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347564) /* 0x5198ec */ + cpu.eax * 4);
    // 0046d3b1  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046d3b4  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d3b8  66c7400a0100           -mov word ptr [eax + 0xa], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 1 /*0x1*/;
    // 0046d3be  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d3c2  66c740080300           -mov word ptr [eax + 8], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 0046d3c8  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d3cc  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d3d0  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046d3d3  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046d3d6  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d3da  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d3de  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046d3e1  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d3e5  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d3e9  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0046d3ec  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046d3ef  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d3f3  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d3f7  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046d3fa  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046d3fd  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046d401  81c380000000           +add ebx, 0x80
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046d407  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046d408  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0046d40c  e942ffffff             -jmp 0x46d353
    goto L_0x0046d353;
L_0x0046d411:
    // 0046d411  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046d415  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046d419  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0046d41b  e973ffffff             -jmp 0x46d393
    goto L_0x0046d393;
}

/* align: skip  */
void Application::sub_46d420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d420  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d421  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d426  0f84b7000000           -je 0x46d4e3
    if (cpu.flags.zf)
    {
        goto L_0x0046d4e3;
    }
    // 0046d42c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d42d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d42e  a1a8895100             -mov eax, dword ptr [0x5189a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343656) /* 0x5189a8 */);
    // 0046d433  8d2c8500000000         -lea ebp, [eax*4]
    cpu.ebp = x86::reg32(cpu.eax * 4);
    // 0046d43a  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d43c  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046d43f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046d441  a1ac895100             -mov eax, dword ptr [0x5189ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343660) /* 0x5189ac */);
    // 0046d446  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046d449  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046d44b  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046d44e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d450  83fe10                 +cmp esi, 0x10
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d453  0f858e000000           -jne 0x46d4e7
    if (!cpu.flags.zf)
    {
        goto L_0x0046d4e7;
    }
L_0x0046d459:
    // 0046d459  8b15b0895100           -mov edx, dword ptr [0x5189b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343664) /* 0x5189b0 */);
    // 0046d45f  83fa20                 +cmp edx, 0x20
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d462  0f8d07010000           -jge 0x46d56f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046d56f;
    }
    // 0046d468  8915a8895100           -mov dword ptr [0x5189a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5343656) /* 0x5189a8 */) = cpu.edx;
    // 0046d46e  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046d471  a3b0895100             -mov dword ptr [0x5189b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5343664) /* 0x5189b0 */) = cpu.eax;
L_0x0046d476:
    // 0046d476  a1a8895100             -mov eax, dword ptr [0x5189a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343656) /* 0x5189a8 */);
    // 0046d47b  8d2c8500000000         -lea ebp, [eax*4]
    cpu.ebp = x86::reg32(cpu.eax * 4);
    // 0046d482  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d484  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046d487  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046d489  a1ac895100             -mov eax, dword ptr [0x5189ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343660) /* 0x5189ac */);
    // 0046d48e  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046d491  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046d493  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x0046d49a:
    // 0046d49a  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0046d49c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046d49e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046d49f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046d4a0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
L_0x0046d4a1:
    // 0046d4a1  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046d4a4  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046d4ab  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d4ad  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046d4b0  8d5510                 -lea edx, [ebp + 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046d4b3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046d4b5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046d4b7  e8f4000000             -call 0x46d5b0
    cpu.esp -= 4;
    sub_46d5b0(app, cpu);
    if (cpu.terminate) return;
    // 0046d4bc  837c241002             +cmp dword ptr [esp + 0x10], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d4c1  0f85ce000000           -jne 0x46d595
    if (!cpu.flags.zf)
    {
        goto L_0x0046d595;
    }
    // 0046d4c7  e8a4f70000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0046d4cc  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0046d4ce  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0046d4d1  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046d4d4  80c202                 -add dl, 2
    (cpu.dl) += x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0046d4d7  88942890010000         -mov byte ptr [eax + ebp + 0x190], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(400) /* 0x190 */ + cpu.ebp * 1) = cpu.dl;
    // 0046d4de  ff450c                 -inc dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))++;
    // 0046d4e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046d4e3:
    // 0046d4e3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d4e4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0046d4e7:
    // 0046d4e7  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046d4e9  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046d4ec  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046d4ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d4f0  7e0c                   -jle 0x46d4fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d4fe;
    }
    // 0046d4f2  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d4f7  7c13                   -jl 0x46d50c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d50c;
    }
    // 0046d4f9  e95bffffff             -jmp 0x46d459
    goto L_0x0046d459;
L_0x0046d4fe:
    // 0046d4fe  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0046d500  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d505  7c05                   -jl 0x46d50c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d50c;
    }
    // 0046d507  e94dffffff             -jmp 0x46d459
    goto L_0x0046d459;
L_0x0046d50c:
    // 0046d50c  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046d50f  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d512  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046d514  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d516  7e0c                   -jle 0x46d524
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d524;
    }
    // 0046d518  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d51d  7c13                   -jl 0x46d532
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d532;
    }
    // 0046d51f  e935ffffff             -jmp 0x46d459
    goto L_0x0046d459;
L_0x0046d524:
    // 0046d524  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0046d526  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d52b  7c05                   -jl 0x46d532
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d532;
    }
    // 0046d52d  e927ffffff             -jmp 0x46d459
    goto L_0x0046d459;
L_0x0046d532:
    // 0046d532  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046d535  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d538  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046d53a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d53c  7e0c                   -jle 0x46d54a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046d54a;
    }
    // 0046d53e  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d543  7c13                   -jl 0x46d558
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d558;
    }
    // 0046d545  e90fffffff             -jmp 0x46d459
    goto L_0x0046d459;
L_0x0046d54a:
    // 0046d54a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0046d54c  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d551  7c05                   -jl 0x46d558
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046d558;
    }
    // 0046d553  e901ffffff             -jmp 0x46d459
    goto L_0x0046d459;
L_0x0046d558:
    // 0046d558  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046d55a  0f85f9feffff           -jne 0x46d459
    if (!cpu.flags.zf)
    {
        goto L_0x0046d459;
    }
    // 0046d560  837d0c00               +cmp dword ptr [ebp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d564  0f8430ffffff           -je 0x46d49a
    if (cpu.flags.zf)
    {
        goto L_0x0046d49a;
    }
    // 0046d56a  e932ffffff             -jmp 0x46d4a1
    goto L_0x0046d4a1;
L_0x0046d56f:
    // 0046d56f  8b35a8895100           -mov esi, dword ptr [0x5189a8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5343656) /* 0x5189a8 */);
    // 0046d575  83fe1f                 +cmp esi, 0x1f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d578  7d0e                   -jge 0x46d588
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046d588;
    }
    // 0046d57a  8d6e01                 -lea ebp, [esi + 1]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046d57d  892da8895100           -mov dword ptr [0x5189a8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5343656) /* 0x5189a8 */) = cpu.ebp;
    // 0046d583  e9eefeffff             -jmp 0x46d476
    goto L_0x0046d476;
L_0x0046d588:
    // 0046d588  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0046d58a  893da8895100           -mov dword ptr [0x5189a8], edi
    app->getMemory<x86::reg32>(x86::reg32(5343656) /* 0x5189a8 */) = cpu.edi;
    // 0046d590  e9e1feffff             -jmp 0x46d476
    goto L_0x0046d476;
L_0x0046d595:
    // 0046d595  e8d6f60000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0046d59a  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046d59d  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0046d59f  88842a90010000         -mov byte ptr [edx + ebp + 0x190], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(400) /* 0x190 */ + cpu.ebp * 1) = cpu.al;
    // 0046d5a6  ff450c                 -inc dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))++;
    // 0046d5a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5aa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5ab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d5ac  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_46d5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d5b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d5b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d5b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d5b3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d5b6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046d5b8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046d5ba  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046d5bc  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046d5be  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046d5c0  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d5c3  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d5c5  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046d5c8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d5ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d5cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d5ce  e8fdb90100             -call 0x488fd0
    cpu.esp -= 4;
    sub_488fd0(app, cpu);
    if (cpu.terminate) return;
    // 0046d5d3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046d5d7  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0046d5dd  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0046d5e0  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046d5e2  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046d5e4  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046d5e6  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d5e8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046d5ed  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d5ef  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0046d5f6  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d5f8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d5fa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d5fc  b8cc4c0000             -mov eax, 0x4ccc
    cpu.eax = 19660 /*0x4ccc*/;
    // 0046d601  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0046d603  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046d605  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046d608  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0046d60b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046d60d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046d60f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046d612  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046d616  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0046d619  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046d61b  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046d61d  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046d61f  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d621  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046d626  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d628  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 0046d62f  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d631  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d633  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d635  b8cc4c0000             -mov eax, 0x4ccc
    cpu.eax = 19660 /*0x4ccc*/;
    // 0046d63a  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d63d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046d63f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046d642  c1e810                 +shr eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0046d645  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046d647  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046d649  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d64b  2b17                   -sub edx, dword ptr [edi]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 0046d64d  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d650  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 0046d653  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046d656  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0046d659  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d65c  66895602               -mov word ptr [esi + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 0046d660  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046d662  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046d665  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046d668  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046d66a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d66c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d66f  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0046d673  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d676  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046d678  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d67a  2b17                   -sub edx, dword ptr [edi]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 0046d67c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d67f  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 0046d683  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046d686  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0046d689  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d68c  66895608               -mov word ptr [esi + 8], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.dx;
    // 0046d690  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046d693  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046d696  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d698  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d69a  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d69d  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0046d6a1  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d6a4  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046d6a7  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0046d6a9  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d6ab  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d6ad  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d6b0  6689560c               -mov word ptr [esi + 0xc], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 0046d6b4  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d6b7  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0046d6ba  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d6bd  6689560e               -mov word ptr [esi + 0xe], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 0046d6c1  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d6c4  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046d6c7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d6c9  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d6cb  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d6ce  66895610               -mov word ptr [esi + 0x10], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 0046d6d2  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046d6d5  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046d6d8  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0046d6da  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d6dc  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d6de  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d6e1  66895612               -mov word ptr [esi + 0x12], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(18) /* 0x12 */) = cpu.dx;
    // 0046d6e5  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046d6e8  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0046d6eb  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046d6ee  66895614               -mov word ptr [esi + 0x14], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.dx;
    // 0046d6f2  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046d6f5  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046d6f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d6fa  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046d6fc  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046d6ff  66894616               -mov word ptr [esi + 0x16], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(22) /* 0x16 */) = cpu.ax;
    // 0046d703  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046d706  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d707  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d708  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d709  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d710  a1146b4c00             -mov eax, dword ptr [0x4c6b14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5008148) /* 0x4c6b14 */);
    // 0046d715  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046d718  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046d71a  8b15b8895100           -mov edx, dword ptr [0x5189b8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5343672) /* 0x5189b8 */);
    // 0046d720  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046d722  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046d724  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d730  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d731  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d732  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d733  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d734  3b05ccfe4f00           +cmp eax, dword ptr [0x4ffecc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d73a  7416                   -je 0x46d752
    if (cpu.flags.zf)
    {
        goto L_0x0046d752;
    }
    // 0046d73c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d73d  bba3000000             -mov ebx, 0xa3
    cpu.ebx = 163 /*0xa3*/;
    // 0046d742  ba6cc54b00             -mov edx, 0x4bc56c
    cpu.edx = 4965740 /*0x4bc56c*/;
    // 0046d747  b8e0c54b00             -mov eax, 0x4bc5e0
    cpu.eax = 4965856 /*0x4bc5e0*/;
    // 0046d74c  e87bcf0100             -call 0x48a6cc
    cpu.esp -= 4;
    sub_48a6cc(app, cpu);
    if (cpu.terminate) return;
    // 0046d751  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046d752:
    // 0046d752  a1ccfe4f00             -mov eax, dword ptr [0x4ffecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 0046d757  e8d490fdff             -call 0x446830
    cpu.esp -= 4;
    sub_446830(app, cpu);
    if (cpu.terminate) return;
    // 0046d75c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d75e  8b35146b4c00           -mov esi, dword ptr [0x4c6b14]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5008148) /* 0x4c6b14 */);
    // 0046d764  890d407c4c00           -mov dword ptr [0x4c7c40], ecx
    app->getMemory<x86::reg32>(x86::reg32(5012544) /* 0x4c7c40 */) = cpu.ecx;
    // 0046d76a  890dccfe4f00           -mov dword ptr [0x4ffecc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */) = cpu.ecx;
    // 0046d770  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046d772  740d                   -je 0x46d781
    if (cpu.flags.zf)
    {
        goto L_0x0046d781;
    }
    // 0046d774  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046d776  e851b30000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046d77b  890d146b4c00           -mov dword ptr [0x4c6b14], ecx
    app->getMemory<x86::reg32>(x86::reg32(5008148) /* 0x4c6b14 */) = cpu.ecx;
L_0x0046d781:
    // 0046d781  8b2d186b4c00           -mov ebp, dword ptr [0x4c6b18]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5008152) /* 0x4c6b18 */);
    // 0046d787  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046d789  740e                   -je 0x46d799
    if (cpu.flags.zf)
    {
        goto L_0x0046d799;
    }
    // 0046d78b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046d78d  e83ab30000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046d792  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d794  a3186b4c00             -mov dword ptr [0x4c6b18], eax
    app->getMemory<x86::reg32>(x86::reg32(5008152) /* 0x4c6b18 */) = cpu.eax;
L_0x0046d799:
    // 0046d799  8b151c6b4c00           -mov edx, dword ptr [0x4c6b1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5008156) /* 0x4c6b1c */);
    // 0046d79f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046d7a1  7505                   -jne 0x46d7a8
    if (!cpu.flags.zf)
    {
        goto L_0x0046d7a8;
    }
    // 0046d7a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d7a8:
    // 0046d7a8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046d7aa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d7ac  e81bb30000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0046d7b1  890d1c6b4c00           -mov dword ptr [0x4c6b1c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5008156) /* 0x4c6b1c */) = cpu.ecx;
    // 0046d7b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d7bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46d7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d7c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046d7c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d7c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d7c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d7c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d7c5  b9ccfe4f00             -mov ecx, 0x4ffecc
    cpu.ecx = 5242572 /*0x4ffecc*/;
    // 0046d7ca  bb00080000             -mov ebx, 0x800
    cpu.ebx = 2048 /*0x800*/;
    // 0046d7cf  ba01080000             -mov edx, 0x801
    cpu.edx = 2049 /*0x801*/;
    // 0046d7d4  e8379afdff             -call 0x447210
    cpu.esp -= 4;
    sub_447210(app, cpu);
    if (cpu.terminate) return;
    // 0046d7d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d7db  7523                   -jne 0x46d800
    if (!cpu.flags.zf)
    {
        goto L_0x0046d800;
    }
    // 0046d7dd  ba6cc54b00             -mov edx, 0x4bc56c
    cpu.edx = 4965740 /*0x4bc56c*/;
    // 0046d7e2  b971000000             -mov ecx, 0x71
    cpu.ecx = 113 /*0x71*/;
    // 0046d7e7  6888c54b00             -push 0x4bc588
    app->getMemory<x86::reg32>(cpu.esp-4) = 4965768 /*0x4bc588*/;
    cpu.esp -= 4;
    // 0046d7ec  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 0046d7f2  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 0046d7f8  e8c3aa0000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0046d7fd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046d800:
    // 0046d800  a1ccfe4f00             -mov eax, dword ptr [0x4ffecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 0046d805  baacfe4f00             -mov edx, 0x4ffeac
    cpu.edx = 5242540 /*0x4ffeac*/;
    // 0046d80a  e8618ffdff             -call 0x446770
    cpu.esp -= 4;
    sub_446770(app, cpu);
    if (cpu.terminate) return;
    // 0046d80f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d811  a3b8895100             -mov dword ptr [0x5189b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5343672) /* 0x5189b8 */) = cpu.eax;
    // 0046d816  891db4895100           -mov dword ptr [0x5189b4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5343668) /* 0x5189b4 */) = cpu.ebx;
    // 0046d81c  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046d821  a1ccfe4f00             -mov eax, dword ptr [0x4ffecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 0046d826  e855010000             -call 0x46d980
    cpu.esp -= 4;
    sub_46d980(app, cpu);
    if (cpu.terminate) return;
    // 0046d82b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d82d  0f8426010000           -je 0x46d959
    if (cpu.flags.zf)
    {
        goto L_0x0046d959;
    }
    // 0046d833  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0046d838  bab4c54b00             -mov edx, 0x4bc5b4
    cpu.edx = 4965812 /*0x4bc5b4*/;
    // 0046d83d  b8acfe4f00             -mov eax, 0x4ffeac
    cpu.eax = 5242540 /*0x4ffeac*/;
    // 0046d842  e85cce0100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 0046d847  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d849  0f850a010000           -jne 0x46d959
    if (!cpu.flags.zf)
    {
        goto L_0x0046d959;
    }
    // 0046d84f  833db0fe4f0016         +cmp dword ptr [0x4ffeb0], 0x16
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5242544) /* 0x4ffeb0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22 /*0x16*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046d856  0f85fd000000           -jne 0x46d959
    if (!cpu.flags.zf)
    {
        goto L_0x0046d959;
    }
    // 0046d85c  bf6cc54b00             -mov edi, 0x4bc56c
    cpu.edi = 4965740 /*0x4bc56c*/;
    // 0046d861  bd82000000             -mov ebp, 0x82
    cpu.ebp = 130 /*0x82*/;
    // 0046d866  b8bcc54b00             -mov eax, 0x4bc5bc
    cpu.eax = 4965820 /*0x4bc5bc*/;
    // 0046d86b  8b15c4fe4f00           -mov edx, dword ptr [0x4ffec4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5242564) /* 0x4ffec4 */);
    // 0046d871  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d873  893d8c844c00           -mov dword ptr [0x4c848c], edi
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edi;
    // 0046d879  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046d87c  892d90844c00           -mov dword ptr [0x4c8490], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebp;
    // 0046d882  e8e1ad0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046d887  8b1dc4fe4f00           -mov ebx, dword ptr [0x4ffec4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5242564) /* 0x4ffec4 */);
    // 0046d88d  8b0dccfe4f00           -mov ecx, dword ptr [0x4ffecc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 0046d893  a3146b4c00             -mov dword ptr [0x4c6b14], eax
    app->getMemory<x86::reg32>(x86::reg32(5008148) /* 0x4c6b14 */) = cpu.eax;
    // 0046d898  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d89a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046d89d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d89f  e8dc000000             -call 0x46d980
    cpu.esp -= 4;
    sub_46d980(app, cpu);
    if (cpu.terminate) return;
    // 0046d8a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d8a6  0f84ad000000           -je 0x46d959
    if (cpu.flags.zf)
    {
        goto L_0x0046d959;
    }
    // 0046d8ac  c70590844c0087000000   -mov dword ptr [0x4c8490], 0x87
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = 135 /*0x87*/;
    // 0046d8b6  8b15c8fe4f00           -mov edx, dword ptr [0x4ffec8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5242568) /* 0x4ffec8 */);
    // 0046d8bc  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046d8c3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046d8c5  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0046d8cc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d8ce  b8c8c54b00             -mov eax, 0x4bc5c8
    cpu.eax = 4965832 /*0x4bc5c8*/;
    // 0046d8d3  893d8c844c00           -mov dword ptr [0x4c848c], edi
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edi;
    // 0046d8d9  e88aad0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046d8de  8b1dc8fe4f00           -mov ebx, dword ptr [0x4ffec8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5242568) /* 0x4ffec8 */);
    // 0046d8e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d8e6  a3186b4c00             -mov dword ptr [0x4c6b18], eax
    app->getMemory<x86::reg32>(x86::reg32(5008152) /* 0x4c6b18 */) = cpu.eax;
    // 0046d8eb  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0046d8f2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d8f4  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0046d8fb  a1ccfe4f00             -mov eax, dword ptr [0x4ffecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 0046d900  e87b000000             -call 0x46d980
    cpu.esp -= 4;
    sub_46d980(app, cpu);
    if (cpu.terminate) return;
    // 0046d905  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d907  7450                   -je 0x46d959
    if (cpu.flags.zf)
    {
        goto L_0x0046d959;
    }
    // 0046d909  bb8c000000             -mov ebx, 0x8c
    cpu.ebx = 140 /*0x8c*/;
    // 0046d90e  b8d4c54b00             -mov eax, 0x4bc5d4
    cpu.eax = 4965844 /*0x4bc5d4*/;
    // 0046d913  8b15c8fe4f00           -mov edx, dword ptr [0x4ffec8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5242568) /* 0x4ffec8 */);
    // 0046d919  891d90844c00           -mov dword ptr [0x4c8490], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebx;
    // 0046d91f  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046d921  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d923  893d8c844c00           -mov dword ptr [0x4c848c], edi
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edi;
    // 0046d929  e83aad0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 0046d92e  8b1dc8fe4f00           -mov ebx, dword ptr [0x4ffec8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5242568) /* 0x4ffec8 */);
    // 0046d934  8b0dccfe4f00           -mov ecx, dword ptr [0x4ffecc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 0046d93a  a31c6b4c00             -mov dword ptr [0x4c6b1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5008156) /* 0x4c6b1c */) = cpu.eax;
    // 0046d93f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046d941  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d943  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046d945  e836000000             -call 0x46d980
    cpu.esp -= 4;
    sub_46d980(app, cpu);
    if (cpu.terminate) return;
    // 0046d94a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d94c  740b                   -je 0x46d959
    if (cpu.flags.zf)
    {
        goto L_0x0046d959;
    }
    // 0046d94e  a1ccfe4f00             -mov eax, dword ptr [0x4ffecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 0046d953  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d954  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d955  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d956  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d957  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d958  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046d959:
    // 0046d959  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d95a  a1ccfe4f00             -mov eax, dword ptr [0x4ffecc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */);
    // 0046d95f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046d961  e8ca8efdff             -call 0x446830
    cpu.esp -= 4;
    sub_446830(app, cpu);
    if (cpu.terminate) return;
    // 0046d966  8935ccfe4f00           -mov dword ptr [0x4ffecc], esi
    app->getMemory<x86::reg32>(x86::reg32(5242572) /* 0x4ffecc */) = cpu.esi;
    // 0046d96c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046d96e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d96f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d970  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d971  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d972  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d973  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d974  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d980  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046d981  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d982  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046d984  a1b8895100             -mov eax, dword ptr [0x5189b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5343672) /* 0x5189b8 */);
    // 0046d989  0305b4895100           -add eax, dword ptr [0x5189b4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5343668) /* 0x5189b4 */)));
    // 0046d98f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046d991  e8ba2d0100             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0046d996  8b35b4895100           -mov esi, dword ptr [0x5189b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5343668) /* 0x5189b4 */);
    // 0046d99c  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046d99e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046d9a0  8935b4895100           -mov dword ptr [0x5189b4], esi
    app->getMemory<x86::reg32>(x86::reg32(5343668) /* 0x5189b4 */) = cpu.esi;
    // 0046d9a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046d9a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46d9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046d9b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046d9b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046d9b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046d9b3  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046d9b6  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046d9ba  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046d9be  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046d9c0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046d9c2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d9c6  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046d9c9  e872d4feff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 0046d9ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046d9d0  0f84af020000           -je 0x46dc85
    if (cpu.flags.zf)
    {
        goto L_0x0046dc85;
    }
    // 0046d9d6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046d9da  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046d9de  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046d9e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046d9e4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046d9e5  8b4914                 -mov ecx, dword ptr [ecx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0046d9e8  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046d9ea  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046d9ec  e82f030000             -call 0x46dd20
    cpu.esp -= 4;
    sub_46dd20(app, cpu);
    if (cpu.terminate) return;
    // 0046d9f1  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046d9f5  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046d9f8  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046d9ff  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046da01  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046da05  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046da08  e833d4feff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 0046da0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046da0f  0f8470020000           -je 0x46dc85
    if (cpu.flags.zf)
    {
        goto L_0x0046dc85;
    }
    // 0046da15  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046da19  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046da1b  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046da1e  e85d340000             -call 0x470e80
    cpu.esp -= 4;
    sub_470e80(app, cpu);
    if (cpu.terminate) return;
    // 0046da23  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046da27  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046da2a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046da2c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046da2e  0f8e20010000           -jle 0x46db54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046db54;
    }
    // 0046da34  bf24000000             -mov edi, 0x24
    cpu.edi = 36 /*0x24*/;
    // 0046da39  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0046da3d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046da3f  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
L_0x0046da43:
    // 0046da43  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046da47  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046da4b  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046da4f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046da51  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046da53  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0046da55  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046da59  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046da5d  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046da60  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da62  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da64  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046da68  668b4a02               -mov cx, word ptr [edx + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046da6c  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da6e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da70  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046da73  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da75  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046da77  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046da79  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0046da7c  0f841d010000           -je 0x46db9f
    if (cpu.flags.zf)
    {
        goto L_0x0046db9f;
    }
    // 0046da82  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046da85  0f8408010000           -je 0x46db93
    if (cpu.flags.zf)
    {
        goto L_0x0046db93;
    }
    // 0046da8b  c740040d000000         -mov dword ptr [eax + 4], 0xd
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
L_0x0046da92:
    // 0046da92  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 0046da95  0f8421010000           -je 0x46dbbc
    if (cpu.flags.zf)
    {
        goto L_0x0046dbbc;
    }
    // 0046da9b  66c7400a0200           -mov word ptr [eax + 0xa], 2
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 2 /*0x2*/;
L_0x0046daa1:
    // 0046daa1  6bed0c                 -imul ebp, ebp, 0xc
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0046daa4  668b3d286b4c00         -mov di, word ptr [0x4c6b28]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5008168) /* 0x4c6b28 */);
    // 0046daab  66897808               -mov word ptr [eax + 8], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.di;
    // 0046daaf  8b3d3c6c4c00           -mov edi, dword ptr [0x4c6c3c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5008444) /* 0x4c6c3c */);
    // 0046dab5  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046dab7  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046daba  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046dabd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046dabf  0f8402010000           -je 0x46dbc7
    if (cpu.flags.zf)
    {
        goto L_0x0046dbc7;
    }
L_0x0046dac5:
    // 0046dac5  668b3dc8895100         -mov di, word ptr [0x5189c8]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5343688) /* 0x5189c8 */);
    // 0046dacc  89681c                 -mov dword ptr [eax + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0046dacf  66897820               -mov word ptr [eax + 0x20], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.di;
    // 0046dad3  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0046dad6  0f8430010000           -je 0x46dc0c
    if (cpu.flags.zf)
    {
        goto L_0x0046dc0c;
    }
    // 0046dadc  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046dadf  0f84ed000000           -je 0x46dbd2
    if (cpu.flags.zf)
    {
        goto L_0x0046dbd2;
    }
    // 0046dae5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dae7  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046daea  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046daee  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046daf1  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046daf3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046daf5  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046daf8  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046dafb  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046daff  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046db02  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046db04  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046db06  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0046db09  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046db0b  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046db0f  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046db12  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046db14  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046db17  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
L_0x0046db19:
    // 0046db19  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046db1f  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046db23  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046db26  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046db28  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0046db2b  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046db2f  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046db33  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046db37  83c324                 -add ebx, 0x24
    (cpu.ebx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046db3a  46                     -inc esi
    (cpu.esi)++;
    // 0046db3b  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046db3e  83c524                 -add ebp, 0x24
    (cpu.ebp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046db41  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046db44  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0046db48  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046db4c  39d6                   +cmp esi, edx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046db4e  0f8ceffeffff           -jl 0x46da43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046da43;
    }
L_0x0046db54:
    // 0046db54  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046db58  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046db5c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046db60  8904d518ff4f00         -mov dword ptr [edx*8 + 0x4fff18], eax
    app->getMemory<x86::reg32>(x86::reg32(5242648) /* 0x4fff18 */ + cpu.edx * 8) = cpu.eax;
    // 0046db67  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046db6a  49                     -dec ecx
    (cpu.ecx)--;
    // 0046db6b  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0046db72  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046db74  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046db78  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046db7b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046db7d  8904d51cff4f00         -mov dword ptr [edx*8 + 0x4fff1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5242652) /* 0x4fff1c */ + cpu.edx * 8) = cpu.eax;
    // 0046db84  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0046db8a  83c41c                 +add esp, 0x1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046db8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046db90  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0046db93:
    // 0046db93  c7400409000000         -mov dword ptr [eax + 4], 9
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 9 /*0x9*/;
    // 0046db9a  e9f3feffff             -jmp 0x46da92
    goto L_0x0046da92;
L_0x0046db9f:
    // 0046db9f  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046dba2  740c                   -je 0x46dbb0
    if (cpu.flags.zf)
    {
        goto L_0x0046dbb0;
    }
    // 0046dba4  c740040c000000         -mov dword ptr [eax + 4], 0xc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 12 /*0xc*/;
    // 0046dbab  e9e2feffff             -jmp 0x46da92
    goto L_0x0046da92;
L_0x0046dbb0:
    // 0046dbb0  c7400408000000         -mov dword ptr [eax + 4], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 0046dbb7  e9d6feffff             -jmp 0x46da92
    goto L_0x0046da92;
L_0x0046dbbc:
    // 0046dbbc  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0046dbc2  e9dafeffff             -jmp 0x46daa1
    goto L_0x0046daa1;
L_0x0046dbc7:
    // 0046dbc7  8b2d40995100           -mov ebp, dword ptr [0x519940]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5347648) /* 0x519940 */);
    // 0046dbcd  e9f3feffff             -jmp 0x46dac5
    goto L_0x0046dac5;
L_0x0046dbd2:
    // 0046dbd2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dbd4  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046dbd6  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dbda  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dbdd  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dbdf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dbe1  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046dbe4  8a4a03                 -mov cl, byte ptr [edx + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0046dbe7  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dbeb  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dbee  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dbf0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dbf2  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0046dbf5  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046dbf8  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dbfc  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dbff  01cd                   +add ebp, ecx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046dc01  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046dc04  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046dc07  e90dffffff             -jmp 0x46db19
    goto L_0x0046db19;
L_0x0046dc0c:
    // 0046dc0c  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046dc0f  743a                   -je 0x46dc4b
    if (cpu.flags.zf)
    {
        goto L_0x0046dc4b;
    }
    // 0046dc11  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc13  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046dc15  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dc19  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dc1c  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc1e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc20  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046dc23  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046dc26  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dc2a  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dc2d  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc2f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc31  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0046dc34  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046dc37  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dc3b  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dc3e  01cd                   +add ebp, ecx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046dc40  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046dc43  8a5202                 -mov dl, byte ptr [edx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046dc46  e9cefeffff             -jmp 0x46db19
    goto L_0x0046db19;
L_0x0046dc4b:
    // 0046dc4b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc4d  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046dc4f  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dc53  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dc56  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc58  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc5a  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046dc5d  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046dc60  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dc64  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dc67  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc69  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dc6b  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0046dc6e  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046dc71  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dc75  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046dc78  01cd                   +add ebp, ecx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046dc7a  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046dc7d  8a5203                 -mov dl, byte ptr [edx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0046dc80  e994feffff             -jmp 0x46db19
    goto L_0x0046db19;
L_0x0046dc85:
    // 0046dc85  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046dc87  e864d1feff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 0046dc8c  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046dc90  8d3cf518ff4f00         -lea edi, [esi*8 + 0x4fff18]
    cpu.edi = x86::reg32(x86::reg32(5242648) /* 0x4fff18 */ + cpu.esi * 8);
    // 0046dc97  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046dc99  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046dc9a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046dc9b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046dc9e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dc9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dca0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dca1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dcb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dcb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046dcb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046dcb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046dcb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046dcb5  30e5                   -xor ch, ah
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046dcb7  66c1f804               -sar ax, 4
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (4 /*0x4*/ % 32));
    // 0046dcbb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046dcbd  30e6                   -xor dh, ah
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046dcbf  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0046dcc3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046dcc5  30e7                   -xor bh, ah
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046dcc7  80e207                 -and dl, 7
    cpu.dl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0046dcca  80e307                 -and bl, 7
    cpu.bl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0046dccd  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0046dcd1  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dcd3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046dcd5  30e7                   -xor bh, ah
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046dcd7  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0046dcdb  80e307                 -and bl, 7
    cpu.bl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0046dcde  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046dce0  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dce2  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0046dce4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046dce6  66c1ea02               -shr dx, 2
    cpu.dx >>= 2 /*0x2*/ % 32;
    // 0046dcea  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046dcec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046dcee  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0046dcf1  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0046dcf4  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0046dcf6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046dcf8  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0046dcfb  c1e20d                 -shl edx, 0xd
    cpu.edx <<= 13 /*0xd*/ % 32;
    // 0046dcfe  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dd00  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0046dd03  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dd05  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0046dd07  66890dc8895100         -mov word ptr [0x5189c8], cx
    app->getMemory<x86::reg16>(x86::reg32(5343688) /* 0x5189c8 */) = cpu.cx;
    // 0046dd0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dd20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dd21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046dd22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046dd23  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0046dd26  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0046dd2a  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0046dd2e  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0046dd32  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046dd34  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0046dd38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dd3a  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0046dd3e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046dd40  0f8e0e010000           -jle 0x46de54
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046de54;
    }
    // 0046dd46  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046dd49  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0046dd4d:
    // 0046dd4d  0fbf4500               -movsx eax, word ptr [ebp]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebp)));
    // 0046dd51  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0046dd54  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046dd58  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046dd5b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046dd5e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0046dd61  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046dd65  8b4502                 -mov eax, dword ptr [ebp + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0046dd68  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046dd6b  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046dd6f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0046dd72  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046dd76  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046dd7a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046dd7e  e805c50100             -call 0x48a288
    cpu.esp -= 4;
    sub_48a288(app, cpu);
    if (cpu.terminate) return;
    // 0046dd83  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046dd87  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046dd8b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046dd8d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046dd8f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046dd91  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0046dd93  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046dd96  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046dd99  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046dd9d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046dda1  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046dda4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046dda6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046dda8  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0046ddab  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046ddae  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046ddb2  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046ddb6  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046ddba  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046ddbd  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046ddc1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046ddc4  83c506                 -add ebp, 6
    (cpu.ebp) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0046ddc7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ddc9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046ddcb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046ddcd  8959e8                 -mov dword ptr [ecx - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 0046ddd0  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046ddd3  893594824c00           -mov dword ptr [0x4c8294], esi
    app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.esi;
    // 0046ddd9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046dddd  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046dddf  66c741ec0000           -mov word ptr [ecx - 0x14], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 0046dde5  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dde9  7e2a                   -jle 0x46de15
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046de15;
    }
    // 0046ddeb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046dded  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 0046ddf3  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046ddf6  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 0046ddfc  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046ddfe  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046de01  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 0046de07  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046de0a  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046de10  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046de13  eb14                   -jmp 0x46de29
    goto L_0x0046de29;
L_0x0046de15:
    // 0046de15  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 0046de1b  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0046de22  830d94824c0001         -or dword ptr [0x4c8294], 1
    app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0046de29:
    // 0046de29  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046de2d  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 0046de33  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046de37  668941ee               -mov word ptr [ecx - 0x12], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-18) /* -0x12 */) = cpu.ax;
    // 0046de3b  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046de3f  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046de42  40                     -inc eax
    (cpu.eax)++;
    // 0046de43  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0046de47  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0046de4b  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046de4d  0f8cfafeffff           -jl 0x46dd4d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046dd4d;
    }
    // 0046de53  90                     -nop 
    ;
L_0x0046de54:
    // 0046de54  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0046de57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de5a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46de60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046de60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046de61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046de62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046de63  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0046de66  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046de6a  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0046de6e  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0046de72  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046de74  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046de78  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046de7a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0046de7e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046de80  0f8ee6000000           -jle 0x46df6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046df6c;
    }
    // 0046de86  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046de89  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0046de8d:
    // 0046de8d  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046de91  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046de95  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046de97  e8ecc30100             -call 0x48a288
    cpu.esp -= 4;
    sub_48a288(app, cpu);
    if (cpu.terminate) return;
    // 0046de9c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046dea0  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046dea4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046dea6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046dea8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046deaa  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0046deac  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046deaf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046deb2  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046deb6  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046deba  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046debd  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046debf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046dec1  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0046dec4  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046dec7  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046decb  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046decf  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046ded3  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046ded6  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046deda  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046dedd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046dedf  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046dee1  893594824c00           -mov dword ptr [0x4c8294], esi
    app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.esi;
    // 0046dee7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046dee9  8959e8                 -mov dword ptr [ecx - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 0046deec  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046deef  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046def2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046def6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046def8  66c741ec0000           -mov word ptr [ecx - 0x14], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 0046defe  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046df02  7e2a                   -jle 0x46df2e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046df2e;
    }
    // 0046df04  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046df06  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 0046df0c  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046df0f  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 0046df15  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046df17  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046df1a  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 0046df20  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046df23  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046df29  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046df2c  eb14                   -jmp 0x46df42
    goto L_0x0046df42;
L_0x0046df2e:
    // 0046df2e  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 0046df34  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0046df3b  830d94824c0001         -or dword ptr [0x4c8294], 1
    app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0046df42:
    // 0046df42  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046df46  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 0046df4c  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046df50  668941ee               -mov word ptr [ecx - 0x12], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-18) /* -0x12 */) = cpu.ax;
    // 0046df54  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046df58  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046df5b  40                     -inc eax
    (cpu.eax)++;
    // 0046df5c  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0046df60  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0046df64  39d0                   +cmp eax, edx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046df66  0f8c21ffffff           -jl 0x46de8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046de8d;
    }
L_0x0046df6c:
    // 0046df6c  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0046df6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df72  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46df80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046df80  e903c30100             -jmp 0x48a288
    return sub_48a288(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46df90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046df90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046df91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046df92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046df93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046df94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046df95  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046df98  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046df9a  833801                 +cmp dword ptr [eax], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046df9d  7556                   -jne 0x46dff5
    if (!cpu.flags.zf)
    {
        goto L_0x0046dff5;
    }
    // 0046df9f  8b566c                 -mov edx, dword ptr [esi + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 0046dfa2  8b4068                 -mov eax, dword ptr [eax + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 0046dfa5  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046dfa7  742e                   -je 0x46dfd7
    if (cpu.flags.zf)
    {
        goto L_0x0046dfd7;
    }
    // 0046dfa9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dfab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dfad  b9d2000000             -mov ecx, 0xd2
    cpu.ecx = 210 /*0xd2*/;
    // 0046dfb2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dfb4  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 0046dfb9  8b4668                 -mov eax, dword ptr [esi + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 0046dfbc  6888000000             -push 0x88
    app->getMemory<x86::reg32>(cpu.esp-4) = 136 /*0x88*/;
    cpu.esp -= 4;
    // 0046dfc1  83ea46                 -sub edx, 0x46
    (cpu.edx) -= x86::reg32(x86::sreg32(70 /*0x46*/));
    // 0046dfc4  2d96000000             -sub eax, 0x96
    (cpu.eax) -= x86::reg32(x86::sreg32(150 /*0x96*/));
L_0x0046dfc9:
    // 0046dfc9  e8f2000000             -call 0x46e0c0
    cpu.esp -= 4;
    sub_46e0c0(app, cpu);
    if (cpu.terminate) return;
L_0x0046dfce:
    // 0046dfce  83c420                 +add esp, 0x20
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046dfd1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfd2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfd3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dfd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046dfd7:
    // 0046dfd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046dfd8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046dfd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046dfda  b9d2000000             -mov ecx, 0xd2
    cpu.ecx = 210 /*0xd2*/;
    // 0046dfdf  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 0046dfe4  6888000000             -push 0x88
    app->getMemory<x86::reg32>(cpu.esp-4) = 136 /*0x88*/;
    cpu.esp -= 4;
    // 0046dfe9  babaffffff             -mov edx, 0xffffffba
    cpu.edx = 4294967226 /*0xffffffba*/;
    // 0046dfee  b86affffff             -mov eax, 0xffffff6a
    cpu.eax = 4294967146 /*0xffffff6a*/;
    // 0046dff3  ebd4                   -jmp 0x46dfc9
    goto L_0x0046dfc9;
L_0x0046dff5:
    // 0046dff5  833de8d24d0001         +cmp dword ptr [0x4dd2e8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dffc  746f                   -je 0x46e06d
    if (cpu.flags.zf)
    {
        goto L_0x0046e06d;
    }
    // 0046dffe  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046e001  e87aa1fcff             -call 0x438180
    cpu.esp -= 4;
    sub_438180(app, cpu);
    if (cpu.terminate) return;
    // 0046e006  83f805                 +cmp eax, 5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e009  74c3                   -je 0x46dfce
    if (cpu.flags.zf)
    {
        goto L_0x0046dfce;
    }
    // 0046e00b  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046e00f  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046e013  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e017  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e018  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e01c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e01e  e86d0f0000             -call 0x46ef90
    cpu.esp -= 4;
    sub_46ef90(app, cpu);
    if (cpu.terminate) return;
    // 0046e023  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046e026  e855a1fcff             -call 0x438180
    cpu.esp -= 4;
    sub_438180(app, cpu);
    if (cpu.terminate) return;
    // 0046e02b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e02d  7514                   -jne 0x46e043
    if (!cpu.flags.zf)
    {
        goto L_0x0046e043;
    }
    // 0046e02f  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046e033  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e035  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 0046e03a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046e03d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046e03f  29442414               -sub dword ptr [esp + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046e043:
    // 0046e043  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e044  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046e046  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046e04a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e04b  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046e04f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e050  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046e054  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046e058  6a5a                   -push 0x5a
    app->getMemory<x86::reg32>(cpu.esp-4) = 90 /*0x5a*/;
    cpu.esp -= 4;
    // 0046e05a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e05c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046e05e  e85d000000             -call 0x46e0c0
    cpu.esp -= 4;
    sub_46e0c0(app, cpu);
    if (cpu.terminate) return;
    // 0046e063  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e064  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046e067  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e068  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e069  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e06a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e06b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e06c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e06d:
    // 0046e06d  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e071  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e075  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e079  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e07a  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e07e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046e081  e80a0f0000             -call 0x46ef90
    cpu.esp -= 4;
    sub_46ef90(app, cpu);
    if (cpu.terminate) return;
    // 0046e086  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046e088  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e08c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e090  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e094  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e098  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e09c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e09d  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0046e09f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e0a0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046e0a2  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e0a4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e0a6  6a5a                   -push 0x5a
    app->getMemory<x86::reg32>(cpu.esp-4) = 90 /*0x5a*/;
    cpu.esp -= 4;
    // 0046e0a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e0aa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e0ae  e80d000000             -call 0x46e0c0
    cpu.esp -= 4;
    sub_46e0c0(app, cpu);
    if (cpu.terminate) return;
    // 0046e0b3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046e0b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46e0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e0c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e0c1  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e0c5  e8a6f90100             -call 0x48da70
    cpu.esp -= 4;
    sub_48da70(app, cpu);
    if (cpu.terminate) return;
    // 0046e0ca  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e0cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e0ce  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046e0d1  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e0d3  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046e0d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046e0d7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e0da  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046e0dc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e0df  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0046e0e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e0e4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046e0e7  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0046e0ea  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046e0ec  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0046e0ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e0f1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e0f3  e8dcfa0100             -call 0x48dbd4
    cpu.esp -= 4;
    sub_48dbd4(app, cpu);
    if (cpu.terminate) return;
    // 0046e0f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0f9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46e100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e100  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e101  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e103  8915447c4c00           -mov dword ptr [0x4c7c44], edx
    app->getMemory<x86::reg32>(x86::reg32(5012548) /* 0x4c7c44 */) = cpu.edx;
    // 0046e109  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e10a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e110  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e111  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e113  8915447c4c00           -mov dword ptr [0x4c7c44], edx
    app->getMemory<x86::reg32>(x86::reg32(5012548) /* 0x4c7c44 */) = cpu.edx;
    // 0046e119  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e11a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 44332200000000000000000000000000 */
void Application::sub_46e130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e130  e8ff810000             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 0046e135  a134955100             -mov eax, dword ptr [0x519534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046e13a  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046e13d  e8ae2a0200             -call 0x490bf0
    cpu.esp -= 4;
    sub_490bf0(app, cpu);
    if (cpu.terminate) return;
    // 0046e142  e915820000             -jmp 0x47635c
    return sub_47635c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e150  a134955100             -mov eax, dword ptr [0x519534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046e155  e9ee820000             -jmp 0x476448
    return sub_476448(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e160  c7051495510001000000   -mov dword ptr [0x519514], 1
    app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */) = 1 /*0x1*/;
    // 0046e16a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e170  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e181  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e182  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e183  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e184  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e185  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e186  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046e189  bfa0000000             -mov edi, 0xa0
    cpu.edi = 160 /*0xa0*/;
    // 0046e18e  bda0000000             -mov ebp, 0xa0
    cpu.ebp = 160 /*0xa0*/;
    // 0046e193  8b0d84db4d00           -mov ecx, dword ptr [0x4ddb84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102468) /* 0x4ddb84 */);
    // 0046e199  8b1580db4d00           -mov edx, dword ptr [0x4ddb80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102464) /* 0x4ddb80 */);
    // 0046e19f  8b1da0db4d00           -mov ebx, dword ptr [0x4ddba0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102496) /* 0x4ddba0 */);
    // 0046e1a5  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e1a7  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e1a9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046e1ab  740e                   -je 0x46e1bb
    if (cpu.flags.zf)
    {
        goto L_0x0046e1bb;
    }
    // 0046e1ad  833d94db4d0000         +cmp dword ptr [0x4ddb94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102484) /* 0x4ddb94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e1b4  746a                   -je 0x46e220
    if (cpu.flags.zf)
    {
        goto L_0x0046e220;
    }
    // 0046e1b6  e855030000             -call 0x46e510
    cpu.esp -= 4;
    sub_46e510(app, cpu);
    if (cpu.terminate) return;
L_0x0046e1bb:
    // 0046e1bb  833d94db4d0000         +cmp dword ptr [0x4ddb94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102484) /* 0x4ddb94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e1c2  0f8481000000           -je 0x46e249
    if (cpu.flags.zf)
    {
        goto L_0x0046e249;
    }
    // 0046e1c8  833dd8d24d0002         +cmp dword ptr [0x4dd2d8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100248) /* 0x4dd2d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e1cf  7556                   -jne 0x46e227
    if (!cpu.flags.zf)
    {
        goto L_0x0046e227;
    }
    // 0046e1d1  ba20c64b00             -mov edx, 0x4bc620
    cpu.edx = 4965920 /*0x4bc620*/;
L_0x0046e1d6:
    // 0046e1d6  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e1db  e8b88b0000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e1e0  e86b960000             -call 0x477850
    cpu.esp -= 4;
    sub_477850(app, cpu);
    if (cpu.terminate) return;
    // 0046e1e5  833d88db4d0000         +cmp dword ptr [0x4ddb88], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102472) /* 0x4ddb88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e1ec  7440                   -je 0x46e22e
    if (cpu.flags.zf)
    {
        goto L_0x0046e22e;
    }
    // 0046e1ee  ba30c64b00             -mov edx, 0x4bc630
    cpu.edx = 4965936 /*0x4bc630*/;
    // 0046e1f3  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e1f8  e89b8b0000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e1fd  e82eca0000             -call 0x47ac30
    cpu.esp -= 4;
    sub_47ac30(app, cpu);
    if (cpu.terminate) return;
    // 0046e202  ba38c64b00             -mov edx, 0x4bc638
    cpu.edx = 4965944 /*0x4bc638*/;
L_0x0046e207:
    // 0046e207  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e20c  e8878b0000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e211  e81aca0000             -call 0x47ac30
    cpu.esp -= 4;
    sub_47ac30(app, cpu);
    if (cpu.terminate) return;
L_0x0046e216:
    // 0046e216  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046e219  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e21a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e21b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e21c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e21d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e21e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e21f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e220:
    // 0046e220  e82b020000             -call 0x46e450
    cpu.esp -= 4;
    sub_46e450(app, cpu);
    if (cpu.terminate) return;
    // 0046e225  eb94                   -jmp 0x46e1bb
    goto L_0x0046e1bb;
L_0x0046e227:
    // 0046e227  ba28c64b00             -mov edx, 0x4bc628
    cpu.edx = 4965928 /*0x4bc628*/;
    // 0046e22c  eba8                   -jmp 0x46e1d6
    goto L_0x0046e1d6;
L_0x0046e22e:
    // 0046e22e  ba40c64b00             -mov edx, 0x4bc640
    cpu.edx = 4965952 /*0x4bc640*/;
    // 0046e233  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e238  e85b8b0000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e23d  e8eec90000             -call 0x47ac30
    cpu.esp -= 4;
    sub_47ac30(app, cpu);
    if (cpu.terminate) return;
    // 0046e242  ba48c64b00             -mov edx, 0x4bc648
    cpu.edx = 4965960 /*0x4bc648*/;
    // 0046e247  ebbe                   -jmp 0x46e207
    goto L_0x0046e207;
L_0x0046e249:
    // 0046e249  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0046e24e  8b0de8d24d00           -mov ecx, dword ptr [0x4dd2e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0046e254  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0046e258  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e25b  7e08                   -jle 0x46e265
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e265;
    }
    // 0046e25d  c744241005000000       -mov dword ptr [esp + 0x10], 5
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 5 /*0x5*/;
L_0x0046e265:
    // 0046e265  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e269  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046e26b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e26d  0f8eb5000000           -jle 0x46e328
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e328;
    }
    // 0046e273  b80c020000             -mov eax, 0x20c
    cpu.eax = 524 /*0x20c*/;
    // 0046e278  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e27a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046e27e  b80c020000             -mov eax, 0x20c
    cpu.eax = 524 /*0x20c*/;
    // 0046e283  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046e285  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0046e289:
    // 0046e289  83fe01                 +cmp esi, 1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e28c  0f8511010000           -jne 0x46e3a3
    if (!cpu.flags.zf)
    {
        goto L_0x0046e3a3;
    }
    // 0046e292  833d9cdb4d0000         +cmp dword ptr [0x4ddb9c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102492) /* 0x4ddb9c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e299  0f8404010000           -je 0x46e3a3
    if (cpu.flags.zf)
    {
        goto L_0x0046e3a3;
    }
    // 0046e29f  ba50c64b00             -mov edx, 0x4bc650
    cpu.edx = 4965968 /*0x4bc650*/;
L_0x0046e2a4:
    // 0046e2a4  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e2a9  e8ea8a0000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e2ae  e87dc90000             -call 0x47ac30
    cpu.esp -= 4;
    sub_47ac30(app, cpu);
    if (cpu.terminate) return;
    // 0046e2b3  ba68c64b00             -mov edx, 0x4bc668
    cpu.edx = 4965992 /*0x4bc668*/;
    // 0046e2b8  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e2bd  bb94000000             -mov ebx, 0x94
    cpu.ebx = 148 /*0x94*/;
    // 0046e2c2  e8d18a0000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e2c7  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 0046e2cc  e86f950000             -call 0x477840
    cpu.esp -= 4;
    sub_477840(app, cpu);
    if (cpu.terminate) return;
    // 0046e2d1  ba68c64b00             -mov edx, 0x4bc668
    cpu.edx = 4965992 /*0x4bc668*/;
    // 0046e2d6  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e2db  bbc0000000             -mov ebx, 0xc0
    cpu.ebx = 192 /*0xc0*/;
    // 0046e2e0  e8b38a0000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e2e5  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 0046e2ea  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0046e2ef  e84c950000             -call 0x477840
    cpu.esp -= 4;
    sub_477840(app, cpu);
    if (cpu.terminate) return;
    // 0046e2f4  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0046e2f6  ba94000000             -mov edx, 0x94
    cpu.edx = 148 /*0x94*/;
    // 0046e2fb  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e2ff  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046e301  e81aef0000             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 0046e306  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0046e308  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0046e30d  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0046e312  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046e316  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0046e318  46                     -inc esi
    (cpu.esi)++;
    // 0046e319  e802ef0000             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 0046e31e  3b742410               +cmp esi, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e322  0f8c61ffffff           -jl 0x46e289
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046e289;
    }
L_0x0046e328:
    // 0046e328  8b35e8d24d00           -mov esi, dword ptr [0x4dd2e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0046e32e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046e330  0f84e0feffff           -je 0x46e216
    if (cpu.flags.zf)
    {
        goto L_0x0046e216;
    }
    // 0046e336  83fe01                 +cmp esi, 1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e339  0f84d7feffff           -je 0x46e216
    if (cpu.flags.zf)
    {
        goto L_0x0046e216;
    }
    // 0046e33f  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e346  0f8fcafeffff           -jg 0x46e216
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046e216;
    }
    // 0046e34c  83fe04                 +cmp esi, 4
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e34f  0f84a8000000           -je 0x46e3fd
    if (cpu.flags.zf)
    {
        goto L_0x0046e3fd;
    }
    // 0046e355  ba78c64b00             -mov edx, 0x4bc678
    cpu.edx = 4966008 /*0x4bc678*/;
    // 0046e35a  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e35f  e8348a0000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e364  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e366  e8c5c80000             -call 0x47ac30
    cpu.esp -= 4;
    sub_47ac30(app, cpu);
    if (cpu.terminate) return;
    // 0046e36b  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046e36e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046e371  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046e374  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046e377  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046e37a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e37c  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046e37f  8d58fe                 -lea ebx, [eax - 2]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-2) /* -0x2 */);
    // 0046e382  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0046e385  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e387  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046e38a  e8f1c70000             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0046e38f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046e394  e8c718fbff             -call 0x41fc60
    cpu.esp -= 4;
    sub_41fc60(app, cpu);
    if (cpu.terminate) return;
    // 0046e399  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046e39c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e39d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e39e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e39f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e3a3:
    // 0046e3a3  83fe02                 +cmp esi, 2
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e3a6  7509                   -jne 0x46e3b1
    if (!cpu.flags.zf)
    {
        goto L_0x0046e3b1;
    }
    // 0046e3a8  833d98db4d0000         +cmp dword ptr [0x4ddb98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102488) /* 0x4ddb98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e3af  7526                   -jne 0x46e3d7
    if (!cpu.flags.zf)
    {
        goto L_0x0046e3d7;
    }
L_0x0046e3b1:
    // 0046e3b1  8b1d88db4d00           -mov ebx, dword ptr [0x4ddb88]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102472) /* 0x4ddb88 */);
    // 0046e3b7  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e3b9  7526                   -jne 0x46e3e1
    if (!cpu.flags.zf)
    {
        goto L_0x0046e3e1;
    }
    // 0046e3bb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046e3bd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e3be  6860c64b00             -push 0x4bc660
    app->getMemory<x86::reg32>(cpu.esp-4) = 4965984 /*0x4bc660*/;
    cpu.esp -= 4;
    // 0046e3c3  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e3c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e3c8  e854c00000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0046e3cd  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046e3d0  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046e3d2  e9cdfeffff             -jmp 0x46e2a4
    goto L_0x0046e2a4;
L_0x0046e3d7:
    // 0046e3d7  ba58c64b00             -mov edx, 0x4bc658
    cpu.edx = 4965976 /*0x4bc658*/;
    // 0046e3dc  e9c3feffff             -jmp 0x46e2a4
    goto L_0x0046e2a4;
L_0x0046e3e1:
    // 0046e3e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046e3e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e3e4  6860c64b00             -push 0x4bc660
    app->getMemory<x86::reg32>(cpu.esp-4) = 4965984 /*0x4bc660*/;
    cpu.esp -= 4;
    // 0046e3e9  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046e3ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e3ee  e82ec00000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0046e3f3  83c410                 +add esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046e3f6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046e3f8  e9a7feffff             -jmp 0x46e2a4
    goto L_0x0046e2a4;
L_0x0046e3fd:
    // 0046e3fd  ba70c64b00             -mov edx, 0x4bc670
    cpu.edx = 4966000 /*0x4bc670*/;
    // 0046e402  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e407  e88c890000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e40c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046e40e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0046e410:
    // 0046e410  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046e413  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046e416  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e419  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0046e41c  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 0046e41f  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046e422  8d1c06                 -lea ebx, [esi + eax]
    cpu.ebx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0046e425  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e427  83c61a                 -add esi, 0x1a
    (cpu.esi) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 0046e42a  e851c70000             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0046e42f  81fed0000000           +cmp esi, 0xd0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e435  75d9                   -jne 0x46e410
    if (!cpu.flags.zf)
    {
        goto L_0x0046e410;
    }
    // 0046e437  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046e43c  e81f18fbff             -call 0x41fc60
    cpu.esp -= 4;
    sub_41fc60(app, cpu);
    if (cpu.terminate) return;
    // 0046e441  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046e444  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e445  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e446  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e447  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e448  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e449  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e44a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e452  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e453  ba08c64b00             -mov edx, 0x4bc608
    cpu.edx = 4965896 /*0x4bc608*/;
    // 0046e458  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e45d  e842890000             -call 0x476da4
    cpu.esp -= 4;
    sub_476da4(app, cpu);
    if (cpu.terminate) return;
    // 0046e462  ba10c64b00             -mov edx, 0x4bc610
    cpu.edx = 4965904 /*0x4bc610*/;
    // 0046e467  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e469  e8a2000000             -call 0x46e510
    cpu.esp -= 4;
    sub_46e510(app, cpu);
    if (cpu.terminate) return;
    // 0046e46e  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e473  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 0046e478  e81b890000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e47d  e8ce930000             -call 0x477850
    cpu.esp -= 4;
    sub_477850(app, cpu);
    if (cpu.terminate) return;
    // 0046e482  ba52010000             -mov edx, 0x152
    cpu.edx = 338 /*0x152*/;
    // 0046e487  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e489  e8f2c60000             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0046e48e  bbb6000000             -mov ebx, 0xb6
    cpu.ebx = 182 /*0xb6*/;
    // 0046e493  ba52010000             -mov edx, 0x152
    cpu.edx = 338 /*0x152*/;
    // 0046e498  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e49a  e8e1c60000             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0046e49f  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0046e4a1  b80c020000             -mov eax, 0x20c
    cpu.eax = 524 /*0x20c*/;
    // 0046e4a6  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0046e4ab  8b1d80db4d00           -mov ebx, dword ptr [0x4ddb80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102464) /* 0x4ddb80 */);
    // 0046e4b1  ba94000000             -mov edx, 0x94
    cpu.edx = 148 /*0x94*/;
    // 0046e4b6  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e4b8  e863ed0000             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 0046e4bd  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0046e4bf  b80c020000             -mov eax, 0x20c
    cpu.eax = 524 /*0x20c*/;
    // 0046e4c4  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0046e4c9  8b1d84db4d00           -mov ebx, dword ptr [0x4ddb84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102468) /* 0x4ddb84 */);
    // 0046e4cf  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0046e4d4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e4d6  e845ed0000             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 0046e4db  8b15e8d24d00           -mov edx, dword ptr [0x4dd2e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0046e4e1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046e4e3  7412                   -je 0x46e4f7
    if (cpu.flags.zf)
    {
        goto L_0x0046e4f7;
    }
    // 0046e4e5  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e4e8  740d                   -je 0x46e4f7
    if (cpu.flags.zf)
    {
        goto L_0x0046e4f7;
    }
    // 0046e4ea  833df4d24d0001         +cmp dword ptr [0x4dd2f4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100276) /* 0x4dd2f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e4f1  7f04                   -jg 0x46e4f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046e4f7;
    }
    // 0046e4f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e4f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e4f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e4f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e4f7:
    // 0046e4f7  ba18c64b00             -mov edx, 0x4bc618
    cpu.edx = 4965912 /*0x4bc618*/;
    // 0046e4fc  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e501  e892880000             -call 0x476d98
    cpu.esp -= 4;
    sub_476d98(app, cpu);
    if (cpu.terminate) return;
    // 0046e506  e825c70000             -call 0x47ac30
    cpu.esp -= 4;
    sub_47ac30(app, cpu);
    if (cpu.terminate) return;
    // 0046e50b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e50c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e50d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e50e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46e510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e512  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e513  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e514  ba00c64b00             -mov edx, 0x4bc600
    cpu.edx = 4965888 /*0x4bc600*/;
    // 0046e519  a18cdb4d00             -mov eax, dword ptr [0x4ddb8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102476) /* 0x4ddb8c */);
    // 0046e51e  bbf0000000             -mov ebx, 0xf0
    cpu.ebx = 240 /*0xf0*/;
    // 0046e523  e87c880000             -call 0x476da4
    cpu.esp -= 4;
    sub_476da4(app, cpu);
    if (cpu.terminate) return;
    // 0046e528  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046e52a  a134955100             -mov eax, dword ptr [0x519534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046e52f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e531  e8127f0000             -call 0x476448
    cpu.esp -= 4;
    sub_476448(app, cpu);
    if (cpu.terminate) return;
    // 0046e536  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046e538  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e53a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e53c  e86f060000             -call 0x46ebb0
    cpu.esp -= 4;
    sub_46ebb0(app, cpu);
    if (cpu.terminate) return;
    // 0046e541  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046e543  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e545  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e547  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e549  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e54b  e860060000             -call 0x46ebb0
    cpu.esp -= 4;
    sub_46ebb0(app, cpu);
    if (cpu.terminate) return;
    // 0046e550  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046e552  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046e557  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0046e55c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e55e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e560  e84b060000             -call 0x46ebb0
    cpu.esp -= 4;
    sub_46ebb0(app, cpu);
    if (cpu.terminate) return;
    // 0046e565  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046e567  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046e56c  bbf0000000             -mov ebx, 0xf0
    cpu.ebx = 240 /*0xf0*/;
    // 0046e571  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0046e576  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e578  e833060000             -call 0x46ebb0
    cpu.esp -= 4;
    sub_46ebb0(app, cpu);
    if (cpu.terminate) return;
    // 0046e57d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e57e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e57f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e580  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e581  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e590  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e5a0  e8cb250200             -call 0x490b70
    cpu.esp -= 4;
    sub_490b70(app, cpu);
    if (cpu.terminate) return;
    // 0046e5a5  e9660c0000             -jmp 0x46f210
    return sub_46f210(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e5b0  a134955100             -mov eax, dword ptr [0x519534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046e5b5  e8d6860000             -call 0x476c90
    cpu.esp -= 4;
    sub_476c90(app, cpu);
    if (cpu.terminate) return;
    // 0046e5ba  a138955100             -mov eax, dword ptr [0x519538]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346616) /* 0x519538 */);
    // 0046e5bf  e8cc860000             -call 0x476c90
    cpu.esp -= 4;
    sub_476c90(app, cpu);
    if (cpu.terminate) return;
    // 0046e5c4  a104955100             -mov eax, dword ptr [0x519504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346564) /* 0x519504 */);
    // 0046e5c9  e8c2860000             -call 0x476c90
    cpu.esp -= 4;
    sub_476c90(app, cpu);
    if (cpu.terminate) return;
    // 0046e5ce  833de8d24d0001         +cmp dword ptr [0x4dd2e8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e5d5  7401                   -je 0x46e5d8
    if (cpu.flags.zf)
    {
        goto L_0x0046e5d8;
    }
    // 0046e5d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e5d8:
    // 0046e5d8  a108955100             -mov eax, dword ptr [0x519508]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346568) /* 0x519508 */);
    // 0046e5dd  e9ae860000             -jmp 0x476c90
    return sub_476c90(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e5f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e600  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e612  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e613  81ec00030000           -sub esp, 0x300
    (cpu.esp) -= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0046e619  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0046e61e  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0046e623  8915f0814c00           -mov dword ptr [0x4c81f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */) = cpu.edx;
    // 0046e629  890dec814c00           -mov dword ptr [0x4c81ec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */) = cpu.ecx;
    // 0046e62f  e8007d0000             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 0046e634  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0046e639  e81e7f0000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 0046e63e  e8ed7f0000             -call 0x476630
    cpu.esp -= 4;
    sub_476630(app, cpu);
    if (cpu.terminate) return;
    // 0046e643  e8147d0000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0046e648  e8fb7c0000             -call 0x476348
    cpu.esp -= 4;
    sub_476348(app, cpu);
    if (cpu.terminate) return;
    // 0046e64d  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0046e652  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046e654  e8037f0000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 0046e659  e8d27f0000             -call 0x476630
    cpu.esp -= 4;
    sub_476630(app, cpu);
    if (cpu.terminate) return;
    // 0046e65e  e8f97c0000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0046e663  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0046e668  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 0046e66d  e8ae23fbff             -call 0x420a20
    cpu.esp -= 4;
    sub_420a20(app, cpu);
    if (cpu.terminate) return;
    // 0046e672  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 0046e677  e898e40000             -call 0x47cb14
    cpu.esp -= 4;
    sub_47cb14(app, cpu);
    if (cpu.terminate) return;
    // 0046e67c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e67e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e680  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e682  e85924fbff             -call 0x420ae0
    cpu.esp -= 4;
    sub_420ae0(app, cpu);
    if (cpu.terminate) return;
    // 0046e687  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 0046e68c  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 0046e691  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046e693  e87ce40000             -call 0x47cb14
    cpu.esp -= 4;
    sub_47cb14(app, cpu);
    if (cpu.terminate) return;
    // 0046e698  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0046e69d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046e69f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046e6a1  e8360a0100             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0046e6a6  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0046e6ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e6ad  e8e6f10100             -call 0x48d898
    cpu.esp -= 4;
    sub_48d898(app, cpu);
    if (cpu.terminate) return;
    // 0046e6b2  e87d7c0000             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 0046e6b7  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0046e6bc  e89b7e0000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 0046e6c1  e86a7f0000             -call 0x476630
    cpu.esp -= 4;
    sub_476630(app, cpu);
    if (cpu.terminate) return;
    // 0046e6c6  e8917c0000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0046e6cb  e8787c0000             -call 0x476348
    cpu.esp -= 4;
    sub_476348(app, cpu);
    if (cpu.terminate) return;
    // 0046e6d0  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0046e6d5  e8827e0000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 0046e6da  e8517f0000             -call 0x476630
    cpu.esp -= 4;
    sub_476630(app, cpu);
    if (cpu.terminate) return;
    // 0046e6df  e8787c0000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0046e6e4  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 0046e6ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46e6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e6f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e6f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e6f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e6f3  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046e6f8  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0046e6fd  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 0046e702  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 0046e707  e844240200             -call 0x490b50
    cpu.esp -= 4;
    sub_490b50(app, cpu);
    if (cpu.terminate) return;
    // 0046e70c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046e711  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0046e716  ba46000000             -mov edx, 0x46
    cpu.edx = 70 /*0x46*/;
    // 0046e71b  a334955100             -mov dword ptr [0x519534], eax
    app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */) = cpu.eax;
    // 0046e720  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 0046e725  e826240200             -call 0x490b50
    cpu.esp -= 4;
    sub_490b50(app, cpu);
    if (cpu.terminate) return;
    // 0046e72a  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046e72f  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0046e734  ba87000000             -mov edx, 0x87
    cpu.edx = 135 /*0x87*/;
    // 0046e739  a338955100             -mov dword ptr [0x519538], eax
    app->getMemory<x86::reg32>(x86::reg32(5346616) /* 0x519538 */) = cpu.eax;
    // 0046e73e  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 0046e743  e808240200             -call 0x490b50
    cpu.esp -= 4;
    sub_490b50(app, cpu);
    if (cpu.terminate) return;
    // 0046e748  8b15e8d24d00           -mov edx, dword ptr [0x4dd2e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0046e74e  a304955100             -mov dword ptr [0x519504], eax
    app->getMemory<x86::reg32>(x86::reg32(5346564) /* 0x519504 */) = cpu.eax;
    // 0046e753  83fa01                 +cmp edx, 1
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e756  7432                   -je 0x46e78a
    if (cpu.flags.zf)
    {
        goto L_0x0046e78a;
    }
    // 0046e758  a120d34d00             -mov eax, dword ptr [0x4dd320]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100320) /* 0x4dd320 */);
    // 0046e75d  a310955100             -mov dword ptr [0x519510], eax
    app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */) = cpu.eax;
L_0x0046e762:
    // 0046e762  a12cd34d00             -mov eax, dword ptr [0x4dd32c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100332) /* 0x4dd32c */);
    // 0046e767  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046e76c  e8bf4dfcff             -call 0x433530
    cpu.esp -= 4;
    sub_433530(app, cpu);
    if (cpu.terminate) return;
    // 0046e771  a124d34d00             -mov eax, dword ptr [0x4dd324]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100324) /* 0x4dd324 */);
    // 0046e776  891d14955100           -mov dword ptr [0x519514], ebx
    app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */) = cpu.ebx;
    // 0046e77c  a30c955100             -mov dword ptr [0x51950c], eax
    app->getMemory<x86::reg32>(x86::reg32(5346572) /* 0x51950c */) = cpu.eax;
    // 0046e781  e80a070000             -call 0x46ee90
    cpu.esp -= 4;
    sub_46ee90(app, cpu);
    if (cpu.terminate) return;
    // 0046e786  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e787  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e788  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e789  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e78a:
    // 0046e78a  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046e78f  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0046e794  ba87000000             -mov edx, 0x87
    cpu.edx = 135 /*0x87*/;
    // 0046e799  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 0046e79e  e8ad230200             -call 0x490b50
    cpu.esp -= 4;
    sub_490b50(app, cpu);
    if (cpu.terminate) return;
    // 0046e7a3  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046e7a5  a308955100             -mov dword ptr [0x519508], eax
    app->getMemory<x86::reg32>(x86::reg32(5346568) /* 0x519508 */) = cpu.eax;
    // 0046e7aa  890d10955100           -mov dword ptr [0x519510], ecx
    app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */) = cpu.ecx;
    // 0046e7b0  ebb0                   -jmp 0x46e762
    goto L_0x0046e762;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e7c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e7c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e7c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e7c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e7c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e7c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e7c5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046e7c8  8b1520955100           -mov edx, dword ptr [0x519520]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5346592) /* 0x519520 */);
    // 0046e7ce  42                     -inc edx
    (cpu.edx)++;
    // 0046e7cf  a134955100             -mov eax, dword ptr [0x519534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046e7d4  891520955100           -mov dword ptr [0x519520], edx
    app->getMemory<x86::reg32>(x86::reg32(5346592) /* 0x519520 */) = cpu.edx;
    // 0046e7da  e8697c0000             -call 0x476448
    cpu.esp -= 4;
    sub_476448(app, cpu);
    if (cpu.terminate) return;
    // 0046e7df  8b0d84d54f00           -mov ecx, dword ptr [0x4fd584]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5232004) /* 0x4fd584 */);
    // 0046e7e5  81f920020000           +cmp ecx, 0x220
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(544 /*0x220*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e7eb  0f8dcc000000           -jge 0x46e8bd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046e8bd;
    }
    // 0046e7f1  81f920010000           +cmp ecx, 0x120
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(288 /*0x120*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e7f7  0f8ec0000000           -jle 0x46e8bd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e8bd;
    }
    // 0046e7fd  a120e14600             -mov eax, dword ptr [0x46e120]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4645152) /* 0x46e120 */);
    // 0046e802  8b3570d14d00           -mov esi, dword ptr [0x4dd170]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099888) /* 0x4dd170 */);
    // 0046e808  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e80b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046e80d  7433                   -je 0x46e842
    if (cpu.flags.zf)
    {
        goto L_0x0046e842;
    }
    // 0046e80f  833d7cd14d0005         +cmp dword ptr [0x4dd17c], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099900) /* 0x4dd17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e816  752a                   -jne 0x46e842
    if (!cpu.flags.zf)
    {
        goto L_0x0046e842;
    }
    // 0046e818  8a542401               -mov dl, byte ptr [esp + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0046e81c  8a5c2403               -mov bl, byte ptr [esp + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 0046e820  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 0046e823  80c228                 -add dl, 0x28
    (cpu.dl) += x86::reg8(x86::sreg8(40 /*0x28*/));
    // 0046e826  80c328                 -add bl, 0x28
    (cpu.bl) += x86::reg8(x86::sreg8(40 /*0x28*/));
    // 0046e829  80c428                 -add ah, 0x28
    (cpu.ah) += x86::reg8(x86::sreg8(40 /*0x28*/));
    // 0046e82c  88542401               -mov byte ptr [esp + 1], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0046e830  8a742402               -mov dh, byte ptr [esp + 2]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 0046e834  885c2403               -mov byte ptr [esp + 3], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 0046e838  80c628                 -add dh, 0x28
    (cpu.dh) += x86::reg8(x86::sreg8(40 /*0x28*/));
    // 0046e83b  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0046e83e  88742402               -mov byte ptr [esp + 2], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dh;
L_0x0046e842:
    // 0046e842  803d802d4c0000         +cmp byte ptr [0x4c2d80], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046e849  0f84b0010000           -je 0x46e9ff
    if (cpu.flags.zf)
    {
        goto L_0x0046e9ff;
    }
L_0x0046e84f:
    // 0046e84f  8b0de8d24d00           -mov ecx, dword ptr [0x4dd2e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0046e855  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e858  0f85c7010000           -jne 0x46ea25
    if (!cpu.flags.zf)
    {
        goto L_0x0046ea25;
    }
    // 0046e85e  a110955100             -mov eax, dword ptr [0x519510]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046e863  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e865  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e867  8a154d955100           -mov dl, byte ptr [0x51954d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5346637) /* 0x51954d */);
    // 0046e86d  8a1c04                 -mov bl, byte ptr [esp + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 0046e870  8b34c53c814c00         -mov esi, dword ptr [eax*8 + 0x4c813c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5013820) /* 0x4c813c */ + cpu.eax * 8);
    // 0046e877  a04c955100             -mov al, byte ptr [0x51954c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5346636) /* 0x51954c */);
    // 0046e87c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e87e  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 0046e880  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046e882  83ee5f                 -sub esi, 0x5f
    (cpu.esi) -= x86::reg32(x86::sreg32(95 /*0x5f*/));
    // 0046e885  d3fb                   -sar ebx, cl
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (cpu.cl % 32));
    // 0046e887  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046e889  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e88a  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 0046e88c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e88e  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0046e893  8a0d802d4c00           -mov cl, byte ptr [0x4c2d80]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */);
    // 0046e899  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e89b  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046e89d  ba59000000             -mov edx, 0x59
    cpu.edx = 89 /*0x59*/;
    // 0046e8a2  8b1c9d2c995100         -mov ebx, dword ptr [ebx*4 + 0x51992c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5347628) /* 0x51992c */ + cpu.ebx * 4);
    // 0046e8a9  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 0046e8ab  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046e8ad  b8bf000000             -mov eax, 0xbf
    cpu.eax = 191 /*0xbf*/;
    // 0046e8b2  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046e8b4  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0046e8b6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046e8b8  e883ee0000             -call 0x47d740
    cpu.esp -= 4;
    sub_47d740(app, cpu);
    if (cpu.terminate) return;
L_0x0046e8bd:
    // 0046e8bd  833d1495510000         +cmp dword ptr [0x519514], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e8c4  0f84c3010000           -je 0x46ea8d
    if (cpu.flags.zf)
    {
        goto L_0x0046ea8d;
    }
    // 0046e8ca  e8797a0000             -call 0x476348
    cpu.esp -= 4;
    sub_476348(app, cpu);
    if (cpu.terminate) return;
L_0x0046e8cf:
    // 0046e8cf  8b1510955100           -mov edx, dword ptr [0x519510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046e8d5  a10c955100             -mov eax, dword ptr [0x51950c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346572) /* 0x51950c */);
    // 0046e8da  e8d198ffff             -call 0x4681b0
    cpu.esp -= 4;
    sub_4681b0(app, cpu);
    if (cpu.terminate) return;
    // 0046e8df  8b0d34955100           -mov ecx, dword ptr [0x519534]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046e8e5  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046e8e8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e8ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e8ec  e877d40100             -call 0x48bd68
    cpu.esp -= 4;
    sub_48bd68(app, cpu);
    if (cpu.terminate) return;
    // 0046e8f1  833d1495510000         +cmp dword ptr [0x519514], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e8f8  750a                   -jne 0x46e904
    if (!cpu.flags.zf)
    {
        goto L_0x0046e904;
    }
    // 0046e8fa  e85d7a0000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0046e8ff  e8307a0000             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
L_0x0046e904:
    // 0046e904  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 0046e909  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e90b  e8a098ffff             -call 0x4681b0
    cpu.esp -= 4;
    sub_4681b0(app, cpu);
    if (cpu.terminate) return;
    // 0046e910  8b0d34955100           -mov ecx, dword ptr [0x519534]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046e916  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046e919  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e91b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e91d  e89e50ffff             -call 0x4639c0
    cpu.esp -= 4;
    sub_4639c0(app, cpu);
    if (cpu.terminate) return;
    // 0046e922  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0046e927  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e929  e88298ffff             -call 0x4681b0
    cpu.esp -= 4;
    sub_4681b0(app, cpu);
    if (cpu.terminate) return;
    // 0046e92e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e930  7412                   -je 0x46e944
    if (cpu.flags.zf)
    {
        goto L_0x0046e944;
    }
    // 0046e932  8b0d38955100           -mov ecx, dword ptr [0x519538]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5346616) /* 0x519538 */);
    // 0046e938  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046e93b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e93d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e93f  e824d40100             -call 0x48bd68
    cpu.esp -= 4;
    sub_48bd68(app, cpu);
    if (cpu.terminate) return;
L_0x0046e944:
    // 0046e944  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0046e949  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e94b  e86098ffff             -call 0x4681b0
    cpu.esp -= 4;
    sub_4681b0(app, cpu);
    if (cpu.terminate) return;
    // 0046e950  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e952  7412                   -je 0x46e966
    if (cpu.flags.zf)
    {
        goto L_0x0046e966;
    }
    // 0046e954  8b0d38955100           -mov ecx, dword ptr [0x519538]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5346616) /* 0x519538 */);
    // 0046e95a  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0046e95d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e95f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e961  e802d40100             -call 0x48bd68
    cpu.esp -= 4;
    sub_48bd68(app, cpu);
    if (cpu.terminate) return;
L_0x0046e966:
    // 0046e966  833de8d24d0001         +cmp dword ptr [0x4dd2e8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e96d  0f8524010000           -jne 0x46ea97
    if (!cpu.flags.zf)
    {
        goto L_0x0046ea97;
    }
    // 0046e973  833d00d14d0000         +cmp dword ptr [0x4dd100], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099776) /* 0x4dd100 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e97a  7414                   -je 0x46e990
    if (cpu.flags.zf)
    {
        goto L_0x0046e990;
    }
    // 0046e97c  a104955100             -mov eax, dword ptr [0x519504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346564) /* 0x519504 */);
    // 0046e981  bb45000000             -mov ebx, 0x45
    cpu.ebx = 69 /*0x45*/;
    // 0046e986  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e988  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046e98b  e8b08e0000             -call 0x477840
    cpu.esp -= 4;
    sub_477840(app, cpu);
    if (cpu.terminate) return;
L_0x0046e990:
    // 0046e990  833d04d14d0000         +cmp dword ptr [0x4dd104], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099780) /* 0x4dd104 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e997  7414                   -je 0x46e9ad
    if (cpu.flags.zf)
    {
        goto L_0x0046e9ad;
    }
    // 0046e999  a108955100             -mov eax, dword ptr [0x519508]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346568) /* 0x519508 */);
    // 0046e99e  bb35010000             -mov ebx, 0x135
    cpu.ebx = 309 /*0x135*/;
    // 0046e9a3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046e9a5:
    // 0046e9a5  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046e9a8  e8938e0000             -call 0x477840
    cpu.esp -= 4;
    sub_477840(app, cpu);
    if (cpu.terminate) return;
L_0x0046e9ad:
    // 0046e9ad  833dd4d34f0002         +cmp dword ptr [0x4fd3d4], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5231572) /* 0x4fd3d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e9b4  7526                   -jne 0x46e9dc
    if (!cpu.flags.zf)
    {
        goto L_0x0046e9dc;
    }
    // 0046e9b6  b9dd010000             -mov ecx, 0x1dd
    cpu.ecx = 477 /*0x1dd*/;
    // 0046e9bb  bb8b010000             -mov ebx, 0x18b
    cpu.ebx = 395 /*0x18b*/;
    // 0046e9c0  bab5010000             -mov edx, 0x1b5
    cpu.edx = 437 /*0x1b5*/;
    // 0046e9c5  b8f5000000             -mov eax, 0xf5
    cpu.eax = 245 /*0xf5*/;
    // 0046e9ca  e821830000             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 0046e9cf  a134955100             -mov eax, dword ptr [0x519534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046e9d4  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046e9d7  e8748e0000             -call 0x477850
    cpu.esp -= 4;
    sub_477850(app, cpu);
    if (cpu.terminate) return;
L_0x0046e9dc:
    // 0046e9dc  833d1495510000         +cmp dword ptr [0x519514], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e9e3  0f84cf000000           -je 0x46eab8
    if (cpu.flags.zf)
    {
        goto L_0x0046eab8;
    }
    // 0046e9e9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046e9eb  e870940100             -call 0x487e60
    cpu.esp -= 4;
    sub_487e60(app, cpu);
    if (cpu.terminate) return;
    // 0046e9f0  893514955100           -mov dword ptr [0x519514], esi
    app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */) = cpu.esi;
    // 0046e9f6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046e9f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e9ff:
    // 0046e9ff  8b2d14d34d00           -mov ebp, dword ptr [0x4dd314]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5100308) /* 0x4dd314 */);
    // 0046ea05  83fd01                 +cmp ebp, 1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ea08  0f84affeffff           -je 0x46e8bd
    if (cpu.flags.zf)
    {
        goto L_0x0046e8bd;
    }
    // 0046ea0e  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ea11  0f84a6feffff           -je 0x46e8bd
    if (cpu.flags.zf)
    {
        goto L_0x0046e8bd;
    }
    // 0046ea17  83fd04                 +cmp ebp, 4
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ea1a  0f849dfeffff           -je 0x46e8bd
    if (cpu.flags.zf)
    {
        goto L_0x0046e8bd;
    }
    // 0046ea20  e92afeffff             -jmp 0x46e84f
    goto L_0x0046e84f;
L_0x0046ea25:
    // 0046ea25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ea26  8b1510955100           -mov edx, dword ptr [0x519510]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046ea2c  a04d955100             -mov al, byte ptr [0x51954d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5346637) /* 0x51954d */);
    // 0046ea31  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ea33  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ea35  8a5c1404               -mov bl, byte ptr [esp + edx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 0046ea39  8b3cd53c814c00         -mov edi, dword ptr [edx*8 + 0x4c813c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5013820) /* 0x4c813c */ + cpu.edx * 8);
    // 0046ea40  8a154c955100           -mov dl, byte ptr [0x51954c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5346636) /* 0x51954c */);
    // 0046ea46  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 0046ea48  d3fb                   -sar ebx, cl
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (cpu.cl % 32));
    // 0046ea4a  83ef5f                 -sub edi, 0x5f
    (cpu.edi) -= x86::reg32(x86::sreg32(95 /*0x5f*/));
    // 0046ea4d  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046ea4f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ea50  d3ff                   -sar edi, cl
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (cpu.cl % 32));
    // 0046ea52  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ea54  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0046ea59  8a0d802d4c00           -mov cl, byte ptr [0x4c2d80]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(4992384) /* 0x4c2d80 */);
    // 0046ea5f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ea61  bebf000000             -mov esi, 0xbf
    cpu.esi = 191 /*0xbf*/;
    // 0046ea66  8b1c9d2c995100         -mov ebx, dword ptr [ebx*4 + 0x51992c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5347628) /* 0x51992c */ + cpu.ebx * 4);
    // 0046ea6d  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ea6f  b859000000             -mov eax, 0x59
    cpu.eax = 89 /*0x59*/;
    // 0046ea74  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046ea76  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0046ea78  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046ea7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046ea7c  d3fe                   +sar esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0046ea7e  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0046ea80  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046ea82  e8b9ec0000             -call 0x47d740
    cpu.esp -= 4;
    sub_47d740(app, cpu);
    if (cpu.terminate) return;
    // 0046ea87  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ea88  e930feffff             -jmp 0x46e8bd
    goto L_0x0046e8bd;
L_0x0046ea8d:
    // 0046ea8d  e8a2780000             -call 0x476334
    cpu.esp -= 4;
    sub_476334(app, cpu);
    if (cpu.terminate) return;
    // 0046ea92  e938feffff             -jmp 0x46e8cf
    goto L_0x0046e8cf;
L_0x0046ea97:
    // 0046ea97  833d00d14d0000         +cmp dword ptr [0x4dd100], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099776) /* 0x4dd100 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ea9e  0f8409ffffff           -je 0x46e9ad
    if (cpu.flags.zf)
    {
        goto L_0x0046e9ad;
    }
    // 0046eaa4  a104955100             -mov eax, dword ptr [0x519504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346564) /* 0x519504 */);
    // 0046eaa9  bb3e010000             -mov ebx, 0x13e
    cpu.ebx = 318 /*0x13e*/;
    // 0046eaae  ba14020000             -mov edx, 0x214
    cpu.edx = 532 /*0x214*/;
    // 0046eab3  e9edfeffff             -jmp 0x46e9a5
    goto L_0x0046e9a5;
L_0x0046eab8:
    // 0046eab8  e89f780000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0046eabd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046eac0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eac1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eac2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eac3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eac4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eac5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ead0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ead0  e8bb50ffff             -call 0x463b90
    cpu.esp -= 4;
    sub_463b90(app, cpu);
    if (cpu.terminate) return;
    // 0046ead5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ead7  750a                   -jne 0x46eae3
    if (!cpu.flags.zf)
    {
        goto L_0x0046eae3;
    }
    // 0046ead9  833d1495510000         +cmp dword ptr [0x519514], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046eae0  750b                   -jne 0x46eaed
    if (!cpu.flags.zf)
    {
        goto L_0x0046eaed;
    }
    // 0046eae2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046eae3:
    // 0046eae3  c7051495510001000000   -mov dword ptr [0x519514], 1
    app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */) = 1 /*0x1*/;
L_0x0046eaed:
    // 0046eaed  e87e76fdff             -call 0x446170
    cpu.esp -= 4;
    sub_446170(app, cpu);
    if (cpu.terminate) return;
    // 0046eaf2  e8c9040000             -call 0x46efc0
    cpu.esp -= 4;
    sub_46efc0(app, cpu);
    if (cpu.terminate) return;
    // 0046eaf7  e904000000             -jmp 0x46eb00
    return sub_46eb00(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46eb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046eb00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046eb01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046eb02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046eb03  e840780000             -call 0x476348
    cpu.esp -= 4;
    sub_476348(app, cpu);
    if (cpu.terminate) return;
    // 0046eb08  833d1095510000         +cmp dword ptr [0x519510], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046eb0f  7536                   -jne 0x46eb47
    if (!cpu.flags.zf)
    {
        goto L_0x0046eb47;
    }
L_0x0046eb11:
    // 0046eb11  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046eb13  8b1d10955100           -mov ebx, dword ptr [0x519510]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046eb19  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 0046eb1e  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 0046eb23  8b0cdd40814c00         -mov ecx, dword ptr [ebx*8 + 0x4c8140]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013824) /* 0x4c8140 */ + cpu.ebx * 8);
    // 0046eb2a  8b1cdd3c814c00         -mov ebx, dword ptr [ebx*8 + 0x4c813c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013820) /* 0x4c813c */ + cpu.ebx * 8);
    // 0046eb31  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eb33  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eb35  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0046eb37  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046eb39  e8e2e60000             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 0046eb3e  e819780000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0046eb43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eb44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eb45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eb46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046eb47:
    // 0046eb47  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046eb49  a124995100             -mov eax, dword ptr [0x519924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347620) /* 0x519924 */);
    // 0046eb4e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eb50  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eb52  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046eb54  e857000000             -call 0x46ebb0
    cpu.esp -= 4;
    sub_46ebb0(app, cpu);
    if (cpu.terminate) return;
    // 0046eb59  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046eb5b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046eb60  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0046eb65  a124995100             -mov eax, dword ptr [0x519924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347620) /* 0x519924 */);
    // 0046eb6a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eb6c  e83f000000             -call 0x46ebb0
    cpu.esp -= 4;
    sub_46ebb0(app, cpu);
    if (cpu.terminate) return;
    // 0046eb71  e8e6770000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 0046eb76  e8cd770000             -call 0x476348
    cpu.esp -= 4;
    sub_476348(app, cpu);
    if (cpu.terminate) return;
    // 0046eb7b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046eb7d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046eb82  bbf0000000             -mov ebx, 0xf0
    cpu.ebx = 240 /*0xf0*/;
    // 0046eb87  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0046eb8c  a124995100             -mov eax, dword ptr [0x519924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347620) /* 0x519924 */);
    // 0046eb91  e81a000000             -call 0x46ebb0
    cpu.esp -= 4;
    sub_46ebb0(app, cpu);
    if (cpu.terminate) return;
    // 0046eb96  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046eb98  bbf0000000             -mov ebx, 0xf0
    cpu.ebx = 240 /*0xf0*/;
    // 0046eb9d  a124995100             -mov eax, dword ptr [0x519924]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347620) /* 0x519924 */);
    // 0046eba2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eba4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046eba6  e805000000             -call 0x46ebb0
    cpu.esp -= 4;
    sub_46ebb0(app, cpu);
    if (cpu.terminate) return;
    // 0046ebab  e961ffffff             -jmp 0x46eb11
    goto L_0x0046eb11;
}

/* align: skip  */
void Application::sub_46ebb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ebb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ebb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ebb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ebb3  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0046ebb6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046ebb8  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046ebbb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046ebbe  48                     -dec eax
    (cpu.eax)--;
    // 0046ebbf  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0046ebc2  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0046ebc6  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0046ebca  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046ebcd  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ebd1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046ebd4  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0046ebd8  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0046ebdc  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 0046ebe0  48                     -dec eax
    (cpu.eax)--;
    // 0046ebe1  81c3f0000000           -add ebx, 0xf0
    (cpu.ebx) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 0046ebe7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0046ebea  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 0046ebee  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 0046ebf2  8d8240010000           -lea eax, [edx + 0x140]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(320) /* 0x140 */);
    // 0046ebf8  895c2444               -mov dword ptr [esp + 0x44], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ebx;
    // 0046ebfc  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0046ec00  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0046ec04  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 0046ec08  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046ec0c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ec0e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec0f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec10  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046ec13  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046ec17  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046ec1b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046ec1f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046ec23  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0046ec27  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046ec2b  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046ec2f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046ec33  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046ec35  7568                   -jne 0x46ec9f
    if (!cpu.flags.zf)
    {
        goto L_0x0046ec9f;
    }
L_0x0046ec37:
    // 0046ec37  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ec3c  7438                   -je 0x46ec76
    if (cpu.flags.zf)
    {
        goto L_0x0046ec76;
    }
    // 0046ec3e  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046ec42  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046ec44  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec45  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec46  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046ec48  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046ec4c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec4d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec4e  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046ec52  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046ec56  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec57  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec58  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046ec5c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ec60  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec61  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec62  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ec66  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ec6a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec6b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec6c  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ec70  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046ec74  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec75  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
L_0x0046ec76:
    // 0046ec76  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046ec7a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046ec7c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046ec7e  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046ec82  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ec86  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0046ec8b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046ec8d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046ec8f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec90  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ec91  e8c6f70100             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 0046ec96  83c460                 +add esp, 0x60
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046ec99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec9c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0046ec9f:
    // 0046ec9f  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046eca3  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046eca5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046eca6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046eca7  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046eca9  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ecad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ecae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ecaf  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ecb3  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046ecb7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ecb8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ecb9  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046ecbd  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ecc1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ecc2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ecc3  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ecc7  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046eccb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046eccc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046eccd  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046ecd1  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046ecd5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ecd6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046ecd7  e95bffffff             -jmp 0x46ec37
    goto L_0x0046ec37;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46ece0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ece0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ece1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ece2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046ece4  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046ece6  83f901                 +cmp ecx, 1
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ece9  7429                   -je 0x46ed14
    if (cpu.flags.zf)
    {
        goto L_0x0046ed14;
    }
    // 0046eceb  83f903                 +cmp ecx, 3
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ecee  752b                   -jne 0x46ed1b
    if (!cpu.flags.zf)
    {
        goto L_0x0046ed1b;
    }
    // 0046ecf0  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046ecf3  8b048504955100         -mov eax, dword ptr [eax*4 + 0x519504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346564) /* 0x519504 */ + cpu.eax * 4);
L_0x0046ecfa:
    // 0046ecfa  e849770000             -call 0x476448
    cpu.esp -= 4;
    sub_476448(app, cpu);
    if (cpu.terminate) return;
    // 0046ecff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046ed01  e84a000000             -call 0x46ed50
    cpu.esp -= 4;
    sub_46ed50(app, cpu);
    if (cpu.terminate) return;
    // 0046ed06  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ed0a  e851040000             -call 0x46f160
    cpu.esp -= 4;
    sub_46f160(app, cpu);
    if (cpu.terminate) return;
    // 0046ed0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed11  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0046ed14:
    // 0046ed14  a138955100             -mov eax, dword ptr [0x519538]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346616) /* 0x519538 */);
    // 0046ed19  ebdf                   -jmp 0x46ecfa
    goto L_0x0046ecfa;
L_0x0046ed1b:
    // 0046ed1b  a134955100             -mov eax, dword ptr [0x519534]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346612) /* 0x519534 */);
    // 0046ed20  ebd8                   -jmp 0x46ecfa
    goto L_0x0046ecfa;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ed30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ed30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ed31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ed32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ed33  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 0046ed38  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 0046ed3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ed3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ed41  e8aa7f0000             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 0046ed46  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed49  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ed50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ed50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ed51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ed52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ed53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ed54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ed55  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046ed57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ed59  e82294fcff             -call 0x438180
    cpu.esp -= 4;
    sub_438180(app, cpu);
    if (cpu.terminate) return;
    // 0046ed5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ed60  7509                   -jne 0x46ed6b
    if (!cpu.flags.zf)
    {
        goto L_0x0046ed6b;
    }
    // 0046ed62  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ed65  0f848a000000           -je 0x46edf5
    if (cpu.flags.zf)
    {
        goto L_0x0046edf5;
    }
L_0x0046ed6b:
    // 0046ed6b  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046ed6e  b9348a5100             -mov ecx, 0x518a34
    cpu.ecx = 5343796 /*0x518a34*/;
    // 0046ed73  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0046ed76  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ed78  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0046ed7a  8b5a68                 -mov ebx, dword ptr [edx + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(104) /* 0x68 */);
    // 0046ed7d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046ed80  8b726c                 -mov esi, dword ptr [edx + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0046ed83  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ed85  09f3                   +or ebx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi))));
    // 0046ed87  0f84d6000000           -je 0x46ee63
    if (cpu.flags.zf)
    {
        goto L_0x0046ee63;
    }
    // 0046ed8d  8b4a68                 -mov ecx, dword ptr [edx + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(104) /* 0x68 */);
    // 0046ed90  0fbf18                 -movsx ebx, word ptr [eax]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0046ed93  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ed95  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046ed97  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046ed9a  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ed9c  890d2c955100           -mov dword ptr [0x51952c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5346604) /* 0x51952c */) = cpu.ecx;
    // 0046eda2  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046eda5  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046eda8  891d48955100           -mov dword ptr [0x519548], ebx
    app->getMemory<x86::reg32>(x86::reg32(5346632) /* 0x519548 */) = cpu.ebx;
    // 0046edae  8d140b                 -lea edx, [ebx + ecx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ecx * 1);
L_0x0046edb1:
    // 0046edb1  891524955100           -mov dword ptr [0x519524], edx
    app->getMemory<x86::reg32>(x86::reg32(5346596) /* 0x519524 */) = cpu.edx;
    // 0046edb7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046edba  a12c955100             -mov eax, dword ptr [0x51952c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346604) /* 0x51952c */);
    // 0046edbf  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046edc2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046edc4  a330955100             -mov dword ptr [0x519530], eax
    app->getMemory<x86::reg32>(x86::reg32(5346608) /* 0x519530 */) = cpu.eax;
    // 0046edc9  a130955100             -mov eax, dword ptr [0x519530]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346608) /* 0x519530 */);
    // 0046edce  a33c955100             -mov dword ptr [0x51953c], eax
    app->getMemory<x86::reg32>(x86::reg32(5346620) /* 0x51953c */) = cpu.eax;
L_0x0046edd3:
    // 0046edd3  8b0d30955100           -mov ecx, dword ptr [0x519530]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5346608) /* 0x519530 */);
    // 0046edd9  8b1d24955100           -mov ebx, dword ptr [0x519524]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5346596) /* 0x519524 */);
    // 0046eddf  8b152c955100           -mov edx, dword ptr [0x51952c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5346604) /* 0x51952c */);
    // 0046ede5  a148955100             -mov eax, dword ptr [0x519548]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5346632) /* 0x519548 */);
    // 0046edea  e8017f0000             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 0046edef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edf1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edf2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edf3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edf4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046edf5:
    // 0046edf5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046edf6  e8654dffff             -call 0x463b60
    cpu.esp -= 4;
    sub_463b60(app, cpu);
    if (cpu.terminate) return;
    // 0046edfb  8a1d4c955100           -mov bl, byte ptr [0x51954c]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5346636) /* 0x51954c */);
    // 0046ee01  0fbf30                 -movsx esi, word ptr [eax]
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0046ee04  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0046ee06  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046ee08  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0046ee0a  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 0046ee0c  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0046ee0f  891548955100           -mov dword ptr [0x519548], edx
    app->getMemory<x86::reg32>(x86::reg32(5346632) /* 0x519548 */) = cpu.edx;
    // 0046ee15  8a154d955100           -mov dl, byte ptr [0x51954d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5346637) /* 0x51954d */);
    // 0046ee1b  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0046ee1d  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046ee1f  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 0046ee21  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046ee24  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046ee27  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046ee2a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046ee2d  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ee2f  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0046ee31  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ee33  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 0046ee35  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046ee37  892d2c955100           -mov dword ptr [0x51952c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5346604) /* 0x51952c */) = cpu.ebp;
    // 0046ee3d  d3ff                   -sar edi, cl
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (cpu.cl % 32));
    // 0046ee3f  893524955100           -mov dword ptr [0x519524], esi
    app->getMemory<x86::reg32>(x86::reg32(5346596) /* 0x519524 */) = cpu.esi;
    // 0046ee45  893d30955100           -mov dword ptr [0x519530], edi
    app->getMemory<x86::reg32>(x86::reg32(5346608) /* 0x519530 */) = cpu.edi;
    // 0046ee4b  e8d04cffff             -call 0x463b20
    cpu.esp -= 4;
    sub_463b20(app, cpu);
    if (cpu.terminate) return;
    // 0046ee50  8a0d4d955100           -mov cl, byte ptr [0x51954d]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5346637) /* 0x51954d */);
    // 0046ee56  d3f8                   +sar eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0046ee58  a33c955100             -mov dword ptr [0x51953c], eax
    app->getMemory<x86::reg32>(x86::reg32(5346620) /* 0x51953c */) = cpu.eax;
    // 0046ee5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee5e  e970ffffff             -jmp 0x46edd3
    goto L_0x0046edd3;
L_0x0046ee63:
    // 0046ee63  0fbf10                 -movsx edx, word ptr [eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 0046ee66  891548955100           -mov dword ptr [0x519548], edx
    app->getMemory<x86::reg32>(x86::reg32(5346632) /* 0x519548 */) = cpu.edx;
    // 0046ee6c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046ee6e  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046ee71  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046ee74  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046ee77  89152c955100           -mov dword ptr [0x51952c], edx
    app->getMemory<x86::reg32>(x86::reg32(5346604) /* 0x51952c */) = cpu.edx;
    // 0046ee7d  8b1548955100           -mov edx, dword ptr [0x519548]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5346632) /* 0x519548 */);
    // 0046ee83  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046ee85  e927ffffff             -jmp 0x46edb1
    goto L_0x0046edb1;
}

}
