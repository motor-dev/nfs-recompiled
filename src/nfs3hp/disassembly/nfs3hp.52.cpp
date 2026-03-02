#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip  */
void Application::sub_52a3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a3a0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a3a1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a3a2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a3a3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a3a4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052a3a7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052a3a9  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052a3ad  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052a3af  8b5028                 -mov edx, dword ptr [eax + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0052a3b2  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052a3b5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a3b7  754a                   -jne 0x52a403
    if (!cpu.flags.zf)
    {
        goto L_0x0052a403;
    }
L_0x0052a3b9:
    // 0052a3b9  8d7d10                 -lea edi, [ebp + 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a3bc  8d452c                 -lea eax, [ebp + 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0052a3bf  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052a3c2  8d7518                 -lea esi, [ebp + 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(24) /* 0x18 */);
L_0x0052a3c5:
    // 0052a3c5  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a3ca  0f8e78010000           -jle 0x52a548
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a548;
    }
    // 0052a3d0  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052a3d3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a3d5  743d                   -je 0x52a414
    if (cpu.flags.zf)
    {
        goto L_0x0052a414;
    }
    // 0052a3d7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052a3da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052a3dc  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0052a3de  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a3e2  e899f8ffff             -call 0x529c80
    cpu.esp -= 4;
    sub_529c80(app, cpu);
    if (cpu.terminate) return;
    // 0052a3e7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a3eb  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052a3ee  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a3f1  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a3f3  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a3f5  01c2                   +add edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a3f7  894d20                 -mov dword ptr [ebp + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0052a3fa  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052a3fe  895528                 -mov dword ptr [ebp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0052a401  ebc2                   -jmp 0x52a3c5
    goto L_0x0052a3c5;
L_0x0052a403:
    // 0052a403  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0052a406  e88d75feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052a40b  c7462800000000         -mov dword ptr [esi + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0052a412  eba5                   -jmp 0x52a3b9
    goto L_0x0052a3b9;
L_0x0052a414:
    // 0052a414  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0052a417  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052a41a  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 0052a41d  39d0                   +cmp eax, edx
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
    // 0052a41f  7d4a                   -jge 0x52a46b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a46b;
    }
    // 0052a421  6b551c1e               -imul edx, dword ptr [ebp + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052a425  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052a42a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a42c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a42f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a431  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0052a434  c745001c000000         -mov dword ptr [ebp], 0x1c
    *app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 0052a43b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a43d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a43e  89550c                 -mov dword ptr [ebp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a441  e80a2e0000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a446  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a449  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0052a44c  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a44f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a453  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a456  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a459  895d1c                 -mov dword ptr [ebp + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0052a45c  83e81c                 +sub eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a45f  895528                 -mov dword ptr [ebp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0052a462  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052a466  e95affffff             -jmp 0x52a3c5
    goto L_0x0052a3c5;
L_0x0052a46b:
    // 0052a46b  837d1400               +cmp dword ptr [ebp + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a46f  745c                   -je 0x52a4cd
    if (cpu.flags.zf)
    {
        goto L_0x0052a4cd;
    }
    // 0052a471  6b551c1e               -imul edx, dword ptr [ebp + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 0052a475  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 0052a47a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a47c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052a47f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052a481  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0052a484  c745001c000000         -mov dword ptr [ebp], 0x1c
    *app->getMemory<x86::reg32>(cpu.ebp) = 28 /*0x1c*/;
    // 0052a48b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a48d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a48e  89550c                 -mov dword ptr [ebp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052a491  e8ba2d0000             -call 0x52d250
    cpu.esp -= 4;
    sub_52d250(app, cpu);
    if (cpu.terminate) return;
    // 0052a496  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0052a499  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a49c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052a49f  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052a4a2  89451c                 -mov dword ptr [ebp + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0052a4a5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a4a7  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a4aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052a4ac  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0052a4b1  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a4b5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a4b7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0052a4ba  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a4bc  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a4be  8b5528                 -mov edx, dword ptr [ebp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a4c1  895d10                 -mov dword ptr [ebp + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052a4c4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a4c6  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052a4ca  895528                 -mov dword ptr [ebp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edx;
L_0x0052a4cd:
    // 0052a4cd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052a4cf  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0052a4d2  e82574feff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052a4d7  894514                 -mov dword ptr [ebp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052a4da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052a4dc  7436                   -je 0x52a514
    if (cpu.flags.zf)
    {
        goto L_0x0052a514;
    }
    // 0052a4de  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052a4e0  668b00                 -mov ax, word ptr [eax]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax);
    // 0052a4e3  66894506               -mov word ptr [ebp + 6], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 0052a4e7  668b4202               -mov ax, word ptr [edx + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0052a4eb  66894504               -mov word ptr [ebp + 4], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0052a4ef  668b4204               -mov ax, word ptr [edx + 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0052a4f3  6689450a               -mov word ptr [ebp + 0xa], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 0052a4f7  668b4206               -mov ax, word ptr [edx + 6]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0052a4fb  66894508               -mov word ptr [ebp + 8], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0052a4ff  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0052a502  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a509  83c008                 +add eax, 8
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
    // 0052a50c  894514                 -mov dword ptr [ebp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052a50f  e9b1feffff             -jmp 0x52a3c5
    goto L_0x0052a3c5;
L_0x0052a514:
    // 0052a514  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a518  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a51a  0f8ea5feffff           -jle 0x52a3c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a3c5;
    }
    // 0052a520  837d2800               +cmp dword ptr [ebp + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a524  740d                   -je 0x52a533
    if (cpu.flags.zf)
    {
        goto L_0x0052a533;
    }
    // 0052a526  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0052a529  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a52c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a52e  e80d61fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052a533:
    // 0052a533  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a537  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a53a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a53d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a53f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a541  897d10                 -mov dword ptr [ebp + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0052a544  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052a548:
    // 0052a548  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a54c  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052a54f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a552  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a554  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a558  895510                 -mov dword ptr [ebp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052a55b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052a55d  7c0b                   -jl 0x52a56a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a56a;
    }
    // 0052a55f  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a562  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052a565  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a566  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a567  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a568  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a569  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a56a:
    // 0052a56a  6bc1ff                 -imul eax, ecx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 0052a56d  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052a570  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052a574  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0052a57b  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0052a57e  8d452c                 -lea eax, [ebp + 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 0052a581  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052a583  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a585  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a586  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052a588  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052a58b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 0052a58d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052a58f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052a592  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 0052a594  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a595  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a599  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0052a59c  8b7d28                 -mov edi, dword ptr [ebp + 0x28]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a59f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a5a1  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a5a3  897520                 -mov dword ptr [ebp + 0x20], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0052a5a6  897d28                 -mov dword ptr [ebp + 0x28], edi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 0052a5a9  8b4528                 -mov eax, dword ptr [ebp + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0052a5ac  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052a5af  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a5b0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a5b1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a5b2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a5b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52a5b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a5b4  e8a72b0000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052a5b9  c7421400000000         -mov dword ptr [edx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0052a5c0  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0052a5c7  c7422000000000         -mov dword ptr [edx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0052a5ce  66c742060000           -mov word ptr [edx + 6], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 0052a5d4  66c742040000           -mov word ptr [edx + 4], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052a5da  66c7420a0000           -mov word ptr [edx + 0xa], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0052a5e0  66c742080000           -mov word ptr [edx + 8], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052a5e6  c7422800000000         -mov dword ptr [edx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0052a5ed  894224                 -mov dword ptr [edx + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0052a5f0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a5f4  894a18                 -mov dword ptr [edx + 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0052a5f7  c700a0a35200           -mov dword ptr [eax], 0x52a3a0
    *app->getMemory<x86::reg32>(cpu.eax) = 5415840 /*0x52a3a0*/;
    // 0052a5fd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a601  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052a607  b898000000             -mov eax, 0x98
    cpu.eax = 152 /*0x98*/;
    // 0052a60c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_52a610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a610  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052a616  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52a618(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a618  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a619  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a61a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a61b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052a61d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052a61f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052a621  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052a623  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a625  7e34                   -jle 0x52a65b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a65b;
    }
    // 0052a627  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052a629  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0052a62b:
    // 0052a62b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0052a62d  25ffff0100             -and eax, 0x1ffff
    cpu.eax &= x86::reg32(x86::sreg32(131071 /*0x1ffff*/));
    // 0052a632  3dff7f0000             +cmp eax, 0x7fff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a637  7613                   -jbe 0x52a64c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052a64c;
    }
    // 0052a639  3d00800100             +cmp eax, 0x18000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98304 /*0x18000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a63e  730c                   -jae 0x52a64c
    if (!cpu.flags.cf)
    {
        goto L_0x0052a64c;
    }
    // 0052a640  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a645  7318                   -jae 0x52a65f
    if (!cpu.flags.cf)
    {
        goto L_0x0052a65f;
    }
    // 0052a647  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
L_0x0052a64c:
    // 0052a64c  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052a64f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052a652  41                     -inc ecx
    (cpu.ecx)++;
    // 0052a653  668943fe               -mov word ptr [ebx - 2], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 0052a657  39f1                   +cmp ecx, esi
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
    // 0052a659  7cd0                   -jl 0x52a62b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052a62b;
    }
L_0x0052a65b:
    // 0052a65b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a65c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a65d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a65e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a65f:
    // 0052a65f  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 0052a664  ebe6                   -jmp 0x52a64c
    goto L_0x0052a64c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52a668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a668  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a669  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a66a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a66b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a66c  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a66f  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052a671  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052a673  8bb04c0d0000           -mov esi, dword ptr [eax + 0xd4c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052a679  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052a67f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052a681  39d6                   +cmp esi, edx
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
    // 0052a683  0f83e1000000           -jae 0x52a76a
    if (!cpu.flags.cf)
    {
        goto L_0x0052a76a;
    }
    // 0052a689  8d1c2e                 -lea ebx, [esi + ebp]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0052a68c  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052a692  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052a694  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a696  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 0052a69c  893424                 -mov dword ptr [esp], esi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0052a69f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052a6a1  0f8ed0000000           -jle 0x52a777
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a777;
    }
    // 0052a6a7  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052a6a9:
    // 0052a6a9  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052a6af  39f5                   +cmp ebp, esi
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
    // 0052a6b1  7d02                   -jge 0x52a6b5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a6b5;
    }
    // 0052a6b3  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x0052a6b5:
    // 0052a6b5  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052a6ba  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052a6c0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052a6c2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a6c4  8d9784060000           -lea edx, [edi + 0x684]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 0052a6ca  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a6cd  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052a6d1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052a6d3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052a6d5  e83effffff             -call 0x52a618
    cpu.esp -= 4;
    sub_52a618(app, cpu);
    if (cpu.terminate) return;
    // 0052a6da  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0052a6dd  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a6df  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052a6e5  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a6e7  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a6e9  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 0052a6ef  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052a6f1  7e5f                   -jle 0x52a752
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a752;
    }
    // 0052a6f3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a6f7  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0052a6fb:
    // 0052a6fb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052a700  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052a702  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 0052a707  e874380000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052a70c  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 0052a716  39f5                   +cmp ebp, esi
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
    // 0052a718  7d02                   -jge 0x52a71c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a71c;
    }
    // 0052a71a  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x0052a71c:
    // 0052a71c  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052a721  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 0052a727  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a72b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a72e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052a730  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052a732  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052a734  e8dffeffff             -call 0x52a618
    cpu.esp -= 4;
    sub_52a618(app, cpu);
    if (cpu.terminate) return;
    // 0052a739  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0052a73c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a73e  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052a744  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a746  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a748  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 0052a74e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052a750  7fa9                   -jg 0x52a6fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052a6fb;
    }
L_0x0052a752:
    // 0052a752  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052a754:
    // 0052a754  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052a757  39d0                   +cmp eax, edx
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
    // 0052a759  7d26                   -jge 0x52a781
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a781;
    }
    // 0052a75b  83c102                 +add ecx, 2
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a75e  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0052a761  668941fe               -mov word ptr [ecx - 2], ax
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 0052a765  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052a768  ebea                   -jmp 0x52a754
    goto L_0x0052a754;
L_0x0052a76a:
    // 0052a76a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052a76f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a772  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a773  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a774  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a775  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a776  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a777:
    // 0052a777  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052a779  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052a77c  e928ffffff             -jmp 0x52a6a9
    goto L_0x0052a6a9;
L_0x0052a781:
    // 0052a781  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052a786  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a789  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a78a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a78b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a78c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a78d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52a790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a790  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a791  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052a793  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052a795  e8fa360000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052a79a  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052a7a4  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a7ae  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a7b2  898e440d0000           -mov dword ptr [esi + 0xd44], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ecx;
    // 0052a7b8  c70068a65200           -mov dword ptr [eax], 0x52a668
    *app->getMemory<x86::reg32>(cpu.eax) = 5416552 /*0x52a668*/;
    // 0052a7be  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052a7c2  c70010a65200           -mov dword ptr [eax], 0x52a610
    *app->getMemory<x86::reg32>(cpu.eax) = 5416464 /*0x52a610*/;
    // 0052a7c8  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 0052a7cd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a7ce  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52a7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a7e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a7e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a7e2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a7e3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a7e4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a7e7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052a7e9  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052a7ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052a7f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a7f3  0f84b8000000           -je 0x52a8b1
    if (cpu.flags.zf)
    {
        goto L_0x0052a8b1;
    }
    // 0052a7f9  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052a7fb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a7fd  0f8ea1000000           -jle 0x52a8a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a8a4;
    }
    // 0052a803  8d9884060000           -lea ebx, [eax + 0x684]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1668) /* 0x684 */);
    // 0052a809  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052a80d  8d98480d0000           -lea ebx, [eax + 0xd48]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(3400) /* 0xd48 */);
    // 0052a813  05440d0000             -add eax, 0xd44
    (cpu.eax) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 0052a818  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052a81c  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0052a81f:
    // 0052a81f  8b814c0d0000           -mov eax, dword ptr [ecx + 0xd4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 0052a825  3b81480d0000           +cmp eax, dword ptr [ecx + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a82b  0f8d8d000000           -jge 0x52a8be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a8be;
    }
L_0x0052a831:
    // 0052a831  83b9500d000000         +cmp dword ptr [ecx + 0xd50], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a838  0f8e15010000           -jle 0x52a953
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a953;
    }
L_0x0052a83e:
    // 0052a83e  8bb1480d0000           -mov esi, dword ptr [ecx + 0xd48]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 0052a844  2bb14c0d0000           -sub esi, dword ptr [ecx + 0xd4c]
    (cpu.esi) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */)));
    // 0052a84a  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052a84c  7d02                   -jge 0x52a850
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052a850;
    }
    // 0052a84e  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0052a850:
    // 0052a850  8b91500d0000           -mov edx, dword ptr [ecx + 0xd50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 0052a856  39d6                   +cmp esi, edx
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
    // 0052a858  7e02                   -jle 0x52a85c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052a85c;
    }
    // 0052a85a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x0052a85c:
    // 0052a85c  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052a861  2b81500d0000           -sub eax, dword ptr [ecx + 0xd50]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */)));
    // 0052a867  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052a86b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052a86e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052a870  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052a872  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052a874  e89ffdffff             -call 0x52a618
    cpu.esp -= 4;
    sub_52a618(app, cpu);
    if (cpu.terminate) return;
    // 0052a879  8b994c0d0000           -mov ebx, dword ptr [ecx + 0xd4c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 0052a87f  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052a881  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0052a884  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052a886  8b81500d0000           -mov eax, dword ptr [ecx + 0xd50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 0052a88c  89994c0d0000           -mov dword ptr [ecx + 0xd4c], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 0052a892  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a894  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052a896  8981500d0000           -mov dword ptr [ecx + 0xd50], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 0052a89c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a89e  0f8f7bffffff           -jg 0x52a81f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052a81f;
    }
L_0x0052a8a4:
    // 0052a8a4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052a8a9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a8ac  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8ad  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8ae  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8af  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a8b1:
    // 0052a8b1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052a8b6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a8b9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8ba  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8bb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8bc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a8bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a8be:
    // 0052a8be  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052a8c2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052a8c5  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052a8cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052a8cd  752b                   -jne 0x52a8fa
    if (!cpu.flags.zf)
    {
        goto L_0x0052a8fa;
    }
    // 0052a8cf  8b99440d0000           -mov ebx, dword ptr [ecx + 0xd44]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 0052a8d5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052a8d7  7421                   -je 0x52a8fa
    if (cpu.flags.zf)
    {
        goto L_0x0052a8fa;
    }
    // 0052a8d9  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx);
    // 0052a8db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052a8dd  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0052a8df  7446                   -je 0x52a927
    if (cpu.flags.zf)
    {
        goto L_0x0052a927;
    }
    // 0052a8e1  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052a8e4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052a8e6  e8a9350000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052a8eb  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a8f5  e937ffffff             -jmp 0x52a831
    goto L_0x0052a831;
L_0x0052a8fa:
    // 0052a8fa  8d1c3f                 -lea ebx, [edi + edi]
    cpu.ebx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0052a8fd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052a8ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052a901  e83a5dfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052a906  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a910  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052a915  c781480d000000000000   -mov dword ptr [ecx + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052a91f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052a922  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a923  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a924  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a925  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052a926  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052a927:
    // 0052a927  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052a92a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052a92f  894104                 -mov dword ptr [ecx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052a932  8b81440d0000           -mov eax, dword ptr [ecx + 0xd44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 0052a938  c7410808000000         -mov dword ptr [ecx + 8], 8
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052a93f  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052a942  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052a944  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a94e  e9defeffff             -jmp 0x52a831
    goto L_0x0052a831;
L_0x0052a953:
    // 0052a953  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052a958  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052a95a  e821360000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052a95f  c781500d0000b0010000   -mov dword ptr [ecx + 0xd50], 0x1b0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 0052a969  e9d0feffff             -jmp 0x52a83e
    goto L_0x0052a83e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52a970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a970  c782440d000001000000   -mov dword ptr [edx + 0xd44], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 0052a97a  c782480d000000000000   -mov dword ptr [edx + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052a984  c7824c0d000000000000   -mov dword ptr [edx + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052a98e  c782500d000000000000   -mov dword ptr [edx + 0xd50], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052a998  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052a99c  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052a9a2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052a9a6  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 0052a9ab  c702e0a75200           -mov dword ptr [edx], 0x52a7e0
    *app->getMemory<x86::reg32>(cpu.edx) = 5416928 /*0x52a7e0*/;
    // 0052a9b1  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52a9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052a9c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052a9c1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052a9c2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052a9c3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052a9c4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052a9c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052a9c9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052a9cb  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052a9cd  8b90500d0000           -mov edx, dword ptr [eax + 0xd50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */);
    // 0052a9d3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052a9d5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052a9d7  0f85c0000000           -jne 0x52aa9d
    if (!cpu.flags.zf)
    {
        goto L_0x0052aa9d;
    }
L_0x0052a9dd:
    // 0052a9dd  8d8184060000           -lea eax, [ecx + 0x684]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1668) /* 0x684 */);
    // 0052a9e3  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052a9e6  8d81480d0000           -lea eax, [ecx + 0xd48]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 0052a9ec  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052a9f0:
    // 0052a9f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052a9f2  0f8e00010000           -jle 0x52aaf8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052aaf8;
    }
    // 0052a9f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052a9fa  8b99480d0000           -mov ebx, dword ptr [ecx + 0xd48]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 0052aa00  668b81540d0000         -mov ax, word ptr [ecx + 0xd54]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */);
    // 0052aa07  39d8                   +cmp eax, ebx
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
    // 0052aa09  0f8da8000000           -jge 0x52aab7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052aab7;
    }
L_0x0052aa0f:
    // 0052aa0f  6683b9560d000000       +cmp word ptr [ecx + 0xd56], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3414) /* 0xd56 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052aa17  0f8e2f010000           -jle 0x52ab4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ab4c;
    }
L_0x0052aa1d:
    // 0052aa1d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052aa1f  8b81480d0000           -mov eax, dword ptr [ecx + 0xd48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 0052aa25  668bb1540d0000         -mov si, word ptr [ecx + 0xd54]
    cpu.si = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */);
    // 0052aa2c  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052aa2e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052aa30  39c7                   +cmp edi, eax
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052aa32  7d02                   -jge 0x52aa36
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052aa36;
    }
    // 0052aa34  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0052aa36:
    // 0052aa36  8b81540d0000           -mov eax, dword ptr [ecx + 0xd54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3412) /* 0xd54 */);
    // 0052aa3c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052aa3f  39f0                   +cmp eax, esi
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
    // 0052aa41  0f8c1f010000           -jl 0x52ab66
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052ab66;
    }
