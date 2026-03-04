#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_490980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490980  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490981  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490982  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490983  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00490986  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049098a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049098c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00490990  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00490992  7444                   -je 0x4909d8
    if (cpu.flags.zf)
    {
        goto L_0x004909d8;
    }
L_0x00490994:
    // 00490994  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00490998  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049099a  7547                   -jne 0x4909e3
    if (!cpu.flags.zf)
    {
        goto L_0x004909e3;
    }
    // 0049099c  c744241c08000000       -mov dword ptr [esp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
L_0x004909a4:
    // 004909a4  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x004909a8:
    // 004909a8  a164ab4c00             -mov eax, dword ptr [0x4cab64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */);
    // 004909ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004909af  741e                   -je 0x4909cf
    if (cpu.flags.zf)
    {
        goto L_0x004909cf;
    }
    // 004909b1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004909b5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004909b7  7c14                   -jl 0x4909cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004909cd;
    }
    // 004909b9  81fa00400000           +cmp edx, 0x4000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004909bf  7f0c                   -jg 0x4909cd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004909cd;
    }
    // 004909c1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004909c3  7c08                   -jl 0x4909cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004909cd;
    }
    // 004909c5  81ff00200000           +cmp edi, 0x2000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004909cb  7e22                   -jle 0x4909ef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004909ef;
    }
L_0x004909cd:
    // 004909cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004909cf:
    // 004909cf  83c420                 +add esp, 0x20
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
    // 004909d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004909d5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004909d8:
    // 004909d8  a1ec814c00             -mov eax, dword ptr [0x4c81ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 004909dd  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004909e1  ebb1                   -jmp 0x490994
    goto L_0x00490994;
L_0x004909e3:
    // 004909e3  83fb0f                 +cmp ebx, 0xf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004909e6  75bc                   -jne 0x4909a4
    if (!cpu.flags.zf)
    {
        goto L_0x004909a4;
    }
    // 004909e8  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 004909ed  ebb9                   -jmp 0x4909a8
    goto L_0x004909a8;
L_0x004909ef:
    // 004909ef  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004909f3  e8085b0000             -call 0x496500
    cpu.esp -= 4;
    sub_496500(app, cpu);
    if (cpu.terminate) return;
    // 004909f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004909fa  74d3                   -je 0x4909cf
    if (cpu.flags.zf)
    {
        goto L_0x004909cf;
    }
    // 004909fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004909fe  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00490a01  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00490a04  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00490a06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490a08  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00490a0b  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00490a0d  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00490a10  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00490a13  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00490a15  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00490a18  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00490a1c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490a1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490a1e  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00490a22  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00490a26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490a27  68b8ee4b00             -push 0x4beeb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4976312 /*0x4beeb8*/;
    cpu.esp -= 4;
    // 00490a2c  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490a30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490a31  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00490a33  e8e999feff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00490a38  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00490a3b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00490a3d  83c248                 -add edx, 0x48
    (cpu.edx) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 00490a40  e8177cfeff             -call 0x47865c
    cpu.esp -= 4;
    sub_47865c(app, cpu);
    if (cpu.terminate) return;
    // 00490a45  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00490a49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490a4b  7521                   -jne 0x490a6e
    if (!cpu.flags.zf)
    {
        goto L_0x00490a6e;
    }
    // 00490a4d  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490a52  0f8475ffffff           -je 0x4909cd
    if (cpu.flags.zf)
    {
        goto L_0x004909cd;
    }
    // 00490a58  ff055c824c00           -inc dword ptr [0x4c825c]
    (app->getMemory<x86::reg32>(x86::reg32(5014108) /* 0x4c825c */))++;
    // 00490a5e  e8a982feff             -call 0x478d0c
    cpu.esp -= 4;
    sub_478d0c(app, cpu);
    if (cpu.terminate) return;
    // 00490a63  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490a65  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00490a68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490a6b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00490a6e:
    // 00490a6e  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00490a70  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490a72  0f8455ffffff           -je 0x4909cd
    if (cpu.flags.zf)
    {
        goto L_0x004909cd;
    }
    // 00490a78  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 00490a7d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00490a7f  e858e6feff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 00490a84  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00490a88  8d5638                 -lea edx, [esi + 0x38]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00490a8b  e8705a0000             -call 0x496500
    cpu.esp -= 4;
    sub_496500(app, cpu);
    if (cpu.terminate) return;
    // 00490a90  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00490a93  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490a98  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00490a9a  66897a06               -mov word ptr [edx + 6], di
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.di;
    // 00490a9e  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00490aa0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490aa4  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00490aa6  66894204               -mov word ptr [edx + 4], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00490aaa  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 00490ab0  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00490ab3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490ab7  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00490aba  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00490abd  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490ac1  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00490ac4  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00490ac7  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00490acb  88461c                 -mov byte ptr [esi + 0x1c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.al;
    // 00490ace  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490ad0  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00490ad2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00490ad4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490ad9  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00490adc  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00490ae0  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 00490ae3  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00490ae8  e8d7250000             -call 0x4930c4
    cpu.esp -= 4;
    sub_4930c4(app, cpu);
    if (cpu.terminate) return;
    // 00490aed  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00490af1  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00490af6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00490af8  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00490afb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490afd  e8c2250000             -call 0x4930c4
    cpu.esp -= 4;
    sub_4930c4(app, cpu);
    if (cpu.terminate) return;
    // 00490b02  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00490b05  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00490b08  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00490b0a  0f84bdfeffff           -je 0x4909cd
    if (cpu.flags.zf)
    {
        goto L_0x004909cd;
    }
    // 00490b10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490b12  0f84b5feffff           -je 0x4909cd
    if (cpu.flags.zf)
    {
        goto L_0x004909cd;
    }
    // 00490b18  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00490b1c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00490b1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b22  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490b28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b28  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00490b2a  e851feffff             -call 0x490980
    cpu.esp -= 4;
    sub_490980(app, cpu);
    if (cpu.terminate) return;
    // 00490b2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b30  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490b32  e849feffff             -call 0x490980
    cpu.esp -= 4;
    sub_490980(app, cpu);
    if (cpu.terminate) return;
    // 00490b37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490b38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b38  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490b39  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490b3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490b3e  e83dfeffff             -call 0x490980
    cpu.esp -= 4;
    sub_490980(app, cpu);
    if (cpu.terminate) return;
    // 00490b43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490b45  7402                   -je 0x490b49
    if (cpu.flags.zf)
    {
        goto L_0x00490b49;
    }
    // 00490b47  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00490b49:
    // 00490b49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490b4a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b50  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00490b52  e829feffff             -call 0x490980
    cpu.esp -= 4;
    sub_490980(app, cpu);
    if (cpu.terminate) return;
    // 00490b57  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00490b59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_490b5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b5c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490b5e  e81dfeffff             -call 0x490980
    cpu.esp -= 4;
    sub_490980(app, cpu);
    if (cpu.terminate) return;
    // 00490b63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490b65  7402                   -je 0x490b69
    if (cpu.flags.zf)
    {
        goto L_0x00490b69;
    }
    // 00490b67  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00490b69:
    // 00490b69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_490b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490b70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490b71  8b158ca74c00           -mov edx, dword ptr [0x4ca78c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023628) /* 0x4ca78c */);
    // 00490b77  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490b79  7532                   -jne 0x490bad
    if (!cpu.flags.zf)
    {
        goto L_0x00490bad;
    }
    // 00490b7b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490b7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490b7d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00490b82  8915706b5200           -mov dword ptr [0x526b70], edx
    app->getMemory<x86::reg32>(x86::reg32(5401456) /* 0x526b70 */) = cpu.edx;
L_0x00490b88:
    // 00490b88  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00490b8d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00490b8f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490b92  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490b94  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00490b96  40                     -inc eax
    (cpu.eax)++;
    // 00490b97  89816c6b5200           -mov dword ptr [ecx + 0x526b6c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5401452) /* 0x526b6c */) = cpu.eax;
    // 00490b9d  81f900100000           +cmp ecx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490ba3  75e3                   -jne 0x490b88
    if (!cpu.flags.zf)
    {
        goto L_0x00490b88;
    }
    // 00490ba5  ff058ca74c00           -inc dword ptr [0x4ca78c]
    (app->getMemory<x86::reg32>(x86::reg32(5023628) /* 0x4ca78c */))++;
    // 00490bab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00490bad:
    // 00490bad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_490bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490bb0  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00490bb2  e995e20000             -jmp 0x49ee4c
    return sub_49ee4c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_490bb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490bb8  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490bba  e98de20000             -jmp 0x49ee4c
    return sub_49ee4c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_490bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490bc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490bc1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490bc3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00490bca  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490bcc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00490bce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490bd0  e877e20000             -call 0x49ee4c
    cpu.esp -= 4;
    sub_49ee4c(app, cpu);
    if (cpu.terminate) return;
    // 00490bd5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490bd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490bd8  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00490bdb  e96ce20000             -jmp 0x49ee4c
    return sub_49ee4c(app, cpu);
}

/* align: skip  */
void Application::sub_490be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490be0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490be1  b990a74c00             -mov ecx, 0x4ca790
    cpu.ecx = 5023632 /*0x4ca790*/;
    // 00490be6  e831200000             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 00490beb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490bec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490bf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00490bf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490bf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490bf3  b990a74c00             -mov ecx, 0x4ca790
    cpu.ecx = 5023632 /*0x4ca790*/;
    // 00490bf8  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00490bfb  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00490bfe  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00490c01  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00490c04  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00490c07  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00490c0a  e80d200000             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 00490c0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_490c14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490c14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490c15  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00490c18  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00490c1b  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490c1d  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00490c20  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00490c23  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490c25  b990a74c00             -mov ecx, 0x4ca790
    cpu.ecx = 5023632 /*0x4ca790*/;
    // 00490c2a  e8ed1f0000             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 00490c2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490c30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490c31(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490c31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490c32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490c33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490c34  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00490c37  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490c38  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490c39  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00490c3b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00490c3e  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490c44  f6410c01               +test byte ptr [ecx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 00490c48  7523                   -jne 0x490c6d
    if (!cpu.flags.zf)
    {
        goto L_0x00490c6d;
    }
    // 00490c4a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00490c4f  e8ec4f0000             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 00490c54  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00490c57  80ce20                 -or dh, 0x20
    cpu.dh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00490c5a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00490c5d  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 00490c60  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490c66  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00490c68  e9c2010000             -jmp 0x490e2f
    goto L_0x00490e2f;
L_0x00490c6d:
    // 00490c6d  0fafda                 -imul ebx, edx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00490c70  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00490c72  7510                   -jne 0x490c84
    if (!cpu.flags.zf)
    {
        goto L_0x00490c84;
    }
    // 00490c74  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00490c77  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490c7d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00490c7f  e9ab010000             -jmp 0x490e2f
    goto L_0x00490e2f;
L_0x00490c84:
    // 00490c84  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00490c87  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490c8b  7507                   -jne 0x490c94
    if (!cpu.flags.zf)
    {
        goto L_0x00490c94;
    }
    // 00490c8d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490c8f  e887df0000             -call 0x49ec1b
    cpu.esp -= 4;
    sub_49ec1b(app, cpu);
    if (cpu.terminate) return;
L_0x00490c94:
    // 00490c94  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00490c96  8a550c                 -mov dl, byte ptr [ebp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00490c99  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00490c9d  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 00490ca0  0f8401010000           -je 0x490da7
    if (cpu.flags.zf)
    {
        goto L_0x00490da7;
    }
    // 00490ca6  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00490caa:
    // 00490caa  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00490cad  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490caf  7454                   -je 0x490d05
    if (cpu.flags.zf)
    {
        goto L_0x00490d05;
    }
    // 00490cb1  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490cb5  39da                   +cmp edx, ebx
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
    // 00490cb7  7602                   -jbe 0x490cbb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490cbb;
    }
    // 00490cb9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00490cbb:
    // 00490cbb  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490cbf  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00490cc1  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 00490cc4  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490cc8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00490cc9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00490ccb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00490ccd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490cce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00490cd0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00490cd3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00490cd5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00490cd7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00490cda  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00490cdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490cdd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00490cde  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490ce2  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00490ce5  8d3417                 -lea esi, [edi + edx]
    cpu.esi = x86::reg32(cpu.edi + cpu.edx * 1);
    // 00490ce8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490cea  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00490cee  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00490cf2  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00490cf5  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00490cf7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00490cf9  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00490cfb  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 00490cfe  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00490d02  897d04                 -mov dword ptr [ebp + 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edi;
L_0x00490d05:
    // 00490d05  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490d09  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00490d0b  0f840a010000           -je 0x490e1b
    if (cpu.flags.zf)
    {
        goto L_0x00490e1b;
    }
    // 00490d11  3b4d14                 +cmp ecx, dword ptr [ebp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490d14  730a                   -jae 0x490d20
    if (!cpu.flags.cf)
    {
        goto L_0x00490d20;
    }
    // 00490d16  f6450d04               +test byte ptr [ebp + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 00490d1a  0f8473000000           -je 0x490d93
    if (cpu.flags.zf)
    {
        goto L_0x00490d93;
    }
L_0x00490d20:
    // 00490d20  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00490d23  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00490d26  c7450400000000         -mov dword ptr [ebp + 4], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00490d2d  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490d31  8a4d0d                 -mov cl, byte ptr [ebp + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(13) /* 0xd */);
    // 00490d34  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00490d37  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00490d3a  750d                   -jne 0x490d49
    if (!cpu.flags.zf)
    {
        goto L_0x00490d49;
    }
    // 00490d3c  81fb00020000           +cmp ebx, 0x200
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490d42  7605                   -jbe 0x490d49
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00490d49;
    }
    // 00490d44  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00490d46  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00490d49:
    // 00490d49  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490d4d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00490d50  e84c2f0100             -call 0x4a3ca1
    cpu.esp -= 4;
    sub_4a3ca1(app, cpu);
    if (cpu.terminate) return;
    // 00490d55  83f8ff                 +cmp eax, -1
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
    // 00490d58  7509                   -jne 0x490d63
    if (!cpu.flags.zf)
    {
        goto L_0x00490d63;
    }
    // 00490d5a  804d0c20               +or byte ptr [ebp + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00490d5e  e9b8000000             -jmp 0x490e1b
    goto L_0x00490e1b;
L_0x00490d63:
    // 00490d63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d65  7509                   -jne 0x490d70
    if (!cpu.flags.zf)
    {
        goto L_0x00490d70;
    }
L_0x00490d67:
    // 00490d67  804d0c10               +or byte ptr [ebp + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00490d6b  e9ab000000             -jmp 0x490e1b
    goto L_0x00490e1b;
L_0x00490d70:
    // 00490d70  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490d74  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00490d78  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490d7c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490d7e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00490d80  01c1                   +add ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00490d82  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00490d86  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00490d8a  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00490d8e  e917ffffff             -jmp 0x490caa
    goto L_0x00490caa;
L_0x00490d93:
    // 00490d93  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490d95  e86a8a0000             -call 0x499804
    cpu.esp -= 4;
    sub_499804(app, cpu);
    if (cpu.terminate) return;
    // 00490d9a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490d9c  0f8479000000           -je 0x490e1b
    if (cpu.flags.zf)
    {
        goto L_0x00490e1b;
    }
    // 00490da2  e903ffffff             -jmp 0x490caa
    goto L_0x00490caa;
L_0x00490da7:
    // 00490da7  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00490dab  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00490dad:
    // 00490dad  837d0400               +cmp dword ptr [ebp + 4], 0
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
    // 00490db1  750b                   -jne 0x490dbe
    if (!cpu.flags.zf)
    {
        goto L_0x00490dbe;
    }
    // 00490db3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490db5  e84a8a0000             -call 0x499804
    cpu.esp -= 4;
    sub_499804(app, cpu);
    if (cpu.terminate) return;
    // 00490dba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490dbc  745d                   -je 0x490e1b
    if (cpu.flags.zf)
    {
        goto L_0x00490e1b;
    }
L_0x00490dbe:
    // 00490dbe  8b4d04                 -mov ecx, dword ptr [ebp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00490dc1  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00490dc4  49                     -dec ecx
    (cpu.ecx)--;
    // 00490dc5  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00490dc8  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00490dcb  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 00490dce  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00490dd0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00490dd5  83f80d                 +cmp eax, 0xd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490dd8  7528                   -jne 0x490e02
    if (!cpu.flags.zf)
    {
        goto L_0x00490e02;
    }
    // 00490dda  837d0400               +cmp dword ptr [ebp + 4], 0
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
    // 00490dde  750b                   -jne 0x490deb
    if (!cpu.flags.zf)
    {
        goto L_0x00490deb;
    }
    // 00490de0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00490de2  e81d8a0000             -call 0x499804
    cpu.esp -= 4;
    sub_499804(app, cpu);
    if (cpu.terminate) return;
    // 00490de7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490de9  7430                   -je 0x490e1b
    if (cpu.flags.zf)
    {
        goto L_0x00490e1b;
    }
L_0x00490deb:
    // 00490deb  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00490dee  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00490df1  4f                     -dec edi
    (cpu.edi)--;
    // 00490df2  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00490df5  897d04                 -mov dword ptr [ebp + 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00490df8  897500                 -mov dword ptr [ebp], esi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.esi;
    // 00490dfb  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00490dfd  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00490e02:
    // 00490e02  83f81a                 +cmp eax, 0x1a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490e05  0f845cffffff           -je 0x490d67
    if (cpu.flags.zf)
    {
        goto L_0x00490d67;
    }
    // 00490e0b  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00490e0d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490e11  40                     -inc eax
    (cpu.eax)++;
    // 00490e12  42                     -inc edx
    (cpu.edx)++;
    // 00490e13  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00490e17  39da                   +cmp edx, ebx
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
    // 00490e19  7592                   -jne 0x490dad
    if (!cpu.flags.zf)
    {
        goto L_0x00490dad;
    }
L_0x00490e1b:
    // 00490e1b  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00490e1e  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00490e21  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490e27  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490e29  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00490e2d  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00490e2f:
    // 00490e2f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00490e32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490e35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_490e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490e40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490e41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490e42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490e43  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00490e46  8b35bca74c00           -mov esi, dword ptr [0x4ca7bc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023676) /* 0x4ca7bc */);
    // 00490e4c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00490e4e  833dc0a74c0000         +cmp dword ptr [0x4ca7c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023680) /* 0x4ca7c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490e55  0f8466000000           -je 0x490ec1
    if (cpu.flags.zf)
    {
        goto L_0x00490ec1;
    }
L_0x00490e5b:
    // 00490e5b  8b3dc0a74c00           -mov edi, dword ptr [0x4ca7c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023680) /* 0x4ca7c0 */);
    // 00490e61  8b35bca74c00           -mov esi, dword ptr [0x4ca7bc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023676) /* 0x4ca7bc */);
    // 00490e67  39fa                   +cmp edx, edi
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
    // 00490e69  7e02                   -jle 0x490e6d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490e6d;
    }
    // 00490e6b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x00490e6d:
    // 00490e6d  39f2                   +cmp edx, esi
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
    // 00490e6f  7c43                   -jl 0x490eb4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490eb4;
    }
    // 00490e71  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 00490e74  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00490e77  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490e79  4b                     -dec ebx
    (cpu.ebx)--;
    // 00490e7a  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 00490e7c  21fb                   -and ebx, edi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.edi));
    // 00490e7e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00490e80  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490e82  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00490e84  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00490e86  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00490e88  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00490e8b  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00490e8d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00490e8f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00490e92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490e94  7e1e                   -jle 0x490eb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00490eb4;
    }
L_0x00490e96:
    // 00490e96  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00490e98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00490e9a  39cb                   +cmp ebx, ecx
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
    // 00490e9c  720c                   -jb 0x490eaa
    if (cpu.flags.cf)
    {
        goto L_0x00490eaa;
    }
L_0x00490e9e:
    // 00490e9e  40                     -inc eax
    (cpu.eax)++;
    // 00490e9f  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00490ea1  83f820                 +cmp eax, 0x20
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
    // 00490ea4  7d04                   -jge 0x490eaa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00490eaa;
    }
    // 00490ea6  39ca                   +cmp edx, ecx
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
    // 00490ea8  73f4                   -jae 0x490e9e
    if (!cpu.flags.cf)
    {
        goto L_0x00490e9e;
    }
