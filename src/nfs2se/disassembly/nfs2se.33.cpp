#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4aca14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aca14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aca15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aca16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aca17  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aca18  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004aca1a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aca1c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aca1e  8b5718                 -mov edx, dword ptr [edi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004aca21  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004aca24  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004aca26  39ca                   +cmp edx, ecx
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
    // 004aca28  7d3e                   -jge 0x4aca68
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aca68;
    }
    // 004aca2a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aca2c  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004aca2f  8b471a                 -mov eax, dword ptr [edi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 004aca32  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004aca35  39c6                   +cmp esi, eax
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
    // 004aca37  7e39                   -jle 0x4aca72
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aca72;
    }
    // 004aca39  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004aca3e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004aca40  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004aca42:
    // 004aca42  8b7b1a                 -mov edi, dword ptr [ebx + 0x1a]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 004aca45  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004aca48  39f8                   +cmp eax, edi
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
    // 004aca4a  0f8d78000000           -jge 0x4acac8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004acac8;
    }
    // 004aca50  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004aca53  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004aca57  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004aca5a  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004aca5d  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aca60  01ef                   +add edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aca62  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004aca63  897b0c                 -mov dword ptr [ebx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004aca66  ebda                   -jmp 0x4aca42
    goto L_0x004aca42;
L_0x004aca68:
    // 004aca68  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004aca6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aca71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aca72:
    // 004aca72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aca74  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004aca76  7e20                   -jle 0x4aca98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aca98;
    }
    // 004aca78  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x004aca7a:
    // 004aca7a  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004aca7d  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004aca81  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004aca84  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004aca87  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aca8a  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aca8d  40                     -inc eax
    (cpu.eax)++;
    // 004aca8e  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004aca91  39f0                   +cmp eax, esi
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
    // 004aca93  7ce5                   -jl 0x4aca7a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aca7a;
    }
    // 004aca95  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004aca98:
    // 004aca98  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004aca9a  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004aca9d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004aca9f  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004acaa1:
    // 004acaa1  8b4b1a                 -mov ecx, dword ptr [ebx + 0x1a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 004acaa4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004acaa7  39c8                   +cmp eax, ecx
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
    // 004acaa9  7d12                   -jge 0x4acabd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004acabd;
    }
    // 004acaab  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acaae  47                     -inc edi
    (cpu.edi)++;
    // 004acaaf  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004acab3  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004acab6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004acab7  66894e1c               -mov word ptr [esi + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004acabb  ebe4                   -jmp 0x4acaa1
    goto L_0x004acaa1;
L_0x004acabd:
    // 004acabd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acabf  66897b1c               -mov word ptr [ebx + 0x1c], di
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.di;
    // 004acac3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acac4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acac5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acac6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acac7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acac8:
    // 004acac8  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004acacb  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004acacd  2b6b18                 -sub ebp, dword ptr [ebx + 0x18]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 004acad0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004acad2  0f8c7b000000           -jl 0x4acb53
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acb53;
    }
L_0x004acad8:
    // 004acad8  39ee                   +cmp esi, ebp
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
    // 004acada  0f8d77000000           -jge 0x4acb57
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004acb57;
    }
    // 004acae0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004acae2:
    // 004acae2  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004acae5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004acaec  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acaee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004acaf0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004acaf3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acaf5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004acaf7  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004acafc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004acaff  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004acb01  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004acb04  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004acb06  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004acb08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004acb09  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acb0c  e85f4b0000             -call 0x4b1670
    cpu.esp -= 4;
    sub_4b1670(app, cpu);
    if (cpu.terminate) return;
    // 004acb11  017b18                 -add dword ptr [ebx + 0x18], edi
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edi));
    // 004acb14  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004acb16  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004acb19  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004acb1b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004acb1e  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004acb21  39fd                   +cmp ebp, edi
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
    // 004acb23  7536                   -jne 0x4acb5b
    if (!cpu.flags.zf)
    {
        goto L_0x004acb5b;
    }
    // 004acb25  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acb27  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004acb2a  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004acb2c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004acb2e  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004acb30  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004acb32  7e18                   -jle 0x4acb4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004acb4c;
    }
    // 004acb34  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004acb36:
    // 004acb36  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004acb39  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 004acb3c  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004acb3f  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acb42  4e                     -dec esi
    (cpu.esi)--;
    // 004acb43  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004acb46  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004acb48  7fec                   -jg 0x4acb36
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004acb36;
    }
    // 004acb4a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004acb4c:
    // 004acb4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acb4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acb53:
    // 004acb53  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004acb55  eb81                   -jmp 0x4acad8
    goto L_0x004acad8;
L_0x004acb57:
    // 004acb57  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004acb59  eb87                   -jmp 0x4acae2
    goto L_0x004acae2;
L_0x004acb5b:
    // 004acb5b  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004acb5d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acb5f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004acb61  7c0b                   -jl 0x4acb6e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acb6e;
    }
    // 004acb63  6689431c               -mov word ptr [ebx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 004acb67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acb69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acb6e:
    // 004acb6e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004acb70  8d343f                 -lea esi, [edi + edi]
    cpu.esi = x86::reg32(cpu.edi + cpu.edi * 1);
L_0x004acb73:
    // 004acb73  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acb76  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004acb79  47                     -inc edi
    (cpu.edi)++;
    // 004acb7a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acb7d  668b4c31fe             -mov cx, word ptr [ecx + esi - 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */ + cpu.esi * 1);
    // 004acb82  40                     -inc eax
    (cpu.eax)++;
    // 004acb83  66894a1c               -mov word ptr [edx + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004acb87  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004acb89  7ce8                   -jl 0x4acb73
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acb73;
    }
    // 004acb8b  6689431c               -mov word ptr [ebx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 004acb8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acb91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acb95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4acb98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acb98  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004acb9f  66c7401c0000           -mov word ptr [eax + 0x1c], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004acba5  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004acbab  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004acbb1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004acbb4  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004acbb7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004acbbb  c70014ca4a00           -mov dword ptr [eax], 0x4aca14
    app->getMemory<x86::reg32>(cpu.eax) = 4901396 /*0x4aca14*/;
    // 004acbc1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004acbc5  c70010ca4a00           -mov dword ptr [eax], 0x4aca10
    app->getMemory<x86::reg32>(cpu.eax) = 4901392 /*0x4aca10*/;
    // 004acbcb  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 004acbd0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4acbe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acbe0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004acbe1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004acbe2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004acbe3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004acbe6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004acbe8  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004acbec  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004acbef  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004acbf1  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004acbf3  39d8                   +cmp eax, ebx
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
    // 004acbf5  7d02                   -jge 0x4acbf9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004acbf9;
    }
    // 004acbf7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004acbf9:
    // 004acbf9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acbfb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004acbfd  7e19                   -jle 0x4acc18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004acc18;
    }
    // 004acbff  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004acc03:
    // 004acc03  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acc06  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004acc09  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acc0c  40                     -inc eax
    (cpu.eax)++;
    // 004acc0d  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004acc11  39f8                   +cmp eax, edi
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
    // 004acc13  7cee                   -jl 0x4acc03
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acc03;
    }
    // 004acc15  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004acc18:
    // 004acc18  39e8                   +cmp eax, ebp
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
    // 004acc1a  7d1c                   -jge 0x4acc38
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004acc38;
    }
    // 004acc1c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004acc20  8d1c00                 -lea ebx, [eax + eax]
    cpu.ebx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004acc23  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004acc25:
    // 004acc25  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acc28  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 004acc2b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acc2e  40                     -inc eax
    (cpu.eax)++;
    // 004acc2f  668971fe               -mov word ptr [ecx - 2], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 004acc33  39e8                   +cmp eax, ebp
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
    // 004acc35  7cee                   -jl 0x4acc25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acc25;
    }
    // 004acc37  90                     -nop 
    ;
L_0x004acc38:
    // 004acc38  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004acc3b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004acc3d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004acc3f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004acc42  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acc43  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acc44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acc45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4acc48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acc48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004acc49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004acc4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004acc4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004acc4c  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004acc4f  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004acc51  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004acc53  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004acc55  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004acc58  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004acc5a  7e55                   -jle 0x4accb1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004accb1;
    }
    // 004acc5c  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004acc5f  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004acc63  8d6826                 -lea ebp, [eax + 0x26]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(38) /* 0x26 */);
L_0x004acc66:
    // 004acc66  66837e2400             +cmp word ptr [esi + 0x24], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004acc6b  755c                   -jne 0x4accc9
    if (!cpu.flags.zf)
    {
        goto L_0x004accc9;
    }
    // 004acc6d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acc70  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004acc73  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004acc76  39c8                   +cmp eax, ecx
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
    // 004acc78  7d70                   -jge 0x4accea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004accea;
    }
    // 004acc7a  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004acc7e  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004acc83  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acc85  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004acc88  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004acc8a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004acc8d  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004acc93  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004acc95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004acc96  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acc99  e8d2490000             -call 0x4b1670
    cpu.esp -= 4;
    sub_4b1670(app, cpu);
    if (cpu.terminate) return;
    // 004acc9e  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acca1  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004acca4  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004acca7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004accaa  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004accad:
    // 004accad  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004accaf  7fb5                   -jg 0x4acc66
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004acc66;
    }
L_0x004accb1:
    // 004accb1  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004accb4  01460c                 -add dword ptr [esi + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004accb7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004accb9  0f8c3f010000           -jl 0x4acdfe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acdfe;
    }
    // 004accbf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004accc1  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004accc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004accc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004accc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004accc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004accc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004accc9:
    // 004accc9  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004acccd  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004acccf  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004accd2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004accd4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004accd7  e804ffffff             -call 0x4acbe0
    cpu.esp -= 4;
    sub_4acbe0(app, cpu);
    if (cpu.terminate) return;
    // 004accdc  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004acce0  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004acce2  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004acce4  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004acce8  ebc3                   -jmp 0x4accad
    goto L_0x004accad;
L_0x004accea:
    // 004accea  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004accee  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004accf1  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004accf6  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004accfa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004accfc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004accff  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004acd01  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004acd07  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004acd0a  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004acd0d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004acd0f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004acd10  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acd13  e858490000             -call 0x4b1670
    cpu.esp -= 4;
    sub_4b1670(app, cpu);
    if (cpu.terminate) return;
    // 004acd18  8346181c               -add dword ptr [esi + 0x18], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004acd1c  668b5e20               -mov bx, word ptr [esi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004acd20  668b4618               -mov ax, word ptr [esi + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acd24  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004acd29  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004acd2b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004acd2d  668b8694000000         -mov ax, word ptr [esi + 0x94]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 004acd34  66895624               -mov word ptr [esi + 0x24], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.dx;
    // 004acd38  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004acd3c  668b8696000000         -mov ax, word ptr [esi + 0x96]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */);
    // 004acd43  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004acd45  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004acd49  41                     -inc ecx
    (cpu.ecx)++;
    // 004acd4a  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004acd4d  66894e24               -mov word ptr [esi + 0x24], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004acd51  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004acd53  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004acd58  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004acd5b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004acd5d  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004acd60  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004acd63  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004acd66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004acd68  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004acd6b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004acd6d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004acd70  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004acd72  0f847a000000           -je 0x4acdf2
    if (cpu.flags.zf)
    {
        goto L_0x004acdf2;
    }
    // 004acd78  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004acd7a  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004acd7e  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004acd83  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004acd85  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004acd88  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004acd8a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004acd8d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004acd8f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004acd91  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acd94  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004acd95  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004acd98  e8d3480000             -call 0x4b1670
    cpu.esp -= 4;
    sub_4b1670(app, cpu);
    if (cpu.terminate) return;
    // 004acd9d  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acda0  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004acda3  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004acda6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004acda8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004acdab  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acdad  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004acdb1  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004acdb6  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004acdba  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004acdbc  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004acdbe  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004acdc0  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004acdc3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004acdc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acdc7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004acdc9  7e27                   -jle 0x4acdf2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004acdf2;
    }
L_0x004acdcb:
    // 004acdcb  8b4e22                 -mov ecx, dword ptr [esi + 0x22]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004acdce  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004acdd1  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004acdd3  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004acdd6  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004acdd9  66894b26               -mov word ptr [ebx + 0x26], cx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(38) /* 0x26 */) = cpu.cx;
    // 004acddd  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004acde1  43                     -inc ebx
    (cpu.ebx)++;
    // 004acde2  40                     -inc eax
    (cpu.eax)++;
    // 004acde3  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004acde7  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004acdeb  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acdee  39d8                   +cmp eax, ebx
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
    // 004acdf0  7cd9                   -jl 0x4acdcb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acdcb;
    }
L_0x004acdf2:
    // 004acdf2  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004acdf6  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004acdf9  e9affeffff             -jmp 0x4accad
    goto L_0x004accad;
L_0x004acdfe:
    // 004acdfe  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004ace01  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ace04  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ace06  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ace09  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004ace0c  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004ace0f  66894226               -mov word ptr [edx + 0x26], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(38) /* 0x26 */) = cpu.ax;
    // 004ace13  83460c02               -add dword ptr [esi + 0xc], 2
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ace17  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ace1b  41                     -inc ecx
    (cpu.ecx)++;
    // 004ace1c  47                     -inc edi
    (cpu.edi)++;
    // 004ace1d  66894e24               -mov word ptr [esi + 0x24], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004ace21  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ace23  7cd9                   -jl 0x4acdfe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acdfe;
    }
    // 004ace25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ace27  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004ace2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ace2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ace2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ace2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ace2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ace30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ace30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ace31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ace32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ace33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ace34  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ace37  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ace3b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ace3d  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ace40  8b5022                 -mov edx, dword ptr [eax + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(34) /* 0x22 */);
    // 004ace43  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ace47  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ace4a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ace4c  39ca                   +cmp edx, ecx
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
    // 004ace4e  7d2d                   -jge 0x4ace7d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ace7d;
    }
    // 004ace50  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004ace55  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ace57:
    // 004ace57  8b5622                 -mov edx, dword ptr [esi + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004ace5a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ace5d  39d3                   +cmp ebx, edx
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
    // 004ace5f  0f8d72000000           -jge 0x4aced7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aced7;
    }
    // 004ace65  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ace68  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004ace6c  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004ace6f  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ace72  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ace75  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ace77  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ace78  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004ace7b  ebda                   -jmp 0x4ace57
    goto L_0x004ace57;
L_0x004ace7d:
    // 004ace7d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ace7f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ace81  7e21                   -jle 0x4acea4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004acea4;
    }
    // 004ace83  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004ace87:
    // 004ace87  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ace8a  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004ace8e  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004ace91  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ace94  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ace97  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ace9a  43                     -inc ebx
    (cpu.ebx)++;
    // 004ace9b  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004ace9e  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004acea0  7ce5                   -jl 0x4ace87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ace87;
    }
    // 004acea2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004acea4:
    // 004acea4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004acea6  8d141b                 -lea edx, [ebx + ebx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004acea9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004aceab  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004acead:
    // 004acead  8b4e22                 -mov ecx, dword ptr [esi + 0x22]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004aceb0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004aceb3  39cb                   +cmp ebx, ecx
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
    // 004aceb5  7d12                   -jge 0x4acec9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004acec9;
    }
    // 004aceb7  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aceba  47                     -inc edi
    (cpu.edi)++;
    // 004acebb  668b4a26               -mov cx, word ptr [edx + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(38) /* 0x26 */);
    // 004acebf  83c202                 +add edx, 2
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004acec2  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004acec3  66894824               -mov word ptr [eax + 0x24], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004acec7  ebe4                   -jmp 0x4acead
    goto L_0x004acead;
L_0x004acec9:
    // 004acec9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acecb  66897e24               -mov word ptr [esi + 0x24], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.di;
    // 004acecf  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aced2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aced3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aced4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aced5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aced6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aced7:
    // 004aced7  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004aceda  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acedd  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004acee1  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004acee3  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acee5  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004acee8  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004aceec  39ef                   +cmp edi, ebp
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
    // 004aceee  7e02                   -jle 0x4acef2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004acef2;
    }
    // 004acef0  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x004acef2:
    // 004acef2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004acef4  0f8cbb000000           -jl 0x4acfb5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acfb5;
    }
L_0x004acefa:
    // 004acefa  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acefd  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004acf04  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004acf06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004acf08  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004acf0b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acf0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004acf0f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004acf14  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004acf17  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004acf19  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004acf1c  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004acf1e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004acf20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004acf21  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004acf24  e847470000             -call 0x4b1670
    cpu.esp -= 4;
    sub_4b1670(app, cpu);
    if (cpu.terminate) return;
    // 004acf29  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004acf2c  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acf2f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004acf31  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004acf33  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004acf35  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004acf37  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004acf3a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004acf3c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004acf3e  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004acf41  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004acf45  8d0c00                 -lea ecx, [eax + eax]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004acf48  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004acf4a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004acf4c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004acf4e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004acf50:
    // 004acf50  7c6a                   -jl 0x4acfbc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004acfbc;
    }
    // 004acf52  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004acf56  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004acf59  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004acf5b  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acf5d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004acf61  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004acf64  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004acf67  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004acf6b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004acf6d  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004acf70  83f81c                 +cmp eax, 0x1c
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
    // 004acf73  7d36                   -jge 0x4acfab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004acfab;
    }
    // 004acf75  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004acf79  66898694000000         -mov word ptr [esi + 0x94], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */) = cpu.ax;
    // 004acf80  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004acf84  66898696000000         -mov word ptr [esi + 0x96], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */) = cpu.ax;
    // 004acf8b  8b8698000000           -mov eax, dword ptr [esi + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 004acf91  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004acf95  c70048cc4a00           -mov dword ptr [eax], 0x4acc48
    app->getMemory<x86::reg32>(cpu.eax) = 4901960 /*0x4acc48*/;
    // 004acf9b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004acf9d  7e0c                   -jle 0x4acfab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004acfab;
    }
    // 004acf9f  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004acfa2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004acfa4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004acfa6  e89dfcffff             -call 0x4acc48
    cpu.esp -= 4;
    sub_4acc48(app, cpu);
    if (cpu.terminate) return;
L_0x004acfab:
    // 004acfab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004acfad  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004acfb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004acfb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004acfb5:
    // 004acfb5  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004acfb7  e93effffff             -jmp 0x4acefa
    goto L_0x004acefa;
L_0x004acfbc:
    // 004acfbc  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004acfbf  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004acfc2  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004acfc5  668b0c28               -mov cx, word ptr [eax + ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1);
    // 004acfc9  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004acfcc  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acfcf  66894d26               -mov word ptr [ebp + 0x26], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(38) /* 0x26 */) = cpu.cx;
    // 004acfd3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004acfd7  43                     -inc ebx
    (cpu.ebx)++;
    // 004acfd8  41                     -inc ecx
    (cpu.ecx)++;
    // 004acfd9  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004acfdc  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004acfe0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004acfe2  e969ffffff             -jmp 0x4acf50
    goto L_0x004acf50;
}

/* align: skip 0x90 */
void Application::sub_4acfe8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004acfe8  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004acfef  66c740240000           -mov word ptr [eax + 0x24], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004acff5  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004acffb  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ad001  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ad004  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004ad007  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004ad00a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad00e  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004ad011  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ad015  899098000000           -mov dword ptr [eax + 0x98], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.edx;
    // 004ad01b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ad01f  c70230ce4a00           -mov dword ptr [edx], 0x4ace30
    app->getMemory<x86::reg32>(cpu.edx) = 4902448 /*0x4ace30*/;
    // 004ad025  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ad02b  b89c000000             -mov eax, 0x9c
    cpu.eax = 156 /*0x9c*/;
    // 004ad030  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ad040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad040  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad041  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad042  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad043  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ad046  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ad048  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004ad04b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad04d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ad04f  0f84c8000000           -je 0x4ad11d
    if (cpu.flags.zf)
    {
        goto L_0x004ad11d;
    }
    // 004ad055  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad056  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ad058  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ad05b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad05d  0f8ea2000000           -jle 0x4ad105
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad105;
    }
    // 004ad063  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004ad066  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ad06a  8d501e                 -lea edx, [eax + 0x1e]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 004ad06d  8d6814                 -lea ebp, [eax + 0x14]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ad070  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ad073  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ad077  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004ad07b:
    // 004ad07b  66837e1c00             +cmp word ptr [esi + 0x1c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ad080  0f85a3000000           -jne 0x4ad129
    if (!cpu.flags.zf)
    {
        goto L_0x004ad129;
    }
    // 004ad086  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ad089  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ad08c  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004ad08f  39c8                   +cmp eax, ecx
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
    // 004ad091  0f8dbb000000           -jge 0x4ad152
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad152;
    }
    // 004ad097  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004ad099  2b5618                 -sub edx, dword ptr [esi + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 004ad09c  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004ad0a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad0a3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad0a6  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad0a8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ad0ac  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004ad0af  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ad0b3  39c7                   +cmp edi, eax
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
    // 004ad0b5  7d11                   -jge 0x4ad0c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad0c8;
    }
    // 004ad0b7  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 004ad0ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad0bc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad0bf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad0c1  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004ad0c4  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x004ad0c8:
    // 004ad0c8  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ad0cc  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ad0d0  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004ad0d2  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004ad0d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad0d9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad0dc  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad0de  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad0e1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad0e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad0e4  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ad0e7  e884450000             -call 0x4b1670
    cpu.esp -= 4;
    sub_4b1670(app, cpu);
    if (cpu.terminate) return;
    // 004ad0ec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad0ef  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ad0f2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ad0f6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad0f8  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad0fa  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004ad0fd:
    // 004ad0fd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad0ff  0f8f76ffffff           -jg 0x4ad07b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ad07b;
    }
L_0x004ad105:
    // 004ad105  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004ad108  01460c                 -add dword ptr [esi + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad10b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad10d  0f8ce8000000           -jl 0x4ad1fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad1fb;
    }
    // 004ad113  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad116  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ad119  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad11a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad11b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad11c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad11d:
    // 004ad11d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ad122  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ad125  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad126  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad127  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad128  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad129:
    // 004ad129  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad12d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ad131  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004ad134  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ad136  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ad139  e8a2faffff             -call 0x4acbe0
    cpu.esp -= 4;
    sub_4acbe0(app, cpu);
    if (cpu.terminate) return;
    // 004ad13e  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ad142  668b5e1c               -mov bx, word ptr [esi + 0x1c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad146  2b5c2410               -sub ebx, dword ptr [esp + 0x10]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004ad14a  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ad14c  66895e1c               -mov word ptr [esi + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.bx;
    // 004ad150  ebab                   -jmp 0x4ad0fd
    goto L_0x004ad0fd;
L_0x004ad152:
    // 004ad152  837e1001               +cmp dword ptr [esi + 0x10], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad156  744f                   -je 0x4ad1a7
    if (cpu.flags.zf)
    {
        goto L_0x004ad1a7;
    }
    // 004ad158  3b4e18                 +cmp ecx, dword ptr [esi + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad15b  7e4a                   -jle 0x4ad1a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad1a7;
    }
    // 004ad15d  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ad161  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004ad166  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad168  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad16b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad16d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad170  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ad176  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad178  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad179  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ad17c  e8ef440000             -call 0x4b1670
    cpu.esp -= 4;
    sub_4b1670(app, cpu);
    if (cpu.terminate) return;
    // 004ad181  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ad184  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ad187  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ad18a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ad18c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad18f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad191  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004ad196  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ad199  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad19b  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad19d  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ad1a0  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad1a2  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad1a4  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004ad1a7:
    // 004ad1a7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ad1ab  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ad1ad  ff15b4a14c00           -call dword ptr [0x4ca1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ad1b3  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad1b6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ad1b8  7424                   -je 0x4ad1de
    if (cpu.flags.zf)
    {
        goto L_0x004ad1de;
    }
    // 004ad1ba  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004ad1bd  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 004ad1c1  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004ad1c5  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004ad1c9  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad1cc  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004ad1d3  83c008                 +add eax, 8
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
    // 004ad1d6  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ad1d9  e91fffffff             -jmp 0x4ad0fd
    goto L_0x004ad0fd;
L_0x004ad1de:
    // 004ad1de  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ad1e1  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ad1e3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad1e5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ad1e7  e8d36ffdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004ad1ec  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ad1ef  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ad1f1  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004ad1f3  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ad1f6  e90affffff             -jmp 0x4ad105
    goto L_0x004ad105;
L_0x004ad1fb:
    // 004ad1fb  8b561a                 -mov edx, dword ptr [esi + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004ad1fe  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ad201  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ad204  668b00                 -mov ax, word ptr [eax]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax);
    // 004ad207  668944561e             -mov word ptr [esi + edx*2 + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(30) /* 0x1e */ + cpu.edx * 2) = cpu.ax;
    // 004ad20c  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ad20f  668b4e1c               -mov cx, word ptr [esi + 0x1c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad213  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad216  41                     -inc ecx
    (cpu.ecx)++;
    // 004ad217  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004ad21a  47                     -inc edi
    (cpu.edi)++;
    // 004ad21b  66894e1c               -mov word ptr [esi + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004ad21f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad221  7cd8                   -jl 0x4ad1fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad1fb;
    }
    // 004ad223  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad225  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad226  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004ad229  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad22a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad22b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad22c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ad230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad230  c7401001000000         -mov dword ptr [eax + 0x10], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004ad237  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004ad23e  66c7401c0000           -mov word ptr [eax + 0x1c], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004ad244  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004ad24a  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ad250  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004ad253  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ad257  c70040d04a00           -mov dword ptr [eax], 0x4ad040
    app->getMemory<x86::reg32>(cpu.eax) = 4902976 /*0x4ad040*/;
    // 004ad25d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ad261  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ad267  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 004ad26c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ad270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad270  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004ad273  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ad274(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad274  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad275  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad276  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad277  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad278  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad27b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ad27d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ad27f  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004ad282  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004ad285  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ad287  39f9                   +cmp ecx, edi
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
    // 004ad289  7d3f                   -jge 0x4ad2ca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad2ca;
    }
    // 004ad28b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ad28d  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ad290  8b501e                 -mov edx, dword ptr [eax + 0x1e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 004ad293  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ad296  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004ad298  39d6                   +cmp esi, edx
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
    // 004ad29a  7e3b                   -jle 0x4ad2d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad2d7;
    }
    // 004ad29c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004ad2a1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004ad2a3:
    // 004ad2a3  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004ad2a6  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ad2a9  39ca                   +cmp edx, ecx
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
    // 004ad2ab  0f8d8a000000           -jge 0x4ad33b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad33b;
    }
    // 004ad2b1  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ad2b4  668b4824               -mov cx, word ptr [eax + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ad2b8  66894d00               -mov word ptr [ebp], cx
    app->getMemory<x86::reg16>(cpu.ebp) = cpu.cx;
    // 004ad2bc  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ad2bf  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad2c2  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ad2c4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ad2c5  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004ad2c8  ebd9                   -jmp 0x4ad2a3
    goto L_0x004ad2a3;
L_0x004ad2ca:
    // 004ad2ca  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ad2cf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad2d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad2d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad2d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad2d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad2d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad2d7:
    // 004ad2d7  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ad2d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad2db  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ad2dd  7e1d                   -jle 0x4ad2fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad2fc;
    }
L_0x004ad2df:
    // 004ad2df  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ad2e2  668b7824               -mov di, word ptr [eax + 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ad2e6  668939                 -mov word ptr [ecx], di
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.di;
    // 004ad2e9  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ad2ec  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad2ef  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad2f2  42                     -inc edx
    (cpu.edx)++;
    // 004ad2f3  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004ad2f6  39f2                   +cmp edx, esi
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
    // 004ad2f8  7ce5                   -jl 0x4ad2df
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad2df;
    }
    // 004ad2fa  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ad2fc:
    // 004ad2fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad2fe  8d3412                 -lea esi, [edx + edx]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004ad301  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ad304  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad306  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004ad308:
    // 004ad308  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004ad30b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ad30e  39ca                   +cmp edx, ecx
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
    // 004ad310  7d18                   -jge 0x4ad32a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad32a;
    }
    // 004ad312  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad315  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ad319  66894822               -mov word ptr [eax + 0x22], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(34) /* 0x22 */) = cpu.cx;
    // 004ad31d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad320  83c602                 +add esi, 2
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
    // 004ad323  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ad324  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ad325  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004ad328  ebde                   -jmp 0x4ad308
    goto L_0x004ad308;
L_0x004ad32a:
    // 004ad32a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad32d  66894320               -mov word ptr [ebx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 004ad331  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad333  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad336  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad337  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad338  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad339  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad33a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad33b:
    // 004ad33b  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ad33e  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004ad341  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004ad343  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad345  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad347  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ad349  0f8c87000000           -jl 0x4ad3d6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad3d6;
    }
