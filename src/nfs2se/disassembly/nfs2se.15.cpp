#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4737a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004737a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004737a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004737a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004737a3  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004737a6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004737a8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004737ab  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004737ad  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004737b1  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004737b6  8a25f8d24d00           -mov ah, byte ptr [0x4dd2f8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */);
    // 004737bc  8b0d88995100           -mov ecx, dword ptr [0x519988]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5347720) /* 0x519988 */);
    // 004737c2  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004737c6  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 004737c9  741a                   -je 0x4737e5
    if (cpu.flags.zf)
    {
        goto L_0x004737e5;
    }
    // 004737cb  837c243800             +cmp dword ptr [esp + 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004737d0  7413                   -je 0x4737e5
    if (cpu.flags.zf)
    {
        goto L_0x004737e5;
    }
    // 004737d2  833cbd5099510000       +cmp dword ptr [edi*4 + 0x519950], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5347664) /* 0x519950 */ + cpu.edi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004737da  7409                   -je 0x4737e5
    if (cpu.flags.zf)
    {
        goto L_0x004737e5;
    }
    // 004737dc  833dd0ed4d0000         +cmp dword ptr [0x4dedd0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107152) /* 0x4dedd0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004737e3  7409                   -je 0x4737ee
    if (cpu.flags.zf)
    {
        goto L_0x004737ee;
    }
L_0x004737e5:
    // 004737e5  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004737e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004737eb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004737ee:
    // 004737ee  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004737f0  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004737f2  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004737f5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004737f7  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 004737fa  8b93e82f4c00           -mov edx, dword ptr [ebx + 0x4c2fe8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4993000) /* 0x4c2fe8 */);
    // 00473800  b8a53c0200             -mov eax, 0x23ca5
    cpu.eax = 146597 /*0x23ca5*/;
    // 00473805  8b92b8020000           -mov edx, dword ptr [edx + 0x2b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(696) /* 0x2b8 */);
    // 0047380b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047380d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00473810  c1e810                 +shr eax, 0x10
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
    // 00473813  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473815  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473817  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047381a  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047381d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047381f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00473822  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00473826  8b9318304c00           -mov edx, dword ptr [ebx + 0x4c3018]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4993048) /* 0x4c3018 */);
    // 0047382c  b800400000             -mov eax, 0x4000
    cpu.eax = 16384 /*0x4000*/;
    // 00473831  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00473833  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00473836  c1e810                 +shr eax, 0x10
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
    // 00473839  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047383b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047383d  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00473841  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00473843  e898090000             -call 0x4741e0
    cpu.esp -= 4;
    sub_4741e0(app, cpu);
    if (cpu.terminate) return;
    // 00473848  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047384b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047384d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047384f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00473852  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473854  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473856  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473859  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047385c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047385e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00473861  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00473863  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473865  0f8c9e010000           -jl 0x473a09
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473a09;
    }
L_0x0047386b:
    // 0047386b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047386e  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473870  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00473872  833cbd5099510001       +cmp dword ptr [edi*4 + 0x519950], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5347664) /* 0x519950 */ + cpu.edi * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047387a  0f8590010000           -jne 0x473a10
    if (!cpu.flags.zf)
    {
        goto L_0x00473a10;
    }
    // 00473880  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473882  8d34dd00000000         -lea esi, [ebx*8]
    cpu.esi = x86::reg32(cpu.ebx * 8);
L_0x00473889:
    // 00473889  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047388c  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047388e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00473890  40                     -inc eax
    (cpu.eax)++;
    // 00473891  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00473895  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 0047389a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047389c  8b742438               -mov esi, dword ptr [esp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004738a0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004738a3  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004738a5  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004738a9  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004738ad  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004738b4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004738b6  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004738b9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004738bb  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004738bf  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004738c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004738c3  0f8e1cffffff           -jle 0x4737e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004737e5;
    }
    // 004738c9  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004738cd  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004738cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004738d1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004738d4  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004738d7  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004738d9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004738dc  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004738e0  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004738e3  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004738e6  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004738e8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004738ec  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004738f0:
    // 004738f0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004738f4  0faf442424             -imul eax, dword ptr [esp + 0x24]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 004738f9  83bf5099510001         +cmp dword ptr [edi + 0x519950], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5347664) /* 0x519950 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473900  0f8518010000           -jne 0x473a1e
    if (!cpu.flags.zf)
    {
        goto L_0x00473a1e;
    }
    // 00473906  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00473908  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047390b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047390e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00473911  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473915  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473917  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
L_0x0047391c:
    // 0047391c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047391e  0faf442424             -imul eax, dword ptr [esp + 0x24]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */))));
    // 00473923  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473925  0fbf11                 -movsx edx, word ptr [ecx]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx)));
    // 00473928  39c2                   +cmp edx, eax
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
    // 0047392a  7e30                   -jle 0x47395c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047395c;
    }
    // 0047392c  e83f930000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00473931  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00473933  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00473936  241f                   -and al, 0x1f
    cpu.al &= x86::reg8(x86::sreg8(31 /*0x1f*/));
    // 00473938  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047393a  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 0047393d  83bf5099510001         +cmp dword ptr [edi + 0x519950], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5347664) /* 0x519950 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473944  0f85f2000000           -jne 0x473a3c
    if (!cpu.flags.zf)
    {
        goto L_0x00473a3c;
    }
    // 0047394a  e821930000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0047394f  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00473951  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
L_0x00473953:
    // 00473953  0502000000             -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00473958  66894102               -mov word ptr [ecx + 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.ax;
L_0x0047395c:
    // 0047395c  837c241c32             +cmp dword ptr [esp + 0x1c], 0x32
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473961  0f8de3000000           -jge 0x473a4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473a4a;
    }
    // 00473967  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047396b  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
L_0x0047396e:
    // 0047396e  83bf5099510001         +cmp dword ptr [edi + 0x519950], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5347664) /* 0x519950 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473975  0f85e4000000           -jne 0x473a5f
    if (!cpu.flags.zf)
    {
        goto L_0x00473a5f;
    }
    // 0047397b  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047397d  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 00473980  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00473983  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 00473987  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473989  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047398c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047398e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00473990  8b510e                 -mov edx, dword ptr [ecx + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 00473993  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00473996  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473998  8b510e                 -mov edx, dword ptr [ecx + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 0047399b  66894114               -mov word ptr [ecx + 0x14], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ax;
    // 0047399f  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004739a3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004739a6  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004739a9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004739ab  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004739ae  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004739b1  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004739b3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004739b6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004739b8  8b5112                 -mov edx, dword ptr [ecx + 0x12]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(18) /* 0x12 */);
    // 004739bb  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004739bd  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004739c0  6689410e               -mov word ptr [ecx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004739c4  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004739c8  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004739cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004739cd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004739d0  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004739d3  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004739d5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004739d8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004739da  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004739dc:
    // 004739dc  66894112               -mov word ptr [ecx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004739e0  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004739e4  668b4102               -mov ax, word ptr [ecx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004739e8  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004739eb  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004739ee  83c118                 -add ecx, 0x18
    (cpu.ecx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004739f1  46                     -inc esi
    (cpu.esi)++;
    // 004739f2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004739f4  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004739f8  668959e8               -mov word ptr [ecx - 0x18], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-24) /* -0x18 */) = cpu.bx;
    // 004739fc  39d6                   +cmp esi, edx
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
    // 004739fe  0f8de1fdffff           -jge 0x4737e5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004737e5;
    }
    // 00473a04  e9e7feffff             -jmp 0x4738f0
    goto L_0x004738f0;
L_0x00473a09:
    // 00473a09  31c5                   +xor ebp, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00473a0b  e95bfeffff             -jmp 0x47386b
    goto L_0x0047386b;
L_0x00473a10:
    // 00473a10  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473a12  8d349d00000000         -lea esi, [ebx*4]
    cpu.esi = x86::reg32(cpu.ebx * 4);
    // 00473a19  e96bfeffff             -jmp 0x473889
    goto L_0x00473889;
L_0x00473a1e:
    // 00473a1e  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00473a21  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00473a23  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00473a26  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00473a29  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00473a2c  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473a30  01c2                   +add edx, eax
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
    // 00473a32  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00473a37  e9e0feffff             -jmp 0x47391c
    goto L_0x0047391c;
L_0x00473a3c:
    // 00473a3c  e82f920000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00473a41  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00473a43  2401                   +and al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00473a45  e909ffffff             -jmp 0x473953
    goto L_0x00473953;
L_0x00473a4a:
    // 00473a4a  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 00473a4f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473a51  e81a920000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00473a56  f7f3                   +div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00473a58  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00473a5a  e90fffffff             -jmp 0x47396e
    goto L_0x0047396e;
L_0x00473a5f:
    // 00473a5f  e80c920000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00473a64  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00473a66  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00473a68  668b11                 -mov dx, word ptr [ecx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx);
    // 00473a6b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00473a6d  668b4102               -mov ax, word ptr [ecx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00473a71  66895110               -mov word ptr [ecx + 0x10], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 00473a75  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473a77  66895114               -mov word ptr [ecx + 0x14], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.dx;
    // 00473a7b  8b510e                 -mov edx, dword ptr [ecx + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(14) /* 0xe */);
    // 00473a7e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00473a82  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00473a85  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00473a88  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473a8a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473a8d  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473a90  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473a92  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00473a95  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00473a97  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00473a99  48                     -dec eax
    (cpu.eax)--;
    // 00473a9a  6689410e               -mov word ptr [ecx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00473a9e  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00473aa1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473aa5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00473aa8  01d0                   +add eax, edx
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
    // 00473aaa  e92dffffff             -jmp 0x4739dc
    goto L_0x004739dc;
}

/* align: skip 0x00 */
void Application::sub_473ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473ab0  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 00473ab7  7501                   -jne 0x473aba
    if (!cpu.flags.zf)
    {
        goto L_0x00473aba;
    }
    // 00473ab9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473aba:
    // 00473aba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473abb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473abc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473abd  ba40d84b00             -mov edx, 0x4bd840
    cpu.edx = 4970560 /*0x4bd840*/;
    // 00473ac2  b9ef010000             -mov ecx, 0x1ef
    cpu.ecx = 495 /*0x1ef*/;
    // 00473ac7  b860d84b00             -mov eax, 0x4bd860
    cpu.eax = 4970592 /*0x4bd860*/;
    // 00473acc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473ace  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 00473ad4  bac0030000             -mov edx, 0x3c0
    cpu.edx = 960 /*0x3c0*/;
    // 00473ad9  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 00473adf  e8844b0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 00473ae4  a388995100             -mov dword ptr [0x519988], eax
    app->getMemory<x86::reg32>(x86::reg32(5347720) /* 0x519988 */) = cpu.eax;
    // 00473ae9  e816040000             -call 0x473f04
    cpu.esp -= 4;
    sub_473f04(app, cpu);
    if (cpu.terminate) return;
    // 00473aee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473aef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473af0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473af1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473b00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473b01  8a25f8d24d00           -mov ah, byte ptr [0x4dd2f8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */);
    // 00473b07  8b0d88995100           -mov ecx, dword ptr [0x519988]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5347720) /* 0x519988 */);
    // 00473b0d  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00473b10  7458                   -je 0x473b6a
    if (cpu.flags.zf)
    {
        goto L_0x00473b6a;
    }
    // 00473b12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473b13  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473b14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473b15  bee0010000             -mov esi, 0x1e0
    cpu.esi = 480 /*0x1e0*/;
    // 00473b1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00473b1c:
    // 00473b1c  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00473b23  c7410811000000         -mov dword ptr [ecx + 8], 0x11
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 17 /*0x11*/;
    // 00473b2a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473b2c  e83f910000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00473b31  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00473b33  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 00473b36  e835910000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00473b3b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00473b3d  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 00473b3f  0502000000             -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00473b44  43                     -inc ebx
    (cpu.ebx)++;
    // 00473b45  66894102               -mov word ptr [ecx + 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 00473b49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473b4b  83c118                 -add ecx, 0x18
    (cpu.ecx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00473b4e  83fb28                 +cmp ebx, 0x28
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473b51  7d0c                   -jge 0x473b5f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473b5f;
    }
    // 00473b53  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00473b55  7ec5                   -jle 0x473b1c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473b1c;
    }
    // 00473b57  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00473b5a  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00473b5d  ebbd                   -jmp 0x473b1c
    goto L_0x00473b1c;
L_0x00473b5f:
    // 00473b5f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473b61  89156c814c00           -mov dword ptr [0x4c816c], edx
    app->getMemory<x86::reg32>(x86::reg32(5013868) /* 0x4c816c */) = cpu.edx;
    // 00473b67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00473b6a:
    // 00473b6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473b6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_473b84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00473b84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473b85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473b86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473b87  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00473b8a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00473b8c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473b8e  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 00473b95  743f                   -je 0x473bd6
    if (cpu.flags.zf)
    {
        goto L_0x00473bd6;
    }
    // 00473b97  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473b98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473b9a  e821010000             -call 0x473cc0
    cpu.esp -= 4;
    sub_473cc0(app, cpu);
    if (cpu.terminate) return;
    // 00473b9f  8b048d50995100         -mov eax, dword ptr [ecx*4 + 0x519950]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347664) /* 0x519950 */ + cpu.ecx * 4);
    // 00473ba6  83f804                 +cmp eax, 4
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
    // 00473ba9  7707                   -ja 0x473bb2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00473bb2;
    }
    // 00473bab  ff2485703b4700         -jmp dword ptr [eax*4 + 0x473b70]
    cpu.ip = app->getMemory<x86::reg32>(4668272 + cpu.eax * 4); goto dynamic_jump;
  case 0x00473bb2:
L_0x00473bb2:
    // 00473bb2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473bb4  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00473bb8  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
L_0x00473bbc:
    // 00473bbc  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473bc0  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473bc4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473bc5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473bc6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473bc7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00473bc9  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00473bcb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473bcc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473bcd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00473bcf  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00473bd2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473bd3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473bd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473bd5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473bd6:
    // 00473bd6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00473bd8  e81372feff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 00473bdd  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00473bdf  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00473be1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473be2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473be3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00473be5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00473be8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473be9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473bea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473beb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473bec:
    // 00473bec  8b148d48995100         -mov edx, dword ptr [ecx*4 + 0x519948]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5347656) /* 0x519948 */ + cpu.ecx * 4);
    // 00473bf3  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00473bf6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473bf8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473bfb  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00473bfe  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473c00  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00473c03  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473c05  0f84a6000000           -je 0x473cb1
    if (cpu.flags.zf)
    {
        goto L_0x00473cb1;
    }
    // 00473c0b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473c0c  8b35f4d04d00           -mov esi, dword ptr [0x4dd0f4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5099764) /* 0x4dd0f4 */);
    // 00473c12  8b1d88995100           -mov ebx, dword ptr [0x519988]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5347720) /* 0x519988 */);
    // 00473c18  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00473c1a  7467                   -je 0x473c83
    if (cpu.flags.zf)
    {
        goto L_0x00473c83;
    }
    // 00473c1c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473c1e  755c                   -jne 0x473c7c
    if (!cpu.flags.zf)
    {
        goto L_0x00473c7c;
    }
    // 00473c20  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00473c22:
    // 00473c22  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
L_0x00473c27:
    // 00473c27  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00473c2e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00473c30  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00473c33  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473c35  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00473c38  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00473c3c  8d46ff                 -lea eax, [esi - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00473c3f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00473c43  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00473c47  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00473c4a  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00473c4c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00473c4f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473c51  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00473c54  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00473c58  a16c814c00             -mov eax, dword ptr [0x4c816c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013868) /* 0x4c816c */);
    // 00473c5d  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00473c64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473c66  7505                   -jne 0x473c6d
    if (!cpu.flags.zf)
    {
        goto L_0x00473c6d;
    }
    // 00473c68  e813060000             -call 0x474280
    cpu.esp -= 4;
    sub_474280(app, cpu);
    if (cpu.terminate) return;
L_0x00473c6d:
    // 00473c6d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00473c6f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00473c71  e8eafaffff             -call 0x473760
    cpu.esp -= 4;
    sub_473760(app, cpu);
    if (cpu.terminate) return;
    // 00473c76  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473c77  e940ffffff             -jmp 0x473bbc
    goto L_0x00473bbc;
L_0x00473c7c:
    // 00473c7c  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 00473c81  eb9f                   -jmp 0x473c22
    goto L_0x00473c22;
L_0x00473c83:
    // 00473c83  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00473c88  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00473c8a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00473c91  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473c93  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00473c96  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473c98  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473c9b  c1e203                 +shl edx, 3
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
    // 00473c9e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473ca0  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00473ca3  be28000000             -mov esi, 0x28
    cpu.esi = 40 /*0x28*/;
    // 00473ca8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473caa  29c6                   +sub esi, eax
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00473cac  e976ffffff             -jmp 0x473c27
    goto L_0x00473c27;
L_0x00473cb1:
    // 00473cb1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00473cb5  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00473cb9  e9fefeffff             -jmp 0x473bbc
    goto L_0x00473bbc;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_473cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473cc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473cc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473cc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473cc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473cc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473cc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473cc6  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473cc9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00473ccb  8a25f8d24d00           -mov ah, byte ptr [0x4dd2f8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */);
    // 00473cd1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473cd3  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 00473cd6  750a                   -jne 0x473ce2
    if (!cpu.flags.zf)
    {
        goto L_0x00473ce2;
    }
    // 00473cd8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473cdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473cdc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473cdd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473cde  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473cdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ce0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ce1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473ce2:
    // 00473ce2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00473ce4  e80741fcff             -call 0x437df0
    cpu.esp -= 4;
    sub_437df0(app, cpu);
    if (cpu.terminate) return;
    // 00473ce9  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00473cec  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00473cee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473cf0  e81f010000             -call 0x473e14
    cpu.esp -= 4;
    sub_473e14(app, cpu);
    if (cpu.terminate) return;
    // 00473cf5  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473cf9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473cfb  743f                   -je 0x473d3c
    if (cpu.flags.zf)
    {
        goto L_0x00473d3c;
    }
    // 00473cfd  a1d0c94d00             -mov eax, dword ptr [0x4dc9d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5097936) /* 0x4dc9d0 */);
    // 00473d02  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00473d05  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473d07  39e8                   +cmp eax, ebp
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
    // 00473d09  7d52                   -jge 0x473d5d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473d5d;
    }
    // 00473d0b  39ca                   +cmp edx, ecx
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
    // 00473d0d  7d4e                   -jge 0x473d5d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473d5d;
    }
    // 00473d0f  8b0dd0c94d00           -mov ecx, dword ptr [0x4dc9d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5097936) /* 0x4dc9d0 */);
    // 00473d15  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473d17  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00473d19:
    // 00473d19  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00473d20  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00473d22  a1d8c94d00             -mov eax, dword ptr [0x4dc9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5097944) /* 0x4dc9d8 */);
    // 00473d27  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00473d2a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00473d2c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473d2e  8a501e                 -mov dl, byte ptr [eax + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 00473d31  c1fa04                 -sar edx, 4
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (4 /*0x4*/ % 32));
    // 00473d34  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00473d37  83fa02                 +cmp edx, 2
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
    // 00473d3a  7534                   -jne 0x473d70
    if (!cpu.flags.zf)
    {
        goto L_0x00473d70;
    }
L_0x00473d3c:
    // 00473d3c  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00473d3f  899f48995100           -mov dword ptr [edi + 0x519948], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5347656) /* 0x519948 */) = cpu.ebx;
    // 00473d45  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00473d47  0f8565000000           -jne 0x473db2
    if (!cpu.flags.zf)
    {
        goto L_0x00473db2;
    }
    // 00473d4d  899f50995100           -mov dword ptr [edi + 0x519950], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5347664) /* 0x519950 */) = cpu.ebx;
    // 00473d53  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473d56  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d59  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d5a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473d5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473d5d:
    // 00473d5d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00473d60  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473d62  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473d64  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00473d66  7e04                   -jle 0x473d6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473d6c;
    }
L_0x00473d68:
    // 00473d68  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473d6a  ebad                   -jmp 0x473d19
    goto L_0x00473d19;
L_0x00473d6c:
    // 00473d6c  f7d8                   +neg eax
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
    // 00473d6e  ebf8                   -jmp 0x473d68
    goto L_0x00473d68;
L_0x00473d70:
    // 00473d70  8a401e                 -mov al, byte ptr [eax + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 00473d73  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00473d75  3c02                   +cmp al, 2
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
    // 00473d77  74c3                   -je 0x473d3c
    if (cpu.flags.zf)
    {
        goto L_0x00473d3c;
    }
    // 00473d79  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00473d7d  39e9                   +cmp ecx, ebp
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
    // 00473d7f  7dbb                   -jge 0x473d3c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473d3c;
    }
    // 00473d81  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00473d83  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00473d85  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00473d87  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00473d8a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00473d8d  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00473d8e  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00473d90  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473d92  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473d94  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00473d98  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00473d9b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00473d9d  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00473da0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00473da2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00473da4  3d00000100             +cmp eax, 0x10000
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
    // 00473da9  7e91                   -jle 0x473d3c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473d3c;
    }
    // 00473dab  bb00000100             -mov ebx, 0x10000
    cpu.ebx = 65536 /*0x10000*/;
    // 00473db0  eb8a                   -jmp 0x473d3c
    goto L_0x00473d3c;
L_0x00473db2:
    // 00473db2  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473db6  898750995100           -mov dword ptr [edi + 0x519950], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5347664) /* 0x519950 */) = cpu.eax;
    // 00473dbc  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473dbf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473dc0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473dc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473dc2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473dc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473dc4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473dc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473dd0  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 00473dd7  7503                   -jne 0x473ddc
    if (!cpu.flags.zf)
    {
        goto L_0x00473ddc;
    }
    // 00473dd9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473ddb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473ddc:
    // 00473ddc  8b048548995100         -mov eax, dword ptr [eax*4 + 0x519948]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347656) /* 0x519948 */ + cpu.eax * 4);
    // 00473de3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473e14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00473e14  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473e15  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473e16  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473e17  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473e1a  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00473e1e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00473e20  a1fcd24d00             -mov eax, dword ptr [0x4dd2fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100284) /* 0x4dd2fc */);
    // 00473e25  83f808                 +cmp eax, 8
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
    // 00473e28  0f8782000000           -ja 0x473eb0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00473eb0;
    }
    // 00473e2e  ff2485f03d4700         -jmp dword ptr [eax*4 + 0x473df0]
    cpu.ip = app->getMemory<x86::reg32>(4668912 + cpu.eax * 4); goto dynamic_jump;
  case 0x00473e35:
    // 00473e35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473e36  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473e37  bb10270000             -mov ebx, 0x2710
    cpu.ebx = 10000 /*0x2710*/;
    // 00473e3c  8b2d8c995100           -mov ebp, dword ptr [0x51998c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5347724) /* 0x51998c */);
    // 00473e42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473e44  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00473e46  7e24                   -jle 0x473e6c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473e6c;
    }
    // 00473e48  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00473e4a:
    // 00473e4a  8b9158995100           -mov edx, dword ptr [ecx + 0x519958]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347672) /* 0x519958 */);
    // 00473e50  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00473e52  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00473e54  7e56                   -jle 0x473eac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473eac;
    }
L_0x00473e56:
    // 00473e56  39da                   +cmp edx, ebx
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
    // 00473e58  7d04                   -jge 0x473e5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00473e5e;
    }
    // 00473e5a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00473e5c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00473e5e:
    // 00473e5e  8b158c995100           -mov edx, dword ptr [0x51998c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5347724) /* 0x51998c */);
    // 00473e64  40                     -inc eax
    (cpu.eax)++;
    // 00473e65  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473e68  39d0                   +cmp eax, edx
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
    // 00473e6a  7cde                   -jl 0x473e4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473e4a;
    }
L_0x00473e6c:
    // 00473e6c  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 00473e73  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00473e75  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00473e78  8b8258995100           -mov eax, dword ptr [edx + 0x519958]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5347672) /* 0x519958 */);
    // 00473e7e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00473e82  8b825c995100           -mov eax, dword ptr [edx + 0x51995c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5347676) /* 0x51995c */);
    // 00473e88  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00473e8c  8b8260995100           -mov eax, dword ptr [edx + 0x519960]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5347680) /* 0x519960 */);
    // 00473e92  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00473e96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473e98  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473e9c  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00473e9e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473e9f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473ea0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473ea1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473ea5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473ea8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ea9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473eaa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473eab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473eac:
    // 00473eac  f7da                   +neg edx
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
    // 00473eae  eba6                   -jmp 0x473e56
    goto L_0x00473e56;
  case 0x00473eb0:
L_0x00473eb0:
    // 00473eb0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473eb2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00473eb6  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00473eba  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00473ebd  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473ec1  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00473ec3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473ec4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473ec5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473ec6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473eca  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473ecd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ece  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ecf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473ed0  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473f04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00473f04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473f05  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473f06  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473f07  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473f08  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473f09  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00473f0c  a1fcd24d00             -mov eax, dword ptr [0x4dd2fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5100284) /* 0x4dd2fc */);
    // 00473f11  83f808                 +cmp eax, 8
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
    // 00473f14  0f8717020000           -ja 0x474131
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00474131;
    }
    // 00473f1a  ff2485e03e4700         -jmp dword ptr [eax*4 + 0x473ee0]
    cpu.ip = app->getMemory<x86::reg32>(4669152 + cpu.eax * 4); goto dynamic_jump;
  case 0x00473f21:
    // 00473f21  c7058c99510001000000   -mov dword ptr [0x51998c], 1
    app->getMemory<x86::reg32>(x86::reg32(5347724) /* 0x51998c */) = 1 /*0x1*/;
    // 00473f2b  e8408d0000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00473f30  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00473f32  742d                   -je 0x473f61
    if (cpu.flags.zf)
    {
        goto L_0x00473f61;
    }
    // 00473f34  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473f39  bac2010000             -mov edx, 0x1c2
    cpu.edx = 450 /*0x1c2*/;
    // 00473f3e  b832000000             -mov eax, 0x32
    cpu.eax = 50 /*0x32*/;
    // 00473f43  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00473f47  bf58995100             -mov edi, 0x519958
    cpu.edi = 5347672 /*0x519958*/;
    // 00473f4c  e8ff010000             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 00473f51  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00473f55  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473f56  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473f57  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x00473f58:
    // 00473f58  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00473f5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473f61:
    // 00473f61  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473f66  bae8030000             -mov edx, 0x3e8
    cpu.edx = 1000 /*0x3e8*/;
    // 00473f6b  b8bc020000             -mov eax, 0x2bc
    cpu.eax = 700 /*0x2bc*/;
    // 00473f70  8d742424               -lea esi, [esp + 0x24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00473f74  bf58995100             -mov edi, 0x519958
    cpu.edi = 5347672 /*0x519958*/;
    // 00473f79  e8d2010000             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 00473f7e  8d742424               -lea esi, [esp + 0x24]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00473f82  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473f83  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473f84  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473f85  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00473f88  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f89  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f8c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473f8d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473f8e:
    // 00473f8e  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 00473f93  b869020000             -mov eax, 0x269
    cpu.eax = 617 /*0x269*/;
    // 00473f98  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00473f9d  bb74020000             -mov ebx, 0x274
    cpu.ebx = 628 /*0x274*/;
    // 00473fa2  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 00473fa7  892d8c995100           -mov dword ptr [0x51998c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5347724) /* 0x51998c */) = cpu.ebp;
    // 00473fad  a358995100             -mov dword ptr [0x519958], eax
    app->getMemory<x86::reg32>(x86::reg32(5347672) /* 0x519958 */) = cpu.eax;
    // 00473fb2  89155c995100           -mov dword ptr [0x51995c], edx
    app->getMemory<x86::reg32>(x86::reg32(5347676) /* 0x51995c */) = cpu.edx;
    // 00473fb8  892d60995100           -mov dword ptr [0x519960], ebp
    app->getMemory<x86::reg32>(x86::reg32(5347680) /* 0x519960 */) = cpu.ebp;
    // 00473fbe  891d64995100           -mov dword ptr [0x519964], ebx
    app->getMemory<x86::reg32>(x86::reg32(5347684) /* 0x519964 */) = cpu.ebx;
    // 00473fc4  893568995100           -mov dword ptr [0x519968], esi
    app->getMemory<x86::reg32>(x86::reg32(5347688) /* 0x519968 */) = cpu.esi;
    // 00473fca  892d6c995100           -mov dword ptr [0x51996c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5347692) /* 0x51996c */) = cpu.ebp;
    // 00473fd0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00473fd2  e8998c0000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00473fd7  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00473fd9  83fa01                 +cmp edx, 1
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
    // 00473fdc  7335                   -jae 0x474013
    if (!cpu.flags.cf)
    {
        goto L_0x00474013;
    }
    // 00473fde  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00473fe0  0f8572ffffff           -jne 0x473f58
    if (!cpu.flags.zf)
    {
        goto L_0x00473f58;
    }
    // 00473fe6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00473feb  baf4010000             -mov edx, 0x1f4
    cpu.edx = 500 /*0x1f4*/;
    // 00473ff0  b832000000             -mov eax, 0x32
    cpu.eax = 50 /*0x32*/;
    // 00473ff5  8d74243c               -lea esi, [esp + 0x3c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00473ff9  bf70995100             -mov edi, 0x519970
    cpu.edi = 5347696 /*0x519970*/;
    // 00473ffe  e84d010000             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 00474003  8d74243c               -lea esi, [esp + 0x3c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00474007  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474008  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474009  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047400a  83c460                 +add esp, 0x60
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
    // 0047400d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047400e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047400f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474010  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474011  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474012  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474013:
    // 00474013  7632                   -jbe 0x474047
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00474047;
    }
    // 00474015  83fa02                 +cmp edx, 2
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
    // 00474018  0f853affffff           -jne 0x473f58
    if (!cpu.flags.zf)
    {
        goto L_0x00473f58;
    }
    // 0047401e  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00474023  baaa050000             -mov edx, 0x5aa
    cpu.edx = 1450 /*0x5aa*/;
    // 00474028  b8c0030000             -mov eax, 0x3c0
    cpu.eax = 960 /*0x3c0*/;
    // 0047402d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047402f  bf70995100             -mov edi, 0x519970
    cpu.edi = 5347696 /*0x519970*/;
    // 00474034  e817010000             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 00474039  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047403b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047403c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047403d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047403e  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00474041  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474042  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474043  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474044  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474045  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474046  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474047:
    // 00474047  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047404c  ba52030000             -mov edx, 0x352
    cpu.edx = 850 /*0x352*/;
    // 00474051  b8d5020000             -mov eax, 0x2d5
    cpu.eax = 725 /*0x2d5*/;
    // 00474056  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047405a  bf70995100             -mov edi, 0x519970
    cpu.edi = 5347696 /*0x519970*/;
    // 0047405f  e8ec000000             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 00474064  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00474068  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474069  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047406a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047406b  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047406e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047406f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474070  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474071  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474072  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474073  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00474074:
    // 00474074  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00474079  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047407e  b8c8000000             -mov eax, 0xc8
    cpu.eax = 200 /*0xc8*/;
    // 00474083  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474087  89158c995100           -mov dword ptr [0x51998c], edx
    app->getMemory<x86::reg32>(x86::reg32(5347724) /* 0x51998c */) = cpu.edx;
    // 0047408d  ba7c010000             -mov edx, 0x17c
    cpu.edx = 380 /*0x17c*/;
    // 00474092  bf58995100             -mov edi, 0x519958
    cpu.edi = 5347672 /*0x519958*/;
    // 00474097  e8b4000000             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 0047409c  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004740a0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740a1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740a2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740a3  e8c88b0000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 004740a8  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004740aa  742d                   -je 0x4740d9
    if (cpu.flags.zf)
    {
        goto L_0x004740d9;
    }
    // 004740ac  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004740b1  ba60040000             -mov edx, 0x460
    cpu.edx = 1120 /*0x460*/;
    // 004740b6  b826020000             -mov eax, 0x226
    cpu.eax = 550 /*0x226*/;
    // 004740bb  8d742454               -lea esi, [esp + 0x54]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004740bf  bf64995100             -mov edi, 0x519964
    cpu.edi = 5347684 /*0x519964*/;
    // 004740c4  e887000000             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 004740c9  8d742454               -lea esi, [esp + 0x54]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004740cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004740d0  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004740d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004740d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004740d9:
    // 004740d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004740da  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004740df  bad6060000             -mov edx, 0x6d6
    cpu.edx = 1750 /*0x6d6*/;
    // 004740e4  b8b0040000             -mov eax, 0x4b0
    cpu.eax = 1200 /*0x4b0*/;
    // 004740e9  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004740ed  bf64995100             -mov edi, 0x519964
    cpu.edi = 5347684 /*0x519964*/;
    // 004740f2  e859000000             -call 0x474150
    cpu.esp -= 4;
    sub_474150(app, cpu);
    if (cpu.terminate) return;
    // 004740f7  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004740fb  b9f0060000             -mov ecx, 0x6f0
    cpu.ecx = 1776 /*0x6f0*/;
    // 00474100  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474101  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474102  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474103  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00474108  8b3d8c995100           -mov edi, dword ptr [0x51998c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5347724) /* 0x51998c */);
    // 0047410e  890d70995100           -mov dword ptr [0x519970], ecx
    app->getMemory<x86::reg32>(x86::reg32(5347696) /* 0x519970 */) = cpu.ecx;
    // 00474114  891d74995100           -mov dword ptr [0x519974], ebx
    app->getMemory<x86::reg32>(x86::reg32(5347700) /* 0x519974 */) = cpu.ebx;
    // 0047411a  47                     -inc edi
    (cpu.edi)++;
    // 0047411b  891d78995100           -mov dword ptr [0x519978], ebx
    app->getMemory<x86::reg32>(x86::reg32(5347704) /* 0x519978 */) = cpu.ebx;
    // 00474121  893d8c995100           -mov dword ptr [0x51998c], edi
    app->getMemory<x86::reg32>(x86::reg32(5347724) /* 0x51998c */) = cpu.edi;
    // 00474127  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474128  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047412b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047412c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047412d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047412e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047412f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474130  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00474131:
L_0x00474131:
    // 00474131  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00474133  892d8c995100           -mov dword ptr [0x51998c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5347724) /* 0x51998c */) = cpu.ebp;
    // 00474139  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047413c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047413d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047413e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047413f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474140  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474141  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474150  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474151  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474152  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474153  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474156  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00474158  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047415a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047415c  bd64000000             -mov ebp, 0x64
    cpu.ebp = 100 /*0x64*/;
    // 00474161  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474163  e8088b0000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00474168  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0047416a  83c23c                 -add edx, 0x3c
    (cpu.edx) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0047416d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00474171  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 00474174  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00474176  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00474178  39d0                   +cmp eax, edx
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
    // 0047417a  7e30                   -jle 0x4741ac
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004741ac;
    }
    // 0047417c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047417e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474181  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474183  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00474185  8d1437                 -lea edx, [edi + esi]
    cpu.edx = x86::reg32(cpu.edi + cpu.esi * 1);
    // 00474188  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047418c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047418e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474191  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474193  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00474195  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00474198  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047419a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047419c  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004741a0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004741a1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004741a2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004741a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004741a5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004741a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004741ac:
    // 004741ac  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004741b0  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004741b2  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004741b4  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004741b6  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004741b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004741bb  e8b08a0000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 004741c0  f7f7                   -div edi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.edi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004741c2  011424                 -add dword ptr [esp], edx
    (app->getMemory<x86::reg32>(cpu.esp)) += x86::reg32(x86::sreg32(cpu.edx));
    // 004741c5  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004741c7  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004741c9  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004741cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004741ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004741cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004741d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004741d2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004741d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004741d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4741e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004741e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004741e1  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 004741e8  83b95099510000         +cmp dword ptr [ecx + 0x519950], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347664) /* 0x519950 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004741ef  7454                   -je 0x474245
    if (cpu.flags.zf)
    {
        goto L_0x00474245;
    }
    // 004741f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004741f2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004741f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004741f5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004741f8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004741fa  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004741fd  8b9010304c00           -mov edx, dword ptr [eax + 0x4c3010]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4993040) /* 0x4c3010 */);
    // 00474203  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047420a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047420c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047420e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474211  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00474214  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474216  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00474219  8d5007                 -lea edx, [eax + 7]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0047421c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047421e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474221  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00474223  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00474225  8b9950995100           -mov ebx, dword ptr [ecx + 0x519950]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347664) /* 0x519950 */);
    // 0047422b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047422e  83fb01                 +cmp ebx, 1
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
    // 00474231  7525                   -jne 0x474258
    if (!cpu.flags.zf)
    {
        goto L_0x00474258;
    }
    // 00474233  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474235  83f809                 +cmp eax, 9
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
    // 00474238  7e12                   -jle 0x47424c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047424c;
    }
    // 0047423a  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
L_0x0047423f:
    // 0047423f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474241  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474242  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474243  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474244  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474245:
    // 00474245  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0047424a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047424b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047424c:
    // 0047424c  83f802                 +cmp eax, 2
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
    // 0047424f  7dee                   -jge 0x47423f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047423f;
    }
    // 00474251  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00474256  ebe7                   -jmp 0x47423f
    goto L_0x0047423f;
L_0x00474258:
    // 00474258  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047425a  83f805                 +cmp eax, 5
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
    // 0047425d  7e0b                   -jle 0x47426a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047426a;
    }
    // 0047425f  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00474264  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474266  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474267  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474268  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474269  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047426a:
    // 0047426a  83f802                 +cmp eax, 2
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
    // 0047426d  7dd0                   -jge 0x47423f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047423f;
    }
    // 0047426f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00474274  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474276  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474277  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474278  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474279  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474280  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474281  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474282  b8848484ff             -mov eax, 0xff848484
    cpu.eax = 4286874756 /*0xff848484*/;
    // 00474287  8b1588995100           -mov edx, dword ptr [0x519988]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5347720) /* 0x519988 */);
    // 0047428d  e8ca220000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00474292  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00474294  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 0047429b  741c                   -je 0x4742b9
    if (cpu.flags.zf)
    {
        goto L_0x004742b9;
    }
    // 0047429d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047429f  741b                   -je 0x4742bc
    if (cpu.flags.zf)
    {
        goto L_0x004742bc;
    }
L_0x004742a1:
    // 004742a1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004742a3:
    // 004742a3  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004742a6  40                     -inc eax
    (cpu.eax)++;
    // 004742a7  885af4                 -mov byte ptr [edx - 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-12) /* -0xc */) = cpu.bl;
    // 004742aa  83f828                 +cmp eax, 0x28
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004742ad  7cf4                   -jl 0x4742a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004742a3;
    }
    // 004742af  c7056c814c0001000000   -mov dword ptr [0x4c816c], 1
    app->getMemory<x86::reg32>(x86::reg32(5013868) /* 0x4c816c */) = 1 /*0x1*/;
L_0x004742b9:
    // 004742b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004742ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004742bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004742bc:
    // 004742bc  b318                   -mov bl, 0x18
    cpu.bl = 24 /*0x18*/;
    // 004742be  ebe1                   -jmp 0x4742a1
    goto L_0x004742a1;
}

/* align: skip  */
void Application::sub_4742c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004742c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4742d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004742d0  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 004742d7  7501                   -jne 0x4742da
    if (!cpu.flags.zf)
    {
        goto L_0x004742da;
    }
    // 004742d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004742da:
    // 004742da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004742db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004742dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004742dd  b920a95100             -mov ecx, 0x51a920
    cpu.ecx = 5351712 /*0x51a920*/;
    // 004742e2  ba64d84b00             -mov edx, 0x4bd864
    cpu.edx = 4970596 /*0x4bd864*/;
    // 004742e7  a1e8975100             -mov eax, dword ptr [0x5197e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 004742ec  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004742ee  e8adf3ffff             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 004742f3  b92ca95100             -mov ecx, 0x51a92c
    cpu.ecx = 5351724 /*0x51a92c*/;
    // 004742f8  ba6cd84b00             -mov edx, 0x4bd86c
    cpu.edx = 4970604 /*0x4bd86c*/;
    // 004742fd  a1e8975100             -mov eax, dword ptr [0x5197e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 00474302  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474304  e897f3ffff             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00474309  b938a95100             -mov ecx, 0x51a938
    cpu.ecx = 5351736 /*0x51a938*/;
    // 0047430e  ba74d84b00             -mov edx, 0x4bd874
    cpu.edx = 4970612 /*0x4bd874*/;
    // 00474313  a1e8975100             -mov eax, dword ptr [0x5197e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 00474318  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047431a  e881f3ffff             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 0047431f  b944a95100             -mov ecx, 0x51a944
    cpu.ecx = 5351748 /*0x51a944*/;
    // 00474324  ba7cd84b00             -mov edx, 0x4bd87c
    cpu.edx = 4970620 /*0x4bd87c*/;
    // 00474329  a1e8975100             -mov eax, dword ptr [0x5197e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 0047432e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474330  e86bf3ffff             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00474335  b950a95100             -mov ecx, 0x51a950
    cpu.ecx = 5351760 /*0x51a950*/;
    // 0047433a  ba84d84b00             -mov edx, 0x4bd884
    cpu.edx = 4970628 /*0x4bd884*/;
    // 0047433f  a1e8975100             -mov eax, dword ptr [0x5197e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 00474344  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474346  e855f3ffff             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 0047434b  b95ca95100             -mov ecx, 0x51a95c
    cpu.ecx = 5351772 /*0x51a95c*/;
    // 00474350  ba8cd84b00             -mov edx, 0x4bd88c
    cpu.edx = 4970636 /*0x4bd88c*/;
    // 00474355  a1e8975100             -mov eax, dword ptr [0x5197e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 0047435a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047435c  e83ff3ffff             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00474361  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474362  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474363  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474364  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474384(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00474384  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474385  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474386  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474387  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047438a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047438c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047438e  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 00474395  7450                   -je 0x4743e7
    if (cpu.flags.zf)
    {
        goto L_0x004743e7;
    }
    // 00474397  833d70d14d0000         +cmp dword ptr [0x4dd170], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099888) /* 0x4dd170 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047439e  7447                   -je 0x4743e7
    if (cpu.flags.zf)
    {
        goto L_0x004743e7;
    }
    // 004743a0  833df4d04d0000         +cmp dword ptr [0x4dd0f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099764) /* 0x4dd0f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004743a7  753e                   -jne 0x4743e7
    if (!cpu.flags.zf)
    {
        goto L_0x004743e7;
    }
    // 004743a9  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004743ad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004743af  e85c000000             -call 0x474410
    cpu.esp -= 4;
    sub_474410(app, cpu);
    if (cpu.terminate) return;
    // 004743b4  833dd0ed4d0000         +cmp dword ptr [0x4dedd0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5107152) /* 0x4dedd0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004743bb  7513                   -jne 0x4743d0
    if (!cpu.flags.zf)
    {
        goto L_0x004743d0;
    }
    // 004743bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004743bf  e85cf3ffff             -call 0x473720
    cpu.esp -= 4;
    sub_473720(app, cpu);
    if (cpu.terminate) return;
    // 004743c4  83f804                 +cmp eax, 4
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
    // 004743c7  7707                   -ja 0x4743d0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004743d0;
    }
    // 004743c9  ff248570434700         -jmp dword ptr [eax*4 + 0x474370]
    cpu.ip = app->getMemory<x86::reg32>(4670320 + cpu.eax * 4); goto dynamic_jump;
  case 0x004743d0:
L_0x004743d0:
    // 004743d0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004743d2  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004743d6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004743d7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004743d8  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004743da  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004743dc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004743dd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004743de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004743e0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004743e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743e4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004743e7:
    // 004743e7  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004743e9  e8026afeff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 004743ee  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004743f0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004743f2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004743f3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004743f4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004743f6  83c410                 +add esp, 0x10
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
    // 004743f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004743fc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004743fd:
    // 004743fd  e81e020000             -call 0x474620
    cpu.esp -= 4;
    sub_474620(app, cpu);
    if (cpu.terminate) return;
    // 00474402  ebcc                   -jmp 0x4743d0
    goto L_0x004743d0;
  case 0x00474404:
    // 00474404  e897000000             -call 0x4744a0
    cpu.esp -= 4;
    sub_4744a0(app, cpu);
    if (cpu.terminate) return;
    // 00474409  ebc5                   -jmp 0x4743d0
    goto L_0x004743d0;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474410  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474411  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474412  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474413  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474416  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00474418  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 0047441f  7468                   -je 0x474489
    if (cpu.flags.zf)
    {
        goto L_0x00474489;
    }
    // 00474421  e8aaf9ffff             -call 0x473dd0
    cpu.esp -= 4;
    sub_473dd0(app, cpu);
    if (cpu.terminate) return;
    // 00474426  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474428  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047442b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047442d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00474430  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474432  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00474435  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474437  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047443a  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047443d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047443f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00474442  a374a95100             -mov dword ptr [0x51a974], eax
    app->getMemory<x86::reg32>(x86::reg32(5351796) /* 0x51a974 */) = cpu.eax;
    // 00474447  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474449  743e                   -je 0x474489
    if (cpu.flags.zf)
    {
        goto L_0x00474489;
    }
    // 0047444b  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 00474450  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00474452  be7ca75100             -mov esi, 0x51a77c
    cpu.esi = 5351292 /*0x51a77c*/;
    // 00474457  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0047445e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00474460  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00474462  ba90995100             -mov edx, 0x519990
    cpu.edx = 5347728 /*0x519990*/;
    // 00474467  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047446a  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0047446e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474470  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474474  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00474478  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474479  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047447a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047447c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047447e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047447f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474480  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474482  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474485  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474486  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474487  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474488  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474489:
    // 00474489  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047448b  e86069feff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 00474490  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00474492  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00474494  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474495  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474496  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474498  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047449b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047449c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047449d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047449e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4744a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004744a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004744a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004744a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004744a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004744a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004744a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004744a6  b8a53c0200             -mov eax, 0x23ca5
    cpu.eax = 146597 /*0x23ca5*/;
    // 004744ab  8b155cd14d00           -mov edx, dword ptr [0x4dd15c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099868) /* 0x4dd15c */);
    // 004744b1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004744b3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004744b6  c1e810                 +shr eax, 0x10
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
    // 004744b9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004744bb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004744bd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004744c0  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004744c3  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004744c5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004744c8  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004744cd  2b1d74a95100           -sub ebx, dword ptr [0x51a974]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5351796) /* 0x51a974 */)));
    // 004744d3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004744d5  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004744d8  0f8dbd000000           -jge 0x47459b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047459b;
    }
    // 004744de  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004744e0  b928000000             -mov ecx, 0x28
    cpu.ecx = 40 /*0x28*/;
    // 004744e5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004744e8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004744ea  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 004744f1  bf07000000             -mov edi, 7
    cpu.edi = 7 /*0x7*/;
    // 004744f6  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004744f8  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004744fa  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
L_0x004744fd:
    // 004744fd  8aa37ca95100           -mov ah, byte ptr [ebx + 0x51a97c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */);
    // 00474503  80fc64                 +cmp ah, 0x64
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474506  0f8796000000           -ja 0x4745a2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004745a2;
    }
    // 0047450c  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0047450e  fec2                   -inc dl
    (cpu.dl)++;
    // 00474510  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00474512  88937ca95100           -mov byte ptr [ebx + 0x51a97c], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */) = cpu.dl;
    // 00474518  83ff02                 +cmp edi, 2
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047451b  7d05                   -jge 0x474522
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474522;
    }
    // 0047451d  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00474522:
    // 00474522  83fd3c                 +cmp ebp, 0x3c
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474525  7e67                   -jle 0x47458e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047458e;
    }
    // 00474527  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474529  8a937ca95100           -mov dl, byte ptr [ebx + 0x51a97c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */);
    // 0047452f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474531  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474534  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474536  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00474538  7554                   -jne 0x47458e
    if (!cpu.flags.zf)
    {
        goto L_0x0047458e;
    }
    // 0047453a  a170814c00             -mov eax, dword ptr [0x4c8170]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013872) /* 0x4c8170 */);
    // 0047453f  8bb19c995100           -mov esi, dword ptr [ecx + 0x51999c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347740) /* 0x51999c */);
    // 00474545  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00474547  a1e0a95100             -mov eax, dword ptr [0x51a9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351904) /* 0x51a9e0 */);
    // 0047454c  8b9198995100           -mov edx, dword ptr [ecx + 0x519998]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */);
    // 00474552  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00474555  89b19c995100           -mov dword ptr [ecx + 0x51999c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347740) /* 0x51999c */) = cpu.esi;
    // 0047455b  39d0                   +cmp eax, edx
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
    // 0047455d  7e0f                   -jle 0x47456e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047456e;
    }
    // 0047455f  a170814c00             -mov eax, dword ptr [0x4c8170]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013872) /* 0x4c8170 */);
    // 00474564  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00474566  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00474568  89b198995100           -mov dword ptr [ecx + 0x519998], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */) = cpu.esi;
L_0x0047456e:
    // 0047456e  a1e2a95100             -mov eax, dword ptr [0x51a9e2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351906) /* 0x51a9e2 */);
    // 00474573  8b9198995100           -mov edx, dword ptr [ecx + 0x519998]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */);
    // 00474579  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047457c  39d0                   +cmp eax, edx
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
    // 0047457e  7d0e                   -jge 0x47458e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047458e;
    }
    // 00474580  a170814c00             -mov eax, dword ptr [0x4c8170]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013872) /* 0x4c8170 */);
    // 00474585  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00474588  89b198995100           -mov dword ptr [ecx + 0x519998], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */) = cpu.esi;
L_0x0047458e:
    // 0047458e  43                     -inc ebx
    (cpu.ebx)++;
    // 0047458f  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00474592  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474595  0f8c62ffffff           -jl 0x4744fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004744fd;
    }
L_0x0047459b:
    // 0047459b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047459c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047459d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047459e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047459f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004745a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004745a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004745a2:
    // 004745a2  e8c9860000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 004745a7  8b35e2a95100           -mov esi, dword ptr [0x51a9e2]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5351906) /* 0x51a9e2 */);
    // 004745ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004745af  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004745b2  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004745b4  a1dea95100             -mov eax, dword ptr [0x51a9de]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351902) /* 0x51a9de */);
    // 004745b9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004745bc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004745be  898198995100           -mov dword ptr [ecx + 0x519998], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */) = cpu.eax;
    // 004745c4  e8a7860000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 004745c9  8b35e0a95100           -mov esi, dword ptr [0x51a9e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5351904) /* 0x51a9e0 */);
    // 004745cf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004745d1  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004745d4  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004745d6  a1e4a95100             -mov eax, dword ptr [0x51a9e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351908) /* 0x51a9e4 */);
    // 004745db  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004745de  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
    // 004745e3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004745e5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004745e7  89819c995100           -mov dword ptr [ecx + 0x51999c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347740) /* 0x51999c */) = cpu.eax;
    // 004745ed  e87e860000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 004745f2  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004745f4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004745f6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004745f8  88837ca95100           -mov byte ptr [ebx + 0x51a97c], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */) = cpu.al;
    // 004745fe  43                     -inc ebx
    (cpu.ebx)++;
    // 004745ff  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00474602  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474605  0f8cf2feffff           -jl 0x4744fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004744fd;
    }
    // 0047460b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047460c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047460d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047460e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047460f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474610  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474611  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474622  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474623  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474624  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474625  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474626  b8a53c0200             -mov eax, 0x23ca5
    cpu.eax = 146597 /*0x23ca5*/;
    // 0047462b  8b155cd14d00           -mov edx, dword ptr [0x4dd15c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5099868) /* 0x4dd15c */);
    // 00474631  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00474633  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00474636  c1e810                 +shr eax, 0x10
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
    // 00474639  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047463b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047463d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474640  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00474643  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00474645  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00474648  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0047464d  2b1d74a95100           -sub ebx, dword ptr [0x51a974]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5351796) /* 0x51a974 */)));
    // 00474653  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00474655  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474658  0f8dcf000000           -jge 0x47472d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047472d;
    }
    // 0047465e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00474660  b928000000             -mov ecx, 0x28
    cpu.ecx = 40 /*0x28*/;
    // 00474665  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474668  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047466a  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 00474671  bd07000000             -mov ebp, 7
    cpu.ebp = 7 /*0x7*/;
    // 00474676  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00474678  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047467a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
L_0x0047467d:
    // 0047467d  8aa37ca95100           -mov ah, byte ptr [ebx + 0x51a97c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */);
    // 00474683  80fcb4                 +cmp ah, 0xb4
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(180 /*0xb4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00474686  0f87a8000000           -ja 0x474734
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00474734;
    }
    // 0047468c  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 0047468e  fec2                   -inc dl
    (cpu.dl)++;
    // 00474690  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00474692  88937ca95100           -mov byte ptr [ebx + 0x51a97c], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */) = cpu.dl;
    // 00474698  83fd02                 +cmp ebp, 2
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047469b  7d05                   -jge 0x4746a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004746a2;
    }
    // 0047469d  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x004746a2:
    // 004746a2  83ff50                 +cmp edi, 0x50
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004746a5  7e56                   -jle 0x4746fd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004746fd;
    }
    // 004746a7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004746a9  8a937ca95100           -mov dl, byte ptr [ebx + 0x51a97c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */);
    // 004746af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004746b1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004746b4  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004746b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004746b8  7543                   -jne 0x4746fd
    if (!cpu.flags.zf)
    {
        goto L_0x004746fd;
    }
    // 004746ba  a1e0a95100             -mov eax, dword ptr [0x51a9e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351904) /* 0x51a9e0 */);
    // 004746bf  8bb19c995100           -mov esi, dword ptr [ecx + 0x51999c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347740) /* 0x51999c */);
    // 004746c5  8b9198995100           -mov edx, dword ptr [ecx + 0x519998]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */);
    // 004746cb  4e                     -dec esi
    (cpu.esi)--;
    // 004746cc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004746cf  89b19c995100           -mov dword ptr [ecx + 0x51999c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347740) /* 0x51999c */) = cpu.esi;
    // 004746d5  39d0                   +cmp eax, edx
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
    // 004746d7  7e09                   -jle 0x4746e2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004746e2;
    }
    // 004746d9  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004746dc  89b198995100           -mov dword ptr [ecx + 0x519998], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */) = cpu.esi;
L_0x004746e2:
    // 004746e2  a1e2a95100             -mov eax, dword ptr [0x51a9e2]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351906) /* 0x51a9e2 */);
    // 004746e7  8b9198995100           -mov edx, dword ptr [ecx + 0x519998]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */);
    // 004746ed  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004746f0  39d0                   +cmp eax, edx
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
    // 004746f2  7d09                   -jge 0x4746fd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004746fd;
    }
    // 004746f4  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004746f7  89b198995100           -mov dword ptr [ecx + 0x519998], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */) = cpu.esi;
L_0x004746fd:
    // 004746fd  83ff0a                 +cmp edi, 0xa
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474700  7d1e                   -jge 0x474720
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474720;
    }
    // 00474702  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474704  8a937ca95100           -mov dl, byte ptr [ebx + 0x51a97c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */);
    // 0047470a  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 0047470f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474711  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00474714  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00474716  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00474718  7506                   -jne 0x474720
    if (!cpu.flags.zf)
    {
        goto L_0x00474720;
    }
    // 0047471a  ff819c995100           -inc dword ptr [ecx + 0x51999c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347740) /* 0x51999c */))++;
L_0x00474720:
    // 00474720  43                     -inc ebx
    (cpu.ebx)++;
    // 00474721  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00474724  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474727  0f8c50ffffff           -jl 0x47467d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047467d;
    }