L_0x00490eaa:
    // 00490eaa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00490ead  47                     -inc edi
    (cpu.edi)++;
    // 00490eae  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00490eb0  39c7                   +cmp edi, eax
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
    // 00490eb2  7ce2                   -jl 0x490e96
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490e96;
    }
L_0x00490eb4:
    // 00490eb4  8935bca74c00           -mov dword ptr [0x4ca7bc], esi
    app->getMemory<x86::reg32>(x86::reg32(5023676) /* 0x4ca7bc */) = cpu.esi;
    // 00490eba  83c404                 +add esp, 4
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
    // 00490ebd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ebe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ebf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ec0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490ec1:
    // 00490ec1  e89e2e0000             -call 0x493d64
    cpu.esp -= 4;
    sub_493d64(app, cpu);
    if (cpu.terminate) return;
    // 00490ec6  a3c0a74c00             -mov dword ptr [0x4ca7c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5023680) /* 0x4ca7c0 */) = cpu.eax;
    // 00490ecb  eb8e                   -jmp 0x490e5b
    goto L_0x00490e5b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_490ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490ed0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490ed1  8b15ac844c00           -mov edx, dword ptr [0x4c84ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */);
    // 00490ed7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00490ed9  7502                   -jne 0x490edd
    if (!cpu.flags.zf)
    {
        goto L_0x00490edd;
    }
    // 00490edb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490edc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490edd:
    // 00490edd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490ede  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00490ee3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490ee5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00490ee6  2eff1598554b00         -call dword ptr cs:[0x4b5598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937112) /* 0x4b5598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00490eed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490eef  890dac844c00           -mov dword ptr [0x4c84ac], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */) = cpu.ecx;
    // 00490ef5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ef6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ef7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_490ef8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00490ef8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00490ef9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00490efa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00490efb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00490efc  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00490eff  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00490f01  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00490f03  e828270000             -call 0x493630
    cpu.esp -= 4;
    sub_493630(app, cpu);
    if (cpu.terminate) return;
    // 00490f08  a330b75100             -mov dword ptr [0x51b730], eax
    app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */) = cpu.eax;
    // 00490f0d  e83e270000             -call 0x493650
    cpu.esp -= 4;
    sub_493650(app, cpu);
    if (cpu.terminate) return;
    // 00490f12  833dbca74c0000         +cmp dword ptr [0x4ca7bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023676) /* 0x4ca7bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490f19  0f84db000000           -je 0x490ffa
    if (cpu.flags.zf)
    {
        goto L_0x00490ffa;
    }
L_0x00490f1f:
    // 00490f1f  e81c2e0000             -call 0x493d40
    cpu.esp -= 4;
    sub_493d40(app, cpu);
    if (cpu.terminate) return;
    // 00490f24  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490f26  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00490f28  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00490f2c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00490f2e  0f85de000000           -jne 0x491012
    if (!cpu.flags.zf)
    {
        goto L_0x00491012;
    }
L_0x00490f34:
    // 00490f34  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490f36  891dac844c00           -mov dword ptr [0x4c84ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */) = cpu.ebx;
    // 00490f3c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00490f3e:
    // 00490f3e  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00490f42  e83d010000             -call 0x491084
    cpu.esp -= 4;
    sub_491084(app, cpu);
    if (cpu.terminate) return;
    // 00490f47  a3ac844c00             -mov dword ptr [0x4c84ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */) = cpu.eax;
    // 00490f4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00490f4e  751a                   -jne 0x490f6a
    if (!cpu.flags.zf)
    {
        goto L_0x00490f6a;
    }
    // 00490f50  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00490f54  81fe00000800           +cmp esi, 0x80000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00490f5a  0f8c92000000           -jl 0x490ff2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00490ff2;
    }
    // 00490f60  8dae0000f8ff           -lea ebp, [esi - 0x80000]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(-524288) /* -0x80000 */);
    // 00490f66  896c2424               -mov dword ptr [esp + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebp;
L_0x00490f6a:
    // 00490f6a  a1ac844c00             -mov eax, dword ptr [0x4c84ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */);
    // 00490f6f  39c1                   +cmp ecx, eax
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
    // 00490f71  74cb                   -je 0x490f3e
    if (cpu.flags.zf)
    {
        goto L_0x00490f3e;
    }
    // 00490f73  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00490f75  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00490f79  8d2cbd00000000         -lea ebp, [edi*4]
    cpu.ebp = x86::reg32(cpu.edi * 4);
    // 00490f80  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00490f82  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00490f84  a3a8844c00             -mov dword ptr [0x4c84a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5014696) /* 0x4c84a8 */) = cpu.eax;
    // 00490f89  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00490f8b  e8807ffeff             -call 0x478f10
    cpu.esp -= 4;
    sub_478f10(app, cpu);
    if (cpu.terminate) return;
    // 00490f90  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490f92  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00490f94  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490f96  c1e503                 -shl ebp, 3
    cpu.ebp <<= 3 /*0x3*/ % 32;
    // 00490f99  b81cf04b00             -mov eax, 0x4bf01c
    cpu.eax = 4976668 /*0x4bf01c*/;
    // 00490f9e  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00490fa0  8b0da8844c00           -mov ecx, dword ptr [0x4c84a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014696) /* 0x4c84a8 */);
    // 00490fa6  8b1dac844c00           -mov ebx, dword ptr [0x4c84ac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */);
    // 00490fac  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00490fae  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00490fb0  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00490fb2  e8a575feff             -call 0x47855c
    cpu.esp -= 4;
    sub_47855c(app, cpu);
    if (cpu.terminate) return;
    // 00490fb7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490fb9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00490fbb  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00490fc0  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 00490fc5  b824f04b00             -mov eax, 0x4bf024
    cpu.eax = 4976676 /*0x4bf024*/;
    // 00490fca  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00490fcf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00490fd1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00490fd3  e88475feff             -call 0x47855c
    cpu.esp -= 4;
    sub_47855c(app, cpu);
    if (cpu.terminate) return;
    // 00490fd8  8b0da8844c00           -mov ecx, dword ptr [0x4c84a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014696) /* 0x4c84a8 */);
    // 00490fde  8b15ac844c00           -mov edx, dword ptr [0x4c84ac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */);
    // 00490fe4  a130b75100             -mov eax, dword ptr [0x51b730]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355312) /* 0x51b730 */);
    // 00490fe9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00490feb  e868260000             -call 0x493658
    cpu.esp -= 4;
    sub_493658(app, cpu);
    if (cpu.terminate) return;
    // 00490ff0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00490ff2:
    // 00490ff2  83c428                 +add esp, 0x28
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
    // 00490ff5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ff6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ff7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ff8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00490ff9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00490ffa:
    // 00490ffa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00490ffc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00490ffd  2eff15ec544b00         -call dword ptr cs:[0x4b54ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936940) /* 0x4b54ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491004  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491008  a3bca74c00             -mov dword ptr [0x4ca7bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5023676) /* 0x4ca7bc */) = cpu.eax;
    // 0049100d  e90dffffff             -jmp 0x490f1f
    goto L_0x00490f1f;
L_0x00491012:
    // 00491012  39c6                   +cmp esi, eax
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
    // 00491014  0f8d1affffff           -jge 0x490f34
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00490f34;
    }
    // 0049101a  6683e6f0               +and si, 0xfff0
    cpu.clear_co();
    cpu.set_szp((cpu.si &= x86::reg16(x86::sreg16(65520 /*0xfff0*/))));
    // 0049101e  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 00491022  e90dffffff             -jmp 0x490f34
    goto L_0x00490f34;
}

/* align: skip 0x90 */
void Application::sub_491028(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491028  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491029  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049102a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049102b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049102c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049102e  e8792d0000             -call 0x493dac
    cpu.esp -= 4;
    sub_493dac(app, cpu);
    if (cpu.terminate) return;
    // 00491033  8b1db4a74c00           -mov ebx, dword ptr [0x4ca7b4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023668) /* 0x4ca7b4 */);
    // 00491039  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049103b  39d8                   +cmp eax, ebx
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
    // 0049103d  771a                   -ja 0x491059
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00491059;
    }
    // 0049103f  8b35b8a74c00           -mov esi, dword ptr [0x4ca7b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023672) /* 0x4ca7b8 */);
    // 00491045  39f0                   +cmp eax, esi
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
    // 00491047  7302                   -jae 0x49104b
    if (!cpu.flags.cf)
    {
        goto L_0x0049104b;
    }
    // 00491049  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0049104b:
    // 0049104b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049104d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049104f  e8a4feffff             -call 0x490ef8
    cpu.esp -= 4;
    sub_490ef8(app, cpu);
    if (cpu.terminate) return;
    // 00491054  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491055  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491056  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491057  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491058  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491059:
    // 00491059  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049105b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049105d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049105f  e894feffff             -call 0x490ef8
    cpu.esp -= 4;
    sub_490ef8(app, cpu);
    if (cpu.terminate) return;
    // 00491064  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491065  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491066  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491067  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491068  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_49106c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049106c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049106d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049106f  e884feffff             -call 0x490ef8
    cpu.esp -= 4;
    sub_490ef8(app, cpu);
    if (cpu.terminate) return;
    // 00491074  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491075  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491078(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491078  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491079  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049107b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049107d  e876feffff             -call 0x490ef8
    cpu.esp -= 4;
    sub_490ef8(app, cpu);
    if (cpu.terminate) return;
    // 00491082  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491083  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491084(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491084  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491085  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491086  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491087  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491088  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491089  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0049108c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049108e  8b15bca74c00           -mov edx, dword ptr [0x4ca7bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023676) /* 0x4ca7bc */);
    // 00491094  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00491096  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00491098  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049109a  7435                   -je 0x4910d1
    if (cpu.flags.zf)
    {
        goto L_0x004910d1;
    }
L_0x0049109c:
    // 0049109c  8b0dbca74c00           -mov ecx, dword ptr [0x4ca7bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023676) /* 0x4ca7bc */);
    // 004910a2  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004910a4  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004910a6  4a                     -dec edx
    (cpu.edx)--;
    // 004910a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004910a9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004910ac  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004910ae  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004910b1  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004910b3  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 004910b8  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004910ba  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004910bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004910bd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004910bf  2eff1594554b00         -call dword ptr cs:[0x4b5594]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937108) /* 0x4b5594 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004910c6  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004910c8  83c424                 +add esp, 0x24
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004910cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004910d1:
    // 004910d1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004910d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004910d4  2eff15ec544b00         -call dword ptr cs:[0x4b54ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936940) /* 0x4b54ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004910db  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004910df  a3bca74c00             -mov dword ptr [0x4ca7bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5023676) /* 0x4ca7bc */) = cpu.eax;
    // 004910e4  ebb6                   -jmp 0x49109c
    goto L_0x0049109c;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4910e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004910e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004910e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004910ea  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 004910ef  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004910f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004910f2  2eff1598554b00         -call dword ptr cs:[0x4b5598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937112) /* 0x4b5598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004910f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004910fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_491100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491100  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491101  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491102  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491104  e83fdafeff             -call 0x47eb48
    cpu.esp -= 4;
    sub_47eb48(app, cpu);
    if (cpu.terminate) return;
    // 00491109  833dac844c0000         +cmp dword ptr [0x4c84ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014700) /* 0x4c84ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491110  742b                   -je 0x49113d
    if (cpu.flags.zf)
    {
        goto L_0x0049113d;
    }
L_0x00491112:
    // 00491112  833dc4814c0000         +cmp dword ptr [0x4c81c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491119  7516                   -jne 0x491131
    if (!cpu.flags.zf)
    {
        goto L_0x00491131;
    }
    // 0049111b  8b1dec814c00           -mov ebx, dword ptr [0x4c81ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 00491121  8b15e8814c00           -mov edx, dword ptr [0x4c81e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 00491127  a1e4814c00             -mov eax, dword ptr [0x4c81e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 0049112c  e8e3b9feff             -call 0x47cb14
    cpu.esp -= 4;
    sub_47cb14(app, cpu);
    if (cpu.terminate) return;
L_0x00491131:
    // 00491131  833dc4814c0000         +cmp dword ptr [0x4c81c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491138  750f                   -jne 0x491149
    if (!cpu.flags.zf)
    {
        goto L_0x00491149;
    }
    // 0049113a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049113b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049113c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049113d:
    // 0049113d  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 00491142  e8e1feffff             -call 0x491028
    cpu.esp -= 4;
    sub_491028(app, cpu);
    if (cpu.terminate) return;
    // 00491147  ebc9                   -jmp 0x491112
    goto L_0x00491112;
L_0x00491149:
    // 00491149  bb0caf4c00             -mov ebx, 0x4caf0c
    cpu.ebx = 5025548 /*0x4caf0c*/;
    // 0049114e  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00491153  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491155  e83ec7ffff             -call 0x48d898
    cpu.esp -= 4;
    sub_48d898(app, cpu);
    if (cpu.terminate) return;
    // 0049115a  a134824c00             -mov eax, dword ptr [0x4c8234]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0049115f  e8846cfeff             -call 0x477de8
    cpu.esp -= 4;
    sub_477de8(app, cpu);
    if (cpu.terminate) return;
    // 00491164  e8c7a5feff             -call 0x47b730
    cpu.esp -= 4;
    sub_47b730(app, cpu);
    if (cpu.terminate) return;
    // 00491169  e8e6a7feff             -call 0x47b954
    cpu.esp -= 4;
    sub_47b954(app, cpu);
    if (cpu.terminate) return;
    // 0049116e  e8cd2b0100             -call 0x4a3d40
    cpu.esp -= 4;
    sub_4a3d40(app, cpu);
    if (cpu.terminate) return;
    // 00491173  b8fcca4c00             -mov eax, 0x4ccafc
    cpu.eax = 5032700 /*0x4ccafc*/;
    // 00491178  e8439cfeff             -call 0x47adc0
    cpu.esp -= 4;
    sub_47adc0(app, cpu);
    if (cpu.terminate) return;
    // 0049117d  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 00491182  e8d553feff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00491187  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491189  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049118e  e8c953feff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00491193  e8e892feff             -call 0x47a480
    cpu.esp -= 4;
    sub_47a480(app, cpu);
    if (cpu.terminate) return;
    // 00491198  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049119f  7505                   -jne 0x4911a6
    if (!cpu.flags.zf)
    {
        goto L_0x004911a6;
    }
    // 004911a1  e8da08f9ff             -call 0x421a80
    cpu.esp -= 4;
    sub_421a80(app, cpu);
    if (cpu.terminate) return;
L_0x004911a6:
    // 004911a6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004911a7  e894090000             -call 0x491b40
    cpu.esp -= 4;
    sub_491b40(app, cpu);
    if (cpu.terminate) return;
    // 004911ac  e897adfeff             -call 0x47bf48
    cpu.esp -= 4;
    sub_47bf48(app, cpu);
    if (cpu.terminate) return;
    // 004911b1  e8ea2b0100             -call 0x4a3da0
    cpu.esp -= 4;
    sub_4a3da0(app, cpu);
    if (cpu.terminate) return;
    // 004911b6  b8d01b4900             -mov eax, 0x491bd0
    cpu.eax = 4791248 /*0x491bd0*/;
    // 004911bb  e8100a0000             -call 0x491bd0
    cpu.esp -= 4;
    sub_491bd0(app, cpu);
    if (cpu.terminate) return;
    // 004911c0  b8a4be4700             -mov eax, 0x47bea4
    cpu.eax = 4701860 /*0x47bea4*/;
    // 004911c5  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 004911ca  e8e5acfeff             -call 0x47beb4
    cpu.esp -= 4;
    sub_47beb4(app, cpu);
    if (cpu.terminate) return;
    // 004911cf  e81c2c0100             -call 0x4a3df0
    cpu.esp -= 4;
    sub_4a3df0(app, cpu);
    if (cpu.terminate) return;
    // 004911d4  e8732d0100             -call 0x4a3f4c
    cpu.esp -= 4;
    sub_4a3f4c(app, cpu);
    if (cpu.terminate) return;
    // 004911d9  b81e000000             -mov eax, 0x1e
    cpu.eax = 30 /*0x1e*/;
    // 004911de  8b0de8814c00           -mov ecx, dword ptr [0x4c81e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 004911e4  8b1de4814c00           -mov ebx, dword ptr [0x4c81e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 004911ea  e8e5c9ffff             -call 0x48dbd4
    cpu.esp -= 4;
    sub_48dbd4(app, cpu);
    if (cpu.terminate) return;
    // 004911ef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004911f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004911f3  e878c8ffff             -call 0x48da70
    cpu.esp -= 4;
    sub_48da70(app, cpu);
    if (cpu.terminate) return;
    // 004911f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004911fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_491200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491200  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491201  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491202  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491203  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00491205  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00491207  e8b467fbff             -call 0x4479c0
    cpu.esp -= 4;
    sub_4479c0(app, cpu);
    if (cpu.terminate) return;
    // 0049120c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049120e  49                     -dec ecx
    (cpu.ecx)--;
    // 0049120f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00491211  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00491213  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00491215  49                     -dec ecx
    (cpu.ecx)--;
    // 00491216  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491218  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049121a  4b                     -dec ebx
    (cpu.ebx)--;
    // 0049121b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049121d  49                     -dec ecx
    (cpu.ecx)--;
    // 0049121e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00491220  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 00491222  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00491224  49                     -dec ecx
    (cpu.ecx)--;
    // 00491225  39d9                   +cmp ecx, ebx
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
    // 00491227  7606                   -jbe 0x49122f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049122f;
    }
    // 00491229  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049122b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049122c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049122d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049122e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049122f:
    // 0049122f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491230  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491232  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00491234  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491235  2bc9                   +sub ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491237  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00491238  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0049123a  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
            x86::reg8 result = tmp1 - tmp2;
            cpu.flags.cf = tmp1 < tmp2;
            cpu.flags.of = 1 & (tmp1 >> 7);
            cpu.flags.of ^= 1 & (result >> 7);
            cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
            cpu.set_szp(result);
        }
        if (cpu.flags.df)
        {
            cpu.edi -= 1;
        }
        else
        {
            cpu.edi += 1;
        }
        --cpu.ecx;
        if (cpu.flags.zf)
            break;
    }
    // 0049123c  4f                     -dec edi
    (cpu.edi)--;
L_0x0049123d:
    // 0049123d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049123f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00491241  3c00                   +cmp al, 0
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
    // 00491243  7410                   -je 0x491255
    if (cpu.flags.zf)
    {
        goto L_0x00491255;
    }
    // 00491245  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00491248  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049124b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0049124e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491251  3c00                   +cmp al, 0
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
    // 00491253  75e8                   -jne 0x49123d
    if (!cpu.flags.zf)
    {
        goto L_0x0049123d;
    }
L_0x00491255:
    // 00491255  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491256  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049125b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049125c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049125d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049125e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049125f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491260  8078013a               +cmp byte ptr [eax + 1], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491264  7406                   -je 0x49126c
    if (cpu.flags.zf)
    {
        goto L_0x0049126c;
    }
    // 00491266  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049126b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049126c:
    // 0049126c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049126d  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 0049126f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491274  8d509f                 -lea edx, [eax - 0x61]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-97) /* -0x61 */);
    // 00491277  83fa1a                 +cmp edx, 0x1a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049127a  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0049127c  83e220                 -and edx, 0x20
    cpu.edx &= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0049127f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00491281  83e841                 -sub eax, 0x41
    (cpu.eax) -= x86::reg32(x86::sreg32(65 /*0x41*/));
    // 00491284  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491285  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491288(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491288  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491289  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049128a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049128b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049128c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049128f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491291  be2cf04b00             -mov esi, 0x4bf02c
    cpu.esi = 4976684 /*0x4bf02c*/;
    // 00491296  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00491298  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00491299:
    // 00491299  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049129b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0049129d  3c00                   +cmp al, 0
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
    // 0049129f  7410                   -je 0x4912b1
    if (cpu.flags.zf)
    {
        goto L_0x004912b1;
    }
    // 004912a1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004912a4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004912a7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004912aa  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004912ad  3c00                   +cmp al, 0
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
    // 004912af  75e8                   -jne 0x491299
    if (!cpu.flags.zf)
    {
        goto L_0x00491299;
    }
