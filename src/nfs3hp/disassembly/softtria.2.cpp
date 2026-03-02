#include "softtria.h"
#include <lib/thread.h>

namespace softtria
{

/* align: skip 0x8d 0x40 0x00 */
void sub_a73bd4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73bd4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a73bd5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a73bd6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a73bd8  ff1570d1a700           -call dword ptr [0xa7d170]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998128) /* 0xa7d170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a73bde  803d1000a80000         +cmp byte ptr [0xa80010], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(11010064) /* 0xa80010 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a73be5  750f                   -jne 0xa73bf6
    if (!cpu.flags.zf)
    {
        goto L_0x00a73bf6;
    }
    // 00a73be7  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a73bec  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00a73bf1  e8260b0000             -call 0xa7471c
    cpu.esp -= 4;
    sub_a7471c(app, cpu);
    if (cpu.terminate) return;
L_0x00a73bf6:
    // 00a73bf6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a73bf8  e803000000             -call 0xa73c00
    cpu.esp -= 4;
    sub_a73c00(app, cpu);
    if (cpu.terminate) return;
    // 00a73bfd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73bfe  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73bff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a73c00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73c00  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a73c01  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a73c03  ff1570d1a700           -call dword ptr [0xa7d170]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998128) /* 0xa7d170 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a73c09  ff1574d1a700           -call dword ptr [0xa7d174]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998132) /* 0xa7d174 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a73c0f  833d20d3a70000         +cmp dword ptr [0xa7d320], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10998560) /* 0xa7d320 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a73c16  7406                   -je 0xa73c1e
    if (cpu.flags.zf)
    {
        goto L_0x00a73c1e;
    }
    // 00a73c18  ff1520d3a700           -call dword ptr [0xa7d320]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998560) /* 0xa7d320 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a73c1e:
    // 00a73c1e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a73c20  e9170a0000             -jmp 0xa7463c
    return sub_a7463c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a73c30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73c30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a73c31  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a73c32  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a73c34  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a73c36  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a73c39  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a73c3b  881a                   -mov byte ptr [edx], bl
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00a73c3d  ff4010                 -inc dword ptr [eax + 0x10]
    (*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 00a73c40  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73c41  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73c42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a73c44(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73c44  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a73c45  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a73c46  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a73c48  b9303ca700             -mov ecx, 0xa73c30
    cpu.ecx = 10959920 /*0xa73c30*/;
    // 00a73c4d  e81e0b0000             -call 0xa74770
    cpu.esp -= 4;
    sub_a74770(app, cpu);
    if (cpu.terminate) return;
    // 00a73c52  c6040600               -mov byte ptr [esi + eax], 0
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 00a73c56  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73c57  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73c58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a73c5a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73c5a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a73c5b  9b                     -wait 
    /*nothing*/;
    // 00a73c5c  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a73c5f  9b                     -wait 
    /*nothing*/;
    // 00a73c60  ff3424                 -push dword ptr [esp]
    *app->getMemory<x86::reg32>(cpu.esp-4) = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    // 00a73c63  c64424011f             -mov byte ptr [esp + 1], 0x1f
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = 31 /*0x1f*/;
    // 00a73c68  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a73c6b  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 00a73c6d  d96c2404               -fldcw word ptr [esp + 4]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a73c71  9b                     -wait 
    /*nothing*/;
    // 00a73c72  8d642408               -lea esp, [esp + 8]
    cpu.esp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a73c76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a73c80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73c80  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a73c81  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a73c82  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a73c83  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a73c84  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a73c85  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a73c86  0fa0                   -push fs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a73c88  0fa8                   -push gs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a73c8a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a73c8b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a73c8e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a73c90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73c92  7405                   -je 0xa73c99
    if (cpu.flags.zf)
    {
        goto L_0x00a73c99;
    }
    // 00a73c94  83f8d4                 +cmp eax, -0x2c
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
    // 00a73c97  7607                   -jbe 0xa73ca0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a73ca0;
    }
L_0x00a73c99:
    // 00a73c99  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a73c9b  e9be000000             -jmp 0xa73d5e
    goto L_0x00a73d5e;
L_0x00a73ca0:
    // 00a73ca0  8d680b                 -lea ebp, [eax + 0xb]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a73ca3  83e5f8                 -and ebp, 0xfffffff8
    cpu.ebp &= x86::reg32(x86::sreg32(4294967288 /*0xfffffff8*/));
    // 00a73ca6  83fd10                 +cmp ebp, 0x10
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
    // 00a73ca9  7305                   -jae 0xa73cb0
    if (!cpu.flags.cf)
    {
        goto L_0x00a73cb0;
    }
    // 00a73cab  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
L_0x00a73cb0:
    // 00a73cb0  ff15b0d2a700           -call dword ptr [0xa7d2b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998448) /* 0xa7d2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a73cb6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a73cb8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a73cba  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a73cbd:
    // 00a73cbd  3b2d80d1a700           +cmp ebp, dword ptr [0xa7d180]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10998144) /* 0xa7d180 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a73cc3  760c                   -jbe 0xa73cd1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a73cd1;
    }
    // 00a73cc5  8b0d7cd1a700           -mov ecx, dword ptr [0xa7d17c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10998140) /* 0xa7d17c */);
    // 00a73ccb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73ccd  7510                   -jne 0xa73cdf
    if (!cpu.flags.zf)
    {
        goto L_0x00a73cdf;
    }
    // 00a73ccf  eb02                   -jmp 0xa73cd3
    goto L_0x00a73cd3;
L_0x00a73cd1:
    // 00a73cd1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a73cd3:
    // 00a73cd3  890d80d1a700           -mov dword ptr [0xa7d180], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10998144) /* 0xa7d180 */) = cpu.ecx;
    // 00a73cd9  8b0d78d1a700           -mov ecx, dword ptr [0xa7d178]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */);
L_0x00a73cdf:
    // 00a73cdf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73ce1  743c                   -je 0xa73d1f
    if (cpu.flags.zf)
    {
        goto L_0x00a73d1f;
    }
    // 00a73ce3  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a73ce6  890d7cd1a700           -mov dword ptr [0xa7d17c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10998140) /* 0xa7d17c */) = cpu.ecx;
    // 00a73cec  39fe                   +cmp esi, edi
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
    // 00a73cee  721c                   -jb 0xa73d0c
    if (cpu.flags.cf)
    {
        goto L_0x00a73d0c;
    }
    // 00a73cf0  b878d1a700             -mov eax, 0xa7d178
    cpu.eax = 10998136 /*0xa7d178*/;
    // 00a73cf5  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a73cf7  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a73cfd  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a73cff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a73d01  e89a180000             -call 0xa755a0
    cpu.esp -= 4;
    sub_a755a0(app, cpu);
    if (cpu.terminate) return;
    // 00a73d06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a73d08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73d0a  7542                   -jne 0xa73d4e
    if (!cpu.flags.zf)
    {
        goto L_0x00a73d4e;
    }
L_0x00a73d0c:
    // 00a73d0c  3b3580d1a700           +cmp esi, dword ptr [0xa7d180]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10998144) /* 0xa7d180 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a73d12  7606                   -jbe 0xa73d1a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a73d1a;
    }
    // 00a73d14  893580d1a700           -mov dword ptr [0xa7d180], esi
    *app->getMemory<x86::reg32>(x86::reg32(10998144) /* 0xa7d180 */) = cpu.esi;
L_0x00a73d1a:
    // 00a73d1a  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a73d1d  ebc0                   -jmp 0xa73cdf
    goto L_0x00a73cdf;
L_0x00a73d1f:
    // 00a73d1f  803c2400               +cmp byte ptr [esp], 0
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
    // 00a73d23  750b                   -jne 0xa73d30
    if (!cpu.flags.zf)
    {
        goto L_0x00a73d30;
    }
    // 00a73d25  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a73d27  e8881b0000             -call 0xa758b4
    cpu.esp -= 4;
    sub_a758b4(app, cpu);
    if (cpu.terminate) return;
    // 00a73d2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73d2e  7515                   -jne 0xa73d45
    if (!cpu.flags.zf)
    {
        goto L_0x00a73d45;
    }
L_0x00a73d30:
    // 00a73d30  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a73d32  e8e91b0000             -call 0xa75920
    cpu.esp -= 4;
    sub_a75920(app, cpu);
    if (cpu.terminate) return;
    // 00a73d37  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73d39  7413                   -je 0xa73d4e
    if (cpu.flags.zf)
    {
        goto L_0x00a73d4e;
    }
    // 00a73d3b  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00a73d3d  880c24                 -mov byte ptr [esp], cl
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.cl;
    // 00a73d40  e978ffffff             -jmp 0xa73cbd
    goto L_0x00a73cbd;
L_0x00a73d45:
    // 00a73d45  c6042401               -mov byte ptr [esp], 1
    *app->getMemory<x86::reg8>(cpu.esp) = 1 /*0x1*/;
    // 00a73d49  e96fffffff             -jmp 0xa73cbd
    goto L_0x00a73cbd;
L_0x00a73d4e:
    // 00a73d4e  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 00a73d50  882d4006a800           -mov byte ptr [0xa80640], ch
    *app->getMemory<x86::reg8>(x86::reg32(11011648) /* 0xa80640 */) = cpu.ch;
    // 00a73d56  ff15b8d2a700           -call dword ptr [0xa7d2b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998456) /* 0xa7d2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a73d5c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a73d5e:
    // 00a73d5e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a73d61  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73d62  0fa9                   -pop gs
    cpu.gs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a73d64  0fa1                   -pop fs
    cpu.fs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a73d66  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a73d67  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73d68  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73d69  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73d6a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73d6b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73d6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a73d70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73d70  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a73d71  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a73d72  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a73d73  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a73d74  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a73d76  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73d78  0f84f3000000           -je 0xa73e71
    if (cpu.flags.zf)
    {
        goto L_0x00a73e71;
    }
    // 00a73d7e  ff15b0d2a700           -call dword ptr [0xa7d2b0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998448) /* 0xa7d2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a73d84  8b0df0ffa700           -mov ecx, dword ptr [0xa7fff0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11010032) /* 0xa7fff0 */);
    // 00a73d8a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73d8c  7440                   -je 0xa73dce
    if (cpu.flags.zf)
    {
        goto L_0x00a73dce;
    }
    // 00a73d8e  39f1                   +cmp ecx, esi
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
    // 00a73d90  770c                   -ja 0xa73d9e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73d9e;
    }
    // 00a73d92  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a73d94  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a73d96  39f0                   +cmp eax, esi
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
    // 00a73d98  0f878d000000           -ja 0xa73e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e2b;
    }
L_0x00a73d9e:
    // 00a73d9e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a73da0  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a73da3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73da5  7410                   -je 0xa73db7
    if (cpu.flags.zf)
    {
        goto L_0x00a73db7;
    }
    // 00a73da7  39f1                   +cmp ecx, esi
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
    // 00a73da9  770c                   -ja 0xa73db7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73db7;
    }
    // 00a73dab  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a73dad  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a73daf  39f0                   +cmp eax, esi
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
    // 00a73db1  0f8774000000           -ja 0xa73e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e2b;
    }
L_0x00a73db7:
    // 00a73db7  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a73dba  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73dbc  7410                   -je 0xa73dce
    if (cpu.flags.zf)
    {
        goto L_0x00a73dce;
    }
    // 00a73dbe  39f1                   +cmp ecx, esi
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
    // 00a73dc0  770c                   -ja 0xa73dce
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73dce;
    }
    // 00a73dc2  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a73dc4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a73dc6  39f0                   +cmp eax, esi
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
    // 00a73dc8  0f875d000000           -ja 0xa73e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e2b;
    }
L_0x00a73dce:
    // 00a73dce  8b0d7cd1a700           -mov ecx, dword ptr [0xa7d17c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10998140) /* 0xa7d17c */);
    // 00a73dd4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73dd6  7434                   -je 0xa73e0c
    if (cpu.flags.zf)
    {
        goto L_0x00a73e0c;
    }
    // 00a73dd8  39f1                   +cmp ecx, esi
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
    // 00a73dda  7708                   -ja 0xa73de4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73de4;
    }
    // 00a73ddc  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a73dde  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a73de0  39f0                   +cmp eax, esi
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
    // 00a73de2  7747                   -ja 0xa73e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e2b;
    }
L_0x00a73de4:
    // 00a73de4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a73de6  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a73de9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73deb  740c                   -je 0xa73df9
    if (cpu.flags.zf)
    {
        goto L_0x00a73df9;
    }
    // 00a73ded  39f1                   +cmp ecx, esi
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
    // 00a73def  7708                   -ja 0xa73df9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73df9;
    }
    // 00a73df1  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a73df3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a73df5  39f0                   +cmp eax, esi
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
    // 00a73df7  7732                   -ja 0xa73e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e2b;
    }
L_0x00a73df9:
    // 00a73df9  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a73dfc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73dfe  740c                   -je 0xa73e0c
    if (cpu.flags.zf)
    {
        goto L_0x00a73e0c;
    }
    // 00a73e00  39f1                   +cmp ecx, esi
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
    // 00a73e02  7708                   -ja 0xa73e0c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e0c;
    }
    // 00a73e04  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a73e06  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a73e08  39f0                   +cmp eax, esi
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
    // 00a73e0a  771f                   -ja 0xa73e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e2b;
    }
L_0x00a73e0c:
    // 00a73e0c  8b0d78d1a700           -mov ecx, dword ptr [0xa7d178]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */);
    // 00a73e12  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73e14  7455                   -je 0xa73e6b
    if (cpu.flags.zf)
    {
        goto L_0x00a73e6b;
    }
L_0x00a73e16:
    // 00a73e16  39f1                   +cmp ecx, esi
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
    // 00a73e18  7708                   -ja 0xa73e22
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e22;
    }
    // 00a73e1a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00a73e1c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a73e1e  39f0                   +cmp eax, esi
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
    // 00a73e20  7709                   -ja 0xa73e2b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73e2b;
    }
L_0x00a73e22:
    // 00a73e22  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a73e25  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a73e27  75ed                   -jne 0xa73e16
    if (!cpu.flags.zf)
    {
        goto L_0x00a73e16;
    }
    // 00a73e29  eb40                   -jmp 0xa73e6b
    goto L_0x00a73e6b;
L_0x00a73e2b:
    // 00a73e2b  b878d1a700             -mov eax, 0xa7d178
    cpu.eax = 10998136 /*0xa7d178*/;
    // 00a73e30  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a73e32  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a73e38  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a73e3a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a73e3c  e80f180000             -call 0xa75650
    cpu.esp -= 4;
    sub_a75650(app, cpu);
    if (cpu.terminate) return;
    // 00a73e41  8b157cd1a700           -mov edx, dword ptr [0xa7d17c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998140) /* 0xa7d17c */);
    // 00a73e47  890df0ffa700           -mov dword ptr [0xa7fff0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11010032) /* 0xa7fff0 */) = cpu.ecx;
    // 00a73e4d  39d1                   +cmp ecx, edx
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
    // 00a73e4f  7312                   -jae 0xa73e63
    if (!cpu.flags.cf)
    {
        goto L_0x00a73e63;
    }
    // 00a73e51  8b1d80d1a700           -mov ebx, dword ptr [0xa7d180]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10998144) /* 0xa7d180 */);
    // 00a73e57  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00a73e5a  39d8                   +cmp eax, ebx
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
    // 00a73e5c  7605                   -jbe 0xa73e63
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a73e63;
    }
    // 00a73e5e  a380d1a700             -mov dword ptr [0xa7d180], eax
    *app->getMemory<x86::reg32>(x86::reg32(10998144) /* 0xa7d180 */) = cpu.eax;
L_0x00a73e63:
    // 00a73e63  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a73e65  88254006a800           -mov byte ptr [0xa80640], ah
    *app->getMemory<x86::reg8>(x86::reg32(11011648) /* 0xa80640 */) = cpu.ah;
L_0x00a73e6b:
    // 00a73e6b  ff15b8d2a700           -call dword ptr [0xa7d2b8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998456) /* 0xa7d2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a73e71:
    // 00a73e71  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73e72  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73e73  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73e74  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73e75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a73e80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73e80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a73e81(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73e81  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a73e82(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73e82  e9791b0000             -jmp 0xa75a00
    return sub_a75a00(app, cpu);
}

/* align: skip  */
/* data blob: 03fca300574154434f4d20432f432b2b33322052756e2d54696d652073797374656d2e2028632920436f7079726967687420627920574154434f4d20496e7465726e6174696f6e616c20436f72702e20313938382d313939342e20416c6c207269676874732072657365727665642e00000000000000000000 */
void sub_a73f00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73f00  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a73f01  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a73f02  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a73f04  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a73f06  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a73f08  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a73f0a  763c                   -jbe 0xa73f48
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a73f48;
    }
L_0x00a73f0c:
    // 00a73f0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a73f0e  e8cd1d0000             -call 0xa75ce0
    cpu.esp -= 4;
    sub_a75ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a73f13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73f15  7531                   -jne 0xa73f48
    if (!cpu.flags.zf)
    {
        goto L_0x00a73f48;
    }
    // 00a73f17  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a73f19  e8c21d0000             -call 0xa75ce0
    cpu.esp -= 4;
    sub_a75ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a73f1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73f20  7526                   -jne 0xa73f48
    if (!cpu.flags.zf)
    {
        goto L_0x00a73f48;
    }
    // 00a73f22  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a73f24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a73f26  e8f51d0000             -call 0xa75d20
    cpu.esp -= 4;
    sub_a75d20(app, cpu);
    if (cpu.terminate) return;
    // 00a73f2b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a73f2d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73f2f  753d                   -jne 0xa73f6e
    if (!cpu.flags.zf)
    {
        goto L_0x00a73f6e;
    }
    // 00a73f31  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a73f33  e8481e0000             -call 0xa75d80
    cpu.esp -= 4;
    sub_a75d80(app, cpu);
    if (cpu.terminate) return;
    // 00a73f38  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a73f3a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a73f3c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a73f3d  e83e1e0000             -call 0xa75d80
    cpu.esp -= 4;
    sub_a75d80(app, cpu);
    if (cpu.terminate) return;
    // 00a73f42  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a73f44  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a73f46  77c4                   -ja 0xa73f0c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a73f0c;
    }
L_0x00a73f48:
    // 00a73f48  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a73f4a  7620                   -jbe 0xa73f6c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a73f6c;
    }
    // 00a73f4c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a73f4e  e88d1d0000             -call 0xa75ce0
    cpu.esp -= 4;
    sub_a75ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a73f53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73f55  750b                   -jne 0xa73f62
    if (!cpu.flags.zf)
    {
        goto L_0x00a73f62;
    }
    // 00a73f57  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a73f59  e8821d0000             -call 0xa75ce0
    cpu.esp -= 4;
    sub_a75ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a73f5e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a73f60  740a                   -je 0xa73f6c
    if (cpu.flags.zf)
    {
        goto L_0x00a73f6c;
    }
L_0x00a73f62:
    // 00a73f62  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a73f64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a73f66  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a73f68  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a73f6a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a73f6c:
    // 00a73f6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a73f6e:
    // 00a73f6e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73f6f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73f70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a73f80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73f80  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a73f82  742c                   -je 0xa73fb0
    if (cpu.flags.zf)
    {
        goto L_0x00a73fb0;
    }
    // 00a73f84  3810                   -cmp byte ptr [eax], dl
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
L_0x00a73f86:
    // 00a73f86  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 00a73f88  7409                   -je 0xa73f93
    if (cpu.flags.zf)
    {
        goto L_0x00a73f93;
    }
    // 00a73f8a  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a73f8c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a73f8d  c1ca08                 +ror edx, 8
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
    // 00a73f90  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73f91  75f3                   -jne 0xa73f86
    if (!cpu.flags.zf)
    {
        goto L_0x00a73f86;
    }
L_0x00a73f93:
    // 00a73f93  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a73f94  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a73f97  e81b000000             -call 0xa73fb7
    cpu.esp -= 4;
    sub_a73fb7(app, cpu);
    if (cpu.terminate) return;
    // 00a73f9c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a73f9d  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a73fa0  740e                   -je 0xa73fb0
    if (cpu.flags.zf)
    {
        goto L_0x00a73fb0;
    }
    // 00a73fa2  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a73fa4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fa5  7409                   -je 0xa73fb0
    if (cpu.flags.zf)
    {
        goto L_0x00a73fb0;
    }
    // 00a73fa7  887001                 -mov byte ptr [eax + 1], dh
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 00a73faa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fab  7403                   -je 0xa73fb0
    if (cpu.flags.zf)
    {
        goto L_0x00a73fb0;
    }
    // 00a73fad  885002                 -mov byte ptr [eax + 2], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x00a73fb0:
    // 00a73fb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a73fb2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a73fb2  90                     -nop 
    ;
    // 00a73fb3  90                     -nop 
    ;
    // 00a73fb4  90                     -nop 
    ;
    // 00a73fb5  90                     -nop 
    ;
    // 00a73fb6  90                     -nop 
    ;
    // 00a73fb7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a73fb9  7467                   -je 0xa74022
    if (cpu.flags.zf)
    {
        goto L_0x00a74022;
    }
L_0x00a73fbb:
    // 00a73fbb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00a73fbd  7408                   -je 0xa73fc7
    if (cpu.flags.zf)
    {
        goto L_0x00a73fc7;
    }
    // 00a73fbf  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a73fc1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a73fc4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fc5  75f4                   -jne 0xa73fbb
    if (!cpu.flags.zf)
    {
        goto L_0x00a73fbb;
    }
L_0x00a73fc7:
    // 00a73fc7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a73fc8  c1e902                 +shr ecx, 2
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
    // 00a73fcb  743a                   -je 0xa74007
    if (cpu.flags.zf)
    {
        goto L_0x00a74007;
    }
    // 00a73fcd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fce  7429                   -je 0xa73ff9
    if (cpu.flags.zf)
    {
        goto L_0x00a73ff9;
    }
L_0x00a73fd0:
    // 00a73fd0  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a73fd2  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a73fd5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fd6  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a73fd9  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a73fdc  7418                   -je 0xa73ff6
    if (cpu.flags.zf)
    {
        goto L_0x00a73ff6;
    }
    // 00a73fde  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 00a73fe1  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a73fe4  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a73fe7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fe8  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a73feb  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a73fee  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a73ff1  75dd                   -jne 0xa73fd0
    if (!cpu.flags.zf)
    {
        goto L_0x00a73fd0;
    }
    // 00a73ff3  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00a73ff6:
    // 00a73ff6  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a73ff9:
    // 00a73ff9  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a73ffb  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a73ffe  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a74001  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a74004  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a74007:
    // 00a74007  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74008  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a7400b  7415                   -je 0xa74022
    if (cpu.flags.zf)
    {
        goto L_0x00a74022;
    }
    // 00a7400d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a7400f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a74012  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74013  740d                   -je 0xa74022
    if (cpu.flags.zf)
    {
        goto L_0x00a74022;
    }
    // 00a74015  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a74017  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a7401a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a7401b  7405                   -je 0xa74022
    if (cpu.flags.zf)
    {
        goto L_0x00a74022;
    }
    // 00a7401d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a7401f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00a74022:
    // 00a74022  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a73fb7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a73fb7;
    // 00a73fb2  90                     -nop 
    ;
    // 00a73fb3  90                     -nop 
    ;
    // 00a73fb4  90                     -nop 
    ;
    // 00a73fb5  90                     -nop 
    ;
    // 00a73fb6  90                     -nop 
    ;
L_entry_0x00a73fb7:
    // 00a73fb7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00a73fb9  7467                   -je 0xa74022
    if (cpu.flags.zf)
    {
        goto L_0x00a74022;
    }
L_0x00a73fbb:
    // 00a73fbb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 00a73fbd  7408                   -je 0xa73fc7
    if (cpu.flags.zf)
    {
        goto L_0x00a73fc7;
    }
    // 00a73fbf  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a73fc1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a73fc4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fc5  75f4                   -jne 0xa73fbb
    if (!cpu.flags.zf)
    {
        goto L_0x00a73fbb;
    }
L_0x00a73fc7:
    // 00a73fc7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a73fc8  c1e902                 +shr ecx, 2
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
    // 00a73fcb  743a                   -je 0xa74007
    if (cpu.flags.zf)
    {
        goto L_0x00a74007;
    }
    // 00a73fcd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fce  7429                   -je 0xa73ff9
    if (cpu.flags.zf)
    {
        goto L_0x00a73ff9;
    }
L_0x00a73fd0:
    // 00a73fd0  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a73fd2  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a73fd5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fd6  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a73fd9  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a73fdc  7418                   -je 0xa73ff6
    if (cpu.flags.zf)
    {
        goto L_0x00a73ff6;
    }
    // 00a73fde  385020                 +cmp byte ptr [eax + 0x20], dl
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
    // 00a73fe1  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00a73fe4  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00a73fe7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a73fe8  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a73feb  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00a73fee  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a73ff1  75dd                   -jne 0xa73fd0
    if (!cpu.flags.zf)
    {
        goto L_0x00a73fd0;
    }
    // 00a73ff3  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x00a73ff6:
    // 00a73ff6  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a73ff9:
    // 00a73ff9  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a73ffb  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a73ffe  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a74001  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a74004  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x00a74007:
    // 00a74007  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74008  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 00a7400b  7415                   -je 0xa74022
    if (cpu.flags.zf)
    {
        goto L_0x00a74022;
    }
    // 00a7400d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a7400f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a74012  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74013  740d                   -je 0xa74022
    if (cpu.flags.zf)
    {
        goto L_0x00a74022;
    }
    // 00a74015  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a74017  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a7401a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a7401b  7405                   -je 0xa74022
    if (cpu.flags.zf)
    {
        goto L_0x00a74022;
    }
    // 00a7401d  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a7401f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00a74022:
    // 00a74022  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a74030(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74030  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a74031  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a74033  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a74035  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a74037  e8741d0000             -call 0xa75db0
    cpu.esp -= 4;
    sub_a75db0(app, cpu);
    if (cpu.terminate) return;
    // 00a7403c  ff4310                 -inc dword ptr [ebx + 0x10]
    (*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */))++;
    // 00a7403f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74040  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a74044(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74044  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74045  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74046  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74047  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74048  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7404a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a7404d  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74053  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a74056  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a74059  83f901                 +cmp ecx, 1
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
    // 00a7405c  741b                   -je 0xa74079
    if (cpu.flags.zf)
    {
        goto L_0x00a74079;
    }
    // 00a7405e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a74060  7410                   -je 0xa74072
    if (cpu.flags.zf)
    {
        goto L_0x00a74072;
    }
    // 00a74062  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a74065  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7406b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7406d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7406e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7406f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74070  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74071  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74072:
    // 00a74072  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a74079:
    // 00a74079  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a7407c  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 00a7407f  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a74082  88660c                 -mov byte ptr [esi + 0xc], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 00a74085  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a74088  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7408b  83e530                 -and ebp, 0x30
    cpu.ebp &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a7408e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a74090  7507                   -jne 0xa74099
    if (!cpu.flags.zf)
    {
        goto L_0x00a74099;
    }
    // 00a74092  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a74094  e8371e0000             -call 0xa75ed0
    cpu.esp -= 4;
    sub_a75ed0(app, cpu);
    if (cpu.terminate) return;
L_0x00a74099:
    // 00a74099  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00a7409c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a7409e  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 00a740a1  7414                   -je 0xa740b7
    if (cpu.flags.zf)
    {
        goto L_0x00a740b7;
    }
    // 00a740a3  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a740a5  80e5fa                 -and ch, 0xfa
    cpu.ch &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00a740a8  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 00a740aa  886e0d                 -mov byte ptr [esi + 0xd], ch
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00a740ad  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a740af  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a740b4  88460d                 -mov byte ptr [esi + 0xd], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x00a740b7:
    // 00a740b7  b93040a700             -mov ecx, 0xa74030
    cpu.ecx = 10960944 /*0xa74030*/;
    // 00a740bc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a740be  e8ad060000             -call 0xa74770
    cpu.esp -= 4;
    sub_a74770(app, cpu);
    if (cpu.terminate) return;
    // 00a740c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a740c5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a740c7  7418                   -je 0xa740e1
    if (cpu.flags.zf)
    {
        goto L_0x00a740e1;
    }
    // 00a740c9  8a660d                 -mov ah, byte ptr [esi + 0xd]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 00a740cc  80e4fa                 -and ah, 0xfa
    cpu.ah &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 00a740cf  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 00a740d1  88660d                 -mov byte ptr [esi + 0xd], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00a740d4  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a740d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a740d9  885e0d                 -mov byte ptr [esi + 0xd], bl
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00a740dc  e83f010000             -call 0xa74220
    cpu.esp -= 4;
    sub_a74220(app, cpu);
    if (cpu.terminate) return;
