#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x90 */
void Application::sub_493098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493098  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493099  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049309a  8b1564ab4c00           -mov edx, dword ptr [0x4cab64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */);
    // 004930a0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004930a2  750b                   -jne 0x4930af
    if (!cpu.flags.zf)
    {
        goto L_0x004930af;
    }
    // 004930a4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004930a6  890d64ab4c00           -mov dword ptr [0x4cab64], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */) = cpu.ecx;
    // 004930ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004930ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004930ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004930af:
    // 004930af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004930b1  e8165afeff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 004930b6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004930b8  890d64ab4c00           -mov dword ptr [0x4cab64], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */) = cpu.ecx;
    // 004930be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004930bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004930c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4930c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004930c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004930c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004930c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004930c7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004930ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004930cc  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004930cf  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004930d3  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004930d5  a164ab4c00             -mov eax, dword ptr [0x4cab64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */);
    // 004930da  8b15a8835200           -mov edx, dword ptr [0x5283a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407656) /* 0x5283a8 */);
    // 004930e0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004930e2  39d0                   +cmp eax, edx
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
    // 004930e4  7335                   -jae 0x49311b
    if (!cpu.flags.cf)
    {
        goto L_0x0049311b;
    }
    // 004930e6  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004930ea  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004930ed  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004930ef  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004930f1:
    // 004930f1  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004930f3  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004930f5  7c14                   -jl 0x49310b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049310b;
    }
    // 004930f7  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004930fb  0f8674000000           -jbe 0x493175
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00493175;
    }
    // 00493101  3b7008                 +cmp esi, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493104  7505                   -jne 0x49310b
    if (!cpu.flags.zf)
    {
        goto L_0x0049310b;
    }
    // 00493106  3b500c                 +cmp edx, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493109  745e                   -je 0x493169
    if (cpu.flags.zf)
    {
        goto L_0x00493169;
    }
L_0x0049310b:
    // 0049310b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0049310e  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00493111  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493113  3b05a8835200           +cmp eax, dword ptr [0x5283a8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5407656) /* 0x5283a8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493119  72d6                   -jb 0x4930f1
    if (cpu.flags.cf)
    {
        goto L_0x004930f1;
    }
L_0x0049311b:
    // 0049311b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049311d  0f846f000000           -je 0x493192
    if (cpu.flags.zf)
    {
        goto L_0x00493192;
    }
    // 00493123  8d5708                 -lea edx, [edi + 8]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00493126  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00493128  39d0                   +cmp eax, edx
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
    // 0049312a  7d51                   -jge 0x49317d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049317d;
    }
    // 0049312c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0049312e:
    // 0049312e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493131  897bfc                 -mov dword ptr [ebx - 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00493134  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493136  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 0049313c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049313f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00493141  7e1d                   -jle 0x493160
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493160;
    }
    // 00493143  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00493145:
    // 00493145  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493149  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0049314b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049314e  40                     -inc eax
    (cpu.eax)++;
    // 0049314f  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 00493151  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00493154  896afc                 -mov dword ptr [edx - 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00493157  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493159  39f8                   +cmp eax, edi
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
    // 0049315b  7ce8                   -jl 0x493145
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493145;
    }
    // 0049315d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00493160:
    // 00493160  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00493162:
    // 00493162  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00493165  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493166  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493167  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493168  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493169:
    // 00493169  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049316c  83c008                 +add eax, 8
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049316f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00493170  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00493173  ebed                   -jmp 0x493162
    goto L_0x00493162;
L_0x00493175:
    // 00493175  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00493177  7592                   -jne 0x49310b
    if (!cpu.flags.zf)
    {
        goto L_0x0049310b;
    }
    // 00493179  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049317b  eb8e                   -jmp 0x49310b
    goto L_0x0049310b;
L_0x0049317d:
    // 0049317d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049317f  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00493181  c744bb0c00000000       -mov dword ptr [ebx + edi*4 + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.edi * 4) = 0 /*0x0*/;
    // 00493189  83ea02                 +sub edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049318c  8954bb08               -mov dword ptr [ebx + edi*4 + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */ + cpu.edi * 4) = cpu.edx;
    // 00493190  eb9c                   -jmp 0x49312e
    goto L_0x0049312e;
L_0x00493192:
    // 00493192  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493194  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00493197  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493198  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493199  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049319a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49319c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049319c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049319d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049319e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049319f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004931a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004931a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004931a3  8d48f8                 -lea ecx, [eax - 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004931a6  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004931a9  4a                     -dec edx
    (cpu.edx)--;
    // 004931aa  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004931ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004931af  7606                   -jbe 0x4931b7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004931b7;
    }
L_0x004931b1:
    // 004931b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004931b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004931b7:
    // 004931b7  a164ab4c00             -mov eax, dword ptr [0x4cab64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */);
    // 004931bc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004931be  39c8                   +cmp eax, ecx
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
    // 004931c0  7312                   -jae 0x4931d4
    if (!cpu.flags.cf)
    {
        goto L_0x004931d4;
    }
L_0x004931c2:
    // 004931c2  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004931c4  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004931c7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004931ca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004931cc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004931ce  39c8                   +cmp eax, ecx
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
    // 004931d0  72f0                   -jb 0x4931c2
    if (cpu.flags.cf)
    {
        goto L_0x004931c2;
    }
    // 004931d2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004931d4:
    // 004931d4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004931d6  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004931d9  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004931dc  8b35a8835200           -mov esi, dword ptr [0x5283a8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407656) /* 0x5283a8 */);
    // 004931e2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004931e4  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004931e6  7306                   -jae 0x4931ee
    if (!cpu.flags.cf)
    {
        goto L_0x004931ee;
    }
    // 004931e8  837a0400               +cmp dword ptr [edx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004931ec  761b                   -jbe 0x493209
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00493209;
    }
L_0x004931ee:
    // 004931ee  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004931f0  74bf                   -je 0x4931b1
    if (cpu.flags.zf)
    {
        goto L_0x004931b1;
    }
    // 004931f2  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004931f6  77b9                   -ja 0x4931b1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004931b1;
    }
    // 004931f8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004931fa  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004931fc  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004931ff  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493201  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 00493203  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493204  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493205  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493206  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493207  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493208  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493209:
    // 00493209  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049320b  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0049320d  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00493210  01d5                   +add ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493212  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 00493214  ebd8                   -jmp 0x4931ee
    goto L_0x004931ee;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493218  a364ab4c00             -mov dword ptr [0x4cab64], eax
    app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */) = cpu.eax;
    // 0049321d  891560ab4c00           -mov dword ptr [0x4cab60], edx
    app->getMemory<x86::reg32>(x86::reg32(5024608) /* 0x4cab60 */) = cpu.edx;
    // 00493223  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493224  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00493225  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493226  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 0049322b  0f8599000000           -jne 0x4932ca
    if (!cpu.flags.zf)
    {
        goto L_0x004932ca;
    }
L_0x00493231:
    // 00493231  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493234  7839                   -js 0x49326f
    if (cpu.flags.sf)
    {
        goto L_0x0049326f;
    }
L_0x00493236:
    // 00493236  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00493238  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049323a  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049323d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00493240  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00493243  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00493246  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493249  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049324c  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049324f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493252  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00493255  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493258  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049325b  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049325e  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00493261  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493264  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00493267  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049326a  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049326d  79c7                   -jns 0x493236
    if (!cpu.flags.sf)
    {
        goto L_0x00493236;
    }
L_0x0049326f:
    // 0049326f  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493272  7815                   -js 0x493289
    if (cpu.flags.sf)
    {
        goto L_0x00493289;
    }
L_0x00493274:
    // 00493274  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00493276  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00493278  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049327b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049327e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00493281  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00493284  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493287  79eb                   -jns 0x493274
    if (!cpu.flags.sf)
    {
        goto L_0x00493274;
    }
L_0x00493289:
    // 00493289  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049328c  7502                   -jne 0x493290
    if (!cpu.flags.zf)
    {
        goto L_0x00493290;
    }
    // 0049328e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049328f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493290:
    // 00493290  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493293  720d                   -jb 0x4932a2
    if (cpu.flags.cf)
    {
        goto L_0x004932a2;
    }
    // 00493295  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00493297  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049329a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049329c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049329f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004932a2:
    // 004932a2  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004932a5  720f                   -jb 0x4932b6
    if (cpu.flags.cf)
    {
        goto L_0x004932b6;
    }
    // 004932a7  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004932aa  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004932ad  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004932b0  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004932b3  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004932b6:
    // 004932b6  83fb01                 +cmp ebx, 1
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
    // 004932b9  720d                   -jb 0x4932c8
    if (cpu.flags.cf)
    {
        goto L_0x004932c8;
    }
    // 004932bb  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004932bd  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004932c0  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004932c2  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004932c5  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004932c8:
    // 004932c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004932c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004932ca:
    // 004932ca  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004932cf  7412                   -je 0x4932e3
    if (cpu.flags.zf)
    {
        goto L_0x004932e3;
    }
    // 004932d1  83fb01                 +cmp ebx, 1
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
    // 004932d4  7c0d                   -jl 0x4932e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004932e3;
    }
    // 004932d6  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004932d8  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004932db  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004932dd  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004932e0  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004932e3:
    // 004932e3  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004932e8  7414                   -je 0x4932fe
    if (cpu.flags.zf)
    {
        goto L_0x004932fe;
    }
    // 004932ea  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004932ed  7c0f                   -jl 0x4932fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004932fe;
    }
    // 004932ef  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004932f2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004932f5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004932f8  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004932fb  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004932fe:
    // 004932fe  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00493303  7412                   -je 0x493317
    if (cpu.flags.zf)
    {
        goto L_0x00493317;
    }
    // 00493305  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493308  7c0d                   -jl 0x493317
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493317;
    }
    // 0049330a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049330c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049330f  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00493311  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493314  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00493317:
    // 00493317  e915ffffff             -jmp 0x493231
    goto L_0x00493231;
}

/* align: skip  */
void Application::sub_493225(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00493225;
    // 00493224  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x00493225:
    // 00493225  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493226  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 0049322b  0f8599000000           -jne 0x4932ca
    if (!cpu.flags.zf)
    {
        goto L_0x004932ca;
    }
L_0x00493231:
    // 00493231  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493234  7839                   -js 0x49326f
    if (cpu.flags.sf)
    {
        goto L_0x0049326f;
    }
L_0x00493236:
    // 00493236  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00493238  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049323a  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049323d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00493240  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00493243  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00493246  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00493249  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049324c  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0049324f  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00493252  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00493255  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00493258  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0049325b  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0049325e  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00493261  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00493264  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00493267  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0049326a  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049326d  79c7                   -jns 0x493236
    if (!cpu.flags.sf)
    {
        goto L_0x00493236;
    }
L_0x0049326f:
    // 0049326f  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493272  7815                   -js 0x493289
    if (cpu.flags.sf)
    {
        goto L_0x00493289;
    }
L_0x00493274:
    // 00493274  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00493276  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00493278  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049327b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049327e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00493281  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00493284  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493287  79eb                   -jns 0x493274
    if (!cpu.flags.sf)
    {
        goto L_0x00493274;
    }
L_0x00493289:
    // 00493289  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049328c  7502                   -jne 0x493290
    if (!cpu.flags.zf)
    {
        goto L_0x00493290;
    }
    // 0049328e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049328f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493290:
    // 00493290  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493293  720d                   -jb 0x4932a2
    if (cpu.flags.cf)
    {
        goto L_0x004932a2;
    }
    // 00493295  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00493297  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049329a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049329c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049329f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004932a2:
    // 004932a2  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004932a5  720f                   -jb 0x4932b6
    if (cpu.flags.cf)
    {
        goto L_0x004932b6;
    }
    // 004932a7  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004932aa  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004932ad  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004932b0  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004932b3  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004932b6:
    // 004932b6  83fb01                 +cmp ebx, 1
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
    // 004932b9  720d                   -jb 0x4932c8
    if (cpu.flags.cf)
    {
        goto L_0x004932c8;
    }
    // 004932bb  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004932bd  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004932c0  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004932c2  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004932c5  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004932c8:
    // 004932c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004932c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004932ca:
    // 004932ca  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004932cf  7412                   -je 0x4932e3
    if (cpu.flags.zf)
    {
        goto L_0x004932e3;
    }
    // 004932d1  83fb01                 +cmp ebx, 1
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
    // 004932d4  7c0d                   -jl 0x4932e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004932e3;
    }
    // 004932d6  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004932d8  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004932db  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004932dd  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004932e0  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004932e3:
    // 004932e3  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004932e8  7414                   -je 0x4932fe
    if (cpu.flags.zf)
    {
        goto L_0x004932fe;
    }
    // 004932ea  83fb02                 +cmp ebx, 2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004932ed  7c0f                   -jl 0x4932fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004932fe;
    }
    // 004932ef  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004932f2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004932f5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004932f8  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004932fb  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004932fe:
    // 004932fe  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00493303  7412                   -je 0x493317
    if (cpu.flags.zf)
    {
        goto L_0x00493317;
    }
    // 00493305  83fb04                 +cmp ebx, 4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493308  7c0d                   -jl 0x493317
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493317;
    }
    // 0049330a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049330c  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049330f  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00493311  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00493314  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00493317:
    // 00493317  e915ffffff             -jmp 0x493231
    goto L_0x00493231;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_493320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493321  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493322  2eff15f4544b00         -call dword ptr cs:[0x4b54f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936948) /* 0x4b54f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493329  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049332a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049332b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49332c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049332c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049332d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049332e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049332f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493330  e897bbfeff             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 00493335  8b15e4835200           -mov edx, dword ptr [0x5283e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 0049333b  a368ab4c00             -mov dword ptr [0x4cab68], eax
    app->getMemory<x86::reg32>(x86::reg32(5024616) /* 0x4cab68 */) = cpu.eax;
    // 00493340  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493342  7453                   -je 0x493397
    if (cpu.flags.zf)
    {
        goto L_0x00493397;
    }
L_0x00493344:
    // 00493344  a168ab4c00             -mov eax, dword ptr [0x4cab68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024616) /* 0x4cab68 */);
    // 00493349  e8cebbfeff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 0049334e  8b1de4835200           -mov ebx, dword ptr [0x5283e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 00493354  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00493356  7436                   -je 0x49338e
    if (cpu.flags.zf)
    {
        goto L_0x0049338e;
    }
    // 00493358  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049335a  e8a9bcfeff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049335f  8b35b0835200           -mov esi, dword ptr [0x5283b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5407664) /* 0x5283b0 */);
    // 00493365  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00493367  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00493369  7419                   -je 0x493384
    if (cpu.flags.zf)
    {
        goto L_0x00493384;
    }
L_0x0049336b:
    // 0049336b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049336d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493370  ff90b0835200           -call dword ptr [eax + 0x5283b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407664) /* 0x5283b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493376  83fa20                 +cmp edx, 0x20
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
    // 00493379  7d09                   -jge 0x493384
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493384;
    }
    // 0049337b  83bab083520000         +cmp dword ptr [edx + 0x5283b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5407664) /* 0x5283b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493382  75e7                   -jne 0x49336b
    if (!cpu.flags.zf)
    {
        goto L_0x0049336b;
    }
L_0x00493384:
    // 00493384  a1e4835200             -mov eax, dword ptr [0x5283e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 00493389  e892bcfeff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x0049338e:
    // 0049338e  833de483520000         +cmp dword ptr [0x5283e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493395  75ad                   -jne 0x493344
    if (!cpu.flags.zf)
    {
        goto L_0x00493344;
    }
L_0x00493397:
    // 00493397  a168ab4c00             -mov eax, dword ptr [0x4cab68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024616) /* 0x4cab68 */);
    // 0049339c  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049339e  e805bcfeff             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 004933a3  892d68ab4c00           -mov dword ptr [0x4cab68], ebp
    app->getMemory<x86::reg32>(x86::reg32(5024616) /* 0x4cab68 */) = cpu.ebp;
    // 004933a9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004933aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004933ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004933ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004933ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4933b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004933b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004933b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004933b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004933b3  8b15e4835200           -mov edx, dword ptr [0x5283e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 004933b9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004933bb  7504                   -jne 0x4933c1
    if (!cpu.flags.zf)
    {
        goto L_0x004933c1;
    }
L_0x004933bd:
    // 004933bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004933be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004933bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004933c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004933c1:
    // 004933c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004933c3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004933c5  e83ebcfeff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004933ca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004933cc  b8d0835200             -mov eax, 0x5283d0
    cpu.eax = 5407696 /*0x5283d0*/;
    // 004933d1  8b1568ab4c00           -mov edx, dword ptr [0x4cab68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024616) /* 0x4cab68 */);
    // 004933d7  891de4835200           -mov dword ptr [0x5283e4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */) = cpu.ebx;
    // 004933dd  e8febafeff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 004933e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004933e4  e837bcfeff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004933e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004933eb  e844bcfeff             -call 0x47f034
    cpu.esp -= 4;
    sub_47f034(app, cpu);
    if (cpu.terminate) return;
    // 004933f0  b8d0835200             -mov eax, 0x5283d0
    cpu.eax = 5407696 /*0x5283d0*/;
    // 004933f5  e8aeb8feff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 004933fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004933fc  75bf                   -jne 0x4933bd
    if (!cpu.flags.zf)
    {
        goto L_0x004933bd;
    }
    // 004933fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00493400:
    // 00493400  3b1568ab4c00           +cmp edx, dword ptr [0x4cab68]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024616) /* 0x4cab68 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493406  74b5                   -je 0x4933bd
    if (cpu.flags.zf)
    {
        goto L_0x004933bd;
    }
    // 00493408  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049340a  e84db8feff             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 0049340f  ebef                   -jmp 0x493400
    goto L_0x00493400;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493414(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493414  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493415  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493416  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493417  b8b0334900             -mov eax, 0x4933b0
    cpu.eax = 4797360 /*0x4933b0*/;
    // 0049341c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00493421  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00493426  e8f181ffff             -call 0x48b61c
    cpu.esp -= 4;
    sub_48b61c(app, cpu);
    if (cpu.terminate) return;
    // 0049342b  e888bbfeff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00493430  a3e4835200             -mov dword ptr [0x5283e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */) = cpu.eax;
    // 00493435  e8cebbfeff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049343a  68d0835200             -push 0x5283d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5407696 /*0x5283d0*/;
    cpu.esp -= 4;
    // 0049343f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00493441  b82c334900             -mov eax, 0x49332c
    cpu.eax = 4797228 /*0x49332c*/;
    // 00493446  e855b7feff             -call 0x47eba0
    cpu.esp -= 4;
    sub_47eba0(app, cpu);
    if (cpu.terminate) return;
    // 0049344b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049344d  7516                   -jne 0x493465
    if (!cpu.flags.zf)
    {
        goto L_0x00493465;
    }
    // 0049344f  a1e4835200             -mov eax, dword ptr [0x5283e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 00493454  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00493456  e8d9bbfeff             -call 0x47f034
    cpu.esp -= 4;
    sub_47f034(app, cpu);
    if (cpu.terminate) return;
    // 0049345b  8915e4835200           -mov dword ptr [0x5283e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */) = cpu.edx;
    // 00493461  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493462  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493463  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493464  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493465:
    // 00493465  a1e4835200             -mov eax, dword ptr [0x5283e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 0049346a  e8b1bbfeff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0049346f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493470  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493471  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493472  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493474(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493474  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493475  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493476  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493477  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00493479  8b15e4835200           -mov edx, dword ptr [0x5283e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 0049347f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00493484  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493486  7446                   -je 0x4934ce
    if (cpu.flags.zf)
    {
        goto L_0x004934ce;
    }
L_0x00493488:
    // 00493488  a1e4835200             -mov eax, dword ptr [0x5283e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 0049348d  e876bbfeff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00493492  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00493494  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00493496:
    // 00493496  83bab083520000         +cmp dword ptr [edx + 0x5283b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5407664) /* 0x5283b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049349d  7504                   -jne 0x4934a3
    if (!cpu.flags.zf)
    {
        goto L_0x004934a3;
    }
    // 0049349f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004934a1  7c32                   -jl 0x4934d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004934d5;
    }
L_0x004934a3:
    // 004934a3  3b9ab0835200           +cmp ebx, dword ptr [edx + 0x5283b0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5407664) /* 0x5283b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004934a9  7415                   -je 0x4934c0
    if (cpu.flags.zf)
    {
        goto L_0x004934c0;
    }
L_0x004934ab:
    // 004934ab  40                     -inc eax
    (cpu.eax)++;
    // 004934ac  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004934af  83f808                 +cmp eax, 8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004934b2  7ce2                   -jl 0x493496
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493496;
    }
    // 004934b4  83f9ff                 +cmp ecx, -1
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
    // 004934b7  7407                   -je 0x4934c0
    if (cpu.flags.zf)
    {
        goto L_0x004934c0;
    }
    // 004934b9  891c8db0835200         -mov dword ptr [ecx*4 + 0x5283b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407664) /* 0x5283b0 */ + cpu.ecx * 4) = cpu.ebx;
L_0x004934c0:
    // 004934c0  a1e4835200             -mov eax, dword ptr [0x5283e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 004934c5  e856bbfeff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004934ca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004934ce:
    // 004934ce  e841ffffff             -call 0x493414
    cpu.esp -= 4;
    sub_493414(app, cpu);
    if (cpu.terminate) return;
    // 004934d3  ebb3                   -jmp 0x493488
    goto L_0x00493488;
L_0x004934d5:
    // 004934d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004934d7  ebd2                   -jmp 0x4934ab
    goto L_0x004934ab;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4934dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004934dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004934dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004934de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004934df  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004934e0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004934e2  8b15e4835200           -mov edx, dword ptr [0x5283e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 004934e8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004934ea  7505                   -jne 0x4934f1
    if (!cpu.flags.zf)
    {
        goto L_0x004934f1;
    }
L_0x004934ec:
    // 004934ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004934f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004934f1:
    // 004934f1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004934f3  e810bbfeff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004934f8  8b1db0835200           -mov ebx, dword ptr [0x5283b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407664) /* 0x5283b0 */);
    // 004934fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00493500  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493502  39d9                   +cmp ecx, ebx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493504  7411                   -je 0x493517
    if (cpu.flags.zf)
    {
        goto L_0x00493517;
    }
L_0x00493506:
    // 00493506  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493509  42                     -inc edx
    (cpu.edx)++;
    // 0049350a  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049350d  7d08                   -jge 0x493517
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493517;
    }
    // 0049350f  3b88b0835200           +cmp ecx, dword ptr [eax + 0x5283b0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407664) /* 0x5283b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493515  75ef                   -jne 0x493506
    if (!cpu.flags.zf)
    {
        goto L_0x00493506;
    }
L_0x00493517:
    // 00493517  83fa08                 +cmp edx, 8
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
    // 0049351a  7d30                   -jge 0x49354c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049354c;
    }
    // 0049351c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00493523  3b88b0835200           +cmp ecx, dword ptr [eax + 0x5283b0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407664) /* 0x5283b0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493529  7521                   -jne 0x49354c
    if (!cpu.flags.zf)
    {
        goto L_0x0049354c;
    }
    // 0049352b  83fa07                 +cmp edx, 7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049352e  7d14                   -jge 0x493544
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493544;
    }
L_0x00493530:
    // 00493530  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493533  8b90b0835200           -mov edx, dword ptr [eax + 0x5283b0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407664) /* 0x5283b0 */);
    // 00493539  8990ac835200           -mov dword ptr [eax + 0x5283ac], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407660) /* 0x5283ac */) = cpu.edx;
    // 0049353f  83f81c                 +cmp eax, 0x1c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493542  7cec                   -jl 0x493530
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493530;
    }
L_0x00493544:
    // 00493544  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493546  892dcc835200           -mov dword ptr [0x5283cc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5407692) /* 0x5283cc */) = cpu.ebp;