L_0x004912b1:
    // 004912b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912b2  001424                 -add byte ptr [esp], dl
    (app->getMemory<x86::reg8>(cpu.esp)) += x86::reg8(x86::sreg8(cpu.dl));
    // 004912b5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004912b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004912b8  2eff15a8544b00         -call dword ptr cs:[0x4b54a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936872) /* 0x4b54a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004912bf  83f805                 +cmp eax, 5
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
    // 004912c2  750d                   -jne 0x4912d1
    if (!cpu.flags.zf)
    {
        goto L_0x004912d1;
    }
    // 004912c4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004912c9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004912cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004912d1:
    // 004912d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004912d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004912d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004912da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4912dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004912dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004912de  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004912e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4912e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004912e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004912e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004912e3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004912e4  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004912e6  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004912e8  c8080000               -enter 8, 0
    {
        cpu.esp -= 4;
        app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
        cpu.ebp = cpu.esp;
        cpu.esp -= 8;
    }
    // 004912ec  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004912ee  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004912f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004912f2  8b5d1c                 -mov ebx, dword ptr [ebp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004912f5  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004912f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004912fa  744f                   -je 0x49134b
    if (cpu.flags.zf)
    {
        goto L_0x0049134b;
    }
    // 004912fc  48                     -dec eax
    (cpu.eax)--;
    // 004912fd  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00491300  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491302  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491304  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
L_0x00491307:
    // 00491307  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049130a  732c                   -jae 0x491338
    if (!cpu.flags.cf)
    {
        goto L_0x00491338;
    }
    // 0049130c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049130f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491311  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491313  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00491315  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 00491317  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049131a  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0049131d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049131f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491321  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491324  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491326  7504                   -jne 0x49132c
    if (!cpu.flags.zf)
    {
        goto L_0x0049132c;
    }
    // 00491328  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049132a  eb1f                   -jmp 0x49134b
    goto L_0x0049134b;
L_0x0049132c:
    // 0049132c  7d05                   -jge 0x491333
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491333;
    }
    // 0049132e  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00491331  ebd4                   -jmp 0x491307
    goto L_0x00491307;
L_0x00491333:
    // 00491333  8d1c31                 -lea ebx, [ecx + esi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 00491336  ebcf                   -jmp 0x491307
    goto L_0x00491307;
L_0x00491338:
    // 00491338  750f                   -jne 0x491349
    if (!cpu.flags.zf)
    {
        goto L_0x00491349;
    }
    // 0049133a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049133c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049133e  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491341  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491343  7504                   -jne 0x491349
    if (!cpu.flags.zf)
    {
        goto L_0x00491349;
    }
    // 00491345  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491347  eb02                   -jmp 0x49134b
    goto L_0x0049134b;
L_0x00491349:
    // 00491349  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049134b:
    // 0049134b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049134c  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049134e  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00491350  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00491351  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491352  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491353  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_491356(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491356  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491357  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491358  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00491359  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049135b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049135d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049135f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491361  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491363  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491365  7e1c                   -jle 0x491383
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491383;
    }
    // 00491367  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491369  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049136b  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049136d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049136f  7e0e                   -jle 0x49137f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049137f;
    }
    // 00491371  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491373  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491375  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491377  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491379  7f1c                   -jg 0x491397
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491397;
    }
L_0x0049137b:
    // 0049137b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049137d  eb1a                   -jmp 0x491399
    goto L_0x00491399;
L_0x0049137f:
    // 0049137f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491381  eb16                   -jmp 0x491399
    goto L_0x00491399;
L_0x00491383:
    // 00491383  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491385  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491387  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491389  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049138b  7df2                   -jge 0x49137f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049137f;
    }
    // 0049138d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049138f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491391  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491393  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491395  7fe4                   -jg 0x49137b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049137b;
    }
L_0x00491397:
    // 00491397  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491399:
    // 00491399  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049139b  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049139d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049139e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049139f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491399(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00491399;
    // 00491356  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491357  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491358  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00491359  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 0049135b  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 0049135d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049135f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491361  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491363  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491365  7e1c                   -jle 0x491383
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491383;
    }
    // 00491367  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491369  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049136b  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049136d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049136f  7e0e                   -jle 0x49137f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049137f;
    }
    // 00491371  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491373  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491375  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491377  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491379  7f1c                   -jg 0x491397
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491397;
    }
L_0x0049137b:
    // 0049137b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049137d  eb1a                   -jmp 0x491399
    goto L_0x00491399;
L_0x0049137f:
    // 0049137f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491381  eb16                   -jmp 0x491399
    goto L_0x00491399;
L_0x00491383:
    // 00491383  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491385  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491387  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491389  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049138b  7df2                   -jge 0x49137f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049137f;
    }
    // 0049138d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0049138f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491391  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491393  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491395  7fe4                   -jg 0x49137b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049137b;
    }
L_0x00491397:
    // 00491397  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491399:
L_entry_0x00491399:
    // 00491399  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049139b  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049139d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049139e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049139f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004913a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4913a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004913a1  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004913a2  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004913a3  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004913a4  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 004913a7  c1e902                 +shr ecx, 2
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
    // 004913aa  740b                   -je 0x4913b7
    if (cpu.flags.zf)
    {
        goto L_0x004913b7;
    }
L_0x004913ac:
    // 004913ac  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004913ae  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004913b0  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004913b1  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004913b4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004913b5  75f5                   -jne 0x4913ac
    if (!cpu.flags.zf)
    {
        goto L_0x004913ac;
    }
L_0x004913b7:
    // 004913b7  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004913ba  7409                   -je 0x4913c5
    if (cpu.flags.zf)
    {
        goto L_0x004913c5;
    }
L_0x004913bc:
    // 004913bc  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004913be  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 004913c0  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004913c1  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004913c2  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004913c3  75f7                   -jne 0x4913bc
    if (!cpu.flags.zf)
    {
        goto L_0x004913bc;
    }
L_0x004913c5:
    // 004913c5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004913c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4913c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004913c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004913c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004913c9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004913ca  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004913cc  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004913ce  c84c0100               -enter 0x14c, 0
    {
        cpu.esp -= 4;
        app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
        cpu.ebp = cpu.esp;
        cpu.esp -= 332;
    }
    // 004913d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004913d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004913d4  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004913d7  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004913d9  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 004913dc  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 004913de  7407                   -je 0x4913e7
    if (cpu.flags.zf)
    {
        goto L_0x004913e7;
    }
    // 004913e0  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004913e5  eb09                   -jmp 0x4913f0
    goto L_0x004913f0;
L_0x004913e7:
    // 004913e7  83fb04                 +cmp ebx, 4
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
    // 004913ea  0f97c0                 -seta al
    cpu.al = (!cpu.flags.cf && !cpu.flags.zf);
    // 004913ed  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
L_0x004913f0:
    // 004913f0  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004913f3  6b85acfeffff03         -imul eax, dword ptr [ebp - 0x154], 3
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))) * x86::sreg64(x86::sreg32(3 /*0x3*/)));
    // 004913fa  8945c4                 -mov dword ptr [ebp - 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.eax;
    // 004913fd  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00491403  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491405  c745e400000000         -mov dword ptr [ebp - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 0049140c  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
L_0x0049140f:
    // 0049140f  83bdb0feffff01         +cmp dword ptr [ebp - 0x150], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491416  0f8688000000           -jbe 0x4914a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004914a4;
    }
    // 0049141c  83bdb0feffff10         +cmp dword ptr [ebp - 0x150], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491423  0f83a7000000           -jae 0x4914d0
    if (!cpu.flags.cf)
    {
        goto L_0x004914d0;
    }
    // 00491429  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 0049142c  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 0049142f  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 00491435  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 0049143c  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049143f  01c2                   +add edx, eax
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
    // 00491441  8955c0                 -mov dword ptr [ebp - 0x40], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edx;
    // 00491444  eb58                   -jmp 0x49149e
    goto L_0x0049149e;
L_0x00491446:
    // 00491446  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00491449  0345e0                 +add eax, dword ptr [ebp - 0x20]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049144c  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 0049144f  eb3f                   -jmp 0x491490
    goto L_0x00491490;
L_0x00491451:
    // 00491451  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491453  eb20                   -jmp 0x491475
    goto L_0x00491475;
L_0x00491455:
    // 00491455  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491459  740f                   -je 0x49146a
    if (cpu.flags.zf)
    {
        goto L_0x0049146a;
    }
    // 0049145b  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00491461  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00491463  e839ffffff             -call 0x4913a1
    cpu.esp -= 4;
    sub_4913a1(app, cpu);
    if (cpu.terminate) return;
    // 00491468  eb08                   -jmp 0x491472
    goto L_0x00491472;
L_0x0049146a:
    // 0049146a  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049146c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049146e  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00491470  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00491472:
    // 00491472  2b5de0                 -sub ebx, dword ptr [ebp - 0x20]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
L_0x00491475:
    // 00491475  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491478  7610                   -jbe 0x49148a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049148a;
    }
    // 0049147a  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049147c  2b7de0                 -sub edi, dword ptr [ebp - 0x20]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 0049147f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00491481  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491483  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491486  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491488  7fcb                   -jg 0x491455
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491455;
    }
L_0x0049148a:
    // 0049148a  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0049148d  0145d4                 -add dword ptr [ebp - 0x2c], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00491490:
    // 00491490  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00491493  3b45c0                 +cmp eax, dword ptr [ebp - 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491496  72b9                   -jb 0x491451
    if (cpu.flags.cf)
    {
        goto L_0x00491451;
    }
    // 00491498  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 0049149b  2945e0                 -sub dword ptr [ebp - 0x20], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049149e:
    // 0049149e  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004914a2  7fa2                   -jg 0x491446
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00491446;
    }
L_0x004914a4:
    // 004914a4  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004914a8  0f843e030000           -je 0x4917ec
    if (cpu.flags.zf)
    {
        goto L_0x004917ec;
    }
    // 004914ae  ff4de4                 +dec dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004914b1  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004914b4  8b9485b4feffff         -mov edx, dword ptr [ebp + eax*4 - 0x14c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-332) /* -0x14c */ + cpu.eax * 4);
    // 004914bb  8b848534ffffff         -mov eax, dword ptr [ebp + eax*4 - 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-204) /* -0xcc */ + cpu.eax * 4);
    // 004914c2  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004914c5  8985b0feffff           -mov dword ptr [ebp - 0x150], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */) = cpu.eax;
    // 004914cb  e93fffffff             -jmp 0x49140f
    goto L_0x0049140f;
L_0x004914d0:
    // 004914d0  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004914d6  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004914d8  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004914df  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004914e2  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004914e4  83bdb0feffff1d         +cmp dword ptr [ebp - 0x150], 0x1d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004914eb  0f8693000000           -jbe 0x491584
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00491584;
    }
    // 004914f1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004914f4  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 004914f7  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004914fd  48                     -dec eax
    (cpu.eax)--;
    // 004914fe  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 00491505  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00491508  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049150a  83bdb0feffff2a         +cmp dword ptr [ebp - 0x150], 0x2a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491511  7660                   -jbe 0x491573
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00491573;
    }
    // 00491513  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 00491519  8b95acfeffff           -mov edx, dword ptr [ebp - 0x154]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049151f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00491522  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00491525  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00491528  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
    // 0049152b  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 0049152e  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00491531  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00491534  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 00491537  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491539  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049153c  0355d8                 -add edx, dword ptr [ebp - 0x28]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 0049153f  e812feffff             -call 0x491356
    cpu.esp -= 4;
    sub_491356(app, cpu);
    if (cpu.terminate) return;
    // 00491544  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00491547  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049154a  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 0049154d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049154f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491551  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00491553  2b45d8                 -sub eax, dword ptr [ebp - 0x28]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 00491556  e8fbfdffff             -call 0x491356
    cpu.esp -= 4;
    sub_491356(app, cpu);
    if (cpu.terminate) return;
    // 0049155b  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 0049155e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00491560  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00491562  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00491564  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491566  2b55d8                 -sub edx, dword ptr [ebp - 0x28]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 00491569  2b45b8                 -sub eax, dword ptr [ebp - 0x48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */)));
    // 0049156c  e8e5fdffff             -call 0x491356
    cpu.esp -= 4;
    sub_491356(app, cpu);
    if (cpu.terminate) return;
    // 00491571  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00491573:
    // 00491573  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00491576  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 00491579  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0049157b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049157d  e8d4fdffff             -call 0x491356
    cpu.esp -= 4;
    sub_491356(app, cpu);
    if (cpu.terminate) return;
    // 00491582  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00491584:
    // 00491584  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491588  7424                   -je 0x4915ae
    if (cpu.flags.zf)
    {
        goto L_0x004915ae;
    }
    // 0049158a  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049158d  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00491590  740f                   -je 0x4915a1
    if (cpu.flags.zf)
    {
        goto L_0x004915a1;
    }
    // 00491592  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00491598  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049159a  e802feffff             -call 0x4913a1
    cpu.esp -= 4;
    sub_4913a1(app, cpu);
    if (cpu.terminate) return;
    // 0049159f  eb18                   -jmp 0x4915b9
    goto L_0x004915b9;
L_0x004915a1:
    // 004915a1  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004915a4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004915a6  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004915a8  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004915aa  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 004915ac  eb0b                   -jmp 0x4915b9
    goto L_0x004915b9;
L_0x004915ae:
    // 004915ae  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004915b1  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004915b4  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004915b6  8945b4                 -mov dword ptr [ebp - 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.eax;
L_0x004915b9:
    // 004915b9  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004915bf  48                     -dec eax
    (cpu.eax)--;
    // 004915c0  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004915c7  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004915ca  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 004915cd  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004915d0  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004915d6  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004915d9  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004915dc  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x004915df:
    // 004915df  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004915e3  7448                   -je 0x49162d
    if (cpu.flags.zf)
    {
        goto L_0x0049162d;
    }
    // 004915e5  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004915e8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004915ea  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004915ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004915ef  7f3c                   -jg 0x49162d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049162d;
    }
    // 004915f1  752f                   -jne 0x491622
    if (!cpu.flags.zf)
    {
        goto L_0x00491622;
    }
    // 004915f3  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004915f7  7412                   -je 0x49160b
    if (cpu.flags.zf)
    {
        goto L_0x0049160b;
    }
    // 004915f9  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004915ff  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00491602  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00491604  e898fdffff             -call 0x4913a1
    cpu.esp -= 4;
    sub_4913a1(app, cpu);
    if (cpu.terminate) return;
    // 00491609  eb0e                   -jmp 0x491619
    goto L_0x00491619;
L_0x0049160b:
    // 0049160b  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0049160e  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00491611  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00491613  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491615  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00491617  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x00491619:
    // 00491619  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049161f  0145ec                 -add dword ptr [ebp - 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00491622:
    // 00491622  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00491625  039dacfeffff           +add ebx, dword ptr [ebp - 0x154]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049162b  ebb2                   -jmp 0x4915df
    goto L_0x004915df;
L_0x0049162d:
    // 0049162d  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491631  7453                   -je 0x491686
    if (cpu.flags.zf)
    {
        goto L_0x00491686;
    }
    // 00491633  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00491636  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00491639  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049163c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049163e  7c46                   -jl 0x491686
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491686;
    }
    // 00491640  7536                   -jne 0x491678
    if (!cpu.flags.zf)
    {
        goto L_0x00491678;
    }
    // 00491642  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491646  7413                   -je 0x49165b
    if (cpu.flags.zf)
    {
        goto L_0x0049165b;
    }
    // 00491648  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049164e  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00491651  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00491654  e848fdffff             -call 0x4913a1
    cpu.esp -= 4;
    sub_4913a1(app, cpu);
    if (cpu.terminate) return;
    // 00491659  eb14                   -jmp 0x49166f
    goto L_0x0049166f;
L_0x0049165b:
    // 0049165b  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049165e  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00491661  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00491664  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00491666  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00491668  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0049166a  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049166d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0049166f:
    // 0049166f  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00491675  2945f0                 -sub dword ptr [ebp - 0x10], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00491678:
    // 00491678  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 0049167e  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 00491681  2945f8                 +sub dword ptr [ebp - 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491684  eba7                   -jmp 0x49162d
    goto L_0x0049162d;
L_0x00491686:
    // 00491686  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049168a  7442                   -je 0x4916ce
    if (cpu.flags.zf)
    {
        goto L_0x004916ce;
    }
    // 0049168c  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491690  7412                   -je 0x4916a4
    if (cpu.flags.zf)
    {
        goto L_0x004916a4;
    }
    // 00491692  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 00491698  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0049169b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049169d  e8fffcffff             -call 0x4913a1
    cpu.esp -= 4;
    sub_4913a1(app, cpu);
    if (cpu.terminate) return;
    // 004916a2  eb0e                   -jmp 0x4916b2
    goto L_0x004916b2;
L_0x004916a4:
    // 004916a4  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004916a7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004916a9  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004916ab  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004916ad  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004916b0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x004916b2:
    // 004916b2  039dacfeffff           +add ebx, dword ptr [ebp - 0x154]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004916b8  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004916bb  7411                   -je 0x4916ce
    if (cpu.flags.zf)
    {
        goto L_0x004916ce;
    }
    // 004916bd  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004916c3  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 004916c6  2945f8                 +sub dword ptr [ebp - 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004916c9  e911ffffff             -jmp 0x4915df
    goto L_0x004915df;
L_0x004916ce:
    // 004916ce  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004916d4  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004916db  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004916de  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004916e0  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004916e2  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004916e5  2b4dec                 -sub ecx, dword ptr [ebp - 0x14]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004916e8  2b45fc                 -sub eax, dword ptr [ebp - 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004916eb  8955cc                 -mov dword ptr [ebp - 0x34], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.edx;
    // 004916ee  39c8                   +cmp eax, ecx
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
    // 004916f0  7d02                   -jge 0x4916f4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004916f4;
    }
    // 004916f2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004916f4:
    // 004916f4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004916f6  762c                   -jbe 0x491724
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00491724;
    }
    // 004916f8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004916fa  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004916fd  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004916ff  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00491700  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00491701  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00491702  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 00491705  c1e902                 +shr ecx, 2
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
    // 00491708  740b                   -je 0x491715
    if (cpu.flags.zf)
    {
        goto L_0x00491715;
    }
L_0x0049170a:
    // 0049170a  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0049170c  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 0049170e  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 0049170f  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491712  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00491713  75f5                   -jne 0x49170a
    if (!cpu.flags.zf)
    {
        goto L_0x0049170a;
    }
L_0x00491715:
    // 00491715  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00491718  7409                   -je 0x491723
    if (cpu.flags.zf)
    {
        goto L_0x00491723;
    }
L_0x0049171a:
    // 0049171a  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 0049171c  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 0049171e  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 0049171f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00491720  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00491721  75f7                   -jne 0x49171a
    if (!cpu.flags.zf)
    {
        goto L_0x0049171a;
    }
L_0x00491723:
    // 00491723  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00491724:
    // 00491724  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00491727  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049172a  2b45f0                 -sub eax, dword ptr [ebp - 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 0049172d  2b4df8                 -sub ecx, dword ptr [ebp - 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 00491730  2b85acfeffff           -sub eax, dword ptr [ebp - 0x154]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
    // 00491736  39c1                   +cmp ecx, eax
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
    // 00491738  7202                   -jb 0x49173c
    if (cpu.flags.cf)
    {
        goto L_0x0049173c;
    }
    // 0049173a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0049173c:
    // 0049173c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049173e  762c                   -jbe 0x49176c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049176c;
    }
    // 00491740  8b7dcc                 -mov edi, dword ptr [ebp - 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00491743  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00491745  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491747  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00491748  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00491749  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049174a  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 0049174d  c1e902                 +shr ecx, 2
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
    // 00491750  740b                   -je 0x49175d
    if (cpu.flags.zf)
    {
        goto L_0x0049175d;
    }
L_0x00491752:
    // 00491752  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00491754  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 00491756  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 00491757  83c604                 +add esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049175a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049175b  75f5                   -jne 0x491752
    if (!cpu.flags.zf)
    {
        goto L_0x00491752;
    }
L_0x0049175d:
    // 0049175d  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00491760  7409                   -je 0x49176b
    if (cpu.flags.zf)
    {
        goto L_0x0049176b;
    }
L_0x00491762:
    // 00491762  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 00491764  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 00491766  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 00491767  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00491768  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00491769  75f7                   -jne 0x491762
    if (!cpu.flags.zf)
    {
        goto L_0x00491762;
    }
