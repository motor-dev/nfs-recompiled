#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ee90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ee90  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ee91  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ee92  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ee93  833de8d24d0001         +cmp dword ptr [0x4dd2e8], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ee9a  756b                   -jne 0x46ef07
    if (!cpu.flags.zf)
    {
        goto L_0x0046ef07;
    }
    // 0046ee9c  68f0000000             -push 0xf0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 240 /*0xf0*/;
    cpu.esp -= 4;
    // 0046eea1  6880020000             -push 0x280
    *app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 0046eea6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eea8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eeaa  68f0000000             -push 0xf0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 240 /*0xf0*/;
    cpu.esp -= 4;
    // 0046eeaf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046eeb1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046eeb3  e878000000             -call 0x46ef30
    cpu.esp -= 4;
    sub_46ef30(app, cpu);
    if (cpu.terminate) return;
    // 0046eeb8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046eeba  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
L_0x0046eebc:
    // 0046eebc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046eec1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eec3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046eec5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eec7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046eec9  e862000000             -call 0x46ef30
    cpu.esp -= 4;
    sub_46ef30(app, cpu);
    if (cpu.terminate) return;
    // 0046eece  68e0010000             -push 0x1e0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 0046eed3  6880020000             -push 0x280
    *app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 0046eed8  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0046eedd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eedf  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046eee1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eee3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046eee5  e846000000             -call 0x46ef30
    cpu.esp -= 4;
    sub_46ef30(app, cpu);
    if (cpu.terminate) return;
    // 0046eeea  6887000000             -push 0x87
    *app->getMemory<x86::reg32>(cpu.esp-4) = 135 /*0x87*/;
    cpu.esp -= 4;
    // 0046eeef  6a6c                   -push 0x6c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 108 /*0x6c*/;
    cpu.esp -= 4;
    // 0046eef1  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046eef6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eef8  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046eefa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eefc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046eefe  e82d000000             -call 0x46ef30
    cpu.esp -= 4;
    sub_46ef30(app, cpu);
    if (cpu.terminate) return;
    // 0046ef03  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ef04  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ef05  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ef06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ef07:
    // 0046ef07  68e0010000             -push 0x1e0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 0046ef0c  6880020000             -push 0x280
    *app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 0046ef11  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ef13  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ef15  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046ef17  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ef19  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046ef1b  e810000000             -call 0x46ef30
    cpu.esp -= 4;
    sub_46ef30(app, cpu);
    if (cpu.terminate) return;
    // 0046ef20  6a46                   -push 0x46
    *app->getMemory<x86::reg32>(cpu.esp-4) = 70 /*0x46*/;
    cpu.esp -= 4;
    // 0046ef22  6896000000             -push 0x96
    *app->getMemory<x86::reg32>(cpu.esp-4) = 150 /*0x96*/;
    cpu.esp -= 4;
    // 0046ef27  eb93                   -jmp 0x46eebc
    goto L_0x0046eebc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ef30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ef30  668914c5348a5100       -mov word ptr [eax*8 + 0x518a34], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343796) /* 0x518a34 */ + cpu.eax * 8) = cpu.dx;
    // 0046ef38  66891cc5368a5100       -mov word ptr [eax*8 + 0x518a36], bx
    *app->getMemory<x86::reg16>(x86::reg32(5343798) /* 0x518a36 */ + cpu.eax * 8) = cpu.bx;
    // 0046ef40  66890cc5548a5100       -mov word ptr [eax*8 + 0x518a54], cx
    *app->getMemory<x86::reg16>(x86::reg32(5343828) /* 0x518a54 */ + cpu.eax * 8) = cpu.cx;
    // 0046ef48  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ef4c  668914c5388a5100       -mov word ptr [eax*8 + 0x518a38], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343800) /* 0x518a38 */ + cpu.eax * 8) = cpu.dx;
    // 0046ef54  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ef58  668914c53a8a5100       -mov word ptr [eax*8 + 0x518a3a], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343802) /* 0x518a3a */ + cpu.eax * 8) = cpu.dx;
    // 0046ef60  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ef64  668914c5568a5100       -mov word ptr [eax*8 + 0x518a56], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343830) /* 0x518a56 */ + cpu.eax * 8) = cpu.dx;
    // 0046ef6c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ef70  668914c5588a5100       -mov word ptr [eax*8 + 0x518a58], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343832) /* 0x518a58 */ + cpu.eax * 8) = cpu.dx;
    // 0046ef78  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ef7c  668914c55a8a5100       -mov word ptr [eax*8 + 0x518a5a], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343834) /* 0x518a5a */ + cpu.eax * 8) = cpu.dx;
    // 0046ef84  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ef90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ef90  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ef91  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0046ef94  05348a5100             -add eax, 0x518a34
    (cpu.eax) += x86::reg32(x86::sreg32(5343796 /*0x518a34*/));
    // 0046ef99  0fbf30                 -movsx esi, word ptr [eax]
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(*app->getMemory<x86::reg16>(cpu.eax)));
    // 0046ef9c  8932                   -mov dword ptr [edx], esi
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 0046ef9e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0046efa0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046efa3  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0046efa5  8b5002                 -mov edx, dword ptr [eax + 2]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0046efa8  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046efab  8911                   -mov dword ptr [ecx], edx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0046efad  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046efb0  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046efb4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046efb7  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0046efb9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046efba  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46efc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046efc0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046efc1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046efc2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046efc3  a10c955100             -mov eax, dword ptr [0x51950c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346572) /* 0x51950c */);
    // 0046efc8  8a144554814c00         -mov dl, byte ptr [eax*2 + 0x4c8154]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5013844) /* 0x4c8154 */ + cpu.eax * 2);
    // 0046efcf  88154c955100           -mov byte ptr [0x51954c], dl
    *app->getMemory<x86::reg8>(x86::reg32(5346636) /* 0x51954c */) = cpu.dl;
    // 0046efd5  8a044555814c00         -mov al, byte ptr [eax*2 + 0x4c8155]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5013845) /* 0x4c8155 */ + cpu.eax * 2);
    // 0046efdc  8b15e8d24d00           -mov edx, dword ptr [0x4dd2e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
    // 0046efe2  a24d955100             -mov byte ptr [0x51954d], al
    *app->getMemory<x86::reg8>(x86::reg32(5346637) /* 0x51954d */) = cpu.al;
    // 0046efe7  83fa01                 +cmp edx, 1
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
    // 0046efea  7549                   -jne 0x46f035
    if (!cpu.flags.zf)
    {
        goto L_0x0046f035;
    }
    // 0046efec  a110955100             -mov eax, dword ptr [0x519510]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046eff1  8a0d4c955100           -mov cl, byte ptr [0x51954c]
    cpu.cl = *app->getMemory<x86::reg8>(x86::reg32(5346636) /* 0x51954c */);
    // 0046eff7  8b14c53c814c00         -mov edx, dword ptr [eax*8 + 0x4c813c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5013820) /* 0x4c813c */ + cpu.eax * 8);
    // 0046effe  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 0046f000  668915588a5100         -mov word ptr [0x518a58], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343832) /* 0x518a58 */) = cpu.dx;
    // 0046f007  8a154d955100           -mov dl, byte ptr [0x51954d]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5346637) /* 0x51954d */);
    // 0046f00d  fec2                   -inc dl
    (cpu.dl)++;
    // 0046f00f  8b04c540814c00         -mov eax, dword ptr [eax*8 + 0x4c8140]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5013824) /* 0x4c8140 */ + cpu.eax * 8);
    // 0046f016  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0046f018  88154d955100           -mov byte ptr [0x51954d], dl
    *app->getMemory<x86::reg8>(x86::reg32(5346637) /* 0x51954d */) = cpu.dl;
    // 0046f01e  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0046f020  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f022  66a35a8a5100           -mov word ptr [0x518a5a], ax
    *app->getMemory<x86::reg16>(x86::reg32(5343834) /* 0x518a5a */) = cpu.ax;
    // 0046f028  668915548a5100         -mov word ptr [0x518a54], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343828) /* 0x518a54 */) = cpu.dx;
    // 0046f02f  66a3568a5100           -mov word ptr [0x518a56], ax
    *app->getMemory<x86::reg16>(x86::reg32(5343830) /* 0x518a56 */) = cpu.ax;
L_0x0046f035:
    // 0046f035  a110955100             -mov eax, dword ptr [0x519510]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046f03a  8a0d4c955100           -mov cl, byte ptr [0x51954c]
    cpu.cl = *app->getMemory<x86::reg8>(x86::reg32(5346636) /* 0x51954c */);
    // 0046f040  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f042  8b14c53c814c00         -mov edx, dword ptr [eax*8 + 0x4c813c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5013820) /* 0x4c813c */ + cpu.eax * 8);
    // 0046f049  8b04c540814c00         -mov eax, dword ptr [eax*8 + 0x4c8140]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5013824) /* 0x4c8140 */ + cpu.eax * 8);
    // 0046f050  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 0046f052  8a0d4d955100           -mov cl, byte ptr [0x51954d]
    cpu.cl = *app->getMemory<x86::reg8>(x86::reg32(5346637) /* 0x51954d */);
    // 0046f058  668915388a5100         -mov word ptr [0x518a38], dx
    *app->getMemory<x86::reg16>(x86::reg32(5343800) /* 0x518a38 */) = cpu.dx;
    // 0046f05f  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 0046f061  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f063  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 0046f065  8a154c955100           -mov dl, byte ptr [0x51954c]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5346636) /* 0x51954c */);
    // 0046f06b  66a33a8a5100           -mov word ptr [0x518a3a], ax
    *app->getMemory<x86::reg16>(x86::reg32(5343802) /* 0x518a3a */) = cpu.ax;
    // 0046f071  a110955100             -mov eax, dword ptr [0x519510]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046f076  e805400000             -call 0x473080
    cpu.esp -= 4;
    sub_473080(app, cpu);
    if (cpu.terminate) return;
    // 0046f07b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f07c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f07d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f07e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46f080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f080  833d1095510000         +cmp dword ptr [0x519510], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f087  7506                   -jne 0x46f08f
    if (!cpu.flags.zf)
    {
        goto L_0x0046f08f;
    }
    // 0046f089  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046f08e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f08f:
    // 0046f08f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f091  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f0a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f0a0  a110955100             -mov eax, dword ptr [0x519510]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046f0a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f0b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f0b0  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f0b1  833de8d24d0001         +cmp dword ptr [0x4dd2e8], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100264) /* 0x4dd2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0b8  7425                   -je 0x46f0df
    if (cpu.flags.zf)
    {
        goto L_0x0046f0df;
    }
    // 0046f0ba  833d70d14d0000         +cmp dword ptr [0x4dd170], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5099888) /* 0x4dd170 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0c1  751e                   -jne 0x46f0e1
    if (!cpu.flags.zf)
    {
        goto L_0x0046f0e1;
    }
L_0x0046f0c3:
    // 0046f0c3  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0046f0c8  a110955100             -mov eax, dword ptr [0x519510]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */);
    // 0046f0cd  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046f0cf  892d14955100           -mov dword ptr [0x519514], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */) = cpu.ebp;
    // 0046f0d5  a310955100             -mov dword ptr [0x519510], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */) = cpu.eax;
    // 0046f0da  83f803                 +cmp eax, 3
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
    // 0046f0dd  7d27                   -jge 0x46f106
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046f106;
    }
L_0x0046f0df:
    // 0046f0df  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f0e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f0e1:
    // 0046f0e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f0e3  e8488dfcff             -call 0x437e30
    cpu.esp -= 4;
    sub_437e30(app, cpu);
    if (cpu.terminate) return;
    // 0046f0e8  833dd4d34f0002         +cmp dword ptr [0x4fd3d4], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5231572) /* 0x4fd3d4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0ef  75d2                   -jne 0x46f0c3
    if (!cpu.flags.zf)
    {
        goto L_0x0046f0c3;
    }
    // 0046f0f1  833ddced4d0008         +cmp dword ptr [0x4deddc], 8
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5107164) /* 0x4deddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0f8  75c9                   -jne 0x46f0c3
    if (!cpu.flags.zf)
    {
        goto L_0x0046f0c3;
    }
    // 0046f0fa  c705dced4d0007000000   -mov dword ptr [0x4deddc], 7
    *app->getMemory<x86::reg32>(x86::reg32(5107164) /* 0x4deddc */) = 7 /*0x7*/;
    // 0046f104  ebbd                   -jmp 0x46f0c3
    goto L_0x0046f0c3;
L_0x0046f106:
    // 0046f106  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f107  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f109  890d10955100           -mov dword ptr [0x519510], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346576) /* 0x519510 */) = cpu.ecx;
    // 0046f10f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f110  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f111  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f120  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f121  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f122  8b150c955100           -mov edx, dword ptr [0x51950c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346572) /* 0x51950c */);
    // 0046f128  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046f12d  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f12f  890d14955100           -mov dword ptr [0x519514], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */) = cpu.ecx;
    // 0046f135  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f138  7c02                   -jl 0x46f13c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f13c;
    }
    // 0046f13a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046f13c:
    // 0046f13c  89150c955100           -mov dword ptr [0x51950c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346572) /* 0x51950c */) = cpu.edx;
    // 0046f142  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f143  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f144  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f150  a10c955100             -mov eax, dword ptr [0x51950c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346572) /* 0x51950c */);
    // 0046f155  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f160  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f161  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f162  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f164  e827000000             -call 0x46f190
    cpu.esp -= 4;
    sub_46f190(app, cpu);
    if (cpu.terminate) return;
    // 0046f169  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f16b  7413                   -je 0x46f180
    if (cpu.flags.zf)
    {
        goto L_0x0046f180;
    }
L_0x0046f16d:
    // 0046f16d  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046f170  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046f172  ff148dcc895100         -call dword ptr [ecx*4 + 0x5189cc]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5343692) /* 0x5189cc */ + cpu.ecx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0046f179  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0046f17b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f17d  75ee                   -jne 0x46f16d
    if (!cpu.flags.zf)
    {
        goto L_0x0046f16d;
    }
    // 0046f17f  90                     -nop 
    ;
L_0x0046f180:
    // 0046f180  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f181  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f182  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f190  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f191  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f192  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f193  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f194  b9b0f64600             -mov ecx, 0x46f6b0
    cpu.ecx = 4650672 /*0x46f6b0*/;
    // 0046f199  bb90f64600             -mov ebx, 0x46f690
    cpu.ebx = 4650640 /*0x46f690*/;
    // 0046f19e  bea0f64600             -mov esi, 0x46f6a0
    cpu.esi = 4650656 /*0x46f6a0*/;
    // 0046f1a3  baf0f64600             -mov edx, 0x46f6f0
    cpu.edx = 4650736 /*0x46f6f0*/;
    // 0046f1a8  890df0895100           -mov dword ptr [0x5189f0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5343728) /* 0x5189f0 */) = cpu.ecx;
    // 0046f1ae  891df4895100           -mov dword ptr [0x5189f4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5343732) /* 0x5189f4 */) = cpu.ebx;
    // 0046f1b4  8935f8895100           -mov dword ptr [0x5189f8], esi
    *app->getMemory<x86::reg32>(x86::reg32(5343736) /* 0x5189f8 */) = cpu.esi;
    // 0046f1ba  8915ec895100           -mov dword ptr [0x5189ec], edx
    *app->getMemory<x86::reg32>(x86::reg32(5343724) /* 0x5189ec */) = cpu.edx;
    // 0046f1c0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1c1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1c2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1c3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f1d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f1d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f1d1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f1d2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f1d3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f1d4  b950f74600             -mov ecx, 0x46f750
    cpu.ecx = 4650832 /*0x46f750*/;
    // 0046f1d9  bb30f74600             -mov ebx, 0x46f730
    cpu.ebx = 4650800 /*0x46f730*/;
    // 0046f1de  be40f74600             -mov esi, 0x46f740
    cpu.esi = 4650816 /*0x46f740*/;
    // 0046f1e3  ba90f74600             -mov edx, 0x46f790
    cpu.edx = 4650896 /*0x46f790*/;
    // 0046f1e8  890df0895100           -mov dword ptr [0x5189f0], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5343728) /* 0x5189f0 */) = cpu.ecx;
    // 0046f1ee  891df4895100           -mov dword ptr [0x5189f4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5343732) /* 0x5189f4 */) = cpu.ebx;
    // 0046f1f4  8935f8895100           -mov dword ptr [0x5189f8], esi
    *app->getMemory<x86::reg32>(x86::reg32(5343736) /* 0x5189f8 */) = cpu.esi;
    // 0046f1fa  8915ec895100           -mov dword ptr [0x5189ec], edx
    *app->getMemory<x86::reg32>(x86::reg32(5343724) /* 0x5189ec */) = cpu.edx;
    // 0046f200  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f201  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f202  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f203  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f204  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f210  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f211  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f212  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f213  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f214  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f215  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f216  b980f44600             -mov ecx, 0x46f480
    cpu.ecx = 4650112 /*0x46f480*/;
    // 0046f21b  bb20f34600             -mov ebx, 0x46f320
    cpu.ebx = 4649760 /*0x46f320*/;
    // 0046f220  bf60f64600             -mov edi, 0x46f660
    cpu.edi = 4650592 /*0x46f660*/;
    // 0046f225  bd50f64600             -mov ebp, 0x46f650
    cpu.ebp = 4650576 /*0x46f650*/;
    // 0046f22a  b840f64600             -mov eax, 0x46f640
    cpu.eax = 4650560 /*0x46f640*/;
    // 0046f22f  bab0f44600             -mov edx, 0x46f4b0
    cpu.edx = 4650160 /*0x46f4b0*/;
    // 0046f234  beb0f54600             -mov esi, 0x46f5b0
    cpu.esi = 4650416 /*0x46f5b0*/;
    // 0046f239  890d108a5100           -mov dword ptr [0x518a10], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5343760) /* 0x518a10 */) = cpu.ecx;
    // 0046f23f  891dd0895100           -mov dword ptr [0x5189d0], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5343696) /* 0x5189d0 */) = cpu.ebx;
    // 0046f245  891dd4895100           -mov dword ptr [0x5189d4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5343700) /* 0x5189d4 */) = cpu.ebx;
    // 0046f24b  893dd8895100           -mov dword ptr [0x5189d8], edi
    *app->getMemory<x86::reg32>(x86::reg32(5343704) /* 0x5189d8 */) = cpu.edi;
    // 0046f251  892ddc895100           -mov dword ptr [0x5189dc], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5343708) /* 0x5189dc */) = cpu.ebp;
    // 0046f257  a3e0895100             -mov dword ptr [0x5189e0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5343712) /* 0x5189e0 */) = cpu.eax;
    // 0046f25c  893de4895100           -mov dword ptr [0x5189e4], edi
    *app->getMemory<x86::reg32>(x86::reg32(5343716) /* 0x5189e4 */) = cpu.edi;
    // 0046f262  8915cc895100           -mov dword ptr [0x5189cc], edx
    *app->getMemory<x86::reg32>(x86::reg32(5343692) /* 0x5189cc */) = cpu.edx;
    // 0046f268  89351c8a5100           -mov dword ptr [0x518a1c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5343772) /* 0x518a1c */) = cpu.esi;
    // 0046f26e  b9f0f54600             -mov ecx, 0x46f5f0
    cpu.ecx = 4650480 /*0x46f5f0*/;
    // 0046f273  bbd0f54600             -mov ebx, 0x46f5d0
    cpu.ebx = 4650448 /*0x46f5d0*/;
    // 0046f278  bf60f54600             -mov edi, 0x46f560
    cpu.edi = 4650336 /*0x46f560*/;
    // 0046f27d  bd20f34600             -mov ebp, 0x46f320
    cpu.ebp = 4649760 /*0x46f320*/;
    // 0046f282  b890f74600             -mov eax, 0x46f790
    cpu.eax = 4650896 /*0x46f790*/;
    // 0046f287  ba50f74600             -mov edx, 0x46f750
    cpu.edx = 4650832 /*0x46f750*/;
    // 0046f28c  be80f64600             -mov esi, 0x46f680
    cpu.esi = 4650624 /*0x46f680*/;
    // 0046f291  890d208a5100           -mov dword ptr [0x518a20], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5343776) /* 0x518a20 */) = cpu.ecx;
    // 0046f297  891d188a5100           -mov dword ptr [0x518a18], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5343768) /* 0x518a18 */) = cpu.ebx;
    // 0046f29d  893d148a5100           -mov dword ptr [0x518a14], edi
    *app->getMemory<x86::reg32>(x86::reg32(5343764) /* 0x518a14 */) = cpu.edi;
    // 0046f2a3  892de8895100           -mov dword ptr [0x5189e8], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5343720) /* 0x5189e8 */) = cpu.ebp;
    // 0046f2a9  a3ec895100             -mov dword ptr [0x5189ec], eax
    *app->getMemory<x86::reg32>(x86::reg32(5343724) /* 0x5189ec */) = cpu.eax;
    // 0046f2ae  8915f0895100           -mov dword ptr [0x5189f0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5343728) /* 0x5189f0 */) = cpu.edx;
    // 0046f2b4  8935fc895100           -mov dword ptr [0x5189fc], esi
    *app->getMemory<x86::reg32>(x86::reg32(5343740) /* 0x5189fc */) = cpu.esi;
    // 0046f2ba  8935048a5100           -mov dword ptr [0x518a04], esi
    *app->getMemory<x86::reg32>(x86::reg32(5343748) /* 0x518a04 */) = cpu.esi;
    // 0046f2c0  8935088a5100           -mov dword ptr [0x518a08], esi
    *app->getMemory<x86::reg32>(x86::reg32(5343752) /* 0x518a08 */) = cpu.esi;
    // 0046f2c6  b930f74600             -mov ecx, 0x46f730
    cpu.ecx = 4650800 /*0x46f730*/;
    // 0046f2cb  bb40f74600             -mov ebx, 0x46f740
    cpu.ebx = 4650816 /*0x46f740*/;
    // 0046f2d0  bf70f64600             -mov edi, 0x46f670
    cpu.edi = 4650608 /*0x46f670*/;
    // 0046f2d5  ba30f44600             -mov edx, 0x46f430
    cpu.edx = 4650032 /*0x46f430*/;
    // 0046f2da  bef0f34600             -mov esi, 0x46f3f0
    cpu.esi = 4649968 /*0x46f3f0*/;
    // 0046f2df  890df4895100           -mov dword ptr [0x5189f4], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5343732) /* 0x5189f4 */) = cpu.ecx;
    // 0046f2e5  891df8895100           -mov dword ptr [0x5189f8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5343736) /* 0x5189f8 */) = cpu.ebx;
    // 0046f2eb  893d008a5100           -mov dword ptr [0x518a00], edi
    *app->getMemory<x86::reg32>(x86::reg32(5343744) /* 0x518a00 */) = cpu.edi;
    // 0046f2f1  8915288a5100           -mov dword ptr [0x518a28], edx
    *app->getMemory<x86::reg32>(x86::reg32(5343784) /* 0x518a28 */) = cpu.edx;
    // 0046f2f7  8935308a5100           -mov dword ptr [0x518a30], esi
    *app->getMemory<x86::reg32>(x86::reg32(5343792) /* 0x518a30 */) = cpu.esi;
    // 0046f2fd  b920f44600             -mov ecx, 0x46f420
    cpu.ecx = 4650016 /*0x46f420*/;
    // 0046f302  bb10f44600             -mov ebx, 0x46f410
    cpu.ebx = 4650000 /*0x46f410*/;
    // 0046f307  890d248a5100           -mov dword ptr [0x518a24], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5343780) /* 0x518a24 */) = cpu.ecx;
    // 0046f30d  891d2c8a5100           -mov dword ptr [0x518a2c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5343788) /* 0x518a2c */) = cpu.ebx;
    // 0046f313  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f314  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f315  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f316  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f317  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f318  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f319  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f320  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f330  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f331  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f332  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f333  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f334  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f335  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046f338  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046f33a  8b1528955100           -mov edx, dword ptr [0x519528]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346600) /* 0x519528 */);
    // 0046f340  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f342  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f344  7e20                   -jle 0x46f366
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f366;
    }
    // 0046f346  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0046f348:
    // 0046f348  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0046f34d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046f34f  e8ecbafeff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 0046f354  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f356  7533                   -jne 0x46f38b
    if (!cpu.flags.zf)
    {
        goto L_0x0046f38b;
    }
L_0x0046f358:
    // 0046f358  8b3d28955100           -mov edi, dword ptr [0x519528]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5346600) /* 0x519528 */);
    // 0046f35e  41                     -inc ecx
    (cpu.ecx)++;
    // 0046f35f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f362  39f9                   +cmp ecx, edi
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
    // 0046f364  7ce2                   -jl 0x46f348
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f348;
    }
L_0x0046f366:
    // 0046f366  833e00                 +cmp dword ptr [esi], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f369  7546                   -jne 0x46f3b1
    if (!cpu.flags.zf)
    {
        goto L_0x0046f3b1;
    }
    // 0046f36b  b900000a00             -mov ecx, 0xa0000
    cpu.ecx = 655360 /*0xa0000*/;
L_0x0046f370:
    // 0046f370  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0046f375  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046f379  e8c2bafeff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 0046f37e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f380  7536                   -jne 0x46f3b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046f3b8;
    }
    // 0046f382  83c408                 +add esp, 8
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
    // 0046f385  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f386  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f387  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f388  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f389  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f38a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f38b:
    // 0046f38b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0046f38e  c7400416000000         -mov dword ptr [eax + 4], 0x16
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 22 /*0x16*/;
    // 0046f395  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0046f398  8a81b4945100           -mov al, byte ptr [ecx + 0x5194b4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5346484) /* 0x5194b4 */);
    // 0046f39e  884208                 -mov byte ptr [edx + 8], al
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0046f3a1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0046f3a4  8b83c4945100           -mov eax, dword ptr [ebx + 0x5194c4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5346500) /* 0x5194c4 */);
    // 0046f3aa  e851d3feff             -call 0x45c700
    cpu.esp -= 4;
    sub_45c700(app, cpu);
    if (cpu.terminate) return;
    // 0046f3af  eba7                   -jmp 0x46f358
    goto L_0x0046f358;
L_0x0046f3b1:
    // 0046f3b1  b900000400             -mov ecx, 0x40000
    cpu.ecx = 262144 /*0x40000*/;
    // 0046f3b6  ebb8                   -jmp 0x46f370
    goto L_0x0046f370;
L_0x0046f3b8:
    // 0046f3b8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046f3bc  c7400418000000         -mov dword ptr [eax + 4], 0x18
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 24 /*0x18*/;
    // 0046f3c3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046f3c7  c6400801               -mov byte ptr [eax + 8], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0046f3cb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046f3cd  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046f3d1  e85ad3feff             -call 0x45c730
    cpu.esp -= 4;
    sub_45c730(app, cpu);
    if (cpu.terminate) return;
    // 0046f3d6  e825d3feff             -call 0x45c700
    cpu.esp -= 4;
    sub_45c700(app, cpu);
    if (cpu.terminate) return;
    // 0046f3db  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046f3de  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3df  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3e0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3e1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3e2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f3f0  833d1495510000         +cmp dword ptr [0x519514], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5346580) /* 0x519514 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f3f7  0f84376f0000           -je 0x476334
    if (cpu.flags.zf)
    {
        return sub_476334(app, cpu);
    }
    // 0046f3fd  e9466f0000             -jmp 0x476348
    return sub_476348(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f410  e9bbfdffff             -jmp 0x46f1d0
    return sub_46f1d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f420  8a4008                 -mov al, byte ptr [eax + 8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f423  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046f428  a344955100             -mov dword ptr [0x519544], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */) = cpu.eax;
    // 0046f42d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46f430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f430  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f431  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f432  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f433  6683780800             +cmp word ptr [eax + 8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046f438  7c21                   -jl 0x46f45b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f45b;
    }
    // 0046f43a  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046f43d  8b580a                 -mov ebx, dword ptr [eax + 0xa]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0046f440  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f443  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f446  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046f449  8b4006                 -mov eax, dword ptr [eax + 6]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0046f44c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046f44f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046f452  e899780000             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 0046f457  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f458  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f459  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f45a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f45b:
    // 0046f45b  8b0d30955100           -mov ecx, dword ptr [0x519530]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5346608) /* 0x519530 */);
    // 0046f461  8b1d24955100           -mov ebx, dword ptr [0x519524]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5346596) /* 0x519524 */);
    // 0046f467  8b152c955100           -mov edx, dword ptr [0x51952c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346604) /* 0x51952c */);
    // 0046f46d  a148955100             -mov eax, dword ptr [0x519548]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346632) /* 0x519548 */);
    // 0046f472  e879780000             -call 0x476cf0
    cpu.esp -= 4;
    sub_476cf0(app, cpu);
    if (cpu.terminate) return;
    // 0046f477  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f478  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f479  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f47a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f480  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f481  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f482  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f483  8b480e                 -mov ecx, dword ptr [eax + 0xe]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 0046f486  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046f489  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f48b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f48e  8a5008                 -mov dl, byte ptr [eax + 8]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f491  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046f494  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f495  8b500a                 -mov edx, dword ptr [eax + 0xa]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0046f498  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f49b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046f49e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046f4a1  e82a850100             -call 0x4879d0
    cpu.esp -= 4;
    sub_4879d0(app, cpu);
    if (cpu.terminate) return;
    // 0046f4a6  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f4a7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f4a8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f4a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f4b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f4b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f4b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f4b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f4b4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f4b5  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046f4b8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f4ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f4bc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f4be  8a4239                 -mov al, byte ptr [edx + 0x39]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(57) /* 0x39 */);
    // 0046f4c1  8a5a3a                 -mov bl, byte ptr [edx + 0x3a]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(58) /* 0x3a */);
    // 0046f4c4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0046f4c7  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0046f4ca  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f4cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f4ce  8a423b                 -mov al, byte ptr [edx + 0x3b]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */);
    // 0046f4d1  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f4d3  e884700000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 0046f4d8  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046f4db  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f4dd  744d                   -je 0x46f52c
    if (cpu.flags.zf)
    {
        goto L_0x0046f52c;
    }
    // 0046f4df  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046f4e1  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046f4e5  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046f4e8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f4e9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f4ea  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0046f4ed  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046f4f1  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046f4f4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f4f5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f4f6  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0046f4f9  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f4fd  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046f500  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f501  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f502  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046f504  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0046f507  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046f50b  8d7c243c               -lea edi, [esp + 0x3c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046f50f  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
