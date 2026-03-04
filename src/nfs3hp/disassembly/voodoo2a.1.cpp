#include "voodoo2a.h"
#include <lib/thread.h>

namespace voodoo2a
{

/* align: skip 0x8d 0x40 0x00 */
void sub_a87c08(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87c08  e9a7270000             -jmp 0xa8a3b4
    return sub_a8a3b4(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a87c10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87c10  e9f7280000             -jmp 0xa8a50c
    return sub_a8a50c(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a87c18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87c18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87c19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87c1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a87c1b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a87c1d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a87c1f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a87c21  89357038a900           -mov dword ptr [0xa93870], esi
    app->getMemory<x86::reg32>(x86::reg32(11090032) /* 0xa93870 */) = cpu.esi;
    // 00a87c27  e8d00b0000             -call 0xa887fc
    cpu.esp -= 4;
    sub_a887fc(app, cpu);
    if (cpu.terminate) return;
    // 00a87c2c  a37c38a900             -mov dword ptr [0xa9387c], eax
    app->getMemory<x86::reg32>(x86::reg32(11090044) /* 0xa9387c */) = cpu.eax;
    // 00a87c31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a87c33  7511                   -jne 0xa87c46
    if (!cpu.flags.zf)
    {
        goto L_0x00a87c46;
    }
    // 00a87c35  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a87c37  0f8505020000           -jne 0xa87e42
    if (!cpu.flags.zf)
    {
        goto L_0x00a87e42;
    }
    // 00a87c3d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a87c3f  2eff158003a900         -call dword ptr cs:[0xa90380]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076480) /* 0xa90380 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a87c46:
    // 00a87c46  e8f5280000             -call 0xa8a540
    cpu.esp -= 4;
    sub_a8a540(app, cpu);
    if (cpu.terminate) return;
    // 00a87c4b  2eff15b403a900         -call dword ptr cs:[0xa903b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076532) /* 0xa903b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87c52  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a87c54  a37d27a900             -mov dword ptr [0xa9277d], eax
    app->getMemory<x86::reg32>(x86::reg32(11085693) /* 0xa9277d */) = cpu.eax;
    // 00a87c59  8915a43ea900           -mov dword ptr [0xa93ea4], edx
    app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */) = cpu.edx;
    // 00a87c5f  2eff15e003a900         -call dword ptr cs:[0xa903e0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076576) /* 0xa903e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87c66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a87c68  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a87c6a  a28327a900             -mov byte ptr [0xa92783], al
    app->getMemory<x86::reg8>(x86::reg32(11085699) /* 0xa92783 */) = cpu.al;
    // 00a87c6f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a87c72  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a87c77  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a87c7c  66a38527a900           -mov word ptr [0xa92785], ax
    app->getMemory<x86::reg16>(x86::reg32(11085701) /* 0xa92785 */) = cpu.ax;
    // 00a87c82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a87c84  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a87c8a  66a18527a900           -mov ax, word ptr [0xa92785]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(11085701) /* 0xa92785 */);
    // 00a87c90  688038a900             -push 0xa93880
    app->getMemory<x86::reg32>(cpu.esp-4) = 11090048 /*0xa93880*/;
    cpu.esp -= 4;
    // 00a87c95  a38727a900             -mov dword ptr [0xa92787], eax
    app->getMemory<x86::reg32>(x86::reg32(11085703) /* 0xa92787 */) = cpu.eax;
    // 00a87c9a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a87c9c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00a87c9f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a87ca1  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a87ca7  a38b27a900             -mov dword ptr [0xa9278b], eax
    app->getMemory<x86::reg32>(x86::reg32(11085707) /* 0xa9278b */) = cpu.eax;
    // 00a87cac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a87cae  88158427a900           -mov byte ptr [0xa92784], dl
    app->getMemory<x86::reg8>(x86::reg32(11085700) /* 0xa92784 */) = cpu.dl;
    // 00a87cb4  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a87cb6  8b158b27a900           -mov edx, dword ptr [0xa9278b]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085707) /* 0xa9278b */);
    // 00a87cbc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a87cbe  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a87cc1  bb8038a900             -mov ebx, 0xa93880
    cpu.ebx = 11090048 /*0xa93880*/;
    // 00a87cc6  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a87cc8  a38f27a900             -mov dword ptr [0xa9278f], eax
    app->getMemory<x86::reg32>(x86::reg32(11085711) /* 0xa9278f */) = cpu.eax;
    // 00a87ccd  89159327a900           -mov dword ptr [0xa92793], edx
    app->getMemory<x86::reg32>(x86::reg32(11085715) /* 0xa92793 */) = cpu.edx;
    // 00a87cd3  2eff15c803a900         -call dword ptr cs:[0xa903c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076552) /* 0xa903c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87cda  ba8439a900             -mov edx, 0xa93984
    cpu.edx = 11090308 /*0xa93984*/;
    // 00a87cdf  891d4427a900           -mov dword ptr [0xa92744], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085636) /* 0xa92744 */) = cpu.ebx;
    // 00a87ce5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a87ce7  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a87cec  b98439a900             -mov ecx, 0xa93984
    cpu.ecx = 11090308 /*0xa93984*/;
    // 00a87cf1  e8fa280000             -call 0xa8a5f0
    cpu.esp -= 4;
    sub_a8a5f0(app, cpu);
    if (cpu.terminate) return;
    // 00a87cf6  890d5027a900           -mov dword ptr [0xa92750], ecx
    app->getMemory<x86::reg32>(x86::reg32(11085648) /* 0xa92750 */) = cpu.ecx;
    // 00a87cfc  2eff159c03a900         -call dword ptr cs:[0xa9039c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076508) /* 0xa9039c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87d03  e888290000             -call 0xa8a690
    cpu.esp -= 4;
    sub_a8a690(app, cpu);
    if (cpu.terminate) return;
    // 00a87d08  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a87d0a  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a87d0c  a37438a900             -mov dword ptr [0xa93874], eax
    app->getMemory<x86::reg32>(x86::reg32(11090036) /* 0xa93874 */) = cpu.eax;
    // 00a87d11  80fb22                 +cmp bl, 0x22
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87d14  751e                   -jne 0xa87d34
    if (!cpu.flags.zf)
    {
        goto L_0x00a87d34;
    }
    // 00a87d16  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a87d19  40                     -inc eax
    (cpu.eax)++;
    // 00a87d1a  38df                   +cmp bh, bl
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87d1c  740e                   -je 0xa87d2c
    if (cpu.flags.zf)
    {
        goto L_0x00a87d2c;
    }
L_0x00a87d1e:
    // 00a87d1e  803800                 +cmp byte ptr [eax], 0
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
    // 00a87d21  7409                   -je 0xa87d2c
    if (cpu.flags.zf)
    {
        goto L_0x00a87d2c;
    }
    // 00a87d23  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a87d26  40                     -inc eax
    (cpu.eax)++;
    // 00a87d27  80fa22                 +cmp dl, 0x22
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87d2a  75f2                   -jne 0xa87d1e
    if (!cpu.flags.zf)
    {
        goto L_0x00a87d1e;
    }
L_0x00a87d2c:
    // 00a87d2c  803800                 +cmp byte ptr [eax], 0
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
    // 00a87d2f  741e                   -je 0xa87d4f
    if (cpu.flags.zf)
    {
        goto L_0x00a87d4f;
    }
    // 00a87d31  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a87d32  eb1b                   -jmp 0xa87d4f
    goto L_0x00a87d4f;
L_0x00a87d34:
    // 00a87d34  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a87d36  fec2                   -inc dl
    (cpu.dl)++;
    // 00a87d38  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a87d3e  f6827825a90002         +test byte ptr [edx + 0xa92578], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11085176) /* 0xa92578 */) & 2 /*0x2*/));
    // 00a87d45  7508                   -jne 0xa87d4f
    if (!cpu.flags.zf)
    {
        goto L_0x00a87d4f;
    }
    // 00a87d47  803800                 +cmp byte ptr [eax], 0
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
    // 00a87d4a  7403                   -je 0xa87d4f
    if (cpu.flags.zf)
    {
        goto L_0x00a87d4f;
    }
    // 00a87d4c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a87d4d  ebe5                   -jmp 0xa87d34
    goto L_0x00a87d34;
L_0x00a87d4f:
    // 00a87d4f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a87d51  fec2                   -inc dl
    (cpu.dl)++;
    // 00a87d53  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a87d59  f6827825a90002         +test byte ptr [edx + 0xa92578], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11085176) /* 0xa92578 */) & 2 /*0x2*/));
    // 00a87d60  7403                   -je 0xa87d65
    if (cpu.flags.zf)
    {
        goto L_0x00a87d65;
    }
    // 00a87d62  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a87d63  ebea                   -jmp 0xa87d4f
    goto L_0x00a87d4f;
L_0x00a87d65:
    // 00a87d65  a34027a900             -mov dword ptr [0xa92740], eax
    app->getMemory<x86::reg32>(x86::reg32(11085632) /* 0xa92740 */) = cpu.eax;
    // 00a87d6a  2eff15a003a900         -call dword ptr cs:[0xa903a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076512) /* 0xa903a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87d71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a87d73  0f847d000000           -je 0xa87df6
    if (cpu.flags.zf)
    {
        goto L_0x00a87df6;
    }
    // 00a87d79  e862290000             -call 0xa8a6e0
    cpu.esp -= 4;
    sub_a8a6e0(app, cpu);
    if (cpu.terminate) return;
    // 00a87d7e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a87d80  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a87d83  a37838a900             -mov dword ptr [0xa93878], eax
    app->getMemory<x86::reg32>(x86::reg32(11090040) /* 0xa93878 */) = cpu.eax;
    // 00a87d88  6683fb22               +cmp bx, 0x22
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a87d8c  752a                   -jne 0xa87db8
    if (!cpu.flags.zf)
    {
        goto L_0x00a87db8;
    }
    // 00a87d8e  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a87d92  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a87d95  6639d9                 +cmp cx, bx
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a87d98  7413                   -je 0xa87dad
    if (cpu.flags.zf)
    {
        goto L_0x00a87dad;
    }
L_0x00a87d9a:
    // 00a87d9a  66833800               +cmp word ptr [eax], 0
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
    // 00a87d9e  740d                   -je 0xa87dad
    if (cpu.flags.zf)
    {
        goto L_0x00a87dad;
    }
    // 00a87da0  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a87da4  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a87da7  6683fb22               +cmp bx, 0x22
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a87dab  75ed                   -jne 0xa87d9a
    if (!cpu.flags.zf)
    {
        goto L_0x00a87d9a;
    }
L_0x00a87dad:
    // 00a87dad  66833800               +cmp word ptr [eax], 0
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
    // 00a87db1  7427                   -je 0xa87dda
    if (cpu.flags.zf)
    {
        goto L_0x00a87dda;
    }
    // 00a87db3  83c002                 +add eax, 2
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
    // 00a87db6  eb22                   -jmp 0xa87dda
    goto L_0x00a87dda;
L_0x00a87db8:
    // 00a87db8  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x00a87dbd:
    // 00a87dbd  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a87dbf  fec2                   -inc dl
    (cpu.dl)++;
    // 00a87dc1  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a87dc7  849a7825a900           -test byte ptr [edx + 0xa92578], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11085176) /* 0xa92578 */) & cpu.bl));
    // 00a87dcd  750b                   -jne 0xa87dda
    if (!cpu.flags.zf)
    {
        goto L_0x00a87dda;
    }
    // 00a87dcf  66833800               +cmp word ptr [eax], 0
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
    // 00a87dd3  7405                   -je 0xa87dda
    if (cpu.flags.zf)
    {
        goto L_0x00a87dda;
    }
    // 00a87dd5  83c002                 +add eax, 2
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
    // 00a87dd8  ebe3                   -jmp 0xa87dbd
    goto L_0x00a87dbd;
L_0x00a87dda:
    // 00a87dda  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x00a87ddf:
    // 00a87ddf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a87de1  fec2                   -inc dl
    (cpu.dl)++;
    // 00a87de3  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a87de9  849a7825a900           -test byte ptr [edx + 0xa92578], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11085176) /* 0xa92578 */) & cpu.bl));
    // 00a87def  740a                   -je 0xa87dfb
    if (cpu.flags.zf)
    {
        goto L_0x00a87dfb;
    }
    // 00a87df1  83c002                 +add eax, 2
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
    // 00a87df4  ebe9                   -jmp 0xa87ddf
    goto L_0x00a87ddf;
L_0x00a87df6:
    // 00a87df6  b82817a900             -mov eax, 0xa91728
    cpu.eax = 11081512 /*0xa91728*/;
L_0x00a87dfb:
    // 00a87dfb  a34c27a900             -mov dword ptr [0xa9274c], eax
    app->getMemory<x86::reg32>(x86::reg32(11085644) /* 0xa9274c */) = cpu.eax;
    // 00a87e00  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a87e02  7439                   -je 0xa87e3d
    if (cpu.flags.zf)
    {
        goto L_0x00a87e3d;
    }
    // 00a87e04  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a87e09  688c3ba900             -push 0xa93b8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11090828 /*0xa93b8c*/;
    cpu.esp -= 4;
    // 00a87e0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a87e0f  be8c3ba900             -mov esi, 0xa93b8c
    cpu.esi = 11090828 /*0xa93b8c*/;
    // 00a87e14  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a87e19  2eff15c803a900         -call dword ptr cs:[0xa903c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076552) /* 0xa903c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87e20  ba903ca900             -mov edx, 0xa93c90
    cpu.edx = 11091088 /*0xa93c90*/;
    // 00a87e25  89354827a900           -mov dword ptr [0xa92748], esi
    app->getMemory<x86::reg32>(x86::reg32(11085640) /* 0xa92748 */) = cpu.esi;
    // 00a87e2b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a87e2d  bf903ca900             -mov edi, 0xa93c90
    cpu.edi = 11091088 /*0xa93c90*/;
    // 00a87e32  e8b9270000             -call 0xa8a5f0
    cpu.esp -= 4;
    sub_a8a5f0(app, cpu);
    if (cpu.terminate) return;
    // 00a87e37  893d5427a900           -mov dword ptr [0xa92754], edi
    app->getMemory<x86::reg32>(x86::reg32(11085652) /* 0xa92754 */) = cpu.edi;
L_0x00a87e3d:
    // 00a87e3d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a87e42:
    // 00a87e42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87e43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87e44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87e45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a87e48(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87e48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87e49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87e4a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87e4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a87e4c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a87e4e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a87e50  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a87e52  2eff15d003a900         -call dword ptr cs:[0xa903d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076560) /* 0xa903d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87e59  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a87e5b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a87e5d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a87e5f  e8b4fdffff             -call 0xa87c18
    cpu.esp -= 4;
    sub_a87c18(app, cpu);
    if (cpu.terminate) return;
    // 00a87e64  ba6027a900             -mov edx, 0xa92760
    cpu.edx = 11085664 /*0xa92760*/;
    // 00a87e69  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87e6f  e89c280000             -call 0xa8a710
    cpu.esp -= 4;
    sub_a8a710(app, cpu);
    if (cpu.terminate) return;
    // 00a87e74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a87e76  e8452d0000             -call 0xa8abc0
    cpu.esp -= 4;
    sub_a8abc0(app, cpu);
    if (cpu.terminate) return;
    // 00a87e7b  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00a87e80  e8a7000000             -call 0xa87f2c
    cpu.esp -= 4;
    sub_a87f2c(app, cpu);
    if (cpu.terminate) return;
    // 00a87e85  ff15e826a900           -call dword ptr [0xa926e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085544) /* 0xa926e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87e8b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00a87e90  e897000000             -call 0xa87f2c
    cpu.esp -= 4;
    sub_a87f2c(app, cpu);
    if (cpu.terminate) return;
    // 00a87e95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87e96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87e97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87e98  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87e99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a87e9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87e9c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a87e9e  833d7038a90000         +cmp dword ptr [0xa93870], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11090032) /* 0xa93870 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87ea5  7418                   -je 0xa87ebf
    if (cpu.flags.zf)
    {
        goto L_0x00a87ebf;
    }
    // 00a87ea7  833df026a90000         +cmp dword ptr [0xa926f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085552) /* 0xa926f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87eae  7426                   -je 0xa87ed6
    if (cpu.flags.zf)
    {
        goto L_0x00a87ed6;
    }
    // 00a87eb0  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a87eb5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a87eb7  ff15f026a900           -call dword ptr [0xa926f0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085552) /* 0xa926f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87ebd  eb17                   -jmp 0xa87ed6
    goto L_0x00a87ed6;
L_0x00a87ebf:
    // 00a87ebf  e8482d0000             -call 0xa8ac0c
    cpu.esp -= 4;
    sub_a8ac0c(app, cpu);
    if (cpu.terminate) return;
    // 00a87ec4  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a87ec9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a87ecb  e8ac000000             -call 0xa87f7c
    cpu.esp -= 4;
    sub_a87f7c(app, cpu);
    if (cpu.terminate) return;
    // 00a87ed0  ff15e426a900           -call dword ptr [0xa926e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085540) /* 0xa926e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a87ed6:
    // 00a87ed6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87ed7  2eff158003a900         -call dword ptr cs:[0xa90380]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076480) /* 0xa90380 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a87ede  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a87ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87ee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a87ee3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87ee4  8b157438a900           -mov edx, dword ptr [0xa93874]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11090036) /* 0xa93874 */);
    // 00a87eea  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a87eec  740f                   -je 0xa87efd
    if (cpu.flags.zf)
    {
        goto L_0x00a87efd;
    }
    // 00a87eee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a87ef0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a87ef2  e8a9eeffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a87ef7  891d7438a900           -mov dword ptr [0xa93874], ebx
    app->getMemory<x86::reg32>(x86::reg32(11090036) /* 0xa93874 */) = cpu.ebx;
L_0x00a87efd:
    // 00a87efd  8b0d7838a900           -mov ecx, dword ptr [0xa93878]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11090040) /* 0xa93878 */);
    // 00a87f03  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a87f05  740f                   -je 0xa87f16
    if (cpu.flags.zf)
    {
        goto L_0x00a87f16;
    }
    // 00a87f07  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a87f09  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a87f0b  e890eeffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a87f10  89357838a900           -mov dword ptr [0xa93878], esi
    app->getMemory<x86::reg32>(x86::reg32(11090040) /* 0xa93878 */) = cpu.esi;
L_0x00a87f16:
    // 00a87f16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87f17  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87f18  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87f19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87f1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a87f20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87f20  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a87f21  833800                 +cmp dword ptr [eax], 0
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
    // 00a87f24  7404                   -je 0xa87f2a
    if (cpu.flags.zf)
    {
        goto L_0x00a87f2a;
    }
    // 00a87f26  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a87f27  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a87f28  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a87f2a:
    // 00a87f2a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a87f2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a87f2c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87f2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87f2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87f2e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a87f2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87f30  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a87f31  be742da900             -mov esi, 0xa92d74
    cpu.esi = 11087220 /*0xa92d74*/;
    // 00a87f36  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x00a87f38:
    // 00a87f38  b8442da900             -mov eax, 0xa92d44
    cpu.eax = 11087172 /*0xa92d44*/;
    // 00a87f3d  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a87f3f  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00a87f41  39c6                   +cmp esi, eax
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
    // 00a87f43  761a                   -jbe 0xa87f5f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a87f5f;
    }
L_0x00a87f45:
    // 00a87f45  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87f48  740b                   -je 0xa87f55
    if (cpu.flags.zf)
    {
        goto L_0x00a87f55;
    }
    // 00a87f4a  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a87f4d  38ea                   +cmp dl, ch
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87f4f  7204                   -jb 0xa87f55
    if (cpu.flags.cf)
    {
        goto L_0x00a87f55;
    }
    // 00a87f51  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a87f53  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a87f55:
    // 00a87f55  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00a87f58  3d742da900             +cmp eax, 0xa92d74
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11087220 /*0xa92d74*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87f5d  72e6                   -jb 0xa87f45
    if (cpu.flags.cf)
    {
        goto L_0x00a87f45;
    }
L_0x00a87f5f:
    // 00a87f5f  81fb742da900           +cmp ebx, 0xa92d74
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11087220 /*0xa92d74*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87f65  740d                   -je 0xa87f74
    if (cpu.flags.zf)
    {
        goto L_0x00a87f74;
    }
    // 00a87f67  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a87f6a  e8b1ffffff             -call 0xa87f20
    cpu.esp -= 4;
    sub_a87f20(app, cpu);
    if (cpu.terminate) return;
    // 00a87f6f  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a87f72  ebc4                   -jmp 0xa87f38
    goto L_0x00a87f38;
L_0x00a87f74:
    // 00a87f74  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a87f75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87f76  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87f77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87f78  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87f79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a87f7c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87f7c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a87f7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87f7e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a87f7f  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a87f80  be442da900             -mov esi, 0xa92d44
    cpu.esi = 11087172 /*0xa92d44*/;
    // 00a87f85  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a87f87  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x00a87f89:
    // 00a87f89  b81a2da900             -mov eax, 0xa92d1a
    cpu.eax = 11087130 /*0xa92d1a*/;
    // 00a87f8e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a87f90  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00a87f92  39c6                   +cmp esi, eax
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
    // 00a87f94  761a                   -jbe 0xa87fb0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a87fb0;
    }
L_0x00a87f96:
    // 00a87f96  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87f99  740b                   -je 0xa87fa6
    if (cpu.flags.zf)
    {
        goto L_0x00a87fa6;
    }
    // 00a87f9b  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a87f9e  38ea                   +cmp dl, ch
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87fa0  7704                   -ja 0xa87fa6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a87fa6;
    }
    // 00a87fa2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a87fa4  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a87fa6:
    // 00a87fa6  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00a87fa9  3d442da900             +cmp eax, 0xa92d44
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11087172 /*0xa92d44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87fae  72e6                   -jb 0xa87f96
    if (cpu.flags.cf)
    {
        goto L_0x00a87f96;
    }
L_0x00a87fb0:
    // 00a87fb0  81fb442da900           +cmp ebx, 0xa92d44
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11087172 /*0xa92d44*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a87fb6  7412                   -je 0xa87fca
    if (cpu.flags.zf)
    {
        goto L_0x00a87fca;
    }
    // 00a87fb8  3a7301                 +cmp dh, byte ptr [ebx + 1]
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a87fbb  7208                   -jb 0xa87fc5
    if (cpu.flags.cf)
    {
        goto L_0x00a87fc5;
    }
    // 00a87fbd  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a87fc0  e85bffffff             -call 0xa87f20
    cpu.esp -= 4;
    sub_a87f20(app, cpu);
    if (cpu.terminate) return;
L_0x00a87fc5:
    // 00a87fc5  c60302                 -mov byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a87fc8  ebbf                   -jmp 0xa87f89
    goto L_0x00a87f89;
L_0x00a87fca:
    // 00a87fca  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a87fcb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87fcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87fcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87fce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a87fd0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a87fd0  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a87fd2  742c                   -je 0xa88000
    if (cpu.flags.zf)
    {
        goto L_0x00a88000;
    }
    // 00a87fd4  3810                   -cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x00a87fd6:
    // 00a87fd6  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 00a87fd8  7409                   -je 0xa87fe3
    if (cpu.flags.zf)
    {
        goto L_0x00a87fe3;
    }
    // 00a87fda  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a87fdc  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a87fdd  c1ca08                 +ror edx, 8
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
    // 00a87fe0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a87fe1  75f3                   -jne 0xa87fd6
    if (!cpu.flags.zf)
    {
        goto L_0x00a87fd6;
    }
L_0x00a87fe3:
    // 00a87fe3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a87fe4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a87fe7  e81b000000             -call 0xa88007
    cpu.esp -= 4;
    sub_a88007(app, cpu);
    if (cpu.terminate) return;
    // 00a87fec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a87fed  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a87ff0  740e                   -je 0xa88000
    if (cpu.flags.zf)
    {
        goto L_0x00a88000;
    }
    // 00a87ff2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a87ff4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a87ff5  7409                   -je 0xa88000
    if (cpu.flags.zf)
    {
        goto L_0x00a88000;
    }
    // 00a87ff7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 00a87ffa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a87ffb  7403                   -je 0xa88000
    if (cpu.flags.zf)
    {
        goto L_0x00a88000;
    }
    // 00a87ffd  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x00a88000:
    // 00a88000  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a88002(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88002  90                     -nop 
    ;
    // 00a88003  90                     -nop 
    ;
    // 00a88004  90                     -nop 
    ;
    // 00a88005  90                     -nop 
    ;
    // 00a88006  90                     -nop 
    ;
    // 00a88007  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a88009  7467                   -je 0xa88072
    if (cpu.flags.zf)
    {
        goto L_0x00a88072;
    }
L_0x00a8800b:
    // 00a8800b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00a8800d  7408                   -je 0xa88017
    if (cpu.flags.zf)
    {
        goto L_0x00a88017;
    }
    // 00a8800f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a88011  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a88014  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88015  75f4                   -jne 0xa8800b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8800b;
    }
L_0x00a88017:
    // 00a88017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88018  c1e902                 +shr ecx, 2
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
    // 00a8801b  743a                   -je 0xa88057
    if (cpu.flags.zf)
    {
        goto L_0x00a88057;
    }
    // 00a8801d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8801e  7429                   -je 0xa88049
    if (cpu.flags.zf)
    {
        goto L_0x00a88049;
    }
L_0x00a88020:
    // 00a88020  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a88022  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a88025  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88026  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a88029  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a8802c  7418                   -je 0xa88046
    if (cpu.flags.zf)
    {
        goto L_0x00a88046;
    }
    // 00a8802e  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88031  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a88034  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a88037  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88038  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a8803b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a8803e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a88041  75dd                   -jne 0xa88020
    if (!cpu.flags.zf)
    {
        goto L_0x00a88020;
    }
    // 00a88043  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00a88046:
    // 00a88046  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a88049:
    // 00a88049  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8804b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8804e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a88051  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a88054  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a88057:
    // 00a88057  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88058  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a8805b  7415                   -je 0xa88072
    if (cpu.flags.zf)
    {
        goto L_0x00a88072;
    }
    // 00a8805d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8805f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a88062  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88063  740d                   -je 0xa88072
    if (cpu.flags.zf)
    {
        goto L_0x00a88072;
    }
    // 00a88065  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a88067  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8806a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8806b  7405                   -je 0xa88072
    if (cpu.flags.zf)
    {
        goto L_0x00a88072;
    }
    // 00a8806d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8806f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00a88072:
    // 00a88072  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88007(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a88007;
    // 00a88002  90                     -nop 
    ;
    // 00a88003  90                     -nop 
    ;
    // 00a88004  90                     -nop 
    ;
    // 00a88005  90                     -nop 
    ;
    // 00a88006  90                     -nop 
    ;
L_entry_0x00a88007:
    // 00a88007  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a88009  7467                   -je 0xa88072
    if (cpu.flags.zf)
    {
        goto L_0x00a88072;
    }
L_0x00a8800b:
    // 00a8800b  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00a8800d  7408                   -je 0xa88017
    if (cpu.flags.zf)
    {
        goto L_0x00a88017;
    }
    // 00a8800f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a88011  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a88014  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88015  75f4                   -jne 0xa8800b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8800b;
    }
L_0x00a88017:
    // 00a88017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88018  c1e902                 +shr ecx, 2
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
    // 00a8801b  743a                   -je 0xa88057
    if (cpu.flags.zf)
    {
        goto L_0x00a88057;
    }
    // 00a8801d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8801e  7429                   -je 0xa88049
    if (cpu.flags.zf)
    {
        goto L_0x00a88049;
    }
L_0x00a88020:
    // 00a88020  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a88022  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a88025  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88026  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a88029  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a8802c  7418                   -je 0xa88046
    if (cpu.flags.zf)
    {
        goto L_0x00a88046;
    }
    // 00a8802e  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88031  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a88034  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a88037  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88038  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a8803b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a8803e  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a88041  75dd                   -jne 0xa88020
    if (!cpu.flags.zf)
    {
        goto L_0x00a88020;
    }
    // 00a88043  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00a88046:
    // 00a88046  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a88049:
    // 00a88049  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8804b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8804e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a88051  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a88054  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a88057:
    // 00a88057  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88058  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a8805b  7415                   -je 0xa88072
    if (cpu.flags.zf)
    {
        goto L_0x00a88072;
    }
    // 00a8805d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8805f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a88062  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88063  740d                   -je 0xa88072
    if (cpu.flags.zf)
    {
        goto L_0x00a88072;
    }
    // 00a88065  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a88067  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8806a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8806b  7405                   -je 0xa88072
    if (cpu.flags.zf)
    {
        goto L_0x00a88072;
    }
    // 00a8806d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8806f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00a88072:
    // 00a88072  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88080(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88080  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88082  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a88084  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a88086  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a88088  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8808a  763c                   -jbe 0xa880c8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a880c8;
    }
L_0x00a8808c:
    // 00a8808c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8808e  e8dd2c0000             -call 0xa8ad70
    cpu.esp -= 4;
    sub_a8ad70(app, cpu);
    if (cpu.terminate) return;
    // 00a88093  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88095  7531                   -jne 0xa880c8
    if (!cpu.flags.zf)
    {
        goto L_0x00a880c8;
    }
    // 00a88097  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a88099  e8d22c0000             -call 0xa8ad70
    cpu.esp -= 4;
    sub_a8ad70(app, cpu);
    if (cpu.terminate) return;
    // 00a8809e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a880a0  7526                   -jne 0xa880c8
    if (!cpu.flags.zf)
    {
        goto L_0x00a880c8;
    }
    // 00a880a2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a880a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a880a6  e8052d0000             -call 0xa8adb0
    cpu.esp -= 4;
    sub_a8adb0(app, cpu);
    if (cpu.terminate) return;
    // 00a880ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a880ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a880af  753d                   -jne 0xa880ee
    if (!cpu.flags.zf)
    {
        goto L_0x00a880ee;
    }
    // 00a880b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a880b3  e8582d0000             -call 0xa8ae10
    cpu.esp -= 4;
    sub_a8ae10(app, cpu);
    if (cpu.terminate) return;
    // 00a880b8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a880ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a880bc  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a880bd  e84e2d0000             -call 0xa8ae10
    cpu.esp -= 4;
    sub_a8ae10(app, cpu);
    if (cpu.terminate) return;
    // 00a880c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a880c4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a880c6  77c4                   -ja 0xa8808c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8808c;
    }
L_0x00a880c8:
    // 00a880c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a880ca  7620                   -jbe 0xa880ec
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a880ec;
    }
    // 00a880cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a880ce  e89d2c0000             -call 0xa8ad70
    cpu.esp -= 4;
    sub_a8ad70(app, cpu);
    if (cpu.terminate) return;
    // 00a880d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a880d5  750b                   -jne 0xa880e2
    if (!cpu.flags.zf)
    {
        goto L_0x00a880e2;
    }
    // 00a880d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a880d9  e8922c0000             -call 0xa8ad70
    cpu.esp -= 4;
    sub_a8ad70(app, cpu);
    if (cpu.terminate) return;
    // 00a880de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a880e0  740a                   -je 0xa880ec
    if (cpu.flags.zf)
    {
        goto L_0x00a880ec;
    }
L_0x00a880e2:
    // 00a880e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a880e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a880e6  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a880e8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a880ea  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a880ec:
    // 00a880ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a880ee:
    // 00a880ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a880ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a880f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88100(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88101  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88102  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88103  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88104  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a88106  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88108  0f849a000000           -je 0xa881a8
    if (cpu.flags.zf)
    {
        goto L_0x00a881a8;
    }
    // 00a8810e  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a88111  39c1                   +cmp ecx, eax
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
    // 00a88113  0f828f000000           -jb 0xa881a8
    if (cpu.flags.cf)
    {
        goto L_0x00a881a8;
    }
    // 00a88119  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8811b  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a8811e  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00a88121  83f910                 +cmp ecx, 0x10
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
    // 00a88124  7305                   -jae 0xa8812b
    if (!cpu.flags.cf)
    {
        goto L_0x00a8812b;
    }
    // 00a88126  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x00a8812b:
    // 00a8812b  39c1                   +cmp ecx, eax
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
    // 00a8812d  0f8775000000           -ja 0xa881a8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a881a8;
    }
    // 00a88133  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00a88136  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00a88139  39d9                   +cmp ecx, ebx
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
    // 00a8813b  7705                   -ja 0xa88142
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a88142;
    }
    // 00a8813d  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a88140  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a88142:
    // 00a88142  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00a88145:
    // 00a88145  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a88147  39d1                   +cmp ecx, edx
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
    // 00a88149  7612                   -jbe 0xa8815d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8815d;
    }
    // 00a8814b  39da                   +cmp edx, ebx
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
    // 00a8814d  7602                   -jbe 0xa88151
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a88151;
    }
    // 00a8814f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00a88151:
    // 00a88151  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a88154  39f0                   +cmp eax, esi
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
    // 00a88156  75ed                   -jne 0xa88145
    if (!cpu.flags.zf)
    {
        goto L_0x00a88145;
    }
    // 00a88158  895f14                 -mov dword ptr [edi + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00a8815b  eb4b                   -jmp 0xa881a8
    goto L_0x00a881a8;
L_0x00a8815d:
    // 00a8815d  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a88160  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00a88163  43                     -inc ebx
    (cpu.ebx)++;
    // 00a88164  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a88166  895f18                 -mov dword ptr [edi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a88169  83fa10                 +cmp edx, 0x10
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
    // 00a8816c  721e                   -jb 0xa8818c
    if (cpu.flags.cf)
    {
        goto L_0x00a8818c;
    }
    // 00a8816e  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00a88171  895f0c                 -mov dword ptr [edi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a88174  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a88176  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a88178  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8817b  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a8817e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a88181  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a88184  895908                 -mov dword ptr [ecx + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a88187  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a8818a  eb12                   -jmp 0xa8819e
    goto L_0x00a8819e;
L_0x00a8818c:
    // 00a8818c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 00a8818f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a88192  89570c                 -mov dword ptr [edi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a88195  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a88198  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a8819b  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a8819e:
    // 00a8819e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a881a0  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a881a3  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a881a6  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a881a8:
    // 00a881a8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a881aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a881ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a881ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a881ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a881ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a881b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a881b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a881b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a881b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a881b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a881b4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a881b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a881b8  0f841d010000           -je 0xa882db
    if (cpu.flags.zf)
    {
        goto L_0x00a882db;
    }
    // 00a881be  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a881c1  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 00a881c4  0f8411010000           -je 0xa882db
    if (cpu.flags.zf)
    {
        goto L_0x00a882db;
    }
    // 00a881ca  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a881cc  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a881cf  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00a881d2  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a881d4  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a881d7  7522                   -jne 0xa881fb
    if (!cpu.flags.zf)
    {
        goto L_0x00a881fb;
    }
    // 00a881d9  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a881db  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a881dd  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a881df  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a881e2  7503                   -jne 0xa881e7
    if (!cpu.flags.zf)
    {
        goto L_0x00a881e7;
    }
    // 00a881e4  89590c                 -mov dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00a881e7:
    // 00a881e7  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a881ea  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a881ed  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a881f0  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a881f3  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a881f6  e994000000             -jmp 0xa8828f
    goto L_0x00a8828f;
L_0x00a881fb:
    // 00a881fb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a881fd  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a88200  39c3                   +cmp ebx, eax
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
    // 00a88202  7316                   -jae 0xa8821a
    if (!cpu.flags.cf)
    {
        goto L_0x00a8821a;
    }
    // 00a88204  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a88207  0f8782000000           -ja 0xa8828f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8828f;
    }
    // 00a8820d  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00a88210  39c3                   +cmp ebx, eax
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
    // 00a88212  0f8277000000           -jb 0xa8828f
    if (cpu.flags.cf)
    {
        goto L_0x00a8828f;
    }
    // 00a88218  eb19                   -jmp 0xa88233
    goto L_0x00a88233;
L_0x00a8821a:
    // 00a8821a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8821d  39c3                   +cmp ebx, eax
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
    // 00a8821f  0f826a000000           -jb 0xa8828f
    if (cpu.flags.cf)
    {
        goto L_0x00a8828f;
    }
    // 00a88225  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a88228  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8822b  39d3                   +cmp ebx, edx
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
    // 00a8822d  0f875c000000           -ja 0xa8828f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8828f;
    }
L_0x00a88233:
    // 00a88233  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a88236  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a88239  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8823b  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a8823e  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a88240  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a88242  39f8                   +cmp eax, edi
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
    // 00a88244  7328                   -jae 0xa8826e
    if (!cpu.flags.cf)
    {
        goto L_0x00a8826e;
    }
    // 00a88246  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a88249  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8824b  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8824d  39f8                   +cmp eax, edi
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
    // 00a8824f  7705                   -ja 0xa88256
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a88256;
    }
    // 00a88251  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00a88256:
    // 00a88256  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a88258  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8825a:
    // 00a8825a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8825c  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a8825f  742e                   -je 0xa8828f
    if (cpu.flags.zf)
    {
        goto L_0x00a8828f;
    }
    // 00a88261  83faff                 +cmp edx, -1
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
    // 00a88264  7408                   -je 0xa8826e
    if (cpu.flags.zf)
    {
        goto L_0x00a8826e;
    }
    // 00a88266  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a88269  01d0                   +add eax, edx
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
    // 00a8826b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8826c  75ec                   -jne 0xa8825a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8825a;
    }
L_0x00a8826e:
    // 00a8826e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a88271  39c3                   +cmp ebx, eax
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
    // 00a88273  7303                   -jae 0xa88278
    if (!cpu.flags.cf)
    {
        goto L_0x00a88278;
    }
    // 00a88275  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x00a88278:
    // 00a88278  39c3                   +cmp ebx, eax
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
    // 00a8827a  7213                   -jb 0xa8828f
    if (cpu.flags.cf)
    {
        goto L_0x00a8828f;
    }
    // 00a8827c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8827f  39c3                   +cmp ebx, eax
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
    // 00a88281  720c                   -jb 0xa8828f
    if (cpu.flags.cf)
    {
        goto L_0x00a8828f;
    }
    // 00a88283  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a88286  39c3                   +cmp ebx, eax
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
    // 00a88288  7205                   -jb 0xa8828f
    if (cpu.flags.cf)
    {
        goto L_0x00a8828f;
    }
    // 00a8828a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8828d  ebe9                   -jmp 0xa88278
    goto L_0x00a88278;
L_0x00a8828f:
    // 00a8828f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a88292  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a88294  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a88296  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a88298  39df                   +cmp edi, ebx
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
    // 00a8829a  7512                   -jne 0xa882ae
    if (!cpu.flags.zf)
    {
        goto L_0x00a882ae;
    }
    // 00a8829c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8829e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a882a0  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a882a2  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a882a5  7503                   -jne 0xa882aa
    if (!cpu.flags.zf)
    {
        goto L_0x00a882aa;
    }
    // 00a882a7  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00a882aa:
    // 00a882aa  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a882ac  eb0f                   -jmp 0xa882bd
    goto L_0x00a882bd;
L_0x00a882ae:
    // 00a882ae  ff461c                 -inc dword ptr [esi + 0x1c]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 00a882b1  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a882b4  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a882b7  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a882ba  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a882bd:
    // 00a882bd  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a882c0  4a                     -dec edx
    (cpu.edx)--;
    // 00a882c1  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a882c4  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a882c7  39fb                   +cmp ebx, edi
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
    // 00a882c9  7308                   -jae 0xa882d3
    if (!cpu.flags.cf)
    {
        goto L_0x00a882d3;
    }
    // 00a882cb  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a882ce  7603                   -jbe 0xa882d3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a882d3;
    }
    // 00a882d0  894e10                 -mov dword ptr [esi + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00a882d3:
    // 00a882d3  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a882d6  7603                   -jbe 0xa882db
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a882db;
    }
    // 00a882d8  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a882db:
    // 00a882db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a882dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a882dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a882de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a882df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a882e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a882e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a882e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a882e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a882e4  a17c26a900             -mov eax, dword ptr [0xa9267c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */);
    // 00a882e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a882eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a882ed  740d                   -je 0xa882fc
    if (cpu.flags.zf)
    {
        goto L_0x00a882fc;
    }