L_0x00a740e1:
    // 00a740e1  f6460c20               +test byte ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 00a740e5  7405                   -je 0xa740ec
    if (cpu.flags.zf)
    {
        goto L_0x00a740ec;
    }
    // 00a740e7  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x00a740ec:
    // 00a740ec  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a740ef  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a740f1  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a740f4  897e0c                 -mov dword ptr [esi + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00a740f7  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a740fd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a740ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74100  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74101  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74102  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74103  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a74110(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74110  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a74111  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74112  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a74113  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74114  8a25a1cfa700           -mov ah, byte ptr [0xa7cfa1]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(10997665) /* 0xa7cfa1 */);
    // 00a7411a  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a7411d  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 00a7411f  8825a1cfa700           -mov byte ptr [0xa7cfa1], ah
    *app->getMemory<x86::reg8>(x86::reg32(10997665) /* 0xa7cfa1 */) = cpu.ah;
    // 00a74125  80ca04                 -or dl, 4
    cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a74128  8815a1cfa700           -mov byte ptr [0xa7cfa1], dl
    *app->getMemory<x86::reg8>(x86::reg32(10997665) /* 0xa7cfa1 */) = cpu.dl;
    // 00a7412e  8b156ccfa700           -mov edx, dword ptr [0xa7cf6c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10997612) /* 0xa7cf6c */);
    // 00a74134  bb60cfa700             -mov ebx, 0xa7cf60
    cpu.ebx = 10997600 /*0xa7cf60*/;
    // 00a74139  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7413b  7466                   -je 0xa741a3
    if (cpu.flags.zf)
    {
        goto L_0x00a741a3;
    }
L_0x00a7413d:
    // 00a7413d  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a74142  e839fbffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a74147  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a74149  7521                   -jne 0xa7416c
    if (!cpu.flags.zf)
    {
        goto L_0x00a7416c;
    }
    // 00a7414b  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a74150  e82bfbffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a74155  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a74157  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a74159  7513                   -jne 0xa7416e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7416e;
    }
    // 00a7415b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a74160  b82cdda700             -mov eax, 0xa7dd2c
    cpu.eax = 11001132 /*0xa7dd2c*/;
    // 00a74165  e8321e0000             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a7416a  eb02                   -jmp 0xa7416e
    goto L_0x00a7416e;
L_0x00a7416c:
    // 00a7416c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00a7416e:
    // 00a7416e  a1e0ffa700             -mov eax, dword ptr [0xa7ffe0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */);
    // 00a74173  895904                 -mov dword ptr [ecx + 4], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a74176  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a74178  894b08                 -mov dword ptr [ebx + 8], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a7417b  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a74182  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a74185  c6401400               -mov byte ptr [eax + 0x14], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a74189  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a7418c  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a74193  890de0ffa700           -mov dword ptr [0xa7ffe0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */) = cpu.ecx;
    // 00a74199  8b4b26                 -mov ecx, dword ptr [ebx + 0x26]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(38) /* 0x26 */);
    // 00a7419c  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 00a7419f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a741a1  759a                   -jne 0xa7413d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7413d;
    }
L_0x00a741a3:
    // 00a741a3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a741a5  8935e4ffa700           -mov dword ptr [0xa7ffe4], esi
    *app->getMemory<x86::reg32>(x86::reg32(11010020) /* 0xa7ffe4 */) = cpu.esi;
    // 00a741ab  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a741ac  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a741ad  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a741ae  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a741af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a741b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a741b0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a741b2  e80d000000             -call 0xa741c4
    cpu.esp -= 4;
    sub_a741c4(app, cpu);
    if (cpu.terminate) return;
    // 00a741b7  e9041f0000             -jmp 0xa760c0
    return sub_a760c0(app, cpu);
}

/* align: skip  */
void sub_a741bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a741bc  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a741c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a741c4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a741c5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a741c6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a741c7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a741c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a741ca  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a741cd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a741cf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a741d2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a741d4  be60cfa700             -mov esi, 0xa7cf60
    cpu.esi = 10997600 /*0xa7cf60*/;
    // 00a741d9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a741db  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a741dd  a1e0ffa700             -mov eax, dword ptr [0xa7ffe0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */);
    // 00a741e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a741e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a741e6  742f                   -je 0xa74217
    if (cpu.flags.zf)
    {
        goto L_0x00a74217;
    }
L_0x00a741e8:
    // 00a741e8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a741ea  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a741ed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a741f2  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00a741f6  7513                   -jne 0xa7420b
    if (!cpu.flags.zf)
    {
        goto L_0x00a7420b;
    }
    // 00a741f8  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a741fc  750d                   -jne 0xa7420b
    if (!cpu.flags.zf)
    {
        goto L_0x00a7420b;
    }
    // 00a741fe  39f0                   +cmp eax, esi
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
    // 00a74200  720f                   -jb 0xa74211
    if (cpu.flags.cf)
    {
        goto L_0x00a74211;
    }
    // 00a74202  3daecfa700             +cmp eax, 0xa7cfae
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10997678 /*0xa7cfae*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74207  7302                   -jae 0xa7420b
    if (!cpu.flags.cf)
    {
        goto L_0x00a7420b;
    }
    // 00a74209  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a7420b:
    // 00a7420b  e8241f0000             -call 0xa76134
    cpu.esp -= 4;
    sub_a76134(app, cpu);
    if (cpu.terminate) return;
    // 00a74210  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a74211:
    // 00a74211  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a74213  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a74215  75d1                   -jne 0xa741e8
    if (!cpu.flags.zf)
    {
        goto L_0x00a741e8;
    }
L_0x00a74217:
    // 00a74217  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a74219  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7421a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7421b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7421c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7421d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a741c4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a741c4;
    // 00a741bc  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00a741c1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a741c4:
    // 00a741c4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a741c5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a741c6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a741c7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a741c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a741ca  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a741cd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a741cf  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a741d2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a741d4  be60cfa700             -mov esi, 0xa7cf60
    cpu.esi = 10997600 /*0xa7cf60*/;
    // 00a741d9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a741db  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a741dd  a1e0ffa700             -mov eax, dword ptr [0xa7ffe0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */);
    // 00a741e2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a741e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a741e6  742f                   -je 0xa74217
    if (cpu.flags.zf)
    {
        goto L_0x00a74217;
    }
L_0x00a741e8:
    // 00a741e8  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a741ea  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a741ed  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a741f2  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 00a741f6  7513                   -jne 0xa7420b
    if (!cpu.flags.zf)
    {
        goto L_0x00a7420b;
    }
    // 00a741f8  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a741fc  750d                   -jne 0xa7420b
    if (!cpu.flags.zf)
    {
        goto L_0x00a7420b;
    }
    // 00a741fe  39f0                   +cmp eax, esi
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
    // 00a74200  720f                   -jb 0xa74211
    if (cpu.flags.cf)
    {
        goto L_0x00a74211;
    }
    // 00a74202  3daecfa700             +cmp eax, 0xa7cfae
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10997678 /*0xa7cfae*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74207  7302                   -jae 0xa7420b
    if (!cpu.flags.cf)
    {
        goto L_0x00a7420b;
    }
    // 00a74209  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a7420b:
    // 00a7420b  e8241f0000             -call 0xa76134
    cpu.esp -= 4;
    sub_a76134(app, cpu);
    if (cpu.terminate) return;
    // 00a74210  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a74211:
    // 00a74211  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a74213  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a74215  75d1                   -jne 0xa741e8
    if (!cpu.flags.zf)
    {
        goto L_0x00a741e8;
    }
L_0x00a74217:
    // 00a74217  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a74219  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7421a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7421b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7421c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7421d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a74220(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74220  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a74221  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74222  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a74223  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74224  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74225  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74226  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a74228  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00a7422b  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74231  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 00a74234  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a74236  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00a74239  0f847a000000           -je 0xa742b9
    if (cpu.flags.zf)
    {
        goto L_0x00a742b9;
    }
    // 00a7423f  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 00a74241  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a74244  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a74247  88790d                 -mov byte ptr [ecx + 0xd], bh
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 00a7424a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a7424c  0f84a2000000           -je 0xa742f4
    if (cpu.flags.zf)
    {
        goto L_0x00a742f4;
    }
    // 00a74252  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a74255  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00a74258  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7425a  0f8494000000           -je 0xa742f4
    if (cpu.flags.zf)
    {
        goto L_0x00a742f4;
    }
    // 00a74260  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a74263  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a74265  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a74267  0f8487000000           -je 0xa742f4
    if (cpu.flags.zf)
    {
        goto L_0x00a742f4;
    }
L_0x00a7426d:
    // 00a7426d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a7426f  0f857f000000           -jne 0xa742f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a742f4;
    }
    // 00a74275  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a74277  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a74279  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a7427c  e84f200000             -call 0xa762d0
    cpu.esp -= 4;
    sub_a762d0(app, cpu);
    if (cpu.terminate) return;
    // 00a74281  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a74283  83f8ff                 +cmp eax, -1
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
    // 00a74286  750d                   -jne 0xa74295
    if (!cpu.flags.zf)
    {
        goto L_0x00a74295;
    }
    // 00a74288  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a7428b  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 00a7428e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a74290  88590c                 -mov byte ptr [ecx + 0xc], bl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 00a74293  eb1c                   -jmp 0xa742b1
    goto L_0x00a742b1;
L_0x00a74295:
    // 00a74295  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a74297  7518                   -jne 0xa742b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a742b1;
    }
    // 00a74299  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00a7429e  e81d210000             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a742a3  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a742a6  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a742a9  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 00a742ae  88610c                 -mov byte ptr [ecx + 0xc], ah
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x00a742b1:
    // 00a742b1  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a742b3  29d6                   +sub esi, edx
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
    // 00a742b5  75b6                   -jne 0xa7426d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7426d;
    }
    // 00a742b7  eb3b                   -jmp 0xa742f4
    goto L_0x00a742f4;
L_0x00a742b9:
    // 00a742b9  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a742bc  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a742c0  7432                   -je 0xa742f4
    if (cpu.flags.zf)
    {
        goto L_0x00a742f4;
    }
    // 00a742c2  80610cef               -and byte ptr [ecx + 0xc], 0xef
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 00a742c6  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00a742ca  7528                   -jne 0xa742f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a742f4;
    }
    // 00a742cc  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a742cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a742d1  7411                   -je 0xa742e4
    if (cpu.flags.zf)
    {
        goto L_0x00a742e4;
    }
    // 00a742d3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a742d5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a742da  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a742dc  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a742df  e83c210000             -call 0xa76420
    cpu.esp -= 4;
    sub_a76420(app, cpu);
    if (cpu.terminate) return;
L_0x00a742e4:
    // 00a742e4  83f8ff                 +cmp eax, -1
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
    // 00a742e7  750b                   -jne 0xa742f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a742f4;
    }
    // 00a742e9  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a742ec  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a742ef  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a742f1  88590c                 -mov byte ptr [ecx + 0xc], bl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x00a742f4:
    // 00a742f4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a742f7  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a742fa  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a74301  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a74303  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a74305  7518                   -jne 0xa7431f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7431f;
    }
    // 00a74307  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7430a  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 00a7430e  740f                   -je 0xa7431f
    if (cpu.flags.zf)
    {
        goto L_0x00a7431f;
    }
    // 00a74310  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a74313  e888210000             -call 0xa764a0
    cpu.esp -= 4;
    sub_a764a0(app, cpu);
    if (cpu.terminate) return;
    // 00a74318  83f8ff                 +cmp eax, -1
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
    // 00a7431b  7502                   -jne 0xa7431f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7431f;
    }
    // 00a7431d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00a7431f:
    // 00a7431f  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a74322  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74328  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7432a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7432b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7432c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7432d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7432e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7432f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74330  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a74340(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74340  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a74345  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a74348  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a74349  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7434a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7434b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7434d  ff15a8d2a700           -call dword ptr [0xa7d2a8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998440) /* 0xa7d2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74353  8b15e0ffa700           -mov edx, dword ptr [0xa7ffe0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */);
    // 00a74359  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7435b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7435d  741a                   -je 0xa74379
    if (cpu.flags.zf)
    {
        goto L_0x00a74379;
    }
L_0x00a7435f:
    // 00a7435f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a74362  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 00a74365  740c                   -je 0xa74373
    if (cpu.flags.zf)
    {
        goto L_0x00a74373;
    }
    // 00a74367  43                     -inc ebx
    (cpu.ebx)++;
    // 00a74368  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a7436c  7405                   -je 0xa74373
    if (cpu.flags.zf)
    {
        goto L_0x00a74373;
    }
    // 00a7436e  e8adfeffff             -call 0xa74220
    cpu.esp -= 4;
    sub_a74220(app, cpu);
    if (cpu.terminate) return;
L_0x00a74373:
    // 00a74373  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a74375  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a74377  75e6                   -jne 0xa7435f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7435f;
    }
L_0x00a74379:
    // 00a74379  ff15acd2a700           -call dword ptr [0xa7d2ac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7437f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a74381  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74382  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74383  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74384  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a74390(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74390  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74396  05da000000             -add eax, 0xda
    (cpu.eax) += x86::reg32(x86::sreg32(218 /*0xda*/));
    // 00a7439b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7439c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7439c  a11c00a800             -mov eax, dword ptr [0xa8001c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11010076) /* 0xa8001c */);
    // 00a743a1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a743a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a743a4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a743a4;
    // 00a7439c  a11c00a800             -mov eax, dword ptr [0xa8001c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11010076) /* 0xa8001c */);
    // 00a743a1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a743a4:
    // 00a743a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a743a8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a743a8  e9a7210000             -jmp 0xa76554
    return sub_a76554(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a743b0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a743b0  e9f7220000             -jmp 0xa766ac
    return sub_a766ac(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a743b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a743b8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a743b9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a743ba  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a743bb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a743bd  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a743bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a743c1  89351000a800           -mov dword ptr [0xa80010], esi
    *app->getMemory<x86::reg32>(x86::reg32(11010064) /* 0xa80010 */) = cpu.esi;
    // 00a743c7  e870260000             -call 0xa76a3c
    cpu.esp -= 4;
    sub_a76a3c(app, cpu);
    if (cpu.terminate) return;
    // 00a743cc  a31c00a800             -mov dword ptr [0xa8001c], eax
    *app->getMemory<x86::reg32>(x86::reg32(11010076) /* 0xa8001c */) = cpu.eax;
    // 00a743d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a743d3  7511                   -jne 0xa743e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a743e6;
    }
    // 00a743d5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a743d7  0f8505020000           -jne 0xa745e2
    if (!cpu.flags.zf)
    {
        goto L_0x00a745e2;
    }
    // 00a743dd  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a743df  2eff15a4bda700         -call dword ptr cs:[0xa7bda4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993060) /* 0xa7bda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a743e6:
    // 00a743e6  e8f5220000             -call 0xa766e0
    cpu.esp -= 4;
    sub_a766e0(app, cpu);
    if (cpu.terminate) return;
    // 00a743eb  2eff15d4bda700         -call dword ptr cs:[0xa7bdd4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993108) /* 0xa7bdd4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a743f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a743f4  a369d3a700             -mov dword ptr [0xa7d369], eax
    *app->getMemory<x86::reg32>(x86::reg32(10998633) /* 0xa7d369 */) = cpu.eax;
    // 00a743f9  89150400a800           -mov dword ptr [0xa80004], edx
    *app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */) = cpu.edx;
    // 00a743ff  2eff1504bea700         -call dword ptr cs:[0xa7be04]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993156) /* 0xa7be04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74406  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a74408  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7440a  a26fd3a700             -mov byte ptr [0xa7d36f], al
    *app->getMemory<x86::reg8>(x86::reg32(10998639) /* 0xa7d36f */) = cpu.al;
    // 00a7440f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a74412  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a74417  6804010000             -push 0x104
    *app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a7441c  66a371d3a700           -mov word ptr [0xa7d371], ax
    *app->getMemory<x86::reg16>(x86::reg32(10998641) /* 0xa7d371 */) = cpu.ax;
    // 00a74422  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a74424  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a7442a  66a171d3a700           -mov ax, word ptr [0xa7d371]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(10998641) /* 0xa7d371 */);
    // 00a74430  682000a800             -push 0xa80020
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11010080 /*0xa80020*/;
    cpu.esp -= 4;
    // 00a74435  a373d3a700             -mov dword ptr [0xa7d373], eax
    *app->getMemory<x86::reg32>(x86::reg32(10998643) /* 0xa7d373 */) = cpu.eax;
    // 00a7443a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7443c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 00a7443f  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a74441  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a74447  a377d3a700             -mov dword ptr [0xa7d377], eax
    *app->getMemory<x86::reg32>(x86::reg32(10998647) /* 0xa7d377 */) = cpu.eax;
    // 00a7444c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7444e  881570d3a700           -mov byte ptr [0xa7d370], dl
    *app->getMemory<x86::reg8>(x86::reg32(10998640) /* 0xa7d370 */) = cpu.dl;
    // 00a74454  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a74456  8b1577d3a700           -mov edx, dword ptr [0xa7d377]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998647) /* 0xa7d377 */);
    // 00a7445c  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7445e  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a74461  bb2000a800             -mov ebx, 0xa80020
    cpu.ebx = 11010080 /*0xa80020*/;
    // 00a74466  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a74468  a37bd3a700             -mov dword ptr [0xa7d37b], eax
    *app->getMemory<x86::reg32>(x86::reg32(10998651) /* 0xa7d37b */) = cpu.eax;
    // 00a7446d  89157fd3a700           -mov dword ptr [0xa7d37f], edx
    *app->getMemory<x86::reg32>(x86::reg32(10998655) /* 0xa7d37f */) = cpu.edx;
    // 00a74473  2eff15e8bda700         -call dword ptr cs:[0xa7bde8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993128) /* 0xa7bde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7447a  ba2401a800             -mov edx, 0xa80124
    cpu.edx = 11010340 /*0xa80124*/;
    // 00a7447f  891d30d3a700           -mov dword ptr [0xa7d330], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10998576) /* 0xa7d330 */) = cpu.ebx;
    // 00a74485  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a74487  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a7448c  b92401a800             -mov ecx, 0xa80124
    cpu.ecx = 11010340 /*0xa80124*/;
    // 00a74491  e8ba280000             -call 0xa76d50
    cpu.esp -= 4;
    sub_a76d50(app, cpu);
    if (cpu.terminate) return;
    // 00a74496  890d3cd3a700           -mov dword ptr [0xa7d33c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10998588) /* 0xa7d33c */) = cpu.ecx;
    // 00a7449c  2eff15bcbda700         -call dword ptr cs:[0xa7bdbc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993084) /* 0xa7bdbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a744a3  e848290000             -call 0xa76df0
    cpu.esp -= 4;
    sub_a76df0(app, cpu);
    if (cpu.terminate) return;
    // 00a744a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a744aa  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a744ac  a31400a800             -mov dword ptr [0xa80014], eax
    *app->getMemory<x86::reg32>(x86::reg32(11010068) /* 0xa80014 */) = cpu.eax;
    // 00a744b1  80fb22                 +cmp bl, 0x22
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
    // 00a744b4  751e                   -jne 0xa744d4
    if (!cpu.flags.zf)
    {
        goto L_0x00a744d4;
    }
    // 00a744b6  8a7801                 -mov bh, byte ptr [eax + 1]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a744b9  40                     -inc eax
    (cpu.eax)++;
    // 00a744ba  38df                   +cmp bh, bl
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
    // 00a744bc  740e                   -je 0xa744cc
    if (cpu.flags.zf)
    {
        goto L_0x00a744cc;
    }
L_0x00a744be:
    // 00a744be  803800                 +cmp byte ptr [eax], 0
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
    // 00a744c1  7409                   -je 0xa744cc
    if (cpu.flags.zf)
    {
        goto L_0x00a744cc;
    }
    // 00a744c3  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a744c6  40                     -inc eax
    (cpu.eax)++;
    // 00a744c7  80fa22                 +cmp dl, 0x22
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
    // 00a744ca  75f2                   -jne 0xa744be
    if (!cpu.flags.zf)
    {
        goto L_0x00a744be;
    }
L_0x00a744cc:
    // 00a744cc  803800                 +cmp byte ptr [eax], 0
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
    // 00a744cf  741e                   -je 0xa744ef
    if (cpu.flags.zf)
    {
        goto L_0x00a744ef;
    }
    // 00a744d1  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a744d2  eb1b                   -jmp 0xa744ef
    goto L_0x00a744ef;
L_0x00a744d4:
    // 00a744d4  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a744d6  fec2                   -inc dl
    (cpu.dl)++;
    // 00a744d8  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a744de  f6828cd1a70002         +test byte ptr [edx + 0xa7d18c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10998156) /* 0xa7d18c */) & 2 /*0x2*/));
    // 00a744e5  7508                   -jne 0xa744ef
    if (!cpu.flags.zf)
    {
        goto L_0x00a744ef;
    }
    // 00a744e7  803800                 +cmp byte ptr [eax], 0
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
    // 00a744ea  7403                   -je 0xa744ef
    if (cpu.flags.zf)
    {
        goto L_0x00a744ef;
    }
    // 00a744ec  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a744ed  ebe5                   -jmp 0xa744d4
    goto L_0x00a744d4;
L_0x00a744ef:
    // 00a744ef  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a744f1  fec2                   -inc dl
    (cpu.dl)++;
    // 00a744f3  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a744f9  f6828cd1a70002         +test byte ptr [edx + 0xa7d18c], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10998156) /* 0xa7d18c */) & 2 /*0x2*/));
    // 00a74500  7403                   -je 0xa74505
    if (cpu.flags.zf)
    {
        goto L_0x00a74505;
    }
    // 00a74502  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74503  ebea                   -jmp 0xa744ef
    goto L_0x00a744ef;
L_0x00a74505:
    // 00a74505  a32cd3a700             -mov dword ptr [0xa7d32c], eax
    *app->getMemory<x86::reg32>(x86::reg32(10998572) /* 0xa7d32c */) = cpu.eax;
    // 00a7450a  2eff15c0bda700         -call dword ptr cs:[0xa7bdc0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993088) /* 0xa7bdc0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74511  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a74513  0f847d000000           -je 0xa74596
    if (cpu.flags.zf)
    {
        goto L_0x00a74596;
    }
    // 00a74519  e822290000             -call 0xa76e40
    cpu.esp -= 4;
    sub_a76e40(app, cpu);
    if (cpu.terminate) return;
    // 00a7451e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a74520  668b18                 -mov bx, word ptr [eax]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.eax);
    // 00a74523  a31800a800             -mov dword ptr [0xa80018], eax
    *app->getMemory<x86::reg32>(x86::reg32(11010072) /* 0xa80018 */) = cpu.eax;
    // 00a74528  6683fb22               +cmp bx, 0x22
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
    // 00a7452c  752a                   -jne 0xa74558
    if (!cpu.flags.zf)
    {
        goto L_0x00a74558;
    }
    // 00a7452e  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a74532  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a74535  6639d9                 +cmp cx, bx
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
    // 00a74538  7413                   -je 0xa7454d
    if (cpu.flags.zf)
    {
        goto L_0x00a7454d;
    }
L_0x00a7453a:
    // 00a7453a  66833800               +cmp word ptr [eax], 0
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
    // 00a7453e  740d                   -je 0xa7454d
    if (cpu.flags.zf)
    {
        goto L_0x00a7454d;
    }
    // 00a74540  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a74544  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a74547  6683fb22               +cmp bx, 0x22
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
    // 00a7454b  75ed                   -jne 0xa7453a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7453a;
    }
L_0x00a7454d:
    // 00a7454d  66833800               +cmp word ptr [eax], 0
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
    // 00a74551  7427                   -je 0xa7457a
    if (cpu.flags.zf)
    {
        goto L_0x00a7457a;
    }
    // 00a74553  83c002                 +add eax, 2
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
    // 00a74556  eb22                   -jmp 0xa7457a
    goto L_0x00a7457a;
L_0x00a74558:
    // 00a74558  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x00a7455d:
    // 00a7455d  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a7455f  fec2                   -inc dl
    (cpu.dl)++;
    // 00a74561  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a74567  849a8cd1a700           -test byte ptr [edx + 0xa7d18c], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10998156) /* 0xa7d18c */) & cpu.bl));
    // 00a7456d  750b                   -jne 0xa7457a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7457a;
    }
    // 00a7456f  66833800               +cmp word ptr [eax], 0
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
    // 00a74573  7405                   -je 0xa7457a
    if (cpu.flags.zf)
    {
        goto L_0x00a7457a;
    }
    // 00a74575  83c002                 +add eax, 2
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
    // 00a74578  ebe3                   -jmp 0xa7455d
    goto L_0x00a7455d;
L_0x00a7457a:
    // 00a7457a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
L_0x00a7457f:
    // 00a7457f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a74581  fec2                   -inc dl
    (cpu.dl)++;
    // 00a74583  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a74589  849a8cd1a700           -test byte ptr [edx + 0xa7d18c], bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10998156) /* 0xa7d18c */) & cpu.bl));
    // 00a7458f  740a                   -je 0xa7459b
    if (cpu.flags.zf)
    {
        goto L_0x00a7459b;
    }
    // 00a74591  83c002                 +add eax, 2
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
    // 00a74594  ebe9                   -jmp 0xa7457f
    goto L_0x00a7457f;
L_0x00a74596:
    // 00a74596  b85cdda700             -mov eax, 0xa7dd5c
    cpu.eax = 11001180 /*0xa7dd5c*/;
L_0x00a7459b:
    // 00a7459b  a338d3a700             -mov dword ptr [0xa7d338], eax
    *app->getMemory<x86::reg32>(x86::reg32(10998584) /* 0xa7d338 */) = cpu.eax;
    // 00a745a0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a745a2  7439                   -je 0xa745dd
    if (cpu.flags.zf)
    {
        goto L_0x00a745dd;
    }
    // 00a745a4  6804010000             -push 0x104
    *app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a745a9  682c03a800             -push 0xa8032c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 11010860 /*0xa8032c*/;
    cpu.esp -= 4;
    // 00a745ae  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a745af  be2c03a800             -mov esi, 0xa8032c
    cpu.esi = 11010860 /*0xa8032c*/;
    // 00a745b4  bb08020000             -mov ebx, 0x208
    cpu.ebx = 520 /*0x208*/;
    // 00a745b9  2eff15e8bda700         -call dword ptr cs:[0xa7bde8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993128) /* 0xa7bde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a745c0  ba3004a800             -mov edx, 0xa80430
    cpu.edx = 11011120 /*0xa80430*/;
    // 00a745c5  893534d3a700           -mov dword ptr [0xa7d334], esi
    *app->getMemory<x86::reg32>(x86::reg32(10998580) /* 0xa7d334 */) = cpu.esi;
    // 00a745cb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a745cd  bf3004a800             -mov edi, 0xa80430
    cpu.edi = 11011120 /*0xa80430*/;
    // 00a745d2  e879270000             -call 0xa76d50
    cpu.esp -= 4;
    sub_a76d50(app, cpu);
    if (cpu.terminate) return;
    // 00a745d7  893d40d3a700           -mov dword ptr [0xa7d340], edi
    *app->getMemory<x86::reg32>(x86::reg32(10998592) /* 0xa7d340 */) = cpu.edi;
L_0x00a745dd:
    // 00a745dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a745e2:
    // 00a745e2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a745e3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a745e4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a745e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a745e8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a745e8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a745e9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a745ea  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a745eb  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a745ec  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a745ee  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a745f0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a745f2  2eff15f0bda700         -call dword ptr cs:[0xa7bdf0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993136) /* 0xa7bdf0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a745f9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a745fb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a745fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a745ff  e8b4fdffff             -call 0xa743b8
    cpu.esp -= 4;
    sub_a743b8(app, cpu);
    if (cpu.terminate) return;
    // 00a74604  ba4cd3a700             -mov edx, 0xa7d34c
    cpu.edx = 10998604 /*0xa7d34c*/;
    // 00a74609  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7460f  e85c280000             -call 0xa76e70
    cpu.esp -= 4;
    sub_a76e70(app, cpu);
    if (cpu.terminate) return;
    // 00a74614  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a74616  e8052d0000             -call 0xa77320
    cpu.esp -= 4;
    sub_a77320(app, cpu);
    if (cpu.terminate) return;
    // 00a7461b  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00a74620  e8a7000000             -call 0xa746cc
    cpu.esp -= 4;
    sub_a746cc(app, cpu);
    if (cpu.terminate) return;
    // 00a74625  ff15d4d2a700           -call dword ptr [0xa7d2d4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998484) /* 0xa7d2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7462b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00a74630  e897000000             -call 0xa746cc
    cpu.esp -= 4;
    sub_a746cc(app, cpu);
    if (cpu.terminate) return;
    // 00a74635  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74636  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74637  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74638  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74639  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7463c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7463c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7463e  833d1000a80000         +cmp dword ptr [0xa80010], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11010064) /* 0xa80010 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74645  7418                   -je 0xa7465f
    if (cpu.flags.zf)
    {
        goto L_0x00a7465f;
    }
    // 00a74647  833ddcd2a70000         +cmp dword ptr [0xa7d2dc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10998492) /* 0xa7d2dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7464e  7426                   -je 0xa74676
    if (cpu.flags.zf)
    {
        goto L_0x00a74676;
    }
    // 00a74650  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a74655  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a74657  ff15dcd2a700           -call dword ptr [0xa7d2dc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998492) /* 0xa7d2dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7465d  eb17                   -jmp 0xa74676
    goto L_0x00a74676;