L_0x0049176b:
    // 0049176b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x0049176c:
    // 0049176c  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0049176f  8b4dcc                 -mov ecx, dword ptr [ebp - 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00491772  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00491774  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00491777  2b75ec                 -sub esi, dword ptr [ebp - 0x14]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 0049177a  2b7df8                 -sub edi, dword ptr [ebp - 8]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0049177d  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00491780  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00491782  39f7                   +cmp edi, esi
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
    // 00491784  7224                   -jb 0x4917aa
    if (cpu.flags.cf)
    {
        goto L_0x004917aa;
    }
    // 00491786  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00491788  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049178a  f7b5acfeffff           -div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00491790  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491792  89842b34ffffff         -mov dword ptr [ebx + ebp - 0xcc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-204) /* -0xcc */ + cpu.ebp * 1) = cpu.eax;
    // 00491799  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049179b  f7b5acfeffff           +div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004917a1  898c2bb4feffff         -mov dword ptr [ebx + ebp - 0x14c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-332) /* -0x14c */ + cpu.ebp * 1) = cpu.ecx;
    // 004917a8  eb34                   -jmp 0x4917de
    goto L_0x004917de;
L_0x004917aa:
    // 004917aa  3bb5acfeffff           +cmp esi, dword ptr [ebp - 0x154]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004917b0  0f86eefcffff           -jbe 0x4914a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004914a4;
    }
    // 004917b6  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004917b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004917bb  89842bb4feffff         -mov dword ptr [ebx + ebp - 0x14c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-332) /* -0x14c */ + cpu.ebp * 1) = cpu.eax;
    // 004917c2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004917c4  f7b5acfeffff           -div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004917ca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004917cc  89842b34ffffff         -mov dword ptr [ebx + ebp - 0xcc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-204) /* -0xcc */ + cpu.ebp * 1) = cpu.eax;
    // 004917d3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004917d5  f7b5acfeffff           +div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004917db  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x004917de:
    // 004917de  8985b0feffff           -mov dword ptr [ebp - 0x150], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */) = cpu.eax;
    // 004917e4  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004917e7  e923fcffff             -jmp 0x49140f
    goto L_0x0049140f;
L_0x004917ec:
    // 004917ec  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004917ed  e9a7fbffff             -jmp 0x491399
    return sub_491399(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_491800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491800  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 00491805  a3cc814c00             -mov dword ptr [0x4c81cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5013964) /* 0x4c81cc */) = cpu.eax;
    // 0049180a  a1787b5200             -mov eax, dword ptr [0x527b78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 0049180f  a3d0814c00             -mov dword ptr [0x4c81d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5013968) /* 0x4c81d0 */) = cpu.eax;
    // 00491814  a1947b5200             -mov eax, dword ptr [0x527b94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 00491819  a3d4814c00             -mov dword ptr [0x4c81d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5013972) /* 0x4c81d4 */) = cpu.eax;
    // 0049181e  a1d4814c00             -mov eax, dword ptr [0x4c81d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013972) /* 0x4c81d4 */);
    // 00491823  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491824  ff05887b5200           -inc dword ptr [0x527b88]
    (app->getMemory<x86::reg32>(x86::reg32(5405576) /* 0x527b88 */))++;
    // 0049182a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49182c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049182c  ff0d887b5200           -dec dword ptr [0x527b88]
    (app->getMemory<x86::reg32>(x86::reg32(5405576) /* 0x527b88 */))--;
    // 00491832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491834(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491834  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491835  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491836  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491837  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0049183c  bf2c184900             -mov edi, 0x49182c
    cpu.edi = 4790316 /*0x49182c*/;
    // 00491841  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491843  a1e4814c00             -mov eax, dword ptr [0x4c81e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013988) /* 0x4c81e4 */);
    // 00491848  89158c7b5200           -mov dword ptr [0x527b8c], edx
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.edx;
    // 0049184e  a3847b5200             -mov dword ptr [0x527b84], eax
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.eax;
    // 00491853  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 00491859  8915887b5200           -mov dword ptr [0x527b88], edx
    app->getMemory<x86::reg32>(x86::reg32(5405576) /* 0x527b88 */) = cpu.edx;
    // 0049185f  8935c8814c00           -mov dword ptr [0x4c81c8], esi
    app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */) = cpu.esi;
    // 00491865  893da4824c00           -mov dword ptr [0x4c82a4], edi
    app->getMemory<x86::reg32>(x86::reg32(5014180) /* 0x4c82a4 */) = cpu.edi;
    // 0049186b  893da8824c00           -mov dword ptr [0x4c82a8], edi
    app->getMemory<x86::reg32>(x86::reg32(5014184) /* 0x4c82a8 */) = cpu.edi;
    // 00491871  a1e8814c00             -mov eax, dword ptr [0x4c81e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013992) /* 0x4c81e8 */);
    // 00491876  ba00184900             -mov edx, 0x491800
    cpu.edx = 4790272 /*0x491800*/;
    // 0049187b  a3807b5200             -mov dword ptr [0x527b80], eax
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.eax;
    // 00491880  b824184900             -mov eax, 0x491824
    cpu.eax = 4790308 /*0x491824*/;
    // 00491885  8915b0824c00           -mov dword ptr [0x4c82b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5014192) /* 0x4c82b0 */) = cpu.edx;
    // 0049188b  a3ac824c00             -mov dword ptr [0x4c82ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5014188) /* 0x4c82ac */) = cpu.eax;
    // 00491890  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00491892  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491893  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491894  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491895  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491898(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491977(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00491977;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
L_entry_0x00491977:
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49196b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049196b;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
L_entry_0x0049196b:
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49195d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0049195d;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
L_entry_0x0049195d:
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4918c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004918c4;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x004918c4:
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491943(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00491943;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_entry_0x00491943:
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4918fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004918fb;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_entry_0x004918fb:
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491926(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00491926;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_entry_0x00491926:
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00491914;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
L_entry_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491983(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00491983;
    // 00491898  a38c7b5200             -mov dword ptr [0x527b8c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */) = cpu.eax;
    // 0049189d  8915907b5200           -mov dword ptr [0x527b90], edx
    app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */) = cpu.edx;
    // 004918a3  891d847b5200           -mov dword ptr [0x527b84], ebx
    app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */) = cpu.ebx;
    // 004918a9  890d807b5200           -mov dword ptr [0x527b80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */) = cpu.ecx;
    // 004918af  8b1d947b5200           -mov ebx, dword ptr [0x527b94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004918b5  8b15787b5200           -mov edx, dword ptr [0x527b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004918bb  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004918c0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004918c2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004918c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004918c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004918c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004918c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004918ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004918cc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004918ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004918d1  833dc8814c0000         +cmp dword ptr [0x4c81c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013960) /* 0x4c81c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918d8  0f84c3000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918de  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004918e5  0f84b6000000           -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 004918eb  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 004918f1  39f8                   +cmp eax, edi
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
    // 004918f3  0f8ede010000           -jle 0x491ad7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ad7(app, cpu);
    }
    // 004918f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004918fb  a1847b5200             -mov eax, dword ptr [0x527b84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491900  39c1                   +cmp ecx, eax
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
    // 00491902  7d10                   -jge 0x491914
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491914;
    }
    // 00491904  8b0d8c7b5200           -mov ecx, dword ptr [0x527b8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 0049190a  39ce                   +cmp esi, ecx
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
    // 0049190c  0f8ecc010000           -jle 0x491ade
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ade(app, cpu);
    }
    // 00491912  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00491914:
    // 00491914  8b1d907b5200           -mov ebx, dword ptr [0x527b90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 0049191a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049191c  39da                   +cmp edx, ebx
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
    // 0049191e  0f8ec1010000           -jle 0x491ae5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491ae5(app, cpu);
    }
    // 00491924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491926  8b3d807b5200           -mov edi, dword ptr [0x527b80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 0049192c  39f8                   +cmp eax, edi
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
    // 0049192e  0f8dbf010000           -jge 0x491af3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_491af3(app, cpu);
    }
    // 00491934  a1907b5200             -mov eax, dword ptr [0x527b90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491939  39c2                   +cmp edx, eax
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
    // 0049193b  0f8eab010000           -jle 0x491aec
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_491aec(app, cpu);
    }
    // 00491941  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00491943  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491948  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049194a  e8b9d6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0049194f  892d947b5200           -mov dword ptr [0x527b94], ebp
    app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */) = cpu.ebp;
    // 00491955  39f1                   +cmp ecx, esi
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
    // 00491957  0f849d010000           -je 0x491afa
    if (cpu.flags.zf)
    {
        return sub_491afa(app, cpu);
    }
    // 0049195d  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491962  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491964  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491966  e8d546feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 0049196b  3b0d7c7b5200           +cmp ecx, dword ptr [0x527b7c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491971  0f8490010000           -je 0x491b07
    if (cpu.flags.zf)
    {
        return sub_491b07(app, cpu);
    }
    // 00491977  890d7c7b5200           -mov dword ptr [0x527b7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.ecx;
    // 0049197d  893d787b5200           -mov dword ptr [0x527b78], edi
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.edi;
L_entry_0x00491983:
    // 00491983  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00491988  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049198b  e890d6feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491990  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491992  740d                   -je 0x4919a1
    if (cpu.flags.zf)
    {
        goto L_0x004919a1;
    }
    // 00491994  833db4824c0000         +cmp dword ptr [0x4c82b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049199b  0f8577010000           -jne 0x491b18
    if (!cpu.flags.zf)
    {
        return sub_491b18(app, cpu);
    }
L_0x004919a1:
    // 004919a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004919a4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4919a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004919a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004919aa  7510                   -jne 0x4919bc
    if (!cpu.flags.zf)
    {
        goto L_0x004919bc;
    }
L_0x004919ac:
    // 004919ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004919ae  7407                   -je 0x4919b7
    if (cpu.flags.zf)
    {
        goto L_0x004919b7;
    }
    // 004919b0  a17c7b5200             -mov eax, dword ptr [0x527b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */);
    // 004919b5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004919b7:
    // 004919b7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004919b9  750d                   -jne 0x4919c8
    if (!cpu.flags.zf)
    {
        goto L_0x004919c8;
    }
    // 004919bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004919bc:
    // 004919bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004919bd  8b0d947b5200           -mov ecx, dword ptr [0x527b94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5405588) /* 0x527b94 */);
    // 004919c3  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004919c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004919c6  ebe4                   -jmp 0x4919ac
    goto L_0x004919ac;
L_0x004919c8:
    // 004919c8  a1787b5200             -mov eax, dword ptr [0x527b78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */);
    // 004919cd  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004919cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4919d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004919d0  ff15b0824c00           -call dword ptr [0x4c82b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014192) /* 0x4c82b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004919d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4919d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004919d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004919d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004919da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004919db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004919dc  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004919df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004919e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004919e3  e8c0d2feff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 004919e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004919ea  0f85a4000000           -jne 0x491a94
    if (!cpu.flags.zf)
    {
        goto L_0x00491a94;
    }
    // 004919f0  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 004919f5  e80ed6feff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
L_0x004919fa:
    // 004919fa  8b1d8c7b5200           -mov ebx, dword ptr [0x527b8c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 00491a00  39d9                   +cmp ecx, ebx
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
    // 00491a02  0f8e9d000000           -jle 0x491aa5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491aa5;
    }
    // 00491a08  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00491a0a:
    // 00491a0a  8b35847b5200           -mov esi, dword ptr [0x527b84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5405572) /* 0x527b84 */);
    // 00491a10  39f0                   +cmp eax, esi
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
    // 00491a12  0f8d9b000000           -jge 0x491ab3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491ab3;
    }
    // 00491a18  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491a19  8b3d8c7b5200           -mov edi, dword ptr [0x527b8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5405580) /* 0x527b8c */);
    // 00491a1f  39f9                   +cmp ecx, edi
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
    // 00491a21  0f8e85000000           -jle 0x491aac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491aac;
    }
L_0x00491a27:
    // 00491a27  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00491a28:
    // 00491a28  8b2d907b5200           -mov ebp, dword ptr [0x527b90]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491a2e  39ea                   +cmp edx, ebp
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
    // 00491a30  0f8e84000000           -jle 0x491aba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491aba;
    }
    // 00491a36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00491a38:
    // 00491a38  8b1d807b5200           -mov ebx, dword ptr [0x527b80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5405568) /* 0x527b80 */);
    // 00491a3e  39d8                   +cmp eax, ebx
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
    // 00491a40  7d0c                   -jge 0x491a4e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00491a4e;
    }
    // 00491a42  8b35907b5200           -mov esi, dword ptr [0x527b90]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5405584) /* 0x527b90 */);
    // 00491a48  39f2                   +cmp edx, esi
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
    // 00491a4a  7e75                   -jle 0x491ac1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491ac1;
    }
L_0x00491a4c:
    // 00491a4c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00491a4e:
    // 00491a4e  890dcc814c00           -mov dword ptr [0x4c81cc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5013964) /* 0x4c81cc */) = cpu.ecx;
    // 00491a54  a1cc814c00             -mov eax, dword ptr [0x4c81cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013964) /* 0x4c81cc */);
    // 00491a59  a37c7b5200             -mov dword ptr [0x527b7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5405564) /* 0x527b7c */) = cpu.eax;
    // 00491a5e  891dd0814c00           -mov dword ptr [0x4c81d0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5013968) /* 0x4c81d0 */) = cpu.ebx;
    // 00491a64  a1d0814c00             -mov eax, dword ptr [0x4c81d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013968) /* 0x4c81d0 */);
    // 00491a69  a3787b5200             -mov dword ptr [0x527b78], eax
    app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */) = cpu.eax;
    // 00491a6e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00491a70  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00491a75  e8c645feff             -call 0x476040
    cpu.esp -= 4;
    sub_476040(app, cpu);
    if (cpu.terminate) return;
    // 00491a7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491a7c  e827d2feff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 00491a81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491a83  7440                   -je 0x491ac5
    if (cpu.flags.zf)
    {
        goto L_0x00491ac5;
    }
    // 00491a85  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00491a87  e8381b0000             -call 0x4935c4
    cpu.esp -= 4;
    sub_4935c4(app, cpu);
    if (cpu.terminate) return;
    // 00491a8c  83c470                 +add esp, 0x70
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491a8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a92  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491a93  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491a94:
    // 00491a94  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00491a96  e8051b0000             -call 0x4935a0
    cpu.esp -= 4;
    sub_4935a0(app, cpu);
    if (cpu.terminate) return;
    // 00491a9b  e8bc48feff             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 00491aa0  e955ffffff             -jmp 0x4919fa
    goto L_0x004919fa;
L_0x00491aa5:
    // 00491aa5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491aa7  e95effffff             -jmp 0x491a0a
    goto L_0x00491a0a;
L_0x00491aac:
    // 00491aac  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00491aae  e974ffffff             -jmp 0x491a27
    goto L_0x00491a27;
L_0x00491ab3:
    // 00491ab3  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00491ab5  e96effffff             -jmp 0x491a28
    goto L_0x00491a28;
L_0x00491aba:
    // 00491aba  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00491abc  e977ffffff             -jmp 0x491a38
    goto L_0x00491a38;
L_0x00491ac1:
    // 00491ac1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00491ac3  eb87                   -jmp 0x491a4c
    goto L_0x00491a4c;
L_0x00491ac5:
    // 00491ac5  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 00491aca  e851d5feff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00491acf  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00491ad2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ad3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ad4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ad5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ad6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_491ad7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491ad7  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00491ad9  e91dfeffff             -jmp 0x4918fb
    return sub_4918fb(app, cpu);
}

/* align: skip  */
void Application::sub_491ade(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491ade  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00491ae0  e92ffeffff             -jmp 0x491914
    return sub_491914(app, cpu);
}

/* align: skip  */
void Application::sub_491ae5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491ae5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491ae7  e93afeffff             -jmp 0x491926
    return sub_491926(app, cpu);
}

/* align: skip  */
void Application::sub_491aec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491aec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491aee  e950feffff             -jmp 0x491943
    return sub_491943(app, cpu);
}

/* align: skip  */
void Application::sub_491af3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491af3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00491af5  e949feffff             -jmp 0x491943
    return sub_491943(app, cpu);
}

/* align: skip  */
void Application::sub_491afa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491afa  39d3                   +cmp ebx, edx
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
    // 00491afc  0f855bfeffff           -jne 0x49195d
    if (!cpu.flags.zf)
    {
        return sub_49195d(app, cpu);
    }
    // 00491b02  e964feffff             -jmp 0x49196b
    return sub_49196b(app, cpu);
}

/* align: skip  */
void Application::sub_491b07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491b07  3b3d787b5200           +cmp edi, dword ptr [0x527b78]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5405560) /* 0x527b78 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491b0d  0f8564feffff           -jne 0x491977
    if (!cpu.flags.zf)
    {
        return sub_491977(app, cpu);
    }
    // 00491b13  e96bfeffff             -jmp 0x491983
    return sub_491983(app, cpu);
}

/* align: skip  */
void Application::sub_491b18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491b18  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00491b1a  ff15b4824c00           -call dword ptr [0x4c82b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014196) /* 0x4c82b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491b20  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491b23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_491b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491b30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491b31  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00491b36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00491b38  e813000000             -call 0x491b50
    cpu.esp -= 4;
    sub_491b50(app, cpu);
    if (cpu.terminate) return;
    // 00491b3d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491b40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491b41  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491b46  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00491b48  e803000000             -call 0x491b50
    cpu.esp -= 4;
    sub_491b50(app, cpu);
    if (cpu.terminate) return;
    // 00491b4d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491b50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491b51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491b52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491b53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491b54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491b55  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491b58  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00491b5b  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00491b60  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00491b62  83f801                 +cmp eax, 1
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
    // 00491b65  7328                   -jae 0x491b8f
    if (!cpu.flags.cf)
    {
        goto L_0x00491b8f;
    }
    // 00491b67  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491b69  751b                   -jne 0x491b86
    if (!cpu.flags.zf)
    {
        goto L_0x00491b86;
    }
    // 00491b6b  b014                   -mov al, 0x14
    cpu.al = 20 /*0x14*/;
    // 00491b6d  b33a                   -mov bl, 0x3a
    cpu.bl = 58 /*0x3a*/;
L_0x00491b6f:
    // 00491b6f  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 00491b72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491b73  2eff15bc534b00         -call dword ptr cs:[0x4b53bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936636) /* 0x4b53bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491b7a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00491b7c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00491b7e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00491b81  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00491b82  39d0                   +cmp eax, edx
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
    // 00491b84  7525                   -jne 0x491bab
    if (!cpu.flags.zf)
    {
        goto L_0x00491bab;
    }
L_0x00491b86:
    // 00491b86  83c404                 +add esp, 4
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
    // 00491b89  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b8a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b8b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491b8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491b8f:
    // 00491b8f  7710                   -ja 0x491ba1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00491ba1;
    }
    // 00491b91  b090                   -mov al, 0x90
    cpu.al = 144 /*0x90*/;
    // 00491b93  b345                   -mov bl, 0x45
    cpu.bl = 69 /*0x45*/;
    // 00491b95  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00491b9a  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 00491b9f  ebce                   -jmp 0x491b6f
    goto L_0x00491b6f;
L_0x00491ba1:
    // 00491ba1  39e8                   +cmp eax, ebp
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
    // 00491ba3  75e1                   -jne 0x491b86
    if (!cpu.flags.zf)
    {
        goto L_0x00491b86;
    }
    // 00491ba5  b091                   -mov al, 0x91
    cpu.al = 145 /*0x91*/;
    // 00491ba7  b346                   -mov bl, 0x46
    cpu.bl = 70 /*0x46*/;
    // 00491ba9  ebc4                   -jmp 0x491b6f
    goto L_0x00491b6f;
