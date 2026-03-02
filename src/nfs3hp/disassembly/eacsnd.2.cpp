#include "eacsnd.h"
#include <lib/thread.h>

namespace eacsnd
{

/* align: skip  */
void sub_a380b3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a380b3;
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
L_entry_0x00a380b3:
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

/* align: skip  */
void sub_a3809d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a3809d;
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
L_entry_0x00a3809d:
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

/* align: skip  */
void sub_a380e6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a380e6  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a380e7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a380e8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a380e9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a380ea  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a380eb  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
L_0x00a380f0:
    // 00a380f0  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a380f6  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00a380f9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a380fb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a380fd  8d7e58                 -lea edi, [esi + 0x58]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(88) /* 0x58 */);
    // 00a38100  8db250cea300           -lea esi, [edx + 0xa3ce50]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(10735184) /* 0xa3ce50 */);
    // 00a38106  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a38109  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a3810a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a3810b  83fa68                 +cmp edx, 0x68
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
    // 00a3810e  75e0                   -jne 0xa380f0
    if (!cpu.flags.zf)
    {
        goto L_0x00a380f0;
    }
    // 00a38110  ba867ea300             -mov edx, 0xa37e86
    cpu.edx = 10714758 /*0xa37e86*/;
    // 00a38115  bba37fa300             -mov ebx, 0xa37fa3
    cpu.ebx = 10715043 /*0xa37fa3*/;
    // 00a3811a  89151ccea300           -mov dword ptr [0xa3ce1c], edx
    *app->getMemory<x86::reg32>(x86::reg32(10735132) /* 0xa3ce1c */) = cpu.edx;
    // 00a38120  891d20cea300           -mov dword ptr [0xa3ce20], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10735136) /* 0xa3ce20 */) = cpu.ebx;
    // 00a38126  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a38127  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38128  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38129  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3812a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3812b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3812c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3812c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3812d  e8cffdffff             -call 0xa37f01
    cpu.esp -= 4;
    sub_a37f01(app, cpu);
    if (cpu.terminate) return;
    // 00a38132  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38134  7423                   -je 0xa38159
    if (cpu.flags.zf)
    {
        goto L_0x00a38159;
    }
    // 00a38136  e82afeffff             -call 0xa37f65
    cpu.esp -= 4;
    sub_a37f65(app, cpu);
    if (cpu.terminate) return;
    // 00a3813b  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a38140  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a38145  e8bcfcffff             -call 0xa37e06
    cpu.esp -= 4;
    sub_a37e06(app, cpu);
    if (cpu.terminate) return;
    // 00a3814a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a3814f  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a38154  e8adfcffff             -call 0xa37e06
    cpu.esp -= 4;
    sub_a37e06(app, cpu);
    if (cpu.terminate) return;
L_0x00a38159:
    // 00a38159  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3815a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3815b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3815b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3815c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3815d  bae680a300             -mov edx, 0xa380e6
    cpu.edx = 10715366 /*0xa380e6*/;
    // 00a38162  bb2c81a300             -mov ebx, 0xa3812c
    cpu.ebx = 10715436 /*0xa3812c*/;
    // 00a38167  8915a4cca300           -mov dword ptr [0xa3cca4], edx
    *app->getMemory<x86::reg32>(x86::reg32(10734756) /* 0xa3cca4 */) = cpu.edx;
    // 00a3816d  891da8cca300           -mov dword ptr [0xa3cca8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10734760) /* 0xa3cca8 */) = cpu.ebx;
    // 00a38173  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38174  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38175  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a38180(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38180  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38181  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38182  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38183  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38184  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a38186  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38188  0f849a000000           -je 0xa38228
    if (cpu.flags.zf)
    {
        goto L_0x00a38228;
    }
    // 00a3818e  8d480b                 -lea ecx, [eax + 0xb]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(11) /* 0xb */);
    // 00a38191  39c1                   +cmp ecx, eax
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
    // 00a38193  0f828f000000           -jb 0xa38228
    if (cpu.flags.cf)
    {
        goto L_0x00a38228;
    }
    // 00a38199  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a3819b  80e1f8                 -and cl, 0xf8
    cpu.cl &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a3819e  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00a381a1  83f910                 +cmp ecx, 0x10
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
    // 00a381a4  7305                   -jae 0xa381ab
    if (!cpu.flags.cf)
    {
        goto L_0x00a381ab;
    }
    // 00a381a6  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
L_0x00a381ab:
    // 00a381ab  39c1                   +cmp ecx, eax
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
    // 00a381ad  0f8775000000           -ja 0xa38228
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a38228;
    }
    // 00a381b3  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00a381b6  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00a381b9  39d9                   +cmp ecx, ebx
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
    // 00a381bb  7705                   -ja 0xa381c2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a381c2;
    }
    // 00a381bd  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a381c0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a381c2:
    // 00a381c2  8d7720                 -lea esi, [edi + 0x20]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x00a381c5:
    // 00a381c5  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a381c7  39d1                   +cmp ecx, edx
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
    // 00a381c9  7612                   -jbe 0xa381dd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a381dd;
    }
    // 00a381cb  39da                   +cmp edx, ebx
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
    // 00a381cd  7602                   -jbe 0xa381d1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a381d1;
    }
    // 00a381cf  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00a381d1:
    // 00a381d1  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a381d4  39f0                   +cmp eax, esi
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
    // 00a381d6  75ed                   -jne 0xa381c5
    if (!cpu.flags.zf)
    {
        goto L_0x00a381c5;
    }
    // 00a381d8  895f14                 -mov dword ptr [edi + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00a381db  eb4b                   -jmp 0xa38228
    goto L_0x00a38228;
L_0x00a381dd:
    // 00a381dd  895f10                 -mov dword ptr [edi + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00a381e0  8b5f18                 -mov ebx, dword ptr [edi + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00a381e3  43                     -inc ebx
    (cpu.ebx)++;
    // 00a381e4  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a381e6  895f18                 -mov dword ptr [edi + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00a381e9  83fa10                 +cmp edx, 0x10
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
    // 00a381ec  721e                   -jb 0xa3820c
    if (cpu.flags.cf)
    {
        goto L_0x00a3820c;
    }
    // 00a381ee  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 00a381f1  895f0c                 -mov dword ptr [edi + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a381f4  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a381f6  8908                   -mov dword ptr [eax], ecx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 00a381f8  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a381fb  894b04                 -mov dword ptr [ebx + 4], ecx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a381fe  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a38201  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a38204  895908                 -mov dword ptr [ecx + 8], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a38207  895a04                 -mov dword ptr [edx + 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a3820a  eb12                   -jmp 0xa3821e
    goto L_0x00a3821e;
L_0x00a3820c:
    // 00a3820c  ff4f1c                 -dec dword ptr [edi + 0x1c]
    (*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */))--;
    // 00a3820f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a38212  89570c                 -mov dword ptr [edi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00a38215  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a38218  895a08                 -mov dword ptr [edx + 8], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a3821b  895304                 -mov dword ptr [ebx + 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a3821e:
    // 00a3821e  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a38220  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a38223  8d6804                 -lea ebp, [eax + 4]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a38226  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
L_0x00a38228:
    // 00a38228  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a3822a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3822b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3822c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3822d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3822e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a38230(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38230  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38231  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38232  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38233  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38234  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a38236  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38238  0f841d010000           -je 0xa3835b
    if (cpu.flags.zf)
    {
        goto L_0x00a3835b;
    }
    // 00a3823e  8d58fc                 -lea ebx, [eax - 4]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-4) /* -0x4 */);
    // 00a38241  f60301                 +test byte ptr [ebx], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx) & 1 /*0x1*/));
    // 00a38244  0f8411010000           -je 0xa3835b
    if (cpu.flags.zf)
    {
        goto L_0x00a3835b;
    }
    // 00a3824a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a3824c  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a3824f  8d0413                 -lea eax, [ebx + edx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 00a38252  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a38254  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a38257  7522                   -jne 0xa3827b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3827b;
    }
    // 00a38259  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a3825b  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00a3825d  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a3825f  3b410c                 +cmp eax, dword ptr [ecx + 0xc]
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
    // 00a38262  7503                   -jne 0xa38267
    if (!cpu.flags.zf)
    {
        goto L_0x00a38267;
    }
    // 00a38264  89590c                 -mov dword ptr [ecx + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x00a38267:
    // 00a38267  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a3826a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a3826d  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38270  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a38273  ff4e1c                 +dec dword ptr [esi + 0x1c]
    {
        x86::reg32& tmp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a38276  e994000000             -jmp 0xa3830f
    goto L_0x00a3830f;
L_0x00a3827b:
    // 00a3827b  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a3827d  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a38280  39c3                   +cmp ebx, eax
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
    // 00a38282  7316                   -jae 0xa3829a
    if (!cpu.flags.cf)
    {
        goto L_0x00a3829a;
    }
    // 00a38284  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 00a38287  0f8782000000           -ja 0xa3830f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a3830f;
    }
    // 00a3828d  8b4128                 -mov eax, dword ptr [ecx + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00a38290  39c3                   +cmp ebx, eax
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
    // 00a38292  0f8277000000           -jb 0xa3830f
    if (cpu.flags.cf)
    {
        goto L_0x00a3830f;
    }
    // 00a38298  eb19                   -jmp 0xa382b3
    goto L_0x00a382b3;
L_0x00a3829a:
    // 00a3829a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a3829d  39c3                   +cmp ebx, eax
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
    // 00a3829f  0f826a000000           -jb 0xa3830f
    if (cpu.flags.cf)
    {
        goto L_0x00a3830f;
    }
    // 00a382a5  8d4120                 -lea eax, [ecx + 0x20]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a382a8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a382ab  39d3                   +cmp ebx, edx
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
    // 00a382ad  0f875c000000           -ja 0xa3830f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a3830f;
    }
L_0x00a382b3:
    // 00a382b3  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00a382b6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a382b9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a382bb  8d4f01                 -lea ecx, [edi + 1]
    cpu.ecx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a382be  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a382c0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a382c2  39f8                   +cmp eax, edi
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
    // 00a382c4  7328                   -jae 0xa382ee
    if (!cpu.flags.cf)
    {
        goto L_0x00a382ee;
    }
    // 00a382c6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a382c9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00a382cb  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a382cd  39f8                   +cmp eax, edi
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
    // 00a382cf  7705                   -ja 0xa382d6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a382d6;
    }
    // 00a382d1  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
L_0x00a382d6:
    // 00a382d6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a382d8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a382da:
    // 00a382da  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a382dc  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 00a382df  742e                   -je 0xa3830f
    if (cpu.flags.zf)
    {
        goto L_0x00a3830f;
    }
    // 00a382e1  83faff                 +cmp edx, -1
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
    // 00a382e4  7408                   -je 0xa382ee
    if (cpu.flags.zf)
    {
        goto L_0x00a382ee;
    }
    // 00a382e6  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00a382e9  01d0                   +add eax, edx
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
    // 00a382eb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a382ec  75ec                   -jne 0xa382da
    if (!cpu.flags.zf)
    {
        goto L_0x00a382da;
    }
L_0x00a382ee:
    // 00a382ee  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a382f1  39c3                   +cmp ebx, eax
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
    // 00a382f3  7303                   -jae 0xa382f8
    if (!cpu.flags.cf)
    {
        goto L_0x00a382f8;
    }
    // 00a382f5  8b4628                 -mov eax, dword ptr [esi + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
L_0x00a382f8:
    // 00a382f8  39c3                   +cmp ebx, eax
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
    // 00a382fa  7213                   -jb 0xa3830f
    if (cpu.flags.cf)
    {
        goto L_0x00a3830f;
    }
    // 00a382fc  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a382ff  39c3                   +cmp ebx, eax
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
    // 00a38301  720c                   -jb 0xa3830f
    if (cpu.flags.cf)
    {
        goto L_0x00a3830f;
    }
    // 00a38303  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a38306  39c3                   +cmp ebx, eax
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
    // 00a38308  7205                   -jb 0xa3830f
    if (cpu.flags.cf)
    {
        goto L_0x00a3830f;
    }
    // 00a3830a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a3830d  ebe9                   -jmp 0xa382f8
    goto L_0x00a382f8;
L_0x00a3830f:
    // 00a3830f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a38312  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a38314  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a38316  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a38318  39df                   +cmp edi, ebx
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
    // 00a3831a  7512                   -jne 0xa3832e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3832e;
    }
    // 00a3831c  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a3831e  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a38320  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00a38322  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
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
    // 00a38325  7503                   -jne 0xa3832a
    if (!cpu.flags.zf)
    {
        goto L_0x00a3832a;
    }
    // 00a38327  89560c                 -mov dword ptr [esi + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x00a3832a:
    // 00a3832a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a3832c  eb0f                   -jmp 0xa3833d
    goto L_0x00a3833d;
L_0x00a3832e:
    // 00a3832e  ff461c                 -inc dword ptr [esi + 0x1c]
    (*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))++;
    // 00a38331  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38334  895304                 -mov dword ptr [ebx + 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a38337  895a08                 -mov dword ptr [edx + 8], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a3833a  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a3833d:
    // 00a3833d  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 00a38340  4a                     -dec edx
    (cpu.edx)--;
    // 00a38341  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a38344  895618                 -mov dword ptr [esi + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00a38347  39fb                   +cmp ebx, edi
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
    // 00a38349  7308                   -jae 0xa38353
    if (!cpu.flags.cf)
    {
        goto L_0x00a38353;
    }
    // 00a3834b  3b4e10                 +cmp ecx, dword ptr [esi + 0x10]
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
    // 00a3834e  7603                   -jbe 0xa38353
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a38353;
    }
    // 00a38350  894e10                 -mov dword ptr [esi + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ecx;
L_0x00a38353:
    // 00a38353  3b4e14                 +cmp ecx, dword ptr [esi + 0x14]
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
    // 00a38356  7603                   -jbe 0xa3835b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a3835b;
    }
    // 00a38358  894e14                 -mov dword ptr [esi + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
L_0x00a3835b:
    // 00a3835b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3835c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3835d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3835e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3835f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38360(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38360  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38361  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38362  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38364  a138cea300             -mov eax, dword ptr [0xa3ce38]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */);
    // 00a38369  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a3836b  eb09                   -jmp 0xa38376
    goto L_0x00a38376;
L_0x00a3836d:
    // 00a3836d  39c2                   +cmp edx, eax
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
    // 00a3836f  7209                   -jb 0xa3837a
    if (cpu.flags.cf)
    {
        goto L_0x00a3837a;
    }
    // 00a38371  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38373  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x00a38376:
    // 00a38376  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38378  75f3                   -jne 0xa3836d
    if (!cpu.flags.zf)
    {
        goto L_0x00a3836d;
    }
L_0x00a3837a:
    // 00a3837a  895a04                 -mov dword ptr [edx + 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a3837d  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38380  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a38382  7405                   -je 0xa38389
    if (cpu.flags.zf)
    {
        goto L_0x00a38389;
    }
    // 00a38384  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00a38387  eb06                   -jmp 0xa3838f
    goto L_0x00a3838f;
L_0x00a38389:
    // 00a38389  891538cea300           -mov dword ptr [0xa3ce38], edx
    *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */) = cpu.edx;
L_0x00a3838f:
    // 00a3838f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38391  7403                   -je 0xa38396
    if (cpu.flags.zf)
    {
        goto L_0x00a38396;
    }
    // 00a38393  895004                 -mov dword ptr [eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x00a38396:
    // 00a38396  8d5a20                 -lea ebx, [edx + 0x20]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00a38399  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a3839b  83c22c                 -add edx, 0x2c
    (cpu.edx) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a3839e  c742f400000000         -mov dword ptr [edx - 0xc], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = 0 /*0x0*/;
    // 00a383a5  c742e400000000         -mov dword ptr [edx - 0x1c], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 00a383ac  c742ec00000000         -mov dword ptr [edx - 0x14], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 00a383b3  c742f000000000         -mov dword ptr [edx - 0x10], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = 0 /*0x0*/;
    // 00a383ba  895af8                 -mov dword ptr [edx - 8], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 00a383bd  895afc                 -mov dword ptr [edx - 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a383c0  83e82c                 -sub eax, 0x2c
    (cpu.eax) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a383c3  895ae0                 -mov dword ptr [edx - 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-32) /* -0x20 */) = cpu.ebx;
    // 00a383c6  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a383c8  c70402ffffffff         -mov dword ptr [edx + eax], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 4294967295 /*0xffffffff*/;
    // 00a383cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a383d1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a383d2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a383d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a383d4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a383d4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a383d5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a383d6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a383d7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a383d8  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a383d9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a383da  833d10cfa30000         +cmp dword ptr [0xa3cf10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10735376) /* 0xa3cf10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a383e1  7507                   -jne 0xa383ea
    if (!cpu.flags.zf)
    {
        goto L_0x00a383ea;
    }
L_0x00a383e3:
    // 00a383e3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a383e5  e973000000             -jmp 0xa3845d
    goto L_0x00a3845d;
