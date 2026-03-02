#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_a36551(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36551  e917feffff             -jmp 0xa3636d
    return sub_a3636d(app, cpu);
}

/* align: skip  */
void sub_a36556(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36556  e930ffffff             -jmp 0xa3648b
    return sub_a3648b(app, cpu);
}

/* align: skip  */
void sub_a3655b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3655b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3655c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3655d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3655e  81ec18060000           -sub esp, 0x618
    (cpu.esp) -= x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 00a36564  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a36566  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a36568  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a3656a  893d18d9a300           -mov dword ptr [0xa3d918], edi
    *app->getMemory<x86::reg32>(x86::reg32(10737944) /* 0xa3d918 */) = cpu.edi;
    // 00a36570  e8c3060000             -call 0xa36c38
    cpu.esp -= 4;
    sub_a36c38(app, cpu);
    if (cpu.terminate) return;
    // 00a36575  a31cd9a300             -mov dword ptr [0xa3d91c], eax
    *app->getMemory<x86::reg32>(x86::reg32(10737948) /* 0xa3d91c */) = cpu.eax;
    // 00a3657a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3657c  7511                   -jne 0xa3658f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3658f;
    }
    // 00a3657e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a36580  0f85f6010000           -jne 0xa3677c
    if (!cpu.flags.zf)
    {
        goto L_0x00a3677c;
    }
    // 00a36586  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a36588  2eff153ca9a300         -call dword ptr cs:[0xa3a93c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725692) /* 0xa3a93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a3658f:
    // 00a3658f  e823ffffff             -call 0xa364b7
    cpu.esp -= 4;
    sub_a364b7(app, cpu);
    if (cpu.terminate) return;
    // 00a36594  2eff155ca9a300         -call dword ptr cs:[0xa3a95c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725724) /* 0xa3a95c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3659b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3659d  a319cba300             -mov dword ptr [0xa3cb19], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734361) /* 0xa3cb19 */) = cpu.eax;
    // 00a365a2  891588e0a300           -mov dword ptr [0xa3e088], edx
    *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */) = cpu.edx;
    // 00a365a8  2eff1580a9a300         -call dword ptr cs:[0xa3a980]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725760) /* 0xa3a980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a365af  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a365b1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a365b3  a21fcba300             -mov byte ptr [0xa3cb1f], al
    *app->getMemory<x86::reg8>(x86::reg32(10734367) /* 0xa3cb1f */) = cpu.al;
    // 00a365b8  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a365bb  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a365c0  66a321cba300           -mov word ptr [0xa3cb21], ax
    *app->getMemory<x86::reg16>(x86::reg32(10734369) /* 0xa3cb21 */) = cpu.ax;
    // 00a365c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a365c8  66a121cba300           -mov ax, word ptr [0xa3cb21]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(10734369) /* 0xa3cb21 */);
    // 00a365ce  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a365d4  a323cba300             -mov dword ptr [0xa3cb23], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734371) /* 0xa3cb23 */) = cpu.eax;
    // 00a365d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a365db  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00a365de  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a365e0  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a365e6  a327cba300             -mov dword ptr [0xa3cb27], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734375) /* 0xa3cb27 */) = cpu.eax;
    // 00a365eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a365ed  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a365ef  881520cba300           -mov byte ptr [0xa3cb20], dl
    *app->getMemory<x86::reg8>(x86::reg32(10734368) /* 0xa3cb20 */) = cpu.dl;
    // 00a365f5  a32bcba300             -mov dword ptr [0xa3cb2b], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734379) /* 0xa3cb2b */) = cpu.eax;
    // 00a365fa  a127cba300             -mov eax, dword ptr [0xa3cb27]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734375) /* 0xa3cb27 */);
    // 00a365ff  8b152bcba300           -mov edx, dword ptr [0xa3cb2b]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734379) /* 0xa3cb2b */);
    // 00a36605  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00a36608  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3660a  6804010000             -push 0x104
    *app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a3660f  a32fcba300             -mov dword ptr [0xa3cb2f], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734383) /* 0xa3cb2f */) = cpu.eax;
    // 00a36614  8d842414040000         -lea eax, [esp + 0x414]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 00a3661b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3661c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3661e  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a36623  2eff1568a9a300         -call dword ptr cs:[0xa3a968]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725736) /* 0xa3a968 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3662a  8d842410040000         -lea eax, [esp + 0x410]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1040) /* 0x410 */);
    // 00a36631  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a36633  e8e6080000             -call 0xa36f1e
    cpu.esp -= 4;
    sub_a36f1e(app, cpu);
    if (cpu.terminate) return;
    // 00a36638  a3e0caa300             -mov dword ptr [0xa3cae0], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734304) /* 0xa3cae0 */) = cpu.eax;
    // 00a3663d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3663f  e81f090000             -call 0xa36f63
    cpu.esp -= 4;
    sub_a36f63(app, cpu);
    if (cpu.terminate) return;
    // 00a36644  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a36646  e8a8090000             -call 0xa36ff3
    cpu.esp -= 4;
    sub_a36ff3(app, cpu);
    if (cpu.terminate) return;
    // 00a3664b  a3eccaa300             -mov dword ptr [0xa3caec], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734316) /* 0xa3caec */) = cpu.eax;
    // 00a36650  2eff154ca9a300         -call dword ptr cs:[0xa3a94c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725708) /* 0xa3a94c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36657  e8c2080000             -call 0xa36f1e
    cpu.esp -= 4;
    sub_a36f1e(app, cpu);
    if (cpu.terminate) return;
    // 00a3665c  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a3665e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36660  80fb22                 +cmp bl, 0x22
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
    // 00a36663  7514                   -jne 0xa36679
    if (!cpu.flags.zf)
    {
        goto L_0x00a36679;
    }
L_0x00a36665:
    // 00a36665  40                     -inc eax
    (cpu.eax)++;
    // 00a36666  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a36668  80fd22                 +cmp ch, 0x22
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(34 /*0x22*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3666b  7404                   -je 0xa36671
    if (cpu.flags.zf)
    {
        goto L_0x00a36671;
    }
    // 00a3666d  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00a3666f  75f4                   -jne 0xa36665
    if (!cpu.flags.zf)
    {
        goto L_0x00a36665;
    }
L_0x00a36671:
    // 00a36671  803800                 +cmp byte ptr [eax], 0
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
    // 00a36674  741e                   -je 0xa36694
    if (cpu.flags.zf)
    {
        goto L_0x00a36694;
    }
L_0x00a36676:
    // 00a36676  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a36677  eb1b                   -jmp 0xa36694
    goto L_0x00a36694;
L_0x00a36679:
    // 00a36679  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a3667b  fec2                   -inc dl
    (cpu.dl)++;
    // 00a3667d  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a36683  f68218cda30002         +test byte ptr [edx + 0xa3cd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10734872) /* 0xa3cd18 */) & 2 /*0x2*/));
    // 00a3668a  7508                   -jne 0xa36694
    if (!cpu.flags.zf)
    {
        goto L_0x00a36694;
    }
    // 00a3668c  803800                 +cmp byte ptr [eax], 0
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
    // 00a3668f  7403                   -je 0xa36694
    if (cpu.flags.zf)
    {
        goto L_0x00a36694;
    }
    // 00a36691  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a36692  ebe5                   -jmp 0xa36679
    goto L_0x00a36679;
L_0x00a36694:
    // 00a36694  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a36696  fec2                   -inc dl
    (cpu.dl)++;
    // 00a36698  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a3669e  f68218cda30002         +test byte ptr [edx + 0xa3cd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10734872) /* 0xa3cd18 */) & 2 /*0x2*/));
    // 00a366a5  75cf                   -jne 0xa36676
    if (!cpu.flags.zf)
    {
        goto L_0x00a36676;
    }
    // 00a366a7  a3dccaa300             -mov dword ptr [0xa3cadc], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734300) /* 0xa3cadc */) = cpu.eax;
    // 00a366ac  2eff1550a9a300         -call dword ptr cs:[0xa3a950]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725712) /* 0xa3a950 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a366b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a366b5  0f845f000000           -je 0xa3671a
    if (cpu.flags.zf)
    {
        goto L_0x00a3671a;
    }
    // 00a366bb  e833090000             -call 0xa36ff3
    cpu.esp -= 4;
    sub_a36ff3(app, cpu);
    if (cpu.terminate) return;
    // 00a366c0  668b18                 -mov bx, word ptr [eax]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.eax);
    // 00a366c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a366c5  6683fb22               +cmp bx, 0x22
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
    // 00a366c9  751c                   -jne 0xa366e7
    if (!cpu.flags.zf)
    {
        goto L_0x00a366e7;
    }
L_0x00a366cb:
    // 00a366cb  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a366ce  668b10                 -mov dx, word ptr [eax]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax);
    // 00a366d1  6683fa22               +cmp dx, 0x22
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(34 /*0x22*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a366d5  7405                   -je 0xa366dc
    if (cpu.flags.zf)
    {
        goto L_0x00a366dc;
    }
    // 00a366d7  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00a366da  75ef                   -jne 0xa366cb
    if (!cpu.flags.zf)
    {
        goto L_0x00a366cb;
    }
L_0x00a366dc:
    // 00a366dc  66833800               +cmp word ptr [eax], 0
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
    // 00a366e0  7423                   -je 0xa36705
    if (cpu.flags.zf)
    {
        goto L_0x00a36705;
    }
L_0x00a366e2:
    // 00a366e2  83c002                 +add eax, 2
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
    // 00a366e5  eb1e                   -jmp 0xa36705
    goto L_0x00a36705;
L_0x00a366e7:
    // 00a366e7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a366e9  fec2                   -inc dl
    (cpu.dl)++;
    // 00a366eb  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a366f1  f68218cda30002         +test byte ptr [edx + 0xa3cd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10734872) /* 0xa3cd18 */) & 2 /*0x2*/));
    // 00a366f8  750b                   -jne 0xa36705
    if (!cpu.flags.zf)
    {
        goto L_0x00a36705;
    }
    // 00a366fa  66833800               +cmp word ptr [eax], 0
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
    // 00a366fe  7405                   -je 0xa36705
    if (cpu.flags.zf)
    {
        goto L_0x00a36705;
    }
    // 00a36700  83c002                 +add eax, 2
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
    // 00a36703  ebe2                   -jmp 0xa366e7
    goto L_0x00a366e7;
L_0x00a36705:
    // 00a36705  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a36707  fec2                   -inc dl
    (cpu.dl)++;
    // 00a36709  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a3670f  f68218cda30002         +test byte ptr [edx + 0xa3cd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10734872) /* 0xa3cd18 */) & 2 /*0x2*/));
    // 00a36716  740c                   -je 0xa36724
    if (cpu.flags.zf)
    {
        goto L_0x00a36724;
    }
    // 00a36718  ebc8                   -jmp 0xa366e2
    goto L_0x00a366e2;
L_0x00a3671a:
    // 00a3671a  b848bba300             -mov eax, 0xa3bb48
    cpu.eax = 10730312 /*0xa3bb48*/;
    // 00a3671f  e8cf080000             -call 0xa36ff3
    cpu.esp -= 4;
    sub_a36ff3(app, cpu);
    if (cpu.terminate) return;
L_0x00a36724:
    // 00a36724  a3e8caa300             -mov dword ptr [0xa3cae8], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734312) /* 0xa3cae8 */) = cpu.eax;
    // 00a36729  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a3672b  744a                   -je 0xa36777
    if (cpu.flags.zf)
    {
        goto L_0x00a36777;
    }
    // 00a3672d  6804010000             -push 0x104
    *app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a36732  8d842418050000         -lea eax, [esp + 0x518]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 00a36739  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3673a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3673b  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a36740  2eff1568a9a300         -call dword ptr cs:[0xa3a968]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725736) /* 0xa3a968 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36747  8d842414050000         -lea eax, [esp + 0x514]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 00a3674e  8d942408020000         -lea edx, [esp + 0x208]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 00a36755  e8c4070000             -call 0xa36f1e
    cpu.esp -= 4;
    sub_a36f1e(app, cpu);
    if (cpu.terminate) return;
    // 00a3675a  a3e4caa300             -mov dword ptr [0xa3cae4], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734308) /* 0xa3cae4 */) = cpu.eax;
    // 00a3675f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a36761  e8fd070000             -call 0xa36f63
    cpu.esp -= 4;
    sub_a36f63(app, cpu);
    if (cpu.terminate) return;
    // 00a36766  8d842408020000         -lea eax, [esp + 0x208]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 00a3676d  e881080000             -call 0xa36ff3
    cpu.esp -= 4;
    sub_a36ff3(app, cpu);
    if (cpu.terminate) return;
    // 00a36772  a3f0caa300             -mov dword ptr [0xa3caf0], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734320) /* 0xa3caf0 */) = cpu.eax;
L_0x00a36777:
    // 00a36777  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a3677c:
    // 00a3677c  81c418060000           -add esp, 0x618
    (cpu.esp) += x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 00a36782  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36783  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36784  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36785  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36786(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36786  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36787  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36788  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36789  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3678a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a3678c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a3678e  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a36790  2eff1570a9a300         -call dword ptr cs:[0xa3a970]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725744) /* 0xa3a970 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36797  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36799  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a3679b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3679d  e8b9fdffff             -call 0xa3655b
    cpu.esp -= 4;
    sub_a3655b(app, cpu);
    if (cpu.terminate) return;
    // 00a367a2  bafccaa300             -mov edx, 0xa3cafc
    cpu.edx = 10734332 /*0xa3cafc*/;
    // 00a367a7  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a367ad  e868080000             -call 0xa3701a
    cpu.esp -= 4;
    sub_a3701a(app, cpu);
    if (cpu.terminate) return;
    // 00a367b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a367b4  e8e80c0000             -call 0xa374a1
    cpu.esp -= 4;
    sub_a374a1(app, cpu);
    if (cpu.terminate) return;
    // 00a367b9  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00a367be  e85a0d0000             -call 0xa3751d
    cpu.esp -= 4;
    sub_a3751d(app, cpu);
    if (cpu.terminate) return;
    // 00a367c3  ff15a4cca300           -call dword ptr [0xa3cca4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734756) /* 0xa3cca4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a367c9  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00a367ce  e84a0d0000             -call 0xa3751d
    cpu.esp -= 4;
    sub_a3751d(app, cpu);
    if (cpu.terminate) return;
    // 00a367d3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a367d4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a367d5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a367d6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a367d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a367d8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a367d8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a367da  833d18d9a30000         +cmp dword ptr [0xa3d918], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737944) /* 0xa3d918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a367e1  7418                   -je 0xa367fb
    if (cpu.flags.zf)
    {
        goto L_0x00a367fb;
    }
    // 00a367e3  833daccca30000         +cmp dword ptr [0xa3ccac], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10734764) /* 0xa3ccac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a367ea  7426                   -je 0xa36812
    if (cpu.flags.zf)
    {
        goto L_0x00a36812;
    }
    // 00a367ec  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a367f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a367f3  ff15accca300           -call dword ptr [0xa3ccac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734764) /* 0xa3ccac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a367f9  eb17                   -jmp 0xa36812
    goto L_0x00a36812;
L_0x00a367fb:
    // 00a367fb  e8ed0c0000             -call 0xa374ed
    cpu.esp -= 4;
    sub_a374ed(app, cpu);
    if (cpu.terminate) return;
    // 00a36800  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a36805  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a36807  e85d0d0000             -call 0xa37569
    cpu.esp -= 4;
    sub_a37569(app, cpu);
    if (cpu.terminate) return;
    // 00a3680c  ff15a0cca300           -call dword ptr [0xa3cca0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734752) /* 0xa3cca0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36812:
    // 00a36812  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36813  2eff153ca9a300         -call dword ptr cs:[0xa3a93c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725692) /* 0xa3a93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3681a  803db0cca30000         +cmp byte ptr [0xa3ccb0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10734768) /* 0xa3ccb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a36821  741a                   -je 0xa3683d
    if (cpu.flags.zf)
    {
        goto L_0x00a3683d;
    }
    // 00a36823  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a36829  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3682a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3682b  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a3682c  eb06                   -jmp 0xa36834
    goto L_0x00a36834;
    // 00a3682e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3682f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36830  49                     -dec ecx
    (cpu.ecx)--;
    // 00a36831  44                     -inc esp
    (cpu.esp)++;
    // 00a36832  45                     -inc ebp
    (cpu.ebp)++;
    // 00a36833  4f                     -dec edi
    (cpu.edi)--;
L_0x00a36834:
    // 00a36834  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a36839  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a3683c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a3683d:
    // 00a3683d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3683f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3681a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a3681a;
    // 00a367d8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a367da  833d18d9a30000         +cmp dword ptr [0xa3d918], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737944) /* 0xa3d918 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a367e1  7418                   -je 0xa367fb
    if (cpu.flags.zf)
    {
        goto L_0x00a367fb;
    }
    // 00a367e3  833daccca30000         +cmp dword ptr [0xa3ccac], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10734764) /* 0xa3ccac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a367ea  7426                   -je 0xa36812
    if (cpu.flags.zf)
    {
        goto L_0x00a36812;
    }
    // 00a367ec  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a367f1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a367f3  ff15accca300           -call dword ptr [0xa3ccac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734764) /* 0xa3ccac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a367f9  eb17                   -jmp 0xa36812
    goto L_0x00a36812;
L_0x00a367fb:
    // 00a367fb  e8ed0c0000             -call 0xa374ed
    cpu.esp -= 4;
    sub_a374ed(app, cpu);
    if (cpu.terminate) return;
    // 00a36800  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a36805  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a36807  e85d0d0000             -call 0xa37569
    cpu.esp -= 4;
    sub_a37569(app, cpu);
    if (cpu.terminate) return;
    // 00a3680c  ff15a0cca300           -call dword ptr [0xa3cca0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734752) /* 0xa3cca0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36812:
    // 00a36812  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36813  2eff153ca9a300         -call dword ptr cs:[0xa3a93c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725692) /* 0xa3a93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x00a3681a:
    // 00a3681a  803db0cca30000         +cmp byte ptr [0xa3ccb0], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10734768) /* 0xa3ccb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a36821  741a                   -je 0xa3683d
    if (cpu.flags.zf)
    {
        goto L_0x00a3683d;
    }
    // 00a36823  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a36829  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3682a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3682b  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a3682c  eb06                   -jmp 0xa36834
    goto L_0x00a36834;
    // 00a3682e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3682f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36830  49                     -dec ecx
    (cpu.ecx)--;
    // 00a36831  44                     -inc esp
    (cpu.esp)++;
    // 00a36832  45                     -inc ebp
    (cpu.ebp)++;
    // 00a36833  4f                     -dec edi
    (cpu.edi)--;