L_0x00491bab:
    // 00491bab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491bad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491bae  0fb6fb                 -movzx edi, bl
    cpu.edi = x86::reg32(cpu.bl);
    // 00491bb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491bb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491bb3  2eff1518544b00         -call dword ptr cs:[0x4b5418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936728) /* 0x4b5418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491bba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00491bbc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491bbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491bbe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491bbf  2eff1518544b00         -call dword ptr cs:[0x4b5418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936728) /* 0x4b5418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00491bc6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491bc9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491bce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_491bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491bd0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491bd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_491be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491be0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00491be1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491be2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00491be3  8a15ec844c00           -mov dl, byte ptr [0x4c84ec]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00491be9  80fa0f                 +cmp dl, 0xf
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
    // 00491bec  0f8288000000           -jb 0x491c7a
    if (cpu.flags.cf)
    {
        goto L_0x00491c7a;
    }
    // 00491bf2  7737                   -ja 0x491c2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00491c2b;
    }
    // 00491bf4  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00491bf7  0f8475000000           -je 0x491c72
    if (cpu.flags.zf)
    {
        goto L_0x00491c72;
    }
    // 00491bfd  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
L_0x00491c02:
    // 00491c02  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491c04  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491c06  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00491c09  c1fb0a                 -sar ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (10 /*0xa*/ % 32));
    // 00491c0c  c1f905                 -sar ecx, 5
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (5 /*0x5*/ % 32));
    // 00491c0f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491c12  83e31f                 -and ebx, 0x1f
    cpu.ebx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491c15  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491c18  c1e313                 -shl ebx, 0x13
    cpu.ebx <<= 19 /*0x13*/ % 32;
    // 00491c1b  c1e10b                 -shl ecx, 0xb
    cpu.ecx <<= 11 /*0xb*/ % 32;
    // 00491c1e  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491c20  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00491c23  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491c25  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x00491c27:
    // 00491c27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c2a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491c2b:
    // 00491c2b  80fa18                 +cmp dl, 0x18
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00491c2e  7337                   -jae 0x491c67
    if (!cpu.flags.cf)
    {
        goto L_0x00491c67;
    }
    // 00491c30  80fa10                 +cmp dl, 0x10
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
    // 00491c33  7545                   -jne 0x491c7a
    if (!cpu.flags.zf)
    {
        goto L_0x00491c7a;
    }
    // 00491c35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00491c37  743d                   -je 0x491c76
    if (cpu.flags.zf)
    {
        goto L_0x00491c76;
    }
    // 00491c39  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
L_0x00491c3e:
    // 00491c3e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491c40  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00491c42  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00491c45  c1f90b                 -sar ecx, 0xb
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (11 /*0xb*/ % 32));
    // 00491c48  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 00491c4b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491c4e  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491c51  83e33f                 -and ebx, 0x3f
    cpu.ebx &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00491c54  c1e113                 -shl ecx, 0x13
    cpu.ecx <<= 19 /*0x13*/ % 32;
    // 00491c57  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 00491c5a  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491c5c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00491c5f  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491c61  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00491c63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491c67:
    // 00491c67  76be                   -jbe 0x491c27
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00491c27;
    }
    // 00491c69  80fa20                 +cmp dl, 0x20
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
    // 00491c6c  750c                   -jne 0x491c7a
    if (!cpu.flags.zf)
    {
        goto L_0x00491c7a;
    }
    // 00491c6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491c72:
    // 00491c72  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00491c74  eb8c                   -jmp 0x491c02
    goto L_0x00491c02;
L_0x00491c76:
    // 00491c76  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00491c78  ebc4                   -jmp 0x491c3e
    goto L_0x00491c3e;
L_0x00491c7a:
    // 00491c7a  8b0485a07b5200         -mov eax, dword ptr [eax*4 + 0x527ba0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5405600) /* 0x527ba0 */ + cpu.eax * 4);
    // 00491c81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491c84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_491c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491c90  43                     -inc ebx
    (cpu.ebx)++;
    // 00491c91  d1fb                   +sar ebx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00491c93  90                     -nop 
    ;
    // 00491c94  e9b7eafeff             -jmp 0x480750
    return sub_480750(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_491c9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491c9c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491c9d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491c9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491c9f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491ca1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491ca3  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00491ca5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491ca7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491ca9  7e2d                   -jle 0x491cd8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491cd8;
    }
    // 00491cab  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00491cad:
    // 00491cad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491caf  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00491cb1  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00491cb3  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00491cb5  7425                   -je 0x491cdc
    if (cpu.flags.zf)
    {
        goto L_0x00491cdc;
    }
    // 00491cb7  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00491cb9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491cbb  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00491cbe  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00491cc0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491cc2  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00491cc4  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
L_0x00491cc7:
    // 00491cc7  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491cc9  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00491ccb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491ccd  42                     -inc edx
    (cpu.edx)++;
    // 00491cce  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00491cd0  40                     -inc eax
    (cpu.eax)++;
    // 00491cd1  881c31                 -mov byte ptr [ecx + esi], bl
    app->getMemory<x86::reg8>(cpu.ecx + cpu.esi * 1) = cpu.bl;
    // 00491cd4  39f8                   +cmp eax, edi
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
    // 00491cd6  7cd5                   -jl 0x491cad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491cad;
    }
L_0x00491cd8:
    // 00491cd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491cd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491cda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491cdb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491cdc:
    // 00491cdc  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00491cde  80e3f0                 -and bl, 0xf0
    cpu.bl &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00491ce1  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00491ce3  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491ce9  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00491cec  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00491cf2  ebd3                   -jmp 0x491cc7
    goto L_0x00491cc7;
}

/* align: skip  */
void Application::sub_491cf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491cf4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491cf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491cf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491cf7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00491cf9  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00491cfb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491cfd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491cff  7e1e                   -jle 0x491d1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491d1f;
    }
L_0x00491d01:
    // 00491d01  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491d03  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 00491d05  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00491d07  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00491d09  7418                   -je 0x491d23
    if (cpu.flags.zf)
    {
        goto L_0x00491d23;
    }
    // 00491d0b  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00491d0d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491d13  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00491d16  42                     -inc edx
    (cpu.edx)++;
    // 00491d17  40                     -inc eax
    (cpu.eax)++;
    // 00491d18  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00491d1b  39f0                   +cmp eax, esi
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
    // 00491d1d  7ce2                   -jl 0x491d01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491d01;
    }
L_0x00491d1f:
    // 00491d1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491d23:
    // 00491d23  8a09                   -mov cl, byte ptr [ecx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00491d25  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00491d28  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00491d2e  42                     -inc edx
    (cpu.edx)++;
    // 00491d2f  40                     -inc eax
    (cpu.eax)++;
    // 00491d30  884aff                 -mov byte ptr [edx - 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00491d33  39f0                   +cmp eax, esi
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
    // 00491d35  7cca                   -jl 0x491d01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491d01;
    }
    // 00491d37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491d3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491d3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491d3c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491d3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491d3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491d3f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491d40  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00491d43  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491d45  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00491d47  8b1dc8824c00           -mov ebx, dword ptr [0x4c82c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014216) /* 0x4c82c8 */);
    // 00491d4d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491d4f  7563                   -jne 0x491db4
    if (!cpu.flags.zf)
    {
        goto L_0x00491db4;
    }
    // 00491d51  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491d53  7e57                   -jle 0x491dac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491dac;
    }
L_0x00491d55:
    // 00491d55  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00491d58  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00491d5d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00491d5f  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00491d62  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491d65  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00491d69  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00491d6b  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00491d6e  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00491d71  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491d74  897c240c               -mov dword ptr [esp + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00491d78  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00491d7c  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00491d80  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 00491d83  c1e50a                 -shl ebp, 0xa
    cpu.ebp <<= 10 /*0xa*/ % 32;
    // 00491d86  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00491d8c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00491d8f  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00491d91  42                     -inc edx
    (cpu.edx)++;
    // 00491d92  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00491d94  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491d97  e8c047feff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00491d9c  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00491da0  43                     -inc ebx
    (cpu.ebx)++;
    // 00491da1  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00491da5  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00491da8  39f3                   +cmp ebx, esi
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
    // 00491daa  7ca9                   -jl 0x491d55
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491d55;
    }
L_0x00491dac:
    // 00491dac  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00491daf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491db0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491db1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491db2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491db3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491db4:
    // 00491db4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491db6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00491db8  7ef2                   -jle 0x491dac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491dac;
    }
L_0x00491dba:
    // 00491dba  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00491dbd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00491dc2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00491dc4  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00491dc7  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491dca  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00491dcd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00491dcf  c1ff05                 -sar edi, 5
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (5 /*0x5*/ % 32));
    // 00491dd2  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491dd5  83e73f                 -and edi, 0x3f
    cpu.edi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 00491dd8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00491ddc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00491ddf  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00491de1  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 00491de4  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 00491de7  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 00491de9  0b442404               -or eax, dword ptr [esp + 4]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00491ded  8b3dc8824c00           -mov edi, dword ptr [0x4c82c8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5014216) /* 0x4c82c8 */);
    // 00491df3  42                     -inc edx
    (cpu.edx)++;
    // 00491df4  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491df7  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 00491dfa  43                     -inc ebx
    (cpu.ebx)++;
    // 00491dfb  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00491dfe  39f3                   +cmp ebx, esi
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
    // 00491e00  7cb8                   -jl 0x491dba
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491dba;
    }
    // 00491e02  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00491e05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e09  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491e0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491e0c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491e0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491e0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491e0f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491e10  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491e12  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00491e14  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00491e16  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00491e18  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491e1a  7e1b                   -jle 0x491e37
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491e37;
    }
L_0x00491e1c:
    // 00491e1c  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00491e1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491e20  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491e26  7314                   -jae 0x491e3c
    if (!cpu.flags.cf)
    {
        goto L_0x00491e3c;
    }
L_0x00491e28:
    // 00491e28  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491e2b  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491e2e  47                     -inc edi
    (cpu.edi)++;
    // 00491e2f  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00491e33  39ef                   +cmp edi, ebp
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
    // 00491e35  7ce5                   -jl 0x491e1c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491e1c;
    }
L_0x00491e37:
    // 00491e37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491e3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491e3c:
    // 00491e3c  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00491e3e  7425                   -je 0x491e65
    if (cpu.flags.zf)
    {
        goto L_0x00491e65;
    }
    // 00491e40  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491e42  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00491e48  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00491e4b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491e4d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00491e50  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00491e56  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00491e59  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491e5c  01c3                   +add ebx, eax
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491e5e  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00491e65:
    // 00491e65  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491e67  ebbf                   -jmp 0x491e28
    goto L_0x00491e28;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_491e6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491e6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491e6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491e6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491e6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491e70  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491e72  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491e74  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00491e76  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00491e78  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491e7a  7e3c                   -jle 0x491eb8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491eb8;
    }
L_0x00491e7c:
    // 00491e7c  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00491e7e  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00491e80  7425                   -je 0x491ea7
    if (cpu.flags.zf)
    {
        goto L_0x00491ea7;
    }
    // 00491e82  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491e84  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00491e8a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00491e8d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491e8f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00491e92  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00491e98  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00491e9b  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491e9e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491ea0  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x00491ea7:
    // 00491ea7  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491eaa  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491ead  47                     -inc edi
    (cpu.edi)++;
    // 00491eae  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00491eb2  39ef                   +cmp edi, ebp
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
    // 00491eb4  7cc6                   -jl 0x491e7c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491e7c;
    }
    // 00491eb6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00491eb8:
    // 00491eb8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491eba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ebb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ebc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_491ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491ec0  01db                   +add ebx, ebx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00491ec2  e989e8feff             -jmp 0x480750
    return sub_480750(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_491ec8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491ec8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491ec9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491eca  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00491ecc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491ece  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491ed0  7e12                   -jle 0x491ee4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491ee4;
    }
L_0x00491ed2:
    // 00491ed2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491ed5  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00491ed8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491edb  41                     -inc ecx
    (cpu.ecx)++;
    // 00491edc  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00491ee0  39f1                   +cmp ecx, esi
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
    // 00491ee2  7cee                   -jl 0x491ed2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491ed2;
    }
L_0x00491ee4:
    // 00491ee4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ee5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ee6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491ee8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491ee8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491ee9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491eea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491eeb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491eec  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00491eee  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00491ef0  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00491ef2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00491ef4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491ef6  7e1b                   -jle 0x491f13
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491f13;
    }
L_0x00491ef8:
    // 00491ef8  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00491efa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00491efc  81fb00000040           +cmp ebx, 0x40000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1073741824 /*0x40000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00491f02  7314                   -jae 0x491f18
    if (!cpu.flags.cf)
    {
        goto L_0x00491f18;
    }
L_0x00491f04:
    // 00491f04  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491f07  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491f0a  47                     -inc edi
    (cpu.edi)++;
    // 00491f0b  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 00491f0f  39ef                   +cmp edi, ebp
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
    // 00491f11  7ce5                   -jl 0x491ef8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491ef8;
    }
L_0x00491f13:
    // 00491f13  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f14  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00491f18:
    // 00491f18  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491f1a  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00491f20  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00491f23  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491f25  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00491f28  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00491f2e  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00491f31  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491f34  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491f36  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00491f38  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491f3a  6685db                 +test bx, bx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & cpu.bx));
    // 00491f3d  75c5                   -jne 0x491f04
    if (!cpu.flags.zf)
    {
        goto L_0x00491f04;
    }
    // 00491f3f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00491f44  ebbe                   -jmp 0x491f04
    goto L_0x00491f04;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_491f48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491f48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491f49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491f4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491f4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491f4c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00491f4e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00491f50  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00491f52  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00491f54  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491f56  7e34                   -jle 0x491f8c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491f8c;
    }
L_0x00491f58:
    // 00491f58  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00491f5a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00491f5c  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00491f62  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00491f65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00491f67  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00491f6a  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00491f70  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00491f73  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00491f76  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00491f78  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00491f7a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491f7d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491f80  47                     -inc edi
    (cpu.edi)++;
    // 00491f81  66895efe               -mov word ptr [esi - 2], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00491f85  39ef                   +cmp edi, ebp
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
    // 00491f87  7ccf                   -jl 0x491f58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491f58;
    }
    // 00491f89  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00491f8c:
    // 00491f8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491f90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_491f94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491f94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491f95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491f96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491f97  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00491f9a  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00491f9e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00491fa0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00491fa2  7e4c                   -jle 0x491ff0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00491ff0;
    }
L_0x00491fa4:
    // 00491fa4  0fb67003               -movzx esi, byte ptr [eax + 3]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 00491fa8  0fb67801               -movzx edi, byte ptr [eax + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 00491fac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491fae  c1fe04                 -sar esi, 4
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (4 /*0x4*/ % 32));
    // 00491fb1  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00491fb4  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00491fb7  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 00491fba  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00491fbe  c1e60c                 -shl esi, 0xc
    cpu.esi <<= 12 /*0xc*/ % 32;
    // 00491fc1  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00491fc4  0fb638                 -movzx edi, byte ptr [eax]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 00491fc7  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00491fc9  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00491fcd  c1ff04                 -sar edi, 4
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (4 /*0x4*/ % 32));
    // 00491fd0  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00491fd3  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00491fd6  09f3                   -or ebx, esi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00491fd8  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00491fdb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491fde  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00491fe0  41                     -inc ecx
    (cpu.ecx)++;
    // 00491fe1  668932                 -mov word ptr [edx], si
    app->getMemory<x86::reg16>(cpu.edx) = cpu.si;
    // 00491fe4  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00491fe8  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00491feb  39f1                   +cmp ecx, esi
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
    // 00491fed  7cb5                   -jl 0x491fa4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00491fa4;
    }
    // 00491fef  90                     -nop 
    ;
L_0x00491ff0:
    // 00491ff0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00491ff3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ff4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ff5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00491ff6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_491ff8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00491ff8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00491ff9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00491ffa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00491ffb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00491ffc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00491fff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492001  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00492003  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00492006  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00492008  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049200a  7e3c                   -jle 0x492048
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492048;
    }
L_0x0049200c:
    // 0049200c  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0049200e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492011  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492013  81e1000000ff           -and ecx, 0xff000000
    cpu.ecx &= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00492019  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049201b  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00492021  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00492024  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492026  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00492029  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 0049202f  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00492032  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00492035  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492037  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492039  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049203b  45                     -inc ebp
    (cpu.ebp)++;
    // 0049203c  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0049203e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00492041  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492044  39cd                   +cmp ebp, ecx
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
    // 00492046  7cc4                   -jl 0x49200c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049200c;
    }
L_0x00492048:
    // 00492048  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049204b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049204c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049204d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049204e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049204f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_492050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492050  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492051  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492052  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492053  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492054  8b2d1ca94c00           -mov ebp, dword ptr [0x4ca91c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */);
    // 0049205a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049205c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049205e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00492060  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492062  7e28                   -jle 0x49208c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049208c;
    }
L_0x00492064:
    // 00492064  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492066  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00492068  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0049206f  8d042b                 -lea eax, [ebx + ebp]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 00492072  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00492075  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00492078  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0049207b  41                     -inc ecx
    (cpu.ecx)++;
    // 0049207c  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 0049207f  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00492082  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00492084  46                     -inc esi
    (cpu.esi)++;
    // 00492085  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 00492088  39fe                   +cmp esi, edi
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
    // 0049208a  7cd8                   -jl 0x492064
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492064;
    }
L_0x0049208c:
    // 0049208c  892d1ca94c00           -mov dword ptr [0x4ca91c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */) = cpu.ebp;
    // 00492092  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492093  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492094  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492095  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492096  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492098  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492099  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049209a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049209b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049209e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004920a0  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004920a2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004920a4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004920a6  7e50                   -jle 0x4920f8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004920f8;
    }
L_0x004920a8:
    // 004920a8  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004920ab  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004920b0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004920b2  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 004920b5  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004920b8  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004920bb  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004920be  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004920c1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004920c3  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004920c6  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 004920c9  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004920cc  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004920cf  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004920d3  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004920d6  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004920da  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004920de  8842fd                 -mov byte ptr [edx - 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 004920e1  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004920e5  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004920e8  8842fe                 -mov byte ptr [edx - 2], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.al;
    // 004920eb  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004920ee  43                     -inc ebx
    (cpu.ebx)++;
    // 004920ef  8842ff                 -mov byte ptr [edx - 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004920f2  39fb                   +cmp ebx, edi
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
    // 004920f4  7cb2                   -jl 0x4920a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004920a8;
    }
    // 004920f6  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004920f8:
    // 004920f8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004920fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004920fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492101  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492103  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0049210a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049210c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049210e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492110  e83be6feff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00492115  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492116  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492118(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492118  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492119  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049211a  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0049211d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049211f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00492121  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492123  7e3b                   -jle 0x492160
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492160;
    }
L_0x00492125:
    // 00492125  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492127  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0049212a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049212d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049212f  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00492132  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00492136  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492138  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049213a  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0049213e  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00492141  8a5c2408               -mov bl, byte ptr [esp + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492145  885afd                 -mov byte ptr [edx - 3], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */) = cpu.bl;
    // 00492148  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049214c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049214f  885afe                 -mov byte ptr [edx - 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bl;
    // 00492152  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 00492155  41                     -inc ecx
    (cpu.ecx)++;
    // 00492156  885aff                 -mov byte ptr [edx - 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 00492159  39f1                   +cmp ecx, esi
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
    // 0049215b  7cc8                   -jl 0x492125
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492125;
    }
    // 0049215d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00492160:
    // 00492160  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00492163  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492165  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_492168(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492168  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492169  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049216a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049216b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049216c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049216f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492171  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00492174  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00492177  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492179  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049217b  7e48                   -jle 0x4921c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004921c5;
    }
L_0x0049217d:
    // 0049217d  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00492180  8b2d14a94c00           -mov ebp, dword ptr [0x4ca914]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5024020) /* 0x4ca914 */);
    // 00492186  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0049218b  39e8                   +cmp eax, ebp
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
    // 0049218d  743e                   -je 0x4921cd
    if (cpu.flags.zf)
    {
        goto L_0x004921cd;
    }
    // 0049218f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492191  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492193  c1ff0a                 -sar edi, 0xa
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (10 /*0xa*/ % 32));
    // 00492196  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 00492199  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049219c  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049219f  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004921a2  c1e713                 -shl edi, 0x13
    cpu.edi <<= 19 /*0x13*/ % 32;
    // 004921a5  c1e60b                 -shl esi, 0xb
    cpu.esi <<= 11 /*0xb*/ % 32;
    // 004921a8  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004921ae  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004921b1  09fe                   -or esi, edi
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edi));
    // 004921b3  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004921b5  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x004921b7:
    // 004921b7  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004921ba  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004921bd  43                     -inc ebx
    (cpu.ebx)++;
    // 004921be  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004921c1  39fb                   +cmp ebx, edi
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
    // 004921c3  7cb8                   -jl 0x49217d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049217d;
    }
