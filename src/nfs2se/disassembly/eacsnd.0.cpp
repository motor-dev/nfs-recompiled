#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_548600(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00548600  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00548601  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00548606  b802000600             -mov eax, 0x60002
    cpu.eax = 393218 /*0x60002*/;
    // 0054860b  891560b85400           -mov dword ptr [0x54b860], edx
    *app->getMemory<x86::reg32>(x86::reg32(5552224) /* 0x54b860 */) = cpu.edx;
    // 00548611  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00548612  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_548614(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00548614  a368b85400             -mov dword ptr [0x54b868], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552232) /* 0x54b868 */) = cpu.eax;
    // 00548619  89156cb85400           -mov dword ptr [0x54b86c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */) = cpu.edx;
    // 0054861f  891d70b85400           -mov dword ptr [0x54b870], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5552240) /* 0x54b870 */) = cpu.ebx;
    // 00548625  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00548629  890d74b85400           -mov dword ptr [0x54b874], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5552244) /* 0x54b874 */) = cpu.ecx;
    // 0054862f  a378b85400             -mov dword ptr [0x54b878], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552248) /* 0x54b878 */) = cpu.eax;
    // 00548634  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00548636  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_54863c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0054863c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054863d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054863e  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054863f  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00548645  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00548647  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00548649  89942488000000         -mov dword ptr [esp + 0x88], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 00548650  833d60b8540000         +cmp dword ptr [0x54b860], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552224) /* 0x54b860 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548657  7c0f                   -jl 0x548668
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00548668;
    }
    // 00548659  a160b85400             -mov eax, dword ptr [0x54b860]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552224) /* 0x54b860 */);
    // 0054865e  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00548664  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00548665  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00548666  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00548667  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00548668:
    // 00548668  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00548669  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0054866a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054866b  803d10b8540000         +cmp byte ptr [0x54b810], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552144) /* 0x54b810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00548672  7475                   -je 0x5486e9
    if (cpu.flags.zf)
    {
        goto L_0x005486e9;
    }
L_0x00548674:
    // 00548674  c744240c60000000       -mov dword ptr [esp + 0xc], 0x60
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 96 /*0x60*/;
    // 0054867c  a100b85400             -mov eax, dword ptr [0x54b800]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 00548681  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00548683  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00548687  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00548688  8b3d00b85400           -mov edi, dword ptr [0x54b800]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 0054868e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0054868f  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548692  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548694  0f848b000000           -je 0x548725
    if (cpu.flags.zf)
    {
        goto L_0x00548725;
    }
L_0x0054869a:
    // 0054869a  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x005486a5:
    // 005486a5  803d10b8540000         +cmp byte ptr [0x54b810], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552144) /* 0x54b810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005486ac  7522                   -jne 0x5486d0
    if (!cpu.flags.zf)
    {
        goto L_0x005486d0;
    }
    // 005486ae  833d00b8540000         +cmp dword ptr [0x54b800], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005486b5  7411                   -je 0x5486c8
    if (cpu.flags.zf)
    {
        goto L_0x005486c8;
    }
    // 005486b7  a100b85400             -mov eax, dword ptr [0x54b800]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 005486bc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 005486be  8b1500b85400           -mov edx, dword ptr [0x54b800]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 005486c4  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005486c5  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005486c8:
    // 005486c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 005486ca  890d00b85400           -mov dword ptr [0x54b800], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */) = cpu.ecx;
L_0x005486d0:
    // 005486d0  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 005486d7  a360b85400             -mov dword ptr [0x54b860], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552224) /* 0x54b860 */) = cpu.eax;
    // 005486dc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005486dd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005486de  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005486df  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 005486e5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005486e6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005486e7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005486e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005486e9:
    // 005486e9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005486ea  6800b85400             -push 0x54b800
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552128 /*0x54b800*/;
    cpu.esp -= 4;
    // 005486ef  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005486f0  e83f110000             -call 0x549834
    cpu.esp -= 4;
    sub_549834(app, cpu);
    if (cpu.terminate) return;
    // 005486f5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005486f7  0f8477ffffff           -je 0x548674
    if (cpu.flags.zf)
    {
        goto L_0x00548674;
    }
    // 005486fd  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548702  7414                   -je 0x548718
    if (cpu.flags.zf)
    {
        goto L_0x00548718;
    }
    // 00548704  3d78007888             +cmp eax, 0x88780078
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565816 /*0x88780078*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548709  758f                   -jne 0x54869a
    if (!cpu.flags.zf)
    {
        goto L_0x0054869a;
    }
    // 0054870b  c7842494000000f6ffffff -mov dword ptr [esp + 0x94], 0xfffffff6
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967286 /*0xfffffff6*/;
    // 00548716  eb8d                   -jmp 0x5486a5
    goto L_0x005486a5;
L_0x00548718:
    // 00548718  c7842494000000eeffffff -mov dword ptr [esp + 0x94], 0xffffffee
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967278 /*0xffffffee*/;
    // 00548723  eb80                   -jmp 0x5486a5
    goto L_0x005486a5;
L_0x00548725:
    // 00548725  f644241020             +test byte ptr [esp + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 0054872a  0f84c2000000           -je 0x5487f2
    if (cpu.flags.zf)
    {
        goto L_0x005487f2;
    }
    // 00548730  c60515b8540001         -mov byte ptr [0x54b815], 1
    *app->getMemory<x86::reg8>(x86::reg32(5552149) /* 0x54b815 */) = 1 /*0x1*/;
L_0x00548737:
    // 00548737  8aac2496000000         -mov ch, byte ptr [esp + 0x96]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */);
    // 0054873e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00548743  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00548747  80cd02                 -or ch, 2
    cpu.ch |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0054874a  6689942482000000       -mov word ptr [esp + 0x82], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.dx;
    // 00548752  88ac2496000000         -mov byte ptr [esp + 0x96], ch
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(150) /* 0x96 */) = cpu.ch;
    // 00548759  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0054875e  83e005                 -and eax, 5
    cpu.eax &= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 00548761  66898c248e000000       -mov word ptr [esp + 0x8e], cx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.cx;
    // 00548769  83f805                 +cmp eax, 5
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
    // 0054876c  7508                   -jne 0x548776
    if (!cpu.flags.zf)
    {
        goto L_0x00548776;
    }
    // 0054876e  808c249400000001       -or byte ptr [esp + 0x94], 1
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00548776:
    // 00548776  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0054877a  83e006                 -and eax, 6
    cpu.eax &= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0054877d  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548780  7508                   -jne 0x54878a
    if (!cpu.flags.zf)
    {
        goto L_0x0054878a;
    }
    // 00548782  808c249400000002       -or byte ptr [esp + 0x94], 2
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0054878a:
    // 0054878a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0054878e  83e009                 -and eax, 9
    cpu.eax &= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 00548791  83f809                 +cmp eax, 9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548794  7508                   -jne 0x54879e
    if (!cpu.flags.zf)
    {
        goto L_0x0054879e;
    }
    // 00548796  808c249400000004       -or byte ptr [esp + 0x94], 4
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0054879e:
    // 0054879e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 005487a2  83e00a                 -and eax, 0xa
    cpu.eax &= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 005487a5  83f80a                 +cmp eax, 0xa
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005487a8  752b                   -jne 0x5487d5
    if (!cpu.flags.zf)
    {
        goto L_0x005487d5;
    }
    // 005487aa  8ab42494000000         -mov dh, byte ptr [esp + 0x94]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 005487b1  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 005487b6  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
    // 005487bb  80ce08                 -or dh, 8
    cpu.dh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 005487be  6689b42482000000       -mov word ptr [esp + 0x82], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */) = cpu.si;
    // 005487c6  6689bc248e000000       -mov word ptr [esp + 0x8e], di
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */) = cpu.di;
    // 005487ce  88b42494000000         -mov byte ptr [esp + 0x94], dh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.dh;
L_0x005487d5:
    // 005487d5  a100b85400             -mov eax, dword ptr [0x54b800]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 005487da  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 005487dc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 005487de  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005487df  8b2d00b85400           -mov ebp, dword ptr [0x54b800]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 005487e5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005487e6  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005487e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005487eb  7412                   -je 0x5487ff
    if (cpu.flags.zf)
    {
        goto L_0x005487ff;
    }
    // 005487ed  e9a8feffff             -jmp 0x54869a
    goto L_0x0054869a;
L_0x005487f2:
    // 005487f2  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 005487f4  883515b85400           -mov byte ptr [0x54b815], dh
    *app->getMemory<x86::reg8>(x86::reg32(5552149) /* 0x54b815 */) = cpu.dh;
    // 005487fa  e938ffffff             -jmp 0x548737
    goto L_0x00548737;