L_0x00a7465f:
    // 00a7465f  e8082d0000             -call 0xa7736c
    cpu.esp -= 4;
    sub_a7736c(app, cpu);
    if (cpu.terminate) return;
    // 00a74664  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a74669  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7466b  e8ac000000             -call 0xa7471c
    cpu.esp -= 4;
    sub_a7471c(app, cpu);
    if (cpu.terminate) return;
    // 00a74670  ff15d0d2a700           -call dword ptr [0xa7d2d0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998480) /* 0xa7d2d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a74676:
    // 00a74676  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a74677  2eff15a4bda700         -call dword ptr cs:[0xa7bda4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993060) /* 0xa7bda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7467e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a74680  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a74681  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74682  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a74683  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74684  8b151400a800           -mov edx, dword ptr [0xa80014]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11010068) /* 0xa80014 */);
    // 00a7468a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7468c  740f                   -je 0xa7469d
    if (cpu.flags.zf)
    {
        goto L_0x00a7469d;
    }
    // 00a7468e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a74690  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a74692  e8d9f6ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a74697  891d1400a800           -mov dword ptr [0xa80014], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11010068) /* 0xa80014 */) = cpu.ebx;
L_0x00a7469d:
    // 00a7469d  8b0d1800a800           -mov ecx, dword ptr [0xa80018]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11010072) /* 0xa80018 */);
    // 00a746a3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a746a5  740f                   -je 0xa746b6
    if (cpu.flags.zf)
    {
        goto L_0x00a746b6;
    }
    // 00a746a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a746a9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a746ab  e8c0f6ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a746b0  89351800a800           -mov dword ptr [0xa80018], esi
    *app->getMemory<x86::reg32>(x86::reg32(11010072) /* 0xa80018 */) = cpu.esi;
L_0x00a746b6:
    // 00a746b6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a746b7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a746b8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a746b9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a746ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a746c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a746c0  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a746c1  833800                 +cmp dword ptr [eax], 0
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
    // 00a746c4  7404                   -je 0xa746ca
    if (cpu.flags.zf)
    {
        goto L_0x00a746ca;
    }
    // 00a746c6  1e                     -push ds
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a746c7  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a746c8  ff10                   -call dword ptr [eax]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a746ca:
    // 00a746ca  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a746cb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a746cc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a746cc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a746cd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a746ce  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a746cf  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a746d0  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a746d1  be9ee4a700             -mov esi, 0xa7e49e
    cpu.esi = 11003038 /*0xa7e49e*/;
    // 00a746d6  88c6                   -mov dh, al
    cpu.dh = cpu.al;
L_0x00a746d8:
    // 00a746d8  b874e4a700             -mov eax, 0xa7e474
    cpu.eax = 11002996 /*0xa7e474*/;
    // 00a746dd  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a746df  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 00a746e1  39c6                   +cmp esi, eax
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
    // 00a746e3  761a                   -jbe 0xa746ff
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a746ff;
    }
L_0x00a746e5:
    // 00a746e5  803802                 +cmp byte ptr [eax], 2
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
    // 00a746e8  740b                   -je 0xa746f5
    if (cpu.flags.zf)
    {
        goto L_0x00a746f5;
    }
    // 00a746ea  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a746ed  38ea                   +cmp dl, ch
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
    // 00a746ef  7204                   -jb 0xa746f5
    if (cpu.flags.cf)
    {
        goto L_0x00a746f5;
    }
    // 00a746f1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a746f3  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a746f5:
    // 00a746f5  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00a746f8  3d9ee4a700             +cmp eax, 0xa7e49e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11003038 /*0xa7e49e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a746fd  72e6                   -jb 0xa746e5
    if (cpu.flags.cf)
    {
        goto L_0x00a746e5;
    }
L_0x00a746ff:
    // 00a746ff  81fb9ee4a700           +cmp ebx, 0xa7e49e
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11003038 /*0xa7e49e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74705  740d                   -je 0xa74714
    if (cpu.flags.zf)
    {
        goto L_0x00a74714;
    }
    // 00a74707  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a7470a  e8b1ffffff             -call 0xa746c0
    cpu.esp -= 4;
    sub_a746c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7470f  c60302                 -mov byte ptr [ebx], 2
    *app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a74712  ebc4                   -jmp 0xa746d8
    goto L_0x00a746d8;
L_0x00a74714:
    // 00a74714  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74715  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74716  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74717  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74718  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74719  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7471c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7471c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7471d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7471e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7471f  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a74720  be74e4a700             -mov esi, 0xa7e474
    cpu.esi = 11002996 /*0xa7e474*/;
    // 00a74725  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a74727  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
L_0x00a74729:
    // 00a74729  b850e4a700             -mov eax, 0xa7e450
    cpu.eax = 11002960 /*0xa7e450*/;
    // 00a7472e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a74730  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00a74732  39c6                   +cmp esi, eax
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
    // 00a74734  761a                   -jbe 0xa74750
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a74750;
    }
L_0x00a74736:
    // 00a74736  803802                 +cmp byte ptr [eax], 2
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
    // 00a74739  740b                   -je 0xa74746
    if (cpu.flags.zf)
    {
        goto L_0x00a74746;
    }
    // 00a7473b  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7473e  38ea                   +cmp dl, ch
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
    // 00a74740  7704                   -ja 0xa74746
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a74746;
    }
    // 00a74742  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a74744  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
L_0x00a74746:
    // 00a74746  83c006                 -add eax, 6
    (cpu.eax) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 00a74749  3d74e4a700             +cmp eax, 0xa7e474
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11002996 /*0xa7e474*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7474e  72e6                   -jb 0xa74736
    if (cpu.flags.cf)
    {
        goto L_0x00a74736;
    }
L_0x00a74750:
    // 00a74750  81fb74e4a700           +cmp ebx, 0xa7e474
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11002996 /*0xa7e474*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74756  7412                   -je 0xa7476a
    if (cpu.flags.zf)
    {
        goto L_0x00a7476a;
    }
    // 00a74758  3a7301                 +cmp dh, byte ptr [ebx + 1]
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
    // 00a7475b  7208                   -jb 0xa74765
    if (cpu.flags.cf)
    {
        goto L_0x00a74765;
    }
    // 00a7475d  8d4302                 -lea eax, [ebx + 2]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00a74760  e85bffffff             -call 0xa746c0
    cpu.esp -= 4;
    sub_a746c0(app, cpu);
    if (cpu.terminate) return;
L_0x00a74765:
    // 00a74765  c60302                 -mov byte ptr [ebx], 2
    *app->getMemory<x86::reg8>(cpu.ebx) = 2 /*0x2*/;
    // 00a74768  ebbf                   -jmp 0xa74729
    goto L_0x00a74729;
L_0x00a7476a:
    // 00a7476a  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7476b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7476c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7476d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7476e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a74770(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74770  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74771  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74772  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a74773  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74774  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a74777  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a74779  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00a7477b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a7477d  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00a74782  885c246c               -mov byte ptr [esp + 0x6c], bl
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.bl;
    // 00a74786  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 00a74788  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7478b  66895c241e             -mov word ptr [esp + 0x1e], bx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(30) /* 0x1e */) = cpu.bx;
    // 00a74790  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a74792  66894c241c             -mov word ptr [esp + 0x1c], cx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 00a74797  895c2410               -mov dword ptr [esp + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a7479b  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a7479d  89542468               -mov dword ptr [esp + 0x68], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 00a747a1  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00a747a3  0f8461030000           -je 0xa74b0a
    if (cpu.flags.zf)
    {
        goto L_0x00a74b0a;
    }
L_0x00a747a9:
    // 00a747a9  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a747ad  8b6c2468               -mov ebp, dword ptr [esp + 0x68]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a747b1  8a28                   -mov ch, byte ptr [eax]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a747b3  45                     -inc ebp
    (cpu.ebp)++;
    // 00a747b4  80fd25                 +cmp ch, 0x25
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
    // 00a747b7  7411                   -je 0xa747ca
    if (cpu.flags.zf)
    {
        goto L_0x00a747ca;
    }
    // 00a747b9  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a747bb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a747bd  88ea                   -mov dl, ch
    cpu.dl = cpu.ch;
    // 00a747bf  896c2468               -mov dword ptr [esp + 0x68], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 00a747c3  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a747c5  e918030000             -jmp 0xa74ae2
    goto L_0x00a74ae2;
L_0x00a747ca:
    // 00a747ca  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a747cc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a747ce  8d542460               -lea edx, [esp + 0x60]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a747d2  89442460               -mov dword ptr [esp + 0x60], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00a747d6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a747d8  e83b030000             -call 0xa74b18
    cpu.esp -= 4;
    sub_a74b18(app, cpu);
    if (cpu.terminate) return;
    // 00a747dd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a747df  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00a747e3  45                     -inc ebp
    (cpu.ebp)++;
    // 00a747e4  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a747e6  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00a747e9  896c2468               -mov dword ptr [esp + 0x68], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebp;
    // 00a747ed  88442415               -mov byte ptr [esp + 0x15], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.al;
    // 00a747f1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a747f3  0f8411030000           -je 0xa74b0a
    if (cpu.flags.zf)
    {
        goto L_0x00a74b0a;
    }
    // 00a747f9  3c6e                   +cmp al, 0x6e
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
    // 00a747fb  0f8570010000           -jne 0xa74971
    if (!cpu.flags.zf)
    {
        goto L_0x00a74971;
    }
    // 00a74801  8a5c241e               -mov bl, byte ptr [esp + 0x1e]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00a74805  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a74808  744f                   -je 0xa74859
    if (cpu.flags.zf)
    {
        goto L_0x00a74859;
    }
    // 00a7480a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a7480d  741f                   -je 0xa7482e
    if (cpu.flags.zf)
    {
        goto L_0x00a7482e;
    }
    // 00a7480f  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a74811  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a74814  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a74816  c452f8                 -les edx, ptr [edx - 8]
    NFS2_ASSERT(false);
    // 00a74819  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a7481d  268902                 -mov dword ptr es:[edx], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00a74820  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a74824  803800                 +cmp byte ptr [eax], 0
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
    // 00a74827  7580                   -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a74829  e9dc020000             -jmp 0xa74b0a
    goto L_0x00a74b0a;
L_0x00a7482e:
    // 00a7482e  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a74831  0f84e8000000           -je 0xa7491f
    if (cpu.flags.zf)
    {
        goto L_0x00a7491f;
    }
    // 00a74837  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a74839  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7483c  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a7483e  8b50fc                 -mov edx, dword ptr [eax - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a74841  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a74845  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a74847  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a7484b  803800                 +cmp byte ptr [eax], 0
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
    // 00a7484e  0f8555ffffff           -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a74854  e9b1020000             -jmp 0xa74b0a
    goto L_0x00a74b0a;
L_0x00a74859:
    // 00a74859  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 00a7485c  0f8489000000           -je 0xa748eb
    if (cpu.flags.zf)
    {
        goto L_0x00a748eb;
    }
    // 00a74862  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a74865  742b                   -je 0xa74892
    if (cpu.flags.zf)
    {
        goto L_0x00a74892;
    }
    // 00a74867  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a74869  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7486c  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00a7486e  c451f8                 -les edx, ptr [ecx - 8]
    NFS2_ASSERT(false);
    // 00a74871  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a74875  66268902               -mov word ptr es:[edx], ax
    *app->getMemory<x86::reg16>(cpu.ees + cpu.edx) = cpu.ax;
    // 00a74879  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a7487d  803800                 +cmp byte ptr [eax], 0
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
    // 00a74880  0f8523ffffff           -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a74886  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a7488a  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a7488d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7488e  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7488f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74890  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74891  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74892:
    // 00a74892  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a74895  742a                   -je 0xa748c1
    if (cpu.flags.zf)
    {
        goto L_0x00a748c1;
    }
    // 00a74897  8b1e                   -mov ebx, dword ptr [esi]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a74899  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7489c  891e                   -mov dword ptr [esi], ebx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00a7489e  8b53fc                 -mov edx, dword ptr [ebx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a748a1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a748a5  668902                 -mov word ptr [edx], ax
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00a748a8  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a748ac  803800                 +cmp byte ptr [eax], 0
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
    // 00a748af  0f85f4feffff           -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a748b5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a748b9  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a748bc  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a748bd  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a748be  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a748bf  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a748c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a748c1:
    // 00a748c1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a748c3  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a748c6  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a748c8  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a748cb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a748cf  668902                 -mov word ptr [edx], ax
    *app->getMemory<x86::reg16>(cpu.edx) = cpu.ax;
    // 00a748d2  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a748d6  803800                 +cmp byte ptr [eax], 0
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
    // 00a748d9  0f85cafeffff           -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a748df  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a748e3  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a748e6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a748e7  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a748e8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a748e9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a748ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a748eb:
    // 00a748eb  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a748ee  742a                   -je 0xa7491a
    if (cpu.flags.zf)
    {
        goto L_0x00a7491a;
    }
    // 00a748f0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a748f2  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a748f5  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a748f7  c450f8                 -les edx, ptr [eax - 8]
    NFS2_ASSERT(false);
    // 00a748fa  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a748fe  268902                 -mov dword ptr es:[edx], eax
    *app->getMemory<x86::reg32>(cpu.ees + cpu.edx) = cpu.eax;
    // 00a74901  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a74905  803800                 +cmp byte ptr [eax], 0
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
    // 00a74908  0f859bfeffff           -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a7490e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a74912  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a74915  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74916  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74917  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74918  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74919  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7491a:
    // 00a7491a  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00a7491d  7429                   -je 0xa74948
    if (cpu.flags.zf)
    {
        goto L_0x00a74948;
    }
L_0x00a7491f:
    // 00a7491f  8b2e                   -mov ebp, dword ptr [esi]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a74921  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74924  892e                   -mov dword ptr [esi], ebp
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 00a74926  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a74929  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a7492d  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a7492f  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a74933  803800                 +cmp byte ptr [eax], 0
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
    // 00a74936  0f856dfeffff           -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a7493c  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a74940  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a74943  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74944  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74945  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74946  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74947  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74948:
    // 00a74948  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a7494a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7494d  890e                   -mov dword ptr [esi], ecx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 00a7494f  8b51fc                 -mov edx, dword ptr [ecx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */);
    // 00a74952  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a74956  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a74958  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a7495c  803800                 +cmp byte ptr [eax], 0
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
    // 00a7495f  0f8544feffff           -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a74965  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a74969  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a7496c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7496d  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7496e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7496f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74970  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74971:
    // 00a74971  8d4c246c               -lea ecx, [esp + 0x6c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00a74975  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a74977  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a74979  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00a7497d  89442464               -mov dword ptr [esp + 0x64], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00a74981  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a74985  e8ea050000             -call 0xa74f74
    cpu.esp -= 4;
    sub_a74f74(app, cpu);
    if (cpu.terminate) return;
    // 00a7498a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a7498c  8b442464               -mov eax, dword ptr [esp + 0x64]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00a74990  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a74992  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a74994  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a74998  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a7499c  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a749a0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a749a2  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a749a6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a749a8  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a749ac  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a749ae  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a749b2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a749b4  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a749b8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a749ba  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a749bc  8a54241e               -mov dl, byte ptr [esp + 0x1e]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */);
    // 00a749c0  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a749c4  f6c208                 +test dl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 8 /*0x8*/));
    // 00a749c7  751d                   -jne 0xa749e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a749e6;
    }
    // 00a749c9  807c241620             +cmp byte ptr [esp + 0x16], 0x20
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a749ce  7516                   -jne 0xa749e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a749e6;
    }
L_0x00a749d0:
    // 00a749d0  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a749d5  7e0f                   -jle 0xa749e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a749e6;
    }
    // 00a749d7  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00a749dc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a749de  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a749e0  ff4c2404               +dec dword ptr [esp + 4]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a749e4  ebea                   -jmp 0xa749d0
    goto L_0x00a749d0;
L_0x00a749e6:
    // 00a749e6  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a749ea  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a749ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a749f0  7e16                   -jle 0xa74a08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74a08;
    }
L_0x00a749f2:
    // 00a749f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a749f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a749f6  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx);
    // 00a749f8  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a749fa  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a749fe  4a                     -dec edx
    (cpu.edx)--;
    // 00a749ff  43                     -inc ebx
    (cpu.ebx)++;
    // 00a74a00  89542420               -mov dword ptr [esp + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a74a04  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a74a06  7fea                   -jg 0xa749f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a749f2;
    }
L_0x00a74a08:
    // 00a74a08  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74a0d  7e0f                   -jle 0xa74a1e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74a1e;
    }
    // 00a74a0f  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a74a14  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74a16  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74a18  ff4c2424               +dec dword ptr [esp + 0x24]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74a1c  ebea                   -jmp 0xa74a08
    goto L_0x00a74a08;
L_0x00a74a1e:
    // 00a74a1e  8a5c2415               -mov bl, byte ptr [esp + 0x15]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */);
    // 00a74a22  80fb73                 +cmp bl, 0x73
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
    // 00a74a25  7533                   -jne 0xa74a5a
    if (!cpu.flags.zf)
    {
        goto L_0x00a74a5a;
    }
    // 00a74a27  f644241e20             +test byte ptr [esp + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a74a2c  740f                   -je 0xa74a3d
    if (cpu.flags.zf)
    {
        goto L_0x00a74a3d;
    }
    // 00a74a2e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a74a30  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00a74a32  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a74a34  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a74a36  e8d5040000             -call 0xa74f10
    cpu.esp -= 4;
    sub_a74f10(app, cpu);
    if (cpu.terminate) return;
    // 00a74a3b  eb4e                   -jmp 0xa74a8b
    goto L_0x00a74a8b;
L_0x00a74a3d:
    // 00a74a3d  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74a42  7e47                   -jle 0xa74a8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74a8b;
    }
    // 00a74a44  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a74a46  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74a48  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a74a4c  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74a4e  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a74a52  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74a53  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74a54  89542428               -mov dword ptr [esp + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a74a58  ebe3                   -jmp 0xa74a3d
    goto L_0x00a74a3d;
L_0x00a74a5a:
    // 00a74a5a  80fb53                 +cmp bl, 0x53
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
    // 00a74a5d  750f                   -jne 0xa74a6e
    if (!cpu.flags.zf)
    {
        goto L_0x00a74a6e;
    }
    // 00a74a5f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00a74a61  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00a74a63  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a74a65  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a74a67  e8a4040000             -call 0xa74f10
    cpu.esp -= 4;
    sub_a74f10(app, cpu);
    if (cpu.terminate) return;
    // 00a74a6c  eb1d                   -jmp 0xa74a8b
    goto L_0x00a74a8b;
L_0x00a74a6e:
    // 00a74a6e  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74a73  7e16                   -jle 0xa74a8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74a8b;
    }
    // 00a74a75  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a74a77  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74a79  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a74a7d  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74a7f  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a74a83  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74a84  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74a85  894c2428               -mov dword ptr [esp + 0x28], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ecx;
    // 00a74a89  ebe3                   -jmp 0xa74a6e
    goto L_0x00a74a6e;
L_0x00a74a8b:
    // 00a74a8b  837c242c00             +cmp dword ptr [esp + 0x2c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74a90  7e0f                   -jle 0xa74aa1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74aa1;
    }
    // 00a74a92  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a74a97  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74a99  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74a9b  ff4c242c               +dec dword ptr [esp + 0x2c]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74a9f  ebea                   -jmp 0xa74a8b
    goto L_0x00a74a8b;
L_0x00a74aa1:
    // 00a74aa1  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74aa6  7e16                   -jle 0xa74abe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74abe;
    }
    // 00a74aa8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a74aaa  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74aac  268a5500               -mov dl, byte ptr es:[ebp]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ees + cpu.ebp);
    // 00a74ab0  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74ab2  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a74ab6  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74ab7  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74ab8  89542430               -mov dword ptr [esp + 0x30], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00a74abc  ebe3                   -jmp 0xa74aa1
    goto L_0x00a74aa1;
L_0x00a74abe:
    // 00a74abe  837c243400             +cmp dword ptr [esp + 0x34], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74ac3  7e0f                   -jle 0xa74ad4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74ad4;
    }
    // 00a74ac5  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00a74aca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74acc  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74ace  ff4c2434               +dec dword ptr [esp + 0x34]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74ad2  ebea                   -jmp 0xa74abe
    goto L_0x00a74abe;
L_0x00a74ad4:
    // 00a74ad4  f644241e08             +test byte ptr [esp + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00a74ad9  7407                   -je 0xa74ae2
    if (cpu.flags.zf)
    {
        goto L_0x00a74ae2;
    }
L_0x00a74adb:
    // 00a74adb  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a74ae0  7f19                   -jg 0xa74afb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a74afb;
    }
L_0x00a74ae2:
    // 00a74ae2  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00a74ae6  803800                 +cmp byte ptr [eax], 0
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
    // 00a74ae9  0f85bafcffff           -jne 0xa747a9
    if (!cpu.flags.zf)
    {
        goto L_0x00a747a9;
    }
    // 00a74aef  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a74af3  83c470                 +add esp, 0x70
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
    // 00a74af6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74af7  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74af8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74af9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74afa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74afb:
    // 00a74afb  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00a74b00  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74b02  ffd7                   -call edi
    cpu.ip = cpu.edi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74b04  ff4c2404               +dec dword ptr [esp + 4]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74b08  ebd1                   -jmp 0xa74adb
    goto L_0x00a74adb;
L_0x00a74b0a:
    // 00a74b0a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a74b0e  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00a74b11  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74b12  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74b13  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74b14  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74b15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a74b18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74b18  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74b19  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74b1a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74b1b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a74b1d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a74b1f  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
    // 00a74b23  e844010000             -call 0xa74c6c
    cpu.esp -= 4;
    sub_a74c6c(app, cpu);
    if (cpu.terminate) return;
    // 00a74b28  c7430400000000         -mov dword ptr [ebx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a74b2f  80382a                 +cmp byte ptr [eax], 0x2a
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(42 /*0x2a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a74b32  7524                   -jne 0xa74b58
    if (!cpu.flags.zf)
    {
        goto L_0x00a74b58;
    }
    // 00a74b34  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a74b36  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74b39  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a74b3b  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a74b3e  895304                 -mov dword ptr [ebx + 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a74b41  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a74b43  7d10                   -jge 0xa74b55
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a74b55;
    }
    // 00a74b45  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a74b47  8a6b1e                 -mov ch, byte ptr [ebx + 0x1e]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00a74b4a  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00a74b4c  80cd08                 +or ch, 8
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a74b4f  897b04                 -mov dword ptr [ebx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00a74b52  886b1e                 -mov byte ptr [ebx + 0x1e], ch
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.ch;
L_0x00a74b55:
    // 00a74b55  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74b56  eb1f                   -jmp 0xa74b77
    goto L_0x00a74b77;
L_0x00a74b58:
    // 00a74b58  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a74b5a  80fa30                 +cmp dl, 0x30
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
    // 00a74b5d  7218                   -jb 0xa74b77
    if (cpu.flags.cf)
    {
        goto L_0x00a74b77;
    }
    // 00a74b5f  80fa39                 +cmp dl, 0x39
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
    // 00a74b62  7713                   -ja 0xa74b77
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a74b77;
    }
    // 00a74b64  6b4b040a               -imul ecx, dword ptr [ebx + 4], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a74b68  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a74b6a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a74b6c  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a74b6f  01d1                   +add ecx, edx
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
    // 00a74b71  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74b72  894b04                 -mov dword ptr [ebx + 4], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a74b75  ebe1                   -jmp 0xa74b58
    goto L_0x00a74b58;
L_0x00a74b77:
    // 00a74b77  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 00a74b7e  80382e                 +cmp byte ptr [eax], 0x2e
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a74b81  7554                   -jne 0xa74bd7
    if (!cpu.flags.zf)
    {
        goto L_0x00a74bd7;
    }
    // 00a74b83  c7430800000000         -mov dword ptr [ebx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a74b8a  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a74b8d  40                     -inc eax
    (cpu.eax)++;
    // 00a74b8e  80fd2a                 +cmp ch, 0x2a
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
    // 00a74b91  751b                   -jne 0xa74bae
    if (!cpu.flags.zf)
    {
        goto L_0x00a74bae;
    }
    // 00a74b93  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a74b95  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74b98  8916                   -mov dword ptr [esi], edx
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00a74b9a  8b52fc                 -mov edx, dword ptr [edx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a74b9d  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a74ba0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a74ba2  7d07                   -jge 0xa74bab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a74bab;
    }
    // 00a74ba4  c74308ffffffff         -mov dword ptr [ebx + 8], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
L_0x00a74bab:
    // 00a74bab  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74bac  eb1f                   -jmp 0xa74bcd
    goto L_0x00a74bcd;
L_0x00a74bae:
    // 00a74bae  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a74bb0  80fa30                 +cmp dl, 0x30
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
    // 00a74bb3  7218                   -jb 0xa74bcd
    if (cpu.flags.cf)
    {
        goto L_0x00a74bcd;
    }
    // 00a74bb5  80fa39                 +cmp dl, 0x39
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
    // 00a74bb8  7713                   -ja 0xa74bcd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a74bcd;
    }
    // 00a74bba  6b4b080a               -imul ecx, dword ptr [ebx + 8], 0xa
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a74bbe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a74bc0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a74bc2  83ea30                 -sub edx, 0x30
    (cpu.edx) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a74bc5  01d1                   +add ecx, edx
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
    // 00a74bc7  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74bc8  894b08                 -mov dword ptr [ebx + 8], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00a74bcb  ebe1                   -jmp 0xa74bae
    goto L_0x00a74bae;
L_0x00a74bcd:
    // 00a74bcd  837b08ff               +cmp dword ptr [ebx + 8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74bd1  7404                   -je 0xa74bd7
    if (cpu.flags.zf)
    {
        goto L_0x00a74bd7;
    }
    // 00a74bd3  c6431620               -mov byte ptr [ebx + 0x16], 0x20
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(22) /* 0x16 */) = 32 /*0x20*/;
L_0x00a74bd7:
    // 00a74bd7  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a74bd9  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a74bdc  80fa4e                 +cmp dl, 0x4e
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
    // 00a74bdf  721f                   -jb 0xa74c00
    if (cpu.flags.cf)
    {
        goto L_0x00a74c00;
    }
    // 00a74be1  0f867b000000           -jbe 0xa74c62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a74c62;
    }
    // 00a74be7  80fa6c                 +cmp dl, 0x6c
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
    // 00a74bea  720b                   -jb 0xa74bf7
    if (cpu.flags.cf)
    {
        goto L_0x00a74bf7;
    }
    // 00a74bec  762b                   -jbe 0xa74c19
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a74c19;
    }
    // 00a74bee  80fa77                 +cmp dl, 0x77
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
    // 00a74bf1  7426                   -je 0xa74c19
    if (cpu.flags.zf)
    {
        goto L_0x00a74c19;
    }
    // 00a74bf3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74bf4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74bf5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74bf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74bf7:
    // 00a74bf7  80fa68                 +cmp dl, 0x68
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
    // 00a74bfa  742b                   -je 0xa74c27
    if (cpu.flags.zf)
    {
        goto L_0x00a74c27;
    }
    // 00a74bfc  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74bfd  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74bfe  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74bff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74c00:
    // 00a74c00  80fa49                 +cmp dl, 0x49
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
    // 00a74c03  720b                   -jb 0xa74c10
    if (cpu.flags.cf)
    {
        goto L_0x00a74c10;
    }
    // 00a74c05  7626                   -jbe 0xa74c2d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a74c2d;
    }
    // 00a74c07  80fa4c                 +cmp dl, 0x4c
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
    // 00a74c0a  743d                   -je 0xa74c49
    if (cpu.flags.zf)
    {
        goto L_0x00a74c49;
    }
    // 00a74c0c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c0d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c0e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c0f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74c10:
    // 00a74c10  80fa46                 +cmp dl, 0x46
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
    // 00a74c13  7443                   -je 0xa74c58
    if (cpu.flags.zf)
    {
        goto L_0x00a74c58;
    }
    // 00a74c15  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c16  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c17  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74c19:
    // 00a74c19  8a4b1e                 -mov cl, byte ptr [ebx + 0x1e]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 00a74c1c  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a74c1f  40                     -inc eax
    (cpu.eax)++;
    // 00a74c20  884b1e                 -mov byte ptr [ebx + 0x1e], cl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00a74c23  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c24  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c25  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74c27:
    // 00a74c27  804b1e10               +or byte ptr [ebx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00a74c2b  eb39                   -jmp 0xa74c66
    goto L_0x00a74c66;