L_0x004ad34f:
    // 004ad34f  39ee                   +cmp esi, ebp
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
    // 004ad351  0f8d86000000           -jge 0x4ad3dd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad3dd;
    }
    // 004ad357  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x004ad35a:
    // 004ad35a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad35d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004ad35f  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004ad362  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad364  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ad366  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004ad369  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad36b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ad36d  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ad372  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad375  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad377  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004ad37a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad37c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ad37d  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ad380  e8db430000             -call 0x4b1760
    cpu.esp -= 4;
    sub_4b1760(app, cpu);
    if (cpu.terminate) return;
    // 004ad385  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad388  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004ad38b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad38e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad390  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ad392  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ad394  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ad397  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad399  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad39c  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004ad39f  39fd                   +cmp ebp, edi
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
    // 004ad3a1  7542                   -jne 0x4ad3e5
    if (!cpu.flags.zf)
    {
        goto L_0x004ad3e5;
    }
    // 004ad3a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad3a5  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ad3a8  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ad3aa  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad3ac  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad3ae  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ad3b0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ad3b2  7e18                   -jle 0x4ad3cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad3cc;
    }
    // 004ad3b4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004ad3b6:
    // 004ad3b6  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ad3b9  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 004ad3bc  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ad3bf  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad3c2  4e                     -dec esi
    (cpu.esi)--;
    // 004ad3c3  897b10                 -mov dword ptr [ebx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004ad3c6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ad3c8  7fec                   -jg 0x4ad3b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ad3b6;
    }
    // 004ad3ca  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ad3cc:
    // 004ad3cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad3ce  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad3d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad3d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad3d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad3d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad3d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad3d6:
    // 004ad3d6  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004ad3d8  e972ffffff             -jmp 0x4ad34f
    goto L_0x004ad34f;
L_0x004ad3dd:
    // 004ad3dd  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004ad3e0  e975ffffff             -jmp 0x4ad35a
    goto L_0x004ad35a;
L_0x004ad3e5:
    // 004ad3e5  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ad3ea  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ad3ec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ad3ee  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad3f1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad3f3  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004ad3f5  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad3f7  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004ad3fa  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad3fd  7502                   -jne 0x4ad401
    if (!cpu.flags.zf)
    {
        goto L_0x004ad401;
    }
    // 004ad3ff  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004ad401:
    // 004ad401  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ad403  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad405  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ad407  7c0e                   -jl 0x4ad417
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad417;
    }
    // 004ad409  66895320               -mov word ptr [ebx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 004ad40d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad40f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad412  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad413  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad414  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad415  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad416  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad417:
    // 004ad417  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ad419  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
L_0x004ad41c:
    // 004ad41c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad41f  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004ad422  46                     -inc esi
    (cpu.esi)++;
    // 004ad423  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad426  668b7c28fe             -mov di, word ptr [eax + ebp - 2]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */ + cpu.ebp * 1);
    // 004ad42b  42                     -inc edx
    (cpu.edx)++;
    // 004ad42c  66897922               -mov word ptr [ecx + 0x22], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(34) /* 0x22 */) = cpu.di;
    // 004ad430  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad432  7ce8                   -jl 0x4ad41c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad41c;
    }
    // 004ad434  66895320               -mov word ptr [ebx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 004ad438  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad43a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad43d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad43e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad43f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad440  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad441  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ad444(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad444  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004ad44b  66c740200000           -mov word ptr [eax + 0x20], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004ad451  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004ad457  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ad45d  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 004ad463  66c740080000           -mov word ptr [eax + 8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004ad469  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ad46c  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ad46f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ad473  c70074d24a00           -mov dword ptr [eax], 0x4ad274
    app->getMemory<x86::reg32>(cpu.eax) = 4903540 /*0x4ad274*/;
    // 004ad479  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ad47d  c70070d24a00           -mov dword ptr [eax], 0x4ad270
    app->getMemory<x86::reg32>(cpu.eax) = 4903536 /*0x4ad270*/;
    // 004ad483  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004ad488  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ad490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad490  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad491  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad492  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad493  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ad496  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ad498  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ad49c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004ad49f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ad4a1  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ad4a3  39d8                   +cmp eax, ebx
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
    // 004ad4a5  7d02                   -jge 0x4ad4a9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad4a9;
    }
    // 004ad4a7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004ad4a9:
    // 004ad4a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad4ab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad4ad  7e21                   -jle 0x4ad4d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad4d0;
    }
    // 004ad4af  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004ad4b3:
    // 004ad4b3  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad4b6  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004ad4b9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad4bc  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004ad4c0  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004ad4c3  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 004ad4c7  40                     -inc eax
    (cpu.eax)++;
    // 004ad4c8  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004ad4cc  39f8                   +cmp eax, edi
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
    // 004ad4ce  7ce3                   -jl 0x4ad4b3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad4b3;
    }
L_0x004ad4d0:
    // 004ad4d0  39e8                   +cmp eax, ebp
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
    // 004ad4d2  7d28                   -jge 0x4ad4fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad4fc;
    }
    // 004ad4d4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad4d8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004ad4df  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004ad4e1:
    // 004ad4e1  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 004ad4e4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad4e7  668931                 -mov word ptr [ecx], si
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.si;
    // 004ad4ea  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad4ed  668b73fe               -mov si, word ptr [ebx - 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */);
    // 004ad4f1  40                     -inc eax
    (cpu.eax)++;
    // 004ad4f2  668971fe               -mov word ptr [ecx - 2], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 004ad4f6  39e8                   +cmp eax, ebp
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
    // 004ad4f8  7ce7                   -jl 0x4ad4e1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad4e1;
    }
    // 004ad4fa  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ad4fc:
    // 004ad4fc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad4ff  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004ad501  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ad503  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ad506  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad507  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad508  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad509  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ad50c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad50c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad50d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad50e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad50f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad510  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004ad513  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ad515  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ad517  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad519  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ad51c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad51e  7e59                   -jle 0x4ad579
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad579;
    }
    // 004ad520  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004ad523  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004ad527  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x004ad52a:
    // 004ad52a  66837e2800             +cmp word ptr [esi + 0x28], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ad52f  7564                   -jne 0x4ad595
    if (!cpu.flags.zf)
    {
        goto L_0x004ad595;
    }
    // 004ad531  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad534  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ad537  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004ad53a  39c8                   +cmp eax, ecx
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
    // 004ad53c  0f8d74000000           -jge 0x4ad5b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad5b6;
    }
    // 004ad542  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004ad546  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ad54b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad54d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad550  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad552  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ad555  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ad55b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad55d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad55e  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ad561  e8fa410000             -call 0x4b1760
    cpu.esp -= 4;
    sub_4b1760(app, cpu);
    if (cpu.terminate) return;
    // 004ad566  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad569  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ad56c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ad56f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad572  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004ad575:
    // 004ad575  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad577  7fb1                   -jg 0x4ad52a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ad52a;
    }
L_0x004ad579:
    // 004ad579  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004ad580  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad583  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad585  0f8c63010000           -jl 0x4ad6ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad6ee;
    }
    // 004ad58b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad58d  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004ad590  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad591  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad592  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad593  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad594  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad595:
    // 004ad595  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ad599  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ad59b  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004ad59e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ad5a0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ad5a3  e8e8feffff             -call 0x4ad490
    cpu.esp -= 4;
    sub_4ad490(app, cpu);
    if (cpu.terminate) return;
    // 004ad5a8  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ad5ac  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad5ae  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ad5b0  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 004ad5b4  ebbf                   -jmp 0x4ad575
    goto L_0x004ad575;
L_0x004ad5b6:
    // 004ad5b6  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004ad5ba  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad5bd  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ad5c2  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004ad5c6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad5c8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad5cb  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad5cd  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ad5d3  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ad5d6  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004ad5d9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad5db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad5dc  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ad5df  e87c410000             -call 0x4b1760
    cpu.esp -= 4;
    sub_4b1760(app, cpu);
    if (cpu.terminate) return;
    // 004ad5e4  83461c1c               -add dword ptr [esi + 0x1c], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ad5e8  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ad5ec  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad5f0  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004ad5f5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad5f7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad5f9  668b8608010000         -mov ax, word ptr [esi + 0x108]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 004ad600  66895628               -mov word ptr [esi + 0x28], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 004ad604  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004ad608  668b860a010000         -mov ax, word ptr [esi + 0x10a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */);
    // 004ad60f  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004ad613  668b860c010000         -mov ax, word ptr [esi + 0x10c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004ad61a  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 004ad61e  668b860e010000         -mov ax, word ptr [esi + 0x10e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */);
    // 004ad625  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ad627  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004ad62b  41                     -inc ecx
    (cpu.ecx)++;
    // 004ad62c  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ad62f  66894e28               -mov word ptr [esi + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 004ad633  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ad635  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ad63a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad63d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad63f  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004ad642  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004ad645  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ad648  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ad64a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad64d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad64f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad652  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ad654  0f8488000000           -je 0x4ad6e2
    if (cpu.flags.zf)
    {
        goto L_0x004ad6e2;
    }
    // 004ad65a  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004ad65c  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004ad660  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ad665  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad667  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad66a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad66c  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ad66f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad671  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ad673  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ad676  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad677  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ad67a  e8e1400000             -call 0x4b1760
    cpu.esp -= 4;
    sub_4b1760(app, cpu);
    if (cpu.terminate) return;
    // 004ad67f  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad682  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ad685  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ad688  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ad68a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad68d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad68f  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004ad694  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 004ad698  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad69a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad69c  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004ad69f  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004ad6a2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004ad6a4  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ad6a8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ad6aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad6ac  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ad6ae  7e32                   -jle 0x4ad6e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad6e2;
    }
L_0x004ad6b0:
    // 004ad6b0  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004ad6b3  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ad6b6  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004ad6b9  66895c8e2c             -mov word ptr [esi + ecx*4 + 0x2c], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = cpu.bx;
    // 004ad6be  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004ad6c1  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ad6c4  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ad6c8  66895c8e2e             -mov word ptr [esi + ecx*4 + 0x2e], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */ + cpu.ecx * 4) = cpu.bx;
    // 004ad6cd  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad6d0  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ad6d4  42                     -inc edx
    (cpu.edx)++;
    // 004ad6d5  43                     -inc ebx
    (cpu.ebx)++;
    // 004ad6d6  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004ad6da  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 004ad6de  39ca                   +cmp edx, ecx
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
    // 004ad6e0  7cce                   -jl 0x4ad6b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad6b0;
    }
L_0x004ad6e2:
    // 004ad6e2  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004ad6e6  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ad6e9  e987feffff             -jmp 0x4ad575
    goto L_0x004ad575;
L_0x004ad6ee:
    // 004ad6ee  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004ad6f1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ad6f4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ad6f7  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad6fa  8d0c06                 -lea ecx, [esi + eax]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004ad6fd  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004ad700  6689412c               -mov word ptr [ecx + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.ax;
    // 004ad704  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004ad707  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ad70a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ad70d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad710  8d0c06                 -lea ecx, [esi + eax]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004ad713  668b4202               -mov ax, word ptr [edx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004ad717  6689412e               -mov word ptr [ecx + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(46) /* 0x2e */) = cpu.ax;
    // 004ad71b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad71e  668b4e28               -mov cx, word ptr [esi + 0x28]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ad722  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad725  41                     -inc ecx
    (cpu.ecx)++;
    // 004ad726  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ad729  47                     -inc edi
    (cpu.edi)++;
    // 004ad72a  66894e28               -mov word ptr [esi + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 004ad72e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad730  7cbc                   -jl 0x4ad6ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad6ee;
    }
    // 004ad732  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad734  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004ad737  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad738  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad739  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad73a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad73b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ad73c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad73c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad73d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad73e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad73f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad740  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ad743  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004ad745  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ad747  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ad74a  8b5026                 -mov edx, dword ptr [eax + 0x26]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004ad74d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ad750  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad752  39d5                   +cmp ebp, edx
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
    // 004ad754  7e38                   -jle 0x4ad78e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad78e;
    }
    // 004ad756  bf04000000             -mov edi, 4
    cpu.edi = 4 /*0x4*/;
    // 004ad75b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ad75d:
    // 004ad75d  8b5626                 -mov edx, dword ptr [esi + 0x26]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004ad760  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ad763  39d3                   +cmp ebx, edx
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
    // 004ad765  0f8da2000000           -jge 0x4ad80d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad80d;
    }
    // 004ad76b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad76e  668b482c               -mov cx, word ptr [eax + 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004ad772  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004ad775  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad778  668b482e               -mov cx, word ptr [eax + 0x2e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004ad77c  66894a02               -mov word ptr [edx + 2], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cx;
    // 004ad780  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad783  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad786  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ad788  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ad789  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004ad78c  ebcf                   -jmp 0x4ad75d
    goto L_0x004ad75d;
L_0x004ad78e:
    // 004ad78e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad790  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ad792  7e28                   -jle 0x4ad7bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad7bc;
    }
L_0x004ad794:
    // 004ad794  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad797  668b482c               -mov cx, word ptr [eax + 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004ad79b  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004ad79e  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad7a1  668b502e               -mov dx, word ptr [eax + 0x2e]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004ad7a5  66895102               -mov word ptr [ecx + 2], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 004ad7a9  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad7ac  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad7af  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad7b2  43                     -inc ebx
    (cpu.ebx)++;
    // 004ad7b3  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004ad7b6  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad7b8  7cda                   -jl 0x4ad794
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad794;
    }
    // 004ad7ba  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004ad7bc:
    // 004ad7bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ad7be  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ad7c0  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 004ad7c7  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004ad7cb  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004ad7cd:
    // 004ad7cd  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004ad7d0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ad7d3  39cb                   +cmp ebx, ecx
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
    // 004ad7d5  7d22                   -jge 0x4ad7f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad7f9;
    }
    // 004ad7d7  668b4a2c               -mov cx, word ptr [edx + 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004ad7db  6689482c               -mov word ptr [eax + 0x2c], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.cx;
    // 004ad7df  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad7e2  668b4a2e               -mov cx, word ptr [edx + 0x2e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 004ad7e6  6689482a               -mov word ptr [eax + 0x2a], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(42) /* 0x2a */) = cpu.cx;
    // 004ad7ea  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad7ee  83c204                 +add edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ad7f1  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ad7f2  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ad7f3  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004ad7f7  ebd4                   -jmp 0x4ad7cd
    goto L_0x004ad7cd;
L_0x004ad7f9:
    // 004ad7f9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad7fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad7ff  66894628               -mov word ptr [esi + 0x28], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ax;
    // 004ad803  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad805  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ad808  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad809  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad80a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad80b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad80c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad80d:
    // 004ad80d  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ad810  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad812  2b461c                 -sub eax, dword ptr [esi + 0x1c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 004ad815  83e81c                 -sub eax, 0x1c
    (cpu.eax) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ad818  39c5                   +cmp ebp, eax
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
    // 004ad81a  0f8de1000000           -jge 0x4ad901
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad901;
    }
    // 004ad820  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
L_0x004ad824:
    // 004ad824  837c240400             +cmp dword ptr [esp + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ad829  0f8cdb000000           -jl 0x4ad90a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad90a;
    }
L_0x004ad82f:
    // 004ad82f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad833  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004ad835  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad838  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad83a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ad83c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004ad83f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad841  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ad843  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ad848  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad84b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad84d  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ad850  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ad852  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad853  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ad856  e8053f0000             -call 0x4b1760
    cpu.esp -= 4;
    sub_4b1760(app, cpu);
    if (cpu.terminate) return;
    // 004ad85b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad85e  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad861  037c2404               -add edi, dword ptr [esp + 4]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004ad865  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ad867  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ad869  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ad86b  897e1c                 -mov dword ptr [esi + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 004ad86e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ad870  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ad872  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ad875  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ad878  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004ad87f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad881  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ad883  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ad885  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ad888:
    // 004ad888  0f8c87000000           -jl 0x4ad915
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ad915;
    }
    // 004ad88e  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad891  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 004ad895  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad897  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ad89a  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad89d  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ad8a0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad8a4  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ad8a6  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad8a8  83f81c                 +cmp eax, 0x1c
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
    // 004ad8ab  7d48                   -jge 0x4ad8f5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ad8f5;
    }
    // 004ad8ad  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004ad8b1  66898608010000         -mov word ptr [esi + 0x108], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */) = cpu.ax;
    // 004ad8b8  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ad8bc  6689860a010000         -mov word ptr [esi + 0x10a], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */) = cpu.ax;
    // 004ad8c3  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004ad8c7  6689860c010000         -mov word ptr [esi + 0x10c], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.ax;
    // 004ad8ce  668b4608               -mov ax, word ptr [esi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ad8d2  6689860e010000         -mov word ptr [esi + 0x10e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */) = cpu.ax;
    // 004ad8d9  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004ad8df  c7000cd54a00           -mov dword ptr [eax], 0x4ad50c
    app->getMemory<x86::reg32>(cpu.eax) = 4904204 /*0x4ad50c*/;
    // 004ad8e5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ad8e7  7e0c                   -jle 0x4ad8f5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ad8f5;
    }
    // 004ad8e9  8d5e10                 -lea ebx, [esi + 0x10]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad8ec  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ad8ee  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ad8f0  e817fcffff             -call 0x4ad50c
    cpu.esp -= 4;
    sub_4ad50c(app, cpu);
    if (cpu.terminate) return;
L_0x004ad8f5:
    // 004ad8f5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ad8f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad8f9  83c408                 +add esp, 8
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
    // 004ad8fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad8fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad8fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad8ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ad900  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ad901:
    // 004ad901  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ad905  e91affffff             -jmp 0x4ad824
    goto L_0x004ad824;
L_0x004ad90a:
    // 004ad90a  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004ad90c  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004ad910  e91affffff             -jmp 0x4ad82f
    goto L_0x004ad82f;
L_0x004ad915:
    // 004ad915  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad918  8d3c01                 -lea edi, [ecx + eax]
    cpu.edi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004ad91b  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004ad91e  668b3f                 -mov di, word ptr [edi]
    cpu.di = app->getMemory<x86::reg16>(cpu.edi);
    // 004ad921  6689792c               -mov word ptr [ecx + 0x2c], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.di;
    // 004ad925  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ad928  668b7c0702             -mov di, word ptr [edi + eax + 2]
    cpu.di = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 004ad92d  43                     -inc ebx
    (cpu.ebx)++;
    // 004ad92e  6689792e               -mov word ptr [ecx + 0x2e], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(46) /* 0x2e */) = cpu.di;
    // 004ad932  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004ad935  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad938  47                     -inc edi
    (cpu.edi)++;
    // 004ad939  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ad93c  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004ad93f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ad941  e942ffffff             -jmp 0x4ad888
    goto L_0x004ad888;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ad948(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad948  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004ad94f  66c740280000           -mov word ptr [eax + 0x28], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004ad955  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004ad95b  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ad961  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 004ad967  66c740080000           -mov word ptr [eax + 8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004ad96d  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ad970  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ad973  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004ad976  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ad97a  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004ad97d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ad981  899010010000           -mov dword ptr [eax + 0x110], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 004ad987  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ad98b  c7023cd74a00           -mov dword ptr [edx], 0x4ad73c
    app->getMemory<x86::reg32>(cpu.edx) = 4904764 /*0x4ad73c*/;
    // 004ad991  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ad997  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 004ad99c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4ad9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ad9a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ad9a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ad9a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ad9a3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ad9a6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ad9a8  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ad9ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ad9ad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ad9af  0f848d000000           -je 0x4ada42
    if (cpu.flags.zf)
    {
        goto L_0x004ada42;
    }
    // 004ad9b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ad9b6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ad9b8  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ad9bb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ad9bd  7e67                   -jle 0x4ada26
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ada26;
    }
    // 004ad9bf  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004ad9c2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ad9c6  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ad9c9  8d6818                 -lea ebp, [eax + 0x18]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004ad9cc  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004ad9cf  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ad9d3  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004ad9d7:
    // 004ad9d7  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ad9da  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ad9dc  756b                   -jne 0x4ada49
    if (!cpu.flags.zf)
    {
        goto L_0x004ada49;
    }
    // 004ad9de  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ad9e1  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ad9e4  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004ad9e7  39d0                   +cmp eax, edx
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
    // 004ad9e9  0f8d77000000           -jge 0x4ada66
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ada66;
    }
    // 004ad9ef  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004ad9f3  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004ad9f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ad9fa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ad9fd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ad9ff  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ada02  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ada08  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ada0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ada0b  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ada0e  e84d3d0000             -call 0x4b1760
    cpu.esp -= 4;
    sub_4b1760(app, cpu);
    if (cpu.terminate) return;
    // 004ada13  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ada16  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ada19  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ada1c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ada1f  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
L_0x004ada22:
    // 004ada22  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ada24  7fb1                   -jg 0x4ad9d7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ad9d7;
    }
L_0x004ada26:
    // 004ada26  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004ada2d  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ada30  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ada32  0f8ce5000000           -jl 0x4adb1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adb1d;
    }
    // 004ada38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ada3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004ada3b:
    // 004ada3b  83c40c                 +add esp, 0xc
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
    // 004ada3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ada3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ada40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ada41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ada42:
    // 004ada42  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ada47  ebf2                   -jmp 0x4ada3b
    goto L_0x004ada3b;
L_0x004ada49:
    // 004ada49  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ada4d  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ada51  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ada53  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ada55  e836faffff             -call 0x4ad490
    cpu.esp -= 4;
    sub_4ad490(app, cpu);
    if (cpu.terminate) return;
    // 004ada5a  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ada5d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ada5f  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ada61  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004ada64  ebbc                   -jmp 0x4ada22
    goto L_0x004ada22;
L_0x004ada66:
    // 004ada66  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ada6a  7445                   -je 0x4adab1
    if (cpu.flags.zf)
    {
        goto L_0x004adab1;
    }
    // 004ada6c  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004ada70  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004ada75  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ada77  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ada7a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ada7c  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ada7f  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ada85  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ada87  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ada88  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ada8b  e8d03c0000             -call 0x4b1760
    cpu.esp -= 4;
    sub_4b1760(app, cpu);
    if (cpu.terminate) return;
    // 004ada90  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ada93  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ada95  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ada98  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004ada9b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ada9d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ada9f  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adaa2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004adaa4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004adaa7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adaaa  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004adaac  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004adaae  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x004adab1:
    // 004adab1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004adab5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004adab7  ff15b4a14c00           -call dword ptr [0x4ca1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004adabd  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004adac0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004adac2  7434                   -je 0x4adaf8
    if (cpu.flags.zf)
    {
        goto L_0x004adaf8;
    }
    // 004adac4  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004adac7  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 004adacb  668b5302               -mov dx, word ptr [ebx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004adacf  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 004adad3  668b5304               -mov dx, word ptr [ebx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004adad7  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 004adadb  668b4306               -mov ax, word ptr [ebx + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 004adadf  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004adae3  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004adae6  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004adaed  83c008                 +add eax, 8
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
    // 004adaf0  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004adaf3  e92affffff             -jmp 0x4ada22
    goto L_0x004ada22;
L_0x004adaf8:
    // 004adaf8  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004adafa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adafc  0f8e20ffffff           -jle 0x4ada22
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ada22;
    }
L_0x004adb02:
    // 004adb02  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adb05  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 004adb0a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adb0d  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004adb10  4f                     -dec edi
    (cpu.edi)--;
    // 004adb11  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004adb14  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adb16  7fea                   -jg 0x4adb02
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004adb02;
    }
    // 004adb18  e905ffffff             -jmp 0x4ada22
    goto L_0x004ada22;
L_0x004adb1d:
    // 004adb1d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adb20  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004adb23  668b12                 -mov dx, word ptr [edx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx);
    // 004adb26  6689548624             -mov word ptr [esi + eax*4 + 0x24], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 4) = cpu.dx;
    // 004adb2b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adb2e  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004adb31  668b5202               -mov dx, word ptr [edx + 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004adb35  6689548626             -mov word ptr [esi + eax*4 + 0x26], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(38) /* 0x26 */ + cpu.eax * 4) = cpu.dx;
    // 004adb3a  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adb3d  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004adb40  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adb43  43                     -inc ebx
    (cpu.ebx)++;
    // 004adb44  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004adb47  47                     -inc edi
    (cpu.edi)++;
    // 004adb48  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004adb4b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adb4d  7cce                   -jl 0x4adb1d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adb1d;
    }
    // 004adb4f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adb51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adb52  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004adb55  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adb56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adb57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adb58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4adb5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adb5c  c7401401000000         -mov dword ptr [eax + 0x14], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004adb63  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004adb6a  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004adb71  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004adb77  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004adb7d  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 004adb83  66c740080000           -mov word ptr [eax + 8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004adb89  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004adb8c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004adb90  c700a0d94a00           -mov dword ptr [eax], 0x4ad9a0
    app->getMemory<x86::reg32>(cpu.eax) = 4905376 /*0x4ad9a0*/;
    // 004adb96  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004adb9a  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004adba0  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004adba5  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4adbb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adbb0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004adbb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4adbb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adbb4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adbb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adbb6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adbb7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adbb8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004adbba  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004adbbc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004adbbe  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004adbc1  8b7918                 -mov edi, dword ptr [ecx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004adbc4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004adbc6  39fa                   +cmp edx, edi
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
    // 004adbc8  7d64                   -jge 0x4adc2e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004adc2e;
    }
    // 004adbca  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004adbcc  8b6920                 -mov ebp, dword ptr [ecx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004adbcf  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004adbd2  39ee                   +cmp esi, ebp
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
    // 004adbd4  7f62                   -jg 0x4adc38
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004adc38;
    }
    // 004adbd6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adbd8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004adbda  7e1c                   -jle 0x4adbf8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adbf8;
    }
    // 004adbdc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004adbde:
    // 004adbde  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004adbe1  8b7a24                 -mov edi, dword ptr [edx + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004adbe4  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 004adbe6  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004adbe9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adbec  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adbef  40                     -inc eax
    (cpu.eax)++;
    // 004adbf0  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004adbf3  39f0                   +cmp eax, esi
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
    // 004adbf5  7ce7                   -jl 0x4adbde
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adbde;
    }
    // 004adbf7  90                     -nop 
    ;
L_0x004adbf8:
    // 004adbf8  8b7320                 -mov esi, dword ptr [ebx + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004adbfb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004adbfd  39f0                   +cmp eax, esi
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
    // 004adbff  7d23                   -jge 0x4adc24
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004adc24;
    }
    // 004adc01  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004adc08  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004adc0a  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004adc0c:
    // 004adc0c  d94224                 -fld dword ptr [edx + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(36) /* 0x24 */)));
    // 004adc0f  41                     -inc ecx
    (cpu.ecx)++;
    // 004adc10  40                     -inc eax
    (cpu.eax)++;
    // 004adc11  d95e24                 -fstp dword ptr [esi + 0x24]
    app->getMemory<float>(cpu.esi + x86::reg32(36) /* 0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004adc14  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adc17  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004adc1a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adc1d  39f8                   +cmp eax, edi
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
    // 004adc1f  7ceb                   -jl 0x4adc0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adc0c;
    }
    // 004adc21  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004adc24:
    // 004adc24  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adc26  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004adc29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004adc2e:
    // 004adc2e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004adc33  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc35  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adc37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004adc38:
    // 004adc38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004adc3a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004adc3c  7e1e                   -jle 0x4adc5c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adc5c;
    }
    // 004adc3e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004adc40:
    // 004adc40  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004adc43  d94024                 -fld dword ptr [eax + 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(36) /* 0x24 */)));
    // 004adc46  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adc49  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004adc4b  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004adc4e  42                     -inc edx
    (cpu.edx)++;
    // 004adc4f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adc52  8b7b20                 -mov edi, dword ptr [ebx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004adc55  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004adc58  39fa                   +cmp edx, edi
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
    // 004adc5a  7ce4                   -jl 0x4adc40
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adc40;
    }
L_0x004adc5c:
    // 004adc5c  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004adc5f  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004adc62  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004adc65  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004adc67  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004adc69  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adc6b  0f8c7e000000           -jl 0x4adcef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adcef;
    }