L_0x005487ff:
    // 005487ff  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00548804  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00548808  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054880a  e8680f0000             -call 0x549777
    cpu.esp -= 4;
    sub_549777(app, cpu);
    if (cpu.terminate) return;
    // 0054880f  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00548814  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00548819  8944246c               -mov dword ptr [esp + 0x6c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 0054881d  89542470               -mov dword ptr [esp + 0x70], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 00548821  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00548823  8b1500b85400           -mov edx, dword ptr [0x54b800]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 00548829  6804b85400             -push 0x54b804
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552132 /*0x54b804*/;
    cpu.esp -= 4;
    // 0054882e  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00548832  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00548834  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00548835  8b0d00b85400           -mov ecx, dword ptr [0x54b800]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 0054883b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054883c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054883f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548841  0f8553feffff           -jne 0x54869a
    if (!cpu.flags.zf)
    {
        goto L_0x0054869a;
    }
    // 00548847  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0054884c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054884e  6689842480000000       -mov word ptr [esp + 0x80], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.ax;
    // 00548856  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00548858  668b942482000000       -mov dx, word ptr [esp + 0x82]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
    // 00548860  668b84248e000000       -mov ax, word ptr [esp + 0x8e]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
    // 00548868  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0054886b  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0054886e  668984248c000000       -mov word ptr [esp + 0x8c], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.ax;
    // 00548876  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00548878  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00548880  69c0112b0000           -imul eax, eax, 0x2b11
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(11025 /*0x2b11*/)));
    // 00548886  bb112b0000             -mov ebx, 0x2b11
    cpu.ebx = 11025 /*0x2b11*/;
    // 0054888b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054888d  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 00548894  6689942490000000       -mov word ptr [esp + 0x90], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.dx;
    // 0054889c  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005488a3  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 005488a8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 005488aa  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005488b1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005488b2  8b3504b85400           -mov esi, dword ptr [0x54b804]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 005488b8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005488b9  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005488bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005488be  7508                   -jne 0x5488c8
    if (!cpu.flags.zf)
    {
        goto L_0x005488c8;
    }
    // 005488c0  808c249500000002       -or byte ptr [esp + 0x95], 2
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x005488c8:
    // 005488c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005488ca  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005488d2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005488d9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005488db  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005488de  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005488e0  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 005488e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 005488e5  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 005488e8  bf803e0000             -mov edi, 0x3e80
    cpu.edi = 16000 /*0x3e80*/;
    // 005488ed  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005488ef  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 005488f6  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005488fd  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548902  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00548904  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0054890b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054890c  8b2d04b85400           -mov ebp, dword ptr [0x54b804]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548912  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00548913  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548916  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548918  7508                   -jne 0x548922
    if (!cpu.flags.zf)
    {
        goto L_0x00548922;
    }
    // 0054891a  808c249500000004       -or byte ptr [esp + 0x95], 4
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00548922:
    // 00548922  c784248400000022560000 -mov dword ptr [esp + 0x84], 0x5622
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 22050 /*0x5622*/;
    // 0054892d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0054892f  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00548937  69c022560000           -imul eax, eax, 0x5622
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(22050 /*0x5622*/)));
    // 0054893d  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 00548944  8b1504b85400           -mov edx, dword ptr [0x54b804]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 0054894a  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00548951  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00548953  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00548954  8b0d04b85400           -mov ecx, dword ptr [0x54b804]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 0054895a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0054895b  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054895e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548960  7508                   -jne 0x54896a
    if (!cpu.flags.zf)
    {
        goto L_0x0054896a;
    }
    // 00548962  808c249500000008       -or byte ptr [esp + 0x95], 8
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0054896a:
    // 0054896a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0054896c  668b94248c000000       -mov dx, word ptr [esp + 0x8c]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00548974  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0054897b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0054897d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00548980  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00548982  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00548985  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00548987  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0054898a  bb007d0000             -mov ebx, 0x7d00
    cpu.ebx = 32000 /*0x7d00*/;
    // 0054898f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00548991  899c2484000000         -mov dword ptr [esp + 0x84], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ebx;
    // 00548998  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0054899f  8b1504b85400           -mov edx, dword ptr [0x54b804]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 005489a5  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005489ac  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 005489ae  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005489af  8b3504b85400           -mov esi, dword ptr [0x54b804]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 005489b5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005489b6  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005489b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005489bb  7508                   -jne 0x5489c5
    if (!cpu.flags.zf)
    {
        goto L_0x005489c5;
    }
    // 005489bd  808c249500000010       -or byte ptr [esp + 0x95], 0x10
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x005489c5:
    // 005489c5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005489c7  bf44ac0000             -mov edi, 0xac44
    cpu.edi = 44100 /*0xac44*/;
    // 005489cc  668b84248c000000       -mov ax, word ptr [esp + 0x8c]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 005489d4  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 005489d7  89bc2484000000         -mov dword ptr [esp + 0x84], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 005489de  89842488000000         -mov dword ptr [esp + 0x88], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 005489e5  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 005489ea  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 005489ec  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 005489f3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005489f4  8b2d04b85400           -mov ebp, dword ptr [0x54b804]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 005489fa  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005489fb  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005489fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548a00  7508                   -jne 0x548a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00548a0a;
    }
    // 00548a02  808c249500000020       -or byte ptr [esp + 0x95], 0x20
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00548a0a:
    // 00548a0a  f68424940000000f       +test byte ptr [esp + 0x94], 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(148) /* 0x94 */) & 15 /*0xf*/));
    // 00548a12  7571                   -jne 0x548a85
    if (!cpu.flags.zf)
    {
        goto L_0x00548a85;
    }
L_0x00548a14:
    // 00548a14  c7842494000000ffffffff -mov dword ptr [esp + 0x94], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4294967295 /*0xffffffff*/;
L_0x00548a1f:
    // 00548a1f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00548a21  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548a26  6a12                   -push 0x12
    *app->getMemory<x86::reg32>(cpu.esp-4) = 18 /*0x12*/;
    cpu.esp -= 4;
    // 00548a28  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00548a2f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00548a31  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00548a32  8b1d04b85400           -mov ebx, dword ptr [0x54b804]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548a38  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00548a39  ff5014                 -call dword ptr [eax + 0x14]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548a3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548a3e  0f8561fcffff           -jne 0x5486a5
    if (!cpu.flags.zf)
    {
        goto L_0x005486a5;
    }
    // 00548a44  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00548a4d  754f                   -jne 0x548a9e
    if (!cpu.flags.zf)
    {
        goto L_0x00548a9e;
    }
    // 00548a4f  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00548a58  7544                   -jne 0x548a9e
    if (!cpu.flags.zf)
    {
        goto L_0x00548a9e;
    }
    // 00548a5a  c784249400000001000000 -mov dword ptr [esp + 0x94], 1
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
L_0x00548a65:
    // 00548a65  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00548a6c  81f9112b0000           +cmp ecx, 0x2b11
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11025 /*0x2b11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548a72  0f859a000000           -jne 0x548b12
    if (!cpu.flags.zf)
    {
        goto L_0x00548b12;
    }
    // 00548a78  808c249500000002       +or byte ptr [esp + 0x95], 2
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00548a80  e920fcffff             -jmp 0x5486a5
    goto L_0x005486a5;
L_0x00548a85:
    // 00548a85  f68424950000003e       +test byte ptr [esp + 0x95], 0x3e
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) & 62 /*0x3e*/));
    // 00548a8d  7485                   -je 0x548a14
    if (cpu.flags.zf)
    {
        goto L_0x00548a14;
    }
    // 00548a8f  83bc249400000000       +cmp dword ptr [esp + 0x94], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548a97  7e86                   -jle 0x548a1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00548a1f;
    }
    // 00548a99  e907fcffff             -jmp 0x5486a5
    goto L_0x005486a5;