L_0x0049354c:
    // 0049354c  a1e4835200             -mov eax, dword ptr [0x5283e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5407716) /* 0x5283e4 */);
    // 00493551  e8cabafeff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00493556  8b15b0835200           -mov edx, dword ptr [0x5283b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5407664) /* 0x5283b0 */);
    // 0049355c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049355e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
L_0x00493560:
    // 00493560  758a                   -jne 0x4934ec
    if (!cpu.flags.zf)
    {
        goto L_0x004934ec;
    }
    // 00493562  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493565  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493568  7d09                   -jge 0x493573
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493573;
    }
    // 0049356a  83b8b083520000         +cmp dword ptr [eax + 0x5283b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407664) /* 0x5283b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493571  ebed                   -jmp 0x493560
    goto L_0x00493560;
L_0x00493573:
    // 00493573  e838feffff             -call 0x4933b0
    cpu.esp -= 4;
    sub_4933b0(app, cpu);
    if (cpu.terminate) return;
    // 00493578  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493579  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049357a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049357b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049357c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_493580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493580  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493581  8b1568ab4c00           -mov edx, dword ptr [0x4cab68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024616) /* 0x4cab68 */);
    // 00493587  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493589  7502                   -jne 0x49358d
    if (!cpu.flags.zf)
    {
        goto L_0x0049358d;
    }
    // 0049358b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049358c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049358d:
    // 0049358d  b8d0835200             -mov eax, 0x5283d0
    cpu.eax = 5407696 /*0x5283d0*/;
    // 00493592  e849b9feff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00493597  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493598  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4935a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004935a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004935a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004935a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004935a3  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004935a8  bed0844c00             -mov esi, 0x4c84d0
    cpu.esi = 5014736 /*0x4c84d0*/;
    // 004935ad  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004935af  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004935b1  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004935b6  be08854c00             -mov esi, 0x4c8508
    cpu.esi = 5014792 /*0x4c8508*/;
    // 004935bb  8d7838                 -lea edi, [eax + 0x38]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004935be  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004935c0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4935c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004935c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004935c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004935c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004935c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004935c9  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004935ce  bf08854c00             -mov edi, 0x4c8508
    cpu.edi = 5014792 /*0x4c8508*/;
    // 004935d3  e8642efeff             -call 0x47643c
    cpu.esp -= 4;
    sub_47643c(app, cpu);
    if (cpu.terminate) return;
    // 004935d8  8d7638                 -lea esi, [esi + 0x38]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004935db  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004935dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004935e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4935e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004935e1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004935e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004935e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004935e6  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004935ea  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004935ec  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004935f0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004935f3  b84abf4c00             -mov eax, 0x4cbf4a
    cpu.eax = 5029706 /*0x4cbf4a*/;
    // 004935f8  e8dbdd0000             -call 0x4a13d8
    cpu.esp -= 4;
    sub_4a13d8(app, cpu);
    if (cpu.terminate) return;
    // 004935fd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493600  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493601  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493602  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493603(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493603  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493604  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493605  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00493607  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00493609  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0049360c  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049360e  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00493610  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 00493613  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493614  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493615  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493616(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493616  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493617  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493618  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049361a  b903364900             -mov ecx, 0x493603
    cpu.ecx = 4797955 /*0x493603*/;
    // 0049361f  e833090100             -call 0x4a3f57
    cpu.esp -= 4;
    sub_4a3f57(app, cpu);
    if (cpu.terminate) return;
    // 00493624  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 00493628  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493629  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049362a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_493630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493630  833de883520000         +cmp dword ptr [0x5283e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5407720) /* 0x5283e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493637  7406                   -je 0x49363f
    if (cpu.flags.zf)
    {
        goto L_0x0049363f;
    }
    // 00493639  b8e8835200             -mov eax, 0x5283e8
    cpu.eax = 5407720 /*0x5283e8*/;
    // 0049363e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049363f:
    // 0049363f  e874b9feff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00493644  a3e8835200             -mov dword ptr [0x5283e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5407720) /* 0x5283e8 */) = cpu.eax;
    // 00493649  b8e8835200             -mov eax, 0x5283e8
    cpu.eax = 5407720 /*0x5283e8*/;
    // 0049364e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493650  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493652  e9b1b9feff             -jmp 0x47f008
    return sub_47f008(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_493658(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493658  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049365a  e9c1b9feff             -jmp 0x47f020
    return sub_47f020(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_493660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493662  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493663  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00493665  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00493667  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00493669  7412                   -je 0x49367d
    if (cpu.flags.zf)
    {
        goto L_0x0049367d;
    }
L_0x0049366b:
    // 0049366b  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049366d  80f95c                 +cmp cl, 0x5c
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00493670  7511                   -jne 0x493683
    if (!cpu.flags.zf)
    {
        goto L_0x00493683;
    }
L_0x00493672:
    // 00493672  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00493675  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00493678  40                     -inc eax
    (cpu.eax)++;
    // 00493679  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0049367b  75ee                   -jne 0x49366b
    if (!cpu.flags.zf)
    {
        goto L_0x0049366b;
    }
L_0x0049367d:
    // 0049367d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049367f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493680  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493681  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493682  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493683:
    // 00493683  80f93a                 +cmp cl, 0x3a
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00493686  74ea                   -je 0x493672
    if (cpu.flags.zf)
    {
        goto L_0x00493672;
    }
    // 00493688  80f92f                 +cmp cl, 0x2f
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049368b  74e5                   -je 0x493672
    if (cpu.flags.zf)
    {
        goto L_0x00493672;
    }
    // 0049368d  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00493690  40                     -inc eax
    (cpu.eax)++;
    // 00493691  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00493693  75d6                   -jne 0x49366b
    if (!cpu.flags.zf)
    {
        goto L_0x0049366b;
    }
    // 00493695  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493697  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493698  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493699  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049369a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4936a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004936a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004936a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004936a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004936a3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004936a5  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004936aa  e8a1ffffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 004936af  804a1940               -or byte ptr [edx + 0x19], 0x40
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(25) /* 0x19 */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004936b3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004936b8  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004936bb  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004936bd  ba444e4542             -mov edx, 0x42454e44
    cpu.edx = 1111838276 /*0x42454e44*/;
    // 004936c2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004936c4  e8c7270000             -call 0x495e90
    cpu.esp -= 4;
    sub_495e90(app, cpu);
    if (cpu.terminate) return;
    // 004936c9  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004936ce  e885ffffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 004936d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004936d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004936d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004936d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4936d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004936d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004936d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004936da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004936db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004936dd  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004936e2  e869ffffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 004936e7  8a6219                 -mov ah, byte ptr [edx + 0x19]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(25) /* 0x19 */);
    // 004936ea  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004936ef  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 004936f2  7510                   -jne 0x493704
    if (!cpu.flags.zf)
    {
        goto L_0x00493704;
    }
L_0x004936f4:
    // 004936f4  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004936f9  e85affffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 004936fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00493700  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493701  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493702  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493703  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493704:
    // 00493704  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00493706  034214                 -add eax, dword ptr [edx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
    // 00493709  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0049370e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00493710  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00493712  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00493714  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0049371b  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0049371d  3d444e4542             +cmp eax, 0x42454e44
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1111838276 /*0x42454e44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493722  74d0                   -je 0x4936f4
    if (cpu.flags.zf)
    {
        goto L_0x004936f4;
    }
    // 00493724  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493726  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 0049372b  e828ffffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00493730  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00493732  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493733  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493734  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493735  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493738(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493738  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049373d  eb05                   -jmp 0x493744
    return sub_493744(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_493740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493740  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493742  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00493744  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493745  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493746  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493747  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493748  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493749  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 0049374e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00493753  e8f8feffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00493758  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049375a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049375c:
    // 0049375c  3bbeb4b55100           +cmp edi, dword ptr [esi + 0x51b5b4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5354932) /* 0x51b5b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493762  7420                   -je 0x493784
    if (cpu.flags.zf)
    {
        goto L_0x00493784;
    }
    // 00493764  8b96b0b55100           -mov edx, dword ptr [esi + 0x51b5b0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5354928) /* 0x51b5b0 */);
    // 0049376a  8b9eb4b55100           -mov ebx, dword ptr [esi + 0x51b5b4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5354932) /* 0x51b5b4 */);
L_0x00493770:
    // 00493770  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00493773  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493775  e85effffff             -call 0x4936d8
    cpu.esp -= 4;
    sub_4936d8(app, cpu);
    if (cpu.terminate) return;
    // 0049377a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049377c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049377e  7404                   -je 0x493784
    if (cpu.flags.zf)
    {
        goto L_0x00493784;
    }
    // 00493780  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493782  75ec                   -jne 0x493770
    if (!cpu.flags.zf)
    {
        goto L_0x00493770;
    }
L_0x00493784:
    // 00493784  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00493787  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049378d  7d04                   -jge 0x493793
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493793;
    }
    // 0049378f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493791  75c9                   -jne 0x49375c
    if (!cpu.flags.zf)
    {
        goto L_0x0049375c;
    }
L_0x00493793:
    // 00493793  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00493798  e8bbfeffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 0049379d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049379f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493744(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00493744;
    // 00493740  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493742  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00493744:
    // 00493744  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493745  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493746  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493747  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493748  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493749  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 0049374e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00493753  e8f8feffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00493758  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049375a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049375c:
    // 0049375c  3bbeb4b55100           +cmp edi, dword ptr [esi + 0x51b5b4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5354932) /* 0x51b5b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493762  7420                   -je 0x493784
    if (cpu.flags.zf)
    {
        goto L_0x00493784;
    }
    // 00493764  8b96b0b55100           -mov edx, dword ptr [esi + 0x51b5b0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5354928) /* 0x51b5b0 */);
    // 0049376a  8b9eb4b55100           -mov ebx, dword ptr [esi + 0x51b5b4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5354932) /* 0x51b5b4 */);
L_0x00493770:
    // 00493770  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00493773  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493775  e85effffff             -call 0x4936d8
    cpu.esp -= 4;
    sub_4936d8(app, cpu);
    if (cpu.terminate) return;
    // 0049377a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049377c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049377e  7404                   -je 0x493784
    if (cpu.flags.zf)
    {
        goto L_0x00493784;
    }
    // 00493780  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493782  75ec                   -jne 0x493770
    if (!cpu.flags.zf)
    {
        goto L_0x00493770;
    }
L_0x00493784:
    // 00493784  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00493787  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049378d  7d04                   -jge 0x493793
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493793;
    }
    // 0049378f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493791  75c9                   -jne 0x49375c
    if (!cpu.flags.zf)
    {
        goto L_0x0049375c;
    }
L_0x00493793:
    // 00493793  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00493798  e8bbfeffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 0049379d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049379f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4937b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004937b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004937b1  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004937b6  e895feffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 004937bb  a1a0844c00             -mov eax, dword ptr [0x4c84a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 004937c0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004937c2  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004937c5  e80e000000             -call 0x4937d8
    cpu.esp -= 4;
    sub_4937d8(app, cpu);
    if (cpu.terminate) return;
    // 004937ca  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004937cf  e884feffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 004937d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004937d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4937d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004937d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004937d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004937da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004937db  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004937dc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004937dd  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004937e0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004937e2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004937e4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004937e6  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004937e9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004937ed  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004937ef  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
L_0x004937f1:
    // 004937f1  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004937f3:
    // 004937f3  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004937f5  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004937f8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004937fa  39d3                   +cmp ebx, edx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004937fc  731b                   -jae 0x493819
    if (!cpu.flags.cf)
    {
        goto L_0x00493819;
    }
    // 004937fe  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00493800  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00493802  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00493804  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00493806:
    // 00493806  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00493808  741a                   -je 0x493824
    if (cpu.flags.zf)
    {
        goto L_0x00493824;
    }
L_0x0049380a:
    // 0049380a  39fe                   +cmp esi, edi
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
    // 0049380c  7416                   -je 0x493824
    if (cpu.flags.zf)
    {
        goto L_0x00493824;
    }
    // 0049380e  f6461818               +test byte ptr [esi + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 00493812  751d                   -jne 0x493831
    if (!cpu.flags.zf)
    {
        goto L_0x00493831;
    }
    // 00493814  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00493817  ebf1                   -jmp 0x49380a
    goto L_0x0049380a;
L_0x00493819:
    // 00493819  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049381b  74e9                   -je 0x493806
    if (cpu.flags.zf)
    {
        goto L_0x00493806;
    }
    // 0049381d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049381f  8b4924                 -mov ecx, dword ptr [ecx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00493822  ebcf                   -jmp 0x4937f3
    goto L_0x004937f3;
L_0x00493824:
    // 00493824  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00493828  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049382b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049382c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049382d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049382e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049382f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493830  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493831:
    // 00493831  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00493833  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00493836  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493838  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049383b  8d1c2a                 -lea ebx, [edx + ebp]
    cpu.ebx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0049383e  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00493842  3b1424                 +cmp edx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493845  7412                   -je 0x493859
    if (cpu.flags.zf)
    {
        goto L_0x00493859;
    }
    // 00493847  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049384a  39d5                   +cmp ebp, edx
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
    // 0049384c  7d2f                   -jge 0x49387d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049387d;
    }
    // 0049384e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493850  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493852  74d0                   -je 0x493824
    if (cpu.flags.zf)
    {
        goto L_0x00493824;
    }
    // 00493854  8b4924                 -mov ecx, dword ptr [ecx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00493857  eb98                   -jmp 0x4937f1
    goto L_0x004937f1;
L_0x00493859:
    // 00493859  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049385d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00493860  29d5                   +sub ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493862  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00493864  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00493866  e8e5cefeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0049386b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00493870  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00493872  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00493874  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00493878  e974ffffff             -jmp 0x4937f1
    goto L_0x004937f1;
L_0x0049387d:
    // 0049387d  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493881  29d5                   +sub ebp, edx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493883  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00493885  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00493887  e8c4cefeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0049388c  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049388f  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00493892  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00493894  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00493897  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049389a  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049389d  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004938a0  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004938a3  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004938a6  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004938a9  897024                 -mov dword ptr [eax + 0x24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004938ac  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004938b1  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004938b4  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004938b8  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004938ba  e932ffffff             -jmp 0x4937f1
    goto L_0x004937f1;
}

/* align: skip 0x90 */
void Application::sub_4938c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004938c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004938c1  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004938c6  e885fdffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 004938cb  a1a0844c00             -mov eax, dword ptr [0x4c84a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 004938d0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004938d3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004938d5  e80e000000             -call 0x4938e8
    cpu.esp -= 4;
    sub_4938e8(app, cpu);
    if (cpu.terminate) return;
    // 004938da  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004938df  e874fdffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 004938e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004938e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4938e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004938e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004938e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004938ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004938eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004938ec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004938ed  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004938ef  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004938f1  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004938f3  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004938f6  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004938f9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004938fb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004938fd:
    // 004938fd  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004938ff:
    // 004938ff  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493901  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493903  39d7                   +cmp edi, edx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x00493905:
    // 00493905  7217                   -jb 0x49391e
    if (cpu.flags.cf)
    {
        goto L_0x0049391e;
    }
    // 00493907  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493909  751b                   -jne 0x493926
    if (!cpu.flags.zf)
    {
        goto L_0x00493926;
    }
L_0x0049390b:
    // 0049390b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049390d  7425                   -je 0x493934
    if (cpu.flags.zf)
    {
        goto L_0x00493934;
    }
L_0x0049390f:
    // 0049390f  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493911  7421                   -je 0x493934
    if (cpu.flags.zf)
    {
        goto L_0x00493934;
    }
    // 00493913  f6461818               +test byte ptr [esi + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 00493917  7523                   -jne 0x49393c
    if (!cpu.flags.zf)
    {
        goto L_0x0049393c;
    }
    // 00493919  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0049391c  ebf1                   -jmp 0x49390f
    goto L_0x0049390f;
L_0x0049391e:
    // 0049391e  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493920  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00493922  29f8                   +sub eax, edi
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
    // 00493924  ebe5                   -jmp 0x49390b
    goto L_0x0049390b;
L_0x00493926:
    // 00493926  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493928  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049392b  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0049392e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00493930  3b39                   +cmp edi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493932  ebd1                   -jmp 0x493905
    goto L_0x00493905;
L_0x00493934:
    // 00493934  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00493936  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493937  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493938  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493939  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049393a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049393b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049393c:
    // 0049393c  39ce                   +cmp esi, ecx
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
    // 0049393e  7415                   -je 0x493955
    if (cpu.flags.zf)
    {
        goto L_0x00493955;
    }
    // 00493940  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00493943  39d0                   +cmp eax, edx
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
    // 00493945  7d28                   -jge 0x49396f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049396f;
    }
    // 00493947  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493949  037910                 -add edi, dword ptr [ecx + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 0049394c  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049394e  74e4                   -je 0x493934
    if (cpu.flags.zf)
    {
        goto L_0x00493934;
    }
    // 00493950  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00493953  ebaa                   -jmp 0x4938ff
    goto L_0x004938ff;
L_0x00493955:
    // 00493955  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493957  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00493959  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049395c  e8efcdfeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00493961  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00493964  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 00493966  01df                   +add edi, ebx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493968  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049396d  eb90                   -jmp 0x4938ff
    goto L_0x004938ff;
L_0x0049396f:
    // 0049396f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00493971  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00493973  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00493975  e8d6cdfeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 0049397a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049397d  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00493980  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 00493982  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00493985  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00493988  894324                 -mov dword ptr [ebx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049398b  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049398e  8b4124                 -mov eax, dword ptr [ecx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00493991  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00493994  897020                 -mov dword ptr [eax + 0x20], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00493997  897124                 -mov dword ptr [ecx + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0049399a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049399d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004939a2  e956ffffff             -jmp 0x4938fd
    goto L_0x004938fd;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4939b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004939b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004939b1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004939b6  e80151feff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 004939bb  e81c000000             -call 0x4939dc
    cpu.esp -= 4;
    sub_4939dc(app, cpu);
    if (cpu.terminate) return;
    // 004939c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4939c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004939c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004939c5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004939ca  e80d000000             -call 0x4939dc
    cpu.esp -= 4;
    sub_4939dc(app, cpu);
    if (cpu.terminate) return;
    // 004939cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004939d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4939d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004939d4  e8e350feff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 004939d9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 004939dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004939dd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004939df  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004939e4  e867fcffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 004939e9  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004939ec  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004939ee  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004939f0  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004939f2  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004939f5  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004939fa  e859fcffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 004939ff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493a01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4939dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004939dc;
    // 004939d4  e8e350feff             -call 0x478abc
    cpu.esp -= 4;
    sub_478abc(app, cpu);
    if (cpu.terminate) return;
    // 004939d9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x004939dc:
    // 004939dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004939dd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004939df  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004939e4  e867fcffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 004939e9  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004939ec  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004939ee  0c08                   -or al, 8
    cpu.al |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004939f0  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004939f2  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004939f5  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 004939fa  e859fcffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 004939ff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493a01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493a04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493a04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493a05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493a06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493a07  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493a08  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00493a0a  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00493a10  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00493a13  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00493a1a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493a1c  bfb0b55100             -mov edi, 0x51b5b0
    cpu.edi = 5354928 /*0x51b5b0*/;
    // 00493a21  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493a24  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493a26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493a28  e833fcffff             -call 0x493660
    cpu.esp -= 4;
    sub_493660(app, cpu);
    if (cpu.terminate) return;
    // 00493a2d  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00493a2f  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00493a32  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493a34  39d1                   +cmp ecx, edx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493a36  7421                   -je 0x493a59
    if (cpu.flags.zf)
    {
        goto L_0x00493a59;
    }
L_0x00493a38:
    // 00493a38  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00493a3d  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493a40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493a42  e85c6cffff             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 00493a47  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493a49  7506                   -jne 0x493a51
    if (!cpu.flags.zf)
    {
        goto L_0x00493a51;
    }
    // 00493a4b  f6411808               +test byte ptr [ecx + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00493a4f  750f                   -jne 0x493a60
    if (!cpu.flags.zf)
    {
        goto L_0x00493a60;
    }
L_0x00493a51:
    // 00493a51  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00493a54  3b4f04                 +cmp ecx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493a57  75df                   -jne 0x493a38
    if (!cpu.flags.zf)
    {
        goto L_0x00493a38;
    }
L_0x00493a59:
    // 00493a59  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493a5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493a60:
    // 00493a60  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493a62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493a68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493a68  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493a69  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00493a6b  e894ffffff             -call 0x493a04
    cpu.esp -= 4;
    sub_493a04(app, cpu);
    if (cpu.terminate) return;
    // 00493a70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493a74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493a74  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493a75  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00493a77  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00493a7c  e8cffbffff             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00493a81  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493a83  e810000000             -call 0x493a98
    cpu.esp -= 4;
    sub_493a98(app, cpu);
    if (cpu.terminate) return;
    // 00493a88  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00493a8a  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00493a8f  e8c4fbffff             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00493a94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493a96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493a97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493a98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493a98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493a99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493a9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493a9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493a9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493a9d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493a9e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00493aa1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00493aa3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00493aa5  81e3000f0000           -and ebx, 0xf00
    cpu.ebx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00493aab  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 00493aae  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00493ab5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493ab7  bbb0b55100             -mov ebx, 0x51b5b0
    cpu.ebx = 5354928 /*0x51b5b0*/;
    // 00493abc  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00493abf  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00493ac1  837b1000               +cmp dword ptr [ebx + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493ac5  0f8484000000           -je 0x493b4f
    if (cpu.flags.zf)
    {
        goto L_0x00493b4f;
    }
    // 00493acb  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00493acd  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00493acf  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00493ad1  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00493ad4  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00493ad7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00493ad9:
    // 00493ad9  f6461808               +test byte ptr [esi + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 00493add  7422                   -je 0x493b01
    if (cpu.flags.zf)
    {
        goto L_0x00493b01;
    }
    // 00493adf  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00493ae2  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00493ae5  39f8                   +cmp eax, edi
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
    // 00493ae7  0f866b000000           -jbe 0x493b58
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00493b58;
    }
L_0x00493aed:
    // 00493aed  a1b4844c00             -mov eax, dword ptr [0x4c84b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */);
    // 00493af2  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00493af4  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00493af7  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00493afa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493afc  83e707                 -and edi, 7
    cpu.edi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00493aff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00493b01:
    // 00493b01  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00493b04  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00493b07  39ce                   +cmp esi, ecx
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
    // 00493b09  75ce                   -jne 0x493ad9
    if (!cpu.flags.zf)
    {
        goto L_0x00493ad9;
    }
    // 00493b0b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00493b0d  7434                   -je 0x493b43
    if (cpu.flags.zf)
    {
        goto L_0x00493b43;
    }
    // 00493b0f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00493b11  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00493b13:
    // 00493b13  40                     -inc eax
    (cpu.eax)++;
    // 00493b14  8a5a04                 -mov bl, byte ptr [edx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00493b17  42                     -inc edx
    (cpu.edx)++;
    // 00493b18  885c04ff               -mov byte ptr [esp + eax - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.eax * 1) = cpu.bl;
    // 00493b1c  83f80c                 +cmp eax, 0xc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493b1f  7cf2                   -jl 0x493b13
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493b13;
    }
    // 00493b21  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00493b23  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
L_0x00493b27:
    // 00493b27  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493b29  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00493b2c  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00493b2f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493b31  80cb08                 -or bl, 8
    cpu.bl |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00493b34  e8a74bfeff             -call 0x4786e0
    cpu.esp -= 4;
    sub_4786e0(app, cpu);
    if (cpu.terminate) return;
    // 00493b39  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00493b3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493b3d  7429                   -je 0x493b68
    if (cpu.flags.zf)
    {
        goto L_0x00493b68;
    }
    // 00493b3f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493b41  7540                   -jne 0x493b83
    if (!cpu.flags.zf)
    {
        goto L_0x00493b83;
    }