L_0x0047472d:
    // 0047472d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047472e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047472f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474730  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474731  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474732  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474733  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474734:
    // 00474734  e837850000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00474739  8b35e2a95100           -mov esi, dword ptr [0x51a9e2]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5351906) /* 0x51a9e2 */);
    // 0047473f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474741  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00474744  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00474746  a1dea95100             -mov eax, dword ptr [0x51a9de]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351902) /* 0x51a9de */);
    // 0047474b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047474e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474750  899198995100           -mov dword ptr [ecx + 0x519998], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347736) /* 0x519998 */) = cpu.edx;
    // 00474756  e815850000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 0047475b  8b35e0a95100           -mov esi, dword ptr [0x51a9e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5351904) /* 0x51a9e0 */);
    // 00474761  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474763  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00474766  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00474768  a1e4a95100             -mov eax, dword ptr [0x51a9e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351908) /* 0x51a9e4 */);
    // 0047476d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00474770  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00474772  be64000000             -mov esi, 0x64
    cpu.esi = 100 /*0x64*/;
    // 00474777  89919c995100           -mov dword ptr [ecx + 0x51999c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5347740) /* 0x51999c */) = cpu.edx;
    // 0047477d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047477f  e8ec840000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00474784  f7f6                   -div esi
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.esi;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00474786  b8b4000000             -mov eax, 0xb4
    cpu.eax = 180 /*0xb4*/;
    // 0047478b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047478d  88837ca95100           -mov byte ptr [ebx + 0x51a97c], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5351804) /* 0x51a97c */) = cpu.al;
    // 00474793  43                     -inc ebx
    (cpu.ebx)++;
    // 00474794  83c124                 -add ecx, 0x24
    (cpu.ecx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00474797  83fb64                 +cmp ebx, 0x64
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047479a  0f8cddfeffff           -jl 0x47467d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047467d;
    }
    // 004747a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4747b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004747b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004747b1  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 004747b8  7502                   -jne 0x4747bc
    if (!cpu.flags.zf)
    {
        goto L_0x004747bc;
    }
    // 004747ba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004747bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004747bc:
    // 004747bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004747bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004747be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004747bf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004747c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004747c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004747c3  e82836fcff             -call 0x437df0
    cpu.esp -= 4;
    sub_437df0(app, cpu);
    if (cpu.terminate) return;
    // 004747c8  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 004747ce  833805                 +cmp dword ptr [eax], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004747d1  0f85f7000000           -jne 0x4748ce
    if (!cpu.flags.zf)
    {
        goto L_0x004748ce;
    }
    // 004747d7  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004747dc  ba5f000000             -mov edx, 0x5f
    cpu.edx = 95 /*0x5f*/;
    // 004747e1  bbb9000000             -mov ebx, 0xb9
    cpu.ebx = 185 /*0xb9*/;
    // 004747e6  bf96000000             -mov edi, 0x96
    cpu.edi = 150 /*0x96*/;
    // 004747eb  66a3e4a95100           -mov word ptr [0x51a9e4], ax
    app->getMemory<x86::reg16>(x86::reg32(5351908) /* 0x51a9e4 */) = cpu.ax;
    // 004747f1  668915e6a95100         -mov word ptr [0x51a9e6], dx
    app->getMemory<x86::reg16>(x86::reg32(5351910) /* 0x51a9e6 */) = cpu.dx;
    // 004747f8  66891de2a95100         -mov word ptr [0x51a9e2], bx
    app->getMemory<x86::reg16>(x86::reg32(5351906) /* 0x51a9e2 */) = cpu.bx;
    // 004747ff  66893de0a95100         -mov word ptr [0x51a9e0], di
    app->getMemory<x86::reg16>(x86::reg32(5351904) /* 0x51a9e0 */) = cpu.di;
L_0x00474806:
    // 00474806  bedcffffff             -mov esi, 0xffffffdc
    cpu.esi = 4294967260 /*0xffffffdc*/;
    // 0047480b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047480d  bf90995100             -mov edi, 0x519990
    cpu.edi = 5347728 /*0x519990*/;
    // 00474812  890d74a95100           -mov dword ptr [0x51a974], ecx
    app->getMemory<x86::reg32>(x86::reg32(5351796) /* 0x51a974 */) = cpu.ecx;
L_0x00474818:
    // 00474818  6bd924                 -imul ebx, ecx, 0x24
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 0047481b  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047481d  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00474822  89ab90995100           -mov dword ptr [ebx + 0x519990], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5347728) /* 0x519990 */) = cpu.ebp;
    // 00474828  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047482a  898394995100           -mov dword ptr [ebx + 0x519994], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5347732) /* 0x519994 */) = cpu.eax;
    // 00474830  bd05000000             -mov ebp, 5
    cpu.ebp = 5 /*0x5*/;
    // 00474835  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00474837  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047483a  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047483c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047483e  0f85bf000000           -jne 0x474903
    if (!cpu.flags.zf)
    {
        goto L_0x00474903;
    }
    // 00474844  c783b09951002ca95100   -mov dword ptr [ebx + 0x5199b0], 0x51a92c
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5347760) /* 0x5199b0 */) = 5351724 /*0x51a92c*/;
L_0x0047484e:
    // 0047484e  e81d840000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00474853  8b1de2a95100           -mov ebx, dword ptr [0x51a9e2]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5351906) /* 0x51a9e2 */);
    // 00474859  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047485b  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047485e  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00474860  6bd924                 -imul ebx, ecx, 0x24
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(36 /*0x24*/)));
    // 00474863  a1dea95100             -mov eax, dword ptr [0x51a9de]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351902) /* 0x51a9de */);
    // 00474868  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047486b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047486d  899398995100           -mov dword ptr [ebx + 0x519998], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5347736) /* 0x519998 */) = cpu.edx;
    // 00474873  e8f8830000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00474878  8b2de0a95100           -mov ebp, dword ptr [0x51a9e0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5351904) /* 0x51a9e0 */);
    // 0047487e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474880  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00474883  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00474885  a1e4a95100             -mov eax, dword ptr [0x51a9e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351908) /* 0x51a9e4 */);
    // 0047488a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047488d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047488f  89939c995100           -mov dword ptr [ebx + 0x51999c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5347740) /* 0x51999c */) = cpu.edx;
    // 00474895  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 0047489a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047489c  e8cf830000             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 004748a1  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004748a3  83c624                 -add esi, 0x24
    (cpu.esi) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004748a6  b8b4000000             -mov eax, 0xb4
    cpu.eax = 180 /*0xb4*/;
    // 004748ab  41                     -inc ecx
    (cpu.ecx)++;
    // 004748ac  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004748ae  83c724                 -add edi, 0x24
    (cpu.edi) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004748b1  88817ba95100           -mov byte ptr [ecx + 0x51a97b], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5351803) /* 0x51a97b */) = cpu.al;
    // 004748b7  39d9                   +cmp ecx, ebx
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
    // 004748b9  7d57                   -jge 0x474912
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00474912;
    }
    // 004748bb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004748bd  0f8e55ffffff           -jle 0x474818
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00474818;
    }
    // 004748c3  89be90995100           -mov dword ptr [esi + 0x519990], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5347728) /* 0x519990 */) = cpu.edi;
    // 004748c9  e94affffff             -jmp 0x474818
    goto L_0x00474818;
L_0x004748ce:
    // 004748ce  bbf4010000             -mov ebx, 0x1f4
    cpu.ebx = 500 /*0x1f4*/;
    // 004748d3  b950000000             -mov ecx, 0x50
    cpu.ecx = 80 /*0x50*/;
    // 004748d8  bec8000000             -mov esi, 0xc8
    cpu.esi = 200 /*0xc8*/;
    // 004748dd  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 004748e2  66891de4a95100         -mov word ptr [0x51a9e4], bx
    app->getMemory<x86::reg16>(x86::reg32(5351908) /* 0x51a9e4 */) = cpu.bx;
    // 004748e9  66890de6a95100         -mov word ptr [0x51a9e6], cx
    app->getMemory<x86::reg16>(x86::reg32(5351910) /* 0x51a9e6 */) = cpu.cx;
    // 004748f0  668935e2a95100         -mov word ptr [0x51a9e2], si
    app->getMemory<x86::reg16>(x86::reg32(5351906) /* 0x51a9e2 */) = cpu.si;
    // 004748f7  668915e0a95100         -mov word ptr [0x51a9e0], dx
    app->getMemory<x86::reg16>(x86::reg32(5351904) /* 0x51a9e0 */) = cpu.dx;
    // 004748fe  e903ffffff             -jmp 0x474806
    goto L_0x00474806;
L_0x00474903:
    // 00474903  c783b099510020a95100   -mov dword ptr [ebx + 0x5199b0], 0x51a920
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5347760) /* 0x5199b0 */) = 5351712 /*0x51a920*/;
    // 0047490d  e93cffffff             -jmp 0x47484e
    goto L_0x0047484e;
L_0x00474912:
    // 00474912  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474914  a378a95100             -mov dword ptr [0x51a978], eax
    app->getMemory<x86::reg32>(x86::reg32(5351800) /* 0x51a978 */) = cpu.eax;
    // 00474919  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047491a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047491b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047491c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047491d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047491e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047491f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_474920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474922  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00474927  8b1d90814c00           -mov ebx, dword ptr [0x4c8190]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013904) /* 0x4c8190 */);
    // 0047492d  a394814c00             -mov dword ptr [0x4c8194], eax
    app->getMemory<x86::reg32>(x86::reg32(5013908) /* 0x4c8194 */) = cpu.eax;
    // 00474932  891598814c00           -mov dword ptr [0x4c8198], edx
    app->getMemory<x86::reg32>(x86::reg32(5013912) /* 0x4c8198 */) = cpu.edx;
    // 00474938  890d8c814c00           -mov dword ptr [0x4c818c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5013900) /* 0x4c818c */) = cpu.ecx;
    // 0047493e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00474940  7403                   -je 0x474945
    if (cpu.flags.zf)
    {
        goto L_0x00474945;
    }
    // 00474942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474943  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474944  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474945:
    // 00474945  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474946  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474947  6880534700             -push 0x475380
    app->getMemory<x86::reg32>(cpu.esp-4) = 4674432 /*0x475380*/;
    cpu.esp -= 4;
    // 0047494c  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047494e  2eff1500544b00         -call dword ptr cs:[0x4b5400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936704) /* 0x4b5400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474955  a390814c00             -mov dword ptr [0x4c8190], eax
    app->getMemory<x86::reg32>(x86::reg32(5013904) /* 0x4c8190 */) = cpu.eax;
    // 0047495a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047495b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047495c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_474960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474960  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474961  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474962  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474964  8a258db55100           -mov ah, byte ptr [0x51b58d]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
    // 0047496a  89158c814c00           -mov dword ptr [0x4c818c], edx
    app->getMemory<x86::reg32>(x86::reg32(5013900) /* 0x4c818c */) = cpu.edx;
    // 00474970  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00474972  740a                   -je 0x47497e
    if (cpu.flags.zf)
    {
        goto L_0x0047497e;
    }
    // 00474974  8b0d90814c00           -mov ecx, dword ptr [0x4c8190]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013904) /* 0x4c8190 */);
    // 0047497a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047497c  7503                   -jne 0x474981
    if (!cpu.flags.zf)
    {
        goto L_0x00474981;
    }
L_0x0047497e:
    // 0047497e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047497f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474980  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474981:
    // 00474981  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474982  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474983  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00474985  2eff1514544b00         -call dword ptr cs:[0x4b5414]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936724) /* 0x4b5414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047498c  893590814c00           -mov dword ptr [0x4c8190], esi
    app->getMemory<x86::reg32>(x86::reg32(5013904) /* 0x4c8190 */) = cpu.esi;
    // 00474992  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474993  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474994  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474995  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4749a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004749a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004749a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004749a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004749a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004749a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004749a6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004749a8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004749aa  2eff15c8534b00         -call dword ptr cs:[0x4b53c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936648) /* 0x4b53c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004749b1  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004749b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004749b5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004749b8  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004749ba  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004749bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004749be  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004749c0  2eff15c8534b00         -call dword ptr cs:[0x4b53c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936648) /* 0x4b53c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004749c7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004749c9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004749cb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004749ce  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004749d0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004749d2  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004749d4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004749d6  e805000000             -call 0x4749e0
    cpu.esp -= 4;
    sub_4749e0(app, cpu);
    if (cpu.terminate) return;
    // 004749db  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749dc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004749df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4749e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004749e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004749e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004749e2  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004749e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004749e7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004749eb  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004749ef  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004749f1  6af0                   -push -0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 004749f3  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004749f7  8b1584b55100           -mov edx, dword ptr [0x51b584]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 004749fd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004749ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474a00  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00474a04  2eff15cc534b00         -call dword ptr cs:[0x4b53cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936652) /* 0x4b53cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474a0b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a0c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474a10  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a11  2eff1584534b00         -call dword ptr cs:[0x4b5384]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936580) /* 0x4b5384 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474a18  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474a1c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474a20  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 00474a22  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474a24  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474a28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a29  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00474a2d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474a2f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474a31  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474a32  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474a34  8b2d84b55100           -mov ebp, dword ptr [0x51b584]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00474a3a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474a3b  2eff15fc534b00         -call dword ptr cs:[0x4b53fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936700) /* 0x4b53fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474a42  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474a44  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a45  a184b55100             -mov eax, dword ptr [0x51b584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00474a4a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a4b  2eff15b8534b00         -call dword ptr cs:[0x4b53b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936632) /* 0x4b53b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474a52  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474a54  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a55  8b1584b55100           -mov edx, dword ptr [0x51b584]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00474a5b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474a5c  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474a63  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474a67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474a68  8b0d84b55100           -mov ecx, dword ptr [0x51b584]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00474a6e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474a6f  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474a76  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00474a7a  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00474a7d  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474a7f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00474a83  a344b15100             -mov dword ptr [0x51b144], eax
    app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */) = cpu.eax;
    // 00474a88  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00474a8c  891d94b55100           -mov dword ptr [0x51b594], ebx
    app->getMemory<x86::reg32>(x86::reg32(5354900) /* 0x51b594 */) = cpu.ebx;
    // 00474a92  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00474a94  893598b55100           -mov dword ptr [0x51b598], esi
    app->getMemory<x86::reg32>(x86::reg32(5354904) /* 0x51b598 */) = cpu.esi;
    // 00474a9a  a348b15100             -mov dword ptr [0x51b148], eax
    app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */) = cpu.eax;
    // 00474a9f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00474aa2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474aa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474aa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474ab0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474ab1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474ab2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474ab3  833d84b5510000         +cmp dword ptr [0x51b584], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474aba  7504                   -jne 0x474ac0
    if (!cpu.flags.zf)
    {
        goto L_0x00474ac0;
    }
    // 00474abc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474abd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474abe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474abf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474ac0:
    // 00474ac0  68ccdb4b00             -push 0x4bdbcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971468 /*0x4bdbcc*/;
    cpu.esp -= 4;
    // 00474ac5  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00474ac7  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00474acc  e89f5d0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00474ad1  8b0d84814c00           -mov ecx, dword ptr [0x4c8184]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013892) /* 0x4c8184 */);
    // 00474ad7  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474ada  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00474adc  740e                   -je 0x474aec
    if (cpu.flags.zf)
    {
        goto L_0x00474aec;
    }
    // 00474ade  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00474ae0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474ae2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474ae3  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00474ae5  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00474aec:
    // 00474aec  8b3588814c00           -mov esi, dword ptr [0x4c8188]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5013896) /* 0x4c8188 */);
    // 00474af2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00474af4  740e                   -je 0x474b04
    if (cpu.flags.zf)
    {
        goto L_0x00474b04;
    }
    // 00474af6  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00474af8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474afa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474afb  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 00474afd  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00474b04:
    // 00474b04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474b05  68e4db4b00             -push 0x4bdbe4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971492 /*0x4bdbe4*/;
    cpu.esp -= 4;
    // 00474b0a  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00474b0c  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00474b11  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474b13  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474b15  e8565d0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00474b1a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474b1d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474b1f  b866040000             -mov eax, 0x466
    cpu.eax = 1126 /*0x466*/;
    // 00474b24  e8a7150000             -call 0x4760d0
    cpu.esp -= 4;
    sub_4760d0(app, cpu);
    if (cpu.terminate) return;
    // 00474b29  833d84b5510000         +cmp dword ptr [0x51b584], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474b30  741a                   -je 0x474b4c
    if (cpu.flags.zf)
    {
        goto L_0x00474b4c;
    }
    // 00474b32  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00474b34:
    // 00474b34  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474b36  e821a10000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00474b3b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474b3d  e83e350000             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00474b42  3b1584b55100           +cmp edx, dword ptr [0x51b584]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474b48  75ea                   -jne 0x474b34
    if (!cpu.flags.zf)
    {
        goto L_0x00474b34;
    }
    // 00474b4a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00474b4c:
    // 00474b4c  6808dc4b00             -push 0x4bdc08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971528 /*0x4bdc08*/;
    cpu.esp -= 4;
    // 00474b51  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00474b53  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00474b58  e8135d0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00474b5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00474b60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b62  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b63  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474b64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474b70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474b71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474b72  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474b73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474b74  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00474b77  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00474b79  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00474b7d  833da0814c0000         +cmp dword ptr [0x4c81a0], 0
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
    // 00474b84  750a                   -jne 0x474b90
    if (!cpu.flags.zf)
    {
        goto L_0x00474b90;
    }
    // 00474b86  e82da40000             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00474b8b  a3a0814c00             -mov dword ptr [0x4c81a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */) = cpu.eax;
L_0x00474b90:
    // 00474b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474b91  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00474b95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474b96  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00474b97  6850db4b00             -push 0x4bdb50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971344 /*0x4bdb50*/;
    cpu.esp -= 4;
    // 00474b9c  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00474b9e  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00474ba3  e8c85c0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00474ba8  8a25a0ae5100           -mov ah, byte ptr [0x51aea0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5353120) /* 0x51aea0 */);
    // 00474bae  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00474bb1  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00474bb3  0f85c2020000           -jne 0x474e7b
    if (!cpu.flags.zf)
    {
        goto L_0x00474e7b;
    }
    // 00474bb9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474bbb  2eff15d8544b00         -call dword ptr cs:[0x4b54d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936920) /* 0x4b54d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474bc2  8b3dac814c00           -mov edi, dword ptr [0x4c81ac]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5013932) /* 0x4c81ac */);
    // 00474bc8  a3a0b55100             -mov dword ptr [0x51b5a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5354912) /* 0x51b5a0 */) = cpu.eax;
    // 00474bcd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00474bcf  750c                   -jne 0x474bdd
    if (!cpu.flags.zf)
    {
        goto L_0x00474bdd;
    }
    // 00474bd1  a1bc605200             -mov eax, dword ptr [0x5260bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5398716) /* 0x5260bc */);
    // 00474bd6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00474bd8  a3ac814c00             -mov dword ptr [0x4c81ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5013932) /* 0x4c81ac */) = cpu.eax;
L_0x00474bdd:
    // 00474bdd  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 00474be2  ba80544700             -mov edx, 0x475480
    cpu.edx = 4674688 /*0x475480*/;
    // 00474be7  8b3db0814c00           -mov edi, dword ptr [0x4c81b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5013936) /* 0x4c81b0 */);
    // 00474bed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00474bef  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00474bf2  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00474bf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474bf7  a1a0b55100             -mov eax, dword ptr [0x51b5a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354912) /* 0x51b5a0 */);
    // 00474bfc  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00474c00  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474c01  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00474c05  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00474c09  2eff15d0534b00         -call dword ptr cs:[0x4b53d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936656) /* 0x4b53d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474c10  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00474c12  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474c14  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00474c18  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00474c1c  2eff157c534b00         -call dword ptr cs:[0x4b537c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936572) /* 0x4b537c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474c23  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00474c27  a1ac814c00             -mov eax, dword ptr [0x4c81ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013932) /* 0x4c81ac */);
    // 00474c2c  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00474c30  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00474c34  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00474c36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474c37  2eff15e4534b00         -call dword ptr cs:[0x4b53e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936676) /* 0x4b53e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474c3e  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00474c41  0f84ff010000           -je 0x474e46
    if (cpu.flags.zf)
    {
        goto L_0x00474e46;
    }
    // 00474c47  e86ca30000             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00474c4c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00474c51  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00474c53  68305c4700             -push 0x475c30
    app->getMemory<x86::reg32>(cpu.esp-4) = 4676656 /*0x475c30*/;
    cpu.esp -= 4;
    // 00474c58  a388ae5100             -mov dword ptr [0x51ae88], eax
    app->getMemory<x86::reg32>(x86::reg32(5353096) /* 0x51ae88 */) = cpu.eax;
    // 00474c5d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00474c5f  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00474c61  890d90ae5100           -mov dword ptr [0x51ae90], ecx
    app->getMemory<x86::reg32>(x86::reg32(5353104) /* 0x51ae90 */) = cpu.ecx;
    // 00474c67  893584ae5100           -mov dword ptr [0x51ae84], esi
    app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */) = cpu.esi;
    // 00474c6d  89358cae5100           -mov dword ptr [0x51ae8c], esi
    app->getMemory<x86::reg32>(x86::reg32(5353100) /* 0x51ae8c */) = cpu.esi;
    // 00474c73  8815a0ae5100           -mov byte ptr [0x51aea0], dl
    app->getMemory<x86::reg8>(x86::reg32(5353120) /* 0x51aea0 */) = cpu.dl;
    // 00474c79  e8e2140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474c7e  68b05b4700             -push 0x475bb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4676528 /*0x475bb0*/;
    cpu.esp -= 4;
    // 00474c83  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 00474c85  e8d6140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474c8a  68505b4700             -push 0x475b50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4676432 /*0x475b50*/;
    cpu.esp -= 4;
    // 00474c8f  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00474c91  e8ca140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474c96  6830594700             -push 0x475930
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675888 /*0x475930*/;
    cpu.esp -= 4;
    // 00474c9b  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00474c9d  e8be140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474ca2  6830594700             -push 0x475930
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675888 /*0x475930*/;
    cpu.esp -= 4;
    // 00474ca7  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00474ca9  e8b2140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474cae  68105b4700             -push 0x475b10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4676368 /*0x475b10*/;
    cpu.esp -= 4;
    // 00474cb3  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00474cb5  e8a6140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474cba  68a05a4700             -push 0x475aa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4676256 /*0x475aa0*/;
    cpu.esp -= 4;
    // 00474cbf  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00474cc1  e89a140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474cc6  68d0554700             -push 0x4755d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675024 /*0x4755d0*/;
    cpu.esp -= 4;
    // 00474ccb  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 00474ccd  e88e140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474cd2  6890554700             -push 0x475590
    app->getMemory<x86::reg32>(cpu.esp-4) = 4674960 /*0x475590*/;
    cpu.esp -= 4;
    // 00474cd7  6885000000             -push 0x85
    app->getMemory<x86::reg32>(cpu.esp-4) = 133 /*0x85*/;
    cpu.esp -= 4;
    // 00474cdc  e87f140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474ce1  68b0594700             -push 0x4759b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4676016 /*0x4759b0*/;
    cpu.esp -= 4;
    // 00474ce6  6a1a                   -push 0x1a
    app->getMemory<x86::reg32>(cpu.esp-4) = 26 /*0x1a*/;
    cpu.esp -= 4;
    // 00474ce8  e873140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474ced  68605a4700             -push 0x475a60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4676192 /*0x475a60*/;
    cpu.esp -= 4;
    // 00474cf2  6812010000             -push 0x112
    app->getMemory<x86::reg32>(cpu.esp-4) = 274 /*0x112*/;
    cpu.esp -= 4;
    // 00474cf7  e864140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474cfc  68d05a4700             -push 0x475ad0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4676304 /*0x475ad0*/;
    cpu.esp -= 4;
    // 00474d01  6866040000             -push 0x466
    app->getMemory<x86::reg32>(cpu.esp-4) = 1126 /*0x466*/;
    cpu.esp -= 4;
    // 00474d06  e855140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d0b  68c0584700             -push 0x4758c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675776 /*0x4758c0*/;
    cpu.esp -= 4;
    // 00474d10  6802010000             -push 0x102
    app->getMemory<x86::reg32>(cpu.esp-4) = 258 /*0x102*/;
    cpu.esp -= 4;
    // 00474d15  e846140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d1a  68a0574700             -push 0x4757a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675488 /*0x4757a0*/;
    cpu.esp -= 4;
    // 00474d1f  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00474d24  e837140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d29  68a0574700             -push 0x4757a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675488 /*0x4757a0*/;
    cpu.esp -= 4;
    // 00474d2e  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00474d33  e828140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d38  6850574700             -push 0x475750
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675408 /*0x475750*/;
    cpu.esp -= 4;
    // 00474d3d  6801010000             -push 0x101
    app->getMemory<x86::reg32>(cpu.esp-4) = 257 /*0x101*/;
    cpu.esp -= 4;
    // 00474d42  e819140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d47  6850574700             -push 0x475750
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675408 /*0x475750*/;
    cpu.esp -= 4;
    // 00474d4c  6805010000             -push 0x105
    app->getMemory<x86::reg32>(cpu.esp-4) = 261 /*0x105*/;
    cpu.esp -= 4;
    // 00474d51  e80a140000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d56  68e0564700             -push 0x4756e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675296 /*0x4756e0*/;
    cpu.esp -= 4;
    // 00474d5b  6801020000             -push 0x201
    app->getMemory<x86::reg32>(cpu.esp-4) = 513 /*0x201*/;
    cpu.esp -= 4;
    // 00474d60  e8fb130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d65  68e0564700             -push 0x4756e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675296 /*0x4756e0*/;
    cpu.esp -= 4;
    // 00474d6a  6807020000             -push 0x207
    app->getMemory<x86::reg32>(cpu.esp-4) = 519 /*0x207*/;
    cpu.esp -= 4;
    // 00474d6f  e8ec130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d74  68e0564700             -push 0x4756e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675296 /*0x4756e0*/;
    cpu.esp -= 4;
    // 00474d79  6804020000             -push 0x204
    app->getMemory<x86::reg32>(cpu.esp-4) = 516 /*0x204*/;
    cpu.esp -= 4;
    // 00474d7e  e8dd130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d83  68e0564700             -push 0x4756e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675296 /*0x4756e0*/;
    cpu.esp -= 4;
    // 00474d88  6803020000             -push 0x203
    app->getMemory<x86::reg32>(cpu.esp-4) = 515 /*0x203*/;
    cpu.esp -= 4;
    // 00474d8d  e8ce130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474d92  68e0564700             -push 0x4756e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675296 /*0x4756e0*/;
    cpu.esp -= 4;
    // 00474d97  6809020000             -push 0x209
    app->getMemory<x86::reg32>(cpu.esp-4) = 521 /*0x209*/;
    cpu.esp -= 4;
    // 00474d9c  e8bf130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474da1  68e0564700             -push 0x4756e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675296 /*0x4756e0*/;
    cpu.esp -= 4;
    // 00474da6  6806020000             -push 0x206
    app->getMemory<x86::reg32>(cpu.esp-4) = 518 /*0x206*/;
    cpu.esp -= 4;
    // 00474dab  e8b0130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474db0  6870564700             -push 0x475670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675184 /*0x475670*/;
    cpu.esp -= 4;
    // 00474db5  6802020000             -push 0x202
    app->getMemory<x86::reg32>(cpu.esp-4) = 514 /*0x202*/;
    cpu.esp -= 4;
    // 00474dba  e8a1130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474dbf  6870564700             -push 0x475670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675184 /*0x475670*/;
    cpu.esp -= 4;
    // 00474dc4  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 00474dc9  e892130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474dce  6870564700             -push 0x475670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675184 /*0x475670*/;
    cpu.esp -= 4;
    // 00474dd3  6805020000             -push 0x205
    app->getMemory<x86::reg32>(cpu.esp-4) = 517 /*0x205*/;
    cpu.esp -= 4;
    // 00474dd8  e883130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00474ddd  6870564700             -push 0x475670
    app->getMemory<x86::reg32>(cpu.esp-4) = 4675184 /*0x475670*/;
    cpu.esp -= 4;
    // 00474de2  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00474de7  e874130000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