L_0x00a36834:
    // 00a36834  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a36839  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a3683c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a3683d:
    // 00a3683d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3683f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36840(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36840  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36841  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a36845  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a36848  6681faff7f             +cmp dx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a3684d  751c                   -jne 0xa3686b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3686b;
    }
    // 00a3684f  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36856  750c                   -jne 0xa36864
    if (!cpu.flags.zf)
    {
        goto L_0x00a36864;
    }
    // 00a36858  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3685b  7507                   -jne 0xa36864
    if (!cpu.flags.zf)
    {
        goto L_0x00a36864;
    }
    // 00a3685d  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a36862  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36863  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a36864:
    // 00a36864  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a36869  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3686a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a3686b:
    // 00a3686b  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(*app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 00a36871  7516                   -jne 0xa36889
    if (!cpu.flags.zf)
    {
        goto L_0x00a36889;
    }
    // 00a36873  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36877  7509                   -jne 0xa36882
    if (!cpu.flags.zf)
    {
        goto L_0x00a36882;
    }
    // 00a36879  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3687c  7504                   -jne 0xa36882
    if (!cpu.flags.zf)
    {
        goto L_0x00a36882;
    }
    // 00a3687e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a36880  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36881  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a36882:
    // 00a36882  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a36887  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36888  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a36889:
    // 00a36889  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a3688e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3688f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36890(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36890  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a36891  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36892  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36893  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36894  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36895  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36896  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a36898  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3689a  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a3689c  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a3689e  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a368a0:
    // 00a368a0  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a368a2  3c00                   +cmp al, 0
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
    // 00a368a4  742f                   -je 0xa368d5
    if (cpu.flags.zf)
    {
        goto L_0x00a368d5;
    }
    // 00a368a6  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a368a8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a368aa  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a368ac  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368ae  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368b0  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a368b2  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368b4  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368b6  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a368b8  01c5                   +add ebp, eax
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
    // 00a368ba  11d9                   +adc ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368bc  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 00a368be  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368c0  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368c2  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a368c4  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a368c6  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a368c8  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00a368ca  01c5                   +add ebp, eax
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
    // 00a368cc  83d100                 +adc ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368cf  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a368d2  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a368d3  ebcb                   -jmp 0xa368a0
    goto L_0x00a368a0;
L_0x00a368d5:
    // 00a368d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a368d7  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 00a368dc  e811000000             -call 0xa368f2
    cpu.esp -= 4;
    sub_a368f2(app, cpu);
    if (cpu.terminate) return;
    // 00a368e1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a368e2  895504                 -mov dword ptr [ebp + 4], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a368e5  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00a368e8  66897508               -mov word ptr [ebp + 8], si
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 00a368ec  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a368ed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a368ee  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a368ef  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a368f0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a368f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a368f2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a368f2  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a368f4  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a368f6  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a368f8  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00a368fa  7436                   -je 0xa36932
    if (cpu.flags.zf)
    {
        goto L_0x00a36932;
    }
    // 00a368fc  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a368fe  7509                   -jne 0xa36909
    if (!cpu.flags.zf)
    {
        goto L_0x00a36909;
    }
    // 00a36900  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36902  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a36904  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a36906  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a36909:
    // 00a36909  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a3690b  7509                   -jne 0xa36916
    if (!cpu.flags.zf)
    {
        goto L_0x00a36916;
    }
    // 00a3690d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a3690f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a36911  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a36913  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a36916:
    // 00a36916  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a36918  7809                   -js 0xa36923
    if (cpu.flags.sf)
    {
        goto L_0x00a36923;
    }
    // 00a3691a  4f                     -dec edi
    (cpu.edi)--;
    // 00a3691b  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a3691d  11c0                   +adc eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a3691f  11d2                   +adc edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a36921  ebf3                   -jmp 0xa36916
    goto L_0x00a36916;
L_0x00a36923:
    // 00a36923  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a36925  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a36928  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a3692b  7303                   -jae 0xa36930
    if (!cpu.flags.cf)
    {
        goto L_0x00a36930;
    }
    // 00a3692d  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 00a3692f  47                     -inc edi
    (cpu.edi)++;
L_0x00a36930:
    // 00a36930  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00a36932:
    // 00a36932  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36933(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00a36933:
    // 00a36933  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36934  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36936  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3693c  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a3693f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36940  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a36941  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a36946  ebeb                   -jmp 0xa36933
    goto L_0x00a36933;
}

/* align: skip  */
void sub_a36948(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36948  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a3694d  ebe4                   -jmp 0xa36933
    return sub_a36933(app, cpu);
}

/* align: skip  */
void sub_a3694f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3694f  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a36954  e8daffffff             -call 0xa36933
    cpu.esp -= 4;
    sub_a36933(app, cpu);
    if (cpu.terminate) return;
    // 00a36959  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a3695e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3695f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3695f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36960  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36962  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36968  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a3696b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3696c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3696d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3696d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3696e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3696f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36970  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36972  3b05b4cca300           +cmp eax, dword ptr [0xa3ccb4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10734772) /* 0xa3ccb4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36978  7206                   -jb 0xa36980
    if (cpu.flags.cf)
    {
        goto L_0x00a36980;
    }
    // 00a3697a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3697c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3697d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3697e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3697f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a36980:
    // 00a36980  83f803                 +cmp eax, 3
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
    // 00a36983  7d31                   -jge 0xa369b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a369b6;
    }
    // 00a36985  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36987  a108cda300             -mov eax, dword ptr [0xa3cd08]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734856) /* 0xa3cd08 */);
    // 00a3698c  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00a3698f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a36991  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a36994  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00a36997  751d                   -jne 0xa369b6
    if (!cpu.flags.zf)
    {
        goto L_0x00a369b6;
    }
    // 00a36999  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a3699b  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a3699e  886801                 -mov byte ptr [eax + 1], ch
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 00a369a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a369a3  e8120c0000             -call 0xa375ba
    cpu.esp -= 4;
    sub_a375ba(app, cpu);
    if (cpu.terminate) return;
    // 00a369a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a369aa  740a                   -je 0xa369b6
    if (cpu.flags.zf)
    {
        goto L_0x00a369b6;
    }
    // 00a369ac  a108cda300             -mov eax, dword ptr [0xa3cd08]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734856) /* 0xa3cd08 */);
    // 00a369b1  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a369b6:
    // 00a369b6  a108cda300             -mov eax, dword ptr [0xa3cd08]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734856) /* 0xa3cd08 */);
    // 00a369bb  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00a369be  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a369bf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a369c0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a369c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a369c2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a369c2  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a369c3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a369c6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a369c8  740e                   -je 0xa369d8
    if (cpu.flags.zf)
    {
        goto L_0x00a369d8;
    }
    // 00a369ca  8b1d08cda300           -mov ebx, dword ptr [0xa3cd08]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10734856) /* 0xa3cd08 */);
    // 00a369d0  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a369d3  891403                 -mov dword ptr [ebx + eax], edx
    *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a369d6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a369d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a369d8:
    // 00a369d8  8b1d08cda300           -mov ebx, dword ptr [0xa3cd08]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10734856) /* 0xa3cd08 */);
    // 00a369de  891403                 -mov dword ptr [ebx + eax], edx
    *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a369e1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a369e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a369e3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a369e3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a369e4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a369e5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a369e6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a369e7  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a369e8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a369ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a369ec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a369ee  7509                   -jne 0xa369f9
    if (!cpu.flags.zf)
    {
        goto L_0x00a369f9;
    }
    // 00a369f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a369f2  e8190c0000             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a369f7  eb5e                   -jmp 0xa36a57
    goto L_0x00a36a57;
L_0x00a369f9:
    // 00a369f9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a369fb  7509                   -jne 0xa36a06
    if (!cpu.flags.zf)
    {
        goto L_0x00a36a06;
    }
    // 00a369fd  e8fb0c0000             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a36a02  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a36a04  eb51                   -jmp 0xa36a57
    goto L_0x00a36a57;
L_0x00a36a06:
    // 00a36a06  e8f60d0000             -call 0xa37801
    cpu.esp -= 4;
    sub_a37801(app, cpu);
    if (cpu.terminate) return;
    // 00a36a0b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a36a0d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36a0f  e8f80d0000             -call 0xa3780c
    cpu.esp -= 4;
    sub_a3780c(app, cpu);
    if (cpu.terminate) return;
    // 00a36a14  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a36a16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36a18  753b                   -jne 0xa36a55
    if (!cpu.flags.zf)
    {
        goto L_0x00a36a55;
    }
    // 00a36a1a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a36a1c  e8ef0b0000             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a36a21  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a36a23  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36a25  7425                   -je 0xa36a4c
    if (cpu.flags.zf)
    {
        goto L_0x00a36a4c;
    }
    // 00a36a27  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a36a29  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a36a2b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a36a2d  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a36a2e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a36a30  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a36a32  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36a33  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a36a35  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a36a38  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a36a3a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a36a3c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a36a3f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a36a41  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36a42  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a36a43  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36a45  e8b30c0000             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a36a4a  eb09                   -jmp 0xa36a55
    goto L_0x00a36a55;
L_0x00a36a4c:
    // 00a36a4c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a36a4e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36a50  e8b70d0000             -call 0xa3780c
    cpu.esp -= 4;
    sub_a3780c(app, cpu);
    if (cpu.terminate) return;
L_0x00a36a55:
    // 00a36a55  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a36a57:
    // 00a36a57  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36a58  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36a59  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36a5a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36a5b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36a5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36a5d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36a5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36a5e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36a5e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36a5f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36a60  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36a61  8b1580daa300           -mov edx, dword ptr [0xa3da80]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10738304) /* 0xa3da80 */);
    // 00a36a67  83fa40                 +cmp edx, 0x40
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
    // 00a36a6a  7d1c                   -jge 0xa36a88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a36a88;
    }
    // 00a36a6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a36a6e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a36a71  bb84daa300             -mov ebx, 0xa3da84
    cpu.ebx = 10738308 /*0xa3da84*/;
    // 00a36a76  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a36a78  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a36a7b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a36a7e  890d80daa300           -mov dword ptr [0xa3da80], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10738304) /* 0xa3da80 */) = cpu.ecx;
    // 00a36a84  01c3                   +add ebx, eax
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
    // 00a36a86  eb24                   -jmp 0xa36aac
    goto L_0x00a36aac;
L_0x00a36a88:
    // 00a36a88  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00a36a8d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a36a92  e8590f0000             -call 0xa379f0
    cpu.esp -= 4;
    sub_a379f0(app, cpu);
    if (cpu.terminate) return;
    // 00a36a97  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36a99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36a9b  750f                   -jne 0xa36aac
    if (!cpu.flags.zf)
    {
        goto L_0x00a36aac;
    }
    // 00a36a9d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a36aa2  b84cbba300             -mov eax, 0xa3bb4c
    cpu.eax = 10730316 /*0xa3bb4c*/;
    // 00a36aa7  e87aeaffff             -call 0xa35526
    cpu.esp -= 4;
    sub_a35526(app, cpu);
    if (cpu.terminate) return;
L_0x00a36aac:
    // 00a36aac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36aae  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36aaf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36ab0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36ab1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36ab2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36ab2  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36ab3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36ab4  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36ab5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36ab7  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36abb  740a                   -je 0xa36ac7
    if (cpu.flags.zf)
    {
        goto L_0x00a36ac7;
    }
    // 00a36abd  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a36abf  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36ac0  2eff1534a9a300         -call dword ptr cs:[0xa3a934]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725684) /* 0xa3a934 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36ac7:
    // 00a36ac7  c7430400000000         -mov dword ptr [ebx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a36ace  c7430800000000         -mov dword ptr [ebx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a36ad5  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a36adc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36add  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36ade  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36adf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36ae0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36ae0  b820d9a300             -mov eax, 0xa3d920
    cpu.eax = 10737952 /*0xa3d920*/;
    // 00a36ae5  e97d000000             -jmp 0xa36b67
    return sub_a36b67(app, cpu);
}

/* align: skip  */
void sub_a36aea(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36aea  b820d9a300             -mov eax, 0xa3d920
    cpu.eax = 10737952 /*0xa3d920*/;
    // 00a36aef  e9d9000000             -jmp 0xa36bcd
    return sub_a36bcd(app, cpu);
}

/* align: skip  */
void sub_a36af4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36af4  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a36af7  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a36afa  0540d9a300             +add eax, 0xa3d940
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10737984 /*0xa3d940*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a36aff  eb66                   -jmp 0xa36b67
    return sub_a36b67(app, cpu);
}

/* align: skip  */
void sub_a36b01(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b01  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a36b04  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a36b07  0540d9a300             +add eax, 0xa3d940
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10737984 /*0xa3d940*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a36b0c  e9bc000000             -jmp 0xa36bcd
    return sub_a36bcd(app, cpu);
}

/* align: skip  */
void sub_a36b11(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b11  e957f8ffff             -jmp 0xa3636d
    return sub_a3636d(app, cpu);
}

/* align: skip  */
void sub_a36b16(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b16  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36b17  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36b19  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a36b1c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a36b1f  0540d9a300             -add eax, 0xa3d940
    (cpu.eax) += x86::reg32(x86::sreg32(10737984 /*0xa3d940*/));
    // 00a36b24  e889ffffff             -call 0xa36ab2
    cpu.esp -= 4;
    sub_a36ab2(app, cpu);
    if (cpu.terminate) return;
    // 00a36b29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a36b2b  e85bf9ffff             -call 0xa3648b
    cpu.esp -= 4;
    sub_a3648b(app, cpu);
    if (cpu.terminate) return;
    // 00a36b30  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36b31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36b32(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b32  b840daa300             -mov eax, 0xa3da40
    cpu.eax = 10738240 /*0xa3da40*/;
    // 00a36b37  eb2e                   -jmp 0xa36b67
    return sub_a36b67(app, cpu);
}

/* align: skip  */
void sub_a36b39(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b39  b840daa300             -mov eax, 0xa3da40
    cpu.eax = 10738240 /*0xa3da40*/;
    // 00a36b3e  e98a000000             -jmp 0xa36bcd
    return sub_a36bcd(app, cpu);
}

/* align: skip  */
void sub_a36b43(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b43  b830d9a300             -mov eax, 0xa3d930
    cpu.eax = 10737968 /*0xa3d930*/;
    // 00a36b48  eb1d                   -jmp 0xa36b67
    return sub_a36b67(app, cpu);
}

/* align: skip  */
void sub_a36b4a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b4a  b830d9a300             -mov eax, 0xa3d930
    cpu.eax = 10737968 /*0xa3d930*/;
    // 00a36b4f  e979000000             -jmp 0xa36bcd
    return sub_a36bcd(app, cpu);
}

/* align: skip  */
void sub_a36b54(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b54  b860daa300             -mov eax, 0xa3da60
    cpu.eax = 10738272 /*0xa3da60*/;
    // 00a36b59  eb0c                   -jmp 0xa36b67
    return sub_a36b67(app, cpu);
}

/* align: skip  */
void sub_a36b5b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b5b  b860daa300             -mov eax, 0xa3da60
    cpu.eax = 10738272 /*0xa3da60*/;
    // 00a36b60  eb6b                   -jmp 0xa36bcd
    return sub_a36bcd(app, cpu);
}

/* align: skip  */
void sub_a36b62(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36b62  b870daa300             -mov eax, 0xa3da70
    cpu.eax = 10738288 /*0xa3da70*/;
    // 00a36b67  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36b68  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36b69  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36b6a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36b6b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36b6d  2eff1554a9a300         -call dword ptr cs:[0xa3a954]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725716) /* 0xa3a954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36b74  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a36b77  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a36b79  39d0                   +cmp eax, edx
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
    // 00a36b7b  7443                   -je 0xa36bc0
    if (cpu.flags.zf)
    {
        goto L_0x00a36bc0;
    }
    // 00a36b7d  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36b81  7530                   -jne 0xa36bb3
    if (!cpu.flags.zf)
    {
        goto L_0x00a36bb3;
    }
    // 00a36b83  b850daa300             -mov eax, 0xa3da50
    cpu.eax = 10738256 /*0xa3da50*/;
    // 00a36b88  e8daffffff             -call 0xa36b67
    cpu.esp -= 4;
    sub_a36b67(app, cpu);
    if (cpu.terminate) return;
    // 00a36b8d  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36b91  7516                   -jne 0xa36ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00a36ba9;
    }
    // 00a36b93  e8c6feffff             -call 0xa36a5e
    cpu.esp -= 4;
    sub_a36a5e(app, cpu);
    if (cpu.terminate) return;
    // 00a36b98  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a36b99  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a36b9b  2eff1584a9a300         -call dword ptr cs:[0xa3a984]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725764) /* 0xa3a984 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36ba2  c7430401000000         -mov dword ptr [ebx + 4], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x00a36ba9:
    // 00a36ba9  b850daa300             -mov eax, 0xa3da50
    cpu.eax = 10738256 /*0xa3da50*/;
    // 00a36bae  e81a000000             -call 0xa36bcd
    cpu.esp -= 4;
    sub_a36bcd(app, cpu);
    if (cpu.terminate) return;