L_0x00548a9e:
    // 00548a9e  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00548aa7  7518                   -jne 0x548ac1
    if (!cpu.flags.zf)
    {
        goto L_0x00548ac1;
    }
    // 00548aa9  6683bc248e00000008     +cmp word ptr [esp + 0x8e], 8
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(8 /*0x8*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00548ab2  750d                   -jne 0x548ac1
    if (!cpu.flags.zf)
    {
        goto L_0x00548ac1;
    }
    // 00548ab4  c784249400000002000000 -mov dword ptr [esp + 0x94], 2
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 2 /*0x2*/;
    // 00548abf  eba4                   -jmp 0x548a65
    goto L_0x00548a65;
L_0x00548ac1:
    // 00548ac1  6683bc248200000001     +cmp word ptr [esp + 0x82], 1
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00548aca  7518                   -jne 0x548ae4
    if (!cpu.flags.zf)
    {
        goto L_0x00548ae4;
    }
    // 00548acc  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00548ad5  750d                   -jne 0x548ae4
    if (!cpu.flags.zf)
    {
        goto L_0x00548ae4;
    }
    // 00548ad7  c784249400000004000000 -mov dword ptr [esp + 0x94], 4
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 4 /*0x4*/;
    // 00548ae2  eb81                   -jmp 0x548a65
    goto L_0x00548a65;
L_0x00548ae4:
    // 00548ae4  6683bc248200000002     +cmp word ptr [esp + 0x82], 2
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(130) /* 0x82 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00548aed  0f85a7fbffff           -jne 0x54869a
    if (!cpu.flags.zf)
    {
        goto L_0x0054869a;
    }
    // 00548af3  6683bc248e00000010     +cmp word ptr [esp + 0x8e], 0x10
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(142) /* 0x8e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00548afc  0f8598fbffff           -jne 0x54869a
    if (!cpu.flags.zf)
    {
        goto L_0x0054869a;
    }
    // 00548b02  c784249400000008000000 -mov dword ptr [esp + 0x94], 8
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = 8 /*0x8*/;
    // 00548b0d  e953ffffff             -jmp 0x548a65
    goto L_0x00548a65;
L_0x00548b12:
    // 00548b12  81f9803e0000           +cmp ecx, 0x3e80
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16000 /*0x3e80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548b18  750d                   -jne 0x548b27
    if (!cpu.flags.zf)
    {
        goto L_0x00548b27;
    }
    // 00548b1a  808c249500000004       +or byte ptr [esp + 0x95], 4
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00548b22  e97efbffff             -jmp 0x5486a5
    goto L_0x005486a5;
L_0x00548b27:
    // 00548b27  81f922560000           +cmp ecx, 0x5622
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22050 /*0x5622*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548b2d  750d                   -jne 0x548b3c
    if (!cpu.flags.zf)
    {
        goto L_0x00548b3c;
    }
    // 00548b2f  808c249500000008       +or byte ptr [esp + 0x95], 8
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00548b37  e969fbffff             -jmp 0x5486a5
    goto L_0x005486a5;
L_0x00548b3c:
    // 00548b3c  81f9007d0000           +cmp ecx, 0x7d00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32000 /*0x7d00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548b42  750d                   -jne 0x548b51
    if (!cpu.flags.zf)
    {
        goto L_0x00548b51;
    }
    // 00548b44  808c249500000010       +or byte ptr [esp + 0x95], 0x10
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00548b4c  e954fbffff             -jmp 0x5486a5
    goto L_0x005486a5;
L_0x00548b51:
    // 00548b51  81f944ac0000           +cmp ecx, 0xac44
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44100 /*0xac44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548b57  0f853dfbffff           -jne 0x54869a
    if (!cpu.flags.zf)
    {
        goto L_0x0054869a;
    }
    // 00548b5d  808c249500000020       +or byte ptr [esp + 0x95], 0x20
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(149) /* 0x95 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00548b65  e93bfbffff             -jmp 0x5486a5
    goto L_0x005486a5;
}

/* align: skip 0x8b 0xc0 */
void sub_548b6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00548b6c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00548b6d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00548b6e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00548b6f  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00548b70  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00548b73  89442440               -mov dword ptr [esp + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00548b77  895c243c               -mov dword ptr [esp + 0x3c], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 00548b7b  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 00548b80  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548b82  0f8499010000           -je 0x548d21
    if (cpu.flags.zf)
    {
        goto L_0x00548d21;
    }
    // 00548b88  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x00548b8d:
    // 00548b8d  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 00548b90  0f8495010000           -je 0x548d2b
    if (cpu.flags.zf)
    {
        goto L_0x00548d2b;
    }
    // 00548b96  c70564b8540022560000   -mov dword ptr [0x54b864], 0x5622
    *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */) = 22050 /*0x5622*/;
L_0x00548ba0:
    // 00548ba0  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00548ba3  0f84e9010000           -je 0x548d92
    if (cpu.flags.zf)
    {
        goto L_0x00548d92;
    }
    // 00548ba9  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00548bae:
    // 00548bae  bf10000000             -mov edi, 0x10
    cpu.edi = 16 /*0x10*/;
L_0x00548bb3:
    // 00548bb3  803d15b8540000         +cmp byte ptr [0x54b815], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552149) /* 0x54b815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00548bba  0f8420020000           -je 0x548de0
    if (cpu.flags.zf)
    {
        goto L_0x00548de0;
    }
    // 00548bc0  c70530b8540000200000   -mov dword ptr [0x54b830], 0x2000
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = 8192 /*0x2000*/;
    // 00548bca  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548bcd  750c                   -jne 0x548bdb
    if (!cpu.flags.zf)
    {
        goto L_0x00548bdb;
    }
    // 00548bcf  a130b85400             -mov eax, dword ptr [0x54b830]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */);
    // 00548bd4  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00548bd6  a330b85400             -mov dword ptr [0x54b830], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.eax;
L_0x00548bdb:
    // 00548bdb  83fe01                 +cmp esi, 1
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
    // 00548bde  750e                   -jne 0x548bee
    if (!cpu.flags.zf)
    {
        goto L_0x00548bee;
    }
    // 00548be0  8b1530b85400           -mov edx, dword ptr [0x54b830]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */);
    // 00548be6  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00548be8  891530b85400           -mov dword ptr [0x54b830], edx
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.edx;
L_0x00548bee:
    // 00548bee  812530b85400f0ff0f00   -and dword ptr [0x54b830], 0xffff0
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00548bf8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00548bfa  a338b85400             -mov dword ptr [0x54b838], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552184) /* 0x54b838 */) = cpu.eax;
    // 00548bff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00548c01  a32cb85400             -mov dword ptr [0x54b82c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552172) /* 0x54b82c */) = cpu.eax;
    // 00548c06  a324b85400             -mov dword ptr [0x54b824], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */) = cpu.eax;
    // 00548c0b  a328b85400             -mov dword ptr [0x54b828], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552168) /* 0x54b828 */) = cpu.eax;
    // 00548c10  a338b85400             -mov dword ptr [0x54b838], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552184) /* 0x54b838 */) = cpu.eax;
    // 00548c15  a318b85400             -mov dword ptr [0x54b818], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */) = cpu.eax;
    // 00548c1a  a344b85400             -mov dword ptr [0x54b844], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552196) /* 0x54b844 */) = cpu.eax;
    // 00548c1f  b932000000             -mov ecx, 0x32
    cpu.ecx = 50 /*0x32*/;
    // 00548c24  a164b85400             -mov eax, dword ptr [0x54b864]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */);
    // 00548c29  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00548c2b  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00548c30  a31cb85400             -mov dword ptr [0x54b81c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552156) /* 0x54b81c */) = cpu.eax;
    // 00548c35  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00548c37  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00548c3a  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00548c3d  a213b85400             -mov byte ptr [0x54b813], al
    *app->getMemory<x86::reg8>(x86::reg32(5552147) /* 0x54b813 */) = cpu.al;
    // 00548c42  0fbe0513b85400         -movsx eax, byte ptr [0x54b813]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552147) /* 0x54b813 */)));
    // 00548c49  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00548c4b  a214b85400             -mov byte ptr [0x54b814], al
    *app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */) = cpu.al;
    // 00548c50  803d10b8540000         +cmp byte ptr [0x54b810], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552144) /* 0x54b810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00548c57  751d                   -jne 0x548c76
    if (!cpu.flags.zf)
    {
        goto L_0x00548c76;
    }
    // 00548c59  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00548c5b  6800b85400             -push 0x54b800
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552128 /*0x54b800*/;
    cpu.esp -= 4;
    // 00548c60  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00548c62  e8cd0b0000             -call 0x549834
    cpu.esp -= 4;
    sub_549834(app, cpu);
    if (cpu.terminate) return;
    // 00548c67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548c69  0f859a010000           -jne 0x548e09
    if (!cpu.flags.zf)
    {
        goto L_0x00548e09;
    }
    // 00548c6f  c60510b8540001         -mov byte ptr [0x54b810], 1
    *app->getMemory<x86::reg8>(x86::reg32(5552144) /* 0x54b810 */) = 1 /*0x1*/;
L_0x00548c76:
    // 00548c76  a100b85400             -mov eax, dword ptr [0x54b800]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 00548c7b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00548c7c  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00548c80  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00548c82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00548c83  8b0d00b85400           -mov ecx, dword ptr [0x54b800]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 00548c89  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00548c8a  ff5018                 -call dword ptr [eax + 0x18]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548c8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548c8f  0f84a0010000           -je 0x548e35
    if (cpu.flags.zf)
    {
        goto L_0x00548e35;
    }
    // 00548c95  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548c9c  740e                   -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00548c9e  685cb65400             -push 0x54b65c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5551708 /*0x54b65c*/;
    cpu.esp -= 4;
L_0x00548ca3:
    // 00548ca3  ff156cb85400           -call dword ptr [0x54b86c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548ca9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00548cac:
    // 00548cac  803d12b8540000         +cmp byte ptr [0x54b812], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552146) /* 0x54b812 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00548cb3  7434                   -je 0x548ce9
    if (cpu.flags.zf)
    {
        goto L_0x00548ce9;
    }
    // 00548cb5  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00548cb7  881512b85400           -mov byte ptr [0x54b812], dl
    *app->getMemory<x86::reg8>(x86::reg32(5552146) /* 0x54b812 */) = cpu.dl;
    // 00548cbd  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548cc2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00548cc4  8b3504b85400           -mov esi, dword ptr [0x54b804]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548cca  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00548ccb  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548cce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548cd0  7417                   -je 0x548ce9
    if (cpu.flags.zf)
    {
        goto L_0x00548ce9;
    }
    // 00548cd2  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548cd9  740e                   -je 0x548ce9
    if (cpu.flags.zf)
    {
        goto L_0x00548ce9;
    }
    // 00548cdb  68a0b75400             -push 0x54b7a0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552032 /*0x54b7a0*/;
    cpu.esp -= 4;
    // 00548ce0  ff156cb85400           -call dword ptr [0x54b86c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548ce6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00548ce9:
    // 00548ce9  803d10b8540000         +cmp byte ptr [0x54b810], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552144) /* 0x54b810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00548cf0  7425                   -je 0x548d17
    if (cpu.flags.zf)
    {
        goto L_0x00548d17;
    }
    // 00548cf2  833d00b8540000         +cmp dword ptr [0x54b800], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548cf9  0f859e040000           -jne 0x54919d
    if (!cpu.flags.zf)
    {
        goto L_0x0054919d;
    }
L_0x00548cff:
    // 00548cff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00548d01  890d00b85400           -mov dword ptr [0x54b800], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */) = cpu.ecx;
    // 00548d07  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00548d09  881d11b85400           -mov byte ptr [0x54b811], bl
    *app->getMemory<x86::reg8>(x86::reg32(5552145) /* 0x54b811 */) = cpu.bl;
    // 00548d0f  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00548d11  883d10b85400           -mov byte ptr [0x54b810], bh
    *app->getMemory<x86::reg8>(x86::reg32(5552144) /* 0x54b810 */) = cpu.bh;
L_0x00548d17:
    // 00548d17  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00548d19  83c444                 +add esp, 0x44
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00548d1c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00548d1d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00548d1e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00548d1f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00548d20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00548d21:
    // 00548d21  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00548d26  e962feffff             -jmp 0x548b8d
    goto L_0x00548b8d;
L_0x00548d2b:
    // 00548d2b  f6c604                 +test dh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 4 /*0x4*/));
    // 00548d2e  740f                   -je 0x548d3f
    if (cpu.flags.zf)
    {
        goto L_0x00548d3f;
    }
    // 00548d30  c70564b85400803e0000   -mov dword ptr [0x54b864], 0x3e80
    *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */) = 16000 /*0x3e80*/;
    // 00548d3a  e961feffff             -jmp 0x548ba0
    goto L_0x00548ba0;
L_0x00548d3f:
    // 00548d3f  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 00548d42  740f                   -je 0x548d53
    if (cpu.flags.zf)
    {
        goto L_0x00548d53;
    }
    // 00548d44  c70564b85400007d0000   -mov dword ptr [0x54b864], 0x7d00
    *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */) = 32000 /*0x7d00*/;
    // 00548d4e  e94dfeffff             -jmp 0x548ba0
    goto L_0x00548ba0;
L_0x00548d53:
    // 00548d53  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 00548d56  740f                   -je 0x548d67
    if (cpu.flags.zf)
    {
        goto L_0x00548d67;
    }
    // 00548d58  c70564b8540044ac0000   -mov dword ptr [0x54b864], 0xac44
    *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */) = 44100 /*0xac44*/;
    // 00548d62  e939feffff             -jmp 0x548ba0
    goto L_0x00548ba0;
L_0x00548d67:
    // 00548d67  f6c602                 +test dh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 2 /*0x2*/));
    // 00548d6a  740f                   -je 0x548d7b
    if (cpu.flags.zf)
    {
        goto L_0x00548d7b;
    }
    // 00548d6c  c70564b85400112b0000   -mov dword ptr [0x54b864], 0x2b11
    *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */) = 11025 /*0x2b11*/;
    // 00548d76  e925feffff             -jmp 0x548ba0
    goto L_0x00548ba0;
L_0x00548d7b:
    // 00548d7b  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548d82  0f8424ffffff           -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00548d88  6800b65400             -push 0x54b600
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5551616 /*0x54b600*/;
    cpu.esp -= 4;
    // 00548d8d  e911ffffff             -jmp 0x548ca3
    goto L_0x00548ca3;
L_0x00548d92:
    // 00548d92  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00548d95  740f                   -je 0x548da6
    if (cpu.flags.zf)
    {
        goto L_0x00548da6;
    }
    // 00548d97  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00548d9c  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 00548da1  e90dfeffff             -jmp 0x548bb3
    goto L_0x00548bb3;