L_0x004adc71:
    // 004adc71  39fe                   +cmp esi, edi
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
    // 004adc73  0f8d7d000000           -jge 0x4adcf6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004adcf6;
    }
    // 004adc79  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x004adc7b:
    // 004adc7b  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004adc7e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004adc85  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004adc87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004adc89  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004adc8c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004adc8e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004adc90  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004adc95  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adc98  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adc9a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004adc9d  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004adc9f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004adca1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004adca2  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004adca5  e8463d0000             -call 0x4b19f0
    cpu.esp -= 4;
    sub_4b19f0(app, cpu);
    if (cpu.terminate) return;
    // 004adcaa  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004adcad  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004adcaf  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004adcb1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004adcb3  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004adcb6  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004adcb8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adcbb  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004adcbe  39ef                   +cmp edi, ebp
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
    // 004adcc0  7538                   -jne 0x4adcfa
    if (!cpu.flags.zf)
    {
        goto L_0x004adcfa;
    }
    // 004adcc2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004adcc4  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004adcc7  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004adcc9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004adccb  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004adccd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004adccf  7e17                   -jle 0x4adce8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adce8;
    }
L_0x004adcd1:
    // 004adcd1  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004adcd4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004adcda  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004adcdd  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adce0  4e                     -dec esi
    (cpu.esi)--;
    // 004adce1  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004adce4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004adce6  7fe9                   -jg 0x4adcd1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004adcd1;
    }
L_0x004adce8:
    // 004adce8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adcea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adceb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adcec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adced  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adcee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004adcef:
    // 004adcef  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004adcf1  e97bffffff             -jmp 0x4adc71
    goto L_0x004adc71;
L_0x004adcf6:
    // 004adcf6  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004adcf8  eb81                   -jmp 0x4adc7b
    goto L_0x004adc7b;
L_0x004adcfa:
    // 004adcfa  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004adcfc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004adcfe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004add00  7c0a                   -jl 0x4add0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004add0c;
    }
    // 004add02  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004add05  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004add07  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add0b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004add0c:
    // 004add0c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004add0e  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
L_0x004add15:
    // 004add15  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004add18  46                     -inc esi
    (cpu.esi)++;
    // 004add19  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004add1c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004add1f  41                     -inc ecx
    (cpu.ecx)++;
    // 004add20  8b6c07fc               -mov ebp, dword ptr [edi + eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004add24  896a20                 -mov dword ptr [edx + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004add27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004add29  7cea                   -jl 0x4add15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004add15;
    }
    // 004add2b  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004add2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004add30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004add34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4add38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004add38  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004add3f  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004add46  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004add4d  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004add54  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004add57  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004add5a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004add5e  c700b4db4a00           -mov dword ptr [eax], 0x4adbb4
    app->getMemory<x86::reg32>(cpu.eax) = 4905908 /*0x4adbb4*/;
    // 004add64  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004add68  c700b0db4a00           -mov dword ptr [eax], 0x4adbb0
    app->getMemory<x86::reg32>(cpu.eax) = 4905904 /*0x4adbb0*/;
    // 004add6e  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004add73  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4add80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004add80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004add81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004add82  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004add83  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004add86  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004add88  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004add8b  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004add8d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004add8f  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004add91  39d8                   +cmp eax, ebx
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
    // 004add93  7d02                   -jge 0x4add97
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004add97;
    }
    // 004add95  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004add97:
    // 004add97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004add99  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004add9b  7e13                   -jle 0x4addb0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004addb0;
    }
    // 004add9d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004adda0:
    // 004adda0  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004adda2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adda5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adda8  40                     -inc eax
    (cpu.eax)++;
    // 004adda9  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004addac  39f0                   +cmp eax, esi
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
    // 004addae  7cf0                   -jl 0x4adda0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adda0;
    }
L_0x004addb0:
    // 004addb0  39f8                   +cmp eax, edi
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
    // 004addb2  7d1c                   -jge 0x4addd0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004addd0;
    }
    // 004addb4  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004addb7  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004addbe  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004addc0:
    // 004addc0  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004addc2  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004addc5  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004addc8  40                     -inc eax
    (cpu.eax)++;
    // 004addc9  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004addcc  39f8                   +cmp eax, edi
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
    // 004addce  7cf0                   -jl 0x4addc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004addc0;
    }
L_0x004addd0:
    // 004addd0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004addd2  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 004addd5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004addd8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004addd9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004addda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adddb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4adddc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adddc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adddd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004addde  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adddf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adde0  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004adde3  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004adde5  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004adde7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004adde9  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004addec  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004addee  7e55                   -jle 0x4ade45
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ade45;
    }
    // 004addf0  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004addf3  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004addf7  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x004addfa:
    // 004addfa  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004addfd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004addff  7560                   -jne 0x4ade61
    if (!cpu.flags.zf)
    {
        goto L_0x004ade61;
    }
    // 004ade01  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ade04  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ade07  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004ade0a  39d8                   +cmp eax, ebx
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
    // 004ade0c  7d6e                   -jge 0x4ade7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ade7c;
    }
    // 004ade0e  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ade12  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ade17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ade19  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ade1c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ade1e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ade21  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ade27  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ade29  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ade2a  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ade2d  e8be3b0000             -call 0x4b19f0
    cpu.esp -= 4;
    sub_4b19f0(app, cpu);
    if (cpu.terminate) return;
    // 004ade32  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ade35  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ade38  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ade3b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ade3e  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004ade41:
    // 004ade41  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ade43  7fb5                   -jg 0x4addfa
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004addfa;
    }
L_0x004ade45:
    // 004ade45  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004ade4c  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ade4f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ade51  0f8c24010000           -jl 0x4adf7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adf7b;
    }
    // 004ade57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ade59  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004ade5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ade5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ade5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ade5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ade60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ade61:
    // 004ade61  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ade63  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ade65  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ade67  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004ade6b  e810ffffff             -call 0x4add80
    cpu.esp -= 4;
    sub_4add80(app, cpu);
    if (cpu.terminate) return;
    // 004ade70  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ade73  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ade75  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ade77  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004ade7a  ebc5                   -jmp 0x4ade41
    goto L_0x004ade41;
L_0x004ade7c:
    // 004ade7c  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ade7f  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004ade83  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ade87  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ade8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ade8e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ade91  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ade93  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ade99  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ade9c  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004ade9f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004adea1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adea2  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004adea5  e8463b0000             -call 0x4b19f0
    cpu.esp -= 4;
    sub_4b19f0(app, cpu);
    if (cpu.terminate) return;
    // 004adeaa  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004adead  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004adeb0  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004adeb3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adeb5  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004adeb8  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004adebd  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004adebf  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004adec1  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004adec4  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004adec7  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004adeca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004adecc  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004aded1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004aded4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004aded6  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004aded9  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004adedc  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004adedf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004adee1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adee4  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adee6  d98608010000           -fld dword ptr [esi + 0x108]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */)));
    // 004adeec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adeef  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004adef2  8b860c010000           -mov eax, dword ptr [esi + 0x10c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004adef8  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004adefb  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004adefe  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004adf00  746d                   -je 0x4adf6f
    if (cpu.flags.zf)
    {
        goto L_0x004adf6f;
    }
    // 004adf02  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004adf05  6bd00f                 -imul edx, eax, 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004adf08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adf0a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004adf0d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004adf0f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004adf12  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004adf14  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004adf16  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004adf18  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004adf1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adf1c  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004adf1f  e8cc3a0000             -call 0x4b19f0
    cpu.esp -= 4;
    sub_4b19f0(app, cpu);
    if (cpu.terminate) return;
    // 004adf24  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004adf27  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004adf2a  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004adf2d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adf2f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adf32  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004adf34  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 004adf38  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004adf3d  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004adf41  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004adf44  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004adf46  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004adf48  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004adf4b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004adf4d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004adf4f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004adf51  7e1c                   -jle 0x4adf6f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adf6f;
    }
    // 004adf53  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
L_0x004adf57:
    // 004adf57  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004adf5a  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004adf5c  d95c8e2c               -fstp dword ptr [esi + ecx*4 + 0x2c]
    app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004adf60  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004adf63  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adf66  41                     -inc ecx
    (cpu.ecx)++;
    // 004adf67  42                     -inc edx
    (cpu.edx)++;
    // 004adf68  894e28                 -mov dword ptr [esi + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004adf6b  39da                   +cmp edx, ebx
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
    // 004adf6d  7ce8                   -jl 0x4adf57
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adf57;
    }
L_0x004adf6f:
    // 004adf6f  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004adf73  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004adf76  e9c6feffff             -jmp 0x4ade41
    goto L_0x004ade41;
L_0x004adf7b:
    // 004adf7b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adf7e  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004adf81  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004adf83  894c862c               -mov dword ptr [esi + eax*4 + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 4) = cpu.ecx;
    // 004adf87  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adf8a  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004adf8d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adf90  43                     -inc ebx
    (cpu.ebx)++;
    // 004adf91  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004adf94  47                     -inc edi
    (cpu.edi)++;
    // 004adf95  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004adf98  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adf9a  7cdf                   -jl 0x4adf7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adf7b;
    }
    // 004adf9c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adf9e  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004adfa1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adfa2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adfa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adfa4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004adfa5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4adfa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004adfa8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004adfa9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004adfaa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004adfab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004adfac  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004adfaf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004adfb1  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004adfb5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004adfb7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004adfb9  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004adfbc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004adfbe  3b4128                 +cmp eax, dword ptr [ecx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004adfc1  7f62                   -jg 0x4ae025
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ae025;
    }
    // 004adfc3  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004adfc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004adfc9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004adfcb  7e1f                   -jle 0x4adfec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004adfec;
    }
    // 004adfcd  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004adfd1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004adfd3:
    // 004adfd3  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adfd6  8b5a2c                 -mov ebx, dword ptr [edx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 004adfd9  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 004adfdb  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004adfde  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adfe1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004adfe4  40                     -inc eax
    (cpu.eax)++;
    // 004adfe5  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004adfe8  39f8                   +cmp eax, edi
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
    // 004adfea  7ce7                   -jl 0x4adfd3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004adfd3;
    }
L_0x004adfec:
    // 004adfec  8b6e28                 -mov ebp, dword ptr [esi + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004adfef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004adff1  39e8                   +cmp eax, ebp
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
    // 004adff3  7d23                   -jge 0x4ae018
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae018;
    }
    // 004adff5  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004adffc  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004adffe  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004ae000:
    // 004ae000  d9422c                 -fld dword ptr [edx + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 004ae003  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae004  40                     -inc eax
    (cpu.eax)++;
    // 004ae005  d9592c                 -fstp dword ptr [ecx + 0x2c]
    app->getMemory<float>(cpu.ecx + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae008  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae00b  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ae00e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae011  39f8                   +cmp eax, edi
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
    // 004ae013  7ceb                   -jl 0x4ae000
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae000;
    }
    // 004ae015  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ae018:
    // 004ae018  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae01a  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004ae01d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ae020  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae021  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae022  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae023  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae024  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae025:
    // 004ae025  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004ae028  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae02a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ae02c  7e1e                   -jle 0x4ae04c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae04c;
    }
    // 004ae02e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004ae030:
    // 004ae030  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae033  d9402c                 -fld dword ptr [eax + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */)));
    // 004ae036  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae039  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae03b  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae03e  42                     -inc edx
    (cpu.edx)++;
    // 004ae03f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae042  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ae045  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004ae048  39ca                   +cmp edx, ecx
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
    // 004ae04a  7ce4                   -jl 0x4ae030
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae030;
    }
L_0x004ae04c:
    // 004ae04c  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ae050  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ae053  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae056  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae058  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ae05b  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ae05d  83e81c                 -sub eax, 0x1c
    (cpu.eax) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ae060  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004ae064  39d8                   +cmp eax, ebx
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
    // 004ae066  0f8ec7000000           -jle 0x4ae133
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae133;
    }
    // 004ae06c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
L_0x004ae06f:
    // 004ae06f  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ae073  0f8cc2000000           -jl 0x4ae13b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae13b;
    }
L_0x004ae079:
    // 004ae079  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ae07c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae07f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004ae081  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004ae088  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ae08a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ae08c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004ae08f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae091  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ae093  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae098  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae09b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae09d  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ae0a0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae0a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae0a3  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ae0a6  e845390000             -call 0x4b19f0
    cpu.esp -= 4;
    sub_4b19f0(app, cpu);
    if (cpu.terminate) return;
    // 004ae0ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae0ae  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae0b1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ae0b4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae0b6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ae0b8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ae0ba  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004ae0bd  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae0bf  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004ae0c2  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004ae0c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae0c6  8d3c9d00000000         -lea edi, [ebx*4]
    cpu.edi = x86::reg32(cpu.ebx * 4);
    // 004ae0cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae0cf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ae0d1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae0d3  90                     -nop 
    ;
L_0x004ae0d4:
    // 004ae0d4  7c6f                   -jl 0x4ae145
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae145;
    }
    // 004ae0d6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ae0d9  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ae0dd  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae0e0  894e28                 -mov dword ptr [esi + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004ae0e3  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae0e5  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae0e7  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ae0ea  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae0ed  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004ae0f1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae0f3  897e10                 -mov dword ptr [esi + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004ae0f6  83f81c                 +cmp eax, 0x1c
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
    // 004ae0f9  7d2e                   -jge 0x4ae129
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae129;
    }
    // 004ae0fb  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004ae0fe  8b8610010000           -mov eax, dword ptr [esi + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(272) /* 0x110 */);
    // 004ae104  d99e08010000           -fstp dword ptr [esi + 0x108]
    app->getMemory<float>(cpu.esi + x86::reg32(264) /* 0x108 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae10a  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ae10d  89960c010000           -mov dword ptr [esi + 0x10c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(268) /* 0x10c */) = cpu.edx;
    // 004ae113  c700dcdd4a00           -mov dword ptr [eax], 0x4adddc
    app->getMemory<x86::reg32>(cpu.eax) = 4906460 /*0x4adddc*/;
    // 004ae119  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ae11b  7e0c                   -jle 0x4ae129
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae129;
    }
    // 004ae11d  8d5e10                 -lea ebx, [esi + 0x10]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae120  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ae122  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ae124  e8b3fcffff             -call 0x4adddc
    cpu.esp -= 4;
    sub_4adddc(app, cpu);
    if (cpu.terminate) return;
L_0x004ae129:
    // 004ae129  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae12b  83c40c                 +add esp, 0xc
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
    // 004ae12e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae12f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae130  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae131  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae132  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae133:
    // 004ae133  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ae136  e934ffffff             -jmp 0x4ae06f
    goto L_0x004ae06f;
L_0x004ae13b:
    // 004ae13b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ae13d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ae140  e934ffffff             -jmp 0x4ae079
    goto L_0x004ae079;
L_0x004ae145:
    // 004ae145  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae148  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae14a  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae14b  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004ae14f  41                     -inc ecx
    (cpu.ecx)++;
    // 004ae150  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ae154  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae157  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004ae15a  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004ae15d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae160  d95f2c                 -fstp dword ptr [edi + 0x2c]
    app->getMemory<float>(cpu.edi + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae163  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ae165  e96affffff             -jmp 0x4ae0d4
    goto L_0x004ae0d4;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ae16c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae16c  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004ae173  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004ae17a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ae181  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004ae188  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ae18b  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ae18e  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004ae191  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ae195  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004ae198  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ae19c  899010010000           -mov dword ptr [eax + 0x110], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(272) /* 0x110 */) = cpu.edx;
    // 004ae1a2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ae1a6  c702a8df4a00           -mov dword ptr [edx], 0x4adfa8
    app->getMemory<x86::reg32>(cpu.edx) = 4906920 /*0x4adfa8*/;
    // 004ae1ac  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ae1b2  b814010000             -mov eax, 0x114
    cpu.eax = 276 /*0x114*/;
    // 004ae1b7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ae1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae1c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae1c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae1c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae1c3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ae1c6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ae1c8  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004ae1cb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ae1cd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ae1cf  0f84b4000000           -je 0x4ae289
    if (cpu.flags.zf)
    {
        goto L_0x004ae289;
    }
    // 004ae1d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ae1d6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ae1d8  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ae1db  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae1dd  0f8e8a000000           -jle 0x4ae26d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae26d;
    }
    // 004ae1e3  8d6810                 -lea ebp, [eax + 0x10]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004ae1e6  8d5024                 -lea edx, [eax + 0x24]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ae1e9  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004ae1ed  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004ae1f0  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004ae1f3  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ae1f7  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004ae1fb:
    // 004ae1fb  8b5e20                 -mov ebx, dword ptr [esi + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ae1fe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ae200  0f858f000000           -jne 0x4ae295
    if (!cpu.flags.zf)
    {
        goto L_0x004ae295;
    }
    // 004ae206  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae209  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae20c  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004ae20f  39d0                   +cmp eax, edx
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
    // 004ae211  0f8d99000000           -jge 0x4ae2b0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae2b0;
    }
    // 004ae217  2b561c                 -sub edx, dword ptr [esi + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
    // 004ae21a  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae21f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae221  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae224  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae226  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ae228  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004ae22b  39df                   +cmp edi, ebx
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
    // 004ae22d  7d0d                   -jge 0x4ae23c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae23c;
    }
    // 004ae22f  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 004ae232  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae234  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae237  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae239  6bd81c                 -imul ebx, eax, 0x1c
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(28 /*0x1c*/)));
L_0x004ae23c:
    // 004ae23c  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ae240  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae245  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae247  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae24a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae24c  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ae24f  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 004ae251  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae253  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae254  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ae257  e894370000             -call 0x4b19f0
    cpu.esp -= 4;
    sub_4b19f0(app, cpu);
    if (cpu.terminate) return;
    // 004ae25c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae25f  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae261  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae263  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae266  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
L_0x004ae269:
    // 004ae269  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae26b  7f8e                   -jg 0x4ae1fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ae1fb;
    }
L_0x004ae26d:
    // 004ae26d  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004ae274  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae277  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae279  0f8cd7000000           -jl 0x4ae356
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae356;
    }
    // 004ae27f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae281  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae282  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ae285  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae286  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae287  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae288  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae289:
    // 004ae289  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ae28e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ae291  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae292  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae293  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae294  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae295:
    // 004ae295  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ae299  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ae29b  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004ae29d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ae29f  e8dcfaffff             -call 0x4add80
    cpu.esp -= 4;
    sub_4add80(app, cpu);
    if (cpu.terminate) return;
    // 004ae2a4  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ae2a7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae2a9  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae2ab  894e20                 -mov dword ptr [esi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004ae2ae  ebb9                   -jmp 0x4ae269
    goto L_0x004ae269;
L_0x004ae2b0:
    // 004ae2b0  837e1401               +cmp dword ptr [esi + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ae2b4  744e                   -je 0x4ae304
    if (cpu.flags.zf)
    {
        goto L_0x004ae304;
    }
    // 004ae2b6  3b561c                 +cmp edx, dword ptr [esi + 0x1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ae2b9  7e49                   -jle 0x4ae304
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae304;
    }
    // 004ae2bb  6b561c0f               -imul edx, dword ptr [esi + 0x1c], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004ae2bf  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae2c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae2c6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae2c9  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae2cb  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ae2ce  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ae2d4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae2d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae2d7  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ae2da  e811370000             -call 0x4b19f0
    cpu.esp -= 4;
    sub_4b19f0(app, cpu);
    if (cpu.terminate) return;
    // 004ae2df  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae2e2  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004ae2e7  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ae2ea  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae2ed  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ae2f0  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae2f2  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae2f5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae2f7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ae2fa  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae2fd  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae2ff  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae301  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x004ae304:
    // 004ae304  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ae308  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ae30c  ff15b4a14c00           -call dword ptr [0x4ca1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ae312  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ae315  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ae317  751d                   -jne 0x4ae336
    if (!cpu.flags.zf)
    {
        goto L_0x004ae336;
    }
L_0x004ae319:
    // 004ae319  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae31b  0f8e48ffffff           -jle 0x4ae269
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae269;
    }
    // 004ae321  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae324  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ae32a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae32d  83c004                 +add eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae330  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ae331  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ae334  ebe3                   -jmp 0x4ae319
    goto L_0x004ae319;
L_0x004ae336:
    // 004ae336  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 004ae338  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004ae33b  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae33e  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 004ae341  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004ae348  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae34b  d95e08                 +fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae34e  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ae351  e913ffffff             -jmp 0x4ae269
    goto L_0x004ae269;
L_0x004ae356:
    // 004ae356  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae359  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ae35c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ae35e  894c8624               -mov dword ptr [esi + eax*4 + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */ + cpu.eax * 4) = cpu.ecx;
    // 004ae362  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae365  8b6e20                 -mov ebp, dword ptr [esi + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004ae368  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae36b  45                     -inc ebp
    (cpu.ebp)++;
    // 004ae36c  895e10                 -mov dword ptr [esi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004ae36f  47                     -inc edi
    (cpu.edi)++;
    // 004ae370  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 004ae373  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae375  7cdf                   -jl 0x4ae356
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae356;
    }
    // 004ae377  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae379  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae37a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ae37d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae37e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae37f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae380  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4ae384(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae384  c7401401000000         -mov dword ptr [eax + 0x14], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004ae38b  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004ae392  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004ae399  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ae3a0  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004ae3a7  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ae3aa  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ae3ae  c700c0e14a00           -mov dword ptr [eax], 0x4ae1c0
    app->getMemory<x86::reg32>(cpu.eax) = 4907456 /*0x4ae1c0*/;
    // 004ae3b4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ae3b8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ae3be  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004ae3c3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ae3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae3d0  8b4024                 -mov eax, dword ptr [eax + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004ae3d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ae3d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae3d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ae3d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae3d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae3d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae3d8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ae3da  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004ae3dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ae3de  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 004ae3e1  8b7920                 -mov edi, dword ptr [ecx + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004ae3e4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ae3e6  39fa                   +cmp edx, edi
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
    // 004ae3e8  0f8d68000000           -jge 0x4ae456
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae456;
    }
    // 004ae3ee  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ae3f0  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ae3f3  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004ae3f6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004ae3f8  39c6                   +cmp esi, eax
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
    // 004ae3fa  7f64                   -jg 0x4ae460
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ae460;
    }
    // 004ae3fc  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ae3fe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae400  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ae402  7e1c                   -jle 0x4ae420
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae420;
    }
    // 004ae404  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004ae406:
    // 004ae406  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ae409  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004ae40c  8939                   -mov dword ptr [ecx], edi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edi;
    // 004ae40e  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ae411  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae414  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae417  42                     -inc edx
    (cpu.edx)++;
    // 004ae418  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004ae41b  39f2                   +cmp edx, esi
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
    // 004ae41d  7ce7                   -jl 0x4ae406
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae406;
    }
    // 004ae41f  90                     -nop 
    ;
L_0x004ae420:
    // 004ae420  8b7328                 -mov esi, dword ptr [ebx + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004ae423  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae425  39f2                   +cmp edx, esi
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
    // 004ae427  7d23                   -jge 0x4ae44c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae44c;
    }
    // 004ae429  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 004ae430  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ae432  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ae434:
    // 004ae434  d9462c                 -fld dword ptr [esi + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(44) /* 0x2c */)));
    // 004ae437  41                     -inc ecx
    (cpu.ecx)++;
    // 004ae438  42                     -inc edx
    (cpu.edx)++;
    // 004ae439  d9582c                 -fstp dword ptr [eax + 0x2c]
    app->getMemory<float>(cpu.eax + x86::reg32(44) /* 0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae43c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae43f  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004ae442  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae445  39fa                   +cmp edx, edi
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
    // 004ae447  7ceb                   -jl 0x4ae434
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae434;
    }
    // 004ae449  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ae44c:
    // 004ae44c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae44e  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004ae451  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae452  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae453  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae454  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae455  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae456:
    // 004ae456  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004ae45b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae45c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae45d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae45e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae45f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae460:
    // 004ae460  8b6928                 -mov ebp, dword ptr [ecx + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004ae463  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae465  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ae467  7e1f                   -jle 0x4ae488
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae488;
    }
    // 004ae469  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004ae46b:
    // 004ae46b  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ae46e  d9422c                 -fld dword ptr [edx + 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(44) /* 0x2c */)));
    // 004ae471  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae474  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae476  8b4b18                 -mov ecx, dword ptr [ebx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ae479  40                     -inc eax
    (cpu.eax)++;
    // 004ae47a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae47d  8b7b28                 -mov edi, dword ptr [ebx + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004ae480  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004ae483  39f8                   +cmp eax, edi
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
    // 004ae485  7ce4                   -jl 0x4ae46b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae46b;
    }
    // 004ae487  90                     -nop 
    ;
L_0x004ae488:
    // 004ae488  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 004ae48b  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004ae48d  8b6b20                 -mov ebp, dword ptr [ebx + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */);
    // 004ae490  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae492  2b6b24                 -sub ebp, dword ptr [ebx + 0x24]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */)));
    // 004ae495  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ae497  0f8c7a000000           -jl 0x4ae517
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae517;
    }
L_0x004ae49d:
    // 004ae49d  39ee                   +cmp esi, ebp
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
    // 004ae49f  0f8d76000000           -jge 0x4ae51b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae51b;
    }
    // 004ae4a5  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004ae4a7:
    // 004ae4a7  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004ae4aa  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae4ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ae4ae  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004ae4b1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae4b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ae4b5  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae4ba  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae4bd  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae4bf  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004ae4c2  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004ae4c4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae4c6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004ae4c7  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ae4ca  e809360000             -call 0x4b1ad8
    cpu.esp -= 4;
    sub_4b1ad8(app, cpu);
    if (cpu.terminate) return;
    // 004ae4cf  8b5324                 -mov edx, dword ptr [ebx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004ae4d2  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ae4d4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ae4d6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ae4d8  895324                 -mov dword ptr [ebx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004ae4db  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae4dd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae4e0  894b24                 -mov dword ptr [ebx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004ae4e3  39fd                   +cmp ebp, edi
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
    // 004ae4e5  7538                   -jne 0x4ae51f
    if (!cpu.flags.zf)
    {
        goto L_0x004ae51f;
    }
    // 004ae4e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ae4e9  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ae4eb  2b4320                 -sub eax, dword ptr [ebx + 0x20]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */)));
    // 004ae4ee  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae4f0  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ae4f2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ae4f4  7e1a                   -jle 0x4ae510
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae510;
    }
L_0x004ae4f6:
    // 004ae4f6  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ae4f9  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004ae4ff  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ae502  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae505  4e                     -dec esi
    (cpu.esi)--;
    // 004ae506  896b18                 -mov dword ptr [ebx + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004ae509  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ae50b  7fe9                   -jg 0x4ae4f6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ae4f6;
    }
    // 004ae50d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ae510:
    // 004ae510  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae512  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae513  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae514  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae515  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae516  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae517:
    // 004ae517  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004ae519  eb82                   -jmp 0x4ae49d
    goto L_0x004ae49d;
L_0x004ae51b:
    // 004ae51b  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ae51d  eb88                   -jmp 0x4ae4a7
    goto L_0x004ae4a7;
L_0x004ae51f:
    // 004ae51f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae524  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ae526  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ae528  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae52b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae52d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004ae52f  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae531  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004ae534  83fee4                 +cmp esi, -0x1c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-28 /*-0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ae537  7502                   -jne 0x4ae53b
    if (!cpu.flags.zf)
    {
        goto L_0x004ae53b;
    }
    // 004ae539  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004ae53b:
    // 004ae53b  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ae53d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ae53f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ae541  7c0a                   -jl 0x4ae54d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae54d;
    }
    // 004ae543  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004ae546  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae548  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae549  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae54a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae54b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae54c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae54d:
    // 004ae54d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ae54f  8d14b500000000         -lea edx, [esi*4]
    cpu.edx = x86::reg32(cpu.esi * 4);