L_0x00a36bb3:
    // 00a36bb3  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a36bb5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a36bb6  2eff1538a9a300         -call dword ptr cs:[0xa3a938]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725688) /* 0xa3a938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36bbd  897308                 -mov dword ptr [ebx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a36bc0:
    // 00a36bc0  ff430c                 -inc dword ptr [ebx + 0xc]
    (*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a36bc3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bc4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bc5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bc6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36b67(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a36b67;
    // 00a36b62  b870daa300             -mov eax, 0xa3da70
    cpu.eax = 10738288 /*0xa3da70*/;
L_entry_0x00a36b67:
    // 00a36b67  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36b68  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36b69  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36b6a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36b6b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36b6d  2eff1554a9a300         -call dword ptr cs:[0xa3a954]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725716) /* 0xa3a954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36b74  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a36b77  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a36b79  39d0                   +cmp eax, edx
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
    // 00a36b7b  7443                   -je 0xa36bc0
    if (cpu.flags.zf)
    {
        goto L_0x00a36bc0;
    }
    // 00a36b7d  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36b81  7530                   -jne 0xa36bb3
    if (!cpu.flags.zf)
    {
        goto L_0x00a36bb3;
    }
    // 00a36b83  b850daa300             -mov eax, 0xa3da50
    cpu.eax = 10738256 /*0xa3da50*/;
    // 00a36b88  e8daffffff             -call 0xa36b67
    cpu.esp -= 4;
    sub_a36b67(app, cpu);
    if (cpu.terminate) return;
    // 00a36b8d  837b0400               +cmp dword ptr [ebx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36b91  7516                   -jne 0xa36ba9
    if (!cpu.flags.zf)
    {
        goto L_0x00a36ba9;
    }
    // 00a36b93  e8c6feffff             -call 0xa36a5e
    cpu.esp -= 4;
    sub_a36a5e(app, cpu);
    if (cpu.terminate) return;
    // 00a36b98  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a36b99  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a36b9b  2eff1584a9a300         -call dword ptr cs:[0xa3a984]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725764) /* 0xa3a984 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36ba2  c7430401000000         -mov dword ptr [ebx + 4], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x00a36ba9:
    // 00a36ba9  b850daa300             -mov eax, 0xa3da50
    cpu.eax = 10738256 /*0xa3da50*/;
    // 00a36bae  e81a000000             -call 0xa36bcd
    cpu.esp -= 4;
    sub_a36bcd(app, cpu);
    if (cpu.terminate) return;
L_0x00a36bb3:
    // 00a36bb3  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a36bb5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a36bb6  2eff1538a9a300         -call dword ptr cs:[0xa3a938]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725688) /* 0xa3a938 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36bbd  897308                 -mov dword ptr [ebx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a36bc0:
    // 00a36bc0  ff430c                 -inc dword ptr [ebx + 0xc]
    (*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a36bc3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bc4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bc5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bc6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36bc8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36bc8  b870daa300             -mov eax, 0xa3da70
    cpu.eax = 10738288 /*0xa3da70*/;
    // 00a36bcd  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36bce  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36bcf  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36bd0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36bd1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a36bd4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a36bd6  7617                   -jbe 0xa36bef
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a36bef;
    }
    // 00a36bd8  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a36bdb  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a36bde  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a36be0  750d                   -jne 0xa36bef
    if (!cpu.flags.zf)
    {
        goto L_0x00a36bef;
    }
    // 00a36be2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a36be4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36be5  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a36be8  2eff1588a9a300         -call dword ptr cs:[0xa3a988]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725768) /* 0xa3a988 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36bef:
    // 00a36bef  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bf0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bf1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bf2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36bcd(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a36bcd;
    // 00a36bc8  b870daa300             -mov eax, 0xa3da70
    cpu.eax = 10738288 /*0xa3da70*/;
L_entry_0x00a36bcd:
    // 00a36bcd  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36bce  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36bcf  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36bd0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36bd1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a36bd4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a36bd6  7617                   -jbe 0xa36bef
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a36bef;
    }
    // 00a36bd8  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a36bdb  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a36bde  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a36be0  750d                   -jne 0xa36bef
    if (!cpu.flags.zf)
    {
        goto L_0x00a36bef;
    }
    // 00a36be2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a36be4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36be5  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a36be8  2eff1588a9a300         -call dword ptr cs:[0xa3a988]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725768) /* 0xa3a988 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36bef:
    // 00a36bef  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bf0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bf1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bf2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36bf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36bf4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36bf4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36bf5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36bf6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36bf7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36bf8  2eff1564a9a300         -call dword ptr cs:[0xa3a964]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725732) /* 0xa3a964 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36bff  8b1560cca300           -mov edx, dword ptr [0xa3cc60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36c05  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36c06  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a36c08  2eff15b8a9a300         -call dword ptr cs:[0xa3a9b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725816) /* 0xa3a9b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36c0f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36c11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36c13  7507                   -jne 0xa36c1c
    if (!cpu.flags.zf)
    {
        goto L_0x00a36c1c;
    }
    // 00a36c15  e8ee0d0000             -call 0xa37a08
    cpu.esp -= 4;
    sub_a37a08(app, cpu);
    if (cpu.terminate) return;
    // 00a36c1a  eb0b                   -jmp 0xa36c27
    goto L_0x00a36c27;
L_0x00a36c1c:
    // 00a36c1c  80785300               +cmp byte ptr [eax + 0x53], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(83) /* 0x53 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a36c20  7407                   -je 0xa36c29
    if (cpu.flags.zf)
    {
        goto L_0x00a36c29;
    }
    // 00a36c22  e81a0e0000             -call 0xa37a41
    cpu.esp -= 4;
    sub_a37a41(app, cpu);
    if (cpu.terminate) return;
L_0x00a36c27:
    // 00a36c27  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a36c29:
    // 00a36c29  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36c2a  2eff15a4a9a300         -call dword ptr cs:[0xa3a9a4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725796) /* 0xa3a9a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36c31  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36c33  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36c34  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36c35  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36c36  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36c37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36c38(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36c38  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36c39  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36c3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36c3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36c3e  7526                   -jne 0xa36c66
    if (!cpu.flags.zf)
    {
        goto L_0x00a36c66;
    }
    // 00a36c40  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a36c45  8b1544cea300           -mov edx, dword ptr [0xa3ce44]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a36c4b  e8a00d0000             -call 0xa379f0
    cpu.esp -= 4;
    sub_a379f0(app, cpu);
    if (cpu.terminate) return;
    // 00a36c50  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36c52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36c54  7410                   -je 0xa36c66
    if (cpu.flags.zf)
    {
        goto L_0x00a36c66;
    }
    // 00a36c56  8b1d44cea300           -mov ebx, dword ptr [0xa3ce44]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a36c5c  c6405201               -mov byte ptr [eax + 0x52], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a36c60  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x00a36c66:
    // 00a36c66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a36c68  e8c70f0000             -call 0xa37c34
    cpu.esp -= 4;
    sub_a37c34(app, cpu);
    if (cpu.terminate) return;
    // 00a36c6d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a36c6f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36c70  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36c71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36c72(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36c72  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36c73  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36c74  2eff15b0a9a300         -call dword ptr cs:[0xa3a9b0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725808) /* 0xa3a9b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36c7b  668b1521cba300         -mov dx, word ptr [0xa3cb21]
    cpu.dx = *app->getMemory<x86::reg16>(x86::reg32(10734369) /* 0xa3cb21 */);
    // 00a36c82  a360cca300             -mov dword ptr [0xa3cc60], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */) = cpu.eax;
    // 00a36c87  6681fa0080             +cmp dx, 0x8000
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
    // 00a36c8c  7227                   -jb 0xa36cb5
    if (cpu.flags.cf)
    {
        goto L_0x00a36cb5;
    }
    // 00a36c8e  803d1fcba30004         +cmp byte ptr [0xa3cb1f], 4
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10734367) /* 0xa3cb1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a36c95  731e                   -jae 0xa36cb5
    if (!cpu.flags.cf)
    {
        goto L_0x00a36cb5;
    }
L_0x00a36c97:
    // 00a36c97  8b1560cca300           -mov edx, dword ptr [0xa3cc60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36c9d  83faff                 +cmp edx, -1
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
    // 00a36ca0  7413                   -je 0xa36cb5
    if (cpu.flags.zf)
    {
        goto L_0x00a36cb5;
    }
    // 00a36ca2  83fa02                 +cmp edx, 2
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
    // 00a36ca5  770e                   -ja 0xa36cb5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a36cb5;
    }
    // 00a36ca7  2eff15b0a9a300         -call dword ptr cs:[0xa3a9b0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725808) /* 0xa3a9b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36cae  a360cca300             -mov dword ptr [0xa3cc60], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */) = cpu.eax;
    // 00a36cb3  ebe2                   -jmp 0xa36c97
    goto L_0x00a36c97;
L_0x00a36cb5:
    // 00a36cb5  833d60cca300ff         +cmp dword ptr [0xa3cc60], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36cbc  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a36cbf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a36cc4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36cc5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36cc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36cc7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36cc7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36cc8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36cc9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36cca  833d60cca300ff         +cmp dword ptr [0xa3cc60], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a36cd1  7506                   -jne 0xa36cd9
    if (!cpu.flags.zf)
    {
        goto L_0x00a36cd9;
    }
L_0x00a36cd3:
    // 00a36cd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a36cd5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36cd6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36cd7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36cd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a36cd9:
    // 00a36cd9  e85affffff             -call 0xa36c38
    cpu.esp -= 4;
    sub_a36c38(app, cpu);
    if (cpu.terminate) return;
    // 00a36cde  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36ce0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36ce2  742e                   -je 0xa36d12
    if (cpu.flags.zf)
    {
        goto L_0x00a36d12;
    }
    // 00a36ce4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a36ce6  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a36cec  e8240e0000             -call 0xa37b15
    cpu.esp -= 4;
    sub_a37b15(app, cpu);
    if (cpu.terminate) return;
    // 00a36cf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36cf3  7509                   -jne 0xa36cfe
    if (!cpu.flags.zf)
    {
        goto L_0x00a36cfe;
    }
    // 00a36cf5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36cf7  e8010a0000             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a36cfc  ebd5                   -jmp 0xa36cd3
    goto L_0x00a36cd3;
L_0x00a36cfe:
    // 00a36cfe  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36cff  8b1d60cca300           -mov ebx, dword ptr [0xa3cc60]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36d05  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36d06  2eff15bca9a300         -call dword ptr cs:[0xa3a9bc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725820) /* 0xa3a9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36d0d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a36d12:
    // 00a36d12  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d13  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d14  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36d16(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36d16  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36d17  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36d18  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d19  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36d1a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36d1b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36d1d  8b1560cca300           -mov edx, dword ptr [0xa3cc60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36d23  83faff                 +cmp edx, -1
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
    // 00a36d26  743d                   -je 0xa36d65
    if (cpu.flags.zf)
    {
        goto L_0x00a36d65;
    }
    // 00a36d28  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d29  2eff15b8a9a300         -call dword ptr cs:[0xa3a9b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725816) /* 0xa3a9b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36d32  7431                   -je 0xa36d65
    if (cpu.flags.zf)
    {
        goto L_0x00a36d65;
    }
    // 00a36d34  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 00a36d3a  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a36d40  e8310e0000             -call 0xa37b76
    cpu.esp -= 4;
    sub_a37b76(app, cpu);
    if (cpu.terminate) return;
    // 00a36d45  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a36d47  8b3d60cca300           -mov edi, dword ptr [0xa3cc60]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36d4d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36d4e  2eff15bca9a300         -call dword ptr cs:[0xa3a9bc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725820) /* 0xa3a9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36d55  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a36d57  740c                   -je 0xa36d65
    if (cpu.flags.zf)
    {
        goto L_0x00a36d65;
    }
    // 00a36d59  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a36d5b  7408                   -je 0xa36d65
    if (cpu.flags.zf)
    {
        goto L_0x00a36d65;
    }
    // 00a36d5d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36d5e  2eff1524a9a300         -call dword ptr cs:[0xa3a924]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725668) /* 0xa3a924 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36d65:
    // 00a36d65  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d66  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d67  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d68  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d69  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36d65(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a36d65;
    // 00a36d16  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36d17  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36d18  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d19  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36d1a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36d1b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36d1d  8b1560cca300           -mov edx, dword ptr [0xa3cc60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36d23  83faff                 +cmp edx, -1
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
    // 00a36d26  743d                   -je 0xa36d65
    if (cpu.flags.zf)
    {
        goto L_0x00a36d65;
    }
    // 00a36d28  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d29  2eff15b8a9a300         -call dword ptr cs:[0xa3a9b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725816) /* 0xa3a9b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36d30  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36d32  7431                   -je 0xa36d65
    if (cpu.flags.zf)
    {
        goto L_0x00a36d65;
    }
    // 00a36d34  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 00a36d3a  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a36d40  e8310e0000             -call 0xa37b76
    cpu.esp -= 4;
    sub_a37b76(app, cpu);
    if (cpu.terminate) return;
    // 00a36d45  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a36d47  8b3d60cca300           -mov edi, dword ptr [0xa3cc60]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36d4d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36d4e  2eff15bca9a300         -call dword ptr cs:[0xa3a9bc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725820) /* 0xa3a9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36d55  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a36d57  740c                   -je 0xa36d65
    if (cpu.flags.zf)
    {
        goto L_0x00a36d65;
    }
    // 00a36d59  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a36d5b  7408                   -je 0xa36d65
    if (cpu.flags.zf)
    {
        goto L_0x00a36d65;
    }
    // 00a36d5d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36d5e  2eff1524a9a300         -call dword ptr cs:[0xa3a924]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725668) /* 0xa3a924 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a36d65:
L_entry_0x00a36d65:
    // 00a36d65  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d66  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d67  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d68  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d69  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36d6b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36d6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a36d70  e8a1ffffff             -call 0xa36d16
    cpu.esp -= 4;
    sub_a36d16(app, cpu);
    if (cpu.terminate) return;
    // 00a36d75  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36d76  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d77  8b1560cca300           -mov edx, dword ptr [0xa3cc60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36d7d  83faff                 +cmp edx, -1
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
    // 00a36d80  7412                   -je 0xa36d94
    if (cpu.flags.zf)
    {
        goto L_0x00a36d94;
    }
    // 00a36d82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d83  2eff15b4a9a300         -call dword ptr cs:[0xa3a9b4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725812) /* 0xa3a9b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36d8a  c70560cca300ffffffff   -mov dword ptr [0xa3cc60], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */) = 4294967295 /*0xffffffff*/;
L_0x00a36d94:
    // 00a36d94  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d95  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36d75(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a36d75;
    // 00a36d6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a36d70  e8a1ffffff             -call 0xa36d16
    cpu.esp -= 4;
    sub_a36d16(app, cpu);
    if (cpu.terminate) return;
L_entry_0x00a36d75:
    // 00a36d75  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36d76  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d77  8b1560cca300           -mov edx, dword ptr [0xa3cc60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36d7d  83faff                 +cmp edx, -1
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
    // 00a36d80  7412                   -je 0xa36d94
    if (cpu.flags.zf)
    {
        goto L_0x00a36d94;
    }
    // 00a36d82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d83  2eff15b4a9a300         -call dword ptr cs:[0xa3a9b4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725812) /* 0xa3a9b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36d8a  c70560cca300ffffffff   -mov dword ptr [0xa3cc60], 0xffffffff
    *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */) = 4294967295 /*0xffffffff*/;
L_0x00a36d94:
    // 00a36d94  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d95  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36d96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36d97(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36d97  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36d98  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36d99  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36d9a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36d9b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36d9c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a36d9d  baf46aa300             -mov edx, 0xa36af4
    cpu.edx = 10709748 /*0xa36af4*/;
    // 00a36da2  bb016ba300             -mov ebx, 0xa36b01
    cpu.ebx = 10709761 /*0xa36b01*/;
    // 00a36da7  b9116ba300             -mov ecx, 0xa36b11
    cpu.ecx = 10709777 /*0xa36b11*/;
    // 00a36dac  be166ba300             -mov esi, 0xa36b16
    cpu.esi = 10709782 /*0xa36b16*/;
    // 00a36db1  bfe06aa300             -mov edi, 0xa36ae0
    cpu.edi = 10709728 /*0xa36ae0*/;
    // 00a36db6  bdea6aa300             -mov ebp, 0xa36aea
    cpu.ebp = 10709738 /*0xa36aea*/;
    // 00a36dbb  b8546ba300             -mov eax, 0xa36b54
    cpu.eax = 10709844 /*0xa36b54*/;
    // 00a36dc0  891568cca300           -mov dword ptr [0xa3cc68], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734696) /* 0xa3cc68 */) = cpu.edx;
    // 00a36dc6  891d6ccca300           -mov dword ptr [0xa3cc6c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10734700) /* 0xa3cc6c */) = cpu.ebx;
    // 00a36dcc  890d70cca300           -mov dword ptr [0xa3cc70], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10734704) /* 0xa3cc70 */) = cpu.ecx;
    // 00a36dd2  893574cca300           -mov dword ptr [0xa3cc74], esi
    *app->getMemory<x86::reg32>(x86::reg32(10734708) /* 0xa3cc74 */) = cpu.esi;
    // 00a36dd8  893d78cca300           -mov dword ptr [0xa3cc78], edi
    *app->getMemory<x86::reg32>(x86::reg32(10734712) /* 0xa3cc78 */) = cpu.edi;
    // 00a36dde  892d7ccca300           -mov dword ptr [0xa3cc7c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(10734716) /* 0xa3cc7c */) = cpu.ebp;
    // 00a36de4  a390cca300             -mov dword ptr [0xa3cc90], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734736) /* 0xa3cc90 */) = cpu.eax;
    // 00a36de9  ba5b6ba300             -mov edx, 0xa36b5b
    cpu.edx = 10709851 /*0xa36b5b*/;
    // 00a36dee  bb676ba300             -mov ebx, 0xa36b67
    cpu.ebx = 10709863 /*0xa36b67*/;
    // 00a36df3  b9cd6ba300             -mov ecx, 0xa36bcd
    cpu.ecx = 10709965 /*0xa36bcd*/;
    // 00a36df8  beb26aa300             -mov esi, 0xa36ab2
    cpu.esi = 10709682 /*0xa36ab2*/;
    // 00a36dfd  bf326ba300             -mov edi, 0xa36b32
    cpu.edi = 10709810 /*0xa36b32*/;
    // 00a36e02  bd436ba300             -mov ebp, 0xa36b43
    cpu.ebp = 10709827 /*0xa36b43*/;
    // 00a36e07  b8396ba300             -mov eax, 0xa36b39
    cpu.eax = 10709817 /*0xa36b39*/;
    // 00a36e0c  891594cca300           -mov dword ptr [0xa3cc94], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734740) /* 0xa3cc94 */) = cpu.edx;
    // 00a36e12  891d0ccda300           -mov dword ptr [0xa3cd0c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10734860) /* 0xa3cd0c */) = cpu.ebx;
    // 00a36e18  890d10cda300           -mov dword ptr [0xa3cd10], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10734864) /* 0xa3cd10 */) = cpu.ecx;
    // 00a36e1e  893514cda300           -mov dword ptr [0xa3cd14], esi
    *app->getMemory<x86::reg32>(x86::reg32(10734868) /* 0xa3cd14 */) = cpu.esi;
    // 00a36e24  893d80cca300           -mov dword ptr [0xa3cc80], edi
    *app->getMemory<x86::reg32>(x86::reg32(10734720) /* 0xa3cc80 */) = cpu.edi;
    // 00a36e2a  892d84cca300           -mov dword ptr [0xa3cc84], ebp
    *app->getMemory<x86::reg32>(x86::reg32(10734724) /* 0xa3cc84 */) = cpu.ebp;
    // 00a36e30  a388cca300             -mov dword ptr [0xa3cc88], eax
    *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */) = cpu.eax;
    // 00a36e35  ba4a6ba300             -mov edx, 0xa36b4a
    cpu.edx = 10709834 /*0xa36b4a*/;
    // 00a36e3a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a36e3f  bec86ba300             -mov esi, 0xa36bc8
    cpu.esi = 10709960 /*0xa36bc8*/;
    // 00a36e44  89158ccca300           -mov dword ptr [0xa3cc8c], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734732) /* 0xa3cc8c */) = cpu.edx;
    // 00a36e4a  e80ffcffff             -call 0xa36a5e
    cpu.esp -= 4;
    sub_a36a5e(app, cpu);
    if (cpu.terminate) return;
    // 00a36e4f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a36e50  bf6b6da300             -mov edi, 0xa36d6b
    cpu.edi = 10710379 /*0xa36d6b*/;
    // 00a36e55  a350daa300             -mov dword ptr [0xa3da50], eax
    *app->getMemory<x86::reg32>(x86::reg32(10738256) /* 0xa3da50 */) = cpu.eax;
    // 00a36e5a  2eff1584a9a300         -call dword ptr cs:[0xa3a984]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725764) /* 0xa3a984 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36e61  b9626ba300             -mov ecx, 0xa36b62
    cpu.ecx = 10709858 /*0xa36b62*/;
    // 00a36e66  8b151cd9a300           -mov edx, dword ptr [0xa3d91c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10737948) /* 0xa3d91c */);
    // 00a36e6c  891d54daa300           -mov dword ptr [0xa3da54], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10738260) /* 0xa3da54 */) = cpu.ebx;
    // 00a36e72  89359ccca300           -mov dword ptr [0xa3cc9c], esi
    *app->getMemory<x86::reg32>(x86::reg32(10734748) /* 0xa3cc9c */) = cpu.esi;
    // 00a36e78  893da0cca300           -mov dword ptr [0xa3cca0], edi
    *app->getMemory<x86::reg32>(x86::reg32(10734752) /* 0xa3cca0 */) = cpu.edi;
    // 00a36e7e  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 00a36e84  890d98cca300           -mov dword ptr [0xa3cc98], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10734744) /* 0xa3cc98 */) = cpu.ecx;
    // 00a36e8a  e8860c0000             -call 0xa37b15
    cpu.esp -= 4;
    sub_a37b15(app, cpu);
    if (cpu.terminate) return;
    // 00a36e8f  8b2d1cd9a300           -mov ebp, dword ptr [0xa3d91c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10737948) /* 0xa3d91c */);
    // 00a36e95  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a36e96  a160cca300             -mov eax, dword ptr [0xa3cc60]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a36e9b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a36e9c  2eff15bca9a300         -call dword ptr cs:[0xa3a9bc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725820) /* 0xa3a9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36ea3  c70564cca300f46ba300   -mov dword ptr [0xa3cc64], 0xa36bf4
    *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */) = 10710004 /*0xa36bf4*/;
    // 00a36ead  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36eae  e9b2feffff             -jmp 0xa36d65
    return sub_a36d65(app, cpu);
}