L_0x00474dec:
    // 00474dec  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00474df1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00474df6  881d8db55100           -mov byte ptr [0x51b58d], bl
    app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */) = cpu.bl;
    // 00474dfc  a3a4b55100             -mov dword ptr [0x51b5a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5354916) /* 0x51b5a4 */) = cpu.eax;
    // 00474e01  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00474e05  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474e07  a348b15100             -mov dword ptr [0x51b148], eax
    app->getMemory<x86::reg32>(x86::reg32(5353800) /* 0x51b148 */) = cpu.eax;
    // 00474e0c  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00474e10  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00474e15  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474e16  b8904f4700             -mov eax, 0x474f90
    cpu.eax = 4673424 /*0x474f90*/;
    // 00474e1b  892d44b15100           -mov dword ptr [0x51b144], ebp
    app->getMemory<x86::reg32>(x86::reg32(5353796) /* 0x51b144 */) = cpu.ebp;
    // 00474e21  e87a9d0000             -call 0x47eba0
    cpu.esp -= 4;
    sub_47eba0(app, cpu);
    if (cpu.terminate) return;
    // 00474e26  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00474e28  7449                   -je 0x474e73
    if (cpu.flags.zf)
    {
        goto L_0x00474e73;
    }
    // 00474e2a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00474e2c:
    // 00474e2c  8b1d7c814c00           -mov ebx, dword ptr [0x4c817c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013884) /* 0x4c817c */);
    // 00474e32  39da                   +cmp edx, ebx
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
    // 00474e34  7571                   -jne 0x474ea7
    if (!cpu.flags.zf)
    {
        goto L_0x00474ea7;
    }
    // 00474e36  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00474e38  e843320000             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00474e3d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00474e3f  e8189e0000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00474e44  ebe6                   -jmp 0x474e2c
    goto L_0x00474e2c;
L_0x00474e46:
    // 00474e46  ba74db4b00             -mov edx, 0x4bdb74
    cpu.edx = 4971380 /*0x4bdb74*/;
    // 00474e4b  b950030000             -mov ecx, 0x350
    cpu.ecx = 848 /*0x350*/;
    // 00474e50  89158c844c00           -mov dword ptr [0x4c848c], edx
    app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 00474e56  890d90844c00           -mov dword ptr [0x4c8490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 00474e5c  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474e63  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00474e64  6894db4b00             -push 0x4bdb94
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971412 /*0x4bdb94*/;
    cpu.esp -= 4;
    // 00474e69  e852340000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00474e6e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00474e71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00474e73:
    // 00474e73  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00474e76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474e7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474e7b:
    // 00474e7b  833d84b5510000         +cmp dword ptr [0x51b584], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474e82  0f8464ffffff           -je 0x474dec
    if (cpu.flags.zf)
    {
        goto L_0x00474dec;
    }
    // 00474e88  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00474e8a  a08db55100             -mov al, byte ptr [0x51b58d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
    // 00474e8f  39c3                   +cmp ebx, eax
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
    // 00474e91  0f8455ffffff           -je 0x474dec
    if (cpu.flags.zf)
    {
        goto L_0x00474dec;
    }
    // 00474e97  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00474e99  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00474e9b  e800fbffff             -call 0x4749a0
    cpu.esp -= 4;
    sub_4749a0(app, cpu);
    if (cpu.terminate) return;
    // 00474ea0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00474ea5  ebcc                   -jmp 0x474e73
    goto L_0x00474e73;
L_0x00474ea7:
    // 00474ea7  833d84b5510000         +cmp dword ptr [0x51b584], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474eae  7405                   -je 0x474eb5
    if (cpu.flags.zf)
    {
        goto L_0x00474eb5;
    }
    // 00474eb0  e8fbfbffff             -call 0x474ab0
    cpu.esp -= 4;
    sub_474ab0(app, cpu);
    if (cpu.terminate) return;
L_0x00474eb5:
    // 00474eb5  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00474eb9  8b157c814c00           -mov edx, dword ptr [0x4c817c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013884) /* 0x4c817c */);
    // 00474ebf  e81ca00000             -call 0x47eee0
    cpu.esp -= 4;
    sub_47eee0(app, cpu);
    if (cpu.terminate) return;
    // 00474ec4  833d7c814c0000         +cmp dword ptr [0x4c817c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013884) /* 0x4c817c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474ecb  741b                   -je 0x474ee8
    if (cpu.flags.zf)
    {
        goto L_0x00474ee8;
    }
    // 00474ecd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00474ecf:
    // 00474ecf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474ed1  e8869d0000             -call 0x47ec5c
    cpu.esp -= 4;
    sub_47ec5c(app, cpu);
    if (cpu.terminate) return;
    // 00474ed6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00474ed8  e8a3310000             -call 0x478080
    cpu.esp -= 4;
    sub_478080(app, cpu);
    if (cpu.terminate) return;
    // 00474edd  3b157c814c00           +cmp edx, dword ptr [0x4c817c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5013884) /* 0x4c817c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474ee3  75ea                   -jne 0x474ecf
    if (!cpu.flags.zf)
    {
        goto L_0x00474ecf;
    }
    // 00474ee5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00474ee8:
    // 00474ee8  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00474eec  bf70ae5100             -mov edi, 0x51ae70
    cpu.edi = 5353072 /*0x51ae70*/;
    // 00474ef1  8a358db55100           -mov dh, byte ptr [0x51b58d]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
    // 00474ef7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474ef8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474ef9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474efa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474efb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00474efc  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00474efe  7461                   -je 0x474f61
    if (cpu.flags.zf)
    {
        goto L_0x00474f61;
    }
    // 00474f00  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474f02  6884814c00             -push 0x4c8184
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013892 /*0x4c8184*/;
    cpu.esp -= 4;
    // 00474f07  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474f09  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00474f0b  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474f12  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474f14  6888814c00             -push 0x4c8188
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013896 /*0x4c8188*/;
    cpu.esp -= 4;
    // 00474f19  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474f1b  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 00474f1d  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474f24  833d84814c0000         +cmp dword ptr [0x4c8184], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013892) /* 0x4c8184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474f2b  740f                   -je 0x474f3c
    if (cpu.flags.zf)
    {
        goto L_0x00474f3c;
    }
    // 00474f2d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00474f2f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474f31  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474f33  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00474f35  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00474f3c:
    // 00474f3c  833d88814c0000         +cmp dword ptr [0x4c8188], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013896) /* 0x4c8188 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00474f43  740f                   -je 0x474f54
    if (cpu.flags.zf)
    {
        goto L_0x00474f54;
    }
    // 00474f45  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00474f47  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474f49  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00474f4b  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 00474f4d  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00474f54:
    // 00474f54  a184b55100             -mov eax, dword ptr [0x51b584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00474f59  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00474f5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474f5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474f5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474f5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474f60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00474f61:
    // 00474f61  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00474f65  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00474f67  e834faffff             -call 0x4749a0
    cpu.esp -= 4;
    sub_4749a0(app, cpu);
    if (cpu.terminate) return;
    // 00474f6c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474f6e  891584814c00           -mov dword ptr [0x4c8184], edx
    app->getMemory<x86::reg32>(x86::reg32(5013892) /* 0x4c8184 */) = cpu.edx;
    // 00474f74  891588814c00           -mov dword ptr [0x4c8188], edx
    app->getMemory<x86::reg32>(x86::reg32(5013896) /* 0x4c8188 */) = cpu.edx;
    // 00474f7a  a184b55100             -mov eax, dword ptr [0x51b584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 00474f7f  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00474f82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474f83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474f84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474f85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00474f86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_474f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00474f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474f91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00474f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00474f93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00474f94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00474f95  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00474f98  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00474f9d  e8fe010000             -call 0x4751a0
    cpu.esp -= 4;
    sub_4751a0(app, cpu);
    if (cpu.terminate) return;
    // 00474fa2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00474fa4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00474fa6  e8219f0000             -call 0x47eecc
    cpu.esp -= 4;
    sub_47eecc(app, cpu);
    if (cpu.terminate) return;
    // 00474fab  a37c814c00             -mov dword ptr [0x4c817c], eax
    app->getMemory<x86::reg32>(x86::reg32(5013884) /* 0x4c817c */) = cpu.eax;
    // 00474fb0  e8679f0000             -call 0x47ef1c
    cpu.esp -= 4;
    sub_47ef1c(app, cpu);
    if (cpu.terminate) return;
    // 00474fb5  a17c814c00             -mov eax, dword ptr [0x4c817c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013884) /* 0x4c817c */);
    // 00474fba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00474fbc  e8e79f0000             -call 0x47efa8
    cpu.esp -= 4;
    sub_47efa8(app, cpu);
    if (cpu.terminate) return;
    // 00474fc1  8a258db55100           -mov ah, byte ptr [0x51b58d]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5354893) /* 0x51b58d */);
    // 00474fc7  891d84b55100           -mov dword ptr [0x51b584], ebx
    app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */) = cpu.ebx;
    // 00474fcd  891580814c00           -mov dword ptr [0x4c8180], edx
    app->getMemory<x86::reg32>(x86::reg32(5013888) /* 0x4c8180 */) = cpu.edx;
    // 00474fd3  89157c814c00           -mov dword ptr [0x4c817c], edx
    app->getMemory<x86::reg32>(x86::reg32(5013884) /* 0x4c817c */) = cpu.edx;
    // 00474fd9  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00474fdb  0f845a010000           -je 0x47513b
    if (cpu.flags.zf)
    {
        goto L_0x0047513b;
    }
    // 00474fe1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00474fe2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00474fe4  2eff15f8534b00         -call dword ptr cs:[0x4b53f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936696) /* 0x4b53f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00474feb  891d94b55100           -mov dword ptr [0x51b594], ebx
    app->getMemory<x86::reg32>(x86::reg32(5354900) /* 0x51b594 */) = cpu.ebx;
    // 00474ff1  891d98b55100           -mov dword ptr [0x51b598], ebx
    app->getMemory<x86::reg32>(x86::reg32(5354904) /* 0x51b598 */) = cpu.ebx;
L_0x00474ff7:
    // 00474ff7  68b0da4b00             -push 0x4bdab0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971184 /*0x4bdab0*/;
    cpu.esp -= 4;
    // 00474ffc  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00474ffe  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475003  e868580100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475008  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047500b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047500c  2eff15ec534b00         -call dword ptr cs:[0x4b53ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936684) /* 0x4b53ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475013  3b3584b55100           +cmp esi, dword ptr [0x51b584]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475019  0f85ff000000           -jne 0x47511e
    if (!cpu.flags.zf)
    {
        goto L_0x0047511e;
    }
L_0x0047501f:
    // 0047501f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475021  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475023  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475025  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475029  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047502a  2eff15c4534b00         -call dword ptr cs:[0x4b53c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936644) /* 0x4b53c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475031  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475033  0f8433010000           -je 0x47516c
    if (cpu.flags.zf)
    {
        goto L_0x0047516c;
    }
    // 00475039  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0047503e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047503f  68d0da4b00             -push 0x4bdad0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971216 /*0x4bdad0*/;
    cpu.esp -= 4;
    // 00475044  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 00475046  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 0047504b  e820580100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475050  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475053  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00475058  e8ab9f0000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047505d  833d98ae510000         +cmp dword ptr [0x51ae98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353112) /* 0x51ae98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475064  751b                   -jne 0x475081
    if (!cpu.flags.zf)
    {
        goto L_0x00475081;
    }
    // 00475066  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047506a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047506e  e8fd0b0000             -call 0x475c70
    cpu.esp -= 4;
    sub_475c70(app, cpu);
    if (cpu.terminate) return;
    // 00475073  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475075  750a                   -jne 0x475081
    if (!cpu.flags.zf)
    {
        goto L_0x00475081;
    }
    // 00475077  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00475079  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047507a  2eff1510544b00         -call dword ptr cs:[0x4b5410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936720) /* 0x4b5410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00475081:
    // 00475081  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00475083  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475084  2eff15a8534b00         -call dword ptr cs:[0x4b53a8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936616) /* 0x4b53a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047508b  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00475090  e88b9f0000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00475095  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 0047509a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047509b  68e0da4b00             -push 0x4bdae0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971232 /*0x4bdae0*/;
    cpu.esp -= 4;
    // 004750a0  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 004750a2  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004750a7  e8c4570100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004750ac  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004750af:
    // 004750af  833d80814c0000         +cmp dword ptr [0x4c8180], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013888) /* 0x4c8180 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004750b6  745a                   -je 0x475112
    if (cpu.flags.zf)
    {
        goto L_0x00475112;
    }
    // 004750b8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004750ba  8b3d30b15100           -mov edi, dword ptr [0x51b130]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5353776) /* 0x51b130 */);
    // 004750c0  891d80814c00           -mov dword ptr [0x4c8180], ebx
    app->getMemory<x86::reg32>(x86::reg32(5013888) /* 0x4c8180 */) = cpu.ebx;
    // 004750c6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004750c8  7427                   -je 0x4750f1
    if (cpu.flags.zf)
    {
        goto L_0x004750f1;
    }
    // 004750ca  833d40b1510000         +cmp dword ptr [0x51b140], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353792) /* 0x51b140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004750d1  741e                   -je 0x4750f1
    if (cpu.flags.zf)
    {
        goto L_0x004750f1;
    }
    // 004750d3  6808db4b00             -push 0x4bdb08
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971272 /*0x4bdb08*/;
    cpu.esp -= 4;
    // 004750d8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004750da  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004750df  e88c570100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004750e4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004750e7  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 004750ec  e803e40000             -call 0x4834f4
    cpu.esp -= 4;
    sub_4834f4(app, cpu);
    if (cpu.terminate) return;
L_0x004750f1:
    // 004750f1  6824db4b00             -push 0x4bdb24
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971300 /*0x4bdb24*/;
    cpu.esp -= 4;
    // 004750f6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004750f8  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004750fd  e86e570100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475102  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475105  a184b55100             -mov eax, dword ptr [0x51b584]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 0047510a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047510b  2eff15a4534b00         -call dword ptr cs:[0x4b53a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936612) /* 0x4b53a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00475112:
    // 00475112  3b3584b55100           +cmp esi, dword ptr [0x51b584]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475118  0f8401ffffff           -je 0x47501f
    if (cpu.flags.zf)
    {
        goto L_0x0047501f;
    }
L_0x0047511e:
    // 0047511e  6834db4b00             -push 0x4bdb34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971316 /*0x4bdb34*/;
    cpu.esp -= 4;
    // 00475123  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00475125  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 0047512a  e841570100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 0047512f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475132  83c42c                 +add esp, 0x2c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00475135  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475136  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475137  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475138  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475139  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047513a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047513b:
    // 0047513b  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047513f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475141  2eff15b8534b00         -call dword ptr cs:[0x4b53b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936632) /* 0x4b53b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475148  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047514c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047514d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047514e  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475155  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00475159  a394b55100             -mov dword ptr [0x51b594], eax
    app->getMemory<x86::reg32>(x86::reg32(5354900) /* 0x51b594 */) = cpu.eax;
    // 0047515e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00475162  a398b55100             -mov dword ptr [0x51b598], eax
    app->getMemory<x86::reg32>(x86::reg32(5354904) /* 0x51b598 */) = cpu.eax;
    // 00475167  e98bfeffff             -jmp 0x474ff7
    goto L_0x00474ff7;
L_0x0047516c:
    // 0047516c  68f0da4b00             -push 0x4bdaf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971248 /*0x4bdaf0*/;
    cpu.esp -= 4;
    // 00475171  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475173  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475178  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 0047517d  e8ee560100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475182  83c40c                 +add esp, 0xc
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
    // 00475185  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047518a  b890604700             -mov eax, 0x476090
    cpu.eax = 4677776 /*0x476090*/;
    // 0047518f  e80c2e0000             -call 0x477fa0
    cpu.esp -= 4;
    sub_477fa0(app, cpu);
    if (cpu.terminate) return;
    // 00475194  e916ffffff             -jmp 0x4750af
    goto L_0x004750af;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4751a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004751a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004751a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004751a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004751a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004751a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004751a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004751a6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004751a9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004751ab  8aa05d040000           -mov ah, byte ptr [eax + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
    // 004751b1  8b359c814c00           -mov esi, dword ptr [0x4c819c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5013916) /* 0x4c819c */);
    // 004751b7  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004751b9  0f8503010000           -jne 0x4752c2
    if (!cpu.flags.zf)
    {
        goto L_0x004752c2;
    }
    // 004751bf  8a15f0814c00           -mov dl, byte ptr [0x4c81f0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5014000) /* 0x4c81f0 */);
    // 004751c5  81ce0000ca00           -or esi, 0xca0000
    cpu.esi |= x86::reg32(x86::sreg32(13238272 /*0xca0000*/));
    // 004751cb  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 004751ce  0f8428010000           -je 0x4752fc
    if (cpu.flags.zf)
    {
        goto L_0x004752fc;
    }
    // 004751d4  81ce00000500           -or esi, 0x50000
    cpu.esi |= x86::reg32(x86::sreg32(327680 /*0x50000*/));
L_0x004751da:
    // 004751da  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004751e1  0f8420010000           -je 0x475307
    if (cpu.flags.zf)
    {
        goto L_0x00475307;
    }
    // 004751e7  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 004751ed  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004751f1  8b8364040000           -mov eax, dword ptr [ebx + 0x464]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 004751f7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004751fa:
    // 004751fa  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004751fe  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00475201  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00475203  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00475207  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047520a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0047520d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047520f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00475211  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475212  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00475216  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047521a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047521b  2eff1584534b00         -call dword ptr cs:[0x4b5384]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936580) /* 0x4b5384 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475222  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00475225  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0047522b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047522f  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 00475235  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475239  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047523c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00475240  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475242  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00475244  b900000400             -mov ecx, 0x40000
    cpu.ecx = 262144 /*0x40000*/;
L_0x00475249:
    // 00475249  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047524a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047524b  8b8368040000           -mov eax, dword ptr [ebx + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 00475251  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475252  8bab64040000           -mov ebp, dword ptr [ebx + 0x464]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 00475258  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475259  6864da4b00             -push 0x4bda64
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971108 /*0x4bda64*/;
    cpu.esp -= 4;
    // 0047525e  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00475260  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475265  e806560100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 0047526a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047526d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047526f  a1a0b55100             -mov eax, dword ptr [0x51b5a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5354912) /* 0x51b5a0 */);
    // 00475274  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475275  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475277  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475279  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047527a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047527b  8b9368040000           -mov edx, dword ptr [ebx + 0x468]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
    // 00475281  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475282  8bbb64040000           -mov edi, dword ptr [ebx + 0x464]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
    // 00475288  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475289  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047528a  8b2dac814c00           -mov ebp, dword ptr [0x4c81ac]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5013932) /* 0x4c81ac */);
    // 00475290  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475291  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475292  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475293  2eff159c534b00         -call dword ptr cs:[0x4b539c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936604) /* 0x4b539c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047529a  6894da4b00             -push 0x4bda94
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971156 /*0x4bda94*/;
    cpu.esp -= 4;
    // 0047529f  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 004752a1  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004752a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004752a8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004752aa  e8c1550100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004752af  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004752b2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004752b4  7562                   -jne 0x475318
    if (!cpu.flags.zf)
    {
        goto L_0x00475318;
    }
L_0x004752b6:
    // 004752b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004752b8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004752bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004752c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004752c2:
    // 004752c2  c7836404000000000000   -mov dword ptr [ebx + 0x464], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = 0 /*0x0*/;
    // 004752cc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004752ce  c7836804000000000000   -mov dword ptr [ebx + 0x468], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = 0 /*0x0*/;
    // 004752d8  2eff15c8534b00         -call dword ptr cs:[0x4b53c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936648) /* 0x4b53c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004752df  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004752e1  81ce00000080           +or esi, 0x80000000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/))));
    // 004752e7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004752e9  2eff15c8534b00         -call dword ptr cs:[0x4b53c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936648) /* 0x4b53c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004752f0  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004752f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004752f7  e94dffffff             -jmp 0x475249
    goto L_0x00475249;
L_0x004752fc:
    // 004752fc  81ce00008000           +or esi, 0x800000
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(8388608 /*0x800000*/))));
    // 00475302  e9d3feffff             -jmp 0x4751da
    goto L_0x004751da;
L_0x00475307:
    // 00475307  b900e0ffff             -mov ecx, 0xffffe000
    cpu.ecx = 4294959104 /*0xffffe000*/;
    // 0047530c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0047530f  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00475313  e9e2feffff             -jmp 0x4751fa
    goto L_0x004751fa;
L_0x00475318:
    // 00475318  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047531a  2eff15f0534b00         -call dword ptr cs:[0x4b53f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936688) /* 0x4b53f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475321  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00475328  7409                   -je 0x475333
    if (cpu.flags.zf)
    {
        goto L_0x00475333;
    }
    // 0047532a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047532c  2eff1504544b00         -call dword ptr cs:[0x4b5404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936708) /* 0x4b5404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00475333:
    // 00475333  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475335  8b0da8814c00           -mov ecx, dword ptr [0x4c81a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013928) /* 0x4c81a8 */);
    // 0047533b  891580854c00           -mov dword ptr [0x4c8580], edx
    app->getMemory<x86::reg32>(x86::reg32(5014912) /* 0x4c8580 */) = cpu.edx;
    // 00475341  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475343  0f856dffffff           -jne 0x4752b6
    if (!cpu.flags.zf)
    {
        goto L_0x004752b6;
    }
    // 00475349  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047534b  e800c80100             -call 0x491b50
    cpu.esp -= 4;
    sub_491b50(app, cpu);
    if (cpu.terminate) return;
    // 00475350  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00475355  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475357  e8f4c70100             -call 0x491b50
    cpu.esp -= 4;
    sub_491b50(app, cpu);
    if (cpu.terminate) return;
    // 0047535c  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00475361  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475363  e8e8c70100             -call 0x491b50
    cpu.esp -= 4;
    sub_491b50(app, cpu);
    if (cpu.terminate) return;
    // 00475368  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047536a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047536d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047536e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047536f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475370  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475371  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475372  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475373  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475381  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475382  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475383  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475384  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475388  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047538c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047538e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475390  754b                   -jne 0x4753dd
    if (!cpu.flags.zf)
    {
        goto L_0x004753dd;
    }
    // 00475392  833d8c814c0000         +cmp dword ptr [0x4c818c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013900) /* 0x4c818c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475399  7442                   -je 0x4753dd
    if (cpu.flags.zf)
    {
        goto L_0x004753dd;
    }
    // 0047539b  833da4b5510000         +cmp dword ptr [0x51b5a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354916) /* 0x51b5a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004753a2  7439                   -je 0x4753dd
    if (cpu.flags.zf)
    {
        goto L_0x004753dd;
    }
    // 004753a4  833d94814c0000         +cmp dword ptr [0x4c8194], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013908) /* 0x4c8194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004753ab  744f                   -je 0x4753fc
    if (cpu.flags.zf)
    {
        goto L_0x004753fc;
    }
    // 004753ad  f644241f20             +test byte ptr [esp + 0x1f], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(31) /* 0x1f */) & 32 /*0x20*/));
    // 004753b2  7448                   -je 0x4753fc
    if (cpu.flags.zf)
    {
        goto L_0x004753fc;
    }
    // 004753b4  bd38000000             -mov ebp, 0x38
    cpu.ebp = 56 /*0x38*/;
    // 004753b9  83fe09                 +cmp esi, 9
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004753bc  7530                   -jne 0x4753ee
    if (!cpu.flags.zf)
    {
        goto L_0x004753ee;
    }
    // 004753be  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004753c3  bf0f000000             -mov edi, 0xf
    cpu.edi = 15 /*0xf*/;
L_0x004753c8:
    // 004753c8  833d98814c0000         +cmp dword ptr [0x4c8198], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013912) /* 0x4c8198 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004753cf  740c                   -je 0x4753dd
    if (cpu.flags.zf)
    {
        goto L_0x004753dd;
    }
    // 004753d1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004753d3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004753d5  ff1598814c00           -call dword ptr [0x4c8198]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5013912) /* 0x4c8198 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004753db  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004753dd:
    // 004753dd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004753df  0f846b000000           -je 0x475450
    if (cpu.flags.zf)
    {
        goto L_0x00475450;
    }
    // 004753e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004753e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004753eb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004753ee:
    // 004753ee  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004753f1  7536                   -jne 0x475429
    if (!cpu.flags.zf)
    {
        goto L_0x00475429;
    }
    // 004753f3  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004753f8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004753fa  ebcc                   -jmp 0x4753c8
    goto L_0x004753c8;
L_0x004753fc:
    // 004753fc  83fe5b                 +cmp esi, 0x5b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004753ff  750b                   -jne 0x47540c
    if (!cpu.flags.zf)
    {
        goto L_0x0047540c;
    }
L_0x00475401:
    // 00475401  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00475406  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00475408  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0047540a  ebbc                   -jmp 0x4753c8
    goto L_0x004753c8;