L_0x00a74c2d:
    // 00a74c2d  80780136               +cmp byte ptr [eax + 1], 0x36
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(54 /*0x36*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a74c31  7535                   -jne 0xa74c68
    if (!cpu.flags.zf)
    {
        goto L_0x00a74c68;
    }
    // 00a74c33  80780234               +cmp byte ptr [eax + 2], 0x34
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(52 /*0x34*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a74c37  752f                   -jne 0xa74c68
    if (!cpu.flags.zf)
    {
        goto L_0x00a74c68;
    }
    // 00a74c39  8a6b1f                 -mov ch, byte ptr [ebx + 0x1f]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00a74c3c  80cd01                 -or ch, 1
    cpu.ch |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a74c3f  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a74c42  886b1f                 -mov byte ptr [ebx + 0x1f], ch
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.ch;
    // 00a74c45  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c46  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c47  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74c49:
    // 00a74c49  8a531f                 -mov dl, byte ptr [ebx + 0x1f]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */);
    // 00a74c4c  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a74c4f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a74c51  88531f                 -mov byte ptr [ebx + 0x1f], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(31) /* 0x1f */) = cpu.dl;
    // 00a74c54  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c55  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c56  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74c58:
    // 00a74c58  804b1e80               -or byte ptr [ebx + 0x1e], 0x80
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a74c5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a74c5e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c5f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c60  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74c62:
    // 00a74c62  804b1e40               -or byte ptr [ebx + 0x1e], 0x40
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00a74c66:
    // 00a74c66  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a74c68:
    // 00a74c68  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c69  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c6a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74c6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a74c6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74c6c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a74c6d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74c6e  66c7421e0000           -mov word ptr [edx + 0x1e], 0
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 00a74c74  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a74c76  80fb2d                 +cmp bl, 0x2d
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
    // 00a74c79  7506                   -jne 0xa74c81
    if (!cpu.flags.zf)
    {
        goto L_0x00a74c81;
    }
    // 00a74c7b  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a74c7f  eb42                   -jmp 0xa74cc3
    goto L_0x00a74cc3;
L_0x00a74c81:
    // 00a74c81  80fb23                 +cmp bl, 0x23
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
    // 00a74c84  7506                   -jne 0xa74c8c
    if (!cpu.flags.zf)
    {
        goto L_0x00a74c8c;
    }
    // 00a74c86  804a1e01               +or byte ptr [edx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00a74c8a  eb37                   -jmp 0xa74cc3
    goto L_0x00a74cc3;
L_0x00a74c8c:
    // 00a74c8c  80fb2b                 +cmp bl, 0x2b
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
    // 00a74c8f  7513                   -jne 0xa74ca4
    if (!cpu.flags.zf)
    {
        goto L_0x00a74ca4;
    }
    // 00a74c91  8a6a1e                 -mov ch, byte ptr [edx + 0x1e]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00a74c94  80cd04                 -or ch, 4
    cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00a74c97  88eb                   -mov bl, ch
    cpu.bl = cpu.ch;
    // 00a74c99  886a1e                 -mov byte ptr [edx + 0x1e], ch
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.ch;
    // 00a74c9c  80e3fd                 +and bl, 0xfd
    cpu.clear_co();
    cpu.set_szp((cpu.bl &= x86::reg8(x86::sreg8(253 /*0xfd*/))));
    // 00a74c9f  885a1e                 -mov byte ptr [edx + 0x1e], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.bl;
    // 00a74ca2  eb1f                   -jmp 0xa74cc3
    goto L_0x00a74cc3;
L_0x00a74ca4:
    // 00a74ca4  80fb20                 +cmp bl, 0x20
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
    // 00a74ca7  7512                   -jne 0xa74cbb
    if (!cpu.flags.zf)
    {
        goto L_0x00a74cbb;
    }
    // 00a74ca9  8a7a1e                 -mov bh, byte ptr [edx + 0x1e]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 00a74cac  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00a74caf  7512                   -jne 0xa74cc3
    if (!cpu.flags.zf)
    {
        goto L_0x00a74cc3;
    }
    // 00a74cb1  88f9                   -mov cl, bh
    cpu.cl = cpu.bh;
    // 00a74cb3  80c902                 +or cl, 2
    cpu.clear_co();
    cpu.set_szp((cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00a74cb6  884a1e                 -mov byte ptr [edx + 0x1e], cl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) = cpu.cl;
    // 00a74cb9  eb08                   -jmp 0xa74cc3
    goto L_0x00a74cc3;
L_0x00a74cbb:
    // 00a74cbb  80fb30                 +cmp bl, 0x30
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
    // 00a74cbe  7511                   -jne 0xa74cd1
    if (!cpu.flags.zf)
    {
        goto L_0x00a74cd1;
    }
    // 00a74cc0  885a16                 -mov byte ptr [edx + 0x16], bl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(22) /* 0x16 */) = cpu.bl;
L_0x00a74cc3:
    // 00a74cc3  40                     -inc eax
    (cpu.eax)++;
    // 00a74cc4  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a74cc6  80fb2d                 +cmp bl, 0x2d
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
    // 00a74cc9  75b6                   -jne 0xa74c81
    if (!cpu.flags.zf)
    {
        goto L_0x00a74c81;
    }
    // 00a74ccb  804a1e08               +or byte ptr [edx + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(30) /* 0x1e */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 00a74ccf  ebf2                   -jmp 0xa74cc3
    goto L_0x00a74cc3;
L_0x00a74cd1:
    // 00a74cd1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74cd2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74cd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a74cd4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74cd4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74cd5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74cd6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74cd7  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a74cd8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a74cda  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a74cdc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a74cde  8ec1                   -mov es, ecx
    cpu.es = cpu.ecx;
    // 00a74ce0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a74ce2:
    // 00a74ce2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a74ce4  268a1e                 -mov bl, byte ptr es:[esi]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ees + cpu.esi);
    // 00a74ce7  42                     -inc edx
    (cpu.edx)++;
    // 00a74ce8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00a74cea  7407                   -je 0xa74cf3
    if (cpu.flags.zf)
    {
        goto L_0x00a74cf3;
    }
    // 00a74cec  39f8                   +cmp eax, edi
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
    // 00a74cee  7403                   -je 0xa74cf3
    if (cpu.flags.zf)
    {
        goto L_0x00a74cf3;
    }
    // 00a74cf0  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74cf1  ebef                   -jmp 0xa74ce2
    goto L_0x00a74ce2;
L_0x00a74cf3:
    // 00a74cf3  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74cf4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74cf5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74cf6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74cf7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a74cf8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74cf8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74cf9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74cfa  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a74cfb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74cfe  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a74d00  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a74d02  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a74d04  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a74d06  83feff                 +cmp esi, -1
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
    // 00a74d09  7521                   -jne 0xa74d2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a74d2c;
    }
L_0x00a74d0b:
    // 00a74d0b  66268b33               -mov si, word ptr es:[ebx]
    cpu.si = *app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00a74d0f  6685f6                 +test si, si
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.si & cpu.si));
    // 00a74d12  7440                   -je 0xa74d54
    if (cpu.flags.zf)
    {
        goto L_0x00a74d54;
    }
    // 00a74d14  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a74d16  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74d18  6689f2                 -mov dx, si
    cpu.dx = cpu.si;
    // 00a74d1b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a74d1e  e86d260000             -call 0xa77390
    cpu.esp -= 4;
    sub_a77390(app, cpu);
    if (cpu.terminate) return;
    // 00a74d23  83f8ff                 +cmp eax, -1
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
    // 00a74d26  74e3                   -je 0xa74d0b
    if (cpu.flags.zf)
    {
        goto L_0x00a74d0b;
    }
    // 00a74d28  01c1                   +add ecx, eax
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
    // 00a74d2a  ebdf                   -jmp 0xa74d0b
    goto L_0x00a74d0b;
L_0x00a74d2c:
    // 00a74d2c  6626833b00             +cmp word ptr es:[ebx], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a74d31  741d                   -je 0xa74d50
    if (cpu.flags.zf)
    {
        goto L_0x00a74d50;
    }
    // 00a74d33  39f1                   +cmp ecx, esi
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
    // 00a74d35  7f19                   -jg 0xa74d50
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a74d50;
    }
    // 00a74d37  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a74d39  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74d3b  66268b13               -mov dx, word ptr es:[ebx]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ees + cpu.ebx);
    // 00a74d3f  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a74d42  e849260000             -call 0xa77390
    cpu.esp -= 4;
    sub_a77390(app, cpu);
    if (cpu.terminate) return;
    // 00a74d47  83f8ff                 +cmp eax, -1
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
    // 00a74d4a  74e0                   -je 0xa74d2c
    if (cpu.flags.zf)
    {
        goto L_0x00a74d2c;
    }
    // 00a74d4c  01c1                   +add ecx, eax
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
    // 00a74d4e  ebdc                   -jmp 0xa74d2c
    goto L_0x00a74d2c;
L_0x00a74d50:
    // 00a74d50  39f1                   +cmp ecx, esi
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
    // 00a74d52  7f04                   -jg 0xa74d58
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a74d58;
    }
L_0x00a74d54:
    // 00a74d54  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a74d56  eb02                   -jmp 0xa74d5a
    goto L_0x00a74d5a;
L_0x00a74d58:
    // 00a74d58  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a74d5a:
    // 00a74d5a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74d5d  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74d5e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74d5f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74d60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a74d64(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74d64  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74d65  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74d66  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74d67  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74d68  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74d6b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a74d6d  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a74d70  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a74d75  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a74d77  e8a0260000             -call 0xa7741c
    cpu.esp -= 4;
    sub_a7741c(app, cpu);
    if (cpu.terminate) return;
    // 00a74d7c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a74d7d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a74d7f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a74d81  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a74d83  49                     -dec ecx
    (cpu.ecx)--;
    // 00a74d84  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a74d86  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a74d88  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a74d8a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a74d8b  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74d8c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a74d8f  48                     -dec eax
    (cpu.eax)--;
    // 00a74d90  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a74d92  7415                   -je 0xa74da9
    if (cpu.flags.zf)
    {
        goto L_0x00a74da9;
    }
    // 00a74d94  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a74d96  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00a74d99  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x00a74d9c:
    // 00a74d9c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a74d9d  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a74da0  4a                     -dec edx
    (cpu.edx)--;
    // 00a74da1  48                     -dec eax
    (cpu.eax)--;
    // 00a74da2  884b01                 -mov byte ptr [ebx + 1], cl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00a74da5  39f2                   +cmp edx, esi
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
    // 00a74da7  75f3                   -jne 0xa74d9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a74d9c;
    }
L_0x00a74da9:
    // 00a74da9  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00a74dac:
    // 00a74dac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a74dae  7c07                   -jl 0xa74db7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a74db7;
    }
    // 00a74db0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74db1  c60230                 -mov byte ptr [edx], 0x30
    *app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00a74db4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74db5  ebf5                   -jmp 0xa74dac
    goto L_0x00a74dac;
L_0x00a74db7:
    // 00a74db7  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
    // 00a74dba  c6450000               -mov byte ptr [ebp], 0
    *app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
    // 00a74dbe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74dc1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74dc2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74dc3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74dc4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74dc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a74dbe(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a74dbe;
    // 00a74d64  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74d65  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74d66  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74d67  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74d68  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74d6b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a74d6d  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a74d70  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a74d75  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a74d77  e8a0260000             -call 0xa7741c
    cpu.esp -= 4;
    sub_a7741c(app, cpu);
    if (cpu.terminate) return;
    // 00a74d7c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a74d7d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a74d7f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a74d81  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a74d83  49                     -dec ecx
    (cpu.ecx)--;
    // 00a74d84  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a74d86  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a74d88  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a74d8a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a74d8b  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74d8c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a74d8f  48                     -dec eax
    (cpu.eax)--;
    // 00a74d90  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a74d92  7415                   -je 0xa74da9
    if (cpu.flags.zf)
    {
        goto L_0x00a74da9;
    }
    // 00a74d94  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a74d96  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00a74d99  8d1429                 -lea edx, [ecx + ebp]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebp * 1);
L_0x00a74d9c:
    // 00a74d9c  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a74d9d  8a4aff                 -mov cl, byte ptr [edx - 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a74da0  4a                     -dec edx
    (cpu.edx)--;
    // 00a74da1  48                     -dec eax
    (cpu.eax)--;
    // 00a74da2  884b01                 -mov byte ptr [ebx + 1], cl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 00a74da5  39f2                   +cmp edx, esi
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
    // 00a74da7  75f3                   -jne 0xa74d9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a74d9c;
    }
L_0x00a74da9:
    // 00a74da9  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
L_0x00a74dac:
    // 00a74dac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a74dae  7c07                   -jl 0xa74db7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a74db7;
    }
    // 00a74db0  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74db1  c60230                 -mov byte ptr [edx], 0x30
    *app->getMemory<x86::reg8>(cpu.edx) = 48 /*0x30*/;
    // 00a74db4  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74db5  ebf5                   -jmp 0xa74dac
    goto L_0x00a74dac;
L_0x00a74db7:
    // 00a74db7  032c24                 -add ebp, dword ptr [esp]
    (cpu.ebp) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
    // 00a74dba  c6450000               -mov byte ptr [ebp], 0
    *app->getMemory<x86::reg8>(cpu.ebp) = 0 /*0x0*/;
L_entry_0x00a74dbe:
    // 00a74dbe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74dc1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74dc2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74dc3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74dc4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74dc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a74dc8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74dc8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74dc9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74dca  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74dcb  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74dcc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74dcf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a74dd1  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a74dd3  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a74dd6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a74dd8  7d0b                   -jge 0xa74de5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a74de5;
    }
    // 00a74dda  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 00a74ddc  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a74ddf  c6002d                 -mov byte ptr [eax], 0x2d
    *app->getMemory<x86::reg8>(cpu.eax) = 45 /*0x2d*/;
    // 00a74de2  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00a74de5:
    // 00a74de5  837e08ff               +cmp dword ptr [esi + 8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74de9  7507                   -jne 0xa74df2
    if (!cpu.flags.zf)
    {
        goto L_0x00a74df2;
    }
    // 00a74deb  c7460804000000         -mov dword ptr [esi + 8], 4
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 4 /*0x4*/;
L_0x00a74df2:
    // 00a74df2  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a74df7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a74df9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a74dfb  668b442402             -mov ax, word ptr [esp + 2]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00a74e00  e817260000             -call 0xa7741c
    cpu.esp -= 4;
    sub_a7741c(app, cpu);
    if (cpu.terminate) return;
    // 00a74e05  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a74e07  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a74e09  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a74e0b  7408                   -je 0xa74e15
    if (cpu.flags.zf)
    {
        goto L_0x00a74e15;
    }
L_0x00a74e0d:
    // 00a74e0d  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a74e10  41                     -inc ecx
    (cpu.ecx)++;
    // 00a74e11  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a74e13  75f8                   -jne 0xa74e0d
    if (!cpu.flags.zf)
    {
        goto L_0x00a74e0d;
    }
L_0x00a74e15:
    // 00a74e15  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00a74e19  7432                   -je 0xa74e4d
    if (cpu.flags.zf)
    {
        goto L_0x00a74e4d;
    }
    // 00a74e1b  c6012e                 -mov byte ptr [ecx], 0x2e
    *app->getMemory<x86::reg8>(cpu.ecx) = 46 /*0x2e*/;
    // 00a74e1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a74e20  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a74e23  41                     -inc ecx
    (cpu.ecx)++;
    // 00a74e24  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a74e26  7e22                   -jle 0xa74e4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74e4a;
    }
L_0x00a74e28:
    // 00a74e28  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a74e2a  6689542402             -mov word ptr [esp + 2], dx
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 00a74e2f  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a74e32  6bd70a                 -imul edx, edi, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 00a74e35  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a74e38  8a542402               -mov dl, byte ptr [esp + 2]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 00a74e3c  80c230                 -add dl, 0x30
    (cpu.dl) += x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a74e3f  8811                   -mov byte ptr [ecx], dl
    *app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 00a74e41  40                     -inc eax
    (cpu.eax)++;
    // 00a74e42  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00a74e45  41                     -inc ecx
    (cpu.ecx)++;
    // 00a74e46  39e8                   +cmp eax, ebp
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
    // 00a74e48  7cde                   -jl 0xa74e28
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a74e28;
    }
L_0x00a74e4a:
    // 00a74e4a  c60100                 -mov byte ptr [ecx], 0
    *app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x00a74e4d:
    // 00a74e4d  f644240180             +test byte ptr [esp + 1], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 128 /*0x80*/));
    // 00a74e52  0f8466ffffff           -je 0xa74dbe
    if (cpu.flags.zf)
    {
        return sub_a74dbe(app, cpu);
    }
L_0x00a74e58:
    // 00a74e58  39d9                   +cmp ecx, ebx
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
    // 00a74e5a  7541                   -jne 0xa74e9d
    if (!cpu.flags.zf)
    {
        goto L_0x00a74e9d;
    }
    // 00a74e5c  8d4b01                 -lea ecx, [ebx + 1]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a74e5f  c60331                 -mov byte ptr [ebx], 0x31
    *app->getMemory<x86::reg8>(cpu.ebx) = 49 /*0x31*/;
    // 00a74e62  803930                 +cmp byte ptr [ecx], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a74e65  7508                   -jne 0xa74e6f
    if (!cpu.flags.zf)
    {
        goto L_0x00a74e6f;
    }
L_0x00a74e67:
    // 00a74e67  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a74e6a  41                     -inc ecx
    (cpu.ecx)++;
    // 00a74e6b  3c30                   +cmp al, 0x30
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
    // 00a74e6d  74f8                   -je 0xa74e67
    if (cpu.flags.zf)
    {
        goto L_0x00a74e67;
    }
L_0x00a74e6f:
    // 00a74e6f  8a21                   -mov ah, byte ptr [ecx]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a74e71  80fc2e                 +cmp ah, 0x2e
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
    // 00a74e74  7518                   -jne 0xa74e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00a74e8e;
    }
    // 00a74e76  c60130                 -mov byte ptr [ecx], 0x30
    *app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a74e79  41                     -inc ecx
    (cpu.ecx)++;
    // 00a74e7a  8821                   -mov byte ptr [ecx], ah
    *app->getMemory<x86::reg8>(cpu.ecx) = cpu.ah;
    // 00a74e7c  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a74e7f  41                     -inc ecx
    (cpu.ecx)++;
    // 00a74e80  80fa30                 +cmp dl, 0x30
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
    // 00a74e83  7509                   -jne 0xa74e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00a74e8e;
    }
L_0x00a74e85:
    // 00a74e85  8a7101                 -mov dh, byte ptr [ecx + 1]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a74e88  41                     -inc ecx
    (cpu.ecx)++;
    // 00a74e89  80fe30                 +cmp dh, 0x30
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
    // 00a74e8c  74f7                   -je 0xa74e85
    if (cpu.flags.zf)
    {
        goto L_0x00a74e85;
    }
L_0x00a74e8e:
    // 00a74e8e  c60130                 -mov byte ptr [ecx], 0x30
    *app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a74e91  41                     -inc ecx
    (cpu.ecx)++;
    // 00a74e92  c60100                 -mov byte ptr [ecx], 0
    *app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 00a74e95  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74e98  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74e99  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74e9a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74e9b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74e9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74e9d:
    // 00a74e9d  8a51ff                 -mov dl, byte ptr [ecx - 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a74ea0  49                     -dec ecx
    (cpu.ecx)--;
    // 00a74ea1  80fa2e                 +cmp dl, 0x2e
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
    // 00a74ea4  7501                   -jne 0xa74ea7
    if (!cpu.flags.zf)
    {
        goto L_0x00a74ea7;
    }
    // 00a74ea6  49                     -dec ecx
    (cpu.ecx)--;
L_0x00a74ea7:
    // 00a74ea7  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a74ea9  80fe39                 +cmp dh, 0x39
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
    // 00a74eac  740e                   -je 0xa74ebc
    if (cpu.flags.zf)
    {
        goto L_0x00a74ebc;
    }
    // 00a74eae  88f3                   -mov bl, dh
    cpu.bl = cpu.dh;
    // 00a74eb0  fec3                   -inc bl
    (cpu.bl)++;
    // 00a74eb2  8819                   -mov byte ptr [ecx], bl
    *app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 00a74eb4  83c404                 +add esp, 4
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
    // 00a74eb7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74eb8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74eb9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74eba  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74ebb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a74ebc:
    // 00a74ebc  c60130                 -mov byte ptr [ecx], 0x30
    *app->getMemory<x86::reg8>(cpu.ecx) = 48 /*0x30*/;
    // 00a74ebf  eb97                   -jmp 0xa74e58
    goto L_0x00a74e58;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a74ec4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74ec4  ff15e4d3a700           -call dword ptr [0xa7d3e4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998756) /* 0xa7d3e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74eca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a74ecc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74ecc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a74ecd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a74ece  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a74ecf  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74ed0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74ed1  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74ed2  f6401e08               +test byte ptr [eax + 0x1e], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) & 8 /*0x8*/));
    // 00a74ed6  7530                   -jne 0xa74f08
    if (!cpu.flags.zf)
    {
        goto L_0x00a74f08;
    }
    // 00a74ed8  80781630               +cmp byte ptr [eax + 0x16], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a74edc  752a                   -jne 0xa74f08
    if (!cpu.flags.zf)
    {
        goto L_0x00a74f08;
    }
    // 00a74ede  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a74ee1  8b5820                 -mov ebx, dword ptr [eax + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00a74ee4  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a74ee7  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a74ee9  8b7028                 -mov esi, dword ptr [eax + 0x28]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00a74eec  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a74eee  8b782c                 -mov edi, dword ptr [eax + 0x2c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00a74ef1  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a74ef3  8b6830                 -mov ebp, dword ptr [eax + 0x30]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00a74ef6  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a74ef8  8b5834                 -mov ebx, dword ptr [eax + 0x34]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 00a74efb  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a74efd  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a74eff  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a74f01  7e05                   -jle 0xa74f08
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74f08;
    }
    // 00a74f03  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a74f05  894824                 -mov dword ptr [eax + 0x24], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ecx;
L_0x00a74f08:
    // 00a74f08  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f09  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f0a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f0b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f0c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f0d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a74f10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74f10  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74f11  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74f12  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a74f13  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74f14  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74f17  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a74f19  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a74f1b  8b5328                 -mov edx, dword ptr [ebx + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00a74f1e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00a74f20  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a74f22  7e45                   -jle 0xa74f69
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a74f69;
    }
L_0x00a74f24:
    // 00a74f24  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a74f26  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a74f28  66268b17               -mov dx, word ptr es:[edi]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ees + cpu.edi);
    // 00a74f2c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a74f2f  e85c240000             -call 0xa77390
    cpu.esp -= 4;
    sub_a77390(app, cpu);
    if (cpu.terminate) return;
    // 00a74f34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a74f36  83f8ff                 +cmp eax, -1
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
    // 00a74f39  740d                   -je 0xa74f48
    if (cpu.flags.zf)
    {
        goto L_0x00a74f48;
    }
    // 00a74f3b  3b4328                 +cmp eax, dword ptr [ebx + 0x28]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74f3e  7f22                   -jg 0xa74f62
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a74f62;
    }
    // 00a74f40  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
L_0x00a74f42:
    // 00a74f42  49                     -dec ecx
    (cpu.ecx)--;
    // 00a74f43  83f9ff                 +cmp ecx, -1
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
    // 00a74f46  7508                   -jne 0xa74f50
    if (!cpu.flags.zf)
    {
        goto L_0x00a74f50;
    }
L_0x00a74f48:
    // 00a74f48  837b2800               +cmp dword ptr [ebx + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a74f4c  7fd6                   -jg 0xa74f24
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a74f24;
    }
    // 00a74f4e  eb19                   -jmp 0xa74f69
    goto L_0x00a74f69;
L_0x00a74f50:
    // 00a74f50  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a74f52  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a74f54  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a74f56  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a74f58  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 00a74f5b  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a74f5c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a74f5d  894328                 -mov dword ptr [ebx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a74f60  ebe0                   -jmp 0xa74f42
    goto L_0x00a74f42;
L_0x00a74f62:
    // 00a74f62  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
L_0x00a74f69:
    // 00a74f69  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74f6c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f6d  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a74f6e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f6f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a74f70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a74f74(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a74f74  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a74f75  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a74f76  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a74f77  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a74f78  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a74f7b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a74f7d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a74f7f  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a74f81  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a74f83  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a74f8a  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 00a74f91  c7432800000000         -mov dword ptr [ebx + 0x28], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 00a74f98  c7432c00000000         -mov dword ptr [ebx + 0x2c], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 00a74f9f  c7433000000000         -mov dword ptr [ebx + 0x30], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00a74fa6  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a74fa8  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00a74fab  c7433400000000         -mov dword ptr [ebx + 0x34], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(52) /* 0x34 */) = 0 /*0x0*/;
    // 00a74fb2  3c69                   +cmp al, 0x69
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
    // 00a74fb4  721e                   -jb 0xa74fd4
    if (cpu.flags.cf)
    {
        goto L_0x00a74fd4;
    }
    // 00a74fb6  0f8692000000           -jbe 0xa7504e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7504e;
    }
    // 00a74fbc  3c75                   +cmp al, 0x75
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
    // 00a74fbe  720b                   -jb 0xa74fcb
    if (cpu.flags.cf)
    {
        goto L_0x00a74fcb;
    }
    // 00a74fc0  7625                   -jbe 0xa74fe7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a74fe7;
    }
    // 00a74fc2  3c78                   +cmp al, 0x78
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
    // 00a74fc4  7421                   -je 0xa74fe7
    if (cpu.flags.zf)
    {
        goto L_0x00a74fe7;
    }
    // 00a74fc6  e960010000             -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a74fcb:
    // 00a74fcb  3c6f                   +cmp al, 0x6f
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
    // 00a74fcd  7418                   -je 0xa74fe7
    if (cpu.flags.zf)
    {
        goto L_0x00a74fe7;
    }
    // 00a74fcf  e957010000             -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a74fd4:
    // 00a74fd4  3c58                   +cmp al, 0x58
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
    // 00a74fd6  0f824f010000           -jb 0xa7512b
    if (cpu.flags.cf)
    {
        goto L_0x00a7512b;
    }
    // 00a74fdc  7609                   -jbe 0xa74fe7
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a74fe7;
    }
    // 00a74fde  3c64                   +cmp al, 0x64
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
    // 00a74fe0  746c                   -je 0xa7504e
    if (cpu.flags.zf)
    {
        goto L_0x00a7504e;
    }
    // 00a74fe2  e944010000             -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a74fe7:
    // 00a74fe7  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a74feb  7420                   -je 0xa7500d
    if (cpu.flags.zf)
    {
        goto L_0x00a7500d;
    }
    // 00a74fed  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a74fef  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a74ff2  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a74ff4  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a74ff7  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a74ffa  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a74ffc  83c504                 +add ebp, 4
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
    // 00a74fff  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a75001  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a75004  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a75008  e91e010000             -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a7500d:
    // 00a7500d  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a75011  7413                   -je 0xa75026
    if (cpu.flags.zf)
    {
        goto L_0x00a75026;
    }
    // 00a75013  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75015  83c004                 +add eax, 4
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
    // 00a75018  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a7501a  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a7501d  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a75021  e905010000             -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a75026:
    // 00a75026  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75028  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7502b  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a7502d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a75030  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a75034  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a75038  0f84ed000000           -je 0xa7512b
    if (cpu.flags.zf)
    {
        goto L_0x00a7512b;
    }
    // 00a7503e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a75040  668b442408             -mov ax, word ptr [esp + 8]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a75045  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a75049  e9dd000000             -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a7504e:
    // 00a7504e  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a75052  741d                   -je 0xa75071
    if (cpu.flags.zf)
    {
        goto L_0x00a75071;
    }
    // 00a75054  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75056  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75059  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a7505b  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a7505e  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a75061  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75063  83c304                 +add ebx, 4
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
    // 00a75066  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a75068  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a7506b  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a7506f  eb33                   -jmp 0xa750a4
    goto L_0x00a750a4;