L_0x004ae556:
    // 004ae556  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae559  46                     -inc esi
    (cpu.esi)++;
    // 004ae55a  8b7b18                 -mov edi, dword ptr [ebx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004ae55d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae560  41                     -inc ecx
    (cpu.ecx)++;
    // 004ae561  8b6c3afc               -mov ebp, dword ptr [edx + edi - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */ + cpu.edi * 1);
    // 004ae565  896828                 -mov dword ptr [eax + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 004ae568  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ae56a  7cea                   -jl 0x4ae556
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae556;
    }
    // 004ae56c  894b28                 -mov dword ptr [ebx + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004ae56f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae571  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae572  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae573  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae574  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae575  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ae578(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae578  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004ae57f  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004ae586  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004ae58d  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004ae594  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004ae59b  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004ae5a2  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ae5a5  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004ae5a8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ae5ac  c700d4e34a00           -mov dword ptr [eax], 0x4ae3d4
    app->getMemory<x86::reg32>(cpu.eax) = 4907988 /*0x4ae3d4*/;
    // 004ae5b2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ae5b6  c700d0e34a00           -mov dword ptr [eax], 0x4ae3d0
    app->getMemory<x86::reg32>(cpu.eax) = 4907984 /*0x4ae3d0*/;
    // 004ae5bc  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 004ae5c1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ae5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae5d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae5d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae5d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae5d3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae5d6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ae5d8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ae5db  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004ae5dd  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ae5df  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ae5e1  39d8                   +cmp eax, ebx
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
    // 004ae5e3  7d02                   -jge 0x4ae5e7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae5e7;
    }
    // 004ae5e5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004ae5e7:
    // 004ae5e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae5e9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae5eb  7e1f                   -jle 0x4ae60c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae60c;
    }
    // 004ae5ed  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004ae5f0:
    // 004ae5f0  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004ae5f2  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae5f5  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ae5f8  40                     -inc eax
    (cpu.eax)++;
    // 004ae5f9  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae5fc  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae5ff  8b59fc                 -mov ebx, dword ptr [ecx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 004ae602  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004ae605  39f8                   +cmp eax, edi
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
    // 004ae607  7ce7                   -jl 0x4ae5f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae5f0;
    }
    // 004ae609  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ae60c:
    // 004ae60c  39f0                   +cmp eax, esi
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
    // 004ae60e  7d24                   -jge 0x4ae634
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae634;
    }
    // 004ae610  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ae613  8d1cc500000000         -lea ebx, [eax*8]
    cpu.ebx = x86::reg32(cpu.eax * 8);
    // 004ae61a  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004ae61c:
    // 004ae61c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004ae61e  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ae621  40                     -inc eax
    (cpu.eax)++;
    // 004ae622  d919                   -fstp dword ptr [ecx]
    app->getMemory<float>(cpu.ecx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae624  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ae627  d943fc                 -fld dword ptr [ebx - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */)));
    // 004ae62a  d959fc                 -fstp dword ptr [ecx - 4]
    app->getMemory<float>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae62d  39f0                   +cmp eax, esi
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
    // 004ae62f  7ceb                   -jl 0x4ae61c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae61c;
    }
    // 004ae631  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ae634:
    // 004ae634  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004ae636  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
    // 004ae639  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae63c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae63d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae63e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae63f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ae640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae640  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ae641  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae642  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae643  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae644  81ecec000000           -sub esp, 0xec
    (cpu.esp) -= x86::reg32(x86::sreg32(236 /*0xec*/));
    // 004ae64a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004ae64c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ae64e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ae650  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004ae653  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae655  7e5c                   -jle 0x4ae6b3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae6b3;
    }
    // 004ae657  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004ae65a  899424e4000000         -mov dword ptr [esp + 0xe4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */) = cpu.edx;
    // 004ae661  8d6834                 -lea ebp, [eax + 0x34]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(52) /* 0x34 */);
L_0x004ae664:
    // 004ae664  66837e3000             +cmp word ptr [esi + 0x30], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004ae669  756a                   -jne 0x4ae6d5
    if (!cpu.flags.zf)
    {
        goto L_0x004ae6d5;
    }
    // 004ae66b  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ae66e  8b4e2c                 -mov ecx, dword ptr [esi + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004ae671  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004ae674  39c8                   +cmp eax, ecx
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
    // 004ae676  0f8d7d000000           -jge 0x4ae6f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae6f9;
    }
    // 004ae67c  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004ae680  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae685  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae687  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae68a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae68c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae68f  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ae695  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae697  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae698  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ae69b  e838340000             -call 0x4b1ad8
    cpu.esp -= 4;
    sub_4b1ad8(app, cpu);
    if (cpu.terminate) return;
    // 004ae6a0  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ae6a3  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ae6a6  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ae6a9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae6ac  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004ae6af:
    // 004ae6af  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae6b1  7fb1                   -jg 0x4ae664
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ae664;
    }
L_0x004ae6b3:
    // 004ae6b3  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004ae6ba  014618                 -add dword ptr [esi + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae6bd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ae6c0:
    // 004ae6c0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae6c2  0f8c6c010000           -jl 0x4ae834
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae834;
    }
    // 004ae6c8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae6ca  81c4ec000000           -add esp, 0xec
    (cpu.esp) += x86::reg32(x86::sreg32(236 /*0xec*/));
    // 004ae6d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae6d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae6d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae6d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae6d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae6d5:
    // 004ae6d5  8b8c24e4000000         -mov ecx, dword ptr [esp + 0xe4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 004ae6dc  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004ae6de  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004ae6e1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ae6e3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ae6e6  e8e5feffff             -call 0x4ae5d0
    cpu.esp -= 4;
    sub_4ae5d0(app, cpu);
    if (cpu.terminate) return;
    // 004ae6eb  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004ae6ef  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae6f1  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae6f3  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004ae6f7  ebb6                   -jmp 0x4ae6af
    goto L_0x004ae6af;
L_0x004ae6f9:
    // 004ae6f9  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004ae6fd  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae700  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae705  898424e0000000         -mov dword ptr [esp + 0xe0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 004ae70c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae70e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae711  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae713  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004ae719  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae71c  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004ae71f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae721  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae722  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ae725  e8ae330000             -call 0x4b1ad8
    cpu.esp -= 4;
    sub_4b1ad8(app, cpu);
    if (cpu.terminate) return;
    // 004ae72a  8346241c               -add dword ptr [esi + 0x24], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ae72e  668b5e2c               -mov bx, word ptr [esi + 0x2c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004ae732  668b4624               -mov ax, word ptr [esi + 0x24]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ae736  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004ae73b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae73d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae73f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ae741  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ae744  66895630               -mov word ptr [esi + 0x30], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.dx;
    // 004ae748  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ae74a  41                     -inc ecx
    (cpu.ecx)++;
    // 004ae74b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae74e  66894e30               -mov word ptr [esi + 0x30], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 004ae752  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae757  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae759  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004ae75c  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004ae75f  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ae762  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ae764  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae767  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae769  d986ec010000           -fld dword ptr [esi + 0x1ec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */)));
    // 004ae76f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae772  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae775  8b86f0010000           -mov eax, dword ptr [esi + 0x1f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */);
    // 004ae77b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ae77e  8b86f4010000           -mov eax, dword ptr [esi + 0x1f4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */);
    // 004ae784  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ae787  8b86f8010000           -mov eax, dword ptr [esi + 0x1f8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */);
    // 004ae78d  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ae790  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ae792  0f848d000000           -je 0x4ae825
    if (cpu.flags.zf)
    {
        goto L_0x004ae825;
    }
    // 004ae798  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004ae79a  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004ae79e  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae7a3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae7a5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae7a8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae7aa  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae7ad  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae7af  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ae7b1  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ae7b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae7b5  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ae7b8  e81b330000             -call 0x4b1ad8
    cpu.esp -= 4;
    sub_4b1ad8(app, cpu);
    if (cpu.terminate) return;
    // 004ae7bd  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ae7c0  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ae7c3  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ae7c6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ae7c8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae7cb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae7cd  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004ae7d2  898424e8000000         -mov dword ptr [esp + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 004ae7d9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae7db  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004ae7de  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae7e0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004ae7e2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004ae7e5  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 004ae7ec  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ae7ee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae7f0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ae7f2  7e31                   -jle 0x4ae825
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae825;
    }
L_0x004ae7f4:
    // 004ae7f4  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004ae7f7  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ae7fa  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ae7fc  895cce34               -mov dword ptr [esi + ecx*8 + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.ecx * 8) = cpu.ebx;
    // 004ae800  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004ae803  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ae806  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ae809  8b58fc                 -mov ebx, dword ptr [eax - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004ae80c  895cce38               -mov dword ptr [esi + ecx*8 + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.ecx * 8) = cpu.ebx;
    // 004ae810  668b5e30               -mov bx, word ptr [esi + 0x30]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004ae814  42                     -inc edx
    (cpu.edx)++;
    // 004ae815  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae816  8b8c24e8000000         -mov ecx, dword ptr [esp + 0xe8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(232) /* 0xe8 */);
    // 004ae81d  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004ae821  39ca                   +cmp edx, ecx
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
    // 004ae823  7ccf                   -jl 0x4ae7f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae7f4;
    }
L_0x004ae825:
    // 004ae825  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 004ae82c  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ae82f  e97bfeffff             -jmp 0x4ae6af
    goto L_0x004ae6af;
L_0x004ae834:
    // 004ae834  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004ae837  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae83a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ae83d  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ae83f  894cd634               -mov dword ptr [esi + edx*8 + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */ + cpu.edx * 8) = cpu.ecx;
    // 004ae843  8b462e                 -mov eax, dword ptr [esi + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004ae846  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae849  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ae84c  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ae84f  894cc638               -mov dword ptr [esi + eax*8 + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */ + cpu.eax * 8) = cpu.ecx;
    // 004ae853  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae856  668b4e30               -mov cx, word ptr [esi + 0x30]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004ae85a  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae85d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ae85e  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004ae861  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ae862  66894e30               -mov word ptr [esi + 0x30], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.cx;
    // 004ae866  e955feffff             -jmp 0x4ae6c0
    goto L_0x004ae6c0;
}

/* align: skip 0x90 */
void Application::sub_4ae86c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ae86c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ae86d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae86e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ae86f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ae870  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ae873  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004ae876  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004ae878  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004ae87b  8b502e                 -mov edx, dword ptr [eax + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004ae87e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ae881  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ae884  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ae886  39ca                   +cmp edx, ecx
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
    // 004ae888  7d34                   -jge 0x4ae8be
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae8be;
    }
    // 004ae88a  bf08000000             -mov edi, 8
    cpu.edi = 8 /*0x8*/;
    // 004ae88f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004ae891:
    // 004ae891  8b562e                 -mov edx, dword ptr [esi + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004ae894  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ae897  39d3                   +cmp ebx, edx
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
    // 004ae899  0f8d8a000000           -jge 0x4ae929
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae929;
    }
    // 004ae89f  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae8a2  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004ae8a5  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ae8a7  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae8aa  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004ae8ad  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004ae8b0  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae8b3  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ae8b6  01fd                   +add ebp, edi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ae8b8  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ae8b9  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004ae8bc  ebd3                   -jmp 0x4ae891
    goto L_0x004ae891;
L_0x004ae8be:
    // 004ae8be  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae8c0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ae8c2  7e28                   -jle 0x4ae8ec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae8ec;
    }
    // 004ae8c4  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
L_0x004ae8c7:
    // 004ae8c7  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae8ca  8b4834                 -mov ecx, dword ptr [eax + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004ae8cd  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004ae8cf  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae8d2  8b4838                 -mov ecx, dword ptr [eax + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004ae8d5  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004ae8d8  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae8db  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ae8de  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ae8e1  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae8e2  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004ae8e5  39eb                   +cmp ebx, ebp
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ae8e7  7cde                   -jl 0x4ae8c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ae8c7;
    }
    // 004ae8e9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004ae8ec:
    // 004ae8ec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ae8ee  8d14dd00000000         -lea edx, [ebx*8]
    cpu.edx = x86::reg32(cpu.ebx * 8);
    // 004ae8f5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004ae8f7  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004ae8f9:
    // 004ae8f9  8b4e2e                 -mov ecx, dword ptr [esi + 0x2e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004ae8fc  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ae8ff  39cb                   +cmp ebx, ecx
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
    // 004ae901  7d16                   -jge 0x4ae919
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ae919;
    }
    // 004ae903  d94234                 -fld dword ptr [edx + 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(52) /* 0x34 */)));
    // 004ae906  47                     -inc edi
    (cpu.edi)++;
    // 004ae907  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ae90a  43                     -inc ebx
    (cpu.ebx)++;
    // 004ae90b  d95834                 -fstp dword ptr [eax + 0x34]
    app->getMemory<float>(cpu.eax + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae90e  83c008                 +add eax, 8
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
    // 004ae911  8b4a30                 -mov ecx, dword ptr [edx + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004ae914  894830                 -mov dword ptr [eax + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 004ae917  ebe0                   -jmp 0x4ae8f9
    goto L_0x004ae8f9;
L_0x004ae919:
    // 004ae919  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae91b  66897e30               -mov word ptr [esi + 0x30], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.di;
    // 004ae91f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ae921  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004ae924  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae925  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae926  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae927  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ae928  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004ae929:
    // 004ae929  8b7e28                 -mov edi, dword ptr [esi + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ae92c  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ae92f  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004ae932  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae934  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae936  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ae939  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004ae93c  39ef                   +cmp edi, ebp
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
    // 004ae93e  7e02                   -jle 0x4ae942
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ae942;
    }
    // 004ae940  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x004ae942:
    // 004ae942  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004ae944  0f8cc8000000           -jl 0x4aea12
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aea12;
    }
L_0x004ae94a:
    // 004ae94a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ae94d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae94f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ae951  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004ae954  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae956  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ae958  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004ae95d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ae960  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ae962  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004ae965  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004ae967  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ae969  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ae96a  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ae96d  e866310000             -call 0x4b1ad8
    cpu.esp -= 4;
    sub_4b1ad8(app, cpu);
    if (cpu.terminate) return;
    // 004ae972  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004ae975  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ae978  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ae97a  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ae97c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae97e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ae980  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004ae983  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ae985  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ae987  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004ae98a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ae98e  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 004ae995  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ae997  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ae999  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ae99b  90                     -nop 
    ;
L_0x004ae99c:
    // 004ae99c  0f8c77000000           -jl 0x4aea19
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aea19;
    }
    // 004ae9a2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ae9a5  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae9a8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ae9aa  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae9ac  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ae9af  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004ae9b2  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004ae9b5  66895e30               -mov word ptr [esi + 0x30], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.bx;
    // 004ae9b9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ae9bb  896e18                 -mov dword ptr [esi + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 004ae9be  83f81c                 +cmp eax, 0x1c
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
    // 004ae9c1  7d43                   -jge 0x4aea06
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aea06;
    }
    // 004ae9c3  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004ae9c6  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ae9c9  8b86fc010000           -mov eax, dword ptr [esi + 0x1fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(508) /* 0x1fc */);
    // 004ae9cf  d99eec010000           -fstp dword ptr [esi + 0x1ec]
    app->getMemory<float>(cpu.esi + x86::reg32(492) /* 0x1ec */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004ae9d5  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ae9d8  8996f0010000           -mov dword ptr [esi + 0x1f0], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(496) /* 0x1f0 */) = cpu.edx;
    // 004ae9de  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004ae9e1  8996f4010000           -mov dword ptr [esi + 0x1f4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(500) /* 0x1f4 */) = cpu.edx;
    // 004ae9e7  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004ae9ea  8996f8010000           -mov dword ptr [esi + 0x1f8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(504) /* 0x1f8 */) = cpu.edx;
    // 004ae9f0  c70040e64a00           -mov dword ptr [eax], 0x4ae640
    app->getMemory<x86::reg32>(cpu.eax) = 4908608 /*0x4ae640*/;
    // 004ae9f6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004ae9f8  7e0c                   -jle 0x4aea06
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aea06;
    }
    // 004ae9fa  8d5e18                 -lea ebx, [esi + 0x18]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004ae9fd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004ae9ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aea01  e83afcffff             -call 0x4ae640
    cpu.esp -= 4;
    sub_4ae640(app, cpu);
    if (cpu.terminate) return;
L_0x004aea06:
    // 004aea06  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aea08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aea0a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aea0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aea0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aea0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aea10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aea11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aea12:
    // 004aea12  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004aea14  e931ffffff             -jmp 0x4ae94a
    goto L_0x004ae94a;
L_0x004aea19:
    // 004aea19  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004aea1c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aea1e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004aea22  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aea26  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004aea29  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004aea2c  d95934                 -fstp dword ptr [ecx + 0x34]
    app->getMemory<float>(cpu.ecx + x86::reg32(52) /* 0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aea2f  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004aea32  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aea34  43                     -inc ebx
    (cpu.ebx)++;
    // 004aea35  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aea38  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004aea3b  d95938                 -fstp dword ptr [ecx + 0x38]
    app->getMemory<float>(cpu.ecx + x86::reg32(56) /* 0x38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aea3e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aea42  41                     -inc ecx
    (cpu.ecx)++;
    // 004aea43  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aea46  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004aea4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aea4c  e94bffffff             -jmp 0x4ae99c
    goto L_0x004ae99c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4aea54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aea54  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004aea5b  66c740300000           -mov word ptr [eax + 0x30], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 004aea61  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004aea68  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004aea6f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004aea76  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004aea7d  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004aea80  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004aea83  894828                 -mov dword ptr [eax + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 004aea86  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aea8a  89502c                 -mov dword ptr [eax + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004aea8d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aea91  8990fc010000           -mov dword ptr [eax + 0x1fc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(508) /* 0x1fc */) = cpu.edx;
    // 004aea97  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aea9b  c7026ce84a00           -mov dword ptr [edx], 0x4ae86c
    app->getMemory<x86::reg32>(cpu.edx) = 4909164 /*0x4ae86c*/;
    // 004aeaa1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004aeaa7  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 004aeaac  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4aeab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aeab0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aeab1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aeab2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aeab3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aeab6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004aeab8  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004aeabb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aeabd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aeabf  0f848d000000           -je 0x4aeb52
    if (cpu.flags.zf)
    {
        goto L_0x004aeb52;
    }
    // 004aeac5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aeac6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aeac8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004aeacb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aeacd  7e67                   -jle 0x4aeb36
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aeb36;
    }
    // 004aeacf  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004aead2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004aead6  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004aead9  8d6820                 -lea ebp, [eax + 0x20]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004aeadc  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004aeadf  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004aeae3  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004aeae7:
    // 004aeae7  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004aeaea  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aeaec  756b                   -jne 0x4aeb59
    if (!cpu.flags.zf)
    {
        goto L_0x004aeb59;
    }
    // 004aeaee  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004aeaf1  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004aeaf4  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004aeaf7  39d0                   +cmp eax, edx
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
    // 004aeaf9  0f8d77000000           -jge 0x4aeb76
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aeb76;
    }
    // 004aeaff  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004aeb03  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004aeb08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aeb0a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004aeb0d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004aeb0f  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004aeb12  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004aeb18  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aeb1a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aeb1b  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004aeb1e  e8b52f0000             -call 0x4b1ad8
    cpu.esp -= 4;
    sub_4b1ad8(app, cpu);
    if (cpu.terminate) return;
    // 004aeb23  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004aeb26  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004aeb29  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004aeb2c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aeb2f  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
L_0x004aeb32:
    // 004aeb32  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aeb34  7fb1                   -jg 0x4aeae7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aeae7;
    }
L_0x004aeb36:
    // 004aeb36  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004aeb3d  014618                 -add dword ptr [esi + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aeb40  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aeb42  0f8ce0000000           -jl 0x4aec28
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aec28;
    }
    // 004aeb48  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aeb4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004aeb4b:
    // 004aeb4b  83c40c                 +add esp, 0xc
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
    // 004aeb4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aeb51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aeb52:
    // 004aeb52  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004aeb57  ebf2                   -jmp 0x4aeb4b
    goto L_0x004aeb4b;
L_0x004aeb59:
    // 004aeb59  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aeb5d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aeb61  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aeb63  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004aeb65  e866faffff             -call 0x4ae5d0
    cpu.esp -= 4;
    sub_4ae5d0(app, cpu);
    if (cpu.terminate) return;
    // 004aeb6a  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004aeb6d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aeb6f  29c7                   +sub edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aeb71  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004aeb74  ebbc                   -jmp 0x4aeb32
    goto L_0x004aeb32;
L_0x004aeb76:
    // 004aeb76  837e1c01               +cmp dword ptr [esi + 0x1c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aeb7a  7445                   -je 0x4aebc1
    if (cpu.flags.zf)
    {
        goto L_0x004aebc1;
    }
    // 004aeb7c  6b56241e               -imul edx, dword ptr [esi + 0x24], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004aeb80  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004aeb85  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aeb87  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004aeb8a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004aeb8c  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004aeb8f  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004aeb95  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aeb97  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aeb98  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004aeb9b  e8382f0000             -call 0x4b1ad8
    cpu.esp -= 4;
    sub_4b1ad8(app, cpu);
    if (cpu.terminate) return;
    // 004aeba0  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004aeba3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aeba5  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004aeba8  894624                 -mov dword ptr [esi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004aebab  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aebad  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aebaf  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004aebb2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aebb4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004aebb7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aebba  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aebbc  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aebbe  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x004aebc1:
    // 004aebc1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aebc5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004aebc7  ff15b4a14c00           -call dword ptr [0x4ca1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aebcd  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004aebd0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aebd2  742e                   -je 0x4aec02
    if (cpu.flags.zf)
    {
        goto L_0x004aec02;
    }
    // 004aebd4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aebd6  df00                   -fild word ptr [eax]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax))));
    // 004aebd8  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aebdb  df4002                 -fild word ptr [eax + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */))));
    // 004aebde  d95e08                 -fstp dword ptr [esi + 8]
    app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aebe1  df4004                 -fild word ptr [eax + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */))));
    // 004aebe4  d95e0c                 -fstp dword ptr [esi + 0xc]
    app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aebe7  df4006                 -fild word ptr [eax + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */))));
    // 004aebea  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004aebed  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004aebf4  83c008                 +add eax, 8
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
    // 004aebf7  d95e10                 +fstp dword ptr [esi + 0x10]
    app->getMemory<float>(cpu.esi + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aebfa  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004aebfd  e930ffffff             -jmp 0x4aeb32
    goto L_0x004aeb32;
L_0x004aec02:
    // 004aec02  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004aec04  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aec06  0f8e26ffffff           -jle 0x4aeb32
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aeb32;
    }
L_0x004aec0c:
    // 004aec0c  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004aec0f  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004aec15  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004aec18  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aec1b  4f                     -dec edi
    (cpu.edi)--;
    // 004aec1c  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004aec1f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aec21  7fe9                   -jg 0x4aec0c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aec0c;
    }
    // 004aec23  e90affffff             -jmp 0x4aeb32
    goto L_0x004aeb32;
L_0x004aec28:
    // 004aec28  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004aec2b  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004aec2e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004aec30  894cc62c               -mov dword ptr [esi + eax*8 + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.eax * 8) = cpu.ecx;
    // 004aec34  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004aec37  8b5628                 -mov edx, dword ptr [esi + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004aec3a  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004aec3d  894cd630               -mov dword ptr [esi + edx*8 + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */ + cpu.edx * 8) = cpu.ecx;
    // 004aec41  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004aec44  8b5e28                 -mov ebx, dword ptr [esi + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004aec47  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aec4a  43                     -inc ebx
    (cpu.ebx)++;
    // 004aec4b  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004aec4e  47                     -inc edi
    (cpu.edi)++;
    // 004aec4f  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004aec52  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aec54  7cd2                   -jl 0x4aec28
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aec28;
    }
    // 004aec56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aec58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aec59  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aec5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aec5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aec5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aec5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aec60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aec60  c7401c01000000         -mov dword ptr [eax + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004aec67  c7402400000000         -mov dword ptr [eax + 0x24], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004aec6e  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004aec75  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004aec7c  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004aec83  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004aec8a  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004aec91  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004aec94  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aec98  c700b0ea4a00           -mov dword ptr [eax], 0x4aeab0
    app->getMemory<x86::reg32>(cpu.eax) = 4909744 /*0x4aeab0*/;
    // 004aec9e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aeca2  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004aeca8  b804010000             -mov eax, 0x104
    cpu.eax = 260 /*0x104*/;
    // 004aecad  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4aecb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aecb0  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004aecb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aecb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aecb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aecb9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aecba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aecbb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004aecbd  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004aecbf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aecc1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aecc3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aecc5  7e34                   -jle 0x4aecfb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aecfb;
    }
    // 004aecc7  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004aecc9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004aeccb:
    // 004aeccb  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004aeccd  25ffff0100             -and eax, 0x1ffff
    cpu.eax &= x86::reg32(x86::sreg32(131071 /*0x1ffff*/));
    // 004aecd2  3dff7f0000             +cmp eax, 0x7fff
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
    // 004aecd7  7613                   -jbe 0x4aecec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aecec;
    }
    // 004aecd9  3d00800100             +cmp eax, 0x18000
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
    // 004aecde  730c                   -jae 0x4aecec
    if (!cpu.flags.cf)
    {
        goto L_0x004aecec;
    }
    // 004aece0  3d00000100             +cmp eax, 0x10000
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
    // 004aece5  7318                   -jae 0x4aecff
    if (!cpu.flags.cf)
    {
        goto L_0x004aecff;
    }
    // 004aece7  b8ff7f0000             -mov eax, 0x7fff
    cpu.eax = 32767 /*0x7fff*/;
L_0x004aecec:
    // 004aecec  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aecef  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aecf2  41                     -inc ecx
    (cpu.ecx)++;
    // 004aecf3  668943fe               -mov word ptr [ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004aecf7  39f1                   +cmp ecx, esi
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
    // 004aecf9  7cd0                   -jl 0x4aeccb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aeccb;
    }
L_0x004aecfb:
    // 004aecfb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aecfc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aecfd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aecfe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aecff:
    // 004aecff  b800800000             -mov eax, 0x8000
    cpu.eax = 32768 /*0x8000*/;
    // 004aed04  ebe6                   -jmp 0x4aecec
    goto L_0x004aecec;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4aed08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aed08  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aed09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aed0a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aed0b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aed0e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004aed10  8b884c0d0000           -mov ecx, dword ptr [eax + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004aed16  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004aed1c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004aed1e  39d1                   +cmp ecx, edx
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
    // 004aed20  0f83eb000000           -jae 0x4aee11
    if (!cpu.flags.cf)
    {
        goto L_0x004aee11;
    }
    // 004aed26  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aed27  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aed29  8b984c0d0000           -mov ebx, dword ptr [eax + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004aed2f  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004aed31  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004aed37  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004aed39  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aed3b  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004aed41  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004aed45  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004aed47  0f8ed0000000           -jle 0x4aee1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aee1d;
    }
    // 004aed4d  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004aed4f:
    // 004aed4f  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004aed55  39f5                   +cmp ebp, esi
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
    // 004aed57  7d02                   -jge 0x4aed5b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aed5b;
    }
    // 004aed59  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004aed5b:
    // 004aed5b  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004aed60  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004aed66  8d9f84060000           -lea ebx, [edi + 0x684]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 004aed6c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aed6e  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004aed72  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aed75  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aed77  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aed79  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004aed7b  e838ffffff             -call 0x4aecb8
    cpu.esp -= 4;
    sub_4aecb8(app, cpu);
    if (cpu.terminate) return;
    // 004aed80  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004aed83  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aed85  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004aed8b  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004aed8d  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004aed8f  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004aed95  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aed97  7e5f                   -jle 0x4aedf8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aedf8;
    }
    // 004aed99  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aed9d  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004aeda1:
    // 004aeda1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004aeda6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aeda8  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004aedad  e8be3a0000             -call 0x4b2870
    cpu.esp -= 4;
    sub_4b2870(app, cpu);
    if (cpu.terminate) return;
    // 004aedb2  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 004aedbc  39f5                   +cmp ebp, esi
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
    // 004aedbe  7d02                   -jge 0x4aedc2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aedc2;
    }
    // 004aedc0  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004aedc2:
    // 004aedc2  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004aedc7  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 004aedcd  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aedd1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aedd4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aedd6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aedd8  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004aedda  e8d9feffff             -call 0x4aecb8
    cpu.esp -= 4;
    sub_4aecb8(app, cpu);
    if (cpu.terminate) return;
    // 004aeddf  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004aede2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aede4  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004aedea  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004aedec  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004aedee  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004aedf4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004aedf6  7fa9                   -jg 0x4aeda1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aeda1;
    }
L_0x004aedf8:
    // 004aedf8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aedfa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004aedfb:
    // 004aedfb  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004aedfe  39d0                   +cmp eax, edx
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
    // 004aee00  7d26                   -jge 0x4aee28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aee28;
    }
    // 004aee02  83c102                 +add ecx, 2
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
    // 004aee05  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004aee08  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004aee0c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004aee0f  ebea                   -jmp 0x4aedfb
    goto L_0x004aedfb;
L_0x004aee11:
    // 004aee11  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004aee16  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aee19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aee1d:
    // 004aee1d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004aee1f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004aee23  e927ffffff             -jmp 0x4aed4f
    goto L_0x004aed4f;