L_0x0047540c:
    // 0047540c  83fe5c                 +cmp esi, 0x5c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(92 /*0x5c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047540f  74f0                   -je 0x475401
    if (cpu.flags.zf)
    {
        goto L_0x00475401;
    }
    // 00475411  83fe5d                 +cmp esi, 0x5d
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475414  74eb                   -je 0x475401
    if (cpu.flags.zf)
    {
        goto L_0x00475401;
    }
    // 00475416  83fe2c                 +cmp esi, 0x2c
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(44 /*0x2c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475419  74e6                   -je 0x475401
    if (cpu.flags.zf)
    {
        goto L_0x00475401;
    }
    // 0047541b  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047541d  2eff15b4534b00         -call dword ptr cs:[0x4b53b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936628) /* 0x4b53b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475424  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00475427  7c11                   -jl 0x47543a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047543a;
    }
L_0x00475429:
    // 00475429  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047542b  759b                   -jne 0x4753c8
    if (!cpu.flags.zf)
    {
        goto L_0x004753c8;
    }
    // 0047542d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047542f  741f                   -je 0x475450
    if (cpu.flags.zf)
    {
        goto L_0x00475450;
    }
    // 00475431  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475433  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475434  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475435  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475436  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475437  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047543a:
    // 0047543a  bd1d000000             -mov ebp, 0x1d
    cpu.ebp = 29 /*0x1d*/;
    // 0047543f  83fe1b                 +cmp esi, 0x1b
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(27 /*0x1b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475442  75e5                   -jne 0x475429
    if (!cpu.flags.zf)
    {
        goto L_0x00475429;
    }
    // 00475444  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00475449  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047544b  e978ffffff             -jmp 0x4753c8
    goto L_0x004753c8;
L_0x00475450:
    // 00475450  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00475454  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475455  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475456  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047545a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047545b  8b3d90814c00           -mov edi, dword ptr [0x4c8190]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5013904) /* 0x4c8190 */);
    // 00475461  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475462  2eff158c534b00         -call dword ptr cs:[0x4b538c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936588) /* 0x4b538c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475469  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047546b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047546d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047546e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047546f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475470  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475471  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475480  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475481  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475482  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475483  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00475484  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00475486  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475489  8b7518                 -mov esi, dword ptr [ebp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0047548c  b930b15100             -mov ecx, 0x51b130
    cpu.ecx = 5353776 /*0x51b130*/;
    // 00475491  68c0624700             -push 0x4762c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4678336 /*0x4762c0*/;
    cpu.esp -= 4;
    // 00475496  ba70aa5100             -mov edx, 0x51aa70
    cpu.edx = 5352048 /*0x51aa70*/;
    // 0047549b  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0047549e  8b1d78814c00           -mov ebx, dword ptr [0x4c8178]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013880) /* 0x4c8178 */);
    // 004754a4  8975f0                 -mov dword ptr [ebp - 0x10], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.esi;
    // 004754a7  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004754a9  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004754ac  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004754b1  897df8                 -mov dword ptr [ebp - 8], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edi;
    // 004754b4  e828be0100             -call 0x4912e1
    cpu.esp -= 4;
    sub_4912e1(app, cpu);
    if (cpu.terminate) return;
    // 004754b9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004754bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004754bd  0f8486000000           -je 0x475549
    if (cpu.flags.zf)
    {
        goto L_0x00475549;
    }
    // 004754c3  b83d000000             -mov eax, 0x3d
    cpu.eax = 61 /*0x3d*/;
L_0x004754c8:
    // 004754c8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004754c9  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004754cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004754cd  8b551c                 -mov edx, dword ptr [ebp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004754d0  8b4d14                 -mov ecx, dword ptr [ebp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004754d3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004754d4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004754d6  0f8477000000           -je 0x475553
    if (cpu.flags.zf)
    {
        goto L_0x00475553;
    }
    // 004754dc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004754e1:
    // 004754e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004754e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004754e3  6844da4b00             -push 0x4bda44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971076 /*0x4bda44*/;
    cpu.esp -= 4;
    // 004754e8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004754ea  746b                   -je 0x475557
    if (cpu.flags.zf)
    {
        goto L_0x00475557;
    }
    // 004754ec  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x004754f1:
    // 004754f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004754f2  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004754f7  e874530100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004754fc  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004754ff  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00475501  741a                   -je 0x47551d
    if (cpu.flags.zf)
    {
        goto L_0x0047551d;
    }
    // 00475503  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00475506  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475507  8b7d20                 -mov edi, dword ptr [ebp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047550a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047550b  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047550e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047550f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475510  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00475513  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475514  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00475517  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475518  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047551b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047551d:
    // 0047551d  6860da4b00             -push 0x4bda60
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971104 /*0x4bda60*/;
    cpu.esp -= 4;
    // 00475522  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00475524  7438                   -je 0x47555e
    if (cpu.flags.zf)
    {
        goto L_0x0047555e;
    }
    // 00475526  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0047552b:
    // 0047552b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047552c  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475531  e83a530100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475536  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475539  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047553b  7428                   -je 0x475565
    if (cpu.flags.zf)
    {
        goto L_0x00475565;
    }
    // 0047553d  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00475540  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00475542  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475543  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475544  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475545  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475546  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00475549:
    // 00475549  b83b000000             -mov eax, 0x3b
    cpu.eax = 59 /*0x3b*/;
    // 0047554e  e975ffffff             -jmp 0x4754c8
    goto L_0x004754c8;
L_0x00475553:
    // 00475553  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00475555  eb8a                   -jmp 0x4754e1
    goto L_0x004754e1;
L_0x00475557:
    // 00475557  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0047555c  eb93                   -jmp 0x4754f1
    goto L_0x004754f1;
L_0x0047555e:
    // 0047555e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00475563  ebc6                   -jmp 0x47552b
    goto L_0x0047552b;
L_0x00475565:
    // 00475565  8b5d20                 -mov ebx, dword ptr [ebp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00475568  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475569  8b7d1c                 -mov edi, dword ptr [ebp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047556c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047556d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047556e  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00475571  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475572  2eff15a0534b00         -call dword ptr cs:[0x4b53a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936608) /* 0x4b53a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475579  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0047557b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047557c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047557d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047557e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047557f  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475590  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475594  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475596  741d                   -je 0x4755b5
    if (cpu.flags.zf)
    {
        goto L_0x004755b5;
    }
    // 00475598  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047559c  3b9054040000           +cmp edx, dword ptr [eax + 0x454]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004755a2  7511                   -jne 0x4755b5
    if (!cpu.flags.zf)
    {
        goto L_0x004755b5;
    }
    // 004755a4  80b85d04000000         +cmp byte ptr [eax + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004755ab  7408                   -je 0x4755b5
    if (cpu.flags.zf)
    {
        goto L_0x004755b5;
    }
    // 004755ad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004755b2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004755b5:
    // 004755b5  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 004755ba  e8499a0000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004755bf  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 004755c4  e8579a0000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004755c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004755cb  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4755d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004755d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004755d1  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004755d4  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004755d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004755da  7409                   -je 0x4755e5
    if (cpu.flags.zf)
    {
        goto L_0x004755e5;
    }
    // 004755dc  83bb5404000000         +cmp dword ptr [ebx + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004755e3  750c                   -jne 0x4755f1
    if (!cpu.flags.zf)
    {
        goto L_0x004755f1;
    }
L_0x004755e5:
    // 004755e5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004755ea  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004755ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004755ee  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004755f1:
    // 004755f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004755f2  6838da4b00             -push 0x4bda38
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971064 /*0x4bda38*/;
    cpu.esp -= 4;
    // 004755f7  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004755f9  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004755fe  e86d520100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475603  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475606  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0047560b  e8f8990000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00475610  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475614  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475615  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047561b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047561c  2eff1588534b00         -call dword ptr cs:[0x4b5388]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936584) /* 0x4b5388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475623  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475627  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475628  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047562e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047562f  2eff15ac534b00         -call dword ptr cs:[0x4b53ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936620) /* 0x4b53ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475636  a14c8d4c00             -mov eax, dword ptr [0x4c8d4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016908) /* 0x4c8d4c */);
    // 0047563b  e8e0990000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00475640  833d84844c0000         +cmp dword ptr [0x4c8484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014660) /* 0x4c8484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475647  7406                   -je 0x47564f
    if (cpu.flags.zf)
    {
        goto L_0x0047564f;
    }
    // 00475649  ff1584844c00           -call dword ptr [0x4c8484]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014660) /* 0x4c8484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047564f:
    // 0047564f  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00475653  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 00475659  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047565a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047565f  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00475662  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475663  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475670  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475674  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00475678  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 0047567d  7505                   -jne 0x475684
    if (!cpu.flags.zf)
    {
        goto L_0x00475684;
    }
    // 0047567f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475681  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475684:
    // 00475684  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475685  682cda4b00             -push 0x4bda2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971052 /*0x4bda2c*/;
    cpu.esp -= 4;
    // 0047568a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047568c  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475691  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475693  e8d8510100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475698  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047569b  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0047569e  7405                   -je 0x4756a5
    if (cpu.flags.zf)
    {
        goto L_0x004756a5;
    }
    // 004756a0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004756a5:
    // 004756a5  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004756a8  7403                   -je 0x4756ad
    if (cpu.flags.zf)
    {
        goto L_0x004756ad;
    }
    // 004756aa  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004756ad:
    // 004756ad  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 004756b0  7403                   -je 0x4756b5
    if (cpu.flags.zf)
    {
        goto L_0x004756b5;
    }
    // 004756b2  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004756b5:
    // 004756b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004756b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004756b9  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004756bc  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 004756bf  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004756c5  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004756cb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004756cd  e8f2c10100             -call 0x4918c4
    cpu.esp -= 4;
    sub_4918c4(app, cpu);
    if (cpu.terminate) return;
    // 004756d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004756d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004756d5  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4756e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004756e0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004756e4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004756e8  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004756ed  7505                   -jne 0x4756f4
    if (!cpu.flags.zf)
    {
        goto L_0x004756f4;
    }
    // 004756ef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004756f1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004756f4:
    // 004756f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004756f5  6820da4b00             -push 0x4bda20
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971040 /*0x4bda20*/;
    cpu.esp -= 4;
    // 004756fa  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004756fc  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475701  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475703  e868510100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475708  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047570b  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0047570e  7405                   -je 0x475715
    if (cpu.flags.zf)
    {
        goto L_0x00475715;
    }
    // 00475710  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00475715:
    // 00475715  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00475718  7403                   -je 0x47571d
    if (cpu.flags.zf)
    {
        goto L_0x0047571d;
    }
    // 0047571a  80cb02                 -or bl, 2
    cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0047571d:
    // 0047571d  f6c210                 +test dl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 16 /*0x10*/));
    // 00475720  7403                   -je 0x475725
    if (cpu.flags.zf)
    {
        goto L_0x00475725;
    }
    // 00475722  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00475725:
    // 00475725  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00475727  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475729  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0047572c  6689c8                 -mov ax, cx
    cpu.ax = cpu.cx;
    // 0047572f  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00475735  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047573a  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00475740  e87fc10100             -call 0x4918c4
    cpu.esp -= 4;
    sub_4918c4(app, cpu);
    if (cpu.terminate) return;
    // 00475745  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475746  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475748  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475750  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00475755  743a                   -je 0x475791
    if (cpu.flags.zf)
    {
        goto L_0x00475791;
    }
    // 00475757  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047575b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0047575e  8b0da8814c00           -mov ecx, dword ptr [0x4c81a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013928) /* 0x4c81a8 */);
    // 00475764  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00475767  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475769  740a                   -je 0x475775
    if (cpu.flags.zf)
    {
        goto L_0x00475775;
    }
    // 0047576b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047576d  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 00475770  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00475775:
    // 00475775  6814da4b00             -push 0x4bda14
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971028 /*0x4bda14*/;
    cpu.esp -= 4;
    // 0047577a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047577c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0047577e  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475783  889084854c00           -mov byte ptr [eax + 0x4c8584], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5014916) /* 0x4c8584 */) = cpu.dl;
    // 00475789  e8e2500100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 0047578e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00475791:
    // 00475791  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475793  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4757a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004757a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004757a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004757a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004757a3  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004757a7  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 004757ac  0f84b1000000           -je 0x475863
    if (cpu.flags.zf)
    {
        goto L_0x00475863;
    }
    // 004757b2  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004757b4  8b0d90ae5100           -mov ecx, dword ptr [0x51ae90]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5353104) /* 0x51ae90 */);
    // 004757ba  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004757c0  39ce                   +cmp esi, ecx
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
    // 004757c2  7e02                   -jle 0x4757c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004757c6;
    }
    // 004757c4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004757c6:
    // 004757c6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004757c8  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004757cb  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004757ce  8b1da8814c00           -mov ebx, dword ptr [0x4c81a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013928) /* 0x4c81a8 */);
    // 004757d4  a39cae5100             -mov dword ptr [0x51ae9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5353116) /* 0x51ae9c */) = cpu.eax;
    // 004757d9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004757db  740e                   -je 0x4757eb
    if (cpu.flags.zf)
    {
        goto L_0x004757eb;
    }
    // 004757dd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004757df  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004757e1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004757e6  a39cae5100             -mov dword ptr [0x51ae9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5353116) /* 0x51ae9c */) = cpu.eax;
L_0x004757eb:
    // 004757eb  a19cae5100             -mov eax, dword ptr [0x51ae9c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353116) /* 0x51ae9c */);
    // 004757f0  c68084854c0001         -mov byte ptr [eax + 0x4c8584], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5014916) /* 0x4c8584 */) = 1 /*0x1*/;
    // 004757f7  833d7c854c0000         +cmp dword ptr [0x4c857c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014908) /* 0x4c857c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004757fe  7424                   -je 0x475824
    if (cpu.flags.zf)
    {
        goto L_0x00475824;
    }
    // 00475800  3b05a4814c00           +cmp eax, dword ptr [0x4c81a4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5013924) /* 0x4c81a4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475806  751c                   -jne 0x475824
    if (!cpu.flags.zf)
    {
        goto L_0x00475824;
    }
    // 00475808  803dbc854c0000         +cmp byte ptr [0x4c85bc], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014972) /* 0x4c85bc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047580f  7413                   -je 0x475824
    if (cpu.flags.zf)
    {
        goto L_0x00475824;
    }
    // 00475811  68c0d94b00             -push 0x4bd9c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970944 /*0x4bd9c0*/;
    cpu.esp -= 4;
    // 00475816  2eff1524554b00         -call dword ptr cs:[0x4b5524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936996) /* 0x4b5524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047581d  2eff153c544b00         -call dword ptr cs:[0x4b543c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936764) /* 0x4b543c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00475824:
    // 00475824  c1ef18                 -shr edi, 0x18
    cpu.edi >>= 24 /*0x18*/ % 32;
    // 00475827  8b1d98ae5100           -mov ebx, dword ptr [0x51ae98]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353112) /* 0x51ae98 */);
    // 0047582d  83e701                 -and edi, 1
    cpu.edi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00475830  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00475832  743a                   -je 0x47586e
    if (cpu.flags.zf)
    {
        goto L_0x0047586e;
    }
    // 00475834  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00475836  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00475838:
    // 00475838  4e                     -dec esi
    (cpu.esi)--;
    // 00475839  83feff                 +cmp esi, -1
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
    // 0047583c  7411                   -je 0x47584f
    if (cpu.flags.zf)
    {
        goto L_0x0047584f;
    }
    // 0047583e  8b159cae5100           -mov edx, dword ptr [0x51ae9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353116) /* 0x51ae9c */);
    // 00475844  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00475846  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00475848  e883070000             -call 0x475fd0
    cpu.esp -= 4;
    sub_475fd0(app, cpu);
    if (cpu.terminate) return;
    // 0047584d  ebe9                   -jmp 0x475838
    goto L_0x00475838;
L_0x0047584f:
    // 0047584f  68d0d94b00             -push 0x4bd9d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970960 /*0x4bd9d0*/;
    cpu.esp -= 4;
L_0x00475854:
    // 00475854  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475856  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 0047585b  e810500100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475860  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00475863:
    // 00475863  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00475868  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475869  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047586a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047586b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047586e:
    // 0047586e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00475872  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475876  e8f5030000             -call 0x475c70
    cpu.esp -= 4;
    sub_475c70(app, cpu);
    if (cpu.terminate) return;
    // 0047587b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047587d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047587f  7417                   -je 0x475898
    if (cpu.flags.zf)
    {
        goto L_0x00475898;
    }
L_0x00475881:
    // 00475881  4e                     -dec esi
    (cpu.esi)--;
    // 00475882  83feff                 +cmp esi, -1
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
    // 00475885  742d                   -je 0x4758b4
    if (cpu.flags.zf)
    {
        goto L_0x004758b4;
    }
    // 00475887  8b159cae5100           -mov edx, dword ptr [0x51ae9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353116) /* 0x51ae9c */);
    // 0047588d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047588f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00475891  e83a070000             -call 0x475fd0
    cpu.esp -= 4;
    sub_475fd0(app, cpu);
    if (cpu.terminate) return;
    // 00475896  ebe9                   -jmp 0x475881
    goto L_0x00475881;
L_0x00475898:
    // 00475898  6800da4b00             -push 0x4bda00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4971008 /*0x4bda00*/;
    cpu.esp -= 4;
    // 0047589d  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047589f  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004758a4  e8c74f0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004758a9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004758ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004758ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004758af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004758b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004758b1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004758b4:
    // 004758b4  68e4d94b00             -push 0x4bd9e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970980 /*0x4bd9e4*/;
    cpu.esp -= 4;
    // 004758b9  eb99                   -jmp 0x475854
    goto L_0x00475854;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4758c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004758c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004758c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004758c2  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004758c6  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004758ca  837c240c00             +cmp dword ptr [esp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004758cf  744f                   -je 0x475920
    if (cpu.flags.zf)
    {
        goto L_0x00475920;
    }
    // 004758d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004758d2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004758d3  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004758d5  8b1d90ae5100           -mov ebx, dword ptr [0x51ae90]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353104) /* 0x51ae90 */);
    // 004758db  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004758e1  39d9                   +cmp ecx, ebx
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
    // 004758e3  7f21                   -jg 0x475906
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00475906;
    }
L_0x004758e5:
    // 004758e5  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004758e7  c1ee18                 -shr esi, 0x18
    cpu.esi >>= 24 /*0x18*/ % 32;
    // 004758ea  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004758ed  83e601                 -and esi, 1
    cpu.esi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004758f0  83e77f                 -and edi, 0x7f
    cpu.edi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x004758f3:
    // 004758f3  49                     -dec ecx
    (cpu.ecx)--;
    // 004758f4  83f9ff                 +cmp ecx, -1
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
    // 004758f7  7411                   -je 0x47590a
    if (cpu.flags.zf)
    {
        goto L_0x0047590a;
    }
    // 004758f9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004758fb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004758fd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004758ff  e8cc060000             -call 0x475fd0
    cpu.esp -= 4;
    sub_475fd0(app, cpu);
    if (cpu.terminate) return;
    // 00475904  ebed                   -jmp 0x4758f3
    goto L_0x004758f3;
L_0x00475906:
    // 00475906  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00475908  ebdb                   -jmp 0x4758e5
    goto L_0x004758e5;
L_0x0047590a:
    // 0047590a  68b4d94b00             -push 0x4bd9b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970932 /*0x4bd9b4*/;
    cpu.esp -= 4;
    // 0047590f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475911  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475916  e8554f0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 0047591b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047591e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047591f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00475920:
    // 00475920  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00475925  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475926  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475927  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475931  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475934  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475938  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047593a  7509                   -jne 0x475945
    if (!cpu.flags.zf)
    {
        goto L_0x00475945;
    }
L_0x0047593c:
    // 0047593c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047593e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475941  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475942  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475945:
    // 00475945  68a4d94b00             -push 0x4bd9a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970916 /*0x4bd9a4*/;
    cpu.esp -= 4;
    // 0047594a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047594c  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475951  e81a4f0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475956  8aa35d040000           -mov ah, byte ptr [ebx + 0x45d]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
    // 0047595c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047595f  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00475961  75d9                   -jne 0x47593c
    if (!cpu.flags.zf)
    {
        goto L_0x0047593c;
    }
    // 00475963  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00475965  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475966  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047596c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047596d  2eff15b8534b00         -call dword ptr cs:[0x4b53b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936632) /* 0x4b53b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475974  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00475976  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475977  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0047597d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047597e  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475985  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00475988  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0047598e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475992  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 00475998  833d84844c0000         +cmp dword ptr [0x4c8484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014660) /* 0x4c8484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047599f  749b                   -je 0x47593c
    if (cpu.flags.zf)
    {
        goto L_0x0047593c;
    }
    // 004759a1  ff1584844c00           -call dword ptr [0x4c8484]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5014660) /* 0x4c8484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004759a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004759a9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004759ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004759ad  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4759b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004759b0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004759b4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004759b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004759b9  6878d94b00             -push 0x4bd978
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970872 /*0x4bd978*/;
    cpu.esp -= 4;
    // 004759be  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004759c0  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004759c5  e8a64e0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004759ca  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004759cd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004759cf  7409                   -je 0x4759da
    if (cpu.flags.zf)
    {
        goto L_0x004759da;
    }
    // 004759d1  80ba5d04000000         +cmp byte ptr [edx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004759d8  750f                   -jne 0x4759e9
    if (!cpu.flags.zf)
    {
        goto L_0x004759e9;
    }
L_0x004759da:
    // 004759da  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004759de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004759e0  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004759e6  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004759e9:
    // 004759e9  688cd94b00             -push 0x4bd98c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970892 /*0x4bd98c*/;
    cpu.esp -= 4;
    // 004759ee  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004759f0  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004759f5  e8764e0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004759fa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004759fd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004759ff  6884814c00             -push 0x4c8184
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013892 /*0x4c8184*/;
    cpu.esp -= 4;
    // 00475a04  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475a06  6a10                   -push 0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = 16 /*0x10*/;
    cpu.esp -= 4;
    // 00475a08  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475a0f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475a11  6888814c00             -push 0x4c8188
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013896 /*0x4c8188*/;
    cpu.esp -= 4;
    // 00475a16  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475a18  6a54                   -push 0x54
    app->getMemory<x86::reg32>(cpu.esp-4) = 84 /*0x54*/;
    cpu.esp -= 4;
    // 00475a1a  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475a21  833d84814c0000         +cmp dword ptr [0x4c8184], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013892) /* 0x4c8184 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a28  740f                   -je 0x475a39
    if (cpu.flags.zf)
    {
        goto L_0x00475a39;
    }
    // 00475a2a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475a2c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475a2e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475a30  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00475a32  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00475a39:
    // 00475a39  833d88814c0000         +cmp dword ptr [0x4c8188], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5013896) /* 0x4c8188 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a40  7498                   -je 0x4759da
    if (cpu.flags.zf)
    {
        goto L_0x004759da;
    }
    // 00475a42  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475a44  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475a46  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475a48  6a56                   -push 0x56
    app->getMemory<x86::reg32>(cpu.esp-4) = 86 /*0x56*/;
    cpu.esp -= 4;
    // 00475a4a  2eff150c544b00         -call dword ptr cs:[0x4b540c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936716) /* 0x4b540c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475a51  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00475a55  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475a57  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00475a5d  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_475a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475a60  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475a64  3d60f00000             +cmp eax, 0xf060
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61536 /*0xf060*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a69  7424                   -je 0x475a8f
    if (cpu.flags.zf)
    {
        goto L_0x00475a8f;
    }
    // 00475a6b  3d20f00000             +cmp eax, 0xf020
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61472 /*0xf020*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a70  741d                   -je 0x475a8f
    if (cpu.flags.zf)
    {
        goto L_0x00475a8f;
    }
    // 00475a72  3d30f00000             +cmp eax, 0xf030
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61488 /*0xf030*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a77  7416                   -je 0x475a8f
    if (cpu.flags.zf)
    {
        goto L_0x00475a8f;
    }
    // 00475a79  3d20f10000             +cmp eax, 0xf120
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61728 /*0xf120*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475a7e  740f                   -je 0x475a8f
    if (cpu.flags.zf)
    {
        goto L_0x00475a8f;
    }
    // 00475a80  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475a84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475a86  8a825d040000           -mov al, byte ptr [edx + 0x45d]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
    // 00475a8c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475a8f:
    // 00475a8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475a91  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475aa0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475aa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475aa6  7505                   -jne 0x475aad
    if (!cpu.flags.zf)
    {
        goto L_0x00475aad;
    }
    // 00475aa8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475aaa  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475aad:
    // 00475aad  6864d94b00             -push 0x4bd964
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970852 /*0x4bd964*/;
    cpu.esp -= 4;
    // 00475ab2  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475ab4  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475ab9  c7805404000000000000   -mov dword ptr [eax + 0x454], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */) = 0 /*0x0*/;
    // 00475ac3  e8a84d0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475ac8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475acb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475acd  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_475ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475ad0  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00475ad5  7508                   -jne 0x475adf
    if (!cpu.flags.zf)
    {
        goto L_0x00475adf;
    }
    // 00475ad7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00475adc  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475adf:
    // 00475adf  6854d94b00             -push 0x4bd954
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970836 /*0x4bd954*/;
    cpu.esp -= 4;
    // 00475ae4  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475ae6  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475aeb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00475af0  e87b4d0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475af5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475af8  890d80814c00           -mov dword ptr [0x4c8180], ecx
    app->getMemory<x86::reg32>(x86::reg32(5013888) /* 0x4c8180 */) = cpu.ecx;
    // 00475afe  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00475b03  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475b10  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00475b15  7508                   -jne 0x475b1f
    if (!cpu.flags.zf)
    {
        goto L_0x00475b1f;
    }
    // 00475b17  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00475b1c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475b1f:
    // 00475b1f  6848d94b00             -push 0x4bd948
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970824 /*0x4bd948*/;
    cpu.esp -= 4;
    // 00475b24  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475b26  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475b2b  e8404d0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475b30  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475b33  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475b35  2eff15dc534b00         -call dword ptr cs:[0x4b53dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936668) /* 0x4b53dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475b3c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00475b41  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475b50  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475b54  3b1584b55100           +cmp edx, dword ptr [0x51b584]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475b5a  7405                   -je 0x475b61
    if (cpu.flags.zf)
    {
        goto L_0x00475b61;
    }
    // 00475b5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475b5e  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475b61:
    // 00475b61  6838d94b00             -push 0x4bd938
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970808 /*0x4bd938*/;
    cpu.esp -= 4;
    // 00475b66  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475b68  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475b6d  e8fe4c0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475b72  8b0d94ae5100           -mov ecx, dword ptr [0x51ae94]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5353108) /* 0x51ae94 */);
    // 00475b78  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475b7b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475b7d  7408                   -je 0x475b87
    if (cpu.flags.zf)
    {
        goto L_0x00475b87;
    }
    // 00475b7f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475b81  ff1594ae5100           -call dword ptr [0x51ae94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5353108) /* 0x51ae94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00475b87:
    // 00475b87  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00475b89  2eff1504544b00         -call dword ptr cs:[0x4b5404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936708) /* 0x4b5404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475b90  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 00475b95  b884854c00             -mov eax, 0x4c8584
    cpu.eax = 5014916 /*0x4c8584*/;
    // 00475b9a  e83d950000             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 00475b9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00475ba1  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475bb0  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00475bb4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00475bb6  7465                   -je 0x475c1d
    if (cpu.flags.zf)
    {
        goto L_0x00475c1d;
    }
    // 00475bb8  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00475bbc  3b0d84b55100           +cmp ecx, dword ptr [0x51b584]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475bc2  7559                   -jne 0x475c1d
    if (!cpu.flags.zf)
    {
        goto L_0x00475c1d;
    }
    // 00475bc4  833d94ae510000         +cmp dword ptr [0x51ae94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5353108) /* 0x51ae94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475bcb  7555                   -jne 0x475c22
    if (!cpu.flags.zf)
    {
        goto L_0x00475c22;
    }
L_0x00475bcd:
    // 00475bcd  80ba5d04000000         +cmp byte ptr [edx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00475bd4  7409                   -je 0x475bdf
    if (cpu.flags.zf)
    {
        goto L_0x00475bdf;
    }
    // 00475bd6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00475bd8  2eff1504544b00         -call dword ptr cs:[0x4b5404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936708) /* 0x4b5404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00475bdf:
    // 00475bdf  833da4b5510000         +cmp dword ptr [0x51b5a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5354916) /* 0x51b5a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475be6  7521                   -jne 0x475c09
    if (!cpu.flags.zf)
    {
        goto L_0x00475c09;
    }
    // 00475be8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475be9  6818d94b00             -push 0x4bd918
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970776 /*0x4bd918*/;
    cpu.esp -= 4;
    // 00475bee  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 00475bf0  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475bf5  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00475bfa  e8714c0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475bff  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00475c02  893da4b55100           -mov dword ptr [0x51b5a4], edi
    app->getMemory<x86::reg32>(x86::reg32(5354916) /* 0x51b5a4 */) = cpu.edi;
    // 00475c08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00475c09:
    // 00475c09  6828d94b00             -push 0x4bd928
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970792 /*0x4bd928*/;
    cpu.esp -= 4;
    // 00475c0e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475c10  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475c15  e8564c0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475c1a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00475c1d:
    // 00475c1d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00475c1f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475c22:
    // 00475c22  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00475c27  ff1594ae5100           -call dword ptr [0x51ae94]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5353108) /* 0x51ae94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00475c2d  eb9e                   -jmp 0x475bcd
    goto L_0x00475bcd;
}

/* align: skip 0x00 */
void Application::sub_475c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475c30  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00475c34  a3a4b55100             -mov dword ptr [0x51b5a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5354916) /* 0x51b5a4 */) = cpu.eax;
    // 00475c39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00475c3b  741f                   -je 0x475c5c
    if (cpu.flags.zf)
    {
        goto L_0x00475c5c;
    }
    // 00475c3d  b8f0d84b00             -mov eax, 0x4bd8f0
    cpu.eax = 4970736 /*0x4bd8f0*/;
L_0x00475c42:
    // 00475c42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00475c43  6804d94b00             -push 0x4bd904
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970756 /*0x4bd904*/;
    cpu.esp -= 4;
    // 00475c48  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00475c4a  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 00475c4f  e81c4c0100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00475c54  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00475c57  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00475c59  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x00475c5c:
    // 00475c5c  b8f8d84b00             -mov eax, 0x4bd8f8
    cpu.eax = 4970744 /*0x4bd8f8*/;
    // 00475c61  ebdf                   -jmp 0x475c42
    goto L_0x00475c42;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475c70  3d04010000             +cmp eax, 0x104
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475c75  752d                   -jne 0x475ca4
    if (!cpu.flags.zf)
    {
        goto L_0x00475ca4;
    }