/* align: skip  */
void sub_a36eb3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36eb3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36eb4  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36eb5  b820d9a300             -mov eax, 0xa3d920
    cpu.eax = 10737952 /*0xa3d920*/;
    // 00a36eba  ba40d9a300             -mov edx, 0xa3d940
    cpu.edx = 10737984 /*0xa3d940*/;
    // 00a36ebf  ff1514cda300           -call dword ptr [0xa3cd14]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734868) /* 0xa3cd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36ec5  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x00a36ecb:
    // 00a36ecb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a36ecd  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a36ed0  ff1514cda300           -call dword ptr [0xa3cd14]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734868) /* 0xa3cd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36ed6  39da                   +cmp edx, ebx
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
    // 00a36ed8  75f1                   -jne 0xa36ecb
    if (!cpu.flags.zf)
    {
        goto L_0x00a36ecb;
    }
    // 00a36eda  b870daa300             -mov eax, 0xa3da70
    cpu.eax = 10738288 /*0xa3da70*/;
    // 00a36edf  ff1514cda300           -call dword ptr [0xa3cd14]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734868) /* 0xa3cd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36ee5  e8720d0000             -call 0xa37c5c
    cpu.esp -= 4;
    sub_a37c5c(app, cpu);
    if (cpu.terminate) return;
    // 00a36eea  b840daa300             -mov eax, 0xa3da40
    cpu.eax = 10738240 /*0xa3da40*/;
    // 00a36eef  ff1514cda300           -call dword ptr [0xa3cd14]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734868) /* 0xa3cd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36ef5  b830d9a300             -mov eax, 0xa3d930
    cpu.eax = 10737968 /*0xa3d930*/;
    // 00a36efa  ff1514cda300           -call dword ptr [0xa3cd14]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734868) /* 0xa3cd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36f00  b860daa300             -mov eax, 0xa3da60
    cpu.eax = 10738272 /*0xa3da60*/;
    // 00a36f05  ff1514cda300           -call dword ptr [0xa3cd14]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734868) /* 0xa3cd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36f0b  b850daa300             -mov eax, 0xa3da50
    cpu.eax = 10738256 /*0xa3da50*/;
    // 00a36f10  ff1514cda300           -call dword ptr [0xa3cd14]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734868) /* 0xa3cd14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36f16  e85afeffff             -call 0xa36d75
    cpu.esp -= 4;
    sub_a36d75(app, cpu);
    if (cpu.terminate) return;
    // 00a36f1b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f1c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36f1e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36f1e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36f1f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36f20  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36f21  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36f22  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a36f24  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a36f26  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a36f27  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a36f29  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a36f2b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a36f2d  49                     -dec ecx
    (cpu.ecx)--;
    // 00a36f2e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a36f30  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
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
    // 00a36f32  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a36f34  49                     -dec ecx
    (cpu.ecx)--;
    // 00a36f35  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a36f36  41                     -inc ecx
    (cpu.ecx)++;
    // 00a36f37  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a36f39  e8d2060000             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a36f3e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36f40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36f42  7418                   -je 0xa36f5c
    if (cpu.flags.zf)
    {
        goto L_0x00a36f5c;
    }
    // 00a36f44  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a36f46  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a36f47  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a36f49  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a36f4b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36f4c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a36f4e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a36f51  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a36f53  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a36f55  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a36f58  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a36f5a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f5b  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a36f5c:
    // 00a36f5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a36f5e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f5f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f60  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f61  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f62  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36f63(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36f63  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36f64  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36f65  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36f66  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a36f67  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a36f69  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a36f6b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a36f6d  2eff1580a9a300         -call dword ptr cs:[0xa3a980]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725760) /* 0xa3a980 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36f74  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a36f77  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a36f7c  663d0080               +cmp ax, 0x8000
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a36f80  730f                   -jae 0xa36f91
    if (!cpu.flags.cf)
    {
        goto L_0x00a36f91;
    }
    // 00a36f82  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36f83  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36f84  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a36f85  2eff156ca9a300         -call dword ptr cs:[0xa3a96c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725740) /* 0xa3a96c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36f8c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f8d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f8e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f8f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36f90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a36f91:
    // 00a36f91  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 00a36f96  e875060000             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a36f9b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a36f9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36f9f  744d                   -je 0xa36fee
    if (cpu.flags.zf)
    {
        goto L_0x00a36fee;
    }
    // 00a36fa1  6808020000             -push 0x208
    *app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 00a36fa6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a36fa7  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a36fa8  2eff1568a9a300         -call dword ptr cs:[0xa3a968]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725736) /* 0xa3a968 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36faf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a36fb1  750e                   -jne 0xa36fc1
    if (!cpu.flags.zf)
    {
        goto L_0x00a36fc1;
    }
    // 00a36fb3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36fb5  e843070000             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a36fba:
    // 00a36fba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a36fbc  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36fbd  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36fbe  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36fbf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36fc0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a36fc1:
    // 00a36fc1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a36fc2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a36fc3  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a36fc5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36fc6  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a36fc8  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a36fca  2eff1590a9a300         -call dword ptr cs:[0xa3a990]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725776) /* 0xa3a990 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a36fd1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a36fd3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a36fd5  e823070000             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a36fda  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a36fdc  74dc                   -je 0xa36fba
    if (cpu.flags.zf)
    {
        goto L_0x00a36fba;
    }
    // 00a36fde  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a36fe0  66c74446fe0000         -mov word ptr [esi + eax*2 - 2], 0
    *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.eax * 2) = 0 /*0x0*/;
    // 00a36fe7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a36fe9  e8350d0000             -call 0xa37d23
    cpu.esp -= 4;
    sub_a37d23(app, cpu);
    if (cpu.terminate) return;
L_0x00a36fee:
    // 00a36fee  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36fef  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36ff0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36ff1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a36ff2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a36ff3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a36ff3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a36ff4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a36ff5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a36ff6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a36ff8  e8260d0000             -call 0xa37d23
    cpu.esp -= 4;
    sub_a37d23(app, cpu);
    if (cpu.terminate) return;
    // 00a36ffd  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a37000  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a37002  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37004  e807060000             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a37009  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a3700b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3700d  7405                   -je 0xa37014
    if (cpu.flags.zf)
    {
        goto L_0x00a37014;
    }
    // 00a3700f  e8220d0000             -call 0xa37d36
    cpu.esp -= 4;
    sub_a37d36(app, cpu);
    if (cpu.terminate) return;
L_0x00a37014:
    // 00a37014  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a37016  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37017  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37018  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37019  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3701a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3701a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3701b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3701c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3701d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a37020  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37022  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a37024  6a1c                   -push 0x1c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00a37026  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a3702a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3702b  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a3702f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a37030  2eff15cca9a300         -call dword ptr cs:[0xa3a9cc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725836) /* 0xa3a9cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37037  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a3703a  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a3703e  668b0d21cba300         -mov cx, word ptr [0xa3cb21]
    cpu.cx = *app->getMemory<x86::reg16>(x86::reg32(10734369) /* 0xa3cb21 */);
    // 00a37045  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a37049  6681f90080             +cmp cx, 0x8000
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a3704e  7307                   -jae 0xa37057
    if (!cpu.flags.cf)
    {
        goto L_0x00a37057;
    }
    // 00a37050  0500300000             +add eax, 0x3000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12288 /*0x3000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a37055  eb17                   -jmp 0xa3706e
    goto L_0x00a3706e;
L_0x00a37057:
    // 00a37057  7210                   -jb 0xa37069
    if (cpu.flags.cf)
    {
        goto L_0x00a37069;
    }
    // 00a37059  803d1fcba30004         +cmp byte ptr [0xa3cb1f], 4
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10734367) /* 0xa3cb1f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a37060  7307                   -jae 0xa37069
    if (!cpu.flags.cf)
    {
        goto L_0x00a37069;
    }
    // 00a37062  0500200100             +add eax, 0x12000
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(73728 /*0x12000*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a37067  eb05                   -jmp 0xa3706e
    goto L_0x00a3706e;
L_0x00a37069:
    // 00a37069  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x00a3706e:
    // 00a3706e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a37070  7402                   -je 0xa37074
    if (cpu.flags.zf)
    {
        goto L_0x00a37074;
    }
    // 00a37072  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a37074:
    // 00a37074  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a37076  7402                   -je 0xa3707a
    if (cpu.flags.zf)
    {
        goto L_0x00a3707a;
    }
    // 00a37078  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x00a3707a:
    // 00a3707a  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a3707d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3707e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3707f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37081(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37081  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37082  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37083  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37084  6870bba300             -push 0xa3bb70
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10730352 /*0xa3bb70*/;
    cpu.esp -= 4;
    // 00a37089  2eff158ca9a300         -call dword ptr cs:[0xa3a98c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725772) /* 0xa3a98c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37090  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a37092  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37094  7417                   -je 0xa370ad
    if (cpu.flags.zf)
    {
        goto L_0x00a370ad;
    }
    // 00a37096  687bbba300             -push 0xa3bb7b
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10730363 /*0xa3bb7b*/;
    cpu.esp -= 4;
    // 00a3709b  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3709c  2eff1578a9a300         -call dword ptr cs:[0xa3a978]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725752) /* 0xa3a978 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a370a3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a370a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a370a7  7404                   -je 0xa370ad
    if (cpu.flags.zf)
    {
        goto L_0x00a370ad;
    }
    // 00a370a9  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a370ab  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a370ad:
    // 00a370ad  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a370af  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a370b2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a370b7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a370b8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a370b9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a370ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a370bb(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a370bb  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a370bc  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a370bd  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a370be  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a370c0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a370c2:
    // 00a370c2  803800                 +cmp byte ptr [eax], 0
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
    // 00a370c5  7403                   -je 0xa370ca
    if (cpu.flags.zf)
    {
        goto L_0x00a370ca;
    }
    // 00a370c7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a370c8  ebf8                   -jmp 0xa370c2
    goto L_0x00a370c2;
L_0x00a370ca:
    // 00a370ca  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x00a370cd:
    // 00a370cd  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a370cf  8808                   -mov byte ptr [eax], cl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00a370d1  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a370d3  7412                   -je 0xa370e7
    if (cpu.flags.zf)
    {
        goto L_0x00a370e7;
    }
    // 00a370d5  80f930                 +cmp cl, 0x30
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a370d8  7508                   -jne 0xa370e2
    if (!cpu.flags.zf)
    {
        goto L_0x00a370e2;
    }
    // 00a370da  807a0178               +cmp byte ptr [edx + 1], 0x78
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a370de  7502                   -jne 0xa370e2
    if (!cpu.flags.zf)
    {
        goto L_0x00a370e2;
    }
    // 00a370e0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00a370e2:
    // 00a370e2  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a370e3  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a370e4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a370e5  ebe6                   -jmp 0xa370cd
    goto L_0x00a370cd;
L_0x00a370e7:
    // 00a370e7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a370e9  7419                   -je 0xa37104
    if (cpu.flags.zf)
    {
        goto L_0x00a37104;
    }
    // 00a370eb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a370ed:
    // 00a370ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a370ef  7413                   -je 0xa37104
    if (cpu.flags.zf)
    {
        goto L_0x00a37104;
    }
    // 00a370f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a370f3  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a370f6  8a9224cea300           -mov dl, byte ptr [edx + 0xa3ce24]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10735140) /* 0xa3ce24 */);
    // 00a370fc  c1e804                 +shr eax, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a370ff  8813                   -mov byte ptr [ebx], dl
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 00a37101  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a37102  ebe9                   -jmp 0xa370ed
    goto L_0x00a370ed;
L_0x00a37104:
    // 00a37104  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37105  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37106  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37107  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37108(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37108  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37109  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3710a  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a37110  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00a37117  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a37119  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a3711c  e860ffffff             -call 0xa37081
    cpu.esp -= 4;
    sub_a37081(app, cpu);
    if (cpu.terminate) return;
    // 00a37121  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37123  750a                   -jne 0xa3712f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3712f;
    }
    // 00a37125  e8ce0c0000             -call 0xa37df8
    cpu.esp -= 4;
    sub_a37df8(app, cpu);
    if (cpu.terminate) return;
    // 00a3712a  83f8ff                 +cmp eax, -1
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
    // 00a3712d  7507                   -jne 0xa37136
    if (!cpu.flags.zf)
    {
        goto L_0x00a37136;
    }
L_0x00a3712f:
    // 00a3712f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a37131  e97e010000             -jmp 0xa372b4
    goto L_0x00a372b4;
L_0x00a37136:
    // 00a37136  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a37138  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00a3713b  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a3713d  3d900000c0             +cmp eax, 0xc0000090
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225616 /*0xc0000090*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37142  724d                   -jb 0xa37191
    if (cpu.flags.cf)
    {
        goto L_0x00a37191;
    }
    // 00a37144  0f86b5000000           -jbe 0xa371ff
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a371ff;
    }
    // 00a3714a  3d930000c0             +cmp eax, 0xc0000093
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225619 /*0xc0000093*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3714f  7233                   -jb 0xa37184
    if (cpu.flags.cf)
    {
        goto L_0x00a37184;
    }
    // 00a37151  0f86a1000000           -jbe 0xa371f8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a371f8;
    }
    // 00a37157  3d960000c0             +cmp eax, 0xc0000096
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225622 /*0xc0000096*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3715c  7216                   -jb 0xa37174
    if (cpu.flags.cf)
    {
        goto L_0x00a37174;
    }
    // 00a3715e  0f86d8000000           -jbe 0xa3723c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a3723c;
    }
    // 00a37164  3dfd0000c0             +cmp eax, 0xc00000fd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225725 /*0xc00000fd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37169  0f84e5000000           -je 0xa37254
    if (cpu.flags.zf)
    {
        goto L_0x00a37254;
    }
    // 00a3716f  e9ea000000             -jmp 0xa3725e
    goto L_0x00a3725e;
L_0x00a37174:
    // 00a37174  3d940000c0             +cmp eax, 0xc0000094
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225620 /*0xc0000094*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37179  0f84cb000000           -je 0xa3724a
    if (cpu.flags.zf)
    {
        goto L_0x00a3724a;
    }
    // 00a3717f  e9da000000             -jmp 0xa3725e
    goto L_0x00a3725e;
L_0x00a37184:
    // 00a37184  3d910000c0             +cmp eax, 0xc0000091
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225617 /*0xc0000091*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37189  0f8662000000           -jbe 0xa371f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a371f1;
    }
    // 00a3718f  eb2f                   -jmp 0xa371c0
    goto L_0x00a371c0;
L_0x00a37191:
    // 00a37191  3d8d0000c0             +cmp eax, 0xc000008d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225613 /*0xc000008d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37196  720b                   -jb 0xa371a3
    if (cpu.flags.cf)
    {
        goto L_0x00a371a3;
    }
    // 00a37198  7642                   -jbe 0xa371dc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a371dc;
    }
    // 00a3719a  3d8e0000c0             +cmp eax, 0xc000008e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225614 /*0xc000008e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3719f  7642                   -jbe 0xa371e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a371e3;
    }
    // 00a371a1  eb47                   -jmp 0xa371ea
    goto L_0x00a371ea;
L_0x00a371a3:
    // 00a371a3  3d050000c0             +cmp eax, 0xc0000005
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225477 /*0xc0000005*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a371a8  0f82b0000000           -jb 0xa3725e
    if (cpu.flags.cf)
    {
        goto L_0x00a3725e;
    }
    // 00a371ae  7656                   -jbe 0xa37206
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a37206;
    }
    // 00a371b0  3d1d0000c0             +cmp eax, 0xc000001d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3221225501 /*0xc000001d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a371b5  0f8488000000           -je 0xa37243
    if (cpu.flags.zf)
    {
        goto L_0x00a37243;
    }
    // 00a371bb  e99e000000             -jmp 0xa3725e
    goto L_0x00a3725e;
L_0x00a371c0:
    // 00a371c0  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a371c4  740f                   -je 0xa371d5
    if (cpu.flags.zf)
    {
        goto L_0x00a371d5;
    }
    // 00a371c6  ba8bbba300             -mov edx, 0xa3bb8b
    cpu.edx = 10730379 /*0xa3bb8b*/;
L_0x00a371cb:
    // 00a371cb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a371cd  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a371d0  e9a1000000             -jmp 0xa37276
    goto L_0x00a37276;
L_0x00a371d5:
    // 00a371d5  badcbba300             -mov edx, 0xa3bbdc
    cpu.edx = 10730460 /*0xa3bbdc*/;
    // 00a371da  ebef                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a371dc:
    // 00a371dc  ba2ebca300             -mov edx, 0xa3bc2e
    cpu.edx = 10730542 /*0xa3bc2e*/;
    // 00a371e1  ebe8                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a371e3:
    // 00a371e3  ba81bca300             -mov edx, 0xa3bc81
    cpu.edx = 10730625 /*0xa3bc81*/;
    // 00a371e8  ebe1                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a371ea:
    // 00a371ea  bad4bca300             -mov edx, 0xa3bcd4
    cpu.edx = 10730708 /*0xa3bcd4*/;
    // 00a371ef  ebda                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a371f1:
    // 00a371f1  ba25bda300             -mov edx, 0xa3bd25
    cpu.edx = 10730789 /*0xa3bd25*/;
    // 00a371f6  ebd3                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a371f8:
    // 00a371f8  ba71bda300             -mov edx, 0xa3bd71
    cpu.edx = 10730865 /*0xa3bd71*/;
    // 00a371fd  ebcc                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a371ff:
    // 00a371ff  babebda300             -mov edx, 0xa3bdbe
    cpu.edx = 10730942 /*0xa3bdbe*/;
    // 00a37204  ebc5                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a37206:
    // 00a37206  ba13bea300             -mov edx, 0xa3be13
    cpu.edx = 10731027 /*0xa3be13*/;
    // 00a3720b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3720d  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a37210  e8a6feffff             -call 0xa370bb
    cpu.esp -= 4;
    sub_a370bb(app, cpu);
    if (cpu.terminate) return;
    // 00a37215  ba44bea300             -mov edx, 0xa3be44
    cpu.edx = 10731076 /*0xa3be44*/;
    // 00a3721a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3721c  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00a3721f  e897feffff             -call 0xa370bb
    cpu.esp -= 4;
    sub_a370bb(app, cpu);
    if (cpu.terminate) return;
    // 00a37224  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37228  750b                   -jne 0xa37235
    if (!cpu.flags.zf)
    {
        goto L_0x00a37235;
    }
    // 00a3722a  ba6cbea300             -mov edx, 0xa3be6c
    cpu.edx = 10731116 /*0xa3be6c*/;
L_0x00a3722f:
    // 00a3722f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a37231  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a37233  eb41                   -jmp 0xa37276
    goto L_0x00a37276;
L_0x00a37235:
    // 00a37235  ba73bea300             -mov edx, 0xa3be73
    cpu.edx = 10731123 /*0xa3be73*/;
    // 00a3723a  ebf3                   -jmp 0xa3722f
    goto L_0x00a3722f;
L_0x00a3723c:
    // 00a3723c  ba7dbea300             -mov edx, 0xa3be7d
    cpu.edx = 10731133 /*0xa3be7d*/;
    // 00a37241  eb88                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a37243:
    // 00a37243  babbbea300             -mov edx, 0xa3bebb
    cpu.edx = 10731195 /*0xa3bebb*/;
    // 00a37248  eb81                   -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a3724a:
    // 00a3724a  baf7bea300             -mov edx, 0xa3bef7
    cpu.edx = 10731255 /*0xa3bef7*/;
    // 00a3724f  e977ffffff             -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a37254:
    // 00a37254  ba39bfa300             -mov edx, 0xa3bf39
    cpu.edx = 10731321 /*0xa3bf39*/;
    // 00a37259  e96dffffff             -jmp 0xa371cb
    goto L_0x00a371cb;
