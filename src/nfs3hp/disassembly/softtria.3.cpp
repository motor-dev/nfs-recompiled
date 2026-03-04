#include "softtria.h"
#include <lib/thread.h>

namespace softtria
{

/* align: skip 0x8b 0xc0 */
void sub_a768dc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a768dc  b87006a800             -mov eax, 0xa80670
    cpu.eax = 11011696 /*0xa80670*/;
    // 00a768e1  e9ea000000             -jmp 0xa769d0
    return sub_a769d0(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a768e8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a768e8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a768eb  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a768ee  059006a800             +add eax, 0xa80690
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11011728 /*0xa80690*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a768f3  e974000000             -jmp 0xa7696c
    return sub_a7696c(app, cpu);
}

/* align: skip  */
void sub_a768f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a768f8  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a768fb  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a768fe  059006a800             +add eax, 0xa80690
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11011728 /*0xa80690*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a76903  e9c8000000             -jmp 0xa769d0
    return sub_a769d0(app, cpu);
}

/* align: skip  */
void sub_a76908(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76908  e947fcffff             -jmp 0xa76554
    return sub_a76554(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a76910(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76910  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76911  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76913  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a76916  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00a76919  059006a800             -add eax, 0xa80690
    (cpu.eax) += x86::reg32(x86::sreg32(11011728 /*0xa80690*/));
    // 00a7691e  e89dffffff             -call 0xa768c0
    cpu.esp -= 4;
    sub_a768c0(app, cpu);
    if (cpu.terminate) return;
    // 00a76923  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a76925  e882fdffff             -call 0xa766ac
    cpu.esp -= 4;
    sub_a766ac(app, cpu);
    if (cpu.terminate) return;
    // 00a7692a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7692b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7692c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7692c  b89007a800             -mov eax, 0xa80790
    cpu.eax = 11011984 /*0xa80790*/;
    // 00a76931  eb39                   -jmp 0xa7696c
    return sub_a7696c(app, cpu);
}

/* align: skip 0x90 */
void sub_a76934(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76934  b89007a800             -mov eax, 0xa80790
    cpu.eax = 11011984 /*0xa80790*/;
    // 00a76939  e992000000             -jmp 0xa769d0
    return sub_a769d0(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a76940(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76940  b88006a800             -mov eax, 0xa80680
    cpu.eax = 11011712 /*0xa80680*/;
    // 00a76945  eb25                   -jmp 0xa7696c
    return sub_a7696c(app, cpu);
}

/* align: skip 0x90 */
void sub_a76948(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76948  b88006a800             -mov eax, 0xa80680
    cpu.eax = 11011712 /*0xa80680*/;
    // 00a7694d  e97e000000             -jmp 0xa769d0
    return sub_a769d0(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void sub_a76954(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76954  b8b00da800             -mov eax, 0xa80db0
    cpu.eax = 11013552 /*0xa80db0*/;
    // 00a76959  eb11                   -jmp 0xa7696c
    return sub_a7696c(app, cpu);
}

/* align: skip 0x90 */
void sub_a7695c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7695c  b8b00da800             -mov eax, 0xa80db0
    cpu.eax = 11013552 /*0xa80db0*/;
    // 00a76961  eb6d                   -jmp 0xa769d0
    return sub_a769d0(app, cpu);
}

/* align: skip 0x90 */
void sub_a76964(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76964  b8c00da800             -mov eax, 0xa80dc0
    cpu.eax = 11013568 /*0xa80dc0*/;
    // 00a76969  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a7696c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7696d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7696e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7696f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76970  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76971  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76973  2eff15ccbda700         -call dword ptr cs:[0xa7bdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993100) /* 0xa7bdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7697a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a7697d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7697f  39d0                   +cmp eax, edx
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
    // 00a76981  743b                   -je 0xa769be
    if (cpu.flags.zf)
    {
        goto L_0x00a769be;
    }
    // 00a76983  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a76987  7528                   -jne 0xa769b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a769b1;
    }
    // 00a76989  b8a00da800             -mov eax, 0xa80da0
    cpu.eax = 11013536 /*0xa80da0*/;
    // 00a7698e  e8d9ffffff             -call 0xa7696c
    cpu.esp -= 4;
    sub_a7696c(app, cpu);
    if (cpu.terminate) return;
    // 00a76993  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a76997  750e                   -jne 0xa769a7
    if (!cpu.flags.zf)
    {
        goto L_0x00a769a7;
    }
    // 00a76999  e8f6fdffff             -call 0xa76794
    cpu.esp -= 4;
    sub_a76794(app, cpu);
    if (cpu.terminate) return;
    // 00a7699e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00a769a5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a769a7:
    // 00a769a7  b8a00da800             -mov eax, 0xa80da0
    cpu.eax = 11013536 /*0xa80da0*/;
    // 00a769ac  e81f000000             -call 0xa769d0
    cpu.esp -= 4;
    sub_a769d0(app, cpu);
    if (cpu.terminate) return;
L_0x00a769b1:
    // 00a769b1  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a769b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a769b4  2eff15a0bda700         -call dword ptr cs:[0xa7bda0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993056) /* 0xa7bda0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a769bb  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a769be:
    // 00a769be  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a769c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7696c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a7696c;
    // 00a76964  b8c00da800             -mov eax, 0xa80dc0
    cpu.eax = 11013568 /*0xa80dc0*/;
    // 00a76969  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a7696c:
    // 00a7696c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7696d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7696e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7696f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76970  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76971  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76973  2eff15ccbda700         -call dword ptr cs:[0xa7bdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993100) /* 0xa7bdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7697a  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a7697d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7697f  39d0                   +cmp eax, edx
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
    // 00a76981  743b                   -je 0xa769be
    if (cpu.flags.zf)
    {
        goto L_0x00a769be;
    }
    // 00a76983  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a76987  7528                   -jne 0xa769b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a769b1;
    }
    // 00a76989  b8a00da800             -mov eax, 0xa80da0
    cpu.eax = 11013536 /*0xa80da0*/;
    // 00a7698e  e8d9ffffff             -call 0xa7696c
    cpu.esp -= 4;
    sub_a7696c(app, cpu);
    if (cpu.terminate) return;
    // 00a76993  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 00a76997  750e                   -jne 0xa769a7
    if (!cpu.flags.zf)
    {
        goto L_0x00a769a7;
    }
    // 00a76999  e8f6fdffff             -call 0xa76794
    cpu.esp -= 4;
    sub_a76794(app, cpu);
    if (cpu.terminate) return;
    // 00a7699e  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 00a769a5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a769a7:
    // 00a769a7  b8a00da800             -mov eax, 0xa80da0
    cpu.eax = 11013536 /*0xa80da0*/;
    // 00a769ac  e81f000000             -call 0xa769d0
    cpu.esp -= 4;
    sub_a769d0(app, cpu);
    if (cpu.terminate) return;
L_0x00a769b1:
    // 00a769b1  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a769b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a769b4  2eff15a0bda700         -call dword ptr cs:[0xa7bda0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993056) /* 0xa7bda0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a769bb  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x00a769be:
    // 00a769be  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 00a769c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a769c8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a769c8  b8c00da800             -mov eax, 0xa80dc0
    cpu.eax = 11013568 /*0xa80dc0*/;
    // 00a769cd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 00a769d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a769d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a769d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a769d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a769d4  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a769d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a769d9  7617                   -jbe 0xa769f2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a769f2;
    }
    // 00a769db  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a769de  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a769e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a769e3  750d                   -jne 0xa769f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a769f2;
    }
    // 00a769e5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a769e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a769e8  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a769eb  2eff150cbea700         -call dword ptr cs:[0xa7be0c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993164) /* 0xa7be0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a769f2:
    // 00a769f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a769d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a769d0;
    // 00a769c8  b8c00da800             -mov eax, 0xa80dc0
    cpu.eax = 11013568 /*0xa80dc0*/;
    // 00a769cd  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x00a769d0:
    // 00a769d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a769d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a769d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a769d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a769d4  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00a769d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a769d9  7617                   -jbe 0xa769f2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a769f2;
    }
    // 00a769db  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 00a769de  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00a769e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a769e3  750d                   -jne 0xa769f2
    if (!cpu.flags.zf)
    {
        goto L_0x00a769f2;
    }
    // 00a769e5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00a769e7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a769e8  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a769eb  2eff150cbea700         -call dword ptr cs:[0xa7be0c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993164) /* 0xa7be0c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a769f2:
    // 00a769f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a769f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a769f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a769f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a769f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a769fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a769fb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a769fc  2eff15e4bda700         -call dword ptr cs:[0xa7bde4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993124) /* 0xa7bde4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76a03  8b1590d2a700           -mov edx, dword ptr [0xa7d290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a76a09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76a0a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a76a0c  2eff1548bea700         -call dword ptr cs:[0xa7be48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993224) /* 0xa7be48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76a13  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76a15  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76a17  7507                   -jne 0xa76a20
    if (!cpu.flags.zf)
    {
        goto L_0x00a76a20;
    }
    // 00a76a19  e822170000             -call 0xa78140
    cpu.esp -= 4;
    sub_a78140(app, cpu);
    if (cpu.terminate) return;
    // 00a76a1e  eb0b                   -jmp 0xa76a2b
    goto L_0x00a76a2b;
L_0x00a76a20:
    // 00a76a20  80785300               +cmp byte ptr [eax + 0x53], 0
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
    // 00a76a24  7407                   -je 0xa76a2d
    if (cpu.flags.zf)
    {
        goto L_0x00a76a2d;
    }
    // 00a76a26  e851170000             -call 0xa7817c
    cpu.esp -= 4;
    sub_a7817c(app, cpu);
    if (cpu.terminate) return;
L_0x00a76a2b:
    // 00a76a2b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a76a2d:
    // 00a76a2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76a2e  2eff1534bea700         -call dword ptr cs:[0xa7be34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993204) /* 0xa7be34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76a35  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a76a37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76a38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76a39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76a3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76a3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a76a3c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76a3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76a3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76a3e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76a40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76a42  7526                   -jne 0xa76a6a
    if (!cpu.flags.zf)
    {
        goto L_0x00a76a6a;
    }
    // 00a76a44  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a76a49  8b15dcd5a700           -mov edx, dword ptr [0xa7d5dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a76a4f  e8cc160000             -call 0xa78120
    cpu.esp -= 4;
    sub_a78120(app, cpu);
    if (cpu.terminate) return;
    // 00a76a54  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76a56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76a58  7410                   -je 0xa76a6a
    if (cpu.flags.zf)
    {
        goto L_0x00a76a6a;
    }
    // 00a76a5a  8b1ddcd5a700           -mov ebx, dword ptr [0xa7d5dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a76a60  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a76a64  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x00a76a6a:
    // 00a76a6a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a76a6c  e81f190000             -call 0xa78390
    cpu.esp -= 4;
    sub_a78390(app, cpu);
    if (cpu.terminate) return;
    // 00a76a71  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a76a73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76a74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76a75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a76a78(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76a78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76a79  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76a7a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76a7b  8b1d90d2a700           -mov ebx, dword ptr [0xa7d290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a76a81  83fbff                 +cmp ebx, -1
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
    // 00a76a84  753b                   -jne 0xa76ac1
    if (!cpu.flags.zf)
    {
        goto L_0x00a76ac1;
    }
    // 00a76a86  2eff1540bea700         -call dword ptr cs:[0xa7be40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993216) /* 0xa7be40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76a8d  668b1571d3a700         -mov dx, word ptr [0xa7d371]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(10998641) /* 0xa7d371 */);
    // 00a76a94  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76a96  6681fa0080             +cmp dx, 0x8000
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
    // 00a76a9b  7224                   -jb 0xa76ac1
    if (cpu.flags.cf)
    {
        goto L_0x00a76ac1;
    }
    // 00a76a9d  803d6fd3a70004         +cmp byte ptr [0xa7d36f], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10998639) /* 0xa7d36f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a76aa4  731b                   -jae 0xa76ac1
    if (!cpu.flags.cf)
    {
        goto L_0x00a76ac1;
    }
L_0x00a76aa6:
    // 00a76aa6  83fbff                 +cmp ebx, -1
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
    // 00a76aa9  7416                   -je 0xa76ac1
    if (cpu.flags.zf)
    {
        goto L_0x00a76ac1;
    }
    // 00a76aab  83fb02                 +cmp ebx, 2
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
    // 00a76aae  7711                   -ja 0xa76ac1
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a76ac1;
    }
    // 00a76ab0  891d90d2a700           -mov dword ptr [0xa7d290], ebx
    app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */) = cpu.ebx;
    // 00a76ab6  2eff1540bea700         -call dword ptr cs:[0xa7be40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993216) /* 0xa7be40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76abd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76abf  ebe5                   -jmp 0xa76aa6
    goto L_0x00a76aa6;
L_0x00a76ac1:
    // 00a76ac1  83fbff                 +cmp ebx, -1
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
    // 00a76ac4  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a76ac7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a76acc  891d90d2a700           -mov dword ptr [0xa7d290], ebx
    app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */) = cpu.ebx;
    // 00a76ad2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ad3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ad4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ad5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a76ad8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76ad8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76ad9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76ada  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76adb  833d90d2a700ff         +cmp dword ptr [0xa7d290], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a76ae2  7506                   -jne 0xa76aea
    if (!cpu.flags.zf)
    {
        goto L_0x00a76aea;
    }
    // 00a76ae4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a76ae6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ae7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ae8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ae9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76aea:
    // 00a76aea  e84dffffff             -call 0xa76a3c
    cpu.esp -= 4;
    sub_a76a3c(app, cpu);
    if (cpu.terminate) return;
    // 00a76aef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76af1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76af3  7432                   -je 0xa76b27
    if (cpu.flags.zf)
    {
        goto L_0x00a76b27;
    }
    // 00a76af5  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a76af7  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a76afd  e84e170000             -call 0xa78250
    cpu.esp -= 4;
    sub_a78250(app, cpu);
    if (cpu.terminate) return;
    // 00a76b02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76b04  750d                   -jne 0xa76b13
    if (!cpu.flags.zf)
    {
        goto L_0x00a76b13;
    }
    // 00a76b06  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a76b08  e863d2ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a76b0d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a76b0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76b13:
    // 00a76b13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76b14  8b1d90d2a700           -mov ebx, dword ptr [0xa7d290]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a76b1a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76b1b  2eff154cbea700         -call dword ptr cs:[0xa7be4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993228) /* 0xa7be4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76b22  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a76b27:
    // 00a76b27  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b28  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a76b2c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76b2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76b2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76b2e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76b2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76b30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76b31  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76b33  8b1590d2a700           -mov edx, dword ptr [0xa7d290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a76b39  83faff                 +cmp edx, -1
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
    // 00a76b3c  743d                   -je 0xa76b7b
    if (cpu.flags.zf)
    {
        goto L_0x00a76b7b;
    }
    // 00a76b3e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76b3f  2eff1548bea700         -call dword ptr cs:[0xa7be48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993224) /* 0xa7be48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76b46  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76b48  7431                   -je 0xa76b7b
    if (cpu.flags.zf)
    {
        goto L_0x00a76b7b;
    }
    // 00a76b4a  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 00a76b50  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 00a76b56  e859170000             -call 0xa782b4
    cpu.esp -= 4;
    sub_a782b4(app, cpu);
    if (cpu.terminate) return;
    // 00a76b5b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a76b5d  8b3d90d2a700           -mov edi, dword ptr [0xa7d290]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a76b63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76b64  2eff154cbea700         -call dword ptr cs:[0xa7be4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993228) /* 0xa7be4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76b6b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a76b6d  740c                   -je 0xa76b7b
    if (cpu.flags.zf)
    {
        goto L_0x00a76b7b;
    }
    // 00a76b6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a76b71  7408                   -je 0xa76b7b
    if (cpu.flags.zf)
    {
        goto L_0x00a76b7b;
    }
    // 00a76b73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76b74  2eff1588bda700         -call dword ptr cs:[0xa7bd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993032) /* 0xa7bd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a76b7b:
    // 00a76b7b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b7c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76b80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a76b84(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76b84  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a76b89  e89effffff             -call 0xa76b2c
    cpu.esp -= 4;
    sub_a76b2c(app, cpu);
    if (cpu.terminate) return;
    // 00a76b8e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00a76b90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76b91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76b92  8b1590d2a700           -mov edx, dword ptr [0xa7d290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a76b98  83faff                 +cmp edx, -1
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
    // 00a76b9b  7412                   -je 0xa76baf
    if (cpu.flags.zf)
    {
        goto L_0x00a76baf;
    }
    // 00a76b9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76b9e  2eff1544bea700         -call dword ptr cs:[0xa7be44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993220) /* 0xa7be44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76ba5  c70590d2a700ffffffff   -mov dword ptr [0xa7d290], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */) = 4294967295 /*0xffffffff*/;
L_0x00a76baf:
    // 00a76baf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76bb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76bb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a76b90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a76b90;
    // 00a76b84  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a76b89  e89effffff             -call 0xa76b2c
    cpu.esp -= 4;
    sub_a76b2c(app, cpu);
    if (cpu.terminate) return;
    // 00a76b8e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x00a76b90:
    // 00a76b90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76b91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76b92  8b1590d2a700           -mov edx, dword ptr [0xa7d290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a76b98  83faff                 +cmp edx, -1
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
    // 00a76b9b  7412                   -je 0xa76baf
    if (cpu.flags.zf)
    {
        goto L_0x00a76baf;
    }
    // 00a76b9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76b9e  2eff1544bea700         -call dword ptr cs:[0xa7be44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993220) /* 0xa7be44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76ba5  c70590d2a700ffffffff   -mov dword ptr [0xa7d290], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */) = 4294967295 /*0xffffffff*/;