L_0x0046f512:
    // 0046f512  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0046f517  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0046f51c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f51d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f51e  e81d110200             -call 0x490640
    cpu.esp -= 4;
    sub_490640(app, cpu);
    if (cpu.terminate) return;
    // 0046f523  83c440                 +add esp, 0x40
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046f526  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f527  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f528  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f529  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f52a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f52b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f52c:
    // 0046f52c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046f52e  8d7218                 -lea esi, [edx + 0x18]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046f531  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f532  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f533  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f537  8d7220                 -lea esi, [edx + 0x20]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0046f53a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f53b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f53c  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f540  8d7228                 -lea esi, [edx + 0x28]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0046f543  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046f545  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f546  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f547  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f548  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046f54c  8d7230                 -lea esi, [edx + 0x30]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 0046f54f  ebc1                   -jmp 0x46f512
    goto L_0x0046f512;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f560  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f561  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f562  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f563  80782900               +cmp byte ptr [eax + 0x29], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046f567  741b                   -je 0x46f584
    if (cpu.flags.zf)
    {
        goto L_0x0046f584;
    }
    // 0046f569  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f56b  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046f56e  8a5028                 -mov dl, byte ptr [eax + 0x28]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0046f571  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046f574  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f575  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046f578  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f57b  e8a0dc0000             -call 0x47d220
    cpu.esp -= 4;
    sub_47d220(app, cpu);
    if (cpu.terminate) return;
    // 0046f580  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f581  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f582  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f583  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f584:
    // 0046f584  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f587  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046f589  8a4028                 -mov al, byte ptr [eax + 0x28]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0046f58c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0046f591  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0046f596  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046f59b  e8a0100200             -call 0x490640
    cpu.esp -= 4;
    sub_490640(app, cpu);
    if (cpu.terminate) return;
    // 0046f5a0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f5a1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f5a2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f5a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f5b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f5b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f5b1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f5b2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046f5b5  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f5b8  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046f5bb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0046f5bd  e8beb50000             -call 0x47ab80
    cpu.esp -= 4;
    sub_47ab80(app, cpu);
    if (cpu.terminate) return;
    // 0046f5c2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f5c3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f5c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f5d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f5d1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f5d2  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046f5d5  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f5d8  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046f5db  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0046f5dd  e85e820000             -call 0x477840
    cpu.esp -= 4;
    sub_477840(app, cpu);
    if (cpu.terminate) return;
    // 0046f5e2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f5e3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f5e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f5f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f5f0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f5f1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f5f2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f5f3  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046f5f6  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046f5f8  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f5fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f5fc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f5fd  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046f601  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046f603  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f604  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f605  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f609  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046f60c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f60d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f60e  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f612  8d7018                 -lea esi, [eax + 0x18]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046f615  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f616  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f617  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046f61b  8d7020                 -lea esi, [eax + 0x20]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046f61e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f61f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f620  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0046f623  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046f625  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0046f627  e884090200             -call 0x48ffb0
    cpu.esp -= 4;
    sub_48ffb0(app, cpu);
    if (cpu.terminate) return;
    // 0046f62c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0046f62f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f630  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f631  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f632  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f640  c7054095510007000000   -mov dword ptr [0x519540], 7
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 7 /*0x7*/;
    // 0046f64a  e931030000             -jmp 0x46f980
    return sub_46f980(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46f650(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f650  c7054095510001000000   -mov dword ptr [0x519540], 1
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 1 /*0x1*/;
    // 0046f65a  e921030000             -jmp 0x46f980
    return sub_46f980(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46f660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f660  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f661  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f663  891540955100           -mov dword ptr [0x519540], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = cpu.edx;
    // 0046f669  e812030000             -call 0x46f980
    cpu.esp -= 4;
    sub_46f980(app, cpu);
    if (cpu.terminate) return;
    // 0046f66e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f66f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_46f670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f670  c7054095510005000000   -mov dword ptr [0x519540], 5
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 5 /*0x5*/;
    // 0046f67a  e951010000             -jmp 0x46f7d0
    return sub_46f7d0(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46f680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f680  c7054095510004000000   -mov dword ptr [0x519540], 4
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 4 /*0x4*/;
    // 0046f68a  e941010000             -jmp 0x46f7d0
    return sub_46f7d0(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46f690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f690  c7054095510002000000   -mov dword ptr [0x519540], 2
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 2 /*0x2*/;
    // 0046f69a  e9b1040000             -jmp 0x46fb50
    return sub_46fb50(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46f6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f6a0  c7054095510007000000   -mov dword ptr [0x519540], 7
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 7 /*0x7*/;
    // 0046f6aa  e9a1040000             -jmp 0x46fb50
    return sub_46fb50(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46f6b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f6b0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f6b1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f6b2  c7054095510005000000   -mov dword ptr [0x519540], 5
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 5 /*0x5*/;
    // 0046f6bc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046f6bf  8b0d90895100           -mov ecx, dword ptr [0x518990]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046f6c5  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f6c8  7513                   -jne 0x46f6dd
    if (!cpu.flags.zf)
    {
        goto L_0x0046f6dd;
    }
    // 0046f6ca  833d4495510000         +cmp dword ptr [0x519544], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f6d1  750a                   -jne 0x46f6dd
    if (!cpu.flags.zf)
    {
        goto L_0x0046f6dd;
    }
    // 0046f6d3  c7054095510001000000   -mov dword ptr [0x519540], 1
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 1 /*0x1*/;
L_0x0046f6dd:
    // 0046f6dd  e86e040000             -call 0x46fb50
    cpu.esp -= 4;
    sub_46fb50(app, cpu);
    if (cpu.terminate) return;
    // 0046f6e2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f6e3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f6e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f6f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f6f1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f6f2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f6f3  c7054095510004000000   -mov dword ptr [0x519540], 4
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 4 /*0x4*/;
    // 0046f6fd  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046f700  8b0d90895100           -mov ecx, dword ptr [0x518990]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046f706  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f709  7510                   -jne 0x46f71b
    if (!cpu.flags.zf)
    {
        goto L_0x0046f71b;
    }
    // 0046f70b  8b1d44955100           -mov ebx, dword ptr [0x519544]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046f711  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046f713  7506                   -jne 0x46f71b
    if (!cpu.flags.zf)
    {
        goto L_0x0046f71b;
    }
    // 0046f715  891d40955100           -mov dword ptr [0x519540], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = cpu.ebx;
L_0x0046f71b:
    // 0046f71b  e830040000             -call 0x46fb50
    cpu.esp -= 4;
    sub_46fb50(app, cpu);
    if (cpu.terminate) return;
    // 0046f720  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f721  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f722  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f723  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f730  c7054095510002000000   -mov dword ptr [0x519540], 2
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 2 /*0x2*/;
    // 0046f73a  e991060000             -jmp 0x46fdd0
    return sub_46fdd0(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46f740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f740  c7054095510007000000   -mov dword ptr [0x519540], 7
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 7 /*0x7*/;
    // 0046f74a  e981060000             -jmp 0x46fdd0
    return sub_46fdd0(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46f750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f750  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f751  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f752  c7054095510005000000   -mov dword ptr [0x519540], 5
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 5 /*0x5*/;
    // 0046f75c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046f75f  8b0d90895100           -mov ecx, dword ptr [0x518990]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046f765  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f768  7513                   -jne 0x46f77d
    if (!cpu.flags.zf)
    {
        goto L_0x0046f77d;
    }
    // 0046f76a  833d4495510000         +cmp dword ptr [0x519544], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f771  750a                   -jne 0x46f77d
    if (!cpu.flags.zf)
    {
        goto L_0x0046f77d;
    }
    // 0046f773  c7054095510001000000   -mov dword ptr [0x519540], 1
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 1 /*0x1*/;
L_0x0046f77d:
    // 0046f77d  e84e060000             -call 0x46fdd0
    cpu.esp -= 4;
    sub_46fdd0(app, cpu);
    if (cpu.terminate) return;
    // 0046f782  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f783  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f784  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f790  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f791  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f792  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f793  c7054095510004000000   -mov dword ptr [0x519540], 4
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = 4 /*0x4*/;
    // 0046f79d  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046f7a0  8b0d90895100           -mov ecx, dword ptr [0x518990]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5343632) /* 0x518990 */);
    // 0046f7a6  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f7a9  7510                   -jne 0x46f7bb
    if (!cpu.flags.zf)
    {
        goto L_0x0046f7bb;
    }
    // 0046f7ab  8b1d44955100           -mov ebx, dword ptr [0x519544]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046f7b1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046f7b3  7506                   -jne 0x46f7bb
    if (!cpu.flags.zf)
    {
        goto L_0x0046f7bb;
    }
    // 0046f7b5  891d40955100           -mov dword ptr [0x519540], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */) = cpu.ebx;
L_0x0046f7bb:
    // 0046f7bb  e810060000             -call 0x46fdd0
    cpu.esp -= 4;
    sub_46fdd0(app, cpu);
    if (cpu.terminate) return;
    // 0046f7c0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7c1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7c2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f7d0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f7d1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f7d2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f7d3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f7d4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f7d5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f7d6  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0046f7d9  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046f7dc  668b560e               -mov dx, word ptr [esi + 0xe]
    cpu.dx = *app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 0046f7e0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046f7e2  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0046f7e5  0f8500010000           -jne 0x46f8eb
    if (!cpu.flags.zf)
    {
        goto L_0x0046f8eb;
    }
    // 0046f7eb  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046f7ee  66837a0e00             +cmp word ptr [edx + 0xe], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046f7f3  0f85f2000000           -jne 0x46f8eb
    if (!cpu.flags.zf)
    {
        goto L_0x0046f8eb;
    }
    // 0046f7f9  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046f7fc  66837a0e00             +cmp word ptr [edx + 0xe], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046f801  0f85e4000000           -jne 0x46f8eb
    if (!cpu.flags.zf)
    {
        goto L_0x0046f8eb;
    }
    // 0046f807  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046f80b  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046f80e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f80f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f810  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046f813  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046f817  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046f81a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f81b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f81c  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046f81f  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f823  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046f826  8b150cd34d00           -mov edx, dword ptr [0x4dd30c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100300) /* 0x4dd30c */);
    // 0046f82c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f82d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f82e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f830  0f84f0000000           -je 0x46f926
    if (cpu.flags.zf)
    {
        goto L_0x0046f926;
    }
    // 0046f836  6683780a02             +cmp word ptr [eax + 0xa], 2
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046f83b  0f85b4000000           -jne 0x46f8f5
    if (!cpu.flags.zf)
    {
        goto L_0x0046f8f5;
    }
L_0x0046f841:
    // 0046f841  8b4d1c                 -mov ecx, dword ptr [ebp + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0046f844  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f846  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0046f848  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046f84a  8a5904                 -mov bl, byte ptr [ecx + 4]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046f84d  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046f850  8b5202                 -mov edx, dword ptr [edx + 2]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046f853  8934dc                 -mov dword ptr [esp + ebx*8], esi
    *app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 8) = cpu.esi;
    // 0046f856  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f858  8a5904                 -mov bl, byte ptr [ecx + 4]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046f85b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046f85e  8974dc04               -mov dword ptr [esp + ebx*8 + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ebx * 8) = cpu.esi;
    // 0046f862  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f864  4a                     -dec edx
    (cpu.edx)--;
    // 0046f865  8a5905                 -mov bl, byte ptr [ecx + 5]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0046f868  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046f86b  8914dc                 -mov dword ptr [esp + ebx*8], edx
    *app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 8) = cpu.edx;
    // 0046f86e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f870  8a5905                 -mov bl, byte ptr [ecx + 5]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0046f873  8974dc04               -mov dword ptr [esp + ebx*8 + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ebx * 8) = cpu.esi;
    // 0046f877  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f879  8a5906                 -mov bl, byte ptr [ecx + 6]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0046f87c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046f87f  8914dc                 -mov dword ptr [esp + ebx*8], edx
    *app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 8) = cpu.edx;
    // 0046f882  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f884  48                     -dec eax
    (cpu.eax)--;
    // 0046f885  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0046f888  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0046f88b  8944d404               -mov dword ptr [esp + edx*8 + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) = cpu.eax;
    // 0046f88f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f891  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0046f894  8934d4                 -mov dword ptr [esp + edx*8], esi
    *app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 8) = cpu.esi;
    // 0046f897  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f899  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0046f89c  8944d404               -mov dword ptr [esp + edx*8 + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) = cpu.eax;
    // 0046f8a0  a1487c4c00             -mov eax, dword ptr [0x4c7c48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5012552) /* 0x4c7c48 */);
    // 0046f8a5  3b4108                 +cmp eax, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f8a8  0f84b4000000           -je 0x46f962
    if (cpu.flags.zf)
    {
        goto L_0x0046f962;
    }
L_0x0046f8ae:
    // 0046f8ae  8b1544955100           -mov edx, dword ptr [0x519544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046f8b4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046f8b7  e8b4baffff             -call 0x46b370
    cpu.esp -= 4;
    sub_46b370(app, cpu);
    if (cpu.terminate) return;
    // 0046f8bc  a144955100             -mov eax, dword ptr [0x519544]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046f8c1  a34c7c4c00             -mov dword ptr [0x4c7c4c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5012556) /* 0x4c7c4c */) = cpu.eax;
    // 0046f8c6  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046f8c9  a3487c4c00             -mov dword ptr [0x4c7c48], eax
    *app->getMemory<x86::reg32>(x86::reg32(5012552) /* 0x4c7c48 */) = cpu.eax;
L_0x0046f8ce:
    // 0046f8ce  8b2d40955100           -mov ebp, dword ptr [0x519540]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */);
    // 0046f8d4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f8d5  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046f8d9  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0046f8de  6aff                   -push -1
    *app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0046f8e0  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0046f8e2  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046f8e6  e871eb0100             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
L_0x0046f8eb:
    // 0046f8eb  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0046f8ee  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8ef  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8f0  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8f1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8f2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8f3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f8f5:
    // 0046f8f5  8d5c2430               -lea ebx, [esp + 0x30]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f8f9  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046f8fd  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046f901  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f903  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046f906  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0046f908  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046f90b  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046f90d  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046f910  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046f912  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046f915  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046f918  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0046f91b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f91d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046f91f  7cca                   -jl 0x46f8eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f8eb;
    }
    // 0046f921  e91bffffff             -jmp 0x46f841
    goto L_0x0046f841;
L_0x0046f926:
    // 0046f926  6683780a02             +cmp word ptr [eax + 0xa], 2
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046f92b  0f8410ffffff           -je 0x46f841
    if (cpu.flags.zf)
    {
        goto L_0x0046f841;
    }
    // 0046f931  8d5c2430               -lea ebx, [esp + 0x30]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f935  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046f939  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046f93d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f93f  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046f942  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0046f944  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046f947  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046f949  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046f94c  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046f94e  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046f951  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046f954  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0046f957  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f959  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046f95b  7f8e                   -jg 0x46f8eb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046f8eb;
    }
    // 0046f95d  e9dffeffff             -jmp 0x46f841
    goto L_0x0046f841;
L_0x0046f962:
    // 0046f962  8b3d44955100           -mov edi, dword ptr [0x519544]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046f968  3b3d4c7c4c00           +cmp edi, dword ptr [0x4c7c4c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5012556) /* 0x4c7c4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f96e  0f853affffff           -jne 0x46f8ae
    if (!cpu.flags.zf)
    {
        goto L_0x0046f8ae;
    }
    // 0046f974  e955ffffff             -jmp 0x46f8ce
    goto L_0x0046f8ce;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f980  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f981  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f982  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f983  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f984  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f985  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046f988  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f98b  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 0046f991  0f8c7e010000           -jl 0x46fb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb15;
    }
    // 0046f997  81fa00100000           +cmp edx, 0x1000
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
    // 0046f99d  0f8f72010000           -jg 0x46fb15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fb15;
    }
    // 0046f9a3  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046f9a6  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f9ac  0f8c63010000           -jl 0x46fb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb15;
    }
    // 0046f9b2  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f9b8  0f8f57010000           -jg 0x46fb15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fb15;
    }
    // 0046f9be  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046f9c0  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f9c3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f9c4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f9c5  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046f9c8  81ff00f0ffff           +cmp edi, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f9ce  0f8c41010000           -jl 0x46fb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb15;
    }
    // 0046f9d4  81ff00100000           +cmp edi, 0x1000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f9da  0f8f35010000           -jg 0x46fb15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fb15;
    }
    // 0046f9e0  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046f9e3  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 0046f9e9  0f8c26010000           -jl 0x46fb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb15;
    }
    // 0046f9ef  81fa00100000           +cmp edx, 0x1000
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
    // 0046f9f5  0f8f1a010000           -jg 0x46fb15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fb15;
    }
    // 0046f9fb  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f9ff  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046fa02  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa03  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa04  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046fa07  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fa0d  0f8c02010000           -jl 0x46fb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb15;
    }
    // 0046fa13  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fa19  0f8ff6000000           -jg 0x46fb15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fb15;
    }
    // 0046fa1f  8b781c                 -mov edi, dword ptr [eax + 0x1c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0046fa22  81ff00f0ffff           +cmp edi, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fa28  0f8ce7000000           -jl 0x46fb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb15;
    }
    // 0046fa2e  81ff00100000           +cmp edi, 0x1000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fa34  0f8fdb000000           -jg 0x46fb15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fb15;
    }
    // 0046fa3a  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fa3e  8d7018                 -lea esi, [eax + 0x18]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046fa41  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa42  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa43  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046fa46  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 0046fa4c  0f8cc3000000           -jl 0x46fb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb15;
    }
    // 0046fa52  81fa00100000           +cmp edx, 0x1000
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
    // 0046fa58  0f8fb7000000           -jg 0x46fb15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fb15;
    }
    // 0046fa5e  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0046fa61  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fa67  0f8ca8000000           -jl 0x46fb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb15;
    }
    // 0046fa6d  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fa73  0f8f9c000000           -jg 0x46fb15
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fb15;
    }
    // 0046fa79  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046fa7d  8d7020                 -lea esi, [eax + 0x20]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046fa80  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa81  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa82  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046fa86  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046fa88  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa89  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa8a  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0046fa8d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046fa8f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0046fa91  0fb67004               -movzx esi, byte ptr [eax + 4]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0046fa95  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046fa98  8b5902                 -mov ebx, dword ptr [ecx + 2]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0046fa9b  897cf428               -mov dword ptr [esp + esi*8 + 0x28], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */ + cpu.esi * 8) = cpu.edi;
    // 0046fa9f  0fb67004               -movzx esi, byte ptr [eax + 4]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 0046faa3  897cf42c               -mov dword ptr [esp + esi*8 + 0x2c], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */ + cpu.esi * 8) = cpu.edi;
    // 0046faa7  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0046faaa  0fb67005               -movzx esi, byte ptr [eax + 5]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */));
    // 0046faae  4b                     -dec ebx
    (cpu.ebx)--;
    // 0046faaf  895cf428               -mov dword ptr [esp + esi*8 + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */ + cpu.esi * 8) = cpu.ebx;
    // 0046fab3  0fb67005               -movzx esi, byte ptr [eax + 5]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */));
    // 0046fab7  897cf42c               -mov dword ptr [esp + esi*8 + 0x2c], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */ + cpu.esi * 8) = cpu.edi;
    // 0046fabb  0fb67006               -movzx esi, byte ptr [eax + 6]
    cpu.esi = x86::reg32(*app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */));
    // 0046fabf  895cf428               -mov dword ptr [esp + esi*8 + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */ + cpu.esi * 8) = cpu.ebx;
    // 0046fac3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046fac5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046fac8  8a5806                 -mov bl, byte ptr [eax + 6]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0046facb  4a                     -dec edx
    (cpu.edx)--;
    // 0046facc  8954dc2c               -mov dword ptr [esp + ebx*8 + 0x2c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */ + cpu.ebx * 8) = cpu.edx;
    // 0046fad0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046fad2  8a5807                 -mov bl, byte ptr [eax + 7]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0046fad5  897cdc28               -mov dword ptr [esp + ebx*8 + 0x28], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */ + cpu.ebx * 8) = cpu.edi;
    // 0046fad9  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0046fadc  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046fae1  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0046fae5  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fae9  8954c42c               -mov dword ptr [esp + eax*8 + 0x2c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */ + cpu.eax * 8) = cpu.edx;
    // 0046faed  a140955100             -mov eax, dword ptr [0x519540]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */);
    // 0046faf2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046faf3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046faf4  83f807                 +cmp eax, 7
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
    // 0046faf7  7525                   -jne 0x46fb1e
    if (!cpu.flags.zf)
    {
        goto L_0x0046fb1e;
    }
    // 0046faf9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046fafb  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046faff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046fb01  e8eef80100             -call 0x48f3f4
    cpu.esp -= 4;
    sub_48f3f4(app, cpu);
    if (cpu.terminate) return;
    // 0046fb06  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fb0a  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046fb0e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046fb10  e8dff80100             -call 0x48f3f4
    cpu.esp -= 4;
    sub_48f3f4(app, cpu);
    if (cpu.terminate) return;
L_0x0046fb15:
    // 0046fb15  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046fb18  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb19  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb1a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb1b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb1c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fb1e:
    // 0046fb1e  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0046fb20  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fb24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046fb26  e8a9030200             -call 0x48fed4
    cpu.esp -= 4;
    sub_48fed4(app, cpu);
    if (cpu.terminate) return;
    // 0046fb2b  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fb2f  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046fb33  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046fb35  e89a030200             -call 0x48fed4
    cpu.esp -= 4;
    sub_48fed4(app, cpu);
    if (cpu.terminate) return;
    // 0046fb3a  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046fb3d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb3e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb3f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb40  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb41  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fb50  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046fb51  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fb52  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fb53  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fb54  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fb55  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fb56  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046fb59  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046fb5b  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046fb5e  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fb62  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046fb65  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fb66  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fb67  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fb6b  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 0046fb71  0f8cbb010000           -jl 0x46fd32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd32;
    }
    // 0046fb77  81fa00100000           +cmp edx, 0x1000
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
    // 0046fb7d  0f8faf010000           -jg 0x46fd32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fd32;
    }
    // 0046fb83  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046fb87  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fb8d  0f8c9f010000           -jl 0x46fd32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd32;
    }
    // 0046fb93  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fb99  0f8f93010000           -jg 0x46fd32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fd32;
    }
    // 0046fb9f  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046fba2  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046fba6  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046fba9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fbaa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fbab  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046fbaf  81ff00f0ffff           +cmp edi, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fbb5  0f8c77010000           -jl 0x46fd32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd32;
    }
    // 0046fbbb  81ff00100000           +cmp edi, 0x1000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fbc1  0f8f6b010000           -jg 0x46fd32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fd32;
    }
    // 0046fbc7  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046fbcb  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 0046fbd1  0f8c5b010000           -jl 0x46fd32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd32;
    }
    // 0046fbd7  81fa00100000           +cmp edx, 0x1000
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
    // 0046fbdd  0f8f4f010000           -jg 0x46fd32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fd32;
    }
    // 0046fbe3  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046fbe6  8d7c2438               -lea edi, [esp + 0x38]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046fbea  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046fbed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fbee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fbef  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046fbf3  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fbf9  0f8c33010000           -jl 0x46fd32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd32;
    }
    // 0046fbff  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fc05  0f8f27010000           -jg 0x46fd32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fd32;
    }
    // 0046fc0b  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046fc0f  81ff00f0ffff           +cmp edi, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fc15  0f8c17010000           -jl 0x46fd32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd32;
    }
    // 0046fc1b  81ff00100000           +cmp edi, 0x1000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fc21  0f8f0b010000           -jg 0x46fd32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fd32;
    }
    // 0046fc27  8b7018                 -mov esi, dword ptr [eax + 0x18]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046fc2a  8d7c2440               -lea edi, [esp + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046fc2e  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046fc31  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fc32  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fc33  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046fc37  81fa00f0ffff           +cmp edx, 0xfffff000
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
    // 0046fc3d  0f8cef000000           -jl 0x46fd32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd32;
    }
    // 0046fc43  81fa00100000           +cmp edx, 0x1000
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
    // 0046fc49  0f8fe3000000           -jg 0x46fd32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fd32;
    }
    // 0046fc4f  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0046fc53  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fc59  0f8cd3000000           -jl 0x46fd32
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd32;
    }
    // 0046fc5f  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fc65  0f8fc7000000           -jg 0x46fd32
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fd32;
    }
    // 0046fc6b  6683780a02             +cmp word ptr [eax + 0xa], 2
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046fc70  0f84c6000000           -je 0x46fd3c
    if (cpu.flags.zf)
    {
        goto L_0x0046fd3c;
    }
    // 0046fc76  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0046fc7b:
    // 0046fc7b  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046fc7d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046fc7f  0f85be000000           -jne 0x46fd43
    if (!cpu.flags.zf)
    {
        goto L_0x0046fd43;
    }
L_0x0046fc85:
    // 0046fc85  8b6d1c                 -mov ebp, dword ptr [ebp + 0x1c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0046fc88  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fc8a  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0046fc8d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046fc8f  8a5504                 -mov dl, byte ptr [ebp + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046fc92  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046fc95  8b4602                 -mov eax, dword ptr [esi + 2]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0046fc98  891cd4                 -mov dword ptr [esp + edx*8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 8) = cpu.ebx;
    // 0046fc9b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fc9d  8a5504                 -mov dl, byte ptr [ebp + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046fca0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046fca3  895cd404               -mov dword ptr [esp + edx*8 + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) = cpu.ebx;
    // 0046fca7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fca9  48                     -dec eax
    (cpu.eax)--;
    // 0046fcaa  8a5505                 -mov dl, byte ptr [ebp + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5) /* 0x5 */);
    // 0046fcad  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0046fcb0  8904d4                 -mov dword ptr [esp + edx*8], eax
    *app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 8) = cpu.eax;
    // 0046fcb3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fcb5  8a5505                 -mov dl, byte ptr [ebp + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5) /* 0x5 */);
    // 0046fcb8  895cd404               -mov dword ptr [esp + edx*8 + 4], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) = cpu.ebx;
    // 0046fcbc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fcbe  8a5506                 -mov dl, byte ptr [ebp + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(6) /* 0x6 */);
    // 0046fcc1  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046fcc4  8904d4                 -mov dword ptr [esp + edx*8], eax
    *app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 8) = cpu.eax;
    // 0046fcc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fcc9  49                     -dec ecx
    (cpu.ecx)--;
    // 0046fcca  8a4506                 -mov al, byte ptr [ebp + 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(6) /* 0x6 */);
    // 0046fccd  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0046fcd0  894cc404               -mov dword ptr [esp + eax*8 + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = cpu.ecx;
    // 0046fcd4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fcd6  8a4507                 -mov al, byte ptr [ebp + 7]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(7) /* 0x7 */);
    // 0046fcd9  891cc4                 -mov dword ptr [esp + eax*8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 8) = cpu.ebx;
    // 0046fcdc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fcde  8a4507                 -mov al, byte ptr [ebp + 7]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(7) /* 0x7 */);
    // 0046fce1  894cc404               -mov dword ptr [esp + eax*8 + 4], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = cpu.ecx;
    // 0046fce5  a1487c4c00             -mov eax, dword ptr [0x4c7c48]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5012552) /* 0x4c7c48 */);
    // 0046fcea  3b4508                 +cmp eax, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fced  7472                   -je 0x46fd61
    if (cpu.flags.zf)
    {
        goto L_0x0046fd61;
    }
L_0x0046fcef:
    // 0046fcef  8b1544955100           -mov edx, dword ptr [0x519544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046fcf5  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046fcf8  e873b6ffff             -call 0x46b370
    cpu.esp -= 4;
    sub_46b370(app, cpu);
    if (cpu.terminate) return;
    // 0046fcfd  a144955100             -mov eax, dword ptr [0x519544]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046fd02  a34c7c4c00             -mov dword ptr [0x4c7c4c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5012556) /* 0x4c7c4c */) = cpu.eax;
    // 0046fd07  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046fd0a  a3487c4c00             -mov dword ptr [0x4c7c48], eax
    *app->getMemory<x86::reg32>(x86::reg32(5012552) /* 0x4c7c48 */) = cpu.eax;
L_0x0046fd0f:
    // 0046fd0f  a140955100             -mov eax, dword ptr [0x519540]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */);
    // 0046fd14  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046fd15  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046fd17  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046fd1b  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0046fd1d  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046fd21  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046fd22  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0046fd27  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046fd29  e82ee70100             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 0046fd2e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046fd30  7c3f                   -jl 0x46fd71
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd71;
    }
L_0x0046fd32:
    // 0046fd32  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046fd35  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd36  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd37  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd38  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd39  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd3a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fd3c:
    // 0046fd3c  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0046fd3e  e938ffffff             -jmp 0x46fc7b
    goto L_0x0046fc7b;
L_0x0046fd43:
    // 0046fd43  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046fd47  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046fd4b  8d542430               -lea edx, [esp + 0x30]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046fd4f  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fd53  e8c8020000             -call 0x470020
    cpu.esp -= 4;
    sub_470020(app, cpu);
    if (cpu.terminate) return;
    // 0046fd58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046fd5a  75d6                   -jne 0x46fd32
    if (!cpu.flags.zf)
    {
        goto L_0x0046fd32;
    }
    // 0046fd5c  e924ffffff             -jmp 0x46fc85
    goto L_0x0046fc85;
L_0x0046fd61:
    // 0046fd61  8b1d44955100           -mov ebx, dword ptr [0x519544]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046fd67  3b1d4c7c4c00           +cmp ebx, dword ptr [0x4c7c4c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5012556) /* 0x4c7c4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fd6d  7580                   -jne 0x46fcef
    if (!cpu.flags.zf)
    {
        goto L_0x0046fcef;
    }
    // 0046fd6f  eb9e                   -jmp 0x46fd0f
    goto L_0x0046fd0f;
L_0x0046fd71:
    // 0046fd71  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0046fd75  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fd79  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fd7d  8b1540955100           -mov edx, dword ptr [0x519540]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */);
    // 0046fd83  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fd84  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fd85  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fd86  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046fd8a  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046fd8e  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046fd92  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046fd94  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fd95  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fd96  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0046fd9b  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0046fd9e  e8b9e60100             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 0046fda3  8b0d40955100           -mov ecx, dword ptr [0x519540]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */);
    // 0046fda9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fdaa  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046fdae  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0046fdb3  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046fdb5  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp);
    // 0046fdb8  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046fdbc  e89be60100             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 0046fdc1  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0046fdc4  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fdc5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fdc6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fdc7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fdc8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fdc9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fdca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fdd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046fdd1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fdd2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fdd3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fdd4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046fdd6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fdd8  89151c955100           -mov dword ptr [0x51951c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346588) /* 0x51951c */) = cpu.edx;
    // 0046fdde  6683780a02             +cmp word ptr [eax + 0xa], 2
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046fde3  0f85bb000000           -jne 0x46fea4
    if (!cpu.flags.zf)
    {
        goto L_0x0046fea4;
    }
    // 0046fde9  c7051c95510001000000   -mov dword ptr [0x51951c], 1
    *app->getMemory<x86::reg32>(x86::reg32(5346588) /* 0x51951c */) = 1 /*0x1*/;
L_0x0046fdf3:
    // 0046fdf3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fdf4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fdf5  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046fdf8  bf848a5100             -mov edi, 0x518a84
    cpu.edi = 5343876 /*0x518a84*/;
    // 0046fdfd  8d7310                 -lea esi, [ebx + 0x10]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0046fe00  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe01  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe02  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046fe05  bf848b5100             -mov edi, 0x518b84
    cpu.edi = 5344132 /*0x518b84*/;
    // 0046fe0a  8d7210                 -lea esi, [edx + 0x10]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0046fe0d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe0e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe0f  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0046fe12  bf84945100             -mov edi, 0x519484
    cpu.edi = 5346436 /*0x519484*/;
    // 0046fe17  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046fe1a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe1b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe1c  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 0046fe1f  bf84935100             -mov edi, 0x519384
    cpu.edi = 5346180 /*0x519384*/;
    // 0046fe24  8d7110                 -lea esi, [ecx + 0x10]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046fe27  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe28  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe29  bf748a5100             -mov edi, 0x518a74
    cpu.edi = 5343860 /*0x518a74*/;
    // 0046fe2e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0046fe30  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe31  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe32  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe33  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe34  bf748b5100             -mov edi, 0x518b74
    cpu.edi = 5344116 /*0x518b74*/;
    // 0046fe39  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046fe3b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe3c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe3d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe3e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe3f  bf74945100             -mov edi, 0x519474
    cpu.edi = 5346420 /*0x519474*/;
    // 0046fe44  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046fe46  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe47  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe48  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe49  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe4a  bf74935100             -mov edi, 0x519374
    cpu.edi = 5346164 /*0x519374*/;
    // 0046fe4f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046fe51  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe52  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe53  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe54  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe55  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0046fe58  8b15487c4c00           -mov edx, dword ptr [0x4c7c48]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5012552) /* 0x4c7c48 */);
    // 0046fe5e  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fe61  745b                   -je 0x46febe
    if (cpu.flags.zf)
    {
        goto L_0x0046febe;
    }
L_0x0046fe63:
    // 0046fe63  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0046fe66  8b1544955100           -mov edx, dword ptr [0x519544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046fe6c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046fe6f  e8fcb4ffff             -call 0x46b370
    cpu.esp -= 4;
    sub_46b370(app, cpu);
    if (cpu.terminate) return;
    // 0046fe74  a144955100             -mov eax, dword ptr [0x519544]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046fe79  a34c7c4c00             -mov dword ptr [0x4c7c4c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5012556) /* 0x4c7c4c */) = cpu.eax;
    // 0046fe7e  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0046fe81  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046fe84  a3487c4c00             -mov dword ptr [0x4c7c48], eax
    *app->getMemory<x86::reg32>(x86::reg32(5012552) /* 0x4c7c48 */) = cpu.eax;
L_0x0046fe89:
    // 0046fe89  b8748a5100             -mov eax, 0x518a74
    cpu.eax = 5343860 /*0x518a74*/;
    // 0046fe8e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046fe90  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fe92  892d18955100           -mov dword ptr [0x519518], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5346584) /* 0x519518 */) = cpu.ebp;
    // 0046fe98  e853020000             -call 0x4700f0
    cpu.esp -= 4;
    sub_4700f0(app, cpu);
    if (cpu.terminate) return;
    // 0046fe9d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fe9e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046fe9f:
    // 0046fe9f  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fea0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fea1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fea2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fea3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fea4:
    // 0046fea4  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046fea7  8b5814                 -mov ebx, dword ptr [eax + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046feaa  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046fead  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046feb0  e81b000000             -call 0x46fed0
    cpu.esp -= 4;
    sub_46fed0(app, cpu);
    if (cpu.terminate) return;
    // 0046feb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046feb7  75e6                   -jne 0x46fe9f
    if (!cpu.flags.zf)
    {
        goto L_0x0046fe9f;
    }
    // 0046feb9  e935ffffff             -jmp 0x46fdf3
    goto L_0x0046fdf3;
L_0x0046febe:
    // 0046febe  8b3544955100           -mov esi, dword ptr [0x519544]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5346628) /* 0x519544 */);
    // 0046fec4  3b354c7c4c00           +cmp esi, dword ptr [0x4c7c4c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5012556) /* 0x4c7c4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046feca  7597                   -jne 0x46fe63
    if (!cpu.flags.zf)
    {
        goto L_0x0046fe63;
    }
    // 0046fecc  ebbb                   -jmp 0x46fe89
    goto L_0x0046fe89;
}

