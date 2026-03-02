#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47e9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047e9a0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047e9a1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047e9a2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047e9a3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047e9a5  e852630100             -call 0x494cfc
    cpu.esp -= 4;
    sub_494cfc(app, cpu);
    if (cpu.terminate) return;
    // 0047e9aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047e9ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047e9ae  0f8c75000000           -jl 0x47ea29
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ea29;
    }
    // 0047e9b4  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0047e9bb  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047e9bd  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047e9c0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e9c2  81c200845200           -add edx, 0x528400
    (cpu.edx) += x86::reg32(x86::sreg32(5407744 /*0x528400*/));
    // 0047e9c8  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047e9cb  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047e9ce  39d8                   +cmp eax, ebx
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
    // 0047e9d0  7460                   -je 0x47ea32
    if (cpu.flags.zf)
    {
        goto L_0x0047ea32;
    }
    // 0047e9d2  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047e9d3  0fb67a3b               -movzx edi, byte ptr [edx + 0x3b]
    cpu.edi = x86::reg32(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 0047e9d7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047e9d9  745d                   -je 0x47ea38
    if (cpu.flags.zf)
    {
        goto L_0x0047ea38;
    }
    // 0047e9db  b900845200             -mov ecx, 0x528400
    cpu.ecx = 5407744 /*0x528400*/;
    // 0047e9e0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047e9e2:
    // 0047e9e2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047e9e4  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0047e9e7  39fa                   +cmp edx, edi
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
    // 0047e9e9  752e                   -jne 0x47ea19
    if (!cpu.flags.zf)
    {
        goto L_0x0047ea19;
    }
    // 0047e9eb  80790c01               +cmp byte ptr [ecx + 0xc], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047e9ef  7528                   -jne 0x47ea19
    if (!cpu.flags.zf)
    {
        goto L_0x0047ea19;
    }
    // 0047e9f1  833900                 +cmp dword ptr [ecx], 0
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
    // 0047e9f4  7c23                   -jl 0x47ea19
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ea19;
    }
    // 0047e9f6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047e9f8  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047e9fb  894120                 -mov dword ptr [ecx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047e9fe  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ea00  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047ea07  e884a40100             -call 0x498e90
    cpu.esp -= 4;
    sub_498e90(app, cpu);
    if (cpu.terminate) return;
    // 0047ea0c  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 0047ea0f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ea11  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0047ea14  e84bfbffff             -call 0x47e564
    cpu.esp -= 4;
    sub_47e564(app, cpu);
    if (cpu.terminate) return;
L_0x0047ea19:
    // 0047ea19  43                     -inc ebx
    (cpu.ebx)++;
    // 0047ea1a  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047ea1d  83fb10                 +cmp ebx, 0x10
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ea20  7cc0                   -jl 0x47e9e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047e9e2;
    }
    // 0047ea22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ea24  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea25  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea26  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea27  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea28  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ea29:
    // 0047ea29  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047ea2e  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea2f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea30  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea31  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ea32:
    // 0047ea32  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ea34  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea35  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea36  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea37  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ea38:
    // 0047ea38  894220                 -mov dword ptr [edx + 0x20], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047ea3b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ea3d  897a18                 -mov dword ptr [edx + 0x18], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0047ea40  e84ba40100             -call 0x498e90
    cpu.esp -= 4;
    sub_498e90(app, cpu);
    if (cpu.terminate) return;
    // 0047ea45  8b522e                 -mov edx, dword ptr [edx + 0x2e]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 0047ea48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ea4a  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0047ea4d  e812fbffff             -call 0x47e564
    cpu.esp -= 4;
    sub_47e564(app, cpu);
    if (cpu.terminate) return;
    // 0047ea52  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ea54  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea55  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea56  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea57  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ea5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ea5c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ea5d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ea5f  803d6cab4c0000         +cmp byte ptr [0x4cab6c], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5024620) /* 0x4cab6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ea66  7410                   -je 0x47ea78
    if (cpu.flags.zf)
    {
        goto L_0x0047ea78;
    }
    // 0047ea68  83fa7f                 +cmp edx, 0x7f
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
    // 0047ea6b  7f04                   -jg 0x47ea71
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ea71;
    }
    // 0047ea6d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ea6f  7d0e                   -jge 0x47ea7f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ea7f;
    }
L_0x0047ea71:
    // 0047ea71  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047ea76  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea77  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ea78:
    // 0047ea78  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047ea7d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ea7f:
    // 0047ea7f  e86c5e0100             -call 0x4948f0
    cpu.esp -= 4;
    sub_4948f0(app, cpu);
    if (cpu.terminate) return;
    // 0047ea84  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ea86  e815ffffff             -call 0x47e9a0
    cpu.esp -= 4;
    sub_47e9a0(app, cpu);
    if (cpu.terminate) return;
    // 0047ea8b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ea8d  e8725e0100             -call 0x494904
    cpu.esp -= 4;
    sub_494904(app, cpu);
    if (cpu.terminate) return;
    // 0047ea92  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ea94  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ea95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47eaa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eaa0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eaa1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eaa2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eaa3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047eaa6  8b1d548d4c00           -mov ebx, dword ptr [0x4c8d54]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5016916) /* 0x4c8d54 */);
    // 0047eaac  8b35508d4c00           -mov esi, dword ptr [0x4c8d50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5016912) /* 0x4c8d50 */);
    // 0047eab2  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0047eab9  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0047eabb  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047eabe  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047eac1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047eac3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047eac5  e8ba250100             -call 0x491084
    cpu.esp -= 4;
    sub_491084(app, cpu);
    if (cpu.terminate) return;
    // 0047eaca  8b35508d4c00           -mov esi, dword ptr [0x4c8d50]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5016912) /* 0x4c8d50 */);
    // 0047ead0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ead2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ead4  741d                   -je 0x47eaf3
    if (cpu.flags.zf)
    {
        goto L_0x0047eaf3;
    }
    // 0047ead6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ead7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ead9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047eadb  7e13                   -jle 0x47eaf0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047eaf0;
    }
L_0x0047eadd:
    // 0047eadd  c7430445455246         -mov dword ptr [ebx + 4], 0x46524545
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1179796805 /*0x46524545*/;
    // 0047eae4  42                     -inc edx
    (cpu.edx)++;
    // 0047eae5  890b                   -mov dword ptr [ebx], ecx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 0047eae7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047eae9  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047eaec  39f2                   +cmp edx, esi
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
    // 0047eaee  7ced                   -jl 0x47eadd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047eadd;
    }
L_0x0047eaf0:
    // 0047eaf0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047eaf2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047eaf3:
    // 0047eaf3  8935508d4c00           -mov dword ptr [0x4c8d50], esi
    *app->getMemory<x86::reg32>(x86::reg32(5016912) /* 0x4c8d50 */) = cpu.esi;
    // 0047eaf9  891d548d4c00           -mov dword ptr [0x4c8d54], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5016916) /* 0x4c8d54 */) = cpu.ebx;
    // 0047eaff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047eb02  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb03  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb04  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47eb08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eb08  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eb09  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eb0a  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047eb0b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047eb0d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047eb0f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eb11  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eb12  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eb14  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eb15  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eb16  2eff15a0554b00         -call dword ptr cs:[0x4b55a0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937120) /* 0x4b55a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eb1d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047eb1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047eb21  7c04                   -jl 0x47eb27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047eb27;
    }
    // 0047eb23  39f8                   +cmp eax, edi
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
    // 0047eb25  7c0c                   -jl 0x47eb33
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047eb33;
    }
L_0x0047eb27:
    // 0047eb27  81fb02010000           -cmp ebx, 0x102
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(258 /*0x102*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eb2d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047eb2f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb30  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb31  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047eb33:
    // 0047eb33  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0047eb36  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb37  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb38  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47eb3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eb3c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047eb40  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eb42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047eb44  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47eb48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eb48  833d98ba510000         +cmp dword ptr [0x51ba98], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5356184) /* 0x51ba98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047eb4f  7401                   -je 0x47eb52
    if (cpu.flags.zf)
    {
        goto L_0x0047eb52;
    }
    // 0047eb51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047eb52:
    // 0047eb52  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eb53  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eb54  2eff159c544b00         -call dword ptr cs:[0x4b549c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936860) /* 0x4b549c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eb5b  6a02                   -push 2
    *app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047eb5d  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eb5f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eb61  6890ba5100             -push 0x51ba90
    *app->getMemory<x86::reg32>(cpu.esp-4) = 5356176 /*0x51ba90*/;
    cpu.esp -= 4;
    // 0047eb66  a394ba5100             -mov dword ptr [0x51ba94], eax
    *app->getMemory<x86::reg32>(x86::reg32(5356180) /* 0x51ba94 */) = cpu.eax;
    // 0047eb6b  2eff1594544b00         -call dword ptr cs:[0x4b5494]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936852) /* 0x4b5494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eb72  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eb73  2eff15a0544b00         -call dword ptr cs:[0x4b54a0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936864) /* 0x4b54a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eb7a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eb7b  2eff1594544b00         -call dword ptr cs:[0x4b5494]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936852) /* 0x4b5494 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eb82  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047eb83  2eff1548544b00         -call dword ptr cs:[0x4b5448]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936776) /* 0x4b5448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eb8a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047eb8f  e80cffffff             -call 0x47eaa0
    cpu.esp -= 4;
    sub_47eaa0(app, cpu);
    if (cpu.terminate) return;
    // 0047eb94  890d98ba5100           -mov dword ptr [0x51ba98], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5356184) /* 0x51ba98 */) = cpu.ecx;
    // 0047eb9a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb9b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eb9c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47eba0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eba0  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eba1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047eba2  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047eba3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047eba6  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047eba8  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047ebaa  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ebae  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047ebb0  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ebb1  6a04                   -push 4
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 0047ebb3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ebb4  683ceb4700             -push 0x47eb3c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4713276 /*0x47eb3c*/;
    cpu.esp -= 4;
    // 0047ebb9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ebba  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ebbc  2eff1538544b00         -call dword ptr cs:[0x4b5438]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936760) /* 0x4b5438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ebc3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047ebc5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ebc7  7441                   -je 0x47ec0a
    if (cpu.flags.zf)
    {
        goto L_0x0047ec0a;
    }
    // 0047ebc9  833d98ba510000         +cmp dword ptr [0x51ba98], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5356184) /* 0x51ba98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ebd0  7507                   -jne 0x47ebd9
    if (!cpu.flags.zf)
    {
        goto L_0x0047ebd9;
    }
    // 0047ebd2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ebd4  e86fffffff             -call 0x47eb48
    cpu.esp -= 4;
    sub_47eb48(app, cpu);
    if (cpu.terminate) return;
L_0x0047ebd9:
    // 0047ebd9  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047ebe0  893b                   -mov dword ptr [ebx], edi
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0047ebe2  896b04                 -mov dword ptr [ebx + 4], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0047ebe5  897308                 -mov dword ptr [ebx + 8], esi
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0047ebe8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047ebeb  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ebed  894310                 -mov dword ptr [ebx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047ebf0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ebf2  e8a9010000             -call 0x47eda0
    cpu.esp -= 4;
    sub_47eda0(app, cpu);
    if (cpu.terminate) return;
    // 0047ebf7  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ebf8  2eff1534554b00         -call dword ptr cs:[0x4b5534]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937012) /* 0x4b5534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ebff  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047ec01  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ec03  2eff1574554b00         -call dword ptr cs:[0x4b5574]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937076) /* 0x4b5574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047ec0a:
    // 0047ec0a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047ec0c  740e                   -je 0x47ec1c
    if (cpu.flags.zf)
    {
        goto L_0x0047ec1c;
    }
    // 0047ec0e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047ec13  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ec16  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec17  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec18  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec19  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047ec1c:
    // 0047ec1c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ec1e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ec21  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec22  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec23  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec24  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47ec28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ec28  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ec2a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ec30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ec30  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ec31  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ec32  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ec33  83f8ff                 +cmp eax, -1
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
    // 0047ec36  7418                   -je 0x47ec50
    if (cpu.flags.zf)
    {
        goto L_0x0047ec50;
    }
    // 0047ec38  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax);
L_0x0047ec3a:
    // 0047ec3a  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047ec3c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ec3d  2eff1578554b00         -call dword ptr cs:[0x4b5578]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937080) /* 0x4b5578 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ec44  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ec45  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ec4c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec4d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec4e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ec50:
    // 0047ec50  2eff15a0544b00         -call dword ptr cs:[0x4b54a0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936864) /* 0x4b54a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ec57  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ec59  ebdf                   -jmp 0x47ec3a
    goto L_0x0047ec3a;
}

/* align: skip 0x90 */
void Application::sub_47ec5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ec5c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ec5d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ec5e  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047ec60  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec61  2eff1574554b00         -call dword ptr cs:[0x4b5574]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937076) /* 0x4b5574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ec68  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec69  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47ec6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ec6c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ec6d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ec6e  8b0d34824c00           -mov ecx, dword ptr [0x4c8234]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0047ec74  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ec76  7505                   -jne 0x47ec7d
    if (!cpu.flags.zf)
    {
        goto L_0x0047ec7d;
    }
    // 0047ec78  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x0047ec7d:
    // 0047ec7d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ec7f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047ec82  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ec84  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047ec87  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047ec89  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047ec8c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ec8e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047ec91  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ec93  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ec95  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ec98  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047ec9a  6a01                   -push 1
    *app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047ec9c  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec9d  2eff1574554b00         -call dword ptr cs:[0x4b5574]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937076) /* 0x4b5574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eca4  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eca5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eca6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47eca8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eca8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eca9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ecaa  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ecab  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ecad  2eff159c544b00         -call dword ptr cs:[0x4b549c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936860) /* 0x4b549c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ecb4  8b0d98ba5100           -mov ecx, dword ptr [0x51ba98]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5356184) /* 0x51ba98 */);
    // 0047ecba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ecbc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ecbe  7415                   -je 0x47ecd5
    if (cpu.flags.zf)
    {
        goto L_0x0047ecd5;
    }
L_0x0047ecc0:
    // 0047ecc0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047ecc2  7520                   -jne 0x47ece4
    if (!cpu.flags.zf)
    {
        goto L_0x0047ece4;
    }
    // 0047ecc4  3b1594ba5100           +cmp edx, dword ptr [0x51ba94]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5356180) /* 0x51ba94 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ecca  7512                   -jne 0x47ecde
    if (!cpu.flags.zf)
    {
        goto L_0x0047ecde;
    }
L_0x0047eccc:
    // 0047eccc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047ecd1  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecd2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecd3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecd4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ecd5:
    // 0047ecd5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047ecd7  e86cfeffff             -call 0x47eb48
    cpu.esp -= 4;
    sub_47eb48(app, cpu);
    if (cpu.terminate) return;
    // 0047ecdc  ebe2                   -jmp 0x47ecc0
    goto L_0x0047ecc0;
L_0x0047ecde:
    // 0047ecde  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ece0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ece1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ece2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ece3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ece4:
    // 0047ece4  83fbff                 +cmp ebx, -1
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
    // 0047ece7  74e3                   -je 0x47eccc
    if (cpu.flags.zf)
    {
        goto L_0x0047eccc;
    }
    // 0047ece9  3b5310                 +cmp edx, dword ptr [ebx + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ecec  74de                   -je 0x47eccc
    if (cpu.flags.zf)
    {
        goto L_0x0047eccc;
    }
    // 0047ecee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ecf0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecf1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecf2  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecf3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ecf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ecf4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ecf5  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ecf6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ecf8  833d98ba510000         +cmp dword ptr [0x51ba98], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5356184) /* 0x51ba98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ecff  742f                   -je 0x47ed30
    if (cpu.flags.zf)
    {
        goto L_0x0047ed30;
    }
L_0x0047ed01:
    // 0047ed01  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ed03  7534                   -jne 0x47ed39
    if (!cpu.flags.zf)
    {
        goto L_0x0047ed39;
    }
    // 0047ed05  a190ba5100             -mov eax, dword ptr [0x51ba90]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356176) /* 0x51ba90 */);
L_0x0047ed0a:
    // 0047ed0a  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ed0b  2eff15f0544b00         -call dword ptr cs:[0x4b54f0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936944) /* 0x4b54f0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ed12  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ed14  7c35                   -jl 0x47ed4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ed4b;
    }
    // 0047ed16  0f8e5b000000           -jle 0x47ed77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ed77;
    }
    // 0047ed1c  83f802                 +cmp eax, 2
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
    // 0047ed1f  7c4e                   -jl 0x47ed6f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ed6f;
    }
    // 0047ed21  7e44                   -jle 0x47ed67
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ed67;
    }
    // 0047ed23  83f80f                 +cmp eax, 0xf
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
    // 0047ed26  754f                   -jne 0x47ed77
    if (!cpu.flags.zf)
    {
        goto L_0x0047ed77;
    }
    // 0047ed28  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0047ed2d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed2e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed30:
    // 0047ed30  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047ed32  e811feffff             -call 0x47eb48
    cpu.esp -= 4;
    sub_47eb48(app, cpu);
    if (cpu.terminate) return;
    // 0047ed37  ebc8                   -jmp 0x47ed01
    goto L_0x0047ed01;
L_0x0047ed39:
    // 0047ed39  83faff                 +cmp edx, -1
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
    // 0047ed3c  7404                   -je 0x47ed42
    if (cpu.flags.zf)
    {
        goto L_0x0047ed42;
    }
    // 0047ed3e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0047ed40  ebc8                   -jmp 0x47ed0a
    goto L_0x0047ed0a;
L_0x0047ed42:
    // 0047ed42  2eff15a0544b00         -call dword ptr cs:[0x4b54a0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936864) /* 0x4b54a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ed49  ebbf                   -jmp 0x47ed0a
    goto L_0x0047ed0a;
L_0x0047ed4b:
    // 0047ed4b  83f8fe                 +cmp eax, -2
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
    // 0047ed4e  7d0d                   -jge 0x47ed5d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ed5d;
    }
    // 0047ed50  83f8f1                 +cmp eax, -0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-15 /*-0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ed53  7522                   -jne 0x47ed77
    if (!cpu.flags.zf)
    {
        goto L_0x0047ed77;
    }
    // 0047ed55  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 0047ed5a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed5b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed5d:
    // 0047ed5d  7f1d                   -jg 0x47ed7c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ed7c;
    }
    // 0047ed5f  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0047ed64  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed65  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed67:
    // 0047ed67  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0047ed6c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed6d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed6e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed6f:
    // 0047ed6f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047ed74  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed75  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed77:
    // 0047ed77  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ed79  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed7a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed7c:
    // 0047ed7c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047ed81  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed82  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47eda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047eda0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eda1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eda2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047eda4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047eda6  833d98ba510000         +cmp dword ptr [0x51ba98], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5356184) /* 0x51ba98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047edad  742a                   -je 0x47edd9
    if (cpu.flags.zf)
    {
        goto L_0x0047edd9;
    }
L_0x0047edaf:
    // 0047edaf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047edb1  752f                   -jne 0x47ede2
    if (!cpu.flags.zf)
    {
        goto L_0x0047ede2;
    }
    // 0047edb3  8b0d90ba5100           -mov ecx, dword ptr [0x51ba90]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5356176) /* 0x51ba90 */);
    // 0047edb9  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0047edbc  83f806                 +cmp eax, 6
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
    // 0047edbf  7764                   -ja 0x47ee25
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047ee25;
    }
    // 0047edc1  ff248584ed4700         -jmp dword ptr [eax*4 + 0x47ed84]
    cpu.ip = *app->getMemory<x86::reg32>(4713860 + cpu.eax * 4); goto dynamic_jump;
  case 0x0047edc8:
    // 0047edc8  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
L_0x0047edcd:
    // 0047edcd  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047edce  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047edcf  2eff156c554b00         -call dword ptr cs:[0x4b556c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937068) /* 0x4b556c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047edd6  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edd7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047edd9:
    // 0047edd9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047eddb  e868fdffff             -call 0x47eb48
    cpu.esp -= 4;
    sub_47eb48(app, cpu);
    if (cpu.terminate) return;
    // 0047ede0  ebcd                   -jmp 0x47edaf
    goto L_0x0047edaf;
L_0x0047ede2:
    // 0047ede2  83f9ff                 +cmp ecx, -1
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
    // 0047ede5  7411                   -je 0x47edf8
    if (cpu.flags.zf)
    {
        goto L_0x0047edf8;
    }
    // 0047ede7  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047ede9  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0047edec  83f806                 +cmp eax, 6
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
    // 0047edef  7734                   -ja 0x47ee25
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047ee25;
    }
    // 0047edf1  ff248584ed4700         -jmp dword ptr [eax*4 + 0x47ed84]
    cpu.ip = *app->getMemory<x86::reg32>(4713860 + cpu.eax * 4); goto dynamic_jump;
L_0x0047edf8:
    // 0047edf8  2eff15a0544b00         -call dword ptr cs:[0x4b54a0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936864) /* 0x4b54a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047edff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ee01  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0047ee04  83f806                 +cmp eax, 6
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
    // 0047ee07  771c                   -ja 0x47ee25
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047ee25;
    }
    // 0047ee09  ff248584ed4700         -jmp dword ptr [eax*4 + 0x47ed84]
    cpu.ip = *app->getMemory<x86::reg32>(4713860 + cpu.eax * 4); goto dynamic_jump;
  case 0x0047ee10:
    // 0047ee10  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 0047ee15  ebb6                   -jmp 0x47edcd
    goto L_0x0047edcd;
  case 0x0047ee17:
    // 0047ee17  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0047ee1c  ebaf                   -jmp 0x47edcd
    goto L_0x0047edcd;
  case 0x0047ee1e:
    // 0047ee1e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047ee23  eba8                   -jmp 0x47edcd
    goto L_0x0047edcd;
  case 0x0047ee25:
L_0x0047ee25:
    // 0047ee25  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ee27  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ee28  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ee29  2eff156c554b00         -call dword ptr cs:[0x4b556c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937068) /* 0x4b556c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ee30  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee31  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee32  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047ee33:
    // 0047ee33  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047ee38  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ee39  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ee3a  2eff156c554b00         -call dword ptr cs:[0x4b556c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937068) /* 0x4b556c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ee41  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee42  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee43  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0047ee44:
    // 0047ee44  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0047ee49  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ee4a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ee4b  2eff156c554b00         -call dword ptr cs:[0x4b556c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937068) /* 0x4b556c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ee52  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee53  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee54  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ee58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ee58  833d588d4c0000         +cmp dword ptr [0x4c8d58], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5016920) /* 0x4c8d58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ee5f  750a                   -jne 0x47ee6b
    if (!cpu.flags.zf)
    {
        goto L_0x0047ee6b;
    }
    // 0047ee61  e852010000             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0047ee66  a3588d4c00             -mov dword ptr [0x4c8d58], eax
    *app->getMemory<x86::reg32>(x86::reg32(5016920) /* 0x4c8d58 */) = cpu.eax;
L_0x0047ee6b:
    // 0047ee6b  a1588d4c00             -mov eax, dword ptr [0x4c8d58]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016920) /* 0x4c8d58 */);
    // 0047ee70  e893010000             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047ee75  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047ee7a  e875feffff             -call 0x47ecf4
    cpu.esp -= 4;
    sub_47ecf4(app, cpu);
    if (cpu.terminate) return;
    // 0047ee7f  83f803                 +cmp eax, 3
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
    // 0047ee82  7501                   -jne 0x47ee85
    if (!cpu.flags.zf)
    {
        goto L_0x0047ee85;
    }
    // 0047ee84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ee85:
    // 0047ee85  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ee86  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0047ee8b  a35c8d4c00             -mov dword ptr [0x4c8d5c], eax
    *app->getMemory<x86::reg32>(x86::reg32(5016924) /* 0x4c8d5c */) = cpu.eax;
    // 0047ee90  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047ee95  e806ffffff             -call 0x47eda0
    cpu.esp -= 4;
    sub_47eda0(app, cpu);
    if (cpu.terminate) return;
    // 0047ee9a  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ee9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ee9c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ee9d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047eea2  8b155c8d4c00           -mov edx, dword ptr [0x4c8d5c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5016924) /* 0x4c8d5c */);
    // 0047eea8  e8f3feffff             -call 0x47eda0
    cpu.esp -= 4;
    sub_47eda0(app, cpu);
    if (cpu.terminate) return;
    // 0047eead  a1588d4c00             -mov eax, dword ptr [0x4c8d58]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016920) /* 0x4c8d58 */);
    // 0047eeb2  e869010000             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047eeb7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eeb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47eebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eebc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eebd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eebe  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eec0  2eff1558544b00         -call dword ptr cs:[0x4b5458]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936792) /* 0x4b5458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eec7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eec8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eec9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47eecc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eecc  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eecd  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eece  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eed0  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eed2  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eed4  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047eed6  2eff1528544b00         -call dword ptr cs:[0x4b5428]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936744) /* 0x4b5428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eedd  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eede  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eedf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47eee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eee0  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eee1  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eee2  2eff1558554b00         -call dword ptr cs:[0x4b5558]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4937048) /* 0x4b5558 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047eee9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047eeea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47eeec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eeec  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eeed  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eeee  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047eef1  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047eef4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047eef6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047eefb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047eefd  e806fcffff             -call 0x47eb08
    cpu.esp -= 4;
    sub_47eb08(app, cpu);
    if (cpu.terminate) return;
    // 0047ef02  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ef05  750b                   -jne 0x47ef12
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef12;
    }
    // 0047ef07  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047ef0c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef0f  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef10  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ef12:
    // 0047ef12  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ef14  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef17  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef18  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ef1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ef1c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ef1d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ef1e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef21  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047ef24  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0047ef29  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047ef2b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047ef30  e8d3fbffff             -call 0x47eb08
    cpu.esp -= 4;
    sub_47eb08(app, cpu);
    if (cpu.terminate) return;
    // 0047ef35  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef38  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef39  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47ef3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ef3c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ef3d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ef3e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef41  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047ef44  8b0d34824c00           -mov ecx, dword ptr [0x4c8234]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5014068) /* 0x4c8234 */);
    // 0047ef4a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ef4c  7505                   -jne 0x47ef53
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef53;
    }
    // 0047ef4e  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x0047ef53:
    // 0047ef53  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047ef5a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ef5c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047ef5f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047ef61  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047ef64  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ef66  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047ef69  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047ef6b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ef6d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ef70  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047ef72  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047ef74  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ef76  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047ef7b  e888fbffff             -call 0x47eb08
    cpu.esp -= 4;
    sub_47eb08(app, cpu);
    if (cpu.terminate) return;
    // 0047ef80  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ef83  750b                   -jne 0x47ef90
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef90;
    }
    // 0047ef85  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047ef8a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef8d  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef8e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ef90:
    // 0047ef90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ef92  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ef95  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef96  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef97  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ef98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ef98  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ef99  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0047ef9e  e865fbffff             -call 0x47eb08
    cpu.esp -= 4;
    sub_47eb08(app, cpu);
    if (cpu.terminate) return;
    // 0047efa3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47efa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047efa8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047efa9  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047efaa  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047efab  2eff1524544b00         -call dword ptr cs:[0x4b5424]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936740) /* 0x4b5424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047efb2  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efb3  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47efb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047efb8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047efb9  833d548d4c0000         +cmp dword ptr [0x4c8d54], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5016916) /* 0x4c8d54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047efc0  740e                   -je 0x47efd0
    if (cpu.flags.zf)
    {
        goto L_0x0047efd0;
    }
    // 0047efc2  8b0d548d4c00           -mov ecx, dword ptr [0x4c8d54]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5016916) /* 0x4c8d54 */);
    // 0047efc8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047efca  7517                   -jne 0x47efe3
    if (!cpu.flags.zf)
    {
        goto L_0x0047efe3;
    }
    // 0047efcc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047efce  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047efd0:
    // 0047efd0  e8cbfaffff             -call 0x47eaa0
    cpu.esp -= 4;
    sub_47eaa0(app, cpu);
    if (cpu.terminate) return;
    // 0047efd5  8b0d548d4c00           -mov ecx, dword ptr [0x4c8d54]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5016916) /* 0x4c8d54 */);
    // 0047efdb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047efdd  7504                   -jne 0x47efe3
    if (!cpu.flags.zf)
    {
        goto L_0x0047efe3;
    }
    // 0047efdf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047efe1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047efe2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047efe3:
    // 0047efe3  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047efe4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047efe5  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047efe7  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 0047efec  a3548d4c00             -mov dword ptr [0x4c8d54], eax
    *app->getMemory<x86::reg32>(x86::reg32(5016916) /* 0x4c8d54 */) = cpu.eax;
    // 0047eff1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047eff3  e8e4000000             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 0047eff8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eff9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047effb  2eff150c554b00         -call dword ptr cs:[0x4b550c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936972) /* 0x4b550c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f002  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f004  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f005  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f006  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f007  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f008  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f00a  7501                   -jne 0x47f00d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f00d;
    }
    // 0047f00c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f00d:
    // 0047f00d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f00e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f00f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f010  2eff154c544b00         -call dword ptr cs:[0x4b544c]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936780) /* 0x4b544c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f017  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047f01c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f01d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f01e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f020  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f022  7501                   -jne 0x47f025
    if (!cpu.flags.zf)
    {
        goto L_0x0047f025;
    }
    // 0047f024  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f025:
    // 0047f025  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f026  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f027  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f028  2eff1510554b00         -call dword ptr cs:[0x4b5510]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936976) /* 0x4b5510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f02f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f030  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f031  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f034(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f034  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f035  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f037  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f039  7502                   -jne 0x47f03d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f03d;
    }
    // 0047f03b  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f03c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f03d:
    // 0047f03d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f03e  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f03f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f040  2eff1540544b00         -call dword ptr cs:[0x4b5440]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936768) /* 0x4b5440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f047  a1548d4c00             -mov eax, dword ptr [0x4c8d54]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5016916) /* 0x4c8d54 */);
    // 0047f04c  c7430445455246         -mov dword ptr [ebx + 4], 0x46524545
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1179796805 /*0x46524545*/;
    // 0047f053  891d548d4c00           -mov dword ptr [0x4c8d54], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5016916) /* 0x4c8d54 */) = cpu.ebx;
    // 0047f059  8903                   -mov dword ptr [ebx], eax
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0047f05b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f05c  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f05d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f05e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f060  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f062  750b                   -jne 0x47f06f
    if (!cpu.flags.zf)
    {
        goto L_0x0047f06f;
    }
    // 0047f064  a19cba5100             -mov eax, dword ptr [0x51ba9c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356188) /* 0x51ba9c */);
    // 0047f069  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047f06e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f06f:
    // 0047f06f  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f070  8b159cba5100           -mov edx, dword ptr [0x51ba9c]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356188) /* 0x51ba9c */);
    // 0047f076  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047f07c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f07d  68ece24b00             -push 0x4be2ec
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4973292 /*0x4be2ec*/;
    cpu.esp -= 4;
    // 0047f082  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f083  e899b3ffff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0047f088  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f08b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f08c  a19cba5100             -mov eax, dword ptr [0x51ba9c]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356188) /* 0x51ba9c */);
    // 0047f091  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047f096  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f098  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f099  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f09a  2eff15c0544b00         -call dword ptr cs:[0x4b54c0]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4936896) /* 0x4b54c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f0a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f0a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f0a5  7503                   -jne 0x47f0aa
    if (!cpu.flags.zf)
    {
        goto L_0x0047f0aa;
    }
L_0x0047f0a7:
    // 0047f0a7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0a8  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f0aa:
    // 0047f0aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f0ac  e8f7fbffff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 0047f0b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f0b3  74f2                   -je 0x47f0a7
    if (cpu.flags.zf)
    {
        goto L_0x0047f0a7;
    }
    // 0047f0b5  89159cba5100           -mov dword ptr [0x51ba9c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5356188) /* 0x51ba9c */) = cpu.edx;
    // 0047f0bb  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0bc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f0c0  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f0c1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f0c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f0c5  7502                   -jne 0x47f0c9
    if (!cpu.flags.zf)
    {
        goto L_0x0047f0c9;
    }
L_0x0047f0c7:
    // 0047f0c7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f0c9:
    // 0047f0c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f0cb  e8d8fbffff             -call 0x47eca8
    cpu.esp -= 4;
    sub_47eca8(app, cpu);
    if (cpu.terminate) return;
    // 0047f0d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f0d2  74f3                   -je 0x47f0c7
    if (cpu.flags.zf)
    {
        goto L_0x0047f0c7;
    }
    // 0047f0d4  89159cba5100           -mov dword ptr [0x51ba9c], edx
    *app->getMemory<x86::reg32>(x86::reg32(5356188) /* 0x51ba9c */) = cpu.edx;
    // 0047f0da  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f0dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f0dc  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f0dd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f0df  e80d000000             -call 0x47f0f1
    cpu.esp -= 4;
    sub_47f0f1(app, cpu);
    if (cpu.terminate) return;
    // 0047f0e4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f0e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f0e6  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 0047f0e8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f0e9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f0eb  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047f0ee  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f0f0  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0f1  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0047f0f6  0f85a7000000           -jne 0x47f1a3
    if (!cpu.flags.zf)
    {
        goto L_0x0047f1a3;
    }
L_0x0047f0fc:
    // 0047f0fc  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f0ff  7c3f                   -jl 0x47f140
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f140;
    }
    // 0047f101  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f104  743b                   -je 0x47f141
    if (cpu.flags.zf)
    {
        goto L_0x0047f141;
    }
    // 0047f106  38fb                   +cmp bl, bh
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
    // 0047f108  7537                   -jne 0x47f141
    if (!cpu.flags.zf)
    {
        goto L_0x0047f141;
    }
    // 0047f10a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f10b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f10c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 0047f10f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f112  7813                   -js 0x47f127
    if (cpu.flags.sf)
    {
        goto L_0x0047f127;
    }
L_0x0047f114:
    // 0047f114  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0047f116  dd5008                 -fst qword ptr [eax + 8]
    *app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 0047f119  dd5010                 -fst qword ptr [eax + 0x10]
    *app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 0047f11c  dd5018                 -fst qword ptr [eax + 0x18]
    *app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 0047f11f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047f122  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f125  79ed                   -jns 0x47f114
    if (!cpu.flags.sf)
    {
        goto L_0x0047f114;
    }
L_0x0047f127:
    // 0047f127  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f12a  780a                   -js 0x47f136
    if (cpu.flags.sf)
    {
        goto L_0x0047f136;
    }
L_0x0047f12c:
    // 0047f12c  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0047f12e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047f131  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f134  79f6                   -jns 0x47f12c
    if (!cpu.flags.sf)
    {
        goto L_0x0047f12c;
    }
L_0x0047f136:
    // 0047f136  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047f138  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047f13b  83c208                 +add edx, 8
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
    // 0047f13e  753d                   -jne 0x47f17d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f17d;
    }
L_0x0047f140:
    // 0047f140  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f141:
    // 0047f141  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f144  781f                   -js 0x47f165
    if (cpu.flags.sf)
    {
        goto L_0x0047f165;
    }
L_0x0047f146:
    // 0047f146  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f148  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047f14b  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047f14e  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047f151  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047f154  895814                 -mov dword ptr [eax + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047f157  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0047f15a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047f15d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047f160  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f163  79e1                   -jns 0x47f146
    if (!cpu.flags.sf)
    {
        goto L_0x0047f146;
    }
L_0x0047f165:
    // 0047f165  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f168  780d                   -js 0x47f177
    if (cpu.flags.sf)
    {
        goto L_0x0047f177;
    }
L_0x0047f16a:
    // 0047f16a  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f16c  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047f16f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047f172  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f175  79f3                   -jns 0x47f16a
    if (!cpu.flags.sf)
    {
        goto L_0x0047f16a;
    }
L_0x0047f177:
    // 0047f177  83c208                 +add edx, 8
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
    // 0047f17a  7501                   -jne 0x47f17d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f17d;
    }
    // 0047f17c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f17d:
    // 0047f17d  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 0047f183  7405                   -je 0x47f18a
    if (cpu.flags.zf)
    {
        goto L_0x0047f18a;
    }
    // 0047f185  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f187  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0047f18a:
    // 0047f18a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0047f190  7406                   -je 0x47f198
    if (cpu.flags.zf)
    {
        goto L_0x0047f198;
    }
    // 0047f192  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0047f195  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x0047f198:
    // 0047f198  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 0047f19e  7402                   -je 0x47f1a2
    if (cpu.flags.zf)
    {
        goto L_0x0047f1a2;
    }
    // 0047f1a0  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x0047f1a2:
    // 0047f1a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f1a3:
    // 0047f1a3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0047f1a8  740d                   -je 0x47f1b7
    if (cpu.flags.zf)
    {
        goto L_0x0047f1b7;
    }
    // 0047f1aa  83fa01                 +cmp edx, 1
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
    // 0047f1ad  7c08                   -jl 0x47f1b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1b7;
    }
    // 0047f1af  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0047f1b1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047f1b4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0047f1b7:
    // 0047f1b7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0047f1bc  740e                   -je 0x47f1cc
    if (cpu.flags.zf)
    {
        goto L_0x0047f1cc;
    }
    // 0047f1be  83fa02                 +cmp edx, 2
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
    // 0047f1c1  7c09                   -jl 0x47f1cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1cc;
    }
    // 0047f1c3  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0047f1c6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047f1c9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0047f1cc:
    // 0047f1cc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0047f1d1  740d                   -je 0x47f1e0
    if (cpu.flags.zf)
    {
        goto L_0x0047f1e0;
    }
    // 0047f1d3  83fa04                 +cmp edx, 4
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
    // 0047f1d6  7c08                   -jl 0x47f1e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1e0;
    }
    // 0047f1d8  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f1da  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047f1dd  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0047f1e0:
    // 0047f1e0  e917ffffff             -jmp 0x47f0fc
    goto L_0x0047f0fc;
}

/* align: skip  */
void Application::sub_47f0f1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047f0f1;
    // 0047f0e6  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 0047f0e8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f0e9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f0eb  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047f0ee  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f0f0  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x0047f0f1:
    // 0047f0f1  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0047f0f6  0f85a7000000           -jne 0x47f1a3
    if (!cpu.flags.zf)
    {
        goto L_0x0047f1a3;
    }
L_0x0047f0fc:
    // 0047f0fc  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f0ff  7c3f                   -jl 0x47f140
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f140;
    }
    // 0047f101  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f104  743b                   -je 0x47f141
    if (cpu.flags.zf)
    {
        goto L_0x0047f141;
    }
    // 0047f106  38fb                   +cmp bl, bh
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
    // 0047f108  7537                   -jne 0x47f141
    if (!cpu.flags.zf)
    {
        goto L_0x0047f141;
    }
    // 0047f10a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f10b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f10c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 0047f10f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f112  7813                   -js 0x47f127
    if (cpu.flags.sf)
    {
        goto L_0x0047f127;
    }
L_0x0047f114:
    // 0047f114  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0047f116  dd5008                 -fst qword ptr [eax + 8]
    *app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 0047f119  dd5010                 -fst qword ptr [eax + 0x10]
    *app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 0047f11c  dd5018                 -fst qword ptr [eax + 0x18]
    *app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 0047f11f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047f122  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f125  79ed                   -jns 0x47f114
    if (!cpu.flags.sf)
    {
        goto L_0x0047f114;
    }
L_0x0047f127:
    // 0047f127  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f12a  780a                   -js 0x47f136
    if (cpu.flags.sf)
    {
        goto L_0x0047f136;
    }
L_0x0047f12c:
    // 0047f12c  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0047f12e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047f131  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f134  79f6                   -jns 0x47f12c
    if (!cpu.flags.sf)
    {
        goto L_0x0047f12c;
    }
L_0x0047f136:
    // 0047f136  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047f138  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047f13b  83c208                 +add edx, 8
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
    // 0047f13e  753d                   -jne 0x47f17d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f17d;
    }
L_0x0047f140:
    // 0047f140  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f141:
    // 0047f141  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f144  781f                   -js 0x47f165
    if (cpu.flags.sf)
    {
        goto L_0x0047f165;
    }
L_0x0047f146:
    // 0047f146  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f148  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047f14b  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047f14e  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047f151  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047f154  895814                 -mov dword ptr [eax + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047f157  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0047f15a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047f15d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047f160  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f163  79e1                   -jns 0x47f146
    if (!cpu.flags.sf)
    {
        goto L_0x0047f146;
    }
L_0x0047f165:
    // 0047f165  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f168  780d                   -js 0x47f177
    if (cpu.flags.sf)
    {
        goto L_0x0047f177;
    }
L_0x0047f16a:
    // 0047f16a  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f16c  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047f16f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047f172  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f175  79f3                   -jns 0x47f16a
    if (!cpu.flags.sf)
    {
        goto L_0x0047f16a;
    }
L_0x0047f177:
    // 0047f177  83c208                 +add edx, 8
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
    // 0047f17a  7501                   -jne 0x47f17d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f17d;
    }
    // 0047f17c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f17d:
    // 0047f17d  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 0047f183  7405                   -je 0x47f18a
    if (cpu.flags.zf)
    {
        goto L_0x0047f18a;
    }
    // 0047f185  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f187  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0047f18a:
    // 0047f18a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0047f190  7406                   -je 0x47f198
    if (cpu.flags.zf)
    {
        goto L_0x0047f198;
    }
    // 0047f192  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0047f195  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x0047f198:
    // 0047f198  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 0047f19e  7402                   -je 0x47f1a2
    if (cpu.flags.zf)
    {
        goto L_0x0047f1a2;
    }
    // 0047f1a0  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x0047f1a2:
    // 0047f1a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f1a3:
    // 0047f1a3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0047f1a8  740d                   -je 0x47f1b7
    if (cpu.flags.zf)
    {
        goto L_0x0047f1b7;
    }
    // 0047f1aa  83fa01                 +cmp edx, 1
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
    // 0047f1ad  7c08                   -jl 0x47f1b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1b7;
    }
    // 0047f1af  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0047f1b1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047f1b4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0047f1b7:
    // 0047f1b7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0047f1bc  740e                   -je 0x47f1cc
    if (cpu.flags.zf)
    {
        goto L_0x0047f1cc;
    }
    // 0047f1be  83fa02                 +cmp edx, 2
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
    // 0047f1c1  7c09                   -jl 0x47f1cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1cc;
    }
    // 0047f1c3  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0047f1c6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047f1c9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0047f1cc:
    // 0047f1cc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0047f1d1  740d                   -je 0x47f1e0
    if (cpu.flags.zf)
    {
        goto L_0x0047f1e0;
    }
    // 0047f1d3  83fa04                 +cmp edx, 4
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
    // 0047f1d6  7c08                   -jl 0x47f1e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1e0;
    }
    // 0047f1d8  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f1da  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047f1dd  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0047f1e0:
    // 0047f1e0  e917ffffff             -jmp 0x47f0fc
    goto L_0x0047f0fc;
}

/* align: skip  */
void Application::sub_47f0e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047f0e8;
    // 0047f0e6  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
L_entry_0x0047f0e8:
    // 0047f0e8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f0e9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f0eb  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047f0ee  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f0f0  58                     -pop eax
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f0f1  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 0047f0f6  0f85a7000000           -jne 0x47f1a3
    if (!cpu.flags.zf)
    {
        goto L_0x0047f1a3;
    }
L_0x0047f0fc:
    // 0047f0fc  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f0ff  7c3f                   -jl 0x47f140
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f140;
    }
    // 0047f101  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f104  743b                   -je 0x47f141
    if (cpu.flags.zf)
    {
        goto L_0x0047f141;
    }
    // 0047f106  38fb                   +cmp bl, bh
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
    // 0047f108  7537                   -jne 0x47f141
    if (!cpu.flags.zf)
    {
        goto L_0x0047f141;
    }
    // 0047f10a  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f10b  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f10c  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(*app->getMemory<double>(cpu.esp)));
    // 0047f10f  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f112  7813                   -js 0x47f127
    if (cpu.flags.sf)
    {
        goto L_0x0047f127;
    }
L_0x0047f114:
    // 0047f114  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0047f116  dd5008                 -fst qword ptr [eax + 8]
    *app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 0047f119  dd5010                 -fst qword ptr [eax + 0x10]
    *app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 0047f11c  dd5018                 -fst qword ptr [eax + 0x18]
    *app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 0047f11f  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047f122  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f125  79ed                   -jns 0x47f114
    if (!cpu.flags.sf)
    {
        goto L_0x0047f114;
    }