L_0x00a383ea:
    // 00a383ea  833dd8caa300fe         +cmp dword ptr [0xa3cad8], -2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10734296) /* 0xa3cad8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a383f1  74f0                   -je 0xa383e3
    if (cpu.flags.zf)
    {
        goto L_0x00a383e3;
    }
    // 00a383f3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a383f5  e87d000000             -call 0xa38477
    cpu.esp -= 4;
    sub_a38477(app, cpu);
    if (cpu.terminate) return;
    // 00a383fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a383fc  745f                   -je 0xa3845d
    if (cpu.flags.zf)
    {
        goto L_0x00a3845d;
    }
    // 00a383fe  6a40                   -push 0x40
    *app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00a38400  6800100000             -push 0x1000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4096 /*0x1000*/;
    cpu.esp -= 4;
    // 00a38405  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a38409  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3840a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3840c  2eff15c4a9a300         -call dword ptr cs:[0xa3a9c4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725828) /* 0xa3a9c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38413  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38415  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38417  7444                   -je 0xa3845d
    if (cpu.flags.zf)
    {
        goto L_0x00a3845d;
    }
    // 00a38419  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a3841c  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a3841f  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a38422  39f0                   +cmp eax, esi
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
    // 00a38424  77bd                   -ja 0xa383e3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a383e3;
    }
    // 00a38426  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a38429  83f838                 +cmp eax, 0x38
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
    // 00a3842c  72b5                   -jb 0xa383e3
    if (cpu.flags.cf)
    {
        goto L_0x00a383e3;
    }
    // 00a3842e  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a38430  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a38432  e829ffffff             -call 0xa38360
    cpu.esp -= 4;
    sub_a38360(app, cpu);
    if (cpu.terminate) return;
    // 00a38437  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38439  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a3843b  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a3843e  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a38440  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a38442  8b7a18                 -mov edi, dword ptr [edx + 0x18]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00a38445  c7421400000000         -mov dword ptr [edx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00a3844c  47                     -inc edi
    (cpu.edi)++;
    // 00a3844d  8d4304                 -lea eax, [ebx + 4]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a38450  897a18                 -mov dword ptr [edx + 0x18], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00a38453  e8a5f2ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a38458  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a3845d:
    // 00a3845d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a38460  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38461  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38462  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38463  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38464  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38465  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38466(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38466  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38467  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38469  e853020000             -call 0xa386c1
    cpu.esp -= 4;
    sub_a386c1(app, cpu);
    if (cpu.terminate) return;
    // 00a3846e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a38470  e85fffffff             -call 0xa383d4
    cpu.esp -= 4;
    sub_a383d4(app, cpu);
    if (cpu.terminate) return;
    // 00a38475  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38476  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38477(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38477  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38478  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38479  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a3847b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a3847d  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00a38480  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 00a38482  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38484  7438                   -je 0xa384be
    if (cpu.flags.zf)
    {
        goto L_0x00a384be;
    }
    // 00a38486  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a38488  83c03c                 -add eax, 0x3c
    (cpu.eax) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a3848b  3b02                   +cmp eax, dword ptr [edx]
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
    // 00a3848d  7305                   -jae 0xa38494
    if (!cpu.flags.cf)
    {
        goto L_0x00a38494;
    }
L_0x00a3848f:
    // 00a3848f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38491  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38492  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38493  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a38494:
    // 00a38494  8b0d14cfa300           -mov ecx, dword ptr [0xa3cf14]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10735380) /* 0xa3cf14 */);
    // 00a3849a  39c8                   +cmp eax, ecx
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
    // 00a3849c  7304                   -jae 0xa384a2
    if (!cpu.flags.cf)
    {
        goto L_0x00a384a2;
    }
    // 00a3849e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a384a0  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00a384a2:
    // 00a384a2  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a384a4  05ff0f0000             -add eax, 0xfff
    (cpu.eax) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a384a9  3b02                   +cmp eax, dword ptr [edx]
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
    // 00a384ab  72e2                   -jb 0xa3848f
    if (cpu.flags.cf)
    {
        goto L_0x00a3848f;
    }
    // 00a384ad  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00a384af  80e4f0                 -and ah, 0xf0
    cpu.ah &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 00a384b2  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a384b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a384b6  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a384b9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x00a384be:
    // 00a384be  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a384bf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a384c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a384c1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a384c1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a384c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a384c4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a384c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a384c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a384c7(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a384c7  ff1500cfa300           -call dword ptr [0xa3cf00]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10735360) /* 0xa3cf00 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a384cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a384ce(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a384ce  ff1504cfa300           -call dword ptr [0xa3cf04]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10735364) /* 0xa3cf04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a384d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a384d5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a384d5  ff1508cfa300           -call dword ptr [0xa3cf08]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10735368) /* 0xa3cf08 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a384db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a384dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a384dc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a384dd  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a384de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a384e0  7410                   -je 0xa384f2
    if (cpu.flags.zf)
    {
        goto L_0x00a384f2;
    }
    // 00a384e2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a384e4  8b3500cfa300           -mov esi, dword ptr [0xa3cf00]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10735360) /* 0xa3cf00 */);
    // 00a384ea  890d00cfa300           -mov dword ptr [0xa3cf00], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10735360) /* 0xa3cf00 */) = cpu.ecx;
    // 00a384f0  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
L_0x00a384f2:
    // 00a384f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a384f4  740f                   -je 0xa38505
    if (cpu.flags.zf)
    {
        goto L_0x00a38505;
    }
    // 00a384f6  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a384f8  8b0d04cfa300           -mov ecx, dword ptr [0xa3cf04]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10735364) /* 0xa3cf04 */);
    // 00a384fe  a304cfa300             -mov dword ptr [0xa3cf04], eax
    *app->getMemory<x86::reg32>(x86::reg32(10735364) /* 0xa3cf04 */) = cpu.eax;
    // 00a38503  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x00a38505:
    // 00a38505  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a38507  740f                   -je 0xa38518
    if (cpu.flags.zf)
    {
        goto L_0x00a38518;
    }
    // 00a38509  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00a3850b  8b1508cfa300           -mov edx, dword ptr [0xa3cf08]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10735368) /* 0xa3cf08 */);
    // 00a38511  a308cfa300             -mov dword ptr [0xa3cf08], eax
    *app->getMemory<x86::reg32>(x86::reg32(10735368) /* 0xa3cf08 */) = cpu.eax;
    // 00a38516  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x00a38518:
    // 00a38518  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38519  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3851a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3851b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3851b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3851c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3851d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3851e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3851f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38520  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38521  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a38524  b854c0a300             -mov eax, 0xa3c054
    cpu.eax = 10731604 /*0xa3c054*/;
    // 00a38529  e806040000             -call 0xa38934
    cpu.esp -= 4;
    sub_a38934(app, cpu);
    if (cpu.terminate) return;
    // 00a3852e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a38530  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38532  0f84f9000000           -je 0xa38631
    if (cpu.flags.zf)
    {
        goto L_0x00a38631;
    }
L_0x00a38538:
    // 00a38538  803900                 +cmp byte ptr [ecx], 0
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
    // 00a3853b  0f84e6000000           -je 0xa38627
    if (cpu.flags.zf)
    {
        goto L_0x00a38627;
    }
    // 00a38541  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a38543  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00a38545:
    // 00a38545  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a38547  3ac2                   +cmp al, dl
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
    // 00a38549  7412                   -je 0xa3855d
    if (cpu.flags.zf)
    {
        goto L_0x00a3855d;
    }
    // 00a3854b  3c00                   +cmp al, 0
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
    // 00a3854d  740c                   -je 0xa3855b
    if (cpu.flags.zf)
    {
        goto L_0x00a3855b;
    }
    // 00a3854f  46                     -inc esi
    (cpu.esi)++;
    // 00a38550  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a38552  3ac2                   +cmp al, dl
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
    // 00a38554  7407                   -je 0xa3855d
    if (cpu.flags.zf)
    {
        goto L_0x00a3855d;
    }
    // 00a38556  46                     -inc esi
    (cpu.esi)++;
    // 00a38557  3c00                   +cmp al, 0
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
    // 00a38559  75ea                   -jne 0xa38545
    if (!cpu.flags.zf)
    {
        goto L_0x00a38545;
    }
L_0x00a3855b:
    // 00a3855b  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a3855d:
    // 00a3855d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3855f  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a38561  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a38563  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a38565  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a38567  e822040000             -call 0xa3898e
    cpu.esp -= 4;
    sub_a3898e(app, cpu);
    if (cpu.terminate) return;
    // 00a3856c  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a38571  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a38573  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a38575  881434                 -mov byte ptr [esp + esi], dl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 00a38578  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3857a  e87d050000             -call 0xa38afc
    cpu.esp -= 4;
    sub_a38afc(app, cpu);
    if (cpu.terminate) return;
    // 00a3857f  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a38582  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a38584  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a38586  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a38588:
    // 00a38588  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a3858a  3ac2                   +cmp al, dl
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
    // 00a3858c  7412                   -je 0xa385a0
    if (cpu.flags.zf)
    {
        goto L_0x00a385a0;
    }
    // 00a3858e  3c00                   +cmp al, 0
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
    // 00a38590  740c                   -je 0xa3859e
    if (cpu.flags.zf)
    {
        goto L_0x00a3859e;
    }
    // 00a38592  46                     -inc esi
    (cpu.esi)++;
    // 00a38593  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a38595  3ac2                   +cmp al, dl
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
    // 00a38597  7407                   -je 0xa385a0
    if (cpu.flags.zf)
    {
        goto L_0x00a385a0;
    }
    // 00a38599  46                     -inc esi
    (cpu.esi)++;
    // 00a3859a  3c00                   +cmp al, 0
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
    // 00a3859c  75ea                   -jne 0xa38588
    if (!cpu.flags.zf)
    {
        goto L_0x00a38588;
    }
L_0x00a3859e:
    // 00a3859e  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a385a0:
    // 00a385a0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a385a2  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a385a4  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a385a6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a385a8  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a385aa  e8df030000             -call 0xa3898e
    cpu.esp -= 4;
    sub_a3898e(app, cpu);
    if (cpu.terminate) return;
    // 00a385af  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a385b4  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a385b6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a385b8  883434                 -mov byte ptr [esp + esi], dh
    *app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 00a385bb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a385bd  e83a050000             -call 0xa38afc
    cpu.esp -= 4;
    sub_a38afc(app, cpu);
    if (cpu.terminate) return;
    // 00a385c2  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a385c5  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 00a385c7  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a385cb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a385cd:
    // 00a385cd  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a385cf  3ac2                   +cmp al, dl
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
    // 00a385d1  7412                   -je 0xa385e5
    if (cpu.flags.zf)
    {
        goto L_0x00a385e5;
    }
    // 00a385d3  3c00                   +cmp al, 0
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
    // 00a385d5  740c                   -je 0xa385e3
    if (cpu.flags.zf)
    {
        goto L_0x00a385e3;
    }
    // 00a385d7  46                     -inc esi
    (cpu.esi)++;
    // 00a385d8  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a385da  3ac2                   +cmp al, dl
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
    // 00a385dc  7407                   -je 0xa385e5
    if (cpu.flags.zf)
    {
        goto L_0x00a385e5;
    }
    // 00a385de  46                     -inc esi
    (cpu.esi)++;
    // 00a385df  3c00                   +cmp al, 0
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
    // 00a385e1  75ea                   -jne 0xa385cd
    if (!cpu.flags.zf)
    {
        goto L_0x00a385cd;
    }
L_0x00a385e3:
    // 00a385e3  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a385e5:
    // 00a385e5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a385e7  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a385e9  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a385eb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a385ed  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a385ef  e89a030000             -call 0xa3898e
    cpu.esp -= 4;
    sub_a3898e(app, cpu);
    if (cpu.terminate) return;
    // 00a385f4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a385f6  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a385f8  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a385fa  881c34                 -mov byte ptr [esp + esi], bl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 00a385fd  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a38602  e8f5040000             -call 0xa38afc
    cpu.esp -= 4;
    sub_a38afc(app, cpu);
    if (cpu.terminate) return;
    // 00a38607  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a38609  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a3860b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a3860f  e8d2ddffff             -call 0xa363e6
    cpu.esp -= 4;
    sub_a363e6(app, cpu);
    if (cpu.terminate) return;
    // 00a38614  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a38616  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a38618  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a3861b  e8a2e3ffff             -call 0xa369c2
    cpu.esp -= 4;
    sub_a369c2(app, cpu);
    if (cpu.terminate) return;
    // 00a38620  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a38622  e911ffffff             -jmp 0xa38538
    goto L_0x00a38538;
L_0x00a38627:
    // 00a38627  b860c0a300             -mov eax, 0xa3c060
    cpu.eax = 10731616 /*0xa3c060*/;
    // 00a3862c  e824050000             -call 0xa38b55
    cpu.esp -= 4;
    sub_a38b55(app, cpu);
    if (cpu.terminate) return;
L_0x00a38631:
    // 00a38631  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a38634  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38635  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38636  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38637  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38638  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38639  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3863a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3863b(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3863b  ff150ccfa300           -call dword ptr [0xa3cf0c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10735372) /* 0xa3cf0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38641  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38642  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a38647  b870c0a300             -mov eax, 0xa3c070
    cpu.eax = 10731632 /*0xa3c070*/;
    // 00a3864c  e8d5ceffff             -call 0xa35526
    cpu.esp -= 4;
    sub_a35526(app, cpu);
    if (cpu.terminate) return;
    // 00a38651  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38652  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38641(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a38641;
    // 00a3863b  ff150ccfa300           -call dword ptr [0xa3cf0c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10735372) /* 0xa3cf0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_entry_0x00a38641:
    // 00a38641  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38642  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00a38647  b870c0a300             -mov eax, 0xa3c070
    cpu.eax = 10731632 /*0xa3c070*/;
    // 00a3864c  e8d5ceffff             -call 0xa35526
    cpu.esp -= 4;
    sub_a35526(app, cpu);
    if (cpu.terminate) return;
    // 00a38651  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38652  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38653(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38653  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38654  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38655  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38656  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38657  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a3865a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a3865c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a3865e  8a25d0caa300           -mov ah, byte ptr [0xa3cad0]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(10734288) /* 0xa3cad0 */);
    // 00a38664  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00a38667  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00a38669  7426                   -je 0xa38691
    if (cpu.flags.zf)
    {
        goto L_0x00a38691;
    }
    // 00a3866b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a3866d  36d93f                 -fnstcw word ptr ss:[edi]
    *app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a38670  9b                     -wait 
    /*nothing*/;
    // 00a38671  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38673  741c                   -je 0xa38691
    if (cpu.flags.zf)
    {
        goto L_0x00a38691;
    }
    // 00a38675  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a38677  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a3867a  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 00a3867c  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a3867e  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 00a38680  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a38682  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a38684  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a38687  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = *app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 00a3868a  9b                     -wait 
    /*nothing*/;
    // 00a3868b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a3868d  36d93f                 -fnstcw word ptr ss:[edi]
    *app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 00a38690  9b                     -wait 
    /*nothing*/;
L_0x00a38691:
    // 00a38691  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38693  668b0424               -mov ax, word ptr [esp]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.esp);
    // 00a38697  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a3869a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3869b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3869c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3869d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3869e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a386a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a386a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a386a1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a386a2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a386a4  ff1580cca300           -call dword ptr [0xa3cc80]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734720) /* 0xa3cc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a386aa  8b1510cfa300           -mov edx, dword ptr [0xa3cf10]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10735376) /* 0xa3cf10 */);
    // 00a386b0  891d10cfa300           -mov dword ptr [0xa3cf10], ebx
    *app->getMemory<x86::reg32>(x86::reg32(10735376) /* 0xa3cf10 */) = cpu.ebx;
    // 00a386b6  ff1588cca300           -call dword ptr [0xa3cc88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a386bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a386be  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a386bf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a386c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a386c1(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a386c1  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a386c2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a386c3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a386c4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a386c5  ff1580cca300           -call dword ptr [0xa3cc80]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734720) /* 0xa3cc80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a386cb  a138cea300             -mov eax, dword ptr [0xa3ce38]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */);
    // 00a386d0  e9a2000000             -jmp 0xa38777
    return sub_a38777(app, cpu);
}

/* align: skip  */
void sub_a386d5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a386d5  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a386d6  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a386d7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a386d8  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a386d9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a386da  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a386dc  6800800000             -push 0x8000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00a386e1  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a386e3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a386e4  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a386e7  2eff15c8a9a300         -call dword ptr cs:[0xa3a9c8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725832) /* 0xa3a9c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a386ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a386f0  7507                   -jne 0xa386f9
    if (!cpu.flags.zf)
    {
        goto L_0x00a386f9;
    }
    // 00a386f2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a386f7  eb36                   -jmp 0xa3872f
    goto L_0x00a3872f;
L_0x00a386f9:
    // 00a386f9  3b1d3ccea300           +cmp ebx, dword ptr [0xa3ce3c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10735164) /* 0xa3ce3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a386ff  751c                   -jne 0xa3871d
    if (!cpu.flags.zf)
    {
        goto L_0x00a3871d;
    }
    // 00a38701  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a38703  7408                   -je 0xa3870d
    if (cpu.flags.zf)
    {
        goto L_0x00a3870d;
    }
    // 00a38705  89353ccea300           -mov dword ptr [0xa3ce3c], esi
    *app->getMemory<x86::reg32>(x86::reg32(10735164) /* 0xa3ce3c */) = cpu.esi;
    // 00a3870b  eb10                   -jmp 0xa3871d
    goto L_0x00a3871d;
L_0x00a3870d:
    // 00a3870d  a138cea300             -mov eax, dword ptr [0xa3ce38]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */);
    // 00a38712  893540cea300           -mov dword ptr [0xa3ce40], esi
    *app->getMemory<x86::reg32>(x86::reg32(10735168) /* 0xa3ce40 */) = cpu.esi;
    // 00a38718  a33ccea300             -mov dword ptr [0xa3ce3c], eax
    *app->getMemory<x86::reg32>(x86::reg32(10735164) /* 0xa3ce3c */) = cpu.eax;
L_0x00a3871d:
    // 00a3871d  3b1d98e0a300           +cmp ebx, dword ptr [0xa3e098]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(10739864) /* 0xa3e098 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a38723  7508                   -jne 0xa3872d
    if (!cpu.flags.zf)
    {
        goto L_0x00a3872d;
    }
    // 00a38725  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a38727  893d98e0a300           -mov dword ptr [0xa3e098], edi
    *app->getMemory<x86::reg32>(x86::reg32(10739864) /* 0xa3e098 */) = cpu.edi;
L_0x00a3872d:
    // 00a3872d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a3872f:
    // 00a3872f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38730  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38731  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38732  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38733  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38734  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38735(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38735  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38736  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38737  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a3873a  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a3873d  e893ffffff             -call 0xa386d5
    cpu.esp -= 4;
    sub_a386d5(app, cpu);
    if (cpu.terminate) return;
    // 00a38742  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38744  7516                   -jne 0xa3875c
    if (!cpu.flags.zf)
    {
        goto L_0x00a3875c;
    }
    // 00a38746  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a38748  7508                   -jne 0xa38752
    if (!cpu.flags.zf)
    {
        goto L_0x00a38752;
    }
    // 00a3874a  891538cea300           -mov dword ptr [0xa3ce38], edx
    *app->getMemory<x86::reg32>(x86::reg32(10735160) /* 0xa3ce38 */) = cpu.edx;
    // 00a38750  eb03                   -jmp 0xa38755
    goto L_0x00a38755;
L_0x00a38752:
    // 00a38752  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00a38755:
    // 00a38755  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38757  7403                   -je 0xa3875c
    if (cpu.flags.zf)
    {
        goto L_0x00a3875c;
    }
    // 00a38759  895a04                 -mov dword ptr [edx + 4], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a3875c:
    // 00a3875c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3875d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3875e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3875f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