/* align: skip 0x00 0x00 */
void Application::sub_46fed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fed0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fed1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fed2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fed3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046fed6  8b351c955100           -mov esi, dword ptr [0x51951c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5346588) /* 0x51951c */);
    // 0046fedc  83fe01                 +cmp esi, 1
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
    // 0046fedf  0f847b000000           -je 0x46ff60
    if (cpu.flags.zf)
    {
        goto L_0x0046ff60;
    }
    // 0046fee5  83fe02                 +cmp esi, 2
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
    // 0046fee8  0f8476000000           -je 0x46ff64
    if (cpu.flags.zf)
    {
        goto L_0x0046ff64;
    }
    // 0046feee  6683780e00             +cmp word ptr [eax + 0xe], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046fef3  756b                   -jne 0x46ff60
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff60;
    }
    // 0046fef5  66837a0e00             +cmp word ptr [edx + 0xe], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046fefa  7564                   -jne 0x46ff60
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff60;
    }
    // 0046fefc  66837b0e00             +cmp word ptr [ebx + 0xe], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046ff01  755d                   -jne 0x46ff60
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff60;
    }
    // 0046ff03  6683790e00             +cmp word ptr [ecx + 0xe], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046ff08  7556                   -jne 0x46ff60
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff60;
    }
    // 0046ff0a  8d7810                 -lea edi, [eax + 0x10]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046ff0d  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046ff10  8d7210                 -lea esi, [edx + 0x10]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0046ff13  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0046ff16  a10cd34d00             -mov eax, dword ptr [0x4dd30c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100300) /* 0x4dd30c */);
    // 0046ff1b  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0046ff1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ff20  0f8484000000           -je 0x46ffaa
    if (cpu.flags.zf)
    {
        goto L_0x0046ffaa;
    }
    // 0046ff26  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046ff28  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046ff2a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0046ff2c  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046ff2f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0046ff31  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046ff34  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046ff36  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046ff39  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046ff3b  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046ff3e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046ff41  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0046ff44  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ff46  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046ff48  7c21                   -jl 0x46ff6b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046ff6b;
    }
L_0x0046ff4a:
    // 0046ff4a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046ff4f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ff51  890d1c955100           -mov dword ptr [0x51951c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346588) /* 0x51951c */) = cpu.ecx;
L_0x0046ff57:
    // 0046ff57  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046ff59  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ff5c  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff5d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff5e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ff60:
    // 0046ff60  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046ff62  ebf3                   -jmp 0x46ff57
    goto L_0x0046ff57;
L_0x0046ff64:
    // 0046ff64  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046ff69  ebec                   -jmp 0x46ff57
    goto L_0x0046ff57;
L_0x0046ff6b:
    // 0046ff6b  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0046ff6e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0046ff70  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046ff72  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0046ff74  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046ff77  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0046ff79  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046ff7c  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046ff7e  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046ff81  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046ff83  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046ff86  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046ff89  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0046ff8c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ff8e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046ff90  7db8                   -jge 0x46ff4a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046ff4a;
    }
    // 0046ff92  c7051c95510002000000   -mov dword ptr [0x51951c], 2
    *app->getMemory<x86::reg32>(x86::reg32(5346588) /* 0x51951c */) = 2 /*0x2*/;
    // 0046ff9c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046ffa1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046ffa3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ffa6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ffa7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ffa8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ffa9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ffaa:
    // 0046ffaa  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046ffac  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046ffae  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0046ffb0  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046ffb3  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0046ffb5  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046ffb8  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046ffba  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046ffbd  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046ffbf  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046ffc2  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046ffc5  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0046ffc8  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ffca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046ffcc  0f8e78ffffff           -jle 0x46ff4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046ff4a;
    }
    // 0046ffd2  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 0046ffd5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0046ffd7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046ffd9  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0046ffdb  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046ffde  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0046ffe0  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046ffe3  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046ffe5  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046ffe8  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0046ffea  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0046ffed  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046fff0  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0046fff3  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fff5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046fff7  0f8e4dffffff           -jle 0x46ff4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046ff4a;
    }
    // 0046fffd  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00470002  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00470007  89151c955100           -mov dword ptr [0x51951c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346588) /* 0x51951c */) = cpu.edx;
    // 0047000d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047000f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470012  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470013  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470014  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470015  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470020  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470021  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470022  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470023  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470026  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00470028  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047002a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047002c  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0047002f  833d0cd34d0000         +cmp dword ptr [0x4dd30c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100300) /* 0x4dd30c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470036  745b                   -je 0x470093
    if (cpu.flags.zf)
    {
        goto L_0x00470093;
    }
    // 00470038  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047003a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0047003c  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047003f  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00470041  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00470044  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 00470046  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00470049  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0047004b  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047004e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00470051  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00470054  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00470056  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00470058  7c0b                   -jl 0x470065
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470065;
    }
L_0x0047005a:
    // 0047005a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047005c:
    // 0047005c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047005e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470061  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470062  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470063  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470064  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470065:
    // 00470065  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 00470068  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047006a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047006c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0047006e  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00470071  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00470073  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00470076  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 00470078  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047007b  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 0047007d  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00470080  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00470083  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00470086  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00470088  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047008a  7dce                   -jge 0x47005a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047005a;
    }
    // 0047008c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00470091  ebc9                   -jmp 0x47005c
    goto L_0x0047005c;
L_0x00470093:
    // 00470093  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00470095  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 00470097  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047009a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0047009c  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047009f  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 004700a1  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004700a4  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 004700a6  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004700a9  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004700ac  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004700af  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004700b1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004700b3  7ea5                   -jle 0x47005a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047005a;
    }
    // 004700b5  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    // 004700b8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004700ba  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004700bc  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004700be  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004700c1  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004700c3  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004700c6  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 004700c8  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004700cb  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 004700cd  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004700d0  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004700d3  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004700d6  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004700d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004700da  0f8e7affffff           -jle 0x47005a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047005a;
    }
    // 004700e0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004700e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004700e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004700ea  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700eb  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700ec  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4700f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004700f0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004700f1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004700f2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004700f3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004700f4  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 004700f7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004700f9  89542454               -mov dword ptr [esp + 0x54], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004700fd  895c2450               -mov dword ptr [esp + 0x50], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00470101  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00470103  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00470106  8b81bc804c00           -mov eax, dword ptr [ecx + 0x4c80bc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013692) /* 0x4c80bc */);
    // 0047010c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047010e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470111  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00470113  8b81c0804c00           -mov eax, dword ptr [ecx + 0x4c80c0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013696) /* 0x4c80c0 */);
    // 00470119  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047011c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047011f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00470121  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00470123  8b81c4804c00           -mov eax, dword ptr [ecx + 0x4c80c4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013700) /* 0x4c80c4 */);
    // 00470129  89542404               -mov dword ptr [esp + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047012d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470130  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00470132  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00470134  8b81c8804c00           -mov eax, dword ptr [ecx + 0x4c80c8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013704) /* 0x4c80c8 */);
    // 0047013a  89542408               -mov dword ptr [esp + 8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047013e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470141  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00470143  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00470145  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00470148  8954240c               -mov dword ptr [esp + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047014c  81780800800000         +cmp dword ptr [eax + 8], 0x8000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470153  7f27                   -jg 0x47017c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047017c;
    }
    // 00470155  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470159  81780800800000         +cmp dword ptr [eax + 8], 0x8000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470160  7f1a                   -jg 0x47017c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047017c;
    }
    // 00470162  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470166  81780800800000         +cmp dword ptr [eax + 8], 0x8000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047016d  7f0d                   -jg 0x47017c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047017c;
    }
    // 0047016f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00470173  81780800800000         +cmp dword ptr [eax + 8], 0x8000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047017a  7e29                   -jle 0x4701a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004701a5;
    }
L_0x0047017c:
    // 0047017c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047017f  8b3d3c955100           -mov edi, dword ptr [0x51953c]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5346620) /* 0x51953c */);
    // 00470185  3b7814                 +cmp edi, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470188  7d23                   -jge 0x4701ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004701ad;
    }
    // 0047018a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047018e  3b7814                 +cmp edi, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470191  7d1a                   -jge 0x4701ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004701ad;
    }
    // 00470193  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470197  3b7814                 +cmp edi, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047019a  7d11                   -jge 0x4701ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004701ad;
    }
    // 0047019c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004701a0  3b7814                 +cmp edi, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004701a3  7d08                   -jge 0x4701ad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004701ad;
    }
L_0x004701a5:
    // 004701a5  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 004701a8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004701a9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004701aa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004701ab  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004701ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004701ad:
    // 004701ad  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004701b1  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004701b5  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004701b9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004701bc  e80ffdffff             -call 0x46fed0
    cpu.esp -= 4;
    sub_46fed0(app, cpu);
    if (cpu.terminate) return;
    // 004701c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004701c3  75e0                   -jne 0x4701a5
    if (!cpu.flags.zf)
    {
        goto L_0x004701a5;
    }
    // 004701c5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004701c9  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004701cc  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004701cf  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004701d2  8b7c2454               -mov edi, dword ptr [esp + 0x54]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004701d6  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004701d8  83ff02                 +cmp edi, 2
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
    // 004701db  7e33                   -jle 0x470210
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00470210;
    }
L_0x004701dd:
    // 004701dd  837c245400             +cmp dword ptr [esp + 0x54], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004701e2  0f8ed0040000           -jle 0x4706b8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004706b8;
    }
    // 004701e8  a118955100             -mov eax, dword ptr [0x519518]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346584) /* 0x519518 */);
    // 004701ed  6683780800             +cmp word ptr [eax + 8], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004701f2  0f85c0040000           -jne 0x4706b8
    if (!cpu.flags.zf)
    {
        goto L_0x004706b8;
    }
    // 004701f8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004701fd  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470201  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00470203  e8c8040000             -call 0x4706d0
    cpu.esp -= 4;
    sub_4706d0(app, cpu);
    if (cpu.terminate) return;
    // 00470208  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 0047020b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047020c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047020d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047020e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047020f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470210:
    // 00470210  8b1518955100           -mov edx, dword ptr [0x519518]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346584) /* 0x519518 */);
    // 00470216  8b5206                 -mov edx, dword ptr [edx + 6]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00470219  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047021c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047021e  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00470221  3b8c82fc804c00         +cmp ecx, dword ptr [edx + eax*4 + 0x4c80fc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5013756) /* 0x4c80fc */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470228  7fb3                   -jg 0x4701dd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004701dd;
    }
    // 0047022a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047022d  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047022f  8944244c               -mov dword ptr [esp + 0x4c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00470233  8b805c804c00           -mov eax, dword ptr [eax + 0x4c805c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5013596) /* 0x4c805c */);
    // 00470239  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0047023c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047023f  8b91bc804c00           -mov edx, dword ptr [ecx + 0x4c80bc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013692) /* 0x4c80bc */);
    // 00470245  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00470248  8b81c0804c00           -mov eax, dword ptr [ecx + 0x4c80c0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013696) /* 0x4c80c0 */);
    // 0047024e  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00470251  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470254  8b342a                 -mov esi, dword ptr [edx + ebp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + cpu.ebp * 1);
    // 00470257  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 0047025a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047025c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0047025e  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00470260  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00470263  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00470265  89742428               -mov dword ptr [esp + 0x28], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00470269  8b742a04               -mov esi, dword ptr [edx + ebp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 0047026d  8b7c2804               -mov edi, dword ptr [eax + ebp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00470271  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00470273  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00470275  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00470277  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0047027a  897b04                 -mov dword ptr [ebx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0047027d  8974242c               -mov dword ptr [esp + 0x2c], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 00470281  8b542a08               -mov edx, dword ptr [edx + ebp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00470285  8b742808               -mov esi, dword ptr [eax + ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00470289  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047028b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047028d  893d94824c00           -mov dword ptr [0x4c8294], edi
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.edi;
    // 00470293  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00470295  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00470298  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047029a  c1fa09                 -sar edx, 9
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (9 /*0x9*/ % 32));
    // 0047029d  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004702a0  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004702a4  89542430               -mov dword ptr [esp + 0x30], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 004702a8  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004702ac  7e2a                   -jle 0x4702d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004702d8;
    }
    // 004702ae  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 004702b0  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 004702b6  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004702b9  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 004702bf  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004702c1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004702c4  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 004702ca  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004702cd  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004702d3  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004702d6  eb14                   -jmp 0x4702ec
    goto L_0x004702ec;
L_0x004702d8:
    // 004702d8  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 004702de  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 004702e5  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004702ec:
    // 004702ec  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 004702f2  6689430e               -mov word ptr [ebx + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004702f6  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004702fa  8b8060804c00           -mov eax, dword ptr [eax + 0x4c8060]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5013600) /* 0x4c8060 */);
    // 00470300  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470303  8b91bc804c00           -mov edx, dword ptr [ecx + 0x4c80bc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013692) /* 0x4c80bc */);
    // 00470309  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0047030c  8b81c8804c00           -mov eax, dword ptr [ecx + 0x4c80c8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013704) /* 0x4c80c8 */);
    // 00470312  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00470315  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470318  8b342a                 -mov esi, dword ptr [edx + ebp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + cpu.ebp * 1);
    // 0047031b  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 0047031e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00470320  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00470322  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00470324  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00470327  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00470329  89742434               -mov dword ptr [esp + 0x34], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 0047032d  8b742a04               -mov esi, dword ptr [edx + ebp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00470331  8b7c2804               -mov edi, dword ptr [eax + ebp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00470335  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00470337  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00470339  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 0047033b  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0047033e  897b04                 -mov dword ptr [ebx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00470341  89742438               -mov dword ptr [esp + 0x38], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.esi;
    // 00470345  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00470347  8b542a08               -mov edx, dword ptr [edx + ebp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 0047034b  8b742808               -mov esi, dword ptr [eax + ebp + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 0047034f  893d94824c00           -mov dword ptr [0x4c8294], edi
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.edi;
    // 00470355  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00470357  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047035a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047035c  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047035e  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 00470361  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00470364  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00470368  8944243c               -mov dword ptr [esp + 0x3c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0047036c  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00470370  7e2a                   -jle 0x47039c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047039c;
    }
    // 00470372  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00470374  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 0047037a  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047037d  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 00470383  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00470385  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00470388  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 0047038e  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00470391  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00470397  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047039a  eb14                   -jmp 0x4703b0
    goto L_0x004703b0;
L_0x0047039c:
    // 0047039c  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 004703a2  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 004703a9  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004703b0:
    // 004703b0  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 004703b6  6689430e               -mov word ptr [ebx + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004703ba  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004703be  8b8064804c00           -mov eax, dword ptr [eax + 0x4c8064]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5013604) /* 0x4c8064 */);
    // 004703c4  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004703c7  8b91c4804c00           -mov edx, dword ptr [ecx + 0x4c80c4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013700) /* 0x4c80c4 */);
    // 004703cd  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004703d0  8b81bc804c00           -mov eax, dword ptr [ecx + 0x4c80bc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013692) /* 0x4c80bc */);
    // 004703d6  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004703d9  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004703dc  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004703de  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004703e0  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx);
    // 004703e2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 004703e4  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004703e6  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004703e8  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 004703ea  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 004703ed  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004703ef  89742440               -mov dword ptr [esp + 0x40], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 004703f3  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004703f6  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004703f9  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004703fb  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004703fd  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 004703ff  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00470402  897b04                 -mov dword ptr [ebx + 4], edi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00470405  89742444               -mov dword ptr [esp + 0x44], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.esi;
    // 00470409  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047040c  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047040f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00470411  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00470413  893d94824c00           -mov dword ptr [0x4c8294], edi
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.edi;
    // 00470419  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047041b  8d742440               -lea esi, [esp + 0x40]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047041f  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00470421  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 00470424  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00470427  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047042a  89442448               -mov dword ptr [esp + 0x48], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 0047042e  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00470432  7e2a                   -jle 0x47045e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047045e;
    }
    // 00470434  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00470436  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 0047043c  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047043f  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 00470445  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00470447  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047044a  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 00470450  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00470453  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00470459  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047045c  eb14                   -jmp 0x470472
    goto L_0x00470472;
L_0x0047045e:
    // 0047045e  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00470464  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0047046b  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00470472:
    // 00470472  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 00470478  6689430e               -mov word ptr [ebx + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0047047c  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00470480  8b8068804c00           -mov eax, dword ptr [eax + 0x4c8068]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5013608) /* 0x4c8068 */);
    // 00470486  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470489  8bb9c0804c00           -mov edi, dword ptr [ecx + 0x4c80c0]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013696) /* 0x4c80c0 */);
    // 0047048f  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00470492  8b81c4804c00           -mov eax, dword ptr [ecx + 0x4c80c4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013700) /* 0x4c80c4 */);
    // 00470498  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0047049b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047049e  8b342f                 -mov esi, dword ptr [edi + ebp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi + cpu.ebp * 1);
    // 004704a1  8b1428                 -mov edx, dword ptr [eax + ebp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004704a4  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004704a6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004704a8  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004704aa  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 004704ad  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004704af  8974241c               -mov dword ptr [esp + 0x1c], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004704b3  8b542f04               -mov edx, dword ptr [edi + ebp + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 004704b7  8b742804               -mov esi, dword ptr [eax + ebp + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 004704bb  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004704bd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004704bf  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 004704c1  c1fa09                 -sar edx, 9
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (9 /*0x9*/ % 32));
    // 004704c4  897304                 -mov dword ptr [ebx + 4], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004704c7  89542420               -mov dword ptr [esp + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004704cb  8b542f08               -mov edx, dword ptr [edi + ebp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 004704cf  03542808               -add edx, dword ptr [eax + ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1)));
    // 004704d3  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004704d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004704d9  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004704dc  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004704de  c1fa09                 -sar edx, 9
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (9 /*0x9*/ % 32));
    // 004704e1  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004704e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004704e6  89542424               -mov dword ptr [esp + 0x24], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004704ea  a394824c00             -mov dword ptr [0x4c8294], eax
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.eax;
    // 004704ef  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004704f3  7e2a                   -jle 0x47051f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047051f;
    }
    // 004704f5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 004704f7  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 004704fd  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00470500  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 00470506  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00470508  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047050b  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 00470511  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00470514  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047051a  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047051d  eb14                   -jmp 0x470533
    goto L_0x00470533;
L_0x0047051f:
    // 0047051f  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00470525  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0047052c  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00470533:
    // 00470533  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 00470539  6689430e               -mov word ptr [ebx + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0047053d  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00470541  8b806c804c00           -mov eax, dword ptr [eax + 0x4c806c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5013612) /* 0x4c806c */);
    // 00470547  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047054a  8b91c8804c00           -mov edx, dword ptr [ecx + 0x4c80c8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013704) /* 0x4c80c8 */);
    // 00470550  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00470553  8b81c4804c00           -mov eax, dword ptr [ecx + 0x4c80c4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5013700) /* 0x4c80c4 */);
    // 00470559  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047055c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047055f  8b0c2a                 -mov ecx, dword ptr [edx + ebp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + cpu.ebp * 1);
    // 00470562  8b3428                 -mov esi, dword ptr [eax + ebp]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 00470565  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00470567  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00470569  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 0047056b  c1f909                 -sar ecx, 9
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (9 /*0x9*/ % 32));
    // 0047056e  8933                   -mov dword ptr [ebx], esi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 00470570  894c2410               -mov dword ptr [esp + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00470574  8b4c2a04               -mov ecx, dword ptr [edx + ebp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00470578  8b7c2804               -mov edi, dword ptr [eax + ebp + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 0047057c  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047057e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00470580  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00470582  c1f909                 -sar ecx, 9
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (9 /*0x9*/ % 32));
    // 00470585  897304                 -mov dword ptr [ebx + 4], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00470588  894c2414               -mov dword ptr [esp + 0x14], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0047058c  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047058f  8b542a08               -mov edx, dword ptr [edx + ebp + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00470593  8b4c2808               -mov ecx, dword ptr [eax + ebp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00470597  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00470599  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047059b  893594824c00           -mov dword ptr [0x4c8294], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.esi;
    // 004705a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004705a3  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004705a5  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 004705a8  895308                 -mov dword ptr [ebx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004705ab  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004705af  89442418               -mov dword ptr [esp + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004705b3  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004705b7  7e2a                   -jle 0x4705e3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004705e3;
    }
    // 004705b9  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 004705bb  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 004705c1  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004705c4  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 004705ca  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004705cc  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004705cf  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 004705d5  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004705d8  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004705de  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004705e1  eb14                   -jmp 0x4705f7
    goto L_0x004705f7;
L_0x004705e3:
    // 004705e3  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 004705e9  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 004705f0  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004705f7:
    // 004705f7  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 004705fd  6689430e               -mov word ptr [ebx + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00470601  8b7c2454               -mov edi, dword ptr [esp + 0x54]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00470605  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470609  8b0d18955100           -mov ecx, dword ptr [0x519518]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5346584) /* 0x519518 */);
    // 0047060f  47                     -inc edi
    (cpu.edi)++;
    // 00470610  40                     -inc eax
    (cpu.eax)++;
    // 00470611  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00470614  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 00470616  89442450               -mov dword ptr [esp + 0x50], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0047061a  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0047061d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047061f  81c6bc804c00           -add esi, 0x4c80bc
    (cpu.esi) += x86::reg32(x86::sreg32(5013692 /*0x4c80bc*/));
    // 00470625  8a4104                 -mov al, byte ptr [ecx + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00470628  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0047062b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047062d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470630  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470634  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00470636  e8b5faffff             -call 0x4700f0
    cpu.esp -= 4;
    sub_4700f0(app, cpu);
    if (cpu.terminate) return;
    // 0047063b  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047063f  0314bd4c804c00         -add edx, dword ptr [edi*4 + 0x4c804c]
    (cpu.edx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5013580) /* 0x4c804c */ + cpu.edi * 4)));
    // 00470646  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470648  8a4105                 -mov al, byte ptr [ecx + 5]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0047064b  89542450               -mov dword ptr [esp + 0x50], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0047064f  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 00470652  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00470654  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470657  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00470659  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047065b  e890faffff             -call 0x4700f0
    cpu.esp -= 4;
    sub_4700f0(app, cpu);
    if (cpu.terminate) return;
    // 00470660  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470664  031cbd4c804c00         -add ebx, dword ptr [edi*4 + 0x4c804c]
    (cpu.ebx) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5013580) /* 0x4c804c */ + cpu.edi * 4)));
    // 0047066b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047066d  8a4106                 -mov al, byte ptr [ecx + 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00470670  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 00470673  897c2454               -mov dword ptr [esp + 0x54], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edi;
    // 00470677  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047067a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047067c  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047067e  895c2450               -mov dword ptr [esp + 0x50], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00470682  e869faffff             -call 0x4700f0
    cpu.esp -= 4;
    sub_4700f0(app, cpu);
    if (cpu.terminate) return;
    // 00470687  8b04bd4c804c00         -mov eax, dword ptr [edi*4 + 0x4c804c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5013580) /* 0x4c804c */ + cpu.edi * 4);
    // 0047068e  8b7c2450               -mov edi, dword ptr [esp + 0x50]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470692  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00470694  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470696  8a4107                 -mov al, byte ptr [ecx + 7]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00470699  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0047069c  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004706a0  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004706a3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004706a5  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004706a7  897c2450               -mov dword ptr [esp + 0x50], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 004706ab  e840faffff             -call 0x4700f0
    cpu.esp -= 4;
    sub_4700f0(app, cpu);
    if (cpu.terminate) return;
    // 004706b0  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 004706b3  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706b4  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706b5  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706b6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004706b8:
    // 004706b8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004706ba  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004706be  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004706c0  e80b000000             -call 0x4706d0
    cpu.esp -= 4;
    sub_4706d0(app, cpu);
    if (cpu.terminate) return;
    // 004706c5  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 004706c8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706c9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706ca  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706cb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4706d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004706d0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004706d1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004706d2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004706d3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004706d4  81ecc0000000           -sub esp, 0xc0
    (cpu.esp) -= x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004706da  898424b0000000         -mov dword ptr [esp + 0xb0], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 004706e1  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004706e3  899c2498000000         -mov dword ptr [esp + 0x98], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ebx;
    // 004706ea  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004706ec  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004706ef:
    // 004706ef  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 004706f1  6683780e00             +cmp word ptr [eax + 0xe], 0
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004706f6  0f855c030000           -jne 0x470a58
    if (!cpu.flags.zf)
    {
        goto L_0x00470a58;
    }
L_0x004706fc:
    // 004706fc  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004706ff  39d9                   +cmp ecx, ebx
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
    // 00470701  75ec                   -jne 0x4706ef
    if (!cpu.flags.zf)
    {
        goto L_0x004706ef;
    }
    // 00470703  8b0d18955100           -mov ecx, dword ptr [0x519518]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5346584) /* 0x519518 */);
    // 00470709  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00470710  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00470713  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00470715  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00470717  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0047071e  898c248c000000         -mov dword ptr [esp + 0x8c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.ecx;
    // 00470725  8b7302                 -mov esi, dword ptr [ebx + 2]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00470728  8b82507c4c00           -mov eax, dword ptr [edx + 0x4c7c50]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5012560) /* 0x4c7c50 */);
    // 0047072e  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00470731  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00470733  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00470736  4e                     -dec esi
    (cpu.esi)--;
    // 00470737  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047073a  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0047073d  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047073e  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 00470740  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00470743  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00470745  d3fb                   -sar ebx, cl
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (cpu.cl % 32));
    // 00470747  0faf82547c4c00         -imul eax, dword ptr [edx + 0x4c7c54]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5012564) /* 0x4c7c54 */))));
    // 0047074e  899c24a0000000         -mov dword ptr [esp + 0xa0], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.ebx;
    // 00470755  898424a8000000         -mov dword ptr [esp + 0xa8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0047075c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047075e  0faf82587c4c00         -imul eax, dword ptr [edx + 0x4c7c58]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5012568) /* 0x4c7c58 */))));
    // 00470765  89b4249c000000         -mov dword ptr [esp + 0x9c], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.esi;
    // 0047076c  8bb424b0000000         -mov esi, dword ptr [esp + 0xb0]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00470773  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00470776  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0047077d  8b9c24b0000000         -mov ebx, dword ptr [esp + 0xb0]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00470784  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00470787  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx);
    // 00470789  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047078c  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047078f  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00470792  898424a4000000         -mov dword ptr [esp + 0xa4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00470799  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0047079b  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047079e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004707a0  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004707a3  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 004707a5  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004707a8  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 004707aa  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004707ad  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004707b0  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004707b3  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004707b5  899c24ac000000         -mov dword ptr [esp + 0xac], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 004707bc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004707be  754a                   -jne 0x47080a
    if (!cpu.flags.zf)
    {
        goto L_0x0047080a;
    }
    // 004707c0  8b9c24b0000000         -mov ebx, dword ptr [esp + 0xb0]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004707c7  8bb424b0000000         -mov esi, dword ptr [esp + 0xb0]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004707ce  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004707d5  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004707d8  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004707db  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004707de  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004707e1  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004707e4  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004707e7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
    // 004707e9  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004707ec  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx);
    // 004707ee  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004707f1  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 004707f3  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004707f6  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi)));
    // 004707f8  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004707fb  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004707fe  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00470801  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00470803  899c24ac000000         -mov dword ptr [esp + 0xac], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.ebx;
L_0x0047080a:
    // 0047080a  83bc249800000000       +cmp dword ptr [esp + 0x98], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470812  0f84f6020000           -je 0x470b0e
    if (cpu.flags.zf)
    {
        goto L_0x00470b0e;
    }
    // 00470818  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0047081f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470821  8bb424a8000000         -mov esi, dword ptr [esp + 0xa8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470828  8a5804                 -mov bl, byte ptr [eax + 4]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047082b  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00470832  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00470834  81c600800000           -add esi, 0x8000
    (cpu.esi) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 0047083a  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0047083d  8974dc40               -mov dword ptr [esp + ebx*8 + 0x40], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.ebx * 8) = cpu.esi;
    // 00470841  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00470844  8954dc44               -mov dword ptr [esp + ebx*8 + 0x44], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.ebx * 8) = cpu.edx;
    // 00470848  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0047084f  8954c440               -mov dword ptr [esp + eax*8 + 0x40], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.edx;
    // 00470853  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0047085a  8b8c24a8000000         -mov ecx, dword ptr [esp + 0xa8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470861  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00470867  8bbc249c000000         -mov edi, dword ptr [esp + 0x9c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0047086e  8954c444               -mov dword ptr [esp + eax*8 + 0x44], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.edx;
    // 00470872  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470879  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047087b  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047087d  8a5805                 -mov bl, byte ptr [eax + 5]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00470880  8db90080ffff           -lea edi, [ecx - 0x8000]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-32768) /* -0x8000 */);
    // 00470886  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00470888  89bc2494000000         -mov dword ptr [esp + 0x94], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 0047088f  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00470892  897cdc40               -mov dword ptr [esp + ebx*8 + 0x40], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.ebx * 8) = cpu.edi;
    // 00470896  8bbc24a4000000         -mov edi, dword ptr [esp + 0xa4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0047089d  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004708a0  897cdc44               -mov dword ptr [esp + ebx*8 + 0x44], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.ebx * 8) = cpu.edi;
    // 004708a4  894cc440               -mov dword ptr [esp + eax*8 + 0x40], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.ecx;
    // 004708a8  8954c444               -mov dword ptr [esp + eax*8 + 0x44], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.edx;
    // 004708ac  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004708b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004708b5  8a5806                 -mov bl, byte ptr [eax + 6]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004708b8  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004708ba  8b942494000000         -mov edx, dword ptr [esp + 0x94]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 004708c1  8954dc40               -mov dword ptr [esp + ebx*8 + 0x40], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.ebx * 8) = cpu.edx;
    // 004708c5  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004708c7  8bbc24a0000000         -mov edi, dword ptr [esp + 0xa0]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 004708ce  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004708d1  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004708d3  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004708d6  8954dc44               -mov dword ptr [esp + ebx*8 + 0x44], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.ebx * 8) = cpu.edx;
    // 004708da  894cc440               -mov dword ptr [esp + eax*8 + 0x40], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.ecx;
    // 004708de  8d8a0080ffff           -lea ecx, [edx - 0x8000]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-32768) /* -0x8000 */);
    // 004708e4  894cc444               -mov dword ptr [esp + eax*8 + 0x44], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.ecx;
    // 004708e8  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004708ef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004708f1  8a5807                 -mov bl, byte ptr [eax + 7]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004708f4  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004708f6  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 004708fb  8974dc40               -mov dword ptr [esp + ebx*8 + 0x40], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.ebx * 8) = cpu.esi;
    // 004708ff  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00470902  8954dc44               -mov dword ptr [esp + ebx*8 + 0x44], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.ebx * 8) = cpu.edx;
    // 00470906  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00470909  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047090b  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470912  899c24bc000000         -mov dword ptr [esp + 0xbc], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.ebx;
    // 00470919  8954c440               -mov dword ptr [esp + eax*8 + 0x40], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.edx;
    // 0047091d  899c24b8000000         -mov dword ptr [esp + 0xb8], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.ebx;
    // 00470924  894cc444               -mov dword ptr [esp + eax*8 + 0x44], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.ecx;
    // 00470928  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047092d  8b8c24b0000000         -mov ecx, dword ptr [esp + 0xb0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00470934  89942490000000         -mov dword ptr [esp + 0x90], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edx;
L_0x0047093b:
    // 0047093b  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0047093e  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00470941  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00470948  898424b4000000         -mov dword ptr [esp + 0xb4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0047094f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00470952  8b9424ac000000         -mov edx, dword ptr [esp + 0xac]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00470959  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047095b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047095d  0f8c6b010000           -jl 0x470ace
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470ace;
    }
    // 00470963  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax);
    // 00470965  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
L_0x00470967:
    // 00470967  8b5710                 -mov edx, dword ptr [edi + 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0047096a  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047096d  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00470970  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00470972  2b4714                 +sub eax, dword ptr [edi + 0x14]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00470975  7405                   -je 0x47097c
    if (cpu.flags.zf)
    {
        goto L_0x0047097c;
    }
    // 00470977  c1f81e                 -sar eax, 0x1e
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (30 /*0x1e*/ % 32));
    // 0047097a  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0047097c:
    // 0047097c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047097e  7406                   -je 0x470986
    if (cpu.flags.zf)
    {
        goto L_0x00470986;
    }
    // 00470980  c1fa1e                 -sar edx, 0x1e
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (30 /*0x1e*/ % 32));
    // 00470983  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00470986:
    // 00470986  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00470988  09d6                   +or esi, edx
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047098a  0f8447010000           -je 0x470ad7
    if (cpu.flags.zf)
    {
        goto L_0x00470ad7;
    }
    // 00470990  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00470992  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00470995  8bbc24b8000000         -mov edi, dword ptr [esp + 0xb8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0047099c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047099e  89343c                 -mov dword ptr [esp + edi], esi
    *app->getMemory<x86::reg32>(cpu.esp + cpu.edi * 1) = cpu.esi;
    // 004709a1  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx);
    // 004709a3  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004709a6  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004709a8  89743c04               -mov dword ptr [esp + edi + 4], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edi * 1) = cpu.esi;
    // 004709ac  8bb424b4000000         -mov esi, dword ptr [esp + 0xb4]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004709b3  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004709ba  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004709bd  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004709bf  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi);
    // 004709c1  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004709c4  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004709c6  8b842490000000         -mov eax, dword ptr [esp + 0x90]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004709cd  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004709d0  8934c4                 -mov dword ptr [esp + eax*8], esi
    *app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 8) = cpu.esi;
    // 004709d3  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi);
    // 004709d5  8b7e14                 -mov edi, dword ptr [esi + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004709d8  8bb424bc000000         -mov esi, dword ptr [esp + 0xbc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 004709df  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004709e1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004709e4  8954c404               -mov dword ptr [esp + eax*8 + 4], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = cpu.edx;
    // 004709e8  8b842490000000         -mov eax, dword ptr [esp + 0x90]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004709ef  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 004709f6  89b424bc000000         -mov dword ptr [esp + 0xbc], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.esi;
    // 004709fd  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00470a00  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00470a03  89842490000000         -mov dword ptr [esp + 0x90], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00470a0a  899424b8000000         -mov dword ptr [esp + 0xb8], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.edx;