L_0x0047f127:
    // 0047f127  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f12a  780a                   -js 0x47f136
    if (cpu.flags.sf)
    {
        goto L_0x0047f136;
    }
L_0x0047f12c:
    // 0047f12c  dd10                   -fst qword ptr [eax]
    *app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 0047f12e  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047f131  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f134  79f6                   -jns 0x47f12c
    if (!cpu.flags.sf)
    {
        goto L_0x0047f12c;
    }
L_0x0047f136:
    // 0047f136  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0047f138  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047f13b  83c208                 +add edx, 8
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
    // 0047f13e  753d                   -jne 0x47f17d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f17d;
    }
L_0x0047f140:
    // 0047f140  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f141:
    // 0047f141  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f144  781f                   -js 0x47f165
    if (cpu.flags.sf)
    {
        goto L_0x0047f165;
    }
L_0x0047f146:
    // 0047f146  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f148  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047f14b  895808                 -mov dword ptr [eax + 8], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0047f14e  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047f151  895810                 -mov dword ptr [eax + 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0047f154  895814                 -mov dword ptr [eax + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047f157  895818                 -mov dword ptr [eax + 0x18], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0047f15a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047f15d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047f160  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f163  79e1                   -jns 0x47f146
    if (!cpu.flags.sf)
    {
        goto L_0x0047f146;
    }
L_0x0047f165:
    // 0047f165  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f168  780d                   -js 0x47f177
    if (cpu.flags.sf)
    {
        goto L_0x0047f177;
    }
L_0x0047f16a:
    // 0047f16a  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f16c  895804                 -mov dword ptr [eax + 4], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047f16f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047f172  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f175  79f3                   -jns 0x47f16a
    if (!cpu.flags.sf)
    {
        goto L_0x0047f16a;
    }
L_0x0047f177:
    // 0047f177  83c208                 +add edx, 8
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
    // 0047f17a  7501                   -jne 0x47f17d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f17d;
    }
    // 0047f17c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f17d:
    // 0047f17d  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 0047f183  7405                   -je 0x47f18a
    if (cpu.flags.zf)
    {
        goto L_0x0047f18a;
    }
    // 0047f185  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f187  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x0047f18a:
    // 0047f18a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 0047f190  7406                   -je 0x47f198
    if (cpu.flags.zf)
    {
        goto L_0x0047f198;
    }
    // 0047f192  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0047f195  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x0047f198:
    // 0047f198  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 0047f19e  7402                   -je 0x47f1a2
    if (cpu.flags.zf)
    {
        goto L_0x0047f1a2;
    }
    // 0047f1a0  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x0047f1a2:
    // 0047f1a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f1a3:
    // 0047f1a3  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 0047f1a8  740d                   -je 0x47f1b7
    if (cpu.flags.zf)
    {
        goto L_0x0047f1b7;
    }
    // 0047f1aa  83fa01                 +cmp edx, 1
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
    // 0047f1ad  7c08                   -jl 0x47f1b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1b7;
    }
    // 0047f1af  8818                   -mov byte ptr [eax], bl
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 0047f1b1  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047f1b4  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0047f1b7:
    // 0047f1b7  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 0047f1bc  740e                   -je 0x47f1cc
    if (cpu.flags.zf)
    {
        goto L_0x0047f1cc;
    }
    // 0047f1be  83fa02                 +cmp edx, 2
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
    // 0047f1c1  7c09                   -jl 0x47f1cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1cc;
    }
    // 0047f1c3  668918                 -mov word ptr [eax], bx
    *app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 0047f1c6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047f1c9  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x0047f1cc:
    // 0047f1cc  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 0047f1d1  740d                   -je 0x47f1e0
    if (cpu.flags.zf)
    {
        goto L_0x0047f1e0;
    }
    // 0047f1d3  83fa04                 +cmp edx, 4
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
    // 0047f1d6  7c08                   -jl 0x47f1e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1e0;
    }
    // 0047f1d8  8918                   -mov dword ptr [eax], ebx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0047f1da  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047f1dd  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0047f1e0:
    // 0047f1e0  e917ffffff             -jmp 0x47f0fc
    goto L_0x0047f0fc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47f1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f1f0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f1f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f1f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f1f4  833d688d4c0000         +cmp dword ptr [0x4c8d68], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5016936) /* 0x4c8d68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f1fb  7501                   -jne 0x47f1fe
    if (!cpu.flags.zf)
    {
        goto L_0x0047f1fe;
    }
    // 0047f1fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f1fe:
    // 0047f1fe  e871010000             -call 0x47f374
    cpu.esp -= 4;
    sub_47f374(app, cpu);
    if (cpu.terminate) return;
    // 0047f203  b8bcba5100             -mov eax, 0x51babc
    cpu.eax = 5356220 /*0x51babc*/;
    // 0047f208  e86f090000             -call 0x47fb7c
    cpu.esp -= 4;
    sub_47fb7c(app, cpu);
    if (cpu.terminate) return;
    // 0047f20d  b8a0ba5100             -mov eax, 0x51baa0
    cpu.eax = 5356192 /*0x51baa0*/;
    // 0047f212  e965090000             -jmp 0x47fb7c
    return sub_47fb7c(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_47f218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f218  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047f21b  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 0047f21f  7506                   -jne 0x47f227
    if (!cpu.flags.zf)
    {
        goto L_0x0047f227;
    }
    // 0047f221  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047f226  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f227:
    // 0047f227  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f22a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047f22f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f230  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f231  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f232  ba18f24700             -mov edx, 0x47f218
    cpu.edx = 4715032 /*0x47f218*/;
    // 0047f237  b8bcba5100             -mov eax, 0x51babc
    cpu.eax = 5356220 /*0x51babc*/;
    // 0047f23c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f23e  e8410e0000             -call 0x480084
    cpu.esp -= 4;
    sub_480084(app, cpu);
    if (cpu.terminate) return;
    // 0047f243  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f244  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f248  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f249  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f24a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f24c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047f24e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047f250  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047f252  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047f256  833d688d4c0000         +cmp dword ptr [0x4c8d68], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5016936) /* 0x4c8d68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f25d  0f84b0000000           -je 0x47f313
    if (cpu.flags.zf)
    {
        goto L_0x0047f313;
    }
L_0x0047f263:
    // 0047f263  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f265  745e                   -je 0x47f2c5
    if (cpu.flags.zf)
    {
        goto L_0x0047f2c5;
    }
    // 0047f267  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f26b  7507                   -jne 0x47f274
    if (!cpu.flags.zf)
    {
        goto L_0x0047f274;
    }
    // 0047f26d  c7462402000000         -mov dword ptr [esi + 0x24], 2
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 2 /*0x2*/;
L_0x0047f274:
    // 0047f274  837e2800               +cmp dword ptr [esi + 0x28], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f278  7507                   -jne 0x47f281
    if (!cpu.flags.zf)
    {
        goto L_0x0047f281;
    }
    // 0047f27a  c7462804000000         -mov dword ptr [esi + 0x28], 4
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 4 /*0x4*/;
L_0x0047f281:
    // 0047f281  837e2c00               +cmp dword ptr [esi + 0x2c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f285  7507                   -jne 0x47f28e
    if (!cpu.flags.zf)
    {
        goto L_0x0047f28e;
    }
    // 0047f287  c7462c06000000         -mov dword ptr [esi + 0x2c], 6
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 6 /*0x6*/;
L_0x0047f28e:
    // 0047f28e  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f292  7507                   -jne 0x47f29b
    if (!cpu.flags.zf)
    {
        goto L_0x0047f29b;
    }
    // 0047f294  c74614f0f14700         -mov dword ptr [esi + 0x14], 0x47f1f0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 4714992 /*0x47f1f0*/;
L_0x0047f29b:
    // 0047f29b  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f29f  7507                   -jne 0x47f2a8
    if (!cpu.flags.zf)
    {
        goto L_0x0047f2a8;
    }
    // 0047f2a1  c7461cf0f14700         -mov dword ptr [esi + 0x1c], 0x47f1f0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 4714992 /*0x47f1f0*/;
L_0x0047f2a8:
    // 0047f2a8  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f2ac  7507                   -jne 0x47f2b5
    if (!cpu.flags.zf)
    {
        goto L_0x0047f2b5;
    }
    // 0047f2ae  c74618f0f14700         -mov dword ptr [esi + 0x18], 0x47f1f0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4714992 /*0x47f1f0*/;
L_0x0047f2b5:
    // 0047f2b5  837e2000               +cmp dword ptr [esi + 0x20], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f2b9  7507                   -jne 0x47f2c2
    if (!cpu.flags.zf)
    {
        goto L_0x0047f2c2;
    }
    // 0047f2bb  c74620f0f14700         -mov dword ptr [esi + 0x20], 0x47f1f0
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 4714992 /*0x47f1f0*/;
L_0x0047f2c2:
    // 0047f2c2  897e0c                 -mov dword ptr [esi + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x0047f2c5:
    // 0047f2c5  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f2c7  741f                   -je 0x47f2e8
    if (cpu.flags.zf)
    {
        goto L_0x0047f2e8;
    }
    // 0047f2c9  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f2cd  7419                   -je 0x47f2e8
    if (cpu.flags.zf)
    {
        goto L_0x0047f2e8;
    }
    // 0047f2cf  833d6c8d4c0000         +cmp dword ptr [0x4c8d6c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5016940) /* 0x4c8d6c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f2d6  750a                   -jne 0x47f2e2
    if (!cpu.flags.zf)
    {
        goto L_0x0047f2e2;
    }
    // 0047f2d8  b830f24700             -mov eax, 0x47f230
    cpu.eax = 4715056 /*0x47f230*/;
    // 0047f2dd  e892410100             -call 0x493474
    cpu.esp -= 4;
    sub_493474(app, cpu);
    if (cpu.terminate) return;
L_0x0047f2e2:
    // 0047f2e2  ff056c8d4c00           -inc dword ptr [0x4c8d6c]
    (*app->getMemory<x86::reg32>(x86::reg32(5016940) /* 0x4c8d6c */))++;
L_0x0047f2e8:
    // 0047f2e8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f2ea  ff5704                 -call dword ptr [edi + 4]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f2ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f2ef  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f2f1  7419                   -je 0x47f30c
    if (cpu.flags.zf)
    {
        goto L_0x0047f30c;
    }
    // 0047f2f3  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f2f7  7413                   -je 0x47f30c
    if (cpu.flags.zf)
    {
        goto L_0x0047f30c;
    }
    // 0047f2f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f2fb  750f                   -jne 0x47f30c
    if (!cpu.flags.zf)
    {
        goto L_0x0047f30c;
    }
    // 0047f2fd  8b1d6c8d4c00           -mov ebx, dword ptr [0x4c8d6c]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5016940) /* 0x4c8d6c */);
    // 0047f303  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047f304  891d6c8d4c00           -mov dword ptr [0x4c8d6c], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5016940) /* 0x4c8d6c */) = cpu.ebx;
    // 0047f30a  7411                   -je 0x47f31d
    if (cpu.flags.zf)
    {
        goto L_0x0047f31d;
    }
L_0x0047f30c:
    // 0047f30c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f30e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f30f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f310  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047f313:
    // 0047f313  e818000000             -call 0x47f330
    cpu.esp -= 4;
    sub_47f330(app, cpu);
    if (cpu.terminate) return;
    // 0047f318  e946ffffff             -jmp 0x47f263
    goto L_0x0047f263;
L_0x0047f31d:
    // 0047f31d  b830f24700             -mov eax, 0x47f230
    cpu.eax = 4715056 /*0x47f230*/;
    // 0047f322  e8b5410100             -call 0x4934dc
    cpu.esp -= 4;
    sub_4934dc(app, cpu);
    if (cpu.terminate) return;
    // 0047f327  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f329  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f32a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f32b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f330  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f331  8b15688d4c00           -mov edx, dword ptr [0x4c8d68]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5016936) /* 0x4c8d68 */);
    // 0047f337  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047f339  7402                   -je 0x47f33d
    if (cpu.flags.zf)
    {
        goto L_0x0047f33d;
    }
    // 0047f33b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f33c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f33d:
    // 0047f33d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f33e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f33f  b8bcba5100             -mov eax, 0x51babc
    cpu.eax = 5356220 /*0x51babc*/;
    // 0047f344  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f346  e8f1070000             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 0047f34b  b8a0ba5100             -mov eax, 0x51baa0
    cpu.eax = 5356192 /*0x51baa0*/;
    // 0047f350  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f352  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f354  e8e3070000             -call 0x47fb3c
    cpu.esp -= 4;
    sub_47fb3c(app, cpu);
    if (cpu.terminate) return;
    // 0047f359  b8f4f14700             -mov eax, 0x47f1f4
    cpu.eax = 4714996 /*0x47f1f4*/;
    // 0047f35e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047f363  e8b4c20000             -call 0x48b61c
    cpu.esp -= 4;
    sub_48b61c(app, cpu);
    if (cpu.terminate) return;
    // 0047f368  890d688d4c00           -mov dword ptr [0x4c8d68], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5016936) /* 0x4c8d68 */) = cpu.ecx;
    // 0047f36e  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f36f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f370  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f371  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f374(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f374  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f375  833d688d4c0000         +cmp dword ptr [0x4c8d68], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5016936) /* 0x4c8d68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f37c  7420                   -je 0x47f39e
    if (cpu.flags.zf)
    {
        goto L_0x0047f39e;
    }
L_0x0047f37e:
    // 0047f37e  b8bcba5100             -mov eax, 0x51babc
    cpu.eax = 5356220 /*0x51babc*/;
    // 0047f383  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f385  e8fa0a0000             -call 0x47fe84
    cpu.esp -= 4;
    sub_47fe84(app, cpu);
    if (cpu.terminate) return;
    // 0047f38a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f38c  7512                   -jne 0x47f3a0
    if (!cpu.flags.zf)
    {
        goto L_0x0047f3a0;
    }
L_0x0047f38e:
    // 0047f38e  b8a0ba5100             -mov eax, 0x51baa0
    cpu.eax = 5356192 /*0x51baa0*/;
    // 0047f393  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f395  e8ea0a0000             -call 0x47fe84
    cpu.esp -= 4;
    sub_47fe84(app, cpu);
    if (cpu.terminate) return;
    // 0047f39a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f39c  7509                   -jne 0x47f3a7
    if (!cpu.flags.zf)
    {
        goto L_0x0047f3a7;
    }
L_0x0047f39e:
    // 0047f39e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f39f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f3a0:
    // 0047f3a0  e823000000             -call 0x47f3c8
    cpu.esp -= 4;
    sub_47f3c8(app, cpu);
    if (cpu.terminate) return;
    // 0047f3a5  ebd7                   -jmp 0x47f37e
    goto L_0x0047f37e;
L_0x0047f3a7:
    // 0047f3a7  e81c000000             -call 0x47f3c8
    cpu.esp -= 4;
    sub_47f3c8(app, cpu);
    if (cpu.terminate) return;
    // 0047f3ac  ebe0                   -jmp 0x47f38e
    goto L_0x0047f38e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f3b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f3b2  7406                   -je 0x47f3ba
    if (cpu.flags.zf)
    {
        goto L_0x0047f3ba;
    }
    // 0047f3b4  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0047f3b8  7503                   -jne 0x47f3bd
    if (!cpu.flags.zf)
    {
        goto L_0x0047f3bd;
    }
L_0x0047f3ba:
    // 0047f3ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f3bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f3bd:
    // 0047f3bd  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f3be  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047f3c1  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f3c4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f3c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f3c8  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f3c9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f3cb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f3cd  7406                   -je 0x47f3d5
    if (cpu.flags.zf)
    {
        goto L_0x0047f3d5;
    }
    // 0047f3cf  83781000               +cmp dword ptr [eax + 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f3d3  7504                   -jne 0x47f3d9
    if (!cpu.flags.zf)
    {
        goto L_0x0047f3d9;
    }
L_0x0047f3d5:
    // 0047f3d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f3d7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f3d9:
    // 0047f3d9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f3da  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f3db  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f3dc  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047f3df  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f3e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f3e4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f3e6  742a                   -je 0x47f412
    if (cpu.flags.zf)
    {
        goto L_0x0047f412;
    }
    // 0047f3e8  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047f3eb  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 0047f3ef  7421                   -je 0x47f412
    if (cpu.flags.zf)
    {
        goto L_0x0047f412;
    }
    // 0047f3f1  8b356c8d4c00           -mov esi, dword ptr [0x4c8d6c]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5016940) /* 0x4c8d6c */);
    // 0047f3f7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f3f9  7417                   -je 0x47f412
    if (cpu.flags.zf)
    {
        goto L_0x0047f412;
    }
    // 0047f3fb  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 0047f3fe  893d6c8d4c00           -mov dword ptr [0x4c8d6c], edi
    *app->getMemory<x86::reg32>(x86::reg32(5016940) /* 0x4c8d6c */) = cpu.edi;
    // 0047f404  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f406  750a                   -jne 0x47f412
    if (!cpu.flags.zf)
    {
        goto L_0x0047f412;
    }
    // 0047f408  b830f24700             -mov eax, 0x47f230
    cpu.eax = 4715056 /*0x47f230*/;
    // 0047f40d  e8ca400100             -call 0x4934dc
    cpu.esp -= 4;
    sub_4934dc(app, cpu);
    if (cpu.terminate) return;
L_0x0047f412:
    // 0047f412  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f414  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f415  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f416  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f417  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f418  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f419(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f419  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f41a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f41b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f41c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f41d  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f41e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f421  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f423  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047f428  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f42a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047f42c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047f42e  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0047f431  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047f433  740e                   -je 0x47f443
    if (cpu.flags.zf)
    {
        goto L_0x0047f443;
    }
    // 0047f435  3b0d2cbf4c00           +cmp ecx, dword ptr [0x4cbf2c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(x86::reg32(5029676) /* 0x4cbf2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f43b  7504                   -jne 0x47f441
    if (!cpu.flags.zf)
    {
        goto L_0x0047f441;
    }
    // 0047f43d  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0047f43f  eb02                   -jmp 0x47f443
    goto L_0x0047f443;
L_0x0047f441:
    // 0047f441  892a                   -mov dword ptr [edx], ebp
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
L_0x0047f443:
    // 0047f443  8a03                   -mov al, byte ptr [ebx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx);
    // 0047f445  3c72                   +cmp al, 0x72
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
    // 0047f447  7208                   -jb 0x47f451
    if (cpu.flags.cf)
    {
        goto L_0x0047f451;
    }
    // 0047f449  760c                   -jbe 0x47f457
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f457;
    }
    // 0047f44b  3c77                   +cmp al, 0x77
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
    // 0047f44d  740e                   -je 0x47f45d
    if (cpu.flags.zf)
    {
        goto L_0x0047f45d;
    }
    // 0047f44f  eb18                   -jmp 0x47f469
    goto L_0x0047f469;
L_0x0047f451:
    // 0047f451  3c61                   +cmp al, 0x61
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
    // 0047f453  740e                   -je 0x47f463
    if (cpu.flags.zf)
    {
        goto L_0x0047f463;
    }
    // 0047f455  eb12                   -jmp 0x47f469
    goto L_0x0047f469;
L_0x0047f457:
    // 0047f457  800c2401               +or byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047f45b  eb1d                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f45d:
    // 0047f45d  800c2402               +or byte ptr [esp], 2
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0047f461  eb17                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f463:
    // 0047f463  800c2482               +or byte ptr [esp], 0x82
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(130 /*0x82*/))));
    // 0047f467  eb11                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f469:
    // 0047f469  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0047f46e  e8cd670100             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0047f473  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047f475  e9af000000             -jmp 0x47f529
    goto L_0x0047f529;
L_0x0047f47a:
    // 0047f47a  43                     -inc ebx
    (cpu.ebx)++;
    // 0047f47b  8a03                   -mov al, byte ptr [ebx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebx);
    // 0047f47d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0047f47f  0f848d000000           -je 0x47f512
    if (cpu.flags.zf)
    {
        goto L_0x0047f512;
    }
    // 0047f485  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047f487  0f8485000000           -je 0x47f512
    if (cpu.flags.zf)
    {
        goto L_0x0047f512;
    }
    // 0047f48d  3c63                   +cmp al, 0x63
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
    // 0047f48f  7216                   -jb 0x47f4a7
    if (cpu.flags.cf)
    {
        goto L_0x0047f4a7;
    }
    // 0047f491  0f8652000000           -jbe 0x47f4e9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f4e9;
    }
    // 0047f497  3c6e                   +cmp al, 0x6e
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
    // 0047f499  72df                   -jb 0x47f47a
    if (cpu.flags.cf)
    {
        goto L_0x0047f47a;
    }
    // 0047f49b  0f865d000000           -jbe 0x47f4fe
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f4fe;
    }
    // 0047f4a1  3c74                   +cmp al, 0x74
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
    // 0047f4a3  7426                   -je 0x47f4cb
    if (cpu.flags.zf)
    {
        goto L_0x0047f4cb;
    }
    // 0047f4a5  ebd3                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f4a7:
    // 0047f4a7  3c2b                   +cmp al, 0x2b
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
    // 0047f4a9  72cf                   -jb 0x47f47a
    if (cpu.flags.cf)
    {
        goto L_0x0047f47a;
    }
    // 0047f4ab  7606                   -jbe 0x47f4b3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f4b3;
    }
    // 0047f4ad  3c62                   +cmp al, 0x62
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
    // 0047f4af  7425                   -je 0x47f4d6
    if (cpu.flags.zf)
    {
        goto L_0x0047f4d6;
    }
    // 0047f4b1  ebc7                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f4b3:
    // 0047f4b3  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047f4b5  7404                   -je 0x47f4bb
    if (cpu.flags.zf)
    {
        goto L_0x0047f4bb;
    }