L_0x0052aa47:
    // 0052aa47  8b81540d0000           -mov eax, dword ptr [ecx + 0xd54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3412) /* 0xd54 */);
    // 0052aa4d  bab0010000             -mov edx, 0x1b0
    cpu.edx = 432 /*0x1b0*/;
    // 0052aa52  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052aa55  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052aa57  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0052aa5e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052aa61  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052aa63  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052aa65  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052aa67  e8acfbffff             -call 0x52a618
    cpu.esp -= 4;
    sub_52a618(app, cpu);
    if (cpu.terminate) return;
    // 0052aa6c  6601b1540d0000         -add word ptr [ecx + 0xd54], si
    (*app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */)) += x86::reg16(x86::sreg16(cpu.si));
    // 0052aa73  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0052aa76  8b99500d0000           -mov ebx, dword ptr [ecx + 0xd50]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 0052aa7c  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052aa7e  668b81560d0000         -mov ax, word ptr [ecx + 0xd56]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3414) /* 0xd56 */);
    // 0052aa85  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052aa87  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052aa89  8999500d0000           -mov dword ptr [ecx + 0xd50], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = cpu.ebx;
    // 0052aa8f  29f7                   +sub edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052aa91  668981560d0000         -mov word ptr [ecx + 0xd56], ax
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3414) /* 0xd56 */) = cpu.ax;
    // 0052aa98  e953ffffff             -jmp 0x52a9f0
    goto L_0x0052a9f0;
L_0x0052aa9d:
    // 0052aa9d  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052aaa3  e8f06efeff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052aaa8  c786500d000000000000   -mov dword ptr [esi + 0xd50], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052aab2  e926ffffff             -jmp 0x52a9dd
    goto L_0x0052a9dd;
L_0x0052aab7:
    // 0052aab7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052aabb  8b814c0d0000           -mov eax, dword ptr [ecx + 0xd4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 0052aac1  e8366efeff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052aac6  8981440d0000           -mov dword ptr [ecx + 0xd44], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */) = cpu.eax;
    // 0052aacc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052aace  7536                   -jne 0x52ab06
    if (!cpu.flags.zf)
    {
        goto L_0x0052ab06;
    }
    // 0052aad0  83b9500d000000         +cmp dword ptr [ecx + 0xd50], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052aad7  740c                   -je 0x52aae5
    if (cpu.flags.zf)
    {
        goto L_0x0052aae5;
    }
    // 0052aad9  8d1c3f                 -lea ebx, [edi + edi]
    cpu.ebx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 0052aadc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052aade  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052aae0  e85b5bfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052aae5:
    // 0052aae5  66c781540d00000000     -mov word ptr [ecx + 0xd54], 0
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052aaee  c781480d000000000000   -mov dword ptr [ecx + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
L_0x0052aaf8:
    // 0052aaf8  8b81500d0000           -mov eax, dword ptr [ecx + 0xd50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 0052aafe  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052ab01  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ab02  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ab03  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ab04  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ab05  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ab06:
    // 0052ab06  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052ab09  7416                   -je 0x52ab21
    if (cpu.flags.zf)
    {
        goto L_0x0052ab21;
    }
    // 0052ab0b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052ab0c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052ab0e  e881330000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052ab13  66c781540d00000000     -mov word ptr [ecx + 0xd54], 0
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052ab1c  e9eefeffff             -jmp 0x52aa0f
    goto L_0x0052aa0f;
L_0x0052ab21:
    // 0052ab21  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052ab24  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052ab29  894104                 -mov dword ptr [ecx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052ab2c  8b81440d0000           -mov eax, dword ptr [ecx + 0xd44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 0052ab32  c7410808000000         -mov dword ptr [ecx + 8], 8
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052ab39  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052ab3c  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052ab3e  66c781540d00000000     -mov word ptr [ecx + 0xd54], 0
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052ab47  e9c3feffff             -jmp 0x52aa0f
    goto L_0x0052aa0f;
L_0x0052ab4c:
    // 0052ab4c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052ab51  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ab53  e828340000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052ab58  66c781560d0000b001     -mov word ptr [ecx + 0xd56], 0x1b0
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(3414) /* 0xd56 */) = 432 /*0x1b0*/;
    // 0052ab61  e9b7feffff             -jmp 0x52aa1d
    goto L_0x0052aa1d;
L_0x0052ab66:
    // 0052ab66  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052ab68  e9dafeffff             -jmp 0x52aa47
    goto L_0x0052aa47;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ab70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ab70  e8eb250000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052ab75  c782440d000000000000   -mov dword ptr [edx + 0xd44], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3396) /* 0xd44 */) = 0 /*0x0*/;
    // 0052ab7f  c782480d000000000000   -mov dword ptr [edx + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052ab89  66c782540d00000000     -mov word ptr [edx + 0xd54], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052ab92  66c782560d00000000     -mov word ptr [edx + 0xd56], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(3414) /* 0xd56 */) = 0 /*0x0*/;
    // 0052ab9b  89824c0d0000           -mov dword ptr [edx + 0xd4c], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3404) /* 0xd4c */) = cpu.eax;
    // 0052aba1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052aba5  c782500d000000000000   -mov dword ptr [edx + 0xd50], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052abaf  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052abb5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052abb9  c700c0a95200           -mov dword ptr [eax], 0x52a9c0
    *app->getMemory<x86::reg32>(cpu.eax) = 5417408 /*0x52a9c0*/;
    // 0052abbf  b8580d0000             -mov eax, 0xd58
    cpu.eax = 3416 /*0xd58*/;
    // 0052abc4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52abd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052abd0  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052abd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52abd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052abd8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052abd9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052abdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052abdd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052abdf  7e13                   -jle 0x52abf4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052abf4;
    }
L_0x0052abe1:
    // 0052abe1  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ecx)));
    // 0052abe3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052abe6  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052abe9  40                     -inc eax
    (cpu.eax)++;
    // 0052abea  d95afc                 -fstp dword ptr [edx - 4]
    *app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052abed  39d8                   +cmp eax, ebx
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
    // 0052abef  7cf0                   -jl 0x52abe1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052abe1;
    }
    // 0052abf1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0052abf4:
    // 0052abf4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052abf5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52abf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052abf8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052abf9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052abfa  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052abfb  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052abfc  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052abff  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052ac01  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052ac03  8bb04c0d0000           -mov esi, dword ptr [eax + 0xd4c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052ac09  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052ac0f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052ac11  39d6                   +cmp esi, edx
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
    // 0052ac13  0f83e7000000           -jae 0x52ad00
    if (!cpu.flags.cf)
    {
        goto L_0x0052ad00;
    }
    // 0052ac19  8d1c2e                 -lea ebx, [esi + ebp]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0052ac1c  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052ac22  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052ac24  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ac26  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 0052ac2c  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052ac30  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052ac32  0f8ed5000000           -jle 0x52ad0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ad0d;
    }
    // 0052ac38  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052ac3a:
    // 0052ac3a  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052ac40  39f5                   +cmp ebp, esi
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
    // 0052ac42  7d02                   -jge 0x52ac46
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052ac46;
    }
    // 0052ac44  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x0052ac46:
    // 0052ac46  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052ac4b  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052ac51  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052ac53  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ac55  8d9784060000           -lea edx, [edi + 0x684]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 0052ac5b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052ac5e  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052ac61  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ac63  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052ac65  e86effffff             -call 0x52abd8
    cpu.esp -= 4;
    sub_52abd8(app, cpu);
    if (cpu.terminate) return;
    // 0052ac6a  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0052ac71  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ac73  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052ac79  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052ac7b  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052ac7d  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 0052ac83  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052ac85  7e5f                   -jle 0x52ace6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ace6;
    }
    // 0052ac87  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052ac8a  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052ac8e:
    // 0052ac8e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052ac90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ac92  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 0052ac97  e8e4320000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052ac9c  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 0052aca6  39f5                   +cmp ebp, esi
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
    // 0052aca8  7d02                   -jge 0x52acac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052acac;
    }
    // 0052acaa  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x0052acac:
    // 0052acac  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 0052acb1  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 0052acb7  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052acbb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052acbe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052acc0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052acc2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052acc4  e80fffffff             -call 0x52abd8
    cpu.esp -= 4;
    sub_52abd8(app, cpu);
    if (cpu.terminate) return;
    // 0052acc9  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0052acd0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052acd2  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 0052acd8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052acda  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052acdc  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 0052ace2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052ace4  7fa8                   -jg 0x52ac8e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052ac8e;
    }
L_0x0052ace6:
    // 0052ace6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052acea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052acec  7e2a                   -jle 0x52ad18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ad18;
    }
    // 0052acee  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0052acf1  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0052acf7  83c104                 +add ecx, 4
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052acfa  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052acfe  ebe6                   -jmp 0x52ace6
    goto L_0x0052ace6;
L_0x0052ad00:
    // 0052ad00  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052ad05  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ad08  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad09  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad0a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad0b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ad0d:
    // 0052ad0d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052ad0f  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052ad13  e922ffffff             -jmp 0x52ac3a
    goto L_0x0052ac3a;
L_0x0052ad18:
    // 0052ad18  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ad1d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ad20  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad21  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad22  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad23  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ad28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ad28  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ad29  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052ad2b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ad2d  e862310000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052ad32  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052ad3c  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052ad46  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ad4a  898e440d0000           -mov dword ptr [esi + 0xd44], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ecx;
    // 0052ad50  c700f8ab5200           -mov dword ptr [eax], 0x52abf8
    *app->getMemory<x86::reg32>(cpu.eax) = 5417976 /*0x52abf8*/;
    // 0052ad56  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052ad5a  c700d0ab5200           -mov dword ptr [eax], 0x52abd0
    *app->getMemory<x86::reg32>(cpu.eax) = 5417936 /*0x52abd0*/;
    // 0052ad60  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 0052ad65  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ad66  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ad70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ad70  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ad71  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ad72  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ad73  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ad74  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052ad77  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052ad79  89542410               -mov dword ptr [esp + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052ad7d  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 0052ad83  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052ad85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ad87  0f84e2000000           -je 0x52ae6f
    if (cpu.flags.zf)
    {
        goto L_0x0052ae6f;
    }
    // 0052ad8d  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ad91  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052ad94  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052ad96  0f8ec6000000           -jle 0x52ae62
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ae62;
    }
    // 0052ad9c  0584060000             -add eax, 0x684
    (cpu.eax) += x86::reg32(x86::sreg32(1668 /*0x684*/));
    // 0052ada1  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052ada5  8d86480d0000           -lea eax, [esi + 0xd48]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3400) /* 0xd48 */);
    // 0052adab  81c6440d0000           -add esi, 0xd44
    (cpu.esi) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 0052adb1  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052adb5  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x0052adb9:
    // 0052adb9  8b854c0d0000           -mov eax, dword ptr [ebp + 0xd4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 0052adbf  3b85480d0000           +cmp eax, dword ptr [ebp + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052adc5  0f8db1000000           -jge 0x52ae7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052ae7c;
    }
L_0x0052adcb:
    // 0052adcb  83bd500d000000         +cmp dword ptr [ebp + 0xd50], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052add2  0f8e40010000           -jle 0x52af18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052af18;
    }
L_0x0052add8:
    // 0052add8  8b95480d0000           -mov edx, dword ptr [ebp + 0xd48]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 0052adde  8bbd4c0d0000           -mov edi, dword ptr [ebp + 0xd4c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 0052ade4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ade8  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052adea  39c2                   +cmp edx, eax
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
    // 0052adec  7e02                   -jle 0x52adf0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052adf0;
    }
    // 0052adee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0052adf0:
    // 0052adf0  8b8d500d0000           -mov ecx, dword ptr [ebp + 0xd50]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052adf6  39ca                   +cmp edx, ecx
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
    // 0052adf8  7e02                   -jle 0x52adfc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052adfc;
    }
    // 0052adfa  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0052adfc:
    // 0052adfc  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 0052ae01  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052ae05  8bbd500d0000           -mov edi, dword ptr [ebp + 0xd50]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052ae0b  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 0052ae12  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052ae14  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052ae16  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0052ae19  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052ae1c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ae1e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ae1f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ae21  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052ae24  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 0052ae26  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052ae28  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052ae2b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 0052ae2d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae2e  8b8d4c0d0000           -mov ecx, dword ptr [ebp + 0xd4c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 0052ae34  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 0052ae37  8b85500d0000           -mov eax, dword ptr [ebp + 0xd50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052ae3d  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ae41  893424                 -mov dword ptr [esp], esi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0052ae44  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ae46  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ae48  898d4c0d0000           -mov dword ptr [ebp + 0xd4c], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = cpu.ecx;
    // 0052ae4e  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052ae50  8985500d0000           -mov dword ptr [ebp + 0xd50], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 0052ae56  897c2410               -mov dword ptr [esp + 0x10], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0052ae5a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052ae5c  0f8f57ffffff           -jg 0x52adb9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052adb9;
    }
L_0x0052ae62:
    // 0052ae62  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ae67  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052ae6a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae6b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae6c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae6d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ae6f:
    // 0052ae6f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052ae74  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052ae77  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae78  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae79  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae7a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ae7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ae7c:
    // 0052ae7c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052ae80  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ae84  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052ae8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052ae8c  752b                   -jne 0x52aeb9
    if (!cpu.flags.zf)
    {
        goto L_0x0052aeb9;
    }
    // 0052ae8e  8b9d440d0000           -mov ebx, dword ptr [ebp + 0xd44]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 0052ae94  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052ae96  7421                   -je 0x52aeb9
    if (cpu.flags.zf)
    {
        goto L_0x0052aeb9;
    }
    // 0052ae98  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx);
    // 0052ae9a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ae9c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0052ae9e  744b                   -je 0x52aeeb
    if (cpu.flags.zf)
    {
        goto L_0x0052aeeb;
    }
    // 0052aea0  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052aea3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052aea5  e8ea2f0000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052aeaa  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052aeb4  e912ffffff             -jmp 0x52adcb
    goto L_0x0052adcb;
L_0x0052aeb9:
    // 0052aeb9  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052aebd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052aec0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052aec2  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0052aec5  e87657fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052aeca  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052aed4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052aed9  c785480d000000000000   -mov dword ptr [ebp + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052aee3  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052aee6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052aee7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052aee8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052aee9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052aeea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052aeeb:
    // 0052aeeb  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0052aeee  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052aef3  894504                 -mov dword ptr [ebp + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052aef6  8b85440d0000           -mov eax, dword ptr [ebp + 0xd44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 0052aefc  c7450808000000         -mov dword ptr [ebp + 8], 8
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052af03  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052af06  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0052af09  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052af13  e9b3feffff             -jmp 0x52adcb
    goto L_0x0052adcb;
L_0x0052af18:
    // 0052af18  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052af1a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052af1c  e85f300000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052af21  c785500d0000b0010000   -mov dword ptr [ebp + 0xd50], 0x1b0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 0052af2b  e9a8feffff             -jmp 0x52add8
    goto L_0x0052add8;
}

/* align: skip  */
void Application::sub_52af30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052af30  c782440d000001000000   -mov dword ptr [edx + 0xd44], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 0052af3a  c782480d000000000000   -mov dword ptr [edx + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052af44  c7824c0d000000000000   -mov dword ptr [edx + 0xd4c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 0052af4e  c782500d000000000000   -mov dword ptr [edx + 0xd50], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052af58  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052af5c  c70270ad5200           -mov dword ptr [edx], 0x52ad70
    *app->getMemory<x86::reg32>(cpu.edx) = 5418352 /*0x52ad70*/;
    // 0052af62  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052af66  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 0052af6b  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052af71  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52af80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052af80  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052af81  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052af82  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052af83  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052af84  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052af87  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052af89  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052af8d  895c240c               -mov dword ptr [esp + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0052af91  8b90500d0000           -mov edx, dword ptr [eax + 0xd50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */);
    // 0052af97  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052af99  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052af9b  0f85eb000000           -jne 0x52b08c
    if (!cpu.flags.zf)
    {
        goto L_0x0052b08c;
    }
L_0x0052afa1:
    // 0052afa1  8d8584060000           -lea eax, [ebp + 0x684]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1668) /* 0x684 */);
    // 0052afa7  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052afaa  8d85480d0000           -lea eax, [ebp + 0xd48]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 0052afb0  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052afb4:
    // 0052afb4  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052afb8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052afba  0f8e2d010000           -jle 0x52b0ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b0ed;
    }
    // 0052afc0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052afc2  8b9d480d0000           -mov ebx, dword ptr [ebp + 0xd48]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 0052afc8  668b85540d0000         -mov ax, word ptr [ebp + 0xd54]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */);
    // 0052afcf  39d8                   +cmp eax, ebx
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
    // 0052afd1  0f8dcf000000           -jge 0x52b0a6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052b0a6;
    }
L_0x0052afd7:
    // 0052afd7  6683bd560d000000       +cmp word ptr [ebp + 0xd56], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052afdf  0f865d010000           -jbe 0x52b142
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052b142;
    }
L_0x0052afe5:
    // 0052afe5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052afe7  8b85480d0000           -mov eax, dword ptr [ebp + 0xd48]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 0052afed  668b95540d0000         -mov dx, word ptr [ebp + 0xd54]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */);
    // 0052aff4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052aff6  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052affa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052affc  39f8                   +cmp eax, edi
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
    // 0052affe  7e02                   -jle 0x52b002
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b002;
    }
    // 0052b000  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0052b002:
    // 0052b002  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b004  668b85560d0000         -mov ax, word ptr [ebp + 0xd56]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */);
    // 0052b00b  39d0                   +cmp eax, edx
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
    // 0052b00d  0f8c46010000           -jl 0x52b159
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b159;
    }
L_0x0052b013:
    // 0052b013  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 0052b018  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b01a  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b01e  668b85560d0000         -mov ax, word ptr [ebp + 0xd56]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */);
    // 0052b025  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 0052b02c  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b02e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052b031  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0052b034  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052b036  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052b038  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b039  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b03b  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052b03e  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 0052b040  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052b042  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052b045  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 0052b047  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b048  668b8d540d0000         -mov cx, word ptr [ebp + 0xd54]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */);
    // 0052b04f  668bb5560d0000         -mov si, word ptr [ebp + 0xd56]
    cpu.si = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */);
    // 0052b056  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052b058  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b05a  66898d540d0000         -mov word ptr [ebp + 0xd54], cx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */) = cpu.cx;
    // 0052b061  6689b5560d0000         -mov word ptr [ebp + 0xd56], si
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */) = cpu.si;
    // 0052b068  8bb5500d0000           -mov esi, dword ptr [ebp + 0xd50]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052b06e  8d0c1f                 -lea ecx, [edi + ebx]
    cpu.ecx = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 0052b071  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b075  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052b079  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052b07b  29d3                   +sub ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b07d  89b5500d0000           -mov dword ptr [ebp + 0xd50], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = cpu.esi;
    // 0052b083  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052b087  e928ffffff             -jmp 0x52afb4
    goto L_0x0052afb4;
L_0x0052b08c:
    // 0052b08c  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 0052b092  e80169feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052b097  c786500d000000000000   -mov dword ptr [esi + 0xd50], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052b0a1  e9fbfeffff             -jmp 0x52afa1
    goto L_0x0052afa1;
L_0x0052b0a6:
    // 0052b0a6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b0aa  8b854c0d0000           -mov eax, dword ptr [ebp + 0xd4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 0052b0b0  e84768feff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052b0b5  8985440d0000           -mov dword ptr [ebp + 0xd44], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */) = cpu.eax;
    // 0052b0bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052b0bd  753c                   -jne 0x52b0fb
    if (!cpu.flags.zf)
    {
        goto L_0x0052b0fb;
    }
    // 0052b0bf  83bd500d000000         +cmp dword ptr [ebp + 0xd50], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b0c6  7412                   -je 0x52b0da
    if (cpu.flags.zf)
    {
        goto L_0x0052b0da;
    }
    // 0052b0c8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b0cc  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0052b0d3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b0d5  e86655fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052b0da:
    // 0052b0da  66c785540d00000000     -mov word ptr [ebp + 0xd54], 0
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052b0e3  c785480d000000000000   -mov dword ptr [ebp + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
L_0x0052b0ed:
    // 0052b0ed  8b85500d0000           -mov eax, dword ptr [ebp + 0xd50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 0052b0f3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052b0f6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b0f7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b0f8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b0f9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b0fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b0fb:
    // 0052b0fb  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052b0fe  7416                   -je 0x52b116
    if (cpu.flags.zf)
    {
        goto L_0x0052b116;
    }
    // 0052b100  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0052b101  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052b103  e88c2d0000             -call 0x52de94
    cpu.esp -= 4;
    sub_52de94(app, cpu);
    if (cpu.terminate) return;
    // 0052b108  66c785540d00000000     -mov word ptr [ebp + 0xd54], 0
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052b111  e9c1feffff             -jmp 0x52afd7
    goto L_0x0052afd7;
L_0x0052b116:
    // 0052b116  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052b119  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052b11e  894504                 -mov dword ptr [ebp + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052b121  8b85440d0000           -mov eax, dword ptr [ebp + 0xd44]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 0052b127  c7450808000000         -mov dword ptr [ebp + 8], 8
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 0052b12e  83c002                 +add eax, 2
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b131  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0052b134  66c785540d00000000     -mov word ptr [ebp + 0xd54], 0
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052b13d  e995feffff             -jmp 0x52afd7
    goto L_0x0052afd7;
L_0x0052b142:
    // 0052b142  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052b144  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052b146  e8352e0000             -call 0x52df80
    cpu.esp -= 4;
    sub_52df80(app, cpu);
    if (cpu.terminate) return;
    // 0052b14b  66c785560d0000b001     -mov word ptr [ebp + 0xd56], 0x1b0
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(3414) /* 0xd56 */) = 432 /*0x1b0*/;
    // 0052b154  e98cfeffff             -jmp 0x52afe5
    goto L_0x0052afe5;