L_0x00475c77:
    // 00475c77  83fa65                 +cmp edx, 0x65
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475c7a  7334                   -jae 0x475cb0
    if (!cpu.flags.cf)
    {
        goto L_0x00475cb0;
    }
    // 00475c7c  83fa28                 +cmp edx, 0x28
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475c7f  0f83c9000000           -jae 0x475d4e
    if (!cpu.flags.cf)
    {
        goto L_0x00475d4e;
    }
    // 00475c85  83fa24                 +cmp edx, 0x24
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
    // 00475c88  0f8311010000           -jae 0x475d9f
    if (!cpu.flags.cf)
    {
        goto L_0x00475d9f;
    }
    // 00475c8e  83fa22                 +cmp edx, 0x22
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
    // 00475c91  0f8319010000           -jae 0x475db0
    if (!cpu.flags.cf)
    {
        goto L_0x00475db0;
    }
    // 00475c97  83fa21                 +cmp edx, 0x21
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475c9a  750f                   -jne 0x475cab
    if (!cpu.flags.zf)
    {
        goto L_0x00475cab;
    }
    // 00475c9c  ba00490000             -mov edx, 0x4900
    cpu.edx = 18688 /*0x4900*/;
    // 00475ca1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475ca3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475ca4:
    // 00475ca4  3d00010000             +cmp eax, 0x100
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
    // 00475ca9  74cc                   -je 0x475c77
    if (cpu.flags.zf)
    {
        goto L_0x00475c77;
    }
L_0x00475cab:
    // 00475cab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00475cad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475caf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475cb0:
    // 00475cb0  0f864c010000           -jbe 0x475e02
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475e02;
    }
    // 00475cb6  83fa73                 +cmp edx, 0x73
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475cb9  731c                   -jae 0x475cd7
    if (!cpu.flags.cf)
    {
        goto L_0x00475cd7;
    }
    // 00475cbb  83fa69                 +cmp edx, 0x69
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475cbe  7364                   -jae 0x475d24
    if (!cpu.flags.cf)
    {
        goto L_0x00475d24;
    }
    // 00475cc0  83fa67                 +cmp edx, 0x67
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475cc3  0f8241010000           -jb 0x475e0a
    if (cpu.flags.cf)
    {
        goto L_0x00475e0a;
    }
    // 00475cc9  0f8743010000           -ja 0x475e12
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475e12;
    }
    // 00475ccf  ba51000000             -mov edx, 0x51
    cpu.edx = 81 /*0x51*/;
    // 00475cd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475cd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475cd7:
    // 00475cd7  0f864d010000           -jbe 0x475e2a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475e2a;
    }
    // 00475cdd  83fa77                 +cmp edx, 0x77
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(119 /*0x77*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475ce0  7317                   -jae 0x475cf9
    if (!cpu.flags.cf)
    {
        goto L_0x00475cf9;
    }
    // 00475ce2  83fa75                 +cmp edx, 0x75
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475ce5  0f8247010000           -jb 0x475e32
    if (cpu.flags.cf)
    {
        goto L_0x00475e32;
    }
    // 00475ceb  0f8749010000           -ja 0x475e3a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475e3a;
    }
    // 00475cf1  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 00475cf6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475cf8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475cf9:
    // 00475cf9  0f8643010000           -jbe 0x475e42
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475e42;
    }
    // 00475cff  83fa79                 +cmp edx, 0x79
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475d02  0f8242010000           -jb 0x475e4a
    if (cpu.flags.cf)
    {
        goto L_0x00475e4a;
    }
    // 00475d08  0f8644010000           -jbe 0x475e52
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475e52;
    }
    // 00475d0e  83fa7a                 +cmp edx, 0x7a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475d11  0f8643010000           -jbe 0x475e5a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475e5a;
    }
    // 00475d17  83fa7b                 +cmp edx, 0x7b
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
    // 00475d1a  758f                   -jne 0x475cab
    if (!cpu.flags.zf)
    {
        goto L_0x00475cab;
    }
    // 00475d1c  ba00880000             -mov edx, 0x8800
    cpu.edx = 34816 /*0x8800*/;
    // 00475d21  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475d23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475d24:
    // 00475d24  0f86f0000000           -jbe 0x475e1a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475e1a;
    }
    // 00475d2a  83fa71                 +cmp edx, 0x71
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(113 /*0x71*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475d2d  7311                   -jae 0x475d40
    if (!cpu.flags.cf)
    {
        goto L_0x00475d40;
    }
    // 00475d2f  83fa70                 +cmp edx, 0x70
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475d32  0f8573ffffff           -jne 0x475cab
    if (!cpu.flags.zf)
    {
        goto L_0x00475cab;
    }
    // 00475d38  ba003b0000             -mov edx, 0x3b00
    cpu.edx = 15104 /*0x3b00*/;
    // 00475d3d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475d3f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475d40:
    // 00475d40  0f87dc000000           -ja 0x475e22
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475e22;
    }
    // 00475d46  ba003c0000             -mov edx, 0x3c00
    cpu.edx = 15360 /*0x3c00*/;
    // 00475d4b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475d4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475d4e:
    // 00475d4e  0f8686000000           -jbe 0x475dda
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475dda;
    }
    // 00475d54  83fa61                 +cmp edx, 0x61
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(97 /*0x61*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475d57  7316                   -jae 0x475d6f
    if (!cpu.flags.cf)
    {
        goto L_0x00475d6f;
    }
    // 00475d59  83fa2e                 +cmp edx, 0x2e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475d5c  732e                   -jae 0x475d8c
    if (!cpu.flags.cf)
    {
        goto L_0x00475d8c;
    }
    // 00475d5e  83fa2d                 +cmp edx, 0x2d
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
    // 00475d61  0f8544ffffff           -jne 0x475cab
    if (!cpu.flags.zf)
    {
        goto L_0x00475cab;
    }
    // 00475d67  ba00520000             -mov edx, 0x5200
    cpu.edx = 20992 /*0x5200*/;
    // 00475d6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475d6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475d6f:
    // 00475d6f  0f8675000000           -jbe 0x475dea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475dea;
    }
    // 00475d75  83fa63                 +cmp edx, 0x63
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475d78  0f8274000000           -jb 0x475df2
    if (cpu.flags.cf)
    {
        goto L_0x00475df2;
    }
    // 00475d7e  0f8776000000           -ja 0x475dfa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475dfa;
    }
    // 00475d84  ba47000000             -mov edx, 0x47
    cpu.edx = 71 /*0x47*/;
    // 00475d89  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475d8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475d8c:
    // 00475d8c  7654                   -jbe 0x475de2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475de2;
    }
    // 00475d8e  83fa60                 +cmp edx, 0x60
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(96 /*0x60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475d91  0f8514ffffff           -jne 0x475cab
    if (!cpu.flags.zf)
    {
        goto L_0x00475cab;
    }
    // 00475d97  ba00520000             -mov edx, 0x5200
    cpu.edx = 20992 /*0x5200*/;
    // 00475d9c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475d9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475d9f:
    // 00475d9f  7621                   -jbe 0x475dc2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00475dc2;
    }
    // 00475da1  83fa26                 +cmp edx, 0x26
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475da4  7224                   -jb 0x475dca
    if (cpu.flags.cf)
    {
        goto L_0x00475dca;
    }
    // 00475da6  772a                   -ja 0x475dd2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475dd2;
    }
    // 00475da8  ba00480000             -mov edx, 0x4800
    cpu.edx = 18432 /*0x4800*/;
    // 00475dad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475daf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475db0:
    // 00475db0  7708                   -ja 0x475dba
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00475dba;
    }
    // 00475db2  ba00510000             -mov edx, 0x5100
    cpu.edx = 20736 /*0x5100*/;
    // 00475db7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475db9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475dba:
    // 00475dba  ba004f0000             -mov edx, 0x4f00
    cpu.edx = 20224 /*0x4f00*/;
    // 00475dbf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475dc1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475dc2:
    // 00475dc2  ba00470000             -mov edx, 0x4700
    cpu.edx = 18176 /*0x4700*/;
    // 00475dc7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475dc9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475dca:
    // 00475dca  ba004b0000             -mov edx, 0x4b00
    cpu.edx = 19200 /*0x4b00*/;
    // 00475dcf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475dd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475dd2:
    // 00475dd2  ba004d0000             -mov edx, 0x4d00
    cpu.edx = 19712 /*0x4d00*/;
    // 00475dd7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475dd9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475dda:
    // 00475dda  ba00500000             -mov edx, 0x5000
    cpu.edx = 20480 /*0x5000*/;
    // 00475ddf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475de1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475de2:
    // 00475de2  ba00530000             -mov edx, 0x5300
    cpu.edx = 21248 /*0x5300*/;
    // 00475de7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475de9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475dea:
    // 00475dea  ba5a000000             -mov edx, 0x5a
    cpu.edx = 90 /*0x5a*/;
    // 00475def  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475df1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475df2:
    // 00475df2  ba58000000             -mov edx, 0x58
    cpu.edx = 88 /*0x58*/;
    // 00475df7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475df9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475dfa:
    // 00475dfa  ba41000000             -mov edx, 0x41
    cpu.edx = 65 /*0x41*/;
    // 00475dff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e02:
    // 00475e02  ba004c0000             -mov edx, 0x4c00
    cpu.edx = 19456 /*0x4c00*/;
    // 00475e07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e0a:
    // 00475e0a  ba44000000             -mov edx, 0x44
    cpu.edx = 68 /*0x44*/;
    // 00475e0f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e12:
    // 00475e12  ba57000000             -mov edx, 0x57
    cpu.edx = 87 /*0x57*/;
    // 00475e17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e19  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e1a:
    // 00475e1a  ba45000000             -mov edx, 0x45
    cpu.edx = 69 /*0x45*/;
    // 00475e1f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e22:
    // 00475e22  ba003d0000             -mov edx, 0x3d00
    cpu.edx = 15616 /*0x3d00*/;
    // 00475e27  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e2a:
    // 00475e2a  ba003e0000             -mov edx, 0x3e00
    cpu.edx = 15872 /*0x3e00*/;
    // 00475e2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e32:
    // 00475e32  ba003f0000             -mov edx, 0x3f00
    cpu.edx = 16128 /*0x3f00*/;
    // 00475e37  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e3a:
    // 00475e3a  ba00410000             -mov edx, 0x4100
    cpu.edx = 16640 /*0x4100*/;
    // 00475e3f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e42:
    // 00475e42  ba00420000             -mov edx, 0x4200
    cpu.edx = 16896 /*0x4200*/;
    // 00475e47  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e4a:
    // 00475e4a  ba00430000             -mov edx, 0x4300
    cpu.edx = 17152 /*0x4300*/;
    // 00475e4f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e52:
    // 00475e52  ba00440000             -mov edx, 0x4400
    cpu.edx = 17408 /*0x4400*/;
    // 00475e57  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00475e5a:
    // 00475e5a  ba00870000             -mov edx, 0x8700
    cpu.edx = 34560 /*0x8700*/;
    // 00475e5f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475e61  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475e70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475e71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475e72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475e73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475e74  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475e77  8b3584ae5100           -mov esi, dword ptr [0x51ae84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00475e7d  a188ae5100             -mov eax, dword ptr [0x51ae88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353096) /* 0x51ae88 */);
    // 00475e82  e881910000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00475e87  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475e89  8b3584ae5100           -mov esi, dword ptr [0x51ae84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00475e8f  8b158cae5100           -mov edx, dword ptr [0x51ae8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353100) /* 0x51ae8c */);
    // 00475e95  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475e97  39d6                   +cmp esi, edx
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
    // 00475e99  7455                   -je 0x475ef0
    if (cpu.flags.zf)
    {
        goto L_0x00475ef0;
    }
L_0x00475e9b:
    // 00475e9b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475e9d  7551                   -jne 0x475ef0
    if (!cpu.flags.zf)
    {
        goto L_0x00475ef0;
    }
    // 00475e9f  893584ae5100           -mov dword ptr [0x51ae84], esi
    app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */) = cpu.esi;
    // 00475ea5  8b04b5f0a95100         -mov eax, dword ptr [esi*4 + 0x51a9f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351920) /* 0x51a9f0 */ + cpu.esi * 4);
    // 00475eac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475eae  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00475eb0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00475eb3  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00475eb6  8a5c2401               -mov bl, byte ptr [esp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00475eba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475ebc  750e                   -jne 0x475ecc
    if (!cpu.flags.zf)
    {
        goto L_0x00475ecc;
    }
    // 00475ebe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475ec0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475ec2  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00475ec5  e8165f0000             -call 0x47bde0
    cpu.esp -= 4;
    sub_47bde0(app, cpu);
    if (cpu.terminate) return;
    // 00475eca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00475ecc:
    // 00475ecc  8b3584ae5100           -mov esi, dword ptr [0x51ae84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00475ed2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475ed4  7512                   -jne 0x475ee8
    if (!cpu.flags.zf)
    {
        goto L_0x00475ee8;
    }
    // 00475ed6  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00475ed9  8b3590ae5100           -mov esi, dword ptr [0x51ae90]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353104) /* 0x51ae90 */);
    // 00475edf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475ee1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475ee4  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00475ee6  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x00475ee8:
    // 00475ee8  3b358cae5100           +cmp esi, dword ptr [0x51ae8c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353100) /* 0x51ae8c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00475eee  75ab                   -jne 0x475e9b
    if (!cpu.flags.zf)
    {
        goto L_0x00475e9b;
    }
L_0x00475ef0:
    // 00475ef0  a188ae5100             -mov eax, dword ptr [0x51ae88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353096) /* 0x51ae88 */);
    // 00475ef5  893584ae5100           -mov dword ptr [0x51ae84], esi
    app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */) = cpu.esi;
    // 00475efb  e820910000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00475f00  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475f02  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00475f05  8b3584ae5100           -mov esi, dword ptr [0x51ae84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00475f0b  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475f0d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475f10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f11  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475f14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475f20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00475f21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475f22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00475f23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475f24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00475f25  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475f28  8b3584ae5100           -mov esi, dword ptr [0x51ae84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00475f2e  a188ae5100             -mov eax, dword ptr [0x51ae88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353096) /* 0x51ae88 */);
    // 00475f33  e8d0900000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00475f38  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475f3a  8b3584ae5100           -mov esi, dword ptr [0x51ae84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00475f40  8b158cae5100           -mov edx, dword ptr [0x51ae8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353100) /* 0x51ae8c */);
    // 00475f46  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475f48  39d6                   +cmp esi, edx
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
    // 00475f4a  7453                   -je 0x475f9f
    if (cpu.flags.zf)
    {
        goto L_0x00475f9f;
    }
L_0x00475f4c:
    // 00475f4c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475f4e  754f                   -jne 0x475f9f
    if (!cpu.flags.zf)
    {
        goto L_0x00475f9f;
    }
    // 00475f50  893584ae5100           -mov dword ptr [0x51ae84], esi
    app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */) = cpu.esi;
    // 00475f56  8b04b5f0a95100         -mov eax, dword ptr [esi*4 + 0x51a9f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5351920) /* 0x51a9f0 */ + cpu.esi * 4);
    // 00475f5d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00475f5f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00475f61  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00475f64  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00475f67  8a5c2401               -mov bl, byte ptr [esp + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00475f6b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00475f6d  750e                   -jne 0x475f7d
    if (!cpu.flags.zf)
    {
        goto L_0x00475f7d;
    }
    // 00475f6f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00475f71  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475f73  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00475f76  e8655e0000             -call 0x47bde0
    cpu.esp -= 4;
    sub_47bde0(app, cpu);
    if (cpu.terminate) return;
    // 00475f7b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00475f7d:
    // 00475f7d  8b3584ae5100           -mov esi, dword ptr [0x51ae84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00475f83  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00475f86  8b3590ae5100           -mov esi, dword ptr [0x51ae90]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353104) /* 0x51ae90 */);
    // 00475f8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00475f8e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00475f91  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00475f93  8b3d8cae5100           -mov edi, dword ptr [0x51ae8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5353100) /* 0x51ae8c */);
    // 00475f99  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00475f9b  39fa                   +cmp edx, edi
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
    // 00475f9d  75ad                   -jne 0x475f4c
    if (!cpu.flags.zf)
    {
        goto L_0x00475f4c;
    }
L_0x00475f9f:
    // 00475f9f  a188ae5100             -mov eax, dword ptr [0x51ae88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353096) /* 0x51ae88 */);
    // 00475fa4  893584ae5100           -mov dword ptr [0x51ae84], esi
    app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */) = cpu.esi;
    // 00475faa  e871900000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00475faf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00475fb1  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00475fb4  8b3584ae5100           -mov esi, dword ptr [0x51ae84]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00475fba  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 00475fbc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00475fbf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fc3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00475fc4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_475fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00475fd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00475fd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00475fd2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00475fd4  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00475fd6  a188ae5100             -mov eax, dword ptr [0x51ae88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353096) /* 0x51ae88 */);
    // 00475fdb  8b158cae5100           -mov edx, dword ptr [0x51ae8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353100) /* 0x51ae8c */);
    // 00475fe1  e822900000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00475fe6  66893495f2a95100       -mov word ptr [edx*4 + 0x51a9f2], si
    app->getMemory<x86::reg16>(x86::reg32(5351922) /* 0x51a9f2 */ + cpu.edx * 4) = cpu.si;
    // 00475fee  880c95f1a95100         -mov byte ptr [edx*4 + 0x51a9f1], cl
    app->getMemory<x86::reg8>(x86::reg32(5351921) /* 0x51a9f1 */ + cpu.edx * 4) = cpu.cl;
    // 00475ff5  881c95f0a95100         -mov byte ptr [edx*4 + 0x51a9f0], bl
    app->getMemory<x86::reg8>(x86::reg32(5351920) /* 0x51a9f0 */ + cpu.edx * 4) = cpu.bl;
    // 00475ffc  8b158cae5100           -mov edx, dword ptr [0x51ae8c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353100) /* 0x51ae8c */);
    // 00476002  42                     -inc edx
    (cpu.edx)++;
    // 00476003  8b0d90ae5100           -mov ecx, dword ptr [0x51ae90]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5353104) /* 0x51ae90 */);
    // 00476009  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047600b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047600e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00476010  a184ae5100             -mov eax, dword ptr [0x51ae84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00476015  89158cae5100           -mov dword ptr [0x51ae8c], edx
    app->getMemory<x86::reg32>(x86::reg32(5353100) /* 0x51ae8c */) = cpu.edx;
    // 0047601b  39d0                   +cmp eax, edx
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
    // 0047601d  7514                   -jne 0x476033
    if (!cpu.flags.zf)
    {
        goto L_0x00476033;
    }
    // 0047601f  8b1584ae5100           -mov edx, dword ptr [0x51ae84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */);
    // 00476025  42                     -inc edx
    (cpu.edx)++;
    // 00476026  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00476028  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047602b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047602d  891584ae5100           -mov dword ptr [0x51ae84], edx
    app->getMemory<x86::reg32>(x86::reg32(5353092) /* 0x51ae84 */) = cpu.edx;
L_0x00476033:
    // 00476033  a188ae5100             -mov eax, dword ptr [0x51ae88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353096) /* 0x51ae88 */);
    // 00476038  e8e38f0000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047603d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047603e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047603f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476040  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476041  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476042  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00476045  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476047  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047604a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047604c  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00476050  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476051  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 00476057  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476058  2eff1598534b00         -call dword ptr cs:[0x4b5398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936600) /* 0x4b5398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047605f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476061  7420                   -je 0x476083
    if (cpu.flags.zf)
    {
        goto L_0x00476083;
    }
    // 00476063  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476067  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476068  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047606c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
L_0x0047606d:
    // 0047606d  2eff15f4534b00         -call dword ptr cs:[0x4b53f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936692) /* 0x4b53f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00476074  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476076  2eff15f0534b00         -call dword ptr cs:[0x4b53f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936688) /* 0x4b53f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047607d  83c408                 +add esp, 8
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
    // 00476080  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476081  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476082  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476083:
    // 00476083  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476084  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476085  ebe6                   -jmp 0x47606d
    goto L_0x0047606d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476090  68d4d84b00             -push 0x4bd8d4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970708 /*0x4bd8d4*/;
    cpu.esp -= 4;
    // 00476095  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00476097  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 0047609c  e8cf470100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004760a1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004760a4  e8b3020000             -call 0x47635c
    cpu.esp -= 4;
    sub_47635c(app, cpu);
    if (cpu.terminate) return;
    // 004760a9  b890604700             -mov eax, 0x476090
    cpu.eax = 4677776 /*0x476090*/;
    // 004760ae  e8811f0000             -call 0x478034
    cpu.esp -= 4;
    sub_478034(app, cpu);
    if (cpu.terminate) return;
    // 004760b3  e869550100             -call 0x48b621
    cpu.esp -= 4;
    sub_48b621(app, cpu);
    if (cpu.terminate) return;
    // 004760b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004760ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4760c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004760c0  a394ae5100             -mov dword ptr [0x51ae94], eax
    app->getMemory<x86::reg32>(x86::reg32(5353108) /* 0x51ae94 */) = cpu.eax;
    // 004760c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4760d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004760d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004760d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004760d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004760d3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004760d5  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004760d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004760d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004760d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004760da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004760db  6894d84b00             -push 0x4bd894
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970644 /*0x4bd894*/;
    cpu.esp -= 4;
    // 004760e0  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004760e2  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 004760e7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004760e9  e882470100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 004760ee  8b2d84b55100           -mov ebp, dword ptr [0x51b584]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5354884) /* 0x51b584 */);
    // 004760f4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004760f7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004760f9  7456                   -je 0x476151
    if (cpu.flags.zf)
    {
        goto L_0x00476151;
    }
    // 004760fb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004760fd  7545                   -jne 0x476144
    if (!cpu.flags.zf)
    {
        goto L_0x00476144;
    }
    // 004760ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476100  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476101  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476102  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476103  2eff15d8534b00         -call dword ptr cs:[0x4b53d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936664) /* 0x4b53d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047610a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047610c  7509                   -jne 0x476117
    if (!cpu.flags.zf)
    {
        goto L_0x00476117;
    }
    // 0047610e  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00476115:
    // 00476115  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00476117:
    // 00476117  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476119  741c                   -je 0x476137
    if (cpu.flags.zf)
    {
        goto L_0x00476137;
    }
    // 0047611b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047611d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00476122  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476123  68bcd84b00             -push 0x4bd8bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970684 /*0x4bd8bc*/;
    cpu.esp -= 4;
    // 00476128  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0047612a  6874814c00             -push 0x4c8174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5013876 /*0x4c8174*/;
    cpu.esp -= 4;
    // 0047612f  e83c470100             -call 0x48a870
    cpu.esp -= 4;
    sub_48a870(app, cpu);
    if (cpu.terminate) return;
    // 00476134  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00476137:
    // 00476137  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476139  7516                   -jne 0x476151
    if (!cpu.flags.zf)
    {
        goto L_0x00476151;
    }
    // 0047613b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00476140  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476141  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476142  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476143  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476144:
    // 00476144  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476145  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476146  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476147  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476148  2eff15e8534b00         -call dword ptr cs:[0x4b53e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936680) /* 0x4b53e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047614f  ebc4                   -jmp 0x476115
    goto L_0x00476115;
L_0x00476151:
    // 00476151  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476153  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476154  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476155  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476156  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476160  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476161  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476162  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476163  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00476166  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047616a  8b15a0814c00           -mov edx, dword ptr [0x4c81a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00476170  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00476172  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476174  750a                   -jne 0x476180
    if (!cpu.flags.zf)
    {
        goto L_0x00476180;
    }
    // 00476176  e83d8e0000             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0047617b  a3a0814c00             -mov dword ptr [0x4c81a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */) = cpu.eax;
L_0x00476180:
    // 00476180  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00476185  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 0047618a  ba70aa5100             -mov edx, 0x51aa70
    cpu.edx = 5352048 /*0x51aa70*/;
    // 0047618f  e8748e0000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00476194  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00476198  68c0624700             -push 0x4762c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4678336 /*0x4762c0*/;
    cpu.esp -= 4;
    // 0047619d  8b1d78814c00           -mov ebx, dword ptr [0x4c8178]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013880) /* 0x4c8178 */);
    // 004761a3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004761a7  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004761ab  e831b10100             -call 0x4912e1
    cpu.esp -= 4;
    sub_4912e1(app, cpu);
    if (cpu.terminate) return;
    // 004761b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004761b2  7449                   -je 0x4761fd
    if (cpu.flags.zf)
    {
        goto L_0x004761fd;
    }
    // 004761b4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004761b6  7540                   -jne 0x4761f8
    if (!cpu.flags.zf)
    {
        goto L_0x004761f8;
    }
    // 004761b8  b9c0624700             -mov ecx, 0x4762c0
    cpu.ecx = 4678336 /*0x4762c0*/;
    // 004761bd  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004761c2  8b1578814c00           -mov edx, dword ptr [0x4c8178]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013880) /* 0x4c8178 */);
    // 004761c8  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 004761ce  b870aa5100             -mov eax, 0x51aa70
    cpu.eax = 5352048 /*0x51aa70*/;
    // 004761d3  e8efb10100             -call 0x4913c7
    cpu.esp -= 4;
    sub_4913c7(app, cpu);
    if (cpu.terminate) return;
    // 004761d8  ff0d78814c00           -dec dword ptr [0x4c8178]
    (app->getMemory<x86::reg32>(x86::reg32(5013880) /* 0x4c8178 */))--;
L_0x004761de:
    // 004761de  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004761e3:
    // 004761e3  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 004761e8  e8338e0000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004761ed  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004761ef  83c408                 +add esp, 8
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
    // 004761f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004761f5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004761f8:
    // 004761f8  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004761fb  ebe1                   -jmp 0x4761de
    goto L_0x004761de;
L_0x004761fd:
    // 004761fd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004761ff  74e2                   -je 0x4761e3
    if (cpu.flags.zf)
    {
        goto L_0x004761e3;
    }
    // 00476201  8b0d78814c00           -mov ecx, dword ptr [0x4c8178]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5013880) /* 0x4c8178 */);
    // 00476207  81f980000000           +cmp ecx, 0x80
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047620d  73d4                   -jae 0x4761e3
    if (!cpu.flags.cf)
    {
        goto L_0x004761e3;
    }
    // 0047620f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00476213  b870aa5100             -mov eax, 0x51aa70
    cpu.eax = 5352048 /*0x51aa70*/;
    // 00476218  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047621b  893ccd74aa5100         -mov dword ptr [ecx*8 + 0x51aa74], edi
    app->getMemory<x86::reg32>(x86::reg32(5352052) /* 0x51aa74 */ + cpu.ecx * 8) = cpu.edi;
    // 00476222  891d78814c00           -mov dword ptr [0x4c8178], ebx
    app->getMemory<x86::reg32>(x86::reg32(5013880) /* 0x4c8178 */) = cpu.ebx;
    // 00476228  8914cd70aa5100         -mov dword ptr [ecx*8 + 0x51aa70], edx
    app->getMemory<x86::reg32>(x86::reg32(5352048) /* 0x51aa70 */ + cpu.ecx * 8) = cpu.edx;
    // 0047622f  b9c0624700             -mov ecx, 0x4762c0
    cpu.ecx = 4678336 /*0x4762c0*/;
    // 00476234  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00476236  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0047623b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00476240  e882b10100             -call 0x4913c7
    cpu.esp -= 4;
    sub_4913c7(app, cpu);
    if (cpu.terminate) return;
    // 00476245  eb9c                   -jmp 0x4761e3
    goto L_0x004761e3;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476251  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476252  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00476255  8b15a0814c00           -mov edx, dword ptr [0x4c81a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 0047625b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047625d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047625f  750a                   -jne 0x47626b
    if (!cpu.flags.zf)
    {
        goto L_0x0047626b;
    }
    // 00476261  e8528d0000             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00476266  a3a0814c00             -mov dword ptr [0x4c81a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */) = cpu.eax;
L_0x0047626b:
    // 0047626b  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00476270  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 00476275  ba70aa5100             -mov edx, 0x51aa70
    cpu.edx = 5352048 /*0x51aa70*/;
    // 0047627a  e8898d0000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047627f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00476283  68c0624700             -push 0x4762c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4678336 /*0x4762c0*/;
    cpu.esp -= 4;
    // 00476288  8b1d78814c00           -mov ebx, dword ptr [0x4c8178]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013880) /* 0x4c8178 */);
    // 0047628e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00476292  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476296  e846b00100             -call 0x4912e1
    cpu.esp -= 4;
    sub_4912e1(app, cpu);
    if (cpu.terminate) return;
    // 0047629b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047629d  7403                   -je 0x4762a2
    if (cpu.flags.zf)
    {
        goto L_0x004762a2;
    }
    // 0047629f  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004762a2:
    // 004762a2  a1a0814c00             -mov eax, dword ptr [0x4c81a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5013920) /* 0x4c81a0 */);
    // 004762a7  e8748d0000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004762ac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004762ae  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004762b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762b3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4762c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004762c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004762c1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004762c3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004762c5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004762c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4762d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004762d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004762d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004762d2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004762d5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004762d8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004762da  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004762dc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004762de  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004762e0  7e0c                   -jle 0x4762ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004762ee;
    }