L_0x00a76baf:
    // 00a76baf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76bb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76bb1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a76bb4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76bb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76bb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76bb6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76bb7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76bb8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76bb9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76bba  bae868a700             -mov edx, 0xa768e8
    cpu.edx = 10971368 /*0xa768e8*/;
    // 00a76bbf  bbf868a700             -mov ebx, 0xa768f8
    cpu.ebx = 10971384 /*0xa768f8*/;
    // 00a76bc4  b90869a700             -mov ecx, 0xa76908
    cpu.ecx = 10971400 /*0xa76908*/;
    // 00a76bc9  be1069a700             -mov esi, 0xa76910
    cpu.esi = 10971408 /*0xa76910*/;
    // 00a76bce  bfd068a700             -mov edi, 0xa768d0
    cpu.edi = 10971344 /*0xa768d0*/;
    // 00a76bd3  bddc68a700             -mov ebp, 0xa768dc
    cpu.ebp = 10971356 /*0xa768dc*/;
    // 00a76bd8  b85469a700             -mov eax, 0xa76954
    cpu.eax = 10971476 /*0xa76954*/;
    // 00a76bdd  891598d2a700           -mov dword ptr [0xa7d298], edx
    app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */) = cpu.edx;
    // 00a76be3  891d9cd2a700           -mov dword ptr [0xa7d29c], ebx
    app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */) = cpu.ebx;
    // 00a76be9  890da0d2a700           -mov dword ptr [0xa7d2a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(10998432) /* 0xa7d2a0 */) = cpu.ecx;
    // 00a76bef  8935a4d2a700           -mov dword ptr [0xa7d2a4], esi
    app->getMemory<x86::reg32>(x86::reg32(10998436) /* 0xa7d2a4 */) = cpu.esi;
    // 00a76bf5  893da8d2a700           -mov dword ptr [0xa7d2a8], edi
    app->getMemory<x86::reg32>(x86::reg32(10998440) /* 0xa7d2a8 */) = cpu.edi;
    // 00a76bfb  892dacd2a700           -mov dword ptr [0xa7d2ac], ebp
    app->getMemory<x86::reg32>(x86::reg32(10998444) /* 0xa7d2ac */) = cpu.ebp;
    // 00a76c01  a3c0d2a700             -mov dword ptr [0xa7d2c0], eax
    app->getMemory<x86::reg32>(x86::reg32(10998464) /* 0xa7d2c0 */) = cpu.eax;
    // 00a76c06  ba5c69a700             -mov edx, 0xa7695c
    cpu.edx = 10971484 /*0xa7695c*/;
    // 00a76c0b  bb6c69a700             -mov ebx, 0xa7696c
    cpu.ebx = 10971500 /*0xa7696c*/;
    // 00a76c10  b9d069a700             -mov ecx, 0xa769d0
    cpu.ecx = 10971600 /*0xa769d0*/;
    // 00a76c15  bec068a700             -mov esi, 0xa768c0
    cpu.esi = 10971328 /*0xa768c0*/;
    // 00a76c1a  bf2c69a700             -mov edi, 0xa7692c
    cpu.edi = 10971436 /*0xa7692c*/;
    // 00a76c1f  bd4069a700             -mov ebp, 0xa76940
    cpu.ebp = 10971456 /*0xa76940*/;
    // 00a76c24  b83469a700             -mov eax, 0xa76934
    cpu.eax = 10971444 /*0xa76934*/;
    // 00a76c29  8915c4d2a700           -mov dword ptr [0xa7d2c4], edx
    app->getMemory<x86::reg32>(x86::reg32(10998468) /* 0xa7d2c4 */) = cpu.edx;
    // 00a76c2f  891d94d3a700           -mov dword ptr [0xa7d394], ebx
    app->getMemory<x86::reg32>(x86::reg32(10998676) /* 0xa7d394 */) = cpu.ebx;
    // 00a76c35  890d98d3a700           -mov dword ptr [0xa7d398], ecx
    app->getMemory<x86::reg32>(x86::reg32(10998680) /* 0xa7d398 */) = cpu.ecx;
    // 00a76c3b  89359cd3a700           -mov dword ptr [0xa7d39c], esi
    app->getMemory<x86::reg32>(x86::reg32(10998684) /* 0xa7d39c */) = cpu.esi;
    // 00a76c41  893db0d2a700           -mov dword ptr [0xa7d2b0], edi
    app->getMemory<x86::reg32>(x86::reg32(10998448) /* 0xa7d2b0 */) = cpu.edi;
    // 00a76c47  892db4d2a700           -mov dword ptr [0xa7d2b4], ebp
    app->getMemory<x86::reg32>(x86::reg32(10998452) /* 0xa7d2b4 */) = cpu.ebp;
    // 00a76c4d  a3b8d2a700             -mov dword ptr [0xa7d2b8], eax
    app->getMemory<x86::reg32>(x86::reg32(10998456) /* 0xa7d2b8 */) = cpu.eax;
    // 00a76c52  ba4869a700             -mov edx, 0xa76948
    cpu.edx = 10971464 /*0xa76948*/;
    // 00a76c57  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a76c5c  b96469a700             -mov ecx, 0xa76964
    cpu.ecx = 10971492 /*0xa76964*/;
    // 00a76c61  bec869a700             -mov esi, 0xa769c8
    cpu.esi = 10971592 /*0xa769c8*/;
    // 00a76c66  bf846ba700             -mov edi, 0xa76b84
    cpu.edi = 10972036 /*0xa76b84*/;
    // 00a76c6b  8915bcd2a700           -mov dword ptr [0xa7d2bc], edx
    app->getMemory<x86::reg32>(x86::reg32(10998460) /* 0xa7d2bc */) = cpu.edx;
    // 00a76c71  e81efbffff             -call 0xa76794
    cpu.esp -= 4;
    sub_a76794(app, cpu);
    if (cpu.terminate) return;
    // 00a76c76  8b151c00a800           -mov edx, dword ptr [0xa8001c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010076) /* 0xa8001c */);
    // 00a76c7c  a3a00da800             -mov dword ptr [0xa80da0], eax
    app->getMemory<x86::reg32>(x86::reg32(11013536) /* 0xa80da0 */) = cpu.eax;
    // 00a76c81  891da40da800           -mov dword ptr [0xa80da4], ebx
    app->getMemory<x86::reg32>(x86::reg32(11013540) /* 0xa80da4 */) = cpu.ebx;
    // 00a76c87  890dc8d2a700           -mov dword ptr [0xa7d2c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(10998472) /* 0xa7d2c8 */) = cpu.ecx;
    // 00a76c8d  8935ccd2a700           -mov dword ptr [0xa7d2cc], esi
    app->getMemory<x86::reg32>(x86::reg32(10998476) /* 0xa7d2cc */) = cpu.esi;
    // 00a76c93  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 00a76c99  893dd0d2a700           -mov dword ptr [0xa7d2d0], edi
    app->getMemory<x86::reg32>(x86::reg32(10998480) /* 0xa7d2d0 */) = cpu.edi;
    // 00a76c9f  e8ac150000             -call 0xa78250
    cpu.esp -= 4;
    sub_a78250(app, cpu);
    if (cpu.terminate) return;
    // 00a76ca4  8b2d1c00a800           -mov ebp, dword ptr [0xa8001c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(11010076) /* 0xa8001c */);
    // 00a76caa  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76cab  a190d2a700             -mov eax, dword ptr [0xa7d290]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a76cb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a76cb1  2eff154cbea700         -call dword ptr cs:[0xa7be4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993228) /* 0xa7be4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76cb8  c70594d2a700f869a700   -mov dword ptr [0xa7d294], 0xa769f8
    app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */) = 10971640 /*0xa769f8*/;
    // 00a76cc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76cc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76cc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76cc5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76cc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76cc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76cc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a76ccc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76ccc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76ccd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76cce  b87006a800             -mov eax, 0xa80670
    cpu.eax = 11011696 /*0xa80670*/;
    // 00a76cd3  ba9006a800             -mov edx, 0xa80690
    cpu.edx = 11011728 /*0xa80690*/;
    // 00a76cd8  ff159cd3a700           -call dword ptr [0xa7d39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998684) /* 0xa7d39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76cde  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x00a76ce4:
    // 00a76ce4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a76ce6  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a76ce9  ff159cd3a700           -call dword ptr [0xa7d39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998684) /* 0xa7d39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76cef  39da                   +cmp edx, ebx
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
    // 00a76cf1  75f1                   -jne 0xa76ce4
    if (!cpu.flags.zf)
    {
        goto L_0x00a76ce4;
    }
    // 00a76cf3  b8c00da800             -mov eax, 0xa80dc0
    cpu.eax = 11013568 /*0xa80dc0*/;
    // 00a76cf8  ff159cd3a700           -call dword ptr [0xa7d39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998684) /* 0xa7d39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76cfe  e865fbffff             -call 0xa76868
    cpu.esp -= 4;
    sub_a76868(app, cpu);
    if (cpu.terminate) return;
    // 00a76d03  e8b8160000             -call 0xa783c0
    cpu.esp -= 4;
    sub_a783c0(app, cpu);
    if (cpu.terminate) return;
    // 00a76d08  e813090000             -call 0xa77620
    cpu.esp -= 4;
    sub_a77620(app, cpu);
    if (cpu.terminate) return;
    // 00a76d0d  b89007a800             -mov eax, 0xa80790
    cpu.eax = 11011984 /*0xa80790*/;
    // 00a76d12  ff159cd3a700           -call dword ptr [0xa7d39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998684) /* 0xa7d39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76d18  b88006a800             -mov eax, 0xa80680
    cpu.eax = 11011712 /*0xa80680*/;
    // 00a76d1d  ff159cd3a700           -call dword ptr [0xa7d39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998684) /* 0xa7d39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76d23  b8b00da800             -mov eax, 0xa80db0
    cpu.eax = 11013552 /*0xa80db0*/;
    // 00a76d28  ff159cd3a700           -call dword ptr [0xa7d39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998684) /* 0xa7d39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76d2e  b8a00da800             -mov eax, 0xa80da0
    cpu.eax = 11013536 /*0xa80da0*/;
    // 00a76d33  ff159cd3a700           -call dword ptr [0xa7d39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998684) /* 0xa7d39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76d39  e8fafaffff             -call 0xa76838
    cpu.esp -= 4;
    sub_a76838(app, cpu);
    if (cpu.terminate) return;
    // 00a76d3e  e84dfeffff             -call 0xa76b90
    cpu.esp -= 4;
    sub_a76b90(app, cpu);
    if (cpu.terminate) return;
    // 00a76d43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76d44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76d45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a76d50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76d50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76d51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76d52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76d53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76d54  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a76d56  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a76d58  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a76d5a  2eff1504bea700         -call dword ptr cs:[0xa7be04]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993156) /* 0xa7be04 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76d61  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 00a76d64  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a76d69  663d0080               +cmp ax, 0x8000
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
    // 00a76d6d  730f                   -jae 0xa76d7e
    if (!cpu.flags.cf)
    {
        goto L_0x00a76d7e;
    }
    // 00a76d6f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76d70  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76d71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76d72  2eff15ecbda700         -call dword ptr cs:[0xa7bdec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993132) /* 0xa7bdec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76d79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76d7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76d7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76d7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76d7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76d7e:
    // 00a76d7e  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 00a76d83  e8f8ceffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a76d88  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76d8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76d8c  7452                   -je 0xa76de0
    if (cpu.flags.zf)
    {
        goto L_0x00a76de0;
    }
    // 00a76d8e  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 00a76d93  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a76d94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a76d95  2eff15e8bda700         -call dword ptr cs:[0xa7bde8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993128) /* 0xa7bde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76d9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76d9e  750e                   -jne 0xa76dae
    if (!cpu.flags.zf)
    {
        goto L_0x00a76dae;
    }
    // 00a76da0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a76da2  e8c9cfffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a76da7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a76da9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76daa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76dab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76dac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76dad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76dae:
    // 00a76dae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76daf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76db0  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a76db2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76db3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a76db5  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a76db7  2eff1518bea700         -call dword ptr cs:[0xa7be18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993176) /* 0xa7be18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76dbe  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a76dc0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a76dc2  e8a9cfffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a76dc7  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a76dc9  7507                   -jne 0xa76dd2
    if (!cpu.flags.zf)
    {
        goto L_0x00a76dd2;
    }
    // 00a76dcb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a76dcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76dce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76dcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76dd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76dd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a76dd2:
    // 00a76dd2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a76dd4  66c7447efe0000         -mov word ptr [esi + edi*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.edi * 2) = 0 /*0x0*/;
    // 00a76ddb  e8f0150000             -call 0xa783d0
    cpu.esp -= 4;
    sub_a783d0(app, cpu);
    if (cpu.terminate) return;
L_0x00a76de0:
    // 00a76de0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76de1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76de2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76de3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76de4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a76df0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76df0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76df1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76df2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76df3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76df4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a76df6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a76df8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a76df9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a76dfb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a76dfd  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a76dff  49                     -dec ecx
    (cpu.ecx)--;
    // 00a76e00  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a76e02  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a76e04  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a76e06  49                     -dec ecx
    (cpu.ecx)--;
    // 00a76e07  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a76e08  41                     -inc ecx
    (cpu.ecx)++;
    // 00a76e09  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a76e0b  e870ceffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a76e10  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76e12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76e14  7418                   -je 0xa76e2e
    if (cpu.flags.zf)
    {
        goto L_0x00a76e2e;
    }
    // 00a76e16  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a76e18  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a76e19  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a76e1b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a76e1d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76e1e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a76e20  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a76e23  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a76e25  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a76e27  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a76e2a  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a76e2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76e2d  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x00a76e2e:
    // 00a76e2e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a76e30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76e31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76e32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76e33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76e34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a76e40(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76e41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76e42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76e43  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76e45  e886150000             -call 0xa783d0
    cpu.esp -= 4;
    sub_a783d0(app, cpu);
    if (cpu.terminate) return;
    // 00a76e4a  40                     -inc eax
    (cpu.eax)++;
    // 00a76e4b  8d1c4500000000         -lea ebx, [eax*2]
    cpu.ebx = x86::reg32(cpu.eax * 2);
    // 00a76e52  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a76e54  e827ceffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a76e59  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a76e5b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76e5d  7405                   -je 0xa76e64
    if (cpu.flags.zf)
    {
        goto L_0x00a76e64;
    }
    // 00a76e5f  e88c150000             -call 0xa783f0
    cpu.esp -= 4;
    sub_a783f0(app, cpu);
    if (cpu.terminate) return;
L_0x00a76e64:
    // 00a76e64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a76e66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76e67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76e68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76e69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a76e70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76e70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76e71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76e72  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76e73  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a76e76  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a76e78  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a76e7a  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 00a76e7c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a76e80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a76e81  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a76e85  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a76e86  2eff1560bea700         -call dword ptr cs:[0xa7be60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993248) /* 0xa7be60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76e8d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a76e90  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 00a76e94  668b0d71d3a700         -mov cx, word ptr [0xa7d371]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(10998641) /* 0xa7d371 */);
    // 00a76e9b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a76e9f  6681f90080             +cmp cx, 0x8000
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
    // 00a76ea4  7307                   -jae 0xa76ead
    if (!cpu.flags.cf)
    {
        goto L_0x00a76ead;
    }
    // 00a76ea6  0500300000             +add eax, 0x3000
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
    // 00a76eab  eb17                   -jmp 0xa76ec4
    goto L_0x00a76ec4;
L_0x00a76ead:
    // 00a76ead  7210                   -jb 0xa76ebf
    if (cpu.flags.cf)
    {
        goto L_0x00a76ebf;
    }
    // 00a76eaf  803d6fd3a70004         +cmp byte ptr [0xa7d36f], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10998639) /* 0xa7d36f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a76eb6  7307                   -jae 0xa76ebf
    if (!cpu.flags.cf)
    {
        goto L_0x00a76ebf;
    }
    // 00a76eb8  0500200100             +add eax, 0x12000
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
    // 00a76ebd  eb05                   -jmp 0xa76ec4
    goto L_0x00a76ec4;
L_0x00a76ebf:
    // 00a76ebf  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x00a76ec4:
    // 00a76ec4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a76ec6  7402                   -je 0xa76eca
    if (cpu.flags.zf)
    {
        goto L_0x00a76eca;
    }
    // 00a76ec8  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00a76eca:
    // 00a76eca  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a76ecc  7402                   -je 0xa76ed0
    if (cpu.flags.zf)
    {
        goto L_0x00a76ed0;
    }
    // 00a76ece  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x00a76ed0:
    // 00a76ed0  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00a76ed3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ed4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ed5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76ed6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a76ee0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76ee0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76ee2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a76ee3  68a8dda700             -push 0xa7dda8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11001256 /*0xa7dda8*/;
    cpu.esp -= 4;
    // 00a76ee8  2eff1510bea700         -call dword ptr cs:[0xa7be10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993168) /* 0xa7be10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76eef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a76ef1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76ef3  7417                   -je 0xa76f0c
    if (cpu.flags.zf)
    {
        goto L_0x00a76f0c;
    }
    // 00a76ef5  68b4dda700             -push 0xa7ddb4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11001268 /*0xa7ddb4*/;
    cpu.esp -= 4;
    // 00a76efa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a76efb  2eff15f8bda700         -call dword ptr cs:[0xa7bdf8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993144) /* 0xa7bdf8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76f02  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76f04  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76f06  7404                   -je 0xa76f0c
    if (cpu.flags.zf)
    {
        goto L_0x00a76f0c;
    }
    // 00a76f08  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a76f0a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a76f0c:
    // 00a76f0c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a76f0e  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 00a76f11  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a76f16  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76f17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76f18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76f19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a76f1c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76f1c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a76f1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a76f1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76f1f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a76f21  8a08                   -mov cl, byte ptr [eax]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a76f23  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a76f25  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a76f27  7408                   -je 0xa76f31
    if (cpu.flags.zf)
    {
        goto L_0x00a76f31;
    }
L_0x00a76f29:
    // 00a76f29  8a6801                 -mov ch, byte ptr [eax + 1]
    cpu.ch = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a76f2c  40                     -inc eax
    (cpu.eax)++;
    // 00a76f2d  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 00a76f2f  75f8                   -jne 0xa76f29
    if (!cpu.flags.zf)
    {
        goto L_0x00a76f29;
    }
L_0x00a76f31:
    // 00a76f31  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x00a76f34:
    // 00a76f34  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a76f36  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 00a76f38  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00a76f3a  7412                   -je 0xa76f4e
    if (cpu.flags.zf)
    {
        goto L_0x00a76f4e;
    }
    // 00a76f3c  80f930                 +cmp cl, 0x30
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
    // 00a76f3f  7508                   -jne 0xa76f49
    if (!cpu.flags.zf)
    {
        goto L_0x00a76f49;
    }
    // 00a76f41  807a0178               +cmp byte ptr [edx + 1], 0x78
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a76f45  7502                   -jne 0xa76f49
    if (!cpu.flags.zf)
    {
        goto L_0x00a76f49;
    }
    // 00a76f47  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x00a76f49:
    // 00a76f49  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a76f4a  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a76f4b  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a76f4c  ebe6                   -jmp 0xa76f34
    goto L_0x00a76f34;