L_0x0047f4b7:
    // 0047f4b7  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047f4b9  ebbf                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f4bb:
    // 0047f4bb  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esp);
    // 0047f4be  80cc03                 +or ah, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047f4c1  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0047f4c6  882424                 -mov byte ptr [esp], ah
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0047f4c9  ebaf                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f4cb:
    // 0047f4cb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f4cd  75e8                   -jne 0x47f4b7
    if (!cpu.flags.zf)
    {
        goto L_0x0047f4b7;
    }
    // 0047f4cf  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0047f4d4  eba4                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f4d6:
    // 0047f4d6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f4d8  75dd                   -jne 0x47f4b7
    if (!cpu.flags.zf)
    {
        goto L_0x0047f4b7;
    }
    // 0047f4da  8a0424                 -mov al, byte ptr [esp]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp);
    // 0047f4dd  0c40                   +or al, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0047f4df  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0047f4e4  880424                 -mov byte ptr [esp], al
    *app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 0047f4e7  eb91                   -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f4e9:
    // 0047f4e9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f4eb  75ca                   -jne 0x47f4b7
    if (!cpu.flags.zf)
    {
        goto L_0x0047f4b7;
    }
    // 0047f4ed  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.edx);
    // 0047f4ef  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047f4f2  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0047f4f7  8822                   -mov byte ptr [edx], ah
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 0047f4f9  e97cffffff             -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f4fe:
    // 0047f4fe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f500  75b5                   -jne 0x47f4b7
    if (!cpu.flags.zf)
    {
        goto L_0x0047f4b7;
    }
    // 0047f502  8a02                   -mov al, byte ptr [edx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.edx);
    // 0047f504  24fe                   +and al, 0xfe
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 0047f506  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0047f50b  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047f50d  e968ffffff             -jmp 0x47f47a
    goto L_0x0047f47a;
L_0x0047f512:
    // 0047f512  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f514  7510                   -jne 0x47f526
    if (!cpu.flags.zf)
    {
        goto L_0x0047f526;
    }
    // 0047f516  813d39c14c0000020000   +cmp dword ptr [0x4cc139], 0x200
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5030201) /* 0x4cc139 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f520  7504                   -jne 0x47f526
    if (!cpu.flags.zf)
    {
        goto L_0x0047f526;
    }
    // 0047f522  800c2440               -or byte ptr [esp], 0x40
    *app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x0047f526:
    // 0047f526  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
L_0x0047f529:
    // 0047f529  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f52b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f52e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f52f  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f530  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f531  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f532  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f533  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f534(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f534  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f535  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f536  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f537  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f539  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0047f53b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047f53d  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047f541  80610cfc               -and byte ptr [ecx + 0xc], 0xfc
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 0047f545  09590c                 -or dword ptr [ecx + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f548  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047f54d  e8d9990100             -call 0x498f2b
    cpu.esp -= 4;
    sub_498f2b(app, cpu);
    if (cpu.terminate) return;
    // 0047f552  3c72                   +cmp al, 0x72
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
    // 0047f554  7522                   -jne 0x47f578
    if (!cpu.flags.zf)
    {
        goto L_0x0047f578;
    }
    // 0047f556  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f558  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0047f55b  7405                   -je 0x47f562
    if (cpu.flags.zf)
    {
        goto L_0x0047f562;
    }
    // 0047f55d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x0047f562:
    // 0047f562  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047f565  7405                   -je 0x47f56c
    if (cpu.flags.zf)
    {
        goto L_0x0047f56c;
    }
    // 0047f567  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0047f56a  eb03                   -jmp 0x47f56f
    goto L_0x0047f56f;
L_0x0047f56c:
    // 0047f56c  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x0047f56f:
    // 0047f56f  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f571  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047f575  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f576  eb30                   -jmp 0x47f5a8
    goto L_0x0047f5a8;
L_0x0047f578:
    // 0047f578  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0047f57b  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0047f57e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047f583  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
    // 0047f586  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 0047f589  7404                   -je 0x47f58f
    if (cpu.flags.zf)
    {
        goto L_0x0047f58f;
    }
    // 0047f58b  0c10                   +or al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0047f58d  eb02                   -jmp 0x47f591
    goto L_0x0047f591;
L_0x0047f58f:
    // 0047f58f  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x0047f591:
    // 0047f591  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047f594  7405                   -je 0x47f59b
    if (cpu.flags.zf)
    {
        goto L_0x0047f59b;
    }
    // 0047f596  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0047f599  eb03                   -jmp 0x47f59e
    goto L_0x0047f59e;
L_0x0047f59b:
    // 0047f59b  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0047f59e:
    // 0047f59e  6880010000             -push 0x180
    *app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 0047f5a3  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047f5a7  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x0047f5a8:
    // 0047f5a8  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f5a9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f5aa  e8ae990100             -call 0x498f5d
    cpu.esp -= 4;
    sub_498f5d(app, cpu);
    if (cpu.terminate) return;
    // 0047f5af  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f5b2  894110                 -mov dword ptr [ecx + 0x10], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047f5b5  837910ff               +cmp dword ptr [ecx + 0x10], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f5b9  750b                   -jne 0x47f5c6
    if (!cpu.flags.zf)
    {
        goto L_0x0047f5c6;
    }
    // 0047f5bb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f5bd  e8869c0100             -call 0x499248
    cpu.esp -= 4;
    sub_499248(app, cpu);
    if (cpu.terminate) return;
    // 0047f5c2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f5c4  eb4e                   -jmp 0x47f614
    goto L_0x0047f614;
L_0x0047f5c6:
    // 0047f5c6  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0047f5cd  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047f5d0  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0047f5d7  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047f5de  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047f5e1  895010                 -mov dword ptr [eax + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047f5e4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047f5e7  c7401500000000         -mov dword ptr [eax + 0x15], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 0047f5ee  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047f5f1  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047f5f8  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 0047f5fb  740e                   -je 0x47f60b
    if (cpu.flags.zf)
    {
        goto L_0x0047f60b;
    }
    // 0047f5fd  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047f602  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f604  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f606  e8e99c0100             -call 0x4992f4
    cpu.esp -= 4;
    sub_4992f4(app, cpu);
    if (cpu.terminate) return;
L_0x0047f60b:
    // 0047f60b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f60d  e8f29d0100             -call 0x499404
    cpu.esp -= 4;
    sub_499404(app, cpu);
    if (cpu.terminate) return;
    // 0047f612  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0047f614:
    // 0047f614  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f615  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f616  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f617  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_47f61a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f61a  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f61b  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f61c  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f61d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f620  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f622  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047f624  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047f626  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047f628  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f62a  e8eafdffff             -call 0x47f419
    cpu.esp -= 4;
    sub_47f419(app, cpu);
    if (cpu.terminate) return;
    // 0047f62f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f631  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f633  7422                   -je 0x47f657
    if (cpu.flags.zf)
    {
        goto L_0x0047f657;
    }
    // 0047f635  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f637  e8519b0100             -call 0x49918d
    cpu.esp -= 4;
    sub_49918d(app, cpu);
    if (cpu.terminate) return;
    // 0047f63c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f63e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f640  7413                   -je 0x47f655
    if (cpu.flags.zf)
    {
        goto L_0x0047f655;
    }
    // 0047f642  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f643  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f645  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f646  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f648  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0047f64a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f64e  e8e1feffff             -call 0x47f534
    cpu.esp -= 4;
    sub_47f534(app, cpu);
    if (cpu.terminate) return;
    // 0047f653  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0047f655:
    // 0047f655  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0047f657:
    // 0047f657  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f65a  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f65b  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f65c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f65d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f65e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f65e  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f65f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f661  e8b4ffffff             -call 0x47f61a
    cpu.esp -= 4;
    sub_47f61a(app, cpu);
    if (cpu.terminate) return;
    // 0047f666  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f667  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f668  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f669  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f66a  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f66b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f66d  ff1558c14c00           -call dword ptr [0x4cc158]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030232) /* 0x4cc158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f673  a1f42b5400             -mov eax, dword ptr [0x542bf4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
L_0x0047f678:
    // 0047f678  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f67a  7429                   -je 0x47f6a5
    if (cpu.flags.zf)
    {
        goto L_0x0047f6a5;
    }
    // 0047f67c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047f67f  39d3                   +cmp ebx, edx
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
    // 0047f681  751e                   -jne 0x47f6a1
    if (!cpu.flags.zf)
    {
        goto L_0x0047f6a1;
    }
    // 0047f683  f6420c03               +test byte ptr [edx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 0047f687  740c                   -je 0x47f695
    if (cpu.flags.zf)
    {
        goto L_0x0047f695;
    }
    // 0047f689  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047f68e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f690  e8ec020000             -call 0x47f981
    cpu.esp -= 4;
    sub_47f981(app, cpu);
    if (cpu.terminate) return;
L_0x0047f695:
    // 0047f695  ff155cc14c00           -call dword ptr [0x4cc15c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f69b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f69d  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f69e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f69f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f6a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f6a1:
    // 0047f6a1  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047f6a3  ebd3                   -jmp 0x47f678
    goto L_0x0047f678;
L_0x0047f6a5:
    // 0047f6a5  baf82b5400             -mov edx, 0x542bf8
    cpu.edx = 5516280 /*0x542bf8*/;
L_0x0047f6aa:
    // 0047f6aa  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx);
    // 0047f6ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f6ae  741c                   -je 0x47f6cc
    if (cpu.flags.zf)
    {
        goto L_0x0047f6cc;
    }
    // 0047f6b0  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 0047f6b3  7513                   -jne 0x47f6c8
    if (!cpu.flags.zf)
    {
        goto L_0x0047f6c8;
    }
    // 0047f6b5  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047f6b7  890a                   -mov dword ptr [edx], ecx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0047f6b9  8b15f42b5400           -mov edx, dword ptr [0x542bf4]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
    // 0047f6bf  a3f42b5400             -mov dword ptr [0x542bf4], eax
    *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */) = cpu.eax;
    // 0047f6c4  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0047f6c6  ebcd                   -jmp 0x47f695
    goto L_0x0047f695;
L_0x0047f6c8:
    // 0047f6c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f6ca  ebde                   -jmp 0x47f6aa
    goto L_0x0047f6aa;
L_0x0047f6cc:
    // 0047f6cc  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0047f6d1  e86a650100             -call 0x495c40
    cpu.esp -= 4;
    sub_495c40(app, cpu);
    if (cpu.terminate) return;
    // 0047f6d6  ff155cc14c00           -call dword ptr [0x4cc15c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f6dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f6de  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f6df  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f6e0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f6e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f6e2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f6e2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f6e3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f6e4  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f6e5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f6e6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f6e9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047f6eb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047f6ed  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047f6ef  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f6f1  e823fdffff             -call 0x47f419
    cpu.esp -= 4;
    sub_47f419(app, cpu);
    if (cpu.terminate) return;
    // 0047f6f6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047f6f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f6fa  7455                   -je 0x47f751
    if (cpu.flags.zf)
    {
        goto L_0x0047f751;
    }
    // 0047f6fc  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047f6ff  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f701  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f707  833d94c14c0000         +cmp dword ptr [0x4cc194], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5030292) /* 0x4cc194 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f70e  7408                   -je 0x47f718
    if (cpu.flags.zf)
    {
        goto L_0x0047f718;
    }
    // 0047f710  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f712  ff1594c14c00           -call dword ptr [0x4cc194]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030292) /* 0x4cc194 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f718:
    // 0047f718  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f71a  e849ffffff             -call 0x47f668
    cpu.esp -= 4;
    sub_47f668(app, cpu);
    if (cpu.terminate) return;
    // 0047f71f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f721  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f723  7422                   -je 0x47f747
    if (cpu.flags.zf)
    {
        goto L_0x0047f747;
    }
    // 0047f725  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f726  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047f729  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f72b  81e300400000           -and ebx, 0x4000
    cpu.ebx &= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 0047f731  6a00                   -push 0
    *app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f733  89580c                 -mov dword ptr [eax + 0xc], ebx
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0047f736  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0047f738  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047f73a  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ecx);
    // 0047f73c  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047f740  e8effdffff             -call 0x47f534
    cpu.esp -= 4;
    sub_47f534(app, cpu);
    if (cpu.terminate) return;
    // 0047f745  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0047f747:
    // 0047f747  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f749  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f74f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0047f751:
    // 0047f751  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f754  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f755  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f756  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f757  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f758  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f759(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f759  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f75a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f75b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f75c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f75d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f760  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f762  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047f764  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047f767  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047f769  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f76f  8a630c                 -mov ah, byte ptr [ebx + 0xc]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0047f772  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0047f775  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 0047f778  83e730                 -and edi, 0x30
    cpu.edi &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047f77b  88630c                 -mov byte ptr [ebx + 0xc], ah
    *app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x0047f77e:
    // 0047f77e  49                     -dec ecx
    (cpu.ecx)--;
    // 0047f77f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047f781  7e19                   -jle 0x47f79c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f79c;
    }
    // 0047f783  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f785  e8869f0100             -call 0x499710
    cpu.esp -= 4;
    sub_499710(app, cpu);
    if (cpu.terminate) return;
    // 0047f78a  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047f78d  83f8ff                 +cmp eax, -1
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
    // 0047f790  740a                   -je 0x47f79c
    if (cpu.flags.zf)
    {
        goto L_0x0047f79c;
    }
    // 0047f792  8a0424                 -mov al, byte ptr [esp]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esp);
    // 0047f795  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047f797  42                     -inc edx
    (cpu.edx)++;
    // 0047f798  3c0a                   +cmp al, 0xa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f79a  75e2                   -jne 0x47f77e
    if (!cpu.flags.zf)
    {
        goto L_0x0047f77e;
    }
L_0x0047f79c:
    // 0047f79c  833c24ff               +cmp dword ptr [esp], -1
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f7a0  750e                   -jne 0x47f7b0
    if (!cpu.flags.zf)
    {
        goto L_0x0047f7b0;
    }
    // 0047f7a2  39f2                   +cmp edx, esi
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
    // 0047f7a4  7406                   -je 0x47f7ac
    if (cpu.flags.zf)
    {
        goto L_0x0047f7ac;
    }
    // 0047f7a6  f6430c20               +test byte ptr [ebx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 0047f7aa  7404                   -je 0x47f7b0
    if (cpu.flags.zf)
    {
        goto L_0x0047f7b0;
    }
L_0x0047f7ac:
    // 0047f7ac  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0047f7ae  eb03                   -jmp 0x47f7b3
    goto L_0x0047f7b3;
L_0x0047f7b0:
    // 0047f7b0  c60200                 -mov byte ptr [edx], 0
    *app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x0047f7b3:
    // 0047f7b3  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0047f7b6  09fd                   -or ebp, edi
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edi));
    // 0047f7b8  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047f7bb  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0047f7be  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f7c4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f7c6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f7c9  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7ca  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7cb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7cc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f7ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f7ce  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f7cf  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f7d0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f7d2  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047f7d5  e8369f0100             -call 0x499710
    cpu.esp -= 4;
    sub_499710(app, cpu);
    if (cpu.terminate) return;
    // 0047f7da  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f7dc  83f8ff                 +cmp eax, -1
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
    // 0047f7df  7504                   -jne 0x47f7e5
    if (!cpu.flags.zf)
    {
        goto L_0x0047f7e5;
    }
    // 0047f7e1  804a1002               -or byte ptr [edx + 0x10], 2
    *app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0047f7e5:
    // 0047f7e5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f7e7  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7e8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f7ea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f7ea  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047f7ed  e9c6a00100             -jmp 0x4998b8
    return sub_4998b8(app, cpu);
}

/* align: skip  */
void Application::sub_47f7f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f7f2  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f7f3  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f7f4  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f7f5  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047f7f8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f7fa  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047f7fd  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f803  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047f806  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047f809  83fe01                 +cmp esi, 1
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
    // 0047f80c  7418                   -je 0x47f826
    if (cpu.flags.zf)
    {
        goto L_0x0047f826;
    }
    // 0047f80e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f810  740d                   -je 0x47f81f
    if (cpu.flags.zf)
    {
        goto L_0x0047f81f;
    }
    // 0047f812  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047f815  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f81b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f81d  eb30                   -jmp 0x47f84f
    goto L_0x0047f84f;
L_0x0047f81f:
    // 0047f81f  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x0047f826:
    // 0047f826  bdcef74700             -mov ebp, 0x47f7ce
    cpu.ebp = 4716494 /*0x47f7ce*/;
    // 0047f82b  b8eaf74700             -mov eax, 0x47f7ea
    cpu.eax = 4716522 /*0x47f7ea*/;
    // 0047f830  894c2408               -mov dword ptr [esp + 8], ecx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047f834  89442404               -mov dword ptr [esp + 4], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047f838  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047f83a  892c24                 -mov dword ptr [esp], ebp
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0047f83d  e83fa10100             -call 0x499981
    cpu.esp -= 4;
    sub_499981(app, cpu);
    if (cpu.terminate) return;
    // 0047f842  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f844  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047f847  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f84d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0047f84f:
    // 0047f84f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047f852  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f853  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f854  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f855  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f856(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f856  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f857  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f858  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f85b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047f85f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047f861  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047f865  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047f868  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047f86c  e881ffffff             -call 0x47f7f2
    cpu.esp -= 4;
    sub_47f7f2(app, cpu);
    if (cpu.terminate) return;
    // 0047f871  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f874  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f875  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f876  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f877(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f877  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f878  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f879  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f87b  ff1558c14c00           -call dword ptr [0x4cc158]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030232) /* 0x4cc158 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f881  a1f42b5400             -mov eax, dword ptr [0x542bf4]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5516276) /* 0x542bf4 */);
L_0x0047f886:
    // 0047f886  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f888  750e                   -jne 0x47f898
    if (!cpu.flags.zf)
    {
        goto L_0x0047f898;
    }
    // 0047f88a  ff155cc14c00           -call dword ptr [0x4cc15c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f890  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047f895  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f896  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f897  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f898:
    // 0047f898  3b5804                 +cmp ebx, dword ptr [eax + 4]
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
    // 0047f89b  7404                   -je 0x47f8a1
    if (cpu.flags.zf)
    {
        goto L_0x0047f8a1;
    }
    // 0047f89d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047f89f  ebe5                   -jmp 0x47f886
    goto L_0x0047f886;
L_0x0047f8a1:
    // 0047f8a1  ff155cc14c00           -call dword ptr [0x4cc15c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030236) /* 0x4cc15c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f8a7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047f8ac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f8ae  e803000000             -call 0x47f8b6
    cpu.esp -= 4;
    sub_47f8b6(app, cpu);
    if (cpu.terminate) return;
    // 0047f8b3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8b4  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f8b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f8b6  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f8b7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f8b9  e8c3000000             -call 0x47f981
    cpu.esp -= 4;
    sub_47f981(app, cpu);
    if (cpu.terminate) return;
    // 0047f8be  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f8c0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f8c2  e881990100             -call 0x499248
    cpu.esp -= 4;
    sub_499248(app, cpu);
    if (cpu.terminate) return;
    // 0047f8c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f8c9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f8cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f8cb  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047f8ce  83f839                 +cmp eax, 0x39
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
    // 0047f8d1  7e03                   -jle 0x47f8d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f8d6;
    }
    // 0047f8d3  83c027                 -add eax, 0x27
    (cpu.eax) += x86::reg32(x86::sreg32(39 /*0x27*/));
L_0x0047f8d6:
    // 0047f8d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f8d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f8d7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f8d8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f8d9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f8da  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f8db  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f8dc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f8df  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047f8e1  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047f8e4  e82eaf0100             -call 0x49a817
    cpu.esp -= 4;
    sub_49a817(app, cpu);
    if (cpu.terminate) return;
    // 0047f8e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f8eb  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0047f8ee  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047f8f0  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f8f2  e821b00100             -call 0x49a918
    cpu.esp -= 4;
    sub_49a918(app, cpu);
    if (cpu.terminate) return;
    // 0047f8f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f8f9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047f8fa:
    // 0047f8fa  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0047f8fc  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047f8fe  3c00                   +cmp al, 0
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
    // 0047f900  7410                   -je 0x47f912
    if (cpu.flags.zf)
    {
        goto L_0x0047f912;
    }
    // 0047f902  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047f905  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047f908  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047f90b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047f90e  3c00                   +cmp al, 0
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
    // 0047f910  75e8                   -jne 0x47f8fa
    if (!cpu.flags.zf)
    {
        goto L_0x0047f8fa;
    }
L_0x0047f912:
    // 0047f912  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f913  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0047f914  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0047f916  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0047f918  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f91a  49                     -dec ecx
    (cpu.ecx)--;
    // 0047f91b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f91d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047f91f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047f921  49                     -dec ecx
    (cpu.ecx)--;
    // 0047f922  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0047f923  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f925  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047f928  c60174                 -mov byte ptr [ecx], 0x74
    *app->getMemory<x86::reg8>(cpu.ecx) = 116 /*0x74*/;
    // 0047f92b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0047f92d:
    // 0047f92d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f92f  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047f932  e894ffffff             -call 0x47f8cb
    cpu.esp -= 4;
    sub_47f8cb(app, cpu);
    if (cpu.terminate) return;
    // 0047f937  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047f939  4a                     -dec edx
    (cpu.edx)--;
    // 0047f93a  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 0047f93d  39f2                   +cmp edx, esi
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
    // 0047f93f  75ec                   -jne 0x47f92d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f92d;
    }
    // 0047f941  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047f944  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047f947  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047f94a  c641055f               -mov byte ptr [ecx + 5], 0x5f
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 0047f94e  e878ffffff             -call 0x47f8cb
    cpu.esp -= 4;
    sub_47f8cb(app, cpu);
    if (cpu.terminate) return;
    // 0047f953  884106                 -mov byte ptr [ecx + 6], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 0047f956  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047f959  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047f95c  e86affffff             -call 0x47f8cb
    cpu.esp -= 4;
    sub_47f8cb(app, cpu);
    if (cpu.terminate) return;
    // 0047f961  c641082e               -mov byte ptr [ecx + 8], 0x2e
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 0047f965  c6410974               -mov byte ptr [ecx + 9], 0x74
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 0047f969  c6410a6d               -mov byte ptr [ecx + 0xa], 0x6d
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 0047f96d  c6410b70               -mov byte ptr [ecx + 0xb], 0x70
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 0047f971  c6410c00               -mov byte ptr [ecx + 0xc], 0
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047f975  884107                 -mov byte ptr [ecx + 7], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047f978  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f97b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f97c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f97d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f97e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f97f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f980  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f97b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047f97b;
    // 0047f8d7  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f8d8  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f8d9  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f8da  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f8db  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f8dc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f8df  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047f8e1  891424                 -mov dword ptr [esp], edx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047f8e4  e82eaf0100             -call 0x49a817
    cpu.esp -= 4;
    sub_49a817(app, cpu);
    if (cpu.terminate) return;
    // 0047f8e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f8eb  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 0047f8ee  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047f8f0  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f8f2  e821b00100             -call 0x49a918
    cpu.esp -= 4;
    sub_49a918(app, cpu);
    if (cpu.terminate) return;
    // 0047f8f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f8f9  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047f8fa:
    // 0047f8fa  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 0047f8fc  8807                   -mov byte ptr [edi], al
    *app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047f8fe  3c00                   +cmp al, 0
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
    // 0047f900  7410                   -je 0x47f912
    if (cpu.flags.zf)
    {
        goto L_0x0047f912;
    }
    // 0047f902  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047f905  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047f908  884701                 -mov byte ptr [edi + 1], al
    *app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047f90b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047f90e  3c00                   +cmp al, 0
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
    // 0047f910  75e8                   -jne 0x47f8fa
    if (!cpu.flags.zf)
    {
        goto L_0x0047f8fa;
    }