L_0x00a75071:
    // 00a75071  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a75075  740c                   -je 0xa75083
    if (cpu.flags.zf)
    {
        goto L_0x00a75083;
    }
    // 00a75077  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75079  83c504                 +add ebp, 4
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
    // 00a7507c  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a7507e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a75081  eb1d                   -jmp 0xa750a0
    goto L_0x00a750a0;
L_0x00a75083:
    // 00a75083  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75085  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75088  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a7508a  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a7508d  8a791e                 -mov bh, byte ptr [ecx + 0x1e]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a75090  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a75094  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 00a75097  740b                   -je 0xa750a4
    if (cpu.flags.zf)
    {
        goto L_0x00a750a4;
    }
    // 00a75099  8b442406               -mov eax, dword ptr [esp + 6]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00a7509d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
L_0x00a750a0:
    // 00a750a0  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00a750a4:
    // 00a750a4  8a591f                 -mov bl, byte ptr [ecx + 0x1f]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00a750a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a750a9  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 00a750ac  7409                   -je 0xa750b7
    if (cpu.flags.zf)
    {
        goto L_0x00a750b7;
    }
    // 00a750ae  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00a750b3  7409                   -je 0xa750be
    if (cpu.flags.zf)
    {
        goto L_0x00a750be;
    }
    // 00a750b5  eb0b                   -jmp 0xa750c2
    goto L_0x00a750c2;
L_0x00a750b7:
    // 00a750b7  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a750bc  7c04                   -jl 0xa750c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a750c2;
    }
L_0x00a750be:
    // 00a750be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a750c0  7442                   -je 0xa75104
    if (cpu.flags.zf)
    {
        goto L_0x00a75104;
    }
L_0x00a750c2:
    // 00a750c2  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a750c5  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a750c8  895920                 -mov dword ptr [ecx + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a750cb  c604062d               -mov byte ptr [esi + eax], 0x2d
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00a750cf  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a750d3  7429                   -je 0xa750fe
    if (cpu.flags.zf)
    {
        goto L_0x00a750fe;
    }
    // 00a750d5  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a750d8  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a750dc  f7d3                   -not ebx
    cpu.ebx = ~cpu.ebx;
    // 00a750de  f7d5                   -not ebp
    cpu.ebp = ~cpu.ebp;
    // 00a750e0  891c24                 -mov dword ptr [esp], ebx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00a750e3  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a750e6  896c2404               -mov dword ptr [esp + 4], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00a750ea  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a750ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a750ef  7505                   -jne 0xa750f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a750f6;
    }
    // 00a750f1  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a750f4  eb02                   -jmp 0xa750f8
    goto L_0x00a750f8;
L_0x00a750f6:
    // 00a750f6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a750f8:
    // 00a750f8  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a750fc  eb2d                   -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a750fe:
    // 00a750fe  f75c2408               +neg dword ptr [esp + 8]
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00a75102  eb27                   -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a75104:
    // 00a75104  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a75107  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 00a75109  740f                   -je 0xa7511a
    if (cpu.flags.zf)
    {
        goto L_0x00a7511a;
    }
    // 00a7510b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a7510e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a75111  895920                 -mov dword ptr [ecx + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a75114  c604062b               -mov byte ptr [esi + eax], 0x2b
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a75118  eb11                   -jmp 0xa7512b
    goto L_0x00a7512b;
L_0x00a7511a:
    // 00a7511a  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00a7511c  740d                   -je 0xa7512b
    if (cpu.flags.zf)
    {
        goto L_0x00a7512b;
    }
    // 00a7511e  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a75121  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a75124  895920                 -mov dword ptr [ecx + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00a75127  c6040620               -mov byte ptr [esi + eax], 0x20
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00a7512b:
    // 00a7512b  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a7512e  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00a75133  3c64                   +cmp al, 0x64
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
    // 00a75135  7261                   -jb 0xa75198
    if (cpu.flags.cf)
    {
        goto L_0x00a75198;
    }
    // 00a75137  0f860b020000           -jbe 0xa75348
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a75348;
    }
    // 00a7513d  3c6f                   +cmp al, 0x6f
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
    // 00a7513f  7238                   -jb 0xa75179
    if (cpu.flags.cf)
    {
        goto L_0x00a75179;
    }
    // 00a75141  0f86e1010000           -jbe 0xa75328
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a75328;
    }
    // 00a75147  3c73                   +cmp al, 0x73
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
    // 00a75149  7221                   -jb 0xa7516c
    if (cpu.flags.cf)
    {
        goto L_0x00a7516c;
    }
    // 00a7514b  0f86f0000000           -jbe 0xa75241
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a75241;
    }
    // 00a75151  3c75                   +cmp al, 0x75
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
    // 00a75153  0f8204040000           -jb 0xa7555d
    if (cpu.flags.cf)
    {
        goto L_0x00a7555d;
    }
    // 00a75159  0f86e9010000           -jbe 0xa75348
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a75348;
    }
    // 00a7515f  3c78                   +cmp al, 0x78
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
    // 00a75161  0f847c010000           -je 0xa752e3
    if (cpu.flags.zf)
    {
        goto L_0x00a752e3;
    }
    // 00a75167  e9f1030000             -jmp 0xa7555d
    goto L_0x00a7555d;
L_0x00a7516c:
    // 00a7516c  3c70                   +cmp al, 0x70
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
    // 00a7516e  0f8489020000           -je 0xa753fd
    if (cpu.flags.zf)
    {
        goto L_0x00a753fd;
    }
    // 00a75174  e9e4030000             -jmp 0xa7555d
    goto L_0x00a7555d;
L_0x00a75179:
    // 00a75179  3c66                   +cmp al, 0x66
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
    // 00a7517b  0f829d000000           -jb 0xa7521e
    if (cpu.flags.cf)
    {
        goto L_0x00a7521e;
    }
    // 00a75181  7666                   -jbe 0xa751e9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a751e9;
    }
    // 00a75183  3c67                   +cmp al, 0x67
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
    // 00a75185  0f8693000000           -jbe 0xa7521e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7521e;
    }
    // 00a7518b  3c69                   +cmp al, 0x69
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
    // 00a7518d  0f84b5010000           -je 0xa75348
    if (cpu.flags.zf)
    {
        goto L_0x00a75348;
    }
    // 00a75193  e9c5030000             -jmp 0xa7555d
    goto L_0x00a7555d;
L_0x00a75198:
    // 00a75198  3c47                   +cmp al, 0x47
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
    // 00a7519a  7238                   -jb 0xa751d4
    if (cpu.flags.cf)
    {
        goto L_0x00a751d4;
    }
    // 00a7519c  0f867c000000           -jbe 0xa7521e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7521e;
    }
    // 00a751a2  3c53                   +cmp al, 0x53
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
    // 00a751a4  7221                   -jb 0xa751c7
    if (cpu.flags.cf)
    {
        goto L_0x00a751c7;
    }
    // 00a751a6  0f8695000000           -jbe 0xa75241
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a75241;
    }
    // 00a751ac  3c58                   +cmp al, 0x58
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
    // 00a751ae  0f82a9030000           -jb 0xa7555d
    if (cpu.flags.cf)
    {
        goto L_0x00a7555d;
    }
    // 00a751b4  0f8629010000           -jbe 0xa752e3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a752e3;
    }
    // 00a751ba  3c63                   +cmp al, 0x63
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
    // 00a751bc  0f84ce020000           -je 0xa75490
    if (cpu.flags.zf)
    {
        goto L_0x00a75490;
    }
    // 00a751c2  e996030000             -jmp 0xa7555d
    goto L_0x00a7555d;
L_0x00a751c7:
    // 00a751c7  3c50                   +cmp al, 0x50
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
    // 00a751c9  0f842e020000           -je 0xa753fd
    if (cpu.flags.zf)
    {
        goto L_0x00a753fd;
    }
    // 00a751cf  e989030000             -jmp 0xa7555d
    goto L_0x00a7555d;
L_0x00a751d4:
    // 00a751d4  3c45                   +cmp al, 0x45
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
    // 00a751d6  7204                   -jb 0xa751dc
    if (cpu.flags.cf)
    {
        goto L_0x00a751dc;
    }
    // 00a751d8  7644                   -jbe 0xa7521e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7521e;
    }
    // 00a751da  eb0d                   -jmp 0xa751e9
    goto L_0x00a751e9;
L_0x00a751dc:
    // 00a751dc  3c43                   +cmp al, 0x43
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
    // 00a751de  0f8438030000           -je 0xa7551c
    if (cpu.flags.zf)
    {
        goto L_0x00a7551c;
    }
    // 00a751e4  e974030000             -jmp 0xa7555d
    goto L_0x00a7555d;
L_0x00a751e9:
    // 00a751e9  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a751ed  742f                   -je 0xa7521e
    if (cpu.flags.zf)
    {
        goto L_0x00a7521e;
    }
    // 00a751ef  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a751f1  83c304                 +add ebx, 4
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
    // 00a751f4  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a751f6  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a751f9  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a751fd  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a751ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a75201  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a75203  e8c0fbffff             -call 0xa74dc8
    cpu.esp -= 4;
    sub_a74dc8(app, cpu);
    if (cpu.terminate) return;
    // 00a75208  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a7520d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a7520f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a75211  e8befaffff             -call 0xa74cd4
    cpu.esp -= 4;
    sub_a74cd4(app, cpu);
    if (cpu.terminate) return;
    // 00a75216  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a75219  e952030000             -jmp 0xa75570
    goto L_0x00a75570;
L_0x00a7521e:
    // 00a7521e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a75220  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a75222  e89dfcffff             -call 0xa74ec4
    cpu.esp -= 4;
    sub_a74ec4(app, cpu);
    if (cpu.terminate) return;
    // 00a75227  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a75229  e89efcffff             -call 0xa74ecc
    cpu.esp -= 4;
    sub_a74ecc(app, cpu);
    if (cpu.terminate) return;
    // 00a7522e  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a75230  8d7e01                 -lea edi, [esi + 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a75233  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a75235  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a75237  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a75239  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7523c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7523d  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7523e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7523f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75240  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75241:
    // 00a75241  c60600                 -mov byte ptr [esi], 0
    *app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00a75244  8a411e                 -mov al, byte ptr [ecx + 0x1e]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a75247  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a75249  741d                   -je 0xa75268
    if (cpu.flags.zf)
    {
        goto L_0x00a75268;
    }
    // 00a7524b  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a7524d  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a75250  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a75252  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00a75255  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a75259  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7525b  7505                   -jne 0xa75262
    if (!cpu.flags.zf)
    {
        goto L_0x00a75262;
    }
    // 00a7525d  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 00a75260  742e                   -je 0xa75290
    if (cpu.flags.zf)
    {
        goto L_0x00a75290;
    }
L_0x00a75262:
    // 00a75262  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a75264  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a75266  eb28                   -jmp 0xa75290
    goto L_0x00a75290;
L_0x00a75268:
    // 00a75268  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00a7526a  7410                   -je 0xa7527c
    if (cpu.flags.zf)
    {
        goto L_0x00a7527c;
    }
    // 00a7526c  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a7526e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75271  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00a75273  8b46fc                 -mov eax, dword ptr [esi - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */);
    // 00a75276  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75278  7416                   -je 0xa75290
    if (cpu.flags.zf)
    {
        goto L_0x00a75290;
    }
    // 00a7527a  eb0e                   -jmp 0xa7528a
    goto L_0x00a7528a;
L_0x00a7527c:
    // 00a7527c  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a7527e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75281  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a75283  8b43fc                 -mov eax, dword ptr [ebx - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a75286  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75288  7406                   -je 0xa75290
    if (cpu.flags.zf)
    {
        goto L_0x00a75290;
    }
L_0x00a7528a:
    // 00a7528a  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a7528c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7528e  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
L_0x00a75290:
    // 00a75290  80791553               +cmp byte ptr [ecx + 0x15], 0x53
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(83 /*0x53*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a75294  7508                   -jne 0xa7529e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7529e;
    }
    // 00a75296  f6411e10               +test byte ptr [ecx + 0x1e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 16 /*0x10*/));
    // 00a7529a  7408                   -je 0xa752a4
    if (cpu.flags.zf)
    {
        goto L_0x00a752a4;
    }
    // 00a7529c  eb14                   -jmp 0xa752b2
    goto L_0x00a752b2;
L_0x00a7529e:
    // 00a7529e  f6411e20               +test byte ptr [ecx + 0x1e], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 32 /*0x20*/));
    // 00a752a2  740e                   -je 0xa752b2
    if (cpu.flags.zf)
    {
        goto L_0x00a752b2;
    }
L_0x00a752a4:
    // 00a752a4  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a752a6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a752a8  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a752ab  e848faffff             -call 0xa74cf8
    cpu.esp -= 4;
    sub_a74cf8(app, cpu);
    if (cpu.terminate) return;
    // 00a752b0  eb0c                   -jmp 0xa752be
    goto L_0x00a752be;
L_0x00a752b2:
    // 00a752b2  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a752b4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a752b6  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a752b9  e816faffff             -call 0xa74cd4
    cpu.esp -= 4;
    sub_a74cd4(app, cpu);
    if (cpu.terminate) return;
L_0x00a752be:
    // 00a752be  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a752c1  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a752c4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a752c6  0f8ca4020000           -jl 0xa75570
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a75570;
    }
    // 00a752cc  39d0                   +cmp eax, edx
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
    // 00a752ce  0f8e9c020000           -jle 0xa75570
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a75570;
    }
    // 00a752d4  895128                 -mov dword ptr [ecx + 0x28], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a752d7  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a752d9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a752db  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a752de  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a752df  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a752e0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a752e1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a752e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a752e3:
    // 00a752e3  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00a752e7  743a                   -je 0xa75323
    if (cpu.flags.zf)
    {
        goto L_0x00a75323;
    }
    // 00a752e9  f6411f01               +test byte ptr [ecx + 0x1f], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */) & 1 /*0x1*/));
    // 00a752ed  740f                   -je 0xa752fe
    if (cpu.flags.zf)
    {
        goto L_0x00a752fe;
    }
    // 00a752ef  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a752f3  7510                   -jne 0xa75305
    if (!cpu.flags.zf)
    {
        goto L_0x00a75305;
    }
    // 00a752f5  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a752fa  7427                   -je 0xa75323
    if (cpu.flags.zf)
    {
        goto L_0x00a75323;
    }
    // 00a752fc  eb07                   -jmp 0xa75305
    goto L_0x00a75305;
L_0x00a752fe:
    // 00a752fe  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a75303  741e                   -je 0xa75323
    if (cpu.flags.zf)
    {
        goto L_0x00a75323;
    }
L_0x00a75305:
    // 00a75305  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a75308  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7530b  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a7530e  c6040630               -mov byte ptr [esi + eax], 0x30
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
    // 00a75312  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a75315  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a75318  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a7531b  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 00a7531e  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a75321  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
L_0x00a75323:
    // 00a75323  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x00a75328:
    // 00a75328  8079156f               +cmp byte ptr [ecx + 0x15], 0x6f
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(111 /*0x6f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a7532c  751a                   -jne 0xa75348
    if (!cpu.flags.zf)
    {
        goto L_0x00a75348;
    }
    // 00a7532e  8a511e                 -mov dl, byte ptr [ecx + 0x1e]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a75331  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a75336  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a75339  740d                   -je 0xa75348
    if (cpu.flags.zf)
    {
        goto L_0x00a75348;
    }
    // 00a7533b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a7533e  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a75341  895120                 -mov dword ptr [ecx + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a75344  c6040630               -mov byte ptr [esi + eax], 0x30
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 48 /*0x30*/;
L_0x00a75348:
    // 00a75348  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a7534a  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a7534d  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a7534f  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a75351  8a711f                 -mov dh, byte ptr [ecx + 0x1f]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(31) /* 0x1f */);
    // 00a75354  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a75356  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 00a75359  7436                   -je 0xa75391
    if (cpu.flags.zf)
    {
        goto L_0x00a75391;
    }
    // 00a7535b  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7535f  7515                   -jne 0xa75376
    if (!cpu.flags.zf)
    {
        goto L_0x00a75376;
    }
    // 00a75361  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75365  750f                   -jne 0xa75376
    if (!cpu.flags.zf)
    {
        goto L_0x00a75376;
    }
    // 00a75367  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a7536c  7508                   -jne 0xa75376
    if (!cpu.flags.zf)
    {
        goto L_0x00a75376;
    }
    // 00a7536e  26c60000               -mov byte ptr es:[eax], 0
    *app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00a75372  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a75374  eb59                   -jmp 0xa753cf
    goto L_0x00a753cf;
L_0x00a75376:
    // 00a75376  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a75379  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a7537b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a7537d  e8de200000             -call 0xa77460
    cpu.esp -= 4;
    sub_a77460(app, cpu);
    if (cpu.terminate) return;
    // 00a75382  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a75386  7539                   -jne 0xa753c1
    if (!cpu.flags.zf)
    {
        goto L_0x00a753c1;
    }
    // 00a75388  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7538a  e8ed010000             -call 0xa7557c
    cpu.esp -= 4;
    sub_a7557c(app, cpu);
    if (cpu.terminate) return;
    // 00a7538f  eb30                   -jmp 0xa753c1
    goto L_0x00a753c1;
L_0x00a75391:
    // 00a75391  83790800               +cmp dword ptr [ecx + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75395  750f                   -jne 0xa753a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a753a6;
    }
    // 00a75397  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00a7539c  7508                   -jne 0xa753a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a753a6;
    }
    // 00a7539e  26c60000               -mov byte ptr es:[eax], 0
    *app->getMemory<x86::reg8>(cpu.ees + cpu.eax) = 0 /*0x0*/;
    // 00a753a2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a753a4  eb29                   -jmp 0xa753cf
    goto L_0x00a753cf;
L_0x00a753a6:
    // 00a753a6  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a753a9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a753ad  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00a753af  e89c210000             -call 0xa77550
    cpu.esp -= 4;
    sub_a77550(app, cpu);
    if (cpu.terminate) return;
    // 00a753b4  80791558               +cmp byte ptr [ecx + 0x15], 0x58
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a753b8  7507                   -jne 0xa753c1
    if (!cpu.flags.zf)
    {
        goto L_0x00a753c1;
    }
    // 00a753ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a753bc  e8bb010000             -call 0xa7557c
    cpu.esp -= 4;
    sub_a7557c(app, cpu);
    if (cpu.terminate) return;
L_0x00a753c1:
    // 00a753c1  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a753c6  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a753c8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a753ca  e805f9ffff             -call 0xa74cd4
    cpu.esp -= 4;
    sub_a74cd4(app, cpu);
    if (cpu.terminate) return;
L_0x00a753cf:
    // 00a753cf  894128                 -mov dword ptr [ecx + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a753d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a753d4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a753d7  39c2                   +cmp edx, eax
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
    // 00a753d9  7d05                   -jge 0xa753e0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a753e0;
    }
    // 00a753db  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a753dd  894124                 -mov dword ptr [ecx + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00a753e0:
    // 00a753e0  837908ff               +cmp dword ptr [ecx + 8], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a753e4  0f8586010000           -jne 0xa75570
    if (!cpu.flags.zf)
    {
        goto L_0x00a75570;
    }
    // 00a753ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a753ec  e8dbfaffff             -call 0xa74ecc
    cpu.esp -= 4;
    sub_a74ecc(app, cpu);
    if (cpu.terminate) return;
    // 00a753f1  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a753f3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a753f5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a753f8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a753f9  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a753fa  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a753fb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a753fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a753fd:
    // 00a753fd  83790400               +cmp dword ptr [ecx + 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75401  7516                   -jne 0xa75419
    if (!cpu.flags.zf)
    {
        goto L_0x00a75419;
    }
    // 00a75403  f6411e80               +test byte ptr [ecx + 0x1e], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 128 /*0x80*/));
    // 00a75407  7409                   -je 0xa75412
    if (cpu.flags.zf)
    {
        goto L_0x00a75412;
    }
    // 00a75409  c741040d000000         -mov dword ptr [ecx + 4], 0xd
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
    // 00a75410  eb07                   -jmp 0xa75419
    goto L_0x00a75419;
L_0x00a75412:
    // 00a75412  c7410408000000         -mov dword ptr [ecx + 4], 8
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
L_0x00a75419:
    // 00a75419  80611ef9               -and byte ptr [ecx + 0x1e], 0xf9
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) &= x86::reg8(x86::sreg8(249 /*0xf9*/));
    // 00a7541d  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a7541f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75422  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a75424  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a75427  8b68fc                 -mov ebp, dword ptr [eax - 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a7542a  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00a7542d  7429                   -je 0xa75458
    if (cpu.flags.zf)
    {
        goto L_0x00a75458;
    }
    // 00a7542f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75432  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a75434  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00a75439  8b40fc                 -mov eax, dword ptr [eax - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a7543c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7543e  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a75443  e81cf9ffff             -call 0xa74d64
    cpu.esp -= 4;
    sub_a74d64(app, cpu);
    if (cpu.terminate) return;
    // 00a75448  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a7544d  8d5605                 -lea edx, [esi + 5]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 00a75450  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a75452  c646043a               -mov byte ptr [esi + 4], 0x3a
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) = 58 /*0x3a*/;
    // 00a75456  eb09                   -jmp 0xa75461
    goto L_0x00a75461;
L_0x00a75458:
    // 00a75458  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00a7545d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7545f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a75461:
    // 00a75461  e8fef8ffff             -call 0xa74d64
    cpu.esp -= 4;
    sub_a74d64(app, cpu);
    if (cpu.terminate) return;
    // 00a75466  80791550               +cmp byte ptr [ecx + 0x15], 0x50
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(80 /*0x50*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a7546a  7507                   -jne 0xa75473
    if (!cpu.flags.zf)
    {
        goto L_0x00a75473;
    }
    // 00a7546c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7546e  e809010000             -call 0xa7557c
    cpu.esp -= 4;
    sub_a7557c(app, cpu);
    if (cpu.terminate) return;
L_0x00a75473:
    // 00a75473  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00a75478  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a7547a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7547c  e853f8ffff             -call 0xa74cd4
    cpu.esp -= 4;
    sub_a74cd4(app, cpu);
    if (cpu.terminate) return;
    // 00a75481  894120                 -mov dword ptr [ecx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a75484  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a75486  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a75488  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a7548b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7548c  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7548d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7548e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7548f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75490:
    // 00a75490  8a591e                 -mov bl, byte ptr [ecx + 0x1e]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a75493  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 00a7549a  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 00a7549d  7465                   -je 0xa75504
    if (cpu.flags.zf)
    {
        goto L_0x00a75504;
    }
    // 00a7549f  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a754a1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a754a4  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a754a6  668b43fc               -mov ax, word ptr [ebx - 4]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-4) /* -0x4 */);
    // 00a754aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a754ac  6689c2                 -mov dx, ax
    cpu.dx = cpu.ax;
    // 00a754af  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a754b3  e8d81e0000             -call 0xa77390
    cpu.esp -= 4;
    sub_a77390(app, cpu);
    if (cpu.terminate) return;
    // 00a754b8  83f8ff                 +cmp eax, -1
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
    // 00a754bb  0f84af000000           -je 0xa75570
    if (cpu.flags.zf)
    {
        goto L_0x00a75570;
    }
    // 00a754c1  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a754c5  8b2df00da800           -mov ebp, dword ptr [0xa80df0]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */);
    // 00a754cb  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a754cd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a754cf  0f849b000000           -je 0xa75570
    if (cpu.flags.zf)
    {
        goto L_0x00a75570;
    }
    // 00a754d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a754d7  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a754db  8a80010ea800           -mov al, byte ptr [eax + 0xa80e01]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a754e1  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a754e3  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a754e8  0f8482000000           -je 0xa75570
    if (cpu.flags.zf)
    {
        goto L_0x00a75570;
    }
    // 00a754ee  8a44240d               -mov al, byte ptr [esp + 0xd]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(13) /* 0xd */);
    // 00a754f2  884601                 -mov byte ptr [esi + 1], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a754f5  ff4120                 -inc dword ptr [ecx + 0x20]
    (*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */))++;
    // 00a754f8  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a754fa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a754fc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a754ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75500  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a75501  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75502  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75503  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75504:
    // 00a75504  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75506  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75509  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a7550b  8a40fc                 -mov al, byte ptr [eax - 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a7550e  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a75510  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a75512  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a75514  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a75517  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75518  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a75519  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7551a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7551b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7551c:
    // 00a7551c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a7551e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75521  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a75523  668b55fc               -mov dx, word ptr [ebp - 4]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a75527  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a7552d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7552f  e85c1e0000             -call 0xa77390
    cpu.esp -= 4;
    sub_a77390(app, cpu);
    if (cpu.terminate) return;
    // 00a75534  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a75536  83f8ff                 +cmp eax, -1
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
    // 00a75539  740f                   -je 0xa7554a
    if (cpu.flags.zf)
    {
        goto L_0x00a7554a;
    }
    // 00a7553b  894120                 -mov dword ptr [ecx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00a7553e  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a75540  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a75542  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a75545  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75546  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a75547  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75548  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75549  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7554a:
    // 00a7554a  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00a75551  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a75553  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a75555  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a75558  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75559  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7555a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7555b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7555c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7555d:
    // 00a7555d  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a75564  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a75567  8806                   -mov byte ptr [esi], al
    *app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 00a75569  c7412001000000         -mov dword ptr [ecx + 0x20], 1
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x00a75570:
    // 00a75570  8cc2                   -mov edx, es
    cpu.edx = cpu.es;
    // 00a75572  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a75574  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a75577  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75578  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a75579  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7557a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7557b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7557c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7557c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7557d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7557e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a75580  803800                 +cmp byte ptr [eax], 0
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
    // 00a75583  7413                   -je 0xa75598
    if (cpu.flags.zf)
    {
        goto L_0x00a75598;
    }
L_0x00a75585:
    // 00a75585  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75587  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a75589  e852200000             -call 0xa775e0
    cpu.esp -= 4;
    sub_a775e0(app, cpu);
    if (cpu.terminate) return;
    // 00a7558e  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00a75590  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a75593  42                     -inc edx
    (cpu.edx)++;
    // 00a75594  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00a75596  75ed                   -jne 0xa75585
    if (!cpu.flags.zf)
    {
        goto L_0x00a75585;
    }
L_0x00a75598:
    // 00a75598  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75599  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7559a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a755a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a755a0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a755a1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a755a2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a755a3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a755a4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a755a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a755a8  0f849a000000           -je 0xa75648
    if (cpu.flags.zf)
    {
        goto L_0x00a75648;
    }
    // 00a755ae  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a755b1  39c1                   +cmp ecx, eax
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
    // 00a755b3  0f828f000000           -jb 0xa75648
    if (cpu.flags.cf)
    {
        goto L_0x00a75648;
    }
    // 00a755b9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a755bb  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a755be  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00a755c1  83f910                 +cmp ecx, 0x10
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
    // 00a755c4  7305                   -jae 0xa755cb
    if (!cpu.flags.cf)
    {
        goto L_0x00a755cb;
    }
    // 00a755c6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x00a755cb:
    // 00a755cb  39c1                   +cmp ecx, eax
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
    // 00a755cd  0f8775000000           -ja 0xa75648
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a75648;
    }
    // 00a755d3  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00a755d6  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00a755d9  39d9                   +cmp ecx, ebx
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
    // 00a755db  7705                   -ja 0xa755e2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a755e2;
    }
    // 00a755dd  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a755e0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a755e2:
    // 00a755e2  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00a755e5:
    // 00a755e5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a755e7  39d1                   +cmp ecx, edx
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
    // 00a755e9  7612                   -jbe 0xa755fd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a755fd;
    }
    // 00a755eb  39da                   +cmp edx, ebx
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
    // 00a755ed  7602                   -jbe 0xa755f1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a755f1;
    }
    // 00a755ef  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00a755f1:
    // 00a755f1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a755f4  39f0                   +cmp eax, esi
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
    // 00a755f6  75ed                   -jne 0xa755e5
    if (!cpu.flags.zf)
    {
        goto L_0x00a755e5;
    }
    // 00a755f8  895f14                 -mov dword ptr [edi + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00a755fb  eb4b                   -jmp 0xa75648
    goto L_0x00a75648;
L_0x00a755fd:
    // 00a755fd  895f10                 -mov dword ptr [edi + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a75600  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00a75603  43                     -inc ebx
    (cpu.ebx)++;
    // 00a75604  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a75606  895f18                 -mov dword ptr [edi + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a75609  83fa10                 +cmp edx, 0x10
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
    // 00a7560c  721e                   -jb 0xa7562c
    if (cpu.flags.cf)
    {
        goto L_0x00a7562c;
    }
    // 00a7560e  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00a75611  895f0c                 -mov dword ptr [edi + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a75614  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a75616  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a75618  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a7561b  894b04                 -mov dword ptr [ebx + 4], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a7561e  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a75621  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a75624  895908                 -mov dword ptr [ecx + 8], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a75627  895a04                 -mov dword ptr [edx + 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a7562a  eb12                   -jmp 0xa7563e
    goto L_0x00a7563e;