L_0x00a76f4e:
    // 00a76f4e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a76f50  741c                   -je 0xa76f6e
    if (cpu.flags.zf)
    {
        goto L_0x00a76f6e;
    }
    // 00a76f52  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a76f54  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00a76f56  7416                   -je 0xa76f6e
    if (cpu.flags.zf)
    {
        goto L_0x00a76f6e;
    }
L_0x00a76f58:
    // 00a76f58  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a76f5a  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00a76f5d  4b                     -dec ebx
    (cpu.ebx)--;
    // 00a76f5e  8a92a8d3a700           -mov dl, byte ptr [edx + 0xa7d3a8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10998696) /* 0xa7d3a8 */);
    // 00a76f64  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 00a76f67  885301                 -mov byte ptr [ebx + 1], dl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00a76f6a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76f6c  75ea                   -jne 0xa76f58
    if (!cpu.flags.zf)
    {
        goto L_0x00a76f58;
    }
L_0x00a76f6e:
    // 00a76f6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76f6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76f70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a76f71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a76f74(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a76f74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a76f75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a76f76  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a76f7c  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00a76f83  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a76f85  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a76f88  e853ffffff             -call 0xa76ee0
    cpu.esp -= 4;
    sub_a76ee0(app, cpu);
    if (cpu.terminate) return;
    // 00a76f8d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a76f8f  750a                   -jne 0xa76f9b
    if (!cpu.flags.zf)
    {
        goto L_0x00a76f9b;
    }
    // 00a76f91  e82e150000             -call 0xa784c4
    cpu.esp -= 4;
    sub_a784c4(app, cpu);
    if (cpu.terminate) return;
    // 00a76f96  83f8ff                 +cmp eax, -1
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
    // 00a76f99  7507                   -jne 0xa76fa2
    if (!cpu.flags.zf)
    {
        goto L_0x00a76fa2;
    }
L_0x00a76f9b:
    // 00a76f9b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a76f9d  e98c010000             -jmp 0xa7712e
    goto L_0x00a7712e;
L_0x00a76fa2:
    // 00a76fa2  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a76fa4  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00a76fa7  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a76fa9  3d900000c0             +cmp eax, 0xc0000090
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
    // 00a76fae  724d                   -jb 0xa76ffd
    if (cpu.flags.cf)
    {
        goto L_0x00a76ffd;
    }
    // 00a76fb0  0f86c2000000           -jbe 0xa77078
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a77078;
    }
    // 00a76fb6  3d930000c0             +cmp eax, 0xc0000093
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
    // 00a76fbb  7233                   -jb 0xa76ff0
    if (cpu.flags.cf)
    {
        goto L_0x00a76ff0;
    }
    // 00a76fbd  0f86ab000000           -jbe 0xa7706e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7706e;
    }
    // 00a76fc3  3d960000c0             +cmp eax, 0xc0000096
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
    // 00a76fc8  7216                   -jb 0xa76fe0
    if (cpu.flags.cf)
    {
        goto L_0x00a76fe0;
    }
    // 00a76fca  0f86ec000000           -jbe 0xa770bc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a770bc;
    }
    // 00a76fd0  3dfd0000c0             +cmp eax, 0xc00000fd
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
    // 00a76fd5  0f84f6000000           -je 0xa770d1
    if (cpu.flags.zf)
    {
        goto L_0x00a770d1;
    }
    // 00a76fdb  e9f8000000             -jmp 0xa770d8
    goto L_0x00a770d8;
L_0x00a76fe0:
    // 00a76fe0  3d940000c0             +cmp eax, 0xc0000094
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
    // 00a76fe5  0f84df000000           -je 0xa770ca
    if (cpu.flags.zf)
    {
        goto L_0x00a770ca;
    }
    // 00a76feb  e9e8000000             -jmp 0xa770d8
    goto L_0x00a770d8;
L_0x00a76ff0:
    // 00a76ff0  3d910000c0             +cmp eax, 0xc0000091
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
    // 00a76ff5  0f8669000000           -jbe 0xa77064
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a77064;
    }
    // 00a76ffb  eb2f                   -jmp 0xa7702c
    goto L_0x00a7702c;
L_0x00a76ffd:
    // 00a76ffd  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 00a77002  720b                   -jb 0xa7700f
    if (cpu.flags.cf)
    {
        goto L_0x00a7700f;
    }
    // 00a77004  7640                   -jbe 0xa77046
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a77046;
    }
    // 00a77006  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 00a7700b  7643                   -jbe 0xa77050
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a77050;
    }
    // 00a7700d  eb4b                   -jmp 0xa7705a
    goto L_0x00a7705a;
L_0x00a7700f:
    // 00a7700f  3d050000c0             +cmp eax, 0xc0000005
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
    // 00a77014  0f82be000000           -jb 0xa770d8
    if (cpu.flags.cf)
    {
        goto L_0x00a770d8;
    }
    // 00a7701a  7666                   -jbe 0xa77082
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a77082;
    }
    // 00a7701c  3d1d0000c0             +cmp eax, 0xc000001d
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
    // 00a77021  0f849c000000           -je 0xa770c3
    if (cpu.flags.zf)
    {
        goto L_0x00a770c3;
    }
    // 00a77027  e9ac000000             -jmp 0xa770d8
    goto L_0x00a770d8;
L_0x00a7702c:
    // 00a7702c  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a77030  740a                   -je 0xa7703c
    if (cpu.flags.zf)
    {
        goto L_0x00a7703c;
    }
    // 00a77032  bac4dda700             -mov edx, 0xa7ddc4
    cpu.edx = 11001284 /*0xa7ddc4*/;
    // 00a77037  e9af000000             -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a7703c:
    // 00a7703c  ba18dea700             -mov edx, 0xa7de18
    cpu.edx = 11001368 /*0xa7de18*/;
    // 00a77041  e9a5000000             -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a77046:
    // 00a77046  ba6cdea700             -mov edx, 0xa7de6c
    cpu.edx = 11001452 /*0xa7de6c*/;
    // 00a7704b  e99b000000             -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a77050:
    // 00a77050  bac0dea700             -mov edx, 0xa7dec0
    cpu.edx = 11001536 /*0xa7dec0*/;
    // 00a77055  e991000000             -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a7705a:
    // 00a7705a  ba14dfa700             -mov edx, 0xa7df14
    cpu.edx = 11001620 /*0xa7df14*/;
    // 00a7705f  e987000000             -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a77064:
    // 00a77064  ba68dfa700             -mov edx, 0xa7df68
    cpu.edx = 11001704 /*0xa7df68*/;
    // 00a77069  e97d000000             -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a7706e:
    // 00a7706e  bab4dfa700             -mov edx, 0xa7dfb4
    cpu.edx = 11001780 /*0xa7dfb4*/;
    // 00a77073  e973000000             -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a77078:
    // 00a77078  ba04e0a700             -mov edx, 0xa7e004
    cpu.edx = 11001860 /*0xa7e004*/;
    // 00a7707d  e969000000             -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a77082:
    // 00a77082  ba5ce0a700             -mov edx, 0xa7e05c
    cpu.edx = 11001948 /*0xa7e05c*/;
    // 00a77087  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a77089  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00a7708c  e88bfeffff             -call 0xa76f1c
    cpu.esp -= 4;
    sub_a76f1c(app, cpu);
    if (cpu.terminate) return;
    // 00a77091  ba90e0a700             -mov edx, 0xa7e090
    cpu.edx = 11002000 /*0xa7e090*/;
    // 00a77096  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a77098  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00a7709b  e87cfeffff             -call 0xa76f1c
    cpu.esp -= 4;
    sub_a76f1c(app, cpu);
    if (cpu.terminate) return;
    // 00a770a0  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a770a4  750b                   -jne 0xa770b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a770b1;
    }
    // 00a770a6  bab8e0a700             -mov edx, 0xa7e0b8
    cpu.edx = 11002040 /*0xa7e0b8*/;
    // 00a770ab  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a770ad  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a770af  eb3f                   -jmp 0xa770f0
    goto L_0x00a770f0;
L_0x00a770b1:
    // 00a770b1  bac0e0a700             -mov edx, 0xa7e0c0
    cpu.edx = 11002048 /*0xa7e0c0*/;
    // 00a770b6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a770b8  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00a770ba  eb34                   -jmp 0xa770f0
    goto L_0x00a770f0;
L_0x00a770bc:
    // 00a770bc  bacce0a700             -mov edx, 0xa7e0cc
    cpu.edx = 11002060 /*0xa7e0cc*/;
    // 00a770c1  eb28                   -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a770c3:
    // 00a770c3  ba0ce1a700             -mov edx, 0xa7e10c
    cpu.edx = 11002124 /*0xa7e10c*/;
    // 00a770c8  eb21                   -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a770ca:
    // 00a770ca  ba48e1a700             -mov edx, 0xa7e148
    cpu.edx = 11002184 /*0xa7e148*/;
    // 00a770cf  eb1a                   -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a770d1:
    // 00a770d1  ba8ce1a700             -mov edx, 0xa7e18c
    cpu.edx = 11002252 /*0xa7e18c*/;
    // 00a770d6  eb13                   -jmp 0xa770eb
    goto L_0x00a770eb;
L_0x00a770d8:
    // 00a770d8  bac8e1a700             -mov edx, 0xa7e1c8
    cpu.edx = 11002312 /*0xa7e1c8*/;
    // 00a770dd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a770df  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a770e1  e836feffff             -call 0xa76f1c
    cpu.esp -= 4;
    sub_a76f1c(app, cpu);
    if (cpu.terminate) return;
    // 00a770e6  bafce1a700             -mov edx, 0xa7e1fc
    cpu.edx = 11002364 /*0xa7e1fc*/;
L_0x00a770eb:
    // 00a770eb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a770ed  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00a770f0:
    // 00a770f0  e827feffff             -call 0xa76f1c
    cpu.esp -= 4;
    sub_a76f1c(app, cpu);
    if (cpu.terminate) return;
    // 00a770f5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a770f7  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00a770fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a770ff  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00a77103  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a77104  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a77106  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a77108  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7710a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a7710b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a7710d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a7710f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a77111  49                     -dec ecx
    (cpu.ecx)--;
    // 00a77112  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a77113  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77114  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a77118  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a77119  a188d3a700             -mov eax, dword ptr [0xa7d388]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a7711e  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a77121  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77122  2eff156cbea700         -call dword ptr cs:[0xa7be6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993260) /* 0xa7be6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77129  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a7712e:
    // 00a7712e  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00a77134  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77135  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77136  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a77158(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00a77158  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77159  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a7715a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a7715b  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a7715e  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00a77162  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00a77166  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 00a7716a  0f85a1010000           -jne 0xa77311
    if (!cpu.flags.zf)
    {
        goto L_0x00a77311;
    }
    // 00a77170  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00a77172  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 00a77177  83f806                 +cmp eax, 6
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
    // 00a7717a  0f871f010000           -ja 0xa7729f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a7729f;
    }
    // 00a77180  2eff24853c71a700       -jmp dword ptr cs:[eax*4 + 0xa7713c]
    cpu.ip = app->getMemory<x86::reg32>(10973500 + cpu.eax * 4); goto dynamic_jump;
  case 0x00a77188:
    // 00a77188  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 00a7718c  740a                   -je 0xa77198
    if (cpu.flags.zf)
    {
        goto L_0x00a77198;
    }
    // 00a7718e  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 00a77193  e9ca000000             -jmp 0xa77262
    goto L_0x00a77262;
L_0x00a77198:
    // 00a77198  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 00a7719d  e9c0000000             -jmp 0xa77262
    goto L_0x00a77262;
  case 0x00a771a2:
    // 00a771a2  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 00a771a7  e9b6000000             -jmp 0xa77262
    goto L_0x00a77262;
  case 0x00a771ac:
    // 00a771ac  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 00a771b1  e9ac000000             -jmp 0xa77262
    goto L_0x00a77262;
  case 0x00a771b6:
    // 00a771b6  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 00a771bb  e9a2000000             -jmp 0xa77262
    goto L_0x00a77262;
  case 0x00a771c0:
    // 00a771c0  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00a771c5  e998000000             -jmp 0xa77262
    goto L_0x00a77262;
  case 0x00a771ca:
    // 00a771ca  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00a771cd  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 00a771d0  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 00a771d5  6681fad9fa             +cmp dx, 0xfad9
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
    // 00a771da  750a                   -jne 0xa771e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a771e6;
    }
    // 00a771dc  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 00a771e1  e97c000000             -jmp 0xa77262
    goto L_0x00a77262;
L_0x00a771e6:
    // 00a771e6  6681fad9f1             +cmp dx, 0xf1d9
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
    // 00a771eb  750a                   -jne 0xa771f7
    if (!cpu.flags.zf)
    {
        goto L_0x00a771f7;
    }
    // 00a771ed  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 00a771f2  e96b000000             -jmp 0xa77262
    goto L_0x00a77262;
L_0x00a771f7:
    // 00a771f7  750a                   -jne 0xa77203
    if (!cpu.flags.zf)
    {
        goto L_0x00a77203;
    }
    // 00a771f9  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00a771fe  e95f000000             -jmp 0xa77262
    goto L_0x00a77262;
L_0x00a77203:
    // 00a77203  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 00a77205  80fedb                 +cmp dh, 0xdb
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
    // 00a77208  7405                   -je 0xa7720f
    if (cpu.flags.zf)
    {
        goto L_0x00a7720f;
    }
    // 00a7720a  80fedf                 +cmp dh, 0xdf
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
    // 00a7720d  7510                   -jne 0xa7721f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7721f;
    }
L_0x00a7720f:
    // 00a7720f  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a77212  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a77215  80fa10                 +cmp dl, 0x10
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
    // 00a77218  7505                   -jne 0xa7721f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7721f;
    }
    // 00a7721a  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x00a7721f:
    // 00a7721f  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 00a77222  7539                   -jne 0xa7725d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7725d;
    }
    // 00a77224  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a77227  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 00a77229  3c30                   +cmp al, 0x30
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
    // 00a7722b  7530                   -jne 0xa7725d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7725d;
    }
    // 00a7722d  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a77230  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a77235  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a77238  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7723a  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 00a7723e  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 00a77241  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 00a77244  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00a7724a  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00a7724c  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 00a7724e  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 00a77251  83fa01                 +cmp edx, 1
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
    // 00a77254  7507                   -jne 0xa7725d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7725d;
    }
  [[fallthrough]];
  case 0x00a77256:
    // 00a77256  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 00a7725b  eb05                   -jmp 0xa77262
    goto L_0x00a77262;
L_0x00a7725d:
    // 00a7725d  83fbff                 +cmp ebx, -1
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
    // 00a77260  743d                   -je 0xa7729f
    if (cpu.flags.zf)
    {
        goto L_0x00a7729f;
    }
L_0x00a77262:
    // 00a77262  c605e40da80001         -mov byte ptr [0xa80de4], 1
    app->getMemory<x86::reg8>(x86::reg32(11013604) /* 0xa80de4 */) = 1 /*0x1*/;
    // 00a77269  e862120000             -call 0xa784d0
    cpu.esp -= 4;
    sub_a784d0(app, cpu);
    if (cpu.terminate) return;
    // 00a7726e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a77270  e82f140000             -call 0xa786a4
    cpu.esp -= 4;
    sub_a786a4(app, cpu);
    if (cpu.terminate) return;
    // 00a77275  83f8ff                 +cmp eax, -1
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
    // 00a77278  0f8474000000           -je 0xa772f2
    if (cpu.flags.zf)
    {
        goto L_0x00a772f2;
    }
    // 00a7727e  803de40da80000         +cmp byte ptr [0xa80de4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11013604) /* 0xa80de4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a77285  0f8467000000           -je 0xa772f2
    if (cpu.flags.zf)
    {
        goto L_0x00a772f2;
    }
    // 00a7728b  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00a7728f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a77291  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 00a77294  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a77296  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 00a7729a  e977000000             -jmp 0xa77316
    goto L_0x00a77316;
L_0x00a7729f:
    // 00a7729f  833da4d3a70000         +cmp dword ptr [0xa7d3a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10998692) /* 0xa7d3a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a772a6  744a                   -je 0xa772f2
    if (cpu.flags.zf)
    {
        goto L_0x00a772f2;
    }
    // 00a772a8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00a772ad  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
L_0x00a772af:
    // 00a772af  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a772b1  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00a772b3  ff15a0d3a700           -call dword ptr [0xa7d3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998688) /* 0xa7d3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a772b9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a772bb  742f                   -je 0xa772ec
    if (cpu.flags.zf)
    {
        goto L_0x00a772ec;
    }
    // 00a772bd  83f801                 +cmp eax, 1
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
    // 00a772c0  7430                   -je 0xa772f2
    if (cpu.flags.zf)
    {
        goto L_0x00a772f2;
    }
    // 00a772c2  83f802                 +cmp eax, 2
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
    // 00a772c5  742b                   -je 0xa772f2
    if (cpu.flags.zf)
    {
        goto L_0x00a772f2;
    }
    // 00a772c7  83f803                 +cmp eax, 3
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
    // 00a772ca  7426                   -je 0xa772f2
    if (cpu.flags.zf)
    {
        goto L_0x00a772f2;
    }
    // 00a772cc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a772ce  880de40da800           -mov byte ptr [0xa80de4], cl
    app->getMemory<x86::reg8>(x86::reg32(11013604) /* 0xa80de4 */) = cpu.cl;
    // 00a772d4  ff15a4d3a700           -call dword ptr [0xa7d3a4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998692) /* 0xa7d3a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a772da  803de40da80000         +cmp byte ptr [0xa80de4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(11013604) /* 0xa80de4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a772e1  7409                   -je 0xa772ec
    if (cpu.flags.zf)
    {
        goto L_0x00a772ec;
    }
    // 00a772e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a772e5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a772e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a772e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a772ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a772eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a772ec:
    // 00a772ec  43                     -inc ebx
    (cpu.ebx)++;
    // 00a772ed  83fb0c                 +cmp ebx, 0xc
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
    // 00a772f0  7ebd                   -jle 0xa772af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00a772af;
    }