L_0x004aee28:
    // 004aee28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aee2a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aee2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4aee34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aee34  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aee35  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aee37  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aee39  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004aee3b  e844390000             -call 0x4b2784
    cpu.esp -= 4;
    sub_4b2784(app, cpu);
    if (cpu.terminate) return;
    // 004aee40  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004aee4a  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004aee54  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aee58  899e440d0000           -mov dword ptr [esi + 0xd44], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ebx;
    // 004aee5e  c70008ed4a00           -mov dword ptr [eax], 0x4aed08
    app->getMemory<x86::reg32>(cpu.eax) = 4910344 /*0x4aed08*/;
    // 004aee64  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aee68  c700b0ec4a00           -mov dword ptr [eax], 0x4aecb0
    app->getMemory<x86::reg32>(cpu.eax) = 4910256 /*0x4aecb0*/;
    // 004aee6e  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 004aee73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aee74  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aee80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aee80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aee81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aee82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aee83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aee84  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aee87  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004aee89  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004aee8f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aee91  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aee93  0f84b5000000           -je 0x4aef4e
    if (cpu.flags.zf)
    {
        goto L_0x004aef4e;
    }
    // 004aee99  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aee9b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aee9d  0f8ea1000000           -jle 0x4aef44
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aef44;
    }
    // 004aeea3  8d9884060000           -lea ebx, [eax + 0x684]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1668) /* 0x684 */);
    // 004aeea9  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004aeead  8d98480d0000           -lea ebx, [eax + 0xd48]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(3400) /* 0xd48 */);
    // 004aeeb3  05440d0000             -add eax, 0xd44
    (cpu.eax) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 004aeeb8  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004aeebc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004aeebf:
    // 004aeebf  8b814c0d0000           -mov eax, dword ptr [ecx + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 004aeec5  3b81480d0000           +cmp eax, dword ptr [ecx + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aeecb  0f8d8a000000           -jge 0x4aef5b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aef5b;
    }
L_0x004aeed1:
    // 004aeed1  83b9500d000000         +cmp dword ptr [ecx + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aeed8  0f8e0f010000           -jle 0x4aefed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aefed;
    }
L_0x004aeede:
    // 004aeede  8bb1480d0000           -mov esi, dword ptr [ecx + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */);
    // 004aeee4  2bb14c0d0000           -sub esi, dword ptr [ecx + 0xd4c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */)));
    // 004aeeea  39f7                   +cmp edi, esi
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
    // 004aeeec  7d02                   -jge 0x4aeef0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aeef0;
    }
    // 004aeeee  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004aeef0:
    // 004aeef0  8b91500d0000           -mov edx, dword ptr [ecx + 0xd50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 004aeef6  39d6                   +cmp esi, edx
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
    // 004aeef8  7e02                   -jle 0x4aeefc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aeefc;
    }
    // 004aeefa  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x004aeefc:
    // 004aeefc  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004aef01  2b81500d0000           -sub eax, dword ptr [ecx + 0xd50]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */)));
    // 004aef07  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aef0b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aef0e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004aef10  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aef12  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004aef14  e89ffdffff             -call 0x4aecb8
    cpu.esp -= 4;
    sub_4aecb8(app, cpu);
    if (cpu.terminate) return;
    // 004aef19  8b994c0d0000           -mov ebx, dword ptr [ecx + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */);
    // 004aef1f  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aef21  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004aef24  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aef26  8b81500d0000           -mov eax, dword ptr [ecx + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */);
    // 004aef2c  89994c0d0000           -mov dword ptr [ecx + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004aef32  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004aef34  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004aef36  8981500d0000           -mov dword ptr [ecx + 0xd50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 004aef3c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004aef3e  0f8f7bffffff           -jg 0x4aeebf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aeebf;
    }
L_0x004aef44:
    // 004aef44  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aef46  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aef49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef4b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aef4e:
    // 004aef4e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004aef53  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aef56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef59  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aef5a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aef5b:
    // 004aef5b  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aef5f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aef62  ff15b4a14c00           -call dword ptr [0x4ca1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aef68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aef6a  752b                   -jne 0x4aef97
    if (!cpu.flags.zf)
    {
        goto L_0x004aef97;
    }
    // 004aef6c  8b99440d0000           -mov ebx, dword ptr [ecx + 0xd44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 004aef72  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aef74  7421                   -je 0x4aef97
    if (cpu.flags.zf)
    {
        goto L_0x004aef97;
    }
    // 004aef76  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004aef78  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aef7a  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004aef7c  7443                   -je 0x4aefc1
    if (cpu.flags.zf)
    {
        goto L_0x004aefc1;
    }
    // 004aef7e  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aef81  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aef83  e8fc370000             -call 0x4b2784
    cpu.esp -= 4;
    sub_4b2784(app, cpu);
    if (cpu.terminate) return;
    // 004aef88  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004aef92  e93affffff             -jmp 0x4aeed1
    goto L_0x004aeed1;
L_0x004aef97:
    // 004aef97  8d1c3f                 -lea ebx, [edi + edi]
    cpu.ebx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004aef9a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004aef9c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aef9e  e81c52fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004aefa3  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004aefad  c781480d000000000000   -mov dword ptr [ecx + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004aefb7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aefb9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004aefbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aefbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aefbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aefbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aefc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aefc1:
    // 004aefc1  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aefc4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aefc9  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004aefcc  8b81440d0000           -mov eax, dword ptr [ecx + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3396) /* 0xd44 */);
    // 004aefd2  c7410808000000         -mov dword ptr [ecx + 8], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 004aefd9  83c002                 +add eax, 2
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
    // 004aefdc  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004aefde  c7814c0d000000000000   -mov dword ptr [ecx + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004aefe8  e9e4feffff             -jmp 0x4aeed1
    goto L_0x004aeed1;
L_0x004aefed:
    // 004aefed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004aeff2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aeff4  e877380000             -call 0x4b2870
    cpu.esp -= 4;
    sub_4b2870(app, cpu);
    if (cpu.terminate) return;
    // 004aeff9  c781500d0000b0010000   -mov dword ptr [ecx + 0xd50], 0x1b0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 004af003  e9d6feffff             -jmp 0x4aeede
    goto L_0x004aeede;
}

/* align: skip  */
void Application::sub_4af008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af008  c780440d000001000000   -mov dword ptr [eax + 0xd44], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 004af012  c780480d000000000000   -mov dword ptr [eax + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004af01c  c7804c0d000000000000   -mov dword ptr [eax + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004af026  c780500d000000000000   -mov dword ptr [eax + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 004af030  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004af034  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004af03a  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004af03e  c70080ee4a00           -mov dword ptr [eax], 0x4aee80
    app->getMemory<x86::reg32>(cpu.eax) = 4910720 /*0x4aee80*/;
    // 004af044  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 004af049  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4af050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af050  8b804c0d0000           -mov eax, dword ptr [eax + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004af056  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4af058(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af058  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af059  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af05b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af05d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004af05f  7e13                   -jle 0x4af074
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af074;
    }
L_0x004af061:
    // 004af061  d901                   -fld dword ptr [ecx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ecx)));
    // 004af063  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004af066  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004af069  40                     -inc eax
    (cpu.eax)++;
    // 004af06a  d95afc                 -fstp dword ptr [edx - 4]
    app->getMemory<float>(cpu.edx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004af06d  39d8                   +cmp eax, ebx
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
    // 004af06f  7cf0                   -jl 0x4af061
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004af061;
    }
    // 004af071  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004af074:
    // 004af074  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af075  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4af078(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af078  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af079  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af07a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af07b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004af07e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004af080  8b884c0d0000           -mov ecx, dword ptr [eax + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004af086  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004af08c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004af08e  39d1                   +cmp ecx, edx
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
    // 004af090  0f83f2000000           -jae 0x4af188
    if (!cpu.flags.cf)
    {
        goto L_0x004af188;
    }
    // 004af096  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af097  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004af099  8b984c0d0000           -mov ebx, dword ptr [eax + 0xd4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */);
    // 004af09f  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004af0a1  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004af0a7  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004af0a9  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af0ab  89984c0d0000           -mov dword ptr [eax + 0xd4c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = cpu.ebx;
    // 004af0b1  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004af0b5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004af0b7  0f8ed7000000           -jle 0x4af194
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af194;
    }
    // 004af0bd  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004af0bf:
    // 004af0bf  8bb7480d0000           -mov esi, dword ptr [edi + 0xd48]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004af0c5  39f5                   +cmp ebp, esi
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
    // 004af0c7  7d02                   -jge 0x4af0cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004af0cb;
    }
    // 004af0c9  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004af0cb:
    // 004af0cb  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004af0d0  8b97480d0000           -mov edx, dword ptr [edi + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004af0d6  8d9f84060000           -lea ebx, [edi + 0x684]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(1668) /* 0x684 */);
    // 004af0dc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af0de  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004af0e2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004af0e5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004af0e7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004af0e9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004af0eb  e868ffffff             -call 0x4af058
    cpu.esp -= 4;
    sub_4af058(app, cpu);
    if (cpu.terminate) return;
    // 004af0f0  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004af0f7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af0f9  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004af0ff  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004af101  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004af103  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004af109  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004af10b  7e60                   -jle 0x4af16d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af16d;
    }
    // 004af10d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004af111  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004af115:
    // 004af115  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004af117  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004af119  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004af11e  e84d370000             -call 0x4b2870
    cpu.esp -= 4;
    sub_4b2870(app, cpu);
    if (cpu.terminate) return;
    // 004af123  c787480d0000b0010000   -mov dword ptr [edi + 0xd48], 0x1b0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = 432 /*0x1b0*/;
    // 004af12d  39f5                   +cmp ebp, esi
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
    // 004af12f  7d02                   -jge 0x4af133
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004af133;
    }
    // 004af131  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004af133:
    // 004af133  b8b0010000             -mov eax, 0x1b0
    cpu.eax = 432 /*0x1b0*/;
    // 004af138  2b87480d0000           -sub eax, dword ptr [edi + 0xd48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */)));
    // 004af13e  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004af142  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004af145  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004af147  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004af149  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004af14b  e808ffffff             -call 0x4af058
    cpu.esp -= 4;
    sub_4af058(app, cpu);
    if (cpu.terminate) return;
    // 004af150  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004af157  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af159  8b87480d0000           -mov eax, dword ptr [edi + 0xd48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */);
    // 004af15f  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004af161  29f5                   -sub ebp, esi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004af163  8987480d0000           -mov dword ptr [edi + 0xd48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3400) /* 0xd48 */) = cpu.eax;
    // 004af169  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004af16b  7fa8                   -jg 0x4af115
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004af115;
    }
L_0x004af16d:
    // 004af16d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004af16e:
    // 004af16e  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004af172  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004af174  7e29                   -jle 0x4af19f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af19f;
    }
    // 004af176  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004af179  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 004af17f  83c104                 +add ecx, 4
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
    // 004af182  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004af186  ebe6                   -jmp 0x4af16e
    goto L_0x004af16e;
L_0x004af188:
    // 004af188  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004af18d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004af190  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af191  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af192  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af193  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af194:
    // 004af194  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004af196  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004af19a  e920ffffff             -jmp 0x4af0bf
    goto L_0x004af0bf;
L_0x004af19f:
    // 004af19f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af1a1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004af1a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af1a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af1a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af1a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af1a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af1a8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af1a9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af1ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af1ad  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004af1af  e8d0350000             -call 0x4b2784
    cpu.esp -= 4;
    sub_4b2784(app, cpu);
    if (cpu.terminate) return;
    // 004af1b4  c786480d000000000000   -mov dword ptr [esi + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004af1be  c7864c0d000000000000   -mov dword ptr [esi + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004af1c8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004af1cc  899e440d0000           -mov dword ptr [esi + 0xd44], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3396) /* 0xd44 */) = cpu.ebx;
    // 004af1d2  c70078f04a00           -mov dword ptr [eax], 0x4af078
    app->getMemory<x86::reg32>(cpu.eax) = 4911224 /*0x4af078*/;
    // 004af1d8  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af1dc  c70050f04a00           -mov dword ptr [eax], 0x4af050
    app->getMemory<x86::reg32>(cpu.eax) = 4911184 /*0x4af050*/;
    // 004af1e2  b8500d0000             -mov eax, 0xd50
    cpu.eax = 3408 /*0xd50*/;
    // 004af1e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af1e8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4af1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af1f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af1f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af1f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af1f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af1f4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004af1f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af1f9  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004af1fd  8b90440d0000           -mov edx, dword ptr [eax + 0xd44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */);
    // 004af203  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004af205  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004af207  0f84e2000000           -je 0x4af2ef
    if (cpu.flags.zf)
    {
        goto L_0x004af2ef;
    }
    // 004af20d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004af20f  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af213  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004af216  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004af218  0f8ec7000000           -jle 0x4af2e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af2e5;
    }
    // 004af21e  8d8684060000           -lea eax, [esi + 0x684]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1668) /* 0x684 */);
    // 004af224  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004af228  8d86480d0000           -lea eax, [esi + 0xd48]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3400) /* 0xd48 */);
    // 004af22e  81c6440d0000           -add esi, 0xd44
    (cpu.esi) += x86::reg32(x86::sreg32(3396 /*0xd44*/));
    // 004af234  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004af238  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004af23c:
    // 004af23c  8b854c0d0000           -mov eax, dword ptr [ebp + 0xd4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004af242  3b85480d0000           +cmp eax, dword ptr [ebp + 0xd48]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af248  0f8dae000000           -jge 0x4af2fc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004af2fc;
    }
L_0x004af24e:
    // 004af24e  83bd500d000000         +cmp dword ptr [ebp + 0xd50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af255  0f8e3a010000           -jle 0x4af395
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af395;
    }
L_0x004af25b:
    // 004af25b  8b95480d0000           -mov edx, dword ptr [ebp + 0xd48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */);
    // 004af261  8bbd4c0d0000           -mov edi, dword ptr [ebp + 0xd4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004af267  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af26b  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004af26d  39c2                   +cmp edx, eax
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
    // 004af26f  7e02                   -jle 0x4af273
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af273;
    }
    // 004af271  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004af273:
    // 004af273  8b8d500d0000           -mov ecx, dword ptr [ebp + 0xd50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004af279  39ca                   +cmp edx, ecx
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
    // 004af27b  7e02                   -jle 0x4af27f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004af27f;
    }
    // 004af27d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x004af27f:
    // 004af27f  beb0010000             -mov esi, 0x1b0
    cpu.esi = 432 /*0x1b0*/;
    // 004af284  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004af288  8bbd500d0000           -mov edi, dword ptr [ebp + 0xd50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004af28e  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 004af295  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004af297  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004af299  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004af29c  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004af29f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004af2a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af2a2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af2a4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004af2a7  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004af2a9  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004af2ab  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004af2ae  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004af2b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2b1  8b8d4c0d0000           -mov ecx, dword ptr [ebp + 0xd4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */);
    // 004af2b7  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 004af2ba  8b85500d0000           -mov eax, dword ptr [ebp + 0xd50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */);
    // 004af2c0  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af2c4  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004af2c7  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004af2c9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af2cb  898d4c0d0000           -mov dword ptr [ebp + 0xd4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = cpu.ecx;
    // 004af2d1  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af2d3  8985500d0000           -mov dword ptr [ebp + 0xd50], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = cpu.eax;
    // 004af2d9  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004af2dd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004af2df  0f8f57ffffff           -jg 0x4af23c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004af23c;
    }
L_0x004af2e5:
    // 004af2e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af2e7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004af2ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af2ef:
    // 004af2ef  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004af2f4  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004af2f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af2fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af2fc:
    // 004af2fc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004af300  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004af304  ff15b4a14c00           -call dword ptr [0x4ca1b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022132) /* 0x4ca1b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af30a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af30c  752b                   -jne 0x4af339
    if (!cpu.flags.zf)
    {
        goto L_0x004af339;
    }
    // 004af30e  8b9d440d0000           -mov ebx, dword ptr [ebp + 0xd44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 004af314  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004af316  7421                   -je 0x4af339
    if (cpu.flags.zf)
    {
        goto L_0x004af339;
    }
    // 004af318  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004af31a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af31c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004af31e  7448                   -je 0x4af368
    if (cpu.flags.zf)
    {
        goto L_0x004af368;
    }
    // 004af320  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004af323  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004af325  e85a340000             -call 0x4b2784
    cpu.esp -= 4;
    sub_4b2784(app, cpu);
    if (cpu.terminate) return;
    // 004af32a  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004af334  e915ffffff             -jmp 0x4af24e
    goto L_0x004af24e;
L_0x004af339:
    // 004af339  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004af33d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004af340  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004af342  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004af345  e8754efdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004af34a  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004af354  c785480d000000000000   -mov dword ptr [ebp + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004af35e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af360  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004af363  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af364  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af365  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af366  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af367  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af368:
    // 004af368  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004af36b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af370  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004af373  8b85440d0000           -mov eax, dword ptr [ebp + 0xd44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3396) /* 0xd44 */);
    // 004af379  c7450808000000         -mov dword ptr [ebp + 8], 8
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 8 /*0x8*/;
    // 004af380  83c002                 +add eax, 2
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
    // 004af383  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004af386  c7854c0d000000000000   -mov dword ptr [ebp + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004af390  e9b9feffff             -jmp 0x4af24e
    goto L_0x004af24e;
L_0x004af395:
    // 004af395  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004af397  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004af399  e8d2340000             -call 0x4b2870
    cpu.esp -= 4;
    sub_4b2870(app, cpu);
    if (cpu.terminate) return;
    // 004af39e  c785500d0000b0010000   -mov dword ptr [ebp + 0xd50], 0x1b0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3408) /* 0xd50 */) = 432 /*0x1b0*/;
    // 004af3a8  e9aefeffff             -jmp 0x4af25b
    goto L_0x004af25b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4af3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af3b0  c780440d000001000000   -mov dword ptr [eax + 0xd44], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3396) /* 0xd44 */) = 1 /*0x1*/;
    // 004af3ba  c780480d000000000000   -mov dword ptr [eax + 0xd48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3400) /* 0xd48 */) = 0 /*0x0*/;
    // 004af3c4  c7804c0d000000000000   -mov dword ptr [eax + 0xd4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3404) /* 0xd4c */) = 0 /*0x0*/;
    // 004af3ce  c780500d000000000000   -mov dword ptr [eax + 0xd50], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3408) /* 0xd50 */) = 0 /*0x0*/;
    // 004af3d8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004af3dc  c700f0f14a00           -mov dword ptr [eax], 0x4af1f0
    app->getMemory<x86::reg32>(cpu.eax) = 4911600 /*0x4af1f0*/;
    // 004af3e2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004af3e6  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004af3ec  b8540d0000             -mov eax, 0xd54
    cpu.eax = 3412 /*0xd54*/;
    // 004af3f1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4af3f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af3f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af3f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af3f6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af3f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af3f8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af3f9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af3fb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004af3fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af3ff  7509                   -jne 0x4af40a
    if (!cpu.flags.zf)
    {
        goto L_0x004af40a;
    }
    // 004af401  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af403  e84b67feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004af408  eb5e                   -jmp 0x4af468
    goto L_0x004af468;
L_0x004af40a:
    // 004af40a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004af40c  7509                   -jne 0x4af417
    if (!cpu.flags.zf)
    {
        goto L_0x004af417;
    }
    // 004af40e  e836b8feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004af413  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004af415  eb51                   -jmp 0x4af468
    goto L_0x004af468;
L_0x004af417:
    // 004af417  e8e4370000             -call 0x4b2c00
    cpu.esp -= 4;
    sub_4b2c00(app, cpu);
    if (cpu.terminate) return;
    // 004af41c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af41e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af420  e8e6370000             -call 0x4b2c0b
    cpu.esp -= 4;
    sub_4b2c0b(app, cpu);
    if (cpu.terminate) return;
    // 004af425  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004af427  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af429  753b                   -jne 0x4af466
    if (!cpu.flags.zf)
    {
        goto L_0x004af466;
    }
    // 004af42b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af42d  e82167feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004af432  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004af434  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af436  7425                   -je 0x4af45d
    if (cpu.flags.zf)
    {
        goto L_0x004af45d;
    }
    // 004af438  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004af43a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004af43c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004af43e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004af43f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004af441  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004af443  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af444  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af446  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004af449  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004af44b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004af44d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004af450  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004af452  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af453  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004af454  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af456  e8eeb7feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004af45b  eb09                   -jmp 0x4af466
    goto L_0x004af466;
L_0x004af45d:
    // 004af45d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004af45f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af461  e8a5370000             -call 0x4b2c0b
    cpu.esp -= 4;
    sub_4b2c0b(app, cpu);
    if (cpu.terminate) return;
L_0x004af466:
    // 004af466  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x004af468:
    // 004af468  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af469  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af46a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af46b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af46c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af46d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af46e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af46e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af46f  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004af472  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af474  e8da66feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004af479  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af47b  7407                   -je 0x4af484
    if (cpu.flags.zf)
    {
        goto L_0x004af484;
    }
    // 004af47d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004af47f  e83b4dfdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
L_0x004af484:
    // 004af484  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af485  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af486(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af486  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af487  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af488  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af489  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af48b  e8399effff             -call 0x4a92c9
    cpu.esp -= 4;
    sub_4a92c9(app, cpu);
    if (cpu.terminate) return;
    // 004af490  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004af492  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af494  7410                   -je 0x4af4a6
    if (cpu.flags.zf)
    {
        goto L_0x004af4a6;
    }
    // 004af496  8b1540c14c00           -mov edx, dword ptr [0x4cc140]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004af49c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af49d  2eff1584554b00         -call dword ptr cs:[0x4b5584]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937092) /* 0x4b5584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af4a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004af4a6:
    // 004af4a6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004af4a8  750f                   -jne 0x4af4b9
    if (!cpu.flags.zf)
    {
        goto L_0x004af4b9;
    }
    // 004af4aa  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004af4af  b860fb4b00             -mov eax, 0x4bfb60
    cpu.eax = 4979552 /*0x4bfb60*/;
    // 004af4b4  e878abffff             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
L_0x004af4b9:
    // 004af4b9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af4bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af4bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af4bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af4be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af4bf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af4bf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af4c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af4c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af4c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af4c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af4c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af4c5  ff1570c14c00           -call dword ptr [0x4cc170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030256) /* 0x4cc170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af4cb  2eff159c544b00         -call dword ptr cs:[0x4b549c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936860) /* 0x4b549c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af4d2  8b1da0755400           -mov ebx, dword ptr [0x5475a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5535136) /* 0x5475a0 */);
    // 004af4d8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004af4da  eb07                   -jmp 0x4af4e3
    goto L_0x004af4e3;
L_0x004af4dc:
    // 004af4dc  3b6b04                 +cmp ebp, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af4df  7406                   -je 0x4af4e7
    if (cpu.flags.zf)
    {
        goto L_0x004af4e7;
    }
    // 004af4e1  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
L_0x004af4e3:
    // 004af4e3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004af4e5  75f5                   -jne 0x4af4dc
    if (!cpu.flags.zf)
    {
        goto L_0x004af4dc;
    }
L_0x004af4e7:
    // 004af4e7  837b0c00               +cmp dword ptr [ebx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af4eb  7425                   -je 0x4af512
    if (cpu.flags.zf)
    {
        goto L_0x004af512;
    }
    // 004af4ed  8b1590d64c00           -mov edx, dword ptr [0x4cd690]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5035664) /* 0x4cd690 */);
    // 004af4f3  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004af4f6  e8f9feffff             -call 0x4af3f4
    cpu.esp -= 4;
    sub_4af3f4(app, cpu);
    if (cpu.terminate) return;
    // 004af4fb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004af4fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af4ff  755e                   -jne 0x4af55f
    if (!cpu.flags.zf)
    {
        goto L_0x004af55f;
    }
    // 004af501  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004af506  b885fb4b00             -mov eax, 0x4bfb85
    cpu.eax = 4979589 /*0x4bfb85*/;
    // 004af50b  e821abffff             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
    // 004af510  eb4d                   -jmp 0x4af55f
    goto L_0x004af55f;
L_0x004af512:
    // 004af512  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004af517  8b1590d64c00           -mov edx, dword ptr [0x4cd690]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5035664) /* 0x4cd690 */);
    // 004af51d  e84cffffff             -call 0x4af46e
    cpu.esp -= 4;
    sub_4af46e(app, cpu);
    if (cpu.terminate) return;
    // 004af522  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004af524  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af526  750f                   -jne 0x4af537
    if (!cpu.flags.zf)
    {
        goto L_0x004af537;
    }
    // 004af528  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004af52d  b8adfb4b00             -mov eax, 0x4bfbad
    cpu.eax = 4979629 /*0x4bfbad*/;
    // 004af532  e8faaaffff             -call 0x4aa031
    cpu.esp -= 4;
    sub_4aa031(app, cpu);
    if (cpu.terminate) return;
L_0x004af537:
    // 004af537  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004af53a  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004af53c  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 004af542  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004af543  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004af545  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004af547  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af548  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af54a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004af54d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004af54f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004af551  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004af554  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004af556  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af557  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004af558  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004af55f:
    // 004af55f  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004af562  a190d64c00             -mov eax, dword ptr [0x4cd690]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035664) /* 0x4cd690 */);
    // 004af567  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004af568  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 004af56c  8b3540c14c00           -mov esi, dword ptr [0x4cc140]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5030208) /* 0x4cc140 */);
    // 004af572  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 004af576  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af577  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004af57d  2eff1588554b00         -call dword ptr cs:[0x4b5588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937096) /* 0x4b5588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af584  ff1574c14c00           -call dword ptr [0x4cc174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030260) /* 0x4cc174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af58a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004af58c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af58d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af58e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af58f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af590  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af591  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af592  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af593(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af593  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af594  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af595  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af596  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004af598  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004af59a  ff1570c14c00           -call dword ptr [0x4cc170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030256) /* 0x4cc170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af5a0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004af5a5  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004af5aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af5ac  e8bdfeffff             -call 0x4af46e
    cpu.esp -= 4;
    sub_4af46e(app, cpu);
    if (cpu.terminate) return;
    // 004af5b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af5b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af5b5  742f                   -je 0x4af5e6
    if (cpu.flags.zf)
    {
        goto L_0x004af5e6;
    }
    // 004af5b7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af5b9  e842380000             -call 0x4b2e00
    cpu.esp -= 4;
    sub_4b2e00(app, cpu);
    if (cpu.terminate) return;
    // 004af5be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af5c0  7409                   -je 0x4af5cb
    if (cpu.flags.zf)
    {
        goto L_0x004af5cb;
    }
    // 004af5c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af5c4  e880b6feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004af5c9  eb1b                   -jmp 0x4af5e6
    goto L_0x004af5e6;
L_0x004af5cb:
    // 004af5cb  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004af5ce  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004af5d1  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 004af5d4  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004af5d7  a1a0755400             -mov eax, dword ptr [0x5475a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5535136) /* 0x5475a0 */);
    // 004af5dc  8915a0755400           -mov dword ptr [0x5475a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5535136) /* 0x5475a0 */) = cpu.edx;
    // 004af5e2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004af5e4  eb02                   -jmp 0x4af5e8
    goto L_0x004af5e8;
L_0x004af5e6:
    // 004af5e6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004af5e8:
    // 004af5e8  ff1574c14c00           -call dword ptr [0x4cc174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030260) /* 0x4cc174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af5ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af5f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af5f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af5f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af5f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af5f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af5f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af5f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af5f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af5f7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af5f9  ff1570c14c00           -call dword ptr [0x4cc170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030256) /* 0x4cc170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af5ff  bba0755400             -mov ebx, 0x5475a0
    cpu.ebx = 5535136 /*0x5475a0*/;
    // 004af604  8b15a0755400           -mov edx, dword ptr [0x5475a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5535136) /* 0x5475a0 */);
    // 004af60a  eb24                   -jmp 0x4af630
    goto L_0x004af630;
L_0x004af60c:
    // 004af60c  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af60f  751b                   -jne 0x4af62c
    if (!cpu.flags.zf)
    {
        goto L_0x004af62c;
    }
    // 004af611  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af615  7408                   -je 0x4af61f
    if (cpu.flags.zf)
    {
        goto L_0x004af61f;
    }
    // 004af617  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004af61a  e82ab6feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004af61f:
    // 004af61f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004af621  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004af623  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af625  e81fb6feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004af62a  eb08                   -jmp 0x4af634
    goto L_0x004af634;
L_0x004af62c:
    // 004af62c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004af62e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004af630:
    // 004af630  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004af632  75d8                   -jne 0x4af60c
    if (!cpu.flags.zf)
    {
        goto L_0x004af60c;
    }
L_0x004af634:
    // 004af634  ff1574c14c00           -call dword ptr [0x4cc174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030260) /* 0x4cc174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af63a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af63b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af63c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af63d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af63a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004af63a;
    // 004af5f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af5f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af5f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af5f7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004af5f9  ff1570c14c00           -call dword ptr [0x4cc170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030256) /* 0x4cc170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af5ff  bba0755400             -mov ebx, 0x5475a0
    cpu.ebx = 5535136 /*0x5475a0*/;
    // 004af604  8b15a0755400           -mov edx, dword ptr [0x5475a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5535136) /* 0x5475a0 */);
    // 004af60a  eb24                   -jmp 0x4af630
    goto L_0x004af630;
