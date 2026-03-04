#include "voodoo2a.h"
#include <lib/thread.h>

namespace voodoo2a
{

/* align: skip  */
void sub_a8c946(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8c946  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8c947  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c948  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8c94a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8c94c  81fa00100000           +cmp edx, 0x1000
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
    // 00a8c952  7e12                   -jle 0xa8c966
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8c966;
    }
    // 00a8c954  ba00100000             -mov edx, 0x1000
    cpu.edx = 4096 /*0x1000*/;
    // 00a8c959  e867ffffff             -call 0xa8c8c5
    cpu.esp -= 4;
    sub_a8c8c5(app, cpu);
    if (cpu.terminate) return;
    // 00a8c95e  81eb00100000           +sub ebx, 0x1000
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
    // 00a8c964  eb18                   -jmp 0xa8c97e
    goto L_0x00a8c97e;
L_0x00a8c966:
    // 00a8c966  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 00a8c96c  7d10                   -jge 0xa8c97e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8c97e;
    }
    // 00a8c96e  ba00f0ffff             -mov edx, 0xfffff000
    cpu.edx = 4294963200 /*0xfffff000*/;
    // 00a8c973  e84dffffff             -call 0xa8c8c5
    cpu.esp -= 4;
    sub_a8c8c5(app, cpu);
    if (cpu.terminate) return;
    // 00a8c978  81c300100000           -add ebx, 0x1000
    (cpu.ebx) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
L_0x00a8c97e:
    // 00a8c97e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8c980  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8c982  e83effffff             -call 0xa8c8c5
    cpu.esp -= 4;
    sub_a8c8c5(app, cpu);
    if (cpu.terminate) return;
    // 00a8c987  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c988  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c989  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8c9a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a8c9a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8c9a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8c9a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c9a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c9a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c9a6  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a8c9ac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8c9ae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8c9b0  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a8c9b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8c9b5  9b                     -wait 
    /*nothing*/;
    // 00a8c9b6  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a8c9b9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c9ba  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a8c9bd  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a8c9c0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a8c9c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8c9c6  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8c9c9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c9ca  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a8c9d1  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a8c9d5  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 00a8c9d9  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00a8c9dc  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00a8c9df  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00a8c9e1  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00a8c9e4  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 00a8c9e8  7407                   -je 0xa8c9f1
    if (cpu.flags.zf)
    {
        goto L_0x00a8c9f1;
    }
    // 00a8c9ea  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x00a8c9f1:
    // 00a8c9f1  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a8c9f5  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00a8c9fc  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a8ca03  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a8ca0a  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8ca0d  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a8ca14  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8ca16  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a8ca1d  e8881f0000             -call 0xa8e9aa
    cpu.esp -= 4;
    sub_a8e9aa(app, cpu);
    if (cpu.terminate) return;
    // 00a8ca22  83f804                 +cmp eax, 4
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
    // 00a8ca25  0f8749010000           -ja 0xa8cb74
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8cb74;
    }
    // 00a8ca2b  2eff24858cc9a800       -jmp dword ptr cs:[eax*4 + 0xa8c98c]
    cpu.ip = app->getMemory<x86::reg32>(11061644 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a8ca33:
    // 00a8ca33  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a8ca3a:
    // 00a8ca3a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8ca3c  e933010000             -jmp 0xa8cb74
    goto L_0x00a8cb74;
  case 0x00a8ca41:
    // 00a8ca41  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8ca44  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 00a8ca47  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 00a8ca4b  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x00a8ca4f:
    // 00a8ca4f  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 00a8ca53  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 00a8ca5a  e970030000             -jmp 0xa8cdcf
    return sub_a8cdcf(app, cpu);
  case 0x00a8ca5f:
    // 00a8ca5f  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8ca62  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 00a8ca65  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 00a8ca69  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 00a8ca6d  ebe0                   -jmp 0xa8ca4f
    goto L_0x00a8ca4f;
  case 0x00a8ca6f:
    // 00a8ca6f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ca71  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8ca75  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 00a8ca7b  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 00a8ca81  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 00a8ca86  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8ca88  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a8ca8b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a8ca8d  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a8ca90  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8ca92  0f84dc000000           -je 0xa8cb74
    if (cpu.flags.zf)
    {
        goto L_0x00a8cb74;
    }
    // 00a8ca98  7d0f                   -jge 0xa8caa9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8caa9;
    }
    // 00a8ca9a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a8ca9c  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a8ca9f  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a8caa2  f7d9                   +neg ecx
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
    // 00a8caa4  e9bf000000             -jmp 0xa8cb68
    goto L_0x00a8cb68;
L_0x00a8caa9:
    // 00a8caa9  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8caac  6681fa1940             +cmp dx, 0x4019
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
    // 00a8cab1  7287                   -jb 0xa8ca3a
    if (cpu.flags.cf)
    {
        goto L_0x00a8ca3a;
    }
    // 00a8cab3  750d                   -jne 0xa8cac2
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cac2;
    }
    // 00a8cab5  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
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
    // 00a8cabc  0f8278ffffff           -jb 0xa8ca3a
    if (cpu.flags.cf)
    {
        goto L_0x00a8ca3a;
    }
L_0x00a8cac2:
    // 00a8cac2  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8cac5  663d3440               +cmp ax, 0x4034
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
    // 00a8cac9  7220                   -jb 0xa8caeb
    if (cpu.flags.cf)
    {
        goto L_0x00a8caeb;
    }
    // 00a8cacb  0f8594000000           -jne 0xa8cb65
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cb65;
    }
    // 00a8cad1  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a8cad4  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
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
    // 00a8cada  720f                   -jb 0xa8caeb
    if (cpu.flags.cf)
    {
        goto L_0x00a8caeb;
    }
    // 00a8cadc  0f8583000000           -jne 0xa8cb65
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cb65;
    }
    // 00a8cae2  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
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
    // 00a8cae9  737a                   -jae 0xa8cb65
    if (!cpu.flags.cf)
    {
        goto L_0x00a8cb65;
    }
L_0x00a8caeb:
    // 00a8caeb  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 00a8caf0  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8caf3  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8caf6  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 00a8cafa  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a8caff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8cb01  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 00a8cb04  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a8cb07  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 00a8cb0a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cb0c  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cb0e  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cb10  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cb12  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a8cb15  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a8cb18  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8cb1b  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cb1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb1f  9b                     -wait 
    /*nothing*/;
    // 00a8cb20  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a8cb23  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb25  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00a8cb28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb29  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cb2c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb2d  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a8cb31  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cb34  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb35  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb36  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8cb38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb39  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a8cb3c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb3d  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cb3f  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8cb42  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a8cb45  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cb47  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cb49  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cb4b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cb4d  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cb50  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8cb53  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cb56  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00a8cb5b  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cb5d  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cb5f  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cb61  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cb63  eb0f                   -jmp 0xa8cb74
    goto L_0x00a8cb74;
L_0x00a8cb65:
    // 00a8cb65  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x00a8cb68:
    // 00a8cb68  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8cb6a  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cb6d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a8cb6f  e8d2fdffff             -call 0xa8c946
    cpu.esp -= 4;
    sub_a8c946(app, cpu);
    if (cpu.terminate) return;
L_0x00a8cb74:
    // 00a8cb74  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00a8cb78  7416                   -je 0xa8cb90
    if (cpu.flags.zf)
    {
        goto L_0x00a8cb90;
    }
    // 00a8cb7a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8cb7c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8cb7e  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a8cb81  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a8cb84  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a8cb87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8cb89  7e0d                   -jle 0xa8cb98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cb98;
    }
    // 00a8cb8b  0145e8                 +add dword ptr [ebp - 0x18], eax
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
    // 00a8cb8e  eb08                   -jmp 0xa8cb98
    goto L_0x00a8cb98;
L_0x00a8cb90:
    // 00a8cb90  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8cb92  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a8cb95  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a8cb98:
    // 00a8cb98  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8cb9b  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a8cba0  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a8cba3  7405                   -je 0xa8cbaa
    if (cpu.flags.zf)
    {
        goto L_0x00a8cbaa;
    }
    // 00a8cba5  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x00a8cbaa:
    // 00a8cbaa  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a8cbae  7402                   -je 0xa8cbb2
    if (cpu.flags.zf)
    {
        goto L_0x00a8cbb2;
    }
    // 00a8cbb0  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8cbb2:
    // 00a8cbb2  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8cbb5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8cbb8  39d8                   +cmp eax, ebx
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
    // 00a8cbba  7d03                   -jge 0xa8cbbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8cbbf;
    }
    // 00a8cbbc  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a8cbbf:
    // 00a8cbbf  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 00a8cbc6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a8cbc8  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 00a8cbce  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a8cbd4  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00a8cbd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8cbd9  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 00a8cbdc  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8cbdf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8cbe1  0f8ee8000000           -jle 0xa8cccf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_a8cccf(app, cpu);
    }
    // 00a8cbe7  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00a8cbea  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a8cbed  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8cbef  7572                   -jne 0xa8cc63
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cc63;
    }
    // 00a8cbf1  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 00a8cbf7  0f84d2000000           -je 0xa8cccf
    if (cpu.flags.zf)
    {
        return sub_a8cccf(app, cpu);
    }
    // 00a8cbfd  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc00  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cc02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc04  9b                     -wait 
    /*nothing*/;
    // 00a8cc05  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a8cc08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc0a  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00a8cc0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc0e  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cc11  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc12  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a8cc16  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cc19  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc1a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc1b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8cc1d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8cc1f  7e42                   -jle 0xa8cc63
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cc63;
    }
    // 00a8cc21  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a8cc24  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc28  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a8cc2b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc2c  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cc2e  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a8cc31  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc34  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cc36  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cc38  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cc3a  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cc3c  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 00a8cc41  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a8cc46  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a8cc49  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 00a8cc4d  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 00a8cc50  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8cc52  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc55  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a8cc58  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc5b  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cc5d  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cc5f  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cc61  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a8cc63:
    // 00a8cc63  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a8cc66  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8cc68  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8cc6b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8cc6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cc6d  e802000000             -call 0xa8cc74
    cpu.esp -= 4;
    sub_a8cc74(app, cpu);
    if (cpu.terminate) return;
    // 00a8cc72  eb45                   -jmp 0xa8ccb9
    return sub_a8ccb9(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a8cbdc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    goto L_entry_0x00a8cbdc;
    // 00a8c9a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8c9a1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8c9a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8c9a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8c9a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8c9a6  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00a8c9ac  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8c9ae  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8c9b0  895de0                 -mov dword ptr [ebp - 0x20], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a8c9b3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8c9b5  9b                     -wait 
    /*nothing*/;
    // 00a8c9b6  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a8c9b9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c9ba  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a8c9bd  80cc03                 -or ah, 3
    cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a8c9c0  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a8c9c5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8c9c6  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8c9c9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8c9ca  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a8c9d1  668b4708               -mov ax, word ptr [edi + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a8c9d5  668945d4               -mov word ptr [ebp - 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.ax;
    // 00a8c9d9  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00a8c9dc  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 00a8c9df  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00a8c9e1  8945cc                 -mov dword ptr [ebp - 0x34], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.eax;
    // 00a8c9e4  f645d580               +test byte ptr [ebp - 0x2b], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) & 128 /*0x80*/));
    // 00a8c9e8  7407                   -je 0xa8c9f1
    if (cpu.flags.zf)
    {
        goto L_0x00a8c9f1;
    }
    // 00a8c9ea  c74214ffffffff         -mov dword ptr [edx + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
L_0x00a8c9f1:
    // 00a8c9f1  8065d57f               -and byte ptr [ebp - 0x2b], 0x7f
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-43) /* -0x2b */) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a8c9f5  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00a8c9fc  c7462000000000         -mov dword ptr [esi + 0x20], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a8ca03  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a8ca0a  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8ca0d  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a8ca14  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8ca16  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00a8ca1d  e8881f0000             -call 0xa8e9aa
    cpu.esp -= 4;
    sub_a8e9aa(app, cpu);
    if (cpu.terminate) return;
    // 00a8ca22  83f804                 +cmp eax, 4
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
    // 00a8ca25  0f8749010000           -ja 0xa8cb74
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8cb74;
    }
    // 00a8ca2b  2eff24858cc9a800       -jmp dword ptr cs:[eax*4 + 0xa8c98c]
    cpu.ip = app->getMemory<x86::reg32>(11061644 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a8ca33:
    // 00a8ca33  c7461400000000         -mov dword ptr [esi + 0x14], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
L_0x00a8ca3a:
    // 00a8ca3a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8ca3c  e933010000             -jmp 0xa8cb74
    goto L_0x00a8cb74;
  case 0x00a8ca41:
    // 00a8ca41  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8ca44  c6006e                 -mov byte ptr [eax], 0x6e
    app->getMemory<x86::reg8>(cpu.eax) = 110 /*0x6e*/;
    // 00a8ca47  c6400161               -mov byte ptr [eax + 1], 0x61
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 97 /*0x61*/;
    // 00a8ca4b  c640026e               -mov byte ptr [eax + 2], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 110 /*0x6e*/;
L_0x00a8ca4f:
    // 00a8ca4f  c6400300               -mov byte ptr [eax + 3], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 00a8ca53  c7461c03000000         -mov dword ptr [esi + 0x1c], 3
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 3 /*0x3*/;
    // 00a8ca5a  e970030000             -jmp 0xa8cdcf
    return sub_a8cdcf(app, cpu);
  case 0x00a8ca5f:
    // 00a8ca5f  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8ca62  c60069                 -mov byte ptr [eax], 0x69
    app->getMemory<x86::reg8>(cpu.eax) = 105 /*0x69*/;
    // 00a8ca65  c640016e               -mov byte ptr [eax + 1], 0x6e
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 110 /*0x6e*/;
    // 00a8ca69  c6400266               -mov byte ptr [eax + 2], 0x66
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = 102 /*0x66*/;
    // 00a8ca6d  ebe0                   -jmp 0xa8ca4f
    goto L_0x00a8ca4f;
  case 0x00a8ca6f:
    // 00a8ca6f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ca71  668b4dd4               -mov cx, word ptr [ebp - 0x2c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8ca75  81e9fe3f0000           -sub ecx, 0x3ffe
    (cpu.ecx) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 00a8ca7b  69d197750000           -imul edx, ecx, 0x7597
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(30103 /*0x7597*/)));
    // 00a8ca81  bba0860100             -mov ebx, 0x186a0
    cpu.ebx = 100000 /*0x186a0*/;
    // 00a8ca86  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8ca88  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a8ca8b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a8ca8d  8d48fc                 -lea ecx, [eax - 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a8ca90  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8ca92  0f84dc000000           -je 0xa8cb74
    if (cpu.flags.zf)
    {
        goto L_0x00a8cb74;
    }
    // 00a8ca98  7d0f                   -jge 0xa8caa9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8caa9;
    }
    // 00a8ca9a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a8ca9c  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a8ca9f  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a8caa2  f7d9                   +neg ecx
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
    // 00a8caa4  e9bf000000             -jmp 0xa8cb68
    goto L_0x00a8cb68;
L_0x00a8caa9:
    // 00a8caa9  8b55d4                 -mov edx, dword ptr [ebp - 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8caac  6681fa1940             +cmp dx, 0x4019
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
    // 00a8cab1  7287                   -jb 0xa8ca3a
    if (cpu.flags.cf)
    {
        goto L_0x00a8ca3a;
    }
    // 00a8cab3  750d                   -jne 0xa8cac2
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cac2;
    }
    // 00a8cab5  817dd00020bcbe         +cmp dword ptr [ebp - 0x30], 0xbebc2000
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
    // 00a8cabc  0f8278ffffff           -jb 0xa8ca3a
    if (cpu.flags.cf)
    {
        goto L_0x00a8ca3a;
    }
L_0x00a8cac2:
    // 00a8cac2  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8cac5  663d3440               +cmp ax, 0x4034
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
    // 00a8cac9  7220                   -jb 0xa8caeb
    if (cpu.flags.cf)
    {
        goto L_0x00a8caeb;
    }
    // 00a8cacb  0f8594000000           -jne 0xa8cb65
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cb65;
    }
    // 00a8cad1  8b5dd0                 -mov ebx, dword ptr [ebp - 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a8cad4  81fbbfc91b8e           +cmp ebx, 0x8e1bc9bf
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
    // 00a8cada  720f                   -jb 0xa8caeb
    if (cpu.flags.cf)
    {
        goto L_0x00a8caeb;
    }
    // 00a8cadc  0f8583000000           -jne 0xa8cb65
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cb65;
    }
    // 00a8cae2  817dcc00000004         +cmp dword ptr [ebp - 0x34], 0x4000000
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
    // 00a8cae9  737a                   -jae 0xa8cb65
    if (!cpu.flags.cf)
    {
        goto L_0x00a8cb65;
    }
L_0x00a8caeb:
    // 00a8caeb  bb19400000             -mov ebx, 0x4019
    cpu.ebx = 16409 /*0x4019*/;
    // 00a8caf0  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8caf3  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8caf6  66895dbc               -mov word ptr [ebp - 0x44], bx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.bx;
    // 00a8cafa  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a8caff  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8cb01  895db8                 -mov dword ptr [ebp - 0x48], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.ebx;
    // 00a8cb04  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a8cb07  894db4                 -mov dword ptr [ebp - 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ecx;
    // 00a8cb0a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cb0c  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cb0e  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cb10  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cb12  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a8cb15  8d55a8                 -lea edx, [ebp - 0x58]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a8cb18  8d5db4                 -lea ebx, [ebp - 0x4c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8cb1b  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cb1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb1f  9b                     -wait 
    /*nothing*/;
    // 00a8cb20  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a8cb23  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb25  80cc0c                 +or ah, 0xc
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/))));
    // 00a8cb28  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb29  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cb2c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb2d  db5c2404               +fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a8cb31  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cb34  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb35  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb36  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8cb38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cb39  db0424                 +fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a8cb3c  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cb3d  db3a                   +fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cb3f  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8cb42  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00a8cb45  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cb47  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cb49  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cb4b  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cb4d  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cb50  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a8cb53  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cb56  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00a8cb5b  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cb5d  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cb5f  dee9                   +fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cb61  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cb63  eb0f                   -jmp 0xa8cb74
    goto L_0x00a8cb74;
L_0x00a8cb65:
    // 00a8cb65  80e1fc                 -and cl, 0xfc
    cpu.cl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
L_0x00a8cb68:
    // 00a8cb68  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8cb6a  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cb6d  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a8cb6f  e8d2fdffff             -call 0xa8c946
    cpu.esp -= 4;
    sub_a8c946(app, cpu);
    if (cpu.terminate) return;
L_0x00a8cb74:
    // 00a8cb74  f6460802               +test byte ptr [esi + 8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 2 /*0x2*/));
    // 00a8cb78  7416                   -je 0xa8cb90
    if (cpu.flags.zf)
    {
        goto L_0x00a8cb90;
    }
    // 00a8cb7a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8cb7c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8cb7e  83c00a                 -add eax, 0xa
    (cpu.eax) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00a8cb81  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a8cb84  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a8cb87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8cb89  7e0d                   -jle 0xa8cb98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cb98;
    }
    // 00a8cb8b  0145e8                 +add dword ptr [ebp - 0x18], eax
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
    // 00a8cb8e  eb08                   -jmp 0xa8cb98
    goto L_0x00a8cb98;
L_0x00a8cb90:
    // 00a8cb90  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8cb92  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a8cb95  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a8cb98:
    // 00a8cb98  8a5e08                 -mov bl, byte ptr [esi + 8]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8cb9b  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a8cba0  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a8cba3  7405                   -je 0xa8cbaa
    if (cpu.flags.zf)
    {
        goto L_0x00a8cbaa;
    }
    // 00a8cba5  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
L_0x00a8cbaa:
    // 00a8cbaa  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a8cbae  7402                   -je 0xa8cbb2
    if (cpu.flags.zf)
    {
        goto L_0x00a8cbb2;
    }
    // 00a8cbb0  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8cbb2:
    // 00a8cbb2  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8cbb5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8cbb8  39d8                   +cmp eax, ebx
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
    // 00a8cbba  7d03                   -jge 0xa8cbbf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8cbbf;
    }
    // 00a8cbbc  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a8cbbf:
    // 00a8cbbf  c68568ffffff30         -mov byte ptr [ebp - 0x98], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = 48 /*0x30*/;
    // 00a8cbc6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a8cbc8  88a569ffffff           -mov byte ptr [ebp - 0x97], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-151) /* -0x97 */) = cpu.ah;
    // 00a8cbce  8d8569ffffff           -lea eax, [ebp - 0x97]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a8cbd4  8945d8                 -mov dword ptr [ebp - 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.eax;
    // 00a8cbd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8cbd9  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
L_entry_0x00a8cbdc:
    // 00a8cbdc  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8cbdf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8cbe1  0f8ee8000000           -jle 0xa8cccf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_a8cccf(app, cpu);
    }
    // 00a8cbe7  8d5af8                 -lea ebx, [edx - 8]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00a8cbea  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a8cbed  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8cbef  7572                   -jne 0xa8cc63
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cc63;
    }
    // 00a8cbf1  66f745d4ff7f           +test word ptr [ebp - 0x2c], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-44) /* -0x2c */) & 32767 /*0x7fff*/));
    // 00a8cbf7  0f84d2000000           -je 0xa8cccf
    if (cpu.flags.zf)
    {
        return sub_a8cccf(app, cpu);
    }
    // 00a8cbfd  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc00  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cc02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc04  9b                     -wait 
    /*nothing*/;
    // 00a8cc05  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a8cc08  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc0a  80cc0c                 -or ah, 0xc
    cpu.ah |= x86::reg8(x86::sreg8(12 /*0xc*/));
    // 00a8cc0d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc0e  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cc11  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc12  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00a8cc16  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cc19  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc1a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc1b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8cc1d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8cc1f  7e42                   -jle 0xa8cc63
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cc63;
    }
    // 00a8cc21  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a8cc24  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cc28  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a8cc2b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc2c  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cc2e  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a8cc31  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc34  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cc36  db2a                   -fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cc38  dee9                   -fsubp st(1)
    cpu.fpu.st(1) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cc3a  db3b                   -fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8cc3c  b819400000             -mov eax, 0x4019
    cpu.eax = 16409 /*0x4019*/;
    // 00a8cc41  bb0020bcbe             -mov ebx, 0xbebc2000
    cpu.ebx = 3200000000 /*0xbebc2000*/;
    // 00a8cc46  8d55c0                 -lea edx, [ebp - 0x40]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a8cc49  668945c8               -mov word ptr [ebp - 0x38], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.ax;
    // 00a8cc4d  895dc4                 -mov dword ptr [ebp - 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.ebx;
    // 00a8cc50  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8cc52  8d5dcc                 -lea ebx, [ebp - 0x34]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc55  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a8cc58  8d45cc                 -lea eax, [ebp - 0x34]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00a8cc5b  db28                   +fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8cc5d  db2a                   +fld xword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.edx)));
    // 00a8cc5f  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a8cc61  db3b                   +fstp xword ptr [ebx]
    app->getMemory<x86::IEEEf80>(cpu.ebx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00a8cc63:
    // 00a8cc63  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a8cc66  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8cc68  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8cc6b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8cc6c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cc6d  e802000000             -call 0xa8cc74
    cpu.esp -= 4;
    sub_a8cc74(app, cpu);
    if (cpu.terminate) return;
    // 00a8cc72  eb45                   -jmp 0xa8ccb9
    return sub_a8ccb9(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a8cc74(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8cc74  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a8cc79  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cc7b  39c8                   +cmp eax, ecx
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
    // 00a8cc7d  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc7e  7203                   -jb 0xa8cc83
    if (cpu.flags.cf)
    {
        goto L_0x00a8cc83;
    }
    // 00a8cc80  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc81  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a8cc83:
    // 00a8cc83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cc84  e801000000             -call 0xa8cc8a
    cpu.esp -= 4;
    sub_a8cc8a(app, cpu);
    if (cpu.terminate) return;
    // 00a8cc89  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc8a  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a8cc8f  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cc91  39c8                   +cmp eax, ecx
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
    // 00a8cc93  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc94  7204                   -jb 0xa8cc9a
    if (cpu.flags.cf)
    {
        goto L_0x00a8cc9a;
    }
    // 00a8cc96  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc97  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a8cc9a:
    // 00a8cc9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cc9b  e801000000             -call 0xa8cca1
    cpu.esp -= 4;
    sub_a8cca1(app, cpu);
    if (cpu.terminate) return;
    // 00a8cca0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cca1  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a8cca3  38c8                   +cmp al, cl
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
    // 00a8cca5  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a8cca7  7204                   -jb 0xa8ccad
    if (cpu.flags.cf)
    {
        goto L_0x00a8ccad;
    }
    // 00a8cca9  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a8ccab  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a8ccad:
    // 00a8ccad  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8ccb0  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8ccb2  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a8ccb4  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8ccb5  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a8ccb7  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8ccb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8cca1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8cca1;
    // 00a8cc74  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a8cc79  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cc7b  39c8                   +cmp eax, ecx
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
    // 00a8cc7d  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc7e  7203                   -jb 0xa8cc83
    if (cpu.flags.cf)
    {
        goto L_0x00a8cc83;
    }
    // 00a8cc80  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc81  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a8cc83:
    // 00a8cc83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cc84  e801000000             -call 0xa8cc8a
    cpu.esp -= 4;
    sub_a8cc8a(app, cpu);
    if (cpu.terminate) return;
    // 00a8cc89  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cc8a  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a8cc8f  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cc91  39c8                   +cmp eax, ecx
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
    // 00a8cc93  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc94  7204                   -jb 0xa8cc9a
    if (cpu.flags.cf)
    {
        goto L_0x00a8cc9a;
    }
    // 00a8cc96  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc97  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a8cc9a:
    // 00a8cc9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cc9b  e801000000             -call 0xa8cca1
    cpu.esp -= 4;
    sub_a8cca1(app, cpu);
    if (cpu.terminate) return;
    // 00a8cca0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00a8cca1:
    // 00a8cca1  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a8cca3  38c8                   +cmp al, cl
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
    // 00a8cca5  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a8cca7  7204                   -jb 0xa8ccad
    if (cpu.flags.cf)
    {
        goto L_0x00a8ccad;
    }
    // 00a8cca9  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a8ccab  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a8ccad:
    // 00a8ccad  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8ccb0  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8ccb2  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a8ccb4  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8ccb5  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a8ccb7  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8ccb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8cc8a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8cc8a;
    // 00a8cc74  b910270000             -mov ecx, 0x2710
    cpu.ecx = 10000 /*0x2710*/;
    // 00a8cc79  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cc7b  39c8                   +cmp eax, ecx
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
    // 00a8cc7d  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc7e  7203                   -jb 0xa8cc83
    if (cpu.flags.cf)
    {
        goto L_0x00a8cc83;
    }
    // 00a8cc80  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc81  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a8cc83:
    // 00a8cc83  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cc84  e801000000             -call 0xa8cc8a
    cpu.esp -= 4;
    sub_a8cc8a(app, cpu);
    if (cpu.terminate) return;
    // 00a8cc89  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00a8cc8a:
    // 00a8cc8a  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a8cc8f  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cc91  39c8                   +cmp eax, ecx
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
    // 00a8cc93  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc94  7204                   -jb 0xa8cc9a
    if (cpu.flags.cf)
    {
        goto L_0x00a8cc9a;
    }
    // 00a8cc96  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8cc97  66f7f1                 -div cx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.cx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
L_0x00a8cc9a:
    // 00a8cc9a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cc9b  e801000000             -call 0xa8cca1
    cpu.esp -= 4;
    sub_a8cca1(app, cpu);
    if (cpu.terminate) return;
    // 00a8cca0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cca1  b10a                   -mov cl, 0xa
    cpu.cl = 10 /*0xa*/;
    // 00a8cca3  38c8                   +cmp al, cl
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
    // 00a8cca5  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a8cca7  7204                   -jb 0xa8ccad
    if (cpu.flags.cf)
    {
        goto L_0x00a8ccad;
    }
    // 00a8cca9  86c4                   -xchg ah, al
    {
        x86::reg8 tmp = cpu.ah;
        cpu.ah = cpu.al;
        cpu.al = tmp;
    }
    // 00a8ccab  f6f1                   -div cl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.cl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
L_0x00a8ccad:
    // 00a8ccad  80c430                 -add ah, 0x30
    (cpu.ah) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8ccb0  0430                   -add al, 0x30
    (cpu.al) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8ccb2  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a8ccb4  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8ccb5  8823                   -mov byte ptr [ebx], ah
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.ah;
    // 00a8ccb7  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8ccb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8ccb9(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ccb9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ccba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ccbb  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a8ccbd  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a8ccbf  895dd8                 -mov dword ptr [ebp - 0x28], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.ebx;
    // 00a8ccc2  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8ccc5  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a8ccc7  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 00a8ccca  e90dffffff             -jmp 0xa8cbdc
    return sub_a8cbdc(app, cpu);
}

/* align: skip  */
void sub_a8cccf(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8cccf  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8ccd2  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a8ccd8  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00a8ccdb:
    // 00a8ccdb  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8ccde  7505                   -jne 0xa8cce5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cce5;
    }
    // 00a8cce0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8cce1  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8cce2  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8cce3  ebf6                   -jmp 0xa8ccdb
    goto L_0x00a8ccdb;
L_0x00a8cce5:
    // 00a8cce5  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8cce8  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8ccea  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00a8cced  740a                   -je 0xa8ccf9
    if (cpu.flags.zf)
    {
        goto L_0x00a8ccf9;
    }
    // 00a8ccef  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00a8ccf2  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a8ccf5  01df                   +add edi, ebx
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
    // 00a8ccf7  eb15                   -jmp 0xa8cd0e
    goto L_0x00a8cd0e;
L_0x00a8ccf9:
    // 00a8ccf9  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00a8ccfc  7410                   -je 0xa8cd0e
    if (cpu.flags.zf)
    {
        goto L_0x00a8cd0e;
    }
    // 00a8ccfe  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a8cd01  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8cd03  7e03                   -jle 0xa8cd08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cd08;
    }
    // 00a8cd05  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8cd06  eb02                   -jmp 0xa8cd0a
    goto L_0x00a8cd0a;
L_0x00a8cd08:
    // 00a8cd08  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8cd0a:
    // 00a8cd0a  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8cd0b  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x00a8cd0e:
    // 00a8cd0e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8cd10  0f8c65000000           -jl 0xa8cd7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8cd7b;
    }
    // 00a8cd16  39c7                   +cmp edi, eax
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
    // 00a8cd18  7e02                   -jle 0xa8cd1c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cd1c;
    }
    // 00a8cd1a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00a8cd1c:
    // 00a8cd1c  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00a8cd21  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 00a8cd25  7405                   -je 0xa8cd2c
    if (cpu.flags.zf)
    {
        goto L_0x00a8cd2c;
    }
    // 00a8cd27  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x00a8cd2c:
    // 00a8cd2c  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a8cd30  7402                   -je 0xa8cd34
    if (cpu.flags.zf)
    {
        goto L_0x00a8cd34;
    }
    // 00a8cd32  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8cd34:
    // 00a8cd34  39df                   +cmp edi, ebx
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
    // 00a8cd36  7e03                   -jle 0xa8cd3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cd3b;
    }
    // 00a8cd38  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x00a8cd3b:
    // 00a8cd3b  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 00a8cd3f  39f8                   +cmp eax, edi
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
    // 00a8cd41  7e0a                   -jle 0xa8cd4d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cd4d;
    }
    // 00a8cd43  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8cd47  7204                   -jb 0xa8cd4d
    if (cpu.flags.cf)
    {
        goto L_0x00a8cd4d;
    }
    // 00a8cd49  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x00a8cd4d:
    // 00a8cd4d  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a8cd50  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x00a8cd53:
    // 00a8cd53  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8cd56  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a8cd57  48                     -dec eax
    (cpu.eax)--;
    // 00a8cd58  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00a8cd5b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8cd5d  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cd60  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8cd62  7503                   -jne 0xa8cd67
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cd67;
    }
    // 00a8cd64  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8cd65  ebec                   -jmp 0xa8cd53
    goto L_0x00a8cd53;