L_0x00a772f2:
    // 00a772f2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a772f4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a772f5  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a772f9  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00a772fd  2eff1550bea700         -call dword ptr cs:[0xa7be50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993232) /* 0xa7be50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77304  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77306  7409                   -je 0xa77311
    if (cpu.flags.zf)
    {
        goto L_0x00a77311;
    }
    // 00a77308  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00a7730a  2eff15a4bda700         -call dword ptr cs:[0xa7bda4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993060) /* 0xa7bda4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00a77311:
    // 00a77311  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00a77316:
    // 00a77316  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a77319  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7731a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7731b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7731c  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a77320(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77320  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77321  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77322  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a77324  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7732a  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00a7732d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7732f  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 00a77332  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a77334  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7733a  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a7733d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00a7733f  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77345  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a77348  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7734a  c740045871a700         -mov dword ptr [eax + 4], 0xa77158
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10973528 /*0xa77158*/;
    // 00a77351  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77357  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a7735a  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 00a7735d  68746fa700             -push 0xa76f74
    app->getMemory<x86::reg32>(cpu.esp-4) = 10973044 /*0xa76f74*/;
    cpu.esp -= 4;
    // 00a77362  2eff153cbea700         -call dword ptr cs:[0xa7be3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993212) /* 0xa7be3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77369  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7736a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7736b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7736c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7736c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7736d  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77373  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 00a77376  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77378  7407                   -je 0xa77381
    if (cpu.flags.zf)
    {
        goto L_0x00a77381;
    }
    // 00a7737a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a7737c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7737e  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x00a77381:
    // 00a77381  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77387  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00a7738e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7738f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a77390(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77390  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77391  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a77394  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a77397  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77399  742a                   -je 0xa773c5
    if (cpu.flags.zf)
    {
        goto L_0x00a773c5;
    }
    // 00a7739b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7739d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7739f  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a773a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a773a2  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a773a4  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00a773a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a773a9  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 00a773ae  8b1554d6a700           -mov edx, dword ptr [0xa7d654]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10999380) /* 0xa7d654 */);
    // 00a773b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a773b5  2eff1568bea700         -call dword ptr cs:[0xa7be68]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993256) /* 0xa7be68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a773bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a773be  7505                   -jne 0xa773c5
    if (!cpu.flags.zf)
    {
        goto L_0x00a773c5;
    }
    // 00a773c0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00a773c5:
    // 00a773c5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a773c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a773c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a773d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a773d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a773d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a773d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a773d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a773d4  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a773d7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a773d9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a773db  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a773dd  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a773df  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a773e3  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00a773e6:
    // 00a773e6  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a773ea  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00a773ee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a773f0  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a773f2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00a773f4  8a82bcd3a700           -mov al, byte ptr [edx + 0xa7d3bc]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10998716) /* 0xa7d3bc */);
    // 00a773fa  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 00a773fc  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a77400  41                     -inc ecx
    (cpu.ecx)++;
    // 00a77401  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77403  75e1                   -jne 0xa773e6
    if (!cpu.flags.zf)
    {
        goto L_0x00a773e6;
    }
L_0x00a77405:
    // 00a77405  46                     -inc esi
    (cpu.esi)++;
    // 00a77406  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a77409  49                     -dec ecx
    (cpu.ecx)--;
    // 00a7740a  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00a7740d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a7740f  75f4                   -jne 0xa77405
    if (!cpu.flags.zf)
    {
        goto L_0x00a77405;
    }
    // 00a77411  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a77413  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a77416  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77417  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77418  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77419  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7741a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a7741c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7741c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7741d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a7741f  83fb0a                 +cmp ebx, 0xa
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
    // 00a77422  750a                   -jne 0xa7742e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7742e;
    }
    // 00a77424  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77426  7d06                   -jge 0xa7742e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a7742e;
    }
    // 00a77428  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a7742a  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a7742d  42                     -inc edx
    (cpu.edx)++;
L_0x00a7742e:
    // 00a7742e  e89dffffff             -call 0xa773d0
    cpu.esp -= 4;
    sub_a773d0(app, cpu);
    if (cpu.terminate) return;
    // 00a77433  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a77435  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77436  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77440(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77440  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77441  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a77446  b828e2a700             -mov eax, 0xa7e228
    cpu.eax = 11002408 /*0xa7e228*/;
    // 00a7744b  e84cebffff             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a77450  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77451  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77460(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77460  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77461  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77462  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77463  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a77464  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a77465  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a77468  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a7746a  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 00a7746e  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a77472  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a77476  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a77478  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 00a7747c  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a7747e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a77480  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a77482  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a77483  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a77484  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00a77488  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00a7748c  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00a7748f:
    // 00a7748f  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a77493  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a77497  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a7749b  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a7749f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a774a2  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a774a4  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00a774a7  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a774a9  e8ab150000             -call 0xa78a59
    cpu.esp -= 4;
    sub_a78a59(app, cpu);
    if (cpu.terminate) return;
    // 00a774ae  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00a774b1  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00a774b3  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00a774b6  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 00a774b8  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00a774bc  8a80ecd3a700           -mov al, byte ptr [eax + 0xa7d3ec]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10998764) /* 0xa7d3ec */);
    // 00a774c2  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 00a774c5  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00a774c9  45                     -inc ebp
    (cpu.ebp)++;
    // 00a774ca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a774cc  75c1                   -jne 0xa7748f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7748f;
    }
    // 00a774ce  837c243800             +cmp dword ptr [esp + 0x38], 0
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
    // 00a774d3  75ba                   -jne 0xa7748f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7748f;
    }
L_0x00a774d5:
    // 00a774d5  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00a774d9  8a45ff                 -mov al, byte ptr [ebp - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 00a774dc  4d                     -dec ebp
    (cpu.ebp)--;
    // 00a774dd  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00a774e0  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 00a774e2  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 00a774e6  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a774e8  75eb                   -jne 0xa774d5
    if (!cpu.flags.zf)
    {
        goto L_0x00a774d5;
    }
    // 00a774ea  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00a774ee  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00a774f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a774f2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a774f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a774f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a774f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a774f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a774f8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a774f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a774f9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a774fa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a774fb  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a774fc  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a774ff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a77501  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a77503  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a77505  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00a77507  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a77509  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7750a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7750b  83fb0a                 +cmp ebx, 0xa
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
    // 00a7750e  752d                   -jne 0xa7753d
    if (!cpu.flags.zf)
    {
        goto L_0x00a7753d;
    }
    // 00a77510  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 00a77515  7426                   -je 0xa7753d
    if (cpu.flags.zf)
    {
        goto L_0x00a7753d;
    }
    // 00a77517  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a7751a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7751d  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a77521  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 00a77523  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 00a77525  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00a77528  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a7752c  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00a7752f  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00a77532  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00a77533  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00a77536  7501                   -jne 0xa77539
    if (!cpu.flags.zf)
    {
        goto L_0x00a77539;
    }
    // 00a77538  46                     -inc esi
    (cpu.esi)++;
L_0x00a77539:
    // 00a77539  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x00a7753d:
    // 00a7753d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a7753f  e81cffffff             -call 0xa77460
    cpu.esp -= 4;
    sub_a77460(app, cpu);
    if (cpu.terminate) return;
    // 00a77544  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a77546  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a77549  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7754a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7754b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7754c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7754d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a77550(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77550  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77551  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77552  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77553  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a77554  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a77557  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00a77559  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00a7755b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a7755d  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a7755f  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00a77563  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x00a77566:
    // 00a77566  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a7756a  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 00a7756e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a77570  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 00a77572  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00a77574  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00a77578  41                     -inc ecx
    (cpu.ecx)++;
    // 00a77579  8a9b14d4a700           -mov bl, byte ptr [ebx + 0xa7d414]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(10998804) /* 0xa7d414 */);
    // 00a7757f  8859ff                 -mov byte ptr [ecx - 1], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 00a77582  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77584  75e0                   -jne 0xa77566
    if (!cpu.flags.zf)
    {
        goto L_0x00a77566;
    }
L_0x00a77586:
    // 00a77586  46                     -inc esi
    (cpu.esi)++;
    // 00a77587  8a41ff                 -mov al, byte ptr [ecx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a7758a  49                     -dec ecx
    (cpu.ecx)--;
    // 00a7758b  8846ff                 -mov byte ptr [esi - 1], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 00a7758e  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00a77590  75f4                   -jne 0xa77586
    if (!cpu.flags.zf)
    {
        goto L_0x00a77586;
    }
    // 00a77592  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a77594  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00a77597  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77598  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77599  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7759a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7759b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7759c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7759c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7759d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a7759f  83fb0a                 +cmp ebx, 0xa
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
    // 00a775a2  750a                   -jne 0xa775ae
    if (!cpu.flags.zf)
    {
        goto L_0x00a775ae;
    }
    // 00a775a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a775a6  7d06                   -jge 0xa775ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a775ae;
    }
    // 00a775a8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 00a775aa  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 00a775ad  42                     -inc edx
    (cpu.edx)++;
L_0x00a775ae:
    // 00a775ae  e89dffffff             -call 0xa77550
    cpu.esp -= 4;
    sub_a77550(app, cpu);
    if (cpu.terminate) return;
    // 00a775b3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a775b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a775b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a775c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a775c0  8a80010ea800           -mov al, byte ptr [eax + 0xa80e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a775c6  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a775c8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a775cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a775d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a775d0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a775d2  e9c9120000             -jmp 0xa788a0
    return sub_a788a0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a775e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a775e0  83f861                 +cmp eax, 0x61
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
    // 00a775e3  7c08                   -jl 0xa775ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a775ed;
    }
    // 00a775e5  83f87a                 +cmp eax, 0x7a
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
    // 00a775e8  7f03                   -jg 0xa775ed
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00a775ed;
    }
    // 00a775ea  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x00a775ed:
    // 00a775ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a775f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a775f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a775f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a775f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a775f4  ff15b0d2a700           -call dword ptr [0xa7d2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998448) /* 0xa7d2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a775fa  8b153cd4a700           -mov edx, dword ptr [0xa7d43c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10998844) /* 0xa7d43c */);
    // 00a77600  891d3cd4a700           -mov dword ptr [0xa7d43c], ebx
    app->getMemory<x86::reg32>(x86::reg32(10998844) /* 0xa7d43c */) = cpu.ebx;
    // 00a77606  ff15b8d2a700           -call dword ptr [0xa7d2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998456) /* 0xa7d2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7760c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7760e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7760f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77610  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77620(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77621  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77622  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77623  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77624  ff15b0d2a700           -call dword ptr [0xa7d2b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998448) /* 0xa7d2b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7762a  a178d1a700             -mov eax, dword ptr [0xa7d178]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */);
    // 00a7762f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77631  741c                   -je 0xa7764f
    if (cpu.flags.zf)
    {
        goto L_0x00a7764f;
    }