L_0x004af60c:
    // 004af60c  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af60f  751b                   -jne 0x4af62c
    if (!cpu.flags.zf)
    {
        goto L_0x004af62c;
    }
    // 004af611  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af615  7408                   -je 0x4af61f
    if (cpu.flags.zf)
    {
        goto L_0x004af61f;
    }
    // 004af617  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004af61a  e82ab6feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004af61f:
    // 004af61f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004af621  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004af623  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af625  e81fb6feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004af62a  eb08                   -jmp 0x4af634
    goto L_0x004af634;
L_0x004af62c:
    // 004af62c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004af62e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004af630:
    // 004af630  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004af632  75d8                   -jne 0x4af60c
    if (!cpu.flags.zf)
    {
        goto L_0x004af60c;
    }
L_0x004af634:
    // 004af634  ff1574c14c00           -call dword ptr [0x4cc174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030260) /* 0x4cc174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x004af63a:
    // 004af63a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af63b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af63c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af63d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af63e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af63e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af63f  ff1570c14c00           -call dword ptr [0x4cc170]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030256) /* 0x4cc170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af645  a1a0755400             -mov eax, dword ptr [0x5475a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5535136) /* 0x5475a0 */);
L_0x004af64a:
    // 004af64a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af64c  740b                   -je 0x4af659
    if (cpu.flags.zf)
    {
        goto L_0x004af659;
    }
    // 004af64e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004af651  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 004af655  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004af657  ebf1                   -jmp 0x4af64a
    goto L_0x004af64a;
L_0x004af659:
    // 004af659  ff1574c14c00           -call dword ptr [0x4cc174]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030260) /* 0x4cc174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af65f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af660  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af661(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af661  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af662  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af663  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af664  8b15a0755400           -mov edx, dword ptr [0x5475a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5535136) /* 0x5475a0 */);
L_0x004af66a:
    // 004af66a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004af66c  74cc                   -je 0x4af63a
    if (cpu.flags.zf)
    {
        return sub_4af63a(app, cpu);
    }
    // 004af66e  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004af671  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004af673  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004af675  7408                   -je 0x4af67f
    if (cpu.flags.zf)
    {
        goto L_0x004af67f;
    }
    // 004af677  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004af67a  e8cab5feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004af67f:
    // 004af67f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af681  e8c3b5feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 004af686  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004af688  ebe0                   -jmp 0x4af66a
    goto L_0x004af66a;
}

/* align: skip  */
void Application::sub_4af68a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af68a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af68b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af68c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af68d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af68f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af691  741b                   -je 0x4af6ae
    if (cpu.flags.zf)
    {
        goto L_0x004af6ae;
    }
    // 004af693  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004af695  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004af69c  e87b9fffff             -call 0x4a961c
    cpu.esp -= 4;
    sub_4a961c(app, cpu);
    if (cpu.terminate) return;
    // 004af6a1  2eff159c544b00         -call dword ptr cs:[0x4b549c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936860) /* 0x4b549c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af6a8  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x004af6ae:
    // 004af6ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af6af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af6b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af6b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af6b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af6b2  e9aaffffff             -jmp 0x4af661
    return sub_4af661(app, cpu);
}

/* align: skip  */
void Application::sub_4af6b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af6b7  e99764feff             -jmp 0x495b53
    return malloc(app, cpu);
}

/* align: skip  */
void Application::sub_4af6bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af6bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af6bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af6be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af6bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af6c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af6c1  833d7c70540000         +cmp dword ptr [0x54707c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af6c8  0f85a5000000           -jne 0x4af773
    if (!cpu.flags.zf)
    {
        goto L_0x004af773;
    }
    // 004af6ce  8b3dfdab4c00           -mov edi, dword ptr [0x4cabfd]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024765) /* 0x4cabfd */);
    // 004af6d4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004af6d6  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004af6d8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004af6da:
    // 004af6da  3a10                   +cmp dl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004af6dc  7412                   -je 0x4af6f0
    if (cpu.flags.zf)
    {
        goto L_0x004af6f0;
    }
L_0x004af6de:
    // 004af6de  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004af6e0  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004af6e3  38f2                   +cmp dl, dh
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004af6e5  7404                   -je 0x4af6eb
    if (cpu.flags.zf)
    {
        goto L_0x004af6eb;
    }
    // 004af6e7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af6e9  ebf3                   -jmp 0x4af6de
    goto L_0x004af6de;
L_0x004af6eb:
    // 004af6eb  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004af6ec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af6ee  ebea                   -jmp 0x4af6da
    goto L_0x004af6da;
L_0x004af6f0:
    // 004af6f0  29f8                   +sub eax, edi
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
    // 004af6f2  7505                   -jne 0x4af6f9
    if (!cpu.flags.zf)
    {
        goto L_0x004af6f9;
    }
    // 004af6f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004af6f9:
    // 004af6f9  e85564feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004af6fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af700  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af702  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af704  7468                   -je 0x4af76e
    if (cpu.flags.zf)
    {
        goto L_0x004af76e;
    }
    // 004af706  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af708  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004af70b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004af70e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af710  e83e64feff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004af715  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af717  744e                   -je 0x4af767
    if (cpu.flags.zf)
    {
        goto L_0x004af767;
    }
    // 004af719  a37c705400             -mov dword ptr [0x54707c], eax
    app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */) = cpu.eax;
    // 004af71e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004af720  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004af722  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004af724:
    // 004af724  803800                 +cmp byte ptr [eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004af727  7419                   -je 0x4af742
    if (cpu.flags.zf)
    {
        goto L_0x004af742;
    }
    // 004af729  8b157c705400           -mov edx, dword ptr [0x54707c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004af72f  891c11                 -mov dword ptr [ecx + edx], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x004af732:
    // 004af732  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004af734  40                     -inc eax
    (cpu.eax)++;
    // 004af735  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004af737  43                     -inc ebx
    (cpu.ebx)++;
    // 004af738  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004af73a  75f6                   -jne 0x4af732
    if (!cpu.flags.zf)
    {
        goto L_0x004af732;
    }
    // 004af73c  83c104                 +add ecx, 4
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
    // 004af73f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004af740  ebe2                   -jmp 0x4af724
    goto L_0x004af724;
L_0x004af742:
    // 004af742  8b157c705400           -mov edx, dword ptr [0x54707c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */);
    // 004af748  c7041100000000         -mov dword ptr [ecx + edx], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 004af74f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004af752  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004af754  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004af756  891578705400           -mov dword ptr [0x547078], edx
    app->getMemory<x86::reg32>(x86::reg32(5533816) /* 0x547078 */) = cpu.edx;
    // 004af75c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af75e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004af760  e85a4afdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004af765  eb07                   -jmp 0x4af76e
    goto L_0x004af76e;
L_0x004af767:
    // 004af767  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af769  e8dbb4feff             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
L_0x004af76e:
    // 004af76e  e8d3360000             -call 0x4b2e46
    cpu.esp -= 4;
    sub_4b2e46(app, cpu);
    if (cpu.terminate) return;
L_0x004af773:
    // 004af773  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af774  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af775  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af776  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af777  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af778  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af779(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af779  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af77a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004af77c:
    // 004af77c  66833800               +cmp word ptr [eax], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004af780  7404                   -je 0x4af786
    if (cpu.flags.zf)
    {
        goto L_0x004af786;
    }
    // 004af782  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004af783  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004af784  ebf6                   -jmp 0x4af77c
    goto L_0x004af77c;
L_0x004af786:
    // 004af786  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004af788  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004af78a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af78b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af78c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af78c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af78d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004af78e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af78f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004af791  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004af793  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004af795  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004af796  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004af798  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004af79a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004af79b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004af79d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004af7a0  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004af7a2  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004af7a4  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004af7a7  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004af7a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af7aa  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004af7ab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004af7ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af7ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af7af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af7b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af7b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af7b1  66833801               +cmp word ptr [eax], 1
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004af7b5  751c                   -jne 0x4af7d3
    if (!cpu.flags.zf)
    {
        goto L_0x004af7d3;
    }
    // 004af7b7  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004af7bb  7416                   -je 0x4af7d3
    if (cpu.flags.zf)
    {
        goto L_0x004af7d3;
    }
    // 004af7bd  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 004af7c1  663d1000               +cmp ax, 0x10
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16 /*0x10*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004af7c5  7206                   -jb 0x4af7cd
    if (cpu.flags.cf)
    {
        goto L_0x004af7cd;
    }
    // 004af7c7  663d1200               +cmp ax, 0x12
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18 /*0x12*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004af7cb  7606                   -jbe 0x4af7d3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004af7d3;
    }
L_0x004af7cd:
    // 004af7cd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004af7d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af7d3:
    // 004af7d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af7d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af7d6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af7d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af7d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af7d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af7da  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af7e0  833d34d94c00ff         +cmp dword ptr [0x4cd934], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5036340) /* 0x4cd934 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af7e7  7523                   -jne 0x4af80c
    if (!cpu.flags.zf)
    {
        goto L_0x004af80c;
    }
    // 004af7e9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004af7eb  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 004af7f0  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004af7f2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004af7f4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004af7f6  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 004af7fb  68d8fb4b00             -push 0x4bfbd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979672 /*0x4bfbd8*/;
    cpu.esp -= 4;
    // 004af800  2eff152c544b00         -call dword ptr cs:[0x4b542c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936748) /* 0x4b542c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af807  a334d94c00             -mov dword ptr [0x4cd934], eax
    app->getMemory<x86::reg32>(x86::reg32(5036340) /* 0x4cd934 */) = cpu.eax;
L_0x004af80c:
    // 004af80c  833d38d94c00ff         +cmp dword ptr [0x4cd938], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5036344) /* 0x4cd938 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af813  7523                   -jne 0x4af838
    if (!cpu.flags.zf)
    {
        goto L_0x004af838;
    }
    // 004af815  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004af817  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 004af81c  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004af81e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004af820  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004af822  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 004af827  68dffb4b00             -push 0x4bfbdf
    app->getMemory<x86::reg32>(cpu.esp-4) = 4979679 /*0x4bfbdf*/;
    cpu.esp -= 4;
    // 004af82c  2eff152c544b00         -call dword ptr cs:[0x4b542c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936748) /* 0x4b542c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af833  a338d94c00             -mov dword ptr [0x4cd938], eax
    app->getMemory<x86::reg32>(x86::reg32(5036344) /* 0x4cd938 */) = cpu.eax;
L_0x004af838:
    // 004af838  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af83a  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af840  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af841  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af842  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af843(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af843  e88effffff             -call 0x4af7d6
    cpu.esp -= 4;
    sub_4af7d6(app, cpu);
    if (cpu.terminate) return;
    // 004af848  a134d94c00             -mov eax, dword ptr [0x4cd934]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5036340) /* 0x4cd934 */);
    // 004af84d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af84e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af84e  e883ffffff             -call 0x4af7d6
    cpu.esp -= 4;
    sub_4af7d6(app, cpu);
    if (cpu.terminate) return;
    // 004af853  a138d94c00             -mov eax, dword ptr [0x4cd938]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5036344) /* 0x4cd938 */);
    // 004af858  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af859(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af859  dbe2                   -fnclex 
    /*nothing*/;
    // 004af85b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af85c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af85c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af85d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af85e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af860  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004af862  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af865  7405                   -je 0x4af86c
    if (cpu.flags.zf)
    {
        goto L_0x004af86c;
    }
    // 004af867  83f804                 +cmp eax, 4
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
    // 004af86a  7513                   -jne 0x4af87f
    if (!cpu.flags.zf)
    {
        goto L_0x004af87f;
    }
L_0x004af86c:
    // 004af86c  8b14dd3cd94c00         -mov edx, dword ptr [ebx*8 + 0x4cd93c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5036348) /* 0x4cd93c */ + cpu.ebx * 8);
    // 004af873  890cdd3cd94c00         -mov dword ptr [ebx*8 + 0x4cd93c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5036348) /* 0x4cd93c */ + cpu.ebx * 8) = cpu.ecx;
    // 004af87a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af87c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af87d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af87e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af87f:
    // 004af87f  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af885  8b54d858               -mov edx, dword ptr [eax + ebx*8 + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.ebx * 8);
    // 004af889  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af88f  894cd858               -mov dword ptr [eax + ebx*8 + 0x58], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.ebx * 8) = cpu.ecx;
    // 004af893  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004af895  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af896  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af897  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af898(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af898  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af899  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af89b  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af89e  7405                   -je 0x4af8a5
    if (cpu.flags.zf)
    {
        goto L_0x004af8a5;
    }
    // 004af8a0  83f804                 +cmp eax, 4
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
    // 004af8a3  7509                   -jne 0x4af8ae
    if (!cpu.flags.zf)
    {
        goto L_0x004af8ae;
    }
L_0x004af8a5:
    // 004af8a5  8b04d53cd94c00         -mov eax, dword ptr [edx*8 + 0x4cd93c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5036348) /* 0x4cd93c */ + cpu.edx * 8);
    // 004af8ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af8ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af8ae:
    // 004af8ae  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af8b4  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 004af8b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af8b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af8ba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af8ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af8bb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af8bd  83f807                 +cmp eax, 7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af8c0  7405                   -je 0x4af8c7
    if (cpu.flags.zf)
    {
        goto L_0x004af8c7;
    }
    // 004af8c2  83f804                 +cmp eax, 4
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
    // 004af8c5  7509                   -jne 0x4af8d0
    if (!cpu.flags.zf)
    {
        goto L_0x004af8d0;
    }
L_0x004af8c7:
    // 004af8c7  8b04d540d94c00         -mov eax, dword ptr [edx*8 + 0x4cd940]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5036352) /* 0x4cd940 */ + cpu.edx * 8);
    // 004af8ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af8cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af8d0:
    // 004af8d0  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af8d6  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 004af8da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af8db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af8dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af8dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af8dd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af8df  e8d6ffffff             -call 0x4af8ba
    cpu.esp -= 4;
    sub_4af8ba(app, cpu);
    if (cpu.terminate) return;
    // 004af8e4  39c2                   +cmp edx, eax
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
    // 004af8e6  7509                   -jne 0x4af8f1
    if (!cpu.flags.zf)
    {
        goto L_0x004af8f1;
    }
    // 004af8e8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004af8ea  e8a9ffffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004af8ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af8f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af8f1:
    // 004af8f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af8f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af8f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af8f5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af8f5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004af8f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af8fb  760a                   -jbe 0x4af907
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004af907;
    }
    // 004af8fd  83f801                 +cmp eax, 1
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
    // 004af900  7424                   -je 0x4af926
    if (cpu.flags.zf)
    {
        goto L_0x004af926;
    }
    // 004af902  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af904  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004af907:
    // 004af907  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004af90c  e887ffffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004af911  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af913  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af915  7503                   -jne 0x4af91a
    if (!cpu.flags.zf)
    {
        goto L_0x004af91a;
    }
    // 004af917  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004af91a:
    // 004af91a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x004af91f:
    // 004af91f  e8d5000000             -call 0x4af9f9
    cpu.esp -= 4;
    sub_4af9f9(app, cpu);
    if (cpu.terminate) return;
    // 004af924  eb1f                   -jmp 0x4af945
    goto L_0x004af945;
L_0x004af926:
    // 004af926  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004af92b  e868ffffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004af930  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af932  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af934  7503                   -jne 0x4af939
    if (!cpu.flags.zf)
    {
        goto L_0x004af939;
    }
    // 004af936  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004af939:
    // 004af939  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004af93e  ebdf                   -jmp 0x4af91f
    goto L_0x004af91f;
L_0x004af940:
    // 004af940  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af942  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004af945:
    // 004af945  83fa02                 +cmp edx, 2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af948  74f6                   -je 0x4af940
    if (cpu.flags.zf)
    {
        goto L_0x004af940;
    }
    // 004af94a  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af94d  74f1                   -je 0x4af940
    if (cpu.flags.zf)
    {
        goto L_0x004af940;
    }
    // 004af94f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004af954  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4af957(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af957  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af958  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004af95d  e836ffffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004af962  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004af964  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004af969  e82affffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004af96e  83fa02                 +cmp edx, 2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af971  7405                   -je 0x4af978
    if (cpu.flags.zf)
    {
        goto L_0x004af978;
    }
    // 004af973  83fa03                 +cmp edx, 3
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af976  750a                   -jne 0x4af982
    if (!cpu.flags.zf)
    {
        goto L_0x004af982;
    }
L_0x004af978:
    // 004af978  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af97b  740c                   -je 0x4af989
    if (cpu.flags.zf)
    {
        goto L_0x004af989;
    }
    // 004af97d  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004af980  7407                   -je 0x4af989
    if (cpu.flags.zf)
    {
        goto L_0x004af989;
    }
L_0x004af982:
    // 004af982  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004af987  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af988  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004af989:
    // 004af989  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af98b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af98c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af98d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af98d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af98e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af98f  803da4d94c0000         +cmp byte ptr [0x4cd9a4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5036452) /* 0x4cd9a4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004af996  7519                   -jne 0x4af9b1
    if (!cpu.flags.zf)
    {
        goto L_0x004af9b1;
    }
    // 004af998  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004af99a  68f5f84a00             -push 0x4af8f5
    app->getMemory<x86::reg32>(cpu.esp-4) = 4913397 /*0x4af8f5*/;
    cpu.esp -= 4;
    // 004af99f  2eff1540554b00         -call dword ptr cs:[0x4b5540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937024) /* 0x4b5540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af9a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af9a8  7407                   -je 0x4af9b1
    if (cpu.flags.zf)
    {
        goto L_0x004af9b1;
    }
    // 004af9aa  c605a4d94c0001         -mov byte ptr [0x4cd9a4], 1
    app->getMemory<x86::reg8>(x86::reg32(5036452) /* 0x4cd9a4 */) = 1 /*0x1*/;
L_0x004af9b1:
    // 004af9b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af9b3  a0a4d94c00             -mov al, byte ptr [0x4cd9a4]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5036452) /* 0x4cd9a4 */);
    // 004af9b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af9b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af9ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af9bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af9bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af9bc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af9bd  803da4d94c0000         +cmp byte ptr [0x4cd9a4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5036452) /* 0x4cd9a4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004af9c4  741a                   -je 0x4af9e0
    if (cpu.flags.zf)
    {
        goto L_0x004af9e0;
    }
    // 004af9c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004af9c8  68f5f84a00             -push 0x4af8f5
    app->getMemory<x86::reg32>(cpu.esp-4) = 4913397 /*0x4af8f5*/;
    cpu.esp -= 4;
    // 004af9cd  2eff1540554b00         -call dword ptr cs:[0x4b5540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937024) /* 0x4b5540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004af9d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af9d6  7408                   -je 0x4af9e0
    if (cpu.flags.zf)
    {
        goto L_0x004af9e0;
    }
    // 004af9d8  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004af9da  8815a4d94c00           -mov byte ptr [0x4cd9a4], dl
    app->getMemory<x86::reg8>(x86::reg32(5036452) /* 0x4cd9a4 */) = cpu.dl;
L_0x004af9e0:
    // 004af9e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004af9e2  a0a4d94c00             -mov al, byte ptr [0x4cd9a4]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5036452) /* 0x4cd9a4 */);
    // 004af9e7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004af9e9  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004af9ec  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004af9f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af9f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004af9f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af9f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004af9f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004af9f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af9fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af9fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af9fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af9fe  e895feffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004afa03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004afa05  83fb02                 +cmp ebx, 2
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
    // 004afa08  0f82db000000           -jb 0x4afae9
    if (cpu.flags.cf)
    {
        return sub_4afae9(app, cpu);
    }
    // 004afa0e  0f86df000000           -jbe 0x4afaf3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4afaf3(app, cpu);
    }
    // 004afa14  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afa17  0f86ec000000           -jbe 0x4afb09
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4afb09(app, cpu);
    }
    // 004afa1d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004afa22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4af9f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004af9f9;
    // 004af9f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_entry_0x004af9f9:
    // 004af9f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af9fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af9fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af9fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af9fe  e895feffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004afa03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004afa05  83fb02                 +cmp ebx, 2
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
    // 004afa08  0f82db000000           -jb 0x4afae9
    if (cpu.flags.cf)
    {
        return sub_4afae9(app, cpu);
    }
    // 004afa0e  0f86df000000           -jbe 0x4afaf3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4afaf3(app, cpu);
    }
    // 004afa14  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afa17  0f86ec000000           -jbe 0x4afb09
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4afb09(app, cpu);
    }
    // 004afa1d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004afa22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afa1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004afa1d;
    // 004af9f4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004af9f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004af9fa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004af9fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004af9fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004af9fe  e895feffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004afa03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004afa05  83fb02                 +cmp ebx, 2
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
    // 004afa08  0f82db000000           -jb 0x4afae9
    if (cpu.flags.cf)
    {
        return sub_4afae9(app, cpu);
    }
    // 004afa0e  0f86df000000           -jbe 0x4afaf3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4afaf3(app, cpu);
    }
    // 004afa14  83fb0c                 +cmp ebx, 0xc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afa17  0f86ec000000           -jbe 0x4afb09
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4afb09(app, cpu);
    }
L_entry_0x004afa1d:
    // 004afa1d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004afa22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afa26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afa26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afa27  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afa28  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afa29  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004afa2b  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004afa30  e863feffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004afa35  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004afa37  83f801                 +cmp eax, 1
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
    // 004afa3a  7425                   -je 0x4afa61
    if (cpu.flags.zf)
    {
        goto L_0x004afa61;
    }
    // 004afa3c  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afa3f  7420                   -je 0x4afa61
    if (cpu.flags.zf)
    {
        goto L_0x004afa61;
    }
    // 004afa41  83f803                 +cmp eax, 3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afa44  741b                   -je 0x4afa61
    if (cpu.flags.zf)
    {
        goto L_0x004afa61;
    }
    // 004afa46  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004afa4b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004afa4d  e80afeffff             -call 0x4af85c
    cpu.esp -= 4;
    sub_4af85c(app, cpu);
    if (cpu.terminate) return;
    // 004afa52  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004afa57  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004afa59  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afa5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afa5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004afa61:
    // 004afa61  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004afa66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afa6a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afa6a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afa6b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afa6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afa6d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004afa6f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004afa71  83f801                 +cmp eax, 1
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
    // 004afa74  7c05                   -jl 0x4afa7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004afa7b;
    }
    // 004afa76  83f80c                 +cmp eax, 0xc
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
    // 004afa79  7e13                   -jle 0x4afa8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afa8e;
    }
L_0x004afa7b:
    // 004afa7b  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004afa80  e8bb61feff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 004afa85  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004afa8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa8b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afa8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004afa8e:
    // 004afa8e  c70580c84c00f4f94a00   -mov dword ptr [0x4cc880], 0x4af9f4
    app->getMemory<x86::reg32>(x86::reg32(5032064) /* 0x4cc880 */) = 4913652 /*0x4af9f4*/;
    // 004afa98  83f902                 +cmp ecx, 2
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
    // 004afa9b  741f                   -je 0x4afabc
    if (cpu.flags.zf)
    {
        goto L_0x004afabc;
    }
    // 004afa9d  83f903                 +cmp ecx, 3
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
    // 004afaa0  741a                   -je 0x4afabc
    if (cpu.flags.zf)
    {
        goto L_0x004afabc;
    }
    // 004afaa2  e813feffff             -call 0x4af8ba
    cpu.esp -= 4;
    sub_4af8ba(app, cpu);
    if (cpu.terminate) return;
    // 004afaa7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afaa9  7411                   -je 0x4afabc
    if (cpu.flags.zf)
    {
        goto L_0x004afabc;
    }
    // 004afaab  83fb02                 +cmp ebx, 2
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
    // 004afaae  750c                   -jne 0x4afabc
    if (!cpu.flags.zf)
    {
        goto L_0x004afabc;
    }
    // 004afab0  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 004afab5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afab7  e8aa340000             -call 0x4b2f66
    cpu.esp -= 4;
    sub_4b2f66(app, cpu);
    if (cpu.terminate) return;
L_0x004afabc:
    // 004afabc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afabe  e8d5fdffff             -call 0x4af898
    cpu.esp -= 4;
    sub_4af898(app, cpu);
    if (cpu.terminate) return;
    // 004afac3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004afac5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afac7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afac9  e88efdffff             -call 0x4af85c
    cpu.esp -= 4;
    sub_4af85c(app, cpu);
    if (cpu.terminate) return;
    // 004aface  e884feffff             -call 0x4af957
    cpu.esp -= 4;
    sub_4af957(app, cpu);
    if (cpu.terminate) return;
    // 004afad3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afad5  7407                   -je 0x4afade
    if (cpu.flags.zf)
    {
        goto L_0x004afade;
    }
    // 004afad7  e8b1feffff             -call 0x4af98d
    cpu.esp -= 4;
    sub_4af98d(app, cpu);
    if (cpu.terminate) return;
    // 004afadc  eb05                   -jmp 0x4afae3
    goto L_0x004afae3;
L_0x004afade:
    // 004afade  e8d8feffff             -call 0x4af9bb
    cpu.esp -= 4;
    sub_4af9bb(app, cpu);
    if (cpu.terminate) return;
L_0x004afae3:
    // 004afae3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004afae5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afae6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afae7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afae8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afae9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afae9  83fb01                 +cmp ebx, 1
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
    // 004afaec  7411                   -je 0x4afaff
    if (cpu.flags.zf)
    {
        goto L_0x004afaff;
    }
    // 004afaee  e92affffff             -jmp 0x4afa1d
    return sub_4afa1d(app, cpu);
    // 004afaf3  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 004afaf8  e829ffffff             -call 0x4afa26
    cpu.esp -= 4;
    sub_4afa26(app, cpu);
    if (cpu.terminate) return;
    // 004afafd  eb37                   -jmp 0x4afb36
    goto L_0x004afb36;
L_0x004afaff:
    // 004afaff  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afb02  7505                   -jne 0x4afb09
    if (!cpu.flags.zf)
    {
        goto L_0x004afb09;
    }
    // 004afb04  e8fdeafeff             -call 0x49e606
    cpu.esp -= 4;
    sub_49e606(app, cpu);
    if (cpu.terminate) return;
L_0x004afb09:
    // 004afb09  83f901                 +cmp ecx, 1
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
    // 004afb0c  741a                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb0e  83f902                 +cmp ecx, 2
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
    // 004afb11  7415                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb13  83f903                 +cmp ecx, 3
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
    // 004afb16  7410                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb18  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004afb1d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afb1f  e838fdffff             -call 0x4af85c
    cpu.esp -= 4;
    sub_4af85c(app, cpu);
    if (cpu.terminate) return;
    // 004afb24  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afb26  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004afb28:
    // 004afb28  e82afeffff             -call 0x4af957
    cpu.esp -= 4;
    sub_4af957(app, cpu);
    if (cpu.terminate) return;
    // 004afb2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afb2f  7505                   -jne 0x4afb36
    if (!cpu.flags.zf)
    {
        goto L_0x004afb36;
    }
    // 004afb31  e885feffff             -call 0x4af9bb
    cpu.esp -= 4;
    sub_4af9bb(app, cpu);
    if (cpu.terminate) return;
L_0x004afb36:
    // 004afb36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afb38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afaf3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004afaf3;
    // 004afae9  83fb01                 +cmp ebx, 1
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
    // 004afaec  7411                   -je 0x4afaff
    if (cpu.flags.zf)
    {
        goto L_0x004afaff;
    }
    // 004afaee  e92affffff             -jmp 0x4afa1d
    return sub_4afa1d(app, cpu);
L_entry_0x004afaf3:
    // 004afaf3  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 004afaf8  e829ffffff             -call 0x4afa26
    cpu.esp -= 4;
    sub_4afa26(app, cpu);
    if (cpu.terminate) return;
    // 004afafd  eb37                   -jmp 0x4afb36
    goto L_0x004afb36;
L_0x004afaff:
    // 004afaff  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afb02  7505                   -jne 0x4afb09
    if (!cpu.flags.zf)
    {
        goto L_0x004afb09;
    }
    // 004afb04  e8fdeafeff             -call 0x49e606
    cpu.esp -= 4;
    sub_49e606(app, cpu);
    if (cpu.terminate) return;