L_0x0047f912:
    // 0047f912  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f913  06                     -push es
    *app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 0047f914  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 0047f916  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 0047f918  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f91a  49                     -dec ecx
    (cpu.ecx)--;
    // 0047f91b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f91d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047f91f  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047f921  49                     -dec ecx
    (cpu.ecx)--;
    // 0047f922  07                     -pop es
    cpu.es = *app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 0047f923  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f925  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047f928  c60174                 -mov byte ptr [ecx], 0x74
    *app->getMemory<x86::reg8>(cpu.ecx) = 116 /*0x74*/;
    // 0047f92b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x0047f92d:
    // 0047f92d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f92f  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047f932  e894ffffff             -call 0x47f8cb
    cpu.esp -= 4;
    sub_47f8cb(app, cpu);
    if (cpu.terminate) return;
    // 0047f937  8802                   -mov byte ptr [edx], al
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 0047f939  4a                     -dec edx
    (cpu.edx)--;
    // 0047f93a  c1eb04                 -shr ebx, 4
    cpu.ebx >>= 4 /*0x4*/ % 32;
    // 0047f93d  39f2                   +cmp edx, esi
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
    // 0047f93f  75ec                   -jne 0x47f92d
    if (!cpu.flags.zf)
    {
        goto L_0x0047f92d;
    }
    // 0047f941  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047f944  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0047f947  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047f94a  c641055f               -mov byte ptr [ecx + 5], 0x5f
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */) = 95 /*0x5f*/;
    // 0047f94e  e878ffffff             -call 0x47f8cb
    cpu.esp -= 4;
    sub_47f8cb(app, cpu);
    if (cpu.terminate) return;
    // 0047f953  884106                 -mov byte ptr [ecx + 6], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 0047f956  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 0047f959  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047f95c  e86affffff             -call 0x47f8cb
    cpu.esp -= 4;
    sub_47f8cb(app, cpu);
    if (cpu.terminate) return;
    // 0047f961  c641082e               -mov byte ptr [ecx + 8], 0x2e
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 46 /*0x2e*/;
    // 0047f965  c6410974               -mov byte ptr [ecx + 9], 0x74
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(9) /* 0x9 */) = 116 /*0x74*/;
    // 0047f969  c6410a6d               -mov byte ptr [ecx + 0xa], 0x6d
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(10) /* 0xa */) = 109 /*0x6d*/;
    // 0047f96d  c6410b70               -mov byte ptr [ecx + 0xb], 0x70
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(11) /* 0xb */) = 112 /*0x70*/;
    // 0047f971  c6410c00               -mov byte ptr [ecx + 0xc], 0
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047f975  884107                 -mov byte ptr [ecx + 7], al
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 0047f978  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_entry_0x0047f97b:
    // 0047f97b  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f97c  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f97d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f97e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f97f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f980  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f981(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f981  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f982  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f983  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f984  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f985  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f986  81ec14010000           -sub esp, 0x114
    (cpu.esp) -= x86::reg32(x86::sreg32(276 /*0x114*/));
    // 0047f98c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f98e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047f990  83780c00               +cmp dword ptr [eax + 0xc], 0
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
    // 0047f994  750a                   -jne 0x47f9a0
    if (!cpu.flags.zf)
    {
        goto L_0x0047f9a0;
    }
    // 0047f996  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047f99b  e993000000             -jmp 0x47fa33
    goto L_0x0047fa33;
L_0x0047f9a0:
    // 0047f9a0  8a600d                 -mov ah, byte ptr [eax + 0xd]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 0047f9a3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047f9a5  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 0047f9a8  7409                   -je 0x47f9b3
    if (cpu.flags.zf)
    {
        goto L_0x0047f9b3;
    }
    // 0047f9aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f9ac  e82fb00100             -call 0x49a9e0
    cpu.esp -= 4;
    sub_49a9e0(app, cpu);
    if (cpu.terminate) return;
    // 0047f9b1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0047f9b3:
    // 0047f9b3  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047f9b6  ff1548c14c00           -call dword ptr [0x4cc148]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030216) /* 0x4cc148 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f9bc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f9be  e82cb10100             -call 0x49aaef
    cpu.esp -= 4;
    sub_49aaef(app, cpu);
    if (cpu.terminate) return;
    // 0047f9c3  83f8ff                 +cmp eax, -1
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
    // 0047f9c6  740e                   -je 0x47f9d6
    if (cpu.flags.zf)
    {
        goto L_0x0047f9d6;
    }
    // 0047f9c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f9ca  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047f9cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f9cf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047f9d1  e872b10100             -call 0x49ab48
    cpu.esp -= 4;
    sub_49ab48(app, cpu);
    if (cpu.terminate) return;
L_0x0047f9d6:
    // 0047f9d6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047f9d8  740a                   -je 0x47f9e4
    if (cpu.flags.zf)
    {
        goto L_0x0047f9e4;
    }
    // 0047f9da  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047f9dd  e8dab10100             -call 0x49abbc
    cpu.esp -= 4;
    sub_49abbc(app, cpu);
    if (cpu.terminate) return;
    // 0047f9e2  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047f9e4:
    // 0047f9e4  f6410c08               +test byte ptr [ecx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 0047f9e8  7415                   -je 0x47f9ff
    if (cpu.flags.zf)
    {
        goto L_0x0047f9ff;
    }
    // 0047f9ea  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047f9ed  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047f9f0  e854b20100             -call 0x49ac49
    cpu.esp -= 4;
    sub_49ac49(app, cpu);
    if (cpu.terminate) return;
    // 0047f9f5  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047f9f8  c7400800000000         -mov dword ptr [eax + 8], 0
    *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
L_0x0047f9ff:
    // 0047f9ff  f6410d08               +test byte ptr [ecx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 0047fa03  7416                   -je 0x47fa1b
    if (cpu.flags.zf)
    {
        goto L_0x0047fa1b;
    }
    // 0047fa05  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047fa08  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047fa0a  8a5014                 -mov dl, byte ptr [eax + 0x14]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0047fa0d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047fa0f  e8c3feffff             -call 0x47f8d7
    cpu.esp -= 4;
    sub_47f8d7(app, cpu);
    if (cpu.terminate) return;
    // 0047fa14  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047fa16  e832b30100             -call 0x49ad4d
    cpu.esp -= 4;
    sub_49ad4d(app, cpu);
    if (cpu.terminate) return;
L_0x0047fa1b:
    // 0047fa1b  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047fa1e  ff154cc14c00           -call dword ptr [0x4cc14c]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030220) /* 0x4cc14c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fa24  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047fa26  7409                   -je 0x47fa31
    if (cpu.flags.zf)
    {
        goto L_0x0047fa31;
    }
    // 0047fa28  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047fa2b  ff1554c14c00           -call dword ptr [0x4cc154]
    cpu.ip = *app->getMemory<x86::reg32>(x86::reg32(5030228) /* 0x4cc154 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047fa31:
    // 0047fa31  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047fa33:
    // 0047fa33  81c414010000           +add esp, 0x114
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(276 /*0x114*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fa39  e93dffffff             -jmp 0x47f97b
    return sub_47f97b(app, cpu);
}

/* align: skip 0x00 0x00 */
void Application::sub_47fa40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fa40  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa41  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fa42  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fa43  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fa45  8d3410                 -lea esi, [eax + edx]
    cpu.esi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0047fa48  baeafb0000             -mov edx, 0xfbea
    cpu.edx = 64490 /*0xfbea*/;
    // 0047fa4d  39f0                   +cmp eax, esi
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
    // 0047fa4f  7323                   -jae 0x47fa74
    if (!cpu.flags.cf)
    {
        goto L_0x0047fa74;
    }
L_0x0047fa51:
    // 0047fa51  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047fa53  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fa55  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0047fa57  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.eax);
    // 0047fa59  31d9                   -xor ecx, ebx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fa5b  668b0c4d748d4c00       -mov cx, word ptr [ecx*2 + 0x4c8d74]
    cpu.cx = *app->getMemory<x86::reg16>(x86::reg32(5016948) /* 0x4c8d74 */ + cpu.ecx * 2);
    // 0047fa63  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047fa69  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0047fa6c  40                     -inc eax
    (cpu.eax)++;
    // 0047fa6d  31ca                   -xor edx, ecx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047fa6f  39f0                   +cmp eax, esi
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
    // 0047fa71  72de                   -jb 0x47fa51
    if (cpu.flags.cf)
    {
        goto L_0x0047fa51;
    }
    // 0047fa73  90                     -nop 
    ;
L_0x0047fa74:
    // 0047fa74  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047fa76  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa77  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa78  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fa79  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47fa80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fa80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47fa84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fa84  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047fa86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fa88  740c                   -je 0x47fa96
    if (cpu.flags.zf)
    {
        goto L_0x0047fa96;
    }
L_0x0047fa8a:
    // 0047fa8a  4a                     -dec edx
    (cpu.edx)--;
    // 0047fa8b  83faff                 +cmp edx, -1
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
    // 0047fa8e  7406                   -je 0x47fa96
    if (cpu.flags.zf)
    {
        goto L_0x0047fa96;
    }
    // 0047fa90  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047fa92  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fa94  75f4                   -jne 0x47fa8a
    if (!cpu.flags.zf)
    {
        goto L_0x0047fa8a;
    }
L_0x0047fa96:
    // 0047fa96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47fa98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fa98  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa99  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fa9a  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fa9b  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa9c  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fa9d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fa9f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047faa1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047faa3  7441                   -je 0x47fae6
    if (cpu.flags.zf)
    {
        goto L_0x0047fae6;
    }
    // 0047faa5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047faa7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047faa9  763b                   -jbe 0x47fae6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047fae6;
    }
    // 0047faab  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047faae  39fa                   +cmp edx, edi
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
    // 0047fab0  743c                   -je 0x47faee
    if (cpu.flags.zf)
    {
        goto L_0x0047faee;
    }
    // 0047fab2  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.edi);
    // 0047fab4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047fab6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047fab8  740b                   -je 0x47fac5
    if (cpu.flags.zf)
    {
        goto L_0x0047fac5;
    }
L_0x0047faba:
    // 0047faba  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fabc  7407                   -je 0x47fac5
    if (cpu.flags.zf)
    {
        goto L_0x0047fac5;
    }
    // 0047fabe  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047fac0  833800                 +cmp dword ptr [eax], 0
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
    // 0047fac3  75f5                   -jne 0x47faba
    if (!cpu.flags.zf)
    {
        goto L_0x0047faba;
    }
L_0x0047fac5:
    // 0047fac5  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047fac7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047fac9  7417                   -je 0x47fae2
    if (cpu.flags.zf)
    {
        goto L_0x0047fae2;
    }
    // 0047facb  39f2                   +cmp edx, esi
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
    // 0047facd  7513                   -jne 0x47fae2
    if (!cpu.flags.zf)
    {
        goto L_0x0047fae2;
    }
    // 0047facf  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047fad4  2919                   -sub dword ptr [ecx], ebx
    (*app->getMemory<x86::reg32>(cpu.ecx)) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fad6  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esi);
    // 0047fad8  8930                   -mov dword ptr [eax], esi
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0047fada  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fadd  7503                   -jne 0x47fae2
    if (!cpu.flags.zf)
    {
        goto L_0x0047fae2;
    }
    // 0047fadf  89410c                 -mov dword ptr [ecx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0047fae2:
    // 0047fae2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fae4  7544                   -jne 0x47fb2a
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb2a;
    }
L_0x0047fae6:
    // 0047fae6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fae8  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fae9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047faea  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047faeb  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047faec  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047faed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047faee:
    // 0047faee  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047faf3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047faf5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047faf7  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047fafa  8901                   -mov dword ptr [ecx], eax
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0047fafc  39f7                   +cmp edi, esi
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
    // 0047fafe  7519                   -jne 0x47fb19
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb19;
    }
    // 0047fb00  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047fb07  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047fb0a  89410c                 -mov dword ptr [ecx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047fb0d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fb0f  7519                   -jne 0x47fb2a
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb2a;
    }
    // 0047fb11  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fb13  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb14  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb15  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb16  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb17  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fb19:
    // 0047fb19  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0047fb1b  894108                 -mov dword ptr [ecx + 8], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047fb1e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fb20  7508                   -jne 0x47fb2a
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb2a;
    }
    // 0047fb22  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fb24  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb25  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb26  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb27  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb28  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fb2a:
    // 0047fb2a  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047fb30  80490401               -or byte ptr [ecx + 4], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047fb34  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fb36  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb37  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb38  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb39  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb3a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fb3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fb3c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fb3d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fb3f  e874f4ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0047fb44  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0047fb4a  c7410400000000         -mov dword ptr [ecx + 4], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0047fb51  c7410800000000         -mov dword ptr [ecx + 8], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047fb58  c7410c00000000         -mov dword ptr [ecx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047fb5f  894118                 -mov dword ptr [ecx + 0x18], eax
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047fb62  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047fb64  7408                   -je 0x47fb6e
    if (cpu.flags.zf)
    {
        goto L_0x0047fb6e;
    }
    // 0047fb66  895110                 -mov dword ptr [ecx + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047fb69  895914                 -mov dword ptr [ecx + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047fb6c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fb6e:
    // 0047fb6e  ba80fa4700             -mov edx, 0x47fa80
    cpu.edx = 4717184 /*0x47fa80*/;
    // 0047fb73  895110                 -mov dword ptr [ecx + 0x10], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047fb76  895914                 -mov dword ptr [ecx + 0x14], ebx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047fb79  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47fb7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fb7c  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fb7d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047fb7f  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fb82  e8adf4ffff             -call 0x47f034
    cpu.esp -= 4;
    sub_47f034(app, cpu);
    if (cpu.terminate) return;
    // 0047fb87  c7421800000000         -mov dword ptr [edx + 0x18], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047fb8e  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fb8f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fb90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fb90  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fb91  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fb93  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fb96  e86df4ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fb9b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047fb9d  741b                   -je 0x47fbba
    if (cpu.flags.zf)
    {
        goto L_0x0047fbba;
    }
    // 0047fb9f  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fba0  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047fba3  8902                   -mov dword ptr [edx], eax
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0047fba5  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047fba7  895108                 -mov dword ptr [ecx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047fbaa  43                     -inc ebx
    (cpu.ebx)++;
    // 0047fbab  8919                   -mov dword ptr [ecx], ebx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0047fbad  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fbb0  7503                   -jne 0x47fbb5
    if (!cpu.flags.zf)
    {
        goto L_0x0047fbb5;
    }
    // 0047fbb2  89510c                 -mov dword ptr [ecx + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0047fbb5:
    // 0047fbb5  80490401               -or byte ptr [ecx + 4], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047fbb9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047fbba:
    // 0047fbba  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fbbd  e85ef4ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fbc2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fbc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fbc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fbc4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fbc5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fbc7  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fbca  e839f4ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fbcf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047fbd1  741e                   -je 0x47fbf1
    if (cpu.flags.zf)
    {
        goto L_0x0047fbf1;
    }
    // 0047fbd3  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fbd4  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047fbd7  c70200000000           -mov dword ptr [edx], 0
    *app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047fbdd  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047fbdf  89510c                 -mov dword ptr [ecx + 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047fbe2  43                     -inc ebx
    (cpu.ebx)++;
    // 0047fbe3  8919                   -mov dword ptr [ecx], ebx
    *app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0047fbe5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fbe7  7512                   -jne 0x47fbfb
    if (!cpu.flags.zf)
    {
        goto L_0x0047fbfb;
    }
    // 0047fbe9  895108                 -mov dword ptr [ecx + 8], edx
    *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047fbec  80490401               -or byte ptr [ecx + 4], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047fbf0  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047fbf1:
    // 0047fbf1  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fbf4  e827f4ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fbf9  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fbfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fbfb:
    // 0047fbfb  8910                   -mov dword ptr [eax], edx
    *app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0047fbfd  80490401               -or byte ptr [ecx + 4], 1
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0047fc01  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc02  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fc05  e816f4ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fc0a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fc0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fc0c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fc0d  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fc0e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047fc10  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fc13  e8f0f3ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fc18  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047fc1b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fc1d  741a                   -je 0x47fc39
    if (cpu.flags.zf)
    {
        goto L_0x0047fc39;
    }
    // 0047fc1f  3b4a0c                 +cmp ecx, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fc22  7526                   -jne 0x47fc4a
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc4a;
    }
    // 0047fc24  c7420c00000000         -mov dword ptr [edx + 0xc], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047fc2b  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
L_0x0047fc2e:
    // 0047fc2e  894208                 -mov dword ptr [edx + 8], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047fc31  ff0a                   -dec dword ptr [edx]
    (*app->getMemory<x86::reg32>(cpu.edx))--;
    // 0047fc33  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x0047fc39:
    // 0047fc39  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047fc3d  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047fc40  e8dbf3ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fc45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fc47  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc48  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fc4a:
    // 0047fc4a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047fc4c  ebe0                   -jmp 0x47fc2e
    goto L_0x0047fc2e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47fc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fc50  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fc51  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fc52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047fc54  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fc57  e8acf3ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fc5c  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047fc5f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fc61  742f                   -je 0x47fc92
    if (cpu.flags.zf)
    {
        goto L_0x0047fc92;
    }
    // 0047fc63  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fc64  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fc65  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.edx);
    // 0047fc67  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047fc68  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047fc6b  891a                   -mov dword ptr [edx], ebx
    *app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0047fc6d  39f1                   +cmp ecx, esi
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
    // 0047fc6f  7432                   -je 0x47fca3
    if (cpu.flags.zf)
    {
        goto L_0x0047fca3;
    }
    // 0047fc71  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fc72  89720c                 -mov dword ptr [edx + 0xc], esi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.esi;
L_0x0047fc75:
    // 0047fc75  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047fc78  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047fc7a  39f9                   +cmp ecx, edi
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
    // 0047fc7c  7405                   -je 0x47fc83
    if (cpu.flags.zf)
    {
        goto L_0x0047fc83;
    }
    // 0047fc7e  897a0c                 -mov dword ptr [edx + 0xc], edi
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0047fc81  ebf2                   -jmp 0x47fc75
    goto L_0x0047fc75;
L_0x0047fc83:
    // 0047fc83  c70000000000           -mov dword ptr [eax], 0
    *app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0047fc89  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047fc8a:
    // 0047fc8a  c70100000000           -mov dword ptr [ecx], 0
    *app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
    // 0047fc90  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc91  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047fc92:
    // 0047fc92  804a0401               +or byte ptr [edx + 4], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047fc96  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047fc99  e882f3ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fc9e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fca0  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fca1  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fca2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fca3:
    // 0047fca3  c7420800000000         -mov dword ptr [edx + 8], 0
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047fcaa  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047fcad  89420c                 -mov dword ptr [edx + 0xc], eax
    *app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047fcb0  ebd8                   -jmp 0x47fc8a
    goto L_0x0047fc8a;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47fcb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fcb4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fcb5  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fcb6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047fcb8  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047fcba  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fcbd  e846f3ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fcc2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047fcc4  750b                   -jne 0x47fcd1
    if (!cpu.flags.zf)
    {
        goto L_0x0047fcd1;
    }
    // 0047fcc6  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0047fcc9  e852f3ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fcce  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fccf  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fcd0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fcd1:
    // 0047fcd1  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fcd2  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fcd3  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fcd4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047fcd6  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0047fcd9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047fcdb  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fcde  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx);
    // 0047fce0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047fce2  42                     -inc edx
    (cpu.edx)++;
    // 0047fce3  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047fce6  8913                   -mov dword ptr [ebx], edx
    *app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0047fce8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fcea  7414                   -je 0x47fd00
    if (cpu.flags.zf)
    {
        goto L_0x0047fd00;
    }
L_0x0047fcec:
    // 0047fcec  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fcee  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0047fcf1  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fcf4  39f8                   +cmp eax, edi
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
    // 0047fcf6  7308                   -jae 0x47fd00
    if (!cpu.flags.cf)
    {
        goto L_0x0047fd00;
    }
    // 0047fcf8  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047fcfa  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047fcfc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fcfe  75ec                   -jne 0x47fcec
    if (!cpu.flags.zf)
    {
        goto L_0x0047fcec;
    }
L_0x0047fd00:
    // 0047fd00  894d00                 -mov dword ptr [ebp], ecx
    *app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0047fd03  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047fd05  751c                   -jne 0x47fd23
    if (!cpu.flags.zf)
    {
        goto L_0x0047fd23;
    }
    // 0047fd07  896b08                 -mov dword ptr [ebx + 8], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x0047fd0a:
    // 0047fd0a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fd0c  7503                   -jne 0x47fd11
    if (!cpu.flags.zf)
    {
        goto L_0x0047fd11;
    }
    // 0047fd0e  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
L_0x0047fd11:
    // 0047fd11  804b0401               +or byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp((*app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0047fd15  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd16  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd17  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd18  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0047fd1b  e800f3ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fd20  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd21  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd22  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fd23:
    // 0047fd23  892e                   -mov dword ptr [esi], ebp
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.ebp;
    // 0047fd25  ebe3                   -jmp 0x47fd0a
    goto L_0x0047fd0a;
}