L_0x00a882ef:
    // 00a882ef  39c2                   +cmp edx, eax
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
    // 00a882f1  7209                   -jb 0xa882fc
    if (cpu.flags.cf)
    {
        goto L_0x00a882fc;
    }
    // 00a882f3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a882f5  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a882f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a882fa  75f3                   -jne 0xa882ef
    if (!cpu.flags.zf)
    {
        goto L_0x00a882ef;
    }
L_0x00a882fc:
    // 00a882fc  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a882ff  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a88302  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a88304  7405                   -je 0xa8830b
    if (cpu.flags.zf)
    {
        goto L_0x00a8830b;
    }
    // 00a88306  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a88309  eb06                   -jmp 0xa88311
    goto L_0x00a88311;
L_0x00a8830b:
    // 00a8830b  89157c26a900           -mov dword ptr [0xa9267c], edx
    app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */) = cpu.edx;
L_0x00a88311:
    // 00a88311  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88313  7403                   -je 0xa88318
    if (cpu.flags.zf)
    {
        goto L_0x00a88318;
    }
    // 00a88315  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a88318:
    // 00a88318  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00a8831b  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a8831e  c742f400000000         -mov dword ptr [edx - 0xc], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 00a88325  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 00a8832c  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00a88333  c742f000000000         -mov dword ptr [edx - 0x10], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 00a8833a  895af8                 -mov dword ptr [edx - 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00a8833d  8b42d4                 -mov eax, dword ptr [edx - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-44) /* -0x2c */);
    // 00a88340  895afc                 -mov dword ptr [edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a88343  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a88346  895ae0                 -mov dword ptr [edx - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a88349  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a8834b  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 00a88352  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a88354  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88355  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88356  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a88358(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88358  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88359  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8835a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8835b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8835c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8835d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a88360  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a88363  833d3028a90000         +cmp dword ptr [0xa92830], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085872) /* 0xa92830 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8836a  7507                   -jne 0xa88373
    if (!cpu.flags.zf)
    {
        goto L_0x00a88373;
    }
    // 00a8836c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8836e  e998000000             -jmp 0xa8840b
    goto L_0x00a8840b;
L_0x00a88373:
    // 00a88373  833d3c27a900fe         +cmp dword ptr [0xa9273c], -2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085628) /* 0xa9273c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8837a  750b                   -jne 0xa88387
    if (!cpu.flags.zf)
    {
        goto L_0x00a88387;
    }
    // 00a8837c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8837e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a88381  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88382  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88383  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88384  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88385  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88386  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a88387:
    // 00a88387  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a88389  e89a000000             -call 0xa88428
    cpu.esp -= 4;
    sub_a88428(app, cpu);
    if (cpu.terminate) return;
    // 00a8838e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88390  0f8475000000           -je 0xa8840b
    if (cpu.flags.zf)
    {
        goto L_0x00a8840b;
    }
    // 00a88396  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00a88398  6800100000             -push 0x1000
    app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00a8839d  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a883a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a883a2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a883a4  2eff152c04a900         -call dword ptr cs:[0xa9042c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076652) /* 0xa9042c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a883ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a883ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a883af  745a                   -je 0xa8840b
    if (cpu.flags.zf)
    {
        goto L_0x00a8840b;
    }
    // 00a883b1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a883b4  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a883b7  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a883ba  39f0                   +cmp eax, esi
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
    // 00a883bc  760b                   -jbe 0xa883c9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a883c9;
    }
    // 00a883be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a883c0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a883c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a883c9:
    // 00a883c9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a883cc  83f838                 +cmp eax, 0x38
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a883cf  730b                   -jae 0xa883dc
    if (!cpu.flags.cf)
    {
        goto L_0x00a883dc;
    }
    // 00a883d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a883d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a883d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a883db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a883dc:
    // 00a883dc  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a883de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a883e0  e8fbfeffff             -call 0xa882e0
    cpu.esp -= 4;
    sub_a882e0(app, cpu);
    if (cpu.terminate) return;
    // 00a883e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a883e7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a883e9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a883ec  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a883ee  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a883f0  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00a883f3  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a883fa  47                     -inc edi
    (cpu.edi)++;
    // 00a883fb  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a883fe  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00a88401  e89ae9ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a88406  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a8840b:
    // 00a8840b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8840e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8840f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88410  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88411  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88412  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88413  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88414(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88414  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88415  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a88417  e8542a0000             -call 0xa8ae70
    cpu.esp -= 4;
    sub_a8ae70(app, cpu);
    if (cpu.terminate) return;
    // 00a8841c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8841e  e835ffffff             -call 0xa88358
    cpu.esp -= 4;
    sub_a88358(app, cpu);
    if (cpu.terminate) return;
    // 00a88423  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88424  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a88428(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88428  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88429  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8842a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8842c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8842e  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a88431  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a88433  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88435  743d                   -je 0xa88474
    if (cpu.flags.zf)
    {
        goto L_0x00a88474;
    }
    // 00a88437  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a88439  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a8843c  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8843e  7305                   -jae 0xa88445
    if (!cpu.flags.cf)
    {
        goto L_0x00a88445;
    }
    // 00a88440  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a88442  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88443  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88444  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a88445:
    // 00a88445  8b0d3428a900           -mov ecx, dword ptr [0xa92834]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11085876) /* 0xa92834 */);
    // 00a8844b  39c8                   +cmp eax, ecx
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
    // 00a8844d  7304                   -jae 0xa88453
    if (!cpu.flags.cf)
    {
        goto L_0x00a88453;
    }
    // 00a8844f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a88451  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00a88453:
    // 00a88453  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a88455  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a8845a  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8845c  7305                   -jae 0xa88463
    if (!cpu.flags.cf)
    {
        goto L_0x00a88463;
    }
    // 00a8845e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a88460  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88461  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88462  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a88463:
    // 00a88463  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00a88465  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00a88468  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a8846a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8846c  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a8846f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00a88474:
    // 00a88474  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88475  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88476  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88480(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88480  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a88482  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88490(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88490  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88491  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88492  ba40afa800             -mov edx, 0xa8af40
    cpu.edx = 11054912 /*0xa8af40*/;
    // 00a88497  bb54b0a800             -mov ebx, 0xa8b054
    cpu.ebx = 11055188 /*0xa8b054*/;
    // 00a8849c  89153828a900           -mov dword ptr [0xa92838], edx
    app->getMemory<x86::reg32>(x86::reg32(11085880) /* 0xa92838 */) = cpu.edx;
    // 00a884a2  891d3c28a900           -mov dword ptr [0xa9283c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085884) /* 0xa9283c */) = cpu.ebx;
    // 00a884a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a884a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a884aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a884b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a884b0  9b                     -wait 
    /*nothing*/;
    // 00a884b1  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 00a884b3  9b                     -wait 
    /*nothing*/;
    // 00a884b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a884b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a884b8  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 00a884ba  9b                     -wait 
    /*nothing*/;
    // 00a884bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a884bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a884bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a884bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a884be  803d8d26a90000         +cmp byte ptr [0xa9268d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a884c5  7416                   -je 0xa884dd
    if (cpu.flags.zf)
    {
        goto L_0x00a884dd;
    }
    // 00a884c7  bab084a800             -mov edx, 0xa884b0
    cpu.edx = 11044016 /*0xa884b0*/;
    // 00a884cc  bbb884a800             -mov ebx, 0xa884b8
    cpu.ebx = 11044024 /*0xa884b8*/;
    // 00a884d1  89154028a900           -mov dword ptr [0xa92840], edx
    app->getMemory<x86::reg32>(x86::reg32(11085888) /* 0xa92840 */) = cpu.edx;
    // 00a884d7  891d4428a900           -mov dword ptr [0xa92844], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085892) /* 0xa92844 */) = cpu.ebx;
L_0x00a884dd:
    // 00a884dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a884df  66a14828a900           -mov ax, word ptr [0xa92848]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(11085896) /* 0xa92848 */);
    // 00a884e5  e8b62b0000             -call 0xa8b0a0
    cpu.esp -= 4;
    sub_a8b0a0(app, cpu);
    if (cpu.terminate) return;
    // 00a884ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a884eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a884ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a884f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a884f0  803d8d26a90000         +cmp byte ptr [0xa9268d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a884f7  75c3                   -jne 0xa884bc
    if (!cpu.flags.zf)
    {
        return sub_a884bc(app, cpu);
    }
    // 00a884f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a884fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a884fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a884fd  8a258c26a900           -mov ah, byte ptr [0xa9268c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11085452) /* 0xa9268c */);
    // 00a88503  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a88505  7537                   -jne 0xa8853e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8853e;
    }
    // 00a88507  88258d26a900           -mov byte ptr [0xa9268d], ah
    app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */) = cpu.ah;
    // 00a8850d  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a8850f  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a88511  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a88512  dbe3                   -fninit 
    cpu.fpu.init();
    // 00a88514  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a88517  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88518  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 00a8851a  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8851c  3c03                   +cmp al, 3
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
    // 00a8851e  7509                   -jne 0xa88529
    if (!cpu.flags.zf)
    {
        goto L_0x00a88529;
    }
    // 00a88520  e897ffffff             -call 0xa884bc
    cpu.esp -= 4;
    sub_a884bc(app, cpu);
    if (cpu.terminate) return;
    // 00a88525  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 00a88527  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x00a88529:
    // 00a88529  803d7827a90000         +cmp byte ptr [0xa92778], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085688) /* 0xa92778 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88530  750c                   -jne 0xa8853e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8853e;
    }
    // 00a88532  88358c26a900           -mov byte ptr [0xa9268c], dh
    app->getMemory<x86::reg8>(x86::reg32(11085452) /* 0xa9268c */) = cpu.dh;
    // 00a88538  88158d26a900           -mov byte ptr [0xa9268d], dl
    app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */) = cpu.dl;