L_0x00470a11:
    // 00470a11  43                     -inc ebx
    (cpu.ebx)++;
    // 00470a12  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470a15  83fb04                 +cmp ebx, 4
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
    // 00470a18  0f8c1dffffff           -jl 0x47093b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047093b;
    }
L_0x00470a1e:
    // 00470a1e  8b3d40955100           -mov edi, dword ptr [0x519540]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */);
    // 00470a24  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470a25  8b8424b0000000         -mov eax, dword ptr [esp + 0xb0]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00470a2c  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470a30  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00470a31  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00470a38  8d5c2448               -lea ebx, [esp + 0x48]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00470a3c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00470a3e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00470a40  e817da0100             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 00470a45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470a47  0f8c90010000           -jl 0x470bdd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470bdd;
    }
    // 00470a4d  81c4c0000000           -add esp, 0xc0
    (cpu.esp) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00470a53  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a54  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a55  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a56  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a57  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470a58:
    // 00470a58  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00470a5a  89842480000000         -mov dword ptr [esp + 0x80], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 00470a61  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00470a63  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00470a66  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 00470a6b  89842484000000         -mov dword ptr [esp + 0x84], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00470a72  89942488000000         -mov dword ptr [esp + 0x88], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 00470a79  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00470a7b  8db42480000000         -lea esi, [esp + 0x80]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00470a82  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00470a85  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00470a89  7e2a                   -jle 0x470ab5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00470ab5;
    }
    // 00470a8b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00470a8d  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 00470a93  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00470a96  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 00470a9c  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00470a9e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00470aa1  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 00470aa7  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00470aaa  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00470ab0  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00470ab3  eb14                   -jmp 0x470ac9
    goto L_0x00470ac9;
L_0x00470ab5:
    // 00470ab5  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00470abb  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00470ac2  830d94824c0001         +or dword ptr [0x4c8294], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/))));
L_0x00470ac9:
    // 00470ac9  e92efcffff             -jmp 0x4706fc
    goto L_0x004706fc;
L_0x00470ace:
    // 00470ace  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00470ad0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00470ad2  e990feffff             -jmp 0x470967
    goto L_0x00470967;
L_0x00470ad7:
    // 00470ad7  8bbc24bc000000         -mov edi, dword ptr [esp + 0xbc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 00470ade  83ed02                 -sub ebp, 2
    (cpu.ebp) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00470ae1  39fd                   +cmp ebp, edi
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
    // 00470ae3  0f8e28ffffff           -jle 0x470a11
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00470a11;
    }
    // 00470ae9  8d14ed00000000         -lea edx, [ebp*8]
    cpu.edx = x86::reg32(cpu.ebp * 8);
    // 00470af0  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
L_0x00470af7:
    // 00470af7  8d7c0440               -lea edi, [esp + eax + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 1);
    // 00470afb  8d740450               -lea esi, [esp + eax + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */ + cpu.eax * 1);
    // 00470aff  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00470b02  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470b03  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470b04  39d0                   +cmp eax, edx
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
    // 00470b06  0f8d05ffffff           -jge 0x470a11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00470a11;
    }
    // 00470b0c  ebe9                   -jmp 0x470af7
    goto L_0x00470af7;
L_0x00470b0e:
    // 00470b0e  8b8c24b0000000         -mov ecx, dword ptr [esp + 0xb0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00470b15  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 00470b1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00470b1c:
    // 00470b1c  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00470b1e  8d3c1c                 -lea edi, [esp + ebx]
    cpu.edi = x86::reg32(cpu.esp + cpu.ebx * 1);
    // 00470b21  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00470b24  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00470b27  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470b2a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470b2b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470b2c  83fb20                 +cmp ebx, 0x20
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470b2f  75eb                   -jne 0x470b1c
    if (!cpu.flags.zf)
    {
        goto L_0x00470b1c;
    }
    // 00470b31  8b94248c000000         -mov edx, dword ptr [esp + 0x8c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470b38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470b3a  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00470b3d  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470b44  8954c440               -mov dword ptr [esp + eax*8 + 0x40], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.edx;
    // 00470b48  8b94248c000000         -mov edx, dword ptr [esp + 0x8c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470b4f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470b51  8b9c249c000000         -mov ebx, dword ptr [esp + 0x9c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00470b58  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00470b5b  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00470b62  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470b69  8954c444               -mov dword ptr [esp + eax*8 + 0x44], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.edx;
    // 00470b6d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470b6f  8b8424a8000000         -mov eax, dword ptr [esp + 0xa8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470b76  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00470b79  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00470b7b  8944d440               -mov dword ptr [esp + edx*8 + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.eax;
    // 00470b7f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470b81  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00470b84  8b8c24a4000000         -mov ecx, dword ptr [esp + 0xa4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00470b8b  894cd444               -mov dword ptr [esp + edx*8 + 0x44], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.ecx;
    // 00470b8f  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470b96  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470b98  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00470b9b  8bb424a0000000         -mov esi, dword ptr [esp + 0xa0]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 00470ba2  8944d440               -mov dword ptr [esp + edx*8 + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.eax;
    // 00470ba6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470ba8  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00470baf  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00470bb2  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00470bb4  8944d444               -mov dword ptr [esp + edx*8 + 0x44], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.eax;
    // 00470bb8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470bba  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00470bbd  8b8c24a8000000         -mov ecx, dword ptr [esp + 0xa8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470bc4  894cd440               -mov dword ptr [esp + edx*8 + 0x40], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.ecx;
    // 00470bc8  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470bcf  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00470bd1  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00470bd4  8944d444               -mov dword ptr [esp + edx*8 + 0x44], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.eax;
    // 00470bd8  e941feffff             -jmp 0x470a1e
    goto L_0x00470a1e;
L_0x00470bdd:
    // 00470bdd  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00470be4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00470be6:
    // 00470be6  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx);
    // 00470be8  8d3c04                 -lea edi, [esp + eax]
    cpu.edi = x86::reg32(cpu.esp + cpu.eax * 1);
    // 00470beb  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00470bee  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00470bf1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470bf4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470bf5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470bf6  83f820                 +cmp eax, 0x20
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
    // 00470bf9  75eb                   -jne 0x470be6
    if (!cpu.flags.zf)
    {
        goto L_0x00470be6;
    }
    // 00470bfb  8b94248c000000         -mov edx, dword ptr [esp + 0x8c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470c02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470c04  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00470c07  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470c0e  8954c440               -mov dword ptr [esp + eax*8 + 0x40], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.edx;
    // 00470c12  8b94248c000000         -mov edx, dword ptr [esp + 0x8c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470c19  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470c1b  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00470c1e  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00470c25  8954c444               -mov dword ptr [esp + eax*8 + 0x44], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.edx;
    // 00470c29  8b8424a8000000         -mov eax, dword ptr [esp + 0xa8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470c30  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00470c37  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470c3e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00470c40  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470c42  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00470c45  8944d440               -mov dword ptr [esp + edx*8 + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.eax;
    // 00470c49  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470c4b  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00470c4e  8b8c24a4000000         -mov ecx, dword ptr [esp + 0xa4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00470c55  894cd444               -mov dword ptr [esp + edx*8 + 0x44], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.ecx;
    // 00470c59  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470c60  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470c62  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00470c65  8b8c24a0000000         -mov ecx, dword ptr [esp + 0xa0]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 00470c6c  8944d440               -mov dword ptr [esp + edx*8 + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.eax;
    // 00470c70  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00470c77  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00470c79  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470c80  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470c82  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00470c85  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00470c89  8944d444               -mov dword ptr [esp + edx*8 + 0x44], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.eax;
    // 00470c8d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470c8f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00470c91  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00470c94  8b8c24a8000000         -mov ecx, dword ptr [esp + 0xa8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00470c9b  8b1d40955100           -mov ebx, dword ptr [0x519540]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */);
    // 00470ca1  894cd440               -mov dword ptr [esp + edx*8 + 0x40], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.ecx;
    // 00470ca5  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470cac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470cae  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470caf  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00470cb2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470cb3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470cb4  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470cb6  8d7c2468               -lea edi, [esp + 0x68]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00470cba  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00470cbe  8944d44c               -mov dword ptr [esp + edx*8 + 0x4c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */ + cpu.edx * 8) = cpu.eax;
    // 00470cc2  8d5c2448               -lea ebx, [esp + 0x48]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00470cc6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470cc7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470cc8  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00470ccd  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00470ccf  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470cd3  e884d70100             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 00470cd8  8b3540955100           -mov esi, dword ptr [0x519540]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5346624) /* 0x519540 */);
    // 00470cde  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00470ce5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470ce6  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00470cea  8d5c2454               -lea ebx, [esp + 0x54]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00470cee  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470cf0  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00470cf5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 00470cf7  e860d70100             -call 0x48e45c
    cpu.esp -= 4;
    sub_48e45c(app, cpu);
    if (cpu.terminate) return;
    // 00470cfc  81c4c0000000           -add esp, 0xc0
    (cpu.esp) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00470d02  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d03  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d04  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d05  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470d10  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470d11  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470d12  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470d13  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470d14  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470d15  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470d16  81ec60130000           -sub esp, 0x1360
    (cpu.esp) -= x86::reg32(x86::sreg32(4960 /*0x1360*/));
    // 00470d1c  8b3528955100           -mov esi, dword ptr [0x519528]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5346600) /* 0x519528 */);
    // 00470d22  8a25b5854c00           -mov ah, byte ptr [0x4c85b5]
    cpu.ah = *app->getMemory<x86::reg8>(x86::reg32(5014965) /* 0x4c85b5 */);
    // 00470d28  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 00470d2d  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00470d2f  0f8484000000           -je 0x470db9
    if (cpu.flags.zf)
    {
        goto L_0x00470db9;
    }
    // 00470d35  bd50000000             -mov ebp, 0x50
    cpu.ebp = 80 /*0x50*/;
    // 00470d3a  bb2c010000             -mov ebx, 0x12c
    cpu.ebx = 300 /*0x12c*/;
    // 00470d3f  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00470d41  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470d43  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470d45  881580955100           -mov byte ptr [0x519580], dl
    *app->getMemory<x86::reg8>(x86::reg32(5346688) /* 0x519580 */) = cpu.dl;
    // 00470d4b  881581955100           -mov byte ptr [0x519581], dl
    *app->getMemory<x86::reg8>(x86::reg32(5346689) /* 0x519581 */) = cpu.dl;
    // 00470d51  881582955100           -mov byte ptr [0x519582], dl
    *app->getMemory<x86::reg8>(x86::reg32(5346690) /* 0x519582 */) = cpu.dl;
    // 00470d57  890da4945100           -mov dword ptr [0x5194a4], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346468) /* 0x5194a4 */) = cpu.ecx;
    // 00470d5d  890d94945100           -mov dword ptr [0x519494], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346452) /* 0x519494 */) = cpu.ecx;
    // 00470d63  892da8945100           -mov dword ptr [0x5194a8], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5346472) /* 0x5194a8 */) = cpu.ebp;
    // 00470d69  890d98945100           -mov dword ptr [0x519498], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346456) /* 0x519498 */) = cpu.ecx;
    // 00470d6f  891db0945100           -mov dword ptr [0x5194b0], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5346480) /* 0x5194b0 */) = cpu.ebx;
    // 00470d75  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00470d7a  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00470d7f  bd0f000000             -mov ebp, 0xf
    cpu.ebp = 15 /*0xf*/;
    // 00470d84  89157c955100           -mov dword ptr [0x51957c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346684) /* 0x51957c */) = cpu.edx;
    // 00470d8a  890d9c945100           -mov dword ptr [0x51949c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346460) /* 0x51949c */) = cpu.ecx;
    // 00470d90  ba55000000             -mov edx, 0x55
    cpu.edx = 85 /*0x55*/;
    // 00470d95  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 00470d9a  8915ac945100           -mov dword ptr [0x5194ac], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346476) /* 0x5194ac */) = cpu.edx;
    // 00470da0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00470da2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00470da4  892da0945100           -mov dword ptr [0x5194a0], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5346464) /* 0x5194a0 */) = cpu.ebp;
    // 00470daa  e8e186ffff             -call 0x469490
    cpu.esp -= 4;
    sub_469490(app, cpu);
    if (cpu.terminate) return;
    // 00470daf  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00470db4  e87727fcff             -call 0x433530
    cpu.esp -= 4;
    sub_433530(app, cpu);
    if (cpu.terminate) return;
L_0x00470db9:
    // 00470db9  a1a0945100             -mov eax, dword ptr [0x5194a0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346464) /* 0x5194a0 */);
    // 00470dbe  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00470dbf  8b15b0945100           -mov edx, dword ptr [0x5194b0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346480) /* 0x5194b0 */);
    // 00470dc5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470dc6  8b0d9c945100           -mov ecx, dword ptr [0x51949c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5346460) /* 0x51949c */);
    // 00470dcc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470dcd  8b1dac945100           -mov ebx, dword ptr [0x5194ac]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5346476) /* 0x5194ac */);
    // 00470dd3  8b3598945100           -mov esi, dword ptr [0x519498]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5346456) /* 0x519498 */);
    // 00470dd9  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470dda  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00470dde  8b15a4945100           -mov edx, dword ptr [0x5194a4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346468) /* 0x5194a4 */);
    // 00470de4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470de5  8b0da8945100           -mov ecx, dword ptr [0x5194a8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5346472) /* 0x5194a8 */);
    // 00470deb  8b1d94945100           -mov ebx, dword ptr [0x519494]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5346452) /* 0x519494 */);
    // 00470df1  e81aaffeff             -call 0x45bd10
    cpu.esp -= 4;
    sub_45bd10(app, cpu);
    if (cpu.terminate) return;
    // 00470df6  8b15b0945100           -mov edx, dword ptr [0x5194b0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346480) /* 0x5194b0 */);
    // 00470dfc  8b2da4945100           -mov ebp, dword ptr [0x5194a4]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5346468) /* 0x5194a4 */);
    // 00470e02  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00470e04  39ea                   +cmp edx, ebp
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
    // 00470e06  7c34                   -jl 0x470e3c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470e3c;
    }
    // 00470e08  8b0da4945100           -mov ecx, dword ptr [0x5194a4]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5346468) /* 0x5194a4 */);
    // 00470e0e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
L_0x00470e15:
    // 00470e15  8b1c04                 -mov ebx, dword ptr [esp + eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 00470e18  39df                   +cmp edi, ebx
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
    // 00470e1a  7418                   -je 0x470e34
    if (cpu.flags.zf)
    {
        goto L_0x00470e34;
    }
    // 00470e1c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00470e1e  83fe10                 +cmp esi, 0x10
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
    // 00470e21  7d11                   -jge 0x470e34
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00470e34;
    }
    // 00470e23  46                     -inc esi
    (cpu.esi)++;
    // 00470e24  8a1c04                 -mov bl, byte ptr [esp + eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00470e27  8914b5c0945100         -mov dword ptr [esi*4 + 0x5194c0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346496) /* 0x5194c0 */ + cpu.esi * 4) = cpu.edx;
    // 00470e2e  889eb3945100           -mov byte ptr [esi + 0x5194b3], bl
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5346483) /* 0x5194b3 */) = cpu.bl;
L_0x00470e34:
    // 00470e34  4a                     -dec edx
    (cpu.edx)--;
    // 00470e35  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470e38  39ca                   +cmp edx, ecx
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
    // 00470e3a  7dd9                   -jge 0x470e15
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00470e15;
    }
L_0x00470e3c:
    // 00470e3c  c705c4945100d7040000   -mov dword ptr [0x5194c4], 0x4d7
    *app->getMemory<x86::reg32>(x86::reg32(5346500) /* 0x5194c4 */) = 1239 /*0x4d7*/;
    // 00470e46  893528955100           -mov dword ptr [0x519528], esi
    *app->getMemory<x86::reg32>(x86::reg32(5346600) /* 0x519528 */) = cpu.esi;
    // 00470e4c  81c460130000           -add esp, 0x1360
    (cpu.esp) += x86::reg32(x86::sreg32(4960 /*0x1360*/));
    // 00470e52  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e53  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e54  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e55  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e56  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e57  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470e60  89148594945100         -mov dword ptr [eax*4 + 0x519494], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346452) /* 0x519494 */ + cpu.eax * 4) = cpu.edx;
    // 00470e67  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470e70  891485a4945100         -mov dword ptr [eax*4 + 0x5194a4], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346468) /* 0x5194a4 */ + cpu.eax * 4) = cpu.edx;
    // 00470e77  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470e80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470e90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470e90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 00000000000000000000000000000000 */
void Application::sub_470eb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470eb0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470eb1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470eb2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470eb3  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470eb4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470eb5  81ec88020000           -sub esp, 0x288
    (cpu.esp) -= x86::reg32(x86::sreg32(648 /*0x288*/));
    // 00470ebb  89b42474020000         -mov dword ptr [esp + 0x274], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(628) /* 0x274 */) = cpu.esi;
    // 00470ec2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00470ec4  e8a7070000             -call 0x471670
    cpu.esp -= 4;
    sub_471670(app, cpu);
    if (cpu.terminate) return;
    // 00470ec9  e8529efeff             -call 0x45ad20
    cpu.esp -= 4;
    sub_45ad20(app, cpu);
    if (cpu.terminate) return;
    // 00470ece  833f01                 +cmp dword ptr [edi], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470ed1  0f8401010000           -je 0x470fd8
    if (cpu.flags.zf)
    {
        goto L_0x00470fd8;
    }
L_0x00470ed7:
    // 00470ed7  833d2c96510000         +cmp dword ptr [0x51962c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5346860) /* 0x51962c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470ede  750d                   -jne 0x470eed
    if (!cpu.flags.zf)
    {
        goto L_0x00470eed;
    }
    // 00470ee0  833d7c95510000         +cmp dword ptr [0x51957c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5346684) /* 0x51957c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470ee7  0f84c9010000           -je 0x4710b6
    if (cpu.flags.zf)
    {
        goto L_0x004710b6;
    }
L_0x00470eed:
    // 00470eed  ba2c000000             -mov edx, 0x2c
    cpu.edx = 44 /*0x2c*/;
    // 00470ef2  8d84245c020000         -lea eax, [esp + 0x25c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470ef9  e8d29dfeff             -call 0x45acd0
    cpu.esp -= 4;
    sub_45acd0(app, cpu);
    if (cpu.terminate) return;
    // 00470efe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470f00  0f84a3000000           -je 0x470fa9
    if (cpu.flags.zf)
    {
        goto L_0x00470fa9;
    }
    // 00470f06  833d7c95510000         +cmp dword ptr [0x51957c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5346684) /* 0x51957c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470f0d  0f848d010000           -je 0x4710a0
    if (cpu.flags.zf)
    {
        goto L_0x004710a0;
    }
    // 00470f13  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00470f18  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f1f  bee0955100             -mov esi, 0x5195e0
    cpu.esi = 5346784 /*0x5195e0*/;
L_0x00470f24:
    // 00470f24  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470f26  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f2d  c6402901               -mov byte ptr [eax + 0x29], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */) = 1 /*0x1*/;
    // 00470f31  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f38  a18cd84d00             -mov eax, dword ptr [0x4dd88c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101708) /* 0x4dd88c */);
    // 00470f3d  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00470f40  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f47  a198d84d00             -mov eax, dword ptr [0x4dd898]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101720) /* 0x4dd898 */);
    // 00470f4c  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00470f4f  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f56  a188d84d00             -mov eax, dword ptr [0x4dd888]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101704) /* 0x4dd888 */);
    // 00470f5b  894210                 -mov dword ptr [edx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00470f5e  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f65  a198d84d00             -mov eax, dword ptr [0x4dd898]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101720) /* 0x4dd898 */);
    // 00470f6a  894214                 -mov dword ptr [edx + 0x14], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00470f6d  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f74  a188d84d00             -mov eax, dword ptr [0x4dd888]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101704) /* 0x4dd888 */);
    // 00470f79  894218                 -mov dword ptr [edx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00470f7c  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f83  a190d84d00             -mov eax, dword ptr [0x4dd890]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101712) /* 0x4dd890 */);
    // 00470f88  89421c                 -mov dword ptr [edx + 0x1c], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00470f8b  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470f92  a18cd84d00             -mov eax, dword ptr [0x4dd88c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101708) /* 0x4dd88c */);
    // 00470f97  894220                 -mov dword ptr [edx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00470f9a  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470fa1  a190d84d00             -mov eax, dword ptr [0x4dd890]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101712) /* 0x4dd890 */);
    // 00470fa6  894224                 -mov dword ptr [edx + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00470fa9:
    // 00470fa9  8db42450020000         -lea esi, [esp + 0x250]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(592) /* 0x250 */);
    // 00470fb0  e8db9cfeff             -call 0x45ac90
    cpu.esp -= 4;
    sub_45ac90(app, cpu);
    if (cpu.terminate) return;
    // 00470fb5  8bbc2474020000         -mov edi, dword ptr [esp + 0x274]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(628) /* 0x274 */);
    // 00470fbc  8db42450020000         -lea esi, [esp + 0x250]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(592) /* 0x250 */);
    // 00470fc3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470fc4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470fc5  8b842474020000         -mov eax, dword ptr [esp + 0x274]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(628) /* 0x274 */);
    // 00470fcc  81c488020000           -add esp, 0x288
    (cpu.esp) += x86::reg32(x86::sreg32(648 /*0x288*/));
    // 00470fd2  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fd3  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fd4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fd5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fd6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fd7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470fd8:
    // 00470fd8  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00470fdb  e89055fcff             -call 0x436570
    cpu.esp -= 4;
    sub_436570(app, cpu);
    if (cpu.terminate) return;
    // 00470fe0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470fe2  0f84effeffff           -je 0x470ed7
    if (cpu.flags.zf)
    {
        goto L_0x00470ed7;
    }
    // 00470fe8  ba2c000000             -mov edx, 0x2c
    cpu.edx = 44 /*0x2c*/;
    // 00470fed  8d84245c020000         -lea eax, [esp + 0x25c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00470ff4  e8d79cfeff             -call 0x45acd0
    cpu.esp -= 4;
    sub_45acd0(app, cpu);
    if (cpu.terminate) return;
    // 00470ff9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470ffb  74ac                   -je 0x470fa9
    if (cpu.flags.zf)
    {
        goto L_0x00470fa9;
    }
    // 00470ffd  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00471002  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471009  bee0955100             -mov esi, 0x5195e0
    cpu.esi = 5346784 /*0x5195e0*/;
    // 0047100e  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471010  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471017  c6402901               -mov byte ptr [eax + 0x29], 1
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */) = 1 /*0x1*/;
    // 0047101b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471022  8b158cd84d00           -mov edx, dword ptr [0x4dd88c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5101708) /* 0x4dd88c */);
    // 00471028  895008                 -mov dword ptr [eax + 8], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047102b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471032  8b1598d84d00           -mov edx, dword ptr [0x4dd898]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5101720) /* 0x4dd898 */);
    // 00471038  89500c                 -mov dword ptr [eax + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047103b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471042  8b1588d84d00           -mov edx, dword ptr [0x4dd888]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5101704) /* 0x4dd888 */);
    // 00471048  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047104b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471052  8b1598d84d00           -mov edx, dword ptr [0x4dd898]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5101720) /* 0x4dd898 */);
    // 00471058  895014                 -mov dword ptr [eax + 0x14], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0047105b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471062  8b1588d84d00           -mov edx, dword ptr [0x4dd888]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5101704) /* 0x4dd888 */);
    // 00471068  895018                 -mov dword ptr [eax + 0x18], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047106b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471072  8b1590d84d00           -mov edx, dword ptr [0x4dd890]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5101712) /* 0x4dd890 */);
    // 00471078  89501c                 -mov dword ptr [eax + 0x1c], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047107b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471082  8b158cd84d00           -mov edx, dword ptr [0x4dd88c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5101708) /* 0x4dd88c */);
    // 00471088  895020                 -mov dword ptr [eax + 0x20], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0047108b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471092  8b1590d84d00           -mov edx, dword ptr [0x4dd890]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5101712) /* 0x4dd890 */);
    // 00471098  895024                 -mov dword ptr [eax + 0x24], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0047109b  e909ffffff             -jmp 0x470fa9
    goto L_0x00470fa9;
L_0x004710a0:
    // 004710a0  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004710a5  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004710ac  be88955100             -mov esi, 0x519588
    cpu.esi = 5346696 /*0x519588*/;
    // 004710b1  e96efeffff             -jmp 0x470f24
    goto L_0x00470f24;
L_0x004710b6:
    // 004710b6  bacc000000             -mov edx, 0xcc
    cpu.edx = 204 /*0xcc*/;
    // 004710bb  8d842458020000         -lea eax, [esp + 0x258]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 004710c2  e8799dfeff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 004710c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004710c9  0f84dafeffff           -je 0x470fa9
    if (cpu.flags.zf)
    {
        goto L_0x00470fa9;
    }
    // 004710cf  8b8c2458020000         -mov ecx, dword ptr [esp + 0x258]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 004710d6  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 004710db  8b1d94d84d00           -mov ebx, dword ptr [0x4dd894]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5101716) /* 0x4dd894 */);
    // 004710e1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004710e3  e8a873fdff             -call 0x448490
    cpu.esp -= 4;
    sub_448490(app, cpu);
    if (cpu.terminate) return;
    // 004710e8  bacc000000             -mov edx, 0xcc
    cpu.edx = 204 /*0xcc*/;
    // 004710ed  8d842468020000         -lea eax, [esp + 0x268]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 004710f4  e8479dfeff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 004710f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004710fb  0f84a8feffff           -je 0x470fa9
    if (cpu.flags.zf)
    {
        goto L_0x00470fa9;
    }
    // 00471101  8b8c2468020000         -mov ecx, dword ptr [esp + 0x268]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 00471108  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 0047110d  8b1d9cd84d00           -mov ebx, dword ptr [0x4dd89c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5101724) /* 0x4dd89c */);
    // 00471113  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00471115  e87673fdff             -call 0x448490
    cpu.esp -= 4;
    sub_448490(app, cpu);
    if (cpu.terminate) return;
    // 0047111a  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0047111f  8d84246c020000         -lea eax, [esp + 0x26c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(620) /* 0x26c */);
    // 00471126  e8159dfeff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 0047112b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047112d  0f8476feffff           -je 0x470fa9
    if (cpu.flags.zf)
    {
        goto L_0x00470fa9;
    }
    // 00471133  8b8c246c020000         -mov ecx, dword ptr [esp + 0x26c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(620) /* 0x26c */);
    // 0047113a  bb0c965100             -mov ebx, 0x51960c
    cpu.ebx = 5346828 /*0x51960c*/;
    // 0047113f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00471144  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00471146  e84573fdff             -call 0x448490
    cpu.esp -= 4;
    sub_448490(app, cpu);
    if (cpu.terminate) return;
    // 0047114b  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00471150  8d842470020000         -lea eax, [esp + 0x270]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(624) /* 0x270 */);
    // 00471157  e8e49cfeff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 0047115c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047115e  0f8445feffff           -je 0x470fa9
    if (cpu.flags.zf)
    {
        goto L_0x00470fa9;
    }
    // 00471164  8b8c2470020000         -mov ecx, dword ptr [esp + 0x270]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(624) /* 0x270 */);
    // 0047116b  bb70955100             -mov ebx, 0x519570
    cpu.ebx = 5346672 /*0x519570*/;
    // 00471170  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00471175  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00471177  e81473fdff             -call 0x448490
    cpu.esp -= 4;
    sub_448490(app, cpu);
    if (cpu.terminate) return;
    // 0047117c  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00471181  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00471188  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 0047118f  bee1fa0000             -mov esi, 0xfae1
    cpu.esi = 64225 /*0xfae1*/;
    // 00471194  e847050000             -call 0x4716e0
    cpu.esp -= 4;
    sub_4716e0(app, cpu);
    if (cpu.terminate) return;
    // 00471199  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 0047119e  8d942410010000         -lea edx, [esp + 0x110]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004711a5  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 004711ac  b91c965100             -mov ecx, 0x51961c
    cpu.ecx = 5346844 /*0x51961c*/;
    // 004711b1  e82a050000             -call 0x4716e0
    cpu.esp -= 4;
    sub_4716e0(app, cpu);
    if (cpu.terminate) return;
    // 004711b6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004711bb  8d942440020000         -lea edx, [esp + 0x240]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(576) /* 0x240 */);
    // 004711c2  8b84246c020000         -mov eax, dword ptr [esp + 0x26c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(620) /* 0x26c */);
    // 004711c9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004711cb  e810050000             -call 0x4716e0
    cpu.esp -= 4;
    sub_4716e0(app, cpu);
    if (cpu.terminate) return;
    // 004711d0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004711d5  8d942448020000         -lea edx, [esp + 0x248]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(584) /* 0x248 */);
    // 004711dc  8b842470020000         -mov eax, dword ptr [esp + 0x270]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(624) /* 0x270 */);
    // 004711e3  89bc247c020000         -mov dword ptr [esp + 0x27c], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */) = cpu.edi;
    // 004711ea  e8f1040000             -call 0x4716e0
    cpu.esp -= 4;
    sub_4716e0(app, cpu);
    if (cpu.terminate) return;
    // 004711ef  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004711f1  8d9c248c000000         -lea ebx, [esp + 0x8c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004711f8  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004711ff  6a11                   -push 0x11
    *app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00471201  8d8424a0010000         -lea eax, [esp + 0x1a0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 00471208  89bc2488020000         -mov dword ptr [esp + 0x288], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(648) /* 0x288 */) = cpu.edi;
    // 0047120f  e83c70fdff             -call 0x448250
    cpu.esp -= 4;
    sub_448250(app, cpu);
    if (cpu.terminate) return;
    // 00471214  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00471216  8d8c2468020000         -lea ecx, [esp + 0x268]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 0047121d  8d9c248c000000         -lea ebx, [esp + 0x8c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00471224  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0047122b  6a11                   -push 0x11
    *app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 0047122d  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471231  89b4246c020000         -mov dword ptr [esp + 0x26c], esi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(620) /* 0x26c */) = cpu.esi;
    // 00471238  e81370fdff             -call 0x448250
    cpu.esp -= 4;
    sub_448250(app, cpu);
    if (cpu.terminate) return;
    // 0047123d  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00471242  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00471247  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471249  89842484020000         -mov dword ptr [esp + 0x284], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */) = cpu.eax;
    // 00471250  89942478020000         -mov dword ptr [esp + 0x278], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */) = cpu.edx;
L_0x00471257:
    // 00471257  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 0047125e  8bb42480020000         -mov esi, dword ptr [esp + 0x280]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 00471265  8b2d30965100           -mov ebp, dword ptr [0x519630]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5346864) /* 0x519630 */);
    // 0047126b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047126d  c1fd02                 -sar ebp, 2
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (2 /*0x2*/ % 32));
    // 00471270  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471273  0f8f1e030000           -jg 0x471597
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471597;
    }