L_0x00a7562c:
    // 00a7562c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 00a7562f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a75632  89570c                 -mov dword ptr [edi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a75635  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a75638  895a08                 -mov dword ptr [edx + 8], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a7563b  895304                 -mov dword ptr [ebx + 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a7563e:
    // 00a7563e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a75640  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a75643  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a75646  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a75648:
    // 00a75648  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a7564a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7564b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7564c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7564d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7564e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a75650(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75650  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75651  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75652  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75653  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75654  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a75656  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75658  0f841d010000           -je 0xa7577b
    if (cpu.flags.zf)
    {
        goto L_0x00a7577b;
    }
    // 00a7565e  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a75661  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 00a75664  0f8411010000           -je 0xa7577b
    if (cpu.flags.zf)
    {
        goto L_0x00a7577b;
    }
    // 00a7566a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a7566c  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a7566f  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00a75672  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a75674  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a75677  7522                   -jne 0xa7569b
    if (!cpu.flags.zf)
    {
        goto L_0x00a7569b;
    }
    // 00a75679  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a7567b  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a7567d  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a7567f  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75682  7503                   -jne 0xa75687
    if (!cpu.flags.zf)
    {
        goto L_0x00a75687;
    }
    // 00a75684  89590c                 -mov dword ptr [ecx + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00a75687:
    // 00a75687  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a7568a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7568d  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a75690  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a75693  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a75696  e994000000             -jmp 0xa7572f
    goto L_0x00a7572f;
L_0x00a7569b:
    // 00a7569b  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a7569d  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a756a0  39c3                   +cmp ebx, eax
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
    // 00a756a2  7316                   -jae 0xa756ba
    if (!cpu.flags.cf)
    {
        goto L_0x00a756ba;
    }
    // 00a756a4  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a756a7  0f8782000000           -ja 0xa7572f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7572f;
    }
    // 00a756ad  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00a756b0  39c3                   +cmp ebx, eax
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
    // 00a756b2  0f8277000000           -jb 0xa7572f
    if (cpu.flags.cf)
    {
        goto L_0x00a7572f;
    }
    // 00a756b8  eb19                   -jmp 0xa756d3
    goto L_0x00a756d3;
L_0x00a756ba:
    // 00a756ba  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a756bd  39c3                   +cmp ebx, eax
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
    // 00a756bf  0f826a000000           -jb 0xa7572f
    if (cpu.flags.cf)
    {
        goto L_0x00a7572f;
    }
    // 00a756c5  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a756c8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a756cb  39d3                   +cmp ebx, edx
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
    // 00a756cd  0f875c000000           -ja 0xa7572f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7572f;
    }
L_0x00a756d3:
    // 00a756d3  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a756d6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a756d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a756db  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a756de  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a756e0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a756e2  39f8                   +cmp eax, edi
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
    // 00a756e4  7328                   -jae 0xa7570e
    if (!cpu.flags.cf)
    {
        goto L_0x00a7570e;
    }
    // 00a756e6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a756e9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a756eb  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a756ed  39f8                   +cmp eax, edi
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
    // 00a756ef  7705                   -ja 0xa756f6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a756f6;
    }
    // 00a756f1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00a756f6:
    // 00a756f6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a756f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a756fa:
    // 00a756fa  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a756fc  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a756ff  742e                   -je 0xa7572f
    if (cpu.flags.zf)
    {
        goto L_0x00a7572f;
    }
    // 00a75701  83faff                 +cmp edx, -1
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
    // 00a75704  7408                   -je 0xa7570e
    if (cpu.flags.zf)
    {
        goto L_0x00a7570e;
    }
    // 00a75706  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a75709  01d0                   +add eax, edx
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
    // 00a7570b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a7570c  75ec                   -jne 0xa756fa
    if (!cpu.flags.zf)
    {
        goto L_0x00a756fa;
    }
L_0x00a7570e:
    // 00a7570e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a75711  39c3                   +cmp ebx, eax
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
    // 00a75713  7303                   -jae 0xa75718
    if (!cpu.flags.cf)
    {
        goto L_0x00a75718;
    }
    // 00a75715  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x00a75718:
    // 00a75718  39c3                   +cmp ebx, eax
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
    // 00a7571a  7213                   -jb 0xa7572f
    if (cpu.flags.cf)
    {
        goto L_0x00a7572f;
    }
    // 00a7571c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7571f  39c3                   +cmp ebx, eax
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
    // 00a75721  720c                   -jb 0xa7572f
    if (cpu.flags.cf)
    {
        goto L_0x00a7572f;
    }
    // 00a75723  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a75726  39c3                   +cmp ebx, eax
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
    // 00a75728  7205                   -jb 0xa7572f
    if (cpu.flags.cf)
    {
        goto L_0x00a7572f;
    }
    // 00a7572a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7572d  ebe9                   -jmp 0xa75718
    goto L_0x00a75718;
L_0x00a7572f:
    // 00a7572f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a75732  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75734  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a75736  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a75738  39df                   +cmp edi, ebx
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
    // 00a7573a  7512                   -jne 0xa7574e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7574e;
    }
    // 00a7573c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a7573e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a75740  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a75742  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75745  7503                   -jne 0xa7574a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7574a;
    }
    // 00a75747  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00a7574a:
    // 00a7574a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a7574c  eb0f                   -jmp 0xa7575d
    goto L_0x00a7575d;
L_0x00a7574e:
    // 00a7574e  ff461c                 -inc dword ptr [esi + 0x1c]
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 00a75751  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a75754  895304                 -mov dword ptr [ebx + 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a75757  895a08                 -mov dword ptr [edx + 8], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a7575a  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a7575d:
    // 00a7575d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a75760  4a                     -dec edx
    (cpu.edx)--;
    // 00a75761  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a75764  895618                 -mov dword ptr [esi + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a75767  39fb                   +cmp ebx, edi
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
    // 00a75769  7308                   -jae 0xa75773
    if (!cpu.flags.cf)
    {
        goto L_0x00a75773;
    }
    // 00a7576b  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7576e  7603                   -jbe 0xa75773
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a75773;
    }
    // 00a75770  894e10                 -mov dword ptr [esi + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00a75773:
    // 00a75773  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75776  7603                   -jbe 0xa7577b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7577b;
    }
    // 00a75778  894e14                 -mov dword ptr [esi + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a7577b:
    // 00a7577b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7577c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7577d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7577e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7577f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a75780(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75780  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75781  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75782  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a75784  a178d1a700             -mov eax, dword ptr [0xa7d178]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */);
    // 00a75789  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7578b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7578d  740d                   -je 0xa7579c
    if (cpu.flags.zf)
    {
        goto L_0x00a7579c;
    }
L_0x00a7578f:
    // 00a7578f  39c2                   +cmp edx, eax
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
    // 00a75791  7209                   -jb 0xa7579c
    if (cpu.flags.cf)
    {
        goto L_0x00a7579c;
    }
    // 00a75793  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75795  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a75798  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7579a  75f3                   -jne 0xa7578f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7578f;
    }
L_0x00a7579c:
    // 00a7579c  895a04                 -mov dword ptr [edx + 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a7579f  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a757a2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a757a4  7405                   -je 0xa757ab
    if (cpu.flags.zf)
    {
        goto L_0x00a757ab;
    }
    // 00a757a6  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a757a9  eb06                   -jmp 0xa757b1
    goto L_0x00a757b1;
L_0x00a757ab:
    // 00a757ab  891578d1a700           -mov dword ptr [0xa7d178], edx
    *app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */) = cpu.edx;
L_0x00a757b1:
    // 00a757b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a757b3  7403                   -je 0xa757b8
    if (cpu.flags.zf)
    {
        goto L_0x00a757b8;
    }
    // 00a757b5  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a757b8:
    // 00a757b8  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00a757bb  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a757be  c742f400000000         -mov dword ptr [edx - 0xc], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 00a757c5  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 00a757cc  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00a757d3  c742f000000000         -mov dword ptr [edx - 0x10], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 00a757da  895af8                 -mov dword ptr [edx - 8], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00a757dd  8b42d4                 -mov eax, dword ptr [edx - 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-44) /* -0x2c */);
    // 00a757e0  895afc                 -mov dword ptr [edx - 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a757e3  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a757e6  895ae0                 -mov dword ptr [edx - 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a757e9  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a757eb  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 00a757f2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a757f4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a757f5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a757f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a757f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a757f8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a757f9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a757fa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a757fb  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a757fc  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a757fd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75800  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a75803  833d3cd4a70000         +cmp dword ptr [0xa7d43c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10998844) /* 0xa7d43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7580a  7507                   -jne 0xa75813
    if (!cpu.flags.zf)
    {
        goto L_0x00a75813;
    }
    // 00a7580c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a7580e  e998000000             -jmp 0xa758ab
    goto L_0x00a758ab;
L_0x00a75813:
    // 00a75813  833d28d3a700fe         +cmp dword ptr [0xa7d328], -2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10998568) /* 0xa7d328 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7581a  750b                   -jne 0xa75827
    if (!cpu.flags.zf)
    {
        goto L_0x00a75827;
    }
    // 00a7581c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7581e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75821  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75822  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75823  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75824  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75825  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75826  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75827:
    // 00a75827  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a75829  e89a000000             -call 0xa758c8
    cpu.esp -= 4;
    sub_a758c8(app, cpu);
    if (cpu.terminate) return;
    // 00a7582e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75830  0f8475000000           -je 0xa758ab
    if (cpu.flags.zf)
    {
        goto L_0x00a758ab;
    }
    // 00a75836  6a40                   -push 0x40
    *app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00a75838  6800100000             -push 0x1000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00a7583d  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a75841  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75842  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a75844  2eff1554bea700         -call dword ptr cs:[0xa7be54]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993236) /* 0xa7be54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7584b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7584d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7584f  745a                   -je 0xa758ab
    if (cpu.flags.zf)
    {
        goto L_0x00a758ab;
    }
    // 00a75851  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a75854  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a75857  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7585a  39f0                   +cmp eax, esi
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
    // 00a7585c  760b                   -jbe 0xa75869
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a75869;
    }
    // 00a7585e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75860  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75863  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75864  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75865  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75866  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75867  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75868  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75869:
    // 00a75869  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7586c  83f838                 +cmp eax, 0x38
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
    // 00a7586f  730b                   -jae 0xa7587c
    if (!cpu.flags.cf)
    {
        goto L_0x00a7587c;
    }
    // 00a75871  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75873  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75876  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75877  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75878  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75879  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7587a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7587b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7587c:
    // 00a7587c  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a7587e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a75880  e8fbfeffff             -call 0xa75780
    cpu.esp -= 4;
    sub_a75780(app, cpu);
    if (cpu.terminate) return;
    // 00a75885  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75887  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a75889  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a7588c  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a7588e  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a75890  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00a75893  c7421400000000         -mov dword ptr [edx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a7589a  47                     -inc edi
    (cpu.edi)++;
    // 00a7589b  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a7589e  897a18                 -mov dword ptr [edx + 0x18], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00a758a1  e8cae4ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a758a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a758ab:
    // 00a758ab  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a758ae  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a758af  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a758b0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a758b1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a758b2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a758b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a758b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a758b4  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a758b5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a758b7  e8641d0000             -call 0xa77620
    cpu.esp -= 4;
    sub_a77620(app, cpu);
    if (cpu.terminate) return;
    // 00a758bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a758be  e835ffffff             -call 0xa757f8
    cpu.esp -= 4;
    sub_a757f8(app, cpu);
    if (cpu.terminate) return;
    // 00a758c3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a758c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a758c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a758c8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a758c9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a758ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a758cc  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a758ce  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a758d1  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a758d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a758d5  743d                   -je 0xa75914
    if (cpu.flags.zf)
    {
        goto L_0x00a75914;
    }
    // 00a758d7  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a758d9  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a758dc  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a758de  7305                   -jae 0xa758e5
    if (!cpu.flags.cf)
    {
        goto L_0x00a758e5;
    }
    // 00a758e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a758e2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a758e3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a758e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a758e5:
    // 00a758e5  8b0d40d4a700           -mov ecx, dword ptr [0xa7d440]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10998848) /* 0xa7d440 */);
    // 00a758eb  39c8                   +cmp eax, ecx
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
    // 00a758ed  7304                   -jae 0xa758f3
    if (!cpu.flags.cf)
    {
        goto L_0x00a758f3;
    }
    // 00a758ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a758f1  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00a758f3:
    // 00a758f3  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a758f5  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a758fa  3b02                   +cmp eax, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a758fc  7305                   -jae 0xa75903
    if (!cpu.flags.cf)
    {
        goto L_0x00a75903;
    }
    // 00a758fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75900  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75901  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75902  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75903:
    // 00a75903  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00a75905  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00a75908  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a7590a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7590c  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a7590f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00a75914:
    // 00a75914  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75915  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75916  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a75920(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75920  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75922  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a75930(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75930  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75931  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75932  baf076a700             -mov edx, 0xa776f0
    cpu.edx = 10974960 /*0xa776f0*/;
    // 00a75937  bb0478a700             -mov ebx, 0xa77804
    cpu.ebx = 10975236 /*0xa77804*/;
    // 00a7593c  8915e4d3a700           -mov dword ptr [0xa7d3e4], edx
    *app->getMemory<x86::reg32>(x86::reg32(10998756) /* 0xa7d3e4 */) = cpu.edx;
    // 00a75942  891de8d3a700           -mov dword ptr [0xa7d3e8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10998760) /* 0xa7d3e8 */) = cpu.ebx;
    // 00a75948  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75949  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7594a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a75950(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75950  9b                     -wait 
    /*nothing*/;
    // 00a75951  dd30                   -fnsave dword ptr [eax]
    NFS2_ASSERT(false);
    // 00a75953  9b                     -wait 
    /*nothing*/;
    // 00a75954  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a75958(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75958  dd20                   -frstor dword ptr [eax]
    NFS2_ASSERT(false);
    // 00a7595a  9b                     -wait 
    /*nothing*/;
    // 00a7595b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7595c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7595c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7595d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7595e  803d89d1a70000         +cmp byte ptr [0xa7d189], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10998153) /* 0xa7d189 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a75965  7416                   -je 0xa7597d
    if (cpu.flags.zf)
    {
        goto L_0x00a7597d;
    }
    // 00a75967  ba5059a700             -mov edx, 0xa75950
    cpu.edx = 10967376 /*0xa75950*/;
    // 00a7596c  bb5859a700             -mov ebx, 0xa75958
    cpu.ebx = 10967384 /*0xa75958*/;
    // 00a75971  891544d4a700           -mov dword ptr [0xa7d444], edx
    *app->getMemory<x86::reg32>(x86::reg32(10998852) /* 0xa7d444 */) = cpu.edx;
    // 00a75977  891d48d4a700           -mov dword ptr [0xa7d448], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10998856) /* 0xa7d448 */) = cpu.ebx;
L_0x00a7597d:
    // 00a7597d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7597f  66a14cd4a700           -mov ax, word ptr [0xa7d44c]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(10998860) /* 0xa7d44c */);
    // 00a75985  e8a61e0000             -call 0xa77830
    cpu.esp -= 4;
    sub_a77830(app, cpu);
    if (cpu.terminate) return;
    // 00a7598a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7598b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7598c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a75990(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75990  803d89d1a70000         +cmp byte ptr [0xa7d189], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10998153) /* 0xa7d189 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a75997  75c3                   -jne 0xa7595c
    if (!cpu.flags.zf)
    {
        return sub_a7595c(app, cpu);
    }
    // 00a75999  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7599c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7599c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7599d  8a2588d1a700           -mov ah, byte ptr [0xa7d188]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(10998152) /* 0xa7d188 */);
    // 00a759a3  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a759a5  7537                   -jne 0xa759de
    if (!cpu.flags.zf)
    {
        goto L_0x00a759de;
    }
    // 00a759a7  882589d1a700           -mov byte ptr [0xa7d189], ah
    *app->getMemory<x86::reg8>(x86::reg32(10998153) /* 0xa7d189 */) = cpu.ah;
    // 00a759ad  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a759af  2bc0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a759b1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a759b2  dbe3                   -fninit 
    cpu.fpu.init();
    // 00a759b4  d93c24                 -fnstcw word ptr [esp]
    *app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 00a759b7  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a759b8  8ac4                   -mov al, ah
    cpu.al = cpu.ah;
    // 00a759ba  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a759bc  3c03                   +cmp al, 3
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
    // 00a759be  7509                   -jne 0xa759c9
    if (!cpu.flags.zf)
    {
        goto L_0x00a759c9;
    }
    // 00a759c0  e897ffffff             -call 0xa7595c
    cpu.esp -= 4;
    sub_a7595c(app, cpu);
    if (cpu.terminate) return;
    // 00a759c5  88c6                   -mov dh, al
    cpu.dh = cpu.al;
    // 00a759c7  88c2                   -mov dl, al
    cpu.dl = cpu.al;
L_0x00a759c9:
    // 00a759c9  803d64d3a70000         +cmp byte ptr [0xa7d364], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(10998628) /* 0xa7d364 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a759d0  750c                   -jne 0xa759de
    if (!cpu.flags.zf)
    {
        goto L_0x00a759de;
    }
    // 00a759d2  883588d1a700           -mov byte ptr [0xa7d188], dh
    *app->getMemory<x86::reg8>(x86::reg32(10998152) /* 0xa7d188 */) = cpu.dh;
    // 00a759d8  881589d1a700           -mov byte ptr [0xa7d189], dl
    *app->getMemory<x86::reg8>(x86::reg32(10998153) /* 0xa7d189 */) = cpu.dl;
L_0x00a759de:
    // 00a759de  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a759df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a759e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a759e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a75a00(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a75a00  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75a01  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75a02  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75a03  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75a04  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a75a08  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a75a0c  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00a75a10  83ff03                 +cmp edi, 3
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75a13  0f8777010000           -ja 0xa75b90
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a75b90;
    }
    // 00a75a19  2eff24bdf059a700       -jmp dword ptr cs:[edi*4 + 0xa759f0]
    cpu.ip = *app->getMemory<x86::reg32>(10967536 + cpu.edi * 4); goto dynamic_jump;
  case 0x00a75a21:
    // 00a75a21  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75a23  e8b0100000             -call 0xa76ad8
    cpu.esp -= 4;
    sub_a76ad8(app, cpu);
    if (cpu.terminate) return;
    // 00a75a28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75a2a  0f8462010000           -je 0xa75b92
    if (cpu.flags.zf)
    {
        goto L_0x00a75b92;
    }
    // 00a75a30  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75a31  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75a32  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75a33  e868e0ffff             -call 0xa73aa0
    cpu.esp -= 4;
    sub_a73aa0(app, cpu);
    if (cpu.terminate) return;
    // 00a75a38  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75a3a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75a3c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a3d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a3e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a3f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a40  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a75a43:
    // 00a75a43  8b155006a800           -mov edx, dword ptr [0xa80650]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11011664) /* 0xa80650 */);
    // 00a75a49  42                     -inc edx
    (cpu.edx)++;
    // 00a75a4a  89155006a800           -mov dword ptr [0xa80650], edx
    *app->getMemory<x86::reg32>(x86::reg32(11011664) /* 0xa80650 */) = cpu.edx;
    // 00a75a50  83fa01                 +cmp edx, 1
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
    // 00a75a53  7e16                   -jle 0xa75a6b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a75a6b;
    }
    // 00a75a55  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a75a57  e8041e0000             -call 0xa77860
    cpu.esp -= 4;
    sub_a77860(app, cpu);
    if (cpu.terminate) return;
    // 00a75a5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75a5e  740b                   -je 0xa75a6b
    if (cpu.flags.zf)
    {
        goto L_0x00a75a6b;
    }
    // 00a75a60  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a75a62  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75a64  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a65  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a66  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a67  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a68  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a75a6b:
    // 00a75a6b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a75a70  e857ecffff             -call 0xa746cc
    cpu.esp -= 4;
    sub_a746cc(app, cpu);
    if (cpu.terminate) return;
    // 00a75a75  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a75a77  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a75a79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a75a7e  e835e9ffff             -call 0xa743b8
    cpu.esp -= 4;
    sub_a743b8(app, cpu);
    if (cpu.terminate) return;
    // 00a75a83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75a85  750b                   -jne 0xa75a92
    if (!cpu.flags.zf)
    {
        goto L_0x00a75a92;
    }
    // 00a75a87  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a75a89  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75a8b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a8c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a8d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a8e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75a8f  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a75a92:
    // 00a75a92  e8e10f0000             -call 0xa76a78
    cpu.esp -= 4;
    sub_a76a78(app, cpu);
    if (cpu.terminate) return;
    // 00a75a97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75a99  750b                   -jne 0xa75aa6
    if (!cpu.flags.zf)
    {
        goto L_0x00a75aa6;
    }
    // 00a75a9b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a75a9d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75a9f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75aa0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75aa1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75aa2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75aa3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a75aa6:
    // 00a75aa6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75aa8  e82b100000             -call 0xa76ad8
    cpu.esp -= 4;
    sub_a76ad8(app, cpu);
    if (cpu.terminate) return;
    // 00a75aad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75aaf  750b                   -jne 0xa75abc
    if (!cpu.flags.zf)
    {
        goto L_0x00a75abc;
    }
    // 00a75ab1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a75ab3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75ab5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ab6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ab7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ab8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ab9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a75abc:
    // 00a75abc  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 00a75ac1  e806ecffff             -call 0xa746cc
    cpu.esp -= 4;
    sub_a746cc(app, cpu);
    if (cpu.terminate) return;
    // 00a75ac6  e8e9100000             -call 0xa76bb4
    cpu.esp -= 4;
    sub_a76bb4(app, cpu);
    if (cpu.terminate) return;
    // 00a75acb  833d50d4a70000         +cmp dword ptr [0xa7d450], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10998864) /* 0xa7d450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75ad2  7422                   -je 0xa75af6
    if (cpu.flags.zf)
    {
        goto L_0x00a75af6;
    }
    // 00a75ad4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75ad5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75ad6  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75ad7  ff1550d4a700           -call dword ptr [0xa7d450]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998864) /* 0xa7d450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75add  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75adf  7515                   -jne 0xa75af6
    if (!cpu.flags.zf)
    {
        goto L_0x00a75af6;
    }
    // 00a75ae1  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a75ae6  e831ecffff             -call 0xa7471c
    cpu.esp -= 4;
    sub_a7471c(app, cpu);
    if (cpu.terminate) return;
    // 00a75aeb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a75aed  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75aef  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75af0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75af1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75af2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75af3  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x00a75af6:
    // 00a75af6  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 00a75afb  e8ccebffff             -call 0xa746cc
    cpu.esp -= 4;
    sub_a746cc(app, cpu);
    if (cpu.terminate) return;
    // 00a75b00  e83b1e0000             -call 0xa77940
    cpu.esp -= 4;
    sub_a77940(app, cpu);
    if (cpu.terminate) return;
    // 00a75b05  ff15d4d2a700           -call dword ptr [0xa7d2d4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998484) /* 0xa7d2d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75b0b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75b0c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75b0d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75b0e  e88ddfffff             -call 0xa73aa0
    cpu.esp -= 4;
    sub_a73aa0(app, cpu);
    if (cpu.terminate) return;
    // 00a75b13  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75b15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75b17  7577                   -jne 0xa75b90
    if (!cpu.flags.zf)
    {
        goto L_0x00a75b90;
    }
    // 00a75b19  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a75b1e  e8f9ebffff             -call 0xa7471c
    cpu.esp -= 4;
    sub_a7471c(app, cpu);
    if (cpu.terminate) return;
    // 00a75b23  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75b25  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b26  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b27  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b28  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b29  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a75b2c:
    // 00a75b2c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75b2d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75b2e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75b2f  e86cdfffff             -call 0xa73aa0
    cpu.esp -= 4;
    sub_a73aa0(app, cpu);
    if (cpu.terminate) return;
    // 00a75b34  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75b36  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a75b3b  e8ec0f0000             -call 0xa76b2c
    cpu.esp -= 4;
    sub_a76b2c(app, cpu);
    if (cpu.terminate) return;
    // 00a75b40  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75b42  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b43  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b44  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b45  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b46  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  case 0x00a75b49:
    // 00a75b49  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75b4a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75b4b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75b4c  e84fdfffff             -call 0xa73aa0
    cpu.esp -= 4;
    sub_a73aa0(app, cpu);
    if (cpu.terminate) return;
    // 00a75b51  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a75b56  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75b58  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00a75b5d  e8baebffff             -call 0xa7471c
    cpu.esp -= 4;
    sub_a7471c(app, cpu);
    if (cpu.terminate) return;
    // 00a75b62  833d50d4a70000         +cmp dword ptr [0xa7d450], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10998864) /* 0xa7d450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75b69  7409                   -je 0xa75b74
    if (cpu.flags.zf)
    {
        goto L_0x00a75b74;
    }
    // 00a75b6b  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75b6c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75b6d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75b6e  ff1550d4a700           -call dword ptr [0xa7d450]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998864) /* 0xa7d450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a75b74:
    // 00a75b74  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00a75b79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75b7b  e89cebffff             -call 0xa7471c
    cpu.esp -= 4;
    sub_a7471c(app, cpu);
    if (cpu.terminate) return;
    // 00a75b80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a75b85  e8a20f0000             -call 0xa76b2c
    cpu.esp -= 4;
    sub_a76b2c(app, cpu);
    if (cpu.terminate) return;
    // 00a75b8a  ff0d5006a800           -dec dword ptr [0xa80650]
    (*app->getMemory<x86::reg32>(x86::reg32(11011664) /* 0xa80650 */))--;
L_0x00a75b90:
    // 00a75b90  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a75b92:
    // 00a75b92  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b93  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b94  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b95  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75b96  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a75ba0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75ba0  e9dbe0ffff             -jmp 0xa73c80
    return sub_a73c80(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a75ba8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75ba8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75ba9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75baa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75bab  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75bac  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75bad  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75bae  8b3d0400a800           -mov edi, dword ptr [0xa80004]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a75bb4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a75bb6  0f85c1000000           -jne 0xa75c7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a75c7d;
    }
    // 00a75bbc  8b2d69d3a700           -mov ebp, dword ptr [0xa7d369]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10998633) /* 0xa7d369 */);
    // 00a75bc2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a75bc4  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp);
    // 00a75bc7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a75bc9  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a75bcb  7416                   -je 0xa75be3
    if (cpu.flags.zf)
    {
        goto L_0x00a75be3;
    }
L_0x00a75bcd:
    // 00a75bcd  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a75bcf  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a75bd2  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00a75bd4  7404                   -je 0xa75bda
    if (cpu.flags.zf)
    {
        goto L_0x00a75bda;
    }
    // 00a75bd6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75bd8  ebf3                   -jmp 0xa75bcd
    goto L_0x00a75bcd;
L_0x00a75bda:
    // 00a75bda  41                     -inc ecx
    (cpu.ecx)++;
    // 00a75bdb  8a33                   -mov dh, byte ptr [ebx]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.ebx);
    // 00a75bdd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75bdf  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 00a75be1  75ea                   -jne 0xa75bcd
    if (!cpu.flags.zf)
    {
        goto L_0x00a75bcd;
    }
L_0x00a75be3:
    // 00a75be3  893d0400a800           -mov dword ptr [0xa80004], edi
    *app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */) = cpu.edi;
    // 00a75be9  29e8                   +sub eax, ebp
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a75beb  7505                   -jne 0xa75bf2
    if (!cpu.flags.zf)
    {
        goto L_0x00a75bf2;
    }
    // 00a75bed  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a75bf2:
    // 00a75bf2  e889e0ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a75bf7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a75bf9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75bfb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75bfd  0f8475000000           -je 0xa75c78
    if (cpu.flags.zf)
    {
        goto L_0x00a75c78;
    }
    // 00a75c03  a36006a800             -mov dword ptr [0xa80660], eax
    *app->getMemory<x86::reg32>(x86::reg32(11011680) /* 0xa80660 */) = cpu.eax;
    // 00a75c08  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00a75c0f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75c12  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a75c14  e867e0ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a75c19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75c1b  7454                   -je 0xa75c71
    if (cpu.flags.zf)
    {
        goto L_0x00a75c71;
    }
    // 00a75c1d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a75c1f  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp);
    // 00a75c22  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a75c24  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a75c26  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a75c28  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a75c2a  741a                   -je 0xa75c46
    if (cpu.flags.zf)
    {
        goto L_0x00a75c46;
    }