L_0x00a8853e:
    // 00a8853e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8853f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88540(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88540  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88550(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88550  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a88554(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88554  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88555  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88556  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88557  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88558  8b152046a900           -mov edx, dword ptr [0xa94620]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11093536) /* 0xa94620 */);
    // 00a8855e  83fa40                 +cmp edx, 0x40
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
    // 00a88561  7d1e                   -jge 0xa88581
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a88581;
    }
    // 00a88563  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a8856a  bbf03fa900             -mov ebx, 0xa93ff0
    cpu.ebx = 11091952 /*0xa93ff0*/;
    // 00a8856f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a88571  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a88574  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a88577  89352046a900           -mov dword ptr [0xa94620], esi
    app->getMemory<x86::reg32>(x86::reg32(11093536) /* 0xa94620 */) = cpu.esi;
    // 00a8857d  01c3                   +add ebx, eax
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
    // 00a8857f  eb67                   -jmp 0xa885e8
    goto L_0x00a885e8;
L_0x00a88581:
    // 00a88581  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00a88586  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8858b  e8402b0000             -call 0xa8b0d0
    cpu.esp -= 4;
    sub_a8b0d0(app, cpu);
    if (cpu.terminate) return;
    // 00a88590  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a88592  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88594  750f                   -jne 0xa885a5
    if (!cpu.flags.zf)
    {
        goto L_0x00a885a5;
    }
    // 00a88596  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8859b  b82c17a900             -mov eax, 0xa9172c
    cpu.eax = 11081516 /*0xa9172c*/;
    // 00a885a0  e857180000             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
L_0x00a885a5:
    // 00a885a5  8b152446a900           -mov edx, dword ptr [0xa94624]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11093540) /* 0xa94624 */);
    // 00a885ab  42                     -inc edx
    (cpu.edx)++;
    // 00a885ac  a12846a900             -mov eax, dword ptr [0xa94628]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11093544) /* 0xa94628 */);
    // 00a885b1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00a885b4  e8372b0000             -call 0xa8b0f0
    cpu.esp -= 4;
    sub_a8b0f0(app, cpu);
    if (cpu.terminate) return;
    // 00a885b9  a32846a900             -mov dword ptr [0xa94628], eax
    app->getMemory<x86::reg32>(x86::reg32(11093544) /* 0xa94628 */) = cpu.eax;
    // 00a885be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a885c0  750f                   -jne 0xa885d1
    if (!cpu.flags.zf)
    {
        goto L_0x00a885d1;
    }
    // 00a885c2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a885c7  b85017a900             -mov eax, 0xa91750
    cpu.eax = 11081552 /*0xa91750*/;
    // 00a885cc  e82b180000             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
L_0x00a885d1:
    // 00a885d1  a12446a900             -mov eax, dword ptr [0xa94624]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11093540) /* 0xa94624 */);
    // 00a885d6  8b152846a900           -mov edx, dword ptr [0xa94628]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11093544) /* 0xa94628 */);
    // 00a885dc  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a885df  891c82                 -mov dword ptr [edx + eax*4], ebx
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = cpu.ebx;
    // 00a885e2  890d2446a900           -mov dword ptr [0xa94624], ecx
    app->getMemory<x86::reg32>(x86::reg32(11093540) /* 0xa94624 */) = cpu.ecx;
L_0x00a885e8:
    // 00a885e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a885e9  2eff15e403a900         -call dword ptr cs:[0xa903e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076580) /* 0xa903e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a885f0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a885f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a885f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a885f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a885f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a885f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a885f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a885f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a885f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a885fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a885fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a885fc  8b152046a900           -mov edx, dword ptr [0xa94620]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11093536) /* 0xa94620 */);
    // 00a88602  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a88604  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a88606  7e1b                   -jle 0xa88623
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a88623;
    }
    // 00a88608  bbf03fa900             -mov ebx, 0xa93ff0
    cpu.ebx = 11091952 /*0xa93ff0*/;
L_0x00a8860d:
    // 00a8860d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8860e  46                     -inc esi
    (cpu.esi)++;
    // 00a8860f  2eff157403a900         -call dword ptr cs:[0xa90374]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076468) /* 0xa90374 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88616  8b0d2046a900           -mov ecx, dword ptr [0xa94620]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11093536) /* 0xa94620 */);
    // 00a8861c  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8861f  39ce                   +cmp esi, ecx
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
    // 00a88621  7cea                   -jl 0xa8860d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8860d;
    }
L_0x00a88623:
    // 00a88623  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88624  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88625  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88626  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88627  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88628(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88628  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88629  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8862a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8862b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8862c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8862d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8862e  8b152446a900           -mov edx, dword ptr [0xa94624]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11093540) /* 0xa94624 */);
    // 00a88634  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a88636  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a88638  7e2d                   -jle 0xa88667
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a88667;
    }
    // 00a8863a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8863c:
    // 00a8863c  a12846a900             -mov eax, dword ptr [0xa94628]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11093544) /* 0xa94628 */);
    // 00a88641  8b0c03                 -mov ecx, dword ptr [ebx + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00a88644  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88645  2eff157403a900         -call dword ptr cs:[0xa90374]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076468) /* 0xa90374 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8864c  a12846a900             -mov eax, dword ptr [0xa94628]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11093544) /* 0xa94628 */);
    // 00a88651  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00a88654  46                     -inc esi
    (cpu.esi)++;
    // 00a88655  e846e7ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8865a  8b3d2446a900           -mov edi, dword ptr [0xa94624]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11093540) /* 0xa94624 */);
    // 00a88660  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a88663  39fe                   +cmp esi, edi
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
    // 00a88665  7cd5                   -jl 0xa8863c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8863c;
    }
L_0x00a88667:
    // 00a88667  8b2d2846a900           -mov ebp, dword ptr [0xa94628]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11093544) /* 0xa94628 */);
    // 00a8866d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8866f  7407                   -je 0xa88678
    if (cpu.flags.zf)
    {
        goto L_0x00a88678;
    }
    // 00a88671  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a88673  e828e7ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a88678:
    // 00a88678  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88679  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8867a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8867b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8867c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8867d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8867e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a88680(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88680  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a88687  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a8868e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a88690(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88690  b8c03ea900             -mov eax, 0xa93ec0
    cpu.eax = 11091648 /*0xa93ec0*/;
    // 00a88695  e992000000             -jmp 0xa8872c
    return sub_a8872c(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a8869c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8869c  b8c03ea900             -mov eax, 0xa93ec0
    cpu.eax = 11091648 /*0xa93ec0*/;
    // 00a886a1  e9ea000000             -jmp 0xa88790
    return sub_a88790(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a886a8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a886a8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a886ab  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a886ae  05e03ea900             +add eax, 0xa93ee0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11091680 /*0xa93ee0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a886b3  e974000000             -jmp 0xa8872c
    return sub_a8872c(app, cpu);
}

/* align: skip  */
void sub_a886b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a886b8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a886bb  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a886be  05e03ea900             +add eax, 0xa93ee0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11091680 /*0xa93ee0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a886c3  e9c8000000             -jmp 0xa88790
    return sub_a88790(app, cpu);
}

/* align: skip  */
void sub_a886c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a886c8  e9e71c0000             -jmp 0xa8a3b4
    return sub_a8a3b4(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a886d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a886d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a886d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a886d3  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a886d6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a886d9  05e03ea900             -add eax, 0xa93ee0
    (cpu.eax) += x86::reg32(x86::sreg32(11091680 /*0xa93ee0*/));
    // 00a886de  e89dffffff             -call 0xa88680
    cpu.esp -= 4;
    sub_a88680(app, cpu);
    if (cpu.terminate) return;
    // 00a886e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a886e5  e8221e0000             -call 0xa8a50c
    cpu.esp -= 4;
    sub_a8a50c(app, cpu);
    if (cpu.terminate) return;
    // 00a886ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a886eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a886ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a886ec  b8e03fa900             -mov eax, 0xa93fe0
    cpu.eax = 11091936 /*0xa93fe0*/;
    // 00a886f1  eb39                   -jmp 0xa8872c
    return sub_a8872c(app, cpu);
}

/* align: skip 0x90 */
void sub_a886f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a886f4  b8e03fa900             -mov eax, 0xa93fe0
    cpu.eax = 11091936 /*0xa93fe0*/;
    // 00a886f9  e992000000             -jmp 0xa88790
    return sub_a88790(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a88700(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88700  b8d03ea900             -mov eax, 0xa93ed0
    cpu.eax = 11091664 /*0xa93ed0*/;
    // 00a88705  eb25                   -jmp 0xa8872c
    return sub_a8872c(app, cpu);
}

/* align: skip 0x90 */
void sub_a88708(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88708  b8d03ea900             -mov eax, 0xa93ed0
    cpu.eax = 11091664 /*0xa93ed0*/;
    // 00a8870d  e97e000000             -jmp 0xa88790
    return sub_a88790(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a88714(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88714  b80046a900             -mov eax, 0xa94600
    cpu.eax = 11093504 /*0xa94600*/;
    // 00a88719  eb11                   -jmp 0xa8872c
    return sub_a8872c(app, cpu);
}

/* align: skip 0x90 */
void sub_a8871c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8871c  b80046a900             -mov eax, 0xa94600
    cpu.eax = 11093504 /*0xa94600*/;
    // 00a88721  eb6d                   -jmp 0xa88790
    return sub_a88790(app, cpu);
}

/* align: skip 0x90 */
void sub_a88724(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88724  b81046a900             -mov eax, 0xa94610
    cpu.eax = 11093520 /*0xa94610*/;
    // 00a88729  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a8872c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8872d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8872e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8872f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88731  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a88733  2eff15ac03a900         -call dword ptr cs:[0xa903ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076524) /* 0xa903ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8873a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a8873d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8873f  39d0                   +cmp eax, edx
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
    // 00a88741  743b                   -je 0xa8877e
    if (cpu.flags.zf)
    {
        goto L_0x00a8877e;
    }
    // 00a88743  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a88747  7528                   -jne 0xa88771
    if (!cpu.flags.zf)
    {
        goto L_0x00a88771;
    }
    // 00a88749  b8f045a900             -mov eax, 0xa945f0
    cpu.eax = 11093488 /*0xa945f0*/;
    // 00a8874e  e8d9ffffff             -call 0xa8872c
    cpu.esp -= 4;
    sub_a8872c(app, cpu);
    if (cpu.terminate) return;
    // 00a88753  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a88757  750e                   -jne 0xa88767
    if (!cpu.flags.zf)
    {
        goto L_0x00a88767;
    }
    // 00a88759  e8f6fdffff             -call 0xa88554
    cpu.esp -= 4;
    sub_a88554(app, cpu);
    if (cpu.terminate) return;
    // 00a8875e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00a88765  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a88767:
    // 00a88767  b8f045a900             -mov eax, 0xa945f0
    cpu.eax = 11093488 /*0xa945f0*/;
    // 00a8876c  e81f000000             -call 0xa88790
    cpu.esp -= 4;
    sub_a88790(app, cpu);
    if (cpu.terminate) return;
L_0x00a88771:
    // 00a88771  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a88773  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88774  2eff157c03a900         -call dword ptr cs:[0xa9037c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076476) /* 0xa9037c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8877b  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a8877e:
    // 00a8877e  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a88781  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88782  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88783  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88784  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88785  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88786  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8872c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8872c;
    // 00a88724  b81046a900             -mov eax, 0xa94610
    cpu.eax = 11093520 /*0xa94610*/;
    // 00a88729  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a8872c:
    // 00a8872c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8872d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8872e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8872f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88731  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a88733  2eff15ac03a900         -call dword ptr cs:[0xa903ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076524) /* 0xa903ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8873a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a8873d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8873f  39d0                   +cmp eax, edx
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
    // 00a88741  743b                   -je 0xa8877e
    if (cpu.flags.zf)
    {
        goto L_0x00a8877e;
    }
    // 00a88743  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a88747  7528                   -jne 0xa88771
    if (!cpu.flags.zf)
    {
        goto L_0x00a88771;
    }
    // 00a88749  b8f045a900             -mov eax, 0xa945f0
    cpu.eax = 11093488 /*0xa945f0*/;
    // 00a8874e  e8d9ffffff             -call 0xa8872c
    cpu.esp -= 4;
    sub_a8872c(app, cpu);
    if (cpu.terminate) return;
    // 00a88753  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a88757  750e                   -jne 0xa88767
    if (!cpu.flags.zf)
    {
        goto L_0x00a88767;
    }
    // 00a88759  e8f6fdffff             -call 0xa88554
    cpu.esp -= 4;
    sub_a88554(app, cpu);
    if (cpu.terminate) return;
    // 00a8875e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00a88765  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a88767:
    // 00a88767  b8f045a900             -mov eax, 0xa945f0
    cpu.eax = 11093488 /*0xa945f0*/;
    // 00a8876c  e81f000000             -call 0xa88790
    cpu.esp -= 4;
    sub_a88790(app, cpu);
    if (cpu.terminate) return;
L_0x00a88771:
    // 00a88771  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a88773  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88774  2eff157c03a900         -call dword ptr cs:[0xa9037c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076476) /* 0xa9037c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8877b  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a8877e:
    // 00a8877e  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a88781  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88782  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88783  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88784  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88785  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88786  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a88788(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88788  b81046a900             -mov eax, 0xa94610
    cpu.eax = 11093520 /*0xa94610*/;
    // 00a8878d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a88790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88791  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88792  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88793  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88794  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a88797  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a88799  7617                   -jbe 0xa887b2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a887b2;
    }
    // 00a8879b  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a8879e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a887a1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a887a3  750d                   -jne 0xa887b2
    if (!cpu.flags.zf)
    {
        goto L_0x00a887b2;
    }
    // 00a887a5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a887a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a887a8  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a887ab  2eff15e803a900         -call dword ptr cs:[0xa903e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076584) /* 0xa903e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a887b2:
    // 00a887b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a88790;
    // 00a88788  b81046a900             -mov eax, 0xa94610
    cpu.eax = 11093520 /*0xa94610*/;
    // 00a8878d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a88790:
    // 00a88790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88791  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88792  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88793  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88794  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a88797  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a88799  7617                   -jbe 0xa887b2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a887b2;
    }
    // 00a8879b  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a8879e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a887a1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a887a3  750d                   -jne 0xa887b2
    if (!cpu.flags.zf)
    {
        goto L_0x00a887b2;
    }
    // 00a887a5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a887a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a887a8  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a887ab  2eff15e803a900         -call dword ptr cs:[0xa903e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076584) /* 0xa903e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a887b2:
    // 00a887b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a887b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a887b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a887b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a887ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a887bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a887bc  2eff15c403a900         -call dword ptr cs:[0xa903c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076548) /* 0xa903c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a887c3  8b15a426a900           -mov edx, dword ptr [0xa926a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a887c9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a887ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a887cc  2eff152004a900         -call dword ptr cs:[0xa90420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076640) /* 0xa90420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a887d3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a887d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a887d7  7507                   -jne 0xa887e0
    if (!cpu.flags.zf)
    {
        goto L_0x00a887e0;
    }
    // 00a887d9  e892290000             -call 0xa8b170
    cpu.esp -= 4;
    sub_a8b170(app, cpu);
    if (cpu.terminate) return;
    // 00a887de  eb0b                   -jmp 0xa887eb
    goto L_0x00a887eb;
L_0x00a887e0:
    // 00a887e0  80785300               +cmp byte ptr [eax + 0x53], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(83) /* 0x53 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a887e4  7407                   -je 0xa887ed
    if (cpu.flags.zf)
    {
        goto L_0x00a887ed;
    }
    // 00a887e6  e8c1290000             -call 0xa8b1ac
    cpu.esp -= 4;
    sub_a8b1ac(app, cpu);
    if (cpu.terminate) return;
L_0x00a887eb:
    // 00a887eb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a887ed:
    // 00a887ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a887ee  2eff150c04a900         -call dword ptr cs:[0xa9040c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076620) /* 0xa9040c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a887f5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a887f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a887fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a887fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a887fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a887fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a887fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a88800  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88802  7526                   -jne 0xa8882a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8882a;
    }
    // 00a88804  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a88809  8b154c28a900           -mov edx, dword ptr [0xa9284c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a8880f  e8bc280000             -call 0xa8b0d0
    cpu.esp -= 4;
    sub_a8b0d0(app, cpu);
    if (cpu.terminate) return;
    // 00a88814  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a88816  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88818  7410                   -je 0xa8882a
    if (cpu.flags.zf)
    {
        goto L_0x00a8882a;
    }
    // 00a8881a  8b1d4c28a900           -mov ebx, dword ptr [0xa9284c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a88820  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a88824  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x00a8882a:
    // 00a8882a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8882c  e88f2b0000             -call 0xa8b3c0
    cpu.esp -= 4;
    sub_a8b3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a88831  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a88833  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88834  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88835  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a88838(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88838  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88839  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8883a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8883b  8b1da426a900           -mov ebx, dword ptr [0xa926a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a88841  83fbff                 +cmp ebx, -1
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
    // 00a88844  753b                   -jne 0xa88881
    if (!cpu.flags.zf)
    {
        goto L_0x00a88881;
    }
    // 00a88846  2eff151804a900         -call dword ptr cs:[0xa90418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076632) /* 0xa90418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8884d  668b158527a900         -mov dx, word ptr [0xa92785]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(11085701) /* 0xa92785 */);
    // 00a88854  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a88856  6681fa0080             +cmp dx, 0x8000
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8885b  7224                   -jb 0xa88881
    if (cpu.flags.cf)
    {
        goto L_0x00a88881;
    }
    // 00a8885d  803d8327a90004         +cmp byte ptr [0xa92783], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085699) /* 0xa92783 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88864  731b                   -jae 0xa88881
    if (!cpu.flags.cf)
    {
        goto L_0x00a88881;
    }
L_0x00a88866:
    // 00a88866  83fbff                 +cmp ebx, -1
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
    // 00a88869  7416                   -je 0xa88881
    if (cpu.flags.zf)
    {
        goto L_0x00a88881;
    }
    // 00a8886b  83fb02                 +cmp ebx, 2
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
    // 00a8886e  7711                   -ja 0xa88881
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a88881;
    }
    // 00a88870  891da426a900           -mov dword ptr [0xa926a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */) = cpu.ebx;
    // 00a88876  2eff151804a900         -call dword ptr cs:[0xa90418]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076632) /* 0xa90418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8887d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8887f  ebe5                   -jmp 0xa88866
    goto L_0x00a88866;
L_0x00a88881:
    // 00a88881  83fbff                 +cmp ebx, -1
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
    // 00a88884  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a88887  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8888c  891da426a900           -mov dword ptr [0xa926a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */) = cpu.ebx;
    // 00a88892  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88893  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88894  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88895  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a88898(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88898  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88899  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8889a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8889b  833da426a900ff         +cmp dword ptr [0xa926a4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a888a2  7506                   -jne 0xa888aa
    if (!cpu.flags.zf)
    {
        goto L_0x00a888aa;
    }
    // 00a888a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a888a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a888aa:
    // 00a888aa  e84dffffff             -call 0xa887fc
    cpu.esp -= 4;
    sub_a887fc(app, cpu);
    if (cpu.terminate) return;
    // 00a888af  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a888b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a888b3  7432                   -je 0xa888e7
    if (cpu.flags.zf)
    {
        goto L_0x00a888e7;
    }
    // 00a888b5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a888b7  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a888bd  e8be290000             -call 0xa8b280
    cpu.esp -= 4;
    sub_a8b280(app, cpu);
    if (cpu.terminate) return;
    // 00a888c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a888c4  750d                   -jne 0xa888d3
    if (!cpu.flags.zf)
    {
        goto L_0x00a888d3;
    }
    // 00a888c6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a888c8  e8d3e4ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a888cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a888cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888d1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a888d3:
    // 00a888d3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a888d4  8b1da426a900           -mov ebx, dword ptr [0xa926a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a888da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a888db  2eff152404a900         -call dword ptr cs:[0xa90424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076644) /* 0xa90424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a888e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a888e7:
    // 00a888e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a888ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a888ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a888ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a888ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a888ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a888ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a888f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a888f1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a888f3  8b15a426a900           -mov edx, dword ptr [0xa926a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a888f9  83faff                 +cmp edx, -1
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
    // 00a888fc  743d                   -je 0xa8893b
    if (cpu.flags.zf)
    {
        goto L_0x00a8893b;
    }
    // 00a888fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a888ff  2eff152004a900         -call dword ptr cs:[0xa90420]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076640) /* 0xa90420 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88906  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88908  7431                   -je 0xa8893b
    if (cpu.flags.zf)
    {
        goto L_0x00a8893b;
    }
    // 00a8890a  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 00a88910  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a88916  e8c9290000             -call 0xa8b2e4
    cpu.esp -= 4;
    sub_a8b2e4(app, cpu);
    if (cpu.terminate) return;
    // 00a8891b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8891d  8b3da426a900           -mov edi, dword ptr [0xa926a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a88923  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88924  2eff152404a900         -call dword ptr cs:[0xa90424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076644) /* 0xa90424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8892b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8892d  740c                   -je 0xa8893b
    if (cpu.flags.zf)
    {
        goto L_0x00a8893b;
    }
    // 00a8892f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a88931  7408                   -je 0xa8893b
    if (cpu.flags.zf)
    {
        goto L_0x00a8893b;
    }
    // 00a88933  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88934  2eff156403a900         -call dword ptr cs:[0xa90364]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076452) /* 0xa90364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a8893b:
    // 00a8893b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8893c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8893d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8893e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8893f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88940  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a88944(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88944  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a88949  e89effffff             -call 0xa888ec
    cpu.esp -= 4;
    sub_a888ec(app, cpu);
    if (cpu.terminate) return;
    // 00a8894e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a88950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88951  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88952  8b15a426a900           -mov edx, dword ptr [0xa926a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a88958  83faff                 +cmp edx, -1
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
    // 00a8895b  7412                   -je 0xa8896f
    if (cpu.flags.zf)
    {
        goto L_0x00a8896f;
    }
    // 00a8895d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8895e  2eff151c04a900         -call dword ptr cs:[0xa9041c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076636) /* 0xa9041c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88965  c705a426a900ffffffff   -mov dword ptr [0xa926a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */) = 4294967295 /*0xffffffff*/;
L_0x00a8896f:
    // 00a8896f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88970  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88971  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88950(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a88950;
    // 00a88944  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a88949  e89effffff             -call 0xa888ec
    cpu.esp -= 4;
    sub_a888ec(app, cpu);
    if (cpu.terminate) return;
    // 00a8894e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00a88950:
    // 00a88950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88951  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88952  8b15a426a900           -mov edx, dword ptr [0xa926a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a88958  83faff                 +cmp edx, -1
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
    // 00a8895b  7412                   -je 0xa8896f
    if (cpu.flags.zf)
    {
        goto L_0x00a8896f;
    }
    // 00a8895d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8895e  2eff151c04a900         -call dword ptr cs:[0xa9041c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076636) /* 0xa9041c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88965  c705a426a900ffffffff   -mov dword ptr [0xa926a4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */) = 4294967295 /*0xffffffff*/;
L_0x00a8896f:
    // 00a8896f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88970  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88971  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a88974(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88974  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88975  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88976  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88977  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88978  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88979  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8897a  baa886a800             -mov edx, 0xa886a8
    cpu.edx = 11044520 /*0xa886a8*/;
    // 00a8897f  bbb886a800             -mov ebx, 0xa886b8
    cpu.ebx = 11044536 /*0xa886b8*/;
    // 00a88984  b9c886a800             -mov ecx, 0xa886c8
    cpu.ecx = 11044552 /*0xa886c8*/;
    // 00a88989  bed086a800             -mov esi, 0xa886d0
    cpu.esi = 11044560 /*0xa886d0*/;
    // 00a8898e  bf9086a800             -mov edi, 0xa88690
    cpu.edi = 11044496 /*0xa88690*/;
    // 00a88993  bd9c86a800             -mov ebp, 0xa8869c
    cpu.ebp = 11044508 /*0xa8869c*/;
    // 00a88998  b81487a800             -mov eax, 0xa88714
    cpu.eax = 11044628 /*0xa88714*/;
    // 00a8899d  8915ac26a900           -mov dword ptr [0xa926ac], edx
    app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */) = cpu.edx;
    // 00a889a3  891db026a900           -mov dword ptr [0xa926b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */) = cpu.ebx;
    // 00a889a9  890db426a900           -mov dword ptr [0xa926b4], ecx
    app->getMemory<x86::reg32>(x86::reg32(11085492) /* 0xa926b4 */) = cpu.ecx;
    // 00a889af  8935b826a900           -mov dword ptr [0xa926b8], esi
    app->getMemory<x86::reg32>(x86::reg32(11085496) /* 0xa926b8 */) = cpu.esi;
    // 00a889b5  893dbc26a900           -mov dword ptr [0xa926bc], edi
    app->getMemory<x86::reg32>(x86::reg32(11085500) /* 0xa926bc */) = cpu.edi;
    // 00a889bb  892dc026a900           -mov dword ptr [0xa926c0], ebp
    app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */) = cpu.ebp;
    // 00a889c1  a3d426a900             -mov dword ptr [0xa926d4], eax
    app->getMemory<x86::reg32>(x86::reg32(11085524) /* 0xa926d4 */) = cpu.eax;
    // 00a889c6  ba1c87a800             -mov edx, 0xa8871c
    cpu.edx = 11044636 /*0xa8871c*/;
    // 00a889cb  bb2c87a800             -mov ebx, 0xa8872c
    cpu.ebx = 11044652 /*0xa8872c*/;
    // 00a889d0  b99087a800             -mov ecx, 0xa88790
    cpu.ecx = 11044752 /*0xa88790*/;
    // 00a889d5  be8086a800             -mov esi, 0xa88680
    cpu.esi = 11044480 /*0xa88680*/;
    // 00a889da  bfec86a800             -mov edi, 0xa886ec
    cpu.edi = 11044588 /*0xa886ec*/;
    // 00a889df  bd0087a800             -mov ebp, 0xa88700
    cpu.ebp = 11044608 /*0xa88700*/;
    // 00a889e4  b8f486a800             -mov eax, 0xa886f4
    cpu.eax = 11044596 /*0xa886f4*/;
    // 00a889e9  8915d826a900           -mov dword ptr [0xa926d8], edx
    app->getMemory<x86::reg32>(x86::reg32(11085528) /* 0xa926d8 */) = cpu.edx;
    // 00a889ef  891d9c27a900           -mov dword ptr [0xa9279c], ebx
    app->getMemory<x86::reg32>(x86::reg32(11085724) /* 0xa9279c */) = cpu.ebx;
    // 00a889f5  890da027a900           -mov dword ptr [0xa927a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11085728) /* 0xa927a0 */) = cpu.ecx;
    // 00a889fb  8935a427a900           -mov dword ptr [0xa927a4], esi
    app->getMemory<x86::reg32>(x86::reg32(11085732) /* 0xa927a4 */) = cpu.esi;
    // 00a88a01  893dc426a900           -mov dword ptr [0xa926c4], edi
    app->getMemory<x86::reg32>(x86::reg32(11085508) /* 0xa926c4 */) = cpu.edi;
    // 00a88a07  892dc826a900           -mov dword ptr [0xa926c8], ebp
    app->getMemory<x86::reg32>(x86::reg32(11085512) /* 0xa926c8 */) = cpu.ebp;
    // 00a88a0d  a3cc26a900             -mov dword ptr [0xa926cc], eax
    app->getMemory<x86::reg32>(x86::reg32(11085516) /* 0xa926cc */) = cpu.eax;
    // 00a88a12  ba0887a800             -mov edx, 0xa88708
    cpu.edx = 11044616 /*0xa88708*/;
    // 00a88a17  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a88a1c  b92487a800             -mov ecx, 0xa88724
    cpu.ecx = 11044644 /*0xa88724*/;
    // 00a88a21  be8887a800             -mov esi, 0xa88788
    cpu.esi = 11044744 /*0xa88788*/;
    // 00a88a26  bf4489a800             -mov edi, 0xa88944
    cpu.edi = 11045188 /*0xa88944*/;
    // 00a88a2b  8915d026a900           -mov dword ptr [0xa926d0], edx
    app->getMemory<x86::reg32>(x86::reg32(11085520) /* 0xa926d0 */) = cpu.edx;
    // 00a88a31  e81efbffff             -call 0xa88554
    cpu.esp -= 4;
    sub_a88554(app, cpu);
    if (cpu.terminate) return;
    // 00a88a36  8b157c38a900           -mov edx, dword ptr [0xa9387c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11090044) /* 0xa9387c */);
    // 00a88a3c  a3f045a900             -mov dword ptr [0xa945f0], eax
    app->getMemory<x86::reg32>(x86::reg32(11093488) /* 0xa945f0 */) = cpu.eax;
    // 00a88a41  891df445a900           -mov dword ptr [0xa945f4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11093492) /* 0xa945f4 */) = cpu.ebx;
    // 00a88a47  890ddc26a900           -mov dword ptr [0xa926dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(11085532) /* 0xa926dc */) = cpu.ecx;
    // 00a88a4d  8935e026a900           -mov dword ptr [0xa926e0], esi
    app->getMemory<x86::reg32>(x86::reg32(11085536) /* 0xa926e0 */) = cpu.esi;
    // 00a88a53  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 00a88a59  893de426a900           -mov dword ptr [0xa926e4], edi
    app->getMemory<x86::reg32>(x86::reg32(11085540) /* 0xa926e4 */) = cpu.edi;
    // 00a88a5f  e81c280000             -call 0xa8b280
    cpu.esp -= 4;
    sub_a8b280(app, cpu);
    if (cpu.terminate) return;
    // 00a88a64  8b2d7c38a900           -mov ebp, dword ptr [0xa9387c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11090044) /* 0xa9387c */);
    // 00a88a6a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88a6b  a1a426a900             -mov eax, dword ptr [0xa926a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085476) /* 0xa926a4 */);
    // 00a88a70  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a88a71  2eff152404a900         -call dword ptr cs:[0xa90424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076644) /* 0xa90424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88a78  c705a826a900b887a800   -mov dword ptr [0xa926a8], 0xa887b8
    app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */) = 11044792 /*0xa887b8*/;
    // 00a88a82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88a83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88a84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88a85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88a86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88a87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88a88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a88a8c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88a8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88a8d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88a8e  b8c03ea900             -mov eax, 0xa93ec0
    cpu.eax = 11091648 /*0xa93ec0*/;
    // 00a88a93  bae03ea900             -mov edx, 0xa93ee0
    cpu.edx = 11091680 /*0xa93ee0*/;
    // 00a88a98  ff15a427a900           -call dword ptr [0xa927a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085732) /* 0xa927a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88a9e  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x00a88aa4:
    // 00a88aa4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a88aa6  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a88aa9  ff15a427a900           -call dword ptr [0xa927a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085732) /* 0xa927a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88aaf  39da                   +cmp edx, ebx
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
    // 00a88ab1  75f1                   -jne 0xa88aa4
    if (!cpu.flags.zf)
    {
        goto L_0x00a88aa4;
    }
    // 00a88ab3  b81046a900             -mov eax, 0xa94610
    cpu.eax = 11093520 /*0xa94610*/;
    // 00a88ab8  ff15a427a900           -call dword ptr [0xa927a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085732) /* 0xa927a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88abe  e865fbffff             -call 0xa88628
    cpu.esp -= 4;
    sub_a88628(app, cpu);
    if (cpu.terminate) return;
    // 00a88ac3  e828290000             -call 0xa8b3f0
    cpu.esp -= 4;
    sub_a8b3f0(app, cpu);
    if (cpu.terminate) return;
    // 00a88ac8  e8a3230000             -call 0xa8ae70
    cpu.esp -= 4;
    sub_a8ae70(app, cpu);
    if (cpu.terminate) return;
    // 00a88acd  b8e03fa900             -mov eax, 0xa93fe0
    cpu.eax = 11091936 /*0xa93fe0*/;
    // 00a88ad2  ff15a427a900           -call dword ptr [0xa927a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085732) /* 0xa927a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88ad8  b8d03ea900             -mov eax, 0xa93ed0
    cpu.eax = 11091664 /*0xa93ed0*/;
    // 00a88add  ff15a427a900           -call dword ptr [0xa927a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085732) /* 0xa927a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88ae3  b80046a900             -mov eax, 0xa94600
    cpu.eax = 11093504 /*0xa94600*/;
    // 00a88ae8  ff15a427a900           -call dword ptr [0xa927a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085732) /* 0xa927a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88aee  b8f045a900             -mov eax, 0xa945f0
    cpu.eax = 11093488 /*0xa945f0*/;
    // 00a88af3  ff15a427a900           -call dword ptr [0xa927a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085732) /* 0xa927a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88af9  e8fafaffff             -call 0xa885f8
    cpu.esp -= 4;
    sub_a885f8(app, cpu);
    if (cpu.terminate) return;
    // 00a88afe  e84dfeffff             -call 0xa88950
    cpu.esp -= 4;
    sub_a88950(app, cpu);
    if (cpu.terminate) return;
    // 00a88b03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88b04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88b05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88b10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88b13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88b14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88b15  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a88b17  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a88b1c  681848a900             -push 0xa94818
    app->getMemory<x86::reg32>(cpu.esp-4) = 11094040 /*0xa94818*/;
    cpu.esp -= 4;
    // 00a88b21  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a88b23  2eff15c803a900         -call dword ptr cs:[0xa903c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076552) /* 0xa903c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88b2a  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a88b2f  681c49a900             -push 0xa9491c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11094300 /*0xa9491c*/;
    cpu.esp -= 4;
    // 00a88b34  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88b35  be7417a900             -mov esi, 0xa91774
    cpu.esi = 11081588 /*0xa91774*/;
    // 00a88b3a  2eff15c803a900         -call dword ptr cs:[0xa903c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076552) /* 0xa903c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88b41  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a88b43  bf3046a900             -mov edi, 0xa94630
    cpu.edi = 11093552 /*0xa94630*/;
    // 00a88b48  88253046a900           -mov byte ptr [0xa94630], ah
    app->getMemory<x86::reg8>(x86::reg32(11093552) /* 0xa94630 */) = cpu.ah;
    // 00a88b4e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a88b4f  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a88b50  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a88b51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88b52  2bc9                   +sub ecx, ecx
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
    // 00a88b54  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88b55  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a88b57  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a88b59  4f                     -dec edi
    (cpu.edi)--;