L_0x00a3875f:
    // 00a3875f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a38761  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a38764  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a38767  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a38769  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a3876c  39f1                   +cmp ecx, esi
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
    // 00a3876e  7505                   -jne 0xa38775
    if (!cpu.flags.zf)
    {
        goto L_0x00a38775;
    }
    // 00a38770  e8c0ffffff             -call 0xa38735
    cpu.esp -= 4;
    sub_a38735(app, cpu);
    if (cpu.terminate) return;
L_0x00a38775:
    // 00a38775  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38779  75e4                   -jne 0xa3875f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3875f;
    }
    // 00a3877b  ff1588cca300           -call dword ptr [0xa3cc88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38781  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38783  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38784  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38785  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38786  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38787  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38777(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a38777;
L_0x00a3875f:
    // 00a3875f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a38761  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a38764  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a38767  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00a38769  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a3876c  39f1                   +cmp ecx, esi
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
    // 00a3876e  7505                   -jne 0xa38775
    if (!cpu.flags.zf)
    {
        goto L_0x00a38775;
    }
    // 00a38770  e8c0ffffff             -call 0xa38735
    cpu.esp -= 4;
    sub_a38735(app, cpu);
    if (cpu.terminate) return;
L_0x00a38775:
    // 00a38775  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_entry_0x00a38777:
    // 00a38777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38779  75e4                   -jne 0xa3875f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3875f;
    }
    // 00a3877b  ff1588cca300           -call dword ptr [0xa3cc88]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734728) /* 0xa3cc88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38781  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38783  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38784  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38785  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38786  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38787  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38788(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38788  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38789  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3878a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3878b  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a3878c  0fa0                   -push fs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 00a3878e  0fa8                   -push gs
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 00a38790  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38791  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a38793  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a38796  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00a38799  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3879b  8945f8                 -mov dword ptr [ebp - 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00a3879e  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00a387a1  8b1518d9a300           -mov edx, dword ptr [0xa3d918]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10737944) /* 0xa3d918 */);
    // 00a387a7  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00a387a9  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00a387ac  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00a387af  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a387b1  753e                   -jne 0xa387f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a387f1;
    }
    // 00a387b3  a144cea300             -mov eax, dword ptr [0xa3ce44]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a387b8  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a387bb  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00a387bd  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a387bf  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00a387c1  8b1d44cea300           -mov ebx, dword ptr [0xa3ce44]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a387c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a387c9  e87bbaffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a387ce  a144cea300             -mov eax, dword ptr [0xa3ce44]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10735172) /* 0xa3ce44 */);
    // 00a387d3  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a387d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a387db  e8e7e4ffff             -call 0xa36cc7
    cpu.esp -= 4;
    sub_a36cc7(app, cpu);
    if (cpu.terminate) return;
    // 00a387e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a387e2  750d                   -jne 0xa387f1
    if (!cpu.flags.zf)
    {
        goto L_0x00a387f1;
    }
    // 00a387e4  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a387e7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a387e8  2eff1524a9a300         -call dword ptr cs:[0xa3a924]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725668) /* 0xa3a924 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a387ef  eb32                   -jmp 0xa38823
    goto L_0x00a38823;
L_0x00a387f1:
    // 00a387f1  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a387f4  ff1564cca300           -call dword ptr [0xa3cc64]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734692) /* 0xa3cc64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a387fa  8998de000000           -mov dword ptr [eax + 0xde], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */) = cpu.ebx;
    // 00a38800  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00a38803  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38804  2eff15a0a9a300         -call dword ptr cs:[0xa3a9a0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725792) /* 0xa3a9a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3880b  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00a3880e  e88eecffff             -call 0xa374a1
    cpu.esp -= 4;
    sub_a374a1(app, cpu);
    if (cpu.terminate) return;
    // 00a38813  ff15a4cca300           -call dword ptr [0xa3cca4]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734756) /* 0xa3cca4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38819  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a3881b  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3881e  e8abfcffff             -call 0xa384ce
    cpu.esp -= 4;
    sub_a384ce(app, cpu);
    if (cpu.terminate) return;
L_0x00a38823:
    // 00a38823  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a38825  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38826  0fa9                   -pop gs
    cpu.gs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a38828  0fa1                   -pop fs
    cpu.fs = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a3882a  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a3882b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3882c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3882d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3882e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3882f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3882f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38830  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38831  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38832  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a38833  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38834  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a38837  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a38839  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a3883b  833d60cca300ff         +cmp dword ptr [0xa3cc60], -1
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
    // 00a38842  7512                   -jne 0xa38856
    if (!cpu.flags.zf)
    {
        goto L_0x00a38856;
    }
    // 00a38844  e829e4ffff             -call 0xa36c72
    cpu.esp -= 4;
    sub_a36c72(app, cpu);
    if (cpu.terminate) return;
    // 00a38849  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3884b  0f84ae000000           -je 0xa388ff
    if (cpu.flags.zf)
    {
        goto L_0x00a388ff;
    }
    // 00a38851  e841e5ffff             -call 0xa36d97
    cpu.esp -= 4;
    sub_a36d97(app, cpu);
    if (cpu.terminate) return;
L_0x00a38856:
    // 00a38856  894c2420               -mov dword ptr [esp + 0x20], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 00a3885a  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a3885e  2eff1558a9a300         -call dword ptr cs:[0xa3a958]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725720) /* 0xa3a958 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38865  89442428               -mov dword ptr [esp + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a38869  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a3886b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a3886d  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a3886f  be88c0a300             -mov esi, 0xa3c088
    cpu.esi = 10731656 /*0xa3c088*/;
    // 00a38874  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a38879  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a3887a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a3887b  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a3887c  2eff1554a9a300         -call dword ptr cs:[0xa3a954]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725716) /* 0xa3a954 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38883  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a38887  e829c8ffff             -call 0xa350b5
    cpu.esp -= 4;
    sub_a350b5(app, cpu);
    if (cpu.terminate) return;
    // 00a3888c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3888e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3888f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a38891  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a38893  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a38895  2eff1528a9a300         -call dword ptr cs:[0xa3a928]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725672) /* 0xa3a928 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3889c  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a388a0  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a388a4  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00a388a8  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00a388ac  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a388ad  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a388af  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00a388b3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a388b4  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 00a388ba  688887a300             -push 0xa38788
    *app->getMemory<x86::reg32>(cpu.esp-4) = 10717064 /*0xa38788*/;
    cpu.esp -= 4;
    // 00a388bf  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 00a388c5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a388c6  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a388c8  2eff1530a9a300         -call dword ptr cs:[0xa3a930]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725680) /* 0xa3a930 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a388cf  89442434               -mov dword ptr [esp + 0x34], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00a388d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a388d5  750a                   -jne 0xa388e1
    if (!cpu.flags.zf)
    {
        goto L_0x00a388e1;
    }
    // 00a388d7  c7442438ffffffff       -mov dword ptr [esp + 0x38], 0xffffffff
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 00a388df  eb0e                   -jmp 0xa388ef
    goto L_0x00a388ef;
L_0x00a388e1:
    // 00a388e1  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a388e3  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00a388e7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a388e8  2eff15d0a9a300         -call dword ptr cs:[0xa3a9d0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725840) /* 0xa3a9d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a388ef:
    // 00a388ef  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a388f3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a388f4  2eff1524a9a300         -call dword ptr cs:[0xa3a924]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725668) /* 0xa3a924 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a388fb  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
L_0x00a388ff:
    // 00a388ff  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00a38902  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38903  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a38904  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38905  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38906  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38907  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38908(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38908  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38909  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3890a  ff15a8cca300           -call dword ptr [0xa3cca8]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(10734760) /* 0xa3cca8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38910  e8d8ebffff             -call 0xa374ed
    cpu.esp -= 4;
    sub_a374ed(app, cpu);
    if (cpu.terminate) return;
    // 00a38915  833d18d9a30000         +cmp dword ptr [0xa3d918], 0
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
    // 00a3891c  750a                   -jne 0xa38928
    if (!cpu.flags.zf)
    {
        goto L_0x00a38928;
    }
    // 00a3891e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a38923  e8eee3ffff             -call 0xa36d16
    cpu.esp -= 4;
    sub_a36d16(app, cpu);
    if (cpu.terminate) return;
L_0x00a38928:
    // 00a38928  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a3892a  2eff1540a9a300         -call dword ptr cs:[0xa3a940]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725696) /* 0xa3a940 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38931  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38932  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38933  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38934(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38934  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38935  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38936  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38937  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38938  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38939  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a3893a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a3893c  8b3588e0a300           -mov esi, dword ptr [0xa3e088]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a38942  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a38944  743f                   -je 0xa38985
    if (cpu.flags.zf)
    {
        goto L_0x00a38985;
    }
    // 00a38946  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38948  743b                   -je 0xa38985
    if (cpu.flags.zf)
    {
        goto L_0x00a38985;
    }
    // 00a3894a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a3894c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a3894d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a3894f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a38951  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a38953  49                     -dec ecx
    (cpu.ecx)--;
    // 00a38954  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a38956  f2ae                   +repne scasb al, byte ptr es:[edi]
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
    // 00a38958  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a3895a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a3895b  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a3895c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00a3895e  eb1f                   -jmp 0xa3897f
    goto L_0x00a3897f;
L_0x00a38960:
    // 00a38960  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a38962  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a38964  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38966  e88d050000             -call 0xa38ef8
    cpu.esp -= 4;
    sub_a38ef8(app, cpu);
    if (cpu.terminate) return;
    // 00a3896b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3896d  750d                   -jne 0xa3897c
    if (!cpu.flags.zf)
    {
        goto L_0x00a3897c;
    }
    // 00a3896f  803c393d               +cmp byte ptr [ecx + edi], 0x3d
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + cpu.edi * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a38973  7507                   -jne 0xa3897c
    if (!cpu.flags.zf)
    {
        goto L_0x00a3897c;
    }
    // 00a38975  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a38978  01c8                   +add eax, ecx
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
    // 00a3897a  eb0b                   -jmp 0xa38987
    goto L_0x00a38987;
L_0x00a3897c:
    // 00a3897c  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a3897f:
    // 00a3897f  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a38981  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a38983  75db                   -jne 0xa38960
    if (!cpu.flags.zf)
    {
        goto L_0x00a38960;
    }
L_0x00a38985:
    // 00a38985  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a38987:
    // 00a38987  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38988  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38989  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3898a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3898b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3898c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3898d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3898e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3898e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3898f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38990  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a38992  eb0b                   -jmp 0xa3899f
    goto L_0x00a3899f;
L_0x00a38994:
    // 00a38994  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a38996  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a38998  7409                   -je 0xa389a3
    if (cpu.flags.zf)
    {
        goto L_0x00a389a3;
    }
    // 00a3899a  42                     -inc edx
    (cpu.edx)++;
    // 00a3899b  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a3899c  8808                   -mov byte ptr [eax], cl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00a3899e  40                     -inc eax
    (cpu.eax)++;
L_0x00a3899f:
    // 00a3899f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a389a1  75f1                   -jne 0xa38994
    if (!cpu.flags.zf)
    {
        goto L_0x00a38994;
    }
L_0x00a389a3:
    // 00a389a3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a389a5  7407                   -je 0xa389ae
    if (cpu.flags.zf)
    {
        goto L_0x00a389ae;
    }
    // 00a389a7  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a389a8  c60000                 -mov byte ptr [eax], 0
    *app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a389ab  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a389ac  ebf5                   -jmp 0xa389a3
    goto L_0x00a389a3;
L_0x00a389ae:
    // 00a389ae  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a389b0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a389b1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a389b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a389b3(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a389b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a389b4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a389b5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a389b6  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a389b9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a389ba  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a389bc  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a389be  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00a389c2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a389c4  7402                   -je 0xa389c8
    if (cpu.flags.zf)
    {
        goto L_0x00a389c8;
    }
    // 00a389c6  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x00a389c8:
    // 00a389c8  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
L_0x00a389cb:
    // 00a389cb  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a389cd  fec0                   -inc al
    (cpu.al)++;
    // 00a389cf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a389d4  f68018cda30002         +test byte ptr [eax + 0xa3cd18], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10734872) /* 0xa3cd18 */) & 2 /*0x2*/));
    // 00a389db  7403                   -je 0xa389e0
    if (cpu.flags.zf)
    {
        goto L_0x00a389e0;
    }
    // 00a389dd  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a389de  ebeb                   -jmp 0xa389cb
    goto L_0x00a389cb;
L_0x00a389e0:
    // 00a389e0  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a389e2  80fd2b                 +cmp ch, 0x2b
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
    // 00a389e5  7405                   -je 0xa389ec
    if (cpu.flags.zf)
    {
        goto L_0x00a389ec;
    }
    // 00a389e7  80fd2d                 +cmp ch, 0x2d
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
    // 00a389ea  7501                   -jne 0xa389ed
    if (!cpu.flags.zf)
    {
        goto L_0x00a389ed;
    }
L_0x00a389ec:
    // 00a389ec  42                     -inc edx
    (cpu.edx)++;
L_0x00a389ed:
    // 00a389ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a389ef  752c                   -jne 0xa38a1d
    if (!cpu.flags.zf)
    {
        goto L_0x00a38a1d;
    }
    // 00a389f1  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a389f4  7514                   -jne 0xa38a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00a38a0a;
    }
    // 00a389f6  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a389f9  80f978                 +cmp cl, 0x78
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
    // 00a389fc  7405                   -je 0xa38a03
    if (cpu.flags.zf)
    {
        goto L_0x00a38a03;
    }
    // 00a389fe  80f958                 +cmp cl, 0x58
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
    // 00a38a01  7507                   -jne 0xa38a0a
    if (!cpu.flags.zf)
    {
        goto L_0x00a38a0a;
    }
L_0x00a38a03:
    // 00a38a03  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 00a38a08  eb33                   -jmp 0xa38a3d
    goto L_0x00a38a3d;
L_0x00a38a0a:
    // 00a38a0a  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a38a0d  7507                   -jne 0xa38a16
    if (!cpu.flags.zf)
    {
        goto L_0x00a38a16;
    }
    // 00a38a0f  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 00a38a14  eb3c                   -jmp 0xa38a52
    goto L_0x00a38a52;
L_0x00a38a16:
    // 00a38a16  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00a38a1b  eb35                   -jmp 0xa38a52
    goto L_0x00a38a52;
L_0x00a38a1d:
    // 00a38a1d  83fe02                 +cmp esi, 2
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
    // 00a38a20  7c05                   -jl 0xa38a27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a38a27;
    }
    // 00a38a22  83fe24                 +cmp esi, 0x24
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
    // 00a38a25  7e11                   -jle 0xa38a38
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a38a38;
    }
L_0x00a38a27:
    // 00a38a27  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00a38a2c  e802dfffff             -call 0xa36933
    cpu.esp -= 4;
    sub_a36933(app, cpu);
    if (cpu.terminate) return;
    // 00a38a31  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a38a33  e9b3000000             -jmp 0xa38aeb
    goto L_0x00a38aeb;
L_0x00a38a38:
    // 00a38a38  83fe10                 +cmp esi, 0x10
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
    // 00a38a3b  7515                   -jne 0xa38a52
    if (!cpu.flags.zf)
    {
        goto L_0x00a38a52;
    }
L_0x00a38a3d:
    // 00a38a3d  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a38a40  7510                   -jne 0xa38a52
    if (!cpu.flags.zf)
    {
        goto L_0x00a38a52;
    }
    // 00a38a42  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a38a45  80ff78                 +cmp bh, 0x78
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
    // 00a38a48  7405                   -je 0xa38a4f
    if (cpu.flags.zf)
    {
        goto L_0x00a38a4f;
    }
    // 00a38a4a  80ff58                 +cmp bh, 0x58
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
    // 00a38a4d  7503                   -jne 0xa38a52
    if (!cpu.flags.zf)
    {
        goto L_0x00a38a52;
    }
L_0x00a38a4f:
    // 00a38a4f  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a38a52:
    // 00a38a52  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a38a56  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a38a58  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00a38a5a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a38a5c  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x00a38a5f:
    // 00a38a5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38a61  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a38a63  e89c000000             -call 0xa38b04
    cpu.esp -= 4;
    sub_a38b04(app, cpu);
    if (cpu.terminate) return;
    // 00a38a68  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38a6c  39f0                   +cmp eax, esi
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
    // 00a38a6e  7d1c                   -jge 0xa38a8c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a38a8c;
    }
    // 00a38a70  3b9f10cfa300           +cmp ebx, dword ptr [edi + 0xa3cf10]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10735376) /* 0xa3cf10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a38a76  7602                   -jbe 0xa38a7a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a38a7a;
    }
    // 00a38a78  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a38a7a:
    // 00a38a7a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38a7c  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00a38a7f  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00a38a83  39c3                   +cmp ebx, eax
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
    // 00a38a85  7302                   -jae 0xa38a89
    if (!cpu.flags.cf)
    {
        goto L_0x00a38a89;
    }
    // 00a38a87  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x00a38a89:
    // 00a38a89  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a38a8a  ebd3                   -jmp 0xa38a5f
    goto L_0x00a38a5f;
L_0x00a38a8c:
    // 00a38a8c  3b542404               +cmp edx, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a38a90  7503                   -jne 0xa38a95
    if (!cpu.flags.zf)
    {
        goto L_0x00a38a95;
    }
    // 00a38a92  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
L_0x00a38a95:
    // 00a38a95  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a38a97  7403                   -je 0xa38a9c
    if (cpu.flags.zf)
    {
        goto L_0x00a38a9c;
    }
    // 00a38a99  895500                 -mov dword ptr [ebp], edx
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
L_0x00a38a9c:
    // 00a38a9c  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a38aa1  750f                   -jne 0xa38ab2
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ab2;
    }
    // 00a38aa3  81fb00000080           +cmp ebx, 0x80000000
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
    // 00a38aa9  7207                   -jb 0xa38ab2
    if (cpu.flags.cf)
    {
        goto L_0x00a38ab2;
    }
    // 00a38aab  7509                   -jne 0xa38ab6
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ab6;
    }
    // 00a38aad  80fd2d                 +cmp ch, 0x2d
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
    // 00a38ab0  7504                   -jne 0xa38ab6
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ab6;
    }