L_0x00548da6:
    // 00548da6  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00548da9  740a                   -je 0x548db5
    if (cpu.flags.zf)
    {
        goto L_0x00548db5;
    }
    // 00548dab  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00548db0  e9f9fdffff             -jmp 0x548bae
    goto L_0x00548bae;
L_0x00548db5:
    // 00548db5  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00548db8  740f                   -je 0x548dc9
    if (cpu.flags.zf)
    {
        goto L_0x00548dc9;
    }
    // 00548dba  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00548dbf  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 00548dc4  e9eafdffff             -jmp 0x548bb3
    goto L_0x00548bb3;
L_0x00548dc9:
    // 00548dc9  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548dd0  0f84d6feffff           -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00548dd6  682cb65400             -push 0x54b62c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5551660 /*0x54b62c*/;
    cpu.esp -= 4;
    // 00548ddb  e9c3feffff             -jmp 0x548ca3
    goto L_0x00548ca3;
L_0x00548de0:
    // 00548de0  c70530b8540014000000   -mov dword ptr [0x54b830], 0x14
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = 20 /*0x14*/;
    // 00548dea  a164b85400             -mov eax, dword ptr [0x54b864]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */);
    // 00548def  0faf0530b85400         -imul eax, dword ptr [0x54b830]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */))));
    // 00548df6  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 00548dfb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00548dfd  f7f1                   +div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00548dff  a330b85400             -mov dword ptr [0x54b830], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.eax;
    // 00548e04  e9e5fdffff             -jmp 0x548bee
    goto L_0x00548bee;
L_0x00548e09:
    // 00548e09  3d0a007888             +cmp eax, 0x8878000a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565706 /*0x8878000a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548e0e  750a                   -jne 0x548e1a
    if (!cpu.flags.zf)
    {
        goto L_0x00548e1a;
    }
    // 00548e10  bdeeffffff             -mov ebp, 0xffffffee
    cpu.ebp = 4294967278 /*0xffffffee*/;
    // 00548e15  e992feffff             -jmp 0x548cac
    goto L_0x00548cac;
L_0x00548e1a:
    // 00548e1a  3d78007888             +cmp eax, 0x88780078
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289565816 /*0x88780078*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548e1f  750a                   -jne 0x548e2b
    if (!cpu.flags.zf)
    {
        goto L_0x00548e2b;
    }
    // 00548e21  bdf6ffffff             -mov ebp, 0xfffffff6
    cpu.ebp = 4294967286 /*0xfffffff6*/;
    // 00548e26  e981feffff             -jmp 0x548cac
    goto L_0x00548cac;
L_0x00548e2b:
    // 00548e2b  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 00548e30  e977feffff             -jmp 0x548cac
    goto L_0x00548cac;
L_0x00548e35:
    // 00548e35  803d11b8540000         +cmp byte ptr [0x54b811], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552145) /* 0x54b811 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00548e3c  755f                   -jne 0x548e9d
    if (!cpu.flags.zf)
    {
        goto L_0x00548e9d;
    }
    // 00548e3e  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00548e43  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00548e45  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00548e47  e82b090000             -call 0x549777
    cpu.esp -= 4;
    sub_549777(app, cpu);
    if (cpu.terminate) return;
    // 00548e4c  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00548e51  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00548e56  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00548e59  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00548e5d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00548e5f  8b1500b85400           -mov edx, dword ptr [0x54b800]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 00548e65  6804b85400             -push 0x54b804
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552132 /*0x54b804*/;
    cpu.esp -= 4;
    // 00548e6a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00548e6e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00548e70  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00548e71  8b0d00b85400           -mov ecx, dword ptr [0x54b800]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 00548e77  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00548e78  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548e7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548e7d  7417                   -je 0x548e96
    if (cpu.flags.zf)
    {
        goto L_0x00548e96;
    }
    // 00548e7f  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548e86  0f8420feffff           -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00548e8c  6890b65400             -push 0x54b690
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5551760 /*0x54b690*/;
    cpu.esp -= 4;
    // 00548e91  e90dfeffff             -jmp 0x548ca3
    goto L_0x00548ca3;
L_0x00548e96:
    // 00548e96  c60511b8540001         -mov byte ptr [0x54b811], 1
    *app->getMemory<x86::reg8>(x86::reg32(5552145) /* 0x54b811 */) = 1 /*0x1*/;
L_0x00548e9d:
    // 00548e9d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00548ea2  668974242a             -mov word ptr [esp + 0x2a], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.si;
    // 00548ea7  6689542428             -mov word ptr [esp + 0x28], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 00548eac  a164b85400             -mov eax, dword ptr [0x54b864]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */);
    // 00548eb1  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00548eb5  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 00548ebc  a164b85400             -mov eax, dword ptr [0x54b864]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */);
    // 00548ec1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00548ec3  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00548ec7  660fbe0513b85400       -movsx ax, byte ptr [0x54b813]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552147) /* 0x54b813 */)));
    // 00548ecf  6689442434             -mov word ptr [esp + 0x34], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 00548ed4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00548ed6  66897c2436             -mov word ptr [esp + 0x36], di
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.di;
    // 00548edb  66895c2438             -mov word ptr [esp + 0x38], bx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.bx;
    // 00548ee0  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548ee5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00548ee7  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00548eeb  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00548eec  8b1d04b85400           -mov ebx, dword ptr [0x54b804]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548ef2  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00548ef3  ff5238                 -call dword ptr [edx + 0x38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548ef6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548ef8  7417                   -je 0x548f11
    if (cpu.flags.zf)
    {
        goto L_0x00548f11;
    }
    // 00548efa  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548f01  0f84a5fdffff           -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00548f07  68c4b65400             -push 0x54b6c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5551812 /*0x54b6c4*/;
    cpu.esp -= 4;
    // 00548f0c  e992fdffff             -jmp 0x548ca3
    goto L_0x00548ca3;
L_0x00548f11:
    // 00548f11  c744241414000000       -mov dword ptr [esp + 0x14], 0x14
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 20 /*0x14*/;
    // 00548f19  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548f1e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00548f20  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00548f24  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00548f25  8b0d04b85400           -mov ecx, dword ptr [0x54b804]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00548f2b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00548f2c  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00548f2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00548f31  7417                   -je 0x548f4a
    if (cpu.flags.zf)
    {
        goto L_0x00548f4a;
    }
    // 00548f33  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548f3a  0f846cfdffff           -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00548f40  68fcb65400             -push 0x54b6fc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5551868 /*0x54b6fc*/;
    cpu.esp -= 4;
    // 00548f45  e959fdffff             -jmp 0x548ca3
    goto L_0x00548ca3;