L_0x004afb09:
    // 004afb09  83f901                 +cmp ecx, 1
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
    // 004afb0c  741a                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb0e  83f902                 +cmp ecx, 2
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
    // 004afb11  7415                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb13  83f903                 +cmp ecx, 3
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
    // 004afb16  7410                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb18  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004afb1d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afb1f  e838fdffff             -call 0x4af85c
    cpu.esp -= 4;
    sub_4af85c(app, cpu);
    if (cpu.terminate) return;
    // 004afb24  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afb26  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004afb28:
    // 004afb28  e82afeffff             -call 0x4af957
    cpu.esp -= 4;
    sub_4af957(app, cpu);
    if (cpu.terminate) return;
    // 004afb2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afb2f  7505                   -jne 0x4afb36
    if (!cpu.flags.zf)
    {
        goto L_0x004afb36;
    }
    // 004afb31  e885feffff             -call 0x4af9bb
    cpu.esp -= 4;
    sub_4af9bb(app, cpu);
    if (cpu.terminate) return;
L_0x004afb36:
    // 004afb36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afb38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afb09(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004afb09;
    // 004afae9  83fb01                 +cmp ebx, 1
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
    // 004afaec  7411                   -je 0x4afaff
    if (cpu.flags.zf)
    {
        goto L_0x004afaff;
    }
    // 004afaee  e92affffff             -jmp 0x4afa1d
    return sub_4afa1d(app, cpu);
    // 004afaf3  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 004afaf8  e829ffffff             -call 0x4afa26
    cpu.esp -= 4;
    sub_4afa26(app, cpu);
    if (cpu.terminate) return;
    // 004afafd  eb37                   -jmp 0x4afb36
    goto L_0x004afb36;
L_0x004afaff:
    // 004afaff  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afb02  7505                   -jne 0x4afb09
    if (!cpu.flags.zf)
    {
        goto L_0x004afb09;
    }
    // 004afb04  e8fdeafeff             -call 0x49e606
    cpu.esp -= 4;
    sub_49e606(app, cpu);
    if (cpu.terminate) return;
L_0x004afb09:
L_entry_0x004afb09:
    // 004afb09  83f901                 +cmp ecx, 1
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
    // 004afb0c  741a                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb0e  83f902                 +cmp ecx, 2
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
    // 004afb11  7415                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb13  83f903                 +cmp ecx, 3
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
    // 004afb16  7410                   -je 0x4afb28
    if (cpu.flags.zf)
    {
        goto L_0x004afb28;
    }
    // 004afb18  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004afb1d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afb1f  e838fdffff             -call 0x4af85c
    cpu.esp -= 4;
    sub_4af85c(app, cpu);
    if (cpu.terminate) return;
    // 004afb24  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afb26  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004afb28:
    // 004afb28  e82afeffff             -call 0x4af957
    cpu.esp -= 4;
    sub_4af957(app, cpu);
    if (cpu.terminate) return;
    // 004afb2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afb2f  7505                   -jne 0x4afb36
    if (!cpu.flags.zf)
    {
        goto L_0x004afb36;
    }
    // 004afb31  e885feffff             -call 0x4af9bb
    cpu.esp -= 4;
    sub_4af9bb(app, cpu);
    if (cpu.terminate) return;
L_0x004afb36:
    // 004afb36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afb38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afb3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afb3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afb3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afb3e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afb3f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004afb40  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004afb41  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x004afb46:
    // 004afb46  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afb4c  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004afb4f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004afb51  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004afb53  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 004afb56  8db23cd94c00           -lea esi, [edx + 0x4cd93c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(5036348) /* 0x4cd93c */);
    // 004afb5c  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afb5f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afb60  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004afb61  83fa68                 +cmp edx, 0x68
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(104 /*0x68*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afb64  75e0                   -jne 0x4afb46
    if (!cpu.flags.zf)
    {
        goto L_0x004afb46;
    }
    // 004afb66  badcf84a00             -mov edx, 0x4af8dc
    cpu.edx = 4913372 /*0x4af8dc*/;
    // 004afb6b  bbf9f94a00             -mov ebx, 0x4af9f9
    cpu.ebx = 4913657 /*0x4af9f9*/;
    // 004afb70  89156cd64c00           -mov dword ptr [0x4cd66c], edx
    app->getMemory<x86::reg32>(x86::reg32(5035628) /* 0x4cd66c */) = cpu.edx;
    // 004afb76  891d70d64c00           -mov dword ptr [0x4cd670], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035632) /* 0x4cd670 */) = cpu.ebx;
    // 004afb7c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004afb7d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afb81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afb82(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afb82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afb83  e8cffdffff             -call 0x4af957
    cpu.esp -= 4;
    sub_4af957(app, cpu);
    if (cpu.terminate) return;
    // 004afb88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afb8a  7423                   -je 0x4afbaf
    if (cpu.flags.zf)
    {
        goto L_0x004afbaf;
    }
    // 004afb8c  e82afeffff             -call 0x4af9bb
    cpu.esp -= 4;
    sub_4af9bb(app, cpu);
    if (cpu.terminate) return;
    // 004afb91  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004afb96  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004afb9b  e8bcfcffff             -call 0x4af85c
    cpu.esp -= 4;
    sub_4af85c(app, cpu);
    if (cpu.terminate) return;
    // 004afba0  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004afba5  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004afbaa  e8adfcffff             -call 0x4af85c
    cpu.esp -= 4;
    sub_4af85c(app, cpu);
    if (cpu.terminate) return;
L_0x004afbaf:
    // 004afbaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afbb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afbb1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afbb1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afbb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afbb3  ba3cfb4a00             -mov edx, 0x4afb3c
    cpu.edx = 4913980 /*0x4afb3c*/;
    // 004afbb8  bb82fb4a00             -mov ebx, 0x4afb82
    cpu.ebx = 4914050 /*0x4afb82*/;
    // 004afbbd  891584c14c00           -mov dword ptr [0x4cc184], edx
    app->getMemory<x86::reg32>(x86::reg32(5030276) /* 0x4cc184 */) = cpu.edx;
    // 004afbc3  891d88c14c00           -mov dword ptr [0x4cc188], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030280) /* 0x4cc188 */) = cpu.ebx;
    // 004afbc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afbca  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afbcb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afbcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afbcc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afbcd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afbce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afbcf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afbd0  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004afbd3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004afbd5  a1a8d94c00             -mov eax, dword ptr [0x4cd9a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5036456) /* 0x4cd9a8 */);
    // 004afbda  83f801                 +cmp eax, 1
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
    // 004afbdd  725e                   -jb 0x4afc3d
    if (cpu.flags.cf)
    {
        goto L_0x004afc3d;
    }
    // 004afbdf  7607                   -jbe 0x4afbe8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004afbe8;
    }
    // 004afbe1  83f802                 +cmp eax, 2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afbe4  7439                   -je 0x4afc1f
    if (cpu.flags.zf)
    {
        goto L_0x004afc1f;
    }
    // 004afbe6  eb55                   -jmp 0x4afc3d
    goto L_0x004afc3d;
L_0x004afbe8:
    // 004afbe8  8b1dac755400           -mov ebx, dword ptr [0x5475ac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5535148) /* 0x5475ac */);
    // 004afbee  4b                     -dec ebx
    (cpu.ebx)--;
    // 004afbef  8b0da8755400           -mov ecx, dword ptr [0x5475a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5535144) /* 0x5475a8 */);
    // 004afbf5  891dac755400           -mov dword ptr [0x5475ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5535148) /* 0x5475ac */) = cpu.ebx;
    // 004afbfb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004afbfd  740c                   -je 0x4afc0b
    if (cpu.flags.zf)
    {
        goto L_0x004afc0b;
    }
    // 004afbff  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004afc01  7512                   -jne 0x4afc15
    if (!cpu.flags.zf)
    {
        goto L_0x004afc15;
    }
    // 004afc03  891da8d94c00           -mov dword ptr [0x4cd9a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5036456) /* 0x4cd9a8 */) = cpu.ebx;
    // 004afc09  eb0a                   -jmp 0x4afc15
    goto L_0x004afc15;
L_0x004afc0b:
    // 004afc0b  c705a8d94c0002000000   -mov dword ptr [0x4cd9a8], 2
    app->getMemory<x86::reg32>(x86::reg32(5036456) /* 0x4cd9a8 */) = 2 /*0x2*/;
L_0x004afc15:
    // 004afc15  a1a8755400             -mov eax, dword ptr [0x5475a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5535144) /* 0x5475a8 */);
    // 004afc1a  e9b2000000             -jmp 0x4afcd1
    goto L_0x004afcd1;
L_0x004afc1f:
    // 004afc1f  833dac75540000         +cmp dword ptr [0x5475ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5535148) /* 0x5475ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afc26  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004afc29  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004afc2e  a3a8d94c00             -mov dword ptr [0x4cd9a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5036456) /* 0x4cd9a8 */) = cpu.eax;
    // 004afc33  a1a4755400             -mov eax, dword ptr [0x5475a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5535140) /* 0x5475a4 */);
    // 004afc38  e994000000             -jmp 0x4afcd1
    goto L_0x004afcd1;
L_0x004afc3d:
    // 004afc3d  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004afc41  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004afc42  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004afc44  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004afc48  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004afc49  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afc4a  2eff152c554b00         -call dword ptr cs:[0x4b552c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937004) /* 0x4b552c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afc51  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afc53  0f8473000000           -je 0x4afccc
    if (cpu.flags.zf)
    {
        goto L_0x004afccc;
    }
    // 004afc59  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004afc5b  e851fbffff             -call 0x4af7b1
    cpu.esp -= 4;
    sub_4af7b1(app, cpu);
    if (cpu.terminate) return;
    // 004afc60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afc62  74d9                   -je 0x4afc3d
    if (cpu.flags.zf)
    {
        goto L_0x004afc3d;
    }
    // 004afc64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afc66  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004afc6b  48                     -dec eax
    (cpu.eax)--;
    // 004afc6c  a3ac755400             -mov dword ptr [0x5475ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5535148) /* 0x5475ac */) = cpu.eax;
    // 004afc71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afc73  8a44240e               -mov al, byte ptr [esp + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 004afc77  a3a8755400             -mov dword ptr [0x5475a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5535144) /* 0x5475a8 */) = cpu.eax;
    // 004afc7c  f644241101             +test byte ptr [esp + 0x11], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(17) /* 0x11 */) & 1 /*0x1*/));
    // 004afc81  7509                   -jne 0x4afc8c
    if (!cpu.flags.zf)
    {
        goto L_0x004afc8c;
    }
    // 004afc83  833da875540000         +cmp dword ptr [0x5475a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5535144) /* 0x5475a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afc8a  7524                   -jne 0x4afcb0
    if (!cpu.flags.zf)
    {
        goto L_0x004afcb0;
    }
L_0x004afc8c:
    // 004afc8c  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 004afc91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afc93  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004afc95  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004afc9a  890da8755400           -mov dword ptr [0x5475a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5535144) /* 0x5475a8 */) = cpu.ecx;
    // 004afca0  8935a8d94c00           -mov dword ptr [0x4cd9a8], esi
    app->getMemory<x86::reg32>(x86::reg32(5036456) /* 0x4cd9a8 */) = cpu.esi;
    // 004afca6  a3a4755400             -mov dword ptr [0x5475a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5535140) /* 0x5475a4 */) = cpu.eax;
    // 004afcab  e965ffffff             -jmp 0x4afc15
    goto L_0x004afc15;
L_0x004afcb0:
    // 004afcb0  833dac75540000         +cmp dword ptr [0x5475ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5535148) /* 0x5475ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afcb7  0f8458ffffff           -je 0x4afc15
    if (cpu.flags.zf)
    {
        goto L_0x004afc15;
    }
    // 004afcbd  c705a8d94c0001000000   -mov dword ptr [0x4cd9a8], 1
    app->getMemory<x86::reg32>(x86::reg32(5036456) /* 0x4cd9a8 */) = 1 /*0x1*/;
    // 004afcc7  e949ffffff             -jmp 0x4afc15
    goto L_0x004afc15;
L_0x004afccc:
    // 004afccc  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004afcd1:
    // 004afcd1  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004afcd4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afcd5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afcd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afcd7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afcd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afcd9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afcd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afcda  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afcdb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afcdc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afcdd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004afce0  a1ecab4c00             -mov eax, dword ptr [0x4cabec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024748) /* 0x4cabec */);
    // 004afce5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afce7  740a                   -je 0x4afcf3
    if (cpu.flags.zf)
    {
        goto L_0x004afcf3;
    }
    // 004afce9  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004afceb  8935ecab4c00           -mov dword ptr [0x4cabec], esi
    app->getMemory<x86::reg32>(x86::reg32(5024748) /* 0x4cabec */) = cpu.esi;
    // 004afcf1  eb5a                   -jmp 0x4afd4d
    goto L_0x004afd4d;
L_0x004afcf3:
    // 004afcf3  833dc4c14c0000         +cmp dword ptr [0x4cc1c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030340) /* 0x4cc1c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afcfa  7410                   -je 0x4afd0c
    if (cpu.flags.zf)
    {
        goto L_0x004afd0c;
    }
    // 004afcfc  ff1590c14c00           -call dword ptr [0x4cc190]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030288) /* 0x4cc190 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd02  ff15c4c14c00           -call dword ptr [0x4cc1c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030340) /* 0x4cc1c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd08  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afd0a  eb3f                   -jmp 0x4afd4b
    goto L_0x004afd4b;
L_0x004afd0c:
    // 004afd0c  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd12  e82cfbffff             -call 0x4af843
    cpu.esp -= 4;
    sub_4af843(app, cpu);
    if (cpu.terminate) return;
    // 004afd17  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004afd19  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004afd1b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004afd1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afd1d  2eff158c544b00         -call dword ptr cs:[0x4b548c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936844) /* 0x4b548c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd24  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004afd26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afd27  2eff1544554b00         -call dword ptr cs:[0x4b5544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937028) /* 0x4b5544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd2e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afd30  e897feffff             -call 0x4afbcc
    cpu.esp -= 4;
    sub_4afbcc(app, cpu);
    if (cpu.terminate) return;
    // 004afd35  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004afd38  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afd39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afd3a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afd3c  2eff1544554b00         -call dword ptr cs:[0x4b5544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937028) /* 0x4b5544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004afd45  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004afd4b:
    // 004afd4b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004afd4d:
    // 004afd4d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004afd50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afd51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afd52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afd53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afd54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afd55(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afd55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afd56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afd57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afd58  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afd5b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004afd5d  8b15ccc14c00           -mov edx, dword ptr [0x4cc1cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030348) /* 0x4cc1cc */);
    // 004afd63  885c2404               -mov byte ptr [esp + 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 004afd67  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004afd69  7415                   -je 0x4afd80
    if (cpu.flags.zf)
    {
        goto L_0x004afd80;
    }
    // 004afd6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004afd70  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004afd72  ff1590c14c00           -call dword ptr [0x4cc190]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030288) /* 0x4cc190 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd78  ff15ccc14c00           -call dword ptr [0x4cc1cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030348) /* 0x4cc1cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd7e  eb30                   -jmp 0x4afdb0
    goto L_0x004afdb0;
L_0x004afd80:
    // 004afd80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004afd85  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afd8b  e8befaffff             -call 0x4af84e
    cpu.esp -= 4;
    sub_4af84e(app, cpu);
    if (cpu.terminate) return;
    // 004afd90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afd91  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004afd95  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afd96  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004afd98  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004afd9c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afd9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004afd9e  2eff15ac554b00         -call dword ptr cs:[0x4b55ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937132) /* 0x4b55ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afda5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004afdaa  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004afdb0:
    // 004afdb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004afdb2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004afdb5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afdb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afdb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afdb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afdb9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004afdb9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004afdba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004afdbb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004afdbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afdbd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004afdbe  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004afdc1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afdc3  83f8ff                 +cmp eax, -1
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
    // 004afdc6  750e                   -jne 0x4afdd6
    if (!cpu.flags.zf)
    {
        goto L_0x004afdd6;
    }
    // 004afdc8  2eff1570544b00         -call dword ptr cs:[0x4b5470]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936816) /* 0x4b5470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004afdcf:
    // 004afdcf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004afdd1  e98e000000             -jmp 0x4afe64
    goto L_0x004afe64;
L_0x004afdd6:
    // 004afdd6  83f8fe                 +cmp eax, -2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afdd9  7509                   -jne 0x4afde4
    if (!cpu.flags.zf)
    {
        goto L_0x004afde4;
    }
    // 004afddb  2eff15dc544b00         -call dword ptr cs:[0x4b54dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936924) /* 0x4b54dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afde2  ebeb                   -jmp 0x4afdcf
    goto L_0x004afdcf;
L_0x004afde4:
    // 004afde4  83f8fd                 +cmp eax, -3
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afde7  7526                   -jne 0x4afe0f
    if (!cpu.flags.zf)
    {
        goto L_0x004afe0f;
    }
    // 004afde9  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 004afdee  b890705400             -mov eax, 0x547090
    cpu.eax = 5533840 /*0x547090*/;
    // 004afdf3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004afdf5  e8c543fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004afdfa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004afdfc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004afdfe  89158c705400           -mov dword ptr [0x54708c], edx
    app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */) = cpu.edx;
    // 004afe04  8915acd94c00           -mov dword ptr [0x4cd9ac], edx
    app->getMemory<x86::reg32>(x86::reg32(5036460) /* 0x4cd9ac */) = cpu.edx;
    // 004afe0a  e9ed000000             -jmp 0x4afefc
    goto L_0x004afefc;
L_0x004afe0f:
    // 004afe0f  83f8fc                 +cmp eax, -4
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afe12  7550                   -jne 0x4afe64
    if (!cpu.flags.zf)
    {
        goto L_0x004afe64;
    }
    // 004afe14  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 004afe19  b890705400             -mov eax, 0x547090
    cpu.eax = 5533840 /*0x547090*/;
    // 004afe1e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004afe20  e89a43fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004afe25  b881000000             -mov eax, 0x81
    cpu.eax = 129 /*0x81*/;
    // 004afe2a  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
L_0x004afe2c:
    // 004afe2c  40                     -inc eax
    (cpu.eax)++;
    // 004afe2d  889090705400           -mov byte ptr [eax + 0x547090], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533840) /* 0x547090 */) = cpu.dl;
    // 004afe33  3d9f000000             +cmp eax, 0x9f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(159 /*0x9f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afe38  7ef2                   -jle 0x4afe2c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afe2c;
    }
    // 004afe3a  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 004afe3f  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
L_0x004afe41:
    // 004afe41  40                     -inc eax
    (cpu.eax)++;
    // 004afe42  88b090705400           -mov byte ptr [eax + 0x547090], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533840) /* 0x547090 */) = cpu.dh;
    // 004afe48  3dfc000000             +cmp eax, 0xfc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004afe4d  7ef2                   -jle 0x4afe41
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afe41;
    }
    // 004afe4f  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004afe54  b8a4030000             -mov eax, 0x3a4
    cpu.eax = 932 /*0x3a4*/;
    // 004afe59  892d8c705400           -mov dword ptr [0x54708c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */) = cpu.ebp;
    // 004afe5f  e989000000             -jmp 0x4afeed
    goto L_0x004afeed;
L_0x004afe64:
    // 004afe64  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004afe66  7505                   -jne 0x4afe6d
    if (!cpu.flags.zf)
    {
        goto L_0x004afe6d;
    }
    // 004afe68  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004afe6d:
    // 004afe6d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004afe6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004afe70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004afe71  2eff1574544b00         -call dword ptr cs:[0x4b5474]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936820) /* 0x4b5474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004afe78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004afe7a  750a                   -jne 0x4afe86
    if (!cpu.flags.zf)
    {
        goto L_0x004afe86;
    }
    // 004afe7c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004afe81  e976000000             -jmp 0x4afefc
    goto L_0x004afefc;
L_0x004afe86:
    // 004afe86  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 004afe8b  b890705400             -mov eax, 0x547090
    cpu.eax = 5533840 /*0x547090*/;
    // 004afe90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004afe92  e82843fdff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 004afe97  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004afe99  8a642406               -mov ah, byte ptr [esp + 6]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 004afe9d  890d8c705400           -mov dword ptr [0x54708c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */) = cpu.ecx;
    // 004afea3  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004afea5  740a                   -je 0x4afeb1
    if (cpu.flags.zf)
    {
        goto L_0x004afeb1;
    }
    // 004afea7  c7058c70540001000000   -mov dword ptr [0x54708c], 1
    app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */) = 1 /*0x1*/;
L_0x004afeb1:
    // 004afeb1  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004afeb3  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 004afeb5  eb1c                   -jmp 0x4afed3
    goto L_0x004afed3;
L_0x004afeb7:
    // 004afeb7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004afeb9  8a441406               -mov al, byte ptr [esp + edx + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.edx * 1);
    // 004afebd  eb07                   -jmp 0x4afec6
    goto L_0x004afec6;
L_0x004afebf:
    // 004afebf  40                     -inc eax
    (cpu.eax)++;
    // 004afec0  888890705400           -mov byte ptr [eax + 0x547090], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533840) /* 0x547090 */) = cpu.cl;
L_0x004afec6:
    // 004afec6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004afec8  8a5c1407               -mov bl, byte ptr [esp + edx + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.edx * 1);
    // 004afecc  39d8                   +cmp eax, ebx
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
    // 004afece  7eef                   -jle 0x4afebf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004afebf;
    }
    // 004afed0  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004afed3:
    // 004afed3  807c140600             +cmp byte ptr [esp + edx + 6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004afed8  75dd                   -jne 0x4afeb7
    if (!cpu.flags.zf)
    {
        goto L_0x004afeb7;
    }
    // 004afeda  807c140700             +cmp byte ptr [esp + edx + 7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.edx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004afedf  75d6                   -jne 0x4afeb7
    if (!cpu.flags.zf)
    {
        goto L_0x004afeb7;
    }
    // 004afee1  83fe01                 +cmp esi, 1
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
    // 004afee4  750e                   -jne 0x4afef4
    if (!cpu.flags.zf)
    {
        goto L_0x004afef4;
    }
    // 004afee6  2eff15dc544b00         -call dword ptr cs:[0x4b54dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936924) /* 0x4b54dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004afeed:
    // 004afeed  a3acd94c00             -mov dword ptr [0x4cd9ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5036460) /* 0x4cd9ac */) = cpu.eax;
    // 004afef2  eb06                   -jmp 0x4afefa
    goto L_0x004afefa;
L_0x004afef4:
    // 004afef4  8935acd94c00           -mov dword ptr [0x4cd9ac], esi
    app->getMemory<x86::reg32>(x86::reg32(5036460) /* 0x4cd9ac */) = cpu.esi;
L_0x004afefa:
    // 004afefa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004afefc:
    // 004afefc  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004afeff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aff00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aff01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aff02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aff03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aff04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aff05(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aff05  833d8c70540000         +cmp dword ptr [0x54708c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aff0c  741c                   -je 0x4aff2a
    if (cpu.flags.zf)
    {
        goto L_0x004aff2a;
    }
    // 004aff0e  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004aff10  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aff15  8a8091705400           -mov al, byte ptr [eax + 0x547091]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533841) /* 0x547091 */);
    // 004aff1b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004aff1d  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004aff22  7406                   -je 0x4aff2a
    if (cpu.flags.zf)
    {
        goto L_0x004aff2a;
    }
    // 004aff24  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004aff29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aff2a:
    // 004aff2a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004aff2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aff30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aff30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aff31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aff32  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aff34  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aff36  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004aff38:
    // 004aff38  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aff3a  763a                   -jbe 0x4aff76
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aff76;
    }
    // 004aff3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aff3e  e86f300000             -call 0x4b2fb2
    cpu.esp -= 4;
    sub_4b2fb2(app, cpu);
    if (cpu.terminate) return;
    // 004aff43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aff45  752f                   -jne 0x4aff76
    if (!cpu.flags.zf)
    {
        goto L_0x004aff76;
    }
    // 004aff47  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aff49  e864300000             -call 0x4b2fb2
    cpu.esp -= 4;
    sub_4b2fb2(app, cpu);
    if (cpu.terminate) return;
    // 004aff4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aff50  7524                   -jne 0x4aff76
    if (!cpu.flags.zf)
    {
        goto L_0x004aff76;
    }
    // 004aff52  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004aff54  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aff56  e893300000             -call 0x4b2fee
    cpu.esp -= 4;
    sub_4b2fee(app, cpu);
    if (cpu.terminate) return;
    // 004aff5b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aff5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aff5f  753e                   -jne 0x4aff9f
    if (!cpu.flags.zf)
    {
        goto L_0x004aff9f;
    }
    // 004aff61  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aff63  e8dd300000             -call 0x4b3045
    cpu.esp -= 4;
    sub_4b3045(app, cpu);
    if (cpu.terminate) return;
    // 004aff68  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aff6a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aff6c  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aff6d  e8d3300000             -call 0x4b3045
    cpu.esp -= 4;
    sub_4b3045(app, cpu);
    if (cpu.terminate) return;
    // 004aff72  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aff74  ebc2                   -jmp 0x4aff38
    goto L_0x004aff38;
L_0x004aff76:
    // 004aff76  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004aff78  7623                   -jbe 0x4aff9d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aff9d;
    }
    // 004aff7a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aff7c  e831300000             -call 0x4b2fb2
    cpu.esp -= 4;
    sub_4b2fb2(app, cpu);
    if (cpu.terminate) return;
    // 004aff81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aff83  750b                   -jne 0x4aff90
    if (!cpu.flags.zf)
    {
        goto L_0x004aff90;
    }
    // 004aff85  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aff87  e826300000             -call 0x4b2fb2
    cpu.esp -= 4;
    sub_4b2fb2(app, cpu);
    if (cpu.terminate) return;
    // 004aff8c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aff8e  740d                   -je 0x4aff9d
    if (cpu.flags.zf)
    {
        goto L_0x004aff9d;
    }
L_0x004aff90:
    // 004aff90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aff92  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aff94  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004aff96  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004aff98  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aff9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aff9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aff9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aff9d:
    // 004aff9d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004aff9f:
    // 004aff9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004affa0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004affa1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4affa2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004affa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004affa3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004affa5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004affa6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004affa7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004affa8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004affa9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004affac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004affae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004affb0  81fa00200000           +cmp edx, 0x2000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004affb6  7c05                   -jl 0x4affbd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004affbd;
    }
    // 004affb8  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x004affbd:
    // 004affbd  b9b0d94c00             -mov ecx, 0x4cd9b0
    cpu.ecx = 5036464 /*0x4cd9b0*/;
    // 004affc2  eb2e                   -jmp 0x4afff2
    goto L_0x004afff2;
L_0x004affc4:
    // 004affc4  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 004affc9  7422                   -je 0x4affed
    if (cpu.flags.zf)
    {
        goto L_0x004affed;
    }
    // 004affcb  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004affcf  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 004affd3  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004affd6  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004affd9  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004affdc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004affde  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004affe0  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004affe3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004affe5  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004affe7  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004affe9  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004affeb  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004affed:
    // 004affed  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 004affef  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x004afff2:
    // 004afff2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004afff4  7fce                   -jg 0x4affc4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004affc4;
    }
    // 004afff6  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004afff9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4afff6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004afff6;
    // 004affa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004affa3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004affa5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004affa6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004affa7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004affa8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004affa9  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004affac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004affae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004affb0  81fa00200000           +cmp edx, 0x2000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004affb6  7c05                   -jl 0x4affbd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004affbd;
    }
    // 004affb8  be00200000             -mov esi, 0x2000
    cpu.esi = 8192 /*0x2000*/;
L_0x004affbd:
    // 004affbd  b9b0d94c00             -mov ecx, 0x4cd9b0
    cpu.ecx = 5036464 /*0x4cd9b0*/;
    // 004affc2  eb2e                   -jmp 0x4afff2
    goto L_0x004afff2;
L_0x004affc4:
    // 004affc4  66f7c60100             +test si, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & 1 /*0x1*/));
    // 004affc9  7422                   -je 0x4affed
    if (cpu.flags.zf)
    {
        goto L_0x004affed;
    }
    // 004affcb  668b4108               -mov ax, word ptr [ecx + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004affcf  668945ec               -mov word ptr [ebp - 0x14], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ax;
    // 004affd3  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004affd6  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004affd9  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004affdc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004affde  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004affe0  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004affe3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004affe5  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004affe7  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004affe9  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004affeb  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004affed:
    // 004affed  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 004affef  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
L_0x004afff2:
    // 004afff2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004afff4  7fce                   -jg 0x4affc4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004affc4;
    }
L_entry_0x004afff6:
    // 004afff6  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004afff9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004afffe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4affff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004affff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b0000  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b0002  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0003  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0004  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b0005  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b0006  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b0009  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b000b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b000d  74e7                   -je 0x4afff6
    if (cpu.flags.zf)
    {
        return sub_4afff6(app, cpu);
    }
    // 004b000f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b0011  9b                     -wait 
    /*nothing*/;
    // 004b0012  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b0015  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0016  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b0018  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004b001b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b0020  bbff3f0000             -mov ebx, 0x3fff
    cpu.ebx = 16383 /*0x3fff*/;
    // 004b0025  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0026  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0029  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b002a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b002c  66895dec               -mov word ptr [ebp - 0x14], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.bx;
    // 004b0030  bb00000080             -mov ebx, 0x80000000
    cpu.ebx = 2147483648 /*0x80000000*/;
    // 004b0035  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 004b0038  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004b003b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b003d  7d1b                   -jge 0x4b005a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b005a;
    }
    // 004b003f  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b0042  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004b0044  e859ffffff             -call 0x4affa2
    cpu.esp -= 4;
    sub_4affa2(app, cpu);
    if (cpu.terminate) return;
    // 004b0049  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b004b  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b004e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0050  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0052  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0054  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0056  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0058  eb17                   -jmp 0x4b0071
    goto L_0x004b0071;