L_0x00a38ab2:
    // 00a38ab2  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a38ab4  742c                   -je 0xa38ae2
    if (cpu.flags.zf)
    {
        goto L_0x00a38ae2;
    }
L_0x00a38ab6:
    // 00a38ab6  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00a38abb  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a38abf  e86fdeffff             -call 0xa36933
    cpu.esp -= 4;
    sub_a36933(app, cpu);
    if (cpu.terminate) return;
    // 00a38ac4  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a38ac6  7507                   -jne 0xa38acf
    if (!cpu.flags.zf)
    {
        goto L_0x00a38acf;
    }
    // 00a38ac8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a38acd  eb1c                   -jmp 0xa38aeb
    goto L_0x00a38aeb;
L_0x00a38acf:
    // 00a38acf  80fd2d                 +cmp ch, 0x2d
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
    // 00a38ad2  7507                   -jne 0xa38adb
    if (!cpu.flags.zf)
    {
        goto L_0x00a38adb;
    }
    // 00a38ad4  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 00a38ad9  eb10                   -jmp 0xa38aeb
    goto L_0x00a38aeb;
L_0x00a38adb:
    // 00a38adb  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 00a38ae0  eb09                   -jmp 0xa38aeb
    goto L_0x00a38aeb;
L_0x00a38ae2:
    // 00a38ae2  80fd2d                 +cmp ch, 0x2d
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
    // 00a38ae5  7502                   -jne 0xa38ae9
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ae9;
    }
    // 00a38ae7  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x00a38ae9:
    // 00a38ae9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a38aeb:
    // 00a38aeb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a38aee  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38aef  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38af0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38af1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38af2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38af2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38af3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a38af5  e8b9feffff             -call 0xa389b3
    cpu.esp -= 4;
    sub_a389b3(app, cpu);
    if (cpu.terminate) return;
    // 00a38afa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38afb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38af5(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a38af5;
    // 00a38af2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38af3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x00a38af5:
    // 00a38af5  e8b9feffff             -call 0xa389b3
    cpu.esp -= 4;
    sub_a389b3(app, cpu);
    if (cpu.terminate) return;
    // 00a38afa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38afb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38afc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38afc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38afd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a38b02  ebf1                   -jmp 0xa38af5
    return sub_a38af5(app, cpu);
}

/* align: skip  */
void sub_a38b04(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38b04  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38b05  3c30                   +cmp al, 0x30
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
    // 00a38b07  720e                   -jb 0xa38b17
    if (cpu.flags.cf)
    {
        goto L_0x00a38b17;
    }
    // 00a38b09  3c39                   +cmp al, 0x39
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
    // 00a38b0b  770a                   -ja 0xa38b17
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a38b17;
    }
    // 00a38b0d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a38b12  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00a38b15  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38b16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a38b17:
    // 00a38b17  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a38b1c  e849040000             -call 0xa38f6a
    cpu.esp -= 4;
    sub_a38f6a(app, cpu);
    if (cpu.terminate) return;
    // 00a38b21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38b23  3c61                   +cmp al, 0x61
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
    // 00a38b25  720d                   -jb 0xa38b34
    if (cpu.flags.cf)
    {
        goto L_0x00a38b34;
    }
    // 00a38b27  3c69                   +cmp al, 0x69
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
    // 00a38b29  7709                   -ja 0xa38b34
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a38b34;
    }
    // 00a38b2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38b2d  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a38b2f  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a38b32  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38b33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a38b34:
    // 00a38b34  3c6a                   +cmp al, 0x6a
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
    // 00a38b36  720e                   -jb 0xa38b46
    if (cpu.flags.cf)
    {
        goto L_0x00a38b46;
    }
    // 00a38b38  3c72                   +cmp al, 0x72
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
    // 00a38b3a  770a                   -ja 0xa38b46
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a38b46;
    }
L_0x00a38b3c:
    // 00a38b3c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a38b41  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 00a38b44  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38b45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a38b46:
    // 00a38b46  3c73                   +cmp al, 0x73
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
    // 00a38b48  7204                   -jb 0xa38b4e
    if (cpu.flags.cf)
    {
        goto L_0x00a38b4e;
    }
    // 00a38b4a  3c7a                   +cmp al, 0x7a
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
    // 00a38b4c  76ee                   -jbe 0xa38b3c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a38b3c;
    }
L_0x00a38b4e:
    // 00a38b4e  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 00a38b53  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38b54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38b55(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38b55  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38b56  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38b57  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38b58  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38b59  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38b5a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38b5b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a38b5e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a38b60  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a38b65  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a38b6a  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a38b6d  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a38b72  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a38b76  e8fd030000             -call 0xa38f78
    cpu.esp -= 4;
    sub_a38f78(app, cpu);
    if (cpu.terminate) return;
    // 00a38b7b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38b7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38b7f  7469                   -je 0xa38bea
    if (cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38b81  39e8                   +cmp eax, ebp
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
    // 00a38b83  7465                   -je 0xa38bea
    if (cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38b85  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a38b87  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a38b8b  40                     -inc eax
    (cpu.eax)++;
    // 00a38b8c  e87feaffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a38b91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38b93  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38b97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38b99  744f                   -je 0xa38bea
    if (cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38b9b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a38b9f  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a38ba1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a38ba3  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a38ba4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a38ba6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a38ba8  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38ba9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38bab  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a38bae  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a38bb0  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a38bb2  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a38bb5  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a38bb7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38bb8  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a38bb9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a38bbd  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a38bc0  c6040200               -mov byte ptr [edx + eax], 0
    *app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a38bc4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a38bc6  e809040000             -call 0xa38fd4
    cpu.esp -= 4;
    sub_a38fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a38bcb  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a38bcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38bd1  7446                   -je 0xa38c19
    if (cpu.flags.zf)
    {
        goto L_0x00a38c19;
    }
    // 00a38bd3  40                     -inc eax
    (cpu.eax)++;
    // 00a38bd4  e837eaffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a38bd9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38bdb  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a38bdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38be1  7511                   -jne 0xa38bf4
    if (!cpu.flags.zf)
    {
        goto L_0x00a38bf4;
    }
    // 00a38be3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a38be5:
    // 00a38be5  e813ebffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a38bea:
    // 00a38bea  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a38bef  e9af000000             -jmp 0xa38ca3
    goto L_0x00a38ca3;
L_0x00a38bf4:
    // 00a38bf4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a38bf8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a38bfa  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a38bfb  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a38bfd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a38bff  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38c00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38c02  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a38c05  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a38c07  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a38c09  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a38c0c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a38c0e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38c0f  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a38c10  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a38c14  c60300                 -mov byte ptr [ebx], 0
    *app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00a38c17  eb04                   -jmp 0xa38c1d
    goto L_0x00a38c1d;
L_0x00a38c19:
    // 00a38c19  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a38c1d:
    // 00a38c1d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a38c21  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a38c22  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a38c26  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38c27  2eff1598a9a300         -call dword ptr cs:[0xa3a998]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725784) /* 0xa3a998 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38c2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38c30  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a38c34  e8c4eaffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a38c39  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a38c3d  e8bbeaffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a38c42  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38c44  74a4                   -je 0xa38bea
    if (cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38c46  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a38c48  e860000000             -call 0xa38cad
    cpu.esp -= 4;
    sub_a38cad(app, cpu);
    if (cpu.terminate) return;
    // 00a38c4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38c4f  7599                   -jne 0xa38bea
    if (!cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38c51  833d8ce0a30000         +cmp dword ptr [0xa3e08c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a38c58  7449                   -je 0xa38ca3
    if (cpu.flags.zf)
    {
        goto L_0x00a38ca3;
    }
    // 00a38c5a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a38c5c  e873030000             -call 0xa38fd4
    cpu.esp -= 4;
    sub_a38fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a38c61  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a38c64  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a38c67  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a38c6a  e8a1e9ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a38c6f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a38c71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38c73  750f                   -jne 0xa38c84
    if (!cpu.flags.zf)
    {
        goto L_0x00a38c84;
    }
    // 00a38c75  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a38c7a  e882030000             -call 0xa39001
    cpu.esp -= 4;
    sub_a39001(app, cpu);
    if (cpu.terminate) return;
    // 00a38c7f  e966ffffff             -jmp 0xa38bea
    goto L_0x00a38bea;
L_0x00a38c84:
    // 00a38c84  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00a38c89  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a38c8b  e8d3030000             -call 0xa39063
    cpu.esp -= 4;
    sub_a39063(app, cpu);
    if (cpu.terminate) return;
    // 00a38c90  83f8ff                 +cmp eax, -1
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
    // 00a38c93  7507                   -jne 0xa38c9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a38c9c;
    }
    // 00a38c95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38c97  e949ffffff             -jmp 0xa38be5
    goto L_0x00a38be5;
L_0x00a38c9c:
    // 00a38c9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38c9e  e85e050000             -call 0xa39201
    cpu.esp -= 4;
    sub_a39201(app, cpu);
    if (cpu.terminate) return;
L_0x00a38ca3:
    // 00a38ca3  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a38ca6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ca7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ca8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ca9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38caa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38cab  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38cac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38ca6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a38ca6;
    // 00a38b55  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38b56  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38b57  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38b58  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38b59  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38b5a  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38b5b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00a38b5e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a38b60  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a38b65  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a38b6a  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a38b6d  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a38b72  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a38b76  e8fd030000             -call 0xa38f78
    cpu.esp -= 4;
    sub_a38f78(app, cpu);
    if (cpu.terminate) return;
    // 00a38b7b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38b7d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38b7f  7469                   -je 0xa38bea
    if (cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38b81  39e8                   +cmp eax, ebp
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
    // 00a38b83  7465                   -je 0xa38bea
    if (cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38b85  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a38b87  89442410               -mov dword ptr [esp + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00a38b8b  40                     -inc eax
    (cpu.eax)++;
    // 00a38b8c  e87feaffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a38b91  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38b93  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38b97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38b99  744f                   -je 0xa38bea
    if (cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38b9b  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a38b9f  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00a38ba1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a38ba3  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a38ba4  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a38ba6  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a38ba8  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38ba9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38bab  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a38bae  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a38bb0  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a38bb2  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a38bb5  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a38bb7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38bb8  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a38bb9  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00a38bbd  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a38bc0  c6040200               -mov byte ptr [edx + eax], 0
    *app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00a38bc4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a38bc6  e809040000             -call 0xa38fd4
    cpu.esp -= 4;
    sub_a38fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a38bcb  89442414               -mov dword ptr [esp + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00a38bcf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38bd1  7446                   -je 0xa38c19
    if (cpu.flags.zf)
    {
        goto L_0x00a38c19;
    }
    // 00a38bd3  40                     -inc eax
    (cpu.eax)++;
    // 00a38bd4  e837eaffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a38bd9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38bdb  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a38bdf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38be1  7511                   -jne 0xa38bf4
    if (!cpu.flags.zf)
    {
        goto L_0x00a38bf4;
    }
    // 00a38be3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a38be5:
    // 00a38be5  e813ebffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a38bea:
    // 00a38bea  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a38bef  e9af000000             -jmp 0xa38ca3
    goto L_0x00a38ca3;
L_0x00a38bf4:
    // 00a38bf4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a38bf8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a38bfa  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a38bfb  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a38bfd  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a38bff  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38c00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38c02  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a38c05  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a38c07  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a38c09  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a38c0c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a38c0e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38c0f  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a38c10  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a38c14  c60300                 -mov byte ptr [ebx], 0
    *app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 00a38c17  eb04                   -jmp 0xa38c1d
    goto L_0x00a38c1d;
L_0x00a38c19:
    // 00a38c19  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00a38c1d:
    // 00a38c1d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a38c21  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a38c22  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a38c26  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38c27  2eff1598a9a300         -call dword ptr cs:[0xa3a998]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725784) /* 0xa3a998 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a38c2e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38c30  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a38c34  e8c4eaffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a38c39  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a38c3d  e8bbeaffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a38c42  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38c44  74a4                   -je 0xa38bea
    if (cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38c46  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a38c48  e860000000             -call 0xa38cad
    cpu.esp -= 4;
    sub_a38cad(app, cpu);
    if (cpu.terminate) return;
    // 00a38c4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38c4f  7599                   -jne 0xa38bea
    if (!cpu.flags.zf)
    {
        goto L_0x00a38bea;
    }
    // 00a38c51  833d8ce0a30000         +cmp dword ptr [0xa3e08c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a38c58  7449                   -je 0xa38ca3
    if (cpu.flags.zf)
    {
        goto L_0x00a38ca3;
    }
    // 00a38c5a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a38c5c  e873030000             -call 0xa38fd4
    cpu.esp -= 4;
    sub_a38fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a38c61  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a38c64  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a38c67  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a38c6a  e8a1e9ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a38c6f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a38c71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38c73  750f                   -jne 0xa38c84
    if (!cpu.flags.zf)
    {
        goto L_0x00a38c84;
    }
    // 00a38c75  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a38c7a  e882030000             -call 0xa39001
    cpu.esp -= 4;
    sub_a39001(app, cpu);
    if (cpu.terminate) return;
    // 00a38c7f  e966ffffff             -jmp 0xa38bea
    goto L_0x00a38bea;
L_0x00a38c84:
    // 00a38c84  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 00a38c89  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a38c8b  e8d3030000             -call 0xa39063
    cpu.esp -= 4;
    sub_a39063(app, cpu);
    if (cpu.terminate) return;
    // 00a38c90  83f8ff                 +cmp eax, -1
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
    // 00a38c93  7507                   -jne 0xa38c9c
    if (!cpu.flags.zf)
    {
        goto L_0x00a38c9c;
    }
    // 00a38c95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38c97  e949ffffff             -jmp 0xa38be5
    goto L_0x00a38be5;
L_0x00a38c9c:
    // 00a38c9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38c9e  e85e050000             -call 0xa39201
    cpu.esp -= 4;
    sub_a39201(app, cpu);
    if (cpu.terminate) return;
L_0x00a38ca3:
    // 00a38ca3  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_entry_0x00a38ca6:
    // 00a38ca6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ca7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ca8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ca9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38caa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38cab  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38cac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38cad(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38cad  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38cae  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38caf  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38cb0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38cb1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38cb2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38cb3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a38cb6  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a38cb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38cb9  750a                   -jne 0xa38cc5
    if (!cpu.flags.zf)
    {
        goto L_0x00a38cc5;
    }
L_0x00a38cbb:
    // 00a38cbb  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a38cc0  e94b010000             -jmp 0xa38e10
    goto L_0x00a38e10;
L_0x00a38cc5:
    // 00a38cc5  803800                 +cmp byte ptr [eax], 0
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
    // 00a38cc8  7411                   -je 0xa38cdb
    if (cpu.flags.zf)
    {
        goto L_0x00a38cdb;
    }
    // 00a38cca  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a38ccd  eb06                   -jmp 0xa38cd5
    goto L_0x00a38cd5;
L_0x00a38ccf:
    // 00a38ccf  80ff3d                 +cmp bh, 0x3d
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a38cd2  7407                   -je 0xa38cdb
    if (cpu.flags.zf)
    {
        goto L_0x00a38cdb;
    }
    // 00a38cd4  42                     -inc edx
    (cpu.edx)++;
L_0x00a38cd5:
    // 00a38cd5  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a38cd7  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 00a38cd9  75f4                   -jne 0xa38ccf
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ccf;
    }
L_0x00a38cdb:
    // 00a38cdb  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a38cde  74db                   -je 0xa38cbb
    if (cpu.flags.zf)
    {
        goto L_0x00a38cbb;
    }
    // 00a38ce0  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a38ce4  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a38ce7  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 00a38cea  a188e0a300             -mov eax, dword ptr [0xa3e088]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a38cef  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38cf3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38cf5  7531                   -jne 0xa38d28
    if (!cpu.flags.zf)
    {
        goto L_0x00a38d28;
    }
    // 00a38cf7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a38cf9  0f8511010000           -jne 0xa38e10
    if (!cpu.flags.zf)
    {
        goto L_0x00a38e10;
    }
    // 00a38cff  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a38d04  e807e9ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a38d09  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38d0d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38d0f  74aa                   -je 0xa38cbb
    if (cpu.flags.zf)
    {
        goto L_0x00a38cbb;
    }
    // 00a38d11  a388e0a300             -mov dword ptr [0xa3e088], eax
    *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */) = cpu.eax;
    // 00a38d16  8928                   -mov dword ptr [eax], ebp
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 00a38d18  83c008                 +add eax, 8
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
    // 00a38d1b  8968fc                 -mov dword ptr [eax - 4], ebp
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 00a38d1e  a384e0a300             -mov dword ptr [0xa3e084], eax
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.eax;
    // 00a38d23  e9cd000000             -jmp 0xa38df5
    goto L_0x00a38df5;
L_0x00a38d28:
    // 00a38d28  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a38d2b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a38d2d  e8e6000000             -call 0xa38e18
    cpu.esp -= 4;
    sub_a38e18(app, cpu);
    if (cpu.terminate) return;
    // 00a38d32  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a38d34  0f85d4000000           -jne 0xa38e0e
    if (!cpu.flags.zf)
    {
        goto L_0x00a38e0e;
    }
    // 00a38d3a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38d3c  0f8fb0000000           -jg 0xa38df2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a38df2;
    }
    // 00a38d42  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a38d44  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00a38d46  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a38d49  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00a38d4b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00a38d4e  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00a38d51  8b3584e0a300           -mov esi, dword ptr [0xa3e084]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a38d57  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a38d5b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a38d5d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a38d5f  7545                   -jne 0xa38da6
    if (!cpu.flags.zf)
    {
        goto L_0x00a38da6;
    }
    // 00a38d61  e8aae8ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a38d66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38d68  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38d6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38d6e  0f8447ffffff           -je 0xa38cbb
    if (cpu.flags.zf)
    {
        goto L_0x00a38cbb;
    }
    // 00a38d74  8b3588e0a300           -mov esi, dword ptr [0xa3e088]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a38d7a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a38d7c  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a38d7d  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a38d7f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a38d81  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38d82  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38d84  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a38d87  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a38d89  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a38d8b  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a38d8e  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a38d90  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38d91  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a38d92  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a38d96  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a38d98  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a38d9a  a384e0a300             -mov dword ptr [0xa3e084], eax
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.eax;
    // 00a38d9f  e8a5b4ffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a38da4  eb32                   -jmp 0xa38dd8
    goto L_0x00a38dd8;
L_0x00a38da6:
    // 00a38da6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38da8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a38dac  e832dcffff             -call 0xa369e3
    cpu.esp -= 4;
    sub_a369e3(app, cpu);
    if (cpu.terminate) return;
    // 00a38db1  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a38db5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38db7  0f84fefeffff           -je 0xa38cbb
    if (cpu.flags.zf)
    {
        goto L_0x00a38cbb;
    }
    // 00a38dbd  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a38dc1  8b1584e0a300           -mov edx, dword ptr [0xa3e084]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a38dc7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a38dc9  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a38dcb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38dcd  e864060000             -call 0xa39436
    cpu.esp -= 4;
    sub_a39436(app, cpu);
    if (cpu.terminate) return;
    // 00a38dd2  890d84e0a300           -mov dword ptr [0xa3e084], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.ecx;
L_0x00a38dd8:
    // 00a38dd8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a38dda  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a38dde  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a38de1  01f8                   +add eax, edi
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
    // 00a38de3  893d88e0a300           -mov dword ptr [0xa3e088], edi
    *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */) = cpu.edi;
    // 00a38de9  c7400400000000         -mov dword ptr [eax + 4], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00a38df0  eb03                   -jmp 0xa38df5
    goto L_0x00a38df5;
L_0x00a38df2:
    // 00a38df2  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a38df5:
    // 00a38df5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a38df7  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a38dfb  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a38dfe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a38e00  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a38e03  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a38e05  a184e0a300             -mov eax, dword ptr [0xa3e084]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a38e0a  c6042800               -mov byte ptr [eax + ebp], 0
    *app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x00a38e0e:
    // 00a38e0e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a38e10:
    // 00a38e10  83c40c                 +add esp, 0xc
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
    // 00a38e13  e98efeffff             -jmp 0xa38ca6
    return sub_a38ca6(app, cpu);
}

/* align: skip  */
void sub_a38e18(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38e18  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38e19  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38e1a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38e1b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a38e1c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a38e1d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a38e1f  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a38e21  8b3588e0a300           -mov esi, dword ptr [0xa3e088]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a38e27  e9b2000000             -jmp 0xa38ede
    goto L_0x00a38ede;
L_0x00a38e2c:
    // 00a38e2c  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a38e2e  e99f000000             -jmp 0xa38ed2
    goto L_0x00a38ed2;
L_0x00a38e33:
    // 00a38e33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38e35  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a38e37  e80cc4ffff             -call 0xa35248
    cpu.esp -= 4;
    sub_a35248(app, cpu);
    if (cpu.terminate) return;
    // 00a38e3c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a38e3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38e40  8a03                   -mov al, byte ptr [ebx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx);
    // 00a38e42  e801c4ffff             -call 0xa35248
    cpu.esp -= 4;
    sub_a35248(app, cpu);
    if (cpu.terminate) return;
    // 00a38e47  39c1                   +cmp ecx, eax
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
    // 00a38e49  0f858c000000           -jne 0xa38edb
    if (!cpu.flags.zf)
    {
        goto L_0x00a38edb;
    }
    // 00a38e4f  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a38e52  0f8578000000           -jne 0xa38ed0
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ed0;
    }
    // 00a38e58  8b1588e0a300           -mov edx, dword ptr [0xa3e088]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a38e5e  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a38e60  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a38e62  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a38e65  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a38e67  7462                   -je 0xa38ecb
    if (cpu.flags.zf)
    {
        goto L_0x00a38ecb;
    }
    // 00a38e69  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a38e6b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a38e6d  eb08                   -jmp 0xa38e77
    goto L_0x00a38e77;
L_0x00a38e6f:
    // 00a38e6f  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a38e72  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a38e74  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a38e77:
    // 00a38e77  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a38e7a  75f3                   -jne 0xa38e6f
    if (!cpu.flags.zf)
    {
        goto L_0x00a38e6f;
    }
    // 00a38e7c  8b3584e0a300           -mov esi, dword ptr [0xa3e084]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a38e82  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a38e84  7441                   -je 0xa38ec7
    if (cpu.flags.zf)
    {
        goto L_0x00a38ec7;
    }
    // 00a38e86  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a38e88  803c0700               +cmp byte ptr [edi + eax], 0
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
    // 00a38e8c  7407                   -je 0xa38e95
    if (cpu.flags.zf)
    {
        goto L_0x00a38e95;
    }
    // 00a38e8e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a38e90  e868e8ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a38e95:
    // 00a38e95  8b2d88e0a300           -mov ebp, dword ptr [0xa3e088]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a38e9b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a38e9d  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a38e9f  8b1584e0a300           -mov edx, dword ptr [0xa3e084]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a38ea5  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00a38ea8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38eaa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a38eac  e885050000             -call 0xa39436
    cpu.esp -= 4;
    sub_a39436(app, cpu);
    if (cpu.terminate) return;
    // 00a38eb1  890d84e0a300           -mov dword ptr [0xa3e084], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.ecx;
    // 00a38eb7  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00a38eba  eb07                   -jmp 0xa38ec3
    goto L_0x00a38ec3;
L_0x00a38ebc:
    // 00a38ebc  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a38ebf  47                     -inc edi
    (cpu.edi)++;
    // 00a38ec0  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a38ec2  40                     -inc eax
    (cpu.eax)++;
L_0x00a38ec3:
    // 00a38ec3  39f7                   +cmp edi, esi
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
    // 00a38ec5  7cf5                   -jl 0xa38ebc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a38ebc;
    }
L_0x00a38ec7:
    // 00a38ec7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a38ec9  eb27                   -jmp 0xa38ef2
    goto L_0x00a38ef2;
L_0x00a38ecb:
    // 00a38ecb  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a38ece  eb22                   -jmp 0xa38ef2
    goto L_0x00a38ef2;
L_0x00a38ed0:
    // 00a38ed0  42                     -inc edx
    (cpu.edx)++;
    // 00a38ed1  43                     -inc ebx
    (cpu.ebx)++;
L_0x00a38ed2:
    // 00a38ed2  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a38ed5  0f8558ffffff           -jne 0xa38e33
    if (!cpu.flags.zf)
    {
        goto L_0x00a38e33;
    }
L_0x00a38edb:
    // 00a38edb  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a38ede:
    // 00a38ede  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a38ee0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38ee2  0f8544ffffff           -jne 0xa38e2c
    if (!cpu.flags.zf)
    {
        goto L_0x00a38e2c;
    }
    // 00a38ee8  a188e0a300             -mov eax, dword ptr [0xa3e088]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a38eed  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a38eef  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x00a38ef2:
    // 00a38ef2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ef3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ef4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ef5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ef6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ef7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38ef8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38ef8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38ef9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a38efa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a38efc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a38efe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00a38f00:
    // 00a38f00  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a38f02  763a                   -jbe 0xa38f3e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a38f3e;
    }
    // 00a38f04  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38f06  e878050000             -call 0xa39483
    cpu.esp -= 4;
    sub_a39483(app, cpu);
    if (cpu.terminate) return;
    // 00a38f0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38f0d  752f                   -jne 0xa38f3e
    if (!cpu.flags.zf)
    {
        goto L_0x00a38f3e;
    }
    // 00a38f0f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a38f11  e86d050000             -call 0xa39483
    cpu.esp -= 4;
    sub_a39483(app, cpu);
    if (cpu.terminate) return;
    // 00a38f16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38f18  7524                   -jne 0xa38f3e
    if (!cpu.flags.zf)
    {
        goto L_0x00a38f3e;
    }
    // 00a38f1a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a38f1c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38f1e  e89c050000             -call 0xa394bf
    cpu.esp -= 4;
    sub_a394bf(app, cpu);
    if (cpu.terminate) return;
    // 00a38f23  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38f25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38f27  753e                   -jne 0xa38f67
    if (!cpu.flags.zf)
    {
        goto L_0x00a38f67;
    }
    // 00a38f29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38f2b  e8e6050000             -call 0xa39516
    cpu.esp -= 4;
    sub_a39516(app, cpu);
    if (cpu.terminate) return;
    // 00a38f30  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a38f32  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a38f34  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a38f35  e8dc050000             -call 0xa39516
    cpu.esp -= 4;
    sub_a39516(app, cpu);
    if (cpu.terminate) return;
    // 00a38f3a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a38f3c  ebc2                   -jmp 0xa38f00
    goto L_0x00a38f00;
L_0x00a38f3e:
    // 00a38f3e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a38f40  7623                   -jbe 0xa38f65
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a38f65;
    }
    // 00a38f42  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38f44  e83a050000             -call 0xa39483
    cpu.esp -= 4;
    sub_a39483(app, cpu);
    if (cpu.terminate) return;
    // 00a38f49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38f4b  750b                   -jne 0xa38f58
    if (!cpu.flags.zf)
    {
        goto L_0x00a38f58;
    }
    // 00a38f4d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a38f4f  e82f050000             -call 0xa39483
    cpu.esp -= 4;
    sub_a39483(app, cpu);
    if (cpu.terminate) return;
    // 00a38f54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38f56  740d                   -je 0xa38f65
    if (cpu.flags.zf)
    {
        goto L_0x00a38f65;
    }
L_0x00a38f58:
    // 00a38f58  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a38f5a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a38f5c  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00a38f5e  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esi);
    // 00a38f60  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a38f62  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38f63  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38f64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a38f65:
    // 00a38f65  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a38f67:
    // 00a38f67  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38f68  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38f69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38f6a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38f6a  83f841                 +cmp eax, 0x41
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
    // 00a38f6d  7c08                   -jl 0xa38f77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a38f77;
    }
    // 00a38f6f  83f85a                 +cmp eax, 0x5a
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
    // 00a38f72  7f03                   -jg 0xa38f77
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a38f77;
    }
    // 00a38f74  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a38f77:
    // 00a38f77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38f78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38f78  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38f79  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a38f7a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a38f7d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38f7f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a38f81  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a38f83  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a38f85  e8b9050000             -call 0xa39543
    cpu.esp -= 4;
    sub_a39543(app, cpu);
    if (cpu.terminate) return;
    // 00a38f8a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a38f8c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a38f8e  e8ca050000             -call 0xa3955d
    cpu.esp -= 4;
    sub_a3955d(app, cpu);
    if (cpu.terminate) return;
    // 00a38f93  881404                 -mov byte ptr [esp + eax], dl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x00a38f96:
    // 00a38f96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38f98  e8e6040000             -call 0xa39483
    cpu.esp -= 4;
    sub_a39483(app, cpu);
    if (cpu.terminate) return;
    // 00a38f9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38f9f  7518                   -jne 0xa38fb9
    if (!cpu.flags.zf)
    {
        goto L_0x00a38fb9;
    }
    // 00a38fa1  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a38fa3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38fa5  e8de050000             -call 0xa39588
    cpu.esp -= 4;
    sub_a39588(app, cpu);
    if (cpu.terminate) return;
    // 00a38faa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38fac  740b                   -je 0xa38fb9
    if (cpu.flags.zf)
    {
        goto L_0x00a38fb9;
    }
    // 00a38fae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38fb0  e861050000             -call 0xa39516
    cpu.esp -= 4;
    sub_a39516(app, cpu);
    if (cpu.terminate) return;
    // 00a38fb5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a38fb7  ebdd                   -jmp 0xa38f96
    goto L_0x00a38f96;
L_0x00a38fb9:
    // 00a38fb9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38fbb  e8c3040000             -call 0xa39483
    cpu.esp -= 4;
    sub_a39483(app, cpu);
    if (cpu.terminate) return;
    // 00a38fc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38fc2  7404                   -je 0xa38fc8
    if (cpu.flags.zf)
    {
        goto L_0x00a38fc8;
    }
    // 00a38fc4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a38fc6  7504                   -jne 0xa38fcc
    if (!cpu.flags.zf)
    {
        goto L_0x00a38fcc;
    }
L_0x00a38fc8:
    // 00a38fc8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38fca  eb02                   -jmp 0xa38fce
    goto L_0x00a38fce;
L_0x00a38fcc:
    // 00a38fcc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a38fce:
    // 00a38fce  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a38fd1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38fd2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38fd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38fd4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38fd4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a38fd5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a38fd6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38fd8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00a38fda:
    // 00a38fda  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a38fdc  e8a2040000             -call 0xa39483
    cpu.esp -= 4;
    sub_a39483(app, cpu);
    if (cpu.terminate) return;
    // 00a38fe1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a38fe3  750c                   -jne 0xa38ff1
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ff1;
    }
    // 00a38fe5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a38fe7  e82a050000             -call 0xa39516
    cpu.esp -= 4;
    sub_a39516(app, cpu);
    if (cpu.terminate) return;
    // 00a38fec  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a38fed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a38fef  ebe9                   -jmp 0xa38fda
    goto L_0x00a38fda;