L_0x004921c5:
    // 004921c5  83c404                 +add esp, 4
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
    // 004921c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004921cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004921cd:
    // 004921cd  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004921d3  ebe2                   -jmp 0x4921b7
    goto L_0x004921b7;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4921d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004921d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004921d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004921da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004921db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004921dc  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004921df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004921e1  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004921e5  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004921e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004921eb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004921ed  7e50                   -jle 0x49223f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049223f;
    }
L_0x004921ef:
    // 004921ef  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004921f2  8b2d14a94c00           -mov ebp, dword ptr [0x4ca914]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5024020) /* 0x4ca914 */);
    // 004921f8  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004921fd  39e8                   +cmp eax, ebp
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
    // 004921ff  7446                   -je 0x492247
    if (cpu.flags.zf)
    {
        goto L_0x00492247;
    }
    // 00492201  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492203  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492205  c1ff0b                 -sar edi, 0xb
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (11 /*0xb*/ % 32));
    // 00492208  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0049220b  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0049220e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00492211  83e71f                 -and edi, 0x1f
    cpu.edi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00492214  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00492217  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492219  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049221c  c1e013                 -shl eax, 0x13
    cpu.eax <<= 19 /*0x13*/ % 32;
    // 0049221f  c1e60a                 -shl esi, 0xa
    cpu.esi <<= 10 /*0xa*/ % 32;
    // 00492222  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00492227  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00492229  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0049222c  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 0049222e  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
L_0x00492230:
    // 00492230  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00492234  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00492237  43                     -inc ebx
    (cpu.ebx)++;
    // 00492238  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049223b  39fb                   +cmp ebx, edi
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
    // 0049223d  7cb0                   -jl 0x4921ef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004921ef;
    }
L_0x0049223f:
    // 0049223f  83c408                 +add esp, 8
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
    // 00492242  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492243  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492244  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492245  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492246  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492247:
    // 00492247  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0049224d  ebe1                   -jmp 0x492230
    goto L_0x00492230;
}

/* align: skip 0x90 */
void Application::sub_492250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492251  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492252  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492253  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492254  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492257  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492259  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049225b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0049225e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00492260  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00492264  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492266  7e68                   -jle 0x4922d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004922d0;
    }
L_0x00492268:
    // 00492268  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 0049226b  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00492270  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492272  c1f90c                 -sar ecx, 0xc
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (12 /*0xc*/ % 32));
    // 00492275  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00492278  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049227a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049227c  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 0049227f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00492282  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00492285  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00492287  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00492289  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0049228c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049228f  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 00492291  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492293  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492296  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 00492299  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 0049229c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0049229f  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004922a2  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004922a4  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004922a7  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 004922aa  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004922ac  09ea                   -or edx, ebp
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004922ae  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004922b0  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004922b3  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 004922b6  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004922b8  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004922ba  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004922bc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004922c0  8956fc                 -mov dword ptr [esi - 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004922c3  40                     -inc eax
    (cpu.eax)++;
    // 004922c4  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004922c7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004922cb  39d0                   +cmp eax, edx
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
    // 004922cd  7c99                   -jl 0x492268
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492268;
    }
    // 004922cf  90                     -nop 
    ;
L_0x004922d0:
    // 004922d0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004922d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004922d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4922d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004922d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004922d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004922da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004922db  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004922de  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004922e0  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004922e4  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004922e8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004922ea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004922ec  7e56                   -jle 0x492344
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492344;
    }
L_0x004922ee:
    // 004922ee  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004922f1  0fb67803               -movzx edi, byte ptr [eax + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */));
    // 004922f5  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004922fb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004922fd  c1fe0b                 -sar esi, 0xb
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (11 /*0xb*/ % 32));
    // 00492300  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00492303  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00492306  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00492308  c1fe05                 -sar esi, 5
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (5 /*0x5*/ % 32));
    // 0049230b  83e63f                 -and esi, 0x3f
    cpu.esi &= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 0049230e  83e21f                 -and edx, 0x1f
    cpu.edx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00492311  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00492315  8d34d500000000         -lea esi, [edx*8]
    cpu.esi = x86::reg32(cpu.edx * 8);
    // 0049231c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049231f  c1e718                 -shl edi, 0x18
    cpu.edi <<= 24 /*0x18*/ % 32;
    // 00492322  c1e213                 -shl edx, 0x13
    cpu.edx <<= 19 /*0x13*/ % 32;
    // 00492325  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00492327  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049232b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049232e  c1e70a                 -shl edi, 0xa
    cpu.edi <<= 10 /*0xa*/ % 32;
    // 00492331  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492334  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00492336  43                     -inc ebx
    (cpu.ebx)++;
    // 00492337  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00492339  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049233d  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00492340  39f3                   +cmp ebx, esi
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
    // 00492342  7caa                   -jl 0x4922ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004922ee;
    }
L_0x00492344:
    // 00492344  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00492347  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492348  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492349  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049234a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_49234c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049234c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049234d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049234e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049234f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492350  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492353  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00492356  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00492358  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049235a  7e34                   -jle 0x492390
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492390;
    }
L_0x0049235c:
    // 0049235c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049235e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492361  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00492364  0fb67001               -movzx esi, byte ptr [eax + 1]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */));
    // 00492368  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0049236a  0fb628                 -movzx ebp, byte ptr [eax]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 0049236d  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 00492370  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00492372  81cf000000ff           -or edi, 0xff000000
    cpu.edi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00492378  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0049237b  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0049237e  09fb                   -or ebx, edi
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edi));
    // 00492380  41                     -inc ecx
    (cpu.ecx)++;
    // 00492381  09eb                   -or ebx, ebp
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00492383  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00492386  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00492389  39f1                   +cmp ecx, esi
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
    // 0049238b  7ccf                   -jl 0x49235c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049235c;
    }
    // 0049238d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00492390:
    // 00492390  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492393  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492394  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492395  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492396  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492397  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_492398(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492398  c1e302                 +shl ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049239b  e9b0e3feff             -jmp 0x480750
    return sub_480750(app, cpu);
}

/* align: skip  */
void Application::sub_4923a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004923a0  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923a3  7312                   -jae 0x4923b7
    if (!cpu.flags.cf)
    {
        goto L_0x004923b7;
    }
    // 004923a5  83f804                 +cmp eax, 4
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
    // 004923a8  722c                   -jb 0x4923d6
    if (cpu.flags.cf)
    {
        goto L_0x004923d6;
    }
    // 004923aa  762a                   -jbe 0x4923d6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923ac  83f808                 +cmp eax, 8
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
    // 004923af  7525                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004923b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923b7:
    // 004923b7  7620                   -jbe 0x4923d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923d9;
    }
    // 004923b9  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923bc  730b                   -jae 0x4923c9
    if (!cpu.flags.cf)
    {
        goto L_0x004923c9;
    }
    // 004923be  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923c1  7513                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923c3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004923c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923c9:
    // 004923c9  7614                   -jbe 0x4923df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923df;
    }
    // 004923cb  83f820                 +cmp eax, 0x20
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
    // 004923ce  7506                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923d0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004923d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923d6:
    // 004923d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004923d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923d9:
    // 004923d9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004923de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923df:
    // 004923df  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004923e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4923d9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004923d9;
    // 004923a0  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923a3  7312                   -jae 0x4923b7
    if (!cpu.flags.cf)
    {
        goto L_0x004923b7;
    }
    // 004923a5  83f804                 +cmp eax, 4
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
    // 004923a8  722c                   -jb 0x4923d6
    if (cpu.flags.cf)
    {
        goto L_0x004923d6;
    }
    // 004923aa  762a                   -jbe 0x4923d6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923ac  83f808                 +cmp eax, 8
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
    // 004923af  7525                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004923b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923b7:
    // 004923b7  7620                   -jbe 0x4923d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923d9;
    }
    // 004923b9  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923bc  730b                   -jae 0x4923c9
    if (!cpu.flags.cf)
    {
        goto L_0x004923c9;
    }
    // 004923be  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923c1  7513                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923c3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004923c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923c9:
    // 004923c9  7614                   -jbe 0x4923df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923df;
    }
    // 004923cb  83f820                 +cmp eax, 0x20
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
    // 004923ce  7506                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923d0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004923d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923d6:
    // 004923d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004923d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923d9:
L_entry_0x004923d9:
    // 004923d9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004923de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923df:
    // 004923df  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004923e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4923d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004923d0;
    // 004923a0  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923a3  7312                   -jae 0x4923b7
    if (!cpu.flags.cf)
    {
        goto L_0x004923b7;
    }
    // 004923a5  83f804                 +cmp eax, 4
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
    // 004923a8  722c                   -jb 0x4923d6
    if (cpu.flags.cf)
    {
        goto L_0x004923d6;
    }
    // 004923aa  762a                   -jbe 0x4923d6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923ac  83f808                 +cmp eax, 8
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
    // 004923af  7525                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004923b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923b7:
    // 004923b7  7620                   -jbe 0x4923d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923d9;
    }
    // 004923b9  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923bc  730b                   -jae 0x4923c9
    if (!cpu.flags.cf)
    {
        goto L_0x004923c9;
    }
    // 004923be  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923c1  7513                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923c3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004923c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923c9:
    // 004923c9  7614                   -jbe 0x4923df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923df;
    }
    // 004923cb  83f820                 +cmp eax, 0x20
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
    // 004923ce  7506                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
L_entry_0x004923d0:
    // 004923d0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004923d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923d6:
    // 004923d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004923d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923d9:
    // 004923d9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004923de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923df:
    // 004923df  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004923e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4923c3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004923c3;
    // 004923a0  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923a3  7312                   -jae 0x4923b7
    if (!cpu.flags.cf)
    {
        goto L_0x004923b7;
    }
    // 004923a5  83f804                 +cmp eax, 4
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
    // 004923a8  722c                   -jb 0x4923d6
    if (cpu.flags.cf)
    {
        goto L_0x004923d6;
    }
    // 004923aa  762a                   -jbe 0x4923d6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923ac  83f808                 +cmp eax, 8
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
    // 004923af  7525                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923b1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004923b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923b7:
    // 004923b7  7620                   -jbe 0x4923d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923d9;
    }
    // 004923b9  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923bc  730b                   -jae 0x4923c9
    if (!cpu.flags.cf)
    {
        goto L_0x004923c9;
    }
    // 004923be  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923c1  7513                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