L_0x00a75c2c:
    // 00a75c2c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a75c2e  891c11                 -mov dword ptr [ecx + edx], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x00a75c31:
    // 00a75c31  43                     -inc ebx
    (cpu.ebx)++;
    // 00a75c32  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a75c34  40                     -inc eax
    (cpu.eax)++;
    // 00a75c35  8853ff                 -mov byte ptr [ebx - 1], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.dl;
    // 00a75c38  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a75c3a  75f5                   -jne 0xa75c31
    if (!cpu.flags.zf)
    {
        goto L_0x00a75c31;
    }
    // 00a75c3c  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75c3f  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a75c41  46                     -inc esi
    (cpu.esi)++;
    // 00a75c42  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00a75c44  75e6                   -jne 0xa75c2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a75c2c;
    }
L_0x00a75c46:
    // 00a75c46  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a75c48  c7040100000000         -mov dword ptr [ecx + eax], 0
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a75c4f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75c52  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a75c54  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00a75c57  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a75c59  a30000a800             -mov dword ptr [0xa80000], eax
    *app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.eax;
    // 00a75c5e  893d0400a800           -mov dword ptr [0xa80004], edi
    *app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */) = cpu.edi;
    // 00a75c64  e807dfffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a75c69  8b3d0400a800           -mov edi, dword ptr [0xa80004]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a75c6f  eb07                   -jmp 0xa75c78
    goto L_0x00a75c78;
L_0x00a75c71:
    // 00a75c71  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a75c73  e8f8e0ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a75c78:
    // 00a75c78  e8d31c0000             -call 0xa77950
    cpu.esp -= 4;
    sub_a77950(app, cpu);
    if (cpu.terminate) return;
L_0x00a75c7d:
    // 00a75c7d  8b3d0400a800           -mov edi, dword ptr [0xa80004]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a75c83  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75c84  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75c85  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75c86  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75c87  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75c88  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75c89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a75c8c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75c8c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75c8d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75c8e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75c8f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75c90  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75c91  e8da1d0000             -call 0xa77a70
    cpu.esp -= 4;
    sub_a77a70(app, cpu);
    if (cpu.terminate) return;
    // 00a75c96  8b150400a800           -mov edx, dword ptr [0xa80004]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a75c9c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a75c9e  740f                   -je 0xa75caf
    if (cpu.flags.zf)
    {
        goto L_0x00a75caf;
    }
    // 00a75ca0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a75ca2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a75ca4  e8c7e0ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a75ca9  891d0400a800           -mov dword ptr [0xa80004], ebx
    *app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */) = cpu.ebx;
L_0x00a75caf:
    // 00a75caf  8b0d6006a800           -mov ecx, dword ptr [0xa80660]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11011680) /* 0xa80660 */);
    // 00a75cb5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a75cb7  740f                   -je 0xa75cc8
    if (cpu.flags.zf)
    {
        goto L_0x00a75cc8;
    }
    // 00a75cb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a75cbb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a75cbd  e8aee0ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a75cc2  89356006a800           -mov dword ptr [0xa80660], esi
    *app->getMemory<x86::reg32>(x86::reg32(11011680) /* 0xa80660 */) = cpu.esi;
L_0x00a75cc8:
    // 00a75cc8  8b3d69d3a700           -mov edi, dword ptr [0xa7d369]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10998633) /* 0xa7d369 */);
    // 00a75cce  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a75cd0  7408                   -je 0xa75cda
    if (cpu.flags.zf)
    {
        goto L_0x00a75cda;
    }
    // 00a75cd2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75cd3  2eff15b0bda700         -call dword ptr cs:[0xa7bdb0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993072) /* 0xa7bdb0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a75cda:
    // 00a75cda  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75cdb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75cdc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75cdd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75cde  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75cdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a75ce0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75ce0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75ce1  803800                 +cmp byte ptr [eax], 0
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
    // 00a75ce4  7507                   -jne 0xa75ced
    if (!cpu.flags.zf)
    {
        goto L_0x00a75ced;
    }
    // 00a75ce6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a75ceb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75cec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75ced:
    // 00a75ced  833df00da80000         +cmp dword ptr [0xa80df0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75cf4  7422                   -je 0xa75d18
    if (cpu.flags.zf)
    {
        goto L_0x00a75d18;
    }
    // 00a75cf6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a75cf8  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a75cfa  8a92010ea800           -mov dl, byte ptr [edx + 0xa80e01]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a75d00  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a75d03  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a75d09  740d                   -je 0xa75d18
    if (cpu.flags.zf)
    {
        goto L_0x00a75d18;
    }
    // 00a75d0b  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a75d0f  7507                   -jne 0xa75d18
    if (!cpu.flags.zf)
    {
        goto L_0x00a75d18;
    }
    // 00a75d11  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a75d16  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75d17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75d18:
    // 00a75d18  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75d1a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75d1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a75d20(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75d20  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75d21  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75d22  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a75d25  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75d27  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a75d29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a75d2b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a75d2d  e8de1d0000             -call 0xa77b10
    cpu.esp -= 4;
    sub_a77b10(app, cpu);
    if (cpu.terminate) return;
    // 00a75d32  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75d34  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a75d36  e8151e0000             -call 0xa77b50
    cpu.esp -= 4;
    sub_a77b50(app, cpu);
    if (cpu.terminate) return;
    // 00a75d3b  881404                 -mov byte ptr [esp + eax], dl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a75d3e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a75d42  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a75d44  e8c71d0000             -call 0xa77b10
    cpu.esp -= 4;
    sub_a77b10(app, cpu);
    if (cpu.terminate) return;
    // 00a75d49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a75d4b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a75d4d  e8fe1d0000             -call 0xa77b50
    cpu.esp -= 4;
    sub_a77b50(app, cpu);
    if (cpu.terminate) return;
    // 00a75d52  88740404               -mov byte ptr [esp + eax + 4], dh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 00a75d56  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a75d58  e8231e0000             -call 0xa77b80
    cpu.esp -= 4;
    sub_a77b80(app, cpu);
    if (cpu.terminate) return;
    // 00a75d5d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a75d61  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a75d65  e8161e0000             -call 0xa77b80
    cpu.esp -= 4;
    sub_a77b80(app, cpu);
    if (cpu.terminate) return;
    // 00a75d6a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a75d6c  e85f1e0000             -call 0xa77bd0
    cpu.esp -= 4;
    sub_a77bd0(app, cpu);
    if (cpu.terminate) return;
    // 00a75d71  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a75d74  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75d75  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75d76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a75d80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75d80  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75d81  833df00da80000         +cmp dword ptr [0xa80df0], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75d88  7420                   -je 0xa75daa
    if (cpu.flags.zf)
    {
        goto L_0x00a75daa;
    }
    // 00a75d8a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a75d8c  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a75d8e  8a92010ea800           -mov dl, byte ptr [edx + 0xa80e01]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a75d94  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a75d97  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a75d9d  740b                   -je 0xa75daa
    if (cpu.flags.zf)
    {
        goto L_0x00a75daa;
    }
    // 00a75d9f  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a75da3  7405                   -je 0xa75daa
    if (cpu.flags.zf)
    {
        goto L_0x00a75daa;
    }
    // 00a75da5  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a75da8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75da9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75daa:
    // 00a75daa  40                     -inc eax
    (cpu.eax)++;
    // 00a75dab  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75dac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a75db0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75db0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75db1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75db2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75db3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75db4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a75db5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75db7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a75dba  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75dc0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a75dc3  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a75dc6  83f901                 +cmp ecx, 1
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
    // 00a75dc9  741e                   -je 0xa75de9
    if (cpu.flags.zf)
    {
        goto L_0x00a75de9;
    }
    // 00a75dcb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a75dcd  7413                   -je 0xa75de2
    if (cpu.flags.zf)
    {
        goto L_0x00a75de2;
    }
    // 00a75dcf  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a75dd2  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75dd8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a75ddd  e9dc000000             -jmp 0xa75ebe
    goto L_0x00a75ebe;
L_0x00a75de2:
    // 00a75de2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a75de9:
    // 00a75de9  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 00a75ded  7522                   -jne 0xa75e11
    if (!cpu.flags.zf)
    {
        goto L_0x00a75e11;
    }
    // 00a75def  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a75df4  e8c7050000             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a75df9  804a0c20               -or byte ptr [edx + 0xc], 0x20
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a75dfd  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a75e00  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75e06  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a75e0b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e0c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e0d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e0e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e0f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75e11:
    // 00a75e11  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a75e14  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75e18  7507                   -jne 0xa75e21
    if (!cpu.flags.zf)
    {
        goto L_0x00a75e21;
    }
    // 00a75e1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a75e1c  e8af000000             -call 0xa75ed0
    cpu.esp -= 4;
    sub_a75ed0(app, cpu);
    if (cpu.terminate) return;
L_0x00a75e21:
    // 00a75e21  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 00a75e26  83fb0a                 +cmp ebx, 0xa
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
    // 00a75e29  7547                   -jne 0xa75e72
    if (!cpu.flags.zf)
    {
        goto L_0x00a75e72;
    }
    // 00a75e2b  8a420c                 -mov al, byte ptr [edx + 0xc]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a75e2e  b900060000             -mov ecx, 0x600
    cpu.ecx = 1536 /*0x600*/;
    // 00a75e33  a840                   +test al, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 64 /*0x40*/));
    // 00a75e35  753b                   -jne 0xa75e72
    if (!cpu.flags.zf)
    {
        goto L_0x00a75e72;
    }
    // 00a75e37  804a0d10               -or byte ptr [edx + 0xd], 0x10
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00a75e3b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75e3d  c6000d                 -mov byte ptr [eax], 0xd
    *app->getMemory<x86::reg8>(cpu.eax) = 13 /*0xd*/;
    // 00a75e40  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75e42  45                     -inc ebp
    (cpu.ebp)++;
    // 00a75e43  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a75e46  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 00a75e48  40                     -inc eax
    (cpu.eax)++;
    // 00a75e49  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a75e4c  894204                 -mov dword ptr [edx + 4], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a75e4f  39f0                   +cmp eax, esi
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
    // 00a75e51  751f                   -jne 0xa75e72
    if (!cpu.flags.zf)
    {
        goto L_0x00a75e72;
    }
    // 00a75e53  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a75e55  e8c6e3ffff             -call 0xa74220
    cpu.esp -= 4;
    sub_a74220(app, cpu);
    if (cpu.terminate) return;
    // 00a75e5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75e5c  7414                   -je 0xa75e72
    if (cpu.flags.zf)
    {
        goto L_0x00a75e72;
    }
    // 00a75e5e  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a75e61  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75e67  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a75e6c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e6d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e6e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e6f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e70  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75e71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75e72:
    // 00a75e72  804a0d10               -or byte ptr [edx + 0xd], 0x10
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 00a75e76  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75e78  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00a75e7a  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a75e7c  47                     -inc edi
    (cpu.edi)++;
    // 00a75e7d  8b6a04                 -mov ebp, dword ptr [edx + 4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a75e80  893a                   -mov dword ptr [edx], edi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00a75e82  45                     -inc ebp
    (cpu.ebp)++;
    // 00a75e83  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a75e86  896a04                 -mov dword ptr [edx + 4], ebp
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00a75e89  85c1                   +test ecx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.eax));
    // 00a75e8b  7505                   -jne 0xa75e92
    if (!cpu.flags.zf)
    {
        goto L_0x00a75e92;
    }
    // 00a75e8d  3b6a14                 +cmp ebp, dword ptr [edx + 0x14]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75e90  751f                   -jne 0xa75eb1
    if (!cpu.flags.zf)
    {
        goto L_0x00a75eb1;
    }
L_0x00a75e92:
    // 00a75e92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a75e94  e887e3ffff             -call 0xa74220
    cpu.esp -= 4;
    sub_a74220(app, cpu);
    if (cpu.terminate) return;
    // 00a75e99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75e9b  7414                   -je 0xa75eb1
    if (cpu.flags.zf)
    {
        goto L_0x00a75eb1;
    }
    // 00a75e9d  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a75ea0  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75ea6  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a75eab  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75eac  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ead  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75eae  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75eaf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75eb0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a75eb1:
    // 00a75eb1  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a75eb4  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75eba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a75ebc  88d8                   -mov al, bl
    cpu.al = cpu.bl;
L_0x00a75ebe:
    // 00a75ebe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ebf  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ec0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ec1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ec2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75ec3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a75ed0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75ed0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75ed1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75ed2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75ed3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a75ed5  e8561d0000             -call 0xa77c30
    cpu.esp -= 4;
    sub_a77c30(app, cpu);
    if (cpu.terminate) return;
    // 00a75eda  837a1400               +cmp dword ptr [edx + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75ede  7526                   -jne 0xa75f06
    if (!cpu.flags.zf)
    {
        goto L_0x00a75f06;
    }
    // 00a75ee0  8a620d                 -mov ah, byte ptr [edx + 0xd]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a75ee3  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a75ee6  7409                   -je 0xa75ef1
    if (cpu.flags.zf)
    {
        goto L_0x00a75ef1;
    }
    // 00a75ee8  c7421486000000         -mov dword ptr [edx + 0x14], 0x86
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 134 /*0x86*/;
    // 00a75eef  eb15                   -jmp 0xa75f06
    goto L_0x00a75f06;
L_0x00a75ef1:
    // 00a75ef1  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a75ef4  7409                   -je 0xa75eff
    if (cpu.flags.zf)
    {
        goto L_0x00a75eff;
    }
    // 00a75ef6  c7421401000000         -mov dword ptr [edx + 0x14], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00a75efd  eb07                   -jmp 0xa75f06
    goto L_0x00a75f06;
L_0x00a75eff:
    // 00a75eff  c7421400100000         -mov dword ptr [edx + 0x14], 0x1000
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 4096 /*0x1000*/;
L_0x00a75f06:
    // 00a75f06  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a75f09  e872ddffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a75f0e  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a75f11  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a75f14  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a75f17  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75f1b  7523                   -jne 0xa75f40
    if (!cpu.flags.zf)
    {
        goto L_0x00a75f40;
    }
    // 00a75f1d  8a4a0d                 -mov cl, byte ptr [edx + 0xd]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a75f20  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a75f23  884a0d                 -mov byte ptr [edx + 0xd], cl
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
    // 00a75f26  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a75f28  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a75f2b  80cd04                 +or ch, 4
    cpu.clear_co();
    cpu.set_szp((cpu.ch |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 00a75f2e  8d5a18                 -lea ebx, [edx + 0x18]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00a75f31  886a0d                 -mov byte ptr [edx + 0xd], ch
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 00a75f34  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a75f37  c7421401000000         -mov dword ptr [edx + 0x14], 1
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 00a75f3e  eb04                   -jmp 0xa75f44
    goto L_0x00a75f44;
L_0x00a75f40:
    // 00a75f40  804a0c08               -or byte ptr [edx + 0xc], 8
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x00a75f44:
    // 00a75f44  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a75f47  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a75f4a  c7420400000000         -mov dword ptr [edx + 4], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a75f51  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a75f53  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75f54  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75f55  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75f56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a75f60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75f60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75f61  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75f62  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75f63  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75f64  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a75f67  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a75f69  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a75f6b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a75f6d  eb01                   -jmp 0xa75f70
    goto L_0x00a75f70;
L_0x00a75f6f:
    // 00a75f6f  42                     -inc edx
    (cpu.edx)++;
L_0x00a75f70:
    // 00a75f70  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75f72  8a0b                   -mov cl, byte ptr [ebx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx);
    // 00a75f74  40                     -inc eax
    (cpu.eax)++;
    // 00a75f75  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a75f77  75f6                   -jne 0xa75f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00a75f6f;
    }
    // 00a75f79  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a75f7b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a75f7f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a75f80  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75f81  a188d3a700             -mov eax, dword ptr [0xa7d388]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a75f86  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75f87  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a75f8a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75f8b  2eff156cbea700         -call dword ptr cs:[0xa7be6c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993260) /* 0xa7be6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75f92  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a75f94  e9a3e6ffff             -jmp 0xa7463c
    return sub_a7463c(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a75f9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75f9c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75f9d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75f9e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a75fa0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a75fa2  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a75fa4  e8c71c0000             -call 0xa77c70
    cpu.esp -= 4;
    sub_a77c70(app, cpu);
    if (cpu.terminate) return;
    // 00a75fa9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a75fab  7509                   -jne 0xa75fb6
    if (!cpu.flags.zf)
    {
        goto L_0x00a75fb6;
    }
    // 00a75fad  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a75faf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a75fb1  e8aaffffff             -call 0xa75f60
    cpu.esp -= 4;
    sub_a75f60(app, cpu);
    if (cpu.terminate) return;
L_0x00a75fb6:
    // 00a75fb6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75fb7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a75fb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a75fc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a75fc0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a75fc1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a75fc2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a75fc3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a75fc4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a75fc5  ff15a8d2a700           -call dword ptr [0xa7d2a8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998440) /* 0xa7d2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a75fcb  8b35e4ffa700           -mov esi, dword ptr [0xa7ffe4]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(11010020) /* 0xa7ffe4 */);
    // 00a75fd1  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a75fd3  7419                   -je 0xa75fee
    if (cpu.flags.zf)
    {
        goto L_0x00a75fee;
    }
    // 00a75fd5  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a75fd8  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a75fdb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a75fdd  81e703400000           -and edi, 0x4003
    cpu.edi &= x86::reg32(x86::sreg32(16387 /*0x4003*/));
    // 00a75fe3  a3e4ffa700             -mov dword ptr [0xa7ffe4], eax
    *app->getMemory<x86::reg32>(x86::reg32(11010020) /* 0xa7ffe4 */) = cpu.eax;
    // 00a75fe8  6683cf03               +or di, 3
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(3 /*0x3*/))));
    // 00a75fec  eb4d                   -jmp 0xa7603b
    goto L_0x00a7603b;
L_0x00a75fee:
    // 00a75fee  b960cfa700             -mov ecx, 0xa7cf60
    cpu.ecx = 10997600 /*0xa7cf60*/;
    // 00a75ff3  81f968d1a700           +cmp ecx, 0xa7d168
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10998120 /*0xa7d168*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a75ff9  7328                   -jae 0xa76023
    if (!cpu.flags.cf)
    {
        goto L_0x00a76023;
    }
L_0x00a75ffb:
    // 00a75ffb  f6410c03               +test byte ptr [ecx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00a75fff  7517                   -jne 0xa76018
    if (!cpu.flags.zf)
    {
        goto L_0x00a76018;
    }
    // 00a76001  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 00a76006  e875dcffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7600b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7600d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7600f  7458                   -je 0xa76069
    if (cpu.flags.zf)
    {
        goto L_0x00a76069;
    }
    // 00a76011  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
    // 00a76016  eb23                   -jmp 0xa7603b
    goto L_0x00a7603b;
L_0x00a76018:
    // 00a76018  83c11a                 -add ecx, 0x1a
    (cpu.ecx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 00a7601b  81f968d1a700           +cmp ecx, 0xa7d168
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10998120 /*0xa7d168*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a76021  72d8                   -jb 0xa75ffb
    if (cpu.flags.cf)
    {
        goto L_0x00a75ffb;
    }
L_0x00a76023:
    // 00a76023  b837000000             -mov eax, 0x37
    cpu.eax = 55 /*0x37*/;
    // 00a76028  bf03400000             -mov edi, 0x4003
    cpu.edi = 16387 /*0x4003*/;
    // 00a7602d  e84edcffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a76032  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a76034  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76036  7431                   -je 0xa76069
    if (cpu.flags.zf)
    {
        goto L_0x00a76069;
    }
    // 00a76038  8d481d                 -lea ecx, [eax + 0x1d]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(29) /* 0x1d */);
L_0x00a7603b:
    // 00a7603b  bb1a000000             -mov ebx, 0x1a
    cpu.ebx = 26 /*0x1a*/;
    // 00a76040  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a76042  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a76044  e827dbffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
    // 00a76049  89790c                 -mov dword ptr [ecx + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00a7604c  894e04                 -mov dword ptr [esi + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a7604f  a1e0ffa700             -mov eax, dword ptr [0xa7ffe0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */);
    // 00a76054  897108                 -mov dword ptr [ecx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00a76057  8935e0ffa700           -mov dword ptr [0xa7ffe0], esi
    *app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */) = cpu.esi;
    // 00a7605d  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a7605f  ff15acd2a700           -call dword ptr [0xa7d2ac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76065  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a76067  eb12                   -jmp 0xa7607b
    goto L_0x00a7607b;
L_0x00a76069:
    // 00a76069  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a7606e  e84d030000             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a76073  ff15acd2a700           -call dword ptr [0xa7d2ac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76079  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a7607b:
    // 00a7607b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7607c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7607d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7607e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7607f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a76084(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76084  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76085  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76086  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76087  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76089  bae0ffa700             -mov edx, 0xa7ffe0
    cpu.edx = 11010016 /*0xa7ffe0*/;
L_0x00a7608e:
    // 00a7608e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a76090  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76092  7425                   -je 0xa760b9
    if (cpu.flags.zf)
    {
        goto L_0x00a760b9;
    }
    // 00a76094  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a76097  39cb                   +cmp ebx, ecx
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
    // 00a76099  7404                   -je 0xa7609f
    if (cpu.flags.zf)
    {
        goto L_0x00a7609f;
    }
    // 00a7609b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7609d  ebef                   -jmp 0xa7608e
    goto L_0x00a7608e;
L_0x00a7609f:
    // 00a7609f  8a490c                 -mov cl, byte ptr [ecx + 0xc]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a760a2  80c903                 -or cl, 3
    cpu.cl |= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 00a760a5  884b0c                 -mov byte ptr [ebx + 0xc], cl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.cl;
    // 00a760a8  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a760aa  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 00a760ac  8b15e4ffa700           -mov edx, dword ptr [0xa7ffe4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11010020) /* 0xa7ffe4 */);
    // 00a760b2  a3e4ffa700             -mov dword ptr [0xa7ffe4], eax
    *app->getMemory<x86::reg32>(x86::reg32(11010020) /* 0xa7ffe4 */) = cpu.eax;
    // 00a760b7  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00a760b9:
    // 00a760b9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a760ba  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a760bb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a760bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a760c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a760c0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a760c1  833de4ffa70000         +cmp dword ptr [0xa7ffe4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(11010020) /* 0xa7ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a760c8  7416                   -je 0xa760e0
    if (cpu.flags.zf)
    {
        goto L_0x00a760e0;
    }
L_0x00a760ca:
    // 00a760ca  a1e4ffa700             -mov eax, dword ptr [0xa7ffe4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11010020) /* 0xa7ffe4 */);
    // 00a760cf  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a760d1  e89adcffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a760d6  8915e4ffa700           -mov dword ptr [0xa7ffe4], edx
    *app->getMemory<x86::reg32>(x86::reg32(11010020) /* 0xa7ffe4 */) = cpu.edx;
    // 00a760dc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a760de  75ea                   -jne 0xa760ca
    if (!cpu.flags.zf)
    {
        goto L_0x00a760ca;
    }
L_0x00a760e0:
    // 00a760e0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a760e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a760f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a760f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a760f1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a760f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a760f4  ff15a8d2a700           -call dword ptr [0xa7d2a8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998440) /* 0xa7d2a8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a760fa  a1e0ffa700             -mov eax, dword ptr [0xa7ffe0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11010016) /* 0xa7ffe0 */);
    // 00a760ff  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76101  750e                   -jne 0xa76111
    if (!cpu.flags.zf)
    {
        goto L_0x00a76111;
    }
L_0x00a76103:
    // 00a76103  ff15acd2a700           -call dword ptr [0xa7d2ac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76109  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7610e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7610f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76110  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76111:
    // 00a76111  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a76114  7408                   -je 0xa7611e
    if (cpu.flags.zf)
    {
        goto L_0x00a7611e;
    }
    // 00a76116  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a76118  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7611a  74e7                   -je 0xa76103
    if (cpu.flags.zf)
    {
        goto L_0x00a76103;
    }
    // 00a7611c  ebf3                   -jmp 0xa76111
    goto L_0x00a76111;
L_0x00a7611e:
    // 00a7611e  ff15acd2a700           -call dword ptr [0xa7d2ac]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76124  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a76129  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7612b  e804000000             -call 0xa76134
    cpu.esp -= 4;
    sub_a76134(app, cpu);
    if (cpu.terminate) return;
    // 00a76130  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76131  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76132  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a76134(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76134  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76135  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76137  e8c8000000             -call 0xa76204
    cpu.esp -= 4;
    sub_a76204(app, cpu);
    if (cpu.terminate) return;
    // 00a7613c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7613e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a76140  e83fffffff             -call 0xa76084
    cpu.esp -= 4;
    sub_a76084(app, cpu);
    if (cpu.terminate) return;
    // 00a76145  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a76147  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76148  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7614c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7614c  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a7614f  83f839                 +cmp eax, 0x39
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
    // 00a76152  7e03                   -jle 0xa76157
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a76157;
    }
    // 00a76154  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x00a76157:
    // 00a76157  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a76158(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76158  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76159  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7615a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7615b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7615c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7615d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a76160  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a76162  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a76165  e8361b0000             -call 0xa77ca0
    cpu.esp -= 4;
    sub_a77ca0(app, cpu);
    if (cpu.terminate) return;
    // 00a7616a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7616c  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 00a7616f  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a76171  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00a76173  e8481c0000             -call 0xa77dc0
    cpu.esp -= 4;
    sub_a77dc0(app, cpu);
    if (cpu.terminate) return;
    // 00a76178  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7617a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00a7617b:
    // 00a7617b  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a7617d  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a7617f  3c00                   +cmp al, 0
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
    // 00a76181  7410                   -je 0xa76193
    if (cpu.flags.zf)
    {
        goto L_0x00a76193;
    }
    // 00a76183  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a76186  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a76189  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a7618c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7618f  3c00                   +cmp al, 0
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
    // 00a76191  75e8                   -jne 0xa7617b
    if (!cpu.flags.zf)
    {
        goto L_0x00a7617b;
    }