L_0x00a8cd67:
    // 00a8cd67  80ff39                 +cmp bh, 0x39
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8cd6a  7506                   -jne 0xa8cd72
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cd72;
    }
    // 00a8cd6c  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00a8cd6e  fec7                   -inc bh
    (cpu.bh)++;
    // 00a8cd70  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x00a8cd72:
    // 00a8cd72  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 00a8cd76  7d03                   -jge 0xa8cd7b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8cd7b;
    }
    // 00a8cd78  4a                     -dec edx
    (cpu.edx)--;
    // 00a8cd79  47                     -inc edi
    (cpu.edi)++;
    // 00a8cd7a  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a8cd7b:
    // 00a8cd7b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8cd7d  7f18                   -jg 0xa8cd97
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8cd97;
    }
    // 00a8cd7f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a8cd84  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 00a8cd86  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8cd88  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 00a8cd8e  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 00a8cd94  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a8cd97:
    // 00a8cd97  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8cd9a  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a8cd9d  7514                   -jne 0xa8cdb3
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cdb3;
    }
    // 00a8cd9f  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a8cda2  741e                   -je 0xa8cdc2
    if (cpu.flags.zf)
    {
        goto L_0x00a8cdc2;
    }
    // 00a8cda4  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8cda7  7c04                   -jl 0xa8cdad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8cdad;
    }
    // 00a8cda9  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8cdab  7c06                   -jl 0xa8cdb3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8cdb3;
    }
L_0x00a8cdad:
    // 00a8cdad  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a8cdb1  740f                   -je 0xa8cdc2
    if (cpu.flags.zf)
    {
        goto L_0x00a8cdc2;
    }
L_0x00a8cdb3:
    // 00a8cdb3  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8cdb6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8cdb7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8cdb9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a8cdbb  e822000000             -call 0xa8cde2
    cpu.esp -= 4;
    sub_a8cde2(app, cpu);
    if (cpu.terminate) return;
    // 00a8cdc0  eb0d                   -jmp 0xa8cdcf
    goto L_0x00a8cdcf;
L_0x00a8cdc2:
    // 00a8cdc2  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8cdc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cdc6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a8cdc8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8cdca  e831020000             -call 0xa8d000
    cpu.esp -= 4;
    sub_a8d000(app, cpu);
    if (cpu.terminate) return;
L_0x00a8cdcf:
    // 00a8cdcf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8cdd1  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cdd5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cdd6  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cdd9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cdda  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cddd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cdde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cddf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cde0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cde1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8cdcf(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8cdcf;
    // 00a8cccf  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8ccd2  8d9569ffffff           -lea edx, [ebp - 0x97]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-151) /* -0x97 */);
    // 00a8ccd8  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x00a8ccdb:
    // 00a8ccdb  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8ccde  7505                   -jne 0xa8cce5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cce5;
    }
    // 00a8cce0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8cce1  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8cce2  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8cce3  ebf6                   -jmp 0xa8ccdb
    goto L_0x00a8ccdb;
L_0x00a8cce5:
    // 00a8cce5  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8cce8  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8ccea  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00a8cced  740a                   -je 0xa8ccf9
    if (cpu.flags.zf)
    {
        goto L_0x00a8ccf9;
    }
    // 00a8ccef  034e04                 -add ecx, dword ptr [esi + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00a8ccf2  8d5901                 -lea ebx, [ecx + 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a8ccf5  01df                   +add edi, ebx
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
    // 00a8ccf7  eb15                   -jmp 0xa8cd0e
    goto L_0x00a8cd0e;
L_0x00a8ccf9:
    // 00a8ccf9  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00a8ccfc  7410                   -je 0xa8cd0e
    if (cpu.flags.zf)
    {
        goto L_0x00a8cd0e;
    }
    // 00a8ccfe  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a8cd01  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8cd03  7e03                   -jle 0xa8cd08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cd08;
    }
    // 00a8cd05  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8cd06  eb02                   -jmp 0xa8cd0a
    goto L_0x00a8cd0a;
L_0x00a8cd08:
    // 00a8cd08  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8cd0a:
    // 00a8cd0a  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8cd0b  2b4e04                 -sub ecx, dword ptr [esi + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
L_0x00a8cd0e:
    // 00a8cd0e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8cd10  0f8c65000000           -jl 0xa8cd7b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8cd7b;
    }
    // 00a8cd16  39c7                   +cmp edi, eax
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
    // 00a8cd18  7e02                   -jle 0xa8cd1c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cd1c;
    }
    // 00a8cd1a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x00a8cd1c:
    // 00a8cd1c  bb0f000000             -mov ebx, 0xf
    cpu.ebx = 15 /*0xf*/;
    // 00a8cd21  f6460820               +test byte ptr [esi + 8], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 32 /*0x20*/));
    // 00a8cd25  7405                   -je 0xa8cd2c
    if (cpu.flags.zf)
    {
        goto L_0x00a8cd2c;
    }
    // 00a8cd27  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
L_0x00a8cd2c:
    // 00a8cd2c  f6460840               +test byte ptr [esi + 8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 64 /*0x40*/));
    // 00a8cd30  7402                   -je 0xa8cd34
    if (cpu.flags.zf)
    {
        goto L_0x00a8cd34;
    }
    // 00a8cd32  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8cd34:
    // 00a8cd34  39df                   +cmp edi, ebx
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
    // 00a8cd36  7e03                   -jle 0xa8cd3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cd3b;
    }
    // 00a8cd38  8d7b01                 -lea edi, [ebx + 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
L_0x00a8cd3b:
    // 00a8cd3b  c645f030               -mov byte ptr [ebp - 0x10], 0x30
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 48 /*0x30*/;
    // 00a8cd3f  39f8                   +cmp eax, edi
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
    // 00a8cd41  7e0a                   -jle 0xa8cd4d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cd4d;
    }
    // 00a8cd43  803c3a35               +cmp byte ptr [edx + edi], 0x35
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(53 /*0x35*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8cd47  7204                   -jb 0xa8cd4d
    if (cpu.flags.cf)
    {
        goto L_0x00a8cd4d;
    }
    // 00a8cd49  c645f039               -mov byte ptr [ebp - 0x10], 0x39
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = 57 /*0x39*/;
L_0x00a8cd4d:
    // 00a8cd4d  897de4                 -mov dword ptr [ebp - 0x1c], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.edi;
    // 00a8cd50  8d0417                 -lea eax, [edi + edx]
    cpu.eax = x86::reg32(cpu.edi + cpu.edx * 1);
L_0x00a8cd53:
    // 00a8cd53  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8cd56  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a8cd57  48                     -dec eax
    (cpu.eax)--;
    // 00a8cd58  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
    // 00a8cd5b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8cd5d  8a7df0                 -mov bh, byte ptr [ebp - 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cd60  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8cd62  7503                   -jne 0xa8cd67
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cd67;
    }
    // 00a8cd64  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8cd65  ebec                   -jmp 0xa8cd53
    goto L_0x00a8cd53;
L_0x00a8cd67:
    // 00a8cd67  80ff39                 +cmp bh, 0x39
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8cd6a  7506                   -jne 0xa8cd72
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cd72;
    }
    // 00a8cd6c  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00a8cd6e  fec7                   -inc bh
    (cpu.bh)++;
    // 00a8cd70  8838                   -mov byte ptr [eax], bh
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
L_0x00a8cd72:
    // 00a8cd72  837de400               +cmp dword ptr [ebp - 0x1c], 0
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
    // 00a8cd76  7d03                   -jge 0xa8cd7b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8cd7b;
    }
    // 00a8cd78  4a                     -dec edx
    (cpu.edx)--;
    // 00a8cd79  47                     -inc edi
    (cpu.edi)++;
    // 00a8cd7a  41                     -inc ecx
    (cpu.ecx)++;
L_0x00a8cd7b:
    // 00a8cd7b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8cd7d  7f18                   -jg 0xa8cd97
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8cd97;
    }
    // 00a8cd7f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a8cd84  b030                   -mov al, 0x30
    cpu.al = 48 /*0x30*/;
    // 00a8cd86  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8cd88  888568ffffff           -mov byte ptr [ebp - 0x98], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-152) /* -0x98 */) = cpu.al;
    // 00a8cd8e  8d9568ffffff           -lea edx, [ebp - 0x98]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-152) /* -0x98 */);
    // 00a8cd94  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a8cd97:
    // 00a8cd97  8a6608                 -mov ah, byte ptr [esi + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8cd9a  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a8cd9d  7514                   -jne 0xa8cdb3
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cdb3;
    }
    // 00a8cd9f  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a8cda2  741e                   -je 0xa8cdc2
    if (cpu.flags.zf)
    {
        goto L_0x00a8cdc2;
    }
    // 00a8cda4  83f9fc                 +cmp ecx, -4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8cda7  7c04                   -jl 0xa8cdad
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8cdad;
    }
    // 00a8cda9  3b0e                   +cmp ecx, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8cdab  7c06                   -jl 0xa8cdb3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8cdb3;
    }
L_0x00a8cdad:
    // 00a8cdad  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a8cdb1  740f                   -je 0xa8cdc2
    if (cpu.flags.zf)
    {
        goto L_0x00a8cdc2;
    }
L_0x00a8cdb3:
    // 00a8cdb3  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8cdb6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8cdb7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8cdb9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a8cdbb  e822000000             -call 0xa8cde2
    cpu.esp -= 4;
    sub_a8cde2(app, cpu);
    if (cpu.terminate) return;
    // 00a8cdc0  eb0d                   -jmp 0xa8cdcf
    goto L_0x00a8cdcf;
L_0x00a8cdc2:
    // 00a8cdc2  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8cdc5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cdc6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a8cdc8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8cdca  e831020000             -call 0xa8d000
    cpu.esp -= 4;
    sub_a8d000(app, cpu);
    if (cpu.terminate) return;
L_0x00a8cdcf:
L_entry_0x00a8cdcf:
    // 00a8cdcf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8cdd1  668b45ec               -mov ax, word ptr [ebp - 0x14]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cdd5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cdd6  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8cdd9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cdda  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cddd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cdde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cddf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cde0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cde1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8cde2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8cde2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8cde3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8cde5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8cde6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8cde7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8cdea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cdeb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cdec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8cded  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8cdef  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8cdf0  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a8cdf3  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a8cdf6  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8cdf9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cdfb  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a8cdfe  7425                   -je 0xa8ce25
    if (cpu.flags.zf)
    {
        goto L_0x00a8ce25;
    }
    // 00a8ce00  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ce03  7d0c                   -jge 0xa8ce11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8ce11;
    }
    // 00a8ce05  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce08  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a8ce0c  7503                   -jne 0xa8ce11
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ce11;
    }
    // 00a8ce0e  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00a8ce11:
    // 00a8ce11  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ce14  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8ce17  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8ce19  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a8ce1c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8ce1e  7d05                   -jge 0xa8ce25
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8ce25;
    }
    // 00a8ce20  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ce22  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x00a8ce25:
    // 00a8ce25  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ce28  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8ce2a  0f8fa4000000           -jg 0xa8ced4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8ced4;
    }
    // 00a8ce30  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce33  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a8ce37  7526                   -jne 0xa8ce5f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ce5f;
    }
    // 00a8ce39  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8ce3c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8ce3e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a8ce40  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8ce43  42                     -inc edx
    (cpu.edx)++;
    // 00a8ce44  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00a8ce47  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ce49  7f09                   -jg 0xa8ce54
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8ce54;
    }
    // 00a8ce4b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce4e  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a8ce52  740b                   -je 0xa8ce5f
    if (cpu.flags.zf)
    {
        goto L_0x00a8ce5f;
    }
L_0x00a8ce54:
    // 00a8ce54  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8ce57  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8ce59  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ce5b  42                     -inc edx
    (cpu.edx)++;
    // 00a8ce5c  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x00a8ce5f:
    // 00a8ce5f  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce62  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a8ce65  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ce68  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8ce6b  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a8ce6d  39fe                   +cmp esi, edi
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
    // 00a8ce6f  7e0a                   -jle 0xa8ce7b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8ce7b;
    }
    // 00a8ce71  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8ce73  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 00a8ce76  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a8ce78  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a8ce7b:
    // 00a8ce7b  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce7e  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ce81  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a8ce84  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8ce86  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a8ce89  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a8ce8b  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a8ce8e  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8ce91  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8ce93  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a8ce96  39fb                   +cmp ebx, edi
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
    // 00a8ce98  7e02                   -jle 0xa8ce9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8ce9c;
    }
    // 00a8ce9a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a8ce9c:
    // 00a8ce9c  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8ce9f  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cea2  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8cea4  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cea6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8cea7  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8cea9  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8ceab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ceac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8ceae  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8ceb1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8ceb3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8ceb5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8ceb8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8ceba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cebb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8cebc  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cebf  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a8cec2  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cec5  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cec7  29de                   +sub esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8cec9  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cecc  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00a8cecf  e90d010000             -jmp 0xa8cfe1
    goto L_0x00a8cfe1;
L_0x00a8ced4:
    // 00a8ced4  39f3                   +cmp ebx, esi
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
    // 00a8ced6  7d70                   -jge 0xa8cf48
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8cf48;
    }
    // 00a8ced8  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cedb  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cede  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8cee0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8cee1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8cee3  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8cee5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8cee6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8cee8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8ceeb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8ceed  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8ceef  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8cef2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8cef4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cef5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8cef6  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cef9  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00a8cefc  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ceff  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cf01  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cf03  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf06  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a8cf09  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf0c  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8cf0f  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8cf12  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a8cf15  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a8cf18  7520                   -jne 0xa8cf3a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cf3a;
    }
    // 00a8cf1a  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a8cf1e  7f05                   -jg 0xa8cf25
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8cf25;
    }
    // 00a8cf20  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00a8cf23  7415                   -je 0xa8cf3a
    if (cpu.flags.zf)
    {
        goto L_0x00a8cf3a;
    }
L_0x00a8cf25:
    // 00a8cf25  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cf28  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8cf2a  01cb                   +add ebx, ecx
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
    // 00a8cf2c  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 00a8cf2f  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf32  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8cf33  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x00a8cf3a:
    // 00a8cf3a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf3d  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cf40  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00a8cf43  e999000000             -jmp 0xa8cfe1
    goto L_0x00a8cfe1;
L_0x00a8cf48:
    // 00a8cf48  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cf4b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8cf4d  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cf50  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8cf51  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8cf53  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8cf55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8cf56  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8cf58  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8cf5b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8cf5d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8cf5f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8cf62  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8cf64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cf65  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8cf66  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf69  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8cf6c  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a8cf6f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8cf71  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8cf73  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a8cf76  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a8cf79  7518                   -jne 0xa8cf93
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cf93;
    }
    // 00a8cf7b  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a8cf7f  7f05                   -jg 0xa8cf86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8cf86;
    }
    // 00a8cf81  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a8cf84  741c                   -je 0xa8cfa2
    if (cpu.flags.zf)
    {
        goto L_0x00a8cfa2;
    }
L_0x00a8cf86:
    // 00a8cf86  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cf89  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8cf8b  01c7                   +add edi, eax
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
    // 00a8cf8d  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8cf8e  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 00a8cf91  eb0f                   -jmp 0xa8cfa2
    goto L_0x00a8cfa2;
L_0x00a8cf93:
    // 00a8cf93  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cf96  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8cf99  7507                   -jne 0xa8cfa2
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cfa2;
    }
    // 00a8cf9b  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00a8cfa2:
    // 00a8cfa2  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cfa5  39cb                   +cmp ebx, ecx
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
    // 00a8cfa7  7e02                   -jle 0xa8cfab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cfab;
    }
    // 00a8cfa9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a8cfab:
    // 00a8cfab  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cfae  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a8cfb1  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cfb4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8cfb6  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cfb8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8cfb9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8cfbb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8cfbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8cfbe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8cfc0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8cfc3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8cfc5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8cfc7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8cfca  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8cfcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfcd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfce  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cfd1  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cfd3  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a8cfd6  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cfd9  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cfdb  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cfde  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x00a8cfe1:
    // 00a8cfe1  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00a8cfe4  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00a8cfe7  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a8cfea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfed  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a8cfe7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8cfe7;
    // 00a8cde2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8cde3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8cde5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8cde6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8cde7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8cdea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8cdeb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8cdec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8cded  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8cdef  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8cdf0  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a8cdf3  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a8cdf6  8a6008                 -mov ah, byte ptr [eax + 8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8cdf9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cdfb  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a8cdfe  7425                   -je 0xa8ce25
    if (cpu.flags.zf)
    {
        goto L_0x00a8ce25;
    }
    // 00a8ce00  3b5df4                 +cmp ebx, dword ptr [ebp - 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ce03  7d0c                   -jge 0xa8ce11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8ce11;
    }
    // 00a8ce05  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce08  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a8ce0c  7503                   -jne 0xa8ce11
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ce11;
    }
    // 00a8ce0e  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
L_0x00a8ce11:
    // 00a8ce11  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ce14  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8ce17  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8ce19  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a8ce1c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8ce1e  7d05                   -jge 0xa8ce25
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8ce25;
    }
    // 00a8ce20  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ce22  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
L_0x00a8ce25:
    // 00a8ce25  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ce28  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8ce2a  0f8fa4000000           -jg 0xa8ced4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8ced4;
    }
    // 00a8ce30  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce33  f6460808               +test byte ptr [esi + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a8ce37  7526                   -jne 0xa8ce5f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ce5f;
    }
    // 00a8ce39  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8ce3c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8ce3e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a8ce40  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8ce43  42                     -inc edx
    (cpu.edx)++;
    // 00a8ce44  c60630                 -mov byte ptr [esi], 0x30
    app->getMemory<x86::reg8>(cpu.esi) = 48 /*0x30*/;
    // 00a8ce47  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ce49  7f09                   -jg 0xa8ce54
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8ce54;
    }
    // 00a8ce4b  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce4e  f6460810               +test byte ptr [esi + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a8ce52  740b                   -je 0xa8ce5f
    if (cpu.flags.zf)
    {
        goto L_0x00a8ce5f;
    }
L_0x00a8ce54:
    // 00a8ce54  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8ce57  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8ce59  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ce5b  42                     -inc edx
    (cpu.edx)++;
    // 00a8ce5c  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
L_0x00a8ce5f:
    // 00a8ce5f  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce62  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a8ce65  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ce68  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8ce6b  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 00a8ce6d  39fe                   +cmp esi, edi
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
    // 00a8ce6f  7e0a                   -jle 0xa8ce7b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8ce7b;
    }
    // 00a8ce71  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8ce73  897de8                 -mov dword ptr [ebp - 0x18], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edi;
    // 00a8ce76  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a8ce78  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a8ce7b:
    // 00a8ce7b  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8ce7e  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ce81  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a8ce84  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8ce86  897720                 -mov dword ptr [edi + 0x20], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a8ce89  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a8ce8b  894f20                 -mov dword ptr [edi + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a8ce8e  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8ce91  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8ce93  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a8ce96  39fb                   +cmp ebx, edi
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
    // 00a8ce98  7e02                   -jle 0xa8ce9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8ce9c;
    }
    // 00a8ce9a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a8ce9c:
    // 00a8ce9c  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8ce9f  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cea2  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8cea4  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cea6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8cea7  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8cea9  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8ceab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ceac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8ceae  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8ceb1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8ceb3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8ceb5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8ceb8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8ceba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cebb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8cebc  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cebf  895e24                 -mov dword ptr [esi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a8cec2  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cec5  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cec7  29de                   +sub esi, ebx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8cec9  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cecc  897328                 -mov dword ptr [ebx + 0x28], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00a8cecf  e90d010000             -jmp 0xa8cfe1
    goto L_0x00a8cfe1;
L_0x00a8ced4:
    // 00a8ced4  39f3                   +cmp ebx, esi
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
    // 00a8ced6  7d70                   -jge 0xa8cf48
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8cf48;
    }
    // 00a8ced8  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cedb  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cede  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8cee0  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8cee1  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8cee3  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8cee5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8cee6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8cee8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8ceeb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8ceed  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8ceef  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8cef2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8cef4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cef5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8cef6  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cef9  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00a8cefc  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8ceff  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cf01  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cf03  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf06  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 00a8cf09  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf0c  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8cf0f  8a4e08                 -mov cl, byte ptr [esi + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8cf12  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a8cf15  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a8cf18  7520                   -jne 0xa8cf3a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cf3a;
    }
    // 00a8cf1a  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a8cf1e  7f05                   -jg 0xa8cf25
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8cf25;
    }
    // 00a8cf20  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 00a8cf23  7415                   -je 0xa8cf3a
    if (cpu.flags.zf)
    {
        goto L_0x00a8cf3a;
    }
L_0x00a8cf25:
    // 00a8cf25  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cf28  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8cf2a  01cb                   +add ebx, ecx
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
    // 00a8cf2c  c6032e                 -mov byte ptr [ebx], 0x2e
    app->getMemory<x86::reg8>(cpu.ebx) = 46 /*0x2e*/;
    // 00a8cf2f  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf32  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8cf33  c7432401000000         -mov dword ptr [ebx + 0x24], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
L_0x00a8cf3a:
    // 00a8cf3a  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf3d  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cf40  895e28                 -mov dword ptr [esi + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00a8cf43  e999000000             -jmp 0xa8cfe1
    goto L_0x00a8cfe1;
L_0x00a8cf48:
    // 00a8cf48  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cf4b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8cf4d  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cf50  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8cf51  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8cf53  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8cf55  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8cf56  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8cf58  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8cf5b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8cf5d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8cf5f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8cf62  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8cf64  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cf65  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8cf66  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cf69  8b75e8                 -mov esi, dword ptr [ebp - 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8cf6c  8a6f08                 -mov ch, byte ptr [edi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a8cf6f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8cf71  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8cf73  897718                 -mov dword ptr [edi + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00a8cf76  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 00a8cf79  7518                   -jne 0xa8cf93
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cf93;
    }
    // 00a8cf7b  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00a8cf7f  7f05                   -jg 0xa8cf86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8cf86;
    }
    // 00a8cf81  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00a8cf84  741c                   -je 0xa8cfa2
    if (cpu.flags.zf)
    {
        goto L_0x00a8cfa2;
    }
L_0x00a8cf86:
    // 00a8cf86  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cf89  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8cf8b  01c7                   +add edi, eax
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
    // 00a8cf8d  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8cf8e  c6072e                 -mov byte ptr [edi], 0x2e
    app->getMemory<x86::reg8>(cpu.edi) = 46 /*0x2e*/;
    // 00a8cf91  eb0f                   -jmp 0xa8cfa2
    goto L_0x00a8cfa2;
L_0x00a8cf93:
    // 00a8cf93  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cf96  803e30                 +cmp byte ptr [esi], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8cf99  7507                   -jne 0xa8cfa2
    if (!cpu.flags.zf)
    {
        goto L_0x00a8cfa2;
    }
    // 00a8cf9b  c7471800000000         -mov dword ptr [edi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
L_0x00a8cfa2:
    // 00a8cfa2  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cfa5  39cb                   +cmp ebx, ecx
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
    // 00a8cfa7  7e02                   -jle 0xa8cfab
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8cfab;
    }
    // 00a8cfa9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
L_0x00a8cfab:
    // 00a8cfab  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8cfae  0375e8                 -add esi, dword ptr [ebp - 0x18]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a8cfb1  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8cfb4  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8cfb6  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8cfb8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8cfb9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8cfbb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8cfbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8cfbe  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8cfc0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8cfc3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8cfc5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8cfc7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8cfca  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8cfcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfcd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfce  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cfd1  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cfd3  89561c                 -mov dword ptr [esi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a8cfd6  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8cfd9  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8cfdb  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8cfde  897320                 -mov dword ptr [ebx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.esi;
L_0x00a8cfe1:
    // 00a8cfe1  035508                 -add edx, dword ptr [ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 00a8cfe4  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_entry_0x00a8cfe7:
    // 00a8cfe7  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a8cfea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8cfed  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void sub_a8d000(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a8d000  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8d001  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8d003  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8d004  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8d005  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8d008  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8d009  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8d00a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8d00b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8d00c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8d00e  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a8d011  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d014  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8d017  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8d019  7f05                   -jg 0xa8d020
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8d020;
    }
    // 00a8d01b  0155ec                 +add dword ptr [ebp - 0x14], edx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8d01e  eb0e                   -jmp 0xa8d02e
    goto L_0x00a8d02e;
L_0x00a8d020:
    // 00a8d020  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8d023  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d025  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00a8d028  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a8d02b  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
L_0x00a8d02e:
    // 00a8d02e  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d031  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8d033  8a5008                 -mov dl, byte ptr [eax + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8d036  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 00a8d039  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00a8d03c  741b                   -je 0xa8d059
    if (cpu.flags.zf)
    {
        goto L_0x00a8d059;
    }
    // 00a8d03e  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8d041  3b45ec                 +cmp eax, dword ptr [ebp - 0x14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d044  7d03                   -jge 0xa8d049
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d049;
    }
    // 00a8d046  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
L_0x00a8d049:
    // 00a8d049  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8d04c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a8d04d  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 00a8d050  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8d052  7d05                   -jge 0xa8d059
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d059;
    }
    // 00a8d054  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8d056  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
L_0x00a8d059:
    // 00a8d059  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d05c  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8d05f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8d061  7f16                   -jg 0xa8d079
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8d079;
    }
    // 00a8d063  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d066  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d069  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d06c  01d8                   +add eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8d06e  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 00a8d071  c60030                 -mov byte ptr [eax], 0x30
    app->getMemory<x86::reg8>(cpu.eax) = 48 /*0x30*/;
    // 00a8d074  e97c000000             -jmp 0xa8d0f5
    goto L_0x00a8d0f5;
L_0x00a8d079:
    // 00a8d079  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8d07c  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a8d07f  39d7                   +cmp edi, edx
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
    // 00a8d081  7e03                   -jle 0xa8d086
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8d086;
    }
    // 00a8d083  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
L_0x00a8d086:
    // 00a8d086  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d089  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d08c  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d08f  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8d092  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8d094  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d097  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8d098  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8d09a  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8d09c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8d09d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8d09f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8d0a2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8d0a4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8d0a6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8d0a9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8d0ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d0ac  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8d0ad  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d0b0  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8d0b3  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8d0b6  8d0c03                 -lea ecx, [ebx + eax]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 00a8d0b9  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d0bb  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d0bd  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a8d0c0  8975e4                 -mov dword ptr [ebp - 0x1c], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.esi;
    // 00a8d0c3  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a8d0c6  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
    // 00a8d0c9  39d8                   +cmp eax, ebx
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
    // 00a8d0cb  7d28                   -jge 0xa8d0f5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d0f5;
    }
    // 00a8d0cd  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d0d0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d0d2  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d0d5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8d0d7  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a8d0dc  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a8d0df  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d0e2  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d0e5  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8d0e7  e8c499ffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8d0ec  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d0ef  8d3c06                 -lea edi, [esi + eax]
    cpu.edi = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00a8d0f2  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
L_0x00a8d0f5:
    // 00a8d0f5  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d0f8  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d0fb  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00a8d0fe  f6420808               +test byte ptr [edx + 8], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) & 8 /*0x8*/));
    // 00a8d102  7520                   -jne 0xa8d124
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d124;
    }
    // 00a8d104  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d108  7f09                   -jg 0xa8d113
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8d113;
    }
    // 00a8d10a  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d10d  f6400810               +test byte ptr [eax + 8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) & 16 /*0x10*/));
    // 00a8d111  7411                   -je 0xa8d124
    if (cpu.flags.zf)
    {
        goto L_0x00a8d124;
    }
L_0x00a8d113:
    // 00a8d113  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d116  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d119  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d11c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a8d11e  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00a8d121  c6002e                 -mov byte ptr [eax], 0x2e
    app->getMemory<x86::reg8>(cpu.eax) = 46 /*0x2e*/;
L_0x00a8d124:
    // 00a8d124  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d127  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8d12a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8d12c  7d25                   -jge 0xa8d153
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d153;
    }
    // 00a8d12e  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d131  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d134  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8d136  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a8d139  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a8d13e  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00a8d140  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8d142  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00a8d145  e86699ffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8d14a  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d14d  8d3401                 -lea esi, [ecx + eax]
    cpu.esi = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a8d150  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
L_0x00a8d153:
    // 00a8d153  8b7dec                 -mov edi, dword ptr [ebp - 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8d156  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8d158  7e49                   -jle 0xa8d1a3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8d1a3;
    }
    // 00a8d15a  3b7de0                 +cmp edi, dword ptr [ebp - 0x20]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d15d  7d03                   -jge 0xa8d162
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d162;
    }
    // 00a8d15f  897de0                 -mov dword ptr [ebp - 0x20], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edi;