L_0x00471279:
    // 00471279  8dbc2420020000         -lea edi, [esp + 0x220]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00471280  8d741c08               -lea esi, [esp + ebx + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.ebx * 1);
    // 00471284  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471285  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471286  8dbc2428020000         -lea edi, [esp + 0x228]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 0047128d  8d341c                 -lea esi, [esp + ebx]
    cpu.esi = x86::reg32(cpu.esp + cpu.ebx * 1);
    // 00471290  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471291  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471292  8dbc2430020000         -lea edi, [esp + 0x230]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 00471299  8db42440020000         -lea esi, [esp + 0x240]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(576) /* 0x240 */);
    // 004712a0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004712a1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004712a2  8dbc2438020000         -lea edi, [esp + 0x238]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 004712a9  8db42440020000         -lea esi, [esp + 0x240]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(576) /* 0x240 */);
    // 004712b0  8d842420020000         -lea eax, [esp + 0x220]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004712b7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004712b8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004712b9  e88270fdff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 004712be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004712c0  0f847f000000           -je 0x471345
    if (cpu.flags.zf)
    {
        goto L_0x00471345;
    }
    // 004712c6  ba2c000000             -mov edx, 0x2c
    cpu.edx = 44 /*0x2c*/;
    // 004712cb  8d84245c020000         -lea eax, [esp + 0x25c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004712d2  e8f999feff             -call 0x45acd0
    cpu.esp -= 4;
    sub_45acd0(app, cpu);
    if (cpu.terminate) return;
    // 004712d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004712d9  746a                   -je 0x471345
    if (cpu.flags.zf)
    {
        goto L_0x00471345;
    }
    // 004712db  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004712e0  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004712e7  be88955100             -mov esi, 0x519588
    cpu.esi = 5346696 /*0x519588*/;
    // 004712ec  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004712ee  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004712f5  c6402900               -mov byte ptr [eax + 0x29], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */) = 0 /*0x0*/;
    // 004712f9  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471300  8db42420020000         -lea esi, [esp + 0x220]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00471307  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047130a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047130b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047130c  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471313  8db42428020000         -lea esi, [esp + 0x228]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 0047131a  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0047131d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047131e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047131f  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471326  8db42430020000         -lea esi, [esp + 0x230]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 0047132d  8d7f18                 -lea edi, [edi + 0x18]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00471330  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471331  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471332  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471339  8db42438020000         -lea esi, [esp + 0x238]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 00471340  8d7f20                 -lea edi, [edi + 0x20]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00471343  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471344  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x00471345:
    // 00471345  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 0047134c  03842480020000         -add eax, dword ptr [esp + 0x280]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */)));
    // 00471353  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471356  0f8f57020000           -jg 0x4715b3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004715b3;
    }
L_0x0047135c:
    // 0047135c  8dbc2420020000         -lea edi, [esp + 0x220]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00471363  8db41c98010000         -lea esi, [esp + ebx + 0x198]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(408) /* 0x198 */ + cpu.ebx * 1);
    // 0047136a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047136b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047136c  8dbc2428020000         -lea edi, [esp + 0x228]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 00471373  8db41ca0010000         -lea esi, [esp + ebx + 0x1a0]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */ + cpu.ebx * 1);
    // 0047137a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047137b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047137c  8dbc2430020000         -lea edi, [esp + 0x230]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 00471383  8db42448020000         -lea esi, [esp + 0x248]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(584) /* 0x248 */);
    // 0047138a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047138b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047138c  8dbc2438020000         -lea edi, [esp + 0x238]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 00471393  8db42448020000         -lea esi, [esp + 0x248]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(584) /* 0x248 */);
    // 0047139a  8d842420020000         -lea eax, [esp + 0x220]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004713a1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004713a2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004713a3  e8986ffdff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 004713a8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004713aa  0f847f000000           -je 0x47142f
    if (cpu.flags.zf)
    {
        goto L_0x0047142f;
    }
    // 004713b0  ba2c000000             -mov edx, 0x2c
    cpu.edx = 44 /*0x2c*/;
    // 004713b5  8d84245c020000         -lea eax, [esp + 0x25c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004713bc  e80f99feff             -call 0x45acd0
    cpu.esp -= 4;
    sub_45acd0(app, cpu);
    if (cpu.terminate) return;
    // 004713c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004713c3  746a                   -je 0x47142f
    if (cpu.flags.zf)
    {
        goto L_0x0047142f;
    }
    // 004713c5  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 004713ca  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004713d1  beb4955100             -mov esi, 0x5195b4
    cpu.esi = 5346740 /*0x5195b4*/;
    // 004713d6  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004713d8  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004713df  c6402900               -mov byte ptr [eax + 0x29], 0
    *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */) = 0 /*0x0*/;
    // 004713e3  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004713ea  8db42420020000         -lea esi, [esp + 0x220]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004713f1  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004713f4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004713f5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004713f6  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 004713fd  8db42428020000         -lea esi, [esp + 0x228]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 00471404  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00471407  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471408  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471409  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471410  8db42430020000         -lea esi, [esp + 0x230]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 00471417  8d7f18                 -lea edi, [edi + 0x18]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047141a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047141b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047141c  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00471423  8db42438020000         -lea esi, [esp + 0x238]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 0047142a  8d7f20                 -lea edi, [edi + 0x20]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0047142d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047142e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x0047142f:
    // 0047142f  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 00471436  8bb42480020000         -mov esi, dword ptr [esp + 0x280]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 0047143d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047143f  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471442  0f8f87010000           -jg 0x4715cf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004715cf;
    }
L_0x00471448:
    // 00471448  833d2496510000         +cmp dword ptr [0x519624], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5346852) /* 0x519624 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047144f  0f84bc010000           -je 0x471611
    if (cpu.flags.zf)
    {
        goto L_0x00471611;
    }
    // 00471455  83bc247c02000007       +cmp dword ptr [esp + 0x27c], 7
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047145d  0f8eae010000           -jle 0x471611
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471611;
    }
    // 00471463  8b842478020000         -mov eax, dword ptr [esp + 0x278]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */);
    // 0047146a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047146c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00471471  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00471474  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471476  8dbc2420020000         -lea edi, [esp + 0x220]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047147d  8db41c90000000         -lea esi, [esp + ebx + 0x90]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */ + cpu.ebx * 1);
    // 00471484  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471485  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471486  8dbc2428020000         -lea edi, [esp + 0x228]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 0047148d  8db41c88000000         -lea esi, [esp + ebx + 0x88]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */ + cpu.ebx * 1);
    // 00471494  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471495  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471496  8dbc2430020000         -lea edi, [esp + 0x230]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 0047149d  8db41c98010000         -lea esi, [esp + ebx + 0x198]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(408) /* 0x198 */ + cpu.ebx * 1);
    // 004714a4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004714a5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004714a6  8dbc2438020000         -lea edi, [esp + 0x238]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 004714ad  8db41ca0010000         -lea esi, [esp + ebx + 0x1a0]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */ + cpu.ebx * 1);
L_0x004714b4:
    // 004714b4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004714b5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004714b6  8b2c9550955100         -mov ebp, dword ptr [edx*4 + 0x519550]
    cpu.ebp = *app->getMemory<x86::reg32>(x86::reg32(5346640) /* 0x519550 */ + cpu.edx * 4);
    // 004714bd  8d842420020000         -lea eax, [esp + 0x220]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004714c4  e8776efdff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 004714c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004714cb  7479                   -je 0x471546
    if (cpu.flags.zf)
    {
        goto L_0x00471546;
    }
    // 004714cd  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 004714d2  8d842460020000         -lea eax, [esp + 0x260]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004714d9  e8f297feff             -call 0x45acd0
    cpu.esp -= 4;
    sub_45acd0(app, cpu);
    if (cpu.terminate) return;
    // 004714de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004714e0  7464                   -je 0x471546
    if (cpu.flags.zf)
    {
        goto L_0x00471546;
    }
    // 004714e2  8b842460020000         -mov eax, dword ptr [esp + 0x260]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004714e9  c7400415000000         -mov dword ptr [eax + 4], 0x15
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 21 /*0x15*/;
    // 004714f0  8b842460020000         -mov eax, dword ptr [esp + 0x260]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004714f7  896828                 -mov dword ptr [eax + 0x28], ebp
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 004714fa  8bbc2460020000         -mov edi, dword ptr [esp + 0x260]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 00471501  8db42420020000         -lea esi, [esp + 0x220]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00471508  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047150b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047150c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047150d  8bbc2460020000         -mov edi, dword ptr [esp + 0x260]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 00471514  8db42428020000         -lea esi, [esp + 0x228]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 0047151b  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0047151e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047151f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471520  8bbc2460020000         -mov edi, dword ptr [esp + 0x260]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 00471527  8db42430020000         -lea esi, [esp + 0x230]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 0047152e  8d7f18                 -lea edi, [edi + 0x18]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00471531  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471532  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471533  8bbc2460020000         -mov edi, dword ptr [esp + 0x260]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 0047153a  8db42438020000         -lea esi, [esp + 0x238]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 00471541  8d7f20                 -lea edi, [edi + 0x20]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00471544  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471545  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x00471546:
    // 00471546  8b842484020000         -mov eax, dword ptr [esp + 0x284]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */);
    // 0047154d  8b942478020000         -mov edx, dword ptr [esp + 0x278]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */);
    // 00471554  8b8c247c020000         -mov ecx, dword ptr [esp + 0x27c]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */);
    // 0047155b  8bac2480020000         -mov ebp, dword ptr [esp + 0x280]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 00471562  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00471565  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00471568  4a                     -dec edx
    (cpu.edx)--;
    // 00471569  41                     -inc ecx
    (cpu.ecx)++;
    // 0047156a  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047156d  89842484020000         -mov dword ptr [esp + 0x284], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */) = cpu.eax;
    // 00471574  89942478020000         -mov dword ptr [esp + 0x278], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */) = cpu.edx;
    // 0047157b  898c247c020000         -mov dword ptr [esp + 0x27c], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */) = cpu.ecx;
    // 00471582  89ac2480020000         -mov dword ptr [esp + 0x280], ebp
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */) = cpu.ebp;
    // 00471589  83f910                 +cmp ecx, 0x10
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
    // 0047158c  0f8cc5fcffff           -jl 0x471257
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471257;
    }
    // 00471592  e912faffff             -jmp 0x470fa9
    goto L_0x00470fa9;
L_0x00471597:
    // 00471597  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 0047159e  03842484020000         -add eax, dword ptr [esp + 0x284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */)));
    // 004715a5  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715a8  0f8ecbfcffff           -jle 0x471279
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471279;
    }
    // 004715ae  e992fdffff             -jmp 0x471345
    goto L_0x00471345;
L_0x004715b3:
    // 004715b3  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 004715ba  03842484020000         -add eax, dword ptr [esp + 0x284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */)));
    // 004715c1  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715c4  0f8e92fdffff           -jle 0x47135c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047135c;
    }
    // 004715ca  e960feffff             -jmp 0x47142f
    goto L_0x0047142f;
L_0x004715cf:
    // 004715cf  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 004715d6  8b942484020000         -mov edx, dword ptr [esp + 0x284]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */);
    // 004715dd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004715df  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715e2  0f8e60feffff           -jle 0x471448
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471448;
    }
    // 004715e8  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 004715ef  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004715f1  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715f4  0f8e4efeffff           -jle 0x471448
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471448;
    }
    // 004715fa  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 00471601  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00471603  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471606  0f8e3cfeffff           -jle 0x471448
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471448;
    }
    // 0047160c  e935ffffff             -jmp 0x471546
    goto L_0x00471546;
L_0x00471611:
    // 00471611  8b84247c020000         -mov eax, dword ptr [esp + 0x27c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */);
    // 00471618  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047161a  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0047161f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00471622  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471624  8dbc2420020000         -lea edi, [esp + 0x220]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047162b  8db41c88000000         -lea esi, [esp + ebx + 0x88]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */ + cpu.ebx * 1);
    // 00471632  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471633  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471634  8dbc2428020000         -lea edi, [esp + 0x228]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 0047163b  8db41c90000000         -lea esi, [esp + ebx + 0x90]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */ + cpu.ebx * 1);
    // 00471642  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471643  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471644  8dbc2430020000         -lea edi, [esp + 0x230]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 0047164b  8db41ca0010000         -lea esi, [esp + ebx + 0x1a0]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */ + cpu.ebx * 1);
    // 00471652  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471653  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471654  8dbc2438020000         -lea edi, [esp + 0x238]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 0047165b  8db41c98010000         -lea esi, [esp + ebx + 0x198]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(408) /* 0x198 */ + cpu.ebx * 1);
    // 00471662  e94dfeffff             -jmp 0x4714b4
    goto L_0x004714b4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471670  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471671  833801                 +cmp dword ptr [eax], 1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471674  7528                   -jne 0x47169e
    if (!cpu.flags.zf)
    {
        goto L_0x0047169e;
    }
    // 00471676  8b506c                 -mov edx, dword ptr [eax + 0x6c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    // 00471679  891598d84d00           -mov dword ptr [0x4dd898], edx
    *app->getMemory<x86::reg32>(x86::reg32(5101720) /* 0x4dd898 */) = cpu.edx;
    // 0047167f  83c246                 -add edx, 0x46
    (cpu.edx) += x86::reg32(x86::sreg32(70 /*0x46*/));
    // 00471682  891590d84d00           -mov dword ptr [0x4dd890], edx
    *app->getMemory<x86::reg32>(x86::reg32(5101712) /* 0x4dd890 */) = cpu.edx;
    // 00471688  8b5068                 -mov edx, dword ptr [eax + 0x68]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 0047168b  89158cd84d00           -mov dword ptr [0x4dd88c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5101708) /* 0x4dd88c */) = cpu.edx;
    // 00471691  8d8296000000           -lea eax, [edx + 0x96]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(150) /* 0x96 */);
    // 00471697  a388d84d00             -mov dword ptr [0x4dd888], eax
    *app->getMemory<x86::reg32>(x86::reg32(5101704) /* 0x4dd888 */) = cpu.eax;
    // 0047169c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047169d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047169e:
    // 0047169e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047169f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004716a0  6890d84d00             -push 0x4dd890
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5101712 /*0x4dd890*/;
    cpu.esp -= 4;
    // 004716a5  b988d84d00             -mov ecx, 0x4dd888
    cpu.ecx = 5101704 /*0x4dd888*/;
    // 004716aa  bb98d84d00             -mov ebx, 0x4dd898
    cpu.ebx = 5101720 /*0x4dd898*/;
    // 004716af  ba8cd84d00             -mov edx, 0x4dd88c
    cpu.edx = 5101708 /*0x4dd88c*/;
    // 004716b4  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004716b7  e8d4d8ffff             -call 0x46ef90
    cpu.esp -= 4;
    sub_46ef90(app, cpu);
    if (cpu.terminate) return;
    // 004716bc  a198d84d00             -mov eax, dword ptr [0x4dd898]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101720) /* 0x4dd898 */);
    // 004716c1  010590d84d00           -add dword ptr [0x4dd890], eax
    (*app->getMemory<x86::reg32>(x86::reg32(5101712) /* 0x4dd890 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004716c7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716c8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716c9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4716d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004716d0  80352c96510001         -xor byte ptr [0x51962c], 1
    *app->getMemory<x86::reg8>(x86::reg32(5346860) /* 0x51962c */) ^= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004716d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4716e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004716e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004716e1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004716e2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004716e3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004716e4  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004716e7  89442450               -mov dword ptr [esp + 0x50], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004716eb  8954244c               -mov dword ptr [esp + 0x4c], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004716ef  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004716f1  8d7c2444               -lea edi, [esp + 0x44]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004716f5  bea00e4700             -mov esi, 0x470ea0
    cpu.esi = 4656800 /*0x470ea0*/;
    // 004716fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004716fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004716fc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004716fe  7e20                   -jle 0x471720
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471720;
    }
    // 00471700  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00471703  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00471705:
    // 00471705  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471708  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047170b  890c14                 -mov dword ptr [esp + edx], ecx
    *app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 1) = cpu.ecx;
    // 0047170e  8b0d28965100           -mov ecx, dword ptr [0x519628]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5346856) /* 0x519628 */);
    // 00471714  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471717  8948fc                 -mov dword ptr [eax - 4], ecx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0047171a  39da                   +cmp edx, ebx
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
    // 0047171c  7ce7                   -jl 0x471705
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471705;
    }
    // 0047171e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00471720:
    // 00471720  8d4c2444               -lea ecx, [esp + 0x44]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00471724  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00471728  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047172c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047172e  e8cd6cfdff             -call 0x448400
    cpu.esp -= 4;
    sub_448400(app, cpu);
    if (cpu.terminate) return;
    // 00471733  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00471735  7e1d                   -jle 0x471754
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471754;
    }
    // 00471737  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047173b  8d1cad00000000         -lea ebx, [ebp*4]
    cpu.ebx = x86::reg32(cpu.ebp * 4);
    // 00471742  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00471744:
    // 00471744  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00471747  8b0c04                 -mov ecx, dword ptr [esp + eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 0047174a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047174d  894afc                 -mov dword ptr [edx - 4], ecx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00471750  39d8                   +cmp eax, ebx
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
    // 00471752  7cf0                   -jl 0x471744
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471744;
    }
L_0x00471754:
    // 00471754  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 00471757  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471758  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471759  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047175a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047175b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_471760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471760  a194d84d00             -mov eax, dword ptr [0x4dd894]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101716) /* 0x4dd894 */);
    // 00471765  e862730000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0047176a  a19cd84d00             -mov eax, dword ptr [0x4dd89c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101724) /* 0x4dd89c */);
    // 0047176f  e958730000             -jmp 0x478acc
    return sub_478acc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471780  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471781  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471782  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471783  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471784  ba90c64b00             -mov edx, 0x4bc690
    cpu.edx = 4966032 /*0x4bc690*/;
    // 00471789  b9c5000000             -mov ecx, 0xc5
    cpu.ecx = 197 /*0xc5*/;
    // 0047178e  bec7000000             -mov esi, 0xc7
    cpu.esi = 199 /*0xc7*/;
    // 00471793  a130d34d00             -mov eax, dword ptr [0x4dd330]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5100336) /* 0x4dd330 */);
    // 00471798  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047179a  a32c965100             -mov dword ptr [0x51962c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346860) /* 0x51962c */) = cpu.eax;
    // 0047179f  89158c844c00           -mov dword ptr [0x4c848c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 004717a5  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 004717aa  b8acc64b00             -mov eax, 0x4bc6ac
    cpu.eax = 4966060 /*0x4bc6ac*/;
    // 004717af  890d90844c00           -mov dword ptr [0x4c8490], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 004717b5  e8ae6e0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 004717ba  bb90c64b00             -mov ebx, 0x4bc690
    cpu.ebx = 4966032 /*0x4bc690*/;
    // 004717bf  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 004717c4  a394d84d00             -mov dword ptr [0x4dd894], eax
    *app->getMemory<x86::reg32>(x86::reg32(5101716) /* 0x4dd894 */) = cpu.eax;
    // 004717c9  b8bcc64b00             -mov eax, 0x4bc6bc
    cpu.eax = 4966076 /*0x4bc6bc*/;
    // 004717ce  891d8c844c00           -mov dword ptr [0x4c848c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebx;
    // 004717d4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004717d6  893590844c00           -mov dword ptr [0x4c8490], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.esi;
    // 004717dc  e8876e0000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 004717e1  a39cd84d00             -mov dword ptr [0x4dd89c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5101724) /* 0x4dd89c */) = cpu.eax;
    // 004717e6  e805000000             -call 0x4717f0
    cpu.esp -= 4;
    sub_4717f0(app, cpu);
    if (cpu.terminate) return;
    // 004717eb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717ec  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717ed  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717ee  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4717f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004717f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004717f1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004717f2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004717f3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004717f4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004717f5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004717f7  89150c965100           -mov dword ptr [0x51960c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346828) /* 0x51960c */) = cpu.edx;
    // 004717fd  8b1534965100           -mov edx, dword ptr [0x519634]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346868) /* 0x519634 */);
    // 00471803  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047180a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047180c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047180e  8b1520965100           -mov edx, dword ptr [0x519620]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346848) /* 0x519620 */);
    // 00471814  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471816  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471818  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047181a  890d14965100           -mov dword ptr [0x519614], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346836) /* 0x519614 */) = cpu.ecx;
    // 00471820  891510965100           -mov dword ptr [0x519610], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346832) /* 0x519610 */) = cpu.edx;
    // 00471826  8b1520965100           -mov edx, dword ptr [0x519620]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346848) /* 0x519620 */);
    // 0047182c  890d70955100           -mov dword ptr [0x519570], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346672) /* 0x519570 */) = cpu.ecx;
    // 00471832  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471834  890d78955100           -mov dword ptr [0x519578], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5346680) /* 0x519578 */) = cpu.ecx;
    // 0047183a  891574955100           -mov dword ptr [0x519574], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346676) /* 0x519574 */) = cpu.edx;
L_0x00471840:
    // 00471840  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00471842  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471844  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00471847  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0047184a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047184c  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047184f  8b3584955100           -mov esi, dword ptr [0x519584]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5346692) /* 0x519584 */);
    // 00471855  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471857  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00471859  8b1530965100           -mov edx, dword ptr [0x519630]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346864) /* 0x519630 */);
    // 0047185f  e8fc900100             -call 0x48a960
    cpu.esp -= 4;
    sub_48a960(app, cpu);
    if (cpu.terminate) return;
    // 00471864  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471866  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00471869  c1e810                 +shr eax, 0x10
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
    // 0047186c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047186e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471870  a19cd84d00             -mov eax, dword ptr [0x4dd89c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101724) /* 0x4dd89c */);
    // 00471875  891403                 -mov dword ptr [ebx + eax], edx
    *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 00471878  8b1520965100           -mov edx, dword ptr [0x519620]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346848) /* 0x519620 */);
    // 0047187e  89540304               -mov dword ptr [ebx + eax + 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.edx;
    // 00471882  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00471884  8b1530965100           -mov edx, dword ptr [0x519630]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346864) /* 0x519630 */);
    // 0047188a  e841910100             -call 0x48a9d0
    cpu.esp -= 4;
    sub_48a9d0(app, cpu);
    if (cpu.terminate) return;
    // 0047188f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471891  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00471894  c1e810                 +shr eax, 0x10
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
    // 00471897  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00471899  8b359cd84d00           -mov esi, dword ptr [0x4dd89c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5101724) /* 0x4dd89c */);
    // 0047189f  89441e08               -mov dword ptr [esi + ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ebx * 1) = cpu.eax;
    // 004718a3  a194d84d00             -mov eax, dword ptr [0x4dd894]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5101716) /* 0x4dd894 */);
    // 004718a8  8b141e                 -mov edx, dword ptr [esi + ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + cpu.ebx * 1);
    // 004718ab  891403                 -mov dword ptr [ebx + eax], edx
    *app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004718ae  8b3d34965100           -mov edi, dword ptr [0x519634]
    cpu.edi = *app->getMemory<x86::reg32>(x86::reg32(5346868) /* 0x519634 */);
    // 004718b4  8b541e04               -mov edx, dword ptr [esi + ebx + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebx * 1);
    // 004718b8  83c30c                 -add ebx, 0xc
    (cpu.ebx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004718bb  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004718bd  895403f8               -mov dword ptr [ebx + eax - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 004718c1  8b541efc               -mov edx, dword ptr [esi + ebx - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ebx * 1);
    // 004718c5  81c100000100           -add ecx, 0x10000
    (cpu.ecx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 004718cb  895403fc               -mov dword ptr [ebx + eax - 4], edx
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 004718cf  81f900002000           +cmp ecx, 0x200000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2097152 /*0x200000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004718d5  0f8565ffffff           -jne 0x471840
    if (!cpu.flags.zf)
    {
        goto L_0x00471840;
    }
    // 004718db  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718dc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718dd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718de  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718df  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4718f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004718f0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004718f1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004718f2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004718f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004718f5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004718f7  a082955100             -mov al, byte ptr [0x519582]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5346690) /* 0x519582 */);
    // 004718fc  8a1581955100           -mov dl, byte ptr [0x519581]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5346689) /* 0x519581 */);
    // 00471902  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00471905  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 00471908  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047190a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047190c  a080955100             -mov al, byte ptr [0x519580]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5346688) /* 0x519580 */);
    // 00471911  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 00471913  e8444c0000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00471918  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047191a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047191c  a01a965100             -mov al, byte ptr [0x51961a]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5346842) /* 0x51961a */);
    // 00471921  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471923  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471925  a019965100             -mov al, byte ptr [0x519619]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5346841) /* 0x519619 */);
    // 0047192a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047192d  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00471930  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00471932  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471934  a018965100             -mov al, byte ptr [0x519618]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5346840) /* 0x519618 */);
    // 00471939  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047193b  e81c4c0000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 00471940  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471942  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471944  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 00471949  e80e4c0000             -call 0x47655c
    cpu.esp -= 4;
    sub_47655c(app, cpu);
    if (cpu.terminate) return;
    // 0047194e  891d8c955100           -mov dword ptr [0x51958c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5346700) /* 0x51958c */) = cpu.ebx;
    // 00471954  880db0955100           -mov byte ptr [0x5195b0], cl
    *app->getMemory<x86::reg8>(x86::reg32(5346736) /* 0x5195b0 */) = cpu.cl;
    // 0047195a  891db8955100           -mov dword ptr [0x5195b8], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5346744) /* 0x5195b8 */) = cpu.ebx;
    // 00471960  8815dc955100           -mov byte ptr [0x5195dc], dl
    *app->getMemory<x86::reg8>(x86::reg32(5346780) /* 0x5195dc */) = cpu.dl;
    // 00471966  891de4955100           -mov dword ptr [0x5195e4], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5346788) /* 0x5195e4 */) = cpu.ebx;
    // 0047196c  a208965100             -mov byte ptr [0x519608], al
    *app->getMemory<x86::reg8>(x86::reg32(5346824) /* 0x519608 */) = cpu.al;
    // 00471971  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471972  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471973  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471974  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471980  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471981  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471983  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00471985:
    // 00471985  899050955100           -mov dword ptr [eax + 0x519550], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5346640) /* 0x519550 */) = cpu.edx;
    // 0047198b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047198e  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00471991  83f820                 +cmp eax, 0x20
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
    // 00471994  75ef                   -jne 0x471985
    if (!cpu.flags.zf)
    {
        goto L_0x00471985;
    }
    // 00471996  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471997  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4719a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004719a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004719a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004719a2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004719a3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004719a4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004719a5  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004719ab  8b15fcd24d00           -mov edx, dword ptr [0x4dd2fc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5100284) /* 0x4dd2fc */);
    // 004719b1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004719b2  8b0d5ce54d00           -mov ecx, dword ptr [0x4de55c]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5104988) /* 0x4de55c */);
    // 004719b8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004719b9  6880c64b00             -push 0x4bc680
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4966016 /*0x4bc680*/;
    cpu.esp -= 4;
    // 004719be  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004719c2  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004719c3  e8598a0000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004719c8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004719cb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004719cd  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004719cf  e8cc920000             -call 0x47aca0
    cpu.esp -= 4;
    sub_47aca0(app, cpu);
    if (cpu.terminate) return;
    // 004719d4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004719d6  89842400010000         -mov dword ptr [esp + 0x100], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.eax;
    // 004719dd  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004719e4  e847a8feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 004719e9  a37c955100             -mov dword ptr [0x51957c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346684) /* 0x51957c */) = cpu.eax;
    // 004719ee  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 004719f5  e836a8feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 004719fa  a324965100             -mov dword ptr [0x519624], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346852) /* 0x519624 */) = cpu.eax;
    // 004719ff  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a06  e825a8feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a0b  a330965100             -mov dword ptr [0x519630], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346864) /* 0x519630 */) = cpu.eax;
    // 00471a10  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a17  e814a8feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a1c  a384955100             -mov dword ptr [0x519584], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346692) /* 0x519584 */) = cpu.eax;
    // 00471a21  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a28  e803a8feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a2d  a328965100             -mov dword ptr [0x519628], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346856) /* 0x519628 */) = cpu.eax;
    // 00471a32  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a39  e8f2a7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a3e  a320965100             -mov dword ptr [0x519620], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346848) /* 0x519620 */) = cpu.eax;
    // 00471a43  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a4a  e8e1a7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a4f  a334965100             -mov dword ptr [0x519634], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346868) /* 0x519634 */) = cpu.eax;
    // 00471a54  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a5b  e8d0a7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a60  a31c965100             -mov dword ptr [0x51961c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346844) /* 0x51961c */) = cpu.eax;
    // 00471a65  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a6c  e8bfa7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a71  a282955100             -mov byte ptr [0x519582], al
    *app->getMemory<x86::reg8>(x86::reg32(5346690) /* 0x519582 */) = cpu.al;
    // 00471a76  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a7d  e8aea7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a82  a281955100             -mov byte ptr [0x519581], al
    *app->getMemory<x86::reg8>(x86::reg32(5346689) /* 0x519581 */) = cpu.al;
    // 00471a87  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a8e  e89da7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471a93  a280955100             -mov byte ptr [0x519580], al
    *app->getMemory<x86::reg8>(x86::reg32(5346688) /* 0x519580 */) = cpu.al;
    // 00471a98  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471a9f  e88ca7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471aa4  a21a965100             -mov byte ptr [0x51961a], al
    *app->getMemory<x86::reg8>(x86::reg32(5346842) /* 0x51961a */) = cpu.al;
    // 00471aa9  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471ab0  e87ba7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471ab5  a219965100             -mov byte ptr [0x519619], al
    *app->getMemory<x86::reg8>(x86::reg32(5346841) /* 0x519619 */) = cpu.al;
    // 00471aba  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471ac1  e86aa7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471ac6  a218965100             -mov byte ptr [0x519618], al
    *app->getMemory<x86::reg8>(x86::reg32(5346840) /* 0x519618 */) = cpu.al;
    // 00471acb  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471ad2  e859a7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471ad7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471ad9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471adb  e890f3ffff             -call 0x470e70
    cpu.esp -= 4;
    sub_470e70(app, cpu);
    if (cpu.terminate) return;
    // 00471ae0  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471ae7  e844a7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471aec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471aee  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471af3  e878f3ffff             -call 0x470e70
    cpu.esp -= 4;
    sub_470e70(app, cpu);
    if (cpu.terminate) return;
    // 00471af8  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471aff  e82ca7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471b04  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471b06  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00471b0b  e860f3ffff             -call 0x470e70
    cpu.esp -= 4;
    sub_470e70(app, cpu);
    if (cpu.terminate) return;
    // 00471b10  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471b17  e814a7feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471b1c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471b1e  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00471b23  e848f3ffff             -call 0x470e70
    cpu.esp -= 4;
    sub_470e70(app, cpu);
    if (cpu.terminate) return;
    // 00471b28  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471b2f  e8fca6feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471b34  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471b36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471b38  e823f3ffff             -call 0x470e60
    cpu.esp -= 4;
    sub_470e60(app, cpu);
    if (cpu.terminate) return;
    // 00471b3d  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471b44  e8e7a6feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471b49  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471b4b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471b50  e80bf3ffff             -call 0x470e60
    cpu.esp -= 4;
    sub_470e60(app, cpu);
    if (cpu.terminate) return;
    // 00471b55  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471b5c  e8cfa6feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471b61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471b63  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00471b68  e8f3f2ffff             -call 0x470e60
    cpu.esp -= 4;
    sub_470e60(app, cpu);
    if (cpu.terminate) return;
    // 00471b6d  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471b74  e8b7a6feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471b79  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471b7b  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00471b80  e8dbf2ffff             -call 0x470e60
    cpu.esp -= 4;
    sub_470e60(app, cpu);
    if (cpu.terminate) return;
    // 00471b85  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471b8c  e89fa6feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471b91  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00471b93  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471b9a  e891a6feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471b9f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471ba1  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471ba8  e883a6feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471bad  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00471baf  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471bb6  e875a6feff             -call 0x45c230
    cpu.esp -= 4;
    sub_45c230(app, cpu);
    if (cpu.terminate) return;
    // 00471bbb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00471bbd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00471bbf  e8cc78ffff             -call 0x469490
    cpu.esp -= 4;
    sub_469490(app, cpu);
    if (cpu.terminate) return;
    // 00471bc4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00471bc6  e8016f0000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 00471bcb  e840f1ffff             -call 0x470d10
    cpu.esp -= 4;
    sub_470d10(app, cpu);
    if (cpu.terminate) return;
    // 00471bd0  8b151c965100           -mov edx, dword ptr [0x51961c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346844) /* 0x51961c */);
    // 00471bd6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00471bd9  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 00471bde  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00471be0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00471be3  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471be5  8b1584955100           -mov edx, dword ptr [0x519584]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5346692) /* 0x519584 */);
    // 00471beb  bb68010000             -mov ebx, 0x168
    cpu.ebx = 360 /*0x168*/;
    // 00471bf0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00471bf3  a31c965100             -mov dword ptr [0x51961c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346844) /* 0x51961c */) = cpu.eax;
    // 00471bf8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00471bfa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00471bfd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471bff  a384955100             -mov dword ptr [0x519584], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346692) /* 0x519584 */) = cpu.eax;
    // 00471c04  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00471c0a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c0b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c0c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c0d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c0e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
/* data blob: ccc64b00ecc64b001cc74b0044c74b0074c74b009cc74b00c0c74b0038c84b00acc84b0048c94b00c8c94b005cca4b00dcca4b0070cb4b0040cc4b0004cd4b00bccd4b0050ce4b00f8ce4b0000cf4b0008cf4b0018cf4b0024cf4b0030cf4b0038cf4b00a4cf4b0038d04b00dcd04b0078d14b00f4d14b00f8ce4b0000cf4b0008cf4b0018cf4b0024cf4b0030cf4b00494e5354414c4c2e57494e00655860626758433a4e46533253454e2e45584500 */
void Application::sub_471cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471cc0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471cc1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471cc2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471cc3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471cc4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471cc5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471cc6  81ec24010000           -sub esp, 0x124
    (cpu.esp) -= x86::reg32(x86::sreg32(292 /*0x124*/));
    // 00471ccc  8dbc2410010000         -lea edi, [esp + 0x110]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00471cd3  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00471cd8  bea01c4700             -mov esi, 0x471ca0
    cpu.esi = 4660384 /*0x471ca0*/;
    // 00471cdd  8d942410010000         -lea edx, [esp + 0x110]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00471ce4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00471ce6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471ce7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471ce8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471ce9  e812f50100             -call 0x491200
    cpu.esp -= 4;
    sub_491200(app, cpu);
    if (cpu.terminate) return;
    // 00471cee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00471cf0  e86bf50100             -call 0x491260
    cpu.esp -= 4;
    sub_491260(app, cpu);
    if (cpu.terminate) return;
    // 00471cf5  e88ef50100             -call 0x491288
    cpu.esp -= 4;
    sub_491288(app, cpu);
    if (cpu.terminate) return;
    // 00471cfa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471cfc  0f8585000000           -jne 0x471d87
    if (!cpu.flags.zf)
    {
        goto L_0x00471d87;
    }
L_0x00471d02:
    // 00471d02  8dbc241c010000         -lea edi, [esp + 0x11c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00471d09  beac1c4700             -mov esi, 0x471cac
    cpu.esi = 4660396 /*0x471cac*/;
    // 00471d0e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471d10  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471d11  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
L_0x00471d13:
    // 00471d13  8aa4141c010000         -mov ah, byte ptr [esp + edx + 0x11c]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(284) /* 0x11c */ + cpu.edx * 1);
    // 00471d1a  42                     -inc edx
    (cpu.edx)++;
    // 00471d1b  80c40d                 -add ah, 0xd
    (cpu.ah) += x86::reg8(x86::sreg8(13 /*0xd*/));
    // 00471d1e  88a4141b010000         -mov byte ptr [esp + edx + 0x11b], ah
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(283) /* 0x11b */ + cpu.edx * 1) = cpu.ah;
    // 00471d25  83fa06                 +cmp edx, 6
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d28  7ce9                   -jl 0x471d13
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471d13;
    }
    // 00471d2a  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 00471d2f  8d94241c010000         -lea edx, [esp + 0x11c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00471d36  a148e54d00             -mov eax, dword ptr [0x4de548]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */);
    // 00471d3b  e863890100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 00471d40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471d42  7436                   -je 0x471d7a
    if (cpu.flags.zf)
    {
        goto L_0x00471d7a;
    }
    // 00471d44  8dbc2400010000         -lea edi, [esp + 0x100]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471d4b  beb21c4700             -mov esi, 0x471cb2
    cpu.esi = 4660402 /*0x471cb2*/;
    // 00471d50  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00471d52  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471d54  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471d55  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471d56  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471d57  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