L_0x00a38ff1:
    // 00a38ff1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a38ff3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ff4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a38ff5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a38ff6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a38ff6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38ff8  7503                   -jne 0xa38ffd
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ffd;
    }
    // 00a38ffa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a38ffc:
    // 00a38ffc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a38ffd:
    // 00a38ffd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38fff  74fb                   -je 0xa38ffc
    if (cpu.flags.zf)
    {
        goto L_0x00a38ffc;
    }
    // 00a39001  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39002  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a39004  e856d9ffff             -call 0xa3695f
    cpu.esp -= 4;
    sub_a3695f(app, cpu);
    if (cpu.terminate) return;
    // 00a39009  83fa7b                 +cmp edx, 0x7b
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
    // 00a3900c  7507                   -jne 0xa39015
    if (!cpu.flags.zf)
    {
        goto L_0x00a39015;
    }
    // 00a3900e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a39013  eb31                   -jmp 0xa39046
    goto L_0x00a39046;
L_0x00a39015:
    // 00a39015  81face000000           +cmp edx, 0xce
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
    // 00a3901b  7507                   -jne 0xa39024
    if (!cpu.flags.zf)
    {
        goto L_0x00a39024;
    }
    // 00a3901d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a39022  eb22                   -jmp 0xa39046
    goto L_0x00a39046;
L_0x00a39024:
    // 00a39024  81fab7000000           +cmp edx, 0xb7
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
    // 00a3902a  7507                   -jne 0xa39033
    if (!cpu.flags.zf)
    {
        goto L_0x00a39033;
    }
    // 00a3902c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a39031  eb13                   -jmp 0xa39046
    goto L_0x00a39046;
L_0x00a39033:
    // 00a39033  83fa13                 +cmp edx, 0x13
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
    // 00a39036  7605                   -jbe 0xa3903d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a3903d;
    }
    // 00a39038  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a3903d:
    // 00a3903d  8b82a1cfa300           -mov eax, dword ptr [edx + 0xa3cfa1]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10735521) /* 0xa3cfa1 */);
    // 00a39043  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a39046:
    // 00a39046  e8e8d8ffff             -call 0xa36933
    cpu.esp -= 4;
    sub_a36933(app, cpu);
    if (cpu.terminate) return;
    // 00a3904b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a39050  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39051  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39001(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a39001;
    // 00a38ff6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38ff8  7503                   -jne 0xa38ffd
    if (!cpu.flags.zf)
    {
        goto L_0x00a38ffd;
    }
    // 00a38ffa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a38ffc:
    // 00a38ffc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a38ffd:
    // 00a38ffd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a38fff  74fb                   -je 0xa38ffc
    if (cpu.flags.zf)
    {
        goto L_0x00a38ffc;
    }
L_entry_0x00a39001:
    // 00a39001  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39002  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a39004  e856d9ffff             -call 0xa3695f
    cpu.esp -= 4;
    sub_a3695f(app, cpu);
    if (cpu.terminate) return;
    // 00a39009  83fa7b                 +cmp edx, 0x7b
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
    // 00a3900c  7507                   -jne 0xa39015
    if (!cpu.flags.zf)
    {
        goto L_0x00a39015;
    }
    // 00a3900e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a39013  eb31                   -jmp 0xa39046
    goto L_0x00a39046;
L_0x00a39015:
    // 00a39015  81face000000           +cmp edx, 0xce
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
    // 00a3901b  7507                   -jne 0xa39024
    if (!cpu.flags.zf)
    {
        goto L_0x00a39024;
    }
    // 00a3901d  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a39022  eb22                   -jmp 0xa39046
    goto L_0x00a39046;
L_0x00a39024:
    // 00a39024  81fab7000000           +cmp edx, 0xb7
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
    // 00a3902a  7507                   -jne 0xa39033
    if (!cpu.flags.zf)
    {
        goto L_0x00a39033;
    }
    // 00a3902c  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a39031  eb13                   -jmp 0xa39046
    goto L_0x00a39046;
L_0x00a39033:
    // 00a39033  83fa13                 +cmp edx, 0x13
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
    // 00a39036  7605                   -jbe 0xa3903d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a3903d;
    }
    // 00a39038  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a3903d:
    // 00a3903d  8b82a1cfa300           -mov eax, dword ptr [edx + 0xa3cfa1]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10735521) /* 0xa3cfa1 */);
    // 00a39043  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a39046:
    // 00a39046  e8e8d8ffff             -call 0xa36933
    cpu.esp -= 4;
    sub_a36933(app, cpu);
    if (cpu.terminate) return;
    // 00a3904b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a39050  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39051  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39052(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39052  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a39053  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39054  2eff1564a9a300         -call dword ptr cs:[0xa3a964]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725732) /* 0xa3a964 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3905b  e8a1ffffff             -call 0xa39001
    cpu.esp -= 4;
    sub_a39001(app, cpu);
    if (cpu.terminate) return;
    // 00a39060  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39061  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39062  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39063(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39063  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a39064  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a39065  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a39066  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a39067  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a39069  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a3906b  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00a3906d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a3906f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39071  7438                   -je 0xa390ab
    if (cpu.flags.zf)
    {
        goto L_0x00a390ab;
    }
L_0x00a39073:
    // 00a39073  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a39075  7658                   -jbe 0xa390cf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a390cf;
    }
    // 00a39077  803900                 +cmp byte ptr [ecx], 0
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
    // 00a3907a  7418                   -je 0xa39094
    if (cpu.flags.zf)
    {
        goto L_0x00a39094;
    }
    // 00a3907c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a39081  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a39083  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a39085  e856050000             -call 0xa395e0
    cpu.esp -= 4;
    sub_a395e0(app, cpu);
    if (cpu.terminate) return;
    // 00a3908a  83f8ff                 +cmp eax, -1
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
    // 00a3908d  750c                   -jne 0xa3909b
    if (!cpu.flags.zf)
    {
        goto L_0x00a3909b;
    }
    // 00a3908f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39090  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39091  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39092  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39093  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39094:
    // 00a39094  66c7060000             -mov word ptr [esi], 0
    *app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 00a39099  eb34                   -jmp 0xa390cf
    goto L_0x00a390cf;