L_0x00a88b5a:
    // 00a88b5a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a88b5c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a88b5e  3c00                   +cmp al, 0
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
    // 00a88b60  7410                   -je 0xa88b72
    if (cpu.flags.zf)
    {
        goto L_0x00a88b72;
    }
    // 00a88b62  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a88b65  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a88b68  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a88b6b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a88b6e  3c00                   +cmp al, 0
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
    // 00a88b70  75e8                   -jne 0xa88b5a
    if (!cpu.flags.zf)
    {
        goto L_0x00a88b5a;
    }
L_0x00a88b72:
    // 00a88b72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88b73  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a88b74  be1848a900             -mov esi, 0xa94818
    cpu.esi = 11094040 /*0xa94818*/;
    // 00a88b79  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a88b7a  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a88b7b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a88b7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88b7d  2bc9                   +sub ecx, ecx
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
    // 00a88b7f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88b80  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a88b82  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a88b84  4f                     -dec edi
    (cpu.edi)--;
L_0x00a88b85:
    // 00a88b85  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a88b87  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a88b89  3c00                   +cmp al, 0
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
    // 00a88b8b  7410                   -je 0xa88b9d
    if (cpu.flags.zf)
    {
        goto L_0x00a88b9d;
    }
    // 00a88b8d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a88b90  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a88b93  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a88b96  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a88b99  3c00                   +cmp al, 0
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
    // 00a88b9b  75e8                   -jne 0xa88b85
    if (!cpu.flags.zf)
    {
        goto L_0x00a88b85;
    }
L_0x00a88b9d:
    // 00a88b9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88b9e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a88b9f  bea817a900             -mov esi, 0xa917a8
    cpu.esi = 11081640 /*0xa917a8*/;
    // 00a88ba4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a88ba5  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a88ba6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a88ba7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88ba8  2bc9                   +sub ecx, ecx
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
    // 00a88baa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a88bab  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a88bad  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a88baf  4f                     -dec edi
    (cpu.edi)--;
L_0x00a88bb0:
    // 00a88bb0  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a88bb2  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a88bb4  3c00                   +cmp al, 0
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
    // 00a88bb6  7410                   -je 0xa88bc8
    if (cpu.flags.zf)
    {
        goto L_0x00a88bc8;
    }
    // 00a88bb8  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a88bbb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a88bbe  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a88bc1  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a88bc4  3c00                   +cmp al, 0
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
    // 00a88bc6  75e8                   -jne 0xa88bb0
    if (!cpu.flags.zf)
    {
        goto L_0x00a88bb0;
    }
L_0x00a88bc8:
    // 00a88bc8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88bc9  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a88bca  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a88bcc  681c49a900             -push 0xa9491c
    app->getMemory<x86::reg32>(cpu.esp-4) = 11094300 /*0xa9491c*/;
    cpu.esp -= 4;
    // 00a88bd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88bd2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a88bd4  2eff155403a900         -call dword ptr cs:[0xa90354]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076436) /* 0xa90354 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88bdb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a88be0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88be1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88be2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88be3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88be4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88be5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88bf0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88bf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88c00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88c00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88c01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88c02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88c03  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a88c06  c7442408000000c0       -mov dword ptr [esp + 8], 0xc0000000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 3221225472 /*0xc0000000*/;
    // 00a88c0e  c744240c7e015041       -mov dword ptr [esp + 0xc], 0x4150017e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1095762302 /*0x4150017e*/;
    // 00a88c16  c7042400000080         -mov dword ptr [esp], 0x80000000
    app->getMemory<x86::reg32>(cpu.esp) = 2147483648 /*0x80000000*/;
    // 00a88c1d  c7442404ffff4741       -mov dword ptr [esp + 4], 0x4147ffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1095237631 /*0x4147ffff*/;
    // 00a88c25  803d8d26a90003         +cmp byte ptr [0xa9268d], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11085453) /* 0xa9268d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88c2c  7249                   -jb 0xa88c77
    if (cpu.flags.cf)
    {
        goto L_0x00a88c77;
    }
    // 00a88c2e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a88c32  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a88c36  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a88c39  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a88c3d  e8b4270000             -call 0xa8b3f6
    cpu.esp -= 4;
    sub_a8b3f6(app, cpu);
    if (cpu.terminate) return;
    // 00a88c42  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a88c45  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a88c49  e86b2b0000             -call 0xa8b7b9
    cpu.esp -= 4;
    sub_a8b7b9(app, cpu);
    if (cpu.terminate) return;
    // 00a88c4e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a88c50  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a88c52  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a88c56  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a88c5a  e89d290000             -call 0xa8b5fc
    cpu.esp -= 4;
    sub_a8b5fc(app, cpu);
    if (cpu.terminate) return;
    // 00a88c5f  bb3a8c30e2             -mov ebx, 0xe2308c3a
    cpu.ebx = 3794832442 /*0xe2308c3a*/;
    // 00a88c64  b98e79453e             -mov ecx, 0x3e45798e
    cpu.ecx = 1044740494 /*0x3e45798e*/;
    // 00a88c69  e8e82c0000             -call 0xa8b956
    cpu.esp -= 4;
    sub_a8b956(app, cpu);
    if (cpu.terminate) return;
    // 00a88c6e  7e07                   -jle 0xa88c77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a88c77;
    }
    // 00a88c70  800d9026a90001         -or byte ptr [0xa92690], 1
    app->getMemory<x86::reg8>(x86::reg32(11085456) /* 0xa92690 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00a88c77:
    // 00a88c77  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a88c7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88c7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88c7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88c7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88c7e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88c7e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88c7f  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a88c81  e802000000             -call 0xa88c88
    cpu.esp -= 4;
    sub_a88c88(app, cpu);
    if (cpu.terminate) return;
    // 00a88c86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88c87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88c88(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88c88  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88c89  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a88c8b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88c8c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88c8d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a88c90  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a88c92  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a88c94  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00a88c97  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a88c9a  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a88c9d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a88c9f  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a88ca2  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a88ca5  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a88ca8  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00a88cab  7407                   -je 0xa88cb4
    if (cpu.flags.zf)
    {
        goto L_0x00a88cb4;
    }
    // 00a88cad  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00a88cb2  eb3a                   -jmp 0xa88cee
    goto L_0x00a88cee;
L_0x00a88cb4:
    // 00a88cb4  f6c180                 +test cl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 128 /*0x80*/));
    // 00a88cb7  7407                   -je 0xa88cc0
    if (cpu.flags.zf)
    {
        goto L_0x00a88cc0;
    }
    // 00a88cb9  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00a88cbe  eb2e                   -jmp 0xa88cee
    goto L_0x00a88cee;
L_0x00a88cc0:
    // 00a88cc0  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 00a88cc3  7407                   -je 0xa88ccc
    if (cpu.flags.zf)
    {
        goto L_0x00a88ccc;
    }
    // 00a88cc5  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 00a88cca  eb22                   -jmp 0xa88cee
    goto L_0x00a88cee;
L_0x00a88ccc:
    // 00a88ccc  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a88ccf  7407                   -je 0xa88cd8
    if (cpu.flags.zf)
    {
        goto L_0x00a88cd8;
    }
    // 00a88cd1  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 00a88cd6  eb16                   -jmp 0xa88cee
    goto L_0x00a88cee;
L_0x00a88cd8:
    // 00a88cd8  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 00a88cdb  7407                   -je 0xa88ce4
    if (cpu.flags.zf)
    {
        goto L_0x00a88ce4;
    }
    // 00a88cdd  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 00a88ce2  eb0a                   -jmp 0xa88cee
    goto L_0x00a88cee;
L_0x00a88ce4:
    // 00a88ce4  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 00a88ce7  7405                   -je 0xa88cee
    if (cpu.flags.zf)
    {
        goto L_0x00a88cee;
    }
    // 00a88ce9  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
L_0x00a88cee:
    // 00a88cee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a88cf0  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00a88cf3  8b0485a827a900         -mov eax, dword ptr [eax*4 + 0xa927a8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085736) /* 0xa927a8 */ + cpu.eax * 4);
    // 00a88cfa  8975d8                 -mov dword ptr [ebp - 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.esi;
    // 00a88cfd  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00a88d00  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a88d03  740d                   -je 0xa88d12
    if (cpu.flags.zf)
    {
        goto L_0x00a88d12;
    }
    // 00a88d05  dd05ec1ea900           +fld qword ptr [0xa91eec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(11083500) /* 0xa91eec */)));
    // 00a88d0b  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a88d0d  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a88d10  eb42                   -jmp 0xa88d54
    goto L_0x00a88d54;
L_0x00a88d12:
    // 00a88d12  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 00a88d15  740a                   -je 0xa88d21
    if (cpu.flags.zf)
    {
        goto L_0x00a88d21;
    }
    // 00a88d17  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a88d19  894df0                 -mov dword ptr [ebp - 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ecx;
    // 00a88d1c  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a88d1f  eb33                   -jmp 0xa88d54
    goto L_0x00a88d54;
L_0x00a88d21:
    // 00a88d21  f6c540                 +test ch, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 64 /*0x40*/));
    // 00a88d24  740f                   -je 0xa88d35
    if (cpu.flags.zf)
    {
        goto L_0x00a88d35;
    }
    // 00a88d26  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a88d28  bb0000f03f             -mov ebx, 0x3ff00000
    cpu.ebx = 1072693248 /*0x3ff00000*/;
    // 00a88d2d  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a88d30  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a88d33  eb1f                   -jmp 0xa88d54
    goto L_0x00a88d54;
L_0x00a88d35:
    // 00a88d35  f6c580                 +test ch, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 128 /*0x80*/));
    // 00a88d38  740f                   -je 0xa88d49
    if (cpu.flags.zf)
    {
        goto L_0x00a88d49;
    }
    // 00a88d3a  a1ec1ea900             -mov eax, dword ptr [0xa91eec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11083500) /* 0xa91eec */);
    // 00a88d3f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a88d42  a1f01ea900             -mov eax, dword ptr [0xa91ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11083504) /* 0xa91ef0 */);
    // 00a88d47  eb08                   -jmp 0xa88d51
    goto L_0x00a88d51;
L_0x00a88d49:
    // 00a88d49  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a88d4b  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a88d4e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
L_0x00a88d51:
    // 00a88d51  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00a88d54:
    // 00a88d54  8d45d8                 -lea eax, [ebp - 0x28]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a88d57  e8822c0000             -call 0xa8b9de
    cpu.esp -= 4;
    sub_a8b9de(app, cpu);
    if (cpu.terminate) return;
    // 00a88d5c  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a88d5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88d60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88d61  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88d62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a88d63(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88d63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88d64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a88d66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a88d67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88d68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88d69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88d6a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a88d6d  8a5510                 -mov dl, byte ptr [ebp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00a88d70  80fa01                 +cmp dl, 1
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
    // 00a88d73  7231                   -jb 0xa88da6
    if (cpu.flags.cf)
    {
        goto L_0x00a88da6;
    }
    // 00a88d75  80fa03                 +cmp dl, 3
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88d78  7607                   -jbe 0xa88d81
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a88d81;
    }
    // 00a88d7a  80fa04                 +cmp dl, 4
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88d7d  7413                   -je 0xa88d92
    if (cpu.flags.zf)
    {
        goto L_0x00a88d92;
    }
    // 00a88d7f  eb25                   -jmp 0xa88da6
    goto L_0x00a88da6;
L_0x00a88d81:
    // 00a88d81  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a88d83  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a88d85  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a88d8a  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a88d8d  80cc20                 +or ah, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00a88d90  eb36                   -jmp 0xa88dc8
    goto L_0x00a88dc8;
L_0x00a88d92:
    // 00a88d92  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a88d94  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    cpu.fpu.pop();
    // 00a88d97  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a88d99  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a88d9a  760a                   -jbe 0xa88da6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a88da6;
    }
    // 00a88d9c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a88d9e  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 00a88da1  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
    // 00a88da4  eb2a                   -jmp 0xa88dd0
    goto L_0x00a88dd0;
L_0x00a88da6:
    // 00a88da6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a88da8  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00a88daa  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a88dac  80cf81                 -or bh, 0x81
    cpu.bh |= x86::reg8(x86::sreg8(129 /*0x81*/));
    // 00a88daf  80fa06                 +cmp dl, 6
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(6 /*0x6*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88db2  750f                   -jne 0xa88dc3
    if (!cpu.flags.zf)
    {
        goto L_0x00a88dc3;
    }
    // 00a88db4  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a88db6  dc5d08                 +fcomp qword ptr [ebp + 8]
    cpu.fpu.compare(cpu.fpu.st(0), app->getMemory<double>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    cpu.fpu.pop();
    // 00a88db9  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a88dbb  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a88dbc  7605                   -jbe 0xa88dc3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a88dc3;
    }
    // 00a88dbe  80cd11                 -or ch, 0x11
    cpu.ch |= x86::reg8(x86::sreg8(17 /*0x11*/));
    // 00a88dc1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a88dc3:
    // 00a88dc3  8d5508                 -lea edx, [ebp + 8]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a88dc6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a88dc8:
    // 00a88dc8  e8b1feffff             -call 0xa88c7e
    cpu.esp -= 4;
    sub_a88c7e(app, cpu);
    if (cpu.terminate) return;
    // 00a88dcd  dd5de8                 -fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a88dd0:
    // 00a88dd0  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a88dd3  8d65f0                 -lea esp, [ebp - 0x10]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a88dd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88dd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88dd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88dd9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88dda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ddb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a88de0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88de0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88de1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88de2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88de3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88de4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88de5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a88de7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a88dea  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88df0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a88df3  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a88df6  83f901                 +cmp ecx, 1
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
    // 00a88df9  741e                   -je 0xa88e19
    if (cpu.flags.zf)
    {
        goto L_0x00a88e19;
    }
    // 00a88dfb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a88dfd  7413                   -je 0xa88e12
    if (cpu.flags.zf)
    {
        goto L_0x00a88e12;
    }
    // 00a88dff  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a88e02  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88e08  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a88e0d  e9dc000000             -jmp 0xa88eee
    goto L_0x00a88eee;
L_0x00a88e12:
    // 00a88e12  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a88e19:
    // 00a88e19  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 00a88e1d  7522                   -jne 0xa88e41
    if (!cpu.flags.zf)
    {
        goto L_0x00a88e41;
    }
    // 00a88e1f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a88e24  e8f7130000             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a88e29  804a0c20               -or byte ptr [edx + 0xc], 0x20
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a88e2d  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a88e30  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88e36  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a88e3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88e3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88e3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88e3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88e3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88e40  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a88e41:
    // 00a88e41  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a88e44  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00a88e48  7507                   -jne 0xa88e51
    if (!cpu.flags.zf)
    {
        goto L_0x00a88e51;
    }
    // 00a88e4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a88e4c  e8af000000             -call 0xa88f00
    cpu.esp -= 4;
    sub_a88f00(app, cpu);
    if (cpu.terminate) return;