L_0x00548f4a:
    // 00548f4a  837c244000             +cmp dword ptr [esp + 0x40], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548f4f  0f8429010000           -je 0x54907e
    if (cpu.flags.zf)
    {
        goto L_0x0054907e;
    }
    // 00548f55  f644241804             +test byte ptr [esp + 0x18], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) & 4 /*0x4*/));
    // 00548f5a  0f844cfdffff           -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00548f60  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00548f64  a33cb85400             -mov dword ptr [0x54b83c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */) = cpu.eax;
    // 00548f69  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 00548f70  a13cb85400             -mov eax, dword ptr [0x54b83c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */);
    // 00548f75  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00548f77  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 00548f79  0f852dfdffff           -jne 0x548cac
    if (!cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
L_0x00548f7f:
    // 00548f7f  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 00548f86  a13cb85400             -mov eax, dword ptr [0x54b83c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */);
    // 00548f8b  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00548f8d  a35cb85400             -mov dword ptr [0x54b85c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */) = cpu.eax;
    // 00548f92  8b155cb85400           -mov edx, dword ptr [0x54b85c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */);
    // 00548f98  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00548f9b  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00548fa0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00548fa2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00548fa5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00548fa7  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00548fac  a334b85400             -mov dword ptr [0x54b834], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552180) /* 0x54b834 */) = cpu.eax;
    // 00548fb1  a15cb85400             -mov eax, dword ptr [0x54b85c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */);
    // 00548fb6  a340b85400             -mov dword ptr [0x54b840], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552192) /* 0x54b840 */) = cpu.eax;
    // 00548fbb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00548fbd  a34cb85400             -mov dword ptr [0x54b84c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552204) /* 0x54b84c */) = cpu.eax;
    // 00548fc2  a350b85400             -mov dword ptr [0x54b850], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552208) /* 0x54b850 */) = cpu.eax;
    // 00548fc7  a348b85400             -mov dword ptr [0x54b848], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552200) /* 0x54b848 */) = cpu.eax;
    // 00548fcc  837c244000             +cmp dword ptr [esp + 0x40], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00548fd1  0f8400010000           -je 0x5490d7
    if (cpu.flags.zf)
    {
        goto L_0x005490d7;
    }
    // 00548fd7  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
L_0x00548fdc:
    // 00548fdc  a30cb85400             -mov dword ptr [0x54b80c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */) = cpu.eax;
    // 00548fe1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00548fe3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00548fe5  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00548fe7  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00548fec  6858b85400             -push 0x54b858
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552216 /*0x54b858*/;
    cpu.esp -= 4;
    // 00548ff1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00548ff3  6854b85400             -push 0x54b854
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552212 /*0x54b854*/;
    cpu.esp -= 4;
    // 00548ff8  8b1d3cb85400           -mov ebx, dword ptr [0x54b83c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */);
    // 00548ffe  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00548fff  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549001  8b350cb85400           -mov esi, dword ptr [0x54b80c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00549007  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00549008  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054900b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054900d  0f8599fcffff           -jne 0x548cac
    if (!cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00549013  8b1d3cb85400           -mov ebx, dword ptr [0x54b83c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */);
    // 00549019  a154b85400             -mov eax, dword ptr [0x54b854]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552212) /* 0x54b854 */);
    // 0054901e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00549020  e852070000             -call 0x549777
    cpu.esp -= 4;
    sub_549777(app, cpu);
    if (cpu.terminate) return;
    // 00549025  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 0054902a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054902c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0054902e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549030  8b3d3cb85400           -mov edi, dword ptr [0x54b83c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */);
    // 00549036  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00549037  8b1554b85400           -mov edx, dword ptr [0x54b854]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552212) /* 0x54b854 */);
    // 0054903d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054903e  8b0d0cb85400           -mov ecx, dword ptr [0x54b80c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00549044  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00549045  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00549048  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0054904a  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 0054904f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549051  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00549053  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549055  8b1d0cb85400           -mov ebx, dword ptr [0x54b80c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 0054905b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054905c  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054905f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00549061  0f8425010000           -je 0x54918c
    if (cpu.flags.zf)
    {
        goto L_0x0054918c;
    }
    // 00549067  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054906e  0f8438fcffff           -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00549074  686cb75400             -push 0x54b76c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5551980 /*0x54b76c*/;
    cpu.esp -= 4;
    // 00549079  e925fcffff             -jmp 0x548ca3
    goto L_0x00548ca3;
L_0x0054907e:
    // 0054907e  803d15b8540000         +cmp byte ptr [0x54b815], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552149) /* 0x54b815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00549085  7418                   -je 0x54909f
    if (cpu.flags.zf)
    {
        goto L_0x0054909f;
    }
    // 00549087  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 0054908e  b800a00000             -mov eax, 0xa000
    cpu.eax = 40960 /*0xa000*/;
    // 00549093  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00549095  a33cb85400             -mov dword ptr [0x54b83c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */) = cpu.eax;
    // 0054909a  e9e0feffff             -jmp 0x548f7f
    goto L_0x00548f7f;
L_0x0054909f:
    // 0054909f  8b1564b85400           -mov edx, dword ptr [0x54b864]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */);
    // 005490a5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 005490ac  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 005490ae  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 005490b1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 005490b3  b9e8030000             -mov ecx, 0x3e8
    cpu.ecx = 1000 /*0x3e8*/;
    // 005490b8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 005490bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005490bd  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 005490bf  25f0ff0f00             -and eax, 0xffff0
    cpu.eax &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005490c4  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 005490cb  d3e0                   +shl eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 005490cd  a33cb85400             -mov dword ptr [0x54b83c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */) = cpu.eax;
    // 005490d2  e9a8feffff             -jmp 0x548f7f
    goto L_0x00548f7f;
L_0x005490d7:
    // 005490d7  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 005490dc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005490de  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 005490e0  e892060000             -call 0x549777
    cpu.esp -= 4;
    sub_549777(app, cpu);
    if (cpu.terminate) return;
    // 005490e5  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 005490ea  ba08000100             -mov edx, 0x10008
    cpu.edx = 65544 /*0x10008*/;
    // 005490ef  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 005490f2  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005490f6  a13cb85400             -mov eax, dword ptr [0x54b83c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552188) /* 0x54b83c */);
    // 005490fb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00549100  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00549104  668974242a             -mov word ptr [esp + 0x2a], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(42) /* 0x2a */) = cpu.si;
    // 00549109  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0054910d  66894c2428             -mov word ptr [esp + 0x28], cx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 00549112  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00549116  a164b85400             -mov eax, dword ptr [0x54b864]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */);
    // 0054911b  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0054911f  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 00549126  a164b85400             -mov eax, dword ptr [0x54b864]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */);
    // 0054912b  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0054912d  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00549131  660fbe0513b85400       -movsx ax, byte ptr [0x54b813]
    cpu.ax = x86::reg16(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552147) /* 0x54b813 */)));
    // 00549139  6689442434             -mov word ptr [esp + 0x34], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ax;
    // 0054913e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00549140  66897c2436             -mov word ptr [esp + 0x36], di
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(54) /* 0x36 */) = cpu.di;
    // 00549145  6689742438             -mov word ptr [esp + 0x38], si
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.si;
    // 0054914a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054914c  a100b85400             -mov eax, dword ptr [0x54b800]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 00549151  6808b85400             -push 0x54b808
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552136 /*0x54b808*/;
    cpu.esp -= 4;
    // 00549156  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00549158  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0054915c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054915d  8b0d00b85400           -mov ecx, dword ptr [0x54b800]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 00549163  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00549164  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00549167  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00549169  7417                   -je 0x549182
    if (cpu.flags.zf)
    {
        goto L_0x00549182;
    }
    // 0054916b  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00549172  0f8434fbffff           -je 0x548cac
    if (cpu.flags.zf)
    {
        goto L_0x00548cac;
    }
    // 00549178  6834b75400             -push 0x54b734
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5551924 /*0x54b734*/;
    cpu.esp -= 4;
    // 0054917d  e921fbffff             -jmp 0x548ca3
    goto L_0x00548ca3;
L_0x00549182:
    // 00549182  a108b85400             -mov eax, dword ptr [0x54b808]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552136) /* 0x54b808 */);
    // 00549187  e950feffff             -jmp 0x548fdc
    goto L_0x00548fdc;
L_0x0054918c:
    // 0054918c  c60512b8540001         -mov byte ptr [0x54b812], 1
    *app->getMemory<x86::reg8>(x86::reg32(5552146) /* 0x54b812 */) = 1 /*0x1*/;
    // 00549193  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00549195  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00549198  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549199  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054919a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054919b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054919c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054919d:
    // 0054919d  a100b85400             -mov eax, dword ptr [0x54b800]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 005491a2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 005491a4  8b1500b85400           -mov edx, dword ptr [0x54b800]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 005491aa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005491ab  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005491ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005491b0  0f8449fbffff           -je 0x548cff
    if (cpu.flags.zf)
    {
        goto L_0x00548cff;
    }
    // 005491b6  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005491bd  740e                   -je 0x5491cd
    if (cpu.flags.zf)
    {
        goto L_0x005491cd;
    }
    // 005491bf  68d0b75400             -push 0x54b7d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552080 /*0x54b7d0*/;
    cpu.esp -= 4;
    // 005491c4  ff156cb85400           -call dword ptr [0x54b86c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005491ca  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005491cd:
    // 005491cd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005491d2  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 005491d5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005491d6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005491d7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005491d8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005491d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_5491dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005491dc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005491dd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005491de  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005491df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 005491e1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005491e3  803d12b8540000         +cmp byte ptr [0x54b812], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552146) /* 0x54b812 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005491ea  751f                   -jne 0x54920b
    if (!cpu.flags.zf)
    {
        goto L_0x0054920b;
    }
L_0x005491ec:
    // 005491ec  803d15b8540000         +cmp byte ptr [0x54b815], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552149) /* 0x54b815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005491f3  751d                   -jne 0x549212
    if (!cpu.flags.zf)
    {
        goto L_0x00549212;
    }
    // 005491f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 005491fa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 005491fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 005491fe  e869f9ffff             -call 0x548b6c
    cpu.esp -= 4;
    sub_548b6c(app, cpu);
    if (cpu.terminate) return;
    // 00549203  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00549205  750b                   -jne 0x549212
    if (!cpu.flags.zf)
    {
        goto L_0x00549212;
    }
    // 00549207  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549208  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549209  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054920a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054920b:
    // 0054920b  e814000000             -call 0x549224
    cpu.esp -= 4;
    sub_549224(app, cpu);
    if (cpu.terminate) return;
    // 00549210  ebda                   -jmp 0x5491ec
    goto L_0x005491ec;
L_0x00549212:
    // 00549212  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00549214  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00549216  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00549218  e84ff9ffff             -call 0x548b6c
    cpu.esp -= 4;
    sub_548b6c(app, cpu);
    if (cpu.terminate) return;
    // 0054921d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054921e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054921f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549220  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_549224(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00549224  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00549225  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00549226  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00549227  803d12b8540000         +cmp byte ptr [0x54b812], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552146) /* 0x54b812 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054922e  7534                   -jne 0x549264
    if (!cpu.flags.zf)
    {
        goto L_0x00549264;
    }
L_0x00549230:
    // 00549230  803d10b8540000         +cmp byte ptr [0x54b810], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552144) /* 0x54b810 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00549237  7425                   -je 0x54925e
    if (cpu.flags.zf)
    {
        goto L_0x0054925e;
    }
    // 00549239  833d00b8540000         +cmp dword ptr [0x54b800], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00549240  7558                   -jne 0x54929a
    if (!cpu.flags.zf)
    {
        goto L_0x0054929a;
    }
L_0x00549242:
    // 00549242  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00549243  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00549244  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00549246  893d00b85400           -mov dword ptr [0x54b800], edi
    *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */) = cpu.edi;
    // 0054924c  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0054924e  881d11b85400           -mov byte ptr [0x54b811], bl
    *app->getMemory<x86::reg8>(x86::reg32(5552145) /* 0x54b811 */) = cpu.bl;
    // 00549254  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00549256  883d10b85400           -mov byte ptr [0x54b810], bh
    *app->getMemory<x86::reg8>(x86::reg32(5552144) /* 0x54b810 */) = cpu.bh;
    // 0054925c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054925d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0054925e:
    // 0054925e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00549260  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549261  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549262  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549263  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00549264:
    // 00549264  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00549266  881512b85400           -mov byte ptr [0x54b812], dl
    *app->getMemory<x86::reg8>(x86::reg32(5552146) /* 0x54b812 */) = cpu.dl;
    // 0054926c  a104b85400             -mov eax, dword ptr [0x54b804]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00549271  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00549273  8b1504b85400           -mov edx, dword ptr [0x54b804]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552132) /* 0x54b804 */);
    // 00549279  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054927a  ff5048                 -call dword ptr [eax + 0x48]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054927d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0054927f  74af                   -je 0x549230
    if (cpu.flags.zf)
    {
        goto L_0x00549230;
    }
    // 00549281  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00549288  74a6                   -je 0x549230
    if (cpu.flags.zf)
    {
        goto L_0x00549230;
    }
    // 0054928a  68a0b75400             -push 0x54b7a0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552032 /*0x54b7a0*/;
    cpu.esp -= 4;
    // 0054928f  ff156cb85400           -call dword ptr [0x54b86c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00549295  83c404                 +add esp, 4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00549298  eb96                   -jmp 0x549230
    goto L_0x00549230;