L_0x00a77633:
    // 00a77633  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00a77635  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00a77638  83eb2c                 -sub ebx, 0x2c
    (cpu.ebx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00a7763b  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00a7763d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a77640  39f3                   +cmp ebx, esi
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
    // 00a77642  7505                   -jne 0xa77649
    if (!cpu.flags.zf)
    {
        goto L_0x00a77649;
    }
    // 00a77644  e873000000             -call 0xa776bc
    cpu.esp -= 4;
    sub_a776bc(app, cpu);
    if (cpu.terminate) return;
L_0x00a77649:
    // 00a77649  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a7764b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7764d  75e4                   -jne 0xa77633
    if (!cpu.flags.zf)
    {
        goto L_0x00a77633;
    }
L_0x00a7764f:
    // 00a7764f  ff15b8d2a700           -call dword ptr [0xa7d2b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998456) /* 0xa7d2b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77655  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77657  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77658  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77659  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7765a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7765b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7765c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7765c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7765d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7765e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7765f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77660  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77661  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a77663  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00a77668  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7766a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a7766b  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a7766e  2eff1558bea700         -call dword ptr cs:[0xa7be58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993240) /* 0xa7be58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77675  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77677  7507                   -jne 0xa77680
    if (!cpu.flags.zf)
    {
        goto L_0x00a77680;
    }
    // 00a77679  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7767e  eb36                   -jmp 0xa776b6
    goto L_0x00a776b6;
L_0x00a77680:
    // 00a77680  3b1d7cd1a700           +cmp ebx, dword ptr [0xa7d17c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10998140) /* 0xa7d17c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77686  751c                   -jne 0xa776a4
    if (!cpu.flags.zf)
    {
        goto L_0x00a776a4;
    }
    // 00a77688  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a7768a  7408                   -je 0xa77694
    if (cpu.flags.zf)
    {
        goto L_0x00a77694;
    }
    // 00a7768c  89357cd1a700           -mov dword ptr [0xa7d17c], esi
    app->getMemory<x86::reg32>(x86::reg32(10998140) /* 0xa7d17c */) = cpu.esi;
    // 00a77692  eb10                   -jmp 0xa776a4
    goto L_0x00a776a4;
L_0x00a77694:
    // 00a77694  a178d1a700             -mov eax, dword ptr [0xa7d178]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */);
    // 00a77699  893580d1a700           -mov dword ptr [0xa7d180], esi
    app->getMemory<x86::reg32>(x86::reg32(10998144) /* 0xa7d180 */) = cpu.esi;
    // 00a7769f  a37cd1a700             -mov dword ptr [0xa7d17c], eax
    app->getMemory<x86::reg32>(x86::reg32(10998140) /* 0xa7d17c */) = cpu.eax;
L_0x00a776a4:
    // 00a776a4  3b1df0ffa700           +cmp ebx, dword ptr [0xa7fff0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(11010032) /* 0xa7fff0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a776aa  7508                   -jne 0xa776b4
    if (!cpu.flags.zf)
    {
        goto L_0x00a776b4;
    }
    // 00a776ac  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00a776ae  893df0ffa700           -mov dword ptr [0xa7fff0], edi
    app->getMemory<x86::reg32>(x86::reg32(11010032) /* 0xa7fff0 */) = cpu.edi;
L_0x00a776b4:
    // 00a776b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a776b6:
    // 00a776b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a776b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a776b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a776b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a776ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a776bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a776bc(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a776bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a776bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a776be  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a776c1  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a776c4  e893ffffff             -call 0xa7765c
    cpu.esp -= 4;
    sub_a7765c(app, cpu);
    if (cpu.terminate) return;
    // 00a776c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a776cb  7516                   -jne 0xa776e3
    if (!cpu.flags.zf)
    {
        goto L_0x00a776e3;
    }
    // 00a776cd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a776cf  7508                   -jne 0xa776d9
    if (!cpu.flags.zf)
    {
        goto L_0x00a776d9;
    }
    // 00a776d1  891578d1a700           -mov dword ptr [0xa7d178], edx
    app->getMemory<x86::reg32>(x86::reg32(10998136) /* 0xa7d178 */) = cpu.edx;
    // 00a776d7  eb03                   -jmp 0xa776dc
    goto L_0x00a776dc;
L_0x00a776d9:
    // 00a776d9  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x00a776dc:
    // 00a776dc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a776de  7403                   -je 0xa776e3
    if (cpu.flags.zf)
    {
        goto L_0x00a776e3;
    }
    // 00a776e0  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x00a776e3:
    // 00a776e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a776e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a776e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a776f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a776f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a776f1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00a776f3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a776f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a776f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a776f6  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00a776f9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a776fb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a776fd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a776ff  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 00a77702  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 00a77705  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 00a77708  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a7770b  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 00a7770d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a77712  83f847                 +cmp eax, 0x47
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(71 /*0x47*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77715  7523                   -jne 0xa7773a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7773a;
    }
    // 00a77717  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a77719  7505                   -jne 0xa77720
    if (!cpu.flags.zf)
    {
        goto L_0x00a77720;
    }
    // 00a7771b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x00a77720:
    // 00a77720  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 00a77727  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 00a7772a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7772f  83ef02                 +sub edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00a77732  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 00a77735  897dc0                 -mov dword ptr [ebp - 0x40], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 00a77738  eb1f                   -jmp 0xa77759
    goto L_0x00a77759;
L_0x00a7773a:
    // 00a7773a  83f845                 +cmp eax, 0x45
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(69 /*0x45*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7773d  750d                   -jne 0xa7774c
    if (!cpu.flags.zf)
    {
        goto L_0x00a7774c;
    }
    // 00a7773f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00a77744  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00a77747  897db8                 -mov dword ptr [ebp - 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 00a7774a  eb0d                   -jmp 0xa77759
    goto L_0x00a77759;
L_0x00a7774c:
    // 00a7774c  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00a77751  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77753  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 00a77756  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x00a77759:
    // 00a77759  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 00a7775d  7404                   -je 0xa77763
    if (cpu.flags.zf)
    {
        goto L_0x00a77763;
    }
    // 00a7775f  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x00a77763:
    // 00a77763  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a77765  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a77768  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a7776a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7776c  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 00a7776f  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00a77772  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 00a77775  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a77778  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00a7777b  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00a7777e  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 00a77780  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a77782  83fbff                 +cmp ebx, -1
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
    // 00a77785  7505                   -jne 0xa7778c
    if (!cpu.flags.zf)
    {
        goto L_0x00a7778c;
    }
    // 00a77787  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x00a7778c:
    // 00a7778c  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00a7778f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a77791  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 00a77794  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 00a77797  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a7779a  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 00a7779d  e87d140000             -call 0xa78c1f
    cpu.esp -= 4;
    sub_a78c1f(app, cpu);
    if (cpu.terminate) return;
    // 00a777a2  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 00a777a5  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00a777a8  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 00a777ab  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00a777ae  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 00a777b1  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00a777b4  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 00a777b7  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00a777ba  837dc800               +cmp dword ptr [ebp - 0x38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a777be  7d0f                   -jge 0xa777cf
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a777cf;
    }
    // 00a777c0  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a777c3  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a777c6  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a777c9  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 00a777cd  eb29                   -jmp 0xa777f8
    goto L_0x00a777f8;
L_0x00a777cf:
    // 00a777cf  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00a777d2  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 00a777d5  740f                   -je 0xa777e6
    if (cpu.flags.zf)
    {
        goto L_0x00a777e6;
    }
    // 00a777d7  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a777da  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a777dd  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a777e0  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 00a777e4  eb12                   -jmp 0xa777f8
    goto L_0x00a777f8;
L_0x00a777e6:
    // 00a777e6  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 00a777e9  740d                   -je 0xa777f8
    if (cpu.flags.zf)
    {
        goto L_0x00a777f8;
    }
    // 00a777eb  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 00a777ee  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a777f1  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00a777f4  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x00a777f8:
    // 00a777f8  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 00a777fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a777fc  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00a777ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77800  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77801  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77802  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77803  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a77804(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77804  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77805  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a77807  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a77809  e85b1f0000             -call 0xa79769
    cpu.esp -= 4;
    sub_a79769(app, cpu);
    if (cpu.terminate) return;
    // 00a7780e  dd1b                   -fstp qword ptr [ebx]
    app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00a77810  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77811  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77820(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77820  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77830(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77830  6650                   -push ax
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ax;
    cpu.esp -= 4;
    // 00a77832  9b                     -wait 
    /*nothing*/;
    // 00a77833  dbe3                   +fninit 
    cpu.fpu.init();
    // 00a77835  d9e8                   +fld1 
    cpu.fpu.push(1.0);
    // 00a77837  d9ee                   +fldz 
    cpu.fpu.push(0.0);
    // 00a77839  def9                   +fdivp st(1)
    cpu.fpu.st(1) /= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00a7783b  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00a7783d  d9e0                   +fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 00a7783f  ded9                   +fcompp 
    cpu.fpu.compare(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    cpu.fpu.pop();
    // 00a77841  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00a77843  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 00a77845  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00a77846  7402                   -je 0xa7784a
    if (cpu.flags.zf)
    {
        goto L_0x00a7784a;
    }
    // 00a77848  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_0x00a7784a:
    // 00a7784a  9b                     -wait 
    /*nothing*/;
    // 00a7784b  dbe3                   -fninit 
    cpu.fpu.init();
    // 00a7784d  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 00a77850  66870424               -xchg word ptr [esp], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.esp);
        app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
        cpu.ax = tmp;
    }
    // 00a77854  6658                   -pop ax
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a77856  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77860(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77860  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77861  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77862  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77863  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77864  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77865  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a77867  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a7786c  68f810a800             -push 0xa810f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 11014392 /*0xa810f8*/;
    cpu.esp -= 4;
    // 00a77871  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a77873  2eff15e8bda700         -call dword ptr cs:[0xa7bde8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993128) /* 0xa7bde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7787a  6804010000             -push 0x104
    app->getMemory<x86::reg32>(cpu.esp-4) = 260 /*0x104*/;
    cpu.esp -= 4;
    // 00a7787f  68fc11a800             -push 0xa811fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 11014652 /*0xa811fc*/;
    cpu.esp -= 4;
    // 00a77884  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77885  be4ce2a700             -mov esi, 0xa7e24c
    cpu.esi = 11002444 /*0xa7e24c*/;
    // 00a7788a  2eff15e8bda700         -call dword ptr cs:[0xa7bde8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993128) /* 0xa7bde8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77891  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00a77893  bf100fa800             -mov edi, 0xa80f10
    cpu.edi = 11013904 /*0xa80f10*/;
    // 00a77898  8825100fa800           -mov byte ptr [0xa80f10], ah
    app->getMemory<x86::reg8>(x86::reg32(11013904) /* 0xa80f10 */) = cpu.ah;
    // 00a7789e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a7789f  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a778a0  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a778a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a778a2  2bc9                   +sub ecx, ecx
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
    // 00a778a4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a778a5  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a778a7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a778a9  4f                     -dec edi
    (cpu.edi)--;
L_0x00a778aa:
    // 00a778aa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a778ac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a778ae  3c00                   +cmp al, 0
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
    // 00a778b0  7410                   -je 0xa778c2
    if (cpu.flags.zf)
    {
        goto L_0x00a778c2;
    }
    // 00a778b2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a778b5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a778b8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a778bb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a778be  3c00                   +cmp al, 0
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
    // 00a778c0  75e8                   -jne 0xa778aa
    if (!cpu.flags.zf)
    {
        goto L_0x00a778aa;
    }
L_0x00a778c2:
    // 00a778c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a778c3  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a778c4  bef810a800             -mov esi, 0xa810f8
    cpu.esi = 11014392 /*0xa810f8*/;
    // 00a778c9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a778ca  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a778cb  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a778cc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a778cd  2bc9                   +sub ecx, ecx
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
    // 00a778cf  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a778d0  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a778d2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a778d4  4f                     -dec edi
    (cpu.edi)--;
L_0x00a778d5:
    // 00a778d5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a778d7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a778d9  3c00                   +cmp al, 0
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
    // 00a778db  7410                   -je 0xa778ed
    if (cpu.flags.zf)
    {
        goto L_0x00a778ed;
    }
    // 00a778dd  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a778e0  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a778e3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a778e6  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a778e9  3c00                   +cmp al, 0
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
    // 00a778eb  75e8                   -jne 0xa778d5
    if (!cpu.flags.zf)
    {
        goto L_0x00a778d5;
    }
L_0x00a778ed:
    // 00a778ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a778ee  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a778ef  be80e2a700             -mov esi, 0xa7e280
    cpu.esi = 11002496 /*0xa7e280*/;
    // 00a778f4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a778f5  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 00a778f6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a778f7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a778f8  2bc9                   +sub ecx, ecx
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
    // 00a778fa  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00a778fb  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00a778fd  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a778ff  4f                     -dec edi
    (cpu.edi)--;
L_0x00a77900:
    // 00a77900  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a77902  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a77904  3c00                   +cmp al, 0
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
    // 00a77906  7410                   -je 0xa77918
    if (cpu.flags.zf)
    {
        goto L_0x00a77918;
    }
    // 00a77908  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a7790b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a7790e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a77911  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a77914  3c00                   +cmp al, 0
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
    // 00a77916  75e8                   -jne 0xa77900
    if (!cpu.flags.zf)
    {
        goto L_0x00a77900;
    }
L_0x00a77918:
    // 00a77918  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77919  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7791a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7791c  68fc11a800             -push 0xa811fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 11014652 /*0xa811fc*/;
    cpu.esp -= 4;
    // 00a77921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77922  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a77924  2eff1574bda700         -call dword ptr cs:[0xa7bd74]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993012) /* 0xa7bd74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7792b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a77930  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77931  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77932  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77933  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77934  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77935  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77940(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77940  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77950(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77950  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77951  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77952  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77953  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77954  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77955  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a77956  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a77959  b834e3a700             -mov eax, 0xa7e334
    cpu.eax = 11002676 /*0xa7e334*/;
    // 00a7795e  e84dc1ffff             -call 0xa73ab0
    cpu.esp -= 4;
    sub_a73ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a77963  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a77965  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77967  0f84f9000000           -je 0xa77a66
    if (cpu.flags.zf)
    {
        goto L_0x00a77a66;
    }
L_0x00a7796d:
    // 00a7796d  803900                 +cmp byte ptr [ecx], 0
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
    // 00a77970  0f84e6000000           -je 0xa77a5c
    if (cpu.flags.zf)
    {
        goto L_0x00a77a5c;
    }
    // 00a77976  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a77978  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x00a7797a:
    // 00a7797a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a7797c  3ac2                   +cmp al, dl
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
    // 00a7797e  7412                   -je 0xa77992
    if (cpu.flags.zf)
    {
        goto L_0x00a77992;
    }
    // 00a77980  3c00                   +cmp al, 0
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
    // 00a77982  740c                   -je 0xa77990
    if (cpu.flags.zf)
    {
        goto L_0x00a77990;
    }
    // 00a77984  46                     -inc esi
    (cpu.esi)++;
    // 00a77985  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a77987  3ac2                   +cmp al, dl
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
    // 00a77989  7407                   -je 0xa77992
    if (cpu.flags.zf)
    {
        goto L_0x00a77992;
    }
    // 00a7798b  46                     -inc esi
    (cpu.esi)++;
    // 00a7798c  3c00                   +cmp al, 0
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
    // 00a7798e  75ea                   -jne 0xa7797a
    if (!cpu.flags.zf)
    {
        goto L_0x00a7797a;
    }
L_0x00a77990:
    // 00a77990  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a77992:
    // 00a77992  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a77994  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a77996  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a77998  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a7799a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a7799c  e8af1e0000             -call 0xa79850
    cpu.esp -= 4;
    sub_a79850(app, cpu);
    if (cpu.terminate) return;
    // 00a779a1  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a779a6  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a779a8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a779aa  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 00a779ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a779af  e82c200000             -call 0xa799e0
    cpu.esp -= 4;
    sub_a799e0(app, cpu);
    if (cpu.terminate) return;
    // 00a779b4  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a779b7  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 00a779b9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a779bb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a779bd:
    // 00a779bd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a779bf  3ac2                   +cmp al, dl
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
    // 00a779c1  7412                   -je 0xa779d5
    if (cpu.flags.zf)
    {
        goto L_0x00a779d5;
    }
    // 00a779c3  3c00                   +cmp al, 0
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
    // 00a779c5  740c                   -je 0xa779d3
    if (cpu.flags.zf)
    {
        goto L_0x00a779d3;
    }
    // 00a779c7  46                     -inc esi
    (cpu.esi)++;
    // 00a779c8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a779ca  3ac2                   +cmp al, dl
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
    // 00a779cc  7407                   -je 0xa779d5
    if (cpu.flags.zf)
    {
        goto L_0x00a779d5;
    }
    // 00a779ce  46                     -inc esi
    (cpu.esi)++;
    // 00a779cf  3c00                   +cmp al, 0
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
    // 00a779d1  75ea                   -jne 0xa779bd
    if (!cpu.flags.zf)
    {
        goto L_0x00a779bd;
    }
L_0x00a779d3:
    // 00a779d3  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a779d5:
    // 00a779d5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a779d7  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a779d9  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a779db  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a779dd  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a779df  e86c1e0000             -call 0xa79850
    cpu.esp -= 4;
    sub_a79850(app, cpu);
    if (cpu.terminate) return;
    // 00a779e4  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a779e9  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00a779eb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a779ed  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 00a779f0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a779f2  e8e91f0000             -call 0xa799e0
    cpu.esp -= 4;
    sub_a799e0(app, cpu);
    if (cpu.terminate) return;
    // 00a779f7  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a779fa  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 00a779fc  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a77a00  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x00a77a02:
    // 00a77a02  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a77a04  3ac2                   +cmp al, dl
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
    // 00a77a06  7412                   -je 0xa77a1a
    if (cpu.flags.zf)
    {
        goto L_0x00a77a1a;
    }
    // 00a77a08  3c00                   +cmp al, 0
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
    // 00a77a0a  740c                   -je 0xa77a18
    if (cpu.flags.zf)
    {
        goto L_0x00a77a18;
    }
    // 00a77a0c  46                     -inc esi
    (cpu.esi)++;
    // 00a77a0d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a77a0f  3ac2                   +cmp al, dl
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
    // 00a77a11  7407                   -je 0xa77a1a
    if (cpu.flags.zf)
    {
        goto L_0x00a77a1a;
    }
    // 00a77a13  46                     -inc esi
    (cpu.esi)++;
    // 00a77a14  3c00                   +cmp al, 0
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
    // 00a77a16  75ea                   -jne 0xa77a02
    if (!cpu.flags.zf)
    {
        goto L_0x00a77a02;
    }
L_0x00a77a18:
    // 00a77a18  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a77a1a:
    // 00a77a1a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a77a1c  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00a77a1e  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a77a20  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a77a22  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00a77a24  e8271e0000             -call 0xa79850
    cpu.esp -= 4;
    sub_a79850(app, cpu);
    if (cpu.terminate) return;
    // 00a77a29  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a77a2b  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00a77a2d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00a77a2f  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 00a77a32  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00a77a37  e8a41f0000             -call 0xa799e0
    cpu.esp -= 4;
    sub_a799e0(app, cpu);
    if (cpu.terminate) return;
    // 00a77a3c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a77a3e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00a77a40  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00a77a44  e88febffff             -call 0xa765d8
    cpu.esp -= 4;
    sub_a765d8(app, cpu);
    if (cpu.terminate) return;
    // 00a77a49  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a77a4b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a77a4d  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 00a77a50  e893050000             -call 0xa77fe8
    cpu.esp -= 4;
    sub_a77fe8(app, cpu);
    if (cpu.terminate) return;
    // 00a77a55  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a77a57  e911ffffff             -jmp 0xa7796d
    goto L_0x00a7796d;
L_0x00a77a5c:
    // 00a77a5c  b840e3a700             -mov eax, 0xa7e340
    cpu.eax = 11002688 /*0xa7e340*/;
    // 00a77a61  e8ea1f0000             -call 0xa79a50
    cpu.esp -= 4;
    sub_a79a50(app, cpu);
    if (cpu.terminate) return;
L_0x00a77a66:
    // 00a77a66  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00a77a69  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77a6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77a6b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77a6c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77a6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77a6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77a6f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a77a70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77a70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77a71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77a72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77a73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77a74  8b150400a800           -mov edx, dword ptr [0xa80004]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a77a7a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a77a7c  0f8480000000           -je 0xa77b02
    if (cpu.flags.zf)
    {
        goto L_0x00a77b02;
    }
    // 00a77a82  eb30                   -jmp 0xa77ab4
    goto L_0x00a77ab4;
L_0x00a77a84:
    // 00a77a84  833d0000a80000         +cmp dword ptr [0xa80000], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77a8b  7424                   -je 0xa77ab1
    if (cpu.flags.zf)
    {
        goto L_0x00a77ab1;
    }
    // 00a77a8d  8b350400a800           -mov esi, dword ptr [0xa80004]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a77a93  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a77a95  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00a77a97  8b1d0000a800           -mov ebx, dword ptr [0xa80000]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
    // 00a77a9d  c1f902                 -sar ecx, 2
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (2 /*0x2*/ % 32));
    // 00a77aa0  803c1900               +cmp byte ptr [ecx + ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + cpu.ebx * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a77aa4  7405                   -je 0xa77aab
    if (cpu.flags.zf)
    {
        goto L_0x00a77aab;
    }
    // 00a77aa6  e8c5c2ffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a77aab:
    // 00a77aab  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
L_0x00a77ab1:
    // 00a77ab1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a77ab4:
    // 00a77ab4  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a77ab6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77ab8  75ca                   -jne 0xa77a84
    if (!cpu.flags.zf)
    {
        goto L_0x00a77a84;
    }
    // 00a77aba  833d0000a80000         +cmp dword ptr [0xa80000], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77ac1  750c                   -jne 0xa77acf
    if (!cpu.flags.zf)
    {
        goto L_0x00a77acf;
    }
    // 00a77ac3  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00a77ac8  e8b3c1ffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a77acd  eb0f                   -jmp 0xa77ade
    goto L_0x00a77ade;
L_0x00a77acf:
    // 00a77acf  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00a77ad4  a10400a800             -mov eax, dword ptr [0xa80004]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */);
    // 00a77ad9  e8c2050000             -call 0xa780a0
    cpu.esp -= 4;
    sub_a780a0(app, cpu);
    if (cpu.terminate) return;
L_0x00a77ade:
    // 00a77ade  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77ae0  750a                   -jne 0xa77aec
    if (!cpu.flags.zf)
    {
        goto L_0x00a77aec;
    }
    // 00a77ae2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a77ae7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77ae8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77ae9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77aea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77aeb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77aec:
    // 00a77aec  a30400a800             -mov dword ptr [0xa80004], eax
    app->getMemory<x86::reg32>(x86::reg32(11010052) /* 0xa80004 */) = cpu.eax;
    // 00a77af1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00a77af7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a77afa  a30000a800             -mov dword ptr [0xa80000], eax
    app->getMemory<x86::reg32>(x86::reg32(11010048) /* 0xa80000 */) = cpu.eax;
    // 00a77aff  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00a77b02:
    // 00a77b02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77b04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77b05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77b06  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77b07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77b08  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77b10(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77b11  833df00da80000         +cmp dword ptr [0xa80df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77b18  7421                   -je 0xa77b3b
    if (cpu.flags.zf)
    {
        goto L_0x00a77b3b;
    }
    // 00a77b1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a77b1c  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a77b1e  8a9b010ea800           -mov bl, byte ptr [ebx + 0xa80e01]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a77b24  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a77b27  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a77b2d  740c                   -je 0xa77b3b
    if (cpu.flags.zf)
    {
        goto L_0x00a77b3b;
    }
    // 00a77b2f  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a77b31  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00a77b33  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a77b36  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 00a77b39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77b3a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77b3b:
    // 00a77b3b  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 00a77b3d  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 00a77b3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77b40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77b50(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77b50  833df00da80000         +cmp dword ptr [0xa80df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77b57  741c                   -je 0xa77b75
    if (cpu.flags.zf)
    {
        goto L_0x00a77b75;
    }
    // 00a77b59  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00a77b5b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a77b60  8a80010ea800           -mov al, byte ptr [eax + 0xa80e01]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a77b66  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a77b68  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a77b6d  7406                   -je 0xa77b75
    if (cpu.flags.zf)
    {
        goto L_0x00a77b75;
    }
    // 00a77b6f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00a77b74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77b75:
    // 00a77b75  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a77b7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void sub_a77b80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77b81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77b82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77b83  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a77b86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00a77b88:
    // 00a77b88  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a77b8a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a77b8c  e84fe1ffff             -call 0xa75ce0
    cpu.esp -= 4;
    sub_a75ce0(app, cpu);
    if (cpu.terminate) return;
    // 00a77b91  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77b93  7531                   -jne 0xa77bc6
    if (!cpu.flags.zf)
    {
        goto L_0x00a77bc6;
    }
    // 00a77b95  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a77b97  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a77b99  e822230000             -call 0xa79ec0
    cpu.esp -= 4;
    sub_a79ec0(app, cpu);
    if (cpu.terminate) return;
    // 00a77b9e  e85d230000             -call 0xa79f00
    cpu.esp -= 4;
    sub_a79f00(app, cpu);
    if (cpu.terminate) return;
    // 00a77ba3  e8c8230000             -call 0xa79f70
    cpu.esp -= 4;
    sub_a79f70(app, cpu);
    if (cpu.terminate) return;
    // 00a77ba8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a77baa  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 00a77bac  e89fffffff             -call 0xa77b50
    cpu.esp -= 4;
    sub_a77b50(app, cpu);
    if (cpu.terminate) return;
    // 00a77bb1  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 00a77bb4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a77bb6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a77bb8  e853ffffff             -call 0xa77b10
    cpu.esp -= 4;
    sub_a77b10(app, cpu);
    if (cpu.terminate) return;
    // 00a77bbd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a77bbf  e8bce1ffff             -call 0xa75d80
    cpu.esp -= 4;
    sub_a75d80(app, cpu);
    if (cpu.terminate) return;
    // 00a77bc4  ebc2                   -jmp 0xa77b88
    goto L_0x00a77b88;
L_0x00a77bc6:
    // 00a77bc6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a77bc8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00a77bcb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77bcc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77bcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77bce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a77bd0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77bd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77bd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77bd2  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a77bd4  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a77bd6  7541                   -jne 0xa77c19
    if (!cpu.flags.zf)
    {
        goto L_0x00a77c19;
    }
    // 00a77bd8  833df00da80000         +cmp dword ptr [0xa80df0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(11013616) /* 0xa80df0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77bdf  741f                   -je 0xa77c00
    if (cpu.flags.zf)
    {
        goto L_0x00a77c00;
    }
    // 00a77be1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a77be3  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a77be5  8a9b010ea800           -mov bl, byte ptr [ebx + 0xa80e01]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(11013633) /* 0xa80e01 */);
    // 00a77beb  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00a77bee  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00a77bf4  740a                   -je 0xa77c00
    if (cpu.flags.zf)
    {
        goto L_0x00a77c00;
    }
    // 00a77bf6  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a77bf9  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00a77bfc  38cb                   +cmp bl, cl
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
    // 00a77bfe  7505                   -jne 0xa77c05
    if (!cpu.flags.zf)
    {
        goto L_0x00a77c05;
    }
L_0x00a77c00:
    // 00a77c00  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77c02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77c05:
    // 00a77c05  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 00a77c07  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a77c0c  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00a77c0e  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a77c14  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a77c16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77c19:
    // 00a77c19  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a77c1b  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a77c1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77c1f  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 00a77c21  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77c23  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a77c25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77c30(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77c32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77c33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a77c35  f6400d20               +test byte ptr [eax + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 00a77c39  7522                   -jne 0xa77c5d
    if (!cpu.flags.zf)
    {
        goto L_0x00a77c5d;
    }
    // 00a77c3b  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a77c3e  e84d230000             -call 0xa79f90
    cpu.esp -= 4;
    sub_a79f90(app, cpu);
    if (cpu.terminate) return;
    // 00a77c43  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77c45  7416                   -je 0xa77c5d
    if (cpu.flags.zf)
    {
        goto L_0x00a77c5d;
    }
    // 00a77c47  8a5a0d                 -mov bl, byte ptr [edx + 0xd]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 00a77c4a  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 00a77c4d  885a0d                 -mov byte ptr [edx + 0xd], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 00a77c50  f6c307                 +test bl, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 7 /*0x7*/));
    // 00a77c53  7508                   -jne 0xa77c5d
    if (!cpu.flags.zf)
    {
        goto L_0x00a77c5d;
    }
    // 00a77c55  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 00a77c57  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 00a77c5a  884a0d                 -mov byte ptr [edx + 0xd], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.cl;
L_0x00a77c5d:
    // 00a77c5d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77c60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77c70(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77c70  803d54d4a70000         +cmp byte ptr [0xa7d454], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10998868) /* 0xa7d454 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a77c77  741a                   -je 0xa77c93
    if (cpu.flags.zf)
    {
        goto L_0x00a77c93;
    }
    // 00a77c79  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00a77c7f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77c80  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00a77c81  cc                     -int3 
    NFS2_ASSERT(false);
    // 00a77c82  eb06                   -jmp 0xa77c8a
    goto L_0x00a77c8a;
    // 00a77c84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77c85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77c86  49                     -dec ecx
    (cpu.ecx)--;
    // 00a77c87  44                     -inc esp
    (cpu.esp)++;
    // 00a77c88  45                     -inc ebp
    (cpu.ebp)++;
    // 00a77c89  4f                     -dec edi
    (cpu.edi)--;
L_0x00a77c8a:
    // 00a77c8a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a77c8f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00a77c92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77c93:
    // 00a77c93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77c95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77ca0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77ca0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77ca1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77ca2  2eff15c8bda700         -call dword ptr cs:[0xa7bdc8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993096) /* 0xa7bdc8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77ca9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77caa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77cab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void sub_a77cb0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77cb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77cb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77cb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77cb4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a77cb5  81ec28020000           -sub esp, 0x228
    (cpu.esp) -= x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a77cbb  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77cc1  bd70e3a700             -mov ebp, 0xa7e370
    cpu.ebp = 11002736 /*0xa7e370*/;
    // 00a77cc6  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00a77cc9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a77ccb:
    // 00a77ccb  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a77cd2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00a77cd4  e87fe4ffff             -call 0xa76158
    cpu.esp -= 4;
    sub_a76158(app, cpu);
    if (cpu.terminate) return;
    // 00a77cd9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a77cde  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a77ce5  41                     -inc ecx
    (cpu.ecx)++;
    // 00a77ce6  e815230000             -call 0xa7a000
    cpu.esp -= 4;
    sub_a7a000(app, cpu);
    if (cpu.terminate) return;
    // 00a77ceb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77ced  74dc                   -je 0xa77ccb
    if (cpu.flags.zf)
    {
        goto L_0x00a77ccb;
    }
    // 00a77cef  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a77cf6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a77cf8  e8ab250000             -call 0xa7a2a8
    cpu.esp -= 4;
    sub_a7a2a8(app, cpu);
    if (cpu.terminate) return;
    // 00a77cfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77cff  751b                   -jne 0xa77d1c
    if (!cpu.flags.zf)
    {
        goto L_0x00a77d1c;
    }
    // 00a77d01  e8ba260000             -call 0xa7a3c0
    cpu.esp -= 4;
    sub_a7a3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a77d06  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77d09  740a                   -je 0xa77d15
    if (cpu.flags.zf)
    {
        goto L_0x00a77d15;
    }
    // 00a77d0b  e8b0260000             -call 0xa7a3c0
    cpu.esp -= 4;
    sub_a7a3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a77d10  833806                 +cmp dword ptr [eax], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77d13  75b6                   -jne 0xa77ccb
    if (!cpu.flags.zf)
    {
        goto L_0x00a77ccb;
    }
L_0x00a77d15:
    // 00a77d15  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a77d17  e998000000             -jmp 0xa77db4
    goto L_0x00a77db4;
L_0x00a77d1c:
    // 00a77d1c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a77d1e  e8cde3ffff             -call 0xa760f0
    cpu.esp -= 4;
    sub_a760f0(app, cpu);
    if (cpu.terminate) return;
    // 00a77d23  8a1d68d1a700           -mov bl, byte ptr [0xa7d168]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(10998120) /* 0xa7d168 */);
L_0x00a77d29:
    // 00a77d29  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a77d2b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a77d2d  e826e4ffff             -call 0xa76158
    cpu.esp -= 4;
    sub_a76158(app, cpu);
    if (cpu.terminate) return;
    // 00a77d32  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00a77d34  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a77d3b  e8a0260000             -call 0xa7a3e0
    cpu.esp -= 4;
    sub_a7a3e0(app, cpu);
    if (cpu.terminate) return;
    // 00a77d40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77d42  7551                   -jne 0xa77d95
    if (!cpu.flags.zf)
    {
        goto L_0x00a77d95;
    }
    // 00a77d44  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00a77d46  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00a77d48  e85b250000             -call 0xa7a2a8
    cpu.esp -= 4;
    sub_a7a2a8(app, cpu);
    if (cpu.terminate) return;
    // 00a77d4d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a77d4f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77d51  742a                   -je 0xa77d7d
    if (cpu.flags.zf)
    {
        goto L_0x00a77d7d;
    }
    // 00a77d53  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 00a77d56  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00a77d59  88620d                 -mov byte ptr [edx + 0xd], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 00a77d5c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a77d5f  885814                 -mov byte ptr [eax + 0x14], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.bl;
    // 00a77d62  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00a77d64  881d68d1a700           -mov byte ptr [0xa7d168], bl
    app->getMemory<x86::reg8>(x86::reg32(10998120) /* 0xa7d168 */) = cpu.bl;
    // 00a77d6a  e851e6ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a77d6f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a77d71  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a77d77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77d7d:
    // 00a77d7d  e83e260000             -call 0xa7a3c0
    cpu.esp -= 4;
    sub_a7a3c0(app, cpu);
    if (cpu.terminate) return;
    // 00a77d82  83380b                 +cmp dword ptr [eax], 0xb
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11 /*0xb*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77d85  750e                   -jne 0xa77d95
    if (!cpu.flags.zf)
    {
        goto L_0x00a77d95;
    }
    // 00a77d87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77d89  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a77d8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d91  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d92  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77d94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77d95:
    // 00a77d95  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00a77d9a  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00a77da1  43                     -inc ebx
    (cpu.ebx)++;
    // 00a77da2  e859220000             -call 0xa7a000
    cpu.esp -= 4;
    sub_a7a000(app, cpu);
    if (cpu.terminate) return;
    // 00a77da7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77da9  0f851cffffff           -jne 0xa77ccb
    if (!cpu.flags.zf)
    {
        goto L_0x00a77ccb;
    }
    // 00a77daf  e975ffffff             -jmp 0xa77d29
    goto L_0x00a77d29;
L_0x00a77db4:
    // 00a77db4  81c428020000           -add esp, 0x228
    (cpu.esp) += x86::reg32(x86::sreg32(552 /*0x228*/));
    // 00a77dba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77dbb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77dbc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77dbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77dbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77dbf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a77dc0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77dc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77dc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77dc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77dc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77dc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77dc5  803d6cd4a70000         +cmp byte ptr [0xa7d46c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10998892) /* 0xa7d46c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a77dcc  0f85ab000000           -jne 0xa77e7d
    if (!cpu.flags.zf)
    {
        goto L_0x00a77e7d;
    }
    // 00a77dd2  bb58d4a700             -mov ebx, 0xa7d458
    cpu.ebx = 10998872 /*0xa7d458*/;
    // 00a77dd7  eb39                   -jmp 0xa77e12
    goto L_0x00a77e12;