L_0x00a88e51:
    // 00a88e51  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 00a88e56  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a88e59  7547                   -jne 0xa88ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00a88ea2;
    }
    // 00a88e5b  8a420c                 -mov al, byte ptr [edx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a88e5e  b900060000             -mov ecx, 0x600
    cpu.ecx = 1536 /*0x600*/;
    // 00a88e63  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00a88e65  753b                   -jne 0xa88ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00a88ea2;
    }
    // 00a88e67  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00a88e6b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a88e6d  c6000d                 -mov byte ptr [eax], 0xd
    app->getMemory<x86::reg8>(cpu.eax) = 13 /*0xd*/;
    // 00a88e70  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a88e72  45                     -inc ebp
    (cpu.ebp)++;
    // 00a88e73  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a88e76  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a88e78  40                     -inc eax
    (cpu.eax)++;
    // 00a88e79  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a88e7c  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a88e7f  39f0                   +cmp eax, esi
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
    // 00a88e81  751f                   -jne 0xa88ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00a88ea2;
    }
    // 00a88e83  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a88e85  e8f6ebffff             -call 0xa87a80
    cpu.esp -= 4;
    sub_a87a80(app, cpu);
    if (cpu.terminate) return;
    // 00a88e8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88e8c  7414                   -je 0xa88ea2
    if (cpu.flags.zf)
    {
        goto L_0x00a88ea2;
    }
    // 00a88e8e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a88e91  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88e97  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a88e9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88e9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88e9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88e9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ea0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ea1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a88ea2:
    // 00a88ea2  804a0d10               -or byte ptr [edx + 0xd], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00a88ea6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a88ea8  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00a88eaa  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a88eac  47                     -inc edi
    (cpu.edi)++;
    // 00a88ead  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a88eb0  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00a88eb2  45                     -inc ebp
    (cpu.ebp)++;
    // 00a88eb3  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a88eb6  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00a88eb9  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00a88ebb  7505                   -jne 0xa88ec2
    if (!cpu.flags.zf)
    {
        goto L_0x00a88ec2;
    }
    // 00a88ebd  3b6a14                 +cmp ebp, dword ptr [edx + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a88ec0  751f                   -jne 0xa88ee1
    if (!cpu.flags.zf)
    {
        goto L_0x00a88ee1;
    }
L_0x00a88ec2:
    // 00a88ec2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a88ec4  e8b7ebffff             -call 0xa87a80
    cpu.esp -= 4;
    sub_a87a80(app, cpu);
    if (cpu.terminate) return;
    // 00a88ec9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a88ecb  7414                   -je 0xa88ee1
    if (cpu.flags.zf)
    {
        goto L_0x00a88ee1;
    }
    // 00a88ecd  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a88ed0  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88ed6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a88edb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88edc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88edd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ede  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88edf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ee0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a88ee1:
    // 00a88ee1  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a88ee4  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88eea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a88eec  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x00a88eee:
    // 00a88eee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88eef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ef0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ef1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ef2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88ef3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88f00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a88f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a88f02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a88f03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a88f05  e8062b0000             -call 0xa8ba10
    cpu.esp -= 4;
    sub_a8ba10(app, cpu);
    if (cpu.terminate) return;
    // 00a88f0a  837a1400               +cmp dword ptr [edx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a88f0e  7526                   -jne 0xa88f36
    if (!cpu.flags.zf)
    {
        goto L_0x00a88f36;
    }
    // 00a88f10  8a620d                 -mov ah, byte ptr [edx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a88f13  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a88f16  7409                   -je 0xa88f21
    if (cpu.flags.zf)
    {
        goto L_0x00a88f21;
    }
    // 00a88f18  c7421486000000         -mov dword ptr [edx + 0x14], 0x86
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 134 /*0x86*/;
    // 00a88f1f  eb15                   -jmp 0xa88f36
    goto L_0x00a88f36;
L_0x00a88f21:
    // 00a88f21  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a88f24  7409                   -je 0xa88f2f
    if (cpu.flags.zf)
    {
        goto L_0x00a88f2f;
    }
    // 00a88f26  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00a88f2d  eb07                   -jmp 0xa88f36
    goto L_0x00a88f36;
L_0x00a88f2f:
    // 00a88f2f  c7421400100000         -mov dword ptr [edx + 0x14], 0x1000
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4096 /*0x1000*/;
L_0x00a88f36:
    // 00a88f36  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a88f39  e872ddffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a88f3e  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a88f41  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a88f44  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a88f47  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00a88f4b  7523                   -jne 0xa88f70
    if (!cpu.flags.zf)
    {
        goto L_0x00a88f70;
    }
    // 00a88f4d  8a4a0d                 -mov cl, byte ptr [edx + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a88f50  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a88f53  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 00a88f56  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a88f58  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a88f5b  80cd04                 +or ch, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a88f5e  8d5a18                 -lea ebx, [edx + 0x18]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00a88f61  886a0d                 -mov byte ptr [edx + 0xd], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00a88f64  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a88f67  c7421401000000         -mov dword ptr [edx + 0x14], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00a88f6e  eb04                   -jmp 0xa88f74
    goto L_0x00a88f74;
L_0x00a88f70:
    // 00a88f70  804a0c08               -or byte ptr [edx + 0xc], 8
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00a88f74:
    // 00a88f74  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a88f77  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a88f7a  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a88f81  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a88f83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88f84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88f85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a88f86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a88f90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a88f90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a88f91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a88f92  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a88f93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a88f94  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a88f97  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a88f99  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00a88f9b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a88f9d  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a88fa2  885c246c               -mov byte ptr [esp + 0x6c], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 00a88fa6  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00a88fa8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a88fab  66895c241e             -mov word ptr [esp + 0x1e], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 00a88fb0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a88fb2  66894c241c             -mov word ptr [esp + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00a88fb7  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a88fbb  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 00a88fbd  89542468               -mov dword ptr [esp + 0x68], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 00a88fc1  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00a88fc3  0f8461030000           -je 0xa8932a
    if (cpu.flags.zf)
    {
        goto L_0x00a8932a;
    }
L_0x00a88fc9:
    // 00a88fc9  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a88fcd  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a88fd1  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 00a88fd3  45                     -inc ebp
    (cpu.ebp)++;
    // 00a88fd4  80fd25                 +cmp ch, 0x25
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a88fd7  7411                   -je 0xa88fea
    if (cpu.flags.zf)
    {
        goto L_0x00a88fea;
    }
    // 00a88fd9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a88fdb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a88fdd  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
    // 00a88fdf  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 00a88fe3  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a88fe5  e918030000             -jmp 0xa89302
    goto L_0x00a89302;
L_0x00a88fea:
    // 00a88fea  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a88fec  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a88fee  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a88ff2  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00a88ff6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a88ff8  e83b030000             -call 0xa89338
    cpu.esp -= 4;
    sub_a89338(app, cpu);
    if (cpu.terminate) return;
    // 00a88ffd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a88fff  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a89003  45                     -inc ebp
    (cpu.ebp)++;
    // 00a89004  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a89006  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00a89009  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 00a8900d  88442415               -mov byte ptr [esp + 0x15], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 00a89011  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a89013  0f8411030000           -je 0xa8932a
    if (cpu.flags.zf)
    {
        goto L_0x00a8932a;
    }
    // 00a89019  3c6e                   +cmp al, 0x6e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8901b  0f8570010000           -jne 0xa89191
    if (!cpu.flags.zf)
    {
        goto L_0x00a89191;
    }
    // 00a89021  8a5c241e               -mov bl, byte ptr [esp + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00a89025  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a89028  744f                   -je 0xa89079
    if (cpu.flags.zf)
    {
        goto L_0x00a89079;
    }
    // 00a8902a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a8902d  741f                   -je 0xa8904e
    if (cpu.flags.zf)
    {
        goto L_0x00a8904e;
    }
    // 00a8902f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a89031  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a89034  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a89036  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
    // 00a89039  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8903d  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00a89040  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a89044  803800                 +cmp byte ptr [eax], 0
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
    // 00a89047  7580                   -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a89049  e9dc020000             -jmp 0xa8932a
    goto L_0x00a8932a;
L_0x00a8904e:
    // 00a8904e  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a89051  0f84e8000000           -je 0xa8913f
    if (cpu.flags.zf)
    {
        goto L_0x00a8913f;
    }
    // 00a89057  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a89059  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8905c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a8905e  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a89061  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a89065  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a89067  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a8906b  803800                 +cmp byte ptr [eax], 0
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
    // 00a8906e  0f8555ffffff           -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a89074  e9b1020000             -jmp 0xa8932a
    goto L_0x00a8932a;
L_0x00a89079:
    // 00a89079  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00a8907c  0f8489000000           -je 0xa8910b
    if (cpu.flags.zf)
    {
        goto L_0x00a8910b;
    }
    // 00a89082  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a89085  742b                   -je 0xa890b2
    if (cpu.flags.zf)
    {
        goto L_0x00a890b2;
    }
    // 00a89087  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a89089  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8908c  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00a8908e  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 00a89091  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a89095  66268902               -mov word ptr es:[edx], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 00a89099  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a8909d  803800                 +cmp byte ptr [eax], 0
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
    // 00a890a0  0f8523ffffff           -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a890a6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a890aa  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a890ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a890ae  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a890af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a890b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a890b1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a890b2:
    // 00a890b2  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a890b5  742a                   -je 0xa890e1
    if (cpu.flags.zf)
    {
        goto L_0x00a890e1;
    }
    // 00a890b7  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a890b9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a890bc  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00a890be  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a890c1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a890c5  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00a890c8  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a890cc  803800                 +cmp byte ptr [eax], 0
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
    // 00a890cf  0f85f4feffff           -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a890d5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a890d9  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a890dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a890dd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a890de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a890df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a890e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a890e1:
    // 00a890e1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a890e3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a890e6  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a890e8  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a890eb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a890ef  668902                 -mov word ptr [edx], ax
    app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00a890f2  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a890f6  803800                 +cmp byte ptr [eax], 0
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
    // 00a890f9  0f85cafeffff           -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a890ff  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a89103  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a89106  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89107  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89108  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89109  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8910a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8910b:
    // 00a8910b  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a8910e  742a                   -je 0xa8913a
    if (cpu.flags.zf)
    {
        goto L_0x00a8913a;
    }
    // 00a89110  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a89112  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a89115  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a89117  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 00a8911a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8911e  268902                 -mov dword ptr es:[edx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00a89121  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a89125  803800                 +cmp byte ptr [eax], 0
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
    // 00a89128  0f859bfeffff           -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a8912e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a89132  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a89135  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89136  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89137  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89138  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89139  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8913a:
    // 00a8913a  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a8913d  7429                   -je 0xa89168
    if (cpu.flags.zf)
    {
        goto L_0x00a89168;
    }
L_0x00a8913f:
    // 00a8913f  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi);
    // 00a89141  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89144  892e                   -mov dword ptr [esi], ebp
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00a89146  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a89149  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8914d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a8914f  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a89153  803800                 +cmp byte ptr [eax], 0
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
    // 00a89156  0f856dfeffff           -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a8915c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a89160  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a89163  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89164  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89165  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89166  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89167  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89168:
    // 00a89168  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8916a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8916d  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00a8916f  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00a89172  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a89176  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a89178  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a8917c  803800                 +cmp byte ptr [eax], 0
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
    // 00a8917f  0f8544feffff           -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a89185  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a89189  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a8918c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8918d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8918e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8918f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89190  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89191:
    // 00a89191  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00a89195  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a89197  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a89199  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00a8919d  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00a891a1  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a891a5  e8ea050000             -call 0xa89794
    cpu.esp -= 4;
    sub_a89794(app, cpu);
    if (cpu.terminate) return;
    // 00a891aa  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a891ac  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00a891b0  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a891b2  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a891b4  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a891b8  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a891bc  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a891c0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a891c2  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a891c6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a891c8  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a891cc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a891ce  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a891d2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a891d4  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a891d8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a891da  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a891dc  8a54241e               -mov dl, byte ptr [esp + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00a891e0  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a891e4  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00a891e7  751d                   -jne 0xa89206
    if (!cpu.flags.zf)
    {
        goto L_0x00a89206;
    }
    // 00a891e9  807c241620             +cmp byte ptr [esp + 0x16], 0x20
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a891ee  7516                   -jne 0xa89206
    if (!cpu.flags.zf)
    {
        goto L_0x00a89206;
    }
L_0x00a891f0:
    // 00a891f0  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a891f5  7e0f                   -jle 0xa89206
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a89206;
    }
    // 00a891f7  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00a891fc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a891fe  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89200  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a89204  ebea                   -jmp 0xa891f0
    goto L_0x00a891f0;
L_0x00a89206:
    // 00a89206  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a8920a  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a8920e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89210  7e16                   -jle 0xa89228
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a89228;
    }
L_0x00a89212:
    // 00a89212  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a89214  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a89216  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a89218  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8921a  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a8921e  4a                     -dec edx
    (cpu.edx)--;
    // 00a8921f  43                     -inc ebx
    (cpu.ebx)++;
    // 00a89220  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a89224  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a89226  7fea                   -jg 0xa89212
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a89212;
    }
L_0x00a89228:
    // 00a89228  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8922d  7e0f                   -jle 0xa8923e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8923e;
    }
    // 00a8922f  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a89234  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a89236  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89238  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8923c  ebea                   -jmp 0xa89228
    goto L_0x00a89228;
L_0x00a8923e:
    // 00a8923e  8a5c2415               -mov bl, byte ptr [esp + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 00a89242  80fb73                 +cmp bl, 0x73
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89245  7533                   -jne 0xa8927a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8927a;
    }
    // 00a89247  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a8924c  740f                   -je 0xa8925d
    if (cpu.flags.zf)
    {
        goto L_0x00a8925d;
    }
    // 00a8924e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a89250  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00a89252  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89254  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a89256  e8d5040000             -call 0xa89730
    cpu.esp -= 4;
    sub_a89730(app, cpu);
    if (cpu.terminate) return;
    // 00a8925b  eb4e                   -jmp 0xa892ab
    goto L_0x00a892ab;
L_0x00a8925d:
    // 00a8925d  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 00a89262  7e47                   -jle 0xa892ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a892ab;
    }
    // 00a89264  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a89266  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a89268  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a8926c  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8926e  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a89272  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a89273  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a89274  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a89278  ebe3                   -jmp 0xa8925d
    goto L_0x00a8925d;
L_0x00a8927a:
    // 00a8927a  80fb53                 +cmp bl, 0x53
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8927d  750f                   -jne 0xa8928e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8928e;
    }
    // 00a8927f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a89281  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00a89283  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89285  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a89287  e8a4040000             -call 0xa89730
    cpu.esp -= 4;
    sub_a89730(app, cpu);
    if (cpu.terminate) return;
    // 00a8928c  eb1d                   -jmp 0xa892ab
    goto L_0x00a892ab;
L_0x00a8928e:
    // 00a8928e  837c242800             +cmp dword ptr [esp + 0x28], 0
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
    // 00a89293  7e16                   -jle 0xa892ab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a892ab;
    }
    // 00a89295  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a89297  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a89299  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a8929d  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8929f  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a892a3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a892a4  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a892a5  894c2428               -mov dword ptr [esp + 0x28], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00a892a9  ebe3                   -jmp 0xa8928e
    goto L_0x00a8928e;
L_0x00a892ab:
    // 00a892ab  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a892b0  7e0f                   -jle 0xa892c1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a892c1;
    }
    // 00a892b2  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a892b7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a892b9  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a892bb  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a892bf  ebea                   -jmp 0xa892ab
    goto L_0x00a892ab;
L_0x00a892c1:
    // 00a892c1  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 00a892c6  7e16                   -jle 0xa892de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a892de;
    }
    // 00a892c8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a892ca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a892cc  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a892d0  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a892d2  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a892d6  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a892d7  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a892d8  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00a892dc  ebe3                   -jmp 0xa892c1
    goto L_0x00a892c1;
L_0x00a892de:
    // 00a892de  837c243400             +cmp dword ptr [esp + 0x34], 0
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
    // 00a892e3  7e0f                   -jle 0xa892f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a892f4;
    }
    // 00a892e5  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a892ea  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a892ec  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a892ee  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a892f2  ebea                   -jmp 0xa892de
    goto L_0x00a892de;
L_0x00a892f4:
    // 00a892f4  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00a892f9  7407                   -je 0xa89302
    if (cpu.flags.zf)
    {
        goto L_0x00a89302;
    }
L_0x00a892fb:
    // 00a892fb  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a89300  7f19                   -jg 0xa8931b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8931b;
    }
L_0x00a89302:
    // 00a89302  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a89306  803800                 +cmp byte ptr [eax], 0
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
    // 00a89309  0f85bafcffff           -jne 0xa88fc9
    if (!cpu.flags.zf)
    {
        goto L_0x00a88fc9;
    }
    // 00a8930f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a89313  83c470                 +add esp, 0x70
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
    // 00a89316  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89317  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89318  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89319  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8931a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8931b:
    // 00a8931b  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00a89320  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a89322  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89324  ff4c2404               +dec dword ptr [esp + 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a89328  ebd1                   -jmp 0xa892fb
    goto L_0x00a892fb;
L_0x00a8932a:
    // 00a8932a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8932e  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a89331  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89332  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89333  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89334  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89335  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a89338(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89338  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89339  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8933a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8933b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8933d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8933f  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 00a89343  e844010000             -call 0xa8948c
    cpu.esp -= 4;
    sub_a8948c(app, cpu);
    if (cpu.terminate) return;
    // 00a89348  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a8934f  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89352  7524                   -jne 0xa89378
    if (!cpu.flags.zf)
    {
        goto L_0x00a89378;
    }
    // 00a89354  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a89356  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89359  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a8935b  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a8935e  895304                 -mov dword ptr [ebx + 4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a89361  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a89363  7d10                   -jge 0xa89375
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a89375;
    }
    // 00a89365  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a89367  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00a8936a  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00a8936c  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a8936f  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a89372  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x00a89375:
    // 00a89375  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a89376  eb1f                   -jmp 0xa89397
    goto L_0x00a89397;
L_0x00a89378:
    // 00a89378  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8937a  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8937d  7218                   -jb 0xa89397
    if (cpu.flags.cf)
    {
        goto L_0x00a89397;
    }
    // 00a8937f  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89382  7713                   -ja 0xa89397
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a89397;
    }
    // 00a89384  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a89388  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8938a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8938c  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a8938f  01d1                   +add ecx, edx
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
    // 00a89391  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a89392  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a89395  ebe1                   -jmp 0xa89378
    goto L_0x00a89378;
L_0x00a89397:
    // 00a89397  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 00a8939e  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a893a1  7554                   -jne 0xa893f7
    if (!cpu.flags.zf)
    {
        goto L_0x00a893f7;
    }
    // 00a893a3  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a893aa  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a893ad  40                     -inc eax
    (cpu.eax)++;
    // 00a893ae  80fd2a                 +cmp ch, 0x2a
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a893b1  751b                   -jne 0xa893ce
    if (!cpu.flags.zf)
    {
        goto L_0x00a893ce;
    }
    // 00a893b3  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a893b5  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a893b8  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a893ba  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a893bd  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a893c0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a893c2  7d07                   -jge 0xa893cb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a893cb;
    }
    // 00a893c4  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x00a893cb:
    // 00a893cb  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a893cc  eb1f                   -jmp 0xa893ed
    goto L_0x00a893ed;
L_0x00a893ce:
    // 00a893ce  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a893d0  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a893d3  7218                   -jb 0xa893ed
    if (cpu.flags.cf)
    {
        goto L_0x00a893ed;
    }
    // 00a893d5  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a893d8  7713                   -ja 0xa893ed
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a893ed;
    }
    // 00a893da  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a893de  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a893e0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a893e2  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a893e5  01d1                   +add ecx, edx
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
    // 00a893e7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a893e8  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a893eb  ebe1                   -jmp 0xa893ce
    goto L_0x00a893ce;