L_0x00a8d162:
    // 00a8d162  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8d165  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8d167  7426                   -je 0xa8d18f
    if (cpu.flags.zf)
    {
        goto L_0x00a8d18f;
    }
    // 00a8d169  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d16c  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d16f  8b75e4                 -mov esi, dword ptr [ebp - 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00a8d172  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8d174  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8d176  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8d177  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8d179  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8d17b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8d17c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8d17e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8d181  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8d183  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8d185  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8d188  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8d18a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d18b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8d18c  015df4                 -add dword ptr [ebp - 0xc], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */)) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8d18f:
    // 00a8d18f  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d192  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d195  8b7de0                 -mov edi, dword ptr [ebp - 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8d198  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a8d19b  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8d19e  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8d1a0  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x00a8d1a3:
    // 00a8d1a3  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d1a6  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 00a8d1aa  7416                   -je 0xa8d1c2
    if (cpu.flags.zf)
    {
        goto L_0x00a8d1c2;
    }
    // 00a8d1ac  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d1af  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d1b2  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d1b5  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d1b8  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8d1ba  8a520c                 -mov dl, byte ptr [edx + 0xc]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a8d1bd  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a8d1c0  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a8d1c2:
    // 00a8d1c2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d1c5  8b75dc                 -mov esi, dword ptr [ebp - 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d1c8  40                     -inc eax
    (cpu.eax)++;
    // 00a8d1c9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8d1cb  7c0f                   -jl 0xa8d1dc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d1dc;
    }
    // 00a8d1cd  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d1d0  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a8d1d3  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d1d6  c604022b               -mov byte ptr [edx + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a8d1da  eb14                   -jmp 0xa8d1f0
    goto L_0x00a8d1f0;
L_0x00a8d1dc:
    // 00a8d1dc  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d1df  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a8d1e1  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a8d1e4  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00a8d1e6  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d1e9  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 00a8d1ec  c604022d               -mov byte ptr [edx + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 45 /*0x2d*/;
L_0x00a8d1f0:
    // 00a8d1f0  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d1f3  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00a8d1f6  83fb03                 +cmp ebx, 3
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
    // 00a8d1f9  773e                   -ja 0xa8d239
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8d239;
    }
    // 00a8d1fb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d1fd  2eff2485f0cfa800       -jmp dword ptr cs:[eax*4 + 0xa8cff0]
    cpu.ip = app->getMemory<x86::reg32>(11063280 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a8d205:
    // 00a8d205  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d20c  7d26                   -jge 0xa8d234
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d234;
    }
    // 00a8d20e  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00a8d213  eb24                   -jmp 0xa8d239
    goto L_0x00a8d239;
  case 0x00a8d215:
    // 00a8d215  837ddc0a               +cmp dword ptr [ebp - 0x24], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d219  7c05                   -jl 0xa8d220
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d220;
    }
    // 00a8d21b  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
  [[fallthrough]];
  case 0x00a8d220:
L_0x00a8d220:
    // 00a8d220  837ddc64               +cmp dword ptr [ebp - 0x24], 0x64
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d224  7c05                   -jl 0xa8d22b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d22b;
    }
    // 00a8d226  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
  [[fallthrough]];
  case 0x00a8d22b:
L_0x00a8d22b:
    // 00a8d22b  817ddce8030000         +cmp dword ptr [ebp - 0x24], 0x3e8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d232  7c05                   -jl 0xa8d239
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d239;
    }
L_0x00a8d234:
    // 00a8d234  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
L_0x00a8d239:
    // 00a8d239  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d23c  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a8d23f  83fb04                 +cmp ebx, 4
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
    // 00a8d242  7c4b                   -jl 0xa8d28f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d28f;
    }
    // 00a8d244  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8d246  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d249  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a8d24c  3de8030000             +cmp eax, 0x3e8
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d251  7c26                   -jl 0xa8d279
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d279;
    }
    // 00a8d253  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d255  bfe8030000             -mov edi, 0x3e8
    cpu.edi = 1000 /*0x3e8*/;
    // 00a8d25a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a8d25d  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a8d25f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a8d262  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d264  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00a8d267  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d269  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a8d26c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d26e  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d271  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a8d274  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d276  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a8d279:
    // 00a8d279  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d27c  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d27f  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d282  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d285  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8d287  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8d28a  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a8d28d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a8d28f:
    // 00a8d28f  83fb03                 +cmp ebx, 3
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
    // 00a8d292  7c49                   -jl 0xa8d2dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d2dd;
    }
    // 00a8d294  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8d296  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d299  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a8d29c  83f864                 +cmp eax, 0x64
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d29f  7c26                   -jl 0xa8d2c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d2c7;
    }
    // 00a8d2a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d2a3  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 00a8d2a8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a8d2ab  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a8d2ad  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a8d2b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d2b2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a8d2b5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d2b7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a8d2ba  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d2bc  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d2bf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a8d2c2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d2c4  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a8d2c7:
    // 00a8d2c7  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d2ca  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d2cd  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d2d0  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d2d3  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8d2d5  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8d2d8  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00a8d2db  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a8d2dd:
    // 00a8d2dd  83fb02                 +cmp ebx, 2
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
    // 00a8d2e0  7c43                   -jl 0xa8d325
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d325;
    }
    // 00a8d2e2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8d2e4  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d2e7  897df0                 -mov dword ptr [ebp - 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edi;
    // 00a8d2ea  83f80a                 +cmp eax, 0xa
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
    // 00a8d2ed  7c20                   -jl 0xa8d30f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d30f;
    }
    // 00a8d2ef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d2f1  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a8d2f6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00a8d2f9  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00a8d2fb  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a8d2fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d300  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a8d303  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d305  8b55dc                 -mov edx, dword ptr [ebp - 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d308  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d30a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d30c  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
L_0x00a8d30f:
    // 00a8d30f  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d312  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d315  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d318  8a55f0                 -mov dl, byte ptr [ebp - 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d31b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8d31d  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8d320  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 00a8d323  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a8d325:
    // 00a8d325  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d328  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00a8d32b  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d32e  8a55dc                 -mov dl, byte ptr [ebp - 0x24]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d331  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a8d333  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a8d336  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a8d338  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d33b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8d33d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00a8d340  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8d342  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d345  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00a8d348  8d0437                 -lea eax, [edi + esi]
    cpu.eax = x86::reg32(cpu.edi + cpu.esi * 1);
    // 00a8d34b  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 00a8d34e  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a8d351  e991fcffff             -jmp 0xa8cfe7
    return sub_a8cfe7(app, cpu);
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void sub_a8d356(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d356  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8d357  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8d359  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8d35a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8d35b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8d35c  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 00a8d35f  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8d361  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 00a8d364  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x00a8d367:
    // 00a8d367  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8d369  80fa20                 +cmp dl, 0x20
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
    // 00a8d36c  740a                   -je 0xa8d378
    if (cpu.flags.zf)
    {
        goto L_0x00a8d378;
    }
    // 00a8d36e  80fa09                 +cmp dl, 9
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d371  7208                   -jb 0xa8d37b
    if (cpu.flags.cf)
    {
        goto L_0x00a8d37b;
    }
    // 00a8d373  80fa0d                 +cmp dl, 0xd
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(13 /*0xd*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d376  7703                   -ja 0xa8d37b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8d37b;
    }
L_0x00a8d378:
    // 00a8d378  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8d379  ebec                   -jmp 0xa8d367
    goto L_0x00a8d367;
L_0x00a8d37b:
    // 00a8d37b  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d37e  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a8d380  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d383  7407                   -je 0xa8d38c
    if (cpu.flags.zf)
    {
        goto L_0x00a8d38c;
    }
    // 00a8d385  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d388  7504                   -jne 0xa8d38e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d38e;
    }
    // 00a8d38a  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a8d38c:
    // 00a8d38c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a8d38e:
    // 00a8d38e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8d390  b630                   -mov dh, 0x30
    cpu.dh = 48 /*0x30*/;
    // 00a8d392  895de4                 -mov dword ptr [ebp - 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.ebx;
L_0x00a8d395:
    // 00a8d395  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8d397  40                     -inc eax
    (cpu.eax)++;
    // 00a8d398  80fa2e                 +cmp dl, 0x2e
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
    // 00a8d39b  750a                   -jne 0xa8d3a7
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d3a7;
    }
    // 00a8d39d  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a8d3a0  752d                   -jne 0xa8d3cf
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d3cf;
    }
    // 00a8d3a2  80c908                 +or cl, 8
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a8d3a5  ebee                   -jmp 0xa8d395
    goto L_0x00a8d395;
L_0x00a8d3a7:
    // 00a8d3a7  80fa30                 +cmp dl, 0x30
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
    // 00a8d3aa  7223                   -jb 0xa8d3cf
    if (cpu.flags.cf)
    {
        goto L_0x00a8d3cf;
    }
    // 00a8d3ac  80fa39                 +cmp dl, 0x39
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
    // 00a8d3af  771e                   -ja 0xa8d3cf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8d3cf;
    }
    // 00a8d3b1  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00a8d3b4  7403                   -je 0xa8d3b9
    if (cpu.flags.zf)
    {
        goto L_0x00a8d3b9;
    }
    // 00a8d3b6  ff45e4                 -inc dword ptr [ebp - 0x1c]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */))++;
L_0x00a8d3b9:
    // 00a8d3b9  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8d3bb  80fe30                 +cmp dh, 0x30
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
    // 00a8d3be  740a                   -je 0xa8d3ca
    if (cpu.flags.zf)
    {
        goto L_0x00a8d3ca;
    }
    // 00a8d3c0  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d3c3  7d04                   -jge 0xa8d3c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d3c9;
    }
    // 00a8d3c5  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
L_0x00a8d3c9:
    // 00a8d3c9  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a8d3ca:
    // 00a8d3ca  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a8d3cd  ebc6                   -jmp 0xa8d395
    goto L_0x00a8d395;
L_0x00a8d3cf:
    // 00a8d3cf  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8d3d1  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a8d3d4  0f8465000000           -je 0xa8d43f
    if (cpu.flags.zf)
    {
        goto L_0x00a8d43f;
    }
    // 00a8d3da  80fa65                 +cmp dl, 0x65
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(101 /*0x65*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d3dd  7405                   -je 0xa8d3e4
    if (cpu.flags.zf)
    {
        goto L_0x00a8d3e4;
    }
    // 00a8d3df  80fa45                 +cmp dl, 0x45
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(69 /*0x45*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d3e2  7557                   -jne 0xa8d43b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d43b;
    }
L_0x00a8d3e4:
    // 00a8d3e4  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00a8d3e7  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8d3e9  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 00a8d3ec  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8d3ef  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d3f2  7408                   -je 0xa8d3fc
    if (cpu.flags.zf)
    {
        goto L_0x00a8d3fc;
    }
    // 00a8d3f4  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d3f7  7505                   -jne 0xa8d3fe
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d3fe;
    }
    // 00a8d3f9  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a8d3fc:
    // 00a8d3fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a8d3fe:
    // 00a8d3fe  80e1fb                 -and cl, 0xfb
    cpu.cl &= x86::reg8(x86::sreg8(251 /*0xfb*/));
L_0x00a8d401:
    // 00a8d401  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8d403  80fa30                 +cmp dl, 0x30
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
    // 00a8d406  7222                   -jb 0xa8d42a
    if (cpu.flags.cf)
    {
        goto L_0x00a8d42a;
    }
    // 00a8d408  80fa39                 +cmp dl, 0x39
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
    // 00a8d40b  771d                   -ja 0xa8d42a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8d42a;
    }
    // 00a8d40d  81fee8030000           +cmp esi, 0x3e8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1000 /*0x3e8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d413  7d0f                   -jge 0xa8d424
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d424;
    }
    // 00a8d415  6bf60a                 -imul esi, esi, 0xa
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a8d418  8975ec                 -mov dword ptr [ebp - 0x14], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.esi;
    // 00a8d41b  0fb6f2                 -movzx esi, dl
    cpu.esi = x86::reg32(cpu.dl);
    // 00a8d41e  0375ec                 -add esi, dword ptr [ebp - 0x14]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 00a8d421  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x00a8d424:
    // 00a8d424  80c904                 +or cl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a8d427  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8d428  ebd7                   -jmp 0xa8d401
    goto L_0x00a8d401;
L_0x00a8d42a:
    // 00a8d42a  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 00a8d42d  7402                   -je 0xa8d431
    if (cpu.flags.zf)
    {
        goto L_0x00a8d431;
    }
    // 00a8d42f  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
L_0x00a8d431:
    // 00a8d431  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a8d434  7506                   -jne 0xa8d43c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d43c;
    }
    // 00a8d436  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a8d439  eb01                   -jmp 0xa8d43c
    goto L_0x00a8d43c;
L_0x00a8d43b:
    // 00a8d43b  48                     -dec eax
    (cpu.eax)--;
L_0x00a8d43c:
    // 00a8d43c  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
L_0x00a8d43f:
    // 00a8d43f  837de800               +cmp dword ptr [ebp - 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d443  7408                   -je 0xa8d44d
    if (cpu.flags.zf)
    {
        goto L_0x00a8d44d;
    }
    // 00a8d445  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d448  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a8d44b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a8d44d:
    // 00a8d44d  2b75e4                 -sub esi, dword ptr [ebp - 0x1c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 00a8d450  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d453  7e0a                   -jle 0xa8d45f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8d45f;
    }
    // 00a8d455  83eb13                 -sub ebx, 0x13
    (cpu.ebx) -= x86::reg32(x86::sreg32(19 /*0x13*/));
    // 00a8d458  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8d45a  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
L_0x00a8d45f:
    // 00a8d45f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8d461  7e0b                   -jle 0xa8d46e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8d46e;
    }
    // 00a8d463  807c2bbf30             +cmp byte ptr [ebx + ebp - 0x41], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-65) /* -0x41 */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8d468  7504                   -jne 0xa8d46e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d46e;
    }
    // 00a8d46a  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8d46b  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8d46c  ebf1                   -jmp 0xa8d45f
    goto L_0x00a8d45f;
L_0x00a8d46e:
    // 00a8d46e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8d470  7511                   -jne 0xa8d483
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d483;
    }
    // 00a8d472  66c747080000           -mov word ptr [edi + 8], 0
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a8d478  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a8d47b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8d47d  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00a8d47f  31f8                   +xor eax, edi
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00a8d481  eb5f                   -jmp 0xa8d4e2
    goto L_0x00a8d4e2;
L_0x00a8d483:
    // 00a8d483  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8d485  8d45c0                 -lea eax, [ebp - 0x40]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a8d488  88542bc0               -mov byte ptr [ebx + ebp - 0x40], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-64) /* -0x40 */ + cpu.ebp * 1) = cpu.dl;
    // 00a8d48c  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8d48f  e866150000             -call 0xa8e9fa
    cpu.esp -= 4;
    sub_a8e9fa(app, cpu);
    if (cpu.terminate) return;
    // 00a8d494  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8d496  740a                   -je 0xa8d4a2
    if (cpu.flags.zf)
    {
        goto L_0x00a8d4a2;
    }
    // 00a8d498  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8d49b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8d49d  e8a4f4ffff             -call 0xa8c946
    cpu.esp -= 4;
    sub_a8c946(app, cpu);
    if (cpu.terminate) return;
L_0x00a8d4a2:
    // 00a8d4a2  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00a8d4a5  7404                   -je 0xa8d4ab
    if (cpu.flags.zf)
    {
        goto L_0x00a8d4ab;
    }
    // 00a8d4a7  804ddd80               -or byte ptr [ebp - 0x23], 0x80
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00a8d4ab:
    // 00a8d4ab  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d4ae  66894708               -mov word ptr [edi + 8], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00a8d4b2  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a8d4b5  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a8d4b8  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8d4bb  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00a8d4bd  8d441eff               -lea eax, [esi + ebx - 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */ + cpu.ebx * 1);
    // 00a8d4c1  3d34010000             +cmp eax, 0x134
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(308 /*0x134*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d4c6  7e07                   -jle 0xa8d4cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8d4cf;
    }
    // 00a8d4c8  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a8d4cd  eb13                   -jmp 0xa8d4e2
    goto L_0x00a8d4e2;
L_0x00a8d4cf:
    // 00a8d4cf  3dccfeffff             +cmp eax, 0xfffffecc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966988 /*0xfffffecc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d4d4  7d07                   -jge 0xa8d4dd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d4dd;
    }
    // 00a8d4d6  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a8d4db  eb05                   -jmp 0xa8d4e2
    goto L_0x00a8d4e2;
L_0x00a8d4dd:
    // 00a8d4dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a8d4e2:
    // 00a8d4e2  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8d4e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d4e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d4e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d4e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d4e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8d4ea(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d4ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8d4eb  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8d4ed  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8d4ee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8d4ef  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00a8d4f2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8d4f4  8d55d4                 -lea edx, [ebp - 0x2c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8d4f7  e85afeffff             -call 0xa8d356
    cpu.esp -= 4;
    sub_a8d356(app, cpu);
    if (cpu.terminate) return;
    // 00a8d4fc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8d4fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8d500  750b                   -jne 0xa8d50d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d50d;
    }
    // 00a8d502  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
L_0x00a8d505:
    // 00a8d505  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a8d508  e9ad000000             -jmp 0xa8d5ba
    goto L_0x00a8d5ba;
L_0x00a8d50d:
    // 00a8d50d  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a8d510  80e47f                 -and ah, 0x7f
    cpu.ah &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a8d513  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a8d518  3dff430000             +cmp eax, 0x43ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17407 /*0x43ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d51d  7c2a                   -jl 0xa8d549
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8d549;
    }
    // 00a8d51f  e820cdffff             -call 0xa8a244
    cpu.esp -= 4;
    sub_a8a244(app, cpu);
    if (cpu.terminate) return;
    // 00a8d524  f645dd80               +test byte ptr [ebp - 0x23], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-35) /* -0x23 */) & 128 /*0x80*/));
    // 00a8d528  7410                   -je 0xa8d53a
    if (cpu.flags.zf)
    {
        goto L_0x00a8d53a;
    }
    // 00a8d52a  dd05ec1ea900           +fld qword ptr [0xa91eec]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(11083500) /* 0xa91eec */)));
    // 00a8d530  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a8d532  dd5de8                 +fstp qword ptr [ebp - 0x18]
    app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8d535  e980000000             -jmp 0xa8d5ba
    goto L_0x00a8d5ba;
L_0x00a8d53a:
    // 00a8d53a  a1ec1ea900             -mov eax, dword ptr [0xa91eec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11083500) /* 0xa91eec */);
    // 00a8d53f  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 00a8d542  a1f01ea900             -mov eax, dword ptr [0xa91ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11083504) /* 0xa91ef0 */);
    // 00a8d547  ebbc                   -jmp 0xa8d505
    goto L_0x00a8d505;
L_0x00a8d549:
    // 00a8d549  3dcd3b0000             +cmp eax, 0x3bcd
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15309 /*0x3bcd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d54e  7d42                   -jge 0xa8d592
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d592;
    }
    // 00a8d550  83f8cc                 +cmp eax, -0x34
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-52 /*-0x34*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d553  7d0f                   -jge 0xa8d564
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8d564;
    }
    // 00a8d555  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8d557  e8e8ccffff             -call 0xa8a244
    cpu.esp -= 4;
    sub_a8a244(app, cpu);
    if (cpu.terminate) return;
    // 00a8d55c  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 00a8d55f  894dec                 -mov dword ptr [ebp - 0x14], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ecx;
    // 00a8d562  eb56                   -jmp 0xa8d5ba
    goto L_0x00a8d5ba;
L_0x00a8d564:
    // 00a8d564  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d567  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8d56a  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8d56c  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8d56e  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d571  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a8d574  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8d577  8b5de8                 -mov ebx, dword ptr [ebp - 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d57a  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 00a8d57d  a9ffffff7f             +test eax, 0x7fffffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2147483647 /*0x7fffffff*/));
    // 00a8d582  7504                   -jne 0xa8d588
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d588;
    }
    // 00a8d584  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8d586  742d                   -je 0xa8d5b5
    if (cpu.flags.zf)
    {
        goto L_0x00a8d5b5;
    }
L_0x00a8d588:
    // 00a8d588  66f745f6f07f           +test word ptr [ebp - 0xa], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-10) /* -0xa */) & 32752 /*0x7ff0*/));
    // 00a8d58e  752a                   -jne 0xa8d5ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d5ba;
    }
    // 00a8d590  eb23                   -jmp 0xa8d5b5
    goto L_0x00a8d5b5;
L_0x00a8d592:
    // 00a8d592  8d55e8                 -lea edx, [ebp - 0x18]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d595  8d45d4                 -lea eax, [ebp - 0x2c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a8d598  db28                   -fld xword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.eax)));
    // 00a8d59a  dd1a                   -fstp qword ptr [edx]
    app->getMemory<double>(cpu.edx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a8d59c  83fb03                 +cmp ebx, 3
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
    // 00a8d59f  7414                   -je 0xa8d5b5
    if (cpu.flags.zf)
    {
        goto L_0x00a8d5b5;
    }
    // 00a8d5a1  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00a8d5a4  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 00a8d5a7  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a8d5aa  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 00a8d5ad  66f745e6f07f           +test word ptr [ebp - 0x1a], 0x7ff0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-26) /* -0x1a */) & 32752 /*0x7ff0*/));
    // 00a8d5b3  7505                   -jne 0xa8d5ba
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d5ba;
    }
L_0x00a8d5b5:
    // 00a8d5b5  e88accffff             -call 0xa8a244
    cpu.esp -= 4;
    sub_a8a244(app, cpu);
    if (cpu.terminate) return;
L_0x00a8d5ba:
    // 00a8d5ba  dd45e8                 -fld qword ptr [ebp - 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.ebp + x86::reg32(-24) /* -0x18 */)));
    // 00a8d5bd  8d65f8                 -lea esp, [ebp - 8]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a8d5c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d5c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d5c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d5c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8d5d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d5d0  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8d5d3  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8d5d5  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a8d5d7  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8d5da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8d5e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d5e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8d5e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8d5e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8d5e3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8d5e6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8d5e8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8d5ea  ff15c426a900           -call dword ptr [0xa926c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085508) /* 0xa926c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d5f0  b87c26a900             -mov eax, 0xa9267c
    cpu.eax = 11085436 /*0xa9267c*/;
    // 00a8d5f5  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a8d5f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d5f9  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a8d5fb  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 00a8d5fe  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8d600  e817000000             -call 0xa8d61c
    cpu.esp -= 4;
    sub_a8d61c(app, cpu);
    if (cpu.terminate) return;
    // 00a8d605  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8d607  0f85bb010000           -jne 0xa8d7c8
    if (!cpu.flags.zf)
    {
        return sub_a8d7c8(app, cpu);
    }
    // 00a8d60d  ff15cc26a900           -call dword ptr [0xa926cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085516) /* 0xa926cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d613  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8d615  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8d618  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d619  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d61a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d61b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8d61c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d61c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8d61d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8d61e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8d61f  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8d622  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a8d626  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8d628  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a8d62a  8d430b                 -lea eax, [ebx + 0xb]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(11) /* 0xb */);
    // 00a8d62d  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a8d62f  39d8                   +cmp eax, ebx
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
    // 00a8d631  7307                   -jae 0xa8d63a
    if (!cpu.flags.cf)
    {
        goto L_0x00a8d63a;
    }
    // 00a8d633  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8d638  eb0a                   -jmp 0xa8d644
    goto L_0x00a8d644;
L_0x00a8d63a:
    // 00a8d63a  83f810                 +cmp eax, 0x10
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
    // 00a8d63d  7305                   -jae 0xa8d644
    if (!cpu.flags.cf)
    {
        goto L_0x00a8d644;
    }
    // 00a8d63f  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x00a8d644:
    // 00a8d644  8d57fc                 -lea edx, [edi - 4]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 00a8d647  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a8d64a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8d64c  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a8d64f  39d0                   +cmp eax, edx
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
    // 00a8d651  0f860b010000           -jbe 0xa8d762
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8d762;
    }
    // 00a8d657  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8d65a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d65c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00a8d65e:
    // 00a8d65e  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00a8d661  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a8d663  83fbff                 +cmp ebx, -1
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
    // 00a8d666  750a                   -jne 0xa8d672
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d672;
    }
    // 00a8d668  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a8d66d  e94d010000             -jmp 0xa8d7bf
    goto L_0x00a8d7bf;
L_0x00a8d672:
    // 00a8d672  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a8d675  0f85d9000000           -jne 0xa8d754
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d754;
    }
    // 00a8d67b  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8d67e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8d682  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8d685  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a8d687  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a8d68b  b87c26a900             -mov eax, 0xa9267c
    cpu.eax = 11085436 /*0xa9267c*/;
    // 00a8d690  663b54240c             +cmp dx, word ptr [esp + 0xc]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8d695  7521                   -jne 0xa8d6b8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d6b8;
    }
    // 00a8d697  8b357c26a900           -mov esi, dword ptr [0xa9267c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */);
    // 00a8d69d  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a8d6a1  7415                   -je 0xa8d6b8
    if (cpu.flags.zf)
    {
        goto L_0x00a8d6b8;
    }
L_0x00a8d6a3:
    // 00a8d6a3  39fe                   +cmp esi, edi
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
    // 00a8d6a5  7708                   -ja 0xa8d6af
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8d6af;
    }
    // 00a8d6a7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8d6a9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8d6ab  39f8                   +cmp eax, edi
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
    // 00a8d6ad  7709                   -ja 0xa8d6b8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8d6b8;
    }
L_0x00a8d6af:
    // 00a8d6af  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8d6b2  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a8d6b6  75eb                   -jne 0xa8d6a3
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d6a3;
    }
L_0x00a8d6b8:
    // 00a8d6b8  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a8d6bb  39d1                   +cmp ecx, edx
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
    // 00a8d6bd  7506                   -jne 0xa8d6c5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d6c5;
    }
    // 00a8d6bf  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a8d6c2  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a8d6c5:
    // 00a8d6c5  3b5d00                 +cmp ebx, dword ptr [ebp]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d6c8  720c                   -jb 0xa8d6d6
    if (cpu.flags.cf)
    {
        goto L_0x00a8d6d6;
    }
    // 00a8d6ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d6cc  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a8d6cf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d6d1  83f810                 +cmp eax, 0x10
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
    // 00a8d6d4  7334                   -jae 0xa8d70a
    if (!cpu.flags.cf)
    {
        goto L_0x00a8d70a;
    }
L_0x00a8d6d6:
    // 00a8d6d6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8d6da  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8d6de  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a8d6e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8d6e3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8d6e7  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8d6ea  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8d6ed  0118                   -add dword ptr [eax], ebx
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8d6ef  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a8d6f2  48                     -dec eax
    (cpu.eax)--;
    // 00a8d6f3  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8d6f5  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00a8d6f8  8815b13ea900           -mov byte ptr [0xa93eb1], dl
    app->getMemory<x86::reg8>(x86::reg32(11091633) /* 0xa93eb1 */) = cpu.dl;
    // 00a8d6fe  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a8d701  39d3                   +cmp ebx, edx
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
    // 00a8d703  7244                   -jb 0xa8d749
    if (cpu.flags.cf)
    {
        goto L_0x00a8d749;
    }
    // 00a8d705  e9b3000000             -jmp 0xa8d7bd
    goto L_0x00a8d7bd;
L_0x00a8d70a:
    // 00a8d70a  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d70c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a8d70e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8d712  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a8d715  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8d719  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8d71c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8d720  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a8d723  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8d727  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a8d72a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8d72d  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00a8d730  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8d732  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8d734  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d736  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a8d738  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a8d73a  8825b13ea900           -mov byte ptr [0xa93eb1], ah
    app->getMemory<x86::reg8>(x86::reg32(11091633) /* 0xa93eb1 */) = cpu.ah;
    // 00a8d740  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d742  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8d745  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d746  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d747  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d748  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8d749:
    // 00a8d749  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8d74b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8d74d  01d9                   +add ecx, ebx
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
    // 00a8d74f  e90affffff             -jmp 0xa8d65e
    goto L_0x00a8d65e;
L_0x00a8d754:
    // 00a8d754  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8d759  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d75b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8d75e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d75f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d760  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d761  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8d762:
    // 00a8d762  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d764  83fa10                 +cmp edx, 0x10
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
    // 00a8d767  7254                   -jb 0xa8d7bd
    if (cpu.flags.cf)
    {
        goto L_0x00a8d7bd;
    }
    // 00a8d769  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8d76b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8d76e  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8d771  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8d774  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 00a8d776  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 00a8d779  b87c26a900             -mov eax, 0xa9267c
    cpu.eax = 11085436 /*0xa9267c*/;
    // 00a8d77e  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a8d781  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a8d783  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a8d785  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8d789  6639da                 +cmp dx, bx
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
    // 00a8d78c  7521                   -jne 0xa8d7af
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d7af;
    }
    // 00a8d78e  8b357c26a900           -mov esi, dword ptr [0xa9267c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11085436) /* 0xa9267c */);
    // 00a8d794  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a8d798  7415                   -je 0xa8d7af
    if (cpu.flags.zf)
    {
        goto L_0x00a8d7af;
    }
L_0x00a8d79a:
    // 00a8d79a  39fe                   +cmp esi, edi
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
    // 00a8d79c  7708                   -ja 0xa8d7a6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8d7a6;
    }
    // 00a8d79e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8d7a0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a8d7a2  39f8                   +cmp eax, edi
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
    // 00a8d7a4  7709                   -ja 0xa8d7af
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8d7af;
    }
L_0x00a8d7a6:
    // 00a8d7a6  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a8d7a9  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a8d7ad  75eb                   -jne 0xa8d79a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d79a;
    }