L_0x00493b43:
    // 00493b43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00493b45:
    // 00493b45  83c410                 +add esp, 0x10
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
    // 00493b48  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493b4f:
    // 00493b4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493b51  e87a50feff             -call 0x478bd0
    cpu.esp -= 4;
    sub_478bd0(app, cpu);
    if (cpu.terminate) return;
    // 00493b56  ebed                   -jmp 0x493b45
    goto L_0x00493b45;
L_0x00493b58:
    // 00493b58  75a7                   -jne 0x493b01
    if (!cpu.flags.zf)
    {
        goto L_0x00493b01;
    }
    // 00493b5a  a1b4844c00             -mov eax, dword ptr [0x4c84b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014708) /* 0x4c84b4 */);
    // 00493b5f  2b461c                 -sub eax, dword ptr [esi + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 00493b62  39d0                   +cmp eax, edx
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
    // 00493b64  7387                   -jae 0x493aed
    if (!cpu.flags.cf)
    {
        goto L_0x00493aed;
    }
    // 00493b66  eb99                   -jmp 0x493b01
    goto L_0x00493b01;
L_0x00493b68:
    // 00493b68  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493b6a  e829ffffff             -call 0x493a98
    cpu.esp -= 4;
    sub_493a98(app, cpu);
    if (cpu.terminate) return;
    // 00493b6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493b71  75b4                   -jne 0x493b27
    if (!cpu.flags.zf)
    {
        goto L_0x00493b27;
    }
    // 00493b73  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493b75  750c                   -jne 0x493b83
    if (!cpu.flags.zf)
    {
        goto L_0x00493b83;
    }
    // 00493b77  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493b79  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00493b7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b81  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493b82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493b83:
    // 00493b83  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00493b86  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00493b88  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00493b8b  e8c0cbfeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00493b90  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00493b92  e8814ffeff             -call 0x478b18
    cpu.esp -= 4;
    sub_478b18(app, cpu);
    if (cpu.terminate) return;
    // 00493b97  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00493b9c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00493b9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ba0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ba1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ba2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ba3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ba4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ba5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493ba8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493ba8  e807000000             -call 0x493bb4
    cpu.esp -= 4;
    sub_493bb4(app, cpu);
    if (cpu.terminate) return;
    // 00493bad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493baf  7402                   -je 0x493bb3
    if (cpu.flags.zf)
    {
        goto L_0x00493bb3;
    }
    // 00493bb1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00493bb3:
    // 00493bb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493bb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493bb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493bb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493bb6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493bb7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493bb8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493bb9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00493bbb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00493bbd  e842feffff             -call 0x493a04
    cpu.esp -= 4;
    sub_493a04(app, cpu);
    if (cpu.terminate) return;
    // 00493bc2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493bc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493bc6  7537                   -jne 0x493bff
    if (!cpu.flags.zf)
    {
        goto L_0x00493bff;
    }
    // 00493bc8  8b1da0844c00           -mov ebx, dword ptr [0x4c84a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014688) /* 0x4c84a0 */);
    // 00493bce  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
L_0x00493bd1:
    // 00493bd1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00493bd3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493bd5  e82afeffff             -call 0x493a04
    cpu.esp -= 4;
    sub_493a04(app, cpu);
    if (cpu.terminate) return;
    // 00493bda  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493bdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493bde  7561                   -jne 0x493c41
    if (!cpu.flags.zf)
    {
        goto L_0x00493c41;
    }
    // 00493be0  81e3000f0000           -and ebx, 0xf00
    cpu.ebx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00493be6  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 00493be9  6bdb18                 -imul ebx, ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(24 /*0x18*/)));
    // 00493bec  81c3b0b55100           -add ebx, 0x51b5b0
    (cpu.ebx) += x86::reg32(x86::sreg32(5354928 /*0x51b5b0*/));
    // 00493bf2  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00493bf5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00493bf7  75d8                   -jne 0x493bd1
    if (!cpu.flags.zf)
    {
        goto L_0x00493bd1;
    }
L_0x00493bf9:
    // 00493bf9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bfa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bfb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bfd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493bfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493bff:
    // 00493bff  8a6018                 -mov ah, byte ptr [eax + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00493c02  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00493c05  886618                 -mov byte ptr [esi + 0x18], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ah;
    // 00493c08  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00493c0b  7404                   -je 0x493c11
    if (cpu.flags.zf)
    {
        goto L_0x00493c11;
    }
    // 00493c0d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493c0f  ebe8                   -jmp 0x493bf9
    goto L_0x00493bf9;
L_0x00493c11:
    // 00493c11  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493c13  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00493c16  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00493c19  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c1b  e8c04afeff             -call 0x4786e0
    cpu.esp -= 4;
    sub_4786e0(app, cpu);
    if (cpu.terminate) return;
    // 00493c20  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00493c22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493c24  7504                   -jne 0x493c2a
    if (!cpu.flags.zf)
    {
        goto L_0x00493c2a;
    }
    // 00493c26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493c28  ebcf                   -jmp 0x493bf9
    goto L_0x00493bf9;
L_0x00493c2a:
    // 00493c2a  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00493c2d  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00493c2f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00493c31  e81acbfeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00493c36  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493c38  e8bb4efeff             -call 0x478af8
    cpu.esp -= 4;
    sub_478af8(app, cpu);
    if (cpu.terminate) return;
    // 00493c3d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493c3f  ebb8                   -jmp 0x493bf9
    goto L_0x00493bf9;
L_0x00493c41:
    // 00493c41  806018f7               -and byte ptr [eax + 0x18], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00493c45  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493c47  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00493c4a  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00493c4d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493c4f  e88c4afeff             -call 0x4786e0
    cpu.esp -= 4;
    sub_4786e0(app, cpu);
    if (cpu.terminate) return;
    // 00493c54  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00493c56  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00493c59  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00493c5b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00493c5d  e8eecafeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00493c62  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493c64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493c69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493c6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493c6c  e807000000             -call 0x493c78
    cpu.esp -= 4;
    sub_493c78(app, cpu);
    if (cpu.terminate) return;
    // 00493c71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493c73  7402                   -je 0x493c77
    if (cpu.flags.zf)
    {
        goto L_0x00493c77;
    }
    // 00493c75  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00493c77:
    // 00493c77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493c78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493c78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493c79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493c7a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493c7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493c7c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00493c7e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00493c80  e87ffdffff             -call 0x493a04
    cpu.esp -= 4;
    sub_493a04(app, cpu);
    if (cpu.terminate) return;
    // 00493c85  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493c87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493c89  7528                   -jne 0x493cb3
    if (!cpu.flags.zf)
    {
        goto L_0x00493cb3;
    }
    // 00493c8b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00493c8d  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00493c93  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00493c96  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00493c9d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00493c9f  bab0b55100             -mov edx, 0x51b5b0
    cpu.edx = 5354928 /*0x51b5b0*/;
    // 00493ca4  8b54c210               -mov edx, dword ptr [edx + eax*8 + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */ + cpu.eax * 8);
    // 00493ca8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493caa  754b                   -jne 0x493cf7
    if (!cpu.flags.zf)
    {
        goto L_0x00493cf7;
    }
    // 00493cac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00493cae:
    // 00493cae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493caf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493cb3:
    // 00493cb3  8a5018                 -mov dl, byte ptr [eax + 0x18]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00493cb6  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00493cb9  885018                 -mov byte ptr [eax + 0x18], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.dl;
    // 00493cbc  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 00493cbf  75ed                   -jne 0x493cae
    if (!cpu.flags.zf)
    {
        goto L_0x00493cae;
    }
    // 00493cc1  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00493cc4  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00493cc7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493cc9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493ccb  e8104afeff             -call 0x4786e0
    cpu.esp -= 4;
    sub_4786e0(app, cpu);
    if (cpu.terminate) return;
    // 00493cd0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00493cd2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493cd4  7507                   -jne 0x493cdd
    if (!cpu.flags.zf)
    {
        goto L_0x00493cdd;
    }
    // 00493cd6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493cd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cdc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493cdd:
    // 00493cdd  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00493ce0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00493ce2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00493ce4  e867cafeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00493ce9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493ceb  e8084efeff             -call 0x478af8
    cpu.esp -= 4;
    sub_478af8(app, cpu);
    if (cpu.terminate) return;
    // 00493cf0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493cf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cf5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493cf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493cf7:
    // 00493cf7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493cf9  e806fdffff             -call 0x493a04
    cpu.esp -= 4;
    sub_493a04(app, cpu);
    if (cpu.terminate) return;
    // 00493cfe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493d00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493d02  74aa                   -je 0x493cae
    if (cpu.flags.zf)
    {
        goto L_0x00493cae;
    }
    // 00493d04  8a6018                 -mov ah, byte ptr [eax + 0x18]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00493d07  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00493d0a  80e4f7                 -and ah, 0xf7
    cpu.ah &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 00493d0d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493d0f  886618                 -mov byte ptr [esi + 0x18], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ah;
    // 00493d12  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00493d14  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00493d17  e8c449feff             -call 0x4786e0
    cpu.esp -= 4;
    sub_4786e0(app, cpu);
    if (cpu.terminate) return;
    // 00493d1c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00493d1e  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00493d21  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00493d23  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00493d25  e826cafeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00493d2a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00493d2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_493d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493d40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493d41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493d42  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00493d45  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493d47  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00493d4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493d4d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00493d51  2eff1508554b00         -call dword ptr cs:[0x4b5508]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936968) /* 0x4b5508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493d58  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00493d5c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00493d5f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493d64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493d64  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493d65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493d66  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00493d69  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493d6b  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00493d70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493d71  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00493d75  2eff1508554b00         -call dword ptr cs:[0x4b5508]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936968) /* 0x4b5508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493d7c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493d80  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00493d83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493d85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493d88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493d88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493d89  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493d8a  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00493d8d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493d8f  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00493d94  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493d95  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00493d99  2eff1508554b00         -call dword ptr cs:[0x4b5508]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936968) /* 0x4b5508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493da0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00493da4  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00493da7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493da8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493da9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_493dac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493dac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493dad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493dae  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00493db1  ba00006000             -mov edx, 0x600000
    cpu.edx = 6291456 /*0x600000*/;
    // 00493db6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00493db8  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00493dbd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493dbe  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00493dc2  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00493dc6  2eff1508554b00         -call dword ptr cs:[0x4b5508]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936968) /* 0x4b5508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493dcd  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00493dd1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493dd2  683f000f00             -push 0xf003f
    app->getMemory<x86::reg32>(cpu.esp-4) = 983103 /*0xf003f*/;
    cpu.esp -= 4;
    // 00493dd7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493dd9  6838f24b00             -push 0x4bf238
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977208 /*0x4bf238*/;
    cpu.esp -= 4;
    // 00493dde  6806000080             -push 0x80000006
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483654 /*0x80000006*/;
    cpu.esp -= 4;
    // 00493de3  2eff1570534b00         -call dword ptr cs:[0x4b5370]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936560) /* 0x4b5370 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493dea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493dec  740e                   -je 0x493dfc
    if (cpu.flags.zf)
    {
        goto L_0x00493dfc;
    }
    // 00493dee  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493df2  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00493df6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00493df9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493dfa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493dfb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493dfc:
    // 00493dfc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493dfd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493dfe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493dff  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00493e03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493e04  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00493e08  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00493e09  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493e0b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00493e0d  684cf24b00             -push 0x4bf24c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4977228 /*0x4bf24c*/;
    cpu.esp -= 4;
    // 00493e12  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00493e16  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00493e1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493e1c  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 00493e20  2eff1574534b00         -call dword ptr cs:[0x4b5374]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936564) /* 0x4b5374 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493e27  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00493e2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493e2c  2eff1568534b00         -call dword ptr cs:[0x4b5368]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936552) /* 0x4b5368 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493e33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e35  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e36  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00493e3a  2b442420               -sub eax, dword ptr [esp + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00493e3e  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00493e41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493e43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_493e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493e51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493e52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493e53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493e54  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00493e56  8b0cc5008a5200         -mov ecx, dword ptr [eax*8 + 0x528a00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.eax * 8);
    // 00493e5d  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00493e62  bf80000000             -mov edi, 0x80
    cpu.edi = 128 /*0x80*/;
    // 00493e67  80790401               +cmp byte ptr [ecx + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00493e6b  7206                   -jb 0x493e73
    if (cpu.flags.cf)
    {
        goto L_0x00493e73;
    }
    // 00493e6d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00493e6f  668b7906               -mov di, word ptr [ecx + 6]
    cpu.di = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
L_0x00493e73:
    // 00493e73  e8bc63feff             -call 0x47a234
    cpu.esp -= 4;
    sub_47a234(app, cpu);
    if (cpu.terminate) return;
    // 00493e78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493e7a  754d                   -jne 0x493ec9
    if (!cpu.flags.zf)
    {
        goto L_0x00493ec9;
    }
    // 00493e7c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00493e7e  7c49                   -jl 0x493ec9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493ec9;
    }
    // 00493e80  39fe                   +cmp esi, edi
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
    // 00493e82  7d45                   -jge 0x493ec9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00493ec9;
    }
    // 00493e84  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00493e8b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493e8d  80790402               +cmp byte ptr [ecx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00493e91  7240                   -jb 0x493ed3
    if (cpu.flags.cf)
    {
        goto L_0x00493ed3;
    }
    // 00493e93  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00493e95  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
L_0x00493e98:
    // 00493e98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493e9a  742d                   -je 0x493ec9
    if (cpu.flags.zf)
    {
        goto L_0x00493ec9;
    }
    // 00493e9c  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493ea2  7534                   -jne 0x493ed8
    if (!cpu.flags.zf)
    {
        goto L_0x00493ed8;
    }
    // 00493ea4  e84f000000             -call 0x493ef8
    cpu.esp -= 4;
    sub_493ef8(app, cpu);
    if (cpu.terminate) return;
L_0x00493ea9:
    // 00493ea9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00493eab:
    // 00493eab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493ead  7c13                   -jl 0x493ec2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493ec2;
    }
    // 00493eaf  8a6104                 -mov ah, byte ptr [ecx + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00493eb2  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00493eb5  80fc02                 +cmp ah, 2
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00493eb8  722e                   -jb 0x493ee8
    if (cpu.flags.cf)
    {
        goto L_0x00493ee8;
    }
    // 00493eba  c7442e0c00000000       -mov dword ptr [esi + ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebp * 1) = 0 /*0x0*/;
L_0x00493ec2:
    // 00493ec2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00493ec4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ec5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ec6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ec7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ec8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493ec9:
    // 00493ec9  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00493ece  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ecf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ed0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ed1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ed2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493ed3:
    // 00493ed3  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00493ed6  ebc0                   -jmp 0x493e98
    goto L_0x00493e98;
L_0x00493ed8:
    // 00493ed8  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00493edd  75cc                   -jne 0x493eab
    if (!cpu.flags.zf)
    {
        goto L_0x00493eab;
    }
    // 00493edf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00493ee1  e86a4d0000             -call 0x498c50
    cpu.esp -= 4;
    sub_498c50(app, cpu);
    if (cpu.terminate) return;
    // 00493ee6  ebc1                   -jmp 0x493ea9
    goto L_0x00493ea9;
L_0x00493ee8:
    // 00493ee8  c744310800000000       -mov dword ptr [ecx + esi + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.esi * 1) = 0 /*0x0*/;
    // 00493ef0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493ef2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ef3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ef4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ef5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493ef6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_493ef8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493ef8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493ef9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00493efa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493efb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00493efd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00493eff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493f01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493f03  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 00493f06  39c2                   +cmp edx, eax
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
    // 00493f08  7c06                   -jl 0x493f10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493f10;
    }
    // 00493f0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493f0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493f10:
    // 00493f10  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00493f13  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00493f15  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00493f18  42                     -inc edx
    (cpu.edx)++;
    // 00493f19  e8d29cfeff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 00493f1e  83c144                 -add ecx, 0x44
    (cpu.ecx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00493f21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493f23  8a4307                 -mov al, byte ptr [ebx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 00493f26  39c2                   +cmp edx, eax
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
    // 00493f28  7ce6                   -jl 0x493f10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493f10;
    }
    // 00493f2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00493f2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_493f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493f30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00493f31  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00493f32  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00493f33  81ec080c0000           -sub esp, 0xc08
    (cpu.esp) -= x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 00493f39  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00493f3b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00493f3d  899c24000c0000         -mov dword ptr [esp + 0xc00], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.ebx;
    // 00493f44  898c24040c0000         -mov dword ptr [esp + 0xc04], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.ecx;
    // 00493f4b  8a256cab4c00           -mov ah, byte ptr [0x4cab6c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
    // 00493f51  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00493f56  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00493f58  750f                   -jne 0x493f69
    if (!cpu.flags.zf)
    {
        goto L_0x00493f69;
    }
    // 00493f5a  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 00493f5f  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 00493f65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493f68  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493f69:
    // 00493f69  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00493f6b  e8c462feff             -call 0x47a234
    cpu.esp -= 4;
    sub_47a234(app, cpu);
    if (cpu.terminate) return;
    // 00493f70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00493f72  0f8562000000           -jne 0x493fda
    if (!cpu.flags.zf)
    {
        goto L_0x00493fda;
    }
    // 00493f78  83bc24000c000000       +cmp dword ptr [esp + 0xc00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493f80  7458                   -je 0x493fda
    if (cpu.flags.zf)
    {
        goto L_0x00493fda;
    }
    // 00493f82  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00493f84  7454                   -je 0x493fda
    if (cpu.flags.zf)
    {
        goto L_0x00493fda;
    }
    // 00493f86  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00493f8b:
    // 00493f8b  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00493f8e  895404f4               -mov dword ptr [esp + eax - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.eax * 1) = cpu.edx;
    // 00493f92  3d000c0000             +cmp eax, 0xc00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493f97  75f2                   -jne 0x493f8b
    if (!cpu.flags.zf)
    {
        goto L_0x00493f8b;
    }
    // 00493f99  8b34f5008a5200         -mov esi, dword ptr [esi*8 + 0x528a00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5409280) /* 0x528a00 */ + cpu.esi * 8);
    // 00493fa0  807e0401               +cmp byte ptr [esi + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00493fa4  7206                   -jb 0x493fac
    if (cpu.flags.cf)
    {
        goto L_0x00493fac;
    }
    // 00493fa6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00493fa8  668b5e06               -mov bx, word ptr [esi + 6]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
L_0x00493fac:
    // 00493fac  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00493fae  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00493fb0  7e19                   -jle 0x493fcb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00493fcb;
    }
    // 00493fb2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00493fb4:
    // 00493fb4  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00493fb8  722f                   -jb 0x493fe9
    if (cpu.flags.cf)
    {
        goto L_0x00493fe9;
    }
    // 00493fba  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00493fbc  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
L_0x00493fbf:
    // 00493fbf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00493fc1  742b                   -je 0x493fee
    if (cpu.flags.zf)
    {
        goto L_0x00493fee;
    }
    // 00493fc3  41                     -inc ecx
    (cpu.ecx)++;
    // 00493fc4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00493fc7  39d9                   +cmp ecx, ebx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493fc9  7ce9                   -jl 0x493fb4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00493fb4;
    }
L_0x00493fcb:
    // 00493fcb  b8f7ffffff             -mov eax, 0xfffffff7
    cpu.eax = 4294967287 /*0xfffffff7*/;
    // 00493fd0  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 00493fd6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493fd7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493fd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493fd9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493fda:
    // 00493fda  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00493fdf  81c4080c0000           +add esp, 0xc08
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3080 /*0xc08*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00493fe5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493fe6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493fe7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493fe8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493fe9:
    // 00493fe9  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00493fec  ebd1                   -jmp 0x493fbf
    goto L_0x00493fbf;
L_0x00493fee:
    // 00493fee  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00493ff0  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 00493ff7  8b8424000c0000         -mov eax, dword ptr [esp + 0xc00]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 00493ffe  e8ad010000             -call 0x4941b0
    cpu.esp -= 4;
    sub_4941b0(app, cpu);
    if (cpu.terminate) return;
    // 00494003  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494005  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494007  7c29                   -jl 0x494032
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494032;
    }
    // 00494009  8a5e04                 -mov bl, byte ptr [esi + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0049400c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00494013  80fb02                 +cmp bl, 2
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494016  722b                   -jb 0x494043
    if (cpu.flags.cf)
    {
        goto L_0x00494043;
    }
    // 00494018  8b9c24000c0000         -mov ebx, dword ptr [esp + 0xc00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 0049401f  895c070c               -mov dword ptr [edi + eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.ebx;
    // 00494023  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494025  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 00494028  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 0049402e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049402f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494030  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494031  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494032:
    // 00494032  c74500ffffffff         -mov dword ptr [ebp], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebp) = 4294967295 /*0xffffffff*/;
    // 00494039  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 0049403f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494040  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494041  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494042  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494043:
    // 00494043  8b9c24000c0000         -mov ebx, dword ptr [esp + 0xc00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 0049404a  895c0608               -mov dword ptr [esi + eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ebx;
    // 0049404e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494050  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 00494053  81c4080c0000           -add esp, 0xc08
    (cpu.esp) += x86::reg32(x86::sreg32(3080 /*0xc08*/));
    // 00494059  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049405a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049405b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049405c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494062  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494063  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 00494069  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049406b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049406d  ba00845200             -mov edx, 0x528400
    cpu.edx = 5407744 /*0x528400*/;
    // 00494072  8d9a00060000           -lea ebx, [edx + 0x600]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1536) /* 0x600 */);
L_0x00494078:
    // 00494078  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 0049407b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049407e  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494080  7511                   -jne 0x494093
    if (!cpu.flags.zf)
    {
        goto L_0x00494093;
    }
    // 00494082  31f0                   -xor eax, esi
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00494084  668b4208               -mov ax, word ptr [edx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00494088  39c8                   +cmp eax, ecx
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
    // 0049408a  7507                   -jne 0x494093
    if (!cpu.flags.zf)
    {
        goto L_0x00494093;
    }
    // 0049408c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049408e  e86da8feff             -call 0x47e900
    cpu.esp -= 4;
    sub_47e900(app, cpu);
    if (cpu.terminate) return;
L_0x00494093:
    // 00494093  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00494096  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494098  75de                   -jne 0x494078
    if (!cpu.flags.zf)
    {
        goto L_0x00494078;
    }
    // 0049409a  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049409c  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x004940a1:
    // 004940a1  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004940a4  895c14f4               -mov dword ptr [esp + edx - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.edx * 1) = cpu.ebx;
    // 004940a8  81fa000c0000           +cmp edx, 0xc00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004940ae  75f1                   -jne 0x4940a1
    if (!cpu.flags.zf)
    {
        goto L_0x004940a1;
    }
    // 004940b0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004940b2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004940b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004940b6  e895fdffff             -call 0x493e50
    cpu.esp -= 4;
    sub_493e50(app, cpu);
    if (cpu.terminate) return;
    // 004940bb  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 004940c1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004940c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004940c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004940c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4940d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004940d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004940d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004940d2  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004940d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004940d7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004940d9  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004940dd  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004940e2  8a6005                 -mov ah, byte ptr [eax + 5]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004940e5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004940e8  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004940ea  0f856a000000           -jne 0x49415a
    if (!cpu.flags.zf)
    {
        goto L_0x0049415a;
    }
    // 004940f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004940f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004940f2  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004940f5  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004940f8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004940fa  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004940fc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004940fe  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00494101:
    // 00494101  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494103  8a4107                 -mov al, byte ptr [ecx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00494106  39c6                   +cmp esi, eax
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
    // 00494108  7d5d                   -jge 0x494167
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494167;
    }
    // 0049410a  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049410d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049410f  83781800               +cmp dword ptr [eax + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494113  7406                   -je 0x49411b
    if (cpu.flags.zf)
    {
        goto L_0x0049411b;
    }
    // 00494115  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00494118  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0049411b:
    // 0049411b  83781c00               +cmp dword ptr [eax + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049411f  7406                   -je 0x494127
    if (cpu.flags.zf)
    {
        goto L_0x00494127;
    }
    // 00494121  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00494124  01501c                 -add dword ptr [eax + 0x1c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00494127:
    // 00494127  83782000               +cmp dword ptr [eax + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049412b  7406                   -je 0x494133
    if (cpu.flags.zf)
    {
        goto L_0x00494133;
    }
    // 0049412d  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00494130  015020                 -add dword ptr [eax + 0x20], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00494133:
    // 00494133  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00494136  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00494139  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0049413c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049413e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00494140  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00494143  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494147  e8549cfeff             -call 0x47dda0
    cpu.esp -= 4;
    sub_47dda0(app, cpu);
    if (cpu.terminate) return;
    // 0049414c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00494150  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494152  7c0e                   -jl 0x494162
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494162;
    }
    // 00494154  83c744                 +add edi, 0x44
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494157  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00494158  eba7                   -jmp 0x494101
    goto L_0x00494101;