L_0x00a77dd9:
    // 00a77dd9  e8d2bcffff             -call 0xa73ab0
    cpu.esp -= 4;
    sub_a73ab0(app, cpu);
    if (cpu.terminate) return;
    // 00a77dde  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a77de0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77de2  742b                   -je 0xa77e0f
    if (cpu.flags.zf)
    {
        goto L_0x00a77e0f;
    }
    // 00a77de4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a77de6  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a77de7  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a77de9  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a77deb  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a77ded  49                     -dec ecx
    (cpu.ecx)--;
    // 00a77dee  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a77df0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a77df2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a77df4  49                     -dec ecx
    (cpu.ecx)--;
    // 00a77df5  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a77df6  81f903010000           +cmp ecx, 0x103
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(259 /*0x103*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77dfc  7711                   -ja 0xa77e0f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00a77e0f;
    }
    // 00a77dfe  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 00a77e03  b86cd4a700             -mov eax, 0xa7d46c
    cpu.eax = 10998892 /*0xa7d46c*/;
    // 00a77e08  e8f3250000             -call 0xa7a400
    cpu.esp -= 4;
    sub_a7a400(app, cpu);
    if (cpu.terminate) return;
    // 00a77e0d  eb0a                   -jmp 0xa77e19
    goto L_0x00a77e19;
L_0x00a77e0f:
    // 00a77e0f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00a77e12:
    // 00a77e12  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a77e14  803800                 +cmp byte ptr [eax], 0
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
    // 00a77e17  75c0                   -jne 0xa77dd9
    if (!cpu.flags.zf)
    {
        goto L_0x00a77dd9;
    }
L_0x00a77e19:
    // 00a77e19  803d6cd4a70000         +cmp byte ptr [0xa7d46c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10998892) /* 0xa7d46c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a77e20  752a                   -jne 0xa77e4c
    if (!cpu.flags.zf)
    {
        goto L_0x00a77e4c;
    }
    // 00a77e22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a77e24  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77e26  bf6cd4a700             -mov edi, 0xa7d46c
    cpu.edi = 10998892 /*0xa7d46c*/;
    // 00a77e2b  e880260000             -call 0xa7a4b0
    cpu.esp -= 4;
    sub_a7a4b0(app, cpu);
    if (cpu.terminate) return;
    // 00a77e30  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a77e32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00a77e33:
    // 00a77e33  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00a77e35  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00a77e37  3c00                   +cmp al, 0
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
    // 00a77e39  7410                   -je 0xa77e4b
    if (cpu.flags.zf)
    {
        goto L_0x00a77e4b;
    }
    // 00a77e3b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00a77e3e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a77e41  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00a77e44  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a77e47  3c00                   +cmp al, 0
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
    // 00a77e49  75e8                   -jne 0xa77e33
    if (!cpu.flags.zf)
    {
        goto L_0x00a77e33;
    }
L_0x00a77e4b:
    // 00a77e4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00a77e4c:
    // 00a77e4c  bf6cd4a700             -mov edi, 0xa7d46c
    cpu.edi = 10998892 /*0xa7d46c*/;
    // 00a77e51  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a77e52  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a77e54  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a77e56  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a77e58  49                     -dec ecx
    (cpu.ecx)--;
    // 00a77e59  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00a77e5b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00a77e5d  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00a77e5f  49                     -dec ecx
    (cpu.ecx)--;
    // 00a77e60  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a77e61  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00a77e64  056cd4a700             -add eax, 0xa7d46c
    (cpu.eax) += x86::reg32(x86::sreg32(10998892 /*0xa7d46c*/));
    // 00a77e69  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 00a77e6b  80fb5c                 +cmp bl, 0x5c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a77e6e  740d                   -je 0xa77e7d
    if (cpu.flags.zf)
    {
        goto L_0x00a77e7d;
    }
    // 00a77e70  80fb2f                 +cmp bl, 0x2f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a77e73  7408                   -je 0xa77e7d
    if (cpu.flags.zf)
    {
        goto L_0x00a77e7d;
    }
    // 00a77e75  40                     -inc eax
    (cpu.eax)++;
    // 00a77e76  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 00a77e79  40                     -inc eax
    (cpu.eax)++;
    // 00a77e7a  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00a77e7d:
    // 00a77e7d  b86cd4a700             -mov eax, 0xa7d46c
    cpu.eax = 10998892 /*0xa7d46c*/;
    // 00a77e82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77e83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77e84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77e85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77e86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77e87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77e90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77e90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77e91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77e92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77e93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77e94  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a77e96  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 00a77e9a  740d                   -je 0xa77ea9
    if (cpu.flags.zf)
    {
        goto L_0x00a77ea9;
    }
    // 00a77e9c  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a77ea0  7407                   -je 0xa77ea9
    if (cpu.flags.zf)
    {
        goto L_0x00a77ea9;
    }
    // 00a77ea2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a77ea4  e817bdffff             -call 0xa73bc0
    cpu.esp -= 4;
    sub_a73bc0(app, cpu);
    if (cpu.terminate) return;
L_0x00a77ea9:
    // 00a77ea9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a77eac  e89f260000             -call 0xa7a550
    cpu.esp -= 4;
    sub_a7a550(app, cpu);
    if (cpu.terminate) return;
    // 00a77eb1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a77eb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00a77eb5  83f8ff                 +cmp eax, -1
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
    // 00a77eb8  742a                   -je 0xa77ee4
    if (cpu.flags.zf)
    {
        goto L_0x00a77ee4;
    }
    // 00a77eba  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a77ebd  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77ec3  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00a77ec6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00a77ec8  740f                   -je 0xa77ed9
    if (cpu.flags.zf)
    {
        goto L_0x00a77ed9;
    }
    // 00a77eca  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 00a77ece  7405                   -je 0xa77ed5
    if (cpu.flags.zf)
    {
        goto L_0x00a77ed5;
    }
    // 00a77ed0  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 00a77ed3  eb04                   -jmp 0xa77ed9
    goto L_0x00a77ed9;
L_0x00a77ed5:
    // 00a77ed5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a77ed7  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x00a77ed9:
    // 00a77ed9  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00a77edc  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77ee2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00a77ee4:
    // 00a77ee4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77ee5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77ee6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77ee7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77ee8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77ef0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77ef3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a77ef4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77ef5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a77ef6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a77ef8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77efa  7c08                   -jl 0xa77f04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00a77f04;
    }
    // 00a77efc  3b0570d5a700           +cmp eax, dword ptr [0xa7d570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10999152) /* 0xa7d570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77f02  7611                   -jbe 0xa77f15
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a77f15;
    }
L_0x00a77f04:
    // 00a77f04  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a77f09  e8b2e4ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a77f0e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a77f13  eb61                   -jmp 0xa77f76
    goto L_0x00a77f76;
L_0x00a77f15:
    // 00a77f15  8b1588d3a700           -mov edx, dword ptr [0xa7d388]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10998664) /* 0xa7d388 */);
    // 00a77f1b  8b2decd2a700           -mov ebp, dword ptr [0xa7d2ec]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(10998508) /* 0xa7d2ec */);
    // 00a77f21  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00a77f23  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00a77f25  8b3c9a                 -mov edi, dword ptr [edx + ebx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4);
    // 00a77f28  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00a77f2a  741e                   -je 0xa77f4a
    if (cpu.flags.zf)
    {
        goto L_0x00a77f4a;
    }
    // 00a77f2c  ff15e0d2a700           -call dword ptr [0xa7d2e0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998496) /* 0xa7d2e0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77f32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a77f34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77f36  7412                   -je 0xa77f4a
    if (cpu.flags.zf)
    {
        goto L_0x00a77f4a;
    }
    // 00a77f38  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a77f3a  ff15e4d2a700           -call dword ptr [0xa7d2e4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998500) /* 0xa7d2e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77f40  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a77f42  ff15ecd2a700           -call dword ptr [0xa7d2ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998508) /* 0xa7d2ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77f48  eb21                   -jmp 0xa77f6b
    goto L_0x00a77f6b;
L_0x00a77f4a:
    // 00a77f4a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a77f4c  751d                   -jne 0xa77f6b
    if (!cpu.flags.zf)
    {
        goto L_0x00a77f6b;
    }
    // 00a77f4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a77f4f  2eff1588bda700         -call dword ptr cs:[0xa7bd88]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993032) /* 0xa7bd88 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a77f56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77f58  7511                   -jne 0xa77f6b
    if (!cpu.flags.zf)
    {
        goto L_0x00a77f6b;
    }
    // 00a77f5a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a77f5f  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 00a77f64  e857e4ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a77f69  eb09                   -jmp 0xa77f74
    goto L_0x00a77f74;