L_0x00a8d7af:
    // 00a8d7af  ff4618                 -inc dword ptr [esi + 0x18]
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))++;
    // 00a8d7b2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8d7b5  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8d7b8  e8e395ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8d7bd:
    // 00a8d7bd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8d7bf:
    // 00a8d7bf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d7c1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8d7c4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d7c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d7c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d7c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8d7c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d7c8  ff15cc26a900           -call dword ptr [0xa926cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085516) /* 0xa926cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d7ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d7d0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8d7d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d7d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d7d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d7d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8d7e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d7e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d7e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8d7e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d7e4  ff15702ba900           -call dword ptr [0xa92b70]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11086704) /* 0xa92b70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d7ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8d7ec(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d7ec  ff15742ba900           -call dword ptr [0xa92b74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11086708) /* 0xa92b74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d7f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8d7f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d7f4  ff15782ba900           -call dword ptr [0xa92b78]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11086712) /* 0xa92b78 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d7fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8d7fc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d7fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8d7fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8d7fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8d800  7410                   -je 0xa8d812
    if (cpu.flags.zf)
    {
        goto L_0x00a8d812;
    }
    // 00a8d802  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8d804  8b35702ba900           -mov esi, dword ptr [0xa92b70]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11086704) /* 0xa92b70 */);
    // 00a8d80a  890d702ba900           -mov dword ptr [0xa92b70], ecx
    app->getMemory<x86::reg32>(x86::reg32(11086704) /* 0xa92b70 */) = cpu.ecx;
    // 00a8d810  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x00a8d812:
    // 00a8d812  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8d814  740f                   -je 0xa8d825
    if (cpu.flags.zf)
    {
        goto L_0x00a8d825;
    }
    // 00a8d816  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8d818  8b0d742ba900           -mov ecx, dword ptr [0xa92b74]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11086708) /* 0xa92b74 */);
    // 00a8d81e  a3742ba900             -mov dword ptr [0xa92b74], eax
    app->getMemory<x86::reg32>(x86::reg32(11086708) /* 0xa92b74 */) = cpu.eax;
    // 00a8d823  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x00a8d825:
    // 00a8d825  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8d827  740f                   -je 0xa8d838
    if (cpu.flags.zf)
    {
        goto L_0x00a8d838;
    }
    // 00a8d829  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a8d82b  8b15782ba900           -mov edx, dword ptr [0xa92b78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11086712) /* 0xa92b78 */);
    // 00a8d831  a3782ba900             -mov dword ptr [0xa92b78], eax
    app->getMemory<x86::reg32>(x86::reg32(11086712) /* 0xa92b78 */) = cpu.eax;
    // 00a8d836  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x00a8d838:
    // 00a8d838  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d839  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d83a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a8d83c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d83c  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d83e  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d840  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8d841(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d841  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 00a8d846  e805140000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d84b  eb1d                   -jmp 0xa8d86a
    goto L_0x00a8d86a;
    // 00a8d84d  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 00a8d852  e8f9130000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d857  eb11                   -jmp 0xa8d86a
    goto L_0x00a8d86a;
    // 00a8d859  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8d85a  e8e5c9ffff             -call 0xa8a244
    cpu.esp -= 4;
    sub_a8a244(app, cpu);
    if (cpu.terminate) return;
    // 00a8d85f  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 00a8d864  e8e7130000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d869  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8d86a:
    // 00a8d86a  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00a8d86f  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00a8d874  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d876  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8d859(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8d859;
    // 00a8d841  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 00a8d846  e805140000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d84b  eb1d                   -jmp 0xa8d86a
    goto L_0x00a8d86a;
    // 00a8d84d  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 00a8d852  e8f9130000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d857  eb11                   -jmp 0xa8d86a
    goto L_0x00a8d86a;
L_entry_0x00a8d859:
    // 00a8d859  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8d85a  e8e5c9ffff             -call 0xa8a244
    cpu.esp -= 4;
    sub_a8a244(app, cpu);
    if (cpu.terminate) return;
    // 00a8d85f  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 00a8d864  e8e7130000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d869  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8d86a:
    // 00a8d86a  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00a8d86f  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00a8d874  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d876  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8d84d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8d84d;
    // 00a8d841  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 00a8d846  e805140000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d84b  eb1d                   -jmp 0xa8d86a
    goto L_0x00a8d86a;
L_entry_0x00a8d84d:
    // 00a8d84d  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 00a8d852  e8f9130000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d857  eb11                   -jmp 0xa8d86a
    goto L_0x00a8d86a;
    // 00a8d859  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8d85a  e8e5c9ffff             -call 0xa8a244
    cpu.esp -= 4;
    sub_a8a244(app, cpu);
    if (cpu.terminate) return;
    // 00a8d85f  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 00a8d864  e8e7130000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d869  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8d86a:
    // 00a8d86a  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00a8d86f  0d0000f07f             -or eax, 0x7ff00000
    cpu.eax |= x86::reg32(x86::sreg32(2146435072 /*0x7ff00000*/));
    // 00a8d874  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d876  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8d879(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d879  b883000000             -mov eax, 0x83
    cpu.eax = 131 /*0x83*/;
    // 00a8d87e  e8cd130000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d883  eb11                   -jmp 0xa8d896
    goto L_0x00a8d896;
    // 00a8d885  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8d886  e8b9c9ffff             -call 0xa8a244
    cpu.esp -= 4;
    sub_a8a244(app, cpu);
    if (cpu.terminate) return;
    // 00a8d88b  b884000000             -mov eax, 0x84
    cpu.eax = 132 /*0x84*/;
    // 00a8d890  e8bb130000             -call 0xa8ec50
    cpu.esp -= 4;
    sub_a8ec50(app, cpu);
    if (cpu.terminate) return;
    // 00a8d895  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a8d896:
    // 00a8d896  2500000080             -and eax, 0x80000000
    cpu.eax &= x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
    // 00a8d89b  0d0000807f             -or eax, 0x7f800000
    cpu.eax |= x86::reg32(x86::sreg32(2139095040 /*0x7f800000*/));
    // 00a8d8a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a8d8a2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d8a2  e9b0130000             -jmp 0xa8ec57
    return sub_a8ec57(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8d8b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d8b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8d8b1  83f803                 +cmp eax, 3
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
    // 00a8d8b4  7604                   -jbe 0xa8d8ba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8d8ba;
    }
    // 00a8d8b6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d8b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d8b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8d8ba:
    // 00a8d8ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8d8bc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a8d8bf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d8c1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a8d8c4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8d8c6  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d8c8  056023a900             -add eax, 0xa92360
    (cpu.eax) += x86::reg32(x86::sreg32(11084640 /*0xa92360*/));
    // 00a8d8cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d8ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a8d8d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d8d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8d8d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8d8d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8d8d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8d8d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8d8d5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8d8d7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8d8d9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a8d8dc  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d8e2  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a8d8e5  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00a8d8e9  7507                   -jne 0xa8d8f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d8f2;
    }
    // 00a8d8eb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8d8ed  e80eb6ffff             -call 0xa88f00
    cpu.esp -= 4;
    sub_a88f00(app, cpu);
    if (cpu.terminate) return;
L_0x00a8d8f2:
    // 00a8d8f2  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00a8d8f5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8d8f7  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a8d8fa  7415                   -je 0xa8d911
    if (cpu.flags.zf)
    {
        goto L_0x00a8d911;
    }
    // 00a8d8fc  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00a8d8fe  80e2f9                 -and dl, 0xf9
    cpu.dl &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 00a8d901  88510d                 -mov byte ptr [ecx + 0xd], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.dl;
    // 00a8d904  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 00a8d906  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00a8d909  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a8d90e  88710d                 -mov byte ptr [ecx + 0xd], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.dh;
L_0x00a8d911:
    // 00a8d911  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a8d913  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a8d915:
    // 00a8d915  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d917  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a8d919  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8d91b  740f                   -je 0xa8d92c
    if (cpu.flags.zf)
    {
        goto L_0x00a8d92c;
    }
    // 00a8d91d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8d91f  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8d920  e8bbb4ffff             -call 0xa88de0
    cpu.esp -= 4;
    sub_a88de0(app, cpu);
    if (cpu.terminate) return;
    // 00a8d925  83f8ff                 +cmp eax, -1
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
    // 00a8d928  75eb                   -jne 0xa8d915
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d915;
    }
    // 00a8d92a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00a8d92c:
    // 00a8d92c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8d92e  741d                   -je 0xa8d94d
    if (cpu.flags.zf)
    {
        goto L_0x00a8d94d;
    }
    // 00a8d930  8a410d                 -mov al, byte ptr [ecx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00a8d933  24f9                   -and al, 0xf9
    cpu.al &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 00a8d935  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 00a8d938  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00a8d93a  80cc04                 -or ah, 4
    cpu.ah |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a8d93d  88610d                 -mov byte ptr [ecx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00a8d940  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8d942  7509                   -jne 0xa8d94d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d94d;
    }
    // 00a8d944  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8d946  e835a1ffff             -call 0xa87a80
    cpu.esp -= 4;
    sub_a87a80(app, cpu);
    if (cpu.terminate) return;
    // 00a8d94b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00a8d94d:
    // 00a8d94d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8d94f  7504                   -jne 0xa8d955
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d955;
    }
    // 00a8d951  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a8d953  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a8d955:
    // 00a8d955  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8d958  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d95e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8d960  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d961  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d962  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d963  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d964  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d965  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8d970(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8d971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8d972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8d973  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8d975  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d97b  833df426a90000         +cmp dword ptr [0xa926f4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085556) /* 0xa926f4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8d982  741d                   -je 0xa8d9a1
    if (cpu.flags.zf)
    {
        goto L_0x00a8d9a1;
    }
    // 00a8d984  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d986  ff15f426a900           -call dword ptr [0xa926f4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085556) /* 0xa926f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d98c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8d98e  7411                   -je 0xa8d9a1
    if (cpu.flags.zf)
    {
        goto L_0x00a8d9a1;
    }
    // 00a8d990  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d992  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d998  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8d99d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d99e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d99f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d9a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8d9a1:
    // 00a8d9a1  a10828a900             -mov eax, dword ptr [0xa92808]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8d9a6  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00a8d9a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8d9aa  2eff15bc03a900         -call dword ptr cs:[0xa903bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076540) /* 0xa903bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d9b1  83f802                 +cmp eax, 2
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
    // 00a8d9b4  7511                   -jne 0xa8d9c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d9c7;
    }
    // 00a8d9b6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d9b8  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d9be  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8d9c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d9c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d9c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d9c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8d9c7:
    // 00a8d9c7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8d9c9  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d9cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8d9d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d9d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d9d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8d9d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8d9e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8d9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8d9e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8d9e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8d9e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8d9e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8d9e5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a8d9e8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8d9ea  83f8ff                 +cmp eax, -1
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
    // 00a8d9ed  750e                   -jne 0xa8d9fd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8d9fd;
    }
    // 00a8d9ef  2eff159403a900         -call dword ptr cs:[0xa90394]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076500) /* 0xa90394 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8d9f6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8d9f8  e998000000             -jmp 0xa8da95
    goto L_0x00a8da95;
L_0x00a8d9fd:
    // 00a8d9fd  83f8fe                 +cmp eax, -2
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
    // 00a8da00  750e                   -jne 0xa8da10
    if (!cpu.flags.zf)
    {
        goto L_0x00a8da10;
    }
    // 00a8da02  2eff15d403a900         -call dword ptr cs:[0xa903d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076564) /* 0xa903d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8da09  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8da0b  e985000000             -jmp 0xa8da95
    goto L_0x00a8da95;
L_0x00a8da10:
    // 00a8da10  83f8fd                 +cmp eax, -3
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
    // 00a8da13  7526                   -jne 0xa8da3b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8da3b;
    }
    // 00a8da15  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a8da1a  b8604aa900             -mov eax, 0xa94a60
    cpu.eax = 11094624 /*0xa94a60*/;
    // 00a8da1f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8da21  e88a90ffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8da26  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8da28  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8da2a  8915504aa900           -mov dword ptr [0xa94a50], edx
    app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */) = cpu.edx;
    // 00a8da30  89157c2ba900           -mov dword ptr [0xa92b7c], edx
    app->getMemory<x86::reg32>(x86::reg32(11086716) /* 0xa92b7c */) = cpu.edx;
    // 00a8da36  e9ff000000             -jmp 0xa8db3a
    goto L_0x00a8db3a;
L_0x00a8da3b:
    // 00a8da3b  83f8fc                 +cmp eax, -4
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
    // 00a8da3e  7555                   -jne 0xa8da95
    if (!cpu.flags.zf)
    {
        goto L_0x00a8da95;
    }
    // 00a8da40  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a8da45  b8604aa900             -mov eax, 0xa94a60
    cpu.eax = 11094624 /*0xa94a60*/;
    // 00a8da4a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8da4c  e85f90ffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8da51  b881000000             -mov eax, 0x81
    cpu.eax = 129 /*0x81*/;
    // 00a8da56  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
L_0x00a8da58:
    // 00a8da58  40                     -inc eax
    (cpu.eax)++;
    // 00a8da59  8890604aa900           -mov byte ptr [eax + 0xa94a60], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11094624) /* 0xa94a60 */) = cpu.dl;
    // 00a8da5f  3d9f000000             +cmp eax, 0x9f
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
    // 00a8da64  7ef2                   -jle 0xa8da58
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8da58;
    }
    // 00a8da66  b8e0000000             -mov eax, 0xe0
    cpu.eax = 224 /*0xe0*/;
    // 00a8da6b  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
L_0x00a8da6d:
    // 00a8da6d  40                     -inc eax
    (cpu.eax)++;
    // 00a8da6e  88b0604aa900           -mov byte ptr [eax + 0xa94a60], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11094624) /* 0xa94a60 */) = cpu.dh;
    // 00a8da74  3dfc000000             +cmp eax, 0xfc
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
    // 00a8da79  7ef2                   -jle 0xa8da6d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8da6d;
    }
    // 00a8da7b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a8da80  b8a4030000             -mov eax, 0x3a4
    cpu.eax = 932 /*0x3a4*/;
    // 00a8da85  892d504aa900           -mov dword ptr [0xa94a50], ebp
    app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */) = cpu.ebp;
    // 00a8da8b  a37c2ba900             -mov dword ptr [0xa92b7c], eax
    app->getMemory<x86::reg32>(x86::reg32(11086716) /* 0xa92b7c */) = cpu.eax;
    // 00a8da90  e9a3000000             -jmp 0xa8db38
    goto L_0x00a8db38;
L_0x00a8da95:
    // 00a8da95  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8da97  7505                   -jne 0xa8da9e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8da9e;
    }
    // 00a8da99  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00a8da9e:
    // 00a8da9e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8daa0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8daa1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8daa2  2eff159803a900         -call dword ptr cs:[0xa90398]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076504) /* 0xa90398 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8daa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8daab  750e                   -jne 0xa8dabb
    if (!cpu.flags.zf)
    {
        goto L_0x00a8dabb;
    }
    // 00a8daad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8dab2  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a8dab5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dab6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dab7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dab8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dab9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8daba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8dabb:
    // 00a8dabb  bb01010000             -mov ebx, 0x101
    cpu.ebx = 257 /*0x101*/;
    // 00a8dac0  b8604aa900             -mov eax, 0xa94a60
    cpu.eax = 11094624 /*0xa94a60*/;
    // 00a8dac5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8dac7  e8e48fffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8dacc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8dace  8a642406               -mov ah, byte ptr [esp + 6]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00a8dad2  890d504aa900           -mov dword ptr [0xa94a50], ecx
    app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */) = cpu.ecx;
    // 00a8dad8  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a8dada  740a                   -je 0xa8dae6
    if (cpu.flags.zf)
    {
        goto L_0x00a8dae6;
    }
    // 00a8dadc  c705504aa90001000000   -mov dword ptr [0xa94a50], 1
    app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */) = 1 /*0x1*/;
L_0x00a8dae6:
    // 00a8dae6  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a8dae8  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
    // 00a8daea  eb1c                   -jmp 0xa8db08
    goto L_0x00a8db08;
L_0x00a8daec:
    // 00a8daec  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8daee  8a441c06               -mov al, byte ptr [esp + ebx + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.ebx * 1);
    // 00a8daf2  eb07                   -jmp 0xa8dafb
    goto L_0x00a8dafb;
L_0x00a8daf4:
    // 00a8daf4  40                     -inc eax
    (cpu.eax)++;
    // 00a8daf5  8888604aa900           -mov byte ptr [eax + 0xa94a60], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11094624) /* 0xa94a60 */) = cpu.cl;
L_0x00a8dafb:
    // 00a8dafb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8dafd  8a541c07               -mov dl, byte ptr [esp + ebx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.ebx * 1);
    // 00a8db01  39d0                   +cmp eax, edx
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
    // 00a8db03  7eef                   -jle 0xa8daf4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8daf4;
    }
    // 00a8db05  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a8db08:
    // 00a8db08  807c1c0600             +cmp byte ptr [esp + ebx + 6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(6) /* 0x6 */ + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8db0d  75dd                   -jne 0xa8daec
    if (!cpu.flags.zf)
    {
        goto L_0x00a8daec;
    }
    // 00a8db0f  807c1c0700             +cmp byte ptr [esp + ebx + 7], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */ + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8db14  75d6                   -jne 0xa8daec
    if (!cpu.flags.zf)
    {
        goto L_0x00a8daec;
    }
    // 00a8db16  83fe01                 +cmp esi, 1
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
    // 00a8db19  7517                   -jne 0xa8db32
    if (!cpu.flags.zf)
    {
        goto L_0x00a8db32;
    }
    // 00a8db1b  2eff15d403a900         -call dword ptr cs:[0xa903d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076564) /* 0xa903d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8db22  a37c2ba900             -mov dword ptr [0xa92b7c], eax
    app->getMemory<x86::reg32>(x86::reg32(11086716) /* 0xa92b7c */) = cpu.eax;
    // 00a8db27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8db29  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a8db2c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8db32:
    // 00a8db32  89357c2ba900           -mov dword ptr [0xa92b7c], esi
    app->getMemory<x86::reg32>(x86::reg32(11086716) /* 0xa92b7c */) = cpu.esi;
L_0x00a8db38:
    // 00a8db38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8db3a:
    // 00a8db3a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00a8db3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db3e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8db42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a8db44(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8db44  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8db46  781e                   -js 0xa8db66
    if (cpu.flags.sf)
    {
        goto L_0x00a8db66;
    }
    // 00a8db48  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8db4a  7806                   -js 0xa8db52
    if (cpu.flags.sf)
    {
        goto L_0x00a8db52;
    }
    // 00a8db4c  e848000000             -call 0xa8db99
    cpu.esp -= 4;
    sub_a8db99(app, cpu);
    if (cpu.terminate) return;
    // 00a8db51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8db52:
    // 00a8db52  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a8db54  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a8db56  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8db59  e83b000000             -call 0xa8db99
    cpu.esp -= 4;
    sub_a8db99(app, cpu);
    if (cpu.terminate) return;
    // 00a8db5e  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a8db60  f7d8                   +neg eax
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
    // 00a8db62  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8db65  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8db66:
    // 00a8db66  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a8db68  f7d8                   +neg eax
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
    // 00a8db6a  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8db6d  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8db6f  7914                   -jns 0xa8db85
    if (!cpu.flags.sf)
    {
        goto L_0x00a8db85;
    }
    // 00a8db71  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a8db73  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a8db75  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8db78  e81c000000             -call 0xa8db99
    cpu.esp -= 4;
    sub_a8db99(app, cpu);
    if (cpu.terminate) return;
    // 00a8db7d  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a8db7f  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a8db81  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8db84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8db85:
    // 00a8db85  e80f000000             -call 0xa8db99
    cpu.esp -= 4;
    sub_a8db99(app, cpu);
    if (cpu.terminate) return;
    // 00a8db8a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00a8db8c  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a8db8e  83d900                 -sbb ecx, 0
    (cpu.ecx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8db91  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a8db93  f7d8                   +neg eax
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
    // 00a8db95  83da00                 -sbb edx, 0
    (cpu.edx) -= x86::reg32(x86::sreg32(0 /*0x0*/) + cpu.flags.cf);
    // 00a8db98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8db99(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8db99  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a8db9b  751a                   -jne 0xa8dbb7
    if (!cpu.flags.zf)
    {
        goto L_0x00a8dbb7;
    }
    // 00a8db9d  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8db9e  7416                   -je 0xa8dbb6
    if (cpu.flags.zf)
    {
        goto L_0x00a8dbb6;
    }
    // 00a8dba0  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8dba1  39d3                   +cmp ebx, edx
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
    // 00a8dba3  7709                   -ja 0xa8dbae
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8dbae;
    }
    // 00a8dba5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8dba7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8dba9  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8dbab  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a8dbad  91                     -xchg ecx, eax
    {
        x86::reg32 tmp = cpu.ecx;
        cpu.ecx = cpu.eax;
        cpu.eax = tmp;
    }
L_0x00a8dbae:
    // 00a8dbae  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a8dbb0  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8dbb2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8dbb4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a8dbb6:
    // 00a8dbb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8dbb7:
    // 00a8dbb7  39d1                   +cmp ecx, edx
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
    // 00a8dbb9  721c                   -jb 0xa8dbd7
    if (cpu.flags.cf)
    {
        goto L_0x00a8dbd7;
    }
    // 00a8dbbb  7512                   -jne 0xa8dbcf
    if (!cpu.flags.zf)
    {
        goto L_0x00a8dbcf;
    }
    // 00a8dbbd  39c3                   +cmp ebx, eax
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
    // 00a8dbbf  770e                   -ja 0xa8dbcf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8dbcf;
    }
    // 00a8dbc1  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8dbc3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8dbc5  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8dbc7  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8dbc9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8dbce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8dbcf:
    // 00a8dbcf  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8dbd1  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8dbd3  93                     -xchg ebx, eax
    {
        x86::reg32 tmp = cpu.ebx;
        cpu.ebx = cpu.eax;
        cpu.eax = tmp;
    }
    // 00a8dbd4  87ca                   -xchg edx, ecx
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.ecx;
        cpu.ecx = tmp;
    }
    // 00a8dbd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8dbd7:
    // 00a8dbd7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8dbd8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8dbd9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8dbda  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8dbdc  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a8dbde  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x00a8dbe0:
    // 00a8dbe0  01db                   +add ebx, ebx
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
    // 00a8dbe2  11c9                   +adc ecx, ecx
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
    // 00a8dbe4  7213                   -jb 0xa8dbf9
    if (cpu.flags.cf)
    {
        goto L_0x00a8dbf9;
    }
    // 00a8dbe6  45                     -inc ebp
    (cpu.ebp)++;
    // 00a8dbe7  39d1                   +cmp ecx, edx
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
    // 00a8dbe9  72f5                   -jb 0xa8dbe0
    if (cpu.flags.cf)
    {
        goto L_0x00a8dbe0;
    }
    // 00a8dbeb  7704                   -ja 0xa8dbf1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8dbf1;
    }
    // 00a8dbed  39c3                   +cmp ebx, eax
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
    // 00a8dbef  76ef                   -jbe 0xa8dbe0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8dbe0;
    }
L_0x00a8dbf1:
    // 00a8dbf1  f8                     +clc 
    cpu.flags.cf = 0;
L_0x00a8dbf2:
    // 00a8dbf2  11f6                   +adc esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dbf4  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dbf6  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8dbf7  7822                   -js 0xa8dc1b
    if (cpu.flags.sf)
    {
        goto L_0x00a8dc1b;
    }
L_0x00a8dbf9:
    // 00a8dbf9  d1d9                   +rcr ecx, 1
    {
        x86::reg32& op = cpu.ecx;
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
    // 00a8dbfb  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
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
    // 00a8dbfd  29d8                   +sub eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dbff  19ca                   +sbb edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dc01  f5                     +cmc 
    cpu.flags.cf ^= 1;
    // 00a8dc02  72ee                   -jb 0xa8dbf2
    if (cpu.flags.cf)
    {
        goto L_0x00a8dbf2;
    }
L_0x00a8dc04:
    // 00a8dc04  01f6                   +add esi, esi
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dc06  11ff                   +adc edi, edi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dc08  4d                     +dec ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8dc09  780c                   -js 0xa8dc17
    if (cpu.flags.sf)
    {
        goto L_0x00a8dc17;
    }
    // 00a8dc0b  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8dc0d  d1db                   -rcr ebx, 1
    {
        x86::reg32& op = cpu.ebx;
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
    // 00a8dc0f  01d8                   +add eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dc11  11ca                   +adc edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dc13  73ef                   -jae 0xa8dc04
    if (!cpu.flags.cf)
    {
        goto L_0x00a8dc04;
    }
    // 00a8dc15  ebdb                   -jmp 0xa8dbf2
    goto L_0x00a8dbf2;
L_0x00a8dc17:
    // 00a8dc17  01d8                   +add eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8dc19  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
L_0x00a8dc1b:
    // 00a8dc1b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8dc1d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8dc1f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8dc21  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a8dc23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc25  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8dc30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8dc30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8dc31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8dc32  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8dc34  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8dc35  2eff15b803a900         -call dword ptr cs:[0xa903b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076536) /* 0xa903b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8dc3c  83f8ff                 +cmp eax, -1
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
    // 00a8dc3f  7508                   -jne 0xa8dc49
    if (!cpu.flags.zf)
    {
        goto L_0x00a8dc49;
    }
    // 00a8dc41  e85ee4ffff             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8dc46  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8dc49:
    // 00a8dc49  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a8dc4c  7411                   -je 0xa8dc5f
    if (cpu.flags.zf)
    {
        goto L_0x00a8dc5f;
    }
    // 00a8dc4e  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00a8dc50  740d                   -je 0xa8dc5f
    if (cpu.flags.zf)
    {
        goto L_0x00a8dc5f;
    }
    // 00a8dc52  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a8dc57  e8e0e3ffff             -call 0xa8c03c
    cpu.esp -= 4;
    sub_a8c03c(app, cpu);
    if (cpu.terminate) return;
    // 00a8dc5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc5d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc5e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8dc5f:
    // 00a8dc5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8dc61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dc63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8dc70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8dc70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8dc71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8dc72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8dc73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8dc74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8dc75  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8dc78  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8dc7a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8dc7c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8dc81  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8dc83  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8dc85  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8dc87  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a8dc8a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8dc8c  740e                   -je 0xa8dc9c
    if (cpu.flags.zf)
    {
        goto L_0x00a8dc9c;
    }
    // 00a8dc8e  3b15102ca900           +cmp edx, dword ptr [0xa92c10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11086864) /* 0xa92c10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8dc94  7504                   -jne 0xa8dc9a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8dc9a;
    }
    // 00a8dc96  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a8dc98  eb02                   -jmp 0xa8dc9c
    goto L_0x00a8dc9c;
L_0x00a8dc9a:
    // 00a8dc9a  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
L_0x00a8dc9c:
    // 00a8dc9c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a8dc9e  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8dca0  7208                   -jb 0xa8dcaa
    if (cpu.flags.cf)
    {
        goto L_0x00a8dcaa;
    }
    // 00a8dca2  760c                   -jbe 0xa8dcb0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8dcb0;
    }
    // 00a8dca4  3c77                   +cmp al, 0x77
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8dca6  740d                   -je 0xa8dcb5
    if (cpu.flags.zf)
    {
        goto L_0x00a8dcb5;
    }
    // 00a8dca8  eb15                   -jmp 0xa8dcbf
    goto L_0x00a8dcbf;
L_0x00a8dcaa:
    // 00a8dcaa  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8dcac  740c                   -je 0xa8dcba
    if (cpu.flags.zf)
    {
        goto L_0x00a8dcba;
    }
    // 00a8dcae  eb0f                   -jmp 0xa8dcbf
    goto L_0x00a8dcbf;
L_0x00a8dcb0:
    // 00a8dcb0  80cb01                 +or bl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a8dcb3  eb1b                   -jmp 0xa8dcd0
    goto L_0x00a8dcd0;
L_0x00a8dcb5:
    // 00a8dcb5  80cb02                 +or bl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a8dcb8  eb16                   -jmp 0xa8dcd0
    goto L_0x00a8dcd0;
L_0x00a8dcba:
    // 00a8dcba  80cb82                 +or bl, 0x82
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(130 /*0x82*/))));
    // 00a8dcbd  eb11                   -jmp 0xa8dcd0
    goto L_0x00a8dcd0;
L_0x00a8dcbf:
    // 00a8dcbf  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a8dcc4  e857c5ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8dcc9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8dccb  e9cf000000             -jmp 0xa8dd9f
    goto L_0x00a8dd9f;
L_0x00a8dcd0:
    // 00a8dcd0  8a6101                 -mov ah, byte ptr [ecx + 1]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a8dcd3  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8dcd4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a8dcd6  0f84ae000000           -je 0xa8dd8a
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd8a;
    }