L_0x0049415a:
    // 0049415a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049415c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049415f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494160  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494161  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494162:
    // 00494162  4e                     -dec esi
    (cpu.esi)--;
    // 00494163  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00494167:
    // 00494167  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049416b  83feff                 +cmp esi, -1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049416e  7e30                   -jle 0x4941a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004941a0;
    }
    // 00494170  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494172  7c20                   -jl 0x494194
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494194;
    }
    // 00494174  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494176  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00494179  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049417b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049417d  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
L_0x00494180:
    // 00494180  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00494183  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494185  83c028                 -add eax, 0x28
    (cpu.eax) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00494188  83c244                 -add edx, 0x44
    (cpu.edx) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0049418b  e8609afeff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 00494190  39f2                   +cmp edx, esi
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494192  7eec                   -jle 0x494180
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494180;
    }
L_0x00494194:
    // 00494194  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494198  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494199  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049419a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049419d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049419e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049419f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004941a0:
    // 004941a0  c6410501               -mov byte ptr [ecx + 5], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 1 /*0x1*/;
    // 004941a4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004941a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004941a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004941aa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004941ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004941ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004941af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4941b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004941b0  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004941b6  0f8414ffffff           -je 0x4940d0
    if (cpu.flags.zf)
    {
        return sub_4940d0(app, cpu);
    }
    // 004941bc  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004941c1  0f84dd490000           -je 0x498ba4
    if (cpu.flags.zf)
    {
        return sub_498ba4(app, cpu);
    }
    // 004941c7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004941cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4941d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004941d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004941d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004941d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004941d3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004941d6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004941d8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004941db  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004941dd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004941df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004941e1  7446                   -je 0x494229
    if (cpu.flags.zf)
    {
        goto L_0x00494229;
    }
    // 004941e3  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004941e9  754c                   -jne 0x494237
    if (!cpu.flags.zf)
    {
        goto L_0x00494237;
    }
    // 004941eb  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004941ef  754d                   -jne 0x49423e
    if (!cpu.flags.zf)
    {
        goto L_0x0049423e;
    }
    // 004941f1  83f9ff                 +cmp ecx, -1
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
    // 004941f4  754f                   -jne 0x494245
    if (!cpu.flags.zf)
    {
        goto L_0x00494245;
    }
    // 004941f6  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
L_0x004941fb:
    // 004941fb  83fbff                 +cmp ebx, -1
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004941fe  7550                   -jne 0x494250
    if (!cpu.flags.zf)
    {
        goto L_0x00494250;
    }
    // 00494200  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
L_0x00494205:
    // 00494205  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494207  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00494209:
    // 00494209  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049420b  8a4f07                 -mov cl, byte ptr [edi + 7]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 0049420e  39c8                   +cmp eax, ecx
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
    // 00494210  0f8d60000000           -jge 0x494276
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494276;
    }
    // 00494216  8b770c                 -mov esi, dword ptr [edi + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00494219  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049421b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049421d  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049421f  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494221  7d38                   -jge 0x49425b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049425b;
    }
L_0x00494223:
    // 00494223  83c244                 +add edx, 0x44
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(68 /*0x44*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494226  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00494227  ebe0                   -jmp 0x494209
    goto L_0x00494209;
L_0x00494229:
    // 00494229  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0049422e:
    // 0049422e  83c410                 +add esp, 0x10
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
    // 00494231  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494232  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494233  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494234  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00494237:
    // 00494237  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0049423c  ebf0                   -jmp 0x49422e
    goto L_0x0049422e;
L_0x0049423e:
    // 0049423e  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 00494243  ebe9                   -jmp 0x49422e
    goto L_0x0049422e;
L_0x00494245:
    // 00494245  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00494247  7ce0                   -jl 0x494229
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494229;
    }
    // 00494249  83f97f                 +cmp ecx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049424c  7ead                   -jle 0x4941fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004941fb;
    }
    // 0049424e  ebd9                   -jmp 0x494229
    goto L_0x00494229;
L_0x00494250:
    // 00494250  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494252  7cd5                   -jl 0x494229
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494229;
    }
    // 00494254  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494257  7eac                   -jle 0x494205
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494205;
    }
    // 00494259  ebce                   -jmp 0x494229
    goto L_0x00494229;
L_0x0049425b:
    // 0049425b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049425d  8a4e01                 -mov cl, byte ptr [esi + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00494260  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494262  7fbf                   -jg 0x494223
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494223;
    }
    // 00494264  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494266  8a4e02                 -mov cl, byte ptr [esi + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00494269  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049426b  7cb6                   -jl 0x494223
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494223;
    }
    // 0049426d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049426f  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00494272  39cb                   +cmp ebx, ecx
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494274  7fad                   -jg 0x494223
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494223;
    }
L_0x00494276:
    // 00494276  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494278  8a5707                 -mov dl, byte ptr [edi + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 0049427b  39d0                   +cmp eax, edx
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
    // 0049427d  0f8482020000           -je 0x494505
    if (cpu.flags.zf)
    {
        goto L_0x00494505;
    }
    // 00494283  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00494287  83f8ff                 +cmp eax, -1
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
    // 0049428a  0f8583020000           -jne 0x494513
    if (!cpu.flags.zf)
    {
        goto L_0x00494513;
    }
    // 00494290  c74424247f000000       -mov dword ptr [esp + 0x24], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 127 /*0x7f*/;
L_0x00494298:
    // 00494298  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049429c  83faff                 +cmp edx, -1
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
    // 0049429f  0f858d020000           -jne 0x494532
    if (!cpu.flags.zf)
    {
        goto L_0x00494532;
    }
    // 004942a5  c744242040000000       -mov dword ptr [esp + 0x20], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 64 /*0x40*/;
L_0x004942ad:
    // 004942ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004942af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004942b1  8a570a                 -mov dl, byte ptr [edi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004942b4  8a4610                 -mov al, byte ptr [esi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004942b7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004942b9  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004942bc  8a5611                 -mov dl, byte ptr [esi + 0x11]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(17) /* 0x11 */);
    // 004942bf  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004942c3  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004942c5  7415                   -je 0x4942dc
    if (cpu.flags.zf)
    {
        goto L_0x004942dc;
    }
    // 004942c7  8b460e                 -mov eax, dword ptr [esi + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004942ca  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004942cd  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004942d1  e80a090100             -call 0x4a4be0
    cpu.esp -= 4;
    sub_4a4be0(app, cpu);
    if (cpu.terminate) return;
    // 004942d6  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004942d8  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004942dc:
    // 004942dc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004942e0  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004942e3  0f8e68020000           -jle 0x494551
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494551;
    }
    // 004942e9  c744240c7f000000       -mov dword ptr [esp + 0xc], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 127 /*0x7f*/;
L_0x004942f1:
    // 004942f1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004942f5  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 004942f9  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004942fc  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00494300  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494302  0f8c5c020000           -jl 0x494564
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494564;
    }
    // 00494308  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049430b  7e08                   -jle 0x494315
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494315;
    }
    // 0049430d  c74424207f000000       -mov dword ptr [esp + 0x20], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 127 /*0x7f*/;
L_0x00494315:
    // 00494315  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00494318  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049431a  740b                   -je 0x494327
    if (cpu.flags.zf)
    {
        goto L_0x00494327;
    }
    // 0049431c  03442420               -add eax, dword ptr [esp + 0x20]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)));
    // 00494320  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 00494323  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00494327:
    // 00494327  837c2428ff             +cmp dword ptr [esp + 0x28], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049432c  7509                   -jne 0x494337
    if (!cpu.flags.zf)
    {
        goto L_0x00494337;
    }
    // 0049432e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494330  8a460c                 -mov al, byte ptr [esi + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00494333  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x00494337:
    // 00494337  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0049433a  8b5612                 -mov edx, dword ptr [esi + 0x12]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0049433d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00494340  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00494343  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494345  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494347  8a5609                 -mov dl, byte ptr [esi + 9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0049434a  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049434c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00494350  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00494357  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00494359  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0049435c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049435e  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494362  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00494365  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00494367  668b5616               -mov dx, word ptr [esi + 0x16]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 0049436b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049436f  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00494372  7412                   -je 0x494386
    if (cpu.flags.zf)
    {
        goto L_0x00494386;
    }
    // 00494374  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00494377  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049437a  e861080100             -call 0x4a4be0
    cpu.esp -= 4;
    sub_4a4be0(app, cpu);
    if (cpu.terminate) return;
    // 0049437f  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00494382  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00494386:
    // 00494386  e865050000             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 0049438b  b9608a5200             -mov ecx, 0x528a60
    cpu.ecx = 5409376 /*0x528a60*/;
    // 00494390  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00494393  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494395  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494397  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0049439a  8a560f                 -mov dl, byte ptr [esi + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(15) /* 0xf */);
    // 0049439d  e8aa050000             -call 0x49494c
    cpu.esp -= 4;
    sub_49494c(app, cpu);
    if (cpu.terminate) return;
    // 004943a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004943a4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004943a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004943aa  0f8cbf010000           -jl 0x49456f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049456f;
    }
    // 004943b0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004943b3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004943b5  bb00845200             -mov ebx, 0x528400
    cpu.ebx = 5407744 /*0x528400*/;
    // 004943ba  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004943bd  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004943bf  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004943c2  89434c                 -mov dword ptr [ebx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004943c5  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004943c8  894350                 -mov dword ptr [ebx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004943cb  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004943ce  894354                 -mov dword ptr [ebx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 004943d1  8a4706                 -mov al, byte ptr [edi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004943d4  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004943d7  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004943db  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004943e2  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004943e5  894320                 -mov dword ptr [ebx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004943e8  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004943eb  8b560f                 -mov edx, dword ptr [esi + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(15) /* 0xf */);
    // 004943ee  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004943f1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004943f4  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004943f7  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004943fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004943fe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00494401  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00494403  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494405  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00494408  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049440b  e8d0070100             -call 0x4a4be0
    cpu.esp -= 4;
    sub_4a4be0(app, cpu);
    if (cpu.terminate) return;
    // 00494410  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494412  39ca                   +cmp edx, ecx
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
    // 00494414  0f8e65010000           -jle 0x49457f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049457f;
    }
    // 0049441a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0049441c:
    // 0049441c  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0049441f  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
    // 00494424  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494426  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00494429  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049442b  884330                 -mov byte ptr [ebx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 0049442e  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494432  884332                 -mov byte ptr [ebx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 00494435  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00494439  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 0049443c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494440  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 00494444  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494446  8a460d                 -mov al, byte ptr [esi + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00494449  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 0049444c  66894342               -mov word ptr [ebx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 00494450  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00494454  884333                 -mov byte ptr [ebx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 00494457  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049445b  e800810000             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
    // 00494460  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 00494463  894348                 -mov dword ptr [ebx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00494466  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 00494469  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00494470  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00494472  89432c                 -mov dword ptr [ebx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00494475  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 00494478  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049447b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049447e  c6433500               -mov byte ptr [ebx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 00494482  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00494485  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00494488  884334                 -mov byte ptr [ebx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 0049448b  8a460b                 -mov al, byte ptr [esi + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */);
    // 0049448e  884336                 -mov byte ptr [ebx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 00494491  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00494494  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494496  88430a                 -mov byte ptr [ebx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 00494499  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049449d  c6430b0f               -mov byte ptr [ebx + 0xb], 0xf
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = 15 /*0xf*/;
    // 004944a1  e8ea490000             -call 0x498e90
    cpu.esp -= 4;
    sub_498e90(app, cpu);
    if (cpu.terminate) return;
    // 004944a6  8b0df4835200           -mov ecx, dword ptr [0x5283f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5407732) /* 0x5283f4 */);
    // 004944ac  8a560e                 -mov dl, byte ptr [esi + 0xe]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004944af  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004944b2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004944b4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004944b7  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004944b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004944ba  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004944bd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004944c0  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004944c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004944c5  8b432e                 -mov eax, dword ptr [ebx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(46) /* 0x2e */);
    // 004944c8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004944ca  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004944cd  8a5706                 -mov dl, byte ptr [edi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004944d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004944d1  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004944d5  8d4628                 -lea eax, [esi + 0x28]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004944d8  e8df98feff             -call 0x47ddbc
    cpu.esp -= 4;
    sub_47ddbc(app, cpu);
    if (cpu.terminate) return;
    // 004944dd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004944df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004944e1  7d0f                   -jge 0x4944f2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004944f2;
    }
    // 004944e3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004944e7  e81c070000             -call 0x494c08
    cpu.esp -= 4;
    sub_494c08(app, cpu);
    if (cpu.terminate) return;
    // 004944ec  8915608a5200           -mov dword ptr [0x528a60], edx
    app->getMemory<x86::reg32>(x86::reg32(5409376) /* 0x528a60 */) = cpu.edx;
L_0x004944f2:
    // 004944f2  e80d040000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 004944f7  a1608a5200             -mov eax, dword ptr [0x528a60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409376) /* 0x528a60 */);
    // 004944fc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004944ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494500  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494501  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494502  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00494505:
    // 00494505  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049450a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049450d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049450e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049450f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494510  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00494513:
    // 00494513  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494515  0f8c0efdffff           -jl 0x494229
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494229;
    }
    // 0049451b  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049451e  0f8e74fdffff           -jle 0x494298
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494298;
    }
    // 00494524  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00494529  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049452c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049452d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049452e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049452f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00494532:
    // 00494532  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00494534  0f8ceffcffff           -jl 0x494229
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494229;
    }
    // 0049453a  83fa7f                 +cmp edx, 0x7f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049453d  0f8e6afdffff           -jle 0x4942ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004942ad;
    }
    // 00494543  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00494548  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049454b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049454c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049454d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049454e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00494551:
    // 00494551  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494553  0f8d98fdffff           -jge 0x4942f1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004942f1;
    }
    // 00494559  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0049455b  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0049455f  e98dfdffff             -jmp 0x4942f1
    goto L_0x004942f1;
L_0x00494564:
    // 00494564  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00494566  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049456a  e9a6fdffff             -jmp 0x494315
    goto L_0x00494315;
L_0x0049456f:
    // 0049456f  e890030000             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00494574  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494576  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00494579  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049457a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049457b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049457c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049457f:
    // 0049457f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00494581  0f8d95feffff           -jge 0x49441c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049441c;
    }
    // 00494587  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00494589  e98efeffff             -jmp 0x49441c
    goto L_0x0049441c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_494590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494590  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494592  7419                   -je 0x4945ad
    if (cpu.flags.zf)
    {
        goto L_0x004945ad;
    }
    // 00494594  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049459a  7417                   -je 0x4945b3
    if (cpu.flags.zf)
    {
        goto L_0x004945b3;
    }
    // 0049459c  6681385054             +cmp word ptr [eax], 0x5450
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004945a1  0f841d420000           -je 0x4987c4
    if (cpu.flags.zf)
    {
        return sub_4987c4(app, cpu);
    }
    // 004945a7  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004945ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004945ad:
    // 004945ad  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004945b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004945b3:
    // 004945b3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004945b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004945b5  8b4a06                 -mov ecx, dword ptr [edx + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 004945b8  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004945bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004945bc  8b4a05                 -mov ecx, dword ptr [edx + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5) /* 0x5 */);
    // 004945bf  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004945c2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004945c3  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004945c6  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004945c9  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004945cc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004945cf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004945d0  8b4a03                 -mov ecx, dword ptr [edx + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 004945d3  8b5201                 -mov edx, dword ptr [edx + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004945d6  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 004945d9  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004945dc  e8effbffff             -call 0x4941d0
    cpu.esp -= 4;
    sub_4941d0(app, cpu);
    if (cpu.terminate) return;
    // 004945e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004945e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4945f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004945f0  a3648a5200             -mov dword ptr [0x528a64], eax
    app->getMemory<x86::reg32>(x86::reg32(5409380) /* 0x528a64 */) = cpu.eax;
    // 004945f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4945f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004945f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004945f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004945fa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004945fc  833da0ab4c0000         +cmp dword ptr [0x4caba0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494603  741c                   -je 0x494621
    if (cpu.flags.zf)
    {
        goto L_0x00494621;
    }
L_0x00494605:
    // 00494605  833d648a520000         +cmp dword ptr [0x528a64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5409380) /* 0x528a64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049460c  741f                   -je 0x49462d
    if (cpu.flags.zf)
    {
        goto L_0x0049462d;
    }
    // 0049460e  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00494610  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494612  893d9cab4c00           -mov dword ptr [0x4cab9c], edi
    app->getMemory<x86::reg32>(x86::reg32(5024668) /* 0x4cab9c */) = cpu.edi;
    // 00494618  ff15648a5200           -call dword ptr [0x528a64]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5409380) /* 0x528a64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049461e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049461f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494620  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494621:
    // 00494621  e8a6a8feff             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 00494626  a3a0ab4c00             -mov dword ptr [0x4caba0], eax
    app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */) = cpu.eax;
    // 0049462b  ebd8                   -jmp 0x494605
    goto L_0x00494605;
L_0x0049462d:
    // 0049462d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049462e  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00494633  8b15a0ab4c00           -mov edx, dword ptr [0x4caba0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */);
    // 00494639  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049463b  89359cab4c00           -mov dword ptr [0x4cab9c], esi
    app->getMemory<x86::reg32>(x86::reg32(5024668) /* 0x4cab9c */) = cpu.esi;
    // 00494641  e89aa8feff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00494646  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494647  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494648  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494649  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49464a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049464a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049464c  e82f3afeff             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00494651  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00494653  8b2d34824c00           -mov ebp, dword ptr [0x4c8234]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 00494659  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049465b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049465e  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00494660  e8f7a5feff             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00494665  e979000000             -jmp 0x4946e3
    return sub_4946e3(app, cpu);
}

/* align: skip  */
void Application::sub_49466a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049466a  8b15a0ab4c00           -mov edx, dword ptr [0x4caba0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */);
    // 00494670  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00494672  0f8481000000           -je 0x4946f9
    if (cpu.flags.zf)
    {
        return sub_4946f9(app, cpu);
    }
    // 00494678  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049467a  e89da8feff             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 0049467f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494680  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494681  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494682  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494683  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494684  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494688(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494688  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00494689  8b15a0ab4c00           -mov edx, dword ptr [0x4caba0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */);
    // 0049468f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00494691  7502                   -jne 0x494695
    if (!cpu.flags.zf)
    {
        goto L_0x00494695;
    }
    // 00494693  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494694  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494695:
    // 00494695  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494696  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0049469b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049469d  890d9cab4c00           -mov dword ptr [0x4cab9c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024668) /* 0x4cab9c */) = cpu.ecx;
    // 004946a3  e838a8feff             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 004946a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4946ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004946ac  a19cab4c00             -mov eax, dword ptr [0x4cab9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024668) /* 0x4cab9c */);
    // 004946b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4946b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004946b4  833d648a520000         +cmp dword ptr [0x528a64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5409380) /* 0x528a64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946bb  7409                   -je 0x4946c6
    if (cpu.flags.zf)
    {
        goto L_0x004946c6;
    }
    // 004946bd  833d34824c0000         +cmp dword ptr [0x4c8234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946c4  7501                   -jne 0x4946c7
    if (!cpu.flags.zf)
    {
        goto L_0x004946c7;
    }
L_0x004946c6:
    // 004946c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004946c7:
    // 004946c7  e82cffffff             -call 0x4945f8
    cpu.esp -= 4;
    sub_4945f8(app, cpu);
    if (cpu.terminate) return;
    // 004946cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004946cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004946ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004946cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004946d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004946d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004946d3  e8d0a5feff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 004946d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004946da  748e                   -je 0x49466a
    if (cpu.flags.zf)
    {
        return sub_49466a(app, cpu);
    }
    // 004946dc  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004946e1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004946e3  3b0da0ab4c00           +cmp ecx, dword ptr [0x4caba0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946e9  740e                   -je 0x4946f9
    if (cpu.flags.zf)
    {
        goto L_0x004946f9;
    }
    // 004946eb  8b3d9cab4c00           -mov edi, dword ptr [0x4cab9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024668) /* 0x4cab9c */);
    // 004946f1  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946f3  0f8451ffffff           -je 0x49464a
    if (cpu.flags.zf)
    {
        return sub_49464a(app, cpu);
    }
L_0x004946f9:
    // 004946f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4946f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004946f9;
    // 004946b4  833d648a520000         +cmp dword ptr [0x528a64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5409380) /* 0x528a64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946bb  7409                   -je 0x4946c6
    if (cpu.flags.zf)
    {
        goto L_0x004946c6;
    }
    // 004946bd  833d34824c0000         +cmp dword ptr [0x4c8234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946c4  7501                   -jne 0x4946c7
    if (!cpu.flags.zf)
    {
        goto L_0x004946c7;
    }
L_0x004946c6:
    // 004946c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004946c7:
    // 004946c7  e82cffffff             -call 0x4945f8
    cpu.esp -= 4;
    sub_4945f8(app, cpu);
    if (cpu.terminate) return;
    // 004946cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004946cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004946ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004946cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004946d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004946d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004946d3  e8d0a5feff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 004946d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004946da  748e                   -je 0x49466a
    if (cpu.flags.zf)
    {
        return sub_49466a(app, cpu);
    }
    // 004946dc  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004946e1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004946e3  3b0da0ab4c00           +cmp ecx, dword ptr [0x4caba0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946e9  740e                   -je 0x4946f9
    if (cpu.flags.zf)
    {
        goto L_0x004946f9;
    }
    // 004946eb  8b3d9cab4c00           -mov edi, dword ptr [0x4cab9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024668) /* 0x4cab9c */);
    // 004946f1  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946f3  0f8451ffffff           -je 0x49464a
    if (cpu.flags.zf)
    {
        return sub_49464a(app, cpu);
    }
L_0x004946f9:
L_entry_0x004946f9:
    // 004946f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4946e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004946e3;
    // 004946b4  833d648a520000         +cmp dword ptr [0x528a64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5409380) /* 0x528a64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946bb  7409                   -je 0x4946c6
    if (cpu.flags.zf)
    {
        goto L_0x004946c6;
    }
    // 004946bd  833d34824c0000         +cmp dword ptr [0x4c8234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946c4  7501                   -jne 0x4946c7
    if (!cpu.flags.zf)
    {
        goto L_0x004946c7;
    }
L_0x004946c6:
    // 004946c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004946c7:
    // 004946c7  e82cffffff             -call 0x4945f8
    cpu.esp -= 4;
    sub_4945f8(app, cpu);
    if (cpu.terminate) return;
    // 004946cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004946cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004946ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004946cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004946d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004946d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004946d3  e8d0a5feff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 004946d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004946da  748e                   -je 0x49466a
    if (cpu.flags.zf)
    {
        return sub_49466a(app, cpu);
    }
    // 004946dc  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004946e1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x004946e3:
    // 004946e3  3b0da0ab4c00           +cmp ecx, dword ptr [0x4caba0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946e9  740e                   -je 0x4946f9
    if (cpu.flags.zf)
    {
        goto L_0x004946f9;
    }
    // 004946eb  8b3d9cab4c00           -mov edi, dword ptr [0x4cab9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024668) /* 0x4cab9c */);
    // 004946f1  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946f3  0f8451ffffff           -je 0x49464a
    if (cpu.flags.zf)
    {
        return sub_49464a(app, cpu);
    }