L_0x00471d59:
    // 00471d59  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00471d5b  e828f50100             -call 0x491288
    cpu.esp -= 4;
    sub_491288(app, cpu);
    if (cpu.terminate) return;
    // 00471d60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471d62  0f8571010000           -jne 0x471ed9
    if (!cpu.flags.zf)
    {
        goto L_0x00471ed9;
    }
L_0x00471d68:
    // 00471d68  42                     -inc edx
    (cpu.edx)++;
    // 00471d69  83fa19                 +cmp edx, 0x19
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(25 /*0x19*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d6c  7d04                   -jge 0x471d72
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471d72;
    }
    // 00471d6e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00471d70  74e7                   -je 0x471d59
    if (cpu.flags.zf)
    {
        goto L_0x00471d59;
    }
L_0x00471d72:
    // 00471d72  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00471d74  0f8488010000           -je 0x471f02
    if (cpu.flags.zf)
    {
        goto L_0x00471f02;
    }
L_0x00471d7a:
    // 00471d7a  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 00471d80  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d81  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d82  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d83  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d84  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d85  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471d87:
    // 00471d87  b8ccd24b00             -mov eax, 0x4bd2cc
    cpu.eax = 4969164 /*0x4bd2cc*/;
    // 00471d8c  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471d92  e8595b0000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471d97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471d99  7523                   -jne 0x471dbe
    if (!cpu.flags.zf)
    {
        goto L_0x00471dbe;
    }
    // 00471d9b  ba80d24b00             -mov edx, 0x4bd280
    cpu.edx = 4969088 /*0x4bd280*/;
    // 00471da0  b94b010000             -mov ecx, 0x14b
    cpu.ecx = 331 /*0x14b*/;
    // 00471da5  6868d34b00             -push 0x4bd368
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969320 /*0x4bd368*/;
    cpu.esp -= 4;
    // 00471daa  89158c844c00           -mov dword ptr [0x4c848c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 00471db0  890d90844c00           -mov dword ptr [0x4c8490], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 00471db6  e805650000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471dbb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471dbe:
    // 00471dbe  b8d4d24b00             -mov eax, 0x4bd2d4
    cpu.eax = 4969172 /*0x4bd2d4*/;
    // 00471dc3  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471dc9  e8225b0000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471dce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471dd0  7523                   -jne 0x471df5
    if (!cpu.flags.zf)
    {
        goto L_0x00471df5;
    }
    // 00471dd2  bb80d24b00             -mov ebx, 0x4bd280
    cpu.ebx = 4969088 /*0x4bd280*/;
    // 00471dd7  be4d010000             -mov esi, 0x14d
    cpu.esi = 333 /*0x14d*/;
    // 00471ddc  68c4d34b00             -push 0x4bd3c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969412 /*0x4bd3c4*/;
    cpu.esp -= 4;
    // 00471de1  891d8c844c00           -mov dword ptr [0x4c848c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebx;
    // 00471de7  893590844c00           -mov dword ptr [0x4c8490], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.esi;
    // 00471ded  e8ce640000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471df2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471df5:
    // 00471df5  b8dcd24b00             -mov eax, 0x4bd2dc
    cpu.eax = 4969180 /*0x4bd2dc*/;
    // 00471dfa  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471e00  e8eb5a0000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471e05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e07  7523                   -jne 0x471e2c
    if (!cpu.flags.zf)
    {
        goto L_0x00471e2c;
    }
    // 00471e09  bf80d24b00             -mov edi, 0x4bd280
    cpu.edi = 4969088 /*0x4bd280*/;
    // 00471e0e  bd4f010000             -mov ebp, 0x14f
    cpu.ebp = 335 /*0x14f*/;
    // 00471e13  682cd44b00             -push 0x4bd42c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969516 /*0x4bd42c*/;
    cpu.esp -= 4;
    // 00471e18  893d8c844c00           -mov dword ptr [0x4c848c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edi;
    // 00471e1e  892d90844c00           -mov dword ptr [0x4c8490], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebp;
    // 00471e24  e897640000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471e29  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471e2c:
    // 00471e2c  b8e4d24b00             -mov eax, 0x4bd2e4
    cpu.eax = 4969188 /*0x4bd2e4*/;
    // 00471e31  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471e37  e8b45a0000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471e3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e3e  7522                   -jne 0x471e62
    if (!cpu.flags.zf)
    {
        goto L_0x00471e62;
    }
    // 00471e40  b880d24b00             -mov eax, 0x4bd280
    cpu.eax = 4969088 /*0x4bd280*/;
    // 00471e45  ba51010000             -mov edx, 0x151
    cpu.edx = 337 /*0x151*/;
    // 00471e4a  6894d44b00             -push 0x4bd494
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969620 /*0x4bd494*/;
    cpu.esp -= 4;
    // 00471e4f  a38c844c00             -mov dword ptr [0x4c848c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.eax;
    // 00471e54  891590844c00           -mov dword ptr [0x4c8490], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.edx;
    // 00471e5a  e861640000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471e5f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471e62:
    // 00471e62  b8ecd24b00             -mov eax, 0x4bd2ec
    cpu.eax = 4969196 /*0x4bd2ec*/;
    // 00471e67  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471e6d  e87e5a0000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471e72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471e74  7523                   -jne 0x471e99
    if (!cpu.flags.zf)
    {
        goto L_0x00471e99;
    }
    // 00471e76  b980d24b00             -mov ecx, 0x4bd280
    cpu.ecx = 4969088 /*0x4bd280*/;
    // 00471e7b  bb53010000             -mov ebx, 0x153
    cpu.ebx = 339 /*0x153*/;
    // 00471e80  68f4d44b00             -push 0x4bd4f4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969716 /*0x4bd4f4*/;
    cpu.esp -= 4;
    // 00471e85  890d8c844c00           -mov dword ptr [0x4c848c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ecx;
    // 00471e8b  891d90844c00           -mov dword ptr [0x4c8490], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebx;
    // 00471e91  e82a640000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471e96  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471e99:
    // 00471e99  b8f4d24b00             -mov eax, 0x4bd2f4
    cpu.eax = 4969204 /*0x4bd2f4*/;
    // 00471e9e  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471ea4  e8475a0000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471ea9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471eab  0f8551feffff           -jne 0x471d02
    if (!cpu.flags.zf)
    {
        goto L_0x00471d02;
    }
    // 00471eb1  be80d24b00             -mov esi, 0x4bd280
    cpu.esi = 4969088 /*0x4bd280*/;
    // 00471eb6  bf55010000             -mov edi, 0x155
    cpu.edi = 341 /*0x155*/;
    // 00471ebb  6850d54b00             -push 0x4bd550
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969808 /*0x4bd550*/;
    cpu.esp -= 4;
    // 00471ec0  89358c844c00           -mov dword ptr [0x4c848c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.esi;
    // 00471ec6  893d90844c00           -mov dword ptr [0x4c8490], edi
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.edi;
    // 00471ecc  e8ef630000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471ed1  83c404                 +add esp, 4
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
    // 00471ed4  e929feffff             -jmp 0x471d02
    goto L_0x00471d02;
L_0x00471ed9:
    // 00471ed9  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00471edb  0441                   -add al, 0x41
    (cpu.al) += x86::reg8(x86::sreg8(65 /*0x41*/));
    // 00471edd  88842400010000         -mov byte ptr [esp + 0x100], al
    *app->getMemory<x86::reg8>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.al;
    // 00471ee4  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00471eeb  e87cb10000             -call 0x47d06c
    cpu.esp -= 4;
    sub_47d06c(app, cpu);
    if (cpu.terminate) return;
    // 00471ef0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471ef2  0f8470feffff           -je 0x471d68
    if (cpu.flags.zf)
    {
        goto L_0x00471d68;
    }
    // 00471ef8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00471efd  e966feffff             -jmp 0x471d68
    goto L_0x00471d68;
L_0x00471f02:
    // 00471f02  b8ccd24b00             -mov eax, 0x4bd2cc
    cpu.eax = 4969164 /*0x4bd2cc*/;
    // 00471f07  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471f0d  e8de590000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471f12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471f14  7522                   -jne 0x471f38
    if (!cpu.flags.zf)
    {
        goto L_0x00471f38;
    }
    // 00471f16  bd80d24b00             -mov ebp, 0x4bd280
    cpu.ebp = 4969088 /*0x4bd280*/;
    // 00471f1b  b879010000             -mov eax, 0x179
    cpu.eax = 377 /*0x179*/;
    // 00471f20  68acd54b00             -push 0x4bd5ac
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969900 /*0x4bd5ac*/;
    cpu.esp -= 4;
    // 00471f25  892d8c844c00           -mov dword ptr [0x4c848c], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebp;
    // 00471f2b  a390844c00             -mov dword ptr [0x4c8490], eax
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.eax;
    // 00471f30  e88b630000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471f35  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471f38:
    // 00471f38  b8d4d24b00             -mov eax, 0x4bd2d4
    cpu.eax = 4969172 /*0x4bd2d4*/;
    // 00471f3d  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471f43  e8a8590000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471f48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471f4a  7523                   -jne 0x471f6f
    if (!cpu.flags.zf)
    {
        goto L_0x00471f6f;
    }
    // 00471f4c  ba80d24b00             -mov edx, 0x4bd280
    cpu.edx = 4969088 /*0x4bd280*/;
    // 00471f51  b97b010000             -mov ecx, 0x17b
    cpu.ecx = 379 /*0x17b*/;
    // 00471f56  68f8d54b00             -push 0x4bd5f8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969976 /*0x4bd5f8*/;
    cpu.esp -= 4;
    // 00471f5b  89158c844c00           -mov dword ptr [0x4c848c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 00471f61  890d90844c00           -mov dword ptr [0x4c8490], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 00471f67  e854630000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471f6c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471f6f:
    // 00471f6f  b8dcd24b00             -mov eax, 0x4bd2dc
    cpu.eax = 4969180 /*0x4bd2dc*/;
    // 00471f74  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471f7a  e871590000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471f7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471f81  7523                   -jne 0x471fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00471fa6;
    }
    // 00471f83  bb80d24b00             -mov ebx, 0x4bd280
    cpu.ebx = 4969088 /*0x4bd280*/;
    // 00471f88  be7d010000             -mov esi, 0x17d
    cpu.esi = 381 /*0x17d*/;
    // 00471f8d  6854d64b00             -push 0x4bd654
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970068 /*0x4bd654*/;
    cpu.esp -= 4;
    // 00471f92  891d8c844c00           -mov dword ptr [0x4c848c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ebx;
    // 00471f98  893590844c00           -mov dword ptr [0x4c8490], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.esi;
    // 00471f9e  e81d630000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471fa3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471fa6:
    // 00471fa6  b8e4d24b00             -mov eax, 0x4bd2e4
    cpu.eax = 4969188 /*0x4bd2e4*/;
    // 00471fab  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471fb1  e83a590000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471fb6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471fb8  7523                   -jne 0x471fdd
    if (!cpu.flags.zf)
    {
        goto L_0x00471fdd;
    }
    // 00471fba  bf80d24b00             -mov edi, 0x4bd280
    cpu.edi = 4969088 /*0x4bd280*/;
    // 00471fbf  bd7f010000             -mov ebp, 0x17f
    cpu.ebp = 383 /*0x17f*/;
    // 00471fc4  68b4d64b00             -push 0x4bd6b4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970164 /*0x4bd6b4*/;
    cpu.esp -= 4;
    // 00471fc9  893d8c844c00           -mov dword ptr [0x4c848c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edi;
    // 00471fcf  892d90844c00           -mov dword ptr [0x4c8490], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebp;
    // 00471fd5  e8e6620000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00471fda  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00471fdd:
    // 00471fdd  b8ecd24b00             -mov eax, 0x4bd2ec
    cpu.eax = 4969196 /*0x4bd2ec*/;
    // 00471fe2  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 00471fe8  e803590000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00471fed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471fef  7522                   -jne 0x472013
    if (!cpu.flags.zf)
    {
        goto L_0x00472013;
    }
    // 00471ff1  b880d24b00             -mov eax, 0x4bd280
    cpu.eax = 4969088 /*0x4bd280*/;
    // 00471ff6  ba81010000             -mov edx, 0x181
    cpu.edx = 385 /*0x181*/;
    // 00471ffb  680cd74b00             -push 0x4bd70c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970252 /*0x4bd70c*/;
    cpu.esp -= 4;
    // 00472000  a38c844c00             -mov dword ptr [0x4c848c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.eax;
    // 00472005  891590844c00           -mov dword ptr [0x4c8490], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.edx;
    // 0047200b  e8b0620000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 00472010  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x00472013:
    // 00472013  b8f4d24b00             -mov eax, 0x4bd2f4
    cpu.eax = 4969204 /*0x4bd2f4*/;
    // 00472018  8b1544e54d00           -mov edx, dword ptr [0x4de544]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */);
    // 0047201e  e8cd580000             -call 0x4778f0
    cpu.esp -= 4;
    sub_4778f0(app, cpu);
    if (cpu.terminate) return;
    // 00472023  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472025  0f854ffdffff           -jne 0x471d7a
    if (!cpu.flags.zf)
    {
        goto L_0x00471d7a;
    }
    // 0047202b  b980d24b00             -mov ecx, 0x4bd280
    cpu.ecx = 4969088 /*0x4bd280*/;
    // 00472030  bb83010000             -mov ebx, 0x183
    cpu.ebx = 387 /*0x183*/;
    // 00472035  6864d74b00             -push 0x4bd764
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970340 /*0x4bd764*/;
    cpu.esp -= 4;
    // 0047203a  890d8c844c00           -mov dword ptr [0x4c848c], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.ecx;
    // 00472040  891d90844c00           -mov dword ptr [0x4c8490], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ebx;
    // 00472046  e875620000             -call 0x4782c0
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0047204b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047204e  81c424010000           -add esp, 0x124
    (cpu.esp) += x86::reg32(x86::sreg32(292 /*0x124*/));
    // 00472054  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472055  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472056  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472057  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472058  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472059  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047205a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472060  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472070  e82b2affff             -call 0x464aa0
    cpu.esp -= 4;
    sub_464aa0(app, cpu);
    if (cpu.terminate) return;
    // 00472075  e8f6effeff             -call 0x461070
    cpu.esp -= 4;
    sub_461070(app, cpu);
    if (cpu.terminate) return;
    // 0047207a  e841fafeff             -call 0x461ac0
    cpu.esp -= 4;
    sub_461ac0(app, cpu);
    if (cpu.terminate) return;
    // 0047207f  e88cdefdff             -call 0x44ff10
    cpu.esp -= 4;
    sub_44ff10(app, cpu);
    if (cpu.terminate) return;
    // 00472084  b844965100             -mov eax, 0x519644
    cpu.eax = 5346884 /*0x519644*/;
    // 00472089  e8a2cb0000             -call 0x47ec30
    cpu.esp -= 4;
    sub_47ec30(app, cpu);
    if (cpu.terminate) return;
    // 0047208e  e8cd280000             -call 0x474960
    cpu.esp -= 4;
    sub_474960(app, cpu);
    if (cpu.terminate) return;
    // 00472093  e8282dffff             -call 0x464dc0
    cpu.esp -= 4;
    sub_464dc0(app, cpu);
    if (cpu.terminate) return;
    // 00472098  e853e2faff             -call 0x4202f0
    cpu.esp -= 4;
    sub_4202f0(app, cpu);
    if (cpu.terminate) return;
    // 0047209d  e97f950100             -jmp 0x48b621
    return sub_48b621(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4720b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004720b0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004720b1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004720b2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004720b3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004720b4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004720b5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004720b6  b850d34b00             -mov eax, 0x4bd350
    cpu.eax = 4969296 /*0x4bd350*/;
    // 004720bb  e864610000             -call 0x478224
    cpu.esp -= 4;
    sub_478224(app, cpu);
    if (cpu.terminate) return;
    // 004720c0  e8cb020000             -call 0x472390
    cpu.esp -= 4;
    sub_472390(app, cpu);
    if (cpu.terminate) return;
    // 004720c5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004720c7  e8f4010000             -call 0x4722c0
    cpu.esp -= 4;
    sub_4722c0(app, cpu);
    if (cpu.terminate) return;
    // 004720cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004720ce  e80d010000             -call 0x4721e0
    cpu.esp -= 4;
    sub_4721e0(app, cpu);
    if (cpu.terminate) return;
    // 004720d3  ba0000a000             -mov edx, 0xa00000
    cpu.edx = 10485760 /*0xa00000*/;
    // 004720d8  b8e8030000             -mov eax, 0x3e8
    cpu.eax = 1000 /*0x3e8*/;
    // 004720dd  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004720e2  e885ef0100             -call 0x49106c
    cpu.esp -= 4;
    sub_49106c(app, cpu);
    if (cpu.terminate) return;
    // 004720e7  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 004720ec  a32ce14d00             -mov dword ptr [0x4de12c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5103916) /* 0x4de12c */) = cpu.eax;
    // 004720f1  890dec814c00           -mov dword ptr [0x4c81ec], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5013996) /* 0x4c81ec */) = cpu.ecx;
    // 004720f7  8915f0814c00           -mov dword ptr [0x4c81f0], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014000) /* 0x4c81f0 */) = cpu.edx;
    // 004720fd  e8feef0100             -call 0x491100
    cpu.esp -= 4;
    sub_491100(app, cpu);
    if (cpu.terminate) return;
    // 00472102  833dc4814c0000         +cmp dword ptr [0x4c81c4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5013956) /* 0x4c81c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472109  0f849d000000           -je 0x4721ac
    if (cpu.flags.zf)
    {
        goto L_0x004721ac;
    }
L_0x0047210f:
    // 0047210f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 00472114  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00472116  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 0047211b  89357c854c00           -mov dword ptr [0x4c857c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014908) /* 0x4c857c */) = cpu.esi;
    // 00472121  893dbc844c00           -mov dword ptr [0x4c84bc], edi
    *app->getMemory<x86::reg32>(x86::reg32(5014716) /* 0x4c84bc */) = cpu.edi;
    // 00472127  e89491ffff             -call 0x46b2c0
    cpu.esp -= 4;
    sub_46b2c0(app, cpu);
    if (cpu.terminate) return;
    // 0047212c  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 00472131  ba40254700             -mov edx, 0x472540
    cpu.edx = 4662592 /*0x472540*/;
    // 00472136  e8ad5c0000             -call 0x477de8
    cpu.esp -= 4;
    sub_477de8(app, cpu);
    if (cpu.terminate) return;
    // 0047213b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047213d  892d34824c00           -mov dword ptr [0x4c8234], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */) = cpu.ebp;
    // 00472143  e8d8270000             -call 0x474920
    cpu.esp -= 4;
    sub_474920(app, cpu);
    if (cpu.terminate) return;
    // 00472148  68c0214700             -push 0x4721c0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4661696 /*0x4721c0*/;
    cpu.esp -= 4;
    // 0047214d  6818020000             -push 0x218
    *app->getMemory<x86::reg32>(cpu.esp-4) = 536 /*0x218*/;
    cpu.esp -= 4;
    // 00472152  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472154  e807400000             -call 0x476160
    cpu.esp -= 4;
    sub_476160(app, cpu);
    if (cpu.terminate) return;
    // 00472159  e8d2ddfdff             -call 0x44ff30
    cpu.esp -= 4;
    sub_44ff30(app, cpu);
    if (cpu.terminate) return;
    // 0047215e  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00472163  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00472168  e8bf720000             -call 0x47942c
    cpu.esp -= 4;
    sub_47942c(app, cpu);
    if (cpu.terminate) return;
    // 0047216d  e83eeefaff             -call 0x420fb0
    cpu.esp -= 4;
    sub_420fb0(app, cpu);
    if (cpu.terminate) return;
    // 00472172  e8d968f9ff             -call 0x408a50
    cpu.esp -= 4;
    sub_408a50(app, cpu);
    if (cpu.terminate) return;
    // 00472177  e864fafeff             -call 0x461be0
    cpu.esp -= 4;
    sub_461be0(app, cpu);
    if (cpu.terminate) return;
    // 0047217c  e86ff6feff             -call 0x4617f0
    cpu.esp -= 4;
    sub_4617f0(app, cpu);
    if (cpu.terminate) return;
    // 00472181  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00472183  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00472188  e8e3dafdff             -call 0x44fc70
    cpu.esp -= 4;
    sub_44fc70(app, cpu);
    if (cpu.terminate) return;
    // 0047218d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047218f  6844965100             -push 0x519644
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5346884 /*0x519644*/;
    cpu.esp -= 4;
    // 00472194  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472196  b890034400             -mov eax, 0x440390
    cpu.eax = 4457360 /*0x440390*/;
    // 0047219b  e800ca0000             -call 0x47eba0
    cpu.esp -= 4;
    sub_47eba0(app, cpu);
    if (cpu.terminate) return;
    // 004721a0  e81b29ffff             -call 0x464ac0
    cpu.esp -= 4;
    sub_464ac0(app, cpu);
    if (cpu.terminate) return;
    // 004721a5  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721a6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721a7  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721a8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721a9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721aa  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004721ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004721ac:
    // 004721ac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004721ae  e832920100             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 004721b3  e957ffffff             -jmp 0x47210f
    goto L_0x0047210f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4721c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004721c0  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004721c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004721c6  7405                   -je 0x4721cd
    if (cpu.flags.zf)
    {
        goto L_0x004721cd;
    }
    // 004721c8  83f801                 +cmp eax, 1
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
    // 004721cb  7508                   -jne 0x4721d5
    if (!cpu.flags.zf)
    {
        goto L_0x004721d5;
    }
L_0x004721cd:
    // 004721cd  b844514d42             -mov eax, 0x424d5144
    cpu.eax = 1112363332 /*0x424d5144*/;
    // 004721d2  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004721d5:
    // 004721d5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004721da  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4721e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004721e0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004721e1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004721e2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004721e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004721e4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004721e5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004721e6  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004721e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004721eb  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004721f0  6858965100             -push 0x519658
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5346904 /*0x519658*/;
    cpu.esp -= 4;
    // 004721f5  891558965100           -mov dword ptr [0x519658], edx
    *app->getMemory<x86::reg32>(x86::reg32(5346904) /* 0x519658 */) = cpu.edx;
    // 004721fb  2eff1508554b00         -call dword ptr cs:[0x4b5508]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936968) /* 0x4b5508 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472202  a164965100             -mov eax, dword ptr [0x519664]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5346916) /* 0x519664 */);
    // 00472207  03056c965100           -add eax, dword ptr [0x51966c]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5346924) /* 0x51966c */)));
    // 0047220d  3d00000001             +cmp eax, 0x1000000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16777216 /*0x1000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472212  7341                   -jae 0x472255
    if (!cpu.flags.cf)
    {
        goto L_0x00472255;
    }
    // 00472214  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00472219  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047221d  be401c4700             -mov esi, 0x471c40
    cpu.esi = 4660288 /*0x471c40*/;
    // 00472222  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472224  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00472229  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047222d  be581c4700             -mov esi, 0x471c58
    cpu.esi = 4660312 /*0x471c58*/;
    // 00472232  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472234  6a31                   -push 0x31
    *app->getMemory<x86::reg32>(cpu.esp-4) = 49 /*0x31*/;
    cpu.esp -= 4;
    // 00472236  8b749c34               -mov esi, dword ptr [esp + ebx*4 + 0x34]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */ + cpu.ebx * 4);
    // 0047223a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047223b  8b7c9c20               -mov edi, dword ptr [esp + ebx*4 + 0x20]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */ + cpu.ebx * 4);
    // 0047223f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472240  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472242  2eff15d4534b00         -call dword ptr cs:[0x4b53d4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936660) /* 0x4b53d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472249  83f802                 +cmp eax, 2
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
    // 0047224c  7507                   -jne 0x472255
    if (!cpu.flags.zf)
    {
        goto L_0x00472255;
    }
    // 0047224e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472250  e890910100             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
L_0x00472255:
    // 00472255  b800001000             -mov eax, 0x100000
    cpu.eax = 1048576 /*0x100000*/;
    // 0047225a  e8b13df9ff             -call 0x406010
    cpu.esp -= 4;
    sub_406010(app, cpu);
    if (cpu.terminate) return;
    // 0047225f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472261  740a                   -je 0x47226d
    if (cpu.flags.zf)
    {
        goto L_0x0047226d;
    }
L_0x00472263:
    // 00472263  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00472266  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472267  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472268  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472269  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047226a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047226b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047226c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047226d:
    // 0047226d  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00472272  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00472274  be701c4700             -mov esi, 0x471c70
    cpu.esi = 4660336 /*0x471c70*/;
    // 00472279  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047227b  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 00472280  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00472284  be881c4700             -mov esi, 0x471c88
    cpu.esi = 4660360 /*0x471c88*/;
    // 00472289  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047228b  6a31                   -push 0x31
    *app->getMemory<x86::reg32>(cpu.esp-4) = 49 /*0x31*/;
    cpu.esp -= 4;
    // 0047228d  8b6c9c4c               -mov ebp, dword ptr [esp + ebx*4 + 0x4c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */ + cpu.ebx * 4);
    // 00472291  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472292  8b449c08               -mov eax, dword ptr [esp + ebx*4 + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.ebx * 4);
    // 00472296  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00472297  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472299  2eff15d4534b00         -call dword ptr cs:[0x4b53d4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936660) /* 0x4b53d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004722a0  83f802                 +cmp eax, 2
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
    // 004722a3  75be                   -jne 0x472263
    if (!cpu.flags.zf)
    {
        goto L_0x00472263;
    }
    // 004722a5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004722a7  e839910100             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 004722ac  83c460                 -add esp, 0x60
    (cpu.esp) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004722af  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4722c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004722c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004722c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004722c2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004722c3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004722c4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004722c5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004722c6  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004722c9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004722cb  68fcd24b00             -push 0x4bd2fc
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969212 /*0x4bd2fc*/;
    cpu.esp -= 4;
    // 004722d0  2eff1514554b00         -call dword ptr cs:[0x4b5514]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936980) /* 0x4b5514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004722d7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004722d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004722db  7545                   -jne 0x472322
    if (!cpu.flags.zf)
    {
        goto L_0x00472322;
    }
    // 004722dd  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 004722e2  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004722e6  be101c4700             -mov esi, 0x471c10
    cpu.esi = 4660240 /*0x471c10*/;
    // 004722eb  6a30                   -push 0x30
    *app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 004722ed  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004722ef  6820d34b00             -push 0x4bd320
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969248 /*0x4bd320*/;
    cpu.esp -= 4;
    // 004722f4  8b549c20               -mov edx, dword ptr [esp + ebx*4 + 0x20]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */ + cpu.ebx * 4);
    // 004722f8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004722f9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004722fa  2eff15d4534b00         -call dword ptr cs:[0x4b53d4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936660) /* 0x4b53d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472301  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472303  e8dd900100             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
L_0x00472308:
    // 00472308  66837c243005           +cmp word ptr [esp + 0x30], 5
    {
        x86::reg16 tmp1 = *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(5 /*0x5*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047230e  7236                   -jb 0x472346
    if (cpu.flags.cf)
    {
        goto L_0x00472346;
    }
    // 00472310  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472311  2eff156c544b00         -call dword ptr cs:[0x4b546c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936812) /* 0x4b546c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472318  83c438                 +add esp, 0x38
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047231b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047231c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047231d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047231e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047231f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472320  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472321  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472322:
    // 00472322  6808d34b00             -push 0x4bd308
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969224 /*0x4bd308*/;
    cpu.esp -= 4;
    // 00472327  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00472328  2eff15e4544b00         -call dword ptr cs:[0x4b54e4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936932) /* 0x4b54e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047232f  a340965100             -mov dword ptr [0x519640], eax
    *app->getMemory<x86::reg32>(x86::reg32(5346880) /* 0x519640 */) = cpu.eax;
    // 00472334  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472338  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00472339  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047233d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047233e  ff1540965100           -call dword ptr [0x519640]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5346880) /* 0x519640 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472344  ebc2                   -jmp 0x472308
    goto L_0x00472308;
L_0x00472346:
    // 00472346  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0047234b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047234d  be281c4700             -mov esi, 0x471c28
    cpu.esi = 4660264 /*0x471c28*/;
    // 00472352  6a30                   -push 0x30
    *app->getMemory<x86::reg32>(cpu.esp-4) = 48 /*0x30*/;
    cpu.esp -= 4;
    // 00472354  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472356  6820d34b00             -push 0x4bd320
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4969248 /*0x4bd320*/;
    cpu.esp -= 4;
    // 0047235b  8b4c9c08               -mov ecx, dword ptr [esp + ebx*4 + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.ebx * 4);
    // 0047235f  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472360  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472362  2eff15d4534b00         -call dword ptr cs:[0x4b53d4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936660) /* 0x4b53d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472369  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047236b  e875900100             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 00472370  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472371  2eff156c544b00         -call dword ptr cs:[0x4b546c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936812) /* 0x4b546c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00472378  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047237b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047237c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047237d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047237e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047237f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472380  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472381  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472390  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472391  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472392  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472393  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472396  babcd24b00             -mov edx, 0x4bd2bc
    cpu.edx = 4969148 /*0x4bd2bc*/;
    // 0047239b  b8c0d24b00             -mov eax, 0x4bd2c0
    cpu.eax = 4969152 /*0x4bd2c0*/;
    // 004723a0  e8b9d20000             -call 0x47f65e
    cpu.esp -= 4;
    sub_47f65e(app, cpu);
    if (cpu.terminate) return;
    // 004723a5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004723a7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004723a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004723ab  0f8479010000           -je 0x47252a
    if (cpu.flags.zf)
    {
        goto L_0x0047252a;
    }
    // 004723b1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004723b2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004723b3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004723b4  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004723b9  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 004723be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004723c0  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004723c4  bfccd24b00             -mov edi, 0x4bd2cc
    cpu.edi = 4969164 /*0x4bd2cc*/;
    // 004723c9  e863e80100             -call 0x490c31
    cpu.esp -= 4;
    sub_490c31(app, cpu);
    if (cpu.terminate) return;
    // 004723ce  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004723d0  49                     -dec ecx
    (cpu.ecx)--;
    // 004723d1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004723d3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004723d5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004723d7  49                     -dec ecx
    (cpu.ecx)--;
    // 004723d8  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 004723dc  b8ccd24b00             -mov eax, 0x4bd2cc
    cpu.eax = 4969164 /*0x4bd2cc*/;
    // 004723e1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004723e3  e8bb820100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 004723e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004723ea  7513                   -jne 0x4723ff
    if (!cpu.flags.zf)
    {
        goto L_0x004723ff;
    }
L_0x004723ec:
    // 004723ec  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004723ee  e884d40000             -call 0x47f877
    cpu.esp -= 4;
    sub_47f877(app, cpu);
    if (cpu.terminate) return;
    // 004723f3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004723f4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004723f5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004723f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004723f8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004723fb  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004723fc  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004723fd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004723fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004723ff:
    // 004723ff  bfd4d24b00             -mov edi, 0x4bd2d4
    cpu.edi = 4969172 /*0x4bd2d4*/;
    // 00472404  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 00472408  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047240a  49                     -dec ecx
    (cpu.ecx)--;
    // 0047240b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047240d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047240f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00472411  49                     -dec ecx
    (cpu.ecx)--;
    // 00472412  b8d4d24b00             -mov eax, 0x4bd2d4
    cpu.eax = 4969172 /*0x4bd2d4*/;
    // 00472417  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00472419  e885820100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 0047241e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472420  7518                   -jne 0x47243a
    if (!cpu.flags.zf)
    {
        goto L_0x0047243a;
    }
    // 00472422  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00472427  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00472429  e849d40000             -call 0x47f877
    cpu.esp -= 4;
    sub_47f877(app, cpu);
    if (cpu.terminate) return;
    // 0047242e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047242f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472430  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472431  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472433  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472436  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472437  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472438  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472439  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047243a:
    // 0047243a  bfdcd24b00             -mov edi, 0x4bd2dc
    cpu.edi = 4969180 /*0x4bd2dc*/;
    // 0047243f  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 00472443  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472445  49                     -dec ecx
    (cpu.ecx)--;
    // 00472446  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00472448  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047244a  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047244c  49                     -dec ecx
    (cpu.ecx)--;
    // 0047244d  b8dcd24b00             -mov eax, 0x4bd2dc
    cpu.eax = 4969180 /*0x4bd2dc*/;
    // 00472452  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00472454  e84a820100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 00472459  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047245b  7518                   -jne 0x472475
    if (!cpu.flags.zf)
    {
        goto L_0x00472475;
    }
    // 0047245d  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
    // 00472462  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00472464  e80ed40000             -call 0x47f877
    cpu.esp -= 4;
    sub_47f877(app, cpu);
    if (cpu.terminate) return;
    // 00472469  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047246a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047246b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047246c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047246e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472471  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472472  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472473  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472474  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472475:
    // 00472475  bfe4d24b00             -mov edi, 0x4bd2e4
    cpu.edi = 4969188 /*0x4bd2e4*/;
    // 0047247a  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 0047247e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472480  49                     -dec ecx
    (cpu.ecx)--;
    // 00472481  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00472483  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00472485  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00472487  49                     -dec ecx
    (cpu.ecx)--;
    // 00472488  b8e4d24b00             -mov eax, 0x4bd2e4
    cpu.eax = 4969188 /*0x4bd2e4*/;
    // 0047248d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047248f  e80f820100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 00472494  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472496  7518                   -jne 0x4724b0
    if (!cpu.flags.zf)
    {
        goto L_0x004724b0;
    }
    // 00472498  be03000000             -mov esi, 3
    cpu.esi = 3 /*0x3*/;
    // 0047249d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047249f  e8d3d30000             -call 0x47f877
    cpu.esp -= 4;
    sub_47f877(app, cpu);
    if (cpu.terminate) return;
    // 004724a4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724a5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724a6  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724a7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004724a9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004724ac  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724ad  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724ae  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004724b0:
    // 004724b0  bfecd24b00             -mov edi, 0x4bd2ec
    cpu.edi = 4969196 /*0x4bd2ec*/;
    // 004724b5  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 004724b9  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004724bb  49                     -dec ecx
    (cpu.ecx)--;
    // 004724bc  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004724be  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004724c0  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004724c2  49                     -dec ecx
    (cpu.ecx)--;
    // 004724c3  b8ecd24b00             -mov eax, 0x4bd2ec
    cpu.eax = 4969196 /*0x4bd2ec*/;
    // 004724c8  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004724ca  e8d4810100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 004724cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004724d1  7518                   -jne 0x4724eb
    if (!cpu.flags.zf)
    {
        goto L_0x004724eb;
    }
    // 004724d3  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
    // 004724d8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004724da  e898d30000             -call 0x47f877
    cpu.esp -= 4;
    sub_47f877(app, cpu);
    if (cpu.terminate) return;
    // 004724df  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724e0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724e1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724e2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004724e4  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004724e7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724e8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724e9  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004724ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004724eb:
    // 004724eb  bff4d24b00             -mov edi, 0x4bd2f4
    cpu.edi = 4969204 /*0x4bd2f4*/;
    // 004724f0  8d54240f               -lea edx, [esp + 0xf]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(15) /* 0xf */);
    // 004724f4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004724f6  49                     -dec ecx
    (cpu.ecx)--;
    // 004724f7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004724f9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004724fb  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004724fd  49                     -dec ecx
    (cpu.ecx)--;
    // 004724fe  b8f4d24b00             -mov eax, 0x4bd2f4
    cpu.eax = 4969204 /*0x4bd2f4*/;
    // 00472503  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00472505  e899810100             -call 0x48a6a3
    cpu.esp -= 4;
    sub_48a6a3(app, cpu);
    if (cpu.terminate) return;
    // 0047250a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047250c  0f85dafeffff           -jne 0x4723ec
    if (!cpu.flags.zf)
    {
        goto L_0x004723ec;
    }
    // 00472512  be05000000             -mov esi, 5
    cpu.esi = 5 /*0x5*/;
    // 00472517  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00472519  e859d30000             -call 0x47f877
    cpu.esp -= 4;
    sub_47f877(app, cpu);
    if (cpu.terminate) return;
    // 0047251e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047251f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472520  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472521  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472523  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472526  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472527  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472528  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472529  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047252a:
    // 0047252a  e8b68e0100             -call 0x48b3e5
    cpu.esp -= 4;
    sub_48b3e5(app, cpu);
    if (cpu.terminate) return;
    // 0047252f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472531  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472534  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472535  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472536  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472537  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472540  83fa2c                 +cmp edx, 0x2c
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
    // 00472543  7406                   -je 0x47254b
    if (cpu.flags.zf)
    {
        goto L_0x0047254b;
    }
    // 00472545  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047254a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047254b:
    // 0047254b  c605bb854c0001         -mov byte ptr [0x4c85bb], 1
    *app->getMemory<x86::reg8>(x86::reg32(5014971) /* 0x4c85bb */) = 1 /*0x1*/;
    // 00472552  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00472557  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472560  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472561  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472562  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00472563  2eff1504554b00         -call dword ptr cs:[0x4b5504]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936964) /* 0x4b5504 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047256a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047256b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_472570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472570  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472580(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472580  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472590  e937650000             -jmp 0x478acc
    return sub_478acc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4725a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004725a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004725a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004725a2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004725a3  ba80d24b00             -mov edx, 0x4bd280
    cpu.edx = 4969088 /*0x4bd280*/;
    // 004725a8  b926000000             -mov ecx, 0x26
    cpu.ecx = 38 /*0x26*/;
    // 004725ad  c70000780500           -mov dword ptr [eax], 0x57800
    *app->getMemory<x86::reg32>(cpu.eax) = 358400 /*0x57800*/;
    // 004725b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004725b5  b8a0d24b00             -mov eax, 0x4bd2a0
    cpu.eax = 4969120 /*0x4bd2a0*/;
    // 004725ba  89158c844c00           -mov dword ptr [0x4c848c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.edx;
    // 004725c0  ba00780500             -mov edx, 0x57800
    cpu.edx = 358400 /*0x57800*/;
    // 004725c5  890d90844c00           -mov dword ptr [0x4c8490], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.ecx;
    // 004725cb  e898600000             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 004725d0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004725d1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004725d2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004725d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472604(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00472604  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472605  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax);
    // 00472607  feca                   -dec dl
    (cpu.dl)--;
    // 00472609  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047260c  7714                   -ja 0x472622
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00472622;
    }
    // 0047260e  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 00472614  ff2495e0254700         -jmp dword ptr [edx*4 + 0x4725e0]
    cpu.ip = *app->getMemory<x86::reg32>(4662752 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047261b:
    // 0047261b  c7400410000000         -mov dword ptr [eax + 4], 0x10
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 16 /*0x10*/;
L_0x00472622:
    // 00472622  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472623  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00472624:
    // 00472624  c7400408000000         -mov dword ptr [eax + 4], 8
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 0047262b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047262c  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047262d:
    // 0047262d  c7400420000000         -mov dword ptr [eax + 4], 0x20
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 32 /*0x20*/;
    // 00472634  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472635  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00472636:
    // 00472636  c7400403000000         -mov dword ptr [eax + 4], 3
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 3 /*0x3*/;
    // 0047263d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047263e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047263f:
    // 0047263f  c7400404000000         -mov dword ptr [eax + 4], 4
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4 /*0x4*/;
    // 00472646  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472647  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472674(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00472674  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472675  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472676  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472677  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472678  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047267b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047267d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047267f  bad4000000             -mov edx, 0xd4
    cpu.edx = 212 /*0xd4*/;
    // 00472684  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00472686  e88587feff             -call 0x45ae10
    cpu.esp -= 4;
    sub_45ae10(app, cpu);
    if (cpu.terminate) return;
    // 0047268b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047268d  7427                   -je 0x4726b6
    if (cpu.flags.zf)
    {
        goto L_0x004726b6;
    }
    // 0047268f  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi);
    // 00472691  80fc04                 +cmp ah, 4
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00472694  7528                   -jne 0x4726be
    if (!cpu.flags.zf)
    {
        goto L_0x004726be;
    }
L_0x00472696:
    // 00472696  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472699  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
L_0x0047269e:
    // 0047269e  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047269f  8d4628                 -lea eax, [esi + 0x28]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004726a2  6800800800             -push 0x88000
    *app->getMemory<x86::reg32>(cpu.esp-4) = 557056 /*0x88000*/;
    cpu.esp -= 4;
    // 004726a7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004726a9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004726ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004726ad  e82e9efeff             -call 0x45c4e0
    cpu.esp -= 4;
    sub_45c4e0(app, cpu);
    if (cpu.terminate) return;
    // 004726b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004726b4  7517                   -jne 0x4726cd
    if (!cpu.flags.zf)
    {
        goto L_0x004726cd;
    }
L_0x004726b6:
    // 004726b6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004726b9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726ba  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726bb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726bc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004726bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004726be:
    // 004726be  80fc05                 +cmp ah, 5
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(5 /*0x5*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004726c1  74d3                   -je 0x472696
    if (cpu.flags.zf)
    {
        goto L_0x00472696;
    }
    // 004726c3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004726c6  05a4000000             +add eax, 0xa4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(164 /*0xa4*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004726cb  ebd1                   -jmp 0x47269e
    goto L_0x0047269e;
L_0x004726cd:
    // 004726cd  bad4000000             -mov edx, 0xd4
    cpu.edx = 212 /*0xd4*/;
    // 004726d2  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004726d4  e86787feff             -call 0x45ae40
    cpu.esp -= 4;
    sub_45ae40(app, cpu);
    if (cpu.terminate) return;
    // 004726d9  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 004726db  fec8                   -dec al
    (cpu.al)--;
    // 004726dd  3c08                   +cmp al, 8
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
    // 004726df  77d5                   -ja 0x4726b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004726b6;
    }
    // 004726e1  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004726e6  ff248550264700         -jmp dword ptr [eax*4 + 0x472650]
    cpu.ip = *app->getMemory<x86::reg32>(4662864 + cpu.eax * 4); goto dynamic_jump;
  case 0x004726ed:
    // 004726ed  8a7601                 -mov dh, byte ptr [esi + 1]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004726f0  f6c603                 +test dh, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 3 /*0x3*/));
    // 004726f3  7562                   -jne 0x472757
    if (!cpu.flags.zf)
    {
        goto L_0x00472757;
    }
    // 004726f5  f6c601                 +test dh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 1 /*0x1*/));
    // 004726f8  0f84af000000           -je 0x4727ad
    if (cpu.flags.zf)
    {
        goto L_0x004727ad;
    }
    // 004726fe  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00472703  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00472706  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472709  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047270b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047270d  83c320                 -add ebx, 0x20
    (cpu.ebx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00472710  e88b070000             -call 0x472ea0
    cpu.esp -= 4;
    sub_472ea0(app, cpu);
    if (cpu.terminate) return;
    // 00472715  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472718  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 00472722  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00472727  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047272a  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047272c  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047272f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00472736  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472738  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0047273f  bb38975100             -mov ebx, 0x519738
    cpu.ebx = 5347128 /*0x519738*/;
    // 00472744  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472747  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472749  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 0047274f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472752  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472753  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472754  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472755  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472756  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472757:
    // 00472757  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0047275c  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047275f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00472762  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00472765  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472768  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047276a  e831070000             -call 0x472ea0
    cpu.esp -= 4;
    sub_472ea0(app, cpu);
    if (cpu.terminate) return;
    // 0047276f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472772  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 0047277c  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00472781  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00472784  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00472786  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00472789  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00472790  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472792  bb38975100             -mov ebx, 0x519738
    cpu.ebx = 5347128 /*0x519738*/;
    // 00472797  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047279a  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047279d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047279f  899acc000000           -mov dword ptr [edx + 0xcc], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 004727a5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004727a8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004727a9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004727aa  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004727ab  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004727ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004727ad:
    // 004727ad  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004727b2  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004727b5  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004727b7  8d5820                 -lea ebx, [eax + 0x20]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004727ba  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004727bd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004727bf  e8dc060000             -call 0x472ea0
    cpu.esp -= 4;
    sub_472ea0(app, cpu);
    if (cpu.terminate) return;
    // 004727c4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004727c7  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 004727d1  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004727d6  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004727d9  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004727db  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004727de  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004727e5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004727e7  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004727ee  bb38975100             -mov ebx, 0x519738
    cpu.ebx = 5347128 /*0x519738*/;
    // 004727f3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004727f6  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004727f8  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 004727fe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472801  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472802  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472803  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472804  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472805  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00472806:
    // 00472806  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472809  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047280b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047280d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047280f  e89c020000             -call 0x472ab0
    cpu.esp -= 4;
    sub_472ab0(app, cpu);
    if (cpu.terminate) return;
    // 00472814  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472817  c7808400000009000000   -mov dword ptr [eax + 0x84], 9
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 9 /*0x9*/;
    // 00472821  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472824  66c780880000000300     -mov word ptr [eax + 0x88], 3
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(136) /* 0x88 */) = 3 /*0x3*/;
    // 0047282d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472830  66c7808a0000000200     -mov word ptr [eax + 0x8a], 2
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(138) /* 0x8a */) = 2 /*0x2*/;
    // 00472839  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0047283e  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00472841  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00472844  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047284b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047284d  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00472854  bbd8965100             -mov ebx, 0x5196d8
    cpu.ebx = 5347032 /*0x5196d8*/;
    // 00472859  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047285c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047285e  89989c000000           -mov dword ptr [eax + 0x9c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */) = cpu.ebx;
    // 00472864  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472867  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472868  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472869  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047286a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047286b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047286c:
    // 0047286c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00472871  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472874  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00472876  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00472878  e833020000             -call 0x472ab0
    cpu.esp -= 4;
    sub_472ab0(app, cpu);
    if (cpu.terminate) return;
    // 0047287d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472880  c7808400000009000000   -mov dword ptr [eax + 0x84], 9
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */) = 9 /*0x9*/;
    // 0047288a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047288d  66c780880000000300     -mov word ptr [eax + 0x88], 3
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(136) /* 0x88 */) = 3 /*0x3*/;
    // 00472896  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472899  66c7808a0000000200     -mov word ptr [eax + 0x8a], 2
    *app->getMemory<x86::reg16>(cpu.eax + x86::reg32(138) /* 0x8a */) = 2 /*0x2*/;
    // 004728a2  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 004728a7  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004728aa  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004728ad  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004728b4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004728b6  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004728bd  bbd8965100             -mov ebx, 0x5196d8
    cpu.ebx = 5347032 /*0x5196d8*/;
    // 004728c2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004728c5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004728c7  89989c000000           -mov dword ptr [eax + 0x9c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */) = cpu.ebx;
    // 004728cd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004728d0  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004728d1  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004728d2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004728d3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004728d4  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004728d5:
    // 004728d5  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004728da  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004728dd  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004728df  8d5820                 -lea ebx, [eax + 0x20]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004728e2  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004728e5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004728e7  e8b4050000             -call 0x472ea0
    cpu.esp -= 4;
    sub_472ea0(app, cpu);
    if (cpu.terminate) return;
    // 004728ec  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004728ef  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 004728f9  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004728fe  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00472901  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00472903  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00472906  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047290d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047290f  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00472916  bb78965100             -mov ebx, 0x519678
    cpu.ebx = 5346936 /*0x519678*/;
    // 0047291b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047291e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472920  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00472926  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472929  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047292a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047292b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047292c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047292d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047292e:
    // 0047292e  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 00472933  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00472936  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472938  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047293b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047293e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472940  e85b050000             -call 0x472ea0
    cpu.esp -= 4;
    sub_472ea0(app, cpu);
    if (cpu.terminate) return;
    // 00472945  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472948  c780a800000005000000   -mov dword ptr [eax + 0xa8], 5
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 5 /*0x5*/;
    // 00472952  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 00472957  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047295a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047295c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047295e  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 00472961  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00472964  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047296b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047296d  bb38975100             -mov ebx, 0x519738
    cpu.ebx = 5347128 /*0x519738*/;
    // 00472972  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00472975  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472978  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047297a  899acc000000           -mov dword ptr [edx + 0xcc], ebx
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00472980  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472983  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472984  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472985  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472986  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472987  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00472988:
    // 00472988  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047298b  c780a800000004000000   -mov dword ptr [eax + 0xa8], 4
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 4 /*0x4*/;
    // 00472995  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0047299a  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047299d  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047299f  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004729a2  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 004729a5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004729a7  e8f4040000             -call 0x472ea0
    cpu.esp -= 4;
    sub_472ea0(app, cpu);
    if (cpu.terminate) return;
    // 004729ac  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004729b1  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004729b4  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004729b6  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004729bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004729bd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004729c0  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004729c2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004729c9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004729cb  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004729d2  bbc4975100             -mov ebx, 0x5197c4
    cpu.ebx = 5347268 /*0x5197c4*/;
    // 004729d7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004729da  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004729dc  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 004729e2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004729e5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004729e6  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004729e7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004729e8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004729e9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004729ea:
    // 004729ea  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004729ed  c780a800000004000000   -mov dword ptr [eax + 0xa8], 4
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 4 /*0x4*/;
    // 004729f7  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004729fc  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004729ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472a01  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472a03  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472a06  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472a09  e892040000             -call 0x472ea0
    cpu.esp -= 4;
    sub_472ea0(app, cpu);
    if (cpu.terminate) return;
    // 00472a0e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00472a13  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00472a16  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00472a18  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00472a1d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472a1f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00472a22  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472a24  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00472a2b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472a2d  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00472a34  bb9c975100             -mov ebx, 0x51979c
    cpu.ebx = 5347228 /*0x51979c*/;
    // 00472a39  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472a3c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472a3e  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00472a44  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472a47  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a48  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a49  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a4a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a4b  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00472a4c:
    // 00472a4c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472a4f  c780a800000004000000   -mov dword ptr [eax + 0xa8], 4
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 4 /*0x4*/;
    // 00472a59  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00472a5e  2b4604                 -sub eax, dword ptr [esi + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00472a61  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472a63  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00472a66  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472a69  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472a6b  e830040000             -call 0x472ea0
    cpu.esp -= 4;
    sub_472ea0(app, cpu);
    if (cpu.terminate) return;
    // 00472a70  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00472a75  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00472a78  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00472a7a  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 00472a7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472a81  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00472a84  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472a86  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00472a8d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472a8f  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00472a96  bbec975100             -mov ebx, 0x5197ec
    cpu.ebx = 5347308 /*0x5197ec*/;
    // 00472a9b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472a9e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472aa0  8998cc000000           -mov dword ptr [eax + 0xcc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00472aa6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00472aa9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472aaa  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472aab  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472aac  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472aad  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_472ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472ab0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472ab1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472ab2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472ab3  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00472ab6  89442430               -mov dword ptr [esp + 0x30], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00472aba  89542434               -mov dword ptr [esp + 0x34], edx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00472abe  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00472ac0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00472ac2  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00472ac6  8d761c                 -lea esi, [esi + 0x1c]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00472ac9  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00472acd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472ace  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472acf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472ad0  e80b7afdff             -call 0x44a4e0
    cpu.esp -= 4;
    sub_44a4e0(app, cpu);
    if (cpu.terminate) return;
    // 00472ad5  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00472ad9  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00472add  83c644                 -add esi, 0x44
    (cpu.esi) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00472ae0  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00472ae3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00472ae5  0f84b4020000           -je 0x472d9f
    if (cpu.flags.zf)
    {
        goto L_0x00472d9f;
    }
    // 00472aeb  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00472aef  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00472af2  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00472af4  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472af6  895c2420               -mov dword ptr [esp + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00472afa  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00472afe  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00472b01  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00472b03  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472b05  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00472b09  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00472b0d  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00472b10  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00472b12  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472b14  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472b16  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00472b18  895c2428               -mov dword ptr [esp + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00472b1c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472b1e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472b1f  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00472b24  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00472b28  e833b3ffff             -call 0x46de60
    cpu.esp -= 4;
    sub_46de60(app, cpu);
    if (cpu.terminate) return;
    // 00472b2d  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472b31  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00472b35  2b412c                 -sub eax, dword ptr [ecx + 0x2c]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */)));
    // 00472b38  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472b3a  0f8e4d020000           -jle 0x472d8d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472d8d;
    }