L_0x00a76193:
    // 00a76193  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76194  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a76195  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a76197  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a76199  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7619b  49                     -dec ecx
    (cpu.ecx)--;
    // 00a7619c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a7619e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a761a0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a761a2  49                     -dec ecx
    (cpu.ecx)--;
    // 00a761a3  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a761a4  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 00a761a7  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a761aa  c60674                 -mov byte ptr [esi], 0x74
    *app->getMemory<x86::reg8>(cpu.esi) = 116 /*0x74*/;
    // 00a761ad  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a761af:
    // 00a761af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a761b1  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a761b4  4a                     -dec edx
    (cpu.edx)--;
    // 00a761b5  e892ffffff             -call 0xa7614c
    cpu.esp -= 4;
    sub_a7614c(app, cpu);
    if (cpu.terminate) return;
    // 00a761ba  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 00a761bd  884201                 -mov byte ptr [edx + 1], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a761c0  39ca                   +cmp edx, ecx
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
    // 00a761c2  75eb                   -jne 0xa761af
    if (!cpu.flags.zf)
    {
        goto L_0x00a761af;
    }
    // 00a761c4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a761c7  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00a761ca  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a761cd  c646055f               -mov byte ptr [esi + 5], 0x5f
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 00a761d1  e876ffffff             -call 0xa7614c
    cpu.esp -= 4;
    sub_a7614c(app, cpu);
    if (cpu.terminate) return;
    // 00a761d6  884606                 -mov byte ptr [esi + 6], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 00a761d9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a761dc  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a761df  e868ffffff             -call 0xa7614c
    cpu.esp -= 4;
    sub_a7614c(app, cpu);
    if (cpu.terminate) return;
    // 00a761e4  c646082e               -mov byte ptr [esi + 8], 0x2e
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 00a761e8  c6460974               -mov byte ptr [esi + 9], 0x74
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 00a761ec  c6460a6d               -mov byte ptr [esi + 0xa], 0x6d
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 00a761f0  c6460b70               -mov byte ptr [esi + 0xb], 0x70
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 00a761f4  c6460c00               -mov byte ptr [esi + 0xc], 0
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a761f8  884607                 -mov byte ptr [esi + 7], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00a761fb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a761fe  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a761ff  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76200  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76201  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76202  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76203  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a76204(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76204  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76205  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76206  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76207  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76208  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76209  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00a7620f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a76211  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a76213  83780c00               +cmp dword ptr [eax + 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a76217  750a                   -jne 0xa76223
    if (!cpu.flags.zf)
    {
        goto L_0x00a76223;
    }
    // 00a76219  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7621e  e997000000             -jmp 0xa762ba
    goto L_0x00a762ba;
L_0x00a76223:
    // 00a76223  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00a76226  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a76228  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 00a7622b  7409                   -je 0xa76236
    if (cpu.flags.zf)
    {
        goto L_0x00a76236;
    }
    // 00a7622d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a7622f  e8ecdfffff             -call 0xa74220
    cpu.esp -= 4;
    sub_a74220(app, cpu);
    if (cpu.terminate) return;
    // 00a76234  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00a76236:
    // 00a76236  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a76239  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7623f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a76241  e84a1c0000             -call 0xa77e90
    cpu.esp -= 4;
    sub_a77e90(app, cpu);
    if (cpu.terminate) return;
    // 00a76246  83f8ff                 +cmp eax, -1
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
    // 00a76249  740e                   -je 0xa76259
    if (cpu.flags.zf)
    {
        goto L_0x00a76259;
    }
    // 00a7624b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7624d  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a76250  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a76252  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a76254  e8c7010000             -call 0xa76420
    cpu.esp -= 4;
    sub_a76420(app, cpu);
    if (cpu.terminate) return;
L_0x00a76259:
    // 00a76259  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a7625b  740a                   -je 0xa76267
    if (cpu.flags.zf)
    {
        goto L_0x00a76267;
    }
    // 00a7625d  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a76260  e88b1c0000             -call 0xa77ef0
    cpu.esp -= 4;
    sub_a77ef0(app, cpu);
    if (cpu.terminate) return;
    // 00a76265  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a76267:
    // 00a76267  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 00a7626b  7415                   -je 0xa76282
    if (cpu.flags.zf)
    {
        goto L_0x00a76282;
    }
    // 00a7626d  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a76270  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a76273  e8f8daffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a76278  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7627b  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x00a76282:
    // 00a76282  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 00a76286  741a                   -je 0xa762a2
    if (cpu.flags.zf)
    {
        goto L_0x00a762a2;
    }
    // 00a76288  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a7628b  8a5214                 -mov dl, byte ptr [edx + 0x14]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00a7628e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a76290  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a76296  e8bdfeffff             -call 0xa76158
    cpu.esp -= 4;
    sub_a76158(app, cpu);
    if (cpu.terminate) return;
    // 00a7629b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a7629d  e8de1c0000             -call 0xa77f80
    cpu.esp -= 4;
    sub_a77f80(app, cpu);
    if (cpu.terminate) return;
L_0x00a762a2:
    // 00a762a2  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a762a5  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a762ab  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a762ad  7409                   -je 0xa762b8
    if (cpu.flags.zf)
    {
        goto L_0x00a762b8;
    }
    // 00a762af  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00a762b2  ff15a4d2a700           -call dword ptr [0xa7d2a4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998436) /* 0xa7d2a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a762b8:
    // 00a762b8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a762ba:
    // 00a762ba  81c414010000           -add esp, 0x114
    (cpu.esp) += x86::reg32(x86::sreg32(276 /*0x114*/));
    // 00a762c0  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a762c1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a762c2  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a762c3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a762c4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a762c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a762d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a762d0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a762d1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a762d2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a762d3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a762d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a762d7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a762d9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a762db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a762dd  7c08                   -jl 0xa762e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a762e7;
    }
    // 00a762df  3b0570d5a700           +cmp eax, dword ptr [0xa7d570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10999152) /* 0xa7d570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a762e5  7614                   -jbe 0xa762fb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a762fb;
    }
L_0x00a762e7:
    // 00a762e7  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a762ec  e8cf000000             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a762f1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a762f6  e9b8000000             -jmp 0xa763b3
    goto L_0x00a763b3;
L_0x00a762fb:
    // 00a762fb  8b2d88d3a700           -mov ebp, dword ptr [0xa7d388]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a76301  8b6cb500               -mov ebp, dword ptr [ebp + esi*4]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + cpu.esi * 4);
    // 00a76305  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7630b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7630d  e87e1c0000             -call 0xa77f90
    cpu.esp -= 4;
    sub_a77f90(app, cpu);
    if (cpu.terminate) return;
    // 00a76312  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a76314  7428                   -je 0xa7633e
    if (cpu.flags.zf)
    {
        goto L_0x00a7633e;
    }
    // 00a76316  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a76318  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7631a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7631c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7631d  2eff1530bea700         -call dword ptr cs:[0xa7be30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993200) /* 0xa7be30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76324  83f8ff                 +cmp eax, -1
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
    // 00a76327  7515                   -jne 0xa7633e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7633e;
    }
    // 00a76329  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7632b  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76331  e84e1d0000             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a76336  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a76339  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7633a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7633b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7633c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7633d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7633e:
    // 00a7633e  833d0cd3a70000         +cmp dword ptr [0xa7d30c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10998540) /* 0xa7d30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a76345  7428                   -je 0xa7636f
    if (cpu.flags.zf)
    {
        goto L_0x00a7636f;
    }
    // 00a76347  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a76349  ff15e0d2a700           -call dword ptr [0xa7d2e0]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998496) /* 0xa7d2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7634f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76351  741c                   -je 0xa7636f
    if (cpu.flags.zf)
    {
        goto L_0x00a7636f;
    }
    // 00a76353  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a76355  ff150cd3a700           -call dword ptr [0xa7d30c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998540) /* 0xa7d30c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7635b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a7635d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7635f  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76365  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a76367  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a7636a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7636b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7636c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7636d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7636e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7636f:
    // 00a7636f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a76371  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a76375  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a76376  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76377  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76378  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76379  2eff156cbea700         -call dword ptr cs:[0xa7be6c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993260) /* 0xa7be6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76380  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76382  7515                   -jne 0xa76399
    if (!cpu.flags.zf)
    {
        goto L_0x00a76399;
    }
    // 00a76384  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a76386  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7638c  e8f31c0000             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a76391  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a76394  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76395  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76396  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76397  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76398  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76399:
    // 00a76399  3b1c24                 +cmp ebx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7639c  740a                   -je 0xa763a8
    if (cpu.flags.zf)
    {
        goto L_0x00a763a8;
    }
    // 00a7639e  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00a763a3  e818000000             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
L_0x00a763a8:
    // 00a763a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a763aa  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a763b0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
L_0x00a763b3:
    // 00a763b3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a763b6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a763b7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a763b8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a763b9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a763ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a763c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a763c0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a763c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a763c3  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a763c9  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a763cc  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a763cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a763d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a763d0  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a763d5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a763d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a763d8  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a763de  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a763e1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a763e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a763e4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a763e4  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a763e9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a763ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a763ec  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a763f2  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a763f5  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a763f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a763f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a763f8  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a763fd  e8beffffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a76402  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a76407  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a76408(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76408  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76409  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7640b  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76411  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a76414  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76415  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a76420(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76420  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76421  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76422  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a76424  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a76426  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76428  7c08                   -jl 0xa76432
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a76432;
    }
    // 00a7642a  3b0570d5a700           +cmp eax, dword ptr [0xa7d570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10999152) /* 0xa7d570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a76430  7612                   -jbe 0xa76444
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a76444;
    }
L_0x00a76432:
    // 00a76432  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a76437  e884ffffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7643c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a76441  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76442  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76443  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76444:
    // 00a76444  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7644a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7644c  e83f1b0000             -call 0xa77f90
    cpu.esp -= 4;
    sub_a77f90(app, cpu);
    if (cpu.terminate) return;
    // 00a76451  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a76453  7e10                   -jle 0xa76465
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a76465;
    }
    // 00a76455  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 00a76457  750c                   -jne 0xa76465
    if (!cpu.flags.zf)
    {
        goto L_0x00a76465;
    }
    // 00a76459  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a7645c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7645e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a76460  e8831b0000             -call 0xa77fe8
    cpu.esp -= 4;
    sub_a77fe8(app, cpu);
    if (cpu.terminate) return;
L_0x00a76465:
    // 00a76465  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76466  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a76468  8b1588d3a700           -mov edx, dword ptr [0xa7d388]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a7646e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7646f  8b04b2                 -mov eax, dword ptr [edx + esi*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + cpu.esi * 4);
    // 00a76472  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a76473  2eff1530bea700         -call dword ptr cs:[0xa7be30]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993200) /* 0xa7be30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7647a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a7647c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a7647e  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76484  83f9ff                 +cmp ecx, -1
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
    // 00a76487  7505                   -jne 0xa7648e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7648e;
    }
    // 00a76489  e8f61b0000             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
L_0x00a7648e:
    // 00a7648e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a76490  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76491  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76492  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a764a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a764a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a764a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a764a2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a764a3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a764a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a764a6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a764a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a764aa  7c08                   -jl 0xa764b4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a764b4;
    }
    // 00a764ac  3b0570d5a700           +cmp eax, dword ptr [0xa7d570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10999152) /* 0xa7d570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a764b2  7614                   -jbe 0xa764c8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a764c8;
    }
L_0x00a764b4:
    // 00a764b4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a764b9  e802ffffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a764be  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a764c3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a764c4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a764c5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a764c6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a764c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a764c8:
    // 00a764c8  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a764ce  a188d3a700             -mov eax, dword ptr [0xa7d388]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a764d3  8b0498                 -mov eax, dword ptr [eax + ebx*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + cpu.ebx * 4);
    // 00a764d6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a764d7  2eff15acbda700         -call dword ptr cs:[0xa7bdac]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993068) /* 0xa7bdac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a764de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a764e0  750a                   -jne 0xa764ec
    if (!cpu.flags.zf)
    {
        goto L_0x00a764ec;
    }
    // 00a764e2  e89d1b0000             -call 0xa78084
    cpu.esp -= 4;
    sub_a78084(app, cpu);
    if (cpu.terminate) return;
    // 00a764e7  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x00a764ec:
    // 00a764ec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a764ee  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a764f4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a764f6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a764f7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a764f8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a764f9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a764fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a76500(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76500  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76501  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76502  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76503  8b0d88d3a700           -mov ecx, dword ptr [0xa7d388]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a76509  a18cd3a700             -mov eax, dword ptr [0xa7d38c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */);
    // 00a7650e  3b0570d5a700           +cmp eax, dword ptr [0xa7d570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10999152) /* 0xa7d570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a76514  7304                   -jae 0xa7651a
    if (!cpu.flags.cf)
    {
        goto L_0x00a7651a;
    }
    // 00a76516  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a76518  eb2f                   -jmp 0xa76549
    goto L_0x00a76549;
L_0x00a7651a:
    // 00a7651a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7651c  7e26                   -jle 0xa76544
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a76544;
    }
    // 00a7651e  8b1d8cd3a700           -mov ebx, dword ptr [0xa7d38c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */);
    // 00a76524  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a76526  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a76528  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
L_0x00a7652b:
    // 00a7652b  833c0200               +cmp dword ptr [edx + eax], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7652f  750c                   -jne 0xa7653d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7653d;
    }
    // 00a76531  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a76533  890d88d3a700           -mov dword ptr [0xa7d388], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */) = cpu.ecx;
    // 00a76539  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7653a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7653b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7653c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7653d:
    // 00a7653d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a76540  39d8                   +cmp eax, ebx
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
    // 00a76542  7ce7                   -jl 0xa7652b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7652b;
    }
L_0x00a76544:
    // 00a76544  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a76549:
    // 00a76549  890d88d3a700           -mov dword ptr [0xa7d388], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */) = cpu.ecx;
    // 00a7654f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76550  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76551  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76552  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a76554(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76554  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76555  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76556  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76557  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76558  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7655a  ff15c8d2a700           -call dword ptr [0xa7d2c8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998472) /* 0xa7d2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76560  8b1d8cd3a700           -mov ebx, dword ptr [0xa7d38c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */);
    // 00a76566  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a76568  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a7656a  7e2d                   -jle 0xa76599
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a76599;
    }
    // 00a7656c  8d0c9d00000000         -lea ecx, [ebx*4]
    cpu.ecx = x86::reg32(cpu.ebx * 4);
    // 00a76573  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a76575:
    // 00a76575  8b1d88d3a700           -mov ebx, dword ptr [0xa7d388]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a7657b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a7657d  833b00                 +cmp dword ptr [ebx], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a76580  750f                   -jne 0xa76591
    if (!cpu.flags.zf)
    {
        goto L_0x00a76591;
    }
    // 00a76582  8933                   -mov dword ptr [ebx], esi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 00a76584  ff15ccd2a700           -call dword ptr [0xa7d2cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998476) /* 0xa7d2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7658a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7658c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7658d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7658e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7658f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76590  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76591:
    // 00a76591  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a76594  42                     -inc edx
    (cpu.edx)++;
    // 00a76595  39c8                   +cmp eax, ecx
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
    // 00a76597  7cdc                   -jl 0xa76575
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a76575;
    }
L_0x00a76599:
    // 00a76599  8b158cd3a700           -mov edx, dword ptr [0xa7d38c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */);
    // 00a7659f  42                     -inc edx
    (cpu.edx)++;
    // 00a765a0  a188d3a700             -mov eax, dword ptr [0xa7d388]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a765a5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00a765a8  e8f31a0000             -call 0xa780a0
    cpu.esp -= 4;
    sub_a780a0(app, cpu);
    if (cpu.terminate) return;
    // 00a765ad  8b158cd3a700           -mov edx, dword ptr [0xa7d38c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */);
    // 00a765b3  a388d3a700             -mov dword ptr [0xa7d388], eax
    *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */) = cpu.eax;
    // 00a765b8  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a765bb  893490                 -mov dword ptr [eax + edx*4], esi
    *app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 00a765be  890d8cd3a700           -mov dword ptr [0xa7d38c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */) = cpu.ecx;
    // 00a765c4  ff15ccd2a700           -call dword ptr [0xa7d2cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998476) /* 0xa7d2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a765ca  a18cd3a700             -mov eax, dword ptr [0xa7d38c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */);
    // 00a765cf  48                     -dec eax
    (cpu.eax)--;
    // 00a765d0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a765d1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a765d2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a765d3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a765d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a765d8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a765d8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a765d9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a765da  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a765db  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a765dc  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a765dd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a765e0  8b3d88d3a700           -mov edi, dword ptr [0xa7d388]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a765e6  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a765e9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a765eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a765ed  0f8caa000000           -jl 0xa7669d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7669d;
    }
    // 00a765f3  ff15c8d2a700           -call dword ptr [0xa7d2c8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998472) /* 0xa7d2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a765f9  83fa01                 +cmp edx, 1
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
    // 00a765fc  7209                   -jb 0xa76607
    if (cpu.flags.cf)
    {
        goto L_0x00a76607;
    }
    // 00a765fe  7613                   -jbe 0xa76613
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a76613;
    }
    // 00a76600  83fa02                 +cmp edx, 2
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
    // 00a76603  7416                   -je 0xa7661b
    if (cpu.flags.zf)
    {
        goto L_0x00a7661b;
    }
    // 00a76605  eb21                   -jmp 0xa76628
    goto L_0x00a76628;
L_0x00a76607:
    // 00a76607  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a76609  751d                   -jne 0xa76628
    if (!cpu.flags.zf)
    {
        goto L_0x00a76628;
    }
    // 00a7660b  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a7660e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7660f  6af6                   -push -0xa
    *app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00a76611  eb0e                   -jmp 0xa76621
    goto L_0x00a76621;
L_0x00a76613:
    // 00a76613  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a76616  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76617  6af5                   -push -0xb
    *app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00a76619  eb06                   -jmp 0xa76621
    goto L_0x00a76621;
L_0x00a7661b:
    // 00a7661b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a7661e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7661f  6af4                   -push -0xc
    *app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x00a76621:
    // 00a76621  2eff1538bea700         -call dword ptr cs:[0xa7be38]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993208) /* 0xa7be38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a76628:
    // 00a76628  8b2d8cd3a700           -mov ebp, dword ptr [0xa7d38c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */);
    // 00a7662e  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
    // 00a76635  8b3d88d3a700           -mov edi, dword ptr [0xa7d388]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a7663b  39ee                   +cmp esi, ebp
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
    // 00a7663d  7d09                   -jge 0xa76648
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a76648;
    }
    // 00a7663f  01f9                   +add ecx, edi
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
    // 00a76641  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a76644  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a76646  eb49                   -jmp 0xa76691
    goto L_0x00a76691;
L_0x00a76648:
    // 00a76648  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a7664b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a7664d  e84e1a0000             -call 0xa780a0
    cpu.esp -= 4;
    sub_a780a0(app, cpu);
    if (cpu.terminate) return;
    // 00a76652  8b158cd3a700           -mov edx, dword ptr [0xa7d38c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */);
    // 00a76658  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a7665a  39f2                   +cmp edx, esi
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
    // 00a7665c  7d18                   -jge 0xa76676
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a76676;
    }
    // 00a7665e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a76665  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
L_0x00a76667:
    // 00a76667  c7040300000000         -mov dword ptr [ebx + eax], 0
    *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a7666e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a76671  42                     -inc edx
    (cpu.edx)++;
    // 00a76672  39c8                   +cmp eax, ecx
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
    // 00a76674  7cf1                   -jl 0xa76667
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a76667;
    }
L_0x00a76676:
    // 00a76676  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00a7667d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a76680  46                     -inc esi
    (cpu.esi)++;
    // 00a76681  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a76683  893d88d3a700           -mov dword ptr [0xa7d388], edi
    *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */) = cpu.edi;
    // 00a76689  89358cd3a700           -mov dword ptr [0xa7d38c], esi
    *app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */) = cpu.esi;
    // 00a7668f  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x00a76691:
    // 00a76691  ff15ccd2a700           -call dword ptr [0xa7d2cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998476) /* 0xa7d2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76697  8b3d88d3a700           -mov edi, dword ptr [0xa7d388]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
L_0x00a7669d:
    // 00a7669d  8b3d88d3a700           -mov edi, dword ptr [0xa7d388]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a766a3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a766a6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a766a7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a766a8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a766a9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a766aa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a766ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a766ac(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a766ac  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a766ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a766af  ff15c8d2a700           -call dword ptr [0xa7d2c8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998472) /* 0xa7d2c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a766b5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a766b7  7e1c                   -jle 0xa766d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a766d5;
    }
    // 00a766b9  3b158cd3a700           +cmp edx, dword ptr [0xa7d38c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10998668) /* 0xa7d38c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a766bf  7d14                   -jge 0xa766d5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a766d5;
    }
    // 00a766c1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a766c8  8b1588d3a700           -mov edx, dword ptr [0xa7d388]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a766ce  c7040200000000         -mov dword ptr [edx + eax], 0
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
L_0x00a766d5:
    // 00a766d5  ff15ccd2a700           -call dword ptr [0xa7d2cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10998476) /* 0xa7d2cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a766db  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a766dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a766e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a766e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a766e1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a766e2  6af6                   -push -0xa
    *app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 00a766e4  2eff15fcbda700         -call dword ptr cs:[0xa7bdfc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993148) /* 0xa7bdfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a766eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a766ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a766ef  7405                   -je 0xa766f6
    if (cpu.flags.zf)
    {
        goto L_0x00a766f6;
    }
    // 00a766f1  83f8ff                 +cmp eax, -1
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
    // 00a766f4  7505                   -jne 0xa766fb
    if (!cpu.flags.zf)
    {
        goto L_0x00a766fb;
    }
L_0x00a766f6:
    // 00a766f6  e845000000             -call 0xa76740
    cpu.esp -= 4;
    sub_a76740(app, cpu);
    if (cpu.terminate) return;
L_0x00a766fb:
    // 00a766fb  e854feffff             -call 0xa76554
    cpu.esp -= 4;
    sub_a76554(app, cpu);
    if (cpu.terminate) return;
    // 00a76700  6af5                   -push -0xb
    *app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 00a76702  2eff15fcbda700         -call dword ptr cs:[0xa7bdfc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993148) /* 0xa7bdfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76709  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7670b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7670d  7405                   -je 0xa76714
    if (cpu.flags.zf)
    {
        goto L_0x00a76714;
    }
    // 00a7670f  83f8ff                 +cmp eax, -1
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
    // 00a76712  7505                   -jne 0xa76719
    if (!cpu.flags.zf)
    {
        goto L_0x00a76719;
    }
L_0x00a76714:
    // 00a76714  e827000000             -call 0xa76740
    cpu.esp -= 4;
    sub_a76740(app, cpu);
    if (cpu.terminate) return;
L_0x00a76719:
    // 00a76719  e836feffff             -call 0xa76554
    cpu.esp -= 4;
    sub_a76554(app, cpu);
    if (cpu.terminate) return;
    // 00a7671e  6af4                   -push -0xc
    *app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 00a76720  2eff15fcbda700         -call dword ptr cs:[0xa7bdfc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993148) /* 0xa7bdfc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76727  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76729  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7672b  7405                   -je 0xa76732
    if (cpu.flags.zf)
    {
        goto L_0x00a76732;
    }
    // 00a7672d  83f8ff                 +cmp eax, -1
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
    // 00a76730  7505                   -jne 0xa76737
    if (!cpu.flags.zf)
    {
        goto L_0x00a76737;
    }
L_0x00a76732:
    // 00a76732  e809000000             -call 0xa76740
    cpu.esp -= 4;
    sub_a76740(app, cpu);
    if (cpu.terminate) return;
L_0x00a76737:
    // 00a76737  e818feffff             -call 0xa76554
    cpu.esp -= 4;
    sub_a76554(app, cpu);
    if (cpu.terminate) return;
    // 00a7673c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7673d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7673e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a76740(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76740  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76741  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76742  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a76744  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a76746  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a76748  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7674a  2eff158cbda700         -call dword ptr cs:[0xa7bd8c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993036) /* 0xa7bd8c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76751  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76753  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76755  750d                   -jne 0xa76764
    if (!cpu.flags.zf)
    {
        goto L_0x00a76764;
    }
    // 00a76757  8b1590d3a700           -mov edx, dword ptr [0xa7d390]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998672) /* 0xa7d390 */);
    // 00a7675d  42                     -inc edx
    (cpu.edx)++;
    // 00a7675e  891590d3a700           -mov dword ptr [0xa7d390], edx
    *app->getMemory<x86::reg32>(x86::reg32(10998672) /* 0xa7d390 */) = cpu.edx;
L_0x00a76764:
    // 00a76764  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a76766  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76767  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76768  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7676c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7676c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7676d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7676e  8b1588d3a700           -mov edx, dword ptr [0xa7d388]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a76774  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a76776  740f                   -je 0xa76787
    if (cpu.flags.zf)
    {
        goto L_0x00a76787;
    }
    // 00a76778  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7677a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7677c  e8efd5ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a76781  891d88d3a700           -mov dword ptr [0xa7d388], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */) = cpu.ebx;
L_0x00a76787:
    // 00a76787  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76788  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76789  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a76790(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76790  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a76794(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76794  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76795  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76796  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76797  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76798  8b15d00da800           -mov edx, dword ptr [0xa80dd0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11013584) /* 0xa80dd0 */);
    // 00a7679e  83fa40                 +cmp edx, 0x40
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
    // 00a767a1  7d1e                   -jge 0xa767c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a767c1;
    }
    // 00a767a3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00a767aa  bba007a800             -mov ebx, 0xa807a0
    cpu.ebx = 11012000 /*0xa807a0*/;
    // 00a767af  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a767b1  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a767b4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00a767b7  8935d00da800           -mov dword ptr [0xa80dd0], esi
    *app->getMemory<x86::reg32>(x86::reg32(11013584) /* 0xa80dd0 */) = cpu.esi;
    // 00a767bd  01c3                   +add ebx, eax
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
    // 00a767bf  eb67                   -jmp 0xa76828
    goto L_0x00a76828;
L_0x00a767c1:
    // 00a767c1  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00a767c6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a767cb  e850190000             -call 0xa78120
    cpu.esp -= 4;
    sub_a78120(app, cpu);
    if (cpu.terminate) return;
    // 00a767d0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a767d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a767d4  750f                   -jne 0xa767e5
    if (!cpu.flags.zf)
    {
        goto L_0x00a767e5;
    }
    // 00a767d6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a767db  b860dda700             -mov eax, 0xa7dd60
    cpu.eax = 11001184 /*0xa7dd60*/;
    // 00a767e0  e8b7f7ffff             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a767e5:
    // 00a767e5  8b15d40da800           -mov edx, dword ptr [0xa80dd4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11013588) /* 0xa80dd4 */);
    // 00a767eb  42                     -inc edx
    (cpu.edx)++;
    // 00a767ec  a1d80da800             -mov eax, dword ptr [0xa80dd8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11013592) /* 0xa80dd8 */);
    // 00a767f1  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00a767f4  e8a7180000             -call 0xa780a0
    cpu.esp -= 4;
    sub_a780a0(app, cpu);
    if (cpu.terminate) return;
    // 00a767f9  a3d80da800             -mov dword ptr [0xa80dd8], eax
    *app->getMemory<x86::reg32>(x86::reg32(11013592) /* 0xa80dd8 */) = cpu.eax;
    // 00a767fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76800  750f                   -jne 0xa76811
    if (!cpu.flags.zf)
    {
        goto L_0x00a76811;
    }
    // 00a76802  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a76807  b884dda700             -mov eax, 0xa7dd84
    cpu.eax = 11001220 /*0xa7dd84*/;
    // 00a7680c  e88bf7ffff             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a76811:
    // 00a76811  a1d40da800             -mov eax, dword ptr [0xa80dd4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11013588) /* 0xa80dd4 */);
    // 00a76816  8b15d80da800           -mov edx, dword ptr [0xa80dd8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11013592) /* 0xa80dd8 */);
    // 00a7681c  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a7681f  891c82                 -mov dword ptr [edx + eax*4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = cpu.ebx;
    // 00a76822  890dd40da800           -mov dword ptr [0xa80dd4], ecx
    *app->getMemory<x86::reg32>(x86::reg32(11013588) /* 0xa80dd4 */) = cpu.ecx;
L_0x00a76828:
    // 00a76828  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76829  2eff1508bea700         -call dword ptr cs:[0xa7be08]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993160) /* 0xa7be08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76830  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a76832  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76833  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76834  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76835  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76836  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a76838(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76838  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76839  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7683a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7683b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7683c  8b15d00da800           -mov edx, dword ptr [0xa80dd0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11013584) /* 0xa80dd0 */);
    // 00a76842  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a76844  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a76846  7e1b                   -jle 0xa76863
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a76863;
    }
    // 00a76848  bba007a800             -mov ebx, 0xa807a0
    cpu.ebx = 11012000 /*0xa807a0*/;
L_0x00a7684d:
    // 00a7684d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7684e  46                     -inc esi
    (cpu.esi)++;
    // 00a7684f  2eff1598bda700         -call dword ptr cs:[0xa7bd98]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993048) /* 0xa7bd98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76856  8b0dd00da800           -mov ecx, dword ptr [0xa80dd0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(11013584) /* 0xa80dd0 */);
    // 00a7685c  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a7685f  39ce                   +cmp esi, ecx
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
    // 00a76861  7cea                   -jl 0xa7684d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7684d;
    }
L_0x00a76863:
    // 00a76863  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76864  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76865  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76866  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76867  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a76868(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76868  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76869  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7686a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7686b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7686c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7686d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a7686e  8b15d40da800           -mov edx, dword ptr [0xa80dd4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(11013588) /* 0xa80dd4 */);
    // 00a76874  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a76876  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a76878  7e2d                   -jle 0xa768a7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a768a7;
    }
    // 00a7687a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a7687c:
    // 00a7687c  a1d80da800             -mov eax, dword ptr [0xa80dd8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11013592) /* 0xa80dd8 */);
    // 00a76881  8b0c03                 -mov ecx, dword ptr [ebx + eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00a76884  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76885  2eff1598bda700         -call dword ptr cs:[0xa7bd98]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993048) /* 0xa7bd98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7688c  a1d80da800             -mov eax, dword ptr [0xa80dd8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(11013592) /* 0xa80dd8 */);
    // 00a76891  8b0403                 -mov eax, dword ptr [ebx + eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 00a76894  46                     -inc esi
    (cpu.esi)++;
    // 00a76895  e8d6d4ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7689a  8b3dd40da800           -mov edi, dword ptr [0xa80dd4]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(11013588) /* 0xa80dd4 */);
    // 00a768a0  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a768a3  39fe                   +cmp esi, edi
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
    // 00a768a5  7cd5                   -jl 0xa7687c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a7687c;
    }
L_0x00a768a7:
    // 00a768a7  8b2dd80da800           -mov ebp, dword ptr [0xa80dd8]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(11013592) /* 0xa80dd8 */);
    // 00a768ad  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a768af  7407                   -je 0xa768b8
    if (cpu.flags.zf)
    {
        goto L_0x00a768b8;
    }
    // 00a768b1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a768b3  e8b8d4ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a768b8:
    // 00a768b8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a768b9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a768ba  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a768bb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a768bc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a768bd  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a768be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a768c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a768c0  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00a768c7  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00a768ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a768d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a768d0  b87006a800             -mov eax, 0xa80670
    cpu.eax = 11011696 /*0xa80670*/;
    // 00a768d5  e992000000             -jmp 0xa7696c
    return sub_a7696c(app, cpu);
}

}