L_0x004946f9:
    // 004946f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4946cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004946cc;
    // 004946b4  833d648a520000         +cmp dword ptr [0x528a64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5409380) /* 0x528a64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946bb  7409                   -je 0x4946c6
    if (cpu.flags.zf)
    {
        goto L_0x004946c6;
    }
    // 004946bd  833d34824c0000         +cmp dword ptr [0x4c8234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946c4  7501                   -jne 0x4946c7
    if (!cpu.flags.zf)
    {
        goto L_0x004946c7;
    }
L_0x004946c6:
    // 004946c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004946c7:
    // 004946c7  e82cffffff             -call 0x4945f8
    cpu.esp -= 4;
    sub_4945f8(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004946cc:
    // 004946cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004946cd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004946ce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004946cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004946d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004946d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004946d3  e8d0a5feff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 004946d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004946da  748e                   -je 0x49466a
    if (cpu.flags.zf)
    {
        return sub_49466a(app, cpu);
    }
    // 004946dc  bbe8030000             -mov ebx, 0x3e8
    cpu.ebx = 1000 /*0x3e8*/;
    // 004946e1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004946e3  3b0da0ab4c00           +cmp ecx, dword ptr [0x4caba0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024672) /* 0x4caba0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946e9  740e                   -je 0x4946f9
    if (cpu.flags.zf)
    {
        goto L_0x004946f9;
    }
    // 004946eb  8b3d9cab4c00           -mov edi, dword ptr [0x4cab9c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024668) /* 0x4cab9c */);
    // 004946f1  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004946f3  0f8451ffffff           -je 0x49464a
    if (cpu.flags.zf)
    {
        return sub_49464a(app, cpu);
    }
L_0x004946f9:
    // 004946f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004946fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_494700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494701  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494702  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00494703  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494704  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494705  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494706  ff05acab4c00           -inc dword ptr [0x4cabac]
    (app->getMemory<x86::reg32>(x86::reg32(5024684) /* 0x4cabac */))++;
    // 0049470c  ff05588a5200           -inc dword ptr [0x528a58]
    (app->getMemory<x86::reg32>(x86::reg32(5409368) /* 0x528a58 */))++;
    // 00494712  e8a59cfeff             -call 0x47e3bc
    cpu.esp -= 4;
    sub_47e3bc(app, cpu);
    if (cpu.terminate) return;
    // 00494717  833d7cab4c0000         +cmp dword ptr [0x4cab7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024636) /* 0x4cab7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049471e  0f8524010000           -jne 0x494848
    if (!cpu.flags.zf)
    {
        goto L_0x00494848;
    }
L_0x00494724:
    // 00494724  833d70ab4c0000         +cmp dword ptr [0x4cab70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024624) /* 0x4cab70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049472b  7406                   -je 0x494733
    if (cpu.flags.zf)
    {
        goto L_0x00494733;
    }
    // 0049472d  ff1570ab4c00           -call dword ptr [0x4cab70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5024624) /* 0x4cab70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00494733:
    // 00494733  833d74ab4c0000         +cmp dword ptr [0x4cab74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024628) /* 0x4cab74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049473a  0f8513010000           -jne 0x494853
    if (!cpu.flags.zf)
    {
        goto L_0x00494853;
    }
L_0x00494740:
    // 00494740  be00845200             -mov esi, 0x528400
    cpu.esi = 5407744 /*0x528400*/;
    // 00494745  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00494747:
    // 00494747  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049474a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0049474c  80fc01                 +cmp ah, 1
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049474f  0f85ba000000           -jne 0x49480f
    if (!cpu.flags.zf)
    {
        goto L_0x0049480f;
    }
    // 00494755  833e00                 +cmp dword ptr [esi], 0
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
    // 00494758  0f8cb1000000           -jl 0x49480f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049480f;
    }
    // 0049475e  837e5c00               +cmp dword ptr [esi + 0x5c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494762  7425                   -je 0x494789
    if (cpu.flags.zf)
    {
        goto L_0x00494789;
    }
    // 00494764  8a563f                 -mov dl, byte ptr [esi + 0x3f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */);
    // 00494767  fec2                   -inc dl
    (cpu.dl)++;
    // 00494769  88563f                 -mov byte ptr [esi + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = cpu.dl;
    // 0049476c  3a563d                 +cmp dl, byte ptr [esi + 0x3d]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(61) /* 0x3d */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049476f  7204                   -jb 0x494775
    if (cpu.flags.cf)
    {
        goto L_0x00494775;
    }
    // 00494771  c6463f00               -mov byte ptr [esi + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
L_0x00494775:
    // 00494775  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494777  e8e47d0000             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
    // 0049477c  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049477f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494781  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00494784  e8c79ffeff             -call 0x47e750
    cpu.esp -= 4;
    sub_47e750(app, cpu);
    if (cpu.terminate) return;
L_0x00494789:
    // 00494789  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 0049478c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049478e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00494790  7418                   -je 0x4947aa
    if (cpu.flags.zf)
    {
        goto L_0x004947aa;
    }
    // 00494792  8a413e                 -mov al, byte ptr [ecx + 0x3e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 00494795  fec0                   -inc al
    (cpu.al)++;
    // 00494797  88413e                 -mov byte ptr [ecx + 0x3e], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.al;
    // 0049479a  8a613c                 -mov ah, byte ptr [ecx + 0x3c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */);
    // 0049479d  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004947a2  38e0                   +cmp al, ah
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004947a4  7204                   -jb 0x4947aa
    if (cpu.flags.cf)
    {
        goto L_0x004947aa;
    }
    // 004947a6  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
L_0x004947aa:
    // 004947aa  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004947ad  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004947af  7431                   -je 0x4947e2
    if (cpu.flags.zf)
    {
        goto L_0x004947e2;
    }
    // 004947b1  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004947b4  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004947b9  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004947bb  8b6918                 -mov ebp, dword ptr [ecx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004947be  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004947c1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004947c3  0f8c95000000           -jl 0x49485e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049485e;
    }
    // 004947c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004947cb  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004947ce  39d0                   +cmp eax, edx
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
    // 004947d0  7c0a                   -jl 0x4947dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004947dc;
    }
    // 004947d2  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004947d9  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x004947dc:
    // 004947dc  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004947e0  7c26                   -jl 0x494808
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494808;
    }
L_0x004947e2:
    // 004947e2  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004947e5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004947e7  7408                   -je 0x4947f1
    if (cpu.flags.zf)
    {
        goto L_0x004947f1;
    }
    // 004947e9  015128                 -add dword ptr [ecx + 0x28], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004947ec  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x004947f1:
    // 004947f1  83792c00               +cmp dword ptr [ecx + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004947f5  0f85ac000000           -jne 0x4948a7
    if (!cpu.flags.zf)
    {
        goto L_0x004948a7;
    }
    // 004947fb  8a5135                 -mov dl, byte ptr [ecx + 0x35]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 004947fe  fec2                   -inc dl
    (cpu.dl)++;
    // 00494800  885135                 -mov byte ptr [ecx + 0x35], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = cpu.dl;
    // 00494803  3a5134                 +cmp dl, byte ptr [ecx + 0x34]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494806  7c70                   -jl 0x494878
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494878;
    }
L_0x00494808:
    // 00494808  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0049480a  e8f1a0feff             -call 0x47e900
    cpu.esp -= 4;
    sub_47e900(app, cpu);
    if (cpu.terminate) return;
L_0x0049480f:
    // 0049480f  43                     -inc ebx
    (cpu.ebx)++;
    // 00494810  83c660                 -add esi, 0x60
    (cpu.esi) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00494813  83fb10                 +cmp ebx, 0x10
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494816  0f8c2bffffff           -jl 0x494747
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494747;
    }
    // 0049481c  833d78ab4c0000         +cmp dword ptr [0x4cab78], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024632) /* 0x4cab78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494823  7416                   -je 0x49483b
    if (cpu.flags.zf)
    {
        goto L_0x0049483b;
    }
    // 00494825  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0049482a  a1588a5200             -mov eax, dword ptr [0x528a58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409368) /* 0x528a58 */);
    // 0049482f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00494831  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00494833  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00494835  0f84a2000000           -je 0x4948dd
    if (cpu.flags.zf)
    {
        goto L_0x004948dd;
    }
L_0x0049483b:
    // 0049483b  ff0dacab4c00           +dec dword ptr [0x4cabac]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5024684) /* 0x4cabac */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00494841  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494842  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494843  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494844  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494845  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494846  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494847  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494848:
    // 00494848  ff157cab4c00           -call dword ptr [0x4cab7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5024636) /* 0x4cab7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049484e  e9d1feffff             -jmp 0x494724
    goto L_0x00494724;
L_0x00494853:
    // 00494853  ff1574ab4c00           -call dword ptr [0x4cab74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5024628) /* 0x4cab74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00494859  e9e2feffff             -jmp 0x494740
    goto L_0x00494740;
L_0x0049485e:
    // 0049485e  8b691c                 -mov ebp, dword ptr [ecx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00494861  39ea                   +cmp edx, ebp
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494863  0f8f73ffffff           -jg 0x4947dc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004947dc;
    }
    // 00494869  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00494870  896920                 -mov dword ptr [ecx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 00494873  e964ffffff             -jmp 0x4947dc
    goto L_0x004947dc;
L_0x00494878:
    // 00494878  8b4132                 -mov eax, dword ptr [ecx + 0x32]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(50) /* 0x32 */);
    // 0049487b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049487e  8b5148                 -mov edx, dword ptr [ecx + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 00494881  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00494884  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494886  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00494888  89512c                 -mov dword ptr [ecx + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0049488b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049488d  7c45                   -jl 0x4948d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004948d4;
    }
L_0x0049488f:
    // 0049488f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00494892  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00494895  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00494898  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049489a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049489c  8b692c                 -mov ebp, dword ptr [ecx + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 0049489f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004948a2  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004948a4  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004948a7:
    // 004948a7  ff492c                 -dec dword ptr [ecx + 0x2c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */))--;
    // 004948aa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004948ac  0f845dffffff           -je 0x49480f
    if (cpu.flags.zf)
    {
        goto L_0x0049480f;
    }
    // 004948b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004948b4  e8d7450000             -call 0x498e90
    cpu.esp -= 4;
    sub_498e90(app, cpu);
    if (cpu.terminate) return;
    // 004948b9  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004948bc  0f8c4dffffff           -jl 0x49480f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049480f;
    }
    // 004948c2  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004948c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004948c7  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004948ca  e8959cfeff             -call 0x47e564
    cpu.esp -= 4;
    sub_47e564(app, cpu);
    if (cpu.terminate) return;
    // 004948cf  e93bffffff             -jmp 0x49480f
    goto L_0x0049480f;
L_0x004948d4:
    // 004948d4  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 004948db  ebb2                   -jmp 0x49488f
    goto L_0x0049488f;
L_0x004948dd:
    // 004948dd  ff1578ab4c00           -call dword ptr [0x4cab78]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5024632) /* 0x4cab78 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004948e3  ff0dacab4c00           -dec dword ptr [0x4cabac]
    (app->getMemory<x86::reg32>(x86::reg32(5024684) /* 0x4cabac */))--;
    // 004948e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004948ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4948f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004948f0  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 004948f5  e80ea7feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004948fa  ff05b0ab4c00           -inc dword ptr [0x4cabb0]
    (app->getMemory<x86::reg32>(x86::reg32(5024688) /* 0x4cabb0 */))++;
    // 00494900  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_494904(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494904  ff0db0ab4c00           +dec dword ptr [0x4cabb0]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5024688) /* 0x4cabb0 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049490a  a1508a5200             -mov eax, dword ptr [0x528a50]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409360) /* 0x528a50 */);
    // 0049490f  e90ca7feff             -jmp 0x47f020
    return sub_47f020(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_494920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494922  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00494924  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00494926  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494928  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049492a  7e12                   -jle 0x49493e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049493e;
    }
L_0x0049492c:
    // 0049492c  8b90658a5200           -mov edx, dword ptr [eax + 0x528a65]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5409381) /* 0x528a65 */);
    // 00494932  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00494935  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494937  740a                   -je 0x494943
    if (cpu.flags.zf)
    {
        goto L_0x00494943;
    }
    // 00494939  40                     -inc eax
    (cpu.eax)++;
    // 0049493a  39c8                   +cmp eax, ecx
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
    // 0049493c  7cee                   -jl 0x49492c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049492c;
    }
L_0x0049493e:
    // 0049493e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494940  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494941  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494942  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494943:
    // 00494943  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494948  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494949  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049494a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49494c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049494c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049494d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049494e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049494f  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00494952  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00494956  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0049495a  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0049495e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00494962  baf7ffffff             -mov edx, 0xfffffff7
    cpu.edx = 4294967287 /*0xfffffff7*/;
    // 00494967  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049496b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049496d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049496f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00494973  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00494976  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494978  7e12                   -jle 0x49498c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049498c;
    }
    // 0049497a  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 0049497c  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x00494980:
    // 00494980  40                     -inc eax
    (cpu.eax)++;
    // 00494981  8890678a5200           -mov byte ptr [eax + 0x528a67], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5409383) /* 0x528a67 */) = cpu.dl;
    // 00494987  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494989  7cf5                   -jl 0x494980
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494980;
    }
    // 0049498b  90                     -nop 
    ;
L_0x0049498c:
    // 0049498c  8b3db4ab4c00           -mov edi, dword ptr [0x4cabb4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024692) /* 0x4cabb4 */);
    // 00494992  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00494995  893db4ab4c00           -mov dword ptr [0x4cabb4], edi
    app->getMemory<x86::reg32>(x86::reg32(5024692) /* 0x4cabb4 */) = cpu.edi;
    // 0049499b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049499d  7c2b                   -jl 0x4949ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004949ca;
    }
L_0x0049499f:
    // 0049499f  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004949a3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004949a5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004949a7:
    // 004949a7  a16aab4c00             -mov eax, dword ptr [0x4cab6a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024618) /* 0x4cab6a */);
    // 004949ac  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004949af  39c3                   +cmp ebx, eax
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
    // 004949b1  7d4a                   -jge 0x4949fd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004949fd;
    }
    // 004949b3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004949b8  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004949ba  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004949be  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004949c0  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 004949c2  750f                   -jne 0x4949d3
    if (!cpu.flags.zf)
    {
        goto L_0x004949d3;
    }
L_0x004949c4:
    // 004949c4  83c660                 +add esi, 0x60
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004949c7  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004949c8  ebdd                   -jmp 0x4949a7
    goto L_0x004949a7;
L_0x004949ca:
    // 004949ca  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004949cc  a3b4ab4c00             -mov dword ptr [0x4cabb4], eax
    app->getMemory<x86::reg32>(x86::reg32(5024692) /* 0x4cabb4 */) = cpu.eax;
    // 004949d1  ebcc                   -jmp 0x49499f
    goto L_0x0049499f;
L_0x004949d3:
    // 004949d3  80be0c84520000         +cmp byte ptr [esi + 0x52840c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5407756) /* 0x52840c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004949da  75e8                   -jne 0x4949c4
    if (!cpu.flags.zf)
    {
        goto L_0x004949c4;
    }
    // 004949dc  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004949df  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004949e1  e83affffff             -call 0x494920
    cpu.esp -= 4;
    sub_494920(app, cpu);
    if (cpu.terminate) return;
    // 004949e6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004949e8  75da                   -jne 0x4949c4
    if (!cpu.flags.zf)
    {
        goto L_0x004949c4;
    }
    // 004949ea  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004949ed  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004949f0  8898688a5200           -mov byte ptr [eax + 0x528a68], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5409384) /* 0x528a68 */) = cpu.bl;
    // 004949f6  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004949f9  39f9                   +cmp ecx, edi
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004949fb  7cc7                   -jl 0x4949c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004949c4;
    }
L_0x004949fd:
    // 004949fd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00494a00  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494a04  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00494a08  39e8                   +cmp eax, ebp
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a0a  0f8d94000000           -jge 0x494aa4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494aa4;
    }
L_0x00494a10:
    // 00494a10  bf66000000             -mov edi, 0x66
    cpu.edi = 102 /*0x66*/;
    // 00494a15  bdffffff7f             -mov ebp, 0x7fffffff
    cpu.ebp = 2147483647 /*0x7fffffff*/;
    // 00494a1a  be00845200             -mov esi, 0x528400
    cpu.esi = 5407744 /*0x528400*/;
    // 00494a1f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494a21  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494a23  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
L_0x00494a27:
    // 00494a27  a16aab4c00             -mov eax, dword ptr [0x4cab6a]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024618) /* 0x4cab6a */);
    // 00494a2c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00494a2f  39c3                   +cmp ebx, eax
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
    // 00494a31  7d48                   -jge 0x494a7b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494a7b;
    }
    // 00494a33  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494a38  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00494a3a  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00494a3e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00494a40  85d0                   +test eax, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edx));
    // 00494a42  7506                   -jne 0x494a4a
    if (!cpu.flags.zf)
    {
        goto L_0x00494a4a;
    }
L_0x00494a44:
    // 00494a44  83c660                 +add esi, 0x60
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494a47  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00494a48  ebdd                   -jmp 0x494a27
    goto L_0x00494a27;
L_0x00494a4a:
    // 00494a4a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494a4d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494a4f  e8ccfeffff             -call 0x494920
    cpu.esp -= 4;
    sub_494920(app, cpu);
    if (cpu.terminate) return;
    // 00494a54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00494a56  75ec                   -jne 0x494a44
    if (!cpu.flags.zf)
    {
        goto L_0x00494a44;
    }
    // 00494a58  8a460e                 -mov al, byte ptr [esi + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 00494a5b  39f8                   +cmp eax, edi
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
    // 00494a5d  7d0b                   -jge 0x494a6a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494a6a;
    }
    // 00494a5f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00494a61  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00494a65  8b6e14                 -mov ebp, dword ptr [esi + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00494a68  ebda                   -jmp 0x494a44
    goto L_0x00494a44;
L_0x00494a6a:
    // 00494a6a  75d8                   -jne 0x494a44
    if (!cpu.flags.zf)
    {
        goto L_0x00494a44;
    }
    // 00494a6c  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00494a6f  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a71  7ed1                   -jle 0x494a44
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494a44;
    }
    // 00494a73  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00494a75  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00494a79  ebc9                   -jmp 0x494a44
    goto L_0x00494a44;
L_0x00494a7b:
    // 00494a7b  3b7c2410               +cmp edi, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494a7f  0f8fe2000000           -jg 0x494b67
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00494b67;
    }
    // 00494a85  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00494a89  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494a8c  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494a90  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00494a93  8883688a5200           -mov byte ptr [ebx + 0x528a68], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5409384) /* 0x528a68 */) = cpu.al;
    // 00494a99  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00494a9c  39fe                   +cmp esi, edi
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
    // 00494a9e  0f8cc3000000           -jl 0x494b67
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494b67;
    }
L_0x00494aa4:
    // 00494aa4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00494aa7  3b442418               +cmp eax, dword ptr [esp + 0x18]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494aab  0f85ab000000           -jne 0x494b5c
    if (!cpu.flags.zf)
    {
        goto L_0x00494b5c;
    }
    // 00494ab1  8b1d658a5200           -mov ebx, dword ptr [0x528a65]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5409381) /* 0x528a65 */);
    // 00494ab7  a1b4ab4c00             -mov eax, dword ptr [0x4cabb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024692) /* 0x4cabb4 */);
    // 00494abc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00494abf  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494ac1  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00494ac5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00494ac7  8b1d658a5200           -mov ebx, dword ptr [0x528a65]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5409381) /* 0x528a65 */);
    // 00494acd  8b3db4ab4c00           -mov edi, dword ptr [0x4cabb4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024692) /* 0x4cabb4 */);
    // 00494ad3  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00494ad6  09df                   -or edi, ebx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494ad8  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00494adf  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00494ae2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494ae4  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00494ae8  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00494aeb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494aed  89b800845200           -mov dword ptr [eax + 0x528400], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407744) /* 0x528400 */) = cpu.edi;
    // 00494af3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494af5  0f8eb4000000           -jle 0x494baf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494baf;
    }
L_0x00494afb:
    // 00494afb  8b83658a5200           -mov eax, dword ptr [ebx + 0x528a65]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5409381) /* 0x528a65 */);
    // 00494b01  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00494b04  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 00494b07  bf00845200             -mov edi, 0x528400
    cpu.edi = 5407744 /*0x528400*/;
    // 00494b0c  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494b0e  8a4f0c                 -mov cl, byte ptr [edi + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00494b11  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 00494b13  80f901                 +cmp cl, 1
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494b16  0f8576000000           -jne 0x494b92
    if (!cpu.flags.zf)
    {
        goto L_0x00494b92;
    }
    // 00494b1c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00494b1e  7c61                   -jl 0x494b81
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494b81;
    }
L_0x00494b20:
    // 00494b20  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494b22  e8d99dfeff             -call 0x47e900
    cpu.esp -= 4;
    sub_47e900(app, cpu);
    if (cpu.terminate) return;
    // 00494b27  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494b29  e83254feff             -call 0x479f60
    cpu.esp -= 4;
    sub_479f60(app, cpu);
    if (cpu.terminate) return;
    // 00494b2e  83f801                 +cmp eax, 1
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494b31  745f                   -je 0x494b92
    if (cpu.flags.zf)
    {
        goto L_0x00494b92;
    }
    // 00494b33  4b                     -dec ebx
    (cpu.ebx)--;
    // 00494b34  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494b36  7c1c                   -jl 0x494b54
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494b54;
    }
    // 00494b38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00494b3a:
    // 00494b3a  8b83658a5200           -mov eax, dword ptr [ebx + 0x528a65]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5409381) /* 0x528a65 */);
    // 00494b40  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00494b43  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 00494b46  0500845200             -add eax, 0x528400
    (cpu.eax) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 00494b4b  4b                     -dec ebx
    (cpu.ebx)--;
    // 00494b4c  88500c                 -mov byte ptr [eax + 0xc], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00494b4f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00494b51  7de7                   -jge 0x494b3a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494b3a;
    }
    // 00494b53  90                     -nop 
    ;
L_0x00494b54:
    // 00494b54  c744240cf7ffffff       -mov dword ptr [esp + 0xc], 0xfffffff7
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 4294967287 /*0xfffffff7*/;
L_0x00494b5c:
    // 00494b5c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494b60  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00494b63  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b65  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494b66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494b67:
    // 00494b67  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00494b6b  40                     -inc eax
    (cpu.eax)++;
    // 00494b6c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494b70  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00494b74  39d0                   +cmp eax, edx
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
    // 00494b76  0f8c94feffff           -jl 0x494a10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494a10;
    }
    // 00494b7c  e923ffffff             -jmp 0x494aa4
    goto L_0x00494aa4;
L_0x00494b81:
    // 00494b81  8b4741                 -mov eax, dword ptr [edi + 0x41]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(65) /* 0x41 */);
    // 00494b84  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00494b87  6bc060                 +imul eax, eax, 0x60
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 00494b8a  8bb000845200           -mov esi, dword ptr [eax + 0x528400]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5407744) /* 0x528400 */);
    // 00494b90  eb8e                   -jmp 0x494b20
    goto L_0x00494b20;
L_0x00494b92:
    // 00494b92  a1588a5200             -mov eax, dword ptr [0x528a58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5409368) /* 0x528a58 */);
    // 00494b97  c6470c01               -mov byte ptr [edi + 0xc], 1
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00494b9b  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00494b9e  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494ba2  43                     -inc ebx
    (cpu.ebx)++;
    // 00494ba3  88470e                 -mov byte ptr [edi + 0xe], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */) = cpu.al;
    // 00494ba6  3b1c24                 +cmp ebx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494ba9  0f8c4cffffff           -jl 0x494afb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494afb;
    }