L_0x00a3909b:
    // 00a3909b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a3909d  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a3909e  e873040000             -call 0xa39516
    cpu.esp -= 4;
    sub_a39516(app, cpu);
    if (cpu.terminate) return;
    // 00a390a3  83c602                 +add esi, 2
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
    // 00a390a6  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a390a7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a390a9  ebc8                   -jmp 0xa39073
    goto L_0x00a39073;
L_0x00a390ab:
    // 00a390ab  803900                 +cmp byte ptr [ecx], 0
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
    // 00a390ae  741f                   -je 0xa390cf
    if (cpu.flags.zf)
    {
        goto L_0x00a390cf;
    }
    // 00a390b0  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00a390b5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a390b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a390b9  e822050000             -call 0xa395e0
    cpu.esp -= 4;
    sub_a395e0(app, cpu);
    if (cpu.terminate) return;
    // 00a390be  83f8ff                 +cmp eax, -1
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
    // 00a390c1  740e                   -je 0xa390d1
    if (cpu.flags.zf)
    {
        goto L_0x00a390d1;
    }
    // 00a390c3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a390c5  e84c040000             -call 0xa39516
    cpu.esp -= 4;
    sub_a39516(app, cpu);
    if (cpu.terminate) return;
    // 00a390ca  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a390cb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a390cd  ebdc                   -jmp 0xa390ab
    goto L_0x00a390ab;
