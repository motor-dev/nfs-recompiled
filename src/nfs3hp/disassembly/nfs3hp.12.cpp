#include "nfs3hp.h"
#include <lib/thread.h>

namespace nfs3hp
{

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4451d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004451d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004451d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004451d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004451d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004451d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004451d5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004451d7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004451da  8b35e8e55500           -mov esi, dword ptr [0x55e5e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 004451e0  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004451e7  0f845e000000           -je 0x44524b
    if (cpu.flags.zf)
    {
        goto L_0x0044524b;
    }
    // 004451ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004451ef:
    // 004451ef  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004451f1  8a15648c5500           -mov dl, byte ptr [0x558c64]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 004451f7  39d0                   +cmp eax, edx
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
    // 004451f9  0f8db2000000           -jge 0x4452b1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004452b1;
    }
    // 004451ff  8d14c500000000         -lea edx, [eax*8]
    cpu.edx = x86::reg32(cpu.eax * 8);
    // 00445206  8b8ace0f6600           -mov ecx, dword ptr [edx + 0x660fce]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6688718) /* 0x660fce */);
    // 0044520c  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0044520f  39ce                   +cmp esi, ecx
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
    // 00445211  7e35                   -jle 0x445248
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00445248;
    }
    // 00445213  8b9ad40f6600           -mov ebx, dword ptr [edx + 0x660fd4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6688724) /* 0x660fd4 */);
    // 00445219  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0044521c  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0044521e  39ce                   +cmp esi, ecx
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
    // 00445220  7d26                   -jge 0x445248
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445248;
    }
    // 00445222  8b8ad00f6600           -mov ecx, dword ptr [edx + 0x660fd0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6688720) /* 0x660fd0 */);
    // 00445228  8b1de4e55500           -mov ebx, dword ptr [0x55e5e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 0044522e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00445231  39d9                   +cmp ecx, ebx
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
    // 00445233  7d13                   -jge 0x445248
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445248;
    }
    // 00445235  8b92d20f6600           -mov edx, dword ptr [edx + 0x660fd2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6688722) /* 0x660fd2 */);
    // 0044523b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044523e  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00445240  39da                   +cmp edx, ebx
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
    // 00445242  0f8f6e000000           -jg 0x4452b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004452b6;
    }
L_0x00445248:
    // 00445248  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00445249  eba4                   -jmp 0x4451ef
    goto L_0x004451ef;
L_0x0044524b:
    // 0044524b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044524d:
    // 0044524d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044524f  8a15648c5500           -mov dl, byte ptr [0x558c64]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 00445255  39d0                   +cmp eax, edx
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
    // 00445257  7d58                   -jge 0x4452b1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004452b1;
    }
    // 00445259  8b0cc5d00f6600         -mov ecx, dword ptr [eax*8 + 0x660fd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688720) /* 0x660fd0 */ + cpu.eax * 8);
    // 00445260  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00445263  8d59f1                 -lea ebx, [ecx - 0xf]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-15) /* -0xf */);
    // 00445266  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00445269  8b1cc5d20f6600         -mov ebx, dword ptr [eax*8 + 0x660fd2]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6688722) /* 0x660fd2 */ + cpu.eax * 8);
    // 00445270  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00445273  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00445275  83c10a                 -add ecx, 0xa
    (cpu.ecx) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00445278  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0044527b  8b0cc5ce0f6600         -mov ecx, dword ptr [eax*8 + 0x660fce]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688718) /* 0x660fce */ + cpu.eax * 8);
    // 00445282  8b14c5d40f6600         -mov edx, dword ptr [eax*8 + 0x660fd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688724) /* 0x660fd4 */ + cpu.eax * 8);
    // 00445289  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0044528c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044528f  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 00445292  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00445294  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445296  7e16                   -jle 0x4452ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004452ae;
    }
    // 00445298  39d6                   +cmp esi, edx
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
    // 0044529a  7d12                   -jge 0x4452ae
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004452ae;
    }
    // 0044529c  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044529f  8b15e4e55500           -mov edx, dword ptr [0x55e5e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 004452a5  39ca                   +cmp edx, ecx
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
    // 004452a7  7e05                   -jle 0x4452ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004452ae;
    }
    // 004452a9  3b55f8                 +cmp edx, dword ptr [ebp - 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004452ac  7c08                   -jl 0x4452b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004452b6;
    }
L_0x004452ae:
    // 004452ae  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004452af  eb9c                   -jmp 0x44524d
    goto L_0x0044524d;
L_0x004452b1:
    // 004452b1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004452b6:
    // 004452b6  8935e8e55500           -mov dword ptr [0x55e5e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.esi;
    // 004452bc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004452be  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004452bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004452c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004452c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004452c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004452c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4452d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004452d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004452d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004452d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004452d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004452d4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004452d6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004452d9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004452db  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004452de  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 004452e3  e818ce0000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 004452e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004452ea  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004452ec  a1748c5500             -mov eax, dword ptr [0x558c74]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606516) /* 0x558c74 */);
    // 004452f1  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004452f4  8b0d788c5500           -mov ecx, dword ptr [0x558c78]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606520) /* 0x558c78 */);
    // 004452fa  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x004452fd:
    // 004452fd  39f3                   +cmp ebx, esi
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
    // 004452ff  0f8d73000000           -jge 0x445378
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445378;
    }
    // 00445305  83fe06                 +cmp esi, 6
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445308  7d6b                   -jge 0x445375
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445375;
    }
    // 0044530a  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044530d  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00445314  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00445316  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00445318  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044531a  740e                   -je 0x44532a
    if (cpu.flags.zf)
    {
        goto L_0x0044532a;
    }
    // 0044531c  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00445321  e8facc0000             -call 0x452020
    cpu.esp -= 4;
    sub_452020(app, cpu);
    if (cpu.terminate) return;
    // 00445326  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00445328  eb02                   -jmp 0x44532c
    goto L_0x0044532c;
L_0x0044532a:
    // 0044532a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044532c:
    // 0044532c  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 00445333  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00445336  6689b8d20f6600         -mov word ptr [eax + 0x660fd2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6688722) /* 0x660fd2 */) = cpu.di;
    // 0044533d  668990d40f6600         -mov word ptr [eax + 0x660fd4], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6688724) /* 0x660fd4 */) = cpu.dx;
    // 00445344  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 0044534a  668988d00f6600         -mov word ptr [eax + 0x660fd0], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6688720) /* 0x660fd0 */) = cpu.cx;
    // 00445351  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00445353  740b                   -je 0x445360
    if (cpu.flags.zf)
    {
        goto L_0x00445360;
    }
    // 00445355  66c780d60f66001e00     -mov word ptr [eax + 0x660fd6], 0x1e
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6688726) /* 0x660fd6 */) = 30 /*0x1e*/;
    // 0044535e  eb09                   -jmp 0x445369
    goto L_0x00445369;
L_0x00445360:
    // 00445360  66c780d60f66001200     -mov word ptr [eax + 0x660fd6], 0x12
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6688726) /* 0x660fd6 */) = 18 /*0x12*/;
L_0x00445369:
    // 00445369  8b04ddd40f6600         -mov eax, dword ptr [ebx*8 + 0x660fd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688724) /* 0x660fd4 */ + cpu.ebx * 8);
    // 00445370  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00445373  01c1                   +add ecx, eax
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
L_0x00445375:
    // 00445375  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00445376  eb85                   -jmp 0x4452fd
    goto L_0x004452fd;
L_0x00445378:
    // 00445378  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044537a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044537b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044537c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044537d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044537e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_445380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00445381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00445382  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445383  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445384  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00445385  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445386  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445388  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0044538b  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 00445390  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 00445395  668955fc               -mov word ptr [ebp - 4], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.dx;
    // 00445399  668955f8               -mov word ptr [ebp - 8], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.dx;
    // 0044539d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044539f  e85ccd0000             -call 0x452100
    cpu.esp -= 4;
    sub_452100(app, cpu);
    if (cpu.terminate) return;
    // 004453a4  8955ec                 -mov dword ptr [ebp - 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.edx;
L_0x004453a7:
    // 004453a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004453a9  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004453ac  a0648c5500             -mov al, byte ptr [0x558c64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 004453b1  39c8                   +cmp eax, ecx
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
    // 004453b3  0f8e50010000           -jle 0x445509
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00445509;
    }
    // 004453b9  8b15688c5500           -mov edx, dword ptr [0x558c68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606504) /* 0x558c68 */);
    // 004453bf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004453c1  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004453c4  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004453c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004453c9  0f8432010000           -je 0x445501
    if (cpu.flags.zf)
    {
        goto L_0x00445501;
    }
    // 004453cf  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004453d6  741a                   -je 0x4453f2
    if (cpu.flags.zf)
    {
        goto L_0x004453f2;
    }
    // 004453d8  3b0d608c5500           +cmp ecx, dword ptr [0x558c60]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004453de  7509                   -jne 0x4453e9
    if (!cpu.flags.zf)
    {
        goto L_0x004453e9;
    }
    // 004453e0  c745f440e4ff00         -mov dword ptr [ebp - 0xc], 0xffe440
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 16770112 /*0xffe440*/;
    // 004453e7  eb21                   -jmp 0x44540a
    goto L_0x0044540a;
L_0x004453e9:
    // 004453e9  c745f4fd9d64ff         -mov dword ptr [ebp - 0xc], 0xff649dfd
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 4284784125 /*0xff649dfd*/;
    // 004453f0  eb18                   -jmp 0x44540a
    goto L_0x0044540a;
L_0x004453f2:
    // 004453f2  3b0d608c5500           +cmp ecx, dword ptr [0x558c60]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004453f8  7509                   -jne 0x445403
    if (!cpu.flags.zf)
    {
        goto L_0x00445403;
    }
    // 004453fa  c745f440e4ff00         -mov dword ptr [ebp - 0xc], 0xffe440
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 16770112 /*0xffe440*/;
    // 00445401  eb07                   -jmp 0x44540a
    goto L_0x0044540a;
L_0x00445403:
    // 00445403  c745f4fd9d6400         -mov dword ptr [ebp - 0xc], 0x649dfd
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = 6594045 /*0x649dfd*/;
L_0x0044540a:
    // 0044540a  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0044540d  8b156c8c5500           -mov edx, dword ptr [0x558c6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606508) /* 0x558c6c */);
    // 00445413  8b3cc5d00f6600         -mov edi, dword ptr [eax*8 + 0x660fd0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6688720) /* 0x660fd0 */ + cpu.eax * 8);
    // 0044541a  8b34c5ce0f6600         -mov esi, dword ptr [eax*8 + 0x660fce]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6688718) /* 0x660fce */ + cpu.eax * 8);
    // 00445421  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00445424  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00445427  8b1534925500           -mov edx, dword ptr [0x559234]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 0044542d  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00445430  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00445432  745b                   -je 0x44548f
    if (cpu.flags.zf)
    {
        goto L_0x0044548f;
    }
    // 00445434  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00445436  7428                   -je 0x445460
    if (cpu.flags.zf)
    {
        goto L_0x00445460;
    }
    // 00445438  833800                 +cmp dword ptr [eax], 0
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
    // 0044543b  7407                   -je 0x445444
    if (cpu.flags.zf)
    {
        goto L_0x00445444;
    }
    // 0044543d  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 00445442  eb05                   -jmp 0x445449
    goto L_0x00445449;
L_0x00445444:
    // 00445444  6800008000             -push 0x800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8388608 /*0x800000*/;
    cpu.esp -= 4;
L_0x00445449:
    // 00445449  8b4df6                 -mov ecx, dword ptr [ebp - 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 0044544c  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0044544f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00445451  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00445453  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00445456  c1fb10                 +sar ebx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00445459  e8b2340900             -call 0x4d8910
    cpu.esp -= 4;
    sub_4d8910(app, cpu);
    if (cpu.terminate) return;
    // 0044545e  eb1a                   -jmp 0x44547a
    goto L_0x0044547a;
L_0x00445460:
    // 00445460  6800008000             -push 0x800000
    app->getMemory<x86::reg32>(cpu.esp-4) = 8388608 /*0x800000*/;
    cpu.esp -= 4;
    // 00445465  8b4df6                 -mov ecx, dword ptr [ebp - 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-10) /* -0xa */);
    // 00445468  8b5dfa                 -mov ebx, dword ptr [ebp - 6]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0044546b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0044546d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044546f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00445472  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00445475  e896340900             -call 0x4d8910
    cpu.esp -= 4;
    sub_4d8910(app, cpu);
    if (cpu.terminate) return;
L_0x0044547a:
    // 0044547a  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044547d  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 00445480  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00445485  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00445486  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00445489  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044548b  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0044548d  eb67                   -jmp 0x4454f6
    goto L_0x004454f6;
L_0x0044548f:
    // 0044548f  8b0d64106600           -mov ecx, dword ptr [0x661064]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 00445495  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00445498  81c1ffffff00           -add ecx, 0xffffff
    (cpu.ecx) += x86::reg32(x86::sreg32(16777215 /*0xffffff*/));
    // 0044549e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004454a0  7423                   -je 0x4454c5
    if (cpu.flags.zf)
    {
        goto L_0x004454c5;
    }
    // 004454a2  833800                 +cmp dword ptr [eax], 0
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
    // 004454a5  740d                   -je 0x4454b4
    if (cpu.flags.zf)
    {
        goto L_0x004454b4;
    }
    // 004454a7  a1248b5500             -mov eax, dword ptr [0x558b24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606180) /* 0x558b24 */);
    // 004454ac  8d5e03                 -lea ebx, [esi + 3]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(3) /* 0x3 */);
    // 004454af  8d57ff                 -lea edx, [edi - 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004454b2  eb0a                   -jmp 0x4454be
    goto L_0x004454be;
L_0x004454b4:
    // 004454b4  a1288b5500             -mov eax, dword ptr [0x558b28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606184) /* 0x558b28 */);
    // 004454b9  8d5e02                 -lea ebx, [esi + 2]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004454bc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x004454be:
    // 004454be  e89d1c0900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
    // 004454c3  eb0e                   -jmp 0x4454d3
    goto L_0x004454d3;
L_0x004454c5:
    // 004454c5  a1288b5500             -mov eax, dword ptr [0x558b28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606184) /* 0x558b28 */);
    // 004454ca  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004454cc  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004454ce  e88d1c0900             -call 0x4d7160
    cpu.esp -= 4;
    sub_4d7160(app, cpu);
    if (cpu.terminate) return;
L_0x004454d3:
    // 004454d3  8d5df8                 -lea ebx, [ebp - 8]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004454d6  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004454d9  a1248b5500             -mov eax, dword ptr [0x558b24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606180) /* 0x558b24 */);
    // 004454de  8b4df4                 -mov ecx, dword ptr [ebp - 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004454e1  e80a120900             -call 0x4d66f0
    cpu.esp -= 4;
    sub_4d66f0(app, cpu);
    if (cpu.terminate) return;
    // 004454e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004454e7  8b45fa                 -mov eax, dword ptr [ebp - 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 004454ea  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004454ec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004454ee  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004454f1  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
L_0x004454f6:
    // 004454f6  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 004454f9  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004454fc  e88fcc0000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x00445501:
    // 00445501  ff45ec                 +inc dword ptr [ebp - 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00445504  e99efeffff             -jmp 0x4453a7
    goto L_0x004453a7;
L_0x00445509:
    // 00445509  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044550b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044550c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044550d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044550e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044550f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445510  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445511  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_445520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445520  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00445521  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00445522  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445523  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445524  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00445525  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445526  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445528  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044552a  663d0048               +cmp ax, 0x4800
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044552e  722f                   -jb 0x44555f
    if (cpu.flags.cf)
    {
        goto L_0x0044555f;
    }
    // 00445530  764c                   -jbe 0x44557e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044557e;
    }
    // 00445532  8b0d308b5500           -mov ecx, dword ptr [0x558b30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 00445538  49                     -dec ecx
    (cpu.ecx)--;
    // 00445539  663d004d               +cmp ax, 0x4d00
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044553d  7215                   -jb 0x445554
    if (cpu.flags.cf)
    {
        goto L_0x00445554;
    }
    // 0044553f  0f86c6000000           -jbe 0x44560b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044560b;
    }
    // 00445545  663d0050               +cmp ax, 0x5000
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00445549  0f848a000000           -je 0x4455d9
    if (cpu.flags.zf)
    {
        goto L_0x004455d9;
    }
    // 0044554f  e91e010000             -jmp 0x445672
    goto L_0x00445672;
L_0x00445554:
    // 00445554  663d004b               +cmp ax, 0x4b00
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00445558  7455                   -je 0x4455af
    if (cpu.flags.zf)
    {
        goto L_0x004455af;
    }
    // 0044555a  e913010000             -jmp 0x445672
    goto L_0x00445672;
L_0x0044555f:
    // 0044555f  663d0d00               +cmp ax, 0xd
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00445563  0f8209010000           -jb 0x445672
    if (cpu.flags.cf)
    {
        goto L_0x00445672;
    }
    // 00445569  0f86c6000000           -jbe 0x445635
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00445635;
    }
    // 0044556f  663d1b00               +cmp ax, 0x1b
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00445573  0f84f4000000           -je 0x44566d
    if (cpu.flags.zf)
    {
        goto L_0x0044566d;
    }
    // 00445579  e9f4000000             -jmp 0x445672
    goto L_0x00445672;
L_0x0044557e:
    // 0044557e  8b0d608c5500           -mov ecx, dword ptr [0x558c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */);
    // 00445584  49                     -dec ecx
    (cpu.ecx)--;
    // 00445585  890d608c5500           -mov dword ptr [0x558c60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.ecx;
    // 0044558b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044558d  7d0d                   -jge 0x44559c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044559c;
    }
    // 0044558f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00445591  a0648c5500             -mov al, byte ptr [0x558c64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 00445596  48                     -dec eax
    (cpu.eax)--;
    // 00445597  a3608c5500             -mov dword ptr [0x558c60], eax
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.eax;
L_0x0044559c:
    // 0044559c  a1608c5500             -mov eax, dword ptr [0x558c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */);
    // 004455a1  e8bafbffff             -call 0x445160
    cpu.esp -= 4;
    sub_445160(app, cpu);
    if (cpu.terminate) return;
    // 004455a6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004455a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004455af:
    // 004455af  8b353c8b5500           -mov esi, dword ptr [0x558b3c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 004455b5  4e                     -dec esi
    (cpu.esi)--;
    // 004455b6  89353c8b5500           -mov dword ptr [0x558b3c], esi
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.esi;
    // 004455bc  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004455be  7d06                   -jge 0x4455c6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004455c6;
    }
    // 004455c0  890d3c8b5500           -mov dword ptr [0x558b3c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ecx;
L_0x004455c6:
    // 004455c6  a13c8b5500             -mov eax, dword ptr [0x558b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 004455cb  e8a0efffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 004455d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004455d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004455d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004455d9:
    // 004455d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004455db  8b0d608c5500           -mov ecx, dword ptr [0x558c60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */);
    // 004455e1  a0648c5500             -mov al, byte ptr [0x558c64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 004455e6  41                     -inc ecx
    (cpu.ecx)++;
    // 004455e7  48                     -dec eax
    (cpu.eax)--;
    // 004455e8  890d608c5500           -mov dword ptr [0x558c60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.ecx;
    // 004455ee  39c8                   +cmp eax, ecx
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
    // 004455f0  7d06                   -jge 0x4455f8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004455f8;
    }
    // 004455f2  8915608c5500           -mov dword ptr [0x558c60], edx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.edx;
L_0x004455f8:
    // 004455f8  a1608c5500             -mov eax, dword ptr [0x558c60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */);
    // 004455fd  e85efbffff             -call 0x445160
    cpu.esp -= 4;
    sub_445160(app, cpu);
    if (cpu.terminate) return;
    // 00445602  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00445604  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445605  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445606  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445607  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445608  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445609  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044560a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044560b:
    // 0044560b  8b3d3c8b5500           -mov edi, dword ptr [0x558b3c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00445611  47                     -inc edi
    (cpu.edi)++;
    // 00445612  893d3c8b5500           -mov dword ptr [0x558b3c], edi
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.edi;
    // 00445618  39f9                   +cmp ecx, edi
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
    // 0044561a  7d06                   -jge 0x445622
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445622;
    }
    // 0044561c  89153c8b5500           -mov dword ptr [0x558b3c], edx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.edx;
L_0x00445622:
    // 00445622  a13c8b5500             -mov eax, dword ptr [0x558b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00445627  e844efffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 0044562c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044562e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044562f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445630  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445631  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445632  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445633  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445634  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00445635:
    // 00445635  8b1d608c5500           -mov ebx, dword ptr [0x558c60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */);
    // 0044563b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044563d  7c20                   -jl 0x44565f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044565f;
    }
    // 0044563f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00445641  a0648c5500             -mov al, byte ptr [0x558c64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 00445646  39d8                   +cmp eax, ebx
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
    // 00445648  7e15                   -jle 0x44565f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044565f;
    }
    // 0044564a  8b156c8c5500           -mov edx, dword ptr [0x558c6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606508) /* 0x558c6c */);
    // 00445650  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00445652  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 00445655  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00445657  7406                   -je 0x44565f
    if (cpu.flags.zf)
    {
        goto L_0x0044565f;
    }
    // 00445659  c70001000000           -mov dword ptr [eax], 1
    app->getMemory<x86::reg32>(cpu.eax) = 1 /*0x1*/;
L_0x0044565f:
    // 0044565f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00445664  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00445666  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445667  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445668  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445669  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044566a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044566b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044566c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044566d:
    // 0044566d  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
L_0x00445672:
    // 00445672  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00445674  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445675  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445676  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445677  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445678  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445679  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044567a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_445680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445680  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00445681  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00445682  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445683  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445684  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00445685  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445686  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445688  e843efffff             -call 0x4445d0
    cpu.esp -= 4;
    sub_4445d0(app, cpu);
    if (cpu.terminate) return;
    // 0044568d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044568f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00445691  e83afbffff             -call 0x4451d0
    cpu.esp -= 4;
    sub_4451d0(app, cpu);
    if (cpu.terminate) return;
    // 00445696  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00445698  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044569a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044569c  7c2f                   -jl 0x4456cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004456cd;
    }
    // 0044569e  3b15308b5500           +cmp edx, dword ptr [0x558b30]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004456a4  7d27                   -jge 0x4456cd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004456cd;
    }
    // 004456a6  3b153c8b5500           +cmp edx, dword ptr [0x558b3c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004456ac  740c                   -je 0x4456ba
    if (cpu.flags.zf)
    {
        goto L_0x004456ba;
    }
    // 004456ae  ba2d000000             -mov edx, 0x2d
    cpu.edx = 45 /*0x2d*/;
    // 004456b3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004456b5  e8162bfdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x004456ba:
    // 004456ba  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004456bf  891d3c8b5500           -mov dword ptr [0x558b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ebx;
    // 004456c5  8915608c5500           -mov dword ptr [0x558c60], edx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.edx;
    // 004456cb  eb45                   -jmp 0x445712
    goto L_0x00445712;
L_0x004456cd:
    // 004456cd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004456cf  7c32                   -jl 0x445703
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00445703;
    }
    // 004456d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004456d3  a0648c5500             -mov al, byte ptr [0x558c64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 004456d8  39c1                   +cmp ecx, eax
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
    // 004456da  7d27                   -jge 0x445703
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445703;
    }
    // 004456dc  3b0d608c5500           +cmp ecx, dword ptr [0x558c60]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004456e2  740c                   -je 0x4456f0
    if (cpu.flags.zf)
    {
        goto L_0x004456f0;
    }
    // 004456e4  ba2d000000             -mov edx, 0x2d
    cpu.edx = 45 /*0x2d*/;
    // 004456e9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004456eb  e8e02afdff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x004456f0:
    // 004456f0  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 004456f5  890d608c5500           -mov dword ptr [0x558c60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.ecx;
    // 004456fb  893d3c8b5500           -mov dword ptr [0x558b3c], edi
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.edi;
    // 00445701  eb0f                   -jmp 0x445712
    goto L_0x00445712;
L_0x00445703:
    // 00445703  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00445708  a33c8b5500             -mov dword ptr [0x558b3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.eax;
    // 0044570d  a3608c5500             -mov dword ptr [0x558c60], eax
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.eax;
L_0x00445712:
    // 00445712  b850106600             -mov eax, 0x661050
    cpu.eax = 6688848 /*0x661050*/;
    // 00445717  bb50106600             -mov ebx, 0x661050
    cpu.ebx = 6688848 /*0x661050*/;
    // 0044571c  e8afe1ffff             -call 0x4438d0
    cpu.esp -= 4;
    sub_4438d0(app, cpu);
    if (cpu.terminate) return;
    // 00445721  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 00445727  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 0044572c  e80fe8ffff             -call 0x443f40
    cpu.esp -= 4;
    sub_443f40(app, cpu);
    if (cpu.terminate) return;
    // 00445731  e84afcffff             -call 0x445380
    cpu.esp -= 4;
    sub_445380(app, cpu);
    if (cpu.terminate) return;
    // 00445736  b850106600             -mov eax, 0x661050
    cpu.eax = 6688848 /*0x661050*/;
    // 0044573b  8b153c8b5500           -mov edx, dword ptr [0x558b3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00445741  e8bae8ffff             -call 0x444000
    cpu.esp -= 4;
    sub_444000(app, cpu);
    if (cpu.terminate) return;
    // 00445746  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00445748  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445749  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044574a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044574b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044574c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044574d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044574e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_445750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445750  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445751  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00445752  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445753  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445755  83ec68                 -sub esp, 0x68
    (cpu.esp) -= x86::reg32(x86::sreg32(104 /*0x68*/));
    // 00445758  8b7d28                 -mov edi, dword ptr [ebp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    // 0044575b  895de8                 -mov dword ptr [ebp - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 0044575e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00445760  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 00445763  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00445765  890d708c5500           -mov dword ptr [0x558c70], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606512) /* 0x558c70 */) = cpu.ecx;
    // 0044576b  890d0c8b5500           -mov dword ptr [0x558b0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.ecx;
    // 00445771  890d388b5500           -mov dword ptr [0x558b38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606200) /* 0x558b38 */) = cpu.ecx;
    // 00445777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00445779  0f8434030000           -je 0x445ab3
    if (cpu.flags.zf)
    {
        goto L_0x00445ab3;
    }
    // 0044577f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00445781  0f842c030000           -je 0x445ab3
    if (cpu.flags.zf)
    {
        goto L_0x00445ab3;
    }
    // 00445787  837de800               +cmp dword ptr [ebp - 0x18], 0
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
    // 0044578b  0f8422030000           -je 0x445ab3
    if (cpu.flags.zf)
    {
        goto L_0x00445ab3;
    }
    // 00445791  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00445793  0f841a030000           -je 0x445ab3
    if (cpu.flags.zf)
    {
        goto L_0x00445ab3;
    }
    // 00445799  837d1000               +cmp dword ptr [ebp + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044579d  0f8410030000           -je 0x445ab3
    if (cpu.flags.zf)
    {
        goto L_0x00445ab3;
    }
    // 004457a3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004457a5  0f8408030000           -je 0x445ab3
    if (cpu.flags.zf)
    {
        goto L_0x00445ab3;
    }
    // 004457ab  837d1c00               +cmp dword ptr [ebp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004457af  0f84fe020000           -je 0x445ab3
    if (cpu.flags.zf)
    {
        goto L_0x00445ab3;
    }
    // 004457b5  83fb0a                 +cmp ebx, 0xa
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
    // 004457b8  0f8df5020000           -jge 0x445ab3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445ab3;
    }
    // 004457be  837de806               +cmp dword ptr [ebp - 0x18], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004457c2  0f8deb020000           -jge 0x445ab3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445ab3;
    }
    // 004457c8  a31c8b5500             -mov dword ptr [0x558b1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */) = cpu.eax;
    // 004457cd  c705148b550004000000   -mov dword ptr [0x558b14], 4
    app->getMemory<x86::reg32>(x86::reg32(5606164) /* 0x558b14 */) = 4 /*0x4*/;
    // 004457d7  c605108b550001         -mov byte ptr [0x558b10], 1
    app->getMemory<x86::reg8>(x86::reg32(5606160) /* 0x558b10 */) = 1 /*0x1*/;
    // 004457de  8a45e8                 -mov al, byte ptr [ebp - 0x18]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004457e1  a2648c5500             -mov byte ptr [0x558c64], al
    app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */) = cpu.al;
    // 004457e6  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004457e9  8915208b5500           -mov dword ptr [0x558b20], edx
    app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */) = cpu.edx;
    // 004457ef  a36c8c5500             -mov dword ptr [0x558c6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606508) /* 0x558c6c */) = cpu.eax;
    // 004457f4  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004457f7  8935688c5500           -mov dword ptr [0x558c68], esi
    app->getMemory<x86::reg32>(x86::reg32(5606504) /* 0x558c68 */) = cpu.esi;
    // 004457fd  a3708c5500             -mov dword ptr [0x558c70], eax
    app->getMemory<x86::reg32>(x86::reg32(5606512) /* 0x558c70 */) = cpu.eax;
    // 00445802  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 00445805  891d308b5500           -mov dword ptr [0x558b30], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */) = cpu.ebx;
    // 0044580b  a3388b5500             -mov dword ptr [0x558b38], eax
    app->getMemory<x86::reg32>(x86::reg32(5606200) /* 0x558b38 */) = cpu.eax;
    // 00445810  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00445813  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00445818  a3348b5500             -mov dword ptr [0x558b34], eax
    app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */) = cpu.eax;
    // 0044581d  8b4524                 -mov eax, dword ptr [ebp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 00445820  8915608c5500           -mov dword ptr [0x558c60], edx
    app->getMemory<x86::reg32>(x86::reg32(5606496) /* 0x558c60 */) = cpu.edx;
    // 00445826  a33c8b5500             -mov dword ptr [0x558b3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.eax;
    // 0044582b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044582d  7d0a                   -jge 0x445839
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445839;
    }
    // 0044582f  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00445831  891d3c8b5500           -mov dword ptr [0x558b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.ebx;
    // 00445837  eb0f                   -jmp 0x445848
    goto L_0x00445848;
L_0x00445839:
    // 00445839  8b5524                 -mov edx, dword ptr [ebp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    // 0044583c  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0044583f  39d0                   +cmp eax, edx
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
    // 00445841  7d05                   -jge 0x445848
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445848;
    }
    // 00445843  a33c8b5500             -mov dword ptr [0x558b3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */) = cpu.eax;
L_0x00445848:
    // 00445848  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044584a  7432                   -je 0x44587e
    if (cpu.flags.zf)
    {
        goto L_0x0044587e;
    }
    // 0044584c  8d4598                 -lea eax, [ebp - 0x68]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-104) /* -0x68 */);
    // 0044584f  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 00445855  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00445857  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00445858  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044585a  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 0044585f  e82ce2ffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 00445864  8d45a8                 -lea eax, [ebp - 0x58]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 00445867  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 0044586d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044586f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00445870  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00445872  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 00445877  e814e2ffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 0044587c  eb2e                   -jmp 0x4458ac
    goto L_0x004458ac;
L_0x0044587e:
    // 0044587e  8d4598                 -lea eax, [ebp - 0x68]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-104) /* -0x68 */);
    // 00445881  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00445886  8b15208b5500           -mov edx, dword ptr [0x558b20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606176) /* 0x558b20 */);
    // 0044588c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044588d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044588f  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 00445894  e8f7e1ffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 00445899  8d5da8                 -lea ebx, [ebp - 0x58]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-88) /* -0x58 */);
    // 0044589c  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 004458a2  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 004458a7  e854e3ffff             -call 0x443c00
    cpu.esp -= 4;
    sub_443c00(app, cpu);
    if (cpu.terminate) return;
L_0x004458ac:
    // 004458ac  8d45b8                 -lea eax, [ebp - 0x48]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-72) /* -0x48 */);
    // 004458af  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004458b1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004458b3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004458b4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004458b6  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004458b9  e8d2e1ffff             -call 0x443a90
    cpu.esp -= 4;
    sub_443a90(app, cpu);
    if (cpu.terminate) return;
    // 004458be  d945a4                 -fld dword ptr [ebp - 0x5c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-92) /* -0x5c */)));
    // 004458c1  d945a0                 -fld dword ptr [ebp - 0x60]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-96) /* -0x60 */)));
    // 004458c4  d9459c                 -fld dword ptr [ebp - 0x64]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-100) /* -0x64 */)));
    // 004458c7  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004458c9  d8659c                 -fsub dword ptr [ebp - 0x64]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-100) /* -0x64 */));
    // 004458cc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004458ce  d86598                 -fsub dword ptr [ebp - 0x68]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-104) /* -0x68 */));
    // 004458d1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004458d3  d955f4                 -fst dword ptr [ebp - 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */) = float(cpu.fpu.st(0));
    // 004458d6  dd05608b5300           -fld qword ptr [0x538b60]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5475168) /* 0x538b60 */)));
    // 004458dc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004458de  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004458e0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004458e2  d955e0                 -fst dword ptr [ebp - 0x20]
    app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = float(cpu.fpu.st(0));
    // 004458e5  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004458e7  d945c4                 -fld dword ptr [ebp - 0x3c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-60) /* -0x3c */)));
    // 004458ea  d945b4                 -fld dword ptr [ebp - 0x4c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-76) /* -0x4c */)));
    // 004458ed  d945b0                 -fld dword ptr [ebp - 0x50]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-80) /* -0x50 */)));
    // 004458f0  8b55e8                 -mov edx, dword ptr [ebp - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004458f3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004458f5  d865bc                 -fsub dword ptr [ebp - 0x44]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-68) /* -0x44 */));
    // 004458f8  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004458ff  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00445901  d865ac                 -fsub dword ptr [ebp - 0x54]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-84) /* -0x54 */));
    // 00445904  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00445906  d865a8                 -fsub dword ptr [ebp - 0x58]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-88) /* -0x58 */));
    // 00445909  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0044590b  d95dec                 -fstp dword ptr [ebp - 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044590e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00445910  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00445912  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00445915  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00445917  d95dd0                 -fstp dword ptr [ebp - 0x30]
    app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044591a  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0044591d  d94598                 -fld dword ptr [ebp - 0x68]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-104) /* -0x68 */)));
    // 00445920  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00445923  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00445925  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00445927  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 0044592a  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 0044592c  d95df0                 -fstp dword ptr [ebp - 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044592f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00445931  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00445933  d95dd8                 -fstp dword ptr [ebp - 0x28]
    app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00445936  d95dd4                 -fstp dword ptr [ebp - 0x2c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00445939  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044593b  744b                   -je 0x445988
    if (cpu.flags.zf)
    {
        goto L_0x00445988;
    }
    // 0044593d  d945e0                 +fld dword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 00445940  d845d0                 +fadd dword ptr [ebp - 0x30]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-48) /* -0x30 */));
    // 00445943  d845d8                 +fadd dword ptr [ebp - 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */));
    // 00445946  d805688b5300           +fadd dword ptr [0x538b68]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475176) /* 0x538b68 */));
    // 0044594c  d945e4                 +fld dword ptr [ebp - 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 0044594f  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00445951  d95ddc                 +fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00445954  d85df4                 +fcomp dword ptr [ebp - 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    cpu.fpu.pop();
    // 00445957  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 00445959  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 0044595a  7605                   -jbe 0x445961
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00445961;
    }
    // 0044595c  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 0044595f  eb03                   -jmp 0x445964
    goto L_0x00445964;
L_0x00445961:
    // 00445961  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x00445964:
    // 00445964  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00445967  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0044596a  d85dec                 +fcomp dword ptr [ebp - 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    cpu.fpu.pop();
    // 0044596d  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 0044596f  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 00445970  7306                   -jae 0x445978
    if (!cpu.flags.cf)
    {
        goto L_0x00445978;
    }
    // 00445972  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00445975  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x00445978:
    // 00445978  d945f0                 +fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 0044597b  e8d6a30900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00445980  db1d408b5500           +fistp dword ptr [0x558b40]
    app->getMemory<x86::reg32>(x86::reg32(5606208) /* 0x558b40 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00445986  eb4c                   -jmp 0x4459d4
    goto L_0x004459d4;
L_0x00445988:
    // 00445988  d945e4                 +fld dword ptr [ebp - 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */)));
    // 0044598b  d9c0                   +fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0044598d  dc05708b5300           +fadd qword ptr [0x538b70]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5475184) /* 0x538b70 */));
    // 00445993  dc0d608b5300           +fmul qword ptr [0x538b60]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5475168) /* 0x538b60 */));
    // 00445999  d86df0                 +fsubr dword ptr [ebp - 0x10]
    cpu.fpu.st(0) = app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */) - cpu.fpu.st(0);
    // 0044599c  e8b5a30900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 004459a1  db1d408b5500           +fistp dword ptr [0x558b40]
    app->getMemory<x86::reg32>(x86::reg32(5606208) /* 0x558b40 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004459a7  d85df4                 +fcomp dword ptr [ebp - 0xc]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-12) /* -0xc */)));
    cpu.fpu.pop();
    // 004459aa  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004459ac  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004459ad  7605                   -jbe 0x4459b4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004459b4;
    }
    // 004459af  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004459b2  eb03                   -jmp 0x4459b7
    goto L_0x004459b7;
L_0x004459b4:
    // 004459b4  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x004459b7:
    // 004459b7  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004459ba  d945f8                 +fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004459bd  d85dec                 +fcomp dword ptr [ebp - 0x14]
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    cpu.fpu.pop();
    // 004459c0  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004459c2  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004459c3  7306                   -jae 0x4459cb
    if (!cpu.flags.cf)
    {
        goto L_0x004459cb;
    }
    // 004459c5  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004459c8  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
L_0x004459cb:
    // 004459cb  d945e0                 -fld dword ptr [ebp - 0x20]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 004459ce  d845d8                 -fadd dword ptr [ebp - 0x28]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-40) /* -0x28 */));
    // 004459d1  d95ddc                 -fstp dword ptr [ebp - 0x24]
    app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004459d4:
    // 004459d4  d905788b5300           -fld dword ptr [0x538b78]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5475192) /* 0x538b78 */)));
    // 004459da  d945ec                 -fld dword ptr [ebp - 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004459dd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004459df  d945dc                 -fld dword ptr [ebp - 0x24]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-36) /* -0x24 */)));
    // 004459e2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004459e4  d945f8                 -fld dword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004459e7  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004459e9  d945d4                 -fld dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    // 004459ec  d945f0                 -fld dword ptr [ebp - 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004459ef  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004459f1  a11c8b5500             -mov eax, dword ptr [0x558b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606172) /* 0x558b1c */);
    // 004459f6  bb50106600             -mov ebx, 0x661050
    cpu.ebx = 6688848 /*0x661050*/;
    // 004459fb  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004459fd  b950106600             -mov ecx, 0x661050
    cpu.ecx = 6688848 /*0x661050*/;
    // 00445a02  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00445a04  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00445a06  d8e9                   -fsubr st(1)
    cpu.fpu.st(0) = cpu.fpu.st(1) - cpu.fpu.st(0);
    // 00445a08  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00445a0a  d8e3                   -fsub st(3)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(3));
    // 00445a0c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00445a0f  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 00445a11  d8e5                   -fsub st(5)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(5));
    // 00445a13  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00445a15  dec5                   -faddp st(5)
    cpu.fpu.st(5) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00445a17  d945d4                 -fld dword ptr [ebp - 0x2c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-44) /* -0x2c */)));
    // 00445a1a  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00445a1c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 00445a1e  d95dcc                 -fstp dword ptr [ebp - 0x34]
    app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00445a21  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00445a23  d91d54106600           -fstp dword ptr [0x661054]
    app->getMemory<float>(x86::reg32(6688852) /* 0x661054 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00445a29  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 00445a2b  d91d5c106600           -fstp dword ptr [0x66105c]
    app->getMemory<float>(x86::reg32(6688860) /* 0x66105c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00445a31  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00445a33  d91d58106600           -fstp dword ptr [0x661058]
    app->getMemory<float>(x86::reg32(6688856) /* 0x661058 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00445a39  d8057c8b5300           -fadd dword ptr [0x538b7c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475196) /* 0x538b7c */));
    // 00445a3f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00445a41  e810a30900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00445a46  8b15688c5500           -mov edx, dword ptr [0x558c68]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606504) /* 0x558c68 */);
    // 00445a4c  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00445a4f  db1d748c5500           -fistp dword ptr [0x558c74]
    app->getMemory<x86::reg32>(x86::reg32(5606516) /* 0x558c74 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00445a55  db45fc                 -fild dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */))));
    // 00445a58  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 00445a5b  d945cc                 -fld dword ptr [ebp - 0x34]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-52) /* -0x34 */)));
    // 00445a5e  a350106600             -mov dword ptr [0x661050], eax
    app->getMemory<x86::reg32>(x86::reg32(6688848) /* 0x661050 */) = cpu.eax;
    // 00445a63  d805808b5300           -fadd dword ptr [0x538b80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5475200) /* 0x538b80 */));
    // 00445a69  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00445a6b  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 00445a6d  a0648c5500             -mov al, byte ptr [0x558c64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5606500) /* 0x558c64 */);
    // 00445a72  e8dfa20900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00445a77  db1d788c5500           -fistp dword ptr [0x558c78]
    app->getMemory<x86::reg32>(x86::reg32(5606520) /* 0x558c78 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00445a7d  e84ef8ffff             -call 0x4452d0
    cpu.esp -= 4;
    sub_4452d0(app, cpu);
    if (cpu.terminate) return;
    // 00445a82  8b15348b5500           -mov edx, dword ptr [0x558b34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606196) /* 0x558b34 */);
    // 00445a88  a1308b5500             -mov eax, dword ptr [0x558b30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606192) /* 0x558b30 */);
    // 00445a8d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00445a8f  e88ce2ffff             -call 0x443d20
    cpu.esp -= 4;
    sub_443d20(app, cpu);
    if (cpu.terminate) return;
    // 00445a94  8b5d2c                 -mov ebx, dword ptr [ebp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(44) /* 0x2c */);
    // 00445a97  a13c8b5500             -mov eax, dword ptr [0x558b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606204) /* 0x558b3c */);
    // 00445a9c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00445a9e  e8cdeaffff             -call 0x444570
    cpu.esp -= 4;
    sub_444570(app, cpu);
    if (cpu.terminate) return;
    // 00445aa3  890d188b5500           -mov dword ptr [0x558b18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.ecx;
    // 00445aa9  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00445aab  7406                   -je 0x445ab3
    if (cpu.flags.zf)
    {
        goto L_0x00445ab3;
    }
    // 00445aad  891d188b5500           -mov dword ptr [0x558b18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.ebx;
L_0x00445ab3:
    // 00445ab3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00445ab5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445ab6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445ab7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445ab8  c22000                 -ret 0x20
    cpu.esp += 4+32 /*0x20*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_445ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00445ac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00445ac2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445ac3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445ac4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00445ac5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445ac6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445ac8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00445acb  833d388b550000         +cmp dword ptr [0x558b38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606200) /* 0x558b38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445ad2  750d                   -jne 0x445ae1
    if (!cpu.flags.zf)
    {
        goto L_0x00445ae1;
    }
    // 00445ad4  833d708c550000         +cmp dword ptr [0x558c70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606512) /* 0x558c70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445adb  0f84ec020000           -je 0x445dcd
    if (cpu.flags.zf)
    {
        goto L_0x00445dcd;
    }
L_0x00445ae1:
    // 00445ae1  e8eaeaffff             -call 0x4445d0
    cpu.esp -= 4;
    sub_4445d0(app, cpu);
    if (cpu.terminate) return;
    // 00445ae6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00445ae8  83f8ff                 +cmp eax, -1
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
    // 00445aeb  751f                   -jne 0x445b0c
    if (!cpu.flags.zf)
    {
        goto L_0x00445b0c;
    }
    // 00445aed  e8def6ffff             -call 0x4451d0
    cpu.esp -= 4;
    sub_4451d0(app, cpu);
    if (cpu.terminate) return;
    // 00445af2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00445af4  83f8ff                 +cmp eax, -1
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
    // 00445af7  740c                   -je 0x445b05
    if (cpu.flags.zf)
    {
        goto L_0x00445b05;
    }
    // 00445af9  c705fc8a550001000000   -mov dword ptr [0x558afc], 1
    app->getMemory<x86::reg32>(x86::reg32(5606140) /* 0x558afc */) = 1 /*0x1*/;
    // 00445b03  eb0f                   -jmp 0x445b14
    goto L_0x00445b14;
L_0x00445b05:
    // 00445b05  a3fc8a5500             -mov dword ptr [0x558afc], eax
    app->getMemory<x86::reg32>(x86::reg32(5606140) /* 0x558afc */) = cpu.eax;
    // 00445b0a  eb08                   -jmp 0x445b14
    goto L_0x00445b14;
L_0x00445b0c:
    // 00445b0c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00445b0e  893dfc8a5500           -mov dword ptr [0x558afc], edi
    app->getMemory<x86::reg32>(x86::reg32(5606140) /* 0x558afc */) = cpu.edi;
L_0x00445b14:
    // 00445b14  83faff                 +cmp edx, -1
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
    // 00445b17  7411                   -je 0x445b2a
    if (cpu.flags.zf)
    {
        goto L_0x00445b2a;
    }
    // 00445b19  3b15088b5500           +cmp edx, dword ptr [0x558b08]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5606152) /* 0x558b08 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445b1f  7509                   -jne 0x445b2a
    if (!cpu.flags.zf)
    {
        goto L_0x00445b2a;
    }
    // 00445b21  833dfc8a5500ff         +cmp dword ptr [0x558afc], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606140) /* 0x558afc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445b28  750a                   -jne 0x445b34
    if (!cpu.flags.zf)
    {
        goto L_0x00445b34;
    }
L_0x00445b2a:
    // 00445b2a  c705088b5500ffffffff   -mov dword ptr [0x558b08], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5606152) /* 0x558b08 */) = 4294967295 /*0xffffffff*/;
L_0x00445b34:
    // 00445b34  be6666663f             -mov esi, 0x3f666666
    cpu.esi = 1063675494 /*0x3f666666*/;
    // 00445b39  8b3d088b5500           -mov edi, dword ptr [0x558b08]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5606152) /* 0x558b08 */);
    // 00445b3f  893550945500           -mov dword ptr [0x559450], esi
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = cpu.esi;
    // 00445b45  83ffff                 +cmp edi, -1
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
    // 00445b48  0f852f010000           -jne 0x445c7d
    if (!cpu.flags.zf)
    {
        goto L_0x00445c7d;
    }
    // 00445b4e  8b0d008b5500           -mov ecx, dword ptr [0x558b00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606144) /* 0x558b00 */);
    // 00445b54  3b0de4e55500           +cmp ecx, dword ptr [0x55e5e4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445b5a  750e                   -jne 0x445b6a
    if (!cpu.flags.zf)
    {
        goto L_0x00445b6a;
    }
    // 00445b5c  8b1d048b5500           -mov ebx, dword ptr [0x558b04]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5606148) /* 0x558b04 */);
    // 00445b62  3b1de8e55500           +cmp ebx, dword ptr [0x55e5e8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445b68  7426                   -je 0x445b90
    if (cpu.flags.zf)
    {
        goto L_0x00445b90;
    }
L_0x00445b6a:
    // 00445b6a  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00445b6f  a3008b5500             -mov dword ptr [0x558b00], eax
    app->getMemory<x86::reg32>(x86::reg32(5606144) /* 0x558b00 */) = cpu.eax;
    // 00445b74  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00445b79  a3048b5500             -mov dword ptr [0x558b04], eax
    app->getMemory<x86::reg32>(x86::reg32(5606148) /* 0x558b04 */) = cpu.eax;
    // 00445b7e  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00445b83  83c064                 +add eax, 0x64
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00445b86  a384106600             -mov dword ptr [0x661084], eax
    app->getMemory<x86::reg32>(x86::reg32(6688900) /* 0x661084 */) = cpu.eax;
    // 00445b8b  e9ed000000             -jmp 0x445c7d
    goto L_0x00445c7d;
L_0x00445b90:
    // 00445b90  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00445b95  3b0584106600           +cmp eax, dword ptr [0x661084]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6688900) /* 0x661084 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445b9b  0f8edc000000           -jle 0x445c7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00445c7d;
    }
    // 00445ba1  39fa                   +cmp edx, edi
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
    // 00445ba3  0f84d4000000           -je 0x445c7d
    if (cpu.flags.zf)
    {
        goto L_0x00445c7d;
    }
    // 00445ba9  8915088b5500           -mov dword ptr [0x558b08], edx
    app->getMemory<x86::reg32>(x86::reg32(5606152) /* 0x558b08 */) = cpu.edx;
    // 00445baf  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00445bb6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00445bb8  8b15fc8a5500           -mov edx, dword ptr [0x558afc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606140) /* 0x558afc */);
    // 00445bbe  893d88106600           -mov dword ptr [0x661088], edi
    app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */) = cpu.edi;
    // 00445bc4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00445bc6  751c                   -jne 0x445be4
    if (!cpu.flags.zf)
    {
        goto L_0x00445be4;
    }
    // 00445bc8  8b1d388b5500           -mov ebx, dword ptr [0x558b38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5606200) /* 0x558b38 */);
    // 00445bce  893d0c8b5500           -mov dword ptr [0x558b0c], edi
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.edi;
    // 00445bd4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00445bd6  7429                   -je 0x445c01
    if (cpu.flags.zf)
    {
        goto L_0x00445c01;
    }
    // 00445bd8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00445bda  8b0402                 -mov eax, dword ptr [edx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 00445bdd  a30c8b5500             -mov dword ptr [0x558b0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.eax;
    // 00445be2  eb1d                   -jmp 0x445c01
    goto L_0x00445c01;
L_0x00445be4:
    // 00445be4  83fa01                 +cmp edx, 1
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
    // 00445be7  7518                   -jne 0x445c01
    if (!cpu.flags.zf)
    {
        goto L_0x00445c01;
    }
    // 00445be9  8b15708c5500           -mov edx, dword ptr [0x558c70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5606512) /* 0x558c70 */);
    // 00445bef  893d0c8b5500           -mov dword ptr [0x558b0c], edi
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.edi;
    // 00445bf5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00445bf7  7408                   -je 0x445c01
    if (cpu.flags.zf)
    {
        goto L_0x00445c01;
    }
    // 00445bf9  8b0402                 -mov eax, dword ptr [edx + eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 00445bfc  a30c8b5500             -mov dword ptr [0x558b0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.eax;
L_0x00445c01:
    // 00445c01  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00445c03  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00445c06  8d4df8                 -lea ecx, [ebp - 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00445c09  bb4a010000             -mov ebx, 0x14a
    cpu.ebx = 330 /*0x14a*/;
    // 00445c0e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00445c0f  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00445c14  a10c8b5500             -mov eax, dword ptr [0x558b0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */);
    // 00445c19  e8d2c30000             -call 0x451ff0
    cpu.esp -= 4;
    sub_451ff0(app, cpu);
    if (cpu.terminate) return;
    // 00445c1e  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00445c21  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00445c24  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00445c2a  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00445c2d  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00445c30  890d7c106600           -mov dword ptr [0x66107c], ecx
    app->getMemory<x86::reg32>(x86::reg32(6688892) /* 0x66107c */) = cpu.ecx;
    // 00445c36  a380106600             -mov dword ptr [0x661080], eax
    app->getMemory<x86::reg32>(x86::reg32(6688896) /* 0x661080 */) = cpu.eax;
    // 00445c3b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00445c3d  891574106600           -mov dword ptr [0x661074], edx
    app->getMemory<x86::reg32>(x86::reg32(6688884) /* 0x661074 */) = cpu.edx;
    // 00445c43  81f976020000           +cmp ecx, 0x276
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(630 /*0x276*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445c49  7e0d                   -jle 0x445c58
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00445c58;
    }
    // 00445c4b  b976020000             -mov ecx, 0x276
    cpu.ecx = 630 /*0x276*/;
    // 00445c50  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00445c52  890d7c106600           -mov dword ptr [0x66107c], ecx
    app->getMemory<x86::reg32>(x86::reg32(6688892) /* 0x66107c */) = cpu.ecx;
L_0x00445c58:
    // 00445c58  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00445c5d  83c016                 -add eax, 0x16
    (cpu.eax) += x86::reg32(x86::sreg32(22 /*0x16*/));
    // 00445c60  a378106600             -mov dword ptr [0x661078], eax
    app->getMemory<x86::reg32>(x86::reg32(6688888) /* 0x661078 */) = cpu.eax;
    // 00445c65  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00445c67  3dcc010000             +cmp eax, 0x1cc
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(460 /*0x1cc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445c6c  7e0f                   -jle 0x445c7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00445c7d;
    }
    // 00445c6e  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00445c73  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00445c75  83e808                 -sub eax, 8
    (cpu.eax) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00445c78  a378106600             -mov dword ptr [0x661078], eax
    app->getMemory<x86::reg32>(x86::reg32(6688888) /* 0x661078 */) = cpu.eax;
L_0x00445c7d:
    // 00445c7d  833d0c8b550000         +cmp dword ptr [0x558b0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445c84  745c                   -je 0x445ce2
    if (cpu.flags.zf)
    {
        goto L_0x00445ce2;
    }
    // 00445c86  833d088b5500ff         +cmp dword ptr [0x558b08], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606152) /* 0x558b08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445c8d  7526                   -jne 0x445cb5
    if (!cpu.flags.zf)
    {
        goto L_0x00445cb5;
    }
    // 00445c8f  8b3588106600           -mov esi, dword ptr [0x661088]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */);
    // 00445c95  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00445c97  7e09                   -jle 0x445ca2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00445ca2;
    }
    // 00445c99  8d7ef1                 -lea edi, [esi - 0xf]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-15) /* -0xf */);
    // 00445c9c  893d88106600           -mov dword ptr [0x661088], edi
    app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */) = cpu.edi;
L_0x00445ca2:
    // 00445ca2  833d8810660000         +cmp dword ptr [0x661088], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445ca9  7f37                   -jg 0x445ce2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00445ce2;
    }
    // 00445cab  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00445cad  89150c8b5500           -mov dword ptr [0x558b0c], edx
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.edx;
    // 00445cb3  eb2d                   -jmp 0x445ce2
    goto L_0x00445ce2;
L_0x00445cb5:
    // 00445cb5  8b0d88106600           -mov ecx, dword ptr [0x661088]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */);
    // 00445cbb  81f9ff000000           +cmp ecx, 0xff
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
    // 00445cc1  7d09                   -jge 0x445ccc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445ccc;
    }
    // 00445cc3  8d590a                 -lea ebx, [ecx + 0xa]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(10) /* 0xa */);
    // 00445cc6  891d88106600           -mov dword ptr [0x661088], ebx
    app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */) = cpu.ebx;
L_0x00445ccc:
    // 00445ccc  813d88106600ff000000   +cmp dword ptr [0x661088], 0xff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445cd6  7e0a                   -jle 0x445ce2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00445ce2;
    }
    // 00445cd8  c70588106600ff000000   -mov dword ptr [0x661088], 0xff
    app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */) = 255 /*0xff*/;
L_0x00445ce2:
    // 00445ce2  833d0c8b550000         +cmp dword ptr [0x558b0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445ce9  0f84d4000000           -je 0x445dc3
    if (cpu.flags.zf)
    {
        goto L_0x00445dc3;
    }
    // 00445cef  a188106600             -mov eax, dword ptr [0x661088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */);
    // 00445cf4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00445cf6  a3a43a5600             -mov dword ptr [0x563aa4], eax
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = cpu.eax;
    // 00445cfb  c1e218                 -shl edx, 0x18
    cpu.edx <<= 24 /*0x18*/ % 32;
    // 00445cfe  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00445d01  8915a43a5600           -mov dword ptr [0x563aa4], edx
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = cpu.edx;
    // 00445d07  8d90ad6c4b00           -lea edx, [eax + 0x4b6cad]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(4943021) /* 0x4b6cad */);
    // 00445d0d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445d0e  059cffff00             -add eax, 0xffff9c
    (cpu.eax) += x86::reg32(x86::sreg32(16777116 /*0xffff9c*/));
    // 00445d13  8b0d74106600           -mov ecx, dword ptr [0x661074]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688884) /* 0x661074 */);
    // 00445d19  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00445d1a  a178106600             -mov eax, dword ptr [0x661078]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688888) /* 0x661078 */);
    // 00445d1f  8b1d80106600           -mov ebx, dword ptr [0x661080]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6688896) /* 0x661080 */);
    // 00445d25  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00445d27  a17c106600             -mov eax, dword ptr [0x66107c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688892) /* 0x66107c */);
    // 00445d2c  8b1578106600           -mov edx, dword ptr [0x661078]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688888) /* 0x661078 */);
    // 00445d32  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00445d34  e817280900             -call 0x4d8550
    cpu.esp -= 4;
    sub_4d8550(app, cpu);
    if (cpu.terminate) return;
    // 00445d39  a188106600             -mov eax, dword ptr [0x661088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688904) /* 0x661088 */);
    // 00445d3e  8b0d74106600           -mov ecx, dword ptr [0x661074]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688884) /* 0x661074 */);
    // 00445d44  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00445d47  8b1d80106600           -mov ebx, dword ptr [0x661080]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6688896) /* 0x661080 */);
    // 00445d4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00445d4e  8b1578106600           -mov edx, dword ptr [0x661078]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688888) /* 0x661078 */);
    // 00445d54  a17c106600             -mov eax, dword ptr [0x66107c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6688892) /* 0x66107c */);
    // 00445d59  e8d22b0900             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 00445d5e  8b3534925500           -mov esi, dword ptr [0x559234]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00445d64  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00445d66  7424                   -je 0x445d8c
    if (cpu.flags.zf)
    {
        goto L_0x00445d8c;
    }
    // 00445d68  68fd8c4800             -push 0x488cfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4754685 /*0x488cfd*/;
    cpu.esp -= 4;
    // 00445d6d  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00445d72  8b1d78106600           -mov ebx, dword ptr [0x661078]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6688888) /* 0x661078 */);
    // 00445d78  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00445d7a  8b157c106600           -mov edx, dword ptr [0x66107c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6688892) /* 0x66107c */);
    // 00445d80  a10c8b5500             -mov eax, dword ptr [0x558b0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */);
    // 00445d85  e806c40000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00445d8a  eb2d                   -jmp 0x445db9
    goto L_0x00445db9;
L_0x00445d8c:
    // 00445d8c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445d8d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445d8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445d8f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445d90  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00445d95  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00445d9a  684a010000             -push 0x14a
    app->getMemory<x86::reg32>(cpu.esp-4) = 330 /*0x14a*/;
    cpu.esp -= 4;
    // 00445d9f  8b3d78106600           -mov edi, dword ptr [0x661078]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6688888) /* 0x661078 */);
    // 00445da5  8b0d7c106600           -mov ecx, dword ptr [0x66107c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688892) /* 0x66107c */);
    // 00445dab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00445dac  a10c8b5500             -mov eax, dword ptr [0x558b0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */);
    // 00445db1  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00445db4  e807c20000             -call 0x451fc0
    cpu.esp -= 4;
    sub_451fc0(app, cpu);
    if (cpu.terminate) return;
L_0x00445db9:
    // 00445db9  c705a43a5600000000ff   -mov dword ptr [0x563aa4], 0xff000000
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = 4278190080 /*0xff000000*/;
L_0x00445dc3:
    // 00445dc3  c705509455000000803f   -mov dword ptr [0x559450], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = 1065353216 /*0x3f800000*/;
L_0x00445dcd:
    // 00445dcd  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00445dcf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445dd0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445dd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445dd2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445dd3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445dd4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445dd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_445de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445de0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445de1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445de3  b8848b5300             -mov eax, 0x538b84
    cpu.eax = 5475204 /*0x538b84*/;
    // 00445de8  e8c3ff0800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00445ded  a38c106600             -mov dword ptr [0x66108c], eax
    app->getMemory<x86::reg32>(x86::reg32(6688908) /* 0x66108c */) = cpu.eax;
    // 00445df2  b88c8b5300             -mov eax, 0x538b8c
    cpu.eax = 5475212 /*0x538b8c*/;
    // 00445df7  e8b4ff0800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00445dfc  a368106600             -mov dword ptr [0x661068], eax
    app->getMemory<x86::reg32>(x86::reg32(6688872) /* 0x661068 */) = cpu.eax;
    // 00445e01  b8948b5300             -mov eax, 0x538b94
    cpu.eax = 5475220 /*0x538b94*/;
    // 00445e06  e8a5ff0800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00445e0b  a360106600             -mov dword ptr [0x661060], eax
    app->getMemory<x86::reg32>(x86::reg32(6688864) /* 0x661060 */) = cpu.eax;
    // 00445e10  b89c8b5300             -mov eax, 0x538b9c
    cpu.eax = 5475228 /*0x538b9c*/;
    // 00445e15  e896ff0800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00445e1a  a3248b5500             -mov dword ptr [0x558b24], eax
    app->getMemory<x86::reg32>(x86::reg32(5606180) /* 0x558b24 */) = cpu.eax;
    // 00445e1f  b8a48b5300             -mov eax, 0x538ba4
    cpu.eax = 5475236 /*0x538ba4*/;
    // 00445e24  e887ff0800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00445e29  a3288b5500             -mov dword ptr [0x558b28], eax
    app->getMemory<x86::reg32>(x86::reg32(5606184) /* 0x558b28 */) = cpu.eax;
    // 00445e2e  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00445e35  750f                   -jne 0x445e46
    if (!cpu.flags.zf)
    {
        goto L_0x00445e46;
    }
    // 00445e37  b8ac8b5300             -mov eax, 0x538bac
    cpu.eax = 5475244 /*0x538bac*/;
    // 00445e3c  e86fff0800             -call 0x4d5db0
    cpu.esp -= 4;
    sub_4d5db0(app, cpu);
    if (cpu.terminate) return;
    // 00445e41  a36c106600             -mov dword ptr [0x66106c], eax
    app->getMemory<x86::reg32>(x86::reg32(6688876) /* 0x66106c */) = cpu.eax;
L_0x00445e46:
    // 00445e46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445e47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_445e60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00445e60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00445e61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00445e62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445e63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445e64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445e66  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00445e69  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00445e6b  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 00445e6d  8b1d34925500           -mov ebx, dword ptr [0x559234]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00445e73  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00445e75  8865fc                 -mov byte ptr [ebp - 4], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ah;
    // 00445e78  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00445e7a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00445e7c  7510                   -jne 0x445e8e
    if (!cpu.flags.zf)
    {
        goto L_0x00445e8e;
    }
    // 00445e7e  813d64106600ff000000   +cmp dword ptr [0x661064], 0xff
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445e88  0f8c65000000           -jl 0x445ef3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00445ef3;
    }
L_0x00445e8e:
    // 00445e8e  8b1d148b5500           -mov ebx, dword ptr [0x558b14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5606164) /* 0x558b14 */);
    // 00445e94  4b                     -dec ebx
    (cpu.ebx)--;
    // 00445e95  83fb03                 +cmp ebx, 3
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
    // 00445e98  772d                   -ja 0x445ec7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00445ec7;
    }
    // 00445e9a  ff249d485e4400         -jmp dword ptr [ebx*4 + 0x445e48]
    cpu.ip = app->getMemory<x86::reg32>(4480584 + cpu.ebx * 4); goto dynamic_jump;
  case 0x00445ea1:
    // 00445ea1  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00445ea4  e867eaffff             -call 0x444910
    cpu.esp -= 4;
    sub_444910(app, cpu);
    if (cpu.terminate) return;
    // 00445ea9  eb1c                   -jmp 0x445ec7
    goto L_0x00445ec7;
  case 0x00445eab:
    // 00445eab  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00445eae  e86decffff             -call 0x444b20
    cpu.esp -= 4;
    sub_444b20(app, cpu);
    if (cpu.terminate) return;
    // 00445eb3  eb12                   -jmp 0x445ec7
    goto L_0x00445ec7;
  case 0x00445eb5:
    // 00445eb5  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00445eb8  e893f0ffff             -call 0x444f50
    cpu.esp -= 4;
    sub_444f50(app, cpu);
    if (cpu.terminate) return;
    // 00445ebd  eb08                   -jmp 0x445ec7
    goto L_0x00445ec7;
  case 0x00445ebf:
    // 00445ebf  0fbfc2                 -movsx eax, dx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 00445ec2  e859f6ffff             -call 0x445520
    cpu.esp -= 4;
    sub_445520(app, cpu);
    if (cpu.terminate) return;
L_0x00445ec7:
    // 00445ec7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00445ec9  741f                   -je 0x445eea
    if (cpu.flags.zf)
    {
        goto L_0x00445eea;
    }
    // 00445ecb  833d188b550000         +cmp dword ptr [0x558b18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445ed2  740b                   -je 0x445edf
    if (cpu.flags.zf)
    {
        goto L_0x00445edf;
    }
    // 00445ed4  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00445ed7  ff15188b5500           -call dword ptr [0x558b18]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00445edd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00445edf:
    // 00445edf  807dfc00               +cmp byte ptr [ebp - 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00445ee3  7405                   -je 0x445eea
    if (cpu.flags.zf)
    {
        goto L_0x00445eea;
    }
    // 00445ee5  e826000000             -call 0x445f10
    cpu.esp -= 4;
    sub_445f10(app, cpu);
    if (cpu.terminate) return;
L_0x00445eea:
    // 00445eea  83f902                 +cmp ecx, 2
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
    // 00445eed  7502                   -jne 0x445ef1
    if (!cpu.flags.zf)
    {
        goto L_0x00445ef1;
    }
    // 00445eef  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00445ef1:
    // 00445ef1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x00445ef3:
    // 00445ef3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00445ef5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445ef6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445ef7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445ef8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445ef9  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_445f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445f00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445f01  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445f03  c70564106600ff000000   -mov dword ptr [0x661064], 0xff
    app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */) = 255 /*0xff*/;
    // 00445f0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445f0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_445f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00445f10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445f11  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445f12  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445f14  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00445f16  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00445f18  8915188b5500           -mov dword ptr [0x558b18], edx
    app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */) = cpu.edx;
    // 00445f1e  8825108b5500           -mov byte ptr [0x558b10], ah
    app->getMemory<x86::reg8>(x86::reg32(5606160) /* 0x558b10 */) = cpu.ah;
    // 00445f24  8915148b5500           -mov dword ptr [0x558b14], edx
    app->getMemory<x86::reg32>(x86::reg32(5606164) /* 0x558b14 */) = cpu.edx;
    // 00445f2a  89150c8b5500           -mov dword ptr [0x558b0c], edx
    app->getMemory<x86::reg32>(x86::reg32(5606156) /* 0x558b0c */) = cpu.edx;
    // 00445f30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445f31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00445f32  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_445f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00445f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00445f51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00445f52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00445f53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00445f54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00445f55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00445f56  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00445f58  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00445f5b  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 00445f5d  bb00ff7f3f             -mov ebx, 0x3f7fff00
    cpu.ebx = 1065352960 /*0x3f7fff00*/;
    // 00445f62  8b3564106600           -mov esi, dword ptr [0x661064]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 00445f68  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00445f6a  8865fc                 -mov byte ptr [ebp - 4], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ah;
    // 00445f6d  8915a83a5600           -mov dword ptr [0x563aa8], edx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.edx;
    // 00445f73  891dac3a5600           -mov dword ptr [0x563aac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.ebx;
    // 00445f79  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00445f7b  81feff000000           +cmp esi, 0xff
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445f81  7d2a                   -jge 0x445fad
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00445fad;
    }
    // 00445f83  8d7e14                 -lea edi, [esi + 0x14]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00445f86  893d64106600           -mov dword ptr [0x661064], edi
    app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */) = cpu.edi;
    // 00445f8c  81ffff000000           +cmp edi, 0xff
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
    // 00445f92  7e0a                   -jle 0x445f9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00445f9e;
    }
    // 00445f94  c70564106600ff000000   -mov dword ptr [0x661064], 0xff
    app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */) = 255 /*0xff*/;
L_0x00445f9e:
    // 00445f9e  8b0d64106600           -mov ecx, dword ptr [0x661064]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6688868) /* 0x661064 */);
    // 00445fa4  c1e118                 -shl ecx, 0x18
    cpu.ecx <<= 24 /*0x18*/ % 32;
    // 00445fa7  890da43a5600           -mov dword ptr [0x563aa4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = cpu.ecx;
L_0x00445fad:
    // 00445fad  8b0d148b5500           -mov ecx, dword ptr [0x558b14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5606164) /* 0x558b14 */);
    // 00445fb3  49                     -dec ecx
    (cpu.ecx)--;
    // 00445fb4  83f903                 +cmp ecx, 3
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
    // 00445fb7  7721                   -ja 0x445fda
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00445fda;
    }
    // 00445fb9  ff248d345f4400         -jmp dword ptr [ecx*4 + 0x445f34]
    cpu.ip = app->getMemory<x86::reg32>(4480820 + cpu.ecx * 4); goto dynamic_jump;
  case 0x00445fc0:
    // 00445fc0  e80beaffff             -call 0x4449d0
    cpu.esp -= 4;
    sub_4449d0(app, cpu);
    if (cpu.terminate) return;
    // 00445fc5  eb13                   -jmp 0x445fda
    goto L_0x00445fda;
  case 0x00445fc7:
    // 00445fc7  e894ebffff             -call 0x444b60
    cpu.esp -= 4;
    sub_444b60(app, cpu);
    if (cpu.terminate) return;
    // 00445fcc  eb0c                   -jmp 0x445fda
    goto L_0x00445fda;
  case 0x00445fce:
    // 00445fce  e8edf0ffff             -call 0x4450c0
    cpu.esp -= 4;
    sub_4450c0(app, cpu);
    if (cpu.terminate) return;
    // 00445fd3  eb05                   -jmp 0x445fda
    goto L_0x00445fda;
  case 0x00445fd5:
    // 00445fd5  e8a6f6ffff             -call 0x445680
    cpu.esp -= 4;
    sub_445680(app, cpu);
    if (cpu.terminate) return;
L_0x00445fda:
    // 00445fda  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00445fdc  741f                   -je 0x445ffd
    if (cpu.flags.zf)
    {
        goto L_0x00445ffd;
    }
    // 00445fde  833d188b550000         +cmp dword ptr [0x558b18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00445fe5  740b                   -je 0x445ff2
    if (cpu.flags.zf)
    {
        goto L_0x00445ff2;
    }
    // 00445fe7  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00445fea  ff15188b5500           -call dword ptr [0x558b18]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5606168) /* 0x558b18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00445ff0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00445ff2:
    // 00445ff2  807dfc00               +cmp byte ptr [ebp - 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00445ff6  7405                   -je 0x445ffd
    if (cpu.flags.zf)
    {
        goto L_0x00445ffd;
    }
    // 00445ff8  e813ffffff             -call 0x445f10
    cpu.esp -= 4;
    sub_445f10(app, cpu);
    if (cpu.terminate) return;
L_0x00445ffd:
    // 00445ffd  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00446004  750a                   -jne 0x446010
    if (!cpu.flags.zf)
    {
        goto L_0x00446010;
    }
    // 00446006  c705a43a5600000000ff   -mov dword ptr [0x563aa4], 0xff000000
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = 4278190080 /*0xff000000*/;
L_0x00446010:
    // 00446010  83fa02                 +cmp edx, 2
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
    // 00446013  7502                   -jne 0x446017
    if (!cpu.flags.zf)
    {
        goto L_0x00446017;
    }
    // 00446015  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00446017:
    // 00446017  bb00ff7f3f             -mov ebx, 0x3f7fff00
    cpu.ebx = 1065352960 /*0x3f7fff00*/;
    // 0044601c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044601e  bf80008037             -mov edi, 0x37800080
    cpu.edi = 931135616 /*0x37800080*/;
    // 00446023  890da83a5600           -mov dword ptr [0x563aa8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.ecx;
    // 00446029  891dac3a5600           -mov dword ptr [0x563aac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.ebx;
    // 0044602f  e88cfaffff             -call 0x445ac0
    cpu.esp -= 4;
    sub_445ac0(app, cpu);
    if (cpu.terminate) return;
    // 00446034  891da83a5600           -mov dword ptr [0x563aa8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.ebx;
    // 0044603a  893dac3a5600           -mov dword ptr [0x563aac], edi
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.edi;
    // 00446040  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446042  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00446044  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446045  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446046  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446047  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446048  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446049  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044604a  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_446060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00446060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446062  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446063  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00446064  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446065  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446066  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446068  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044606a  803800                 +cmp byte ptr [eax], 0
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
    // 0044606d  7521                   -jne 0x446090
    if (!cpu.flags.zf)
    {
        goto L_0x00446090;
    }
    // 0044606f  beb48b5300             -mov esi, 0x538bb4
    cpu.esi = 5475252 /*0x538bb4*/;
    // 00446074  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00446076  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00446077:
    // 00446077  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446079  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044607b  3c00                   +cmp al, 0
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
    // 0044607d  7410                   -je 0x44608f
    if (cpu.flags.zf)
    {
        goto L_0x0044608f;
    }
    // 0044607f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446082  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446085  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446088  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044608b  3c00                   +cmp al, 0
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
    // 0044608d  75e8                   -jne 0x446077
    if (!cpu.flags.zf)
    {
        goto L_0x00446077;
    }
L_0x0044608f:
    // 0044608f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00446090:
    // 00446090  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00446092  e8c9ad0900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00446097  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446099  0f841e010000           -je 0x4461bd
    if (cpu.flags.zf)
    {
        goto L_0x004461bd;
    }
    // 0044609f  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004460a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004460a6  e835af0900             -call 0x4e0fe0
    cpu.esp -= 4;
    sub_4e0fe0(app, cpu);
    if (cpu.terminate) return;
    // 004460ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004460ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004460af  0f8408010000           -je 0x4461bd
    if (cpu.flags.zf)
    {
        goto L_0x004461bd;
    }
    // 004460b5  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004460ba  8bb06c190000           -mov esi, dword ptr [eax + 0x196c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6508) /* 0x196c */);
    // 004460c0  8b8078180000           -mov eax, dword ptr [eax + 0x1878]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6264) /* 0x1878 */);
    // 004460c6  83f803                 +cmp eax, 3
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
    // 004460c9  7721                   -ja 0x4460ec
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004460ec;
    }
    // 004460cb  ff248550604400         -jmp dword ptr [eax*4 + 0x446050]
    cpu.ip = app->getMemory<x86::reg32>(4481104 + cpu.eax * 4); goto dynamic_jump;
  case 0x004460d2:
    // 004460d2  b9d5000000             -mov ecx, 0xd5
    cpu.ecx = 213 /*0xd5*/;
    // 004460d7  eb13                   -jmp 0x4460ec
    goto L_0x004460ec;
  case 0x004460d9:
    // 004460d9  b9d6000000             -mov ecx, 0xd6
    cpu.ecx = 214 /*0xd6*/;
    // 004460de  eb0c                   -jmp 0x4460ec
    goto L_0x004460ec;
  case 0x004460e0:
    // 004460e0  b9d7000000             -mov ecx, 0xd7
    cpu.ecx = 215 /*0xd7*/;
    // 004460e5  eb05                   -jmp 0x4460ec
    goto L_0x004460ec;
  case 0x004460e7:
    // 004460e7  b9dc000000             -mov ecx, 0xdc
    cpu.ecx = 220 /*0xdc*/;
L_0x004460ec:
    // 004460ec  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004460ef  0f8fc1000000           -jg 0x4461b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004461b6;
    }
    // 004460f5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004460f7  0f8cb9000000           -jl 0x4461b6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004461b6;
    }
    // 004460fd  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004460ff  0f8eb1000000           -jle 0x4461b6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004461b6;
    }
    // 00446105  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446107  e8841f0300             -call 0x478090
    cpu.esp -= 4;
    sub_478090(app, cpu);
    if (cpu.terminate) return;
    // 0044610c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044610e  0f84a2000000           -je 0x4461b6
    if (cpu.flags.zf)
    {
        goto L_0x004461b6;
    }
    // 00446114  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446116  e8e51f0300             -call 0x478100
    cpu.esp -= 4;
    sub_478100(app, cpu);
    if (cpu.terminate) return;
    // 0044611b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044611d  0f8493000000           -je 0x4461b6
    if (cpu.flags.zf)
    {
        goto L_0x004461b6;
    }
    // 00446123  8b9ab4190000           -mov ebx, dword ptr [edx + 0x19b4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6580) /* 0x19b4 */);
    // 00446129  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00446130  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00446132  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00446135  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00446137  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0044613a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0044613c  8b9c02001a0000         -mov ebx, dword ptr [edx + eax + 0x1a00]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6656) /* 0x1a00 */ + cpu.eax * 1);
    // 00446143  8d4666                 -lea eax, [esi + 0x66]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(102) /* 0x66 */);
    // 00446146  e805b70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044614b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044614c  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 00446151  680c8d5500             -push 0x558d0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606668 /*0x558d0c*/;
    cpu.esp -= 4;
    // 00446156  e835950900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0044615b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044615e  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 00446163  e8e8b60800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00446168  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446169  8bb274190000           -mov esi, dword ptr [edx + 0x1974]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6516) /* 0x1974 */);
    // 0044616f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00446170  68c48b5300             -push 0x538bc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475268 /*0x538bc4*/;
    cpu.esp -= 4;
    // 00446175  68848d5500             -push 0x558d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606788 /*0x558d84*/;
    cpu.esp -= 4;
    // 0044617a  e811950900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0044617f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00446182  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00446184  e8c7b60800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00446189  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044618a  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 0044618f  68fc8d5500             -push 0x558dfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606908 /*0x558dfc*/;
    cpu.esp -= 4;
    // 00446194  e8f7940900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446199  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044619c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044619e  e8ad30ffff             -call 0x439250
    cpu.esp -= 4;
    sub_439250(app, cpu);
    if (cpu.terminate) return;
    // 004461a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004461a4  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 004461a9  68748e5500             -push 0x558e74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5607028 /*0x558e74*/;
    cpu.esp -= 4;
    // 004461ae  e8dd940900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004461b3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004461b6:
    // 004461b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004461b8  e8d3b60900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004461bd:
    // 004461bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004461be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004461bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004461c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004461c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004461c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004461c3  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4461d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004461d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004461d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004461d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004461d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004461d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004461d5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004461d7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004461d9  e882ac0900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004461de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004461e0  0f84f1000000           -je 0x4462d7
    if (cpu.flags.zf)
    {
        goto L_0x004462d7;
    }
    // 004461e6  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004461eb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004461ed  e8eead0900             -call 0x4e0fe0
    cpu.esp -= 4;
    sub_4e0fe0(app, cpu);
    if (cpu.terminate) return;
    // 004461f2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004461f4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004461f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004461f8  0f84d9000000           -je 0x4462d7
    if (cpu.flags.zf)
    {
        goto L_0x004462d7;
    }
    // 004461fe  8b807a180000           -mov eax, dword ptr [eax + 0x187a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6266) /* 0x187a */);
    // 00446204  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00446207  8bb442bc180000         -mov esi, dword ptr [edx + eax*2 + 0x18bc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6332) /* 0x18bc */ + cpu.eax * 2);
    // 0044620e  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00446211  83fe08                 +cmp esi, 8
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00446214  0f8fb6000000           -jg 0x4462d0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004462d0;
    }
    // 0044621a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044621c  0f8cae000000           -jl 0x4462d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004462d0;
    }
    // 00446222  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446224  e8671e0300             -call 0x478090
    cpu.esp -= 4;
    sub_478090(app, cpu);
    if (cpu.terminate) return;
    // 00446229  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044622b  0f849f000000           -je 0x4462d0
    if (cpu.flags.zf)
    {
        goto L_0x004462d0;
    }
    // 00446231  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446233  e8c81e0300             -call 0x478100
    cpu.esp -= 4;
    sub_478100(app, cpu);
    if (cpu.terminate) return;
    // 00446238  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044623a  0f8490000000           -je 0x4462d0
    if (cpu.flags.zf)
    {
        goto L_0x004462d0;
    }
    // 00446240  8b9a30190000           -mov ebx, dword ptr [edx + 0x1930]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6448) /* 0x1930 */);
    // 00446246  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00446248  7507                   -jne 0x446251
    if (!cpu.flags.zf)
    {
        goto L_0x00446251;
    }
    // 0044624a  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 0044624f  eb05                   -jmp 0x446256
    goto L_0x00446256;
L_0x00446251:
    // 00446251  bb91010000             -mov ebx, 0x191
    cpu.ebx = 401 /*0x191*/;
L_0x00446256:
    // 00446256  8b91b4190000           -mov edx, dword ptr [ecx + 0x19b4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6580) /* 0x19b4 */);
    // 0044625c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00446263  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00446265  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00446268  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044626a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0044626d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044626f  8b9401001a0000         -mov edx, dword ptr [ecx + eax + 0x1a00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6656) /* 0x1a00 */ + cpu.eax * 1);
    // 00446276  b8d7000000             -mov eax, 0xd7
    cpu.eax = 215 /*0xd7*/;
    // 0044627b  e8d0b50800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00446280  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446281  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00446283  e8c8b50800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00446288  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446289  68cc8b5300             -push 0x538bcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475276 /*0x538bcc*/;
    cpu.esp -= 4;
    // 0044628e  680c8d5500             -push 0x558d0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606668 /*0x558d0c*/;
    cpu.esp -= 4;
    // 00446293  e8f8930900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446298  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0044629b  8d4666                 -lea eax, [esi + 0x66]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(102) /* 0x66 */);
    // 0044629e  e8adb50800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004462a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004462a4  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 004462a9  68848d5500             -push 0x558d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606788 /*0x558d84*/;
    cpu.esp -= 4;
    // 004462ae  e8dd930900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004462b3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004462b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004462b8  e8932fffff             -call 0x439250
    cpu.esp -= 4;
    sub_439250(app, cpu);
    if (cpu.terminate) return;
    // 004462bd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004462be  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 004462c3  68fc8d5500             -push 0x558dfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606908 /*0x558dfc*/;
    cpu.esp -= 4;
    // 004462c8  e8c3930900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004462cd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004462d0:
    // 004462d0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004462d2  e8b9b50900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004462d7:
    // 004462d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004462d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004462d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004462da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004462db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004462dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4462e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004462e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004462e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004462e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004462e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004462e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004462e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004462e7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004462e9  e872ab0900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004462ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004462f0  0f8415010000           -je 0x44640b
    if (cpu.flags.zf)
    {
        goto L_0x0044640b;
    }
    // 004462f6  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004462fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004462fd  e8deac0900             -call 0x4e0fe0
    cpu.esp -= 4;
    sub_4e0fe0(app, cpu);
    if (cpu.terminate) return;
    // 00446302  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00446304  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00446306  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446308  0f84fd000000           -je 0x44640b
    if (cpu.flags.zf)
    {
        goto L_0x0044640b;
    }
    // 0044630e  8b80ca180000           -mov eax, dword ptr [eax + 0x18ca]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6346) /* 0x18ca */);
    // 00446314  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00446317  8b1c8504d05500         -mov ebx, dword ptr [eax*4 + 0x55d004]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5623812) /* 0x55d004 */ + cpu.eax * 4);
    // 0044631e  83fb08                 +cmp ebx, 8
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
    // 00446321  0f8ddd000000           -jge 0x446404
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00446404;
    }
    // 00446327  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00446329  0f8cd5000000           -jl 0x446404
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00446404;
    }
    // 0044632f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446331  e85a1d0300             -call 0x478090
    cpu.esp -= 4;
    sub_478090(app, cpu);
    if (cpu.terminate) return;
    // 00446336  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446338  0f84c6000000           -je 0x446404
    if (cpu.flags.zf)
    {
        goto L_0x00446404;
    }
    // 0044633e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446340  e8bb1d0300             -call 0x478100
    cpu.esp -= 4;
    sub_478100(app, cpu);
    if (cpu.terminate) return;
    // 00446345  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446347  0f84b7000000           -je 0x446404
    if (cpu.flags.zf)
    {
        goto L_0x00446404;
    }
    // 0044634d  8bb230190000           -mov esi, dword ptr [edx + 0x1930]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6448) /* 0x1930 */);
    // 00446353  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00446355  7507                   -jne 0x44635e
    if (!cpu.flags.zf)
    {
        goto L_0x0044635e;
    }
    // 00446357  be90010000             -mov esi, 0x190
    cpu.esi = 400 /*0x190*/;
    // 0044635c  eb05                   -jmp 0x446363
    goto L_0x00446363;
L_0x0044635e:
    // 0044635e  be91010000             -mov esi, 0x191
    cpu.esi = 401 /*0x191*/;
L_0x00446363:
    // 00446363  8b91b4190000           -mov edx, dword ptr [ecx + 0x19b4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6580) /* 0x19b4 */);
    // 00446369  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00446370  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00446372  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00446375  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00446377  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0044637a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044637c  8b9401001a0000         -mov edx, dword ptr [ecx + eax + 0x1a00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6656) /* 0x1a00 */ + cpu.eax * 1);
    // 00446383  b8d6000000             -mov eax, 0xd6
    cpu.eax = 214 /*0xd6*/;
    // 00446388  e8c3b40800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044638d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044638e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00446390  e8bbb40800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00446395  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446396  68cc8b5300             -push 0x538bcc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475276 /*0x538bcc*/;
    cpu.esp -= 4;
    // 0044639b  680c8d5500             -push 0x558d0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606668 /*0x558d0c*/;
    cpu.esp -= 4;
    // 004463a0  e8eb920900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004463a5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004463a8  8d4366                 -lea eax, [ebx + 0x66]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(102) /* 0x66 */);
    // 004463ab  e8a0b40800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004463b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004463b1  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 004463b6  68848d5500             -push 0x558d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606788 /*0x558d84*/;
    cpu.esp -= 4;
    // 004463bb  e8d0920900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004463c0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004463c3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004463c5  e8862effff             -call 0x439250
    cpu.esp -= 4;
    sub_439250(app, cpu);
    if (cpu.terminate) return;
    // 004463ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004463cb  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 004463d0  68fc8d5500             -push 0x558dfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606908 /*0x558dfc*/;
    cpu.esp -= 4;
    // 004463d5  e8b6920900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004463da  8b810c190000           -mov eax, dword ptr [ecx + 0x190c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(6412) /* 0x190c */);
    // 004463e0  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004463e3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004463e6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004463e7  b8f0000000             -mov eax, 0xf0
    cpu.eax = 240 /*0xf0*/;
    // 004463ec  e85fb40800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004463f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004463f2  68d48b5300             -push 0x538bd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475284 /*0x538bd4*/;
    cpu.esp -= 4;
    // 004463f7  68748e5500             -push 0x558e74
    app->getMemory<x86::reg32>(cpu.esp-4) = 5607028 /*0x558e74*/;
    cpu.esp -= 4;
    // 004463fc  e88f920900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446401  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00446404:
    // 00446404  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00446406  e885b40900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0044640b:
    // 0044640b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044640c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044640d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044640e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044640f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446410  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_446420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446420  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446421  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446422  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446423  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00446424  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446425  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446427  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00446429  e832aa0900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0044642e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446430  0f84c7000000           -je 0x4464fd
    if (cpu.flags.zf)
    {
        goto L_0x004464fd;
    }
    // 00446436  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0044643b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044643d  e89eab0900             -call 0x4e0fe0
    cpu.esp -= 4;
    sub_4e0fe0(app, cpu);
    if (cpu.terminate) return;
    // 00446442  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00446444  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00446446  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446448  0f84af000000           -je 0x4464fd
    if (cpu.flags.zf)
    {
        goto L_0x004464fd;
    }
    // 0044644e  8b986c190000           -mov ebx, dword ptr [eax + 0x196c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6508) /* 0x196c */);
    // 00446454  83fb08                 +cmp ebx, 8
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
    // 00446457  0f8f99000000           -jg 0x4464f6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004464f6;
    }
    // 0044645d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044645f  0f8c91000000           -jl 0x4464f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004464f6;
    }
    // 00446465  e8261c0300             -call 0x478090
    cpu.esp -= 4;
    sub_478090(app, cpu);
    if (cpu.terminate) return;
    // 0044646a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044646c  0f8484000000           -je 0x4464f6
    if (cpu.flags.zf)
    {
        goto L_0x004464f6;
    }
    // 00446472  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446474  e8871c0300             -call 0x478100
    cpu.esp -= 4;
    sub_478100(app, cpu);
    if (cpu.terminate) return;
    // 00446479  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044647b  7479                   -je 0x4464f6
    if (cpu.flags.zf)
    {
        goto L_0x004464f6;
    }
    // 0044647d  8b8ab4190000           -mov ecx, dword ptr [edx + 0x19b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6580) /* 0x19b4 */);
    // 00446483  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044648a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044648c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044648f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00446491  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00446494  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00446496  8b8c02001a0000         -mov ecx, dword ptr [edx + eax + 0x1a00]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6656) /* 0x1a00 */ + cpu.eax * 1);
    // 0044649d  8d4366                 -lea eax, [ebx + 0x66]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(102) /* 0x66 */);
    // 004464a0  e8abb30800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004464a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004464a6  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 004464ab  680c8d5500             -push 0x558d0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606668 /*0x558d0c*/;
    cpu.esp -= 4;
    // 004464b0  e8db910900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004464b5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004464b8  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004464bd  e88eb30800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004464c2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004464c3  8b9a74190000           -mov ebx, dword ptr [edx + 0x1974]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6516) /* 0x1974 */);
    // 004464c9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004464ca  68c48b5300             -push 0x538bc4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475268 /*0x538bc4*/;
    cpu.esp -= 4;
    // 004464cf  68848d5500             -push 0x558d84
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606788 /*0x558d84*/;
    cpu.esp -= 4;
    // 004464d4  e8b7910900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004464d9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004464dc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004464de  e86d2dffff             -call 0x439250
    cpu.esp -= 4;
    sub_439250(app, cpu);
    if (cpu.terminate) return;
    // 004464e3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004464e4  68c08b5300             -push 0x538bc0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475264 /*0x538bc0*/;
    cpu.esp -= 4;
    // 004464e9  68fc8d5500             -push 0x558dfc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5606908 /*0x558dfc*/;
    cpu.esp -= 4;
    // 004464ee  e89d910900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004464f3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x004464f6:
    // 004464f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004464f8  e893b30900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004464fd:
    // 004464fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004464fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004464ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446500  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446501  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446502  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_446510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446510  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446511  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446513  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00446519  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044651a  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 0044651f  68dc8b5300             -push 0x538bdc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475292 /*0x538bdc*/;
    cpu.esp -= 4;
    // 00446524  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044652a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044652b  e860910900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446530  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00446533  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00446539  e822a90900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 0044653e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446540  7405                   -je 0x446547
    if (cpu.flags.zf)
    {
        goto L_0x00446547;
    }
    // 00446542  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00446547:
    // 00446547  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00446549  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044654a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_446550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446552  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446553  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00446554  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446555  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446556  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446558  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0044655e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044655f  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 00446564  68dc8b5300             -push 0x538bdc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475292 /*0x538bdc*/;
    cpu.esp -= 4;
    // 00446569  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044656f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446570  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00446575  baf0200000             -mov edx, 0x20f0
    cpu.edx = 8432 /*0x20f0*/;
    // 0044657a  e811910900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 0044657f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00446582  b8e88b5300             -mov eax, 0x538be8
    cpu.eax = 5475304 /*0x538be8*/;
    // 00446587  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00446589  e892b00900             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 0044658e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00446590  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00446592  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446594  743a                   -je 0x4465d0
    if (cpu.flags.zf)
    {
        goto L_0x004465d0;
    }
    // 00446596  bbf0200000             -mov ebx, 0x20f0
    cpu.ebx = 8432 /*0x20f0*/;
    // 0044659b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044659d  b840bb6f00             -mov eax, 0x6fbb40
    cpu.eax = 7322432 /*0x6fbb40*/;
    // 004465a2  e8493f0a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004465a7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004465a9  e8621a0300             -call 0x478010
    cpu.esp -= 4;
    sub_478010(app, cpu);
    if (cpu.terminate) return;
    // 004465ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004465b0  7417                   -je 0x4465c9
    if (cpu.flags.zf)
    {
        goto L_0x004465c9;
    }
    // 004465b2  bbf0200000             -mov ebx, 0x20f0
    cpu.ebx = 8432 /*0x20f0*/;
    // 004465b7  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004465bd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004465bf  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004465c4  e817850a00             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
L_0x004465c9:
    // 004465c9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004465cb  e8c0b20900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004465d0:
    // 004465d0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004465d2  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004465d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004465d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004465d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004465d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004465d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004465d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004465da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_4465e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004465e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004465e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004465e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004465e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004465e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004465e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004465e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004465e8  81ec8c170000           -sub esp, 0x178c
    (cpu.esp) -= x86::reg32(x86::sreg32(6028 /*0x178c*/));
    // 004465ee  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004465f0  b9db050000             -mov ecx, 0x5db
    cpu.ecx = 1499 /*0x5db*/;
    // 004465f5  8dbd74e8ffff           -lea edi, [ebp - 0x178c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-6028) /* -0x178c */);
    // 004465fb  be4cbb6f00             -mov esi, 0x6fbb4c
    cpu.esi = 7322444 /*0x6fbb4c*/;
    // 00446600  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446602  8d7dec                 -lea edi, [ebp - 0x14]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00446605  bedcd26f00             -mov esi, 0x6fd2dc
    cpu.esi = 7328476 /*0x6fd2dc*/;
    // 0044660a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044660b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044660c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044660d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044660f  8d7de0                 -lea edi, [ebp - 0x20]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00446612  be48d36f00             -mov esi, 0x6fd348
    cpu.esi = 7328584 /*0x6fd348*/;
    // 00446617  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0044661a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044661b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044661c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044661d  e83ea80900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00446622  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446624  746a                   -je 0x446690
    if (cpu.flags.zf)
    {
        goto L_0x00446690;
    }
    // 00446626  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0044662b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044662d  e8aea90900             -call 0x4e0fe0
    cpu.esp -= 4;
    sub_4e0fe0(app, cpu);
    if (cpu.terminate) return;
    // 00446632  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00446634  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00446637  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446639  7452                   -je 0x44668d
    if (cpu.flags.zf)
    {
        goto L_0x0044668d;
    }
    // 0044663b  e8501a0300             -call 0x478090
    cpu.esp -= 4;
    sub_478090(app, cpu);
    if (cpu.terminate) return;
    // 00446640  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446642  7441                   -je 0x446685
    if (cpu.flags.zf)
    {
        goto L_0x00446685;
    }
    // 00446644  bbf0200000             -mov ebx, 0x20f0
    cpu.ebx = 8432 /*0x20f0*/;
    // 00446649  ba40bb6f00             -mov edx, 0x6fbb40
    cpu.edx = 7322432 /*0x6fbb40*/;
    // 0044664e  b9db050000             -mov ecx, 0x5db
    cpu.ecx = 1499 /*0x5db*/;
    // 00446653  bf4cbb6f00             -mov edi, 0x6fbb4c
    cpu.edi = 7322444 /*0x6fbb4c*/;
    // 00446658  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044665a  8db574e8ffff           -lea esi, [ebp - 0x178c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-6028) /* -0x178c */);
    // 00446660  e88b3e0a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00446665  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446667  8d75ec                 -lea esi, [ebp - 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0044666a  bfdcd26f00             -mov edi, 0x6fd2dc
    cpu.edi = 7328476 /*0x6fd2dc*/;
    // 0044666f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446670  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446671  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446672  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00446677  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0044667a  bf48d36f00             -mov edi, 0x6fd348
    cpu.edi = 7328584 /*0x6fd348*/;
    // 0044667f  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00446682  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446683  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446684  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x00446685:
    // 00446685  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00446688  e803b20900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x0044668d:
    // 0044668d  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x00446690:
    // 00446690  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00446692  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446693  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446694  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446695  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446696  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446697  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446698  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4466a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004466a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004466a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004466a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004466a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004466a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004466a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004466a7  81ec84170000           -sub esp, 0x1784
    (cpu.esp) -= x86::reg32(x86::sreg32(6020 /*0x1784*/));
    // 004466ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004466af  b9db050000             -mov ecx, 0x5db
    cpu.ecx = 1499 /*0x5db*/;
    // 004466b4  8dbd7ce8ffff           -lea edi, [ebp - 0x1784]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-6020) /* -0x1784 */);
    // 004466ba  be4cbb6f00             -mov esi, 0x6fbb4c
    cpu.esi = 7322444 /*0x6fbb4c*/;
    // 004466bf  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004466c1  8d7df4                 -lea edi, [ebp - 0xc]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004466c4  bedcd26f00             -mov esi, 0x6fd2dc
    cpu.esi = 7328476 /*0x6fd2dc*/;
    // 004466c9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004466ca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004466cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004466cc  8d7de8                 -lea edi, [ebp - 0x18]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004466cf  be48d36f00             -mov esi, 0x6fd348
    cpu.esi = 7328584 /*0x6fd348*/;
    // 004466d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004466d5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004466d6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004466d7  e844c10200             -call 0x472820
    cpu.esp -= 4;
    sub_472820(app, cpu);
    if (cpu.terminate) return;
    // 004466dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004466de  e86d140300             -call 0x477b50
    cpu.esp -= 4;
    sub_477b50(app, cpu);
    if (cpu.terminate) return;
    // 004466e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004466e5  7445                   -je 0x44672c
    if (cpu.flags.zf)
    {
        goto L_0x0044672c;
    }
    // 004466e7  b9db050000             -mov ecx, 0x5db
    cpu.ecx = 1499 /*0x5db*/;
    // 004466ec  8db57ce8ffff           -lea esi, [ebp - 0x1784]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-6020) /* -0x1784 */);
    // 004466f2  bf4cbb6f00             -mov edi, 0x6fbb4c
    cpu.edi = 7322444 /*0x6fbb4c*/;
    // 004466f7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004466f9  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004466fc  bfdcd26f00             -mov edi, 0x6fd2dc
    cpu.edi = 7328476 /*0x6fd2dc*/;
    // 00446701  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446702  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446703  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446704  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00446707  bf48d36f00             -mov edi, 0x6fd348
    cpu.edi = 7328584 /*0x6fd348*/;
    // 0044670c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044670d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044670e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044670f  a1aad46f00             -mov eax, dword ptr [0x6fd4aa]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328938) /* 0x6fd4aa */);
    // 00446714  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00446717  e8e4870800             -call 0x4cef00
    cpu.esp -= 4;
    sub_4cef00(app, cpu);
    if (cpu.terminate) return;
    // 0044671c  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0044671d  a3b4d26f00             -mov dword ptr [0x6fd2b4], eax
    app->getMemory<x86::reg32>(x86::reg32(7328436) /* 0x6fd2b4 */) = cpu.eax;
    // 00446722  a350bb6f00             -mov dword ptr [0x6fbb50], eax
    app->getMemory<x86::reg32>(x86::reg32(7322448) /* 0x6fbb50 */) = cpu.eax;
    // 00446727  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0044672c:
    // 0044672c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044672e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044672f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446730  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446731  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446732  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446733  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_446740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446740  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446741  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446743  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00446749  68ec8b5300             -push 0x538bec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475308 /*0x538bec*/;
    cpu.esp -= 4;
    // 0044674e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044674f  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 00446754  68f08b5300             -push 0x538bf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475312 /*0x538bf0*/;
    cpu.esp -= 4;
    // 00446759  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044675f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446760  e82b8f0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446765  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00446768  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044676e  e8eda60900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00446773  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446775  7405                   -je 0x44677c
    if (cpu.flags.zf)
    {
        goto L_0x0044677c;
    }
    // 00446777  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0044677c:
    // 0044677c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044677e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044677f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_446780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446783  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446784  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446786  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0044678c  68ec8b5300             -push 0x538bec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475308 /*0x538bec*/;
    cpu.esp -= 4;
    // 00446791  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446792  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 00446797  68f08b5300             -push 0x538bf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475312 /*0x538bf0*/;
    cpu.esp -= 4;
    // 0044679c  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004467a2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004467a3  e8e88e0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004467a8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004467ab  b8f88b5300             -mov eax, 0x538bf8
    cpu.eax = 5475320 /*0x538bf8*/;
    // 004467b0  e8aba60900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 004467b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004467b7  7435                   -je 0x4467ee
    if (cpu.flags.zf)
    {
        goto L_0x004467ee;
    }
    // 004467b9  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004467be  b8f88b5300             -mov eax, 0x538bf8
    cpu.eax = 5475320 /*0x538bf8*/;
    // 004467c3  e8f8a60900             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 004467c8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004467ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004467cc  7420                   -je 0x4467ee
    if (cpu.flags.zf)
    {
        goto L_0x004467ee;
    }
    // 004467ce  e8fdad0900             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 004467d3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004467d5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004467d7  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004467dd  e8fe820a00             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
    // 004467e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004467e4  e8a7b00900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004467e9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004467ee:
    // 004467ee  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004467f0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004467f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004467f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004467f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004467f4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_446800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446802  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446803  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00446804  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446805  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446806  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446808  81ec8c170000           -sub esp, 0x178c
    (cpu.esp) -= x86::reg32(x86::sreg32(6028 /*0x178c*/));
    // 0044680e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00446810  b9db050000             -mov ecx, 0x5db
    cpu.ecx = 1499 /*0x5db*/;
    // 00446815  8dbd74e8ffff           -lea edi, [ebp - 0x178c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-6028) /* -0x178c */);
    // 0044681b  be4cbb6f00             -mov esi, 0x6fbb4c
    cpu.esi = 7322444 /*0x6fbb4c*/;
    // 00446820  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446822  8d7dec                 -lea edi, [ebp - 0x14]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 00446825  bedcd26f00             -mov esi, 0x6fd2dc
    cpu.esi = 7328476 /*0x6fd2dc*/;
    // 0044682a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044682b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044682c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044682d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044682f  8d7de0                 -lea edi, [ebp - 0x20]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00446832  be48d36f00             -mov esi, 0x6fd348
    cpu.esi = 7328584 /*0x6fd348*/;
    // 00446837  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0044683a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044683b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044683c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044683d  e81ea60900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00446842  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446844  746a                   -je 0x4468b0
    if (cpu.flags.zf)
    {
        goto L_0x004468b0;
    }
    // 00446846  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0044684b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044684d  e88ea70900             -call 0x4e0fe0
    cpu.esp -= 4;
    sub_4e0fe0(app, cpu);
    if (cpu.terminate) return;
    // 00446852  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00446854  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00446857  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446859  7452                   -je 0x4468ad
    if (cpu.flags.zf)
    {
        goto L_0x004468ad;
    }
    // 0044685b  e830180300             -call 0x478090
    cpu.esp -= 4;
    sub_478090(app, cpu);
    if (cpu.terminate) return;
    // 00446860  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446862  7441                   -je 0x4468a5
    if (cpu.flags.zf)
    {
        goto L_0x004468a5;
    }
    // 00446864  bbf0200000             -mov ebx, 0x20f0
    cpu.ebx = 8432 /*0x20f0*/;
    // 00446869  ba40bb6f00             -mov edx, 0x6fbb40
    cpu.edx = 7322432 /*0x6fbb40*/;
    // 0044686e  b9db050000             -mov ecx, 0x5db
    cpu.ecx = 1499 /*0x5db*/;
    // 00446873  bf4cbb6f00             -mov edi, 0x6fbb4c
    cpu.edi = 7322444 /*0x6fbb4c*/;
    // 00446878  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044687a  8db574e8ffff           -lea esi, [ebp - 0x178c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-6028) /* -0x178c */);
    // 00446880  e86b3c0a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00446885  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446887  8d75ec                 -lea esi, [ebp - 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0044688a  bfdcd26f00             -mov edi, 0x6fd2dc
    cpu.edi = 7328476 /*0x6fd2dc*/;
    // 0044688f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446890  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446891  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00446892  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00446897  8d75e0                 -lea esi, [ebp - 0x20]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0044689a  bf48d36f00             -mov edi, 0x6fd348
    cpu.edi = 7328584 /*0x6fd348*/;
    // 0044689f  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 004468a2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004468a3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004468a4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
L_0x004468a5:
    // 004468a5  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004468a8  e8e3af0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x004468ad:
    // 004468ad  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x004468b0:
    // 004468b0  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004468b2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004468b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004468b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004468b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004468b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004468b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004468b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4468c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004468c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004468c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004468c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004468c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004468c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004468c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004468c6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004468c8  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 004468ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004468cf  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 004468d4  68048c5300             -push 0x538c04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475332 /*0x538c04*/;
    cpu.esp -= 4;
    // 004468d9  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 004468df  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004468e0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004468e5  baf0200000             -mov edx, 0x20f0
    cpu.edx = 8432 /*0x20f0*/;
    // 004468ea  e8a18d0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004468ef  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004468f2  b8e88b5300             -mov eax, 0x538be8
    cpu.eax = 5475304 /*0x538be8*/;
    // 004468f7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004468f9  e822ad0900             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004468fe  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00446900  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00446902  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446904  743a                   -je 0x446940
    if (cpu.flags.zf)
    {
        goto L_0x00446940;
    }
    // 00446906  bbf0200000             -mov ebx, 0x20f0
    cpu.ebx = 8432 /*0x20f0*/;
    // 0044690b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044690d  b840bb6f00             -mov eax, 0x6fbb40
    cpu.eax = 7322432 /*0x6fbb40*/;
    // 00446912  e8d93b0a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 00446917  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00446919  e8f2160300             -call 0x478010
    cpu.esp -= 4;
    sub_478010(app, cpu);
    if (cpu.terminate) return;
    // 0044691e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446920  7417                   -je 0x446939
    if (cpu.flags.zf)
    {
        goto L_0x00446939;
    }
    // 00446922  bbf0200000             -mov ebx, 0x20f0
    cpu.ebx = 8432 /*0x20f0*/;
    // 00446927  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044692d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044692f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00446934  e8a7810a00             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
L_0x00446939:
    // 00446939  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044693b  e850af0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
L_0x00446940:
    // 00446940  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00446942  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00446944  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446945  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446946  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446947  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446948  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446949  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044694a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_446950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446950  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446951  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446953  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00446959  68108c5300             -push 0x538c10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475344 /*0x538c10*/;
    cpu.esp -= 4;
    // 0044695e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044695f  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 00446964  68f08b5300             -push 0x538bf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475312 /*0x538bf0*/;
    cpu.esp -= 4;
    // 00446969  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044696f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446970  e81b8d0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446975  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00446978  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 0044697e  e8dda40900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00446983  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446985  7405                   -je 0x44698c
    if (cpu.flags.zf)
    {
        goto L_0x0044698c;
    }
    // 00446987  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0044698c:
    // 0044698c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044698e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044698f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_446990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446990  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446991  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446992  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446993  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00446994  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446995  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446997  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00446999  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0044699b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0044699d  7515                   -jne 0x4469b4
    if (!cpu.flags.zf)
    {
        goto L_0x004469b4;
    }
    // 0044699f  e87cbe0200             -call 0x472820
    cpu.esp -= 4;
    sub_472820(app, cpu);
    if (cpu.terminate) return;
    // 004469a4  e857610700             -call 0x4bcb00
    cpu.esp -= 4;
    sub_4bcb00(app, cpu);
    if (cpu.terminate) return;
    // 004469a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004469ab  7456                   -je 0x446a03
    if (cpu.flags.zf)
    {
        goto L_0x00446a03;
    }
    // 004469ad  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004469b2  eb4f                   -jmp 0x446a03
    goto L_0x00446a03;
L_0x004469b4:
    // 004469b4  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004469b9  e822a60900             -call 0x4e0fe0
    cpu.esp -= 4;
    sub_4e0fe0(app, cpu);
    if (cpu.terminate) return;
    // 004469be  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004469c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004469c2  743f                   -je 0x446a03
    if (cpu.flags.zf)
    {
        goto L_0x00446a03;
    }
    // 004469c4  b8b48b5300             -mov eax, 0x538bb4
    cpu.eax = 5475252 /*0x538bb4*/;
    // 004469c9  e8d2be0900             -call 0x4e28a0
    cpu.esp -= 4;
    sub_4e28a0(app, cpu);
    if (cpu.terminate) return;
    // 004469ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004469d0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004469d2  e8f9ab0900             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 004469d7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004469d9  b8b48b5300             -mov eax, 0x538bb4
    cpu.eax = 5475252 /*0x538bb4*/;
    // 004469de  e8fd800a00             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
    // 004469e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004469e5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004469e7  e8a4ae0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004469ec  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004469ee  7413                   -je 0x446a03
    if (cpu.flags.zf)
    {
        goto L_0x00446a03;
    }
    // 004469f0  e82bbe0200             -call 0x472820
    cpu.esp -= 4;
    sub_472820(app, cpu);
    if (cpu.terminate) return;
    // 004469f5  e806610700             -call 0x4bcb00
    cpu.esp -= 4;
    sub_4bcb00(app, cpu);
    if (cpu.terminate) return;
    // 004469fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004469fc  7405                   -je 0x446a03
    if (cpu.flags.zf)
    {
        goto L_0x00446a03;
    }
    // 004469fe  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x00446a03:
    // 00446a03  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00446a05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_446a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446a10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446a11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446a12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446a13  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446a14  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446a16  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00446a1c  68148c5300             -push 0x538c14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475348 /*0x538c14*/;
    cpu.esp -= 4;
    // 00446a21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446a22  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 00446a27  68f08b5300             -push 0x538bf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475312 /*0x538bf0*/;
    cpu.esp -= 4;
    // 00446a2c  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00446a32  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446a33  e8588c0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446a38  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00446a3b  b8b48b5300             -mov eax, 0x538bb4
    cpu.eax = 5475252 /*0x538bb4*/;
    // 00446a40  e81ba40900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00446a45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446a47  7435                   -je 0x446a7e
    if (cpu.flags.zf)
    {
        goto L_0x00446a7e;
    }
    // 00446a49  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00446a4e  b8b48b5300             -mov eax, 0x538bb4
    cpu.eax = 5475252 /*0x538bb4*/;
    // 00446a53  e868a40900             -call 0x4e0ec0
    cpu.esp -= 4;
    sub_4e0ec0(app, cpu);
    if (cpu.terminate) return;
    // 00446a58  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00446a5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446a5c  7420                   -je 0x446a7e
    if (cpu.flags.zf)
    {
        goto L_0x00446a7e;
    }
    // 00446a5e  e86dab0900             -call 0x4e15d0
    cpu.esp -= 4;
    sub_4e15d0(app, cpu);
    if (cpu.terminate) return;
    // 00446a63  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00446a65  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00446a67  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00446a6d  e86e800a00             -call 0x4eeae0
    cpu.esp -= 4;
    sub_4eeae0(app, cpu);
    if (cpu.terminate) return;
    // 00446a72  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00446a74  e817ae0900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 00446a79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00446a7e:
    // 00446a7e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00446a80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446a84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_446a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446a90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446a91  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446a93  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00446a99  68148c5300             -push 0x538c14
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475348 /*0x538c14*/;
    cpu.esp -= 4;
    // 00446a9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446a9f  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 00446aa4  68f08b5300             -push 0x538bf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475312 /*0x538bf0*/;
    cpu.esp -= 4;
    // 00446aa9  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00446aaf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446ab0  e8db8b0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446ab5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00446ab8  8d8500ffffff           -lea eax, [ebp - 0x100]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-256) /* -0x100 */);
    // 00446abe  e89da30900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00446ac3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446ac5  7405                   -je 0x446acc
    if (cpu.flags.zf)
    {
        goto L_0x00446acc;
    }
    // 00446ac7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00446acc:
    // 00446acc  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00446ace  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446acf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_446ad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446ad0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446ad1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446ad2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446ad3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446ad5  8b15c0915500           -mov edx, dword ptr [0x5591c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446adb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00446add  7506                   -jne 0x446ae5
    if (!cpu.flags.zf)
    {
        goto L_0x00446ae5;
    }
    // 00446adf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00446ae1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446ae2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446ae3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446ae4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00446ae5:
    // 00446ae5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446ae7  ba108c5300             -mov edx, 0x538c10
    cpu.edx = 5475344 /*0x538c10*/;
    // 00446aec  e8af0a0000             -call 0x4475a0
    cpu.esp -= 4;
    sub_4475a0(app, cpu);
    if (cpu.terminate) return;
    // 00446af1  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446af6  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00446afb  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00446afe  890dbc915500           -mov dword ptr [0x5591bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */) = cpu.ecx;
    // 00446b04  e897060000             -call 0x4471a0
    cpu.esp -= 4;
    sub_4471a0(app, cpu);
    if (cpu.terminate) return;
    // 00446b09  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00446b0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_446b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446b10  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446b11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446b12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446b13  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446b15  8b15c0915500           -mov edx, dword ptr [0x5591c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446b1b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00446b1d  7506                   -jne 0x446b25
    if (!cpu.flags.zf)
    {
        goto L_0x00446b25;
    }
    // 00446b1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00446b21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00446b25:
    // 00446b25  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446b27  ba188c5300             -mov edx, 0x538c18
    cpu.edx = 5475352 /*0x538c18*/;
    // 00446b2c  e86f0a0000             -call 0x4475a0
    cpu.esp -= 4;
    sub_4475a0(app, cpu);
    if (cpu.terminate) return;
    // 00446b31  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446b36  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 00446b3b  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00446b3e  890dbc915500           -mov dword ptr [0x5591bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */) = cpu.ecx;
    // 00446b44  e857060000             -call 0x4471a0
    cpu.esp -= 4;
    sub_4471a0(app, cpu);
    if (cpu.terminate) return;
    // 00446b49  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00446b4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b4f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_446b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446b60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446b61  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446b62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446b63  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446b65  8b15c0915500           -mov edx, dword ptr [0x5591c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446b6b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00446b6d  7506                   -jne 0x446b75
    if (!cpu.flags.zf)
    {
        goto L_0x00446b75;
    }
    // 00446b6f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00446b71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b72  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b74  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00446b75:
    // 00446b75  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446b77  ba148c5300             -mov edx, 0x538c14
    cpu.edx = 5475348 /*0x538c14*/;
    // 00446b7c  e81f0a0000             -call 0x4475a0
    cpu.esp -= 4;
    sub_4475a0(app, cpu);
    if (cpu.terminate) return;
    // 00446b81  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446b86  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00446b88  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00446b8b  890dbc915500           -mov dword ptr [0x5591bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */) = cpu.ecx;
    // 00446b91  e80a060000             -call 0x4471a0
    cpu.esp -= 4;
    sub_4471a0(app, cpu);
    if (cpu.terminate) return;
    // 00446b96  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00446b9b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446b9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_446ba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446ba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446ba1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446ba2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446ba3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446ba5  8b15c0915500           -mov edx, dword ptr [0x5591c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446bab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00446bad  7506                   -jne 0x446bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00446bb5;
    }
    // 00446baf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00446bb1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446bb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446bb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446bb4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00446bb5:
    // 00446bb5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446bb7  baec8b5300             -mov edx, 0x538bec
    cpu.edx = 5475308 /*0x538bec*/;
    // 00446bbc  e8df090000             -call 0x4475a0
    cpu.esp -= 4;
    sub_4475a0(app, cpu);
    if (cpu.terminate) return;
    // 00446bc1  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446bc6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00446bcb  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00446bce  890dbc915500           -mov dword ptr [0x5591bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */) = cpu.ecx;
    // 00446bd4  e8c7050000             -call 0x4471a0
    cpu.esp -= 4;
    sub_4471a0(app, cpu);
    if (cpu.terminate) return;
    // 00446bd9  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00446bde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446bdf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446be0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446be1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_446bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446bf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446bf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446bf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446bf3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446bf4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446bf6  b841000000             -mov eax, 0x41
    cpu.eax = 65 /*0x41*/;
    // 00446bfb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00446c00  bb00040000             -mov ebx, 0x400
    cpu.ebx = 1024 /*0x400*/;
    // 00446c05  e846ac0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00446c0a  a3a0116600             -mov dword ptr [0x6611a0], eax
    app->getMemory<x86::reg32>(x86::reg32(6689184) /* 0x6611a0 */) = cpu.eax;
    // 00446c0f  b8c7010000             -mov eax, 0x1c7
    cpu.eax = 455 /*0x1c7*/;
    // 00446c14  baa0116600             -mov edx, 0x6611a0
    cpu.edx = 6689184 /*0x6611a0*/;
    // 00446c19  e832ac0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00446c1e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00446c20  a3a4116600             -mov dword ptr [0x6611a4], eax
    app->getMemory<x86::reg32>(x86::reg32(6689188) /* 0x6611a4 */) = cpu.eax;
    // 00446c25  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00446c2a  e851deffff             -call 0x444a80
    cpu.esp -= 4;
    sub_444a80(app, cpu);
    if (cpu.terminate) return;
    // 00446c2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c31  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_446c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00446c50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446c51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446c52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446c53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00446c54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446c55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446c56  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446c58  81ecfc000000           -sub esp, 0xfc
    (cpu.esp) -= x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 00446c5e  81ed7a010000           -sub ebp, 0x17a
    (cpu.ebp) -= x86::reg32(x86::sreg32(378 /*0x17a*/));
    // 00446c64  8b15c0915500           -mov edx, dword ptr [0x5591c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446c6a  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00446c6f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00446c71  7507                   -jne 0x446c7a
    if (!cpu.flags.zf)
    {
        goto L_0x00446c7a;
    }
    // 00446c73  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00446c75  e9fb010000             -jmp 0x446e75
    goto L_0x00446e75;
L_0x00446c7a:
    // 00446c7a  8b7a4c                 -mov edi, dword ptr [edx + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 00446c7d  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 00446c80  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00446c82  39cf                   +cmp edi, ecx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00446c84  0f8de9010000           -jge 0x446e73
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00446e73;
    }
    // 00446c8a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00446c8c  7d0f                   -jge 0x446c9d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00446c9d;
    }
    // 00446c8e  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00446c90  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00446c96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c97  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c98  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446c9c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00446c9d:
    // 00446c9d  8b4270                 -mov eax, dword ptr [edx + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 00446ca0  8b14f8                 -mov edx, dword ptr [eax + edi*8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.edi * 8);
    // 00446ca3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446ca4  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 00446ca9  681c8c5300             -push 0x538c1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475356 /*0x538c1c*/;
    cpu.esp -= 4;
    // 00446cae  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446cb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00446cb2  e8d9890900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446cb7  a1bc915500             -mov eax, dword ptr [0x5591bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */);
    // 00446cbc  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00446cbf  83f803                 +cmp eax, 3
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
    // 00446cc2  0f87ab010000           -ja 0x446e73
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00446e73;
    }
    // 00446cc8  ff2485346c4400         -jmp dword ptr [eax*4 + 0x446c34]
    cpu.ip = app->getMemory<x86::reg32>(4484148 + cpu.eax * 4); goto dynamic_jump;
  case 0x00446ccf:
    // 00446ccf  b843010000             -mov eax, 0x143
    cpu.eax = 323 /*0x143*/;
    // 00446cd4  e877ab0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00446cd9  8b3dc0915500           -mov edi, dword ptr [0x5591c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446cdf  8b574c                 -mov edx, dword ptr [edi + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(76) /* 0x4c */);
    // 00446ce2  8b7f70                 -mov edi, dword ptr [edi + 0x70]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(112) /* 0x70 */);
    // 00446ce5  8b3cd7                 -mov edi, dword ptr [edi + edx*8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.edx * 8);
    // 00446ce8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00446cea  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00446cec  e81f760a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00446cf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446cf3  7507                   -jne 0x446cfc
    if (!cpu.flags.zf)
    {
        goto L_0x00446cfc;
    }
    // 00446cf5  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 00446cf7  88657e                 -mov byte ptr [ebp + 0x7e], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.ah;
    // 00446cfa  eb30                   -jmp 0x446d2c
    goto L_0x00446d2c;
L_0x00446cfc:
    // 00446cfc  807d7e00               +cmp byte ptr [ebp + 0x7e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00446d00  742a                   -je 0x446d2c
    if (cpu.flags.zf)
    {
        goto L_0x00446d2c;
    }
    // 00446d02  be148c5300             -mov esi, 0x538c14
    cpu.esi = 5475348 /*0x538c14*/;
    // 00446d07  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446d0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446d0b  2bc9                   +sub ecx, ecx
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
    // 00446d0d  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00446d0e  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00446d10  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00446d12  4f                     -dec edi
    (cpu.edi)--;
L_0x00446d13:
    // 00446d13  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446d15  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00446d17  3c00                   +cmp al, 0
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
    // 00446d19  7410                   -je 0x446d2b
    if (cpu.flags.zf)
    {
        goto L_0x00446d2b;
    }
    // 00446d1b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446d1e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446d21  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446d24  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446d27  3c00                   +cmp al, 0
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
    // 00446d29  75e8                   -jne 0x446d13
    if (!cpu.flags.zf)
    {
        goto L_0x00446d13;
    }
L_0x00446d2b:
    // 00446d2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00446d2c:
    // 00446d2c  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446d2f  e85cfcffff             -call 0x446990
    cpu.esp -= 4;
    sub_446990(app, cpu);
    if (cpu.terminate) return;
    // 00446d34  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446d36  740a                   -je 0x446d42
    if (cpu.flags.zf)
    {
        goto L_0x00446d42;
    }
    // 00446d38  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 00446d3d  e931010000             -jmp 0x446e73
    goto L_0x00446e73;
L_0x00446d42:
    // 00446d42  e8a9feffff             -call 0x446bf0
    cpu.esp -= 4;
    sub_446bf0(app, cpu);
    if (cpu.terminate) return;
    // 00446d47  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00446d49  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00446d4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446d50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446d51  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446d52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446d53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446d54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446d55  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00446d56:
    // 00446d56  807d7e00               +cmp byte ptr [ebp + 0x7e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00446d5a  742a                   -je 0x446d86
    if (cpu.flags.zf)
    {
        goto L_0x00446d86;
    }
    // 00446d5c  be108c5300             -mov esi, 0x538c10
    cpu.esi = 5475344 /*0x538c10*/;
    // 00446d61  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446d64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446d65  2bc9                   +sub ecx, ecx
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
    // 00446d67  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00446d68  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00446d6a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00446d6c  4f                     -dec edi
    (cpu.edi)--;
L_0x00446d6d:
    // 00446d6d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446d6f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00446d71  3c00                   +cmp al, 0
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
    // 00446d73  7410                   -je 0x446d85
    if (cpu.flags.zf)
    {
        goto L_0x00446d85;
    }
    // 00446d75  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446d78  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446d7b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446d7e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446d81  3c00                   +cmp al, 0
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
    // 00446d83  75e8                   -jne 0x446d6d
    if (!cpu.flags.zf)
    {
        goto L_0x00446d6d;
    }
L_0x00446d85:
    // 00446d85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00446d86:
    // 00446d86  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446d89  e872faffff             -call 0x446800
    cpu.esp -= 4;
    sub_446800(app, cpu);
    if (cpu.terminate) return;
    // 00446d8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446d90  7414                   -je 0x446da6
    if (cpu.flags.zf)
    {
        goto L_0x00446da6;
    }
    // 00446d92  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 00446d97  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00446d99  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00446d9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446da0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446da1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446da2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446da3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446da4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446da5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00446da6:
    // 00446da6  e845feffff             -call 0x446bf0
    cpu.esp -= 4;
    sub_446bf0(app, cpu);
    if (cpu.terminate) return;
    // 00446dab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00446dad  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00446db3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446db4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446db5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446db6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446db7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446db8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446db9  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00446dba:
    // 00446dba  807d7e00               +cmp byte ptr [ebp + 0x7e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00446dbe  742a                   -je 0x446dea
    if (cpu.flags.zf)
    {
        goto L_0x00446dea;
    }
    // 00446dc0  be188c5300             -mov esi, 0x538c18
    cpu.esi = 5475352 /*0x538c18*/;
    // 00446dc5  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446dc8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446dc9  2bc9                   +sub ecx, ecx
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
    // 00446dcb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00446dcc  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00446dce  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00446dd0  4f                     -dec edi
    (cpu.edi)--;
L_0x00446dd1:
    // 00446dd1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446dd3  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00446dd5  3c00                   +cmp al, 0
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
    // 00446dd7  7410                   -je 0x446de9
    if (cpu.flags.zf)
    {
        goto L_0x00446de9;
    }
    // 00446dd9  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446ddc  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446ddf  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446de2  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446de5  3c00                   +cmp al, 0
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
    // 00446de7  75e8                   -jne 0x446dd1
    if (!cpu.flags.zf)
    {
        goto L_0x00446dd1;
    }
L_0x00446de9:
    // 00446de9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00446dea:
    // 00446dea  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446ded  e8eef7ffff             -call 0x4465e0
    cpu.esp -= 4;
    sub_4465e0(app, cpu);
    if (cpu.terminate) return;
    // 00446df2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446df4  7414                   -je 0x446e0a
    if (cpu.flags.zf)
    {
        goto L_0x00446e0a;
    }
    // 00446df6  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 00446dfb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00446dfd  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00446e03  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e04  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e05  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e06  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e07  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e08  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e09  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00446e0a:
    // 00446e0a  e8e1fdffff             -call 0x446bf0
    cpu.esp -= 4;
    sub_446bf0(app, cpu);
    if (cpu.terminate) return;
    // 00446e0f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00446e11  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00446e17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e1a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e1c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e1d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00446e1e:
    // 00446e1e  807d7e00               +cmp byte ptr [ebp + 0x7e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00446e22  742a                   -je 0x446e4e
    if (cpu.flags.zf)
    {
        goto L_0x00446e4e;
    }
    // 00446e24  beec8b5300             -mov esi, 0x538bec
    cpu.esi = 5475308 /*0x538bec*/;
    // 00446e29  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446e2c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446e2d  2bc9                   +sub ecx, ecx
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
    // 00446e2f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00446e30  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00446e32  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00446e34  4f                     -dec edi
    (cpu.edi)--;
L_0x00446e35:
    // 00446e35  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446e37  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00446e39  3c00                   +cmp al, 0
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
    // 00446e3b  7410                   -je 0x446e4d
    if (cpu.flags.zf)
    {
        goto L_0x00446e4d;
    }
    // 00446e3d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446e40  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446e43  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446e46  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446e49  3c00                   +cmp al, 0
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
    // 00446e4b  75e8                   -jne 0x446e35
    if (!cpu.flags.zf)
    {
        goto L_0x00446e35;
    }
L_0x00446e4d:
    // 00446e4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00446e4e:
    // 00446e4e  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00446e51  e84af8ffff             -call 0x4466a0
    cpu.esp -= 4;
    sub_4466a0(app, cpu);
    if (cpu.terminate) return;
    // 00446e56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00446e58  7414                   -je 0x446e6e
    if (cpu.flags.zf)
    {
        goto L_0x00446e6e;
    }
    // 00446e5a  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 00446e5f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00446e61  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00446e67  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e68  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00446e6e:
    // 00446e6e  e87dfdffff             -call 0x446bf0
    cpu.esp -= 4;
    sub_446bf0(app, cpu);
    if (cpu.terminate) return;
L_0x00446e73:
    // 00446e73  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00446e75:
    // 00446e75  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00446e7b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e7c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e7e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446e81  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_446ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00446ea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446ea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446ea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00446ea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00446ea4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446ea5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446ea6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446ea8  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446ead  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00446eb0  3b5048                 +cmp edx, dword ptr [eax + 0x48]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00446eb3  7c0d                   -jl 0x446ec2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00446ec2;
    }
    // 00446eb5  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 00446eb7  8825a0106600           -mov byte ptr [0x6610a0], ah
    app->getMemory<x86::reg8>(x86::reg32(6688928) /* 0x6610a0 */) = cpu.ah;
    // 00446ebd  e924010000             -jmp 0x446fe6
    goto L_0x00446fe6;
L_0x00446ec2:
    // 00446ec2  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00446ec5  8b1cd0                 -mov ebx, dword ptr [eax + edx*8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 8);
    // 00446ec8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00446ec9  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 00446ece  681c8c5300             -push 0x538c1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475356 /*0x538c1c*/;
    cpu.esp -= 4;
    // 00446ed3  68a0106600             -push 0x6610a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 6688928 /*0x6610a0*/;
    cpu.esp -= 4;
    // 00446ed8  e8b3870900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00446edd  a1bc915500             -mov eax, dword ptr [0x5591bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */);
    // 00446ee2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00446ee5  83f803                 +cmp eax, 3
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
    // 00446ee8  0f87eb000000           -ja 0x446fd9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00446fd9;
    }
    // 00446eee  ff2485846e4400         -jmp dword ptr [eax*4 + 0x446e84]
    cpu.ip = app->getMemory<x86::reg32>(4484740 + cpu.eax * 4); goto dynamic_jump;
  case 0x00446ef5:
    // 00446ef5  be148c5300             -mov esi, 0x538c14
    cpu.esi = 5475348 /*0x538c14*/;
    // 00446efa  bfa0106600             -mov edi, 0x6610a0
    cpu.edi = 6688928 /*0x6610a0*/;
    // 00446eff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446f00  2bc9                   +sub ecx, ecx
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
    // 00446f02  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00446f03  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00446f05  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00446f07  4f                     -dec edi
    (cpu.edi)--;
L_0x00446f08:
    // 00446f08  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446f0a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00446f0c  3c00                   +cmp al, 0
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
    // 00446f0e  7410                   -je 0x446f20
    if (cpu.flags.zf)
    {
        goto L_0x00446f20;
    }
    // 00446f10  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446f13  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446f16  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446f19  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446f1c  3c00                   +cmp al, 0
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
    // 00446f1e  75e8                   -jne 0x446f08
    if (!cpu.flags.zf)
    {
        goto L_0x00446f08;
    }
L_0x00446f20:
    // 00446f20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446f21  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00446f23  ba148c5300             -mov edx, 0x538c14
    cpu.edx = 5475348 /*0x538c14*/;
    // 00446f28  e99d000000             -jmp 0x446fca
    goto L_0x00446fca;
  case 0x00446f2d:
    // 00446f2d  be108c5300             -mov esi, 0x538c10
    cpu.esi = 5475344 /*0x538c10*/;
    // 00446f32  bfa0106600             -mov edi, 0x6610a0
    cpu.edi = 6688928 /*0x6610a0*/;
    // 00446f37  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446f38  2bc9                   +sub ecx, ecx
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
    // 00446f3a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00446f3b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00446f3d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00446f3f  4f                     -dec edi
    (cpu.edi)--;
L_0x00446f40:
    // 00446f40  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446f42  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00446f44  3c00                   +cmp al, 0
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
    // 00446f46  7410                   -je 0x446f58
    if (cpu.flags.zf)
    {
        goto L_0x00446f58;
    }
    // 00446f48  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446f4b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446f4e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446f51  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446f54  3c00                   +cmp al, 0
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
    // 00446f56  75e8                   -jne 0x446f40
    if (!cpu.flags.zf)
    {
        goto L_0x00446f40;
    }
L_0x00446f58:
    // 00446f58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446f59  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00446f5b  ba108c5300             -mov edx, 0x538c10
    cpu.edx = 5475344 /*0x538c10*/;
    // 00446f60  eb68                   -jmp 0x446fca
    goto L_0x00446fca;
  case 0x00446f62:
    // 00446f62  be188c5300             -mov esi, 0x538c18
    cpu.esi = 5475352 /*0x538c18*/;
    // 00446f67  bfa0106600             -mov edi, 0x6610a0
    cpu.edi = 6688928 /*0x6610a0*/;
    // 00446f6c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446f6d  2bc9                   +sub ecx, ecx
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
    // 00446f6f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00446f70  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00446f72  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00446f74  4f                     -dec edi
    (cpu.edi)--;
L_0x00446f75:
    // 00446f75  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446f77  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00446f79  3c00                   +cmp al, 0
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
    // 00446f7b  7410                   -je 0x446f8d
    if (cpu.flags.zf)
    {
        goto L_0x00446f8d;
    }
    // 00446f7d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446f80  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446f83  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446f86  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446f89  3c00                   +cmp al, 0
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
    // 00446f8b  75e8                   -jne 0x446f75
    if (!cpu.flags.zf)
    {
        goto L_0x00446f75;
    }
L_0x00446f8d:
    // 00446f8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446f8e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00446f90  ba188c5300             -mov edx, 0x538c18
    cpu.edx = 5475352 /*0x538c18*/;
    // 00446f95  eb33                   -jmp 0x446fca
    goto L_0x00446fca;
  case 0x00446f97:
    // 00446f97  beec8b5300             -mov esi, 0x538bec
    cpu.esi = 5475308 /*0x538bec*/;
    // 00446f9c  bfa0106600             -mov edi, 0x6610a0
    cpu.edi = 6688928 /*0x6610a0*/;
    // 00446fa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00446fa2  2bc9                   +sub ecx, ecx
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
    // 00446fa4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00446fa5  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00446fa7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00446fa9  4f                     -dec edi
    (cpu.edi)--;
L_0x00446faa:
    // 00446faa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00446fac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00446fae  3c00                   +cmp al, 0
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
    // 00446fb0  7410                   -je 0x446fc2
    if (cpu.flags.zf)
    {
        goto L_0x00446fc2;
    }
    // 00446fb2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00446fb5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446fb8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00446fbb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00446fbe  3c00                   +cmp al, 0
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
    // 00446fc0  75e8                   -jne 0x446faa
    if (!cpu.flags.zf)
    {
        goto L_0x00446faa;
    }
L_0x00446fc2:
    // 00446fc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446fc3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00446fc5  baec8b5300             -mov edx, 0x538bec
    cpu.edx = 5475308 /*0x538bec*/;
L_0x00446fca:
    // 00446fca  e8d1b80900             -call 0x4e28a0
    cpu.esp -= 4;
    sub_4e28a0(app, cpu);
    if (cpu.terminate) return;
    // 00446fcf  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446fd4  e8c7050000             -call 0x4475a0
    cpu.esp -= 4;
    sub_4475a0(app, cpu);
    if (cpu.terminate) return;
L_0x00446fd9:
    // 00446fd9  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00446fde  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00446fe1  e8ba010000             -call 0x4471a0
    cpu.esp -= 4;
    sub_4471a0(app, cpu);
    if (cpu.terminate) return;
L_0x00446fe6:
    // 00446fe6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446fe7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446fe8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446fe9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446fea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446feb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00446fec  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_446ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00446ff0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00446ff1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00446ff2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00446ff4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00446ff6  e8c5d6ffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 00446ffb  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00446ffe  83f903                 +cmp ecx, 3
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
    // 00447001  7417                   -je 0x44701a
    if (cpu.flags.zf)
    {
        goto L_0x0044701a;
    }
    // 00447003  83f901                 +cmp ecx, 1
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
    // 00447006  7515                   -jne 0x44701d
    if (!cpu.flags.zf)
    {
        goto L_0x0044701d;
    }
    // 00447008  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044700a  7609                   -jbe 0x447015
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00447015;
    }
    // 0044700c  39c8                   +cmp eax, ecx
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
    // 0044700e  740a                   -je 0x44701a
    if (cpu.flags.zf)
    {
        goto L_0x0044701a;
    }
    // 00447010  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00447012  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447013  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447014  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00447015:
    // 00447015  e886feffff             -call 0x446ea0
    cpu.esp -= 4;
    sub_446ea0(app, cpu);
    if (cpu.terminate) return;
L_0x0044701a:
    // 0044701a  c60201                 -mov byte ptr [edx], 1
    app->getMemory<x86::reg8>(cpu.edx) = 1 /*0x1*/;
L_0x0044701d:
    // 0044701d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044701f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447020  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447021  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_447030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447030  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00447031  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447033  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00447034  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00447035  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447036  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447038  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 0044703d  8b704c                 -mov esi, dword ptr [eax + 0x4c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00447040  3b7048                 +cmp esi, dword ptr [eax + 0x48]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00447043  7c0a                   -jl 0x44704f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044704f;
    }
    // 00447045  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 00447047  8825a0106600           -mov byte ptr [0x6610a0], ah
    app->getMemory<x86::reg8>(x86::reg32(6688928) /* 0x6610a0 */) = cpu.ah;
    // 0044704d  eb79                   -jmp 0x4470c8
    goto L_0x004470c8;
L_0x0044704f:
    // 0044704f  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00447052  bfa0106600             -mov edi, 0x6610a0
    cpu.edi = 6688928 /*0x6610a0*/;
    // 00447057  8b34f0                 -mov esi, dword ptr [eax + esi*8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 8);
    // 0044705a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0044705b:
    // 0044705b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044705d  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044705f  3c00                   +cmp al, 0
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
    // 00447061  7410                   -je 0x447073
    if (cpu.flags.zf)
    {
        goto L_0x00447073;
    }
    // 00447063  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00447066  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447069  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044706c  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044706f  3c00                   +cmp al, 0
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
    // 00447071  75e8                   -jne 0x44705b
    if (!cpu.flags.zf)
    {
        goto L_0x0044705b;
    }
L_0x00447073:
    // 00447073  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447074  b844010000             -mov eax, 0x144
    cpu.eax = 324 /*0x144*/;
    // 00447079  e8d2a70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044707e  a3a8116600             -mov dword ptr [0x6611a8], eax
    app->getMemory<x86::reg32>(x86::reg32(6689192) /* 0x6611a8 */) = cpu.eax;
    // 00447083  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 00447088  893dac116600           -mov dword ptr [0x6611ac], edi
    app->getMemory<x86::reg32>(x86::reg32(6689196) /* 0x6611ac */) = cpu.edi;
    // 0044708e  e8bda70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447093  a3b0116600             -mov dword ptr [0x6611b0], eax
    app->getMemory<x86::reg32>(x86::reg32(6689200) /* 0x6611b0 */) = cpu.eax;
    // 00447098  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 0044709d  e8aea70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004470a2  68f06f4400             -push 0x446ff0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4485104 /*0x446ff0*/;
    cpu.esp -= 4;
    // 004470a7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004470a9  b9b0116600             -mov ecx, 0x6611b0
    cpu.ecx = 6689200 /*0x6611b0*/;
    // 004470ae  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004470b0  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004470b5  baa8116600             -mov edx, 0x6611a8
    cpu.edx = 6689192 /*0x6611a8*/;
    // 004470ba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004470bc  a3b4116600             -mov dword ptr [0x6611b4], eax
    app->getMemory<x86::reg32>(x86::reg32(6689204) /* 0x6611b4 */) = cpu.eax;
    // 004470c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004470c3  e808d6ffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
L_0x004470c8:
    // 004470c8  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004470cd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004470ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004470cf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004470d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004470d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004470d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004470d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4470e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004470e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004470e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004470e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004470e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004470e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004470e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004470e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004470e8  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004470ee  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004470f1  8b7006                 -mov esi, dword ptr [eax + 6]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 004470f4  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 004470f9  e852a70800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004470fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004470ff  68248c5300             -push 0x538c24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475364 /*0x538c24*/;
    cpu.esp -= 4;
    // 00447104  8d85fcfeffff           -lea eax, [ebp - 0x104]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-260) /* -0x104 */);
    // 0044710a  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0044710f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00447110  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 00447113  e878850900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00447118  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044711b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0044711e  83c70a                 -add edi, 0xa
    (cpu.edi) += x86::reg32(x86::sreg32(10 /*0xa*/));
    // 00447121  68ffbe5aff             -push 0xff5abeff
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284137215 /*0xff5abeff*/;
    cpu.esp -= 4;
    // 00447126  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00447128  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0044712a  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0044712c  8d85fcfeffff           -lea eax, [ebp - 0x104]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-260) /* -0x104 */);
    // 00447132  83c619                 -add esi, 0x19
    (cpu.esi) += x86::reg32(x86::sreg32(25 /*0x19*/));
    // 00447135  e856b00000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 0044713a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044713c  83c70a                 +add edi, 0xa
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044713f  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 00447142  eb2a                   -jmp 0x44716e
    goto L_0x0044716e;
L_0x00447144:
    // 00447144  68fd9d64ff             -push 0xff649dfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4284784125 /*0xff649dfd*/;
    cpu.esp -= 4;
    // 00447149  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 0044714e  050c8d5500             -add eax, 0x558d0c
    (cpu.eax) += x86::reg32(x86::sreg32(5606668 /*0x558d0c*/));
    // 00447153  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 00447155  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00447157  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00447159  e832b00000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
L_0x0044715e:
    // 0044715e  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447161  43                     -inc ebx
    (cpu.ebx)++;
    // 00447162  83c614                 -add esi, 0x14
    (cpu.esi) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00447165  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00447168  837dfc0a               +cmp dword ptr [ebp - 4], 0xa
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044716c  7d18                   -jge 0x447186
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00447186;
    }
L_0x0044716e:
    // 0044716e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447171  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00447174  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00447176  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00447179  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044717b  80b80c8d550000         +cmp byte ptr [eax + 0x558d0c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5606668) /* 0x558d0c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00447182  75c0                   -jne 0x447144
    if (!cpu.flags.zf)
    {
        goto L_0x00447144;
    }
    // 00447184  ebd8                   -jmp 0x44715e
    goto L_0x0044715e;
L_0x00447186:
    // 00447186  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00447188  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447189  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044718a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044718b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044718c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044718d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044718e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4471a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004471a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004471a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004471a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004471a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004471a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004471a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004471a7  81ecfc000000           -sub esp, 0xfc
    (cpu.esp) -= x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 004471ad  81ed7a010000           -sub ebp, 0x17a
    (cpu.ebp) -= x86::reg32(x86::sreg32(378 /*0x17a*/));
    // 004471b3  bab0040000             -mov edx, 0x4b0
    cpu.edx = 1200 /*0x4b0*/;
    // 004471b8  b80c8d5500             -mov eax, 0x558d0c
    cpu.eax = 5606668 /*0x558d0c*/;
    // 004471bd  e84a950900             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004471c2  8b15c0915500           -mov edx, dword ptr [0x5591c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 004471c8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004471ca  0f847e010000           -je 0x44734e
    if (cpu.flags.zf)
    {
        goto L_0x0044734e;
    }
    // 004471d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004471d2  8b524c                 -mov edx, dword ptr [edx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 004471d5  3b5048                 +cmp edx, dword ptr [eax + 0x48]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004471d8  0f8d70010000           -jge 0x44734e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044734e;
    }
    // 004471de  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 004471e1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004471e3  0f8c65010000           -jl 0x44734e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044734e;
    }
    // 004471e9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004471eb  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004471ee  8b34d0                 -mov esi, dword ptr [eax + edx*8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 8);
    // 004471f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004471f2  68342f7a00             -push 0x7a2f34
    app->getMemory<x86::reg32>(cpu.esp-4) = 8007476 /*0x7a2f34*/;
    cpu.esp -= 4;
    // 004471f7  681c8c5300             -push 0x538c1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475356 /*0x538c1c*/;
    cpu.esp -= 4;
    // 004471fc  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004471ff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00447200  e88b840900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00447205  a1bc915500             -mov eax, dword ptr [0x5591bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */);
    // 0044720a  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0044720d  83f803                 +cmp eax, 3
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
    // 00447210  0f8738010000           -ja 0x44734e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0044734e;
    }
    // 00447216  ff248590714400         -jmp dword ptr [eax*4 + 0x447190]
    cpu.ip = app->getMemory<x86::reg32>(4485520 + cpu.eax * 4); goto dynamic_jump;
  case 0x0044721d:
    // 0044721d  b843010000             -mov eax, 0x143
    cpu.eax = 323 /*0x143*/;
    // 00447222  e829a60800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447227  8b15c0915500           -mov edx, dword ptr [0x5591c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 0044722d  8b7a4c                 -mov edi, dword ptr [edx + 0x4c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 00447230  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 00447233  8b3cfa                 -mov edi, dword ptr [edx + edi*8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + cpu.edi * 8);
    // 00447236  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00447238  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044723a  e8d1700a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044723f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447241  7507                   -jne 0x44724a
    if (!cpu.flags.zf)
    {
        goto L_0x0044724a;
    }
    // 00447243  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 00447245  88657e                 -mov byte ptr [ebp + 0x7e], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */) = cpu.ah;
    // 00447248  eb30                   -jmp 0x44727a
    goto L_0x0044727a;
L_0x0044724a:
    // 0044724a  807d7e00               +cmp byte ptr [ebp + 0x7e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044724e  742a                   -je 0x44727a
    if (cpu.flags.zf)
    {
        goto L_0x0044727a;
    }
    // 00447250  be148c5300             -mov esi, 0x538c14
    cpu.esi = 5475348 /*0x538c14*/;
    // 00447255  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00447258  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00447259  2bc9                   +sub ecx, ecx
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
    // 0044725b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044725c  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044725e  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00447260  4f                     -dec edi
    (cpu.edi)--;
L_0x00447261:
    // 00447261  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00447263  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00447265  3c00                   +cmp al, 0
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
    // 00447267  7410                   -je 0x447279
    if (cpu.flags.zf)
    {
        goto L_0x00447279;
    }
    // 00447269  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044726c  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044726f  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00447272  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447275  3c00                   +cmp al, 0
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
    // 00447277  75e8                   -jne 0x447261
    if (!cpu.flags.zf)
    {
        goto L_0x00447261;
    }
L_0x00447279:
    // 00447279  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0044727a:
    // 0044727a  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044727d  e8deedffff             -call 0x446060
    cpu.esp -= 4;
    sub_446060(app, cpu);
    if (cpu.terminate) return;
    // 00447282  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00447288  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447289  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044728a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044728b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044728c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044728d  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0044728e:
    // 0044728e  807d7e00               +cmp byte ptr [ebp + 0x7e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00447292  742a                   -je 0x4472be
    if (cpu.flags.zf)
    {
        goto L_0x004472be;
    }
    // 00447294  be108c5300             -mov esi, 0x538c10
    cpu.esi = 5475344 /*0x538c10*/;
    // 00447299  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044729c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044729d  2bc9                   +sub ecx, ecx
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
    // 0044729f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004472a0  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004472a2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004472a4  4f                     -dec edi
    (cpu.edi)--;
L_0x004472a5:
    // 004472a5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004472a7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004472a9  3c00                   +cmp al, 0
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
    // 004472ab  7410                   -je 0x4472bd
    if (cpu.flags.zf)
    {
        goto L_0x004472bd;
    }
    // 004472ad  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004472b0  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004472b3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004472b6  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004472b9  3c00                   +cmp al, 0
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
    // 004472bb  75e8                   -jne 0x4472a5
    if (!cpu.flags.zf)
    {
        goto L_0x004472a5;
    }
L_0x004472bd:
    // 004472bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004472be:
    // 004472be  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004472c1  e81af0ffff             -call 0x4462e0
    cpu.esp -= 4;
    sub_4462e0(app, cpu);
    if (cpu.terminate) return;
    // 004472c6  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 004472cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004472cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004472ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004472cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004472d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004472d1  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004472d2:
    // 004472d2  807d7e00               +cmp byte ptr [ebp + 0x7e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004472d6  742a                   -je 0x447302
    if (cpu.flags.zf)
    {
        goto L_0x00447302;
    }
    // 004472d8  be188c5300             -mov esi, 0x538c18
    cpu.esi = 5475352 /*0x538c18*/;
    // 004472dd  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004472e0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004472e1  2bc9                   +sub ecx, ecx
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
    // 004472e3  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004472e4  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004472e6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004472e8  4f                     -dec edi
    (cpu.edi)--;
L_0x004472e9:
    // 004472e9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004472eb  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004472ed  3c00                   +cmp al, 0
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
    // 004472ef  7410                   -je 0x447301
    if (cpu.flags.zf)
    {
        goto L_0x00447301;
    }
    // 004472f1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004472f4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004472f7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004472fa  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004472fd  3c00                   +cmp al, 0
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
    // 004472ff  75e8                   -jne 0x4472e9
    if (!cpu.flags.zf)
    {
        goto L_0x004472e9;
    }
L_0x00447301:
    // 00447301  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00447302:
    // 00447302  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00447305  e8c6eeffff             -call 0x4461d0
    cpu.esp -= 4;
    sub_4461d0(app, cpu);
    if (cpu.terminate) return;
    // 0044730a  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00447310  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447311  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447312  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447313  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447314  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447315  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00447316:
    // 00447316  807d7e00               +cmp byte ptr [ebp + 0x7e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(126) /* 0x7e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044731a  742a                   -je 0x447346
    if (cpu.flags.zf)
    {
        goto L_0x00447346;
    }
    // 0044731c  beec8b5300             -mov esi, 0x538bec
    cpu.esi = 5475308 /*0x538bec*/;
    // 00447321  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00447324  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00447325  2bc9                   +sub ecx, ecx
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
    // 00447327  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00447328  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0044732a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044732c  4f                     -dec edi
    (cpu.edi)--;
L_0x0044732d:
    // 0044732d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044732f  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00447331  3c00                   +cmp al, 0
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
    // 00447333  7410                   -je 0x447345
    if (cpu.flags.zf)
    {
        goto L_0x00447345;
    }
    // 00447335  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00447338  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044733b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044733e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447341  3c00                   +cmp al, 0
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
    // 00447343  75e8                   -jne 0x44732d
    if (!cpu.flags.zf)
    {
        goto L_0x0044732d;
    }
L_0x00447345:
    // 00447345  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00447346:
    // 00447346  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00447349  e8d2f0ffff             -call 0x446420
    cpu.esp -= 4;
    sub_446420(app, cpu);
    if (cpu.terminate) return;
L_0x0044734e:
    // 0044734e  8da57a010000           -lea esp, [ebp + 0x17a]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(378) /* 0x17a */);
    // 00447354  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447355  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447356  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447357  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447358  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447359  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_447370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00447370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00447371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447372  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447373  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00447374  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447375  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447377  ba2c8c5300             -mov edx, 0x538c2c
    cpu.edx = 5475372 /*0x538c2c*/;
    // 0044737c  e8bfb6ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447381  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447383  7413                   -je 0x447398
    if (cpu.flags.zf)
    {
        goto L_0x00447398;
    }
    // 00447385  803d0c8d550000         +cmp byte ptr [0x558d0c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5606668) /* 0x558d0c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044738c  7506                   -jne 0x447394
    if (!cpu.flags.zf)
    {
        goto L_0x00447394;
    }
    // 0044738e  80480510               +or byte ptr [eax + 5], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00447392  eb04                   -jmp 0x447398
    goto L_0x00447398;
L_0x00447394:
    // 00447394  806005ef               -and byte ptr [eax + 5], 0xef
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x00447398:
    // 00447398  8b15c4915500           -mov edx, dword ptr [0x5591c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607876) /* 0x5591c4 */);
    // 0044739e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004473a0  7454                   -je 0x4473f6
    if (cpu.flags.zf)
    {
        goto L_0x004473f6;
    }
    // 004473a2  8a7a04                 -mov bh, byte ptr [edx + 4]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004473a5  80e7fe                 -and bh, 0xfe
    cpu.bh &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004473a8  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 004473ad  887a04                 -mov byte ptr [edx + 4], bh
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.bh;
    // 004473b0  83784800               +cmp dword ptr [eax + 0x48], 0
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
    // 004473b4  7437                   -je 0x4473ed
    if (cpu.flags.zf)
    {
        goto L_0x004473ed;
    }
    // 004473b6  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 004473b9  3b584c                 +cmp ebx, dword ptr [eax + 0x4c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004473bc  7e2f                   -jle 0x4473ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004473ed;
    }
    // 004473be  833dbc91550000         +cmp dword ptr [0x5591bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004473c5  752f                   -jne 0x4473f6
    if (!cpu.flags.zf)
    {
        goto L_0x004473f6;
    }
    // 004473c7  b843010000             -mov eax, 0x143
    cpu.eax = 323 /*0x143*/;
    // 004473cc  e87fa40800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004473d1  8b0dc0915500           -mov ecx, dword ptr [0x5591c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 004473d7  8b514c                 -mov edx, dword ptr [ecx + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */);
    // 004473da  8b4970                 -mov ecx, dword ptr [ecx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 004473dd  8b0cd1                 -mov ecx, dword ptr [ecx + edx*8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 8);
    // 004473e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004473e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004473e4  e8276f0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004473e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004473eb  7509                   -jne 0x4473f6
    if (!cpu.flags.zf)
    {
        goto L_0x004473f6;
    }
L_0x004473ed:
    // 004473ed  a1c4915500             -mov eax, dword ptr [0x5591c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607876) /* 0x5591c4 */);
    // 004473f2  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004473f6:
    // 004473f6  8b3dc8915500           -mov edi, dword ptr [0x5591c8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5607880) /* 0x5591c8 */);
    // 004473fc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004473fe  7420                   -je 0x447420
    if (cpu.flags.zf)
    {
        goto L_0x00447420;
    }
    // 00447400  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00447405  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 00447408  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044740a  7405                   -je 0x447411
    if (cpu.flags.zf)
    {
        goto L_0x00447411;
    }
    // 0044740c  3b504c                 +cmp edx, dword ptr [eax + 0x4c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044740f  7f0b                   -jg 0x44741c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0044741c;
    }
L_0x00447411:
    // 00447411  a1c8915500             -mov eax, dword ptr [0x5591c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607880) /* 0x5591c8 */);
    // 00447416  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044741a  eb04                   -jmp 0x447420
    goto L_0x00447420;
L_0x0044741c:
    // 0044741c  806704fe               -and byte ptr [edi + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00447420:
    // 00447420  a1bc915500             -mov eax, dword ptr [0x5591bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */);
    // 00447425  83f803                 +cmp eax, 3
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
    // 00447428  772f                   -ja 0x447459
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00447459;
    }
    // 0044742a  ff24855c734400         -jmp dword ptr [eax*4 + 0x44735c]
    cpu.ip = app->getMemory<x86::reg32>(4485980 + cpu.eax * 4); goto dynamic_jump;
  case 0x00447431:
    // 00447431  b83f010000             -mov eax, 0x13f
    cpu.eax = 319 /*0x13f*/;
    // 00447436  eb13                   -jmp 0x44744b
    goto L_0x0044744b;
  case 0x00447438:
    // 00447438  b841010000             -mov eax, 0x141
    cpu.eax = 321 /*0x141*/;
    // 0044743d  eb0c                   -jmp 0x44744b
    goto L_0x0044744b;
  case 0x0044743f:
    // 0044743f  b842010000             -mov eax, 0x142
    cpu.eax = 322 /*0x142*/;
    // 00447444  eb05                   -jmp 0x44744b
    goto L_0x0044744b;
  case 0x00447446:
    // 00447446  b840010000             -mov eax, 0x140
    cpu.eax = 320 /*0x140*/;
L_0x0044744b:
    // 0044744b  e800a40800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447450  8b0dc0915500           -mov ecx, dword ptr [0x5591c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00447456  89413c                 -mov dword ptr [ecx + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(60) /* 0x3c */) = cpu.eax;
L_0x00447459:
    // 00447459  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044745b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044745c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044745d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044745e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044745f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447460  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_447470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00447471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447473  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447474  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447476  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00447478  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044747a  b80c8d5500             -mov eax, 0x558d0c
    cpu.eax = 5606668 /*0x558d0c*/;
    // 0044747f  8915c0915500           -mov dword ptr [0x5591c0], edx
    app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */) = cpu.edx;
    // 00447485  bab0040000             -mov edx, 0x4b0
    cpu.edx = 1200 /*0x4b0*/;
    // 0044748a  e87d920900             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 0044748f  ba2c8c5300             -mov edx, 0x538c2c
    cpu.edx = 5475372 /*0x538c2c*/;
    // 00447494  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447496  e8a5b5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044749b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044749d  7407                   -je 0x4474a6
    if (cpu.flags.zf)
    {
        goto L_0x004474a6;
    }
    // 0044749f  c74054e0704400         -mov dword ptr [eax + 0x54], 0x4470e0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 4485344 /*0x4470e0*/;
L_0x004474a6:
    // 004474a6  ba3c8c5300             -mov edx, 0x538c3c
    cpu.edx = 5475388 /*0x538c3c*/;
    // 004474ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004474ad  e88eb5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004474b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004474b4  740c                   -je 0x4474c2
    if (cpu.flags.zf)
    {
        goto L_0x004474c2;
    }
    // 004474b6  a3c0915500             -mov dword ptr [0x5591c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */) = cpu.eax;
    // 004474bb  c74074a0714400         -mov dword ptr [eax + 0x74], 0x4471a0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = 4485536 /*0x4471a0*/;
L_0x004474c2:
    // 004474c2  ba448c5300             -mov edx, 0x538c44
    cpu.edx = 5475396 /*0x538c44*/;
    // 004474c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004474c9  e872b5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004474ce  a3c4915500             -mov dword ptr [0x5591c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5607876) /* 0x5591c4 */) = cpu.eax;
    // 004474d3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004474d5  7407                   -je 0x4474de
    if (cpu.flags.zf)
    {
        goto L_0x004474de;
    }
    // 004474d7  c7406430704400         -mov dword ptr [eax + 0x64], 0x447030
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4485168 /*0x447030*/;
L_0x004474de:
    // 004474de  ba508c5300             -mov edx, 0x538c50
    cpu.edx = 5475408 /*0x538c50*/;
    // 004474e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004474e5  e856b5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004474ea  a3c8915500             -mov dword ptr [0x5591c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5607880) /* 0x5591c8 */) = cpu.eax;
    // 004474ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004474f1  7407                   -je 0x4474fa
    if (cpu.flags.zf)
    {
        goto L_0x004474fa;
    }
    // 004474f3  c74064506c4400         -mov dword ptr [eax + 0x64], 0x446c50
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4484176 /*0x446c50*/;
L_0x004474fa:
    // 004474fa  ba588c5300             -mov edx, 0x538c58
    cpu.edx = 5475416 /*0x538c58*/;
    // 004474ff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447501  e83ab5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447506  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447508  7407                   -je 0x447511
    if (cpu.flags.zf)
    {
        goto L_0x00447511;
    }
    // 0044750a  c74064d06a4400         -mov dword ptr [eax + 0x64], 0x446ad0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4483792 /*0x446ad0*/;
L_0x00447511:
    // 00447511  ba6c8c5300             -mov edx, 0x538c6c
    cpu.edx = 5475436 /*0x538c6c*/;
    // 00447516  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447518  e823b5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044751d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044751f  7407                   -je 0x447528
    if (cpu.flags.zf)
    {
        goto L_0x00447528;
    }
    // 00447521  c74064106b4400         -mov dword ptr [eax + 0x64], 0x446b10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4483856 /*0x446b10*/;
L_0x00447528:
    // 00447528  ba7c8c5300             -mov edx, 0x538c7c
    cpu.edx = 5475452 /*0x538c7c*/;
    // 0044752d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044752f  e80cb5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447534  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447536  7407                   -je 0x44753f
    if (cpu.flags.zf)
    {
        goto L_0x0044753f;
    }
    // 00447538  c74064a06b4400         -mov dword ptr [eax + 0x64], 0x446ba0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4484000 /*0x446ba0*/;
L_0x0044753f:
    // 0044753f  ba888c5300             -mov edx, 0x538c88
    cpu.edx = 5475464 /*0x538c88*/;
    // 00447544  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447546  e8f5b4ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044754b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044754d  7407                   -je 0x447556
    if (cpu.flags.zf)
    {
        goto L_0x00447556;
    }
    // 0044754f  c74064606b4400         -mov dword ptr [eax + 0x64], 0x446b60
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */) = 4483936 /*0x446b60*/;
L_0x00447556:
    // 00447556  8b0dc0915500           -mov ecx, dword ptr [0x5591c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 0044755c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044755e  740c                   -je 0x44756c
    if (cpu.flags.zf)
    {
        goto L_0x0044756c;
    }
    // 00447560  ba148c5300             -mov edx, 0x538c14
    cpu.edx = 5475348 /*0x538c14*/;
    // 00447565  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447567  e834000000             -call 0x4475a0
    cpu.esp -= 4;
    sub_4475a0(app, cpu);
    if (cpu.terminate) return;
L_0x0044756c:
    // 0044756c  a1c0915500             -mov eax, dword ptr [0x5591c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607872) /* 0x5591c0 */);
    // 00447571  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00447573  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 00447576  891dbc915500           -mov dword ptr [0x5591bc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5607868) /* 0x5591bc */) = cpu.ebx;
    // 0044757c  e81ffcffff             -call 0x4471a0
    cpu.esp -= 4;
    sub_4471a0(app, cpu);
    if (cpu.terminate) return;
    // 00447581  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00447583  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447584  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447585  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447586  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447587  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_447590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447590  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447591  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447593  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00447595  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447596  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4475a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004475a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004475a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004475a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004475a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004475a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004475a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004475a7  81ec20020000           -sub esp, 0x220
    (cpu.esp) -= x86::reg32(x86::sreg32(544 /*0x220*/));
    // 004475ad  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004475b0  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004475b3  8b5070                 -mov edx, dword ptr [eax + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 004475b6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004475b8  7411                   -je 0x4475cb
    if (cpu.flags.zf)
    {
        goto L_0x004475cb;
    }
    // 004475ba  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004475bc  e8cfa20900             -call 0x4e1890
    cpu.esp -= 4;
    sub_4e1890(app, cpu);
    if (cpu.terminate) return;
    // 004475c1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004475c4  c7407000000000         -mov dword ptr [eax + 0x70], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
L_0x004475cb:
    // 004475cb  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004475ce  ba707b0000             -mov edx, 0x7b70
    cpu.edx = 31600 /*0x7b70*/;
    // 004475d3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004475d5  c74048c8000000         -mov dword ptr [eax + 0x48], 0xc8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = 200 /*0xc8*/;
    // 004475dc  b8e88b5300             -mov eax, 0x538be8
    cpu.eax = 5475304 /*0x538be8*/;
    // 004475e1  e83aa00900             -call 0x4e1620
    cpu.esp -= 4;
    sub_4e1620(app, cpu);
    if (cpu.terminate) return;
    // 004475e6  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004475e9  894270                 -mov dword ptr [edx + 0x70], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004475ec  8b4248                 -mov eax, dword ptr [edx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004475ef  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004475f2  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 004475f5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004475f7  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004475fa  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004475fc  0538750000             -add eax, 0x7538
    (cpu.eax) += x86::reg32(x86::sreg32(30008 /*0x7538*/));
    // 00447601  ba148c5300             -mov edx, 0x538c14
    cpu.edx = 5475348 /*0x538c14*/;
    // 00447606  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00447609  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044760c  894df8                 -mov dword ptr [ebp - 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ecx;
    // 0044760f  e8fc6c0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00447614  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447616  756b                   -jne 0x447683
    if (!cpu.flags.zf)
    {
        goto L_0x00447683;
    }
    // 00447618  b8b48b5300             -mov eax, 0x538bb4
    cpu.eax = 5475252 /*0x538bb4*/;
    // 0044761d  e83e980900             -call 0x4e0e60
    cpu.esp -= 4;
    sub_4e0e60(app, cpu);
    if (cpu.terminate) return;
    // 00447622  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447624  745d                   -je 0x447683
    if (cpu.flags.zf)
    {
        goto L_0x00447683;
    }
    // 00447626  b843010000             -mov eax, 0x143
    cpu.eax = 323 /*0x143*/;
    // 0044762b  e820a20800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447630  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00447632  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00447634  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00447635:
    // 00447635  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00447637  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00447639  3c00                   +cmp al, 0
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
    // 0044763b  7410                   -je 0x44764d
    if (cpu.flags.zf)
    {
        goto L_0x0044764d;
    }
    // 0044763d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00447640  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447643  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00447646  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447649  3c00                   +cmp al, 0
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
    // 0044764b  75e8                   -jne 0x447635
    if (!cpu.flags.zf)
    {
        goto L_0x00447635;
    }
L_0x0044764d:
    // 0044764d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044764e  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447651  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00447654  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00447656  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447659  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0044765c  c6400400               -mov byte ptr [eax + 4], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00447660  b843010000             -mov eax, 0x143
    cpu.eax = 323 /*0x143*/;
    // 00447665  e8e6a10800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044766a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044766c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00447671  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00447673  49                     -dec ecx
    (cpu.ecx)--;
    // 00447674  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00447676  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00447678  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0044767a  49                     -dec ecx
    (cpu.ecx)--;
    // 0044767b  8d0431                 -lea eax, [ecx + esi]
    cpu.eax = x86::reg32(cpu.ecx + cpu.esi * 1);
    // 0044767e  8975f8                 -mov dword ptr [ebp - 8], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.esi;
    // 00447681  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x00447683:
    // 00447683  8d85e0fdffff           -lea eax, [ebp - 0x220]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-544) /* -0x220 */);
    // 00447689  e812bd0900             -call 0x4e33a0
    cpu.esp -= 4;
    sub_4e33a0(app, cpu);
    if (cpu.terminate) return;
    // 0044768e  b8342f7a00             -mov eax, 0x7a2f34
    cpu.eax = 8007476 /*0x7a2f34*/;
    // 00447693  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00447696  e8c58b0a00             -call 0x4f0260
    cpu.esp -= 4;
    sub_4f0260(app, cpu);
    if (cpu.terminate) return;
    // 0044769b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044769c  68988c5300             -push 0x538c98
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475480 /*0x538c98*/;
    cpu.esp -= 4;
    // 004476a1  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004476a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004476a5  e8e67f0900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 004476aa  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004476ad  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004476b0  e87b8c0a00             -call 0x4f0330
    cpu.esp -= 4;
    sub_4f0330(app, cpu);
    if (cpu.terminate) return;
    // 004476b5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004476b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004476b9  0f84fb000000           -je 0x4477ba
    if (cpu.flags.zf)
    {
        goto L_0x004477ba;
    }
    // 004476bf  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004476c2  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004476c5  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 004476c8  891cc2                 -mov dword ptr [edx + eax*8], ebx
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 8) = cpu.ebx;
    // 004476cb  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004476ce  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 004476d1  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004476d3  c644c20400             -mov byte ptr [edx + eax*8 + 4], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = 0 /*0x0*/;
    // 004476d8  b22e                   -mov dl, 0x2e
    cpu.dl = 46 /*0x2e*/;
    // 004476da  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
L_0x004476dc:
    // 004476dc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004476de  3ac2                   +cmp al, dl
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
    // 004476e0  7412                   -je 0x4476f4
    if (cpu.flags.zf)
    {
        goto L_0x004476f4;
    }
    // 004476e2  3c00                   +cmp al, 0
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
    // 004476e4  740c                   -je 0x4476f2
    if (cpu.flags.zf)
    {
        goto L_0x004476f2;
    }
    // 004476e6  46                     -inc esi
    (cpu.esi)++;
    // 004476e7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004476e9  3ac2                   +cmp al, dl
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
    // 004476eb  7407                   -je 0x4476f4
    if (cpu.flags.zf)
    {
        goto L_0x004476f4;
    }
    // 004476ed  46                     -inc esi
    (cpu.esi)++;
    // 004476ee  3c00                   +cmp al, 0
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
    // 004476f0  75ea                   -jne 0x4476dc
    if (!cpu.flags.zf)
    {
        goto L_0x004476dc;
    }
L_0x004476f2:
    // 004476f2  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004476f4:
    // 004476f4  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 004476f7  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004476f9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004476fa:
    // 004476fa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004476fc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004476fe  3c00                   +cmp al, 0
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
    // 00447700  7410                   -je 0x447712
    if (cpu.flags.zf)
    {
        goto L_0x00447712;
    }
    // 00447702  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00447705  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447708  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044770b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044770e  3c00                   +cmp al, 0
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
    // 00447710  75e8                   -jne 0x4476fa
    if (!cpu.flags.zf)
    {
        goto L_0x004476fa;
    }
L_0x00447712:
    // 00447712  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447713  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
L_0x00447715:
    // 00447715  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00447717  49                     -dec ecx
    (cpu.ecx)--;
    // 00447718  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044771a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044771c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0044771e  49                     -dec ecx
    (cpu.ecx)--;
    // 0044771f  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00447722  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00447724  ff45f8                 -inc dword ptr [ebp - 8]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */))++;
    // 00447727  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044772a  81fac8000000           +cmp edx, 0xc8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00447730  0f8d84000000           -jge 0x4477ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004477ba;
    }
    // 00447736  e8458b0a00             -call 0x4f0280
    cpu.esp -= 4;
    sub_4f0280(app, cpu);
    if (cpu.terminate) return;
    // 0044773b  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0044773e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447740  0f8474000000           -je 0x4477ba
    if (cpu.flags.zf)
    {
        goto L_0x004477ba;
    }
    // 00447746  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00447748  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044774b  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0044774e  891cc2                 -mov dword ptr [edx + eax*8], ebx
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 8) = cpu.ebx;
    // 00447751  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447754  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 00447757  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044775a  c644c20400             -mov byte ptr [edx + eax*8 + 4], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = 0 /*0x0*/;
    // 0044775f  b22e                   -mov dl, 0x2e
    cpu.dl = 46 /*0x2e*/;
    // 00447761  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
L_0x00447764:
    // 00447764  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00447766  3ac2                   +cmp al, dl
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
    // 00447768  7412                   -je 0x44777c
    if (cpu.flags.zf)
    {
        goto L_0x0044777c;
    }
    // 0044776a  3c00                   +cmp al, 0
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
    // 0044776c  740c                   -je 0x44777a
    if (cpu.flags.zf)
    {
        goto L_0x0044777a;
    }
    // 0044776e  46                     -inc esi
    (cpu.esi)++;
    // 0044776f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00447771  3ac2                   +cmp al, dl
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
    // 00447773  7407                   -je 0x44777c
    if (cpu.flags.zf)
    {
        goto L_0x0044777c;
    }
    // 00447775  46                     -inc esi
    (cpu.esi)++;
    // 00447776  3c00                   +cmp al, 0
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
    // 00447778  75ea                   -jne 0x447764
    if (!cpu.flags.zf)
    {
        goto L_0x00447764;
    }
L_0x0044777a:
    // 0044777a  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0044777c:
    // 0044777c  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 0044777f  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00447781  49                     -dec ecx
    (cpu.ecx)--;
    // 00447782  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00447784  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00447786  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00447788  49                     -dec ecx
    (cpu.ecx)--;
    // 00447789  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0044778c  8d040b                 -lea eax, [ebx + ecx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 0044778f  39f0                   +cmp eax, esi
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
    // 00447791  7327                   -jae 0x4477ba
    if (!cpu.flags.cf)
    {
        goto L_0x004477ba;
    }
    // 00447793  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00447796  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00447798  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00447799:
    // 00447799  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044779b  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044779d  3c00                   +cmp al, 0
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
    // 0044779f  7410                   -je 0x4477b1
    if (cpu.flags.zf)
    {
        goto L_0x004477b1;
    }
    // 004477a1  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004477a4  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004477a7  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004477aa  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004477ad  3c00                   +cmp al, 0
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
    // 004477af  75e8                   -jne 0x447799
    if (!cpu.flags.zf)
    {
        goto L_0x00447799;
    }
L_0x004477b1:
    // 004477b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004477b2  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004477b5  e95bffffff             -jmp 0x447715
    goto L_0x00447715;
L_0x004477ba:
    // 004477ba  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004477bd  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004477c0  894248                 -mov dword ptr [edx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004477c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004477c5  7420                   -je 0x4477e7
    if (cpu.flags.zf)
    {
        goto L_0x004477e7;
    }
    // 004477c7  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 004477ca  3b4a4c                 +cmp ecx, dword ptr [edx + 0x4c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004477cd  7f06                   -jg 0x4477d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004477d5;
    }
    // 004477cf  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004477d2  89424c                 -mov dword ptr [edx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = cpu.eax;
L_0x004477d5:
    // 004477d5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004477d8  83784c00               +cmp dword ptr [eax + 0x4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004477dc  7d0c                   -jge 0x4477ea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004477ea;
    }
    // 004477de  c7404c00000000         -mov dword ptr [eax + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 004477e5  eb03                   -jmp 0x4477ea
    goto L_0x004477ea;
L_0x004477e7:
    // 004477e7  89424c                 -mov dword ptr [edx + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = cpu.eax;
L_0x004477ea:
    // 004477ea  8d85e0fdffff           -lea eax, [ebp - 0x220]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-544) /* -0x220 */);
    // 004477f0  e86b8a0a00             -call 0x4f0260
    cpu.esp -= 4;
    sub_4f0260(app, cpu);
    if (cpu.terminate) return;
    // 004477f5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004477f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004477f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004477f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004477fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004477fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004477fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_447800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00447801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447802  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00447803  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447804  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447806  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00447808  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0044780a  e8b1ceffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 0044780f  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00447812  83f903                 +cmp ecx, 3
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
    // 00447815  7512                   -jne 0x447829
    if (!cpu.flags.zf)
    {
        goto L_0x00447829;
    }
L_0x00447817:
    // 00447817  a1e8915500             -mov eax, dword ptr [0x5591e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607912) /* 0x5591e8 */);
    // 0044781c  e80f020000             -call 0x447a30
    cpu.esp -= 4;
    sub_447a30(app, cpu);
    if (cpu.terminate) return;
    // 00447821  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00447824  e982000000             -jmp 0x4478ab
    goto L_0x004478ab;
L_0x00447829:
    // 00447829  83f901                 +cmp ecx, 1
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
    // 0044782c  0f8579000000           -jne 0x4478ab
    if (!cpu.flags.zf)
    {
        goto L_0x004478ab;
    }
    // 00447832  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447834  760b                   -jbe 0x447841
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00447841;
    }
    // 00447836  39c8                   +cmp eax, ecx
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
    // 00447838  74dd                   -je 0x447817
    if (cpu.flags.zf)
    {
        goto L_0x00447817;
    }
    // 0044783a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044783c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044783d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044783e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044783f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447840  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00447841:
    // 00447841  b8d4915500             -mov eax, 0x5591d4
    cpu.eax = 5607892 /*0x5591d4*/;
    // 00447846  ff15cc915500           -call dword ptr [0x5591cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5607884) /* 0x5591cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044784c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044784e  7423                   -je 0x447873
    if (cpu.flags.zf)
    {
        goto L_0x00447873;
    }
    // 00447850  bad4915500             -mov edx, 0x5591d4
    cpu.edx = 5607892 /*0x5591d4*/;
    // 00447855  b842000000             -mov eax, 0x42
    cpu.eax = 66 /*0x42*/;
    // 0044785a  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0044785f  8915b8116600           -mov dword ptr [0x6611b8], edx
    app->getMemory<x86::reg32>(x86::reg32(6689208) /* 0x6611b8 */) = cpu.edx;
    // 00447865  e8e69f0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044786a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044786c  bab8116600             -mov edx, 0x6611b8
    cpu.edx = 6689208 /*0x6611b8*/;
    // 00447871  eb26                   -jmp 0x447899
    goto L_0x00447899;
L_0x00447873:
    // 00447873  b9d4915500             -mov ecx, 0x5591d4
    cpu.ecx = 5607892 /*0x5591d4*/;
    // 00447878  b843000000             -mov eax, 0x43
    cpu.eax = 67 /*0x43*/;
    // 0044787d  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 00447882  bab8116600             -mov edx, 0x6611b8
    cpu.edx = 6689208 /*0x6611b8*/;
    // 00447887  890db8116600           -mov dword ptr [0x6611b8], ecx
    app->getMemory<x86::reg32>(x86::reg32(6689208) /* 0x6611b8 */) = cpu.ecx;
    // 0044788d  e8be9f0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447892  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447894  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x00447899:
    // 00447899  a3bc116600             -mov dword ptr [0x6611bc], eax
    app->getMemory<x86::reg32>(x86::reg32(6689212) /* 0x6611bc */) = cpu.eax;
    // 0044789e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004478a3  e8d8d1ffff             -call 0x444a80
    cpu.esp -= 4;
    sub_444a80(app, cpu);
    if (cpu.terminate) return;
    // 004478a8  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
L_0x004478ab:
    // 004478ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004478ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004478ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004478af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004478b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004478b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
void Application::sub_4478c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004478c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004478c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004478c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004478c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004478c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004478c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004478c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004478ca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004478cc  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004478cf  e8eccdffff             -call 0x4446c0
    cpu.esp -= 4;
    sub_4446c0(app, cpu);
    if (cpu.terminate) return;
    // 004478d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004478d6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004478d8  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004478db  e830d3ffff             -call 0x444c10
    cpu.esp -= 4;
    sub_444c10(app, cpu);
    if (cpu.terminate) return;
    // 004478e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004478e2  83f903                 +cmp ecx, 3
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
    // 004478e5  7409                   -je 0x4478f0
    if (cpu.flags.zf)
    {
        goto L_0x004478f0;
    }
    // 004478e7  83f901                 +cmp ecx, 1
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
    // 004478ea  750f                   -jne 0x4478fb
    if (!cpu.flags.zf)
    {
        goto L_0x004478fb;
    }
    // 004478ec  39cb                   +cmp ebx, ecx
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
    // 004478ee  750b                   -jne 0x4478fb
    if (!cpu.flags.zf)
    {
        goto L_0x004478fb;
    }
L_0x004478f0:
    // 004478f0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004478f3  c60001                 -mov byte ptr [eax], 1
    app->getMemory<x86::reg8>(cpu.eax) = 1 /*0x1*/;
    // 004478f6  e90d010000             -jmp 0x447a08
    goto L_0x00447a08;
L_0x004478fb:
    // 004478fb  83f901                 +cmp ecx, 1
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
    // 004478fe  0f8504010000           -jne 0x447a08
    if (!cpu.flags.zf)
    {
        goto L_0x00447a08;
    }
    // 00447904  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00447906  740a                   -je 0x447912
    if (cpu.flags.zf)
    {
        goto L_0x00447912;
    }
    // 00447908  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044790a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044790c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044790d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044790e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044790f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447910  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447911  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00447912:
    // 00447912  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00447914  0f84ee000000           -je 0x447a08
    if (cpu.flags.zf)
    {
        goto L_0x00447a08;
    }
    // 0044791a  803a00                 +cmp byte ptr [edx], 0
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
    // 0044791d  0f84e5000000           -je 0x447a08
    if (cpu.flags.zf)
    {
        goto L_0x00447a08;
    }
    // 00447923  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00447925  ff15d0915500           -call dword ptr [0x5591d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5607888) /* 0x5591d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044792b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044792d  7561                   -jne 0x447990
    if (!cpu.flags.zf)
    {
        goto L_0x00447990;
    }
    // 0044792f  bfd4915500             -mov edi, 0x5591d4
    cpu.edi = 5607892 /*0x5591d4*/;
    // 00447934  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00447936  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00447937:
    // 00447937  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00447939  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044793b  3c00                   +cmp al, 0
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
    // 0044793d  7410                   -je 0x44794f
    if (cpu.flags.zf)
    {
        goto L_0x0044794f;
    }
    // 0044793f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00447942  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447945  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00447948  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044794b  3c00                   +cmp al, 0
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
    // 0044794d  75e8                   -jne 0x447937
    if (!cpu.flags.zf)
    {
        goto L_0x00447937;
    }
L_0x0044794f:
    // 0044794f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447950  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00447952  ff15cc915500           -call dword ptr [0x5591cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5607884) /* 0x5591cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00447958  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044795a  7407                   -je 0x447963
    if (cpu.flags.zf)
    {
        goto L_0x00447963;
    }
    // 0044795c  b842000000             -mov eax, 0x42
    cpu.eax = 66 /*0x42*/;
    // 00447961  eb05                   -jmp 0x447968
    goto L_0x00447968;
L_0x00447963:
    // 00447963  b843000000             -mov eax, 0x43
    cpu.eax = 67 /*0x43*/;
L_0x00447968:
    // 00447968  bb00010000             -mov ebx, 0x100
    cpu.ebx = 256 /*0x100*/;
    // 0044796d  bac0116600             -mov edx, 0x6611c0
    cpu.edx = 6689216 /*0x6611c0*/;
    // 00447972  e8d99e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447977  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447979  a3c0116600             -mov dword ptr [0x6611c0], eax
    app->getMemory<x86::reg32>(x86::reg32(6689216) /* 0x6611c0 */) = cpu.eax;
    // 0044797e  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00447983  893dc4116600           -mov dword ptr [0x6611c4], edi
    app->getMemory<x86::reg32>(x86::reg32(6689220) /* 0x6611c4 */) = cpu.edi;
    // 00447989  e8f2d0ffff             -call 0x444a80
    cpu.esp -= 4;
    sub_444a80(app, cpu);
    if (cpu.terminate) return;
    // 0044798e  eb72                   -jmp 0x447a02
    goto L_0x00447a02;
L_0x00447990:
    // 00447990  b83c000000             -mov eax, 0x3c
    cpu.eax = 60 /*0x3c*/;
    // 00447995  e8b69e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044799a  a3c8116600             -mov dword ptr [0x6611c8], eax
    app->getMemory<x86::reg32>(x86::reg32(6689224) /* 0x6611c8 */) = cpu.eax;
    // 0044799f  b8c4000000             -mov eax, 0xc4
    cpu.eax = 196 /*0xc4*/;
    // 004479a4  bfd4915500             -mov edi, 0x5591d4
    cpu.edi = 5607892 /*0x5591d4*/;
    // 004479a9  e8a29e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004479ae  a3cc116600             -mov dword ptr [0x6611cc], eax
    app->getMemory<x86::reg32>(x86::reg32(6689228) /* 0x6611cc */) = cpu.eax;
    // 004479b3  b8c5000000             -mov eax, 0xc5
    cpu.eax = 197 /*0xc5*/;
    // 004479b8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004479ba  e8919e0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 004479bf  a3d0116600             -mov dword ptr [0x6611d0], eax
    app->getMemory<x86::reg32>(x86::reg32(6689232) /* 0x6611d0 */) = cpu.eax;
    // 004479c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004479c5:
    // 004479c5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004479c7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004479c9  3c00                   +cmp al, 0
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
    // 004479cb  7410                   -je 0x4479dd
    if (cpu.flags.zf)
    {
        goto L_0x004479dd;
    }
    // 004479cd  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004479d0  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004479d3  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004479d6  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004479d9  3c00                   +cmp al, 0
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
    // 004479db  75e8                   -jne 0x4479c5
    if (!cpu.flags.zf)
    {
        goto L_0x004479c5;
    }
L_0x004479dd:
    // 004479dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004479de  6800784400             -push 0x447800
    app->getMemory<x86::reg32>(cpu.esp-4) = 4487168 /*0x447800*/;
    cpu.esp -= 4;
    // 004479e3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004479e5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004479e7  b9cc116600             -mov ecx, 0x6611cc
    cpu.ecx = 6689228 /*0x6611cc*/;
    // 004479ec  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004479f1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004479f3  bac8116600             -mov edx, 0x6611c8
    cpu.edx = 6689224 /*0x6611c8*/;
    // 004479f8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004479fd  e8ceccffff             -call 0x4446d0
    cpu.esp -= 4;
    sub_4446d0(app, cpu);
    if (cpu.terminate) return;
L_0x00447a02:
    // 00447a02  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447a05  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x00447a08:
    // 00447a08  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00447a0a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00447a0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447a0d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447a0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447a0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447a10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447a11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_447a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00447a30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00447a31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447a32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447a33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00447a34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00447a35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447a36  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447a38  a3e8915500             -mov dword ptr [0x5591e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5607912) /* 0x5591e8 */) = cpu.eax;
    // 00447a3d  83f803                 +cmp eax, 3
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
    // 00447a40  0f878a000000           -ja 0x447ad0
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00447ad0;
    }
    // 00447a46  ff2485147a4400         -jmp dword ptr [eax*4 + 0x447a14]
    cpu.ip = app->getMemory<x86::reg32>(4487700 + cpu.eax * 4); goto dynamic_jump;
  case 0x00447a4d:
    // 00447a4d  b83d000000             -mov eax, 0x3d
    cpu.eax = 61 /*0x3d*/;
    // 00447a52  ba50654400             -mov edx, 0x446550
    cpu.edx = 4482384 /*0x446550*/;
    // 00447a57  b910654400             -mov ecx, 0x446510
    cpu.ecx = 4482320 /*0x446510*/;
    // 00447a5c  eb5c                   -jmp 0x447aba
    goto L_0x00447aba;
  case 0x00447a5e:
    // 00447a5e  b83e000000             -mov eax, 0x3e
    cpu.eax = 62 /*0x3e*/;
    // 00447a63  bbc0684400             -mov ebx, 0x4468c0
    cpu.ebx = 4483264 /*0x4468c0*/;
    // 00447a68  be50694400             -mov esi, 0x446950
    cpu.esi = 4483408 /*0x446950*/;
    // 00447a6d  e8de9d0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447a72  a3dc116600             -mov dword ptr [0x6611dc], eax
    app->getMemory<x86::reg32>(x86::reg32(6689244) /* 0x6611dc */) = cpu.eax;
    // 00447a77  891dcc915500           -mov dword ptr [0x5591cc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5607884) /* 0x5591cc */) = cpu.ebx;
    // 00447a7d  8935d0915500           -mov dword ptr [0x5591d0], esi
    app->getMemory<x86::reg32>(x86::reg32(5607888) /* 0x5591d0 */) = cpu.esi;
    // 00447a83  eb4b                   -jmp 0x447ad0
    goto L_0x00447ad0;
  case 0x00447a85:
    // 00447a85  b840000000             -mov eax, 0x40
    cpu.eax = 64 /*0x40*/;
    // 00447a8a  bf106a4400             -mov edi, 0x446a10
    cpu.edi = 4483600 /*0x446a10*/;
    // 00447a8f  e8bc9d0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447a94  a3dc116600             -mov dword ptr [0x6611dc], eax
    app->getMemory<x86::reg32>(x86::reg32(6689244) /* 0x6611dc */) = cpu.eax;
    // 00447a99  b8906a4400             -mov eax, 0x446a90
    cpu.eax = 4483728 /*0x446a90*/;
    // 00447a9e  893dcc915500           -mov dword ptr [0x5591cc], edi
    app->getMemory<x86::reg32>(x86::reg32(5607884) /* 0x5591cc */) = cpu.edi;
    // 00447aa4  a3d0915500             -mov dword ptr [0x5591d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5607888) /* 0x5591d0 */) = cpu.eax;
    // 00447aa9  eb25                   -jmp 0x447ad0
    goto L_0x00447ad0;
  case 0x00447aab:
    // 00447aab  b83f000000             -mov eax, 0x3f
    cpu.eax = 63 /*0x3f*/;
    // 00447ab0  ba80674400             -mov edx, 0x446780
    cpu.edx = 4482944 /*0x446780*/;
    // 00447ab5  b940674400             -mov ecx, 0x446740
    cpu.ecx = 4482880 /*0x446740*/;
L_0x00447aba:
    // 00447aba  e8919d0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447abf  a3dc116600             -mov dword ptr [0x6611dc], eax
    app->getMemory<x86::reg32>(x86::reg32(6689244) /* 0x6611dc */) = cpu.eax;
    // 00447ac4  8915cc915500           -mov dword ptr [0x5591cc], edx
    app->getMemory<x86::reg32>(x86::reg32(5607884) /* 0x5591cc */) = cpu.edx;
    // 00447aca  890dd0915500           -mov dword ptr [0x5591d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5607888) /* 0x5591d0 */) = cpu.ecx;
L_0x00447ad0:
    // 00447ad0  b8f9000000             -mov eax, 0xf9
    cpu.eax = 249 /*0xf9*/;
    // 00447ad5  befcd26f00             -mov esi, 0x6fd2fc
    cpu.esi = 7328508 /*0x6fd2fc*/;
    // 00447ada  e8719d0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447adf  a3d4116600             -mov dword ptr [0x6611d4], eax
    app->getMemory<x86::reg32>(x86::reg32(6689236) /* 0x6611d4 */) = cpu.eax;
    // 00447ae4  b8c6000000             -mov eax, 0xc6
    cpu.eax = 198 /*0xc6*/;
    // 00447ae9  bfd4915500             -mov edi, 0x5591d4
    cpu.edi = 5607892 /*0x5591d4*/;
    // 00447aee  e85d9d0800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 00447af3  a3d8116600             -mov dword ptr [0x6611d8], eax
    app->getMemory<x86::reg32>(x86::reg32(6689240) /* 0x6611d8 */) = cpu.eax;
    // 00447af8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00447af9:
    // 00447af9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00447afb  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00447afd  3c00                   +cmp al, 0
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
    // 00447aff  7410                   -je 0x447b11
    if (cpu.flags.zf)
    {
        goto L_0x00447b11;
    }
    // 00447b01  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00447b04  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447b07  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00447b0a  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00447b0d  3c00                   +cmp al, 0
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
    // 00447b0f  75e8                   -jne 0x447af9
    if (!cpu.flags.zf)
    {
        goto L_0x00447af9;
    }
L_0x00447b11:
    // 00447b11  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447b12  68c0784400             -push 0x4478c0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4487360 /*0x4478c0*/;
    cpu.esp -= 4;
    // 00447b17  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447b19  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 00447b1b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00447b1c  b9d4116600             -mov ecx, 0x6611d4
    cpu.ecx = 6689236 /*0x6611d4*/;
    // 00447b21  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00447b26  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447b28  badc116600             -mov edx, 0x6611dc
    cpu.edx = 6689244 /*0x6611dc*/;
    // 00447b2d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00447b32  e8e9d0ffff             -call 0x444c20
    cpu.esp -= 4;
    sub_444c20(app, cpu);
    if (cpu.terminate) return;
    // 00447b37  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447b38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447b39  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447b3a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447b3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447b3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447b3d  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 */
void Application::sub_447b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447b40  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447b41  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447b43  6683fb0d               +cmp bx, 0xd
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00447b47  750a                   -jne 0x447b53
    if (!cpu.flags.zf)
    {
        goto L_0x00447b53;
    }
    // 00447b49  c7051012660001000000   -mov dword ptr [0x661210], 1
    app->getMemory<x86::reg32>(x86::reg32(6689296) /* 0x661210 */) = 1 /*0x1*/;
L_0x00447b53:
    // 00447b53  0fbfdb                 -movsx ebx, bx
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 00447b56  e815970100             -call 0x461270
    cpu.esp -= 4;
    sub_461270(app, cpu);
    if (cpu.terminate) return;
    // 00447b5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447b5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_447b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00447b61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447b62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447b63  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00447b64  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00447b65  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447b66  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447b68  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00447b6b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447b6d  e83e4e0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00447b72  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 00447b74  d80da08c5300           -fmul dword ptr [0x538ca0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475488) /* 0x538ca0 */));
    // 00447b7a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00447b7c  d80da48c5300           -fmul dword ptr [0x538ca4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475492) /* 0x538ca4 */));
    // 00447b82  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00447b84  e8cd810900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00447b89  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00447b8b  e8c6810900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00447b90  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 00447b92  db5df8                 -fistp dword ptr [ebp - 8]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00447b95  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00447b98  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00447b9b  a3b4c96f00             -mov dword ptr [0x6fc9b4], eax
    app->getMemory<x86::reg32>(x86::reg32(7326132) /* 0x6fc9b4 */) = cpu.eax;
    // 00447ba0  8a45fc                 -mov al, byte ptr [ebp - 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447ba3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00447ba8  83c07f                 -add eax, 0x7f
    (cpu.eax) += x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00447bab  8b15e4116600           -mov edx, dword ptr [0x6611e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6689252) /* 0x6611e4 */);
    // 00447bb1  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00447bb3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00447bb5  7413                   -je 0x447bca
    if (cpu.flags.zf)
    {
        goto L_0x00447bca;
    }
    // 00447bb7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447bb9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00447bbe  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00447bc0  a1e4116600             -mov eax, dword ptr [0x6611e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689252) /* 0x6611e4 */);
    // 00447bc5  e8d6500200             -call 0x46cca0
    cpu.esp -= 4;
    sub_46cca0(app, cpu);
    if (cpu.terminate) return;
L_0x00447bca:
    // 00447bca  8b1de8116600           -mov ebx, dword ptr [0x6611e8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6689256) /* 0x6611e8 */);
    // 00447bd0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00447bd2  7410                   -je 0x447be4
    if (cpu.flags.zf)
    {
        goto L_0x00447be4;
    }
    // 00447bd4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00447bd6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447bd8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00447bdd  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00447bdf  e8bc500200             -call 0x46cca0
    cpu.esp -= 4;
    sub_46cca0(app, cpu);
    if (cpu.terminate) return;
L_0x00447be4:
    // 00447be4  8b35ec116600           -mov esi, dword ptr [0x6611ec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6689260) /* 0x6611ec */);
    // 00447bea  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00447bec  7410                   -je 0x447bfe
    if (cpu.flags.zf)
    {
        goto L_0x00447bfe;
    }
    // 00447bee  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00447bf3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447bf5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00447bf7  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00447bf9  e8a2500200             -call 0x46cca0
    cpu.esp -= 4;
    sub_46cca0(app, cpu);
    if (cpu.terminate) return;
L_0x00447bfe:
    // 00447bfe  8b3df0116600           -mov edi, dword ptr [0x6611f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 00447c04  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00447c06  7410                   -je 0x447c18
    if (cpu.flags.zf)
    {
        goto L_0x00447c18;
    }
    // 00447c08  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00447c0d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447c0f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00447c11  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00447c13  e888500200             -call 0x46cca0
    cpu.esp -= 4;
    sub_46cca0(app, cpu);
    if (cpu.terminate) return;
L_0x00447c18:
    // 00447c18  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00447c1d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447c1f  740e                   -je 0x447c2f
    if (cpu.flags.zf)
    {
        goto L_0x00447c2f;
    }
    // 00447c21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447c23  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00447c28  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00447c2a  e871500200             -call 0x46cca0
    cpu.esp -= 4;
    sub_46cca0(app, cpu);
    if (cpu.terminate) return;
L_0x00447c2f:
    // 00447c2f  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00447c31  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_447c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447c40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447c41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447c42  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447c44  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00447c47  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447c49  e8624d0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00447c4e  d80da88c5300           -fmul dword ptr [0x538ca8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475496) /* 0x538ca8 */));
    // 00447c54  e8fd800900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00447c59  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00447c5c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447c5f  a3f4d16f00             -mov dword ptr [0x6fd1f4], eax
    app->getMemory<x86::reg32>(x86::reg32(7328244) /* 0x6fd1f4 */) = cpu.eax;
    // 00447c64  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00447c66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_447c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447c70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447c71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447c72  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447c74  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00447c77  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447c79  e8324d0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00447c7e  d80dac8c5300           -fmul dword ptr [0x538cac]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475500) /* 0x538cac */));
    // 00447c84  e8cd800900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00447c89  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00447c8c  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447c8f  a3f0d16f00             -mov dword ptr [0x6fd1f0], eax
    app->getMemory<x86::reg32>(x86::reg32(7328240) /* 0x6fd1f0 */) = cpu.eax;
    // 00447c94  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00447c96  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447c98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_447ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447ca0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447ca1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447ca2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447ca4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00447ca7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447ca9  e8024d0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00447cae  d80db08c5300           -fmul dword ptr [0x538cb0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475504) /* 0x538cb0 */));
    // 00447cb4  e89d800900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00447cb9  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00447cbc  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447cbf  a3f8d16f00             -mov dword ptr [0x6fd1f8], eax
    app->getMemory<x86::reg32>(x86::reg32(7328248) /* 0x6fd1f8 */) = cpu.eax;
    // 00447cc4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00447cc6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447cc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447cc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_447cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447cd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447cd1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447cd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447cd3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447cd5  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00447cd8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447cda  e8d14c0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00447cdf  d80db48c5300           -fmul dword ptr [0x538cb4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475508) /* 0x538cb4 */));
    // 00447ce5  a1f0116600             -mov eax, dword ptr [0x6611f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 00447cea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447cec  e865800900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00447cf1  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00447cf4  e8c74d0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00447cf9  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00447cfe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447d00  e8bb4d0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00447d05  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447d08  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00447d0a  741b                   -je 0x447d27
    if (cpu.flags.zf)
    {
        goto L_0x00447d27;
    }
    // 00447d0c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00447d0e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447d0f  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00447d14  8915fcd16f00           -mov dword ptr [0x6fd1fc], edx
    app->getMemory<x86::reg32>(x86::reg32(7328252) /* 0x6fd1fc */) = cpu.edx;
    // 00447d1a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447d1c  890d00d26f00           -mov dword ptr [0x6fd200], ecx
    app->getMemory<x86::reg32>(x86::reg32(7328256) /* 0x6fd200 */) = cpu.ecx;
    // 00447d22  e8294c0200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00447d27:
    // 00447d27  ba507d4400             -mov edx, 0x447d50
    cpu.edx = 4488528 /*0x447d50*/;
    // 00447d2c  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00447d31  e88a4d0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00447d36  bad07c4400             -mov edx, 0x447cd0
    cpu.edx = 4488400 /*0x447cd0*/;
    // 00447d3b  a1f0116600             -mov eax, dword ptr [0x6611f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 00447d40  e87b4d0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00447d45  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00447d47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447d48  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447d49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447d4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_447d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447d50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447d51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447d52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447d53  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447d55  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00447d58  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447d5a  e8514c0200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 00447d5f  d80db88c5300           -fmul dword ptr [0x538cb8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475512) /* 0x538cb8 */));
    // 00447d65  a1f0116600             -mov eax, dword ptr [0x6611f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 00447d6a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447d6c  e8e57f0900             -call 0x4dfd56
    cpu.esp -= 4;
    sub_4dfd56(app, cpu);
    if (cpu.terminate) return;
    // 00447d71  db5dfc                 -fistp dword ptr [ebp - 4]
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 00447d74  e8474d0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00447d79  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00447d7e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00447d80  e83b4d0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00447d85  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00447d88  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00447d8a  741b                   -je 0x447da7
    if (cpu.flags.zf)
    {
        goto L_0x00447da7;
    }
    // 00447d8c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00447d8e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447d8f  a1f0116600             -mov eax, dword ptr [0x6611f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 00447d94  891500d26f00           -mov dword ptr [0x6fd200], edx
    app->getMemory<x86::reg32>(x86::reg32(7328256) /* 0x6fd200 */) = cpu.edx;
    // 00447d9a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447d9c  890dfcd16f00           -mov dword ptr [0x6fd1fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(7328252) /* 0x6fd1fc */) = cpu.ecx;
    // 00447da2  e8a94b0200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
L_0x00447da7:
    // 00447da7  ba507d4400             -mov edx, 0x447d50
    cpu.edx = 4488528 /*0x447d50*/;
    // 00447dac  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00447db1  e80a4d0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00447db6  bad07c4400             -mov edx, 0x447cd0
    cpu.edx = 4488400 /*0x447cd0*/;
    // 00447dbb  a1f0116600             -mov eax, dword ptr [0x6611f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 00447dc0  e8fb4c0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
    // 00447dc5  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00447dc7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447dc8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447dc9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00447dca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_447dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00447dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00447dd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00447dd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00447dd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00447dd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00447dd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00447dd6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00447dd8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00447ddb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00447ddd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447ddf  0f84cf030000           -je 0x4481b4
    if (cpu.flags.zf)
    {
        goto L_0x004481b4;
    }
    // 00447de5  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00447dec  740a                   -je 0x447df8
    if (cpu.flags.zf)
    {
        goto L_0x00447df8;
    }
    // 00447dee  689a99193f             -push 0x3f19999a
    app->getMemory<x86::reg32>(cpu.esp-4) = 1058642330 /*0x3f19999a*/;
    cpu.esp -= 4;
    // 00447df3  e838970000             -call 0x451530
    cpu.esp -= 4;
    sub_451530(app, cpu);
    if (cpu.terminate) return;
L_0x00447df8:
    // 00447df8  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00447dfd  b8e0116600             -mov eax, 0x6611e0
    cpu.eax = 6689248 /*0x6611e0*/;
    // 00447e02  e805890900             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 00447e07  babc8c5300             -mov edx, 0x538cbc
    cpu.edx = 5475516 /*0x538cbc*/;
    // 00447e0c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447e0e  e82dacffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447e13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447e15  740d                   -je 0x447e24
    if (cpu.flags.zf)
    {
        goto L_0x00447e24;
    }
    // 00447e17  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00447e1e  7e04                   -jle 0x447e24
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00447e24;
    }
    // 00447e20  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00447e24:
    // 00447e24  bacc8c5300             -mov edx, 0x538ccc
    cpu.edx = 5475532 /*0x538ccc*/;
    // 00447e29  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447e2b  e810acffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447e30  bae08c5300             -mov edx, 0x538ce0
    cpu.edx = 5475552 /*0x538ce0*/;
    // 00447e35  a3e0116600             -mov dword ptr [0x6611e0], eax
    app->getMemory<x86::reg32>(x86::reg32(6689248) /* 0x6611e0 */) = cpu.eax;
    // 00447e3a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447e3c  e8ffabffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447e41  baf48c5300             -mov edx, 0x538cf4
    cpu.edx = 5475572 /*0x538cf4*/;
    // 00447e46  a3e4116600             -mov dword ptr [0x6611e4], eax
    app->getMemory<x86::reg32>(x86::reg32(6689252) /* 0x6611e4 */) = cpu.eax;
    // 00447e4b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447e4d  e8eeabffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447e52  ba048d5300             -mov edx, 0x538d04
    cpu.edx = 5475588 /*0x538d04*/;
    // 00447e57  a3e8116600             -mov dword ptr [0x6611e8], eax
    app->getMemory<x86::reg32>(x86::reg32(6689256) /* 0x6611e8 */) = cpu.eax;
    // 00447e5c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447e5e  e8ddabffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447e63  ba148d5300             -mov edx, 0x538d14
    cpu.edx = 5475604 /*0x538d14*/;
    // 00447e68  a3ec116600             -mov dword ptr [0x6611ec], eax
    app->getMemory<x86::reg32>(x86::reg32(6689260) /* 0x6611ec */) = cpu.eax;
    // 00447e6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447e6f  e8ccabffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447e74  ba248d5300             -mov edx, 0x538d24
    cpu.edx = 5475620 /*0x538d24*/;
    // 00447e79  a3f0116600             -mov dword ptr [0x6611f0], eax
    app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */) = cpu.eax;
    // 00447e7e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00447e80  e8bbabffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00447e85  8b35e0116600           -mov esi, dword ptr [0x6611e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6689248) /* 0x6611e0 */);
    // 00447e8b  a3f4116600             -mov dword ptr [0x6611f4], eax
    app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */) = cpu.eax;
    // 00447e90  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00447e92  7467                   -je 0x447efb
    if (cpu.flags.zf)
    {
        goto L_0x00447efb;
    }
    // 00447e94  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00447e9b  7427                   -je 0x447ec4
    if (cpu.flags.zf)
    {
        goto L_0x00447ec4;
    }
    // 00447e9d  c6463d00               -mov byte ptr [esi + 0x3d], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(61) /* 0x3d */) = 0 /*0x0*/;
    // 00447ea1  66c746400000           -mov word ptr [esi + 0x40], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 00447ea7  66c746064001           -mov word ptr [esi + 6], 0x140
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 320 /*0x140*/;
    // 00447ead  668b15949c5500         -mov dx, word ptr [0x559c94]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5610644) /* 0x559c94 */);
    // 00447eb4  66c746644000           -mov word ptr [esi + 0x64], 0x40
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(100) /* 0x64 */) = 64 /*0x40*/;
    // 00447eba  66895608               -mov word ptr [esi + 8], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.dx;
    // 00447ebe  66895666               -mov word ptr [esi + 0x66], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(102) /* 0x66 */) = cpu.dx;
    // 00447ec2  eb0a                   -jmp 0x447ece
    goto L_0x00447ece;
L_0x00447ec4:
    // 00447ec4  c6463d01               -mov byte ptr [esi + 0x3d], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(61) /* 0x3d */) = 1 /*0x1*/;
    // 00447ec8  66c746400000           -mov word ptr [esi + 0x40], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
L_0x00447ece:
    // 00447ece  db05b4c96f00           -fild dword ptr [0x6fc9b4]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7326132) /* 0x6fc9b4 */))));
    // 00447ed4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447ed6  d80d448d5300           -fmul dword ptr [0x538d44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475652) /* 0x538d44 */));
    // 00447edc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00447edf  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00447ee2  a1e0116600             -mov eax, dword ptr [0x6611e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689248) /* 0x6611e0 */);
    // 00447ee7  ba607b4400             -mov edx, 0x447b60
    cpu.edx = 4488032 /*0x447b60*/;
    // 00447eec  e85f4a0200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00447ef1  a1e0116600             -mov eax, dword ptr [0x6611e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689248) /* 0x6611e0 */);
    // 00447ef6  e8c54b0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x00447efb:
    // 00447efb  a1e4116600             -mov eax, dword ptr [0x6611e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689252) /* 0x6611e4 */);
    // 00447f00  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00447f02  7474                   -je 0x447f78
    if (cpu.flags.zf)
    {
        goto L_0x00447f78;
    }
    // 00447f04  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00447f0b  742a                   -je 0x447f37
    if (cpu.flags.zf)
    {
        goto L_0x00447f37;
    }
    // 00447f0d  c6403d00               -mov byte ptr [eax + 0x3d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(61) /* 0x3d */) = 0 /*0x0*/;
    // 00447f11  66c740400200           -mov word ptr [eax + 0x40], 2
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(64) /* 0x40 */) = 2 /*0x2*/;
    // 00447f17  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00447f19  66c740064001           -mov word ptr [eax + 6], 0x140
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 320 /*0x140*/;
    // 00447f1f  66a19c9c5500           -mov ax, word ptr [0x559c9c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5610652) /* 0x559c9c */);
    // 00447f25  66894208               -mov word ptr [edx + 8], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00447f29  66894266               -mov word ptr [edx + 0x66], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(102) /* 0x66 */) = cpu.ax;
    // 00447f2d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00447f2f  66c740644000           -mov word ptr [eax + 0x64], 0x40
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(100) /* 0x64 */) = 64 /*0x40*/;
    // 00447f35  eb0a                   -jmp 0x447f41
    goto L_0x00447f41;
L_0x00447f37:
    // 00447f37  c6403d01               -mov byte ptr [eax + 0x3d], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(61) /* 0x3d */) = 1 /*0x1*/;
    // 00447f3b  66c740400200           -mov word ptr [eax + 0x40], 2
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(64) /* 0x40 */) = 2 /*0x2*/;
L_0x00447f41:
    // 00447f41  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00447f43  a1f4d16f00             -mov eax, dword ptr [0x6fd1f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328244) /* 0x6fd1f4 */);
    // 00447f48  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 00447f4b  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00447f4e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447f50  df6df8                 -fild qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 00447f53  d80d448d5300           -fmul dword ptr [0x538d44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475652) /* 0x538d44 */));
    // 00447f59  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00447f5c  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00447f5f  a1e4116600             -mov eax, dword ptr [0x6611e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689252) /* 0x6611e4 */);
    // 00447f64  ba407c4400             -mov edx, 0x447c40
    cpu.edx = 4488256 /*0x447c40*/;
    // 00447f69  e8e2490200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00447f6e  a1e4116600             -mov eax, dword ptr [0x6611e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689252) /* 0x6611e4 */);
    // 00447f73  e8484b0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x00447f78:
    // 00447f78  8b35e8116600           -mov esi, dword ptr [0x6611e8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6689256) /* 0x6611e8 */);
    // 00447f7e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00447f80  7470                   -je 0x447ff2
    if (cpu.flags.zf)
    {
        goto L_0x00447ff2;
    }
    // 00447f82  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00447f89  7426                   -je 0x447fb1
    if (cpu.flags.zf)
    {
        goto L_0x00447fb1;
    }
    // 00447f8b  c6463d00               -mov byte ptr [esi + 0x3d], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(61) /* 0x3d */) = 0 /*0x0*/;
    // 00447f8f  66c746400300           -mov word ptr [esi + 0x40], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */) = 3 /*0x3*/;
    // 00447f95  66c746064001           -mov word ptr [esi + 6], 0x140
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = 320 /*0x140*/;
    // 00447f9b  66a1a09c5500           -mov ax, word ptr [0x559ca0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5610656) /* 0x559ca0 */);
    // 00447fa1  66c746644000           -mov word ptr [esi + 0x64], 0x40
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(100) /* 0x64 */) = 64 /*0x40*/;
    // 00447fa7  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00447fab  66894666               -mov word ptr [esi + 0x66], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(102) /* 0x66 */) = cpu.ax;
    // 00447faf  eb0a                   -jmp 0x447fbb
    goto L_0x00447fbb;
L_0x00447fb1:
    // 00447fb1  c6463d01               -mov byte ptr [esi + 0x3d], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(61) /* 0x3d */) = 1 /*0x1*/;
    // 00447fb5  66c746400300           -mov word ptr [esi + 0x40], 3
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(64) /* 0x40 */) = 3 /*0x3*/;
L_0x00447fbb:
    // 00447fbb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00447fbd  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00447fc0  a1f0d16f00             -mov eax, dword ptr [0x6fd1f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328240) /* 0x6fd1f0 */);
    // 00447fc5  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00447fc8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00447fca  df6df8                 -fild qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 00447fcd  d80d448d5300           -fmul dword ptr [0x538d44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475652) /* 0x538d44 */));
    // 00447fd3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00447fd6  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00447fd9  a1e8116600             -mov eax, dword ptr [0x6611e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689256) /* 0x6611e8 */);
    // 00447fde  ba707c4400             -mov edx, 0x447c70
    cpu.edx = 4488304 /*0x447c70*/;
    // 00447fe3  e868490200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00447fe8  a1e8116600             -mov eax, dword ptr [0x6611e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689256) /* 0x6611e8 */);
    // 00447fed  e8ce4a0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x00447ff2:
    // 00447ff2  8b15ec116600           -mov edx, dword ptr [0x6611ec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6689260) /* 0x6611ec */);
    // 00447ff8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00447ffa  7470                   -je 0x44806c
    if (cpu.flags.zf)
    {
        goto L_0x0044806c;
    }
    // 00447ffc  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00448003  7426                   -je 0x44802b
    if (cpu.flags.zf)
    {
        goto L_0x0044802b;
    }
    // 00448005  c6423d00               -mov byte ptr [edx + 0x3d], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(61) /* 0x3d */) = 0 /*0x0*/;
    // 00448009  66c742400400           -mov word ptr [edx + 0x40], 4
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(64) /* 0x40 */) = 4 /*0x4*/;
    // 0044800f  66c742064001           -mov word ptr [edx + 6], 0x140
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = 320 /*0x140*/;
    // 00448015  66a1a49c5500           -mov ax, word ptr [0x559ca4]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5610660) /* 0x559ca4 */);
    // 0044801b  66c742644000           -mov word ptr [edx + 0x64], 0x40
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(100) /* 0x64 */) = 64 /*0x40*/;
    // 00448021  66894208               -mov word ptr [edx + 8], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 00448025  66894266               -mov word ptr [edx + 0x66], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(102) /* 0x66 */) = cpu.ax;
    // 00448029  eb0a                   -jmp 0x448035
    goto L_0x00448035;
L_0x0044802b:
    // 0044802b  c6423d01               -mov byte ptr [edx + 0x3d], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(61) /* 0x3d */) = 1 /*0x1*/;
    // 0044802f  66c742400400           -mov word ptr [edx + 0x40], 4
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(64) /* 0x40 */) = 4 /*0x4*/;
L_0x00448035:
    // 00448035  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00448037  a1f8d16f00             -mov eax, dword ptr [0x6fd1f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328248) /* 0x6fd1f8 */);
    // 0044803c  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0044803f  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00448042  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00448044  df6df8                 -fild qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 00448047  d80d448d5300           -fmul dword ptr [0x538d44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475652) /* 0x538d44 */));
    // 0044804d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00448050  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00448053  a1ec116600             -mov eax, dword ptr [0x6611ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689260) /* 0x6611ec */);
    // 00448058  baa07c4400             -mov edx, 0x447ca0
    cpu.edx = 4488352 /*0x447ca0*/;
    // 0044805d  e8ee480200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00448062  a1ec116600             -mov eax, dword ptr [0x6611ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689260) /* 0x6611ec */);
    // 00448067  e8544a0200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x0044806c:
    // 0044806c  8b3df0116600           -mov edi, dword ptr [0x6611f0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 00448072  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00448074  7470                   -je 0x4480e6
    if (cpu.flags.zf)
    {
        goto L_0x004480e6;
    }
    // 00448076  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044807d  7426                   -je 0x4480a5
    if (cpu.flags.zf)
    {
        goto L_0x004480a5;
    }
    // 0044807f  c6473d00               -mov byte ptr [edi + 0x3d], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(61) /* 0x3d */) = 0 /*0x0*/;
    // 00448083  66c747400600           -mov word ptr [edi + 0x40], 6
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(64) /* 0x40 */) = 6 /*0x6*/;
    // 00448089  66c747064001           -mov word ptr [edi + 6], 0x140
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */) = 320 /*0x140*/;
    // 0044808f  66a1ac9c5500           -mov ax, word ptr [0x559cac]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5610668) /* 0x559cac */);
    // 00448095  66c747644000           -mov word ptr [edi + 0x64], 0x40
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(100) /* 0x64 */) = 64 /*0x40*/;
    // 0044809b  66894708               -mov word ptr [edi + 8], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0044809f  66894766               -mov word ptr [edi + 0x66], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(102) /* 0x66 */) = cpu.ax;
    // 004480a3  eb0a                   -jmp 0x4480af
    goto L_0x004480af;
L_0x004480a5:
    // 004480a5  c6473d01               -mov byte ptr [edi + 0x3d], 1
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(61) /* 0x3d */) = 1 /*0x1*/;
    // 004480a9  66c747400600           -mov word ptr [edi + 0x40], 6
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(64) /* 0x40 */) = 6 /*0x6*/;
L_0x004480af:
    // 004480af  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004480b1  a1fcd16f00             -mov eax, dword ptr [0x6fd1fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328252) /* 0x6fd1fc */);
    // 004480b6  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004480b9  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004480bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004480be  df6df8                 -fild qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 004480c1  d80d448d5300           -fmul dword ptr [0x538d44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475652) /* 0x538d44 */));
    // 004480c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004480ca  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004480cd  a1f0116600             -mov eax, dword ptr [0x6611f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 004480d2  bad07c4400             -mov edx, 0x447cd0
    cpu.edx = 4488400 /*0x447cd0*/;
    // 004480d7  e874480200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 004480dc  a1f0116600             -mov eax, dword ptr [0x6611f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689264) /* 0x6611f0 */);
    // 004480e1  e8da490200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x004480e6:
    // 004480e6  8b1df4116600           -mov ebx, dword ptr [0x6611f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 004480ec  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004480ee  0f8484000000           -je 0x448178
    if (cpu.flags.zf)
    {
        goto L_0x00448178;
    }
    // 004480f4  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004480fb  7426                   -je 0x448123
    if (cpu.flags.zf)
    {
        goto L_0x00448123;
    }
    // 004480fd  c6433d00               -mov byte ptr [ebx + 0x3d], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(61) /* 0x3d */) = 0 /*0x0*/;
    // 00448101  66c743400700           -mov word ptr [ebx + 0x40], 7
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(64) /* 0x40 */) = 7 /*0x7*/;
    // 00448107  66c743064001           -mov word ptr [ebx + 6], 0x140
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 320 /*0x140*/;
    // 0044810d  66a1b09c5500           -mov ax, word ptr [0x559cb0]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5610672) /* 0x559cb0 */);
    // 00448113  66c743644000           -mov word ptr [ebx + 0x64], 0x40
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(100) /* 0x64 */) = 64 /*0x40*/;
    // 00448119  66894308               -mov word ptr [ebx + 8], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 0044811d  66894366               -mov word ptr [ebx + 0x66], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(102) /* 0x66 */) = cpu.ax;
    // 00448121  eb0a                   -jmp 0x44812d
    goto L_0x0044812d;
L_0x00448123:
    // 00448123  c6433d01               -mov byte ptr [ebx + 0x3d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(61) /* 0x3d */) = 1 /*0x1*/;
    // 00448127  66c743400700           -mov word ptr [ebx + 0x40], 7
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(64) /* 0x40 */) = 7 /*0x7*/;
L_0x0044812d:
    // 0044812d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044812f  a100d26f00             -mov eax, dword ptr [0x6fd200]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7328256) /* 0x6fd200 */);
    // 00448134  897dfc                 -mov dword ptr [ebp - 4], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edi;
    // 00448137  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0044813a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0044813c  df6df8                 -fild qword ptr [ebp - 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(-8) /* -0x8 */))));
    // 0044813f  d80d448d5300           -fmul dword ptr [0x538d44]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5475652) /* 0x538d44 */));
    // 00448145  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00448148  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0044814b  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00448150  e8fb470200             -call 0x46c950
    cpu.esp -= 4;
    sub_46c950(app, cpu);
    if (cpu.terminate) return;
    // 00448155  f6052eeb550010         +test byte ptr [0x55eb2e], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5630766) /* 0x55eb2e */) & 16 /*0x10*/));
    // 0044815c  740b                   -je 0x448169
    if (cpu.flags.zf)
    {
        goto L_0x00448169;
    }
    // 0044815e  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00448163  80480510               +or byte ptr [eax + 5], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00448167  eb0f                   -jmp 0x448178
    goto L_0x00448178;
L_0x00448169:
    // 00448169  ba507d4400             -mov edx, 0x447d50
    cpu.edx = 4488528 /*0x447d50*/;
    // 0044816e  a1f4116600             -mov eax, dword ptr [0x6611f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689268) /* 0x6611f4 */);
    // 00448173  e848490200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x00448178:
    // 00448178  ba348d5300             -mov edx, 0x538d34
    cpu.edx = 5475636 /*0x538d34*/;
    // 0044817d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044817f  e8bca8ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448184  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448186  7407                   -je 0x44818f
    if (cpu.flags.zf)
    {
        goto L_0x0044818f;
    }
    // 00448188  c74030407b4400         -mov dword ptr [eax + 0x30], 0x447b40
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 4488000 /*0x447b40*/;
L_0x0044818f:
    // 0044818f  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00448194  baf8116600             -mov edx, 0x6611f8
    cpu.edx = 6689272 /*0x6611f8*/;
    // 00448199  b8f0d16f00             -mov eax, 0x6fd1f0
    cpu.eax = 7328240 /*0x6fd1f0*/;
    // 0044819e  e84d230a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004481a3  a1b4c96f00             -mov eax, dword ptr [0x6fc9b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7326132) /* 0x6fc9b4 */);
    // 004481a8  a30c126600             -mov dword ptr [0x66120c], eax
    app->getMemory<x86::reg32>(x86::reg32(6689292) /* 0x66120c */) = cpu.eax;
    // 004481ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004481af  a310126600             -mov dword ptr [0x661210], eax
    app->getMemory<x86::reg32>(x86::reg32(6689296) /* 0x661210 */) = cpu.eax;
L_0x004481b4:
    // 004481b4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004481b6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004481b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004481b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004481b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004481ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004481bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004481bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4481c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004481c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004481c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004481c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004481c3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004481c5  833d1012660001         +cmp dword ptr [0x661210], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6689296) /* 0x661210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004481cc  751e                   -jne 0x4481ec
    if (!cpu.flags.zf)
    {
        goto L_0x004481ec;
    }
    // 004481ce  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 004481d3  baf0d16f00             -mov edx, 0x6fd1f0
    cpu.edx = 7328240 /*0x6fd1f0*/;
    // 004481d8  b8f8116600             -mov eax, 0x6611f8
    cpu.eax = 6689272 /*0x6611f8*/;
    // 004481dd  e80e230a00             -call 0x4ea4f0
    cpu.esp -= 4;
    sub_4ea4f0(app, cpu);
    if (cpu.terminate) return;
    // 004481e2  a10c126600             -mov eax, dword ptr [0x66120c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689292) /* 0x66120c */);
    // 004481e7  a3b4c96f00             -mov dword ptr [0x6fc9b4], eax
    app->getMemory<x86::reg32>(x86::reg32(7326132) /* 0x6fc9b4 */) = cpu.eax;
L_0x004481ec:
    // 004481ec  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004481f1  b8e0116600             -mov eax, 0x6611e0
    cpu.eax = 6689248 /*0x6611e0*/;
    // 004481f6  e811850900             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004481fb  8b15b4c96f00           -mov edx, dword ptr [0x6fc9b4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7326132) /* 0x6fc9b4 */);
    // 00448201  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00448203  e8e8dbfeff             -call 0x435df0
    cpu.esp -= 4;
    sub_435df0(app, cpu);
    if (cpu.terminate) return;
    // 00448208  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044820a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044820b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044820c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044820d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_448210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448210  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00448211  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448212  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448213  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448215  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00448217  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00448219  8b1518925500           -mov edx, dword ptr [0x559218]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */);
    // 0044821f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00448221  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00448224  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00448226  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00448229  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044822b  ba20126600             -mov edx, 0x661220
    cpu.edx = 6689312 /*0x661220*/;
    // 00448230  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00448233  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00448235  833d1892550014         +cmp dword ptr [0x559218], 0x14
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044823c  7d75                   -jge 0x4482b3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004482b3;
    }
    // 0044823e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044823f  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 00448241  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00448242  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00448245  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00448246  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 00448249  895a08                 -mov dword ptr [edx + 8], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0044824c  68488d5300             -push 0x538d48
    app->getMemory<x86::reg32>(cpu.esp-4) = 5475656 /*0x538d48*/;
    cpu.esp -= 4;
    // 00448251  8d7a14                 -lea edi, [edx + 0x14]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00448254  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00448257  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448258  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0044825b  e830740900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00448260  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00448263  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00448266  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00448268  7427                   -je 0x448291
    if (cpu.flags.zf)
    {
        goto L_0x00448291;
    }
    // 0044826a  be588d5300             -mov esi, 0x538d58
    cpu.esi = 5475672 /*0x538d58*/;
    // 0044826f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448270  2bc9                   +sub ecx, ecx
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
    // 00448272  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00448273  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00448275  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00448277  4f                     -dec edi
    (cpu.edi)--;
L_0x00448278:
    // 00448278  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044827a  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0044827c  3c00                   +cmp al, 0
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
    // 0044827e  7410                   -je 0x448290
    if (cpu.flags.zf)
    {
        goto L_0x00448290;
    }
    // 00448280  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00448283  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00448286  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00448289  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044828c  3c00                   +cmp al, 0
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
    // 0044828e  75e8                   -jne 0x448278
    if (!cpu.flags.zf)
    {
        goto L_0x00448278;
    }
L_0x00448290:
    // 00448290  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00448291:
    // 00448291  8b1518925500           -mov edx, dword ptr [0x559218]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */);
    // 00448297  66a118925500           -mov ax, word ptr [0x559218]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5607960) /* 0x559218 */);
    // 0044829d  8d5a01                 -lea ebx, [edx + 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004482a0  05a8070000             -add eax, 0x7a8
    (cpu.eax) += x86::reg32(x86::sreg32(1960 /*0x7a8*/));
    // 004482a5  891d18925500           -mov dword ptr [0x559218], ebx
    app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */) = cpu.ebx;
    // 004482ab  66890455ec915500       -mov word ptr [edx*2 + 0x5591ec], ax
    app->getMemory<x86::reg16>(x86::reg32(5607916) /* 0x5591ec */ + cpu.edx * 2) = cpu.ax;
L_0x004482b3:
    // 004482b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004482b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004482b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004482b6  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_4482c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004482c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004482c1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004482c2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004482c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004482c6  b8ec915500             -mov eax, 0x5591ec
    cpu.eax = 5607916 /*0x5591ec*/;
    // 004482cb  891518925500           -mov dword ptr [0x559218], edx
    app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */) = cpu.edx;
    // 004482d1  ba2a000000             -mov edx, 0x2a
    cpu.edx = 42 /*0x2a*/;
    // 004482d6  e831840900             -call 0x4e070c
    cpu.esp -= 4;
    sub_4e070c(app, cpu);
    if (cpu.terminate) return;
    // 004482db  b810824400             -mov eax, 0x448210
    cpu.eax = 4489744 /*0x448210*/;
    // 004482e0  e8ab6a0700             -call 0x4bed90
    cpu.esp -= 4;
    sub_4bed90(app, cpu);
    if (cpu.terminate) return;
    // 004482e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004482e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004482e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4482f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004482f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004482f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004482f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004482f3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004482f5  e8c6ffffff             -call 0x4482c0
    cpu.esp -= 4;
    sub_4482c0(app, cpu);
    if (cpu.terminate) return;
    // 004482fa  a114bc6f00             -mov eax, dword ptr [0x6fbc14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */);
    // 004482ff  3b0518925500           +cmp eax, dword ptr [0x559218]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00448305  7c08                   -jl 0x44830f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044830f;
    }
    // 00448307  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00448309  890d14bc6f00           -mov dword ptr [0x6fbc14], ecx
    app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */) = cpu.ecx;
L_0x0044830f:
    // 0044830f  8b1514bc6f00           -mov edx, dword ptr [0x6fbc14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */);
    // 00448315  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00448317  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044831a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044831c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044831f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00448321  8b048520126600         -mov eax, dword ptr [eax*4 + 0x661220]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689312) /* 0x661220 */ + cpu.eax * 4);
    // 00448328  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448329  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044832a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044832b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_448330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448330  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00448331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00448332  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00448333  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448334  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448335  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448337  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 0044833d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0044833f  8b0d18925500           -mov ecx, dword ptr [0x559218]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */);
    // 00448345  3b0d14bc6f00           +cmp ecx, dword ptr [0x6fbc14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044834b  7f08                   -jg 0x448355
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00448355;
    }
    // 0044834d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044834f  891d14bc6f00           -mov dword ptr [0x6fbc14], ebx
    app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */) = cpu.ebx;
L_0x00448355:
    // 00448355  8b3514bc6f00           -mov esi, dword ptr [0x6fbc14]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */);
    // 0044835b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044835d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00448360  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00448362  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00448365  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00448367  b945000000             -mov ecx, 0x45
    cpu.ecx = 69 /*0x45*/;
    // 0044836c  8dbdecfeffff           -lea edi, [ebp - 0x114]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00448372  8d348520126600         -lea esi, [eax*4 + 0x661220]
    cpu.esi = x86::reg32(x86::reg32(6689312) /* 0x661220 */ + cpu.eax * 4);
    // 00448379  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044837b  b945000000             -mov ecx, 0x45
    cpu.ecx = 69 /*0x45*/;
    // 00448380  8db5ecfeffff           -lea esi, [ebp - 0x114]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00448386  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00448388  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044838a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044838c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044838e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044838f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448390  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448391  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448392  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448393  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_4483a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004483a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004483a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004483a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004483a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004483a4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004483a6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004483a8  e813ffffff             -call 0x4482c0
    cpu.esp -= 4;
    sub_4482c0(app, cpu);
    if (cpu.terminate) return;
    // 004483ad  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004483af:
    // 004483af  3b1518925500           +cmp edx, dword ptr [0x559218]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004483b5  7d30                   -jge 0x4483e7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004483e7;
    }
    // 004483b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004483b9  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004483bc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004483be  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004483c1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004483c3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004483c6  3b9820126600           +cmp ebx, dword ptr [eax + 0x661220]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6689312) /* 0x661220 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004483cc  7516                   -jne 0x4483e4
    if (!cpu.flags.zf)
    {
        goto L_0x004483e4;
    }
    // 004483ce  8b8024126600           -mov eax, dword ptr [eax + 0x661224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6689316) /* 0x661224 */);
    // 004483d4  891514bc6f00           -mov dword ptr [0x6fbc14], edx
    app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */) = cpu.edx;
    // 004483da  a318bc6f00             -mov dword ptr [0x6fbc18], eax
    app->getMemory<x86::reg32>(x86::reg32(7322648) /* 0x6fbc18 */) = cpu.eax;
    // 004483df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004483e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004483e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004483e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004483e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004483e4:
    // 004483e4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004483e5  ebc8                   -jmp 0x4483af
    goto L_0x004483af;
L_0x004483e7:
    // 004483e7  a124126600             -mov eax, dword ptr [0x661224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689316) /* 0x661224 */);
    // 004483ec  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004483ee  a318bc6f00             -mov dword ptr [0x6fbc18], eax
    app->getMemory<x86::reg32>(x86::reg32(7322648) /* 0x6fbc18 */) = cpu.eax;
    // 004483f3  893d14bc6f00           -mov dword ptr [0x6fbc14], edi
    app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */) = cpu.edi;
    // 004483f9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004483fa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004483fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004483fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004483fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_448400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448400  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00448401  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448402  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448404  2da8070000             -sub eax, 0x7a8
    (cpu.eax) -= x86::reg32(x86::sreg32(1960 /*0x7a8*/));
    // 00448409  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044840b  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044840e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00448410  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00448413  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00448415  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00448418  0520126600             -add eax, 0x661220
    (cpu.eax) += x86::reg32(x86::sreg32(6689312 /*0x661220*/));
    // 0044841d  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00448420  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448421  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448422  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_448430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448430  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448431  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448433  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00448435  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448436  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_448440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448440  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00448441  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00448442  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00448443  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00448444  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448445  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448446  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448448  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044844a  e871feffff             -call 0x4482c0
    cpu.esp -= 4;
    sub_4482c0(app, cpu);
    if (cpu.terminate) return;
    // 0044844f  a114bc6f00             -mov eax, dword ptr [0x6fbc14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */);
    // 00448454  3b0518925500           +cmp eax, dword ptr [0x559218]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5607960) /* 0x559218 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044845a  7c08                   -jl 0x448464
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00448464;
    }
    // 0044845c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044845e  890d14bc6f00           -mov dword ptr [0x6fbc14], ecx
    app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */) = cpu.ecx;
L_0x00448464:
    // 00448464  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00448469  bfb0276600             -mov edi, 0x6627b0
    cpu.edi = 6694832 /*0x6627b0*/;
    // 0044846e  be10bc6f00             -mov esi, 0x6fbc10
    cpu.esi = 7322640 /*0x6fbc10*/;
    // 00448473  ba608d5300             -mov edx, 0x538d60
    cpu.edx = 5475680 /*0x538d60*/;
    // 00448478  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044847a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044847c  e8bfa5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448481  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448483  740d                   -je 0x448492
    if (cpu.flags.zf)
    {
        goto L_0x00448492;
    }
    // 00448485  f605583a7a0006         +test byte ptr [0x7a3a58], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 6 /*0x6*/));
    // 0044848c  7404                   -je 0x448492
    if (cpu.flags.zf)
    {
        goto L_0x00448492;
    }
    // 0044848e  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00448492:
    // 00448492  ba6c8d5300             -mov edx, 0x538d6c
    cpu.edx = 5475692 /*0x538d6c*/;
    // 00448497  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00448499  e8a2a5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044849e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004484a0  740f                   -je 0x4484b1
    if (cpu.flags.zf)
    {
        goto L_0x004484b1;
    }
    // 004484a2  f605583a7a0006         +test byte ptr [0x7a3a58], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 6 /*0x6*/));
    // 004484a9  7406                   -je 0x4484b1
    if (cpu.flags.zf)
    {
        goto L_0x004484b1;
    }
    // 004484ab  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x004484b1:
    // 004484b1  ba7c8d5300             -mov edx, 0x538d7c
    cpu.edx = 5475708 /*0x538d7c*/;
    // 004484b6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004484b8  e883a5ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004484bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004484bf  740d                   -je 0x4484ce
    if (cpu.flags.zf)
    {
        goto L_0x004484ce;
    }
    // 004484c1  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004484c8  7e04                   -jle 0x4484ce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004484ce;
    }
    // 004484ca  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004484ce:
    // 004484ce  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004484d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004484d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004484d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004484d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004484d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004484d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004484d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_4484e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004484e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004484e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004484e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004484e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004484e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004484e5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004484e7  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004484ea  8b4016                 -mov eax, dword ptr [eax + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 004484ed  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004484f0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004484f3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004484f5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004484fc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004484fe  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00448501  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00448503  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00448506  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044850b  833805                 +cmp dword ptr [eax], 5
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
    // 0044850e  7526                   -jne 0x448536
    if (!cpu.flags.zf)
    {
        goto L_0x00448536;
    }
    // 00448510  ba848d5300             -mov edx, 0x538d84
    cpu.edx = 5475716 /*0x538d84*/;
    // 00448515  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00448518  e8a3a4ffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044851d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044851f  7415                   -je 0x448536
    if (cpu.flags.zf)
    {
        goto L_0x00448536;
    }
    // 00448521  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00448526  bf10bc6f00             -mov edi, 0x6fbc10
    cpu.edi = 7322640 /*0x6fbc10*/;
    // 0044852b  beb0276600             -mov esi, 0x6627b0
    cpu.esi = 6694832 /*0x6627b0*/;
    // 00448530  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00448532  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00448534  eb25                   -jmp 0x44855b
    goto L_0x0044855b;
L_0x00448536:
    // 00448536  e885fdffff             -call 0x4482c0
    cpu.esp -= 4;
    sub_4482c0(app, cpu);
    if (cpu.terminate) return;
    // 0044853b  8b1514bc6f00           -mov edx, dword ptr [0x6fbc14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(7322644) /* 0x6fbc14 */);
    // 00448541  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00448543  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00448546  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00448548  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044854b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044854d  8b048524126600         -mov eax, dword ptr [eax*4 + 0x661224]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6689316) /* 0x661224 */ + cpu.eax * 4);
    // 00448554  a318bc6f00             -mov dword ptr [0x6fbc18], eax
    app->getMemory<x86::reg32>(x86::reg32(7322648) /* 0x6fbc18 */) = cpu.eax;
    // 00448559  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044855b:
    // 0044855b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044855c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044855d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044855e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044855f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448560  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_448570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448570  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00448571  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00448572  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448573  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448575  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00448577  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 0044857c  e8df200000             -call 0x44a660
    cpu.esp -= 4;
    sub_44a660(app, cpu);
    if (cpu.terminate) return;
    // 00448581  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448583  740f                   -je 0x448594
    if (cpu.flags.zf)
    {
        goto L_0x00448594;
    }
    // 00448585  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00448587  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00448589  e822440200             -call 0x46c9b0
    cpu.esp -= 4;
    sub_46c9b0(app, cpu);
    if (cpu.terminate) return;
    // 0044858e  d91d38bc6f00           -fstp dword ptr [0x6fbc38]
    app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00448594:
    // 00448594  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448595  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448596  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448597  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4485a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004485a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004485a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004485a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004485a3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004485a5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004485a7  ba9c8d5300             -mov edx, 0x538d9c
    cpu.edx = 5475740 /*0x538d9c*/;
    // 004485ac  e88fa4ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004485b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004485b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004485b5  741c                   -je 0x4485d3
    if (cpu.flags.zf)
    {
        goto L_0x004485d3;
    }
    // 004485b7  833d683a7a0000         +cmp dword ptr [0x7a3a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010344) /* 0x7a3a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004485be  740f                   -je 0x4485cf
    if (cpu.flags.zf)
    {
        goto L_0x004485cf;
    }
    // 004485c0  833d34bc6f0000         +cmp dword ptr [0x6fbc34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322676) /* 0x6fbc34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004485c7  7406                   -je 0x4485cf
    if (cpu.flags.zf)
    {
        goto L_0x004485cf;
    }
    // 004485c9  806004fe               +and byte ptr [eax + 4], 0xfe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 004485cd  eb04                   -jmp 0x4485d3
    goto L_0x004485d3;
L_0x004485cf:
    // 004485cf  804a0401               -or byte ptr [edx + 4], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004485d3:
    // 004485d3  bab08d5300             -mov edx, 0x538db0
    cpu.edx = 5475760 /*0x538db0*/;
    // 004485d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004485da  e861a4ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004485df  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004485e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004485e3  7420                   -je 0x448605
    if (cpu.flags.zf)
    {
        goto L_0x00448605;
    }
    // 004485e5  833d683a7a0000         +cmp dword ptr [0x7a3a68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8010344) /* 0x7a3a68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004485ec  7411                   -je 0x4485ff
    if (cpu.flags.zf)
    {
        goto L_0x004485ff;
    }
    // 004485ee  833d34bc6f0000         +cmp dword ptr [0x6fbc34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322676) /* 0x6fbc34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004485f5  7408                   -je 0x4485ff
    if (cpu.flags.zf)
    {
        goto L_0x004485ff;
    }
    // 004485f7  66816004feef           +and word ptr [eax + 4], 0xeffe
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg16(x86::sreg16(61438 /*0xeffe*/))));
    // 004485fd  eb06                   -jmp 0x448605
    goto L_0x00448605;
L_0x004485ff:
    // 004485ff  66814a040110           -or word ptr [edx + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x00448605:
    // 00448605  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00448607  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448608  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448609  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044860a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_448610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00448611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00448612  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00448613  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00448614  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448615  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448616  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448618  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 0044861e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00448620  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 00448625  bfb0276600             -mov edi, 0x6627b0
    cpu.edi = 6694832 /*0x6627b0*/;
    // 0044862a  be10bc6f00             -mov esi, 0x6fbc10
    cpu.esi = 7322640 /*0x6fbc10*/;
    // 0044862f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00448631  8db5ecfeffff           -lea esi, [ebp - 0x114]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-276) /* -0x114 */);
    // 00448637  ba7c8d5300             -mov edx, 0x538d7c
    cpu.edx = 5475708 /*0x538d7c*/;
    // 0044863c  e8effcffff             -call 0x448330
    cpu.esp -= 4;
    sub_448330(app, cpu);
    if (cpu.terminate) return;
    // 00448641  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00448643  e8f8a3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448648  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044864a  740d                   -je 0x448659
    if (cpu.flags.zf)
    {
        goto L_0x00448659;
    }
    // 0044864c  833db0d36f0001         +cmp dword ptr [0x6fd3b0], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7328688) /* 0x6fd3b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00448653  7e04                   -jle 0x448659
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00448659;
    }
    // 00448655  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00448659:
    // 00448659  bac48d5300             -mov edx, 0x538dc4
    cpu.edx = 5475780 /*0x538dc4*/;
    // 0044865e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00448660  e8dba3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448665  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448667  7413                   -je 0x44867c
    if (cpu.flags.zf)
    {
        goto L_0x0044867c;
    }
    // 00448669  833d4cbb6f0001         +cmp dword ptr [0x6fbb4c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7322444) /* 0x6fbb4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00448670  7506                   -jne 0x448678
    if (!cpu.flags.zf)
    {
        goto L_0x00448678;
    }
    // 00448672  806005ef               +and byte ptr [eax + 5], 0xef
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 00448676  eb04                   -jmp 0x44867c
    goto L_0x0044867c;
L_0x00448678:
    // 00448678  80480510               -or byte ptr [eax + 5], 0x10
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0044867c:
    // 0044867c  f605583a7a0006         +test byte ptr [0x7a3a58], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 6 /*0x6*/));
    // 00448683  7554                   -jne 0x4486d9
    if (!cpu.flags.zf)
    {
        goto L_0x004486d9;
    }
    // 00448685  bad08d5300             -mov edx, 0x538dd0
    cpu.edx = 5475792 /*0x538dd0*/;
    // 0044868a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044868c  e8afa3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448691  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448693  7406                   -je 0x44869b
    if (cpu.flags.zf)
    {
        goto L_0x0044869b;
    }
    // 00448695  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x0044869b:
    // 0044869b  bae48d5300             -mov edx, 0x538de4
    cpu.edx = 5475812 /*0x538de4*/;
    // 004486a0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004486a2  e899a3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004486a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004486a9  7404                   -je 0x4486af
    if (cpu.flags.zf)
    {
        goto L_0x004486af;
    }
    // 004486ab  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004486af:
    // 004486af  baf08d5300             -mov edx, 0x538df0
    cpu.edx = 5475824 /*0x538df0*/;
    // 004486b4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004486b6  e885a3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004486bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004486bd  7406                   -je 0x4486c5
    if (cpu.flags.zf)
    {
        goto L_0x004486c5;
    }
    // 004486bf  668148040110           -or word ptr [eax + 4], 0x1001
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/));
L_0x004486c5:
    // 004486c5  ba0c8e5300             -mov edx, 0x538e0c
    cpu.edx = 5475852 /*0x538e0c*/;
    // 004486ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004486cc  e86fa3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004486d1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004486d3  7404                   -je 0x4486d9
    if (cpu.flags.zf)
    {
        goto L_0x004486d9;
    }
    // 004486d5  80480401               -or byte ptr [eax + 4], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004486d9:
    // 004486d9  ba208e5300             -mov edx, 0x538e20
    cpu.edx = 5475872 /*0x538e20*/;
    // 004486de  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004486e0  e85ba3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004486e5  ba2c8e5300             -mov edx, 0x538e2c
    cpu.edx = 5475884 /*0x538e2c*/;
    // 004486ea  a3f0276600             -mov dword ptr [0x6627f0], eax
    app->getMemory<x86::reg32>(x86::reg32(6694896) /* 0x6627f0 */) = cpu.eax;
    // 004486ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004486f1  e84aa3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004486f6  8b35f0276600           -mov esi, dword ptr [0x6627f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6694896) /* 0x6627f0 */);
    // 004486fc  a3f4276600             -mov dword ptr [0x6627f4], eax
    app->getMemory<x86::reg32>(x86::reg32(6694900) /* 0x6627f4 */) = cpu.eax;
    // 00448701  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00448703  7423                   -je 0x448728
    if (cpu.flags.zf)
    {
        goto L_0x00448728;
    }
    // 00448705  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448707  741f                   -je 0x448728
    if (cpu.flags.zf)
    {
        goto L_0x00448728;
    }
    // 00448709  83bdfcfeffff00         +cmp dword ptr [ebp - 0x104], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-260) /* -0x104 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00448710  750c                   -jne 0x44871e
    if (!cpu.flags.zf)
    {
        goto L_0x0044871e;
    }
    // 00448712  804e0401               -or byte ptr [esi + 4], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00448716  668148040110           +or word ptr [eax + 4], 0x1001
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg16(x86::sreg16(4097 /*0x1001*/))));
    // 0044871c  eb0a                   -jmp 0x448728
    goto L_0x00448728;
L_0x0044871e:
    // 0044871e  806604fe               -and byte ptr [esi + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 00448722  66816004feef           -and word ptr [eax + 4], 0xeffe
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg16(x86::sreg16(61438 /*0xeffe*/));
L_0x00448728:
    // 00448728  ba3c8e5300             -mov edx, 0x538e3c
    cpu.edx = 5475900 /*0x538e3c*/;
    // 0044872d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044872f  e80ca3ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448734  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448736  7422                   -je 0x44875a
    if (cpu.flags.zf)
    {
        goto L_0x0044875a;
    }
    // 00448738  f605583a7a0040         +test byte ptr [0x7a3a58], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 64 /*0x40*/));
    // 0044873f  7506                   -jne 0x448747
    if (!cpu.flags.zf)
    {
        goto L_0x00448747;
    }
    // 00448741  80480401               +or byte ptr [eax + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00448745  eb13                   -jmp 0x44875a
    goto L_0x0044875a;
L_0x00448747:
    // 00448747  d90538bc6f00           -fld dword ptr [0x6fbc38]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(7322680) /* 0x6fbc38 */)));
    // 0044874d  ba70854400             -mov edx, 0x448570
    cpu.edx = 4490608 /*0x448570*/;
    // 00448752  d95854                 -fstp dword ptr [eax + 0x54]
    app->getMemory<float>(cpu.eax + x86::reg32(84) /* 0x54 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00448755  e866430200             -call 0x46cac0
    cpu.esp -= 4;
    sub_46cac0(app, cpu);
    if (cpu.terminate) return;
L_0x0044875a:
    // 0044875a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044875c  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044875e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044875f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448760  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448761  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448762  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448763  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448764  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_448770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448770  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00448771  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00448772  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00448773  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448774  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448775  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448777  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044877a  8b4016                 -mov eax, dword ptr [eax + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044877d  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00448780  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00448783  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00448785  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044878c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044878e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00448791  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00448793  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00448796  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044879b  833805                 +cmp dword ptr [eax], 5
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
    // 0044879e  7526                   -jne 0x4487c6
    if (!cpu.flags.zf)
    {
        goto L_0x004487c6;
    }
    // 004487a0  ba4c8e5300             -mov edx, 0x538e4c
    cpu.edx = 5475916 /*0x538e4c*/;
    // 004487a5  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004487a8  e813a2ffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004487ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004487af  7415                   -je 0x4487c6
    if (cpu.flags.zf)
    {
        goto L_0x004487c6;
    }
    // 004487b1  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004487b6  bf10bc6f00             -mov edi, 0x6fbc10
    cpu.edi = 7322640 /*0x6fbc10*/;
    // 004487bb  beb0276600             -mov esi, 0x6627b0
    cpu.esi = 6694832 /*0x6627b0*/;
    // 004487c0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004487c2  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004487c4  eb02                   -jmp 0x4487c8
    goto L_0x004487c8;
L_0x004487c6:
    // 004487c6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004487c8:
    // 004487c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004487c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004487ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004487cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004487cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004487cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4487d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004487d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004487d1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004487d3  e828e3fdff             -call 0x426b00
    cpu.esp -= 4;
    sub_426b00(app, cpu);
    if (cpu.terminate) return;
    // 004487d8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004487da  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004487db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_4487e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004487e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004487e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004487e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004487e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004487e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004487e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004487e6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004487e8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004487ea  ba688e5300             -mov edx, 0x538e68
    cpu.edx = 5475944 /*0x538e68*/;
    // 004487ef  e84ca2ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004487f4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004487f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004487f8  741a                   -je 0x448814
    if (cpu.flags.zf)
    {
        goto L_0x00448814;
    }
    // 004487fa  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00448800  83fb01                 +cmp ebx, 1
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
    // 00448803  7405                   -je 0x44880a
    if (cpu.flags.zf)
    {
        goto L_0x0044880a;
    }
    // 00448805  83fb02                 +cmp ebx, 2
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
    // 00448808  7506                   -jne 0x448810
    if (!cpu.flags.zf)
    {
        goto L_0x00448810;
    }
L_0x0044880a:
    // 0044880a  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044880e  eb04                   -jmp 0x448814
    goto L_0x00448814;
L_0x00448810:
    // 00448810  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00448814:
    // 00448814  ba808e5300             -mov edx, 0x538e80
    cpu.edx = 5475968 /*0x538e80*/;
    // 00448819  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044881b  e820a2ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448820  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00448822  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448824  741a                   -je 0x448840
    if (cpu.flags.zf)
    {
        goto L_0x00448840;
    }
    // 00448826  8b3db8d36f00           -mov edi, dword ptr [0x6fd3b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044882c  83ff01                 +cmp edi, 1
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
    // 0044882f  7405                   -je 0x448836
    if (cpu.flags.zf)
    {
        goto L_0x00448836;
    }
    // 00448831  83ff02                 +cmp edi, 2
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
    // 00448834  7506                   -jne 0x44883c
    if (!cpu.flags.zf)
    {
        goto L_0x0044883c;
    }
L_0x00448836:
    // 00448836  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044883a  eb04                   -jmp 0x448840
    goto L_0x00448840;
L_0x0044883c:
    // 0044883c  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00448840:
    // 00448840  ba988e5300             -mov edx, 0x538e98
    cpu.edx = 5475992 /*0x538e98*/;
    // 00448845  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00448847  e8f4a1ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 0044884c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044884e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448850  741a                   -je 0x44886c
    if (cpu.flags.zf)
    {
        goto L_0x0044886c;
    }
    // 00448852  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00448858  83fe01                 +cmp esi, 1
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
    // 0044885b  7405                   -je 0x448862
    if (cpu.flags.zf)
    {
        goto L_0x00448862;
    }
    // 0044885d  83fe02                 +cmp esi, 2
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
    // 00448860  7506                   -jne 0x448868
    if (!cpu.flags.zf)
    {
        goto L_0x00448868;
    }
L_0x00448862:
    // 00448862  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00448866  eb04                   -jmp 0x44886c
    goto L_0x0044886c;
L_0x00448868:
    // 00448868  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x0044886c:
    // 0044886c  bab08e5300             -mov edx, 0x538eb0
    cpu.edx = 5476016 /*0x538eb0*/;
    // 00448871  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00448873  e8c8a1ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448878  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044887a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044887c  741a                   -je 0x448898
    if (cpu.flags.zf)
    {
        goto L_0x00448898;
    }
    // 0044887e  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00448884  83fb01                 +cmp ebx, 1
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
    // 00448887  7405                   -je 0x44888e
    if (cpu.flags.zf)
    {
        goto L_0x0044888e;
    }
    // 00448889  83fb02                 +cmp ebx, 2
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
    // 0044888c  7506                   -jne 0x448894
    if (!cpu.flags.zf)
    {
        goto L_0x00448894;
    }
L_0x0044888e:
    // 0044888e  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00448892  eb04                   -jmp 0x448898
    goto L_0x00448898;
L_0x00448894:
    // 00448894  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00448898:
    // 00448898  bac48e5300             -mov edx, 0x538ec4
    cpu.edx = 5476036 /*0x538ec4*/;
    // 0044889d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044889f  e89ca1ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004488a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004488a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004488a8  741a                   -je 0x4488c4
    if (cpu.flags.zf)
    {
        goto L_0x004488c4;
    }
    // 004488aa  8b3db8d36f00           -mov edi, dword ptr [0x6fd3b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004488b0  83ff01                 +cmp edi, 1
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
    // 004488b3  7405                   -je 0x4488ba
    if (cpu.flags.zf)
    {
        goto L_0x004488ba;
    }
    // 004488b5  83ff02                 +cmp edi, 2
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
    // 004488b8  7506                   -jne 0x4488c0
    if (!cpu.flags.zf)
    {
        goto L_0x004488c0;
    }
L_0x004488ba:
    // 004488ba  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004488be  eb04                   -jmp 0x4488c4
    goto L_0x004488c4;
L_0x004488c0:
    // 004488c0  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004488c4:
    // 004488c4  badc8e5300             -mov edx, 0x538edc
    cpu.edx = 5476060 /*0x538edc*/;
    // 004488c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004488cb  e870a1ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004488d0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004488d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004488d4  741a                   -je 0x4488f0
    if (cpu.flags.zf)
    {
        goto L_0x004488f0;
    }
    // 004488d6  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004488dc  83fe01                 +cmp esi, 1
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
    // 004488df  7405                   -je 0x4488e6
    if (cpu.flags.zf)
    {
        goto L_0x004488e6;
    }
    // 004488e1  83fe02                 +cmp esi, 2
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
    // 004488e4  7506                   -jne 0x4488ec
    if (!cpu.flags.zf)
    {
        goto L_0x004488ec;
    }
L_0x004488e6:
    // 004488e6  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004488ea  eb04                   -jmp 0x4488f0
    goto L_0x004488f0;
L_0x004488ec:
    // 004488ec  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004488f0:
    // 004488f0  baf08e5300             -mov edx, 0x538ef0
    cpu.edx = 5476080 /*0x538ef0*/;
    // 004488f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004488f7  e844a1ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004488fc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004488fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448900  741a                   -je 0x44891c
    if (cpu.flags.zf)
    {
        goto L_0x0044891c;
    }
    // 00448902  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00448908  83fb01                 +cmp ebx, 1
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
    // 0044890b  7405                   -je 0x448912
    if (cpu.flags.zf)
    {
        goto L_0x00448912;
    }
    // 0044890d  83fb02                 +cmp ebx, 2
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
    // 00448910  7506                   -jne 0x448918
    if (!cpu.flags.zf)
    {
        goto L_0x00448918;
    }
L_0x00448912:
    // 00448912  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00448916  eb04                   -jmp 0x44891c
    goto L_0x0044891c;
L_0x00448918:
    // 00448918  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x0044891c:
    // 0044891c  ba088f5300             -mov edx, 0x538f08
    cpu.edx = 5476104 /*0x538f08*/;
    // 00448921  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00448923  e818a1ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448928  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044892a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044892c  741a                   -je 0x448948
    if (cpu.flags.zf)
    {
        goto L_0x00448948;
    }
    // 0044892e  8b3db8d36f00           -mov edi, dword ptr [0x6fd3b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00448934  83ff01                 +cmp edi, 1
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
    // 00448937  7405                   -je 0x44893e
    if (cpu.flags.zf)
    {
        goto L_0x0044893e;
    }
    // 00448939  83ff02                 +cmp edi, 2
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
    // 0044893c  7506                   -jne 0x448944
    if (!cpu.flags.zf)
    {
        goto L_0x00448944;
    }
L_0x0044893e:
    // 0044893e  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00448942  eb04                   -jmp 0x448948
    goto L_0x00448948;
L_0x00448944:
    // 00448944  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00448948:
    // 00448948  ba208f5300             -mov edx, 0x538f20
    cpu.edx = 5476128 /*0x538f20*/;
    // 0044894d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044894f  e8eca0ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448954  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00448956  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448958  741a                   -je 0x448974
    if (cpu.flags.zf)
    {
        goto L_0x00448974;
    }
    // 0044895a  8b35b8d36f00           -mov esi, dword ptr [0x6fd3b8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 00448960  83fe01                 +cmp esi, 1
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
    // 00448963  7405                   -je 0x44896a
    if (cpu.flags.zf)
    {
        goto L_0x0044896a;
    }
    // 00448965  83fe02                 +cmp esi, 2
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
    // 00448968  7506                   -jne 0x448970
    if (!cpu.flags.zf)
    {
        goto L_0x00448970;
    }
L_0x0044896a:
    // 0044896a  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044896e  eb04                   -jmp 0x448974
    goto L_0x00448974;
L_0x00448970:
    // 00448970  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x00448974:
    // 00448974  ba388f5300             -mov edx, 0x538f38
    cpu.edx = 5476152 /*0x538f38*/;
    // 00448979  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044897b  e8c0a0ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 00448980  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00448982  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448984  741a                   -je 0x4489a0
    if (cpu.flags.zf)
    {
        goto L_0x004489a0;
    }
    // 00448986  8b1db8d36f00           -mov ebx, dword ptr [0x6fd3b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 0044898c  83fb01                 +cmp ebx, 1
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
    // 0044898f  7405                   -je 0x448996
    if (cpu.flags.zf)
    {
        goto L_0x00448996;
    }
    // 00448991  83fb02                 +cmp ebx, 2
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
    // 00448994  7506                   -jne 0x44899c
    if (!cpu.flags.zf)
    {
        goto L_0x0044899c;
    }
L_0x00448996:
    // 00448996  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0044899a  eb04                   -jmp 0x4489a0
    goto L_0x004489a0;
L_0x0044899c:
    // 0044899c  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004489a0:
    // 004489a0  ba508f5300             -mov edx, 0x538f50
    cpu.edx = 5476176 /*0x538f50*/;
    // 004489a5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004489a7  e894a0ffff             -call 0x442a40
    cpu.esp -= 4;
    sub_442a40(app, cpu);
    if (cpu.terminate) return;
    // 004489ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004489ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004489b0  741a                   -je 0x4489cc
    if (cpu.flags.zf)
    {
        goto L_0x004489cc;
    }
    // 004489b2  8b3db8d36f00           -mov edi, dword ptr [0x6fd3b8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(7328696) /* 0x6fd3b8 */);
    // 004489b8  83ff01                 +cmp edi, 1
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
    // 004489bb  7405                   -je 0x4489c2
    if (cpu.flags.zf)
    {
        goto L_0x004489c2;
    }
    // 004489bd  83ff02                 +cmp edi, 2
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
    // 004489c0  7506                   -jne 0x4489c8
    if (!cpu.flags.zf)
    {
        goto L_0x004489c8;
    }
L_0x004489c2:
    // 004489c2  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004489c6  eb04                   -jmp 0x4489cc
    goto L_0x004489cc;
L_0x004489c8:
    // 004489c8  806004fe               -and byte ptr [eax + 4], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
L_0x004489cc:
    // 004489cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004489ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004489cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004489d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004489d1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004489d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004489d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004489d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_4489e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004489e0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004489e1  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004489e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004489e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004489e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8b 0xc0 */
/* data blob: 00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 */
void Application::sub_448f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00448f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00448f02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00448f03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448f04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448f05  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448f07  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00448f09  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00448f0b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00448f0d:
    // 00448f0d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00448f0f  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00448f12  83bb107c550000         +cmp dword ptr [ebx + 0x557c10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5602320) /* 0x557c10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00448f19  7427                   -je 0x448f42
    if (cpu.flags.zf)
    {
        goto L_0x00448f42;
    }
    // 00448f1b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00448f1d  8b93147c5500           -mov edx, dword ptr [ebx + 0x557c14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5602324) /* 0x557c14 */);
    // 00448f23  e8e8530a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00448f28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00448f2a  7513                   -jne 0x448f3f
    if (!cpu.flags.zf)
    {
        goto L_0x00448f3f;
    }
    // 00448f2c  8b83107c5500           -mov eax, dword ptr [ebx + 0x557c10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5602320) /* 0x557c10 */);
    // 00448f32  39c7                   +cmp edi, eax
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
    // 00448f34  7405                   -je 0x448f3b
    if (cpu.flags.zf)
    {
        goto L_0x00448f3b;
    }
    // 00448f36  83f801                 +cmp eax, 1
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
    // 00448f39  7504                   -jne 0x448f3f
    if (!cpu.flags.zf)
    {
        goto L_0x00448f3f;
    }
L_0x00448f3b:
    // 00448f3b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00448f3d  eb08                   -jmp 0x448f47
    goto L_0x00448f47;
L_0x00448f3f:
    // 00448f3f  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00448f40  ebcb                   -jmp 0x448f0d
    goto L_0x00448f0d;
L_0x00448f42:
    // 00448f42  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00448f47:
    // 00448f47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448f48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448f49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448f4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448f4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448f4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_448f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448f50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00448f51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00448f52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00448f53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00448f54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00448f55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448f56  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448f58  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00448f5a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00448f5c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00448f5e  49                     -dec ecx
    (cpu.ecx)--;
    // 00448f5f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00448f61  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00448f63  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00448f65  49                     -dec ecx
    (cpu.ecx)--;
    // 00448f66  a1a80b6600             -mov eax, dword ptr [0x660ba8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6687656) /* 0x660ba8 */);
    // 00448f6b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00448f6d  40                     -inc eax
    (cpu.eax)++;
    // 00448f6e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00448f70  3d00000100             +cmp eax, 0x10000
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
    // 00448f75  7344                   -jae 0x448fbb
    if (!cpu.flags.cf)
    {
        goto L_0x00448fbb;
    }
    // 00448f77  bbd0405f00             -mov ebx, 0x5f40d0
    cpu.ebx = 6242512 /*0x5f40d0*/;
    // 00448f7c  031da80b6600           -add ebx, dword ptr [0x660ba8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687656) /* 0x660ba8 */)));
    // 00448f82  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00448f84  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00448f86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00448f87:
    // 00448f87  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00448f89  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00448f8b  3c00                   +cmp al, 0
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
    // 00448f8d  7410                   -je 0x448f9f
    if (cpu.flags.zf)
    {
        goto L_0x00448f9f;
    }
    // 00448f8f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00448f92  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00448f95  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00448f98  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00448f9b  3c00                   +cmp al, 0
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
    // 00448f9d  75e8                   -jne 0x448f87
    if (!cpu.flags.zf)
    {
        goto L_0x00448f87;
    }
L_0x00448f9f:
    // 00448f9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448fa0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00448fa2  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00448fa4  49                     -dec ecx
    (cpu.ecx)--;
    // 00448fa5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00448fa7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00448fa9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00448fab  49                     -dec ecx
    (cpu.ecx)--;
    // 00448fac  8b35a80b6600           -mov esi, dword ptr [0x660ba8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6687656) /* 0x660ba8 */);
    // 00448fb2  41                     -inc ecx
    (cpu.ecx)++;
    // 00448fb3  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00448fb5  8935a80b6600           -mov dword ptr [0x660ba8], esi
    app->getMemory<x86::reg32>(x86::reg32(6687656) /* 0x660ba8 */) = cpu.esi;
L_0x00448fbb:
    // 00448fbb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00448fbd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448fbe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448fbf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448fc0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448fc1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448fc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00448fc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_448fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00448fd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00448fd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00448fd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00448fd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00448fd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00448fd5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00448fd7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00448fd9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00448fdb:
    // 00448fdb  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00448fe2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00448fe4  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00448feb  83be847a550000         +cmp dword ptr [esi + 0x557a84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5601924) /* 0x557a84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00448ff2  741c                   -je 0x449010
    if (cpu.flags.zf)
    {
        goto L_0x00449010;
    }
    // 00448ff4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00448ff6  8b96887a5500           -mov edx, dword ptr [esi + 0x557a88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5601928) /* 0x557a88 */);
    // 00448ffc  e80f530a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00449001  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449003  7508                   -jne 0x44900d
    if (!cpu.flags.zf)
    {
        goto L_0x0044900d;
    }
    // 00449005  8b86847a5500           -mov eax, dword ptr [esi + 0x557a84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5601924) /* 0x557a84 */);
    // 0044900b  eb08                   -jmp 0x449015
    goto L_0x00449015;
L_0x0044900d:
    // 0044900d  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044900e  ebcb                   -jmp 0x448fdb
    goto L_0x00448fdb;
L_0x00449010:
    // 00449010  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00449015:
    // 00449015  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449016  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449017  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449018  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449019  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044901a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_449020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449021  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449022  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449023  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449024  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449026  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00449028  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044902a:
    // 0044902a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449031  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449033  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449036  8b88847a5500           -mov ecx, dword ptr [eax + 0x557a84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5601924) /* 0x557a84 */);
    // 0044903c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044903e  7412                   -je 0x449052
    if (cpu.flags.zf)
    {
        goto L_0x00449052;
    }
    // 00449040  39cb                   +cmp ebx, ecx
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
    // 00449042  750b                   -jne 0x44904f
    if (!cpu.flags.zf)
    {
        goto L_0x0044904f;
    }
    // 00449044  8b80887a5500           -mov eax, dword ptr [eax + 0x557a88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5601928) /* 0x557a88 */);
    // 0044904a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044904b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044904c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044904d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044904e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044904f:
    // 0044904f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00449050  ebd8                   -jmp 0x44902a
    goto L_0x0044902a;
L_0x00449052:
    // 00449052  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00449054  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449055  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449056  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449057  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449058  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_449060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449060  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449061  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449062  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449063  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449064  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449065  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449067  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00449069  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0044906b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0044906d:
    // 0044906d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449074  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449076  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449079  8b98847a5500           -mov ebx, dword ptr [eax + 0x557a84]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5601924) /* 0x557a84 */);
    // 0044907f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00449081  7407                   -je 0x44908a
    if (cpu.flags.zf)
    {
        goto L_0x0044908a;
    }
    // 00449083  39df                   +cmp edi, ebx
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
    // 00449085  7403                   -je 0x44908a
    if (cpu.flags.zf)
    {
        goto L_0x0044908a;
    }
    // 00449087  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00449088  ebe3                   -jmp 0x44906d
    goto L_0x0044906d;
L_0x0044908a:
    // 0044908a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449091  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449093  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449096  83b8847a550000         +cmp dword ptr [eax + 0x557a84], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5601924) /* 0x557a84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044909d  7433                   -je 0x4490d2
    if (cpu.flags.zf)
    {
        goto L_0x004490d2;
    }
    // 0044909f  8bb08c7a5500           -mov esi, dword ptr [eax + 0x557a8c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5601932) /* 0x557a8c */);
    // 004490a5  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004490ac  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004490ae  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004490b1  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004490b3  bfe04e6000             -mov edi, 0x604ee0
    cpu.edi = 6311648 /*0x604ee0*/;
    // 004490b8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004490bb  b9bc000000             -mov ecx, 0xbc
    cpu.ecx = 188 /*0xbc*/;
    // 004490c0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004490c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004490c3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004490c5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004490c8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004490ca  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004490cc  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004490cf  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004490d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004490d2:
    // 004490d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004490d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004490d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004490d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004490d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004490d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8b 0xd2 */
void Application::sub_4490e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004490e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004490e1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004490e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004490e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004490e4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004490e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004490e8  80385b                 +cmp byte ptr [eax], 0x5b
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(91 /*0x5b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004490eb  7535                   -jne 0x449122
    if (!cpu.flags.zf)
    {
        goto L_0x00449122;
    }
    // 004490ed  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004490ef  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004490f1  49                     -dec ecx
    (cpu.ecx)--;
    // 004490f2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004490f4  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004490f6  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004490f8  49                     -dec ecx
    (cpu.ecx)--;
    // 004490f9  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 004490fc  8078ff5d               +cmp byte ptr [eax - 1], 0x5d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(93 /*0x5d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00449100  7520                   -jne 0x449122
    if (!cpu.flags.zf)
    {
        goto L_0x00449122;
    }
    // 00449102  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00449104  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449106  49                     -dec ecx
    (cpu.ecx)--;
    // 00449107  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00449109  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044910b  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0044910d  49                     -dec ecx
    (cpu.ecx)--;
    // 0044910e  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 00449111  c640ff00               -mov byte ptr [eax - 1], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = 0 /*0x0*/;
    // 00449115  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00449118  e8b3feffff             -call 0x448fd0
    cpu.esp -= 4;
    sub_448fd0(app, cpu);
    if (cpu.terminate) return;
    // 0044911d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044911e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044911f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449120  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449121  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00449122:
    // 00449122  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00449127  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449128  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449129  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044912a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044912b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x44 0x20 0x00 */
void Application::sub_449130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449130  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449131  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449132  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449133  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449135  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449137  e8f4720a00             -call 0x4f0430
    cpu.esp -= 4;
    sub_4f0430(app, cpu);
    if (cpu.terminate) return;
    // 0044913c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044913e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00449140:
    // 00449140  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00449142  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00449144  741a                   -je 0x449160
    if (cpu.flags.zf)
    {
        goto L_0x00449160;
    }
    // 00449146  fec2                   -inc dl
    (cpu.dl)++;
    // 00449148  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0044914e  f682f04e560020         +test byte ptr [edx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 00449155  7506                   -jne 0x44915d
    if (!cpu.flags.zf)
    {
        goto L_0x0044915d;
    }
    // 00449157  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00449159  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044915a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044915b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044915c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044915d:
    // 0044915d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044915e  ebe0                   -jmp 0x449140
    goto L_0x00449140;
L_0x00449160:
    // 00449160  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00449162  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449163  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449164  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449165  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_449170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449170  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449172  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449173  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449175  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449177  e814730a00             -call 0x4f0490
    cpu.esp -= 4;
    sub_4f0490(app, cpu);
    if (cpu.terminate) return;
    // 0044917c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044917e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00449180:
    // 00449180  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00449182  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00449184  741a                   -je 0x4491a0
    if (cpu.flags.zf)
    {
        goto L_0x004491a0;
    }
    // 00449186  fec2                   -inc dl
    (cpu.dl)++;
    // 00449188  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0044918e  f682f04e560020         +test byte ptr [edx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 00449195  7506                   -jne 0x44919d
    if (!cpu.flags.zf)
    {
        goto L_0x0044919d;
    }
    // 00449197  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00449199  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044919a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044919b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044919c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044919d:
    // 0044919d  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044919e  ebe0                   -jmp 0x449180
    goto L_0x00449180;
L_0x004491a0:
    // 004491a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004491a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004491a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004491a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004491a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_4491b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004491b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004491b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004491b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004491b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004491b4  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004491b6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004491b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004491bb  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004491be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004491bf  68708f5300             -push 0x538f70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5476208 /*0x538f70*/;
    cpu.esp -= 4;
    // 004491c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004491c5  e87e730a00             -call 0x4f0548
    cpu.esp -= 4;
    sub_4f0548(app, cpu);
    if (cpu.terminate) return;
    // 004491ca  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004491cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004491cf  7437                   -je 0x449208
    if (cpu.flags.zf)
    {
        goto L_0x00449208;
    }
    // 004491d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004491d3:
    // 004491d3  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004491d5  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004491d7  742c                   -je 0x449205
    if (cpu.flags.zf)
    {
        goto L_0x00449205;
    }
    // 004491d9  fec2                   -inc dl
    (cpu.dl)++;
    // 004491db  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004491e1  f682f04e560020         +test byte ptr [edx + 0x564ef0], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5656304) /* 0x564ef0 */) & 32 /*0x20*/));
    // 004491e8  7518                   -jne 0x449202
    if (!cpu.flags.zf)
    {
        goto L_0x00449202;
    }
    // 004491ea  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 004491ec  80ff2e                 +cmp bh, 0x2e
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004491ef  7411                   -je 0x449202
    if (cpu.flags.zf)
    {
        goto L_0x00449202;
    }
    // 004491f1  80ff30                 +cmp bh, 0x30
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004491f4  740c                   -je 0x449202
    if (cpu.flags.zf)
    {
        goto L_0x00449202;
    }
    // 004491f6  80ff2d                 +cmp bh, 0x2d
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004491f9  7407                   -je 0x449202
    if (cpu.flags.zf)
    {
        goto L_0x00449202;
    }
    // 004491fb  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004491fd  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 00449200  eb09                   -jmp 0x44920b
    goto L_0x0044920b;
L_0x00449202:
    // 00449202  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00449203  ebce                   -jmp 0x4491d3
    goto L_0x004491d3;
L_0x00449205:
    // 00449205  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x00449208:
    // 00449208  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x0044920b:
    // 0044920b  d945fc                 -fld dword ptr [ebp - 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 0044920e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00449210  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449211  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449212  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449213  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449214  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_449240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00449240  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449241  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449242  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449243  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449244  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449246  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 00449249  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044924b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044924d  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0044924f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00449251  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 00449258  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044925a  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044925c  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0044925f  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00449262  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00449265  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00449267  8b8e1c7c5500           -mov ecx, dword ptr [esi + 0x557c1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5602332) /* 0x557c1c */);
    // 0044926d  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00449270  81e9e04e6000           -sub ecx, 0x604ee0
    (cpu.ecx) -= x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 00449276  81c2e04e6000           -add edx, 0x604ee0
    (cpu.edx) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044927c  8d3c0a                 -lea edi, [edx + ecx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0044927f  8b96187c5500           -mov edx, dword ptr [esi + 0x557c18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5602328) /* 0x557c18 */);
    // 00449285  83fa06                 +cmp edx, 6
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
    // 00449288  0f8715010000           -ja 0x4493a3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004493a3;
    }
    // 0044928e  ff249518924400         -jmp dword ptr [edx*4 + 0x449218]
    cpu.ip = app->getMemory<x86::reg32>(4493848 + cpu.edx * 4); goto dynamic_jump;
  case 0x00449295:
    // 00449295  e896feffff             -call 0x449130
    cpu.esp -= 4;
    sub_449130(app, cpu);
    if (cpu.terminate) return;
    // 0044929a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0044929f  8d75fc                 -lea esi, [ebp - 4]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004492a2  8845fc                 -mov byte ptr [ebp - 4], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 004492a5  e9e9000000             -jmp 0x449393
    goto L_0x00449393;
  case 0x004492aa:
    // 004492aa  e881feffff             -call 0x449130
    cpu.esp -= 4;
    sub_449130(app, cpu);
    if (cpu.terminate) return;
    // 004492af  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004492b4  8d75f8                 -lea esi, [ebp - 8]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004492b7  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004492ba  e9d4000000             -jmp 0x449393
    goto L_0x00449393;
  case 0x004492bf:
    // 004492bf  e86cfeffff             -call 0x449130
    cpu.esp -= 4;
    sub_449130(app, cpu);
    if (cpu.terminate) return;
    // 004492c4  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004492c9  8d75e8                 -lea esi, [ebp - 0x18]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004492cc  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 004492cf  e9bf000000             -jmp 0x449393
    goto L_0x00449393;
  case 0x004492d4:
    // 004492d4  e897feffff             -call 0x449170
    cpu.esp -= 4;
    sub_449170(app, cpu);
    if (cpu.terminate) return;
    // 004492d9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004492de  8d75ec                 -lea esi, [ebp - 0x14]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004492e1  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004492e4  e9aa000000             -jmp 0x449393
    goto L_0x00449393;
  case 0x004492e9:
    // 004492e9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004492eb  ba748f5300             -mov edx, 0x538f74
    cpu.edx = 5476212 /*0x538f74*/;
    // 004492f0  895df4                 -mov dword ptr [ebp - 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ebx;
    // 004492f3  e858fcffff             -call 0x448f50
    cpu.esp -= 4;
    sub_448f50(app, cpu);
    if (cpu.terminate) return;
    // 004492f8  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004492fb  e820750900             -call 0x4e0820
    cpu.esp -= 4;
    sub_4e0820(app, cpu);
    if (cpu.terminate) return;
    // 00449300  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00449303  39f0                   +cmp eax, esi
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
    // 00449305  7411                   -je 0x449318
    if (cpu.flags.zf)
    {
        goto L_0x00449318;
    }
    // 00449307  ba7c8f5300             -mov edx, 0x538f7c
    cpu.edx = 5476220 /*0x538f7c*/;
    // 0044930c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044930e  e80d750900             -call 0x4e0820
    cpu.esp -= 4;
    sub_4e0820(app, cpu);
    if (cpu.terminate) return;
    // 00449313  3b45f0                 +cmp eax, dword ptr [ebp - 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449316  752a                   -jne 0x449342
    if (!cpu.flags.zf)
    {
        goto L_0x00449342;
    }
L_0x00449318:
    // 00449318  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044931a  eb09                   -jmp 0x449325
    goto L_0x00449325;
L_0x0044931c:
    // 0044931c  43                     -inc ebx
    (cpu.ebx)++;
    // 0044931d  81fb89070000           +cmp ebx, 0x789
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1929 /*0x789*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449323  7d1d                   -jge 0x449342
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00449342;
    }
L_0x00449325:
    // 00449325  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00449328  8b149d441c5600         -mov edx, dword ptr [ebx*4 + 0x561c44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643332) /* 0x561c44 */ + cpu.ebx * 4);
    // 0044932f  e8dc4f0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00449334  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449336  75e4                   -jne 0x44931c
    if (!cpu.flags.zf)
    {
        goto L_0x0044931c;
    }
    // 00449338  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044933a  e811850800             -call 0x4d1850
    cpu.esp -= 4;
    sub_4d1850(app, cpu);
    if (cpu.terminate) return;
    // 0044933f  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x00449342:
    // 00449342  837df400               +cmp dword ptr [ebp - 0xc], 0
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
    // 00449346  740a                   -je 0x449352
    if (cpu.flags.zf)
    {
        goto L_0x00449352;
    }
    // 00449348  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044934d  8d75f4                 -lea esi, [ebp - 0xc]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00449350  eb08                   -jmp 0x44935a
    goto L_0x0044935a;
L_0x00449352:
    // 00449352  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00449357  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
L_0x0044935a:
    // 0044935a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044935b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044935d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00449360  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00449362  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00449364  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00449367  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00449369  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044936a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044936c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044936d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044936e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044936f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449370  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00449371:
    // 00449371  e8dafbffff             -call 0x448f50
    cpu.esp -= 4;
    sub_448f50(app, cpu);
    if (cpu.terminate) return;
    // 00449376  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044937b  8d75f0                 -lea esi, [ebp - 0x10]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0044937e  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00449381  eb10                   -jmp 0x449393
    goto L_0x00449393;
  case 0x00449383:
    // 00449383  e828feffff             -call 0x4491b0
    cpu.esp -= 4;
    sub_4491b0(app, cpu);
    if (cpu.terminate) return;
    // 00449388  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0044938d  8d75e4                 -lea esi, [ebp - 0x1c]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 00449390  d95de4                 -fstp dword ptr [ebp - 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x00449393:
    // 00449393  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449394  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00449396  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00449399  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0044939b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0044939d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004493a0  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004493a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004493a3:
    // 004493a3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004493a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004493a9  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_4493b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004493b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004493b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004493b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004493b3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004493b5  81ec14050000           -sub esp, 0x514
    (cpu.esp) -= x86::reg32(x86::sreg32(1300 /*0x514*/));
    // 004493bb  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004493be  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004493c1  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004493c4  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 004493c7  b940010000             -mov ecx, 0x140
    cpu.ecx = 320 /*0x140*/;
    // 004493cc  8dbdecfaffff           -lea edi, [ebp - 0x514]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 004493d2  bef0894400             -mov esi, 0x4489f0
    cpu.esi = 4491760 /*0x4489f0*/;
    // 004493d7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004493d9  66a5                   -movsw word ptr es:[edi], word ptr [esi]
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
L_0x004493db:
    // 004493db  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004493de  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004493e1  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004493e4  8b5df0                 -mov ebx, dword ptr [ebp - 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004493e7  ba01050000             -mov edx, 0x501
    cpu.edx = 1281 /*0x501*/;
    // 004493ec  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004493ef  8d85ecfaffff           -lea eax, [ebp - 0x514]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 004493f5  e876710a00             -call 0x4f0570
    cpu.esp -= 4;
    sub_4f0570(app, cpu);
    if (cpu.terminate) return;
    // 004493fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004493fc  0f84fc000000           -je 0x4494fe
    if (cpu.flags.zf)
    {
        goto L_0x004494fe;
    }
    // 00449402  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00449405  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00449407  42                     -inc edx
    (cpu.edx)++;
    // 00449408  8dbdecfaffff           -lea edi, [ebp - 0x514]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 0044940e  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00449410  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449412  49                     -dec ecx
    (cpu.ecx)--;
    // 00449413  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00449415  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00449417  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00449419  49                     -dec ecx
    (cpu.ecx)--;
    // 0044941a  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
L_0x0044941d:
    // 0044941d  83f8ff                 +cmp eax, -1
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
    // 00449420  7e1d                   -jle 0x44943f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044943f;
    }
    // 00449422  8a9428ecfaffff         -mov dl, byte ptr [eax + ebp - 0x514]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
    // 00449429  80fa0a                 +cmp dl, 0xa
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044942c  7405                   -je 0x449433
    if (cpu.flags.zf)
    {
        goto L_0x00449433;
    }
    // 0044942e  80fa0d                 +cmp dl, 0xd
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
    // 00449431  7509                   -jne 0x44943c
    if (!cpu.flags.zf)
    {
        goto L_0x0044943c;
    }
L_0x00449433:
    // 00449433  30db                   +xor bl, bl
    cpu.clear_co();
    cpu.set_szp((cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl))));
    // 00449435  889c28ecfaffff         -mov byte ptr [eax + ebp - 0x514], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1) = cpu.bl;
L_0x0044943c:
    // 0044943c  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044943d  ebde                   -jmp 0x44941d
    goto L_0x0044941d;
L_0x0044943f:
    // 0044943f  8dbdecfaffff           -lea edi, [ebp - 0x514]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
    // 00449445  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449447  49                     -dec ecx
    (cpu.ecx)--;
    // 00449448  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044944a  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044944c  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0044944e  49                     -dec ecx
    (cpu.ecx)--;
    // 0044944f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00449451  7502                   -jne 0x449455
    if (!cpu.flags.zf)
    {
        goto L_0x00449455;
    }
    // 00449453  eb86                   -jmp 0x4493db
    goto L_0x004493db;
L_0x00449455:
    // 00449455  80bdecfaffff3b         +cmp byte ptr [ebp - 0x514], 0x3b
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-1300) /* -0x514 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(59 /*0x3b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044945c  7505                   -jne 0x449463
    if (!cpu.flags.zf)
    {
        goto L_0x00449463;
    }
    // 0044945e  e978ffffff             -jmp 0x4493db
    goto L_0x004493db;
L_0x00449463:
    // 00449463  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00449465  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00449467:
    // 00449467  8a8c28ecfaffff         -mov cl, byte ptr [eax + ebp - 0x514]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
    // 0044946e  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00449470  7422                   -je 0x449494
    if (cpu.flags.zf)
    {
        goto L_0x00449494;
    }
    // 00449472  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449475  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00449477  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00449479  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0044947b  40                     -inc eax
    (cpu.eax)++;
    // 0044947c  42                     -inc edx
    (cpu.edx)++;
    // 0044947d  8819                   -mov byte ptr [ecx], bl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bl;
    // 0044947f  80fb3d                 +cmp bl, 0x3d
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00449482  7503                   -jne 0x449487
    if (!cpu.flags.zf)
    {
        goto L_0x00449487;
    }
    // 00449484  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00449485  eb0d                   -jmp 0x449494
    goto L_0x00449494;
L_0x00449487:
    // 00449487  80fb20                 +cmp bl, 0x20
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
    // 0044948a  7405                   -je 0x449491
    if (cpu.flags.zf)
    {
        goto L_0x00449491;
    }
    // 0044948c  80fb09                 +cmp bl, 9
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044948f  75d6                   -jne 0x449467
    if (!cpu.flags.zf)
    {
        goto L_0x00449467;
    }
L_0x00449491:
    // 00449491  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00449492  ebd3                   -jmp 0x449467
    goto L_0x00449467;
L_0x00449494:
    // 00449494  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449497  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449499  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
    // 0044949c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044949e  7505                   -jne 0x4494a5
    if (!cpu.flags.zf)
    {
        goto L_0x004494a5;
    }
    // 004494a0  e936ffffff             -jmp 0x4493db
    goto L_0x004493db;
L_0x004494a5:
    // 004494a5  80bc28ecfaffff00       +cmp byte ptr [eax + ebp - 0x514], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004494ad  7510                   -jne 0x4494bf
    if (!cpu.flags.zf)
    {
        goto L_0x004494bf;
    }
    // 004494af  8079ff5d               +cmp byte ptr [ecx - 1], 0x5d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(93 /*0x5d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004494b3  740a                   -je 0x4494bf
    if (cpu.flags.zf)
    {
        goto L_0x004494bf;
    }
    // 004494b5  e8666c0a00             -call 0x4f0120
    cpu.esp -= 4;
    sub_4f0120(app, cpu);
    if (cpu.terminate) return;
    // 004494ba  e91cffffff             -jmp 0x4493db
    goto L_0x004493db;
L_0x004494bf:
    // 004494bf  8a9c28ecfaffff         -mov bl, byte ptr [eax + ebp - 0x514]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
    // 004494c6  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004494c8  7410                   -je 0x4494da
    if (cpu.flags.zf)
    {
        goto L_0x004494da;
    }
    // 004494ca  40                     -inc eax
    (cpu.eax)++;
    // 004494cb  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 004494cd  80fb20                 +cmp bl, 0x20
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
    // 004494d0  74ed                   -je 0x4494bf
    if (cpu.flags.zf)
    {
        goto L_0x004494bf;
    }
    // 004494d2  80fb09                 +cmp bl, 9
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004494d5  7502                   -jne 0x4494d9
    if (!cpu.flags.zf)
    {
        goto L_0x004494d9;
    }
    // 004494d7  ebe6                   -jmp 0x4494bf
    goto L_0x004494bf;
L_0x004494d9:
    // 004494d9  48                     -dec eax
    (cpu.eax)--;
L_0x004494da:
    // 004494da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004494dc:
    // 004494dc  8abc28ecfaffff         -mov bh, byte ptr [eax + ebp - 0x514]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1300) /* -0x514 */ + cpu.ebp * 1);
    // 004494e3  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004494e5  740d                   -je 0x4494f4
    if (cpu.flags.zf)
    {
        goto L_0x004494f4;
    }
    // 004494e7  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004494ea  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004494ec  01f9                   +add ecx, edi
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
    // 004494ee  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004494ef  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004494f0  8839                   -mov byte ptr [ecx], bh
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.bh;
    // 004494f2  ebe8                   -jmp 0x4494dc
    goto L_0x004494dc;
L_0x004494f4:
    // 004494f4  0355f8                 -add edx, dword ptr [ebp - 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004494f7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004494fc  883a                   -mov byte ptr [edx], bh
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bh;
L_0x004494fe:
    // 004494fe  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00449500  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449501  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449502  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449503  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 */
void Application::sub_449510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449510  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449511  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449512  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449513  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449514  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449515  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449517  81ec0c060000           -sub esp, 0x60c
    (cpu.esp) -= x86::reg32(x86::sreg32(1548 /*0x60c*/));
    // 0044951d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044951f  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00449522  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00449524  7441                   -je 0x449567
    if (cpu.flags.zf)
    {
        goto L_0x00449567;
    }
    // 00449526  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0044952b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044952d  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044952f  891dac0b6600           -mov dword ptr [0x660bac], ebx
    app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */) = cpu.ebx;
    // 00449535  890da80b6600           -mov dword ptr [0x660ba8], ecx
    app->getMemory<x86::reg32>(x86::reg32(6687656) /* 0x660ba8 */) = cpu.ecx;
    // 0044953b  890db00b6600           -mov dword ptr [0x660bb0], ecx
    app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */) = cpu.ecx;
    // 00449541  eb08                   -jmp 0x44954b
    goto L_0x0044954b;
L_0x00449543:
    // 00449543  81fad0070000           +cmp edx, 0x7d0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2000 /*0x7d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449549  7d50                   -jge 0x44959b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044959b;
    }
L_0x0044954b:
    // 0044954b  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0044954d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449554  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449556  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449559  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044955b  31d1                   +xor ecx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0044955d  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044955e  890c85e04e6000         -mov dword ptr [eax*4 + 0x604ee0], ecx
    app->getMemory<x86::reg32>(x86::reg32(6311648) /* 0x604ee0 */ + cpu.eax * 4) = cpu.ecx;
    // 00449565  ebdc                   -jmp 0x449543
    goto L_0x00449543;
L_0x00449567:
    // 00449567  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00449569:
    // 00449569  3b0db00b6600           +cmp ecx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044956f  7d1e                   -jge 0x44958f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044958f;
    }
    // 00449571  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00449578  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0044957a  8b1485e4406000         -mov edx, dword ptr [eax*4 + 0x6040e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6308068) /* 0x6040e4 */ + cpu.eax * 4);
    // 00449581  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00449583  e8884d0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00449588  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044958a  7403                   -je 0x44958f
    if (cpu.flags.zf)
    {
        goto L_0x0044958f;
    }
    // 0044958c  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044958d  ebda                   -jmp 0x449569
    goto L_0x00449569;
L_0x0044958f:
    // 0044958f  3b0db00b6600           +cmp ecx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449595  0f8ce9020000           -jl 0x449884
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00449884;
    }
L_0x0044959b:
    // 0044959b  8b15b00b6600           -mov edx, dword ptr [0x660bb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 004495a1  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004495a8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004495aa  bb24000000             -mov ebx, 0x24
    cpu.ebx = 36 /*0x24*/;
    // 004495af  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004495b2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004495b4  05d0406000             -add eax, 0x6040d0
    (cpu.eax) += x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
    // 004495b9  e882700900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004495be  8b15b00b6600           -mov edx, dword ptr [0x660bb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 004495c4  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004495cb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004495cd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004495d0  42                     -inc edx
    (cpu.edx)++;
    // 004495d1  89b0e4406000           -mov dword ptr [eax + 0x6040e4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6308068) /* 0x6040e4 */) = cpu.esi;
    // 004495d7  05d0406000             -add eax, 0x6040d0
    (cpu.eax) += x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
    // 004495dc  8915b00b6600           -mov dword ptr [0x660bb0], edx
    app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */) = cpu.edx;
    // 004495e2  e82995ffff             -call 0x442b10
    cpu.esp -= 4;
    sub_442b10(app, cpu);
    if (cpu.terminate) return;
    // 004495e7  a1b00b6600             -mov eax, dword ptr [0x660bb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 004495ec  48                     -dec eax
    (cpu.eax)--;
    // 004495ed  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
L_0x004495f0:
    // 004495f0  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004495f3  3b05b00b6600           +cmp eax, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004495f9  0f8d62020000           -jge 0x449861
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00449861;
    }
    // 004495ff  be848f5300             -mov esi, 0x538f84
    cpu.esi = 5476228 /*0x538f84*/;
    // 00449604  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449607  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0044960d  8d1cd500000000         -lea ebx, [edx*8]
    cpu.ebx = x86::reg32(cpu.edx * 8);
    // 00449614  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00449615:
    // 00449615  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00449617  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00449619  3c00                   +cmp al, 0
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
    // 0044961b  7410                   -je 0x44962d
    if (cpu.flags.zf)
    {
        goto L_0x0044962d;
    }
    // 0044961d  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00449620  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00449623  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00449626  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00449629  3c00                   +cmp al, 0
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
    // 0044962b  75e8                   -jne 0x449615
    if (!cpu.flags.zf)
    {
        goto L_0x00449615;
    }
L_0x0044962d:
    // 0044962d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044962e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449630  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449636  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00449639  e862930000             -call 0x4529a0
    cpu.esp -= 4;
    sub_4529a0(app, cpu);
    if (cpu.terminate) return;
    // 0044963e  8b8be4406000           -mov ecx, dword ptr [ebx + 0x6040e4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6308068) /* 0x6040e4 */);
    // 00449644  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449645  68948f5300             -push 0x538f94
    app->getMemory<x86::reg32>(cpu.esp-4) = 5476244 /*0x538f94*/;
    cpu.esp -= 4;
    // 0044964a  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449650  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449652  49                     -dec ecx
    (cpu.ecx)--;
    // 00449653  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00449655  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00449657  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00449659  49                     -dec ecx
    (cpu.ecx)--;
    // 0044965a  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449660  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00449662  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00449663  e828600900             -call 0x4df690
    cpu.esp -= 4;
    sub_4df690(app, cpu);
    if (cpu.terminate) return;
    // 00449668  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044966b  ba9c8f5300             -mov edx, 0x538f9c
    cpu.edx = 5476252 /*0x538f9c*/;
    // 00449670  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449676  e86d490a00             -call 0x4edfe8
    cpu.esp -= 4;
    sub_4edfe8(app, cpu);
    if (cpu.terminate) return;
    // 0044967b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044967d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044967f  7509                   -jne 0x44968a
    if (!cpu.flags.zf)
    {
        goto L_0x0044968a;
    }
    // 00449681  837df800               +cmp dword ptr [ebp - 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449685  e9cf010000             -jmp 0x449859
    goto L_0x00449859;
L_0x0044968a:
    // 0044968a  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00449690  a31c925500             -mov dword ptr [0x55921c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607964) /* 0x55921c */) = cpu.eax;
    // 00449695  66a1ac0b6600           -mov ax, word ptr [0x660bac]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(6687660) /* 0x660bac */);
    // 0044969b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0044969d  40                     -inc eax
    (cpu.eax)++;
    // 0044969e  897df4                 -mov dword ptr [ebp - 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edi;
    // 004496a1  668983e8406000         -mov word ptr [ebx + 0x6040e8], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6308072) /* 0x6040e8 */) = cpu.ax;
L_0x004496a8:
    // 004496a8  8d4df4                 -lea ecx, [ebp - 0xc]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004496ab  8d9df4f9ffff           -lea ebx, [ebp - 0x60c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-1548) /* -0x60c */);
    // 004496b1  8d95f4fdffff           -lea edx, [ebp - 0x20c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-524) /* -0x20c */);
    // 004496b7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004496b9  e8f2fcffff             -call 0x4493b0
    cpu.esp -= 4;
    sub_4493b0(app, cpu);
    if (cpu.terminate) return;
    // 004496be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004496c0  0f8476010000           -je 0x44983c
    if (cpu.flags.zf)
    {
        goto L_0x0044983c;
    }
    // 004496c6  8d85f4fdffff           -lea eax, [ebp - 0x20c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-524) /* -0x20c */);
    // 004496cc  e80ffaffff             -call 0x4490e0
    cpu.esp -= 4;
    sub_4490e0(app, cpu);
    if (cpu.terminate) return;
    // 004496d1  83f8ff                 +cmp eax, -1
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
    // 004496d4  7422                   -je 0x4496f8
    if (cpu.flags.zf)
    {
        goto L_0x004496f8;
    }
    // 004496d6  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 004496dc  81fad0070000           +cmp edx, 0x7d0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2000 /*0x7d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004496e2  7dc4                   -jge 0x4496a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004496a8;
    }
    // 004496e4  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004496e7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004496e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004496eb  890dac0b6600           -mov dword ptr [0x660bac], ecx
    app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */) = cpu.ecx;
    // 004496f1  e86af9ffff             -call 0x449060
    cpu.esp -= 4;
    sub_449060(app, cpu);
    if (cpu.terminate) return;
    // 004496f6  ebb0                   -jmp 0x4496a8
    goto L_0x004496a8;
L_0x004496f8:
    // 004496f8  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 004496fe  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449705  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449707  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044970a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044970c  8b1485e04e6000         -mov edx, dword ptr [eax*4 + 0x604ee0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6311648) /* 0x604ee0 */ + cpu.eax * 4);
    // 00449713  8d85f4fdffff           -lea eax, [ebp - 0x20c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-524) /* -0x20c */);
    // 00449719  e8e2f7ffff             -call 0x448f00
    cpu.esp -= 4;
    sub_448f00(app, cpu);
    if (cpu.terminate) return;
    // 0044971e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00449720  83f8ff                 +cmp eax, -1
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
    // 00449723  7483                   -je 0x4496a8
    if (cpu.flags.zf)
    {
        goto L_0x004496a8;
    }
    // 00449725  8d9df4f9ffff           -lea ebx, [ebp - 0x60c]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-1548) /* -0x60c */);
    // 0044972b  a1ac0b6600             -mov eax, dword ptr [0x660bac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 00449730  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00449732  e809fbffff             -call 0x449240
    cpu.esp -= 4;
    sub_449240(app, cpu);
    if (cpu.terminate) return;
    // 00449737  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00449739  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044973c  83b8107c550005         +cmp dword ptr [eax + 0x557c10], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5602320) /* 0x557c10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449743  0f855fffffff           -jne 0x4496a8
    if (!cpu.flags.zf)
    {
        goto L_0x004496a8;
    }
    // 00449749  baa08f5300             -mov edx, 0x538fa0
    cpu.edx = 5476256 /*0x538fa0*/;
    // 0044974e  8b80147c5500           -mov eax, dword ptr [eax + 0x557c14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5602324) /* 0x557c14 */);
    // 00449754  e8b74b0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 00449759  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044975b  7405                   -je 0x449762
    if (cpu.flags.zf)
    {
        goto L_0x00449762;
    }
    // 0044975d  e946ffffff             -jmp 0x4496a8
    goto L_0x004496a8;
L_0x00449762:
    // 00449762  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 00449768  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044976f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449771  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449774  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449776  8b0485204f6000         -mov eax, dword ptr [eax*4 + 0x604f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6311712) /* 0x604f20 */ + cpu.eax * 4);
    // 0044977d  803800                 +cmp byte ptr [eax], 0
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
    // 00449780  0f8422ffffff           -je 0x4496a8
    if (cpu.flags.zf)
    {
        goto L_0x004496a8;
    }
    // 00449786  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00449788:
    // 00449788  3b0db00b6600           +cmp ecx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044978e  7d39                   -jge 0x4497c9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004497c9;
    }
    // 00449790  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00449797  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00449799  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 0044979f  8b3c85e4406000         -mov edi, dword ptr [eax*4 + 0x6040e4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6308068) /* 0x6040e4 */ + cpu.eax * 4);
    // 004497a6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004497ad  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004497af  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004497b2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004497b4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004497b6  8b0485204f6000         -mov eax, dword ptr [eax*4 + 0x604f20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6311712) /* 0x604f20 */ + cpu.eax * 4);
    // 004497bd  e84e4b0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 004497c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004497c4  7403                   -je 0x4497c9
    if (cpu.flags.zf)
    {
        goto L_0x004497c9;
    }
    // 004497c6  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004497c7  ebbf                   -jmp 0x449788
    goto L_0x00449788;
L_0x004497c9:
    // 004497c9  a1b00b6600             -mov eax, dword ptr [0x660bb0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 004497ce  39c1                   +cmp ecx, eax
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
    // 004497d0  0f85d2feffff           -jne 0x4496a8
    if (!cpu.flags.zf)
    {
        goto L_0x004496a8;
    }
    // 004497d6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004497d8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004497db  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004497dd  bb24000000             -mov ebx, 0x24
    cpu.ebx = 36 /*0x24*/;
    // 004497e2  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004497e5  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004497e7  05d0406000             -add eax, 0x6040d0
    (cpu.eax) += x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
    // 004497ec  e84f6e0900             -call 0x4e0640
    cpu.esp -= 4;
    sub_4e0640(app, cpu);
    if (cpu.terminate) return;
    // 004497f1  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 004497f7  8d1c9500000000         -lea ebx, [edx*4]
    cpu.ebx = x86::reg32(cpu.edx * 4);
    // 004497fe  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449800  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00449803  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449805  8b15b00b6600           -mov edx, dword ptr [0x660bb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */);
    // 0044980b  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00449812  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00449815  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449817  8b8b204f6000           -mov ecx, dword ptr [ebx + 0x604f20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(6311712) /* 0x604f20 */);
    // 0044981d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449820  42                     -inc edx
    (cpu.edx)++;
    // 00449821  8988e4406000           -mov dword ptr [eax + 0x6040e4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6308068) /* 0x6040e4 */) = cpu.ecx;
    // 00449827  05d0406000             +add eax, 0x6040d0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044982c  8915b00b6600           -mov dword ptr [0x660bb0], edx
    app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */) = cpu.edx;
    // 00449832  e8d992ffff             -call 0x442b10
    cpu.esp -= 4;
    sub_442b10(app, cpu);
    if (cpu.terminate) return;
    // 00449837  e96cfeffff             -jmp 0x4496a8
    goto L_0x004496a8;
L_0x0044983c:
    // 0044983c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044983e  e8bd480a00             -call 0x4ee100
    cpu.esp -= 4;
    sub_4ee100(app, cpu);
    if (cpu.terminate) return;
    // 00449843  8b15ac0b6600           -mov edx, dword ptr [0x660bac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */);
    // 00449849  42                     -inc edx
    (cpu.edx)++;
    // 0044984a  8915ac0b6600           -mov dword ptr [0x660bac], edx
    app->getMemory<x86::reg32>(x86::reg32(6687660) /* 0x660bac */) = cpu.edx;
    // 00449850  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00449852  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00449854  e807f8ffff             -call 0x449060
    cpu.esp -= 4;
    sub_449060(app, cpu);
    if (cpu.terminate) return;
L_0x00449859:
    // 00449859  ff45fc                 +inc dword ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044985c  e98ffdffff             -jmp 0x4495f0
    goto L_0x004495f0;
L_0x00449861:
    // 00449861  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00449863:
    // 00449863  3b15b00b6600           +cmp edx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449869  7d19                   -jge 0x449884
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00449884;
    }
    // 0044986b  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00449872  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449874  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449877  05d0406000             +add eax, 0x6040d0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6308048 /*0x6040d0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044987c  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044987d  e80e010000             -call 0x449990
    cpu.esp -= 4;
    sub_449990(app, cpu);
    if (cpu.terminate) return;
    // 00449882  ebdf                   -jmp 0x449863
    goto L_0x00449863;
L_0x00449884:
    // 00449884  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00449889  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044988b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044988c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044988d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044988e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044988f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449890  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x92 0x00 0x00 0x00 0x00 0x8d 0x40 0x00 */
void Application::sub_4498a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004498a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004498a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004498a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004498a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004498a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004498a5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004498a7  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 004498ad  81edaa010000           -sub ebp, 0x1aa
    (cpu.ebp) -= x86::reg32(x86::sreg32(426 /*0x1aa*/));
    // 004498b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004498b5  be848f5300             -mov esi, 0x538f84
    cpu.esi = 5476228 /*0x538f84*/;
    // 004498ba  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004498bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004498be:
    // 004498be  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004498c0  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004498c2  3c00                   +cmp al, 0
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
    // 004498c4  7410                   -je 0x4498d6
    if (cpu.flags.zf)
    {
        goto L_0x004498d6;
    }
    // 004498c6  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004498c9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004498cc  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004498cf  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004498d2  3c00                   +cmp al, 0
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
    // 004498d4  75e8                   -jne 0x4498be
    if (!cpu.flags.zf)
    {
        goto L_0x004498be;
    }
L_0x004498d6:
    // 004498d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004498d7  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004498da  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004498dc  e8bf900000             -call 0x4529a0
    cpu.esp -= 4;
    sub_4529a0(app, cpu);
    if (cpu.terminate) return;
    // 004498e1  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 004498e8  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004498ea  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004498ed  8b3485e4406000         -mov esi, dword ptr [eax*4 + 0x6040e4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6308068) /* 0x6040e4 */ + cpu.eax * 4);
    // 004498f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004498f5  2bc9                   +sub ecx, ecx
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
    // 004498f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004498f8  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004498fa  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004498fc  4f                     -dec edi
    (cpu.edi)--;
L_0x004498fd:
    // 004498fd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004498ff  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00449901  3c00                   +cmp al, 0
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
    // 00449903  7410                   -je 0x449915
    if (cpu.flags.zf)
    {
        goto L_0x00449915;
    }
    // 00449905  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00449908  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044990b  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044990e  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00449911  3c00                   +cmp al, 0
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
    // 00449913  75e8                   -jne 0x4498fd
    if (!cpu.flags.zf)
    {
        goto L_0x004498fd;
    }
L_0x00449915:
    // 00449915  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449916  beac8f5300             -mov esi, 0x538fac
    cpu.esi = 5476268 /*0x538fac*/;
    // 0044991b  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044991e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00449923  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449924  2bc9                   +sub ecx, ecx
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
    // 00449926  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00449927  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00449929  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0044992b  4f                     -dec edi
    (cpu.edi)--;
L_0x0044992c:
    // 0044992c  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0044992e  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00449930  3c00                   +cmp al, 0
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
    // 00449932  7410                   -je 0x449944
    if (cpu.flags.zf)
    {
        goto L_0x00449944;
    }
    // 00449934  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00449937  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044993a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044993d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00449940  3c00                   +cmp al, 0
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
    // 00449942  75e8                   -jne 0x44992c
    if (!cpu.flags.zf)
    {
        goto L_0x0044992c;
    }
L_0x00449944:
    // 00449944  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449945  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00449948  e8a36c0a00             -call 0x4f05f0
    cpu.esp -= 4;
    sub_4f05f0(app, cpu);
    if (cpu.terminate) return;
    // 0044994d  8da5aa010000           -lea esp, [ebp + 0x1aa]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(426) /* 0x1aa */);
    // 00449953  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449954  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449955  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449956  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449957  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449958  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_449960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449961  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449962  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449964  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00449966:
    // 00449966  3b15b00b6600           +cmp edx, dword ptr [0x660bb0]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6687664) /* 0x660bb0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044996c  7d15                   -jge 0x449983
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00449983;
    }
    // 0044996e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00449970  e88b93ffff             -call 0x442d00
    cpu.esp -= 4;
    sub_442d00(app, cpu);
    if (cpu.terminate) return;
    // 00449975  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449977  7407                   -je 0x449980
    if (cpu.flags.zf)
    {
        goto L_0x00449980;
    }
    // 00449979  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044997b  e820ffffff             -call 0x4498a0
    cpu.esp -= 4;
    sub_4498a0(app, cpu);
    if (cpu.terminate) return;
L_0x00449980:
    // 00449980  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00449981  ebe3                   -jmp 0x449966
    goto L_0x00449966;
L_0x00449983:
    // 00449983  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449984  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449985  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x54 0x22 0x00 */
void Application::sub_449990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449990  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449991  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449992  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449994  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449996  6683782000             +cmp word ptr [eax + 0x20], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044999b  750d                   -jne 0x4499aa
    if (!cpu.flags.zf)
    {
        goto L_0x004499aa;
    }
    // 0044999d  833800                 +cmp dword ptr [eax], 0
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
    // 004499a0  7402                   -je 0x4499a4
    if (cpu.flags.zf)
    {
        goto L_0x004499a4;
    }
    // 004499a2  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004499a4:
    // 004499a4  66c742200100           -mov word ptr [edx + 0x20], 1
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x004499aa:
    // 004499aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4499b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004499b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004499b1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004499b2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004499b4  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004499bb  742b                   -je 0x4499e8
    if (cpu.flags.zf)
    {
        goto L_0x004499e8;
    }
    // 004499bd  833d08d56f0000         +cmp dword ptr [0x6fd508], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004499c4  7422                   -je 0x4499e8
    if (cpu.flags.zf)
    {
        goto L_0x004499e8;
    }
    // 004499c6  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004499cd  7519                   -jne 0x4499e8
    if (!cpu.flags.zf)
    {
        goto L_0x004499e8;
    }
    // 004499cf  bab48f5300             -mov edx, 0x538fb4
    cpu.edx = 5476276 /*0x538fb4*/;
    // 004499d4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004499d7  e8e48fffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 004499dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004499de  740d                   -je 0x4499ed
    if (cpu.flags.zf)
    {
        goto L_0x004499ed;
    }
    // 004499e0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004499e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499e7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004499e8:
    // 004499e8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004499ed:
    // 004499ed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004499ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4499f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004499f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004499f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004499f2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004499f4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004499f6  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004499fd  0f8455000000           -je 0x449a58
    if (cpu.flags.zf)
    {
        goto L_0x00449a58;
    }
    // 00449a03  833d08d56f0000         +cmp dword ptr [0x6fd508], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(7329032) /* 0x6fd508 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449a0a  744c                   -je 0x449a58
    if (cpu.flags.zf)
    {
        goto L_0x00449a58;
    }
    // 00449a0c  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449a13  7543                   -jne 0x449a58
    if (!cpu.flags.zf)
    {
        goto L_0x00449a58;
    }
    // 00449a15  e8667cffff             -call 0x441680
    cpu.esp -= 4;
    sub_441680(app, cpu);
    if (cpu.terminate) return;
    // 00449a1a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449a1c  753a                   -jne 0x449a58
    if (!cpu.flags.zf)
    {
        goto L_0x00449a58;
    }
    // 00449a1e  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449a23  7438                   -je 0x449a5d
    if (cpu.flags.zf)
    {
        goto L_0x00449a5d;
    }
    // 00449a25  6683fa1b               +cmp dx, 0x1b
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449a29  7432                   -je 0x449a5d
    if (cpu.flags.zf)
    {
        goto L_0x00449a5d;
    }
    // 00449a2b  8b4116                 -mov eax, dword ptr [ecx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 00449a2e  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00449a31  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00449a34  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449a37  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449a39  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449a40  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449a42  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449a45  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449a47  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449a4a  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 00449a4f  e85cffffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 00449a54  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449a56  7405                   -je 0x449a5d
    if (cpu.flags.zf)
    {
        goto L_0x00449a5d;
    }
L_0x00449a58:
    // 00449a58  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00449a5d:
    // 00449a5d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a5f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_449a60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449a60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449a61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449a62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449a63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449a64  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449a66  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00449a6b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00449a70  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449a75  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00449a77  890d44925500           -mov dword ptr [0x559244], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */) = cpu.ecx;
    // 00449a7d  891d4c925500           -mov dword ptr [0x55924c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.ebx;
    // 00449a83  a33c925500             -mov dword ptr [0x55923c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607996) /* 0x55923c */) = cpu.eax;
    // 00449a88  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449a8d  891538925500           -mov dword ptr [0x559238], edx
    app->getMemory<x86::reg32>(x86::reg32(5607992) /* 0x559238 */) = cpu.edx;
    // 00449a93  a340925500             -mov dword ptr [0x559240], eax
    app->getMemory<x86::reg32>(x86::reg32(5608000) /* 0x559240 */) = cpu.eax;
    // 00449a98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a9b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449a9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_449aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449aa0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449aa1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449aa2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449aa3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449aa4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449aa5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449aa6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449aa8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00449aab  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00449ab2  740c                   -je 0x449ac0
    if (cpu.flags.zf)
    {
        goto L_0x00449ac0;
    }
    // 00449ab4  c705509455000000803f   -mov dword ptr [0x559450], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = 1065353216 /*0x3f800000*/;
    // 00449abe  eb0a                   -jmp 0x449aca
    goto L_0x00449aca;
L_0x00449ac0:
    // 00449ac0  c705509455006666663f   -mov dword ptr [0x559450], 0x3f666666
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = 1063675494 /*0x3f666666*/;
L_0x00449aca:
    // 00449aca  e8e1130000             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00449acf  3b0548925500           +cmp eax, dword ptr [0x559248]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5608008) /* 0x559248 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449ad5  7509                   -jne 0x449ae0
    if (!cpu.flags.zf)
    {
        goto L_0x00449ae0;
    }
    // 00449ad7  e8d49dffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00449adc  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00449ade  743a                   -je 0x449b1a
    if (cpu.flags.zf)
    {
        goto L_0x00449b1a;
    }
L_0x00449ae0:
    // 00449ae0  c7053892550001000000   -mov dword ptr [0x559238], 1
    app->getMemory<x86::reg32>(x86::reg32(5607992) /* 0x559238 */) = 1 /*0x1*/;
    // 00449aea  e8c1130000             -call 0x44aeb0
    cpu.esp -= 4;
    sub_44aeb0(app, cpu);
    if (cpu.terminate) return;
    // 00449aef  a348925500             -mov dword ptr [0x559248], eax
    app->getMemory<x86::reg32>(x86::reg32(5608008) /* 0x559248 */) = cpu.eax;
    // 00449af4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00449af6  a34c925500             -mov dword ptr [0x55924c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.eax;
    // 00449afb  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449b00  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 00449b05  a33c925500             -mov dword ptr [0x55923c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607996) /* 0x55923c */) = cpu.eax;
    // 00449b0a  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449b0f  893d44925500           -mov dword ptr [0x559244], edi
    app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */) = cpu.edi;
    // 00449b15  a340925500             -mov dword ptr [0x559240], eax
    app->getMemory<x86::reg32>(x86::reg32(5608000) /* 0x559240 */) = cpu.eax;
L_0x00449b1a:
    // 00449b1a  e8d1020000             -call 0x449df0
    cpu.esp -= 4;
    sub_449df0(app, cpu);
    if (cpu.terminate) return;
    // 00449b1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449b21  0f85ba020000           -jne 0x449de1
    if (!cpu.flags.zf)
    {
        goto L_0x00449de1;
    }
    // 00449b27  e814090000             -call 0x44a440
    cpu.esp -= 4;
    sub_44a440(app, cpu);
    if (cpu.terminate) return;
    // 00449b2c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449b2e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00449b30  e87b9dffff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00449b35  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00449b37  750f                   -jne 0x449b48
    if (!cpu.flags.zf)
    {
        goto L_0x00449b48;
    }
    // 00449b39  83faff                 +cmp edx, -1
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
    // 00449b3c  740a                   -je 0x449b48
    if (cpu.flags.zf)
    {
        goto L_0x00449b48;
    }
    // 00449b3e  8b1d44925500           -mov ebx, dword ptr [0x559244]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */);
    // 00449b44  39da                   +cmp edx, ebx
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
    // 00449b46  740c                   -je 0x449b54
    if (cpu.flags.zf)
    {
        goto L_0x00449b54;
    }
L_0x00449b48:
    // 00449b48  c70544925500ffffffff   -mov dword ptr [0x559244], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */) = 4294967295 /*0xffffffff*/;
    // 00449b52  eb09                   -jmp 0x449b5d
    goto L_0x00449b5d;
L_0x00449b54:
    // 00449b54  83fbff                 +cmp ebx, -1
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
    // 00449b57  0f8517010000           -jne 0x449c74
    if (!cpu.flags.zf)
    {
        goto L_0x00449c74;
    }
L_0x00449b5d:
    // 00449b5d  8b153c925500           -mov edx, dword ptr [0x55923c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607996) /* 0x55923c */);
    // 00449b63  3b15e4e55500           +cmp edx, dword ptr [0x55e5e4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449b69  750e                   -jne 0x449b79
    if (!cpu.flags.zf)
    {
        goto L_0x00449b79;
    }
    // 00449b6b  8b1d40925500           -mov ebx, dword ptr [0x559240]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5608000) /* 0x559240 */);
    // 00449b71  3b1de8e55500           +cmp ebx, dword ptr [0x55e5e8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449b77  742e                   -je 0x449ba7
    if (cpu.flags.zf)
    {
        goto L_0x00449ba7;
    }
L_0x00449b79:
    // 00449b79  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449b7e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00449b80  a33c925500             -mov dword ptr [0x55923c], eax
    app->getMemory<x86::reg32>(x86::reg32(5607996) /* 0x55923c */) = cpu.eax;
    // 00449b85  a1e8e55500             -mov eax, dword ptr [0x55e5e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449b8a  893538925500           -mov dword ptr [0x559238], esi
    app->getMemory<x86::reg32>(x86::reg32(5607992) /* 0x559238 */) = cpu.esi;
    // 00449b90  a340925500             -mov dword ptr [0x559240], eax
    app->getMemory<x86::reg32>(x86::reg32(5608000) /* 0x559240 */) = cpu.eax;
    // 00449b95  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00449b9a  83c064                 +add eax, 0x64
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00449b9d  a350296600             -mov dword ptr [0x662950], eax
    app->getMemory<x86::reg32>(x86::reg32(6695248) /* 0x662950 */) = cpu.eax;
    // 00449ba2  e9cd000000             -jmp 0x449c74
    goto L_0x00449c74;
L_0x00449ba7:
    // 00449ba7  a1a4c17900             -mov eax, dword ptr [0x79c1a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(7979428) /* 0x79c1a4 */);
    // 00449bac  3b0550296600           +cmp eax, dword ptr [0x662950]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(6695248) /* 0x662950 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449bb2  0f8ebc000000           -jle 0x449c74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449c74;
    }
    // 00449bb8  83f9ff                 +cmp ecx, -1
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
    // 00449bbb  0f84b3000000           -je 0x449c74
    if (cpu.flags.zf)
    {
        goto L_0x00449c74;
    }
    // 00449bc1  a138925500             -mov eax, dword ptr [0x559238]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607992) /* 0x559238 */);
    // 00449bc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449bc8  0f85a6000000           -jne 0x449c74
    if (!cpu.flags.zf)
    {
        goto L_0x00449c74;
    }
    // 00449bce  890d44925500           -mov dword ptr [0x559244], ecx
    app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */) = cpu.ecx;
    // 00449bd4  a364296600             -mov dword ptr [0x662964], eax
    app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */) = cpu.eax;
    // 00449bd9  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00449be0  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449be2  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449be5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00449be7  bb7c010000             -mov ebx, 0x17c
    cpu.ebx = 380 /*0x17c*/;
    // 00449bec  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00449bee  8b0485ec4e6000         -mov eax, dword ptr [eax*4 + 0x604eec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6311660) /* 0x604eec */ + cpu.eax * 4);
    // 00449bf5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449bf6  a34c925500             -mov dword ptr [0x55924c], eax
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.eax;
    // 00449bfb  8d45fc                 -lea eax, [ebp - 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449bfe  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00449c03  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00449c04  8d4df8                 -lea ecx, [ebp - 8]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00449c07  a14c925500             -mov eax, dword ptr [0x55924c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
    // 00449c0c  e8df830000             -call 0x451ff0
    cpu.esp -= 4;
    sub_451ff0(app, cpu);
    if (cpu.terminate) return;
    // 00449c11  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00449c14  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00449c17  8b0de4e55500           -mov ecx, dword ptr [0x55e5e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449c1d  83c207                 -add edx, 7
    (cpu.edx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00449c20  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00449c23  890d58296600           -mov dword ptr [0x662958], ecx
    app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */) = cpu.ecx;
    // 00449c29  891560296600           -mov dword ptr [0x662960], edx
    app->getMemory<x86::reg32>(x86::reg32(6695264) /* 0x662960 */) = cpu.edx;
    // 00449c2f  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449c31  a354296600             -mov dword ptr [0x662954], eax
    app->getMemory<x86::reg32>(x86::reg32(6695252) /* 0x662954 */) = cpu.eax;
    // 00449c36  81f976020000           +cmp ecx, 0x276
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(630 /*0x276*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449c3c  7e0d                   -jle 0x449c4b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449c4b;
    }
    // 00449c3e  b976020000             -mov ecx, 0x276
    cpu.ecx = 630 /*0x276*/;
    // 00449c43  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449c45  890d58296600           -mov dword ptr [0x662958], ecx
    app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */) = cpu.ecx;
L_0x00449c4b:
    // 00449c4b  8b15e8e55500           -mov edx, dword ptr [0x55e5e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449c51  83c214                 -add edx, 0x14
    (cpu.edx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00449c54  89155c296600           -mov dword ptr [0x66295c], edx
    app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */) = cpu.edx;
    // 00449c5a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449c5c  81facc010000           +cmp edx, 0x1cc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(460 /*0x1cc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449c62  7e10                   -jle 0x449c74
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449c74;
    }
    // 00449c64  8b15e8e55500           -mov edx, dword ptr [0x55e5e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */);
    // 00449c6a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00449c6c  8d42f8                 -lea eax, [edx - 8]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-8) /* -0x8 */);
    // 00449c6f  a35c296600             -mov dword ptr [0x66295c], eax
    app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */) = cpu.eax;
L_0x00449c74:
    // 00449c74  8b0d4c925500           -mov ecx, dword ptr [0x55924c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
    // 00449c7a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00449c7c  740d                   -je 0x449c8b
    if (cpu.flags.zf)
    {
        goto L_0x00449c8b;
    }
    // 00449c7e  803900                 +cmp byte ptr [ecx], 0
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
    // 00449c81  7508                   -jne 0x449c8b
    if (!cpu.flags.zf)
    {
        goto L_0x00449c8b;
    }
    // 00449c83  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00449c85  891d4c925500           -mov dword ptr [0x55924c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.ebx;
L_0x00449c8b:
    // 00449c8b  833d4c92550000         +cmp dword ptr [0x55924c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449c92  0f8466000000           -je 0x449cfe
    if (cpu.flags.zf)
    {
        goto L_0x00449cfe;
    }
    // 00449c98  833d44925500ff         +cmp dword ptr [0x559244], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608004) /* 0x559244 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449c9f  7530                   -jne 0x449cd1
    if (!cpu.flags.zf)
    {
        goto L_0x00449cd1;
    }
    // 00449ca1  a164296600             -mov eax, dword ptr [0x662964]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */);
    // 00449ca6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449ca8  7e0a                   -jle 0x449cb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449cb4;
    }
    // 00449caa  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00449cac  891564296600           -mov dword ptr [0x662964], edx
    app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */) = cpu.edx;
    // 00449cb2  eb02                   -jmp 0x449cb6
    goto L_0x00449cb6;
L_0x00449cb4:
    // 00449cb4  7f08                   -jg 0x449cbe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00449cbe;
    }
L_0x00449cb6:
    // 00449cb6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00449cb8  891d4c925500           -mov dword ptr [0x55924c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.ebx;
L_0x00449cbe:
    // 00449cbe  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00449cc5  7437                   -je 0x449cfe
    if (cpu.flags.zf)
    {
        goto L_0x00449cfe;
    }
    // 00449cc7  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00449cc9  89354c925500           -mov dword ptr [0x55924c], esi
    app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */) = cpu.esi;
    // 00449ccf  eb2d                   -jmp 0x449cfe
    goto L_0x00449cfe;
L_0x00449cd1:
    // 00449cd1  8b3d64296600           -mov edi, dword ptr [0x662964]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */);
    // 00449cd7  81ffff000000           +cmp edi, 0xff
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
    // 00449cdd  7c02                   -jl 0x449ce1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00449ce1;
    }
    // 00449cdf  7e0a                   -jle 0x449ceb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00449ceb;
    }
L_0x00449ce1:
    // 00449ce1  c70564296600ff000000   -mov dword ptr [0x662964], 0xff
    app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */) = 255 /*0xff*/;
L_0x00449ceb:
    // 00449ceb  f605583a7a0002         +test byte ptr [0x7a3a58], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(8010328) /* 0x7a3a58 */) & 2 /*0x2*/));
    // 00449cf2  740a                   -je 0x449cfe
    if (cpu.flags.zf)
    {
        goto L_0x00449cfe;
    }
    // 00449cf4  c70564296600ff000000   -mov dword ptr [0x662964], 0xff
    app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */) = 255 /*0xff*/;
L_0x00449cfe:
    // 00449cfe  833d4c92550000         +cmp dword ptr [0x55924c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449d05  0f84cc000000           -je 0x449dd7
    if (cpu.flags.zf)
    {
        goto L_0x00449dd7;
    }
    // 00449d0b  68ad6c4bff             -push 0xff4b6cad
    app->getMemory<x86::reg32>(cpu.esp-4) = 4283133101 /*0xff4b6cad*/;
    cpu.esp -= 4;
    // 00449d10  a164296600             -mov eax, dword ptr [0x662964]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */);
    // 00449d15  8b0d5c296600           -mov ecx, dword ptr [0x66295c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449d1b  8b1554296600           -mov edx, dword ptr [0x662954]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6695252) /* 0x662954 */);
    // 00449d21  8b1d60296600           -mov ebx, dword ptr [0x662960]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6695264) /* 0x662960 */);
    // 00449d27  6a9c                   -push -0x64
    app->getMemory<x86::reg32>(cpu.esp-4) = -100 /*-0x64*/;
    cpu.esp -= 4;
    // 00449d29  a3a43a5600             -mov dword ptr [0x563aa4], eax
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = cpu.eax;
    // 00449d2e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00449d30  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00449d32  a158296600             -mov eax, dword ptr [0x662958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */);
    // 00449d37  8b155c296600           -mov edx, dword ptr [0x66295c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449d3d  c1e718                 -shl edi, 0x18
    cpu.edi <<= 24 /*0x18*/ % 32;
    // 00449d40  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449d42  893da43a5600           -mov dword ptr [0x563aa4], edi
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = cpu.edi;
    // 00449d48  e803e80800             -call 0x4d8550
    cpu.esp -= 4;
    sub_4d8550(app, cpu);
    if (cpu.terminate) return;
    // 00449d4d  a164296600             -mov eax, dword ptr [0x662964]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695268) /* 0x662964 */);
    // 00449d52  8b0d54296600           -mov ecx, dword ptr [0x662954]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6695252) /* 0x662954 */);
    // 00449d58  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 00449d5b  8b1d60296600           -mov ebx, dword ptr [0x662960]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6695264) /* 0x662960 */);
    // 00449d61  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00449d62  8b155c296600           -mov edx, dword ptr [0x66295c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449d68  a158296600             -mov eax, dword ptr [0x662958]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */);
    // 00449d6d  e8beeb0800             -call 0x4d8930
    cpu.esp -= 4;
    sub_4d8930(app, cpu);
    if (cpu.terminate) return;
    // 00449d72  8b3534925500           -mov esi, dword ptr [0x559234]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
    // 00449d78  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00449d7a  7424                   -je 0x449da0
    if (cpu.flags.zf)
    {
        goto L_0x00449da0;
    }
    // 00449d7c  68fd8c4800             -push 0x488cfd
    app->getMemory<x86::reg32>(cpu.esp-4) = 4754685 /*0x488cfd*/;
    cpu.esp -= 4;
    // 00449d81  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00449d86  8b1d5c296600           -mov ebx, dword ptr [0x66295c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449d8c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00449d8e  8b1558296600           -mov edx, dword ptr [0x662958]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */);
    // 00449d94  a14c925500             -mov eax, dword ptr [0x55924c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
    // 00449d99  e8f2830000             -call 0x452190
    cpu.esp -= 4;
    sub_452190(app, cpu);
    if (cpu.terminate) return;
    // 00449d9e  eb2d                   -jmp 0x449dcd
    goto L_0x00449dcd;
L_0x00449da0:
    // 00449da0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449da2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449da3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449da4  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00449da9  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 00449dae  687c010000             -push 0x17c
    app->getMemory<x86::reg32>(cpu.esp-4) = 380 /*0x17c*/;
    cpu.esp -= 4;
    // 00449db3  8b3d5c296600           -mov edi, dword ptr [0x66295c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(6695260) /* 0x66295c */);
    // 00449db9  8b0d58296600           -mov ecx, dword ptr [0x662958]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(6695256) /* 0x662958 */);
    // 00449dbf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00449dc0  a14c925500             -mov eax, dword ptr [0x55924c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5608012) /* 0x55924c */);
    // 00449dc5  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00449dc8  e8f3810000             -call 0x451fc0
    cpu.esp -= 4;
    sub_451fc0(app, cpu);
    if (cpu.terminate) return;
L_0x00449dcd:
    // 00449dcd  c705a43a5600000000ff   -mov dword ptr [0x563aa4], 0xff000000
    app->getMemory<x86::reg32>(x86::reg32(5651108) /* 0x563aa4 */) = 4278190080 /*0xff000000*/;
L_0x00449dd7:
    // 00449dd7  c705509455000000803f   -mov dword ptr [0x559450], 0x3f800000
    app->getMemory<x86::reg32>(x86::reg32(5608528) /* 0x559450 */) = 1065353216 /*0x3f800000*/;
L_0x00449de1:
    // 00449de1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00449de3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449de9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 */
void Application::sub_449df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449df0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449df1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449df2  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449df4  e847060000             -call 0x44a440
    cpu.esp -= 4;
    sub_44a440(app, cpu);
    if (cpu.terminate) return;
    // 00449df9  83f8ff                 +cmp eax, -1
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
    // 00449dfc  743a                   -je 0x449e38
    if (cpu.flags.zf)
    {
        goto L_0x00449e38;
    }
    // 00449dfe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449e00  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449e03  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449e05  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449e08  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449e0a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449e0d  f680e54e600004         +test byte ptr [eax + 0x604ee5], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6311653) /* 0x604ee5 */) & 4 /*0x4*/));
    // 00449e14  7422                   -je 0x449e38
    if (cpu.flags.zf)
    {
        goto L_0x00449e38;
    }
    // 00449e16  8b90e04e6000           -mov edx, dword ptr [eax + 0x604ee0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
    // 00449e1c  83fa11                 +cmp edx, 0x11
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449e1f  740f                   -je 0x449e30
    if (cpu.flags.zf)
    {
        goto L_0x00449e30;
    }
    // 00449e21  83fa1d                 +cmp edx, 0x1d
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449e24  740a                   -je 0x449e30
    if (cpu.flags.zf)
    {
        goto L_0x00449e30;
    }
    // 00449e26  83fa12                 +cmp edx, 0x12
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449e29  7405                   -je 0x449e30
    if (cpu.flags.zf)
    {
        goto L_0x00449e30;
    }
    // 00449e2b  83fa13                 +cmp edx, 0x13
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
    // 00449e2e  7508                   -jne 0x449e38
    if (!cpu.flags.zf)
    {
        goto L_0x00449e38;
    }
L_0x00449e30:
    // 00449e30  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00449e35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00449e38:
    // 00449e38  e8739affff             -call 0x4438b0
    cpu.esp -= 4;
    sub_4438b0(app, cpu);
    if (cpu.terminate) return;
    // 00449e3d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00449e3f  7408                   -je 0x449e49
    if (cpu.flags.zf)
    {
        goto L_0x00449e49;
    }
    // 00449e41  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00449e46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e47  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00449e49:
    // 00449e49  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00449e4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_449e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449e50  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449e51  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449e53  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449e55  7c43                   -jl 0x449e9a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00449e9a;
    }
    // 00449e57  83f864                 +cmp eax, 0x64
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
    // 00449e5a  743e                   -je 0x449e9a
    if (cpu.flags.zf)
    {
        goto L_0x00449e9a;
    }
    // 00449e5c  8b5216                 -mov edx, dword ptr [edx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(22) /* 0x16 */);
    // 00449e5f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449e62  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449e64  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449e6b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449e6d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449e70  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449e72  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449e75  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 00449e7a  8b5002                 -mov edx, dword ptr [eax + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00449e7d  e82efbffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 00449e82  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449e85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449e87  7503                   -jne 0x449e8c
    if (!cpu.flags.zf)
    {
        goto L_0x00449e8c;
    }
    // 00449e89  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00449e8c:
    // 00449e8c  66f7c20113             +test dx, 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & 4865 /*0x1301*/));
    // 00449e91  7507                   -jne 0x449e9a
    if (!cpu.flags.zf)
    {
        goto L_0x00449e9a;
    }
    // 00449e93  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00449e98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e99  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00449e9a:
    // 00449e9a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00449e9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449e9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_449ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449ea0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449ea1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449ea2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449ea3  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449ea5  6683781a64             +cmp word ptr [eax + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449eaa  7477                   -je 0x449f23
    if (cpu.flags.zf)
    {
        goto L_0x00449f23;
    }
    // 00449eac  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 00449eaf  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00449eb2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449eb5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00449eb8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449eba  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449ec1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449ec3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449ec6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449ec8  b9e04e6000             -mov ecx, 0x604ee0
    cpu.ecx = 6311648 /*0x604ee0*/;
    // 00449ecd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449ed0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449ed2  8b511c                 -mov edx, dword ptr [ecx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00449ed5  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449ed8  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449edf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449ee1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00449ee3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00449ee6  c1e202                 +shl edx, 2
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
    // 00449ee9  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00449eeb  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00449eee  8b511a                 -mov edx, dword ptr [ecx + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 00449ef1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449ef4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449ef6  8915e4e55500           -mov dword ptr [0x55e5e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */) = cpu.edx;
    // 00449efc  8b511e                 -mov edx, dword ptr [ecx + 0x1e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 00449eff  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449f02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00449f04  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00449f07  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449f09  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00449f0b  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00449f0e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449f11  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00449f13  a1e4e55500             -mov eax, dword ptr [0x55e5e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5629412) /* 0x55e5e4 */);
    // 00449f18  8915e8e55500           -mov dword ptr [0x55e5e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5629416) /* 0x55e5e8 */) = cpu.edx;
    // 00449f1e  e89d200500             -call 0x49bfc0
    cpu.esp -= 4;
    sub_49bfc0(app, cpu);
    if (cpu.terminate) return;
L_0x00449f23:
    // 00449f23  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449f24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449f25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00449f26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 */
void Application::sub_449f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00449f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00449f31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00449f32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00449f33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00449f34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00449f35  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00449f37  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00449f3a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00449f3c  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00449f3f  668b501a               -mov dx, word ptr [eax + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
    // 00449f43  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00449f46  6683fa64               +cmp dx, 0x64
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449f4a  7424                   -je 0x449f70
    if (cpu.flags.zf)
    {
        goto L_0x00449f70;
    }
    // 00449f4c  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 00449f4f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00449f52  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00449f54  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449f5b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449f5d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449f60  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449f62  f60485e54e600004       +test byte ptr [eax*4 + 0x604ee5], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6311653) /* 0x604ee5 */ + cpu.eax * 4) & 4 /*0x4*/));
    // 00449f6a  0f853d010000           -jne 0x44a0ad
    if (!cpu.flags.zf)
    {
        goto L_0x0044a0ad;
    }
L_0x00449f70:
    // 00449f70  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449f75  7411                   -je 0x449f88
    if (cpu.flags.zf)
    {
        goto L_0x00449f88;
    }
    // 00449f77  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00449f7a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00449f7c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00449f7f  e8ccfeffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 00449f84  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449f86  751e                   -jne 0x449fa6
    if (!cpu.flags.zf)
    {
        goto L_0x00449fa6;
    }
L_0x00449f88:
    // 00449f88  8b411a                 -mov eax, dword ptr [ecx + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 00449f8b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00449f8d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00449f90  e8bbfeffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 00449f95  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449f97  740d                   -je 0x449fa6
    if (cpu.flags.zf)
    {
        goto L_0x00449fa6;
    }
    // 00449f99  668b411c               -mov ax, word ptr [ecx + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00449f9d  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 00449fa1  e9d9000000             -jmp 0x44a07f
    goto L_0x0044a07f;
L_0x00449fa6:
    // 00449fa6  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00449fab  7556                   -jne 0x44a003
    if (!cpu.flags.zf)
    {
        goto L_0x0044a003;
    }
    // 00449fad  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 00449fb0  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
L_0x00449fb3:
    // 00449fb3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00449fba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449fbc  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00449fbf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00449fc1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00449fc4  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00449fcb  0f84ae000000           -je 0x44a07f
    if (cpu.flags.zf)
    {
        goto L_0x0044a07f;
    }
    // 00449fd1  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 00449fd6  8b7002                 -mov esi, dword ptr [eax + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00449fd9  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 00449fdc  e8cff9ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 00449fe1  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 00449fe4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00449fe6  7504                   -jne 0x449fec
    if (!cpu.flags.zf)
    {
        goto L_0x00449fec;
    }
    // 00449fe8  804dfc01               -or byte ptr [ebp - 4], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00449fec:
    // 00449fec  66f745fc0113           +test word ptr [ebp - 4], 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4865 /*0x1301*/));
    // 00449ff2  750c                   -jne 0x44a000
    if (!cpu.flags.zf)
    {
        goto L_0x0044a000;
    }
    // 00449ff4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00449ff6  668b4118               -mov ax, word ptr [ecx + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00449ffa  29c6                   +sub esi, eax
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
    // 00449ffc  6689711a               -mov word ptr [ecx + 0x1a], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.si;
L_0x0044a000:
    // 0044a000  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a001  ebb0                   -jmp 0x449fb3
    goto L_0x00449fb3;
L_0x0044a003:
    // 0044a003  668b511a               -mov dx, word ptr [ecx + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 0044a007  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 0044a00a  7409                   -je 0x44a015
    if (cpu.flags.zf)
    {
        goto L_0x0044a015;
    }
    // 0044a00c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0044a00e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044a00f  6689711a               -mov word ptr [ecx + 0x1a], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.si;
    // 0044a013  eb2d                   -jmp 0x44a042
    goto L_0x0044a042;
L_0x0044a015:
    // 0044a015  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a018  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a01b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a01e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a021  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a023  42                     -inc edx
    (cpu.edx)++;
    // 0044a024  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a02b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a02d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a030  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a032  833c85e04e600000       +cmp dword ptr [eax*4 + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6311648) /* 0x604ee0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a03a  7406                   -je 0x44a042
    if (cpu.flags.zf)
    {
        goto L_0x0044a042;
    }
    // 0044a03c  66ff411a               +inc word ptr [ecx + 0x1a]
    {
        auto tmp = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 0044a040  ebd3                   -jmp 0x44a015
    goto L_0x0044a015;
L_0x0044a042:
    // 0044a042  8b4116                 -mov eax, dword ptr [ecx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a045  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a048  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a04b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a04e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a050  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a057  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a059  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a05c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a05e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a061  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a066  8b5002                 -mov edx, dword ptr [eax + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0044a069  e842f9ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 0044a06e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a071  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a073  7503                   -jne 0x44a078
    if (!cpu.flags.zf)
    {
        goto L_0x0044a078;
    }
    // 0044a075  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044a078:
    // 0044a078  66f7c20113             +test dx, 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & 4865 /*0x1301*/));
    // 0044a07d  7584                   -jne 0x44a003
    if (!cpu.flags.zf)
    {
        goto L_0x0044a003;
    }
L_0x0044a07f:
    // 0044a07f  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a082  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a085  39d8                   +cmp eax, ebx
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
    // 0044a087  740c                   -je 0x44a095
    if (cpu.flags.zf)
    {
        goto L_0x0044a095;
    }
    // 0044a089  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044a08e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a090  e83be1fcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a095:
    // 0044a095  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a097  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a099  e8b2fdffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a09e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a0a0  7404                   -je 0x44a0a6
    if (cpu.flags.zf)
    {
        goto L_0x0044a0a6;
    }
    // 0044a0a2  6689591c               -mov word ptr [ecx + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.bx;
L_0x0044a0a6:
    // 0044a0a6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a0a8  e8f3fdffff             -call 0x449ea0
    cpu.esp -= 4;
    sub_449ea0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a0ad:
    // 0044a0ad  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a0af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a0b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x8d 0x52 0x00 0x8b 0xdb */
void Application::sub_44a0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a0c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a0c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a0c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a0c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044a0c4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a0c5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a0c7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044a0ca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044a0cc  6683781a64             +cmp word ptr [eax + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a0d1  742a                   -je 0x44a0fd
    if (cpu.flags.zf)
    {
        goto L_0x0044a0fd;
    }
    // 0044a0d3  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a0d6  8b4016                 -mov eax, dword ptr [eax + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a0d9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a0dc  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a0df  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a0e1  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a0e8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a0ea  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a0ed  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a0ef  f60485e54e600004       +test byte ptr [eax*4 + 0x604ee5], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(6311653) /* 0x604ee5 */ + cpu.eax * 4) & 4 /*0x4*/));
    // 0044a0f7  0f8536010000           -jne 0x44a233
    if (!cpu.flags.zf)
    {
        goto L_0x0044a233;
    }
L_0x0044a0fd:
    // 0044a0fd  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a100  668b711a               -mov si, word ptr [ecx + 0x1a]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 0044a104  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0044a107  6683fe64               +cmp si, 0x64
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a10b  740d                   -je 0x44a11a
    if (cpu.flags.zf)
    {
        goto L_0x0044a11a;
    }
    // 0044a10d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a10f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a111  e83afdffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a116  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a118  751e                   -jne 0x44a138
    if (!cpu.flags.zf)
    {
        goto L_0x0044a138;
    }
L_0x0044a11a:
    // 0044a11a  8b411a                 -mov eax, dword ptr [ecx + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(26) /* 0x1a */);
    // 0044a11d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a11f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a122  e829fdffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a127  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a129  740d                   -je 0x44a138
    if (cpu.flags.zf)
    {
        goto L_0x0044a138;
    }
    // 0044a12b  668b411c               -mov ax, word ptr [ecx + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0044a12f  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 0044a133  e9cd000000             -jmp 0x44a205
    goto L_0x0044a205;
L_0x0044a138:
    // 0044a138  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a13d  7559                   -jne 0x44a198
    if (!cpu.flags.zf)
    {
        goto L_0x0044a198;
    }
    // 0044a13f  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a142  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
L_0x0044a145:
    // 0044a145  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a14c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a14e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a151  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a153  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a156  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a15d  0f84a2000000           -je 0x44a205
    if (cpu.flags.zf)
    {
        goto L_0x0044a205;
    }
    // 0044a163  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a168  8b7002                 -mov esi, dword ptr [eax + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0044a16b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 0044a16e  e83df8ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 0044a173  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 0044a176  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a178  7504                   -jne 0x44a17e
    if (!cpu.flags.zf)
    {
        goto L_0x0044a17e;
    }
    // 0044a17a  804dfc01               -or byte ptr [ebp - 4], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-4) /* -0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044a17e:
    // 0044a17e  66f745fc0113           +test word ptr [ebp - 4], 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) & 4865 /*0x1301*/));
    // 0044a184  750f                   -jne 0x44a195
    if (!cpu.flags.zf)
    {
        goto L_0x0044a195;
    }
    // 0044a186  668b4118               -mov ax, word ptr [ecx + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a18a  29c2                   +sub edx, eax
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
    // 0044a18c  6689511a               -mov word ptr [ecx + 0x1a], dx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.dx;
    // 0044a190  e970000000             -jmp 0x44a205
    goto L_0x0044a205;
L_0x0044a195:
    // 0044a195  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a196  ebad                   -jmp 0x44a145
    goto L_0x0044a145;
L_0x0044a198:
    // 0044a198  66ff411a               -inc word ptr [ecx + 0x1a]
    (app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */))++;
    // 0044a19c  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a19f  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a1a2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a1a5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a1a8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a1aa  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a1b1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a1b3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a1b6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a1b8  833c85e04e600000       +cmp dword ptr [eax*4 + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6311648) /* 0x604ee0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a1c0  7506                   -jne 0x44a1c8
    if (!cpu.flags.zf)
    {
        goto L_0x0044a1c8;
    }
    // 0044a1c2  66c7411a0000           -mov word ptr [ecx + 0x1a], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = 0 /*0x0*/;
L_0x0044a1c8:
    // 0044a1c8  8b5116                 -mov edx, dword ptr [ecx + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a1cb  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a1ce  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a1d1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a1d4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a1d6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a1dd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a1df  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a1e2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a1e4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a1e7  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a1ec  8b5002                 -mov edx, dword ptr [eax + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0044a1ef  e8bcf7ffff             -call 0x4499b0
    cpu.esp -= 4;
    sub_4499b0(app, cpu);
    if (cpu.terminate) return;
    // 0044a1f4  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a1f7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a1f9  7503                   -jne 0x44a1fe
    if (!cpu.flags.zf)
    {
        goto L_0x0044a1fe;
    }
    // 0044a1fb  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0044a1fe:
    // 0044a1fe  66f7c20113             +test dx, 0x1301
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & 4865 /*0x1301*/));
    // 0044a203  7593                   -jne 0x44a198
    if (!cpu.flags.zf)
    {
        goto L_0x0044a198;
    }
L_0x0044a205:
    // 0044a205  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a207  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a209  e842fcffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a20e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a210  7404                   -je 0x44a216
    if (cpu.flags.zf)
    {
        goto L_0x0044a216;
    }
    // 0044a212  6689591c               -mov word ptr [ecx + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.bx;
L_0x0044a216:
    // 0044a216  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a219  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a21c  39d8                   +cmp eax, ebx
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
    // 0044a21e  740c                   -je 0x44a22c
    if (cpu.flags.zf)
    {
        goto L_0x0044a22c;
    }
    // 0044a220  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044a225  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a227  e8a4dffcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a22c:
    // 0044a22c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a22e  e86dfcffff             -call 0x449ea0
    cpu.esp -= 4;
    sub_449ea0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a233:
    // 0044a233  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a235  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a236  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a237  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a238  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a239  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a23a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44a240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a241  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a242  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044a243  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044a244  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a245  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a247  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044a24a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044a24c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0044a24e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a250  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0044a253  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 0044a255  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a257  0f8464000000           -je 0x44a2c1
    if (cpu.flags.zf)
    {
        goto L_0x0044a2c1;
    }
    // 0044a25d  8b5816                 -mov ebx, dword ptr [eax + 0x16]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a260  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
L_0x0044a263:
    // 0044a263  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0044a26a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044a26c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a26f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044a271  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a274  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a27b  7441                   -je 0x44a2be
    if (cpu.flags.zf)
    {
        goto L_0x0044a2be;
    }
    // 0044a27d  b9e04e6000             -mov ecx, 0x604ee0
    cpu.ecx = 6311648 /*0x604ee0*/;
    // 0044a282  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a284  833905                 +cmp dword ptr [ecx], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a287  7532                   -jne 0x44a2bb
    if (!cpu.flags.zf)
    {
        goto L_0x0044a2bb;
    }
    // 0044a289  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0044a28c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044a28e  742b                   -je 0x44a2bb
    if (cpu.flags.zf)
    {
        goto L_0x0044a2bb;
    }
    // 0044a290  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a294  7525                   -jne 0x44a2bb
    if (!cpu.flags.zf)
    {
        goto L_0x0044a2bb;
    }
    // 0044a296  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044a298  babc8f5300             -mov edx, 0x538fbc
    cpu.edx = 5476284 /*0x538fbc*/;
    // 0044a29d  e81e87ffff             -call 0x4429c0
    cpu.esp -= 4;
    sub_4429c0(app, cpu);
    if (cpu.terminate) return;
    // 0044a2a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a2a4  7415                   -je 0x44a2bb
    if (cpu.flags.zf)
    {
        goto L_0x0044a2bb;
    }
    // 0044a2a6  f6410401               +test byte ptr [ecx + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0044a2aa  750f                   -jne 0x44a2bb
    if (!cpu.flags.zf)
    {
        goto L_0x0044a2bb;
    }
    // 0044a2ac  8b4616                 -mov eax, dword ptr [esi + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 0044a2af  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0044a2b1  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a2b4  29c2                   +sub edx, eax
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
    // 0044a2b6  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
    // 0044a2b9  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
L_0x0044a2bb:
    // 0044a2bb  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a2bc  eba5                   -jmp 0x44a263
    goto L_0x0044a263;
L_0x0044a2be:
    // 0044a2be  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
L_0x0044a2c1:
    // 0044a2c1  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a2c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a2c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44a2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a2d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a2d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a2d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044a2d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044a2d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a2d5  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a2d7  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044a2da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044a2dc  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0044a2de  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044a2e0  8b3de0227a00           -mov edi, dword ptr [0x7a22e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
    // 0044a2e6  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0044a2e9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044a2eb  7423                   -je 0x44a310
    if (cpu.flags.zf)
    {
        goto L_0x0044a310;
    }
    // 0044a2ed  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 0044a2f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044a2f2  e80974ffff             -call 0x441700
    cpu.esp -= 4;
    sub_441700(app, cpu);
    if (cpu.terminate) return;
    // 0044a2f7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044a2f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a2fb  0f8527010000           -jne 0x44a428
    if (!cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
    // 0044a301  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a303  e8e8f6ffff             -call 0x4499f0
    cpu.esp -= 4;
    sub_4499f0(app, cpu);
    if (cpu.terminate) return;
    // 0044a308  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a30a  0f8418010000           -je 0x44a428
    if (cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
L_0x0044a310:
    // 0044a310  833d6829660000         +cmp dword ptr [0x662968], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6695272) /* 0x662968 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a317  7508                   -jne 0x44a321
    if (!cpu.flags.zf)
    {
        goto L_0x0044a321;
    }
    // 0044a319  0fbfc6                 -movsx eax, si
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0044a31c  e8bf810000             -call 0x4524e0
    cpu.esp -= 4;
    sub_4524e0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a321:
    // 0044a321  6683791a64             +cmp word ptr [ecx + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a326  750d                   -jne 0x44a335
    if (!cpu.flags.zf)
    {
        goto L_0x0044a335;
    }
    // 0044a328  6683fe0d               +cmp si, 0xd
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(13 /*0xd*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a32c  7541                   -jne 0x44a36f
    if (!cpu.flags.zf)
    {
        goto L_0x0044a36f;
    }
    // 0044a32e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044a330  e9fc000000             -jmp 0x44a431
    goto L_0x0044a431;
L_0x0044a335:
    // 0044a335  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0044a338  8b4116                 -mov eax, dword ptr [ecx + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(22) /* 0x16 */);
    // 0044a33b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a33e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a341  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a343  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a34a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a34c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a34f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a351  bfe04e6000             -mov edi, 0x604ee0
    cpu.edi = 6311648 /*0x604ee0*/;
    // 0044a356  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a359  01c7                   +add edi, eax
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
    // 0044a35b  7412                   -je 0x44a36f
    if (cpu.flags.zf)
    {
        goto L_0x0044a36f;
    }
    // 0044a35d  837f3000               +cmp dword ptr [edi + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a361  740c                   -je 0x44a36f
    if (cpu.flags.zf)
    {
        goto L_0x0044a36f;
    }
    // 0044a363  0fbfde                 -movsx ebx, si
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(cpu.si));
    // 0044a366  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a368  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044a36a  ff5730                 -call dword ptr [edi + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a36d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0044a36f:
    // 0044a36f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044a371  0f85b1000000           -jne 0x44a428
    if (!cpu.flags.zf)
    {
        goto L_0x0044a428;
    }
    // 0044a377  6681fe004b             +cmp si, 0x4b00
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19200 /*0x4b00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a37c  7227                   -jb 0x44a3a5
    if (cpu.flags.cf)
    {
        goto L_0x0044a3a5;
    }
    // 0044a37e  0f867c000000           -jbe 0x44a400
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044a400;
    }
    // 0044a384  6681fe004d             +cmp si, 0x4d00
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(19712 /*0x4d00*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a389  0f8299000000           -jb 0x44a428
    if (cpu.flags.cf)
    {
        goto L_0x0044a428;
    }
    // 0044a38f  0f8680000000           -jbe 0x44a415
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044a415;
    }
    // 0044a395  6681fe0050             +cmp si, 0x5000
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(20480 /*0x5000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a39a  0f8475000000           -je 0x44a415
    if (cpu.flags.zf)
    {
        goto L_0x0044a415;
    }
    // 0044a3a0  e983000000             -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a3a5:
    // 0044a3a5  6683fe1b               +cmp si, 0x1b
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(27 /*0x1b*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a3a9  0f8279000000           -jb 0x44a428
    if (cpu.flags.cf)
    {
        goto L_0x0044a428;
    }
    // 0044a3af  7609                   -jbe 0x44a3ba
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0044a3ba;
    }
    // 0044a3b1  6681fe0048             +cmp si, 0x4800
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18432 /*0x4800*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a3b6  7448                   -je 0x44a400
    if (cpu.flags.zf)
    {
        goto L_0x0044a400;
    }
    // 0044a3b8  eb6e                   -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a3ba:
    // 0044a3ba  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044a3bf  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0044a3c4  e807defcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0044a3c9  8d55fc                 -lea edx, [ebp - 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044a3cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a3ce  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 0044a3d1  e86afeffff             -call 0x44a240
    cpu.esp -= 4;
    sub_44a240(app, cpu);
    if (cpu.terminate) return;
    // 0044a3d6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044a3d8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044a3da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a3dc  741b                   -je 0x44a3f9
    if (cpu.flags.zf)
    {
        goto L_0x0044a3f9;
    }
    // 0044a3de  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0044a3e1  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 0044a3e6  6689411a               -mov word ptr [ecx + 0x1a], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(26) /* 0x1a */) = cpu.ax;
    // 0044a3ea  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044a3ec  6689411c               -mov word ptr [ecx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 0044a3f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044a3f2  ff5730                 -call dword ptr [edi + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a3f5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044a3f7  eb2f                   -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a3f9:
    // 0044a3f9  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0044a3fe  eb28                   -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a400:
    // 0044a400  ba2d000000             -mov edx, 0x2d
    cpu.edx = 45 /*0x2d*/;
    // 0044a405  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044a407  e8c4ddfcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0044a40c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a40e  e81dfbffff             -call 0x449f30
    cpu.esp -= 4;
    sub_449f30(app, cpu);
    if (cpu.terminate) return;
    // 0044a413  eb13                   -jmp 0x44a428
    goto L_0x0044a428;
L_0x0044a415:
    // 0044a415  ba2d000000             -mov edx, 0x2d
    cpu.edx = 45 /*0x2d*/;
    // 0044a41a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a41c  e8afddfcff             -call 0x4181d0
    cpu.esp -= 4;
    sub_4181d0(app, cpu);
    if (cpu.terminate) return;
    // 0044a421  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044a423  e898fcffff             -call 0x44a0c0
    cpu.esp -= 4;
    sub_44a0c0(app, cpu);
    if (cpu.terminate) return;
L_0x0044a428:
    // 0044a428  83fb02                 +cmp ebx, 2
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
    // 0044a42b  7502                   -jne 0x44a42f
    if (!cpu.flags.zf)
    {
        goto L_0x0044a42f;
    }
    // 0044a42d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0044a42f:
    // 0044a42f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0044a431:
    // 0044a431  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a433  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a434  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a435  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a436  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a437  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a438  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44a440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a440  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a441  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a442  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a444  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a449  6683781a64             +cmp word ptr [eax + 0x1a], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0044a44e  7508                   -jne 0x44a458
    if (!cpu.flags.zf)
    {
        goto L_0x0044a458;
    }
    // 0044a450  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0044a455  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a456  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a457  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044a458:
    // 0044a458  8b5016                 -mov edx, dword ptr [eax + 0x16]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a45b  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044a45e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a461  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a464  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044a466  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a467  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a468  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x80 0x00 0x00 0x00 0x00 0x90 */
void Application::sub_44a470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a473  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a474  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a476  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044a478  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a47d  8b4816                 -mov ecx, dword ptr [eax + 0x16]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(22) /* 0x16 */);
    // 0044a480  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
L_0x0044a483:
    // 0044a483  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0044a48a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044a48c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a48f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044a491  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a494  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a49b  7447                   -je 0x44a4e4
    if (cpu.flags.zf)
    {
        goto L_0x0044a4e4;
    }
    // 0044a49d  05e04e6000             -add eax, 0x604ee0
    (cpu.eax) += x86::reg32(x86::sreg32(6311648 /*0x604ee0*/));
    // 0044a4a2  39d8                   +cmp eax, ebx
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
    // 0044a4a4  753b                   -jne 0x44a4e1
    if (!cpu.flags.zf)
    {
        goto L_0x0044a4e1;
    }
    // 0044a4a6  8b1530925500           -mov edx, dword ptr [0x559230]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a4ac  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0044a4af  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a4b2  e899f9ffff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 0044a4b7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a4b9  740d                   -je 0x44a4c8
    if (cpu.flags.zf)
    {
        goto L_0x0044a4c8;
    }
    // 0044a4bb  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a4c0  668b501a               -mov dx, word ptr [eax + 0x1a]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */);
    // 0044a4c4  6689501c               -mov word ptr [eax + 0x1c], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.dx;
L_0x0044a4c8:
    // 0044a4c8  a130925500             -mov eax, dword ptr [0x559230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5607984) /* 0x559230 */);
    // 0044a4cd  668b5018               -mov dx, word ptr [eax + 0x18]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044a4d1  29d1                   +sub ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044a4d3  6689481a               -mov word ptr [eax + 0x1a], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(26) /* 0x1a */) = cpu.cx;
    // 0044a4d7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044a4dc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4de  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044a4e1:
    // 0044a4e1  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a4e2  eb9f                   -jmp 0x44a483
    goto L_0x0044a483;
L_0x0044a4e4:
    // 0044a4e4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044a4e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a4ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 0x8b 0xc9 */
void Application::sub_44a4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0044a4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0044a4f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044a4f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0044a4f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044a4f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0044a4f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0044a4f6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 0044a4f8  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0044a4fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0044a4fd  668b5818               -mov bx, word ptr [eax + 0x18]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0044a501  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044a503  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0044a505:
    // 0044a505  0fbfc3                 -movsx eax, bx
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 0044a508  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0044a50b  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0044a50e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a511  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a513  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a516  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a518  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a51b  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a522  7412                   -je 0x44a536
    if (cpu.flags.zf)
    {
        goto L_0x0044a536;
    }
    // 0044a524  8b80e84e6000           -mov eax, dword ptr [eax + 0x604ee8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311656) /* 0x604ee8 */);
    // 0044a52a  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a52d  39c8                   +cmp eax, ecx
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
    // 0044a52f  7e02                   -jle 0x44a533
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044a533;
    }
    // 0044a531  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0044a533:
    // 0044a533  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0044a534  ebcf                   -jmp 0x44a505
    goto L_0x0044a505;
L_0x0044a536:
    // 0044a536  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0044a538  0f8cfc000000           -jl 0x44a63a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044a63a;
    }
    // 0044a53e  83f904                 +cmp ecx, 4
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
    // 0044a541  7f14                   -jg 0x44a557
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0044a557;
    }
    // 0044a543  b800ff7f3f             -mov eax, 0x3f7fff00
    cpu.eax = 1065352960 /*0x3f7fff00*/;
    // 0044a548  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0044a54a  a3ac3a5600             -mov dword ptr [0x563aac], eax
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.eax;
    // 0044a54f  891da83a5600           -mov dword ptr [0x563aa8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.ebx;
    // 0044a555  eb16                   -jmp 0x44a56d
    goto L_0x0044a56d;
L_0x0044a557:
    // 0044a557  bb80008037             -mov ebx, 0x37800080
    cpu.ebx = 931135616 /*0x37800080*/;
    // 0044a55c  ba00ff7f3f             -mov edx, 0x3f7fff00
    cpu.edx = 1065352960 /*0x3f7fff00*/;
    // 0044a561  891dac3a5600           -mov dword ptr [0x563aac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.ebx;
    // 0044a567  8915a83a5600           -mov dword ptr [0x563aa8], edx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.edx;
L_0x0044a56d:
    // 0044a56d  668b4618               -mov ax, word ptr [esi + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0044a571  668945fc               -mov word ptr [ebp - 4], ax
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ax;
L_0x0044a575:
    // 0044a575  8b55fa                 -mov edx, dword ptr [ebp - 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0044a578  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0044a57b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0044a582  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a584  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044a587  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044a589  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0044a58c  83b8e04e600000         +cmp dword ptr [eax + 0x604ee0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6311648) /* 0x604ee0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a593  7456                   -je 0x44a5eb
    if (cpu.flags.zf)
    {
        goto L_0x0044a5eb;
    }
    // 0044a595  bbe04e6000             -mov ebx, 0x604ee0
    cpu.ebx = 6311648 /*0x604ee0*/;
    // 0044a59a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044a59c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0044a59f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a5a2  39c1                   +cmp ecx, eax
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
    // 0044a5a4  753f                   -jne 0x44a5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0044a5e5;
    }
    // 0044a5a6  8b4616                 -mov eax, dword ptr [esi + 0x16]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 0044a5a9  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a5ac  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 0044a5af  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0044a5b2  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044a5b5  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 0044a5b8  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044a5bb  0345f8                 -add eax, dword ptr [ebp - 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 0044a5be  39c2                   +cmp edx, eax
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
    // 0044a5c0  7507                   -jne 0x44a5c9
    if (!cpu.flags.zf)
    {
        goto L_0x0044a5c9;
    }
    // 0044a5c2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044a5c7  eb02                   -jmp 0x44a5cb
    goto L_0x0044a5cb;
L_0x0044a5c9:
    // 0044a5c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0044a5cb:
    // 0044a5cb  837b2c00               +cmp dword ptr [ebx + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a5cf  7414                   -je 0x44a5e5
    if (cpu.flags.zf)
    {
        goto L_0x0044a5e5;
    }
    // 0044a5d1  f6430510               +test byte ptr [ebx + 5], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) & 16 /*0x10*/));
    // 0044a5d5  750e                   -jne 0x44a5e5
    if (!cpu.flags.zf)
    {
        goto L_0x0044a5e5;
    }
    // 0044a5d7  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0044a5d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044a5da  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044a5dc  ff532c                 -call dword ptr [ebx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0044a5df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a5e1  7402                   -je 0x44a5e5
    if (cpu.flags.zf)
    {
        goto L_0x0044a5e5;
    }
    // 0044a5e3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0044a5e5:
    // 0044a5e5  66ff45fc               +inc word ptr [ebp - 4]
    {
        auto tmp = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        cpu.flags.of = ~(1 & (tmp >> 15));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 15);
        cpu.set_szp(tmp);
    }
    // 0044a5e9  eb8a                   -jmp 0x44a575
    goto L_0x0044a575;
L_0x0044a5eb:
    // 0044a5eb  833d3492550000         +cmp dword ptr [0x559234], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5607988) /* 0x559234 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a5f2  7416                   -je 0x44a60a
    if (cpu.flags.zf)
    {
        goto L_0x0044a60a;
    }
    // 0044a5f4  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a5fb  7437                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a5fd  e83e6affff             -call 0x441040
    cpu.esp -= 4;
    sub_441040(app, cpu);
    if (cpu.terminate) return;
    // 0044a602  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a604  742e                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a606  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0044a608  eb2a                   -jmp 0x44a634
    goto L_0x0044a634;
L_0x0044a60a:
    // 0044a60a  83f908                 +cmp ecx, 8
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
    // 0044a60d  7525                   -jne 0x44a634
    if (!cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a60f  833de0227a0000         +cmp dword ptr [0x7a22e0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(8004320) /* 0x7a22e0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044a616  741c                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a618  bac48f5300             -mov edx, 0x538fc4
    cpu.edx = 5476292 /*0x538fc4*/;
    // 0044a61d  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0044a620  e8eb3c0a00             -call 0x4ee310
    cpu.esp -= 4;
    sub_4ee310(app, cpu);
    if (cpu.terminate) return;
    // 0044a625  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a627  740b                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a629  e8126affff             -call 0x441040
    cpu.esp -= 4;
    sub_441040(app, cpu);
    if (cpu.terminate) return;
    // 0044a62e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044a630  7402                   -je 0x44a634
    if (cpu.flags.zf)
    {
        goto L_0x0044a634;
    }
    // 0044a632  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0044a634:
    // 0044a634  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044a635  e9fcfeffff             -jmp 0x44a536
    goto L_0x0044a536;
L_0x0044a63a:
    // 0044a63a  bb80008037             -mov ebx, 0x37800080
    cpu.ebx = 931135616 /*0x37800080*/;
    // 0044a63f  b900ff7f3f             -mov ecx, 0x3f7fff00
    cpu.ecx = 1065352960 /*0x3f7fff00*/;
    // 0044a644  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0044a646  891dac3a5600           -mov dword ptr [0x563aac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5651116) /* 0x563aac */) = cpu.ebx;
    // 0044a64c  890da83a5600           -mov dword ptr [0x563aa8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5651112) /* 0x563aa8 */) = cpu.ecx;
    // 0044a652  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044a654  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a655  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a656  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a657  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a658  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a659  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044a65a  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