L_0x00494baf:
    // 00494baf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00494bb4  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00494bb7  7da3                   -jge 0x494b5c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494b5c;
    }
    // 00494bb9  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x00494bbc:
    // 00494bbc  8b1d658a5200           -mov ebx, dword ptr [0x528a65]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5409381) /* 0x528a65 */);
    // 00494bc2  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00494bc5  6bdb60                 -imul ebx, ebx, 0x60
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 00494bc8  8a90688a5200           -mov dl, byte ptr [eax + 0x528a68]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5409384) /* 0x528a68 */);
    // 00494bce  88940303845200         -mov byte ptr [ebx + eax + 0x528403], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5407747) /* 0x528403 */ + cpu.eax * 1) = cpu.dl;
    // 00494bd5  8b98658a5200           -mov ebx, dword ptr [eax + 0x528a65]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5409381) /* 0x528a65 */);
    // 00494bdb  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00494bde  6bdb60                 -imul ebx, ebx, 0x60
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 00494be1  c78300845200ffffffff   -mov dword ptr [ebx + 0x528400], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5407744) /* 0x528400 */) = 4294967295 /*0xffffffff*/;
    // 00494beb  8a15688a5200           -mov dl, byte ptr [0x528a68]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5409384) /* 0x528a68 */);
    // 00494bf1  40                     -inc eax
    (cpu.eax)++;
    // 00494bf2  889344845200           -mov byte ptr [ebx + 0x528444], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5407812) /* 0x528444 */) = cpu.dl;
    // 00494bf8  39c8                   +cmp eax, ecx
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
    // 00494bfa  7cc0                   -jl 0x494bbc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494bbc;
    }
    // 00494bfc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00494c00  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00494c03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494c04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494c05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494c06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_494c08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494c08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494c09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494c0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00494c0b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494c0c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494c0d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494c0e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00494c10  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00494c17  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00494c1c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00494c1e  b800845200             -mov eax, 0x528400
    cpu.eax = 5407744 /*0x528400*/;
    // 00494c23  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00494c26  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494c28  8a5c023b               -mov bl, byte ptr [edx + eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */ + cpu.eax * 1);
    // 00494c2c  0fb67c023b             -movzx edi, byte ptr [edx + eax + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */ + cpu.eax * 1));
    // 00494c31  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00494c33  0f84b4000000           -je 0x494ced
    if (cpu.flags.zf)
    {
        goto L_0x00494ced;
    }
    // 00494c39  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00494c3b:
    // 00494c3b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00494c3d  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 00494c40  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c42  7515                   -jne 0x494c59
    if (!cpu.flags.zf)
    {
        goto L_0x00494c59;
    }
    // 00494c44  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c47  7c10                   -jl 0x494c59
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494c59;
    }
    // 00494c49  80780c00               +cmp byte ptr [eax + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494c4d  740a                   -je 0x494c59
    if (cpu.flags.zf)
    {
        goto L_0x00494c59;
    }
    // 00494c4f  8a783a                 -mov bh, byte ptr [eax + 0x3a]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */);
    // 00494c52  41                     -inc ecx
    (cpu.ecx)++;
    // 00494c53  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00494c55  7402                   -je 0x494c59
    if (cpu.flags.zf)
    {
        goto L_0x00494c59;
    }
    // 00494c57  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x00494c59:
    // 00494c59  42                     -inc edx
    (cpu.edx)++;
    // 00494c5a  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00494c5d  83fa10                 +cmp edx, 0x10
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c60  7cd9                   -jl 0x494c3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00494c3b;
    }
    // 00494c62  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 00494c69  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00494c6b  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 00494c6e  83f901                 +cmp ecx, 1
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
    // 00494c71  7445                   -je 0x494cb8
    if (cpu.flags.zf)
    {
        goto L_0x00494cb8;
    }
    // 00494c73  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00494c7a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00494c7c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00494c7f  80b80c84520002         +cmp byte ptr [eax + 0x52840c], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5407756) /* 0x52840c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494c86  7509                   -jne 0x494c91
    if (!cpu.flags.zf)
    {
        goto L_0x00494c91;
    }
    // 00494c88  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c8a  7405                   -je 0x494c91
    if (cpu.flags.zf)
    {
        goto L_0x00494c91;
    }
    // 00494c8c  83f902                 +cmp ecx, 2
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494c8f  7431                   -je 0x494cc2
    if (cpu.flags.zf)
    {
        goto L_0x00494cc2;
    }
L_0x00494c91:
    // 00494c91  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00494c98  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00494c9a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00494c9d  80b80c84520001         +cmp byte ptr [eax + 0x52840c], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5407756) /* 0x52840c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494ca4  752c                   -jne 0x494cd2
    if (!cpu.flags.zf)
    {
        goto L_0x00494cd2;
    }
    // 00494ca6  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494ca8  7528                   -jne 0x494cd2
    if (!cpu.flags.zf)
    {
        goto L_0x00494cd2;
    }
    // 00494caa  c6800c84520002         -mov byte ptr [eax + 0x52840c], 2
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5407756) /* 0x52840c */) = 2 /*0x2*/;
L_0x00494cb1:
    // 00494cb1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cb2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cb3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cb4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cb6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494cb8:
    // 00494cb8  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00494cba  88830c845200           -mov byte ptr [ebx + 0x52840c], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5407756) /* 0x52840c */) = cpu.al;
    // 00494cc0  ebef                   -jmp 0x494cb1
    goto L_0x00494cb1;
L_0x00494cc2:
    // 00494cc2  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00494cc4  888b0c845200           -mov byte ptr [ebx + 0x52840c], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5407756) /* 0x52840c */) = cpu.cl;
    // 00494cca  88880c845200           -mov byte ptr [eax + 0x52840c], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5407756) /* 0x52840c */) = cpu.cl;
    // 00494cd0  ebdf                   -jmp 0x494cb1
    goto L_0x00494cb1;
L_0x00494cd2:
    // 00494cd2  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00494cd9  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00494cdb  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00494cde  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00494ce0  88980c845200           -mov byte ptr [eax + 0x52840c], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5407756) /* 0x52840c */) = cpu.bl;
    // 00494ce6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ce7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ce8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ce9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494ceb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00494ced:
    // 00494ced  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00494cef  88ba0c845200           -mov byte ptr [edx + 0x52840c], bh
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5407756) /* 0x52840c */) = cpu.bh;
    // 00494cf5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cf6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cf8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cf9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cfa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494cfb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494cfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494cfc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00494cfd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00494cfe  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494d00  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494d02  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494d05  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00494d0c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00494d0e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00494d11  0500845200             -add eax, 0x528400
    (cpu.eax) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 00494d16  80780c00               +cmp byte ptr [eax + 0xc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494d1a  7404                   -je 0x494d20
    if (cpu.flags.zf)
    {
        goto L_0x00494d20;
    }
    // 00494d1c  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494d1e  7405                   -je 0x494d25
    if (cpu.flags.zf)
    {
        goto L_0x00494d25;
    }
L_0x00494d20:
    // 00494d20  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x00494d25:
    // 00494d25  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00494d27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494d2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494d2a  9b                     -wait 
    /*nothing*/;
    // 00494d2b  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 00494d2d  9b                     -wait 
    /*nothing*/;
    // 00494d2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494d2f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494d2f  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 00494d31  9b                     -wait 
    /*nothing*/;
    // 00494d32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494d33(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00494d33:
    // 00494d33  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00494d34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00494d35  803dcd874c0000         +cmp byte ptr [0x4c87cd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5015501) /* 0x4c87cd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494d3c  7416                   -je 0x494d54
    if (cpu.flags.zf)
    {
        goto L_0x00494d54;
    }
    // 00494d3e  ba2a4d4900             -mov edx, 0x494d2a
    cpu.edx = 4803882 /*0x494d2a*/;
    // 00494d43  bb2f4d4900             -mov ebx, 0x494d2f
    cpu.ebx = 4803887 /*0x494d2f*/;
    // 00494d48  8915f4d34c00           -mov dword ptr [0x4cd3f4], edx
    app->getMemory<x86::reg32>(x86::reg32(5034996) /* 0x4cd3f4 */) = cpu.edx;
    // 00494d4e  891df8d34c00           -mov dword ptr [0x4cd3f8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035000) /* 0x4cd3f8 */) = cpu.ebx;
L_0x00494d54:
    // 00494d54  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494d56  66a1fcd34c00           -mov ax, word ptr [0x4cd3fc]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5035004) /* 0x4cd3fc */);
    // 00494d5c  e8b1fe0000             -call 0x4a4c12
    cpu.esp -= 4;
    sub_4a4c12(app, cpu);
    if (cpu.terminate) return;
    // 00494d61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d63  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00494d64  803dcd874c0000         +cmp byte ptr [0x4c87cd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5015501) /* 0x4c87cd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494d6b  75c6                   -jne 0x494d33
    if (!cpu.flags.zf)
    {
        goto L_0x00494d33;
    }
    // 00494d6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494d6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494d6e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00494d6f  8a25cc874c00           -mov ah, byte ptr [0x4c87cc]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5015500) /* 0x4c87cc */);
    // 00494d75  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00494d77  7537                   -jne 0x494db0
    if (!cpu.flags.zf)
    {
        goto L_0x00494db0;
    }
    // 00494d79  8825cd874c00           -mov byte ptr [0x4c87cd], ah
    app->getMemory<x86::reg8>(x86::reg32(5015501) /* 0x4c87cd */) = cpu.ah;
    // 00494d7f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00494d81  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00494d83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00494d84  dbe3                   -fninit 
    cpu.fpu.init();
    // 00494d86  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00494d89  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494d8a  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 00494d8c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00494d8e  3c03                   +cmp al, 3
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494d90  7509                   -jne 0x494d9b
    if (!cpu.flags.zf)
    {
        goto L_0x00494d9b;
    }
    // 00494d92  e89cffffff             -call 0x494d33
    cpu.esp -= 4;
    sub_494d33(app, cpu);
    if (cpu.terminate) return;
    // 00494d97  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 00494d99  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x00494d9b:
    // 00494d9b  803df8ab4c0000         +cmp byte ptr [0x4cabf8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5024760) /* 0x4cabf8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494da2  750c                   -jne 0x494db0
    if (!cpu.flags.zf)
    {
        goto L_0x00494db0;
    }
    // 00494da4  8835cc874c00           -mov byte ptr [0x4c87cc], dh
    app->getMemory<x86::reg8>(x86::reg32(5015500) /* 0x4c87cc */) = cpu.dh;
    // 00494daa  8815cd874c00           -mov byte ptr [0x4c87cd], dl
    app->getMemory<x86::reg8>(x86::reg32(5015501) /* 0x4c87cd */) = cpu.dl;
L_0x00494db0:
    // 00494db0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00494db1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_494db2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494db2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_494dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00494dc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00494dc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00494dc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00494dc3  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00494dc6  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00494dca  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00494dce  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00494dd2  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00494dd6  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00494dd9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00494ddb  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00494dde  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00494de1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494de3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00494de5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00494de7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00494de9  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00494dec  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00494df0  40                     -inc eax
    (cpu.eax)++;
    // 00494df1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00494df3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00494df7  8a25ee844c00           -mov ah, byte ptr [0x4c84ee]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5014766) /* 0x4c84ee */);
    // 00494dfd  8b2d54a84c00           -mov ebp, dword ptr [0x4ca854]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */);
    // 00494e03  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00494e05  0f8585030000           -jne 0x495190
    if (!cpu.flags.zf)
    {
        goto L_0x00495190;
    }
    // 00494e0b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00494e0f  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e15  0f8c75030000           -jl 0x495190
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495190;
    }
    // 00494e1b  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e21  0f8d69030000           -jge 0x495190
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495190;
    }
    // 00494e27  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494e2b  3b05e0844c00           +cmp eax, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e31  0f8c59030000           -jl 0x495190
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495190;
    }
    // 00494e37  3b05e8844c00           +cmp eax, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e3d  0f8d4d030000           -jge 0x495190
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495190;
    }
    // 00494e43  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00494e47  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00494e4b  8b1ddc844c00           -mov ebx, dword ptr [0x4c84dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 00494e51  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494e53  39d8                   +cmp eax, ebx
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
    // 00494e55  0f8c35030000           -jl 0x495190
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495190;
    }
    // 00494e5b  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e61  0f8d29030000           -jge 0x495190
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495190;
    }
    // 00494e67  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494e6b  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00494e6f  8b1de0844c00           -mov ebx, dword ptr [0x4c84e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 00494e75  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494e77  39d8                   +cmp eax, ebx
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
    // 00494e79  0f8c11030000           -jl 0x495190
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495190;
    }
    // 00494e7f  3b05e8844c00           +cmp eax, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494e85  0f8d05030000           -jge 0x495190
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495190;
    }
    // 00494e8b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494e8f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00494e91  8a15ec844c00           -mov dl, byte ptr [0x4c84ec]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00494e97  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00494e99  80fa10                 +cmp dl, 0x10
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00494e9c  0f8565010000           -jne 0x495007
    if (!cpu.flags.zf)
    {
        goto L_0x00495007;
    }
    // 00494ea2  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00494ea5:
    // 00494ea5  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494ea9  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00494ead  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00494eb3  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00494eb6  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00494ebc  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 00494ebf  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 00494ec5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00494ec7  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00494ecb  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x00494ecf:
    // 00494ecf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494ed1  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00494ed3  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00494ed6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 00494eda  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494ee0  726b                   -jb 0x494f4d
    if (cpu.flags.cf)
    {
        goto L_0x00494f4d;
    }
    // 00494ee2  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494ee8  7340                   -jae 0x494f2a
    if (!cpu.flags.cf)
    {
        goto L_0x00494f2a;
    }
    // 00494eea  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00494eed  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00494eef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494ef1  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00494ef4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00494ef7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00494ef9  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00494eff  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00494f02  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00494f07  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00494f0a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494f0c  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00494f0e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00494f11  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494f13  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00494f16  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494f18  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00494f1b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494f21  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00494f26  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494f28  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00494f2a:
    // 00494f2a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494f2c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00494f32  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00494f35  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494f37  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00494f3a  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00494f40  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00494f43  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494f46  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494f48  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494f4a  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00494f4d:
    // 00494f4d  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00494f50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00494f52  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00494f54  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00494f57  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 00494f5b  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494f61  726b                   -jb 0x494fce
    if (cpu.flags.cf)
    {
        goto L_0x00494fce;
    }
    // 00494f63  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00494f69  7340                   -jae 0x494fab
    if (!cpu.flags.cf)
    {
        goto L_0x00494fab;
    }
    // 00494f6b  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00494f6e  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00494f70  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494f72  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00494f75  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00494f78  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00494f7a  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00494f80  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00494f83  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00494f88  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00494f8b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494f8d  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00494f8f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00494f92  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00494f94  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00494f97  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00494f99  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00494f9c  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00494fa2  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00494fa7  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00494fa9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00494fab:
    // 00494fab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00494fad  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00494fb3  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00494fb6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00494fb8  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00494fbb  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00494fc1  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00494fc4  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00494fc7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00494fc9  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494fcb  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00494fce:
    // 00494fce  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00494fd1  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00494fd5  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00494fd6  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00494fd7  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 00494fdb  0f85eefeffff           -jne 0x494ecf
    if (!cpu.flags.zf)
    {
        goto L_0x00494ecf;
    }
    // 00494fe1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00494fe4  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00494fe8  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00494fec  41                     -inc ecx
    (cpu.ecx)++;
    // 00494fed  01d7                   +add edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00494fef  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00494ff3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00494ff4  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 00494ff8  0f85a7feffff           -jne 0x494ea5
    if (!cpu.flags.zf)
    {
        goto L_0x00494ea5;
    }
L_0x00494ffe:
    // 00494ffe  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00495001  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495002  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495003  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495004  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00495007:
    // 00495007  80fa0f                 +cmp dl, 0xf
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049500a  0f8577010000           -jne 0x495187
    if (!cpu.flags.zf)
    {
        goto L_0x00495187;
    }
    // 00495010  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00495014:
    // 00495014  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00495018  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049501c  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00495022  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00495025  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0049502b  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 0049502e  0305f0844c00           -add eax, dword ptr [0x4c84f0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */)));
    // 00495034  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495036  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049503a  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
L_0x0049503e:
    // 0049503e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495040  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00495042  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00495045  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00495048  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0049504b  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049504d  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495053  7273                   -jb 0x4950c8
    if (cpu.flags.cf)
    {
        goto L_0x004950c8;
    }
    // 00495055  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049505b  7348                   -jae 0x4950a5
    if (!cpu.flags.cf)
    {
        goto L_0x004950a5;
    }
    // 0049505d  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00495060  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495062  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 00495067  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0049506a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049506c  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00495072  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00495075  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495077  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049507a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049507c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049507e  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00495081  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495087  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00495089  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0049508c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049508e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495090  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00495093  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495099  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049509b  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0049509e  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004950a3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004950a5:
    // 004950a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004950a7  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004950ad  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004950b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004950b2  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004950b5  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004950bb  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004950be  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004950c1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004950c3  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004950c5  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004950c8:
    // 004950c8  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004950cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004950cd  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004950cf  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004950d2  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004950d6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004950dc  7273                   -jb 0x495151
    if (cpu.flags.cf)
    {
        goto L_0x00495151;
    }
    // 004950de  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004950e4  7348                   -jae 0x49512e
    if (!cpu.flags.cf)
    {
        goto L_0x0049512e;
    }
    // 004950e6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004950e9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004950eb  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004950f0  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004950f3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004950f5  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004950fb  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004950fe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495100  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00495103  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495105  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00495107  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0049510a  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495110  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00495112  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00495115  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495117  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495119  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 0049511c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00495122  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495124  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00495127  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 0049512c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0049512e:
    // 0049512e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495130  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00495136  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00495139  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049513b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0049513e  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00495144  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00495147  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049514a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049514c  01d3                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049514e  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00495151:
    // 00495151  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00495154  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00495158  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00495159  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049515a  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0049515e  0f85dafeffff           -jne 0x49503e
    if (!cpu.flags.zf)
    {
        goto L_0x0049503e;
    }
    // 00495164  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00495168  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049516c  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00495170  40                     -inc eax
    (cpu.eax)++;
    // 00495171  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495173  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00495177  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00495178  8954244c               -mov dword ptr [esp + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0049517c  0f847cfeffff           -je 0x494ffe
    if (cpu.flags.zf)
    {
        goto L_0x00494ffe;
    }
    // 00495182  e98dfeffff             -jmp 0x495014
    goto L_0x00495014;
L_0x00495187:
    // 00495187  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049518a  0f849c000000           -je 0x49522c
    if (cpu.flags.zf)
    {
        goto L_0x0049522c;
    }
L_0x00495190:
    // 00495190  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00495194  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00495196  0f8e62feffff           -jle 0x494ffe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00494ffe;
    }
    // 0049519c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004951a0  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004951a4  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004951a8  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004951aa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004951ac  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004951b0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004951b4:
    // 004951b4  8b742448               -mov esi, dword ptr [esp + 0x48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004951b8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004951ba  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004951bc  7e51                   -jle 0x49520f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049520f;
    }
    // 004951be  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004951c2  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004951c6  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004951ca  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004951ce  46                     -inc esi
    (cpu.esi)++;
L_0x004951cf:
    // 004951cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004951d1  8a1f                   -mov bl, byte ptr [edi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi);
    // 004951d3  47                     -inc edi
    (cpu.edi)++;
    // 004951d4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004951d6  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004951d9  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004951dc  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004951e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004951e2  0f858f000000           -jne 0x495277
    if (!cpu.flags.zf)
    {
        goto L_0x00495277;
    }
L_0x004951e8:
    // 004951e8  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004951ec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004951ee  7411                   -je 0x495201
    if (cpu.flags.zf)
    {
        goto L_0x00495201;
    }
    // 004951f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004951f2  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004951f6  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 004951fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004951fc  e83ffa0000             -call 0x4a4c40
    cpu.esp -= 4;
    sub_4a4c40(app, cpu);
    if (cpu.terminate) return;
L_0x00495201:
    // 00495201  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00495205  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00495208  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049520b  39c1                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049520d  7cc0                   -jl 0x4951cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004951cf;
    }
L_0x0049520f:
    // 0049520f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00495213  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00495217  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049521b  46                     -inc esi
    (cpu.esi)++;
    // 0049521c  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049521e  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00495222  39d6                   +cmp esi, edx
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
    // 00495224  0f8dd4fdffff           -jge 0x494ffe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00494ffe;
    }
    // 0049522a  eb88                   -jmp 0x4951b4
    goto L_0x004951b4;
L_0x0049522c:
    // 0049522c  8b1df8844c00           -mov ebx, dword ptr [0x4c84f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 00495232  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495234  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495236  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495237  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495238  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049523c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049523d  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00495241  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495242  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00495246  8b0dfc844c00           -mov ecx, dword ptr [0x4c84fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 0049524c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049524f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00495251  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 00495256  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00495258  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049525c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049525e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495260  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00495261  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495262  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00495265  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495266  e861fc0000             -call 0x4a4ecc
    cpu.esp -= 4;
    sub_4a4ecc(app, cpu);
    if (cpu.terminate) return;
    // 0049526b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049526e  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00495271  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495272  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495273  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495274  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00495277:
    // 00495277  8b5c8500               -mov ebx, dword ptr [ebp + eax*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + cpu.eax * 4);
    // 0049527b  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049527f  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00495283  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495285  e8b6f90000             -call 0x4a4c40
    cpu.esp -= 4;
    sub_4a4c40(app, cpu);
    if (cpu.terminate) return;
    // 0049528a  e959ffffff             -jmp 0x4951e8
    goto L_0x004951e8;
}

/* align: skip 0x90 */
void Application::sub_495290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495290  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495291  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495292  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495293  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00495296  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0049529a  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049529e  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004952a2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004952a4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004952a6  0f8eae000000           -jle 0x49535a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049535a;
    }
    // 004952ac  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004952ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004952b0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004952b3  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004952b5  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004952b7  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004952bb  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004952be  6bc700                 -imul eax, edi, 0
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004952c1  0faf7c2430             -imul edi, dword ptr [esp + 0x30]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */))));
    // 004952c6  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004952c9  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004952cd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004952cf  01ee                   -add esi, ebp
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004952d1  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004952d3  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004952d7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004952db:
    // 004952db  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004952df  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004952e2  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004952e6  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004952e8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004952ea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004952ec  7e4d                   -jle 0x49533b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049533b;
    }
    // 004952ee  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004952f2  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004952f6  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004952fa  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004952fe  46                     -inc esi
    (cpu.esi)++;
L_0x004952ff:
    // 004952ff  0fb62f                 -movzx ebp, byte ptr [edi]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edi));
    // 00495302  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00495304  47                     -inc edi
    (cpu.edi)++;
    // 00495305  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 00495308  83e50f                 -and ebp, 0xf
    cpu.ebp &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049530b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049530d  7554                   -jne 0x495363
    if (!cpu.flags.zf)
    {
        goto L_0x00495363;
    }
L_0x0049530f:
    // 0049530f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00495311  741a                   -je 0x49532d
    if (cpu.flags.zf)
    {
        goto L_0x0049532d;
    }
    // 00495313  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 0049531a  81c3fca74c00           -add ebx, 0x4ca7fc
    (cpu.ebx) += x86::reg32(x86::sreg32(5023740 /*0x4ca7fc*/));
    // 00495320  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00495324  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00495326  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00495328  e8436f0000             -call 0x49c270
    cpu.esp -= 4;
    sub_49c270(app, cpu);
    if (cpu.terminate) return;
L_0x0049532d:
    // 0049532d  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00495331  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00495334  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00495337  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495339  7cc4                   -jl 0x4952ff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004952ff;
    }