L_0x00a8dcdc:
    // 00a8dcdc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8dcde  0f84a6000000           -je 0xa8dd8a
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd8a;
    }
    // 00a8dce4  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a8dce6  3c63                   +cmp al, 0x63
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
    // 00a8dce8  721d                   -jb 0xa8dd07
    if (cpu.flags.cf)
    {
        goto L_0x00a8dd07;
    }
    // 00a8dcea  0f8665000000           -jbe 0xa8dd55
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8dd55;
    }
    // 00a8dcf0  3c6e                   +cmp al, 0x6e
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
    // 00a8dcf2  0f8286000000           -jb 0xa8dd7e
    if (cpu.flags.cf)
    {
        goto L_0x00a8dd7e;
    }
    // 00a8dcf8  0f866c000000           -jbe 0xa8dd6a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8dd6a;
    }
    // 00a8dcfe  3c74                   +cmp al, 0x74
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(116 /*0x74*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8dd00  7432                   -je 0xa8dd34
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd34;
    }
    // 00a8dd02  e977000000             -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd07:
    // 00a8dd07  3c2b                   +cmp al, 0x2b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8dd09  0f826f000000           -jb 0xa8dd7e
    if (cpu.flags.cf)
    {
        goto L_0x00a8dd7e;
    }
    // 00a8dd0f  7609                   -jbe 0xa8dd1a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8dd1a;
    }
    // 00a8dd11  3c62                   +cmp al, 0x62
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(98 /*0x62*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8dd13  742e                   -je 0xa8dd43
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd43;
    }
    // 00a8dd15  e964000000             -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd1a:
    // 00a8dd1a  833c2400               +cmp dword ptr [esp], 0
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
    // 00a8dd1e  7407                   -je 0xa8dd27
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd27;
    }
    // 00a8dd20  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8dd22  e957000000             -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd27:
    // 00a8dd27  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8dd2c  80cb03                 +or bl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8dd2f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8dd32  eb4a                   -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd34:
    // 00a8dd34  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8dd36  7404                   -je 0xa8dd3c
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd3c;
    }
    // 00a8dd38  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8dd3a  eb42                   -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd3c:
    // 00a8dd3c  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a8dd41  eb3b                   -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd43:
    // 00a8dd43  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8dd45  7404                   -je 0xa8dd4b
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd4b;
    }
    // 00a8dd47  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8dd49  eb33                   -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd4b:
    // 00a8dd4b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a8dd50  80cb40                 +or bl, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00a8dd53  eb29                   -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd55:
    // 00a8dd55  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8dd57  7404                   -je 0xa8dd5d
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd5d;
    }
    // 00a8dd59  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8dd5b  eb21                   -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd5d:
    // 00a8dd5d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8dd5f  0c01                   +or al, 1
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a8dd61  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a8dd66  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a8dd68  eb14                   -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd6a:
    // 00a8dd6a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8dd6c  7404                   -je 0xa8dd72
    if (cpu.flags.zf)
    {
        goto L_0x00a8dd72;
    }
    // 00a8dd6e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8dd70  eb0c                   -jmp 0xa8dd7e
    goto L_0x00a8dd7e;
L_0x00a8dd72:
    // 00a8dd72  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8dd74  80e4fe                 -and ah, 0xfe
    cpu.ah &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a8dd77  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00a8dd7c  8826                   -mov byte ptr [esi], ah
    app->getMemory<x86::reg8>(cpu.esi) = cpu.ah;
L_0x00a8dd7e:
    // 00a8dd7e  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a8dd81  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8dd82  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a8dd84  0f8552ffffff           -jne 0xa8dcdc
    if (!cpu.flags.zf)
    {
        goto L_0x00a8dcdc;
    }
L_0x00a8dd8a:
    // 00a8dd8a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8dd8c  750f                   -jne 0xa8dd9d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8dd9d;
    }
    // 00a8dd8e  813d6c25a90000020000   +cmp dword ptr [0xa9256c], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085164) /* 0xa9256c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8dd98  7503                   -jne 0xa8dd9d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8dd9d;
    }
    // 00a8dd9a  80cb40                 -or bl, 0x40
    cpu.bl |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a8dd9d:
    // 00a8dd9d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x00a8dd9f:
    // 00a8dd9f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8dda1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8dda4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dda5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dda6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dda7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dda8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dda9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8ddac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ddac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8ddad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ddae  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8ddaf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8ddb1  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a8ddb3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8ddb5  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8ddb9  80610cfc               -and byte ptr [ecx + 0xc], 0xfc
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a8ddbd  09590c                 -or dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8ddc0  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8ddc5  e8a60e0000             -call 0xa8ec70
    cpu.esp -= 4;
    sub_a8ec70(app, cpu);
    if (cpu.terminate) return;
    // 00a8ddca  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8ddcc  7522                   -jne 0xa8ddf0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ddf0;
    }
    // 00a8ddce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8ddd0  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a8ddd3  7405                   -je 0xa8ddda
    if (cpu.flags.zf)
    {
        goto L_0x00a8ddda;
    }
    // 00a8ddd5  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00a8ddda:
    // 00a8ddda  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a8dddd  7405                   -je 0xa8dde4
    if (cpu.flags.zf)
    {
        goto L_0x00a8dde4;
    }
    // 00a8dddf  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a8dde2  eb03                   -jmp 0xa8dde7
    goto L_0x00a8dde7;
L_0x00a8dde4:
    // 00a8dde4  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x00a8dde7:
    // 00a8dde7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8dde9  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8dded  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ddee  eb30                   -jmp 0xa8de20
    goto L_0x00a8de20;
L_0x00a8ddf0:
    // 00a8ddf0  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a8ddf3  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a8ddf6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8ddfb  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
    // 00a8ddfe  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a8de01  7404                   -je 0xa8de07
    if (cpu.flags.zf)
    {
        goto L_0x00a8de07;
    }
    // 00a8de03  0c10                   +or al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00a8de05  eb02                   -jmp 0xa8de09
    goto L_0x00a8de09;
L_0x00a8de07:
    // 00a8de07  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a8de09:
    // 00a8de09  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a8de0c  7405                   -je 0xa8de13
    if (cpu.flags.zf)
    {
        goto L_0x00a8de13;
    }
    // 00a8de0e  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a8de11  eb03                   -jmp 0xa8de16
    goto L_0x00a8de16;
L_0x00a8de13:
    // 00a8de13  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00a8de16:
    // 00a8de16  6880010000             -push 0x180
    app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 00a8de1b  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8de1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00a8de20:
    // 00a8de20  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8de21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8de22  e87d0e0000             -call 0xa8eca4
    cpu.esp -= 4;
    sub_a8eca4(app, cpu);
    if (cpu.terminate) return;
    // 00a8de27  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8de2a  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a8de2d  837910ff               +cmp dword ptr [ecx + 0x10], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8de31  750b                   -jne 0xa8de3e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8de3e;
    }
    // 00a8de33  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8de35  e8aac0ffff             -call 0xa89ee4
    cpu.esp -= 4;
    sub_a89ee4(app, cpu);
    if (cpu.terminate) return;
    // 00a8de3a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8de3c  eb4e                   -jmp 0xa8de8c
    goto L_0x00a8de8c;
L_0x00a8de3e:
    // 00a8de3e  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a8de45  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8de48  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a8de4f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a8de56  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8de59  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a8de5c  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8de5f  c7401500000000         -mov dword ptr [eax + 0x15], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 00a8de66  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8de69  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a8de70  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a8de73  740e                   -je 0xa8de83
    if (cpu.flags.zf)
    {
        goto L_0x00a8de83;
    }
    // 00a8de75  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a8de7a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8de7c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8de7e  e8d5100000             -call 0xa8ef58
    cpu.esp -= 4;
    sub_a8ef58(app, cpu);
    if (cpu.terminate) return;
L_0x00a8de83:
    // 00a8de83  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8de85  e886dbffff             -call 0xa8ba10
    cpu.esp -= 4;
    sub_a8ba10(app, cpu);
    if (cpu.terminate) return;
    // 00a8de8a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a8de8c:
    // 00a8de8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8de8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8de8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8de8f  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8de94(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8de94  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8de95  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8de96  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8de97  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8de9a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8de9c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8de9e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8dea0  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a8dea2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8dea4  e8c7fdffff             -call 0xa8dc70
    cpu.esp -= 4;
    sub_a8dc70(app, cpu);
    if (cpu.terminate) return;
    // 00a8dea9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8deab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8dead  7422                   -je 0xa8ded1
    if (cpu.flags.zf)
    {
        goto L_0x00a8ded1;
    }
    // 00a8deaf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8deb1  e86abfffff             -call 0xa89e20
    cpu.esp -= 4;
    sub_a89e20(app, cpu);
    if (cpu.terminate) return;
    // 00a8deb6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8deb8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8deba  7413                   -je 0xa8decf
    if (cpu.flags.zf)
    {
        goto L_0x00a8decf;
    }
    // 00a8debc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8debd  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8debf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8dec0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8dec2  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a8dec4  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8dec8  e8dffeffff             -call 0xa8ddac
    cpu.esp -= 4;
    sub_a8ddac(app, cpu);
    if (cpu.terminate) return;
    // 00a8decd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a8decf:
    // 00a8decf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a8ded1:
    // 00a8ded1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8ded4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ded5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ded6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ded7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8ded8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ded8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ded9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8dedb  e8b4ffffff             -call 0xa8de94
    cpu.esp -= 4;
    sub_a8de94(app, cpu);
    if (cpu.terminate) return;
    // 00a8dee0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dee1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8dee4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8dee4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8dee5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8dee6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8dee7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8dee9  ff15bc26a900           -call dword ptr [0xa926bc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085500) /* 0xa926bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8deef  a1b037a900             -mov eax, dword ptr [0xa937b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */);
    // 00a8def4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8def6  742b                   -je 0xa8df23
    if (cpu.flags.zf)
    {
        goto L_0x00a8df23;
    }
L_0x00a8def8:
    // 00a8def8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a8defb  39d3                   +cmp ebx, edx
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
    // 00a8defd  751e                   -jne 0xa8df1d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8df1d;
    }
    // 00a8deff  f6420c03               +test byte ptr [edx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00a8df03  740c                   -je 0xa8df11
    if (cpu.flags.zf)
    {
        goto L_0x00a8df11;
    }
    // 00a8df05  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8df0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8df0c  e853c1ffff             -call 0xa8a064
    cpu.esp -= 4;
    sub_a8a064(app, cpu);
    if (cpu.terminate) return;
L_0x00a8df11:
    // 00a8df11  ff15c026a900           -call dword ptr [0xa926c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8df17  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8df19  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df1a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df1b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8df1d:
    // 00a8df1d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8df1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8df21  75d5                   -jne 0xa8def8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8def8;
    }
L_0x00a8df23:
    // 00a8df23  bab437a900             -mov edx, 0xa937b4
    cpu.edx = 11089844 /*0xa937b4*/;
L_0x00a8df28:
    // 00a8df28  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8df2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8df2c  7426                   -je 0xa8df54
    if (cpu.flags.zf)
    {
        goto L_0x00a8df54;
    }
    // 00a8df2e  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00a8df31  751d                   -jne 0xa8df50
    if (!cpu.flags.zf)
    {
        goto L_0x00a8df50;
    }
    // 00a8df33  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a8df35  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a8df37  8b15b037a900           -mov edx, dword ptr [0xa937b0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */);
    // 00a8df3d  a3b037a900             -mov dword ptr [0xa937b0], eax
    app->getMemory<x86::reg32>(x86::reg32(11089840) /* 0xa937b0 */) = cpu.eax;
    // 00a8df42  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8df44  ff15c026a900           -call dword ptr [0xa926c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8df4a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8df4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8df50:
    // 00a8df50  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8df52  ebd4                   -jmp 0xa8df28
    goto L_0x00a8df28;
L_0x00a8df54:
    // 00a8df54  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8df59  e8c2c2ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8df5e  ff15c026a900           -call dword ptr [0xa926c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085504) /* 0xa926c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8df64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8df66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8df69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8df6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8df6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8df6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8df6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8df6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8df70  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8df73  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8df75  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8df77  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a8df79  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8df7b  e8f0fcffff             -call 0xa8dc70
    cpu.esp -= 4;
    sub_a8dc70(app, cpu);
    if (cpu.terminate) return;
    // 00a8df80  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8df82  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8df84  7455                   -je 0xa8dfdb
    if (cpu.flags.zf)
    {
        goto L_0x00a8dfdb;
    }
    // 00a8df86  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00a8df89  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8df8b  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8df91  833df826a90000         +cmp dword ptr [0xa926f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085560) /* 0xa926f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8df98  7408                   -je 0xa8dfa2
    if (cpu.flags.zf)
    {
        goto L_0x00a8dfa2;
    }
    // 00a8df9a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8df9c  ff15f826a900           -call dword ptr [0xa926f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085560) /* 0xa926f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a8dfa2:
    // 00a8dfa2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8dfa4  e83bffffff             -call 0xa8dee4
    cpu.esp -= 4;
    sub_a8dee4(app, cpu);
    if (cpu.terminate) return;
    // 00a8dfa9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8dfab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8dfad  7422                   -je 0xa8dfd1
    if (cpu.flags.zf)
    {
        goto L_0x00a8dfd1;
    }
    // 00a8dfaf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8dfb0  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a8dfb3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8dfb5  81e300400000           -and ebx, 0x4000
    cpu.ebx &= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 00a8dfbb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8dfbd  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a8dfc0  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a8dfc2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8dfc4  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00a8dfc6  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8dfca  e8ddfdffff             -call 0xa8ddac
    cpu.esp -= 4;
    sub_a8ddac(app, cpu);
    if (cpu.terminate) return;
    // 00a8dfcf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a8dfd1:
    // 00a8dfd1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8dfd3  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8dfd9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a8dfdb:
    // 00a8dfdb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8dfde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dfdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dfe0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dfe1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8dfe2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8dff0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8dff0  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8dff6  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8dff9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8dffc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8dffc  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e002  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8e005  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e010(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e010  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e011  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e012  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8e013  2eff15f003a900         -call dword ptr cs:[0xa903f0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076592) /* 0xa903f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e01a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e01c  7507                   -jne 0xa8e025
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e025;
    }
    // 00a8e01e  e881e0ffff             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8e023  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e024  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e025:
    // 00a8e025  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e027  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e028  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e030(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e033  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e036  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8e038  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8e03a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e03c  7525                   -jne 0xa8e063
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e063;
    }
    // 00a8e03e  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 00a8e043  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8e045  e8668cffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e04a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8e04c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e04e  7511                   -jne 0xa8e061
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e061;
    }
    // 00a8e050  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a8e055  e8c6c1ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8e05a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8e05c  e974000000             -jmp 0xa8e0d5
    goto L_0x00a8e0d5;
L_0x00a8e061:
    // 00a8e061  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00a8e063:
    // 00a8e063  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8e065  7405                   -je 0xa8e06c
    if (cpu.flags.zf)
    {
        goto L_0x00a8e06c;
    }
    // 00a8e067  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e06a  7510                   -jne 0xa8e07c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e07c;
    }
L_0x00a8e06c:
    // 00a8e06c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8e06e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8e070  e86b000000             -call 0xa8e0e0
    cpu.esp -= 4;
    sub_a8e0e0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e075  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e078  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e079  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e07a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e07b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e07c:
    // 00a8e07c  bac01ea900             -mov edx, 0xa91ec0
    cpu.edx = 11083456 /*0xa91ec0*/;
    // 00a8e081  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e083  e848100000             -call 0xa8f0d0
    cpu.esp -= 4;
    sub_a8f0d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e088  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e08a  7528                   -jne 0xa8e0b4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e0b4;
    }
    // 00a8e08c  83fb04                 +cmp ebx, 4
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
    // 00a8e08f  731a                   -jae 0xa8e0ab
    if (!cpu.flags.cf)
    {
        goto L_0x00a8e0ab;
    }
    // 00a8e091  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8e093  e8088dffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e098  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a8e09d  e87ec1ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8e0a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e0a4  83c404                 +add esp, 4
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
    // 00a8e0a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e0ab:
    // 00a8e0ab  a1c01ea900             -mov eax, dword ptr [0xa91ec0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11083456) /* 0xa91ec0 */);
    // 00a8e0b0  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a8e0b2  eb1f                   -jmp 0xa8e0d3
    goto L_0x00a8e0d3;
L_0x00a8e0b4:
    // 00a8e0b4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8e0b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8e0b7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e0b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e0b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e0ba  2eff15c003a900         -call dword ptr cs:[0xa903c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076544) /* 0xa903c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e0c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e0c3  750e                   -jne 0xa8e0d3
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e0d3;
    }
    // 00a8e0c5  e8dadfffff             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8e0ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e0cc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e0cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e0d3:
    // 00a8e0d3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a8e0d5:
    // 00a8e0d5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e0d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e0db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8e0e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e0e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e0e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e0e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e0e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e0e4  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a8e0ea  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8e0ec  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8e0ee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8e0f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8e0f1  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a8e0f6  2eff15a403a900         -call dword ptr cs:[0xa903a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076516) /* 0xa903a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e0fd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8e0ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e101  7509                   -jne 0xa8e10c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e10c;
    }
    // 00a8e103  e89cdfffff             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8e108  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8e10a  eb65                   -jmp 0xa8e171
    goto L_0x00a8e171;
L_0x00a8e10c:
    // 00a8e10c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8e10e  7529                   -jne 0xa8e139
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e139;
    }
    // 00a8e110  40                     -inc eax
    (cpu.eax)++;
    // 00a8e111  39c6                   +cmp esi, eax
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
    // 00a8e113  7602                   -jbe 0xa8e117
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8e117;
    }
    // 00a8e115  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a8e117:
    // 00a8e117  e8948bffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e11c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8e11e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e120  7532                   -jne 0xa8e154
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e154;
    }
    // 00a8e122  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a8e127  e8f4c0ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8e12c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e12e  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a8e134  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e135  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e136  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e137  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e138  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e139:
    // 00a8e139  39f0                   +cmp eax, esi
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
    // 00a8e13b  7617                   -jbe 0xa8e154
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8e154;
    }
    // 00a8e13d  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a8e142  e8d9c0ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8e147  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e149  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a8e14f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e150  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e151  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e152  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e153  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e154:
    // 00a8e154  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00a8e156  41                     -inc ecx
    (cpu.ecx)++;
    // 00a8e157  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a8e159  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8e15a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8e15c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8e15e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e15f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e161  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8e164  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8e166  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8e168  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8e16b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8e16d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e16e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8e16f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a8e171:
    // 00a8e171  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a8e177  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e178  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e179  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e17a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e17b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8e180(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e181  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e182  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e183  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8e185  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e187  7c08                   -jl 0xa8e191
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8e191;
    }
    // 00a8e189  3b05042aa900           +cmp eax, dword ptr [0xa92a04]
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
    // 00a8e18f  7613                   -jbe 0xa8e1a4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8e1a4;
    }
L_0x00a8e191:
    // 00a8e191  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8e196  e885c0ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8e19b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e1a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e1a4:
    // 00a8e1a4  8b150828a900           -mov edx, dword ptr [0xa92808]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11085832) /* 0xa92808 */);
    // 00a8e1aa  8b149a                 -mov edx, dword ptr [edx + ebx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 00a8e1ad  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e1b3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8e1b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8e1b7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8e1b9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e1ba  2eff150804a900         -call dword ptr cs:[0xa90408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076616) /* 0xa90408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e1c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8e1c3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8e1c5  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e1cb  83faff                 +cmp edx, -1
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
    // 00a8e1ce  7505                   -jne 0xa8e1d5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e1d5;
    }
    // 00a8e1d0  e8cfdeffff             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
L_0x00a8e1d5:
    // 00a8e1d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8e1d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e1e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e1e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e1e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e1e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8e1e3  2eff157803a900         -call dword ptr cs:[0xa90378]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076472) /* 0xa90378 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e1ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e1ec  7508                   -jne 0xa8e1f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e1f6;
    }
    // 00a8e1ee  e8b1deffff             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8e1f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e1f6:
    // 00a8e1f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e1f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e1fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e200(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e200  ff15802ba900           -call dword ptr [0xa92b80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11086720) /* 0xa92b80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e206  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a8e208  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e209  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a8e20e  b8c41ea900             -mov eax, 0xa91ec4
    cpu.eax = 11083460 /*0xa91ec4*/;
    // 00a8e213  e8e4bbffff             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
    // 00a8e218  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e219  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8e208(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a8e208;
    // 00a8e200  ff15802ba900           -call dword ptr [0xa92b80]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11086720) /* 0xa92b80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e206  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00a8e208:
    // 00a8e208  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e209  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a8e20e  b8c41ea900             -mov eax, 0xa91ec4
    cpu.eax = 11083460 /*0xa91ec4*/;
    // 00a8e213  e8e4bbffff             -call 0xa89dfc
    cpu.esp -= 4;
    sub_a89dfc(app, cpu);
    if (cpu.terminate) return;
    // 00a8e218  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e219  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e222  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e223  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e224  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e227  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8e229  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8e22b  8a258c26a900           -mov ah, byte ptr [0xa9268c]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(11085452) /* 0xa9268c */);
    // 00a8e231  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00a8e234  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a8e236  7426                   -je 0xa8e25e
    if (cpu.flags.zf)
    {
        goto L_0x00a8e25e;
    }
    // 00a8e238  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a8e23a  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a8e23d  9b                     -wait 
    /*nothing*/;
    // 00a8e23e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8e240  741c                   -je 0xa8e25e
    if (cpu.flags.zf)
    {
        goto L_0x00a8e25e;
    }
    // 00a8e242  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8e244  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8e247  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00a8e249  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8e24b  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8e24d  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8e24f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a8e251  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8e254  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 00a8e257  9b                     -wait 
    /*nothing*/;
    // 00a8e258  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a8e25a  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a8e25d  9b                     -wait 
    /*nothing*/;
L_0x00a8e25e:
    // 00a8e25e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e260  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 00a8e264  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e267  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e268  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e269  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e26a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e26b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8e270(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e271  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e272  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8e274  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8e276  740f                   -je 0xa8e287
    if (cpu.flags.zf)
    {
        goto L_0x00a8e287;
    }
L_0x00a8e278:
    // 00a8e278  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e27b  740a                   -je 0xa8e287
    if (cpu.flags.zf)
    {
        goto L_0x00a8e287;
    }
    // 00a8e27d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8e27e  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8e280  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8e281  8848ff                 -mov byte ptr [eax - 1], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.cl;
    // 00a8e284  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8e285  75f1                   -jne 0xa8e278
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e278;
    }
L_0x00a8e287:
    // 00a8e287  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a8e289:
    // 00a8e289  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8e28b  7407                   -je 0xa8e294
    if (cpu.flags.zf)
    {
        goto L_0x00a8e294;
    }
    // 00a8e28d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8e28e  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a8e28f  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a8e292  ebf5                   -jmp 0xa8e289
    goto L_0x00a8e289;
L_0x00a8e294:
    // 00a8e294  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8e296  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e297  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e298  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e2a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e2a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e2a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e2a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8e2a3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8e2a6  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a8e2aa  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8e2ae  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a8e2b0  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a8e2b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8e2b6  7402                   -je 0xa8e2ba
    if (cpu.flags.zf)
    {
        goto L_0x00a8e2ba;
    }
    // 00a8e2b8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a8e2ba:
    // 00a8e2ba  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00a8e2be:
    // 00a8e2be  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8e2c0  fec0                   -inc al
    (cpu.al)++;
    // 00a8e2c2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8e2c7  f6807825a90002         +test byte ptr [eax + 0xa92578], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11085176) /* 0xa92578 */) & 2 /*0x2*/));
    // 00a8e2ce  7403                   -je 0xa8e2d3
    if (cpu.flags.zf)
    {
        goto L_0x00a8e2d3;
    }
    // 00a8e2d0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8e2d1  ebeb                   -jmp 0xa8e2be
    goto L_0x00a8e2be;
L_0x00a8e2d3:
    // 00a8e2d3  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8e2d5  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e2d8  7405                   -je 0xa8e2df
    if (cpu.flags.zf)
    {
        goto L_0x00a8e2df;
    }
    // 00a8e2da  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e2dd  7501                   -jne 0xa8e2e0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e2e0;
    }
L_0x00a8e2df:
    // 00a8e2df  42                     -inc edx
    (cpu.edx)++;
L_0x00a8e2e0:
    // 00a8e2e0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8e2e2  752c                   -jne 0xa8e310
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e310;
    }
    // 00a8e2e4  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e2e7  7514                   -jne 0xa8e2fd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e2fd;
    }
    // 00a8e2e9  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a8e2ec  80f978                 +cmp cl, 0x78
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e2ef  7405                   -je 0xa8e2f6
    if (cpu.flags.zf)
    {
        goto L_0x00a8e2f6;
    }
    // 00a8e2f1  80f958                 +cmp cl, 0x58
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e2f4  7507                   -jne 0xa8e2fd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e2fd;
    }
L_0x00a8e2f6:
    // 00a8e2f6  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00a8e2fb  eb33                   -jmp 0xa8e330
    goto L_0x00a8e330;
L_0x00a8e2fd:
    // 00a8e2fd  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e300  7507                   -jne 0xa8e309
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e309;
    }
    // 00a8e302  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00a8e307  eb3c                   -jmp 0xa8e345
    goto L_0x00a8e345;
L_0x00a8e309:
    // 00a8e309  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00a8e30e  eb35                   -jmp 0xa8e345
    goto L_0x00a8e345;
L_0x00a8e310:
    // 00a8e310  83fe02                 +cmp esi, 2
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
    // 00a8e313  7c05                   -jl 0xa8e31a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8e31a;
    }
    // 00a8e315  83fe24                 +cmp esi, 0x24
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e318  7e11                   -jle 0xa8e32b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a8e32b;
    }
L_0x00a8e31a:
    // 00a8e31a  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a8e31f  e8fcbeffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8e324  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8e326  e9c1000000             -jmp 0xa8e3ec
    goto L_0x00a8e3ec;
L_0x00a8e32b:
    // 00a8e32b  83fe10                 +cmp esi, 0x10
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
    // 00a8e32e  7515                   -jne 0xa8e345
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e345;
    }
L_0x00a8e330:
    // 00a8e330  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e333  7510                   -jne 0xa8e345
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e345;
    }
    // 00a8e335  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a8e338  80ff78                 +cmp bh, 0x78
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e33b  7405                   -je 0xa8e342
    if (cpu.flags.zf)
    {
        goto L_0x00a8e342;
    }
    // 00a8e33d  80ff58                 +cmp bh, 0x58
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e340  7503                   -jne 0xa8e345
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e345;
    }
L_0x00a8e342:
    // 00a8e342  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a8e345:
    // 00a8e345  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a8e348  8d2cb500000000         -lea ebp, [esi*4]
    cpu.ebp = x86::reg32(cpu.esi * 4);
    // 00a8e34f  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a8e351  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8e353:
    // 00a8e353  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e355  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8e357  e8b4000000             -call 0xa8e410
    cpu.esp -= 4;
    sub_a8e410(app, cpu);
    if (cpu.terminate) return;
    // 00a8e35c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8e35e  39f0                   +cmp eax, esi
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
    // 00a8e360  7d1a                   -jge 0xa8e37c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8e37c;
    }
    // 00a8e362  3b9d7c2ba900           +cmp ebx, dword ptr [ebp + 0xa92b7c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(11086716) /* 0xa92b7c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e368  7602                   -jbe 0xa8e36c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8e36c;
    }
    // 00a8e36a  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a8e36c:
    // 00a8e36c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8e36e  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00a8e371  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a8e373  39c3                   +cmp ebx, eax
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
    // 00a8e375  7302                   -jae 0xa8e379
    if (!cpu.flags.cf)
    {
        goto L_0x00a8e379;
    }
    // 00a8e377  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a8e379:
    // 00a8e379  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8e37a  ebd7                   -jmp 0xa8e353
    goto L_0x00a8e353;
L_0x00a8e37c:
    // 00a8e37c  3b1424                 +cmp edx, dword ptr [esp]
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
    // 00a8e37f  7504                   -jne 0xa8e385
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e385;
    }
    // 00a8e381  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00a8e385:
    // 00a8e385  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8e389  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8e38b  7402                   -je 0xa8e38f
    if (cpu.flags.zf)
    {
        goto L_0x00a8e38f;
    }
    // 00a8e38d  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x00a8e38f:
    // 00a8e38f  837c240801             +cmp dword ptr [esp + 8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e394  750f                   -jne 0xa8e3a5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e3a5;
    }
    // 00a8e396  81fb00000080           +cmp ebx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e39c  7207                   -jb 0xa8e3a5
    if (cpu.flags.cf)
    {
        goto L_0x00a8e3a5;
    }
    // 00a8e39e  7509                   -jne 0xa8e3a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e3a9;
    }
    // 00a8e3a0  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e3a3  7504                   -jne 0xa8e3a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e3a9;
    }
L_0x00a8e3a5:
    // 00a8e3a5  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a8e3a7  743a                   -je 0xa8e3e3
    if (cpu.flags.zf)
    {
        goto L_0x00a8e3e3;
    }
L_0x00a8e3a9:
    // 00a8e3a9  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a8e3ae  e86dbeffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8e3b3  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a8e3b8  750c                   -jne 0xa8e3c6
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e3c6;
    }
    // 00a8e3ba  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e3bf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8e3c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e3c6:
    // 00a8e3c6  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e3c9  750c                   -jne 0xa8e3d7
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e3d7;
    }
    // 00a8e3cb  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 00a8e3d0  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8e3d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e3d7:
    // 00a8e3d7  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 00a8e3dc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8e3df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e3e3:
    // 00a8e3e3  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e3e6  7502                   -jne 0xa8e3ea
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e3ea;
    }
    // 00a8e3e8  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x00a8e3ea:
    // 00a8e3ea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a8e3ec:
    // 00a8e3ec  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8e3ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8e3f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e3f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e3f5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8e3f7  e8a4feffff             -call 0xa8e2a0
    cpu.esp -= 4;
    sub_a8e2a0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e3fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e3fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8e400(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e400  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e401  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a8e406  e895feffff             -call 0xa8e2a0
    cpu.esp -= 4;
    sub_a8e2a0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e40b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e40c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8e410(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e410  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e411  3c30                   +cmp al, 0x30
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
    // 00a8e413  720e                   -jb 0xa8e423
    if (cpu.flags.cf)
    {
        goto L_0x00a8e423;
    }
    // 00a8e415  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e417  770a                   -ja 0xa8e423
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8e423;
    }
    // 00a8e419  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8e41e  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a8e421  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e422  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e423:
    // 00a8e423  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8e428  e843080000             -call 0xa8ec70
    cpu.esp -= 4;
    sub_a8ec70(app, cpu);
    if (cpu.terminate) return;
    // 00a8e42d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8e42f  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e431  720d                   -jb 0xa8e440
    if (cpu.flags.cf)
    {
        goto L_0x00a8e440;
    }
    // 00a8e433  3c69                   +cmp al, 0x69
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
    // 00a8e435  7709                   -ja 0xa8e440
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8e440;
    }
    // 00a8e437  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e439  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a8e43b  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a8e43e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e43f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e440:
    // 00a8e440  3c6a                   +cmp al, 0x6a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(106 /*0x6a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e442  720e                   -jb 0xa8e452
    if (cpu.flags.cf)
    {
        goto L_0x00a8e452;
    }
    // 00a8e444  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e446  770a                   -ja 0xa8e452
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8e452;
    }
    // 00a8e448  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8e44d  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a8e450  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e451  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e452:
    // 00a8e452  3c73                   +cmp al, 0x73
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
    // 00a8e454  720e                   -jb 0xa8e464
    if (cpu.flags.cf)
    {
        goto L_0x00a8e464;
    }
    // 00a8e456  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e458  770a                   -ja 0xa8e464
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8e464;
    }
    // 00a8e45a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8e45f  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a8e462  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e463  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e464:
    // 00a8e464  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 00a8e469  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e46a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e470(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e473  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e474  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e475  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8e476  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e479  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8e47b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a8e480  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a8e485  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a8e488  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a8e48d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a8e491  e87a0c0000             -call 0xa8f110
    cpu.esp -= 4;
    sub_a8f110(app, cpu);
    if (cpu.terminate) return;
    // 00a8e496  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8e498  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e49a  750a                   -jne 0xa8e4a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e4a6;
    }
    // 00a8e49c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e4a1  e97c010000             -jmp 0xa8e622
    goto L_0x00a8e622;
L_0x00a8e4a6:
    // 00a8e4a6  39e8                   +cmp eax, ebp
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
    // 00a8e4a8  750f                   -jne 0xa8e4b9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e4b9;
    }
    // 00a8e4aa  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e4af  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e4b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4b8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e4b9:
    // 00a8e4b9  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8e4bb  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a8e4bf  40                     -inc eax
    (cpu.eax)++;
    // 00a8e4c0  e8eb87ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e4c5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8e4c7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8e4cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e4cd  750f                   -jne 0xa8e4de
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e4de;
    }
    // 00a8e4cf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e4d4  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e4d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e4de:
    // 00a8e4de  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8e4e2  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a8e4e4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8e4e6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8e4e7  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8e4e9  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8e4eb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e4ec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e4ee  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8e4f1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8e4f3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8e4f5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8e4f8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8e4fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4fb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8e4fc  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8e500  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a8e503  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a8e507  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8e509  e8620c0000             -call 0xa8f170
    cpu.esp -= 4;
    sub_a8f170(app, cpu);
    if (cpu.terminate) return;
    // 00a8e50e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a8e512  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e514  744b                   -je 0xa8e561
    if (cpu.flags.zf)
    {
        goto L_0x00a8e561;
    }
    // 00a8e516  40                     -inc eax
    (cpu.eax)++;
    // 00a8e517  e89487ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e51c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8e51e  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a8e522  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e524  7516                   -jne 0xa8e53c
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e53c;
    }
    // 00a8e526  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8e528  e87388ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e52d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e532  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e535  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e536  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e537  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e538  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e539  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e53a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e53b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e53c:
    // 00a8e53c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8e540  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8e542  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8e543  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8e545  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8e547  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e548  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e54a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8e54d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8e54f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8e551  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8e554  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8e556  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e557  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8e558  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8e55c  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00a8e55f  eb04                   -jmp 0xa8e565
    goto L_0x00a8e565;