L_0x004762e2:
    // 004762e2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004762e4  ff1568a84c00           -call dword ptr [0x4ca868]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023848) /* 0x4ca868 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004762ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004762ec  7508                   -jne 0x4762f6
    if (!cpu.flags.zf)
    {
        goto L_0x004762f6;
    }
L_0x004762ee:
    // 004762ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004762f0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004762f3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004762f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004762f6:
    // 004762f6  e849430000             -call 0x47a644
    cpu.esp -= 4;
    sub_47a644(app, cpu);
    if (cpu.terminate) return;
    // 004762fb  42                     -inc edx
    (cpu.edx)++;
    // 004762fc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004762fe  7408                   -je 0x476308
    if (cpu.flags.zf)
    {
        goto L_0x00476308;
    }
    // 00476300  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00476303  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00476306  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00476308:
    // 00476308  39da                   +cmp edx, ebx
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
    // 0047630a  7cd6                   -jl 0x4762e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004762e2;
    }
    // 0047630c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047630e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00476311  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476312  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476313  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476314(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476314  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476315  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0047631a  e8b1ffffff             -call 0x4762d0
    cpu.esp -= 4;
    sub_4762d0(app, cpu);
    if (cpu.terminate) return;
    // 0047631f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476320  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: c38d4000 */
void Application::sub_476334(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476334  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476335  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047633a  b808854c00             -mov eax, 0x4c8508
    cpu.eax = 5014792 /*0x4c8508*/;
    // 0047633f  e828000000             -call 0x47636c
    cpu.esp -= 4;
    sub_47636c(app, cpu);
    if (cpu.terminate) return;
    // 00476344  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476345  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_476348(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476348  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476349  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047634e  b840854c00             -mov eax, 0x4c8540
    cpu.eax = 5014848 /*0x4c8540*/;
    // 00476353  e814000000             -call 0x47636c
    cpu.esp -= 4;
    sub_47636c(app, cpu);
    if (cpu.terminate) return;
    // 00476358  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476359  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47635c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047635c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047635d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00476362  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476364  e803000000             -call 0x47636c
    cpu.esp -= 4;
    sub_47636c(app, cpu);
    if (cpu.terminate) return;
    // 00476369  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047636a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47636c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047636c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047636d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047636e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047636f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476370  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476371  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476373  8b1584a84c00           -mov edx, dword ptr [0x4ca884]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023876) /* 0x4ca884 */);
    // 00476379  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0047637e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476380  7540                   -jne 0x4763c2
    if (!cpu.flags.zf)
    {
        goto L_0x004763c2;
    }
    // 00476382  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476384  7444                   -je 0x4763ca
    if (cpu.flags.zf)
    {
        goto L_0x004763ca;
    }
    // 00476386  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476388  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 0047638b  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00476390  e803d40000             -call 0x483798
    cpu.esp -= 4;
    sub_483798(app, cpu);
    if (cpu.terminate) return;
L_0x00476395:
    // 00476395  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00476397:
    // 00476397  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00476399  7461                   -je 0x4763fc
    if (cpu.flags.zf)
    {
        goto L_0x004763fc;
    }
    // 0047639b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047639d  7537                   -jne 0x4763d6
    if (!cpu.flags.zf)
    {
        goto L_0x004763d6;
    }
    // 0047639f  833d4c824c0000         +cmp dword ptr [0x4c824c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014092) /* 0x4c824c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004763a6  7435                   -je 0x4763dd
    if (cpu.flags.zf)
    {
        goto L_0x004763dd;
    }
L_0x004763a8:
    // 004763a8  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004763ad  8b354c824c00           -mov esi, dword ptr [0x4c824c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014092) /* 0x4c824c */);
L_0x004763b3:
    // 004763b3  bfd0844c00             -mov edi, 0x4c84d0
    cpu.edi = 5014736 /*0x4c84d0*/;
    // 004763b8  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004763ba  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004763bc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004763bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004763be  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004763bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004763c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004763c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004763c2:
    // 004763c2  ff1584a84c00           -call dword ptr [0x4ca884]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5023876) /* 0x4ca884 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004763c8  ebcb                   -jmp 0x476395
    goto L_0x00476395;
L_0x004763ca:
    // 004763ca  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 004763cf  e818d50000             -call 0x4838ec
    cpu.esp -= 4;
    sub_4838ec(app, cpu);
    if (cpu.terminate) return;
    // 004763d4  ebc1                   -jmp 0x476397
    goto L_0x00476397;
L_0x004763d6:
    // 004763d6  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004763db  ebd6                   -jmp 0x4763b3
    goto L_0x004763b3;
L_0x004763dd:
    // 004763dd  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004763e2  8b0d50824c00           -mov ecx, dword ptr [0x4c8250]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014096) /* 0x4c8250 */);
    // 004763e8  8b1dec814c00           -mov ebx, dword ptr [0x4c81ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 004763ee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004763f0  e85ba70100             -call 0x490b50
    cpu.esp -= 4;
    sub_490b50(app, cpu);
    if (cpu.terminate) return;
    // 004763f5  a34c824c00             -mov dword ptr [0x4c824c], eax
    app->getMemory<x86::reg32>(x86::reg32(5014092) /* 0x4c824c */) = cpu.eax;
    // 004763fa  ebac                   -jmp 0x4763a8
    goto L_0x004763a8;
L_0x004763fc:
    // 004763fc  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 00476401  b8d0844c00             -mov eax, 0x4c84d0
    cpu.eax = 5014736 /*0x4c84d0*/;
    // 00476406  e8d18c0000             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0047640b  a024854c00             -mov al, byte ptr [0x4c8524]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014820) /* 0x4c8524 */);
    // 00476410  a2ec844c00             -mov byte ptr [0x4c84ec], al
    app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */) = cpu.al;
    // 00476415  a025854c00             -mov al, byte ptr [0x4c8525]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014821) /* 0x4c8525 */);
    // 0047641a  a2ed844c00             -mov byte ptr [0x4c84ed], al
    app->getMemory<x86::reg8>(x86::reg32(5014765) /* 0x4c84ed */) = cpu.al;
    // 0047641f  a026854c00             -mov al, byte ptr [0x4c8526]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014822) /* 0x4c8526 */);
    // 00476424  a2ee844c00             -mov byte ptr [0x4c84ee], al
    app->getMemory<x86::reg8>(x86::reg32(5014766) /* 0x4c84ee */) = cpu.al;
    // 00476429  a138854c00             -mov eax, dword ptr [0x4c8538]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014840) /* 0x4c8538 */);
    // 0047642e  a300854c00             -mov dword ptr [0x4c8500], eax
    app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */) = cpu.eax;
    // 00476433  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476435  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476436  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476437  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476438  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476439  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047643a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47643c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047643c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047643d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047643f  e828ffffff             -call 0x47636c
    cpu.esp -= 4;
    sub_47636c(app, cpu);
    if (cpu.terminate) return;
    // 00476444  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476445  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_476448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476448  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476449  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047644e  e819ffffff             -call 0x47636c
    cpu.esp -= 4;
    sub_47636c(app, cpu);
    if (cpu.terminate) return;
    // 00476453  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476454  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_476458(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476458  b808854c00             -mov eax, 0x4c8508
    cpu.eax = 5014792 /*0x4c8508*/;
    // 0047645d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_476460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476460  b840854c00             -mov eax, 0x4c8540
    cpu.eax = 5014848 /*0x4c8540*/;
    // 00476465  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476470  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476471  8b35ec814c00           -mov esi, dword ptr [0x4c81ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 00476477  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476478  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047647a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0047647c  e8ffa40100             -call 0x490980
    cpu.esp -= 4;
    sub_490980(app, cpu);
    if (cpu.terminate) return;
    // 00476481  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476483  7402                   -je 0x476487
    if (cpu.flags.zf)
    {
        goto L_0x00476487;
    }
    // 00476485  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x00476487:
    // 00476487  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476488  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47648c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047648c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047648d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047648f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00476491  8b1dec814c00           -mov ebx, dword ptr [0x4c81ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 00476497  e8e4a40100             -call 0x490980
    cpu.esp -= 4;
    sub_490980(app, cpu);
    if (cpu.terminate) return;
    // 0047649c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047649e  7402                   -je 0x4764a2
    if (cpu.flags.zf)
    {
        goto L_0x004764a2;
    }
    // 004764a0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x004764a2:
    // 004764a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004764a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4764a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004764a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004764a5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004764a7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004764a9  8b1dec814c00           -mov ebx, dword ptr [0x4c81ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */);
    // 004764af  e8cca40100             -call 0x490980
    cpu.esp -= 4;
    sub_490980(app, cpu);
    if (cpu.terminate) return;
    // 004764b4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004764b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004764b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4764c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004764c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004764c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004764c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004764c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004764c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004764c5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004764c8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004764ca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004764cc  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004764cf  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004764d5  baa07b5200             -mov edx, 0x527ba0
    cpu.edx = 5405600 /*0x527ba0*/;
    // 004764da  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004764de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004764e0  bb9f860100             -mov ebx, 0x1869f
    cpu.ebx = 99999 /*0x1869f*/;
    // 004764e5  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004764e8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004764ed  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004764f3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004764f6  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004764fa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004764fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004764fe  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x00476502:
    // 00476502  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00476505  0fb672fe               -movzx esi, byte ptr [edx - 2]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-2) /* -0x2 */));
    // 00476509  0fb67afd               -movzx edi, byte ptr [edx - 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-3) /* -0x3 */));
    // 0047650d  8a88cc824c00           -mov cl, byte ptr [eax + 0x4c82cc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5014220) /* 0x4c82cc */);
    // 00476513  0fb66afc               -movzx ebp, byte ptr [edx - 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */));
    // 00476517  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00476519  742b                   -je 0x476546
    if (cpu.flags.zf)
    {
        goto L_0x00476546;
    }
    // 0047651b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047651f  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00476521  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00476523  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00476526  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047652a  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047652c  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0047652f  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00476532  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00476535  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00476537  0fafc9                 -imul ecx, ecx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0047653a  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047653c  39d9                   +cmp ecx, ebx
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
    // 0047653e  7d06                   -jge 0x476546
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00476546;
    }
    // 00476540  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00476542  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00476546:
    // 00476546  40                     -inc eax
    (cpu.eax)++;
    // 00476547  3d00010000             +cmp eax, 0x100
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
    // 0047654c  7cb4                   -jl 0x476502
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476502;
    }
    // 0047654e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476552  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00476555  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476556  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476557  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476558  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476559  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047655a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47655c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047655c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047655d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047655e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476560  8a25ec844c00           -mov ah, byte ptr [0x4c84ec]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00476566  80fc08                 +cmp ah, 8
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476569  761c                   -jbe 0x476587
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00476587;
    }
    // 0047656b  80fc0f                 +cmp ah, 0xf
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047656e  745e                   -je 0x4765ce
    if (cpu.flags.zf)
    {
        goto L_0x004765ce;
    }
    // 00476570  80fc10                 +cmp ah, 0x10
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476573  0f8483000000           -je 0x4765fc
    if (cpu.flags.zf)
    {
        goto L_0x004765fc;
    }
    // 00476579  80fc18                 +cmp ah, 0x18
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047657c  0f829f000000           -jb 0x476621
    if (cpu.flags.cf)
    {
        goto L_0x00476621;
    }
    // 00476582  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476584  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476585  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476586  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476587:
    // 00476587  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476588  8b0dc8824c00           -mov ecx, dword ptr [0x4c82c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014216) /* 0x4c82c8 */);
    // 0047658e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00476590  7427                   -je 0x4765b9
    if (cpu.flags.zf)
    {
        goto L_0x004765b9;
    }
    // 00476592  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476594  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 0047659a  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 0047659d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047659f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004765a2  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004765a8  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004765ab  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004765ae  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004765b0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004765b2  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004765b4  8a1c01                 -mov bl, byte ptr [ecx + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
    // 004765b7  eb0f                   -jmp 0x4765c8
    goto L_0x004765c8;
L_0x004765b9:
    // 004765b9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004765bb  8d05a07b5200           -lea eax, [0x527ba0]
    cpu.eax = x86::reg32(x86::reg32(5405600) /* 0x527ba0 */);
    // 004765c1  e8fafeffff             -call 0x4764c0
    cpu.esp -= 4;
    sub_4764c0(app, cpu);
    if (cpu.terminate) return;
    // 004765c6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004765c8:
    // 004765c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004765c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004765cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004765cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004765cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004765ce:
    // 004765ce  09db                   +or ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004765d0  7425                   -je 0x4765f7
    if (cpu.flags.zf)
    {
        goto L_0x004765f7;
    }
    // 004765d2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004765d4  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004765da  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004765dd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004765df  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004765e2  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004765e8  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004765eb  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004765ee  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004765f0  8d9c1300800000         -lea ebx, [ebx + edx + 0x8000]
    cpu.ebx = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */ + cpu.edx * 1);
L_0x004765f7:
    // 004765f7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004765f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004765fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004765fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004765fc:
    // 004765fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004765fe  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00476604  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00476607  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476609  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0047660c  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00476612  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00476615  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00476618  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047661a  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047661c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047661e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047661f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476620  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476621:
    // 00476621  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476623  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476625  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476626  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476627  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476630(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476630  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476631  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476632  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476633  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476634  8b0de8844c00           -mov ecx, dword ptr [0x4c84e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 0047663a  8b15e0844c00           -mov edx, dword ptr [0x4c84e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 00476640  8b1ddc844c00           -mov ebx, dword ptr [0x4c84dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 00476646  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00476647  a1e4844c00             -mov eax, dword ptr [0x4c84e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */);
    // 0047664c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047664e  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476650  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00476652  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476654  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476656  e8c56b0000             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 0047665b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047665c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047665d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047665e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047665f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476660  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476661  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476663  3b05a8af5100           +cmp eax, dword ptr [0x51afa8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353384) /* 0x51afa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476669  7428                   -je 0x476693
    if (cpu.flags.zf)
    {
        goto L_0x00476693;
    }
    // 0047666b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047666c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047666d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047666e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00476670  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476672  6bd600                 -imul edx, esi, 0
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(0 /*0x0*/)));
L_0x00476675:
    // 00476675  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00476677  40                     -inc eax
    (cpu.eax)++;
    // 00476678  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0047667b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047667d  8888a3ae5100           -mov byte ptr [eax + 0x51aea3], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5353123) /* 0x51aea3 */) = cpu.cl;
    // 00476683  3d00010000             +cmp eax, 0x100
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
    // 00476688  7ceb                   -jl 0x476675
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476675;
    }
    // 0047668a  8935a8af5100           -mov dword ptr [0x51afa8], esi
    app->getMemory<x86::reg32>(x86::reg32(5353384) /* 0x51afa8 */) = cpu.esi;
    // 00476690  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476691  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476692  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00476693:
    // 00476693  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476694  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_476698(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476698  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476699  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047669b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 0047669d  8a9ba4ae5100           -mov bl, byte ptr [ebx + 0x51aea4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5353124) /* 0x51aea4 */);
    // 004766a3  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004766a5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004766a7  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004766aa  8a9ba4ae5100           -mov bl, byte ptr [ebx + 0x51aea4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5353124) /* 0x51aea4 */);
    // 004766b0  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004766b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004766b5  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004766b8  8a9ba4ae5100           -mov bl, byte ptr [ebx + 0x51aea4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5353124) /* 0x51aea4 */);
    // 004766be  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004766c1  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 004766c4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004766c9  8a80a4ae5100           -mov al, byte ptr [eax + 0x51aea4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5353124) /* 0x51aea4 */);
    // 004766cf  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004766d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004766d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4766d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004766d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004766d5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004766d8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004766da  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004766dc  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004766df  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004766e2  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004766e5  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004766e8  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004766ea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004766ec  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004766ef  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004766f2  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004766f5  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004766f8  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 004766fb  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004766fe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00476700  8a4802                 -mov cl, byte ptr [eax + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00476703  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00476706  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 00476709  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0047670c  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 0047670f  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 00476712  8a4003                 -mov al, byte ptr [eax + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00476715  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047671a  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0047671d  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00476720  884203                 -mov byte ptr [edx + 3], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 00476723  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00476726  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476727  90                     -nop 
    ;
    // 00476728  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47672c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047672c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047672d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047672e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047672f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476730  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00476733  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476735  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476737  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00476739:
    // 00476739  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047673b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047673d  e856ffffff             -call 0x476698
    cpu.esp -= 4;
    sub_476698(app, cpu);
    if (cpu.terminate) return;
    // 00476742  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 00476744  8a742402               -mov dh, byte ptr [esp + 2]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00476748  8a642403               -mov ah, byte ptr [esp + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 0047674c  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 0047674f  28e0                   -sub al, ah
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.ah));
    // 00476751  8a542401               -mov dl, byte ptr [esp + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00476755  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 00476759  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047675b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476760  e87bb40100             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 00476765  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00476767  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 0047676a  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476770  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00476774  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00476778  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047677c  c1ed08                 -shr ebp, 8
    cpu.ebp >>= 8 /*0x8*/ % 32;
    // 0047677f  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476785  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476789  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0047678d  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 00476791  8a7c2408               -mov bh, byte ptr [esp + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476795  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00476797  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047679c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004767a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004767a2  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004767a6  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004767aa  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004767ad  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 004767b0  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004767b4  0fb6ee                 -movzx ebp, dh
    cpu.ebp = x86::reg32(cpu.dh);
    // 004767b7  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004767bb  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004767bf  0fb6ef                 -movzx ebp, bh
    cpu.ebp = x86::reg32(cpu.bh);
    // 004767c2  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004767c5  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 004767c8  8a742408               -mov dh, byte ptr [esp + 8]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004767cc  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004767d0  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 004767d3  036c2404               -add ebp, dword ptr [esp + 4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004767d7  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004767db  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 004767e0  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004767e3  8a542408               -mov dl, byte ptr [esp + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004767e7  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004767ea  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004767f0  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004767f2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004767f4  88f0                   -mov al, dh
    cpu.al = cpu.dh;
    // 004767f6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004767f9  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004767ff  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00476802  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00476804  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476806  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00476808  46                     -inc esi
    (cpu.esi)++;
    // 00476809  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047680b  83c104                 +add ecx, 4
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
    // 0047680e  e849fdffff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00476813  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00476816  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476817  0f851cffffff           -jne 0x476739
    if (!cpu.flags.zf)
    {
        goto L_0x00476739;
    }
    // 0047681d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00476820  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476821  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476822  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476823  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476824  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_476828(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476828  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476829  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047682a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047682b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047682c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047682f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00476831  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476833  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00476835:
    // 00476835  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00476837  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00476839  e85afeffff             -call 0x476698
    cpu.esp -= 4;
    sub_476698(app, cpu);
    if (cpu.terminate) return;
    // 0047683e  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00476841  81fb00000010           +cmp ebx, 0x10000000
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
    // 00476847  7273                   -jb 0x4768bc
    if (cpu.flags.cf)
    {
        goto L_0x004768bc;
    }
    // 00476849  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 0047684f  7348                   -jae 0x476899
    if (!cpu.flags.cf)
    {
        goto L_0x00476899;
    }
    // 00476851  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00476854  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476856  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 0047685b  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 0047685e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00476860  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00476866  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00476869  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047686b  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047686e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00476870  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00476872  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00476875  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047687b  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 0047687d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00476880  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476882  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476884  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00476887  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047688d  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047688f  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00476892  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00476897  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00476899:
    // 00476899  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047689b  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004768a1  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004768a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004768a6  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004768a9  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004768af  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004768b2  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004768b5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004768b7  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004768b9  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004768bc:
    // 004768bc  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004768bf  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004768c2  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004768c3  0f856cffffff           -jne 0x476835
    if (!cpu.flags.zf)
    {
        goto L_0x00476835;
    }
    // 004768c9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004768cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004768d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4768d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004768d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004768d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004768d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004768d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004768d8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004768db  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004768dd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004768df  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x004768e1:
    // 004768e1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004768e3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004768e5  e8aefdffff             -call 0x476698
    cpu.esp -= 4;
    sub_476698(app, cpu);
    if (cpu.terminate) return;
    // 004768ea  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004768ed  81fb00000010           +cmp ebx, 0x10000000
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
    // 004768f3  726b                   -jb 0x476960
    if (cpu.flags.cf)
    {
        goto L_0x00476960;
    }
    // 004768f5  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004768fb  7340                   -jae 0x47693d
    if (!cpu.flags.cf)
    {
        goto L_0x0047693d;
    }
    // 004768fd  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00476900  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00476902  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476904  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00476907  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047690a  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0047690c  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00476912  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00476915  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 0047691a  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 0047691d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047691f  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00476921  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00476924  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476926  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00476929  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047692b  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 0047692e  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476934  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00476939  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047693b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0047693d:
    // 0047693d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047693f  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00476945  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00476948  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047694a  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0047694d  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00476953  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00476956  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00476959  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047695b  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047695d  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00476960:
    // 00476960  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00476963  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476966  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476967  0f8574ffffff           -jne 0x4768e1
    if (!cpu.flags.zf)
    {
        goto L_0x004768e1;
    }
    // 0047696d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00476970  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476971  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476972  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476973  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476974  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_476978(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476978  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476979  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047697a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047697b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047697e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476980  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00476982:
    // 00476982  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00476984  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476986  e80dfdffff             -call 0x476698
    cpu.esp -= 4;
    sub_476698(app, cpu);
    if (cpu.terminate) return;
    // 0047698b  b0ff                   -mov al, 0xff
    cpu.al = 255 /*0xff*/;
    // 0047698d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00476990  8a642403               -mov ah, byte ptr [esp + 3]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 00476994  88542410               -mov byte ptr [esp + 0x10], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00476998  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047699a  28e0                   -sub al, ah
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.ah));
    // 0047699c  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 004769a0  8a6102                 -mov ah, byte ptr [ecx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004769a3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004769a5  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004769a7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004769ac  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004769af  0fb67c2402             -movzx edi, byte ptr [esp + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */));
    // 004769b4  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004769b7  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004769b9  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004769bd  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004769c1  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 004769c5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004769c7  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004769cb  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004769ce  0fb67c2401             -movzx edi, byte ptr [esp + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */));
    // 004769d3  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004769d6  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004769d8  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004769dc  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004769e0  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004769e4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004769e6  8a542414               -mov dl, byte ptr [esp + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004769ea  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004769ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004769ef  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004769f2  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 004769f5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004769f7  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004769fa  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004769fe  8861ff                 -mov byte ptr [ecx - 1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.ah;
    // 00476a01  8a64240c               -mov ah, byte ptr [esp + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476a05  8861fe                 -mov byte ptr [ecx - 2], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ah;
    // 00476a08  83c604                 +add esi, 4
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
    // 00476a0b  8841fd                 -mov byte ptr [ecx - 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-3) /* -0x3 */) = cpu.al;
    // 00476a0e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476a0f  0f856dffffff           -jne 0x476982
    if (!cpu.flags.zf)
    {
        goto L_0x00476982;
    }
    // 00476a15  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00476a18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476a19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476a1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476a1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476a1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476a1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476a1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476a1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476a1f  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00476a22  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00476a24  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
L_0x00476a26:
    // 00476a26  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00476a28  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476a2a  e869fcffff             -call 0x476698
    cpu.esp -= 4;
    sub_476698(app, cpu);
    if (cpu.terminate) return;
    // 00476a2f  b4ff                   -mov ah, 0xff
    cpu.ah = 255 /*0xff*/;
    // 00476a31  2a642403               -sub ah, byte ptr [esp + 3]
    (cpu.ah) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */)));
    // 00476a35  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00476a38  88542410               -mov byte ptr [esp + 0x10], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00476a3c  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00476a3e  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00476a41  88542414               -mov byte ptr [esp + 0x14], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dl;
    // 00476a45  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476a47  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00476a49  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00476a4b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476a50  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00476a53  0fb67c2402             -movzx edi, byte ptr [esp + 2]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */));
    // 00476a58  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00476a5b  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476a5d  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00476a61  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476a65  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00476a69  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476a6b  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00476a6f  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00476a72  0fb67c2401             -movzx edi, byte ptr [esp + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */));
    // 00476a77  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00476a7a  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476a7c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00476a80  8a542404               -mov dl, byte ptr [esp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476a84  8854240c               -mov byte ptr [esp + 0xc], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00476a88  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476a8a  8a542414               -mov dl, byte ptr [esp + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00476a8e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00476a91  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476a93  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00476a96  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00476a99  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00476a9c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476a9e  c641ffff               -mov byte ptr [ecx - 1], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = 255 /*0xff*/;
    // 00476aa2  8a642408               -mov ah, byte ptr [esp + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00476aa6  8861fe                 -mov byte ptr [ecx - 2], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ah;
    // 00476aa9  8a64240c               -mov ah, byte ptr [esp + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476aad  8861fd                 -mov byte ptr [ecx - 3], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-3) /* -0x3 */) = cpu.ah;
    // 00476ab0  83c604                 +add esi, 4
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
    // 00476ab3  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 00476ab6  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476ab7  0f8569ffffff           -jne 0x476a26
    if (!cpu.flags.zf)
    {
        goto L_0x00476a26;
    }
    // 00476abd  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00476ac0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ac1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ac2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ac3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_476ac4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476ac4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476ac5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476ac6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476ac7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476ac8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00476aca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476acc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00476ace:
    // 00476ace  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476ad0  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00476ad3  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00476ada  8b1da4af5100           -mov ebx, dword ptr [0x51afa4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353380) /* 0x51afa4 */);
    // 00476ae0  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00476ae3  45                     -inc ebp
    (cpu.ebp)++;
    // 00476ae4  81fb00000010           +cmp ebx, 0x10000000
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
    // 00476aea  726b                   -jb 0x476b57
    if (cpu.flags.cf)
    {
        goto L_0x00476b57;
    }
    // 00476aec  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00476af2  7340                   -jae 0x476b34
    if (!cpu.flags.cf)
    {
        goto L_0x00476b34;
    }
    // 00476af4  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00476af7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00476af9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476afb  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00476afe  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00476b01  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00476b03  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00476b09  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00476b0c  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00476b11  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00476b14  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476b16  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00476b18  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00476b1b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476b1d  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00476b20  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476b22  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00476b25  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476b2b  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00476b30  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00476b32  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00476b34:
    // 00476b34  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476b36  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00476b3c  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00476b3f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476b41  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00476b44  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00476b4a  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00476b4d  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00476b50  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00476b52  01d3                   +add ebx, edx
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
    // 00476b54  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00476b57:
    // 00476b57  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00476b5a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476b5b  0f856dffffff           -jne 0x476ace
    if (!cpu.flags.zf)
    {
        goto L_0x00476ace;
    }
    // 00476b61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b62  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b63  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476b65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_476b68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476b68  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476b69  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476b6a  81ec08040000           -sub esp, 0x408
    (cpu.esp) -= x86::reg32(x86::sreg32(1032 /*0x408*/));
    // 00476b70  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00476b72  89942400040000         -mov dword ptr [esp + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 00476b79  899c2404040000         -mov dword ptr [esp + 0x404], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */) = cpu.ebx;
    // 00476b80  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00476b82  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00476b84  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00476b87  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 00476b8d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476b8f  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 00476b94  8915e4834c00           -mov dword ptr [0x4c83e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5014500) /* 0x4c83e4 */) = cpu.edx;
    // 00476b9a  890dec834c00           -mov dword ptr [0x4c83ec], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014508) /* 0x4c83ec */) = cpu.ecx;
    // 00476ba0  83f808                 +cmp eax, 8
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
    // 00476ba3  0f8593000000           -jne 0x476c3c
    if (!cpu.flags.zf)
    {
        goto L_0x00476c3c;
    }
    // 00476ba9  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476bb0  0f8586000000           -jne 0x476c3c
    if (!cpu.flags.zf)
    {
        goto L_0x00476c3c;
    }
    // 00476bb6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476bb7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476bbb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476bbd  e886b80100             -call 0x492448
    cpu.esp -= 4;
    sub_492448(app, cpu);
    if (cpu.terminate) return;
    // 00476bc2  a3a4af5100             -mov dword ptr [0x51afa4], eax
    app->getMemory<x86::reg32>(x86::reg32(5353380) /* 0x51afa4 */) = cpu.eax;
    // 00476bc7  81ffff000000           +cmp edi, 0xff
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476bcd  7d33                   -jge 0x476c02
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00476c02;
    }
    // 00476bcf  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476bd3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00476bd5:
    // 00476bd5  8b15a4af5100           -mov edx, dword ptr [0x51afa4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5353380) /* 0x51afa4 */);
    // 00476bdb  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00476be2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00476be4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476be6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00476be8  41                     -inc ecx
    (cpu.ecx)++;
    // 00476be9  e8e6faffff             -call 0x4766d4
    cpu.esp -= 4;
    sub_4766d4(app, cpu);
    if (cpu.terminate) return;
    // 00476bee  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00476bf1  81f900010000           +cmp ecx, 0x100
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476bf7  7cdc                   -jl 0x476bd5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476bd5;
    }
    // 00476bf9  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476bfd  a3a4af5100             -mov dword ptr [0x51afa4], eax
    app->getMemory<x86::reg32>(x86::reg32(5353380) /* 0x51afa4 */) = cpu.eax;
