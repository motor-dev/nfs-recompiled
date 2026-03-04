#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_495d6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495d6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495d6d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00495d6e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495d70  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495d72  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00495d74  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00495d76  42                     -inc edx
    (cpu.edx)++;
    // 00495d77  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00495d79  7416                   -je 0x495d91
    if (cpu.flags.zf)
    {
        goto L_0x00495d91;
    }
    // 00495d7b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495d7c  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00495d7e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00495d81  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00495d83  42                     -inc edx
    (cpu.edx)++;
    // 00495d84  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495d86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d87  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00495d89  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00495d8e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495d90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495d91:
    // 00495d91  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00495d96  e8b9ffffff             -call 0x495d54
    cpu.esp -= 4;
    sub_495d54(app, cpu);
    if (cpu.terminate) return;
    // 00495d9b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00495d9d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00495da2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495da3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495da4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_495db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495db0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00495db1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495db2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495db3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495db4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00495db6  8b35dc844c00           -mov esi, dword ptr [0x4c84dc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 00495dbc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495dbe  39f0                   +cmp eax, esi
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
    // 00495dc0  7c4e                   -jl 0x495e10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495e10;
    }
    // 00495dc2  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 00495dc8  7d46                   -jge 0x495e10
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495e10;
    }
    // 00495dca  3b15e0844c00           +cmp edx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495dd0  7c3e                   -jl 0x495e10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495e10;
    }
    // 00495dd2  3b15e8844c00           +cmp edx, dword ptr [0x4c84e8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495dd8  7d36                   -jge 0x495e10
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495e10;
    }
    // 00495dda  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00495ddf  8b3500854c00           -mov esi, dword ptr [0x4c8500]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00495de5  8b1490                 -mov edx, dword ptr [eax + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00495de8  8b3c9e                 -mov edi, dword ptr [esi + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 4);
    // 00495deb  a1f0844c00             -mov eax, dword ptr [0x4c84f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014768) /* 0x4c84f0 */);
    // 00495df0  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00495df2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00495df4  a0ec844c00             -mov al, byte ptr [0x4c84ec]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5014764) /* 0x4c84ec */);
    // 00495df9  3c0f                   +cmp al, 0xf
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
    // 00495dfb  731a                   -jae 0x495e17
    if (!cpu.flags.cf)
    {
        goto L_0x00495e17;
    }
    // 00495dfd  3c04                   +cmp al, 4
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
    // 00495dff  720f                   -jb 0x495e10
    if (cpu.flags.cf)
    {
        goto L_0x00495e10;
    }
    // 00495e01  772f                   -ja 0x495e32
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00495e32;
    }
    // 00495e03  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00495e06  7432                   -je 0x495e3a
    if (cpu.flags.zf)
    {
        goto L_0x00495e3a;
    }
    // 00495e08  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00495e0a  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 00495e0d  83e10f                 +and ecx, 0xf
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/))));
L_0x00495e10:
    // 00495e10  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495e12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e15  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495e17:
    // 00495e17  7608                   -jbe 0x495e21
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495e21;
    }
    // 00495e19  3c18                   +cmp al, 0x18
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
    // 00495e1b  730b                   -jae 0x495e28
    if (!cpu.flags.cf)
    {
        goto L_0x00495e28;
    }
    // 00495e1d  3c10                   +cmp al, 0x10
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
    // 00495e1f  75ef                   -jne 0x495e10
    if (!cpu.flags.zf)
    {
        goto L_0x00495e10;
    }
L_0x00495e21:
    // 00495e21  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00495e23  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 00495e26  ebe8                   -jmp 0x495e10
    goto L_0x00495e10;
L_0x00495e28:
    // 00495e28  761c                   -jbe 0x495e46
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00495e46;
    }
    // 00495e2a  3c20                   +cmp al, 0x20
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
    // 00495e2c  75e2                   -jne 0x495e10
    if (!cpu.flags.zf)
    {
        goto L_0x00495e10;
    }
    // 00495e2e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00495e30  ebde                   -jmp 0x495e10
    goto L_0x00495e10;
L_0x00495e32:
    // 00495e32  3c08                   +cmp al, 8
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
    // 00495e34  75da                   -jne 0x495e10
    if (!cpu.flags.zf)
    {
        goto L_0x00495e10;
    }
    // 00495e36  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00495e38  ebd6                   -jmp 0x495e10
    goto L_0x00495e10;
L_0x00495e3a:
    // 00495e3a  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00495e3c  83e10f                 -and ecx, 0xf
    cpu.ecx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00495e3f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495e41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00495e46:
    // 00495e46  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00495e4b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00495e4d  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 00495e51  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00495e53  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00495e5a  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00495e5c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00495e5e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00495e60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_495e68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495e68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495e69  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00495e6b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00495e6d  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00495e6f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00495e71  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00495e78  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00495e7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495e7c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495e7d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00495e7f  8b4408fc               -mov eax, dword ptr [eax + ecx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 1);
    // 00495e83  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 00495e85  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 00495e8c  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 00495e8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495e8f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495e90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495e91  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00495e93  8d4408ff               -lea eax, [eax + ecx - 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1);
    // 00495e97  83e901                 +sub ecx, 1
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
    // 00495e9a  7c0d                   -jl 0x495ea9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495ea9;
    }
L_0x00495e9c:
    // 00495e9c  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00495e9e  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00495ea1  83e901                 +sub ecx, 1
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
    // 00495ea4  8d40ff                 -lea eax, [eax - 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00495ea7  7df3                   -jge 0x495e9c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495e9c;
    }
L_0x00495ea9:
    // 00495ea9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495eaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495eab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495eab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495eac  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00495eae  83e901                 +sub ecx, 1
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
    // 00495eb1  7c0d                   -jl 0x495ec0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495ec0;
    }
L_0x00495eb3:
    // 00495eb3  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00495eb5  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00495eb8  83e901                 +sub ecx, 1
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
    // 00495ebb  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00495ebe  7df3                   -jge 0x495eb3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00495eb3;
    }
L_0x00495ec0:
    // 00495ec0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495ec1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_495ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495ec4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495ec5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495ec6  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 00495ecc  7423                   -je 0x495ef1
    if (cpu.flags.zf)
    {
        goto L_0x00495ef1;
    }
    // 00495ece  83fb01                 +cmp ebx, 1
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
    // 00495ed1  7c1e                   -jl 0x495ef1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495ef1;
    }
    // 00495ed3  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00495ed6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495ed9  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00495edb  81e1c0ff0000           -and ecx, 0xffc0
    cpu.ecx &= x86::reg32(x86::sreg32(65472 /*0xffc0*/));
    // 00495ee1  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00495ee3  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00495ee6  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00495ee8  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00495eeb  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 00495eee  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x00495ef1:
    // 00495ef1  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495ef4  7821                   -js 0x495f17
    if (cpu.flags.sf)
    {
        goto L_0x00495f17;
    }
L_0x00495ef6:
    // 00495ef6  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495ef8  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495efb  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00495efd  81e1c0ffc0ff           -and ecx, 0xffc0ffc0
    cpu.ecx &= x86::reg32(x86::sreg32(4290838464 /*0xffc0ffc0*/));
    // 00495f03  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00495f05  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 00495f0b  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00495f0d  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495f10  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00495f12  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495f15  79df                   -jns 0x495ef6
    if (!cpu.flags.sf)
    {
        goto L_0x00495ef6;
    }
L_0x00495f17:
    // 00495f17  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495f1a  7820                   -js 0x495f3c
    if (cpu.flags.sf)
    {
        goto L_0x00495f3c;
    }
L_0x00495f1c:
    // 00495f1c  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00495f1f  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495f22  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00495f24  81e1c0ff0000           -and ecx, 0xffc0
    cpu.ecx &= x86::reg32(x86::sreg32(65472 /*0xffc0*/));
    // 00495f2a  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 00495f2c  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00495f2f  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00495f31  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495f34  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 00495f37  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00495f3a  79e0                   -jns 0x495f1c
    if (!cpu.flags.sf)
    {
        goto L_0x00495f1c;
    }
L_0x00495f3c:
    // 00495f3c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495f3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495f3f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495f3f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495f40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495f41  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 00495f47  7423                   -je 0x495f6c
    if (cpu.flags.zf)
    {
        goto L_0x00495f6c;
    }
    // 00495f49  83fb01                 +cmp ebx, 1
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
    // 00495f4c  7c1e                   -jl 0x495f6c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00495f6c;
    }
    // 00495f4e  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00495f51  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495f54  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00495f56  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 00495f5c  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495f5e  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00495f61  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00495f63  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00495f66  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 00495f69  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
L_0x00495f6c:
    // 00495f6c  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495f6f  7821                   -js 0x495f92
    if (cpu.flags.sf)
    {
        goto L_0x00495f92;
    }
L_0x00495f71:
    // 00495f71  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00495f73  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00495f76  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00495f78  81e1e07fe07f           -and ecx, 0x7fe07fe0
    cpu.ecx &= x86::reg32(x86::sreg32(2145419232 /*0x7fe07fe0*/));
    // 00495f7e  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495f80  81e61f001f00           -and esi, 0x1f001f
    cpu.esi &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 00495f86  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00495f88  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495f8b  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00495f8d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495f90  79df                   -jns 0x495f71
    if (!cpu.flags.sf)
    {
        goto L_0x00495f71;
    }
L_0x00495f92:
    // 00495f92  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495f95  7820                   -js 0x495fb7
    if (cpu.flags.sf)
    {
        goto L_0x00495fb7;
    }
L_0x00495f97:
    // 00495f97  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 00495f9a  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00495f9d  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00495f9f  81e1e07f0000           -and ecx, 0x7fe0
    cpu.ecx &= x86::reg32(x86::sreg32(32736 /*0x7fe0*/));
    // 00495fa5  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00495fa7  83e61f                 -and esi, 0x1f
    cpu.esi &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 00495faa  09f1                   -or ecx, esi
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi));
    // 00495fac  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495faf  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 00495fb2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00495fb5  79e0                   -jns 0x495f97
    if (!cpu.flags.sf)
    {
        goto L_0x00495f97;
    }
L_0x00495fb7:
    // 00495fb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495fb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495fb9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495fba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495fbb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495fbc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495fbd  8b3d1ca94c00           -mov edi, dword ptr [0x4ca91c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5024028) /* 0x4ca91c */);
    // 00495fc3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00495fc5:
    // 00495fc5  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00495fc7  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00495fca  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00495fcd  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00495fd0  8b348f                 -mov esi, dword ptr [edi + ecx*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ecx * 4);
    // 00495fd3  8972fc                 -mov dword ptr [edx - 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00495fd6  7fed                   -jg 0x495fc5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00495fc5;
    }
    // 00495fd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495fd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495fda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00495fdb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_495fdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00495fdc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00495fdd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00495fde  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00495fdf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00495fe0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00495fe2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00495fe4  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00495fe6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00495fe8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00495fea  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00495fec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00495fee  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00495ff1  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 00495ff7  754e                   -jne 0x496047
    if (!cpu.flags.zf)
    {
        goto L_0x00496047;
    }
    // 00495ff9  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00495ffc  7849                   -js 0x496047
    if (cpu.flags.sf)
    {
        goto L_0x00496047;
    }
    // 00495ffe  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00496001  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 00496003  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00496006  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
L_0x00496009:
    // 00496009  8b04459e7f5200         -mov eax, dword ptr [eax*2 + 0x527f9e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5406622) /* 0x527f9e */ + cpu.eax * 2);
    // 00496010  8d7604                 -lea esi, [esi + 4]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00496013  8b0c4d9e7f5200         -mov ecx, dword ptr [ecx*2 + 0x527f9e]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5406622) /* 0x527f9e */ + cpu.ecx * 2);
    // 0049601a  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0049601d  668b045da07f5200       -mov ax, word ptr [ebx*2 + 0x527fa0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.ebx * 2);
    // 00496025  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
    // 00496027  668b0c55a07f5200       -mov cx, word ptr [edx*2 + 0x527fa0]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.edx * 2);
    // 0049602f  8a5602                 -mov dl, byte ptr [esi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00496032  8947f8                 -mov dword ptr [edi - 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00496035  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00496038  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049603a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049603c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049603f  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496042  8a4e03                 -mov cl, byte ptr [esi + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00496045  79c2                   -jns 0x496009
    if (!cpu.flags.sf)
    {
        goto L_0x00496009;
    }
L_0x00496047:
    // 00496047  83c503                 +add ebp, 3
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049604a  7818                   -js 0x496064
    if (cpu.flags.sf)
    {
        goto L_0x00496064;
    }
L_0x0049604c:
    // 0049604c  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 0049604e  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00496051  668b0455a07f5200       -mov ax, word ptr [edx*2 + 0x527fa0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.edx * 2);
    // 00496059  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0049605c  8d7f02                 -lea edi, [edi + 2]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0049605f  83ed01                 +sub ebp, 1
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
    // 00496062  79e8                   -jns 0x49604c
    if (!cpu.flags.sf)
    {
        goto L_0x0049604c;
    }
L_0x00496064:
    // 00496064  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496065  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496066  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496067  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496068  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496069(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496069  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049606a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049606b  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049606e  83eb04                 +sub ebx, 4
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
    // 00496071  783f                   -js 0x4960b2
    if (cpu.flags.sf)
    {
        goto L_0x004960b2;
    }
L_0x00496073:
    // 00496073  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00496075  8b4e03                 -mov ecx, dword ptr [esi + 3]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 00496078  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049607a  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0049607c  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00496081  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00496087  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00496089  894a04                 -mov dword ptr [edx + 4], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049608c  8b4606                 -mov eax, dword ptr [esi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0049608f  8b4e09                 -mov ecx, dword ptr [esi + 9]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 00496092  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00496094  0fc9                   -bswap ecx
    {
        x86::reg32& tmp = cpu.ecx;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 00496096  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0049609b  81c9000000ff           -or ecx, 0xff000000
    cpu.ecx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004960a1  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004960a4  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004960a7  83eb04                 +sub ebx, 4
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
    // 004960aa  8d760c                 -lea esi, [esi + 0xc]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004960ad  8d5210                 -lea edx, [edx + 0x10]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004960b0  79c1                   -jns 0x496073
    if (!cpu.flags.sf)
    {
        goto L_0x00496073;
    }
L_0x004960b2:
    // 004960b2  83c303                 +add ebx, 3
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004960b5  7816                   -js 0x4960cd
    if (cpu.flags.sf)
    {
        goto L_0x004960cd;
    }
L_0x004960b7:
    // 004960b7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004960b9  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 004960bb  0d000000ff             -or eax, 0xff000000
    cpu.eax |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004960c0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004960c2  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004960c5  8d7603                 -lea esi, [esi + 3]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004960c8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004960cb  79ea                   -jns 0x4960b7
    if (!cpu.flags.sf)
    {
        goto L_0x004960b7;
    }
L_0x004960cd:
    // 004960cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004960ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004960cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4960d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004960d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004960d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004960d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004960d3  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004960d6  782f                   -js 0x496107
    if (cpu.flags.sf)
    {
        goto L_0x00496107;
    }
L_0x004960d8:
    // 004960d8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004960da  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004960dc  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 004960e2  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 004960e5  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004960e7  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 004960ed  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 004960ef  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 004960f5  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 004960f8  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004960fa  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004960fc  83eb02                 +sub ebx, 2
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004960ff  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00496102  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00496105  79d1                   -jns 0x4960d8
    if (!cpu.flags.sf)
    {
        goto L_0x004960d8;
    }
L_0x00496107:
    // 00496107  83c301                 +add ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049610a  7831                   -js 0x49613d
    if (cpu.flags.sf)
    {
        goto L_0x0049613d;
    }
L_0x0049610c:
    // 0049610c  668b08                 -mov cx, word ptr [eax]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax);
    // 0049610f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00496111  81e7007c007c           -and edi, 0x7c007c00
    cpu.edi &= x86::reg32(x86::sreg32(2080406528 /*0x7c007c00*/));
    // 00496117  c1ef0a                 -shr edi, 0xa
    cpu.edi >>= 10 /*0xa*/ % 32;
    // 0049611a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049611c  81e6e083e083           -and esi, 0x83e083e0
    cpu.esi &= x86::reg32(x86::sreg32(2212529120 /*0x83e083e0*/));
    // 00496122  09f7                   -or edi, esi
    cpu.edi |= x86::reg32(x86::sreg32(cpu.esi));
    // 00496124  81e11f001f00           -and ecx, 0x1f001f
    cpu.ecx &= x86::reg32(x86::sreg32(2031647 /*0x1f001f*/));
    // 0049612a  c1e10a                 -shl ecx, 0xa
    cpu.ecx <<= 10 /*0xa*/ % 32;
    // 0049612d  09cf                   -or edi, ecx
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049612f  66893a                 -mov word ptr [edx], di
    app->getMemory<x86::reg16>(cpu.edx) = cpu.di;
    // 00496132  83eb01                 +sub ebx, 1
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496135  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00496138  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0049613b  79cf                   -jns 0x49610c
    if (!cpu.flags.sf)
    {
        goto L_0x0049610c;
    }
L_0x0049613d:
    // 0049613d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049613e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049613f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496140  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496141(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496142  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496143  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496144  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496145  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00496147  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00496149  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049614b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049614d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049614f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496151  83ed04                 -sub ebp, 4
    (cpu.ebp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496154  f7c702000000           +test edi, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & 2 /*0x2*/));
    // 0049615a  754e                   -jne 0x4961aa
    if (!cpu.flags.zf)
    {
        goto L_0x004961aa;
    }
    // 0049615c  83fd00                 +cmp ebp, 0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049615f  7849                   -js 0x4961aa
    if (cpu.flags.sf)
    {
        goto L_0x004961aa;
    }
    // 00496161  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00496163  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
L_0x00496166:
    // 00496166  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496168  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0049616b  8b144d9e7f5200         -mov edx, dword ptr [ecx*2 + 0x527f9e]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5406622) /* 0x527f9e */ + cpu.ecx * 2);
    // 00496172  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00496175  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00496177  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 0049617a  8b0c4d9e7f5200         -mov ecx, dword ptr [ecx*2 + 0x527f9e]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5406622) /* 0x527f9e */ + cpu.ecx * 2);
    // 00496181  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00496184  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00496187  668b1445a07f5200       -mov dx, word ptr [eax*2 + 0x527fa0]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.eax * 2);
    // 0049618f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00496191  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00496194  668b0c5da07f5200       -mov cx, word ptr [ebx*2 + 0x527fa0]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.ebx * 2);
    // 0049619c  8a5e01                 -mov bl, byte ptr [esi + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049619f  8957f8                 -mov dword ptr [edi - 8], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004961a2  894ffc                 -mov dword ptr [edi - 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004961a5  83ed04                 +sub ebp, 4
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004961a8  79bc                   -jns 0x496166
    if (!cpu.flags.sf)
    {
        goto L_0x00496166;
    }
L_0x004961aa:
    // 004961aa  83c502                 +add ebp, 2
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004961ad  7827                   -js 0x4961d6
    if (cpu.flags.sf)
    {
        goto L_0x004961d6;
    }
L_0x004961af:
    // 004961af  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004961b1  c1e904                 -shr ecx, 4
    cpu.ecx >>= 4 /*0x4*/ % 32;
    // 004961b4  8b144d9e7f5200         -mov edx, dword ptr [ecx*2 + 0x527f9e]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5406622) /* 0x527f9e */ + cpu.ecx * 2);
    // 004961bb  8d7601                 -lea esi, [esi + 1]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004961be  8d7f04                 -lea edi, [edi + 4]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004961c1  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004961c4  668b1445a07f5200       -mov dx, word ptr [eax*2 + 0x527fa0]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.eax * 2);
    // 004961cc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004961ce  8957fc                 -mov dword ptr [edi - 4], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004961d1  83ed02                 +sub ebp, 2
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
    // 004961d4  79d9                   -jns 0x4961af
    if (!cpu.flags.sf)
    {
        goto L_0x004961af;
    }
L_0x004961d6:
    // 004961d6  83c501                 +add ebp, 1
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004961d9  780e                   -js 0x4961e9
    if (cpu.flags.sf)
    {
        goto L_0x004961e9;
    }
    // 004961db  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004961de  668b1445a07f5200       -mov dx, word ptr [eax*2 + 0x527fa0]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5406624) /* 0x527fa0 */ + cpu.eax * 2);
    // 004961e6  668917                 -mov word ptr [edi], dx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.dx;
L_0x004961e9:
    // 004961e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004961ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4961ee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004961ee  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004961ef  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004961f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004961f1  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004961f4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004961f6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004961f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004961f9  2eff15c4544b00         -call dword ptr cs:[0x4b54c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936900) /* 0x4b54c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496200  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496202  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 00496206  2d6c070000             -sub eax, 0x76c
    (cpu.eax) -= x86::reg32(x86::sreg32(1900 /*0x76c*/));
    // 0049620b  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0049620e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496210  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00496215  48                     -dec eax
    (cpu.eax)--;
    // 00496216  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00496219  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049621b  668b442406             -mov ax, word ptr [esp + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00496220  89430c                 -mov dword ptr [ebx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00496223  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496225  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049622a  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0049622d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049622f  668b44240a             -mov ax, word ptr [esp + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(10) /* 0xa */);
    // 00496234  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00496237  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496239  668b44240c             -mov ax, word ptr [esp + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049623e  c74320ffffffff         -mov dword ptr [ebx + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 00496245  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00496247  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496249  668b44240e             -mov ax, word ptr [esp + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 0049624e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00496251  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496252  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496253  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496254  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496255(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496255  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496256  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496257  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496258  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496259  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049625a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049625b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049625e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00496260  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 00496265  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00496268  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049626b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049626e  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00496270  b9a0fc4b00             -mov ecx, 0x4bfca0
    cpu.ecx = 4979872 /*0x4bfca0*/;
    // 00496275  8b7514                 -mov esi, dword ptr [ebp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00496278  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049627a  81fea17efbf4           +cmp esi, 0xf4fb7ea1
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4110122657 /*0xf4fb7ea1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496280  7d0a                   -jge 0x49628c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049628c;
    }
L_0x00496282:
    // 00496282  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00496287  e94e010000             -jmp 0x4963da
    goto L_0x004963da;
L_0x0049628c:
    // 0049628c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0049628f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496291  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00496294  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00496296  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00496298:
    // 00496298  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049629a  7d06                   -jge 0x4962a2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004962a2;
    }
    // 0049629c  4e                     -dec esi
    (cpu.esi)--;
    // 0049629d  83c70c                 +add edi, 0xc
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004962a0  ebf6                   -jmp 0x496298
    goto L_0x00496298;
L_0x004962a2:
    // 004962a2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004962a4  7cdc                   -jl 0x496282
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496282;
    }
    // 004962a6  8d866c070000           -lea eax, [esi + 0x76c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1900) /* 0x76c */);
    // 004962ac  e873f00000             -call 0x4a5324
    cpu.esp -= 4;
    sub_4a5324(app, cpu);
    if (cpu.terminate) return;
    // 004962b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004962b3  7405                   -je 0x4962ba
    if (cpu.flags.zf)
    {
        goto L_0x004962ba;
    }
    // 004962b5  b9bafc4b00             -mov ecx, 0x4bfcba
    cpu.ecx = 4979898 /*0x4bfcba*/;
L_0x004962ba:
    // 004962ba  8d5603                 -lea edx, [esi + 3]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004962bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004962bf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004962c2  c1e202                 +shl edx, 2
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
    // 004962c5  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004962c7  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004962ca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004962cc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004962ce  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004962d1  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004962d3  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004962d6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004962d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004962da  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004962dd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004962df  8d5663                 -lea edx, [esi + 0x63]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(99) /* 0x63 */);
    // 004962e2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004962e4  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004962e9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004962ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004962ee  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004962f1  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004962f3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004962f6  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004962f8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004962fb  8d962b010000           -lea edx, [esi + 0x12b]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(299) /* 0x12b */);
    // 00496301  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 00496306  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496308  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049630b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049630d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00496310  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496312  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496314  0fbf0441               -movsx eax, word ptr [ecx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 2)));
    // 00496318  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0049631a  03450c                 -add eax, dword ptr [ebp + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 0049631d  8d78ff                 -lea edi, [eax - 1]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00496320  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00496323  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496325  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00496328  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049632a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049632d  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00496330  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496332  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496334  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00496337  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496339  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0049633c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049633f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00496341:
    // 00496341  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496343  7d09                   -jge 0x49634e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049634e;
    }
    // 00496345  4f                     -dec edi
    (cpu.edi)--;
    // 00496346  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049634c  ebf3                   -jmp 0x496341
    goto L_0x00496341;
L_0x0049634e:
    // 0049634e  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00496350  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496352  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496354  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00496356  e802f40000             -call 0x4a575d
    cpu.esp -= 4;
    sub_4a575d(app, cpu);
    if (cpu.terminate) return;
    // 0049635b  e87cf60000             -call 0x4a59dc
    cpu.esp -= 4;
    sub_4a59dc(app, cpu);
    if (cpu.terminate) return;
    // 00496360  8b1d52d54c00           -mov ebx, dword ptr [0x4cd552]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035346) /* 0x4cd552 */);
    // 00496366  8b4d20                 -mov ecx, dword ptr [ebp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00496369  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0049636b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049636d  7d07                   -jge 0x496376
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496376;
    }
    // 0049636f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496371  e808f10000             -call 0x4a547e
    cpu.esp -= 4;
    sub_4a547e(app, cpu);
    if (cpu.terminate) return;
L_0x00496376:
    // 00496376  837d2000               +cmp dword ptr [ebp + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049637a  7e06                   -jle 0x496382
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496382;
    }
    // 0049637c  2b355ad54c00           -sub esi, dword ptr [0x4cd55a]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5035354) /* 0x4cd55a */)));
L_0x00496382:
    // 00496382  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00496384  7d09                   -jge 0x49638f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049638f;
    }
    // 00496386  4f                     -dec edi
    (cpu.edi)--;
    // 00496387  81c680510100           +add esi, 0x15180
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(86400 /*0x15180*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049638d  ebf3                   -jmp 0x496382
    goto L_0x00496382;
L_0x0049638f:
    // 0049638f  81ffde630000           +cmp edi, 0x63de
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25566 /*0x63de*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496395  0f8ce7feffff           -jl 0x496282
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496282;
    }
    // 0049639b  751d                   -jne 0x4963ba
    if (!cpu.flags.zf)
    {
        goto L_0x004963ba;
    }
    // 0049639d  8b1d52d54c00           -mov ebx, dword ptr [0x4cd552]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5035346) /* 0x4cd552 */);
    // 004963a3  81ee80510100           -sub esi, 0x15180
    (cpu.esi) -= x86::reg32(x86::sreg32(86400 /*0x15180*/));
    // 004963a9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004963ab  0f8ed1feffff           -jle 0x496282
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496282;
    }
    // 004963b1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004963b3  7d23                   -jge 0x4963d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004963d8;
    }
    // 004963b5  e9c8feffff             -jmp 0x496282
    goto L_0x00496282;
L_0x004963ba:
    // 004963ba  8d87219cffff           -lea eax, [edi - 0x63df]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-25567) /* -0x63df */);
    // 004963c0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004963c2  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 004963c5  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004963c7  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 004963ca  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004963cc  c1e707                 -shl edi, 7
    cpu.edi <<= 7 /*0x7*/ % 32;
    // 004963cf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004963d1  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004963d4  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004963d6  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
L_0x004963d8:
    // 004963d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004963da:
    // 004963da  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004963dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4963e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004963e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004963e5  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004963e6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004963e7  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004963e9  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004963ec  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004963ed  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963ee  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004963f0  3500002000             -xor eax, 0x200000
    cpu.eax ^= x86::reg32(x86::sreg32(2097152 /*0x200000*/));
    // 004963f5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004963f6  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963f7  9c                     -pushfd 
    cpu.esp -= 4;
    app->getMemory<x86::reg32>(cpu.esp) = cpu.flags.eflags;
    // 004963f8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963f9  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004963fb  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004963fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963fe  9d                     -popfd 
    cpu.flags.eflags = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004963ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496400  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496401(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496401  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496402  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496403  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496404  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496405  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496406  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496407  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496409  0fa2                   -cpuid 
    cpu.cpuid();
    // 0049640b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049640c  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049640e  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00496411  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00496414  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00496417  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496418  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496419  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049641a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049641b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049641c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49641d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049641d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049641e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049641f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496421  9e                     -sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00496422  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00496427  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0049642c  f6f3                   -div bl
    {
        x86::reg16 tmp = cpu.ax;
        x86::reg8 d = cpu.bl;
        cpu.ax /= d;
        cpu.ah = tmp % d;
    }
    // 0049642e  9f                     -lahf 
    cpu.ah = 0x02 | (cpu.flags.lo & 0xD7);
    // 0049642f  80fc02                 +cmp ah, 2
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
    // 00496432  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 00496437  7505                   -jne 0x49643e
    if (!cpu.flags.zf)
    {
        goto L_0x0049643e;
    }
    // 00496439  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0049643e:
    // 0049643e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049643f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496440  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_496442(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496442  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496443(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496443  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496444(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496444  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496445  ff0d06ae4c00           +dec dword ptr [0x4cae06]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5025286) /* 0x4cae06 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049644b  753f                   -jne 0x49648c
    if (!cpu.flags.zf)
    {
        goto L_0x0049648c;
    }
    // 0049644d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049644f  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 00496451  7421                   -je 0x496474
    if (cpu.flags.zf)
    {
        goto L_0x00496474;
    }
    // 00496453  83e27f                 +and edx, 0x7f
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(127 /*0x7f*/))));
    // 00496456  8a9200ad4c00           -mov dl, byte ptr [edx + 0x4cad00]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5025024) /* 0x4cad00 */);
L_0x0049645c:
    // 0049645c  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049645d  7c2d                   -jl 0x49648c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049648c;
    }
    // 0049645f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496460  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496461  ff14950aae4c00         -call dword ptr [edx*4 + 0x4cae0a]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025290) /* 0x4cae0a */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496468  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496469  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049646a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049646c  ff0506ae4c00           -inc dword ptr [0x4cae06]
    (app->getMemory<x86::reg32>(x86::reg32(5025286) /* 0x4cae06 */))++;
    // 00496472  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496473  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496474:
    // 00496474  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 00496477  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049647d  7c05                   -jl 0x496484
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496484;
    }
    // 0049647f  ba84000000             -mov edx, 0x84
    cpu.edx = 132 /*0x84*/;
L_0x00496484:
    // 00496484  8a9280ad4c00           -mov dl, byte ptr [edx + 0x4cad80]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5025152) /* 0x4cad80 */);
    // 0049648a  ebd0                   -jmp 0x49645c
    goto L_0x0049645c;
L_0x0049648c:
    // 0049648c  ff0506ae4c00           -inc dword ptr [0x4cae06]
    (app->getMemory<x86::reg32>(x86::reg32(5025286) /* 0x4cae06 */))++;
    // 00496492  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496493  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496494(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496494  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496495  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496496  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496497  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00496499  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049649b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049649d  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 004964a2  ba0aae4c00             -mov edx, 0x4cae0a
    cpu.edx = 5025290 /*0x4cae0a*/;
L_0x004964a7:
    // 004964a7  3902                   +cmp dword ptr [edx], eax
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004964a9  7412                   -je 0x4964bd
    if (cpu.flags.zf)
    {
        goto L_0x004964bd;
    }
    // 004964ab  66833a00               +cmp word ptr [edx], 0
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
    // 004964af  740a                   -je 0x4964bb
    if (cpu.flags.zf)
    {
        goto L_0x004964bb;
    }
    // 004964b1  83c204                 +add edx, 4
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
    // 004964b4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004964b5  75f0                   -jne 0x4964a7
    if (!cpu.flags.zf)
    {
        goto L_0x004964a7;
    }
    // 004964b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004964bb:
    // 004964bb  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004964bd:
    // 004964bd  b841000000             -mov eax, 0x41
    cpu.eax = 65 /*0x41*/;
    // 004964c2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004964c4:
    // 004964c4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004964c6  08d2                   +or dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(cpu.dl))));
    // 004964c8  740f                   -je 0x4964d9
    if (cpu.flags.zf)
    {
        goto L_0x004964d9;
    }
    // 004964ca  83fa7f                 +cmp edx, 0x7f
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
    // 004964cd  7f06                   -jg 0x4964d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004964d5;
    }
    // 004964cf  888200ad4c00           -mov byte ptr [edx + 0x4cad00], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5025024) /* 0x4cad00 */) = cpu.al;
L_0x004964d5:
    // 004964d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004964d9:
    // 004964d9  0fb6d6                 -movzx edx, dh
    cpu.edx = x86::reg32(cpu.dh);
    // 004964dc  81fa84000000           +cmp edx, 0x84
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004964e2  7ff1                   -jg 0x4964d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004964d5;
    }
    // 004964e4  888280ad4c00           -mov byte ptr [edx + 0x4cad80], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5025152) /* 0x4cad80 */) = cpu.al;
    // 004964ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004964ed  c3                     -ret 
    cpu.esp += 4;
    return;
    // 004964ee  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004964ef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004964f0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004964f1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004964f3  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004964f5  ebcd                   -jmp 0x4964c4
    goto L_0x004964c4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_496500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496500  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496501  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00496503  83f80f                 +cmp eax, 0xf
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
    // 00496506  7313                   -jae 0x49651b
    if (!cpu.flags.cf)
    {
        goto L_0x0049651b;
    }
    // 00496508  83f804                 +cmp eax, 4
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
    // 0049650b  7333                   -jae 0x496540
    if (!cpu.flags.cf)
    {
        goto L_0x00496540;
    }
    // 0049650d  83f801                 +cmp eax, 1
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
    // 00496510  7505                   -jne 0x496517
    if (!cpu.flags.zf)
    {
        goto L_0x00496517;
    }
    // 00496512  ba79000000             -mov edx, 0x79
    cpu.edx = 121 /*0x79*/;
L_0x00496517:
    // 00496517  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496519  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049651a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049651b:
    // 0049651b  763c                   -jbe 0x496559
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496559;
    }
    // 0049651d  83f818                 +cmp eax, 0x18
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
    // 00496520  730e                   -jae 0x496530
    if (!cpu.flags.cf)
    {
        goto L_0x00496530;
    }
    // 00496522  83f810                 +cmp eax, 0x10
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
    // 00496525  75f0                   -jne 0x496517
    if (!cpu.flags.zf)
    {
        goto L_0x00496517;
    }
    // 00496527  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 0049652c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049652e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049652f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496530:
    // 00496530  7630                   -jbe 0x496562
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496562;
    }
    // 00496532  83f820                 +cmp eax, 0x20
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
    // 00496535  75e0                   -jne 0x496517
    if (!cpu.flags.zf)
    {
        goto L_0x00496517;
    }
    // 00496537  ba7d000000             -mov edx, 0x7d
    cpu.edx = 125 /*0x7d*/;
    // 0049653c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049653e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049653f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496540:
    // 00496540  760e                   -jbe 0x496550
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00496550;
    }
    // 00496542  83f808                 +cmp eax, 8
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
    // 00496545  75d0                   -jne 0x496517
    if (!cpu.flags.zf)
    {
        goto L_0x00496517;
    }
    // 00496547  ba7b000000             -mov edx, 0x7b
    cpu.edx = 123 /*0x7b*/;
    // 0049654c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049654e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049654f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496550:
    // 00496550  ba7a000000             -mov edx, 0x7a
    cpu.edx = 122 /*0x7a*/;
    // 00496555  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496557  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496559:
    // 00496559  ba7e000000             -mov edx, 0x7e
    cpu.edx = 126 /*0x7e*/;
    // 0049655e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496560  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496561  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496562:
    // 00496562  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00496567  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496569  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049656a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49656b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049656b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049656c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049656d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049656e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049656f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00496571  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00496573  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00496578  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0049657a  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0049657c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049657d  e30b                   -jecxz 0x49658a
    if (cpu.ecx == 0)
    {
        goto L_0x0049658a;
    }
    // 0049657f  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00496581  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00496583  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00496585  7503                   -jne 0x49658a
    if (!cpu.flags.zf)
    {
        goto L_0x0049658a;
    }
    // 00496587  4f                     -dec edi
    (cpu.edi)--;
    // 00496588  66a989cf               +test ax, 0xcf89
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 53129 /*0xcf89*/));
    // FakeJmpInstruction
    goto L_0x0049658c;
L_0x0049658a:
    // 0049658a  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x0049658c:
    // 0049658c  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049658d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0049658f:
    // 0049658f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496591  740d                   -je 0x4965a0
    if (cpu.flags.zf)
    {
        goto L_0x004965a0;
    }
    // 00496593  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 00496595  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00496597  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00496599  7405                   -je 0x4965a0
    if (cpu.flags.zf)
    {
        goto L_0x004965a0;
    }
    // 0049659b  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049659c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049659d  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049659e  ebef                   -jmp 0x49658f
    goto L_0x0049658f;
L_0x004965a0:
    // 004965a0  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004965a3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004965a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4965b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004965b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004965b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004965b2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004965b4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004965b6  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004965bb  83f87b                 +cmp eax, 0x7b
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
    // 004965be  7509                   -jne 0x4965c9
    if (!cpu.flags.zf)
    {
        goto L_0x004965c9;
    }
    // 004965c0  8b4202                 -mov eax, dword ptr [edx + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004965c3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004965c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004965c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004965c9:
    // 004965c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004965cb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004965cd  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004965d0  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 004965d6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004965d8  83f80f                 +cmp eax, 0xf
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
    // 004965db  7505                   -jne 0x4965e2
    if (!cpu.flags.zf)
    {
        goto L_0x004965e2;
    }
    // 004965dd  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x004965e2:
    // 004965e2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004965e3  8b5a02                 -mov ebx, dword ptr [edx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004965e6  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004965e9  0fafcb                 -imul ecx, ebx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004965ec  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004965ee  25f0000000             -and eax, 0xf0
    cpu.eax &= x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004965f3  83f840                 +cmp eax, 0x40
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
    // 004965f6  750c                   -jne 0x496604
    if (!cpu.flags.zf)
    {
        goto L_0x00496604;
    }
    // 004965f8  8d410f                 -lea eax, [ecx + 0xf]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(15) /* 0xf */);
    // 004965fb  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004965fd  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 00496600  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496601  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496602  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496603  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496604:
    // 00496604  8d4107                 -lea eax, [ecx + 7]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00496607  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00496609  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0049660c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049660d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049660e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049660f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_496610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496610  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496612  7501                   -jne 0x496615
    if (!cpu.flags.zf)
    {
        goto L_0x00496615;
    }
    // 00496614  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496615:
    // 00496615  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496616  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00496617  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00496619  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0049661a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049661c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049661e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496620  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00496624  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00496627  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00496629  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0049662c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049662e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049662f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00496630  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_496634(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00496634  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496635  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00496636  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00496637  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00496638  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0049663e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00496640  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00496644  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 00496648  bae9c34800             -mov edx, 0x48c3e9
    cpu.edx = 4768745 /*0x48c3e9*/;
    // 0049664d  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00496650  8b1d10824c00           -mov ebx, dword ptr [0x4c8210]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5014032) /* 0x4c8210 */);
    // 00496656  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496659  89942490000000         -mov dword ptr [esp + 0x90], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 00496660  89842480000000         -mov dword ptr [esp + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 00496667  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00496669  7418                   -je 0x496683
    if (cpu.flags.zf)
    {
        goto L_0x00496683;
    }
    // 0049666b  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496672  0f845c010000           -je 0x4967d4
    if (cpu.flags.zf)
    {
        goto L_0x004967d4;
    }
    // 00496678  c7842490000000c4c64800 -mov dword ptr [esp + 0x90], 0x48c6c4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = 4769476 /*0x48c6c4*/;
L_0x00496683:
    // 00496683  ba6c8a5200             -mov edx, 0x528a6c
    cpu.edx = 5409388 /*0x528a6c*/;
    // 00496688  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049668b  e8805affff             -call 0x48c110
    cpu.esp -= 4;
    sub_48c110(app, cpu);
    if (cpu.terminate) return;
    // 00496690  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496692  89842484000000         -mov dword ptr [esp + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00496699  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049669b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049669d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004966a0  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 004966a6  83f820                 +cmp eax, 0x20
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
    // 004966a9  750b                   -jne 0x4966b6
    if (!cpu.flags.zf)
    {
        goto L_0x004966b6;
    }
    // 004966ab  c784248400000002000000 -mov dword ptr [esp + 0x84], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 2 /*0x2*/;
L_0x004966b6:
    // 004966b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004966b8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004966ba  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004966bd  8a8090a84c00           -mov al, byte ptr [eax + 0x4ca890]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023888) /* 0x4ca890 */);
    // 004966c3  40                     -inc eax
    (cpu.eax)++;
    // 004966c4  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004966c6  83f810                 +cmp eax, 0x10
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
    // 004966c9  750b                   -jne 0x4966d6
    if (!cpu.flags.zf)
    {
        goto L_0x004966d6;
    }
    // 004966cb  c784248400000001000000 -mov dword ptr [esp + 0x84], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = 1 /*0x1*/;
L_0x004966d6:
    // 004966d6  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004966da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004966dc  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004966e0  895c2440               -mov dword ptr [esp + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 004966e4  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004966e7  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004966ea  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 004966ee  39f8                   +cmp eax, edi
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
    // 004966f0  7e08                   -jle 0x4966fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004966fa;
    }
    // 004966f2  c744244001000000       -mov dword ptr [esp + 0x40], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
L_0x004966fa:
    // 004966fa  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004966fe  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00496702  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496705  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496707  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049670b  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049670e  3b480c                 +cmp ecx, dword ptr [eax + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496711  7e08                   -jle 0x49671b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049671b;
    }
    // 00496713  c744243c01000000       -mov dword ptr [esp + 0x3c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 1 /*0x1*/;
L_0x0049671b:
    // 0049671b  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0049671f  8b74244c               -mov esi, dword ptr [esp + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00496723  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496726  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00496728  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0049672b  3b5004                 +cmp edx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049672e  7e08                   -jle 0x496738
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496738;
    }
    // 00496730  c744244002000000       -mov dword ptr [esp + 0x40], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = 2 /*0x2*/;
L_0x00496738:
    // 00496738  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049673c  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00496740  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496743  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496745  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00496749  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049674c  3b4814                 +cmp ecx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049674f  7e08                   -jle 0x496759
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496759;
    }
    // 00496751  c744243c02000000       -mov dword ptr [esp + 0x3c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = 2 /*0x2*/;
L_0x00496759:
    // 00496759  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049675d  8b742440               -mov esi, dword ptr [esp + 0x40]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00496761  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00496766  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00496768  8b7c244c               -mov edi, dword ptr [esp + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049676c  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049676e  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00496772  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00496776  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0049677d  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 00496780  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00496782  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00496784  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00496787  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496789  89542448               -mov dword ptr [esp + 0x48], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 0049678d  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00496791  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00496793  8d14f500000000         -lea edx, [esi*8]
    cpu.edx = x86::reg32(cpu.esi * 8);
    // 0049679a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049679d  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049679f  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004967a1  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004967a5  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004967a7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004967a9  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004967ac  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004967b0  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004967b3  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004967b5  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004967b9  3d00000100             +cmp eax, 0x10000
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
    // 004967be  7d28                   -jge 0x4967e8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004967e8;
    }
    // 004967c0  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004967c7  751b                   -jne 0x4967e4
    if (!cpu.flags.zf)
    {
        goto L_0x004967e4;
    }
L_0x004967c9:
    // 004967c9  81c4a4000000           +add esp, 0xa4
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(164 /*0xa4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004967cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004967d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004967d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004967d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004967d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004967d4:
    // 004967d4  c78424900000009ec94800 -mov dword ptr [esp + 0x90], 0x48c99e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = 4770206 /*0x48c99e*/;
    // 004967df  e99ffeffff             -jmp 0x496683
    goto L_0x00496683;
L_0x004967e4:
    // 004967e4  0f77                   -emms 
    cpu.mmx.init();
    // 004967e6  ebe1                   -jmp 0x4967c9
    goto L_0x004967c9;
L_0x004967e8:
    // 004967e8  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004967ec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004967ee  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004967f2  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004967f4  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004967f6  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004967f8  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004967fa  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004967fc  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496800  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00496804  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00496806  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496808  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0049680c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0049680e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00496810  7c1e                   -jl 0x496830
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496830;
    }
L_0x00496812:
    // 00496812  81f900000100           +cmp ecx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496818  7d23                   -jge 0x49683d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049683d;
    }
L_0x0049681a:
    // 0049681a  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496821  74a6                   -je 0x4967c9
    if (cpu.flags.zf)
    {
        goto L_0x004967c9;
    }
    // 00496823  0f77                   -emms 
    cpu.mmx.init();
    // 00496825  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0049682b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049682c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049682d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049682e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049682f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00496830:
    // 00496830  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00496835  f7d9                   +neg ecx
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
    // 00496837  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049683b  ebd5                   -jmp 0x496812
    goto L_0x00496812;
L_0x0049683d:
    // 0049683d  81f900000006           +cmp ecx, 0x6000000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100663296 /*0x6000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496843  7dd5                   -jge 0x49681a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049681a;
    }
    // 00496845  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00496849  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049684d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496850  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496852  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 00496856  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049685a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049685c  8b7c2448               -mov edi, dword ptr [esp + 0x48]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496860  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00496864  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00496867  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00496869  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049686d  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496871  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 00496874  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496878  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0049687a  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049687c  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00496880  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496882  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496886  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00496888  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049688c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049688e  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00496890  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496894  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 00496897  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049689a  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049689c  2b542448               -sub edx, dword ptr [esp + 0x48]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */)));
    // 004968a0  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004968a4  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004968a8  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004968ab  2b4304                 -sub eax, dword ptr [ebx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004968ae  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004968b2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004968b4  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004968b6  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004968ba  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004968bd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004968bf  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004968c3  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004968c6  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004968ca  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004968cd  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004968cf  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004968d3  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004968d5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004968d7  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004968d9  e832fdffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 004968de  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004968e0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004968e4  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004968e7  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004968ea  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004968ec  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004968ee  e81dfdffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 004968f3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004968f5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004968f8  42                     -inc edx
    (cpu.edx)++;
    // 004968f9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004968fa  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00496901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00496902  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496906  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496907  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00496909  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 0049690e  b86c8a5200             -mov eax, 0x528a6c
    cpu.eax = 5409388 /*0x528a6c*/;
    // 00496913  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00496915  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00496919  e8f2070000             -call 0x497110
    cpu.esp -= 4;
    sub_497110(app, cpu);
    if (cpu.terminate) return;
    // 0049691e  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00496922  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00496926  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00496928  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0049692a  8b6d04                 -mov ebp, dword ptr [ebp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0049692d  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00496930  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00496932  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00496935  89bc249c000000         -mov dword ptr [esp + 0x9c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.edi;
    // 0049693c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049693e  0f8452010000           -je 0x496a96
    if (cpu.flags.zf)
    {
        goto L_0x00496a96;
    }
    // 00496944  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496948  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049694b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0049694d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00496951  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00496955  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496957  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00496959  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049695d  e8aefcffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496962  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 00496969  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049696c  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496970  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00496974  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496976  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x0049697a:
    // 0049697a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049697d  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 00496980  e88bfcffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496985  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0049698c  3b5c2414               +cmp ebx, dword ptr [esp + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496990  0f8d17030000           -jge 0x496cad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496cad;
    }
    // 00496996  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0049699a  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0049699e  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004969a1  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004969a5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004969a7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004969a9  0f8438010000           -je 0x496ae7
    if (cpu.flags.zf)
    {
        goto L_0x00496ae7;
    }
    // 004969af  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004969b3  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004969b6  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004969b8  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004969ba  2b442444               -sub eax, dword ptr [esp + 0x44]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
    // 004969be  e84dfcffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 004969c3  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004969c7  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 004969cb  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004969cf  e83cfcffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 004969d4  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x004969d8:
    // 004969d8  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004969dc  a1e8844c00             -mov eax, dword ptr [0x4c84e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 004969e1  39d0                   +cmp eax, edx
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
    // 004969e3  7d02                   -jge 0x4969e7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004969e7;
    }
    // 004969e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004969e7:
    // 004969e7  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 004969ed  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 004969f1  39cb                   +cmp ebx, ecx
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
    // 004969f3  0f8d1c010000           -jge 0x496b15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496b15;
    }
L_0x004969f9:
    // 004969f9  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00496a00  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
L_0x00496a04:
    // 00496a04  3b5c2450               +cmp ebx, dword ptr [esp + 0x50]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a08  0f8d9f020000           -jge 0x496cad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496cad;
    }
    // 00496a0e  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496a15  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496a17  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00496a1a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496a1d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496a1f  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00496a22  2b0de4844c00           -sub ecx, dword ptr [0x4c84e4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
    // 00496a28  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00496a2a  7e02                   -jle 0x496a2e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496a2e;
    }
    // 00496a2c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00496a2e:
    // 00496a2e  8b0ddc844c00           -mov ecx, dword ptr [0x4c84dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 00496a34  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496a36  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 00496a3d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00496a3f  0f8ef3010000           -jle 0x496c38
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496c38;
    }
    // 00496a45  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496a47  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00496a49:
    // 00496a49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496a4b  7e0c                   -jle 0x496a59
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496a59;
    }
    // 00496a4d  3b1de0844c00           +cmp ebx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496a53  0f8ded010000           -jge 0x496c46
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496c46;
    }
L_0x00496a59:
    // 00496a59  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00496a60  8b942488000000         -mov edx, dword ptr [esp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00496a67  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496a6e  43                     -inc ebx
    (cpu.ebx)++;
    // 00496a6f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496a71  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496a73  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00496a77  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00496a7b  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496a7e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496a80  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00496a84  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 00496a8b  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00496a8f  01c7                   +add edi, eax
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
    // 00496a91  e96effffff             -jmp 0x496a04
    goto L_0x00496a04;
L_0x00496a96:
    // 00496a96  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00496a99  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00496aa0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496aa4  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 00496aab  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00496aae  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00496ab0  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00496ab4  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496ab8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496aba  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00496abc  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496ac0  e84bfbffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496ac5  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00496ac9  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 00496ad0  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00496ad3  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00496ad6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00496ad8  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00496adc  29ca                   +sub edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496ade  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00496ae2  e993feffff             -jmp 0x49697a
    goto L_0x0049697a;
L_0x00496ae7:
    // 00496ae7  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496aeb  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00496aee  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496af0  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496af2  2b442444               +sub eax, dword ptr [esp + 0x44]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496af6  e815fbffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496afb  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496aff  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00496b03  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00496b07  e804fbffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496b0c  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00496b10  e9c3feffff             -jmp 0x4969d8
    goto L_0x004969d8;
L_0x00496b15:
    // 00496b15  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00496b19  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496b1d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496b20  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00496b22  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00496b24  3b0ddc844c00           +cmp ecx, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b2a  0f8cc9feffff           -jl 0x4969f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004969f9;
    }
    // 00496b30  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496b32  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 00496b38  0f8dbbfeffff           -jge 0x4969f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004969f9;
    }
    // 00496b3e  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496b42  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
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
    // 00496b48  0f8cabfeffff           -jl 0x4969f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004969f9;
    }
    // 00496b4e  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 00496b54  0f8d9ffeffff           -jge 0x4969f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004969f9;
    }
    // 00496b5a  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00496b5e  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
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
    // 00496b64  0f8c8ffeffff           -jl 0x4969f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004969f9;
    }
    // 00496b6a  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 00496b70  0f8d83feffff           -jge 0x4969f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004969f9;
    }
    // 00496b76  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00496b7d  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00496b80  8944247c               -mov dword ptr [esp + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 00496b84  8954245c               -mov dword ptr [esp + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.edx;
L_0x00496b88:
    // 00496b88  8b44247c               -mov eax, dword ptr [esp + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00496b8c  3b44245c               +cmp eax, dword ptr [esp + 0x5c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496b90  0f8d17010000           -jge 0x496cad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496cad;
    }
    // 00496b96  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496b9d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496b9f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00496ba2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496ba5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496ba7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496ba9  7e50                   -jle 0x496bfb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496bfb;
    }
    // 00496bab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496bac  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496bae  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00496bb5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496bb8  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00496bbb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496bbd  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496bc0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496bc2  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00496bc6  8a8c2488000000         -mov cl, byte ptr [esp + 0x88]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00496bcd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496bd1  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00496bd3  8b8c2480000000         -mov ecx, dword ptr [esp + 0x80]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00496bda  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496bdb  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00496be0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00496be3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496be5  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00496bea  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496bec  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00496bee  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00496bf0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496bf1  ff94249c000000         -call dword ptr [esp + 0x9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496bf8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00496bfb:
    // 00496bfb  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00496c02  8b942488000000         -mov edx, dword ptr [esp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00496c09  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496c10  43                     -inc ebx
    (cpu.ebx)++;
    // 00496c11  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496c13  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496c15  8b54247c               -mov edx, dword ptr [esp + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00496c19  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00496c1d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496c20  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496c22  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00496c26  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 00496c2d  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 00496c31  01c7                   +add edi, eax
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
    // 00496c33  e950ffffff             -jmp 0x496b88
    goto L_0x00496b88;
L_0x00496c38:
    // 00496c38  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00496c3a  898c2494000000         -mov dword ptr [esp + 0x94], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.ecx;
    // 00496c41  e903feffff             -jmp 0x496a49
    goto L_0x00496a49;
L_0x00496c46:
    // 00496c46  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496c47  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496c49  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00496c50  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496c53  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00496c56  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496c58  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496c5b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496c5d  8b842498000000         -mov eax, dword ptr [esp + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 00496c64  030c856c8a5200         -add ecx, dword ptr [eax*4 + 0x528a6c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5409388) /* 0x528a6c */ + cpu.eax * 4)));
    // 00496c6b  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00496c6e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00496c72  8a8c2488000000         -mov cl, byte ptr [esp + 0x88]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00496c79  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496c7d  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00496c81  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00496c83  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00496c87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496c88  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00496c8d  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00496c93  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00496c95  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00496c99  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00496c9b  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00496c9d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496c9e  ff94249c000000         -call dword ptr [esp + 0x9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496ca5  83c40c                 +add esp, 0xc
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
    // 00496ca8  e9acfdffff             -jmp 0x496a59
    goto L_0x00496a59;
L_0x00496cad:
    // 00496cad  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00496cb1  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00496cb5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496cb8  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496cba  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00496cbe  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00496cc1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496cc4  39c3                   +cmp ebx, eax
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
    // 00496cc6  0f8d4a030000           -jge 0x497016
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497016;
    }
    // 00496ccc  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 00496cd1  0f8471010000           -je 0x496e48
    if (cpu.flags.zf)
    {
        goto L_0x00496e48;
    }
    // 00496cd7  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496cdb  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496cdf  8b6904                 -mov ebp, dword ptr [ecx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00496ce2  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00496ce4  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00496ce6  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00496ce8  e823f9ffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496ced  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496cf1  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00496cf5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00496cf9  e812f9ffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496cfe  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00496d02  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496d06  8984249c000000         -mov dword ptr [esp + 0x9c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.eax;
    // 00496d0d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00496d11  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496d15  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496d18  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496d1a  8b442448               -mov eax, dword ptr [esp + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496d1e  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00496d22  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00496d24  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00496d27  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 00496d2a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00496d2e  898424a0000000         -mov dword ptr [esp + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00496d35  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496d39  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496d3b  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00496d3f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496d43  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00496d45  2b02                   -sub eax, dword ptr [edx]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00496d47  8b9424a0000000         -mov edx, dword ptr [esp + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 00496d4e  e8bdf8ffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496d53  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496d57  8984248c000000         -mov dword ptr [esp + 0x8c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.eax;
    // 00496d5e  2b5104                 -sub edx, dword ptr [ecx + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 00496d61  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00496d65  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00496d69  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00496d6c  2b4104                 -sub eax, dword ptr [ecx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 00496d6f  e89cf8ffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496d74  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
L_0x00496d7b:
    // 00496d7b  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00496d7f  8b4c244c               -mov ecx, dword ptr [esp + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00496d83  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00496d86  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00496d88  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00496d8b  a1e8844c00             -mov eax, dword ptr [0x4c84e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014760) /* 0x4c84e8 */);
    // 00496d90  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00496d93  39c2                   +cmp edx, eax
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
    // 00496d95  7e02                   -jle 0x496d99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496d99;
    }
    // 00496d97  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00496d99:
    // 00496d99  8b0de0844c00           -mov ecx, dword ptr [0x4c84e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */);
    // 00496d9f  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00496da3  39cb                   +cmp ebx, ecx
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
    // 00496da5  0f8dcf000000           -jge 0x496e7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496e7a;
    }
L_0x00496dab:
    // 00496dab  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00496db2  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
L_0x00496db6:
    // 00496db6  3b5c2454               +cmp ebx, dword ptr [esp + 0x54]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496dba  0f8d56020000           -jge 0x497016
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497016;
    }
    // 00496dc0  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496dc7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00496dc9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00496dcc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496dcf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496dd1  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00496dd4  2b0de4844c00           -sub ecx, dword ptr [0x4c84e4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014756) /* 0x4c84e4 */)));
    // 00496dda  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00496ddc  7e02                   -jle 0x496de0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496de0;
    }
    // 00496dde  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00496de0:
    // 00496de0  8b0ddc844c00           -mov ecx, dword ptr [0x4c84dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */);
    // 00496de6  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00496de8  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00496def  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00496df1  0f8eab010000           -jle 0x496fa2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496fa2;
    }
    // 00496df7  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00496df9  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00496dfb:
    // 00496dfb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00496dfd  7e0c                   -jle 0x496e0b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496e0b;
    }
    // 00496dff  3b1de0844c00           +cmp ebx, dword ptr [0x4c84e0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014752) /* 0x4c84e0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496e05  0f8da5010000           -jge 0x496fb0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496fb0;
    }
L_0x00496e0b:
    // 00496e0b  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00496e12  8b942488000000         -mov edx, dword ptr [esp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00496e19  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496e20  43                     -inc ebx
    (cpu.ebx)++;
    // 00496e21  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496e23  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496e25  8b542470               -mov edx, dword ptr [esp + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 00496e29  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00496e2d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496e30  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496e32  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00496e36  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 00496e3d  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 00496e41  01c7                   +add edi, eax
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
    // 00496e43  e96effffff             -jmp 0x496db6
    goto L_0x00496db6;
L_0x00496e48:
    // 00496e48  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00496e4c  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00496e4f  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496e53  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00496e55  2b01                   +sub eax, dword ptr [ecx]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00496e57  e8b4f7ffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496e5c  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00496e60  8944246c               -mov dword ptr [esp + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 00496e64  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00496e68  8b7c2444               -mov edi, dword ptr [esp + 0x44]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496e6c  e89ff7ffff             -call 0x496610
    cpu.esp -= 4;
    sub_496610(app, cpu);
    if (cpu.terminate) return;
    // 00496e71  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00496e75  e901ffffff             -jmp 0x496d7b
    goto L_0x00496d7b;
L_0x00496e7a:
    // 00496e7a  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00496e7e  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00496e82  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00496e85  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00496e87  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00496e89  3b0ddc844c00           +cmp ecx, dword ptr [0x4c84dc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5014748) /* 0x4c84dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496e8f  0f8c16ffffff           -jl 0x496dab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dab;
    }
    // 00496e95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00496e97  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 00496e9d  0f8d08ffffff           -jge 0x496dab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496dab;
    }
    // 00496ea3  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00496ea7  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
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
    // 00496ead  0f8cf8feffff           -jl 0x496dab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dab;
    }
    // 00496eb3  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 00496eb9  0f8decfeffff           -jge 0x496dab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496dab;
    }
    // 00496ebf  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00496ec3  3b05dc844c00           +cmp eax, dword ptr [0x4c84dc]
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
    // 00496ec9  0f8cdcfeffff           -jl 0x496dab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00496dab;
    }
    // 00496ecf  3b05e4844c00           +cmp eax, dword ptr [0x4c84e4]
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
    // 00496ed5  0f8dd0feffff           -jge 0x496dab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00496dab;
    }
    // 00496edb  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00496ee2  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00496ee5  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00496ee9  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
L_0x00496eed:
    // 00496eed  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00496ef1  3b442458               +cmp eax, dword ptr [esp + 0x58]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00496ef5  0f8d1b010000           -jge 0x497016
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497016;
    }
    // 00496efb  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496f02  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00496f04  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496f07  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00496f0a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00496f0c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00496f0e  7e55                   -jle 0x496f65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00496f65;
    }
    // 00496f10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496f11  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00496f13  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00496f1a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00496f1d  0fafca                 -imul ecx, edx
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00496f20  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00496f22  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00496f25  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496f27  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 00496f2e  8a8c2488000000         -mov cl, byte ptr [esp + 0x88]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00496f35  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00496f3c  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00496f3e  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00496f42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00496f43  8b15fc844c00           -mov edx, dword ptr [0x4c84fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00496f49  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00496f4c  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496f4e  8b1500854c00           -mov edx, dword ptr [0x4c8500]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00496f54  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496f56  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00496f58  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00496f5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496f5b  ff94249c000000         -call dword ptr [esp + 0x9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00496f62  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00496f65:
    // 00496f65  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00496f6c  8b942488000000         -mov edx, dword ptr [esp + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00496f73  8b8c249c000000         -mov ecx, dword ptr [esp + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496f7a  43                     -inc ebx
    (cpu.ebx)++;
    // 00496f7b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496f7d  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 00496f7f  8b542478               -mov edx, dword ptr [esp + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00496f83  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00496f87  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00496f8a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496f8c  8b44246c               -mov eax, dword ptr [esp + 0x6c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00496f90  898c249c000000         -mov dword ptr [esp + 0x9c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.ecx;
    // 00496f97  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 00496f9b  01c7                   +add edi, eax
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
    // 00496f9d  e94bffffff             -jmp 0x496eed
    goto L_0x00496eed;
L_0x00496fa2:
    // 00496fa2  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00496fa4  898c2498000000         -mov dword ptr [esp + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00496fab  e94bfeffff             -jmp 0x496dfb
    goto L_0x00496dfb;
L_0x00496fb0:
    // 00496fb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496fb1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00496fb3  8b8c2484000000         -mov ecx, dword ptr [esp + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00496fba  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00496fbd  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00496fc0  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00496fc2  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00496fc5  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496fc7  8b84249c000000         -mov eax, dword ptr [esp + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00496fce  030c856c8a5200         -add ecx, dword ptr [eax*4 + 0x528a6c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5409388) /* 0x528a6c */ + cpu.eax * 4)));
    // 00496fd5  898c24a4000000         -mov dword ptr [esp + 0xa4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.ecx;
    // 00496fdc  8a8c2488000000         -mov cl, byte ptr [esp + 0x88]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00496fe3  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00496fea  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00496fec  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00496ff0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00496ff1  a1fc844c00             -mov eax, dword ptr [0x4c84fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014780) /* 0x4c84fc */);
    // 00496ff6  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00496ff9  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00496ffb  a100854c00             -mov eax, dword ptr [0x4c8500]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014784) /* 0x4c8500 */);
    // 00497000  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497002  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00497004  0302                   -add eax, dword ptr [edx]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 00497006  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497007  ff94249c000000         -call dword ptr [esp + 0x9c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049700e  83c40c                 +add esp, 0xc
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
    // 00497011  e9f5fdffff             -jmp 0x496e0b
    goto L_0x00496e0b;
L_0x00497016:
    // 00497016  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049701d  0f84a6f7ffff           -je 0x4967c9
    if (cpu.flags.zf)
    {
        goto L_0x004967c9;
    }
    // 00497023  0f77                   -emms 
    cpu.mmx.init();
    // 00497025  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0049702b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049702c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049702d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049702e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049702f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497031  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00497034  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00497036  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00497039  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049703f  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00497042  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00497045  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00497048  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049704e  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00497052  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00497055  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00497058  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049705e  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00497062  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00497065  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00497068  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049706e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00497072  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00497075  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00497078  81c100800000           -add ecx, 0x8000
    (cpu.ecx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049707e  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00497082  8b5214                 -mov edx, dword ptr [edx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00497085  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00497088  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049708e  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00497092  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00497094  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00497097  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0049709d  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004970a1  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004970a4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004970a7  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004970ad  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004970b1  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004970b4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004970b7  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004970bd  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004970c1  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004970c4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004970c7  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004970cd  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004970d1  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004970d4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004970d7  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004970dd  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004970e1  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004970e4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004970e7  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004970ed  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004970f1  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 004970f5  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004970f7  e838f5ffff             -call 0x496634
    cpu.esp -= 4;
    sub_496634(app, cpu);
    if (cpu.terminate) return;
    // 004970fc  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004970ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497100  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_497110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497110  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497111  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497112  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497113  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497116  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049711a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049711c  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0049711e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00497122  47                     -inc edi
    (cpu.edi)++;
    // 00497123  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00497125  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00497127  7e5b                   -jle 0x497184
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497184;
    }
    // 00497129  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049712c  85c8                   +test eax, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.ecx));
    // 0049712e  745d                   -je 0x49718d
    if (cpu.flags.zf)
    {
        goto L_0x0049718d;
    }
L_0x00497130:
    // 00497130  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00497132  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00497135  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00497138  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0049713c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0049713e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00497141  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00497144  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497148  030c24                 -add ecx, dword ptr [esp]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0049714b  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0049714d  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00497151  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00497153  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00497155  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00497158  0fafc8                 -imul ecx, eax
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0049715b  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049715d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00497160  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00497162  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00497165  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00497169  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0049716c  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049716f  034c2404               -add ecx, dword ptr [esp + 4]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 00497173  894efc                 -mov dword ptr [esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00497176  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049717a  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0049717c  01cb                   +add ebx, ecx
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
    // 0049717e  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049717f  75af                   -jne 0x497130
    if (!cpu.flags.zf)
    {
        goto L_0x00497130;
    }
    // 00497181  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00497184:
    // 00497184  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497187  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497188  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497189  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049718a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0049718d:
    // 0049718d  e88eeb0000             -call 0x4a5d20
    cpu.esp -= 4;
    sub_4a5d20(app, cpu);
    if (cpu.terminate) return;
    // 00497192  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00497196:
    // 00497196  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497198  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0049719b  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049719f  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004971a1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004971a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004971a6  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004971a9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004971ac  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004971ae  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004971b2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004971b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004971b6  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004971b8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004971bb  8a4c2408               -mov cl, byte ptr [esp + 8]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004971bf  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004971c1  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004971c3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004971c6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004971c8  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004971cb  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004971ce  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004971d1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004971d3  894efc                 -mov dword ptr [esi - 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004971d6  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004971da  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004971dc  01cb                   +add ebx, ecx
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
    // 004971de  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004971df  75b5                   -jne 0x497196
    if (!cpu.flags.zf)
    {
        goto L_0x00497196;
    }
    // 004971e1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004971e4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004971e5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004971e6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004971e7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4971f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004971f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4971f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004971f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004971f5  a114824c00             -mov eax, dword ptr [0x4c8214]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
    // 004971fa  a3dcb24c00             -mov dword ptr [0x4cb2dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5026524) /* 0x4cb2dc */) = cpu.eax;
    // 004971ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497201  7502                   -jne 0x497205
    if (!cpu.flags.zf)
    {
        goto L_0x00497205;
    }
    // 00497203  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497204  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497205:
    // 00497205  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497206  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497207  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497208  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497209  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049720a  b90c714a00             -mov ecx, 0x4a710c
    cpu.ecx = 4878604 /*0x4a710c*/;
    // 0049720f  bb0c724a00             -mov ebx, 0x4a720c
    cpu.ebx = 4878860 /*0x4a720c*/;
    // 00497214  bedc724a00             -mov esi, 0x4a72dc
    cpu.esi = 4879068 /*0x4a72dc*/;
    // 00497219  bfd0734a00             -mov edi, 0x4a73d0
    cpu.edi = 4879312 /*0x4a73d0*/;
    // 0049721e  bdb0744a00             -mov ebp, 0x4a74b0
    cpu.ebp = 4879536 /*0x4a74b0*/;
    // 00497223  b8e4744a00             -mov eax, 0x4a74e4
    cpu.eax = 4879588 /*0x4a74e4*/;
    // 00497228  ba94754a00             -mov edx, 0x4a7594
    cpu.edx = 4879764 /*0x4a7594*/;
    // 0049722d  890d84b24c00           -mov dword ptr [0x4cb284], ecx
    app->getMemory<x86::reg32>(x86::reg32(5026436) /* 0x4cb284 */) = cpu.ecx;
    // 00497233  891d88b24c00           -mov dword ptr [0x4cb288], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026440) /* 0x4cb288 */) = cpu.ebx;
    // 00497239  89358cb24c00           -mov dword ptr [0x4cb28c], esi
    app->getMemory<x86::reg32>(x86::reg32(5026444) /* 0x4cb28c */) = cpu.esi;
    // 0049723f  893d90b24c00           -mov dword ptr [0x4cb290], edi
    app->getMemory<x86::reg32>(x86::reg32(5026448) /* 0x4cb290 */) = cpu.edi;
    // 00497245  892db4b24c00           -mov dword ptr [0x4cb2b4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5026484) /* 0x4cb2b4 */) = cpu.ebp;
    // 0049724b  a3b8b24c00             -mov dword ptr [0x4cb2b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5026488) /* 0x4cb2b8 */) = cpu.eax;
    // 00497250  8915bcb24c00           -mov dword ptr [0x4cb2bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5026492) /* 0x4cb2bc */) = cpu.edx;
    // 00497256  b9c4754a00             -mov ecx, 0x4a75c4
    cpu.ecx = 4879812 /*0x4a75c4*/;
    // 0049725b  bb44764a00             -mov ebx, 0x4a7644
    cpu.ebx = 4879940 /*0x4a7644*/;
    // 00497260  bea8794a00             -mov esi, 0x4a79a8
    cpu.esi = 4880808 /*0x4a79a8*/;
    // 00497265  bf9c7d4a00             -mov edi, 0x4a7d9c
    cpu.edi = 4881820 /*0x4a7d9c*/;
    // 0049726a  bd10814a00             -mov ebp, 0x4a8110
    cpu.ebp = 4882704 /*0x4a8110*/;
    // 0049726f  b854854a00             -mov eax, 0x4a8554
    cpu.eax = 4883796 /*0x4a8554*/;
    // 00497274  890dc0b24c00           -mov dword ptr [0x4cb2c0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5026496) /* 0x4cb2c0 */) = cpu.ecx;
    // 0049727a  891dc4b24c00           -mov dword ptr [0x4cb2c4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026500) /* 0x4cb2c4 */) = cpu.ebx;
    // 00497280  8935a4b24c00           -mov dword ptr [0x4cb2a4], esi
    app->getMemory<x86::reg32>(x86::reg32(5026468) /* 0x4cb2a4 */) = cpu.esi;
    // 00497286  893da8b24c00           -mov dword ptr [0x4cb2a8], edi
    app->getMemory<x86::reg32>(x86::reg32(5026472) /* 0x4cb2a8 */) = cpu.edi;
    // 0049728c  892dacb24c00           -mov dword ptr [0x4cb2ac], ebp
    app->getMemory<x86::reg32>(x86::reg32(5026476) /* 0x4cb2ac */) = cpu.ebp;
    // 00497292  a3b0b24c00             -mov dword ptr [0x4cb2b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5026480) /* 0x4cb2b0 */) = cpu.eax;
    // 00497297  893594b24c00           -mov dword ptr [0x4cb294], esi
    app->getMemory<x86::reg32>(x86::reg32(5026452) /* 0x4cb294 */) = cpu.esi;
    // 0049729d  893d98b24c00           -mov dword ptr [0x4cb298], edi
    app->getMemory<x86::reg32>(x86::reg32(5026456) /* 0x4cb298 */) = cpu.edi;
    // 004972a3  892d9cb24c00           -mov dword ptr [0x4cb29c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5026460) /* 0x4cb29c */) = cpu.ebp;
    // 004972a9  a3a0b24c00             -mov dword ptr [0x4cb2a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5026464) /* 0x4cb2a0 */) = cpu.eax;
    // 004972ae  bf94854a00             -mov edi, 0x4a8594
    cpu.edi = 4883860 /*0x4a8594*/;
    // 004972b3  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004972b5  893dc8b24c00           -mov dword ptr [0x4cb2c8], edi
    app->getMemory<x86::reg32>(x86::reg32(5026504) /* 0x4cb2c8 */) = cpu.edi;
    // 004972bb  892dd8b24c00           -mov dword ptr [0x4cb2d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5026520) /* 0x4cb2d8 */) = cpu.ebp;
    // 004972c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972c5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004972c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4972c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004972c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004972c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004972ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004972cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004972cc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004972cd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004972d0  8b1dccb24c00           -mov ebx, dword ptr [0x4cb2cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 004972d6  8b35d4b24c00           -mov esi, dword ptr [0x4cb2d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */);
    // 004972dc  8b3dd0b24c00           -mov edi, dword ptr [0x4cb2d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */);
    // 004972e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004972e4  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004972e6  e8b5120100             -call 0x4a85a0
    cpu.esp -= 4;
    sub_4a85a0(app, cpu);
    if (cpu.terminate) return;
    // 004972eb  e860130100             -call 0x4a8650
    cpu.esp -= 4;
    sub_4a8650(app, cpu);
    if (cpu.terminate) return;
    // 004972f0  e89b140100             -call 0x4a8790
    cpu.esp -= 4;
    sub_4a8790(app, cpu);
    if (cpu.terminate) return;
    // 004972f5  e846150100             -call 0x4a8840
    cpu.esp -= 4;
    sub_4a8840(app, cpu);
    if (cpu.terminate) return;
    // 004972fa  8b3dd0b24c00           -mov edi, dword ptr [0x4cb2d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */);
    // 00497300  8b35d4b24c00           -mov esi, dword ptr [0x4cb2d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */);
L_0x00497306:
    // 00497306  8b1dccb24c00           -mov ebx, dword ptr [0x4cb2cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 0049730c  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 00497313  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00497315  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497317  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049731a  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049731d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049731f  7518                   -jne 0x497339
    if (!cpu.flags.zf)
    {
        goto L_0x00497339;
    }
L_0x00497321:
    // 00497321  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 00497328  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049732a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049732c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049732f  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00497332  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497334  740c                   -je 0x497342
    if (cpu.flags.zf)
    {
        goto L_0x00497342;
    }
    // 00497336  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00497337  ebe8                   -jmp 0x497321
    goto L_0x00497321;
L_0x00497339:
    // 00497339  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049733a  891dccb24c00           -mov dword ptr [0x4cb2cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */) = cpu.ebx;
    // 00497340  ebc4                   -jmp 0x497306
    goto L_0x00497306;
L_0x00497342:
    // 00497342  c7042408000000         -mov dword ptr [esp], 8
    app->getMemory<x86::reg32>(cpu.esp) = 8 /*0x8*/;
    // 00497349  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049734b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049734d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00497350  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00497353  891dccb24c00           -mov dword ptr [0x4cb2cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */) = cpu.ebx;
    // 00497359  8935d4b24c00           -mov dword ptr [0x4cb2d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */) = cpu.esi;
    // 0049735f  893dd0b24c00           -mov dword ptr [0x4cb2d0], edi
    app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */) = cpu.edi;
    // 00497365  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497367  7403                   -je 0x49736c
    if (cpu.flags.zf)
    {
        goto L_0x0049736c;
    }
    // 00497369  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049736a  ebd6                   -jmp 0x497342
    goto L_0x00497342;
L_0x0049736c:
    // 0049736c  e883feffff             -call 0x4971f4
    cpu.esp -= 4;
    sub_4971f4(app, cpu);
    if (cpu.terminate) return;
    // 00497371  892d70d25300           -mov dword ptr [0x53d270], ebp
    app->getMemory<x86::reg32>(x86::reg32(5493360) /* 0x53d270 */) = cpu.ebp;
    // 00497377  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0049737a  0f84a5000000           -je 0x497425
    if (cpu.flags.zf)
    {
        goto L_0x00497425;
    }
    // 00497380  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 00497385  8b3dd0b24c00           -mov edi, dword ptr [0x4cb2d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */);
    // 0049738b  8b35d4b24c00           -mov esi, dword ptr [0x4cb2d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */);
    // 00497391  a1c0b24c00             -mov eax, dword ptr [0x4cb2c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026496) /* 0x4cb2c0 */);
    // 00497396  8b1dccb24c00           -mov ebx, dword ptr [0x4cb2cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
L_0x0049739c:
    // 0049739c  a374d25300             -mov dword ptr [0x53d274], eax
    app->getMemory<x86::reg32>(x86::reg32(5493364) /* 0x53d274 */) = cpu.eax;
    // 004973a1  891578d25300           -mov dword ptr [0x53d278], edx
    app->getMemory<x86::reg32>(x86::reg32(5493368) /* 0x53d278 */) = cpu.edx;
L_0x004973a7:
    // 004973a7  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 004973aa  0f84ec000000           -je 0x49749c
    if (cpu.flags.zf)
    {
        goto L_0x0049749c;
    }
    // 004973b0  c7057cd2530044ac0000   -mov dword ptr [0x53d27c], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5493372) /* 0x53d27c */) = 44100 /*0xac44*/;
L_0x004973ba:
    // 004973ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004973bc  8935d4b24c00           -mov dword ptr [0x4cb2d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */) = cpu.esi;
    // 004973c2  893dd0b24c00           -mov dword ptr [0x4cb2d0], edi
    app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */) = cpu.edi;
L_0x004973c8:
    // 004973c8  05e40d0000             -add eax, 0xde4
    (cpu.eax) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 004973cd  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004973cf  889048e65200           -mov byte ptr [eax + 0x52e648], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5432904) /* 0x52e648 */) = cpu.dl;
    // 004973d5  3d40de0000             +cmp eax, 0xde40
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56896 /*0xde40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004973da  75ec                   -jne 0x4973c8
    if (!cpu.flags.zf)
    {
        goto L_0x004973c8;
    }
    // 004973dc  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004973e1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004973e2  891dccb24c00           -mov dword ptr [0x4cb2cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */) = cpu.ebx;
    // 004973e8  ff15c4b24c00           -call dword ptr [0x4cb2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026500) /* 0x4cb2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004973ee  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004973f1  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004973f6  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 004973fb  68e0b64c00             -push 0x4cb6e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5027552 /*0x4cb6e0*/;
    cpu.esp -= 4;
    // 00497400  a36cd25300             -mov dword ptr [0x53d26c], eax
    app->getMemory<x86::reg32>(x86::reg32(5493356) /* 0x53d26c */) = cpu.eax;
    // 00497405  ff15c4b24c00           -call dword ptr [0x4cb2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026500) /* 0x4cb2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049740b  8b1dccb24c00           -mov ebx, dword ptr [0x4cb2cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 00497411  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497414  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497416  891dccb24c00           -mov dword ptr [0x4cb2cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */) = cpu.ebx;
    // 0049741c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049741f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497420  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497421  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497422  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497423  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497424  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497425:
    // 00497425  8b3dd0b24c00           -mov edi, dword ptr [0x4cb2d0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */);
    // 0049742b  8b35d4b24c00           -mov esi, dword ptr [0x4cb2d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */);
    // 00497431  8b1dccb24c00           -mov ebx, dword ptr [0x4cb2cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 00497437  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 0049743a  7419                   -je 0x497455
    if (cpu.flags.zf)
    {
        goto L_0x00497455;
    }
    // 0049743c  a1b8b24c00             -mov eax, dword ptr [0x4cb2b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026488) /* 0x4cb2b8 */);
    // 00497441  a374d25300             -mov dword ptr [0x53d274], eax
    app->getMemory<x86::reg32>(x86::reg32(5493364) /* 0x53d274 */) = cpu.eax;
    // 00497446  c70578d2530000020000   -mov dword ptr [0x53d278], 0x200
    app->getMemory<x86::reg32>(x86::reg32(5493368) /* 0x53d278 */) = 512 /*0x200*/;
    // 00497450  e952ffffff             -jmp 0x4973a7
    goto L_0x004973a7;
L_0x00497455:
    // 00497455  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00497458  741a                   -je 0x497474
    if (cpu.flags.zf)
    {
        goto L_0x00497474;
    }
    // 0049745a  a1bcb24c00             -mov eax, dword ptr [0x4cb2bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026492) /* 0x4cb2bc */);
    // 0049745f  bd00020000             -mov ebp, 0x200
    cpu.ebp = 512 /*0x200*/;
    // 00497464  a374d25300             -mov dword ptr [0x53d274], eax
    app->getMemory<x86::reg32>(x86::reg32(5493364) /* 0x53d274 */) = cpu.eax;
    // 00497469  892d78d25300           -mov dword ptr [0x53d278], ebp
    app->getMemory<x86::reg32>(x86::reg32(5493368) /* 0x53d278 */) = cpu.ebp;
    // 0049746f  e933ffffff             -jmp 0x4973a7
    goto L_0x004973a7;
L_0x00497474:
    // 00497474  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00497477  740f                   -je 0x497488
    if (cpu.flags.zf)
    {
        goto L_0x00497488;
    }
    // 00497479  a1b4b24c00             -mov eax, dword ptr [0x4cb2b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026484) /* 0x4cb2b4 */);
    // 0049747e  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00497483  e914ffffff             -jmp 0x49739c
    goto L_0x0049739c;
L_0x00497488:
    // 00497488  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049748d  891dccb24c00           -mov dword ptr [0x4cb2cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */) = cpu.ebx;
    // 00497493  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497496  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497497  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497498  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497499  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049749a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049749b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049749c:
    // 0049749c  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0049749f  740f                   -je 0x4974b0
    if (cpu.flags.zf)
    {
        goto L_0x004974b0;
    }
    // 004974a1  c7057cd25300007d0000   -mov dword ptr [0x53d27c], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5493372) /* 0x53d27c */) = 32000 /*0x7d00*/;
    // 004974ab  e90affffff             -jmp 0x4973ba
    goto L_0x004973ba;
L_0x004974b0:
    // 004974b0  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 004974b3  740f                   -je 0x4974c4
    if (cpu.flags.zf)
    {
        goto L_0x004974c4;
    }
    // 004974b5  c7057cd2530022560000   -mov dword ptr [0x53d27c], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5493372) /* 0x53d27c */) = 22050 /*0x5622*/;
    // 004974bf  e9f6feffff             -jmp 0x4973ba
    goto L_0x004973ba;
L_0x004974c4:
    // 004974c4  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004974c7  740f                   -je 0x4974d8
    if (cpu.flags.zf)
    {
        goto L_0x004974d8;
    }
    // 004974c9  c7057cd25300803e0000   -mov dword ptr [0x53d27c], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5493372) /* 0x53d27c */) = 16000 /*0x3e80*/;
    // 004974d3  e9e2feffff             -jmp 0x4973ba
    goto L_0x004973ba;
L_0x004974d8:
    // 004974d8  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 004974db  740f                   -je 0x4974ec
    if (cpu.flags.zf)
    {
        goto L_0x004974ec;
    }
    // 004974dd  c7057cd25300112b0000   -mov dword ptr [0x53d27c], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5493372) /* 0x53d27c */) = 11025 /*0x2b11*/;
    // 004974e7  e9cefeffff             -jmp 0x4973ba
    goto L_0x004973ba;
L_0x004974ec:
    // 004974ec  f6c501                 +test ch, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 1 /*0x1*/));
    // 004974ef  740f                   -je 0x497500
    if (cpu.flags.zf)
    {
        goto L_0x00497500;
    }
    // 004974f1  c7057cd25300401f0000   -mov dword ptr [0x53d27c], 0x1f40
    app->getMemory<x86::reg32>(x86::reg32(5493372) /* 0x53d27c */) = 8000 /*0x1f40*/;
    // 004974fb  e9bafeffff             -jmp 0x4973ba
    goto L_0x004973ba;
L_0x00497500:
    // 00497500  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00497505  8935d4b24c00           -mov dword ptr [0x4cb2d4], esi
    app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */) = cpu.esi;
    // 0049750b  893dd0b24c00           -mov dword ptr [0x4cb2d0], edi
    app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */) = cpu.edi;
    // 00497511  891dccb24c00           -mov dword ptr [0x4cb2cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */) = cpu.ebx;
    // 00497517  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049751a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049751b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049751c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049751d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049751e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049751f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497520  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497521  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497522  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497523  8b157cd25300           -mov edx, dword ptr [0x53d27c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5493372) /* 0x53d27c */);
    // 00497529  8b0d74d25300           -mov ecx, dword ptr [0x53d274]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5493364) /* 0x53d274 */);
    // 0049752f  8b1d78d25300           -mov ebx, dword ptr [0x53d278]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5493368) /* 0x53d278 */);
    // 00497535  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 00497537  7435                   -je 0x49756e
    if (cpu.flags.zf)
    {
        goto L_0x0049756e;
    }
    // 00497539  bb00040000             -mov ebx, 0x400
    cpu.ebx = 1024 /*0x400*/;
    // 0049753e  8b0dc0b24c00           -mov ecx, dword ptr [0x4cb2c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026496) /* 0x4cb2c0 */);
L_0x00497544:
    // 00497544  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 00497547  745f                   -je 0x4975a8
    if (cpu.flags.zf)
    {
        goto L_0x004975a8;
    }
    // 00497549  ba44ac0000             -mov edx, 0xac44
    cpu.edx = 44100 /*0xac44*/;
L_0x0049754e:
    // 0049754e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00497550:
    // 00497550  40                     -inc eax
    (cpu.eax)++;
    // 00497551  83f810                 +cmp eax, 0x10
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
    // 00497554  7cfa                   -jl 0x497550
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497550;
    }
    // 00497556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00497558:
    // 00497558  891d78d25300           -mov dword ptr [0x53d278], ebx
    app->getMemory<x86::reg32>(x86::reg32(5493368) /* 0x53d278 */) = cpu.ebx;
    // 0049755e  890d74d25300           -mov dword ptr [0x53d274], ecx
    app->getMemory<x86::reg32>(x86::reg32(5493364) /* 0x53d274 */) = cpu.ecx;
    // 00497564  89157cd25300           -mov dword ptr [0x53d27c], edx
    app->getMemory<x86::reg32>(x86::reg32(5493372) /* 0x53d27c */) = cpu.edx;
    // 0049756a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049756b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049756c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049756d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049756e:
    // 0049756e  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00497570  740d                   -je 0x49757f
    if (cpu.flags.zf)
    {
        goto L_0x0049757f;
    }
    // 00497572  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00497577  8b0db8b24c00           -mov ecx, dword ptr [0x4cb2b8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026488) /* 0x4cb2b8 */);
    // 0049757d  ebc5                   -jmp 0x497544
    goto L_0x00497544;
L_0x0049757f:
    // 0049757f  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00497581  740d                   -je 0x497590
    if (cpu.flags.zf)
    {
        goto L_0x00497590;
    }
    // 00497583  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 00497588  8b0dbcb24c00           -mov ecx, dword ptr [0x4cb2bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026492) /* 0x4cb2bc */);
    // 0049758e  ebb4                   -jmp 0x497544
    goto L_0x00497544;
L_0x00497590:
    // 00497590  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00497592  740d                   -je 0x4975a1
    if (cpu.flags.zf)
    {
        goto L_0x004975a1;
    }
    // 00497594  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00497599  8b0db4b24c00           -mov ecx, dword ptr [0x4cb2b4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026484) /* 0x4cb2b4 */);
    // 0049759f  eba3                   -jmp 0x497544
    goto L_0x00497544;
L_0x004975a1:
    // 004975a1  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004975a6  ebb0                   -jmp 0x497558
    goto L_0x00497558;
L_0x004975a8:
    // 004975a8  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004975ab  7407                   -je 0x4975b4
    if (cpu.flags.zf)
    {
        goto L_0x004975b4;
    }
    // 004975ad  ba007d0000             -mov edx, 0x7d00
    cpu.edx = 32000 /*0x7d00*/;
    // 004975b2  eb9a                   -jmp 0x49754e
    goto L_0x0049754e;
L_0x004975b4:
    // 004975b4  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 004975b7  7407                   -je 0x4975c0
    if (cpu.flags.zf)
    {
        goto L_0x004975c0;
    }
    // 004975b9  ba22560000             -mov edx, 0x5622
    cpu.edx = 22050 /*0x5622*/;
    // 004975be  eb8e                   -jmp 0x49754e
    goto L_0x0049754e;
L_0x004975c0:
    // 004975c0  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004975c3  7407                   -je 0x4975cc
    if (cpu.flags.zf)
    {
        goto L_0x004975cc;
    }
    // 004975c5  ba803e0000             -mov edx, 0x3e80
    cpu.edx = 16000 /*0x3e80*/;
    // 004975ca  eb82                   -jmp 0x49754e
    goto L_0x0049754e;
L_0x004975cc:
    // 004975cc  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004975cf  740a                   -je 0x4975db
    if (cpu.flags.zf)
    {
        goto L_0x004975db;
    }
    // 004975d1  ba112b0000             -mov edx, 0x2b11
    cpu.edx = 11025 /*0x2b11*/;
    // 004975d6  e973ffffff             -jmp 0x49754e
    goto L_0x0049754e;
L_0x004975db:
    // 004975db  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004975de  74c1                   -je 0x4975a1
    if (cpu.flags.zf)
    {
        goto L_0x004975a1;
    }
    // 004975e0  ba401f0000             -mov edx, 0x1f40
    cpu.edx = 8000 /*0x1f40*/;
    // 004975e5  e964ffffff             -jmp 0x49754e
    goto L_0x0049754e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4975ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004975ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004975ed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004975ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004975ef  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004975f2  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004975f6  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004975f9  8d34c500000000         -lea esi, [eax*8]
    cpu.esi = x86::reg32(cpu.eax * 8);
    // 00497600  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00497602  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497604  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 00497607  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00497609  81c62cf45200           -add esi, 0x52f42c
    (cpu.esi) += x86::reg32(x86::sreg32(5436460 /*0x52f42c*/));
    // 0049760f  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00497612  8d460c                 -lea eax, [esi + 0xc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00497615  c64609ff               -mov byte ptr [esi + 9], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 255 /*0xff*/;
    // 00497619  8986600d0000           -mov dword ptr [esi + 0xd60], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */) = cpu.eax;
    // 0049761f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00497622  7559                   -jne 0x49767d
    if (!cpu.flags.zf)
    {
        goto L_0x0049767d;
    }
    // 00497624  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00497627  0f847a000000           -je 0x4976a7
    if (cpu.flags.zf)
    {
        goto L_0x004976a7;
    }
    // 0049762d  a190b24c00             -mov eax, dword ptr [0x4cb290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026448) /* 0x4cb290 */);
    // 00497632  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00497635  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0049763a  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049763d  7f60                   -jg 0x49769f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049769f;
    }
    // 0049763f  8b3da0b24c00           -mov edi, dword ptr [0x4cb2a0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026464) /* 0x4cb2a0 */);
L_0x00497645:
    // 00497645  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00497647  0f85bc000000           -jne 0x497709
    if (!cpu.flags.zf)
    {
        goto L_0x00497709;
    }
L_0x0049764d:
    // 0049764d  83f901                 +cmp ecx, 1
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
    // 00497650  0f8520010000           -jne 0x497776
    if (!cpu.flags.zf)
    {
        goto L_0x00497776;
    }
    // 00497656  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 0049765b  7e02                   -jle 0x49765f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049765f;
    }
L_0x0049765d:
    // 0049765d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0049765f:
    // 0049765f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00497662  83b80cb24c0000         +cmp dword ptr [eax + 0x4cb20c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5026316) /* 0x4cb20c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497669  0f851e010000           -jne 0x49778d
    if (!cpu.flags.zf)
    {
        goto L_0x0049778d;
    }
L_0x0049766f:
    // 0049766f  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 00497674  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497677  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497678  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497679  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049767a  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0049767d:
    // 0049767d  a18cb24c00             -mov eax, dword ptr [0x4cb28c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026444) /* 0x4cb28c */);
    // 00497682  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00497685  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0049768a  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049768d  7f08                   -jg 0x497697
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00497697;
    }
    // 0049768f  8b3d9cb24c00           -mov edi, dword ptr [0x4cb29c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026460) /* 0x4cb29c */);
    // 00497695  ebae                   -jmp 0x497645
    goto L_0x00497645;
L_0x00497697:
    // 00497697  8b3dacb24c00           -mov edi, dword ptr [0x4cb2ac]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026476) /* 0x4cb2ac */);
    // 0049769d  eba6                   -jmp 0x497645
    goto L_0x00497645;
L_0x0049769f:
    // 0049769f  8b3db0b24c00           -mov edi, dword ptr [0x4cb2b0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026480) /* 0x4cb2b0 */);
    // 004976a5  eb9e                   -jmp 0x497645
    goto L_0x00497645;
L_0x004976a7:
    // 004976a7  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004976aa  7422                   -je 0x4976ce
    if (cpu.flags.zf)
    {
        goto L_0x004976ce;
    }
    // 004976ac  a184b24c00             -mov eax, dword ptr [0x4cb284]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026436) /* 0x4cb284 */);
    // 004976b1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004976b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004976b6  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004976b9  7f08                   -jg 0x4976c3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004976c3;
    }
    // 004976bb  8b3d94b24c00           -mov edi, dword ptr [0x4cb294]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026452) /* 0x4cb294 */);
    // 004976c1  eb82                   -jmp 0x497645
    goto L_0x00497645;
L_0x004976c3:
    // 004976c3  8b3da4b24c00           -mov edi, dword ptr [0x4cb2a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026468) /* 0x4cb2a4 */);
    // 004976c9  e977ffffff             -jmp 0x497645
    goto L_0x00497645;
L_0x004976ce:
    // 004976ce  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 004976d1  7428                   -je 0x4976fb
    if (cpu.flags.zf)
    {
        goto L_0x004976fb;
    }
    // 004976d3  a188b24c00             -mov eax, dword ptr [0x4cb288]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026440) /* 0x4cb288 */);
    // 004976d8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004976db  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004976e0  83ff19                 +cmp edi, 0x19
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004976e3  7f0b                   -jg 0x4976f0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004976f0;
    }
    // 004976e5  8b3d98b24c00           -mov edi, dword ptr [0x4cb298]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026456) /* 0x4cb298 */);
    // 004976eb  e955ffffff             -jmp 0x497645
    goto L_0x00497645;
L_0x004976f0:
    // 004976f0  8b3da8b24c00           -mov edi, dword ptr [0x4cb2a8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026472) /* 0x4cb2a8 */);
    // 004976f6  e94affffff             -jmp 0x497645
    goto L_0x00497645;
L_0x004976fb:
    // 004976fb  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 00497700  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497703  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497704  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497705  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497706  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x00497709:
    // 00497709  83fb07                 +cmp ebx, 7
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049770c  752c                   -jne 0x49773a
    if (!cpu.flags.zf)
    {
        goto L_0x0049773a;
    }
    // 0049770e  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00497711  740a                   -je 0x49771d
    if (cpu.flags.zf)
    {
        goto L_0x0049771d;
    }
    // 00497713  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00497718  e930ffffff             -jmp 0x49764d
    goto L_0x0049764d;
L_0x0049771d:
    // 0049771d  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00497720  740a                   -je 0x49772c
    if (cpu.flags.zf)
    {
        goto L_0x0049772c;
    }
    // 00497722  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00497727  e921ffffff             -jmp 0x49764d
    goto L_0x0049764d;
L_0x0049772c:
    // 0049772c  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00497731  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497734  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497735  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497736  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497737  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0049773a:
    // 0049773a  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049773d  750f                   -jne 0x49774e
    if (!cpu.flags.zf)
    {
        goto L_0x0049774e;
    }
L_0x0049773f:
    // 0049773f  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 00497742  74e8                   -je 0x49772c
    if (cpu.flags.zf)
    {
        goto L_0x0049772c;
    }
    // 00497744  b81b000000             -mov eax, 0x1b
    cpu.eax = 27 /*0x1b*/;
    // 00497749  e9fffeffff             -jmp 0x49764d
    goto L_0x0049764d;
L_0x0049774e:
    // 0049774e  83fb08                 +cmp ebx, 8
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
    // 00497751  74ec                   -je 0x49773f
    if (cpu.flags.zf)
    {
        goto L_0x0049773f;
    }
    // 00497753  83fb02                 +cmp ebx, 2
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
    // 00497756  75a3                   -jne 0x4976fb
    if (!cpu.flags.zf)
    {
        goto L_0x004976fb;
    }
    // 00497758  f6c204                 +test dl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 4 /*0x4*/));
    // 0049775b  740a                   -je 0x497767
    if (cpu.flags.zf)
    {
        goto L_0x00497767;
    }
    // 0049775d  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00497762  e9e6feffff             -jmp 0x49764d
    goto L_0x0049764d;
L_0x00497767:
    // 00497767  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 0049776a  74c0                   -je 0x49772c
    if (cpu.flags.zf)
    {
        goto L_0x0049772c;
    }
    // 0049776c  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 00497771  e9d7feffff             -jmp 0x49764d
    goto L_0x0049764d;
L_0x00497776:
    // 00497776  83f902                 +cmp ecx, 2
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
    // 00497779  0f84defeffff           -je 0x49765d
    if (cpu.flags.zf)
    {
        goto L_0x0049765d;
    }
    // 0049777f  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 00497784  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497787  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497788  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497789  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049778a  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
L_0x0049778d:
    // 0049778d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049778f  8d86ac0d0000           -lea eax, [esi + 0xdac]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3500) /* 0xdac */);
    // 00497795  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497796  8d86a80d0000           -lea eax, [esi + 0xda8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    // 0049779c  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004977a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004977a1  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004977a5  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004977a9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004977aa  8b86600d0000           -mov eax, dword ptr [esi + 0xd60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 004977b0  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004977b4  ff950cb24c00           -call dword ptr [ebp + 0x4cb20c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5026316) /* 0x4cb20c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004977ba  833c2400               +cmp dword ptr [esp], 0
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
    // 004977be  0f84abfeffff           -je 0x49766f
    if (cpu.flags.zf)
    {
        goto L_0x0049766f;
    }
    // 004977c4  8d86bc0d0000           -lea eax, [esi + 0xdbc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    // 004977ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004977cb  8d86c00d0000           -lea eax, [esi + 0xdc0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    // 004977d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004977d2  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 004977d8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004977d9  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004977dd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004977e0  8d86dc0d0000           -lea eax, [esi + 0xddc]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3548) /* 0xddc */);
    // 004977e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004977e7  8d86e00d0000           -lea eax, [esi + 0xde0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    // 004977ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004977ee  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 004977f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004977f5  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004977f9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004977fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004977fe  0f846bfeffff           -je 0x49766f
    if (cpu.flags.zf)
    {
        goto L_0x0049766f;
    }
    // 00497804  8d86b80d0000           -lea eax, [esi + 0xdb8]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    // 0049780a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049780b  8d86b40d0000           -lea eax, [esi + 0xdb4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    // 00497811  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497812  8d86b00d0000           -lea eax, [esi + 0xdb0]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    // 00497818  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497819  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 0049781f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497820  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497822  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00497825  817c242c00000800       +cmp dword ptr [esp + 0x2c], 0x80000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049782d  7608                   -jbe 0x497837
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497837;
    }
    // 0049782f  c744242c00000800       -mov dword ptr [esp + 0x2c], 0x80000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = 524288 /*0x80000*/;
L_0x00497837:
    // 00497837  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049783b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049783c  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 00497842  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497843  ff96b00d0000           -call dword ptr [esi + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497849  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049784c  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00497850  884601                 -mov byte ptr [esi + 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00497853  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00497857  884602                 -mov byte ptr [esi + 2], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0049785a  8a442424               -mov al, byte ptr [esp + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049785e  884604                 -mov byte ptr [esi + 4], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 00497861  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00497865  884605                 -mov byte ptr [esi + 5], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 00497868  8a442434               -mov al, byte ptr [esp + 0x34]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0049786c  884603                 -mov byte ptr [esi + 3], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0049786f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497871  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00497875  e826020000             -call 0x497aa0
    cpu.esp -= 4;
    sub_497aa0(app, cpu);
    if (cpu.terminate) return;
    // 0049787a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049787b  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049787f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497880  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 00497886  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497887  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049788d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497890  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 00497893  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497895  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497898  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497899  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049789a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049789b  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4978a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004978a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004978a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004978a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004978a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004978a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004978a5  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004978a8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004978aa  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004978ac  05c40d0000             -add eax, 0xdc4
    (cpu.eax) += x86::reg32(x86::sreg32(3524 /*0xdc4*/));
    // 004978b1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004978b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004978b6  05900d0000             -add eax, 0xd90
    (cpu.eax) += x86::reg32(x86::sreg32(3472 /*0xd90*/));
    // 004978bb  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004978bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004978c1  05640d0000             -add eax, 0xd64
    (cpu.eax) += x86::reg32(x86::sreg32(3428 /*0xd64*/));
    // 004978c6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004978c8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004978cc:
    // 004978cc  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004978cf  3a4604                 +cmp al, byte ptr [esi + 4]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004978d2  0f84cd000000           -je 0x4979a5
    if (cpu.flags.zf)
    {
        goto L_0x004979a5;
    }
L_0x004978d8:
    // 004978d8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004978da  0f84d1000000           -je 0x4979b1
    if (cpu.flags.zf)
    {
        goto L_0x004979b1;
    }
    // 004978e0  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004978e3  8a7604                 -mov dh, byte ptr [esi + 4]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004978e6  4d                     -dec ebp
    (cpu.ebp)--;
    // 004978e7  38f0                   +cmp al, dh
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004978e9  0f85cd000000           -jne 0x4979bc
    if (!cpu.flags.zf)
    {
        goto L_0x004979bc;
    }
L_0x004978ef:
    // 004978ef  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004978f2  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004978f5  7406                   -je 0x4978fd
    if (cpu.flags.zf)
    {
        goto L_0x004978fd;
    }
    // 004978f7  8a4607                 -mov al, byte ptr [esi + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 004978fa  004602                 -add byte ptr [esi + 2], al
    (app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)) += x86::reg8(x86::sreg8(cpu.al));
L_0x004978fd:
    // 004978fd  0fbe4602               -movsx eax, byte ptr [esi + 2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */)));
    // 00497901  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497902  0fbe4601               -movsx eax, byte ptr [esi + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */)));
    // 00497906  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497907  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049790b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049790c  ff96bc0d0000           -call dword ptr [esi + 0xdbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3516) /* 0xdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497912  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497915  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00497917  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049791b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049791c  ff96b40d0000           -call dword ptr [esi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497922  8b0dd0b24c00           -mov ecx, dword ptr [0x4cb2d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */);
    // 00497928  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0049792b  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049792e  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00497932  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497936  8b8e600d0000           -mov ecx, dword ptr [esi + 0xd60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 0049793c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049793e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497940  ff96a80d0000           -call dword ptr [esi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497946  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497948  7c67                   -jl 0x4979b1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004979b1;
    }
    // 0049794a  a1d4b24c00             -mov eax, dword ptr [0x4cb2d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */);
    // 0049794f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00497953  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00497957  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0049795b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049795c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049795d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049795f  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00497963  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497964  ff96b80d0000           -call dword ptr [esi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049796a  8a0dd8b24c00           -mov cl, byte ptr [0x4cb2d8]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5026520) /* 0x4cb2d8 */);
    // 00497970  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00497972  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00497974  8b0dccb24c00           -mov ecx, dword ptr [0x4cb2cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 0049797a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0049797d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00497980  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00497982  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497983  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497987  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497988  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049798a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0049798e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049798f  ff96c00d0000           -call dword ptr [esi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497995  8a6e08                 -mov ch, byte ptr [esi + 8]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00497998  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0049799b  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 0049799d  7528                   -jne 0x4979c7
    if (!cpu.flags.zf)
    {
        goto L_0x004979c7;
    }
    // 0049799f  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004979a0  e927ffffff             -jmp 0x4978cc
    goto L_0x004978cc;
L_0x004979a5:
    // 004979a5  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004979a8  3a4605                 +cmp al, byte ptr [esi + 5]
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004979ab  0f8527ffffff           -jne 0x4978d8
    if (!cpu.flags.zf)
    {
        goto L_0x004978d8;
    }
L_0x004979b1:
    // 004979b1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004979b3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004979b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004979bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004979bc:
    // 004979bc  8a4606                 -mov al, byte ptr [esi + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004979bf  004601                 +add byte ptr [esi + 1], al
    {
        auto tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.al));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004979c2  e928ffffff             -jmp 0x4978ef
    goto L_0x004978ef;
L_0x004979c7:
    // 004979c7  8a0dd8b24c00           -mov cl, byte ptr [0x4cb2d8]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5026520) /* 0x4cb2d8 */);
    // 004979cd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004979cf  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004979d1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004979d4  05e0b64c00             -add eax, 0x4cb6e0
    (cpu.eax) += x86::reg32(x86::sreg32(5027552 /*0x4cb6e0*/));
    // 004979d9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004979da  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004979de  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004979df  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004979e1  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004979e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004979e6  ff96e00d0000           -call dword ptr [esi + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004979ec  83c410                 +add esp, 0x10
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
    // 004979ef  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004979f0  e9d7feffff             -jmp 0x4978cc
    goto L_0x004978cc;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4979f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004979f8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004979f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004979fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004979fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004979fd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00497a00  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497a02  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00497a05  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497a07  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497a09  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00497a0c  bf2cf45200             -mov edi, 0x52f42c
    cpu.edi = 5436460 /*0x52f42c*/;
    // 00497a11  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497a13  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497a15  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00497a18  7509                   -jne 0x497a23
    if (!cpu.flags.zf)
    {
        goto L_0x00497a23;
    }
    // 00497a1a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00497a1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a21  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497a23:
    // 00497a23  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497a24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497a25  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497a27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00497a29  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497a2b  e8c0000000             -call 0x497af0
    cpu.esp -= 4;
    sub_497af0(app, cpu);
    if (cpu.terminate) return;
    // 00497a30  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00497a35  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00497a37  e864feffff             -call 0x4978a0
    cpu.esp -= 4;
    sub_4978a0(app, cpu);
    if (cpu.terminate) return;
    // 00497a3c  ff15c8b24c00           -call dword ptr [0x4cb2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026504) /* 0x4cb2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497a42  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497a44  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 00497a47  ff1570d25300           -call dword ptr [0x53d270]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5493360) /* 0x53d270 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497a4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497a4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497a58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497a58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497a59  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00497a5b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00497a5e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497a60  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00497a63  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497a65  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497a67  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00497a6a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497a6c  052cf45200             -add eax, 0x52f42c
    (cpu.eax) += x86::reg32(x86::sreg32(5436460 /*0x52f42c*/));
    // 00497a71  803800                 +cmp byte ptr [eax], 0
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
    // 00497a74  7422                   -je 0x497a98
    if (cpu.flags.zf)
    {
        goto L_0x00497a98;
    }
    // 00497a76  81f900000800           +cmp ecx, 0x80000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497a7c  7605                   -jbe 0x497a83
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497a83;
    }
    // 00497a7e  b900000800             -mov ecx, 0x80000
    cpu.ecx = 524288 /*0x80000*/;
L_0x00497a83:
    // 00497a83  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497a84  8d90640d0000           -lea edx, [eax + 0xd64]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3428) /* 0xd64 */);
    // 00497a8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497a8b  ff90b00d0000           -call dword ptr [eax + 0xdb0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3504) /* 0xdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497a91  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497a94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497a96  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497a98:
    // 00497a98  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00497a9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497a9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_497aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497aa0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497aa1  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00497aa4  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00497aa6  7505                   -jne 0x497aad
    if (!cpu.flags.zf)
    {
        goto L_0x00497aad;
    }
    // 00497aa8  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00497aab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497aac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497aad:
    // 00497aad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497aae  8b5001                 -mov edx, dword ptr [eax + 1]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00497ab1  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00497ab4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00497ab7  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00497aba  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00497abc  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00497abe  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00497ac1  8b4805                 -mov ecx, dword ptr [eax + 5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00497ac4  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00497ac6  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00497ac9  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00497acc  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00497acf  c1fa07                 -sar edx, 7
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (7 /*0x7*/ % 32));
    // 00497ad2  885008                 -mov byte ptr [eax + 8], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.dl;
    // 00497ad5  8b5005                 -mov edx, dword ptr [eax + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00497ad8  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00497adb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497adc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497add  8d90c40d0000           -lea edx, [eax + 0xdc4]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(3524) /* 0xdc4 */);
    // 00497ae3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497ae4  ff90dc0d0000           -call dword ptr [eax + 0xddc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(3548) /* 0xddc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497aea  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497aed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497aee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497aef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497af0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497af1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00497af3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00497af6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497af8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00497afb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497afd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497aff  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00497b02  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497b04  052cf45200             -add eax, 0x52f42c
    (cpu.eax) += x86::reg32(x86::sreg32(5436460 /*0x52f42c*/));
    // 00497b09  803800                 +cmp byte ptr [eax], 0
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
    // 00497b0c  7427                   -je 0x497b35
    if (cpu.flags.zf)
    {
        goto L_0x00497b35;
    }
    // 00497b0e  884804                 -mov byte ptr [eax + 4], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.cl;
    // 00497b11  0fbe5001               -movsx edx, byte ptr [eax + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */)));
    // 00497b15  885805                 -mov byte ptr [eax + 5], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = cpu.bl;
    // 00497b18  39ca                   +cmp edx, ecx
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
    // 00497b1a  7c20                   -jl 0x497b3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497b3c;
    }
    // 00497b1c  c64006ff               -mov byte ptr [eax + 6], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 255 /*0xff*/;
L_0x00497b20:
    // 00497b20  0fbe5002               -movsx edx, byte ptr [eax + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */)));
    // 00497b24  39da                   +cmp edx, ebx
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
    // 00497b26  7d1a                   -jge 0x497b42
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00497b42;
    }
    // 00497b28  c6400701               -mov byte ptr [eax + 7], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 1 /*0x1*/;
    // 00497b2c  e86fffffff             -call 0x497aa0
    cpu.esp -= 4;
    sub_497aa0(app, cpu);
    if (cpu.terminate) return;
    // 00497b31  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00497b33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497b35:
    // 00497b35  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00497b3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497b3c:
    // 00497b3c  c6400601               -mov byte ptr [eax + 6], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 1 /*0x1*/;
    // 00497b40  ebde                   -jmp 0x497b20
    goto L_0x00497b20;
L_0x00497b42:
    // 00497b42  c64007ff               -mov byte ptr [eax + 7], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 255 /*0xff*/;
    // 00497b46  e855ffffff             -call 0x497aa0
    cpu.esp -= 4;
    sub_497aa0(app, cpu);
    if (cpu.terminate) return;
    // 00497b4b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497b4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497b4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_497b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497b50  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00497b53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497b55  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00497b58  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497b5a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497b5c  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00497b5f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497b61  052cf45200             -add eax, 0x52f42c
    (cpu.eax) += x86::reg32(x86::sreg32(5436460 /*0x52f42c*/));
    // 00497b66  803800                 +cmp byte ptr [eax], 0
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
    // 00497b69  7506                   -jne 0x497b71
    if (!cpu.flags.zf)
    {
        goto L_0x00497b71;
    }
    // 00497b6b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00497b70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497b71:
    // 00497b71  885803                 -mov byte ptr [eax + 3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 00497b74  e827ffffff             -call 0x497aa0
    cpu.esp -= 4;
    sub_497aa0(app, cpu);
    if (cpu.terminate) return;
    // 00497b79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00497b7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_497b7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497b7c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497b7d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00497b80  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497b82  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00497b85  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497b87  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497b89  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00497b8c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00497b8e  ba2cf45200             -mov edx, 0x52f42c
    cpu.edx = 5436460 /*0x52f42c*/;
    // 00497b93  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00497b95  83baac0d000000         +cmp dword ptr [edx + 0xdac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3500) /* 0xdac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497b9c  7507                   -jne 0x497ba5
    if (!cpu.flags.zf)
    {
        goto L_0x00497ba5;
    }
    // 00497b9e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00497ba3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ba4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497ba5:
    // 00497ba5  8b82600d0000           -mov eax, dword ptr [edx + 0xd60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3424) /* 0xd60 */);
    // 00497bab  ff92ac0d0000           -call dword ptr [edx + 0xdac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(3500) /* 0xdac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497bb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bb2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_497bb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497bb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497bb5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497bb6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497bb9  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00497bbd  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00497bc1  ff15c8b24c00           -call dword ptr [0x4cb2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026504) /* 0x4cb2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497bc7  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00497bcb  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00497bce  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00497bd0  39cb                   +cmp ebx, ecx
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
    // 00497bd2  7320                   -jae 0x497bf4
    if (!cpu.flags.cf)
    {
        goto L_0x00497bf4;
    }
L_0x00497bd4:
    // 00497bd4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00497bd6  0fbf16                 -movsx edx, word ptr [esi]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi)));
    // 00497bd9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00497bdc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00497bde  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497be1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00497be4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497be7  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 00497bea  d95bfc                 -fstp dword ptr [ebx - 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497bed  39cb                   +cmp ebx, ecx
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
    // 00497bef  72e3                   -jb 0x497bd4
    if (cpu.flags.cf)
    {
        goto L_0x00497bd4;
    }
    // 00497bf1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00497bf4:
    // 00497bf4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497bf7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bf8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497bf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497bfc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497bfc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497bfd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497bfe  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00497c01  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00497c05  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00497c09  ff15c8b24c00           -call dword ptr [0x4cb2c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026504) /* 0x4cb2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497c0f  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00497c13  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00497c16  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00497c18  39ce                   +cmp esi, ecx
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
    // 00497c1a  0f8390000000           -jae 0x497cb0
    if (!cpu.flags.cf)
    {
        goto L_0x00497cb0;
    }
L_0x00497c20:
    // 00497c20  df03                   -fild word ptr [ebx]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx))));
    // 00497c22  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 00497c24  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c28  df4302                 -fild word ptr [ebx + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */))));
    // 00497c2b  d806                   -fadd dword ptr [esi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi));
    // 00497c2d  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c31  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00497c35  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00497c37  dd05c4f24b00           -fld qword ptr [0x4bf2c4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(4977348) /* 0x4bf2c4 */)));
    // 00497c3d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497c3f  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 00497c41  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497c44  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c46  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497c48  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c4c  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00497c50  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 00497c52  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497c56  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00497c58  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c5a  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00497c5e  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00497c62  25ffff0f00             -and eax, 0xfffff
    cpu.eax &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00497c67  81e2ffff0f00           -and edx, 0xfffff
    cpu.edx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 00497c6d  3dff7f0000             +cmp eax, 0x7fff
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
    // 00497c72  7649                   -jbe 0x497cbd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497cbd;
    }
    // 00497c74  3d00800f00             +cmp eax, 0xf8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497c79  7342                   -jae 0x497cbd
    if (!cpu.flags.cf)
    {
        goto L_0x00497cbd;
    }
    // 00497c7b  3d00000800             +cmp eax, 0x80000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497c80  7334                   -jae 0x497cb6
    if (!cpu.flags.cf)
    {
        goto L_0x00497cb6;
    }
    // 00497c82  66c703ff7f             -mov word ptr [ebx], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx) = 32767 /*0x7fff*/;
L_0x00497c87:
    // 00497c87  81faff7f0000           +cmp edx, 0x7fff
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32767 /*0x7fff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497c8d  763b                   -jbe 0x497cca
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00497cca;
    }
    // 00497c8f  81fa00800f00           +cmp edx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497c95  7333                   -jae 0x497cca
    if (!cpu.flags.cf)
    {
        goto L_0x00497cca;
    }
    // 00497c97  81fa00000800           +cmp edx, 0x80000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(524288 /*0x80000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497c9d  7323                   -jae 0x497cc2
    if (!cpu.flags.cf)
    {
        goto L_0x00497cc2;
    }
    // 00497c9f  66c74302ff7f           -mov word ptr [ebx + 2], 0x7fff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32767 /*0x7fff*/;
L_0x00497ca5:
    // 00497ca5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497ca8  39ce                   +cmp esi, ecx
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
    // 00497caa  0f8270ffffff           -jb 0x497c20
    if (cpu.flags.cf)
    {
        goto L_0x00497c20;
    }
L_0x00497cb0:
    // 00497cb0  83c410                 +add esp, 0x10
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
    // 00497cb3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497cb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497cb5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497cb6:
    // 00497cb6  66c7030080             -mov word ptr [ebx], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx) = 32768 /*0x8000*/;
    // 00497cbb  ebca                   -jmp 0x497c87
    goto L_0x00497c87;
L_0x00497cbd:
    // 00497cbd  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 00497cc0  ebc5                   -jmp 0x497c87
    goto L_0x00497c87;
L_0x00497cc2:
    // 00497cc2  66c743020080           -mov word ptr [ebx + 2], 0x8000
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = 32768 /*0x8000*/;
    // 00497cc8  ebdb                   -jmp 0x497ca5
    goto L_0x00497ca5;
L_0x00497cca:
    // 00497cca  66895302               -mov word ptr [ebx + 2], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00497cce  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00497cd1  39ce                   +cmp esi, ecx
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
    // 00497cd3  0f8247ffffff           -jb 0x497c20
    if (cpu.flags.cf)
    {
        goto L_0x00497c20;
    }
    // 00497cd9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00497cdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497cdd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497cde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_497ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497ce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497ce2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497ce3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497ce4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497ce5  83ec64                 -sub esp, 0x64
    (cpu.esp) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00497ce8  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00497cec  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00497cf0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00497cf2  be2cf45200             -mov esi, 0x52f42c
    cpu.esi = 5436460 /*0x52f42c*/;
    // 00497cf7  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 00497cfb  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x00497cff:
    // 00497cff  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 00497d01  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00497d03  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00497d05  0f85bb000000           -jne 0x497dc6
    if (!cpu.flags.zf)
    {
        goto L_0x00497dc6;
    }
L_0x00497d0b:
    // 00497d0b  8b6c2460               -mov ebp, dword ptr [esp + 0x60]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00497d0f  45                     -inc ebp
    (cpu.ebp)++;
    // 00497d10  81c6e40d0000           -add esi, 0xde4
    (cpu.esi) += x86::reg32(x86::sreg32(3556 /*0xde4*/));
    // 00497d16  896c2460               -mov dword ptr [esp + 0x60], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.ebp;
    // 00497d1a  83fd10                 +cmp ebp, 0x10
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
    // 00497d1d  7ce0                   -jl 0x497cff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497cff;
    }
L_0x00497d1f:
    // 00497d1f  837c245000             +cmp dword ptr [esp + 0x50], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497d24  0f8498010000           -je 0x497ec2
    if (cpu.flags.zf)
    {
        goto L_0x00497ec2;
    }
    // 00497d2a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00497d2c  89356cd25300           -mov dword ptr [0x53d26c], esi
    app->getMemory<x86::reg32>(x86::reg32(5493356) /* 0x53d26c */) = cpu.esi;
L_0x00497d32:
    // 00497d32  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00497d36  8b3ddcb24c00           -mov edi, dword ptr [0x4cb2dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5026524) /* 0x4cb2dc */);
    // 00497d3c  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00497d3e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00497d40  0f849a010000           -je 0x497ee0
    if (cpu.flags.zf)
    {
        goto L_0x00497ee0;
    }
    // 00497d46  68e0b24c00             -push 0x4cb2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5026528 /*0x4cb2e0*/;
    cpu.esp -= 4;
    // 00497d4b  68e0b64c00             -push 0x4cb6e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5027552 /*0x4cb6e0*/;
    cpu.esp -= 4;
    // 00497d50  8b74245c               -mov esi, dword ptr [esp + 0x5c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00497d54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497d55  e85afeffff             -call 0x497bb4
    cpu.esp -= 4;
    sub_497bb4(app, cpu);
    if (cpu.terminate) return;
    // 00497d5a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497d5d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497d5e  68e0b64c00             -push 0x4cb6e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5027552 /*0x4cb6e0*/;
    cpu.esp -= 4;
    // 00497d63  ff15c4b24c00           -call dword ptr [0x4cb2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026500) /* 0x4cb2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497d69  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497d6c  68e0b24c00             -push 0x4cb2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5026528 /*0x4cb2e0*/;
    cpu.esp -= 4;
    // 00497d71  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497d72  e8190b0100             -call 0x4a8890
    cpu.esp -= 4;
    sub_4a8890(app, cpu);
    if (cpu.terminate) return;
    // 00497d77  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497d7a  8b2dccb24c00           -mov ebp, dword ptr [0x4cb2cc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 00497d80  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497d81  68e0b24c00             -push 0x4cb2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5026528 /*0x4cb2e0*/;
    cpu.esp -= 4;
    // 00497d86  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497d87  e870feffff             -call 0x497bfc
    cpu.esp -= 4;
    sub_497bfc(app, cpu);
    if (cpu.terminate) return;
    // 00497d8c  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00497d8f:
    // 00497d8f  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00497d93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497d94  8b0dccb24c00           -mov ecx, dword ptr [0x4cb2cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 00497d9a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497d9b  8b5c245c               -mov ebx, dword ptr [esp + 0x5c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00497d9f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497da0  ff1574d25300           -call dword ptr [0x53d274]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5493364) /* 0x53d274 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497da6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497da9  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 00497dac  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497dad  8b35ccb24c00           -mov esi, dword ptr [0x4cb2cc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 00497db3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497db4  ff15c4b24c00           -call dword ptr [0x4cb2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026500) /* 0x4cb2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497dba  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497dbd  83c464                 -add esp, 0x64
    (cpu.esp) += x86::reg32(x86::sreg32(100 /*0x64*/));
    // 00497dc0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497dc1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497dc2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497dc3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497dc4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497dc5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497dc6:
    // 00497dc6  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00497dca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00497dcc  8b6c2454               -mov ebp, dword ptr [esp + 0x54]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00497dd0  e8cbfaffff             -call 0x4978a0
    cpu.esp -= 4;
    sub_4978a0(app, cpu);
    if (cpu.terminate) return;
    // 00497dd5  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 00497dd9  29c5                   +sub ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00497ddb  0f843effffff           -je 0x497d1f
    if (cpu.flags.zf)
    {
        goto L_0x00497d1f;
    }
    // 00497de1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497de2  8d86640d0000           -lea eax, [esi + 0xd64]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3428) /* 0xd64 */);
    // 00497de8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497de9  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00497ded  ff97b40d0000           -call dword ptr [edi + 0xdb4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3508) /* 0xdb4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497df3  8b0dd0b24c00           -mov ecx, dword ptr [0x4cb2d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026512) /* 0x4cb2d0 */);
    // 00497df9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497dfc  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00497dff  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 00497e03  8d5c2440               -lea ebx, [esp + 0x40]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00497e07  8b8e600d0000           -mov ecx, dword ptr [esi + 0xd60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(3424) /* 0xd60 */);
    // 00497e0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497e0f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497e11  ff97a80d0000           -call dword ptr [edi + 0xda8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3496) /* 0xda8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497e17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00497e19  0f8c95000000           -jl 0x497eb4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497eb4;
    }
    // 00497e1f  8b0dd4b24c00           -mov ecx, dword ptr [0x4cb2d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026516) /* 0x4cb2d4 */);
    // 00497e25  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00497e29  894c2440               -mov dword ptr [esp + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ecx;
    // 00497e2d  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00497e31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497e32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497e33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497e34  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00497e38  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497e39  ff97b80d0000           -call dword ptr [edi + 0xdb8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3512) /* 0xdb8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497e3f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00497e42  8a0dd8b24c00           -mov cl, byte ptr [0x4cb2d8]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5026520) /* 0x4cb2d8 */);
    // 00497e48  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00497e4c  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00497e4e  8b0dccb24c00           -mov ecx, dword ptr [0x4cb2cc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 00497e54  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00497e57  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00497e59  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497e5a  8b4c2444               -mov ecx, dword ptr [esp + 0x44]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00497e5e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497e5f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497e60  8d86900d0000           -lea eax, [esi + 0xd90]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3472) /* 0xd90 */);
    // 00497e66  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497e67  ff97c00d0000           -call dword ptr [edi + 0xdc0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3520) /* 0xdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497e6d  8a5608                 -mov dl, byte ptr [esi + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00497e70  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00497e73  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00497e75  0f8490feffff           -je 0x497d0b
    if (cpu.flags.zf)
    {
        goto L_0x00497d0b;
    }
    // 00497e7b  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00497e7f  8a0dd8b24c00           -mov cl, byte ptr [0x4cb2d8]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5026520) /* 0x4cb2d8 */);
    // 00497e85  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 00497e87  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00497e8a  05e0b64c00             -add eax, 0x4cb6e0
    (cpu.eax) += x86::reg32(x86::sreg32(5027552 /*0x4cb6e0*/));
    // 00497e8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497e90  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00497e94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497e95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497e96  8d86c40d0000           -lea eax, [esi + 0xdc4]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(3524) /* 0xdc4 */);
    // 00497e9c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497e9d  ff97e00d0000           -call dword ptr [edi + 0xde0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(3552) /* 0xde0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497ea3  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00497ea8  83c410                 +add esp, 0x10
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
    // 00497eab  897c2450               -mov dword ptr [esp + 0x50], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 00497eaf  e957feffff             -jmp 0x497d0b
    goto L_0x00497d0b;
L_0x00497eb4:
    // 00497eb4  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00497eb8  e83bfbffff             -call 0x4979f8
    cpu.esp -= 4;
    sub_4979f8(app, cpu);
    if (cpu.terminate) return;
    // 00497ebd  e949feffff             -jmp 0x497d0b
    goto L_0x00497d0b;
L_0x00497ec2:
    // 00497ec2  8b0d6cd25300           -mov ecx, dword ptr [0x53d26c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5493356) /* 0x53d26c */);
    // 00497ec8  41                     -inc ecx
    (cpu.ecx)++;
    // 00497ec9  890d6cd25300           -mov dword ptr [0x53d26c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5493356) /* 0x53d26c */) = cpu.ecx;
    // 00497ecf  81f9f4010000           +cmp ecx, 0x1f4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497ed5  0f8c57feffff           -jl 0x497d32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00497d32;
    }
    // 00497edb  e9affeffff             -jmp 0x497d8f
    goto L_0x00497d8f;
L_0x00497ee0:
    // 00497ee0  68e0b24c00             -push 0x4cb2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5026528 /*0x4cb2e0*/;
    cpu.esp -= 4;
    // 00497ee5  68e0b64c00             -push 0x4cb6e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5027552 /*0x4cb6e0*/;
    cpu.esp -= 4;
    // 00497eea  8b6c245c               -mov ebp, dword ptr [esp + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00497eee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497eef  e86c0b0100             -call 0x4a8a60
    cpu.esp -= 4;
    sub_4a8a60(app, cpu);
    if (cpu.terminate) return;
    // 00497ef4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497ef7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497ef8  68e0b64c00             -push 0x4cb6e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5027552 /*0x4cb6e0*/;
    cpu.esp -= 4;
    // 00497efd  ff15c4b24c00           -call dword ptr [0x4cb2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5026500) /* 0x4cb2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497f03  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497f06  68e0b24c00             -push 0x4cb2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5026528 /*0x4cb2e0*/;
    cpu.esp -= 4;
    // 00497f0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497f0c  e87f090100             -call 0x4a8890
    cpu.esp -= 4;
    sub_4a8890(app, cpu);
    if (cpu.terminate) return;
    // 00497f11  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497f14  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00497f18  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497f19  8d44244c               -lea eax, [esp + 0x4c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00497f1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497f1e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497f22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497f23  e850de0000             -call 0x4a5d78
    cpu.esp -= 4;
    sub_4a5d78(app, cpu);
    if (cpu.terminate) return;
    // 00497f28  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497f2b  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00497f2d  6a7f                   -push 0x7f
    app->getMemory<x86::reg32>(cpu.esp-4) = 127 /*0x7f*/;
    cpu.esp -= 4;
    // 00497f2f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00497f33  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497f34  ff542450               -call dword ptr [esp + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497f38  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00497f3b  8b15ccb24c00           -mov edx, dword ptr [0x4cb2cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5026508) /* 0x4cb2cc */);
    // 00497f41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497f42  68e0b24c00             -push 0x4cb2e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5026528 /*0x4cb2e0*/;
    cpu.esp -= 4;
    // 00497f47  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497f48  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00497f4c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00497f4d  ff542458               -call dword ptr [esp + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00497f51  83c410                 +add esp, 0x10
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
    // 00497f54  e936feffff             -jmp 0x497d8f
    goto L_0x00497d8f;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_497f5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497f5c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00497f5d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497f5e  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00497f60  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00497f62  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497f64  7e28                   -jle 0x497f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497f8e;
    }
L_0x00497f66:
    // 00497f66  81f900010000           +cmp ecx, 0x100
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
    // 00497f6c  7e23                   -jle 0x497f91
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497f91;
    }
    // 00497f6e  b800010000             -mov eax, 0x100
    cpu.eax = 256 /*0x100*/;
L_0x00497f73:
    // 00497f73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497f75  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00497f77  e864fdffff             -call 0x497ce0
    cpu.esp -= 4;
    sub_497ce0(app, cpu);
    if (cpu.terminate) return;
    // 00497f7c  8b1578d25300           -mov edx, dword ptr [0x53d278]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5493368) /* 0x53d278 */);
    // 00497f82  81e900010000           -sub ecx, 0x100
    (cpu.ecx) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00497f88  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00497f8a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00497f8c  7fd8                   -jg 0x497f66
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00497f66;
    }
L_0x00497f8e:
    // 00497f8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497f90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00497f91:
    // 00497f91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00497f93  ebde                   -jmp 0x497f73
    goto L_0x00497f73;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_497fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497fa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497fa1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497fa2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497fa3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00497fa4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00497fa5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497fa8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00497fac  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00497fb0  d84c2420               -fmul dword ptr [esp + 0x20]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(32) /* 0x20 */));
    // 00497fb4  e89724feff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 00497fb9  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
L_0x00497fbc:
    // 00497fbc  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00497fc1  3b0c24                 +cmp ecx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00497fc4  7f11                   -jg 0x497fd7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00497fd7;
    }
    // 00497fc6  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
L_0x00497fc9:
    // 00497fc9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00497fcc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00497fce  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00497fd1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00497fd3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00497fd5  750f                   -jne 0x497fe6
    if (!cpu.flags.zf)
    {
        goto L_0x00497fe6;
    }
L_0x00497fd7:
    // 00497fd7  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00497fda  39f9                   +cmp ecx, edi
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
    // 00497fdc  740f                   -je 0x497fed
    if (cpu.flags.zf)
    {
        goto L_0x00497fed;
    }
    // 00497fde  8d6f01                 -lea ebp, [edi + 1]
    cpu.ebp = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00497fe1  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00497fe4  ebd6                   -jmp 0x497fbc
    goto L_0x00497fbc;
L_0x00497fe6:
    // 00497fe6  41                     -inc ecx
    (cpu.ecx)++;
    // 00497fe7  39f1                   +cmp ecx, esi
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
    // 00497fe9  7ede                   -jle 0x497fc9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00497fc9;
    }
    // 00497feb  ebea                   -jmp 0x497fd7
    goto L_0x00497fd7;
L_0x00497fed:
    // 00497fed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00497fef  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00497ff2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ff3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ff4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ff5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ff6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00497ff7  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_497ffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00497ffc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00497ffd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00497ffe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00497fff  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00498002  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00498004  c7442408cdcccc3d       -mov dword ptr [esp + 8], 0x3dcccccd
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1036831949 /*0x3dcccccd*/;
    // 0049800c  3d22560000             +cmp eax, 0x5622
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22050 /*0x5622*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498011  0f8f96000000           -jg 0x4980ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004980ad;
    }
    // 00498017  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00498019:
    // 00498019  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049801c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049801e  898a8cd25300           -mov dword ptr [edx + 0x53d28c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5493388) /* 0x53d28c */) = cpu.ecx;
    // 00498024  81fa10590000           +cmp edx, 0x5910
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22800 /*0x5910*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049802a  75ed                   -jne 0x498019
    if (!cpu.flags.zf)
    {
        goto L_0x00498019;
    }
    // 0049802c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049802d  b990d25300             -mov ecx, 0x53d290
    cpu.ecx = 5493392 /*0x53d290*/;
    // 00498032  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00498034:
    // 00498034  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498037  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 0049803b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049803d  898abc2b5400           -mov dword ptr [edx + 0x542bbc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5516220) /* 0x542bbc */) = cpu.ecx;
    // 00498043  e858ffffff             -call 0x497fa0
    cpu.esp -= 4;
    sub_497fa0(app, cpu);
    if (cpu.terminate) return;
    // 00498048  d982ecbe4c00           -fld dword ptr [edx + 0x4cbeec]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(5029612) /* 0x4cbeec */)));
    // 0049804e  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 00498050  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 00498052  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00498059  d99afcbe4c00           -fstp dword ptr [edx + 0x4cbefc]
    app->getMemory<float>(cpu.edx + x86::reg32(5029628) /* 0x4cbefc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049805f  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00498063  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00498065  dc0dccf24b00           -fmul qword ptr [0x4bf2cc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4977356) /* 0x4bf2cc */));
    // 0049806b  8b82bc2b5400           -mov eax, dword ptr [edx + 0x542bbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5516220) /* 0x542bbc */);
    // 00498071  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00498073  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498076  89829c2b5400           -mov dword ptr [edx + 0x542b9c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5516188) /* 0x542b9c */) = cpu.eax;
    // 0049807c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049807e  8982ac2b5400           -mov dword ptr [edx + 0x542bac], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5516204) /* 0x542bac */) = cpu.eax;
    // 00498084  899adc2b5400           -mov dword ptr [edx + 0x542bdc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5516252) /* 0x542bdc */) = cpu.ebx;
    // 0049808a  899a7cd25300           -mov dword ptr [edx + 0x53d27c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5493372) /* 0x53d27c */) = cpu.ebx;
    // 00498090  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498092  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00498094  899acc2b5400           -mov dword ptr [edx + 0x542bcc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5516236) /* 0x542bcc */) = cpu.ebx;
    // 0049809a  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0049809e  83fa10                 +cmp edx, 0x10
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
    // 004980a1  7591                   -jne 0x498034
    if (!cpu.flags.zf)
    {
        goto L_0x00498034;
    }
    // 004980a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004980a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980a6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004980a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004980ad:
    // 004980ad  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004980b2  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004980b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4980c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004980c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004980c1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004980c4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004980c6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004980c8  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004980cc  e8bf090100             -call 0x4a8a90
    cpu.esp -= 4;
    sub_4a8a90(app, cpu);
    if (cpu.terminate) return;
    // 004980d1  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004980d5  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004980d7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004980db  db442404               -fild dword ptr [esp + 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004980df  def9                   -fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004980e1  d80dd4f24b00           -fmul dword ptr [0x4bf2d4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(4977364) /* 0x4bf2d4 */));
    // 004980e7  e86423feff             -call 0x47a450
    cpu.esp -= 4;
    sub_47a450(app, cpu);
    if (cpu.terminate) return;
    // 004980ec  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004980ef  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004980f2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004980f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004980f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498100  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00498102  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00498104  83f840                 +cmp eax, 0x40
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
    // 00498107  740a                   -je 0x498113
    if (cpu.flags.zf)
    {
        goto L_0x00498113;
    }
    // 00498109  7d09                   -jge 0x498114
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498114;
    }
    // 0049810b  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0049810e  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 00498111  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00498113:
    // 00498113  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498114:
    // 00498114  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00498119  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049811b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049811d  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00498120  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 00498123  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00498125  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498131  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498132  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498133  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00498135  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00498137:
    // 00498137  4a                     -dec edx
    (cpu.edx)--;
    // 00498138  83faff                 +cmp edx, -1
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
    // 0049813b  740c                   -je 0x498149
    if (cpu.flags.zf)
    {
        goto L_0x00498149;
    }
    // 0049813d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049813f  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 00498142  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00498144  40                     -inc eax
    (cpu.eax)++;
    // 00498145  01d9                   +add ecx, ebx
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
    // 00498147  ebee                   -jmp 0x498137
    goto L_0x00498137;
L_0x00498149:
    // 00498149  83fe01                 +cmp esi, 1
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
    // 0049814c  7505                   -jne 0x498153
    if (!cpu.flags.zf)
    {
        goto L_0x00498153;
    }
    // 0049814e  83f97f                 +cmp ecx, 0x7f
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
    // 00498151  7f26                   -jg 0x498179
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498179;
    }
L_0x00498153:
    // 00498153  83fe02                 +cmp esi, 2
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
    // 00498156  7508                   -jne 0x498160
    if (!cpu.flags.zf)
    {
        goto L_0x00498160;
    }
    // 00498158  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 0049815e  7f21                   -jg 0x498181
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498181;
    }
L_0x00498160:
    // 00498160  83fe03                 +cmp esi, 3
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
    // 00498163  750e                   -jne 0x498173
    if (!cpu.flags.zf)
    {
        goto L_0x00498173;
    }
    // 00498165  81f9ffff7f00           +cmp ecx, 0x7fffff
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
    // 0049816b  7e06                   -jle 0x498173
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498173;
    }
    // 0049816d  81e900000001           -sub ecx, 0x1000000
    (cpu.ecx) -= x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
L_0x00498173:
    // 00498173  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00498175  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498176  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498177  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498178  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498179:
    // 00498179  81e900010000           +sub ecx, 0x100
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
    // 0049817f  ebf2                   -jmp 0x498173
    goto L_0x00498173;
L_0x00498181:
    // 00498181  81e900000100           -sub ecx, 0x10000
    (cpu.ecx) -= x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 00498187  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00498189  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049818a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049818b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049818c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498190  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
    // 00498196  c7809000000000000000   -mov dword ptr [eax + 0x90], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */) = 0 /*0x0*/;
    // 004981a0  c7406c0f000000         -mov dword ptr [eax + 0x6c], 0xf
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 15 /*0xf*/;
    // 004981a7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4981a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004981a8  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004981af  c740087f000000         -mov dword ptr [eax + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 004981b6  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004981bd  c740107f000000         -mov dword ptr [eax + 0x10], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 127 /*0x7f*/;
    // 004981c4  c74014ffffffff         -mov dword ptr [eax + 0x14], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 4294967295 /*0xffffffff*/;
    // 004981cb  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004981d2  c7401c3c000000         -mov dword ptr [eax + 0x1c], 0x3c
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 60 /*0x3c*/;
    // 004981d9  c74020ffffffff         -mov dword ptr [eax + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 004981e0  c7402401000000         -mov dword ptr [eax + 0x24], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 1 /*0x1*/;
    // 004981e7  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 004981ee  c7402c01000000         -mov dword ptr [eax + 0x2c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 1 /*0x1*/;
    // 004981f5  c7403040000000         -mov dword ptr [eax + 0x30], 0x40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 64 /*0x40*/;
    // 004981fc  c7403400000000         -mov dword ptr [eax + 0x34], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 00498203  c740387f000000         -mov dword ptr [eax + 0x38], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 127 /*0x7f*/;
    // 0049820a  c7403c00000000         -mov dword ptr [eax + 0x3c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = 0 /*0x0*/;
    // 00498211  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00498218  c7404400000000         -mov dword ptr [eax + 0x44], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0049821f  c7404800000000         -mov dword ptr [eax + 0x48], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 00498226  c7404c00000000         -mov dword ptr [eax + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 0049822d  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00498234  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 0049823b  c7406420bf4c00         -mov dword ptr [eax + 0x64], 0x4cbf20
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 5029664 /*0x4cbf20*/;
    // 00498242  c740707f000000         -mov dword ptr [eax + 0x70], 0x7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = 127 /*0x7f*/;
    // 00498249  c7407400000000         -mov dword ptr [eax + 0x74], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 00498250  c7407800000000         -mov dword ptr [eax + 0x78], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 00498257  c7407c00000000         -mov dword ptr [eax + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 0049825e  c7808000000000000000   -mov dword ptr [eax + 0x80], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 00498268  c7808400000000000000   -mov dword ptr [eax + 0x84], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 00498272  c7808c00000000000000   -mov dword ptr [eax + 0x8c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */) = 0 /*0x0*/;
    // 0049827c  c7808800000000000000   -mov dword ptr [eax + 0x88], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 00498286  c7809400000001000000   -mov dword ptr [eax + 0x94], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */) = 1 /*0x1*/;
    // 00498290  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498292  81c298000000           -add edx, 0x98
    (cpu.edx) += x86::reg32(x86::sreg32(152 /*0x98*/));
L_0x00498298:
    // 00498298  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0049829e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004982a1  39d0                   +cmp eax, edx
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
    // 004982a3  75f3                   -jne 0x498298
    if (!cpu.flags.zf)
    {
        goto L_0x00498298;
    }
    // 004982a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4982a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004982a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004982a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004982aa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004982ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004982ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004982ad  83784800               +cmp dword ptr [eax + 0x48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004982b1  7552                   -jne 0x498305
    if (!cpu.flags.zf)
    {
        goto L_0x00498305;
    }
L_0x004982b3:
    // 004982b3  8b7054                 -mov esi, dword ptr [eax + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004982b6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004982b8  7409                   -je 0x4982c3
    if (cpu.flags.zf)
    {
        goto L_0x004982c3;
    }
    // 004982ba  8b4a54                 -mov ecx, dword ptr [edx + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 004982bd  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004982c0  897854                 -mov dword ptr [eax + 0x54], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edi;
L_0x004982c3:
    // 004982c3  8b685c                 -mov ebp, dword ptr [eax + 0x5c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 004982c6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004982c8  7409                   -je 0x4982d3
    if (cpu.flags.zf)
    {
        goto L_0x004982d3;
    }
    // 004982ca  8b4a5c                 -mov ecx, dword ptr [edx + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(92) /* 0x5c */);
    // 004982cd  8d1c29                 -lea ebx, [ecx + ebp]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004982d0  89585c                 -mov dword ptr [eax + 0x5c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.ebx;
L_0x004982d3:
    // 004982d3  8b7064                 -mov esi, dword ptr [eax + 0x64]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    // 004982d6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004982d8  7409                   -je 0x4982e3
    if (cpu.flags.zf)
    {
        goto L_0x004982e3;
    }
    // 004982da  8b4a64                 -mov ecx, dword ptr [edx + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    // 004982dd  8d3c0e                 -lea edi, [esi + ecx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004982e0  897864                 -mov dword ptr [eax + 0x64], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = cpu.edi;
L_0x004982e3:
    // 004982e3  8b6874                 -mov ebp, dword ptr [eax + 0x74]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 004982e6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004982e8  7409                   -je 0x4982f3
    if (cpu.flags.zf)
    {
        goto L_0x004982f3;
    }
    // 004982ea  8b4a74                 -mov ecx, dword ptr [edx + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */);
    // 004982ed  8d1c29                 -lea ebx, [ecx + ebp]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004982f0  895874                 -mov dword ptr [eax + 0x74], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ebx;
L_0x004982f3:
    // 004982f3  8bb080000000           -mov esi, dword ptr [eax + 0x80]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004982f9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004982fb  7510                   -jne 0x49830d
    if (!cpu.flags.zf)
    {
        goto L_0x0049830d;
    }
    // 004982fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004982ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498300  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498301  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498302  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498303  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498304  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498305:
    // 00498305  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00498308  014848                 +add dword ptr [eax + 0x48], ecx
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049830b  eba6                   -jmp 0x4982b3
    goto L_0x004982b3;
L_0x0049830d:
    // 0049830d  8b9280000000           -mov edx, dword ptr [edx + 0x80]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 00498313  8d3c16                 -lea edi, [esi + edx]
    cpu.edi = x86::reg32(cpu.esi + cpu.edx * 1);
    // 00498316  89b880000000           -mov dword ptr [eax + 0x80], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */) = cpu.edi;
    // 0049831c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049831e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049831f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498320  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498321  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498322  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498323  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498324(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498324  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498325  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498326  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498327  8a3d28bf4c00           -mov bh, byte ptr [0x4cbf28]
    cpu.bh = app->getMemory<x86::reg8>(x86::reg32(5029672) /* 0x4cbf28 */);
    // 0049832d  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
L_0x0049832f:
    // 0049832f  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 00498331  742a                   -je 0x49835d
    if (cpu.flags.zf)
    {
        goto L_0x0049835d;
    }
L_0x00498333:
    // 00498333  b800845200             -mov eax, 0x528400
    cpu.eax = 5407744 /*0x528400*/;
    // 00498338  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0049833a:
    // 0049833a  3a480c                 +cmp cl, byte ptr [eax + 0xc]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049833d  7407                   -je 0x498346
    if (cpu.flags.zf)
    {
        goto L_0x00498346;
    }
    // 0049833f  8a583b                 -mov bl, byte ptr [eax + 0x3b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */);
    // 00498342  38fb                   +cmp bl, bh
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
    // 00498344  74e9                   -je 0x49832f
    if (cpu.flags.zf)
    {
        goto L_0x0049832f;
    }
L_0x00498346:
    // 00498346  42                     -inc edx
    (cpu.edx)++;
    // 00498347  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0049834a  83fa10                 +cmp edx, 0x10
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
    // 0049834d  7ceb                   -jl 0x49833a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049833a;
    }
    // 0049834f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00498351  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 00498353  883d28bf4c00           -mov byte ptr [0x4cbf28], bh
    app->getMemory<x86::reg8>(x86::reg32(5029672) /* 0x4cbf28 */) = cpu.bh;
    // 00498359  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049835a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049835b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049835c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049835d:
    // 0049835d  fec7                   +inc bh
    {
        x86::reg8& tmp = cpu.bh;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0049835f  ebd2                   -jmp 0x498333
    goto L_0x00498333;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498364(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498364  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498365  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498366  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498367  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049836a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049836d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00498371  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00498373  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00498375  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00498379  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049837c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049837f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00498383  8b4305                 -mov eax, dword ptr [ebx + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5) /* 0x5 */);
    // 00498386  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498389  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049838d  8b4306                 -mov eax, dword ptr [ebx + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6) /* 0x6 */);
    // 00498390  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498393  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00498397  8b4307                 -mov eax, dword ptr [ebx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(7) /* 0x7 */);
    // 0049839a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0049839d  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004983a1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004983a3  e800ffffff             -call 0x4982a8
    cpu.esp -= 4;
    sub_4982a8(app, cpu);
    if (cpu.terminate) return;
    // 004983a8  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004983ac  83faff                 +cmp edx, -1
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
    // 004983af  0f8429030000           -je 0x4986de
    if (cpu.flags.zf)
    {
        goto L_0x004986de;
    }
    // 004983b5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004983b7  0f8c2e030000           -jl 0x4986eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004986eb;
    }
    // 004983bd  83fa7f                 +cmp edx, 0x7f
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
    // 004983c0  0f8f25030000           -jg 0x4986eb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004986eb;
    }
L_0x004983c6:
    // 004983c6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004983ca  83f8ff                 +cmp eax, -1
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
    // 004983cd  0f8526030000           -jne 0x4986f9
    if (!cpu.flags.zf)
    {
        goto L_0x004986f9;
    }
    // 004983d3  c744241840000000       -mov dword ptr [esp + 0x18], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 64 /*0x40*/;
L_0x004983db:
    // 004983db  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004983df  83fdff                 +cmp ebp, -1
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
    // 004983e2  0f852c030000           -jne 0x498714
    if (!cpu.flags.zf)
    {
        goto L_0x00498714;
    }
    // 004983e8  c74424087f000000       -mov dword ptr [esp + 8], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
L_0x004983f0:
    // 004983f0  8b4630                 -mov eax, dword ptr [esi + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 004983f3  8b5e34                 -mov ebx, dword ptr [esi + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */);
    // 004983f6  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004983fa  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004983fc  7411                   -je 0x49840f
    if (cpu.flags.zf)
    {
        goto L_0x0049840f;
    }
    // 004983fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498400  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498404  e8d7c70000             -call 0x4a4be0
    cpu.esp -= 4;
    sub_4a4be0(app, cpu);
    if (cpu.terminate) return;
    // 00498409  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049840b  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
L_0x0049840f:
    // 0049840f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498413  83f87f                 +cmp eax, 0x7f
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
    // 00498416  0f8e13030000           -jle 0x49872f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049872f;
    }
    // 0049841c  c74424147f000000       -mov dword ptr [esp + 0x14], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = 127 /*0x7f*/;
L_0x00498424:
    // 00498424  8bae94000000           -mov ebp, dword ptr [esi + 0x94]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 0049842a  83fd01                 +cmp ebp, 1
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
    // 0049842d  7411                   -je 0x498440
    if (cpu.flags.zf)
    {
        goto L_0x00498440;
    }
    // 0049842f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498433  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00498436  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 00498439  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049843c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x00498440:
    // 00498440  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498444  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00498448  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0049844b  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049844f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498451  0f8ceb020000           -jl 0x498742
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498742;
    }
    // 00498457  83f87f                 +cmp eax, 0x7f
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
    // 0049845a  7e08                   -jle 0x498464
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498464;
    }
    // 0049845c  c74424187f000000       -mov dword ptr [esp + 0x18], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 127 /*0x7f*/;
L_0x00498464:
    // 00498464  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00498468  83f9ff                 +cmp ecx, -1
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
    // 0049846b  0f85dc020000           -jne 0x49874d
    if (!cpu.flags.zf)
    {
        goto L_0x0049874d;
    }
    // 00498471  c744241040000000       -mov dword ptr [esp + 0x10], 0x40
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 64 /*0x40*/;
L_0x00498479:
    // 00498479  b9f02b5400             -mov ecx, 0x542bf0
    cpu.ecx = 5516272 /*0x542bf0*/;
    // 0049847e  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00498481  8b562c                 -mov edx, dword ptr [esi + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 00498484  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00498487  e8c0c4ffff             -call 0x49494c
    cpu.esp -= 4;
    sub_49494c(app, cpu);
    if (cpu.terminate) return;
    // 0049848c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0049848e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498490  0f8c3f020000           -jl 0x4986d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004986d5;
    }
    // 00498496  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0049849d  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0049849f  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 004984a2  81c100845200           -add ecx, 0x528400
    (cpu.ecx) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 004984a8  8a8694000000           -mov al, byte ptr [esi + 0x94]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 004984ae  884137                 -mov byte ptr [ecx + 0x37], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(55) /* 0x37 */) = cpu.al;
    // 004984b1  668b4640               -mov ax, word ptr [esi + 0x40]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */);
    // 004984b5  66894110               -mov word ptr [ecx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004984b9  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004984bd  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004984c1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004984c3  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 004984c6  668b5910               -mov bx, word ptr [ecx + 0x10]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004984ca  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004984cc  66895910               -mov word ptr [ecx + 0x10], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.bx;
    // 004984d0  83be9000000000         +cmp dword ptr [esi + 0x90], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(144) /* 0x90 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004984d7  740c                   -je 0x4984e5
    if (cpu.flags.zf)
    {
        goto L_0x004984e5;
    }
    // 004984d9  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004984dd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004984df  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004984e1  66895110               -mov word ptr [ecx + 0x10], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dx;
L_0x004984e5:
    // 004984e5  8b5e44                 -mov ebx, dword ptr [esi + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 004984e8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004984ea  740b                   -je 0x4984f7
    if (cpu.flags.zf)
    {
        goto L_0x004984f7;
    }
    // 004984ec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004984ee  e8edc60000             -call 0x4a4be0
    cpu.esp -= 4;
    sub_4a4be0(app, cpu);
    if (cpu.terminate) return;
    // 004984f3  66014110               -add word ptr [ecx + 0x10], ax
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.ax));
L_0x004984f7:
    // 004984f7  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 004984fa  89414c                 -mov dword ptr [ecx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 004984fd  8b4654                 -mov eax, dword ptr [esi + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */);
    // 00498500  894150                 -mov dword ptr [ecx + 0x50], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00498503  8b465c                 -mov eax, dword ptr [esi + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    // 00498506  894154                 -mov dword ptr [ecx + 0x54], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(84) /* 0x54 */) = cpu.eax;
    // 00498509  8b4150                 -mov eax, dword ptr [ecx + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 0049850c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049850e  740b                   -je 0x49851b
    if (cpu.flags.zf)
    {
        goto L_0x0049851b;
    }
    // 00498510  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 00498514  0fbe00                 -movsx eax, byte ptr [eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.eax)));
    // 00498517  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0049851b:
    // 0049851b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0049851d  88410d                 -mov byte ptr [ecx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 00498520  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00498524  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0049852b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0049852e  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00498531  8b5e3c                 -mov ebx, dword ptr [esi + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00498534  8b5638                 -mov edx, dword ptr [esi + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00498537  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498539  7409                   -je 0x498544
    if (cpu.flags.zf)
    {
        goto L_0x00498544;
    }
    // 0049853b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0049853d  e89ec60000             -call 0x4a4be0
    cpu.esp -= 4;
    sub_4a4be0(app, cpu);
    if (cpu.terminate) return;
    // 00498542  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00498544:
    // 00498544  83fa7f                 +cmp edx, 0x7f
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
    // 00498547  0f8e1b020000           -jle 0x498768
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498768;
    }
    // 0049854d  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
L_0x00498552:
    // 00498552  0faf542434             -imul edx, dword ptr [esp + 0x34]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))));
    // 00498557  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 0049855c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049855e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00498561  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00498563  884130                 -mov byte ptr [ecx + 0x30], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.al;
    // 00498566  8a442414               -mov al, byte ptr [esp + 0x14]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049856a  884132                 -mov byte ptr [ecx + 0x32], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(50) /* 0x32 */) = cpu.al;
    // 0049856d  8a442418               -mov al, byte ptr [esp + 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498571  88410f                 -mov byte ptr [ecx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 00498574  668b4628               -mov ax, word ptr [esi + 0x28]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 00498578  6bc064                 -imul eax, eax, 0x64
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(100 /*0x64*/)));
    // 0049857b  66894142               -mov word ptr [ecx + 0x42], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(66) /* 0x42 */) = cpu.ax;
    // 0049857f  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00498583  884133                 -mov byte ptr [ecx + 0x33], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(51) /* 0x33 */) = cpu.al;
    // 00498586  8b4664                 -mov eax, dword ptr [esi + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(100) /* 0x64 */);
    // 00498589  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0049858c  8b4670                 -mov eax, dword ptr [esi + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */);
    // 0049858f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00498592  c6413500               -mov byte ptr [ecx + 0x35], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(53) /* 0x35 */) = 0 /*0x0*/;
    // 00498596  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00498599  8a4624                 -mov al, byte ptr [esi + 0x24]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0049859c  884134                 -mov byte ptr [ecx + 0x34], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.al;
    // 0049859f  8a4620                 -mov al, byte ptr [esi + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004985a2  884136                 -mov byte ptr [ecx + 0x36], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(54) /* 0x36 */) = cpu.al;
    // 004985a5  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004985a8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004985aa  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004985ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004985af  0f8cc6010000           -jl 0x49877b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049877b;
    }
L_0x004985b5:
    // 004985b5  8b4148                 -mov eax, dword ptr [ecx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */);
    // 004985b8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004985bb  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 004985be  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004985c1  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004985c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004985c5  8b592c                 -mov ebx, dword ptr [ecx + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 004985c8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004985cb  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004985cd  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004985d0  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 004985d3  894158                 -mov dword ptr [ecx + 0x58], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 004985d6  8b8680000000           -mov eax, dword ptr [esi + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 004985dc  89415c                 -mov dword ptr [ecx + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 004985df  8a4678                 -mov al, byte ptr [esi + 0x78]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 004985e2  88413c                 -mov byte ptr [ecx + 0x3c], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.al;
    // 004985e5  8a8684000000           -mov al, byte ptr [esi + 0x84]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004985eb  88413d                 -mov byte ptr [ecx + 0x3d], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(61) /* 0x3d */) = cpu.al;
    // 004985ee  668b8688000000         -mov ax, word ptr [esi + 0x88]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004985f5  66894140               -mov word ptr [ecx + 0x40], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.ax;
    // 004985f9  837e7c00               +cmp dword ptr [esi + 0x7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004985fd  0f8484010000           -je 0x498787
    if (cpu.flags.zf)
    {
        goto L_0x00498787;
    }
    // 00498603  e86846feff             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00498608  8b5e78                 -mov ebx, dword ptr [esi + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 0049860b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049860d  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049860f  88513e                 -mov byte ptr [ecx + 0x3e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = cpu.dl;
L_0x00498612:
    // 00498612  83be8c00000000         +cmp dword ptr [esi + 0x8c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498619  0f8471010000           -je 0x498790
    if (cpu.flags.zf)
    {
        goto L_0x00498790;
    }
    // 0049861f  e84c46feff             -call 0x47cc70
    cpu.esp -= 4;
    sub_47cc70(app, cpu);
    if (cpu.terminate) return;
    // 00498624  8b9e84000000           -mov ebx, dword ptr [esi + 0x84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 0049862a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049862c  f7f3                   -div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049862e  88513f                 -mov byte ptr [ecx + 0x3f], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = cpu.dl;
L_0x00498631:
    // 00498631  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00498633  e8283f0000             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
    // 00498638  8a466c                 -mov al, byte ptr [esi + 0x6c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 0049863b  88410b                 -mov byte ptr [ecx + 0xb], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = cpu.al;
    // 0049863e  8a464c                 -mov al, byte ptr [esi + 0x4c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 00498641  884138                 -mov byte ptr [ecx + 0x38], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(56) /* 0x38 */) = cpu.al;
    // 00498644  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498648  884139                 -mov byte ptr [ecx + 0x39], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(57) /* 0x39 */) = cpu.al;
    // 0049864b  8a4704                 -mov al, byte ptr [edi + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0049864e  88410a                 -mov byte ptr [ecx + 0xa], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = cpu.al;
    // 00498651  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 00498654  66894108               -mov word ptr [ecx + 8], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00498658  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049865a  e831080000             -call 0x498e90
    cpu.esp -= 4;
    sub_498e90(app, cpu);
    if (cpu.terminate) return;
    // 0049865f  807f0b00               +cmp byte ptr [edi + 0xb], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00498663  0f8430010000           -je 0x498799
    if (cpu.flags.zf)
    {
        goto L_0x00498799;
    }
    // 00498669  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0049866b:
    // 0049866b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049866c  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049866f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00498672  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498673  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498675  668b470c               -mov ax, word ptr [edi + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00498679  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049867a  8b4135                 -mov eax, dword ptr [ecx + 0x35]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(53) /* 0x35 */);
    // 0049867d  8b3df4835200           -mov edi, dword ptr [0x5283f4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5407732) /* 0x5283f4 */);
    // 00498683  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498686  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 00498689  8b5136                 -mov edx, dword ptr [ecx + 0x36]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(54) /* 0x36 */);
    // 0049868c  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0049868f  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00498692  bb013f0000             -mov ebx, 0x3f01
    cpu.ebx = 16129 /*0x3f01*/;
    // 00498697  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498699  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0049869c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0049869e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0049869f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004986a2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004986a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004986a6  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004986a9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004986ac  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004986b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004986b1  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004986b5  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 004986b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004986b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004986ba  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004986bc  8a4202                 -mov al, byte ptr [edx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004986bf  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004986c3  e83059feff             -call 0x47dff8
    cpu.esp -= 4;
    sub_47dff8(app, cpu);
    if (cpu.terminate) return;
    // 004986c8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004986ca  0f8cd3000000           -jl 0x4987a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004987a3;
    }
    // 004986d0  a1f02b5400             -mov eax, dword ptr [0x542bf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516272) /* 0x542bf0 */);
L_0x004986d5:
    // 004986d5  83c41c                 +add esp, 0x1c
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
    // 004986d8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986db  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004986de:
    // 004986de  c744240c7f000000       -mov dword ptr [esp + 0xc], 0x7f
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 127 /*0x7f*/;
    // 004986e6  e9dbfcffff             -jmp 0x4983c6
    goto L_0x004983c6;
L_0x004986eb:
    // 004986eb  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004986f0  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004986f3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986f4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004986f6  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004986f9:
    // 004986f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004986fb  7c09                   -jl 0x498706
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498706;
    }
    // 004986fd  83f87f                 +cmp eax, 0x7f
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
    // 00498700  0f8ed5fcffff           -jle 0x4983db
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004983db;
    }
L_0x00498706:
    // 00498706  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049870b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0049870e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049870f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498710  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498711  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00498714:
    // 00498714  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00498716  7c09                   -jl 0x498721
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498721;
    }
    // 00498718  83fd7f                 +cmp ebp, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049871b  0f8ecffcffff           -jle 0x4983f0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004983f0;
    }
L_0x00498721:
    // 00498721  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00498726  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00498729  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049872a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049872b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049872c  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0049872f:
    // 0049872f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498731  0f8dedfcffff           -jge 0x498424
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498424;
    }
    // 00498737  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00498739  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0049873d  e9e2fcffff             -jmp 0x498424
    goto L_0x00498424;
L_0x00498742:
    // 00498742  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00498744  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00498748  e917fdffff             -jmp 0x498464
    goto L_0x00498464;
L_0x0049874d:
    // 0049874d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049874f  7c09                   -jl 0x49875a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049875a;
    }
    // 00498751  83f97f                 +cmp ecx, 0x7f
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
    // 00498754  0f8e1ffdffff           -jle 0x498479
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498479;
    }
L_0x0049875a:
    // 0049875a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0049875f  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00498762  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498763  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498764  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498765  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00498768:
    // 00498768  83fa80                 +cmp edx, -0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-128 /*-0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049876b  0f8de1fdffff           -jge 0x498552
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498552;
    }
    // 00498771  ba80ffffff             -mov edx, 0xffffff80
    cpu.edx = 4294967168 /*0xffffff80*/;
    // 00498776  e9d7fdffff             -jmp 0x498552
    goto L_0x00498552;
L_0x0049877b:
    // 0049877b  c7412cffffff7f         -mov dword ptr [ecx + 0x2c], 0x7fffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = 2147483647 /*0x7fffffff*/;
    // 00498782  e92efeffff             -jmp 0x4985b5
    goto L_0x004985b5;
L_0x00498787:
    // 00498787  c6413e00               -mov byte ptr [ecx + 0x3e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */) = 0 /*0x0*/;
    // 0049878b  e982feffff             -jmp 0x498612
    goto L_0x00498612;
L_0x00498790:
    // 00498790  c6413f00               -mov byte ptr [ecx + 0x3f], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(63) /* 0x3f */) = 0 /*0x0*/;
    // 00498794  e998feffff             -jmp 0x498631
    goto L_0x00498631;
L_0x00498799:
    // 00498799  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0049879e  e9c8feffff             -jmp 0x49866b
    goto L_0x0049866b;
L_0x004987a3:
    // 004987a3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004987a5  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004987aa  e859c4ffff             -call 0x494c08
    cpu.esp -= 4;
    sub_494c08(app, cpu);
    if (cpu.terminate) return;
    // 004987af  8915f02b5400           -mov dword ptr [0x542bf0], edx
    app->getMemory<x86::reg32>(x86::reg32(5516272) /* 0x542bf0 */) = cpu.edx;
    // 004987b5  a1f02b5400             -mov eax, dword ptr [0x542bf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516272) /* 0x542bf0 */);
    // 004987ba  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004987bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004987be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004987bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004987c0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4987c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004987c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004987c5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004987c6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004987c7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004987c8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004987c9  81ec98010000           -sub esp, 0x198
    (cpu.esp) -= x86::reg32(x86::sreg32(408 /*0x198*/));
    // 004987cf  89842480010000         -mov dword ptr [esp + 0x180], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */) = cpu.eax;
    // 004987d6  8994247c010000         -mov dword ptr [esp + 0x17c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */) = cpu.edx;
    // 004987dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004987df  b9f7ffffff             -mov ecx, 0xfffffff7
    cpu.ecx = 4294967287 /*0xfffffff7*/;
    // 004987e4  89942488010000         -mov dword ptr [esp + 0x188], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.edx;
    // 004987eb  898c2470010000         -mov dword ptr [esp + 0x170], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.ecx;
    // 004987f2  8994248c010000         -mov dword ptr [esp + 0x18c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.edx;
    // 004987f9  89942490010000         -mov dword ptr [esp + 0x190], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.edx;
    // 00498800  89942474010000         -mov dword ptr [esp + 0x174], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */) = cpu.edx;
    // 00498807  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498809  0f84e8000000           -je 0x4988f7
    if (cpu.flags.zf)
    {
        goto L_0x004988f7;
    }
    // 0049880f  6681385054             +cmp word ptr [eax], 0x5450
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
    // 00498814  0f85ba000000           -jne 0x4988d4
    if (!cpu.flags.zf)
    {
        goto L_0x004988d4;
    }
    // 0049881a  8bac247c010000         -mov ebp, dword ptr [esp + 0x17c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 00498821  8bbc247c010000         -mov edi, dword ptr [esp + 0x17c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(380) /* 0x17c */);
    // 00498828  8b6d03                 -mov ebp, dword ptr [ebp + 3]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(3) /* 0x3 */);
    // 0049882b  8b7f02                 -mov edi, dword ptr [edi + 2]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0049882e  c1fd18                 -sar ebp, 0x18
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (24 /*0x18*/ % 32));
    // 00498831  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 00498834  83fdff                 +cmp ebp, -1
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
    // 00498837  0f859e000000           -jne 0x4988db
    if (!cpu.flags.zf)
    {
        goto L_0x004988db;
    }
    // 0049883d  bd7f000000             -mov ebp, 0x7f
    cpu.ebp = 127 /*0x7f*/;
L_0x00498842:
    // 00498842  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498845  0f859f000000           -jne 0x4988ea
    if (!cpu.flags.zf)
    {
        goto L_0x004988ea;
    }
    // 0049884b  bf3c000000             -mov edi, 0x3c
    cpu.edi = 60 /*0x3c*/;
L_0x00498850:
    // 00498850  8b842480010000         -mov eax, dword ptr [esp + 0x180]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(384) /* 0x180 */);
    // 00498857  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 0049885b  0f84a7000000           -je 0x498908
    if (cpu.flags.zf)
    {
        goto L_0x00498908;
    }
    // 00498861  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x00498864:
    // 00498864  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049886b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049886d  e81ef9ffff             -call 0x498190
    cpu.esp -= 4;
    sub_498190(app, cpu);
    if (cpu.terminate) return;
    // 00498872  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 00498879  e82af9ffff             -call 0x4981a8
    cpu.esp -= 4;
    sub_4981a8(app, cpu);
    if (cpu.terminate) return;
    // 0049887e  e86dc0ffff             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 00498883  e89cfaffff             -call 0x498324
    cpu.esp -= 4;
    sub_498324(app, cpu);
    if (cpu.terminate) return;
    // 00498888  89842478010000         -mov dword ptr [esp + 0x178], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(376) /* 0x178 */) = cpu.eax;
    // 0049888f  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 00498896  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00498899  89842494010000         -mov dword ptr [esp + 0x194], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.eax;
L_0x004988a0:
    // 004988a0  8b84248c010000         -mov eax, dword ptr [esp + 0x18c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 004988a7  40                     -inc eax
    (cpu.eax)++;
    // 004988a8  8a36                   -mov dh, byte ptr [esi]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi);
    // 004988aa  89842484010000         -mov dword ptr [esp + 0x184], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */) = cpu.eax;
    // 004988b1  80feff                 +cmp dh, 0xff
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004988b4  0f8489010000           -je 0x498a43
    if (cpu.flags.zf)
    {
        goto L_0x00498a43;
    }
    // 004988ba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004988bc  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 004988be  8d4601                 -lea eax, [esi + 1]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004988c1  81fbfd000000           +cmp ebx, 0xfd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004988c7  7547                   -jne 0x498910
    if (!cpu.flags.zf)
    {
        goto L_0x00498910;
    }
    // 004988c9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004988cb  89842488010000         -mov dword ptr [esp + 0x188], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */) = cpu.eax;
    // 004988d2  ebcc                   -jmp 0x4988a0
    goto L_0x004988a0;
L_0x004988d4:
    // 004988d4  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004988d9  eb21                   -jmp 0x4988fc
    goto L_0x004988fc;
L_0x004988db:
    // 004988db  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004988dd  7c18                   -jl 0x4988f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004988f7;
    }
    // 004988df  83fd7f                 +cmp ebp, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004988e2  0f8e5affffff           -jle 0x498842
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498842;
    }
    // 004988e8  eb0d                   -jmp 0x4988f7
    goto L_0x004988f7;
L_0x004988ea:
    // 004988ea  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004988ec  7c09                   -jl 0x4988f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004988f7;
    }
    // 004988ee  83ff7f                 +cmp edi, 0x7f
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
    // 004988f1  0f8e59ffffff           -jle 0x498850
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498850;
    }
L_0x004988f7:
    // 004988f7  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x004988fc:
    // 004988fc  81c498010000           +add esp, 0x198
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(408 /*0x198*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00498902  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498903  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498904  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498905  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498906  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498907  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498908:
    // 00498908  8d7004                 -lea esi, [eax + 4]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049890b  e954ffffff             -jmp 0x498864
    goto L_0x00498864;
L_0x00498910:
    // 00498910  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498916  0f85b1000000           -jne 0x4989cd
    if (!cpu.flags.zf)
    {
        goto L_0x004989cd;
    }
    // 0049891c  3bac249c000000         +cmp ebp, dword ptr [esp + 0x9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498923  7d14                   -jge 0x498939
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498939;
    }
L_0x00498925:
    // 00498925  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00498927  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0049892e  e875f8ffff             -call 0x4981a8
    cpu.esp -= 4;
    sub_4981a8(app, cpu);
    if (cpu.terminate) return;
    // 00498933  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00498934  e967ffffff             -jmp 0x4988a0
    goto L_0x004988a0;
L_0x00498939:
    // 00498939  3bac24a0000000         +cmp ebp, dword ptr [esp + 0xa0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498940  7fe3                   -jg 0x498925
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498925;
    }
    // 00498942  3bbc24a4000000         +cmp edi, dword ptr [esp + 0xa4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498949  7cda                   -jl 0x498925
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498925;
    }
    // 0049894b  3bbc24a8000000         +cmp edi, dword ptr [esp + 0xa8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498952  7fd1                   -jg 0x498925
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498925;
    }
    // 00498954  8b942474010000         -mov edx, dword ptr [esp + 0x174]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 0049895b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049895c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049895d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498961  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498962  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00498969  8b9c2488010000         -mov ebx, dword ptr [esp + 0x188]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 00498970  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498971  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 00498978  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 0049897f  e8e0f9ffff             -call 0x498364
    cpu.esp -= 4;
    sub_498364(app, cpu);
    if (cpu.terminate) return;
    // 00498984  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 0049898b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049898d  0f8c3a010000           -jl 0x498acd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498acd;
    }
    // 00498993  8b942494010000         -mov edx, dword ptr [esp + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 0049899a  8d4a04                 -lea ecx, [edx + 4]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0049899d  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 004989a4  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 004989ab  898c2494010000         -mov dword ptr [esp + 0x194], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */) = cpu.ecx;
    // 004989b2  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
    // 004989b9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004989bb  8d842498000000         -lea eax, [esp + 0x98]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004989c2  e8e1f7ffff             -call 0x4981a8
    cpu.esp -= 4;
    sub_4981a8(app, cpu);
    if (cpu.terminate) return;
    // 004989c7  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004989c8  e9d3feffff             -jmp 0x4988a0
    goto L_0x004988a0;
L_0x004989cd:
    // 004989cd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004989cf  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004989d5  0f84c5feffff           -je 0x4988a0
    if (cpu.flags.zf)
    {
        goto L_0x004988a0;
    }
    // 004989db  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004989dd  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 004989df  81f9ff000000           +cmp ecx, 0xff
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
    // 004989e5  7514                   -jne 0x4989fb
    if (!cpu.flags.zf)
    {
        goto L_0x004989fb;
    }
    // 004989e7  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004989ea  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004989ef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004989f1  e83af7ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 004989f6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004989f8  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004989fb:
    // 004989fb  46                     -inc esi
    (cpu.esi)++;
    // 004989fc  83fb26                 +cmp ebx, 0x26
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(38 /*0x26*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004989ff  7c07                   -jl 0x498a08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498a08;
    }
L_0x00498a01:
    // 00498a01  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00498a03  e998feffff             -jmp 0x4988a0
    goto L_0x004988a0;
L_0x00498a08:
    // 00498a08  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00498a0a  7cf5                   -jl 0x498a01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498a01;
    }
    // 00498a0c  83f904                 +cmp ecx, 4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498a0f  7ff0                   -jg 0x498a01
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498a01;
    }
    // 00498a11  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00498a13  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00498a15  e816f7ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 00498a1a  89849c98000000         -mov dword ptr [esp + ebx*4 + 0x98], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */ + cpu.ebx * 4) = cpu.eax;
    // 00498a21  89349c                 -mov dword ptr [esp + ebx*4], esi
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 4) = cpu.esi;
    // 00498a24  83fb24                 +cmp ebx, 0x24
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498a27  75d8                   -jne 0x498a01
    if (!cpu.flags.zf)
    {
        goto L_0x00498a01;
    }
    // 00498a29  8b842428010000         -mov eax, dword ptr [esp + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 00498a30  e8abc10000             -call 0x4a4be0
    cpu.esp -= 4;
    sub_4a4be0(app, cpu);
    if (cpu.terminate) return;
    // 00498a35  89842474010000         -mov dword ptr [esp + 0x174], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */) = cpu.eax;
    // 00498a3c  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00498a3e  e95dfeffff             -jmp 0x4988a0
    goto L_0x004988a0;
L_0x00498a43:
    // 00498a43  3bac249c000000         +cmp ebp, dword ptr [esp + 0x9c]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498a4a  0f8c72000000           -jl 0x498ac2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498ac2;
    }
    // 00498a50  3bac24a0000000         +cmp ebp, dword ptr [esp + 0xa0]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498a57  7f69                   -jg 0x498ac2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498ac2;
    }
    // 00498a59  3bbc24a4000000         +cmp edi, dword ptr [esp + 0xa4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498a60  7c60                   -jl 0x498ac2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498ac2;
    }
    // 00498a62  3bbc24a8000000         +cmp edi, dword ptr [esp + 0xa8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498a69  7f57                   -jg 0x498ac2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498ac2;
    }
    // 00498a6b  8bb42474010000         -mov esi, dword ptr [esp + 0x174]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(372) /* 0x174 */);
    // 00498a72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498a73  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498a74  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498a78  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498a79  8d8c24a4000000         -lea ecx, [esp + 0xa4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00498a80  8b9c2488010000         -mov ebx, dword ptr [esp + 0x188]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(392) /* 0x188 */);
    // 00498a87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498a88  8b942498010000         -mov edx, dword ptr [esp + 0x198]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(408) /* 0x198 */);
    // 00498a8f  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 00498a96  e8c9f8ffff             -call 0x498364
    cpu.esp -= 4;
    sub_498364(app, cpu);
    if (cpu.terminate) return;
    // 00498a9b  89842470010000         -mov dword ptr [esp + 0x170], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */) = cpu.eax;
    // 00498aa2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498aa4  7c27                   -jl 0x498acd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498acd;
    }
    // 00498aa6  8b942494010000         -mov edx, dword ptr [esp + 0x194]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(404) /* 0x194 */);
    // 00498aad  89841430010000         -mov dword ptr [esp + edx + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.edx * 1) = cpu.eax;
    // 00498ab4  8b842484010000         -mov eax, dword ptr [esp + 0x184]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(388) /* 0x184 */);
    // 00498abb  8984248c010000         -mov dword ptr [esp + 0x18c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */) = cpu.eax;
L_0x00498ac2:
    // 00498ac2  8bbc248c010000         -mov edi, dword ptr [esp + 0x18c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 00498ac9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498acb  7542                   -jne 0x498b0f
    if (!cpu.flags.zf)
    {
        goto L_0x00498b0f;
    }
L_0x00498acd:
    // 00498acd  8b9c248c010000         -mov ebx, dword ptr [esp + 0x18c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */);
    // 00498ad4  e82bbeffff             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00498ad9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498adb  7e1f                   -jle 0x498afc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498afc;
    }
    // 00498add  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 00498ae4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00498ae6:
    // 00498ae6  8b840c30010000         -mov eax, dword ptr [esp + ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.ecx * 1);
    // 00498aed  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498af0  e80b5efeff             -call 0x47e900
    cpu.esp -= 4;
    sub_47e900(app, cpu);
    if (cpu.terminate) return;
    // 00498af5  39d1                   +cmp ecx, edx
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
    // 00498af7  7ced                   -jl 0x498ae6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498ae6;
    }
    // 00498af9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00498afc:
    // 00498afc  8b842470010000         -mov eax, dword ptr [esp + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00498b03  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 00498b09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b0c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498b0f:
    // 00498b0f  83ff01                 +cmp edi, 1
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
    // 00498b12  753f                   -jne 0x498b53
    if (!cpu.flags.zf)
    {
        goto L_0x00498b53;
    }
    // 00498b14  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 00498b1b  e8dcc1ffff             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 00498b20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498b22  7c17                   -jl 0x498b3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498b3b;
    }
    // 00498b24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00498b26  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00498b29  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00498b2b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00498b2e  0500845200             -add eax, 0x528400
    (cpu.eax) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 00498b33  c6403b00               -mov byte ptr [eax + 0x3b], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(59) /* 0x3b */) = 0 /*0x0*/;
    // 00498b37  c6403a00               -mov byte ptr [eax + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
L_0x00498b3b:
    // 00498b3b  e8c4bdffff             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 00498b40  8b842470010000         -mov eax, dword ptr [esp + 0x170]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 00498b47  81c498010000           -add esp, 0x198
    (cpu.esp) += x86::reg32(x86::sreg32(408 /*0x198*/));
    // 00498b4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498b52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498b53:
    // 00498b53  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00498b55  7e3f                   -jle 0x498b96
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498b96;
    }
    // 00498b57  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 00498b5e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00498b60:
    // 00498b60  8b840c30010000         -mov eax, dword ptr [esp + ecx + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */ + cpu.ecx * 1);
    // 00498b67  e890c1ffff             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 00498b6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498b6e  7c1f                   -jl 0x498b8f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498b8f;
    }
    // 00498b70  6bc060                 -imul eax, eax, 0x60
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(96 /*0x60*/)));
    // 00498b73  bb00845200             -mov ebx, 0x528400
    cpu.ebx = 5407744 /*0x528400*/;
    // 00498b78  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00498b7a  8a842478010000         -mov al, byte ptr [esp + 0x178]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(376) /* 0x178 */);
    // 00498b81  c6433a00               -mov byte ptr [ebx + 0x3a], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(58) /* 0x3a */) = 0 /*0x0*/;
    // 00498b85  899c2490010000         -mov dword ptr [esp + 0x190], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */) = cpu.ebx;
    // 00498b8c  88433b                 -mov byte ptr [ebx + 0x3b], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(59) /* 0x3b */) = cpu.al;
L_0x00498b8f:
    // 00498b8f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498b92  39d1                   +cmp ecx, edx
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
    // 00498b94  7cca                   -jl 0x498b60
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498b60;
    }
L_0x00498b96:
    // 00498b96  8b842490010000         -mov eax, dword ptr [esp + 0x190]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(400) /* 0x190 */);
    // 00498b9d  c6403a01               -mov byte ptr [eax + 0x3a], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(58) /* 0x3a */) = 1 /*0x1*/;
    // 00498ba1  eb98                   -jmp 0x498b3b
    goto L_0x00498b3b;
}

/* align: skip 0x90 */
void Application::sub_498ba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498ba4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498ba5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498ba6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498ba9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00498bac  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00498bae  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00498bb0  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00498bb3  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00498bb8  6681fa5054             +cmp dx, 0x5450
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21584 /*0x5450*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00498bbd  7552                   -jne 0x498c11
    if (!cpu.flags.zf)
    {
        goto L_0x00498c11;
    }
    // 00498bbf  8a5003                 -mov dl, byte ptr [eax + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */);
    // 00498bc2  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00498bc5  7555                   -jne 0x498c1c
    if (!cpu.flags.zf)
    {
        goto L_0x00498c1c;
    }
    // 00498bc7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498bc8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498bc9  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00498bcc  7452                   -je 0x498c20
    if (cpu.flags.zf)
    {
        goto L_0x00498c20;
    }
    // 00498bce  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x00498bd1:
    // 00498bd1  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00498bd3  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00498bd5  7460                   -je 0x498c37
    if (cpu.flags.zf)
    {
        goto L_0x00498c37;
    }
    // 00498bd7  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 00498bda  81fefd000000           +cmp esi, 0xfd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498be0  750e                   -jne 0x498bf0
    if (!cpu.flags.zf)
    {
        goto L_0x00498bf0;
    }
    // 00498be2  41                     -inc ecx
    (cpu.ecx)++;
    // 00498be3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00498be5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00498be7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00498be9  e88257feff             -call 0x47e370
    cpu.esp -= 4;
    sub_47e370(app, cpu);
    if (cpu.terminate) return;
    // 00498bee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00498bf0:
    // 00498bf0  41                     -inc ecx
    (cpu.ecx)++;
    // 00498bf1  81fefe000000           +cmp esi, 0xfe
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498bf7  74d8                   -je 0x498bd1
    if (cpu.flags.zf)
    {
        goto L_0x00498bd1;
    }
    // 00498bf9  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498bff  74d0                   -je 0x498bd1
    if (cpu.flags.zf)
    {
        goto L_0x00498bd1;
    }
    // 00498c01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498c03  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00498c05  3dff000000             +cmp eax, 0xff
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
    // 00498c0a  7419                   -je 0x498c25
    if (cpu.flags.zf)
    {
        goto L_0x00498c25;
    }
L_0x00498c0c:
    // 00498c0c  41                     -inc ecx
    (cpu.ecx)++;
    // 00498c0d  01c1                   +add ecx, eax
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
    // 00498c0f  ebc0                   -jmp 0x498bd1
    goto L_0x00498bd1;
L_0x00498c11:
    // 00498c11  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
L_0x00498c16:
    // 00498c16  83c404                 +add esp, 4
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
    // 00498c19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c1a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c1b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498c1c:
    // 00498c1c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498c1e  ebf6                   -jmp 0x498c16
    goto L_0x00498c16;
L_0x00498c20:
    // 00498c20  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00498c23  ebac                   -jmp 0x498bd1
    goto L_0x00498bd1;
L_0x00498c25:
    // 00498c25  41                     -inc ecx
    (cpu.ecx)++;
    // 00498c26  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00498c2b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00498c2d  e8fef4ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 00498c32  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00498c35  ebd5                   -jmp 0x498c0c
    goto L_0x00498c0c;
L_0x00498c37:
    // 00498c37  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498c39  7c08                   -jl 0x498c43
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498c43;
    }
    // 00498c3b  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00498c3f  80480301               -or byte ptr [eax + 3], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00498c43:
    // 00498c43  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498c45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c47  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498c4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498c4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_498c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498c50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498c51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498c52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498c53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498c54  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00498c56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00498c58  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 00498c5c  7437                   -je 0x498c95
    if (cpu.flags.zf)
    {
        goto L_0x00498c95;
    }
    // 00498c5e  8d4f08                 -lea ecx, [edi + 8]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
L_0x00498c61:
    // 00498c61  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 00498c63  80faff                 +cmp dl, 0xff
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00498c66  7450                   -je 0x498cb8
    if (cpu.flags.zf)
    {
        goto L_0x00498cb8;
    }
    // 00498c68  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00498c6a  88d3                   -mov bl, dl
    cpu.bl = cpu.dl;
    // 00498c6c  81fbfd000000           +cmp ebx, 0xfd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498c72  7426                   -je 0x498c9a
    if (cpu.flags.zf)
    {
        goto L_0x00498c9a;
    }
L_0x00498c74:
    // 00498c74  41                     -inc ecx
    (cpu.ecx)++;
    // 00498c75  81fbfe000000           +cmp ebx, 0xfe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(254 /*0xfe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498c7b  74e4                   -je 0x498c61
    if (cpu.flags.zf)
    {
        goto L_0x00498c61;
    }
    // 00498c7d  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498c83  74dc                   -je 0x498c61
    if (cpu.flags.zf)
    {
        goto L_0x00498c61;
    }
    // 00498c85  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498c87  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00498c89  3dff000000             +cmp eax, 0xff
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
    // 00498c8e  7416                   -je 0x498ca6
    if (cpu.flags.zf)
    {
        goto L_0x00498ca6;
    }
L_0x00498c90:
    // 00498c90  41                     -inc ecx
    (cpu.ecx)++;
    // 00498c91  01c1                   +add ecx, eax
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
    // 00498c93  ebcc                   -jmp 0x498c61
    goto L_0x00498c61;
L_0x00498c95:
    // 00498c95  8d4f04                 -lea ecx, [edi + 4]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00498c98  ebc7                   -jmp 0x498c61
    goto L_0x00498c61;
L_0x00498c9a:
    // 00498c9a  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00498c9b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00498c9d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00498c9f  e84c4ffeff             -call 0x47dbf0
    cpu.esp -= 4;
    sub_47dbf0(app, cpu);
    if (cpu.terminate) return;
    // 00498ca4  ebce                   -jmp 0x498c74
    goto L_0x00498c74;
L_0x00498ca6:
    // 00498ca6  41                     -inc ecx
    (cpu.ecx)++;
    // 00498ca7  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00498cac  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00498cae  e87df4ffff             -call 0x498130
    cpu.esp -= 4;
    sub_498130(app, cpu);
    if (cpu.terminate) return;
    // 00498cb3  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00498cb6  ebd8                   -jmp 0x498c90
    goto L_0x00498c90;
L_0x00498cb8:
    // 00498cb8  8a7703                 -mov dh, byte ptr [edi + 3]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 00498cbb  80e6fe                 -and dh, 0xfe
    cpu.dh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00498cbe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498cc0  887703                 -mov byte ptr [edi + 3], dh
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.dh;
    // 00498cc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498cc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498cc5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498cc6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498cc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498cd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498cd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498cd2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00498cd4  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00498cd6  e835fe0000             -call 0x4a8b10
    cpu.esp -= 4;
    sub_4a8b10(app, cpu);
    if (cpu.terminate) return;
    // 00498cdb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00498cdd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498cdf  7c09                   -jl 0x498cea
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498cea;
    }
    // 00498ce1  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00498ce3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498ce5  7c11                   -jl 0x498cf8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498cf8;
    }
    // 00498ce7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ce8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ce9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498cea:
    // 00498cea  6bc2ff                 -imul eax, edx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00498ced  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00498cef  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 00498cf1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498cf3  7c03                   -jl 0x498cf8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498cf8;
    }
    // 00498cf5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498cf6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498cf7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498cf8:
    // 00498cf8  6bc3ff                 -imul eax, ebx, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00498cfb  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00498cfd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498cfe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498cff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498d00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498d01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498d02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498d03  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498d06  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498d0a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00498d0d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00498d0f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00498d11  e8fafd0000             -call 0x4a8b10
    cpu.esp -= 4;
    sub_4a8b10(app, cpu);
    if (cpu.terminate) return;
    // 00498d16  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498d1a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498d1c  0f8c93000000           -jl 0x498db5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498db5;
    }
L_0x00498d22:
    // 00498d22  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498d26  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00498d28  0f8ca1000000           -jl 0x498dcf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498dcf;
    }
    // 00498d2e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00498d30  0f8c99000000           -jl 0x498dcf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498dcf;
    }
    // 00498d36  39cd                   +cmp ebp, ecx
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
    // 00498d38  0f8e87000000           -jle 0x498dc5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498dc5;
    }
L_0x00498d3e:
    // 00498d3e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00498d43:
    // 00498d43  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00498d46  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00498d48  81f900400000           +cmp ecx, 0x4000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498d4e  0f8cc5000000           -jl 0x498e19
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498e19;
    }
    // 00498d54  81f900c00000           +cmp ecx, 0xc000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00498d5a  0f8db9000000           -jge 0x498e19
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498e19;
    }
    // 00498d60  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00498d62  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 00498d64  0f8da5000000           -jge 0x498e0f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498e0f;
    }
    // 00498d6a  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
L_0x00498d6f:
    // 00498d6f  83f802                 +cmp eax, 2
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
    // 00498d72  7f13                   -jg 0x498d87
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498d87;
    }
    // 00498d74  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00498d79  83f903                 +cmp ecx, 3
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
    // 00498d7c  7509                   -jne 0x498d87
    if (!cpu.flags.zf)
    {
        goto L_0x00498d87;
    }
    // 00498d7e  39d0                   +cmp eax, edx
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
L_0x00498d80:
    // 00498d80  7505                   -jne 0x498d87
    if (!cpu.flags.zf)
    {
        goto L_0x00498d87;
    }
    // 00498d82  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00498d87:
    // 00498d87  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 00498d8c  0f8cb7000000           -jl 0x498e49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498e49;
    }
L_0x00498d92:
    // 00498d92  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00498d94  0f8cbb000000           -jl 0x498e55
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498e55;
    }
L_0x00498d9a:
    // 00498d9a  83fa01                 +cmp edx, 1
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
    // 00498d9d  0f84be000000           -je 0x498e61
    if (cpu.flags.zf)
    {
        goto L_0x00498e61;
    }
    // 00498da3  83fa02                 +cmp edx, 2
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
    // 00498da6  0f84c5000000           -je 0x498e71
    if (cpu.flags.zf)
    {
        goto L_0x00498e71;
    }
    // 00498dac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498daf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498db0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498db1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498db2  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00498db5:
    // 00498db5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00498db7  0f8d65ffffff           -jge 0x498d22
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498d22;
    }
    // 00498dbd  39d5                   +cmp ebp, edx
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
    // 00498dbf  0f8e79ffffff           -jle 0x498d3e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498d3e;
    }
L_0x00498dc5:
    // 00498dc5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00498dca  e974ffffff             -jmp 0x498d43
    goto L_0x00498d43;
L_0x00498dcf:
    // 00498dcf  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498dd3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498dd5  7e16                   -jle 0x498ded
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498ded;
    }
    // 00498dd7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00498dd9:
    // 00498dd9  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00498ddb  7e16                   -jle 0x498df3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498df3;
    }
    // 00498ddd  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00498ddf  39d0                   +cmp eax, edx
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
    // 00498de1  7e22                   -jle 0x498e05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498e05;
    }
    // 00498de3  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00498de8  e956ffffff             -jmp 0x498d43
    goto L_0x00498d43;
L_0x00498ded:
    // 00498ded  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00498def  f7d8                   +neg eax
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
    // 00498df1  ebe6                   -jmp 0x498dd9
    goto L_0x00498dd9;
L_0x00498df3:
    // 00498df3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00498df5  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00498df7  39d0                   +cmp eax, edx
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
    // 00498df9  7e0a                   -jle 0x498e05
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00498e05;
    }
    // 00498dfb  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00498e00  e93effffff             -jmp 0x498d43
    goto L_0x00498d43;
L_0x00498e05:
    // 00498e05  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00498e0a  e934ffffff             -jmp 0x498d43
    goto L_0x00498d43;
L_0x00498e0f:
    // 00498e0f  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00498e14  e956ffffff             -jmp 0x498d6f
    goto L_0x00498d6f;
L_0x00498e19:
    // 00498e19  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00498e1b  3b0e                   +cmp ecx, dword ptr [esi]
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
    // 00498e1d  7d23                   -jge 0x498e42
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00498e42;
    }
    // 00498e1f  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
L_0x00498e24:
    // 00498e24  83f803                 +cmp eax, 3
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
    // 00498e27  0f8c5affffff           -jl 0x498d87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498d87;
    }
    // 00498e2d  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00498e32  39d1                   +cmp ecx, edx
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
    // 00498e34  0f854dffffff           -jne 0x498d87
    if (!cpu.flags.zf)
    {
        goto L_0x00498d87;
    }
    // 00498e3a  83f803                 +cmp eax, 3
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
    // 00498e3d  e93effffff             -jmp 0x498d80
    goto L_0x00498d80;
L_0x00498e42:
    // 00498e42  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00498e47  ebdb                   -jmp 0x498e24
    goto L_0x00498e24;
L_0x00498e49:
    // 00498e49  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 00498e4b  6bc1ff                 +imul eax, ecx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 00498e4e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00498e50  e93dffffff             -jmp 0x498d92
    goto L_0x00498d92;
L_0x00498e55:
    // 00498e55  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi);
    // 00498e57  6bc3ff                 +imul eax, ebx, -1
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 00498e5a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00498e5c  e939ffffff             -jmp 0x498d9a
    goto L_0x00498d9a;
L_0x00498e61:
    // 00498e61  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 00498e63  6bc5ff                 -imul eax, ebp, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00498e66  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00498e68  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498e6b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e6c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e6d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e6e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00498e71:
    // 00498e71  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 00498e73  6bc7ff                 -imul eax, edi, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 00498e76  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00498e78  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498e7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498e7e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_498e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498e92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498e93  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00498e9a  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00498e9c  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 00498e9f  81c100845200           -add ecx, 0x528400
    (cpu.ecx) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 00498ea5  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00498ea8  8b512d                 -mov edx, dword ptr [ecx + 0x2d]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(45) /* 0x2d */);
    // 00498eab  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00498eae  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00498eb1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00498eb4  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00498eb7  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00498eba  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00498ebd  8b155a8a5200           -mov edx, dword ptr [0x528a5a]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5409370) /* 0x528a5a */);
    // 00498ec3  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 00498ec6  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00498ec9  bb7f411f00             -mov ebx, 0x1f417f
    cpu.ebx = 2048383 /*0x1f417f*/;
    // 00498ece  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498ed0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00498ed3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00498ed5  8b5158                 -mov edx, dword ptr [ecx + 0x58]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 00498ed8  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 00498edb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00498edd  750b                   -jne 0x498eea
    if (!cpu.flags.zf)
    {
        goto L_0x00498eea;
    }
    // 00498edf  8b594c                 -mov ebx, dword ptr [ecx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 00498ee2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498ee4  7533                   -jne 0x498f19
    if (!cpu.flags.zf)
    {
        goto L_0x00498f19;
    }
    // 00498ee6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ee7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ee8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498ee9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498eea:
    // 00498eea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00498eec  8b4158                 -mov eax, dword ptr [ecx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    // 00498eef  8a513e                 -mov dl, byte ptr [ecx + 0x3e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(62) /* 0x3e */);
    // 00498ef2  0fbe1402               -movsx edx, byte ptr [edx + eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1)));
    // 00498ef6  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 00498ef9  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498efc  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00498eff  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
    // 00498f04  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00498f06  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00498f09  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00498f0b  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 00498f0e  8b594c                 -mov ebx, dword ptr [ecx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 00498f11  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00498f13  7504                   -jne 0x498f19
    if (!cpu.flags.zf)
    {
        goto L_0x00498f19;
    }
    // 00498f15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00498f19:
    // 00498f19  8b412e                 -mov eax, dword ptr [ecx + 0x2e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 00498f1c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00498f1e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 00498f21  8a0402                 -mov al, byte ptr [edx + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1);
    // 00498f24  884131                 -mov byte ptr [ecx + 0x31], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(49) /* 0x31 */) = cpu.al;
    // 00498f27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498f2b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498f2b  83f841                 +cmp eax, 0x41
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
    // 00498f2e  7c08                   -jl 0x498f38
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00498f38;
    }
    // 00498f30  83f85a                 +cmp eax, 0x5a
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
    // 00498f33  7f03                   -jg 0x498f38
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00498f38;
    }
    // 00498f35  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00498f38:
    // 00498f38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498f39(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498f39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498f3a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498f3b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498f3f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498f42  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00498f45  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00498f46  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00498f48  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498f4c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498f4d  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498f51  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498f52  e806000000             -call 0x498f5d
    cpu.esp -= 4;
    sub_498f5d(app, cpu);
    if (cpu.terminate) return;
    // 00498f57  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00498f5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f5b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498f5d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498f5d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00498f5e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00498f5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00498f60  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498f63  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00498f67  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00498f69  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00498f6d  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498f71  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00498f74  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498f78  e807000000             -call 0x498f84
    cpu.esp -= 4;
    sub_498f84(app, cpu);
    if (cpu.terminate) return;
    // 00498f7d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00498f80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00498f83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_498f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00498f84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00498f85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00498f86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00498f87  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00498f8a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00498f8c  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00498f90  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00498f94  e8d7fc0000             -call 0x4a8c70
    cpu.esp -= 4;
    sub_4a8c70(app, cpu);
    if (cpu.terminate) return;
    // 00498f99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00498f9b  7414                   -je 0x498fb1
    if (cpu.flags.zf)
    {
        goto L_0x00498fb1;
    }
    // 00498f9d  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
L_0x00498fa2:
    // 00498fa2  e899ccffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 00498fa7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00498fac  e9d5010000             -jmp 0x499186
    goto L_0x00499186;
L_0x00498fb1:
    // 00498fb1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00498fb3  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00498fb7  83e607                 -and esi, 7
    cpu.esi &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00498fba  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00498fbe  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00498fc0  e8effe0000             -call 0x4a8eb4
    cpu.esp -= 4;
    sub_4a8eb4(app, cpu);
    if (cpu.terminate) return;
    // 00498fc5  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00498fc9  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00498fcd  09f0                   -or eax, esi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.esi));
    // 00498fcf  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 00498fd4  e807ff0000             -call 0x4a8ee0
    cpu.esp -= 4;
    sub_4a8ee0(app, cpu);
    if (cpu.terminate) return;
    // 00498fd9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00498fdb  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00498fe0  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00498fe4  8a64241c               -mov ah, byte ptr [esp + 0x1c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00498fe8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00498feb  f6c480                 +test ah, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 128 /*0x80*/));
    // 00498fee  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00498ff1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00498ff6  8b1598c14c00           -mov edx, dword ptr [0x4cc198]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030296) /* 0x4cc198 */);
    // 00498ffc  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00499000  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499002  7435                   -je 0x499039
    if (cpu.flags.zf)
    {
        goto L_0x00499039;
    }
    // 00499004  bad8f24b00             -mov edx, 0x4bf2d8
    cpu.edx = 4977368 /*0x4bf2d8*/;
    // 00499009  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049900b  e81319ffff             -call 0x48a923
    cpu.esp -= 4;
    sub_48a923(app, cpu);
    if (cpu.terminate) return;
    // 00499010  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499012  7525                   -jne 0x499039
    if (!cpu.flags.zf)
    {
        goto L_0x00499039;
    }
    // 00499014  e845fe0000             -call 0x4a8e5e
    cpu.esp -= 4;
    sub_4a8e5e(app, cpu);
    if (cpu.terminate) return;
    // 00499019  ff1550c14c00           -call dword ptr [0x4cc150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030224) /* 0x4cc150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049901f  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00499021  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499022  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00499024  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00499029  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049902b  ff1598c14c00           -call dword ptr [0x4cc198]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030296) /* 0x4cc198 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499031  83c40c                 +add esp, 0xc
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
    // 00499034  e9fd000000             -jmp 0x499136
    goto L_0x00499136;
L_0x00499039:
    // 00499039  8a54241c               -mov dl, byte ptr [esp + 0x1c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049903d  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00499040  7462                   -je 0x4990a4
    if (cpu.flags.zf)
    {
        goto L_0x004990a4;
    }
    // 00499042  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 00499044  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499047  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 00499049  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0049904c  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00499050  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 00499056  a104d64c00             -mov eax, dword ptr [0x4cd604]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5035524) /* 0x4cd604 */);
    // 0049905b  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0049905f  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00499061  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 00499063  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00499067  f644241501             +test byte ptr [esp + 0x15], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) & 1 /*0x1*/));
    // 0049906c  740c                   -je 0x49907a
    if (cpu.flags.zf)
    {
        goto L_0x0049907a;
    }
    // 0049906e  f644241480             +test byte ptr [esp + 0x14], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) & 128 /*0x80*/));
    // 00499073  7505                   -jne 0x49907a
    if (!cpu.flags.zf)
    {
        goto L_0x0049907a;
    }
    // 00499075  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0049907a:
    // 0049907a  f644241d04             +test byte ptr [esp + 0x1d], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */) & 4 /*0x4*/));
    // 0049907f  7409                   -je 0x49908a
    if (cpu.flags.zf)
    {
        goto L_0x0049908a;
    }
    // 00499081  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00499086  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00499088  eb24                   -jmp 0x4990ae
    goto L_0x004990ae;
L_0x0049908a:
    // 0049908a  f644241c40             +test byte ptr [esp + 0x1c], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 64 /*0x40*/));
    // 0049908f  740c                   -je 0x49909d
    if (cpu.flags.zf)
    {
        goto L_0x0049909d;
    }
    // 00499091  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
L_0x00499096:
    // 00499096  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0049909b  eb11                   -jmp 0x4990ae
    goto L_0x004990ae;
L_0x0049909d:
    // 0049909d  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 004990a2  eb05                   -jmp 0x4990a9
    goto L_0x004990a9;
L_0x004990a4:
    // 004990a4  f6c240                 +test dl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 64 /*0x40*/));
    // 004990a7  75ed                   -jne 0x499096
    if (!cpu.flags.zf)
    {
        goto L_0x00499096;
    }
L_0x004990a9:
    // 004990a9  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_0x004990ae:
    // 004990ae  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004990b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004990b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004990b2  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004990b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004990b7  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004990bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004990bc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004990c0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004990c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004990c2  2eff152c544b00         -call dword ptr cs:[0x4b542c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936748) /* 0x4b542c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004990c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004990cb  83f8ff                 +cmp eax, -1
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
    // 004990ce  7530                   -jne 0x499100
    if (!cpu.flags.zf)
    {
        goto L_0x00499100;
    }
    // 004990d0  f644241c20             +test byte ptr [esp + 0x1c], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 32 /*0x20*/));
    // 004990d5  741a                   -je 0x4990f1
    if (cpu.flags.zf)
    {
        goto L_0x004990f1;
    }
    // 004990d7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004990d9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004990da  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004990db  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004990dd  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004990e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004990e2  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004990e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004990e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004990e8  2eff152c544b00         -call dword ptr cs:[0x4b542c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936748) /* 0x4b542c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004990ef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004990f1:
    // 004990f1  83f9ff                 +cmp ecx, -1
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
    // 004990f4  750a                   -jne 0x499100
    if (!cpu.flags.zf)
    {
        goto L_0x00499100;
    }
    // 004990f6  e847caffff             -call 0x495b42
    cpu.esp -= 4;
    sub_495b42(app, cpu);
    if (cpu.terminate) return;
    // 004990fb  e986000000             -jmp 0x499186
    goto L_0x00499186;
L_0x00499100:
    // 00499100  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499102  ff1550c14c00           -call dword ptr [0x4cc150]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030224) /* 0x4cc150 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499108  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049910a  8b2d08d64c00           -mov ebp, dword ptr [0x4cd608]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5035528) /* 0x4cd608 */);
    // 00499110  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00499112  39e8                   +cmp eax, ebp
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
    // 00499114  7212                   -jb 0x499128
    if (cpu.flags.cf)
    {
        goto L_0x00499128;
    }
    // 00499116  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499117  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049911e  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00499123  e97afeffff             -jmp 0x498fa2
    goto L_0x00498fa2;
L_0x00499128:
    // 00499128  e881fe0000             -call 0x4a8fae
    cpu.esp -= 4;
    sub_4a8fae(app, cpu);
    if (cpu.terminate) return;
    // 0049912d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049912f  7405                   -je 0x499136
    if (cpu.flags.zf)
    {
        goto L_0x00499136;
    }
    // 00499131  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x00499136:
    // 00499136  83fe02                 +cmp esi, 2
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
    // 00499139  7505                   -jne 0x499140
    if (!cpu.flags.zf)
    {
        goto L_0x00499140;
    }
    // 0049913b  80ca03                 +or dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0049913e  eb11                   -jmp 0x499151
    goto L_0x00499151;
L_0x00499140:
    // 00499140  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499142  7505                   -jne 0x499149
    if (!cpu.flags.zf)
    {
        goto L_0x00499149;
    }
    // 00499144  80ca01                 +or dl, 1
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00499147  eb08                   -jmp 0x499151
    goto L_0x00499151;
L_0x00499149:
    // 00499149  83fe01                 +cmp esi, 1
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
    // 0049914c  7503                   -jne 0x499151
    if (!cpu.flags.zf)
    {
        goto L_0x00499151;
    }
    // 0049914e  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x00499151:
    // 00499151  f644241c10             +test byte ptr [esp + 0x1c], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) & 16 /*0x10*/));
    // 00499156  7403                   -je 0x49915b
    if (cpu.flags.zf)
    {
        goto L_0x0049915b;
    }
    // 00499158  80ca80                 -or dl, 0x80
    cpu.dl |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0049915b:
    // 0049915b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049915d  8a7c241d               -mov bh, byte ptr [esp + 0x1d]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(29) /* 0x1d */);
    // 00499161  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00499163  f6c703                 +test bh, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 3 /*0x3*/));
    // 00499166  7407                   -je 0x49916f
    if (cpu.flags.zf)
    {
        goto L_0x0049916f;
    }
    // 00499168  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 0049916b  7410                   -je 0x49917d
    if (cpu.flags.zf)
    {
        goto L_0x0049917d;
    }
    // 0049916d  eb0c                   -jmp 0x49917b
    goto L_0x0049917b;
L_0x0049916f:
    // 0049916f  813d39c14c0000020000   +cmp dword ptr [0x4cc139], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030201) /* 0x4cc139 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499179  7502                   -jne 0x49917d
    if (!cpu.flags.zf)
    {
        goto L_0x0049917d;
    }
L_0x0049917b:
    // 0049917b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0049917d:
    // 0049917d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049917f  e809fe0000             -call 0x4a8f8d
    cpu.esp -= 4;
    sub_4a8f8d(app, cpu);
    if (cpu.terminate) return;
    // 00499184  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00499186:
    // 00499186  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00499189  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049918a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049918b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049918c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49918d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049918d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049918e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049918f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499190  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499191  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499192  ff1558c14c00           -call dword ptr [0x4cc158]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030232) /* 0x4cc158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499198  8b35f82b5400           -mov esi, dword ptr [0x542bf8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5516280) /* 0x542bf8 */);
    // 0049919e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004991a0  7419                   -je 0x4991bb
    if (cpu.flags.zf)
    {
        goto L_0x004991bb;
    }
    // 004991a2  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004991a5  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004991a8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004991aa  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 004991b0  a3f82b5400             -mov dword ptr [0x542bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5516280) /* 0x542bf8 */) = cpu.eax;
    // 004991b5  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 004991b9  eb47                   -jmp 0x499202
    goto L_0x00499202;
L_0x004991bb:
    // 004991bb  b930bf4c00             -mov ecx, 0x4cbf30
    cpu.ecx = 5029680 /*0x4cbf30*/;
    // 004991c0  eb20                   -jmp 0x4991e2
    goto L_0x004991e2;
L_0x004991c2:
    // 004991c2  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 004991c6  7517                   -jne 0x4991df
    if (!cpu.flags.zf)
    {
        goto L_0x004991df;
    }
    // 004991c8  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004991cd  e881c9ffff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004991d2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004991d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004991d6  7458                   -je 0x499230
    if (cpu.flags.zf)
    {
        goto L_0x00499230;
    }
    // 004991d8  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 004991dd  eb23                   -jmp 0x499202
    goto L_0x00499202;
L_0x004991df:
    // 004991df  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
L_0x004991e2:
    // 004991e2  81f938c14c00           +cmp ecx, 0x4cc138
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5030200 /*0x4cc138*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004991e8  72d8                   -jb 0x4991c2
    if (cpu.flags.cf)
    {
        goto L_0x004991c2;
    }
    // 004991ea  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 004991ef  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 004991f4  e85ac9ffff             -call 0x495b53
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004991f9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004991fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004991fd  7431                   -je 0x499230
    if (cpu.flags.zf)
    {
        goto L_0x00499230;
    }
    // 004991ff  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x00499202:
    // 00499202  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 00499207  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499209  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0049920b  e8afaffeff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 00499210  89790c                 -mov dword ptr [ecx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00499213  894e04                 -mov dword ptr [esi + 4], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00499216  a1f42b5400             -mov eax, dword ptr [0x542bf4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
    // 0049921b  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049921e  8935f42b5400           -mov dword ptr [0x542bf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */) = cpu.esi;
    // 00499224  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00499226  ff155cc14c00           -call dword ptr [0x4cc15c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049922c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049922e  eb12                   -jmp 0x499242
    goto L_0x00499242;
L_0x00499230:
    // 00499230  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00499235  e806caffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0049923a  ff155cc14c00           -call dword ptr [0x4cc15c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499240  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00499242:
    // 00499242  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499243  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499244  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499245  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499246  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499247  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499248  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499249  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049924a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049924b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049924d  baf42b5400             -mov edx, 0x542bf4
    cpu.edx = 5516276 /*0x542bf4*/;
L_0x00499252:
    // 00499252  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00499254  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499256  7425                   -je 0x49927d
    if (cpu.flags.zf)
    {
        goto L_0x0049927d;
    }
    // 00499258  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049925b  39cb                   +cmp ebx, ecx
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
    // 0049925d  7404                   -je 0x499263
    if (cpu.flags.zf)
    {
        goto L_0x00499263;
    }
    // 0049925f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499261  ebef                   -jmp 0x499252
    goto L_0x00499252;
L_0x00499263:
    // 00499263  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00499266  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00499269  884b0c                 -mov byte ptr [ebx + 0xc], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 0049926c  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049926e  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00499270  8b15f82b5400           -mov edx, dword ptr [0x542bf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5516280) /* 0x542bf8 */);
    // 00499276  a3f82b5400             -mov dword ptr [0x542bf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5516280) /* 0x542bf8 */) = cpu.eax;
    // 0049927b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x0049927d:
    // 0049927d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049927e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049927f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499280  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499281(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499281  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
L_0x00499282:
    // 00499282  8b15f82b5400           -mov edx, dword ptr [0x542bf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5516280) /* 0x542bf8 */);
    // 00499288  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049928a  7411                   -je 0x49929d
    if (cpu.flags.zf)
    {
        goto L_0x0049929d;
    }
    // 0049928c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049928e  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499290  e8b4190000             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 00499295  8915f82b5400           -mov dword ptr [0x542bf8], edx
    app->getMemory<x86::reg32>(x86::reg32(5516280) /* 0x542bf8 */) = cpu.edx;
    // 0049929b  ebe5                   -jmp 0x499282
    goto L_0x00499282;
L_0x0049929d:
    // 0049929d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049929e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49929f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049929f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004992a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004992a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004992a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004992a3  3b4204                 +cmp eax, dword ptr [edx + 4]
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
    // 004992a6  7f2c                   -jg 0x4992d4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004992d4;
    }
    // 004992a8  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004992ab  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004992ad  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004992b0  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004992b2  39d8                   +cmp eax, ebx
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
    // 004992b4  7c1e                   -jl 0x4992d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004992d4;
    }
    // 004992b6  8a5a0c                 -mov bl, byte ptr [edx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004992b9  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004992bb  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004992be  80e3ef                 -and bl, 0xef
    cpu.bl &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004992c1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004992c3  885a0c                 -mov byte ptr [edx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 004992c6  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004992c8  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004992ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004992cc  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004992cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004992d4:
    // 004992d4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004992d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4992de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004992de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004992df  80600cef               -and byte ptr [eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004992e3  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004992e6  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004992e9  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004992f0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004992f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004992f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4992f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004992f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004992f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004992f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004992f7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004992f9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004992fb  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004992fe  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499304  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00499307  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 0049930a  7465                   -je 0x499371
    if (cpu.flags.zf)
    {
        goto L_0x00499371;
    }
    // 0049930c  f6410d10               +test byte ptr [ecx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00499310  741f                   -je 0x499331
    if (cpu.flags.zf)
    {
        goto L_0x00499331;
    }
    // 00499312  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499314  e8c7160000             -call 0x49a9e0
    cpu.esp -= 4;
    sub_49a9e0(app, cpu);
    if (cpu.terminate) return;
    // 00499319  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049931b  742b                   -je 0x499348
    if (cpu.flags.zf)
    {
        goto L_0x00499348;
    }
    // 0049931d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049931f  753e                   -jne 0x49935f
    if (!cpu.flags.zf)
    {
        goto L_0x0049935f;
    }
    // 00499321  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499323  7d3a                   -jge 0x49935f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049935f;
    }
L_0x00499325:
    // 00499325  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0049932a  e811c9ffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0049932f  eb2e                   -jmp 0x49935f
    goto L_0x0049935f;
L_0x00499331:
    // 00499331  83fb01                 +cmp ebx, 1
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
    // 00499334  7503                   -jne 0x499339
    if (!cpu.flags.zf)
    {
        goto L_0x00499339;
    }
    // 00499336  2b7104                 -sub esi, dword ptr [ecx + 4]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
L_0x00499339:
    // 00499339  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049933c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049933f  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00499346  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
L_0x00499348:
    // 00499348  80610ceb               -and byte ptr [ecx + 0xc], 0xeb
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(235 /*0xeb*/));
    // 0049934c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049934e  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
L_0x00499351:
    // 00499351  e8f2170000             -call 0x49ab48
    cpu.esp -= 4;
    sub_49ab48(app, cpu);
    if (cpu.terminate) return;
    // 00499356  83f8ff                 +cmp eax, -1
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
    // 00499359  0f8596000000           -jne 0x4993f5
    if (!cpu.flags.zf)
    {
        goto L_0x004993f5;
    }
L_0x0049935f:
    // 0049935f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499362  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499368  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049936d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049936e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049936f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499370  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499371:
    // 00499371  83fb01                 +cmp ebx, 1
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
    // 00499374  7209                   -jb 0x49937f
    if (cpu.flags.cf)
    {
        goto L_0x0049937f;
    }
    // 00499376  760d                   -jbe 0x499385
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499385;
    }
    // 00499378  83fb02                 +cmp ebx, 2
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
    // 0049937b  7457                   -je 0x4993d4
    if (cpu.flags.zf)
    {
        goto L_0x004993d4;
    }
    // 0049937d  eba6                   -jmp 0x499325
    goto L_0x00499325;
L_0x0049937f:
    // 0049937f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499381  742c                   -je 0x4993af
    if (cpu.flags.zf)
    {
        goto L_0x004993af;
    }
    // 00499383  eba0                   -jmp 0x499325
    goto L_0x00499325;
L_0x00499385:
    // 00499385  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499387  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499389  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0049938c  e80effffff             -call 0x49929f
    cpu.esp -= 4;
    sub_49929f(app, cpu);
    if (cpu.terminate) return;
    // 00499391  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499393  7460                   -je 0x4993f5
    if (cpu.flags.zf)
    {
        goto L_0x004993f5;
    }
    // 00499395  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499397  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049939a  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049939c:
    // 0049939c  e8a7170000             -call 0x49ab48
    cpu.esp -= 4;
    sub_49ab48(app, cpu);
    if (cpu.terminate) return;
    // 004993a1  83f8ff                 +cmp eax, -1
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
    // 004993a4  74b9                   -je 0x49935f
    if (cpu.flags.zf)
    {
        goto L_0x0049935f;
    }
    // 004993a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004993a8  e831ffffff             -call 0x4992de
    cpu.esp -= 4;
    sub_4992de(app, cpu);
    if (cpu.terminate) return;
    // 004993ad  eb46                   -jmp 0x4993f5
    goto L_0x004993f5;
L_0x004993af:
    // 004993af  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004993b2  e84dfc0000             -call 0x4a9004
    cpu.esp -= 4;
    sub_4a9004(app, cpu);
    if (cpu.terminate) return;
    // 004993b7  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004993ba  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004993bc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004993be  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004993c0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004993c2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004993c4  e8d6feffff             -call 0x49929f
    cpu.esp -= 4;
    sub_49929f(app, cpu);
    if (cpu.terminate) return;
    // 004993c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004993cb  7428                   -je 0x4993f5
    if (cpu.flags.zf)
    {
        goto L_0x004993f5;
    }
    // 004993cd  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004993cf  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004993d2  ebc8                   -jmp 0x49939c
    goto L_0x0049939c;
L_0x004993d4:
    // 004993d4  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004993d6  80e2ef                 +and dl, 0xef
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 004993d9  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004993dc  88510c                 -mov byte ptr [ecx + 0xc], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dl;
    // 004993df  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004993e2  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004993e4  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004993e6  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004993e9  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004993f0  e95cffffff             -jmp 0x499351
    goto L_0x00499351;
L_0x004993f5:
    // 004993f5  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004993f8  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004993fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499400  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499401  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499402  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499403  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499405  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499406  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499407  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499409  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 0049940d  7522                   -jne 0x499431
    if (!cpu.flags.zf)
    {
        goto L_0x00499431;
    }
    // 0049940f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499412  e897fb0000             -call 0x4a8fae
    cpu.esp -= 4;
    sub_4a8fae(app, cpu);
    if (cpu.terminate) return;
    // 00499417  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499419  7416                   -je 0x499431
    if (cpu.flags.zf)
    {
        goto L_0x00499431;
    }
    // 0049941b  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 0049941e  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00499421  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00499424  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 00499427  7508                   -jne 0x499431
    if (!cpu.flags.zf)
    {
        goto L_0x00499431;
    }
    // 00499429  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 0049942b  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0049942e  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x00499431:
    // 00499431  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499432  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499433  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499434  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499435(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499435  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049943b  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 00499440  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499441(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499441  a1002c5400             -mov eax, dword ptr [0x542c00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516288) /* 0x542c00 */);
    // 00499446  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499446(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00499446;
    // 00499441  a1002c5400             -mov eax, dword ptr [0x542c00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5516288) /* 0x542c00 */);
L_entry_0x00499446:
    // 00499446  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499447(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499447  e969f80000             -jmp 0x4a8cb5
    return sub_4a8cb5(app, cpu);
}

/* align: skip  */
void Application::sub_49944c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049944c  e982f90000             -jmp 0x4a8dd3
    return sub_4a8dd3(app, cpu);
}

/* align: skip  */
void Application::sub_499451(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499452  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499453  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499454  81ec18060000           -sub esp, 0x618
    (cpu.esp) -= x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 0049945a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049945c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0049945e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499460  893dfc2b5400           -mov dword ptr [0x542bfc], edi
    app->getMemory<x86::reg32>(x86::reg32(5516284) /* 0x542bfc */) = cpu.edi;
    // 00499466  e8cffd0000             -call 0x4a923a
    cpu.esp -= 4;
    sub_4a923a(app, cpu);
    if (cpu.terminate) return;
    // 0049946b  a3002c5400             -mov dword ptr [0x542c00], eax
    app->getMemory<x86::reg32>(x86::reg32(5516288) /* 0x542c00 */) = cpu.eax;
    // 00499470  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499472  7511                   -jne 0x499485
    if (!cpu.flags.zf)
    {
        goto L_0x00499485;
    }
    // 00499474  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00499476  0f85f6010000           -jne 0x499672
    if (!cpu.flags.zf)
    {
        goto L_0x00499672;
    }
    // 0049947c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0049947e  2eff1554544b00         -call dword ptr cs:[0x4b5454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936788) /* 0x4b5454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00499485:
    // 00499485  e875f90000             -call 0x4a8dff
    cpu.esp -= 4;
    sub_4a8dff(app, cpu);
    if (cpu.terminate) return;
    // 0049948a  2eff15ac544b00         -call dword ptr cs:[0x4b54ac]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936876) /* 0x4b54ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499491  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499493  a3fdab4c00             -mov dword ptr [0x4cabfd], eax
    app->getMemory<x86::reg32>(x86::reg32(5024765) /* 0x4cabfd */) = cpu.eax;
    // 00499498  89157c705400           -mov dword ptr [0x54707c], edx
    app->getMemory<x86::reg32>(x86::reg32(5533820) /* 0x54707c */) = cpu.edx;
    // 0049949e  2eff15fc544b00         -call dword ptr cs:[0x4b54fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936956) /* 0x4b54fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004994a5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004994a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004994a9  a203ac4c00             -mov byte ptr [0x4cac03], al
    app->getMemory<x86::reg8>(x86::reg32(5024771) /* 0x4cac03 */) = cpu.al;
    // 004994ae  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004994b1  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004994b6  66a305ac4c00           -mov word ptr [0x4cac05], ax
    app->getMemory<x86::reg16>(x86::reg32(5024773) /* 0x4cac05 */) = cpu.ax;
    // 004994bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004994be  66a105ac4c00           -mov ax, word ptr [0x4cac05]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5024773) /* 0x4cac05 */);
    // 004994c4  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004994ca  a307ac4c00             -mov dword ptr [0x4cac07], eax
    app->getMemory<x86::reg32>(x86::reg32(5024775) /* 0x4cac07 */) = cpu.eax;
    // 004994cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004994d1  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 004994d4  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004994d6  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004994dc  a30bac4c00             -mov dword ptr [0x4cac0b], eax
    app->getMemory<x86::reg32>(x86::reg32(5024779) /* 0x4cac0b */) = cpu.eax;
    // 004994e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004994e3  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004994e5  881504ac4c00           -mov byte ptr [0x4cac04], dl
    app->getMemory<x86::reg8>(x86::reg32(5024772) /* 0x4cac04 */) = cpu.dl;
    // 004994eb  a30fac4c00             -mov dword ptr [0x4cac0f], eax
    app->getMemory<x86::reg32>(x86::reg32(5024783) /* 0x4cac0f */) = cpu.eax;
    // 004994f0  a10bac4c00             -mov eax, dword ptr [0x4cac0b]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024779) /* 0x4cac0b */);
    // 004994f5  8b150fac4c00           -mov edx, dword ptr [0x4cac0f]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024783) /* 0x4cac0f */);
    // 004994fb  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004994fe  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00499500  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00499505  a313ac4c00             -mov dword ptr [0x4cac13], eax
    app->getMemory<x86::reg32>(x86::reg32(5024787) /* 0x4cac13 */) = cpu.eax;
    // 0049950a  8d842414040000         -lea eax, [esp + 0x414]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 00499511  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499512  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00499514  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00499519  2eff15d0544b00         -call dword ptr cs:[0x4b54d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936912) /* 0x4b54d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499520  8d842410040000         -lea eax, [esp + 0x410]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1040) /* 0x410 */);
    // 00499527  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00499529  e8f2ff0000             -call 0x4a9520
    cpu.esp -= 4;
    strdup(app, cpu);
    if (cpu.terminate) return;
    // 0049952e  a3c4ab4c00             -mov dword ptr [0x4cabc4], eax
    app->getMemory<x86::reg32>(x86::reg32(5024708) /* 0x4cabc4 */) = cpu.eax;
    // 00499533  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499535  e82b000100             -call 0x4a9565
    cpu.esp -= 4;
    sub_4a9565(app, cpu);
    if (cpu.terminate) return;
    // 0049953a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049953c  e8b4000100             -call 0x4a95f5
    cpu.esp -= 4;
    sub_4a95f5(app, cpu);
    if (cpu.terminate) return;
    // 00499541  a3d0ab4c00             -mov dword ptr [0x4cabd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5024720) /* 0x4cabd0 */) = cpu.eax;
    // 00499546  2eff1584544b00         -call dword ptr cs:[0x4b5484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936836) /* 0x4b5484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049954d  e8ceff0000             -call 0x4a9520
    cpu.esp -= 4;
    strdup(app, cpu);
    if (cpu.terminate) return;
    // 00499552  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00499554  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499556  80fb22                 +cmp bl, 0x22
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
    // 00499559  7514                   -jne 0x49956f
    if (!cpu.flags.zf)
    {
        goto L_0x0049956f;
    }
L_0x0049955b:
    // 0049955b  40                     -inc eax
    (cpu.eax)++;
    // 0049955c  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax);
    // 0049955e  80fd22                 +cmp ch, 0x22
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
    // 00499561  7404                   -je 0x499567
    if (cpu.flags.zf)
    {
        goto L_0x00499567;
    }
    // 00499563  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00499565  75f4                   -jne 0x49955b
    if (!cpu.flags.zf)
    {
        goto L_0x0049955b;
    }
L_0x00499567:
    // 00499567  803800                 +cmp byte ptr [eax], 0
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
    // 0049956a  741e                   -je 0x49958a
    if (cpu.flags.zf)
    {
        goto L_0x0049958a;
    }
L_0x0049956c:
    // 0049956c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049956d  eb1b                   -jmp 0x49958a
    goto L_0x0049958a;
L_0x0049956f:
    // 0049956f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00499571  fec2                   -inc dl
    (cpu.dl)++;
    // 00499573  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499579  f68284c84c0002         +test byte ptr [edx + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 00499580  7508                   -jne 0x49958a
    if (!cpu.flags.zf)
    {
        goto L_0x0049958a;
    }
    // 00499582  803800                 +cmp byte ptr [eax], 0
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
    // 00499585  7403                   -je 0x49958a
    if (cpu.flags.zf)
    {
        goto L_0x0049958a;
    }
    // 00499587  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499588  ebe5                   -jmp 0x49956f
    goto L_0x0049956f;
L_0x0049958a:
    // 0049958a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 0049958c  fec2                   -inc dl
    (cpu.dl)++;
    // 0049958e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499594  f68284c84c0002         +test byte ptr [edx + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 0049959b  75cf                   -jne 0x49956c
    if (!cpu.flags.zf)
    {
        goto L_0x0049956c;
    }
    // 0049959d  a3c0ab4c00             -mov dword ptr [0x4cabc0], eax
    app->getMemory<x86::reg32>(x86::reg32(5024704) /* 0x4cabc0 */) = cpu.eax;
    // 004995a2  2eff1588544b00         -call dword ptr cs:[0x4b5488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936840) /* 0x4b5488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004995a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004995ab  0f845f000000           -je 0x499610
    if (cpu.flags.zf)
    {
        goto L_0x00499610;
    }
    // 004995b1  e83f000100             -call 0x4a95f5
    cpu.esp -= 4;
    sub_4a95f5(app, cpu);
    if (cpu.terminate) return;
    // 004995b6  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004995b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004995bb  6683fb22               +cmp bx, 0x22
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
    // 004995bf  751c                   -jne 0x4995dd
    if (!cpu.flags.zf)
    {
        goto L_0x004995dd;
    }
L_0x004995c1:
    // 004995c1  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004995c4  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004995c7  6683fa22               +cmp dx, 0x22
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
    // 004995cb  7405                   -je 0x4995d2
    if (cpu.flags.zf)
    {
        goto L_0x004995d2;
    }
    // 004995cd  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004995d0  75ef                   -jne 0x4995c1
    if (!cpu.flags.zf)
    {
        goto L_0x004995c1;
    }
L_0x004995d2:
    // 004995d2  66833800               +cmp word ptr [eax], 0
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
    // 004995d6  7423                   -je 0x4995fb
    if (cpu.flags.zf)
    {
        goto L_0x004995fb;
    }
L_0x004995d8:
    // 004995d8  83c002                 +add eax, 2
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
    // 004995db  eb1e                   -jmp 0x4995fb
    goto L_0x004995fb;
L_0x004995dd:
    // 004995dd  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004995df  fec2                   -inc dl
    (cpu.dl)++;
    // 004995e1  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004995e7  f68284c84c0002         +test byte ptr [edx + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 004995ee  750b                   -jne 0x4995fb
    if (!cpu.flags.zf)
    {
        goto L_0x004995fb;
    }
    // 004995f0  66833800               +cmp word ptr [eax], 0
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
    // 004995f4  7405                   -je 0x4995fb
    if (cpu.flags.zf)
    {
        goto L_0x004995fb;
    }
    // 004995f6  83c002                 +add eax, 2
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
    // 004995f9  ebe2                   -jmp 0x4995dd
    goto L_0x004995dd;
L_0x004995fb:
    // 004995fb  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004995fd  fec2                   -inc dl
    (cpu.dl)++;
    // 004995ff  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499605  f68284c84c0002         +test byte ptr [edx + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 0049960c  740c                   -je 0x49961a
    if (cpu.flags.zf)
    {
        goto L_0x0049961a;
    }
    // 0049960e  ebc8                   -jmp 0x4995d8
    goto L_0x004995d8;
L_0x00499610:
    // 00499610  b8dcf24b00             -mov eax, 0x4bf2dc
    cpu.eax = 4977372 /*0x4bf2dc*/;
    // 00499615  e8dbff0000             -call 0x4a95f5
    cpu.esp -= 4;
    sub_4a95f5(app, cpu);
    if (cpu.terminate) return;
L_0x0049961a:
    // 0049961a  a3ccab4c00             -mov dword ptr [0x4cabcc], eax
    app->getMemory<x86::reg32>(x86::reg32(5024716) /* 0x4cabcc */) = cpu.eax;
    // 0049961f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00499621  744a                   -je 0x49966d
    if (cpu.flags.zf)
    {
        goto L_0x0049966d;
    }
    // 00499623  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00499628  8d842418050000         -lea eax, [esp + 0x518]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1304) /* 0x518 */);
    // 0049962f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00499630  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499631  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00499636  2eff15d0544b00         -call dword ptr cs:[0x4b54d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936912) /* 0x4b54d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049963d  8d842414050000         -lea eax, [esp + 0x514]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1300) /* 0x514 */);
    // 00499644  8d942408020000         -lea edx, [esp + 0x208]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0049964b  e8d0fe0000             -call 0x4a9520
    cpu.esp -= 4;
    strdup(app, cpu);
    if (cpu.terminate) return;
    // 00499650  a3c8ab4c00             -mov dword ptr [0x4cabc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5024712) /* 0x4cabc8 */) = cpu.eax;
    // 00499655  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499657  e809ff0000             -call 0x4a9565
    cpu.esp -= 4;
    sub_4a9565(app, cpu);
    if (cpu.terminate) return;
    // 0049965c  8d842408020000         -lea eax, [esp + 0x208]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 00499663  e88dff0000             -call 0x4a95f5
    cpu.esp -= 4;
    sub_4a95f5(app, cpu);
    if (cpu.terminate) return;
    // 00499668  a3d4ab4c00             -mov dword ptr [0x4cabd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5024724) /* 0x4cabd4 */) = cpu.eax;
L_0x0049966d:
    // 0049966d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00499672:
    // 00499672  81c418060000           -add esp, 0x618
    (cpu.esp) += x86::reg32(x86::sreg32(1560 /*0x618*/));
    // 00499678  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499679  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049967a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049967b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49967c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049967c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049967d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049967e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049967f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499680  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00499682  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00499684  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00499686  2eff15d8544b00         -call dword ptr cs:[0x4b54d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936920) /* 0x4b54d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049968d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049968f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00499691  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499693  e8b9fdffff             -call 0x499451
    cpu.esp -= 4;
    sub_499451(app, cpu);
    if (cpu.terminate) return;
    // 00499698  bae0ab4c00             -mov edx, 0x4cabe0
    cpu.edx = 5024736 /*0x4cabe0*/;
    // 0049969d  ff1544c14c00           -call dword ptr [0x4cc144]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030212) /* 0x4cc144 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004996a3  e874ff0000             -call 0x4a961c
    cpu.esp -= 4;
    sub_4a961c(app, cpu);
    if (cpu.terminate) return;
    // 004996a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004996aa  e8f4030100             -call 0x4a9aa3
    cpu.esp -= 4;
    sub_4a9aa3(app, cpu);
    if (cpu.terminate) return;
    // 004996af  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 004996b4  e806540000             -call 0x49eabf
    cpu.esp -= 4;
    sub_49eabf(app, cpu);
    if (cpu.terminate) return;
    // 004996b9  ff1584c14c00           -call dword ptr [0x4cc184]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030276) /* 0x4cc184 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004996bf  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004996c4  e8f6530000             -call 0x49eabf
    cpu.esp -= 4;
    sub_49eabf(app, cpu);
    if (cpu.terminate) return;
    // 004996c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996cb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004996cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4996ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004996ce  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004996d0  833dfc2b540000         +cmp dword ptr [0x542bfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5516284) /* 0x542bfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004996d7  7418                   -je 0x4996f1
    if (cpu.flags.zf)
    {
        goto L_0x004996f1;
    }
    // 004996d9  833d8cc14c0000         +cmp dword ptr [0x4cc18c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030284) /* 0x4cc18c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004996e0  7426                   -je 0x499708
    if (cpu.flags.zf)
    {
        goto L_0x00499708;
    }
    // 004996e2  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004996e7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004996e9  ff158cc14c00           -call dword ptr [0x4cc18c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030284) /* 0x4cc18c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004996ef  eb17                   -jmp 0x499708
    goto L_0x00499708;
L_0x004996f1:
    // 004996f1  e8f9030100             -call 0x4a9aef
    cpu.esp -= 4;
    sub_4a9aef(app, cpu);
    if (cpu.terminate) return;
    // 004996f6  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004996fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004996fd  e809540000             -call 0x49eb0b
    cpu.esp -= 4;
    sub_49eb0b(app, cpu);
    if (cpu.terminate) return;
    // 00499702  ff1580c14c00           -call dword ptr [0x4cc180]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030272) /* 0x4cc180 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00499708:
    // 00499708  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499709  2eff1554544b00         -call dword ptr cs:[0x4b5454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936788) /* 0x4b5454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499712  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499713  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499714  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499715  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499717  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049971a  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499720  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00499723  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00499726  83fb01                 +cmp ebx, 1
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
    // 00499729  741e                   -je 0x499749
    if (cpu.flags.zf)
    {
        goto L_0x00499749;
    }
    // 0049972b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049972d  7413                   -je 0x499742
    if (cpu.flags.zf)
    {
        goto L_0x00499742;
    }
    // 0049972f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499732  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499738  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049973d  e98d000000             -jmp 0x4997cf
    goto L_0x004997cf;
L_0x00499742:
    // 00499742  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00499749:
    // 00499749  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 0049974d  7515                   -jne 0x499764
    if (!cpu.flags.zf)
    {
        goto L_0x00499764;
    }
    // 0049974f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00499754  e8e7c4ffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 00499759  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049975d  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00499762  eb1f                   -jmp 0x499783
    goto L_0x00499783;
L_0x00499764:
    // 00499764  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00499767  4e                     -dec esi
    (cpu.esi)--;
    // 00499768  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049976b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049976d  7d0b                   -jge 0x49977a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049977a;
    }
    // 0049976f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499771  e85f000000             -call 0x4997d5
    cpu.esp -= 4;
    sub_4997d5(app, cpu);
    if (cpu.terminate) return;
    // 00499776  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499778  eb09                   -jmp 0x499783
    goto L_0x00499783;
L_0x0049977a:
    // 0049977a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049977c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049977e  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00499780  40                     -inc eax
    (cpu.eax)++;
    // 00499781  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00499783:
    // 00499783  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 00499787  753b                   -jne 0x4997c4
    if (!cpu.flags.zf)
    {
        goto L_0x004997c4;
    }
    // 00499789  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049978c  7523                   -jne 0x4997b1
    if (!cpu.flags.zf)
    {
        goto L_0x004997b1;
    }
    // 0049978e  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00499791  4d                     -dec ebp
    (cpu.ebp)--;
    // 00499792  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00499795  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00499797  7d0b                   -jge 0x4997a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004997a4;
    }
    // 00499799  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049979b  e835000000             -call 0x4997d5
    cpu.esp -= 4;
    sub_4997d5(app, cpu);
    if (cpu.terminate) return;
    // 004997a0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004997a2  eb0d                   -jmp 0x4997b1
    goto L_0x004997b1;
L_0x004997a4:
    // 004997a4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004997a6  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004997a8  40                     -inc eax
    (cpu.eax)++;
    // 004997a9  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004997af  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004997b1:
    // 004997b1  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004997b4  750e                   -jne 0x4997c4
    if (!cpu.flags.zf)
    {
        goto L_0x004997c4;
    }
    // 004997b6  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004997b9  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004997bc  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004997c1  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x004997c4:
    // 004997c4  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004997c7  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004997cd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004997cf:
    // 004997cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00499710;
    // 004996ce  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004996d0  833dfc2b540000         +cmp dword ptr [0x542bfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5516284) /* 0x542bfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004996d7  7418                   -je 0x4996f1
    if (cpu.flags.zf)
    {
        goto L_0x004996f1;
    }
    // 004996d9  833d8cc14c0000         +cmp dword ptr [0x4cc18c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030284) /* 0x4cc18c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004996e0  7426                   -je 0x499708
    if (cpu.flags.zf)
    {
        goto L_0x00499708;
    }
    // 004996e2  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 004996e7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004996e9  ff158cc14c00           -call dword ptr [0x4cc18c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030284) /* 0x4cc18c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004996ef  eb17                   -jmp 0x499708
    goto L_0x00499708;
L_0x004996f1:
    // 004996f1  e8f9030100             -call 0x4a9aef
    cpu.esp -= 4;
    sub_4a9aef(app, cpu);
    if (cpu.terminate) return;
    // 004996f6  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004996fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004996fd  e809540000             -call 0x49eb0b
    cpu.esp -= 4;
    sub_49eb0b(app, cpu);
    if (cpu.terminate) return;
    // 00499702  ff1580c14c00           -call dword ptr [0x4cc180]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030272) /* 0x4cc180 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00499708:
    // 00499708  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499709  2eff1554544b00         -call dword ptr cs:[0x4b5454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936788) /* 0x4b5454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x00499710:
    // 00499710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499712  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499713  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499714  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499715  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499717  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0049971a  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499720  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00499723  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00499726  83fb01                 +cmp ebx, 1
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
    // 00499729  741e                   -je 0x499749
    if (cpu.flags.zf)
    {
        goto L_0x00499749;
    }
    // 0049972b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049972d  7413                   -je 0x499742
    if (cpu.flags.zf)
    {
        goto L_0x00499742;
    }
    // 0049972f  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499732  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499738  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0049973d  e98d000000             -jmp 0x4997cf
    goto L_0x004997cf;
L_0x00499742:
    // 00499742  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00499749:
    // 00499749  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 0049974d  7515                   -jne 0x499764
    if (!cpu.flags.zf)
    {
        goto L_0x00499764;
    }
    // 0049974f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00499754  e8e7c4ffff             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 00499759  804a0c20               +or byte ptr [edx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 0049975d  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00499762  eb1f                   -jmp 0x499783
    goto L_0x00499783;
L_0x00499764:
    // 00499764  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00499767  4e                     -dec esi
    (cpu.esi)--;
    // 00499768  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0049976b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049976d  7d0b                   -jge 0x49977a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049977a;
    }
    // 0049976f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499771  e85f000000             -call 0x4997d5
    cpu.esp -= 4;
    sub_4997d5(app, cpu);
    if (cpu.terminate) return;
    // 00499776  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499778  eb09                   -jmp 0x499783
    goto L_0x00499783;
L_0x0049977a:
    // 0049977a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049977c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049977e  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00499780  40                     -inc eax
    (cpu.eax)++;
    // 00499781  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00499783:
    // 00499783  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 00499787  753b                   -jne 0x4997c4
    if (!cpu.flags.zf)
    {
        goto L_0x004997c4;
    }
    // 00499789  83fb0d                 +cmp ebx, 0xd
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13 /*0xd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049978c  7523                   -jne 0x4997b1
    if (!cpu.flags.zf)
    {
        goto L_0x004997b1;
    }
    // 0049978e  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00499791  4d                     -dec ebp
    (cpu.ebp)--;
    // 00499792  896a04                 -mov dword ptr [edx + 4], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00499795  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00499797  7d0b                   -jge 0x4997a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004997a4;
    }
    // 00499799  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049979b  e835000000             -call 0x4997d5
    cpu.esp -= 4;
    sub_4997d5(app, cpu);
    if (cpu.terminate) return;
    // 004997a0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004997a2  eb0d                   -jmp 0x4997b1
    goto L_0x004997b1;
L_0x004997a4:
    // 004997a4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004997a6  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004997a8  40                     -inc eax
    (cpu.eax)++;
    // 004997a9  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004997af  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004997b1:
    // 004997b1  83fb1a                 +cmp ebx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004997b4  750e                   -jne 0x4997c4
    if (!cpu.flags.zf)
    {
        goto L_0x004997c4;
    }
    // 004997b6  8a6a0c                 -mov ch, byte ptr [edx + 0xc]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004997b9  80cd10                 -or ch, 0x10
    cpu.ch |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 004997bc  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004997c1  886a0c                 -mov byte ptr [edx + 0xc], ch
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ch;
L_0x004997c4:
    // 004997c4  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004997c7  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004997cd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004997cf:
    // 004997cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4997d5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004997d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004997d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004997d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004997d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004997da  e825000000             -call 0x499804
    cpu.esp -= 4;
    sub_499804(app, cpu);
    if (cpu.terminate) return;
    // 004997df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004997e1  7509                   -jne 0x4997ec
    if (!cpu.flags.zf)
    {
        goto L_0x004997ec;
    }
    // 004997e3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004997e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004997eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004997ec:
    // 004997ec  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004997ef  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004997f1  4b                     -dec ebx
    (cpu.ebx)--;
    // 004997f2  41                     -inc ecx
    (cpu.ecx)++;
    // 004997f3  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004997f6  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004997f8  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004997fb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499800  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499801  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499802  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499803  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499804(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499804  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499805  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499806  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499807  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499808  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049980a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049980d  83780800               +cmp dword ptr [eax + 8], 0
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
    // 00499811  7507                   -jne 0x49981a
    if (!cpu.flags.zf)
    {
        goto L_0x0049981a;
    }
    // 00499813  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499815  e801540000             -call 0x49ec1b
    cpu.esp -= 4;
    sub_49ec1b(app, cpu);
    if (cpu.terminate) return;
L_0x0049981a:
    // 0049981a  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 0049981d  f6c420                 +test ah, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 32 /*0x20*/));
    // 00499820  740f                   -je 0x499831
    if (cpu.flags.zf)
    {
        goto L_0x00499831;
    }
    // 00499822  f6c406                 +test ah, 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 6 /*0x6*/));
    // 00499825  740a                   -je 0x499831
    if (cpu.flags.zf)
    {
        goto L_0x00499831;
    }
    // 00499827  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 0049982c  e8e7020100             -call 0x4a9b18
    cpu.esp -= 4;
    sub_4a9b18(app, cpu);
    if (cpu.terminate) return;
L_0x00499831:
    // 00499831  8a710c                 -mov dh, byte ptr [ecx + 0xc]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00499834  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 00499837  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0049983a  88710c                 -mov byte ptr [ecx + 0xc], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.dh;
    // 0049983d  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00499840  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00499842  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00499845  2500240000             -and eax, 0x2400
    cpu.eax &= x86::reg32(x86::sreg32(9216 /*0x2400*/));
    // 0049984a  3d00240000             +cmp eax, 0x2400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9216 /*0x2400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049984f  7523                   -jne 0x499874
    if (!cpu.flags.zf)
    {
        goto L_0x00499874;
    }
    // 00499851  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499854  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499856  751c                   -jne 0x499874
    if (!cpu.flags.zf)
    {
        goto L_0x00499874;
    }
    // 00499858  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049985b  e8f3020100             -call 0x4a9b53
    cpu.esp -= 4;
    sub_4a9b53(app, cpu);
    if (cpu.terminate) return;
    // 00499860  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499862  83f8ff                 +cmp eax, -1
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
    // 00499865  742a                   -je 0x499891
    if (cpu.flags.zf)
    {
        goto L_0x00499891;
    }
    // 00499867  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00499869  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 0049986b  c7410401000000         -mov dword ptr [ecx + 4], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00499872  eb3c                   -jmp 0x4998b0
    goto L_0x004998b0;
L_0x00499874:
    // 00499874  f6410d04               +test byte ptr [ecx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 00499878  7407                   -je 0x499881
    if (cpu.flags.zf)
    {
        goto L_0x00499881;
    }
    // 0049987a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0049987f  eb03                   -jmp 0x499884
    goto L_0x00499884;
L_0x00499881:
    // 00499881  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
L_0x00499884:
    // 00499884  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00499886  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499889  e813a40000             -call 0x4a3ca1
    cpu.esp -= 4;
    sub_4a3ca1(app, cpu);
    if (cpu.terminate) return;
    // 0049988e  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00499891:
    // 00499891  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00499894  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00499896  7f18                   -jg 0x4998b0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004998b0;
    }
    // 00499898  7506                   -jne 0x4998a0
    if (!cpu.flags.zf)
    {
        goto L_0x004998a0;
    }
    // 0049989a  80490c10               +or byte ptr [ecx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0049989e  eb10                   -jmp 0x4998b0
    goto L_0x004998b0;
L_0x004998a0:
    // 004998a0  8a790c                 -mov bh, byte ptr [ecx + 0xc]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004998a3  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004998aa  80cf20                 -or bh, 0x20
    cpu.bh |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004998ad  88790c                 -mov byte ptr [ecx + 0xc], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bh;
L_0x004998b0:
    // 004998b0  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004998b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4998b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004998b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004998b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004998ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004998bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004998bc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004998be  83f8ff                 +cmp eax, -1
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
    // 004998c1  0f84a6000000           -je 0x49996d
    if (cpu.flags.zf)
    {
        goto L_0x0049996d;
    }
    // 004998c7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004998ca  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004998d0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004998d3  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004998d6  83f901                 +cmp ecx, 1
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
    // 004998d9  741e                   -je 0x4998f9
    if (cpu.flags.zf)
    {
        goto L_0x004998f9;
    }
    // 004998db  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004998dd  7413                   -je 0x4998f2
    if (cpu.flags.zf)
    {
        goto L_0x004998f2;
    }
L_0x004998df:
    // 004998df  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004998e2  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004998e8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004998ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004998f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004998f2:
    // 004998f2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004998f9:
    // 004998f9  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004998fd  75e0                   -jne 0x4998df
    if (!cpu.flags.zf)
    {
        goto L_0x004998df;
    }
    // 004998ff  f6420c01               +test byte ptr [edx + 0xc], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 1 /*0x1*/));
    // 00499903  74da                   -je 0x4998df
    if (cpu.flags.zf)
    {
        goto L_0x004998df;
    }
    // 00499905  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00499908  83780800               +cmp dword ptr [eax + 8], 0
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
    // 0049990c  7507                   -jne 0x499915
    if (!cpu.flags.zf)
    {
        goto L_0x00499915;
    }
    // 0049990e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00499910  e806530000             -call 0x49ec1b
    cpu.esp -= 4;
    sub_49ec1b(app, cpu);
    if (cpu.terminate) return;
L_0x00499915:
    // 00499915  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00499918  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049991a  7517                   -jne 0x499933
    if (!cpu.flags.zf)
    {
        goto L_0x00499933;
    }
    // 0049991c  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00499923  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00499926  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00499929  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0049992c  01c8                   +add eax, ecx
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
    // 0049992e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0049992f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00499931  eb21                   -jmp 0x499954
    goto L_0x00499954;
L_0x00499933:
    // 00499933  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00499936  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499938  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049993b  74a2                   -je 0x4998df
    if (cpu.flags.zf)
    {
        goto L_0x004998df;
    }
    // 0049993d  8d7d01                 -lea edi, [ebp + 1]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00499940  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 00499942  897a04                 -mov dword ptr [edx + 4], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00499945  4d                     -dec ebp
    (cpu.ebp)--;
    // 00499946  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00499948  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0049994b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499950  39d8                   +cmp eax, ebx
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
    // 00499952  7404                   -je 0x499958
    if (cpu.flags.zf)
    {
        goto L_0x00499958;
    }
L_0x00499954:
    // 00499954  804a0c04               -or byte ptr [edx + 0xc], 4
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00499958:
    // 00499958  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0049995a  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0049995c  80620cef               -and byte ptr [edx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00499960  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499963  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499969  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049996b  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x0049996d:
    // 0049996d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049996e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049996f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499970  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499971  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499972(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499973  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499975  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00499977  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499978  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499979(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499979  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049997a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0049997c  ff5304                 -call dword ptr [ebx + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049997f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499980  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499981(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499981  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499982  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499983  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499984  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499985  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499988  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049998a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0049998d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049998f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00499993  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00499996  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499998  80e4fd                 -and ah, 0xfd
    cpu.ah &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 0049999b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049999d  886610                 -mov byte ptr [esi + 0x10], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ah;
L_0x004999a0:
    // 004999a0  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004999a3  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004999a6  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004999a9  8a1b                   -mov bl, byte ptr [ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004999ab  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004999b1  0f8423020000           -je 0x499bda
    if (cpu.flags.zf)
    {
        goto L_0x00499bda;
    }
    // 004999b7  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004999b9  fec0                   -inc al
    (cpu.al)++;
    // 004999bb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004999c0  f68084c84c0002         +test byte ptr [eax + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 004999c7  740e                   -je 0x4999d7
    if (cpu.flags.zf)
    {
        goto L_0x004999d7;
    }
    // 004999c9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004999cb  e81c030000             -call 0x499cec
    cpu.esp -= 4;
    sub_499cec(app, cpu);
    if (cpu.terminate) return;
    // 004999d0  01c7                   +add edi, eax
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
    // 004999d2  e9cd010000             -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x004999d7:
    // 004999d7  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004999da  7425                   -je 0x499a01
    if (cpu.flags.zf)
    {
        goto L_0x00499a01;
    }
    // 004999dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004999de  e88fffffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 004999e3  39d8                   +cmp eax, ebx
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
    // 004999e5  0f84b8010000           -je 0x499ba3
    if (cpu.flags.zf)
    {
        goto L_0x00499ba3;
    }
L_0x004999eb:
    // 004999eb  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 004999ef  0f85e5010000           -jne 0x499bda
    if (!cpu.flags.zf)
    {
        goto L_0x00499bda;
    }
    // 004999f5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004999f7  e87dffffff             -call 0x499979
    cpu.esp -= 4;
    sub_499979(app, cpu);
    if (cpu.terminate) return;
    // 004999fc  e9d9010000             -jmp 0x499bda
    goto L_0x00499bda;
L_0x00499a01:
    // 00499a01  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00499a04  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499a06  e8ea010000             -call 0x499bf5
    cpu.esp -= 4;
    sub_499bf5(app, cpu);
    if (cpu.terminate) return;
    // 00499a0b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00499a0d  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00499a10  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00499a12  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499a14  7404                   -je 0x499a1a
    if (cpu.flags.zf)
    {
        goto L_0x00499a1a;
    }
    // 00499a16  40                     -inc eax
    (cpu.eax)++;
    // 00499a17  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00499a1a:
    // 00499a1a  83fb64                 +cmp ebx, 0x64
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
    // 00499a1d  7265                   -jb 0x499a84
    if (cpu.flags.cf)
    {
        goto L_0x00499a84;
    }
    // 00499a1f  0f86c3000000           -jbe 0x499ae8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499ae8;
    }
    // 00499a25  83fb6f                 +cmp ebx, 0x6f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(111 /*0x6f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a28  7233                   -jb 0x499a5d
    if (cpu.flags.cf)
    {
        goto L_0x00499a5d;
    }
    // 00499a2a  0f86e1000000           -jbe 0x499b11
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b11;
    }
    // 00499a30  83fb73                 +cmp ebx, 0x73
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a33  7223                   -jb 0x499a58
    if (cpu.flags.cf)
    {
        goto L_0x00499a58;
    }
    // 00499a35  0f860e010000           -jbe 0x499b49
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b49;
    }
    // 00499a3b  83fb75                 +cmp ebx, 0x75
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(117 /*0x75*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a3e  0f8260010000           -jb 0x499ba4
    if (cpu.flags.cf)
    {
        goto L_0x00499ba4;
    }
    // 00499a44  0f86d3000000           -jbe 0x499b1d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b1d;
    }
    // 00499a4a  83fb78                 +cmp ebx, 0x78
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
L_0x00499a4d:
    // 00499a4d  0f84d9000000           -je 0x499b2c
    if (cpu.flags.zf)
    {
        goto L_0x00499b2c;
    }
    // 00499a53  e94c010000             -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499a58:
    // 00499a58  83fb70                 +cmp ebx, 0x70
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a5b  ebf0                   -jmp 0x499a4d
    goto L_0x00499a4d;
L_0x00499a5d:
    // 00499a5d  83fb69                 +cmp ebx, 0x69
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(105 /*0x69*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a60  7214                   -jb 0x499a76
    if (cpu.flags.cf)
    {
        goto L_0x00499a76;
    }
    // 00499a62  0f869a000000           -jbe 0x499b02
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b02;
    }
    // 00499a68  83fb6e                 +cmp ebx, 0x6e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a6b  0f8414010000           -je 0x499b85
    if (cpu.flags.zf)
    {
        goto L_0x00499b85;
    }
    // 00499a71  e92e010000             -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499a76:
    // 00499a76  83fb67                 +cmp ebx, 0x67
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(103 /*0x67*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a79  0f86b9000000           -jbe 0x499b38
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b38;
    }
    // 00499a7f  e920010000             -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499a84:
    // 00499a84  83fb47                 +cmp ebx, 0x47
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a87  723c                   -jb 0x499ac5
    if (cpu.flags.cf)
    {
        goto L_0x00499ac5;
    }
    // 00499a89  0f86a9000000           -jbe 0x499b38
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b38;
    }
    // 00499a8f  83fb58                 +cmp ebx, 0x58
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a92  7223                   -jb 0x499ab7
    if (cpu.flags.cf)
    {
        goto L_0x00499ab7;
    }
    // 00499a94  0f8692000000           -jbe 0x499b2c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b2c;
    }
    // 00499a9a  83fb5b                 +cmp ebx, 0x5b
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(91 /*0x5b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499a9d  0f8201010000           -jb 0x499ba4
    if (cpu.flags.cf)
    {
        goto L_0x00499ba4;
    }
    // 00499aa3  0f86ad000000           -jbe 0x499b56
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b56;
    }
    // 00499aa9  83fb63                 +cmp ebx, 0x63
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499aac  0f84b7000000           -je 0x499b69
    if (cpu.flags.zf)
    {
        goto L_0x00499b69;
    }
    // 00499ab2  e9ed000000             -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499ab7:
    // 00499ab7  83fb53                 +cmp ebx, 0x53
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(83 /*0x53*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499aba  0f8485000000           -je 0x499b45
    if (cpu.flags.zf)
    {
        goto L_0x00499b45;
    }
    // 00499ac0  e9df000000             -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499ac5:
    // 00499ac5  83fb43                 +cmp ebx, 0x43
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(67 /*0x43*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499ac8  7210                   -jb 0x499ada
    if (cpu.flags.cf)
    {
        goto L_0x00499ada;
    }
    // 00499aca  0f8695000000           -jbe 0x499b65
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499b65;
    }
    // 00499ad0  83fb45                 +cmp ebx, 0x45
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499ad3  7463                   -je 0x499b38
    if (cpu.flags.zf)
    {
        goto L_0x00499b38;
    }
    // 00499ad5  e9ca000000             -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499ada:
    // 00499ada  83fb25                 +cmp ebx, 0x25
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(37 /*0x25*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499add  0f84b1000000           -je 0x499b94
    if (cpu.flags.zf)
    {
        goto L_0x00499b94;
    }
    // 00499ae3  e9bc000000             -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499ae8:
    // 00499ae8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00499aed  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
L_0x00499af2:
    // 00499af2  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499af6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00499af8:
    // 00499af8  e8c8080000             -call 0x49a3c5
    cpu.esp -= 4;
    sub_49a3c5(app, cpu);
    if (cpu.terminate) return;
    // 00499afd  e972000000             -jmp 0x499b74
    goto L_0x00499b74;
L_0x00499b02:
    // 00499b02  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00499b07  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499b0b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499b0d  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00499b0f  ebe7                   -jmp 0x499af8
    goto L_0x00499af8;
L_0x00499b11:
    // 00499b11  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00499b16  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00499b1b  ebd5                   -jmp 0x499af2
    goto L_0x00499af2;
L_0x00499b1d:
    // 00499b1d  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00499b22  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499b26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499b28  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00499b2a  ebcc                   -jmp 0x499af8
    goto L_0x00499af8;
L_0x00499b2c:
    // 00499b2c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00499b31  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00499b36  ebba                   -jmp 0x499af2
    goto L_0x00499af2;
L_0x00499b38:
    // 00499b38  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499b3c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499b3e  e8ac050000             -call 0x49a0ef
    cpu.esp -= 4;
    sub_49a0ef(app, cpu);
    if (cpu.terminate) return;
    // 00499b43  eb2f                   -jmp 0x499b74
    goto L_0x00499b74;
L_0x00499b45:
    // 00499b45  804e1020               +or byte ptr [esi + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/))));
L_0x00499b49:
    // 00499b49  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499b4d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499b4f  e8b1020000             -call 0x499e05
    cpu.esp -= 4;
    sub_499e05(app, cpu);
    if (cpu.terminate) return;
    // 00499b54  eb1e                   -jmp 0x499b74
    goto L_0x00499b74;
L_0x00499b56:
    // 00499b56  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00499b58  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499b5c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499b5e  e896040000             -call 0x499ff9
    cpu.esp -= 4;
    sub_499ff9(app, cpu);
    if (cpu.terminate) return;
    // 00499b63  eb0f                   -jmp 0x499b74
    goto L_0x00499b74;
L_0x00499b65:
    // 00499b65  804e1020               -or byte ptr [esi + 0x10], 0x20
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00499b69:
    // 00499b69  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499b6d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499b6f  e8af010000             -call 0x499d23
    cpu.esp -= 4;
    sub_499d23(app, cpu);
    if (cpu.terminate) return;
L_0x00499b74:
    // 00499b74  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499b76  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00499b78  7e60                   -jle 0x499bda
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499bda;
    }
    // 00499b7a  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00499b7c  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00499b80  7422                   -je 0x499ba4
    if (cpu.flags.zf)
    {
        goto L_0x00499ba4;
    }
    // 00499b82  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499b83  eb1f                   -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499b85:
    // 00499b85  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499b89  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00499b8b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499b8d  e8c6030000             -call 0x499f58
    cpu.esp -= 4;
    sub_499f58(app, cpu);
    if (cpu.terminate) return;
    // 00499b92  eb10                   -jmp 0x499ba4
    goto L_0x00499ba4;
L_0x00499b94:
    // 00499b94  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499b96  e8d7fdffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 00499b9b  39d8                   +cmp eax, ebx
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
    // 00499b9d  0f8548feffff           -jne 0x4999eb
    if (!cpu.flags.zf)
    {
        goto L_0x004999eb;
    }
L_0x00499ba3:
    // 00499ba3  47                     -inc edi
    (cpu.edi)++;
L_0x00499ba4:
    // 00499ba4  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 00499ba8  0f84f2fdffff           -je 0x4999a0
    if (cpu.flags.zf)
    {
        goto L_0x004999a0;
    }
    // 00499bae  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00499bb1  803825                 +cmp byte ptr [eax], 0x25
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(37 /*0x25*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499bb4  7524                   -jne 0x499bda
    if (!cpu.flags.zf)
    {
        goto L_0x00499bda;
    }
    // 00499bb6  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00499bb9  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00499bbb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499bbd  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00499bc0  e830000000             -call 0x499bf5
    cpu.esp -= 4;
    sub_499bf5(app, cpu);
    if (cpu.terminate) return;
    // 00499bc5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00499bc8  80386e                 +cmp byte ptr [eax], 0x6e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499bcb  750d                   -jne 0x499bda
    if (!cpu.flags.zf)
    {
        goto L_0x00499bda;
    }
    // 00499bcd  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499bd1  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00499bd3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499bd5  e87e030000             -call 0x499f58
    cpu.esp -= 4;
    sub_499f58(app, cpu);
    if (cpu.terminate) return;
L_0x00499bda:
    // 00499bda  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00499bdc  750d                   -jne 0x499beb
    if (!cpu.flags.zf)
    {
        goto L_0x00499beb;
    }
    // 00499bde  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 00499be2  7407                   -je 0x499beb
    if (cpu.flags.zf)
    {
        goto L_0x00499beb;
    }
    // 00499be4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00499be9  eb02                   -jmp 0x499bed
    goto L_0x00499bed;
L_0x00499beb:
    // 00499beb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00499bed:
    // 00499bed  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499bf0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499bf1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499bf2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499bf3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499bf4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499bf5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499bf5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499bf6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499bf7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499bf8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499bfb  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00499bfd  8a5210                 -mov dl, byte ptr [edx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00499c00  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00499c03  885310                 -mov byte ptr [ebx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00499c06  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 00499c08  c7430cffffffff         -mov dword ptr [ebx + 0xc], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 4294967295 /*0xffffffff*/;
    // 00499c0f  80e603                 -and dh, 3
    cpu.dh &= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00499c12  887310                 -mov byte ptr [ebx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 00499c15  80382a                 +cmp byte ptr [eax], 0x2a
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
    // 00499c18  750a                   -jne 0x499c24
    if (!cpu.flags.zf)
    {
        goto L_0x00499c24;
    }
    // 00499c1a  8a6b10                 -mov ch, byte ptr [ebx + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00499c1d  80e5fe                 -and ch, 0xfe
    cpu.ch &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00499c20  40                     -inc eax
    (cpu.eax)++;
    // 00499c21  886b10                 -mov byte ptr [ebx + 0x10], ch
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ch;
L_0x00499c24:
    // 00499c24  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499c26  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00499c28  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00499c2b  8a1424                 -mov dl, byte ptr [esp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp);
    // 00499c2e  fec2                   -inc dl
    (cpu.dl)++;
    // 00499c30  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499c36  f68284c84c0020         +test byte ptr [edx + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 00499c3d  7428                   -je 0x499c67
    if (cpu.flags.zf)
    {
        goto L_0x00499c67;
    }
    // 00499c3f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00499c41:
    // 00499c41  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00499c44  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00499c47  83ee30                 -sub esi, 0x30
    (cpu.esi) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00499c4a  40                     -inc eax
    (cpu.eax)++;
    // 00499c4b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00499c4d  0fb630                 -movzx esi, byte ptr [eax]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax));
    // 00499c50  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00499c53  8a0c24                 -mov cl, byte ptr [esp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp);
    // 00499c56  fec1                   -inc cl
    (cpu.cl)++;
    // 00499c58  0fb6f1                 -movzx esi, cl
    cpu.esi = x86::reg32(cpu.cl);
    // 00499c5b  f68684c84c0020         +test byte ptr [esi + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 00499c62  75dd                   -jne 0x499c41
    if (!cpu.flags.zf)
    {
        goto L_0x00499c41;
    }
    // 00499c64  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00499c67:
    // 00499c67  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00499c69  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00499c6c  80f94e                 +cmp cl, 0x4e
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(78 /*0x4e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499c6f  7506                   -jne 0x499c77
    if (!cpu.flags.zf)
    {
        goto L_0x00499c77;
    }
    // 00499c71  804b1008               +or byte ptr [ebx + 0x10], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00499c75  eb09                   -jmp 0x499c80
    goto L_0x00499c80;
L_0x00499c77:
    // 00499c77  80f946                 +cmp cl, 0x46
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(70 /*0x46*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499c7a  7506                   -jne 0x499c82
    if (!cpu.flags.zf)
    {
        goto L_0x00499c82;
    }
    // 00499c7c  804b1004               -or byte ptr [ebx + 0x10], 4
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x00499c80:
    // 00499c80  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00499c82:
    // 00499c82  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00499c84  8d7001                 -lea esi, [eax + 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00499c87  80fa68                 +cmp dl, 0x68
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
    // 00499c8a  7210                   -jb 0x499c9c
    if (cpu.flags.cf)
    {
        goto L_0x00499c9c;
    }
    // 00499c8c  761c                   -jbe 0x499caa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499caa;
    }
    // 00499c8e  80fa6c                 +cmp dl, 0x6c
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
    // 00499c91  7252                   -jb 0x499ce5
    if (cpu.flags.cf)
    {
        goto L_0x00499ce5;
    }
    // 00499c93  761f                   -jbe 0x499cb4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499cb4;
    }
    // 00499c95  80fa77                 +cmp dl, 0x77
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
    // 00499c98  741a                   -je 0x499cb4
    if (cpu.flags.zf)
    {
        goto L_0x00499cb4;
    }
    // 00499c9a  eb49                   -jmp 0x499ce5
    goto L_0x00499ce5;
L_0x00499c9c:
    // 00499c9c  80fa49                 +cmp dl, 0x49
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
    // 00499c9f  7244                   -jb 0x499ce5
    if (cpu.flags.cf)
    {
        goto L_0x00499ce5;
    }
    // 00499ca1  762a                   -jbe 0x499ccd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00499ccd;
    }
    // 00499ca3  80fa4c                 +cmp dl, 0x4c
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
    // 00499ca6  7418                   -je 0x499cc0
    if (cpu.flags.zf)
    {
        goto L_0x00499cc0;
    }
    // 00499ca8  eb3b                   -jmp 0x499ce5
    goto L_0x00499ce5;
L_0x00499caa:
    // 00499caa  8a7310                 -mov dh, byte ptr [ebx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00499cad  80ce10                 +or dh, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dh |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00499cb0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499cb2  eb2e                   -jmp 0x499ce2
    goto L_0x00499ce2;
L_0x00499cb4:
    // 00499cb4  8a5310                 -mov dl, byte ptr [ebx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00499cb7  80ca20                 +or dl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00499cba  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499cbb  885310                 -mov byte ptr [ebx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 00499cbe  eb25                   -jmp 0x499ce5
    goto L_0x00499ce5;
L_0x00499cc0:
    // 00499cc0  8a4b10                 -mov cl, byte ptr [ebx + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00499cc3  80c940                 +or cl, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 00499cc6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499cc8  884b10                 -mov byte ptr [ebx + 0x10], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.cl;
    // 00499ccb  eb18                   -jmp 0x499ce5
    goto L_0x00499ce5;
L_0x00499ccd:
    // 00499ccd  80780136               +cmp byte ptr [eax + 1], 0x36
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
    // 00499cd1  7512                   -jne 0x499ce5
    if (!cpu.flags.zf)
    {
        goto L_0x00499ce5;
    }
    // 00499cd3  80780234               +cmp byte ptr [eax + 2], 0x34
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
    // 00499cd7  750c                   -jne 0x499ce5
    if (!cpu.flags.zf)
    {
        goto L_0x00499ce5;
    }
    // 00499cd9  8a7310                 -mov dh, byte ptr [ebx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00499cdc  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00499cdf  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x00499ce2:
    // 00499ce2  887310                 -mov byte ptr [ebx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.dh;
L_0x00499ce5:
    // 00499ce5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499ce8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ce9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499cea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ceb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499cec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499cec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499ced  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00499cee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499cef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499cf1  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x00499cf3:
    // 00499cf3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499cf5  e878fcffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 00499cfa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499cfc  fec2                   -inc dl
    (cpu.dl)++;
    // 00499cfe  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499d04  f68284c84c0002         +test byte ptr [edx + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 00499d0b  7403                   -je 0x499d10
    if (cpu.flags.zf)
    {
        goto L_0x00499d10;
    }
    // 00499d0d  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499d0e  ebe3                   -jmp 0x499cf3
    goto L_0x00499cf3;
L_0x00499d10:
    // 00499d10  f6431002               +test byte ptr [ebx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 00499d14  7507                   -jne 0x499d1d
    if (!cpu.flags.zf)
    {
        goto L_0x00499d1d;
    }
    // 00499d16  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00499d18  e85cfcffff             -call 0x499979
    cpu.esp -= 4;
    sub_499979(app, cpu);
    if (cpu.terminate) return;
L_0x00499d1d:
    // 00499d1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499d1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d21  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499d22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499d23(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499d23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499d24  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499d25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499d26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499d27  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499d28  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499d29  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499d2c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499d2e  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00499d32  7437                   -je 0x499d6b
    if (cpu.flags.zf)
    {
        goto L_0x00499d6b;
    }
    // 00499d34  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499d37  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 00499d3a  740c                   -je 0x499d48
    if (cpu.flags.zf)
    {
        goto L_0x00499d48;
    }
    // 00499d3c  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00499d3e  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499d41  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00499d43  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 00499d46  eb23                   -jmp 0x499d6b
    goto L_0x00499d6b;
L_0x00499d48:
    // 00499d48  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00499d4b  7410                   -je 0x499d5d
    if (cpu.flags.zf)
    {
        goto L_0x00499d5d;
    }
    // 00499d4d  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00499d4f  83c604                 +add esi, 4
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
    // 00499d52  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499d54  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00499d56  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499d58  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00499d5b  eb0e                   -jmp 0x499d6b
    goto L_0x00499d6b;
L_0x00499d5d:
    // 00499d5d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499d5f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499d62  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499d64  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00499d66  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499d68  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x00499d6b:
    // 00499d6b  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00499d6e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499d70  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d73  7505                   -jne 0x499d7a
    if (!cpu.flags.zf)
    {
        goto L_0x00499d7a;
    }
    // 00499d75  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00499d7a:
    // 00499d7a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00499d7c  0f8e77000000           -jle 0x499df9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499df9;
    }
    // 00499d82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499d84  e8e9fbffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 00499d89  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499d8c  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00499d8f  0f8564000000           -jne 0x499df9
    if (!cpu.flags.zf)
    {
        goto L_0x00499df9;
    }
    // 00499d95  45                     -inc ebp
    (cpu.ebp)++;
    // 00499d96  4f                     -dec edi
    (cpu.edi)--;
    // 00499d97  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00499d9a  74de                   -je 0x499d7a
    if (cpu.flags.zf)
    {
        goto L_0x00499d7a;
    }
    // 00499d9c  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00499d9f  7452                   -je 0x499df3
    if (cpu.flags.zf)
    {
        goto L_0x00499df3;
    }
    // 00499da1  8b158c705400           -mov edx, dword ptr [0x54708c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
    // 00499da7  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 00499dab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499dad  741f                   -je 0x499dce
    if (cpu.flags.zf)
    {
        goto L_0x00499dce;
    }
    // 00499daf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499db4  8a8091705400           -mov al, byte ptr [eax + 0x547091]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533841) /* 0x547091 */);
    // 00499dba  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00499dbc  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00499dc1  740b                   -je 0x499dce
    if (cpu.flags.zf)
    {
        goto L_0x00499dce;
    }
    // 00499dc3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499dc5  e8a8fbffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 00499dca  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x00499dce:
    // 00499dce  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00499dd3  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499dd7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499dd9  e8acfd0000             -call 0x4a9b8a
    cpu.esp -= 4;
    sub_4a9b8a(app, cpu);
    if (cpu.terminate) return;
    // 00499dde  83f8ff                 +cmp eax, -1
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
    // 00499de1  7504                   -jne 0x499de7
    if (!cpu.flags.zf)
    {
        goto L_0x00499de7;
    }
    // 00499de3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00499de5  eb14                   -jmp 0x499dfb
    goto L_0x00499dfb;
L_0x00499de7:
    // 00499de7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00499dea  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
    // 00499dee  83c602                 +add esi, 2
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
    // 00499df1  eb87                   -jmp 0x499d7a
    goto L_0x00499d7a;
L_0x00499df3:
    // 00499df3  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 00499df6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499df7  eb81                   -jmp 0x499d7a
    goto L_0x00499d7a;
L_0x00499df9:
    // 00499df9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00499dfb:
    // 00499dfb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499dfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dff  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499e00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499dfe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00499dfe;
    // 00499d23  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499d24  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499d25  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499d26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499d27  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499d28  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499d29  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00499d2c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499d2e  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00499d32  7437                   -je 0x499d6b
    if (cpu.flags.zf)
    {
        goto L_0x00499d6b;
    }
    // 00499d34  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499d37  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 00499d3a  740c                   -je 0x499d48
    if (cpu.flags.zf)
    {
        goto L_0x00499d48;
    }
    // 00499d3c  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00499d3e  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499d41  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00499d43  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 00499d46  eb23                   -jmp 0x499d6b
    goto L_0x00499d6b;
L_0x00499d48:
    // 00499d48  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00499d4b  7410                   -je 0x499d5d
    if (cpu.flags.zf)
    {
        goto L_0x00499d5d;
    }
    // 00499d4d  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00499d4f  83c604                 +add esi, 4
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
    // 00499d52  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499d54  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00499d56  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499d58  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00499d5b  eb0e                   -jmp 0x499d6b
    goto L_0x00499d6b;
L_0x00499d5d:
    // 00499d5d  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499d5f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499d62  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499d64  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00499d66  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499d68  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x00499d6b:
    // 00499d6b  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00499d6e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00499d70  83ffff                 +cmp edi, -1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499d73  7505                   -jne 0x499d7a
    if (!cpu.flags.zf)
    {
        goto L_0x00499d7a;
    }
    // 00499d75  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x00499d7a:
    // 00499d7a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00499d7c  0f8e77000000           -jle 0x499df9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499df9;
    }
    // 00499d82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499d84  e8e9fbffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 00499d89  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499d8c  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 00499d8f  0f8564000000           -jne 0x499df9
    if (!cpu.flags.zf)
    {
        goto L_0x00499df9;
    }
    // 00499d95  45                     -inc ebp
    (cpu.ebp)++;
    // 00499d96  4f                     -dec edi
    (cpu.edi)--;
    // 00499d97  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00499d9a  74de                   -je 0x499d7a
    if (cpu.flags.zf)
    {
        goto L_0x00499d7a;
    }
    // 00499d9c  f6c220                 +test dl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 32 /*0x20*/));
    // 00499d9f  7452                   -je 0x499df3
    if (cpu.flags.zf)
    {
        goto L_0x00499df3;
    }
    // 00499da1  8b158c705400           -mov edx, dword ptr [0x54708c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
    // 00499da7  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 00499dab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00499dad  741f                   -je 0x499dce
    if (cpu.flags.zf)
    {
        goto L_0x00499dce;
    }
    // 00499daf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499db4  8a8091705400           -mov al, byte ptr [eax + 0x547091]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533841) /* 0x547091 */);
    // 00499dba  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00499dbc  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00499dc1  740b                   -je 0x499dce
    if (cpu.flags.zf)
    {
        goto L_0x00499dce;
    }
    // 00499dc3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499dc5  e8a8fbffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 00499dca  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x00499dce:
    // 00499dce  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00499dd3  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499dd7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499dd9  e8acfd0000             -call 0x4a9b8a
    cpu.esp -= 4;
    sub_4a9b8a(app, cpu);
    if (cpu.terminate) return;
    // 00499dde  83f8ff                 +cmp eax, -1
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
    // 00499de1  7504                   -jne 0x499de7
    if (!cpu.flags.zf)
    {
        goto L_0x00499de7;
    }
    // 00499de3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00499de5  eb14                   -jmp 0x499dfb
    goto L_0x00499dfb;
L_0x00499de7:
    // 00499de7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00499dea  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
    // 00499dee  83c602                 +add esi, 2
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
    // 00499df1  eb87                   -jmp 0x499d7a
    goto L_0x00499d7a;
L_0x00499df3:
    // 00499df3  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 00499df6  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499df7  eb81                   -jmp 0x499d7a
    goto L_0x00499d7a;
L_0x00499df9:
    // 00499df9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00499dfb:
    // 00499dfb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_entry_0x00499dfe:
    // 00499dfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499dff  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499e00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499e04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499e05(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499e05  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499e06  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499e07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499e08  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499e09  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499e0a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499e0b  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00499e0e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499e10  f6401020               +test byte ptr [eax + 0x10], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 32 /*0x20*/));
    // 00499e14  7407                   -je 0x499e1d
    if (cpu.flags.zf)
    {
        goto L_0x00499e1d;
    }
    // 00499e16  c644240802             -mov byte ptr [esp + 8], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 2 /*0x2*/;
    // 00499e1b  eb09                   -jmp 0x499e26
    goto L_0x00499e26;
L_0x00499e1d:
    // 00499e1d  f6411010               -test byte ptr [ecx + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 00499e21  c644240801             -mov byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
L_0x00499e26:
    // 00499e26  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499e29  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00499e2c  7434                   -je 0x499e62
    if (cpu.flags.zf)
    {
        goto L_0x00499e62;
    }
    // 00499e2e  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 00499e31  740c                   -je 0x499e3f
    if (cpu.flags.zf)
    {
        goto L_0x00499e3f;
    }
    // 00499e33  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00499e35  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499e38  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00499e3a  c477f8                 -les esi, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 00499e3d  eb23                   -jmp 0x499e62
    goto L_0x00499e62;
L_0x00499e3f:
    // 00499e3f  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 00499e42  7410                   -je 0x499e54
    if (cpu.flags.zf)
    {
        goto L_0x00499e54;
    }
    // 00499e44  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00499e46  83c604                 +add esi, 4
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
    // 00499e49  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499e4b  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00499e4d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499e4f  8b76fc                 -mov esi, dword ptr [esi - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00499e52  eb0e                   -jmp 0x499e62
    goto L_0x00499e62;
L_0x00499e54:
    // 00499e54  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499e56  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499e59  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00499e5b  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00499e5d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00499e5f  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
L_0x00499e62:
    // 00499e62  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00499e64:
    // 00499e64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499e66  e807fbffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 00499e6b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499e6d  fec0                   -inc al
    (cpu.al)++;
    // 00499e6f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499e74  f68084c84c0002         +test byte ptr [eax + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 00499e7b  7403                   -je 0x499e80
    if (cpu.flags.zf)
    {
        goto L_0x00499e80;
    }
    // 00499e7d  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00499e7e  ebe4                   -jmp 0x499e64
    goto L_0x00499e64;
L_0x00499e80:
    // 00499e80  f6411002               +test byte ptr [ecx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 00499e84  7407                   -je 0x499e8d
    if (cpu.flags.zf)
    {
        goto L_0x00499e8d;
    }
    // 00499e86  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 00499e88  e9a4000000             -jmp 0x499f31
    goto L_0x00499f31;
L_0x00499e8d:
    // 00499e8d  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00499e90  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00499e93  89510c                 -mov dword ptr [ecx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00499e96  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499e98  0f848a000000           -je 0x499f28
    if (cpu.flags.zf)
    {
        goto L_0x00499f28;
    }
L_0x00499e9e:
    // 00499e9e  8a4110                 -mov al, byte ptr [ecx + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00499ea1  47                     -inc edi
    (cpu.edi)++;
    // 00499ea2  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00499ea4  7460                   -je 0x499f06
    if (cpu.flags.zf)
    {
        goto L_0x00499f06;
    }
    // 00499ea6  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499eab  7505                   -jne 0x499eb2
    if (!cpu.flags.zf)
    {
        goto L_0x00499eb2;
    }
    // 00499ead  26881e                 -mov byte ptr es:[esi], bl
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.bl;
    // 00499eb0  eb4c                   -jmp 0x499efe
    goto L_0x00499efe;
L_0x00499eb2:
    // 00499eb2  8b2d8c705400           -mov ebp, dword ptr [0x54708c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5533836) /* 0x54708c */);
    // 00499eb8  885c2404               -mov byte ptr [esp + 4], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bl;
    // 00499ebc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00499ebe  741e                   -je 0x499ede
    if (cpu.flags.zf)
    {
        goto L_0x00499ede;
    }
    // 00499ec0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499ec2  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00499ec4  8a8091705400           -mov al, byte ptr [eax + 0x547091]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5533841) /* 0x547091 */);
    // 00499eca  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00499ecc  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00499ed1  740b                   -je 0x499ede
    if (cpu.flags.zf)
    {
        goto L_0x00499ede;
    }
    // 00499ed3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499ed5  e898faffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 00499eda  88442405               -mov byte ptr [esp + 5], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.al;
L_0x00499ede:
    // 00499ede  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00499ee3  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00499ee7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00499ee9  e89cfc0000             -call 0x4a9b8a
    cpu.esp -= 4;
    sub_4a9b8a(app, cpu);
    if (cpu.terminate) return;
    // 00499eee  83f8ff                 +cmp eax, -1
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
    // 00499ef1  7504                   -jne 0x499ef7
    if (!cpu.flags.zf)
    {
        goto L_0x00499ef7;
    }
    // 00499ef3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00499ef5  eb59                   -jmp 0x499f50
    goto L_0x00499f50;
L_0x00499ef7:
    // 00499ef7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00499efa  66268906               -mov word ptr es:[esi], ax
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = cpu.ax;
L_0x00499efe:
    // 00499efe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499f00  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00499f04  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00499f06:
    // 00499f06  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499f08  e8e4080000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 00499f0d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00499f0f  83f8ff                 +cmp eax, -1
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
    // 00499f12  741d                   -je 0x499f31
    if (cpu.flags.zf)
    {
        goto L_0x00499f31;
    }
    // 00499f14  fec0                   -inc al
    (cpu.al)++;
    // 00499f16  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00499f1b  f68084c84c0002         +test byte ptr [eax + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 00499f22  0f8476ffffff           -je 0x499e9e
    if (cpu.flags.zf)
    {
        goto L_0x00499e9e;
    }
L_0x00499f28:
    // 00499f28  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499f2a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00499f2c  e848faffff             -call 0x499979
    cpu.esp -= 4;
    sub_499979(app, cpu);
    if (cpu.terminate) return;
L_0x00499f31:
    // 00499f31  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00499f35  7417                   -je 0x499f4e
    if (cpu.flags.zf)
    {
        goto L_0x00499f4e;
    }
    // 00499f37  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00499f39  7e13                   -jle 0x499f4e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00499f4e;
    }
    // 00499f3b  807c240801             +cmp byte ptr [esp + 8], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00499f40  7506                   -jne 0x499f48
    if (!cpu.flags.zf)
    {
        goto L_0x00499f48;
    }
    // 00499f42  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
    // 00499f46  eb06                   -jmp 0x499f4e
    goto L_0x00499f4e;
L_0x00499f48:
    // 00499f48  6626c7060000           -mov word ptr es:[esi], 0
    app->getMemory<x86::reg16>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x00499f4e:
    // 00499f4e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00499f50:
    // 00499f50  83c40c                 +add esp, 0xc
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
    // 00499f53  e9a6feffff             -jmp 0x499dfe
    return sub_499dfe(app, cpu);
}

/* align: skip  */
void Application::sub_499f58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499f58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499f59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499f5a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499f5b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499f5c  8a4810                 -mov cl, byte ptr [eax + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00499f5f  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 00499f62  744d                   -je 0x499fb1
    if (cpu.flags.zf)
    {
        goto L_0x00499fb1;
    }
    // 00499f64  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00499f67  740c                   -je 0x499f75
    if (cpu.flags.zf)
    {
        goto L_0x00499f75;
    }
    // 00499f69  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00499f6b  83c708                 +add edi, 8
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00499f6e  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00499f70  c457f8                 -les edx, ptr [edi - 8]
    NFS2_ASSERT(false);
    // 00499f73  eb25                   -jmp 0x499f9a
    goto L_0x00499f9a;
L_0x00499f75:
    // 00499f75  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 00499f78  7410                   -je 0x499f8a
    if (cpu.flags.zf)
    {
        goto L_0x00499f8a;
    }
    // 00499f7a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 00499f7c  83c604                 +add esi, 4
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
    // 00499f7f  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 00499f81  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00499f83  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 00499f85  8b56fc                 -mov edx, dword ptr [esi - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00499f88  eb10                   -jmp 0x499f9a
    goto L_0x00499f9a;
L_0x00499f8a:
    // 00499f8a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00499f8c  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00499f8f  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00499f91  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00499f93  8cd9                   -mov ecx, ds
    cpu.ecx = cpu.ds;
    // 00499f95  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 00499f97  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x00499f9a:
    // 00499f9a  8a6810                 -mov ch, byte ptr [eax + 0x10]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00499f9d  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00499fa0  7409                   -je 0x499fab
    if (cpu.flags.zf)
    {
        goto L_0x00499fab;
    }
    // 00499fa2  6626891a               -mov word ptr es:[edx], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.bx;
    // 00499fa6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499fa7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fa8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fa9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499faa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00499fab:
    // 00499fab  f6c520                 -test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 00499fae  26891a                 -mov dword ptr es:[edx], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.ebx;
L_0x00499fb1:
    // 00499fb1  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00499fb2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fb3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499fb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499fb6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499fb6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00499fb7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499fb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499fb9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00499fbb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00499fbd  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00499fc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00499fc4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00499fc6  e8f4a1feff             -call 0x4841bf
    cpu.esp -= 4;
    sub_4841bf(app, cpu);
    if (cpu.terminate) return;
    // 00499fcb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499fcd  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00499fcf  41                     -inc ecx
    (cpu.ecx)++;
    // 00499fd0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499fd2  741f                   -je 0x499ff3
    if (cpu.flags.zf)
    {
        goto L_0x00499ff3;
    }
L_0x00499fd4:
    // 00499fd4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00499fd6  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00499fd9  c1fa03                 -sar edx, 3
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (3 /*0x3*/ % 32));
    // 00499fdc  8a80d4c14c00           -mov al, byte ptr [eax + 0x4cc1d4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5030356) /* 0x4cc1d4 */);
    // 00499fe2  080432                 -or byte ptr [edx + esi], al
    app->getMemory<x86::reg8>(cpu.edx + cpu.esi * 1) |= x86::reg8(x86::sreg8(cpu.al));
    // 00499fe5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00499fe7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 00499fe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00499feb  7406                   -je 0x499ff3
    if (cpu.flags.zf)
    {
        goto L_0x00499ff3;
    }
    // 00499fed  41                     -inc ecx
    (cpu.ecx)++;
    // 00499fee  83f85d                 +cmp eax, 0x5d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(93 /*0x5d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00499ff1  75e1                   -jne 0x499fd4
    if (!cpu.flags.zf)
    {
        goto L_0x00499fd4;
    }
L_0x00499ff3:
    // 00499ff3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00499ff5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ff6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ff7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00499ff8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_499ff9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00499ff9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00499ffa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00499ffb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00499ffc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00499ffd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00499ffe  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0049a001  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a003  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0049a005  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049a007  80385e                 +cmp byte ptr [eax], 0x5e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(94 /*0x5e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049a00a  0f94c2                 -sete dl
    cpu.dl = cpu.flags.zf;
    // 0049a00d  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0049a013  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049a017  7403                   -je 0x49a01c
    if (cpu.flags.zf)
    {
        goto L_0x0049a01c;
    }
    // 0049a019  40                     -inc eax
    (cpu.eax)++;
    // 0049a01a  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0049a01c:
    // 0049a01c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0049a01e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049a020  e891ffffff             -call 0x499fb6
    cpu.esp -= 4;
    sub_499fb6(app, cpu);
    if (cpu.terminate) return;
    // 0049a025  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0049a027  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049a02a  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0049a02d  7434                   -je 0x49a063
    if (cpu.flags.zf)
    {
        goto L_0x0049a063;
    }
    // 0049a02f  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0049a032  740c                   -je 0x49a040
    if (cpu.flags.zf)
    {
        goto L_0x0049a040;
    }
    // 0049a034  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 0049a036  83c608                 +add esi, 8
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a039  8937                   -mov dword ptr [edi], esi
    app->getMemory<x86::reg32>(cpu.edi) = cpu.esi;
    // 0049a03b  c476f8                 -les esi, ptr [esi - 8]
    NFS2_ASSERT(false);
    // 0049a03e  eb23                   -jmp 0x49a063
    goto L_0x0049a063;
L_0x0049a040:
    // 0049a040  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0049a043  7410                   -je 0x49a055
    if (cpu.flags.zf)
    {
        goto L_0x0049a055;
    }
    // 0049a045  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049a047  83c304                 +add ebx, 4
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
    // 0049a04a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049a04c  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 0049a04e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049a050  8b73fc                 -mov esi, dword ptr [ebx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 0049a053  eb0e                   -jmp 0x49a063
    goto L_0x0049a063;
L_0x0049a055:
    // 0049a055  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0049a057  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a05a  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049a05c  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0049a05e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049a060  8b72fc                 -mov esi, dword ptr [edx - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0049a063:
    // 0049a063  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0049a066  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0049a068:
    // 0049a068  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a06a  766a                   -jbe 0x49a0d6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0049a0d6;
    }
    // 0049a06c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a06e  e8fff8ffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 0049a073  8a5910                 -mov bl, byte ptr [ecx + 0x10]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049a076  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0049a07a  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0049a07d  7557                   -jne 0x49a0d6
    if (!cpu.flags.zf)
    {
        goto L_0x0049a0d6;
    }
    // 0049a07f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049a081  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 0049a084  8a1c1c                 -mov bl, byte ptr [esp + ebx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.ebx * 1);
    // 0049a087  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a08d  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049a091  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0049a093  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0049a096  8a9bd4c14c00           -mov bl, byte ptr [ebx + 0x4cc1d4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5030356) /* 0x4cc1d4 */);
    // 0049a09c  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a0a0  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a0a6  85eb                   +test ebx, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebp));
    // 0049a0a8  0f94c3                 -sete bl
    cpu.bl = cpu.flags.zf;
    // 0049a0ab  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049a0af  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a0b5  39eb                   +cmp ebx, ebp
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
    // 0049a0b7  7409                   -je 0x49a0c2
    if (cpu.flags.zf)
    {
        goto L_0x0049a0c2;
    }
    // 0049a0b9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0049a0bb  e8b9f8ffff             -call 0x499979
    cpu.esp -= 4;
    sub_499979(app, cpu);
    if (cpu.terminate) return;
    // 0049a0c0  eb14                   -jmp 0x49a0d6
    goto L_0x0049a0d6;
L_0x0049a0c2:
    // 0049a0c2  47                     -inc edi
    (cpu.edi)++;
    // 0049a0c3  8a7910                 -mov bh, byte ptr [ecx + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0049a0c6  4a                     -dec edx
    (cpu.edx)--;
    // 0049a0c7  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0049a0ca  749c                   -je 0x49a068
    if (cpu.flags.zf)
    {
        goto L_0x0049a068;
    }
    // 0049a0cc  8a442428               -mov al, byte ptr [esp + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049a0d0  268806                 -mov byte ptr es:[esi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = cpu.al;
    // 0049a0d3  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049a0d4  eb92                   -jmp 0x49a068
    goto L_0x0049a068;
L_0x0049a0d6:
    // 0049a0d6  f6411001               +test byte ptr [ecx + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049a0da  7408                   -je 0x49a0e4
    if (cpu.flags.zf)
    {
        goto L_0x0049a0e4;
    }
    // 0049a0dc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049a0de  7e04                   -jle 0x49a0e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a0e4;
    }
    // 0049a0e0  26c60600               -mov byte ptr es:[esi], 0
    app->getMemory<x86::reg8>(cpu.ees + cpu.esi) = 0 /*0x0*/;
L_0x0049a0e4:
    // 0049a0e4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a0e6  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0049a0e9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0ea  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049a0eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a0ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a0ef(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a0ef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a0f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a0f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a0f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a0f3  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049a0f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a0f5  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0049a0f8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0049a0fa  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 0049a0fe  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0049a100  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049a102  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
L_0x0049a106:
    // 0049a106  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a108  e865f8ffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 0049a10d  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0049a10f  fec2                   -inc dl
    (cpu.dl)++;
    // 0049a111  0fb6ea                 -movzx ebp, dl
    cpu.ebp = x86::reg32(cpu.dl);
    // 0049a114  8a9584c84c00           -mov dl, byte ptr [ebp + 0x4cc884]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5032068) /* 0x4cc884 */);
    // 0049a11a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a11c  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0049a11f  7406                   -je 0x49a127
    if (cpu.flags.zf)
    {
        goto L_0x0049a127;
    }
    // 0049a121  ff442468               +inc dword ptr [esp + 0x68]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049a125  ebdf                   -jmp 0x49a106
    goto L_0x0049a106;
L_0x0049a127:
    // 0049a127  f6461002               +test byte ptr [esi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049a12b  0f85d7010000           -jne 0x49a308
    if (!cpu.flags.zf)
    {
        goto L_0x0049a308;
    }
    // 0049a131  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0049a134  8d6aff                 -lea ebp, [edx - 1]
    cpu.ebp = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 0049a137  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0049a13a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a13c  0f84bd010000           -je 0x49a2ff
    if (cpu.flags.zf)
    {
        goto L_0x0049a2ff;
    }
    // 0049a142  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a145  7405                   -je 0x49a14c
    if (cpu.flags.zf)
    {
        goto L_0x0049a14c;
    }
    // 0049a147  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a14a  751e                   -jne 0x49a16a
    if (!cpu.flags.zf)
    {
        goto L_0x0049a16a;
    }
L_0x0049a14c:
    // 0049a14c  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0049a150  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a152  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049a154  e898060000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a159  43                     -inc ebx
    (cpu.ebx)++;
    // 0049a15a  45                     -inc ebp
    (cpu.ebp)++;
    // 0049a15b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a15d  896c2468               -mov dword ptr [esp + 0x68], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 0049a161  83f8ff                 +cmp eax, -1
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
    // 0049a164  0f849e010000           -je 0x49a308
    if (cpu.flags.zf)
    {
        goto L_0x0049a308;
    }
L_0x0049a16a:
    // 0049a16a  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0049a16c  fec0                   -inc al
    (cpu.al)++;
    // 0049a16e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a173  f68084c84c0020         +test byte ptr [eax + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 0049a17a  7509                   -jne 0x49a185
    if (!cpu.flags.zf)
    {
        goto L_0x0049a185;
    }
    // 0049a17c  83f92e                 +cmp ecx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a17f  0f857a010000           -jne 0x49a2ff
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2ff;
    }
L_0x0049a185:
    // 0049a185  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a187  89442464               -mov dword ptr [esp + 0x64], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 0049a18b  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0049a18d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a18f  fec0                   -inc al
    (cpu.al)++;
    // 0049a191  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a196  f68084c84c0020         +test byte ptr [eax + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 0049a19d  7441                   -je 0x49a1e0
    if (cpu.flags.zf)
    {
        goto L_0x0049a1e0;
    }
    // 0049a19f  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
L_0x0049a1a4:
    // 0049a1a4  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049a1a6  8a4610                 -mov al, byte ptr [esi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049a1a9  43                     -inc ebx
    (cpu.ebx)++;
    // 0049a1aa  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0049a1ac  740f                   -je 0x49a1bd
    if (cpu.flags.zf)
    {
        goto L_0x0049a1bd;
    }
    // 0049a1ae  6b4424660a             -imul eax, dword ptr [esp + 0x66], 0xa
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(102) /* 0x66 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 0049a1b3  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a1b5  83e930                 -sub ecx, 0x30
    (cpu.ecx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049a1b8  66894c2466             -mov word ptr [esp + 0x66], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(102) /* 0x66 */) = cpu.cx;
L_0x0049a1bd:
    // 0049a1bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a1bf  47                     -inc edi
    (cpu.edi)++;
    // 0049a1c0  e82c060000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a1c5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a1c7  83f8ff                 +cmp eax, -1
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
    // 0049a1ca  0f8438010000           -je 0x49a308
    if (cpu.flags.zf)
    {
        goto L_0x0049a308;
    }
    // 0049a1d0  fec0                   -inc al
    (cpu.al)++;
    // 0049a1d2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a1d7  f68084c84c0020         +test byte ptr [eax + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 0049a1de  75c4                   -jne 0x49a1a4
    if (!cpu.flags.zf)
    {
        goto L_0x0049a1a4;
    }
L_0x0049a1e0:
    // 0049a1e0  83f92e                 +cmp ecx, 0x2e
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(46 /*0x2e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a1e3  0f8598000000           -jne 0x49a281
    if (!cpu.flags.zf)
    {
        goto L_0x0049a281;
    }
    // 0049a1e9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a1eb  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049a1ed  e8ff050000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a1f2  43                     -inc ebx
    (cpu.ebx)++;
    // 0049a1f3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a1f5  83f8ff                 +cmp eax, -1
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
    // 0049a1f8  0f840a010000           -je 0x49a308
    if (cpu.flags.zf)
    {
        goto L_0x0049a308;
    }
    // 0049a1fe  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049a200  7514                   -jne 0x49a216
    if (!cpu.flags.zf)
    {
        goto L_0x0049a216;
    }
    // 0049a202  fec0                   -inc al
    (cpu.al)++;
    // 0049a204  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a209  f68084c84c0020         +test byte ptr [eax + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 0049a210  0f84e9000000           -je 0x49a2ff
    if (cpu.flags.zf)
    {
        goto L_0x0049a2ff;
    }
L_0x0049a216:
    // 0049a216  47                     -inc edi
    (cpu.edi)++;
L_0x0049a217:
    // 0049a217  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0049a219  fec0                   -inc al
    (cpu.al)++;
    // 0049a21b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a220  f68084c84c0020         +test byte ptr [eax + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 0049a227  7412                   -je 0x49a23b
    if (cpu.flags.zf)
    {
        goto L_0x0049a23b;
    }
    // 0049a229  47                     -inc edi
    (cpu.edi)++;
    // 0049a22a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a22c  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049a22e  e8be050000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a233  43                     -inc ebx
    (cpu.ebx)++;
    // 0049a234  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a236  83f8ff                 +cmp eax, -1
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
    // 0049a239  75dc                   -jne 0x49a217
    if (!cpu.flags.zf)
    {
        goto L_0x0049a217;
    }
L_0x0049a23b:
    // 0049a23b  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0049a23f  7437                   -je 0x49a278
    if (cpu.flags.zf)
    {
        goto L_0x0049a278;
    }
    // 0049a241  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a243  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0049a245  89542460               -mov dword ptr [esp + 0x60], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.edx;
L_0x0049a249:
    // 0049a249  4d                     -dec ebp
    (cpu.ebp)--;
    // 0049a24a  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 0049a24d  3c2e                   +cmp al, 0x2e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049a24f  741e                   -je 0x49a26f
    if (cpu.flags.zf)
    {
        goto L_0x0049a26f;
    }
    // 0049a251  2c30                   -sub al, 0x30
    (cpu.al) -= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 0049a253  c744245c0a000000       -mov dword ptr [esp + 0x5c], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = 10 /*0xa*/;
    // 0049a25b  88442462               -mov byte ptr [esp + 0x62], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(98) /* 0x62 */) = cpu.al;
    // 0049a25f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a261  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049a265  f774245c               +div dword ptr [esp + 0x5c]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 0049a269  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 0049a26d  ebda                   -jmp 0x49a249
    goto L_0x0049a249;
L_0x0049a26f:
    // 0049a26f  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0049a273  6689442464             -mov word ptr [esp + 0x64], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ax;
L_0x0049a278:
    // 0049a278  83f9ff                 +cmp ecx, -1
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
    // 0049a27b  0f8487000000           -je 0x49a308
    if (cpu.flags.zf)
    {
        goto L_0x0049a308;
    }
L_0x0049a281:
    // 0049a281  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0049a285  0f8574000000           -jne 0x49a2ff
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2ff;
    }
    // 0049a28b  83f965                 +cmp ecx, 0x65
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(101 /*0x65*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a28e  7409                   -je 0x49a299
    if (cpu.flags.zf)
    {
        goto L_0x0049a299;
    }
    // 0049a290  83f945                 +cmp ecx, 0x45
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a293  0f8566000000           -jne 0x49a2ff
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2ff;
    }
L_0x0049a299:
    // 0049a299  47                     -inc edi
    (cpu.edi)++;
    // 0049a29a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a29c  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049a29e  e84e050000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a2a3  43                     -inc ebx
    (cpu.ebx)++;
    // 0049a2a4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a2a6  83f8ff                 +cmp eax, -1
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
    // 0049a2a9  745d                   -je 0x49a308
    if (cpu.flags.zf)
    {
        goto L_0x0049a308;
    }
    // 0049a2ab  83f82b                 +cmp eax, 0x2b
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(43 /*0x2b*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a2ae  7405                   -je 0x49a2b5
    if (cpu.flags.zf)
    {
        goto L_0x0049a2b5;
    }
    // 0049a2b0  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a2b3  7512                   -jne 0x49a2c7
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2c7;
    }
L_0x0049a2b5:
    // 0049a2b5  47                     -inc edi
    (cpu.edi)++;
    // 0049a2b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a2b8  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049a2ba  e832050000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a2bf  43                     -inc ebx
    (cpu.ebx)++;
    // 0049a2c0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a2c2  83f8ff                 +cmp eax, -1
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
    // 0049a2c5  7441                   -je 0x49a308
    if (cpu.flags.zf)
    {
        goto L_0x0049a308;
    }
L_0x0049a2c7:
    // 0049a2c7  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 0049a2c9  fec0                   -inc al
    (cpu.al)++;
    // 0049a2cb  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a2d0  f68084c84c0020         +test byte ptr [eax + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 0049a2d7  7504                   -jne 0x49a2dd
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2dd;
    }
    // 0049a2d9  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0049a2db  eb22                   -jmp 0x49a2ff
    goto L_0x0049a2ff;
L_0x0049a2dd:
    // 0049a2dd  47                     -inc edi
    (cpu.edi)++;
    // 0049a2de  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0049a2e0  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 0049a2e2  e80a050000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a2e7  43                     -inc ebx
    (cpu.ebx)++;
    // 0049a2e8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0049a2ea  83f8ff                 +cmp eax, -1
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
    // 0049a2ed  7419                   -je 0x49a308
    if (cpu.flags.zf)
    {
        goto L_0x0049a308;
    }
    // 0049a2ef  fec0                   -inc al
    (cpu.al)++;
    // 0049a2f1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a2f6  f68084c84c0020         +test byte ptr [eax + 0x4cc884], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032068) /* 0x4cc884 */) & 32 /*0x20*/));
    // 0049a2fd  75de                   -jne 0x49a2dd
    if (!cpu.flags.zf)
    {
        goto L_0x0049a2dd;
    }
L_0x0049a2ff:
    // 0049a2ff  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0049a301  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0049a303  e871f6ffff             -call 0x499979
    cpu.esp -= 4;
    sub_499979(app, cpu);
    if (cpu.terminate) return;
L_0x0049a308:
    // 0049a308  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0049a30a  0f8eab000000           -jle 0x49a3bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a3bb;
    }
    // 0049a310  037c2468               -add edi, dword ptr [esp + 0x68]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */)));
    // 0049a314  f6461001               +test byte ptr [esi + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 0049a318  0f849d000000           -je 0x49a3bb
    if (cpu.flags.zf)
    {
        goto L_0x0049a3bb;
    }
    // 0049a31e  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 0049a321  f6461010               +test byte ptr [esi + 0x10], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */) & 16 /*0x10*/));
    // 0049a325  740c                   -je 0x49a333
    if (cpu.flags.zf)
    {
        goto L_0x0049a333;
    }
    // 0049a327  803c242d               +cmp byte ptr [esp], 0x2d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esp);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0049a32b  7512                   -jne 0x49a33f
    if (!cpu.flags.zf)
    {
        goto L_0x0049a33f;
    }
    // 0049a32d  f75c2464               +neg dword ptr [esp + 0x64]
    {
        x86::reg32 tmp1 = 0;
        auto tmp2 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0049a331  eb0c                   -jmp 0x49a33f
    goto L_0x0049a33f;
L_0x0049a333:
    // 0049a333  8d542450               -lea edx, [esp + 0x50]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049a337  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0049a339  ff158cd64c00           -call dword ptr [0x4cd68c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5035660) /* 0x4cd68c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0049a33f:
    // 0049a33f  8a6610                 -mov ah, byte ptr [esi + 0x10]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049a342  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 0049a345  7410                   -je 0x49a357
    if (cpu.flags.zf)
    {
        goto L_0x0049a357;
    }
    // 0049a347  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049a34b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a34d  83c108                 +add ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a350  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 0049a352  c459f8                 -les ebx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 0049a355  eb2b                   -jmp 0x49a382
    goto L_0x0049a382;
L_0x0049a357:
    // 0049a357  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 0049a35a  7414                   -je 0x49a370
    if (cpu.flags.zf)
    {
        goto L_0x0049a370;
    }
    // 0049a35c  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049a360  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a362  83c304                 +add ebx, 4
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
    // 0049a365  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0049a367  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049a369  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049a36b  8b5bfc                 -mov ebx, dword ptr [ebx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 0049a36e  eb12                   -jmp 0x49a382
    goto L_0x0049a382;
L_0x0049a370:
    // 0049a370  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0049a374  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a376  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a379  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049a37b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049a37d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049a37f  8b5afc                 -mov ebx, dword ptr [edx - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
L_0x0049a382:
    // 0049a382  8a7610                 -mov dh, byte ptr [esi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0049a385  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0049a388  7406                   -je 0x49a390
    if (cpu.flags.zf)
    {
        goto L_0x0049a390;
    }
    // 0049a38a  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0049a38e  eb28                   -jmp 0x49a3b8
    goto L_0x0049a3b8;
L_0x0049a390:
    // 0049a390  f6c620                 +test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0049a393  7505                   -jne 0x49a39a
    if (!cpu.flags.zf)
    {
        goto L_0x0049a39a;
    }
    // 0049a395  f6c640                 +test dh, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 64 /*0x40*/));
    // 0049a398  7411                   -je 0x49a3ab
    if (cpu.flags.zf)
    {
        goto L_0x0049a3ab;
    }
L_0x0049a39a:
    // 0049a39a  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049a39e  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
    // 0049a3a1  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049a3a5  26894304               -mov dword ptr es:[ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049a3a9  eb10                   -jmp 0x49a3bb
    goto L_0x0049a3bb;
L_0x0049a3ab:
    // 0049a3ab  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0049a3af  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0049a3b3  e878f80000             -call 0x4a9c30
    cpu.esp -= 4;
    sub_4a9c30(app, cpu);
    if (cpu.terminate) return;
L_0x0049a3b8:
    // 0049a3b8  268903                 -mov dword ptr es:[ebx], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.ebx) = cpu.eax;
L_0x0049a3bb:
    // 0049a3bb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a3bd  83c46c                 +add esp, 0x6c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0049a3c0  e939faffff             -jmp 0x499dfe
    return sub_499dfe(app, cpu);
}

/* align: skip  */
void Application::sub_49a3c5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a3c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0049a3c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0049a3c7  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0049a3c8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0049a3c9  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049a3cc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0049a3ce  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0049a3d2  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0049a3d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0049a3d8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a3da  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049a3de  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0049a3e2  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0049a3e6  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
L_0x0049a3ea:
    // 0049a3ea  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a3ec  e881f5ffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 0049a3f1  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a3f5  8a5c242c               -mov bl, byte ptr [esp + 0x2c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049a3f9  fec3                   -inc bl
    (cpu.bl)++;
    // 0049a3fb  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0049a401  f68384c84c0002         +test byte ptr [ebx + 0x4cc884], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5032068) /* 0x4cc884 */) & 2 /*0x2*/));
    // 0049a408  7406                   -je 0x49a410
    if (cpu.flags.zf)
    {
        goto L_0x0049a410;
    }
    // 0049a40a  ff442420               +inc dword ptr [esp + 0x20]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0049a40e  ebda                   -jmp 0x49a3ea
    goto L_0x0049a3ea;
L_0x0049a410:
    // 0049a410  f6471002               +test byte ptr [edi + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049a414  0f8590020000           -jne 0x49a6aa
    if (!cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
    // 0049a41a  8b5f0c                 -mov ebx, dword ptr [edi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0049a41d  8d73ff                 -lea esi, [ebx - 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0049a420  89770c                 -mov dword ptr [edi + 0xc], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0049a423  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0049a425  0f8474020000           -je 0x49a69f
    if (cpu.flags.zf)
    {
        goto L_0x0049a69f;
    }
    // 0049a42b  bb2b000000             -mov ebx, 0x2b
    cpu.ebx = 43 /*0x2b*/;
    // 0049a430  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0049a434  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0049a436  742e                   -je 0x49a466
    if (cpu.flags.zf)
    {
        goto L_0x0049a466;
    }
    // 0049a438  39d8                   +cmp eax, ebx
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
    // 0049a43a  7405                   -je 0x49a441
    if (cpu.flags.zf)
    {
        goto L_0x0049a441;
    }
    // 0049a43c  83f82d                 +cmp eax, 0x2d
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a43f  7525                   -jne 0x49a466
    if (!cpu.flags.zf)
    {
        goto L_0x0049a466;
    }
L_0x0049a441:
    // 0049a441  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049a445  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a449  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0049a44d  41                     -inc ecx
    (cpu.ecx)++;
    // 0049a44e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a450  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0049a454  e898030000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a459  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a45d  83f8ff                 +cmp eax, -1
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
    // 0049a460  0f8444020000           -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
L_0x0049a466:
    // 0049a466  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049a46a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0049a46c  0f8569000000           -jne 0x49a4db
    if (!cpu.flags.zf)
    {
        goto L_0x0049a4db;
    }
    // 0049a472  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a477  7558                   -jne 0x49a4d1
    if (!cpu.flags.zf)
    {
        goto L_0x0049a4d1;
    }
    // 0049a479  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a47b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049a480  e86c030000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a485  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a489  83f8ff                 +cmp eax, -1
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
    // 0049a48c  0f8418020000           -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
    // 0049a492  83f878                 +cmp eax, 0x78
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
    // 0049a495  7405                   -je 0x49a49c
    if (cpu.flags.zf)
    {
        goto L_0x0049a49c;
    }
    // 0049a497  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a49a  752b                   -jne 0x49a4c7
    if (!cpu.flags.zf)
    {
        goto L_0x0049a4c7;
    }
L_0x0049a49c:
    // 0049a49c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a49e  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a4a2  e84a030000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a4a7  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a4a9  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049a4ac  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a4b0  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0049a4b4  83f8ff                 +cmp eax, -1
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
    // 0049a4b7  0f84ed010000           -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
    // 0049a4bd  c744242810000000       -mov dword ptr [esp + 0x28], 0x10
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 16 /*0x10*/;
    // 0049a4c5  eb64                   -jmp 0x49a52b
    goto L_0x0049a52b;
L_0x0049a4c7:
    // 0049a4c7  c744242808000000       -mov dword ptr [esp + 0x28], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 8 /*0x8*/;
    // 0049a4cf  eb5a                   -jmp 0x49a52b
    goto L_0x0049a52b;
L_0x0049a4d1:
    // 0049a4d1  c74424280a000000       -mov dword ptr [esp + 0x28], 0xa
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 10 /*0xa*/;
    // 0049a4d9  eb50                   -jmp 0x49a52b
    goto L_0x0049a52b;
L_0x0049a4db:
    // 0049a4db  83fe10                 +cmp esi, 0x10
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
    // 0049a4de  754b                   -jne 0x49a52b
    if (!cpu.flags.zf)
    {
        goto L_0x0049a52b;
    }
    // 0049a4e0  837c242c30             +cmp dword ptr [esp + 0x2c], 0x30
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a4e5  7544                   -jne 0x49a52b
    if (!cpu.flags.zf)
    {
        goto L_0x0049a52b;
    }
    // 0049a4e7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a4e9  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0049a4ee  e8fe020000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a4f3  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a4f7  83f8ff                 +cmp eax, -1
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
    // 0049a4fa  0f84aa010000           -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
    // 0049a500  83f878                 +cmp eax, 0x78
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
    // 0049a503  7405                   -je 0x49a50a
    if (cpu.flags.zf)
    {
        goto L_0x0049a50a;
    }
    // 0049a505  83f858                 +cmp eax, 0x58
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(88 /*0x58*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a508  7521                   -jne 0x49a52b
    if (!cpu.flags.zf)
    {
        goto L_0x0049a52b;
    }
L_0x0049a50a:
    // 0049a50a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a50c  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a510  e8dc020000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a515  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0049a517  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0049a51a  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a51e  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0049a522  83f8ff                 +cmp eax, -1
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
    // 0049a525  0f847f010000           -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
L_0x0049a52b:
    // 0049a52b  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 0049a52f  0f84ff000000           -je 0x49a634
    if (cpu.flags.zf)
    {
        goto L_0x0049a634;
    }
    // 0049a535  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049a539  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a53b  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0049a53f  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x0049a543:
    // 0049a543  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049a547  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049a54b  e87a020000             -call 0x49a7ca
    cpu.esp -= 4;
    sub_49a7ca(app, cpu);
    if (cpu.terminate) return;
    // 0049a550  39d0                   +cmp eax, edx
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
    // 0049a552  7d5d                   -jge 0x49a5b1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a5b1;
    }
    // 0049a554  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a558  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049a55b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0049a55d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a561  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0049a565  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049a569  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049a56c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a56e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049a571  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049a573  e804f70000             -call 0x4a9c7c
    cpu.esp -= 4;
    sub_4a9c7c(app, cpu);
    if (cpu.terminate) return;
    // 0049a578  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049a57b  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049a57d  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a581  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049a583  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a587  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049a58a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a58c  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049a58f  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049a591  01d8                   +add eax, ebx
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
    // 0049a593  11ca                   -adc edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0049a595  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049a598  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049a59a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a59c  45                     -inc ebp
    (cpu.ebp)++;
    // 0049a59d  e84f020000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a5a2  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a5a6  83f8ff                 +cmp eax, -1
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
    // 0049a5a9  0f84fb000000           -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
    // 0049a5af  eb92                   -jmp 0x49a543
    goto L_0x0049a543;
L_0x0049a5b1:
    // 0049a5b1  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a5b6  0f85e3000000           -jne 0x49a69f
    if (!cpu.flags.zf)
    {
        goto L_0x0049a69f;
    }
    // 0049a5bc  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 0049a5c0  0f84d9000000           -je 0x49a69f
    if (cpu.flags.zf)
    {
        goto L_0x0049a69f;
    }
L_0x0049a5c6:
    // 0049a5c6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a5c8  45                     -inc ebp
    (cpu.ebp)++;
    // 0049a5c9  e823020000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a5ce  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a5d2  83f8ff                 +cmp eax, -1
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
    // 0049a5d5  0f84cf000000           -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
    // 0049a5db  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0049a5df  e8e6010000             -call 0x49a7ca
    cpu.esp -= 4;
    sub_49a7ca(app, cpu);
    if (cpu.terminate) return;
    // 0049a5e4  39f0                   +cmp eax, esi
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
    // 0049a5e6  0f8db3000000           -jge 0x49a69f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a69f;
    }
    // 0049a5ec  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a5f0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0049a5f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0049a5f5  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0049a5f9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0049a5fd  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a601  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049a604  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a606  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049a609  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049a60b  e86cf60000             -call 0x4a9c7c
    cpu.esp -= 4;
    sub_4a9c7c(app, cpu);
    if (cpu.terminate) return;
    // 0049a610  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049a613  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049a615  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a619  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0049a61b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a61f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0049a622  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a624  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0049a627  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0049a629  01d8                   +add eax, ebx
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
    // 0049a62b  11ca                   +adc edx, ecx
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
    // 0049a62d  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0049a630  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0049a632  eb92                   -jmp 0x49a5c6
    goto L_0x0049a5c6;
L_0x0049a634:
    // 0049a634  8b742428               -mov esi, dword ptr [esp + 0x28]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0049a638:
    // 0049a638  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049a63c  e889010000             -call 0x49a7ca
    cpu.esp -= 4;
    sub_49a7ca(app, cpu);
    if (cpu.terminate) return;
    // 0049a641  39f0                   +cmp eax, esi
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
    // 0049a643  7d20                   -jge 0x49a665
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a665;
    }
    // 0049a645  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049a649  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0049a64c  45                     -inc ebp
    (cpu.ebp)++;
    // 0049a64d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0049a64f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a651  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049a655  e897010000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a65a  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a65e  83f8ff                 +cmp eax, -1
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
    // 0049a661  7447                   -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
    // 0049a663  ebd3                   -jmp 0x49a638
    goto L_0x0049a638;
L_0x0049a665:
    // 0049a665  837c242c3a             +cmp dword ptr [esp + 0x2c], 0x3a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(58 /*0x3a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a66a  7533                   -jne 0x49a69f
    if (!cpu.flags.zf)
    {
        goto L_0x0049a69f;
    }
    // 0049a66c  f6471080               +test byte ptr [edi + 0x10], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 128 /*0x80*/));
    // 0049a670  742d                   -je 0x49a69f
    if (cpu.flags.zf)
    {
        goto L_0x0049a69f;
    }
    // 0049a672  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x0049a676:
    // 0049a676  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0049a678  45                     -inc ebp
    (cpu.ebp)++;
    // 0049a679  e873010000             -call 0x49a7f1
    cpu.esp -= 4;
    sub_49a7f1(app, cpu);
    if (cpu.terminate) return;
    // 0049a67e  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0049a682  83f8ff                 +cmp eax, -1
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
    // 0049a685  7423                   -je 0x49a6aa
    if (cpu.flags.zf)
    {
        goto L_0x0049a6aa;
    }
    // 0049a687  e83e010000             -call 0x49a7ca
    cpu.esp -= 4;
    sub_49a7ca(app, cpu);
    if (cpu.terminate) return;
    // 0049a68c  39c8                   +cmp eax, ecx
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
    // 0049a68e  7d0f                   -jge 0x49a69f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0049a69f;
    }
    // 0049a690  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049a694  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0049a697  01c3                   +add ebx, eax
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
    // 0049a699  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0049a69d  ebd7                   -jmp 0x49a676
    goto L_0x0049a676;
L_0x0049a69f:
    // 0049a69f  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0049a6a3  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0049a6a5  e8cff2ffff             -call 0x499979
    cpu.esp -= 4;
    sub_499979(app, cpu);
    if (cpu.terminate) return;
L_0x0049a6aa:
    // 0049a6aa  f6471040               +test byte ptr [edi + 0x10], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */) & 64 /*0x40*/));
    // 0049a6ae  0f8492000000           -je 0x49a746
    if (cpu.flags.zf)
    {
        goto L_0x0049a746;
    }
    // 0049a6b4  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a6b9  7524                   -jne 0x49a6df
    if (!cpu.flags.zf)
    {
        goto L_0x0049a6df;
    }
    // 0049a6bb  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a6bf  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0049a6c3  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 0049a6c5  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0049a6c7  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0049a6cb  8d5601                 -lea edx, [esi + 1]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0049a6ce  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0049a6d2  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0049a6d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0049a6d8  7501                   -jne 0x49a6db
    if (!cpu.flags.zf)
    {
        goto L_0x0049a6db;
    }
    // 0049a6da  40                     -inc eax
    (cpu.eax)++;
L_0x0049a6db:
    // 0049a6db  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0049a6df:
    // 0049a6df  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049a6e1  0f8ed9000000           -jle 0x49a7c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a7c0;
    }
    // 0049a6e7  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a6eb  8a7f10                 -mov bh, byte ptr [edi + 0x10]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049a6ee  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a6f0  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 0049a6f3  0f84c7000000           -je 0x49a7c0
    if (cpu.flags.zf)
    {
        goto L_0x0049a7c0;
    }
    // 0049a6f9  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0049a6fc  7414                   -je 0x49a712
    if (cpu.flags.zf)
    {
        goto L_0x0049a712;
    }
    // 0049a6fe  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049a702  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a704  83c208                 +add edx, 8
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
    // 0049a707  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049a709  668b42fc               -mov ax, word ptr [edx - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0049a70d  8b7af8                 -mov edi, dword ptr [edx - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 0049a710  eb27                   -jmp 0x49a739
    goto L_0x0049a739;
L_0x0049a712:
    // 0049a712  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 0049a715  7412                   -je 0x49a729
    if (cpu.flags.zf)
    {
        goto L_0x0049a729;
    }
    // 0049a717  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049a71b  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a71d  83c704                 +add edi, 4
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
    // 0049a720  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0049a722  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049a724  8b7ffc                 -mov edi, dword ptr [edi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 0049a727  eb10                   -jmp 0x49a739
    goto L_0x0049a739;
L_0x0049a729:
    // 0049a729  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049a72d  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a72f  83c604                 +add esi, 4
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
    // 0049a732  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0049a734  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0049a736  8b7efc                 -mov edi, dword ptr [esi - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x0049a739:
    // 0049a739  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0049a73d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0049a73f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049a740  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0049a741  e97a000000             -jmp 0x49a7c0
    goto L_0x0049a7c0;
L_0x0049a746:
    // 0049a746  837c24182d             +cmp dword ptr [esp + 0x18], 0x2d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(45 /*0x2d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a74b  7504                   -jne 0x49a751
    if (!cpu.flags.zf)
    {
        goto L_0x0049a751;
    }
    // 0049a74d  f75c2424               -neg dword ptr [esp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = ~app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) + 1;
L_0x0049a751:
    // 0049a751  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0049a753  0f8e67000000           -jle 0x49a7c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0049a7c0;
    }
    // 0049a759  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0049a75d  8a4710                 -mov al, byte ptr [edi + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049a760  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0049a762  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0049a764  745a                   -je 0x49a7c0
    if (cpu.flags.zf)
    {
        goto L_0x0049a7c0;
    }
    // 0049a766  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0049a768  7410                   -je 0x49a77a
    if (cpu.flags.zf)
    {
        goto L_0x0049a77a;
    }
    // 0049a76a  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049a76e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a770  83c308                 +add ebx, 8
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
    // 0049a773  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0049a775  c443f8                 -les eax, ptr [ebx - 8]
    NFS2_ASSERT(false);
    // 0049a778  eb2a                   -jmp 0x49a7a4
    goto L_0x0049a7a4;
L_0x0049a77a:
    // 0049a77a  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0049a77c  7414                   -je 0x49a792
    if (cpu.flags.zf)
    {
        goto L_0x0049a792;
    }
    // 0049a77e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049a782  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a784  83c204                 +add edx, 4
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
    // 0049a787  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 0049a789  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0049a78b  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 0049a78d  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 0049a790  eb12                   -jmp 0x49a7a4
    goto L_0x0049a7a4;
L_0x0049a792:
    // 0049a792  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0049a796  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0049a798  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0049a79b  8cdb                   -mov ebx, ds
    cpu.ebx = cpu.ds;
    // 0049a79d  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0049a79f  8ec3                   -mov es, ebx
    cpu.es = cpu.ebx;
    // 0049a7a1  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
L_0x0049a7a4:
    // 0049a7a4  8a7710                 -mov dh, byte ptr [edi + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0049a7a7  f6c610                 +test dh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 16 /*0x10*/));
    // 0049a7aa  740a                   -je 0x49a7b6
    if (cpu.flags.zf)
    {
        goto L_0x0049a7b6;
    }
    // 0049a7ac  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049a7b0  66268918               -mov word ptr es:[eax], bx
    app->getMemory<x86::reg16>(cpu.ees + cpu.eax) = cpu.bx;
    // 0049a7b4  eb0a                   -jmp 0x49a7c0
    goto L_0x0049a7c0;
L_0x0049a7b6:
    // 0049a7b6  f6c620                 -test dh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 32 /*0x20*/));
    // 0049a7b9  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0049a7bd  268918                 -mov dword ptr es:[eax], ebx
    app->getMemory<x86::reg32>(cpu.ees + cpu.eax) = cpu.ebx;
L_0x0049a7c0:
    // 0049a7c0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0049a7c2  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049a7c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a7c6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0049a7c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a7c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a7c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a7ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a7ca  83f830                 +cmp eax, 0x30
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
    // 0049a7cd  7c09                   -jl 0x49a7d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a7d8;
    }
    // 0049a7cf  83f839                 +cmp eax, 0x39
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
    // 0049a7d2  7f04                   -jg 0x49a7d8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a7d8;
    }
    // 0049a7d4  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0049a7d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a7d8:
    // 0049a7d8  e84ee7ffff             -call 0x498f2b
    cpu.esp -= 4;
    sub_498f2b(app, cpu);
    if (cpu.terminate) return;
    // 0049a7dd  83f861                 +cmp eax, 0x61
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
    // 0049a7e0  7c09                   -jl 0x49a7eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0049a7eb;
    }
    // 0049a7e2  83f866                 +cmp eax, 0x66
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(102 /*0x66*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0049a7e5  7f04                   -jg 0x49a7eb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0049a7eb;
    }
    // 0049a7e7  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 0049a7ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0049a7eb:
    // 0049a7eb  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0049a7f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a7f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a7f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0049a7f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a7f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0049a7f5  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0049a7f8  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0049a7fb  895a0c                 -mov dword ptr [edx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0049a7fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0049a800  740d                   -je 0x49a80f
    if (cpu.flags.zf)
    {
        goto L_0x0049a80f;
    }
    // 0049a802  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0049a804  e869f1ffff             -call 0x499972
    cpu.esp -= 4;
    sub_499972(app, cpu);
    if (cpu.terminate) return;
    // 0049a809  f6421002               +test byte ptr [edx + 0x10], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) & 2 /*0x2*/));
    // 0049a80d  7405                   -je 0x49a814
    if (cpu.flags.zf)
    {
        goto L_0x0049a814;
    }
L_0x0049a80f:
    // 0049a80f  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0049a814:
    // 0049a814  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a815  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a816  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_49a817(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0049a817  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0049a818  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0049a819  2eff1598544b00         -call dword ptr cs:[0x4b5498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936856) /* 0x4b5498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0049a820  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a821  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0049a822  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