/* align: skip 0x90 */
void Application::sub_47fd28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fd28  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fd29  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fd2a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fd2c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fd2f  e8d4f2ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fd34  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047fd36  750d                   -jne 0x47fd45
    if (!cpu.flags.zf)
    {
        goto L_0x0047fd45;
    }
    // 0047fd38  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fd3b  e8e0f2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fd40  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fd42  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd43  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fd45:
    // 0047fd45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fd47  e84cfdffff             -call 0x47fa98
    cpu.esp -= 4;
    sub_47fa98(app, cpu);
    if (cpu.terminate) return;
    // 0047fd4c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047fd4e  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fd51  e8caf2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fd56  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fd58  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd59  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fd5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47fd5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fd5c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax);
    // 0047fd5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47fd60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fd60  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fd61  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fd62  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fd63  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fd64  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fd65  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047fd68  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047fd6a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047fd6c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fd6f  e894f2ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fd74  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fd76  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047fd78  742b                   -je 0x47fda5
    if (cpu.flags.zf)
    {
        goto L_0x0047fda5;
    }
    // 0047fd7a  8b7710                 -mov esi, dword ptr [edi + 0x10]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0047fd7d  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047fd80  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047fd82  7539                   -jne 0x47fdbd
    if (!cpu.flags.zf)
    {
        goto L_0x0047fdbd;
    }
    // 0047fd84  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047fd86:
    // 0047fd86  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047fd89  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fd8b  7414                   -je 0x47fda1
    if (cpu.flags.zf)
    {
        goto L_0x0047fda1;
    }
L_0x0047fd8d:
    // 0047fd8d  39e9                   +cmp ecx, ebp
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
    // 0047fd8f  7410                   -je 0x47fda1
    if (cpu.flags.zf)
    {
        goto L_0x0047fda1;
    }
    // 0047fd91  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047fd93  7431                   -je 0x47fdc6
    if (cpu.flags.zf)
    {
        goto L_0x0047fdc6;
    }
    // 0047fd95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fd97  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0047fd9a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fd9c  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(*app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fd9f  7625                   -jbe 0x47fdc6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047fdc6;
    }
L_0x0047fda1:
    // 0047fda1  39e9                   +cmp ecx, ebp
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
    // 0047fda3  7405                   -je 0x47fdaa
    if (cpu.flags.zf)
    {
        goto L_0x0047fdaa;
    }
L_0x0047fda5:
    // 0047fda5  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
L_0x0047fdaa:
    // 0047fdaa  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047fdad  e86ef2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fdb2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fdb4  83c404                 +add esp, 4
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
    // 0047fdb7  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdb8  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdb9  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdba  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdbb  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdbc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fdbd:
    // 0047fdbd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047fdbf  8b5714                 -mov edx, dword ptr [edi + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 0047fdc2  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fdc4  ebc0                   -jmp 0x47fd86
    goto L_0x0047fd86;
L_0x0047fdc6:
    // 0047fdc6  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047fdc8  43                     -inc ebx
    (cpu.ebx)++;
    // 0047fdc9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fdcb  75c0                   -jne 0x47fd8d
    if (!cpu.flags.zf)
    {
        goto L_0x0047fd8d;
    }
    // 0047fdcd  ebd2                   -jmp 0x47fda1
    goto L_0x0047fda1;
}

/* align: skip 0x90 */
void Application::sub_47fdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fdd0  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fdd1  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fdd2  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fdd3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fdd5  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fdd8  e82bf2ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fddd  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047fde0  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047fde5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fde7  750e                   -jne 0x47fdf7
    if (!cpu.flags.zf)
    {
        goto L_0x0047fdf7;
    }
    // 0047fde9  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fdec  e82ff2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fdf1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047fdf3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdf4  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdf5  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fdf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fdf7:
    // 0047fdf7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fdf9  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0047fdfc  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fdff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047fe01  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fe04  e817f2ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fe09  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047fe0b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe0c  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe0d  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47fe10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fe10  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fe11  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fe12  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fe13  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fe15  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fe18  e8ebf1ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fe1d  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047fe20  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047fe22  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fe24  750e                   -jne 0x47fe34
    if (!cpu.flags.zf)
    {
        goto L_0x0047fe34;
    }
    // 0047fe26  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fe29  e8f2f1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fe2e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047fe30  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe31  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe32  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fe34:
    // 0047fe34  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fe36  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0047fe39  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fe3c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047fe3e  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fe41  e8daf1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fe46  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047fe48  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe49  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe4a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe4b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fe4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fe4c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fe4d  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fe4e  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fe4f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047fe51  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047fe53  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fe56  e8adf1ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fe5b  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047fe5e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fe60  7414                   -je 0x47fe76
    if (cpu.flags.zf)
    {
        goto L_0x0047fe76;
    }
L_0x0047fe62:
    // 0047fe62  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047fe64  7410                   -je 0x47fe76
    if (cpu.flags.zf)
    {
        goto L_0x0047fe76;
    }
    // 0047fe66  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047fe68  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fe6a  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fe6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fe6e  7506                   -jne 0x47fe76
    if (!cpu.flags.zf)
    {
        goto L_0x0047fe76;
    }
    // 0047fe70  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047fe72  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fe74  75ec                   -jne 0x47fe62
    if (!cpu.flags.zf)
    {
        goto L_0x0047fe62;
    }
L_0x0047fe76:
    // 0047fe76  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047fe79  e8a2f1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fe7e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fe80  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe81  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe82  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47fe84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fe84  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fe85  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fe86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fe88  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fe8b  e878f1ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fe90  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047fe93  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047fe95  741f                   -je 0x47feb6
    if (cpu.flags.zf)
    {
        goto L_0x0047feb6;
    }
    // 0047fe97  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047fe99  770f                   -ja 0x47feaa
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047feaa;
    }
    // 0047fe9b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x0047fe9d:
    // 0047fe9d  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fea0  e87bf1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fea5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047fea7  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fea8  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fea9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047feaa:
    // 0047feaa  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047feab  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fead  e8d2fbffff             -call 0x47fa84
    cpu.esp -= 4;
    sub_47fa84(app, cpu);
    if (cpu.terminate) return;
    // 0047feb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047feb4  ebe7                   -jmp 0x47fe9d
    goto L_0x0047fe9d;
L_0x0047feb6:
    // 0047feb6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047feb8  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047febb  e860f1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fec0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047fec2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fec3  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fec4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47fec8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047fec8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fec9  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047feca  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fecb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047fecd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047fecf  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047fed2  e831f1ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047fed7  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047feda  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fedc  7412                   -je 0x47fef0
    if (cpu.flags.zf)
    {
        goto L_0x0047fef0;
    }
L_0x0047fede:
    // 0047fede  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fee0  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0047fee3  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047fee6  39f0                   +cmp eax, esi
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
    // 0047fee8  7306                   -jae 0x47fef0
    if (!cpu.flags.cf)
    {
        goto L_0x0047fef0;
    }
    // 0047feea  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047feec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047feee  75ee                   -jne 0x47fede
    if (!cpu.flags.zf)
    {
        goto L_0x0047fede;
    }
L_0x0047fef0:
    // 0047fef0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047fef2  750e                   -jne 0x47ff02
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff02;
    }
L_0x0047fef4:
    // 0047fef4  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0047fef7  e824f1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fefc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047fefe  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047feff  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff00  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ff02:
    // 0047ff02  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ff04  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0047ff07  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ff0a  39f0                   +cmp eax, esi
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
    // 0047ff0c  74e6                   -je 0x47fef4
    if (cpu.flags.zf)
    {
        goto L_0x0047fef4;
    }
    // 0047ff0e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ff10  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0047ff13  e808f1ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047ff18  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ff1a  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff1b  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff1c  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ff20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ff20  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ff21  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ff22  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ff23  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047ff25  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047ff27  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047ff2a  e8d9f0ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047ff2f  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047ff32  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ff34  7414                   -je 0x47ff4a
    if (cpu.flags.zf)
    {
        goto L_0x0047ff4a;
    }
L_0x0047ff36:
    // 0047ff36  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047ff38  7410                   -je 0x47ff4a
    if (cpu.flags.zf)
    {
        goto L_0x0047ff4a;
    }
    // 0047ff3a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047ff3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ff3e  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ff40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ff42  7506                   -jne 0x47ff4a
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff4a;
    }
    // 0047ff44  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 0047ff46  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ff48  75ec                   -jne 0x47ff36
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff36;
    }
L_0x0047ff4a:
    // 0047ff4a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ff4c  750e                   -jne 0x47ff5c
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff5c;
    }
L_0x0047ff4e:
    // 0047ff4e  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047ff51  e8caf0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047ff56  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ff58  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff59  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff5a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff5b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ff5c:
    // 0047ff5c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ff5e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ff60  e833fbffff             -call 0x47fa98
    cpu.esp -= 4;
    sub_47fa98(app, cpu);
    if (cpu.terminate) return;
    // 0047ff65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ff67  75e5                   -jne 0x47ff4e
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff4e;
    }
    // 0047ff69  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ff6b  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 0047ff6e  e8adf0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047ff73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ff75  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff76  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff77  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ff7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ff7c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ff7d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ff7e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ff80  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047ff82  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047ff85  e87ef0ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047ff8a  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047ff8d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ff8f  7433                   -je 0x47ffc4
    if (cpu.flags.zf)
    {
        goto L_0x0047ffc4;
    }
    // 0047ff91  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047ff93  7713                   -ja 0x47ffa8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047ffa8;
    }
    // 0047ff95  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0047ff97:
    // 0047ff97  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047ff99  751c                   -jne 0x47ffb7
    if (!cpu.flags.zf)
    {
        goto L_0x0047ffb7;
    }
L_0x0047ff9b:
    // 0047ff9b  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047ff9e  e87df0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047ffa3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ffa5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ffa6  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ffa7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ffa8:
    // 0047ffa8  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0047ffab  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047ffae  e8d1faffff             -call 0x47fa84
    cpu.esp -= 4;
    sub_47fa84(app, cpu);
    if (cpu.terminate) return;
    // 0047ffb3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ffb5  ebe0                   -jmp 0x47ff97
    goto L_0x0047ff97;
L_0x0047ffb7:
    // 0047ffb7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047ffb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ffbb  e8d8faffff             -call 0x47fa98
    cpu.esp -= 4;
    sub_47fa98(app, cpu);
    if (cpu.terminate) return;
    // 0047ffc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ffc2  75d7                   -jne 0x47ff9b
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff9b;
    }
L_0x0047ffc4:
    // 0047ffc4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ffc6  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047ffc9  e852f0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047ffce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047ffd0  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ffd1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ffd2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47ffd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ffd4  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ffd5  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ffd6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ffd8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047ffda  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047ffdd  e826f0ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0047ffe2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047ffe4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047ffe6  e899faffff             -call 0x47fa84
    cpu.esp -= 4;
    sub_47fa84(app, cpu);
    if (cpu.terminate) return;
    // 0047ffeb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ffed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ffef  750d                   -jne 0x47fffe
    if (!cpu.flags.zf)
    {
        goto L_0x0047fffe;
    }
L_0x0047fff1:
    // 0047fff1  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047fff4  e827f0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0047fff9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047fffb  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fffc  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fffd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047fffe:
    // 0047fffe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480000  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480002  e891faffff             -call 0x47fa98
    cpu.esp -= 4;
    sub_47fa98(app, cpu);
    if (cpu.terminate) return;
    // 00480007  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480009  75e6                   -jne 0x47fff1
    if (!cpu.flags.zf)
    {
        goto L_0x0047fff1;
    }
    // 0048000b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048000d  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00480010  e80bf0ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00480015  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480017  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480018  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480019  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48001c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048001c  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048001d  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048001e  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048001f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480021  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00480023  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00480026  e8ddefffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 0048002b  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048002e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480030  7412                   -je 0x480044
    if (cpu.flags.zf)
    {
        goto L_0x00480044;
    }
L_0x00480032:
    // 00480032  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480034  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00480037  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048003a  39f0                   +cmp eax, esi
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
    // 0048003c  7306                   -jae 0x480044
    if (!cpu.flags.cf)
    {
        goto L_0x00480044;
    }
    // 0048003e  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 00480040  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480042  75ee                   -jne 0x480032
    if (!cpu.flags.zf)
    {
        goto L_0x00480032;
    }
L_0x00480044:
    // 00480044  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480046  7510                   -jne 0x480058
    if (!cpu.flags.zf)
    {
        goto L_0x00480058;
    }
L_0x00480048:
    // 00480048  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048004a:
    // 0048004a  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048004d  e8ceefffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00480052  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480054  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480055  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480056  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480057  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480058:
    // 00480058  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048005a  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048005d  ff5310                 -call dword ptr [ebx + 0x10]
    cpu.ip = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480060  39f0                   +cmp eax, esi
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
    // 00480062  75e4                   -jne 0x480048
    if (!cpu.flags.zf)
    {
        goto L_0x00480048;
    }
    // 00480064  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00480066  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480068  e82bfaffff             -call 0x47fa98
    cpu.esp -= 4;
    sub_47fa98(app, cpu);
    if (cpu.terminate) return;
    // 0048006d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048006f  75d9                   -jne 0x48004a
    if (!cpu.flags.zf)
    {
        goto L_0x0048004a;
    }
    // 00480071  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480073  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 00480076  e8a5efffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048007b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048007d  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048007e  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048007f  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480084(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480084  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480085  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480086  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480087  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480088  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048008b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048008d  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048008f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00480091  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00480094  e86fefffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00480099  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048009c  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 0048009f  890424                 -mov dword ptr [esp], eax
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004800a2  806604fe               -and byte ptr [esi + 4], 0xfe
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004800a6  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004800a9  e872efffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004800ae  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004800b1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004800b3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004800b5  7422                   -je 0x4800d9
    if (cpu.flags.zf)
    {
        goto L_0x004800d9;
    }
L_0x004800b7:
    // 004800b7  8a5604                 -mov dl, byte ptr [esi + 4]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004800ba  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004800bd  751a                   -jne 0x4800d9
    if (!cpu.flags.zf)
    {
        goto L_0x004800d9;
    }
    // 004800bf  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 004800c2  750f                   -jne 0x4800d3
    if (!cpu.flags.zf)
    {
        goto L_0x004800d3;
    }
    // 004800c4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004800c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004800c8  ffd5                   -call ebp
    cpu.ip = cpu.ebp;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004800ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004800cc  7504                   -jne 0x4800d2
    if (!cpu.flags.zf)
    {
        goto L_0x004800d2;
    }
    // 004800ce  804e0401               -or byte ptr [esi + 4], 1
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004800d2:
    // 004800d2  43                     -inc ebx
    (cpu.ebx)++;
L_0x004800d3:
    // 004800d3  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ecx);
    // 004800d5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004800d7  75de                   -jne 0x4800b7
    if (!cpu.flags.zf)
    {
        goto L_0x004800b7;
    }
L_0x004800d9:
    // 004800d9  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004800dc  e827efffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004800e1  f6460401               +test byte ptr [esi + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 004800e5  741d                   -je 0x480104
    if (cpu.flags.zf)
    {
        goto L_0x00480104;
    }
L_0x004800e7:
    // 004800e7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esp);
    // 004800ea  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004800ed  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004800ef  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004800f2  895604                 -mov dword ptr [esi + 4], edx
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004800f5  e826efffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004800fa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004800fc  83c404                 +add esp, 4
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
    // 004800ff  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480100  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480101  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480102  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480103  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480104:
    // 00480104  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00480109  ebdc                   -jmp 0x4800e7
    goto L_0x004800e7;
}

/* align: skip 0x90 */
void Application::sub_48010c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048010c  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048010d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048010f  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00480112  e8f1eeffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00480117  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480119  e866ffffff             -call 0x480084
    cpu.esp -= 4;
    sub_480084(app, cpu);
    if (cpu.terminate) return;
    // 0048011e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480120  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 00480123  e8f8eeffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00480128  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048012a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048012b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48012c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048012c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048012f  e9d4eeffff             -jmp 0x47f008
    return sub_47f008(app, cpu);
}

/* align: skip  */
void Application::sub_480134(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480134  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00480137  e9e4eeffff             -jmp 0x47f020
    return sub_47f020(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_480140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480140  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480141  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480142  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480144  833d788f4c0000         +cmp dword ptr [0x4c8f78], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048014b  7424                   -je 0x480171
    if (cpu.flags.zf)
    {
        goto L_0x00480171;
    }
L_0x0048014d:
    // 0048014d  833d748f4c0000         +cmp dword ptr [0x4c8f74], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017460) /* 0x4c8f74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480154  750a                   -jne 0x480160
    if (!cpu.flags.zf)
    {
        goto L_0x00480160;
    }
    // 00480156  e85deeffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 0048015b  a3748f4c00             -mov dword ptr [0x4c8f74], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017460) /* 0x4c8f74 */) = cpu.eax;
L_0x00480160:
    // 00480160  833d788f4c0000         +cmp dword ptr [0x4c8f78], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480167  7453                   -je 0x4801bc
    if (cpu.flags.zf)
    {
        goto L_0x004801bc;
    }
    // 00480169  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048016e  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048016f  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480170  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480171:
    // 00480171  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480172  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480173  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480174  be0ce34b00             -mov esi, 0x4be30c
    cpu.esi = 4973324 /*0x4be30c*/;
    // 00480179  bf62000000             -mov edi, 0x62
    cpu.edi = 98 /*0x62*/;
    // 0048017e  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 00480181  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00480183  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00480185  83c004                 +add eax, 4
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
    // 00480188  89358c844c00           -mov dword ptr [0x4c848c], esi
    *app->getMemory<x86::reg32>(x86::reg32(5014668) /* 0x4c848c */) = cpu.esi;
    // 0048018e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480190  b81ce34b00             -mov eax, 0x4be31c
    cpu.eax = 4973340 /*0x4be31c*/;
    // 00480195  893d90844c00           -mov dword ptr [0x4c8490], edi
    *app->getMemory<x86::reg32>(x86::reg32(5014672) /* 0x4c8490 */) = cpu.edi;
    // 0048019b  e8c884ffff             -call 0x478668
    cpu.esp -= 4;
    sub_478668(app, cpu);
    if (cpu.terminate) return;
    // 004801a0  a3788f4c00             -mov dword ptr [0x4c8f78], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */) = cpu.eax;
    // 004801a5  890dd8ba5100           -mov dword ptr [0x51bad8], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5356248) /* 0x51bad8 */) = cpu.ecx;
    // 004801ab  892de0ba5100           -mov dword ptr [0x51bae0], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5356256) /* 0x51bae0 */) = cpu.ebp;
    // 004801b1  892ddcba5100           -mov dword ptr [0x51badc], ebp
    *app->getMemory<x86::reg32>(x86::reg32(5356252) /* 0x51badc */) = cpu.ebp;
    // 004801b7  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801b8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801b9  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801ba  eb91                   -jmp 0x48014d
    goto L_0x0048014d;
L_0x004801bc:
    // 004801bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004801be  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801bf  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4801c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004801c4  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004801c5  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004801c6  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004801c7  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004801c8  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004801c9  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004801ca  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004801cc  81ec0c010000           -sub esp, 0x10c
    (cpu.esp) -= x86::reg32(x86::sreg32(268 /*0x10c*/));
    // 004801d2  833d788f4c0000         +cmp dword ptr [0x4c8f78], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004801d9  0f8460020000           -je 0x48043f
    if (cpu.flags.zf)
    {
        goto L_0x0048043f;
    }
    // 004801df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004801e1  0f8458020000           -je 0x48043f
    if (cpu.flags.zf)
    {
        goto L_0x0048043f;
    }
    // 004801e7  e80cac0100             -call 0x49adf8
    cpu.esp -= 4;
    sub_49adf8(app, cpu);
    if (cpu.terminate) return;
L_0x004801ec:
    // 004801ec  8b15788f4c00           -mov edx, dword ptr [0x4c8f78]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
    // 004801f2  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004801f5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004801f7  8955f4                 -mov dword ptr [ebp - 0xc], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
    // 004801fa  890d788f4c00           -mov dword ptr [0x4c8f78], ecx
    *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */) = cpu.ecx;
    // 00480200  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480202  0f84ff020000           -je 0x480507
    if (cpu.flags.zf)
    {
        goto L_0x00480507;
    }
    // 00480208  a1e0ba5100             -mov eax, dword ptr [0x51bae0]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5356256) /* 0x51bae0 */);
    // 0048020d  8b1dd8ba5100           -mov ebx, dword ptr [0x51bad8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5356248) /* 0x51bad8 */);
    // 00480213  39d8                   +cmp eax, ebx
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
    // 00480215  0f8d2b020000           -jge 0x480446
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00480446;
    }
L_0x0048021b:
    // 0048021b  a3e0ba5100             -mov dword ptr [0x51bae0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5356256) /* 0x51bae0 */) = cpu.eax;
L_0x00480220:
    // 00480220  8b35e0ba5100           -mov esi, dword ptr [0x51bae0]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5356256) /* 0x51bae0 */);
    // 00480226  4e                     -dec esi
    (cpu.esi)--;
    // 00480227  8935e0ba5100           -mov dword ptr [0x51bae0], esi
    *app->getMemory<x86::reg32>(x86::reg32(5356256) /* 0x51bae0 */) = cpu.esi;
    // 0048022d  83feff                 +cmp esi, -1
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
    // 00480230  0f84c9020000           -je 0x4804ff
    if (cpu.flags.zf)
    {
        goto L_0x004804ff;
    }
    // 00480236  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00480239  8b35dcba5100           -mov esi, dword ptr [0x51badc]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5356252) /* 0x51badc */);
    // 0048023f  8b15dcba5100           -mov edx, dword ptr [0x51badc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356252) /* 0x51badc */);
    // 00480245  8b0dd8ba5100           -mov ecx, dword ptr [0x51bad8]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5356248) /* 0x51bad8 */);
    // 0048024b  c1e606                 -shl esi, 6
    cpu.esi <<= 6 /*0x6*/ % 32;
    // 0048024e  42                     -inc edx
    (cpu.edx)++;
    // 0048024f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480251  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480253  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480256  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00480258  8a6609                 -mov ah, byte ptr [esi + 9]
    cpu.ah = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0048025b  8915dcba5100           -mov dword ptr [0x51badc], edx
    *app->getMemory<x86::reg32>(x86::reg32(5356252) /* 0x51badc */) = cpu.edx;
    // 00480261  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00480263  0f84ee010000           -je 0x480457
    if (cpu.flags.zf)
    {
        goto L_0x00480457;
    }
    // 00480269  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048026b  8a4609                 -mov al, byte ptr [esi + 9]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */);
    // 0048026e  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00480271  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480272  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 00480275  0f84d2010000           -je 0x48044d
    if (cpu.flags.zf)
    {
        goto L_0x0048044d;
    }
    // 0048027b  b828e34b00             -mov eax, 0x4be328
    cpu.eax = 4973352 /*0x4be328*/;