L_0x00a390cf:
    // 00a390cf  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x00a390d1:
    // 00a390d1  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a390d2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a390d3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a390d4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a390d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a390d6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a390d6  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a390d7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a390d8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a390d9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a390da  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a390db  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a390dc  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a390df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a390e1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a390e6  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a390ea  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a390ed  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a390f2  e87d050000             -call 0xa39674
    cpu.esp -= 4;
    sub_a39674(app, cpu);
    if (cpu.terminate) return;
    // 00a390f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a390f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a390fb  7458                   -je 0xa39155
    if (cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a390fd  39c8                   +cmp eax, ecx
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
    // 00a390ff  7454                   -je 0xa39155
    if (cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a39101  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a39103  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a39105  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 00a39107  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a39109  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00a3910c  e8ffe4ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a39111  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a39113  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a39117  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39119  743a                   -je 0xa39155
    if (cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a3911b  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a3911d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a3911f  e812ecffff             -call 0xa37d36
    cpu.esp -= 4;
    sub_a37d36(app, cpu);
    if (cpu.terminate) return;
    // 00a39124  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00a39127  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a39129  66c7042e0000           -mov word ptr [esi + ebp], 0
    *app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 00a3912f  e8efebffff             -call 0xa37d23
    cpu.esp -= 4;
    sub_a37d23(app, cpu);
    if (cpu.terminate) return;
    // 00a39134  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39136  743d                   -je 0xa39175
    if (cpu.flags.zf)
    {
        goto L_0x00a39175;
    }
    // 00a39138  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a3913a  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a3913e  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a39141  e8cae4ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a39146  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a39148  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a3914a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3914c  7511                   -jne 0xa3915f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3915f;
    }
L_0x00a3914e:
    // 00a3914e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a39150  e8a8e5ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a39155:
    // 00a39155  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a3915a  e998000000             -jmp 0xa391f7
    goto L_0x00a391f7;
L_0x00a3915f:
    // 00a3915f  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a39163  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a39167  01f7                   +add edi, esi
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
    // 00a39169  e8c8ebffff             -call 0xa37d36
    cpu.esp -= 4;
    sub_a37d36(app, cpu);
    if (cpu.terminate) return;
    // 00a3916e  66c7070000             -mov word ptr [edi], 0
    *app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 00a39173  eb02                   -jmp 0xa39177
    goto L_0x00a39177;
L_0x00a39175:
    // 00a39175  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a39177:
    // 00a39177  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a3917b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a3917d  e808050000             -call 0xa3968a
    cpu.esp -= 4;
    sub_a3968a(app, cpu);
    if (cpu.terminate) return;
    // 00a39182  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a39184  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a39188  e870e5ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a3918d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a3918f  e869e5ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a39194  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a39196  74bd                   -je 0xa39155
    if (cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a39198  833d8ce0a30000         +cmp dword ptr [0xa3e08c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3919f  7505                   -jne 0xa391a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a391a6;
    }
    // 00a391a1  e8aa050000             -call 0xa39750
    cpu.esp -= 4;
    sub_a39750(app, cpu);
    if (cpu.terminate) return;
L_0x00a391a6:
    // 00a391a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a391a8  e854000000             -call 0xa39201
    cpu.esp -= 4;
    sub_a39201(app, cpu);
    if (cpu.terminate) return;
    // 00a391ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a391af  75a4                   -jne 0xa39155
    if (!cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a391b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a391b3  e86bebffff             -call 0xa37d23
    cpu.esp -= 4;
    sub_a37d23(app, cpu);
    if (cpu.terminate) return;
    // 00a391b8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a391bb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a391bf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a391c2  e849e4ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a391c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a391c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a391cb  750f                   -jne 0xa391dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a391dc;
    }
    // 00a391cd  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a391d2  e82afeffff             -call 0xa39001
    cpu.esp -= 4;
    sub_a39001(app, cpu);
    if (cpu.terminate) return;
    // 00a391d7  e979ffffff             -jmp 0xa39155
    goto L_0x00a39155;
L_0x00a391dc:
    // 00a391dc  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a391e0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a391e2  e8b9050000             -call 0xa397a0
    cpu.esp -= 4;
    sub_a397a0(app, cpu);
    if (cpu.terminate) return;
    // 00a391e7  83f8ff                 +cmp eax, -1
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
    // 00a391ea  0f845effffff           -je 0xa3914e
    if (cpu.flags.zf)
    {
        goto L_0x00a3914e;
    }
    // 00a391f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a391f2  e8b6faffff             -call 0xa38cad
    cpu.esp -= 4;
    sub_a38cad(app, cpu);
    if (cpu.terminate) return;
L_0x00a391f7:
    // 00a391f7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a391fa  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391fb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391fc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391fd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391fe  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391ff  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a391fa(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a391fa;
    // 00a390d6  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a390d7  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a390d8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a390d9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a390da  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a390db  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a390dc  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a390df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a390e1  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a390e6  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a390ea  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a390ed  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 00a390f2  e87d050000             -call 0xa39674
    cpu.esp -= 4;
    sub_a39674(app, cpu);
    if (cpu.terminate) return;
    // 00a390f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a390f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a390fb  7458                   -je 0xa39155
    if (cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a390fd  39c8                   +cmp eax, ecx
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
    // 00a390ff  7454                   -je 0xa39155
    if (cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a39101  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a39103  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a39105  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 00a39107  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a39109  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 00a3910c  e8ffe4ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a39111  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a39113  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00a39117  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39119  743a                   -je 0xa39155
    if (cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a3911b  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00a3911d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a3911f  e812ecffff             -call 0xa37d36
    cpu.esp -= 4;
    sub_a37d36(app, cpu);
    if (cpu.terminate) return;
    // 00a39124  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 00a39127  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a39129  66c7042e0000           -mov word ptr [esi + ebp], 0
    *app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 00a3912f  e8efebffff             -call 0xa37d23
    cpu.esp -= 4;
    sub_a37d23(app, cpu);
    if (cpu.terminate) return;
    // 00a39134  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39136  743d                   -je 0xa39175
    if (cpu.flags.zf)
    {
        goto L_0x00a39175;
    }
    // 00a39138  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a3913a  8944240c               -mov dword ptr [esp + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a3913e  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a39141  e8cae4ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a39146  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a39148  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a3914a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3914c  7511                   -jne 0xa3915f
    if (!cpu.flags.zf)
    {
        goto L_0x00a3915f;
    }
L_0x00a3914e:
    // 00a3914e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a39150  e8a8e5ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a39155:
    // 00a39155  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a3915a  e998000000             -jmp 0xa391f7
    goto L_0x00a391f7;
L_0x00a3915f:
    // 00a3915f  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a39163  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a39167  01f7                   +add edi, esi
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
    // 00a39169  e8c8ebffff             -call 0xa37d36
    cpu.esp -= 4;
    sub_a37d36(app, cpu);
    if (cpu.terminate) return;
    // 00a3916e  66c7070000             -mov word ptr [edi], 0
    *app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 00a39173  eb02                   -jmp 0xa39177
    goto L_0x00a39177;
L_0x00a39175:
    // 00a39175  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00a39177:
    // 00a39177  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a3917b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a3917d  e808050000             -call 0xa3968a
    cpu.esp -= 4;
    sub_a3968a(app, cpu);
    if (cpu.terminate) return;
    // 00a39182  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a39184  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a39188  e870e5ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a3918d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a3918f  e869e5ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a39194  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a39196  74bd                   -je 0xa39155
    if (cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a39198  833d8ce0a30000         +cmp dword ptr [0xa3e08c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3919f  7505                   -jne 0xa391a6
    if (!cpu.flags.zf)
    {
        goto L_0x00a391a6;
    }
    // 00a391a1  e8aa050000             -call 0xa39750
    cpu.esp -= 4;
    sub_a39750(app, cpu);
    if (cpu.terminate) return;
L_0x00a391a6:
    // 00a391a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a391a8  e854000000             -call 0xa39201
    cpu.esp -= 4;
    sub_a39201(app, cpu);
    if (cpu.terminate) return;
    // 00a391ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a391af  75a4                   -jne 0xa39155
    if (!cpu.flags.zf)
    {
        goto L_0x00a39155;
    }
    // 00a391b1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a391b3  e86bebffff             -call 0xa37d23
    cpu.esp -= 4;
    sub_a37d23(app, cpu);
    if (cpu.terminate) return;
    // 00a391b8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a391bb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a391bf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00a391c2  e849e4ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a391c7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a391c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a391cb  750f                   -jne 0xa391dc
    if (!cpu.flags.zf)
    {
        goto L_0x00a391dc;
    }
    // 00a391cd  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a391d2  e82afeffff             -call 0xa39001
    cpu.esp -= 4;
    sub_a39001(app, cpu);
    if (cpu.terminate) return;
    // 00a391d7  e979ffffff             -jmp 0xa39155
    goto L_0x00a39155;
L_0x00a391dc:
    // 00a391dc  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp))));
    // 00a391e0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a391e2  e8b9050000             -call 0xa397a0
    cpu.esp -= 4;
    sub_a397a0(app, cpu);
    if (cpu.terminate) return;
    // 00a391e7  83f8ff                 +cmp eax, -1
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
    // 00a391ea  0f845effffff           -je 0xa3914e
    if (cpu.flags.zf)
    {
        goto L_0x00a3914e;
    }
    // 00a391f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a391f2  e8b6faffff             -call 0xa38cad
    cpu.esp -= 4;
    sub_a38cad(app, cpu);
    if (cpu.terminate) return;
L_0x00a391f7:
    // 00a391f7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_entry_0x00a391fa:
    // 00a391fa  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391fb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391fc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391fd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391fe  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a391ff  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39201(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39201  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a39202  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a39203  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39204  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a39205  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a39206  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a39207  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a3920a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a3920c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3920e  750a                   -jne 0xa3921a
    if (!cpu.flags.zf)
    {
        goto L_0x00a3921a;
    }
L_0x00a39210:
    // 00a39210  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a39215  e92b010000             -jmp 0xa39345
    goto L_0x00a39345;
L_0x00a3921a:
    // 00a3921a  66833800               +cmp word ptr [eax], 0
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
    // 00a3921e  7416                   -je 0xa39236
    if (cpu.flags.zf)
    {
        goto L_0x00a39236;
    }
    // 00a39220  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a39223  eb09                   -jmp 0xa3922e
    goto L_0x00a3922e;
L_0x00a39225:
    // 00a39225  6683f93d               +cmp cx, 0x3d
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a39229  740b                   -je 0xa39236
    if (cpu.flags.zf)
    {
        goto L_0x00a39236;
    }
    // 00a3922b  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a3922e:
    // 00a3922e  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.edx);
    // 00a39231  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a39234  75ef                   -jne 0xa39225
    if (!cpu.flags.zf)
    {
        goto L_0x00a39225;
    }
L_0x00a39236:
    // 00a39236  66833a00               +cmp word ptr [edx], 0
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
    // 00a3923a  74d4                   -je 0xa39210
    if (cpu.flags.zf)
    {
        goto L_0x00a39210;
    }
    // 00a3923c  66837a0200             +cmp word ptr [edx + 2], 0
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
    // 00a39241  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a39244  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a39246  8b0d8ce0a300           -mov ecx, dword ptr [0xa3e08c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
    // 00a3924c  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 00a3924e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a39250  7531                   -jne 0xa39283
    if (!cpu.flags.zf)
    {
        goto L_0x00a39283;
    }
    // 00a39252  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a39254  0f85e9000000           -jne 0xa39343
    if (!cpu.flags.zf)
    {
        goto L_0x00a39343;
    }
    // 00a3925a  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a3925f  e8ace3ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a39264  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a39266  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39268  74a6                   -je 0xa39210
    if (cpu.flags.zf)
    {
        goto L_0x00a39210;
    }
    // 00a3926a  a38ce0a300             -mov dword ptr [0xa3e08c], eax
    *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */) = cpu.eax;
    // 00a3926f  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00a39271  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a39274  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a39276  8958fc                 -mov dword ptr [eax - 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00a39279  a384e0a300             -mov dword ptr [0xa3e084], eax
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.eax;
    // 00a3927e  e9b2000000             -jmp 0xa39335
    goto L_0x00a39335;
L_0x00a39283:
    // 00a39283  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a39285  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a39287  e8c1000000             -call 0xa3934d
    cpu.esp -= 4;
    sub_a3934d(app, cpu);
    if (cpu.terminate) return;
    // 00a3928c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a3928e  0f85af000000           -jne 0xa39343
    if (!cpu.flags.zf)
    {
        goto L_0x00a39343;
    }
    // 00a39294  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39296  0f8f96000000           -jg 0xa39332
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a39332;
    }
    // 00a3929c  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a3929e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a392a0  8b2d84e0a300           -mov ebp, dword ptr [0xa3e084]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a392a6  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a392a8  40                     -inc eax
    (cpu.eax)++;
    // 00a392a9  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00a392ac  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a392b0  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a392b3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a392b7  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00a392ba  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a392bc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a392be  7533                   -jne 0xa392f3
    if (!cpu.flags.zf)
    {
        goto L_0x00a392f3;
    }
    // 00a392c0  e84be3ffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a392c5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a392c7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a392c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a392cb  0f843fffffff           -je 0xa39210
    if (cpu.flags.zf)
    {
        goto L_0x00a39210;
    }
    // 00a392d1  8b158ce0a300           -mov edx, dword ptr [0xa3e08c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
    // 00a392d7  e85aeaffff             -call 0xa37d36
    cpu.esp -= 4;
    sub_a37d36(app, cpu);
    if (cpu.terminate) return;
    // 00a392dc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a392df  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a392e3  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00a392e5  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a392e7  a384e0a300             -mov dword ptr [0xa3e084], eax
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.eax;
    // 00a392ec  e858afffff             -call 0xa34249
    cpu.esp -= 4;
    sub_a34249(app, cpu);
    if (cpu.terminate) return;
    // 00a392f1  eb2d                   -jmp 0xa39320
    goto L_0x00a39320;
L_0x00a392f3:
    // 00a392f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a392f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a392f7  e8e7d6ffff             -call 0xa369e3
    cpu.esp -= 4;
    sub_a369e3(app, cpu);
    if (cpu.terminate) return;
    // 00a392fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a392fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39300  0f840affffff           -je 0xa39210
    if (cpu.flags.zf)
    {
        goto L_0x00a39210;
    }
    // 00a39306  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a39309  8b1584e0a300           -mov edx, dword ptr [0xa3e084]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a3930f  01c5                   +add ebp, eax
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
    // 00a39311  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a39313  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a39315  e81c010000             -call 0xa39436
    cpu.esp -= 4;
    sub_a39436(app, cpu);
    if (cpu.terminate) return;
    // 00a3931a  892d84e0a300           -mov dword ptr [0xa3e084], ebp
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.ebp;
L_0x00a39320:
    // 00a39320  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a39322  890d8ce0a300           -mov dword ptr [0xa3e08c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */) = cpu.ecx;
    // 00a39328  c744810400000000       -mov dword ptr [ecx + eax*4 + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 00a39330  eb03                   -jmp 0xa39335
    goto L_0x00a39335;
L_0x00a39332:
    // 00a39332  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00a39335:
    // 00a39335  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a39337  893c81                 -mov dword ptr [ecx + eax*4], edi
    *app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = cpu.edi;
    // 00a3933a  a184e0a300             -mov eax, dword ptr [0xa3e084]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a3933f  c6040600               -mov byte ptr [esi + eax], 0
    *app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x00a39343:
    // 00a39343  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a39345:
    // 00a39345  83c408                 +add esp, 8
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
    // 00a39348  e9adfeffff             -jmp 0xa391fa
    return sub_a391fa(app, cpu);
}

/* align: skip  */
void sub_a3934d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3934d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3934e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3934f  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a39350  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a39351  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a39352  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a39354  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a39356  8b358ce0a300           -mov esi, dword ptr [0xa3e08c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
    // 00a3935c  e9bb000000             -jmp 0xa3941c
    goto L_0x00a3941c;
L_0x00a39361:
    // 00a39361  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00a39363  e9a7000000             -jmp 0xa3940f
    goto L_0x00a3940f;
L_0x00a39368:
    // 00a39368  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a3936a  668b02                 -mov ax, word ptr [edx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.edx);
    // 00a3936d  e8e4040000             -call 0xa39856
    cpu.esp -= 4;
    sub_a39856(app, cpu);
    if (cpu.terminate) return;
    // 00a39372  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a39374  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a39376  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = *app->getMemory<x86::reg16>(cpu.ebx);
    // 00a39379  e8d8040000             -call 0xa39856
    cpu.esp -= 4;
    sub_a39856(app, cpu);
    if (cpu.terminate) return;
    // 00a3937e  6639c1                 +cmp cx, ax
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
    // 00a39381  0f8592000000           -jne 0xa39419
    if (!cpu.flags.zf)
    {
        goto L_0x00a39419;
    }
    // 00a39387  66833a3d               +cmp word ptr [edx], 0x3d
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
    // 00a3938b  0f8578000000           -jne 0xa39409
    if (!cpu.flags.zf)
    {
        goto L_0x00a39409;
    }
    // 00a39391  8b158ce0a300           -mov edx, dword ptr [0xa3e08c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
    // 00a39397  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00a39399  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3939b  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 00a3939e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a393a0  7462                   -je 0xa39404
    if (cpu.flags.zf)
    {
        goto L_0x00a39404;
    }
    // 00a393a2  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a393a4  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a393a6  eb08                   -jmp 0xa393b0
    goto L_0x00a393b0;
L_0x00a393a8:
    // 00a393a8  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00a393ab  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a393ad  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a393b0:
    // 00a393b0  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a393b3  75f3                   -jne 0xa393a8
    if (!cpu.flags.zf)
    {
        goto L_0x00a393a8;
    }
    // 00a393b5  8b3584e0a300           -mov esi, dword ptr [0xa3e084]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a393bb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a393bd  7441                   -je 0xa39400
    if (cpu.flags.zf)
    {
        goto L_0x00a39400;
    }
    // 00a393bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a393c1  803c0700               +cmp byte ptr [edi + eax], 0
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
    // 00a393c5  7407                   -je 0xa393ce
    if (cpu.flags.zf)
    {
        goto L_0x00a393ce;
    }
    // 00a393c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a393c9  e82fe3ffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a393ce:
    // 00a393ce  8b2d8ce0a300           -mov ebp, dword ptr [0xa3e08c]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
    // 00a393d4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00a393d6  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00a393d8  8b1584e0a300           -mov edx, dword ptr [0xa3e084]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */);
    // 00a393de  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00a393e1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a393e3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a393e5  e84c000000             -call 0xa39436
    cpu.esp -= 4;
    sub_a39436(app, cpu);
    if (cpu.terminate) return;
    // 00a393ea  890d84e0a300           -mov dword ptr [0xa3e084], ecx
    *app->getMemory<x86::reg32>(x86::reg32(10739844) /* 0xa3e084 */) = cpu.ecx;
    // 00a393f0  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 00a393f3  eb07                   -jmp 0xa393fc
    goto L_0x00a393fc;
L_0x00a393f5:
    // 00a393f5  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a393f8  47                     -inc edi
    (cpu.edi)++;
    // 00a393f9  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a393fb  40                     -inc eax
    (cpu.eax)++;
L_0x00a393fc:
    // 00a393fc  39f7                   +cmp edi, esi
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
    // 00a393fe  7cf5                   -jl 0xa393f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a393f5;
    }
L_0x00a39400:
    // 00a39400  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a39402  eb2c                   -jmp 0xa39430
    goto L_0x00a39430;
L_0x00a39404:
    // 00a39404  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 00a39407  eb27                   -jmp 0xa39430
    goto L_0x00a39430;
L_0x00a39409:
    // 00a39409  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a3940c  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00a3940f:
    // 00a3940f  66833b00               +cmp word ptr [ebx], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a39413  0f854fffffff           -jne 0xa39368
    if (!cpu.flags.zf)
    {
        goto L_0x00a39368;
    }
L_0x00a39419:
    // 00a39419  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a3941c:
    // 00a3941c  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a3941e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a39420  0f853bffffff           -jne 0xa39361
    if (!cpu.flags.zf)
    {
        goto L_0x00a39361;
    }
    // 00a39426  a18ce0a300             -mov eax, dword ptr [0xa3e08c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10739852) /* 0xa3e08c */);
    // 00a3942b  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a3942d  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x00a39430:
    // 00a39430  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39431  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39432  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39433  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39434  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39435  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39436(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39436  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a39437  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a39438  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a39439  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a3943b  39c2                   +cmp edx, eax
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
    // 00a3943d  7440                   -je 0xa3947f
    if (cpu.flags.zf)
    {
        goto L_0x00a3947f;
    }
    // 00a3943f  7328                   -jae 0xa39469
    if (!cpu.flags.cf)
    {
        goto L_0x00a39469;
    }
    // 00a39441  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a39444  39c7                   +cmp edi, eax
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
    // 00a39446  7621                   -jbe 0xa39469
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a39469;
    }
    // 00a39448  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 00a3944b  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00a3944e  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a39450  4f                     -dec edi
    (cpu.edi)--;
    // 00a39451  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a39452  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a39454  fd                     -std 
    cpu.flags.df = 1;
    // 00a39455  4e                     -dec esi
    (cpu.esi)--;
    // 00a39456  4f                     -dec edi
    (cpu.edi)--;
    // 00a39457  d1e9                   +shr ecx, 1
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
    // 00a39459  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
    while (cpu.ecx)
    {
        *app->getMemory<x86::reg16>(cpu.ees + cpu.edi) = *app->getMemory<x86::reg16>(cpu.esi);
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
    // 00a3945c  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00a3945e  46                     -inc esi
    (cpu.esi)++;
    // 00a3945f  47                     -inc edi
    (cpu.edi)++;
    // 00a39460  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 00a39463  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a39464  fc                     -cld 
    cpu.flags.df = 0;
    // 00a39465  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39466  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39467  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39468  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39469:
    // 00a39469  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a3946b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a3946d  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a3946f  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a39470  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 00a39472  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a39473  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a39476  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a39478  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39479  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00a3947c  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 00a3947e  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a3947f:
    // 00a3947f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39480  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39481  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39482  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39483(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39483  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39484  803800                 +cmp byte ptr [eax], 0
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
    // 00a39487  7507                   -jne 0xa39490
    if (!cpu.flags.zf)
    {
        goto L_0x00a39490;
    }
    // 00a39489  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a3948e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3948f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39490:
    // 00a39490  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a39497  7422                   -je 0xa394bb
    if (cpu.flags.zf)
    {
        goto L_0x00a394bb;
    }
    // 00a39499  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a3949b  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a3949d  8a9215d8a300           -mov dl, byte ptr [edx + 0xa3d815]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a394a3  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a394a6  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a394ac  740d                   -je 0xa394bb
    if (cpu.flags.zf)
    {
        goto L_0x00a394bb;
    }
    // 00a394ae  80780100               +cmp byte ptr [eax + 1], 0
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
    // 00a394b2  7507                   -jne 0xa394bb
    if (!cpu.flags.zf)
    {
        goto L_0x00a394bb;
    }
    // 00a394b4  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a394b9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a394ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a394bb:
    // 00a394bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a394bd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a394be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a394bf(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a394bf  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a394c0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a394c1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a394c4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a394c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a394c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a394ca  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a394cc  e895030000             -call 0xa39866
    cpu.esp -= 4;
    sub_a39866(app, cpu);
    if (cpu.terminate) return;
    // 00a394d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a394d3  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a394d5  e883000000             -call 0xa3955d
    cpu.esp -= 4;
    sub_a3955d(app, cpu);
    if (cpu.terminate) return;
    // 00a394da  881404                 -mov byte ptr [esp + eax], dl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a394dd  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a394e1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a394e3  e87e030000             -call 0xa39866
    cpu.esp -= 4;
    sub_a39866(app, cpu);
    if (cpu.terminate) return;
    // 00a394e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a394ea  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a394ec  e86c000000             -call 0xa3955d
    cpu.esp -= 4;
    sub_a3955d(app, cpu);
    if (cpu.terminate) return;
    // 00a394f1  88740404               -mov byte ptr [esp + eax + 4], dh
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 00a394f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a394f7  e89b030000             -call 0xa39897
    cpu.esp -= 4;
    sub_a39897(app, cpu);
    if (cpu.terminate) return;
    // 00a394fc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a39500  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a39504  e88e030000             -call 0xa39897
    cpu.esp -= 4;
    sub_a39897(app, cpu);
    if (cpu.terminate) return;
    // 00a39509  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3950b  e878000000             -call 0xa39588
    cpu.esp -= 4;
    sub_a39588(app, cpu);
    if (cpu.terminate) return;
    // 00a39510  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a39513  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39514  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39515  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39516(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39516  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39517  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3951e  7420                   -je 0xa39540
    if (cpu.flags.zf)
    {
        goto L_0x00a39540;
    }
    // 00a39520  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a39522  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a39524  8a9215d8a300           -mov dl, byte ptr [edx + 0xa3d815]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a3952a  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a3952d  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a39533  740b                   -je 0xa39540
    if (cpu.flags.zf)
    {
        goto L_0x00a39540;
    }
    // 00a39535  80780100               +cmp byte ptr [eax + 1], 0
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
    // 00a39539  7405                   -je 0xa39540
    if (cpu.flags.zf)
    {
        goto L_0x00a39540;
    }
    // 00a3953b  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a3953e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3953f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39540:
    // 00a39540  40                     -inc eax
    (cpu.eax)++;
    // 00a39541  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39542  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39543(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39543  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a39544  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a39546  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a39548  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 00a3954b  740c                   -je 0xa39559
    if (cpu.flags.zf)
    {
        goto L_0x00a39559;
    }
    // 00a3954d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a3954f  885801                 -mov byte ptr [eax + 1], bl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 00a39552  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a39555  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a39557  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39558  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39559:
    // 00a39559  881a                   -mov byte ptr [edx], bl
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 00a3955b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3955c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3955d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3955d  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a39564  741c                   -je 0xa39582
    if (cpu.flags.zf)
    {
        goto L_0x00a39582;
    }
    // 00a39566  8a00                   -mov al, byte ptr [eax]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a39568  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a3956d  8a8015d8a300           -mov al, byte ptr [eax + 0xa3d815]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a39573  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a39575  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a3957a  7406                   -je 0xa39582
    if (cpu.flags.zf)
    {
        goto L_0x00a39582;
    }
    // 00a3957c  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a39581  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39582:
    // 00a39582  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a39587  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39588(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39588  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a39589  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3958a  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a3958c  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3958e  7541                   -jne 0xa395d1
    if (!cpu.flags.zf)
    {
        goto L_0x00a395d1;
    }
    // 00a39590  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a39597  741f                   -je 0xa395b8
    if (cpu.flags.zf)
    {
        goto L_0x00a395b8;
    }
    // 00a39599  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a3959b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a3959d  8a9b15d8a300           -mov bl, byte ptr [ebx + 0xa3d815]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a395a3  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a395a6  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a395ac  740a                   -je 0xa395b8
    if (cpu.flags.zf)
    {
        goto L_0x00a395b8;
    }
    // 00a395ae  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a395b1  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a395b4  38cb                   +cmp bl, cl
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a395b6  7505                   -jne 0xa395bd
    if (!cpu.flags.zf)
    {
        goto L_0x00a395bd;
    }
L_0x00a395b8:
    // 00a395b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a395ba  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a395bb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a395bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a395bd:
    // 00a395bd  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a395bf  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a395c4  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00a395c6  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a395cc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a395ce  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a395cf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a395d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a395d1:
    // 00a395d1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a395d3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a395d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a395d7  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a395d9  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a395db  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a395dd  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a395de  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a395df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a395e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a395e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a395e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a395e2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a395e3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a395e4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a395e6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a395e9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a395eb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a395ed  7507                   -jne 0xa395f6
    if (!cpu.flags.zf)
    {
        goto L_0x00a395f6;
    }
L_0x00a395ef:
    // 00a395ef  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a395f1  e977000000             -jmp 0xa3966d
    goto L_0x00a3966d;
L_0x00a395f6:
    // 00a395f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a395f8  0f866a000000           -jbe 0xa39668
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a39668;
    }
    // 00a395fe  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a39601  750b                   -jne 0xa3960e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3960e;
    }
    // 00a39603  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a39605  74e8                   -je 0xa395ef
    if (cpu.flags.zf)
    {
        goto L_0x00a395ef;
    }
    // 00a39607  66c7060000             -mov word ptr [esi], 0
    *app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 00a3960c  ebe1                   -jmp 0xa395ef
    goto L_0x00a395ef;
L_0x00a3960e:
    // 00a3960e  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a39615  7419                   -je 0xa39630
    if (cpu.flags.zf)
    {
        goto L_0x00a39630;
    }
    // 00a39617  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a39619  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a3961b  8a8015d8a300           -mov al, byte ptr [eax + 0xa3d815]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a39621  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a39623  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a39628  7406                   -je 0xa39630
    if (cpu.flags.zf)
    {
        goto L_0x00a39630;
    }
    // 00a3962a  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a3962e  7438                   -je 0xa39668
    if (cpu.flags.zf)
    {
        goto L_0x00a39668;
    }
L_0x00a39630:
    // 00a39630  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a39632  e826ffffff             -call 0xa3955d
    cpu.esp -= 4;
    sub_a3955d(app, cpu);
    if (cpu.terminate) return;
    // 00a39637  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a39639  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a3963c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a3963e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3963f  39c3                   +cmp ebx, eax
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
    // 00a39641  7302                   -jae 0xa39645
    if (!cpu.flags.cf)
    {
        goto L_0x00a39645;
    }
    // 00a39643  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a39645:
    // 00a39645  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a39646  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39647  6a08                   -push 8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00a39649  a1c4cba300             -mov eax, dword ptr [0xa3cbc4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(10734532) /* 0xa3cbc4 */);
    // 00a3964e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3964f  2eff1590a9a300         -call dword ptr cs:[0xa3a990]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725776) /* 0xa3a990 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a39656  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39658  740e                   -je 0xa39668
    if (cpu.flags.zf)
    {
        goto L_0x00a39668;
    }
    // 00a3965a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a3965c  7406                   -je 0xa39664
    if (cpu.flags.zf)
    {
        goto L_0x00a39664;
    }
    // 00a3965e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00a39661  668906                 -mov word ptr [esi], ax
    *app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x00a39664:
    // 00a39664  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a39666  eb05                   -jmp 0xa3966d
    goto L_0x00a3966d;
L_0x00a39668:
    // 00a39668  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a3966d:
    // 00a3966d  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00a3966f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39670  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39671  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39672  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39673  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39674(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39674  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a39675  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x00a39677:
    // 00a39677  663b18                 +cmp bx, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(*app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a3967a  740c                   -je 0xa39688
    if (cpu.flags.zf)
    {
        goto L_0x00a39688;
    }
    // 00a3967c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a3967e  40                     -inc eax
    (cpu.eax)++;
    // 00a3967f  40                     -inc eax
    (cpu.eax)++;
    // 00a39680  66833a00               +cmp word ptr [edx], 0
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
    // 00a39684  75f1                   -jne 0xa39677
    if (!cpu.flags.zf)
    {
        goto L_0x00a39677;
    }
    // 00a39686  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a39688:
    // 00a39688  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39689  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3968a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3968a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a3968b  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a3968c  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a3968d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3968e  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a3968f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a39690  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00a39692  66813d21cba3000080     +cmp word ptr [0xa3cb21], 0x8000
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(x86::reg32(10734369) /* 0xa3cb21 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a3969b  730e                   -jae 0xa396ab
    if (!cpu.flags.cf)
    {
        goto L_0x00a396ab;
    }
    // 00a3969d  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a3969e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a3969f  2eff159ca9a300         -call dword ptr cs:[0xa3a99c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725788) /* 0xa3a99c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a396a6  e99c000000             -jmp 0xa39747
    goto L_0x00a39747;
L_0x00a396ab:
    // 00a396ab  e873e6ffff             -call 0xa37d23
    cpu.esp -= 4;
    sub_a37d23(app, cpu);
    if (cpu.terminate) return;
    // 00a396b0  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a396b2  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a396b5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a396b7  e854dfffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a396bc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a396be  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a396c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a396c2  0f847f000000           -je 0xa39747
    if (cpu.flags.zf)
    {
        goto L_0x00a39747;
    }
    // 00a396c8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a396ca  7504                   -jne 0xa396d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a396d0;
    }
    // 00a396cc  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00a396ce  eb1d                   -jmp 0xa396ed
    goto L_0x00a396ed;
L_0x00a396d0:
    // 00a396d0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a396d2  e84ce6ffff             -call 0xa37d23
    cpu.esp -= 4;
    sub_a37d23(app, cpu);
    if (cpu.terminate) return;
    // 00a396d7  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00a396d9  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a396dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a396de  e82ddfffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a396e3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a396e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a396e7  7504                   -jne 0xa396ed
    if (!cpu.flags.zf)
    {
        goto L_0x00a396ed;
    }
    // 00a396e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a396eb  eb1e                   -jmp 0xa3970b
    goto L_0x00a3970b;
L_0x00a396ed:
    // 00a396ed  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a396f0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a396f2  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a396f4  e8a7000000             -call 0xa397a0
    cpu.esp -= 4;
    sub_a397a0(app, cpu);
    if (cpu.terminate) return;
    // 00a396f9  83f8ff                 +cmp eax, -1
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
    // 00a396fc  7516                   -jne 0xa39714
    if (!cpu.flags.zf)
    {
        goto L_0x00a39714;
    }
    // 00a396fe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a39700  e8f8dfffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a39705  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a39707  7407                   -je 0xa39710
    if (cpu.flags.zf)
    {
        goto L_0x00a39710;
    }
L_0x00a39709:
    // 00a39709  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a3970b:
    // 00a3970b  e8eddfffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a39710:
    // 00a39710  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a39712  eb33                   -jmp 0xa39747
    goto L_0x00a39747;
L_0x00a39714:
    // 00a39714  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a39716  7410                   -je 0xa39728
    if (cpu.flags.zf)
    {
        goto L_0x00a39728;
    }
    // 00a39718  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00a3971a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a3971c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a3971e  e87d000000             -call 0xa397a0
    cpu.esp -= 4;
    sub_a397a0(app, cpu);
    if (cpu.terminate) return;
    // 00a39723  83f8ff                 +cmp eax, -1
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
    // 00a39726  74e1                   -je 0xa39709
    if (cpu.flags.zf)
    {
        goto L_0x00a39709;
    }
L_0x00a39728:
    // 00a39728  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a39729  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a3972a  2eff1598a9a300         -call dword ptr cs:[0xa3a998]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725784) /* 0xa3a998 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a39731  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a39733  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a39735  e8c3dfffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a3973a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a3973c  7407                   -je 0xa39745
    if (cpu.flags.zf)
    {
        goto L_0x00a39745;
    }
    // 00a3973e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a39740  e8b8dfffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
L_0x00a39745:
    // 00a39745  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00a39747:
    // 00a39747  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a3974a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3974b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3974c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3974d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3974e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3974f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39750(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39750  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a39751  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a39752  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39753  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a39754  8b3588e0a300           -mov esi, dword ptr [0xa3e088]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(10739848) /* 0xa3e088 */);
    // 00a3975a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a3975c  743d                   -je 0xa3979b
    if (cpu.flags.zf)
    {
        goto L_0x00a3979b;
    }
L_0x00a3975e:
    // 00a3975e  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00a39760  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a39763  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a39765  7434                   -je 0xa3979b
    if (cpu.flags.zf)
    {
        goto L_0x00a3979b;
    }
    // 00a39767  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a39769  e866f8ffff             -call 0xa38fd4
    cpu.esp -= 4;
    sub_a38fd4(app, cpu);
    if (cpu.terminate) return;
    // 00a3976e  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a39771  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 00a39774  e897deffff             -call 0xa37610
    cpu.esp -= 4;
    sub_a37610(app, cpu);
    if (cpu.terminate) return;
    // 00a39779  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a3977b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a3977d  74df                   -je 0xa3975e
    if (cpu.flags.zf)
    {
        goto L_0x00a3975e;
    }
    // 00a3977f  e8dff8ffff             -call 0xa39063
    cpu.esp -= 4;
    sub_a39063(app, cpu);
    if (cpu.terminate) return;
    // 00a39784  83f8ff                 +cmp eax, -1
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
    // 00a39787  7409                   -je 0xa39792
    if (cpu.flags.zf)
    {
        goto L_0x00a39792;
    }
    // 00a39789  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a3978b  e871faffff             -call 0xa39201
    cpu.esp -= 4;
    sub_a39201(app, cpu);
    if (cpu.terminate) return;
    // 00a39790  ebcc                   -jmp 0xa3975e
    goto L_0x00a3975e;
L_0x00a39792:
    // 00a39792  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a39794  e864dfffff             -call 0xa376fd
    cpu.esp -= 4;
    sub_a376fd(app, cpu);
    if (cpu.terminate) return;
    // 00a39799  ebc3                   -jmp 0xa3975e
    goto L_0x00a3975e;
L_0x00a3979b:
    // 00a3979b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3979c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3979d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3979e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3979f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a397a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a397a0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a397a1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a397a2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a397a3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a397a4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a397a7  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a397a8  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a397aa  895c2404               -mov dword ptr [esp + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00a397ae  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a397b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a397b2  0f8472000000           -je 0xa3982a
    if (cpu.flags.zf)
    {
        goto L_0x00a3982a;
    }
L_0x00a397b8:
    // 00a397b8  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 00a397bd  0f8689000000           -jbe 0xa3984c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a3984c;
    }
    // 00a397c3  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = *app->getMemory<x86::reg16>(cpu.ebp);
    // 00a397c7  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a397ca  7421                   -je 0xa397ed
    if (cpu.flags.zf)
    {
        goto L_0x00a397ed;
    }
    // 00a397cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a397ce  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a397d2  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 00a397d5  e85db8ffff             -call 0xa35037
    cpu.esp -= 4;
    sub_a35037(app, cpu);
    if (cpu.terminate) return;
    // 00a397da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a397dc  83f8ff                 +cmp eax, -1
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
    // 00a397df  0f8469000000           -je 0xa3984e
    if (cpu.flags.zf)
    {
        goto L_0x00a3984e;
    }
    // 00a397e5  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a397e9  7761                   -ja 0xa3984c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a3984c;
    }
    // 00a397eb  eb08                   -jmp 0xa397f5
    goto L_0x00a397f5;
L_0x00a397ed:
    // 00a397ed  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a397f0  c60000                 -mov byte ptr [eax], 0
    *app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00a397f3  eb57                   -jmp 0xa3984c
    goto L_0x00a3984c;
L_0x00a397f5:
    // 00a397f5  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a397f9  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00a397fc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a397fe  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a397ff  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a39801  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a39803  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a39804  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a39806  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a39809  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a3980b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a3980d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a39810  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a39812  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39813  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a39814  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a39817  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a39819  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a3981d  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00a3981f  29d0                   +sub eax, edx
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
    // 00a39821  893c24                 -mov dword ptr [esp], edi
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00a39824  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00a39828  eb8e                   -jmp 0xa397b8
    goto L_0x00a397b8;
L_0x00a3982a:
    // 00a3982a  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00a3982f  741b                   -je 0xa3984c
    if (cpu.flags.zf)
    {
        goto L_0x00a3984c;
    }
    // 00a39831  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a39833  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a39837  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.ebp);
    // 00a3983b  e8f7b7ffff             -call 0xa35037
    cpu.esp -= 4;
    sub_a35037(app, cpu);
    if (cpu.terminate) return;
    // 00a39840  83f8ff                 +cmp eax, -1
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
    // 00a39843  7409                   -je 0xa3984e
    if (cpu.flags.zf)
    {
        goto L_0x00a3984e;
    }
    // 00a39845  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a39848  01c3                   +add ebx, eax
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
    // 00a3984a  ebde                   -jmp 0xa3982a
    goto L_0x00a3982a;
L_0x00a3984c:
    // 00a3984c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00a3984e:
    // 00a3984e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00a39851  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39852  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39853  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39854  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39855  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39856(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39856  663d6100               +cmp ax, 0x61
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
    // 00a3985a  7209                   -jb 0xa39865
    if (cpu.flags.cf)
    {
        goto L_0x00a39865;
    }
    // 00a3985c  663d7a00               +cmp ax, 0x7a
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
    // 00a39860  7703                   -ja 0xa39865
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a39865;
    }
    // 00a39862  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a39865:
    // 00a39865  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39866(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39866  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a39867  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3986e  7421                   -je 0xa39891
    if (cpu.flags.zf)
    {
        goto L_0x00a39891;
    }
    // 00a39870  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a39872  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a39874  8a9b15d8a300           -mov bl, byte ptr [ebx + 0xa3d815]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a3987a  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a3987d  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a39883  740c                   -je 0xa39891
    if (cpu.flags.zf)
    {
        goto L_0x00a39891;
    }
    // 00a39885  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a39887  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00a39889  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a3988c  885001                 -mov byte ptr [eax + 1], dl
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00a3988f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39890  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39891:
    // 00a39891  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx);
    // 00a39893  8810                   -mov byte ptr [eax], dl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a39895  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39896  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39897(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39897  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a39898  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a39899  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3989a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a3989d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00a3989f:
    // 00a3989f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a398a1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a398a3  e8dbfbffff             -call 0xa39483
    cpu.esp -= 4;
    sub_a39483(app, cpu);
    if (cpu.terminate) return;
    // 00a398a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a398aa  7531                   -jne 0xa398dd
    if (!cpu.flags.zf)
    {
        goto L_0x00a398dd;
    }
    // 00a398ac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a398ae  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a398b0  e831000000             -call 0xa398e6
    cpu.esp -= 4;
    sub_a398e6(app, cpu);
    if (cpu.terminate) return;
    // 00a398b5  e867000000             -call 0xa39921
    cpu.esp -= 4;
    sub_a39921(app, cpu);
    if (cpu.terminate) return;
    // 00a398ba  e884fcffff             -call 0xa39543
    cpu.esp -= 4;
    sub_a39543(app, cpu);
    if (cpu.terminate) return;
    // 00a398bf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a398c1  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 00a398c3  e895fcffff             -call 0xa3955d
    cpu.esp -= 4;
    sub_a3955d(app, cpu);
    if (cpu.terminate) return;
    // 00a398c8  881404                 -mov byte ptr [esp + eax], dl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a398cb  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a398cd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a398cf  e892ffffff             -call 0xa39866
    cpu.esp -= 4;
    sub_a39866(app, cpu);
    if (cpu.terminate) return;
    // 00a398d4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a398d6  e83bfcffff             -call 0xa39516
    cpu.esp -= 4;
    sub_a39516(app, cpu);
    if (cpu.terminate) return;
    // 00a398db  ebc2                   -jmp 0xa3989f
    goto L_0x00a3989f;