L_0x00a893ed:
    // 00a893ed  837b08ff               +cmp dword ptr [ebx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a893f1  7404                   -je 0xa893f7
    if (cpu.flags.zf)
    {
        goto L_0x00a893f7;
    }
    // 00a893f3  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x00a893f7:
    // 00a893f7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a893f9  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a893fc  80fa4e                 +cmp dl, 0x4e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a893ff  721f                   -jb 0xa89420
    if (cpu.flags.cf)
    {
        goto L_0x00a89420;
    }
    // 00a89401  0f867b000000           -jbe 0xa89482
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89482;
    }
    // 00a89407  80fa6c                 +cmp dl, 0x6c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(108 /*0x6c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8940a  720b                   -jb 0xa89417
    if (cpu.flags.cf)
    {
        goto L_0x00a89417;
    }
    // 00a8940c  762b                   -jbe 0xa89439
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89439;
    }
    // 00a8940e  80fa77                 +cmp dl, 0x77
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89411  7426                   -je 0xa89439
    if (cpu.flags.zf)
    {
        goto L_0x00a89439;
    }
    // 00a89413  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89414  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89415  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89416  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89417:
    // 00a89417  80fa68                 +cmp dl, 0x68
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(104 /*0x68*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8941a  742b                   -je 0xa89447
    if (cpu.flags.zf)
    {
        goto L_0x00a89447;
    }
    // 00a8941c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8941d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8941e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8941f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89420:
    // 00a89420  80fa49                 +cmp dl, 0x49
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(73 /*0x49*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89423  720b                   -jb 0xa89430
    if (cpu.flags.cf)
    {
        goto L_0x00a89430;
    }
    // 00a89425  7626                   -jbe 0xa8944d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8944d;
    }
    // 00a89427  80fa4c                 +cmp dl, 0x4c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(76 /*0x4c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8942a  743d                   -je 0xa89469
    if (cpu.flags.zf)
    {
        goto L_0x00a89469;
    }
    // 00a8942c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8942d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8942e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8942f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89430:
    // 00a89430  80fa46                 +cmp dl, 0x46
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89433  7443                   -je 0xa89478
    if (cpu.flags.zf)
    {
        goto L_0x00a89478;
    }
    // 00a89435  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89436  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89437  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89438  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89439:
    // 00a89439  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00a8943c  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a8943f  40                     -inc eax
    (cpu.eax)++;
    // 00a89440  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00a89443  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89444  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89445  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89446  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89447:
    // 00a89447  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00a8944b  eb39                   -jmp 0xa89486
    goto L_0x00a89486;
L_0x00a8944d:
    // 00a8944d  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89451  7535                   -jne 0xa89488
    if (!cpu.flags.zf)
    {
        goto L_0x00a89488;
    }
    // 00a89453  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89457  752f                   -jne 0xa89488
    if (!cpu.flags.zf)
    {
        goto L_0x00a89488;
    }
    // 00a89459  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00a8945c  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8945f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a89462  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 00a89465  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89466  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89467  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89468  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89469:
    // 00a89469  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00a8946c  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8946f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a89471  88531f                 -mov byte ptr [ebx + 0x1f], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 00a89474  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89475  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89476  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89477  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89478:
    // 00a89478  804b1e80               -or byte ptr [ebx + 0x1e], 0x80
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a8947c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8947e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8947f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89480  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89481  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89482:
    // 00a89482  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a89486:
    // 00a89486  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a89488:
    // 00a89488  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89489  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8948a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8948b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8948c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8948c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8948d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8948e  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 00a89494  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a89496  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89499  7506                   -jne 0xa894a1
    if (!cpu.flags.zf)
    {
        goto L_0x00a894a1;
    }
    // 00a8949b  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a8949f  eb42                   -jmp 0xa894e3
    goto L_0x00a894e3;
L_0x00a894a1:
    // 00a894a1  80fb23                 +cmp bl, 0x23
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(35 /*0x23*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a894a4  7506                   -jne 0xa894ac
    if (!cpu.flags.zf)
    {
        goto L_0x00a894ac;
    }
    // 00a894a6  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a894aa  eb37                   -jmp 0xa894e3
    goto L_0x00a894e3;
L_0x00a894ac:
    // 00a894ac  80fb2b                 +cmp bl, 0x2b
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a894af  7513                   -jne 0xa894c4
    if (!cpu.flags.zf)
    {
        goto L_0x00a894c4;
    }
    // 00a894b1  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00a894b4  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a894b7  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 00a894b9  886a1e                 -mov byte ptr [edx + 0x1e], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 00a894bc  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 00a894bf  885a1e                 -mov byte ptr [edx + 0x1e], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 00a894c2  eb1f                   -jmp 0xa894e3
    goto L_0x00a894e3;
L_0x00a894c4:
    // 00a894c4  80fb20                 +cmp bl, 0x20
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
    // 00a894c7  7512                   -jne 0xa894db
    if (!cpu.flags.zf)
    {
        goto L_0x00a894db;
    }
    // 00a894c9  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00a894cc  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00a894cf  7512                   -jne 0xa894e3
    if (!cpu.flags.zf)
    {
        goto L_0x00a894e3;
    }
    // 00a894d1  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 00a894d3  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a894d6  884a1e                 -mov byte ptr [edx + 0x1e], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00a894d9  eb08                   -jmp 0xa894e3
    goto L_0x00a894e3;
L_0x00a894db:
    // 00a894db  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a894de  7511                   -jne 0xa894f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a894f1;
    }
    // 00a894e0  885a16                 -mov byte ptr [edx + 0x16], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x00a894e3:
    // 00a894e3  40                     -inc eax
    (cpu.eax)++;
    // 00a894e4  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a894e6  80fb2d                 +cmp bl, 0x2d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a894e9  75b6                   -jne 0xa894a1
    if (!cpu.flags.zf)
    {
        goto L_0x00a894a1;
    }
    // 00a894eb  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a894ef  ebf2                   -jmp 0xa894e3
    goto L_0x00a894e3;
L_0x00a894f1:
    // 00a894f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a894f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a894f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a894f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a894f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a894f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a894f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a894f7  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a894f8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a894fa  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a894fc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a894fe  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 00a89500  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a89502:
    // 00a89502  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a89504  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 00a89507  42                     -inc edx
    (cpu.edx)++;
    // 00a89508  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00a8950a  7407                   -je 0xa89513
    if (cpu.flags.zf)
    {
        goto L_0x00a89513;
    }
    // 00a8950c  39f8                   +cmp eax, edi
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
    // 00a8950e  7403                   -je 0xa89513
    if (cpu.flags.zf)
    {
        goto L_0x00a89513;
    }
    // 00a89510  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a89511  ebef                   -jmp 0xa89502
    goto L_0x00a89502;
L_0x00a89513:
    // 00a89513  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89514  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89515  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89516  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89517  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a89518(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89518  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89519  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8951a  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8951b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8951e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a89520  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a89522  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a89524  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a89526  83feff                 +cmp esi, -1
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
    // 00a89529  7521                   -jne 0xa8954c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8954c;
    }
L_0x00a8952b:
    // 00a8952b  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00a8952f  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 00a89532  7440                   -je 0xa89574
    if (cpu.flags.zf)
    {
        goto L_0x00a89574;
    }
    // 00a89534  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a89536  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a89538  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 00a8953b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8953e  e80d250000             -call 0xa8ba50
    cpu.esp -= 4;
    sub_a8ba50(app, cpu);
    if (cpu.terminate) return;
    // 00a89543  83f8ff                 +cmp eax, -1
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
    // 00a89546  74e3                   -je 0xa8952b
    if (cpu.flags.zf)
    {
        goto L_0x00a8952b;
    }
    // 00a89548  01c1                   +add ecx, eax
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
    // 00a8954a  ebdf                   -jmp 0xa8952b
    goto L_0x00a8952b;
L_0x00a8954c:
    // 00a8954c  6626833b00             +cmp word ptr es:[ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a89551  741d                   -je 0xa89570
    if (cpu.flags.zf)
    {
        goto L_0x00a89570;
    }
    // 00a89553  39f1                   +cmp ecx, esi
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
    // 00a89555  7f19                   -jg 0xa89570
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a89570;
    }
    // 00a89557  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a89559  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8955b  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00a8955f  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a89562  e8e9240000             -call 0xa8ba50
    cpu.esp -= 4;
    sub_a8ba50(app, cpu);
    if (cpu.terminate) return;
    // 00a89567  83f8ff                 +cmp eax, -1
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
    // 00a8956a  74e0                   -je 0xa8954c
    if (cpu.flags.zf)
    {
        goto L_0x00a8954c;
    }
    // 00a8956c  01c1                   +add ecx, eax
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
    // 00a8956e  ebdc                   -jmp 0xa8954c
    goto L_0x00a8954c;
L_0x00a89570:
    // 00a89570  39f1                   +cmp ecx, esi
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
    // 00a89572  7f04                   -jg 0xa89578
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a89578;
    }
L_0x00a89574:
    // 00a89574  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a89576  eb02                   -jmp 0xa8957a
    goto L_0x00a8957a;
L_0x00a89578:
    // 00a89578  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a8957a:
    // 00a8957a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8957d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8957e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8957f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89580  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a89584(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89584  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89585  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a89586  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a89587  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a89588  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8958b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a8958d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a89590  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a89595  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a89597  e840250000             -call 0xa8badc
    cpu.esp -= 4;
    sub_a8badc(app, cpu);
    if (cpu.terminate) return;
    // 00a8959c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8959d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8959f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a895a1  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a895a3  49                     -dec ecx
    (cpu.ecx)--;
    // 00a895a4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a895a6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a895a8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a895aa  49                     -dec ecx
    (cpu.ecx)--;
    // 00a895ab  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a895ac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a895af  48                     -dec eax
    (cpu.eax)--;
    // 00a895b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a895b2  7415                   -je 0xa895c9
    if (cpu.flags.zf)
    {
        goto L_0x00a895c9;
    }
    // 00a895b4  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a895b6  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00a895b9  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x00a895bc:
    // 00a895bc  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a895bd  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a895c0  4a                     -dec edx
    (cpu.edx)--;
    // 00a895c1  48                     -dec eax
    (cpu.eax)--;
    // 00a895c2  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00a895c5  39f2                   +cmp edx, esi
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
    // 00a895c7  75f3                   -jne 0xa895bc
    if (!cpu.flags.zf)
    {
        goto L_0x00a895bc;
    }
L_0x00a895c9:
    // 00a895c9  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00a895cc:
    // 00a895cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a895ce  7c07                   -jl 0xa895d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a895d7;
    }
    // 00a895d0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a895d1  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00a895d4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a895d5  ebf5                   -jmp 0xa895cc
    goto L_0x00a895cc;
L_0x00a895d7:
    // 00a895d7  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00a895da  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 00a895de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a895e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a895e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a895e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a895e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a895e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a895de(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a895de;
    // 00a89584  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89585  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a89586  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a89587  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a89588  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8958b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a8958d  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a89590  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a89595  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a89597  e840250000             -call 0xa8badc
    cpu.esp -= 4;
    sub_a8badc(app, cpu);
    if (cpu.terminate) return;
    // 00a8959c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8959d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8959f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a895a1  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a895a3  49                     -dec ecx
    (cpu.ecx)--;
    // 00a895a4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a895a6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a895a8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a895aa  49                     -dec ecx
    (cpu.ecx)--;
    // 00a895ab  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a895ac  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a895af  48                     -dec eax
    (cpu.eax)--;
    // 00a895b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a895b2  7415                   -je 0xa895c9
    if (cpu.flags.zf)
    {
        goto L_0x00a895c9;
    }
    // 00a895b4  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a895b6  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00a895b9  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x00a895bc:
    // 00a895bc  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a895bd  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a895c0  4a                     -dec edx
    (cpu.edx)--;
    // 00a895c1  48                     -dec eax
    (cpu.eax)--;
    // 00a895c2  884b01                 -mov byte ptr [ebx + 1], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00a895c5  39f2                   +cmp edx, esi
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
    // 00a895c7  75f3                   -jne 0xa895bc
    if (!cpu.flags.zf)
    {
        goto L_0x00a895bc;
    }
L_0x00a895c9:
    // 00a895c9  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00a895cc:
    // 00a895cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a895ce  7c07                   -jl 0xa895d7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a895d7;
    }
    // 00a895d0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a895d1  c60230                 -mov byte ptr [edx], 0x30
    app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00a895d4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a895d5  ebf5                   -jmp 0xa895cc
    goto L_0x00a895cc;
L_0x00a895d7:
    // 00a895d7  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 00a895da  c6450000               -mov byte ptr [ebp], 0
    app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
L_entry_0x00a895de:
    // 00a895de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a895e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a895e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a895e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a895e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a895e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a895e8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a895e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a895e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a895ea  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a895eb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a895ec  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a895ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a895f1  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a895f3  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a895f6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a895f8  7d0b                   -jge 0xa89605
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a89605;
    }
    // 00a895fa  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a895fc  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a895ff  c6002d                 -mov byte ptr [eax], 0x2d
    app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 00a89602  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00a89605:
    // 00a89605  837e08ff               +cmp dword ptr [esi + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89609  7507                   -jne 0xa89612
    if (!cpu.flags.zf)
    {
        goto L_0x00a89612;
    }
    // 00a8960b  c7460804000000         -mov dword ptr [esi + 8], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x00a89612:
    // 00a89612  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a89617  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a89619  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8961b  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00a89620  e8b7240000             -call 0xa8badc
    cpu.esp -= 4;
    sub_a8badc(app, cpu);
    if (cpu.terminate) return;
    // 00a89625  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a89627  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a89629  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a8962b  7408                   -je 0xa89635
    if (cpu.flags.zf)
    {
        goto L_0x00a89635;
    }
L_0x00a8962d:
    // 00a8962d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a89630  41                     -inc ecx
    (cpu.ecx)++;
    // 00a89631  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a89633  75f8                   -jne 0xa8962d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8962d;
    }
L_0x00a89635:
    // 00a89635  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a89639  7432                   -je 0xa8966d
    if (cpu.flags.zf)
    {
        goto L_0x00a8966d;
    }
    // 00a8963b  c6012e                 -mov byte ptr [ecx], 0x2e
    app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 00a8963e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a89640  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a89643  41                     -inc ecx
    (cpu.ecx)++;
    // 00a89644  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a89646  7e22                   -jle 0xa8966a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8966a;
    }
L_0x00a89648:
    // 00a89648  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8964a  6689542402             -mov word ptr [esp + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00a8964f  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a89652  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a89655  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a89658  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00a8965c  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8965f  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 00a89661  40                     -inc eax
    (cpu.eax)++;
    // 00a89662  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a89665  41                     -inc ecx
    (cpu.ecx)++;
    // 00a89666  39e8                   +cmp eax, ebp
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
    // 00a89668  7cde                   -jl 0xa89648
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a89648;
    }
L_0x00a8966a:
    // 00a8966a  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x00a8966d:
    // 00a8966d  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 00a89672  0f8466ffffff           -je 0xa895de
    if (cpu.flags.zf)
    {
        return sub_a895de(app, cpu);
    }
L_0x00a89678:
    // 00a89678  39d9                   +cmp ecx, ebx
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
    // 00a8967a  7541                   -jne 0xa896bd
    if (!cpu.flags.zf)
    {
        goto L_0x00a896bd;
    }
    // 00a8967c  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a8967f  c60331                 -mov byte ptr [ebx], 0x31
    app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
    // 00a89682  803930                 +cmp byte ptr [ecx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89685  7508                   -jne 0xa8968f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8968f;
    }
L_0x00a89687:
    // 00a89687  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a8968a  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8968b  3c30                   +cmp al, 0x30
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8968d  74f8                   -je 0xa89687
    if (cpu.flags.zf)
    {
        goto L_0x00a89687;
    }
L_0x00a8968f:
    // 00a8968f  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a89691  80fc2e                 +cmp ah, 0x2e
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89694  7518                   -jne 0xa896ae
    if (!cpu.flags.zf)
    {
        goto L_0x00a896ae;
    }
    // 00a89696  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a89699  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8969a  8821                   -mov byte ptr [ecx], ah
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 00a8969c  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a8969f  41                     -inc ecx
    (cpu.ecx)++;
    // 00a896a0  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a896a3  7509                   -jne 0xa896ae
    if (!cpu.flags.zf)
    {
        goto L_0x00a896ae;
    }
L_0x00a896a5:
    // 00a896a5  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a896a8  41                     -inc ecx
    (cpu.ecx)++;
    // 00a896a9  80fe30                 +cmp dh, 0x30
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a896ac  74f7                   -je 0xa896a5
    if (cpu.flags.zf)
    {
        goto L_0x00a896a5;
    }
L_0x00a896ae:
    // 00a896ae  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a896b1  41                     -inc ecx
    (cpu.ecx)++;
    // 00a896b2  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00a896b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a896b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a896b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a896ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a896bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a896bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a896bd:
    // 00a896bd  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a896c0  49                     -dec ecx
    (cpu.ecx)--;
    // 00a896c1  80fa2e                 +cmp dl, 0x2e
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a896c4  7501                   -jne 0xa896c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a896c7;
    }
    // 00a896c6  49                     -dec ecx
    (cpu.ecx)--;
L_0x00a896c7:
    // 00a896c7  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a896c9  80fe39                 +cmp dh, 0x39
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a896cc  740e                   -je 0xa896dc
    if (cpu.flags.zf)
    {
        goto L_0x00a896dc;
    }
    // 00a896ce  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 00a896d0  fec3                   -inc bl
    (cpu.bl)++;
    // 00a896d2  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 00a896d4  83c404                 +add esp, 4
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
    // 00a896d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a896d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a896d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a896da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a896db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a896dc:
    // 00a896dc  c60130                 -mov byte ptr [ecx], 0x30
    app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a896df  eb97                   -jmp 0xa89678
    goto L_0x00a89678;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a896e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a896e4  ff153828a900           -call dword ptr [0xa92838]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085880) /* 0xa92838 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a896ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a896ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a896ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a896ed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a896ee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a896ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a896f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a896f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a896f2  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00a896f6  7530                   -jne 0xa89728
    if (!cpu.flags.zf)
    {
        goto L_0x00a89728;
    }
    // 00a896f8  80781630               +cmp byte ptr [eax + 0x16], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a896fc  752a                   -jne 0xa89728
    if (!cpu.flags.zf)
    {
        goto L_0x00a89728;
    }
    // 00a896fe  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a89701  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a89704  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a89707  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a89709  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00a8970c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8970e  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00a89711  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a89713  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00a89716  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a89718  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00a8971b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8971d  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8971f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a89721  7e05                   -jle 0xa89728
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a89728;
    }
    // 00a89723  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a89725  894824                 -mov dword ptr [eax + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x00a89728:
    // 00a89728  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89729  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8972a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8972b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8972c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8972d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8972e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a89730(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89730  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a89731  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a89732  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a89733  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a89734  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89737  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a89739  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8973b  8b5328                 -mov edx, dword ptr [ebx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00a8973e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a89740  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a89742  7e45                   -jle 0xa89789
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a89789;
    }
L_0x00a89744:
    // 00a89744  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a89746  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a89748  66268b17               -mov dx, word ptr es:[edi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ees + cpu.edi);
    // 00a8974c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8974f  e8fc220000             -call 0xa8ba50
    cpu.esp -= 4;
    sub_a8ba50(app, cpu);
    if (cpu.terminate) return;
    // 00a89754  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a89756  83f8ff                 +cmp eax, -1
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
    // 00a89759  740d                   -je 0xa89768
    if (cpu.flags.zf)
    {
        goto L_0x00a89768;
    }
    // 00a8975b  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8975e  7f22                   -jg 0xa89782
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a89782;
    }
    // 00a89760  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x00a89762:
    // 00a89762  49                     -dec ecx
    (cpu.ecx)--;
    // 00a89763  83f9ff                 +cmp ecx, -1
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
    // 00a89766  7508                   -jne 0xa89770
    if (!cpu.flags.zf)
    {
        goto L_0x00a89770;
    }
L_0x00a89768:
    // 00a89768  837b2800               +cmp dword ptr [ebx + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8976c  7fd6                   -jg 0xa89744
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a89744;
    }
    // 00a8976e  eb19                   -jmp 0xa89789
    goto L_0x00a89789;
L_0x00a89770:
    // 00a89770  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a89772  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a89774  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00a89776  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89778  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00a8977b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8977c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8977d  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a89780  ebe0                   -jmp 0xa89762
    goto L_0x00a89762;
L_0x00a89782:
    // 00a89782  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x00a89789:
    // 00a89789  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8978c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8978d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8978e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8978f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89790  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a89794(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89794  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a89795  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a89796  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a89797  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a89798  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8979b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8979d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8979f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a897a1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a897a3  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a897aa  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a897b1  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a897b8  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 00a897bf  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00a897c6  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a897c8  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00a897cb  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 00a897d2  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a897d4  721e                   -jb 0xa897f4
    if (cpu.flags.cf)
    {
        goto L_0x00a897f4;
    }
    // 00a897d6  0f8692000000           -jbe 0xa8986e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8986e;
    }
    // 00a897dc  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a897de  720b                   -jb 0xa897eb
    if (cpu.flags.cf)
    {
        goto L_0x00a897eb;
    }
    // 00a897e0  7625                   -jbe 0xa89807
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89807;
    }
    // 00a897e2  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a897e4  7421                   -je 0xa89807
    if (cpu.flags.zf)
    {
        goto L_0x00a89807;
    }
    // 00a897e6  e960010000             -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a897eb:
    // 00a897eb  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a897ed  7418                   -je 0xa89807
    if (cpu.flags.zf)
    {
        goto L_0x00a89807;
    }
    // 00a897ef  e957010000             -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a897f4:
    // 00a897f4  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a897f6  0f824f010000           -jb 0xa8994b
    if (cpu.flags.cf)
    {
        goto L_0x00a8994b;
    }
    // 00a897fc  7609                   -jbe 0xa89807
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89807;
    }
    // 00a897fe  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89800  746c                   -je 0xa8986e
    if (cpu.flags.zf)
    {
        goto L_0x00a8986e;
    }
    // 00a89802  e944010000             -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a89807:
    // 00a89807  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a8980b  7420                   -je 0xa8982d
    if (cpu.flags.zf)
    {
        goto L_0x00a8982d;
    }
    // 00a8980d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8980f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89812  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a89814  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a89817  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8981a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8981c  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8981f  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a89821  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a89824  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a89828  e91e010000             -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a8982d:
    // 00a8982d  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a89831  7413                   -je 0xa89846
    if (cpu.flags.zf)
    {
        goto L_0x00a89846;
    }
    // 00a89833  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89835  83c004                 +add eax, 4
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
    // 00a89838  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a8983a  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a8983d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a89841  e905010000             -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a89846:
    // 00a89846  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89848  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8984b  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a8984d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a89850  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a89854  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a89858  0f84ed000000           -je 0xa8994b
    if (cpu.flags.zf)
    {
        goto L_0x00a8994b;
    }
    // 00a8985e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a89860  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a89865  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a89869  e9dd000000             -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a8986e:
    // 00a8986e  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a89872  741d                   -je 0xa89891
    if (cpu.flags.zf)
    {
        goto L_0x00a89891;
    }
    // 00a89874  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89876  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89879  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a8987b  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a8987e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a89881  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89883  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a89886  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a89888  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a8988b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a8988f  eb33                   -jmp 0xa898c4
    goto L_0x00a898c4;
L_0x00a89891:
    // 00a89891  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a89895  740c                   -je 0xa898a3
    if (cpu.flags.zf)
    {
        goto L_0x00a898a3;
    }
    // 00a89897  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89899  83c504                 +add ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8989c  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a8989e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a898a1  eb1d                   -jmp 0xa898c0
    goto L_0x00a898c0;
L_0x00a898a3:
    // 00a898a3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a898a5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a898a8  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a898aa  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a898ad  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a898b0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a898b4  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 00a898b7  740b                   -je 0xa898c4
    if (cpu.flags.zf)
    {
        goto L_0x00a898c4;
    }
    // 00a898b9  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00a898bd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x00a898c0:
    // 00a898c0  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00a898c4:
    // 00a898c4  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00a898c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a898c9  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a898cc  7409                   -je 0xa898d7
    if (cpu.flags.zf)
    {
        goto L_0x00a898d7;
    }
    // 00a898ce  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00a898d3  7409                   -je 0xa898de
    if (cpu.flags.zf)
    {
        goto L_0x00a898de;
    }
    // 00a898d5  eb0b                   -jmp 0xa898e2
    goto L_0x00a898e2;
L_0x00a898d7:
    // 00a898d7  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a898dc  7c04                   -jl 0xa898e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a898e2;
    }
L_0x00a898de:
    // 00a898de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a898e0  7442                   -je 0xa89924
    if (cpu.flags.zf)
    {
        goto L_0x00a89924;
    }
L_0x00a898e2:
    // 00a898e2  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a898e5  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a898e8  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a898eb  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00a898ef  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a898f3  7429                   -je 0xa8991e
    if (cpu.flags.zf)
    {
        goto L_0x00a8991e;
    }
    // 00a898f5  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a898f8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a898fc  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00a898fe  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 00a89900  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a89903  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a89906  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00a8990a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8990d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8990f  7505                   -jne 0xa89916
    if (!cpu.flags.zf)
    {
        goto L_0x00a89916;
    }
    // 00a89911  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a89914  eb02                   -jmp 0xa89918
    goto L_0x00a89918;
L_0x00a89916:
    // 00a89916  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a89918:
    // 00a89918  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a8991c  eb2d                   -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a8991e:
    // 00a8991e  f75c2408               +neg dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a89922  eb27                   -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a89924:
    // 00a89924  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a89927  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00a89929  740f                   -je 0xa8993a
    if (cpu.flags.zf)
    {
        goto L_0x00a8993a;
    }
    // 00a8992b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a8992e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a89931  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a89934  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a89938  eb11                   -jmp 0xa8994b
    goto L_0x00a8994b;
L_0x00a8993a:
    // 00a8993a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a8993c  740d                   -je 0xa8994b
    if (cpu.flags.zf)
    {
        goto L_0x00a8994b;
    }
    // 00a8993e  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a89941  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a89944  895920                 -mov dword ptr [ecx + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a89947  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00a8994b:
    // 00a8994b  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a8994e  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a89953  3c64                   +cmp al, 0x64
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(100 /*0x64*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89955  7261                   -jb 0xa899b8
    if (cpu.flags.cf)
    {
        goto L_0x00a899b8;
    }
    // 00a89957  0f860b020000           -jbe 0xa89b68
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89b68;
    }
    // 00a8995d  3c6f                   +cmp al, 0x6f
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8995f  7238                   -jb 0xa89999
    if (cpu.flags.cf)
    {
        goto L_0x00a89999;
    }
    // 00a89961  0f86e1010000           -jbe 0xa89b48
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89b48;
    }
    // 00a89967  3c73                   +cmp al, 0x73
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89969  7221                   -jb 0xa8998c
    if (cpu.flags.cf)
    {
        goto L_0x00a8998c;
    }
    // 00a8996b  0f86f0000000           -jbe 0xa89a61
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89a61;
    }
    // 00a89971  3c75                   +cmp al, 0x75
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(117 /*0x75*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89973  0f8204040000           -jb 0xa89d7d
    if (cpu.flags.cf)
    {
        goto L_0x00a89d7d;
    }
    // 00a89979  0f86e9010000           -jbe 0xa89b68
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89b68;
    }
    // 00a8997f  3c78                   +cmp al, 0x78
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89981  0f847c010000           -je 0xa89b03
    if (cpu.flags.zf)
    {
        goto L_0x00a89b03;
    }
    // 00a89987  e9f1030000             -jmp 0xa89d7d
    goto L_0x00a89d7d;
L_0x00a8998c:
    // 00a8998c  3c70                   +cmp al, 0x70
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(112 /*0x70*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8998e  0f8489020000           -je 0xa89c1d
    if (cpu.flags.zf)
    {
        goto L_0x00a89c1d;
    }
    // 00a89994  e9e4030000             -jmp 0xa89d7d
    goto L_0x00a89d7d;
L_0x00a89999:
    // 00a89999  3c66                   +cmp al, 0x66
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(102 /*0x66*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8999b  0f829d000000           -jb 0xa89a3e
    if (cpu.flags.cf)
    {
        goto L_0x00a89a3e;
    }
    // 00a899a1  7666                   -jbe 0xa89a09
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89a09;
    }
    // 00a899a3  3c67                   +cmp al, 0x67
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(103 /*0x67*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899a5  0f8693000000           -jbe 0xa89a3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89a3e;
    }
    // 00a899ab  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899ad  0f84b5010000           -je 0xa89b68
    if (cpu.flags.zf)
    {
        goto L_0x00a89b68;
    }
    // 00a899b3  e9c5030000             -jmp 0xa89d7d
    goto L_0x00a89d7d;
L_0x00a899b8:
    // 00a899b8  3c47                   +cmp al, 0x47
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(71 /*0x47*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899ba  7238                   -jb 0xa899f4
    if (cpu.flags.cf)
    {
        goto L_0x00a899f4;
    }
    // 00a899bc  0f867c000000           -jbe 0xa89a3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89a3e;
    }
    // 00a899c2  3c53                   +cmp al, 0x53
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899c4  7221                   -jb 0xa899e7
    if (cpu.flags.cf)
    {
        goto L_0x00a899e7;
    }
    // 00a899c6  0f8695000000           -jbe 0xa89a61
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89a61;
    }
    // 00a899cc  3c58                   +cmp al, 0x58
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899ce  0f82a9030000           -jb 0xa89d7d
    if (cpu.flags.cf)
    {
        goto L_0x00a89d7d;
    }
    // 00a899d4  0f8629010000           -jbe 0xa89b03
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89b03;
    }
    // 00a899da  3c63                   +cmp al, 0x63
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(99 /*0x63*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899dc  0f84ce020000           -je 0xa89cb0
    if (cpu.flags.zf)
    {
        goto L_0x00a89cb0;
    }
    // 00a899e2  e996030000             -jmp 0xa89d7d
    goto L_0x00a89d7d;
L_0x00a899e7:
    // 00a899e7  3c50                   +cmp al, 0x50
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899e9  0f842e020000           -je 0xa89c1d
    if (cpu.flags.zf)
    {
        goto L_0x00a89c1d;
    }
    // 00a899ef  e989030000             -jmp 0xa89d7d
    goto L_0x00a89d7d;
L_0x00a899f4:
    // 00a899f4  3c45                   +cmp al, 0x45
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899f6  7204                   -jb 0xa899fc
    if (cpu.flags.cf)
    {
        goto L_0x00a899fc;
    }
    // 00a899f8  7644                   -jbe 0xa89a3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a89a3e;
    }
    // 00a899fa  eb0d                   -jmp 0xa89a09
    goto L_0x00a89a09;
L_0x00a899fc:
    // 00a899fc  3c43                   +cmp al, 0x43
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(67 /*0x43*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a899fe  0f8438030000           -je 0xa89d3c
    if (cpu.flags.zf)
    {
        goto L_0x00a89d3c;
    }
    // 00a89a04  e974030000             -jmp 0xa89d7d
    goto L_0x00a89d7d;
L_0x00a89a09:
    // 00a89a09  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a89a0d  742f                   -je 0xa89a3e
    if (cpu.flags.zf)
    {
        goto L_0x00a89a3e;
    }
    // 00a89a0f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89a11  83c304                 +add ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a89a14  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a89a16  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a89a19  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a89a1d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a89a1f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a89a21  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a89a23  e8c0fbffff             -call 0xa895e8
    cpu.esp -= 4;
    sub_a895e8(app, cpu);
    if (cpu.terminate) return;
    // 00a89a28  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a89a2d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a89a2f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a89a31  e8befaffff             -call 0xa894f4
    cpu.esp -= 4;
    sub_a894f4(app, cpu);
    if (cpu.terminate) return;
    // 00a89a36  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a89a39  e952030000             -jmp 0xa89d90
    goto L_0x00a89d90;
L_0x00a89a3e:
    // 00a89a3e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a89a40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a89a42  e89dfcffff             -call 0xa896e4
    cpu.esp -= 4;
    sub_a896e4(app, cpu);
    if (cpu.terminate) return;
    // 00a89a47  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a89a49  e89efcffff             -call 0xa896ec
    cpu.esp -= 4;
    sub_a896ec(app, cpu);
    if (cpu.terminate) return;
    // 00a89a4e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a89a50  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a89a53  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a89a55  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89a57  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89a59  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89a5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89a5d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89a5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89a5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89a60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89a61:
    // 00a89a61  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00a89a64  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a89a67  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a89a69  741d                   -je 0xa89a88
    if (cpu.flags.zf)
    {
        goto L_0x00a89a88;
    }
    // 00a89a6b  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89a6d  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a89a70  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a89a72  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a89a75  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a89a79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89a7b  7505                   -jne 0xa89a82
    if (!cpu.flags.zf)
    {
        goto L_0x00a89a82;
    }
    // 00a89a7d  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00a89a80  742e                   -je 0xa89ab0
    if (cpu.flags.zf)
    {
        goto L_0x00a89ab0;
    }
L_0x00a89a82:
    // 00a89a82  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a89a84  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a89a86  eb28                   -jmp 0xa89ab0
    goto L_0x00a89ab0;
L_0x00a89a88:
    // 00a89a88  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00a89a8a  7410                   -je 0xa89a9c
    if (cpu.flags.zf)
    {
        goto L_0x00a89a9c;
    }
    // 00a89a8c  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89a8e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89a91  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00a89a93  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00a89a96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89a98  7416                   -je 0xa89ab0
    if (cpu.flags.zf)
    {
        goto L_0x00a89ab0;
    }
    // 00a89a9a  eb0e                   -jmp 0xa89aaa
    goto L_0x00a89aaa;
L_0x00a89a9c:
    // 00a89a9c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89a9e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89aa1  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a89aa3  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a89aa6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89aa8  7406                   -je 0xa89ab0
    if (cpu.flags.zf)
    {
        goto L_0x00a89ab0;
    }
L_0x00a89aaa:
    // 00a89aaa  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a89aac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a89aae  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x00a89ab0:
    // 00a89ab0  80791553               +cmp byte ptr [ecx + 0x15], 0x53
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89ab4  7508                   -jne 0xa89abe
    if (!cpu.flags.zf)
    {
        goto L_0x00a89abe;
    }
    // 00a89ab6  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a89aba  7408                   -je 0xa89ac4
    if (cpu.flags.zf)
    {
        goto L_0x00a89ac4;
    }
    // 00a89abc  eb14                   -jmp 0xa89ad2
    goto L_0x00a89ad2;
L_0x00a89abe:
    // 00a89abe  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a89ac2  740e                   -je 0xa89ad2
    if (cpu.flags.zf)
    {
        goto L_0x00a89ad2;
    }
L_0x00a89ac4:
    // 00a89ac4  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89ac6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89ac8  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a89acb  e848faffff             -call 0xa89518
    cpu.esp -= 4;
    sub_a89518(app, cpu);
    if (cpu.terminate) return;
    // 00a89ad0  eb0c                   -jmp 0xa89ade
    goto L_0x00a89ade;
L_0x00a89ad2:
    // 00a89ad2  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89ad4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89ad6  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a89ad9  e816faffff             -call 0xa894f4
    cpu.esp -= 4;
    sub_a894f4(app, cpu);
    if (cpu.terminate) return;
L_0x00a89ade:
    // 00a89ade  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a89ae1  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a89ae4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a89ae6  0f8ca4020000           -jl 0xa89d90
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a89d90;
    }
    // 00a89aec  39d0                   +cmp eax, edx
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
    // 00a89aee  0f8e9c020000           -jle 0xa89d90
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a89d90;
    }
    // 00a89af4  895128                 -mov dword ptr [ecx + 0x28], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a89af7  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89af9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89afb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89afe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89aff  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89b00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89b01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89b02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89b03:
    // 00a89b03  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00a89b07  743a                   -je 0xa89b43
    if (cpu.flags.zf)
    {
        goto L_0x00a89b43;
    }
    // 00a89b09  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a89b0d  740f                   -je 0xa89b1e
    if (cpu.flags.zf)
    {
        goto L_0x00a89b1e;
    }
    // 00a89b0f  833c2400               +cmp dword ptr [esp], 0
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
    // 00a89b13  7510                   -jne 0xa89b25
    if (!cpu.flags.zf)
    {
        goto L_0x00a89b25;
    }
    // 00a89b15  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a89b1a  7427                   -je 0xa89b43
    if (cpu.flags.zf)
    {
        goto L_0x00a89b43;
    }
    // 00a89b1c  eb07                   -jmp 0xa89b25
    goto L_0x00a89b25;
L_0x00a89b1e:
    // 00a89b1e  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a89b23  741e                   -je 0xa89b43
    if (cpu.flags.zf)
    {
        goto L_0x00a89b43;
    }
L_0x00a89b25:
    // 00a89b25  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a89b28  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a89b2b  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a89b2e  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 00a89b32  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a89b35  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a89b38  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a89b3b  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00a89b3e  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a89b41  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
L_0x00a89b43:
    // 00a89b43  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x00a89b48:
    // 00a89b48  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89b4c  751a                   -jne 0xa89b68
    if (!cpu.flags.zf)
    {
        goto L_0x00a89b68;
    }
    // 00a89b4e  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a89b51  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a89b56  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a89b59  740d                   -je 0xa89b68
    if (cpu.flags.zf)
    {
        goto L_0x00a89b68;
    }
    // 00a89b5b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a89b5e  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a89b61  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a89b64  c6040630               -mov byte ptr [esi + eax], 0x30
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x00a89b68:
    // 00a89b68  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a89b6a  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a89b6d  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a89b6f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a89b71  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00a89b74  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a89b76  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 00a89b79  7436                   -je 0xa89bb1
    if (cpu.flags.zf)
    {
        goto L_0x00a89bb1;
    }
    // 00a89b7b  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89b7f  7515                   -jne 0xa89b96
    if (!cpu.flags.zf)
    {
        goto L_0x00a89b96;
    }
    // 00a89b81  833c2400               +cmp dword ptr [esp], 0
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
    // 00a89b85  750f                   -jne 0xa89b96
    if (!cpu.flags.zf)
    {
        goto L_0x00a89b96;
    }
    // 00a89b87  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a89b8c  7508                   -jne 0xa89b96
    if (!cpu.flags.zf)
    {
        goto L_0x00a89b96;
    }
    // 00a89b8e  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00a89b92  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a89b94  eb59                   -jmp 0xa89bef
    goto L_0x00a89bef;
L_0x00a89b96:
    // 00a89b96  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a89b99  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a89b9b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a89b9d  e85e1f0000             -call 0xa8bb00
    cpu.esp -= 4;
    sub_a8bb00(app, cpu);
    if (cpu.terminate) return;
    // 00a89ba2  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89ba6  7539                   -jne 0xa89be1
    if (!cpu.flags.zf)
    {
        goto L_0x00a89be1;
    }
    // 00a89ba8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a89baa  e8ed010000             -call 0xa89d9c
    cpu.esp -= 4;
    sub_a89d9c(app, cpu);
    if (cpu.terminate) return;
    // 00a89baf  eb30                   -jmp 0xa89be1
    goto L_0x00a89be1;
L_0x00a89bb1:
    // 00a89bb1  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89bb5  750f                   -jne 0xa89bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00a89bc6;
    }
    // 00a89bb7  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a89bbc  7508                   -jne 0xa89bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00a89bc6;
    }
    // 00a89bbe  26c60000               -mov byte ptr es:[eax], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00a89bc2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a89bc4  eb29                   -jmp 0xa89bef
    goto L_0x00a89bef;
L_0x00a89bc6:
    // 00a89bc6  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a89bc9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a89bcd  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a89bcf  e81c200000             -call 0xa8bbf0
    cpu.esp -= 4;
    sub_a8bbf0(app, cpu);
    if (cpu.terminate) return;
    // 00a89bd4  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89bd8  7507                   -jne 0xa89be1
    if (!cpu.flags.zf)
    {
        goto L_0x00a89be1;
    }
    // 00a89bda  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a89bdc  e8bb010000             -call 0xa89d9c
    cpu.esp -= 4;
    sub_a89d9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a89be1:
    // 00a89be1  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a89be6  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89be8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89bea  e805f9ffff             -call 0xa894f4
    cpu.esp -= 4;
    sub_a894f4(app, cpu);
    if (cpu.terminate) return;
L_0x00a89bef:
    // 00a89bef  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a89bf2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a89bf4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a89bf7  39c2                   +cmp edx, eax
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
    // 00a89bf9  7d05                   -jge 0xa89c00
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a89c00;
    }
    // 00a89bfb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a89bfd  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00a89c00:
    // 00a89c00  837908ff               +cmp dword ptr [ecx + 8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89c04  0f8586010000           -jne 0xa89d90
    if (!cpu.flags.zf)
    {
        goto L_0x00a89d90;
    }
    // 00a89c0a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a89c0c  e8dbfaffff             -call 0xa896ec
    cpu.esp -= 4;
    sub_a896ec(app, cpu);
    if (cpu.terminate) return;
    // 00a89c11  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89c13  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89c15  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89c18  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89c19  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89c1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89c1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89c1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89c1d:
    // 00a89c1d  83790400               +cmp dword ptr [ecx + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89c21  7516                   -jne 0xa89c39
    if (!cpu.flags.zf)
    {
        goto L_0x00a89c39;
    }
    // 00a89c23  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 00a89c27  7409                   -je 0xa89c32
    if (cpu.flags.zf)
    {
        goto L_0x00a89c32;
    }
    // 00a89c29  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 00a89c30  eb07                   -jmp 0xa89c39
    goto L_0x00a89c39;
L_0x00a89c32:
    // 00a89c32  c7410408000000         -mov dword ptr [ecx + 4], 8
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x00a89c39:
    // 00a89c39  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 00a89c3d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89c3f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89c42  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a89c44  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a89c47  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a89c4a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a89c4d  7429                   -je 0xa89c78
    if (cpu.flags.zf)
    {
        goto L_0x00a89c78;
    }
    // 00a89c4f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89c52  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a89c54  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00a89c59  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a89c5c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a89c5e  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a89c63  e81cf9ffff             -call 0xa89584
    cpu.esp -= 4;
    sub_a89584(app, cpu);
    if (cpu.terminate) return;
    // 00a89c68  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a89c6d  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00a89c70  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a89c72  c646043a               -mov byte ptr [esi + 4], 0x3a
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 00a89c76  eb09                   -jmp 0xa89c81
    goto L_0x00a89c81;
L_0x00a89c78:
    // 00a89c78  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a89c7d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a89c7f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a89c81:
    // 00a89c81  e8fef8ffff             -call 0xa89584
    cpu.esp -= 4;
    sub_a89584(app, cpu);
    if (cpu.terminate) return;
    // 00a89c86  80791550               +cmp byte ptr [ecx + 0x15], 0x50
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a89c8a  7507                   -jne 0xa89c93
    if (!cpu.flags.zf)
    {
        goto L_0x00a89c93;
    }
    // 00a89c8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a89c8e  e809010000             -call 0xa89d9c
    cpu.esp -= 4;
    sub_a89d9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a89c93:
    // 00a89c93  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a89c98  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89c9a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89c9c  e853f8ffff             -call 0xa894f4
    cpu.esp -= 4;
    sub_a894f4(app, cpu);
    if (cpu.terminate) return;
    // 00a89ca1  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a89ca4  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89ca6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89ca8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89cab  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89cac  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89cad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89cae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89caf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89cb0:
    // 00a89cb0  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a89cb3  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 00a89cba  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a89cbd  7465                   -je 0xa89d24
    if (cpu.flags.zf)
    {
        goto L_0x00a89d24;
    }
    // 00a89cbf  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89cc1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89cc4  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a89cc6  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a89cca  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a89ccc  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 00a89ccf  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a89cd3  e8781d0000             -call 0xa8ba50
    cpu.esp -= 4;
    sub_a8ba50(app, cpu);
    if (cpu.terminate) return;
    // 00a89cd8  83f8ff                 +cmp eax, -1
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
    // 00a89cdb  0f84af000000           -je 0xa89d90
    if (cpu.flags.zf)
    {
        goto L_0x00a89d90;
    }
    // 00a89ce1  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a89ce5  8b2d504aa900           -mov ebp, dword ptr [0xa94a50]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
    // 00a89ceb  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a89ced  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a89cef  0f849b000000           -je 0xa89d90
    if (cpu.flags.zf)
    {
        goto L_0x00a89d90;
    }
    // 00a89cf5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a89cf7  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a89cfb  8a80614aa900           -mov al, byte ptr [eax + 0xa94a61]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a89d01  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a89d03  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a89d08  0f8482000000           -je 0xa89d90
    if (cpu.flags.zf)
    {
        goto L_0x00a89d90;
    }
    // 00a89d0e  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 00a89d12  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a89d15  ff4120                 -inc dword ptr [ecx + 0x20]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */))++;
    // 00a89d18  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89d1a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89d1c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89d1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d20  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89d21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89d24:
    // 00a89d24  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89d26  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89d29  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a89d2b  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a89d2e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a89d30  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89d32  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89d34  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89d37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d38  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89d39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89d3c:
    // 00a89d3c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89d3e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89d41  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a89d43  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a89d47  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a89d4d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a89d4f  e8fc1c0000             -call 0xa8ba50
    cpu.esp -= 4;
    sub_a8ba50(app, cpu);
    if (cpu.terminate) return;
    // 00a89d54  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a89d56  83f8ff                 +cmp eax, -1
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
    // 00a89d59  740f                   -je 0xa89d6a
    if (cpu.flags.zf)
    {
        goto L_0x00a89d6a;
    }
    // 00a89d5b  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a89d5e  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89d60  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89d62  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89d65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d66  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89d67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89d6a:
    // 00a89d6a  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a89d71  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89d73  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89d75  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89d78  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d79  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89d7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89d7d:
    // 00a89d7d  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a89d84  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a89d87  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a89d89  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x00a89d90:
    // 00a89d90  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a89d92  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a89d94  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a89d97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d98  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a89d99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89d9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a89d9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89d9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a89d9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a89d9e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a89da0  803800                 +cmp byte ptr [eax], 0
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
    // 00a89da3  7413                   -je 0xa89db8
    if (cpu.flags.zf)
    {
        goto L_0x00a89db8;
    }