L_entry_0x004923c3:
    // 004923c3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004923c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923c9:
    // 004923c9  7614                   -jbe 0x4923df
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923df;
    }
    // 004923cb  83f820                 +cmp eax, 0x20
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
    // 004923ce  7506                   -jne 0x4923d6
    if (!cpu.flags.zf)
    {
        goto L_0x004923d6;
    }
    // 004923d0  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004923d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923d6:
    // 004923d6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004923d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923d9:
    // 004923d9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004923de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923df:
    // 004923df  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004923e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4923e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004923e8  83f878                 +cmp eax, 0x78
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923eb  730f                   -jae 0x4923fc
    if (!cpu.flags.cf)
    {
        goto L_0x004923fc;
    }
    // 004923ed  83f842                 +cmp eax, 0x42
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(66 /*0x42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923f0  7335                   -jae 0x492427
    if (!cpu.flags.cf)
    {
        goto L_0x00492427;
    }
    // 004923f2  83f840                 +cmp eax, 0x40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004923f5  7248                   -jb 0x49243f
    if (cpu.flags.cf)
    {
        goto L_0x0049243f;
    }
    // 004923f7  7716                   -ja 0x49240f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0049240f;
    }
L_0x004923f9:
    // 004923f9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004923fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004923fc:
    // 004923fc  76c5                   -jbe 0x4923c3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4923c3(app, cpu);
    }
    // 004923fe  83f87d                 +cmp eax, 0x7d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(125 /*0x7d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492401  7312                   -jae 0x492415
    if (!cpu.flags.cf)
    {
        goto L_0x00492415;
    }
    // 00492403  83f87a                 +cmp eax, 0x7a
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
    // 00492406  7237                   -jb 0x49243f
    if (cpu.flags.cf)
    {
        goto L_0x0049243f;
    }
    // 00492408  76ef                   -jbe 0x4923f9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004923f9;
    }
    // 0049240a  83f87b                 +cmp eax, 0x7b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(123 /*0x7b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049240d  7530                   -jne 0x49243f
    if (!cpu.flags.zf)
    {
        goto L_0x0049243f;
    }
L_0x0049240f:
    // 0049240f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00492414  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492415:
    // 00492415  76b9                   -jbe 0x4923d0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4923d0(app, cpu);
    }
    // 00492417  83f87e                 +cmp eax, 0x7e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(126 /*0x7e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049241a  76bd                   -jbe 0x4923d9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_4923d9(app, cpu);
    }
    // 0049241c  83f87f                 +cmp eax, 0x7f
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
    // 0049241f  751e                   -jne 0x49243f
    if (!cpu.flags.zf)
    {
        goto L_0x0049243f;
    }
L_0x00492421:
    // 00492421  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00492426  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492427:
    // 00492427  7610                   -jbe 0x492439
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00492439;
    }
    // 00492429  83f843                 +cmp eax, 0x43
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049242c  76f3                   -jbe 0x492421
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00492421;
    }
    // 0049242e  83f86d                 +cmp eax, 0x6d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(109 /*0x6d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492431  750c                   -jne 0x49243f
    if (!cpu.flags.zf)
    {
        goto L_0x0049243f;
    }
    // 00492433  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00492438  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492439:
    // 00492439  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0049243e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049243f:
    // 0049243f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00492444  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492448  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492449  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049244a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049244b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049244c  81ec00020000           -sub esp, 0x200
    (cpu.esp) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00492452  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00492454  e87797ffff             -call 0x48bbd0
    cpu.esp -= 4;
    sub_48bbd0(app, cpu);
    if (cpu.terminate) return;
    // 00492459  bfa07b5200             -mov edi, 0x527ba0
    cpu.edi = 5405600 /*0x527ba0*/;
    // 0049245e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492460  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492462  7448                   -je 0x4924ac
    if (cpu.flags.zf)
    {
        goto L_0x004924ac;
    }
    // 00492464  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00492466  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049246c  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049246f  83fe2a                 +cmp esi, 0x2a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492472  7445                   -je 0x4924b9
    if (cpu.flags.zf)
    {
        goto L_0x004924b9;
    }
    // 00492474  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00492477  c781fc03000000000000   -mov dword ptr [ecx + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00492481  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00492483  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00492485  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049248b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0049248e  83fa24                 +cmp edx, 0x24
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
    // 00492491  742a                   -je 0x4924bd
    if (cpu.flags.zf)
    {
        goto L_0x004924bd;
    }
    // 00492493  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492496  7432                   -je 0x4924ca
    if (cpu.flags.zf)
    {
        goto L_0x004924ca;
    }
    // 00492498  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049249b  7438                   -je 0x4924d5
    if (cpu.flags.zf)
    {
        goto L_0x004924d5;
    }
    // 0049249d  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004924a0  743e                   -je 0x4924e0
    if (cpu.flags.zf)
    {
        goto L_0x004924e0;
    }
    // 004924a2  83fa22                 +cmp edx, 0x22
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
    // 004924a5  7444                   -je 0x4924eb
    if (cpu.flags.zf)
    {
        goto L_0x004924eb;
    }
    // 004924a7  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004924aa  744c                   -je 0x4924f8
    if (cpu.flags.zf)
    {
        goto L_0x004924f8;
    }
L_0x004924ac:
    // 004924ac  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004924ae  81c400020000           +add esp, 0x200
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004924b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004924b8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004924b9:
    // 004924b9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004924bb  ebef                   -jmp 0x4924ac
    goto L_0x004924ac;
L_0x004924bd:
    // 004924bd  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004924bf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004924c1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004924c3  e8ccc20000             -call 0x49e794
    cpu.esp -= 4;
    sub_49e794(app, cpu);
    if (cpu.terminate) return;
    // 004924c8  ebe2                   -jmp 0x4924ac
    goto L_0x004924ac;
L_0x004924ca:
    // 004924ca  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004924cc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004924ce  e805fdffff             -call 0x4921d8
    cpu.esp -= 4;
    sub_4921d8(app, cpu);
    if (cpu.terminate) return;
    // 004924d3  ebd7                   -jmp 0x4924ac
    goto L_0x004924ac;
L_0x004924d5:
    // 004924d5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004924d7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004924d9  e88afcffff             -call 0x492168
    cpu.esp -= 4;
    sub_492168(app, cpu);
    if (cpu.terminate) return;
    // 004924de  ebcc                   -jmp 0x4924ac
    goto L_0x004924ac;
L_0x004924e0:
    // 004924e0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004924e2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004924e4  e8effdffff             -call 0x4922d8
    cpu.esp -= 4;
    sub_4922d8(app, cpu);
    if (cpu.terminate) return;
    // 004924e9  ebc1                   -jmp 0x4924ac
    goto L_0x004924ac;
L_0x004924eb:
    // 004924eb  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004924ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004924ef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004924f1  e8aac10000             -call 0x49e6a0
    cpu.esp -= 4;
    sub_49e6a0(app, cpu);
    if (cpu.terminate) return;
    // 004924f6  ebb4                   -jmp 0x4924ac
    goto L_0x004924ac;
L_0x004924f8:
    // 004924f8  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 004924fd  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004924ff  e8cc3b0000             -call 0x4960d0
    cpu.esp -= 4;
    sub_4960d0(app, cpu);
    if (cpu.terminate) return;
    // 00492504  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00492509  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049250b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049250d  e856fcffff             -call 0x492168
    cpu.esp -= 4;
    sub_492168(app, cpu);
    if (cpu.terminate) return;
    // 00492512  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492514  81c400020000           -add esp, 0x200
    (cpu.esp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0049251a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049251b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049251c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049251d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049251e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492520  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492521  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492522  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492523  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492524  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049252a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049252c  e89f96ffff             -call 0x48bbd0
    cpu.esp -= 4;
    sub_48bbd0(app, cpu);
    if (cpu.terminate) return;
    // 00492531  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492533  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492535  0f84b4000000           -je 0x4925ef
    if (cpu.flags.zf)
    {
        goto L_0x004925ef;
    }
    // 0049253b  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049253d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492543  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492546  83fb29                 +cmp ebx, 0x29
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492549  7444                   -je 0x49258f
    if (cpu.flags.zf)
    {
        goto L_0x0049258f;
    }
    // 0049254b  8b7202                 -mov esi, dword ptr [edx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049254e  66c781fe0100000000     -mov word ptr [ecx + 0x1fe], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(510) /* 0x1fe */) = 0 /*0x0*/;
    // 00492557  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00492559  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0049255b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492561  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00492564  83fa24                 +cmp edx, 0x24
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
    // 00492567  742a                   -je 0x492593
    if (cpu.flags.zf)
    {
        goto L_0x00492593;
    }
    // 00492569  83fa2c                 +cmp edx, 0x2c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049256c  743d                   -je 0x4925ab
    if (cpu.flags.zf)
    {
        goto L_0x004925ab;
    }
    // 0049256e  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492571  7443                   -je 0x4925b6
    if (cpu.flags.zf)
    {
        goto L_0x004925b6;
    }
    // 00492573  83fa2a                 +cmp edx, 0x2a
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
    // 00492576  7428                   -je 0x4925a0
    if (cpu.flags.zf)
    {
        goto L_0x004925a0;
    }
    // 00492578  83fa22                 +cmp edx, 0x22
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
    // 0049257b  7444                   -je 0x4925c1
    if (cpu.flags.zf)
    {
        goto L_0x004925c1;
    }
    // 0049257d  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492580  7457                   -je 0x4925d9
    if (cpu.flags.zf)
    {
        goto L_0x004925d9;
    }
L_0x00492582:
    // 00492582  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492584  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049258a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049258b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049258c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049258d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049258e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049258f:
    // 0049258f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492591  ebef                   -jmp 0x492582
    goto L_0x00492582;
L_0x00492593:
    // 00492593  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00492595  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492597  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492599  e8f6c10000             -call 0x49e794
    cpu.esp -= 4;
    sub_49e794(app, cpu);
    if (cpu.terminate) return;
    // 0049259e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004925a0:
    // 004925a0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004925a2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004925a4  e83ff9ffff             -call 0x491ee8
    cpu.esp -= 4;
    sub_491ee8(app, cpu);
    if (cpu.terminate) return;
    // 004925a9  ebd7                   -jmp 0x492582
    goto L_0x00492582;
L_0x004925ab:
    // 004925ab  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004925ad  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004925af  e814f9ffff             -call 0x491ec8
    cpu.esp -= 4;
    sub_491ec8(app, cpu);
    if (cpu.terminate) return;
    // 004925b4  ebcc                   -jmp 0x492582
    goto L_0x00492582;
L_0x004925b6:
    // 004925b6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004925b8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004925ba  e8a9fbffff             -call 0x492168
    cpu.esp -= 4;
    sub_492168(app, cpu);
    if (cpu.terminate) return;
    // 004925bf  ebc1                   -jmp 0x492582
    goto L_0x00492582;
L_0x004925c1:
    // 004925c1  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004925c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004925c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004925c7  e8d4c00000             -call 0x49e6a0
    cpu.esp -= 4;
    sub_49e6a0(app, cpu);
    if (cpu.terminate) return;
    // 004925cc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004925ce  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004925d0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004925d2  e811f9ffff             -call 0x491ee8
    cpu.esp -= 4;
    sub_491ee8(app, cpu);
    if (cpu.terminate) return;
    // 004925d7  eba9                   -jmp 0x492582
    goto L_0x00492582;
L_0x004925d9:
    // 004925d9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004925db  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004925dd  e8ee3a0000             -call 0x4960d0
    cpu.esp -= 4;
    sub_4960d0(app, cpu);
    if (cpu.terminate) return;
    // 004925e2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004925e4  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004925ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004925ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004925ef:
    // 004925ef  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 004925f4  b8a07b5200             -mov eax, 0x527ba0
    cpu.eax = 5405600 /*0x527ba0*/;
    // 004925f9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004925fb  e8e8f8ffff             -call 0x491ee8
    cpu.esp -= 4;
    sub_491ee8(app, cpu);
    if (cpu.terminate) return;
    // 00492600  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00492602  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492604  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049260a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049260b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049260c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049260d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049260e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_492610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492612  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492613  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492614  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0049261a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0049261c  e8af95ffff             -call 0x48bbd0
    cpu.esp -= 4;
    sub_48bbd0(app, cpu);
    if (cpu.terminate) return;
    // 00492621  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492623  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492625  0f84e1000000           -je 0x49270c
    if (cpu.flags.zf)
    {
        goto L_0x0049270c;
    }
    // 0049262b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049262d  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492633  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492636  83f92c                 +cmp ecx, 0x2c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492639  7445                   -je 0x492680
    if (cpu.flags.zf)
    {
        goto L_0x00492680;
    }
    // 0049263b  8b4a02                 -mov ecx, dword ptr [edx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049263e  c786fc03000000000000   -mov dword ptr [esi + 0x3fc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1020) /* 0x3fc */) = 0 /*0x0*/;
    // 00492648  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0049264a  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049264c  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492652  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00492655  83fa24                 +cmp edx, 0x24
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
    // 00492658  742a                   -je 0x492684
    if (cpu.flags.zf)
    {
        goto L_0x00492684;
    }
    // 0049265a  83fa29                 +cmp edx, 0x29
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049265d  743d                   -je 0x49269c
    if (cpu.flags.zf)
    {
        goto L_0x0049269c;
    }
    // 0049265f  83fa2d                 +cmp edx, 0x2d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492662  744e                   -je 0x4926b2
    if (cpu.flags.zf)
    {
        goto L_0x004926b2;
    }
    // 00492664  83fa2a                 +cmp edx, 0x2a
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
    // 00492667  7454                   -je 0x4926bd
    if (cpu.flags.zf)
    {
        goto L_0x004926bd;
    }
    // 00492669  83fa22                 +cmp edx, 0x22
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
    // 0049266c  745a                   -je 0x4926c8
    if (cpu.flags.zf)
    {
        goto L_0x004926c8;
    }
    // 0049266e  83fa23                 +cmp edx, 0x23
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(35 /*0x23*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492671  746d                   -je 0x4926e0
    if (cpu.flags.zf)
    {
        goto L_0x004926e0;
    }
L_0x00492673:
    // 00492673  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492675  81c400040000           +add esp, 0x400
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049267b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049267c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049267d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049267e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049267f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492680:
    // 00492680  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492682  ebef                   -jmp 0x492673
    goto L_0x00492673;
L_0x00492684:
    // 00492684  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00492686  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492688  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049268a  e805c10000             -call 0x49e794
    cpu.esp -= 4;
    sub_49e794(app, cpu);
    if (cpu.terminate) return;
    // 0049268f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492691  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492693  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00492695  e85ef9ffff             -call 0x491ff8
    cpu.esp -= 4;
    sub_491ff8(app, cpu);
    if (cpu.terminate) return;
    // 0049269a  ebd7                   -jmp 0x492673
    goto L_0x00492673;
L_0x0049269c:
    // 0049269c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049269e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004926a0  e833fbffff             -call 0x4921d8
    cpu.esp -= 4;
    sub_4921d8(app, cpu);
    if (cpu.terminate) return;
    // 004926a5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004926a7  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004926a9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004926ab  e848f9ffff             -call 0x491ff8
    cpu.esp -= 4;
    sub_491ff8(app, cpu);
    if (cpu.terminate) return;
    // 004926b0  ebc1                   -jmp 0x492673
    goto L_0x00492673;
L_0x004926b2:
    // 004926b2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004926b4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004926b6  e8adfaffff             -call 0x492168
    cpu.esp -= 4;
    sub_492168(app, cpu);
    if (cpu.terminate) return;
    // 004926bb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004926bd:
    // 004926bd  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004926bf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004926c1  e832f9ffff             -call 0x491ff8
    cpu.esp -= 4;
    sub_491ff8(app, cpu);
    if (cpu.terminate) return;
    // 004926c6  ebab                   -jmp 0x492673
    goto L_0x00492673;
L_0x004926c8:
    // 004926c8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004926ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004926cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004926ce  e8cdbf0000             -call 0x49e6a0
    cpu.esp -= 4;
    sub_49e6a0(app, cpu);
    if (cpu.terminate) return;
    // 004926d3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004926d5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004926d7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004926d9  e81af9ffff             -call 0x491ff8
    cpu.esp -= 4;
    sub_491ff8(app, cpu);
    if (cpu.terminate) return;
    // 004926de  eb93                   -jmp 0x492673
    goto L_0x00492673;
L_0x004926e0:
    // 004926e0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004926e2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004926e4  e8e7390000             -call 0x4960d0
    cpu.esp -= 4;
    sub_4960d0(app, cpu);
    if (cpu.terminate) return;
    // 004926e9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004926eb  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004926ed  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004926ef  e8e4faffff             -call 0x4921d8
    cpu.esp -= 4;
    sub_4921d8(app, cpu);
    if (cpu.terminate) return;
    // 004926f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004926f6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004926f8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004926fa  e8f9f8ffff             -call 0x491ff8
    cpu.esp -= 4;
    sub_491ff8(app, cpu);
    if (cpu.terminate) return;
    // 004926ff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492701  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00492707  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492708  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492709  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049270a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049270b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049270c:
    // 0049270c  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00492711  b8a07b5200             -mov eax, 0x527ba0
    cpu.eax = 5405600 /*0x527ba0*/;
    // 00492716  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00492718  e8dbf8ffff             -call 0x491ff8
    cpu.esp -= 4;
    sub_491ff8(app, cpu);
    if (cpu.terminate) return;
    // 0049271d  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0049271f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492721  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00492727  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492728  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492729  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049272a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049272b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49272c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049272c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049272d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049272e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049272f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492730  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492733  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492735  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00492739  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049273b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492741  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492743  e8a0fcffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 00492748  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0049274f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00492751  e892fcffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 00492756  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492758  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049275a  8a8120ab4c00           -mov al, byte ptr [ecx + 0x4cab20]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5024544) /* 0x4cab20 */);
    // 00492760  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00492762  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00492765  39c2                   +cmp edx, eax
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
    // 00492767  754d                   -jne 0x4927b6
    if (!cpu.flags.zf)
    {
        goto L_0x004927b6;
    }
    // 00492769  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0049276e  7550                   -jne 0x4927c0
    if (!cpu.flags.zf)
    {
        goto L_0x004927c0;
    }
    // 00492770  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492772  e871fcffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 00492777  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 0049277e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00492780  e863fcffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 00492785  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00492787  8b2c8520aa4c00         -mov ebp, dword ptr [eax*4 + 0x4caa20]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5024288) /* 0x4caa20 */ + cpu.eax * 4);
L_0x0049278e:
    // 0049278e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492790  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492792  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00492795  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 0049279b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049279d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049279f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004927a1  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004927a4  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 004927aa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004927ac  83f908                 +cmp ecx, 8
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004927af  7f05                   -jg 0x4927b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004927b6;
    }
    // 004927b1  83f808                 +cmp eax, 8
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
    // 004927b4  7f2a                   -jg 0x4927e0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004927e0;
    }
L_0x004927b6:
    // 004927b6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004927b8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004927bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004927bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004927c0:
    // 004927c0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004927c2  e821fcffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 004927c7  8d0cc500000000         -lea ecx, [eax*8]
    cpu.ecx = x86::reg32(cpu.eax * 8);
    // 004927ce  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004927d0  e813fcffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 004927d5  01c8                   +add eax, ecx
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
    // 004927d7  8b2c8520a94c00         -mov ebp, dword ptr [eax*4 + 0x4ca920]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5024032) /* 0x4ca920 */ + cpu.eax * 4);
    // 004927de  ebae                   -jmp 0x49278e
    goto L_0x0049278e;
L_0x004927e0:
    // 004927e0  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 004927e5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004927e7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004927ec  e857fcffff             -call 0x492448
    cpu.esp -= 4;
    sub_492448(app, cpu);
    if (cpu.terminate) return;
    // 004927f1  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004927f5  a31ca94c00             -mov dword ptr [0x4ca91c], eax
    app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */) = cpu.eax;
    // 004927fa  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004927fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004927fe  7432                   -je 0x492832
    if (cpu.flags.zf)
    {
        goto L_0x00492832;
    }
    // 00492800  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492803  7419                   -je 0x49281e
    if (cpu.flags.zf)
    {
        goto L_0x0049281e;
    }
    // 00492805  83fe10                 +cmp esi, 0x10
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
    // 00492808  75ac                   -jne 0x4927b6
    if (!cpu.flags.zf)
    {
        goto L_0x004927b6;
    }
    // 0049280a  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 0049280f  e8d4f6ffff             -call 0x491ee8
    cpu.esp -= 4;
    sub_491ee8(app, cpu);
    if (cpu.terminate) return;
    // 00492814  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00492816  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492819  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049281a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049281b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049281c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049281d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049281e:
    // 0049281e  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 00492823  e8e4f5ffff             -call 0x491e0c
    cpu.esp -= 4;
    sub_491e0c(app, cpu);
    if (cpu.terminate) return;
    // 00492828  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049282a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049282d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049282e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049282f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492830  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492831  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492832:
    // 00492832  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492835  741d                   -je 0x492854
    if (cpu.flags.zf)
    {
        goto L_0x00492854;
    }
    // 00492837  83fe10                 +cmp esi, 0x10
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
    // 0049283a  0f8576ffffff           -jne 0x4927b6
    if (!cpu.flags.zf)
    {
        goto L_0x004927b6;
    }
    // 00492840  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 00492845  e8fef6ffff             -call 0x491f48
    cpu.esp -= 4;
    sub_491f48(app, cpu);
    if (cpu.terminate) return;
    // 0049284a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049284c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049284f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492850  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492851  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492852  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492853  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492854:
    // 00492854  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 00492859  e80ef6ffff             -call 0x491e6c
    cpu.esp -= 4;
    sub_491e6c(app, cpu);
    if (cpu.terminate) return;
    // 0049285e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00492860  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00492863  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492864  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492865  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492866  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492867  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_492868(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492868  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492869  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049286a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049286b  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0049286e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492870  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00492874  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 00492878  894c2430               -mov dword ptr [esp + 0x30], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ecx;
    // 0049287c  e84f93ffff             -call 0x48bbd0
    cpu.esp -= 4;
    sub_48bbd0(app, cpu);
    if (cpu.terminate) return;
    // 00492881  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00492886  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00492888  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0049288c  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00492890  894c2438               -mov dword ptr [esp + 0x38], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ecx;
L_0x00492894:
    // 00492894  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492899  0f8580020000           -jne 0x492b1f
    if (!cpu.flags.zf)
    {
        goto L_0x00492b1f;
    }
    // 0049289f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004928a1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004928a6  e83dfbffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 004928ab  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 004928b2  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004928b6  e82dfbffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 004928bb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004928bd  8b048520aa4c00         -mov eax, dword ptr [eax*4 + 0x4caa20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024288) /* 0x4caa20 */ + cpu.eax * 4);
L_0x004928c4:
    // 004928c4  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004928c8  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004928ca  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004928cf  e814fbffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 004928d4  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 004928db  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004928df  e804fbffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 004928e4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004928e6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004928e8  8a8220ab4c00           -mov al, byte ptr [edx + 0x4cab20]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5024544) /* 0x4cab20 */);
    // 004928ee  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004928f2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004928f4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004928f6  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004928f9  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 004928ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492901  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00492905  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00492909  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049290b  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0049290e  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 00492914  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492916  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0049291a  40                     -inc eax
    (cpu.eax)++;
    // 0049291b  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 0049291d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049291f  8b4702                 -mov eax, dword ptr [edi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00492922  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00492925  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00492929  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049292c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049292f  89442454               -mov dword ptr [esp + 0x54], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00492933  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492935  e8763c0000             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 0049293a  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0049293e  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00492942  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00492945  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00492948  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0049294a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049294c  c1fd03                 -sar ebp, 3
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (3 /*0x3*/ % 32));
    // 0049294f  83f908                 +cmp ecx, 8
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492952  0f8f73000000           -jg 0x4929cb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004929cb;
    }
    // 00492958  83fb08                 +cmp ebx, 8
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
    // 0049295b  7e6e                   -jle 0x4929cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004929cb;
    }
    // 0049295d  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00492962  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492966  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 00492968  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049296a  0f84d9010000           -je 0x492b49
    if (cpu.flags.zf)
    {
        goto L_0x00492b49;
    }
    // 00492970  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492972  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492974  7e1e                   -jle 0x492994
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492994;
    }
    // 00492976  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00492978:
    // 00492978  0fb6b080a44c00         -movzx esi, byte ptr [eax + 0x4ca480]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5022848) /* 0x4ca480 */));
    // 0049297f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00492982  8b34b5a07b5200         -mov esi, dword ptr [esi*4 + 0x527ba0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5405600) /* 0x527ba0 */ + cpu.esi * 4);
    // 00492989  40                     -inc eax
    (cpu.eax)++;
    // 0049298a  89b19c7f5200           -mov dword ptr [ecx + 0x527f9c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5406620) /* 0x527f9c */) = cpu.esi;
    // 00492990  39d8                   +cmp eax, ebx
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
    // 00492992  7ce4                   -jl 0x492978
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492978;
    }
L_0x00492994:
    // 00492994  c7051ca94c00a07f5200   -mov dword ptr [0x4ca91c], 0x527fa0
    app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */) = 5406624 /*0x527fa0*/;
L_0x0049299e:
    // 0049299e  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929a3  0f84d5010000           -je 0x492b7e
    if (cpu.flags.zf)
    {
        goto L_0x00492b7e;
    }
    // 004929a9  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004929ad  83f80f                 +cmp eax, 0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004929b0  0f85ab010000           -jne 0x492b61
    if (!cpu.flags.zf)
    {
        goto L_0x00492b61;
    }
    // 004929b6  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 004929bb  a11ca94c00             -mov eax, dword ptr [0x4ca91c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */);
    // 004929c0  e847f4ffff             -call 0x491e0c
    cpu.esp -= 4;
    sub_491e0c(app, cpu);
    if (cpu.terminate) return;
L_0x004929c5:
    // 004929c5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004929c7  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
L_0x004929cb:
    // 004929cb  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004929cf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004929d0  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004929d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004929d5  6828f14b00             -push 0x4bf128
    app->getMemory<x86::reg32>(cpu.esp-4) = 4976936 /*0x4bf128*/;
    cpu.esp -= 4;
    // 004929da  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004929de  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004929df  e83d7afeff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004929e4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004929e7  8b742454               -mov esi, dword ptr [esp + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004929eb  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004929ee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004929f0  8b1d50824c00           -mov ebx, dword ptr [0x4c8250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 004929f6  8d5614                 -lea edx, [esi + 0x14]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004929f9  e86a5cfeff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 004929fe  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00492a03  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00492a05  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00492a09  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492a0b  ba50485343             -mov edx, 0x43534850
    cpu.edx = 1129531472 /*0x43534850*/;
    // 00492a10  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492a13  e878340000             -call 0x495e90
    cpu.esp -= 4;
    sub_495e90(app, cpu);
    if (cpu.terminate) return;
    // 00492a18  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00492a1c  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00492a1f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492a24  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00492a26  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00492a28  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00492a2c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00492a2e  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00492a30  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492a36  66894104               -mov word ptr [ecx + 4], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 00492a3a  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00492a3e  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00492a40  66894106               -mov word ptr [ecx + 6], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 00492a44  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00492a48  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00492a4c  668b470a               -mov ax, word ptr [edi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 00492a50  668b510c               -mov dx, word ptr [ecx + 0xc]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00492a54  6689410a               -mov word ptr [ecx + 0xa], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 00492a58  81e200f0ffff           -and edx, 0xfffff000
    cpu.edx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00492a5e  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00492a61  6689510c               -mov word ptr [ecx + 0xc], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 00492a65  25ff0f0000             -and eax, 0xfff
    cpu.eax &= x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00492a6a  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00492a6d  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492a70  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00492a72  8971fc                 -mov dword ptr [ecx - 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00492a75  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 00492a79  8d7710                 -lea esi, [edi + 0x10]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00492a7c  81e300f0ffff           -and ebx, 0xfffff000
    cpu.ebx &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00492a82  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00492a85  668959fe               -mov word ptr [ecx - 2], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 00492a89  250000ff0f             -and eax, 0xfff0000
    cpu.eax &= x86::reg32(x86::sreg32(268369920 /*0xfff0000*/));
    // 00492a8e  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00492a91  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00492a93  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00492a95  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00492a99  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00492a9c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492a9e  7e1d                   -jle 0x492abd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492abd;
    }
L_0x00492aa0:
    // 00492aa0  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00492aa4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00492aa6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492aa8  ff54244c               -call dword ptr [esp + 0x4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492aac  47                     -inc edi
    (cpu.edi)++;
    // 00492aad  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00492ab1  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00492ab5  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492ab7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492ab9  39d7                   +cmp edi, edx
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
    // 00492abb  7ce3                   -jl 0x492aa0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00492aa0;
    }
L_0x00492abd:
    // 00492abd  0faf6c2454             -imul ebp, dword ptr [esp + 0x54]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */))));
    // 00492ac2  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00492ac6  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492ac8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00492acd  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00492ad0  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00492ad4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492ad6  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00492ad8  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00492ada  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00492ae1  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00492ae3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492ae5  7407                   -je 0x492aee
    if (cpu.flags.zf)
    {
        goto L_0x00492aee;
    }
    // 00492ae7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00492ae9  e8de5ffeff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x00492aee:
    // 00492aee  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00492af2  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00492af6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00492af8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492afa  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492afe  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492b03  39f0                   +cmp eax, esi
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
    // 00492b05  740f                   -je 0x492b16
    if (cpu.flags.zf)
    {
        goto L_0x00492b16;
    }
    // 00492b07  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00492b0b  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00492b0c  896c2438               -mov dword ptr [esp + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 00492b10  0f857efdffff           -jne 0x492894
    if (!cpu.flags.zf)
    {
        goto L_0x00492894;
    }