L_0x0052b159:
    // 0052b159  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b15b  e9b3feffff             -jmp 0x52b013
    goto L_0x0052b013;
}

/* align: skip  */
void Application::sub_52b160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b160  e8fb1f0000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052b165  c782440d000000000000   -mov dword ptr [edx + 0xd44], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3396) /* 0xd44 */) = 0 /*0x0*/;
    // 0052b16f  c782480d000000000000   -mov dword ptr [edx + 0xd48], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 0052b179  66c782540d00000000     -mov word ptr [edx + 0xd54], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(3412) /* 0xd54 */) = 0 /*0x0*/;
    // 0052b182  66c782560d00000000     -mov word ptr [edx + 0xd56], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(3414) /* 0xd56 */) = 0 /*0x0*/;
    // 0052b18b  89824c0d0000           -mov dword ptr [edx + 0xd4c], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3404) /* 0xd4c */) = cpu.eax;
    // 0052b191  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b195  c782500d000000000000   -mov dword ptr [edx + 0xd50], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 0052b19f  c70080af5200           -mov dword ptr [eax], 0x52af80
    *app->getMemory<x86::reg32>(cpu.eax) = 5418880 /*0x52af80*/;
    // 0052b1a5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052b1a9  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052b1af  b8580d0000             -mov eax, 0xd58
    cpu.eax = 3416 /*0xd58*/;
    // 0052b1b4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b1c0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b1c1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b1c2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052b1c4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0052b1c6  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0052b1c9  c0e407                 +shl ah, 7
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
    // 0052b1cc  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0052b1ce  00e4                   +add ah, ah
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
    // 0052b1d0  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0052b1d2  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052b1d4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052b1d9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052b1db  8b0485ac725600         -mov eax, dword ptr [eax*4 + 0x5672ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5665452) /* 0x5672ac */ + cpu.eax * 4);
    // 0052b1e2  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b1e4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b1e6  b900000100             -mov ecx, 0x10000
    cpu.ecx = 65536 /*0x10000*/;
    // 0052b1eb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b1ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b1ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b1f1  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0052b1f4  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0052b1f7  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0052b1f9  83f87f                 +cmp eax, 0x7f
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
    // 0052b1fc  7f16                   -jg 0x52b214
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b214;
    }
L_0x0052b1fe:
    // 0052b1fe  81c200000100           -add edx, 0x10000
    (cpu.edx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0052b204  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0052b207  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 0052b20a  893e                   -mov dword ptr [esi], edi
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 0052b20c  83ff7f                 +cmp edi, 0x7f
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b20f  7f0b                   -jg 0x52b21c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b21c;
    }
    // 0052b211  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b212  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b213  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b214:
    // 0052b214  c7037f000000           -mov dword ptr [ebx], 0x7f
    *app->getMemory<x86::reg32>(cpu.ebx) = 127 /*0x7f*/;
    // 0052b21a  ebe2                   -jmp 0x52b1fe
    goto L_0x0052b1fe;
L_0x0052b21c:
    // 0052b21c  c7067f000000           -mov dword ptr [esi], 0x7f
    *app->getMemory<x86::reg32>(cpu.esi) = 127 /*0x7f*/;
    // 0052b222  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b223  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b224  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b230  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b231  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b232  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b233  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052b235  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0052b237:
    // 0052b237  4a                     -dec edx
    (cpu.edx)--;
    // 0052b238  83faff                 +cmp edx, -1
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
    // 0052b23b  740c                   -je 0x52b249
    if (cpu.flags.zf)
    {
        goto L_0x0052b249;
    }
    // 0052b23d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052b23f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 0052b242  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0052b244  40                     -inc eax
    (cpu.eax)++;
    // 0052b245  01d9                   +add ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b247  ebee                   -jmp 0x52b237
    goto L_0x0052b237;
L_0x0052b249:
    // 0052b249  83fe01                 +cmp esi, 1
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
    // 0052b24c  7505                   -jne 0x52b253
    if (!cpu.flags.zf)
    {
        goto L_0x0052b253;
    }
    // 0052b24e  83f97f                 +cmp ecx, 0x7f
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
    // 0052b251  7f26                   -jg 0x52b279
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b279;
    }
L_0x0052b253:
    // 0052b253  83fe02                 +cmp esi, 2
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
    // 0052b256  7508                   -jne 0x52b260
    if (!cpu.flags.zf)
    {
        goto L_0x0052b260;
    }
    // 0052b258  81f9ff7f0000           +cmp ecx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b25e  7f21                   -jg 0x52b281
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b281;
    }
L_0x0052b260:
    // 0052b260  83fe03                 +cmp esi, 3
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b263  750e                   -jne 0x52b273
    if (!cpu.flags.zf)
    {
        goto L_0x0052b273;
    }
    // 0052b265  81f9ffff7f00           +cmp ecx, 0x7fffff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8388607 /*0x7fffff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b26b  7e06                   -jle 0x52b273
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b273;
    }
    // 0052b26d  81e900000001           -sub ecx, 0x1000000
    (cpu.ecx) -= x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
L_0x0052b273:
    // 0052b273  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b275  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b276  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b277  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b278  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b279:
    // 0052b279  81e900010000           +sub ecx, 0x100
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b27f  ebf2                   -jmp 0x52b273
    goto L_0x0052b273;
L_0x0052b281:
    // 0052b281  81e900000100           -sub ecx, 0x10000
    (cpu.ecx) -= x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 0052b287  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b289  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b28a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b28b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b28c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52b290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b290  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b291  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b292  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b293  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b296  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b298  8b15ec775600           -mov edx, dword ptr [0x5677ec]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5666796) /* 0x5677ec */);
    // 0052b29e  885c2404               -mov byte ptr [esp + 4], bl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 0052b2a2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052b2a4  7415                   -je 0x52b2bb
    if (cpu.flags.zf)
    {
        goto L_0x0052b2bb;
    }
    // 0052b2a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b2ab  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b2ad  ff15b0775600           -call dword ptr [0x5677b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666736) /* 0x5677b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b2b3  ff15ec775600           -call dword ptr [0x5677ec]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666796) /* 0x5677ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b2b9  eb30                   -jmp 0x52b2eb
    goto L_0x0052b2eb;
L_0x0052b2bb:
    // 0052b2bb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b2c0  ff1568775600           -call dword ptr [0x567768]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666664) /* 0x567768 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b2c6  e869a4feff             -call 0x515734
    cpu.esp -= 4;
    sub_515734(app, cpu);
    if (cpu.terminate) return;
    // 0052b2cb  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b2cc  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b2d0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b2d1  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0052b2d3  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052b2d7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b2d8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052b2d9  2eff153c465300         -call dword ptr cs:[0x53463c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5457468) /* 0x53463c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b2e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b2e5  ff156c775600           -call dword ptr [0x56776c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666668) /* 0x56776c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0052b2eb:
    // 0052b2eb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052b2ed  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b2f0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b2f1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b2f2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b2f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b300  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052b301  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052b303  60                     -pushal 
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    *app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    *app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    *app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    *app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    *app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    *app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    *app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 0052b304  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052b307  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052b30a  8b15f481a100           -mov edx, dword ptr [0xa181f4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10584564) /* 0xa181f4 */);
    // 0052b310  a1a4d2a000             -mov eax, dword ptr [0xa0d2a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10539684) /* 0xa0d2a4 */);
    // 0052b315  8b1db481a100           -mov ebx, dword ptr [0xa181b4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584500) /* 0xa181b4 */);
    // 0052b31b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b31e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052b321:
    // 0052b321  3bc2                   +cmp eax, edx
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
    // 0052b323  7c05                   -jl 0x52b32a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b32a;
    }
    // 0052b325  a1c481a100             -mov eax, dword ptr [0xa181c4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10584516) /* 0xa181c4 */);
L_0x0052b32a:
    // 0052b32a  3bda                   +cmp ebx, edx
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
    // 0052b32c  7c06                   -jl 0x52b334
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b334;
    }
    // 0052b32e  8b1dc481a100           -mov ebx, dword ptr [0xa181c4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584516) /* 0xa181c4 */);
L_0x0052b334:
    // 0052b334  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edi)));
    // 0052b336  d805e481a100           -fadd dword ptr [0xa181e4]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(x86::reg32(10584548) /* 0xa181e4 */));
    // 0052b33c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 0052b33e  a3a4d2a000             -mov dword ptr [0xa0d2a4], eax
    *app->getMemory<x86::reg32>(x86::reg32(10539684) /* 0xa0d2a4 */) = cpu.eax;
    // 0052b343  891db481a100           -mov dword ptr [0xa181b4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10584500) /* 0xa181b4 */) = cpu.ebx;
    // 0052b349  d80d50ae5600           -fmul dword ptr [0x56ae50]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680720) /* 0x56ae50 */));
    // 0052b34f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b351  d910                   -fst dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 0052b353  d80d50ae5600           -fmul dword ptr [0x56ae50]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680720) /* 0x56ae50 */));
    // 0052b359  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b35b  d91de481a100           -fstp dword ptr [0xa181e4]
    *app->getMemory<float>(x86::reg32(10584548) /* 0xa181e4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b361  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebx) - cpu.fpu.st(0);
    // 0052b363  8b15f881a100           -mov edx, dword ptr [0xa181f8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10584568) /* 0xa181f8 */);
    // 0052b369  a1a8d2a000             -mov eax, dword ptr [0xa0d2a8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10539688) /* 0xa0d2a8 */);
    // 0052b36e  8b1db881a100           -mov ebx, dword ptr [0xa181b8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584504) /* 0xa181b8 */);
    // 0052b374  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b377  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b37a  3bc2                   +cmp eax, edx
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
    // 0052b37c  7c05                   -jl 0x52b383
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b383;
    }
    // 0052b37e  a1c881a100             -mov eax, dword ptr [0xa181c8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10584520) /* 0xa181c8 */);
L_0x0052b383:
    // 0052b383  3bda                   +cmp ebx, edx
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
    // 0052b385  7c06                   -jl 0x52b38d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b38d;
    }
    // 0052b387  8b1dc881a100           -mov ebx, dword ptr [0xa181c8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584520) /* 0xa181c8 */);
L_0x0052b38d:
    // 0052b38d  d805e881a100           -fadd dword ptr [0xa181e8]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(x86::reg32(10584552) /* 0xa181e8 */));
    // 0052b393  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 0052b395  a3a8d2a000             -mov dword ptr [0xa0d2a8], eax
    *app->getMemory<x86::reg32>(x86::reg32(10539688) /* 0xa0d2a8 */) = cpu.eax;
    // 0052b39a  891db881a100           -mov dword ptr [0xa181b8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10584504) /* 0xa181b8 */) = cpu.ebx;
    // 0052b3a0  d80d54ae5600           -fmul dword ptr [0x56ae54]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680724) /* 0x56ae54 */));
    // 0052b3a6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b3a8  d910                   -fst dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 0052b3aa  d80d54ae5600           -fmul dword ptr [0x56ae54]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680724) /* 0x56ae54 */));
    // 0052b3b0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b3b2  d91de881a100           -fstp dword ptr [0xa181e8]
    *app->getMemory<float>(x86::reg32(10584552) /* 0xa181e8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b3b8  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebx) - cpu.fpu.st(0);
    // 0052b3ba  d90524ae5600           -fld dword ptr [0x56ae24]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5680676) /* 0x56ae24 */)));
    // 0052b3c0  d80d34ae5600           -fmul dword ptr [0x56ae34]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680692) /* 0x56ae34 */));
    // 0052b3c6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b3c8  d80d44ae5600           -fmul dword ptr [0x56ae44]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680708) /* 0x56ae44 */));
    // 0052b3ce  a1acd2a000             -mov eax, dword ptr [0xa0d2ac]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10539692) /* 0xa0d2ac */);
    // 0052b3d3  8b1dbc81a100           -mov ebx, dword ptr [0xa181bc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584508) /* 0xa181bc */);
    // 0052b3d9  8b15fc81a100           -mov edx, dword ptr [0xa181fc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10584572) /* 0xa181fc */);
    // 0052b3df  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052b3e1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b3e4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b3e7  3bc2                   +cmp eax, edx
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
    // 0052b3e9  7c05                   -jl 0x52b3f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b3f0;
    }
    // 0052b3eb  a1cc81a100             -mov eax, dword ptr [0xa181cc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10584524) /* 0xa181cc */);
L_0x0052b3f0:
    // 0052b3f0  3bda                   +cmp ebx, edx
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
    // 0052b3f2  7c06                   -jl 0x52b3fa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b3fa;
    }
    // 0052b3f4  8b1dcc81a100           -mov ebx, dword ptr [0xa181cc]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584524) /* 0xa181cc */);
L_0x0052b3fa:
    // 0052b3fa  d91524ae5600           -fst dword ptr [0x56ae24]
    *app->getMemory<float>(x86::reg32(5680676) /* 0x56ae24 */) = float(cpu.fpu.st(0));
    // 0052b400  d805ec81a100           -fadd dword ptr [0xa181ec]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(x86::reg32(10584556) /* 0xa181ec */));
    // 0052b406  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 0052b408  a3acd2a000             -mov dword ptr [0xa0d2ac], eax
    *app->getMemory<x86::reg32>(x86::reg32(10539692) /* 0xa0d2ac */) = cpu.eax;
    // 0052b40d  891dbc81a100           -mov dword ptr [0xa181bc], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10584508) /* 0xa181bc */) = cpu.ebx;
    // 0052b413  d80d58ae5600           -fmul dword ptr [0x56ae58]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680728) /* 0x56ae58 */));
    // 0052b419  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b41b  d910                   -fst dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 0052b41d  d80d58ae5600           -fmul dword ptr [0x56ae58]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680728) /* 0x56ae58 */));
    // 0052b423  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b425  d91dec81a100           -fstp dword ptr [0xa181ec]
    *app->getMemory<float>(x86::reg32(10584556) /* 0xa181ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b42b  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebx) - cpu.fpu.st(0);
    // 0052b42d  8b150082a100           -mov edx, dword ptr [0xa18200]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10584576) /* 0xa18200 */);
    // 0052b433  a1b0d2a000             -mov eax, dword ptr [0xa0d2b0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10539696) /* 0xa0d2b0 */);
    // 0052b438  8b1dc081a100           -mov ebx, dword ptr [0xa181c0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584512) /* 0xa181c0 */);
    // 0052b43e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b441  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b444  3bc2                   +cmp eax, edx
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
    // 0052b446  7c05                   -jl 0x52b44d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b44d;
    }
    // 0052b448  a1d081a100             -mov eax, dword ptr [0xa181d0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10584528) /* 0xa181d0 */);
L_0x0052b44d:
    // 0052b44d  3bda                   +cmp ebx, edx
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
    // 0052b44f  7c06                   -jl 0x52b457
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b457;
    }
    // 0052b451  8b1dd081a100           -mov ebx, dword ptr [0xa181d0]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584528) /* 0xa181d0 */);
L_0x0052b457:
    // 0052b457  d805f081a100           -fadd dword ptr [0xa181f0]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(x86::reg32(10584560) /* 0xa181f0 */));
    // 0052b45d  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.ebx)));
    // 0052b45f  a3b0d2a000             -mov dword ptr [0xa0d2b0], eax
    *app->getMemory<x86::reg32>(x86::reg32(10539696) /* 0xa0d2b0 */) = cpu.eax;
    // 0052b464  891dc081a100           -mov dword ptr [0xa181c0], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10584512) /* 0xa181c0 */) = cpu.ebx;
    // 0052b46a  d80d5cae5600           -fmul dword ptr [0x56ae5c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680732) /* 0x56ae5c */));
    // 0052b470  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b472  d910                   -fst dword ptr [eax]
    *app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 0052b474  d80d5cae5600           -fmul dword ptr [0x56ae5c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680732) /* 0x56ae5c */));
    // 0052b47a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b47c  d91df081a100           -fstp dword ptr [0xa181f0]
    *app->getMemory<float>(x86::reg32(10584560) /* 0xa181f0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b482  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = *app->getMemory<float>(cpu.ebx) - cpu.fpu.st(0);
    // 0052b484  d9052cae5600           -fld dword ptr [0x56ae2c]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(x86::reg32(5680684) /* 0x56ae2c */)));
    // 0052b48a  d80d3cae5600           -fmul dword ptr [0x56ae3c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680700) /* 0x56ae3c */));
    // 0052b490  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0052b492  d80d4cae5600           -fmul dword ptr [0x56ae4c]
    cpu.fpu.st(0) *= x86::Float(*app->getMemory<float>(x86::reg32(5680716) /* 0x56ae4c */));
    // 0052b498  8b15f481a100           -mov edx, dword ptr [0xa181f4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10584564) /* 0xa181f4 */);
    // 0052b49e  a1a4d2a000             -mov eax, dword ptr [0xa0d2a4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10539684) /* 0xa0d2a4 */);
    // 0052b4a3  8b1db481a100           -mov ebx, dword ptr [0xa181b4]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10584500) /* 0xa181b4 */);
    // 0052b4a9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0052b4ab  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4ae  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4b1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4b4  d9152cae5600           -fst dword ptr [0x56ae2c]
    *app->getMemory<float>(x86::reg32(5680684) /* 0x56ae2c */) = float(cpu.fpu.st(0));
    // 0052b4ba  d95ffc                 -fstp dword ptr [edi - 4]
    *app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b4bd  83e901                 +sub ecx, 1
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b4c0  0f8f5bfeffff           -jg 0x52b321
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b321;
    }
    // 0052b4c6  61                     -popal 
    {
        cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 0052b4c7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b4c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b4d0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b4d4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b4d8  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b4dc  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0052b4df  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052b4e1  39c8                   +cmp eax, ecx
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
    // 0052b4e3  7313                   -jae 0x52b4f8
    if (!cpu.flags.cf)
    {
        goto L_0x0052b4f8;
    }
L_0x0052b4e5:
    // 0052b4e5  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(*app->getMemory<float>(cpu.edx)));
    // 0052b4e7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052b4ea  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(*app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 0052b4ed  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b4f0  d958fc                 -fstp dword ptr [eax - 4]
    *app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0052b4f3  39c8                   +cmp eax, ecx
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
    // 0052b4f5  72ee                   -jb 0x52b4e5
    if (cpu.flags.cf)
    {
        goto L_0x0052b4e5;
    }
    // 0052b4f7  90                     -nop 
    ;
L_0x0052b4f8:
    // 0052b4f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b500  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b501  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052b503  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0052b506  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b508  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0052b50b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b50d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b50f  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0052b512  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b514  05b4bc9f00             -add eax, 0x9fbcb4
    (cpu.eax) += x86::reg32(x86::sreg32(10468532 /*0x9fbcb4*/));
    // 0052b519  884803                 -mov byte ptr [eax + 3], cl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 0052b51c  e83351fdff             -call 0x500654
    cpu.esp -= 4;
    sub_500654(app, cpu);
    if (cpu.terminate) return;
    // 0052b521  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b522  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b523(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b523  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052b524  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0052b526  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052b527  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b528  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b529  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b52a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b52d  8a6518                 -mov ah, byte ptr [ebp + 0x18]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0052b530  80fc01                 +cmp ah, 1
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
    // 0052b533  772f                   -ja 0x52b564
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052b564;
    }
    // 0052b535  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0052b537  7524                   -jne 0x52b55d
    if (!cpu.flags.zf)
    {
        goto L_0x0052b55d;
    }
    // 0052b539  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b53b  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    cpu.fpu.pop();
    // 0052b53e  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b540  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b541  730a                   -jae 0x52b54d
    if (!cpu.flags.cf)
    {
        goto L_0x0052b54d;
    }
    // 0052b543  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0052b545  894de8                 -mov dword ptr [ebp - 0x18], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 0052b548  894dec                 -mov dword ptr [ebp - 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 0052b54b  eb4f                   -jmp 0x52b59c
    goto L_0x0052b59c;