L_0x00a89da5:
    // 00a89da5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a89da7  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a89da9  e8d21e0000             -call 0xa8bc80
    cpu.esp -= 4;
    sub_a8bc80(app, cpu);
    if (cpu.terminate) return;
    // 00a89dae  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00a89db0  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a89db3  42                     -inc edx
    (cpu.edx)++;
    // 00a89db4  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00a89db6  75ed                   -jne 0xa89da5
    if (!cpu.flags.zf)
    {
        goto L_0x00a89da5;
    }
L_0x00a89db8:
    // 00a89db8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89db9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89dba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a89dc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89dc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a89dc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89dc2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a89dc3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a89dc4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89dc7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a89dc9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a89dcb  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a89dcd  eb01                   -jmp 0xa89dd0
    goto L_0x00a89dd0;
L_0x00a89dcf:
    // 00a89dcf  42                     -inc edx
    (cpu.edx)++;
L_0x00a89dd0:
    // 00a89dd0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a89dd2  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a89dd4  40                     -inc eax
    (cpu.eax)++;
    // 00a89dd5  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a89dd7  75f6                   -jne 0xa89dcf
    if (!cpu.flags.zf)
    {
        goto L_0x00a89dcf;
    }
    // 00a89dd9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a89ddb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a89ddf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a89de0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a89de1  a10828a900             -mov eax, dword ptr [0xa92808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a89de6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a89de7  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a89dea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a89deb  2eff154004a900         -call dword ptr cs:[0xa90440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076672) /* 0xa90440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89df2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a89df4  e9a3e0ffff             -jmp 0xa87e9c
    return sub_a87e9c(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a89dfc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89dfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a89dfd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89dfe  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a89e00  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a89e02  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a89e04  e8871e0000             -call 0xa8bc90
    cpu.esp -= 4;
    sub_a8bc90(app, cpu);
    if (cpu.terminate) return;
    // 00a89e09  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89e0b  7509                   -jne 0xa89e16
    if (!cpu.flags.zf)
    {
        goto L_0x00a89e16;
    }
    // 00a89e0d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a89e0f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a89e11  e8aaffffff             -call 0xa89dc0
    cpu.esp -= 4;
    sub_a89dc0(app, cpu);
    if (cpu.terminate) return;
L_0x00a89e16:
    // 00a89e16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89e17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89e18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a89e20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89e20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a89e21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89e22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a89e23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a89e24  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a89e25  ff15bc26a900           -call dword ptr [0xa926bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085500) /* 0xa926bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89e2b  8b35b437a900           -mov esi, dword ptr [0xa937b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11089844) /* 0xa937b4 */);
    // 00a89e31  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a89e33  7419                   -je 0xa89e4e
    if (cpu.flags.zf)
    {
        goto L_0x00a89e4e;
    }
    // 00a89e35  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a89e38  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a89e3b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a89e3d  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 00a89e43  a3b437a900             -mov dword ptr [0xa937b4], eax
    app->getMemory<x86::reg32>(x86::reg32(11089844) /* 0xa937b4 */) = cpu.eax;
    // 00a89e48  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 00a89e4c  eb4d                   -jmp 0xa89e9b
    goto L_0x00a89e9b;
L_0x00a89e4e:
    // 00a89e4e  b96023a900             -mov ecx, 0xa92360
    cpu.ecx = 11084640 /*0xa92360*/;
    // 00a89e53  81f96825a900           +cmp ecx, 0xa92568
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11085160 /*0xa92568*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89e59  7328                   -jae 0xa89e83
    if (!cpu.flags.cf)
    {
        goto L_0x00a89e83;
    }
L_0x00a89e5b:
    // 00a89e5b  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00a89e5f  7517                   -jne 0xa89e78
    if (!cpu.flags.zf)
    {
        goto L_0x00a89e78;
    }
    // 00a89e61  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a89e66  e845ceffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a89e6b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a89e6d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89e6f  7458                   -je 0xa89ec9
    if (cpu.flags.zf)
    {
        goto L_0x00a89ec9;
    }
    // 00a89e71  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 00a89e76  eb23                   -jmp 0xa89e9b
    goto L_0x00a89e9b;
L_0x00a89e78:
    // 00a89e78  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 00a89e7b  81f96825a900           +cmp ecx, 0xa92568
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11085160 /*0xa92568*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89e81  72d8                   -jb 0xa89e5b
    if (cpu.flags.cf)
    {
        goto L_0x00a89e5b;
    }
L_0x00a89e83:
    // 00a89e83  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 00a89e88  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 00a89e8d  e81eceffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a89e92  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a89e94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89e96  7431                   -je 0xa89ec9
    if (cpu.flags.zf)
    {
        goto L_0x00a89ec9;
    }
    // 00a89e98  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x00a89e9b:
    // 00a89e9b  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 00a89ea0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a89ea2  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a89ea4  e807ccffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a89ea9  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00a89eac  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a89eaf  a1b037a900             -mov eax, dword ptr [0xa937b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */);
    // 00a89eb4  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00a89eb7  8935b037a900           -mov dword ptr [0xa937b0], esi
    app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */) = cpu.esi;
    // 00a89ebd  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a89ebf  ff15c026a900           -call dword ptr [0xa926c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89ec5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a89ec7  eb12                   -jmp 0xa89edb
    goto L_0x00a89edb;
L_0x00a89ec9:
    // 00a89ec9  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a89ece  e84d030000             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a89ed3  ff15c026a900           -call dword ptr [0xa926c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89ed9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a89edb:
    // 00a89edb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89edc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89edd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89ede  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89edf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89ee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a89ee4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89ee4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a89ee5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89ee6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a89ee7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a89ee9  bab037a900             -mov edx, 0xa937b0
    cpu.edx = 11089840 /*0xa937b0*/;
L_0x00a89eee:
    // 00a89eee  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a89ef0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89ef2  7425                   -je 0xa89f19
    if (cpu.flags.zf)
    {
        goto L_0x00a89f19;
    }
    // 00a89ef4  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a89ef7  39cb                   +cmp ebx, ecx
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
    // 00a89ef9  7404                   -je 0xa89eff
    if (cpu.flags.zf)
    {
        goto L_0x00a89eff;
    }
    // 00a89efb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a89efd  ebef                   -jmp 0xa89eee
    goto L_0x00a89eee;
L_0x00a89eff:
    // 00a89eff  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a89f02  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a89f05  884b0c                 -mov byte ptr [ebx + 0xc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 00a89f08  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a89f0a  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a89f0c  8b15b437a900           -mov edx, dword ptr [0xa937b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11089844) /* 0xa937b4 */);
    // 00a89f12  a3b437a900             -mov dword ptr [0xa937b4], eax
    app->getMemory<x86::reg32>(x86::reg32(11089844) /* 0xa937b4 */) = cpu.eax;
    // 00a89f17  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00a89f19:
    // 00a89f19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89f1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89f1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89f1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a89f20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89f20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a89f21  833db437a90000         +cmp dword ptr [0xa937b4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11089844) /* 0xa937b4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89f28  7416                   -je 0xa89f40
    if (cpu.flags.zf)
    {
        goto L_0x00a89f40;
    }
L_0x00a89f2a:
    // 00a89f2a  a1b437a900             -mov eax, dword ptr [0xa937b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11089844) /* 0xa937b4 */);
    // 00a89f2f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a89f31  e86aceffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a89f36  8915b437a900           -mov dword ptr [0xa937b4], edx
    app->getMemory<x86::reg32>(x86::reg32(11089844) /* 0xa937b4 */) = cpu.edx;
    // 00a89f3c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a89f3e  75ea                   -jne 0xa89f2a
    if (!cpu.flags.zf)
    {
        goto L_0x00a89f2a;
    }
L_0x00a89f40:
    // 00a89f40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89f41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a89f50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a89f51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a89f52  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a89f54  ff15bc26a900           -call dword ptr [0xa926bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085500) /* 0xa926bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89f5a  a1b037a900             -mov eax, dword ptr [0xa937b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */);
    // 00a89f5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89f61  750e                   -jne 0xa89f71
    if (!cpu.flags.zf)
    {
        goto L_0x00a89f71;
    }
L_0x00a89f63:
    // 00a89f63  ff15c026a900           -call dword ptr [0xa926c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89f69  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a89f6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89f6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89f70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a89f71:
    // 00a89f71  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89f74  7408                   -je 0xa89f7e
    if (cpu.flags.zf)
    {
        goto L_0x00a89f7e;
    }
    // 00a89f76  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a89f78  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a89f7a  74e7                   -je 0xa89f63
    if (cpu.flags.zf)
    {
        goto L_0x00a89f63;
    }
    // 00a89f7c  ebf3                   -jmp 0xa89f71
    goto L_0x00a89f71;