L_0x00a398dd:
    // 00a398dd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a398df  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a398e2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a398e3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a398e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a398e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a398e6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a398e6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a398e7  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a398ee  7428                   -je 0xa39918
    if (cpu.flags.zf)
    {
        goto L_0x00a39918;
    }
    // 00a398f0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a398f2  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a398f4  8a9215d8a300           -mov dl, byte ptr [edx + 0xa3d815]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a398fa  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a398fd  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a39903  7413                   -je 0xa39918
    if (cpu.flags.zf)
    {
        goto L_0x00a39918;
    }
    // 00a39905  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a39907  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a39909  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00a3990c  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a3990f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a39914  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00a39916  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39917  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39918:
    // 00a39918  8a00                   -mov al, byte ptr [eax]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax);
    // 00a3991a  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a3991f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39920  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39921(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39921  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a39922  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a39923  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a39924  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a39927  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a39929  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a3992b  e813fcffff             -call 0xa39543
    cpu.esp -= 4;
    sub_a39543(app, cpu);
    if (cpu.terminate) return;
    // 00a39930  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a39932  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a39934  e824fcffff             -call 0xa3955d
    cpu.esp -= 4;
    sub_a3955d(app, cpu);
    if (cpu.terminate) return;
    // 00a39939  881404                 -mov byte ptr [esp + eax], dl
    *app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a3993c  813dc4cba300a4030000   +cmp dword ptr [0xa3cbc4], 0x3a4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10734532) /* 0xa3cbc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a39946  7526                   -jne 0xa3996e
    if (!cpu.flags.zf)
    {
        goto L_0x00a3996e;
    }
    // 00a39948  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a3994f  741d                   -je 0xa3996e
    if (cpu.flags.zf)
    {
        goto L_0x00a3996e;
    }
    // 00a39951  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a39953  8a0424                 -mov al, byte ptr [esp]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp);
    // 00a39956  8a8015d8a300           -mov al, byte ptr [eax + 0xa3d815]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a3995c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a3995e  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a39963  7409                   -je 0xa3996e
    if (cpu.flags.zf)
    {
        goto L_0x00a3996e;
    }
    // 00a39965  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a39967  e81e000000             -call 0xa3998a
    cpu.esp -= 4;
    sub_a3998a(app, cpu);
    if (cpu.terminate) return;
    // 00a3996c  eb15                   -jmp 0xa39983
    goto L_0x00a39983;
L_0x00a3996e:
    // 00a3996e  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a39970  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a39974  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a39975  2eff151ca9a300         -call dword ptr cs:[0xa3a91c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10725660) /* 0xa3a91c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a3997c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a3997e  e863ffffff             -call 0xa398e6
    cpu.esp -= 4;
    sub_a398e6(app, cpu);
    if (cpu.terminate) return;
L_0x00a39983:
    // 00a39983  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a39986  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39987  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39988  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39989  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3998a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3998a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3998b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a3998d  e80b000000             -call 0xa3999d
    cpu.esp -= 4;
    sub_a3999d(app, cpu);
    if (cpu.terminate) return;
    // 00a39992  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39994  7403                   -je 0xa39999
    if (cpu.flags.zf)
    {
        goto L_0x00a39999;
    }
    // 00a39996  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x00a39999:
    // 00a39999  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a3999b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a3999c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a3999d(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a3999d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a3999e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a399a0  e83b000000             -call 0xa399e0
    cpu.esp -= 4;
    sub_a399e0(app, cpu);
    if (cpu.terminate) return;
    // 00a399a5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a399a7  741f                   -je 0xa399c8
    if (cpu.flags.zf)
    {
        goto L_0x00a399c8;
    }
    // 00a399a9  81fa81820000           +cmp edx, 0x8281
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
    // 00a399af  7211                   -jb 0xa399c2
    if (cpu.flags.cf)
    {
        goto L_0x00a399c2;
    }
    // 00a399b1  81fa9a820000           +cmp edx, 0x829a
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
    // 00a399b7  7709                   -ja 0xa399c2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a399c2;
    }
    // 00a399b9  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a399be  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a399c0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a399c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a399c2:
    // 00a399c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a399c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a399c6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a399c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a399c8:
    // 00a399c8  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00a399ca  fec0                   -inc al
    (cpu.al)++;
    // 00a399cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a399ce  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a399d0  8a8218cda300           -mov al, byte ptr [edx + 0xa3cd18]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10734872) /* 0xa3cd18 */);
    // 00a399d6  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 00a399d8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a399da  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00a399dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a399de  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a399df  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a399e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a399e0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a399e1  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a399e8  7431                   -je 0xa39a1b
    if (cpu.flags.zf)
    {
        goto L_0x00a39a1b;
    }
    // 00a399ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a399ec  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 00a399ef  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a399f5  8a9215d8a300           -mov dl, byte ptr [edx + 0xa3d815]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10737685) /* 0xa3d815 */);
    // 00a399fb  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a399fe  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a39a04  7415                   -je 0xa39a1b
    if (cpu.flags.zf)
    {
        goto L_0x00a39a1b;
    }
    // 00a39a06  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a39a0b  e80f000000             -call 0xa39a1f
    cpu.esp -= 4;
    sub_a39a1f(app, cpu);
    if (cpu.terminate) return;
    // 00a39a10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39a12  7407                   -je 0xa39a1b
    if (cpu.flags.zf)
    {
        goto L_0x00a39a1b;
    }
    // 00a39a14  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a39a19  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39a1a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39a1b:
    // 00a39a1b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a39a1d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a39a1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39a1f(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a1f  833d10d8a30000         +cmp dword ptr [0xa3d810], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10737680) /* 0xa3d810 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a39a26  7429                   -je 0xa39a51
    if (cpu.flags.zf)
    {
        goto L_0x00a39a51;
    }
    // 00a39a28  813dc4cba300a4030000   +cmp dword ptr [0xa3cbc4], 0x3a4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(10734532) /* 0xa3cbc4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a39a32  740a                   -je 0xa39a3e
    if (cpu.flags.zf)
    {
        goto L_0x00a39a3e;
    }
    // 00a39a34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a39a36  741b                   -je 0xa39a53
    if (cpu.flags.zf)
    {
        goto L_0x00a39a53;
    }
    // 00a39a38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a39a3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39a3e:
    // 00a39a3e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a39a43  8a80b9cfa300           -mov al, byte ptr [eax + 0xa3cfb9]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10735545) /* 0xa3cfb9 */);
    // 00a39a49  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a39a4b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a39a50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a39a51:
    // 00a39a51  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a39a53:
    // 00a39a53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a39a54(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a54  ff251ca9a300           -jmp dword ptr [0xa3a91c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725660), cpu);
}

/* align: skip  */
void sub_a39a5a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a5a  ff259ca9a300           -jmp dword ptr [0xa3a99c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725788), cpu);
}

/* align: skip  */
void sub_a39a60(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a60  ff2598a9a300           -jmp dword ptr [0xa3a998]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725784), cpu);
}

/* align: skip  */
void sub_a39a66(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a66  ff2540a9a300           -jmp dword ptr [0xa3a940]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725696), cpu);
}

/* align: skip  */
void sub_a39a6c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a6c  ff25d0a9a300           -jmp dword ptr [0xa3a9d0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725840), cpu);
}

/* align: skip  */
void sub_a39a72(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a72  ff2530a9a300           -jmp dword ptr [0xa3a930]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725680), cpu);
}

/* align: skip  */
void sub_a39a78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a78  ff2558a9a300           -jmp dword ptr [0xa3a958]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725720), cpu);
}

/* align: skip  */
void sub_a39a7e(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a7e  ff25a0a9a300           -jmp dword ptr [0xa3a9a0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725792), cpu);
}

/* align: skip  */
void sub_a39a84(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a84  ff25c8a9a300           -jmp dword ptr [0xa3a9c8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725832), cpu);
}

/* align: skip  */
void sub_a39a8a(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a8a  ff25c4a9a300           -jmp dword ptr [0xa3a9c4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725828), cpu);
}

/* align: skip  */
void sub_a39a90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a90  ff2594a9a300           -jmp dword ptr [0xa3a994]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725780), cpu);
}

/* align: skip  */
void sub_a39a96(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a96  ff252ca9a300           -jmp dword ptr [0xa3a92c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725676), cpu);
}

/* align: skip  */
void sub_a39a9c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39a9c  ff2560a9a300           -jmp dword ptr [0xa3a960]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725728), cpu);
}

/* align: skip  */
void sub_a39aa2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39aa2  ff25aca9a300           -jmp dword ptr [0xa3a9ac]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725804), cpu);
}

/* align: skip  */
void sub_a39aa8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39aa8  ff25c0a9a300           -jmp dword ptr [0xa3a9c0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725824), cpu);
}

/* align: skip  */
void sub_a39aae(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39aae  ff2578a9a300           -jmp dword ptr [0xa3a978]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725752), cpu);
}

/* align: skip  */
void sub_a39ab4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39ab4  ff258ca9a300           -jmp dword ptr [0xa3a98c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725772), cpu);
}

/* align: skip  */
void sub_a39aba(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39aba  ff25cca9a300           -jmp dword ptr [0xa3a9cc]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725836), cpu);
}

/* align: skip  */
void sub_a39ac0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39ac0  ff2590a9a300           -jmp dword ptr [0xa3a990]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725776), cpu);
}

/* align: skip  */
void sub_a39ac6(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39ac6  ff256ca9a300           -jmp dword ptr [0xa3a96c]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725740), cpu);
}

/* align: skip  */
void sub_a39acc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39acc  ff25b4a9a300           -jmp dword ptr [0xa3a9b4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725812), cpu);
}

/* align: skip  */
void sub_a39ad2(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39ad2  ff2524a9a300           -jmp dword ptr [0xa3a924]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725668), cpu);
}

/* align: skip  */
void sub_a39ad8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39ad8  ff25bca9a300           -jmp dword ptr [0xa3a9bc]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725820), cpu);
}

/* align: skip  */
void sub_a39ade(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39ade  ff25b0a9a300           -jmp dword ptr [0xa3a9b0]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725808), cpu);
}

/* align: skip  */
void sub_a39ae4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39ae4  ff25a4a9a300           -jmp dword ptr [0xa3a9a4]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725796), cpu);
}

/* align: skip  */
void sub_a39aea(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a39aea  ff25b8a9a300           -jmp dword ptr [0xa3a9b8]
    return app->dynamic_call(*app->getMemory<x86::reg32>(10725816), cpu);
}

}