L_0x00472b40:
    // 00472b40  3d00800000             +cmp eax, 0x8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472b45  7d1d                   -jge 0x472b64
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472b64;
    }
    // 00472b47  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472b4b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00472b4f  8b792c                 -mov edi, dword ptr [ecx + 0x2c]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00472b52  39f8                   +cmp eax, edi
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
    // 00472b54  0f8e3a020000           -jle 0x472d94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472d94;
    }
    // 00472b5a  8d8700800000           -lea eax, [edi + 0x8000]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(32768) /* 0x8000 */);
L_0x00472b60:
    // 00472b60  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00472b64:
    // 00472b64  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472b68  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00472b6b  0500800000             -add eax, 0x8000
    (cpu.eax) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00472b70  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00472b73  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472b77  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00472b7a  894504                 -mov dword ptr [ebp + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472b7d  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472b81  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00472b84  894508                 -mov dword ptr [ebp + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00472b87  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472b8b  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00472b8e  050080ffff             -add eax, 0xffff8000
    (cpu.eax) += x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
    // 00472b93  894560                 -mov dword ptr [ebp + 0x60], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00472b96  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472b9a  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00472b9d  894564                 -mov dword ptr [ebp + 0x64], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00472ba0  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472ba4  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00472ba7  894568                 -mov dword ptr [ebp + 0x68], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00472baa  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472bad  0500800000             -add eax, 0x8000
    (cpu.eax) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00472bb2  894520                 -mov dword ptr [ebp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00472bb5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00472bb9  894524                 -mov dword ptr [ebp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00472bbc  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00472bc0  894528                 -mov dword ptr [ebp + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00472bc3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472bc6  050080ffff             -add eax, 0xffff8000
    (cpu.eax) += x86::reg32(x86::sreg32(4294934528 /*0xffff8000*/));
    // 00472bcb  894540                 -mov dword ptr [ebp + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00472bce  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x00472bd2:
    // 00472bd2  894544                 -mov dword ptr [ebp + 0x44], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 00472bd5  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00472bd9  894548                 -mov dword ptr [ebp + 0x48], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00472bdc  66c7450c0000           -mov word ptr [ebp + 0xc], 0
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 00472be2  66c7452c0000           -mov word ptr [ebp + 0x2c], 0
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 00472be8  66c7454c0000           -mov word ptr [ebp + 0x4c], 0
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 00472bee  8d7d10                 -lea edi, [ebp + 0x10]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00472bf1  66c7456c0000           -mov word ptr [ebp + 0x6c], 0
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(108) /* 0x6c */) = 0 /*0x0*/;
    // 00472bf7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472bf9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472bfb  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 00472bfd  a394824c00             -mov dword ptr [0x4c8294], eax
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.eax;
    // 00472c02  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00472c06  7e2a                   -jle 0x472c32
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472c32;
    }
    // 00472c08  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00472c0a  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 00472c10  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472c13  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 00472c19  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00472c1b  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00472c1e  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 00472c24  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472c27  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472c2d  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472c30  eb14                   -jmp 0x472c46
    goto L_0x00472c46;
L_0x00472c32:
    // 00472c32  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00472c38  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00472c3f  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00472c46:
    // 00472c46  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 00472c4c  8d7d30                 -lea edi, [ebp + 0x30]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(48) /* 0x30 */);
    // 00472c4f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472c51  6689450e               -mov word ptr [ebp + 0xe], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00472c55  8d4520                 -lea eax, [ebp + 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00472c58  891594824c00           -mov dword ptr [0x4c8294], edx
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.edx;
    // 00472c5e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00472c60  8944242c               -mov dword ptr [esp + 0x2c], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00472c64  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00472c68  7e2a                   -jle 0x472c94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472c94;
    }
    // 00472c6a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00472c6c  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 00472c72  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472c75  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 00472c7b  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00472c7d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00472c80  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 00472c86  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472c89  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472c8f  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472c92  eb14                   -jmp 0x472ca8
    goto L_0x00472ca8;
L_0x00472c94:
    // 00472c94  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00472c9a  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00472ca1  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00472ca8:
    // 00472ca8  8d7d50                 -lea edi, [ebp + 0x50]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(80) /* 0x50 */);
    // 00472cab  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 00472cb1  8d5d40                 -lea ebx, [ebp + 0x40]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(64) /* 0x40 */);
    // 00472cb4  890d94824c00           -mov dword ptr [0x4c8294], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.ecx;
    // 00472cba  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00472cbc  6689452e               -mov word ptr [ebp + 0x2e], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(46) /* 0x2e */) = cpu.ax;
    // 00472cc0  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00472cc4  7e2a                   -jle 0x472cf0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472cf0;
    }
    // 00472cc6  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00472cc8  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 00472cce  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472cd1  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 00472cd7  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00472cd9  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00472cdc  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 00472ce2  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472ce5  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472ceb  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472cee  eb14                   -jmp 0x472d04
    goto L_0x00472d04;
L_0x00472cf0:
    // 00472cf0  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00472cf6  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00472cfd  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00472d04:
    // 00472d04  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 00472d0a  8d7d70                 -lea edi, [ebp + 0x70]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(112) /* 0x70 */);
    // 00472d0d  890d94824c00           -mov dword ptr [0x4c8294], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) = cpu.ecx;
    // 00472d13  8d4d60                 -lea ecx, [ebp + 0x60]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(96) /* 0x60 */);
    // 00472d16  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00472d18  6689454e               -mov word ptr [ebp + 0x4e], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(78) /* 0x4e */) = cpu.ax;
    // 00472d1c  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00472d20  7e2a                   -jle 0x472d4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472d4c;
    }
    // 00472d22  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 00472d24  f72d8c824c00           -imul dword ptr [0x4c828c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */))));
    // 00472d2a  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472d2d  030584824c00           -add eax, dword ptr [0x4c8284]
    (cpu.eax) += x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014148) /* 0x4c8284 */)));
    // 00472d33  8907                   -mov dword ptr [edi], eax
    *app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00472d35  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00472d38  f72d90824c00           -imul dword ptr [0x4c8290]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014160) /* 0x4c8290 */))));
    // 00472d3e  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(*app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472d41  030588824c00           +add eax, dword ptr [0x4c8288]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5014152) /* 0x4c8288 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472d47  894704                 -mov dword ptr [edi + 4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472d4a  eb14                   -jmp 0x472d60
    goto L_0x00472d60;
L_0x00472d4c:
    // 00472d4c  c70700000080           -mov dword ptr [edi], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00472d52  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00472d59  830d94824c0001         -or dword ptr [0x4c8294], 1
    *app->getMemory<x86::reg32>(x86::reg32(5014164) /* 0x4c8294 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00472d60:
    // 00472d60  89ad8c000000           -mov dword ptr [ebp + 0x8c], ebp
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(140) /* 0x8c */) = cpu.ebp;
    // 00472d66  899d94000000           -mov dword ptr [ebp + 0x94], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(148) /* 0x94 */) = cpu.ebx;
    // 00472d6c  66a194824c00           -mov ax, word ptr [0x4c8294]
    cpu.ax = *app->getMemory<x86::reg16>(x86::reg32(5014164) /* 0x4c8294 */);
    // 00472d72  898d98000000           -mov dword ptr [ebp + 0x98], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00472d78  6689456e               -mov word ptr [ebp + 0x6e], ax
    *app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(110) /* 0x6e */) = cpu.ax;
    // 00472d7c  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00472d80  898590000000           -mov dword ptr [ebp + 0x90], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00472d86  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00472d89  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d8a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d8b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472d8c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472d8d:
    // 00472d8d  f7d8                   +neg eax
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
    // 00472d8f  e9acfdffff             -jmp 0x472b40
    goto L_0x00472b40;
L_0x00472d94:
    // 00472d94  8d870080ffff           -lea eax, [edi - 0x8000]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(-32768) /* -0x8000 */);
    // 00472d9a  e9c1fdffff             -jmp 0x472b60
    goto L_0x00472b60;
L_0x00472d9f:
    // 00472d9f  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00472da3  8b5a10                 -mov ebx, dword ptr [edx + 0x10]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00472da6  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00472da9  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472dab  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00472daf  895c2420               -mov dword ptr [esp + 0x20], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00472db3  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00472db6  8b5a14                 -mov ebx, dword ptr [edx + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00472db9  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472dbb  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00472dbf  895c2424               -mov dword ptr [esp + 0x24], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 00472dc3  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00472dc6  8b5a18                 -mov ebx, dword ptr [edx + 0x18]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00472dc9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472dcb  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472dcd  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00472dcf  895c2428               -mov dword ptr [esp + 0x28], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 00472dd3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472dd5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472dd6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00472ddb  8d4c2424               -lea ecx, [esp + 0x24]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00472ddf  e87cb0ffff             -call 0x46de60
    cpu.esp -= 4;
    sub_46de60(app, cpu);
    if (cpu.terminate) return;
    // 00472de4  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472de8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472deb  2b4128                 -sub eax, dword ptr [ecx + 0x28]
    (cpu.eax) -= x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */)));
    // 00472dee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472df0  0f8e95000000           -jle 0x472e8b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472e8b;
    }
L_0x00472df6:
    // 00472df6  3d00800000             +cmp eax, 0x8000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472dfb  7d1b                   -jge 0x472e18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00472e18;
    }
    // 00472dfd  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472e01  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472e04  8b5928                 -mov ebx, dword ptr [ecx + 0x28]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00472e07  39d8                   +cmp eax, ebx
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
    // 00472e09  0f8e83000000           -jle 0x472e92
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472e92;
    }
    // 00472e0f  8d8300800000           -lea eax, [ebx + 0x8000]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(32768) /* 0x8000 */);
L_0x00472e15:
    // 00472e15  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00472e18:
    // 00472e18  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472e1c  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00472e1f  894500                 -mov dword ptr [ebp], eax
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 00472e22  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472e26  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00472e29  05cc4c0000             -add eax, 0x4ccc
    (cpu.eax) += x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
    // 00472e2e  894504                 -mov dword ptr [ebp + 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472e31  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472e35  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00472e38  894508                 -mov dword ptr [ebp + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00472e3b  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472e3f  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00472e42  894560                 -mov dword ptr [ebp + 0x60], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(96) /* 0x60 */) = cpu.eax;
    // 00472e45  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472e49  8b402c                 -mov eax, dword ptr [eax + 0x2c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 00472e4c  2dcc4c0000             -sub eax, 0x4ccc
    (cpu.eax) -= x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
    // 00472e51  894564                 -mov dword ptr [ebp + 0x64], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(100) /* 0x64 */) = cpu.eax;
    // 00472e54  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00472e58  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 00472e5b  894568                 -mov dword ptr [ebp + 0x68], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00472e5e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472e61  894520                 -mov dword ptr [ebp + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00472e64  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00472e68  05cc4c0000             -add eax, 0x4ccc
    (cpu.eax) += x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
    // 00472e6d  894524                 -mov dword ptr [ebp + 0x24], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00472e70  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00472e74  894528                 -mov dword ptr [ebp + 0x28], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00472e77  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472e7a  894540                 -mov dword ptr [ebp + 0x40], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 00472e7d  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00472e81  2dcc4c0000             +sub eax, 0x4ccc
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472e86  e947fdffff             -jmp 0x472bd2
    goto L_0x00472bd2;
L_0x00472e8b:
    // 00472e8b  f7d8                   +neg eax
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
    // 00472e8d  e964ffffff             -jmp 0x472df6
    goto L_0x00472df6;