L_0x00a89f7e:
    // 00a89f7e  ff15c026a900           -call dword ptr [0xa926c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a89f84  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a89f89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a89f8b  e804000000             -call 0xa89f94
    cpu.esp -= 4;
    sub_a89f94(app, cpu);
    if (cpu.terminate) return;
    // 00a89f90  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89f91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a89f94(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89f94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a89f95  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a89f97  e8c8000000             -call 0xa8a064
    cpu.esp -= 4;
    sub_a8a064(app, cpu);
    if (cpu.terminate) return;
    // 00a89f9c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a89f9e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a89fa0  e83fffffff             -call 0xa89ee4
    cpu.esp -= 4;
    sub_a89ee4(app, cpu);
    if (cpu.terminate) return;
    // 00a89fa5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a89fa7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89fa8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a89fac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89fac  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a89faf  83f839                 +cmp eax, 0x39
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(57 /*0x39*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a89fb2  7e03                   -jle 0xa89fb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a89fb7;
    }
    // 00a89fb4  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x00a89fb7:
    // 00a89fb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a89fb8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a89fb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a89fb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a89fba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a89fbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a89fbc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a89fbd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a89fc0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a89fc2  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a89fc5  e8f61c0000             -call 0xa8bcc0
    cpu.esp -= 4;
    sub_a8bcc0(app, cpu);
    if (cpu.terminate) return;
    // 00a89fca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a89fcc  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00a89fcf  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a89fd1  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a89fd3  e8081e0000             -call 0xa8bde0
    cpu.esp -= 4;
    sub_a8bde0(app, cpu);
    if (cpu.terminate) return;
    // 00a89fd8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a89fda  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00a89fdb:
    // 00a89fdb  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a89fdd  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a89fdf  3c00                   +cmp al, 0
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
    // 00a89fe1  7410                   -je 0xa89ff3
    if (cpu.flags.zf)
    {
        goto L_0x00a89ff3;
    }
    // 00a89fe3  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a89fe6  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a89fe9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a89fec  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a89fef  3c00                   +cmp al, 0
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
    // 00a89ff1  75e8                   -jne 0xa89fdb
    if (!cpu.flags.zf)
    {
        goto L_0x00a89fdb;
    }
L_0x00a89ff3:
    // 00a89ff3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a89ff4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a89ff5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a89ff7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a89ff9  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a89ffb  49                     -dec ecx
    (cpu.ecx)--;
    // 00a89ffc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a89ffe  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a8a000  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a8a002  49                     -dec ecx
    (cpu.ecx)--;
    // 00a8a003  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8a004  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 00a8a007  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a8a00a  c60674                 -mov byte ptr [esi], 0x74
    app->getMemory<x86::reg8>(cpu.esi) = 116 /*0x74*/;
    // 00a8a00d  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a8a00f:
    // 00a8a00f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8a011  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a8a014  4a                     -dec edx
    (cpu.edx)--;
    // 00a8a015  e892ffffff             -call 0xa89fac
    cpu.esp -= 4;
    sub_a89fac(app, cpu);
    if (cpu.terminate) return;
    // 00a8a01a  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 00a8a01d  884201                 -mov byte ptr [edx + 1], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a8a020  39ca                   +cmp edx, ecx
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
    // 00a8a022  75eb                   -jne 0xa8a00f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a00f;
    }
    // 00a8a024  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8a027  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00a8a02a  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a8a02d  c646055f               -mov byte ptr [esi + 5], 0x5f
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 00a8a031  e876ffffff             -call 0xa89fac
    cpu.esp -= 4;
    sub_a89fac(app, cpu);
    if (cpu.terminate) return;
    // 00a8a036  884606                 -mov byte ptr [esi + 6], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00a8a039  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8a03c  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a8a03f  e868ffffff             -call 0xa89fac
    cpu.esp -= 4;
    sub_a89fac(app, cpu);
    if (cpu.terminate) return;
    // 00a8a044  c646082e               -mov byte ptr [esi + 8], 0x2e
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 00a8a048  c6460974               -mov byte ptr [esi + 9], 0x74
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 00a8a04c  c6460a6d               -mov byte ptr [esi + 0xa], 0x6d
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 00a8a050  c6460b70               -mov byte ptr [esi + 0xb], 0x70
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 00a8a054  c6460c00               -mov byte ptr [esi + 0xc], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a8a058  884607                 -mov byte ptr [esi + 7], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00a8a05b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a05e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a05f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a060  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a062  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a063  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8a064(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a064  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a065  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a066  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a067  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a068  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8a069  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00a8a06f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8a071  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8a073  83780c00               +cmp dword ptr [eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a077  750a                   -jne 0xa8a083
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a083;
    }
    // 00a8a079  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8a07e  e997000000             -jmp 0xa8a11a
    goto L_0x00a8a11a;
L_0x00a8a083:
    // 00a8a083  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00a8a086  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8a088  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00a8a08b  7409                   -je 0xa8a096
    if (cpu.flags.zf)
    {
        goto L_0x00a8a096;
    }
    // 00a8a08d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8a08f  e8ecd9ffff             -call 0xa87a80
    cpu.esp -= 4;
    sub_a87a80(app, cpu);
    if (cpu.terminate) return;
    // 00a8a094  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00a8a096:
    // 00a8a096  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8a099  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a09f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8a0a1  e80a1e0000             -call 0xa8beb0
    cpu.esp -= 4;
    sub_a8beb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a0a6  83f8ff                 +cmp eax, -1
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
    // 00a8a0a9  740e                   -je 0xa8a0b9
    if (cpu.flags.zf)
    {
        goto L_0x00a8a0b9;
    }
    // 00a8a0ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a0ad  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8a0b0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8a0b2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8a0b4  e8c7010000             -call 0xa8a280
    cpu.esp -= 4;
    sub_a8a280(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a0b9:
    // 00a8a0b9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8a0bb  740a                   -je 0xa8a0c7
    if (cpu.flags.zf)
    {
        goto L_0x00a8a0c7;
    }
    // 00a8a0bd  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8a0c0  e84b1e0000             -call 0xa8bf10
    cpu.esp -= 4;
    sub_a8bf10(app, cpu);
    if (cpu.terminate) return;
    // 00a8a0c5  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8a0c7:
    // 00a8a0c7  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 00a8a0cb  7415                   -je 0xa8a0e2
    if (cpu.flags.zf)
    {
        goto L_0x00a8a0e2;
    }
    // 00a8a0cd  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8a0d0  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8a0d3  e8c8ccffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a0d8  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8a0db  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00a8a0e2:
    // 00a8a0e2  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a8a0e6  741a                   -je 0xa8a102
    if (cpu.flags.zf)
    {
        goto L_0x00a8a102;
    }
    // 00a8a0e8  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8a0eb  8a5214                 -mov dl, byte ptr [edx + 0x14]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a8a0ee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8a0f0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8a0f6  e8bdfeffff             -call 0xa89fb8
    cpu.esp -= 4;
    sub_a89fb8(app, cpu);
    if (cpu.terminate) return;
    // 00a8a0fb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8a0fd  e89e1e0000             -call 0xa8bfa0
    cpu.esp -= 4;
    sub_a8bfa0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a102:
    // 00a8a102  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8a105  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a10b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8a10d  7409                   -je 0xa8a118
    if (cpu.flags.zf)
    {
        goto L_0x00a8a118;
    }
    // 00a8a10f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8a112  ff15b826a900           -call dword ptr [0xa926b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085496) /* 0xa926b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a8a118:
    // 00a8a118  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a8a11a:
    // 00a8a11a  81c414010000           -add esp, 0x114
    (cpu.esp) += x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00a8a120  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a121  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a122  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a123  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a124  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a125  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a130(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a131  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a132  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a133  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8a134  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a137  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8a139  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8a13b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a13d  7c08                   -jl 0xa8a147
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8a147;
    }
    // 00a8a13f  3b05042aa900           +cmp eax, dword ptr [0xa92a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11086340) /* 0xa92a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a145  7614                   -jbe 0xa8a15b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a15b;
    }
L_0x00a8a147:
    // 00a8a147  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8a14c  e8cf000000             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8a151  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8a156  e9b8000000             -jmp 0xa8a213
    goto L_0x00a8a213;
L_0x00a8a15b:
    // 00a8a15b  8b2d0828a900           -mov ebp, dword ptr [0xa92808]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a161  8b6cb500               -mov ebp, dword ptr [ebp + esi*4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4);
    // 00a8a165  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a16b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a16d  e83e1e0000             -call 0xa8bfb0
    cpu.esp -= 4;
    sub_a8bfb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a172  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a8a174  7428                   -je 0xa8a19e
    if (cpu.flags.zf)
    {
        goto L_0x00a8a19e;
    }
    // 00a8a176  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a8a178  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a17a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a17c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8a17d  2eff150804a900         -call dword ptr cs:[0xa90408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076616) /* 0xa90408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a184  83f8ff                 +cmp eax, -1
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
    // 00a8a187  7515                   -jne 0xa8a19e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a19e;
    }
    // 00a8a189  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a18b  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a191  e80e1f0000             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8a196  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a199  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a19a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a19b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a19c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a19d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a19e:
    // 00a8a19e  833d2027a90000         +cmp dword ptr [0xa92720], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085600) /* 0xa92720 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a1a5  7428                   -je 0xa8a1cf
    if (cpu.flags.zf)
    {
        goto L_0x00a8a1cf;
    }
    // 00a8a1a7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a1a9  ff15f426a900           -call dword ptr [0xa926f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085556) /* 0xa926f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a1af  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a1b1  741c                   -je 0xa8a1cf
    if (cpu.flags.zf)
    {
        goto L_0x00a8a1cf;
    }
    // 00a8a1b3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a8a1b5  ff152027a900           -call dword ptr [0xa92720]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085600) /* 0xa92720 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a1bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8a1bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a1bf  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a1c5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8a1c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a1ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a1cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a1cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a1cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a1ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a1cf:
    // 00a8a1cf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a1d1  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8a1d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a1d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a1d7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a1d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8a1d9  2eff154004a900         -call dword ptr cs:[0xa90440]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076672) /* 0xa90440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a1e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a1e2  7515                   -jne 0xa8a1f9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a1f9;
    }
    // 00a8a1e4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a1e6  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a1ec  e8b31e0000             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8a1f1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a1f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a1f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a1f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a1f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a1f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a1f9:
    // 00a8a1f9  3b1c24                 +cmp ebx, dword ptr [esp]
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
    // 00a8a1fc  740a                   -je 0xa8a208
    if (cpu.flags.zf)
    {
        goto L_0x00a8a208;
    }
    // 00a8a1fe  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00a8a203  e818000000             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a208:
    // 00a8a208  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a20a  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a210  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x00a8a213:
    // 00a8a213  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a216  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a217  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a218  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a219  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a21a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a220  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a221  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a223  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a229  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8a22c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a22d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8a230(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a230  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a8a235  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a236  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a238  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a23e  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8a241  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a242  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8a244(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a244  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a8a249  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a24a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a24c  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a252  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8a255  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a256  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8a258(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a258  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a8a25d  e8beffffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8a262  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8a267  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8a268(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a268  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a269  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a26b  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a271  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a8a274  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a275  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a280(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a280  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a281  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a282  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8a284  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8a286  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a288  7c08                   -jl 0xa8a292
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8a292;
    }
    // 00a8a28a  3b05042aa900           +cmp eax, dword ptr [0xa92a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11086340) /* 0xa92a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a290  7612                   -jbe 0xa8a2a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a2a4;
    }
L_0x00a8a292:
    // 00a8a292  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8a297  e884ffffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8a29c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8a2a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a2a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a2a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a2a4:
    // 00a8a2a4  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a2aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a2ac  e8ff1c0000             -call 0xa8bfb0
    cpu.esp -= 4;
    sub_a8bfb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a2b1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8a2b3  7e10                   -jle 0xa8a2c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8a2c5;
    }
    // 00a8a2b5  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a8a2b7  750c                   -jne 0xa8a2c5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a2c5;
    }
    // 00a8a2b9  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a8a2bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a2be  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a2c0  e8431d0000             -call 0xa8c008
    cpu.esp -= 4;
    sub_a8c008(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a2c5:
    // 00a8a2c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a2c6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8a2c8  8b150828a900           -mov edx, dword ptr [0xa92808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a2ce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a2cf  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00a8a2d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a2d3  2eff150804a900         -call dword ptr cs:[0xa90408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076616) /* 0xa90408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a2da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8a2dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a2de  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a2e4  83f9ff                 +cmp ecx, -1
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
    // 00a8a2e7  7505                   -jne 0xa8a2ee
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a2ee;
    }
    // 00a8a2e9  e8b61d0000             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a2ee:
    // 00a8a2ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8a2f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a2f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a2f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a300(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a302  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a303  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a304  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8a306  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8a308  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a30a  7c08                   -jl 0xa8a314
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8a314;
    }
    // 00a8a30c  3b05042aa900           +cmp eax, dword ptr [0xa92a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11086340) /* 0xa92a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a312  7614                   -jbe 0xa8a328
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a328;
    }
L_0x00a8a314:
    // 00a8a314  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8a319  e802ffffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8a31e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8a323  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a324  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a325  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a326  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a327  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a328:
    // 00a8a328  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a32e  a10828a900             -mov eax, dword ptr [0xa92808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a333  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00a8a336  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8a337  2eff158803a900         -call dword ptr cs:[0xa90388]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076488) /* 0xa90388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a33e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a340  750a                   -jne 0xa8a34c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a34c;
    }
    // 00a8a342  e85d1d0000             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8a347  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x00a8a34c:
    // 00a8a34c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8a34e  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a354  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8a356  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a357  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a358  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a359  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a35a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8a360(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a362  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a363  8b0d0828a900           -mov ecx, dword ptr [0xa92808]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a369  a10c28a900             -mov eax, dword ptr [0xa9280c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */);
    // 00a8a36e  3b05042aa900           +cmp eax, dword ptr [0xa92a04]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11086340) /* 0xa92a04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a374  7304                   -jae 0xa8a37a
    if (!cpu.flags.cf)
    {
        goto L_0x00a8a37a;
    }
    // 00a8a376  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8a378  eb2f                   -jmp 0xa8a3a9
    goto L_0x00a8a3a9;
L_0x00a8a37a:
    // 00a8a37a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a37c  7e26                   -jle 0xa8a3a4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8a3a4;
    }
    // 00a8a37e  8b1d0c28a900           -mov ebx, dword ptr [0xa9280c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */);
    // 00a8a384  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8a386  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8a388  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
L_0x00a8a38b:
    // 00a8a38b  833c0200               +cmp dword ptr [edx + eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a38f  750c                   -jne 0xa8a39d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a39d;
    }
    // 00a8a391  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8a393  890d0828a900           -mov dword ptr [0xa92808], ecx
    app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */) = cpu.ecx;
    // 00a8a399  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a39a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a39b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a39c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a39d:
    // 00a8a39d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a3a0  39d8                   +cmp eax, ebx
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
    // 00a8a3a2  7ce7                   -jl 0xa8a38b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8a38b;
    }
L_0x00a8a3a4:
    // 00a8a3a4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a8a3a9:
    // 00a8a3a9  890d0828a900           -mov dword ptr [0xa92808], ecx
    app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */) = cpu.ecx;
    // 00a8a3af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a3b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a3b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a3b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8a3b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a3b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a3b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a3b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a3b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a3b8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8a3ba  ff15dc26a900           -call dword ptr [0xa926dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085532) /* 0xa926dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a3c0  8b1d0c28a900           -mov ebx, dword ptr [0xa9280c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */);
    // 00a8a3c6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8a3c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8a3ca  7e2d                   -jle 0xa8a3f9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8a3f9;
    }
    // 00a8a3cc  8d0c9d00000000         -lea ecx, [ebx*4]
    cpu.ecx = x86::reg32(cpu.ebx * 4);
    // 00a8a3d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8a3d5:
    // 00a8a3d5  8b1d0828a900           -mov ebx, dword ptr [0xa92808]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a3db  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8a3dd  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a3e0  750f                   -jne 0xa8a3f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a3f1;
    }
    // 00a8a3e2  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 00a8a3e4  ff15e026a900           -call dword ptr [0xa926e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085536) /* 0xa926e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a3ea  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8a3ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a3ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a3ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a3ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a3f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8a3f1:
    // 00a8a3f1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a3f4  42                     -inc edx
    (cpu.edx)++;
    // 00a8a3f5  39c8                   +cmp eax, ecx
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
    // 00a8a3f7  7cdc                   -jl 0xa8a3d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8a3d5;
    }
L_0x00a8a3f9:
    // 00a8a3f9  8b150c28a900           -mov edx, dword ptr [0xa9280c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */);
    // 00a8a3ff  42                     -inc edx
    (cpu.edx)++;
    // 00a8a400  a10828a900             -mov eax, dword ptr [0xa92808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a405  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00a8a408  e8e30c0000             -call 0xa8b0f0
    cpu.esp -= 4;
    sub_a8b0f0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a40d  8b150c28a900           -mov edx, dword ptr [0xa9280c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */);
    // 00a8a413  a30828a900             -mov dword ptr [0xa92808], eax
    app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */) = cpu.eax;
    // 00a8a418  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a8a41b  893490                 -mov dword ptr [eax + edx*4], esi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 00a8a41e  890d0c28a900           -mov dword ptr [0xa9280c], ecx
    app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */) = cpu.ecx;
    // 00a8a424  ff15e026a900           -call dword ptr [0xa926e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085536) /* 0xa926e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a42a  a10c28a900             -mov eax, dword ptr [0xa9280c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */);
    // 00a8a42f  48                     -dec eax
    (cpu.eax)--;
    // 00a8a430  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a431  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a432  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a433  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8a438(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a438  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a439  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a43a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8a43b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8a43c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8a43d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a440  8b3d0828a900           -mov edi, dword ptr [0xa92808]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a446  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8a449  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8a44b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8a44d  0f8caa000000           -jl 0xa8a4fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8a4fd;
    }
    // 00a8a453  ff15dc26a900           -call dword ptr [0xa926dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085532) /* 0xa926dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a459  83fa01                 +cmp edx, 1
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
    // 00a8a45c  7209                   -jb 0xa8a467
    if (cpu.flags.cf)
    {
        goto L_0x00a8a467;
    }
    // 00a8a45e  7613                   -jbe 0xa8a473
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8a473;
    }
    // 00a8a460  83fa02                 +cmp edx, 2
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
    // 00a8a463  7416                   -je 0xa8a47b
    if (cpu.flags.zf)
    {
        goto L_0x00a8a47b;
    }
    // 00a8a465  eb21                   -jmp 0xa8a488
    goto L_0x00a8a488;
L_0x00a8a467:
    // 00a8a467  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8a469  751d                   -jne 0xa8a488
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a488;
    }
    // 00a8a46b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8a46e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a46f  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00a8a471  eb0e                   -jmp 0xa8a481
    goto L_0x00a8a481;
L_0x00a8a473:
    // 00a8a473  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8a476  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8a477  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00a8a479  eb06                   -jmp 0xa8a481
    goto L_0x00a8a481;
L_0x00a8a47b:
    // 00a8a47b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8a47e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a47f  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x00a8a481:
    // 00a8a481  2eff151004a900         -call dword ptr cs:[0xa90410]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076624) /* 0xa90410 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a8a488:
    // 00a8a488  8b2d0c28a900           -mov ebp, dword ptr [0xa9280c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */);
    // 00a8a48e  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 00a8a495  8b3d0828a900           -mov edi, dword ptr [0xa92808]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a49b  39ee                   +cmp esi, ebp
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
    // 00a8a49d  7d09                   -jge 0xa8a4a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8a4a8;
    }
    // 00a8a49f  01f9                   +add ecx, edi
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
    // 00a8a4a1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8a4a4  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a8a4a6  eb49                   -jmp 0xa8a4f1
    goto L_0x00a8a4f1;
L_0x00a8a4a8:
    // 00a8a4a8  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8a4ab  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8a4ad  e83e0c0000             -call 0xa8b0f0
    cpu.esp -= 4;
    sub_a8b0f0(app, cpu);
    if (cpu.terminate) return;
    // 00a8a4b2  8b150c28a900           -mov edx, dword ptr [0xa9280c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */);
    // 00a8a4b8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8a4ba  39f2                   +cmp edx, esi
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
    // 00a8a4bc  7d18                   -jge 0xa8a4d6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8a4d6;
    }
    // 00a8a4be  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a8a4c5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a8a4c7:
    // 00a8a4c7  c7040300000000         -mov dword ptr [ebx + eax], 0
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a8a4ce  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a4d1  42                     -inc edx
    (cpu.edx)++;
    // 00a8a4d2  39c8                   +cmp eax, ecx
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
    // 00a8a4d4  7cf1                   -jl 0xa8a4c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8a4c7;
    }
L_0x00a8a4d6:
    // 00a8a4d6  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00a8a4dd  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8a4e0  46                     -inc esi
    (cpu.esi)++;
    // 00a8a4e1  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a8a4e3  893d0828a900           -mov dword ptr [0xa92808], edi
    app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */) = cpu.edi;
    // 00a8a4e9  89350c28a900           -mov dword ptr [0xa9280c], esi
    app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */) = cpu.esi;
    // 00a8a4ef  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00a8a4f1:
    // 00a8a4f1  ff15e026a900           -call dword ptr [0xa926e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085536) /* 0xa926e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a4f7  8b3d0828a900           -mov edi, dword ptr [0xa92808]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
L_0x00a8a4fd:
    // 00a8a4fd  8b3d0828a900           -mov edi, dword ptr [0xa92808]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a503  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8a506  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a507  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a508  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a509  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a50a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a50b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8a50c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a50c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a50d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a50f  ff15dc26a900           -call dword ptr [0xa926dc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085532) /* 0xa926dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a515  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8a517  7e1c                   -jle 0xa8a535
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8a535;
    }
    // 00a8a519  3b150c28a900           +cmp edx, dword ptr [0xa9280c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11085836) /* 0xa9280c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8a51f  7d14                   -jge 0xa8a535
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8a535;
    }
    // 00a8a521  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a8a528  8b150828a900           -mov edx, dword ptr [0xa92808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8a52e  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
L_0x00a8a535:
    // 00a8a535  ff15e026a900           -call dword ptr [0xa926e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085536) /* 0xa926e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a53b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a53c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8a540(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8a540  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8a541  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8a542  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00a8a544  2eff15dc03a900         -call dword ptr cs:[0xa903dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076572) /* 0xa903dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a54b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a54d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a54f  7405                   -je 0xa8a556
    if (cpu.flags.zf)
    {
        goto L_0x00a8a556;
    }
    // 00a8a551  83f8ff                 +cmp eax, -1
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
    // 00a8a554  7505                   -jne 0xa8a55b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a55b;
    }
L_0x00a8a556:
    // 00a8a556  e845000000             -call 0xa8a5a0
    cpu.esp -= 4;
    sub_a8a5a0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a55b:
    // 00a8a55b  e854feffff             -call 0xa8a3b4
    cpu.esp -= 4;
    sub_a8a3b4(app, cpu);
    if (cpu.terminate) return;
    // 00a8a560  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00a8a562  2eff15dc03a900         -call dword ptr cs:[0xa903dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076572) /* 0xa903dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a569  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a56b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a56d  7405                   -je 0xa8a574
    if (cpu.flags.zf)
    {
        goto L_0x00a8a574;
    }
    // 00a8a56f  83f8ff                 +cmp eax, -1
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
    // 00a8a572  7505                   -jne 0xa8a579
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a579;
    }
L_0x00a8a574:
    // 00a8a574  e827000000             -call 0xa8a5a0
    cpu.esp -= 4;
    sub_a8a5a0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a579:
    // 00a8a579  e836feffff             -call 0xa8a3b4
    cpu.esp -= 4;
    sub_a8a3b4(app, cpu);
    if (cpu.terminate) return;
    // 00a8a57e  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 00a8a580  2eff15dc03a900         -call dword ptr cs:[0xa903dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076572) /* 0xa903dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8a587  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8a589  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8a58b  7405                   -je 0xa8a592
    if (cpu.flags.zf)
    {
        goto L_0x00a8a592;
    }
    // 00a8a58d  83f8ff                 +cmp eax, -1
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
    // 00a8a590  7505                   -jne 0xa8a597
    if (!cpu.flags.zf)
    {
        goto L_0x00a8a597;
    }
L_0x00a8a592:
    // 00a8a592  e809000000             -call 0xa8a5a0
    cpu.esp -= 4;
    sub_a8a5a0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8a597:
    // 00a8a597  e818feffff             -call 0xa8a3b4
    cpu.esp -= 4;
    sub_a8a3b4(app, cpu);
    if (cpu.terminate) return;
    // 00a8a59c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a59d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8a59e  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