L_0x0052b54d:
    // 0052b54d  7607                   -jbe 0x52b556
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052b556;
    }
    // 0052b54f  b847800000             -mov eax, 0x8047
    cpu.eax = 32839 /*0x8047*/;
    // 0052b554  eb38                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b556:
    // 0052b556  b847400000             -mov eax, 0x4047
    cpu.eax = 16455 /*0x4047*/;
    // 0052b55b  eb31                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b55d:
    // 0052b55d  b847200000             -mov eax, 0x2047
    cpu.eax = 8263 /*0x2047*/;
    // 0052b562  eb2a                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b564:
    // 0052b564  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b566  dc5d10                 +fcomp qword ptr [ebp + 0x10]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    cpu.fpu.pop();
    // 0052b569  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b56b  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b56c  720a                   -jb 0x52b578
    if (cpu.flags.cf)
    {
        goto L_0x0052b578;
    }
    // 0052b56e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052b570  8955e8                 -mov dword ptr [ebp - 0x18], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 0052b573  8955ec                 -mov dword ptr [ebp - 0x14], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 0052b576  eb24                   -jmp 0x52b59c
    goto L_0x0052b59c;
L_0x0052b578:
    // 0052b578  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 0052b57a  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), *app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    cpu.fpu.pop();
    // 0052b57d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0052b57f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0052b580  7307                   -jae 0x52b589
    if (!cpu.flags.cf)
    {
        goto L_0x0052b589;
    }
    // 0052b582  b807810000             -mov eax, 0x8107
    cpu.eax = 33031 /*0x8107*/;
    // 0052b587  eb05                   -jmp 0x52b58e
    goto L_0x0052b58e;
L_0x0052b589:
    // 0052b589  b807110000             -mov eax, 0x1107
    cpu.eax = 4359 /*0x1107*/;
L_0x0052b58e:
    // 0052b58e  8d5d10                 -lea ebx, [ebp + 0x10]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0052b591  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052b594  e8188effff             -call 0x5243b1
    cpu.esp -= 4;
    sub_5243b1(app, cpu);
    if (cpu.terminate) return;
    // 0052b599  dd5de8                 -fstp qword ptr [ebp - 0x18]
    *app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x0052b59c:
    // 0052b59c  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 0052b59f  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0052b5a2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a5  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b5a7  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b5b0  833d00b2a00000         +cmp dword ptr [0xa0b200], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10531328) /* 0xa0b200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b5b7  741c                   -je 0x52b5d5
    if (cpu.flags.zf)
    {
        goto L_0x0052b5d5;
    }
    // 0052b5b9  8a00                   -mov al, byte ptr [eax]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax);
    // 0052b5bb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052b5c0  8a8011b2a000           -mov al, byte ptr [eax + 0xa0b211]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10531345) /* 0xa0b211 */);
    // 0052b5c6  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0052b5c8  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0052b5cd  7406                   -je 0x52b5d5
    if (cpu.flags.zf)
    {
        goto L_0x0052b5d5;
    }
    // 0052b5cf  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0052b5d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b5d5:
    // 0052b5d5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b5da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b5e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b5e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b5e2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b5e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b5e7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052b5e9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b5eb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b5ed  e81e2d0000             -call 0x52e310
    cpu.esp -= 4;
    sub_52e310(app, cpu);
    if (cpu.terminate) return;
    // 0052b5f2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052b5f4  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052b5f6  e8b5ffffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b5fb  881404                 -mov byte ptr [esp + eax], dl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 0052b5fe  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b602  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052b604  e8072d0000             -call 0x52e310
    cpu.esp -= 4;
    sub_52e310(app, cpu);
    if (cpu.terminate) return;
    // 0052b609  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b60b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0052b60d  e89effffff             -call 0x52b5b0
    cpu.esp -= 4;
    sub_52b5b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b612  88740404               -mov byte ptr [esp + eax + 4], dh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 0052b616  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b618  e8332d0000             -call 0x52e350
    cpu.esp -= 4;
    sub_52e350(app, cpu);
    if (cpu.terminate) return;
    // 0052b61d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b621  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b625  e8262d0000             -call 0x52e350
    cpu.esp -= 4;
    sub_52e350(app, cpu);
    if (cpu.terminate) return;
    // 0052b62a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b62c  e86f2d0000             -call 0x52e3a0
    cpu.esp -= 4;
    sub_52e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0052b631  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052b634  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b635  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b636  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b640  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b641(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b641  a36cb15600             -mov dword ptr [0x56b16c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5681516) /* 0x56b16c */) = cpu.eax;
    // 0052b646  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b647(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b647  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b648  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b649  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b64a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052b64c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052b64e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0052b653  e8a82d0000             -call 0x52e400
    cpu.esp -= 4;
    sub_52e400(app, cpu);
    if (cpu.terminate) return;
    // 0052b658  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b65a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b65c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b65e  8b048550b15600         -mov eax, dword ptr [eax*4 + 0x56b150]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5681488) /* 0x56b150 */ + cpu.eax * 4);
    // 0052b665  e816c7fcff             -call 0x4f7d80
    cpu.esp -= 4;
    sub_4f7d80(app, cpu);
    if (cpu.terminate) return;
    // 0052b66a  b8ed1f5500             -mov eax, 0x551fed
    cpu.eax = 5578733 /*0x551fed*/;
    // 0052b66f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b671  e80ac7fcff             -call 0x4f7d80
    cpu.esp -= 4;
    sub_4f7d80(app, cpu);
    if (cpu.terminate) return;
    // 0052b676  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b678  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b67a  e801c7fcff             -call 0x4f7d80
    cpu.esp -= 4;
    sub_4f7d80(app, cpu);
    if (cpu.terminate) return;
    // 0052b67f  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 0052b684  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b686  e825e1fdff             -call 0x5097b0
    cpu.esp -= 4;
    sub_5097b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b68b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b68c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b68d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b68e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b68f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b68f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b690  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b691  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052b693  ff156cb15600           -call dword ptr [0x56b16c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5681516) /* 0x56b16c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052b699  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052b69b  751b                   -jne 0x52b6b8
    if (!cpu.flags.zf)
    {
        goto L_0x0052b6b8;
    }
    // 0052b69d  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052b6a0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0052b6a2  e8a0ffffff             -call 0x52b647
    cpu.esp -= 4;
    sub_52b647(app, cpu);
    if (cpu.terminate) return;
    // 0052b6a7  833b01                 +cmp dword ptr [ebx], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b6aa  7507                   -jne 0x52b6b3
    if (!cpu.flags.zf)
    {
        goto L_0x0052b6b3;
    }
    // 0052b6ac  e8df71fdff             -call 0x502890
    cpu.esp -= 4;
    sub_502890(app, cpu);
    if (cpu.terminate) return;
    // 0052b6b1  eb05                   -jmp 0x52b6b8
    goto L_0x0052b6b8;
L_0x0052b6b3:
    // 0052b6b3  e8ec71fdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
L_0x0052b6b8:
    // 0052b6b8  dd4318                 -fld qword ptr [ebx + 0x18]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 0052b6bb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b6bc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b6bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_52b6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b6c0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b6c1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b6c2  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052b6c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052b6c8  7c3b                   -jl 0x52b705
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b705;
    }
L_0x0052b6ca:
    // 0052b6ca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052b6cc  7c3b                   -jl 0x52b709
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b709;
    }
L_0x0052b6ce:
    // 0052b6ce  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052b6d1  39f2                   +cmp edx, esi
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
    // 0052b6d3  7e02                   -jle 0x52b6d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b6d7;
    }
    // 0052b6d5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0052b6d7:
    // 0052b6d7  39f1                   +cmp ecx, esi
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
    // 0052b6d9  7e02                   -jle 0x52b6dd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b6dd;
    }
    // 0052b6db  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0052b6dd:
    // 0052b6dd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052b6df  7c2c                   -jl 0x52b70d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b70d;
    }
L_0x0052b6e1:
    // 0052b6e1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052b6e3  7c2c                   -jl 0x52b711
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052b711;
    }
L_0x0052b6e5:
    // 0052b6e5  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052b6e8  39f3                   +cmp ebx, esi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b6ea  7e02                   -jle 0x52b6ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b6ee;
    }
    // 0052b6ec  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x0052b6ee:
    // 0052b6ee  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b6f0  7e02                   -jle 0x52b6f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052b6f4;
    }
    // 0052b6f2  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x0052b6f4:
    // 0052b6f4  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0052b6f7  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0052b6fa  897818                 -mov dword ptr [eax + 0x18], edi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0052b6fd  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052b700  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b701  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b702  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052b705:
    // 0052b705  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052b707  ebc1                   -jmp 0x52b6ca
    goto L_0x0052b6ca;
L_0x0052b709:
    // 0052b709  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0052b70b  ebc1                   -jmp 0x52b6ce
    goto L_0x0052b6ce;
L_0x0052b70d:
    // 0052b70d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0052b70f  ebd0                   -jmp 0x52b6e1
    goto L_0x0052b6e1;
L_0x0052b711:
    // 0052b711  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0052b713  ebd0                   -jmp 0x52b6e5
    goto L_0x0052b6e5;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b720  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b721  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b722  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052b723  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052b726  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052b728  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052b72a  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052b72e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052b730  39d8                   +cmp eax, ebx
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
    // 0052b732  0f8f84000000           -jg 0x52b7bc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052b7bc;
    }
L_0x0052b738:
    // 0052b738  39fd                   +cmp ebp, edi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b73a  7d06                   -jge 0x52b742
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052b742;
    }
    // 0052b73c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052b73e  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0052b740  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x0052b742:
    // 0052b742  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b746  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052b748  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052b74c  40                     -inc eax
    (cpu.eax)++;
    // 0052b74d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052b74f  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052b752  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052b754  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b755  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052b757  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052b75c  48                     -dec eax
    (cpu.eax)--;
    // 0052b75d  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b761  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052b765  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b767  47                     -inc edi
    (cpu.edi)++;
    // 0052b768  e8d31dfdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052b76d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052b771  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b775  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052b779  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b77a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052b77c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052b781  e8ba1dfdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052b786  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052b78a  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052b78e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0052b793  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052b794  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052b796  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b798  e8a31dfdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052b79d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052b7a1  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052b7a6  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052b7a9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b7aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b7ac  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052b7ae  e88d1dfdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052b7b3  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052b7b6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b7b7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b7b8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b7b9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0052b7bc:
    // 0052b7bc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052b7be  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052b7c2  e971ffffff             -jmp 0x52b738
    goto L_0x0052b738;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b7d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b7d1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b7d2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b7d3  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b7d9  813d9472560080b55000   +cmp dword ptr [0x567294], 0x50b580
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5665428) /* 0x567294 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5289344 /*0x50b580*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b7e3  7444                   -je 0x52b829
    if (cpu.flags.zf)
    {
        goto L_0x0052b829;
    }
L_0x0052b7e5:
    // 0052b7e5  8d84241c010000         -lea eax, [esp + 0x11c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0052b7ec  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0052b7f3  8b942418010000         -mov edx, dword ptr [esp + 0x118]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 0052b7fa  89842400010000         -mov dword ptr [esp + 0x100], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052b801  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b803  e86c3efbff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0052b808  8b942414010000         -mov edx, dword ptr [esp + 0x114]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0052b80f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b811  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0052b813  e848000000             -call 0x52b860
    cpu.esp -= 4;
    sub_52b860(app, cpu);
    if (cpu.terminate) return;
    // 0052b818  89bc2400010000         -mov dword ptr [esp + 0x100], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edi;
    // 0052b81f  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b825  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b826  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b827  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b828  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052b829:
    // 0052b829  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b82a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b82b  b9f41f5500             -mov ecx, 0x551ff4
    cpu.ecx = 5578740 /*0x551ff4*/;
    // 0052b830  bb04205500             -mov ebx, 0x552004
    cpu.ebx = 5578756 /*0x552004*/;
    // 0052b835  be3c000000             -mov esi, 0x3c
    cpu.esi = 60 /*0x3c*/;
    // 0052b83a  6810205500             -push 0x552010
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5578768 /*0x552010*/;
    cpu.esp -= 4;
    // 0052b83f  890d90215500           -mov dword ptr [0x552190], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ecx;
    // 0052b845  891d94215500           -mov dword ptr [0x552194], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.ebx;
    // 0052b84b  893598215500           -mov dword ptr [0x552198], esi
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.esi;
    // 0052b851  e8ba57edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052b856  83c404                 +add esp, 4
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
    // 0052b859  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b85a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b85b  eb88                   -jmp 0x52b7e5
    goto L_0x0052b7e5;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52b860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b860  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b861  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b862  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b863  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052b864  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052b866  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052b868  e88346fcff             -call 0x4efef0
    cpu.esp -= 4;
    sub_4efef0(app, cpu);
    if (cpu.terminate) return;
    // 0052b86d  8b1584435600           -mov edx, dword ptr [0x564384]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5653380) /* 0x564384 */);
    // 0052b873  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052b875  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052b877  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052b87a  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b87c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0052b87e  8b3df8715600           -mov edi, dword ptr [0x5671f8]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */);
    // 0052b884  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b886  8b35fc715600           -mov esi, dword ptr [0x5671fc]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */);
    // 0052b88c  e8bf4ffcff             -call 0x4f0850
    cpu.esp -= 4;
    sub_4f0850(app, cpu);
    if (cpu.terminate) return;
    // 0052b891  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052b893  e8b842fcff             -call 0x4efb50
    cpu.esp -= 4;
    sub_4efb50(app, cpu);
    if (cpu.terminate) return;
    // 0052b898  893df8715600           -mov dword ptr [0x5671f8], edi
    *app->getMemory<x86::reg32>(x86::reg32(5665272) /* 0x5671f8 */) = cpu.edi;
    // 0052b89e  8935fc715600           -mov dword ptr [0x5671fc], esi
    *app->getMemory<x86::reg32>(x86::reg32(5665276) /* 0x5671fc */) = cpu.esi;
    // 0052b8a4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8a5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8a6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8a7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b8b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b8b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b8b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b8b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b8b3  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052b8b6  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052b8b9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b8ba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052b8bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b8be  e8fdfdffff             -call 0x52b6c0
    cpu.esp -= 4;
    sub_52b6c0(app, cpu);
    if (cpu.terminate) return;
    // 0052b8c3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8c4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8c5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b8c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52b8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b8d0  b870b15600             -mov eax, 0x56b170
    cpu.eax = 5681520 /*0x56b170*/;
    // 0052b8d5  e946bdf6ff             -jmp 0x497620
    return sub_497620(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52b8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b8e0  e83bf4fbff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 0052b8e5  e9362b0000             -jmp 0x52e420
    return sub_52e420(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52b8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b8f0  e99bf4fbff             -jmp 0x4ead90
    return sub_4ead90(app, cpu);
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_52b910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052b910  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b911  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052b914  7707                   -ja 0x52b91d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052b91d;
    }
    // 0052b916  ff2485f8b85200         -jmp dword ptr [eax*4 + 0x52b8f8]
    cpu.ip = *app->getMemory<x86::reg32>(5421304 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052b91d:
L_0x0052b91d:
    // 0052b91d  a1f84f5600             -mov eax, dword ptr [0x564ff8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052b922  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b924  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052b927  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052b92a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0052b92c  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0052b92f  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0052b930  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b932  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b934  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b935  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052b936:
    // 0052b936  a1fc4f5600             -mov eax, dword ptr [0x564ffc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052b93b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052b93d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052b940  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052b943  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0052b945  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0052b948  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0052b949  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b94b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b94d  48                     -dec eax
    (cpu.eax)--;
    // 0052b94e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b94f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052b950:
    // 0052b950  a1f84f5600             -mov eax, dword ptr [0x564ff8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052b955  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b956  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052b957:
    // 0052b957  a1fc4f5600             -mov eax, dword ptr [0x564ffc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052b95c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b95d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052b95e:
    // 0052b95e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052b963  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b964  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_52b970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b970  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b971  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b972  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b973  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b974  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b97a  8bb4241c010000         -mov esi, dword ptr [esp + 0x11c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0052b981  8b8c2418010000         -mov ecx, dword ptr [esp + 0x118]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 0052b988  8d842424010000         -lea eax, [esp + 0x124]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0052b98f  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0052b996  8b942420010000         -mov edx, dword ptr [esp + 0x120]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0052b99d  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0052b9a0  89842400010000         -mov dword ptr [esp + 0x100], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052b9a7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b9a9  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0052b9ac  e8c33cfbff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0052b9b1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b9b3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052b9b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052b9b7  e8242b0000             -call 0x52e4e0
    cpu.esp -= 4;
    sub_52e4e0(app, cpu);
    if (cpu.terminate) return;
    // 0052b9bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b9be  89942400010000         -mov dword ptr [esp + 0x100], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 0052b9c5  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b9cb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9ce  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cf  90                     -nop 
    ;
    // 0052b9d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52b9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052b9d0;
    // 0052b970  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052b971  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052b972  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052b973  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b974  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b97a  8bb4241c010000         -mov esi, dword ptr [esp + 0x11c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0052b981  8b8c2418010000         -mov ecx, dword ptr [esp + 0x118]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 0052b988  8d842424010000         -lea eax, [esp + 0x124]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0052b98f  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0052b996  8b942420010000         -mov edx, dword ptr [esp + 0x120]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0052b99d  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0052b9a0  89842400010000         -mov dword ptr [esp + 0x100], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052b9a7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b9a9  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0052b9ac  e8c33cfbff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0052b9b1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052b9b3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052b9b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052b9b7  e8242b0000             -call 0x52e4e0
    cpu.esp -= 4;
    sub_52e4e0(app, cpu);
    if (cpu.terminate) return;
    // 0052b9bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052b9be  89942400010000         -mov dword ptr [esp + 0x100], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 0052b9c5  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052b9cb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9ce  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9cf  90                     -nop 
    ;
L_entry_0x0052b9d0:
    // 0052b9d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_52b9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052b9e0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052b9e1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052b9e3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052b9e5  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0052b9ea  e8713dfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0052b9ef  e8bc37fcff             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 0052b9f4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0052b9f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052b9f8  e8c34ffcff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 0052b9fd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052b9fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52ba00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ba00  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ba01  e86a000000             -call 0x52ba70
    cpu.esp -= 4;
    sub_52ba70(app, cpu);
    if (cpu.terminate) return;
    // 0052ba06  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052ba08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052ba0a  e861000000             -call 0x52ba70
    cpu.esp -= 4;
    sub_52ba70(app, cpu);
    if (cpu.terminate) return;
    // 0052ba0f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052ba11  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ba13  e8183efcff             -call 0x4ef830
    cpu.esp -= 4;
    sub_4ef830(app, cpu);
    if (cpu.terminate) return;
    // 0052ba18  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ba19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52ba70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052ba70  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ba73  7707                   -ja 0x52ba7c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052ba7c;
    }
    // 0052ba75  ff24851cba5200         -jmp dword ptr [eax*4 + 0x52ba1c]
    cpu.ip = *app->getMemory<x86::reg32>(5421596 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052ba7c:
L_0x0052ba7c:
    // 0052ba7c  b8aaaa00ff             -mov eax, 0xff00aaaa
    cpu.eax = 4278233770 /*0xff00aaaa*/;
    // 0052ba81  e9da3cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052ba86:
    // 0052ba86  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0052ba8b  e9d03cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052ba90:
    // 0052ba90  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052ba95  e9c63cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052ba9a:
    // 0052ba9a  b80000aaff             -mov eax, 0xffaa0000
    cpu.eax = 4289331200 /*0xffaa0000*/;
    // 0052ba9f  e9bc3cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052baa4:
    // 0052baa4  b850ffffff             -mov eax, 0xffffff50
    cpu.eax = 4294967120 /*0xffffff50*/;
    // 0052baa9  e9b23cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  case 0x0052baae:
    // 0052baae  b8aa0000ff             -mov eax, 0xff0000aa
    cpu.eax = 4278190250 /*0xff0000aa*/;
    // 0052bab3  e9a83cfcff             -jmp 0x4ef760
    return sub_4ef760(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52bac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bac0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bac1  b8e0004f00             -mov eax, 0x4f00e0
    cpu.eax = 5177568 /*0x4f00e0*/;
    // 0052bac6  e82546fcff             -call 0x4f00f0
    cpu.esp -= 4;
    sub_4f00f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bacb:
    // 0052bacb  e85046fcff             -call 0x4f0120
    cpu.esp -= 4;
    sub_4f0120(app, cpu);
    if (cpu.terminate) return;
    // 0052bad0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052bad2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bad4  74f5                   -je 0x52bacb
    if (cpu.flags.zf)
    {
        goto L_0x0052bacb;
    }
    // 0052bad6  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bad9  7c08                   -jl 0x52bae3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052bae3;
    }
    // 0052badb  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bade  7f03                   -jg 0x52bae3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052bae3;
    }
    // 0052bae0  8d50e0                 -lea edx, [eax - 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-32) /* -0x20 */);
L_0x0052bae3:
    // 0052bae3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052bae5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bae6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_52baf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052baf0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052baf1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052baf3  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052baf7  e874ffffff             -call 0x52ba70
    cpu.esp -= 4;
    sub_52ba70(app, cpu);
    if (cpu.terminate) return;
    // 0052bafc  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0052baff  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0052bb02  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0052bb05  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052bb06  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0052bb09  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052bb0b  e8301afdff             -call 0x4fd540
    cpu.esp -= 4;
    sub_4fd540(app, cpu);
    if (cpu.terminate) return;
    // 0052bb10  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bb11  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52bb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bb20  b898b15600             -mov eax, 0x56b198
    cpu.eax = 5681560 /*0x56b198*/;
    // 0052bb25  e9f6baf6ff             -jmp 0x497620
    return sub_497620(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52bb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052bb50  83f804                 +cmp eax, 4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bb53  7707                   -ja 0x52bb5c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052bb5c;
    }
    // 0052bb55  ff248534bb5200         -jmp dword ptr [eax*4 + 0x52bb34]
    cpu.ip = *app->getMemory<x86::reg32>(5421876 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052bb5c:
L_0x0052bb5c:
    // 0052bb5c  b850000000             -mov eax, 0x50
    cpu.eax = 80 /*0x50*/;
    // 0052bb61  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bb62:
    // 0052bb62  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0052bb67  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bb68:
    // 0052bb68  a1f84f5600             -mov eax, dword ptr [0x564ff8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656568) /* 0x564ff8 */);
    // 0052bb6d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bb6e:
    // 0052bb6e  a1fc4f5600             -mov eax, dword ptr [0x564ffc]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5656572) /* 0x564ffc */);
    // 0052bb73  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bb74:
    // 0052bb74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bb76  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_52bb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bb80  e91b51fbff             -jmp 0x4e0ca0
    return sub_4e0ca0(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_52bb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bb90  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bb91  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052bb93  e888f1fbff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 0052bb98  e883280000             -call 0x52e420
    cpu.esp -= 4;
    sub_52e420(app, cpu);
    if (cpu.terminate) return;
    // 0052bb9d  8b5602                 -mov edx, dword ptr [esi + 2]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0052bba0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0052bba5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0052bba8  e8a3ffffff             -call 0x52bb50
    cpu.esp -= 4;
    sub_52bb50(app, cpu);
    if (cpu.terminate) return;
    // 0052bbad  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052bbaf  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052bbb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052bbb4  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0052bbb9  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0052bbbc  e88fffffff             -call 0x52bb50
    cpu.esp -= 4;
    sub_52bb50(app, cpu);
    if (cpu.terminate) return;
    // 0052bbc1  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052bbc3  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0052bbc5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052bbc7  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0052bbcc  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0052bbce  e88d3bfcff             -call 0x4ef760
    cpu.esp -= 4;
    sub_4ef760(app, cpu);
    if (cpu.terminate) return;
    // 0052bbd3  e8d835fcff             -call 0x4ef1b0
    cpu.esp -= 4;
    sub_4ef1b0(app, cpu);
    if (cpu.terminate) return;
    // 0052bbd8  e8c350fbff             -call 0x4e0ca0
    cpu.esp -= 4;
    sub_4e0ca0(app, cpu);
    if (cpu.terminate) return;
    // 0052bbdd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052bbdf  e8dc4dfcff             -call 0x4f09c0
    cpu.esp -= 4;
    sub_4f09c0(app, cpu);
    if (cpu.terminate) return;
    // 0052bbe4  e8a7f1fbff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 0052bbe9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bbea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_52bbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bbf0  e80b010000             -call 0x52bd00
    cpu.esp -= 4;
    sub_52bd00(app, cpu);
    if (cpu.terminate) return;
    // 0052bbf5  e95651fbff             -jmp 0x4e0d50
    return sub_4e0d50(app, cpu);
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52bc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bc00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052bc01  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bc02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bc03  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bc04  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052bc05  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052bc0b  8b8c241c010000         -mov ecx, dword ptr [esp + 0x11c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 0052bc12  8bb42420010000         -mov esi, dword ptr [esp + 0x120]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0052bc19  8b1594725600           -mov edx, dword ptr [0x567294]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5665428) /* 0x567294 */);
    // 0052bc1f  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 0052bc22  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0052bc25  81fa80b55000           +cmp edx, 0x50b580
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5289344 /*0x50b580*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bc2b  7452                   -je 0x52bc7f
    if (cpu.flags.zf)
    {
        goto L_0x0052bc7f;
    }
L_0x0052bc2d:
    // 0052bc2d  8d842428010000         -lea eax, [esp + 0x128]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 0052bc34  8d9c2400010000         -lea ebx, [esp + 0x100]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0052bc3b  8b942424010000         -mov edx, dword ptr [esp + 0x124]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0052bc42  89842400010000         -mov dword ptr [esp + 0x100], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052bc49  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052bc4b  e8243afbff             -call 0x4df674
    cpu.esp -= 4;
    sub_4df674(app, cpu);
    if (cpu.terminate) return;
    // 0052bc50  e8cbf0fbff             -call 0x4ead20
    cpu.esp -= 4;
    sub_4ead20(app, cpu);
    if (cpu.terminate) return;
    // 0052bc55  e8c6270000             -call 0x52e420
    cpu.esp -= 4;
    sub_52e420(app, cpu);
    if (cpu.terminate) return;
    // 0052bc5a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052bc5c  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052bc5e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052bc60  e87b280000             -call 0x52e4e0
    cpu.esp -= 4;
    sub_52e4e0(app, cpu);
    if (cpu.terminate) return;
    // 0052bc65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bc67  89842400010000         -mov dword ptr [esp + 0x100], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 0052bc6e  e81df1fbff             -call 0x4ead90
    cpu.esp -= 4;
    sub_4ead90(app, cpu);
    if (cpu.terminate) return;
    // 0052bc73  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0052bc79  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bc7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bc7f:
    // 0052bc7f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052bc80  bb50205500             -mov ebx, 0x552050
    cpu.ebx = 5578832 /*0x552050*/;
    // 0052bc85  bf60205500             -mov edi, 0x552060
    cpu.edi = 5578848 /*0x552060*/;
    // 0052bc8a  bd72000000             -mov ebp, 0x72
    cpu.ebp = 114 /*0x72*/;
    // 0052bc8f  6874205500             -push 0x552074
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5578868 /*0x552074*/;
    cpu.esp -= 4;
    // 0052bc94  891d90215500           -mov dword ptr [0x552190], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5579152) /* 0x552190 */) = cpu.ebx;
    // 0052bc9a  893d94215500           -mov dword ptr [0x552194], edi
    *app->getMemory<x86::reg32>(x86::reg32(5579156) /* 0x552194 */) = cpu.edi;
    // 0052bca0  892d98215500           -mov dword ptr [0x552198], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5579160) /* 0x552198 */) = cpu.ebp;
    // 0052bca6  e86553edff             -call 0x401010
    cpu.esp -= 4;
    sub_401010(app, cpu);
    if (cpu.terminate) return;
    // 0052bcab  83c404                 +add esp, 4
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
    // 0052bcae  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bcaf  e979ffffff             -jmp 0x52bc2d
    goto L_0x0052bc2d;
}

/* align: skip  */
void Application::sub_52bd00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0052bd00  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bd03  7707                   -ja 0x52bd0c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052bd0c;
    }
    // 0052bd05  ff2485b4bc5200         -jmp dword ptr [eax*4 + 0x52bcb4]
    cpu.ip = *app->getMemory<x86::reg32>(5422260 + cpu.eax * 4); goto dynamic_jump;
  case 0x0052bd0c:
L_0x0052bd0c:
    // 0052bd0c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0052bd11  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0052bd12:
    // 0052bd12  b870000000             -mov eax, 0x70
    cpu.eax = 112 /*0x70*/;
    // 0052bd17  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52bd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bd20  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bd21  b8e0004f00             -mov eax, 0x4f00e0
    cpu.eax = 5177568 /*0x4f00e0*/;
    // 0052bd26  e8c543fcff             -call 0x4f00f0
    cpu.esp -= 4;
    sub_4f00f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bd2b:
    // 0052bd2b  e8f043fcff             -call 0x4f0120
    cpu.esp -= 4;
    sub_4f0120(app, cpu);
    if (cpu.terminate) return;
    // 0052bd30  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052bd32  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bd34  74f5                   -je 0x52bd2b
    if (cpu.flags.zf)
    {
        goto L_0x0052bd2b;
    }
    // 0052bd36  83f861                 +cmp eax, 0x61
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bd39  7c08                   -jl 0x52bd43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052bd43;
    }
    // 0052bd3b  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bd3e  7f03                   -jg 0x52bd43
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052bd43;
    }
    // 0052bd40  8d50e0                 -lea edx, [eax - 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-32) /* -0x20 */);
L_0x0052bd43:
    // 0052bd43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052bd45  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bd46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_52bd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bd50  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bd51  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052bd52  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052bd53  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052bd56  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052bd58  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052bd5b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052bd5d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052bd5f  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0052bd63  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052bd66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052bd68  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052bd6a  e881feffff             -call 0x52bbf0
    cpu.esp -= 4;
    sub_52bbf0(app, cpu);
    if (cpu.terminate) return;
    // 0052bd6f  39cd                   +cmp ebp, ecx
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
    // 0052bd71  7e31                   -jle 0x52bda4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052bda4;
    }
    // 0052bd73  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052bd77  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x0052bd7b:
    // 0052bd7b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052bd7d  7e20                   -jle 0x52bd9f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052bd9f;
    }
    // 0052bd7f  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052bd83  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052bd87  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052bd89  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0052bd8b:
    // 0052bd8b  68b4205500             -push 0x5520b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5578932 /*0x5520b4*/;
    cpu.esp -= 4;
    // 0052bd90  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bd91  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bd92  e8e94bfbff             -call 0x4e0980
    cpu.esp -= 4;
    sub_4e0980(app, cpu);
    if (cpu.terminate) return;
    // 0052bd97  42                     -inc edx
    (cpu.edx)++;
    // 0052bd98  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052bd9b  39da                   +cmp edx, ebx
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
    // 0052bd9d  7cec                   -jl 0x52bd8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052bd8b;
    }
L_0x0052bd9f:
    // 0052bd9f  41                     -inc ecx
    (cpu.ecx)++;
    // 0052bda0  39e9                   +cmp ecx, ebp
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
    // 0052bda2  7cd7                   -jl 0x52bd7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052bd7b;
    }
L_0x0052bda4:
    // 0052bda4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052bda7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bda8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bda9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bdaa  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52bdb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bdb0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052bdb1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bdb2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bdb3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bdb4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052bdb5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052bdb6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052bdb9  b8b8205500             -mov eax, 0x5520b8
    cpu.eax = 5578936 /*0x5520b8*/;
    // 0052bdbe  e80d2dfeff             -call 0x50ead0
    cpu.esp -= 4;
    sub_50ead0(app, cpu);
    if (cpu.terminate) return;
    // 0052bdc3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052bdc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bdc7  0f84f9000000           -je 0x52bec6
    if (cpu.flags.zf)
    {
        goto L_0x0052bec6;
    }
L_0x0052bdcd:
    // 0052bdcd  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052bdd0  0f84e6000000           -je 0x52bebc
    if (cpu.flags.zf)
    {
        goto L_0x0052bebc;
    }
    // 0052bdd6  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 0052bdd8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0052bdda:
    // 0052bdda  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0052bddc  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052bdde  7412                   -je 0x52bdf2
    if (cpu.flags.zf)
    {
        goto L_0x0052bdf2;
    }
    // 0052bde0  3c00                   +cmp al, 0
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
    // 0052bde2  740c                   -je 0x52bdf0
    if (cpu.flags.zf)
    {
        goto L_0x0052bdf0;
    }
    // 0052bde4  46                     -inc esi
    (cpu.esi)++;
    // 0052bde5  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0052bde7  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052bde9  7407                   -je 0x52bdf2
    if (cpu.flags.zf)
    {
        goto L_0x0052bdf2;
    }
    // 0052bdeb  46                     -inc esi
    (cpu.esi)++;
    // 0052bdec  3c00                   +cmp al, 0
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
    // 0052bdee  75ea                   -jne 0x52bdda
    if (!cpu.flags.zf)
    {
        goto L_0x0052bdda;
    }
L_0x0052bdf0:
    // 0052bdf0  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052bdf2:
    // 0052bdf2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052bdf4  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0052bdf6  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052bdf8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052bdfa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052bdfc  e82f50fbff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0052be01  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0052be06  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0052be08  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be0a  881434                 -mov byte ptr [esp + esi], dl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 0052be0d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052be0f  e84c280000             -call 0x52e660
    cpu.esp -= 4;
    sub_52e660(app, cpu);
    if (cpu.terminate) return;
    // 0052be14  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0052be17  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 0052be19  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052be1b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0052be1d:
    // 0052be1d  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0052be1f  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052be21  7412                   -je 0x52be35
    if (cpu.flags.zf)
    {
        goto L_0x0052be35;
    }
    // 0052be23  3c00                   +cmp al, 0
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
    // 0052be25  740c                   -je 0x52be33
    if (cpu.flags.zf)
    {
        goto L_0x0052be33;
    }
    // 0052be27  46                     -inc esi
    (cpu.esi)++;
    // 0052be28  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0052be2a  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052be2c  7407                   -je 0x52be35
    if (cpu.flags.zf)
    {
        goto L_0x0052be35;
    }
    // 0052be2e  46                     -inc esi
    (cpu.esi)++;
    // 0052be2f  3c00                   +cmp al, 0
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
    // 0052be31  75ea                   -jne 0x52be1d
    if (!cpu.flags.zf)
    {
        goto L_0x0052be1d;
    }
L_0x0052be33:
    // 0052be33  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052be35:
    // 0052be35  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be37  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0052be39  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052be3b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052be3d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052be3f  e8ec4ffbff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0052be44  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0052be49  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0052be4b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be4d  883434                 -mov byte ptr [esp + esi], dh
    *app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 0052be50  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052be52  e809280000             -call 0x52e660
    cpu.esp -= 4;
    sub_52e660(app, cpu);
    if (cpu.terminate) return;
    // 0052be57  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0052be5a  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 0052be5c  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052be60  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x0052be62:
    // 0052be62  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0052be64  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052be66  7412                   -je 0x52be7a
    if (cpu.flags.zf)
    {
        goto L_0x0052be7a;
    }
    // 0052be68  3c00                   +cmp al, 0
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
    // 0052be6a  740c                   -je 0x52be78
    if (cpu.flags.zf)
    {
        goto L_0x0052be78;
    }
    // 0052be6c  46                     -inc esi
    (cpu.esi)++;
    // 0052be6d  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0052be6f  3ac2                   +cmp al, dl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052be71  7407                   -je 0x52be7a
    if (cpu.flags.zf)
    {
        goto L_0x0052be7a;
    }
    // 0052be73  46                     -inc esi
    (cpu.esi)++;
    // 0052be74  3c00                   +cmp al, 0
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
    // 0052be76  75ea                   -jne 0x52be62
    if (!cpu.flags.zf)
    {
        goto L_0x0052be62;
    }
L_0x0052be78:
    // 0052be78  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052be7a:
    // 0052be7a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be7c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0052be7e  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052be80  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052be82  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052be84  e8a74ffbff             -call 0x4e0e30
    cpu.esp -= 4;
    sub_4e0e30(app, cpu);
    if (cpu.terminate) return;
    // 0052be89  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0052be8b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0052be8d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052be8f  881c34                 -mov byte ptr [esp + esi], bl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 0052be92  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 0052be97  e8c4270000             -call 0x52e660
    cpu.esp -= 4;
    sub_52e660(app, cpu);
    if (cpu.terminate) return;
    // 0052be9c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052be9e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052bea0  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052bea4  e8df24ffff             -call 0x51e388
    cpu.esp -= 4;
    sub_51e388(app, cpu);
    if (cpu.terminate) return;
    // 0052bea9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052beab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052bead  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 0052beb0  e8836fffff             -call 0x522e38
    cpu.esp -= 4;
    sub_522e38(app, cpu);
    if (cpu.terminate) return;
    // 0052beb5  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052beb7  e911ffffff             -jmp 0x52bdcd
    goto L_0x0052bdcd;
L_0x0052bebc:
    // 0052bebc  b8c4205500             -mov eax, 0x5520c4
    cpu.eax = 5578948 /*0x5520c4*/;
    // 0052bec1  e80a280000             -call 0x52e6d0
    cpu.esp -= 4;
    sub_52e6d0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bec6:
    // 0052bec6  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052bec9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052beca  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052becb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052becc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052becd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bece  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052becf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52bed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bed0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052bed1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bed2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bed3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bed4  8b1554b1a000           -mov edx, dword ptr [0xa0b154]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052beda  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052bedc  0f8480000000           -je 0x52bf62
    if (cpu.flags.zf)
    {
        goto L_0x0052bf62;
    }
    // 0052bee2  eb30                   -jmp 0x52bf14
    goto L_0x0052bf14;
L_0x0052bee4:
    // 0052bee4  833d50b1a00000         +cmp dword ptr [0xa0b150], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052beeb  7424                   -je 0x52bf11
    if (cpu.flags.zf)
    {
        goto L_0x0052bf11;
    }
    // 0052beed  8b3554b1a000           -mov esi, dword ptr [0xa0b154]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052bef3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052bef5  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052bef7  8b1d50b1a000           -mov ebx, dword ptr [0xa0b150]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052befd  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 0052bf00  803c1900               +cmp byte ptr [ecx + ebx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052bf04  7405                   -je 0x52bf0b
    if (cpu.flags.zf)
    {
        goto L_0x0052bf0b;
    }
    // 0052bf06  e8e5bafcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bf0b:
    // 0052bf0b  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x0052bf11:
    // 0052bf11  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052bf14:
    // 0052bf14  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0052bf16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bf18  75ca                   -jne 0x52bee4
    if (!cpu.flags.zf)
    {
        goto L_0x0052bee4;
    }
    // 0052bf1a  833d50b1a00000         +cmp dword ptr [0xa0b150], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052bf21  750c                   -jne 0x52bf2f
    if (!cpu.flags.zf)
    {
        goto L_0x0052bf2f;
    }
    // 0052bf23  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0052bf28  e8d3b9fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052bf2d  eb0f                   -jmp 0x52bf3e
    goto L_0x0052bf3e;
L_0x0052bf2f:
    // 0052bf2f  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0052bf34  a154b1a000             -mov eax, dword ptr [0xa0b154]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */);
    // 0052bf39  e882c6feff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
L_0x0052bf3e:
    // 0052bf3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052bf40  750a                   -jne 0x52bf4c
    if (!cpu.flags.zf)
    {
        goto L_0x0052bf4c;
    }
    // 0052bf42  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052bf47  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf48  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf49  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf4a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bf4c:
    // 0052bf4c  a354b1a000             -mov dword ptr [0xa0b154], eax
    *app->getMemory<x86::reg32>(x86::reg32(10531156) /* 0xa0b154 */) = cpu.eax;
    // 0052bf51  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0052bf57  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052bf5a  a350b1a000             -mov dword ptr [0xa0b150], eax
    *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052bf5f  c60000                 -mov byte ptr [eax], 0
    *app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x0052bf62:
    // 0052bf62  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bf64  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf65  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf66  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf67  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52bf70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bf70  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bf71  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bf72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052bf74  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052bf76  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052bf78  7505                   -jne 0x52bf7f
    if (!cpu.flags.zf)
    {
        goto L_0x0052bf7f;
    }