L_0x00476c02:
    // 00476c02  bbc46a4700             -mov ebx, 0x476ac4
    cpu.ebx = 4680388 /*0x476ac4*/;
    // 00476c07  be7b000000             -mov esi, 0x7b
    cpu.esi = 123 /*0x7b*/;
    // 00476c0c  891de4834c00           -mov dword ptr [0x4c83e4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014500) /* 0x4c83e4 */) = cpu.ebx;
    // 00476c12  8935ec834c00           -mov dword ptr [0x4c83ec], esi
    app->getMemory<x86::reg32>(x86::reg32(5014508) /* 0x4c83ec */) = cpu.esi;
    // 00476c18  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00476c19:
    // 00476c19  b9cc834c00             -mov ecx, 0x4c83cc
    cpu.ecx = 5014476 /*0x4c83cc*/;
    // 00476c1e  8b9c2404040000         -mov ebx, dword ptr [esp + 0x404]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1028) /* 0x404 */);
    // 00476c25  8b942400040000         -mov edx, dword ptr [esp + 0x400]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 00476c2c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00476c2e  e8e9bf0100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 00476c33  81c408040000           +add esp, 0x408
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1032 /*0x408*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476c39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476c3c:
    // 00476c3c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00476c3e  e81dfaffff             -call 0x476660
    cpu.esp -= 4;
    sub_476660(app, cpu);
    if (cpu.terminate) return;
    // 00476c43  ebd4                   -jmp 0x476c19
    goto L_0x00476c19;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_476c48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476c48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476c49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476c4a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476c4b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00476c4d  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00476c50  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00476c53  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00476c56  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00476c59  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00476c5c  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00476c5f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00476c61  e802ffffff             -call 0x476b68
    cpu.esp -= 4;
    sub_476b68(app, cpu);
    if (cpu.terminate) return;
    // 00476c66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_476c6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476c6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476c6d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00476c70  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00476c73  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00476c75  8b7006                 -mov esi, dword ptr [eax + 6]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00476c78  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00476c7b  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00476c7d  e8e6feffff             -call 0x476b68
    cpu.esp -= 4;
    sub_476b68(app, cpu);
    if (cpu.terminate) return;
    // 00476c82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476c83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476c90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476c91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476c92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00476c93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476c94  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476c96  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00476c99  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476c9b  7527                   -jne 0x476cc4
    if (!cpu.flags.zf)
    {
        goto L_0x00476cc4;
    }
L_0x00476c9d:
    // 00476c9d  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00476ca0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476ca2  7407                   -je 0x476cab
    if (cpu.flags.zf)
    {
        goto L_0x00476cab;
    }
    // 00476ca4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476ca6  e8f1c40100             -call 0x49319c
    cpu.esp -= 4;
    sub_49319c(app, cpu);
    if (cpu.terminate) return;
L_0x00476cab:
    // 00476cab  8b7130                 -mov esi, dword ptr [ecx + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 00476cae  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00476cb0  751e                   -jne 0x476cd0
    if (!cpu.flags.zf)
    {
        goto L_0x00476cd0;
    }
    // 00476cb2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00476cb4  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 00476cba  e80d1e0000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00476cbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cc0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476cc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476cc4:
    // 00476cc4  b830b15100             -mov eax, 0x51b130
    cpu.eax = 5353776 /*0x51b130*/;
    // 00476cc9  e8bacf0000             -call 0x483c88
    cpu.esp -= 4;
    sub_483c88(app, cpu);
    if (cpu.terminate) return;
    // 00476cce  ebcd                   -jmp 0x476c9d
    goto L_0x00476c9d;
L_0x00476cd0:
    // 00476cd0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00476cd2  e8c5c40100             -call 0x49319c
    cpu.esp -= 4;
    sub_49319c(app, cpu);
    if (cpu.terminate) return;
    // 00476cd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00476cd9  c7016b4e4957           -mov dword ptr [ecx], 0x57494e6b
    app->getMemory<x86::reg32>(cpu.ecx) = 1464421995 /*0x57494e6b*/;
    // 00476cdf  e8e81d0000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00476ce4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ce5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ce6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ce7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ce8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476cf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476cf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00476cf3  7c49                   -jl 0x476d3e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476d3e;
    }
L_0x00476cf5:
    // 00476cf5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00476cf7  7c49                   -jl 0x476d42
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476d42;
    }
L_0x00476cf9:
    // 00476cf9  8b35d4844c00           -mov esi, dword ptr [0x4c84d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014740) /* 0x4c84d4 */);
    // 00476cff  39f0                   +cmp eax, esi
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
    // 00476d01  7e02                   -jle 0x476d05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00476d05;
    }
    // 00476d03  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00476d05:
    // 00476d05  39f3                   +cmp ebx, esi
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
    // 00476d07  7e02                   -jle 0x476d0b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00476d0b;
    }
    // 00476d09  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00476d0b:
    // 00476d0b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00476d0d  7c37                   -jl 0x476d46
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476d46;
    }
L_0x00476d0f:
    // 00476d0f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00476d11  7c37                   -jl 0x476d4a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476d4a;
    }
L_0x00476d13:
    // 00476d13  8b35d8844c00           -mov esi, dword ptr [0x4c84d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014744) /* 0x4c84d8 */);
    // 00476d19  39f2                   +cmp edx, esi
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
    // 00476d1b  7e02                   -jle 0x476d1f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00476d1f;
    }
    // 00476d1d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x00476d1f:
    // 00476d1f  39f1                   +cmp ecx, esi
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
    // 00476d21  7e02                   -jle 0x476d25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00476d25;
    }
    // 00476d23  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00476d25:
    // 00476d25  a3dc844c00             -mov dword ptr [0x4c84dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */) = cpu.eax;
    // 00476d2a  891de4844c00           -mov dword ptr [0x4c84e4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */) = cpu.ebx;
    // 00476d30  8915e0844c00           -mov dword ptr [0x4c84e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */) = cpu.edx;
    // 00476d36  890de8844c00           -mov dword ptr [0x4c84e8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */) = cpu.ecx;
    // 00476d3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476d3e:
    // 00476d3e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00476d40  ebb3                   -jmp 0x476cf5
    goto L_0x00476cf5;
L_0x00476d42:
    // 00476d42  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00476d44  ebb3                   -jmp 0x476cf9
    goto L_0x00476cf9;
L_0x00476d46:
    // 00476d46  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00476d48  ebc5                   -jmp 0x476d0f
    goto L_0x00476d0f;
L_0x00476d4a:
    // 00476d4a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00476d4c  ebc5                   -jmp 0x476d13
    goto L_0x00476d13;
}

/* align: skip 0x00 0x00 */
void Application::sub_476d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476d50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476d51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476d52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476d53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476d54  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476d56  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00476d58  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00476d5a  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00476d5d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476d5f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00476d61  7e10                   -jle 0x476d73
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00476d73;
    }
L_0x00476d63:
    // 00476d63  3b5810                 +cmp ebx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00476d66  7416                   -je 0x476d7e
    if (cpu.flags.zf)
    {
        goto L_0x00476d7e;
    }
    // 00476d68  42                     -inc edx
    (cpu.edx)++;
    // 00476d69  8b6908                 -mov ebp, dword ptr [ecx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00476d6c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00476d6f  39ea                   +cmp edx, ebp
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
    // 00476d71  7cf0                   -jl 0x476d63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00476d63;
    }
L_0x00476d73:
    // 00476d73  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00476d75  7511                   -jne 0x476d88
    if (!cpu.flags.zf)
    {
        goto L_0x00476d88;
    }
    // 00476d77  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476d79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476d7e:
    // 00476d7e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00476d81  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00476d83  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d84  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476d88:
    // 00476d88  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00476d8a  e8e1220000             -call 0x479070
    cpu.esp -= 4;
    sub_479070(app, cpu);
    if (cpu.terminate) return;
    // 00476d8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476d91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476d95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_476d98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476d98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476d99  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476d9b  e8b0ffffff             -call 0x476d50
    cpu.esp -= 4;
    sub_476d50(app, cpu);
    if (cpu.terminate) return;
    // 00476da0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476da1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_476da4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476da4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00476da5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00476daa  e8a1ffffff             -call 0x476d50
    cpu.esp -= 4;
    sub_476d50(app, cpu);
    if (cpu.terminate) return;
    // 00476daf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476db0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_476dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476dc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_476dc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476dc4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476dc5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476dc6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476dc7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476dc8  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00476dcb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476dcd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476dcf  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00476dd1:
    // 00476dd1  80790300               +cmp byte ptr [ecx + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476dd5  750f                   -jne 0x476de6
    if (!cpu.flags.zf)
    {
        goto L_0x00476de6;
    }
    // 00476dd7  83c104                 +add ecx, 4
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
    // 00476dda  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00476ddb  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476ddc  75f3                   -jne 0x476dd1
    if (!cpu.flags.zf)
    {
        goto L_0x00476dd1;
    }
    // 00476dde  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00476de1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476de2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476de3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476de4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476de5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00476de6:
    // 00476de6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00476de8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476ded  e8eead0100             -call 0x491be0
    cpu.esp -= 4;
    sub_491be0(app, cpu);
    if (cpu.terminate) return;
    // 00476df2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476df4  a9000000ff             +test eax, 0xff000000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4278190080 /*0xff000000*/));
    // 00476df9  0f84a8000000           -je 0x476ea7
    if (cpu.flags.zf)
    {
        goto L_0x00476ea7;
    }
    // 00476dff  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 00476e01  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00476e03  8a5903                 -mov bl, byte ptr [ecx + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */);
    // 00476e06  c1ed10                 -shr ebp, 0x10
    cpu.ebp >>= 16 /*0x10*/ % 32;
    // 00476e09  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 00476e0c  28de                   -sub dh, bl
    (cpu.dh) -= x86::reg8(x86::sreg8(cpu.bl));
    // 00476e0e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476e13  8a5902                 -mov bl, byte ptr [ecx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 00476e16  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476e1c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00476e1f  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00476e21  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00476e24  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00476e27  887c240c               -mov byte ptr [esp + 0xc], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bh;
    // 00476e2b  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 00476e2e  88442410               -mov byte ptr [esp + 0x10], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.al;
    // 00476e32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476e34  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 00476e36  88742404               -mov byte ptr [esp + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.dh;
    // 00476e3a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00476e3d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476e3f  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00476e42  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00476e46  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00476e49  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00476e4c  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00476e4f  88542408               -mov byte ptr [esp + 8], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00476e53  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476e59  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00476e5b  0fb66c2410             -movzx ebp, byte ptr [esp + 0x10]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00476e60  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00476e63  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00476e66  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00476e68  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476e6e  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00476e70  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00476e75  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00476e78  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00476e7b  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00476e7e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476e80  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00476e83  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476e87  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00476e89  8844240c               -mov byte ptr [esp + 0xc], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.al;
    // 00476e8d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476e8f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00476e91  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00476e93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00476e95  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00476e98  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00476e9a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00476e9c  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00476e9f  8a54240c               -mov dl, byte ptr [esp + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00476ea3  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00476ea5  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00476ea7:
    // 00476ea7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00476ea9  e8aef6ffff             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00476eae  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00476eb0  83c104                 +add ecx, 4
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
    // 00476eb3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00476eb4  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476eb5  0f8516ffffff           -jne 0x476dd1
    if (!cpu.flags.zf)
    {
        goto L_0x00476dd1;
    }
    // 00476ebb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00476ebe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ebf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ec0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ec1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476ec2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_476ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476ec4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476ec5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476ec6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476ec7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476ec8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00476eca  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476ecc  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00476ece:
    // 00476ece  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00476ed0  81fb00000010           +cmp ebx, 0x10000000
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
    // 00476ed6  7273                   -jb 0x476f4b
    if (cpu.flags.cf)
    {
        goto L_0x00476f4b;
    }
    // 00476ed8  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00476ede  7348                   -jae 0x476f28
    if (!cpu.flags.cf)
    {
        goto L_0x00476f28;
    }
    // 00476ee0  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00476ee3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476ee5  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 00476eea  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 00476eed  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00476eef  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 00476ef5  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 00476ef8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476efa  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00476efd  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00476eff  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00476f01  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00476f04  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476f0a  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00476f0c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00476f0f  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476f11  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476f13  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00476f16  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476f1c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476f1e  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00476f21  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00476f26  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00476f28:
    // 00476f28  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476f2a  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00476f30  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 00476f33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476f35  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00476f38  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 00476f3e  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 00476f41  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00476f44  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00476f46  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476f48  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00476f4b:
    // 00476f4b  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00476f4e  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476f51  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476f52  0f8576ffffff           -jne 0x476ece
    if (!cpu.flags.zf)
    {
        goto L_0x00476ece;
    }
    // 00476f58  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f59  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f5a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476f5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_476f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476f60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476f61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476f62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476f63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476f64  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00476f66  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00476f68  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x00476f6a:
    // 00476f6a  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00476f6c  81fb00000010           +cmp ebx, 0x10000000
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
    // 00476f72  726b                   -jb 0x476fdf
    if (cpu.flags.cf)
    {
        goto L_0x00476fdf;
    }
    // 00476f74  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 00476f7a  7340                   -jae 0x476fbc
    if (!cpu.flags.cf)
    {
        goto L_0x00476fbc;
    }
    // 00476f7c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 00476f7f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00476f81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476f83  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 00476f86  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00476f89  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00476f8b  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 00476f91  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00476f94  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 00476f99  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 00476f9c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476f9e  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 00476fa0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00476fa3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00476fa5  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 00476fa8  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476faa  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 00476fad  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00476fb3  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 00476fb8  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00476fba  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00476fbc:
    // 00476fbc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00476fbe  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 00476fc4  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 00476fc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00476fc9  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00476fcc  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 00476fd2  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 00476fd5  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00476fd8  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00476fda  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00476fdc  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x00476fdf:
    // 00476fdf  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00476fe2  83c704                 +add edi, 4
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00476fe5  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00476fe6  7582                   -jne 0x476f6a
    if (!cpu.flags.zf)
    {
        goto L_0x00476f6a;
    }
    // 00476fe8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476fe9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476fea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476feb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00476fec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_476ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00476ff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00476ff1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00476ff2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00476ff3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00476ff4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00476ff7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00476ff9:
    // 00476ff9  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00476ffd  7511                   -jne 0x477010
    if (!cpu.flags.zf)
    {
        goto L_0x00477010;
    }
L_0x00476fff:
    // 00476fff  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00477002  83c203                 +add edx, 3
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00477005  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00477006  75f1                   -jne 0x476ff9
    if (!cpu.flags.zf)
    {
        goto L_0x00476ff9;
    }
    // 00477008  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047700b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047700c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047700d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047700e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047700f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00477010:
    // 00477010  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00477013  b3ff                   -mov bl, 0xff
    cpu.bl = 255 /*0xff*/;
    // 00477015  8a6a02                 -mov ch, byte ptr [edx + 2]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00477018  8a7803                 -mov bh, byte ptr [eax + 3]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 0047701b  886c2410               -mov byte ptr [esp + 0x10], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ch;
    // 0047701f  28fb                   -sub bl, bh
    (cpu.bl) -= x86::reg8(x86::sreg8(cpu.bh));
    // 00477021  0fb6742410             -movzx esi, byte ptr [esp + 0x10]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 00477026  885c240c               -mov byte ptr [esp + 0xc], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 0047702a  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0047702d  0fb674240c             -movzx esi, byte ptr [esp + 0xc]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00477032  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00477035  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00477038  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047703b  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 0047703e  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00477040  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00477043  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 00477046  8a6a01                 -mov ch, byte ptr [edx + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00477049  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0047704c  886c2408               -mov byte ptr [esp + 8], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ch;
    // 00477050  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00477053  0fb66c2408             -movzx ebp, byte ptr [esp + 8]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */));
    // 00477058  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0047705b  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 0047705d  886c2404               -mov byte ptr [esp + 4], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ch;
    // 00477061  c1fd08                 -sar ebp, 8
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (8 /*0x8*/ % 32));
    // 00477064  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 00477067  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047706d  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047706f  0fb66c2404             -movzx ebp, byte ptr [esp + 4]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */));
    // 00477074  0faff5                 -imul esi, ebp
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00477077  c1fe08                 -sar esi, 8
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (8 /*0x8*/ % 32));
    // 0047707a  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0047707d  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00477080  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 00477083  01f5                   +add ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00477085  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00477088  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 0047708b  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 0047708e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00477091  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
    // 00477093  e967ffffff             -jmp 0x476fff
    goto L_0x00476fff;
}

/* align: skip  */
void Application::sub_477098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477098  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477099  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047709a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047709b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047709c  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047709f  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x004770a1:
    // 004770a1  80780300               +cmp byte ptr [eax + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004770a5  7511                   -jne 0x4770b8
    if (!cpu.flags.zf)
    {
        goto L_0x004770b8;
    }
L_0x004770a7:
    // 004770a7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004770aa  83c204                 +add edx, 4
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
    // 004770ad  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004770ae  75f1                   -jne 0x4770a1
    if (!cpu.flags.zf)
    {
        goto L_0x004770a1;
    }
    // 004770b0  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004770b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004770b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004770b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004770b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004770b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004770b8:
    // 004770b8  8a5802                 -mov bl, byte ptr [eax + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004770bb  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004770be  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 004770c2  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004770c4  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
    // 004770c8  807a0300               +cmp byte ptr [edx + 3], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004770cc  0f84a1000000           -je 0x477173
    if (cpu.flags.zf)
    {
        goto L_0x00477173;
    }
    // 004770d2  b7ff                   -mov bh, 0xff
    cpu.bh = 255 /*0xff*/;
    // 004770d4  2a7803                 -sub bh, byte ptr [eax + 3]
    (cpu.bh) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */)));
    // 004770d7  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004770da  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004770dc  887c2408               -mov byte ptr [esp + 8], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.bh;
    // 004770e0  886c240c               -mov byte ptr [esp + 0xc], ch
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ch;
    // 004770e4  0fb6f9                 -movzx edi, cl
    cpu.edi = x86::reg32(cpu.cl);
    // 004770e7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004770e9  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004770ed  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004770f0  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004770f3  0fb6eb                 -movzx ebp, bl
    cpu.ebp = x86::reg32(cpu.bl);
    // 004770f6  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 004770f9  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004770fb  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004770ff  8a5c2404               -mov bl, byte ptr [esp + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477103  0fb6ff                 -movzx edi, bh
    cpu.edi = x86::reg32(cpu.bh);
    // 00477106  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00477109  0fb66c2414             -movzx ebp, byte ptr [esp + 0x14]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0047710e  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 00477111  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00477113  0fb67c240c             -movzx edi, byte ptr [esp + 0xc]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 00477118  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0047711b  c1ff08                 -sar edi, 8
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (8 /*0x8*/ % 32));
    // 0047711e  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00477122  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00477125  0fb67c2410             -movzx edi, byte ptr [esp + 0x10]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0047712a  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0047712d  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047712f  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00477132  0fb67a03               -movzx edi, byte ptr [edx + 3]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */));
    // 00477136  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 0047713b  29fd                   -sub ebp, edi
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047713d  0fafcd                 -imul ecx, ebp
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00477140  8a7c2404               -mov bh, byte ptr [esp + 4]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00477144  bfff000000             -mov edi, 0xff
    cpu.edi = 255 /*0xff*/;
    // 00477149  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0047714c  887c2414               -mov byte ptr [esp + 0x14], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.bh;
    // 00477150  29cf                   +sub edi, ecx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00477152  8a3c24                 -mov bh, byte ptr [esp]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp);
    // 00477155  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00477157  887c2410               -mov byte ptr [esp + 0x10], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.bh;
L_0x0047715b:
    // 0047715b  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 0047715e  885a02                 -mov byte ptr [edx + 2], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 00477161  8a5c2414               -mov bl, byte ptr [esp + 0x14]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00477165  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00477168  8a5c2410               -mov bl, byte ptr [esp + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047716c  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 0047716e  e934ffffff             -jmp 0x4770a7
    goto L_0x004770a7;
L_0x00477173:
    // 00477173  8a4803                 -mov cl, byte ptr [eax + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00477176  ebe3                   -jmp 0x47715b
    goto L_0x0047715b;
}

/* align: skip  */
void Application::sub_477178(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477178  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477179  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047717a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047717b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047717c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047717e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00477180  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x00477182:
    // 00477182  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00477184  8a5d00                 -mov bl, byte ptr [ebp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebp);
    // 00477187  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0047718e  8b1dacaf5100           -mov ebx, dword ptr [0x51afac]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5353388) /* 0x51afac */);
    // 00477194  8b1c03                 -mov ebx, dword ptr [ebx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00477197  45                     -inc ebp
    (cpu.ebp)++;
    // 00477198  81fb00000010           +cmp ebx, 0x10000000
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
    // 0047719e  7250                   -jb 0x4771f0
    if (cpu.flags.cf)
    {
        goto L_0x004771f0;
    }
    // 004771a0  81fb000000fc           +cmp ebx, 0xfc000000
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
    // 004771a6  7345                   -jae 0x4771ed
    if (!cpu.flags.cf)
    {
        goto L_0x004771ed;
    }
    // 004771a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004771aa  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004771ad  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004771af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004771b1  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004771b4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004771b7  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004771b9  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004771bf  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004771c2  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004771c7  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004771ca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004771cc  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004771ce  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004771d1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004771d3  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004771d6  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004771dc  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004771df  25e0070000             -and eax, 0x7e0
    cpu.eax &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004771e4  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004771e6  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004771e9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004771eb  01cb                   +add ebx, ecx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004771ed:
    // 004771ed  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004771f0:
    // 004771f0  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004771f3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004771f4  758c                   -jne 0x477182
    if (!cpu.flags.zf)
    {
        goto L_0x00477182;
    }
    // 004771f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004771f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004771f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004771f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004771fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4771fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004771fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004771fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004771fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004771ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00477200  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00477206  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00477208  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047720a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047720c  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047720f  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 00477215  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00477217  b97d000000             -mov ecx, 0x7d
    cpu.ecx = 125 /*0x7d*/;
    // 0047721c  891508844c00           -mov dword ptr [0x4c8408], edx
    app->getMemory<x86::reg32>(x86::reg32(5014536) /* 0x4c8408 */) = cpu.edx;
    // 00477222  890d10844c00           -mov dword ptr [0x4c8410], ecx
    app->getMemory<x86::reg32>(x86::reg32(5014544) /* 0x4c8410 */) = cpu.ecx;
    // 00477228  83f808                 +cmp eax, 8
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
    // 0047722b  752c                   -jne 0x477259
    if (!cpu.flags.zf)
    {
        goto L_0x00477259;
    }
    // 0047722d  803dec844c0010         +cmp byte ptr [0x4c84ec], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00477234  7523                   -jne 0x477259
    if (!cpu.flags.zf)
    {
        goto L_0x00477259;
    }
    // 00477236  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00477238  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047723a  bd78714700             -mov ebp, 0x477178
    cpu.ebp = 4682104 /*0x477178*/;
    // 0047723f  e8ccb30100             -call 0x492610
    cpu.esp -= 4;
    sub_492610(app, cpu);
    if (cpu.terminate) return;
    // 00477244  a3acaf5100             -mov dword ptr [0x51afac], eax
    app->getMemory<x86::reg32>(x86::reg32(5353388) /* 0x51afac */) = cpu.eax;
    // 00477249  b87b000000             -mov eax, 0x7b
    cpu.eax = 123 /*0x7b*/;
    // 0047724e  892d08844c00           -mov dword ptr [0x4c8408], ebp
    app->getMemory<x86::reg32>(x86::reg32(5014536) /* 0x4c8408 */) = cpu.ebp;
    // 00477254  a310844c00             -mov dword ptr [0x4c8410], eax
    app->getMemory<x86::reg32>(x86::reg32(5014544) /* 0x4c8410 */) = cpu.eax;
L_0x00477259:
    // 00477259  b9f0834c00             -mov ecx, 0x4c83f0
    cpu.ecx = 5014512 /*0x4c83f0*/;
    // 0047725e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00477260  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00477262  e8b5b90100             -call 0x492c1c
    cpu.esp -= 4;
    sub_492c1c(app, cpu);
    if (cpu.terminate) return;
    // 00477267  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0047726d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047726e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047726f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477270  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00477271  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_477274(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477274  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00477275  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00477276  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00477279  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047727c  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047727f  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 00477282  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 00477285  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 00477288  e86fffffff             -call 0x4771fc
    cpu.esp -= 4;
    sub_4771fc(app, cpu);
    if (cpu.terminate) return;
    // 0047728d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047728e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047728f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_477290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00477290  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00477291  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00477294  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00477297  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00477299  8b4806                 -mov ecx, dword ptr [eax + 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047729c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047729f  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004772a1  e856ffffff             -call 0x4771fc
    cpu.esp -= 4;
    sub_4771fc(app, cpu);
    if (cpu.terminate) return;
    // 004772a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004772a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4772a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004772a8  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 004772ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4772ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004772ae  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004772b0  030524b05100           -add eax, dword ptr [0x51b024]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */)));
    // 004772b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