L_0x00a3725e:
    // 00a3725e  ba72bfa300             -mov edx, 0xa3bf72
    cpu.edx = 10731378 /*0xa3bf72*/;
    // 00a37263  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a37265  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a37267  e84ffeffff             -call 0xa370bb
    cpu.esp -= 4;
    sub_a370bb(app, cpu);
    if (cpu.terminate) return;
    // 00a3726c  baa3bfa300             -mov edx, 0xa3bfa3
    cpu.edx = 10731427 /*0xa3bfa3*/;
    // 00a37271  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a37273  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00a37276:
    // 00a37276  e840feffff             -call 0xa370bb
    cpu.esp -= 4;
    sub_a370bb(app, cpu);
    if (cpu.terminate) return;
    // 00a3727b  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3727d  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00a37284  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a37285  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a37289  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a3728a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a3728c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a3728e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37290  49                     -dec ecx
    (cpu.ecx)--;
    // 00a37291  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a37293  f2ae                   -repne scasb al, byte ptr es:[edi]
    while (cpu.ecx)
    {
        {
            x86::reg8 tmp1 = cpu.al;
            x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.ees + cpu.edi)));
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
    // 00a37295  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a37297  49                     -dec ecx
    (cpu.ecx)--;
    // 00a37298  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a37299  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3729a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a3729e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3729f  a154cca300             -mov eax, dword ptr [0xa3cc54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a372a4  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a372a7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a372a8  2eff15d8a9a300         -call dword ptr cs:[0xa3a9d8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725848) /* 0xa3a9d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a372af  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a372b4:
    // 00a372b4  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a372ba  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a372bb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a372bc  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
/* data blob: 8bc02773a3003173a3003b73a3005973a3004573a3000d73a3004f73a300 */
void sub_a372dd(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a372dd  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a372de  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a372df  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a372e0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a372e3  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a372e7  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a372eb  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00a372ef  0f85a0010000           -jne 0xa37495
    if (!cpu.flags.zf)
    {
        goto L_0x00a37495;
    }
    // 00a372f5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a372f7  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 00a372fc  83f806                 +cmp eax, 6
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
    // 00a372ff  0f8723010000           -ja 0xa37428
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a37428;
    }
    // 00a37305  2eff2485c172a300       -jmp dword ptr cs:[eax*4 + 0xa372c1]
    cpu.ip = *app->getMemory<x86::reg32>(10711745 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a3730d:
    // 00a3730d  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a37311  740a                   -je 0xa3731d
    if (cpu.flags.zf)
    {
        goto L_0x00a3731d;
    }
    // 00a37313  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 00a37318  e9ce000000             -jmp 0xa373eb
    goto L_0x00a373eb;
L_0x00a3731d:
    // 00a3731d  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 00a37322  e9c4000000             -jmp 0xa373eb
    goto L_0x00a373eb;
  case 0x00a37327:
    // 00a37327  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 00a3732c  e9ba000000             -jmp 0xa373eb
    goto L_0x00a373eb;
  case 0x00a37331:
L_0x00a37331:
    // 00a37331  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 00a37336  e9b0000000             -jmp 0xa373eb
    goto L_0x00a373eb;
  case 0x00a3733b:
    // 00a3733b  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 00a37340  e9a6000000             -jmp 0xa373eb
    goto L_0x00a373eb;
  case 0x00a37345:
    // 00a37345  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 00a3734a  e99c000000             -jmp 0xa373eb
    goto L_0x00a373eb;
  case 0x00a3734f:
    // 00a3734f  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00a37354  e992000000             -jmp 0xa373eb
    goto L_0x00a373eb;
  case 0x00a37359:
    // 00a37359  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a3735c  668b10                 -mov dx, word ptr [eax]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.eax);
    // 00a3735f  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 00a37364  6681fad9fa             +cmp dx, 0xfad9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(64217 /*0xfad9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a37369  750a                   -jne 0xa37375
    if (!cpu.flags.zf)
    {
        goto L_0x00a37375;
    }
    // 00a3736b  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 00a37370  e976000000             -jmp 0xa373eb
    goto L_0x00a373eb;
L_0x00a37375:
    // 00a37375  6681fad9f1             +cmp dx, 0xf1d9
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61913 /*0xf1d9*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a3737a  750a                   -jne 0xa37386
    if (!cpu.flags.zf)
    {
        goto L_0x00a37386;
    }
    // 00a3737c  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 00a37381  e965000000             -jmp 0xa373eb
    goto L_0x00a373eb;
L_0x00a37386:
    // 00a37386  7507                   -jne 0xa3738f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3738f;
    }
    // 00a37388  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00a3738d  eb5c                   -jmp 0xa373eb
    goto L_0x00a373eb;
L_0x00a3738f:
    // 00a3738f  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a37391  80fedb                 +cmp dh, 0xdb
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(219 /*0xdb*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a37394  7405                   -je 0xa3739b
    if (cpu.flags.zf)
    {
        goto L_0x00a3739b;
    }
    // 00a37396  80fedf                 +cmp dh, 0xdf
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(223 /*0xdf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a37399  7510                   -jne 0xa373ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a373ab;
    }
L_0x00a3739b:
    // 00a3739b  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a3739e  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a373a1  80fa10                 +cmp dl, 0x10
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
    // 00a373a4  7505                   -jne 0xa373ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a373ab;
    }
    // 00a373a6  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x00a373ab:
    // 00a373ab  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a373ae  7536                   -jne 0xa373e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a373e6;
    }
    // 00a373b0  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a373b3  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a373b5  3c30                   +cmp al, 0x30
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
    // 00a373b7  752d                   -jne 0xa373e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a373e6;
    }
    // 00a373b9  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a373bc  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a373c1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a373c4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a373c6  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 00a373ca  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00a373cd  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 00a373d0  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a373d6  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a373d8  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00a373da  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00a373dd  83fa01                 +cmp edx, 1
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
    // 00a373e0  0f844bffffff           -je 0xa37331
    if (cpu.flags.zf)
    {
        goto L_0x00a37331;
    }
L_0x00a373e6:
    // 00a373e6  83fbff                 +cmp ebx, -1
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
    // 00a373e9  743d                   -je 0xa37428
    if (cpu.flags.zf)
    {
        goto L_0x00a37428;
    }
L_0x00a373eb:
    // 00a373eb  c60594e0a30001         -mov byte ptr [0xa3e094], 1
    *app->getMemory<x86::reg8>(x86::reg32(10739860) /* 0xa3e094 */) = 1 /*0x1*/;
    // 00a373f2  e80c0a0000             -call 0xa37e03
    cpu.esp -= 4;
    sub_a37e03(app, cpu);
    if (cpu.terminate) return;
    // 00a373f7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a373f9  e8d20b0000             -call 0xa37fd0
    cpu.esp -= 4;
    sub_a37fd0(app, cpu);
    if (cpu.terminate) return;
    // 00a373fe  83f8ff                 +cmp eax, -1
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
    // 00a37401  0f846f000000           -je 0xa37476
    if (cpu.flags.zf)
    {
        goto L_0x00a37476;
    }
    // 00a37407  803d94e0a30000         +cmp byte ptr [0xa3e094], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10739860) /* 0xa3e094 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3740e  0f8462000000           -je 0xa37476
    if (cpu.flags.zf)
    {
        goto L_0x00a37476;
    }
    // 00a37414  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a37418  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a3741a  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a3741d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a3741f  66895f20               -mov word ptr [edi + 0x20], bx
    *app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 00a37423  e972000000             -jmp 0xa3749a
    goto L_0x00a3749a;
L_0x00a37428:
    // 00a37428  833d20cea30000         +cmp dword ptr [0xa3ce20], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10735136) /* 0xa3ce20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3742f  7445                   -je 0xa37476
    if (cpu.flags.zf)
    {
        goto L_0x00a37476;
    }
    // 00a37431  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00a37436:
    // 00a37436  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37438  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3743a  ff151ccea300           -call dword ptr [0xa3ce1c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10735132) /* 0xa3ce1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37440  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37442  742c                   -je 0xa37470
    if (cpu.flags.zf)
    {
        goto L_0x00a37470;
    }
    // 00a37444  83f801                 +cmp eax, 1
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
    // 00a37447  742d                   -je 0xa37476
    if (cpu.flags.zf)
    {
        goto L_0x00a37476;
    }
    // 00a37449  83f802                 +cmp eax, 2
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
    // 00a3744c  7428                   -je 0xa37476
    if (cpu.flags.zf)
    {
        goto L_0x00a37476;
    }
    // 00a3744e  83f803                 +cmp eax, 3
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
    // 00a37451  7423                   -je 0xa37476
    if (cpu.flags.zf)
    {
        goto L_0x00a37476;
    }
    // 00a37453  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00a37455  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37457  881594e0a300           -mov byte ptr [0xa3e094], dl
    *app->getMemory<x86::reg8>(x86::reg32(10739860) /* 0xa3e094 */) = cpu.dl;
    // 00a3745d  ff1520cea300           -call dword ptr [0xa3ce20]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10735136) /* 0xa3ce20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37463  803d94e0a30000         +cmp byte ptr [0xa3e094], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10739860) /* 0xa3e094 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3746a  7404                   -je 0xa37470
    if (cpu.flags.zf)
    {
        goto L_0x00a37470;
    }
    // 00a3746c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a3746e  eb2a                   -jmp 0xa3749a
    goto L_0x00a3749a;
L_0x00a37470:
    // 00a37470  43                     -inc ebx
    (cpu.ebx)++;
    // 00a37471  83fb0c                 +cmp ebx, 0xc
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
    // 00a37474  7ec0                   -jle 0xa37436
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a37436;
    }
L_0x00a37476:
    // 00a37476  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a37478  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a37479  89742404               -mov dword ptr [esp + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a3747d  897c2408               -mov dword ptr [esp + 8], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00a37481  2eff15c0a9a300         -call dword ptr cs:[0xa3a9c0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725824) /* 0xa3a9c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37488  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3748a  7409                   -je 0xa37495
    if (cpu.flags.zf)
    {
        goto L_0x00a37495;
    }
    // 00a3748c  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a3748e  2eff153ca9a300         -call dword ptr cs:[0xa3a93c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725692) /* 0xa3a93c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a37495:
    // 00a37495  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a3749a:
    // 00a3749a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a3749d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3749e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3749f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a374a0  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a374a1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a374a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a374a2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a374a3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a374a5  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a374ab  895054                 -mov dword ptr [eax + 0x54], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00a374ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a374b0  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 00a374b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a374b5  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a374bb  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a374be  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a374c0  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a374c6  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a374c9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a374cb  c74004dd72a300         -mov dword ptr [eax + 4], 0xa372dd
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10711773 /*0xa372dd*/;
    // 00a374d2  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a374d8  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a374db  648902                 -mov dword ptr fs:[edx], eax
    *app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 00a374de  680871a300             -push 0xa37108
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10711304 /*0xa37108*/;
    cpu.esp -= 4;
    // 00a374e3  2eff15aca9a300         -call dword ptr cs:[0xa3a9ac]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725804) /* 0xa3a9ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a374ea  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a374eb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a374ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a374ed(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a374ed  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a374ee  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a374f4  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a374f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a374f9  7407                   -je 0xa37502
    if (cpu.flags.zf)
    {
        goto L_0x00a37502;
    }
    // 00a374fb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a374fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a374ff  648902                 -mov dword ptr fs:[edx], eax
    *app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x00a37502:
    // 00a37502  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37508  c7405400000000         -mov dword ptr [eax + 0x54], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00a3750f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37510  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37511(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37511  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a37512  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37515  7404                   -je 0xa3751b
    if (cpu.flags.zf)
    {
        goto L_0x00a3751b;
    }
    // 00a37517  1e                     -push ds
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a37518  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a37519  ff10                   -call dword ptr [eax]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a3751b:
    // 00a3751b  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a3751c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3751d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3751d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3751e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3751f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37520  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37521  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a37522  be04d1a300             -mov esi, 0xa3d104
    cpu.esi = 10735876 /*0xa3d104*/;
    // 00a37527  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x00a37529:
    // 00a37529  b8e0d0a300             -mov eax, 0xa3d0e0
    cpu.eax = 10735840 /*0xa3d0e0*/;
    // 00a3752e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a37530  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
L_0x00a37532:
    // 00a37532  3d04d1a300             +cmp eax, 0xa3d104
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10735876 /*0xa3d104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37537  7315                   -jae 0xa3754e
    if (!cpu.flags.cf)
    {
        goto L_0x00a3754e;
    }
    // 00a37539  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3753c  740b                   -je 0xa37549
    if (cpu.flags.zf)
    {
        goto L_0x00a37549;
    }
    // 00a3753e  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a37541  38ea                   +cmp dl, ch
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
    // 00a37543  7204                   -jb 0xa37549
    if (cpu.flags.cf)
    {
        goto L_0x00a37549;
    }
    // 00a37545  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37547  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a37549:
    // 00a37549  83c006                 +add eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a3754c  ebe4                   -jmp 0xa37532
    goto L_0x00a37532;
L_0x00a3754e:
    // 00a3754e  81fb04d1a300           +cmp ebx, 0xa3d104
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10735876 /*0xa3d104*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37554  740d                   -je 0xa37563
    if (cpu.flags.zf)
    {
        goto L_0x00a37563;
    }
    // 00a37556  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a37559  e8b3ffffff             -call 0xa37511
    cpu.esp -= 4;
    sub_a37511(app, cpu);
    if (cpu.terminate) return;
    // 00a3755e  c60302                 -mov byte ptr [ebx], 2
    *app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a37561  ebc6                   -jmp 0xa37529
    goto L_0x00a37529;
L_0x00a37563:
    // 00a37563  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a37564  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37565  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37566  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37567  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37568  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37569(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37569  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3756a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3756b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3756c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a3756d  be10d1a300             -mov esi, 0xa3d110
    cpu.esi = 10735888 /*0xa3d110*/;
    // 00a37572  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a37574  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x00a37576:
    // 00a37576  b804d1a300             -mov eax, 0xa3d104
    cpu.eax = 10735876 /*0xa3d104*/;
    // 00a3757b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a3757d  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
L_0x00a3757f:
    // 00a3757f  3d10d1a300             +cmp eax, 0xa3d110
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10735888 /*0xa3d110*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37584  7315                   -jae 0xa3759b
    if (!cpu.flags.cf)
    {
        goto L_0x00a3759b;
    }
    // 00a37586  803802                 +cmp byte ptr [eax], 2
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a37589  740b                   -je 0xa37596
    if (cpu.flags.zf)
    {
        goto L_0x00a37596;
    }
    // 00a3758b  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a3758e  38ea                   +cmp dl, ch
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
    // 00a37590  7704                   -ja 0xa37596
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a37596;
    }
    // 00a37592  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37594  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a37596:
    // 00a37596  83c006                 +add eax, 6
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a37599  ebe4                   -jmp 0xa3757f
    goto L_0x00a3757f;
L_0x00a3759b:
    // 00a3759b  81fb10d1a300           +cmp ebx, 0xa3d110
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10735888 /*0xa3d110*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a375a1  7412                   -je 0xa375b5
    if (cpu.flags.zf)
    {
        goto L_0x00a375b5;
    }
    // 00a375a3  3a7301                 +cmp dh, byte ptr [ebx + 1]
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a375a6  7208                   -jb 0xa375b0
    if (cpu.flags.cf)
    {
        goto L_0x00a375b0;
    }
    // 00a375a8  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a375ab  e861ffffff             -call 0xa37511
    cpu.esp -= 4;
    sub_a37511(app, cpu);
    if (cpu.terminate) return;
L_0x00a375b0:
    // 00a375b0  c60302                 -mov byte ptr [ebx], 2
    *app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a375b3  ebc1                   -jmp 0xa37576
    goto L_0x00a37576;
L_0x00a375b5:
    // 00a375b5  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a375b6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a375b7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a375b8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a375b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a375ba(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a375ba  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a375bb  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a375bc  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a375bd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a375bf  ff1568cca300           -call dword ptr [0xa3cc68]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734696) /* 0xa3cc68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a375c5  833dbccea30000         +cmp dword ptr [0xa3cebc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10735292) /* 0xa3cebc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a375cc  741d                   -je 0xa375eb
    if (cpu.flags.zf)
    {
        goto L_0x00a375eb;
    }
    // 00a375ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a375d0  ff15bccea300           -call dword ptr [0xa3cebc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10735292) /* 0xa3cebc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a375d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a375d8  7411                   -je 0xa375eb
    if (cpu.flags.zf)
    {
        goto L_0x00a375eb;
    }
L_0x00a375da:
    // 00a375da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a375dc  ff156ccca300           -call dword ptr [0xa3cc6c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734700) /* 0xa3cc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a375e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a375e7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a375e8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a375e9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a375ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a375eb:
    // 00a375eb  a154cca300             -mov eax, dword ptr [0xa3cc54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734676) /* 0xa3cc54 */);
    // 00a375f0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a375f2  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00a375f5  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a375f6  2eff1560a9a300         -call dword ptr cs:[0xa3a960]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725728) /* 0xa3a960 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a375fd  83f802                 +cmp eax, 2
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
    // 00a37600  74d8                   -je 0xa375da
    if (cpu.flags.zf)
    {
        goto L_0x00a375da;
    }
    // 00a37602  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37604  ff156ccca300           -call dword ptr [0xa3cc6c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734700) /* 0xa3cc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3760a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3760c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3760d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3760e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3760f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37610(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37610  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37611  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37612  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37613  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37614  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a37615  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a37616  0fa0                   -push fs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a37618  0fa8                   -push gs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a3761a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a3761b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a3761e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a37620  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37622  7405                   -je 0xa37629
    if (cpu.flags.zf)
    {
        goto L_0x00a37629;
    }
    // 00a37624  83f8d4                 +cmp eax, -0x2c
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
    // 00a37627  7607                   -jbe 0xa37630
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a37630;
    }
L_0x00a37629:
    // 00a37629  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a3762b  e9be000000             -jmp 0xa376ee
    goto L_0x00a376ee;
L_0x00a37630:
    // 00a37630  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a37633  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00a37636  83fd10                 +cmp ebp, 0x10
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
    // 00a37639  7305                   -jae 0xa37640
    if (!cpu.flags.cf)
    {
        goto L_0x00a37640;
    }
    // 00a3763b  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x00a37640:
    // 00a37640  ff1580cca300           -call dword ptr [0xa3cc80]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734720) /* 0xa3cc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37646  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a37648  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3764a  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a3764d:
    // 00a3764d  3b2d40cea300           +cmp ebp, dword ptr [0xa3ce40]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10735168) /* 0xa3ce40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37653  760c                   -jbe 0xa37661
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a37661;
    }
    // 00a37655  8b0d3ccea300           -mov ecx, dword ptr [0xa3ce3c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10735164) /* 0xa3ce3c */);
    // 00a3765b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a3765d  7510                   -jne 0xa3766f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3766f;
    }
    // 00a3765f  eb02                   -jmp 0xa37663
    goto L_0x00a37663;
L_0x00a37661:
    // 00a37661  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a37663:
    // 00a37663  890d40cea300           -mov dword ptr [0xa3ce40], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10735168) /* 0xa3ce40 */) = cpu.ecx;
    // 00a37669  8b0d38cea300           -mov ecx, dword ptr [0xa3ce38]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */);