L_0x00472e92:
    // 00472e92  8d830080ffff           -lea eax, [ebx - 0x8000]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-32768) /* -0x8000 */);
    // 00472e98  e978ffffff             -jmp 0x472e15
    goto L_0x00472e15;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_472ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472ea0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472ea1  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472ea2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472ea3  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472ea4  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00472ea7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00472ea9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00472eab  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00472ead  81783000000100         +cmp dword ptr [eax + 0x30], 0x10000
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472eb4  0f8c63010000           -jl 0x47301d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047301d;
    }
L_0x00472eba:
    // 00472eba  813d8c824c00f4010000   +cmp dword ptr [0x4c828c], 0x1f4
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014156) /* 0x4c828c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(500 /*0x1f4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472ec4  0f8e5f010000           -jle 0x473029
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473029;
    }
    // 00472eca  ba99990100             -mov edx, 0x19999
    cpu.edx = 104857 /*0x19999*/;
    // 00472ecf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00472ed1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472ed3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472ed6  c1e810                 +shr eax, 0x10
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
    // 00472ed9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472edb  6689442408             -mov word ptr [esp + 8], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00472ee0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00472ee2:
    // 00472ee2  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00472ee5  0fbfea                 -movsx ebp, dx
    cpu.ebp = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00472ee8  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00472eee  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00472ef1  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472ef3  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472ef5  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00472ef7  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472ef9  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00472efe  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472f00  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 00472f07  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472f09  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472f0b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00472f0d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472f0f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472f12  c1e810                 +shr eax, 0x10
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
    // 00472f15  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472f17  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00472f1a  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00472f1d  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00472f20  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472f22  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472f24  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00472f26  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472f28  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00472f2d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472f2f  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 00472f36  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472f38  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472f3a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00472f3c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472f3e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472f41  c1e810                 +shr eax, 0x10
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
    // 00472f44  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472f46  8b6c2406               -mov ebp, dword ptr [esp + 6]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(6) /* 0x6 */);
    // 00472f4a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00472f4c  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00472f4f  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 00472f52  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00472f58  c0e507                 +shl ch, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ch;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00472f5b  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472f5d  00ed                   +add ch, ch
    {
        x86::reg8& tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472f5f  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00472f61  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472f63  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00472f68  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472f6a  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 00472f71  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472f73  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472f75  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00472f77  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472f79  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472f7c  c1e810                 +shr eax, 0x10
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
    // 00472f7f  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472f81  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472f85  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00472f88  c0e407                 +shl ah, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg8& op = cpu.ah;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 00472f8b  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472f8d  00e4                   +add ah, ah
    {
        x86::reg8& tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ah));
        x86::reg8 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) == (1 & (tmp2 >> 7));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472f8f  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00472f91  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472f93  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00472f98  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472f9a  8b048514894c00         -mov eax, dword ptr [eax*4 + 0x4c8914]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */ + cpu.eax * 4);
    // 00472fa1  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472fa3  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472fa5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00472fa7  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472fa9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00472fac  c1e810                 +shr eax, 0x10
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
    // 00472faf  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00472fb1  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472fb4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472fb6  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00472fb9  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00472fbb  8987c4000000           -mov dword ptr [edi + 0xc4], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(196) /* 0xc4 */) = cpu.eax;
    // 00472fc1  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00472fc4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472fc6  8987c8000000           -mov dword ptr [edi + 0xc8], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(200) /* 0xc8 */) = cpu.eax;
    // 00472fcc  8b6e38                 -mov ebp, dword ptr [esi + 0x38]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00472fcf  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00472fd1  89afbc000000           -mov dword ptr [edi + 0xbc], ebp
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(188) /* 0xbc */) = cpu.ebp;
    // 00472fd7  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00472fdb  8b463c                 -mov eax, dword ptr [esi + 0x3c]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00472fde  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472fe0  8987c0000000           -mov dword ptr [edi + 0xc0], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 00472fe6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 00472fe9  8b6e38                 -mov ebp, dword ptr [esi + 0x38]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00472fec  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00472fee  89afb4000000           -mov dword ptr [edi + 0xb4], ebp
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 00472ff4  8b6e3c                 -mov ebp, dword ptr [esi + 0x3c]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 00472ff7  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472ff9  89afb8000000           -mov dword ptr [edi + 0xb8], ebp
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
    // 00472fff  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00473002  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00473004  8987ac000000           -mov dword ptr [edi + 0xac], eax
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0047300a  8b763c                 -mov esi, dword ptr [esi + 0x3c]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */);
    // 0047300d  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047300f  89b7b0000000           -mov dword ptr [edi + 0xb0], esi
    *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(176) /* 0xb0 */) = cpu.esi;
    // 00473015  83c40c                 +add esp, 0xc
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
    // 00473018  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473019  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047301a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047301b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047301c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047301d:
    // 0047301d  c7403000000100         -mov dword ptr [eax + 0x30], 0x10000
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 65536 /*0x10000*/;
    // 00473024  e991feffff             -jmp 0x472eba
    goto L_0x00472eba;
L_0x00473029:
    // 00473029  a198975100             -mov eax, dword ptr [0x519798]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347224) /* 0x519798 */);
    // 0047302e  8b5e30                 -mov ebx, dword ptr [esi + 0x30]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 00473031  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00473032  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00473034  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00473036  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00473038  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0047303c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047303f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00473041  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00473044  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00473046  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00473048  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047304a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047304c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047304f  c1e810                 +shr eax, 0x10
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
    // 00473052  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00473054  8a0d11985100           -mov cl, byte ptr [0x519811]
    cpu.cl = *app->getMemory<x86::reg8>(x86::reg32(5347345) /* 0x519811 */);
    // 0047305a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047305c  66d3fa                 -sar dx, cl
    cpu.dx = x86::reg16(x86::sreg16(cpu.dx) >> (cpu.cl % 32));
    // 0047305f  8a0d10985100           -mov cl, byte ptr [0x519810]
    cpu.cl = *app->getMemory<x86::reg8>(x86::reg32(5347344) /* 0x519810 */);
    // 00473065  66d3f8                 +sar ax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg16& op = cpu.ax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg16(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg16(x86::sreg16(op) >> tmp)));
        }
    }
    // 00473068  6689442408             -mov word ptr [esp + 8], ax
    *app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0047306d  e970feffff             -jmp 0x472ee2
    goto L_0x00472ee2;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473080  881511985100           -mov byte ptr [0x519811], dl
    *app->getMemory<x86::reg8>(x86::reg32(5347345) /* 0x519811 */) = cpu.dl;
    // 00473086  8b048560814c00         -mov eax, dword ptr [eax*4 + 0x4c8160]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5013856) /* 0x4c8160 */ + cpu.eax * 4);
    // 0047308d  881d10985100           -mov byte ptr [0x519810], bl
    *app->getMemory<x86::reg8>(x86::reg32(5347344) /* 0x519810 */) = cpu.bl;
    // 00473093  a398975100             -mov dword ptr [0x519798], eax
    *app->getMemory<x86::reg32>(x86::reg32(5347224) /* 0x519798 */) = cpu.eax;
    // 00473098  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4730a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004730a0  a1e8975100             -mov eax, dword ptr [0x5197e8]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 004730a5  e8225a0000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 004730aa  a1c0975100             -mov eax, dword ptr [0x5197c0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347264) /* 0x5197c0 */);
    // 004730af  e9185a0000             -jmp 0x478acc
    return sub_478acc(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4730c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004730c0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004730c1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004730c2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004730c3  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004730c8  bb38975100             -mov ebx, 0x519738
    cpu.ebx = 5347128 /*0x519738*/;
    // 004730cd  b8d4d74b00             -mov eax, 0x4bd7d4
    cpu.eax = 4970452 /*0x4bd7d4*/;
    // 004730d2  8b15c0975100           -mov edx, dword ptr [0x5197c0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5347264) /* 0x5197c0 */);
    // 004730d8  e833010000             -call 0x473210
    cpu.esp -= 4;
    sub_473210(app, cpu);
    if (cpu.terminate) return;
    // 004730dd  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004730e2  bb78965100             -mov ebx, 0x519678
    cpu.ebx = 5346936 /*0x519678*/;
    // 004730e7  b8d8d74b00             -mov eax, 0x4bd7d8
    cpu.eax = 4970456 /*0x4bd7d8*/;
    // 004730ec  8b15c0975100           -mov edx, dword ptr [0x5197c0]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5347264) /* 0x5197c0 */);
    // 004730f2  e819010000             -call 0x473210
    cpu.esp -= 4;
    sub_473210(app, cpu);
    if (cpu.terminate) return;
    // 004730f7  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 004730fc  bbc4975100             -mov ebx, 0x5197c4
    cpu.ebx = 5347268 /*0x5197c4*/;
    // 00473101  b8dcd74b00             -mov eax, 0x4bd7dc
    cpu.eax = 4970460 /*0x4bd7dc*/;
    // 00473106  8b15e8975100           -mov edx, dword ptr [0x5197e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 0047310c  e8ff000000             -call 0x473210
    cpu.esp -= 4;
    sub_473210(app, cpu);
    if (cpu.terminate) return;
    // 00473111  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00473116  bb9c975100             -mov ebx, 0x51979c
    cpu.ebx = 5347228 /*0x51979c*/;
    // 0047311b  b8e0d74b00             -mov eax, 0x4bd7e0
    cpu.eax = 4970464 /*0x4bd7e0*/;
    // 00473120  8b15e8975100           -mov edx, dword ptr [0x5197e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 00473126  e8e5000000             -call 0x473210
    cpu.esp -= 4;
    sub_473210(app, cpu);
    if (cpu.terminate) return;
    // 0047312b  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00473130  bbec975100             -mov ebx, 0x5197ec
    cpu.ebx = 5347308 /*0x5197ec*/;
    // 00473135  b8e4d74b00             -mov eax, 0x4bd7e4
    cpu.eax = 4970468 /*0x4bd7e4*/;
    // 0047313a  8b15e8975100           -mov edx, dword ptr [0x5197e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 00473140  e8cb000000             -call 0x473210
    cpu.esp -= 4;
    sub_473210(app, cpu);
    if (cpu.terminate) return;
    // 00473145  833dfcd24d0008         +cmp dword ptr [0x4dd2fc], 8
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5100284) /* 0x4dd2fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047314c  751e                   -jne 0x47316c
    if (!cpu.flags.zf)
    {
        goto L_0x0047316c;
    }
    // 0047314e  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00473153  bbd8965100             -mov ebx, 0x5196d8
    cpu.ebx = 5347032 /*0x5196d8*/;
    // 00473158  b8e8d74b00             -mov eax, 0x4bd7e8
    cpu.eax = 4970472 /*0x4bd7e8*/;
    // 0047315d  8b15e8975100           -mov edx, dword ptr [0x5197e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 00473163  e8a8000000             -call 0x473210
    cpu.esp -= 4;
    sub_473210(app, cpu);
    if (cpu.terminate) return;
    // 00473168  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473169  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047316a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047316b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047316c:
    // 0047316c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00473171  bbd8965100             -mov ebx, 0x5196d8
    cpu.ebx = 5347032 /*0x5196d8*/;
    // 00473176  b8ecd74b00             -mov eax, 0x4bd7ec
    cpu.eax = 4970476 /*0x4bd7ec*/;
    // 0047317b  8b15e8975100           -mov edx, dword ptr [0x5197e8]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */);
    // 00473181  e88a000000             -call 0x473210
    cpu.esp -= 4;
    sub_473210(app, cpu);
    if (cpu.terminate) return;
    // 00473186  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473187  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473188  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473189  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473190  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473191  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473192  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473193  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00473199  8b1578e54d00           -mov edx, dword ptr [0x4de578]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5105016) /* 0x4de578 */);
    // 0047319f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004731a0  68b8d74b00             -push 0x4bd7b8
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970424 /*0x4bd7b8*/;
    cpu.esp -= 4;
    // 004731a5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004731a9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004731aa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004731ac  e870720000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004731b1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004731b4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004731b6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004731b8  e8078c0000             -call 0x47bdc4
    cpu.esp -= 4;
    sub_47bdc4(app, cpu);
    if (cpu.terminate) return;
    // 004731bd  a3e8975100             -mov dword ptr [0x5197e8], eax
    *app->getMemory<x86::reg32>(x86::reg32(5347304) /* 0x5197e8 */) = cpu.eax;
    // 004731c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004731c4  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004731c9  e832010000             -call 0x473300
    cpu.esp -= 4;
    sub_473300(app, cpu);
    if (cpu.terminate) return;
    // 004731ce  8b0d78e54d00           -mov ecx, dword ptr [0x4de578]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5105016) /* 0x4de578 */);
    // 004731d4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004731d5  68c4d74b00             -push 0x4bd7c4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970436 /*0x4bd7c4*/;
    cpu.esp -= 4;
    // 004731da  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004731de  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004731df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004731e1  e83b720000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004731e6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004731e9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004731eb  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004731f0  e8cf8b0000             -call 0x47bdc4
    cpu.esp -= 4;
    sub_47bdc4(app, cpu);
    if (cpu.terminate) return;
    // 004731f5  a3c0975100             -mov dword ptr [0x5197c0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5347264) /* 0x5197c0 */) = cpu.eax;
    // 004731fa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004731fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004731fe  e8fd000000             -call 0x473300
    cpu.esp -= 4;
    sub_473300(app, cpu);
    if (cpu.terminate) return;
    // 00473203  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00473209  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047320a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047320b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047320c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_473210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473210  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473211  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473212  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473213  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473216  89442408               -mov dword ptr [esp + 8], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047321a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047321c  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00473220  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00473222  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00473224  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00473226  7e38                   -jle 0x473260
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473260;
    }
    // 00473228  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x0047322a:
    // 0047322a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047322b  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047322f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473230  68b0d74b00             -push 0x4bd7b0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970416 /*0x4bd7b0*/;
    cpu.esp -= 4;
    // 00473235  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473239  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047323a  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047323c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047323e  e8de710000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00473243  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00473247  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047324a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047324c  46                     -inc esi
    (cpu.esi)++;
    // 0047324d  e84e040000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00473252  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473256  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473259  39c6                   +cmp esi, eax
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
    // 0047325b  7ccd                   -jl 0x47322a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047322a;
    }
    // 0047325d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00473260:
    // 00473260  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473263  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473264  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473265  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473266  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473270  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 00473275  e852580000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0047327a  e8115fffff             -call 0x469190
    cpu.esp -= 4;
    sub_469190(app, cpu);
    if (cpu.terminate) return;
    // 0047327f  e91cfeffff             -jmp 0x4730a0
    return sub_4730a0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473290  e80b5fffff             -call 0x4691a0
    cpu.esp -= 4;
    sub_4691a0(app, cpu);
    if (cpu.terminate) return;
    // 00473295  e8e660ffff             -call 0x469380
    cpu.esp -= 4;
    sub_469380(app, cpu);
    if (cpu.terminate) return;
    // 0047329a  e871b3ffff             -call 0x46e610
    cpu.esp -= 4;
    sub_46e610(app, cpu);
    if (cpu.terminate) return;
    // 0047329f  e99c84ffff             -jmp 0x46b740
    return sub_46b740(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4732b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004732b0  e85b000000             -call 0x473310
    cpu.esp -= 4;
    sub_473310(app, cpu);
    if (cpu.terminate) return;
    // 004732b5  e906feffff             -jmp 0x4730c0
    return sub_4730c0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4732c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004732c0  e88b9effff             -call 0x46d150
    cpu.esp -= 4;
    sub_46d150(app, cpu);
    if (cpu.terminate) return;
    // 004732c5  e85685ffff             -call 0x46b820
    cpu.esp -= 4;
    sub_46b820(app, cpu);
    if (cpu.terminate) return;
    // 004732ca  e80185ffff             -call 0x46b7d0
    cpu.esp -= 4;
    sub_46b7d0(app, cpu);
    if (cpu.terminate) return;
    // 004732cf  e80c84ffff             -call 0x46b6e0
    cpu.esp -= 4;
    sub_46b6e0(app, cpu);
    if (cpu.terminate) return;
    // 004732d4  e8e760ffff             -call 0x4693c0
    cpu.esp -= 4;
    sub_4693c0(app, cpu);
    if (cpu.terminate) return;
    // 004732d9  e82281ffff             -call 0x46b400
    cpu.esp -= 4;
    sub_46b400(app, cpu);
    if (cpu.terminate) return;
    // 004732de  e95d9effff             -jmp 0x46d140
    return sub_46d140(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4732f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004732f0  e91b87ffff             -jmp 0x46ba10
    return sub_46ba10(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473300  e9cb87ffff             -jmp 0x46bad0
    return sub_46bad0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473310  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473311  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473312  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473313  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473314  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473315  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00473316  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0047331c  be14985100             -mov esi, 0x519814
    cpu.esi = 5347348 /*0x519814*/;
    // 00473321  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00473323  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00473325:
    // 00473325  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473326  6800d84b00             -push 0x4bd800
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970496 /*0x4bd800*/;
    cpu.esp -= 4;
    // 0047332b  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047332f  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473333  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473334  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00473336  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473339  e8e3700000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0047333e  8b1d1c995100           -mov ebx, dword ptr [0x51991c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5347612) /* 0x51991c */);
    // 00473344  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473347  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 0047334c  47                     -inc edi
    (cpu.edi)++;
    // 0047334d  e84e030000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00473352  89b5f8985100           -mov dword ptr [ebp + 0x5198f8], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5347576) /* 0x5198f8 */) = cpu.esi;
    // 00473358  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047335b  83ff08                 +cmp edi, 8
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047335e  7cc5                   -jl 0x473325
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473325;
    }
    // 00473360  b974985100             -mov ecx, 0x519874
    cpu.ecx = 5347444 /*0x519874*/;
    // 00473365  ba08d84b00             -mov edx, 0x4bd808
    cpu.edx = 4970504 /*0x4bd808*/;
    // 0047336a  8b1d1c995100           -mov ebx, dword ptr [0x51991c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5347612) /* 0x51991c */);
    // 00473370  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 00473375  e826030000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 0047337a  ba74985100             -mov edx, 0x519874
    cpu.edx = 5347444 /*0x519874*/;
    // 0047337f  b980985100             -mov ecx, 0x519880
    cpu.ecx = 5347456 /*0x519880*/;
    // 00473384  8b1d1c995100           -mov ebx, dword ptr [0x51991c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5347612) /* 0x51991c */);
    // 0047338a  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 0047338f  891540995100           -mov dword ptr [0x519940], edx
    *app->getMemory<x86::reg32>(x86::reg32(5347648) /* 0x519940 */) = cpu.edx;
    // 00473395  ba10d84b00             -mov edx, 0x4bd810
    cpu.edx = 4970512 /*0x4bd810*/;
    // 0047339a  be98985100             -mov esi, 0x519898
    cpu.esi = 5347480 /*0x519898*/;
    // 0047339f  e8fc020000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 004733a4  b980985100             -mov ecx, 0x519880
    cpu.ecx = 5347456 /*0x519880*/;
    // 004733a9  ba18d84b00             -mov edx, 0x4bd818
    cpu.edx = 4970520 /*0x4bd818*/;
    // 004733ae  8b1d1c995100           -mov ebx, dword ptr [0x51991c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5347612) /* 0x51991c */);
    // 004733b4  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 004733b9  890dec985100           -mov dword ptr [0x5198ec], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5347564) /* 0x5198ec */) = cpu.ecx;
    // 004733bf  b98c985100             -mov ecx, 0x51988c
    cpu.ecx = 5347468 /*0x51988c*/;
    // 004733c4  bfa4985100             -mov edi, 0x5198a4
    cpu.edi = 5347492 /*0x5198a4*/;
    // 004733c9  e8d2020000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 004733ce  bb8c985100             -mov ebx, 0x51988c
    cpu.ebx = 5347468 /*0x51988c*/;
    // 004733d3  b998985100             -mov ecx, 0x519898
    cpu.ecx = 5347480 /*0x519898*/;
    // 004733d8  ba20d84b00             -mov edx, 0x4bd820
    cpu.edx = 4970528 /*0x4bd820*/;
    // 004733dd  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 004733e2  891df0985100           -mov dword ptr [0x5198f0], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5347568) /* 0x5198f0 */) = cpu.ebx;
    // 004733e8  8b1d1c995100           -mov ebx, dword ptr [0x51991c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5347612) /* 0x51991c */);
    // 004733ee  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004733f0  e8ab020000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 004733f5  b9a4985100             -mov ecx, 0x5198a4
    cpu.ecx = 5347492 /*0x5198a4*/;
    // 004733fa  ba28d84b00             -mov edx, 0x4bd828
    cpu.edx = 4970536 /*0x4bd828*/;
    // 004733ff  8b1d1c995100           -mov ebx, dword ptr [0x51991c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5347612) /* 0x51991c */);
    // 00473405  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 0047340a  8935f4985100           -mov dword ptr [0x5198f4], esi
    *app->getMemory<x86::reg32>(x86::reg32(5347572) /* 0x5198f4 */) = cpu.esi;
    // 00473410  e88b020000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00473415  be14985100             -mov esi, 0x519814
    cpu.esi = 5347348 /*0x519814*/;
    // 0047341a  893df8985100           -mov dword ptr [0x5198f8], edi
    *app->getMemory<x86::reg32>(x86::reg32(5347576) /* 0x5198f8 */) = cpu.edi;
    // 00473420  81c69c000000           -add esi, 0x9c
    (cpu.esi) += x86::reg32(x86::sreg32(156 /*0x9c*/));
    // 00473426  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00473428:
    // 00473428  47                     -inc edi
    (cpu.edi)++;
    // 00473429  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047342a  6830d84b00             -push 0x4bd830
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970544 /*0x4bd830*/;
    cpu.esp -= 4;
    // 0047342f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00473433  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00473434  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00473438  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047343a  e8e26f0000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0047343f  8b1d1c995100           -mov ebx, dword ptr [0x51991c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5347612) /* 0x51991c */);
    // 00473445  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473448  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 0047344d  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00473450  e84b020000             -call 0x4736a0
    cpu.esp -= 4;
    sub_4736a0(app, cpu);
    if (cpu.terminate) return;
    // 00473455  89b528995100           -mov dword ptr [ebp + 0x519928], esi
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5347624) /* 0x519928 */) = cpu.esi;
    // 0047345b  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047345e  83ff05                 +cmp edi, 5
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473461  7cc5                   -jl 0x473428
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00473428;
    }
    // 00473463  bd14985100             -mov ebp, 0x519814
    cpu.ebp = 5347348 /*0x519814*/;
    // 00473468  ba38d84b00             -mov edx, 0x4bd838
    cpu.edx = 4970552 /*0x4bd838*/;
    // 0047346d  a128995100             -mov eax, dword ptr [0x519928]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */);
    // 00473472  892d44995100           -mov dword ptr [0x519944], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5347652) /* 0x519944 */) = cpu.ebp;
    // 00473478  e827390000             -call 0x476da4
    cpu.esp -= 4;
    sub_476da4(app, cpu);
    if (cpu.terminate) return;
    // 0047347d  a324995100             -mov dword ptr [0x519924], eax
    *app->getMemory<x86::reg32>(x86::reg32(5347620) /* 0x519924 */) = cpu.eax;
    // 00473482  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00473488  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473489  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047348a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047348b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047348c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047348d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047348e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_473490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473490  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473491  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473492  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00473498  8b1578e54d00           -mov edx, dword ptr [0x4de578]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5105016) /* 0x4de578 */);
    // 0047349e  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047349f  68f0d74b00             -push 0x4bd7f0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4970480 /*0x4bd7f0*/;
    cpu.esp -= 4;
    // 004734a4  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004734a8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004734a9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004734ab  e8716f0000             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004734b0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004734b3  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004734b5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004734ba  e8e1770000             -call 0x47aca0
    cpu.esp -= 4;
    sub_47aca0(app, cpu);
    if (cpu.terminate) return;
    // 004734bf  a328995100             -mov dword ptr [0x519928], eax
    *app->getMemory<x86::reg32>(x86::reg32(5347624) /* 0x519928 */) = cpu.eax;
    // 004734c4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004734c6  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004734cb  e80086ffff             -call 0x46bad0
    cpu.esp -= 4;
    sub_46bad0(app, cpu);
    if (cpu.terminate) return;
    // 004734d0  a31c995100             -mov dword ptr [0x51991c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5347612) /* 0x51991c */) = cpu.eax;
    // 004734d5  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004734db  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734dc  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004734dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4734f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004734f4  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004734f5  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004734f6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004734f8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004734fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004734fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004734fc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004734fd  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473500  771f                   -ja 0x473521
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00473521;
    }
    // 00473502  ff2495e0344700         -jmp dword ptr [edx*4 + 0x4734e0]
    cpu.ip = *app->getMemory<x86::reg32>(4666592 + cpu.edx * 4); goto dynamic_jump;
  case 0x00473509:
    // 00473509  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0047350c  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 0047350f  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00473512  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00473515  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00473518  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 0047351b  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047351e  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
L_0x00473521:
    // 00473521  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473522  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473523  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473524:
    // 00473524  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00473527  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 0047352a  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047352d  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00473530  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00473533  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00473536  8a4006                 -mov al, byte ptr [eax + 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00473539  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047353c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047353d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047353e  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047353f:
    // 0047353f  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00473542  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 00473545  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00473548  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0047354b  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0047354e  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00473551  8a4006                 -mov al, byte ptr [eax + 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00473554  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00473557  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473558  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473559  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047355a:
    // 0047355a  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047355d  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 00473560  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00473563  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00473566  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00473569  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 0047356c  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0047356f  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00473572  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473573  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473574  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473575:
    // 00473575  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00473578  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 0047357b  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047357e  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00473581  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00473584  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00473587  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047358a  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047358d  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047358e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047358f  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4735a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004735a4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004735a5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004735a6  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004735a7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004735a9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004735ab  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004735ac  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004735ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004735ae  83fa04                 +cmp edx, 4
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004735b1  771f                   -ja 0x4735d2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004735d2;
    }
    // 004735b3  ff249590354700         -jmp dword ptr [edx*4 + 0x473590]
    cpu.ip = *app->getMemory<x86::reg32>(4666768 + cpu.edx * 4); goto dynamic_jump;
  case 0x004735ba:
    // 004735ba  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004735bd  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 004735c0  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004735c3  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 004735c6  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004735c9  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004735cc  8a4006                 -mov al, byte ptr [eax + 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004735cf  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
L_0x004735d2:
    // 004735d2  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735d3  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735d4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735d5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004735d6:
    // 004735d6  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004735d9  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 004735dc  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004735df  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 004735e2  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 004735e5  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 004735e8  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004735eb  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 004735ee  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735ef  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735f0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004735f1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004735f2:
    // 004735f2  8a4b05                 -mov cl, byte ptr [ebx + 5]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */);
    // 004735f5  3a4b04                 +cmp cl, byte ptr [ebx + 4]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004735f8  731c                   -jae 0x473616
    if (!cpu.flags.cf)
    {
        goto L_0x00473616;
    }
L_0x004735fa:
    // 004735fa  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004735fd  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 00473600  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00473603  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00473606  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00473609  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 0047360c  8a4006                 -mov al, byte ptr [eax + 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047360f  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 00473612  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473613  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473614  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473615  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473616:
    // 00473616  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00473619  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 0047361c  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047361f  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00473622  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00473625  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00473628  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047362b  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047362e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047362f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473630  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473631  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00473632:
    // 00473632  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00473635  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 00473638  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0047363b  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0047363e  8a5004                 -mov dl, byte ptr [eax + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00473641  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00473644  8a4005                 -mov al, byte ptr [eax + 5]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00473647  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047364a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047364b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047364c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047364d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047364e:
    // 0047364e  8a5304                 -mov dl, byte ptr [ebx + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00473651  3a5305                 +cmp dl, byte ptr [ebx + 5]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00473654  76a4                   -jbe 0x4735fa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004735fa;
    }
    // 00473656  8a5005                 -mov dl, byte ptr [eax + 5]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00473659  885304                 -mov byte ptr [ebx + 4], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.dl;
    // 0047365c  8a5006                 -mov dl, byte ptr [eax + 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047365f  885305                 -mov byte ptr [ebx + 5], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00473662  8a5007                 -mov dl, byte ptr [eax + 7]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00473665  885306                 -mov byte ptr [ebx + 6], dl
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 00473668  8a4004                 -mov al, byte ptr [eax + 4]
    cpu.al = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047366b  884307                 -mov byte ptr [ebx + 7], al
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047366e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047366f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473670  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473671  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473680  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00473681  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00473682  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00473684  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473686  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00473688  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473689  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047368a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047368b  e8f07cffff             -call 0x46b380
    cpu.esp -= 4;
    sub_46b380(app, cpu);
    if (cpu.terminate) return;
    // 00473690  894308                 -mov dword ptr [ebx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00473693  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473694  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473695  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4736a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004736a0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004736a2  751d                   -jne 0x4736c1
    if (!cpu.flags.zf)
    {
        goto L_0x004736c1;
    }
    // 004736a4  8911                   -mov dword ptr [ecx], edx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
L_0x004736a6:
    // 004736a6  c6410400               -mov byte ptr [ecx + 4], 0
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004736aa  c6410501               -mov byte ptr [ecx + 5], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 1 /*0x1*/;
    // 004736ae  c6410602               -mov byte ptr [ecx + 6], 2
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = 2 /*0x2*/;
    // 004736b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004736b4  c6410703               -mov byte ptr [ecx + 7], 3
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = 3 /*0x3*/;
    // 004736b8  e8c37cffff             -call 0x46b380
    cpu.esp -= 4;
    sub_46b380(app, cpu);
    if (cpu.terminate) return;
    // 004736bd  894108                 -mov dword ptr [ecx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004736c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004736c1:
    // 004736c1  e8de360000             -call 0x476da4
    cpu.esp -= 4;
    sub_476da4(app, cpu);
    if (cpu.terminate) return;
    // 004736c6  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004736c8  ebdc                   -jmp 0x4736a6
    goto L_0x004736a6;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4736d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004736d0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004736d1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004736d2  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004736d5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004736d7  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 004736de  7424                   -je 0x473704
    if (cpu.flags.zf)
    {
        goto L_0x00473704;
    }
    // 004736e0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004736e1  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004736e5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004736e7  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004736eb  894c240c               -mov dword ptr [esp + 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004736ef  894c2410               -mov dword ptr [esp + 0x10], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004736f3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004736f4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004736f5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004736f6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004736f8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004736fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004736fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004736fc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004736fe  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473701  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473702  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473703  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473704:
    // 00473704  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00473706  e8e576feff             -call 0x45adf0
    cpu.esp -= 4;
    sub_45adf0(app, cpu);
    if (cpu.terminate) return;
    // 0047370b  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047370d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047370f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473710  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00473711  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473713  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00473716  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473717  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473718  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473720(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473720  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 00473727  7503                   -jne 0x47372c
    if (!cpu.flags.zf)
    {
        goto L_0x0047372c;
    }
    // 00473729  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047372b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047372c:
    // 0047372c  8b048550995100         -mov eax, dword ptr [eax*4 + 0x519950]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5347664) /* 0x519950 */ + cpu.eax * 4);
    // 00473733  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_473740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473740  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00473741  f605f8d24d0040         +test byte ptr [0x4dd2f8], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(x86::reg32(5100280) /* 0x4dd2f8 */) & 64 /*0x40*/));
    // 00473748  740a                   -je 0x473754
    if (cpu.flags.zf)
    {
        goto L_0x00473754;
    }
    // 0047374a  8b1588995100           -mov edx, dword ptr [0x519988]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5347720) /* 0x519988 */);
    // 00473750  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00473752  7502                   -jne 0x473756
    if (!cpu.flags.zf)
    {
        goto L_0x00473756;
    }
L_0x00473754:
    // 00473754  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473755  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473756:
    // 00473756  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00473758  e86f530000             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
    // 0047375d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047375e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_473760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00473760  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00473761  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00473763  8b15f4d04d00           -mov edx, dword ptr [0x4dd0f4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5099764) /* 0x4dd0f4 */);
    // 00473769  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047376b  7420                   -je 0x47378d
    if (cpu.flags.zf)
    {
        goto L_0x0047378d;
    }
    // 0047376d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047376f  750f                   -jne 0x473780
    if (!cpu.flags.zf)
    {
        goto L_0x00473780;
    }
    // 00473771  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473772  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00473774  bbb4000000             -mov ebx, 0xb4
    cpu.ebx = 180 /*0xb4*/;
L_0x00473779:
    // 00473779  e822000000             -call 0x4737a0
    cpu.esp -= 4;
    sub_4737a0(app, cpu);
    if (cpu.terminate) return;
    // 0047377e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047377f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00473780:
    // 00473780  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00473781  baf0000000             -mov edx, 0xf0
    cpu.edx = 240 /*0xf0*/;
    // 00473786  bba4010000             -mov ebx, 0x1a4
    cpu.ebx = 420 /*0x1a4*/;
    // 0047378b  ebec                   -jmp 0x473779
    goto L_0x00473779;
L_0x0047378d:
    // 0047378d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047378e  bb68010000             -mov ebx, 0x168
    cpu.ebx = 360 /*0x168*/;
    // 00473793  e808000000             -call 0x4737a0
    cpu.esp -= 4;
    sub_4737a0(app, cpu);
    if (cpu.terminate) return;
    // 00473798  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00473799  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