L_0x004b005a:
    // 004b005a  8d45e4                 -lea eax, [ebp - 0x1c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b005d  e840ffffff             -call 0x4affa2
    cpu.esp -= 4;
    sub_4affa2(app, cpu);
    if (cpu.terminate) return;
    // 004b0062  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b0064  8d55e4                 -lea edx, [ebp - 0x1c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004b0067  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b0069  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b006b  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b006d  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b006f  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004b0071:
    // 004b0071  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b0073  6689f0                 -mov ax, si
    cpu.ax = cpu.si;
    // 004b0076  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0077  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b007a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b007b  e976ffffff             -jmp 0x4afff6
    return sub_4afff6(app, cpu);
}

/* align: skip  */
void Application::sub_4b0080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b0080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b0081  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b0082  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b0084  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b0086  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b008c  7e12                   -jle 0x4b00a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b00a0;
    }
    // 004b008e  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 004b0093  e867ffffff             -call 0x4affff
    cpu.esp -= 4;
    sub_4affff(app, cpu);
    if (cpu.terminate) return;
    // 004b0098  81eb00100000           +sub ebx, 0x1000
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b009e  eb18                   -jmp 0x4b00b8
    goto L_0x004b00b8;
L_0x004b00a0:
    // 004b00a0  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b00a6  7d10                   -jge 0x4b00b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b00b8;
    }
    // 004b00a8  ba00f0ffff             -mov edx, 0xfffff000
    cpu.edx = 4294963200 /*0xfffff000*/;
    // 004b00ad  e84dffffff             -call 0x4affff
    cpu.esp -= 4;
    sub_4affff(app, cpu);
    if (cpu.terminate) return;
    // 004b00b2  81c300100000           -add ebx, 0x1000
    (cpu.ebx) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
L_0x004b00b8:
    // 004b00b8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b00ba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b00bc  e83effffff             -call 0x4affff
    cpu.esp -= 4;
    sub_4affff(app, cpu);
    if (cpu.terminate) return;
    // 004b00c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b00c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b00c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b00c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004b00c4  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004b00c6  6d                     -insd dword ptr es:[edi], dx
    NFS2_ASSERT(false);
    // 004b00c7  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00ca  a9014b007b             -test eax, 0x7b004b01
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2063616769 /*0x7b004b01*/));
    // 004b00cf  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00d2  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004b00d3  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00d6  6d                     -insd dword ptr es:[edi], dx
    NFS2_ASSERT(false);
    // 004b00d7  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b00db  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b00dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b00de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b00df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b00e0  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004b00e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b00e8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b00ea  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 004b00ed  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b00ef  9b                     -wait 
    /*nothing*/;
    // 004b00f0  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b00f3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b00f4  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004b00f7  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004b00fa  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b00ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0100  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0103  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0104  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b010b  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004b010f  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 004b0113  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004b0116  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004b0119  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004b011b  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004b011e  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 004b0122  7407                   -je 0x4b012b
    if (cpu.flags.zf)
    {
        goto L_0x004b012b;
    }
    // 004b0124  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x004b012b:
    // 004b012b  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004b012f  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b0136  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b013d  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004b0144  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0147  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004b014e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b0150  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004b0157  e8162f0000             -call 0x4b3072
    cpu.esp -= 4;
    sub_4b3072(app, cpu);
    if (cpu.terminate) return;
    // 004b015c  83f804                 +cmp eax, 4
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
    // 004b015f  0f8749010000           -ja 0x4b02ae
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b02ae;
    }
    // 004b0165  2eff2485c6004b00       -jmp dword ptr cs:[eax*4 + 0x4b00c6]
    cpu.ip = app->getMemory<x86::reg32>(4915398 + cpu.eax * 4); goto dynamic_jump;
  case 0x004b016d:
    // 004b016d  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004b0174:
    // 004b0174  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b0176  e933010000             -jmp 0x4b02ae
    goto L_0x004b02ae;
  case 0x004b017b:
    // 004b017b  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b017e  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 004b0181  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 004b0185  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x004b0189:
    // 004b0189  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004b018d  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 004b0194  e970030000             -jmp 0x4b0509
    return sub_4b0509(app, cpu);
  case 0x004b0199:
    // 004b0199  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b019c  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 004b019f  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 004b01a3  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 004b01a7  ebe0                   -jmp 0x4b0189
    goto L_0x004b0189;
  case 0x004b01a9:
    // 004b01a9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b01ab  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01af  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 004b01b5  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 004b01bb  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 004b01c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b01c2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b01c5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b01c7  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b01ca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b01cc  0f84dc000000           -je 0x4b02ae
    if (cpu.flags.zf)
    {
        goto L_0x004b02ae;
    }
    // 004b01d2  7d0f                   -jge 0x4b01e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b01e3;
    }
    // 004b01d4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b01d6  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b01d9  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b01dc  f7d9                   +neg ecx
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
    // 004b01de  e9bf000000             -jmp 0x4b02a2
    goto L_0x004b02a2;
L_0x004b01e3:
    // 004b01e3  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01e6  6681fa1940             +cmp dx, 0x4019
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16409 /*0x4019*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b01eb  7287                   -jb 0x4b0174
    if (cpu.flags.cf)
    {
        goto L_0x004b0174;
    }
    // 004b01ed  750d                   -jne 0x4b01fc
    if (!cpu.flags.zf)
    {
        goto L_0x004b01fc;
    }
    // 004b01ef  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b01f6  0f8278ffffff           -jb 0x4b0174
    if (cpu.flags.cf)
    {
        goto L_0x004b0174;
    }
L_0x004b01fc:
    // 004b01fc  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01ff  663d3440               +cmp ax, 0x4034
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16436 /*0x4034*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b0203  7220                   -jb 0x4b0225
    if (cpu.flags.cf)
    {
        goto L_0x004b0225;
    }
    // 004b0205  0f8594000000           -jne 0x4b029f
    if (!cpu.flags.zf)
    {
        goto L_0x004b029f;
    }
    // 004b020b  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004b020e  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2384185791 /*0x8e1bc9bf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0214  720f                   -jb 0x4b0225
    if (cpu.flags.cf)
    {
        goto L_0x004b0225;
    }
    // 004b0216  0f8583000000           -jne 0x4b029f
    if (!cpu.flags.zf)
    {
        goto L_0x004b029f;
    }
    // 004b021c  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0223  737a                   -jae 0x4b029f
    if (!cpu.flags.cf)
    {
        goto L_0x004b029f;
    }
L_0x004b0225:
    // 004b0225  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 004b022a  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b022d  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0230  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 004b0234  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004b0239  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b023b  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 004b023e  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b0241  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 004b0244  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0246  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0248  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b024a  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b024c  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b024f  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b0252  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b0255  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0257  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0258  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0259  9b                     -wait 
    /*nothing*/;
    // 004b025a  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b025d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b025e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b025f  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 004b0262  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0263  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0266  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0267  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004b026b  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b026e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b026f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0270  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0272  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0273  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b0276  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0277  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0279  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b027c  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b027f  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0281  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0283  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0285  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0287  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b028a  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b028d  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0290  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004b0295  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0297  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0299  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b029b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b029d  eb0f                   -jmp 0x4b02ae
    goto L_0x004b02ae;
L_0x004b029f:
    // 004b029f  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x004b02a2:
    // 004b02a2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b02a4  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b02a7  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b02a9  e8d2fdffff             -call 0x4b0080
    cpu.esp -= 4;
    sub_4b0080(app, cpu);
    if (cpu.terminate) return;
L_0x004b02ae:
    // 004b02ae  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 004b02b2  7416                   -je 0x4b02ca
    if (cpu.flags.zf)
    {
        goto L_0x004b02ca;
    }
    // 004b02b4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b02b6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b02b8  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004b02bb  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004b02be  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b02c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b02c3  7e0d                   -jle 0x4b02d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b02d2;
    }
    // 004b02c5  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b02c8  eb08                   -jmp 0x4b02d2
    goto L_0x004b02d2;
L_0x004b02ca:
    // 004b02ca  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b02cc  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b02cf  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004b02d2:
    // 004b02d2  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b02d5  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004b02da  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004b02dd  7405                   -je 0x4b02e4
    if (cpu.flags.zf)
    {
        goto L_0x004b02e4;
    }
    // 004b02df  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x004b02e4:
    // 004b02e4  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004b02e8  7402                   -je 0x4b02ec
    if (cpu.flags.zf)
    {
        goto L_0x004b02ec;
    }
    // 004b02ea  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004b02ec:
    // 004b02ec  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b02ef  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b02f2  39d8                   +cmp eax, ebx
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
    // 004b02f4  7d03                   -jge 0x4b02f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b02f9;
    }
    // 004b02f6  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004b02f9:
    // 004b02f9  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 004b0300  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004b0302  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 004b0308  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004b030e  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004b0311  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0313  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004b0316  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0319  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b031b  0f8ee8000000           -jle 0x4b0409
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4b0409(app, cpu);
    }
    // 004b0321  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 004b0324  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004b0327  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0329  7572                   -jne 0x4b039d
    if (!cpu.flags.zf)
    {
        goto L_0x004b039d;
    }
    // 004b032b  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 004b0331  0f84d2000000           -je 0x4b0409
    if (cpu.flags.zf)
    {
        return sub_4b0409(app, cpu);
    }
    // 004b0337  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b033a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b033c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b033d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b033e  9b                     -wait 
    /*nothing*/;
    // 004b033f  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b0342  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0343  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0344  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 004b0347  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0348  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b034b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b034c  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004b0350  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0353  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0354  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0355  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0357  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0359  7e42                   -jle 0x4b039d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b039d;
    }
    // 004b035b  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b035e  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0361  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0362  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b0365  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0366  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0368  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b036b  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b036e  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0370  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0372  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0374  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0376  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 004b037b  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004b0380  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b0383  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 004b0387  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 004b038a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b038c  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b038f  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004b0392  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0395  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0397  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0399  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b039b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004b039d:
    // 004b039d  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004b03a0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b03a2  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b03a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b03a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03a7  e802000000             -call 0x4b03ae
    cpu.esp -= 4;
    sub_4b03ae(app, cpu);
    if (cpu.terminate) return;
    // 004b03ac  eb45                   -jmp 0x4b03f3
    return sub_4b03f3(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4b00da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x004b00da;
    // 004b00c4  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004b00c6  6d                     -insd dword ptr es:[edi], dx
    NFS2_ASSERT(false);
    // 004b00c7  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00ca  a9014b007b             -test eax, 0x7b004b01
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2063616769 /*0x7b004b01*/));
    // 004b00cf  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00d2  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004b00d3  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00d6  6d                     -insd dword ptr es:[edi], dx
    NFS2_ASSERT(false);
    // 004b00d7  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x004b00da:
    // 004b00da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b00db  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b00dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b00de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b00df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b00e0  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004b00e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b00e8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b00ea  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 004b00ed  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b00ef  9b                     -wait 
    /*nothing*/;
    // 004b00f0  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b00f3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b00f4  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004b00f7  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004b00fa  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b00ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0100  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0103  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0104  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b010b  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004b010f  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 004b0113  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004b0116  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004b0119  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004b011b  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004b011e  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 004b0122  7407                   -je 0x4b012b
    if (cpu.flags.zf)
    {
        goto L_0x004b012b;
    }
    // 004b0124  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x004b012b:
    // 004b012b  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004b012f  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b0136  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b013d  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004b0144  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0147  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004b014e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b0150  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004b0157  e8162f0000             -call 0x4b3072
    cpu.esp -= 4;
    sub_4b3072(app, cpu);
    if (cpu.terminate) return;
    // 004b015c  83f804                 +cmp eax, 4
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
    // 004b015f  0f8749010000           -ja 0x4b02ae
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b02ae;
    }
    // 004b0165  2eff2485c6004b00       -jmp dword ptr cs:[eax*4 + 0x4b00c6]
    cpu.ip = app->getMemory<x86::reg32>(4915398 + cpu.eax * 4); goto dynamic_jump;
  case 0x004b016d:
    // 004b016d  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004b0174:
    // 004b0174  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b0176  e933010000             -jmp 0x4b02ae
    goto L_0x004b02ae;
  case 0x004b017b:
    // 004b017b  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b017e  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 004b0181  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 004b0185  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x004b0189:
    // 004b0189  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004b018d  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 004b0194  e970030000             -jmp 0x4b0509
    return sub_4b0509(app, cpu);
  case 0x004b0199:
    // 004b0199  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b019c  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 004b019f  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 004b01a3  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 004b01a7  ebe0                   -jmp 0x4b0189
    goto L_0x004b0189;
  case 0x004b01a9:
    // 004b01a9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b01ab  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01af  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 004b01b5  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 004b01bb  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 004b01c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b01c2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b01c5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b01c7  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b01ca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b01cc  0f84dc000000           -je 0x4b02ae
    if (cpu.flags.zf)
    {
        goto L_0x004b02ae;
    }
    // 004b01d2  7d0f                   -jge 0x4b01e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b01e3;
    }
    // 004b01d4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b01d6  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b01d9  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b01dc  f7d9                   +neg ecx
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
    // 004b01de  e9bf000000             -jmp 0x4b02a2
    goto L_0x004b02a2;
L_0x004b01e3:
    // 004b01e3  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01e6  6681fa1940             +cmp dx, 0x4019
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16409 /*0x4019*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b01eb  7287                   -jb 0x4b0174
    if (cpu.flags.cf)
    {
        goto L_0x004b0174;
    }
    // 004b01ed  750d                   -jne 0x4b01fc
    if (!cpu.flags.zf)
    {
        goto L_0x004b01fc;
    }
    // 004b01ef  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b01f6  0f8278ffffff           -jb 0x4b0174
    if (cpu.flags.cf)
    {
        goto L_0x004b0174;
    }
L_0x004b01fc:
    // 004b01fc  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01ff  663d3440               +cmp ax, 0x4034
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16436 /*0x4034*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b0203  7220                   -jb 0x4b0225
    if (cpu.flags.cf)
    {
        goto L_0x004b0225;
    }
    // 004b0205  0f8594000000           -jne 0x4b029f
    if (!cpu.flags.zf)
    {
        goto L_0x004b029f;
    }
    // 004b020b  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004b020e  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2384185791 /*0x8e1bc9bf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0214  720f                   -jb 0x4b0225
    if (cpu.flags.cf)
    {
        goto L_0x004b0225;
    }
    // 004b0216  0f8583000000           -jne 0x4b029f
    if (!cpu.flags.zf)
    {
        goto L_0x004b029f;
    }
    // 004b021c  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0223  737a                   -jae 0x4b029f
    if (!cpu.flags.cf)
    {
        goto L_0x004b029f;
    }
L_0x004b0225:
    // 004b0225  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 004b022a  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b022d  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0230  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 004b0234  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004b0239  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b023b  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 004b023e  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b0241  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 004b0244  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0246  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0248  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b024a  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b024c  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b024f  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b0252  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b0255  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0257  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0258  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0259  9b                     -wait 
    /*nothing*/;
    // 004b025a  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b025d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b025e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b025f  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 004b0262  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0263  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0266  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0267  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004b026b  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b026e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b026f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0270  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0272  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0273  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b0276  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0277  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0279  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b027c  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b027f  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0281  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0283  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0285  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0287  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b028a  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b028d  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0290  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004b0295  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0297  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0299  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b029b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b029d  eb0f                   -jmp 0x4b02ae
    goto L_0x004b02ae;
L_0x004b029f:
    // 004b029f  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x004b02a2:
    // 004b02a2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b02a4  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b02a7  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b02a9  e8d2fdffff             -call 0x4b0080
    cpu.esp -= 4;
    sub_4b0080(app, cpu);
    if (cpu.terminate) return;
L_0x004b02ae:
    // 004b02ae  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 004b02b2  7416                   -je 0x4b02ca
    if (cpu.flags.zf)
    {
        goto L_0x004b02ca;
    }
    // 004b02b4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b02b6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b02b8  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004b02bb  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004b02be  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b02c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b02c3  7e0d                   -jle 0x4b02d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b02d2;
    }
    // 004b02c5  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b02c8  eb08                   -jmp 0x4b02d2
    goto L_0x004b02d2;
L_0x004b02ca:
    // 004b02ca  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b02cc  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b02cf  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004b02d2:
    // 004b02d2  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b02d5  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004b02da  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004b02dd  7405                   -je 0x4b02e4
    if (cpu.flags.zf)
    {
        goto L_0x004b02e4;
    }
    // 004b02df  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x004b02e4:
    // 004b02e4  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004b02e8  7402                   -je 0x4b02ec
    if (cpu.flags.zf)
    {
        goto L_0x004b02ec;
    }
    // 004b02ea  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004b02ec:
    // 004b02ec  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b02ef  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b02f2  39d8                   +cmp eax, ebx
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
    // 004b02f4  7d03                   -jge 0x4b02f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b02f9;
    }
    // 004b02f6  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004b02f9:
    // 004b02f9  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 004b0300  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004b0302  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 004b0308  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004b030e  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004b0311  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0313  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004b0316  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0319  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b031b  0f8ee8000000           -jle 0x4b0409
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4b0409(app, cpu);
    }
    // 004b0321  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 004b0324  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004b0327  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0329  7572                   -jne 0x4b039d
    if (!cpu.flags.zf)
    {
        goto L_0x004b039d;
    }
    // 004b032b  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 004b0331  0f84d2000000           -je 0x4b0409
    if (cpu.flags.zf)
    {
        return sub_4b0409(app, cpu);
    }
    // 004b0337  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b033a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b033c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b033d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b033e  9b                     -wait 
    /*nothing*/;
    // 004b033f  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b0342  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0343  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0344  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 004b0347  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0348  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b034b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b034c  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004b0350  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0353  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0354  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0355  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0357  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0359  7e42                   -jle 0x4b039d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b039d;
    }
    // 004b035b  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b035e  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0361  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0362  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b0365  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0366  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0368  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b036b  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b036e  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0370  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0372  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0374  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0376  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 004b037b  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004b0380  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b0383  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 004b0387  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 004b038a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b038c  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b038f  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004b0392  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0395  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0397  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0399  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b039b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004b039d:
    // 004b039d  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004b03a0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b03a2  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b03a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b03a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03a7  e802000000             -call 0x4b03ae
    cpu.esp -= 4;
    sub_4b03ae(app, cpu);
    if (cpu.terminate) return;
    // 004b03ac  eb45                   -jmp 0x4b03f3
    return sub_4b03f3(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4b0316(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x004b0316;
    // 004b00c4  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004b00c6  6d                     -insd dword ptr es:[edi], dx
    NFS2_ASSERT(false);
    // 004b00c7  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00ca  a9014b007b             -test eax, 0x7b004b01
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2063616769 /*0x7b004b01*/));
    // 004b00cf  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00d2  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004b00d3  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00d6  6d                     -insd dword ptr es:[edi], dx
    NFS2_ASSERT(false);
    // 004b00d7  014b00                 -add dword ptr [ebx], ecx
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b00da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b00db  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b00dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b00de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b00df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b00e0  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 004b00e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b00e8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b00ea  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 004b00ed  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b00ef  9b                     -wait 
    /*nothing*/;
    // 004b00f0  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b00f3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b00f4  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004b00f7  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004b00fa  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b00ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0100  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0103  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0104  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b010b  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004b010f  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 004b0113  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004b0116  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004b0119  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004b011b  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 004b011e  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 004b0122  7407                   -je 0x4b012b
    if (cpu.flags.zf)
    {
        goto L_0x004b012b;
    }
    // 004b0124  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x004b012b:
    // 004b012b  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004b012f  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b0136  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004b013d  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004b0144  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0147  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004b014e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b0150  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004b0157  e8162f0000             -call 0x4b3072
    cpu.esp -= 4;
    sub_4b3072(app, cpu);
    if (cpu.terminate) return;
    // 004b015c  83f804                 +cmp eax, 4
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
    // 004b015f  0f8749010000           -ja 0x4b02ae
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b02ae;
    }
    // 004b0165  2eff2485c6004b00       -jmp dword ptr cs:[eax*4 + 0x4b00c6]
    cpu.ip = app->getMemory<x86::reg32>(4915398 + cpu.eax * 4); goto dynamic_jump;
  case 0x004b016d:
    // 004b016d  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x004b0174:
    // 004b0174  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004b0176  e933010000             -jmp 0x4b02ae
    goto L_0x004b02ae;
  case 0x004b017b:
    // 004b017b  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b017e  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 004b0181  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 004b0185  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x004b0189:
    // 004b0189  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004b018d  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 004b0194  e970030000             -jmp 0x4b0509
    return sub_4b0509(app, cpu);
  case 0x004b0199:
    // 004b0199  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b019c  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 004b019f  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 004b01a3  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 004b01a7  ebe0                   -jmp 0x4b0189
    goto L_0x004b0189;
  case 0x004b01a9:
    // 004b01a9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b01ab  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01af  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 004b01b5  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 004b01bb  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 004b01c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b01c2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b01c5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b01c7  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 004b01ca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b01cc  0f84dc000000           -je 0x4b02ae
    if (cpu.flags.zf)
    {
        goto L_0x004b02ae;
    }
    // 004b01d2  7d0f                   -jge 0x4b01e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b01e3;
    }
    // 004b01d4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b01d6  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b01d9  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b01dc  f7d9                   +neg ecx
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
    // 004b01de  e9bf000000             -jmp 0x4b02a2
    goto L_0x004b02a2;
L_0x004b01e3:
    // 004b01e3  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01e6  6681fa1940             +cmp dx, 0x4019
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16409 /*0x4019*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b01eb  7287                   -jb 0x4b0174
    if (cpu.flags.cf)
    {
        goto L_0x004b0174;
    }
    // 004b01ed  750d                   -jne 0x4b01fc
    if (!cpu.flags.zf)
    {
        goto L_0x004b01fc;
    }
    // 004b01ef  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3200000000 /*0xbebc2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b01f6  0f8278ffffff           -jb 0x4b0174
    if (cpu.flags.cf)
    {
        goto L_0x004b0174;
    }
L_0x004b01fc:
    // 004b01fc  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b01ff  663d3440               +cmp ax, 0x4034
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(16436 /*0x4034*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b0203  7220                   -jb 0x4b0225
    if (cpu.flags.cf)
    {
        goto L_0x004b0225;
    }
    // 004b0205  0f8594000000           -jne 0x4b029f
    if (!cpu.flags.zf)
    {
        goto L_0x004b029f;
    }
    // 004b020b  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004b020e  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2384185791 /*0x8e1bc9bf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0214  720f                   -jb 0x4b0225
    if (cpu.flags.cf)
    {
        goto L_0x004b0225;
    }
    // 004b0216  0f8583000000           -jne 0x4b029f
    if (!cpu.flags.zf)
    {
        goto L_0x004b029f;
    }
    // 004b021c  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67108864 /*0x4000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b0223  737a                   -jae 0x4b029f
    if (!cpu.flags.cf)
    {
        goto L_0x004b029f;
    }
L_0x004b0225:
    // 004b0225  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 004b022a  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b022d  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0230  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 004b0234  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004b0239  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b023b  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 004b023e  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b0241  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 004b0244  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0246  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0248  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b024a  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b024c  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b024f  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b0252  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b0255  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0257  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0258  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0259  9b                     -wait 
    /*nothing*/;
    // 004b025a  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b025d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b025e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b025f  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 004b0262  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0263  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0266  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0267  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004b026b  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b026e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b026f  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0270  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0272  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0273  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b0276  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0277  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0279  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b027c  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 004b027f  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0281  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0283  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0285  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0287  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b028a  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b028d  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0290  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004b0295  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0297  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0299  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b029b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b029d  eb0f                   -jmp 0x4b02ae
    goto L_0x004b02ae;
L_0x004b029f:
    // 004b029f  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x004b02a2:
    // 004b02a2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b02a4  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b02a7  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b02a9  e8d2fdffff             -call 0x4b0080
    cpu.esp -= 4;
    sub_4b0080(app, cpu);
    if (cpu.terminate) return;
L_0x004b02ae:
    // 004b02ae  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 004b02b2  7416                   -je 0x4b02ca
    if (cpu.flags.zf)
    {
        goto L_0x004b02ca;
    }
    // 004b02b4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b02b6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b02b8  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004b02bb  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004b02be  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b02c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b02c3  7e0d                   -jle 0x4b02d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b02d2;
    }
    // 004b02c5  0145e8                 +add dword ptr [ebp - 0x18], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b02c8  eb08                   -jmp 0x4b02d2
    goto L_0x004b02d2;
L_0x004b02ca:
    // 004b02ca  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b02cc  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b02cf  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004b02d2:
    // 004b02d2  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b02d5  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004b02da  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004b02dd  7405                   -je 0x4b02e4
    if (cpu.flags.zf)
    {
        goto L_0x004b02e4;
    }
    // 004b02df  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x004b02e4:
    // 004b02e4  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 004b02e8  7402                   -je 0x4b02ec
    if (cpu.flags.zf)
    {
        goto L_0x004b02ec;
    }
    // 004b02ea  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004b02ec:
    // 004b02ec  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b02ef  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b02f2  39d8                   +cmp eax, ebx
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
    // 004b02f4  7d03                   -jge 0x4b02f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b02f9;
    }
    // 004b02f6  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x004b02f9:
    // 004b02f9  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 004b0300  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004b0302  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 004b0308  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 004b030e  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 004b0311  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b0313  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_entry_0x004b0316:
    // 004b0316  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004b0319  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b031b  0f8ee8000000           -jle 0x4b0409
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4b0409(app, cpu);
    }
    // 004b0321  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 004b0324  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 004b0327  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b0329  7572                   -jne 0x4b039d
    if (!cpu.flags.zf)
    {
        goto L_0x004b039d;
    }
    // 004b032b  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 004b0331  0f84d2000000           -je 0x4b0409
    if (cpu.flags.zf)
    {
        return sub_4b0409(app, cpu);
    }
    // 004b0337  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b033a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b033c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b033d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b033e  9b                     -wait 
    /*nothing*/;
    // 004b033f  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 004b0342  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0343  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0344  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 004b0347  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0348  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b034b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b034c  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004b0350  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 004b0353  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0354  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0355  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b0357  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b0359  7e42                   -jle 0x4b039d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b039d;
    }
    // 004b035b  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b035e  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0361  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b0362  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b0365  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b0366  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0368  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b036b  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b036e  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0370  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0372  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b0374  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b0376  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 004b037b  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 004b0380  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b0383  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 004b0387  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 004b038a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b038c  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b038f  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004b0392  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004b0395  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 004b0397  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 004b0399  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b039b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004b039d:
    // 004b039d  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004b03a0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b03a2  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b03a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b03a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03a7  e802000000             -call 0x4b03ae
    cpu.esp -= 4;
    sub_4b03ae(app, cpu);
    if (cpu.terminate) return;
    // 004b03ac  eb45                   -jmp 0x4b03f3
    return sub_4b03f3(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4b03ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b03ae  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 004b03b3  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b03b5  39c8                   +cmp eax, ecx
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
    // 004b03b7  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03b8  7203                   -jb 0x4b03bd
    if (cpu.flags.cf)
    {
        goto L_0x004b03bd;
    }
    // 004b03ba  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03bb  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004b03bd:
    // 004b03bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03be  e801000000             -call 0x4b03c4
    cpu.esp -= 4;
    sub_4b03c4(app, cpu);
    if (cpu.terminate) return;
    // 004b03c3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03c4  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 004b03c9  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b03cb  39c8                   +cmp eax, ecx
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
    // 004b03cd  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03ce  7204                   -jb 0x4b03d4
    if (cpu.flags.cf)
    {
        goto L_0x004b03d4;
    }
    // 004b03d0  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004b03d1  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x004b03d4:
    // 004b03d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b03d5  e801000000             -call 0x4b03db
    cpu.esp -= 4;
    sub_4b03db(app, cpu);
    if (cpu.terminate) return;
    // 004b03da  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b03db  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 004b03dd  38c8                   +cmp al, cl
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b03df  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004b03e1  7204                   -jb 0x4b03e7
    if (cpu.flags.cf)
    {
        goto L_0x004b03e7;
    }
    // 004b03e3  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 004b03e5  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x004b03e7:
    // 004b03e7  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b03ea  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b03ec  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004b03ee  43                     -inc ebx
    (cpu.ebx)++;
    // 004b03ef  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 004b03f1  43                     -inc ebx
    (cpu.ebx)++;
    // 004b03f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