L_0x00492b16:
    // 00492b16  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00492b18  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00492b1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492b1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492b1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492b1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492b1f:
    // 00492b1f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00492b21  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492b26  e8bdf8ffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 00492b2b  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00492b32  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492b36  e8adf8ffff             -call 0x4923e8
    cpu.esp -= 4;
    sub_4923e8(app, cpu);
    if (cpu.terminate) return;
    // 00492b3b  01d0                   +add eax, edx
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
    // 00492b3d  8b048520a94c00         -mov eax, dword ptr [eax*4 + 0x4ca920]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024032) /* 0x4ca920 */ + cpu.eax * 4);
    // 00492b44  e97bfdffff             -jmp 0x4928c4
    goto L_0x004928c4;
L_0x00492b49:
    // 00492b49  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 00492b4e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492b52  e8f1f8ffff             -call 0x492448
    cpu.esp -= 4;
    sub_492448(app, cpu);
    if (cpu.terminate) return;
    // 00492b57  a31ca94c00             -mov dword ptr [0x4ca91c], eax
    app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */) = cpu.eax;
    // 00492b5c  e93dfeffff             -jmp 0x49299e
    goto L_0x0049299e;
L_0x00492b61:
    // 00492b61  83f810                 +cmp eax, 0x10
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492b64  0f855bfeffff           -jne 0x4929c5
    if (!cpu.flags.zf)
    {
        goto L_0x004929c5;
    }
    // 00492b6a  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 00492b6f  a11ca94c00             -mov eax, dword ptr [0x4ca91c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */);
    // 00492b74  e86ff3ffff             -call 0x491ee8
    cpu.esp -= 4;
    sub_491ee8(app, cpu);
    if (cpu.terminate) return;
    // 00492b79  e947feffff             -jmp 0x4929c5
    goto L_0x004929c5;
L_0x00492b7e:
    // 00492b7e  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00492b82  83f90f                 +cmp ecx, 0xf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492b85  741d                   -je 0x492ba4
    if (cpu.flags.zf)
    {
        goto L_0x00492ba4;
    }
    // 00492b87  83f910                 +cmp ecx, 0x10
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
    // 00492b8a  0f8535feffff           -jne 0x4929c5
    if (!cpu.flags.zf)
    {
        goto L_0x004929c5;
    }
    // 00492b90  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 00492b95  a11ca94c00             -mov eax, dword ptr [0x4ca91c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */);
    // 00492b9a  e8a9f3ffff             -call 0x491f48
    cpu.esp -= 4;
    sub_491f48(app, cpu);
    if (cpu.terminate) return;
    // 00492b9f  e921feffff             -jmp 0x4929c5
    goto L_0x004929c5;
L_0x00492ba4:
    // 00492ba4  baa07f5200             -mov edx, 0x527fa0
    cpu.edx = 5406624 /*0x527fa0*/;
    // 00492ba9  a11ca94c00             -mov eax, dword ptr [0x4ca91c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */);
    // 00492bae  e8b9f2ffff             -call 0x491e6c
    cpu.esp -= 4;
    sub_491e6c(app, cpu);
    if (cpu.terminate) return;
    // 00492bb3  e90dfeffff             -jmp 0x4929c5
    goto L_0x004929c5;
}

/* align: skip  */
void Application::sub_492bb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492bb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492bb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492bba  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00492bbf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492bc1  e8a2fcffff             -call 0x492868
    cpu.esp -= 4;
    sub_492868(app, cpu);
    if (cpu.terminate) return;
    // 00492bc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492bc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492bc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492bcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492bcc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00492bcd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492bce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492bcf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492bd1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00492bd3  e828390000             -call 0x496500
    cpu.esp -= 4;
    sub_496500(app, cpu);
    if (cpu.terminate) return;
    // 00492bd8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00492bdd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00492bdf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492be1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492be3  e880fcffff             -call 0x492868
    cpu.esp -= 4;
    sub_492868(app, cpu);
    if (cpu.terminate) return;
    // 00492be8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492be9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492bea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492beb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_492bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492bf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00492bf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492bf2  81ec00140000           -sub esp, 0x1400
    (cpu.esp) -= x86::reg32(x86::sreg32(5120 /*0x1400*/));
    // 00492bf8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00492bfa  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00492bfc  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00492bfe  ff15a4835200           -call dword ptr [0x5283a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5407652) /* 0x5283a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492c04  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00492c06  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00492c08  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00492c0a  ff15a0835200           -call dword ptr [0x5283a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5407648) /* 0x5283a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492c10  81c400140000           -add esp, 0x1400
    (cpu.esp) += x86::reg32(x86::sreg32(5120 /*0x1400*/));
    // 00492c16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492c18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_492c1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00492c1c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00492c1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00492c1e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00492c1f  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00492c22  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492c24  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00492c28  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00492c2c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00492c2e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492c30  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00492c33  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 00492c39  0fb62ded844c00         -movzx ebp, byte ptr [0x4c84ed]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */));
    // 00492c40  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00492c43  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00492c45  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00492c48  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00492c4c  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00492c50  8915a4835200           -mov dword ptr [0x5283a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5407652) /* 0x5283a4 */) = cpu.edx;
    // 00492c56  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00492c58  7402                   -je 0x492c5c
    if (cpu.flags.zf)
    {
        goto L_0x00492c5c;
    }
    // 00492c5a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00492c5c:
    // 00492c5c  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 00492c61  7540                   -jne 0x492ca3
    if (!cpu.flags.zf)
    {
        goto L_0x00492ca3;
    }
    // 00492c63  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00492c65  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00492c6a  39e8                   +cmp eax, ebp
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
    // 00492c6c  7435                   -je 0x492ca3
    if (cpu.flags.zf)
    {
        goto L_0x00492ca3;
    }
    // 00492c6e  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492c72  0f8464020000           -je 0x492edc
    if (cpu.flags.zf)
    {
        goto L_0x00492edc;
    }
    // 00492c78  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00492c7d:
    // 00492c7d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00492c7f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492c81  e8a6faffff             -call 0x49272c
    cpu.esp -= 4;
    sub_49272c(app, cpu);
    if (cpu.terminate) return;
    // 00492c86  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00492c8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492c8c  0f8451020000           -je 0x492ee3
    if (cpu.flags.zf)
    {
        goto L_0x00492ee3;
    }
    // 00492c92  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492c96  740b                   -je 0x492ca3
    if (cpu.flags.zf)
    {
        goto L_0x00492ca3;
    }
    // 00492c98  a3a4835200             -mov dword ptr [0x5283a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5407652) /* 0x5283a4 */) = cpu.eax;
    // 00492c9d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492c9f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x00492ca3:
    // 00492ca3  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00492ca6  8b6e02                 -mov ebp, dword ptr [esi + 2]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00492ca9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492cab  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00492cae  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00492cb0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00492cb3  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 00492cb9  40                     -inc eax
    (cpu.eax)++;
    // 00492cba  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00492cbc  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00492cbf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00492cc1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00492cc3  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00492cc6  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00492cc9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00492ccd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492ccf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00492cd3  e8d8380000             -call 0x4965b0
    cpu.esp -= 4;
    sub_4965b0(app, cpu);
    if (cpu.terminate) return;
    // 00492cd8  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00492cda  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492cde  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00492ce2  a1e0844c00             -mov eax, dword ptr [0x4c84e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 00492ce7  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00492ce9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00492cec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492cee  7e15                   -jle 0x492d05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492d05;
    }
    // 00492cf0  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00492cf4  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00492cf7  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492cf9  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492cfd  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492cff  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00492d01  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x00492d05:
    // 00492d05  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492d09  8b35e8844c00           -mov esi, dword ptr [0x4c84e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 00492d0f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492d11  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00492d13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492d15  7e02                   -jle 0x492d19
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492d19;
    }
    // 00492d17  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00492d19:
    // 00492d19  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492d1d  a1dc844c00             -mov eax, dword ptr [0x4c84dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 00492d22  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00492d24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492d26  7e20                   -jle 0x492d48
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492d48;
    }
    // 00492d28  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492d2a  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00492d2d  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 00492d30  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00492d33  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492d35  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492d39  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00492d3b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492d3d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00492d40  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00492d44  01442420               -add dword ptr [esp + 0x20], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00492d48:
    // 00492d48  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492d4c  8b35e4844c00           -mov esi, dword ptr [0x4c84e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 00492d52  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492d54  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00492d56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492d58  7e0e                   -jle 0x492d68
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492d68;
    }
    // 00492d5a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492d5c  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00492d5f  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 00492d62  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00492d64  01742420               -add dword ptr [esp + 0x20], esi
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00492d68:
    // 00492d68  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00492d6a  0f8e59010000           -jle 0x492ec9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492ec9;
    }
    // 00492d70  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492d72  0f8e51010000           -jle 0x492ec9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00492ec9;
    }
    // 00492d78  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00492d7b  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 00492d80  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00492d84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492d86  a0ec844c00             -mov al, byte ptr [0x4c84ec]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00492d8b  40                     -inc eax
    (cpu.eax)++;
    // 00492d8c  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00492d8e  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00492d91  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 00492d94  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00492d97  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00492d9b  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00492d9f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492da3  8b1dfc844c00           -mov ebx, dword ptr [0x4c84fc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00492da9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00492dac  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492dae  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00492db2  8b3500854c00           -mov esi, dword ptr [0x4c8500]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00492db8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00492dbb  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492dbd  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 00492dbf  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00492dc1  a1f8844c00             -mov eax, dword ptr [0x4c84f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014776) /* 0x4c84f8 */);
    // 00492dc6  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492dc8  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00492dcc  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492dce  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00492dd2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00492dd6  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00492dda  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492ddc  0f8542010000           -jne 0x492f24
    if (!cpu.flags.zf)
    {
        goto L_0x00492f24;
    }
    // 00492de2  a0ec844c00             -mov al, byte ptr [0x4c84ec]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00492de7  3c0f                   +cmp al, 0xf
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
    // 00492de9  0f833e010000           -jae 0x492f2d
    if (!cpu.flags.cf)
    {
        goto L_0x00492f2d;
    }
    // 00492def  3c04                   +cmp al, 4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00492df1  0f837e010000           -jae 0x492f75
    if (!cpu.flags.cf)
    {
        goto L_0x00492f75;
    }
L_0x00492df7:
    // 00492df7  833da483520000         +cmp dword ptr [0x5283a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5407652) /* 0x5283a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492dfe  0f8592010000           -jne 0x492f96
    if (!cpu.flags.zf)
    {
        goto L_0x00492f96;
    }
L_0x00492e04:
    // 00492e04  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00492e08  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00492e0c  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00492e10  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00492e14  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492e18  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492e1a  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x00492e1e:
    // 00492e1e  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492e22  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00492e24  745a                   -je 0x492e80
    if (cpu.flags.zf)
    {
        goto L_0x00492e80;
    }
    // 00492e26  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492e2a  a104854c00             -mov eax, dword ptr [0x4c8504]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014788) /* 0x4c8504 */);
    // 00492e2f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00492e31  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492e33  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00492e35  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00492e39  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00492e3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492e3f  0f8480010000           -je 0x492fc5
    if (cpu.flags.zf)
    {
        goto L_0x00492fc5;
    }
    // 00492e45  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00492e47  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
L_0x00492e4b:
    // 00492e4b  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00492e4f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00492e51  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492e53  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492e55  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492e59  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00492e5d  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492e61  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00492e65  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492e67  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492e69  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00492e6b  8b1d48824c00           -mov ebx, dword ptr [0x4c8248]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014088) /* 0x4c8248 */);
    // 00492e71  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00492e75  39da                   +cmp edx, ebx
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
    // 00492e77  0f8f30010000           -jg 0x492fad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00492fad;
    }
L_0x00492e7d:
    // 00492e7d  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00492e7e  75cb                   -jne 0x492e4b
    if (!cpu.flags.zf)
    {
        goto L_0x00492e4b;
    }
L_0x00492e80:
    // 00492e80  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00492e84  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492e86  7436                   -je 0x492ebe
    if (cpu.flags.zf)
    {
        goto L_0x00492ebe;
    }
    // 00492e88  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00492e8b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492e8d  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00492e91  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00492e95  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00492e97  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492e99  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00492e9d  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492ea1  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00492ea5  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00492ea9  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00492ead  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00492eaf  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00492eb3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492eb5  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00492eb7  47                     -inc edi
    (cpu.edi)++;
    // 00492eb8  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00492eba  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
L_0x00492ebe:
    // 00492ebe  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ec3  0f8f55ffffff           -jg 0x492e1e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00492e1e;
    }
L_0x00492ec9:
    // 00492ec9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00492ecd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00492ecf  0f8550010000           -jne 0x493025
    if (!cpu.flags.zf)
    {
        goto L_0x00493025;
    }
L_0x00492ed5:
    // 00492ed5  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00492ed8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492ed9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492eda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00492edb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00492edc:
    // 00492edc  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00492ede  e99afdffff             -jmp 0x492c7d
    goto L_0x00492c7d;
L_0x00492ee3:
    // 00492ee3  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ee7  7421                   -je 0x492f0a
    if (cpu.flags.zf)
    {
        goto L_0x00492f0a;
    }
    // 00492ee9  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00492eee:
    // 00492eee  8b5f1c                 -mov ebx, dword ptr [edi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 00492ef1  83fb01                 +cmp ebx, 1
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
    // 00492ef4  7518                   -jne 0x492f0e
    if (!cpu.flags.zf)
    {
        goto L_0x00492f0e;
    }
    // 00492ef6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00492ef8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492efa  e869f9ffff             -call 0x492868
    cpu.esp -= 4;
    sub_492868(app, cpu);
    if (cpu.terminate) return;
    // 00492eff  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00492f03  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492f05  e999fdffff             -jmp 0x492ca3
    goto L_0x00492ca3;
L_0x00492f0a:
    // 00492f0a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00492f0c  ebe0                   -jmp 0x492eee
    goto L_0x00492eee;
L_0x00492f0e:
    // 00492f0e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00492f10  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00492f12  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00492f14  e84ff9ffff             -call 0x492868
    cpu.esp -= 4;
    sub_492868(app, cpu);
    if (cpu.terminate) return;
    // 00492f19  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00492f1d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00492f1f  e97ffdffff             -jmp 0x492ca3
    goto L_0x00492ca3;
L_0x00492f24:
    // 00492f24  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00492f28  e9d7feffff             -jmp 0x492e04
    goto L_0x00492e04;
L_0x00492f2d:
    // 00492f2d  770c                   -ja 0x492f3b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00492f3b;
    }
    // 00492f2f  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00492f32  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00492f36  e9bcfeffff             -jmp 0x492df7
    goto L_0x00492df7;
L_0x00492f3b:
    // 00492f3b  3c18                   +cmp al, 0x18
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
    // 00492f3d  7314                   -jae 0x492f53
    if (!cpu.flags.cf)
    {
        goto L_0x00492f53;
    }
    // 00492f3f  3c10                   +cmp al, 0x10
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
    // 00492f41  0f85b0feffff           -jne 0x492df7
    if (!cpu.flags.zf)
    {
        goto L_0x00492df7;
    }
    // 00492f47  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00492f4a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00492f4e  e9a4feffff             -jmp 0x492df7
    goto L_0x00492df7;
L_0x00492f53:
    // 00492f53  770c                   -ja 0x492f61
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00492f61;
    }
    // 00492f55  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00492f58  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00492f5c  e996feffff             -jmp 0x492df7
    goto L_0x00492df7;
L_0x00492f61:
    // 00492f61  3c20                   +cmp al, 0x20
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
    // 00492f63  0f858efeffff           -jne 0x492df7
    if (!cpu.flags.zf)
    {
        goto L_0x00492df7;
    }
    // 00492f69  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 00492f6c  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00492f70  e982feffff             -jmp 0x492df7
    goto L_0x00492df7;
L_0x00492f75:
    // 00492f75  770b                   -ja 0x492f82
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00492f82;
    }
    // 00492f77  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00492f79  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00492f7d  e975feffff             -jmp 0x492df7
    goto L_0x00492df7;
L_0x00492f82:
    // 00492f82  3c08                   +cmp al, 8
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
    // 00492f84  0f856dfeffff           -jne 0x492df7
    if (!cpu.flags.zf)
    {
        goto L_0x00492df7;
    }
    // 00492f8a  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00492f8d  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00492f91  e961feffff             -jmp 0x492df7
    goto L_0x00492df7;
L_0x00492f96:
    // 00492f96  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00492f9a  bbf02b4900             -mov ebx, 0x492bf0
    cpu.ebx = 4795376 /*0x492bf0*/;
    // 00492f9f  a3a0835200             -mov dword ptr [0x5283a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5407648) /* 0x5283a0 */) = cpu.eax;
    // 00492fa4  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 00492fa8  e957feffff             -jmp 0x492e04
    goto L_0x00492e04;
L_0x00492fad:
    // 00492fad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00492faf  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00492fb3  e8e051feff             -call 0x478198
    cpu.esp -= 4;
    sub_478198(app, cpu);
    if (cpu.terminate) return;
    // 00492fb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00492fba  0f8415ffffff           -je 0x492ed5
    if (cpu.flags.zf)
    {
        goto L_0x00492ed5;
    }
    // 00492fc0  e9b8feffff             -jmp 0x492e7d
    goto L_0x00492e7d;
L_0x00492fc5:
    // 00492fc5  837c241400             +cmp dword ptr [esp + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492fca  7422                   -je 0x492fee
    if (cpu.flags.zf)
    {
        goto L_0x00492fee;
    }
L_0x00492fcc:
    // 00492fcc  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00492fd0  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00492fd2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00492fd4  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00492fd6  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00492fda  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00492fde  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00492fe2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00492fe4  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00492fe6  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00492fe7  75e3                   -jne 0x492fcc
    if (!cpu.flags.zf)
    {
        goto L_0x00492fcc;
    }
    // 00492fe9  e992feffff             -jmp 0x492e80
    goto L_0x00492e80;
L_0x00492fee:
    // 00492fee  837c242000             +cmp dword ptr [esp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ff3  75d7                   -jne 0x492fcc
    if (!cpu.flags.zf)
    {
        goto L_0x00492fcc;
    }
    // 00492ff5  817c2438f02b4900       +cmp dword ptr [esp + 0x38], 0x492bf0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4795376 /*0x492bf0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00492ffd  74cd                   -je 0x492fcc
    if (cpu.flags.zf)
    {
        goto L_0x00492fcc;
    }
    // 00492fff  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00493001  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00493004  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00493008  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049300a  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0049300c  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00493010  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00493014  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00493017  0faf7c2418             -imul edi, dword ptr [esp + 0x18]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0049301c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049301e  01f9                   +add ecx, edi
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
    // 00493020  e95bfeffff             -jmp 0x492e80
    goto L_0x00492e80;
L_0x00493025:
    // 00493025  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00493027  e8a05afeff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0049302c  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049302f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493030  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493031  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493032  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_493040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00493040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00493041  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00493042  833d64ab4c0000         +cmp dword ptr [0x4cab64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00493049  742c                   -je 0x493077
    if (cpu.flags.zf)
    {
        goto L_0x00493077;
    }
L_0x0049304b:
    // 0049304b  8b1560ab4c00           -mov edx, dword ptr [0x4cab60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024608) /* 0x4cab60 */);
    // 00493051  a164ab4c00             -mov eax, dword ptr [0x4cab64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */);
    // 00493056  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00493059  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0049305c  8b1560ab4c00           -mov edx, dword ptr [0x4cab60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024608) /* 0x4cab60 */);
    // 00493062  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00493069  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049306c  891da8835200           -mov dword ptr [0x5283a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5407656) /* 0x5283a8 */) = cpu.ebx;
    // 00493072  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00493074  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493075  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00493076  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00493077:
    // 00493077  b8d0f14b00             -mov eax, 0x4bf1d0
    cpu.eax = 4977104 /*0x4bf1d0*/;
    // 0049307c  8b1560ab4c00           -mov edx, dword ptr [0x4cab60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024608) /* 0x4cab60 */);
    // 00493082  8b1d50824c00           -mov ebx, dword ptr [0x4c8250]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 00493088  c1e202                 +shl edx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0049308b  e8d855feff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00493090  a364ab4c00             -mov dword ptr [0x4cab64], eax
    app->getMemory<x86::reg32>(x86::reg32(5024612) /* 0x4cab64 */) = cpu.eax;
    // 00493095  ebb4                   -jmp 0x49304b
    goto L_0x0049304b;
}

}