L_0x00a3766f:
    // 00a3766f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a37671  743c                   -je 0xa376af
    if (cpu.flags.zf)
    {
        goto L_0x00a376af;
    }
    // 00a37673  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a37676  890d3ccea300           -mov dword ptr [0xa3ce3c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10735164) /* 0xa3ce3c */) = cpu.ecx;
    // 00a3767c  39fe                   +cmp esi, edi
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
    // 00a3767e  721c                   -jb 0xa3769c
    if (cpu.flags.cf)
    {
        goto L_0x00a3769c;
    }
    // 00a37680  b838cea300             -mov eax, 0xa3ce38
    cpu.eax = 10735160 /*0xa3ce38*/;
    // 00a37685  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a37687  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a3768d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a3768f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a37691  e8ea0a0000             -call 0xa38180
    cpu.esp -= 4;
    sub_a38180(app, cpu);
    if (cpu.terminate) return;
    // 00a37696  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a37698  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3769a  7542                   -jne 0xa376de
    if (!cpu.flags.zf)
    {
        goto L_0x00a376de;
    }
L_0x00a3769c:
    // 00a3769c  3b3540cea300           +cmp esi, dword ptr [0xa3ce40]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10735168) /* 0xa3ce40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a376a2  7606                   -jbe 0xa376aa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a376aa;
    }
    // 00a376a4  893540cea300           -mov dword ptr [0xa3ce40], esi
    *app->getMemory<x86::reg32>(x86::reg32(10735168) /* 0xa3ce40 */) = cpu.esi;
L_0x00a376aa:
    // 00a376aa  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a376ad  ebc0                   -jmp 0xa3766f
    goto L_0x00a3766f;
L_0x00a376af:
    // 00a376af  803c2400               +cmp byte ptr [esp], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a376b3  750b                   -jne 0xa376c0
    if (!cpu.flags.zf)
    {
        goto L_0x00a376c0;
    }
    // 00a376b5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a376b7  e8aa0d0000             -call 0xa38466
    cpu.esp -= 4;
    sub_a38466(app, cpu);
    if (cpu.terminate) return;
    // 00a376bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a376be  7515                   -jne 0xa376d5
    if (!cpu.flags.zf)
    {
        goto L_0x00a376d5;
    }
L_0x00a376c0:
    // 00a376c0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a376c2  e8fa0d0000             -call 0xa384c1
    cpu.esp -= 4;
    sub_a384c1(app, cpu);
    if (cpu.terminate) return;
    // 00a376c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a376c9  7413                   -je 0xa376de
    if (cpu.flags.zf)
    {
        goto L_0x00a376de;
    }
    // 00a376cb  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00a376cd  880c24                 -mov byte ptr [esp], cl
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 00a376d0  e978ffffff             -jmp 0xa3764d
    goto L_0x00a3764d;
L_0x00a376d5:
    // 00a376d5  c6042401               -mov byte ptr [esp], 1
    *app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 00a376d9  e96fffffff             -jmp 0xa3764d
    goto L_0x00a3764d;
L_0x00a376de:
    // 00a376de  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00a376e0  882da0e0a300           -mov byte ptr [0xa3e0a0], ch
    *app->getMemory<x86::reg8>(x86::reg32(10739872) /* 0xa3e0a0 */) = cpu.ch;
    // 00a376e6  ff1588cca300           -call dword ptr [0xa3cc88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a376ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a376ee:
    // 00a376ee  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a376f1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a376f2  0fa9                   -pop gs
    cpu.gs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a376f4  0fa1                   -pop fs
    cpu.fs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a376f6  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a376f7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a376f8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a376f9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a376fa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a376fb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a376fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a376fd(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a376fd  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a376fe  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a376ff  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37700  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37701  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a37703  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37705  0f84f1000000           -je 0xa377fc
    if (cpu.flags.zf)
    {
        goto L_0x00a377fc;
    }
    // 00a3770b  ff1580cca300           -call dword ptr [0xa3cc80]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734720) /* 0xa3cc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37711  8b0d98e0a300           -mov ecx, dword ptr [0xa3e098]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10739864) /* 0xa3e098 */);
    // 00a37717  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a37719  7440                   -je 0xa3775b
    if (cpu.flags.zf)
    {
        goto L_0x00a3775b;
    }
    // 00a3771b  39f1                   +cmp ecx, esi
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
    // 00a3771d  770c                   -ja 0xa3772b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a3772b;
    }
    // 00a3771f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a37721  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37723  39f0                   +cmp eax, esi
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
    // 00a37725  0f878b000000           -ja 0xa377b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a377b6;
    }
L_0x00a3772b:
    // 00a3772b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a3772d  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a37730  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a37732  7410                   -je 0xa37744
    if (cpu.flags.zf)
    {
        goto L_0x00a37744;
    }
    // 00a37734  39f1                   +cmp ecx, esi
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
    // 00a37736  770c                   -ja 0xa37744
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a37744;
    }
    // 00a37738  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a3773a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a3773c  39f2                   +cmp edx, esi
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
    // 00a3773e  0f8772000000           -ja 0xa377b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a377b6;
    }
L_0x00a37744:
    // 00a37744  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a37747  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a37749  7410                   -je 0xa3775b
    if (cpu.flags.zf)
    {
        goto L_0x00a3775b;
    }
    // 00a3774b  39f1                   +cmp ecx, esi
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
    // 00a3774d  770c                   -ja 0xa3775b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a3775b;
    }
    // 00a3774f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a37751  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37753  39f0                   +cmp eax, esi
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
    // 00a37755  0f875b000000           -ja 0xa377b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a377b6;
    }
L_0x00a3775b:
    // 00a3775b  8b0d3ccea300           -mov ecx, dword ptr [0xa3ce3c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10735164) /* 0xa3ce3c */);
    // 00a37761  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a37763  7434                   -je 0xa37799
    if (cpu.flags.zf)
    {
        goto L_0x00a37799;
    }
    // 00a37765  39f1                   +cmp ecx, esi
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
    // 00a37767  7708                   -ja 0xa37771
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a37771;
    }
    // 00a37769  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a3776b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a3776d  39f0                   +cmp eax, esi
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
    // 00a3776f  7745                   -ja 0xa377b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a377b6;
    }
L_0x00a37771:
    // 00a37771  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a37773  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a37776  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a37778  740c                   -je 0xa37786
    if (cpu.flags.zf)
    {
        goto L_0x00a37786;
    }
    // 00a3777a  39f1                   +cmp ecx, esi
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
    // 00a3777c  7708                   -ja 0xa37786
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a37786;
    }
    // 00a3777e  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a37780  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37782  39f2                   +cmp edx, esi
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
    // 00a37784  7730                   -ja 0xa377b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a377b6;
    }
L_0x00a37786:
    // 00a37786  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a37789  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a3778b  740c                   -je 0xa37799
    if (cpu.flags.zf)
    {
        goto L_0x00a37799;
    }
    // 00a3778d  39f1                   +cmp ecx, esi
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
    // 00a3778f  7708                   -ja 0xa37799
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a37799;
    }
    // 00a37791  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a37793  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37795  39f0                   +cmp eax, esi
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
    // 00a37797  771d                   -ja 0xa377b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a377b6;
    }
L_0x00a37799:
    // 00a37799  8b0d38cea300           -mov ecx, dword ptr [0xa3ce38]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */);
    // 00a3779f  eb0f                   -jmp 0xa377b0
    goto L_0x00a377b0;
L_0x00a377a1:
    // 00a377a1  39f1                   +cmp ecx, esi
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
    // 00a377a3  7708                   -ja 0xa377ad
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a377ad;
    }
    // 00a377a5  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a377a7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a377a9  39f0                   +cmp eax, esi
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
    // 00a377ab  7709                   -ja 0xa377b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a377b6;
    }
L_0x00a377ad:
    // 00a377ad  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x00a377b0:
    // 00a377b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a377b2  75ed                   -jne 0xa377a1
    if (!cpu.flags.zf)
    {
        goto L_0x00a377a1;
    }
    // 00a377b4  eb40                   -jmp 0xa377f6
    goto L_0x00a377f6;
L_0x00a377b6:
    // 00a377b6  b838cea300             -mov eax, 0xa3ce38
    cpu.eax = 10735160 /*0xa3ce38*/;
    // 00a377bb  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a377bd  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a377c3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a377c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a377c7  e8640a0000             -call 0xa38230
    cpu.esp -= 4;
    sub_a38230(app, cpu);
    if (cpu.terminate) return;
    // 00a377cc  8b153ccea300           -mov edx, dword ptr [0xa3ce3c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10735164) /* 0xa3ce3c */);
    // 00a377d2  890d98e0a300           -mov dword ptr [0xa3e098], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10739864) /* 0xa3e098 */) = cpu.ecx;
    // 00a377d8  39d1                   +cmp ecx, edx
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
    // 00a377da  7312                   -jae 0xa377ee
    if (!cpu.flags.cf)
    {
        goto L_0x00a377ee;
    }
    // 00a377dc  8b1d40cea300           -mov ebx, dword ptr [0xa3ce40]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10735168) /* 0xa3ce40 */);
    // 00a377e2  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a377e5  39d8                   +cmp eax, ebx
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
    // 00a377e7  7605                   -jbe 0xa377ee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a377ee;
    }
    // 00a377e9  a340cea300             -mov dword ptr [0xa3ce40], eax
    *app->getMemory<x86::reg32>(x86::reg32(10735168) /* 0xa3ce40 */) = cpu.eax;
L_0x00a377ee:
    // 00a377ee  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a377f0  8825a0e0a300           -mov byte ptr [0xa3e0a0], ah
    *app->getMemory<x86::reg8>(x86::reg32(10739872) /* 0xa3e0a0 */) = cpu.ah;
L_0x00a377f6:
    // 00a377f6  ff1588cca300           -call dword ptr [0xa3cc88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a377fc:
    // 00a377fc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a377fd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a377fe  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a377ff  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37800  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37801(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37801  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a37804  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a37806  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a37808  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a3780b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3780c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3780c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3780d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3780e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3780f  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a37812  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a37814  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a37816  ff1580cca300           -call dword ptr [0xa3cc80]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734720) /* 0xa3cc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3781c  b838cea300             -mov eax, 0xa3ce38
    cpu.eax = 10735160 /*0xa3ce38*/;
    // 00a37821  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a37823  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37825  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a37827  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 00a3782a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a3782c  e815000000             -call 0xa37846
    cpu.esp -= 4;
    sub_a37846(app, cpu);
    if (cpu.terminate) return;
    // 00a37831  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37833  0f85a8010000           -jne 0xa379e1
    if (!cpu.flags.zf)
    {
        return sub_a379e1(app, cpu);
    }
    // 00a37839  ff1588cca300           -call dword ptr [0xa3cc88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3783f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a37841  e9a3010000             -jmp 0xa379e9
    return sub_a379e9(app, cpu);
}

/* align: skip  */
void sub_a37846(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37846  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37847  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a37848  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a37849  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a3784c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3784d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a3784f  8d430b                 -lea eax, [ebx + 0xb]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(11) /* 0xb */);
    // 00a37852  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a37854  39d8                   +cmp eax, ebx
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
    // 00a37856  7307                   -jae 0xa3785f
    if (!cpu.flags.cf)
    {
        goto L_0x00a3785f;
    }
    // 00a37858  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a3785d  eb0a                   -jmp 0xa37869
    goto L_0x00a37869;
L_0x00a3785f:
    // 00a3785f  83f810                 +cmp eax, 0x10
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
    // 00a37862  7305                   -jae 0xa37869
    if (!cpu.flags.cf)
    {
        goto L_0x00a37869;
    }
    // 00a37864  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x00a37869:
    // 00a37869  8d57fc                 -lea edx, [edi - 4]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 00a3786c  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a37870  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a37872  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a37875  39d0                   +cmp eax, edx
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
    // 00a37877  0f86fc000000           -jbe 0xa37979
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a37979;
    }
    // 00a3787d  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a37881  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a37883  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00a37885:
    // 00a37885  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a37887  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a37889  83fdff                 +cmp ebp, -1
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3788c  750a                   -jne 0xa37898
    if (!cpu.flags.zf)
    {
        goto L_0x00a37898;
    }
    // 00a3788e  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00a37893  e940010000             -jmp 0xa379d8
    goto L_0x00a379d8;
L_0x00a37898:
    // 00a37898  f7c501000000           +test ebp, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & 1 /*0x1*/));
    // 00a3789e  0f85ce000000           -jne 0xa37972
    if (!cpu.flags.zf)
    {
        goto L_0x00a37972;
    }
    // 00a378a4  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a378a7  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a378ab  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a378ae  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a378b0  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a378b4  b838cea300             -mov eax, 0xa3ce38
    cpu.eax = 10735160 /*0xa3ce38*/;
    // 00a378b9  663b1424               +cmp dx, word ptr [esp]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(*app->getMemory<x86::reg16>(cpu.esp)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a378bd  751d                   -jne 0xa378dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a378dc;
    }
    // 00a378bf  8b3538cea300           -mov esi, dword ptr [0xa3ce38]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */);
    // 00a378c5  eb0f                   -jmp 0xa378d6
    goto L_0x00a378d6;
L_0x00a378c7:
    // 00a378c7  39fe                   +cmp esi, edi
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
    // 00a378c9  7708                   -ja 0xa378d3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a378d3;
    }
    // 00a378cb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a378cd  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a378cf  39f8                   +cmp eax, edi
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
    // 00a378d1  7709                   -ja 0xa378dc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a378dc;
    }
L_0x00a378d3:
    // 00a378d3  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x00a378d6:
    // 00a378d6  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a378da  75eb                   -jne 0xa378c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a378c7;
    }
L_0x00a378dc:
    // 00a378dc  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a378df  39d3                   +cmp ebx, edx
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
    // 00a378e1  7506                   -jne 0xa378e9
    if (!cpu.flags.zf)
    {
        goto L_0x00a378e9;
    }
    // 00a378e3  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a378e6  89460c                 -mov dword ptr [esi + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a378e9:
    // 00a378e9  3b29                   +cmp ebp, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a378eb  720b                   -jb 0xa378f8
    if (cpu.flags.cf)
    {
        goto L_0x00a378f8;
    }
    // 00a378ed  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a378ef  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a378f1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a378f3  83f810                 +cmp eax, 0x10
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
    // 00a378f6  7334                   -jae 0xa3792c
    if (!cpu.flags.cf)
    {
        goto L_0x00a3792c;
    }
L_0x00a378f8:
    // 00a378f8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a378fc  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a37900  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a37903  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37905  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a37909  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a3790c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a37910  0128                   -add dword ptr [eax], ebp
    (*app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a37912  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a37915  48                     -dec eax
    (cpu.eax)--;
    // 00a37916  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a37918  89461c                 -mov dword ptr [esi + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a3791b  8815a1e0a300           -mov byte ptr [0xa3e0a1], dl
    *app->getMemory<x86::reg8>(x86::reg32(10739873) /* 0xa3e0a1 */) = cpu.dl;
    // 00a37921  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a37923  39d5                   +cmp ebp, edx
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
    // 00a37925  7240                   -jb 0xa37967
    if (cpu.flags.cf)
    {
        goto L_0x00a37967;
    }
    // 00a37927  e9aa000000             -jmp 0xa379d6
    goto L_0x00a379d6;
L_0x00a3792c:
    // 00a3792c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a3792e  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a37930  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a37934  894304                 -mov dword ptr [ebx + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a37937  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a3793b  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a3793e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a37942  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a37945  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a37949  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a3794c  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a37950  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a37952  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a37954  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a37956  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a37958  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 00a3795a  893a                   -mov dword ptr [edx], edi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00a3795c  8825a1e0a300           -mov byte ptr [0xa3e0a1], ah
    *app->getMemory<x86::reg8>(x86::reg32(10739873) /* 0xa3e0a1 */) = cpu.ah;
    // 00a37962  e971000000             -jmp 0xa379d8
    goto L_0x00a379d8;
L_0x00a37967:
    // 00a37967  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37969  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a3796b  01eb                   +add ebx, ebp
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a3796d  e913ffffff             -jmp 0xa37885
    goto L_0x00a37885;
L_0x00a37972:
    // 00a37972  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a37977  eb5f                   -jmp 0xa379d8
    goto L_0x00a379d8;
L_0x00a37979:
    // 00a37979  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3797b  83fa10                 +cmp edx, 0x10
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
    // 00a3797e  7256                   -jb 0xa379d6
    if (cpu.flags.cf)
    {
        goto L_0x00a379d6;
    }
    // 00a37980  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37982  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a37986  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a37989  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a3798c  8919                   -mov dword ptr [ecx], ebx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00a3798e  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a37991  b838cea300             -mov eax, 0xa3ce38
    cpu.eax = 10735160 /*0xa3ce38*/;
    // 00a37996  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a3799a  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a3799c  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a3799e  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a379a1  6639da                 +cmp dx, bx
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a379a4  751d                   -jne 0xa379c3
    if (!cpu.flags.zf)
    {
        goto L_0x00a379c3;
    }
    // 00a379a6  8b3538cea300           -mov esi, dword ptr [0xa3ce38]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */);
    // 00a379ac  eb0f                   -jmp 0xa379bd
    goto L_0x00a379bd;
L_0x00a379ae:
    // 00a379ae  39fe                   +cmp esi, edi
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
    // 00a379b0  7708                   -ja 0xa379ba
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a379ba;
    }
    // 00a379b2  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a379b4  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a379b6  39f8                   +cmp eax, edi
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
    // 00a379b8  7709                   -ja 0xa379c3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a379c3;
    }
L_0x00a379ba:
    // 00a379ba  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x00a379bd:
    // 00a379bd  837e0800               +cmp dword ptr [esi + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a379c1  75eb                   -jne 0xa379ae
    if (!cpu.flags.zf)
    {
        goto L_0x00a379ae;
    }
L_0x00a379c3:
    // 00a379c3  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a379c6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a379ca  47                     -inc edi
    (cpu.edi)++;
    // 00a379cb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a379ce  897e18                 -mov dword ptr [esi + 0x18], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00a379d1  e827fdffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a379d6:
    // 00a379d6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a379d8:
    // 00a379d8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a379da  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a379dd  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379de  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379df  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a379e1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a379e1  ff1588cca300           -call dword ptr [0xa3cc88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a379e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a379e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a379ec  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379ed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379ee  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a379e9(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a379e9;
    // 00a379e1  ff1588cca300           -call dword ptr [0xa3cc88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a379e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_entry_0x00a379e9:
    // 00a379e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a379ec  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379ed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379ee  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a379ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a379f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a379f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a379f1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00a379f4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a379f6  e815fcffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a379fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a379fd  7407                   -je 0xa37a06
    if (cpu.flags.zf)
    {
        goto L_0x00a37a06;
    }
    // 00a379ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a37a01  e843c8ffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
L_0x00a37a06:
    // 00a37a06  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37a07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37a08(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37a08  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37a09  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37a0a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37a0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37a0d  e8b5f2ffff             -call 0xa36cc7
    cpu.esp -= 4;
    sub_a36cc7(app, cpu);
    if (cpu.terminate) return;
    // 00a37a12  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a37a14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37a16  7410                   -je 0xa37a28
    if (cpu.flags.zf)
    {
        goto L_0x00a37a28;
    }
    // 00a37a18  8b1560cca300           -mov edx, dword ptr [0xa3cc60]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a37a1e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37a1f  2eff15b8a9a300         -call dword ptr cs:[0xa3a9b8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725816) /* 0xa3a9b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37a26  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a37a28:
    // 00a37a28  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a37a2a  750f                   -jne 0xa37a3b
    if (!cpu.flags.zf)
    {
        goto L_0x00a37a3b;
    }
    // 00a37a2c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a37a31  b8ccbfa300             -mov eax, 0xa3bfcc
    cpu.eax = 10731468 /*0xa3bfcc*/;
    // 00a37a36  e8ebdaffff             -call 0xa35526
    cpu.esp -= 4;
    sub_a35526(app, cpu);
    if (cpu.terminate) return;