L_0x0049533b:
    // 0049533b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049533f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00495343  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00495347  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049534b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049534d  41                     -inc ecx
    (cpu.ecx)++;
    // 0049534e  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00495352  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00495356  39d9                   +cmp ecx, ebx
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495358  7c81                   -jl 0x4952db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004952db;
    }
L_0x0049535a:
    // 0049535a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049535d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049535e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049535f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495360  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00495363:
    // 00495363  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00495366  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049536a  81c3fca74c00           -add ebx, 0x4ca7fc
    (cpu.ebx) += x86::reg32(x86::sreg32(5023740 /*0x4ca7fc*/));
    // 00495370  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00495374  01c8                   +add eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495376  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00495378  e8f36e0000             -call 0x49c270
    cpu.esp -= 4;
    sub_49c270(app, cpu);
    if (cpu.terminate) return;
    // 0049537d  eb90                   -jmp 0x49530f
    goto L_0x0049530f;
}

/* align: skip 0x90 */
void Application::sub_495380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495380  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495381  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495382  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495383  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00495386  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495388  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049538c  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00495390  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00495394  a0ec844c00             -mov al, byte ptr [0x4c84ec]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00495399  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049539b  0f837c010000           -jae 0x49551d
    if (!cpu.flags.cf)
    {
        goto L_0x0049551d;
    }
    // 004953a1  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004953a3  0f82ac010000           -jb 0x495555
    if (cpu.flags.cf)
    {
        goto L_0x00495555;
    }
    // 004953a9  0f8798010000           -ja 0x495547
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00495547;
    }
    // 004953af  bf7c594900             -mov edi, 0x49597c
    cpu.edi = 4807036 /*0x49597c*/;
L_0x004953b4:
    // 004953b4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004953b6  0f8499010000           -je 0x495555
    if (cpu.flags.zf)
    {
        goto L_0x00495555;
    }
    // 004953bc  8b2ddc844c00           -mov ebp, dword ptr [0x4c84dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 004953c2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004953c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004953c6  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004953ca  39ee                   +cmp esi, ebp
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004953cc  7d04                   -jge 0x4953d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004953d2;
    }
    // 004953ce  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004953d0  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004953d2:
    // 004953d2  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 004953d8  39ca                   +cmp edx, ecx
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
    // 004953da  7d06                   -jge 0x4953e2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004953e2;
    }
    // 004953dc  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004953de  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004953e2:
    // 004953e2  8b2de4844c00           -mov ebp, dword ptr [0x4c84e4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 004953e8  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004953eb  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004953ed  7e04                   -jle 0x4953f3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004953f3;
    }
    // 004953ef  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004953f1  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004953f3:
    // 004953f3  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004953f7  8b2de8844c00           -mov ebp, dword ptr [0x4c84e8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 004953fd  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004953ff  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495401  7e08                   -jle 0x49540b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049540b;
    }
    // 00495403  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00495405  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00495407  894c2444               -mov dword ptr [esp + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ecx;
L_0x0049540b:
    // 0049540b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049540d  0f8c42010000           -jl 0x495555
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495555;
    }
    // 00495413  837c244400             +cmp dword ptr [esp + 0x44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495418  0f8c37010000           -jl 0x495555
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495555;
    }
    // 0049541e  39d8                   +cmp eax, ebx
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
    // 00495420  0f8d2f010000           -jge 0x495555
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495555;
    }
    // 00495426  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049542a  3b4c2444               +cmp ecx, dword ptr [esp + 0x44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049542e  0f8d21010000           -jge 0x495555
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495555;
    }
    // 00495434  8b6c243c               -mov ebp, dword ptr [esp + 0x3c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00495438  036c2418               -add ebp, dword ptr [esp + 0x18]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0049543c  0faf6c2448             -imul ebp, dword ptr [esp + 0x48]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */))));
    // 00495441  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00495444  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00495448  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049544b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049544d  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00495450  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00495453  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00495456  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049545a  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049545c  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0049545f  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00495463  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00495466  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 0049546a  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0049546e  03542418               -add edx, dword ptr [esp + 0x18]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00495472  8b2dfc844c00           -mov ebp, dword ptr [0x4c84fc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00495478  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0049547b  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049547d  8b2df0844c00           -mov ebp, dword ptr [0x4c84f0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 00495483  032a                   -add ebp, dword ptr [edx]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00495485  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 0049548b  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049548d  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495490  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00495493  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495495  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495497  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495499  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 0049549c  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0049549e  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004954a2  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004954a5  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004954a9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004954ab  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004954ae  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004954b2  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004954b4  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004954b9  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 004954bb  b108                   -mov cl, 8
    cpu.cl = 8 /*0x8*/;
    // 004954bd  88442424               -mov byte ptr [esp + 0x24], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.al;
    // 004954c1  2a4c2410               -sub cl, byte ptr [esp + 0x10]
    (cpu.cl) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004954c5  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 004954c7  d2e0                   -shl al, cl
    cpu.al <<= cpu.cl % 32;
    // 004954c9  88442420               -mov byte ptr [esp + 0x20], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.al;
L_0x004954cd:
    // 004954cd  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004954d1  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004954d4  8b742444               -mov esi, dword ptr [esp + 0x44]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004954d8  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004954dc  39f0                   +cmp eax, esi
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004954de  0f8d71000000           -jge 0x495555
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495555;
    }
    // 004954e4  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004954e8  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004954ec  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004954f0  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004954f2  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
    // 004954f6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004954f8  7564                   -jne 0x49555e
    if (!cpu.flags.zf)
    {
        goto L_0x0049555e;
    }
L_0x004954fa:
    // 004954fa  837c241000             +cmp dword ptr [esp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004954ff  0f8591000000           -jne 0x495596
    if (!cpu.flags.zf)
    {
        goto L_0x00495596;
    }
L_0x00495505:
    // 00495505  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00495509  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049550d  8b1df8844c00           -mov ebx, dword ptr [0x4c84f8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 00495513  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00495515  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495517  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 0049551b  ebb0                   -jmp 0x4954cd
    goto L_0x004954cd;
L_0x0049551d:
    // 0049551d  770a                   -ja 0x495529
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00495529;
    }
    // 0049551f  bfc0594900             -mov edi, 0x4959c0
    cpu.edi = 4807104 /*0x4959c0*/;
    // 00495524  e98bfeffff             -jmp 0x4953b4
    goto L_0x004953b4;
L_0x00495529:
    // 00495529  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049552b  7228                   -jb 0x495555
    if (cpu.flags.cf)
    {
        goto L_0x00495555;
    }
    // 0049552d  770a                   -ja 0x495539
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00495539;
    }
    // 0049552f  bf105a4900             -mov edi, 0x495a10
    cpu.edi = 4807184 /*0x495a10*/;
    // 00495534  e97bfeffff             -jmp 0x4953b4
    goto L_0x004953b4;
L_0x00495539:
    // 00495539  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049553b  7518                   -jne 0x495555
    if (!cpu.flags.zf)
    {
        goto L_0x00495555;
    }
    // 0049553d  bfa05a4900             -mov edi, 0x495aa0
    cpu.edi = 4807328 /*0x495aa0*/;
    // 00495542  e96dfeffff             -jmp 0x4953b4
    goto L_0x004953b4;
L_0x00495547:
    // 00495547  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495549  750a                   -jne 0x495555
    if (!cpu.flags.zf)
    {
        goto L_0x00495555;
    }
    // 0049554b  bfc0594900             -mov edi, 0x4959c0
    cpu.edi = 4807104 /*0x4959c0*/;
    // 00495550  e95ffeffff             -jmp 0x4953b4
    goto L_0x004953b4;
L_0x00495555:
    // 00495555  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00495558  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495559  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049555a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049555b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049555e:
    // 0049555e  8a5c2424               -mov bl, byte ptr [esp + 0x24]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00495562  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00495564  8b15f4a74c00           -mov edx, dword ptr [0x4ca7f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023732) /* 0x4ca7f4 */);
    // 0049556a  20d8                   -and al, bl
    cpu.al &= x86::reg8(x86::sreg8(cpu.bl));
    // 0049556c  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00495571  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00495573  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495575  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495577  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00495579  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049557a  88442428               -mov byte ptr [esp + 0x28], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.al;
L_0x0049557e:
    // 0049557e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049557f  0f8475ffffff           -je 0x4954fa
    if (cpu.flags.zf)
    {
        goto L_0x004954fa;
    }
    // 00495585  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00495587  8b15f4a74c00           -mov edx, dword ptr [0x4ca7f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023732) /* 0x4ca7f4 */);
    // 0049558d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 0049558f  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00495590  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495592  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495594  ebe8                   -jmp 0x49557e
    goto L_0x0049557e;
L_0x00495596:
    // 00495596  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00495598  8a642428               -mov ah, byte ptr [esp + 0x28]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049559c  8a4c2420               -mov cl, byte ptr [esp + 0x20]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004955a0  20e0                   -and al, ah
    cpu.al &= x86::reg8(x86::sreg8(cpu.ah));
    // 004955a2  8b15f4a74c00           -mov edx, dword ptr [0x4ca7f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023732) /* 0x4ca7f4 */);
    // 004955a8  20c8                   -and al, cl
    cpu.al &= x86::reg8(x86::sreg8(cpu.cl));
    // 004955aa  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004955af  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004955b1  e94fffffff             -jmp 0x495505
    goto L_0x00495505;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4955b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004955b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004955b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004955ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004955bb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004955bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004955bd  81ec30030000           -sub esp, 0x330
    (cpu.esp) -= x86::reg32(x86::sreg32(816 /*0x330*/));
    // 004955c3  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 004955ca  8994240c030000         -mov dword ptr [esp + 0x30c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */) = cpu.edx;
    // 004955d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004955d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004955d5:
    // 004955d5  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004955d8  8b88a07b5200           -mov ecx, dword ptr [eax + 0x527ba0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5405600) /* 0x527ba0 */);
    // 004955de  8b98a07b5200           -mov ebx, dword ptr [eax + 0x527ba0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5405600) /* 0x527ba0 */);
    // 004955e4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004955e7  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004955ea  884c14fd               -mov byte ptr [esp + edx - 3], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-3) /* -0x3 */ + cpu.edx * 1) = cpu.cl;
    // 004955ee  885c14fe               -mov byte ptr [esp + edx - 2], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.edx * 1) = cpu.bl;
    // 004955f2  8a98a07b5200           -mov bl, byte ptr [eax + 0x527ba0]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5405600) /* 0x527ba0 */);
    // 004955f8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004955fb  885c14ff               -mov byte ptr [esp + edx - 1], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.edx * 1) = cpu.bl;
    // 004955ff  3d00040000             +cmp eax, 0x400
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
    // 00495604  75cf                   -jne 0x4955d5
    if (!cpu.flags.zf)
    {
        goto L_0x004955d5;
    }
    // 00495606  8b842400030000         -mov eax, dword ptr [esp + 0x300]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0049560d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049560f  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00495612  89bc2404030000         -mov dword ptr [esp + 0x304], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.edi;
    // 00495619  89842408030000         -mov dword ptr [esp + 0x308], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */) = cpu.eax;
L_0x00495620:
    // 00495620  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 00495627  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495629  8a0414                 -mov al, byte ptr [esp + edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + cpu.edx * 1);
    // 0049562c  89842418030000         -mov dword ptr [esp + 0x318], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */) = cpu.eax;
    // 00495633  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495635  8a441401               -mov al, byte ptr [esp + edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.edx * 1);
    // 00495639  89842410030000         -mov dword ptr [esp + 0x310], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */) = cpu.eax;
    // 00495640  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495642  8b8c2400030000         -mov ecx, dword ptr [esp + 0x300]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 00495649  8a441402               -mov al, byte ptr [esp + edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.edx * 1);
    // 0049564d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049564f  89842414030000         -mov dword ptr [esp + 0x314], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */) = cpu.eax;
L_0x00495656:
    // 00495656  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495658  8a5103                 -mov dl, byte ptr [ecx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 0049565b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049565d  754b                   -jne 0x4956aa
    if (!cpu.flags.zf)
    {
        goto L_0x004956aa;
    }
    // 0049565f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00495661:
    // 00495661  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00495663  8b9c240c030000         -mov ebx, dword ptr [esp + 0x30c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(780) /* 0x30c */);
    // 0049566a  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 0049566c  8bac2408030000         -mov ebp, dword ptr [esp + 0x308]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(776) /* 0x308 */);
    // 00495673  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00495675  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495678  81c600010000           -add esi, 0x100
    (cpu.esi) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0049567e  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00495680  39e9                   +cmp ecx, ebp
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495682  75d2                   -jne 0x495656
    if (!cpu.flags.zf)
    {
        goto L_0x00495656;
    }
    // 00495684  8b842404030000         -mov eax, dword ptr [esp + 0x304]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 0049568b  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049568e  47                     -inc edi
    (cpu.edi)++;
    // 0049568f  89842404030000         -mov dword ptr [esp + 0x304], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */) = cpu.eax;
    // 00495696  81ff00010000           +cmp edi, 0x100
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049569c  7c82                   -jl 0x495620
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495620;
    }
    // 0049569e  81c430030000           -add esp, 0x330
    (cpu.esp) += x86::reg32(x86::sreg32(816 /*0x330*/));
    // 004956a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004956a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004956aa:
    // 004956aa  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 004956af  89942424030000         -mov dword ptr [esp + 0x324], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */) = cpu.edx;
    // 004956b6  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004956b8  8b942418030000         -mov edx, dword ptr [esp + 0x318]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(792) /* 0x318 */);
    // 004956bf  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004956c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004956c4  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004956c7  8984241c030000         -mov dword ptr [esp + 0x31c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */) = cpu.eax;
    // 004956ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004956d0  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004956d2  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 004956dd  89842420030000         -mov dword ptr [esp + 0x320], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */) = cpu.eax;
    // 004956e4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004956e6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004956e9  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004956f0  0384241c030000         -add eax, dword ptr [esp + 0x31c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(796) /* 0x31c */)));
    // 004956f7  0fb66901               -movzx ebp, byte ptr [ecx + 1]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */));
    // 004956fb  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495700  7e05                   -jle 0x495707
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495707;
    }
    // 00495702  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x00495707:
    // 00495707  8b942410030000         -mov edx, dword ptr [esp + 0x310]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(784) /* 0x310 */);
    // 0049570e  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00495711  c784242c030000ff000000 -mov dword ptr [esp + 0x32c], 0xff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */) = 255 /*0xff*/;
    // 0049571c  89842428030000         -mov dword ptr [esp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */) = cpu.eax;
    // 00495723  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495725  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00495728  f7bc242c030000         -idiv dword ptr [esp + 0x32c]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(812) /* 0x32c */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049572f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00495731  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495736  7e05                   -jle 0x49573d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049573d;
    }
    // 00495738  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0049573d:
    // 0049573d  8b942414030000         -mov edx, dword ptr [esp + 0x314]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(788) /* 0x314 */);
    // 00495744  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00495747  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00495749  bbff000000             -mov ebx, 0xff
    cpu.ebx = 255 /*0xff*/;
    // 0049574e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495750  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00495753  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00495755  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 0049575c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049575e  39da                   +cmp edx, ebx
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495760  7e02                   -jle 0x495764
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00495764;
    }
    // 00495762  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00495764:
    // 00495764  8b842424030000         -mov eax, dword ptr [esp + 0x324]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 0049576b  8b9c2428030000         -mov ebx, dword ptr [esp + 0x328]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(808) /* 0x328 */);
    // 00495772  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00495775  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00495778  c1e508                 -shl ebp, 8
    cpu.ebp <<= 8 /*0x8*/ % 32;
    // 0049577b  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049577d  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049577f  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00495781  e8d60dfeff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00495786  e9d6feffff             -jmp 0x495661
    goto L_0x00495661;
}

/* align: skip 0x90 */
void Application::sub_49578c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049578c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049578d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049578e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049578f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495790  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495791  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495792  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00495795  8b1554a84c00           -mov edx, dword ptr [0x4ca854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */);
    // 0049579b  e840c4ffff             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 004957a0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004957a2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004957a4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004957a9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004957ac  6be800                 -imul ebp, eax, 0
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004957af  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004957b2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004957b8  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004957bc  6bdb00                 -imul ebx, ebx, 0
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004957bf  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004957c2  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004957c8  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004957cc  6bff00                 -imul edi, edi, 0
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
    // 004957cf  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004957d3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004957d5  8d4240                 -lea eax, [edx + 0x40]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(64) /* 0x40 */);
    // 004957d8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004957da  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004957de:
    // 004957de  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004957e6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004957e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004957ea  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004957ed  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004957f1  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 004957f9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004957fb  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004957fe  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495800  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00495803  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00495807  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 0049580f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00495811  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 00495814  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00495816  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00495819  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049581d  c74424140f000000       -mov dword ptr [esp + 0x14], 0xf
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 15 /*0xf*/;
    // 00495825  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00495827  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049582a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049582c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049582f  f77c2414               -idiv dword ptr [esp + 0x14]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00495833  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495836  81c6ff000000           -add esi, 0xff
    (cpu.esi) += x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049583c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049583f  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 00495842  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00495846  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495848  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049584c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049584e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00495852  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00495854  39c1                   +cmp ecx, eax
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495856  7586                   -jne 0x4957de
    if (!cpu.flags.zf)
    {
        goto L_0x004957de;
    }
    // 00495858  803dec844c0008         +cmp byte ptr [0x4c84ec], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049585f  760a                   -jbe 0x49586b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049586b;
    }
    // 00495861  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00495864  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495865  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495866  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495867  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495868  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495869  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049586a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049586b:
    // 0049586b  8b1554a84c00           -mov edx, dword ptr [0x4ca854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */);
    // 00495871  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00495875  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00495878  e83bfdffff             -call 0x4955b8
    cpu.esp -= 4;
    sub_4955b8(app, cpu);
    if (cpu.terminate) return;
    // 0049587d  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00495880  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495881  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495882  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495883  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495884  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495885  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495886  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495888  833d54a84c0000         +cmp dword ptr [0x4ca854], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049588f  7519                   -jne 0x4958aa
    if (!cpu.flags.zf)
    {
        goto L_0x004958aa;
    }
    // 00495891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495892  b940100000             -mov ecx, 0x1040
    cpu.ecx = 4160 /*0x1040*/;
    // 00495897  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495899  890d58a84c00           -mov dword ptr [0x4ca858], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023832) /* 0x4ca858 */) = cpu.ecx;
    // 0049589f  e82c43ffff             -call 0x489bd0
    cpu.esp -= 4;
    sub_489bd0(app, cpu);
    if (cpu.terminate) return;
    // 004958a4  a354a84c00             -mov dword ptr [0x4ca854], eax
    app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */) = cpu.eax;
    // 004958a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004958aa:
    // 004958aa  e835000000             -call 0x4958e4
    cpu.esp -= 4;
    sub_4958e4(app, cpu);
    if (cpu.terminate) return;
    // 004958af  833ddca74c0001         +cmp dword ptr [0x4ca7dc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023708) /* 0x4ca7dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004958b6  7414                   -je 0x4958cc
    if (cpu.flags.zf)
    {
        goto L_0x004958cc;
    }
    // 004958b8  833de0a74c0000         +cmp dword ptr [0x4ca7e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023712) /* 0x4ca7e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004958bf  7416                   -je 0x4958d7
    if (cpu.flags.zf)
    {
        goto L_0x004958d7;
    }
    // 004958c1  c7055ca84c00c04d4900   -mov dword ptr [0x4ca85c], 0x494dc0
    app->getMemory<x86::reg32>(x86::reg32(5023836) /* 0x4ca85c */) = 4804032 /*0x494dc0*/;
    // 004958cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004958cc:
    // 004958cc  c7055ca84c0080534900   -mov dword ptr [0x4ca85c], 0x495380
    app->getMemory<x86::reg32>(x86::reg32(5023836) /* 0x4ca85c */) = 4805504 /*0x495380*/;
    // 004958d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004958d7:
    // 004958d7  c7055ca84c0090524900   -mov dword ptr [0x4ca85c], 0x495290
    app->getMemory<x86::reg32>(x86::reg32(5023836) /* 0x4ca85c */) = 4805264 /*0x495290*/;
    // 004958e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4958e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004958e4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004958e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004958e6  833d78a84c0000         +cmp dword ptr [0x4ca878], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023864) /* 0x4ca878 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004958ed  7515                   -jne 0x495904
    if (!cpu.flags.zf)
    {
        goto L_0x00495904;
    }
    // 004958ef  833de0a74c0000         +cmp dword ptr [0x4ca7e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023712) /* 0x4ca7e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004958f6  7409                   -je 0x495901
    if (cpu.flags.zf)
    {
        goto L_0x00495901;
    }
    // 004958f8  833ddca74c0004         +cmp dword ptr [0x4ca7dc], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023708) /* 0x4ca7dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004958ff  7431                   -je 0x495932
    if (cpu.flags.zf)
    {
        goto L_0x00495932;
    }
L_0x00495901:
    // 00495901  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495902  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495903  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495904:
    // 00495904  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00495909  b8fca74c00             -mov eax, 0x4ca7fc
    cpu.eax = 5023740 /*0x4ca7fc*/;
    // 0049590e  8b1554a84c00           -mov edx, dword ptr [0x4ca854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */);
    // 00495914  e837aefeff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00495919  803dec844c0008         +cmp byte ptr [0x4c84ec], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495920  77df                   -ja 0x495901
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00495901;
    }
    // 00495922  a154a84c00             -mov eax, dword ptr [0x4ca854]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */);
    // 00495927  8d5040                 -lea edx, [eax + 0x40]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0049592a  e889fcffff             -call 0x4955b8
    cpu.esp -= 4;
    sub_4955b8(app, cpu);
    if (cpu.terminate) return;
    // 0049592f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495930  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495931  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495932:
    // 00495932  a1f4a74c00             -mov eax, dword ptr [0x4ca7f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023732) /* 0x4ca7f4 */);
    // 00495937  e850feffff             -call 0x49578c
    cpu.esp -= 4;
    sub_49578c(app, cpu);
    if (cpu.terminate) return;
    // 0049593c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049593d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049593e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_495940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495940  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495941  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495942  8b1554a84c00           -mov edx, dword ptr [0x4ca854]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */);
    // 00495948  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049594a  750b                   -jne 0x495957
    if (!cpu.flags.zf)
    {
        goto L_0x00495957;
    }
    // 0049594c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0049594e  89355ca84c00           -mov dword ptr [0x4ca85c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023836) /* 0x4ca85c */) = cpu.esi;
    // 00495954  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495955  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495956  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495957:
    // 00495957  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495958  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049595a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049595c  e8d742ffff             -call 0x489c38
    cpu.esp -= 4;
    sub_489c38(app, cpu);
    if (cpu.terminate) return;
    // 00495961  890d54a84c00           -mov dword ptr [0x4ca854], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023828) /* 0x4ca854 */) = cpu.ecx;
    // 00495967  890d58a84c00           -mov dword ptr [0x4ca858], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023832) /* 0x4ca858 */) = cpu.ecx;
    // 0049596d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049596e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00495970  89355ca84c00           -mov dword ptr [0x4ca85c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023836) /* 0x4ca85c */) = cpu.esi;
    // 00495976  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495977  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495978  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49597c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049597c  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 0049597e  7532                   -jne 0x4959b2
    if (!cpu.flags.zf)
    {
        goto L_0x004959b2;
    }
L_0x00495980:
    // 00495980  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00495982  7403                   -je 0x495987
    if (cpu.flags.zf)
    {
        goto L_0x00495987;
    }
    // 00495984  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