L_0x00480280:
    // 00480280  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480281  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00480283  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480284  6838e34b00             -push 0x4be338
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4973368 /*0x4be338*/;
    cpu.esp -= 4;
    // 00480289  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048028f  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480290  e88ca1ffff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00480295  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x00480298:
    // 00480298  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048029e  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004802a4  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004802a6  49                     -dec ecx
    (cpu.ecx)--;
    // 004802a7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004802a9  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004802ab  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004802ad  49                     -dec ecx
    (cpu.ecx)--;
    // 004802ae  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004802b1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004802b3  e8a4ac0100             -call 0x49af5c
    cpu.esp -= 4;
    sub_49af5c(app, cpu);
    if (cpu.terminate) return;
    // 004802b8  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004802bd  8d45f8                 -lea eax, [ebp - 8]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004802c0  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004802c3  e8c85b0100             -call 0x495e90
    cpu.esp -= 4;
    sub_495e90(app, cpu);
    if (cpu.terminate) return;
    // 004802c8  8a5df8                 -mov bl, byte ptr [ebp - 8]
    cpu.bl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004802cb  80fb20                 +cmp bl, 0x20
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
    // 004802ce  0f83b2010000           -jae 0x480486
    if (!cpu.flags.cf)
    {
        goto L_0x00480486;
    }
L_0x004802d4:
    // 004802d4  c645f85f               -mov byte ptr [ebp - 8], 0x5f
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = 95 /*0x5f*/;
L_0x004802d8:
    // 004802d8  8a6df9                 -mov ch, byte ptr [ebp - 7]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 004802db  80fd20                 +cmp ch, 0x20
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004802de  0f83b0010000           -jae 0x480494
    if (!cpu.flags.cf)
    {
        goto L_0x00480494;
    }
L_0x004802e4:
    // 004802e4  c645f95f               -mov byte ptr [ebp - 7], 0x5f
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */) = 95 /*0x5f*/;
L_0x004802e8:
    // 004802e8  8a55fa                 -mov dl, byte ptr [ebp - 6]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 004802eb  80fa20                 +cmp dl, 0x20
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
    // 004802ee  0f83ae010000           -jae 0x4804a2
    if (!cpu.flags.cf)
    {
        goto L_0x004804a2;
    }
L_0x004802f4:
    // 004802f4  c645fa5f               -mov byte ptr [ebp - 6], 0x5f
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */) = 95 /*0x5f*/;
L_0x004802f8:
    // 004802f8  8a7dfb                 -mov bh, byte ptr [ebp - 5]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 004802fb  80ff20                 +cmp bh, 0x20
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004802fe  0f83ac010000           -jae 0x4804b0
    if (!cpu.flags.cf)
    {
        goto L_0x004804b0;
    }
L_0x00480304:
    // 00480304  c645fb5f               -mov byte ptr [ebp - 5], 0x5f
    *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */) = 95 /*0x5f*/;
L_0x00480308:
    // 00480308  f6460a02               +test byte ptr [esi + 0xa], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 2 /*0x2*/));
    // 0048030c  0f84ac010000           -je 0x4804be
    if (cpu.flags.zf)
    {
        goto L_0x004804be;
    }
    // 00480312  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480314  8a45fb                 -mov al, byte ptr [ebp - 5]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-5) /* -0x5 */);
    // 00480317  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480318  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048031a  8a45fa                 -mov al, byte ptr [ebp - 6]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 0048031d  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048031e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480320  8a45f9                 -mov al, byte ptr [ebp - 7]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-7) /* -0x7 */);
    // 00480323  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480324  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480326  8a45f8                 -mov al, byte ptr [ebp - 8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 00480329  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048032a  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048032d  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048032e  6858e34b00             -push 0x4be358
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4973400 /*0x4be358*/;
    cpu.esp -= 4;
    // 00480333  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00480339  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048033a  e8e2a0ffff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0048033f  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x00480342:
    // 00480342  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00480348  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 0048034e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00480350  49                     -dec ecx
    (cpu.ecx)--;
    // 00480351  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00480353  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00480355  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00480357  49                     -dec ecx
    (cpu.ecx)--;
    // 00480358  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 0048035b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048035d  e8faab0100             -call 0x49af5c
    cpu.esp -= 4;
    sub_49af5c(app, cpu);
    if (cpu.terminate) return;
    // 00480362  f6460a01               +test byte ptr [esi + 0xa], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 1 /*0x1*/));
    // 00480366  7473                   -je 0x4803db
    if (cpu.flags.zf)
    {
        goto L_0x004803db;
    }
    // 00480368  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048036a  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048036f  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00480372  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00480374  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480376  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480378  7e09                   -jle 0x480383
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00480383;
    }
    // 0048037a  83fa35                 +cmp edx, 0x35
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048037d  0f8d5b010000           -jge 0x4804de
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004804de;
    }
L_0x00480383:
    // 00480383  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480385  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 0048038a  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048038d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048038f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480391  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480393  0f8e3e010000           -jle 0x4804d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004804d7;
    }
L_0x00480399:
    // 00480399  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0048039b:
    // 0048039b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048039d  8d560b                 -lea edx, [esi + 0xb]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 004803a0  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004803a3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004803a5  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004803a7  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004803ad  e84aa0ffff             -call 0x47a3fc
    cpu.esp -= 4;
    sub_47a3fc(app, cpu);
    if (cpu.terminate) return;
    // 004803b2  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004803b4  8dbdf4feffff           -lea edi, [ebp - 0x10c]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004803ba  889429f4feffff         -mov byte ptr [ecx + ebp - 0x10c], dl
    *app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-268) /* -0x10c */ + cpu.ebp * 1) = cpu.dl;
    // 004803c1  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004803c3  49                     -dec ecx
    (cpu.ecx)--;
    // 004803c4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004803c6  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004803c8  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004803ca  49                     -dec ecx
    (cpu.ecx)--;
    // 004803cb  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004803d1  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004803d4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004803d6  e881ab0100             -call 0x49af5c
    cpu.esp -= 4;
    sub_49af5c(app, cpu);
    if (cpu.terminate) return;
L_0x004803db:
    // 004803db  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004803e0  ba78e34b00             -mov edx, 0x4be378
    cpu.edx = 4973432 /*0x4be378*/;
    // 004803e5  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004803e8  e86fab0100             -call 0x49af5c
    cpu.esp -= 4;
    sub_49af5c(app, cpu);
    if (cpu.terminate) return;
    // 004803ed  f6460a04               +test byte ptr [esi + 0xa], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 4 /*0x4*/));
    // 004803f1  0f84f1000000           -je 0x4804e8
    if (cpu.flags.zf)
    {
        goto L_0x004804e8;
    }
    // 004803f7  8d4e0b                 -lea ecx, [esi + 0xb]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 004803fa  bf03000000             -mov edi, 3
    cpu.edi = 3 /*0x3*/;
L_0x004803ff:
    // 004803ff  8a4608                 -mov al, byte ptr [esi + 8]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00480402  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 00480404  fecc                   -dec ah
    (cpu.ah)--;
    // 00480406  886608                 -mov byte ptr [esi + 8], ah
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ah;
    // 00480409  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0048040b  0f84d7000000           -je 0x4804e8
    if (cpu.flags.zf)
    {
        goto L_0x004804e8;
    }
    // 00480411  8a01                   -mov al, byte ptr [ecx]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ecx);
    // 00480413  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480415  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 00480417  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480418  687ce34b00             -push 0x4be37c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4973436 /*0x4be37c*/;
    cpu.esp -= 4;
    // 0048041d  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00480423  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480424  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00480426  e8f69fffff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 0048042b  8d95f4feffff           -lea edx, [ebp - 0x10c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00480431  83c40c                 +add esp, 0xc
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
    // 00480434  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480437  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00480438  e81fab0100             -call 0x49af5c
    cpu.esp -= 4;
    sub_49af5c(app, cpu);
    if (cpu.terminate) return;
    // 0048043d  ebc0                   -jmp 0x4803ff
    goto L_0x004803ff;
L_0x0048043f:
    // 0048043f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00480441  e9a6fdffff             -jmp 0x4801ec
    goto L_0x004801ec;
L_0x00480446:
    // 00480446  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480448  e9cefdffff             -jmp 0x48021b
    goto L_0x0048021b;
L_0x0048044d:
    // 0048044d  b830e34b00             -mov eax, 0x4be330
    cpu.eax = 4973360 /*0x4be330*/;
    // 00480452  e929feffff             -jmp 0x480280
    goto L_0x00480280;
L_0x00480457:
    // 00480457  f6460a08               +test byte ptr [esi + 0xa], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(*app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) & 8 /*0x8*/));
    // 0048045b  7422                   -je 0x48047f
    if (cpu.flags.zf)
    {
        goto L_0x0048047f;
    }
    // 0048045d  b828e34b00             -mov eax, 0x4be328
    cpu.eax = 4973352 /*0x4be328*/;
L_0x00480462:
    // 00480462  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480463  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esi);
    // 00480465  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480466  6848e34b00             -push 0x4be348
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4973384 /*0x4be348*/;
    cpu.esp -= 4;
    // 0048046b  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 00480471  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480472  e8aa9fffff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 00480477  83c410                 +add esp, 0x10
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
    // 0048047a  e919feffff             -jmp 0x480298
    goto L_0x00480298;
L_0x0048047f:
    // 0048047f  b830e34b00             -mov eax, 0x4be330
    cpu.eax = 4973360 /*0x4be330*/;
    // 00480484  ebdc                   -jmp 0x480462
    goto L_0x00480462;
L_0x00480486:
    // 00480486  80fb7f                 +cmp bl, 0x7f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480489  0f8745feffff           -ja 0x4802d4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004802d4;
    }
    // 0048048f  e944feffff             -jmp 0x4802d8
    goto L_0x004802d8;
L_0x00480494:
    // 00480494  80fd7f                 +cmp ch, 0x7f
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480497  0f8747feffff           -ja 0x4802e4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004802e4;
    }
    // 0048049d  e946feffff             -jmp 0x4802e8
    goto L_0x004802e8;
L_0x004804a2:
    // 004804a2  80fa7f                 +cmp dl, 0x7f
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004804a5  0f8749feffff           -ja 0x4802f4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004802f4;
    }
    // 004804ab  e948feffff             -jmp 0x4802f8
    goto L_0x004802f8;
L_0x004804b0:
    // 004804b0  80ff7f                 +cmp bh, 0x7f
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(127 /*0x7f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004804b3  0f874bfeffff           -ja 0x480304
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00480304;
    }
    // 004804b9  e94afeffff             -jmp 0x480308
    goto L_0x00480308;
L_0x004804be:
    // 004804be  6868e34b00             -push 0x4be368
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4973416 /*0x4be368*/;
    cpu.esp -= 4;
    // 004804c3  8d85f4feffff           -lea eax, [ebp - 0x10c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-268) /* -0x10c */);
    // 004804c9  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004804ca  e8529fffff             -call 0x47a421
    cpu.esp -= 4;
    sub_47a421(app, cpu);
    if (cpu.terminate) return;
    // 004804cf  83c408                 +add esp, 8
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
    // 004804d2  e96bfeffff             -jmp 0x480342
    goto L_0x00480342;
L_0x004804d7:
    // 004804d7  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004804d9  e9bbfeffff             -jmp 0x480399
    goto L_0x00480399;
L_0x004804de:
    // 004804de  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 004804e3  e9b3feffff             -jmp 0x48039b
    goto L_0x0048039b;
L_0x004804e8:
    // 004804e8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004804ed  ba84e34b00             -mov edx, 0x4be384
    cpu.edx = 4973444 /*0x4be384*/;
    // 004804f2  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004804f5  e862aa0100             -call 0x49af5c
    cpu.esp -= 4;
    sub_49af5c(app, cpu);
    if (cpu.terminate) return;
    // 004804fa  e921fdffff             -jmp 0x480220
    goto L_0x00480220;
L_0x004804ff:
    // 004804ff  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480502  e855a90100             -call 0x49ae5c
    cpu.esp -= 4;
    sub_49ae5c(app, cpu);
    if (cpu.terminate) return;
L_0x00480507:
    // 00480507  8b75f4                 -mov esi, dword ptr [ebp - 0xc]
    cpu.esi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0048050a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048050c  7407                   -je 0x480515
    if (cpu.flags.zf)
    {
        goto L_0x00480515;
    }
    // 0048050e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480510  e8b785ffff             -call 0x478acc
    cpu.esp -= 4;
    sub_478acc(app, cpu);
    if (cpu.terminate) return;
L_0x00480515:
    // 00480515  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480519  740e                   -je 0x480529
    if (cpu.flags.zf)
    {
        goto L_0x00480529;
    }
    // 0048051b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480520  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00480522  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480523  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480524  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480525  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480526  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480527  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480528  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480529:
    // 00480529  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048052b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0048052d  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048052e  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048052f  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480530  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480531  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480532  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480533  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480534(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480534  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480535  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480536  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480537  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00480539  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048053c  8945fc                 -mov dword ptr [ebp - 4], eax
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 0048053f  8955f8                 -mov dword ptr [ebp - 8], edx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 00480542  895df0                 -mov dword ptr [ebp - 0x10], ebx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 00480545  894df4                 -mov dword ptr [ebp - 0xc], ecx
    *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00480548  a1748f4c00             -mov eax, dword ptr [0x4c8f74]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017460) /* 0x4c8f74 */);
    // 0048054d  e8b6eaffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00480552  833d788f4c0000         +cmp dword ptr [0x4c8f78], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480559  0f847d010000           -je 0x4806dc
    if (cpu.flags.zf)
    {
        goto L_0x004806dc;
    }
    // 0048055f  8b15dcba5100           -mov edx, dword ptr [0x51badc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356252) /* 0x51badc */);
    // 00480565  8b0de0ba5100           -mov ecx, dword ptr [0x51bae0]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5356256) /* 0x51bae0 */);
    // 0048056b  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048056d  8b1dd8ba5100           -mov ebx, dword ptr [0x51bad8]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5356248) /* 0x51bad8 */);
    // 00480573  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480575  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480578  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048057a  8b35788f4c00           -mov esi, dword ptr [0x4c8f78]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
    // 00480580  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 00480583  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480585  39d9                   +cmp ecx, ebx
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
    // 00480587  0f856f010000           -jne 0x4806fc
    if (!cpu.flags.zf)
    {
        goto L_0x004806fc;
    }
    // 0048058d  8b15dcba5100           -mov edx, dword ptr [0x51badc]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5356252) /* 0x51badc */);
    // 00480593  42                     -inc edx
    (cpu.edx)++;
    // 00480594  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480596  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480599  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048059b  8915dcba5100           -mov dword ptr [0x51badc], edx
    *app->getMemory<x86::reg32>(x86::reg32(5356252) /* 0x51badc */) = cpu.edx;
L_0x004805a1:
    // 004805a1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004805a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004805a6  0f8467010000           -je 0x480713
    if (cpu.flags.zf)
    {
        goto L_0x00480713;
    }
    // 004805ac  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004805ae  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004805b0  49                     -dec ecx
    (cpu.ecx)--;
    // 004805b1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004805b3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004805b5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004805b7  49                     -dec ecx
    (cpu.ecx)--;
    // 004805b8  83f935                 +cmp ecx, 0x35
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(53 /*0x35*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004805bb  0f8348010000           -jae 0x480709
    if (!cpu.flags.cf)
    {
        goto L_0x00480709;
    }
    // 004805c1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004805c3  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004805c5  49                     -dec ecx
    (cpu.ecx)--;
    // 004805c6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004805c8  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004805ca  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004805cc  49                     -dec ecx
    (cpu.ecx)--;
L_0x004805cd:
    // 004805cd  837df000               +cmp dword ptr [ebp - 0x10], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004805d1  0f8443010000           -je 0x48071a
    if (cpu.flags.zf)
    {
        goto L_0x0048071a;
    }
    // 004805d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004805d9  ba35000000             -mov edx, 0x35
    cpu.edx = 53 /*0x35*/;
    // 004805de  88c8                   -mov al, cl
    cpu.al = cpu.cl;
    // 004805e0  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004805e2  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004805e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004805e7  39fa                   +cmp edx, edi
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
    // 004805e9  7e02                   -jle 0x4805ed
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004805ed;
    }
    // 004805eb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004805ed:
    // 004805ed  884608                 -mov byte ptr [esi + 8], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
L_0x004805f0:
    // 004805f0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004805f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004805f5  7405                   -je 0x4805fc
    if (cpu.flags.zf)
    {
        goto L_0x004805fc;
    }
    // 004805f7  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x004805fc:
    // 004805fc  88460a                 -mov byte ptr [esi + 0xa], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.al;
    // 004805ff  a124b05100             -mov eax, dword ptr [0x51b024]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5353508) /* 0x51b024 */);
    // 00480604  8906                   -mov dword ptr [esi], eax
    *app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00480606  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 00480609  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0048060c  884609                 -mov byte ptr [esi + 9], al
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0048060f  8d460b                 -lea eax, [esi + 0xb]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(11) /* 0xb */);
    // 00480612  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480614  742a                   -je 0x480640
    if (cpu.flags.zf)
    {
        goto L_0x00480640;
    }
    // 00480616  807e0800               +cmp byte ptr [esi + 8], 0
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048061a  7424                   -je 0x480640
    if (cpu.flags.zf)
    {
        goto L_0x00480640;
    }
    // 0048061c  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048061f  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00480621  80ce04                 -or dh, 4
    cpu.dh |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 00480624  8a7e08                 -mov bh, byte ptr [esi + 8]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00480627  88760a                 -mov byte ptr [esi + 0xa], dh
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
    // 0048062a  8b55f0                 -mov edx, dword ptr [ebp - 0x10]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 0048062d  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 0048062f  760f                   -jbe 0x480640
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480640;
    }
L_0x00480631:
    // 00480631  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx);
    // 00480633  42                     -inc edx
    (cpu.edx)++;
    // 00480634  8838                   -mov byte ptr [eax], bh
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
    // 00480636  fec3                   -inc bl
    (cpu.bl)++;
    // 00480638  8a6e08                 -mov ch, byte ptr [esi + 8]
    cpu.ch = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048063b  40                     -inc eax
    (cpu.eax)++;
    // 0048063c  38eb                   +cmp bl, ch
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.ch));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048063e  72f1                   -jb 0x480631
    if (cpu.flags.cf)
    {
        goto L_0x00480631;
    }
L_0x00480640:
    // 00480640  837dfc00               +cmp dword ptr [ebp - 4], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480644  7425                   -je 0x48066b
    if (cpu.flags.zf)
    {
        goto L_0x0048066b;
    }
    // 00480646  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 00480648  7421                   -je 0x48066b
    if (cpu.flags.zf)
    {
        goto L_0x0048066b;
    }
    // 0048064a  8a560a                 -mov dl, byte ptr [esi + 0xa]
    cpu.dl = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0048064d  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 00480650  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 00480652  88560a                 -mov byte ptr [esi + 0xa], dl
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dl;
    // 00480655  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480658  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0048065a  760c                   -jbe 0x480668
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00480668;
    }
L_0x0048065c:
    // 0048065c  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = *app->getMemory<x86::reg8>(cpu.edx);
    // 0048065e  42                     -inc edx
    (cpu.edx)++;
    // 0048065f  8838                   -mov byte ptr [eax], bh
    *app->getMemory<x86::reg8>(cpu.eax) = cpu.bh;
    // 00480661  fec3                   -inc bl
    (cpu.bl)++;
    // 00480663  40                     -inc eax
    (cpu.eax)++;
    // 00480664  38cb                   +cmp bl, cl
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
    // 00480666  72f4                   -jb 0x48065c
    if (cpu.flags.cf)
    {
        goto L_0x0048065c;
    }
L_0x00480668:
    // 00480668  c60000                 -mov byte ptr [eax], 0
    *app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x0048066b:
    // 0048066b  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 0048066e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00480670  0f84ad000000           -je 0x480723
    if (cpu.flags.zf)
    {
        goto L_0x00480723;
    }
    // 00480676  8a760a                 -mov dh, byte ptr [esi + 0xa]
    cpu.dh = *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 00480679  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.edi);
    // 0048067b  80ce02                 -or dh, 2
    cpu.dh |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0048067e  894604                 -mov dword ptr [esi + 4], eax
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00480681  88760a                 -mov byte ptr [esi + 0xa], dh
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dh;
L_0x00480684:
    // 00480684  833d7c8f4c0000         +cmp dword ptr [0x4c8f7c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017468) /* 0x4c8f7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048068b  744f                   -je 0x4806dc
    if (cpu.flags.zf)
    {
        goto L_0x004806dc;
    }
    // 0048068d  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00480690  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00480693  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480694  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480696  0f848f000000           -je 0x48072b
    if (cpu.flags.zf)
    {
        goto L_0x0048072b;
    }
    // 0048069c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0048069e:
    // 0048069e  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004806a1  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004806a2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004806a4  0f848b000000           -je 0x480735
    if (cpu.flags.zf)
    {
        goto L_0x00480735;
    }
    // 004806aa  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.ebx);
L_0x004806ac:
    // 004806ac  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = *app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004806af  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004806b0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004806b2  0f8484000000           -je 0x48073c
    if (cpu.flags.zf)
    {
        goto L_0x0048073c;
    }
    // 004806b8  b828e34b00             -mov eax, 0x4be328
    cpu.eax = 4973352 /*0x4be328*/;
L_0x004806bd:
    // 004806bd  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004806be  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004806c0  8a4514                 -mov al, byte ptr [ebp + 0x14]
    cpu.al = *app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004806c3  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004806c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004806c6  a0808f4c00             -mov al, byte ptr [0x4c8f80]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5017472) /* 0x4c8f80 */);
    // 004806cb  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004806cc  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = *app->getMemory<x86::reg32>(cpu.esi);
    // 004806ce  50                     -push eax
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004806cf  688ce34b00             -push 0x4be38c
    *app->getMemory<x86::reg32>(cpu.esp-4) = 4973452 /*0x4be38c*/;
    cpu.esp -= 4;
    // 004806d4  e8d7000000             -call 0x4807b0
    cpu.esp -= 4;
    sub_4807b0(app, cpu);
    if (cpu.terminate) return;
    // 004806d9  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004806dc:
    // 004806dc  a1748f4c00             -mov eax, dword ptr [0x4c8f74]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017460) /* 0x4c8f74 */);
    // 004806e1  e83ae9ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004806e6  833d788f4c0000         +cmp dword ptr [0x4c8f78], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017464) /* 0x4c8f78 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004806ed  7457                   -je 0x480746
    if (cpu.flags.zf)
    {
        goto L_0x00480746;
    }
    // 004806ef  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004806f4  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004806f6  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f7  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f8  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f9  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004806fc:
    // 004806fc  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004806ff  a3e0ba5100             -mov dword ptr [0x51bae0], eax
    *app->getMemory<x86::reg32>(x86::reg32(5356256) /* 0x51bae0 */) = cpu.eax;
    // 00480704  e998feffff             -jmp 0x4805a1
    goto L_0x004805a1;