L_0x00a8e561:
    // 00a8e561  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a8e565:
    // 00a8e565  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8e569  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8e56a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8e56e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e56f  2eff15fc03a900         -call dword ptr cs:[0xa903fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076604) /* 0xa903fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e576  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8e578  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8e57c  e81f88ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e581  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8e585  e81688ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e58a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8e58c  750f                   -jne 0xa8e59d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e59d;
    }
    // 00a8e58e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e593  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e596  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e597  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e598  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e599  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e59a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e59b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e59c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e59d:
    // 00a8e59d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8e59f  e888000000             -call 0xa8e62c
    cpu.esp -= 4;
    sub_a8e62c(app, cpu);
    if (cpu.terminate) return;
    // 00a8e5a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e5a6  740f                   -je 0xa8e5b7
    if (cpu.flags.zf)
    {
        goto L_0x00a8e5b7;
    }
    // 00a8e5a8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e5ad  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e5b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e5b7:
    // 00a8e5b7  833da83ea90000         +cmp dword ptr [0xa93ea8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e5be  7462                   -je 0xa8e622
    if (cpu.flags.zf)
    {
        goto L_0x00a8e622;
    }
    // 00a8e5c0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8e5c2  e8a90b0000             -call 0xa8f170
    cpu.esp -= 4;
    sub_a8f170(app, cpu);
    if (cpu.terminate) return;
    // 00a8e5c7  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8e5ca  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8e5cd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a8e5d0  e8db86ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e5d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8e5d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e5d9  7519                   -jne 0xa8e5f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e5f4;
    }
    // 00a8e5db  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a8e5e0  e857daffff             -call 0xa8c03c
    cpu.esp -= 4;
    sub_a8c03c(app, cpu);
    if (cpu.terminate) return;
    // 00a8e5e5  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e5ea  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e5ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e5f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e5f4:
    // 00a8e5f4  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00a8e5f9  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a8e5fb  e8a00b0000             -call 0xa8f1a0
    cpu.esp -= 4;
    sub_a8f1a0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e600  83f8ff                 +cmp eax, -1
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
    // 00a8e603  7516                   -jne 0xa8e61b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e61b;
    }
    // 00a8e605  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e607  e89487ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e60c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e611  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e614  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e615  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e616  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e617  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e618  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e619  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e61a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e61b:
    // 00a8e61b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e61d  e8960d0000             -call 0xa8f3b8
    cpu.esp -= 4;
    sub_a8f3b8(app, cpu);
    if (cpu.terminate) return;
L_0x00a8e622:
    // 00a8e622  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a8e625  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e626  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e627  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e628  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e629  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e62a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e62b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8e62c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e62c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e62d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e62e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e62f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e630  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e631  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8e632  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8e635  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a8e639  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e63b  750a                   -jne 0xa8e647
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e647;
    }
    // 00a8e63d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e642  e989010000             -jmp 0xa8e7d0
    goto L_0x00a8e7d0;
L_0x00a8e647:
    // 00a8e647  803800                 +cmp byte ptr [eax], 0
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
    // 00a8e64a  7415                   -je 0xa8e661
    if (cpu.flags.zf)
    {
        goto L_0x00a8e661;
    }
    // 00a8e64c  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8e64f  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e652  740d                   -je 0xa8e661
    if (cpu.flags.zf)
    {
        goto L_0x00a8e661;
    }
L_0x00a8e654:
    // 00a8e654  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e657  7408                   -je 0xa8e661
    if (cpu.flags.zf)
    {
        goto L_0x00a8e661;
    }
    // 00a8e659  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a8e65c  42                     -inc edx
    (cpu.edx)++;
    // 00a8e65d  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a8e65f  75f3                   -jne 0xa8e654
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e654;
    }
L_0x00a8e661:
    // 00a8e661  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e664  750f                   -jne 0xa8e675
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e675;
    }
    // 00a8e666  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e66b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8e66e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e66f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e670  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e671  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e672  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e673  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e674  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e675:
    // 00a8e675  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e679  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a8e67c  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 00a8e67f  a1a43ea900             -mov eax, dword ptr [0xa93ea4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8e684  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8e688  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e68a  7541                   -jne 0xa8e6cd
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e6cd;
    }
    // 00a8e68c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8e68e  0f853c010000           -jne 0xa8e7d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e7d0;
    }
    // 00a8e694  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a8e699  e81286ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e69e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8e6a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e6a4  750f                   -jne 0xa8e6b5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e6b5;
    }
    // 00a8e6a6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e6ab  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8e6ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e6af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e6b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e6b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e6b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e6b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e6b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e6b5:
    // 00a8e6b5  a3a43ea900             -mov dword ptr [0xa93ea4], eax
    app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */) = cpu.eax;
    // 00a8e6ba  83c008                 +add eax, 8
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
    // 00a8e6bd  8968f8                 -mov dword ptr [eax - 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebp;
    // 00a8e6c0  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00a8e6c3  a3a03ea900             -mov dword ptr [0xa93ea0], eax
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.eax;
    // 00a8e6c8  e9e5000000             -jmp 0xa8e7b2
    goto L_0x00a8e7b2;
L_0x00a8e6cd:
    // 00a8e6cd  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8e6d1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a8e6d3  e804010000             -call 0xa8e7dc
    cpu.esp -= 4;
    sub_a8e7dc(app, cpu);
    if (cpu.terminate) return;
    // 00a8e6d8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8e6da  0f85ee000000           -jne 0xa8e7ce
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e7ce;
    }
    // 00a8e6e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e6e2  0f8fc7000000           -jg 0xa8e7af
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8e7af;
    }
    // 00a8e6e8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8e6ea  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00a8e6ec  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a8e6ef  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 00a8e6f6  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8e6f9  8b35a03ea900           -mov esi, dword ptr [0xa93ea0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8e6ff  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8e702  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8e704  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8e706  754f                   -jne 0xa8e757
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e757;
    }
    // 00a8e708  e8a385ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e70d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8e70f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8e713  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e715  750f                   -jne 0xa8e726
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e726;
    }
    // 00a8e717  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e71c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8e71f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e720  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e721  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e722  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e723  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e724  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e725  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e726:
    // 00a8e726  8b35a43ea900           -mov esi, dword ptr [0xa93ea4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8e72c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8e72e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8e72f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8e731  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8e733  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e734  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e736  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8e739  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8e73b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8e73d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8e740  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8e742  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e743  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8e744  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8e747  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8e749  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8e74b  a3a03ea900             -mov dword ptr [0xa93ea0], eax
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.eax;
    // 00a8e750  e85b83ffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e755  eb3c                   -jmp 0xa8e793
    goto L_0x00a8e793;
L_0x00a8e757:
    // 00a8e757  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8e759  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8e75d  e88ec9ffff             -call 0xa8b0f0
    cpu.esp -= 4;
    sub_a8b0f0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e762  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8e766  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8e768  750f                   -jne 0xa8e779
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e779;
    }
    // 00a8e76a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8e76f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8e772  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e773  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e774  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e775  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e776  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e777  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e778  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e779:
    // 00a8e779  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8e77c  8b15a03ea900           -mov edx, dword ptr [0xa93ea0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8e782  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e784  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a8e786  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e788  e8c30e0000             -call 0xa8f650
    cpu.esp -= 4;
    sub_a8f650(app, cpu);
    if (cpu.terminate) return;
    // 00a8e78d  890da03ea900           -mov dword ptr [0xa93ea0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.ecx;
L_0x00a8e793:
    // 00a8e793  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8e797  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00a8e79e  01f8                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8e7a0  893da43ea900           -mov dword ptr [0xa93ea4], edi
    app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */) = cpu.edi;
    // 00a8e7a6  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a8e7ad  eb03                   -jmp 0xa8e7b2
    goto L_0x00a8e7b2;
L_0x00a8e7af:
    // 00a8e7af  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a8e7b2:
    // 00a8e7b2  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8e7b6  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00a8e7bd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8e7bf  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8e7c3  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8e7c5  a1a03ea900             -mov eax, dword ptr [0xa93ea0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8e7ca  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x00a8e7ce:
    // 00a8e7ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8e7d0:
    // 00a8e7d0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8e7d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e7d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e7d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e7d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e7d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e7d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e7d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8e7dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e7dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e7dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e7de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e7df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e7e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8e7e1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8e7e3  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a8e7e5  8b35a43ea900           -mov esi, dword ptr [0xa93ea4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8e7eb  e9cb000000             -jmp 0xa8e8bb
    goto L_0x00a8e8bb;
L_0x00a8e7f0:
    // 00a8e7f0  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 00a8e7f2  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a8e7f4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a8e7f6  0f84bc000000           -je 0xa8e8b8
    if (cpu.flags.zf)
    {
        goto L_0x00a8e8b8;
    }
L_0x00a8e7fc:
    // 00a8e7fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e7fe  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8e800  e87bd4ffff             -call 0xa8bc80
    cpu.esp -= 4;
    sub_a8bc80(app, cpu);
    if (cpu.terminate) return;
    // 00a8e805  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8e807  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e809  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a8e80b  e870d4ffff             -call 0xa8bc80
    cpu.esp -= 4;
    sub_a8bc80(app, cpu);
    if (cpu.terminate) return;
    // 00a8e810  39c1                   +cmp ecx, eax
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
    // 00a8e812  0f85a0000000           -jne 0xa8e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e8b8;
    }
    // 00a8e818  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e81b  0f858a000000           -jne 0xa8e8ab
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e8ab;
    }
    // 00a8e821  8b15a43ea900           -mov edx, dword ptr [0xa93ea4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8e827  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a8e829  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8e82b  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a8e82e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8e830  0f846c000000           -je 0xa8e8a2
    if (cpu.flags.zf)
    {
        goto L_0x00a8e8a2;
    }
    // 00a8e836  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8e838  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8e83a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8e83c  740f                   -je 0xa8e84d
    if (cpu.flags.zf)
    {
        goto L_0x00a8e84d;
    }
L_0x00a8e83e:
    // 00a8e83e  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8e841  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a8e843  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8e846  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e849  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8e84b  75f1                   -jne 0xa8e83e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e83e;
    }
L_0x00a8e84d:
    // 00a8e84d  8b35a03ea900           -mov esi, dword ptr [0xa93ea0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8e853  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8e855  7443                   -je 0xa8e89a
    if (cpu.flags.zf)
    {
        goto L_0x00a8e89a;
    }
    // 00a8e857  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8e859  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8e85d  7407                   -je 0xa8e866
    if (cpu.flags.zf)
    {
        goto L_0x00a8e866;
    }
    // 00a8e85f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8e861  e83a85ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8e866:
    // 00a8e866  8b2da43ea900           -mov ebp, dword ptr [0xa93ea4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8e86c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a8e86e  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8e870  8b15a03ea900           -mov edx, dword ptr [0xa93ea0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8e876  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 00a8e879  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8e87b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a8e87d  e8ce0d0000             -call 0xa8f650
    cpu.esp -= 4;
    sub_a8f650(app, cpu);
    if (cpu.terminate) return;
    // 00a8e882  890da03ea900           -mov dword ptr [0xa93ea0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.ecx;
    // 00a8e888  39f7                   +cmp edi, esi
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
    // 00a8e88a  7d0e                   -jge 0xa8e89a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8e89a;
    }
    // 00a8e88c  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x00a8e88f:
    // 00a8e88f  40                     -inc eax
    (cpu.eax)++;
    // 00a8e890  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8e892  47                     -inc edi
    (cpu.edi)++;
    // 00a8e893  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a8e896  39f7                   +cmp edi, esi
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
    // 00a8e898  7cf5                   -jl 0xa8e88f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8e88f;
    }
L_0x00a8e89a:
    // 00a8e89a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e89c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e89d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e89e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e89f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e8a2:
    // 00a8e8a2  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a8e8a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8a9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8aa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e8ab:
    // 00a8e8ab  42                     -inc edx
    (cpu.edx)++;
    // 00a8e8ac  8a4b01                 -mov cl, byte ptr [ebx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a8e8af  43                     -inc ebx
    (cpu.ebx)++;
    // 00a8e8b0  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a8e8b2  0f8544ffffff           -jne 0xa8e7fc
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e7fc;
    }
L_0x00a8e8b8:
    // 00a8e8b8  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a8e8bb:
    // 00a8e8bb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8e8bd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8e8bf  0f852bffffff           -jne 0xa8e7f0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e7f0;
    }
    // 00a8e8c5  a1a43ea900             -mov eax, dword ptr [0xa93ea4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8e8ca  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8e8cc  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00a8e8cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e8d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e8e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e8e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e8e1  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e8e8  7428                   -je 0xa8e912
    if (cpu.flags.zf)
    {
        goto L_0x00a8e912;
    }
    // 00a8e8ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8e8ec  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8e8ee  8a92614aa900           -mov dl, byte ptr [edx + 0xa94a61]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8e8f4  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8e8f7  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8e8fd  7413                   -je 0xa8e912
    if (cpu.flags.zf)
    {
        goto L_0x00a8e912;
    }
    // 00a8e8ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8e901  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8e903  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a8e906  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8e909  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8e90e  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8e910  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e911  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e912:
    // 00a8e912  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8e914  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8e919  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e91a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e920(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e922  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e923  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e926  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8e928  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a8e92a  e861000000             -call 0xa8e990
    cpu.esp -= 4;
    sub_a8e990(app, cpu);
    if (cpu.terminate) return;
    // 00a8e92f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8e931  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8e933  e858deffff             -call 0xa8c790
    cpu.esp -= 4;
    sub_a8c790(app, cpu);
    if (cpu.terminate) return;
    // 00a8e938  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a8e93b  813d7c2ba900a4030000   +cmp dword ptr [0xa92b7c], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11086716) /* 0xa92b7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e945  7526                   -jne 0xa8e96d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e96d;
    }
    // 00a8e947  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e94e  741d                   -je 0xa8e96d
    if (cpu.flags.zf)
    {
        goto L_0x00a8e96d;
    }
    // 00a8e950  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e952  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00a8e955  8a80614aa900           -mov al, byte ptr [eax + 0xa94a61]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8e95b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8e95d  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8e962  7409                   -je 0xa8e96d
    if (cpu.flags.zf)
    {
        goto L_0x00a8e96d;
    }
    // 00a8e964  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8e966  e8350d0000             -call 0xa8f6a0
    cpu.esp -= 4;
    sub_a8f6a0(app, cpu);
    if (cpu.terminate) return;
    // 00a8e96b  eb15                   -jmp 0xa8e982
    goto L_0x00a8e982;
L_0x00a8e96d:
    // 00a8e96d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8e96f  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8e973  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8e974  2eff155003a900         -call dword ptr cs:[0xa90350]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076432) /* 0xa90350 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8e97b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8e97d  e85effffff             -call 0xa8e8e0
    cpu.esp -= 4;
    sub_a8e8e0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8e982:
    // 00a8e982  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8e985  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e986  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e987  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e988  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8e990(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e990  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e991  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8e993  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8e995  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 00a8e998  740c                   -je 0xa8e9a6
    if (cpu.flags.zf)
    {
        goto L_0x00a8e9a6;
    }
    // 00a8e99a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8e99c  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00a8e99f  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a8e9a2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a8e9a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e9a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e9a6:
    // 00a8e9a6  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00a8e9a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e9a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8e9aa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e9aa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8e9ab  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8e9af  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a8e9b2  6681faff7f             +cmp dx, 0x7fff
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
    // 00a8e9b7  751c                   -jne 0xa8e9d5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e9d5;
    }
    // 00a8e9b9  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8e9c0  750c                   -jne 0xa8e9ce
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e9ce;
    }
    // 00a8e9c2  833800                 +cmp dword ptr [eax], 0
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
    // 00a8e9c5  7507                   -jne 0xa8e9ce
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e9ce;
    }
    // 00a8e9c7  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a8e9cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e9cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e9ce:
    // 00a8e9ce  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a8e9d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e9d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e9d5:
    // 00a8e9d5  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 00a8e9db  7516                   -jne 0xa8e9f3
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e9f3;
    }
    // 00a8e9dd  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00a8e9e1  7509                   -jne 0xa8e9ec
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e9ec;
    }
    // 00a8e9e3  833800                 +cmp dword ptr [eax], 0
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
    // 00a8e9e6  7504                   -jne 0xa8e9ec
    if (!cpu.flags.zf)
    {
        goto L_0x00a8e9ec;
    }
    // 00a8e9e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8e9ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e9eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e9ec:
    // 00a8e9ec  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a8e9f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e9f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8e9f3:
    // 00a8e9f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8e9f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8e9f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8e9fa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8e9fa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8e9fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8e9fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8e9fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8e9fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8e9ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ea00  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8ea02  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8ea04  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ea06  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8ea08  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8ea0a:
    // 00a8ea0a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8ea0c  3c00                   +cmp al, 0
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
    // 00a8ea0e  742f                   -je 0xa8ea3f
    if (cpu.flags.zf)
    {
        goto L_0x00a8ea3f;
    }
    // 00a8ea10  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8ea12  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a8ea14  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8ea16  01ed                   +add ebp, ebp
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
    // 00a8ea18  11c9                   +adc ecx, ecx
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
    // 00a8ea1a  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a8ea1c  01ed                   +add ebp, ebp
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
    // 00a8ea1e  11c9                   +adc ecx, ecx
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
    // 00a8ea20  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a8ea22  01c5                   +add ebp, eax
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
    // 00a8ea24  11d9                   +adc ecx, ebx
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
    // 00a8ea26  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 00a8ea28  01ed                   +add ebp, ebp
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
    // 00a8ea2a  11c9                   +adc ecx, ecx
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
    // 00a8ea2c  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00a8ea2e  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8ea30  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a8ea32  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 00a8ea34  01c5                   +add ebp, eax
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
    // 00a8ea36  83d100                 +adc ecx, 0
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
    // 00a8ea39  83d200                 +adc edx, 0
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
    // 00a8ea3c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8ea3d  ebcb                   -jmp 0xa8ea0a
    goto L_0x00a8ea0a;
L_0x00a8ea3f:
    // 00a8ea3f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8ea41  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 00a8ea46  e811000000             -call 0xa8ea5c
    cpu.esp -= 4;
    sub_a8ea5c(app, cpu);
    if (cpu.terminate) return;
    // 00a8ea4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ea4c  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8ea4f  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00a8ea52  66897508               -mov word ptr [ebp + 8], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 00a8ea56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ea57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ea58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ea59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ea5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ea5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8ea5c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ea5c  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8ea5e  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8ea60  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8ea62  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00a8ea64  7436                   -je 0xa8ea9c
    if (cpu.flags.zf)
    {
        goto L_0x00a8ea9c;
    }
    // 00a8ea66  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8ea68  7509                   -jne 0xa8ea73
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ea73;
    }
    // 00a8ea6a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8ea6c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8ea6e  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8ea70  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a8ea73:
    // 00a8ea73  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8ea75  7509                   -jne 0xa8ea80
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ea80;
    }
    // 00a8ea77  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8ea79  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8ea7b  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8ea7d  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a8ea80:
    // 00a8ea80  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8ea82  7809                   -js 0xa8ea8d
    if (cpu.flags.sf)
    {
        goto L_0x00a8ea8d;
    }
    // 00a8ea84  4f                     -dec edi
    (cpu.edi)--;
    // 00a8ea85  01ed                   +add ebp, ebp
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
    // 00a8ea87  11c0                   +adc eax, eax
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
    // 00a8ea89  11d2                   +adc edx, edx
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
    // 00a8ea8b  ebf3                   -jmp 0xa8ea80
    goto L_0x00a8ea80;
L_0x00a8ea8d:
    // 00a8ea8d  01ed                   +add ebp, ebp
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
    // 00a8ea8f  83d000                 +adc eax, 0
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
    // 00a8ea92  83d200                 +adc edx, 0
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
    // 00a8ea95  7303                   -jae 0xa8ea9a
    if (!cpu.flags.cf)
    {
        goto L_0x00a8ea9a;
    }
    // 00a8ea97  d1da                   -rcr edx, 1
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
    // 00a8ea99  47                     -inc edi
    (cpu.edi)++;
L_0x00a8ea9a:
    // 00a8ea9a  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x00a8ea9c:
    // 00a8ea9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a8eaa0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8eaa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8eaa1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8eaa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8eaa3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8eaa4  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a8eaa6  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a8eaa8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8eaa9  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8eaab  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8eaae  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00a8eab1  8b157038a900           -mov edx, dword ptr [0xa93870]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11090032) /* 0xa93870 */);
    // 00a8eab7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8eab9  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a8eabc  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00a8eabf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8eac1  7531                   -jne 0xa8eaf4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8eaf4;
    }
    // 00a8eac3  a14c28a900             -mov eax, dword ptr [0xa9284c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a8eac8  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a8eacb  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a8eacd  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8eacf  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a8ead1  8b1d4c28a900           -mov ebx, dword ptr [0xa9284c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a8ead7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8ead9  e8d27fffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8eade  a14c28a900             -mov eax, dword ptr [0xa9284c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11085900) /* 0xa9284c */);
    // 00a8eae3  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a8eae9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8eaeb  e8a89dffff             -call 0xa88898
    cpu.esp -= 4;
    sub_a88898(app, cpu);
    if (cpu.terminate) return;
    // 00a8eaf0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8eaf2  7431                   -je 0xa8eb25
    if (cpu.flags.zf)
    {
        goto L_0x00a8eb25;
    }
L_0x00a8eaf4:
    // 00a8eaf4  ff15a826a900           -call dword ptr [0xa926a8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085480) /* 0xa926a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8eafa  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a8eafd  05de000000             -add eax, 0xde
    (cpu.eax) += x86::reg32(x86::sreg32(222 /*0xde*/));
    // 00a8eb02  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8eb03  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a8eb06  2eff150404a900         -call dword ptr cs:[0xa90404]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076612) /* 0xa90404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8eb0d  8d45f4                 -lea eax, [ebp - 0xc]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a8eb10  e8abc0ffff             -call 0xa8abc0
    cpu.esp -= 4;
    sub_a8abc0(app, cpu);
    if (cpu.terminate) return;
    // 00a8eb15  ff15e826a900           -call dword ptr [0xa926e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085544) /* 0xa926e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8eb1b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8eb1d  ff55fc                 -call dword ptr [ebp - 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8eb20  e8c7ecffff             -call 0xa8d7ec
    cpu.esp -= 4;
    sub_a8d7ec(app, cpu);
    if (cpu.terminate) return;
L_0x00a8eb25:
    // 00a8eb25  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a8eb27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eb28  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8eb2a  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8eb2c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8eb2d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eb2e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eb2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eb30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8eb34(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8eb34  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8eb35  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8eb36  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8eb37  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8eb38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8eb39  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00a8eb3c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8eb3e  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a8eb40  833da426a900ff         +cmp dword ptr [0xa926a4], -1
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
    // 00a8eb47  7512                   -jne 0xa8eb5b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8eb5b;
    }
    // 00a8eb49  e8ea9cffff             -call 0xa88838
    cpu.esp -= 4;
    sub_a88838(app, cpu);
    if (cpu.terminate) return;
    // 00a8eb4e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8eb50  0f84be000000           -je 0xa8ec14
    if (cpu.flags.zf)
    {
        goto L_0x00a8ec14;
    }
    // 00a8eb56  e8199effff             -call 0xa88974
    cpu.esp -= 4;
    sub_a88974(app, cpu);
    if (cpu.terminate) return;
L_0x00a8eb5b:
    // 00a8eb5b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a8eb5d  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a8eb61  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a8eb65  2eff15b003a900         -call dword ptr cs:[0xa903b0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076528) /* 0xa903b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8eb6c  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a8eb70  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8eb72  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8eb74  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8eb76  bedc1ea900             -mov esi, 0xa91edc
    cpu.esi = 11083484 /*0xa91edc*/;
    // 00a8eb7b  895c2430               -mov dword ptr [esp + 0x30], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.ebx;
    // 00a8eb7f  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a8eb84  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8eb85  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8eb86  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8eb87  2eff15ac03a900         -call dword ptr cs:[0xa903ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076524) /* 0xa903ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8eb8e  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8eb92  e845cfffff             -call 0xa8badc
    cpu.esp -= 4;
    sub_a8badc(app, cpu);
    if (cpu.terminate) return;
    // 00a8eb97  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8eb99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8eb9a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8eb9c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8eb9e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8eba0  2eff156803a900         -call dword ptr cs:[0xa90368]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076456) /* 0xa90368 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8eba7  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a8ebab  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a8ebaf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ebb0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ebb2  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a8ebb6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ebb7  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a8ebbd  68a0eaa800             -push 0xa8eaa0
    app->getMemory<x86::reg32>(cpu.esp-4) = 11070112 /*0xa8eaa0*/;
    cpu.esp -= 4;
    // 00a8ebc2  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00a8ebc8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8ebc9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ebcb  2eff157003a900         -call dword ptr cs:[0xa90370]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076464) /* 0xa90370 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ebd2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8ebd4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8ebd6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ebd8  750a                   -jne 0xa8ebe4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ebe4;
    }
    // 00a8ebda  c7442434ffffffff       -mov dword ptr [esp + 0x34], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = 4294967295 /*0xffffffff*/;
    // 00a8ebe2  eb22                   -jmp 0xa8ec06
    goto L_0x00a8ec06;
L_0x00a8ebe4:
    // 00a8ebe4  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a8ebe6  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a8ebea  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ebeb  2eff153804a900         -call dword ptr cs:[0xa90438]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076664) /* 0xa90438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ebf2  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a8ebf6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8ebf8  7404                   -je 0xa8ebfe
    if (cpu.flags.zf)
    {
        goto L_0x00a8ebfe;
    }
    // 00a8ebfa  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00a8ebfc  eb08                   -jmp 0xa8ec06
    goto L_0x00a8ec06;
L_0x00a8ebfe:
    // 00a8ebfe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ebff  2eff156403a900         -call dword ptr cs:[0xa90364]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076452) /* 0xa90364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a8ec06:
    // 00a8ec06  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a8ec0a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ec0b  2eff156403a900         -call dword ptr cs:[0xa90364]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076452) /* 0xa90364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ec12  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a8ec14:
    // 00a8ec14  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00a8ec17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ec18  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8ec19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ec1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ec1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ec1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8ec20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ec20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ec21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ec22  ff15ec26a900           -call dword ptr [0xa926ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085548) /* 0xa926ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ec28  e8dfbfffff             -call 0xa8ac0c
    cpu.esp -= 4;
    sub_a8ac0c(app, cpu);
    if (cpu.terminate) return;
    // 00a8ec2d  833d7038a90000         +cmp dword ptr [0xa93870], 0
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
    // 00a8ec34  750a                   -jne 0xa8ec40
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ec40;
    }
    // 00a8ec36  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8ec3b  e8ac9cffff             -call 0xa888ec
    cpu.esp -= 4;
    sub_a888ec(app, cpu);
    if (cpu.terminate) return;
L_0x00a8ec40:
    // 00a8ec40  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ec42  2eff158403a900         -call dword ptr cs:[0xa90384]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076484) /* 0xa90384 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ec49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ec4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ec4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8ec50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ec50  ff159727a900           -call dword ptr [0xa92797]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085719) /* 0xa92797 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ec56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8ec57(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ec57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8ec59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8ec60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ec60  c705102ca90001000000   -mov dword ptr [0xa92c10], 1
    app->getMemory<x86::reg32>(x86::reg32(11086864) /* 0xa92c10 */) = 1 /*0x1*/;
    // 00a8ec6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8ec70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ec70  83f841                 +cmp eax, 0x41
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65 /*0x41*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ec73  7c08                   -jl 0xa8ec7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8ec7d;
    }
    // 00a8ec75  83f85a                 +cmp eax, 0x5a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(90 /*0x5a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ec78  7f03                   -jg 0xa8ec7d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8ec7d;
    }
    // 00a8ec7a  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a8ec7d:
    // 00a8ec7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a8ec80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ec80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ec81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ec82  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8ec86  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8ec89  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a8ec8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ec8d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ec8f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a8ec93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ec94  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a8ec98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ec99  e806000000             -call 0xa8eca4
    cpu.esp -= 4;
    sub_a8eca4(app, cpu);
    if (cpu.terminate) return;
    // 00a8ec9e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8eca1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eca2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eca3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8eca4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8eca4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8eca5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8eca6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8eca7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8ecaa  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a8ecae  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a8ecb0  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8ecb4  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a8ecb8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8ecbb  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8ecbf  e808000000             -call 0xa8eccc
    cpu.esp -= 4;
    sub_a8eccc(app, cpu);
    if (cpu.terminate) return;
    // 00a8ecc4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8ecc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ecc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ecc9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ecca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8eccc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8eccc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8eccd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ecce  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8eccf  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a8ecd2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8ecd4  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a8ecd8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a8ecda  e881b6ffff             -call 0xa8a360
    cpu.esp -= 4;
    sub_a8a360(app, cpu);
    if (cpu.terminate) return;
    // 00a8ecdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ece1  7414                   -je 0xa8ecf7
    if (cpu.flags.zf)
    {
        goto L_0x00a8ecf7;
    }
    // 00a8ece3  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 00a8ece8  e833b5ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8eced  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8ecf2  e9fe010000             -jmp 0xa8eef5
    goto L_0x00a8eef5;
L_0x00a8ecf7:
    // 00a8ecf7  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8ecf9  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8ecfd  83e607                 -and esi, 7
    cpu.esi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a8ed00  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a8ed04  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8ed06  e8e5090000             -call 0xa8f6f0
    cpu.esp -= 4;
    sub_a8f6f0(app, cpu);
    if (cpu.terminate) return;
    // 00a8ed0b  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8ed0f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8ed11  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8ed13  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8ed15  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 00a8ed1a  e8050a0000             -call 0xa8f724
    cpu.esp -= 4;
    sub_a8f724(app, cpu);
    if (cpu.terminate) return;
    // 00a8ed1f  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00a8ed24  8a64241c               -mov ah, byte ptr [esp + 0x1c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8ed28  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a8ed2c  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a8ed2f  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00a8ed32  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a8ed35  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8ed3a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8ed3e  833dfc26a90000         +cmp dword ptr [0xa926fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085564) /* 0xa926fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ed45  7434                   -je 0xa8ed7b
    if (cpu.flags.zf)
    {
        goto L_0x00a8ed7b;
    }
    // 00a8ed47  bae81ea900             -mov edx, 0xa91ee8
    cpu.edx = 11083496 /*0xa91ee8*/;
    // 00a8ed4c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8ed4e  e87d030000             -call 0xa8f0d0
    cpu.esp -= 4;
    sub_a8f0d0(app, cpu);
    if (cpu.terminate) return;
    // 00a8ed53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ed55  7524                   -jne 0xa8ed7b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ed7b;
    }
    // 00a8ed57  e844b8ffff             -call 0xa8a5a0
    cpu.esp -= 4;
    sub_a8a5a0(app, cpu);
    if (cpu.terminate) return;
    // 00a8ed5c  ff15b426a900           -call dword ptr [0xa926b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085492) /* 0xa926b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ed62  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a8ed64  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ed65  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ed66  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00a8ed6b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8ed6d  ff15fc26a900           -call dword ptr [0xa926fc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085564) /* 0xa926fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ed73  83c40c                 +add esp, 0xc
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
    // 00a8ed76  e92a010000             -jmp 0xa8eea5
    goto L_0x00a8eea5;