L_0x0052bf7a:
    // 0052bf7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bf7c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf7d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bf7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bf7f:
    // 0052bf7f  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ecx);
    // 0052bf82  668b16                 -mov dx, word ptr [esi]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esi);
    // 0052bf85  f6c4ff                 +test ah, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 255 /*0xff*/));
    // 0052bf88  7525                   -jne 0x52bfaf
    if (!cpu.flags.zf)
    {
        goto L_0x0052bfaf;
    }
    // 0052bf8a  f6c6ff                 +test dh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 255 /*0xff*/));
    // 0052bf8d  7520                   -jne 0x52bfaf
    if (!cpu.flags.zf)
    {
        goto L_0x0052bfaf;
    }
    // 0052bf8f  663d4100               +cmp ax, 0x41
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bf93  720b                   -jb 0x52bfa0
    if (cpu.flags.cf)
    {
        goto L_0x0052bfa0;
    }
    // 0052bf95  663d5a00               +cmp ax, 0x5a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bf99  7705                   -ja 0x52bfa0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052bfa0;
    }
    // 0052bf9b  0520000000             -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0052bfa0:
    // 0052bfa0  6683fa41               +cmp dx, 0x41
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(65 /*0x41*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bfa4  7209                   -jb 0x52bfaf
    if (cpu.flags.cf)
    {
        goto L_0x0052bfaf;
    }
    // 0052bfa6  6683fa5a               +cmp dx, 0x5a
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(90 /*0x5a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bfaa  7703                   -ja 0x52bfaf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0052bfaf;
    }
    // 0052bfac  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0052bfaf:
    // 0052bfaf  6639d0                 +cmp ax, dx
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.dx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052bfb2  740f                   -je 0x52bfc3
    if (cpu.flags.zf)
    {
        goto L_0x0052bfc3;
    }
    // 0052bfb4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052bfb6  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0052bfbb  6689d3                 -mov bx, dx
    cpu.bx = cpu.dx;
    // 0052bfbe  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052bfc0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bfc1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bfc2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bfc3:
    // 0052bfc3  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0052bfc6  7505                   -jne 0x52bfcd
    if (!cpu.flags.zf)
    {
        goto L_0x0052bfcd;
    }
    // 0052bfc8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052bfca  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bfcb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052bfcc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052bfcd:
    // 0052bfcd  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052bfd0  83c602                 +add esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052bfd3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0052bfd4  74a4                   -je 0x52bf7a
    if (cpu.flags.zf)
    {
        goto L_0x0052bf7a;
    }
    // 0052bfd6  eba7                   -jmp 0x52bf7f
    goto L_0x0052bf7f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52bfe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052bfe0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052bfe1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052bfe2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052bfe3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052bfe4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052bfe5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052bfe6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052bfe9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052bfeb  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052bff0  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052bff4  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0052bff7  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 0052bffc  e83f2b0000             -call 0x52eb40
    cpu.esp -= 4;
    sub_52eb40(app, cpu);
    if (cpu.terminate) return;
    // 0052c001  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c003  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c005  750a                   -jne 0x52c011
    if (!cpu.flags.zf)
    {
        goto L_0x0052c011;
    }
    // 0052c007  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c00c  e95a010000             -jmp 0x52c16b
    goto L_0x0052c16b;
L_0x0052c011:
    // 0052c011  39c8                   +cmp eax, ecx
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
    // 0052c013  750f                   -jne 0x52c024
    if (!cpu.flags.zf)
    {
        goto L_0x0052c024;
    }
    // 0052c015  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c01a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c01d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c01e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c01f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c020  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c021  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c022  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c023  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c024:
    // 0052c024  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052c026  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0052c028  8d2c4500000000         -lea ebp, [eax*2]
    cpu.ebp = x86::reg32(cpu.eax * 2);
    // 0052c02f  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0052c032  e8c9b8fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c037  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052c039  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052c03d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c03f  750f                   -jne 0x52c050
    if (!cpu.flags.zf)
    {
        goto L_0x0052c050;
    }
    // 0052c041  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c046  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c049  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c04f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c050:
    // 0052c050  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c052  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052c054  e8c792ffff             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
    // 0052c059  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0052c05c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c05e  66c7042e0000           -mov word ptr [esi + ebp], 0
    *app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 0052c064  e89792ffff             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 0052c069  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c06b  7442                   -je 0x52c0af
    if (cpu.flags.zf)
    {
        goto L_0x0052c0af;
    }
    // 0052c06d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c06f  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052c073  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c076  e885b8fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c07b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c07d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c07f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c081  7516                   -jne 0x52c099
    if (!cpu.flags.zf)
    {
        goto L_0x0052c099;
    }
    // 0052c083  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c085  e866b9fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c08a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c08f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c092  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c093  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c094  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c095  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c096  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c097  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c098  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c099:
    // 0052c099  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c09d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c0a1  01f7                   +add edi, esi
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
    // 0052c0a3  e87892ffff             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
    // 0052c0a8  66c7070000             -mov word ptr [edi], 0
    *app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 0052c0ad  eb02                   -jmp 0x52c0b1
    goto L_0x0052c0b1;
L_0x0052c0af:
    // 0052c0af  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0052c0b1:
    // 0052c0b1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c0b5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052c0b7  e8e490ffff             -call 0x5251a0
    cpu.esp -= 4;
    sub_5251a0(app, cpu);
    if (cpu.terminate) return;
    // 0052c0bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c0be  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c0c2  e829b9fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c0c7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c0c9  e822b9fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c0ce  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052c0d0  750f                   -jne 0x52c0e1
    if (!cpu.flags.zf)
    {
        goto L_0x0052c0e1;
    }
    // 0052c0d2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c0d7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c0da  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0db  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0dc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0dd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0de  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0df  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c0e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c0e1:
    // 0052c0e1  833d58b1a00000         +cmp dword ptr [0xa0b158], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c0e8  7505                   -jne 0x52c0ef
    if (!cpu.flags.zf)
    {
        goto L_0x0052c0ef;
    }
    // 0052c0ea  e8b191ffff             -call 0x5252a0
    cpu.esp -= 4;
    sub_5252a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052c0ef:
    // 0052c0ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c0f1  e882000000             -call 0x52c178
    cpu.esp -= 4;
    sub_52c178(app, cpu);
    if (cpu.terminate) return;
    // 0052c0f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c0f8  740f                   -je 0x52c109
    if (cpu.flags.zf)
    {
        goto L_0x0052c109;
    }
    // 0052c0fa  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c0ff  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c102  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c103  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c104  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c105  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c106  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c107  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c108  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c109:
    // 0052c109  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c10b  e8f091ffff             -call 0x525300
    cpu.esp -= 4;
    sub_525300(app, cpu);
    if (cpu.terminate) return;
    // 0052c110  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0052c113  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c117  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0052c11a  e8e1b7fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c11f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052c121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c123  7519                   -jne 0x52c13e
    if (!cpu.flags.zf)
    {
        goto L_0x0052c13e;
    }
    // 0052c125  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0052c12a  e85d4efdff             -call 0x500f8c
    cpu.esp -= 4;
    sub_500f8c(app, cpu);
    if (cpu.terminate) return;
    // 0052c12f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c134  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c137  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c138  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c139  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c13a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c13b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c13c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c13d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c13e:
    // 0052c13e  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 0052c142  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052c144  e8a781ffff             -call 0x5242f0
    cpu.esp -= 4;
    sub_5242f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c149  83f8ff                 +cmp eax, -1
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
    // 0052c14c  7516                   -jne 0x52c164
    if (!cpu.flags.zf)
    {
        goto L_0x0052c164;
    }
    // 0052c14e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c150  e89bb8fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
    // 0052c155  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c15a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c15d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c15e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c15f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c160  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c161  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c162  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c163  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c164:
    // 0052c164  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c166  e821270000             -call 0x52e88c
    cpu.esp -= 4;
    sub_52e88c(app, cpu);
    if (cpu.terminate) return;
L_0x0052c16b:
    // 0052c16b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0052c16e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c16f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c170  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c171  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c172  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c173  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c174  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52c178(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c178  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052c179  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c17a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052c17b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c17c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c17d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c17e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c181  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c183  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c185  750a                   -jne 0x52c191
    if (!cpu.flags.zf)
    {
        goto L_0x0052c191;
    }
    // 0052c187  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c18c  e963010000             -jmp 0x52c2f4
    goto L_0x0052c2f4;
L_0x0052c191:
    // 0052c191  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c195  741b                   -je 0x52c1b2
    if (cpu.flags.zf)
    {
        goto L_0x0052c1b2;
    }
    // 0052c197  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0052c19a  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c19e  7412                   -je 0x52c1b2
    if (cpu.flags.zf)
    {
        goto L_0x0052c1b2;
    }
L_0x0052c1a0:
    // 0052c1a0  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c1a4  740c                   -je 0x52c1b2
    if (cpu.flags.zf)
    {
        goto L_0x0052c1b2;
    }
    // 0052c1a6  668b7202               -mov si, word ptr [edx + 2]
    cpu.si = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0052c1aa  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c1ad  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 0052c1b0  75ee                   -jne 0x52c1a0
    if (!cpu.flags.zf)
    {
        goto L_0x0052c1a0;
    }
L_0x0052c1b2:
    // 0052c1b2  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c1b6  750f                   -jne 0x52c1c7
    if (!cpu.flags.zf)
    {
        goto L_0x0052c1c7;
    }
    // 0052c1b8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c1bd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c1c0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c1c7:
    // 0052c1c7  66837a0200             +cmp word ptr [edx + 2], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c1cc  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 0052c1cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052c1d1  8b0d58b1a000           -mov ecx, dword ptr [0xa0b158]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c1d7  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 0052c1d9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0052c1db  7541                   -jne 0x52c21e
    if (!cpu.flags.zf)
    {
        goto L_0x0052c21e;
    }
    // 0052c1dd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052c1df  0f850d010000           -jne 0x52c2f2
    if (!cpu.flags.zf)
    {
        goto L_0x0052c2f2;
    }
    // 0052c1e5  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0052c1ea  e811b7fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c1ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052c1f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c1f3  750f                   -jne 0x52c204
    if (!cpu.flags.zf)
    {
        goto L_0x0052c204;
    }
    // 0052c1f5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c1fa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c1fd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1fe  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c1ff  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c200  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c201  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c202  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c203  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c204:
    // 0052c204  a358b1a000             -mov dword ptr [0xa0b158], eax
    *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */) = cpu.eax;
    // 0052c209  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c20c  8958f8                 -mov dword ptr [eax - 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 0052c20f  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0052c211  8958fc                 -mov dword ptr [eax - 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0052c214  a350b1a000             -mov dword ptr [0xa0b150], eax
    *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052c219  e9c8000000             -jmp 0x52c2e6
    goto L_0x0052c2e6;
L_0x0052c21e:
    // 0052c21e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052c220  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052c222  e8d9000000             -call 0x52c300
    cpu.esp -= 4;
    sub_52c300(app, cpu);
    if (cpu.terminate) return;
    // 0052c227  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052c229  0f85c3000000           -jne 0x52c2f2
    if (!cpu.flags.zf)
    {
        goto L_0x0052c2f2;
    }
    // 0052c22f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c231  0f8fac000000           -jg 0x52c2e3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052c2e3;
    }
    // 0052c237  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0052c239  8b2d50b1a000           -mov ebp, dword ptr [0xa0b150]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c23f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052c241  40                     -inc eax
    (cpu.eax)++;
    // 0052c242  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 0052c249  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052c24c  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052c24f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c252  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052c256  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052c258  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052c25a  753e                   -jne 0x52c29a
    if (!cpu.flags.zf)
    {
        goto L_0x0052c29a;
    }
    // 0052c25c  e89fb6fcff             -call 0x4f7900
    cpu.esp -= 4;
    sub_4f7900(app, cpu);
    if (cpu.terminate) return;
    // 0052c261  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c263  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052c265  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c267  750f                   -jne 0x52c278
    if (!cpu.flags.zf)
    {
        goto L_0x0052c278;
    }
    // 0052c269  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c26e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c271  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c272  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c273  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c274  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c275  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c276  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c277  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c278:
    // 0052c278  8b1558b1a000           -mov edx, dword ptr [0xa0b158]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c27e  e89d90ffff             -call 0x525320
    cpu.esp -= 4;
    sub_525320(app, cpu);
    if (cpu.terminate) return;
    // 0052c283  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c287  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c28a  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0052c28c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052c28e  a350b1a000             -mov dword ptr [0xa0b150], eax
    *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.eax;
    // 0052c293  e8a843fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052c298  eb39                   -jmp 0x52c2d3
    goto L_0x0052c2d3;
L_0x0052c29a:
    // 0052c29a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c29c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c29e  e81dc3feff             -call 0x5185c0
    cpu.esp -= 4;
    sub_5185c0(app, cpu);
    if (cpu.terminate) return;
    // 0052c2a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052c2a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c2a7  750f                   -jne 0x52c2b8
    if (!cpu.flags.zf)
    {
        goto L_0x0052c2b8;
    }
    // 0052c2a9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c2ae  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c2b1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c2b8:
    // 0052c2b8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c2bc  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c2c2  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052c2c4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c2c6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c2c8  e873c3feff             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 0052c2cd  892d50b1a000           -mov dword ptr [0xa0b150], ebp
    *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ebp;
L_0x0052c2d3:
    // 0052c2d3  890d58b1a000           -mov dword ptr [0xa0b158], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */) = cpu.ecx;
    // 0052c2d9  c744b10400000000       -mov dword ptr [ecx + esi*4 + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4) = 0 /*0x0*/;
    // 0052c2e1  eb03                   -jmp 0x52c2e6
    goto L_0x0052c2e6;
L_0x0052c2e3:
    // 0052c2e3  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0052c2e6:
    // 0052c2e6  a150b1a000             -mov eax, dword ptr [0xa0b150]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c2eb  893cb1                 -mov dword ptr [ecx + esi*4], edi
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4) = cpu.edi;
    // 0052c2ee  c6040600               -mov byte ptr [esi + eax], 0
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x0052c2f2:
    // 0052c2f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0052c2f4:
    // 0052c2f4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c2f7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2f8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2f9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2fa  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2fb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2fc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c2fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52c300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c300  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052c301  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c302  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c303  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c304  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c305  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c307  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052c309  8b3558b1a000           -mov esi, dword ptr [0xa0b158]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c30f  e9d7000000             -jmp 0x52c3eb
    goto L_0x0052c3eb;
L_0x0052c314:
    // 0052c314  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edi);
    // 0052c317  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052c319  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0052c31c  0f84c6000000           -je 0x52c3e8
    if (cpu.flags.zf)
    {
        goto L_0x0052c3e8;
    }
L_0x0052c322:
    // 0052c322  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c324  668b02                 -mov ax, word ptr [edx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx);
    // 0052c327  e84490ffff             -call 0x525370
    cpu.esp -= 4;
    sub_525370(app, cpu);
    if (cpu.terminate) return;
    // 0052c32c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052c32e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c330  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx);
    // 0052c333  e83890ffff             -call 0x525370
    cpu.esp -= 4;
    sub_525370(app, cpu);
    if (cpu.terminate) return;
    // 0052c338  6639c1                 +cmp cx, ax
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c33b  0f85a7000000           -jne 0x52c3e8
    if (!cpu.flags.zf)
    {
        goto L_0x0052c3e8;
    }
    // 0052c341  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052c345  0f858a000000           -jne 0x52c3d5
    if (!cpu.flags.zf)
    {
        goto L_0x0052c3d5;
    }
    // 0052c34b  8b1558b1a000           -mov edx, dword ptr [0xa0b158]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c351  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0052c353  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c355  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 0052c358  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052c35a  0f846c000000           -je 0x52c3cc
    if (cpu.flags.zf)
    {
        goto L_0x0052c3cc;
    }
    // 0052c360  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052c362  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052c364  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052c366  740f                   -je 0x52c377
    if (cpu.flags.zf)
    {
        goto L_0x0052c377;
    }
L_0x0052c368:
    // 0052c368  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0052c36b  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0052c36d  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0052c370  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c373  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052c375  75f1                   -jne 0x52c368
    if (!cpu.flags.zf)
    {
        goto L_0x0052c368;
    }
L_0x0052c377:
    // 0052c377  8b3550b1a000           -mov esi, dword ptr [0xa0b150]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c37d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0052c37f  7443                   -je 0x52c3c4
    if (cpu.flags.zf)
    {
        goto L_0x0052c3c4;
    }
    // 0052c381  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c383  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052c387  7407                   -je 0x52c390
    if (cpu.flags.zf)
    {
        goto L_0x0052c390;
    }
    // 0052c389  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c38b  e860b6fcff             -call 0x4f79f0
    cpu.esp -= 4;
    sub_4f79f0(app, cpu);
    if (cpu.terminate) return;
L_0x0052c390:
    // 0052c390  8b2d58b1a000           -mov ebp, dword ptr [0xa0b158]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c396  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0052c398  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0052c39a  8b1550b1a000           -mov edx, dword ptr [0xa0b150]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */);
    // 0052c3a0  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 0052c3a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c3a5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c3a7  e894c2feff             -call 0x518640
    cpu.esp -= 4;
    sub_518640(app, cpu);
    if (cpu.terminate) return;
    // 0052c3ac  890d50b1a000           -mov dword ptr [0xa0b150], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10531152) /* 0xa0b150 */) = cpu.ecx;
    // 0052c3b2  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c3b4  7d0e                   -jge 0x52c3c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c3c4;
    }
    // 0052c3b6  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x0052c3b9:
    // 0052c3b9  40                     -inc eax
    (cpu.eax)++;
    // 0052c3ba  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0052c3bc  47                     -inc edi
    (cpu.edi)++;
    // 0052c3bd  8850ff                 -mov byte ptr [eax - 1], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 0052c3c0  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c3c2  7cf5                   -jl 0x52c3b9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052c3b9;
    }
L_0x0052c3c4:
    // 0052c3c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c3c6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3c7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3c8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3c9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3ca  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c3cc:
    // 0052c3cc  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0052c3cf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c3d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c3d5:
    // 0052c3d5  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c3d8  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0052c3dc  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c3df  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0052c3e2  0f853affffff           -jne 0x52c322
    if (!cpu.flags.zf)
    {
        goto L_0x0052c322;
    }
L_0x0052c3e8:
    // 0052c3e8  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0052c3eb:
    // 0052c3eb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052c3ed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052c3ef  0f851fffffff           -jne 0x52c314
    if (!cpu.flags.zf)
    {
        goto L_0x0052c314;
    }
    // 0052c3f5  a158b1a000             -mov eax, dword ptr [0xa0b158]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10531160) /* 0xa0b158 */);
    // 0052c3fa  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052c3fc  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0052c3ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c400  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c401  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c402  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c403  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c404  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52c410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c410  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0052c413  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052c416  83e002                 -and eax, 2
    cpu.eax &= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0052c419  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52c420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c420  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0052c423  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052c426  83e004                 -and eax, 4
    cpu.eax &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c429  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_52c430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c430  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c431  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c432  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c433  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052c436  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052c438  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c43a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0052c43d  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c443  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c445  89542418               -mov dword ptr [esp + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0052c449  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c44b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c450  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052c454  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052c456  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0052c459  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0052c45c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c462  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c467  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052c46b  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052c46f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052c471  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0052c473  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0052c476  c1ea18                 -shr edx, 0x18
    cpu.edx >>= 24 /*0x18*/ % 32;
    // 0052c479  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c47e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c484  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052c488  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c48a  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052c48d  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 0052c490  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c496  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0052c49c  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052c4a0  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0052c4a3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052c4a5  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052c4a8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c4aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c4ac  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052c4af  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052c4b1  3dff000000             +cmp eax, 0xff
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
    // 0052c4b6  0f8e93000000           -jle 0x52c54f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c54f;
    }
    // 0052c4bc  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0052c4c1:
    // 0052c4c1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0052c4c5  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052c4c8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c4ca  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052c4ce  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052c4d1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c4d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c4d5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052c4d8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052c4da  3dff000000             +cmp eax, 0xff
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
    // 0052c4df  0f8e79000000           -jle 0x52c55e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c55e;
    }
    // 0052c4e5  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0052c4ea:
    // 0052c4ea  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0052c4ee  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0052c4f1  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052c4f4  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c4f8  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052c4fb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c4fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c4ff  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052c502  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052c504  3dff000000             +cmp eax, 0xff
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
    // 0052c509  7e5b                   -jle 0x52c566
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c566;
    }
    // 0052c50b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x0052c510:
    // 0052c510  0faf4c2404             -imul ecx, dword ptr [esp + 4]
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 0052c515  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c519  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0052c51c  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052c51e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c520  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c522  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0052c525  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0052c527  3dff000000             +cmp eax, 0xff
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
    // 0052c52c  7f40                   -jg 0x52c56e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052c56e;
    }
    // 0052c52e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c530  7c43                   -jl 0x52c575
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052c575;
    }
L_0x0052c532:
    // 0052c532  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c535  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052c537  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0052c53a  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 0052c53d  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c53f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052c541  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0052c544  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052c546  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c548  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0052c54b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c54c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c54d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c54e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c54f:
    // 0052c54f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c551  0f8d6affffff           -jge 0x52c4c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c4c1;
    }
    // 0052c557  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052c559  e963ffffff             -jmp 0x52c4c1
    goto L_0x0052c4c1;
L_0x0052c55e:
    // 0052c55e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c560  7d88                   -jge 0x52c4ea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c4ea;
    }
    // 0052c562  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052c564  eb84                   -jmp 0x52c4ea
    goto L_0x0052c4ea;
L_0x0052c566:
    // 0052c566  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c568  7da6                   -jge 0x52c510
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c510;
    }
    // 0052c56a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052c56c  eba2                   -jmp 0x52c510
    goto L_0x0052c510;
L_0x0052c56e:
    // 0052c56e  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 0052c573  ebbd                   -jmp 0x52c532
    goto L_0x0052c532;
L_0x0052c575:
    // 0052c575  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0052c577  ebb9                   -jmp 0x52c532
    goto L_0x0052c532;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_52c580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c580  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c581  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c582  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c583  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c584  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c587  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052c58b  f7c3000000ff           +test ebx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 4278190080 /*0xff000000*/));
    // 0052c591  7431                   -je 0x52c5c4
    if (cpu.flags.zf)
    {
        goto L_0x0052c5c4;
    }