L_0x00a37a3b:
    // 00a37a3b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37a3d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37a3e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37a3f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37a40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37a41(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37a41  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37a42  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37a43  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37a44  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37a45  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a37a46  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a37a47  ff1590cca300           -call dword ptr [0xa3cc90]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734736) /* 0xa3cc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37a4d  2eff1554a9a300         -call dword ptr cs:[0xa3a954]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725716) /* 0xa3a954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37a54  8b1d9ce0a300           -mov ebx, dword ptr [0xa3e09c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10739868) /* 0xa3e09c */);
    // 00a37a5a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a37a5c  eb07                   -jmp 0xa37a65
    goto L_0x00a37a65;
L_0x00a37a5e:
    // 00a37a5e  3b6b04                 +cmp ebp, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37a61  7406                   -je 0xa37a69
    if (cpu.flags.zf)
    {
        goto L_0x00a37a69;
    }
    // 00a37a63  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx);
L_0x00a37a65:
    // 00a37a65  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a37a67  75f5                   -jne 0xa37a5e
    if (!cpu.flags.zf)
    {
        goto L_0x00a37a5e;
    }
L_0x00a37a69:
    // 00a37a69  837b0c00               +cmp dword ptr [ebx + 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37a6d  7425                   -je 0xa37a94
    if (cpu.flags.zf)
    {
        goto L_0x00a37a94;
    }
    // 00a37a6f  8b1544cea300           -mov edx, dword ptr [0xa3ce44]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a37a75  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a37a78  e866efffff             -call 0xa369e3
    cpu.esp -= 4;
    sub_a369e3(app, cpu);
    if (cpu.terminate) return;
    // 00a37a7d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a37a7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37a81  755e                   -jne 0xa37ae1
    if (!cpu.flags.zf)
    {
        goto L_0x00a37ae1;
    }
    // 00a37a83  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a37a88  b8f1bfa300             -mov eax, 0xa3bff1
    cpu.eax = 10731505 /*0xa3bff1*/;
    // 00a37a8d  e894daffff             -call 0xa35526
    cpu.esp -= 4;
    sub_a35526(app, cpu);
    if (cpu.terminate) return;
    // 00a37a92  eb4d                   -jmp 0xa37ae1
    goto L_0x00a37ae1;
L_0x00a37a94:
    // 00a37a94  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a37a99  8b1544cea300           -mov edx, dword ptr [0xa3ce44]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a37a9f  e84cffffff             -call 0xa379f0
    cpu.esp -= 4;
    sub_a379f0(app, cpu);
    if (cpu.terminate) return;
    // 00a37aa4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a37aa6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37aa8  750f                   -jne 0xa37ab9
    if (!cpu.flags.zf)
    {
        goto L_0x00a37ab9;
    }
    // 00a37aaa  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a37aaf  b819c0a300             -mov eax, 0xa3c019
    cpu.eax = 10731545 /*0xa3c019*/;
    // 00a37ab4  e86ddaffff             -call 0xa35526
    cpu.esp -= 4;
    sub_a35526(app, cpu);
    if (cpu.terminate) return;
L_0x00a37ab9:
    // 00a37ab9  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a37abc  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a37abe  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 00a37ac4  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a37ac5  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a37ac7  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a37ac9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a37aca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a37acc  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a37acf  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a37ad1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a37ad3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a37ad6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a37ad8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37ad9  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a37ada  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a37ae1:
    // 00a37ae1  896b08                 -mov dword ptr [ebx + 8], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00a37ae4  a144cea300             -mov eax, dword ptr [0xa3ce44]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a37ae9  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a37aea  c6455201               -mov byte ptr [ebp + 0x52], 1
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a37aee  8b3560cca300           -mov esi, dword ptr [0xa3cc60]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10734688) /* 0xa3cc60 */);
    // 00a37af4  c6455300               -mov byte ptr [ebp + 0x53], 0
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 00a37af8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37af9  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a37aff  2eff15bca9a300         -call dword ptr cs:[0xa3a9bc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725820) /* 0xa3a9bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37b06  ff1594cca300           -call dword ptr [0xa3cc94]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734740) /* 0xa3cc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37b0c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a37b0e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b0f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b10  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b11  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b12  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b13  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37b15(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37b15  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37b16  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37b17  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37b18  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a37b1a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a37b1c  ff1590cca300           -call dword ptr [0xa3cc90]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734736) /* 0xa3cc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37b22  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a37b27  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00a37b2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a37b2e  e8bdfeffff             -call 0xa379f0
    cpu.esp -= 4;
    sub_a379f0(app, cpu);
    if (cpu.terminate) return;
    // 00a37b33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a37b35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37b37  742f                   -je 0xa37b68
    if (cpu.flags.zf)
    {
        goto L_0x00a37b68;
    }
    // 00a37b39  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37b3b  e895090000             -call 0xa384d5
    cpu.esp -= 4;
    sub_a384d5(app, cpu);
    if (cpu.terminate) return;
    // 00a37b40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37b42  7409                   -je 0xa37b4d
    if (cpu.flags.zf)
    {
        goto L_0x00a37b4d;
    }
    // 00a37b44  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37b46  e8b2fbffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a37b4b  eb1b                   -jmp 0xa37b68
    goto L_0x00a37b68;
L_0x00a37b4d:
    // 00a37b4d  895a08                 -mov dword ptr [edx + 8], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a37b50  897204                 -mov dword ptr [edx + 4], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a37b53  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 00a37b56  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a37b59  a19ce0a300             -mov eax, dword ptr [0xa3e09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10739868) /* 0xa3e09c */);
    // 00a37b5e  89159ce0a300           -mov dword ptr [0xa3e09c], edx
    *app->getMemory<x86::reg32>(x86::reg32(10739868) /* 0xa3e09c */) = cpu.edx;
    // 00a37b64  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a37b66  eb02                   -jmp 0xa37b6a
    goto L_0x00a37b6a;
L_0x00a37b68:
    // 00a37b68  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a37b6a:
    // 00a37b6a  ff1594cca300           -call dword ptr [0xa3cc94]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734740) /* 0xa3cc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37b70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a37b72  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b73  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b74  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37b75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37b76(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37b76  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37b77  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37b78  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37b79  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a37b7b  ff1590cca300           -call dword ptr [0xa3cc90]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734736) /* 0xa3cc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37b81  bb9ce0a300             -mov ebx, 0xa3e09c
    cpu.ebx = 10739868 /*0xa3e09c*/;
    // 00a37b86  8b159ce0a300           -mov edx, dword ptr [0xa3e09c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739868) /* 0xa3e09c */);
    // 00a37b8c  eb24                   -jmp 0xa37bb2
    goto L_0x00a37bb2;
L_0x00a37b8e:
    // 00a37b8e  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37b91  751b                   -jne 0xa37bae
    if (!cpu.flags.zf)
    {
        goto L_0x00a37bae;
    }
    // 00a37b93  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37b97  7408                   -je 0xa37ba1
    if (cpu.flags.zf)
    {
        goto L_0x00a37ba1;
    }
    // 00a37b99  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a37b9c  e85cfbffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a37ba1:
    // 00a37ba1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a37ba3  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a37ba5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37ba7  e851fbffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a37bac  eb08                   -jmp 0xa37bb6
    goto L_0x00a37bb6;
L_0x00a37bae:
    // 00a37bae  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a37bb0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
L_0x00a37bb2:
    // 00a37bb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a37bb4  75d8                   -jne 0xa37b8e
    if (!cpu.flags.zf)
    {
        goto L_0x00a37b8e;
    }
L_0x00a37bb6:
    // 00a37bb6  ff1594cca300           -call dword ptr [0xa3cc94]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734740) /* 0xa3cc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37bbc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37bbd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37bbe  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37bbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37bbc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a37bbc;
    // 00a37b76  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37b77  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37b78  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37b79  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a37b7b  ff1590cca300           -call dword ptr [0xa3cc90]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734736) /* 0xa3cc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37b81  bb9ce0a300             -mov ebx, 0xa3e09c
    cpu.ebx = 10739868 /*0xa3e09c*/;
    // 00a37b86  8b159ce0a300           -mov edx, dword ptr [0xa3e09c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739868) /* 0xa3e09c */);
    // 00a37b8c  eb24                   -jmp 0xa37bb2
    goto L_0x00a37bb2;
L_0x00a37b8e:
    // 00a37b8e  3b4a04                 +cmp ecx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37b91  751b                   -jne 0xa37bae
    if (!cpu.flags.zf)
    {
        goto L_0x00a37bae;
    }
    // 00a37b93  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37b97  7408                   -je 0xa37ba1
    if (cpu.flags.zf)
    {
        goto L_0x00a37ba1;
    }
    // 00a37b99  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a37b9c  e85cfbffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a37ba1:
    // 00a37ba1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a37ba3  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a37ba5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37ba7  e851fbffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a37bac  eb08                   -jmp 0xa37bb6
    goto L_0x00a37bb6;
L_0x00a37bae:
    // 00a37bae  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a37bb0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
L_0x00a37bb2:
    // 00a37bb2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a37bb4  75d8                   -jne 0xa37b8e
    if (!cpu.flags.zf)
    {
        goto L_0x00a37b8e;
    }
L_0x00a37bb6:
    // 00a37bb6  ff1594cca300           -call dword ptr [0xa3cc94]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734740) /* 0xa3cc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x00a37bbc:
    // 00a37bbc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37bbd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37bbe  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37bbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37bc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37bc0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37bc1  ff1590cca300           -call dword ptr [0xa3cc90]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734736) /* 0xa3cc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37bc7  a19ce0a300             -mov eax, dword ptr [0xa3e09c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10739868) /* 0xa3e09c */);
L_0x00a37bcc:
    // 00a37bcc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37bce  740b                   -je 0xa37bdb
    if (cpu.flags.zf)
    {
        goto L_0x00a37bdb;
    }
    // 00a37bd0  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a37bd3  c6425301               -mov byte ptr [edx + 0x53], 1
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 00a37bd7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a37bd9  ebf1                   -jmp 0xa37bcc
    goto L_0x00a37bcc;
L_0x00a37bdb:
    // 00a37bdb  ff1594cca300           -call dword ptr [0xa3cc94]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734740) /* 0xa3cc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37be1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37be2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37be3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37be3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37be4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37be5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37be6  8b159ce0a300           -mov edx, dword ptr [0xa3e09c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739868) /* 0xa3e09c */);
L_0x00a37bec:
    // 00a37bec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a37bee  74cc                   -je 0xa37bbc
    if (cpu.flags.zf)
    {
        return sub_a37bbc(app, cpu);
    }
    // 00a37bf0  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a37bf3  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a37bf5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a37bf7  7408                   -je 0xa37c01
    if (cpu.flags.zf)
    {
        goto L_0x00a37c01;
    }
    // 00a37bf9  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a37bfc  e8fcfaffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a37c01:
    // 00a37c01  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37c03  e8f5faffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a37c08  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a37c0a  ebe0                   -jmp 0xa37bec
    goto L_0x00a37bec;
}

/* align: skip  */
void sub_a37c0c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37c0c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37c0d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37c0e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37c10  ff1590cca300           -call dword ptr [0xa3cc90]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734736) /* 0xa3cc90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37c16  8b1544cea300           -mov edx, dword ptr [0xa3ce44]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a37c1c  8d041a                 -lea eax, [edx + ebx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a37c1f  a344cea300             -mov dword ptr [0xa3ce44], eax
    *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */) = cpu.eax;
    // 00a37c24  e897ffffff             -call 0xa37bc0
    cpu.esp -= 4;
    sub_a37bc0(app, cpu);
    if (cpu.terminate) return;
    // 00a37c29  ff1594cca300           -call dword ptr [0xa3cc94]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734740) /* 0xa3cc94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37c2f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37c31  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37c32  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37c33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37c34(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37c34  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37c35  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37c36  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37c37  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37c39  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37c3b  741b                   -je 0xa37c58
    if (cpu.flags.zf)
    {
        goto L_0x00a37c58;
    }
    // 00a37c3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a37c3f  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00a37c46  e8cff3ffff             -call 0xa3701a
    cpu.esp -= 4;
    sub_a3701a(app, cpu);
    if (cpu.terminate) return;
    // 00a37c4b  2eff1554a9a300         -call dword ptr cs:[0xa3a954]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725716) /* 0xa3a954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37c52  8983da000000           -mov dword ptr [ebx + 0xda], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x00a37c58:
    // 00a37c58  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37c59  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37c5a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37c5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37c5c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37c5c  e982ffffff             -jmp 0xa37be3
    return sub_a37be3(app, cpu);
}

/* align: skip  */
void sub_a37c61(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37c61  e9aaf9ffff             -jmp 0xa37610
    return sub_a37610(app, cpu);
}

/* align: skip  */
void sub_a37c66(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37c66  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37c67  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37c68  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37c69  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37c6a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a37c6b  833d88e0a30000         +cmp dword ptr [0xa3e088], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37c72  0f85a5000000           -jne 0xa37d1d
    if (!cpu.flags.zf)
    {
        goto L_0x00a37d1d;
    }
    // 00a37c78  8b3d19cba300           -mov edi, dword ptr [0xa3cb19]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10734361) /* 0xa3cb19 */);
    // 00a37c7e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37c80  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a37c82  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a37c84:
    // 00a37c84  3a10                   +cmp dl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a37c86  7412                   -je 0xa37c9a
    if (cpu.flags.zf)
    {
        goto L_0x00a37c9a;
    }
L_0x00a37c88:
    // 00a37c88  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a37c8a  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a37c8d  38f2                   +cmp dl, dh
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
    // 00a37c8f  7404                   -je 0xa37c95
    if (cpu.flags.zf)
    {
        goto L_0x00a37c95;
    }
    // 00a37c91  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37c93  ebf3                   -jmp 0xa37c88
    goto L_0x00a37c88;
L_0x00a37c95:
    // 00a37c95  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a37c96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37c98  ebea                   -jmp 0xa37c84
    goto L_0x00a37c84;
L_0x00a37c9a:
    // 00a37c9a  29f8                   +sub eax, edi
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
    // 00a37c9c  7505                   -jne 0xa37ca3
    if (!cpu.flags.zf)
    {
        goto L_0x00a37ca3;
    }
    // 00a37c9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a37ca3:
    // 00a37ca3  e868f9ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a37ca8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a37caa  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37cac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37cae  7468                   -je 0xa37d18
    if (cpu.flags.zf)
    {
        goto L_0x00a37d18;
    }
    // 00a37cb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a37cb2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a37cb5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a37cb8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37cba  e851f9ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a37cbf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37cc1  744e                   -je 0xa37d11
    if (cpu.flags.zf)
    {
        goto L_0x00a37d11;
    }
    // 00a37cc3  a388e0a300             -mov dword ptr [0xa3e088], eax
    *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */) = cpu.eax;
    // 00a37cc8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a37cca  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37ccc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a37cce:
    // 00a37cce  803800                 +cmp byte ptr [eax], 0
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
    // 00a37cd1  7419                   -je 0xa37cec
    if (cpu.flags.zf)
    {
        goto L_0x00a37cec;
    }
    // 00a37cd3  8b1588e0a300           -mov edx, dword ptr [0xa3e088]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a37cd9  891c11                 -mov dword ptr [ecx + edx], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x00a37cdc:
    // 00a37cdc  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a37cde  40                     -inc eax
    (cpu.eax)++;
    // 00a37cdf  8813                   -mov byte ptr [ebx], dl
    *app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 00a37ce1  43                     -inc ebx
    (cpu.ebx)++;
    // 00a37ce2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a37ce4  75f6                   -jne 0xa37cdc
    if (!cpu.flags.zf)
    {
        goto L_0x00a37cdc;
    }
    // 00a37ce6  83c104                 +add ecx, 4
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
    // 00a37ce9  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a37cea  ebe2                   -jmp 0xa37cce
    goto L_0x00a37cce;
L_0x00a37cec:
    // 00a37cec  8b1588e0a300           -mov edx, dword ptr [0xa3e088]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a37cf2  c7041100000000         -mov dword ptr [ecx + edx], 0
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 00a37cf9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a37cfc  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a37cfe  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a37d00  891584e0a300           -mov dword ptr [0xa3e084], edx
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.edx;
    // 00a37d06  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37d08  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a37d0a  e83ac5ffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a37d0f  eb07                   -jmp 0xa37d18
    goto L_0x00a37d18;
L_0x00a37d11:
    // 00a37d11  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37d13  e8e5f9ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a37d18:
    // 00a37d18  e8fe070000             -call 0xa3851b
    cpu.esp -= 4;
    sub_a3851b(app, cpu);
    if (cpu.terminate) return;
L_0x00a37d1d:
    // 00a37d1d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d1e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d1f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d20  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d21  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37d23(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37d23  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37d24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a37d26:
    // 00a37d26  66833800               +cmp word ptr [eax], 0
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
    // 00a37d2a  7404                   -je 0xa37d30
    if (cpu.flags.zf)
    {
        goto L_0x00a37d30;
    }
    // 00a37d2c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a37d2d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a37d2e  ebf6                   -jmp 0xa37d26
    goto L_0x00a37d26;
L_0x00a37d30:
    // 00a37d30  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a37d32  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a37d34  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37d36(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37d36  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37d37  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a37d38  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a37d39  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a37d3b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a37d3d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a37d3f  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a37d40  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a37d42  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a37d44  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a37d45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a37d47  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a37d4a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a37d4c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a37d4e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a37d51  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a37d53  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d54  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a37d55  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a37d57  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d58  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d59  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37d5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37d5b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37d5b  66833801               +cmp word ptr [eax], 1
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a37d5f  751c                   -jne 0xa37d7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a37d7d;
    }
    // 00a37d61  83780400               +cmp dword ptr [eax + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37d65  7416                   -je 0xa37d7d
    if (cpu.flags.zf)
    {
        goto L_0x00a37d7d;
    }
    // 00a37d67  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00a37d6b  663d1000               +cmp ax, 0x10
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
    // 00a37d6f  7206                   -jb 0xa37d77
    if (cpu.flags.cf)
    {
        goto L_0x00a37d77;
    }
    // 00a37d71  663d1200               +cmp ax, 0x12
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
    // 00a37d75  7606                   -jbe 0xa37d7d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a37d7d;
    }
L_0x00a37d77:
    // 00a37d77  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a37d7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a37d7d:
    // 00a37d7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37d7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37d80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37d80  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37d81  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37d82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37d84  ff1568cca300           -call dword ptr [0xa3cc68]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734696) /* 0xa3cc68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37d8a  833d48cea300ff         +cmp dword ptr [0xa3ce48], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10735176) /* 0xa3ce48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37d91  7523                   -jne 0xa37db6
    if (!cpu.flags.zf)
    {
        goto L_0x00a37db6;
    }
    // 00a37d93  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a37d95  6880000000             -push 0x80
    *app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a37d9a  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a37d9c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a37d9e  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a37da0  6800000080             -push 0x80000000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 00a37da5  6844c0a300             -push 0xa3c044
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731588 /*0xa3c044*/;
    cpu.esp -= 4;
    // 00a37daa  2eff152ca9a300         -call dword ptr cs:[0xa3a92c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725676) /* 0xa3a92c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37db1  a348cea300             -mov dword ptr [0xa3ce48], eax
    *app->getMemory<x86::reg32>(x86::reg32(10735176) /* 0xa3ce48 */) = cpu.eax;