L_0x00495987:
    // 00495987  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00495989  7403                   -je 0x49598e
    if (cpu.flags.zf)
    {
        goto L_0x0049598e;
    }
    // 0049598b  885302                 -mov byte ptr [ebx + 2], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x0049598e:
    // 0049598e  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00495990  7403                   -je 0x495995
    if (cpu.flags.zf)
    {
        goto L_0x00495995;
    }
    // 00495992  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
L_0x00495995:
    // 00495995  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00495997  7403                   -je 0x49599c
    if (cpu.flags.zf)
    {
        goto L_0x0049599c;
    }
    // 00495999  885304                 -mov byte ptr [ebx + 4], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
L_0x0049599c:
    // 0049599c  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0049599e  7403                   -je 0x4959a3
    if (cpu.flags.zf)
    {
        goto L_0x004959a3;
    }
    // 004959a0  885305                 -mov byte ptr [ebx + 5], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
L_0x004959a3:
    // 004959a3  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004959a5  7403                   -je 0x4959aa
    if (cpu.flags.zf)
    {
        goto L_0x004959aa;
    }
    // 004959a7  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
L_0x004959aa:
    // 004959aa  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004959ac  7508                   -jne 0x4959b6
    if (!cpu.flags.zf)
    {
        goto L_0x004959b6;
    }
    // 004959ae  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004959b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004959b2:
    // 004959b2  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004959b4  ebca                   -jmp 0x495980
    goto L_0x00495980;
L_0x004959b6:
    // 004959b6  885307                 -mov byte ptr [ebx + 7], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.dl;
    // 004959b9  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004959bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4959c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004959c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004959c1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004959c3  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004959c5  7539                   -jne 0x495a00
    if (!cpu.flags.zf)
    {
        goto L_0x00495a00;
    }
L_0x004959c7:
    // 004959c7  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 004959c9  7404                   -je 0x4959cf
    if (cpu.flags.zf)
    {
        goto L_0x004959cf;
    }
    // 004959cb  66895102               -mov word ptr [ecx + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
L_0x004959cf:
    // 004959cf  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 004959d1  7404                   -je 0x4959d7
    if (cpu.flags.zf)
    {
        goto L_0x004959d7;
    }
    // 004959d3  66895104               -mov word ptr [ecx + 4], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.dx;
L_0x004959d7:
    // 004959d7  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004959d9  7404                   -je 0x4959df
    if (cpu.flags.zf)
    {
        goto L_0x004959df;
    }
    // 004959db  66895106               -mov word ptr [ecx + 6], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.dx;
L_0x004959df:
    // 004959df  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004959e1  7404                   -je 0x4959e7
    if (cpu.flags.zf)
    {
        goto L_0x004959e7;
    }
    // 004959e3  66895108               -mov word ptr [ecx + 8], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.dx;
L_0x004959e7:
    // 004959e7  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004959e9  7404                   -je 0x4959ef
    if (cpu.flags.zf)
    {
        goto L_0x004959ef;
    }
    // 004959eb  6689510a               -mov word ptr [ecx + 0xa], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.dx;
L_0x004959ef:
    // 004959ef  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004959f1  7404                   -je 0x4959f7
    if (cpu.flags.zf)
    {
        goto L_0x004959f7;
    }
    // 004959f3  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
L_0x004959f7:
    // 004959f7  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004959f9  750a                   -jne 0x495a05
    if (!cpu.flags.zf)
    {
        goto L_0x00495a05;
    }
    // 004959fb  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004959fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004959ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495a00:
    // 00495a00  668913                 -mov word ptr [ebx], dx
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.dx;
    // 00495a03  ebc2                   -jmp 0x4959c7
    goto L_0x004959c7;
L_0x00495a05:
    // 00495a05  6689510e               -mov word ptr [ecx + 0xe], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 00495a09  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00495a0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_495a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495a10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495a11  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495a14  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00495a17  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00495a1a  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00495a1d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00495a20  88cc                   -mov ah, cl
    cpu.ah = cpu.cl;
    // 00495a22  8a3424                 -mov dh, byte ptr [esp]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp);
    // 00495a25  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00495a27  755a                   -jne 0x495a83
    if (!cpu.flags.zf)
    {
        goto L_0x00495a83;
    }
L_0x00495a29:
    // 00495a29  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00495a2b  7409                   -je 0x495a36
    if (cpu.flags.zf)
    {
        goto L_0x00495a36;
    }
    // 00495a2d  885303                 -mov byte ptr [ebx + 3], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.dl;
    // 00495a30  886304                 -mov byte ptr [ebx + 4], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 00495a33  887305                 -mov byte ptr [ebx + 5], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dh;
L_0x00495a36:
    // 00495a36  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00495a38  7409                   -je 0x495a43
    if (cpu.flags.zf)
    {
        goto L_0x00495a43;
    }
    // 00495a3a  885306                 -mov byte ptr [ebx + 6], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00495a3d  886307                 -mov byte ptr [ebx + 7], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.ah;
    // 00495a40  887308                 -mov byte ptr [ebx + 8], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.dh;
L_0x00495a43:
    // 00495a43  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00495a45  7409                   -je 0x495a50
    if (cpu.flags.zf)
    {
        goto L_0x00495a50;
    }
    // 00495a47  885309                 -mov byte ptr [ebx + 9], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(9) /* 0x9 */) = cpu.dl;
    // 00495a4a  88630a                 -mov byte ptr [ebx + 0xa], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10) /* 0xa */) = cpu.ah;
    // 00495a4d  88730b                 -mov byte ptr [ebx + 0xb], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11) /* 0xb */) = cpu.dh;
L_0x00495a50:
    // 00495a50  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00495a52  7409                   -je 0x495a5d
    if (cpu.flags.zf)
    {
        goto L_0x00495a5d;
    }
    // 00495a54  88530c                 -mov byte ptr [ebx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00495a57  88630d                 -mov byte ptr [ebx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00495a5a  88730e                 -mov byte ptr [ebx + 0xe], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.dh;
L_0x00495a5d:
    // 00495a5d  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00495a5f  7409                   -je 0x495a6a
    if (cpu.flags.zf)
    {
        goto L_0x00495a6a;
    }
    // 00495a61  88530f                 -mov byte ptr [ebx + 0xf], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.dl;
    // 00495a64  886310                 -mov byte ptr [ebx + 0x10], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ah;
    // 00495a67  887311                 -mov byte ptr [ebx + 0x11], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = cpu.dh;
L_0x00495a6a:
    // 00495a6a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00495a6c  7409                   -je 0x495a77
    if (cpu.flags.zf)
    {
        goto L_0x00495a77;
    }
    // 00495a6e  885312                 -mov byte ptr [ebx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 00495a71  886313                 -mov byte ptr [ebx + 0x13], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(19) /* 0x13 */) = cpu.ah;
    // 00495a74  887314                 -mov byte ptr [ebx + 0x14], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.dh;
L_0x00495a77:
    // 00495a77  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00495a79  7512                   -jne 0x495a8d
    if (!cpu.flags.zf)
    {
        goto L_0x00495a8d;
    }
    // 00495a7b  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00495a7e  83c404                 +add esp, 4
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
    // 00495a81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495a83:
    // 00495a83  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 00495a85  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00495a88  887302                 -mov byte ptr [ebx + 2], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dh;
    // 00495a8b  eb9c                   -jmp 0x495a29
    goto L_0x00495a29;
L_0x00495a8d:
    // 00495a8d  885315                 -mov byte ptr [ebx + 0x15], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = cpu.dl;
    // 00495a90  886316                 -mov byte ptr [ebx + 0x16], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = cpu.ah;
    // 00495a93  887317                 -mov byte ptr [ebx + 0x17], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(23) /* 0x17 */) = cpu.dh;
    // 00495a96  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00495a99  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495a9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495a9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_495aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495aa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495aa1  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00495aa3  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00495aa5  7533                   -jne 0x495ada
    if (!cpu.flags.zf)
    {
        goto L_0x00495ada;
    }
L_0x00495aa7:
    // 00495aa7  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00495aa9  7403                   -je 0x495aae
    if (cpu.flags.zf)
    {
        goto L_0x00495aae;
    }
    // 00495aab  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00495aae:
    // 00495aae  a820                   +test al, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 32 /*0x20*/));
    // 00495ab0  7403                   -je 0x495ab5
    if (cpu.flags.zf)
    {
        goto L_0x00495ab5;
    }
    // 00495ab2  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00495ab5:
    // 00495ab5  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 00495ab7  7403                   -je 0x495abc
    if (cpu.flags.zf)
    {
        goto L_0x00495abc;
    }
    // 00495ab9  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00495abc:
    // 00495abc  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00495abe  7403                   -je 0x495ac3
    if (cpu.flags.zf)
    {
        goto L_0x00495ac3;
    }
    // 00495ac0  895110                 -mov dword ptr [ecx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x00495ac3:
    // 00495ac3  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00495ac5  7403                   -je 0x495aca
    if (cpu.flags.zf)
    {
        goto L_0x00495aca;
    }
    // 00495ac7  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x00495aca:
    // 00495aca  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00495acc  7403                   -je 0x495ad1
    if (cpu.flags.zf)
    {
        goto L_0x00495ad1;
    }
    // 00495ace  895118                 -mov dword ptr [ecx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x00495ad1:
    // 00495ad1  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00495ad3  7509                   -jne 0x495ade
    if (!cpu.flags.zf)
    {
        goto L_0x00495ade;
    }
    // 00495ad5  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00495ad8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ad9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495ada:
    // 00495ada  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00495adc  ebc9                   -jmp 0x495aa7
    goto L_0x00495aa7;
L_0x00495ade:
    // 00495ade  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00495ae1  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00495ae4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ae5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495ae6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495ae6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495ae8  7503                   -jne 0x495aed
    if (!cpu.flags.zf)
    {
        goto L_0x00495aed;
    }
    // 00495aea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00495aec:
    // 00495aec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495aed:
    // 00495aed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495aef  74fb                   -je 0x495aec
    if (cpu.flags.zf)
    {
        goto L_0x00495aec;
    }
    // 00495af1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495af2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495af4  e873010000             -call 0x495c6c
    cpu.esp -= 4;
    sub_495c6c(app, cpu);
    if (cpu.terminate) return;
    // 00495af9  83fa7b                 +cmp edx, 0x7b
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
    // 00495afc  7507                   -jne 0x495b05
    if (!cpu.flags.zf)
    {
        goto L_0x00495b05;
    }
    // 00495afe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00495b03  eb31                   -jmp 0x495b36
    goto L_0x00495b36;
L_0x00495b05:
    // 00495b05  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b0b  7507                   -jne 0x495b14
    if (!cpu.flags.zf)
    {
        goto L_0x00495b14;
    }
    // 00495b0d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00495b12  eb22                   -jmp 0x495b36
    goto L_0x00495b36;
L_0x00495b14:
    // 00495b14  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b1a  7507                   -jne 0x495b23
    if (!cpu.flags.zf)
    {
        goto L_0x00495b23;
    }
    // 00495b1c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00495b21  eb13                   -jmp 0x495b36
    goto L_0x00495b36;
L_0x00495b23:
    // 00495b23  83fa13                 +cmp edx, 0x13
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b26  7605                   -jbe 0x495b2d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495b2d;
    }
    // 00495b28  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00495b2d:
    // 00495b2d  8b8219ac4c00           -mov eax, dword ptr [edx + 0x4cac19]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5024793) /* 0x4cac19 */);
    // 00495b33  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00495b36:
    // 00495b36  e805010000             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 00495b3b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00495b40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495af1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00495af1;
    // 00495ae6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495ae8  7503                   -jne 0x495aed
    if (!cpu.flags.zf)
    {
        goto L_0x00495aed;
    }
    // 00495aea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00495aec:
    // 00495aec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495aed:
    // 00495aed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00495aef  74fb                   -je 0x495aec
    if (cpu.flags.zf)
    {
        goto L_0x00495aec;
    }
L_entry_0x00495af1:
    // 00495af1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495af2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495af4  e873010000             -call 0x495c6c
    cpu.esp -= 4;
    sub_495c6c(app, cpu);
    if (cpu.terminate) return;
    // 00495af9  83fa7b                 +cmp edx, 0x7b
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
    // 00495afc  7507                   -jne 0x495b05
    if (!cpu.flags.zf)
    {
        goto L_0x00495b05;
    }
    // 00495afe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00495b03  eb31                   -jmp 0x495b36
    goto L_0x00495b36;
L_0x00495b05:
    // 00495b05  81face000000           +cmp edx, 0xce
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b0b  7507                   -jne 0x495b14
    if (!cpu.flags.zf)
    {
        goto L_0x00495b14;
    }
    // 00495b0d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00495b12  eb22                   -jmp 0x495b36
    goto L_0x00495b36;
L_0x00495b14:
    // 00495b14  81fab7000000           +cmp edx, 0xb7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b1a  7507                   -jne 0x495b23
    if (!cpu.flags.zf)
    {
        goto L_0x00495b23;
    }
    // 00495b1c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00495b21  eb13                   -jmp 0x495b36
    goto L_0x00495b36;
L_0x00495b23:
    // 00495b23  83fa13                 +cmp edx, 0x13
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b26  7605                   -jbe 0x495b2d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495b2d;
    }
    // 00495b28  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00495b2d:
    // 00495b2d  8b8219ac4c00           -mov eax, dword ptr [edx + 0x4cac19]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5024793) /* 0x4cac19 */);
    // 00495b33  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00495b36:
    // 00495b36  e805010000             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 00495b3b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00495b40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495b42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495b42  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495b43  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495b44  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495b4b  e8a1ffffff             -call 0x495af1
    cpu.esp -= 4;
    sub_495af1(app, cpu);
    if (cpu.terminate) return;
    // 00495b50  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495b52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::malloc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495b53  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495b54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495b55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495b56  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495b57  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495b58  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00495b59  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00495b5b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00495b5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495b5e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495b61  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00495b63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495b65  7405                   -je 0x495b6c
    if (cpu.flags.zf)
    {
        goto L_0x00495b6c;
    }
    // 00495b67  83f8d4                 +cmp eax, -0x2c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-44 /*-0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b6a  7607                   -jbe 0x495b73
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495b73;
    }
L_0x00495b6c:
    // 00495b6c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00495b6e  e9be000000             -jmp 0x495c31
    goto L_0x00495c31;
L_0x00495b73:
    // 00495b73  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00495b76  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00495b79  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b7c  7305                   -jae 0x495b83
    if (!cpu.flags.cf)
    {
        goto L_0x00495b83;
    }
    // 00495b7e  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x00495b83:
    // 00495b83  ff1560c14c00           -call dword ptr [0x4cc160]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030240) /* 0x4cc160 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495b89  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00495b8b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495b8d  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00495b90:
    // 00495b90  3b2d38ac4c00           +cmp ebp, dword ptr [0x4cac38]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024824) /* 0x4cac38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495b96  760c                   -jbe 0x495ba4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495ba4;
    }
    // 00495b98  8b0d34ac4c00           -mov ecx, dword ptr [0x4cac34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024820) /* 0x4cac34 */);
    // 00495b9e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00495ba0  7510                   -jne 0x495bb2
    if (!cpu.flags.zf)
    {
        goto L_0x00495bb2;
    }
    // 00495ba2  eb02                   -jmp 0x495ba6
    goto L_0x00495ba6;
L_0x00495ba4:
    // 00495ba4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00495ba6:
    // 00495ba6  890d38ac4c00           -mov dword ptr [0x4cac38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024824) /* 0x4cac38 */) = cpu.ecx;
    // 00495bac  8b0d30ac4c00           -mov ecx, dword ptr [0x4cac30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024816) /* 0x4cac30 */);
L_0x00495bb2:
    // 00495bb2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00495bb4  743c                   -je 0x495bf2
    if (cpu.flags.zf)
    {
        goto L_0x00495bf2;
    }
    // 00495bb6  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00495bb9  890d34ac4c00           -mov dword ptr [0x4cac34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5024820) /* 0x4cac34 */) = cpu.ecx;
    // 00495bbf  39fe                   +cmp esi, edi
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
    // 00495bc1  721c                   -jb 0x495bdf
    if (cpu.flags.cf)
    {
        goto L_0x00495bdf;
    }
    // 00495bc3  b830ac4c00             -mov eax, 0x4cac30
    cpu.eax = 5024816 /*0x4cac30*/;
    // 00495bc8  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00495bca  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00495bd0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00495bd2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495bd4  e807f40000             -call 0x4a4fe0
    cpu.esp -= 4;
    sub_4a4fe0(app, cpu);
    if (cpu.terminate) return;
    // 00495bd9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495bdb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495bdd  7542                   -jne 0x495c21
    if (!cpu.flags.zf)
    {
        goto L_0x00495c21;
    }
L_0x00495bdf:
    // 00495bdf  3b3538ac4c00           +cmp esi, dword ptr [0x4cac38]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5024824) /* 0x4cac38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495be5  7606                   -jbe 0x495bed
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495bed;
    }
    // 00495be7  893538ac4c00           -mov dword ptr [0x4cac38], esi
    app->getMemory<x86::reg32>(x86::reg32(5024824) /* 0x4cac38 */) = cpu.esi;
L_0x00495bed:
    // 00495bed  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00495bf0  ebc0                   -jmp 0x495bb2
    goto L_0x00495bb2;
L_0x00495bf2:
    // 00495bf2  803c2400               +cmp byte ptr [esp], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495bf6  750b                   -jne 0x495c03
    if (!cpu.flags.zf)
    {
        goto L_0x00495c03;
    }
    // 00495bf8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495bfa  e8c7f60000             -call 0x4a52c6
    cpu.esp -= 4;
    sub_4a52c6(app, cpu);
    if (cpu.terminate) return;
    // 00495bff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495c01  7515                   -jne 0x495c18
    if (!cpu.flags.zf)
    {
        goto L_0x00495c18;
    }
L_0x00495c03:
    // 00495c03  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00495c05  e817f70000             -call 0x4a5321
    cpu.esp -= 4;
    sub_4a5321(app, cpu);
    if (cpu.terminate) return;
    // 00495c0a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00495c0c  7413                   -je 0x495c21
    if (cpu.flags.zf)
    {
        goto L_0x00495c21;
    }
    // 00495c0e  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00495c10  880c24                 -mov byte ptr [esp], cl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 00495c13  e978ffffff             -jmp 0x495b90
    goto L_0x00495b90;
L_0x00495c18:
    // 00495c18  c6042401               -mov byte ptr [esp], 1
    app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 00495c1c  e96fffffff             -jmp 0x495b90
    goto L_0x00495b90;
L_0x00495c21:
    // 00495c21  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00495c23  882d10615400           -mov byte ptr [0x546110], ch
    app->getMemory<x86::reg8>(x86::reg32(5529872) /* 0x546110 */) = cpu.ch;
    // 00495c29  ff1568c14c00           -call dword ptr [0x4cc168]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030248) /* 0x4cc168 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495c2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00495c31:
    // 00495c31  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495c34  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c35  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495c37  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495c39  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00495c3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00495c40:
    // 00495c40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495c41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495c43  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495c49  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00495c4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c4d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00495c4e  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00495c53  ebeb                   -jmp 0x495c40
    goto L_0x00495c40;
}

/* align: skip  */
void Application::sub_495c55(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495c55  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00495c5a  ebe4                   -jmp 0x495c40
    return sub_495c40(app, cpu);
}

/* align: skip  */
void Application::sub_495c5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495c5c  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00495c61  e8daffffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 00495c66  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00495c6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495c6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495c6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495c6d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00495c6f  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00495c75  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00495c78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495c79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_495c7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495c7c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495c7d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495c7e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495c7f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495c80  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495c82  8b3d58b75100           -mov edi, dword ptr [0x51b758]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5355352) /* 0x51b758 */);
    // 00495c88  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495c8a  f7c203000000           +test edx, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 3 /*0x3*/));
    // 00495c90  7420                   -je 0x495cb2
    if (cpu.flags.zf)
    {
        goto L_0x00495cb2;
    }
    // 00495c92  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495c95  7818                   -js 0x495caf
    if (cpu.flags.sf)
    {
        goto L_0x00495caf;
    }
L_0x00495c97:
    // 00495c97  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00495c99  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495c9c  7411                   -je 0x495caf
    if (cpu.flags.zf)
    {
        goto L_0x00495caf;
    }
    // 00495c9e  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00495ca1  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 00495ca4  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00495ca7  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00495caa  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495cad  79e8                   -jns 0x495c97
    if (!cpu.flags.sf)
    {
        goto L_0x00495c97;
    }
L_0x00495caf:
    // 00495caf  83c501                 -add ebp, 1
    (cpu.ebp) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00495cb2:
    // 00495cb2  83ed02                 +sub ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495cb5  7859                   -js 0x495d10
    if (cpu.flags.sf)
    {
        goto L_0x00495d10;
    }
L_0x00495cb7:
    // 00495cb7  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00495cb9  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495cbc  7428                   -je 0x495ce6
    if (cpu.flags.zf)
    {
        goto L_0x00495ce6;
    }
    // 00495cbe  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00495cc1  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00495cc4  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495cc7  7439                   -je 0x495d02
    if (cpu.flags.zf)
    {
        goto L_0x00495d02;
    }
    // 00495cc9  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00495ccc  81e3ffff0000           -and ebx, 0xffff
    cpu.ebx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00495cd2  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 00495cd5  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00495cd7  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
L_0x00495cd9:
    // 00495cd9  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495cdc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495cdf  83ed02                 +sub ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495ce2  79d3                   -jns 0x495cb7
    if (!cpu.flags.sf)
    {
        goto L_0x00495cb7;
    }
    // 00495ce4  eb2a                   -jmp 0x495d10
    goto L_0x00495d10;
L_0x00495ce6:
    // 00495ce6  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00495ce9  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495cec  74eb                   -je 0x495cd9
    if (cpu.flags.zf)
    {
        goto L_0x00495cd9;
    }
    // 00495cee  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00495cf1  66895a02               -mov word ptr [edx + 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bx;
    // 00495cf5  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495cf8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495cfb  83ed02                 +sub ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495cfe  79b7                   -jns 0x495cb7
    if (!cpu.flags.sf)
    {
        goto L_0x00495cb7;
    }
    // 00495d00  eb0e                   -jmp 0x495d10
    goto L_0x00495d10;
L_0x00495d02:
    // 00495d02  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 00495d05  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495d08  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495d0b  83ed02                 +sub ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495d0e  79a7                   -jns 0x495cb7
    if (!cpu.flags.sf)
    {
        goto L_0x00495cb7;
    }
L_0x00495d10:
    // 00495d10  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00495d13  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495d16  7818                   -js 0x495d30
    if (cpu.flags.sf)
    {
        goto L_0x00495d30;
    }
L_0x00495d18:
    // 00495d18  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00495d1a  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00495d1d  7411                   -je 0x495d30
    if (cpu.flags.zf)
    {
        goto L_0x00495d30;
    }
    // 00495d1f  8b1c8f                 -mov ebx, dword ptr [edi + ecx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00495d22  66891a                 -mov word ptr [edx], bx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.bx;
    // 00495d25  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00495d28  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00495d2b  83ed01                 +sub ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495d2e  79e8                   -jns 0x495d18
    if (!cpu.flags.sf)
    {
        goto L_0x00495d18;
    }
L_0x00495d30:
    // 00495d30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_495d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495d40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495d41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495d42  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495d44  42                     -inc edx
    (cpu.edx)++;
    // 00495d45  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495d47  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00495d4a  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00495d4c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495d4e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d4f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_495d54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495d54  83f820                 +cmp eax, 0x20
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d57  7c12                   -jl 0x495d6b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495d6b;
    }
    // 00495d59  83f87f                 +cmp eax, 0x7f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495d5c  7f0d                   -jg 0x495d6b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495d6b;
    }
    // 00495d5e  668b044500ac4c00       -mov ax, word ptr [eax*2 + 0x4cac00]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5024768) /* 0x4cac00 */ + cpu.eax * 2);
    // 00495d66  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
L_0x00495d6b:
    // 00495d6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