L_0x0052c593:
    // 0052c593  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
    // 0052c598  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c59a  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052c59d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0052c59f:
    // 0052c59f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c5a2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c5a6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0052c5a8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0052c5aa  e881feffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c5af  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c5b2  4f                     -dec edi
    (cpu.edi)--;
    // 0052c5b3  46                     -inc esi
    (cpu.esi)++;
    // 0052c5b4  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0052c5b7  83fe10                 +cmp esi, 0x10
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
    // 0052c5ba  7ce3                   -jl 0x52c59f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052c59f;
    }
    // 0052c5bc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c5bf  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c5c0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c5c1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c5c2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c5c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c5c4:
    // 0052c5c4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052c5c6  81e3ffffff00           +and ebx, 0xffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/))));
    // 0052c5cc  ebc5                   -jmp 0x52c593
    goto L_0x0052c593;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52c5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c5d0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c5d1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c5d2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c5d3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0052c5d6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0052c5d8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0052c5da  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052c5dc  f7c3000000ff           +test ebx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 4278190080 /*0xff000000*/));
    // 0052c5e2  0f8524010000           -jne 0x52c70c
    if (!cpu.flags.zf)
    {
        goto L_0x0052c70c;
    }
    // 0052c5e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c5ea  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052c5ee  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x0052c5f1:
    // 0052c5f1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c5f5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052c5fa  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c5fd  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0052c602  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0052c604  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c606  896f04                 -mov dword ptr [edi + 4], ebp
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0052c609  e822feffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c60e  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0052c613  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c616  894708                 -mov dword ptr [edi + 8], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052c619  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0052c61b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c61d  e80efeffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c622  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0052c627  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c62a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052c62f  89470c                 -mov dword ptr [edi + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052c632  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052c634  e8f7fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c639  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052c63e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052c643  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c645  894710                 -mov dword ptr [edi + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0052c648  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c64c  e8dffdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c651  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0052c656  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0052c65b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c65d  894714                 -mov dword ptr [edi + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0052c660  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c664  e8c7fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c669  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0052c66e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052c673  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c675  894718                 -mov dword ptr [edi + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0052c678  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c67c  e8affdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c681  89471c                 -mov dword ptr [edi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0052c684  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0052c689  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052c68e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c692  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0052c694  e897fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c699  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0052c69e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0052c6a3  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c6a5  894720                 -mov dword ptr [edi + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0052c6a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c6aa  897724                 -mov dword ptr [edi + 0x24], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0052c6ad  e87efdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c6b2  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0052c6b7  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0052c6bc  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c6be  894728                 -mov dword ptr [edi + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0052c6c1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c6c3  e868fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c6c8  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0052c6cd  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0052c6d2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c6d4  89472c                 -mov dword ptr [edi + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0052c6d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c6d9  e852fdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c6de  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0052c6e3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0052c6e8  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0052c6ea  894730                 -mov dword ptr [edi + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0052c6ed  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c6ef  e83cfdffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c6f4  c7473800000000         -mov dword ptr [edi + 0x38], 0
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 0052c6fb  c7473c00000000         -mov dword ptr [edi + 0x3c], 0
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 0052c702  894734                 -mov dword ptr [edi + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0052c705  83c408                 +add esp, 8
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
    // 0052c708  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c709  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c70a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c70b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c70c:
    // 0052c70c  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052c710  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052c713  e9d9feffff             -jmp 0x52c5f1
    goto L_0x0052c5f1;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_52c720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c720  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c721  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c722  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c723  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052c726  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052c729  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052c72d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0052c72f  f7c3000000ff           +test ebx, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & 4278190080 /*0xff000000*/));
    // 0052c735  746e                   -je 0x52c7a5
    if (cpu.flags.zf)
    {
        goto L_0x0052c7a5;
    }
L_0x0052c737:
    // 0052c737  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c73a  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 0052c73f  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052c743  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052c745  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0052c749:
    // 0052c749  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c74d  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052c74f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052c751  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052c753  e8d8fcffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c758  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c75c  4d                     -dec ebp
    (cpu.ebp)--;
    // 0052c75d  46                     -inc esi
    (cpu.esi)++;
    // 0052c75e  8d5304                 -lea edx, [ebx + 4]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052c761  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0052c763  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052c767  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c76a  7edd                   -jle 0x52c749
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c749;
    }
    // 0052c76c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052c76f  bd07000000             -mov ebp, 7
    cpu.ebp = 7 /*0x7*/;
    // 0052c774  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0052c776  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x0052c77a:
    // 0052c77a  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c77e  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052c780  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0052c782  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0052c784  e8a7fcffff             -call 0x52c430
    cpu.esp -= 4;
    sub_52c430(app, cpu);
    if (cpu.terminate) return;
    // 0052c789  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052c78d  4d                     -dec ebp
    (cpu.ebp)--;
    // 0052c78e  46                     -inc esi
    (cpu.esi)++;
    // 0052c78f  8d4b04                 -lea ecx, [ebx + 4]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052c792  894320                 -mov dword ptr [ebx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0052c795  894c2410               -mov dword ptr [esp + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0052c799  83fe07                 +cmp esi, 7
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c79c  7edc                   -jle 0x52c77a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052c77a;
    }
    // 0052c79e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0052c7a1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7a2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7a3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c7a5:
    // 0052c7a5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0052c7a7  81e3ffffff00           +and ebx, 0xffffff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(16777215 /*0xffffff*/))));
    // 0052c7ad  eb88                   -jmp 0x52c737
    goto L_0x0052c737;
}

/* align: skip 0x90 */
void Application::sub_52c7b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c7b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052c7b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c7b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052c7b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c7b4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c7b6  e855fcffff             -call 0x52c410
    cpu.esp -= 4;
    sub_52c410(app, cpu);
    if (cpu.terminate) return;
    // 0052c7bb  8d727c                 -lea esi, [edx + 0x7c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(124) /* 0x7c */);
    // 0052c7be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c7c0  7520                   -jne 0x52c7e2
    if (!cpu.flags.zf)
    {
        goto L_0x0052c7e2;
    }
    // 0052c7c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052c7c4  e857fcffff             -call 0x52c420
    cpu.esp -= 4;
    sub_52c420(app, cpu);
    if (cpu.terminate) return;
    // 0052c7c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c7cb  742a                   -je 0x52c7f7
    if (cpu.flags.zf)
    {
        goto L_0x0052c7f7;
    }
    // 0052c7cd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c7cf  8b4a78                 -mov ecx, dword ptr [edx + 0x78]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 0052c7d2  8b5a70                 -mov ebx, dword ptr [edx + 0x70]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0052c7d5  8b526c                 -mov edx, dword ptr [edx + 0x6c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0052c7d8  e843ffffff             -call 0x52c720
    cpu.esp -= 4;
    sub_52c720(app, cpu);
    if (cpu.terminate) return;
    // 0052c7dd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7de  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7df  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7e0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c7e2:
    // 0052c7e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c7e4  8b4a74                 -mov ecx, dword ptr [edx + 0x74]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 0052c7e7  8b5a70                 -mov ebx, dword ptr [edx + 0x70]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0052c7ea  8b526c                 -mov edx, dword ptr [edx + 0x6c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0052c7ed  e8defdffff             -call 0x52c5d0
    cpu.esp -= 4;
    sub_52c5d0(app, cpu);
    if (cpu.terminate) return;
    // 0052c7f2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7f3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7f4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7f5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c7f6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c7f7:
    // 0052c7f7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052c7f9  8b5a70                 -mov ebx, dword ptr [edx + 0x70]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0052c7fc  8b526c                 -mov edx, dword ptr [edx + 0x6c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 0052c7ff  e87cfdffff             -call 0x52c580
    cpu.esp -= 4;
    sub_52c580(app, cpu);
    if (cpu.terminate) return;
    // 0052c804  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c805  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c806  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c807  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c808  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52c810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c810  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c812  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c814(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c814  ff15c0b15600           -call dword ptr [0x56b1c0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5681600) /* 0x56b1c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c81a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c81c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c81c  ff15c4b15600           -call dword ptr [0x56b1c4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5681604) /* 0x56b1c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c822  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c824  ff15c8b15600           -call dword ptr [0x56b1c8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5681608) /* 0x56b1c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c82a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c82c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c82c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c82d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c82e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052c830  7410                   -je 0x52c842
    if (cpu.flags.zf)
    {
        goto L_0x0052c842;
    }
    // 0052c832  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052c834  8b35c0b15600           -mov esi, dword ptr [0x56b1c0]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5681600) /* 0x56b1c0 */);
    // 0052c83a  890dc0b15600           -mov dword ptr [0x56b1c0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5681600) /* 0x56b1c0 */) = cpu.ecx;
    // 0052c840  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x0052c842:
    // 0052c842  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052c844  740f                   -je 0x52c855
    if (cpu.flags.zf)
    {
        goto L_0x0052c855;
    }
    // 0052c846  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0052c848  8b0dc4b15600           -mov ecx, dword ptr [0x56b1c4]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5681604) /* 0x56b1c4 */);
    // 0052c84e  a3c4b15600             -mov dword ptr [0x56b1c4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5681604) /* 0x56b1c4 */) = cpu.eax;
    // 0052c853  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x0052c855:
    // 0052c855  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0052c857  740f                   -je 0x52c868
    if (cpu.flags.zf)
    {
        goto L_0x0052c868;
    }
    // 0052c859  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0052c85b  8b15c8b15600           -mov edx, dword ptr [0x56b1c8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5681608) /* 0x56b1c8 */);
    // 0052c861  a3c8b15600             -mov dword ptr [0x56b1c8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5681608) /* 0x56b1c8 */) = cpu.eax;
    // 0052c866  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x0052c868:
    // 0052c868  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c869  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c86a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52c870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c870  ff15ccb15600           -call dword ptr [0x56b1cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5681612) /* 0x56b1cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c876  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0052c878  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052c879  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0052c87e  b8d4205500             -mov eax, 0x5520d4
    cpu.eax = 5578964 /*0x5520d4*/;
    // 0052c883  e88454feff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 0052c888  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c889  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c878(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052c878;
    // 0052c870  ff15ccb15600           -call dword ptr [0x56b1cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5681612) /* 0x56b1cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052c876  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x0052c878:
    // 0052c878  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052c879  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0052c87e  b8d4205500             -mov eax, 0x5520d4
    cpu.eax = 5578964 /*0x5520d4*/;
    // 0052c883  e88454feff             -call 0x511d0c
    cpu.esp -= 4;
    sub_511d0c(app, cpu);
    if (cpu.terminate) return;
    // 0052c888  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c889  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c88a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c88a  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c88c  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c88e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c88f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c88f  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c894  e887240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c899  eb1d                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
    // 0052c89b  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c8a0  e87b240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8a5  eb11                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
    // 0052c8a7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052c8a8  e8f75ffdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 0052c8ad  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 0052c8b2  e869240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8b7  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052c8b8:
    // 0052c8b8  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0052c8bd  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0052c8c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c8c4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c8c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c8a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052c8a7;
    // 0052c88f  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c894  e887240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c899  eb1d                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
    // 0052c89b  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c8a0  e87b240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8a5  eb11                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
L_entry_0x0052c8a7:
    // 0052c8a7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052c8a8  e8f75ffdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 0052c8ad  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 0052c8b2  e869240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8b7  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052c8b8:
    // 0052c8b8  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0052c8bd  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0052c8c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c8c4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c8c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c89b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0052c89b;
    // 0052c88f  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c894  e887240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c899  eb1d                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
L_entry_0x0052c89b:
    // 0052c89b  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c8a0  e87b240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8a5  eb11                   -jmp 0x52c8b8
    goto L_0x0052c8b8;
    // 0052c8a7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052c8a8  e8f75ffdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 0052c8ad  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 0052c8b2  e869240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8b7  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052c8b8:
    // 0052c8b8  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0052c8bd  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 0052c8c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c8c4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c8c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c8c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c8c7  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 0052c8cc  e84f240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8d1  eb11                   -jmp 0x52c8e4
    goto L_0x0052c8e4;
    // 0052c8d3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052c8d4  e8cb5ffdff             -call 0x5028a4
    cpu.esp -= 4;
    sub_5028a4(app, cpu);
    if (cpu.terminate) return;
    // 0052c8d9  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 0052c8de  e83d240000             -call 0x52ed20
    cpu.esp -= 4;
    sub_52ed20(app, cpu);
    if (cpu.terminate) return;
    // 0052c8e3  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052c8e4:
    // 0052c8e4  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 0052c8e9  0d0000807f             -or eax, 0x7f800000
    cpu.eax |= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 0052c8ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_52c8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c8f0  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052c8f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52c8f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c8f4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c8f5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c8f8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052c8fa  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052c8fd  3b4508                 +cmp eax, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c900  7366                   -jae 0x52c968
    if (!cpu.flags.cf)
    {
        goto L_0x0052c968;
    }
    // 0052c902  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c903  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c904  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c905  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0052c908  8d0c10                 -lea ecx, [eax + edx]
    cpu.ecx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0052c90b  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052c90e  894d04                 -mov dword ptr [ebp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052c911  39f9                   +cmp ecx, edi
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
    // 0052c913  725d                   -jb 0x52c972
    if (cpu.flags.cf)
    {
        goto L_0x0052c972;
    }
    // 0052c915  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0052c917  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c919  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052c91d  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c921  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052c924  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0052c926  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052c928  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0052c92b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052c92d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052c92f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0052c931  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052c933  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c934  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c936  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052c939  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 0052c93b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052c93d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052c940  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 0052c942  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c943  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052c947  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052c94a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0052c94c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052c94e  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052c950  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052c952  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052c954  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052c956  e8e53cfbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052c95b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052c960  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c961  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c962  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c963  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c966  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c967  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c968:
    // 0052c968  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052c96d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c970  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c971  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052c972:
    // 0052c972  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052c974  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052c977  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0052c97a  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052c97c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052c97e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0052c980  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052c982  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c983  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052c985  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052c988  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 0052c98a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052c98c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052c98f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 0052c991  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c992  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052c997  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c998  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c999  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c99a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c99d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052c99e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_52c9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c9a0  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052c9a7  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052c9a9  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0052c9ab  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052c9ae  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052c9b1  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052c9b5  c700f4c85200           -mov dword ptr [eax], 0x52c8f4
    *app->getMemory<x86::reg32>(cpu.eax) = 5425396 /*0x52c8f4*/;
    // 0052c9bb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052c9bf  c700f0c85200           -mov dword ptr [eax], 0x52c8f0
    *app->getMemory<x86::reg32>(cpu.eax) = 5425392 /*0x52c8f0*/;
    // 0052c9c5  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0052c9ca  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_52c9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052c9d0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052c9d1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052c9d2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052c9d3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052c9d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052c9d7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0052c9d9  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0052c9dc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052c9de  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052c9e0  7e59                   -jle 0x52ca3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ca3b;
    }
L_0x0052c9e2:
    // 0052c9e2  8b5a0c                 -mov ebx, dword ptr [edx + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0052c9e5  2b5a04                 -sub ebx, dword ptr [edx + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0052c9e8  43                     -inc ebx
    (cpu.ebx)++;
    // 0052c9e9  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052c9eb  7d02                   -jge 0x52c9ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052c9ef;
    }
    // 0052c9ed  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
L_0x0052c9ef:
    // 0052c9ef  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0052c9f1  8a4a10                 -mov cl, byte ptr [edx + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0052c9f4  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0052c9f7  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 0052c9f9  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 0052c9fb  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052c9fd  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0052c9ff  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ca01  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052ca04  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052ca06  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ca07  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052ca09  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052ca0c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 0052ca0e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052ca10  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052ca13  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 0052ca15  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca16  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052ca18  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0052ca1b  8a4a10                 -mov cl, byte ptr [edx + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0052ca1e  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052ca20  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052ca22  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0052ca25  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ca27  897204                 -mov dword ptr [edx + 4], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0052ca2a  893c24                 -mov dword ptr [esp], edi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0052ca2d  39ce                   +cmp esi, ecx
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
    // 0052ca2f  7606                   -jbe 0x52ca37
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052ca37;
    }
    // 0052ca31  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0052ca34  894204                 -mov dword ptr [edx + 4], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052ca37:
    // 0052ca37  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0052ca39  7fa7                   -jg 0x52c9e2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052c9e2;
    }
L_0x0052ca3b:
    // 0052ca3b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ca40  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ca43  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca44  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca45  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca46  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ca47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52ca48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ca48  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052ca4f  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052ca51  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052ca54  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052ca58  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052ca5b  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0052ca5d  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052ca60  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ca64  c700d0c95200           -mov dword ptr [eax], 0x52c9d0
    *app->getMemory<x86::reg32>(cpu.eax) = 5425616 /*0x52c9d0*/;
    // 0052ca6a  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0052ca6f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ca80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ca80  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ca81  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ca82  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ca83  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ca84  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ca87  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052ca8b  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052ca8f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052ca91  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052ca93  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ca95  7471                   -je 0x52cb08
    if (cpu.flags.zf)
    {
        goto L_0x0052cb08;
    }
    // 0052ca97  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ca9a  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0052ca9d:
    // 0052ca9d  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052caa2  0f8ebd000000           -jle 0x52cb65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052cb65;
    }
    // 0052caa8  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052caab  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052caae  7d65                   -jge 0x52cb15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052cb15;
    }
L_0x0052cab0:
    // 0052cab0  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0052cab3  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cab6  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052caba  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0052cabc  39c2                   +cmp edx, eax
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
    // 0052cabe  0f8f9a000000           -jg 0x52cb5e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052cb5e;
    }
L_0x0052cac4:
    // 0052cac4  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cac8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052caca  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052cacd  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cad0  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0052cad3  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cad5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cad7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052cad9  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052cadb  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cadc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052cade  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052cae1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 0052cae3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052cae5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052cae8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 0052caea  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052caeb  015508                 -add dword ptr [ebp + 8], edx
    (*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052caee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052caf0  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052caf3  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052caf7  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052caf9  29d6                   +sub esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052cafb  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0052cafe  89742408               -mov dword ptr [esp + 8], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0052cb02  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052cb06  eb95                   -jmp 0x52ca9d
    goto L_0x0052ca9d;
L_0x0052cb08:
    // 0052cb08  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052cb0d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cb10  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb11  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb12  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb13  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb14  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cb15:
    // 0052cb15  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052cb18  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cb1a  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052cb20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052cb22  750b                   -jne 0x52cb2f
    if (!cpu.flags.zf)
    {
        goto L_0x0052cb2f;
    }
    // 0052cb24  837d0000               +cmp dword ptr [ebp], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cb28  7405                   -je 0x52cb2f
    if (cpu.flags.zf)
    {
        goto L_0x0052cb2f;
    }
    // 0052cb2a  894508                 -mov dword ptr [ebp + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052cb2d  eb81                   -jmp 0x52cab0
    goto L_0x0052cab0;
L_0x0052cb2f:
    // 0052cb2f  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cb33  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cb37  8a4d0c                 -mov cl, byte ptr [ebp + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052cb3a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cb3c  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cb3e  e8fd3afbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052cb43  c7450800000000         -mov dword ptr [ebp + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cb4a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cb4f  c7450400000000         -mov dword ptr [ebp + 4], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cb56  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052cb59  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb5a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb5b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb5c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cb5e:
    // 0052cb5e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0052cb60  e95fffffff             -jmp 0x52cac4
    goto L_0x0052cac4;
L_0x0052cb65:
    // 0052cb65  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cb6a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cb6d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb6e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb6f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb70  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cb71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_52cb74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cb74  c70001000000           -mov dword ptr [eax], 1
    *app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0052cb7a  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cb81  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0052cb83  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cb8a  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052cb8d  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0052cb92  c70380ca5200           -mov dword ptr [ebx], 0x52ca80
    *app->getMemory<x86::reg32>(cpu.ebx) = 5425792 /*0x52ca80*/;
    // 0052cb98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52cba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cba0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052cba1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cba2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cba3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052cba4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cba7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052cba9  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052cbad  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0052cbb1  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0052cbb5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0052cbb7  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0052cbba  0f8589000000           -jne 0x52cc49
    if (!cpu.flags.zf)
    {
        goto L_0x0052cc49;
    }
L_0x0052cbc0:
    // 0052cbc0  837c240800             +cmp dword ptr [esp + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cbc5  0f8ec6000000           -jle 0x52cc91
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052cc91;
    }
    // 0052cbcb  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cbce  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cbd1  0f8d8b000000           -jge 0x52cc62
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052cc62;
    }
L_0x0052cbd7:
    // 0052cbd7  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0052cbda  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cbdd  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cbe1  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052cbe3  39fa                   +cmp edx, edi
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
    // 0052cbe5  0f8fc6000000           -jg 0x52ccb1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052ccb1;
    }
L_0x0052cbeb:
    // 0052cbeb  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cbef  8b450e                 -mov eax, dword ptr [ebp + 0xe]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 0052cbf2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0052cbf4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0052cbf7  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0052cbfa  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052cbfc  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cbff  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cc01  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cc03  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052cc05  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052cc07  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cc08  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052cc0a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0052cc0d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg32>(cpu.esi);
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
    // 0052cc0f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0052cc11  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0052cc14  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg8>(cpu.esi);
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
    // 0052cc16  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc17  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cc1b  8b4d0e                 -mov ecx, dword ptr [ebp + 0xe]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 0052cc1e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0052cc21  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052cc24  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cc26  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052cc28  895c2408               -mov dword ptr [esp + 8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052cc2c  894508                 -mov dword ptr [ebp + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0052cc2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0052cc31  668b5d12               -mov bx, word ptr [ebp + 0x12]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(18) /* 0x12 */);
    // 0052cc35  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cc37  01d3                   +add ebx, edx
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
    // 0052cc39  8d0c07                 -lea ecx, [edi + eax]
    cpu.ecx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0052cc3c  66895d12               -mov word ptr [ebp + 0x12], bx
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.bx;
    // 0052cc40  894c2404               -mov dword ptr [esp + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0052cc44  e977ffffff             -jmp 0x52cbc0
    goto L_0x0052cbc0;