L_0x00a37db6:
    // 00a37db6  833d4ccea300ff         +cmp dword ptr [0xa3ce4c], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10735180) /* 0xa3ce4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a37dbd  7523                   -jne 0xa37de2
    if (!cpu.flags.zf)
    {
        goto L_0x00a37de2;
    }
    // 00a37dbf  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a37dc1  6880000000             -push 0x80
    *app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a37dc6  6a03                   -push 3
    *app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a37dc8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a37dca  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a37dcc  6800000040             -push 0x40000000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00a37dd1  684bc0a300             -push 0xa3c04b
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10731595 /*0xa3c04b*/;
    cpu.esp -= 4;
    // 00a37dd6  2eff152ca9a300         -call dword ptr cs:[0xa3a92c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725676) /* 0xa3a92c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37ddd  a34ccea300             -mov dword ptr [0xa3ce4c], eax
    *app->getMemory<x86::reg32>(x86::reg32(10735180) /* 0xa3ce4c */) = cpu.eax;
L_0x00a37de2:
    // 00a37de2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37de4  ff156ccca300           -call dword ptr [0xa3cc6c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734700) /* 0xa3cc6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37dea  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37deb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37dec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37ded(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37ded  e88effffff             -call 0xa37d80
    cpu.esp -= 4;
    sub_a37d80(app, cpu);
    if (cpu.terminate) return;
    // 00a37df2  a148cea300             -mov eax, dword ptr [0xa3ce48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735176) /* 0xa3ce48 */);
    // 00a37df7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37df8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37df8  e883ffffff             -call 0xa37d80
    cpu.esp -= 4;
    sub_a37d80(app, cpu);
    if (cpu.terminate) return;
    // 00a37dfd  a14ccea300             -mov eax, dword ptr [0xa3ce4c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735180) /* 0xa3ce4c */);
    // 00a37e02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37e03(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37e03  dbe2                   -fnclex 
    /*nothing*/;
    // 00a37e05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37e06(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37e06  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37e07  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37e08  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37e0a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a37e0c  83f807                 +cmp eax, 7
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
    // 00a37e0f  7405                   -je 0xa37e16
    if (cpu.flags.zf)
    {
        goto L_0x00a37e16;
    }
    // 00a37e11  83f804                 +cmp eax, 4
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
    // 00a37e14  7513                   -jne 0xa37e29
    if (!cpu.flags.zf)
    {
        goto L_0x00a37e29;
    }
L_0x00a37e16:
    // 00a37e16  8b14dd50cea300         -mov edx, dword ptr [ebx*8 + 0xa3ce50]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10735184) /* 0xa3ce50 */ + cpu.ebx * 8);
    // 00a37e1d  890cdd50cea300         -mov dword ptr [ebx*8 + 0xa3ce50], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10735184) /* 0xa3ce50 */ + cpu.ebx * 8) = cpu.ecx;
    // 00a37e24  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37e26  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e27  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a37e29:
    // 00a37e29  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37e2f  8b54d858               -mov edx, dword ptr [eax + ebx*8 + 0x58]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.ebx * 8);
    // 00a37e33  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37e39  894cd858               -mov dword ptr [eax + ebx*8 + 0x58], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.ebx * 8) = cpu.ecx;
    // 00a37e3d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37e3f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e40  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37e42(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37e42  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37e43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a37e45  83f807                 +cmp eax, 7
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
    // 00a37e48  7405                   -je 0xa37e4f
    if (cpu.flags.zf)
    {
        goto L_0x00a37e4f;
    }
    // 00a37e4a  83f804                 +cmp eax, 4
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
    // 00a37e4d  7509                   -jne 0xa37e58
    if (!cpu.flags.zf)
    {
        goto L_0x00a37e58;
    }
L_0x00a37e4f:
    // 00a37e4f  8b04d550cea300         -mov eax, dword ptr [edx*8 + 0xa3ce50]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735184) /* 0xa3ce50 */ + cpu.edx * 8);
    // 00a37e56  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a37e58:
    // 00a37e58  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37e5e  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 00a37e62  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37e64(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37e64  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37e65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a37e67  83f807                 +cmp eax, 7
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
    // 00a37e6a  7405                   -je 0xa37e71
    if (cpu.flags.zf)
    {
        goto L_0x00a37e71;
    }
    // 00a37e6c  83f804                 +cmp eax, 4
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
    // 00a37e6f  7509                   -jne 0xa37e7a
    if (!cpu.flags.zf)
    {
        goto L_0x00a37e7a;
    }
L_0x00a37e71:
    // 00a37e71  8b04d554cea300         -mov eax, dword ptr [edx*8 + 0xa3ce54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735188) /* 0xa3ce54 */ + cpu.edx * 8);
    // 00a37e78  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a37e7a:
    // 00a37e7a  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37e80  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 00a37e84  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37e86(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37e86  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37e87  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37e89  e8d6ffffff             -call 0xa37e64
    cpu.esp -= 4;
    sub_a37e64(app, cpu);
    if (cpu.terminate) return;
    // 00a37e8e  39c2                   +cmp edx, eax
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
    // 00a37e90  7509                   -jne 0xa37e9b
    if (!cpu.flags.zf)
    {
        goto L_0x00a37e9b;
    }
    // 00a37e92  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a37e94  e8a9ffffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37e99  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e9a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a37e9b:
    // 00a37e9b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37e9d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37e9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37e9f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37e9f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a37ea3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37ea5  760a                   -jbe 0xa37eb1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a37eb1;
    }
    // 00a37ea7  83f801                 +cmp eax, 1
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
    // 00a37eaa  7424                   -je 0xa37ed0
    if (cpu.flags.zf)
    {
        goto L_0x00a37ed0;
    }
    // 00a37eac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37eae  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a37eb1:
    // 00a37eb1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a37eb6  e887ffffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37ebb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a37ebd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37ebf  7503                   -jne 0xa37ec4
    if (!cpu.flags.zf)
    {
        goto L_0x00a37ec4;
    }
    // 00a37ec1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a37ec4:
    // 00a37ec4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x00a37ec9:
    // 00a37ec9  e8d5000000             -call 0xa37fa3
    cpu.esp -= 4;
    sub_a37fa3(app, cpu);
    if (cpu.terminate) return;
    // 00a37ece  eb1f                   -jmp 0xa37eef
    goto L_0x00a37eef;
L_0x00a37ed0:
    // 00a37ed0  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a37ed5  e868ffffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37eda  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a37edc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37ede  7503                   -jne 0xa37ee3
    if (!cpu.flags.zf)
    {
        goto L_0x00a37ee3;
    }
    // 00a37ee0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a37ee3:
    // 00a37ee3  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a37ee8  ebdf                   -jmp 0xa37ec9
    goto L_0x00a37ec9;
L_0x00a37eea:
    // 00a37eea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37eec  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a37eef:
    // 00a37eef  83fa02                 +cmp edx, 2
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
    // 00a37ef2  74f6                   -je 0xa37eea
    if (cpu.flags.zf)
    {
        goto L_0x00a37eea;
    }
    // 00a37ef4  83fa03                 +cmp edx, 3
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
    // 00a37ef7  74f1                   -je 0xa37eea
    if (cpu.flags.zf)
    {
        goto L_0x00a37eea;
    }
    // 00a37ef9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a37efe  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a37f01(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37f01  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37f02  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a37f07  e836ffffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37f0c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a37f0e  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a37f13  e82affffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37f18  83fa02                 +cmp edx, 2
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
    // 00a37f1b  7405                   -je 0xa37f22
    if (cpu.flags.zf)
    {
        goto L_0x00a37f22;
    }
    // 00a37f1d  83fa03                 +cmp edx, 3
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
    // 00a37f20  750a                   -jne 0xa37f2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a37f2c;
    }
L_0x00a37f22:
    // 00a37f22  83f802                 +cmp eax, 2
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
    // 00a37f25  740c                   -je 0xa37f33
    if (cpu.flags.zf)
    {
        goto L_0x00a37f33;
    }
    // 00a37f27  83f803                 +cmp eax, 3
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
    // 00a37f2a  7407                   -je 0xa37f33
    if (cpu.flags.zf)
    {
        goto L_0x00a37f33;
    }
L_0x00a37f2c:
    // 00a37f2c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a37f31  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37f32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a37f33:
    // 00a37f33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37f35  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37f36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37f37(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37f37  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37f38  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37f39  803db8cea30000         +cmp byte ptr [0xa3ceb8], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10735288) /* 0xa3ceb8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a37f40  7519                   -jne 0xa37f5b
    if (!cpu.flags.zf)
    {
        goto L_0x00a37f5b;
    }
    // 00a37f42  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a37f44  689f7ea300             -push 0xa37e9f
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10714783 /*0xa37e9f*/;
    cpu.esp -= 4;
    // 00a37f49  2eff1594a9a300         -call dword ptr cs:[0xa3a994]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725780) /* 0xa3a994 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37f50  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37f52  7407                   -je 0xa37f5b
    if (cpu.flags.zf)
    {
        goto L_0x00a37f5b;
    }
    // 00a37f54  c605b8cea30001         -mov byte ptr [0xa3ceb8], 1
    *app->getMemory<x86::reg8>(x86::reg32(10735288) /* 0xa3ceb8 */) = 1 /*0x1*/;
L_0x00a37f5b:
    // 00a37f5b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37f5d  a0b8cea300             -mov al, byte ptr [0xa3ceb8]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(10735288) /* 0xa3ceb8 */);
    // 00a37f62  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37f63  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37f64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37f65(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37f65  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37f66  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37f67  803db8cea30000         +cmp byte ptr [0xa3ceb8], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10735288) /* 0xa3ceb8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a37f6e  741a                   -je 0xa37f8a
    if (cpu.flags.zf)
    {
        goto L_0x00a37f8a;
    }
    // 00a37f70  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a37f72  689f7ea300             -push 0xa37e9f
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10714783 /*0xa37e9f*/;
    cpu.esp -= 4;
    // 00a37f77  2eff1594a9a300         -call dword ptr cs:[0xa3a994]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725780) /* 0xa3a994 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a37f7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37f80  7408                   -je 0xa37f8a
    if (cpu.flags.zf)
    {
        goto L_0x00a37f8a;
    }
    // 00a37f82  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a37f84  8815b8cea300           -mov byte ptr [0xa3ceb8], dl
    *app->getMemory<x86::reg8>(x86::reg32(10735288) /* 0xa3ceb8 */) = cpu.dl;
L_0x00a37f8a:
    // 00a37f8a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a37f8c  a0b8cea300             -mov al, byte ptr [0xa3ceb8]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(10735288) /* 0xa3ceb8 */);
    // 00a37f91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a37f93  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a37f96  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a37f9b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37f9c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37f9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37f9e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37f9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a37fa3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37fa4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37fa5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37fa6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37fa8  e895feffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37fad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a37faf  83fb02                 +cmp ebx, 2
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
    // 00a37fb2  0f82db000000           -jb 0xa38093
    if (cpu.flags.cf)
    {
        return sub_a38093(app, cpu);
    }
    // 00a37fb8  0f86df000000           -jbe 0xa3809d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a3809d(app, cpu);
    }
    // 00a37fbe  83fb0c                 +cmp ebx, 0xc
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
    // 00a37fc1  0f86ec000000           -jbe 0xa380b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a380b3(app, cpu);
    }
    // 00a37fc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a37fcc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fcd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fce  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37fc7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a37fc7;
    // 00a37f9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a37fa3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37fa4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37fa5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37fa6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37fa8  e895feffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37fad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a37faf  83fb02                 +cmp ebx, 2
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
    // 00a37fb2  0f82db000000           -jb 0xa38093
    if (cpu.flags.cf)
    {
        return sub_a38093(app, cpu);
    }
    // 00a37fb8  0f86df000000           -jbe 0xa3809d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a3809d(app, cpu);
    }
    // 00a37fbe  83fb0c                 +cmp ebx, 0xc
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
    // 00a37fc1  0f86ec000000           -jbe 0xa380b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a380b3(app, cpu);
    }
L_entry_0x00a37fc7:
    // 00a37fc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a37fcc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fcd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fce  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37fa3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a37fa3;
    // 00a37f9e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_entry_0x00a37fa3:
    // 00a37fa3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37fa4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37fa5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37fa6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37fa8  e895feffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37fad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a37faf  83fb02                 +cmp ebx, 2
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
    // 00a37fb2  0f82db000000           -jb 0xa38093
    if (cpu.flags.cf)
    {
        return sub_a38093(app, cpu);
    }
    // 00a37fb8  0f86df000000           -jbe 0xa3809d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a3809d(app, cpu);
    }
    // 00a37fbe  83fb0c                 +cmp ebx, 0xc
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
    // 00a37fc1  0f86ec000000           -jbe 0xa380b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        return sub_a380b3(app, cpu);
    }
    // 00a37fc7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a37fcc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fcd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fce  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a37fcf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a37fd0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a37fd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a37fd1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a37fd2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a37fd3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a37fd5  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a37fda  e863feffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a37fdf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a37fe1  83f801                 +cmp eax, 1
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
    // 00a37fe4  7425                   -je 0xa3800b
    if (cpu.flags.zf)
    {
        goto L_0x00a3800b;
    }
    // 00a37fe6  83f802                 +cmp eax, 2
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
    // 00a37fe9  7420                   -je 0xa3800b
    if (cpu.flags.zf)
    {
        goto L_0x00a3800b;
    }
    // 00a37feb  83f803                 +cmp eax, 3
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
    // 00a37fee  741b                   -je 0xa3800b
    if (cpu.flags.zf)
    {
        goto L_0x00a3800b;
    }
    // 00a37ff0  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a37ff5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a37ff7  e80afeffff             -call 0xa37e06
    cpu.esp -= 4;
    sub_a37e06(app, cpu);
    if (cpu.terminate) return;
    // 00a37ffc  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a38001  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a38003  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38005  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38007  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38008  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38009  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3800a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a3800b:
    // 00a3800b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a38010  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38011  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38012  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38013  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38014(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38014  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38015  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38016  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38017  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38019  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a3801b  83f801                 +cmp eax, 1
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
    // 00a3801e  7c05                   -jl 0xa38025
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a38025;
    }
    // 00a38020  83f80c                 +cmp eax, 0xc
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
    // 00a38023  7e13                   -jle 0xa38038
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a38038;
    }
L_0x00a38025:
    // 00a38025  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a3802a  e804e9ffff             -call 0xa36933
    cpu.esp -= 4;
    sub_a36933(app, cpu);
    if (cpu.terminate) return;
    // 00a3802f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a38034  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38035  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38036  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38037  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a38038:
    // 00a38038  c7050ccfa3009e7fa300   -mov dword ptr [0xa3cf0c], 0xa37f9e
    *app->getMemory<x86::reg32>(x86::reg32(10735372) /* 0xa3cf0c */) = 10715038 /*0xa37f9e*/;
    // 00a38042  83f902                 +cmp ecx, 2
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
    // 00a38045  741f                   -je 0xa38066
    if (cpu.flags.zf)
    {
        goto L_0x00a38066;
    }
    // 00a38047  83f903                 +cmp ecx, 3
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
    // 00a3804a  741a                   -je 0xa38066
    if (cpu.flags.zf)
    {
        goto L_0x00a38066;
    }
    // 00a3804c  e813feffff             -call 0xa37e64
    cpu.esp -= 4;
    sub_a37e64(app, cpu);
    if (cpu.terminate) return;
    // 00a38051  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38053  7411                   -je 0xa38066
    if (cpu.flags.zf)
    {
        goto L_0x00a38066;
    }
    // 00a38055  83fb02                 +cmp ebx, 2
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
    // 00a38058  750c                   -jne 0xa38066
    if (!cpu.flags.zf)
    {
        goto L_0x00a38066;
    }
    // 00a3805a  ba9f000000             -mov edx, 0x9f
    cpu.edx = 159 /*0x9f*/;
    // 00a3805f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38061  e8ed050000             -call 0xa38653
    cpu.esp -= 4;
    sub_a38653(app, cpu);
    if (cpu.terminate) return;
L_0x00a38066:
    // 00a38066  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38068  e8d5fdffff             -call 0xa37e42
    cpu.esp -= 4;
    sub_a37e42(app, cpu);
    if (cpu.terminate) return;
    // 00a3806d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a3806f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a38071  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38073  e88efdffff             -call 0xa37e06
    cpu.esp -= 4;
    sub_a37e06(app, cpu);
    if (cpu.terminate) return;
    // 00a38078  e884feffff             -call 0xa37f01
    cpu.esp -= 4;
    sub_a37f01(app, cpu);
    if (cpu.terminate) return;
    // 00a3807d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3807f  7407                   -je 0xa38088
    if (cpu.flags.zf)
    {
        goto L_0x00a38088;
    }
    // 00a38081  e8b1feffff             -call 0xa37f37
    cpu.esp -= 4;
    sub_a37f37(app, cpu);
    if (cpu.terminate) return;
    // 00a38086  eb05                   -jmp 0xa3808d
    goto L_0x00a3808d;
L_0x00a38088:
    // 00a38088  e8d8feffff             -call 0xa37f65
    cpu.esp -= 4;
    sub_a37f65(app, cpu);
    if (cpu.terminate) return;
L_0x00a3808d:
    // 00a3808d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a3808f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38090  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38091  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38092  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38093(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38093  83fb01                 +cmp ebx, 1
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
    // 00a38096  7411                   -je 0xa380a9
    if (cpu.flags.zf)
    {
        goto L_0x00a380a9;
    }
    // 00a38098  e92affffff             -jmp 0xa37fc7
    return sub_a37fc7(app, cpu);
    // 00a3809d  b88c000000             -mov eax, 0x8c
    cpu.eax = 140 /*0x8c*/;
    // 00a380a2  e829ffffff             -call 0xa37fd0
    cpu.esp -= 4;
    sub_a37fd0(app, cpu);
    if (cpu.terminate) return;
    // 00a380a7  eb37                   -jmp 0xa380e0
    goto L_0x00a380e0;
L_0x00a380a9:
    // 00a380a9  83f802                 +cmp eax, 2
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
    // 00a380ac  7505                   -jne 0xa380b3
    if (!cpu.flags.zf)
    {
        goto L_0x00a380b3;
    }
    // 00a380ae  e88e050000             -call 0xa38641
    cpu.esp -= 4;
    sub_a38641(app, cpu);
    if (cpu.terminate) return;
L_0x00a380b3:
    // 00a380b3  83f901                 +cmp ecx, 1
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
    // 00a380b6  741a                   -je 0xa380d2
    if (cpu.flags.zf)
    {
        goto L_0x00a380d2;
    }
    // 00a380b8  83f902                 +cmp ecx, 2
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
    // 00a380bb  7415                   -je 0xa380d2
    if (cpu.flags.zf)
    {
        goto L_0x00a380d2;
    }
    // 00a380bd  83f903                 +cmp ecx, 3
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
    // 00a380c0  7410                   -je 0xa380d2
    if (cpu.flags.zf)
    {
        goto L_0x00a380d2;
    }
    // 00a380c2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a380c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a380c9  e838fdffff             -call 0xa37e06
    cpu.esp -= 4;
    sub_a37e06(app, cpu);
    if (cpu.terminate) return;
    // 00a380ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a380d0  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a380d2:
    // 00a380d2  e82afeffff             -call 0xa37f01
    cpu.esp -= 4;
    sub_a37f01(app, cpu);
    if (cpu.terminate) return;
    // 00a380d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a380d9  7505                   -jne 0xa380e0
    if (!cpu.flags.zf)
    {
        goto L_0x00a380e0;
    }
    // 00a380db  e885feffff             -call 0xa37f65
    cpu.esp -= 4;
    sub_a37f65(app, cpu);
    if (cpu.terminate) return;
L_0x00a380e0:
    // 00a380e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a380e2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a380e3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a380e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a380e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