L_0x0054929a:
    // 0054929a  a100b85400             -mov eax, dword ptr [0x54b800]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 0054929f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 005492a1  8b3500b85400           -mov esi, dword ptr [0x54b800]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552128) /* 0x54b800 */);
    // 005492a7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005492a8  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005492ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005492ad  7493                   -je 0x549242
    if (cpu.flags.zf)
    {
        goto L_0x00549242;
    }
    // 005492af  833d6cb8540000         +cmp dword ptr [0x54b86c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005492b6  740e                   -je 0x5492c6
    if (cpu.flags.zf)
    {
        goto L_0x005492c6;
    }
    // 005492b8  68d0b75400             -push 0x54b7d0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552080 /*0x54b7d0*/;
    cpu.esp -= 4;
    // 005492bd  ff156cb85400           -call dword ptr [0x54b86c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5552236) /* 0x54b86c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005492c3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x005492c6:
    // 005492c6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 005492cb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005492cc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005492cd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005492ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_5492d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005492d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005492d1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005492d2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005492d3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 005492d4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 005492d6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 005492d8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 005492da  7e43                   -jle 0x54931f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054931f;
    }
L_0x005492dc:
    // 005492dc  833d48b8540000         +cmp dword ptr [0x54b848], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552200) /* 0x54b848 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005492e3  7e3f                   -jle 0x549324
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00549324;
    }
L_0x005492e5:
    // 005492e5  a148b85400             -mov eax, dword ptr [0x54b848]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552200) /* 0x54b848 */);
    // 005492ea  39c6                   +cmp esi, eax
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005492ec  0f8e98000000           -jle 0x54938a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0054938a;
    }
    // 005492f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x005492f4:
    // 005492f4  8b1548b85400           -mov edx, dword ptr [0x54b848]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552200) /* 0x54b848 */);
    // 005492fa  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 005492fc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 005492fe  891548b85400           -mov dword ptr [0x54b848], edx
    *app->getMemory<x86::reg32>(x86::reg32(5552200) /* 0x54b848 */) = cpu.edx;
    // 00549304  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00549306  ff1568b85400           -call dword ptr [0x54b868]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5552232) /* 0x54b868 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054930c  8b0d11b85400           -mov ecx, dword ptr [0x54b811]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552145) /* 0x54b811 */);
    // 00549312  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00549315  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00549317  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00549319  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0054931b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0054931d  7fbd                   -jg 0x5492dc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x005492dc;
    }
L_0x0054931f:
    // 0054931f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549320  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549321  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549322  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549323  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00549324:
    // 00549324  ff054cb85400           -inc dword ptr [0x54b84c]
    (*app->getMemory<x86::reg32>(x86::reg32(5552204) /* 0x54b84c */))++;
    // 0054932a  ff1574b85400           -call dword ptr [0x54b874]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5552244) /* 0x54b874 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00549330  a14cb85400             -mov eax, dword ptr [0x54b84c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552204) /* 0x54b84c */);
    // 00549335  0faf0564b85400         -imul eax, dword ptr [0x54b864]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552228) /* 0x54b864 */))));
    // 0054933c  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00549341  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00549343  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00549345  8b0d50b85400           -mov ecx, dword ptr [0x54b850]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552208) /* 0x54b850 */);
    // 0054934b  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0054934d  a348b85400             -mov dword ptr [0x54b848], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552200) /* 0x54b848 */) = cpu.eax;
    // 00549352  25f0ffff0f             -and eax, 0xffffff0
    cpu.eax &= x86::reg32(x86::sreg32(268435440 /*0xffffff0*/));
    // 00549357  8d1401                 -lea edx, [ecx + eax]
    cpu.edx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 0054935a  a348b85400             -mov dword ptr [0x54b848], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552200) /* 0x54b848 */) = cpu.eax;
    // 0054935f  8b0d4cb85400           -mov ecx, dword ptr [0x54b84c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552204) /* 0x54b84c */);
    // 00549365  891550b85400           -mov dword ptr [0x54b850], edx
    *app->getMemory<x86::reg32>(x86::reg32(5552208) /* 0x54b850 */) = cpu.edx;
    // 0054936b  81f930750000           +cmp ecx, 0x7530
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30000 /*0x7530*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00549371  0f8e6effffff           -jle 0x5492e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005492e5;
    }
    // 00549377  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00549379  891d4cb85400           -mov dword ptr [0x54b84c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5552204) /* 0x54b84c */) = cpu.ebx;
    // 0054937f  891d50b85400           -mov dword ptr [0x54b850], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5552208) /* 0x54b850 */) = cpu.ebx;
    // 00549385  e95bffffff             -jmp 0x5492e5
    goto L_0x005492e5;
L_0x0054938a:
    // 0054938a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0054938c  e963ffffff             -jmp 0x5492f4
    goto L_0x005492f4;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_549394(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00549394  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00549395  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00549396  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00549397  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00549398  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00549399  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054939a  8b1518b85400           -mov edx, dword ptr [0x54b818]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */);
    // 005493a0  81fa00000011           +cmp edx, 0x11000000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(285212672 /*0x11000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005493a6  0f879f000000           -ja 0x54944b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0054944b;
    }
L_0x005493ac:
    // 005493ac  a118b85400             -mov eax, dword ptr [0x54b818]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */);
    // 005493b1  8b351cb85400           -mov esi, dword ptr [0x54b81c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552156) /* 0x54b81c */);
    // 005493b7  8b3d5cb85400           -mov edi, dword ptr [0x54b85c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */);
    // 005493bd  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 005493bf  39f8                   +cmp eax, edi
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
    // 005493c1  7c10                   -jl 0x5493d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005493d3;
    }
    // 005493c3  8b2d18b85400           -mov ebp, dword ptr [0x54b818]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */);
    // 005493c9  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005493cb  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 005493cd  892d18b85400           -mov dword ptr [0x54b818], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */) = cpu.ebp;
L_0x005493d3:
    // 005493d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005493d5  0f8cab000000           -jl 0x549486
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00549486;
    }
    // 005493db  8b1544b85400           -mov edx, dword ptr [0x54b844]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552196) /* 0x54b844 */);
    // 005493e1  42                     -inc edx
    (cpu.edx)++;
    // 005493e2  8b0d40b85400           -mov ecx, dword ptr [0x54b840]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552192) /* 0x54b840 */);
    // 005493e8  891544b85400           -mov dword ptr [0x54b844], edx
    *app->getMemory<x86::reg32>(x86::reg32(5552196) /* 0x54b844 */) = cpu.edx;
    // 005493ee  39c8                   +cmp eax, ecx
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005493f0  0f8c78000000           -jl 0x54946e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0054946e;
    }
L_0x005493f6:
    // 005493f6  8b1d44b85400           -mov ebx, dword ptr [0x54b844]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552196) /* 0x54b844 */);
    // 005493fc  81fbb80b0000           +cmp ebx, 0xbb8
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3000 /*0xbb8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00549402  7c40                   -jl 0x549444
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00549444;
    }
    // 00549404  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00549409  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0054940b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0054940d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00549410  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00549412  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00549414  752e                   -jne 0x549444
    if (!cpu.flags.zf)
    {
        goto L_0x00549444;
    }
    // 00549416  833d40b8540010         +cmp dword ptr [0x54b840], 0x10
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552192) /* 0x54b840 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054941d  7e56                   -jle 0x549475
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00549475;
    }
    // 0054941f  8b3d30b85400           -mov edi, dword ptr [0x54b830]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */);
    // 00549425  4f                     -dec edi
    (cpu.edi)--;
    // 00549426  a15cb85400             -mov eax, dword ptr [0x54b85c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */);
    // 0054942b  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 0054942d  893d30b85400           -mov dword ptr [0x54b830], edi
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.edi;
    // 00549433  81e5f0ff0f00           -and ebp, 0xffff0
    cpu.ebp &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00549439  a340b85400             -mov dword ptr [0x54b840], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552192) /* 0x54b840 */) = cpu.eax;
    // 0054943e  892d30b85400           -mov dword ptr [0x54b830], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.ebp;
L_0x00549444:
    // 00549444  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549445  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549446  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549447  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549448  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549449  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054944a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054944b:
    // 0054944b  8b1d1cb85400           -mov ebx, dword ptr [0x54b81c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552156) /* 0x54b81c */);
    // 00549451  8d8a000000f0           -lea ecx, [edx - 0x10000000]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-268435456) /* -0x10000000 */);
    // 00549457  81eb00000010           +sub ebx, 0x10000000
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0054945d  890d18b85400           -mov dword ptr [0x54b818], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */) = cpu.ecx;
    // 00549463  891d1cb85400           -mov dword ptr [0x54b81c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5552156) /* 0x54b81c */) = cpu.ebx;
    // 00549469  e93effffff             -jmp 0x5493ac
    goto L_0x005493ac;
L_0x0054946e:
    // 0054946e  a340b85400             -mov dword ptr [0x54b840], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552192) /* 0x54b840 */) = cpu.eax;
    // 00549473  eb81                   -jmp 0x5493f6
    goto L_0x005493f6;
L_0x00549475:
    // 00549475  a15cb85400             -mov eax, dword ptr [0x54b85c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */);
    // 0054947a  a340b85400             -mov dword ptr [0x54b840], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552192) /* 0x54b840 */) = cpu.eax;
    // 0054947f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549480  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549481  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549482  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549483  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549484  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549485  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00549486:
    // 00549486  833d18b8540000         +cmp dword ptr [0x54b818], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054948d  74b5                   -je 0x549444
    if (cpu.flags.zf)
    {
        goto L_0x00549444;
    }
    // 0054948f  8b1d30b85400           -mov ebx, dword ptr [0x54b830]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */);
    // 00549495  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00549497  891d30b85400           -mov dword ptr [0x54b830], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.ebx;
    // 0054949d  8d730f                 -lea esi, [ebx + 0xf]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 005494a0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 005494a2  893530b85400           -mov dword ptr [0x54b830], esi
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.esi;
    // 005494a8  81e7f0ff0f00           -and edi, 0xffff0
    cpu.edi &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005494ae  8b2d34b85400           -mov ebp, dword ptr [0x54b834]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5552180) /* 0x54b834 */);
    // 005494b4  893d30b85400           -mov dword ptr [0x54b830], edi
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.edi;
    // 005494ba  39ef                   +cmp edi, ebp
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
    // 005494bc  7e06                   -jle 0x5494c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x005494c4;
    }
    // 005494be  892d30b85400           -mov dword ptr [0x54b830], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */) = cpu.ebp;
L_0x005494c4:
    // 005494c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 005494c6  a344b85400             -mov dword ptr [0x54b844], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552196) /* 0x54b844 */) = cpu.eax;
    // 005494cb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494cc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494cd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494ce  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494cf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494d0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_5494d4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005494d4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 005494d5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005494d6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005494d7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005494d8  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 005494d9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005494dc  803d12b8540000         +cmp byte ptr [0x54b812], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552146) /* 0x54b812 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005494e3  7509                   -jne 0x5494ee
    if (!cpu.flags.zf)
    {
        goto L_0x005494ee;
    }