L_0x0052cc49:
    // 0052cc49  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0052cc4b  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0052cc4f  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cc52  e8414dfeff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052cc57  66c741120000           -mov word ptr [ecx + 0x12], 0
    *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 0052cc5d  e95effffff             -jmp 0x52cbc0
    goto L_0x0052cbc0;
L_0x0052cc62:
    // 0052cc62  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052cc64  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0052cc67  e8904cfeff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052cc6c  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0052cc6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052cc71  752c                   -jne 0x52cc9f
    if (!cpu.flags.zf)
    {
        goto L_0x0052cc9f;
    }
    // 0052cc73  66837d1200             +cmp word ptr [ebp + 0x12], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(18) /* 0x12 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0052cc78  7417                   -je 0x52cc91
    if (cpu.flags.zf)
    {
        goto L_0x0052cc91;
    }
    // 0052cc7a  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cc7e  8b4d0e                 -mov ecx, dword ptr [ebp + 0xe]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(14) /* 0xe */);
    // 0052cc81  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cc85  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0052cc88  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cc8a  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cc8c  e8af39fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052cc91:
    // 0052cc91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0052cc93  668b4512               -mov ax, word ptr [ebp + 0x12]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(18) /* 0x12 */);
    // 0052cc97  83c40c                 +add esp, 0xc
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052cc9a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc9b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc9c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc9d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cc9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cc9f:
    // 0052cc9f  c7450800000000         -mov dword ptr [ebp + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cca6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052cca9  894504                 -mov dword ptr [ebp + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052ccac  e926ffffff             -jmp 0x52cbd7
    goto L_0x0052cbd7;
L_0x0052ccb1:
    // 0052ccb1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0052ccb3  e933ffffff             -jmp 0x52cbeb
    goto L_0x0052cbeb;
}

/* align: skip  */
void Application::sub_52ccb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ccb8  e8a3040000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052ccbd  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052ccc3  c74204ffffffff         -mov dword ptr [edx + 4], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 4294967295 /*0xffffffff*/;
    // 0052ccca  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052ccd1  66c742120000           -mov word ptr [edx + 0x12], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 0052ccd7  d1fb                   -sar ebx, 1
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (1 /*0x1*/ % 32));
    // 0052ccd9  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052ccdc  66895a10               -mov word ptr [edx + 0x10], bx
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.bx;
    // 0052cce0  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 0052cce5  c701a0cb5200           -mov dword ptr [ecx], 0x52cba0
    *app->getMemory<x86::reg32>(cpu.ecx) = 5426080 /*0x52cba0*/;
    // 0052cceb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52ccf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ccf0  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052ccf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_52ccf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ccf4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ccf5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ccf6  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ccf7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052ccfa  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052ccfc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0052ccfe  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0052cd01  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052cd04  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0052cd07  39d3                   +cmp ebx, edx
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
    // 0052cd09  733a                   -jae 0x52cd45
    if (!cpu.flags.cf)
    {
        goto L_0x0052cd45;
    }
    // 0052cd0b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052cd0c  8d143b                 -lea edx, [ebx + edi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 0052cd0f  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0052cd12  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0052cd15  39ca                   +cmp edx, ecx
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
    // 0052cd17  734b                   -jae 0x52cd64
    if (!cpu.flags.cf)
    {
        goto L_0x0052cd64;
    }
    // 0052cd19  83781400               +cmp dword ptr [eax + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cd1d  742d                   -je 0x52cd4c
    if (cpu.flags.zf)
    {
        goto L_0x0052cd4c;
    }
    // 0052cd1f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cd20  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cd23  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052cd25  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cd27  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052cd29  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052cd2c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052cd2d  d3e7                   -shl edi, cl
    cpu.edi <<= cpu.cl % 32;
    // 0052cd2f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cd30  e86b3bfdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052cd35:
    // 0052cd35  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cd38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cd3d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0052cd3e:
    // 0052cd3e  83c404                 +add esp, 4
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
    // 0052cd41  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cd42  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cd43  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cd44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cd45:
    // 0052cd45  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052cd4a  ebf2                   -jmp 0x52cd3e
    goto L_0x0052cd3e;
L_0x0052cd4c:
    // 0052cd4c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cd4d  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cd50  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052cd52  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cd54  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052cd56  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052cd59  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052cd5a  d3e7                   +shl edi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.edi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0052cd5c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cd5d  e8ae3dfdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052cd62  ebd1                   -jmp 0x52cd35
    goto L_0x0052cd35;
L_0x0052cd64:
    // 0052cd64  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0052cd66  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0052cd69  29dd                   -sub ebp, ebx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052cd6b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052cd6d  744b                   -je 0x52cdba
    if (cpu.flags.zf)
    {
        goto L_0x0052cdba;
    }
    // 0052cd6f  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cd72  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cd74  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0052cd76  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052cd78  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cd79  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0052cd7b  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052cd7e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cd80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052cd81  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cd83  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cd84  e8173bfdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052cd89:
    // 0052cd89  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cd8c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cd90  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052cd92  8a4910                 -mov cl, byte ptr [ecx + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0052cd95  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0052cd97  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cd99  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052cd9d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cd9f  8a4910                 -mov cl, byte ptr [ecx + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0052cda2  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cda4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cda6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052cda8  e89338fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052cdad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cdb2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cdb3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052cdb6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cdb7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cdb8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cdb9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cdba:
    // 0052cdba  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cdbb  8a480c                 -mov cl, byte ptr [eax + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052cdbe  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052cdc0  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cdc2  8a4818                 -mov cl, byte ptr [eax + 0x18]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0052cdc5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052cdc7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cdc9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052cdca  d3e0                   +shl eax, cl
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
    // 0052cdcc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cdcd  e83e3dfdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052cdd2  ebb5                   -jmp 0x52cd89
    goto L_0x0052cd89;
}

/* align: skip  */
void Application::sub_52cdd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cdd4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cdd5  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cdd9  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cde0  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052cde2  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052cde5  8d1431                 -lea edx, [ecx + esi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0052cde8  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0052cdeb  894814                 -mov dword ptr [eax + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0052cdee  8d5602                 -lea edx, [esi + 2]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0052cdf1  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052cdf4  897018                 -mov dword ptr [eax + 0x18], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0052cdf7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052cdfb  c700f4cc5200           -mov dword ptr [eax], 0x52ccf4
    *app->getMemory<x86::reg32>(cpu.eax) = 5426420 /*0x52ccf4*/;
    // 0052ce01  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052ce05  c700f0cc5200           -mov dword ptr [eax], 0x52ccf0
    *app->getMemory<x86::reg32>(cpu.eax) = 5426416 /*0x52ccf0*/;
    // 0052ce0b  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0052ce10  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce11  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52ce20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ce20  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052ce21  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ce22  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052ce23  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ce24  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052ce26  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052ce28  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052ce2a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ce2c  7e58                   -jle 0x52ce86
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052ce86;
    }
L_0x0052ce2e:
    // 0052ce2e  8b730c                 -mov esi, dword ptr [ebx + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0052ce31  2b7304                 -sub esi, dword ptr [ebx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 0052ce34  46                     -inc esi
    (cpu.esi)++;
    // 0052ce35  39f7                   +cmp edi, esi
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ce37  7d02                   -jge 0x52ce3b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052ce3b;
    }
    // 0052ce39  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0052ce3b:
    // 0052ce3b  837b1800               +cmp dword ptr [ebx + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052ce3f  744f                   -je 0x52ce90
    if (cpu.flags.zf)
    {
        goto L_0x0052ce90;
    }
    // 0052ce41  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052ce44  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0052ce47  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0052ce49  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052ce4b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ce4c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ce4e  8a4b1c                 -mov cl, byte ptr [ebx + 0x1c]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0052ce51  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ce52  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052ce54  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052ce56  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052ce57  e8443afdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052ce5c:
    // 0052ce5c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052ce5f  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052ce62  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052ce64  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0052ce67  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052ce6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052ce6c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052ce6e  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0052ce71  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052ce73  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052ce76  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0052ce78  39d0                   +cmp eax, edx
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
    // 0052ce7a  7606                   -jbe 0x52ce82
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0052ce82;
    }
    // 0052ce7c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0052ce7f  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0052ce82:
    // 0052ce82  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052ce84  7fa8                   -jg 0x52ce2e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052ce2e;
    }
L_0x0052ce86:
    // 0052ce86  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052ce8b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce8c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce8d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce8e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ce8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052ce90:
    // 0052ce90  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0052ce93  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0052ce96  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0052ce98  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052ce9a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052ce9b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052ce9d  8a4b1c                 -mov cl, byte ptr [ebx + 0x1c]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 0052cea0  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cea1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052cea3  d3e0                   +shl eax, cl
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
    // 0052cea5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cea6  e8653cfdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052ceab  ebaf                   -jmp 0x52ce5c
    goto L_0x0052ce5c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52ceb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052ceb0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052ceb1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0052ceb5  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cebc  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0052cebe  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0052cec1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052cec5  89480c                 -mov dword ptr [eax + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0052cec8  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0052ceca  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0052cecd  8d5602                 -lea edx, [esi + 2]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0052ced0  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0052ced3  89701c                 -mov dword ptr [eax + 0x1c], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0052ced6  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0052ceda  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0052cedd  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0052cee1  c70020ce5200           -mov dword ptr [eax], 0x52ce20
    *app->getMemory<x86::reg32>(cpu.eax) = 5426720 /*0x52ce20*/;
    // 0052cee7  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 0052ceec  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052ceed  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_52cef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cef0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052cef1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cef2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052cef3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052cef4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052cef7  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052cef9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052cefb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052cefd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052ceff  7467                   -je 0x52cf68
    if (cpu.flags.zf)
    {
        goto L_0x0052cf68;
    }
    // 0052cf01  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052cf03  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052cf05  7e54                   -jle 0x52cf5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052cf5b;
    }
    // 0052cf07  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052cf0a  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x0052cf0d:
    // 0052cf0d  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052cf10  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cf13  7d5a                   -jge 0x52cf6f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052cf6f;
    }
L_0x0052cf15:
    // 0052cf15  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052cf18  2b5e08                 -sub ebx, dword ptr [esi + 8]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0052cf1b  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cf1d  7d02                   -jge 0x52cf21
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052cf21;
    }
    // 0052cf1f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0052cf21:
    // 0052cf21  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cf25  0f848c000000           -je 0x52cfb7
    if (cpu.flags.zf)
    {
        goto L_0x0052cfb7;
    }
    // 0052cf2b  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052cf2e  8a4e0c                 -mov cl, byte ptr [esi + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052cf31  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052cf33  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cf35  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052cf36  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052cf38  8a4e18                 -mov cl, byte ptr [esi + 0x18]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052cf3b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cf3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052cf3e  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cf40  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cf41  e85a39fdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052cf46:
    // 0052cf46  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052cf49  015e08                 -add dword ptr [esi + 8], ebx
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052cf4c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052cf4e  8a4e10                 -mov cl, byte ptr [esi + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052cf51  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052cf53  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052cf55  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0052cf57  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052cf59  7fb2                   -jg 0x52cf0d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0052cf0d;
    }
L_0x0052cf5b:
    // 0052cf5b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0052cf60:
    // 0052cf60  83c404                 +add esp, 4
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
    // 0052cf63  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cf64  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cf65  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cf66  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cf67  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cf68:
    // 0052cf68  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052cf6d  ebf1                   -jmp 0x52cf60
    goto L_0x0052cf60;
L_0x0052cf6f:
    // 0052cf6f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052cf72  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0052cf74  ff15b4785600           -call dword ptr [0x5678b4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5666996) /* 0x5678b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0052cf7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052cf7c  750e                   -jne 0x52cf8c
    if (!cpu.flags.zf)
    {
        goto L_0x0052cf8c;
    }
    // 0052cf7e  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052cf81  7409                   -je 0x52cf8c
    if (cpu.flags.zf)
    {
        goto L_0x0052cf8c;
    }
    // 0052cf83  c7460800000000         -mov dword ptr [esi + 8], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cf8a  eb89                   -jmp 0x52cf15
    goto L_0x0052cf15;
L_0x0052cf8c:
    // 0052cf8c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052cf8e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052cf90  8a4e10                 -mov cl, byte ptr [esi + 0x10]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052cf93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052cf95  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052cf97  e8a436fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 0052cf9c  c7460800000000         -mov dword ptr [esi + 8], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cfa3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0052cfa8  c7460400000000         -mov dword ptr [esi + 4], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cfaf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052cfb2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cfb3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cfb4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cfb5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052cfb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052cfb7:
    // 0052cfb7  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052cfba  8a4e0c                 -mov cl, byte ptr [esi + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052cfbd  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052cfbf  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052cfc1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052cfc2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052cfc4  8a4e18                 -mov cl, byte ptr [esi + 0x18]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0052cfc7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cfc8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052cfca  d3e0                   +shl eax, cl
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
    // 0052cfcc  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052cfcd  e83e3bfdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052cfd2  e96fffffff             -jmp 0x52cf46
    goto L_0x0052cf46;
}

/* align: skip 0x90 */
void Application::sub_52cfd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052cfd8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052cfd9  c70001000000           -mov dword ptr [eax], 1
    *app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 0052cfdf  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0052cfe6  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052cfed  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0052cff0  89700c                 -mov dword ptr [eax + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0052cff3  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0052cff6  8d7302                 -lea esi, [ebx + 2]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 0052cff9  897010                 -mov dword ptr [eax + 0x10], esi
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0052cffc  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0052cfff  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 0052d004  c701f0ce5200           -mov dword ptr [ecx], 0x52cef0
    *app->getMemory<x86::reg32>(cpu.ecx) = 5426928 /*0x52cef0*/;
    // 0052d00a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d00b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_52d010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d010  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d011  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0052d012  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0052d013  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d014  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d017  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0052d019  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0052d01b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0052d01d  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0052d020  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0052d022  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0052d024  756a                   -jne 0x52d090
    if (!cpu.flags.zf)
    {
        goto L_0x0052d090;
    }
L_0x0052d026:
    // 0052d026  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0052d028  0f8e9c000000           -jle 0x52d0ca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0052d0ca;
    }
    // 0052d02e  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d031  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d034  7d6b                   -jge 0x52d0a1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052d0a1;
    }
L_0x0052d036:
    // 0052d036  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0052d039  2b5e08                 -sub ebx, dword ptr [esi + 8]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
    // 0052d03c  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d03e  7d02                   -jge 0x52d042
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0052d042;
    }
    // 0052d040  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x0052d042:
    // 0052d042  807e1600               +cmp byte ptr [esi + 0x16], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0052d046  0f849b000000           -je 0x52d0e7
    if (cpu.flags.zf)
    {
        goto L_0x0052d0e7;
    }
    // 0052d04c  8b4e11                 -mov ecx, dword ptr [esi + 0x11]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(17) /* 0x11 */);
    // 0052d04f  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d052  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d055  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052d057  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052d059  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d05a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052d05c  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052d05f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052d060  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d063  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d065  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052d067  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052d068  e83338fdff             -call 0x5008a0
    cpu.esp -= 4;
    sub_5008a0(app, cpu);
    if (cpu.terminate) return;
L_0x0052d06d:
    // 0052d06d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0052d070  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d072  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d075  8b4e12                 -mov ecx, dword ptr [esi + 0x12]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0052d078  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d07a  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d07d  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d07f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0052d081  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052d084  895608                 -mov dword ptr [esi + 8], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0052d087  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0052d089  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0052d08b  894e10                 -mov dword ptr [esi + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0052d08e  eb96                   -jmp 0x52d026
    goto L_0x0052d026;
L_0x0052d090:
    // 0052d090  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0052d093  e80049feff             -call 0x511998
    cpu.esp -= 4;
    sub_511998(app, cpu);
    if (cpu.terminate) return;
    // 0052d098  c7411000000000         -mov dword ptr [ecx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0052d09f  eb85                   -jmp 0x52d026
    goto L_0x0052d026;
L_0x0052d0a1:
    // 0052d0a1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0052d0a3  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0052d0a6  e85148feff             -call 0x5118fc
    cpu.esp -= 4;
    sub_5118fc(app, cpu);
    if (cpu.terminate) return;
    // 0052d0ab  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0052d0ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052d0af  7524                   -jne 0x52d0d5
    if (!cpu.flags.zf)
    {
        goto L_0x0052d0d5;
    }
    // 0052d0b1  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d0b5  7413                   -je 0x52d0ca
    if (cpu.flags.zf)
    {
        goto L_0x0052d0ca;
    }
    // 0052d0b7  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0052d0b9  8b4e12                 -mov ecx, dword ptr [esi + 0x12]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 0052d0bc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0052d0be  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d0c1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0052d0c3  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0052d0c5  e87635fbff             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
L_0x0052d0ca:
    // 0052d0ca  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0052d0cd  83c404                 +add esp, 4
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
    // 0052d0d0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d0d1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d0d2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d0d3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d0d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d0d5:
    // 0052d0d5  c7460800000000         -mov dword ptr [esi + 8], 0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052d0dc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0052d0df  894604                 -mov dword ptr [esi + 4], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0052d0e2  e94fffffff             -jmp 0x52d036
    goto L_0x0052d036;
L_0x0052d0e7:
    // 0052d0e7  8b4e11                 -mov ecx, dword ptr [esi + 0x11]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(17) /* 0x11 */);
    // 0052d0ea  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0052d0ed  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d0f0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 0052d0f2  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0052d0f4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0052d0f5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0052d0f7  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0052d0fa  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052d0fb  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 0052d0fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0052d100  d3e0                   +shl eax, cl
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
    // 0052d102  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0052d103  e8083afdff             -call 0x500b10
    cpu.esp -= 4;
    sub_500b10(app, cpu);
    if (cpu.terminate) return;
    // 0052d108  e960ffffff             -jmp 0x52d06d
    goto L_0x0052d06d;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_52d110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d110  e84b000000             -call 0x52d160
    cpu.esp -= 4;
    sub_52d160(app, cpu);
    if (cpu.terminate) return;
    // 0052d115  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0052d11b  c74204ffffffff         -mov dword ptr [edx + 4], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 4294967295 /*0xffffffff*/;
    // 0052d122  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0052d129  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0052d12c  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0052d12e  c7421000000000         -mov dword ptr [edx + 0x10], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0052d135  00c8                   -add al, cl
    (cpu.al) += x86::reg8(x86::sreg8(cpu.cl));
    // 0052d137  884214                 -mov byte ptr [edx + 0x14], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.al;
    // 0052d13a  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0052d13c  885a16                 -mov byte ptr [edx + 0x16], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
    // 0052d13f  0402                   -add al, 2
    (cpu.al) += x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0052d141  884215                 -mov byte ptr [edx + 0x15], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 0052d144  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0052d148  884a17                 -mov byte ptr [edx + 0x17], cl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(23) /* 0x17 */) = cpu.cl;
    // 0052d14b  c70010d05200           -mov dword ptr [eax], 0x52d010
    *app->getMemory<x86::reg32>(cpu.eax) = 5427216 /*0x52d010*/;
    // 0052d151  b818000000             -mov eax, 0x18
    cpu.eax = 24 /*0x18*/;
    // 0052d156  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_52d160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0052d160  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0052d161  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0052d162  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0052d163  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0052d165  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0052d167  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0052d169:
    // 0052d169  8b8244b0a000           -mov eax, dword ptr [edx + 0xa0b044]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10530884) /* 0xa0b044 */);
    // 0052d16f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0052d171  7512                   -jne 0x52d185
    if (!cpu.flags.zf)
    {
        goto L_0x0052d185;
    }
L_0x0052d173:
    // 0052d173  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0052d176  41                     -inc ecx
    (cpu.ecx)++;
    // 0052d177  83fa40                 +cmp edx, 0x40
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0052d17a  7ced                   -jl 0x52d169
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0052d169;
    }
    // 0052d17c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0052d181  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d182  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d183  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d184  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0052d185:
    // 0052d185  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0052d187  e8102bfdff             -call 0x4ffc9c
    cpu.esp -= 4;
    sub_4ffc9c(app, cpu);
    if (cpu.terminate) return;
    // 0052d18c  39d8                   +cmp eax, ebx
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
    // 0052d18e  75e3                   -jne 0x52d173
    if (!cpu.flags.zf)
    {
        goto L_0x0052d173;
    }
    // 0052d190  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0052d192  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d193  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d194  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0052d195  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