L_0x00480709:
    // 00480709  b935000000             -mov ecx, 0x35
    cpu.ecx = 53 /*0x35*/;
    // 0048070e  e9bafeffff             -jmp 0x4805cd
    goto L_0x004805cd;
L_0x00480713:
    // 00480713  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00480715  e9b3feffff             -jmp 0x4805cd
    goto L_0x004805cd;
L_0x0048071a:
    // 0048071a  c6460800               -mov byte ptr [esi + 8], 0
    *app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048071e  e9cdfeffff             -jmp 0x4805f0
    goto L_0x004805f0;
L_0x00480723:
    // 00480723  897e04                 -mov dword ptr [esi + 4], edi
    *app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00480726  e959ffffff             -jmp 0x480684
    goto L_0x00480684;
L_0x0048072b:
    // 0048072b  b888e34b00             -mov eax, 0x4be388
    cpu.eax = 4973448 /*0x4be388*/;
    // 00480730  e969ffffff             -jmp 0x48069e
    goto L_0x0048069e;
L_0x00480735:
    // 00480735  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00480737  e970ffffff             -jmp 0x4806ac
    goto L_0x004806ac;
L_0x0048073c:
    // 0048073c  b830e34b00             -mov eax, 0x4be330
    cpu.eax = 4973360 /*0x4be330*/;
    // 00480741  e977ffffff             -jmp 0x4806bd
    goto L_0x004806bd;
L_0x00480746:
    // 00480746  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480748  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0048074a  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048074b  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048074c  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048074d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_480750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480750  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480751  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00480753  39c2                   +cmp edx, eax
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
    // 00480755  771d                   -ja 0x480774
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00480774;
    }
L_0x00480757:
    // 00480757  833d14824c0000         +cmp dword ptr [0x4c8214], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014036) /* 0x4c8214 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048075e  752f                   -jne 0x48078f
    if (!cpu.flags.zf)
    {
        goto L_0x0048078f;
    }
    // 00480760  833d0c824c0000         +cmp dword ptr [0x4c820c], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5014028) /* 0x4c820c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480767  7433                   -je 0x48079c
    if (cpu.flags.zf)
    {
        goto L_0x0048079c;
    }
    // 00480769  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048076b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048076d  e857a90100             -call 0x49b0c9
    cpu.esp -= 4;
    sub_49b0c9(app, cpu);
    if (cpu.terminate) return;
L_0x00480772:
    // 00480772  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480773  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480774:
    // 00480774  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 00480777  39d1                   +cmp ecx, edx
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
    // 00480779  73dc                   -jae 0x480757
    if (!cpu.flags.cf)
    {
        goto L_0x00480757;
    }
    // 0048077b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048077d  8d1419                 -lea edx, [ecx + ebx]
    cpu.edx = x86::reg32(cpu.ecx + cpu.ebx * 1);
L_0x00480780:
    // 00480780  4b                     -dec ebx
    (cpu.ebx)--;
    // 00480781  83fbff                 +cmp ebx, -1
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
    // 00480784  74ec                   -je 0x480772
    if (cpu.flags.zf)
    {
        goto L_0x00480772;
    }
    // 00480786  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480787  8a48ff                 -mov cl, byte ptr [eax - 1]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 0048078a  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048078b  880a                   -mov byte ptr [edx], cl
    *app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 0048078d  ebf1                   -jmp 0x480780
    goto L_0x00480780;
L_0x0048078f:
    // 0048078f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480791  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480793  e80daa0100             -call 0x49b1a5
    cpu.esp -= 4;
    sub_49b1a5(app, cpu);
    if (cpu.terminate) return;
    // 00480798  0f77                   -emms 
    cpu.mmx.init();
    // 0048079a  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048079b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048079c:
    // 0048079c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048079e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004807a0  e8802a0100             -call 0x493225
    cpu.esp -= 4;
    sub_493225(app, cpu);
    if (cpu.terminate) return;
    // 004807a5  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4807b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004807b0  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004807b6  833d888f4c0002         +cmp dword ptr [0x4c8f88], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017480) /* 0x4c8f88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004807bd  7c21                   -jl 0x4807e0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004807e0;
    }
    // 004807bf  833d848f4c0000         +cmp dword ptr [0x4c8f84], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004807c6  750a                   -jne 0x4807d2
    if (!cpu.flags.zf)
    {
        goto L_0x004807d2;
    }
    // 004807c8  e8ebe7ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 004807cd  a3848f4c00             -mov dword ptr [0x4c8f84], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */) = cpu.eax;
L_0x004807d2:
    // 004807d2  a1848f4c00             -mov eax, dword ptr [0x4c8f84]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 004807d7  e82ce8ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 004807dc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004807de  7507                   -jne 0x4807e7
    if (!cpu.flags.zf)
    {
        goto L_0x004807e7;
    }
L_0x004807e0:
    // 004807e0  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004807e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004807e7:
    // 004807e7  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004807e8  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004807e9  8d842414010000         -lea eax, [esp + 0x114]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004807f0  8d9c2408010000         -lea ebx, [esp + 0x108]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 004807f7  8b942410010000         -mov edx, dword ptr [esp + 0x110]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004807fe  89842408010000         -mov dword ptr [esp + 0x108], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.eax;
    // 00480805  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480809  e8082e0100             -call 0x493616
    cpu.esp -= 4;
    sub_493616(app, cpu);
    if (cpu.terminate) return;
    // 0048080e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480810  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00480814  899c2408010000         -mov dword ptr [esp + 0x108], ebx
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */) = cpu.ebx;
    // 0048081b  e8e0000000             -call 0x480900
    cpu.esp -= 4;
    sub_480900(app, cpu);
    if (cpu.terminate) return;
    // 00480820  a1848f4c00             -mov eax, dword ptr [0x4c8f84]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 00480825  e8f6e7ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 0048082a  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048082b  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048082c  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00480832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480834(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480834  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480835  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480836  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 0048083c  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00480843  8b942414010000         -mov edx, dword ptr [esp + 0x114]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 0048084a  833d888f4c0002         +cmp dword ptr [0x4c8f88], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017480) /* 0x4c8f88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480851  0f8c8b000000           -jl 0x4808e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004808e2;
    }
    // 00480857  833d848f4c0000         +cmp dword ptr [0x4c8f84], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048085e  750a                   -jne 0x48086a
    if (!cpu.flags.zf)
    {
        goto L_0x0048086a;
    }
    // 00480860  e853e7ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00480865  a3848f4c00             -mov dword ptr [0x4c8f84], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */) = cpu.eax;
L_0x0048086a:
    // 0048086a  a1848f4c00             -mov eax, dword ptr [0x4c8f84]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 0048086f  e894e7ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00480874  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480876  746a                   -je 0x4808e2
    if (cpu.flags.zf)
    {
        goto L_0x004808e2;
    }
    // 00480878  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048087a  7c23                   -jl 0x48089f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048089f;
    }
    // 0048087c  83fb50                 +cmp ebx, 0x50
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048087f  7d1e                   -jge 0x48089f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048089f;
    }
    // 00480881  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480883  7c1a                   -jl 0x48089f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048089f;
    }
    // 00480885  83fa19                 +cmp edx, 0x19
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
    // 00480888  7d15                   -jge 0x48089f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048089f;
    }
    // 0048088a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00480891  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480893  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00480896  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00480898  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048089a  a3948f4c00             -mov dword ptr [0x4c8f94], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */) = cpu.eax;
L_0x0048089f:
    // 0048089f  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004808a0  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004808a7  8d9c2404010000         -lea ebx, [esp + 0x104]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004808ae  8b94241c010000         -mov edx, dword ptr [esp + 0x11c]
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 004808b5  89842404010000         -mov dword ptr [esp + 0x104], eax
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 004808bc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004808c0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004808c2  e84f2d0100             -call 0x493616
    cpu.esp -= 4;
    sub_493616(app, cpu);
    if (cpu.terminate) return;
    // 004808c7  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004808cb  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    *app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 004808d2  e829000000             -call 0x480900
    cpu.esp -= 4;
    sub_480900(app, cpu);
    if (cpu.terminate) return;
    // 004808d7  a1848f4c00             -mov eax, dword ptr [0x4c8f84]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 004808dc  e83fe7ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 004808e1  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004808e2:
    // 004808e2  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004808e8  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808e9  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00480900  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480901  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480902  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480903  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480904  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480905  55                     -push ebp
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480906  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480909  8b1d948f4c00           -mov ebx, dword ptr [0x4c8f94]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */);
    // 0048090f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480911  833d888f4c0002         +cmp dword ptr [0x4c8f88], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017480) /* 0x4c8f88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480918  7d10                   -jge 0x48092a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048092a;
    }
L_0x0048091a:
    // 0048091a  8b1d948f4c00           -mov ebx, dword ptr [0x4c8f94]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */);
    // 00480920  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480923  5d                     -pop ebp
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480924  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480925  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480926  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480927  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480928  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480929  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048092a:
    // 0048092a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048092c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048092e  49                     -dec ecx
    (cpu.ecx)--;
    // 0048092f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00480931  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00480933  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00480935  49                     -dec ecx
    (cpu.ecx)--;
    // 00480936  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480938  890c24                 -mov dword ptr [esp], ecx
    *app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048093b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048093d  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0048093f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480941  7ed7                   -jle 0x48091a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048091a;
    }
L_0x00480943:
    // 00480943  8b1d948f4c00           -mov ebx, dword ptr [0x4c8f94]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */);
    // 00480949  80f90e                 +cmp cl, 0xe
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(14 /*0xe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048094c  7441                   -je 0x48098f
    if (cpu.flags.zf)
    {
        goto L_0x0048098f;
    }
    // 0048094e  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = *app->getMemory<x86::reg8>(cpu.esi);
    // 00480950  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480953  7245                   -jb 0x48099a
    if (cpu.flags.cf)
    {
        goto L_0x0048099a;
    }
    // 00480955  e8fa000000             -call 0x480a54
    cpu.esp -= 4;
    sub_480a54(app, cpu);
    if (cpu.terminate) return;
    // 0048095a  8b1d948f4c00           -mov ebx, dword ptr [0x4c8f94]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */);
    // 00480960  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00480962  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00480964  a0998f4c00             -mov al, byte ptr [0x4c8f99]
    cpu.al = *app->getMemory<x86::reg8>(x86::reg32(5017497) /* 0x4c8f99 */);
    // 00480969  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0048096b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048096e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00480971  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480973  8b15908f4c00           -mov edx, dword ptr [0x4c8f90]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */);
    // 00480979  6689441afe             -mov word ptr [edx + ebx - 2], ax
    *app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */ + cpu.ebx * 1) = cpu.ax;
L_0x0048097e:
    // 0048097e  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = *app->getMemory<x86::reg32>(cpu.esp);
    // 00480981  46                     -inc esi
    (cpu.esi)++;
    // 00480982  47                     -inc edi
    (cpu.edi)++;
    // 00480983  891d948f4c00           -mov dword ptr [0x4c8f94], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */) = cpu.ebx;
    // 00480989  39ef                   +cmp edi, ebp
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048098b  7d8d                   -jge 0x48091a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048091a;
    }
    // 0048098d  ebb4                   -jmp 0x480943
    goto L_0x00480943;
L_0x0048098f:
    // 0048098f  8a06                   -mov al, byte ptr [esi]
    cpu.al = *app->getMemory<x86::reg8>(cpu.esi);
    // 00480991  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00480993  a2998f4c00             -mov byte ptr [0x4c8f99], al
    *app->getMemory<x86::reg8>(x86::reg32(5017497) /* 0x4c8f99 */) = cpu.al;
    // 00480998  ebe4                   -jmp 0x48097e
    goto L_0x0048097e;
L_0x0048099a:
    // 0048099a  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 0048099c  80ea08                 -sub dl, 8
    (cpu.dl) -= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0048099f  80fa04                 +cmp dl, 4
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
    // 004809a2  77da                   -ja 0x48097e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048097e;
    }
    // 004809a4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004809a6  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004809a8  ff2485ec084800         -jmp dword ptr [eax*4 + 0x4808ec]
    cpu.ip = *app->getMemory<x86::reg32>(4720876 + cpu.eax * 4); goto dynamic_jump;
  case 0x004809af:
    // 004809af  83fb02                 +cmp ebx, 2
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
    // 004809b2  7cca                   -jl 0x48097e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048097e;
    }
    // 004809b4  83eb02                 +sub ebx, 2
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
    // 004809b7  ebc5                   -jmp 0x48097e
    goto L_0x0048097e;
  case 0x004809b9:
    // 004809b9  803d9a8f4c0001         +cmp byte ptr [0x4c8f9a], 1
    {
        x86::reg8 tmp1 = *app->getMemory<x86::reg8>(x86::reg32(5017498) /* 0x4c8f9a */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004809c0  76bc                   -jbe 0x48097e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048097e;
    }
    // 004809c2  bda0000000             -mov ebp, 0xa0
    cpu.ebp = 160 /*0xa0*/;
    // 004809c7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004809c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004809cb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004809ce  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004809d0  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004809d3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004809d5  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004809d7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004809d9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004809dc  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004809de  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004809e0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004809e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004809e4  8a1d9a8f4c00           -mov bl, byte ptr [0x4c8f9a]
    cpu.bl = *app->getMemory<x86::reg8>(x86::reg32(5017498) /* 0x4c8f9a */);
    // 004809ea  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004809ed  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004809ef  40                     -inc eax
    (cpu.eax)++;
    // 004809f0  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004809f3  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004809f5  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004809f8  eb84                   -jmp 0x48097e
    goto L_0x0048097e;
  case 0x004809fa:
    // 004809fa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004809fc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004809fe  bba0000000             -mov ebx, 0xa0
    cpu.ebx = 160 /*0xa0*/;
    // 00480a03  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480a06  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00480a08  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00480a0b  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00480a11  891d948f4c00           -mov dword ptr [0x4c8f94], ebx
    *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */) = cpu.ebx;
    // 00480a17  e838000000             -call 0x480a54
    cpu.esp -= 4;
    sub_480a54(app, cpu);
    if (cpu.terminate) return;
    // 00480a1c  8b1d948f4c00           -mov ebx, dword ptr [0x4c8f94]
    cpu.ebx = *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */);
    // 00480a22  e957ffffff             -jmp 0x48097e
    goto L_0x0048097e;
  case 0x00480a27:
    // 00480a27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480a29  8a1d988f4c00           -mov bl, byte ptr [0x4c8f98]
    cpu.bl = *app->getMemory<x86::reg8>(x86::reg32(5017496) /* 0x4c8f98 */);
    // 00480a2f  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00480a35  e944ffffff             -jmp 0x48097e
    goto L_0x0048097e;
  case 0x00480a3a:
    // 00480a3a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480a3c  e897000000             -call 0x480ad8
    cpu.esp -= 4;
    sub_480ad8(app, cpu);
    if (cpu.terminate) return;
    // 00480a41  8a1d988f4c00           -mov bl, byte ptr [0x4c8f98]
    cpu.bl = *app->getMemory<x86::reg8>(x86::reg32(5017496) /* 0x4c8f98 */);
    // 00480a47  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00480a4d  e92cffffff             -jmp 0x48097e
    goto L_0x0048097e;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480a54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a54  813d948f4c00a00f0000   +cmp dword ptr [0x4c8f94], 0xfa0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480a5e  7d01                   -jge 0x480a61
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00480a61;
    }
    // 00480a60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480a61:
    // 00480a61  57                     -push edi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480a62  56                     -push esi
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480a63  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480a64  51                     -push ecx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480a65  53                     -push ebx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480a66  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480a68  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 00480a6d  8a15988f4c00           -mov dl, byte ptr [0x4c8f98]
    cpu.dl = *app->getMemory<x86::reg8>(x86::reg32(5017496) /* 0x4c8f98 */);
    // 00480a73  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00480a75  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00480a7c  49                     -dec ecx
    (cpu.ecx)--;
    // 00480a7d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480a7f  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 00480a86  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00480a89  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00480a8b  8b0d908f4c00           -mov ecx, dword ptr [0x4c8f90]
    cpu.ecx = *app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */);
    // 00480a91  42                     -inc edx
    (cpu.edx)++;
    // 00480a92  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480a94  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00480a9b  8b35908f4c00           -mov esi, dword ptr [0x4c8f90]
    cpu.esi = *app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */);
    // 00480aa1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480aa3  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 00480aa6  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00480aa9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00480aab  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00480aad  e89efcffff             -call 0x480750
    cpu.esp -= 4;
    sub_480750(app, cpu);
    if (cpu.terminate) return;
    // 00480ab2  a1908f4c00             -mov eax, dword ptr [0x4c8f90]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */);
    // 00480ab7  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 00480abc  05000f0000             -add eax, 0xf00
    (cpu.eax) += x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00480ac1  bf000f0000             -mov edi, 0xf00
    cpu.edi = 3840 /*0xf00*/;
    // 00480ac6  e811e6ffff             -call 0x47f0dc
    cpu.esp -= 4;
    sub_47f0dc(app, cpu);
    if (cpu.terminate) return;
    // 00480acb  893d948f4c00           -mov dword ptr [0x4c8f94], edi
    *app->getMemory<x86::reg32>(x86::reg32(5017492) /* 0x4c8f94 */) = cpu.edi;
    // 00480ad1  5b                     -pop ebx
    cpu.ebx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad2  59                     -pop ecx
    cpu.ecx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad3  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad4  5e                     -pop esi
    cpu.esi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad5  5f                     -pop edi
    cpu.edi = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480ad8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480ad8  833d888f4c0002         +cmp dword ptr [0x4c8f88], 2
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017480) /* 0x4c8f88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480adf  7c46                   -jl 0x480b27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480b27;
    }
    // 00480ae1  833d848f4c0000         +cmp dword ptr [0x4c8f84], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ae8  750a                   -jne 0x480af4
    if (!cpu.flags.zf)
    {
        goto L_0x00480af4;
    }
    // 00480aea  e8c9e4ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00480aef  a3848f4c00             -mov dword ptr [0x4c8f84], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */) = cpu.eax;
L_0x00480af4:
    // 00480af4  a1848f4c00             -mov eax, dword ptr [0x4c8f84]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 00480af9  e80ae5ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00480afe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480b00  7425                   -je 0x480b27
    if (cpu.flags.zf)
    {
        goto L_0x00480b27;
    }
    // 00480b02  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480b03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00480b05:
    // 00480b05  8b15908f4c00           -mov edx, dword ptr [0x4c8f90]
    cpu.edx = *app->getMemory<x86::reg32>(x86::reg32(5017488) /* 0x4c8f90 */);
    // 00480b0b  c7040200000000         -mov dword ptr [edx + eax], 0
    *app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00480b12  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480b15  3da00f0000             +cmp eax, 0xfa0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480b1a  7ce9                   -jl 0x480b05
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480b05;
    }
    // 00480b1c  a1848f4c00             -mov eax, dword ptr [0x4c8f84]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 00480b21  e8fae4ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
    // 00480b26  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00480b27:
    // 00480b27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480b28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b28  52                     -push edx
    *app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480b29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480b2b  833d848f4c0000         +cmp dword ptr [0x4c8f84], 0
    {
        x86::reg32 tmp1 = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480b32  750a                   -jne 0x480b3e
    if (!cpu.flags.zf)
    {
        goto L_0x00480b3e;
    }
    // 00480b34  e87fe4ffff             -call 0x47efb8
    cpu.esp -= 4;
    sub_47efb8(app, cpu);
    if (cpu.terminate) return;
    // 00480b39  a3848f4c00             -mov dword ptr [0x4c8f84], eax
    *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */) = cpu.eax;
L_0x00480b3e:
    // 00480b3e  a1848f4c00             -mov eax, dword ptr [0x4c8f84]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 00480b43  e8c0e4ffff             -call 0x47f008
    cpu.esp -= 4;
    sub_47f008(app, cpu);
    if (cpu.terminate) return;
    // 00480b48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480b4a  7419                   -je 0x480b65
    if (cpu.flags.zf)
    {
        goto L_0x00480b65;
    }
    // 00480b4c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480b4e  7c0b                   -jl 0x480b5b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480b5b;
    }
    // 00480b50  83fa18                 +cmp edx, 0x18
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480b53  7f06                   -jg 0x480b5b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00480b5b;
    }
    // 00480b55  8815988f4c00           -mov byte ptr [0x4c8f98], dl
    *app->getMemory<x86::reg8>(x86::reg32(5017496) /* 0x4c8f98 */) = cpu.dl;
L_0x00480b5b:
    // 00480b5b  a1848f4c00             -mov eax, dword ptr [0x4c8f84]
    cpu.eax = *app->getMemory<x86::reg32>(x86::reg32(5017476) /* 0x4c8f84 */);
    // 00480b60  e8bbe4ffff             -call 0x47f020
    cpu.esp -= 4;
    sub_47f020(app, cpu);
    if (cpu.terminate) return;
L_0x00480b65:
    // 00480b65  5a                     -pop edx
    cpu.edx = *app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b66  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480b68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b68  a2998f4c00             -mov byte ptr [0x4c8f99], al
    *app->getMemory<x86::reg8>(x86::reg32(5017497) /* 0x4c8f99 */) = cpu.al;
    // 00480b6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b70  83f801                 +cmp eax, 1
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
    // 00480b73  7d01                   -jge 0x480b76
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00480b76;
    }
    // 00480b75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480b76:
    // 00480b76  a29a8f4c00             -mov byte ptr [0x4c8f9a], al
    *app->getMemory<x86::reg8>(x86::reg32(5017498) /* 0x4c8f9a */) = cpu.al;
    // 00480b7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