L_0x00a77f6b:
    // 00a77f6b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a77f6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a77f6f  e874000000             -call 0xa77fe8
    cpu.esp -= 4;
    sub_a77fe8(app, cpu);
    if (cpu.terminate) return;
L_0x00a77f74:
    // 00a77f74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x00a77f76:
    // 00a77f76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77f77  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77f78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77f79  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77f7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77f7b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77f7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a77f80(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77f80  e92b260000             -jmp 0xa7a5b0
    return sub_a7a5b0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a77f90(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77f90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77f91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a77f92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a77f93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a77f95  3b0570d5a700           +cmp eax, dword ptr [0xa7d570]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(10999152) /* 0xa7d570 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a77f9b  7206                   -jb 0xa77fa3
    if (cpu.flags.cf)
    {
        goto L_0x00a77fa3;
    }
    // 00a77f9d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a77f9f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77fa0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77fa1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77fa2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77fa3:
    // 00a77fa3  83f803                 +cmp eax, 3
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
    // 00a77fa6  7d33                   -jge 0xa77fdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00a77fdb;
    }
    // 00a77fa8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00a77faf  a1c4d5a700             -mov eax, dword ptr [0xa7d5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999236) /* 0xa7d5c4 */);
    // 00a77fb4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00a77fb6  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00a77fb9  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 00a77fbc  751d                   -jne 0xa77fdb
    if (!cpu.flags.zf)
    {
        goto L_0x00a77fdb;
    }
    // 00a77fbe  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 00a77fc0  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a77fc3  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 00a77fc6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a77fc8  e8c31f0000             -call 0xa79f90
    cpu.esp -= 4;
    sub_a79f90(app, cpu);
    if (cpu.terminate) return;
    // 00a77fcd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a77fcf  740a                   -je 0xa77fdb
    if (cpu.flags.zf)
    {
        goto L_0x00a77fdb;
    }
    // 00a77fd1  a1c4d5a700             -mov eax, dword ptr [0xa7d5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999236) /* 0xa7d5c4 */);
    // 00a77fd6  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x00a77fdb:
    // 00a77fdb  a1c4d5a700             -mov eax, dword ptr [0xa7d5c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999236) /* 0xa7d5c4 */);
    // 00a77fe0  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 00a77fe3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77fe4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77fe5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77fe6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a77fe8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a77fe8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a77fe9  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00a77fec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a77fee  740e                   -je 0xa77ffe
    if (cpu.flags.zf)
    {
        goto L_0x00a77ffe;
    }
    // 00a77ff0  8b1dc4d5a700           -mov ebx, dword ptr [0xa7d5c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10999236) /* 0xa7d5c4 */);
    // 00a77ff6  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00a77ff9  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a77ffc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a77ffd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a77ffe:
    // 00a77ffe  8b1dc4d5a700           -mov ebx, dword ptr [0xa7d5c4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(10999236) /* 0xa7d5c4 */);
    // 00a78004  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00a78007  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78008  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a78010(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78010  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a78012  7504                   -jne 0xa78018
    if (!cpu.flags.zf)
    {
        goto L_0x00a78018;
    }
    // 00a78014  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a78016:
    // 00a78016  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a78017  90                     -nop 
    ;
L_0x00a78018:
    // 00a78018  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7801a  74fa                   -je 0xa78016
    if (cpu.flags.zf)
    {
        goto L_0x00a78016;
    }
    // 00a7801c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7801d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7801f  e8e4e3ffff             -call 0xa76408
    cpu.esp -= 4;
    sub_a76408(app, cpu);
    if (cpu.terminate) return;
    // 00a78024  83fa7b                 +cmp edx, 0x7b
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
    // 00a78027  7507                   -jne 0xa78030
    if (!cpu.flags.zf)
    {
        goto L_0x00a78030;
    }
    // 00a78029  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7802e  eb45                   -jmp 0xa78075
    goto L_0x00a78075;
L_0x00a78030:
    // 00a78030  81face000000           +cmp edx, 0xce
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
    // 00a78036  7511                   -jne 0xa78049
    if (!cpu.flags.zf)
    {
        goto L_0x00a78049;
    }
    // 00a78038  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a7803d  e87ee3ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a78042  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a78047  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78049:
    // 00a78049  81fab7000000           +cmp edx, 0xb7
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
    // 00a7804f  7511                   -jne 0xa78062
    if (!cpu.flags.zf)
    {
        goto L_0x00a78062;
    }
    // 00a78051  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a78056  e865e3ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7805b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a78060  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78061  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78062:
    // 00a78062  83fa13                 +cmp edx, 0x13
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
    // 00a78065  7605                   -jbe 0xa7806c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7806c;
    }
    // 00a78067  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a7806c:
    // 00a7806c  8b82c5d5a700           -mov eax, dword ptr [edx + 0xa7d5c5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10999237) /* 0xa7d5c5 */);
    // 00a78072  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a78075:
    // 00a78075  e846e3ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7807a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7807f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a7801c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00a7801c;
    // 00a78010  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a78012  7504                   -jne 0xa78018
    if (!cpu.flags.zf)
    {
        goto L_0x00a78018;
    }
    // 00a78014  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00a78016:
    // 00a78016  c3                     -ret 
    cpu.esp += 4;
    return;
    // 00a78017  90                     -nop 
    ;
L_0x00a78018:
    // 00a78018  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a7801a  74fa                   -je 0xa78016
    if (cpu.flags.zf)
    {
        goto L_0x00a78016;
    }
L_entry_0x00a7801c:
    // 00a7801c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7801d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7801f  e8e4e3ffff             -call 0xa76408
    cpu.esp -= 4;
    sub_a76408(app, cpu);
    if (cpu.terminate) return;
    // 00a78024  83fa7b                 +cmp edx, 0x7b
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
    // 00a78027  7507                   -jne 0xa78030
    if (!cpu.flags.zf)
    {
        goto L_0x00a78030;
    }
    // 00a78029  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a7802e  eb45                   -jmp 0xa78075
    goto L_0x00a78075;
L_0x00a78030:
    // 00a78030  81face000000           +cmp edx, 0xce
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
    // 00a78036  7511                   -jne 0xa78049
    if (!cpu.flags.zf)
    {
        goto L_0x00a78049;
    }
    // 00a78038  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00a7803d  e87ee3ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a78042  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a78047  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78049:
    // 00a78049  81fab7000000           +cmp edx, 0xb7
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
    // 00a7804f  7511                   -jne 0xa78062
    if (!cpu.flags.zf)
    {
        goto L_0x00a78062;
    }
    // 00a78051  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a78056  e865e3ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7805b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a78060  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78061  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78062:
    // 00a78062  83fa13                 +cmp edx, 0x13
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
    // 00a78065  7605                   -jbe 0xa7806c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7806c;
    }
    // 00a78067  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x00a7806c:
    // 00a7806c  8b82c5d5a700           -mov eax, dword ptr [edx + 0xa7d5c5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10999237) /* 0xa7d5c5 */);
    // 00a78072  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
L_0x00a78075:
    // 00a78075  e846e3ffff             -call 0xa763c0
    cpu.esp -= 4;
    sub_a763c0(app, cpu);
    if (cpu.terminate) return;
    // 00a7807a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00a7807f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a78084(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78084  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78085  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78086  2eff15e4bda700         -call dword ptr cs:[0xa7bde4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993124) /* 0xa7bde4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7808d  e88affffff             -call 0xa7801c
    cpu.esp -= 4;
    sub_a7801c(app, cpu);
    if (cpu.terminate) return;
    // 00a78092  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78093  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78094  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a780a0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a780a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a780a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a780a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a780a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a780a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a780a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a780a7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a780a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a780ab  7509                   -jne 0xa780b6
    if (!cpu.flags.zf)
    {
        goto L_0x00a780b6;
    }
    // 00a780ad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a780af  e8ccbbffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a780b4  eb62                   -jmp 0xa78118
    goto L_0x00a78118;
L_0x00a780b6:
    // 00a780b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a780b8  750d                   -jne 0xa780c7
    if (!cpu.flags.zf)
    {
        goto L_0x00a780c7;
    }
    // 00a780ba  e8b1bcffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a780bf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a780c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a780c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a780c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a780c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a780c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a780c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a780c7:
    // 00a780c7  e804250000             -call 0xa7a5d0
    cpu.esp -= 4;
    sub_a7a5d0(app, cpu);
    if (cpu.terminate) return;
    // 00a780cc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a780ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a780d0  e80b250000             -call 0xa7a5e0
    cpu.esp -= 4;
    sub_a7a5e0(app, cpu);
    if (cpu.terminate) return;
    // 00a780d5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a780d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a780d9  753b                   -jne 0xa78116
    if (!cpu.flags.zf)
    {
        goto L_0x00a78116;
    }
    // 00a780db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a780dd  e89ebbffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a780e2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a780e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a780e6  7425                   -je 0xa7810d
    if (cpu.flags.zf)
    {
        goto L_0x00a7810d;
    }
    // 00a780e8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00a780ea  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a780ec  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00a780ee  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a780ef  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a780f1  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a780f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a780f4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a780f6  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a780f9  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a780fb  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a780fd  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a78100  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a78102  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78103  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a78104  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a78106  e865bcffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7810b  eb09                   -jmp 0xa78116
    goto L_0x00a78116;
L_0x00a7810d:
    // 00a7810d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00a7810f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a78111  e8ca240000             -call 0xa7a5e0
    cpu.esp -= 4;
    sub_a7a5e0(app, cpu);
    if (cpu.terminate) return;
L_0x00a78116:
    // 00a78116  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
L_0x00a78118:
    // 00a78118  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78119  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7811a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7811b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7811c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7811d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void sub_a78120(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78121  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00a78124  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a78126  e855bbffff             -call 0xa73c80
    cpu.esp -= 4;
    sub_a73c80(app, cpu);
    if (cpu.terminate) return;
    // 00a7812b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7812d  7407                   -je 0xa78136
    if (cpu.flags.zf)
    {
        goto L_0x00a78136;
    }
    // 00a7812f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a78131  e83abaffff             -call 0xa73b70
    cpu.esp -= 4;
    sub_a73b70(app, cpu);
    if (cpu.terminate) return;
L_0x00a78136:
    // 00a78136  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78137  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a78140(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78140  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78141  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78142  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78143  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78145  e88ee9ffff             -call 0xa76ad8
    cpu.esp -= 4;
    sub_a76ad8(app, cpu);
    if (cpu.terminate) return;
    // 00a7814a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00a7814c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7814e  7410                   -je 0xa78160
    if (cpu.flags.zf)
    {
        goto L_0x00a78160;
    }
    // 00a78150  8b1590d2a700           -mov edx, dword ptr [0xa7d290]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a78156  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78157  2eff1548bea700         -call dword ptr cs:[0xa7be48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993224) /* 0xa7be48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7815e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00a78160:
    // 00a78160  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a78162  750f                   -jne 0xa78173
    if (!cpu.flags.zf)
    {
        goto L_0x00a78173;
    }
    // 00a78164  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a78169  b874e3a700             -mov eax, 0xa7e374
    cpu.eax = 11002740 /*0xa7e374*/;
    // 00a7816e  e829deffff             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a78173:
    // 00a78173  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a78175  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78176  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78177  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78178  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7817c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7817c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a7817d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7817e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7817f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78180  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a78181  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a78182  ff15c0d2a700           -call dword ptr [0xa7d2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998464) /* 0xa7d2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78188  2eff15ccbda700         -call dword ptr cs:[0xa7bdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993100) /* 0xa7bdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7818f  8b1d0013a800           -mov ebx, dword ptr [0xa81300]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(11014912) /* 0xa81300 */);
    // 00a78195  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a78197  740b                   -je 0xa781a4
    if (cpu.flags.zf)
    {
        goto L_0x00a781a4;
    }
L_0x00a78199:
    // 00a78199  3b4304                 +cmp eax, dword ptr [ebx + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a7819c  7406                   -je 0xa781a4
    if (cpu.flags.zf)
    {
        goto L_0x00a781a4;
    }
    // 00a7819e  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00a781a0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a781a2  75f5                   -jne 0xa78199
    if (!cpu.flags.zf)
    {
        goto L_0x00a78199;
    }
L_0x00a781a4:
    // 00a781a4  837b0c00               +cmp dword ptr [ebx + 0xc], 0
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
    // 00a781a8  7425                   -je 0xa781cf
    if (cpu.flags.zf)
    {
        goto L_0x00a781cf;
    }
    // 00a781aa  8b15dcd5a700           -mov edx, dword ptr [0xa7d5dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a781b0  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a781b3  e8e8feffff             -call 0xa780a0
    cpu.esp -= 4;
    sub_a780a0(app, cpu);
    if (cpu.terminate) return;
    // 00a781b8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a781ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a781bc  755e                   -jne 0xa7821c
    if (!cpu.flags.zf)
    {
        goto L_0x00a7821c;
    }
    // 00a781be  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a781c3  b89ce3a700             -mov eax, 0xa7e39c
    cpu.eax = 11002780 /*0xa7e39c*/;
    // 00a781c8  e8cfddffff             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
    // 00a781cd  eb4d                   -jmp 0xa7821c
    goto L_0x00a7821c;
L_0x00a781cf:
    // 00a781cf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a781d4  8b15dcd5a700           -mov edx, dword ptr [0xa7d5dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a781da  e841ffffff             -call 0xa78120
    cpu.esp -= 4;
    sub_a78120(app, cpu);
    if (cpu.terminate) return;
    // 00a781df  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00a781e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a781e3  750f                   -jne 0xa781f4
    if (!cpu.flags.zf)
    {
        goto L_0x00a781f4;
    }
    // 00a781e5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00a781ea  b8c4e3a700             -mov eax, 0xa7e3c4
    cpu.eax = 11002820 /*0xa7e3c4*/;
    // 00a781ef  e8a8ddffff             -call 0xa75f9c
    cpu.esp -= 4;
    sub_a75f9c(app, cpu);
    if (cpu.terminate) return;
L_0x00a781f4:
    // 00a781f4  8b7308                 -mov esi, dword ptr [ebx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 00a781f7  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00a781f9  8b8ef0000000           -mov ecx, dword ptr [esi + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 00a781ff  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a78200  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a78202  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a78204  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a78205  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a78207  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a7820a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a7820c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a7820e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a78211  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a78213  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78214  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a78215  c7430c01000000         -mov dword ptr [ebx + 0xc], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x00a7821c:
    // 00a7821c  896b08                 -mov dword ptr [ebx + 8], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00a7821f  a1dcd5a700             -mov eax, dword ptr [0xa7d5dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a78224  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00a78225  c6455201               -mov byte ptr [ebp + 0x52], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 00a78229  8b3590d2a700           -mov esi, dword ptr [0xa7d290]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(10998416) /* 0xa7d290 */);
    // 00a7822f  c6455300               -mov byte ptr [ebp + 0x53], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(83) /* 0x53 */) = 0 /*0x0*/;
    // 00a78233  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78234  8985f0000000           -mov dword ptr [ebp + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00a7823a  2eff154cbea700         -call dword ptr cs:[0xa7be4c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993228) /* 0xa7be4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78241  ff15c4d2a700           -call dword ptr [0xa7d2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998468) /* 0xa7d2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78247  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00a78249  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7824a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7824b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7824c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7824d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7824e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7824f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78250(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78251  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78252  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a78253  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00a78255  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00a78257  ff15c0d2a700           -call dword ptr [0xa7d2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998464) /* 0xa7d2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7825d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00a78262  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00a78267  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a78269  e8b2feffff             -call 0xa78120
    cpu.esp -= 4;
    sub_a78120(app, cpu);
    if (cpu.terminate) return;
    // 00a7826e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a78270  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78272  742f                   -je 0xa782a3
    if (cpu.flags.zf)
    {
        goto L_0x00a782a3;
    }
    // 00a78274  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a78276  e879250000             -call 0xa7a7f4
    cpu.esp -= 4;
    sub_a7a7f4(app, cpu);
    if (cpu.terminate) return;
    // 00a7827b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7827d  7409                   -je 0xa78288
    if (cpu.flags.zf)
    {
        goto L_0x00a78288;
    }
    // 00a7827f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a78281  e8eabaffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a78286  eb1b                   -jmp 0xa782a3
    goto L_0x00a782a3;
L_0x00a78288:
    // 00a78288  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00a7828b  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00a7828e  8a4352                 -mov al, byte ptr [ebx + 0x52]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(82) /* 0x52 */);
    // 00a78291  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00a78294  a10013a800             -mov eax, dword ptr [0xa81300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11014912) /* 0xa81300 */);
    // 00a78299  89150013a800           -mov dword ptr [0xa81300], edx
    app->getMemory<x86::reg32>(x86::reg32(11014912) /* 0xa81300 */) = cpu.edx;
    // 00a7829f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00a782a1  eb02                   -jmp 0xa782a5
    goto L_0x00a782a5;
L_0x00a782a3:
    // 00a782a3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00a782a5:
    // 00a782a5  ff15c4d2a700           -call dword ptr [0xa7d2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998468) /* 0xa7d2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a782ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a782ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a782ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a782af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a782b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a782b4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a782b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a782b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a782b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a782b7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a782b9  ff15c0d2a700           -call dword ptr [0xa7d2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998464) /* 0xa7d2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a782bf  8b150013a800           -mov edx, dword ptr [0xa81300]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11014912) /* 0xa81300 */);
    // 00a782c5  b90013a800             -mov ecx, 0xa81300
    cpu.ecx = 11014912 /*0xa81300*/;
    // 00a782ca  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a782cc  7428                   -je 0xa782f6
    if (cpu.flags.zf)
    {
        goto L_0x00a782f6;
    }
L_0x00a782ce:
    // 00a782ce  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a782d1  751b                   -jne 0xa782ee
    if (!cpu.flags.zf)
    {
        goto L_0x00a782ee;
    }
    // 00a782d3  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 00a782d7  7408                   -je 0xa782e1
    if (cpu.flags.zf)
    {
        goto L_0x00a782e1;
    }
    // 00a782d9  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a782dc  e88fbaffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a782e1:
    // 00a782e1  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00a782e3  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 00a782e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a782e7  e884baffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a782ec  eb08                   -jmp 0xa782f6
    goto L_0x00a782f6;