L_0x005494e5:
    // 005494e5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 005494e8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494e9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494ea  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494eb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494ec  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005494ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x005494ee:
    // 005494ee  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 005494f3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 005494f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 005494f7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005494f8  8b0d0cb85400           -mov ecx, dword ptr [0x54b80c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 005494fe  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005494ff  ff5224                 -call dword ptr [edx + 0x24]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00549502  f6042402               +test byte ptr [esp], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp) & 2 /*0x2*/));
    // 00549506  0f85e4000000           -jne 0x5495f0
    if (!cpu.flags.zf)
    {
        goto L_0x005495f0;
    }
    // 0054950c  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00549511  6820b85400             -push 0x54b820
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552160 /*0x54b820*/;
    cpu.esp -= 4;
    // 00549516  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00549518  6824b85400             -push 0x54b824
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552164 /*0x54b824*/;
    cpu.esp -= 4;
    // 0054951d  8b1d0cb85400           -mov ebx, dword ptr [0x54b80c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00549523  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00549524  ff5010                 -call dword ptr [eax + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00549527  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00549529  75ba                   -jne 0x5494e5
    if (!cpu.flags.zf)
    {
        goto L_0x005494e5;
    }
    // 0054952b  803d15b8540000         +cmp byte ptr [0x54b815], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552149) /* 0x54b815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00549532  740a                   -je 0x54953e
    if (cpu.flags.zf)
    {
        goto L_0x0054953e;
    }
    // 00549534  a120b85400             -mov eax, dword ptr [0x54b820]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552160) /* 0x54b820 */);
    // 00549539  a324b85400             -mov dword ptr [0x54b824], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */) = cpu.eax;
L_0x0054953e:
    // 0054953e  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 00549545  d32d24b85400           -shr dword ptr [0x54b824], cl
    *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */) >>= cpu.cl % 32;
    // 0054954b  812524b85400f0ff0f00   -and dword ptr [0x54b824], 0xffff0
    *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */) &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 00549555  a124b85400             -mov eax, dword ptr [0x54b824]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */);
    // 0054955a  3b0528b85400           +cmp eax, dword ptr [0x54b828]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552168) /* 0x54b828 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00549560  0f82a4000000           -jb 0x54960a
    if (cpu.flags.cf)
    {
        goto L_0x0054960a;
    }
    // 00549566  a124b85400             -mov eax, dword ptr [0x54b824]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */);
L_0x0054956b:
    // 0054956b  2b0528b85400           -sub eax, dword ptr [0x54b828]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552168) /* 0x54b828 */)));
    // 00549571  01051cb85400           -add dword ptr [0x54b81c], eax
    (*app->getMemory<x86::reg32>(x86::reg32(5552156) /* 0x54b81c */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 00549577  a124b85400             -mov eax, dword ptr [0x54b824]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */);
    // 0054957c  3b0528b85400           +cmp eax, dword ptr [0x54b828]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552168) /* 0x54b828 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00549582  0f8592000000           -jne 0x54961a
    if (!cpu.flags.zf)
    {
        goto L_0x0054961a;
    }
    // 00549588  8b157cb85400           -mov edx, dword ptr [0x54b87c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552252) /* 0x54b87c */);
    // 0054958e  42                     -inc edx
    (cpu.edx)++;
    // 0054958f  89157cb85400           -mov dword ptr [0x54b87c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5552252) /* 0x54b87c */) = cpu.edx;
    // 00549595  81faf4010000           +cmp edx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0054959b  0f8f85000000           -jg 0x549626
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00549626;
    }
L_0x005495a1:
    // 005495a1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x005495a2:
    // 005495a2  8b1d24b85400           -mov ebx, dword ptr [0x54b824]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */);
    // 005495a8  031d30b85400           -add ebx, dword ptr [0x54b830]
    (cpu.ebx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */)));
    // 005495ae  81e3f0ff0f00           -and ebx, 0xffff0
    cpu.ebx &= x86::reg32(x86::sreg32(1048560 /*0xffff0*/));
    // 005495b4  3b1d5cb85400           +cmp ebx, dword ptr [0x54b85c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005495ba  7c06                   -jl 0x5495c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x005495c2;
    }
    // 005495bc  2b1d5cb85400           -sub ebx, dword ptr [0x54b85c]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */)));
L_0x005495c2:
    // 005495c2  3b1d2cb85400           +cmp ebx, dword ptr [0x54b82c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552172) /* 0x54b82c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005495c8  0f8c78000000           -jl 0x549646
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00549646;
    }
    // 005495ce  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 005495d0  2b352cb85400           -sub esi, dword ptr [0x54b82c]
    (cpu.esi) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552172) /* 0x54b82c */)));
    // 005495d6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x005495d8:
    // 005495d8  a15cb85400             -mov eax, dword ptr [0x54b85c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */);
    // 005495dd  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 005495e0  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 005495e3  39c2                   +cmp edx, eax
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 005495e5  7c71                   -jl 0x549658
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00549658;
    }
    // 005495e7  830530b8540010         +add dword ptr [0x54b830], 0x10
    {
        x86::reg32& tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5552176) /* 0x54b830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 005495ee  ebb2                   -jmp 0x5495a2
    goto L_0x005495a2;
L_0x005495f0:
    // 005495f0  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 005495f5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 005495f7  8b350cb85400           -mov esi, dword ptr [0x54b80c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 005495fd  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005495fe  ff5050                 -call dword ptr [eax + 0x50]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00549601  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00549604  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549605  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549606  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549607  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549608  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549609  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0054960a:
    // 0054960a  a124b85400             -mov eax, dword ptr [0x54b824]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */);
    // 0054960f  03055cb85400           +add eax, dword ptr [0x54b85c]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00549615  e951ffffff             -jmp 0x54956b
    goto L_0x0054956b;
L_0x0054961a:
    // 0054961a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0054961c  a37cb85400             -mov dword ptr [0x54b87c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552252) /* 0x54b87c */) = cpu.eax;
    // 00549621  e97bffffff             -jmp 0x5495a1
    goto L_0x005495a1;
L_0x00549626:
    // 00549626  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00549628  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 0054962d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054962f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00549631  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549633  8b1d0cb85400           -mov ebx, dword ptr [0x54b80c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00549639  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0054963a  ff5030                 -call dword ptr [eax + 0x30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0054963d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00549640  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549641  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549642  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549643  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549644  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549645  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00549646:
    // 00549646  8b355cb85400           -mov esi, dword ptr [0x54b85c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552220) /* 0x54b85c */);
    // 0054964c  8b0d2cb85400           -mov ecx, dword ptr [0x54b82c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552172) /* 0x54b82c */);
    // 00549652  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00549654  29ce                   +sub esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00549656  eb80                   -jmp 0x5495d8
    goto L_0x005495d8;
L_0x00549658:
    // 00549658  803d15b8540000         +cmp byte ptr [0x54b815], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5552149) /* 0x54b815 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0054965f  7505                   -jne 0x549666
    if (!cpu.flags.zf)
    {
        goto L_0x00549666;
    }
    // 00549661  e82efdffff             -call 0x549394
    cpu.esp -= 4;
    sub_549394(app, cpu);
    if (cpu.terminate) return;
L_0x00549666:
    // 00549666  a124b85400             -mov eax, dword ptr [0x54b824]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552164) /* 0x54b824 */);
    // 0054966b  a328b85400             -mov dword ptr [0x54b828], eax
    *app->getMemory<x86::reg32>(x86::reg32(5552168) /* 0x54b828 */) = cpu.eax;
    // 00549670  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00549672  0f84ef000000           -je 0x549767
    if (cpu.flags.zf)
    {
        goto L_0x00549767;
    }
    // 00549678  013518b85400           -add dword ptr [0x54b818], esi
    (*app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */)) += x86::reg32(x86::sreg32(cpu.esi));
    // 0054967e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549680  8b150cb85400           -mov edx, dword ptr [0x54b80c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00549686  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549688  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0054968a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054968c  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 00549693  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00549695  6858b85400             -push 0x54b858
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552216 /*0x54b858*/;
    cpu.esp -= 4;
    // 0054969a  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0054969c  6854b85400             -push 0x54b854
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552212 /*0x54b854*/;
    cpu.esp -= 4;
    // 005496a1  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 005496a8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005496a9  a12cb85400             -mov eax, dword ptr [0x54b82c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552172) /* 0x54b82c */);
    // 005496ae  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 005496b0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005496b1  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 005496b6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 005496b7  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 005496ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 005496bc  7532                   -jne 0x5496f0
    if (!cpu.flags.zf)
    {
        goto L_0x005496f0;
    }
    // 005496be  a154b85400             -mov eax, dword ptr [0x54b854]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552212) /* 0x54b854 */);
    // 005496c3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 005496c5  e806fcffff             -call 0x5492d0
    cpu.esp -= 4;
    sub_5492d0(app, cpu);
    if (cpu.terminate) return;
    // 005496ca  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 005496cf  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 005496d1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005496d3  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 005496da  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005496dc  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 005496de  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 005496df  8b1554b85400           -mov edx, dword ptr [0x54b854]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552212) /* 0x54b854 */);
    // 005496e5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 005496e6  8b0d0cb85400           -mov ecx, dword ptr [0x54b80c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 005496ec  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005496ed  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x005496f0:
    // 005496f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 005496f2  7473                   -je 0x549767
    if (cpu.flags.zf)
    {
        goto L_0x00549767;
    }
    // 005496f4  8b3518b85400           -mov esi, dword ptr [0x54b818]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */);
    // 005496fa  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 005496fc  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 005496fe  893518b85400           -mov dword ptr [0x54b818], esi
    *app->getMemory<x86::reg32>(x86::reg32(5552152) /* 0x54b818 */) = cpu.esi;
    // 00549704  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549706  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 0054970b  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054970d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0054970f  6858b85400             -push 0x54b858
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552216 /*0x54b858*/;
    cpu.esp -= 4;
    // 00549714  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 0054971b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0054971d  6854b85400             -push 0x54b854
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5552212 /*0x54b854*/;
    cpu.esp -= 4;
    // 00549722  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00549724  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00549725  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549727  8b2d0cb85400           -mov ebp, dword ptr [0x54b80c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 0054972d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0054972e  ff502c                 -call dword ptr [eax + 0x2c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00549731  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00549733  750c                   -jne 0x549741
    if (!cpu.flags.zf)
    {
        goto L_0x00549741;
    }
    // 00549735  a154b85400             -mov eax, dword ptr [0x54b854]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552212) /* 0x54b854 */);
    // 0054973a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0054973c  e88ffbffff             -call 0x5492d0
    cpu.esp -= 4;
    sub_5492d0(app, cpu);
    if (cpu.terminate) return;