L_0x00a8ed7b:
    // 00a8ed7b  8a54241c               -mov dl, byte ptr [esp + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8ed7f  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00a8ed82  0f8472000000           -je 0xa8edfa
    if (cpu.flags.zf)
    {
        goto L_0x00a8edfa;
    }
    // 00a8ed88  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a8ed8a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8ed8d  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00a8ed8f  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a8ed92  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a8ed96  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00a8ed9c  a1142ca900             -mov eax, dword ptr [0xa92c14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086868) /* 0xa92c14 */);
    // 00a8eda1  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a8eda5  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00a8eda7  21c3                   -and ebx, eax
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8eda9  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00a8edad  f644241501             +test byte ptr [esp + 0x15], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) & 1 /*0x1*/));
    // 00a8edb2  740c                   -je 0xa8edc0
    if (cpu.flags.zf)
    {
        goto L_0x00a8edc0;
    }
    // 00a8edb4  f644241480             +test byte ptr [esp + 0x14], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 128 /*0x80*/));
    // 00a8edb9  7505                   -jne 0xa8edc0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8edc0;
    }
    // 00a8edbb  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x00a8edc0:
    // 00a8edc0  f644241d04             +test byte ptr [esp + 0x1d], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) & 4 /*0x4*/));
    // 00a8edc5  740d                   -je 0xa8edd4
    if (cpu.flags.zf)
    {
        goto L_0x00a8edd4;
    }
    // 00a8edc7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8edcc  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a8edd0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8edd2  eb37                   -jmp 0xa8ee0b
    goto L_0x00a8ee0b;
L_0x00a8edd4:
    // 00a8edd4  f644241c40             +test byte ptr [esp + 0x1c], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 64 /*0x40*/));
    // 00a8edd9  740f                   -je 0xa8edea
    if (cpu.flags.zf)
    {
        goto L_0x00a8edea;
    }
    // 00a8eddb  c744241802000000       -mov dword ptr [esp + 0x18], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 2 /*0x2*/;
    // 00a8ede3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8ede8  eb21                   -jmp 0xa8ee0b
    goto L_0x00a8ee0b;
L_0x00a8edea:
    // 00a8edea  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00a8edef  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a8edf4  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00a8edf8  eb11                   -jmp 0xa8ee0b
    goto L_0x00a8ee0b;
L_0x00a8edfa:
    // 00a8edfa  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 00a8edfd  7407                   -je 0xa8ee06
    if (cpu.flags.zf)
    {
        goto L_0x00a8ee06;
    }
    // 00a8edff  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a8ee04  eb05                   -jmp 0xa8ee0b
    goto L_0x00a8ee0b;
L_0x00a8ee06:
    // 00a8ee06  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x00a8ee0b:
    // 00a8ee0b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ee0d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8ee0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ee0f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8ee13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ee14  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8ee18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ee19  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a8ee1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ee1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ee1f  2eff156c03a900         -call dword ptr cs:[0xa9036c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076460) /* 0xa9036c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ee26  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8ee28  83f8ff                 +cmp eax, -1
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
    // 00a8ee2b  7536                   -jne 0xa8ee63
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ee63;
    }
    // 00a8ee2d  f644241c20             +test byte ptr [esp + 0x1c], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 32 /*0x20*/));
    // 00a8ee32  741e                   -je 0xa8ee52
    if (cpu.flags.zf)
    {
        goto L_0x00a8ee52;
    }
    // 00a8ee34  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ee36  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8ee37  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a8ee3b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8ee3c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a8ee3e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a8ee42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8ee43  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a8ee47  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ee48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ee49  2eff156c03a900         -call dword ptr cs:[0xa9036c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076460) /* 0xa9036c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ee50  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a8ee52:
    // 00a8ee52  83fbff                 +cmp ebx, -1
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
    // 00a8ee55  750c                   -jne 0xa8ee63
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ee63;
    }
    // 00a8ee57  e848d2ffff             -call 0xa8c0a4
    cpu.esp -= 4;
    sub_a8c0a4(app, cpu);
    if (cpu.terminate) return;
    // 00a8ee5c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a8ee5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ee60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ee61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ee62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8ee63:
    // 00a8ee63  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8ee65  ff15b426a900           -call dword ptr [0xa926b4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085492) /* 0xa926b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ee6b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8ee6d  8b3d042aa900           -mov edi, dword ptr [0xa92a04]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(11086340) /* 0xa92a04 */);
    // 00a8ee73  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8ee75  39f8                   +cmp eax, edi
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
    // 00a8ee77  721e                   -jb 0xa8ee97
    if (cpu.flags.cf)
    {
        goto L_0x00a8ee97;
    }
    // 00a8ee79  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ee7a  2eff156403a900         -call dword ptr cs:[0xa90364]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076452) /* 0xa90364 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ee81  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a8ee86  e895b3ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
    // 00a8ee8b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8ee90  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a8ee93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ee94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ee95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ee96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8ee97:
    // 00a8ee97  e8d4eaffff             -call 0xa8d970
    cpu.esp -= 4;
    sub_a8d970(app, cpu);
    if (cpu.terminate) return;
    // 00a8ee9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ee9e  7405                   -je 0xa8eea5
    if (cpu.flags.zf)
    {
        goto L_0x00a8eea5;
    }
    // 00a8eea0  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x00a8eea5:
    // 00a8eea5  83fe02                 +cmp esi, 2
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
    // 00a8eea8  7505                   -jne 0xa8eeaf
    if (!cpu.flags.zf)
    {
        goto L_0x00a8eeaf;
    }
    // 00a8eeaa  80ca03                 +or dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8eead  eb11                   -jmp 0xa8eec0
    goto L_0x00a8eec0;
L_0x00a8eeaf:
    // 00a8eeaf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8eeb1  7505                   -jne 0xa8eeb8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8eeb8;
    }
    // 00a8eeb3  80ca01                 +or dl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a8eeb6  eb08                   -jmp 0xa8eec0
    goto L_0x00a8eec0;
L_0x00a8eeb8:
    // 00a8eeb8  83fe01                 +cmp esi, 1
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
    // 00a8eebb  7503                   -jne 0xa8eec0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8eec0;
    }
    // 00a8eebd  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a8eec0:
    // 00a8eec0  f644241c10             +test byte ptr [esp + 0x1c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 16 /*0x10*/));
    // 00a8eec5  7403                   -je 0xa8eeca
    if (cpu.flags.zf)
    {
        goto L_0x00a8eeca;
    }
    // 00a8eec7  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x00a8eeca:
    // 00a8eeca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8eecc  8a5c241d               -mov bl, byte ptr [esp + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 00a8eed0  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a8eed2  f6c303                 +test bl, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 3 /*0x3*/));
    // 00a8eed5  7407                   -je 0xa8eede
    if (cpu.flags.zf)
    {
        goto L_0x00a8eede;
    }
    // 00a8eed7  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 00a8eeda  7410                   -je 0xa8eeec
    if (cpu.flags.zf)
    {
        goto L_0x00a8eeec;
    }
    // 00a8eedc  eb0c                   -jmp 0xa8eeea
    goto L_0x00a8eeea;
L_0x00a8eede:
    // 00a8eede  813d6c25a90000020000   +cmp dword ptr [0xa9256c], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11085164) /* 0xa9256c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8eee8  7502                   -jne 0xa8eeec
    if (!cpu.flags.zf)
    {
        goto L_0x00a8eeec;
    }
L_0x00a8eeea:
    // 00a8eeea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00a8eeec:
    // 00a8eeec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8eeee  e815d1ffff             -call 0xa8c008
    cpu.esp -= 4;
    sub_a8c008(app, cpu);
    if (cpu.terminate) return;
    // 00a8eef3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a8eef5:
    // 00a8eef5  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a8eef8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eef9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eefa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8eefb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8ef00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ef00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8ef01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ef02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8ef03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ef04  3b4204                 +cmp eax, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8ef07  7f2c                   -jg 0xa8ef35
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8ef35;
    }
    // 00a8ef09  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a8ef0c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8ef0e  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a8ef11  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8ef13  39d8                   +cmp eax, ebx
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
    // 00a8ef15  7c1e                   -jl 0xa8ef35
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8ef35;
    }
    // 00a8ef17  8a5a0c                 -mov bl, byte ptr [edx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a8ef1a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00a8ef1c  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a8ef1f  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a8ef22  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8ef24  885a0c                 -mov byte ptr [edx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00a8ef27  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8ef29  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00a8ef2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8ef2d  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a8ef30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef32  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8ef35:
    // 00a8ef35  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8ef3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a8ef40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ef40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8ef41  80600cef               -and byte ptr [eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a8ef45  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8ef48  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a8ef4b  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a8ef52  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a8ef54  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8ef55  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8ef58(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8ef58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8ef59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8ef5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8ef5b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8ef5d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8ef5f  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a8ef62  ff15ac26a900           -call dword ptr [0xa926ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085484) /* 0xa926ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8ef68  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a8ef6b  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 00a8ef6e  0f8475000000           -je 0xa8efe9
    if (cpu.flags.zf)
    {
        goto L_0x00a8efe9;
    }
    // 00a8ef74  f6410d10               +test byte ptr [ecx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a8ef78  742f                   -je 0xa8efa9
    if (cpu.flags.zf)
    {
        goto L_0x00a8efa9;
    }
    // 00a8ef7a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8ef7c  e8ff8affff             -call 0xa87a80
    cpu.esp -= 4;
    sub_a87a80(app, cpu);
    if (cpu.terminate) return;
    // 00a8ef81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8ef83  743b                   -je 0xa8efc0
    if (cpu.flags.zf)
    {
        goto L_0x00a8efc0;
    }
    // 00a8ef85  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8ef87  750e                   -jne 0xa8ef97
    if (!cpu.flags.zf)
    {
        goto L_0x00a8ef97;
    }
    // 00a8ef89  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8ef8b  7d0a                   -jge 0xa8ef97
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8ef97;
    }
L_0x00a8ef8d:
    // 00a8ef8d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a8ef92  e889b2ffff             -call 0xa8a220
    cpu.esp -= 4;
    sub_a8a220(app, cpu);
    if (cpu.terminate) return;
L_0x00a8ef97:
    // 00a8ef97  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8ef9a  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8efa0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8efa5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8efa6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8efa7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8efa8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8efa9:
    // 00a8efa9  83fb01                 +cmp ebx, 1
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
    // 00a8efac  7503                   -jne 0xa8efb1
    if (!cpu.flags.zf)
    {
        goto L_0x00a8efb1;
    }
    // 00a8efae  2b7104                 -sub esi, dword ptr [ecx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
L_0x00a8efb1:
    // 00a8efb1  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8efb4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8efb7  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a8efbe  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00a8efc0:
    // 00a8efc0  80610ceb               -and byte ptr [ecx + 0xc], 0xeb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 00a8efc4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8efc6  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8efc9  e8b2b2ffff             -call 0xa8a280
    cpu.esp -= 4;
    sub_a8a280(app, cpu);
    if (cpu.terminate) return;
    // 00a8efce  83f8ff                 +cmp eax, -1
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
    // 00a8efd1  0f85e4000000           -jne 0xa8f0bb
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f0bb;
    }
    // 00a8efd7  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8efda  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8efe0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8efe5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8efe6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8efe7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8efe8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8efe9:
    // 00a8efe9  83fb01                 +cmp ebx, 1
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
    // 00a8efec  720d                   -jb 0xa8effb
    if (cpu.flags.cf)
    {
        goto L_0x00a8effb;
    }
    // 00a8efee  7611                   -jbe 0xa8f001
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8f001;
    }
    // 00a8eff0  83fb02                 +cmp ebx, 2
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
    // 00a8eff3  0f848a000000           -je 0xa8f083
    if (cpu.flags.zf)
    {
        goto L_0x00a8f083;
    }
    // 00a8eff9  eb92                   -jmp 0xa8ef8d
    goto L_0x00a8ef8d;
L_0x00a8effb:
    // 00a8effb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8effd  7445                   -je 0xa8f044
    if (cpu.flags.zf)
    {
        goto L_0x00a8f044;
    }
    // 00a8efff  eb8c                   -jmp 0xa8ef8d
    goto L_0x00a8ef8d;
L_0x00a8f001:
    // 00a8f001  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8f003  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f005  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8f008  e8f3feffff             -call 0xa8ef00
    cpu.esp -= 4;
    sub_a8ef00(app, cpu);
    if (cpu.terminate) return;
    // 00a8f00d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f00f  0f84a6000000           -je 0xa8f0bb
    if (cpu.flags.zf)
    {
        goto L_0x00a8f0bb;
    }
    // 00a8f015  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8f017  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8f01a  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8f01c  e85fb2ffff             -call 0xa8a280
    cpu.esp -= 4;
    sub_a8a280(app, cpu);
    if (cpu.terminate) return;
    // 00a8f021  83f8ff                 +cmp eax, -1
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
    // 00a8f024  7512                   -jne 0xa8f038
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f038;
    }
    // 00a8f026  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8f029  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8f02f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f034  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f035  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f036  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f037  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f038:
    // 00a8f038  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f03a  e801ffffff             -call 0xa8ef40
    cpu.esp -= 4;
    sub_a8ef40(app, cpu);
    if (cpu.terminate) return;
    // 00a8f03f  e977000000             -jmp 0xa8f0bb
    goto L_0x00a8f0bb;
L_0x00a8f044:
    // 00a8f044  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8f047  e834f1ffff             -call 0xa8e180
    cpu.esp -= 4;
    sub_a8e180(app, cpu);
    if (cpu.terminate) return;
    // 00a8f04c  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8f04f  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a8f051  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8f053  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f055  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8f057  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8f059  e8a2feffff             -call 0xa8ef00
    cpu.esp -= 4;
    sub_a8ef00(app, cpu);
    if (cpu.terminate) return;
    // 00a8f05e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f060  7459                   -je 0xa8f0bb
    if (cpu.flags.zf)
    {
        goto L_0x00a8f0bb;
    }
    // 00a8f062  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8f064  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8f067  e814b2ffff             -call 0xa8a280
    cpu.esp -= 4;
    sub_a8a280(app, cpu);
    if (cpu.terminate) return;
    // 00a8f06c  83f8ff                 +cmp eax, -1
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
    // 00a8f06f  75c7                   -jne 0xa8f038
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f038;
    }
    // 00a8f071  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8f074  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8f07a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f07f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f080  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f081  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f082  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f083:
    // 00a8f083  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00a8f085  80e2ef                 -and dl, 0xef
    cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a8f088  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a8f08b  88510c                 -mov byte ptr [ecx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 00a8f08e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a8f091  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a8f093  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a8f095  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8f098  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a8f09f  e8dcb1ffff             -call 0xa8a280
    cpu.esp -= 4;
    sub_a8a280(app, cpu);
    if (cpu.terminate) return;
    // 00a8f0a4  83f8ff                 +cmp eax, -1
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
    // 00a8f0a7  7512                   -jne 0xa8f0bb
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f0bb;
    }
    // 00a8f0a9  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8f0ac  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8f0b2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f0b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f0b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f0b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f0ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f0bb:
    // 00a8f0bb  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a8f0be  ff15b026a900           -call dword ptr [0xa926b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(11085488) /* 0xa926b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8f0c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f0c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f0c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f0c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f0c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f0d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f0d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f0d1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a8f0d3:
    // 00a8f0d3  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00a8f0d5  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8f0d7  3c41                   +cmp al, 0x41
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f0d9  7206                   -jb 0xa8f0e1
    if (cpu.flags.cf)
    {
        goto L_0x00a8f0e1;
    }
    // 00a8f0db  3c5a                   +cmp al, 0x5a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(90 /*0x5a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f0dd  7702                   -ja 0xa8f0e1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8f0e1;
    }
    // 00a8f0df  0420                   -add al, 0x20
    (cpu.al) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a8f0e1:
    // 00a8f0e1  80fc41                 +cmp ah, 0x41
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(65 /*0x41*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f0e4  7208                   -jb 0xa8f0ee
    if (cpu.flags.cf)
    {
        goto L_0x00a8f0ee;
    }
    // 00a8f0e6  80fc5a                 +cmp ah, 0x5a
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(90 /*0x5a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f0e9  7703                   -ja 0xa8f0ee
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8f0ee;
    }
    // 00a8f0eb  80c420                 -add ah, 0x20
    (cpu.ah) += x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a8f0ee:
    // 00a8f0ee  38e0                   +cmp al, ah
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
    // 00a8f0f0  7508                   -jne 0xa8f0fa
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f0fa;
    }
    // 00a8f0f2  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a8f0f4  7404                   -je 0xa8f0fa
    if (cpu.flags.zf)
    {
        goto L_0x00a8f0fa;
    }
    // 00a8f0f6  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8f0f7  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8f0f8  ebd9                   -jmp 0xa8f0d3
    goto L_0x00a8f0d3;
L_0x00a8f0fa:
    // 00a8f0fa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8f0fc  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a8f0fe  88e0                   -mov al, ah
    cpu.al = cpu.ah;
    // 00a8f100  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8f105  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f107  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f109  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f10a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f110(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f112  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f115  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8f117  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8f119  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a8f11b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f11d  e86ef8ffff             -call 0xa8e990
    cpu.esp -= 4;
    sub_a8e990(app, cpu);
    if (cpu.terminate) return;
    // 00a8f122  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a8f124  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a8f126  e865d6ffff             -call 0xa8c790
    cpu.esp -= 4;
    sub_a8c790(app, cpu);
    if (cpu.terminate) return;
    // 00a8f12b  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x00a8f12e:
    // 00a8f12e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8f130  e83bbcffff             -call 0xa8ad70
    cpu.esp -= 4;
    sub_a8ad70(app, cpu);
    if (cpu.terminate) return;
    // 00a8f135  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f137  7518                   -jne 0xa8f151
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f151;
    }
    // 00a8f139  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a8f13b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8f13d  e8ced6ffff             -call 0xa8c810
    cpu.esp -= 4;
    sub_a8c810(app, cpu);
    if (cpu.terminate) return;
    // 00a8f142  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f144  740b                   -je 0xa8f151
    if (cpu.flags.zf)
    {
        goto L_0x00a8f151;
    }
    // 00a8f146  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8f148  e8c3bcffff             -call 0xa8ae10
    cpu.esp -= 4;
    sub_a8ae10(app, cpu);
    if (cpu.terminate) return;
    // 00a8f14d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8f14f  ebdd                   -jmp 0xa8f12e
    goto L_0x00a8f12e;
L_0x00a8f151:
    // 00a8f151  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8f153  e818bcffff             -call 0xa8ad70
    cpu.esp -= 4;
    sub_a8ad70(app, cpu);
    if (cpu.terminate) return;
    // 00a8f158  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f15a  7404                   -je 0xa8f160
    if (cpu.flags.zf)
    {
        goto L_0x00a8f160;
    }
    // 00a8f15c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8f15e  7504                   -jne 0xa8f164
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f164;
    }
L_0x00a8f160:
    // 00a8f160  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8f162  eb02                   -jmp 0xa8f166
    goto L_0x00a8f166;
L_0x00a8f164:
    // 00a8f164  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8f166:
    // 00a8f166  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f169  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f16a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f16b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8f170(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8f172  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f174  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a8f176:
    // 00a8f176  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f178  e8f3bbffff             -call 0xa8ad70
    cpu.esp -= 4;
    sub_a8ad70(app, cpu);
    if (cpu.terminate) return;
    // 00a8f17d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f17f  750c                   -jne 0xa8f18d
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f18d;
    }
    // 00a8f181  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f183  e888bcffff             -call 0xa8ae10
    cpu.esp -= 4;
    sub_a8ae10(app, cpu);
    if (cpu.terminate) return;
    // 00a8f188  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8f189  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f18b  ebe9                   -jmp 0xa8f176
    goto L_0x00a8f176;
L_0x00a8f18d:
    // 00a8f18d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a8f18f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f190  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f191  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f1a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f1a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f1a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f1a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f1a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8f1a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8f1a6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a8f1a8  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a8f1aa  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a8f1ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f1ae  7438                   -je 0xa8f1e8
    if (cpu.flags.zf)
    {
        goto L_0x00a8f1e8;
    }
L_0x00a8f1b0:
    // 00a8f1b0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8f1b2  765a                   -jbe 0xa8f20e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8f20e;
    }
    // 00a8f1b4  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f1b7  7418                   -je 0xa8f1d1
    if (cpu.flags.zf)
    {
        goto L_0x00a8f1d1;
    }
    // 00a8f1b9  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a8f1be  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8f1c0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f1c2  e8b9050000             -call 0xa8f780
    cpu.esp -= 4;
    sub_a8f780(app, cpu);
    if (cpu.terminate) return;
    // 00a8f1c7  83f8ff                 +cmp eax, -1
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
    // 00a8f1ca  750c                   -jne 0xa8f1d8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f1d8;
    }
    // 00a8f1cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f1cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f1ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f1cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f1d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f1d1:
    // 00a8f1d1  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 00a8f1d6  eb36                   -jmp 0xa8f20e
    goto L_0x00a8f20e;
L_0x00a8f1d8:
    // 00a8f1d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f1da  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a8f1db  e830bcffff             -call 0xa8ae10
    cpu.esp -= 4;
    sub_a8ae10(app, cpu);
    if (cpu.terminate) return;
    // 00a8f1e0  83c602                 +add esi, 2
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
    // 00a8f1e3  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8f1e4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8f1e6  ebc8                   -jmp 0xa8f1b0
    goto L_0x00a8f1b0;
L_0x00a8f1e8:
    // 00a8f1e8  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x00a8f1ed:
    // 00a8f1ed  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f1f0  741c                   -je 0xa8f20e
    if (cpu.flags.zf)
    {
        goto L_0x00a8f20e;
    }
    // 00a8f1f2  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a8f1f4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8f1f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f1f8  e883050000             -call 0xa8f780
    cpu.esp -= 4;
    sub_a8f780(app, cpu);
    if (cpu.terminate) return;
    // 00a8f1fd  83f8ff                 +cmp eax, -1
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
    // 00a8f200  740e                   -je 0xa8f210
    if (cpu.flags.zf)
    {
        goto L_0x00a8f210;
    }
    // 00a8f202  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f204  e807bcffff             -call 0xa8ae10
    cpu.esp -= 4;
    sub_a8ae10(app, cpu);
    if (cpu.terminate) return;
    // 00a8f209  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a8f20a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8f20c  ebdf                   -jmp 0xa8f1ed
    goto L_0x00a8f1ed;
L_0x00a8f20e:
    // 00a8f20e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a8f210:
    // 00a8f210  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f211  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f212  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f213  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f214  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f220  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f221  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8f223  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f224  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f225  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8f226  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f229  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8f22b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a8f230  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a8f234  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a8f237  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a8f23c  e8df050000             -call 0xa8f820
    cpu.esp -= 4;
    sub_a8f820(app, cpu);
    if (cpu.terminate) return;
    // 00a8f241  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8f243  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f245  750a                   -jne 0xa8f251
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f251;
    }
    // 00a8f247  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f24c  e95a010000             -jmp 0xa8f3ab
    goto L_0x00a8f3ab;
L_0x00a8f251:
    // 00a8f251  39c8                   +cmp eax, ecx
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
    // 00a8f253  750f                   -jne 0xa8f264
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f264;
    }
    // 00a8f255  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f25a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f25d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f25e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f25f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f260  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f261  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f262  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f263  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f264:
    // 00a8f264  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a8f266  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a8f268  8d2c4500000000         -lea ebp, [eax*2]
    cpu.ebp = x86::reg32(cpu.eax * 2);
    // 00a8f26f  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00a8f272  e8397affff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f277  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8f279  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a8f27d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f27f  750f                   -jne 0xa8f290
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f290;
    }
    // 00a8f281  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f286  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f289  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f28a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f28b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f28c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f28d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f28e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f28f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f290:
    // 00a8f290  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a8f292  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8f294  e847ceffff             -call 0xa8c0e0
    cpu.esp -= 4;
    sub_a8c0e0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f299  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00a8f29c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f29e  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 00a8f2a4  e817ceffff             -call 0xa8c0c0
    cpu.esp -= 4;
    sub_a8c0c0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f2a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f2ab  7442                   -je 0xa8f2ef
    if (cpu.flags.zf)
    {
        goto L_0x00a8f2ef;
    }
    // 00a8f2ad  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f2af  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a8f2b3  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8f2b6  e8f579ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f2bb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8f2bd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8f2bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f2c1  7516                   -jne 0xa8f2d9
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f2d9;
    }
    // 00a8f2c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f2c5  e8d67affff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f2ca  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f2cf  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f2d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f2d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f2d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f2d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f2d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f2d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f2d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f2d9:
    // 00a8f2d9  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8f2dd  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a8f2e1  01f7                   +add edi, esi
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
    // 00a8f2e3  e8f8cdffff             -call 0xa8c0e0
    cpu.esp -= 4;
    sub_a8c0e0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f2e8  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 00a8f2ed  eb02                   -jmp 0xa8f2f1
    goto L_0x00a8f2f1;
L_0x00a8f2ef:
    // 00a8f2ef  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a8f2f1:
    // 00a8f2f1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8f2f5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a8f2f7  e854050000             -call 0xa8f850
    cpu.esp -= 4;
    sub_a8f850(app, cpu);
    if (cpu.terminate) return;
    // 00a8f2fc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f2fe  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8f302  e8997affff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f307  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8f309  e8927affff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f30e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8f310  750f                   -jne 0xa8f321
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f321;
    }
    // 00a8f312  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f317  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f31a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f31b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f31c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f31d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f31e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f31f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f320  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f321:
    // 00a8f321  833da83ea90000         +cmp dword ptr [0xa93ea8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8f328  7505                   -jne 0xa8f32f
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f32f;
    }
    // 00a8f32a  e821060000             -call 0xa8f950
    cpu.esp -= 4;
    sub_a8f950(app, cpu);
    if (cpu.terminate) return;
L_0x00a8f32f:
    // 00a8f32f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f331  e882000000             -call 0xa8f3b8
    cpu.esp -= 4;
    sub_a8f3b8(app, cpu);
    if (cpu.terminate) return;
    // 00a8f336  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f338  740f                   -je 0xa8f349
    if (cpu.flags.zf)
    {
        goto L_0x00a8f349;
    }
    // 00a8f33a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f33f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f342  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f343  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f344  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f345  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f346  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f347  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f348  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f349:
    // 00a8f349  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f34b  e870cdffff             -call 0xa8c0c0
    cpu.esp -= 4;
    sub_a8c0c0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f350  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8f353  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8f357  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a8f35a  e85179ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f35f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8f361  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f363  7519                   -jne 0xa8f37e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f37e;
    }
    // 00a8f365  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a8f36a  e8cdccffff             -call 0xa8c03c
    cpu.esp -= 4;
    sub_a8c03c(app, cpu);
    if (cpu.terminate) return;
    // 00a8f36f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f374  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f377  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f378  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f379  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f37a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f37b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f37c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f37d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f37e:
    // 00a8f37e  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00a8f382  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a8f384  e827060000             -call 0xa8f9b0
    cpu.esp -= 4;
    sub_a8f9b0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f389  83f8ff                 +cmp eax, -1
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
    // 00a8f38c  7516                   -jne 0xa8f3a4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f3a4;
    }
    // 00a8f38e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f390  e80b7affff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f395  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f39a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f39d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f39e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f39f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f3a4:
    // 00a8f3a4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f3a6  e881f2ffff             -call 0xa8e62c
    cpu.esp -= 4;
    sub_a8e62c(app, cpu);
    if (cpu.terminate) return;
L_0x00a8f3ab:
    // 00a8f3ab  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a8f3ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f3b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8f3b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f3b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f3b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f3ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8f3bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f3bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f3bd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8f3be  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8f3c1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8f3c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f3c5  750a                   -jne 0xa8f3d1
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f3d1;
    }
    // 00a8f3c7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f3cc  e963010000             -jmp 0xa8f534
    goto L_0x00a8f534;
L_0x00a8f3d1:
    // 00a8f3d1  66833800               +cmp word ptr [eax], 0
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
    // 00a8f3d5  741b                   -je 0xa8f3f2
    if (cpu.flags.zf)
    {
        goto L_0x00a8f3f2;
    }
    // 00a8f3d7  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a8f3da  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8f3de  7412                   -je 0xa8f3f2
    if (cpu.flags.zf)
    {
        goto L_0x00a8f3f2;
    }
L_0x00a8f3e0:
    // 00a8f3e0  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8f3e4  740c                   -je 0xa8f3f2
    if (cpu.flags.zf)
    {
        goto L_0x00a8f3f2;
    }
    // 00a8f3e6  668b7202               -mov si, word ptr [edx + 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00a8f3ea  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8f3ed  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 00a8f3f0  75ee                   -jne 0xa8f3e0
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f3e0;
    }
L_0x00a8f3f2:
    // 00a8f3f2  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8f3f6  750f                   -jne 0xa8f407
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f407;
    }
    // 00a8f3f8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f3fd  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8f400  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f401  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f402  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f403  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f404  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f405  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f406  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f407:
    // 00a8f407  66837a0200             +cmp word ptr [edx + 2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8f40c  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a8f40f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8f411  8b0da83ea900           -mov ecx, dword ptr [0xa93ea8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */);
    // 00a8f417  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00a8f419  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a8f41b  7541                   -jne 0xa8f45e
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f45e;
    }
    // 00a8f41d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8f41f  0f850d010000           -jne 0xa8f532
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f532;
    }
    // 00a8f425  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a8f42a  e88178ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f42f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8f431  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f433  750f                   -jne 0xa8f444
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f444;
    }
    // 00a8f435  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f43a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8f43d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f43e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f43f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f440  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f441  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f442  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f443  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f444:
    // 00a8f444  a3a83ea900             -mov dword ptr [0xa93ea8], eax
    app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */) = cpu.eax;
    // 00a8f449  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8f44c  8958f8                 -mov dword ptr [eax - 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00a8f44f  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a8f451  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a8f454  a3a03ea900             -mov dword ptr [0xa93ea0], eax
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.eax;
    // 00a8f459  e9c8000000             -jmp 0xa8f526
    goto L_0x00a8f526;