L_0x00a782ee:
    // 00a782ee  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00a782f0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a782f2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a782f4  75d8                   -jne 0xa782ce
    if (!cpu.flags.zf)
    {
        goto L_0x00a782ce;
    }
L_0x00a782f6:
    // 00a782f6  ff15c4d2a700           -call dword ptr [0xa7d2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998468) /* 0xa7d2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a782fc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a782fd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a782fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a782ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void sub_a78300(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78300  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78301  ff15c0d2a700           -call dword ptr [0xa7d2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998464) /* 0xa7d2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78307  a10013a800             -mov eax, dword ptr [0xa81300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(11014912) /* 0xa81300 */);
    // 00a7830c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7830e  740d                   -je 0xa7831d
    if (cpu.flags.zf)
    {
        goto L_0x00a7831d;
    }
L_0x00a78310:
    // 00a78310  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00a78313  c6425301               -mov byte ptr [edx + 0x53], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(83) /* 0x53 */) = 1 /*0x1*/;
    // 00a78317  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00a78319  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7831b  75f3                   -jne 0xa78310
    if (!cpu.flags.zf)
    {
        goto L_0x00a78310;
    }
L_0x00a7831d:
    // 00a7831d  ff15c4d2a700           -call dword ptr [0xa7d2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998468) /* 0xa7d2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78323  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78324  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a78328(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78328  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78329  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7832a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7832b  8b150013a800           -mov edx, dword ptr [0xa81300]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(11014912) /* 0xa81300 */);
    // 00a78331  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00a78333  741e                   -je 0xa78353
    if (cpu.flags.zf)
    {
        goto L_0x00a78353;
    }
L_0x00a78335:
    // 00a78335  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00a78338  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 00a7833a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00a7833c  7408                   -je 0xa78346
    if (cpu.flags.zf)
    {
        goto L_0x00a78346;
    }
    // 00a7833e  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00a78341  e82abaffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
L_0x00a78346:
    // 00a78346  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a78348  e823baffff             -call 0xa73d70
    cpu.esp -= 4;
    sub_a73d70(app, cpu);
    if (cpu.terminate) return;
    // 00a7834d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00a7834f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00a78351  75e2                   -jne 0xa78335
    if (!cpu.flags.zf)
    {
        goto L_0x00a78335;
    }
L_0x00a78353:
    // 00a78353  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78354  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78355  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78356  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a78360(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78360  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78361  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78362  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a78364  ff15c0d2a700           -call dword ptr [0xa7d2c0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998464) /* 0xa7d2c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7836a  8b15dcd5a700           -mov edx, dword ptr [0xa7d5dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */);
    // 00a78370  8d041a                 -lea eax, [edx + ebx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 00a78373  a3dcd5a700             -mov dword ptr [0xa7d5dc], eax
    app->getMemory<x86::reg32>(x86::reg32(10999260) /* 0xa7d5dc */) = cpu.eax;
    // 00a78378  e883ffffff             -call 0xa78300
    cpu.esp -= 4;
    sub_a78300(app, cpu);
    if (cpu.terminate) return;
    // 00a7837d  ff15c4d2a700           -call dword ptr [0xa7d2c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998468) /* 0xa7d2c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78383  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00a78385  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78386  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78387  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a78390(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78392  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78393  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a78395  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78397  741b                   -je 0xa783b4
    if (cpu.flags.zf)
    {
        goto L_0x00a783b4;
    }
    // 00a78399  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00a7839b  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 00a783a2  e8c9eaffff             -call 0xa76e70
    cpu.esp -= 4;
    sub_a76e70(app, cpu);
    if (cpu.terminate) return;
    // 00a783a7  2eff15ccbda700         -call dword ptr cs:[0xa7bdcc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993100) /* 0xa7bdcc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a783ae  8983da000000           -mov dword ptr [ebx + 0xda], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(218) /* 0xda */) = cpu.eax;
L_0x00a783b4:
    // 00a783b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a783b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a783b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a783b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a783c0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a783c0  e963ffffff             -jmp 0xa78328
    return sub_a78328(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a783d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a783d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a783d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a783d2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a783d4  66833800               +cmp word ptr [eax], 0
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
    // 00a783d8  740c                   -je 0xa783e6
    if (cpu.flags.zf)
    {
        goto L_0x00a783e6;
    }
L_0x00a783da:
    // 00a783da  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00a783de  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00a783e1  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00a783e4  75f4                   -jne 0xa783da
    if (!cpu.flags.zf)
    {
        goto L_0x00a783da;
    }
L_0x00a783e6:
    // 00a783e6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00a783e8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00a783ea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a783eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a783ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void sub_a783f0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a783f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a783f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00a783f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a783f3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00a783f5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00a783f7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00a783f9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 00a783fa  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 00a783fc  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 00a783fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00a783ff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00a78401  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00a78404  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00a78406  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00a78408  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00a7840b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00a7840d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7840e  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 00a7840f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00a78411  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78412  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78413  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78414  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a78420(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78420  66833801               +cmp word ptr [eax], 1
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
    // 00a78424  751c                   -jne 0xa78442
    if (!cpu.flags.zf)
    {
        goto L_0x00a78442;
    }
    // 00a78426  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00a7842a  7416                   -je 0xa78442
    if (cpu.flags.zf)
    {
        goto L_0x00a78442;
    }
    // 00a7842c  668b400a               -mov ax, word ptr [eax + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00a78430  663d1000               +cmp ax, 0x10
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
    // 00a78434  7206                   -jb 0xa7843c
    if (cpu.flags.cf)
    {
        goto L_0x00a7843c;
    }
    // 00a78436  663d1200               +cmp ax, 0x12
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
    // 00a7843a  7606                   -jbe 0xa78442
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a78442;
    }
L_0x00a7843c:
    // 00a7843c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a78441  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78442:
    // 00a78442  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78444  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a78448(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78448  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a78449  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7844a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7844c  ff1598d2a700           -call dword ptr [0xa7d298]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998424) /* 0xa7d298 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78452  833de0d5a700ff         +cmp dword ptr [0xa7d5e0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10999264) /* 0xa7d5e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a78459  7523                   -jne 0xa7847e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7847e;
    }
    // 00a7845b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a7845d  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a78462  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a78464  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a78466  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a78468  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 00a7846d  68ece3a700             -push 0xa7e3ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 11002860 /*0xa7e3ec*/;
    cpu.esp -= 4;
    // 00a78472  2eff1590bda700         -call dword ptr cs:[0xa7bd90]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993040) /* 0xa7bd90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78479  a3e0d5a700             -mov dword ptr [0xa7d5e0], eax
    app->getMemory<x86::reg32>(x86::reg32(10999264) /* 0xa7d5e0 */) = cpu.eax;
L_0x00a7847e:
    // 00a7847e  833de4d5a700ff         +cmp dword ptr [0xa7d5e4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(10999268) /* 0xa7d5e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00a78485  7523                   -jne 0xa784aa
    if (!cpu.flags.zf)
    {
        goto L_0x00a784aa;
    }
    // 00a78487  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a78489  6880000000             -push 0x80
    app->getMemory<x86::reg32>(cpu.esp-4) = 128 /*0x80*/;
    cpu.esp -= 4;
    // 00a7848e  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00a78490  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a78492  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00a78494  6800000040             -push 0x40000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741824 /*0x40000000*/;
    cpu.esp -= 4;
    // 00a78499  68f4e3a700             -push 0xa7e3f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 11002868 /*0xa7e3f4*/;
    cpu.esp -= 4;
    // 00a7849e  2eff1590bda700         -call dword ptr cs:[0xa7bd90]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993040) /* 0xa7bd90 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a784a5  a3e4d5a700             -mov dword ptr [0xa7d5e4], eax
    app->getMemory<x86::reg32>(x86::reg32(10999268) /* 0xa7d5e4 */) = cpu.eax;
L_0x00a784aa:
    // 00a784aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a784ac  ff159cd2a700           -call dword ptr [0xa7d29c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998428) /* 0xa7d29c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a784b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a784b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a784b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a784b8(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a784b8  e88bffffff             -call 0xa78448
    cpu.esp -= 4;
    sub_a78448(app, cpu);
    if (cpu.terminate) return;
    // 00a784bd  a1e0d5a700             -mov eax, dword ptr [0xa7d5e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999264) /* 0xa7d5e0 */);
    // 00a784c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void sub_a784c4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a784c4  e87fffffff             -call 0xa78448
    cpu.esp -= 4;
    sub_a78448(app, cpu);
    if (cpu.terminate) return;
    // 00a784c9  a1e4d5a700             -mov eax, dword ptr [0xa7d5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999268) /* 0xa7d5e4 */);
    // 00a784ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void sub_a784d0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a784d0  dbe2                   -fnclex 
    /*nothing*/;
    // 00a784d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void sub_a784e0(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a784e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a784e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a784e2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a784e4  83f807                 +cmp eax, 7
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
    // 00a784e7  7405                   -je 0xa784ee
    if (cpu.flags.zf)
    {
        goto L_0x00a784ee;
    }
    // 00a784e9  83f804                 +cmp eax, 4
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
    // 00a784ec  7518                   -jne 0xa78506
    if (!cpu.flags.zf)
    {
        goto L_0x00a78506;
    }
L_0x00a784ee:
    // 00a784ee  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00a784f5  8b98e8d5a700           -mov ebx, dword ptr [eax + 0xa7d5e8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10999272) /* 0xa7d5e8 */);
    // 00a784fb  8990e8d5a700           -mov dword ptr [eax + 0xa7d5e8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10999272) /* 0xa7d5e8 */) = cpu.edx;
    // 00a78501  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a78503  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78504  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78505  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78506:
    // 00a78506  8d0cdd00000000         -lea ecx, [ebx*8]
    cpu.ecx = x86::reg32(cpu.ebx * 8);
    // 00a7850d  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78513  8b5c0158               -mov ebx, dword ptr [ecx + eax + 0x58]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1);
    // 00a78517  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a7851d  89540158               -mov dword ptr [ecx + eax + 0x58], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */ + cpu.eax * 1) = cpu.edx;
    // 00a78521  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a78523  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78524  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78525  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a78528(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78528  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a78529  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7852b  83f807                 +cmp eax, 7
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
    // 00a7852e  7405                   -je 0xa78535
    if (cpu.flags.zf)
    {
        goto L_0x00a78535;
    }
    // 00a78530  83f804                 +cmp eax, 4
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
    // 00a78533  7509                   -jne 0xa7853e
    if (!cpu.flags.zf)
    {
        goto L_0x00a7853e;
    }
L_0x00a78535:
    // 00a78535  8b04d5e8d5a700         -mov eax, dword ptr [edx*8 + 0xa7d5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999272) /* 0xa7d5e8 */ + cpu.edx * 8);
    // 00a7853c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7853d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a7853e:
    // 00a7853e  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78544  8b44d058               -mov eax, dword ptr [eax + edx*8 + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */ + cpu.edx * 8);
    // 00a78548  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78549  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7854c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7854c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7854d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a7854f  83f807                 +cmp eax, 7
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
    // 00a78552  7405                   -je 0xa78559
    if (cpu.flags.zf)
    {
        goto L_0x00a78559;
    }
    // 00a78554  83f804                 +cmp eax, 4
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
    // 00a78557  7509                   -jne 0xa78562
    if (!cpu.flags.zf)
    {
        goto L_0x00a78562;
    }
L_0x00a78559:
    // 00a78559  8b04d5ecd5a700         -mov eax, dword ptr [edx*8 + 0xa7d5ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(10999276) /* 0xa7d5ec */ + cpu.edx * 8);
    // 00a78560  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78561  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78562:
    // 00a78562  ff1594d2a700           -call dword ptr [0xa7d294]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(10998420) /* 0xa7d294 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78568  8b44d05c               -mov eax, dword ptr [eax + edx*8 + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */ + cpu.edx * 8);
    // 00a7856c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a7856d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a78570(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a78570  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00a78571  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00a78573  e8d4ffffff             -call 0xa7854c
    cpu.esp -= 4;
    sub_a7854c(app, cpu);
    if (cpu.terminate) return;
    // 00a78578  39c2                   +cmp edx, eax
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
    // 00a7857a  7509                   -jne 0xa78585
    if (!cpu.flags.zf)
    {
        goto L_0x00a78585;
    }
    // 00a7857c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00a7857e  e8a5ffffff             -call 0xa78528
    cpu.esp -= 4;
    sub_a78528(app, cpu);
    if (cpu.terminate) return;
    // 00a78583  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78584  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78585:
    // 00a78585  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78587  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78588  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a7858c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7858c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00a78590  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78592  760a                   -jbe 0xa7859e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00a7859e;
    }
    // 00a78594  83f801                 +cmp eax, 1
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
    // 00a78597  7424                   -je 0xa785bd
    if (cpu.flags.zf)
    {
        goto L_0x00a785bd;
    }
    // 00a78599  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a7859b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a7859e:
    // 00a7859e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a785a3  e880ffffff             -call 0xa78528
    cpu.esp -= 4;
    sub_a78528(app, cpu);
    if (cpu.terminate) return;
    // 00a785a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a785aa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a785ac  7503                   -jne 0xa785b1
    if (!cpu.flags.zf)
    {
        goto L_0x00a785b1;
    }
    // 00a785ae  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a785b1:
    // 00a785b1  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a785b6  e8dd010000             -call 0xa78798
    cpu.esp -= 4;
    sub_a78798(app, cpu);
    if (cpu.terminate) return;
    // 00a785bb  eb1d                   -jmp 0xa785da
    goto L_0x00a785da;
L_0x00a785bd:
    // 00a785bd  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a785c2  e861ffffff             -call 0xa78528
    cpu.esp -= 4;
    sub_a78528(app, cpu);
    if (cpu.terminate) return;
    // 00a785c7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a785c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a785cb  7503                   -jne 0xa785d0
    if (!cpu.flags.zf)
    {
        goto L_0x00a785d0;
    }
    // 00a785cd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a785d0:
    // 00a785d0  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a785d5  e8be010000             -call 0xa78798
    cpu.esp -= 4;
    sub_a78798(app, cpu);
    if (cpu.terminate) return;
L_0x00a785da:
    // 00a785da  83fa02                 +cmp edx, 2
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
    // 00a785dd  7405                   -je 0xa785e4
    if (cpu.flags.zf)
    {
        goto L_0x00a785e4;
    }
    // 00a785df  83fa03                 +cmp edx, 3
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
    // 00a785e2  7505                   -jne 0xa785e9
    if (!cpu.flags.zf)
    {
        goto L_0x00a785e9;
    }
L_0x00a785e4:
    // 00a785e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a785e6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00a785e9:
    // 00a785e9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a785ee  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void sub_a785f4(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a785f4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a785f5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00a785fa  e829ffffff             -call 0xa78528
    cpu.esp -= 4;
    sub_a78528(app, cpu);
    if (cpu.terminate) return;
    // 00a785ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00a78601  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00a78606  e81dffffff             -call 0xa78528
    cpu.esp -= 4;
    sub_a78528(app, cpu);
    if (cpu.terminate) return;
    // 00a7860b  83fa02                 +cmp edx, 2
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
    // 00a7860e  7405                   -je 0xa78615
    if (cpu.flags.zf)
    {
        goto L_0x00a78615;
    }
    // 00a78610  83fa03                 +cmp edx, 3
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
    // 00a78613  750a                   -jne 0xa7861f
    if (!cpu.flags.zf)
    {
        goto L_0x00a7861f;
    }
L_0x00a78615:
    // 00a78615  83f802                 +cmp eax, 2
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
    // 00a78618  740c                   -je 0xa78626
    if (cpu.flags.zf)
    {
        goto L_0x00a78626;
    }
    // 00a7861a  83f803                 +cmp eax, 3
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
    // 00a7861d  7407                   -je 0xa78626
    if (cpu.flags.zf)
    {
        goto L_0x00a78626;
    }
L_0x00a7861f:
    // 00a7861f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00a78624  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78625  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00a78626:
    // 00a78626  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78628  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78629  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7862c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7862c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7862d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7862e  803d50d6a70000         +cmp byte ptr [0xa7d650], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10999376) /* 0xa7d650 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a78635  7519                   -jne 0xa78650
    if (!cpu.flags.zf)
    {
        goto L_0x00a78650;
    }
    // 00a78637  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00a78639  688c85a700             -push 0xa7858c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10978700 /*0xa7858c*/;
    cpu.esp -= 4;
    // 00a7863e  2eff1520bea700         -call dword ptr cs:[0xa7be20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993184) /* 0xa7be20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78645  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78647  7407                   -je 0xa78650
    if (cpu.flags.zf)
    {
        goto L_0x00a78650;
    }
    // 00a78649  c60550d6a70001         -mov byte ptr [0xa7d650], 1
    app->getMemory<x86::reg8>(x86::reg32(10999376) /* 0xa7d650 */) = 1 /*0x1*/;
L_0x00a78650:
    // 00a78650  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78652  a050d6a700             -mov al, byte ptr [0xa7d650]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10999376) /* 0xa7d650 */);
    // 00a78657  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78658  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78659  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void sub_a7865c(win32::WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00a7865c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00a7865d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00a7865e  803d50d6a70000         +cmp byte ptr [0xa7d650], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(10999376) /* 0xa7d650 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00a78665  741a                   -je 0xa78681
    if (cpu.flags.zf)
    {
        goto L_0x00a78681;
    }
    // 00a78667  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00a78669  688c85a700             -push 0xa7858c
    app->getMemory<x86::reg32>(cpu.esp-4) = 10978700 /*0xa7858c*/;
    cpu.esp -= 4;
    // 00a7866e  2eff1520bea700         -call dword ptr cs:[0xa7be20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(10993184) /* 0xa7be20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00a78675  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a78677  7408                   -je 0xa78681
    if (cpu.flags.zf)
    {
        goto L_0x00a78681;
    }
    // 00a78679  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00a7867b  881550d6a700           -mov byte ptr [0xa7d650], dl
    app->getMemory<x86::reg8>(x86::reg32(10999376) /* 0xa7d650 */) = cpu.dl;
L_0x00a78681:
    // 00a78681  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00a78683  a050d6a700             -mov al, byte ptr [0xa7d650]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(10999376) /* 0xa7d650 */);
    // 00a78688  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00a7868a  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 00a7868d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00a78692  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78693  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00a78694  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