L_0x00549741:
    // 00549741  a10cb85400             -mov eax, dword ptr [0x54b80c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00549746  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00549748  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0054974a  0fbe0d14b85400         -movsx ecx, byte ptr [0x54b814]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(*app->getMemory<x86::reg8>(x86::reg32(5552148) /* 0x54b814 */)));
    // 00549751  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00549753  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 00549755  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00549756  8b1554b85400           -mov edx, dword ptr [0x54b854]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5552212) /* 0x54b854 */);
    // 0054975c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0054975d  8b0d0cb85400           -mov ecx, dword ptr [0x54b80c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5552140) /* 0x54b80c */);
    // 00549763  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00549764  ff504c                 -call dword ptr [eax + 0x4c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00549767:
    // 00549767  891d2cb85400           -mov dword ptr [0x54b82c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5552172) /* 0x54b82c */) = cpu.ebx;
    // 0054976d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054976e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00549771  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549772  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549773  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549774  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549775  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549776  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_549777(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00549777  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00549778  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0054977a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0054977b  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 0054977d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00549780  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00549782  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00549785  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00549787  e804000000             -call 0x549790
    cpu.esp -= 4;
    sub_549790(app, cpu);
    if (cpu.terminate) return;
    // 0054978c  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054978d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0054978e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_549790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00549790  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00549792  742c                   -je 0x5497c0
    if (cpu.flags.zf)
    {
        goto L_0x005497c0;
    }
    // 00549794  3810                   -cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x00549796:
    // 00549796  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 00549798  7409                   -je 0x5497a3
    if (cpu.flags.zf)
    {
        goto L_0x005497a3;
    }
    // 0054979a  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0054979c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0054979d  c1ca08                 +ror edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 count = 8 /*0x8*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 005497a0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497a1  75f3                   -jne 0x549796
    if (!cpu.flags.zf)
    {
        goto L_0x00549796;
    }
L_0x005497a3:
    // 005497a3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005497a4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 005497a7  e81b000000             -call 0x5497c7
    cpu.esp -= 4;
    sub_5497c7(app, cpu);
    if (cpu.terminate) return;
    // 005497ac  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 005497ad  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 005497b0  740e                   -je 0x5497c0
    if (cpu.flags.zf)
    {
        goto L_0x005497c0;
    }
    // 005497b2  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 005497b4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497b5  7409                   -je 0x5497c0
    if (cpu.flags.zf)
    {
        goto L_0x005497c0;
    }
    // 005497b7  887001                 -mov byte ptr [eax + 1], dh
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 005497ba  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497bb  7403                   -je 0x5497c0
    if (cpu.flags.zf)
    {
        goto L_0x005497c0;
    }
    // 005497bd  885002                 -mov byte ptr [eax + 2], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x005497c0:
    // 005497c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_5497c2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 005497c2  90                     -nop 
    ;
    // 005497c3  90                     -nop 
    ;
    // 005497c4  90                     -nop 
    ;
    // 005497c5  90                     -nop 
    ;
    // 005497c6  90                     -nop 
    ;
    // 005497c7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005497c9  7467                   -je 0x549832
    if (cpu.flags.zf)
    {
        goto L_0x00549832;
    }
L_0x005497cb:
    // 005497cb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 005497cd  7408                   -je 0x5497d7
    if (cpu.flags.zf)
    {
        goto L_0x005497d7;
    }
    // 005497cf  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005497d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005497d4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497d5  75f4                   -jne 0x5497cb
    if (!cpu.flags.zf)
    {
        goto L_0x005497cb;
    }
L_0x005497d7:
    // 005497d7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005497d8  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005497db  743a                   -je 0x549817
    if (cpu.flags.zf)
    {
        goto L_0x00549817;
    }
    // 005497dd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497de  7429                   -je 0x549809
    if (cpu.flags.zf)
    {
        goto L_0x00549809;
    }
L_0x005497e0:
    // 005497e0  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005497e2  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005497e5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497e6  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005497e9  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005497ec  7418                   -je 0x549806
    if (cpu.flags.zf)
    {
        goto L_0x00549806;
    }
    // 005497ee  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005497f1  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 005497f4  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005497f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497f8  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005497fb  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005497fe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00549801  75dd                   -jne 0x5497e0
    if (!cpu.flags.zf)
    {
        goto L_0x005497e0;
    }
    // 00549803  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00549806:
    // 00549806  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00549809:
    // 00549809  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054980b  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0054980e  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00549811  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00549814  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00549817:
    // 00549817  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549818  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0054981b  7415                   -je 0x549832
    if (cpu.flags.zf)
    {
        goto L_0x00549832;
    }
    // 0054981d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054981f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00549822  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00549823  740d                   -je 0x549832
    if (cpu.flags.zf)
    {
        goto L_0x00549832;
    }
    // 00549825  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00549827  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0054982a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054982b  7405                   -je 0x549832
    if (cpu.flags.zf)
    {
        goto L_0x00549832;
    }
    // 0054982d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054982f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00549832:
    // 00549832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_5497c7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x005497c7;
    // 005497c2  90                     -nop 
    ;
    // 005497c3  90                     -nop 
    ;
    // 005497c4  90                     -nop 
    ;
    // 005497c5  90                     -nop 
    ;
    // 005497c6  90                     -nop 
    ;
L_entry_0x005497c7:
    // 005497c7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 005497c9  7467                   -je 0x549832
    if (cpu.flags.zf)
    {
        goto L_0x00549832;
    }
L_0x005497cb:
    // 005497cb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 005497cd  7408                   -je 0x5497d7
    if (cpu.flags.zf)
    {
        goto L_0x005497d7;
    }
    // 005497cf  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005497d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 005497d4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497d5  75f4                   -jne 0x5497cb
    if (!cpu.flags.zf)
    {
        goto L_0x005497cb;
    }
L_0x005497d7:
    // 005497d7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 005497d8  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 005497db  743a                   -je 0x549817
    if (cpu.flags.zf)
    {
        goto L_0x00549817;
    }
    // 005497dd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497de  7429                   -je 0x549809
    if (cpu.flags.zf)
    {
        goto L_0x00549809;
    }
L_0x005497e0:
    // 005497e0  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 005497e2  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 005497e5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497e6  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 005497e9  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 005497ec  7418                   -je 0x549806
    if (cpu.flags.zf)
    {
        goto L_0x00549806;
    }
    // 005497ee  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 005497f1  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 005497f4  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 005497f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 005497f8  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 005497fb  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 005497fe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00549801  75dd                   -jne 0x5497e0
    if (!cpu.flags.zf)
    {
        goto L_0x005497e0;
    }
    // 00549803  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00549806:
    // 00549806  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00549809:
    // 00549809  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054980b  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0054980e  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00549811  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00549814  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00549817:
    // 00549817  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00549818  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 0054981b  7415                   -je 0x549832
    if (cpu.flags.zf)
    {
        goto L_0x00549832;
    }
    // 0054981d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054981f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00549822  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00549823  740d                   -je 0x549832
    if (cpu.flags.zf)
    {
        goto L_0x00549832;
    }
    // 00549825  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00549827  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0054982a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0054982b  7405                   -je 0x549832
    if (cpu.flags.zf)
    {
        goto L_0x00549832;
    }
    // 0054982d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0054982f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00549832:
    // 00549832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_549834(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00549834  ff2530a65400           -jmp dword ptr [0x54a630]
    return app->dynamic_call(*app->getMemory<x86::reg32>(5547568), cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_549840(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00549840  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549842  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549844  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549846  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549848  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054984a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054984c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054984e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549850  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549852  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549854  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549856  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549858  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054985a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054985c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054985e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549860  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549862  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549864  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549866  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549868  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054986a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054986c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054986e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549870  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549872  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549874  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549876  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549878  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054987a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054987c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054987e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549880  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549882  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549884  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549886  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549888  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054988a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054988c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054988e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549890  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549892  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549894  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549896  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549898  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054989a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054989c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054989e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498a0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498a2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498a4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498a6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498a8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498aa  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498ac  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498ae  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498b0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498b2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498b4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498b6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498b8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498ba  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498bc  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498be  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498c0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498c2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498c4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498c6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498c8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498ca  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498cc  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498ce  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498d0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498d2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498d4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498d6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498d8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498da  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498dc  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498de  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498e0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498e2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498e4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498e6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498e8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498ea  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498ec  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498ee  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498f0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498f2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498f4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498f6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498f8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498fa  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498fc  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005498fe  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549900  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549902  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549904  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549906  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549908  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054990a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054990c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054990e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549910  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549912  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549914  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549916  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549918  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054991a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054991c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054991e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549920  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549922  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549924  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549926  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549928  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054992a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054992c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054992e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549930  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549932  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549934  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549936  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549938  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054993a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054993c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054993e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549940  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549942  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549944  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549946  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549948  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054994a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054994c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054994e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549950  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549952  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549954  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549956  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549958  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054995a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054995c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054995e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549960  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549962  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549964  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549966  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549968  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054996a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054996c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054996e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549970  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549972  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549974  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549976  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549978  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054997a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054997c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054997e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549980  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549982  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549984  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549986  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549988  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054998a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054998c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054998e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549990  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549992  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549994  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549996  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 00549998  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054999a  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054999c  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0054999e  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499a0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499a2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499a4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499a6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499a8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499aa  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499ac  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499ae  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499b0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499b2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499b4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499b6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499b8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499ba  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499bc  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499be  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499c0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499c2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499c4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499c6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499c8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499ca  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499cc  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499ce  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499d0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499d2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499d4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499d6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499d8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499da  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499dc  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499de  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499e0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499e2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499e4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499e6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499e8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499ea  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499ec  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499ee  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499f0  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499f2  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499f4  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499f6  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499f8  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499fa  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499fc  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 005499fe  0000                   -add byte ptr [eax], al
    (*app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
}

}