L_0x00a8f45e:
    // 00a8f45e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a8f460  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8f462  e8d9000000             -call 0xa8f540
    cpu.esp -= 4;
    sub_a8f540(app, cpu);
    if (cpu.terminate) return;
    // 00a8f467  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8f469  0f85c3000000           -jne 0xa8f532
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f532;
    }
    // 00a8f46f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f471  0f8fac000000           -jg 0xa8f523
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a8f523;
    }
    // 00a8f477  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a8f479  8b2da03ea900           -mov ebp, dword ptr [0xa93ea0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8f47f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8f481  40                     -inc eax
    (cpu.eax)++;
    // 00a8f482  8d1cb500000000         -lea ebx, [esi*4]
    cpu.ebx = x86::reg32(cpu.esi * 4);
    // 00a8f489  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8f48c  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a8f48f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8f492  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a8f496  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8f498  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8f49a  753e                   -jne 0xa8f4da
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f4da;
    }
    // 00a8f49c  e80f78ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f4a1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8f4a3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8f4a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f4a7  750f                   -jne 0xa8f4b8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f4b8;
    }
    // 00a8f4a9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f4ae  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8f4b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f4b8:
    // 00a8f4b8  8b15a83ea900           -mov edx, dword ptr [0xa93ea8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */);
    // 00a8f4be  e81dccffff             -call 0xa8c0e0
    cpu.esp -= 4;
    sub_a8c0e0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f4c3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8f4c7  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8f4ca  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8f4cc  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a8f4ce  a3a03ea900             -mov dword ptr [0xa93ea0], eax
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.eax;
    // 00a8f4d3  e8d875ffff             -call 0xa86ab0
    cpu.esp -= 4;
    sub_a86ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f4d8  eb39                   -jmp 0xa8f513
    goto L_0x00a8f513;
L_0x00a8f4da:
    // 00a8f4da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f4dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f4de  e80dbcffff             -call 0xa8b0f0
    cpu.esp -= 4;
    sub_a8b0f0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f4e3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8f4e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f4e7  750f                   -jne 0xa8f4f8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f4f8;
    }
    // 00a8f4e9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a8f4ee  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8f4f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f4f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f4f8:
    // 00a8f4f8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8f4fc  8b15a03ea900           -mov edx, dword ptr [0xa93ea0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8f502  01c5                   +add ebp, eax
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
    // 00a8f504  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a8f506  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8f508  e843010000             -call 0xa8f650
    cpu.esp -= 4;
    sub_a8f650(app, cpu);
    if (cpu.terminate) return;
    // 00a8f50d  892da03ea900           -mov dword ptr [0xa93ea0], ebp
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.ebp;
L_0x00a8f513:
    // 00a8f513  890da83ea900           -mov dword ptr [0xa93ea8], ecx
    app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */) = cpu.ecx;
    // 00a8f519  c744b10400000000       -mov dword ptr [ecx + esi*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.esi * 4) = 0 /*0x0*/;
    // 00a8f521  eb03                   -jmp 0xa8f526
    goto L_0x00a8f526;
L_0x00a8f523:
    // 00a8f523  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a8f526:
    // 00a8f526  a1a03ea900             -mov eax, dword ptr [0xa93ea0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8f52b  893cb1                 -mov dword ptr [ecx + esi*4], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 4) = cpu.edi;
    // 00a8f52e  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x00a8f532:
    // 00a8f532  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8f534:
    // 00a8f534  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a8f537  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f538  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f539  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f53a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f53b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f53c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f53d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a8f540(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f541  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f542  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f543  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f544  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8f545  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8f547  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a8f549  8b35a83ea900           -mov esi, dword ptr [0xa93ea8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */);
    // 00a8f54f  e9d7000000             -jmp 0xa8f62b
    goto L_0x00a8f62b;
L_0x00a8f554:
    // 00a8f554  668b0f                 -mov cx, word ptr [edi]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edi);
    // 00a8f557  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a8f559  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a8f55c  0f84c6000000           -je 0xa8f628
    if (cpu.flags.zf)
    {
        goto L_0x00a8f628;
    }
L_0x00a8f562:
    // 00a8f562  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f564  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 00a8f567  e804050000             -call 0xa8fa70
    cpu.esp -= 4;
    sub_a8fa70(app, cpu);
    if (cpu.terminate) return;
    // 00a8f56c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8f56e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f570  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 00a8f573  e8f8040000             -call 0xa8fa70
    cpu.esp -= 4;
    sub_a8fa70(app, cpu);
    if (cpu.terminate) return;
    // 00a8f578  6639c1                 +cmp cx, ax
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
    // 00a8f57b  0f85a7000000           -jne 0xa8f628
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f628;
    }
    // 00a8f581  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8f585  0f858a000000           -jne 0xa8f615
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f615;
    }
    // 00a8f58b  8b15a83ea900           -mov edx, dword ptr [0xa93ea8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */);
    // 00a8f591  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a8f593  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8f595  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a8f598  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a8f59a  0f846c000000           -je 0xa8f60c
    if (cpu.flags.zf)
    {
        goto L_0x00a8f60c;
    }
    // 00a8f5a0  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8f5a2  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a8f5a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8f5a6  740f                   -je 0xa8f5b7
    if (cpu.flags.zf)
    {
        goto L_0x00a8f5b7;
    }
L_0x00a8f5a8:
    // 00a8f5a8  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8f5ab  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a8f5ad  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a8f5b0  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f5b3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8f5b5  75f1                   -jne 0xa8f5a8
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f5a8;
    }
L_0x00a8f5b7:
    // 00a8f5b7  8b35a03ea900           -mov esi, dword ptr [0xa93ea0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8f5bd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8f5bf  7443                   -je 0xa8f604
    if (cpu.flags.zf)
    {
        goto L_0x00a8f604;
    }
    // 00a8f5c1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f5c3  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f5c7  7407                   -je 0xa8f5d0
    if (cpu.flags.zf)
    {
        goto L_0x00a8f5d0;
    }
    // 00a8f5c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f5cb  e8d077ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8f5d0:
    // 00a8f5d0  8b2da83ea900           -mov ebp, dword ptr [0xa93ea8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */);
    // 00a8f5d6  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a8f5d8  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a8f5da  8b15a03ea900           -mov edx, dword ptr [0xa93ea0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */);
    // 00a8f5e0  c1fe02                 -sar esi, 2
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (2 /*0x2*/ % 32));
    // 00a8f5e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f5e5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a8f5e7  e864000000             -call 0xa8f650
    cpu.esp -= 4;
    sub_a8f650(app, cpu);
    if (cpu.terminate) return;
    // 00a8f5ec  890da03ea900           -mov dword ptr [0xa93ea0], ecx
    app->getMemory<x86::reg32>(x86::reg32(11091616) /* 0xa93ea0 */) = cpu.ecx;
    // 00a8f5f2  39f7                   +cmp edi, esi
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
    // 00a8f5f4  7d0e                   -jge 0xa8f604
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a8f604;
    }
    // 00a8f5f6  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
L_0x00a8f5f9:
    // 00a8f5f9  40                     -inc eax
    (cpu.eax)++;
    // 00a8f5fa  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a8f5fc  47                     -inc edi
    (cpu.edi)++;
    // 00a8f5fd  8850ff                 -mov byte ptr [eax - 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a8f600  39f7                   +cmp edi, esi
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
    // 00a8f602  7cf5                   -jl 0xa8f5f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a8f5f9;
    }
L_0x00a8f604:
    // 00a8f604  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f606  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f608  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f609  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f60a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f60b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f60c:
    // 00a8f60c  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a8f60f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f610  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f611  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f612  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f613  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f614  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f615:
    // 00a8f615  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8f618  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a8f61c  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8f61f  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 00a8f622  0f853affffff           -jne 0xa8f562
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f562;
    }
L_0x00a8f628:
    // 00a8f628  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a8f62b:
    // 00a8f62b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8f62d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8f62f  0f851fffffff           -jne 0xa8f554
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f554;
    }
    // 00a8f635  a1a83ea900             -mov eax, dword ptr [0xa93ea8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11091624) /* 0xa93ea8 */);
    // 00a8f63a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a8f63c  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00a8f63f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f640  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f641  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f642  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f643  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f644  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f650(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f650  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f651  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f652  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f653  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a8f655  39c2                   +cmp edx, eax
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
    // 00a8f657  7440                   -je 0xa8f699
    if (cpu.flags.zf)
    {
        goto L_0x00a8f699;
    }
    // 00a8f659  7328                   -jae 0xa8f683
    if (!cpu.flags.cf)
    {
        goto L_0x00a8f683;
    }
    // 00a8f65b  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a8f65e  39c7                   +cmp edi, eax
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
    // 00a8f660  7621                   -jbe 0xa8f683
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8f683;
    }
    // 00a8f662  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00a8f665  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00a8f668  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a8f66a  4f                     -dec edi
    (cpu.edi)--;
    // 00a8f66b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8f66c  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a8f66e  fd                     -std 
    cpu.flags.df = 1;
    // 00a8f66f  4e                     -dec esi
    (cpu.esi)--;
    // 00a8f670  4f                     -dec edi
    (cpu.edi)--;
    // 00a8f671  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 00a8f673  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
    while (cpu.ecx)
    {
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
        --cpu.ecx;
    }
    // 00a8f676  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00a8f678  46                     -inc esi
    (cpu.esi)++;
    // 00a8f679  47                     -inc edi
    (cpu.edi)++;
    // 00a8f67a  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 00a8f67d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8f67e  fc                     -cld 
    cpu.flags.df = 0;
    // 00a8f67f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f680  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f681  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f682  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f683:
    // 00a8f683  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a8f685  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8f687  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a8f689  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8f68a  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a8f68c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f68d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8f690  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8f692  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f693  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a8f696  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 00a8f698  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a8f699:
    // 00a8f699  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f69a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f69b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f69c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a8f6a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f6a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8f6a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f6a3  e8d8030000             -call 0xa8fa80
    cpu.esp -= 4;
    sub_a8fa80(app, cpu);
    if (cpu.terminate) return;
    // 00a8f6a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f6aa  7403                   -je 0xa8f6af
    if (cpu.flags.zf)
    {
        goto L_0x00a8f6af;
    }
    // 00a8f6ac  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x00a8f6af:
    // 00a8f6af  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f6b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f6b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f6c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f6c0  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00a8f6c2  740e                   -je 0xa8f6d2
    if (cpu.flags.zf)
    {
        goto L_0x00a8f6d2;
    }
    // 00a8f6c4  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 00a8f6ca  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00a8f6d0  eb0c                   -jmp 0xa8f6de
    goto L_0x00a8f6de;
L_0x00a8f6d2:
    // 00a8f6d2  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 00a8f6d8  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
L_0x00a8f6de:
    // 00a8f6de  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a8f6e0  7403                   -je 0xa8f6e5
    if (cpu.flags.zf)
    {
        goto L_0x00a8f6e5;
    }
    // 00a8f6e2  800b02                 -or byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00a8f6e5:
    // 00a8f6e5  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00a8f6e7  7403                   -je 0xa8f6ec
    if (cpu.flags.zf)
    {
        goto L_0x00a8f6ec;
    }
    // 00a8f6e9  800b04                 -or byte ptr [ebx], 4
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00a8f6ec:
    // 00a8f6ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8f6f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f6f0  83f802                 +cmp eax, 2
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
    // 00a8f6f3  750d                   -jne 0xa8f702
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f702;
    }
    // 00a8f6f5  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 00a8f6fb  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 00a8f701  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f702:
    // 00a8f702  83f801                 +cmp eax, 1
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
    // 00a8f705  750d                   -jne 0xa8f714
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f714;
    }
    // 00a8f707  c70200000040           -mov dword ptr [edx], 0x40000000
    app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 00a8f70d  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 00a8f713  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f714:
    // 00a8f714  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 00a8f71a  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 00a8f720  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a8f724(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f724  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f725  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a8f727  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a8f72a  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a8f72d  83f820                 +cmp eax, 0x20
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
    // 00a8f730  7210                   -jb 0xa8f742
    if (cpu.flags.cf)
    {
        goto L_0x00a8f742;
    }
    // 00a8f732  7638                   -jbe 0xa8f76c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8f76c;
    }
    // 00a8f734  83f830                 +cmp eax, 0x30
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8f737  7241                   -jb 0xa8f77a
    if (cpu.flags.cf)
    {
        goto L_0x00a8f77a;
    }
    // 00a8f739  7629                   -jbe 0xa8f764
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8f764;
    }
    // 00a8f73b  83f840                 +cmp eax, 0x40
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
    // 00a8f73e  7434                   -je 0xa8f774
    if (cpu.flags.zf)
    {
        goto L_0x00a8f774;
    }
    // 00a8f740  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f741  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f742:
    // 00a8f742  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f744  7607                   -jbe 0xa8f74d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8f74d;
    }
    // 00a8f746  83f810                 +cmp eax, 0x10
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
    // 00a8f749  7411                   -je 0xa8f75c
    if (cpu.flags.zf)
    {
        goto L_0x00a8f75c;
    }
    // 00a8f74b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f74c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f74d:
    // 00a8f74d  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00a8f753  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8f755  7523                   -jne 0xa8f77a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f77a;
    }
    // 00a8f757  800a02                 -or byte ptr [edx], 2
    app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00a8f75a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f75b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f75c:
    // 00a8f75c  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 00a8f762  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f763  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f764:
    // 00a8f764  c70202000000           -mov dword ptr [edx], 2
    app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 00a8f76a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f76b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f76c:
    // 00a8f76c  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 00a8f772  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f773  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f774:
    // 00a8f774  c70203000000           -mov dword ptr [edx], 3
    app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x00a8f77a:
    // 00a8f77a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f77b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a8f780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f780  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f781  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f782  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f783  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8f784  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a8f786  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f789  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8f78b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8f78d  7507                   -jne 0xa8f796
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f796;
    }
    // 00a8f78f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a8f791  e983000000             -jmp 0xa8f819
    goto L_0x00a8f819;
L_0x00a8f796:
    // 00a8f796  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a8f798  0f8676000000           -jbe 0xa8f814
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8f814;
    }
    // 00a8f79e  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f7a1  7512                   -jne 0xa8f7b5
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f7b5;
    }
    // 00a8f7a3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8f7a5  7405                   -je 0xa8f7ac
    if (cpu.flags.zf)
    {
        goto L_0x00a8f7ac;
    }
    // 00a8f7a7  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
L_0x00a8f7ac:
    // 00a8f7ac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f7ae  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a8f7b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f7b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f7b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f7b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f7b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f7b5:
    // 00a8f7b5  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8f7bc  7419                   -je 0xa8f7d7
    if (cpu.flags.zf)
    {
        goto L_0x00a8f7d7;
    }
    // 00a8f7be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f7c0  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a8f7c2  8a80614aa900           -mov al, byte ptr [eax + 0xa94a61]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8f7c8  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8f7ca  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8f7cf  7406                   -je 0xa8f7d7
    if (cpu.flags.zf)
    {
        goto L_0x00a8f7d7;
    }
    // 00a8f7d1  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a8f7d5  743d                   -je 0xa8f814
    if (cpu.flags.zf)
    {
        goto L_0x00a8f814;
    }
L_0x00a8f7d7:
    // 00a8f7d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f7d9  e8b2cfffff             -call 0xa8c790
    cpu.esp -= 4;
    sub_a8c790(app, cpu);
    if (cpu.terminate) return;
    // 00a8f7de  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a8f7e0  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a8f7e3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a8f7e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f7e6  39c3                   +cmp ebx, eax
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
    // 00a8f7e8  7302                   -jae 0xa8f7ec
    if (!cpu.flags.cf)
    {
        goto L_0x00a8f7ec;
    }
    // 00a8f7ea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a8f7ec:
    // 00a8f7ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8f7ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8f7ee  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00a8f7f0  a17c2ba900             -mov eax, dword ptr [0xa92b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11086716) /* 0xa92b7c */);
    // 00a8f7f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8f7f6  2eff15f403a900         -call dword ptr cs:[0xa903f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076596) /* 0xa903f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8f7fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f7ff  7413                   -je 0xa8f814
    if (cpu.flags.zf)
    {
        goto L_0x00a8f814;
    }
    // 00a8f801  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8f803  7406                   -je 0xa8f80b
    if (cpu.flags.zf)
    {
        goto L_0x00a8f80b;
    }
    // 00a8f805  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a8f808  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x00a8f80b:
    // 00a8f80b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8f80d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a8f80f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f810  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f811  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f812  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f813  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f814:
    // 00a8f814  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a8f819:
    // 00a8f819  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a8f81b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f81c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f81d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f81e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f81f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8f820(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f820  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f821  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f822  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f823  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a8f826  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a8f828  6639ca                 +cmp dx, cx
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.cx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8f82b  7416                   -je 0xa8f843
    if (cpu.flags.zf)
    {
        goto L_0x00a8f843;
    }
L_0x00a8f82d:
    // 00a8f82d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f82f  668b3a                 -mov di, word ptr [edx]
    cpu.di = app->getMemory<x86::reg16>(cpu.edx);
    // 00a8f832  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8f835  6685ff                 +test di, di
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & cpu.di));
    // 00a8f838  7407                   -je 0xa8f841
    if (cpu.flags.zf)
    {
        goto L_0x00a8f841;
    }
    // 00a8f83a  663b18                 +cmp bx, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8f83d  7404                   -je 0xa8f843
    if (cpu.flags.zf)
    {
        goto L_0x00a8f843;
    }
    // 00a8f83f  ebec                   -jmp 0xa8f82d
    goto L_0x00a8f82d;
L_0x00a8f841:
    // 00a8f841  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8f843:
    // 00a8f843  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f844  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f845  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f846  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f850(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f851  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f852  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f853  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f854  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8f855  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f858  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8f85b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a8f85d  66813d8527a9000080     +cmp word ptr [0xa92785], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(11085701) /* 0xa92785 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8f866  730e                   -jae 0xa8f876
    if (!cpu.flags.cf)
    {
        goto L_0x00a8f876;
    }
    // 00a8f868  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f869  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a8f86a  2eff150004a900         -call dword ptr cs:[0xa90400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076608) /* 0xa90400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8f871  e9c3000000             -jmp 0xa8f939
    goto L_0x00a8f939;
L_0x00a8f876:
    // 00a8f876  e845c8ffff             -call 0xa8c0c0
    cpu.esp -= 4;
    sub_a8c0c0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f87b  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f87d  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8f880  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f882  e82974ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f887  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f889  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a8f88b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f88d  0f84a6000000           -je 0xa8f939
    if (cpu.flags.zf)
    {
        goto L_0x00a8f939;
    }
    // 00a8f893  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a8f895  7504                   -jne 0xa8f89b
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f89b;
    }
    // 00a8f897  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a8f899  eb2b                   -jmp 0xa8f8c6
    goto L_0x00a8f8c6;
L_0x00a8f89b:
    // 00a8f89b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a8f89d  e81ec8ffff             -call 0xa8c0c0
    cpu.esp -= 4;
    sub_a8c0c0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f8a2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f8a4  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8f8a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f8a9  e80274ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f8ae  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a8f8b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f8b2  7512                   -jne 0xa8f8c6
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f8c6;
    }
    // 00a8f8b4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f8b6  e8e574ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f8bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f8bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f8c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f8c6:
    // 00a8f8c6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8f8c9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a8f8cb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8f8cd  e8de000000             -call 0xa8f9b0
    cpu.esp -= 4;
    sub_a8f9b0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f8d2  83f8ff                 +cmp eax, -1
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
    // 00a8f8d5  751d                   -jne 0xa8f8f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f8f4;
    }
    // 00a8f8d7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8f8d9  e8c274ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f8de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8f8e0  7407                   -je 0xa8f8e9
    if (cpu.flags.zf)
    {
        goto L_0x00a8f8e9;
    }
    // 00a8f8e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f8e4  e8b774ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8f8e9:
    // 00a8f8e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f8eb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f8ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f8f3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f8f4:
    // 00a8f8f4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8f8f6  7422                   -je 0xa8f91a
    if (cpu.flags.zf)
    {
        goto L_0x00a8f91a;
    }
    // 00a8f8f8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a8f8fa  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a8f8fc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f8fe  e8ad000000             -call 0xa8f9b0
    cpu.esp -= 4;
    sub_a8f9b0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f903  83f8ff                 +cmp eax, -1
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
    // 00a8f906  7512                   -jne 0xa8f91a
    if (!cpu.flags.zf)
    {
        goto L_0x00a8f91a;
    }
    // 00a8f908  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f90a  e89174ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f90f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8f911  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f914  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f915  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f916  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f917  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f918  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f919  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8f91a:
    // 00a8f91a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f91b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8f91c  2eff15fc03a900         -call dword ptr cs:[0xa903fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(11076604) /* 0xa903fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a8f923  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f925  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a8f927  e87474ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f92c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8f92e  7407                   -je 0xa8f937
    if (cpu.flags.zf)
    {
        goto L_0x00a8f937;
    }
    // 00a8f930  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a8f932  e86974ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
L_0x00a8f937:
    // 00a8f937  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a8f939:
    // 00a8f939  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f93c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f93d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f93e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f93f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f940  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f941  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f950(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a8f951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f952  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8f953  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f954  8b35a43ea900           -mov esi, dword ptr [0xa93ea4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11091620) /* 0xa93ea4 */);
    // 00a8f95a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a8f95c  7441                   -je 0xa8f99f
    if (cpu.flags.zf)
    {
        goto L_0x00a8f99f;
    }
L_0x00a8f95e:
    // 00a8f95e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a8f960  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a8f963  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a8f965  7438                   -je 0xa8f99f
    if (cpu.flags.zf)
    {
        goto L_0x00a8f99f;
    }
    // 00a8f967  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8f969  e802f8ffff             -call 0xa8f170
    cpu.esp -= 4;
    sub_a8f170(app, cpu);
    if (cpu.terminate) return;
    // 00a8f96e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a8f971  8d045d00000000         -lea eax, [ebx*2]
    cpu.eax = x86::reg32(cpu.ebx * 2);
    // 00a8f978  e83373ffff             -call 0xa86cb0
    cpu.esp -= 4;
    sub_a86cb0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f97d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8f97f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f981  74db                   -je 0xa8f95e
    if (cpu.flags.zf)
    {
        goto L_0x00a8f95e;
    }
    // 00a8f983  e818f8ffff             -call 0xa8f1a0
    cpu.esp -= 4;
    sub_a8f1a0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f988  83f8ff                 +cmp eax, -1
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
    // 00a8f98b  7409                   -je 0xa8f996
    if (cpu.flags.zf)
    {
        goto L_0x00a8f996;
    }
    // 00a8f98d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f98f  e824faffff             -call 0xa8f3b8
    cpu.esp -= 4;
    sub_a8f3b8(app, cpu);
    if (cpu.terminate) return;
    // 00a8f994  ebc8                   -jmp 0xa8f95e
    goto L_0x00a8f95e;
L_0x00a8f996:
    // 00a8f996  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8f998  e80374ffff             -call 0xa86da0
    cpu.esp -= 4;
    sub_a86da0(app, cpu);
    if (cpu.terminate) return;
    // 00a8f99d  ebbf                   -jmp 0xa8f95e
    goto L_0x00a8f95e;
L_0x00a8f99f:
    // 00a8f99f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f9a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f9a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f9a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8f9a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8f9b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8f9b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a8f9b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a8f9b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8f9b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a8f9b4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8f9b7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a8f9bb  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a8f9bd  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a8f9c0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a8f9c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8f9c4  0f8471000000           -je 0xa8fa3b
    if (cpu.flags.zf)
    {
        goto L_0x00a8fa3b;
    }
L_0x00a8f9ca:
    // 00a8f9ca  833c2400               +cmp dword ptr [esp], 0
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
    // 00a8f9ce  0f8689000000           -jbe 0xa8fa5d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a8fa5d;
    }
    // 00a8f9d4  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00a8f9d8  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a8f9db  7420                   -je 0xa8f9fd
    if (cpu.flags.zf)
    {
        goto L_0x00a8f9fd;
    }
    // 00a8f9dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8f9df  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8f9e3  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 00a8f9e6  e865c0ffff             -call 0xa8ba50
    cpu.esp -= 4;
    sub_a8ba50(app, cpu);
    if (cpu.terminate) return;
    // 00a8f9eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8f9ed  83f8ff                 +cmp eax, -1
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
    // 00a8f9f0  0f8469000000           -je 0xa8fa5f
    if (cpu.flags.zf)
    {
        goto L_0x00a8fa5f;
    }
    // 00a8f9f6  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00a8f9f9  7762                   -ja 0xa8fa5d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8fa5d;
    }
    // 00a8f9fb  eb09                   -jmp 0xa8fa06
    goto L_0x00a8fa06;
L_0x00a8f9fd:
    // 00a8f9fd  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8fa01  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a8fa04  eb57                   -jmp 0xa8fa5d
    goto L_0x00a8fa5d;
L_0x00a8fa06:
    // 00a8fa06  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8fa0a  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a8fa0e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a8fa10  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a8fa11  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a8fa13  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a8fa15  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a8fa16  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a8fa18  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a8fa1b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a8fa1d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a8fa1f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a8fa22  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a8fa24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8fa25  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a8fa26  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8fa29  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8fa2b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00a8fa2e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a8fa30  29d0                   +sub eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a8fa32  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a8fa36  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a8fa39  eb8f                   -jmp 0xa8f9ca
    goto L_0x00a8f9ca;
L_0x00a8fa3b:
    // 00a8fa3b  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8fa40  741b                   -je 0xa8fa5d
    if (cpu.flags.zf)
    {
        goto L_0x00a8fa5d;
    }
    // 00a8fa42  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8fa44  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a8fa48  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp);
    // 00a8fa4c  e8ffbfffff             -call 0xa8ba50
    cpu.esp -= 4;
    sub_a8ba50(app, cpu);
    if (cpu.terminate) return;
    // 00a8fa51  83f8ff                 +cmp eax, -1
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
    // 00a8fa54  7409                   -je 0xa8fa5f
    if (cpu.flags.zf)
    {
        goto L_0x00a8fa5f;
    }
    // 00a8fa56  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a8fa59  01c3                   +add ebx, eax
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
    // 00a8fa5b  ebde                   -jmp 0xa8fa3b
    goto L_0x00a8fa3b;
L_0x00a8fa5d:
    // 00a8fa5d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a8fa5f:
    // 00a8fa5f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a8fa62  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8fa63  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8fa64  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8fa65  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8fa66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8fa70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fa70  663d6100               +cmp ax, 0x61
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(97 /*0x61*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8fa74  7209                   -jb 0xa8fa7f
    if (cpu.flags.cf)
    {
        goto L_0x00a8fa7f;
    }
    // 00a8fa76  663d7a00               +cmp ax, 0x7a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(122 /*0x7a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a8fa7a  7703                   -ja 0xa8fa7f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8fa7f;
    }
    // 00a8fa7c  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a8fa7f:
    // 00a8fa7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a8fa80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fa80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8fa81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8fa83  e848000000             -call 0xa8fad0
    cpu.esp -= 4;
    sub_a8fad0(app, cpu);
    if (cpu.terminate) return;
    // 00a8fa88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8fa8a  741f                   -je 0xa8faab
    if (cpu.flags.zf)
    {
        goto L_0x00a8faab;
    }
    // 00a8fa8c  81fa81820000           +cmp edx, 0x8281
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33409 /*0x8281*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8fa92  7211                   -jb 0xa8faa5
    if (cpu.flags.cf)
    {
        goto L_0x00a8faa5;
    }
    // 00a8fa94  81fa9a820000           +cmp edx, 0x829a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33434 /*0x829a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8fa9a  7709                   -ja 0xa8faa5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a8faa5;
    }
    // 00a8fa9c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a8faa1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8faa3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8faa4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8faa5:
    // 00a8faa5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8faa7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8faa9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8faaa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8faab:
    // 00a8faab  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a8faad  fec0                   -inc al
    (cpu.al)++;
    // 00a8faaf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8fab4  8a807825a900           -mov al, byte ptr [eax + 0xa92578]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11085176) /* 0xa92578 */);
    // 00a8faba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a8fabc  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a8fabe  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a8fac0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a8fac2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8fac3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a8fad0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fad0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a8fad1  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8fad8  7431                   -je 0xa8fb0b
    if (cpu.flags.zf)
    {
        goto L_0x00a8fb0b;
    }
    // 00a8fada  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a8fadc  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a8fadf  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8fae5  8a92614aa900           -mov dl, byte ptr [edx + 0xa94a61]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11094625) /* 0xa94a61 */);
    // 00a8faeb  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a8faee  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a8faf4  7415                   -je 0xa8fb0b
    if (cpu.flags.zf)
    {
        goto L_0x00a8fb0b;
    }
    // 00a8faf6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8fafb  e810000000             -call 0xa8fb10
    cpu.esp -= 4;
    sub_a8fb10(app, cpu);
    if (cpu.terminate) return;
    // 00a8fb00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8fb02  7407                   -je 0xa8fb0b
    if (cpu.flags.zf)
    {
        goto L_0x00a8fb0b;
    }
    // 00a8fb04  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8fb09  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8fb0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8fb0b:
    // 00a8fb0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a8fb0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a8fb0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a8fb10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a8fb10  833d504aa90000         +cmp dword ptr [0xa94a50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11094608) /* 0xa94a50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8fb17  7429                   -je 0xa8fb42
    if (cpu.flags.zf)
    {
        goto L_0x00a8fb42;
    }
    // 00a8fb19  813d7c2ba900a4030000   +cmp dword ptr [0xa92b7c], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11086716) /* 0xa92b7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a8fb23  740a                   -je 0xa8fb2f
    if (cpu.flags.zf)
    {
        goto L_0x00a8fb2f;
    }
    // 00a8fb25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a8fb27  741b                   -je 0xa8fb44
    if (cpu.flags.zf)
    {
        goto L_0x00a8fb44;
    }
    // 00a8fb29  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a8fb2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8fb2f:
    // 00a8fb2f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8fb34  8a80192ca900           -mov al, byte ptr [eax + 0xa92c19]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11086873) /* 0xa92c19 */);
    // 00a8fb3a  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a8fb3c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a8fb41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a8fb42:
    // 00a8fb42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a8fb44:
    // 00a8fb44  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
